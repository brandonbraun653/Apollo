/*
 * cslr_dfe_dduc.h
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

#ifndef CSLR_DFE_DDUC_H__
#define CSLR_DFE_DDUC_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_DDUC_PFIR_COEF_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 mid;
    volatile Uint32 hi;
    volatile Uint32 rsvd0[1];
} CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_OFFSET_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_REGS;

typedef struct
{
    volatile Uint32 bank0;
    volatile Uint32 bank1;
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_REGS;

typedef struct
{
    volatile Uint32 lobank0;
    volatile Uint32 hibank0;
    volatile Uint32 lobank1;
    volatile Uint32 hibank1;
} CSL_DFE_DDUC_FRW_PHASE_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 intr_mask_mask;
    /* Addr: h(8), d(8) */
    volatile Uint32 intr_mask_status;
    /* Addr: h(C), d(12) */
    volatile Uint32 intr_mask_force;
    /* Addr: h(10), d(16) */
    volatile Uint32 rsvd1[252];
    /* Addr: h(400), d(1024) */
    volatile Uint32 inits_clks;
    /* Addr: h(404), d(1028) */
    volatile Uint32 rsvd2[255];
    /* Addr: h(800), d(2048) */
    volatile Uint32 clk_gater_time_step_lsb;
    /* Addr: h(804), d(2052) */
    volatile Uint32 clk_gater_time_step_msb;
    /* Addr: h(808), d(2056) */
    volatile Uint32 clk_gater_reset_int_lsb;
    /* Addr: h(80C), d(2060) */
    volatile Uint32 clk_gater_reset_int_msb;
    /* Addr: h(810), d(2064) */
    volatile Uint32 clk_gater_tdd_period_lsb;
    /* Addr: h(814), d(2068) */
    volatile Uint32 clk_gater_tdd_period_msb;
    /* Addr: h(818), d(2072) */
    volatile Uint32 clk_gater_tdd_on_0_lsb;
    /* Addr: h(81C), d(2076) */
    volatile Uint32 clk_gater_tdd_on_0_msb;
    /* Addr: h(820), d(2080) */
    volatile Uint32 clk_gater_tdd_off_0_lsb;
    /* Addr: h(824), d(2084) */
    volatile Uint32 clk_gater_tdd_off_0_msb;
    /* Addr: h(828), d(2088) */
    volatile Uint32 clk_gater_tdd_on_1_lsb;
    /* Addr: h(82C), d(2092) */
    volatile Uint32 clk_gater_tdd_on_1_msb;
    /* Addr: h(830), d(2096) */
    volatile Uint32 clk_gater_tdd_off_1_lsb;
    /* Addr: h(834), d(2100) */
    volatile Uint32 clk_gater_tdd_off_1_msb;
    /* Addr: h(838), d(2104) */
    volatile Uint32 rsvd3[626];
    /* Addr: h(1200), d(4608) */
    volatile Uint32 bb_frame;
    /* Addr: h(1204), d(4612) */
    volatile Uint32 bb_flag;
    /* Addr: h(1208), d(4616) */
    volatile Uint32 fir_start1;
    /* Addr: h(120C), d(4620) */
    volatile Uint32 fir_start2;
    /* Addr: h(1210), d(4624) */
    volatile Uint32 fir_stop1;
    /* Addr: h(1214), d(4628) */
    volatile Uint32 fir_stop2;
    /* Addr: h(1218), d(4632) */
    volatile Uint32 fir_flag1;
    /* Addr: h(121C), d(4636) */
    volatile Uint32 fir_flag2;
    /* Addr: h(1220), d(4640) */
    volatile Uint32 frwbb_start1;
    /* Addr: h(1224), d(4644) */
    volatile Uint32 frwbb_start2;
    /* Addr: h(1228), d(4648) */
    volatile Uint32 frwbb_stop1;
    /* Addr: h(122C), d(4652) */
    volatile Uint32 frwbb_stop2;
    /* Addr: h(1230), d(4656) */
    volatile Uint32 frwbb_flag1;
    /* Addr: h(1234), d(4660) */
    volatile Uint32 frwbb_flag2;
    /* Addr: h(1238), d(4664) */
    volatile Uint32 rsvd4[1];
    /* Addr: h(123C), d(4668) */
    volatile Uint32 config;
    /* Addr: h(1240), d(4672) */
    volatile Uint32 frwif_start;
    /* Addr: h(1244), d(4676) */
    volatile Uint32 frwif_stop;
    /* Addr: h(1248), d(4680) */
    volatile Uint32 frwif_flag;
    /* Addr: h(124C), d(4684) */
    volatile Uint32 rsvd5[1];
    /* Addr: h(1250), d(4688) */
    volatile Uint32 cicmix_start;
    /* Addr: h(1254), d(4692) */
    volatile Uint32 cicmix_comb_stop;
    /* Addr: h(1258), d(4696) */
    volatile Uint32 cicmix_stop;
    /* Addr: h(125C), d(4700) */
    volatile Uint32 cicmix_flag;
    /* Addr: h(1260), d(4704) */
    volatile Uint32 bbfir_ptr;
    /* Addr: h(1264), d(4708) */
    volatile Uint32 firfrw_ptr;
    /* Addr: h(1268), d(4712) */
    volatile Uint32 frwcic_ptr;
    /* Addr: h(126C), d(4716) */
    volatile Uint32 cic_config;
    /* Addr: h(1270), d(4720) */
    volatile Uint32 mix_config;
    /* Addr: h(1274), d(4724) */
    volatile Uint32 mix_phase[12];
    /* Addr: h(12A4), d(4772) */
    volatile Uint32 hop_dly_acc_lo;
    /* Addr: h(12A8), d(4776) */
    volatile Uint32 hop_dly_acc_hi;
    /* Addr: h(12AC), d(4780) */
    volatile Uint32 hop_rst_cnt_lo;
    /* Addr: h(12B0), d(4784) */
    volatile Uint32 hop_rst_cnt_hi;
    /* Addr: h(12B4), d(4788) */
    volatile Uint32 hop_period_lo;
    /* Addr: h(12B8), d(4792) */
    volatile Uint32 hop_total_indices;
    /* Addr: h(12BC), d(4796) */
    volatile Uint32 hop_sync_delay;
    /* Addr: h(12C0), d(4800) */
    volatile Uint32 hop_config;
    /* Addr: h(12C4), d(4804) */
    volatile Uint32 ssel0;
    /* Addr: h(12C8), d(4808) */
    volatile Uint32 ssel1;
    /* Addr: h(12CC), d(4812) */
    volatile Uint32 ssel2;
    /* Addr: h(12D0), d(4816) */
    volatile Uint32 ssel3;
    /* Addr: h(12D4), d(4820) */
    volatile Uint32 ssel4;
    /* Addr: h(12D8), d(4824) */
    volatile Uint32 ssel5;
    /* Addr: h(12DC), d(4828) */
    volatile Uint32 test_bus_mux_icg_dly;
    /* Addr: h(12E0), d(4832) */
    volatile Uint32 test_bus_bb_mux;
    /* Addr: h(12E4), d(4836) */
    volatile Uint32 selector_mix0_sel;
    /* Addr: h(12E8), d(4840) */
    volatile Uint32 selector_mix1_sel;
    /* Addr: h(12EC), d(4844) */
    volatile Uint32 selector_mix2_sel;
    /* Addr: h(12F0), d(4848) */
    volatile Uint32 rsvd6[4];
    /* Addr: h(1300), d(4864) */
    volatile Uint32 pfir_config0;
    /* Addr: h(1304), d(4868) */
    volatile Uint32 pfir_config1;
    /* Addr: h(1308), d(4872) */
    volatile Uint32 pfir_config2;
    /* Addr: h(130C), d(4876) */
    volatile Uint32 pfir_coef_offset0;
    /* Addr: h(1310), d(4880) */
    volatile Uint32 pfir_coef_offset1;
    /* Addr: h(1314), d(4884) */
    volatile Uint32 pfir_coef_offset2;
    /* Addr: h(1318), d(4888) */
    volatile Uint32 pfir_fcmux0;
    /* Addr: h(131C), d(4892) */
    volatile Uint32 pfir_fcmux1;
    /* Addr: h(1320), d(4896) */
    volatile Uint32 pfir_fcmux2;
    /* Addr: h(1324), d(4900) */
    volatile Uint32 pfir_pcsym;
    /* Addr: h(1328), d(4904) */
    volatile Uint32 rsvd7[6];
    /* Addr: h(1340), d(4928) */
    volatile Uint32 frw_time_step_lo;
    /* Addr: h(1344), d(4932) */
    volatile Uint32 frw_time_step_hi;
    /* Addr: h(1348), d(4936) */
    volatile Uint32 frw_reset_int_m1_lo;
    /* Addr: h(134C), d(4940) */
    volatile Uint32 frw_config0;
    /* Addr: h(1350), d(4944) */
    volatile Uint32 frw_config1;
    /* Addr: h(1354), d(4948) */
    volatile Uint32 frw_sig_init_val_lo;
    /* Addr: h(1358), d(4952) */
    volatile Uint32 frw_sig_inc_val_lo;
    /* Addr: h(135C), d(4956) */
    volatile Uint32 frw_sig_cfg;
    /* Addr: h(1360), d(4960) */
    volatile Uint32 frw_chksum_lo;
    /* Addr: h(1364), d(4964) */
    volatile Uint32 frw_chksum_hi;
    /* Addr: h(1368), d(4968) */
    volatile Uint32 rsvd8[6];
    /* Addr: h(1380), d(4992) */
    volatile Uint32 tx_signal_gen_config;
    /* Addr: h(1384), d(4996) */
    volatile Uint32 tx_signal_gen_ramp_start_lo;
    /* Addr: h(1388), d(5000) */
    volatile Uint32 tx_signal_gen_ramp_start_hi;
    /* Addr: h(138C), d(5004) */
    volatile Uint32 tx_signal_gen_ramp_stop_lo;
    /* Addr: h(1390), d(5008) */
    volatile Uint32 tx_signal_gen_ramp_stop_hi;
    /* Addr: h(1394), d(5012) */
    volatile Uint32 tx_signal_gen_ramp_slope_lo;
    /* Addr: h(1398), d(5016) */
    volatile Uint32 tx_signal_gen_ramp_slope_hi;
    /* Addr: h(139C), d(5020) */
    volatile Uint32 tx_signal_gen_pulse_width;
    /* Addr: h(13A0), d(5024) */
    volatile Uint32 rsvd9[1];
    /* Addr: h(13A4), d(5028) */
    volatile Uint32 rx_signal_gen_config;
    /* Addr: h(13A8), d(5032) */
    volatile Uint32 rx_signal_gen_ramp_start_lo;
    /* Addr: h(13AC), d(5036) */
    volatile Uint32 rx_signal_gen_ramp_start_hi;
    /* Addr: h(13B0), d(5040) */
    volatile Uint32 rx_signal_gen_ramp_stop_lo;
    /* Addr: h(13B4), d(5044) */
    volatile Uint32 rx_signal_gen_ramp_stop_hi;
    /* Addr: h(13B8), d(5048) */
    volatile Uint32 rx_signal_gen_ramp_slope_lo;
    /* Addr: h(13BC), d(5052) */
    volatile Uint32 rx_signal_gen_ramp_slope_hi;
    /* Addr: h(13C0), d(5056) */
    volatile Uint32 rx_signal_gen_pulse_width;
    /* Addr: h(13C4), d(5060) */
    volatile Uint32 rsvd10[1];
    /* Addr: h(13C8), d(5064) */
    volatile Uint32 tx_check_sum_config;
    /* Addr: h(13CC), d(5068) */
    volatile Uint32 tx_check_sum_signal_len;
    /* Addr: h(13D0), d(5072) */
    volatile Uint32 tx_check_sum_chan_sel;
    /* Addr: h(13D4), d(5076) */
    volatile Uint32 tx_check_sum_result_lo;
    /* Addr: h(13D8), d(5080) */
    volatile Uint32 tx_check_sum_result_hi;
    /* Addr: h(13DC), d(5084) */
    volatile Uint32 rx_check_sum_config;
    /* Addr: h(13E0), d(5088) */
    volatile Uint32 rx_check_sum_signal_len;
    /* Addr: h(13E4), d(5092) */
    volatile Uint32 rx_check_sum_chan_sel;
    /* Addr: h(13E8), d(5096) */
    volatile Uint32 rx_check_sum_result_lo;
    /* Addr: h(13EC), d(5100) */
    volatile Uint32 rx_check_sum_result_hi;
    /* Addr: h(13F0), d(5104) */
    volatile Uint32 rsvd11[64260];
    /* Addr: h(40000), d(262144) */
    volatile CSL_DFE_DDUC_PFIR_COEF_REGS pfir_coef[640];
    /* Addr: h(41400), d(267264) */
    volatile Uint32 rsvd12[768];
    /* Addr: h(42000), d(270336) */
    volatile Uint32 hop_hop2freq_tbl[1024];
    /* Addr: h(43000), d(274432) */
    volatile CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_REGS hop_freq2word_tbl[64];
    /* Addr: h(43400), d(275456) */
    volatile CSL_DFE_DDUC_HOP_OFFSET_REGS hop_offset[12];
    /* Addr: h(43460), d(275552) */
    volatile Uint32 rsvd13[8];
    /* Addr: h(43480), d(275584) */
    volatile CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_REGS hop_mix0_freq_word_lo[4];
    /* Addr: h(434A0), d(275616) */
    volatile CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_REGS hop_mix0_freq_word_mid[4];
    /* Addr: h(434C0), d(275648) */
    volatile CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_REGS hop_mix0_freq_word_hi[4];
    /* Addr: h(434E0), d(275680) */
    volatile CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_REGS hop_mix1_freq_word_lo[4];
    /* Addr: h(43500), d(275712) */
    volatile CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_REGS hop_mix1_freq_word_mid[4];
    /* Addr: h(43520), d(275744) */
    volatile CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_REGS hop_mix1_freq_word_hi[4];
    /* Addr: h(43540), d(275776) */
    volatile CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_REGS hop_mix2_freq_word_lo[4];
    /* Addr: h(43560), d(275808) */
    volatile CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_REGS hop_mix2_freq_word_mid[4];
    /* Addr: h(43580), d(275840) */
    volatile CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_REGS hop_mix2_freq_word_hi[4];
    /* Addr: h(435A0), d(275872) */
    volatile Uint32 rsvd14[152];
    /* Addr: h(43800), d(276480) */
    volatile CSL_DFE_DDUC_FRW_PHASE_REGS frw_phase[12];
} CSL_DFE_DDUC_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* INTR_MASK_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 hop_halfway_intr_mask : 1;
    Uint32 hop_rollover_intr_mask : 1;
    Uint32 cic_ov_intr_mask : 3;
