/*
 * cslr_dfe_jesd.h
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

/* The file is auto generated at 11:02:54 08/16/13 (Rev 1.71)*/

#ifndef CSLR_DFE_JESD_H__
#define CSLR_DFE_JESD_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 jesdtx_base_inits;
    /* Addr: h(8), d(8) */
    volatile Uint32 jesdtx_base_tx_inputs;
    /* Addr: h(C), d(12) */
    volatile Uint32 jesdtx_base_test_bus_sel;
    /* Addr: h(10), d(16) */
    volatile Uint32 jesdtx_base_test_seq_sel;
    /* Addr: h(14), d(20) */
    volatile Uint32 jesdtx_base_sync_n;
    /* Addr: h(18), d(24) */
    volatile Uint32 jesdtx_base_bb_ctrl;
    /* Addr: h(1C), d(28) */
    volatile Uint32 jesdtx_base_bb_err;
    /* Addr: h(20), d(32) */
    volatile Uint32 jesdtx_base_fifo;
    /* Addr: h(24), d(36) */
    volatile Uint32 jesdtx_base_sysref;
    /* Addr: h(28), d(40) */
    volatile Uint32 jesdtx_base_sysref_cntr_lo;
    /* Addr: h(2C), d(44) */
    volatile Uint32 jesdtx_base_sysref_cntr_hi;
    /* Addr: h(30), d(48) */
    volatile Uint32 jesdtx_base_sync_state;
    /* Addr: h(34), d(52) */
    volatile Uint32 jesdtx_base_first_sync_request;
    /* Addr: h(38), d(56) */
    volatile Uint32 rsvd1[3];
    /* Addr: h(44), d(68) */
    volatile Uint32 jesdtx_ssel_ssel_addr_0;
    /* Addr: h(48), d(72) */
    volatile Uint32 jesdtx_ssel_ssel_addr_1;
    /* Addr: h(4C), d(76) */
    volatile Uint32 jesdtx_ssel_ssel_addr_2;
    /* Addr: h(50), d(80) */
    volatile Uint32 rsvd2[237];
    /* Addr: h(404), d(1028) */
    volatile Uint32 jesdtx_signal_gen_txi0_general;
    /* Addr: h(408), d(1032) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_start_lo;
    /* Addr: h(40C), d(1036) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_start_hi;
    /* Addr: h(410), d(1040) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_stop_lo;
    /* Addr: h(414), d(1044) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_stop_hi;
    /* Addr: h(418), d(1048) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_slope_lo;
    /* Addr: h(41C), d(1052) */
    volatile Uint32 jesdtx_signal_gen_txi0_ramp_slope_hi;
    /* Addr: h(420), d(1056) */
    volatile Uint32 jesdtx_signal_gen_txi0_gen_timer;
    /* Addr: h(424), d(1060) */
    volatile Uint32 rsvd3[8];
    /* Addr: h(444), d(1092) */
    volatile Uint32 jesdtx_signal_gen_txq0_general;
    /* Addr: h(448), d(1096) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_start_lo;
    /* Addr: h(44C), d(1100) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_start_hi;
    /* Addr: h(450), d(1104) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_stop_lo;
    /* Addr: h(454), d(1108) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_stop_hi;
    /* Addr: h(458), d(1112) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_slope_lo;
    /* Addr: h(45C), d(1116) */
    volatile Uint32 jesdtx_signal_gen_txq0_ramp_slope_hi;
    /* Addr: h(460), d(1120) */
    volatile Uint32 jesdtx_signal_gen_txq0_gen_timer;
    /* Addr: h(464), d(1124) */
    volatile Uint32 rsvd4[8];
    /* Addr: h(484), d(1156) */
    volatile Uint32 jesdtx_signal_gen_txi1_general;
    /* Addr: h(488), d(1160) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_start_lo;
    /* Addr: h(48C), d(1164) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_start_hi;
    /* Addr: h(490), d(1168) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_stop_lo;
    /* Addr: h(494), d(1172) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_stop_hi;
    /* Addr: h(498), d(1176) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_slope_lo;
    /* Addr: h(49C), d(1180) */
    volatile Uint32 jesdtx_signal_gen_txi1_ramp_slope_hi;
    /* Addr: h(4A0), d(1184) */
    volatile Uint32 jesdtx_signal_gen_txi1_gen_timer;
    /* Addr: h(4A4), d(1188) */
    volatile Uint32 rsvd5[8];
    /* Addr: h(4C4), d(1220) */
    volatile Uint32 jesdtx_signal_gen_txq1_general;
    /* Addr: h(4C8), d(1224) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_start_lo;
    /* Addr: h(4CC), d(1228) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_start_hi;
    /* Addr: h(4D0), d(1232) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_stop_lo;
    /* Addr: h(4D4), d(1236) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_stop_hi;
    /* Addr: h(4D8), d(1240) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_slope_lo;
    /* Addr: h(4DC), d(1244) */
    volatile Uint32 jesdtx_signal_gen_txq1_ramp_slope_hi;
    /* Addr: h(4E0), d(1248) */
    volatile Uint32 jesdtx_signal_gen_txq1_gen_timer;
    /* Addr: h(4E4), d(1252) */
    volatile Uint32 rsvd6[200];
    /* Addr: h(804), d(2052) */
    volatile Uint32 jesdtx_check_sum_lane0_ctrl;
    /* Addr: h(808), d(2056) */
    volatile Uint32 jesdtx_check_sum_lane0_signal_len;
    /* Addr: h(80C), d(2060) */
    volatile Uint32 jesdtx_check_sum_lane0_chan_sel;
    /* Addr: h(810), d(2064) */
    volatile Uint32 jesdtx_check_sum_lane0_result_lo;
    /* Addr: h(814), d(2068) */
    volatile Uint32 jesdtx_check_sum_lane0_result_hi;
    /* Addr: h(818), d(2072) */
    volatile Uint32 rsvd7[11];
    /* Addr: h(844), d(2116) */
    volatile Uint32 jesdtx_check_sum_lane1_ctrl;
    /* Addr: h(848), d(2120) */
    volatile Uint32 jesdtx_check_sum_lane1_signal_len;
    /* Addr: h(84C), d(2124) */
    volatile Uint32 jesdtx_check_sum_lane1_chan_sel;
    /* Addr: h(850), d(2128) */
    volatile Uint32 jesdtx_check_sum_lane1_result_lo;
    /* Addr: h(854), d(2132) */
    volatile Uint32 jesdtx_check_sum_lane1_result_hi;
    /* Addr: h(858), d(2136) */
    volatile Uint32 rsvd8[11];
    /* Addr: h(884), d(2180) */
    volatile Uint32 jesdtx_check_sum_lane2_ctrl;
    /* Addr: h(888), d(2184) */
    volatile Uint32 jesdtx_check_sum_lane2_signal_len;
    /* Addr: h(88C), d(2188) */
    volatile Uint32 jesdtx_check_sum_lane2_chan_sel;
    /* Addr: h(890), d(2192) */
    volatile Uint32 jesdtx_check_sum_lane2_result_lo;
    /* Addr: h(894), d(2196) */
    volatile Uint32 jesdtx_check_sum_lane2_result_hi;
    /* Addr: h(898), d(2200) */
    volatile Uint32 rsvd9[11];
    /* Addr: h(8C4), d(2244) */
    volatile Uint32 jesdtx_check_sum_lane3_ctrl;
    /* Addr: h(8C8), d(2248) */
    volatile Uint32 jesdtx_check_sum_lane3_signal_len;
    /* Addr: h(8CC), d(2252) */
    volatile Uint32 jesdtx_check_sum_lane3_chan_sel;
    /* Addr: h(8D0), d(2256) */
    volatile Uint32 jesdtx_check_sum_lane3_result_lo;
    /* Addr: h(8D4), d(2260) */
    volatile Uint32 jesdtx_check_sum_lane3_result_hi;
    /* Addr: h(8D8), d(2264) */
    volatile Uint32 rsvd10[203];
    /* Addr: h(C04), d(3076) */
    volatile Uint32 jesdtx_clk_gater_link0_time_step;
    /* Addr: h(C08), d(3080) */
    volatile Uint32 rsvd11[1];
    /* Addr: h(C0C), d(3084) */
    volatile Uint32 jesdtx_clk_gater_link0_reset_int;
    /* Addr: h(C10), d(3088) */
    volatile Uint32 rsvd12[1];
    /* Addr: h(C14), d(3092) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_period_lsb;
    /* Addr: h(C18), d(3096) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_period_msb;
    /* Addr: h(C1C), d(3100) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_on_0_lsb;
    /* Addr: h(C20), d(3104) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_on_0_msb;
    /* Addr: h(C24), d(3108) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_off_0_lsb;
    /* Addr: h(C28), d(3112) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_off_0_msb;
    /* Addr: h(C2C), d(3116) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_on_1_lsb;
    /* Addr: h(C30), d(3120) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_on_1_msb;
    /* Addr: h(C34), d(3124) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_off_1_lsb;
    /* Addr: h(C38), d(3128) */
    volatile Uint32 jesdtx_clk_gater_link0_tdd_off_1_msb;
    /* Addr: h(C3C), d(3132) */
    volatile Uint32 rsvd13[2];
    /* Addr: h(C44), d(3140) */
    volatile Uint32 jesdtx_clk_gater_link1_time_step;
    /* Addr: h(C48), d(3144) */
    volatile Uint32 rsvd14[1];
    /* Addr: h(C4C), d(3148) */
    volatile Uint32 jesdtx_clk_gater_link1_reset_int;
    /* Addr: h(C50), d(3152) */
    volatile Uint32 rsvd15[1];
    /* Addr: h(C54), d(3156) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_period_lsb;
    /* Addr: h(C58), d(3160) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_period_msb;
    /* Addr: h(C5C), d(3164) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_on_0_lsb;
    /* Addr: h(C60), d(3168) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_on_0_msb;
    /* Addr: h(C64), d(3172) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_off_0_lsb;
    /* Addr: h(C68), d(3176) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_off_0_msb;
    /* Addr: h(C6C), d(3180) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_on_1_lsb;
    /* Addr: h(C70), d(3184) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_on_1_msb;
    /* Addr: h(C74), d(3188) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_off_1_lsb;
    /* Addr: h(C78), d(3192) */
    volatile Uint32 jesdtx_clk_gater_link1_tdd_off_1_msb;
    /* Addr: h(C7C), d(3196) */
    volatile Uint32 rsvd16[482];
    /* Addr: h(1404), d(5124) */
    volatile Uint32 jesdtx_lane0_cfg;
    /* Addr: h(1408), d(5128) */
    volatile Uint32 jesdtx_lane1_cfg;
    /* Addr: h(140C), d(5132) */
    volatile Uint32 jesdtx_lane2_cfg;
    /* Addr: h(1410), d(5136) */
    volatile Uint32 jesdtx_lane3_cfg;
    /* Addr: h(1414), d(5140) */
    volatile Uint32 rsvd17[252];
    /* Addr: h(1804), d(6148) */
    volatile Uint32 jesdtx_link0_cfg0;
    /* Addr: h(1808), d(6152) */
    volatile Uint32 jesdtx_link0_cfg1;
    /* Addr: h(180C), d(6156) */
    volatile Uint32 jesdtx_link0_cfg2;
    /* Addr: h(1810), d(6160) */
    volatile Uint32 jesdtx_link0_cfg3;
    /* Addr: h(1814), d(6164) */
    volatile Uint32 jesdtx_link0_cfg4;
    /* Addr: h(1818), d(6168) */
    volatile Uint32 jesdtx_link0_cfg5;
    /* Addr: h(181C), d(6172) */
    volatile Uint32 jesdtx_link0_cfg6;
    /* Addr: h(1820), d(6176) */
    volatile Uint32 jesdtx_link0_cfg7;
    /* Addr: h(1824), d(6180) */
    volatile Uint32 jesdtx_link0_cfg8;
    /* Addr: h(1828), d(6184) */
    volatile Uint32 jesdtx_link0_cfg9;
    /* Addr: h(182C), d(6188) */
    volatile Uint32 rsvd18[6];
    /* Addr: h(1844), d(6212) */
    volatile Uint32 jesdtx_link1_cfg0;
    /* Addr: h(1848), d(6216) */
    volatile Uint32 jesdtx_link1_cfg1;
    /* Addr: h(184C), d(6220) */
    volatile Uint32 jesdtx_link1_cfg2;
    /* Addr: h(1850), d(6224) */
    volatile Uint32 jesdtx_link1_cfg3;
    /* Addr: h(1854), d(6228) */
    volatile Uint32 jesdtx_link1_cfg4;
    /* Addr: h(1858), d(6232) */
    volatile Uint32 jesdtx_link1_cfg5;
    /* Addr: h(185C), d(6236) */
    volatile Uint32 jesdtx_link1_cfg6;
    /* Addr: h(1860), d(6240) */
    volatile Uint32 jesdtx_link1_cfg7;
    /* Addr: h(1864), d(6244) */
    volatile Uint32 jesdtx_link1_cfg8;
    /* Addr: h(1868), d(6248) */
    volatile Uint32 jesdtx_link1_cfg9;
    /* Addr: h(186C), d(6252) */
    volatile Uint32 rsvd19[230];
    /* Addr: h(1C04), d(7172) */
    volatile Uint32 jesdtx_intr_lane0_mask;
    /* Addr: h(1C08), d(7176) */
    volatile Uint32 jesdtx_intr_lane0_intr;
    /* Addr: h(1C0C), d(7180) */
    volatile Uint32 jesdtx_intr_lane0_force;
    /* Addr: h(1C10), d(7184) */
    volatile Uint32 rsvd20[13];
    /* Addr: h(1C44), d(7236) */
    volatile Uint32 jesdtx_intr_lane1_mask;
    /* Addr: h(1C48), d(7240) */
    volatile Uint32 jesdtx_intr_lane1_intr;
    /* Addr: h(1C4C), d(7244) */
    volatile Uint32 jesdtx_intr_lane1_force;
    /* Addr: h(1C50), d(7248) */
    volatile Uint32 rsvd21[13];
    /* Addr: h(1C84), d(7300) */
    volatile Uint32 jesdtx_intr_lane2_mask;
    /* Addr: h(1C88), d(7304) */
    volatile Uint32 jesdtx_intr_lane2_intr;
    /* Addr: h(1C8C), d(7308) */
    volatile Uint32 jesdtx_intr_lane2_force;
    /* Addr: h(1C90), d(7312) */
    volatile Uint32 rsvd22[13];
    /* Addr: h(1CC4), d(7364) */
    volatile Uint32 jesdtx_intr_lane3_mask;
    /* Addr: h(1CC8), d(7368) */
    volatile Uint32 jesdtx_intr_lane3_intr;
    /* Addr: h(1CCC), d(7372) */
    volatile Uint32 jesdtx_intr_lane3_force;
    /* Addr: h(1CD0), d(7376) */
    volatile Uint32 rsvd23[205];
    /* Addr: h(2004), d(8196) */
    volatile Uint32 jesdtx_intr_sysref_mask;
    /* Addr: h(2008), d(8200) */
    volatile Uint32 jesdtx_intr_sysref_intr;
    /* Addr: h(200C), d(8204) */
    volatile Uint32 jesdtx_intr_sysref_force;
    /* Addr: h(2010), d(8208) */
    volatile Uint32 rsvd24[253];
    /* Addr: h(2404), d(9220) */
    volatile Uint32 jesdtx_map_lane0_nibble0_position0;
    /* Addr: h(2408), d(9224) */
    volatile Uint32 jesdtx_map_lane0_nibble0_position1;
    /* Addr: h(240C), d(9228) */
    volatile Uint32 jesdtx_map_lane0_nibble0_position2;
    /* Addr: h(2410), d(9232) */
    volatile Uint32 jesdtx_map_lane0_nibble0_position3;
    /* Addr: h(2414), d(9236) */
    volatile Uint32 jesdtx_map_lane0_nibble1_position0;
    /* Addr: h(2418), d(9240) */
    volatile Uint32 jesdtx_map_lane0_nibble1_position1;
    /* Addr: h(241C), d(9244) */
    volatile Uint32 jesdtx_map_lane0_nibble1_position2;
    /* Addr: h(2420), d(9248) */
    volatile Uint32 jesdtx_map_lane0_nibble1_position3;
    /* Addr: h(2424), d(9252) */
    volatile Uint32 jesdtx_map_lane0_nibble2_position0;
    /* Addr: h(2428), d(9256) */
    volatile Uint32 jesdtx_map_lane0_nibble2_position1;
    /* Addr: h(242C), d(9260) */
    volatile Uint32 jesdtx_map_lane0_nibble2_position2;
    /* Addr: h(2430), d(9264) */
    volatile Uint32 jesdtx_map_lane0_nibble2_position3;
    /* Addr: h(2434), d(9268) */
    volatile Uint32 jesdtx_map_lane0_nibble3_position0;
    /* Addr: h(2438), d(9272) */
    volatile Uint32 jesdtx_map_lane0_nibble3_position1;
    /* Addr: h(243C), d(9276) */
    volatile Uint32 jesdtx_map_lane0_nibble3_position2;
    /* Addr: h(2440), d(9280) */
    volatile Uint32 jesdtx_map_lane0_nibble3_position3;
    /* Addr: h(2444), d(9284) */
    volatile Uint32 jesdtx_map_lane1_nibble0_position0;
    /* Addr: h(2448), d(9288) */
    volatile Uint32 jesdtx_map_lane1_nibble0_position1;
    /* Addr: h(244C), d(9292) */
    volatile Uint32 jesdtx_map_lane1_nibble0_position2;
    /* Addr: h(2450), d(9296) */
    volatile Uint32 jesdtx_map_lane1_nibble0_position3;
    /* Addr: h(2454), d(9300) */
    volatile Uint32 jesdtx_map_lane1_nibble1_position0;
    /* Addr: h(2458), d(9304) */
    volatile Uint32 jesdtx_map_lane1_nibble1_position1;
    /* Addr: h(245C), d(9308) */
    volatile Uint32 jesdtx_map_lane1_nibble1_position2;
    /* Addr: h(2460), d(9312) */
    volatile Uint32 jesdtx_map_lane1_nibble1_position3;
    /* Addr: h(2464), d(9316) */
    volatile Uint32 jesdtx_map_lane1_nibble2_position0;
    /* Addr: h(2468), d(9320) */
    volatile Uint32 jesdtx_map_lane1_nibble2_position1;
    /* Addr: h(246C), d(9324) */
    volatile Uint32 jesdtx_map_lane1_nibble2_position2;
    /* Addr: h(2470), d(9328) */
    volatile Uint32 jesdtx_map_lane1_nibble2_position3;
    /* Addr: h(2474), d(9332) */
    volatile Uint32 jesdtx_map_lane1_nibble3_position0;
    /* Addr: h(2478), d(9336) */
    volatile Uint32 jesdtx_map_lane1_nibble3_position1;
    /* Addr: h(247C), d(9340) */
    volatile Uint32 jesdtx_map_lane1_nibble3_position2;
    /* Addr: h(2480), d(9344) */
    volatile Uint32 jesdtx_map_lane1_nibble3_position3;
    /* Addr: h(2484), d(9348) */
    volatile Uint32 jesdtx_map_lane2_nibble0_position0;
    /* Addr: h(2488), d(9352) */
    volatile Uint32 jesdtx_map_lane2_nibble0_position1;
    /* Addr: h(248C), d(9356) */
    volatile Uint32 jesdtx_map_lane2_nibble0_position2;
    /* Addr: h(2490), d(9360) */
    volatile Uint32 jesdtx_map_lane2_nibble0_position3;
    /* Addr: h(2494), d(9364) */
    volatile Uint32 jesdtx_map_lane2_nibble1_position0;
    /* Addr: h(2498), d(9368) */
    volatile Uint32 jesdtx_map_lane2_nibble1_position1;
    /* Addr: h(249C), d(9372) */
    volatile Uint32 jesdtx_map_lane2_nibble1_position2;
    /* Addr: h(24A0), d(9376) */
    volatile Uint32 jesdtx_map_lane2_nibble1_position3;
    /* Addr: h(24A4), d(9380) */
    volatile Uint32 jesdtx_map_lane2_nibble2_position0;
    /* Addr: h(24A8), d(9384) */
    volatile Uint32 jesdtx_map_lane2_nibble2_position1;
    /* Addr: h(24AC), d(9388) */
    volatile Uint32 jesdtx_map_lane2_nibble2_position2;
    /* Addr: h(24B0), d(9392) */
    volatile Uint32 jesdtx_map_lane2_nibble2_position3;
    /* Addr: h(24B4), d(9396) */
    volatile Uint32 jesdtx_map_lane2_nibble3_position0;
    /* Addr: h(24B8), d(9400) */
    volatile Uint32 jesdtx_map_lane2_nibble3_position1;
    /* Addr: h(24BC), d(9404) */
    volatile Uint32 jesdtx_map_lane2_nibble3_position2;
    /* Addr: h(24C0), d(9408) */
    volatile Uint32 jesdtx_map_lane2_nibble3_position3;
    /* Addr: h(24C4), d(9412) */
    volatile Uint32 jesdtx_map_lane3_nibble0_position0;
    /* Addr: h(24C8), d(9416) */
    volatile Uint32 jesdtx_map_lane3_nibble0_position1;
    /* Addr: h(24CC), d(9420) */
    volatile Uint32 jesdtx_map_lane3_nibble0_position2;
    /* Addr: h(24D0), d(9424) */
    volatile Uint32 jesdtx_map_lane3_nibble0_position3;
    /* Addr: h(24D4), d(9428) */
    volatile Uint32 jesdtx_map_lane3_nibble1_position0;
    /* Addr: h(24D8), d(9432) */
    volatile Uint32 jesdtx_map_lane3_nibble1_position1;
    /* Addr: h(24DC), d(9436) */
    volatile Uint32 jesdtx_map_lane3_nibble1_position2;
    /* Addr: h(24E0), d(9440) */
    volatile Uint32 jesdtx_map_lane3_nibble1_position3;
    /* Addr: h(24E4), d(9444) */
    volatile Uint32 jesdtx_map_lane3_nibble2_position0;
    /* Addr: h(24E8), d(9448) */
    volatile Uint32 jesdtx_map_lane3_nibble2_position1;
    /* Addr: h(24EC), d(9452) */
    volatile Uint32 jesdtx_map_lane3_nibble2_position2;
    /* Addr: h(24F0), d(9456) */
    volatile Uint32 jesdtx_map_lane3_nibble2_position3;
    /* Addr: h(24F4), d(9460) */
    volatile Uint32 jesdtx_map_lane3_nibble3_position0;
    /* Addr: h(24F8), d(9464) */
    volatile Uint32 jesdtx_map_lane3_nibble3_position1;
    /* Addr: h(24FC), d(9468) */
    volatile Uint32 jesdtx_map_lane3_nibble3_position2;
    /* Addr: h(2500), d(9472) */
    volatile Uint32 jesdtx_map_lane3_nibble3_position3;
    /* Addr: h(2504), d(9476) */
    volatile Uint32 rsvd25[192];
    /* Addr: h(2804), d(10244) */
    volatile Uint32 jesdtx_map_nibble00_cfg;
    /* Addr: h(2808), d(10248) */
    volatile Uint32 jesdtx_map_nibble01_cfg;
    /* Addr: h(280C), d(10252) */
    volatile Uint32 jesdtx_map_nibble02_cfg;
    /* Addr: h(2810), d(10256) */
    volatile Uint32 jesdtx_map_nibble03_cfg;
    /* Addr: h(2814), d(10260) */
    volatile Uint32 jesdtx_map_nibble04_cfg;
    /* Addr: h(2818), d(10264) */
    volatile Uint32 jesdtx_map_nibble05_cfg;
    /* Addr: h(281C), d(10268) */
    volatile Uint32 jesdtx_map_nibble06_cfg;
    /* Addr: h(2820), d(10272) */
    volatile Uint32 jesdtx_map_nibble07_cfg;
    /* Addr: h(2824), d(10276) */
    volatile Uint32 jesdtx_map_nibble08_cfg;
    /* Addr: h(2828), d(10280) */
    volatile Uint32 jesdtx_map_nibble09_cfg;
    /* Addr: h(282C), d(10284) */
    volatile Uint32 jesdtx_map_nibble10_cfg;
    /* Addr: h(2830), d(10288) */
    volatile Uint32 jesdtx_map_nibble11_cfg;
    /* Addr: h(2834), d(10292) */
    volatile Uint32 jesdtx_map_nibble12_cfg;
    /* Addr: h(2838), d(10296) */
    volatile Uint32 jesdtx_map_nibble13_cfg;
    /* Addr: h(283C), d(10300) */
    volatile Uint32 jesdtx_map_nibble14_cfg;
    /* Addr: h(2840), d(10304) */
    volatile Uint32 jesdtx_map_nibble15_cfg;
    /* Addr: h(2844), d(10308) */
    volatile Uint32 rsvd26[1520];
    /* Addr: h(4004), d(16388) */
    volatile Uint32 jesdtx_map_test_nibble00_position0;
    /* Addr: h(4008), d(16392) */
    volatile Uint32 jesdtx_map_test_nibble00_position1;
    /* Addr: h(400C), d(16396) */
    volatile Uint32 jesdtx_map_test_nibble00_position2;
    /* Addr: h(4010), d(16400) */
    volatile Uint32 jesdtx_map_test_nibble00_position3;
    /* Addr: h(4014), d(16404) */
    volatile Uint32 jesdtx_map_test_nibble01_position0;
    /* Addr: h(4018), d(16408) */
    volatile Uint32 jesdtx_map_test_nibble01_position1;
    /* Addr: h(401C), d(16412) */
    volatile Uint32 jesdtx_map_test_nibble01_position2;
    /* Addr: h(4020), d(16416) */
    volatile Uint32 jesdtx_map_test_nibble01_position3;
    /* Addr: h(4024), d(16420) */
    volatile Uint32 jesdtx_map_test_nibble02_position0;
    /* Addr: h(4028), d(16424) */
    volatile Uint32 jesdtx_map_test_nibble02_position1;
    /* Addr: h(402C), d(16428) */
    volatile Uint32 jesdtx_map_test_nibble02_position2;
    /* Addr: h(4030), d(16432) */
    volatile Uint32 jesdtx_map_test_nibble02_position3;
    /* Addr: h(4034), d(16436) */
    volatile Uint32 jesdtx_map_test_nibble03_position0;
    /* Addr: h(4038), d(16440) */
    volatile Uint32 jesdtx_map_test_nibble03_position1;
    /* Addr: h(403C), d(16444) */
    volatile Uint32 jesdtx_map_test_nibble03_position2;
    /* Addr: h(4040), d(16448) */
    volatile Uint32 jesdtx_map_test_nibble03_position3;
    /* Addr: h(4044), d(16452) */
    volatile Uint32 jesdtx_map_test_nibble04_position0;
    /* Addr: h(4048), d(16456) */
    volatile Uint32 jesdtx_map_test_nibble04_position1;
    /* Addr: h(404C), d(16460) */
    volatile Uint32 jesdtx_map_test_nibble04_position2;
    /* Addr: h(4050), d(16464) */
    volatile Uint32 jesdtx_map_test_nibble04_position3;
    /* Addr: h(4054), d(16468) */
    volatile Uint32 jesdtx_map_test_nibble05_position0;
    /* Addr: h(4058), d(16472) */
    volatile Uint32 jesdtx_map_test_nibble05_position1;
    /* Addr: h(405C), d(16476) */
    volatile Uint32 jesdtx_map_test_nibble05_position2;
    /* Addr: h(4060), d(16480) */
    volatile Uint32 jesdtx_map_test_nibble05_position3;
    /* Addr: h(4064), d(16484) */
    volatile Uint32 jesdtx_map_test_nibble06_position0;
    /* Addr: h(4068), d(16488) */
    volatile Uint32 jesdtx_map_test_nibble06_position1;
    /* Addr: h(406C), d(16492) */
    volatile Uint32 jesdtx_map_test_nibble06_position2;
    /* Addr: h(4070), d(16496) */
    volatile Uint32 jesdtx_map_test_nibble06_position3;
    /* Addr: h(4074), d(16500) */
    volatile Uint32 jesdtx_map_test_nibble07_position0;
    /* Addr: h(4078), d(16504) */
    volatile Uint32 jesdtx_map_test_nibble07_position1;
    /* Addr: h(407C), d(16508) */
    volatile Uint32 jesdtx_map_test_nibble07_position2;
    /* Addr: h(4080), d(16512) */
    volatile Uint32 jesdtx_map_test_nibble07_position3;
    /* Addr: h(4084), d(16516) */
    volatile Uint32 jesdtx_map_test_nibble08_position0;
    /* Addr: h(4088), d(16520) */
    volatile Uint32 jesdtx_map_test_nibble08_position1;
    /* Addr: h(408C), d(16524) */
    volatile Uint32 jesdtx_map_test_nibble08_position2;
    /* Addr: h(4090), d(16528) */
    volatile Uint32 jesdtx_map_test_nibble08_position3;
    /* Addr: h(4094), d(16532) */
    volatile Uint32 jesdtx_map_test_nibble09_position0;
    /* Addr: h(4098), d(16536) */
    volatile Uint32 jesdtx_map_test_nibble09_position1;
    /* Addr: h(409C), d(16540) */
    volatile Uint32 jesdtx_map_test_nibble09_position2;
    /* Addr: h(40A0), d(16544) */
    volatile Uint32 jesdtx_map_test_nibble09_position3;
    /* Addr: h(40A4), d(16548) */
    volatile Uint32 jesdtx_map_test_nibble10_position0;
    /* Addr: h(40A8), d(16552) */
    volatile Uint32 jesdtx_map_test_nibble10_position1;
    /* Addr: h(40AC), d(16556) */
    volatile Uint32 jesdtx_map_test_nibble10_position2;
    /* Addr: h(40B0), d(16560) */
    volatile Uint32 jesdtx_map_test_nibble10_position3;
    /* Addr: h(40B4), d(16564) */
    volatile Uint32 jesdtx_map_test_nibble11_position0;
    /* Addr: h(40B8), d(16568) */
    volatile Uint32 jesdtx_map_test_nibble11_position1;
    /* Addr: h(40BC), d(16572) */
    volatile Uint32 jesdtx_map_test_nibble11_position2;
    /* Addr: h(40C0), d(16576) */
    volatile Uint32 jesdtx_map_test_nibble11_position3;
    /* Addr: h(40C4), d(16580) */
    volatile Uint32 jesdtx_map_test_nibble12_position0;
    /* Addr: h(40C8), d(16584) */
    volatile Uint32 jesdtx_map_test_nibble12_position1;
    /* Addr: h(40CC), d(16588) */
    volatile Uint32 jesdtx_map_test_nibble12_position2;
    /* Addr: h(40D0), d(16592) */
    volatile Uint32 jesdtx_map_test_nibble12_position3;
    /* Addr: h(40D4), d(16596) */
    volatile Uint32 jesdtx_map_test_nibble13_position0;
    /* Addr: h(40D8), d(16600) */
    volatile Uint32 jesdtx_map_test_nibble13_position1;
    /* Addr: h(40DC), d(16604) */
    volatile Uint32 jesdtx_map_test_nibble13_position2;
    /* Addr: h(40E0), d(16608) */
    volatile Uint32 jesdtx_map_test_nibble13_position3;
    /* Addr: h(40E4), d(16612) */
    volatile Uint32 jesdtx_map_test_nibble14_position0;
    /* Addr: h(40E8), d(16616) */
    volatile Uint32 jesdtx_map_test_nibble14_position1;
    /* Addr: h(40EC), d(16620) */
    volatile Uint32 jesdtx_map_test_nibble14_position2;
    /* Addr: h(40F0), d(16624) */
    volatile Uint32 jesdtx_map_test_nibble14_position3;
    /* Addr: h(40F4), d(16628) */
    volatile Uint32 jesdtx_map_test_nibble15_position0;
    /* Addr: h(40F8), d(16632) */
    volatile Uint32 jesdtx_map_test_nibble15_position1;
    /* Addr: h(40FC), d(16636) */
    volatile Uint32 jesdtx_map_test_nibble15_position2;
    /* Addr: h(4100), d(16640) */
    volatile Uint32 jesdtx_map_test_nibble15_position3;
    /* Addr: h(4104), d(16644) */
    volatile Uint32 rsvd27[61376];
    /* Addr: h(40004), d(262148) */
    volatile Uint32 jesdrx_base_inits;
    /* Addr: h(40008), d(262152) */
    volatile Uint32 jesdrx_base_test_bus_sel;
    /* Addr: h(4000C), d(262156) */
    volatile Uint32 jesdrx_base_test_seq_sel;
    /* Addr: h(40010), d(262160) */
    volatile Uint32 jesdrx_base_lpbk_ena;
    /* Addr: h(40014), d(262164) */
    volatile Uint32 jesdrx_base_bb_rx_ctrl;
    /* Addr: h(40018), d(262168) */
    volatile Uint32 jesdrx_base_fifo;
    /* Addr: h(4001C), d(262172) */
    volatile Uint32 jesdrx_base_sync_n_out;
    /* Addr: h(40020), d(262176) */
    volatile Uint32 jesdrx_base_sync_n_out_inv;
    /* Addr: h(40024), d(262180) */
    volatile Uint32 jesdrx_base_sysref;
    /* Addr: h(40028), d(262184) */
    volatile Uint32 jesdrx_base_sysref_cntr_lo;
    /* Addr: h(4002C), d(262188) */
    volatile Uint32 jesdrx_base_sysref_cntr_hi;
    /* Addr: h(40030), d(262192) */
    volatile Uint32 jesdrx_base_cs_state;
    /* Addr: h(40034), d(262196) */
    volatile Uint32 jesdrx_base_fs_state;
    /* Addr: h(40038), d(262200) */
    volatile Uint32 rsvd28[3];
    /* Addr: h(40044), d(262212) */
    volatile Uint32 jesdrx_ssel_ssel_addr_0;
    /* Addr: h(40048), d(262216) */
    volatile Uint32 jesdrx_ssel_ssel_addr_1;
    /* Addr: h(4004C), d(262220) */
    volatile Uint32 jesdrx_ssel_ssel_addr_2;
    /* Addr: h(40050), d(262224) */
    volatile Uint32 rsvd29[493];
    /* Addr: h(40804), d(264196) */
    volatile Uint32 jesdrx_check_sum_rx0i_ctrl;
    /* Addr: h(40808), d(264200) */
    volatile Uint32 jesdrx_check_sum_rx0i_signal_len;
    /* Addr: h(4080C), d(264204) */
    volatile Uint32 jesdrx_check_sum_rx0i_chan_sel;
    /* Addr: h(40810), d(264208) */
    volatile Uint32 jesdrx_check_sum_rx0i_result_lo;
    /* Addr: h(40814), d(264212) */
    volatile Uint32 jesdrx_check_sum_rx0i_result_hi;
    /* Addr: h(40818), d(264216) */
    volatile Uint32 rsvd30[11];
    /* Addr: h(40844), d(264260) */
    volatile Uint32 jesdrx_check_sum_rx0q_ctrl;
    /* Addr: h(40848), d(264264) */
    volatile Uint32 jesdrx_check_sum_rx0q_signal_len;
    /* Addr: h(4084C), d(264268) */
    volatile Uint32 jesdrx_check_sum_rx0q_chan_sel;
    /* Addr: h(40850), d(264272) */
    volatile Uint32 jesdrx_check_sum_rx0q_result_lo;
    /* Addr: h(40854), d(264276) */
    volatile Uint32 jesdrx_check_sum_rx0q_result_hi;
    /* Addr: h(40858), d(264280) */
    volatile Uint32 rsvd31[11];
    /* Addr: h(40884), d(264324) */
    volatile Uint32 jesdrx_check_sum_rx1i_ctrl;
    /* Addr: h(40888), d(264328) */
    volatile Uint32 jesdrx_check_sum_rx1i_signal_len;
    /* Addr: h(4088C), d(264332) */
    volatile Uint32 jesdrx_check_sum_rx1i_chan_sel;
    /* Addr: h(40890), d(264336) */
    volatile Uint32 jesdrx_check_sum_rx1i_result_lo;
    /* Addr: h(40894), d(264340) */
    volatile Uint32 jesdrx_check_sum_rx1i_result_hi;
    /* Addr: h(40898), d(264344) */
    volatile Uint32 rsvd32[11];
    /* Addr: h(408C4), d(264388) */
    volatile Uint32 jesdrx_check_sum_rx1q_ctrl;
    /* Addr: h(408C8), d(264392) */
    volatile Uint32 jesdrx_check_sum_rx1q_signal_len;
    /* Addr: h(408CC), d(264396) */
    volatile Uint32 jesdrx_check_sum_rx1q_chan_sel;
    /* Addr: h(408D0), d(264400) */
    volatile Uint32 jesdrx_check_sum_rx1q_result_lo;
    /* Addr: h(408D4), d(264404) */
    volatile Uint32 jesdrx_check_sum_rx1q_result_hi;
    /* Addr: h(408D8), d(264408) */
    volatile Uint32 rsvd33[11];
    /* Addr: h(40904), d(264452) */
    volatile Uint32 jesdrx_check_sum_rx2i_ctrl;
    /* Addr: h(40908), d(264456) */
    volatile Uint32 jesdrx_check_sum_rx2i_signal_len;
    /* Addr: h(4090C), d(264460) */
    volatile Uint32 jesdrx_check_sum_rx2i_chan_sel;
    /* Addr: h(40910), d(264464) */
    volatile Uint32 jesdrx_check_sum_rx2i_result_lo;
    /* Addr: h(40914), d(264468) */
    volatile Uint32 jesdrx_check_sum_rx2i_result_hi;
    /* Addr: h(40918), d(264472) */
    volatile Uint32 rsvd34[11];
    /* Addr: h(40944), d(264516) */
    volatile Uint32 jesdrx_check_sum_rx2q_ctrl;
    /* Addr: h(40948), d(264520) */
    volatile Uint32 jesdrx_check_sum_rx2q_signal_len;
    /* Addr: h(4094C), d(264524) */
    volatile Uint32 jesdrx_check_sum_rx2q_chan_sel;
    /* Addr: h(40950), d(264528) */
    volatile Uint32 jesdrx_check_sum_rx2q_result_lo;
    /* Addr: h(40954), d(264532) */
    volatile Uint32 jesdrx_check_sum_rx2q_result_hi;
    /* Addr: h(40958), d(264536) */
    volatile Uint32 rsvd35[171];
    /* Addr: h(40C04), d(265220) */
    volatile Uint32 jesdrx_clk_gater_link0_time_step;
    /* Addr: h(40C08), d(265224) */
    volatile Uint32 rsvd36[1];
    /* Addr: h(40C0C), d(265228) */
    volatile Uint32 jesdrx_clk_gater_link0_reset_int;
    /* Addr: h(40C10), d(265232) */
    volatile Uint32 rsvd37[1];
    /* Addr: h(40C14), d(265236) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_period_lsb;
    /* Addr: h(40C18), d(265240) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_period_msb;
    /* Addr: h(40C1C), d(265244) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_on_0_lsb;
    /* Addr: h(40C20), d(265248) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_on_0_msb;
    /* Addr: h(40C24), d(265252) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_off_0_lsb;
    /* Addr: h(40C28), d(265256) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_off_0_msb;
    /* Addr: h(40C2C), d(265260) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_on_1_lsb;
    /* Addr: h(40C30), d(265264) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_on_1_msb;
    /* Addr: h(40C34), d(265268) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_off_1_lsb;
    /* Addr: h(40C38), d(265272) */
    volatile Uint32 jesdrx_clk_gater_link0_tdd_off_1_msb;
    /* Addr: h(40C3C), d(265276) */
    volatile Uint32 rsvd38[2];
    /* Addr: h(40C44), d(265284) */
    volatile Uint32 jesdrx_clk_gater_link1_time_step;
    /* Addr: h(40C48), d(265288) */
    volatile Uint32 rsvd39[1];
    /* Addr: h(40C4C), d(265292) */
    volatile Uint32 jesdrx_clk_gater_link1_reset_int;
    /* Addr: h(40C50), d(265296) */
    volatile Uint32 rsvd40[1];
    /* Addr: h(40C54), d(265300) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_period_lsb;
    /* Addr: h(40C58), d(265304) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_period_msb;
    /* Addr: h(40C5C), d(265308) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_on_0_lsb;
    /* Addr: h(40C60), d(265312) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_on_0_msb;
    /* Addr: h(40C64), d(265316) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_off_0_lsb;
    /* Addr: h(40C68), d(265320) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_off_0_msb;
    /* Addr: h(40C6C), d(265324) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_on_1_lsb;
    /* Addr: h(40C70), d(265328) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_on_1_msb;
    /* Addr: h(40C74), d(265332) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_off_1_lsb;
    /* Addr: h(40C78), d(265336) */
    volatile Uint32 jesdrx_clk_gater_link1_tdd_off_1_msb;
    /* Addr: h(40C7C), d(265340) */
    volatile Uint32 rsvd41[226];
    /* Addr: h(41004), d(266244) */
    volatile Uint32 jesdrx_clk_gater_rx0_time_step;
    /* Addr: h(41008), d(266248) */
    volatile Uint32 rsvd42[1];
    /* Addr: h(4100C), d(266252) */
    volatile Uint32 jesdrx_clk_gater_rx0_reset_int;
    /* Addr: h(41010), d(266256) */
    volatile Uint32 rsvd43[1];
    /* Addr: h(41014), d(266260) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_period_lsb;
    /* Addr: h(41018), d(266264) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_period_msb;
    /* Addr: h(4101C), d(266268) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_on_0_lsb;
    /* Addr: h(41020), d(266272) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_on_0_msb;
    /* Addr: h(41024), d(266276) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_off_0_lsb;
    /* Addr: h(41028), d(266280) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_off_0_msb;
    /* Addr: h(4102C), d(266284) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_on_1_lsb;
    /* Addr: h(41030), d(266288) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_on_1_msb;
    /* Addr: h(41034), d(266292) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_off_1_lsb;
    /* Addr: h(41038), d(266296) */
    volatile Uint32 jesdrx_clk_gater_rx0_tdd_off_1_msb;
    /* Addr: h(4103C), d(266300) */
    volatile Uint32 rsvd44[2];
    /* Addr: h(41044), d(266308) */
    volatile Uint32 jesdrx_clk_gater_rx1_time_step;
    /* Addr: h(41048), d(266312) */
    volatile Uint32 rsvd45[1];
    /* Addr: h(4104C), d(266316) */
    volatile Uint32 jesdrx_clk_gater_rx1_reset_int;
    /* Addr: h(41050), d(266320) */
    volatile Uint32 rsvd46[1];
    /* Addr: h(41054), d(266324) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_period_lsb;
    /* Addr: h(41058), d(266328) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_period_msb;
    /* Addr: h(4105C), d(266332) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_on_0_lsb;
    /* Addr: h(41060), d(266336) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_on_0_msb;
    /* Addr: h(41064), d(266340) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_off_0_lsb;
    /* Addr: h(41068), d(266344) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_off_0_msb;
    /* Addr: h(4106C), d(266348) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_on_1_lsb;
    /* Addr: h(41070), d(266352) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_on_1_msb;
    /* Addr: h(41074), d(266356) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_off_1_lsb;
    /* Addr: h(41078), d(266360) */
    volatile Uint32 jesdrx_clk_gater_rx1_tdd_off_1_msb;
    /* Addr: h(4107C), d(266364) */
    volatile Uint32 rsvd47[2];
    /* Addr: h(41084), d(266372) */
    volatile Uint32 jesdrx_clk_gater_rx2_time_step;
    /* Addr: h(41088), d(266376) */
    volatile Uint32 rsvd48[1];
    /* Addr: h(4108C), d(266380) */
    volatile Uint32 jesdrx_clk_gater_rx2_reset_int;
    /* Addr: h(41090), d(266384) */
    volatile Uint32 rsvd49[1];
    /* Addr: h(41094), d(266388) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_period_lsb;
    /* Addr: h(41098), d(266392) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_period_msb;
    /* Addr: h(4109C), d(266396) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_on_0_lsb;
    /* Addr: h(410A0), d(266400) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_on_0_msb;
    /* Addr: h(410A4), d(266404) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_off_0_lsb;
    /* Addr: h(410A8), d(266408) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_off_0_msb;
    /* Addr: h(410AC), d(266412) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_on_1_lsb;
    /* Addr: h(410B0), d(266416) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_on_1_msb;
    /* Addr: h(410B4), d(266420) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_off_1_lsb;
    /* Addr: h(410B8), d(266424) */
    volatile Uint32 jesdrx_clk_gater_rx2_tdd_off_1_msb;
    /* Addr: h(410BC), d(266428) */
    volatile Uint32 rsvd50[210];
    /* Addr: h(41404), d(267268) */
    volatile Uint32 jesdrx_lane0_cfg;
    /* Addr: h(41408), d(267272) */
    volatile Uint32 jesdrx_lane1_cfg;
    /* Addr: h(4140C), d(267276) */
    volatile Uint32 jesdrx_lane2_cfg;
    /* Addr: h(41410), d(267280) */
    volatile Uint32 jesdrx_lane3_cfg;
    /* Addr: h(41414), d(267284) */
    volatile Uint32 rsvd51[252];
    /* Addr: h(41804), d(268292) */
    volatile Uint32 jesdrx_link0_cfg0;
    /* Addr: h(41808), d(268296) */
    volatile Uint32 jesdrx_link0_cfg1;
    /* Addr: h(4180C), d(268300) */
    volatile Uint32 jesdrx_link0_cfg2;
    /* Addr: h(41810), d(268304) */
    volatile Uint32 jesdrx_link0_cfg3;
    /* Addr: h(41814), d(268308) */
    volatile Uint32 jesdrx_link0_cfg4;
    /* Addr: h(41818), d(268312) */
    volatile Uint32 jesdrx_link0_cfg5;
    /* Addr: h(4181C), d(268316) */
    volatile Uint32 jesdrx_link0_cfg6;
    /* Addr: h(41820), d(268320) */
    volatile Uint32 jesdrx_link0_cfg7;
    /* Addr: h(41824), d(268324) */
    volatile Uint32 jesdrx_link0_cfg8;
    /* Addr: h(41828), d(268328) */
    volatile Uint32 jesdrx_link0_cfg9;
    /* Addr: h(4182C), d(268332) */
    volatile Uint32 jesdrx_link0_cfg10;
    /* Addr: h(41830), d(268336) */
    volatile Uint32 jesdrx_link0_cfg11;
    /* Addr: h(41834), d(268340) */
    volatile Uint32 rsvd52[4];
    /* Addr: h(41844), d(268356) */
    volatile Uint32 jesdrx_link1_cfg0;
    /* Addr: h(41848), d(268360) */
    volatile Uint32 jesdrx_link1_cfg1;
    /* Addr: h(4184C), d(268364) */
    volatile Uint32 jesdrx_link1_cfg2;
    /* Addr: h(41850), d(268368) */
    volatile Uint32 jesdrx_link1_cfg3;
    /* Addr: h(41854), d(268372) */
    volatile Uint32 jesdrx_link1_cfg4;
    /* Addr: h(41858), d(268376) */
    volatile Uint32 jesdrx_link1_cfg5;
    /* Addr: h(4185C), d(268380) */
    volatile Uint32 jesdrx_link1_cfg6;
    /* Addr: h(41860), d(268384) */
    volatile Uint32 jesdrx_link1_cfg7;
    /* Addr: h(41864), d(268388) */
    volatile Uint32 jesdrx_link1_cfg8;
    /* Addr: h(41868), d(268392) */
    volatile Uint32 jesdrx_link1_cfg9;
    /* Addr: h(4186C), d(268396) */
    volatile Uint32 jesdrx_link1_cfg10;
    /* Addr: h(41870), d(268400) */
    volatile Uint32 jesdrx_link1_cfg11;
    /* Addr: h(41874), d(268404) */
    volatile Uint32 rsvd53[228];
    /* Addr: h(41C04), d(269316) */
    volatile Uint32 jesdrx_intr_lane0_mask;
    /* Addr: h(41C08), d(269320) */
    volatile Uint32 jesdrx_intr_lane0_intr;
    /* Addr: h(41C0C), d(269324) */
    volatile Uint32 jesdrx_intr_lane0_force;
    /* Addr: h(41C10), d(269328) */
    volatile Uint32 rsvd54[13];
    /* Addr: h(41C44), d(269380) */
    volatile Uint32 jesdrx_intr_lane1_mask;
    /* Addr: h(41C48), d(269384) */
    volatile Uint32 jesdrx_intr_lane1_intr;
    /* Addr: h(41C4C), d(269388) */
    volatile Uint32 jesdrx_intr_lane1_force;
    /* Addr: h(41C50), d(269392) */
    volatile Uint32 rsvd55[13];
    /* Addr: h(41C84), d(269444) */
    volatile Uint32 jesdrx_intr_lane2_mask;
    /* Addr: h(41C88), d(269448) */
    volatile Uint32 jesdrx_intr_lane2_intr;
    /* Addr: h(41C8C), d(269452) */
    volatile Uint32 jesdrx_intr_lane2_force;
    /* Addr: h(41C90), d(269456) */
    volatile Uint32 rsvd56[13];
    /* Addr: h(41CC4), d(269508) */
    volatile Uint32 jesdrx_intr_lane3_mask;
    /* Addr: h(41CC8), d(269512) */
    volatile Uint32 jesdrx_intr_lane3_intr;
    /* Addr: h(41CCC), d(269516) */
    volatile Uint32 jesdrx_intr_lane3_force;
    /* Addr: h(41CD0), d(269520) */
    volatile Uint32 rsvd57[205];
    /* Addr: h(42004), d(270340) */
    volatile Uint32 jesdrx_intr_sysref_mask;
    /* Addr: h(42008), d(270344) */
    volatile Uint32 jesdrx_intr_sysref_intr;
    /* Addr: h(4200C), d(270348) */
    volatile Uint32 jesdrx_intr_sysref_force;
    /* Addr: h(42010), d(270352) */
    volatile Uint32 rsvd58[253];
    /* Addr: h(42404), d(271364) */
    volatile Uint32 jesdrx_map_lane0_cfg;
    /* Addr: h(42408), d(271368) */
    volatile Uint32 jesdrx_map_lane1_cfg;
    /* Addr: h(4240C), d(271372) */
    volatile Uint32 jesdrx_map_lane2_cfg;
    /* Addr: h(42410), d(271376) */
    volatile Uint32 jesdrx_map_lane3_cfg;
    /* Addr: h(42414), d(271380) */
    volatile Uint32 rsvd59[252];
    /* Addr: h(42804), d(272388) */
    volatile Uint32 jesdrx_map_nibble00_position0;
    /* Addr: h(42808), d(272392) */
    volatile Uint32 jesdrx_map_nibble00_position1;
    /* Addr: h(4280C), d(272396) */
    volatile Uint32 jesdrx_map_nibble00_position2;
    /* Addr: h(42810), d(272400) */
    volatile Uint32 jesdrx_map_nibble00_position3;
    /* Addr: h(42814), d(272404) */
    volatile Uint32 rsvd60[12];
    /* Addr: h(42844), d(272452) */
    volatile Uint32 jesdrx_map_nibble01_position0;
    /* Addr: h(42848), d(272456) */
    volatile Uint32 jesdrx_map_nibble01_position1;
    /* Addr: h(4284C), d(272460) */
    volatile Uint32 jesdrx_map_nibble01_position2;
    /* Addr: h(42850), d(272464) */
    volatile Uint32 jesdrx_map_nibble01_position3;
    /* Addr: h(42854), d(272468) */
    volatile Uint32 rsvd61[12];
    /* Addr: h(42884), d(272516) */
    volatile Uint32 jesdrx_map_nibble02_position0;
    /* Addr: h(42888), d(272520) */
    volatile Uint32 jesdrx_map_nibble02_position1;
    /* Addr: h(4288C), d(272524) */
    volatile Uint32 jesdrx_map_nibble02_position2;
    /* Addr: h(42890), d(272528) */
    volatile Uint32 jesdrx_map_nibble02_position3;
    /* Addr: h(42894), d(272532) */
    volatile Uint32 rsvd62[12];
    /* Addr: h(428C4), d(272580) */
    volatile Uint32 jesdrx_map_nibble03_position0;
    /* Addr: h(428C8), d(272584) */
    volatile Uint32 jesdrx_map_nibble03_position1;
    /* Addr: h(428CC), d(272588) */
    volatile Uint32 jesdrx_map_nibble03_position2;
    /* Addr: h(428D0), d(272592) */
    volatile Uint32 jesdrx_map_nibble03_position3;
    /* Addr: h(428D4), d(272596) */
    volatile Uint32 rsvd63[12];
    /* Addr: h(42904), d(272644) */
    volatile Uint32 jesdrx_map_nibble04_position0;
    /* Addr: h(42908), d(272648) */
    volatile Uint32 jesdrx_map_nibble04_position1;
    /* Addr: h(4290C), d(272652) */
    volatile Uint32 jesdrx_map_nibble04_position2;
    /* Addr: h(42910), d(272656) */
    volatile Uint32 jesdrx_map_nibble04_position3;
    /* Addr: h(42914), d(272660) */
    volatile Uint32 rsvd64[12];
    /* Addr: h(42944), d(272708) */
    volatile Uint32 jesdrx_map_nibble05_position0;
    /* Addr: h(42948), d(272712) */
    volatile Uint32 jesdrx_map_nibble05_position1;
    /* Addr: h(4294C), d(272716) */
    volatile Uint32 jesdrx_map_nibble05_position2;
    /* Addr: h(42950), d(272720) */
    volatile Uint32 jesdrx_map_nibble05_position3;
    /* Addr: h(42954), d(272724) */
    volatile Uint32 rsvd65[12];
    /* Addr: h(42984), d(272772) */
    volatile Uint32 jesdrx_map_nibble06_position0;
    /* Addr: h(42988), d(272776) */
    volatile Uint32 jesdrx_map_nibble06_position1;
    /* Addr: h(4298C), d(272780) */
    volatile Uint32 jesdrx_map_nibble06_position2;
    /* Addr: h(42990), d(272784) */
    volatile Uint32 jesdrx_map_nibble06_position3;
    /* Addr: h(42994), d(272788) */
    volatile Uint32 rsvd66[12];
    /* Addr: h(429C4), d(272836) */
    volatile Uint32 jesdrx_map_nibble07_position0;
    /* Addr: h(429C8), d(272840) */
    volatile Uint32 jesdrx_map_nibble07_position1;
    /* Addr: h(429CC), d(272844) */
    volatile Uint32 jesdrx_map_nibble07_position2;
    /* Addr: h(429D0), d(272848) */
    volatile Uint32 jesdrx_map_nibble07_position3;
    /* Addr: h(429D4), d(272852) */
    volatile Uint32 rsvd67[12];
    /* Addr: h(42A04), d(272900) */
    volatile Uint32 jesdrx_map_nibble08_position0;
    /* Addr: h(42A08), d(272904) */
    volatile Uint32 jesdrx_map_nibble08_position1;
    /* Addr: h(42A0C), d(272908) */
    volatile Uint32 jesdrx_map_nibble08_position2;
    /* Addr: h(42A10), d(272912) */
    volatile Uint32 jesdrx_map_nibble08_position3;
    /* Addr: h(42A14), d(272916) */
    volatile Uint32 rsvd68[12];
    /* Addr: h(42A44), d(272964) */
    volatile Uint32 jesdrx_map_nibble09_position0;
    /* Addr: h(42A48), d(272968) */
    volatile Uint32 jesdrx_map_nibble09_position1;
    /* Addr: h(42A4C), d(272972) */
    volatile Uint32 jesdrx_map_nibble09_position2;
    /* Addr: h(42A50), d(272976) */
    volatile Uint32 jesdrx_map_nibble09_position3;
    /* Addr: h(42A54), d(272980) */
    volatile Uint32 rsvd69[12];
    /* Addr: h(42A84), d(273028) */
    volatile Uint32 jesdrx_map_nibble10_position0;
    /* Addr: h(42A88), d(273032) */
    volatile Uint32 jesdrx_map_nibble10_position1;
    /* Addr: h(42A8C), d(273036) */
    volatile Uint32 jesdrx_map_nibble10_position2;
    /* Addr: h(42A90), d(273040) */
    volatile Uint32 jesdrx_map_nibble10_position3;
    /* Addr: h(42A94), d(273044) */
    volatile Uint32 rsvd70[12];
    /* Addr: h(42AC4), d(273092) */
    volatile Uint32 jesdrx_map_nibble11_position0;
    /* Addr: h(42AC8), d(273096) */
    volatile Uint32 jesdrx_map_nibble11_position1;
    /* Addr: h(42ACC), d(273100) */
    volatile Uint32 jesdrx_map_nibble11_position2;
    /* Addr: h(42AD0), d(273104) */
    volatile Uint32 jesdrx_map_nibble11_position3;
    /* Addr: h(42AD4), d(273108) */
    volatile Uint32 rsvd71[12];
    /* Addr: h(42B04), d(273156) */
    volatile Uint32 jesdrx_map_nibble12_position0;
    /* Addr: h(42B08), d(273160) */
    volatile Uint32 jesdrx_map_nibble12_position1;
    /* Addr: h(42B0C), d(273164) */
    volatile Uint32 jesdrx_map_nibble12_position2;
    /* Addr: h(42B10), d(273168) */
    volatile Uint32 jesdrx_map_nibble12_position3;
    /* Addr: h(42B14), d(273172) */
    volatile Uint32 rsvd72[12];
    /* Addr: h(42B44), d(273220) */
    volatile Uint32 jesdrx_map_nibble13_position0;
    /* Addr: h(42B48), d(273224) */
    volatile Uint32 jesdrx_map_nibble13_position1;
    /* Addr: h(42B4C), d(273228) */
    volatile Uint32 jesdrx_map_nibble13_position2;
    /* Addr: h(42B50), d(273232) */
    volatile Uint32 jesdrx_map_nibble13_position3;
    /* Addr: h(42B54), d(273236) */
    volatile Uint32 rsvd73[12];
    /* Addr: h(42B84), d(273284) */
    volatile Uint32 jesdrx_map_nibble14_position0;
    /* Addr: h(42B88), d(273288) */
    volatile Uint32 jesdrx_map_nibble14_position1;
    /* Addr: h(42B8C), d(273292) */
    volatile Uint32 jesdrx_map_nibble14_position2;
    /* Addr: h(42B90), d(273296) */
    volatile Uint32 jesdrx_map_nibble14_position3;
    /* Addr: h(42B94), d(273300) */
    volatile Uint32 rsvd74[12];
    /* Addr: h(42BC4), d(273348) */
    volatile Uint32 jesdrx_map_nibble15_position0;
    /* Addr: h(42BC8), d(273352) */
    volatile Uint32 jesdrx_map_nibble15_position1;
    /* Addr: h(42BCC), d(273356) */
    volatile Uint32 jesdrx_map_nibble15_position2;
    /* Addr: h(42BD0), d(273360) */
    volatile Uint32 jesdrx_map_nibble15_position3;
    /* Addr: h(42BD4), d(273364) */
    volatile Uint32 rsvd75[12];
    /* Addr: h(42C04), d(273412) */
    volatile Uint32 jesdrx_map_nibble16_position0;
    /* Addr: h(42C08), d(273416) */
    volatile Uint32 jesdrx_map_nibble16_position1;
    /* Addr: h(42C0C), d(273420) */
    volatile Uint32 jesdrx_map_nibble16_position2;
    /* Addr: h(42C10), d(273424) */
    volatile Uint32 jesdrx_map_nibble16_position3;
    /* Addr: h(42C14), d(273428) */
    volatile Uint32 rsvd76[12];
    /* Addr: h(42C44), d(273476) */
    volatile Uint32 jesdrx_map_nibble17_position0;
    /* Addr: h(42C48), d(273480) */
    volatile Uint32 jesdrx_map_nibble17_position1;
    /* Addr: h(42C4C), d(273484) */
    volatile Uint32 jesdrx_map_nibble17_position2;
    /* Addr: h(42C50), d(273488) */
    volatile Uint32 jesdrx_map_nibble17_position3;
    /* Addr: h(42C54), d(273492) */
    volatile Uint32 rsvd77[12];
    /* Addr: h(42C84), d(273540) */
    volatile Uint32 jesdrx_map_nibble18_position0;
    /* Addr: h(42C88), d(273544) */
    volatile Uint32 jesdrx_map_nibble18_position1;
    /* Addr: h(42C8C), d(273548) */
    volatile Uint32 jesdrx_map_nibble18_position2;
    /* Addr: h(42C90), d(273552) */
    volatile Uint32 jesdrx_map_nibble18_position3;
    /* Addr: h(42C94), d(273556) */
    volatile Uint32 rsvd78[12];
    /* Addr: h(42CC4), d(273604) */
    volatile Uint32 jesdrx_map_nibble19_position0;
    /* Addr: h(42CC8), d(273608) */
    volatile Uint32 jesdrx_map_nibble19_position1;
    /* Addr: h(42CCC), d(273612) */
    volatile Uint32 jesdrx_map_nibble19_position2;
    /* Addr: h(42CD0), d(273616) */
    volatile Uint32 jesdrx_map_nibble19_position3;
    /* Addr: h(42CD4), d(273620) */
    volatile Uint32 rsvd79[12];
    /* Addr: h(42D04), d(273668) */
    volatile Uint32 jesdrx_map_nibble20_position0;
    /* Addr: h(42D08), d(273672) */
    volatile Uint32 jesdrx_map_nibble20_position1;
    /* Addr: h(42D0C), d(273676) */
    volatile Uint32 jesdrx_map_nibble20_position2;
    /* Addr: h(42D10), d(273680) */
    volatile Uint32 jesdrx_map_nibble20_position3;
    /* Addr: h(42D14), d(273684) */
    volatile Uint32 rsvd80[12];
    /* Addr: h(42D44), d(273732) */
    volatile Uint32 jesdrx_map_nibble21_position0;
    /* Addr: h(42D48), d(273736) */
    volatile Uint32 jesdrx_map_nibble21_position1;
    /* Addr: h(42D4C), d(273740) */
    volatile Uint32 jesdrx_map_nibble21_position2;
    /* Addr: h(42D50), d(273744) */
    volatile Uint32 jesdrx_map_nibble21_position3;
    /* Addr: h(42D54), d(273748) */
    volatile Uint32 rsvd81[12];
    /* Addr: h(42D84), d(273796) */
    volatile Uint32 jesdrx_map_nibble22_position0;
    /* Addr: h(42D88), d(273800) */
    volatile Uint32 jesdrx_map_nibble22_position1;
    /* Addr: h(42D8C), d(273804) */
    volatile Uint32 jesdrx_map_nibble22_position2;
    /* Addr: h(42D90), d(273808) */
    volatile Uint32 jesdrx_map_nibble22_position3;
    /* Addr: h(42D94), d(273812) */
    volatile Uint32 rsvd82[12];
    /* Addr: h(42DC4), d(273860) */
    volatile Uint32 jesdrx_map_nibble23_position0;
    /* Addr: h(42DC8), d(273864) */
    volatile Uint32 jesdrx_map_nibble23_position1;
    /* Addr: h(42DCC), d(273868) */
    volatile Uint32 jesdrx_map_nibble23_position2;
    /* Addr: h(42DD0), d(273872) */
    volatile Uint32 jesdrx_map_nibble23_position3;
    /* Addr: h(42DD4), d(273876) */
    volatile Uint32 rsvd83[1164];
    /* Addr: h(44004), d(278532) */
    volatile Uint32 jesdrx_map_test_lane0_position0;
    /* Addr: h(44008), d(278536) */
    volatile Uint32 jesdrx_map_test_lane0_position1;
    /* Addr: h(4400C), d(278540) */
    volatile Uint32 jesdrx_map_test_lane0_position2;
    /* Addr: h(44010), d(278544) */
    volatile Uint32 jesdrx_map_test_lane0_position3;
    /* Addr: h(44014), d(278548) */
    volatile Uint32 jesdrx_map_test_lane1_position0;
    /* Addr: h(44018), d(278552) */
    volatile Uint32 jesdrx_map_test_lane1_position1;
    /* Addr: h(4401C), d(278556) */
    volatile Uint32 jesdrx_map_test_lane1_position2;
    /* Addr: h(44020), d(278560) */
    volatile Uint32 jesdrx_map_test_lane1_position3;
    /* Addr: h(44024), d(278564) */
    volatile Uint32 jesdrx_map_test_lane2_position0;
    /* Addr: h(44028), d(278568) */
    volatile Uint32 jesdrx_map_test_lane2_position1;
    /* Addr: h(4402C), d(278572) */
    volatile Uint32 jesdrx_map_test_lane2_position2;
    /* Addr: h(44030), d(278576) */
    volatile Uint32 jesdrx_map_test_lane2_position3;
    /* Addr: h(44034), d(278580) */
    volatile Uint32 jesdrx_map_test_lane3_position0;
    /* Addr: h(44038), d(278584) */
    volatile Uint32 jesdrx_map_test_lane3_position1;
    /* Addr: h(4403C), d(278588) */
    volatile Uint32 jesdrx_map_test_lane3_position2;
    /* Addr: h(44040), d(278592) */
    volatile Uint32 jesdrx_map_test_lane3_position3;
} CSL_DFE_JESD_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* JESDTX_BASE_INITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 clear_data_lane3 : 1;
    Uint32 clear_data_lane2 : 1;
    Uint32 clear_data_lane1 : 1;
    Uint32 clear_data_lane0 : 1;
    Uint32 rsvd0 : 1;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 rsvd0 : 1;
    Uint32 clear_data_lane0 : 1;
    Uint32 clear_data_lane1 : 1;
    Uint32 clear_data_lane2 : 1;
    Uint32 clear_data_lane3 : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_INITS_REG;

