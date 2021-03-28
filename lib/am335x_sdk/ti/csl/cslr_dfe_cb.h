/*
 * cslr_dfe_cb.h
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

#ifndef CSLR_DFE_CB_H__
#define CSLR_DFE_CB_H__

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
    volatile Uint32 cb_arm;
    /* Addr: h(204), d(516) */
    volatile Uint32 bus_ctrl_reset;
    /* Addr: h(208), d(520) */
    volatile Uint32 cb_buffer_mode;
    /* Addr: h(20C), d(524) */
    volatile Uint32 dpda_read_skipchunk;
    /* Addr: h(210), d(528) */
    volatile Uint32 cba_setting;
    /* Addr: h(214), d(532) */
    volatile Uint32 cba_dly;
    /* Addr: h(218), d(536) */
    volatile Uint32 cbb_setting;
    /* Addr: h(21C), d(540) */
    volatile Uint32 cbb_dly;
    /* Addr: h(220), d(544) */
    volatile Uint32 cbc_setting;
    /* Addr: h(224), d(548) */
    volatile Uint32 cbc_dly;
    /* Addr: h(228), d(552) */
    volatile Uint32 cbd_setting;
    /* Addr: h(22C), d(556) */
    volatile Uint32 cbd_dly;
    /* Addr: h(230), d(560) */
    volatile Uint32 rate_mode;
    /* Addr: h(234), d(564) */
    volatile Uint32 node0_config;
    /* Addr: h(238), d(568) */
    volatile Uint32 node0_fsf_fsfm;
    /* Addr: h(23C), d(572) */
    volatile Uint32 node1_config;
    /* Addr: h(240), d(576) */
    volatile Uint32 node1_fsf_fsfm;
    /* Addr: h(244), d(580) */
    volatile Uint32 node2_config;
    /* Addr: h(248), d(584) */
    volatile Uint32 node2_fsf_fsfm;
    /* Addr: h(24C), d(588) */
    volatile Uint32 node3_config;
    /* Addr: h(250), d(592) */
    volatile Uint32 node3_fsf_fsfm;
    /* Addr: h(254), d(596) */
    volatile Uint32 node4_config;
    /* Addr: h(258), d(600) */
    volatile Uint32 node4_fsf_fsfm;
    /* Addr: h(25C), d(604) */
    volatile Uint32 node5_config;
    /* Addr: h(260), d(608) */
    volatile Uint32 node5_fsf_fsfm;
    /* Addr: h(264), d(612) */
    volatile Uint32 node6_config;
    /* Addr: h(268), d(616) */
    volatile Uint32 node6_fsf_fsfm;
    /* Addr: h(26C), d(620) */
    volatile Uint32 node7_config;
    /* Addr: h(270), d(624) */
    volatile Uint32 node7_fsf_fsfm;
    /* Addr: h(274), d(628) */
    volatile Uint32 node8_config;
    /* Addr: h(278), d(632) */
    volatile Uint32 node8_fsf_fsfm;
    /* Addr: h(27C), d(636) */
    volatile Uint32 frac_cnt;
    /* Addr: h(280), d(640) */
    volatile Uint32 initial_fractional_phase_ctrl;
    /* Addr: h(284), d(644) */
    volatile Uint32 done_frac_cnt;
    /* Addr: h(288), d(648) */
    volatile Uint32 buf_ab_done_addr;
    /* Addr: h(28C), d(652) */
    volatile Uint32 buf_cd_done_addr;
    /* Addr: h(290), d(656) */
    volatile Uint32 cba_done_length_cnt;
    /* Addr: h(294), d(660) */
    volatile Uint32 cbb_done_length_cnt;
    /* Addr: h(298), d(664) */
    volatile Uint32 cbc_done_length_cnt;
    /* Addr: h(29C), d(668) */
    volatile Uint32 cbd_done_length_cnt;
    /* Addr: h(2A0), d(672) */
    volatile Uint32 cb_c_multi_capture_ctrl;
    /* Addr: h(2A4), d(676) */
    volatile Uint32 cb_c_multicap_timer1;
    /* Addr: h(2A8), d(680) */
    volatile Uint32 cb_c_multicap_timer2;
    /* Addr: h(2AC), d(684) */
    volatile Uint32 cb_c_multicap_timer3;
    /* Addr: h(2B0), d(688) */
    volatile Uint32 cb_c_multicap_timer4;
    /* Addr: h(2B4), d(692) */
    volatile Uint32 cb_c_multicap_timer5;
    /* Addr: h(2B8), d(696) */
    volatile Uint32 cb_c_multicap_timer6;
    /* Addr: h(2BC), d(700) */
    volatile Uint32 cb_c_multicap_timer7;
    /* Addr: h(2C0), d(704) */
    volatile Uint32 cb_c_multicap_timer8;
    /* Addr: h(2C4), d(708) */
    volatile Uint32 chunk1_done_addr;
    /* Addr: h(2C8), d(712) */
    volatile Uint32 chunk2_done_addr;
    /* Addr: h(2CC), d(716) */
    volatile Uint32 chunk3_done_addr;
    /* Addr: h(2D0), d(720) */
    volatile Uint32 chunk4_done_addr;
    /* Addr: h(2D4), d(724) */
    volatile Uint32 chunk5_done_addr;
    /* Addr: h(2D8), d(728) */
    volatile Uint32 chunk6_done_addr;
    /* Addr: h(2DC), d(732) */
    volatile Uint32 chunk7_done_addr;
    /* Addr: h(2E0), d(736) */
    volatile Uint32 chunk8_done_addr;
    /* Addr: h(2E4), d(740) */
    volatile Uint32 trigger_monitor_setting;
    /* Addr: h(2E8), d(744) */
    volatile Uint32 trigger_monitor_a_config;
    /* Addr: h(2EC), d(748) */
    volatile Uint32 trigger_monitor_a_fsf_fsfm;
    /* Addr: h(2F0), d(752) */
    volatile Uint32 trigger_monitor_b_config;
    /* Addr: h(2F4), d(756) */
    volatile Uint32 trigger_monitor_b_fsf_fsfm;
    /* Addr: h(2F8), d(760) */
    volatile Uint32 triga_blk0_length;
    /* Addr: h(2FC), d(764) */
    volatile Uint32 triga_blk0_t1;
    /* Addr: h(300), d(768) */
    volatile Uint32 triga_blk0_t2;
    /* Addr: h(304), d(772) */
    volatile Uint32 triga_blk1_length;
    /* Addr: h(308), d(776) */
    volatile Uint32 triga_blk1_t1;
    /* Addr: h(30C), d(780) */
    volatile Uint32 triga_blk1_t2;
    /* Addr: h(310), d(784) */
    volatile Uint32 trigb_blk0_length;
    /* Addr: h(314), d(788) */
    volatile Uint32 trigb_blk0_t1;
    /* Addr: h(318), d(792) */
    volatile Uint32 trigb_blk0_t2;
    /* Addr: h(31C), d(796) */
    volatile Uint32 trigb_blk1_length;
    /* Addr: h(320), d(800) */
    volatile Uint32 trigb_blk1_t1;
    /* Addr: h(324), d(804) */
    volatile Uint32 trigb_blk1_t2;
    /* Addr: h(328), d(808) */
    volatile Uint32 trigger_monitor_decoder;
    /* Addr: h(32C), d(812) */
    volatile Uint32 gsg_mode;
    /* Addr: h(330), d(816) */
    volatile Uint32 gsg0_delayfromsync;
    /* Addr: h(334), d(820) */
    volatile Uint32 gsg0_timer1;
    /* Addr: h(338), d(824) */
    volatile Uint32 gsg0_timer2;
    /* Addr: h(33C), d(828) */
    volatile Uint32 gsg0_timer3;
    /* Addr: h(340), d(832) */
    volatile Uint32 gsg0_timer4;
    /* Addr: h(344), d(836) */
    volatile Uint32 gsg0_timer5;
    /* Addr: h(348), d(840) */
    volatile Uint32 gsg1_delayfromsync;
    /* Addr: h(34C), d(844) */
    volatile Uint32 gsg1_timer1;
    /* Addr: h(350), d(848) */
    volatile Uint32 gsg1_timer2;
    /* Addr: h(354), d(852) */
    volatile Uint32 gsg1_timer3;
    /* Addr: h(358), d(856) */
    volatile Uint32 gsg1_timer4;
    /* Addr: h(35C), d(860) */
    volatile Uint32 gsg1_timer5;
    /* Addr: h(360), d(864) */
    volatile Uint32 gsg2_delayfromsync;
    /* Addr: h(364), d(868) */
    volatile Uint32 gsg2_timer1;
    /* Addr: h(368), d(872) */
    volatile Uint32 gsg2_timer2;
    /* Addr: h(36C), d(876) */
    volatile Uint32 gsg2_timer3;
    /* Addr: h(370), d(880) */
    volatile Uint32 gsg2_timer4;
    /* Addr: h(374), d(884) */
    volatile Uint32 gsg2_timer5;
    /* Addr: h(378), d(888) */
    volatile Uint32 gsg3_delayfromsync;
    /* Addr: h(37C), d(892) */
    volatile Uint32 gsg3_timer1;
    /* Addr: h(380), d(896) */
    volatile Uint32 gsg3_timer2;
    /* Addr: h(384), d(900) */
    volatile Uint32 gsg3_timer3;
    /* Addr: h(388), d(904) */
    volatile Uint32 gsg3_timer4;
    /* Addr: h(38C), d(908) */
    volatile Uint32 gsg3_timer5;
    /* Addr: h(390), d(912) */
    volatile Uint32 gsg4_delayfromsync;
    /* Addr: h(394), d(916) */
    volatile Uint32 gsg4_timer1;
    /* Addr: h(398), d(920) */
    volatile Uint32 gsg4_timer2;
    /* Addr: h(39C), d(924) */
    volatile Uint32 gsg4_timer3;
    /* Addr: h(3A0), d(928) */
    volatile Uint32 gsg4_timer4;
    /* Addr: h(3A4), d(932) */
    volatile Uint32 gsg4_timer5;
    /* Addr: h(3A8), d(936) */
    volatile Uint32 gsg5_delayfromsync;
    /* Addr: h(3AC), d(940) */
    volatile Uint32 gsg5_timer1;
    /* Addr: h(3B0), d(944) */
    volatile Uint32 gsg5_timer2;
    /* Addr: h(3B4), d(948) */
    volatile Uint32 gsg5_timer3;
    /* Addr: h(3B8), d(952) */
    volatile Uint32 gsg5_timer4;
    /* Addr: h(3BC), d(956) */
    volatile Uint32 gsg5_timer5;
    /* Addr: h(3C0), d(960) */
    volatile Uint32 rsvd1[1];
    /* Addr: h(3C4), d(964) */
    volatile Uint32 gsg_ssel;
    /* Addr: h(3C8), d(968) */
    volatile Uint32 gsg_seq_sel_part1;
    /* Addr: h(3CC), d(972) */
    volatile Uint32 gsg_seq_sel_part2;
    /* Addr: h(3D0), d(976) */
    volatile Uint32 silent_detect_setting;
    /* Addr: h(3D4), d(980) */
    volatile Uint32 cb_f_chunk_selection;
    /* Addr: h(3D8), d(984) */
    volatile Uint32 cb_f_broken_chain_detection;
    /* Addr: h(3DC), d(988) */
    volatile Uint32 cb_f_maxrefpower_ant0_1;
    /* Addr: h(3E0), d(992) */
    volatile Uint32 cb_f_maxrefpower_ant2_3;
    /* Addr: h(3E4), d(996) */
    volatile Uint32 cb_f_deltapowerinlinear;
    /* Addr: h(3E8), d(1000) */
    volatile Uint32 cb_f_badbuffer_detection_en;
    /* Addr: h(3EC), d(1004) */
    volatile Uint32 power_monitor_sync_dly_ant0;
    /* Addr: h(3F0), d(1008) */
    volatile Uint32 power_monitor_sync_dly_ant1;
    /* Addr: h(3F4), d(1012) */
    volatile Uint32 power_monitor_sync_dly_ant2;
    /* Addr: h(3F8), d(1016) */
    volatile Uint32 power_monitor_sync_dly_ant3;
    /* Addr: h(3FC), d(1020) */
    volatile Uint32 power_monitor_intg_pd_ant0;
    /* Addr: h(400), d(1024) */
    volatile Uint32 power_monitor_intg_pd_ant1;
    /* Addr: h(404), d(1028) */
    volatile Uint32 power_monitor_intg_pd_ant2;
    /* Addr: h(408), d(1032) */
    volatile Uint32 power_monitor_intg_pd_ant3;
    /* Addr: h(40C), d(1036) */
    volatile Uint32 power_monitor_config_ant0;
    /* Addr: h(410), d(1040) */
    volatile Uint32 power_monitor_ant0_fsf_fsfm;
    /* Addr: h(414), d(1044) */
    volatile Uint32 power_monitor_config_ant1;
    /* Addr: h(418), d(1048) */
    volatile Uint32 power_monitor_ant1_fsf_fsfm;
    /* Addr: h(41C), d(1052) */
    volatile Uint32 power_monitor_config_ant2;
    /* Addr: h(420), d(1056) */
    volatile Uint32 power_monitor_ant2_fsf_fsfm;
    /* Addr: h(424), d(1060) */
    volatile Uint32 power_monitor_config_ant3;
    /* Addr: h(428), d(1064) */
    volatile Uint32 power_monitor_ant3_fsf_fsfm;
    /* Addr: h(42C), d(1068) */
    volatile Uint32 power_monitor_node_sel;
    /* Addr: h(430), d(1072) */
    volatile Uint32 cb_sourcing_control;
    /* Addr: h(434), d(1076) */
    volatile Uint32 cb_time_step;
    /* Addr: h(438), d(1080) */
    volatile Uint32 cb_reset_int;
    /* Addr: h(43C), d(1084) */
    volatile Uint32 cb_tdd_period;
    /* Addr: h(440), d(1088) */
    volatile Uint32 cb_tdd_on_0;
    /* Addr: h(444), d(1092) */
    volatile Uint32 cb_tdd_off_0;
    /* Addr: h(448), d(1096) */
    volatile Uint32 cb_tdd_on_1;
    /* Addr: h(44C), d(1100) */
    volatile Uint32 cb_tdd_off_1;
    /* Addr: h(450), d(1104) */
    volatile Uint32 inits;
    /* Addr: h(454), d(1108) */
    volatile Uint32 cb_sync_select_part1;
    /* Addr: h(458), d(1112) */
    volatile Uint32 cb_sync_select_part2;
    /* Addr: h(45C), d(1116) */
    volatile Uint32 cb_sync_select_part3;
    /* Addr: h(460), d(1120) */
    volatile Uint32 cb_src_node_control;
    /* Addr: h(464), d(1124) */
    volatile Uint32 buffer_full_flag;
    /* Addr: h(468), d(1128) */
    volatile Uint32 triga_blk0_outpwr;
    /* Addr: h(46C), d(1132) */
    volatile Uint32 triga_blk1_outpwr;
    /* Addr: h(470), d(1136) */
    volatile Uint32 trigb_blk0_outpwr;
    /* Addr: h(474), d(1140) */
    volatile Uint32 trigb_blk1_outpwr;
    /* Addr: h(478), d(1144) */
    volatile Uint32 cb_ref_fb_latency_ant0;
    /* Addr: h(47C), d(1148) */
    volatile Uint32 cb_ref_fb_latency_ant1;
    /* Addr: h(480), d(1152) */
    volatile Uint32 cb_ref_fb_latency_ant2;
    /* Addr: h(484), d(1156) */
    volatile Uint32 cb_ref_fb_latency_ant3;
    /* Addr: h(488), d(1160) */
    volatile Uint32 cb_sync_select_part4;
    /* Addr: h(48C), d(1164) */
    volatile Uint32 cba_chunk1_2_done_addr;
    /* Addr: h(490), d(1168) */
    volatile Uint32 cba_chunk3_4_done_addr;
    /* Addr: h(494), d(1172) */
    volatile Uint32 cba_chunk5_6_done_addr;
    /* Addr: h(498), d(1176) */
    volatile Uint32 cba_chunk7_8_done_addr;
    /* Addr: h(49C), d(1180) */
    volatile Uint32 cbb_chunk1_2_done_addr;
    /* Addr: h(4A0), d(1184) */
    volatile Uint32 cbb_chunk3_4_done_addr;
    /* Addr: h(4A4), d(1188) */
    volatile Uint32 cbb_chunk5_6_done_addr;
    /* Addr: h(4A8), d(1192) */
    volatile Uint32 cbb_chunk7_8_done_addr;
    /* Addr: h(4AC), d(1196) */
    volatile Uint32 cbc_chunk1_2_done_addr;
    /* Addr: h(4B0), d(1200) */
    volatile Uint32 cbc_chunk3_4_done_addr;
    /* Addr: h(4B4), d(1204) */
    volatile Uint32 cbc_chunk5_6_done_addr;
    /* Addr: h(4B8), d(1208) */
    volatile Uint32 cbc_chunk7_8_done_addr;
    /* Addr: h(4BC), d(1212) */
    volatile Uint32 cbd_chunk1_2_done_addr;
    /* Addr: h(4C0), d(1216) */
    volatile Uint32 cbd_chunk3_4_done_addr;
    /* Addr: h(4C4), d(1220) */
    volatile Uint32 cbd_chunk5_6_done_addr;
    /* Addr: h(4C8), d(1224) */
    volatile Uint32 cbd_chunk7_8_done_addr;
    /* Addr: h(4CC), d(1228) */
    volatile Uint32 rsvd2[65229];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 capture_buffer_a_16msb[8192];
    /* Addr: h(48000), d(294912) */
    volatile Uint32 capture_buffer_b_16msb[8192];
    /* Addr: h(50000), d(327680) */
    volatile Uint32 capture_buffer_c_16msb[8192];
    /* Addr: h(58000), d(360448) */
    volatile Uint32 capture_buffer_d_16msb[8192];
    /* Addr: h(60000), d(393216) */
    volatile Uint32 capture_buffer_a_2lsb[8192];
    /* Addr: h(68000), d(425984) */
    volatile Uint32 capture_buffer_b_2lsb[8192];
    /* Addr: h(70000), d(458752) */
    volatile Uint32 capture_buffer_c_2lsb[8192];
    /* Addr: h(78000), d(491520) */
    volatile Uint32 capture_buffer_d_2lsb[8192];
} CSL_DFE_CB_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CB_ARM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 26;
    Uint32 cb_f_capture_done : 1;
    Uint32 cb_f_sync_arm : 1;
    Uint32 rsvd0 : 2;
    Uint32 cb_c_capture_done : 1;
    Uint32 cb_c_sync_arm : 1;