#else 
    Uint32 cic_ov_intr_mask : 3;
    Uint32 hop_rollover_intr_mask : 1;
    Uint32 hop_halfway_intr_mask : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_DDUC_INTR_MASK_MASK_REG;

/* Mask which interrupts go out dduc interrupt pin. 1 to mask on, 0 to mask off. */
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_CIC_OV_INTR_MASK_MASK (0x00000007u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_CIC_OV_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_CIC_OV_INTR_MASK_RESETVAL (0x00000000u)

/* Mask which interrupts go out dduc interrupt pin. 1 to mask on, 0 to mask off. */
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_ROLLOVER_INTR_MASK_MASK (0x00000008u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_ROLLOVER_INTR_MASK_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_ROLLOVER_INTR_MASK_RESETVAL (0x00000000u)

/* Mask which interrupts go out dduc interrupt pin. 1 to mask on, 0 to mask off. */
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_HALFWAY_INTR_MASK_MASK (0x00000010u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_HALFWAY_INTR_MASK_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_HOP_HALFWAY_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_ADDR (0x00000004u)
#define CSL_DFE_DDUC_INTR_MASK_MASK_REG_RESETVAL (0x00000000u)

/* INTR_MASK_STATUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 hop_halfway_intr_status : 1;
    Uint32 hop_rollover_intr_status : 1;
    Uint32 cic_ov_intr_status : 3;
#else 
    Uint32 cic_ov_intr_status : 3;
    Uint32 hop_rollover_intr_status : 1;
    Uint32 hop_halfway_intr_status : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_DDUC_INTR_MASK_STATUS_REG;

/* Goes high only if cic overflows. Goes low only when mpu writes a 0. MPU writing 1 does nothing. */
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_CIC_OV_INTR_STATUS_MASK (0x00000007u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_CIC_OV_INTR_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_CIC_OV_INTR_STATUS_RESETVAL (0x00000000u)

/* Goes high only if hop period is done Goes low only when mpu writes a 0. MPU writing 1 does nothing. */
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_ROLLOVER_INTR_STATUS_MASK (0x00000008u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_ROLLOVER_INTR_STATUS_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_ROLLOVER_INTR_STATUS_RESETVAL (0x00000000u)

/* Goes high only if hop period is halways done. Goes low only when mpu writes a 0. MPU writing 1 does nothing. */
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_HALFWAY_INTR_STATUS_MASK (0x00000010u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_HALFWAY_INTR_STATUS_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_HOP_HALFWAY_INTR_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_ADDR (0x00000008u)
#define CSL_DFE_DDUC_INTR_MASK_STATUS_REG_RESETVAL (0x00000000u)

/* INTR_MASK_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 hop_halfway_intr_force : 1;
    Uint32 hop_rollover_intr_force : 1;
    Uint32 cic_ov_intr_force : 3;
#else 
    Uint32 cic_ov_intr_force : 3;
    Uint32 hop_rollover_intr_force : 1;
    Uint32 hop_halfway_intr_force : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_DDUC_INTR_MASK_FORCE_REG;

/* Set to 1 to force cic_ov_intr status high */
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_CIC_OV_INTR_FORCE_MASK (0x00000007u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_CIC_OV_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_CIC_OV_INTR_FORCE_RESETVAL (0x00000000u)

/* Set to 1 to force hop_rollover_intr status high */
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_ROLLOVER_INTR_FORCE_MASK (0x00000008u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_ROLLOVER_INTR_FORCE_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_ROLLOVER_INTR_FORCE_RESETVAL (0x00000000u)

/* Set to 1 to force hop_halfway_intr status high */
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_HALFWAY_INTR_FORCE_MASK (0x00000010u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_HALFWAY_INTR_FORCE_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_HOP_HALFWAY_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_ADDR (0x0000000Cu)
#define CSL_DFE_DDUC_INTR_MASK_FORCE_REG_RESETVAL (0x00000000u)

/* INITS_CLKS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rx_cken_mult : 2;
    Uint32 rx_cken_dly : 3;
    Uint32 bb_cken_dly : 3;
    Uint32 tx_sel : 1;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 tx_sel : 1;
    Uint32 bb_cken_dly : 3;
    Uint32 rx_cken_dly : 3;
    Uint32 rx_cken_mult : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_INITS_CLKS_REG;

/* Sync to release init_clk_gate, init_state and clear_data */
#define CSL_DFE_DDUC_INITS_CLKS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* When set to 1, all clock gating logic is held in initial state. When set to 0 AND an inits_ssel is sent, clock gating logic is released from initial state. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* When set to 1, all state machine logic is held in initial state. When set to 0 AND an inits_ssel is sent, state machine logic is released from initial state. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* When set to 1, all data is forced to zero. When set to 0 AND an inits_ssel is sent, data is allowed to flow through. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* Set to 1 if dduc is in transmit/downlink, 0 otherwse. Used to mux cken signals. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_TX_SEL_MASK (0x00000080u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_TX_SEL_SHIFT (0x00000007u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_TX_SEL_RESETVAL (0x00000000u)

/* Set to N to delay the bb_cken signal by N clocks (does NOT delay frame/data). */
#define CSL_DFE_DDUC_INITS_CLKS_REG_BB_CKEN_DLY_MASK (0x00000700u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_BB_CKEN_DLY_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_BB_CKEN_DLY_RESETVAL (0x00000000u)

/* If this is dduc0, then set to N to delay the rx_cken signal by N clocks. If this is dduc1, then set to N to delay the fb_cken signal by N clocks. This does nothing for dduc 2 and 3. This does NOT delay frame/data. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_DLY_MASK (0x00003800u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_DLY_SHIFT (0x0000000Bu)
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_DLY_RESETVAL (0x00000000u)

/* If this is dduc0, then set to 3 to multiply rx_cken signal by 8. 2 by 4. 1 by 2. 0 to do nothing. If this is dduc1, then this multiplies fb_cken signal instead. If this is dduc2 or 3, it does nothing. Also re-aligns data and frame signals with new, multiplied cken. */
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_MULT_MASK (0x0000C000u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_MULT_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_INITS_CLKS_REG_RX_CKEN_MULT_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_INITS_CLKS_REG_ADDR (0x00000400u)
#define CSL_DFE_DDUC_INITS_CLKS_REG_RESETVAL (0x00000070u)

/* CLK_GATER_TIME_STEP_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_15_0 : 16;
#else 
    Uint32 time_step_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^31)/time_step clocks. Put another way: multiplies the clock rate by ((2^31)-time_step)/(2^31). */
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG_TIME_STEP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG_TIME_STEP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG_TIME_STEP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG_ADDR (0x00000800u)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TIME_STEP_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_31_16 : 16;
#else 
    Uint32 time_step_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG_TIME_STEP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG_TIME_STEP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG_TIME_STEP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG_ADDR (0x00000804u)
#define CSL_DFE_DDUC_CLK_GATER_TIME_STEP_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_RESET_INT_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int_15_0 : 16;
#else 
    Uint32 reset_int_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG_RESET_INT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG_RESET_INT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG_RESET_INT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG_ADDR (0x00000808u)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_RESET_INT_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int_31_16 : 16;
#else 
    Uint32 reset_int_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG_RESET_INT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG_RESET_INT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG_RESET_INT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG_ADDR (0x0000080Cu)
#define CSL_DFE_DDUC_CLK_GATER_RESET_INT_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_PERIOD_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_15_0 : 16;
#else 
    Uint32 tdd_period_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG_TDD_PERIOD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG_TDD_PERIOD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG_TDD_PERIOD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG_ADDR (0x00000810u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_PERIOD_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_23_16 : 8;
#else 
    Uint32 tdd_period_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG_TDD_PERIOD_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG_TDD_PERIOD_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG_TDD_PERIOD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG_ADDR (0x00000814u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_PERIOD_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_ON_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_15_0 : 16;
#else 
    Uint32 tdd_on_0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG_TDD_ON_0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG_TDD_ON_0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG_TDD_ON_0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG_ADDR (0x00000818u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_ON_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_23_16 : 8;
#else 
    Uint32 tdd_on_0_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG_TDD_ON_0_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG_TDD_ON_0_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG_TDD_ON_0_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG_ADDR (0x0000081Cu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_0_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_OFF_0_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_15_0 : 16;
#else 
    Uint32 tdd_off_0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG_TDD_OFF_0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG_TDD_OFF_0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG_TDD_OFF_0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG_ADDR (0x00000820u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_OFF_0_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_23_16 : 8;
#else 
    Uint32 tdd_off_0_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG_TDD_OFF_0_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG_TDD_OFF_0_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG_TDD_OFF_0_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG_ADDR (0x00000824u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_0_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_ON_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_15_0 : 16;
#else 
    Uint32 tdd_on_1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG_TDD_ON_1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG_TDD_ON_1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG_TDD_ON_1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG_ADDR (0x00000828u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_ON_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_23_16 : 8;
#else 
    Uint32 tdd_on_1_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG_TDD_ON_1_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG_TDD_ON_1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG_TDD_ON_1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG_ADDR (0x0000082Cu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_ON_1_MSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_OFF_1_LSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_15_0 : 16;
#else 
    Uint32 tdd_off_1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG_TDD_OFF_1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG_TDD_OFF_1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG_TDD_OFF_1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG_ADDR (0x00000830u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_LSB_REG_RESETVAL (0x00000000u)

/* CLK_GATER_TDD_OFF_1_MSB */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_23_16 : 8;
#else 
    Uint32 tdd_off_1_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG;

/*  */
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG_TDD_OFF_1_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG_TDD_OFF_1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG_TDD_OFF_1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG_ADDR (0x00000834u)
#define CSL_DFE_DDUC_CLK_GATER_TDD_OFF_1_MSB_REG_RESETVAL (0x00000000u)

/* BB_FRAME */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_frame : 16;
#else 
    Uint32 bb_frame : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_BB_FRAME_REG;

/* number of BB clocks in frame minus 1 (number of clocks before reseting BB clock counter) */
#define CSL_DFE_DDUC_BB_FRAME_REG_BB_FRAME_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_BB_FRAME_REG_BB_FRAME_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_BB_FRAME_REG_BB_FRAME_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_BB_FRAME_REG_ADDR (0x00001200u)
#define CSL_DFE_DDUC_BB_FRAME_REG_RESETVAL (0x00000000u)

/* BB_FLAG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_flag : 16;
#else 
    Uint32 bb_flag : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_BB_FLAG_REG;

/* value the BB clock counter must be to send a flag to the BB-PFIR buffer and a delayed channel flag out of the DDUC in RX mode. Does nothing in TX mode. */
#define CSL_DFE_DDUC_BB_FLAG_REG_BB_FLAG_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_BB_FLAG_REG_BB_FLAG_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_BB_FLAG_REG_BB_FLAG_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_BB_FLAG_REG_ADDR (0x00001204u)
#define CSL_DFE_DDUC_BB_FLAG_REG_RESETVAL (0x00000000u)

/* FIR_START1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_strt1 : 16;
#else 
    Uint32 fir_strt1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_START1_REG;

/* value the BB clock counter must be to start clocks to fir the first time */
#define CSL_DFE_DDUC_FIR_START1_REG_FIR_STRT1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_START1_REG_FIR_STRT1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_START1_REG_FIR_STRT1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_START1_REG_ADDR (0x00001208u)
#define CSL_DFE_DDUC_FIR_START1_REG_RESETVAL (0x00000000u)

/* FIR_START2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_strt2 : 16;
#else 
    Uint32 fir_strt2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_START2_REG;

/* value the BB clock counter must be to start clocks to fir the second time */
#define CSL_DFE_DDUC_FIR_START2_REG_FIR_STRT2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_START2_REG_FIR_STRT2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_START2_REG_FIR_STRT2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_START2_REG_ADDR (0x0000120Cu)
#define CSL_DFE_DDUC_FIR_START2_REG_RESETVAL (0x00000000u)

/* FIR_STOP1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_stop1 : 16;
#else 
    Uint32 fir_stop1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_STOP1_REG;

/* value the BB clock counter must be to stop clocks to fir the first time */
#define CSL_DFE_DDUC_FIR_STOP1_REG_FIR_STOP1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_STOP1_REG_FIR_STOP1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_STOP1_REG_FIR_STOP1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_STOP1_REG_ADDR (0x00001210u)
#define CSL_DFE_DDUC_FIR_STOP1_REG_RESETVAL (0x00000000u)

/* FIR_STOP2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_stop2 : 16;
#else 
    Uint32 fir_stop2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_STOP2_REG;

/* value the BB clock counter must be to stop clocks to fir the second time */
#define CSL_DFE_DDUC_FIR_STOP2_REG_FIR_STOP2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_STOP2_REG_FIR_STOP2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_STOP2_REG_FIR_STOP2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_STOP2_REG_ADDR (0x00001214u)
#define CSL_DFE_DDUC_FIR_STOP2_REG_RESETVAL (0x00000000u)

/* FIR_FLAG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_flag1 : 16;
#else 
    Uint32 fir_flag1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_FLAG1_REG;

/* value the BB clock counter must be to send a flag to BB-PFIR buffer and a delayed flag to PFIR in TX mode, or a flag to PFIR-FRW buffer and a delayed flag to PFIR in RX mode the first time. */
#define CSL_DFE_DDUC_FIR_FLAG1_REG_FIR_FLAG1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_FLAG1_REG_FIR_FLAG1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_FLAG1_REG_FIR_FLAG1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_FLAG1_REG_ADDR (0x00001218u)
#define CSL_DFE_DDUC_FIR_FLAG1_REG_RESETVAL (0x00000000u)

/* FIR_FLAG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fir_flag2 : 16;
#else 
    Uint32 fir_flag2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FIR_FLAG2_REG;

/* value the BB clock counter must be to send a flag to BB-PFIR buffer and a delayed flag to PFIR in TX mode, or a flag to PFIR-FRW buffer and a delayed flag to PFIR in RX mode a second time. */
#define CSL_DFE_DDUC_FIR_FLAG2_REG_FIR_FLAG2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FIR_FLAG2_REG_FIR_FLAG2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIR_FLAG2_REG_FIR_FLAG2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIR_FLAG2_REG_ADDR (0x0000121Cu)
#define CSL_DFE_DDUC_FIR_FLAG2_REG_RESETVAL (0x00000000u)

/* FRWBB_START1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_strt1 : 16;
#else 
    Uint32 frwbb_strt1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_START1_REG;

/* value the BB clock counter must be to start clocks to frw (BB side) the first time */
#define CSL_DFE_DDUC_FRWBB_START1_REG_FRWBB_STRT1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_START1_REG_FRWBB_STRT1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_START1_REG_FRWBB_STRT1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_START1_REG_ADDR (0x00001220u)
#define CSL_DFE_DDUC_FRWBB_START1_REG_RESETVAL (0x00000000u)

/* FRWBB_START2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_strt2 : 16;
#else 
    Uint32 frwbb_strt2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_START2_REG;

/* value the BB clock counter must be to start clocks to frw (BB side) the second time */
#define CSL_DFE_DDUC_FRWBB_START2_REG_FRWBB_STRT2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_START2_REG_FRWBB_STRT2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_START2_REG_FRWBB_STRT2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_START2_REG_ADDR (0x00001224u)
#define CSL_DFE_DDUC_FRWBB_START2_REG_RESETVAL (0x00000000u)

/* FRWBB_STOP1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_stop1 : 16;
#else 
    Uint32 frwbb_stop1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_STOP1_REG;

/* value the BB clock counter must be to stop clocks to frw (BB side) the first time */
#define CSL_DFE_DDUC_FRWBB_STOP1_REG_FRWBB_STOP1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_STOP1_REG_FRWBB_STOP1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_STOP1_REG_FRWBB_STOP1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_STOP1_REG_ADDR (0x00001228u)
#define CSL_DFE_DDUC_FRWBB_STOP1_REG_RESETVAL (0x00000000u)

/* FRWBB_STOP2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_stop2 : 16;
#else 
    Uint32 frwbb_stop2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_STOP2_REG;

/* value the BB clock counter must be to stop clocks to frw (BB side) the second time */
#define CSL_DFE_DDUC_FRWBB_STOP2_REG_FRWBB_STOP2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_STOP2_REG_FRWBB_STOP2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_STOP2_REG_FRWBB_STOP2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_STOP2_REG_ADDR (0x0000122Cu)
#define CSL_DFE_DDUC_FRWBB_STOP2_REG_RESETVAL (0x00000000u)

/* FRWBB_FLAG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_flag1 : 16;
#else 
    Uint32 frwbb_flag1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_FLAG1_REG;

/* value the BB clock counter must be to send a flag to FIR-FRW buffer and to FRW bb side in TX or RX mode the first time. Depending on the mode, the flag is delayed to the buffer or to FRW. */
#define CSL_DFE_DDUC_FRWBB_FLAG1_REG_FRWBB_FLAG1_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_FLAG1_REG_FRWBB_FLAG1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_FLAG1_REG_FRWBB_FLAG1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_FLAG1_REG_ADDR (0x00001230u)
#define CSL_DFE_DDUC_FRWBB_FLAG1_REG_RESETVAL (0x00000000u)

/* FRWBB_FLAG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frwbb_flag2 : 16;
#else 
    Uint32 frwbb_flag2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRWBB_FLAG2_REG;

/* value the BB clock counter must be to send a flag to FIR-FRW buffer and to FRW bb side in TX or RX mode a second time. Depending on the mode, the flag is delayed to the buffer or to FRW. */
#define CSL_DFE_DDUC_FRWBB_FLAG2_REG_FRWBB_FLAG2_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRWBB_FLAG2_REG_FRWBB_FLAG2_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWBB_FLAG2_REG_FRWBB_FLAG2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWBB_FLAG2_REG_ADDR (0x00001234u)
#define CSL_DFE_DDUC_FRWBB_FLAG2_REG_RESETVAL (0x00000000u)

/* CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 frw_byp : 1;
    Uint32 cic0_byp : 1;
    Uint32 cicmix_en2 : 1;
    Uint32 cicmix_en1 : 1;
    Uint32 cicmix_en0 : 1;
    Uint32 if_frame : 6;
#else 
    Uint32 if_frame : 6;
    Uint32 cicmix_en0 : 1;
    Uint32 cicmix_en1 : 1;
    Uint32 cicmix_en2 : 1;
    Uint32 cic0_byp : 1;
    Uint32 frw_byp : 1;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_DDUC_CONFIG_REG;

/* number of IF clocks in frame minus 1 (number of clocks before reseting IF clock counter) */
#define CSL_DFE_DDUC_CONFIG_REG_IF_FRAME_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_CONFIG_REG_IF_FRAME_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CONFIG_REG_IF_FRAME_RESETVAL (0x00000000u)

/* enable CIC0 and MIX0 (turns on/off the clocks…does NOT bypass the blocks) */
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN0_MASK (0x00000040u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN0_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN0_RESETVAL (0x00000000u)

/* enable CIC1 and MIX1 (turns on/off the clocks…does NOT bypass the blocks) */
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN1_MASK (0x00000080u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN1_SHIFT (0x00000007u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN1_RESETVAL (0x00000000u)

/* enable CIC2 and MIX2 (turns on/off the clocks…does NOT bypass the blocks) */
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN2_MASK (0x00000100u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_CONFIG_REG_CICMIX_EN2_RESETVAL (0x00000000u)

/* bypass CIC 0 input to output (both xmt and rcv…does NOT turn off clocks) */
#define CSL_DFE_DDUC_CONFIG_REG_CIC0_BYP_MASK (0x00000200u)
#define CSL_DFE_DDUC_CONFIG_REG_CIC0_BYP_SHIFT (0x00000009u)
#define CSL_DFE_DDUC_CONFIG_REG_CIC0_BYP_RESETVAL (0x00000000u)

/* bypass frw (requires farrow phase to be 0 and time_step decimal portion to be 0); if asserted, frw gain is forced to 1.0 in transmit and 0.5 in receive. */
#define CSL_DFE_DDUC_CONFIG_REG_FRW_BYP_MASK (0x00000400u)
#define CSL_DFE_DDUC_CONFIG_REG_FRW_BYP_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_CONFIG_REG_FRW_BYP_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CONFIG_REG_ADDR (0x0000123Cu)
#define CSL_DFE_DDUC_CONFIG_REG_RESETVAL (0x00000000u)

/* FRWIF_START */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 frwif_strt2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_strt1 : 6;
#else 
    Uint32 frwif_strt1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_strt2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_FRWIF_START_REG;

/* value the IF clock counter must be to start clocks to frw (IF side) the first time */
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to start clocks to frw (IF side) the second time */
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRWIF_START_REG_FRWIF_STRT2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWIF_START_REG_ADDR (0x00001240u)
#define CSL_DFE_DDUC_FRWIF_START_REG_RESETVAL (0x00000000u)

/* FRWIF_STOP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 frwif_stop2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_stop1 : 6;
#else 
    Uint32 frwif_stop1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_stop2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_FRWIF_STOP_REG;

/* value the IF clock counter must be to stop clocks to frw (IF side) the first time */
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to stop clocks to frw (IF side) the second time */
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRWIF_STOP_REG_FRWIF_STOP2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWIF_STOP_REG_ADDR (0x00001244u)
#define CSL_DFE_DDUC_FRWIF_STOP_REG_RESETVAL (0x00000000u)

/* FRWIF_FLAG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 frwif_flag2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_flag1 : 6;
#else 
    Uint32 frwif_flag1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 frwif_flag2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_FRWIF_FLAG_REG;

/* value the IF clock counter must be to send a flag to FRW IF side and a delayed flag to FRW-CIC buffer the first time in TX or RX mode. */
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to send a flag to FRW IF side and a delayed flag to FRW-CIC buffer a second time in TX or RX mode. */
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_FRWIF_FLAG2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWIF_FLAG_REG_ADDR (0x00001248u)
#define CSL_DFE_DDUC_FRWIF_FLAG_REG_RESETVAL (0x00000000u)

/* CICMIX_START */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cicmix_strt2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_strt1 : 6;
#else 
    Uint32 cicmix_strt1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_strt2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_CICMIX_START_REG;

/* value the IF clock counter must be to start clocks to CIC (including CIC comb filter) and mixer the first time */
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to start clocks to CIC (including CIC comb filter) and mixer the second time */
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_CICMIX_START_REG_CICMIX_STRT2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CICMIX_START_REG_ADDR (0x00001250u)
#define CSL_DFE_DDUC_CICMIX_START_REG_RESETVAL (0x00000000u)

/* CICMIX_COMB_STOP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cic_cmb_stop2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cic_cmb_stop1 : 6;
#else 
    Uint32 cic_cmb_stop1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cic_cmb_stop2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_CICMIX_COMB_STOP_REG;

/* value the IF clock counter must be to stop clocks to CIC comb filter for the first time */
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to stop clocks to CIC comb filter for the second time */
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_CIC_CMB_STOP2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_ADDR (0x00001254u)
#define CSL_DFE_DDUC_CICMIX_COMB_STOP_REG_RESETVAL (0x00000000u)

/* CICMIX_STOP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cicmix_stop2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_stop1 : 6;
#else 
    Uint32 cicmix_stop1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_stop2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_CICMIX_STOP_REG;

/* value the IF clock counter must be to stop clocks to the rest of CIC and the mixer for the first time */
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to stop clocks to the rest of CIC and the mixer for the second time */
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_CICMIX_STOP_REG_CICMIX_STOP2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CICMIX_STOP_REG_ADDR (0x00001258u)
#define CSL_DFE_DDUC_CICMIX_STOP_REG_RESETVAL (0x00000000u)

/* CICMIX_FLAG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cicmix_flag2 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_flag1 : 6;
#else 
    Uint32 cicmix_flag1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cicmix_flag2 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_CICMIX_FLAG_REG;

/* value the IF clock counter must be to send a channel flag to CIC-FRW buffer and a delayed flag to hopper and MIX the first time. In TX mode, is also delayed to create DDUC's ch0 out flag. */
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG1_RESETVAL (0x00000000u)

/* value the IF clock counter must be to send a channel flag to CIC-FRW buffer and a delayed flag to hopper and MIX a second time. In TX mode, is also delayed to create DDUC's ch0 out flag. */
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG2_MASK (0x00003F00u)
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_CICMIX_FLAG2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CICMIX_FLAG_REG_ADDR (0x0000125Cu)
#define CSL_DFE_DDUC_CICMIX_FLAG_REG_RESETVAL (0x00000000u)

/* BBFIR_PTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 bbf_rp : 5;
    Uint32 rsvd0 : 3;
    Uint32 bbf_wp : 5;
#else 
    Uint32 bbf_wp : 5;
    Uint32 rsvd0 : 3;
    Uint32 bbf_rp : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_DDUC_BBFIR_PTR_REG;

/* starting write pointer address for BB-FIR buffer */
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_WP_MASK (0x0000001Fu)
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_WP_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_WP_RESETVAL (0x00000000u)

/* starting read pointer address for BB-FIR buffer */
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_RP_MASK (0x00001F00u)
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_RP_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_BBFIR_PTR_REG_BBF_RP_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_BBFIR_PTR_REG_ADDR (0x00001260u)
#define CSL_DFE_DDUC_BBFIR_PTR_REG_RESETVAL (0x00000000u)

/* FIRFRW_PTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 ff_rp : 6;
    Uint32 rsvd0 : 2;
    Uint32 ff_wp : 6;
#else 
    Uint32 ff_wp : 6;
    Uint32 rsvd0 : 2;
    Uint32 ff_rp : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_FIRFRW_PTR_REG;

/* starting write pointer address for FIR-FRW buffer */
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_WP_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_WP_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_WP_RESETVAL (0x00000000u)

/* starting read pointer address for FIR-FRW buffer */
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_RP_MASK (0x00003F00u)
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_RP_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_FF_RP_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FIRFRW_PTR_REG_ADDR (0x00001264u)
#define CSL_DFE_DDUC_FIRFRW_PTR_REG_RESETVAL (0x00000000u)

/* FRWCIC_PTR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 set_tx : 1;
    Uint32 fc_rp : 5;
    Uint32 rsvd0 : 3;
    Uint32 fc_wp : 5;
#else 
    Uint32 fc_wp : 5;
    Uint32 rsvd0 : 3;
    Uint32 fc_rp : 5;
    Uint32 set_tx : 1;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_FRWCIC_PTR_REG;

/* starting write pointer address for FRW-CIC buffer */
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_WP_MASK (0x0000001Fu)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_WP_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_WP_RESETVAL (0x00000000u)

/* starting read pointer address for FRW-CIC buffer */
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_RP_MASK (0x00001F00u)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_RP_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_FC_RP_RESETVAL (0x00000000u)

/* 1 if in transmit (DUC) mode, 0 if in receive (DDC) mode */
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_SET_TX_MASK (0x00002000u)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_SET_TX_SHIFT (0x0000000Du)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_SET_TX_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRWCIC_PTR_REG_ADDR (0x00001268u)
#define CSL_DFE_DDUC_FRWCIC_PTR_REG_RESETVAL (0x00000000u)

/* CIC_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 22;
    Uint32 cic_rx_output_scale : 4;
    Uint32 rsvd0 : 1;
    Uint32 fl_en : 1;
    Uint32 cic_ndata : 3;
    Uint32 rate : 1;
#else 
    Uint32 rate : 1;
    Uint32 cic_ndata : 3;
    Uint32 fl_en : 1;
    Uint32 rsvd0 : 1;
    Uint32 cic_rx_output_scale : 4;
    Uint32 rsvd1 : 22;
#endif 
} CSL_DFE_DDUC_CIC_CONFIG_REG;

/* 0 for int/dec by 2, 1 for int/dec by 3 */
#define CSL_DFE_DDUC_CIC_CONFIG_REG_RATE_MASK (0x00000001u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_RATE_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_RATE_RESETVAL (0x00000000u)

/* number of real streams per CIC minus one (also sets for the mixer) */
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_NDATA_MASK (0x0000000Eu)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_NDATA_SHIFT (0x00000001u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_NDATA_RESETVAL (0x00000000u)

/* 1 to enable auto-flush, 0 to disable */
#define CSL_DFE_DDUC_CIC_CONFIG_REG_FL_EN_MASK (0x00000010u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_FL_EN_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_FL_EN_RESETVAL (0x00000000u)

/* change CIC gain in receive mode (has no effect in transmit mode): */
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_RX_OUTPUT_SCALE_MASK (0x000003C0u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_RX_OUTPUT_SCALE_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_CIC_RX_OUTPUT_SCALE_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_CIC_CONFIG_REG_ADDR (0x0000126Cu)
#define CSL_DFE_DDUC_CIC_CONFIG_REG_RESETVAL (0x00000000u)

/* MIX_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 mix_im2 : 1;
    Uint32 mix_im1 : 1;
    Uint32 mix_im0 : 1;
    Uint32 mix_rl2 : 1;
    Uint32 mix_rl1 : 1;
    Uint32 mix_rl0 : 1;
    Uint32 mix_dit_en : 1;
#else 
    Uint32 mix_dit_en : 1;
    Uint32 mix_rl0 : 1;
    Uint32 mix_rl1 : 1;
    Uint32 mix_rl2 : 1;
    Uint32 mix_im0 : 1;
    Uint32 mix_im1 : 1;
    Uint32 mix_im2 : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_DDUC_MIX_CONFIG_REG;

/* 1 to enable dithering on all mixers, 0 to turn all dithering off */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_DIT_EN_MASK (0x00000001u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_DIT_EN_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_DIT_EN_RESETVAL (0x00000000u)

/* 1 to set mixer0 to 1 channel real mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL0_MASK (0x00000002u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL0_SHIFT (0x00000001u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL0_RESETVAL (0x00000000u)

/* 1 to set mixer1 to 1 channel real mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL1_MASK (0x00000004u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL1_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL1_RESETVAL (0x00000000u)

/* 1 to set mixer2 to 1 channel real mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL2_MASK (0x00000008u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL2_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_RL2_RESETVAL (0x00000000u)

/* 1 to set mixer0 to 1 channel imaginary mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM0_MASK (0x00000010u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM0_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM0_RESETVAL (0x00000000u)

/* 1 to set mixer1 to 1 channel imaginary mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM1_MASK (0x00000020u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM1_SHIFT (0x00000005u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM1_RESETVAL (0x00000000u)

/* 1 to set mixer2 to 1 channel imaginary mode */
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM2_MASK (0x00000040u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM2_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_MIX_IM2_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_MIX_CONFIG_REG_ADDR (0x00001270u)
#define CSL_DFE_DDUC_MIX_CONFIG_REG_RESETVAL (0x00000000u)

/* MIX_PHASE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 phase : 16;
#else 
    Uint32 phase : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_MIX_PHASE_REG;

/* shadow registers for mixer phase for channels 0-11. Loaded to active registers upon sync. This control provides 360 degrees of phase control (ie phase equals 360 degrees * value/65536) */
#define CSL_DFE_DDUC_MIX_PHASE_REG_PHASE_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_MIX_PHASE_REG_PHASE_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_MIX_PHASE_REG_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_MIX_PHASE_REG_ADDR (0x00001274u)
#define CSL_DFE_DDUC_MIX_PHASE_REG_RESETVAL (0x00000000u)

/* HOP_DLY_ACC_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dly_acc_15_0 : 16;
#else 
    Uint32 dly_acc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG;

/* Time step word for the farrow-style accumulator in hopper. When there is an overflow at 0x40000000, the hop period counter does NOT count for one clock. Note that the accumulation word (24 bits) is smaller than the overflow point (at 30 bits) */
#define CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG_DLY_ACC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG_DLY_ACC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG_DLY_ACC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG_ADDR (0x000012A4u)
#define CSL_DFE_DDUC_HOP_DLY_ACC_LO_REG_RESETVAL (0x00000000u)

/* HOP_DLY_ACC_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 dly_acc_23_16 : 8;
#else 
    Uint32 dly_acc_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG;

/*  */
#define CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG_DLY_ACC_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG_DLY_ACC_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG_DLY_ACC_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG_ADDR (0x000012A8u)
#define CSL_DFE_DDUC_HOP_DLY_ACC_HI_REG_RESETVAL (0x00000000u)

/* HOP_RST_CNT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rst_cnt_15_0 : 16;
#else 
    Uint32 rst_cnt_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_RST_CNT_LO_REG;

/* Reset interval for farrow-style accumulator in hopper. Counts every clock. When this counts down, the accumulator zeroes itself and it counts as an overflow. Program to desired counting period minus 1. If set to 0, it disables the counter. */
#define CSL_DFE_DDUC_HOP_RST_CNT_LO_REG_RST_CNT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_RST_CNT_LO_REG_RST_CNT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_RST_CNT_LO_REG_RST_CNT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_RST_CNT_LO_REG_ADDR (0x000012ACu)
#define CSL_DFE_DDUC_HOP_RST_CNT_LO_REG_RESETVAL (0x00000000u)

/* HOP_RST_CNT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 rst_cnt_25_16 : 10;
#else 
    Uint32 rst_cnt_25_16 : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_DDUC_HOP_RST_CNT_HI_REG;

/*  */
#define CSL_DFE_DDUC_HOP_RST_CNT_HI_REG_RST_CNT_25_16_MASK (0x000003FFu)
#define CSL_DFE_DDUC_HOP_RST_CNT_HI_REG_RST_CNT_25_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_RST_CNT_HI_REG_RST_CNT_25_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_RST_CNT_HI_REG_ADDR (0x000012B0u)
#define CSL_DFE_DDUC_HOP_RST_CNT_HI_REG_RESETVAL (0x00000000u)

/* HOP_PERIOD_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hop_period_15_0 : 16;
#else 
    Uint32 hop_period_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_PERIOD_LO_REG;

/* Number of dduc if clocks in one hopper period. When it counts down, it increments the hop index counter. */
#define CSL_DFE_DDUC_HOP_PERIOD_LO_REG_HOP_PERIOD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_PERIOD_LO_REG_HOP_PERIOD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_PERIOD_LO_REG_HOP_PERIOD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_PERIOD_LO_REG_ADDR (0x000012B4u)
#define CSL_DFE_DDUC_HOP_PERIOD_LO_REG_RESETVAL (0x00000000u)

/* HOP_TOTAL_INDICES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 hop_index : 11;
    Uint32 hop_period_19_16 : 4;
#else 
    Uint32 hop_period_19_16 : 4;
    Uint32 hop_index : 11;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG;

/*  */
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_PERIOD_19_16_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_PERIOD_19_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_PERIOD_19_16_RESETVAL (0x00000000u)

/* Total number of hop indices being using minus one. The hop index counter loops at this count value. */
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_INDEX_MASK (0x00007FF0u)
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_INDEX_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_HOP_INDEX_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_ADDR (0x000012B8u)
#define CSL_DFE_DDUC_HOP_TOTAL_INDICES_REG_RESETVAL (0x00000000u)

/* HOP_SYNC_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_delay : 16;
#else 
    Uint32 sync_delay : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_SYNC_DELAY_REG;

/* How many dduc if clocks delay the incoming hop_ssel sync before syncing hopper; if this is set to zero, and a hop_ssel sync arrives, then the hop_ssel sync will NOT trigger until this is set to a non-zero value. */
#define CSL_DFE_DDUC_HOP_SYNC_DELAY_REG_SYNC_DELAY_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_SYNC_DELAY_REG_SYNC_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_SYNC_DELAY_REG_SYNC_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_SYNC_DELAY_REG_ADDR (0x000012BCu)
#define CSL_DFE_DDUC_HOP_SYNC_DELAY_REG_RESETVAL (0x00000000u)

/* HOP_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 hi_ext_sync : 1;
    Uint32 hop_en : 1;
    Uint32 hop_ndata : 3;
#else 
    Uint32 hop_ndata : 3;
    Uint32 hop_en : 1;
    Uint32 hi_ext_sync : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_DDUC_HOP_CONFIG_REG;

/* Number of real streams per mixer minus 1 */
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_NDATA_MASK (0x00000007u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_NDATA_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_NDATA_RESETVAL (0x00000000u)

/* 1 to enable hopping; 0 uses MPU control to freq word RAMs */
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_EN_MASK (0x00000008u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_EN_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HOP_EN_RESETVAL (0x00000000u)

/* 1 to sync hop index on hop_hi_ssel sync with no delay, 0 to sync on hop_ssel sync with sync_delay */
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HI_EXT_SYNC_MASK (0x00000010u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HI_EXT_SYNC_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_HI_EXT_SYNC_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_CONFIG_REG_ADDR (0x000012C0u)
#define CSL_DFE_DDUC_HOP_CONFIG_REG_RESETVAL (0x00000000u)

/* SSEL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hop_ho_ssel : 4;
    Uint32 hop_hi_ssel : 4;
    Uint32 hop_ssel : 4;
    Uint32 pfir_coef_ssel : 4;
#else 
    Uint32 pfir_coef_ssel : 4;
    Uint32 hop_ssel : 4;
    Uint32 hop_hi_ssel : 4;
    Uint32 hop_ho_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SSEL0_REG;

/* PFIR coefficients sync select */
#define CSL_DFE_DDUC_SSEL0_REG_PFIR_COEF_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL0_REG_PFIR_COEF_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL0_REG_PFIR_COEF_SSEL_RESETVAL (0x00000000u)

/* hopper master sync select. This sync delays by sync_delay, then takes effect. If hop_en is high, it zeros time accumulator and hop period counter…in addition, it zeros hop index counter if hop_hi_ext_sync is low. If hop_en is low, then it swaps banks on the freq word memories (between active and shadow). */
#define CSL_DFE_DDUC_SSEL0_REG_HOP_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_SSEL_RESETVAL (0x00000000u)

/* zeros hop index counter if hop_hi_ext_sync is high (no delay) */
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HI_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HI_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HI_SSEL_RESETVAL (0x00000000u)

/* swaps halves of the hop offset swap ram */
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HO_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HO_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SSEL0_REG_HOP_HO_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL0_REG_ADDR (0x000012C4u)
#define CSL_DFE_DDUC_SSEL0_REG_RESETVAL (0x00000000u)

/* SSEL1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frw_chksum_ssel : 4;
    Uint32 frw_phase_ssel : 4;
    Uint32 cic_flush_ssel : 4;
    Uint32 mix_phase_ssel : 4;
#else 
    Uint32 mix_phase_ssel : 4;
    Uint32 cic_flush_ssel : 4;
    Uint32 frw_phase_ssel : 4;
    Uint32 frw_chksum_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SSEL1_REG;

/* mixer phase sync select for all mixers */
#define CSL_DFE_DDUC_SSEL1_REG_MIX_PHASE_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL1_REG_MIX_PHASE_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL1_REG_MIX_PHASE_SSEL_RESETVAL (0x00000000u)

/* sync to reset CIC's state machines; does NOT flush the CIC!! */
#define CSL_DFE_DDUC_SSEL1_REG_CIC_FLUSH_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL1_REG_CIC_FLUSH_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL1_REG_CIC_FLUSH_SSEL_RESETVAL (0x00000000u)

/* farrow phase word sync select to load new phase */
#define CSL_DFE_DDUC_SSEL1_REG_FRW_PHASE_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DDUC_SSEL1_REG_FRW_PHASE_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SSEL1_REG_FRW_PHASE_SSEL_RESETVAL (0x00000000u)

/* farrow check sum sync select (for both IF and BB check sums) */
#define CSL_DFE_DDUC_SSEL1_REG_FRW_CHKSUM_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DDUC_SSEL1_REG_FRW_CHKSUM_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SSEL1_REG_FRW_CHKSUM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL1_REG_ADDR (0x000012C8u)
#define CSL_DFE_DDUC_SSEL1_REG_RESETVAL (0x00000000u)

/* SSEL2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 selector_ssel : 4;
    Uint32 frw_sig_ssel : 4;
#else 
    Uint32 frw_sig_ssel : 4;
    Uint32 selector_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DDUC_SSEL2_REG;

/* sync to reset frw signal generator (for both IF and BB signal generators) */
#define CSL_DFE_DDUC_SSEL2_REG_FRW_SIG_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL2_REG_FRW_SIG_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL2_REG_FRW_SIG_SSEL_RESETVAL (0x00000000u)

/* sync to update selector registers */
#define CSL_DFE_DDUC_SSEL2_REG_SELECTOR_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL2_REG_SELECTOR_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL2_REG_SELECTOR_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL2_REG_ADDR (0x000012CCu)
#define CSL_DFE_DDUC_SSEL2_REG_RESETVAL (0x00000000u)

/* SSEL3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix3_nco_ssel : 4;
    Uint32 mix2_nco_ssel : 4;
    Uint32 mix1_nco_ssel : 4;
    Uint32 mix0_nco_ssel : 4;
#else 
    Uint32 mix0_nco_ssel : 4;
    Uint32 mix1_nco_ssel : 4;
    Uint32 mix2_nco_ssel : 4;
    Uint32 mix3_nco_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SSEL3_REG;

/* mixer0 channel 0 NCO accumulator sync…also syncs dither */
#define CSL_DFE_DDUC_SSEL3_REG_MIX0_NCO_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL3_REG_MIX0_NCO_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX0_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer0 channel 1 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL3_REG_MIX1_NCO_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX1_NCO_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX1_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer0 channel 2 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL3_REG_MIX2_NCO_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX2_NCO_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX2_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer0 channel 3 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL3_REG_MIX3_NCO_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DDUC_SSEL3_REG_MIX3_NCO_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SSEL3_REG_MIX3_NCO_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL3_REG_ADDR (0x000012D0u)
#define CSL_DFE_DDUC_SSEL3_REG_RESETVAL (0x00000000u)

/* SSEL4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix7_nco_ssel : 4;
    Uint32 mix6_nco_ssel : 4;
    Uint32 mix5_nco_ssel : 4;
    Uint32 mix4_nco_ssel : 4;
#else 
    Uint32 mix4_nco_ssel : 4;
    Uint32 mix5_nco_ssel : 4;
    Uint32 mix6_nco_ssel : 4;
    Uint32 mix7_nco_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SSEL4_REG;

/* mixer1 channel 0 NCO accumulator sync…also syncs dither */
#define CSL_DFE_DDUC_SSEL4_REG_MIX4_NCO_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL4_REG_MIX4_NCO_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX4_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer1 channel 1 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL4_REG_MIX5_NCO_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX5_NCO_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX5_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer1 channel 2 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL4_REG_MIX6_NCO_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX6_NCO_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX6_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer1 channel 3 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL4_REG_MIX7_NCO_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DDUC_SSEL4_REG_MIX7_NCO_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SSEL4_REG_MIX7_NCO_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL4_REG_ADDR (0x000012D4u)
#define CSL_DFE_DDUC_SSEL4_REG_RESETVAL (0x00000000u)

/* SSEL5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix11_nco_ssel : 4;
    Uint32 mix10_nco_ssel : 4;
    Uint32 mix9_nco_ssel : 4;
    Uint32 mix8_nco_ssel : 4;
#else 
    Uint32 mix8_nco_ssel : 4;
    Uint32 mix9_nco_ssel : 4;
    Uint32 mix10_nco_ssel : 4;
    Uint32 mix11_nco_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SSEL5_REG;

/* mixer2 channel 0 NCO accumulator sync…also syncs dither */
#define CSL_DFE_DDUC_SSEL5_REG_MIX8_NCO_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_SSEL5_REG_MIX8_NCO_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX8_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer2 channel 1 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL5_REG_MIX9_NCO_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX9_NCO_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX9_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer2 channel 2 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL5_REG_MIX10_NCO_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX10_NCO_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX10_NCO_SSEL_RESETVAL (0x00000000u)

/* mixer2 channel 3 NCO accumulator sync */
#define CSL_DFE_DDUC_SSEL5_REG_MIX11_NCO_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DDUC_SSEL5_REG_MIX11_NCO_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SSEL5_REG_MIX11_NCO_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SSEL5_REG_ADDR (0x000012D8u)
#define CSL_DFE_DDUC_SSEL5_REG_RESETVAL (0x00000000u)

/* TEST_BUS_MUX_ICG_DLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 init_clk_gate_delay_4_0 : 5;
    Uint32 rsvd0 : 2;
    Uint32 test_bus_mux : 9;
#else 
    Uint32 test_bus_mux : 9;
    Uint32 rsvd0 : 2;
    Uint32 init_clk_gate_delay_4_0 : 5;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG;

/* test bus mux for DDUC; should be set to 0 if not observing a dduc signal */
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_TEST_BUS_MUX_MASK (0x000001FFu)
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_TEST_BUS_MUX_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_TEST_BUS_MUX_RESETVAL (0x00000000u)

/* delay value for init_clk_gate delay */
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_INIT_CLK_GATE_DELAY_4_0_MASK (0x0000F800u)
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_INIT_CLK_GATE_DELAY_4_0_SHIFT (0x0000000Bu)
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_INIT_CLK_GATE_DELAY_4_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_ADDR (0x000012DCu)
#define CSL_DFE_DDUC_TEST_BUS_MUX_ICG_DLY_REG_RESETVAL (0x00000000u)

/* TEST_BUS_BB_MUX */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 test_bus_bb_mux : 9;
#else 
    Uint32 test_bus_bb_mux : 9;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG;

/* mux for baseband test bus */
#define CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG_TEST_BUS_BB_MUX_MASK (0x000001FFu)
#define CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG_TEST_BUS_BB_MUX_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG_TEST_BUS_BB_MUX_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG_ADDR (0x000012E0u)
#define CSL_DFE_DDUC_TEST_BUS_BB_MUX_REG_RESETVAL (0x00000000u)

/* SELECTOR_MIX0_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix0chan3_rx_sel : 2;
    Uint32 mix0chan3_chan_sel : 2;
    Uint32 mix0chan2_rx_sel : 2;
    Uint32 mix0chan2_chan_sel : 2;
    Uint32 mix0chan1_rx_sel : 2;
    Uint32 mix0chan1_chan_sel : 2;
    Uint32 mix0chan0_rx_sel : 2;
    Uint32 mix0chan0_chan_sel : 2;
#else 
    Uint32 mix0chan0_chan_sel : 2;
    Uint32 mix0chan0_rx_sel : 2;
    Uint32 mix0chan1_chan_sel : 2;
    Uint32 mix0chan1_rx_sel : 2;
    Uint32 mix0chan2_chan_sel : 2;
    Uint32 mix0chan2_rx_sel : 2;
    Uint32 mix0chan3_chan_sel : 2;
    Uint32 mix0chan3_rx_sel : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG;

/* in receive mode, which channel from selected RX to use for mixer0 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_CHAN_SEL_MASK (0x00000003u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer0 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_RX_SEL_MASK (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_RX_SEL_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN0_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer0 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_CHAN_SEL_MASK (0x00000030u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_CHAN_SEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer0 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_RX_SEL_MASK (0x000000C0u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_RX_SEL_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN1_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer0 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_CHAN_SEL_MASK (0x00000300u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_CHAN_SEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer0 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_RX_SEL_MASK (0x00000C00u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_RX_SEL_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN2_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer0 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_CHAN_SEL_MASK (0x00003000u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_CHAN_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer0 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_RX_SEL_MASK (0x0000C000u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_RX_SEL_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_MIX0CHAN3_RX_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_ADDR (0x000012E4u)
#define CSL_DFE_DDUC_SELECTOR_MIX0_SEL_REG_RESETVAL (0x00000000u)

/* SELECTOR_MIX1_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix1chan3_rx_sel : 2;
    Uint32 mix1chan3_chan_sel : 2;
    Uint32 mix1chan2_rx_sel : 2;
    Uint32 mix1chan2_chan_sel : 2;
    Uint32 mix1chan1_rx_sel : 2;
    Uint32 mix1chan1_chan_sel : 2;
    Uint32 mix1chan0_rx_sel : 2;
    Uint32 mix1chan0_chan_sel : 2;
#else 
    Uint32 mix1chan0_chan_sel : 2;
    Uint32 mix1chan0_rx_sel : 2;
    Uint32 mix1chan1_chan_sel : 2;
    Uint32 mix1chan1_rx_sel : 2;
    Uint32 mix1chan2_chan_sel : 2;
    Uint32 mix1chan2_rx_sel : 2;
    Uint32 mix1chan3_chan_sel : 2;
    Uint32 mix1chan3_rx_sel : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG;

/* in receive mode, which channel from selected RX to use for mixer1 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_CHAN_SEL_MASK (0x00000003u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer1 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_RX_SEL_MASK (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_RX_SEL_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN0_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer1 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_CHAN_SEL_MASK (0x00000030u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_CHAN_SEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer1 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_RX_SEL_MASK (0x000000C0u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_RX_SEL_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN1_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer1 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_CHAN_SEL_MASK (0x00000300u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_CHAN_SEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer1 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_RX_SEL_MASK (0x00000C00u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_RX_SEL_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN2_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer1 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_CHAN_SEL_MASK (0x00003000u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_CHAN_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer1 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_RX_SEL_MASK (0x0000C000u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_RX_SEL_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_MIX1CHAN3_RX_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_ADDR (0x000012E8u)
#define CSL_DFE_DDUC_SELECTOR_MIX1_SEL_REG_RESETVAL (0x00000000u)

/* SELECTOR_MIX2_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mix2chan3_rx_sel : 2;
    Uint32 mix2chan3_chan_sel : 2;
    Uint32 mix2chan2_rx_sel : 2;
    Uint32 mix2chan2_chan_sel : 2;
    Uint32 mix2chan1_rx_sel : 2;
    Uint32 mix2chan1_chan_sel : 2;
    Uint32 mix2chan0_rx_sel : 2;
    Uint32 mix2chan0_chan_sel : 2;
#else 
    Uint32 mix2chan0_chan_sel : 2;
    Uint32 mix2chan0_rx_sel : 2;
    Uint32 mix2chan1_chan_sel : 2;
    Uint32 mix2chan1_rx_sel : 2;
    Uint32 mix2chan2_chan_sel : 2;
    Uint32 mix2chan2_rx_sel : 2;
    Uint32 mix2chan3_chan_sel : 2;
    Uint32 mix2chan3_rx_sel : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG;

/* in receive mode, which channel from selected RX to use for mixer2 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_CHAN_SEL_MASK (0x00000003u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer2 channel 0 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_RX_SEL_MASK (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_RX_SEL_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN0_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer2 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_CHAN_SEL_MASK (0x00000030u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_CHAN_SEL_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer2 channel 1 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_RX_SEL_MASK (0x000000C0u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_RX_SEL_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN1_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer2 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_CHAN_SEL_MASK (0x00000300u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_CHAN_SEL_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer2 channel 2 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_RX_SEL_MASK (0x00000C00u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_RX_SEL_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN2_RX_SEL_RESETVAL (0x00000000u)

/* in receive mode, which channel from selected RX to use for mixer2 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_CHAN_SEL_MASK (0x00003000u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_CHAN_SEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_CHAN_SEL_RESETVAL (0x00000000u)

/* in receive mode, which RX to use for mixer2 channel 3 */
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_RX_SEL_MASK (0x0000C000u)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_RX_SEL_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_MIX2CHAN3_RX_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_ADDR (0x000012ECu)
#define CSL_DFE_DDUC_SELECTOR_MIX2_SEL_REG_RESETVAL (0x00000000u)

/* PFIR_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 n_fir_coef_m1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 delay_len_m1 : 6;
#else 
    Uint32 delay_len_m1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 n_fir_coef_m1 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_DDUC_PFIR_CONFIG0_REG;

/* length of delay ram - 1 */
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_DELAY_LEN_M1_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_DELAY_LEN_M1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_DELAY_LEN_M1_RESETVAL (0x00000000u)

/* number of samples - 1 */
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_N_FIR_COEF_M1_MASK (0x00003F00u)
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_N_FIR_COEF_M1_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_N_FIR_COEF_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_ADDR (0x00001300u)
#define CSL_DFE_DDUC_PFIR_CONFIG0_REG_RESETVAL (0x00000000u)

/* PFIR_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 17;
    Uint32 turn_offset : 7;
    Uint32 rsvd0 : 2;
    Uint32 fwd_offset : 6;
#else 
    Uint32 fwd_offset : 6;
    Uint32 rsvd0 : 2;
    Uint32 turn_offset : 7;
    Uint32 rsvd1 : 17;
#endif 
} CSL_DFE_DDUC_PFIR_CONFIG1_REG;

/* offset from read address to write new fwd data */
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_FWD_OFFSET_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_FWD_OFFSET_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_FWD_OFFSET_RESETVAL (0x00000000u)

/* offset from read address to write new turn data */
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_TURN_OFFSET_MASK (0x00007F00u)
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_TURN_OFFSET_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_TURN_OFFSET_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_ADDR (0x00001304u)
#define CSL_DFE_DDUC_PFIR_CONFIG1_REG_RESETVAL (0x00000000u)

/* PFIR_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 17;
    Uint32 real : 1;
    Uint32 dec2 : 1;
    Uint32 int2 : 1;
    Uint32 rsvd0 : 1;
    Uint32 all_valid : 1;
    Uint32 ch1i2 : 1;
    Uint32 real1 : 1;
    Uint32 fir_interpolate : 1;
    Uint32 shift_fir_output : 3;
    Uint32 num_fir_channels_m1 : 4;
#else 
    Uint32 num_fir_channels_m1 : 4;
    Uint32 shift_fir_output : 3;
    Uint32 fir_interpolate : 1;
    Uint32 real1 : 1;
    Uint32 ch1i2 : 1;
    Uint32 all_valid : 1;
    Uint32 rsvd0 : 1;
    Uint32 int2 : 1;
    Uint32 dec2 : 1;
    Uint32 real : 1;
    Uint32 rsvd1 : 17;
#endif 
} CSL_DFE_DDUC_PFIR_CONFIG2_REG;

/* number of data that each coef dwells for  - 1  */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_NUM_FIR_CHANNELS_M1_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_NUM_FIR_CHANNELS_M1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_NUM_FIR_CHANNELS_M1_RESETVAL (0x00000000u)

/* adjusts gain through pfir; gain is: */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_SHIFT_FIR_OUTPUT_MASK (0x00000070u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_SHIFT_FIR_OUTPUT_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_SHIFT_FIR_OUTPUT_RESETVAL (0x00000000u)

/* 1 = tx; 0 = rx */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_FIR_INTERPOLATE_MASK (0x00000080u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_FIR_INTERPOLATE_SHIFT (0x00000007u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_FIR_INTERPOLATE_RESETVAL (0x00000000u)

/* special case:  1 if real mode with 1 tap filter */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL1_MASK (0x00000100u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL1_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL1_RESETVAL (0x00000000u)

/* special case:  1 if 1 channel, interpolating by 2 and 2 tap filter */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_CH1I2_MASK (0x00000200u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_CH1I2_SHIFT (0x00000009u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_CH1I2_RESETVAL (0x00000000u)

/* special case:  1 if 1 channel and delay_len is 1 (all output is always valid in this configuration) */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_ALL_VALID_MASK (0x00000400u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_ALL_VALID_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_ALL_VALID_RESETVAL (0x00000000u)

/* 1 if in int by 2 mode */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_INT2_MASK (0x00001000u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_INT2_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_INT2_RESETVAL (0x00000000u)

/* 1 if in dec by 2 mode */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_DEC2_MASK (0x00002000u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_DEC2_SHIFT (0x0000000Du)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_DEC2_RESETVAL (0x00000000u)

/* 1 if in real mode */
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL_MASK (0x00004000u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_REAL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_ADDR (0x00001308u)
#define CSL_DFE_DDUC_PFIR_CONFIG2_REG_RESETVAL (0x00000000u)

/* PFIR_COEF_OFFSET0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 coef_offset3 : 4;
    Uint32 coef_offset2 : 4;
    Uint32 coef_offset1 : 4;
    Uint32 coef_offset0 : 4;
#else 
    Uint32 coef_offset0 : 4;
    Uint32 coef_offset1 : 4;
    Uint32 coef_offset2 : 4;
    Uint32 coef_offset3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG;

/* coefficient offset for the last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 7). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET0_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET0_RESETVAL (0x00000000u)

/* coefficient offset for the 2nd-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 6). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET1_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET1_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET1_RESETVAL (0x00000000u)

/* coefficient offset for the 3rd-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 5). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET2_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET2_RESETVAL (0x00000000u)

/* coefficient offset for the 4th-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 4). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET3_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET3_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_COEF_OFFSET3_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_ADDR (0x0000130Cu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET0_REG_RESETVAL (0x00000000u)

/* PFIR_COEF_OFFSET1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 coef_offset7 : 4;
    Uint32 coef_offset6 : 4;
    Uint32 coef_offset5 : 4;
    Uint32 coef_offset4 : 4;
#else 
    Uint32 coef_offset4 : 4;
    Uint32 coef_offset5 : 4;
    Uint32 coef_offset6 : 4;
    Uint32 coef_offset7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG;

/* coefficient offset for the 5th-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 3). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET4_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET4_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET4_RESETVAL (0x00000000u)

/* coefficient offset for the 6th-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 2). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET5_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET5_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET5_RESETVAL (0x00000000u)

/* coefficient offset for the 7th-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 1). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET6_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET6_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET6_RESETVAL (0x00000000u)

/* coefficient offset for the 8th-to-last channel (if there are 8 channels numbered 0 to 7, this is the offset for channel 0). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET7_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET7_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_COEF_OFFSET7_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_ADDR (0x00001310u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET1_REG_RESETVAL (0x00000000u)

/* PFIR_COEF_OFFSET2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 coef_offset11 : 4;
    Uint32 coef_offset10 : 4;
    Uint32 coef_offset9 : 4;
    Uint32 coef_offset8 : 4;
#else 
    Uint32 coef_offset8 : 4;
    Uint32 coef_offset9 : 4;
    Uint32 coef_offset10 : 4;
    Uint32 coef_offset11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG;

/* coefficient offset for the 9th-to-last channel (if there are 8 channels numbered 0 to 7, this value would be unused). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET8_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET8_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET8_RESETVAL (0x00000000u)

/* coefficient offset for the 10th-to-last channel (if there are 8 channels numbered 0 to 7, this value would be unused). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET9_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET9_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET9_RESETVAL (0x00000000u)

/* coefficient offset for the 11th-to-last channel (if there are 8 channels numbered 0 to 7, this value would be unused). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET10_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET10_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET10_RESETVAL (0x00000000u)

/* coefficient offset for the 12th-to-last channel (if there are 8 channels numbered 0 to 7, this value would be unused). This offset determines which coefficient bank is used for this channel. */
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET11_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET11_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_COEF_OFFSET11_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_ADDR (0x00001314u)
#define CSL_DFE_DDUC_PFIR_COEF_OFFSET2_REG_RESETVAL (0x00000000u)

/* PFIR_FCMUX0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fcmux3 : 4;
    Uint32 fcmux2 : 4;
    Uint32 fcmux1 : 4;
    Uint32 fcmux0 : 4;
#else 
    Uint32 fcmux0 : 4;
    Uint32 fcmux1 : 4;
    Uint32 fcmux2 : 4;
    Uint32 fcmux3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_FCMUX0_REG;

/* fcmux value for last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX0_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX0_RESETVAL (0x00000000u)

/* fcmux value for 2nd-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX1_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX1_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX1_RESETVAL (0x00000000u)

/* fcmux value for 3rd-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX2_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX2_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX2_RESETVAL (0x00000000u)

/* fcmux value for 4th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX3_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX3_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_FCMUX3_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_ADDR (0x00001318u)
#define CSL_DFE_DDUC_PFIR_FCMUX0_REG_RESETVAL (0x00000000u)

/* PFIR_FCMUX1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fcmux7 : 4;
    Uint32 fcmux6 : 4;
    Uint32 fcmux5 : 4;
    Uint32 fcmux4 : 4;
#else 
    Uint32 fcmux4 : 4;
    Uint32 fcmux5 : 4;
    Uint32 fcmux6 : 4;
    Uint32 fcmux7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_FCMUX1_REG;

/* fcmux value for 5th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX4_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX4_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX4_RESETVAL (0x00000000u)

/* fcmux value for 6th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX5_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX5_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX5_RESETVAL (0x00000000u)

/* fcmux value for 7th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX6_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX6_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX6_RESETVAL (0x00000000u)

/* fcmux value for 8th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX7_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX7_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_FCMUX7_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_ADDR (0x0000131Cu)
#define CSL_DFE_DDUC_PFIR_FCMUX1_REG_RESETVAL (0x00000000u)

/* PFIR_FCMUX2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 fcmux11 : 4;
    Uint32 fcmux10 : 4;
    Uint32 fcmux9 : 4;
    Uint32 fcmux8 : 4;
#else 
    Uint32 fcmux8 : 4;
    Uint32 fcmux9 : 4;
    Uint32 fcmux10 : 4;
    Uint32 fcmux11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_FCMUX2_REG;

/* fcmux value for 9th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX8_MASK (0x0000000Fu)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX8_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX8_RESETVAL (0x00000000u)

/* fcmux value for 10th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX9_MASK (0x000000F0u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX9_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX9_RESETVAL (0x00000000u)

/* fcmux value for 11th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX10_MASK (0x00000F00u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX10_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX10_RESETVAL (0x00000000u)

/* fcmux value for 12th-to-last channel; used to shorten filter */
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX11_MASK (0x0000F000u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX11_SHIFT (0x0000000Cu)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_FCMUX11_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_ADDR (0x00001320u)
#define CSL_DFE_DDUC_PFIR_FCMUX2_REG_RESETVAL (0x00000000u)

/* PFIR_PCSYM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pcsym11 : 1;
    Uint32 pcsym10 : 1;
    Uint32 pcsym9 : 1;
    Uint32 pcsym8 : 1;
    Uint32 pcsym7 : 1;
    Uint32 pcsym6 : 1;
    Uint32 pcsym5 : 1;
    Uint32 pcsym4 : 1;
    Uint32 pcsym3 : 1;
    Uint32 pcsym2 : 1;
    Uint32 pcsym1 : 1;
    Uint32 pcsym0 : 1;
#else 
    Uint32 pcsym0 : 1;
    Uint32 pcsym1 : 1;
    Uint32 pcsym2 : 1;
    Uint32 pcsym3 : 1;
    Uint32 pcsym4 : 1;
    Uint32 pcsym5 : 1;
    Uint32 pcsym6 : 1;
    Uint32 pcsym7 : 1;
    Uint32 pcsym8 : 1;
    Uint32 pcsym9 : 1;
    Uint32 pcsym10 : 1;
    Uint32 pcsym11 : 1;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_DDUC_PFIR_PCSYM_REG;

/* 1 for symmetry on for last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM0_MASK (0x00000001u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM0_RESETVAL (0x00000000u)

/* 1 for symmetry on for 2nd-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM1_MASK (0x00000002u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM1_SHIFT (0x00000001u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM1_RESETVAL (0x00000000u)

/* 1 for symmetry on for 3rd-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM2_MASK (0x00000004u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM2_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM2_RESETVAL (0x00000000u)

/* 1 for symmetry on for 4th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM3_MASK (0x00000008u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM3_SHIFT (0x00000003u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM3_RESETVAL (0x00000000u)

/* 1 for symmetry on for 5th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM4_MASK (0x00000010u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM4_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM4_RESETVAL (0x00000000u)

/* 1 for symmetry on for 6th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM5_MASK (0x00000020u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM5_SHIFT (0x00000005u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM5_RESETVAL (0x00000000u)

/* 1 for symmetry on for 7th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM6_MASK (0x00000040u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM6_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM6_RESETVAL (0x00000000u)

/* 1 for symmetry on for 8th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM7_MASK (0x00000080u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM7_SHIFT (0x00000007u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM7_RESETVAL (0x00000000u)

/* 1 for symmetry on for 9th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM8_MASK (0x00000100u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM8_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM8_RESETVAL (0x00000000u)

/* 1 for symmetry on for 10th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM9_MASK (0x00000200u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM9_SHIFT (0x00000009u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM9_RESETVAL (0x00000000u)

/* 1 for symmetry on for 11th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM10_MASK (0x00000400u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM10_SHIFT (0x0000000Au)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM10_RESETVAL (0x00000000u)

/* 1 for symmetry on for 12th-to-last channel; 0 for no symmetry */
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM11_MASK (0x00000800u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM11_SHIFT (0x0000000Bu)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_PCSYM11_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_PCSYM_REG_ADDR (0x00001324u)
#define CSL_DFE_DDUC_PFIR_PCSYM_REG_RESETVAL (0x00000000u)

/* FRW_TIME_STEP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_15_0 : 16;
#else 
    Uint32 time_step_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG;

/* time step word in frw. Amount to increment accumulator each IF clock. Is a function of the interpolation or decimation ratio. If interpolating, equals 2^31 * decimation/interpolation. If decimating, equals 2^31 * interpolation/decimation */
#define CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG_TIME_STEP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG_TIME_STEP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG_TIME_STEP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG_ADDR (0x00001340u)
#define CSL_DFE_DDUC_FRW_TIME_STEP_LO_REG_RESETVAL (0x00000000u)

/* FRW_TIME_STEP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_31_16 : 16;
#else 
    Uint32 time_step_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG;

/*  */
#define CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG_TIME_STEP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG_TIME_STEP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG_TIME_STEP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG_ADDR (0x00001344u)
#define CSL_DFE_DDUC_FRW_TIME_STEP_HI_REG_RESETVAL (0x00000000u)

/* FRW_RESET_INT_M1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int_m1_15_0 : 16;
#else 
    Uint32 reset_int_m1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG;

/* time accumulator reset interval minus 1. Interval (minus 1) at which the accumulation word should reset itself if reset_en; should equal the interpolation factor minus 1 if interpolating, or the decimation factor minus 1 if decimating. */
#define CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG_RESET_INT_M1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG_RESET_INT_M1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG_RESET_INT_M1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG_ADDR (0x00001348u)
#define CSL_DFE_DDUC_FRW_RESET_INT_M1_LO_REG_RESETVAL (0x00000000u)

/* FRW_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 int_mode : 1;
    Uint32 reset_en : 1;
    Uint32 num_real_streams_m1 : 5;
    Uint32 reset_int_m1_23_16 : 8;
#else 
    Uint32 reset_int_m1_23_16 : 8;
    Uint32 num_real_streams_m1 : 5;
    Uint32 reset_en : 1;
    Uint32 int_mode : 1;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_DDUC_FRW_CONFIG0_REG;

/*  */
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_INT_M1_23_16_MASK (0x000000FFu)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_INT_M1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_INT_M1_23_16_RESETVAL (0x00000000u)

/* Number of real streams (a complex channel has 2 real streams) minus 1. If 0, then it is in one-channel real mode.  */
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_NUM_REAL_STREAMS_M1_MASK (0x00001F00u)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_NUM_REAL_STREAMS_M1_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_NUM_REAL_STREAMS_M1_RESETVAL (0x00000000u)

/* 1 to enable time accumulator reset. 0 to never reset. Enables auto-reset of the accumulation word; needed if the interpolation factor can not be perfectly expressed in time_step. */
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_EN_MASK (0x00002000u)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_EN_SHIFT (0x0000000Du)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESET_EN_RESETVAL (0x00000000u)

/* 1 if in DUC mode (interpolate), 0 if in DDC mode (decimate) */
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_INT_MODE_MASK (0x00004000u)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_INT_MODE_SHIFT (0x0000000Eu)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_INT_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_CONFIG0_REG_ADDR (0x0000134Cu)
#define CSL_DFE_DDUC_FRW_CONFIG0_REG_RESETVAL (0x00000000u)

/* FRW_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 id_shift : 4;
    Uint32 two : 1;
    Uint32 one : 1;
    Uint32 nch : 5;
#else 
    Uint32 nch : 5;
    Uint32 one : 1;
    Uint32 two : 1;
    Uint32 id_shift : 4;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_DDUC_FRW_CONFIG1_REG;

/* Number of real streams minus 3. Set to 0 if 1 or 2 streams (used by delay ram addressing) */
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_NCH_MASK (0x0000001Fu)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_NCH_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_NCH_RESETVAL (0x00000000u)

/* High to delay by one in delay ram addressing */
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ONE_MASK (0x00000020u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ONE_SHIFT (0x00000005u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ONE_RESETVAL (0x00000000u)

/* High to delay by two in delay ram addressing */
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_TWO_MASK (0x00000040u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_TWO_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_TWO_RESETVAL (0x00000000u)

/* Receive accumulator shift value (0-10). Amount to shift left the decimation mode’s polynomial accumulators prior to rounding it to go into the FIFO...the rounder will round off 10-id_shift bits (rounding off 0 bits is unity gain). Ignored in interpolation mode. Final gain through frw is ultimately: */
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ID_SHIFT_MASK (0x00000780u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ID_SHIFT_SHIFT (0x00000007u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ID_SHIFT_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_CONFIG1_REG_ADDR (0x00001350u)
#define CSL_DFE_DDUC_FRW_CONFIG1_REG_RESETVAL (0x00000000u)

/* FRW_SIG_INIT_VAL_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sig_init_val_15_0 : 16;
#else 
    Uint32 sig_init_val_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG;

/* Initial value for signal generators in ramp mode (affects both IF and BB signal generators) */
#define CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG_SIG_INIT_VAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG_SIG_INIT_VAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG_SIG_INIT_VAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG_ADDR (0x00001354u)
#define CSL_DFE_DDUC_FRW_SIG_INIT_VAL_LO_REG_RESETVAL (0x00000000u)

/* FRW_SIG_INC_VAL_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sig_inc_val_15_0 : 16;
#else 
    Uint32 sig_inc_val_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG;

/* Increment value for signal generators in ramp mode (affects both IF and BB signal generators) */
#define CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG_SIG_INC_VAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG_SIG_INC_VAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG_SIG_INC_VAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG_ADDR (0x00001358u)
#define CSL_DFE_DDUC_FRW_SIG_INC_VAL_LO_REG_RESETVAL (0x00000000u)

/* FRW_SIG_CFG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 22;
    Uint32 sig_en : 1;
    Uint32 sig_lfsr_mode : 1;
    Uint32 rsvd1 : 1;
    Uint32 sig_inc_val_18_16 : 3;
    Uint32 rsvd0 : 1;
    Uint32 sig_init_val_18_16 : 3;
#else 
    Uint32 sig_init_val_18_16 : 3;
    Uint32 rsvd0 : 1;
    Uint32 sig_inc_val_18_16 : 3;
    Uint32 rsvd1 : 1;
    Uint32 sig_lfsr_mode : 1;
    Uint32 sig_en : 1;
    Uint32 rsvd2 : 22;
#endif 
} CSL_DFE_DDUC_FRW_SIG_CFG_REG;

/*  */
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INIT_VAL_18_16_MASK (0x00000007u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INIT_VAL_18_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INIT_VAL_18_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INC_VAL_18_16_MASK (0x00000070u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INC_VAL_18_16_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_INC_VAL_18_16_RESETVAL (0x00000000u)

/* 1 for signal generators to be in lfsr mode, 0 for ramp mode (affects both IF and BB signal generators) */
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_LFSR_MODE_MASK (0x00000100u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_LFSR_MODE_SHIFT (0x00000008u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_LFSR_MODE_RESETVAL (0x00000000u)

/* 1 to enable signal generators, 0 to disable (in xmt mode, affects IF generator. In rcv mode, affects BB generator. Unused one is always disabled) */
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_EN_MASK (0x00000200u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_EN_SHIFT (0x00000009u)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_SIG_EN_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_ADDR (0x0000135Cu)
#define CSL_DFE_DDUC_FRW_SIG_CFG_REG_RESETVAL (0x00000000u)

/* FRW_CHKSUM_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 chksum_15_0 : 16;
#else 
    Uint32 chksum_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_CHKSUM_LO_REG;

/* checksum from signature analyzer. In xmt mode, reads BB checksum. In rcv, reads IF checksum. */
#define CSL_DFE_DDUC_FRW_CHKSUM_LO_REG_CHKSUM_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_CHKSUM_LO_REG_CHKSUM_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_CHKSUM_LO_REG_CHKSUM_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_CHKSUM_LO_REG_ADDR (0x00001360u)
#define CSL_DFE_DDUC_FRW_CHKSUM_LO_REG_RESETVAL (0x00000000u)

/* FRW_CHKSUM_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 chksum_31_16 : 16;
#else 
    Uint32 chksum_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_CHKSUM_HI_REG;

/*  */
#define CSL_DFE_DDUC_FRW_CHKSUM_HI_REG_CHKSUM_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_CHKSUM_HI_REG_CHKSUM_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_CHKSUM_HI_REG_CHKSUM_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_CHKSUM_HI_REG_ADDR (0x00001364u)
#define CSL_DFE_DDUC_FRW_CHKSUM_HI_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 rsvd0 : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_ADDR (0x00001380u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_CONFIG_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG_ADDR (0x00001384u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG_ADDR (0x00001388u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG_ADDR (0x0000138Cu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG_ADDR (0x00001390u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_ADDR (0x00001394u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_ADDR (0x00001398u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TX_SIGNAL_GEN_PULSE_WIDTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pulse_width : 16;
#else 
    Uint32 pulse_width : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG_ADDR (0x0000139Cu)
#define CSL_DFE_DDUC_TX_SIGNAL_GEN_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 rsvd0 : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_ADDR (0x000013A4u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_CONFIG_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG_ADDR (0x000013A8u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG_ADDR (0x000013ACu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG_ADDR (0x000013B0u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG_ADDR (0x000013B4u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_ADDR (0x000013B8u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_ADDR (0x000013BCu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* RX_SIGNAL_GEN_PULSE_WIDTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pulse_width : 16;
#else 
    Uint32 pulse_width : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG_ADDR (0x000013C0u)
#define CSL_DFE_DDUC_RX_SIGNAL_GEN_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

/* TX_CHECK_SUM_CONFIG */
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
} CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG;

/* 1 = return latency, 0 = return check sum */
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_MODE_RESETVAL (0x00000000u)

/* in latency mode, clocks that data must remain stable after pulse */
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_ADDR (0x000013C8u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CONFIG_REG_RESETVAL (0x00000000u)

/* TX_CHECK_SUM_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG;

/* in latency mode, width of data pulse from signal_gen */
#define CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG_ADDR (0x000013CCu)
#define CSL_DFE_DDUC_TX_CHECK_SUM_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* TX_CHECK_SUM_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG;

/* in latency mode, channel select specified by clocks after frame */
#define CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG_ADDR (0x000013D0u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* TX_CHECK_SUM_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG_ADDR (0x000013D4u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_LO_REG_RESETVAL (0x00000000u)

/* TX_CHECK_SUM_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG_ADDR (0x000013D8u)
#define CSL_DFE_DDUC_TX_CHECK_SUM_RESULT_HI_REG_RESETVAL (0x00000000u)

/* RX_CHECK_SUM_CONFIG */
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
} CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG;

/* 1 = return latency, 0 = return check sum */
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_MODE_RESETVAL (0x00000000u)

/* in latency mode, clocks that data must remain stable after pulse */
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_ADDR (0x000013DCu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CONFIG_REG_RESETVAL (0x00000000u)

/* RX_CHECK_SUM_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG;

/* in latency mode, width of data pulse from signal_gen */
#define CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG_ADDR (0x000013E0u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* RX_CHECK_SUM_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG;

/* in latency mode, channel select specified by clocks after frame */
#define CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG_ADDR (0x000013E4u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* RX_CHECK_SUM_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG_ADDR (0x000013E8u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_LO_REG_RESETVAL (0x00000000u)

/* RX_CHECK_SUM_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG_ADDR (0x000013ECu)
#define CSL_DFE_DDUC_RX_CHECK_SUM_RESULT_HI_REG_RESETVAL (0x00000000u)

/* PFIR_COEF_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 coef_15_0 : 16;
#else 
    Uint32 coef_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_PFIR_COEF_LO_REG;

/* coefficient tap memory, split into banks */
#define CSL_DFE_DDUC_PFIR_COEF_LO_REG_COEF_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_PFIR_COEF_LO_REG_COEF_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_COEF_LO_REG_COEF_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_COEF_LO_REG_ADDR (0x00040000u)
#define CSL_DFE_DDUC_PFIR_COEF_LO_REG_RESETVAL (0x00000000u)

/* PFIR_COEF_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 coef_17_16 : 2;
#else 
    Uint32 coef_17_16 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_DDUC_PFIR_COEF_HI_REG;

/*  */
#define CSL_DFE_DDUC_PFIR_COEF_HI_REG_COEF_17_16_MASK (0x00000003u)
#define CSL_DFE_DDUC_PFIR_COEF_HI_REG_COEF_17_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_PFIR_COEF_HI_REG_COEF_17_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_PFIR_COEF_HI_REG_ADDR (0x00040004u)
#define CSL_DFE_DDUC_PFIR_COEF_HI_REG_RESETVAL (0x00000000u)

/* HOP_HOP2FREQ_TBL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 hop_to_index_2i_1 : 6;
    Uint32 hop_to_index_2i : 6;
#else 
    Uint32 hop_to_index_2i : 6;
    Uint32 hop_to_index_2i_1 : 6;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG;

/* hop index to freq index mapping table, even values */
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_MASK (0x0000003Fu)
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_RESETVAL (0x00000000u)

/* hop index to freq index mapping table, odd values */
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_1_MASK (0x00000FC0u)
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_1_SHIFT (0x00000006u)
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_HOP_TO_INDEX_2I_1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_ADDR (0x00042000u)
#define CSL_DFE_DDUC_HOP_HOP2FREQ_TBL_REG_RESETVAL (0x00000000u)

/* HOP_FREQ2WORD_TBL_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_index_to_word_15_0 : 16;
#else 
    Uint32 freq_index_to_word_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG;

/* freq index to freq word mapping table */
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG_FREQ_INDEX_TO_WORD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG_FREQ_INDEX_TO_WORD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG_FREQ_INDEX_TO_WORD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG_ADDR (0x00043000u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_LO_REG_RESETVAL (0x00000000u)

/* HOP_FREQ2WORD_TBL_MID */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_index_to_word_31_16 : 16;
#else 
    Uint32 freq_index_to_word_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG;

/*  */
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG_FREQ_INDEX_TO_WORD_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG_FREQ_INDEX_TO_WORD_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG_FREQ_INDEX_TO_WORD_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG_ADDR (0x00043004u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_MID_REG_RESETVAL (0x00000000u)

/* HOP_FREQ2WORD_TBL_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_index_to_word_47_32 : 16;
#else 
    Uint32 freq_index_to_word_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG;

/*  */
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG_FREQ_INDEX_TO_WORD_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG_FREQ_INDEX_TO_WORD_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG_FREQ_INDEX_TO_WORD_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG_ADDR (0x00043008u)
#define CSL_DFE_DDUC_HOP_FREQ2WORD_TBL_HI_REG_RESETVAL (0x00000000u)

/* HOP_OFFSET_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 hop_offset_swap_bank_0 : 11;
#else 
    Uint32 hop_offset_swap_bank_0 : 11;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG;

/* hopper delay offset for each channel for bank 0; when mem_mpu_access is low, this address will write to the inactive bank. Address 0-3 go to mixer 0 (highest numbered carrier to lowest-numbered carrier). 4-7 go to mixer 1 and 8-11 go to mixer 2. */
#define CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG_HOP_OFFSET_SWAP_BANK_0_MASK (0x000007FFu)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG_HOP_OFFSET_SWAP_BANK_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG_HOP_OFFSET_SWAP_BANK_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG_ADDR (0x00043400u)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_OFFSET_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 hop_offset_swap_bank_1 : 11;
#else 
    Uint32 hop_offset_swap_bank_1 : 11;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG;

/* hopper delay offset for each channel for bank 1; when mem_mpu_access is low this address will write to the inactive bank. Address 0-3 go to mixer 0 (highest numbered carrier to lowest-numbered carrier). 4-7 go to mixer 1 and 8-11 go to mixer 2. */
#define CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG_HOP_OFFSET_SWAP_BANK_1_MASK (0x000007FFu)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG_HOP_OFFSET_SWAP_BANK_1_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG_HOP_OFFSET_SWAP_BANK_1_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG_ADDR (0x00043404u)
#define CSL_DFE_DDUC_HOP_OFFSET_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_LO_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_0_3_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_0_0_3_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG;

/* freq word table for bank 0 in mixer0, w/the highest channel in 1st address (channels 3, 2, 1 and 0 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG_ADDR (0x00043480u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_LO_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_0_3_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_1_0_3_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG;

/* freq word table for bank 1 in mixer0, w/the highest channel in 1st address (channels 3, 2, 1 and 0 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG_ADDR (0x00043484u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_LO_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_MID_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_0_3_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_0_0_3_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG_ADDR (0x000434A0u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_MID_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_0_3_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_1_0_3_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG_ADDR (0x000434A4u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_MID_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_HI_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_0_3_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_0_0_3_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_0_3_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG_ADDR (0x000434C0u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX0_FREQ_WORD_HI_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_0_3_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_1_0_3_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_0_3_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG_ADDR (0x000434C4u)
#define CSL_DFE_DDUC_HOP_MIX0_FREQ_WORD_HI_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_LO_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_4_7_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_0_4_7_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG;

/* freq word table for bank 0 in mixer1, w/the highest channel in 1st address (channels 7, 6, 5 and 4 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG_ADDR (0x000434E0u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_LO_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_4_7_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_1_4_7_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG;

/* freq word table for bank 1 in mixer1, w/the highest channel in 1st address (channels 7, 6, 5 and 4 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG_ADDR (0x000434E4u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_LO_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_MID_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_4_7_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_0_4_7_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG_ADDR (0x00043500u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_MID_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_4_7_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_1_4_7_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG_ADDR (0x00043504u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_MID_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_HI_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_4_7_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_0_4_7_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_4_7_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG_ADDR (0x00043520u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX1_FREQ_WORD_HI_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_4_7_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_1_4_7_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_4_7_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG_ADDR (0x00043524u)
#define CSL_DFE_DDUC_HOP_MIX1_FREQ_WORD_HI_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_LO_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_8_11_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_0_8_11_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG;

/* freq word table for bank 0 in mixer2, w/the highest channel in 1st address (channels 11, 10, 9 and 8 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG_ADDR (0x00043540u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_LO_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_8_11_15_0 : 16;
#else 
    Uint32 freq_word_swap_bank_1_8_11_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG;

/* freq word table for bank 1 in mixer2, w/the highest channel in 1st address (channels 11, 10, 9 and 8 if 12 channel mode). When mem_mpu_access is low, it will write to inactive bank. */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG_ADDR (0x00043544u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_LO_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_MID_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_8_11_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_0_8_11_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG_ADDR (0x00043560u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_MID_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_8_11_31_16 : 16;
#else 
    Uint32 freq_word_swap_bank_1_8_11_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG_ADDR (0x00043564u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_MID_BANK1_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_HI_BANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_0_8_11_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_0_8_11_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG_FREQ_WORD_SWAP_BANK_0_8_11_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG_ADDR (0x00043580u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK0_REG_RESETVAL (0x00000000u)

/* HOP_MIX2_FREQ_WORD_HI_BANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_swap_bank_1_8_11_47_32 : 16;
#else 
    Uint32 freq_word_swap_bank_1_8_11_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG;

/*  */
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_47_32_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG_FREQ_WORD_SWAP_BANK_1_8_11_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG_ADDR (0x00043584u)
#define CSL_DFE_DDUC_HOP_MIX2_FREQ_WORD_HI_BANK1_REG_RESETVAL (0x00000000u)

/* FRW_PHASE_LOBANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 phase_swap_bank_0_15_0 : 16;
#else 
    Uint32 phase_swap_bank_0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG;

/* phase word for each channel in frw for bank 0; when mem_mpu_access is low, this address will write to the inactive bank. 6 MSBs are FIFO depth and the 20 LSBs are for adjusting the phase (in other words, partway between a FIFO address). Should also add the value 0x4 (to assist in rounding in the hardware). */
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG_PHASE_SWAP_BANK_0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG_PHASE_SWAP_BANK_0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG_PHASE_SWAP_BANK_0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG_ADDR (0x00043800u)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK0_REG_RESETVAL (0x00000000u)

/* FRW_PHASE_HIBANK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 phase_swap_bank_0_25_16 : 10;
#else 
    Uint32 phase_swap_bank_0_25_16 : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG;

/*  */
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG_PHASE_SWAP_BANK_0_25_16_MASK (0x000003FFu)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG_PHASE_SWAP_BANK_0_25_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG_PHASE_SWAP_BANK_0_25_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG_ADDR (0x00043804u)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK0_REG_RESETVAL (0x00000000u)

/* FRW_PHASE_LOBANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 phase_swap_bank1_15_0 : 16;
#else 
    Uint32 phase_swap_bank1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG;

/* phase word for each channel in frw for bank 1; when mem_mpu_access is low, this address will write to the inactive bank. 6 MSBs are FIFO depth and the 20 LSBs are for adjusting the phase (in other words, partway between a FIFO address). Should also add the value 0x4 (to assist in rounding in the hardware). */
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG_PHASE_SWAP_BANK1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG_PHASE_SWAP_BANK1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG_PHASE_SWAP_BANK1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG_ADDR (0x00043808u)
#define CSL_DFE_DDUC_FRW_PHASE_LOBANK1_REG_RESETVAL (0x00000000u)

/* FRW_PHASE_HIBANK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 phase_swap_bank_1_25_16 : 10;
#else 
    Uint32 phase_swap_bank_1_25_16 : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG;

/*  */
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG_PHASE_SWAP_BANK_1_25_16_MASK (0x000003FFu)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG_PHASE_SWAP_BANK_1_25_16_SHIFT (0x00000000u)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG_PHASE_SWAP_BANK_1_25_16_RESETVAL (0x00000000u)

#define CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG_ADDR (0x0004380Cu)
#define CSL_DFE_DDUC_FRW_PHASE_HIBANK1_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_DDUC_H__ */
