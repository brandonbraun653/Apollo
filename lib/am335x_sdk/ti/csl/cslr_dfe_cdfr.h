/*
 * cslr_dfe_cdfr.h
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

#ifndef CSLR_DFE_CDFR_H__
#define CSLR_DFE_CDFR_H__

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
    volatile Uint32 cdfr_cdfr_1;
    /* Addr: h(8), d(8) */
    volatile Uint32 cdfr_cdfr_2;
    /* Addr: h(C), d(12) */
    volatile Uint32 cdfr_cdfr_3;
    /* Addr: h(10), d(16) */
    volatile Uint32 cdfr_cdfr_4;
    /* Addr: h(14), d(20) */
    volatile Uint32 cdfr_cdfr_5;
    /* Addr: h(18), d(24) */
    volatile Uint32 cdfr_cdfr_6;
    /* Addr: h(1C), d(28) */
    volatile Uint32 cdfr_cdfr_7;
    /* Addr: h(20), d(32) */
    volatile Uint32 cdfr_cdfr_8;
    /* Addr: h(24), d(36) */
    volatile Uint32 cdfr_cdfr_9;
    /* Addr: h(28), d(40) */
    volatile Uint32 cdfr_cdfr_10;
    /* Addr: h(2C), d(44) */
    volatile Uint32 cdfr_cdfr_11;
    /* Addr: h(30), d(48) */
    volatile Uint32 cdfr_cdfr_12;
    /* Addr: h(34), d(52) */
    volatile Uint32 cdfr_cdfr_13;
    /* Addr: h(38), d(56) */
    volatile Uint32 cdfr_cdfr_14;
    /* Addr: h(3C), d(60) */
    volatile Uint32 cdfr_cdfr_15;
    /* Addr: h(40), d(64) */
    volatile Uint32 cdfr_cdfr_16;
    /* Addr: h(44), d(68) */
    volatile Uint32 rsvd1[15];
    /* Addr: h(80), d(128) */
    volatile Uint32 signal_gen_general;
    /* Addr: h(84), d(132) */
    volatile Uint32 signal_gen_ramp_start_lo;
    /* Addr: h(88), d(136) */
    volatile Uint32 signal_gen_ramp_start_hi;
    /* Addr: h(8C), d(140) */
    volatile Uint32 signal_gen_ramp_stop_lo;
    /* Addr: h(90), d(144) */
    volatile Uint32 signal_gen_ramp_stop_hi;
    /* Addr: h(94), d(148) */
    volatile Uint32 signal_gen_ramp_slope_lo;
    /* Addr: h(98), d(152) */
    volatile Uint32 signal_gen_ramp_slope_hi;
    /* Addr: h(9C), d(156) */
    volatile Uint32 signal_gen_gen_timer;
    /* Addr: h(A0), d(160) */
    volatile Uint32 rsvd2[1];
    /* Addr: h(A4), d(164) */
    volatile Uint32 check_sum_ctrl0;
    /* Addr: h(A8), d(168) */
    volatile Uint32 check_sum_signal_len;
    /* Addr: h(AC), d(172) */
    volatile Uint32 check_sum_chan_sel;
    /* Addr: h(B0), d(176) */
    volatile Uint32 check_sum_result_lo;
    /* Addr: h(B4), d(180) */
    volatile Uint32 check_sum_result_hi;
    /* Addr: h(B8), d(184) */
    volatile Uint32 rsvd3[82];
    /* Addr: h(200), d(512) */
    volatile Uint32 cdfr_cdfr_892[96];
    /* Addr: h(380), d(896) */
    volatile Uint32 rsvd4[32];
    /* Addr: h(400), d(1024) */
    volatile Uint32 cdfr_cdfr_1404[96];
    /* Addr: h(580), d(1408) */
    volatile Uint32 rsvd5[32];
    /* Addr: h(600), d(1536) */
    volatile Uint32 cdfr_cdfr_1916[96];
    /* Addr: h(780), d(1920) */
    volatile Uint32 rsvd6[32];
    /* Addr: h(800), d(2048) */
    volatile Uint32 cdfr_cdfr_2428[96];
    /* Addr: h(980), d(2432) */
    volatile Uint32 rsvd7[416];
    /* Addr: h(1000), d(4096) */
    volatile Uint32 cdfr_top_inits;
    /* Addr: h(1004), d(4100) */
    volatile Uint32 rsvd8[63];
    /* Addr: h(1100), d(4352) */
    volatile Uint32 cdfr_top_time_step;
    /* Addr: h(1104), d(4356) */
    volatile Uint32 cdfr_top_reset_int;
    /* Addr: h(1108), d(4360) */
    volatile Uint32 cdfr_top_tdd_period;
    /* Addr: h(110C), d(4364) */
    volatile Uint32 cdfr_top_tdd_on_0;
    /* Addr: h(1110), d(4368) */
    volatile Uint32 cdfr_top_tdd_off_0;
    /* Addr: h(1114), d(4372) */
    volatile Uint32 cdfr_top_tdd_on_1;
    /* Addr: h(1118), d(4376) */
    volatile Uint32 cdfr_top_tdd_off_1;
} CSL_DFE_CDFR_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CDFR_CDFR_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 en_buc : 1;
    Uint32 buc_mode : 1;
    Uint32 dit_en : 1;
    Uint32 spare : 8;
    Uint32 tb_sel : 5;
    Uint32 ssel_mix : 4;
    Uint32 ssel_rs_cf_swap : 4;
    Uint32 ssel_rs_ph_init : 4;
    Uint32 ssel_chksum : 4;