#else 
    Uint32 cb_c_sync_arm : 1;
    Uint32 cb_c_capture_done : 1;
    Uint32 rsvd0 : 2;
    Uint32 cb_f_sync_arm : 1;
    Uint32 cb_f_capture_done : 1;
    Uint32 rsvd1 : 26;
#endif 
} CSL_DFE_CB_CB_ARM_REG;

/* arm control to cb_c_start_sync. It must be armed(set to 1) for cbc to start looking at sync. Once sync is detected, sync_arm will go back to 0 */
#define CSL_DFE_CB_CB_ARM_REG_CB_C_SYNC_ARM_MASK (0x00000001u)
#define CSL_DFE_CB_CB_ARM_REG_CB_C_SYNC_ARM_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_ARM_REG_CB_C_SYNC_ARM_RESETVAL (0x00000000u)

/* When capture is done, it will bring this signal low. Similar signal to sync_arm.  If the user sets it to 1 before capture starts, the chip will bring the signal to 0 when the capture is done.  */
#define CSL_DFE_CB_CB_ARM_REG_CB_C_CAPTURE_DONE_MASK (0x00000002u)
#define CSL_DFE_CB_CB_ARM_REG_CB_C_CAPTURE_DONE_SHIFT (0x00000001u)
#define CSL_DFE_CB_CB_ARM_REG_CB_C_CAPTURE_DONE_RESETVAL (0x00000000u)

/* arm control to cb_f_start_sync. It must be armed(set to 1) for cbf to start looking at sync. Once sync is detected, sync_arm will go back to 0 */
#define CSL_DFE_CB_CB_ARM_REG_CB_F_SYNC_ARM_MASK (0x00000010u)
#define CSL_DFE_CB_CB_ARM_REG_CB_F_SYNC_ARM_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_ARM_REG_CB_F_SYNC_ARM_RESETVAL (0x00000000u)

/* When capture is done, it will bring this signal low. Similar signal to sync_arm.  If the user sets it to 1 before capture starts, the chip will bring the signal to 0 when the capture is done.  */
#define CSL_DFE_CB_CB_ARM_REG_CB_F_CAPTURE_DONE_MASK (0x00000020u)
#define CSL_DFE_CB_CB_ARM_REG_CB_F_CAPTURE_DONE_SHIFT (0x00000005u)
#define CSL_DFE_CB_CB_ARM_REG_CB_F_CAPTURE_DONE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_ARM_REG_ADDR (0x00000200u)
#define CSL_DFE_CB_CB_ARM_REG_RESETVAL (0x00000000u)

/* BUS_CTRL_RESET */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 8;
    Uint32 dpd_mode : 4;
    Uint32 cb_f_force_done_reset : 1;
    Uint32 cb_f_subsample_fb : 1;
    Uint32 cb_c_force_done_reset : 1;
    Uint32 cb_c_force_arm_reset : 1;
    Uint32 rsvd3 : 3;
    Uint32 dsp_ctrl : 1;
    Uint32 rsvd2 : 3;
    Uint32 iq_swap : 1;
    Uint32 rsvd1 : 3;
    Uint32 tbus_sel : 1;
    Uint32 rsvd0 : 3;
    Uint32 nogating : 1;
#else 
    Uint32 nogating : 1;
    Uint32 rsvd0 : 3;
    Uint32 tbus_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 iq_swap : 1;
    Uint32 rsvd2 : 3;
    Uint32 dsp_ctrl : 1;
    Uint32 rsvd3 : 3;
    Uint32 cb_c_force_arm_reset : 1;
    Uint32 cb_c_force_done_reset : 1;
    Uint32 cb_f_subsample_fb : 1;
    Uint32 cb_f_force_done_reset : 1;
    Uint32 dpd_mode : 4;
    Uint32 rsvd4 : 8;
#endif 
} CSL_DFE_CB_BUS_CTRL_RESET_REG;