/* sync select for initialization signals */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INITS_SSEL_RESETVAL (0x0000000Fu)

/* initialize all clock gating */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* initialize all state machines */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* clear output data on all lanes */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* clear output data on lane 0 */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE0_RESETVAL (0x00000001u)

/* clear output data on lane 1 */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE1_RESETVAL (0x00000001u)

/* clear output data on lane 2 */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE2_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE2_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE2_RESETVAL (0x00000001u)

/* clear output data on lane 3 */
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE3_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE3_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_CLEAR_DATA_LANE3_RESETVAL (0x00000001u)

#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_ADDR (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_INITS_REG_RESETVAL (0x00000F7Fu)

/* JESDTX_BASE_TX_INPUTS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 19;
    Uint32 rxtx_lpbk_ena_tx1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 rxtx_lpbk_ena_tx0 : 1;
    Uint32 rsvd1 : 1;
    Uint32 cken_dly_tx1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 cken_dly_tx0 : 3;
#else 
    Uint32 cken_dly_tx0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 cken_dly_tx1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 rxtx_lpbk_ena_tx0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 rxtx_lpbk_ena_tx1 : 1;
    Uint32 rsvd3 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG;

/* clock gating delay for tx0 */
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX0_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX0_RESETVAL (0x00000000u)

/* clock gating delay for tx1 */
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX1_MASK (0x00000070u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_CKEN_DLY_TX1_RESETVAL (0x00000000u)

/* jesdrxmap to jesdtxmap loopback for tx0 */
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX0_RESETVAL (0x00000000u)

/* jesdrxmap to jesdtxmap loopback for tx1 */
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX1_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX1_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RXTX_LPBK_ENA_TX1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_ADDR (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_TX_INPUTS_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_TEST_BUS_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 test_bus_sel : 8;
#else 
    Uint32 test_bus_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG;

/* test bus select */
#define CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG_ADDR (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_BUS_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_TEST_SEQ_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 lane3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 lane2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 lane1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 lane0 : 3;
#else 
    Uint32 lane0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 lane1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 lane2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 lane3 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG;

/* link layer test sequence select for lane 0 */
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE0_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE0_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 1 */
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE1_MASK (0x00000070u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE1_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 2 */
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE2_MASK (0x00000700u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE2_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 3 */
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE3_MASK (0x00007000u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_ADDR (0x00000010u)
#define CSL_DFE_JESD_JESDTX_BASE_TEST_SEQ_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_SYNC_N */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 26;
    Uint32 inv_link1 : 1;
    Uint32 inv_link0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 lpbk_ena_link1 : 1;
    Uint32 lpbk_ena_link0 : 1;
#else 
    Uint32 lpbk_ena_link0 : 1;
    Uint32 lpbk_ena_link1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 inv_link0 : 1;
    Uint32 inv_link1 : 1;
    Uint32 rsvd1 : 26;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG;

/* SYNC~ loopback from JESDRX output to JESDTX input for link 0 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK0_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK0_RESETVAL (0x00000000u)

/* SYNC~ loopback from JESDRX output to JESDTX input for link 1 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK1_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK1_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_LPBK_ENA_LINK1_RESETVAL (0x00000000u)

/* SYNC~ input polarity invert for link 0 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK0_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK0_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK0_RESETVAL (0x00000000u)

/* SYNC~ input polarity invert for link 1 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK1_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK1_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_INV_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_ADDR (0x00000014u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_N_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_BB_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 23;
    Uint32 bb_link_sel : 1;
    Uint32 rsvd0 : 4;
    Uint32 bb_lane_ena : 4;
#else 
    Uint32 bb_lane_ena : 4;
    Uint32 rsvd0 : 4;
    Uint32 bb_link_sel : 1;
    Uint32 rsvd1 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG;

/* 0 = disable BB interface, otherwise each bit enables BB input to each lane */
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LANE_ENA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LANE_ENA_RESETVAL (0x00000000u)

/* link select for BB interface to mux a multiframe alignment signal to the BB */
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LINK_SEL_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LINK_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_BB_LINK_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_ADDR (0x00000018u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_CTRL_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_BB_ERR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 bb_multiframe_align_err : 1;
#else 
    Uint32 bb_multiframe_align_err : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG;

/* BB interface multiframe alignment error */
#define CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG_BB_MULTIFRAME_ALIGN_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG_BB_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG_BB_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG_ADDR (0x0000001Cu)
#define CSL_DFE_JESD_JESDTX_BASE_BB_ERR_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_FIFO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 23;
    Uint32 disable_fifo_errors_zero_data : 1;
    Uint32 rsvd0 : 4;
    Uint32 fifo_read_delay : 4;
#else 
    Uint32 fifo_read_delay : 4;
    Uint32 rsvd0 : 4;
    Uint32 disable_fifo_errors_zero_data : 1;
    Uint32 rsvd1 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_FIFO_REG;

/* FIFO read delay applied to all SERDES TX FIFOs */
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_FIFO_READ_DELAY_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_FIFO_READ_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_FIFO_READ_DELAY_RESETVAL (0x00000003u)

/* 0 = allow FIFO errors to zero data */
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_ADDR (0x00000020u)
#define CSL_DFE_JESD_JESDTX_BASE_FIFO_REG_RESETVAL (0x00000003u)

/* JESDTX_BASE_SYSREF */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 force_sysref_request_auto_off : 8;
    Uint32 rsvd0 : 3;
    Uint32 force_sysref_request : 1;
    Uint32 sysref_dly_sel : 4;
#else 
    Uint32 sysref_dly_sel : 4;
    Uint32 force_sysref_request : 1;
    Uint32 rsvd0 : 3;
    Uint32 force_sysref_request_auto_off : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG;

/* SYSREF delay line select */
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_SYSREF_DLY_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_SYSREF_DLY_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_SYSREF_DLY_SEL_RESETVAL (0x00000000u)

/* force SYSREF request */
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_RESETVAL (0x00000000u)

/* auto off timer for forced SYSREF request, 0 = disable auto off */
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_ADDR (0x00000024u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_SYSREF_CNTR_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sysref_cntr_15_0 : 16;
#else 
    Uint32 sysref_cntr_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG;

/* SYSREF alignment counter bits [15:0] */
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG_ADDR (0x00000028u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_SYSREF_CNTR_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sysref_cntr_31_16 : 16;
#else 
    Uint32 sysref_cntr_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG;

/* SYSREF alignment counter bits [31:16] */
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG_ADDR (0x0000002Cu)
#define CSL_DFE_JESD_JESDTX_BASE_SYSREF_CNTR_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_SYNC_STATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 lane3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane0 : 2;
#else 
    Uint32 lane0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG;

/* synchronization state machine status for lane 0 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE0_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE0_RESETVAL (0x00000000u)

/* synchronization state machine status for lane 1 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE1_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE1_RESETVAL (0x00000000u)

/* synchronization state machine status for lane 2 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE2_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE2_RESETVAL (0x00000000u)

/* synchronization state machine status for lane 3 */
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE3_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_ADDR (0x00000030u)
#define CSL_DFE_JESD_JESDTX_BASE_SYNC_STATE_REG_RESETVAL (0x00000000u)

/* JESDTX_BASE_FIRST_SYNC_REQUEST */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 27;
    Uint32 link1 : 1;
    Uint32 rsvd0 : 3;
    Uint32 link0 : 1;
#else 
    Uint32 link0 : 1;
    Uint32 rsvd0 : 3;
    Uint32 link1 : 1;
    Uint32 rsvd1 : 27;
#endif 
} CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG;

/* first sync request received for link 0 */
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK0_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK0_RESETVAL (0x00000000u)

/* first sync request received for link 1 */
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK1_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_ADDR (0x00000034u)
#define CSL_DFE_JESD_JESDTX_BASE_FIRST_SYNC_REQUEST_REG_RESETVAL (0x00000000u)

/* JESDTX_SSEL_SSEL_ADDR_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen_ssel_txq1 : 4;
    Uint32 signal_gen_ssel_txi1 : 4;
    Uint32 signal_gen_ssel_txq0 : 4;
    Uint32 signal_gen_ssel_txi0 : 4;
#else 
    Uint32 signal_gen_ssel_txi0 : 4;
    Uint32 signal_gen_ssel_txq0 : 4;
    Uint32 signal_gen_ssel_txi1 : 4;
    Uint32 signal_gen_ssel_txq1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG;

/* sync select for signal generator for tx0i */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI0_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI0_RESETVAL (0x00000000u)

/* sync select for signal generator for tx0q */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ0_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ0_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ0_RESETVAL (0x00000000u)

/* sync select for signal generator for tx1i */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI1_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXI1_RESETVAL (0x00000000u)

/* sync select for signal generator for tx1q */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ1_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ1_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_SIGNAL_GEN_SSEL_TXQ1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_ADDR (0x00000044u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_0_REG_RESETVAL (0x00000000u)

/* JESDTX_SSEL_SSEL_ADDR_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_ssel_lane3 : 4;
    Uint32 check_sum_ssel_lane2 : 4;
    Uint32 check_sum_ssel_lane1 : 4;
    Uint32 check_sum_ssel_lane0 : 4;
#else 
    Uint32 check_sum_ssel_lane0 : 4;
    Uint32 check_sum_ssel_lane1 : 4;
    Uint32 check_sum_ssel_lane2 : 4;
    Uint32 check_sum_ssel_lane3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG;

/* sync select for check sum for lane 0 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE0_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE0_RESETVAL (0x00000000u)

/* sync select for check sum for lane 1 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE1_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE1_RESETVAL (0x00000000u)

/* sync select for check sum for lane 2 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE2_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE2_RESETVAL (0x00000000u)

/* sync select for check sum for lane 3 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE3_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_ADDR (0x00000048u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_1_REG_RESETVAL (0x00000000u)

/* JESDTX_SSEL_SSEL_ADDR_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tx_sysref_mode_ssel : 4;
    Uint32 sysref_cntr_ssel : 4;
    Uint32 init_state_ssel_link1 : 4;
    Uint32 init_state_ssel_link0 : 4;
#else 
    Uint32 init_state_ssel_link0 : 4;
    Uint32 init_state_ssel_link1 : 4;
    Uint32 sysref_cntr_ssel : 4;
    Uint32 tx_sysref_mode_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG;

/* sync select for init_state for link 0 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK0_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK0_RESETVAL (0x00000000u)

/* sync select for init_state for link 1 */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK1_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_INIT_STATE_SSEL_LINK1_RESETVAL (0x00000000u)

/* sync select for SYSREF alignment counter */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_RESETVAL (0x00000000u)

/* sync select for SYSREF mode */
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_TX_SYSREF_MODE_SSEL_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_TX_SYSREF_MODE_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_TX_SYSREF_MODE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_ADDR (0x0000004Cu)
#define CSL_DFE_JESD_JESDTX_SSEL_SSEL_ADDR_2_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_ADDR (0x00000404u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GENERAL_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG_ADDR (0x00000408u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG_ADDR (0x0000040Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG_ADDR (0x00000410u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG_ADDR (0x00000414u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG_ADDR (0x00000418u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG_ADDR (0x0000041Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG_ADDR (0x00000420u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI0_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_ADDR (0x00000444u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GENERAL_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG_ADDR (0x00000448u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG_ADDR (0x0000044Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG_ADDR (0x00000450u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG_ADDR (0x00000454u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG_ADDR (0x00000458u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG_ADDR (0x0000045Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG_ADDR (0x00000460u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ0_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_ADDR (0x00000484u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GENERAL_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG_ADDR (0x00000488u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG_ADDR (0x0000048Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG_ADDR (0x00000490u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG_ADDR (0x00000494u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG_ADDR (0x00000498u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG_ADDR (0x0000049Cu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG_ADDR (0x000004A0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXI1_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_ADDR (0x000004C4u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GENERAL_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG_ADDR (0x000004C8u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG_ADDR (0x000004CCu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG_ADDR (0x000004D0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG_ADDR (0x000004D4u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG_ADDR (0x000004D8u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG_ADDR (0x000004DCu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG_ADDR (0x000004E0u)
#define CSL_DFE_JESD_JESDTX_SIGNAL_GEN_TXQ1_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE0_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG;

/* 0 = return check sum, 1 = INVALID (latency calculation) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* UNUSED (latency calculation - clocks that data must remain stable after pulse) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_ADDR (0x00000804u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CTRL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG;

/* UNUSED (latency calculation - width of data pulse from signal_gen) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG_ADDR (0x00000808u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE0_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG;

/* UNUSED (latency calculation - channel select specified by clocks after frame) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG_ADDR (0x0000080Cu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE0_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG;

/* check sum result LSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG_ADDR (0x00000810u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE0_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG;

/* check sum result MSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG_ADDR (0x00000814u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE0_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE1_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG;

/* 0 = return check sum, 1 = INVALID (latency calculation) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* UNUSED (latency calculation - clocks that data must remain stable after pulse) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_ADDR (0x00000844u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CTRL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG;

/* UNUSED (latency calculation - width of data pulse from signal_gen) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG_ADDR (0x00000848u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE1_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG;

/* UNUSED (latency calculation - channel select specified by clocks after frame) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG_ADDR (0x0000084Cu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE1_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG;

/* check sum result LSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG_ADDR (0x00000850u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE1_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG;

/* check sum result MSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG_ADDR (0x00000854u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE1_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE2_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG;

/* 0 = return check sum, 1 = INVALID (latency calculation) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* UNUSED (latency calculation - clocks that data must remain stable after pulse) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_ADDR (0x00000884u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CTRL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG;

/* UNUSED (latency calculation - width of data pulse from signal_gen) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG_ADDR (0x00000888u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE2_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG;

/* UNUSED (latency calculation - channel select specified by clocks after frame) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG_ADDR (0x0000088Cu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE2_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG;

/* check sum result LSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG_ADDR (0x00000890u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE2_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG;

/* check sum result MSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG_ADDR (0x00000894u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE2_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE3_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG;

/* 0 = return check sum, 1 = INVALID (latency calculation) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* UNUSED (latency calculation - clocks that data must remain stable after pulse) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_ADDR (0x000008C4u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CTRL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG;

/* UNUSED (latency calculation - width of data pulse from signal_gen) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG_ADDR (0x000008C8u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE3_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG;

/* UNUSED (latency calculation - channel select specified by clocks after frame) */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG_ADDR (0x000008CCu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE3_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG;

/* check sum result LSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG_ADDR (0x000008D0u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDTX_CHECK_SUM_LANE3_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG;

/* check sum result MSBs */
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG_ADDR (0x000008D4u)
#define CSL_DFE_JESD_JESDTX_CHECK_SUM_LANE3_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG_ADDR (0x00000C04u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG_ADDR (0x00000C0Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_ADDR (0x00000C14u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_ADDR (0x00000C18u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_ADDR (0x00000C1Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_ADDR (0x00000C20u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_ADDR (0x00000C24u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_ADDR (0x00000C28u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_ADDR (0x00000C2Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_ADDR (0x00000C30u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_ADDR (0x00000C34u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_ADDR (0x00000C38u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG_ADDR (0x00000C44u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG_ADDR (0x00000C4Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_ADDR (0x00000C54u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_ADDR (0x00000C58u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_ADDR (0x00000C5Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_ADDR (0x00000C60u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_ADDR (0x00000C64u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_ADDR (0x00000C68u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_ADDR (0x00000C6Cu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_ADDR (0x00000C70u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_ADDR (0x00000C74u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_ADDR (0x00000C78u)
#define CSL_DFE_JESD_JESDTX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDTX_LANE0_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LANE0_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_ADDR (0x00001404u)
#define CSL_DFE_JESD_JESDTX_LANE0_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_LANE1_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LANE1_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_ADDR (0x00001408u)
#define CSL_DFE_JESD_JESDTX_LANE1_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_LANE2_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LANE2_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_ADDR (0x0000140Cu)
#define CSL_DFE_JESD_JESDTX_LANE2_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_LANE3_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LANE3_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_ADDR (0x00001410u)
#define CSL_DFE_JESD_JESDTX_LANE3_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 adjcnt : 4;
    Uint32 bid : 4;
    Uint32 did : 8;
#else 
    Uint32 did : 8;
    Uint32 bid : 4;
    Uint32 adjcnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG;

/* Device (link) ID */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_DID_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_DID_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_DID_RESETVAL (0x00000000u)

/* Bank ID – Extension to DID */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_BID_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_BID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_BID_RESETVAL (0x00000000u)

/* Number of adjustment resolution steps to adjust DAC LMFC. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_ADJCNT_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_ADJCNT_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_ADJCNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_ADDR (0x00001804u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG0_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 scr : 1;
    Uint32 rsvd2 : 2;
    Uint32 l_m1 : 5;
    Uint32 rsvd1 : 1;
    Uint32 adjdir : 1;
    Uint32 phadj : 1;
    Uint32 rsvd0 : 5;
#else 
    Uint32 rsvd0 : 5;
    Uint32 phadj : 1;
    Uint32 adjdir : 1;
    Uint32 rsvd1 : 1;
    Uint32 l_m1 : 5;
    Uint32 rsvd2 : 2;
    Uint32 scr : 1;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG;

/* Phase adjustment request to DAC. Subclass 2 only. */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_PHADJ_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_PHADJ_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_PHADJ_RESETVAL (0x00000000u)

/* Direction to adjust DAC LMFC. 0 – Advance, 1 – Delay. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_ADJDIR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_ADJDIR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_ADJDIR_RESETVAL (0x00000000u)

/* Number of lanes per converter device (link) minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_L_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_L_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_L_M1_RESETVAL (0x00000000u)

/* Scrambling enabled */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_SCR_MASK (0x00008000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_SCR_SHIFT (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_SCR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_ADDR (0x00001808u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG1_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 k_m1 : 5;
    Uint32 f_m1 : 8;
#else 
    Uint32 f_m1 : 8;
    Uint32 k_m1 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG;

/* Number of octets per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_F_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_F_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_F_M1_RESETVAL (0x00000000u)

/* Number of frames per multiframe minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_K_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_K_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_K_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_ADDR (0x0000180Cu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG2_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cs : 2;
    Uint32 rsvd0 : 1;
    Uint32 n_m1 : 5;
    Uint32 m_m1 : 8;
#else 
    Uint32 m_m1 : 8;
    Uint32 n_m1 : 5;
    Uint32 rsvd0 : 1;
    Uint32 cs : 2;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG;

/* Number of converters per device minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_M_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_M_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_M_M1_RESETVAL (0x00000000u)

/* Converter resolution minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_N_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_N_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_N_M1_RESETVAL (0x00000000u)

/* Number of control bits per sample */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_CS_MASK (0x0000C000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_CS_SHIFT (0x0000000Eu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_CS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_ADDR (0x00001810u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG3_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesdv : 3;
    Uint32 s_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 nprime_m1 : 5;
#else 
    Uint32 nprime_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 s_m1 : 5;
    Uint32 jesdv : 3;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG;

/* Total number of bits per sample minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_NPRIME_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_NPRIME_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_NPRIME_M1_RESETVAL (0x00000000u)

/* Device Subclass Version. 000 – Subclass 0, 001 – Subclass 1, 010 – Subclass 2 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_SUBCLASSV_MASK (0x000000E0u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_SUBCLASSV_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_SUBCLASSV_RESETVAL (0x00000000u)

/* Number of samples per converter per frame cycle minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_S_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_S_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_S_M1_RESETVAL (0x00000000u)

/* JESD204 version. 000 – JESD204A, 001 – JESD204B */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_JESDV_MASK (0x0000E000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_JESDV_SHIFT (0x0000000Du)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_JESDV_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_ADDR (0x00001814u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG4_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 res1 : 8;
    Uint32 hd : 1;
    Uint32 rsvd0 : 2;
    Uint32 cf : 5;
#else 
    Uint32 cf : 5;
    Uint32 rsvd0 : 2;
    Uint32 hd : 1;
    Uint32 res1 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG;

/* Number of control words per frame clock period per link */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_CF_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_CF_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_CF_RESETVAL (0x00000000u)

/* High Density format */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_HD_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_HD_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_HD_RESETVAL (0x00000000u)

/* Reserved field 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_RES1_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_RES1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_RES1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_ADDR (0x00001818u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG5_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 res2 : 8;
#else 
    Uint32 res2 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG;

/* Reserved field 2 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG_RES2_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG_RES2_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG_RES2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG_ADDR (0x0000181Cu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG6_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd0 : 3;
    Uint32 no_lane_sync : 1;
    Uint32 ila_mf_m1 : 8;
#else 
    Uint32 ila_mf_m1 : 8;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd0 : 3;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG;

/* Number of multiframes in the ILA sequence minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_ILA_MF_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_ILA_MF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_ILA_MF_M1_RESETVAL (0x00000000u)

/* 1 = receiver does not support lane synchronization (do not send ILA sequence or /A/ multiframe alignment characters) */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_NO_LANE_SYNC_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_NO_LANE_SYNC_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_NO_LANE_SYNC_RESETVAL (0x00000000u)

/* multipoint link enable */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_MP_LINK_ENA_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_MP_LINK_ENA_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_MP_LINK_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_ADDR (0x00001820u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG7_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 sysref_mode : 3;
#else 
    Uint32 sysref_mode : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG;

/* sysref sampling mode. 0 = ignore all sysrefs, 1 = use all sysrefs, 2 = use only next sysref, 3 = skip one sysref and then use one (use only next, next sysref), 4 = skip one sysref and then use all, 5 = skip two sysrefs and then use one, 6 = skip two sysrefs and then use all */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG_SYSREF_MODE_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG_SYSREF_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG_SYSREF_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG_ADDR (0x00001824u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG8_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK0_CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 err_cnt : 16;
#else 
    Uint32 err_cnt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG;

/* error count as reported over SYNC~ interface. write 1 to clear. */
#define CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG_ERR_CNT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG_ERR_CNT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG_ERR_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG_ADDR (0x00001828u)
#define CSL_DFE_JESD_JESDTX_LINK0_CFG9_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 adjcnt : 4;
    Uint32 bid : 4;
    Uint32 did : 8;
#else 
    Uint32 did : 8;
    Uint32 bid : 4;
    Uint32 adjcnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG;

/* Device (link) ID */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_DID_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_DID_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_DID_RESETVAL (0x00000000u)

/* Bank ID – Extension to DID */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_BID_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_BID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_BID_RESETVAL (0x00000000u)

/* Number of adjustment resolution steps to adjust DAC LMFC. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_ADJCNT_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_ADJCNT_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_ADJCNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_ADDR (0x00001844u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG0_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 scr : 1;
    Uint32 rsvd2 : 2;
    Uint32 l_m1 : 5;
    Uint32 rsvd1 : 1;
    Uint32 adjdir : 1;
    Uint32 phadj : 1;
    Uint32 rsvd0 : 5;
#else 
    Uint32 rsvd0 : 5;
    Uint32 phadj : 1;
    Uint32 adjdir : 1;
    Uint32 rsvd1 : 1;
    Uint32 l_m1 : 5;
    Uint32 rsvd2 : 2;
    Uint32 scr : 1;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG;

/* Phase adjustment request to DAC. Subclass 2 only. */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_PHADJ_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_PHADJ_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_PHADJ_RESETVAL (0x00000000u)

/* Direction to adjust DAC LMFC. 0 – Advance, 1 – Delay. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_ADJDIR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_ADJDIR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_ADJDIR_RESETVAL (0x00000000u)

/* Number of lanes per converter device (link) minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_L_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_L_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_L_M1_RESETVAL (0x00000000u)

/* Scrambling enabled */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_SCR_MASK (0x00008000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_SCR_SHIFT (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_SCR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_ADDR (0x00001848u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG1_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 k_m1 : 5;
    Uint32 f_m1 : 8;
#else 
    Uint32 f_m1 : 8;
    Uint32 k_m1 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG;

/* Number of octets per frame minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_F_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_F_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_F_M1_RESETVAL (0x00000000u)

/* Number of frames per multiframe minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_K_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_K_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_K_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_ADDR (0x0000184Cu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG2_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cs : 2;
    Uint32 rsvd0 : 1;
    Uint32 n_m1 : 5;
    Uint32 m_m1 : 8;
#else 
    Uint32 m_m1 : 8;
    Uint32 n_m1 : 5;
    Uint32 rsvd0 : 1;
    Uint32 cs : 2;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG;

/* Number of converters per device minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_M_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_M_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_M_M1_RESETVAL (0x00000000u)

/* Converter resolution minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_N_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_N_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_N_M1_RESETVAL (0x00000000u)

/* Number of control bits per sample */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_CS_MASK (0x0000C000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_CS_SHIFT (0x0000000Eu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_CS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_ADDR (0x00001850u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG3_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesdv : 3;
    Uint32 s_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 nprime_m1 : 5;
#else 
    Uint32 nprime_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 s_m1 : 5;
    Uint32 jesdv : 3;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG;

/* Total number of bits per sample minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_NPRIME_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_NPRIME_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_NPRIME_M1_RESETVAL (0x00000000u)

/* Device Subclass Version. 000 – Subclass 0, 001 – Subclass 1, 010 – Subclass 2 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_SUBCLASSV_MASK (0x000000E0u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_SUBCLASSV_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_SUBCLASSV_RESETVAL (0x00000000u)

/* Number of samples per converter per frame cycle minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_S_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_S_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_S_M1_RESETVAL (0x00000000u)

/* JESD204 version. 000 – JESD204A, 001 – JESD204B */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_JESDV_MASK (0x0000E000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_JESDV_SHIFT (0x0000000Du)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_JESDV_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_ADDR (0x00001854u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG4_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 res1 : 8;
    Uint32 hd : 1;
    Uint32 rsvd0 : 2;
    Uint32 cf : 5;
#else 
    Uint32 cf : 5;
    Uint32 rsvd0 : 2;
    Uint32 hd : 1;
    Uint32 res1 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG;

/* Number of control words per frame clock period per link */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_CF_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_CF_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_CF_RESETVAL (0x00000000u)

/* High Density format */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_HD_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_HD_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_HD_RESETVAL (0x00000000u)

/* Reserved field 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_RES1_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_RES1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_RES1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_ADDR (0x00001858u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG5_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 res2 : 8;
#else 
    Uint32 res2 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG;

/* Reserved field 2 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG_RES2_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG_RES2_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG_RES2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG_ADDR (0x0000185Cu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG6_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd0 : 3;
    Uint32 no_lane_sync : 1;
    Uint32 ila_mf_m1 : 8;
#else 
    Uint32 ila_mf_m1 : 8;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd0 : 3;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG;

/* Number of multiframes in the ILA sequence minus 1 */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_ILA_MF_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_ILA_MF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_ILA_MF_M1_RESETVAL (0x00000000u)

/* 1 = receiver does not support lane synchronization (do not send ILA sequence or /A/ multiframe alignment characters) */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_NO_LANE_SYNC_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_NO_LANE_SYNC_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_NO_LANE_SYNC_RESETVAL (0x00000000u)

/* multipoint link enable */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_MP_LINK_ENA_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_MP_LINK_ENA_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_MP_LINK_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_ADDR (0x00001860u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG7_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 sysref_mode : 3;
#else 
    Uint32 sysref_mode : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG;

/* sysref sampling mode. 0 = ignore all sysrefs, 1 = use all sysrefs, 2 = use only next sysref, 3 = skip one sysref and then use one (use only next, next sysref), 4 = skip one sysref and then use all, 5 = skip two sysrefs and then use one, 6 = skip two sysrefs and then use all */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG_SYSREF_MODE_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG_SYSREF_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG_SYSREF_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG_ADDR (0x00001864u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG8_REG_RESETVAL (0x00000000u)

/* JESDTX_LINK1_CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 err_cnt : 16;
#else 
    Uint32 err_cnt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG;

/* error count as reported over SYNC~ interface. write 1 to clear. */
#define CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG_ERR_CNT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG_ERR_CNT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG_ERR_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG_ADDR (0x00001868u)
#define CSL_DFE_JESD_JESDTX_LINK1_CFG9_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE0_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG;

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_ADDR (0x00001C04u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_MASK_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE0_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG;

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_ADDR (0x00001C08u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_INTR_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE0_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG;

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_ADDR (0x00001C0Cu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE0_FORCE_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE1_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG;

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_ADDR (0x00001C44u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_MASK_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE1_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG;

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_ADDR (0x00001C48u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_INTR_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE1_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG;

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_ADDR (0x00001C4Cu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE1_FORCE_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE2_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG;

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_ADDR (0x00001C84u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_MASK_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE2_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG;

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_ADDR (0x00001C88u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_INTR_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE2_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG;

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_ADDR (0x00001C8Cu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE2_FORCE_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE3_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG;

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_ADDR (0x00001CC4u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_MASK_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE3_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG;

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_ADDR (0x00001CC8u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_INTR_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_LANE3_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG;

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_ADDR (0x00001CCCu)
#define CSL_DFE_JESD_JESDTX_INTR_LANE3_FORCE_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_SYSREF_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG;

/* interrupt bit mask for sysref_request_assert */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_request_deassert */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_err on link 0 */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_err on link 1 */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_ADDR (0x00002004u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_MASK_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_SYSREF_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG;

/* captured interrupt bit for sysref_request_assert (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_request_deassert (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_err on link 0 (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_err on link 1 (write 0 to clear) */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_ADDR (0x00002008u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_INTR_REG_RESETVAL (0x00000000u)

/* JESDTX_INTR_SYSREF_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG;

/* force interrupt bit for sysref_request_assert */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_request_deassert */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_err on link 0 */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_err on link 1 */
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_ADDR (0x0000200Cu)
#define CSL_DFE_JESD_JESDTX_INTR_SYSREF_FORCE_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE0_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_ADDR (0x00002404u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE0_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_ADDR (0x00002408u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE0_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_ADDR (0x0000240Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE0_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_ADDR (0x00002410u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE0_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE1_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_ADDR (0x00002414u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE1_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_ADDR (0x00002418u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE1_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_ADDR (0x0000241Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE1_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_ADDR (0x00002420u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE1_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE2_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_ADDR (0x00002424u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE2_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_ADDR (0x00002428u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE2_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_ADDR (0x0000242Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE2_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_ADDR (0x00002430u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE2_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE3_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_ADDR (0x00002434u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE3_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_ADDR (0x00002438u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE3_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_ADDR (0x0000243Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE0_NIBBLE3_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG;

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 0 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_ADDR (0x00002440u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE0_NIBBLE3_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE0_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_ADDR (0x00002444u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE0_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_ADDR (0x00002448u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE0_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_ADDR (0x0000244Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE0_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_ADDR (0x00002450u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE0_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE1_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_ADDR (0x00002454u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE1_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_ADDR (0x00002458u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE1_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_ADDR (0x0000245Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE1_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_ADDR (0x00002460u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE1_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE2_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_ADDR (0x00002464u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE2_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_ADDR (0x00002468u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE2_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_ADDR (0x0000246Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE2_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_ADDR (0x00002470u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE2_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE3_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_ADDR (0x00002474u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE3_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_ADDR (0x00002478u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE3_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_ADDR (0x0000247Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE1_NIBBLE3_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG;

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 1 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_ADDR (0x00002480u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE1_NIBBLE3_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE0_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_ADDR (0x00002484u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE0_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_ADDR (0x00002488u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE0_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_ADDR (0x0000248Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE0_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_ADDR (0x00002490u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE0_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE1_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_ADDR (0x00002494u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE1_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_ADDR (0x00002498u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE1_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_ADDR (0x0000249Cu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE1_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_ADDR (0x000024A0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE1_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE2_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_ADDR (0x000024A4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE2_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_ADDR (0x000024A8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE2_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_ADDR (0x000024ACu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE2_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_ADDR (0x000024B0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE2_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE3_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_ADDR (0x000024B4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE3_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_ADDR (0x000024B8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE3_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_ADDR (0x000024BCu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE2_NIBBLE3_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG;

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 2 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_ADDR (0x000024C0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE2_NIBBLE3_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE0_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_ADDR (0x000024C4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE0_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_ADDR (0x000024C8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE0_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_ADDR (0x000024CCu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE0_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_ADDR (0x000024D0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE0_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE1_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_ADDR (0x000024D4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE1_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_ADDR (0x000024D8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE1_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_ADDR (0x000024DCu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE1_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_ADDR (0x000024E0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE1_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE2_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_ADDR (0x000024E4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE2_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_ADDR (0x000024E8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE2_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_ADDR (0x000024ECu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE2_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_ADDR (0x000024F0u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE2_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE3_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_ADDR (0x000024F4u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE3_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_ADDR (0x000024F8u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE3_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_ADDR (0x000024FCu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_LANE3_NIBBLE3_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 frame_pos : 2;
    Uint32 rsvd0 : 4;
    Uint32 nibble_sel : 4;
#else 
    Uint32 nibble_sel : 4;
    Uint32 rsvd0 : 4;
    Uint32 frame_pos : 2;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG;

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_NIBBLE_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_NIBBLE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_NIBBLE_SEL_RESETVAL (0x00000000u)

/* mapping configuration for lane 3 */
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_FRAME_POS_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_FRAME_POS_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_FRAME_POS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_ADDR (0x00002500u)
#define CSL_DFE_JESD_JESDTX_MAP_LANE3_NIBBLE3_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE00_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_ADDR (0x00002804u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE00_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE01_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_ADDR (0x00002808u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE01_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE02_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_ADDR (0x0000280Cu)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE02_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE03_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_ADDR (0x00002810u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE03_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE04_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_ADDR (0x00002814u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE04_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE05_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_ADDR (0x00002818u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE05_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE06_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_ADDR (0x0000281Cu)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE06_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE07_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_ADDR (0x00002820u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE07_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE08_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_ADDR (0x00002824u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE08_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE09_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_ADDR (0x00002828u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE09_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE10_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_ADDR (0x0000282Cu)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE10_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE11_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_ADDR (0x00002830u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE11_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE12_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_ADDR (0x00002834u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE12_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE13_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_ADDR (0x00002838u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE13_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE14_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_ADDR (0x0000283Cu)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE14_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_NIBBLE15_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 23;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 link_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 link_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 test_pat_ena : 1;
    Uint32 rsvd2 : 23;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

/* link select */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_LINK_SEL_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_LINK_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_LINK_SEL_RESETVAL (0x00000000u)

/* enable test pattern mpu interface */
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_TEST_PAT_ENA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_TEST_PAT_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_TEST_PAT_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_ADDR (0x00002840u)
#define CSL_DFE_JESD_JESDTX_MAP_NIBBLE15_CFG_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE00_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG_ADDR (0x00004004u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE00_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG_ADDR (0x00004008u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE00_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG_ADDR (0x0000400Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE00_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG_ADDR (0x00004010u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE00_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE01_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG_ADDR (0x00004014u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE01_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG_ADDR (0x00004018u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE01_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG_ADDR (0x0000401Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE01_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG_ADDR (0x00004020u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE01_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE02_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG_ADDR (0x00004024u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE02_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG_ADDR (0x00004028u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE02_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG_ADDR (0x0000402Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE02_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG_ADDR (0x00004030u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE02_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE03_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG_ADDR (0x00004034u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE03_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG_ADDR (0x00004038u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE03_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG_ADDR (0x0000403Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE03_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG_ADDR (0x00004040u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE03_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE04_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG_ADDR (0x00004044u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE04_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG_ADDR (0x00004048u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE04_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG_ADDR (0x0000404Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE04_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG_ADDR (0x00004050u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE04_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE05_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG_ADDR (0x00004054u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE05_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG_ADDR (0x00004058u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE05_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG_ADDR (0x0000405Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE05_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG_ADDR (0x00004060u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE05_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE06_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG_ADDR (0x00004064u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE06_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG_ADDR (0x00004068u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE06_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG_ADDR (0x0000406Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE06_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG_ADDR (0x00004070u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE06_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE07_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG_ADDR (0x00004074u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE07_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG_ADDR (0x00004078u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE07_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG_ADDR (0x0000407Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE07_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG_ADDR (0x00004080u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE07_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE08_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG_ADDR (0x00004084u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE08_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG_ADDR (0x00004088u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE08_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG_ADDR (0x0000408Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE08_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG_ADDR (0x00004090u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE08_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE09_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG_ADDR (0x00004094u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE09_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG_ADDR (0x00004098u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE09_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG_ADDR (0x0000409Cu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE09_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG_ADDR (0x000040A0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE09_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE10_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG_ADDR (0x000040A4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE10_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG_ADDR (0x000040A8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE10_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG_ADDR (0x000040ACu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE10_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG_ADDR (0x000040B0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE10_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE11_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG_ADDR (0x000040B4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE11_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG_ADDR (0x000040B8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE11_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG_ADDR (0x000040BCu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE11_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG_ADDR (0x000040C0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE11_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE12_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG_ADDR (0x000040C4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE12_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG_ADDR (0x000040C8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE12_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG_ADDR (0x000040CCu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE12_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG_ADDR (0x000040D0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE12_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE13_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG_ADDR (0x000040D4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE13_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG_ADDR (0x000040D8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE13_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG_ADDR (0x000040DCu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE13_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG_ADDR (0x000040E0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE13_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE14_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG_ADDR (0x000040E4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE14_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG_ADDR (0x000040E8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE14_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG_ADDR (0x000040ECu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE14_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG_ADDR (0x000040F0u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE14_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE15_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG_ADDR (0x000040F4u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE15_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG_ADDR (0x000040F8u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE15_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG_ADDR (0x000040FCu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDTX_MAP_TEST_NIBBLE15_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 test_data : 4;
#else 
    Uint32 test_data : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG;

/* test data */
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG_TEST_DATA_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG_ADDR (0x00004100u)
#define CSL_DFE_JESD_JESDTX_MAP_TEST_NIBBLE15_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_INITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 clear_data_lane3 : 1;
    Uint32 clear_data_lane2 : 1;
    Uint32 clear_data_lane1 : 1;
    Uint32 clear_data_lane0 : 1;
    Uint32 rsvd0 : 1;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 rsvd0 : 1;
    Uint32 clear_data_lane0 : 1;
    Uint32 clear_data_lane1 : 1;
    Uint32 clear_data_lane2 : 1;
    Uint32 clear_data_lane3 : 1;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_INITS_REG;

/* sync select for initialization signals */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INITS_SSEL_RESETVAL (0x0000000Fu)

/* initialize all clock gating */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* initialize all state machines */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* clear output data from all lanes and mapper outputs */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* clear output data from lane 0 before mapper */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE0_RESETVAL (0x00000001u)

/* clear output data from lane 1 before mapper */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE1_RESETVAL (0x00000001u)

/* clear output data from lane 2 before mapper */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE2_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE2_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE2_RESETVAL (0x00000001u)

/* clear output data from lane 3 before mapper */
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE3_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE3_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_CLEAR_DATA_LANE3_RESETVAL (0x00000001u)

#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_ADDR (0x00040004u)
#define CSL_DFE_JESD_JESDRX_BASE_INITS_REG_RESETVAL (0x00000F7Fu)

/* JESDRX_BASE_TEST_BUS_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 test_bus_sel : 8;
#else 
    Uint32 test_bus_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG;

/* test bus select */
#define CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG_TEST_BUS_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG_ADDR (0x00040008u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_BUS_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_TEST_SEQ_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 lane3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane0 : 2;
#else 
    Uint32 lane0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG;

/* link layer test sequence select for lane 0 */
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE0_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE0_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 1 */
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE1_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE1_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 2 */
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE2_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE2_RESETVAL (0x00000000u)

/* link layer test sequence select for lane 3 */
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE3_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_ADDR (0x0004000Cu)
#define CSL_DFE_JESD_JESDRX_BASE_TEST_SEQ_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_LPBK_ENA */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 21;
    Uint32 rx2 : 1;
    Uint32 rx1 : 1;
    Uint32 rx0 : 1;
    Uint32 rsvd0 : 4;
    Uint32 lane3 : 1;
    Uint32 lane2 : 1;
    Uint32 lane1 : 1;
    Uint32 lane0 : 1;
#else 
    Uint32 lane0 : 1;
    Uint32 lane1 : 1;
    Uint32 lane2 : 1;
    Uint32 lane3 : 1;
    Uint32 rsvd0 : 4;
    Uint32 rx0 : 1;
    Uint32 rx1 : 1;
    Uint32 rx2 : 1;
    Uint32 rsvd1 : 21;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG;

/* loopback enable for lane 0 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE0_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE0_RESETVAL (0x00000000u)

/* loopback enable for lane 1 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE1_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE1_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE1_RESETVAL (0x00000000u)

/* loopback enable for lane 2 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE2_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE2_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE2_RESETVAL (0x00000000u)

/* loopback enable for lane 3 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE3_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE3_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_LANE3_RESETVAL (0x00000000u)

/* loopback enable from TX to RX 0 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX0_RESETVAL (0x00000000u)

/* loopback enable from TX to RX 1 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX1_RESETVAL (0x00000000u)

/* loopback enable from TX to RX 2 */
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX2_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX2_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RX2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_ADDR (0x00040010u)
#define CSL_DFE_JESD_JESDRX_BASE_LPBK_ENA_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_BB_RX_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 21;
    Uint32 rx_force_frame_rx2 : 1;
    Uint32 rx_force_frame_rx1 : 1;
    Uint32 rx_force_frame_rx0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 bb_out_ena : 1;
    Uint32 rsvd0 : 2;
    Uint32 bb_out_lane_sel : 2;
#else 
    Uint32 bb_out_lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 bb_out_ena : 1;
    Uint32 rsvd1 : 3;
    Uint32 rx_force_frame_rx0 : 1;
    Uint32 rx_force_frame_rx1 : 1;
    Uint32 rx_force_frame_rx2 : 1;
    Uint32 rsvd2 : 21;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG;

/* BB output lane select */
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_LANE_SEL_RESETVAL (0x00000000u)

/* BB output enable */
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_ENA_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_ENA_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_BB_OUT_ENA_RESETVAL (0x00000000u)

/* force frame signal high to RX 0 */
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX0_RESETVAL (0x00000000u)

/* force frame signal high to RX 1 */
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX1_RESETVAL (0x00000000u)

/* force frame signal high to RX 2 */
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX2_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX2_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RX_FORCE_FRAME_RX2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_ADDR (0x00040014u)
#define CSL_DFE_JESD_JESDRX_BASE_BB_RX_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_FIFO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 23;
    Uint32 disable_fifo_errors_zero_data : 1;
    Uint32 rsvd0 : 4;
    Uint32 fifo_read_delay : 4;
#else 
    Uint32 fifo_read_delay : 4;
    Uint32 rsvd0 : 4;
    Uint32 disable_fifo_errors_zero_data : 1;
    Uint32 rsvd1 : 23;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_FIFO_REG;

/* FIFO read delay applied to all SERDES RX FIFOs */
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_FIFO_READ_DELAY_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_FIFO_READ_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_FIFO_READ_DELAY_RESETVAL (0x00000003u)

/* 0 = allow FIFO errors to zero data */
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_DISABLE_FIFO_ERRORS_ZERO_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_ADDR (0x00040018u)
#define CSL_DFE_JESD_JESDRX_BASE_FIFO_REG_RESETVAL (0x00000003u)

/* JESDRX_BASE_SYNC_N_OUT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 19;
    Uint32 sync_bus_ena_1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 sync_bus_ena_0 : 1;
    Uint32 rsvd1 : 1;
    Uint32 sel_link1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 sel_link0 : 3;
#else 
    Uint32 sel_link0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 sel_link1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 sync_bus_ena_0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 sync_bus_ena_1 : 1;
    Uint32 rsvd3 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG;

/* SYNC~ output mux select for link 0 */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK0_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK0_RESETVAL (0x00000000u)

/* SYNC~ output mux select for link 1 */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK1_MASK (0x00000070u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SEL_LINK1_RESETVAL (0x00000000u)

/* enable sync selected by sync_n_out_sync_bus_ssel_0 to be output on SYNC~ 0 */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_0_RESETVAL (0x00000000u)

/* enable sync selected by sync_n_out_sync_bus_ssel_1 to be output on SYNC~ 1 */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_1_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_1_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_SYNC_BUS_ENA_1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_ADDR (0x0004001Cu)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_SYNC_N_OUT_INV */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 link1 : 1;
    Uint32 link0 : 1;
#else 
    Uint32 link0 : 1;
    Uint32 link1 : 1;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG;

/* SYNC~ output polarity invert for link 0, does not apply if sync_bus_ena0 set */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK0_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK0_RESETVAL (0x00000000u)

/* SYNC~ output polarity invert for link 1, does not apply if sync_bus_ena1 set */
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK1_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK1_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_ADDR (0x00040020u)
#define CSL_DFE_JESD_JESDRX_BASE_SYNC_N_OUT_INV_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_SYSREF */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 force_sysref_request_auto_off : 8;
    Uint32 rsvd0 : 3;
    Uint32 force_sysref_request : 1;
    Uint32 sysref_dly_sel : 4;
#else 
    Uint32 sysref_dly_sel : 4;
    Uint32 force_sysref_request : 1;
    Uint32 rsvd0 : 3;
    Uint32 force_sysref_request_auto_off : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG;

/* SYSREF delay line select */
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_SYSREF_DLY_SEL_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_SYSREF_DLY_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_SYSREF_DLY_SEL_RESETVAL (0x00000000u)

/* force SYSREF request */
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_RESETVAL (0x00000000u)

/* auto off timer for forced SYSREF request, 0 = disable auto off */
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_FORCE_SYSREF_REQUEST_AUTO_OFF_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_ADDR (0x00040024u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_SYSREF_CNTR_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sysref_cntr_15_0 : 16;
#else 
    Uint32 sysref_cntr_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG;

/* SYSREF alignment counter bits [15:0] */
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG_SYSREF_CNTR_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG_ADDR (0x00040028u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_SYSREF_CNTR_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sysref_cntr_31_16 : 16;
#else 
    Uint32 sysref_cntr_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG;

/* SYSREF alignment counter bits [31:16] */
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG_SYSREF_CNTR_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG_ADDR (0x0004002Cu)
#define CSL_DFE_JESD_JESDRX_BASE_SYSREF_CNTR_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_CS_STATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 lane3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane0 : 2;
#else 
    Uint32 lane0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG;

/* code group synchronization state machine status for lane 0 */
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE0_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE0_RESETVAL (0x00000000u)

/* code group synchronization state machine status for lane 1 */
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE1_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE1_RESETVAL (0x00000000u)

/* code group synchronization state machine status for lane 2 */
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE2_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE2_RESETVAL (0x00000000u)

/* code group synchronization state machine status for lane 3 */
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE3_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_ADDR (0x00040030u)
#define CSL_DFE_JESD_JESDRX_BASE_CS_STATE_REG_RESETVAL (0x00000000u)

/* JESDRX_BASE_FS_STATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 lane3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane0 : 2;
#else 
    Uint32 lane0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 lane3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG;

/* frame synchronization state machine status for lane 0 */
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE0_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE0_RESETVAL (0x00000000u)

/* frame synchronization state machine status for lane 1 */
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE1_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE1_RESETVAL (0x00000000u)

/* frame synchronization state machine status for lane 2 */
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE2_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE2_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE2_RESETVAL (0x00000000u)

/* frame synchronization state machine status for lane 3 */
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE3_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE3_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_LANE3_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_ADDR (0x00040034u)
#define CSL_DFE_JESD_JESDRX_BASE_FS_STATE_REG_RESETVAL (0x00000000u)

/* JESDRX_SSEL_SSEL_ADDR_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_ssel_rx0q : 4;
    Uint32 check_sum_ssel_rx0i : 4;
    Uint32 init_state_ssel_link1 : 4;
    Uint32 init_state_ssel_link0 : 4;
#else 
    Uint32 init_state_ssel_link0 : 4;
    Uint32 init_state_ssel_link1 : 4;
    Uint32 check_sum_ssel_rx0i : 4;
    Uint32 check_sum_ssel_rx0q : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG;

/* sync select for init_state for link 0 */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK0_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK0_RESETVAL (0x00000000u)

/* sync select for init_state for link 1 */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK1_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_INIT_STATE_SSEL_LINK1_RESETVAL (0x00000000u)

/* sync select for check sum for rx0i */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0I_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0I_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0I_RESETVAL (0x00000000u)

/* sync select for check sum for rx0q */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0Q_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0Q_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_CHECK_SUM_SSEL_RX0Q_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_ADDR (0x00040044u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_0_REG_RESETVAL (0x00000000u)

/* JESDRX_SSEL_SSEL_ADDR_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_ssel_rx2q : 4;
    Uint32 check_sum_ssel_rx2i : 4;
    Uint32 check_sum_ssel_rx1q : 4;
    Uint32 check_sum_ssel_rx1i : 4;
#else 
    Uint32 check_sum_ssel_rx1i : 4;
    Uint32 check_sum_ssel_rx1q : 4;
    Uint32 check_sum_ssel_rx2i : 4;
    Uint32 check_sum_ssel_rx2q : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG;

/* sync select for check sum for rx1i */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1I_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1I_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1I_RESETVAL (0x00000000u)

/* sync select for check sum for rx1q */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1Q_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1Q_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX1Q_RESETVAL (0x00000000u)

/* sync select for check sum for rx2i */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2I_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2I_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2I_RESETVAL (0x00000000u)

/* sync select for check sum for rx2q */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2Q_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2Q_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_CHECK_SUM_SSEL_RX2Q_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_ADDR (0x00040048u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_1_REG_RESETVAL (0x00000000u)

/* JESDRX_SSEL_SSEL_ADDR_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rx_sysref_mode_ssel : 4;
    Uint32 sysref_cntr_ssel : 4;
    Uint32 sync_n_out_sync_bus_ssel_1 : 4;
    Uint32 sync_n_out_sync_bus_ssel_0 : 4;
#else 
    Uint32 sync_n_out_sync_bus_ssel_0 : 4;
    Uint32 sync_n_out_sync_bus_ssel_1 : 4;
    Uint32 sysref_cntr_ssel : 4;
    Uint32 rx_sysref_mode_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG;

/* sync select for SYNC~ output 0, must also set sync_n_out_sync_bus_ena_0 */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_0_MASK (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_0_RESETVAL (0x00000000u)

/* sync select for SYNC~ output 1, must also set sync_n_out_sync_bus_ena_1 */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_1_MASK (0x000000F0u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_1_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYNC_N_OUT_SYNC_BUS_SSEL_1_RESETVAL (0x00000000u)

/* sync select for SYSREF alignment counter */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_SYSREF_CNTR_SSEL_RESETVAL (0x00000000u)

/* sync select for SYSREF mode */
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_RX_SYSREF_MODE_SSEL_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_RX_SYSREF_MODE_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_RX_SYSREF_MODE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_ADDR (0x0004004Cu)
#define CSL_DFE_JESD_JESDRX_SSEL_SSEL_ADDR_2_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0I_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_ADDR (0x00040804u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG_ADDR (0x00040808u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0I_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG_ADDR (0x0004080Cu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0I_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG_ADDR (0x00040810u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0I_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG_ADDR (0x00040814u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0I_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0Q_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_ADDR (0x00040844u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG_ADDR (0x00040848u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0Q_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG_ADDR (0x0004084Cu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0Q_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG_ADDR (0x00040850u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX0Q_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG_ADDR (0x00040854u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX0Q_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1I_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_ADDR (0x00040884u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG_ADDR (0x00040888u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1I_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG_ADDR (0x0004088Cu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1I_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG_ADDR (0x00040890u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1I_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG_ADDR (0x00040894u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1I_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1Q_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_ADDR (0x000408C4u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG_ADDR (0x000408C8u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1Q_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG_ADDR (0x000408CCu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1Q_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG_ADDR (0x000408D0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX1Q_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG_ADDR (0x000408D4u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX1Q_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2I_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_ADDR (0x00040904u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG_ADDR (0x00040908u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2I_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG_ADDR (0x0004090Cu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2I_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG_ADDR (0x00040910u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2I_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG_ADDR (0x00040914u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2I_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2Q_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_ADDR (0x00040944u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CTRL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG_ADDR (0x00040948u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2Q_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG_ADDR (0x0004094Cu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2Q_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG_ADDR (0x00040950u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_LO_REG_RESETVAL (0x00000000u)

/* JESDRX_CHECK_SUM_RX2Q_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG_ADDR (0x00040954u)
#define CSL_DFE_JESD_JESDRX_CHECK_SUM_RX2Q_RESULT_HI_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG_ADDR (0x00040C04u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG_ADDR (0x00040C0Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_ADDR (0x00040C14u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_ADDR (0x00040C18u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_ADDR (0x00040C1Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_ADDR (0x00040C20u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_ADDR (0x00040C24u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_ADDR (0x00040C28u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_ADDR (0x00040C2Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_ADDR (0x00040C30u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_ADDR (0x00040C34u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_ADDR (0x00040C38u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK0_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG_ADDR (0x00040C44u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG_ADDR (0x00040C4Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_ADDR (0x00040C54u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_ADDR (0x00040C58u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_ADDR (0x00040C5Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_ADDR (0x00040C60u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_ADDR (0x00040C64u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_ADDR (0x00040C68u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_ADDR (0x00040C6Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_ADDR (0x00040C70u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_ADDR (0x00040C74u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_ADDR (0x00040C78u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_LINK1_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG_ADDR (0x00041004u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG_ADDR (0x0004100Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG_ADDR (0x00041014u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG_ADDR (0x00041018u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG_ADDR (0x0004101Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG_ADDR (0x00041020u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG_ADDR (0x00041024u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG_ADDR (0x00041028u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG_ADDR (0x0004102Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG_ADDR (0x00041030u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG_ADDR (0x00041034u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG_ADDR (0x00041038u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX0_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG_ADDR (0x00041044u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG_ADDR (0x0004104Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG_ADDR (0x00041054u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG_ADDR (0x00041058u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG_ADDR (0x0004105Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG_ADDR (0x00041060u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG_ADDR (0x00041064u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG_ADDR (0x00041068u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG_ADDR (0x0004106Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG_ADDR (0x00041070u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG_ADDR (0x00041074u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG_ADDR (0x00041078u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX1_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG_ADDR (0x00041084u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TIME_STEP_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG_ADDR (0x0004108Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_RESET_INT_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_lsb : 16;
#else 
    Uint32 tdd_period_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG_TDD_PERIOD_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG_ADDR (0x00041094u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_msb : 8;
#else 
    Uint32 tdd_period_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG_TDD_PERIOD_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG_ADDR (0x00041098u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_lsb : 16;
#else 
    Uint32 tdd_on_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG_TDD_ON_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG_ADDR (0x0004109Cu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_msb : 8;
#else 
    Uint32 tdd_on_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG_TDD_ON_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG_ADDR (0x000410A0u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_lsb : 16;
#else 
    Uint32 tdd_off_0_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG_TDD_OFF_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG_ADDR (0x000410A4u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_msb : 8;
#else 
    Uint32 tdd_off_0_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG_TDD_OFF_0_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG_ADDR (0x000410A8u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_lsb : 16;
#else 
    Uint32 tdd_on_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG_TDD_ON_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG_ADDR (0x000410ACu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_msb : 8;
#else 
    Uint32 tdd_on_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG_TDD_ON_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG_ADDR (0x000410B0u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_lsb : 16;
#else 
    Uint32 tdd_off_1_lsb : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG_TDD_OFF_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG_ADDR (0x000410B4u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_msb : 8;
#else 
    Uint32 tdd_off_1_msb : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG_TDD_OFF_1_MSB_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG_ADDR (0x000410B8u)
#define CSL_DFE_JESD_JESDRX_CLK_GATER_RX2_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* JESDRX_LANE0_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LANE0_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_ADDR (0x00041404u)
#define CSL_DFE_JESD_JESDRX_LANE0_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_LANE1_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LANE1_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_ADDR (0x00041408u)
#define CSL_DFE_JESD_JESDRX_LANE1_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_LANE2_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LANE2_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_ADDR (0x0004140Cu)
#define CSL_DFE_JESD_JESDRX_LANE2_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_LANE3_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 lid : 5;
    Uint32 rsvd1 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd0 : 3;
    Uint32 lane_ena : 1;
#else 
    Uint32 lane_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 link_assign : 1;
    Uint32 rsvd1 : 3;
    Uint32 lid : 5;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LANE3_CFG_REG;

/* lane enable */
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LANE_ENA_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LANE_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LANE_ENA_RESETVAL (0x00000000u)

/* link assignment */
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LINK_ASSIGN_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LINK_ASSIGN_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LINK_ASSIGN_RESETVAL (0x00000000u)

/* lane ID */
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LID_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_LID_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_ADDR (0x00041410u)
#define CSL_DFE_JESD_JESDRX_LANE3_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 adjcnt : 4;
    Uint32 bid : 4;
    Uint32 did : 8;
#else 
    Uint32 did : 8;
    Uint32 bid : 4;
    Uint32 adjcnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG;

/* Device (link) ID */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_DID_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_DID_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_DID_RESETVAL (0x00000000u)

/* Bank ID – Extension to DID */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_BID_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_BID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_BID_RESETVAL (0x00000000u)

/* Number of adjustment resolution steps to adjust DAC LMFC. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_ADJCNT_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_ADJCNT_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_ADJCNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_ADDR (0x00041804u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG0_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 scr : 1;
    Uint32 rsvd2 : 2;
    Uint32 l_m1 : 5;
    Uint32 rsvd1 : 1;
    Uint32 adjdir : 1;
    Uint32 phadj : 1;
    Uint32 rsvd0 : 5;
#else 
    Uint32 rsvd0 : 5;
    Uint32 phadj : 1;
    Uint32 adjdir : 1;
    Uint32 rsvd1 : 1;
    Uint32 l_m1 : 5;
    Uint32 rsvd2 : 2;
    Uint32 scr : 1;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG;

/* Phase adjustment request to DAC. Subclass 2 only. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_PHADJ_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_PHADJ_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_PHADJ_RESETVAL (0x00000000u)

/* Direction to adjust DAC LMFC. 0 – Advance, 1 – Delay. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_ADJDIR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_ADJDIR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_ADJDIR_RESETVAL (0x00000000u)

/* Number of lanes per converter device (link) minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_L_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_L_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_L_M1_RESETVAL (0x00000000u)

/* Scrambling enabled */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_SCR_MASK (0x00008000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_SCR_SHIFT (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_SCR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_ADDR (0x00041808u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG1_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 k_m1 : 5;
    Uint32 f_m1 : 8;
#else 
    Uint32 f_m1 : 8;
    Uint32 k_m1 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG;

/* Number of octets per frame minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_F_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_F_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_F_M1_RESETVAL (0x00000000u)

/* Number of frames per multiframe minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_K_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_K_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_K_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_ADDR (0x0004180Cu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG2_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cs : 2;
    Uint32 rsvd0 : 1;
    Uint32 n_m1 : 5;
    Uint32 m_m1 : 8;
#else 
    Uint32 m_m1 : 8;
    Uint32 n_m1 : 5;
    Uint32 rsvd0 : 1;
    Uint32 cs : 2;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG;

/* Number of converters per device minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_M_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_M_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_M_M1_RESETVAL (0x00000000u)

/* Converter resolution minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_N_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_N_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_N_M1_RESETVAL (0x00000000u)

/* Number of control bits per sample */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_CS_MASK (0x0000C000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_CS_SHIFT (0x0000000Eu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_CS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_ADDR (0x00041810u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG3_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesdv : 3;
    Uint32 s_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 nprime_m1 : 5;
#else 
    Uint32 nprime_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 s_m1 : 5;
    Uint32 jesdv : 3;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG;

/* Total number of bits per sample minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_NPRIME_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_NPRIME_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_NPRIME_M1_RESETVAL (0x00000000u)

/* Device Subclass Version. 000 – Subclass 0, 001 – Subclass 1, 010 – Subclass 2 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_SUBCLASSV_MASK (0x000000E0u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_SUBCLASSV_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_SUBCLASSV_RESETVAL (0x00000000u)

/* Number of samples per converter per frame cycle minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_S_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_S_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_S_M1_RESETVAL (0x00000000u)

/* JESD204 version. 000 – JESD204A, 001 – JESD204B */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_JESDV_MASK (0x0000E000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_JESDV_SHIFT (0x0000000Du)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_JESDV_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_ADDR (0x00041814u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG4_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 res1 : 8;
    Uint32 hd : 1;
    Uint32 rsvd0 : 2;
    Uint32 cf : 5;
#else 
    Uint32 cf : 5;
    Uint32 rsvd0 : 2;
    Uint32 hd : 1;
    Uint32 res1 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG;

/* Number of control words per frame clock period per link */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_CF_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_CF_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_CF_RESETVAL (0x00000000u)

/* High Density format */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_HD_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_HD_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_HD_RESETVAL (0x00000000u)

/* Reserved field 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_RES1_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_RES1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_RES1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_ADDR (0x00041818u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG5_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 res2 : 8;
#else 
    Uint32 res2 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG;

/* Reserved field 2 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG_RES2_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG_RES2_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG_RES2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG_ADDR (0x0004181Cu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG6_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 match_data : 8;
    Uint32 match_ctrl : 1;
    Uint32 match_specific : 1;
    Uint32 min_latency_ena : 1;
    Uint32 rbd_m1 : 5;
#else 
    Uint32 rbd_m1 : 5;
    Uint32 min_latency_ena : 1;
    Uint32 match_specific : 1;
    Uint32 match_ctrl : 1;
    Uint32 match_data : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG;

/* number of frames for RX buffer delay minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_RBD_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_RBD_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_RBD_M1_RESETVAL (0x00000000u)

/* ignore RBD and release buffers as soon as possible (support for Subclass 0) */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MIN_LATENCY_ENA_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MIN_LATENCY_ENA_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MIN_LATENCY_ENA_RESETVAL (0x00000000u)

/* 1 = match with specified character to start buffering, 0 = start buffering with first non-/K/ */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_SPECIFIC_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_SPECIFIC_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_SPECIFIC_RESETVAL (0x00000000u)

/* 1 = match character is control character (typically 1) */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_CTRL_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_CTRL_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_CTRL_RESETVAL (0x00000000u)

/* specific control character to start buffering (typically /R/ = /K.28.0/ = 0x1C) */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_DATA_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_DATA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_MATCH_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_ADDR (0x00041820u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG7_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 error_ena : 8;
    Uint32 sync_request_ena : 8;
#else 
    Uint32 sync_request_ena : 8;
    Uint32 error_ena : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG;

/* choose which errors trigger sync request */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_SYNC_REQUEST_ENA_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_SYNC_REQUEST_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_SYNC_REQUEST_ENA_RESETVAL (0x00000000u)

/* choose which errors contribute towards error count and error reporting */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_ERROR_ENA_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_ERROR_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_ERROR_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_ADDR (0x00041824u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG8_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd2 : 3;
    Uint32 disable_err_report : 1;
    Uint32 rsvd1 : 3;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd0 : 1;
    Uint32 sysref_mode : 3;
#else 
    Uint32 sysref_mode : 3;
    Uint32 rsvd0 : 1;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd1 : 3;
    Uint32 disable_err_report : 1;
    Uint32 rsvd2 : 3;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG;

/* sysref sampling mode. 0 = ignore all sysrefs, 1 = use all sysrefs, 2 = use only next sysref, 3 = skip one sysref and then use one (use only next, next sysref), 4 = skip one sysref and then use all, 5 = skip two sysrefs and then use one, 6 = skip two sysrefs and then use all */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_SYSREF_MODE_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_SYSREF_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_SYSREF_MODE_RESETVAL (0x00000000u)

/* 1 = transmitter does not support lane synchronization. do not check link configuration data. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_NO_LANE_SYNC_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_NO_LANE_SYNC_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_NO_LANE_SYNC_RESETVAL (0x00000000u)

/* suppress error reporting for subclass 0 operation. errors won't trigger sync_n but will be counted. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_DISABLE_ERR_REPORT_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_DISABLE_ERR_REPORT_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_DISABLE_ERR_REPORT_RESETVAL (0x00000000u)

/* multipoint link enable */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_MP_LINK_ENA_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_MP_LINK_ENA_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_MP_LINK_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_ADDR (0x00041828u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG9_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 lane_skew : 5;
#else 
    Uint32 lane_skew : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG;

/* measured lane skew (on gated clock) */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG_LANE_SKEW_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG_LANE_SKEW_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG_LANE_SKEW_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG_ADDR (0x0004182Cu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG10_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK0_CFG11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 err_cnt : 16;
#else 
    Uint32 err_cnt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG;

/* error count as reported over SYNC~ interface. write 1 to clear. */
#define CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG_ERR_CNT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG_ERR_CNT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG_ERR_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG_ADDR (0x00041830u)
#define CSL_DFE_JESD_JESDRX_LINK0_CFG11_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 adjcnt : 4;
    Uint32 bid : 4;
    Uint32 did : 8;
#else 
    Uint32 did : 8;
    Uint32 bid : 4;
    Uint32 adjcnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG;

/* Device (link) ID */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_DID_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_DID_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_DID_RESETVAL (0x00000000u)

/* Bank ID – Extension to DID */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_BID_MASK (0x00000F00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_BID_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_BID_RESETVAL (0x00000000u)

/* Number of adjustment resolution steps to adjust DAC LMFC. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_ADJCNT_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_ADJCNT_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_ADJCNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_ADDR (0x00041844u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG0_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 scr : 1;
    Uint32 rsvd2 : 2;
    Uint32 l_m1 : 5;
    Uint32 rsvd1 : 1;
    Uint32 adjdir : 1;
    Uint32 phadj : 1;
    Uint32 rsvd0 : 5;
#else 
    Uint32 rsvd0 : 5;
    Uint32 phadj : 1;
    Uint32 adjdir : 1;
    Uint32 rsvd1 : 1;
    Uint32 l_m1 : 5;
    Uint32 rsvd2 : 2;
    Uint32 scr : 1;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG;

/* Phase adjustment request to DAC. Subclass 2 only. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_PHADJ_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_PHADJ_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_PHADJ_RESETVAL (0x00000000u)

/* Direction to adjust DAC LMFC. 0 – Advance, 1 – Delay. Applies to Subclass 2 operation only. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_ADJDIR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_ADJDIR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_ADJDIR_RESETVAL (0x00000000u)

/* Number of lanes per converter device (link) minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_L_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_L_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_L_M1_RESETVAL (0x00000000u)

/* Scrambling enabled */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_SCR_MASK (0x00008000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_SCR_SHIFT (0x0000000Fu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_SCR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_ADDR (0x00041848u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG1_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 k_m1 : 5;
    Uint32 f_m1 : 8;
#else 
    Uint32 f_m1 : 8;
    Uint32 k_m1 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG;

/* Number of octets per frame minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_F_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_F_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_F_M1_RESETVAL (0x00000000u)

/* Number of frames per multiframe minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_K_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_K_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_K_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_ADDR (0x0004184Cu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG2_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cs : 2;
    Uint32 rsvd0 : 1;
    Uint32 n_m1 : 5;
    Uint32 m_m1 : 8;
#else 
    Uint32 m_m1 : 8;
    Uint32 n_m1 : 5;
    Uint32 rsvd0 : 1;
    Uint32 cs : 2;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG;

/* Number of converters per device minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_M_M1_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_M_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_M_M1_RESETVAL (0x00000000u)

/* Converter resolution minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_N_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_N_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_N_M1_RESETVAL (0x00000000u)

/* Number of control bits per sample */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_CS_MASK (0x0000C000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_CS_SHIFT (0x0000000Eu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_CS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_ADDR (0x00041850u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG3_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesdv : 3;
    Uint32 s_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 nprime_m1 : 5;
#else 
    Uint32 nprime_m1 : 5;
    Uint32 subclassv : 3;
    Uint32 s_m1 : 5;
    Uint32 jesdv : 3;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG;

/* Total number of bits per sample minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_NPRIME_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_NPRIME_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_NPRIME_M1_RESETVAL (0x00000000u)

/* Device Subclass Version. 000 – Subclass 0, 001 – Subclass 1, 010 – Subclass 2 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_SUBCLASSV_MASK (0x000000E0u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_SUBCLASSV_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_SUBCLASSV_RESETVAL (0x00000000u)

/* Number of samples per converter per frame cycle minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_S_M1_MASK (0x00001F00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_S_M1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_S_M1_RESETVAL (0x00000000u)

/* JESD204 version. 000 – JESD204A, 001 – JESD204B */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_JESDV_MASK (0x0000E000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_JESDV_SHIFT (0x0000000Du)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_JESDV_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_ADDR (0x00041854u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG4_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 res1 : 8;
    Uint32 hd : 1;
    Uint32 rsvd0 : 2;
    Uint32 cf : 5;
#else 
    Uint32 cf : 5;
    Uint32 rsvd0 : 2;
    Uint32 hd : 1;
    Uint32 res1 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG;

/* Number of control words per frame clock period per link */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_CF_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_CF_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_CF_RESETVAL (0x00000000u)

/* High Density format */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_HD_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_HD_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_HD_RESETVAL (0x00000000u)

/* Reserved field 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_RES1_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_RES1_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_RES1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_ADDR (0x00041858u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG5_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 res2 : 8;
#else 
    Uint32 res2 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG;

/* Reserved field 2 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG_RES2_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG_RES2_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG_RES2_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG_ADDR (0x0004185Cu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG6_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 match_data : 8;
    Uint32 match_ctrl : 1;
    Uint32 match_specific : 1;
    Uint32 min_latency_ena : 1;
    Uint32 rbd_m1 : 5;
#else 
    Uint32 rbd_m1 : 5;
    Uint32 min_latency_ena : 1;
    Uint32 match_specific : 1;
    Uint32 match_ctrl : 1;
    Uint32 match_data : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG;

/* number of frames for RX buffer delay minus 1 */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_RBD_M1_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_RBD_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_RBD_M1_RESETVAL (0x00000000u)

/* ignore RBD and release buffers as soon as possible (support for Subclass 0) */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MIN_LATENCY_ENA_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MIN_LATENCY_ENA_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MIN_LATENCY_ENA_RESETVAL (0x00000000u)

/* 1 = match with specified character to start buffering, 0 = start buffering with first non-/K/ */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_SPECIFIC_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_SPECIFIC_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_SPECIFIC_RESETVAL (0x00000000u)

/* 1 = match character is control character (typically 1) */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_CTRL_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_CTRL_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_CTRL_RESETVAL (0x00000000u)

/* specific control character to start buffering (typically /R/ = /K.28.0/ = 0x1C) */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_DATA_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_DATA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_MATCH_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_ADDR (0x00041860u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG7_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 error_ena : 8;
    Uint32 sync_request_ena : 8;
#else 
    Uint32 sync_request_ena : 8;
    Uint32 error_ena : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG;

/* choose which errors trigger sync request */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_SYNC_REQUEST_ENA_MASK (0x000000FFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_SYNC_REQUEST_ENA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_SYNC_REQUEST_ENA_RESETVAL (0x00000000u)

/* choose which errors contribute towards error count and error reporting */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_ERROR_ENA_MASK (0x0000FF00u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_ERROR_ENA_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_ERROR_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_ADDR (0x00041864u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG8_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd2 : 3;
    Uint32 disable_err_report : 1;
    Uint32 rsvd1 : 3;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd0 : 1;
    Uint32 sysref_mode : 3;
#else 
    Uint32 sysref_mode : 3;
    Uint32 rsvd0 : 1;
    Uint32 no_lane_sync : 1;
    Uint32 rsvd1 : 3;
    Uint32 disable_err_report : 1;
    Uint32 rsvd2 : 3;
    Uint32 mp_link_ena : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG;

/* sysref sampling mode. 0 = ignore all sysrefs, 1 = use all sysrefs, 2 = use only next sysref, 3 = skip one sysref and then use one (use only next, next sysref), 4 = skip one sysref and then use all, 5 = skip two sysrefs and then use one, 6 = skip two sysrefs and then use all */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_SYSREF_MODE_MASK (0x00000007u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_SYSREF_MODE_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_SYSREF_MODE_RESETVAL (0x00000000u)

/* 1 = transmitter does not support lane synchronization. do not check link configuration data. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_NO_LANE_SYNC_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_NO_LANE_SYNC_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_NO_LANE_SYNC_RESETVAL (0x00000000u)

/* suppress error reporting for subclass 0 operation. errors won't trigger sync_n but will be counted. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_DISABLE_ERR_REPORT_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_DISABLE_ERR_REPORT_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_DISABLE_ERR_REPORT_RESETVAL (0x00000000u)

/* multipoint link enable */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_MP_LINK_ENA_MASK (0x00003000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_MP_LINK_ENA_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_MP_LINK_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_ADDR (0x00041868u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG9_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 lane_skew : 5;
#else 
    Uint32 lane_skew : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG;

/* measured lane skew (on gated clock) */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG_LANE_SKEW_MASK (0x0000001Fu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG_LANE_SKEW_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG_LANE_SKEW_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG_ADDR (0x0004186Cu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG10_REG_RESETVAL (0x00000000u)

/* JESDRX_LINK1_CFG11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 err_cnt : 16;
#else 
    Uint32 err_cnt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG;

/* error count as reported over SYNC~ interface. write 1 to clear. */
#define CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG_ERR_CNT_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG_ERR_CNT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG_ERR_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG_ADDR (0x00041870u)
#define CSL_DFE_JESD_JESDRX_LINK1_CFG11_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE0_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG;

/* interrupt bit mask for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_ADDR (0x00041C04u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_MASK_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE0_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG;

/* captured interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_ADDR (0x00041C08u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_INTR_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE0_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG;

/* force interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_ADDR (0x00041C0Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE0_FORCE_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE1_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG;

/* interrupt bit mask for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_ADDR (0x00041C44u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_MASK_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE1_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG;

/* captured interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_ADDR (0x00041C48u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_INTR_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE1_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG;

/* force interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_ADDR (0x00041C4Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE1_FORCE_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE2_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG;

/* interrupt bit mask for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_ADDR (0x00041C84u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_MASK_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE2_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG;

/* captured interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_ADDR (0x00041C88u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_INTR_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE2_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG;

/* force interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_ADDR (0x00041C8Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE2_FORCE_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE3_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG;

/* interrupt bit mask for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* interrupt bit mask for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* interrupt bit mask for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_ADDR (0x00041CC4u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_MASK_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE3_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG;

/* captured interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO empty flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO read error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO full flag (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* captured interrupt bit for FIFO write error (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* captured interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_ADDR (0x00041CC8u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_INTR_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_LANE3_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 test_seq_err : 1;
    Uint32 fifo_write_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_empty : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 link_config_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 decoder_disp_err : 1;
#else 
    Uint32 decoder_disp_err : 1;
    Uint32 decoder_code_err : 1;
    Uint32 code_sync_err : 1;
    Uint32 buf_match_err : 1;
    Uint32 buf_overflow_err : 1;
    Uint32 link_config_err : 1;
    Uint32 frame_align_err : 1;
    Uint32 multiframe_align_err : 1;
    Uint32 fifo_empty : 1;
    Uint32 fifo_read_error : 1;
    Uint32 fifo_full : 1;
    Uint32 fifo_write_error : 1;
    Uint32 test_seq_err : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG;

/* force interrupt bit for 8b/10b disparity error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_DISP_ERR_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_DISP_ERR_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_DISP_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for 8b/10b not-in-table code error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_CODE_ERR_MASK (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_CODE_ERR_SHIFT (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_DECODER_CODE_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for code synchronization error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_CODE_SYNC_ERR_MASK (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_CODE_SYNC_ERR_SHIFT (0x00000002u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_CODE_SYNC_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer match error (first non-/K/ doesn't match match_ctrl and match_data) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_MATCH_ERR_MASK (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_MATCH_ERR_SHIFT (0x00000003u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_MATCH_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for elastic buffer overflow error (bad RBD value) */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_OVERFLOW_ERR_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_OVERFLOW_ERR_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_BUF_OVERFLOW_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for link configuration error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_LINK_CONFIG_ERR_MASK (0x00000020u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_LINK_CONFIG_ERR_SHIFT (0x00000005u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_LINK_CONFIG_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for frame alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FRAME_ALIGN_ERR_MASK (0x00000040u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FRAME_ALIGN_ERR_SHIFT (0x00000006u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for multiframe alignment error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_MULTIFRAME_ALIGN_ERR_MASK (0x00000080u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_MULTIFRAME_ALIGN_ERR_SHIFT (0x00000007u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_MULTIFRAME_ALIGN_ERR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO empty flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_EMPTY_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO read error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_READ_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO full flag */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_FULL_MASK (0x00000400u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_FULL_SHIFT (0x0000000Au)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_FULL_RESETVAL (0x00000000u)

/* force interrupt bit for FIFO write error */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_MASK (0x00000800u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_SHIFT (0x0000000Bu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_FIFO_WRITE_ERROR_RESETVAL (0x00000000u)

/* force interrupt bit for test sequence verification fail */
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_TEST_SEQ_ERR_MASK (0x00001000u)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_TEST_SEQ_ERR_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_TEST_SEQ_ERR_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_ADDR (0x00041CCCu)
#define CSL_DFE_JESD_JESDRX_INTR_LANE3_FORCE_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_SYSREF_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG;

/* interrupt bit mask for sysref_request_assert */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_request_deassert */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_err on link 0 */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* interrupt bit mask for sysref_err on link 1 */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_ADDR (0x00042004u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_MASK_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_SYSREF_INTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG;

/* captured interrupt bit for sysref_request_assert (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_request_deassert (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_err on link 0 (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* captured interrupt bit for sysref_err on link 1 (write 0 to clear) */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_ADDR (0x00042008u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_INTR_REG_RESETVAL (0x00000000u)

/* JESDRX_INTR_SYSREF_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sysref_err_link1 : 1;
    Uint32 sysref_err_link0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_assert : 1;
#else 
    Uint32 sysref_request_assert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sysref_request_deassert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sysref_err_link0 : 1;
    Uint32 sysref_err_link1 : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG;

/* force interrupt bit for sysref_request_assert */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_MASK (0x00000001u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_ASSERT_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_request_deassert */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_MASK (0x00000010u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_REQUEST_DEASSERT_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_err on link 0 */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_MASK (0x00000100u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK0_RESETVAL (0x00000000u)

/* force interrupt bit for sysref_err on link 1 */
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_MASK (0x00000200u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_SHIFT (0x00000009u)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_SYSREF_ERR_LINK1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_ADDR (0x0004200Cu)
#define CSL_DFE_JESD_JESDRX_INTR_SYSREF_FORCE_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_LANE0_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG_ADDR (0x00042404u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE0_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_LANE1_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG_ADDR (0x00042408u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE1_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_LANE2_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG_ADDR (0x0004240Cu)
#define CSL_DFE_JESD_JESDRX_MAP_LANE2_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_LANE3_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 num_frame_buf_m1 : 2;
#else 
    Uint32 num_frame_buf_m1 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG;

/* number of frames to buffer */
#define CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG_NUM_FRAME_BUF_M1_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG_NUM_FRAME_BUF_M1_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG_NUM_FRAME_BUF_M1_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG_ADDR (0x00042410u)
#define CSL_DFE_JESD_JESDRX_MAP_LANE3_CFG_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE00_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_ADDR (0x00042804u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE00_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_ADDR (0x00042808u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE00_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_ADDR (0x0004280Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE00_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_ADDR (0x00042810u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE00_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE01_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_ADDR (0x00042844u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE01_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_ADDR (0x00042848u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE01_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_ADDR (0x0004284Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE01_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_ADDR (0x00042850u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE01_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE02_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_ADDR (0x00042884u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE02_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_ADDR (0x00042888u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE02_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_ADDR (0x0004288Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE02_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_ADDR (0x00042890u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE02_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE03_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_ADDR (0x000428C4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE03_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_ADDR (0x000428C8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE03_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_ADDR (0x000428CCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE03_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_ADDR (0x000428D0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE03_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE04_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_ADDR (0x00042904u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE04_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_ADDR (0x00042908u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE04_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_ADDR (0x0004290Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE04_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_ADDR (0x00042910u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE04_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE05_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_ADDR (0x00042944u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE05_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_ADDR (0x00042948u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE05_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_ADDR (0x0004294Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE05_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_ADDR (0x00042950u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE05_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE06_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_ADDR (0x00042984u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE06_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_ADDR (0x00042988u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE06_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_ADDR (0x0004298Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE06_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_ADDR (0x00042990u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE06_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE07_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_ADDR (0x000429C4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE07_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_ADDR (0x000429C8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE07_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_ADDR (0x000429CCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE07_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_ADDR (0x000429D0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE07_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE08_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_ADDR (0x00042A04u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE08_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_ADDR (0x00042A08u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE08_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_ADDR (0x00042A0Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE08_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_ADDR (0x00042A10u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE08_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE09_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_ADDR (0x00042A44u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE09_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_ADDR (0x00042A48u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE09_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_ADDR (0x00042A4Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE09_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_ADDR (0x00042A50u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE09_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE10_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_ADDR (0x00042A84u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE10_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_ADDR (0x00042A88u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE10_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_ADDR (0x00042A8Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE10_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_ADDR (0x00042A90u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE10_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE11_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_ADDR (0x00042AC4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE11_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_ADDR (0x00042AC8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE11_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_ADDR (0x00042ACCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE11_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_ADDR (0x00042AD0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE11_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE12_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_ADDR (0x00042B04u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE12_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_ADDR (0x00042B08u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE12_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_ADDR (0x00042B0Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE12_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_ADDR (0x00042B10u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE12_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE13_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_ADDR (0x00042B44u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE13_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_ADDR (0x00042B48u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE13_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_ADDR (0x00042B4Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE13_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_ADDR (0x00042B50u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE13_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE14_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_ADDR (0x00042B84u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE14_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_ADDR (0x00042B88u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE14_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_ADDR (0x00042B8Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE14_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_ADDR (0x00042B90u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE14_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE15_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_ADDR (0x00042BC4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE15_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_ADDR (0x00042BC8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE15_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_ADDR (0x00042BCCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE15_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_ADDR (0x00042BD0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE15_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE16_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_ADDR (0x00042C04u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE16_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_ADDR (0x00042C08u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE16_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_ADDR (0x00042C0Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE16_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_ADDR (0x00042C10u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE16_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE17_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_ADDR (0x00042C44u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE17_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_ADDR (0x00042C48u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE17_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_ADDR (0x00042C4Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE17_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_ADDR (0x00042C50u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE17_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE18_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_ADDR (0x00042C84u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE18_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_ADDR (0x00042C88u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE18_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_ADDR (0x00042C8Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE18_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_ADDR (0x00042C90u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE18_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE19_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_ADDR (0x00042CC4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE19_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_ADDR (0x00042CC8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE19_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_ADDR (0x00042CCCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE19_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_ADDR (0x00042CD0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE19_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE20_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_ADDR (0x00042D04u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE20_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_ADDR (0x00042D08u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE20_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_ADDR (0x00042D0Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE20_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_ADDR (0x00042D10u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE20_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE21_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_ADDR (0x00042D44u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE21_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_ADDR (0x00042D48u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE21_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_ADDR (0x00042D4Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE21_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_ADDR (0x00042D50u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE21_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE22_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_ADDR (0x00042D84u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE22_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_ADDR (0x00042D88u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE22_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_ADDR (0x00042D8Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE22_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_ADDR (0x00042D90u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE22_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE23_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_ADDR (0x00042DC4u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE23_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_ADDR (0x00042DC8u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE23_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_ADDR (0x00042DCCu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_NIBBLE23_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 zero_bits : 4;
    Uint32 rsvd2 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_sel : 2;
#else 
    Uint32 lane_sel : 2;
    Uint32 rsvd0 : 2;
    Uint32 lane_nibble_sel : 2;
    Uint32 rsvd1 : 2;
    Uint32 time_slot_sel : 2;
    Uint32 rsvd2 : 2;
    Uint32 zero_bits : 4;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG;

/* lane select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_SEL_MASK (0x00000003u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_SEL_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_SEL_RESETVAL (0x00000000u)

/* lane nibble select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_NIBBLE_SEL_MASK (0x00000030u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_NIBBLE_SEL_SHIFT (0x00000004u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_LANE_NIBBLE_SEL_RESETVAL (0x00000000u)

/* time slot select */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_TIME_SLOT_SEL_MASK (0x00000300u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_TIME_SLOT_SEL_SHIFT (0x00000008u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_TIME_SLOT_SEL_RESETVAL (0x00000000u)

/* zero bits */
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_ZERO_BITS_MASK (0x0000F000u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_ZERO_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_ZERO_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_ADDR (0x00042DD0u)
#define CSL_DFE_JESD_JESDRX_MAP_NIBBLE23_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE0_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG_ADDR (0x00044004u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE0_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG_ADDR (0x00044008u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE0_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG_ADDR (0x0004400Cu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE0_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG_ADDR (0x00044010u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE0_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE1_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG_ADDR (0x00044014u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE1_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG_ADDR (0x00044018u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE1_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG_ADDR (0x0004401Cu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE1_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG_ADDR (0x00044020u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE1_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE2_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG_ADDR (0x00044024u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE2_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG_ADDR (0x00044028u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE2_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG_ADDR (0x0004402Cu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE2_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG_ADDR (0x00044030u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE2_POSITION3_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE3_POSITION0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG_ADDR (0x00044034u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION0_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE3_POSITION1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG_ADDR (0x00044038u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION1_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE3_POSITION2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG_ADDR (0x0004403Cu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION2_REG_RESETVAL (0x00000000u)

/* JESDRX_MAP_TEST_LANE3_POSITION3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 test_data : 16;
#else 
    Uint32 test_data : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG;

/* test data (read only) */
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG_TEST_DATA_MASK (0x0000FFFFu)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG_TEST_DATA_SHIFT (0x00000000u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG_TEST_DATA_RESETVAL (0x00000000u)

#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG_ADDR (0x00044040u)
#define CSL_DFE_JESD_JESDRX_MAP_TEST_LANE3_POSITION3_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_JESD_H__ */