#else 
    Uint32 ssel_chksum : 4;
    Uint32 ssel_rs_ph_init : 4;
    Uint32 ssel_rs_cf_swap : 4;
    Uint32 ssel_mix : 4;
    Uint32 tb_sel : 5;
    Uint32 spare : 8;
    Uint32 dit_en : 1;
    Uint32 buc_mode : 1;
    Uint32 en_buc : 1;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_1_REG;

/* check sum sync sel */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_CHKSUM_MASK (0x0000000Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_CHKSUM_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_CHKSUM_RESETVAL (0x00000000u)

/* resampler phase init sync sel */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_PH_INIT_MASK (0x000000F0u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_PH_INIT_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_PH_INIT_RESETVAL (0x00000000u)

/* resampler coef swap sync sel */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_CF_SWAP_MASK (0x00000F00u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_CF_SWAP_SHIFT (0x00000008u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_RS_CF_SWAP_RESETVAL (0x00000000u)

/* common sync for all 4 mixers */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_MIX_MASK (0x0000F000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_MIX_SHIFT (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SSEL_MIX_RESETVAL (0x00000000u)

/* test bus selection */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_TB_SEL_MASK (0x001F0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_TB_SEL_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_TB_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SPARE_MASK (0x1FE00000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SPARE_SHIFT (0x00000015u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_SPARE_RESETVAL (0x00000000u)

/* 0 dither off; 1 dither on */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_DIT_EN_MASK (0x20000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_DIT_EN_SHIFT (0x0000001Du)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_DIT_EN_RESETVAL (0x00000000u)

/* 0 ck/4 input; 1 ck/2 input */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_BUC_MODE_MASK (0x40000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_BUC_MODE_SHIFT (0x0000001Eu)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_BUC_MODE_RESETVAL (0x00000000u)

/* 0 buc off; 1 buc on */
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_EN_BUC_MASK (0x80000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_EN_BUC_SHIFT (0x0000001Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_EN_BUC_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_ADDR (0x00000004u)
#define CSL_DFE_CDFR_CDFR_CDFR_1_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsa_mode : 1;
    Uint32 rsa_init_ph : 3;
    Uint32 rsa_state_cnt : 4;
    Uint32 rsa_ant_ph : 24;
#else 
    Uint32 rsa_ant_ph : 24;
    Uint32 rsa_state_cnt : 4;
    Uint32 rsa_init_ph : 3;
    Uint32 rsa_mode : 1;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_2_REG;

/* antenna phase */
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_ANT_PH_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_ANT_PH_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_ANT_PH_RESETVAL (0x00000000u)

/* max state counter value - 1 */
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_STATE_CNT_MASK (0x0F000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_STATE_CNT_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_STATE_CNT_RESETVAL (0x00000000u)

/* initial phase */
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_INIT_PH_MASK (0x70000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_INIT_PH_SHIFT (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_INIT_PH_RESETVAL (0x00000000u)

/* 0 = 1x; 1 = 2x (don't think 2x is used) */
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_MODE_MASK (0x80000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_MODE_SHIFT (0x0000001Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RSA_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_ADDR (0x00000008u)
#define CSL_DFE_CDFR_CDFR_CDFR_2_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsb_mode : 1;
    Uint32 rsb_init_ph : 3;
    Uint32 rsb_state_cnt : 4;
    Uint32 rsb_ant_ph : 24;
#else 
    Uint32 rsb_ant_ph : 24;
    Uint32 rsb_state_cnt : 4;
    Uint32 rsb_init_ph : 3;
    Uint32 rsb_mode : 1;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_3_REG;

/* antenna phase */
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_ANT_PH_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_ANT_PH_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_ANT_PH_RESETVAL (0x00000000u)

/* max state counter value - 1 */
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_STATE_CNT_MASK (0x0F000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_STATE_CNT_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_STATE_CNT_RESETVAL (0x00000000u)

/* initial phase */
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_INIT_PH_MASK (0x70000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_INIT_PH_SHIFT (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_INIT_PH_RESETVAL (0x00000000u)

/* 0 = 1x; 1 = 2x (don't think 2x is used) */
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_MODE_MASK (0x80000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_MODE_SHIFT (0x0000001Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RSB_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_ADDR (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_3_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsc_mode : 1;
    Uint32 rsc_init_ph : 3;
    Uint32 rsc_state_cnt : 4;
    Uint32 rsc_ant_ph : 24;
#else 
    Uint32 rsc_ant_ph : 24;
    Uint32 rsc_state_cnt : 4;
    Uint32 rsc_init_ph : 3;
    Uint32 rsc_mode : 1;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_4_REG;

/* antenna phase */
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_ANT_PH_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_ANT_PH_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_ANT_PH_RESETVAL (0x00000000u)

/* max state counter value - 1 */
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_STATE_CNT_MASK (0x0F000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_STATE_CNT_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_STATE_CNT_RESETVAL (0x00000000u)

/* initial phase */
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_INIT_PH_MASK (0x70000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_INIT_PH_SHIFT (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_INIT_PH_RESETVAL (0x00000000u)

/* 0 = 1x; 1 = 2x (don't think 2x is used) */
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_MODE_MASK (0x80000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_MODE_SHIFT (0x0000001Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RSC_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_ADDR (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_4_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsd_mode : 1;
    Uint32 rsd_init_ph : 3;
    Uint32 rsd_state_cnt : 4;
    Uint32 rsd_ant_ph : 24;
#else 
    Uint32 rsd_ant_ph : 24;
    Uint32 rsd_state_cnt : 4;
    Uint32 rsd_init_ph : 3;
    Uint32 rsd_mode : 1;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_5_REG;

/* antenna phase */
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_ANT_PH_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_ANT_PH_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_ANT_PH_RESETVAL (0x00000000u)

/* max state counter value - 1 */
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_STATE_CNT_MASK (0x0F000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_STATE_CNT_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_STATE_CNT_RESETVAL (0x00000000u)

/* initial phase */
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_INIT_PH_MASK (0x70000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_INIT_PH_SHIFT (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_INIT_PH_RESETVAL (0x00000000u)

/* 0 = 1x; 1 = 2x (don't think 2x is used) */
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_MODE_MASK (0x80000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_MODE_SHIFT (0x0000001Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RSD_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_ADDR (0x00000014u)
#define CSL_DFE_CDFR_CDFR_CDFR_5_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix0_freq_lsb : 32;
#else 
    Uint32 mix0_freq_lsb : 32;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_6_REG;

/* mixer 0 f[31:0] */
#define CSL_DFE_CDFR_CDFR_CDFR_6_REG_MIX0_FREQ_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_6_REG_MIX0_FREQ_LSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_6_REG_MIX0_FREQ_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_6_REG_ADDR (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_6_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix0_phase : 16;
    Uint32 mix0_freq_msb : 16;
#else 
    Uint32 mix0_freq_msb : 16;
    Uint32 mix0_phase : 16;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_7_REG;

/* mixer 0 f[47:32] */
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_FREQ_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_FREQ_MSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_FREQ_MSB_RESETVAL (0x00000000u)

/* mixer 0 phase */
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_PHASE_MASK (0xFFFF0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_PHASE_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_MIX0_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_ADDR (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_7_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix1_freq_lsb : 32;
#else 
    Uint32 mix1_freq_lsb : 32;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_8_REG;

/* mixer 1 f[31:0] */
#define CSL_DFE_CDFR_CDFR_CDFR_8_REG_MIX1_FREQ_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_8_REG_MIX1_FREQ_LSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_8_REG_MIX1_FREQ_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_8_REG_ADDR (0x00000020u)
#define CSL_DFE_CDFR_CDFR_CDFR_8_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix1_phase : 16;
    Uint32 mix1_freq_msb : 16;
#else 
    Uint32 mix1_freq_msb : 16;
    Uint32 mix1_phase : 16;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_9_REG;

/* mixer 1 f[47:32] */
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_FREQ_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_FREQ_MSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_FREQ_MSB_RESETVAL (0x00000000u)

/* mixer 1 phase */
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_PHASE_MASK (0xFFFF0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_PHASE_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_MIX1_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_ADDR (0x00000024u)
#define CSL_DFE_CDFR_CDFR_CDFR_9_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix2_freq_lsb : 32;
#else 
    Uint32 mix2_freq_lsb : 32;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_10_REG;

/* mixer 2 f[31:0] */
#define CSL_DFE_CDFR_CDFR_CDFR_10_REG_MIX2_FREQ_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_10_REG_MIX2_FREQ_LSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_10_REG_MIX2_FREQ_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_10_REG_ADDR (0x00000028u)
#define CSL_DFE_CDFR_CDFR_CDFR_10_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix2_phase : 16;
    Uint32 mix2_freq_msb : 16;
#else 
    Uint32 mix2_freq_msb : 16;
    Uint32 mix2_phase : 16;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_11_REG;

/* mixer 2 f[47:32] */
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_FREQ_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_FREQ_MSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_FREQ_MSB_RESETVAL (0x00000000u)

/* mixer 2 phase */
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_PHASE_MASK (0xFFFF0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_PHASE_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_MIX2_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_ADDR (0x0000002Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_11_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix3_freq_lsb : 32;
#else 
    Uint32 mix3_freq_lsb : 32;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_12_REG;

/* mixer 3 f[31:0] */
#define CSL_DFE_CDFR_CDFR_CDFR_12_REG_MIX3_FREQ_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_12_REG_MIX3_FREQ_LSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_12_REG_MIX3_FREQ_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_12_REG_ADDR (0x00000030u)
#define CSL_DFE_CDFR_CDFR_CDFR_12_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mix3_phase : 16;
    Uint32 mix3_freq_msb : 16;
#else 
    Uint32 mix3_freq_msb : 16;
    Uint32 mix3_phase : 16;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_13_REG;

/* mixer 3 f[47:32] */
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_FREQ_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_FREQ_MSB_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_FREQ_MSB_RESETVAL (0x00000000u)

/* mixer 3 phase */
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_PHASE_MASK (0xFFFF0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_PHASE_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_MIX3_PHASE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_ADDR (0x00000034u)
#define CSL_DFE_CDFR_CDFR_CDFR_13_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 addd_d : 2;
    Uint32 addd_c : 2;
    Uint32 addd_b : 2;
    Uint32 addd_a : 2;
    Uint32 addc_d : 2;
    Uint32 addc_c : 2;
    Uint32 addc_b : 2;
    Uint32 addc_a : 2;
    Uint32 addb_d : 2;
    Uint32 addb_c : 2;
    Uint32 addb_b : 2;
    Uint32 addb_a : 2;
    Uint32 adda_d : 2;
    Uint32 adda_c : 2;
    Uint32 adda_b : 2;
    Uint32 adda_a : 2;
#else 
    Uint32 adda_a : 2;
    Uint32 adda_b : 2;
    Uint32 adda_c : 2;
    Uint32 adda_d : 2;
    Uint32 addb_a : 2;
    Uint32 addb_b : 2;
    Uint32 addb_c : 2;
    Uint32 addb_d : 2;
    Uint32 addc_a : 2;
    Uint32 addc_b : 2;
    Uint32 addc_c : 2;
    Uint32 addc_d : 2;
    Uint32 addd_a : 2;
    Uint32 addd_b : 2;
    Uint32 addd_c : 2;
    Uint32 addd_d : 2;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_14_REG;

/* adder a a input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_A_MASK (0x00000003u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_A_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_A_RESETVAL (0x00000000u)

/* adder a b input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_B_MASK (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_B_SHIFT (0x00000002u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_B_RESETVAL (0x00000000u)

/* adder a c input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_C_MASK (0x00000030u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_C_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_C_RESETVAL (0x00000000u)

/* adder a d input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_D_MASK (0x000000C0u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_D_SHIFT (0x00000006u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDA_D_RESETVAL (0x00000000u)

/* adder b a input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_A_MASK (0x00000300u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_A_SHIFT (0x00000008u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_A_RESETVAL (0x00000000u)

/* adder b b input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_B_MASK (0x00000C00u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_B_SHIFT (0x0000000Au)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_B_RESETVAL (0x00000000u)

/* adder b c input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_C_MASK (0x00003000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_C_SHIFT (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_C_RESETVAL (0x00000000u)

/* adder b d input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_D_MASK (0x0000C000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_D_SHIFT (0x0000000Eu)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDB_D_RESETVAL (0x00000000u)

/* adder c a input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_A_MASK (0x00030000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_A_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_A_RESETVAL (0x00000000u)

/* adder c b input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_B_MASK (0x000C0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_B_SHIFT (0x00000012u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_B_RESETVAL (0x00000000u)

/* adder c c input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_C_MASK (0x00300000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_C_SHIFT (0x00000014u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_C_RESETVAL (0x00000000u)

/* adder c d input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_D_MASK (0x00C00000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_D_SHIFT (0x00000016u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDC_D_RESETVAL (0x00000000u)

/* adder d a input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_A_MASK (0x03000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_A_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_A_RESETVAL (0x00000000u)

/* adder d b input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_B_MASK (0x0C000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_B_SHIFT (0x0000001Au)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_B_RESETVAL (0x00000000u)

/* adder d c input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_C_MASK (0x30000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_C_SHIFT (0x0000001Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_C_RESETVAL (0x00000000u)

/* adder d d input select 0,1 = off; 2=mixbypass; 3=mix */
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_D_MASK (0xC0000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_D_SHIFT (0x0000001Eu)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDD_D_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_ADDR (0x00000038u)
#define CSL_DFE_CDFR_CDFR_CDFR_14_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 8;
    Uint32 rsdq_ctl : 3;
    Uint32 rsdi_ctl : 3;
    Uint32 rscq_ctl : 3;
    Uint32 rsci_ctl : 3;
    Uint32 rsbq_ctl : 3;
    Uint32 rsbi_ctl : 3;
    Uint32 rsaq_ctl : 3;
    Uint32 rsai_ctl : 3;
#else 
    Uint32 rsai_ctl : 3;
    Uint32 rsaq_ctl : 3;
    Uint32 rsbi_ctl : 3;
    Uint32 rsbq_ctl : 3;
    Uint32 rsci_ctl : 3;
    Uint32 rscq_ctl : 3;
    Uint32 rsdi_ctl : 3;
    Uint32 rsdq_ctl : 3;
    Uint32 spare : 8;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_15_REG;

/* resampler a I input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAI_CTL_MASK (0x00000007u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAI_CTL_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAI_CTL_RESETVAL (0x00000000u)

/* resampler a Q input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAQ_CTL_MASK (0x00000038u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAQ_CTL_SHIFT (0x00000003u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSAQ_CTL_RESETVAL (0x00000000u)

/* resampler b I input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBI_CTL_MASK (0x000001C0u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBI_CTL_SHIFT (0x00000006u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBI_CTL_RESETVAL (0x00000000u)

/* resampler b Q input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBQ_CTL_MASK (0x00000E00u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBQ_CTL_SHIFT (0x00000009u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSBQ_CTL_RESETVAL (0x00000000u)

/* resampler c I input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCI_CTL_MASK (0x00007000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCI_CTL_SHIFT (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCI_CTL_RESETVAL (0x00000000u)

/* resampler c Q input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCQ_CTL_MASK (0x00038000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCQ_CTL_SHIFT (0x0000000Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSCQ_CTL_RESETVAL (0x00000000u)

/* resampler d I input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDI_CTL_MASK (0x001C0000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDI_CTL_SHIFT (0x00000012u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDI_CTL_RESETVAL (0x00000000u)

/* resampler d Q input mux control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDQ_CTL_MASK (0x00E00000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDQ_CTL_SHIFT (0x00000015u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RSDQ_CTL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_SPARE_MASK (0xFF000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_SPARE_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_ADDR (0x0000003Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_15_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 8;
    Uint32 add4d_cken : 1;
    Uint32 add4c_cken : 1;
    Uint32 add4b_cken : 1;
    Uint32 add4a_cken : 1;
    Uint32 mixd_cken : 1;
    Uint32 mixc_cken : 1;
    Uint32 mixb_cken : 1;
    Uint32 mixa_cken : 1;
    Uint32 rsd_men_ctl : 1;
    Uint32 rsd_nen_ctl : 3;
    Uint32 rsc_men_ctl : 1;
    Uint32 rsc_nen_ctl : 3;
    Uint32 rsb_men_ctl : 1;
    Uint32 rsb_nen_ctl : 3;
    Uint32 rsa_men_ctl : 1;
    Uint32 rsa_nen_ctl : 3;
#else 
    Uint32 rsa_nen_ctl : 3;
    Uint32 rsa_men_ctl : 1;
    Uint32 rsb_nen_ctl : 3;
    Uint32 rsb_men_ctl : 1;
    Uint32 rsc_nen_ctl : 3;
    Uint32 rsc_men_ctl : 1;
    Uint32 rsd_nen_ctl : 3;
    Uint32 rsd_men_ctl : 1;
    Uint32 mixa_cken : 1;
    Uint32 mixb_cken : 1;
    Uint32 mixc_cken : 1;
    Uint32 mixd_cken : 1;
    Uint32 add4a_cken : 1;
    Uint32 add4b_cken : 1;
    Uint32 add4c_cken : 1;
    Uint32 add4d_cken : 1;
    Uint32 spare : 8;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_16_REG;

/* resampler a nen control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_NEN_CTL_MASK (0x00000007u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_NEN_CTL_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_NEN_CTL_RESETVAL (0x00000000u)

/* resampler a men control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_MEN_CTL_MASK (0x00000008u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_MEN_CTL_SHIFT (0x00000003u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSA_MEN_CTL_RESETVAL (0x00000000u)

/* resampler b nen control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_NEN_CTL_MASK (0x00000070u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_NEN_CTL_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_NEN_CTL_RESETVAL (0x00000000u)

/* resampler b men control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_MEN_CTL_MASK (0x00000080u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_MEN_CTL_SHIFT (0x00000007u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSB_MEN_CTL_RESETVAL (0x00000000u)

/* resampler c nen control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_NEN_CTL_MASK (0x00000700u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_NEN_CTL_SHIFT (0x00000008u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_NEN_CTL_RESETVAL (0x00000000u)

/* resampler c men control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_MEN_CTL_MASK (0x00000800u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_MEN_CTL_SHIFT (0x0000000Bu)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSC_MEN_CTL_RESETVAL (0x00000000u)

/* resampler d nen control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_NEN_CTL_MASK (0x00007000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_NEN_CTL_SHIFT (0x0000000Cu)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_NEN_CTL_RESETVAL (0x00000000u)

/* resampler d men control; see config sheet for value */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_MEN_CTL_MASK (0x00008000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_MEN_CTL_SHIFT (0x0000000Fu)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RSD_MEN_CTL_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXA_CKEN_MASK (0x00010000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXA_CKEN_SHIFT (0x00000010u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXA_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXB_CKEN_MASK (0x00020000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXB_CKEN_SHIFT (0x00000011u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXB_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXC_CKEN_MASK (0x00040000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXC_CKEN_SHIFT (0x00000012u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXC_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXD_CKEN_MASK (0x00080000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXD_CKEN_SHIFT (0x00000013u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_MIXD_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4A_CKEN_MASK (0x00100000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4A_CKEN_SHIFT (0x00000014u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4A_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4B_CKEN_MASK (0x00200000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4B_CKEN_SHIFT (0x00000015u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4B_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4C_CKEN_MASK (0x00400000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4C_CKEN_SHIFT (0x00000016u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4C_CKEN_RESETVAL (0x00000000u)

/* 0 = off; 1 = on */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4D_CKEN_MASK (0x00800000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4D_CKEN_SHIFT (0x00000017u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADD4D_CKEN_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_SPARE_MASK (0xFF000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_SPARE_SHIFT (0x00000018u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_ADDR (0x00000040u)
#define CSL_DFE_CDFR_CDFR_CDFR_16_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_GENERAL */
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
} CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_ADDR (0x00000080u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG_ADDR (0x00000084u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG_ADDR (0x00000088u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG_ADDR (0x0000008Cu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG_ADDR (0x00000090u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG_ADDR (0x00000094u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG_ADDR (0x00000098u)
#define CSL_DFE_CDFR_SIGNAL_GEN_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG_ADDR (0x0000009Cu)
#define CSL_DFE_CDFR_SIGNAL_GEN_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 spare : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 spare : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_SPARE_MASK (0x0000000Eu)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_SPARE_SHIFT (0x00000001u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_SPARE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_ADDR (0x000000A4u)
#define CSL_DFE_CDFR_CHECK_SUM_CTRL0_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG_ADDR (0x000000A8u)
#define CSL_DFE_CDFR_CHECK_SUM_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG_ADDR (0x000000ACu)
#define CSL_DFE_CDFR_CHECK_SUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG_ADDR (0x000000B0u)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG_ADDR (0x000000B4u)
#define CSL_DFE_CDFR_CHECK_SUM_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_892 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpa_coef : 18;
#else 
    Uint32 rsmpa_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_892_REG;

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_892_REG_RSMPA_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_892_REG_RSMPA_COEF_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_892_REG_RSMPA_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_892_REG_ADDR (0x00000200u)
#define CSL_DFE_CDFR_CDFR_CDFR_892_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_1404 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpb_coef : 18;
#else 
    Uint32 rsmpb_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_1404_REG;

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_1404_REG_RSMPB_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_1404_REG_RSMPB_COEF_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1404_REG_RSMPB_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_1404_REG_ADDR (0x00000400u)
#define CSL_DFE_CDFR_CDFR_CDFR_1404_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_1916 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpc_coef : 18;
#else 
    Uint32 rsmpc_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_1916_REG;

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_1916_REG_RSMPC_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_1916_REG_RSMPC_COEF_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_1916_REG_RSMPC_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_1916_REG_ADDR (0x00000600u)
#define CSL_DFE_CDFR_CDFR_CDFR_1916_REG_RESETVAL (0x00000000u)

/* CDFR_CDFR_2428 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpd_coef : 18;
#else 
    Uint32 rsmpd_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_CDFR_CDFR_CDFR_2428_REG;

/*  */
#define CSL_DFE_CDFR_CDFR_CDFR_2428_REG_RSMPD_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_CDFR_CDFR_CDFR_2428_REG_RSMPD_COEF_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_CDFR_2428_REG_RSMPD_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_CDFR_2428_REG_ADDR (0x00000800u)
#define CSL_DFE_CDFR_CDFR_CDFR_2428_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_INITS */
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
} CSL_DFE_CDFR_CDFR_TOP_INITS_REG;

/*  */
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* released on inits_ssel */
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* released on inits_ssel */
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* released on inits_ssel */
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_ADDR (0x00001000u)
#define CSL_DFE_CDFR_CDFR_TOP_INITS_REG_RESETVAL (0x00000070u)

/* CDFR_TOP_TIME_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). Note there is only ONE cken for BOTH halves of cdfr. */
#define CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG_ADDR (0x00001100u)
#define CSL_DFE_CDFR_CDFR_TOP_TIME_STEP_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_RESET_INT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. Note there is only ONE cken for BOTH halves of cdfr. */
#define CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG_ADDR (0x00001104u)
#define CSL_DFE_CDFR_CDFR_TOP_RESET_INT_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_TDD_PERIOD */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_period : 24;
#else 
    Uint32 tdd_period : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG_TDD_PERIOD_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG_TDD_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG_TDD_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG_ADDR (0x00001108u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_PERIOD_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_TDD_ON_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_0 : 24;
#else 
    Uint32 tdd_on_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG_TDD_ON_0_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG_TDD_ON_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG_TDD_ON_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG_ADDR (0x0000110Cu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_0_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_TDD_OFF_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_0 : 24;
#else 
    Uint32 tdd_off_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG_TDD_OFF_0_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG_TDD_OFF_0_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG_TDD_OFF_0_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG_ADDR (0x00001110u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_0_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_TDD_ON_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_1 : 24;
#else 
    Uint32 tdd_on_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG_TDD_ON_1_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG_TDD_ON_1_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG_TDD_ON_1_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG_ADDR (0x00001114u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_ON_1_REG_RESETVAL (0x00000000u)

/* CDFR_TOP_TDD_OFF_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_1 : 24;
#else 
    Uint32 tdd_off_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG_TDD_OFF_1_MASK (0x00FFFFFFu)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG_TDD_OFF_1_SHIFT (0x00000000u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG_TDD_OFF_1_RESETVAL (0x00000000u)

#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG_ADDR (0x00001118u)
#define CSL_DFE_CDFR_CDFR_TOP_TDD_OFF_1_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_CDFR_H__ */