/* No gating mode:  */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_NOGATING_MASK (0x00000001u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_NOGATING_SHIFT (0x00000000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_NOGATING_RESETVAL (0x00000000u)

/* 0 = capture the 36 MSB's of 38-bit testbus */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_TBUS_SEL_MASK (0x00000010u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_TBUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_TBUS_SEL_RESETVAL (0x00000000u)

/* if set to '1', swap the I, Q data when put them onto mpurd bus. */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_IQ_SWAP_MASK (0x00000100u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_IQ_SWAP_SHIFT (0x00000008u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_IQ_SWAP_RESETVAL (0x00000000u)

/* When this bit is set to '0', capture buffer will not listen to arbiter, DSP will control the start and stop of capture buffer. Otherwise, capture buffer receives all commands from arbiter. */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DSP_CTRL_MASK (0x00001000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DSP_CTRL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DSP_CTRL_RESETVAL (0x00000000u)

/* force cb_c_sync_arm register into asynchronuous reset */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_ARM_RESET_MASK (0x00010000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_ARM_RESET_SHIFT (0x00000010u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_ARM_RESET_RESETVAL (0x00000000u)

/* force cb_c_capture_ done register into asynchronuous reset */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_DONE_RESET_MASK (0x00020000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_DONE_RESET_SHIFT (0x00000011u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_C_FORCE_DONE_RESET_RESETVAL (0x00000000u)

/* It only matters when we do CB-F capture. If fb signal is subsampled (by 2) relative to reference signal, then cb-f chunk size of fb signal is 256 and need to manipulate the memory write address to handle this since the sample cnt output from 'chunksel' is 0~511: */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_SUBSAMPLE_FB_MASK (0x00040000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_SUBSAMPLE_FB_SHIFT (0x00000012u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_SUBSAMPLE_FB_RESETVAL (0x00000000u)

/* force cb_f_capture_ done register into asynchronuous reset */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_FORCE_DONE_RESET_MASK (0x00080000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_FORCE_DONE_RESET_SHIFT (0x00000013u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_CB_F_FORCE_DONE_RESET_RESETVAL (0x00000000u)

/* The DPD mode information combined with 'antenna[2:0]' from arbiter will be used to program I/Q_bus_sel for cb-f capture of reference signal: */
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DPD_MODE_MASK (0x00F00000u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DPD_MODE_SHIFT (0x00000014u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_DPD_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_BUS_CTRL_RESET_REG_ADDR (0x00000204u)
#define CSL_DFE_CB_BUS_CTRL_RESET_REG_RESETVAL (0x00000000u)

/* CB_BUFFER_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 cbd_mode : 3;
    Uint32 rsvd2 : 1;
    Uint32 cbc_mode : 3;
    Uint32 rsvd1 : 1;
    Uint32 cbb_mode : 3;
    Uint32 rsvd0 : 1;
    Uint32 cba_mode : 3;
#else 
    Uint32 cba_mode : 3;
    Uint32 rsvd0 : 1;
    Uint32 cbb_mode : 3;
    Uint32 rsvd1 : 1;
    Uint32 cbc_mode : 3;
    Uint32 rsvd2 : 1;
    Uint32 cbd_mode : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_CB_CB_BUFFER_MODE_REG;

/* capture buffer operation mode: */
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBA_MODE_MASK (0x00000007u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBA_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBA_MODE_RESETVAL (0x00000000u)

/* same as cba_mode */
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBB_MODE_MASK (0x00000070u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBB_MODE_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBB_MODE_RESETVAL (0x00000000u)

/* same as cba_mode */
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBC_MODE_MASK (0x00000700u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBC_MODE_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBC_MODE_RESETVAL (0x00000000u)

/* same as cba_mode */
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBD_MODE_MASK (0x00007000u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBD_MODE_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_CBD_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_BUFFER_MODE_REG_ADDR (0x00000208u)
#define CSL_DFE_CB_CB_BUFFER_MODE_REG_RESETVAL (0x00000000u)

/* DPDA_READ_SKIPCHUNK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 spare_bits : 10;
    Uint32 readfb_skipchunk : 1;
    Uint32 readref_skipchunk : 1;
#else 
    Uint32 readref_skipchunk : 1;
    Uint32 readfb_skipchunk : 1;
    Uint32 spare_bits : 10;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG;

/* When this bit is set to '1', cb will skip the two last (useless) chunks when dpda reads (cb-f) reference data. Otherwise, cb will send out reference data continuously based on read address from dpda. */
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READREF_SKIPCHUNK_MASK (0x00000001u)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READREF_SKIPCHUNK_SHIFT (0x00000000u)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READREF_SKIPCHUNK_RESETVAL (0x00000000u)

/* When this bit is set to '1', cb will skip the two last (useless) chunks when dpda reads (cb-f) feedback data. Otherwise, cb will send out feedback data continuously based on read address from dpda. */
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READFB_SKIPCHUNK_MASK (0x00000002u)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READFB_SKIPCHUNK_SHIFT (0x00000001u)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_READFB_SKIPCHUNK_RESETVAL (0x00000000u)

/* spear bits reserved for future use */
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_SPARE_BITS_MASK (0x00000FFCu)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_SPARE_BITS_SHIFT (0x00000002u)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_SPARE_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_ADDR (0x0000020Cu)
#define CSL_DFE_CB_DPDA_READ_SKIPCHUNK_REG_RESETVAL (0x00000000u)

/* CBA_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 15;
    Uint32 cba_not_used : 1;
    Uint32 rsvd2 : 2;
    Uint32 cba_ref_or_fb : 2;
    Uint32 rsvd1 : 3;
    Uint32 cba_bus_sel : 1;
    Uint32 cba_sel : 4;
    Uint32 rsvd0 : 4;
#else 
    Uint32 rsvd0 : 4;
    Uint32 cba_sel : 4;
    Uint32 cba_bus_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 cba_ref_or_fb : 2;
    Uint32 rsvd2 : 2;
    Uint32 cba_not_used : 1;
    Uint32 rsvd3 : 15;
#endif 
} CSL_DFE_CB_CBA_SETTING_REG;

/* capture node select: */
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_SEL_RESETVAL (0x00000000u)

/* In 1x mode, when each buffer only captures two data buses, 'cba_bus_sel' determines which two buses to be captured at the selected node specified by 'cba_sel': */
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_BUS_SEL_MASK (0x00000100u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_BUS_SEL_RESETVAL (0x00000000u)

/* Indicate whehter capture buffer A is capturing reference signal or feedback signal, which it is doing cb-c or cb-f: */
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_REF_OR_FB_MASK (0x00003000u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_REF_OR_FB_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_REF_OR_FB_RESETVAL (0x00000000u)

/* 0 = capture buffer A is used for capture. Capture buffer A has to be done before 'cb_interrupt' is issued */
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_NOT_USED_MASK (0x00010000u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_NOT_USED_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBA_SETTING_REG_CBA_NOT_USED_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_SETTING_REG_ADDR (0x00000210u)
#define CSL_DFE_CB_CBA_SETTING_REG_RESETVAL (0x00000000u)

/* CBA_DLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cba_dly : 32;
#else 
    Uint32 cba_dly : 32;
#endif 
} CSL_DFE_CB_CBA_DLY_REG;

/* Capture buffer delay from sync (or 'trigger_stop' in trigger mode) to stop capturing, can also be used to accommodate the latency between reference signal and feedback signal unless in multicapture mode, then we have to use 'cba_start_delay'. */
#define CSL_DFE_CB_CBA_DLY_REG_CBA_DLY_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBA_DLY_REG_CBA_DLY_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_DLY_REG_CBA_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_DLY_REG_ADDR (0x00000214u)
#define CSL_DFE_CB_CBA_DLY_REG_RESETVAL (0x00000000u)

/* CBB_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 15;
    Uint32 cbb_not_used : 1;
    Uint32 rsvd2 : 2;
    Uint32 cbb_ref_or_fb : 2;
    Uint32 rsvd1 : 3;
    Uint32 cbb_bus_sel : 1;
    Uint32 cbb_sel : 4;
    Uint32 rsvd0 : 4;
#else 
    Uint32 rsvd0 : 4;
    Uint32 cbb_sel : 4;
    Uint32 cbb_bus_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 cbb_ref_or_fb : 2;
    Uint32 rsvd2 : 2;
    Uint32 cbb_not_used : 1;
    Uint32 rsvd3 : 15;
#endif 
} CSL_DFE_CB_CBB_SETTING_REG;

/* same as cba_sel */
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_SEL_RESETVAL (0x00000000u)

/* same as cba_bus_sel */
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_BUS_SEL_MASK (0x00000100u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_BUS_SEL_RESETVAL (0x00000000u)

/* same as cba_ref_or_fb */
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_REF_OR_FB_MASK (0x00003000u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_REF_OR_FB_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_REF_OR_FB_RESETVAL (0x00000000u)

/* 0 = capture buffer B is used for capture. Capture buffer B has to be done before 'cb_interrupt' is issued */
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_NOT_USED_MASK (0x00010000u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_NOT_USED_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBB_SETTING_REG_CBB_NOT_USED_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_SETTING_REG_ADDR (0x00000218u)
#define CSL_DFE_CB_CBB_SETTING_REG_RESETVAL (0x00000000u)

/* CBB_DLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbb_dly : 32;
#else 
    Uint32 cbb_dly : 32;
#endif 
} CSL_DFE_CB_CBB_DLY_REG;

/* same as cba_dly */
#define CSL_DFE_CB_CBB_DLY_REG_CBB_DLY_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBB_DLY_REG_CBB_DLY_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_DLY_REG_CBB_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_DLY_REG_ADDR (0x0000021Cu)
#define CSL_DFE_CB_CBB_DLY_REG_RESETVAL (0x00000000u)

/* CBC_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 15;
    Uint32 cbc_not_used : 1;
    Uint32 rsvd2 : 2;
    Uint32 cbc_ref_or_fb : 2;
    Uint32 rsvd1 : 3;
    Uint32 cbc_bus_sel : 1;
    Uint32 cbc_sel : 4;
    Uint32 rsvd0 : 4;
#else 
    Uint32 rsvd0 : 4;
    Uint32 cbc_sel : 4;
    Uint32 cbc_bus_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 cbc_ref_or_fb : 2;
    Uint32 rsvd2 : 2;
    Uint32 cbc_not_used : 1;
    Uint32 rsvd3 : 15;
#endif 
} CSL_DFE_CB_CBC_SETTING_REG;

/* same as cba_sel */
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_SEL_RESETVAL (0x00000000u)

/* same as cba_bus_sel */
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_BUS_SEL_MASK (0x00000100u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_BUS_SEL_RESETVAL (0x00000000u)

/* same as cba_ref_or_fb */
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_REF_OR_FB_MASK (0x00003000u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_REF_OR_FB_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_REF_OR_FB_RESETVAL (0x00000000u)

/* 0 = capture buffer C is used for capture. Capture buffer C has to be done before 'cb_interrupt' is issued */
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_NOT_USED_MASK (0x00010000u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_NOT_USED_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBC_SETTING_REG_CBC_NOT_USED_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_SETTING_REG_ADDR (0x00000220u)
#define CSL_DFE_CB_CBC_SETTING_REG_RESETVAL (0x00000000u)

/* CBC_DLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbc_dly : 32;
#else 
    Uint32 cbc_dly : 32;
#endif 
} CSL_DFE_CB_CBC_DLY_REG;

/* same as cba_dly */
#define CSL_DFE_CB_CBC_DLY_REG_CBC_DLY_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBC_DLY_REG_CBC_DLY_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_DLY_REG_CBC_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_DLY_REG_ADDR (0x00000224u)
#define CSL_DFE_CB_CBC_DLY_REG_RESETVAL (0x00000000u)

/* CBD_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 15;
    Uint32 cbd_not_used : 1;
    Uint32 rsvd2 : 2;
    Uint32 cbd_ref_or_fb : 2;
    Uint32 rsvd1 : 3;
    Uint32 cbd_bus_sel : 1;
    Uint32 cbd_sel : 4;
    Uint32 rsvd0 : 4;
#else 
    Uint32 rsvd0 : 4;
    Uint32 cbd_sel : 4;
    Uint32 cbd_bus_sel : 1;
    Uint32 rsvd1 : 3;
    Uint32 cbd_ref_or_fb : 2;
    Uint32 rsvd2 : 2;
    Uint32 cbd_not_used : 1;
    Uint32 rsvd3 : 15;
#endif 
} CSL_DFE_CB_CBD_SETTING_REG;

/* same as cba_sel */
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_SEL_RESETVAL (0x00000000u)

/* same as cba_bus_sel */
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_BUS_SEL_MASK (0x00000100u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_BUS_SEL_RESETVAL (0x00000000u)

/* same as cba_ref_or_fb */
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_REF_OR_FB_MASK (0x00003000u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_REF_OR_FB_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_REF_OR_FB_RESETVAL (0x00000000u)

/* 0 = capture buffer D is used for capture. Capture buffer D has to be done before 'cb_interrupt' is issued */
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_NOT_USED_MASK (0x00010000u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_NOT_USED_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBD_SETTING_REG_CBD_NOT_USED_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_SETTING_REG_ADDR (0x00000228u)
#define CSL_DFE_CB_CBD_SETTING_REG_RESETVAL (0x00000000u)

/* CBD_DLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbd_dly : 32;
#else 
    Uint32 cbd_dly : 32;
#endif 
} CSL_DFE_CB_CBD_DLY_REG;

/* same as cba_dly */
#define CSL_DFE_CB_CBD_DLY_REG_CBD_DLY_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBD_DLY_REG_CBD_DLY_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_DLY_REG_CBD_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_DLY_REG_ADDR (0x0000022Cu)
#define CSL_DFE_CB_CBD_DLY_REG_RESETVAL (0x00000000u)

/* RATE_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 cbd_rate_mode : 1;
    Uint32 cbc_rate_mode : 1;
    Uint32 cbb_rate_mode : 1;
    Uint32 cba_rate_mode : 1;
#else 
    Uint32 cba_rate_mode : 1;
    Uint32 cbb_rate_mode : 1;
    Uint32 cbc_rate_mode : 1;
    Uint32 cbd_rate_mode : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_RATE_MODE_REG;

/* 0 = 1s/1c mode, can capture up to two selected data buses */
#define CSL_DFE_CB_RATE_MODE_REG_CBA_RATE_MODE_MASK (0x00000001u)
#define CSL_DFE_CB_RATE_MODE_REG_CBA_RATE_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CB_RATE_MODE_REG_CBA_RATE_MODE_RESETVAL (0x00000000u)

/* same as cba_rate_mode */
#define CSL_DFE_CB_RATE_MODE_REG_CBB_RATE_MODE_MASK (0x00000002u)
#define CSL_DFE_CB_RATE_MODE_REG_CBB_RATE_MODE_SHIFT (0x00000001u)
#define CSL_DFE_CB_RATE_MODE_REG_CBB_RATE_MODE_RESETVAL (0x00000000u)

/* same as cba_rate_mode */
#define CSL_DFE_CB_RATE_MODE_REG_CBC_RATE_MODE_MASK (0x00000004u)
#define CSL_DFE_CB_RATE_MODE_REG_CBC_RATE_MODE_SHIFT (0x00000002u)
#define CSL_DFE_CB_RATE_MODE_REG_CBC_RATE_MODE_RESETVAL (0x00000000u)

/* same as cba_rate_mode */
#define CSL_DFE_CB_RATE_MODE_REG_CBD_RATE_MODE_MASK (0x00000008u)
#define CSL_DFE_CB_RATE_MODE_REG_CBD_RATE_MODE_SHIFT (0x00000003u)
#define CSL_DFE_CB_RATE_MODE_REG_CBD_RATE_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_RATE_MODE_REG_ADDR (0x00000230u)
#define CSL_DFE_CB_RATE_MODE_REG_RESETVAL (0x00000000u)

/* NODE0_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node0_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node0_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node0_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node0_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node0_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node0_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node0_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node0_i0bus_sel : 3;
#else 
    Uint32 node0_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node0_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node0_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node0_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node0_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node0_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node0_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node0_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE0_CONFIG_REG;

/* choose between bus0 ~bus7 for I0 data, if total number of buses at a capture node is less than 8, then some buses will be duplicated. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for Q0 data. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for I1 data. Only matters in 2s/1c mode or in multiband case. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for Q1 data. Only matters in 2s/1c mode or in multiband case. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1BUS_SEL_RESETVAL (0x00000000u)

/* I0 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I0FSDLY_RESETVAL (0x00000000u)

/* Q0 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q0FSDLY_RESETVAL (0x00000000u)

/* I1 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_I1FSDLY_RESETVAL (0x00000000u)

/* Q1 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE0_CONFIG_REG_NODE0_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE0_CONFIG_REG_ADDR (0x00000234u)
#define CSL_DFE_CB_NODE0_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE0_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node0_fsfm : 2;
    Uint32 node0_fsf : 2;
#else 
    Uint32 node0_fsf : 2;
    Uint32 node0_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE0_FSF_FSFM_REG;

/* frame strobe format; need to program the 2-bit combination of  */
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSF_RESETVAL (0x00000000u)

/* frame strobe format mask; program a 0 in bit locations where it is desired to mask out those bits in the 'frame strobe format'. */
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_NODE0_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_ADDR (0x00000238u)
#define CSL_DFE_CB_NODE0_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE1_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node1_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node1_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node1_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node1_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node1_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node1_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node1_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node1_i0bus_sel : 3;
#else 
    Uint32 node1_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node1_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node1_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node1_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node1_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node1_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node1_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node1_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE1_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE1_CONFIG_REG_NODE1_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE1_CONFIG_REG_ADDR (0x0000023Cu)
#define CSL_DFE_CB_NODE1_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE1_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node1_fsfm : 2;
    Uint32 node1_fsf : 2;
#else 
    Uint32 node1_fsf : 2;
    Uint32 node1_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE1_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_NODE1_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_ADDR (0x00000240u)
#define CSL_DFE_CB_NODE1_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE2_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node2_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node2_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node2_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node2_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node2_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node2_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node2_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node2_i0bus_sel : 3;
#else 
    Uint32 node2_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node2_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node2_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node2_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node2_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node2_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node2_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node2_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE2_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE2_CONFIG_REG_NODE2_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE2_CONFIG_REG_ADDR (0x00000244u)
#define CSL_DFE_CB_NODE2_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE2_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node2_fsfm : 2;
    Uint32 node2_fsf : 2;
#else 
    Uint32 node2_fsf : 2;
    Uint32 node2_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE2_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_NODE2_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_ADDR (0x00000248u)
#define CSL_DFE_CB_NODE2_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE3_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node3_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node3_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node3_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node3_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node3_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node3_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node3_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node3_i0bus_sel : 3;
#else 
    Uint32 node3_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node3_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node3_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node3_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node3_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node3_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node3_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node3_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE3_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE3_CONFIG_REG_NODE3_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE3_CONFIG_REG_ADDR (0x0000024Cu)
#define CSL_DFE_CB_NODE3_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE3_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node3_fsfm : 2;
    Uint32 node3_fsf : 2;
#else 
    Uint32 node3_fsf : 2;
    Uint32 node3_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE3_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_NODE3_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_ADDR (0x00000250u)
#define CSL_DFE_CB_NODE3_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE4_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node4_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node4_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node4_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node4_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node4_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node4_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node4_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node4_i0bus_sel : 3;
#else 
    Uint32 node4_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node4_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node4_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node4_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node4_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node4_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node4_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node4_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE4_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE4_CONFIG_REG_NODE4_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE4_CONFIG_REG_ADDR (0x00000254u)
#define CSL_DFE_CB_NODE4_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE4_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node4_fsfm : 2;
    Uint32 node4_fsf : 2;
#else 
    Uint32 node4_fsf : 2;
    Uint32 node4_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE4_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_NODE4_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_ADDR (0x00000258u)
#define CSL_DFE_CB_NODE4_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE5_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node5_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node5_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node5_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node5_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node5_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node5_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node5_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node5_i0bus_sel : 3;
#else 
    Uint32 node5_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node5_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node5_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node5_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node5_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node5_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node5_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node5_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE5_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE5_CONFIG_REG_NODE5_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE5_CONFIG_REG_ADDR (0x0000025Cu)
#define CSL_DFE_CB_NODE5_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE5_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node5_fsfm : 2;
    Uint32 node5_fsf : 2;
#else 
    Uint32 node5_fsf : 2;
    Uint32 node5_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE5_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_NODE5_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_ADDR (0x00000260u)
#define CSL_DFE_CB_NODE5_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE6_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node6_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node6_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node6_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node6_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node6_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node6_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node6_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node6_i0bus_sel : 3;
#else 
    Uint32 node6_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node6_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node6_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node6_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node6_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node6_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node6_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node6_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE6_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE6_CONFIG_REG_NODE6_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE6_CONFIG_REG_ADDR (0x00000264u)
#define CSL_DFE_CB_NODE6_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE6_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node6_fsfm : 2;
    Uint32 node6_fsf : 2;
#else 
    Uint32 node6_fsf : 2;
    Uint32 node6_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE6_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_NODE6_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_ADDR (0x00000268u)
#define CSL_DFE_CB_NODE6_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE7_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node7_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node7_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node7_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node7_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node7_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node7_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node7_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node7_i0bus_sel : 3;
#else 
    Uint32 node7_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node7_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node7_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node7_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node7_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node7_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node7_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node7_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE7_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE7_CONFIG_REG_NODE7_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE7_CONFIG_REG_ADDR (0x0000026Cu)
#define CSL_DFE_CB_NODE7_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE7_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node7_fsfm : 2;
    Uint32 node7_fsf : 2;
#else 
    Uint32 node7_fsf : 2;
    Uint32 node7_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE7_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_NODE7_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_ADDR (0x00000270u)
#define CSL_DFE_CB_NODE7_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* NODE8_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 node8_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node8_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node8_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node8_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 node8_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node8_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node8_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node8_i0bus_sel : 3;
#else 
    Uint32 node8_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 node8_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 node8_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 node8_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 node8_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 node8_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 node8_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 node8_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_NODE8_CONFIG_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_NODE8_CONFIG_REG_NODE8_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE8_CONFIG_REG_ADDR (0x00000274u)
#define CSL_DFE_CB_NODE8_CONFIG_REG_RESETVAL (0x00000000u)

/* NODE8_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 node8_fsfm : 2;
    Uint32 node8_fsf : 2;
#else 
    Uint32 node8_fsf : 2;
    Uint32 node8_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_NODE8_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_NODE8_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_ADDR (0x00000278u)
#define CSL_DFE_CB_NODE8_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* FRAC_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cbd_frac_cnt : 4;
    Uint32 cbc_frac_cnt : 4;
    Uint32 cbb_frac_cnt : 4;
    Uint32 cba_frac_cnt : 4;
#else 
    Uint32 cba_frac_cnt : 4;
    Uint32 cbb_frac_cnt : 4;
    Uint32 cbc_frac_cnt : 4;
    Uint32 cbd_frac_cnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_FRAC_CNT_REG;

/* capture buffer A fractional counter length minus 1; range 0-15; value depends on the relative sampling rates for different buffers, e.g. if reference signal is captured in buffer A and has sample rate 100 MS/sec and feedback signal is captured in buffer B and has sample rate of (3/5)*100 MS/sec, then the  */
#define CSL_DFE_CB_FRAC_CNT_REG_CBA_FRAC_CNT_MASK (0x0000000Fu)
#define CSL_DFE_CB_FRAC_CNT_REG_CBA_FRAC_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBA_FRAC_CNT_RESETVAL (0x00000000u)

/* see definition of 'cba_frac_cnt' */
#define CSL_DFE_CB_FRAC_CNT_REG_CBB_FRAC_CNT_MASK (0x000000F0u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBB_FRAC_CNT_SHIFT (0x00000004u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBB_FRAC_CNT_RESETVAL (0x00000000u)

/* see definition of 'cba_frac_cnt' */
#define CSL_DFE_CB_FRAC_CNT_REG_CBC_FRAC_CNT_MASK (0x00000F00u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBC_FRAC_CNT_SHIFT (0x00000008u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBC_FRAC_CNT_RESETVAL (0x00000000u)

/* see definition of 'cba_frac_cnt' */
#define CSL_DFE_CB_FRAC_CNT_REG_CBD_FRAC_CNT_MASK (0x0000F000u)
#define CSL_DFE_CB_FRAC_CNT_REG_CBD_FRAC_CNT_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_FRAC_CNT_REG_CBD_FRAC_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_FRAC_CNT_REG_ADDR (0x0000027Cu)
#define CSL_DFE_CB_FRAC_CNT_REG_RESETVAL (0x00000000u)

/* INITIAL_FRACTIONAL_PHASE_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 24;
    Uint32 init_frac_phase : 4;
    Uint32 rsvd0 : 3;
    Uint32 init_frac_phase_en : 1;
#else 
    Uint32 init_frac_phase_en : 1;
    Uint32 rsvd0 : 3;
    Uint32 init_frac_phase : 4;
    Uint32 rsvd1 : 24;
#endif 
} CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG;

/* may delay the stop of the capture for a few samples in order to make sure each captured chunk of reference signal starts with certain fractional phase specified by 'init_frac_phase': */
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_EN_MASK (0x00000001u)
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_EN_SHIFT (0x00000000u)
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_EN_RESETVAL (0x00000000u)

/* When 'init_frac_phase_en' is set, 'init_frac_phase' can be used to adjust the fractional phase of the first captured reference sampe */
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_MASK (0x000000F0u)
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_SHIFT (0x00000004u)
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_INIT_FRAC_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_ADDR (0x00000280u)
#define CSL_DFE_CB_INITIAL_FRACTIONAL_PHASE_CTRL_REG_RESETVAL (0x00000000u)

/* DONE_FRAC_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cbd_done_frac_cnt : 4;
    Uint32 cbc_done_frac_cnt : 4;
    Uint32 cbb_done_frac_cnt : 4;
    Uint32 cba_done_frac_cnt : 4;
#else 
    Uint32 cba_done_frac_cnt : 4;
    Uint32 cbb_done_frac_cnt : 4;
    Uint32 cbc_done_frac_cnt : 4;
    Uint32 cbd_done_frac_cnt : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_DONE_FRAC_CNT_REG;

/* capture buffer A finished capture fractional counter value; number to track fractional phase between different buffers; will report the phase that was associated with the most recent capture in cba (e.g. if  */
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBA_DONE_FRAC_CNT_MASK (0x0000000Fu)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBA_DONE_FRAC_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBA_DONE_FRAC_CNT_RESETVAL (0x00000000u)

/* similar to cba_done_frac_cnt */
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBB_DONE_FRAC_CNT_MASK (0x000000F0u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBB_DONE_FRAC_CNT_SHIFT (0x00000004u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBB_DONE_FRAC_CNT_RESETVAL (0x00000000u)

/* similar to cba_done_frac_cnt */
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBC_DONE_FRAC_CNT_MASK (0x00000F00u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBC_DONE_FRAC_CNT_SHIFT (0x00000008u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBC_DONE_FRAC_CNT_RESETVAL (0x00000000u)

/* similar to cba_done_frac_cnt */
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBD_DONE_FRAC_CNT_MASK (0x0000F000u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBD_DONE_FRAC_CNT_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_CBD_DONE_FRAC_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_DONE_FRAC_CNT_REG_ADDR (0x00000284u)
#define CSL_DFE_CB_DONE_FRAC_CNT_REG_RESETVAL (0x00000000u)

/* BUF_AB_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbb_done_addr : 16;
    Uint32 cba_done_addr : 16;
#else 
    Uint32 cba_done_addr : 16;
    Uint32 cbb_done_addr : 16;
#endif 
} CSL_DFE_CB_BUF_AB_DONE_ADDR_REG;

/* capture buffer A finished capture location + 1 */
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBA_DONE_ADDR_MASK (0x0000FFFFu)
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBA_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBA_DONE_ADDR_RESETVAL (0x00000000u)

/* capture buffer B finished capture location + 1 */
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBB_DONE_ADDR_MASK (0xFFFF0000u)
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBB_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_CBB_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_ADDR (0x00000288u)
#define CSL_DFE_CB_BUF_AB_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* BUF_CD_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbd_done_addr : 16;
    Uint32 cbc_done_addr : 16;
#else 
    Uint32 cbc_done_addr : 16;
    Uint32 cbd_done_addr : 16;
#endif 
} CSL_DFE_CB_BUF_CD_DONE_ADDR_REG;

/* capture buffer C finished capture location + 1 */
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBC_DONE_ADDR_MASK (0x0000FFFFu)
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBC_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBC_DONE_ADDR_RESETVAL (0x00000000u)

/* capture buffer D finished capture location + 1 */
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBD_DONE_ADDR_MASK (0xFFFF0000u)
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBD_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_CBD_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_ADDR (0x0000028Cu)
#define CSL_DFE_CB_BUF_CD_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBA_DONE_LENGTH_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cba_done_length_cnt : 32;
#else 
    Uint32 cba_done_length_cnt : 32;
#endif 
} CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG;

/* number of samples from capture buffer A length counter sync to end of data capture */
#define CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG_CBA_DONE_LENGTH_CNT_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG_CBA_DONE_LENGTH_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG_CBA_DONE_LENGTH_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG_ADDR (0x00000290u)
#define CSL_DFE_CB_CBA_DONE_LENGTH_CNT_REG_RESETVAL (0x00000000u)

/* CBB_DONE_LENGTH_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbb_done_length_cnt : 32;
#else 
    Uint32 cbb_done_length_cnt : 32;
#endif 
} CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG;

/* similar to cba_done_length_cnt */
#define CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG_CBB_DONE_LENGTH_CNT_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG_CBB_DONE_LENGTH_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG_CBB_DONE_LENGTH_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG_ADDR (0x00000294u)
#define CSL_DFE_CB_CBB_DONE_LENGTH_CNT_REG_RESETVAL (0x00000000u)

/* CBC_DONE_LENGTH_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbc_done_length_cnt : 32;
#else 
    Uint32 cbc_done_length_cnt : 32;
#endif 
} CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG;

/* similar to cba_done_length_cnt */
#define CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG_CBC_DONE_LENGTH_CNT_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG_CBC_DONE_LENGTH_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG_CBC_DONE_LENGTH_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG_ADDR (0x00000298u)
#define CSL_DFE_CB_CBC_DONE_LENGTH_CNT_REG_RESETVAL (0x00000000u)

/* CBD_DONE_LENGTH_CNT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbd_done_length_cnt : 32;
#else 
    Uint32 cbd_done_length_cnt : 32;
#endif 
} CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG;

/* similar to cba_done_length_cnt */
#define CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG_CBD_DONE_LENGTH_CNT_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG_CBD_DONE_LENGTH_CNT_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG_CBD_DONE_LENGTH_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG_ADDR (0x0000029Cu)
#define CSL_DFE_CB_CBD_DONE_LENGTH_CNT_REG_RESETVAL (0x00000000u)

/* CB_C_MULTI_CAPTURE_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 11;
    Uint32 cb_c_chunk_size : 13;
    Uint32 cb_c_num_captures : 4;
    Uint32 rsvd0 : 3;
    Uint32 cb_c_multi_capture : 1;
#else 
    Uint32 cb_c_multi_capture : 1;
    Uint32 rsvd0 : 3;
    Uint32 cb_c_num_captures : 4;
    Uint32 cb_c_chunk_size : 13;
    Uint32 rsvd1 : 11;
#endif 
} CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG;

/* multiple capture enable: */
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_MULTI_CAPTURE_MASK (0x00000001u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_MULTI_CAPTURE_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_MULTI_CAPTURE_RESETVAL (0x00000000u)

/* Number of captures upon one capture request (only matters when mult_capture = 1), max value is 8. */
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_NUM_CAPTURES_MASK (0x000000F0u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_NUM_CAPTURES_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_NUM_CAPTURES_RESETVAL (0x00000000u)

/* valid chunk size must be power of 2, range from 1024 to 8192 */
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_CHUNK_SIZE_MASK (0x001FFF00u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_CHUNK_SIZE_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_CB_C_CHUNK_SIZE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_ADDR (0x000002A0u)
#define CSL_DFE_CB_CB_C_MULTI_CAPTURE_CTRL_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer1 : 24;
#else 
    Uint32 cb_c_multicap_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG;

/* Delay from 'trigger' to start capturing the first chunk in samples.  */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG_CB_C_MULTICAP_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG_CB_C_MULTICAP_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG_CB_C_MULTICAP_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG_ADDR (0x000002A4u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER1_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer2 : 24;
#else 
    Uint32 cb_c_multicap_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG;

/* Delay from 'trigger' to start capturing the second chunk in samples. (Make sure that 'timer2' is greater than 'timer1 + cb_c_chunk_size') */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG_CB_C_MULTICAP_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG_CB_C_MULTICAP_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG_CB_C_MULTICAP_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG_ADDR (0x000002A8u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER2_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer3 : 24;
#else 
    Uint32 cb_c_multicap_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG_CB_C_MULTICAP_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG_CB_C_MULTICAP_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG_CB_C_MULTICAP_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG_ADDR (0x000002ACu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER3_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer4 : 24;
#else 
    Uint32 cb_c_multicap_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG_CB_C_MULTICAP_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG_CB_C_MULTICAP_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG_CB_C_MULTICAP_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG_ADDR (0x000002B0u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER4_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer5 : 24;
#else 
    Uint32 cb_c_multicap_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG_CB_C_MULTICAP_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG_CB_C_MULTICAP_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG_CB_C_MULTICAP_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG_ADDR (0x000002B4u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER5_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer6 : 24;
#else 
    Uint32 cb_c_multicap_timer6 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG_CB_C_MULTICAP_TIMER6_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG_CB_C_MULTICAP_TIMER6_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG_CB_C_MULTICAP_TIMER6_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG_ADDR (0x000002B8u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER6_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer7 : 24;
#else 
    Uint32 cb_c_multicap_timer7 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG_CB_C_MULTICAP_TIMER7_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG_CB_C_MULTICAP_TIMER7_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG_CB_C_MULTICAP_TIMER7_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG_ADDR (0x000002BCu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER7_REG_RESETVAL (0x00000000u)

/* CB_C_MULTICAP_TIMER8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 cb_c_multicap_timer8 : 24;
#else 
    Uint32 cb_c_multicap_timer8 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG;

/* see description of 'cb_c_multicap_timer1' */
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG_CB_C_MULTICAP_TIMER8_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG_CB_C_MULTICAP_TIMER8_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG_CB_C_MULTICAP_TIMER8_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG_ADDR (0x000002C0u)
#define CSL_DFE_CB_CB_C_MULTICAP_TIMER8_REG_RESETVAL (0x00000000u)

/* CHUNK1_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk1_done_addr : 13;
#else 
    Uint32 ref_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk1_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK1_DONE_ADDR_REG;

/* In sharing mode and trigger mode, each section of cb-c buffer (of size chunk size) is a circular buffer, this register indicates where the capture stoped when capture chunk 1 of reference signal */
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_REF_CHUNK1_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_REF_CHUNK1_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_REF_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

/* In sharing mode and trigger mode, each section of cb-c buffer (of size chunk size) is a circular buffer, this register indicates where the capture stoped when capture chunk 1 of feedback signal */
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_FB_CHUNK1_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_FB_CHUNK1_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_FB_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_ADDR (0x000002C4u)
#define CSL_DFE_CB_CHUNK1_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK2_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk2_done_addr : 13;
#else 
    Uint32 ref_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk2_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK2_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_REF_CHUNK2_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_REF_CHUNK2_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_REF_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_FB_CHUNK2_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_FB_CHUNK2_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_FB_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_ADDR (0x000002C8u)
#define CSL_DFE_CB_CHUNK2_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK3_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk3_done_addr : 13;
#else 
    Uint32 ref_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk3_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK3_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_REF_CHUNK3_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_REF_CHUNK3_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_REF_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_FB_CHUNK3_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_FB_CHUNK3_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_FB_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_ADDR (0x000002CCu)
#define CSL_DFE_CB_CHUNK3_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK4_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk4_done_addr : 13;
#else 
    Uint32 ref_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk4_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK4_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_REF_CHUNK4_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_REF_CHUNK4_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_REF_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_FB_CHUNK4_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_FB_CHUNK4_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_FB_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_ADDR (0x000002D0u)
#define CSL_DFE_CB_CHUNK4_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK5_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk5_done_addr : 13;
#else 
    Uint32 ref_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk5_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK5_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_REF_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_REF_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_REF_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_FB_CHUNK5_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_FB_CHUNK5_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_FB_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_ADDR (0x000002D4u)
#define CSL_DFE_CB_CHUNK5_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK6_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk6_done_addr : 13;
#else 
    Uint32 ref_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK6_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_REF_CHUNK6_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_REF_CHUNK6_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_REF_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_FB_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_FB_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_FB_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_ADDR (0x000002D8u)
#define CSL_DFE_CB_CHUNK6_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK7_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk7_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk7_done_addr : 13;
#else 
    Uint32 ref_chunk7_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk7_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK7_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_REF_CHUNK7_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_REF_CHUNK7_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_REF_CHUNK7_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_FB_CHUNK7_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_FB_CHUNK7_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_FB_CHUNK7_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_ADDR (0x000002DCu)
#define CSL_DFE_CB_CHUNK7_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CHUNK8_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 fb_chunk8_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 ref_chunk8_done_addr : 13;
#else 
    Uint32 ref_chunk8_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 fb_chunk8_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CHUNK8_DONE_ADDR_REG;

/* similar to 'ref_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_REF_CHUNK8_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_REF_CHUNK8_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_REF_CHUNK8_DONE_ADDR_RESETVAL (0x00000000u)

/* similar to 'fb_chunk1_done_addr' */
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_FB_CHUNK8_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_FB_CHUNK8_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_FB_CHUNK8_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_ADDR (0x000002E0u)
#define CSL_DFE_CB_CHUNK8_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 12;
    Uint32 trigb_blk1_ioc : 1;
    Uint32 trigb_blk0_ioc : 1;
    Uint32 triga_blk1_ioc : 1;
    Uint32 triga_blk0_ioc : 1;
    Uint32 trigb_blk1_magsqd_sel : 1;
    Uint32 trigb_blk0_magsqd_sel : 1;
    Uint32 triga_blk1_magsqd_sel : 1;
    Uint32 triga_blk0_magsqd_sel : 1;
    Uint32 rsvd0 : 2;
    Uint32 trigb_multiband : 1;
    Uint32 triga_multiband : 1;
    Uint32 trigb_sel : 4;
    Uint32 triga_sel : 4;
#else 
    Uint32 triga_sel : 4;
    Uint32 trigb_sel : 4;
    Uint32 triga_multiband : 1;
    Uint32 trigb_multiband : 1;
    Uint32 rsvd0 : 2;
    Uint32 triga_blk0_magsqd_sel : 1;
    Uint32 triga_blk1_magsqd_sel : 1;
    Uint32 trigb_blk0_magsqd_sel : 1;
    Uint32 trigb_blk1_magsqd_sel : 1;
    Uint32 triga_blk0_ioc : 1;
    Uint32 triga_blk1_ioc : 1;
    Uint32 trigb_blk0_ioc : 1;
    Uint32 trigb_blk1_ioc : 1;
    Uint32 rsvd1 : 12;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG;

/* node selection for trigger moniter A */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_SEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_SEL_RESETVAL (0x00000000u)

/* node selection for trigger moniter B */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_SEL_RESETVAL (0x00000000u)

/* when set to '1', trigger moniter block will moniter all four data buses, i.e. I0, Q0, I1, Q1, of the selected node. (I0, Q0) and (I1, Q1) are complex signal for two different sub-bands. */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_MULTIBAND_MASK (0x00000100u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_MULTIBAND_SHIFT (0x00000008u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_MULTIBAND_RESETVAL (0x00000000u)

/* when set to '1', trigger moniter block will moniter all four data buses, i.e. I0, Q0, I1, Q1, of the selected node. (I0, Q0) and (I1, Q1) are complex signal for two different sub-bands. */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_MULTIBAND_MASK (0x00000200u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_MULTIBAND_SHIFT (0x00000009u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_MULTIBAND_RESETVAL (0x00000000u)

/* trigger A block 0 magnitude or magnitude square select: 1 magsqd, 0 mag */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_MAGSQD_SEL_MASK (0x00001000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_MAGSQD_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_MAGSQD_SEL_RESETVAL (0x00000000u)

/* trigger A block 1 magnitude or magnitude square select: 1 magsqd, 0 mag */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_MAGSQD_SEL_MASK (0x00002000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_MAGSQD_SEL_SHIFT (0x0000000Du)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_MAGSQD_SEL_RESETVAL (0x00000000u)

/* trigger B block 0 magnitude or magnitude square select: 1 magsqd, 0 mag */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_MAGSQD_SEL_MASK (0x00004000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_MAGSQD_SEL_SHIFT (0x0000000Eu)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_MAGSQD_SEL_RESETVAL (0x00000000u)

/* trigger B block 1 magnitude or magnitude square select: 1 magsqd, 0 mag */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_MAGSQD_SEL_MASK (0x00008000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_MAGSQD_SEL_SHIFT (0x0000000Fu)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_MAGSQD_SEL_RESETVAL (0x00000000u)

/* trigger A block 0 integrator counter select: 1 integrator; 0 counter */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_IOC_MASK (0x00010000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_IOC_SHIFT (0x00000010u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK0_IOC_RESETVAL (0x00000000u)

/* trigger A block 1 integrator counter select: 1 integrator; 0 counter */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_IOC_MASK (0x00020000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_IOC_SHIFT (0x00000011u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGA_BLK1_IOC_RESETVAL (0x00000000u)

/* trigger B block 0 integrator counter select: 1 integrator; 0 counter */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_IOC_MASK (0x00040000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_IOC_SHIFT (0x00000012u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK0_IOC_RESETVAL (0x00000000u)

/* trigger B block 1 integrator counter select: 1 integrator; 0 counter */
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_IOC_MASK (0x00080000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_IOC_SHIFT (0x00000013u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_TRIGB_BLK1_IOC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_ADDR (0x000002E4u)
#define CSL_DFE_CB_TRIGGER_MONITOR_SETTING_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_A_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 triga_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 triga_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 triga_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 triga_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 triga_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 triga_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 triga_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 triga_i0bus_sel : 3;
#else 
    Uint32 triga_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 triga_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 triga_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 triga_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 triga_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 triga_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 triga_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 triga_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG;

/* choose between bus0 ~bus7 for I0 data, if total number of buses at a capture node is less than 8, then some buses will be duplicated. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for Q0 data. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for I1 data. Only matters when 'triga_multiband' is set to '1'. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1BUS_SEL_RESETVAL (0x00000000u)

/* choose between bus0 ~bus7 for Q1 data. Only matters when 'triga_multiband' is set to '1'. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1BUS_SEL_RESETVAL (0x00000000u)

/* I0 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I0FSDLY_RESETVAL (0x00000000u)

/* Q0 data delay locaton relative to frame start on the corresponding selected bus. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q0FSDLY_RESETVAL (0x00000000u)

/* I1 data delay locaton relative to frame start on the corresponding selected bus. Only matters when 'triga_multiband' is set to '1'. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_I1FSDLY_RESETVAL (0x00000000u)

/* Q1 data delay locaton relative to frame start on the corresponding selected bus. Only matters when 'triga_multiband' is set to '1'. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_TRIGA_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_ADDR (0x000002E8u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_CONFIG_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_A_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 triga_fsfm : 2;
    Uint32 triga_fsf : 2;
#else 
    Uint32 triga_fsf : 2;
    Uint32 triga_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_TRIGA_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_ADDR (0x000002ECu)
#define CSL_DFE_CB_TRIGGER_MONITOR_A_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_B_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd7 : 1;
    Uint32 trigb_q1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 trigb_i1fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 trigb_q0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 trigb_i0fsdly : 3;
    Uint32 rsvd3 : 1;
    Uint32 trigb_q1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 trigb_i1bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 trigb_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 trigb_i0bus_sel : 3;
#else 
    Uint32 trigb_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 trigb_q0bus_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 trigb_i1bus_sel : 3;
    Uint32 rsvd2 : 1;
    Uint32 trigb_q1bus_sel : 3;
    Uint32 rsvd3 : 1;
    Uint32 trigb_i0fsdly : 3;
    Uint32 rsvd4 : 1;
    Uint32 trigb_q0fsdly : 3;
    Uint32 rsvd5 : 1;
    Uint32 trigb_i1fsdly : 3;
    Uint32 rsvd6 : 1;
    Uint32 trigb_q1fsdly : 3;
    Uint32 rsvd7 : 1;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG;

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1BUS_SEL_MASK (0x00000700u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1BUS_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1BUS_SEL_MASK (0x00007000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1BUS_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1FSDLY_MASK (0x07000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1FSDLY_SHIFT (0x00000018u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_I1FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1FSDLY_MASK (0x70000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1FSDLY_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_TRIGB_Q1FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_ADDR (0x000002F0u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_CONFIG_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_B_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 trigb_fsfm : 2;
    Uint32 trigb_fsf : 2;
#else 
    Uint32 trigb_fsf : 2;
    Uint32 trigb_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG;

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for triga. */
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_TRIGB_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_ADDR (0x000002F4u)
#define CSL_DFE_CB_TRIGGER_MONITOR_B_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK0_LENGTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 triga_blk0_length : 16;
#else 
    Uint32 triga_blk0_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG;

/* trigger A block 0 window size (in number of samples), valid range 0~8191, bit [15:13] not in use. */
#define CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG_TRIGA_BLK0_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG_TRIGA_BLK0_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG_TRIGA_BLK0_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG_ADDR (0x000002F8u)
#define CSL_DFE_CB_TRIGA_BLK0_LENGTH_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK0_T1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 triga_blk0_t1 : 32;
#else 
    Uint32 triga_blk0_t1 : 32;
#endif 
} CSL_DFE_CB_TRIGA_BLK0_T1_REG;

/* trigger A block 0 threshold 1 (unsigned number) */
#define CSL_DFE_CB_TRIGA_BLK0_T1_REG_TRIGA_BLK0_T1_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_TRIGA_BLK0_T1_REG_TRIGA_BLK0_T1_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK0_T1_REG_TRIGA_BLK0_T1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK0_T1_REG_ADDR (0x000002FCu)
#define CSL_DFE_CB_TRIGA_BLK0_T1_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK0_T2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 triga_blk0_t2 : 16;
#else 
    Uint32 triga_blk0_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGA_BLK0_T2_REG;

/* trigger A block 0 threshold 2 (unsigned number) */
#define CSL_DFE_CB_TRIGA_BLK0_T2_REG_TRIGA_BLK0_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGA_BLK0_T2_REG_TRIGA_BLK0_T2_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK0_T2_REG_TRIGA_BLK0_T2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK0_T2_REG_ADDR (0x00000300u)
#define CSL_DFE_CB_TRIGA_BLK0_T2_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK1_LENGTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 triga_blk1_length : 16;
#else 
    Uint32 triga_blk1_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG;

/* trigger A block 1 window size (in number of samples), valid range 0~8191, bit [15:13] not in use. */
#define CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG_TRIGA_BLK1_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG_TRIGA_BLK1_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG_TRIGA_BLK1_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG_ADDR (0x00000304u)
#define CSL_DFE_CB_TRIGA_BLK1_LENGTH_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK1_T1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 triga_blk1_t1 : 32;
#else 
    Uint32 triga_blk1_t1 : 32;
#endif 
} CSL_DFE_CB_TRIGA_BLK1_T1_REG;

/* trigger A block 1 threshold 1 (unsigned number) */
#define CSL_DFE_CB_TRIGA_BLK1_T1_REG_TRIGA_BLK1_T1_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_TRIGA_BLK1_T1_REG_TRIGA_BLK1_T1_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK1_T1_REG_TRIGA_BLK1_T1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK1_T1_REG_ADDR (0x00000308u)
#define CSL_DFE_CB_TRIGA_BLK1_T1_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK1_T2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 triga_blk1_t2 : 16;
#else 
    Uint32 triga_blk1_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGA_BLK1_T2_REG;

/* trigger A block 1 threshold 2 (unsigned number) */
#define CSL_DFE_CB_TRIGA_BLK1_T2_REG_TRIGA_BLK1_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGA_BLK1_T2_REG_TRIGA_BLK1_T2_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK1_T2_REG_TRIGA_BLK1_T2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK1_T2_REG_ADDR (0x0000030Cu)
#define CSL_DFE_CB_TRIGA_BLK1_T2_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK0_LENGTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigb_blk0_length : 16;
#else 
    Uint32 trigb_blk0_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG;

/* trigger B block 0 window size (in number of samples), valid range 0~8191, bit [15:13] not in use. */
#define CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG_TRIGB_BLK0_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG_TRIGB_BLK0_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG_TRIGB_BLK0_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG_ADDR (0x00000310u)
#define CSL_DFE_CB_TRIGB_BLK0_LENGTH_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK0_T1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 trigb_blk0_t1 : 32;
#else 
    Uint32 trigb_blk0_t1 : 32;
#endif 
} CSL_DFE_CB_TRIGB_BLK0_T1_REG;

/* trigger B block 0 threshold 1 (unsigned number) */
#define CSL_DFE_CB_TRIGB_BLK0_T1_REG_TRIGB_BLK0_T1_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_TRIGB_BLK0_T1_REG_TRIGB_BLK0_T1_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK0_T1_REG_TRIGB_BLK0_T1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK0_T1_REG_ADDR (0x00000314u)
#define CSL_DFE_CB_TRIGB_BLK0_T1_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK0_T2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigb_blk0_t2 : 16;
#else 
    Uint32 trigb_blk0_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGB_BLK0_T2_REG;

/* trigger B block 0 threshold 2 (unsigned number) */
#define CSL_DFE_CB_TRIGB_BLK0_T2_REG_TRIGB_BLK0_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGB_BLK0_T2_REG_TRIGB_BLK0_T2_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK0_T2_REG_TRIGB_BLK0_T2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK0_T2_REG_ADDR (0x00000318u)
#define CSL_DFE_CB_TRIGB_BLK0_T2_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK1_LENGTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigb_blk1_length : 16;
#else 
    Uint32 trigb_blk1_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG;

/* trigger B block 1 window size (in number of samples), valid range 0~8191, bit [15:13] not in use. */
#define CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG_TRIGB_BLK1_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG_TRIGB_BLK1_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG_TRIGB_BLK1_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG_ADDR (0x0000031Cu)
#define CSL_DFE_CB_TRIGB_BLK1_LENGTH_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK1_T1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 trigb_blk1_t1 : 32;
#else 
    Uint32 trigb_blk1_t1 : 32;
#endif 
} CSL_DFE_CB_TRIGB_BLK1_T1_REG;

/* trigger B block 1 threshold 1 (unsigned number) */
#define CSL_DFE_CB_TRIGB_BLK1_T1_REG_TRIGB_BLK1_T1_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_TRIGB_BLK1_T1_REG_TRIGB_BLK1_T1_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK1_T1_REG_TRIGB_BLK1_T1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK1_T1_REG_ADDR (0x00000320u)
#define CSL_DFE_CB_TRIGB_BLK1_T1_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK1_T2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigb_blk1_t2 : 16;
#else 
    Uint32 trigb_blk1_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGB_BLK1_T2_REG;

/* trigger B block 1 threshold 2 (unsigned number) */
#define CSL_DFE_CB_TRIGB_BLK1_T2_REG_TRIGB_BLK1_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGB_BLK1_T2_REG_TRIGB_BLK1_T2_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK1_T2_REG_TRIGB_BLK1_T2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK1_T2_REG_ADDR (0x00000324u)
#define CSL_DFE_CB_TRIGB_BLK1_T2_REG_RESETVAL (0x00000000u)

/* TRIGGER_MONITOR_DECODER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigger_monitor_decoder : 16;
#else 
    Uint32 trigger_monitor_decoder : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG;

/* for decoding the output from the four trigger monitor blocks, the output from [trigb_blk1, trigb_blk0, triga_blk1, triga_blk0] will be used as 4-bit input address to this decoder, and the output is the bit specified by the 4-bit address. For example, if we program 'trigger_monitor_decoder' to 0x8000, that means the decoder output will be high only when the output from all four trigger monitor blocks are high, because only bit 15 is '1'. */
#define CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG_TRIGGER_MONITOR_DECODER_MASK (0x0000FFFFu)
#define CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG_TRIGGER_MONITOR_DECODER_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG_TRIGGER_MONITOR_DECODER_RESETVAL (0x0000FFFFu)

#define CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG_ADDR (0x00000328u)
#define CSL_DFE_CB_TRIGGER_MONITOR_DECODER_REG_RESETVAL (0x0000FFFFu)

/* GSG_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 gsg5_mode : 2;
    Uint32 gsg4_mode : 2;
    Uint32 gsg3_mode : 2;
    Uint32 gsg2_mode : 2;
    Uint32 gsg1_mode : 2;
    Uint32 gsg0_mode : 2;
#else 
    Uint32 gsg0_mode : 2;
    Uint32 gsg1_mode : 2;
    Uint32 gsg2_mode : 2;
    Uint32 gsg3_mode : 2;
    Uint32 gsg4_mode : 2;
    Uint32 gsg5_mode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_GSG_MODE_REG;

/* 0 = off */
#define CSL_DFE_CB_GSG_MODE_REG_GSG0_MODE_MASK (0x00000003u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG0_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG0_MODE_RESETVAL (0x00000000u)

/* same as gsg0_mode */
#define CSL_DFE_CB_GSG_MODE_REG_GSG1_MODE_MASK (0x0000000Cu)
#define CSL_DFE_CB_GSG_MODE_REG_GSG1_MODE_SHIFT (0x00000002u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG1_MODE_RESETVAL (0x00000000u)

/* same as gsg0_mode */
#define CSL_DFE_CB_GSG_MODE_REG_GSG2_MODE_MASK (0x00000030u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG2_MODE_SHIFT (0x00000004u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG2_MODE_RESETVAL (0x00000000u)

/* same as gsg0_mode */
#define CSL_DFE_CB_GSG_MODE_REG_GSG3_MODE_MASK (0x000000C0u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG3_MODE_SHIFT (0x00000006u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG3_MODE_RESETVAL (0x00000000u)

/* same as gsg0_mode */
#define CSL_DFE_CB_GSG_MODE_REG_GSG4_MODE_MASK (0x00000300u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG4_MODE_SHIFT (0x00000008u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG4_MODE_RESETVAL (0x00000000u)

/* same as gsg0_mode */
#define CSL_DFE_CB_GSG_MODE_REG_GSG5_MODE_MASK (0x00000C00u)
#define CSL_DFE_CB_GSG_MODE_REG_GSG5_MODE_SHIFT (0x0000000Au)
#define CSL_DFE_CB_GSG_MODE_REG_GSG5_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG_MODE_REG_ADDR (0x0000032Cu)
#define CSL_DFE_CB_GSG_MODE_REG_RESETVAL (0x00000000u)

/* GSG0_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_delayfromsync : 24;
#else 
    Uint32 gsg0_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG;

/* interval in samples from sync to start of first 'on' period  minus 1 sample */
#define CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG_GSG0_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG_GSG0_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG_GSG0_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG_ADDR (0x00000330u)
#define CSL_DFE_CB_GSG0_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG0_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_timer1 : 24;
#else 
    Uint32 gsg0_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_TIMER1_REG;

/* duration in samples of the first 'on' period */
#define CSL_DFE_CB_GSG0_TIMER1_REG_GSG0_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_TIMER1_REG_GSG0_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_TIMER1_REG_GSG0_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_TIMER1_REG_ADDR (0x00000334u)
#define CSL_DFE_CB_GSG0_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG0_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_timer2 : 24;
#else 
    Uint32 gsg0_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_TIMER2_REG;

/* off' duration in samples between the first 'on' period and the second 'on' period */
#define CSL_DFE_CB_GSG0_TIMER2_REG_GSG0_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_TIMER2_REG_GSG0_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_TIMER2_REG_GSG0_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_TIMER2_REG_ADDR (0x00000338u)
#define CSL_DFE_CB_GSG0_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG0_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_timer3 : 24;
#else 
    Uint32 gsg0_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_TIMER3_REG;

/* duration in samples of the second 'on' period */
#define CSL_DFE_CB_GSG0_TIMER3_REG_GSG0_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_TIMER3_REG_GSG0_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_TIMER3_REG_GSG0_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_TIMER3_REG_ADDR (0x0000033Cu)
#define CSL_DFE_CB_GSG0_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG0_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_timer4 : 24;
#else 
    Uint32 gsg0_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_TIMER4_REG;

/* off' duration in samples between the second 'on' period and the third 'on' period */
#define CSL_DFE_CB_GSG0_TIMER4_REG_GSG0_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_TIMER4_REG_GSG0_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_TIMER4_REG_GSG0_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_TIMER4_REG_ADDR (0x00000340u)
#define CSL_DFE_CB_GSG0_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG0_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg0_timer5 : 24;
#else 
    Uint32 gsg0_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG0_TIMER5_REG;

/* duration in samples of the third 'on' period */
#define CSL_DFE_CB_GSG0_TIMER5_REG_GSG0_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG0_TIMER5_REG_GSG0_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG0_TIMER5_REG_GSG0_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG0_TIMER5_REG_ADDR (0x00000344u)
#define CSL_DFE_CB_GSG0_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG1_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_delayfromsync : 24;
#else 
    Uint32 gsg1_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG;

/* same as gsg0_delayfromsync */
#define CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG_GSG1_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG_GSG1_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG_GSG1_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG_ADDR (0x00000348u)
#define CSL_DFE_CB_GSG1_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG1_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_timer1 : 24;
#else 
    Uint32 gsg1_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_TIMER1_REG;

/* same as gsg0_timer1 */
#define CSL_DFE_CB_GSG1_TIMER1_REG_GSG1_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_TIMER1_REG_GSG1_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_TIMER1_REG_GSG1_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_TIMER1_REG_ADDR (0x0000034Cu)
#define CSL_DFE_CB_GSG1_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG1_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_timer2 : 24;
#else 
    Uint32 gsg1_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_TIMER2_REG;

/* same as gsg0_timer2 */
#define CSL_DFE_CB_GSG1_TIMER2_REG_GSG1_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_TIMER2_REG_GSG1_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_TIMER2_REG_GSG1_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_TIMER2_REG_ADDR (0x00000350u)
#define CSL_DFE_CB_GSG1_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG1_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_timer3 : 24;
#else 
    Uint32 gsg1_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_TIMER3_REG;

/* same as gsg0_timer3 */
#define CSL_DFE_CB_GSG1_TIMER3_REG_GSG1_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_TIMER3_REG_GSG1_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_TIMER3_REG_GSG1_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_TIMER3_REG_ADDR (0x00000354u)
#define CSL_DFE_CB_GSG1_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG1_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_timer4 : 24;
#else 
    Uint32 gsg1_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_TIMER4_REG;

/* same as gsg0_timer4 */
#define CSL_DFE_CB_GSG1_TIMER4_REG_GSG1_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_TIMER4_REG_GSG1_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_TIMER4_REG_GSG1_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_TIMER4_REG_ADDR (0x00000358u)
#define CSL_DFE_CB_GSG1_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG1_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg1_timer5 : 24;
#else 
    Uint32 gsg1_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG1_TIMER5_REG;

/* same as gsg0_timer5 */
#define CSL_DFE_CB_GSG1_TIMER5_REG_GSG1_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG1_TIMER5_REG_GSG1_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG1_TIMER5_REG_GSG1_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG1_TIMER5_REG_ADDR (0x0000035Cu)
#define CSL_DFE_CB_GSG1_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG2_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_delayfromsync : 24;
#else 
    Uint32 gsg2_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG;

/* same as gsg0_delayfromsync */
#define CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG_GSG2_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG_GSG2_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG_GSG2_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG_ADDR (0x00000360u)
#define CSL_DFE_CB_GSG2_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG2_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_timer1 : 24;
#else 
    Uint32 gsg2_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_TIMER1_REG;

/* same as gsg0_timer1 */
#define CSL_DFE_CB_GSG2_TIMER1_REG_GSG2_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_TIMER1_REG_GSG2_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_TIMER1_REG_GSG2_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_TIMER1_REG_ADDR (0x00000364u)
#define CSL_DFE_CB_GSG2_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG2_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_timer2 : 24;
#else 
    Uint32 gsg2_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_TIMER2_REG;

/* same as gsg0_timer2 */
#define CSL_DFE_CB_GSG2_TIMER2_REG_GSG2_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_TIMER2_REG_GSG2_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_TIMER2_REG_GSG2_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_TIMER2_REG_ADDR (0x00000368u)
#define CSL_DFE_CB_GSG2_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG2_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_timer3 : 24;
#else 
    Uint32 gsg2_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_TIMER3_REG;

/* same as gsg0_timer3 */
#define CSL_DFE_CB_GSG2_TIMER3_REG_GSG2_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_TIMER3_REG_GSG2_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_TIMER3_REG_GSG2_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_TIMER3_REG_ADDR (0x0000036Cu)
#define CSL_DFE_CB_GSG2_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG2_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_timer4 : 24;
#else 
    Uint32 gsg2_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_TIMER4_REG;

/* same as gsg0_timer4 */
#define CSL_DFE_CB_GSG2_TIMER4_REG_GSG2_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_TIMER4_REG_GSG2_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_TIMER4_REG_GSG2_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_TIMER4_REG_ADDR (0x00000370u)
#define CSL_DFE_CB_GSG2_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG2_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg2_timer5 : 24;
#else 
    Uint32 gsg2_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG2_TIMER5_REG;

/* same as gsg0_timer5 */
#define CSL_DFE_CB_GSG2_TIMER5_REG_GSG2_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG2_TIMER5_REG_GSG2_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG2_TIMER5_REG_GSG2_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG2_TIMER5_REG_ADDR (0x00000374u)
#define CSL_DFE_CB_GSG2_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG3_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_delayfromsync : 24;
#else 
    Uint32 gsg3_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG;

/* same as gsg0_delayfromsync */
#define CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG_GSG3_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG_GSG3_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG_GSG3_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG_ADDR (0x00000378u)
#define CSL_DFE_CB_GSG3_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG3_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_timer1 : 24;
#else 
    Uint32 gsg3_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_TIMER1_REG;

/* same as gsg0_timer1 */
#define CSL_DFE_CB_GSG3_TIMER1_REG_GSG3_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_TIMER1_REG_GSG3_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_TIMER1_REG_GSG3_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_TIMER1_REG_ADDR (0x0000037Cu)
#define CSL_DFE_CB_GSG3_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG3_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_timer2 : 24;
#else 
    Uint32 gsg3_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_TIMER2_REG;

/* same as gsg0_timer2 */
#define CSL_DFE_CB_GSG3_TIMER2_REG_GSG3_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_TIMER2_REG_GSG3_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_TIMER2_REG_GSG3_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_TIMER2_REG_ADDR (0x00000380u)
#define CSL_DFE_CB_GSG3_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG3_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_timer3 : 24;
#else 
    Uint32 gsg3_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_TIMER3_REG;

/* same as gsg0_timer3 */
#define CSL_DFE_CB_GSG3_TIMER3_REG_GSG3_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_TIMER3_REG_GSG3_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_TIMER3_REG_GSG3_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_TIMER3_REG_ADDR (0x00000384u)
#define CSL_DFE_CB_GSG3_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG3_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_timer4 : 24;
#else 
    Uint32 gsg3_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_TIMER4_REG;

/* same as gsg0_timer4 */
#define CSL_DFE_CB_GSG3_TIMER4_REG_GSG3_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_TIMER4_REG_GSG3_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_TIMER4_REG_GSG3_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_TIMER4_REG_ADDR (0x00000388u)
#define CSL_DFE_CB_GSG3_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG3_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg3_timer5 : 24;
#else 
    Uint32 gsg3_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG3_TIMER5_REG;

/* same as gsg0_timer5 */
#define CSL_DFE_CB_GSG3_TIMER5_REG_GSG3_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG3_TIMER5_REG_GSG3_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG3_TIMER5_REG_GSG3_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG3_TIMER5_REG_ADDR (0x0000038Cu)
#define CSL_DFE_CB_GSG3_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG4_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_delayfromsync : 24;
#else 
    Uint32 gsg4_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG;

/* same as gsg0_delayfromsync */
#define CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG_GSG4_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG_GSG4_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG_GSG4_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG_ADDR (0x00000390u)
#define CSL_DFE_CB_GSG4_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG4_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_timer1 : 24;
#else 
    Uint32 gsg4_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_TIMER1_REG;

/* same as gsg0_timer1 */
#define CSL_DFE_CB_GSG4_TIMER1_REG_GSG4_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_TIMER1_REG_GSG4_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_TIMER1_REG_GSG4_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_TIMER1_REG_ADDR (0x00000394u)
#define CSL_DFE_CB_GSG4_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG4_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_timer2 : 24;
#else 
    Uint32 gsg4_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_TIMER2_REG;

/* same as gsg0_timer2 */
#define CSL_DFE_CB_GSG4_TIMER2_REG_GSG4_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_TIMER2_REG_GSG4_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_TIMER2_REG_GSG4_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_TIMER2_REG_ADDR (0x00000398u)
#define CSL_DFE_CB_GSG4_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG4_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_timer3 : 24;
#else 
    Uint32 gsg4_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_TIMER3_REG;

/* same as gsg0_timer3 */
#define CSL_DFE_CB_GSG4_TIMER3_REG_GSG4_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_TIMER3_REG_GSG4_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_TIMER3_REG_GSG4_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_TIMER3_REG_ADDR (0x0000039Cu)
#define CSL_DFE_CB_GSG4_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG4_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_timer4 : 24;
#else 
    Uint32 gsg4_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_TIMER4_REG;

/* same as gsg0_timer4 */
#define CSL_DFE_CB_GSG4_TIMER4_REG_GSG4_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_TIMER4_REG_GSG4_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_TIMER4_REG_GSG4_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_TIMER4_REG_ADDR (0x000003A0u)
#define CSL_DFE_CB_GSG4_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG4_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg4_timer5 : 24;
#else 
    Uint32 gsg4_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG4_TIMER5_REG;

/* same as gsg0_timer5 */
#define CSL_DFE_CB_GSG4_TIMER5_REG_GSG4_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG4_TIMER5_REG_GSG4_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG4_TIMER5_REG_GSG4_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG4_TIMER5_REG_ADDR (0x000003A4u)
#define CSL_DFE_CB_GSG4_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG5_DELAYFROMSYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_delayfromsync : 24;
#else 
    Uint32 gsg5_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG;

/* same as gsg0_delayfromsync */
#define CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG_GSG5_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG_GSG5_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG_GSG5_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG_ADDR (0x000003A8u)
#define CSL_DFE_CB_GSG5_DELAYFROMSYNC_REG_RESETVAL (0x00000000u)

/* GSG5_TIMER1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_timer1 : 24;
#else 
    Uint32 gsg5_timer1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_TIMER1_REG;

/* same as gsg0_timer1 */
#define CSL_DFE_CB_GSG5_TIMER1_REG_GSG5_TIMER1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_TIMER1_REG_GSG5_TIMER1_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_TIMER1_REG_GSG5_TIMER1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_TIMER1_REG_ADDR (0x000003ACu)
#define CSL_DFE_CB_GSG5_TIMER1_REG_RESETVAL (0x00000000u)

/* GSG5_TIMER2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_timer2 : 24;
#else 
    Uint32 gsg5_timer2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_TIMER2_REG;

/* same as gsg0_timer2 */
#define CSL_DFE_CB_GSG5_TIMER2_REG_GSG5_TIMER2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_TIMER2_REG_GSG5_TIMER2_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_TIMER2_REG_GSG5_TIMER2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_TIMER2_REG_ADDR (0x000003B0u)
#define CSL_DFE_CB_GSG5_TIMER2_REG_RESETVAL (0x00000000u)

/* GSG5_TIMER3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_timer3 : 24;
#else 
    Uint32 gsg5_timer3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_TIMER3_REG;

/* same as gsg0_timer3 */
#define CSL_DFE_CB_GSG5_TIMER3_REG_GSG5_TIMER3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_TIMER3_REG_GSG5_TIMER3_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_TIMER3_REG_GSG5_TIMER3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_TIMER3_REG_ADDR (0x000003B4u)
#define CSL_DFE_CB_GSG5_TIMER3_REG_RESETVAL (0x00000000u)

/* GSG5_TIMER4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_timer4 : 24;
#else 
    Uint32 gsg5_timer4 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_TIMER4_REG;

/* same as gsg0_timer4 */
#define CSL_DFE_CB_GSG5_TIMER4_REG_GSG5_TIMER4_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_TIMER4_REG_GSG5_TIMER4_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_TIMER4_REG_GSG5_TIMER4_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_TIMER4_REG_ADDR (0x000003B8u)
#define CSL_DFE_CB_GSG5_TIMER4_REG_RESETVAL (0x00000000u)

/* GSG5_TIMER5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_timer5 : 24;
#else 
    Uint32 gsg5_timer5 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG5_TIMER5_REG;

/* same as gsg0_timer5 */
#define CSL_DFE_CB_GSG5_TIMER5_REG_GSG5_TIMER5_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_GSG5_TIMER5_REG_GSG5_TIMER5_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG5_TIMER5_REG_GSG5_TIMER5_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG5_TIMER5_REG_ADDR (0x000003BCu)
#define CSL_DFE_CB_GSG5_TIMER5_REG_RESETVAL (0x00000000u)

/* GSG_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 gsg5_ssel : 4;
    Uint32 gsg4_ssel : 4;
    Uint32 gsg3_ssel : 4;
    Uint32 gsg2_ssel : 4;
    Uint32 gsg1_ssel : 4;
    Uint32 gsg0_ssel : 4;
#else 
    Uint32 gsg0_ssel : 4;
    Uint32 gsg1_ssel : 4;
    Uint32 gsg2_ssel : 4;
    Uint32 gsg3_ssel : 4;
    Uint32 gsg4_ssel : 4;
    Uint32 gsg5_ssel : 4;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_GSG_SSEL_REG;

/* gsg0 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG0_SSEL_RESETVAL (0x00000000u)

/* gsg1 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG1_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG1_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG1_SSEL_RESETVAL (0x00000000u)

/* gsg2 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG2_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG2_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG2_SSEL_RESETVAL (0x00000000u)

/* gsg3 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG3_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG3_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG3_SSEL_RESETVAL (0x00000000u)

/* gsg4 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG4_SSEL_MASK (0x000F0000u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG4_SSEL_SHIFT (0x00000010u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG4_SSEL_RESETVAL (0x00000000u)

/* gsg5 sync select */
#define CSL_DFE_CB_GSG_SSEL_REG_GSG5_SSEL_MASK (0x00F00000u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG5_SSEL_SHIFT (0x00000014u)
#define CSL_DFE_CB_GSG_SSEL_REG_GSG5_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG_SSEL_REG_ADDR (0x000003C4u)
#define CSL_DFE_CB_GSG_SSEL_REG_RESETVAL (0x00000000u)

/* GSG_SEQ_SEL_PART1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cb_f_fb_ant2_gsg_sel : 4;
    Uint32 cb_f_ref_ant2_gsg_sel : 4;
    Uint32 cb_f_fb_ant1_gsg_sel : 4;
    Uint32 cb_f_ref_ant1_gsg_sel : 4;
    Uint32 cb_f_fb_ant0_gsg_sel : 4;
    Uint32 cb_f_ref_ant0_gsg_sel : 4;
    Uint32 cb_c_fb_gsg_sel : 4;
    Uint32 cb_c_ref_gsg_sel : 4;
#else 
    Uint32 cb_c_ref_gsg_sel : 4;
    Uint32 cb_c_fb_gsg_sel : 4;
    Uint32 cb_f_ref_ant0_gsg_sel : 4;
    Uint32 cb_f_fb_ant0_gsg_sel : 4;
    Uint32 cb_f_ref_ant1_gsg_sel : 4;
    Uint32 cb_f_fb_ant1_gsg_sel : 4;
    Uint32 cb_f_ref_ant2_gsg_sel : 4;
    Uint32 cb_f_fb_ant2_gsg_sel : 4;
#endif 
} CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG;

/* gsg signal selection for CB-C capture of reference signal, bit [0]:  */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_REF_GSG_SEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_REF_GSG_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_REF_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_FB_GSG_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_FB_GSG_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_C_FB_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' (define this register per antenna such that we can quickly switch between four antennas for CB-F with out aid from DSP) */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT0_GSG_SEL_MASK (0x00000F00u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT0_GSG_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT0_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT0_GSG_SEL_MASK (0x0000F000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT0_GSG_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT0_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT1_GSG_SEL_MASK (0x000F0000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT1_GSG_SEL_SHIFT (0x00000010u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT1_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT1_GSG_SEL_MASK (0x00F00000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT1_GSG_SEL_SHIFT (0x00000014u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT1_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT2_GSG_SEL_MASK (0x0F000000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT2_GSG_SEL_SHIFT (0x00000018u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_REF_ANT2_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT2_GSG_SEL_MASK (0xF0000000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT2_GSG_SEL_SHIFT (0x0000001Cu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_CB_F_FB_ANT2_GSG_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_ADDR (0x000003C8u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART1_REG_RESETVAL (0x00000000u)

/* GSG_SEQ_SEL_PART2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 trigb_gsg_sel : 4;
    Uint32 triga_gsg_sel : 4;
    Uint32 cb_f_fb_ant3_gsg_sel : 4;
    Uint32 cb_f_ref_ant3_gsg_sel : 4;
#else 
    Uint32 cb_f_ref_ant3_gsg_sel : 4;
    Uint32 cb_f_fb_ant3_gsg_sel : 4;
    Uint32 triga_gsg_sel : 4;
    Uint32 trigb_gsg_sel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG;

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_REF_ANT3_GSG_SEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_REF_ANT3_GSG_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_REF_ANT3_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_FB_ANT3_GSG_SEL_MASK (0x000000F0u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_FB_ANT3_GSG_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_CB_F_FB_ANT3_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGA_GSG_SEL_MASK (0x00000F00u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGA_GSG_SEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGA_GSG_SEL_RESETVAL (0x00000000u)

/* similar to 'cba_gsg_sel' */
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGB_GSG_SEL_MASK (0x0000F000u)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGB_GSG_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_TRIGB_GSG_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_ADDR (0x000003CCu)
#define CSL_DFE_CB_GSG_SEQ_SEL_PART2_REG_RESETVAL (0x00000000u)

/* SILENT_DETECT_SETTING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 silent_detect_thresh : 24;
    Uint32 silent_detect_samples : 7;
    Uint32 silent_detect_en : 1;
#else 
    Uint32 silent_detect_en : 1;
    Uint32 silent_detect_samples : 7;
    Uint32 silent_detect_thresh : 24;
#endif 
} CSL_DFE_CB_SILENT_DETECT_SETTING_REG;

/* enable silent detection */
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_EN_MASK (0x00000001u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_EN_SHIFT (0x00000000u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_EN_RESETVAL (0x00000000u)

/* Number of continuous samples with mag_squared value below the threshold in a chunk to qualify 'silent period', 0~127. */
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_SAMPLES_MASK (0x000000FEu)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_SAMPLES_SHIFT (0x00000001u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_SAMPLES_RESETVAL (0x00000000u)

/* Unsigned value. Threshold to compare mag-squared of the complex signal to qualify silent period'. Mag-squared of signal (only take 16-MSB's) will be saturated to 24-bit before comparison. */
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_THRESH_MASK (0xFFFFFF00u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_THRESH_SHIFT (0x00000008u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_SILENT_DETECT_THRESH_RESETVAL (0x00000000u)

#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_ADDR (0x000003D0u)
#define CSL_DFE_CB_SILENT_DETECT_SETTING_REG_RESETVAL (0x00000000u)

/* CB_F_CHUNK_SELECTION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 ant3_criteria_disable : 3;
    Uint32 rsvd2 : 1;
    Uint32 ant2_criteria_disable : 3;
    Uint32 rsvd1 : 1;
    Uint32 ant1_criteria_disable : 3;
    Uint32 rsvd0 : 1;
    Uint32 ant0_criteria_disable : 3;
#else 
    Uint32 ant0_criteria_disable : 3;
    Uint32 rsvd0 : 1;
    Uint32 ant1_criteria_disable : 3;
    Uint32 rsvd1 : 1;
    Uint32 ant2_criteria_disable : 3;
    Uint32 rsvd2 : 1;
    Uint32 ant3_criteria_disable : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG;

/* bit[0] is to disable highest peak criteria, bit[1] is to disable RMS value criteria, bit [2] is to diable peak density (sum of 3 max peaks) criteria: 0 = enabled, 1= disabled. */
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT0_CRITERIA_DISABLE_MASK (0x00000007u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT0_CRITERIA_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT0_CRITERIA_DISABLE_RESETVAL (0x00000000u)

/* similar to ant1_criteria_disable */
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT1_CRITERIA_DISABLE_MASK (0x00000070u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT1_CRITERIA_DISABLE_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT1_CRITERIA_DISABLE_RESETVAL (0x00000000u)

/* similar to ant2_criteria_disable */
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT2_CRITERIA_DISABLE_MASK (0x00000700u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT2_CRITERIA_DISABLE_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT2_CRITERIA_DISABLE_RESETVAL (0x00000000u)

/* similar to ant3_criteria_disable */
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT3_CRITERIA_DISABLE_MASK (0x00007000u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT3_CRITERIA_DISABLE_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ANT3_CRITERIA_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_ADDR (0x000003D4u)
#define CSL_DFE_CB_CB_F_CHUNK_SELECTION_REG_RESETVAL (0x00000000u)

/* CB_F_BROKEN_CHAIN_DETECTION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 cb_f_ref_fb_powerratio : 4;
    Uint32 cb_f_powerth : 16;
#else 
    Uint32 cb_f_powerth : 16;
    Uint32 cb_f_ref_fb_powerratio : 4;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG;

/* unsigned value in (-1, 17) format. Threshold to compare the RMS power of the captured reference chunk. If reference chunk RMS value is greater than this threshold and (feedback chunk RMS * cb_f_ref_fb_powerRatio), the feedback chain will be considered broken. */
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_POWERTH_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_POWERTH_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_POWERTH_RESETVAL (0x00000000u)

/*  unsigned value in (4, 0), will be multiplied with feedback chunk RMS before compare to reference chunk RMS. */
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_REF_FB_POWERRATIO_MASK (0x000F0000u)
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_REF_FB_POWERRATIO_SHIFT (0x00000010u)
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_CB_F_REF_FB_POWERRATIO_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_ADDR (0x000003D8u)
#define CSL_DFE_CB_CB_F_BROKEN_CHAIN_DETECTION_REG_RESETVAL (0x00000000u)

/* CB_F_MAXREFPOWER_ANT0_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cb_f_maxrefpower_ant1 : 16;
    Uint32 cb_f_maxrefpower_ant0 : 16;
#else 
    Uint32 cb_f_maxrefpower_ant0 : 16;
    Uint32 cb_f_maxrefpower_ant1 : 16;
#endif 
} CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG;

/* Normalized block RMS power of the reference signal in (-1, 17) format. The position and duration of the block is defined by the corresponding GSG gating signal. This RMS power will be compared to the average power of captured reference chunks to determine the validity of this capture. */
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT0_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT0_RESETVAL (0x00000000u)

/* same as above, for antenna1.  */
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT1_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT1_SHIFT (0x00000010u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_CB_F_MAXREFPOWER_ANT1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_ADDR (0x000003DCu)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT0_1_REG_RESETVAL (0x00000000u)

/* CB_F_MAXREFPOWER_ANT2_3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cb_f_maxrefpower_ant3 : 16;
    Uint32 cb_f_maxrefpower_ant2 : 16;
#else 
    Uint32 cb_f_maxrefpower_ant2 : 16;
    Uint32 cb_f_maxrefpower_ant3 : 16;
#endif 
} CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG;

/* same as above, for antenna2.  */
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT2_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT2_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT2_RESETVAL (0x00000000u)

/* same as above, for antenna3.  */
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT3_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT3_SHIFT (0x00000010u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_CB_F_MAXREFPOWER_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_ADDR (0x000003E0u)
#define CSL_DFE_CB_CB_F_MAXREFPOWER_ANT2_3_REG_RESETVAL (0x00000000u)

/* CB_F_DELTAPOWERINLINEAR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 2;
    Uint32 cb_f_deltapower_ant3 : 6;
    Uint32 rsvd2 : 2;
    Uint32 cb_f_deltapower_ant2 : 6;
    Uint32 rsvd1 : 2;
    Uint32 cb_f_deltapower_ant1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cb_f_deltapower_ant0 : 6;
#else 
    Uint32 cb_f_deltapower_ant0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cb_f_deltapower_ant1 : 6;
    Uint32 rsvd1 : 2;
    Uint32 cb_f_deltapower_ant2 : 6;
    Uint32 rsvd2 : 2;
    Uint32 cb_f_deltapower_ant3 : 6;
    Uint32 rsvd3 : 2;
#endif 
} CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG;

/* unsigned value in (0, 6). The meaured block RMS power of the reference signal for antenna0, i.e. cb_f_MaxRefPower_ant0, will be multiplied with 'cb_f_deltaPower_ant0' to get a dynamic threshold, which will be compared with average power of all captured reference chunks for antenna0 to check for 'bad buffer' condition. */
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT0_MASK (0x0000003Fu)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT0_RESETVAL (0x00000001u)

/* same as 'cb_f_deltaPower_ant0', for antenna1 */
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT1_MASK (0x00003F00u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT1_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT1_RESETVAL (0x00000001u)

/* same as 'cb_f_deltaPower_ant0', for antenna2 */
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT2_MASK (0x003F0000u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT2_SHIFT (0x00000010u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT2_RESETVAL (0x00000001u)

/* same as 'cb_f_deltaPower_ant0', for antenna3 */
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT3_MASK (0x3F000000u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT3_SHIFT (0x00000018u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_CB_F_DELTAPOWER_ANT3_RESETVAL (0x00000001u)

#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_ADDR (0x000003E4u)
#define CSL_DFE_CB_CB_F_DELTAPOWERINLINEAR_REG_RESETVAL (0x01010101u)

/* CB_F_BADBUFFER_DETECTION_EN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 bad_buffer_detection_en_ant3 : 1;
    Uint32 bad_buffer_detection_en_ant2 : 1;
    Uint32 bad_buffer_detection_en_ant1 : 1;
    Uint32 bad_buffer_detection_en_ant0 : 1;
#else 
    Uint32 bad_buffer_detection_en_ant0 : 1;
    Uint32 bad_buffer_detection_en_ant1 : 1;
    Uint32 bad_buffer_detection_en_ant2 : 1;
    Uint32 bad_buffer_detection_en_ant3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG;

/* To enable bad buffer detection for antenna 0 */
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT0_MASK (0x00000001u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT0_RESETVAL (0x00000000u)

/* To enable bad buffer detection for antenna 1 */
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT1_MASK (0x00000002u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT1_SHIFT (0x00000001u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT1_RESETVAL (0x00000000u)

/* To enable bad buffer detection for antenna 2 */
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT2_MASK (0x00000004u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT2_SHIFT (0x00000002u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT2_RESETVAL (0x00000000u)

/* To enable bad buffer detection for antenna 3 */
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT3_MASK (0x00000008u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT3_SHIFT (0x00000003u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_BAD_BUFFER_DETECTION_EN_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_ADDR (0x000003E8u)
#define CSL_DFE_CB_CB_F_BADBUFFER_DETECTION_EN_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_SYNC_DLY_ANT0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_sync_dly_ant0 : 24;
#else 
    Uint32 power_monitor_sync_dly_ant0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG;

/* Delay of the start of power integration after sync event for antenna0 (in samples) */
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG_POWER_MONITOR_SYNC_DLY_ANT0_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG_POWER_MONITOR_SYNC_DLY_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG_POWER_MONITOR_SYNC_DLY_ANT0_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG_ADDR (0x000003ECu)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT0_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_SYNC_DLY_ANT1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_sync_dly_ant1 : 24;
#else 
    Uint32 power_monitor_sync_dly_ant1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG;

/* Delay of the start of power integration after sync event for antenna1(in samples) */
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG_POWER_MONITOR_SYNC_DLY_ANT1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG_POWER_MONITOR_SYNC_DLY_ANT1_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG_POWER_MONITOR_SYNC_DLY_ANT1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG_ADDR (0x000003F0u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT1_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_SYNC_DLY_ANT2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_sync_dly_ant2 : 24;
#else 
    Uint32 power_monitor_sync_dly_ant2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG;

/* Delay of the start of power integration after sync event for antenna2 (in samples) */
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG_POWER_MONITOR_SYNC_DLY_ANT2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG_POWER_MONITOR_SYNC_DLY_ANT2_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG_POWER_MONITOR_SYNC_DLY_ANT2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG_ADDR (0x000003F4u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT2_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_SYNC_DLY_ANT3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_sync_dly_ant3 : 24;
#else 
    Uint32 power_monitor_sync_dly_ant3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG;

/* Delay of the start of power integration after sync event for antenna3 (in samples) */
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG_POWER_MONITOR_SYNC_DLY_ANT3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG_POWER_MONITOR_SYNC_DLY_ANT3_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG_POWER_MONITOR_SYNC_DLY_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG_ADDR (0x000003F8u)
#define CSL_DFE_CB_POWER_MONITOR_SYNC_DLY_ANT3_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_INTG_PD_ANT0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_intg_pd_ant0 : 24;
#else 
    Uint32 power_monitor_intg_pd_ant0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG;

/* Power integration time in samples for antenna0, must be power of 2 to simplify normalization after power measurement is done. */
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG_POWER_MONITOR_INTG_PD_ANT0_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG_POWER_MONITOR_INTG_PD_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG_POWER_MONITOR_INTG_PD_ANT0_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG_ADDR (0x000003FCu)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT0_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_INTG_PD_ANT1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_intg_pd_ant1 : 24;
#else 
    Uint32 power_monitor_intg_pd_ant1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG;

/* same as 'power_monitor_intg_pd_ant0', for antenna1 */
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG_POWER_MONITOR_INTG_PD_ANT1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG_POWER_MONITOR_INTG_PD_ANT1_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG_POWER_MONITOR_INTG_PD_ANT1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG_ADDR (0x00000400u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT1_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_INTG_PD_ANT2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_intg_pd_ant2 : 24;
#else 
    Uint32 power_monitor_intg_pd_ant2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG;

/* same as 'power_monitor_intg_pd_ant0', for antenna2 */
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG_POWER_MONITOR_INTG_PD_ANT2_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG_POWER_MONITOR_INTG_PD_ANT2_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG_POWER_MONITOR_INTG_PD_ANT2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG_ADDR (0x00000404u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT2_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_INTG_PD_ANT3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 power_monitor_intg_pd_ant3 : 24;
#else 
    Uint32 power_monitor_intg_pd_ant3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG;

/* same as 'power_monitor_intg_pd_ant0', for antenna3 */
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG_POWER_MONITOR_INTG_PD_ANT3_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG_POWER_MONITOR_INTG_PD_ANT3_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG_POWER_MONITOR_INTG_PD_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG_ADDR (0x00000408u)
#define CSL_DFE_CB_POWER_MONITOR_INTG_PD_ANT3_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_CONFIG_ANT0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 9;
    Uint32 power_monitor_ant0_q0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant0_i0fsdly : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant0_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant0_i0bus_sel : 3;
#else 
    Uint32 power_monitor_ant0_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant0_q0bus_sel : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant0_i0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant0_q0fsdly : 3;
    Uint32 rsvd3 : 9;
#endif 
} CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_POWER_MONITOR_ANT0_Q0FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_ADDR (0x0000040Cu)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT0_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_ANT0_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 power_monitor_ant0_fsfm : 2;
    Uint32 power_monitor_ant0_fsf : 2;
#else 
    Uint32 power_monitor_ant0_fsf : 2;
    Uint32 power_monitor_ant0_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_POWER_MONITOR_ANT0_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_ADDR (0x00000410u)
#define CSL_DFE_CB_POWER_MONITOR_ANT0_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_CONFIG_ANT1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 9;
    Uint32 power_monitor_ant1_q0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant1_i0fsdly : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant1_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant1_i0bus_sel : 3;
#else 
    Uint32 power_monitor_ant1_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant1_q0bus_sel : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant1_i0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant1_q0fsdly : 3;
    Uint32 rsvd3 : 9;
#endif 
} CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_POWER_MONITOR_ANT1_Q0FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_ADDR (0x00000414u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT1_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_ANT1_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 power_monitor_ant1_fsfm : 2;
    Uint32 power_monitor_ant1_fsf : 2;
#else 
    Uint32 power_monitor_ant1_fsf : 2;
    Uint32 power_monitor_ant1_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_POWER_MONITOR_ANT1_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_ADDR (0x00000418u)
#define CSL_DFE_CB_POWER_MONITOR_ANT1_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_CONFIG_ANT2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 9;
    Uint32 power_monitor_ant2_q0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant2_i0fsdly : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant2_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant2_i0bus_sel : 3;
#else 
    Uint32 power_monitor_ant2_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant2_q0bus_sel : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant2_i0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant2_q0fsdly : 3;
    Uint32 rsvd3 : 9;
#endif 
} CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_POWER_MONITOR_ANT2_Q0FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_ADDR (0x0000041Cu)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT2_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_ANT2_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 power_monitor_ant2_fsfm : 2;
    Uint32 power_monitor_ant2_fsf : 2;
#else 
    Uint32 power_monitor_ant2_fsf : 2;
    Uint32 power_monitor_ant2_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_POWER_MONITOR_ANT2_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_ADDR (0x00000420u)
#define CSL_DFE_CB_POWER_MONITOR_ANT2_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_CONFIG_ANT3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 9;
    Uint32 power_monitor_ant3_q0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant3_i0fsdly : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant3_q0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant3_i0bus_sel : 3;
#else 
    Uint32 power_monitor_ant3_i0bus_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 power_monitor_ant3_q0bus_sel : 3;
    Uint32 rsvd1 : 9;
    Uint32 power_monitor_ant3_i0fsdly : 3;
    Uint32 rsvd2 : 1;
    Uint32 power_monitor_ant3_q0fsdly : 3;
    Uint32 rsvd3 : 9;
#endif 
} CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0BUS_SEL_MASK (0x00000007u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0BUS_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0BUS_SEL_MASK (0x00000070u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0BUS_SEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0BUS_SEL_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0FSDLY_MASK (0x00070000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0FSDLY_SHIFT (0x00000010u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_I0FSDLY_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0FSDLY_MASK (0x00700000u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0FSDLY_SHIFT (0x00000014u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_POWER_MONITOR_ANT3_Q0FSDLY_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_ADDR (0x00000424u)
#define CSL_DFE_CB_POWER_MONITOR_CONFIG_ANT3_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_ANT3_FSF_FSFM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 power_monitor_ant3_fsfm : 2;
    Uint32 power_monitor_ant3_fsf : 2;
#else 
    Uint32 power_monitor_ant3_fsf : 2;
    Uint32 power_monitor_ant3_fsfm : 2;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG;

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSF_MASK (0x00000003u)
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSF_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSF_RESETVAL (0x00000000u)

/* see definition of corresponding register for node0. */
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSFM_MASK (0x0000000Cu)
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSFM_SHIFT (0x00000002u)
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_POWER_MONITOR_ANT3_FSFM_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_ADDR (0x00000428u)
#define CSL_DFE_CB_POWER_MONITOR_ANT3_FSF_FSFM_REG_RESETVAL (0x00000000u)

/* POWER_MONITOR_NODE_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 power_monitor_sel : 4;
#else 
    Uint32 power_monitor_sel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG;

/* node selection for power monitor, refer to 'cba_sel' for definition of capture nodes. */
#define CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG_POWER_MONITOR_SEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG_POWER_MONITOR_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG_POWER_MONITOR_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG_ADDR (0x0000042Cu)
#define CSL_DFE_CB_POWER_MONITOR_NODE_SEL_REG_RESETVAL (0x00000000u)

/* CB_SOURCING_CONTROL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 7;
    Uint32 cb_sc_repeat : 1;
    Uint32 rsvd1 : 1;
    Uint32 cb_sc_size : 15;
    Uint32 rsvd0 : 2;
    Uint32 cb_sc_fsl : 6;
#else 
    Uint32 cb_sc_fsl : 6;
    Uint32 rsvd0 : 2;
    Uint32 cb_sc_size : 15;
    Uint32 rsvd1 : 1;
    Uint32 cb_sc_repeat : 1;
    Uint32 rsvd2 : 7;
#endif 
} CSL_DFE_CB_CB_SOURCING_CONTROL_REG;

/* source mode frame length; values are 0 to 63 clock cycles ,i.e. frame length minus 1 */
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_FSL_MASK (0x0000003Fu)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_FSL_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_FSL_RESETVAL (0x00000000u)

/* number of data to be sourced minus 1; Max 32768 complex samples (in I/Q interleaved mode, max is 16384 complex samples) . Note that since each capture buffer is of size 8k, we need to concatenate capture buffer A and B if the soucing size is between 8k~16k. We need to concatenate capture buffer A, B, C if the sourcing size is between 16k and 24k and we need to concatenate all four capture buffers if sourcing size is between 24k~32k. The user need to program the corresponding buffers to 'sourcing mode'.  */
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_SIZE_MASK (0x007FFF00u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_SIZE_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_SIZE_RESETVAL (0x00000000u)

/* repeat source data: 1: repeat; 0: source data once */
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_REPEAT_MASK (0x01000000u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_REPEAT_SHIFT (0x00000018u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_CB_SC_REPEAT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_ADDR (0x00000430u)
#define CSL_DFE_CB_CB_SOURCING_CONTROL_REG_RESETVAL (0x00000000u)

/* CB_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 time_step : 32;
#else 
    Uint32 time_step : 32;
#endif 
} CSL_DFE_CB_CB_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^31)/time_step clocks. Put another way: multiplies the clock rate by ((2^31)-time_step)/(2^31). */
#define CSL_DFE_CB_CB_TIME_STEP_REG_TIME_STEP_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CB_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TIME_STEP_REG_ADDR (0x00000434u)
#define CSL_DFE_CB_CB_TIME_STEP_REG_RESETVAL (0x00000000u)

/* CB_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 reset_int : 32;
#else 
    Uint32 reset_int : 32;
#endif 
} CSL_DFE_CB_CB_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_CB_CB_RESET_INT_REG_RESET_INT_MASK (0xFFFFFFFFu)
#define CSL_DFE_CB_CB_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_RESET_INT_REG_ADDR (0x00000438u)
#define CSL_DFE_CB_CB_RESET_INT_REG_RESETVAL (0x00000000u)

/* CB_TDD_PERIOD */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_period : 24;
#else 
    Uint32 tdd_period : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_TDD_PERIOD_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_CB_CB_TDD_PERIOD_REG_TDD_PERIOD_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_TDD_PERIOD_REG_TDD_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TDD_PERIOD_REG_TDD_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TDD_PERIOD_REG_ADDR (0x0000043Cu)
#define CSL_DFE_CB_CB_TDD_PERIOD_REG_RESETVAL (0x00000000u)

/* CB_TDD_ON_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_0 : 24;
#else 
    Uint32 tdd_on_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_TDD_ON_0_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_CB_CB_TDD_ON_0_REG_TDD_ON_0_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_TDD_ON_0_REG_TDD_ON_0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TDD_ON_0_REG_TDD_ON_0_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TDD_ON_0_REG_ADDR (0x00000440u)
#define CSL_DFE_CB_CB_TDD_ON_0_REG_RESETVAL (0x00000000u)

/* CB_TDD_OFF_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_0 : 24;
#else 
    Uint32 tdd_off_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_TDD_OFF_0_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_CB_CB_TDD_OFF_0_REG_TDD_OFF_0_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_TDD_OFF_0_REG_TDD_OFF_0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TDD_OFF_0_REG_TDD_OFF_0_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TDD_OFF_0_REG_ADDR (0x00000444u)
#define CSL_DFE_CB_CB_TDD_OFF_0_REG_RESETVAL (0x00000000u)

/* CB_TDD_ON_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_1 : 24;
#else 
    Uint32 tdd_on_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_TDD_ON_1_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_CB_CB_TDD_ON_1_REG_TDD_ON_1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_TDD_ON_1_REG_TDD_ON_1_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TDD_ON_1_REG_TDD_ON_1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TDD_ON_1_REG_ADDR (0x00000448u)
#define CSL_DFE_CB_CB_TDD_ON_1_REG_RESETVAL (0x00000000u)

/* CB_TDD_OFF_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_1 : 24;
#else 
    Uint32 tdd_off_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CB_CB_TDD_OFF_1_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_CB_CB_TDD_OFF_1_REG_TDD_OFF_1_MASK (0x00FFFFFFu)
#define CSL_DFE_CB_CB_TDD_OFF_1_REG_TDD_OFF_1_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_TDD_OFF_1_REG_TDD_OFF_1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_TDD_OFF_1_REG_ADDR (0x0000044Cu)
#define CSL_DFE_CB_CB_TDD_OFF_1_REG_RESETVAL (0x00000000u)

/* INITS */
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
} CSL_DFE_CB_INITS_REG;

/* sync select for 'init_state' */
#define CSL_DFE_CB_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* for init_clk_gate */
#define CSL_DFE_CB_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_CB_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_CB_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* for init_state */
#define CSL_DFE_CB_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_CB_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_CB_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* for clear_data */
#define CSL_DFE_CB_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_CB_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_CB_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_CB_INITS_REG_ADDR (0x00000450u)
#define CSL_DFE_CB_INITS_REG_RESETVAL (0x00000070u)

/* CB_SYNC_SELECT_PART1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cb_f_powermonitor_ssel : 4;
    Uint32 cb_source_ssel : 4;
    Uint32 cb_f_start_ssel : 4;
    Uint32 cb_c_start_ssel : 4;
#else 
    Uint32 cb_c_start_ssel : 4;
    Uint32 cb_f_start_ssel : 4;
    Uint32 cb_source_ssel : 4;
    Uint32 cb_f_powermonitor_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG;

/* coarse capture buffer start sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_C_START_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_C_START_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_C_START_SSEL_RESETVAL (0x00000000u)

/* fine capture buffer start sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_START_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_START_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_START_SSEL_RESETVAL (0x00000000u)

/* capture buffer source mode sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_SOURCE_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_SOURCE_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_SOURCE_SSEL_RESETVAL (0x00000000u)

/* sync select for CB-F power monitor in order to get MaxRefPwr */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_POWERMONITOR_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_POWERMONITOR_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_CB_F_POWERMONITOR_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_ADDR (0x00000454u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART1_REG_RESETVAL (0x00000000u)

/* CB_SYNC_SELECT_PART2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cbd_frac_cnt_ssel : 4;
    Uint32 cbc_frac_cnt_ssel : 4;
    Uint32 cbb_frac_cnt_ssel : 4;
    Uint32 cba_frac_cnt_ssel : 4;
#else 
    Uint32 cba_frac_cnt_ssel : 4;
    Uint32 cbb_frac_cnt_ssel : 4;
    Uint32 cbc_frac_cnt_ssel : 4;
    Uint32 cbd_frac_cnt_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG;

/* cba fractional counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBA_FRAC_CNT_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBA_FRAC_CNT_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBA_FRAC_CNT_SSEL_RESETVAL (0x00000000u)

/* cbb fractional counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBB_FRAC_CNT_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBB_FRAC_CNT_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBB_FRAC_CNT_SSEL_RESETVAL (0x00000000u)

/* cbc fractional counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBC_FRAC_CNT_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBC_FRAC_CNT_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBC_FRAC_CNT_SSEL_RESETVAL (0x00000000u)

/* cbd fractional counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBD_FRAC_CNT_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBD_FRAC_CNT_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_CBD_FRAC_CNT_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_ADDR (0x00000458u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART2_REG_RESETVAL (0x00000000u)

/* CB_SYNC_SELECT_PART3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cbd_len_cnt_ssel : 4;
    Uint32 cbc_len_cnt_ssel : 4;
    Uint32 cbb_len_cnt_ssel : 4;
    Uint32 cba_len_cnt_ssel : 4;
#else 
    Uint32 cba_len_cnt_ssel : 4;
    Uint32 cbb_len_cnt_ssel : 4;
    Uint32 cbc_len_cnt_ssel : 4;
    Uint32 cbd_len_cnt_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG;

/* cba length counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBA_LEN_CNT_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBA_LEN_CNT_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBA_LEN_CNT_SSEL_RESETVAL (0x00000000u)

/* cbb length counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBB_LEN_CNT_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBB_LEN_CNT_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBB_LEN_CNT_SSEL_RESETVAL (0x00000000u)

/* cbc length counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBC_LEN_CNT_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBC_LEN_CNT_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBC_LEN_CNT_SSEL_RESETVAL (0x00000000u)

/* cbd length counter sync select */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBD_LEN_CNT_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBD_LEN_CNT_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_CBD_LEN_CNT_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_ADDR (0x0000045Cu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART3_REG_RESETVAL (0x00000000u)

/* CB_SRC_NODE_CONTROL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cb_src_dduc_to_bb : 1;
    Uint32 cb_src_fb_to_dduc : 1;
    Uint32 cb_src_rx_to_dduc : 1;
    Uint32 cb_src_jesd_to_fb : 1;
    Uint32 cb_src_jesd_to_rx : 1;
    Uint32 cb_src_tx_to_jesd : 1;
    Uint32 cb_src_dpd_to_tx : 1;
    Uint32 cb_src_cdfr_to_dpd : 1;
    Uint32 cb_src_sum_to_cfr : 1;
    Uint32 cb_src_bb_to_dduc : 1;
#else 
    Uint32 cb_src_bb_to_dduc : 1;
    Uint32 cb_src_sum_to_cfr : 1;
    Uint32 cb_src_cdfr_to_dpd : 1;
    Uint32 cb_src_dpd_to_tx : 1;
    Uint32 cb_src_tx_to_jesd : 1;
    Uint32 cb_src_jesd_to_rx : 1;
    Uint32 cb_src_jesd_to_fb : 1;
    Uint32 cb_src_rx_to_dduc : 1;
    Uint32 cb_src_fb_to_dduc : 1;
    Uint32 cb_src_dduc_to_bb : 1;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG;

/* determine whether we want to source into a spcific node: */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_BB_TO_DDUC_MASK (0x00000001u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_BB_TO_DDUC_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_BB_TO_DDUC_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_SUM_TO_CFR_MASK (0x00000002u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_SUM_TO_CFR_SHIFT (0x00000001u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_SUM_TO_CFR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_CDFR_TO_DPD_MASK (0x00000004u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_CDFR_TO_DPD_SHIFT (0x00000002u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_CDFR_TO_DPD_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DPD_TO_TX_MASK (0x00000008u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DPD_TO_TX_SHIFT (0x00000003u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DPD_TO_TX_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_TX_TO_JESD_MASK (0x00000010u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_TX_TO_JESD_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_TX_TO_JESD_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_RX_MASK (0x00000020u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_RX_SHIFT (0x00000005u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_RX_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_FB_MASK (0x00000040u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_FB_SHIFT (0x00000006u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_JESD_TO_FB_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_RX_TO_DDUC_MASK (0x00000080u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_RX_TO_DDUC_SHIFT (0x00000007u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_RX_TO_DDUC_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_FB_TO_DDUC_MASK (0x00000100u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_FB_TO_DDUC_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_FB_TO_DDUC_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DDUC_TO_BB_MASK (0x00000200u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DDUC_TO_BB_SHIFT (0x00000009u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_CB_SRC_DDUC_TO_BB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_ADDR (0x00000460u)
#define CSL_DFE_CB_CB_SRC_NODE_CONTROL_REG_RESETVAL (0x00000000u)

/* BUFFER_FULL_FLAG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 cbd_full : 1;
    Uint32 cbc_full : 1;
    Uint32 cbb_full : 1;
    Uint32 cba_full : 1;
#else 
    Uint32 cba_full : 1;
    Uint32 cbb_full : 1;
    Uint32 cbc_full : 1;
    Uint32 cbd_full : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_CB_BUFFER_FULL_FLAG_REG;

/* The bit will be set to '1' once buffer A is filled with valid data. It will be reset to '0' once cb_c restarts. This buffer is mainly for smart capture mode, especially when 'trig_blk_length' is smaller than buffer size, it is possible that a 'stop capture' is captured before the buffer is filled up with valid data. */
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBA_FULL_MASK (0x00000001u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBA_FULL_SHIFT (0x00000000u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBA_FULL_RESETVAL (0x00000000u)

/* same as cba_full. */
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBB_FULL_MASK (0x00000002u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBB_FULL_SHIFT (0x00000001u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBB_FULL_RESETVAL (0x00000000u)

/* same as cba_full. */
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBC_FULL_MASK (0x00000004u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBC_FULL_SHIFT (0x00000002u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBC_FULL_RESETVAL (0x00000000u)

/* same as cba_full. */
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBD_FULL_MASK (0x00000008u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBD_FULL_SHIFT (0x00000003u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_CBD_FULL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_ADDR (0x00000464u)
#define CSL_DFE_CB_BUFFER_FULL_FLAG_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK0_OUTPWR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 3;
    Uint32 triga_blk0_outpwr : 29;
#else 
    Uint32 triga_blk0_outpwr : 29;
    Uint32 rsvd0 : 3;
#endif 
} CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG;

/* At the end of blk length, triga blk0 will report the average power of this block. How to interprete this value would also depend on setting of trga_blk0, e.g. triga_blk0_MagSqd_sel, triga_blk0_IOC and the threshold T1. Typical setting would be triga_blk0_length = 8191, triga_blk0_MagSqd_sel = 1, triga_blk0_IOC=1 and triga_blk0_T1=0. */
#define CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG_TRIGA_BLK0_OUTPWR_MASK (0x1FFFFFFFu)
#define CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG_TRIGA_BLK0_OUTPWR_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG_TRIGA_BLK0_OUTPWR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG_ADDR (0x00000468u)
#define CSL_DFE_CB_TRIGA_BLK0_OUTPWR_REG_RESETVAL (0x00000000u)

/* TRIGA_BLK1_OUTPWR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 3;
    Uint32 triga_blk1_outpwr : 29;
#else 
    Uint32 triga_blk1_outpwr : 29;
    Uint32 rsvd0 : 3;
#endif 
} CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG;

/* similar to triga_blk0_outpwr */
#define CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG_TRIGA_BLK1_OUTPWR_MASK (0x1FFFFFFFu)
#define CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG_TRIGA_BLK1_OUTPWR_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG_TRIGA_BLK1_OUTPWR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG_ADDR (0x0000046Cu)
#define CSL_DFE_CB_TRIGA_BLK1_OUTPWR_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK0_OUTPWR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 3;
    Uint32 trigb_blk0_outpwr : 29;
#else 
    Uint32 trigb_blk0_outpwr : 29;
    Uint32 rsvd0 : 3;
#endif 
} CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG;

/* similar to triga_blk0_outpwr */
#define CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG_TRIGB_BLK0_OUTPWR_MASK (0x1FFFFFFFu)
#define CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG_TRIGB_BLK0_OUTPWR_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG_TRIGB_BLK0_OUTPWR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG_ADDR (0x00000470u)
#define CSL_DFE_CB_TRIGB_BLK0_OUTPWR_REG_RESETVAL (0x00000000u)

/* TRIGB_BLK1_OUTPWR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 3;
    Uint32 trigb_blk1_outpwr : 29;
#else 
    Uint32 trigb_blk1_outpwr : 29;
    Uint32 rsvd0 : 3;
#endif 
} CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG;

/* similar to triga_blk0_outpwr */
#define CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG_TRIGB_BLK1_OUTPWR_MASK (0x1FFFFFFFu)
#define CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG_TRIGB_BLK1_OUTPWR_SHIFT (0x00000000u)
#define CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG_TRIGB_BLK1_OUTPWR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG_ADDR (0x00000474u)
#define CSL_DFE_CB_TRIGB_BLK1_OUTPWR_REG_RESETVAL (0x00000000u)

/* CB_REF_FB_LATENCY_ANT0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ref_fb_latency_ant0 : 12;
#else 
    Uint32 ref_fb_latency_ant0 : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG;

/* 0~4095, specify the latency (in reference samples) between reference signal and the feedback signal such that we can start the capture of refrence signal and capture of feedback signal at different time. This is important when arbiter is controlling capture buffer. */
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG_REF_FB_LATENCY_ANT0_MASK (0x00000FFFu)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG_REF_FB_LATENCY_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG_REF_FB_LATENCY_ANT0_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG_ADDR (0x00000478u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT0_REG_RESETVAL (0x00000000u)

/* CB_REF_FB_LATENCY_ANT1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ref_fb_latency_ant1 : 12;
#else 
    Uint32 ref_fb_latency_ant1 : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG;

/* same as above */
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG_REF_FB_LATENCY_ANT1_MASK (0x00000FFFu)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG_REF_FB_LATENCY_ANT1_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG_REF_FB_LATENCY_ANT1_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG_ADDR (0x0000047Cu)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT1_REG_RESETVAL (0x00000000u)

/* CB_REF_FB_LATENCY_ANT2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ref_fb_latency_ant2 : 12;
#else 
    Uint32 ref_fb_latency_ant2 : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG;

/* same as above */
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG_REF_FB_LATENCY_ANT2_MASK (0x00000FFFu)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG_REF_FB_LATENCY_ANT2_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG_REF_FB_LATENCY_ANT2_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG_ADDR (0x00000480u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT2_REG_RESETVAL (0x00000000u)

/* CB_REF_FB_LATENCY_ANT3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ref_fb_latency_ant3 : 12;
#else 
    Uint32 ref_fb_latency_ant3 : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG;

/* same as above */
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG_REF_FB_LATENCY_ANT3_MASK (0x00000FFFu)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG_REF_FB_LATENCY_ANT3_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG_REF_FB_LATENCY_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG_ADDR (0x00000484u)
#define CSL_DFE_CB_CB_REF_FB_LATENCY_ANT3_REG_RESETVAL (0x00000000u)

/* CB_SYNC_SELECT_PART4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cb_f_powermonitor_ant3_ssel : 4;
    Uint32 cb_f_powermonitor_ant2_ssel : 4;
    Uint32 cb_f_powermonitor_ant1_ssel : 4;
    Uint32 cb_f_powermonitor_ant0_ssel : 4;
#else 
    Uint32 cb_f_powermonitor_ant0_ssel : 4;
    Uint32 cb_f_powermonitor_ant1_ssel : 4;
    Uint32 cb_f_powermonitor_ant2_ssel : 4;
    Uint32 cb_f_powermonitor_ant3_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG;

/* sync select for CB-F power monitor in order to get MaxRefPwr for antenna 0 */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT0_SSEL_RESETVAL (0x00000000u)

/* sync select for CB-F power monitor in order to get MaxRefPwr for antenna 1 */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT1_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT1_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT1_SSEL_RESETVAL (0x00000000u)

/* sync select for CB-F power monitor in order to get MaxRefPwr for antenna 2 */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT2_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT2_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT2_SSEL_RESETVAL (0x00000000u)

/* sync select for CB-F power monitor in order to get MaxRefPwr for antenna 3 */
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT3_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT3_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_CB_F_POWERMONITOR_ANT3_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_ADDR (0x00000488u)
#define CSL_DFE_CB_CB_SYNC_SELECT_PART4_REG_RESETVAL (0x00000000u)

/* CBA_CHUNK1_2_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cba_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk1_done_addr : 13;
#else 
    Uint32 cba_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk2_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG;

/* In sharing mode and trigger mode, each section of cb-c buffer (of size chunk size) is a circular buffer, this register indicates where the capture stoped when cba was capturing chunk 1 of reference signal */
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK1_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK1_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

/* In sharing mode and trigger mode, each section of cb-c buffer (of size chunk size) is a circular buffer, this register indicates where the capture stoped when cba was capturing chunk 2 of reference signal */
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK2_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK2_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_CBA_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_ADDR (0x0000048Cu)
#define CSL_DFE_CB_CBA_CHUNK1_2_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBA_CHUNK3_4_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cba_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk3_done_addr : 13;
#else 
    Uint32 cba_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk4_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK3_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK3_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK4_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK4_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_CBA_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_ADDR (0x00000490u)
#define CSL_DFE_CB_CBA_CHUNK3_4_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBA_CHUNK5_6_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cba_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk5_done_addr : 13;
#else 
    Uint32 cba_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_ADDR (0x00000494u)
#define CSL_DFE_CB_CBA_CHUNK5_6_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBA_CHUNK7_8_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cba_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk5_done_addr : 13;
#else 
    Uint32 cba_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cba_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_CBA_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_ADDR (0x00000498u)
#define CSL_DFE_CB_CBA_CHUNK7_8_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBB_CHUNK1_2_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbb_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk1_done_addr : 13;
#else 
    Uint32 cbb_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk2_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK1_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK1_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK2_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK2_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_CBB_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_ADDR (0x0000049Cu)
#define CSL_DFE_CB_CBB_CHUNK1_2_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBB_CHUNK3_4_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbb_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk3_done_addr : 13;
#else 
    Uint32 cbb_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk4_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK3_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK3_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK4_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK4_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_CBB_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_ADDR (0x000004A0u)
#define CSL_DFE_CB_CBB_CHUNK3_4_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBB_CHUNK5_6_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbb_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk5_done_addr : 13;
#else 
    Uint32 cbb_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_ADDR (0x000004A4u)
#define CSL_DFE_CB_CBB_CHUNK5_6_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBB_CHUNK7_8_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbb_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk5_done_addr : 13;
#else 
    Uint32 cbb_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbb_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_CBB_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_ADDR (0x000004A8u)
#define CSL_DFE_CB_CBB_CHUNK7_8_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBC_CHUNK1_2_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbc_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk1_done_addr : 13;
#else 
    Uint32 cbc_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk2_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK1_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK1_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK2_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK2_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_CBC_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_ADDR (0x000004ACu)
#define CSL_DFE_CB_CBC_CHUNK1_2_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBC_CHUNK3_4_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbc_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk3_done_addr : 13;
#else 
    Uint32 cbc_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk4_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK3_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK3_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK4_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK4_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_CBC_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_ADDR (0x000004B0u)
#define CSL_DFE_CB_CBC_CHUNK3_4_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBC_CHUNK5_6_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbc_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk5_done_addr : 13;
#else 
    Uint32 cbc_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_ADDR (0x000004B4u)
#define CSL_DFE_CB_CBC_CHUNK5_6_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBC_CHUNK7_8_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbc_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk5_done_addr : 13;
#else 
    Uint32 cbc_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbc_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_CBC_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_ADDR (0x000004B8u)
#define CSL_DFE_CB_CBC_CHUNK7_8_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBD_CHUNK1_2_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbd_chunk2_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk1_done_addr : 13;
#else 
    Uint32 cbd_chunk1_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk2_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK1_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK1_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK1_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK2_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK2_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_CBD_CHUNK2_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_ADDR (0x000004BCu)
#define CSL_DFE_CB_CBD_CHUNK1_2_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBD_CHUNK3_4_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbd_chunk4_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk3_done_addr : 13;
#else 
    Uint32 cbd_chunk3_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk4_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK3_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK3_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK3_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK4_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK4_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_CBD_CHUNK4_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_ADDR (0x000004C0u)
#define CSL_DFE_CB_CBD_CHUNK3_4_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBD_CHUNK5_6_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbd_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk5_done_addr : 13;
#else 
    Uint32 cbd_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_ADDR (0x000004C4u)
#define CSL_DFE_CB_CBD_CHUNK5_6_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CBD_CHUNK7_8_DONE_ADDR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 3;
    Uint32 cbd_chunk6_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk5_done_addr : 13;
#else 
    Uint32 cbd_chunk5_done_addr : 13;
    Uint32 rsvd0 : 3;
    Uint32 cbd_chunk6_done_addr : 13;
    Uint32 rsvd1 : 3;
#endif 
} CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG;

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_MASK (0x00001FFFu)
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_SHIFT (0x00000000u)
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK5_DONE_ADDR_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_MASK (0x1FFF0000u)
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_SHIFT (0x00000010u)
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_CBD_CHUNK6_DONE_ADDR_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_ADDR (0x000004C8u)
#define CSL_DFE_CB_CBD_CHUNK7_8_DONE_ADDR_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_A_16MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 capture_buffer_a_i_16msb : 16;
    Uint32 capture_buffer_a_q_16msb : 16;
#else 
    Uint32 capture_buffer_a_q_16msb : 16;
    Uint32 capture_buffer_a_i_16msb : 16;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG;

/* capture buffer A data, Q[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_Q_16MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_Q_16MSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_Q_16MSB_RESETVAL (0x00000000u)

/* capture buffer A data, I[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_I_16MSB_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_I_16MSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_CAPTURE_BUFFER_A_I_16MSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_ADDR (0x00040000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_16MSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_B_16MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 capture_buffer_b_i_16msb : 16;
    Uint32 capture_buffer_b_q_16msb : 16;
#else 
    Uint32 capture_buffer_b_q_16msb : 16;
    Uint32 capture_buffer_b_i_16msb : 16;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG;

/* capture buffer B data, Q[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_Q_16MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_Q_16MSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_Q_16MSB_RESETVAL (0x00000000u)

/* capture buffer B data, I[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_I_16MSB_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_I_16MSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_CAPTURE_BUFFER_B_I_16MSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_ADDR (0x00048000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_16MSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_C_16MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 capture_buffer_c_i_16msb : 16;
    Uint32 capture_buffer_c_q_16msb : 16;
#else 
    Uint32 capture_buffer_c_q_16msb : 16;
    Uint32 capture_buffer_c_i_16msb : 16;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG;

/* capture buffer C data, Q[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_Q_16MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_Q_16MSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_Q_16MSB_RESETVAL (0x00000000u)

/* capture buffer C data, I[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_I_16MSB_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_I_16MSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_CAPTURE_BUFFER_C_I_16MSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_ADDR (0x00050000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_16MSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_D_16MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 capture_buffer_d_i_16msb : 16;
    Uint32 capture_buffer_d_q_16msb : 16;
#else 
    Uint32 capture_buffer_d_q_16msb : 16;
    Uint32 capture_buffer_d_i_16msb : 16;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG;

/* capture buffer D data, Q[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_Q_16MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_Q_16MSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_Q_16MSB_RESETVAL (0x00000000u)

/* capture buffer D data, I[17:2], memory is also readable when 'cba_mode' is set to 'mpu_mode' regardless 'mem_mpu_access'. */
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_I_16MSB_MASK (0xFFFF0000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_I_16MSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_CAPTURE_BUFFER_D_I_16MSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_ADDR (0x00058000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_16MSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_A_2LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 14;
    Uint32 capture_buffer_a_i_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_a_q_2lsb : 2;
#else 
    Uint32 capture_buffer_a_q_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_a_i_2lsb : 2;
    Uint32 rsvd1 : 14;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG;

/* capture buffer A data, Q[1:0]. Note that when we read, we can read out Q[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_Q_2LSB_MASK (0x00000003u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_Q_2LSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_Q_2LSB_RESETVAL (0x00000000u)

/* capture buffer A data, I[1:0], Note that when we read, we can read out I[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_I_2LSB_MASK (0x00030000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_I_2LSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_CAPTURE_BUFFER_A_I_2LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_ADDR (0x00060000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_A_2LSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_B_2LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 14;
    Uint32 capture_buffer_b_i_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_b_q_2lsb : 2;
#else 
    Uint32 capture_buffer_b_q_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_b_i_2lsb : 2;
    Uint32 rsvd1 : 14;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG;

/* capture buffer B data, Q[1:0]. Note that when we read, we can read out Q[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_Q_2LSB_MASK (0x00000003u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_Q_2LSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_Q_2LSB_RESETVAL (0x00000000u)

/* capture buffer B data, I[1:0], Note that when we read, we can read out I[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_I_2LSB_MASK (0x00030000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_I_2LSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_CAPTURE_BUFFER_B_I_2LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_ADDR (0x00068000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_B_2LSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_C_2LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 14;
    Uint32 capture_buffer_c_i_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_c_q_2lsb : 2;
#else 
    Uint32 capture_buffer_c_q_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_c_i_2lsb : 2;
    Uint32 rsvd1 : 14;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG;

/* capture buffer C data, Q[1:0]. Note that when we read, we can read out Q[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_Q_2LSB_MASK (0x00000003u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_Q_2LSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_Q_2LSB_RESETVAL (0x00000000u)

/* capture buffer C data, I[1:0], Note that when we read, we can read out I[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_I_2LSB_MASK (0x00030000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_I_2LSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_CAPTURE_BUFFER_C_I_2LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_ADDR (0x00070000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_C_2LSB_REG_RESETVAL (0x00000000u)

/* CAPTURE_BUFFER_D_2LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 14;
    Uint32 capture_buffer_d_i_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_d_q_2lsb : 2;
#else 
    Uint32 capture_buffer_d_q_2lsb : 2;
    Uint32 rsvd0 : 14;
    Uint32 capture_buffer_d_i_2lsb : 2;
    Uint32 rsvd1 : 14;
#endif 
} CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG;

/* capture buffer D data, Q[1:0]. Note that when we read, we can read out Q[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_Q_2LSB_MASK (0x00000003u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_Q_2LSB_SHIFT (0x00000000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_Q_2LSB_RESETVAL (0x00000000u)

/* capture buffer D data, I[1:0], Note that when we read, we can read out I[15:0]. */
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_I_2LSB_MASK (0x00030000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_I_2LSB_SHIFT (0x00000010u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_CAPTURE_BUFFER_D_I_2LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_ADDR (0x00078000u)
#define CSL_DFE_CB_CAPTURE_BUFFER_D_2LSB_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_CB_H__ */
