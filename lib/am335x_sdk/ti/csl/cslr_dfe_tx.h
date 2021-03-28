/*
 * cslr_dfe_tx.h
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

#ifndef CSLR_DFE_TX_H__
#define CSLR_DFE_TX_H__

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
    volatile Uint32 txa_txa_1;
    /* Addr: h(8), d(8) */
    volatile Uint32 txa_txa_2;
    /* Addr: h(C), d(12) */
    volatile Uint32 txa_txa_3;
    /* Addr: h(10), d(16) */
    volatile Uint32 txa_txa_4;
    /* Addr: h(14), d(20) */
    volatile Uint32 txa_txa_5;
    /* Addr: h(18), d(24) */
    volatile Uint32 txa_txa_6;
    /* Addr: h(1C), d(28) */
    volatile Uint32 txa_txa_7;
    /* Addr: h(20), d(32) */
    volatile Uint32 txa_txa_8;
    /* Addr: h(24), d(36) */
    volatile Uint32 txa_txa_9;
    /* Addr: h(28), d(40) */
    volatile Uint32 txa_txa_10;
    /* Addr: h(2C), d(44) */
    volatile Uint32 txa_txa_11;
    /* Addr: h(30), d(48) */
    volatile Uint32 rsvd1[5];
    /* Addr: h(44), d(68) */
    volatile Uint32 txb_txb_17;
    /* Addr: h(48), d(72) */
    volatile Uint32 txb_txb_18;
    /* Addr: h(4C), d(76) */
    volatile Uint32 txb_txb_19;
    /* Addr: h(50), d(80) */
    volatile Uint32 txb_txb_20;
    /* Addr: h(54), d(84) */
    volatile Uint32 txb_txb_21;
    /* Addr: h(58), d(88) */
    volatile Uint32 txb_txb_22;
    /* Addr: h(5C), d(92) */
    volatile Uint32 txb_txb_23;
    /* Addr: h(60), d(96) */
    volatile Uint32 txb_txb_24;
    /* Addr: h(64), d(100) */
    volatile Uint32 txb_txb_25;
    /* Addr: h(68), d(104) */
    volatile Uint32 txb_txb_26;
    /* Addr: h(6C), d(108) */
    volatile Uint32 txb_txb_27;
    /* Addr: h(70), d(112) */
    volatile Uint32 rsvd2[4];
    /* Addr: h(80), d(128) */
    volatile Uint32 txa_txa_32[15];
    /* Addr: h(BC), d(188) */
    volatile Uint32 txa_txa_47;
    /* Addr: h(C0), d(192) */
    volatile Uint32 txa_txa_48[15];
    /* Addr: h(FC), d(252) */
    volatile Uint32 rsvd3[1];
    /* Addr: h(100), d(256) */
    volatile Uint32 txb_txb_64[15];
    /* Addr: h(13C), d(316) */
    volatile Uint32 txb_txb_79;
    /* Addr: h(140), d(320) */
    volatile Uint32 txb_txb_80[15];
    /* Addr: h(17C), d(380) */
    volatile Uint32 rsvd4[1];
    /* Addr: h(180), d(384) */
    volatile Uint32 signal_gen_signal_gen_96;
    /* Addr: h(184), d(388) */
    volatile Uint32 signal_gen_signal_gen_97;
    /* Addr: h(188), d(392) */
    volatile Uint32 signal_gen_signal_gen_98;
    /* Addr: h(18C), d(396) */
    volatile Uint32 signal_gen_signal_gen_99;
    /* Addr: h(190), d(400) */
    volatile Uint32 signal_gen_signal_gen_100;
    /* Addr: h(194), d(404) */
    volatile Uint32 signal_gen_signal_gen_101;
    /* Addr: h(198), d(408) */
    volatile Uint32 signal_gen_signal_gen_102;
    /* Addr: h(19C), d(412) */
    volatile Uint32 signal_gen_signal_gen_103;
    /* Addr: h(1A0), d(416) */
    volatile Uint32 signal_gen_signal_gen_104;
    /* Addr: h(1A4), d(420) */
    volatile Uint32 check_sum_check_sum_105;
    /* Addr: h(1A8), d(424) */
    volatile Uint32 check_sum_check_sum_106;
    /* Addr: h(1AC), d(428) */
    volatile Uint32 check_sum_check_sum_107;
    /* Addr: h(1B0), d(432) */
    volatile Uint32 check_sum_check_sum_108;
    /* Addr: h(1B4), d(436) */
    volatile Uint32 check_sum_check_sum_109;
    /* Addr: h(1B8), d(440) */
    volatile Uint32 tx_tx_110;
    /* Addr: h(1BC), d(444) */
    volatile Uint32 rsvd5[17];
    /* Addr: h(200), d(512) */
    volatile Uint32 txa_txa_128[96];
    /* Addr: h(380), d(896) */
    volatile Uint32 rsvd6[32];
    /* Addr: h(400), d(1024) */
    volatile Uint32 txa_txa_256[96];
    /* Addr: h(580), d(1408) */
    volatile Uint32 rsvd7[32];
    /* Addr: h(600), d(1536) */
    volatile Uint32 txb_txb_384[96];
    /* Addr: h(780), d(1920) */
    volatile Uint32 rsvd8[32];
    /* Addr: h(800), d(2048) */
    volatile Uint32 txb_txb_512[96];
    /* Addr: h(980), d(2432) */
    volatile Uint32 rsvd9[32];
    /* Addr: h(A00), d(2560) */
    volatile Uint32 txa_txa_640;
    /* Addr: h(A04), d(2564) */
    volatile Uint32 txa_txa_641;
    /* Addr: h(A08), d(2568) */
    volatile Uint32 txa_txa_642;
    /* Addr: h(A0C), d(2572) */
    volatile Uint32 txa_txa_643;
    /* Addr: h(A10), d(2576) */
    volatile Uint32 txa_txa_644;
    /* Addr: h(A14), d(2580) */
    volatile Uint32 txa_txa_645;
    /* Addr: h(A18), d(2584) */
    volatile Uint32 txa_txa_646;
    /* Addr: h(A1C), d(2588) */
    volatile Uint32 txa_txa_647;
    /* Addr: h(A20), d(2592) */
    volatile Uint32 txa_txa_648;
    /* Addr: h(A24), d(2596) */
    volatile Uint32 txa_txa_649;
    /* Addr: h(A28), d(2600) */
    volatile Uint32 txa_txa_650;
    /* Addr: h(A2C), d(2604) */
    volatile Uint32 txa_txa_651;
    /* Addr: h(A30), d(2608) */
    volatile Uint32 txa_txa_652;
    /* Addr: h(A34), d(2612) */
    volatile Uint32 txa_txa_653;
    /* Addr: h(A38), d(2616) */
    volatile Uint32 txa_txa_654;
    /* Addr: h(A3C), d(2620) */
    volatile Uint32 txa_txa_655;
    /* Addr: h(A40), d(2624) */
    volatile Uint32 txa_txa_656;
    /* Addr: h(A44), d(2628) */
    volatile Uint32 txa_txa_657;
    /* Addr: h(A48), d(2632) */
    volatile Uint32 rsvd10[14];
    /* Addr: h(A80), d(2688) */
    volatile Uint32 txb_txb_672;
    /* Addr: h(A84), d(2692) */
    volatile Uint32 txb_txb_673;
    /* Addr: h(A88), d(2696) */
    volatile Uint32 txb_txb_674;
    /* Addr: h(A8C), d(2700) */
    volatile Uint32 txb_txb_675;
    /* Addr: h(A90), d(2704) */
    volatile Uint32 txb_txb_676;
    /* Addr: h(A94), d(2708) */
    volatile Uint32 txb_txb_677;
    /* Addr: h(A98), d(2712) */
    volatile Uint32 txb_txb_678;
    /* Addr: h(A9C), d(2716) */
    volatile Uint32 txb_txb_679;
    /* Addr: h(AA0), d(2720) */
    volatile Uint32 txb_txb_680;
    /* Addr: h(AA4), d(2724) */
    volatile Uint32 txb_txb_681;
    /* Addr: h(AA8), d(2728) */
    volatile Uint32 txb_txb_682;
    /* Addr: h(AAC), d(2732) */
    volatile Uint32 txb_txb_683;
    /* Addr: h(AB0), d(2736) */
    volatile Uint32 txb_txb_684;
    /* Addr: h(AB4), d(2740) */
    volatile Uint32 txb_txb_685;
    /* Addr: h(AB8), d(2744) */
    volatile Uint32 txb_txb_686;
    /* Addr: h(ABC), d(2748) */
    volatile Uint32 txb_txb_687;
    /* Addr: h(AC0), d(2752) */
    volatile Uint32 txb_txb_688;
    /* Addr: h(AC4), d(2756) */
    volatile Uint32 txb_txb_689;
    /* Addr: h(AC8), d(2760) */
    volatile Uint32 rsvd11[14];
    /* Addr: h(B00), d(2816) */
    volatile Uint32 txrx_txrx_704;
    /* Addr: h(B04), d(2820) */
    volatile Uint32 txrx_txrx_705;
    /* Addr: h(B08), d(2824) */
    volatile Uint32 txrx_txrx_706;
    /* Addr: h(B0C), d(2828) */
    volatile Uint32 txrx_txrx_707;
    /* Addr: h(B10), d(2832) */
    volatile Uint32 txrx_txrx_708;
    /* Addr: h(B14), d(2836) */
    volatile Uint32 txrx_txrx_709;
    /* Addr: h(B18), d(2840) */
    volatile Uint32 txrx_txrx_710;
    /* Addr: h(B1C), d(2844) */
    volatile Uint32 txrx_txrx_711;
    /* Addr: h(B20), d(2848) */
    volatile Uint32 txrx_txrx_712;
    /* Addr: h(B24), d(2852) */
    volatile Uint32 txrx_txrx_713;
    /* Addr: h(B28), d(2856) */
    volatile Uint32 txrx_txrx_714;
    /* Addr: h(B2C), d(2860) */
    volatile Uint32 txrx_txrx_715;
    /* Addr: h(B30), d(2864) */
    volatile Uint32 txrx_txrx_716;
    /* Addr: h(B34), d(2868) */
    volatile Uint32 txrx_txrx_717;
    /* Addr: h(B38), d(2872) */
    volatile Uint32 txrx_txrx_718;
    /* Addr: h(B3C), d(2876) */
    volatile Uint32 txrx_txrx_719;
    /* Addr: h(B40), d(2880) */
    volatile Uint32 txrx_txrx_720;
    /* Addr: h(B44), d(2884) */
    volatile Uint32 txrx_txrx_721;
    /* Addr: h(B48), d(2888) */
    volatile Uint32 rsvd12[64814];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 txa_txa_65536[128];
    /* Addr: h(40200), d(262656) */
    volatile Uint32 txa_txa_65664[128];
    /* Addr: h(40400), d(263168) */
    volatile Uint32 txa_txa_65792[128];
    /* Addr: h(40600), d(263680) */
    volatile Uint32 txb_txb_65920[128];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 txb_txb_66048[128];
    /* Addr: h(40A00), d(264704) */
    volatile Uint32 txb_txb_66176[128];
} CSL_DFE_TX_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* TXA_TXA_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 freq_0_lsb : 32;
#else 
    Uint32 freq_0_lsb : 32;
#endif 
} CSL_DFE_TX_TXA_TXA_1_REG;

/* mix anta lower 32 freq */
#define CSL_DFE_TX_TXA_TXA_1_REG_FREQ_0_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_TX_TXA_TXA_1_REG_FREQ_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_1_REG_FREQ_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_1_REG_ADDR (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_1_REG_RESETVAL (0x00000000u)

/* TXA_TXA_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 phase_0 : 16;
    Uint32 freq_0_msb : 16;
#else 
    Uint32 freq_0_msb : 16;
    Uint32 phase_0 : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_2_REG;

/* mix anta upper 16 freq */
#define CSL_DFE_TX_TXA_TXA_2_REG_FREQ_0_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_2_REG_FREQ_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_2_REG_FREQ_0_MSB_RESETVAL (0x00000000u)

/* mix anta phase */
#define CSL_DFE_TX_TXA_TXA_2_REG_PHASE_0_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_2_REG_PHASE_0_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_2_REG_PHASE_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_2_REG_ADDR (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_2_REG_RESETVAL (0x00000000u)

/* TXA_TXA_3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 freq_1_lsb : 32;
#else 
    Uint32 freq_1_lsb : 32;
#endif 
} CSL_DFE_TX_TXA_TXA_3_REG;

/* mix antb lower 32 freq */
#define CSL_DFE_TX_TXA_TXA_3_REG_FREQ_1_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_TX_TXA_TXA_3_REG_FREQ_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_3_REG_FREQ_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_3_REG_ADDR (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_3_REG_RESETVAL (0x00000000u)

/* TXA_TXA_4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 phase_1 : 16;
    Uint32 freq_1_msb : 16;
#else 
    Uint32 freq_1_msb : 16;
    Uint32 phase_1 : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_4_REG;

/* mix antb upper 16 freq */
#define CSL_DFE_TX_TXA_TXA_4_REG_FREQ_1_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_4_REG_FREQ_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_4_REG_FREQ_1_MSB_RESETVAL (0x00000000u)

/* mix antb phase */
#define CSL_DFE_TX_TXA_TXA_4_REG_PHASE_1_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_4_REG_PHASE_1_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_4_REG_PHASE_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_4_REG_ADDR (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_4_REG_RESETVAL (0x00000000u)

/* TXA_TXA_5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 5;
    Uint32 rsmp_init_ph_a : 3;
    Uint32 rsmp_ant_ph_a : 24;
#else 
    Uint32 rsmp_ant_ph_a : 24;
    Uint32 rsmp_init_ph_a : 3;
    Uint32 spare : 5;
#endif 
} CSL_DFE_TX_TXA_TXA_5_REG;

/* resampler a antenna phase */
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_ANT_PH_A_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_ANT_PH_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_ANT_PH_A_RESETVAL (0x00000000u)

/* rsmp_init_pha, initial phase for resampler a */
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_INIT_PH_A_MASK (0x07000000u)
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_INIT_PH_A_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXA_TXA_5_REG_RSMP_INIT_PH_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_5_REG_SPARE_MASK (0xF8000000u)
#define CSL_DFE_TX_TXA_TXA_5_REG_SPARE_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXA_TXA_5_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_5_REG_ADDR (0x00000014u)
#define CSL_DFE_TX_TXA_TXA_5_REG_RESETVAL (0x00000000u)

/* TXA_TXA_6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 5;
    Uint32 rsmp_init_ph_b : 3;
    Uint32 rsmp_ant_ph_b : 24;
#else 
    Uint32 rsmp_ant_ph_b : 24;
    Uint32 rsmp_init_ph_b : 3;
    Uint32 spare : 5;
#endif 
} CSL_DFE_TX_TXA_TXA_6_REG;

/* resampler b antenna phase */
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_ANT_PH_B_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_ANT_PH_B_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_ANT_PH_B_RESETVAL (0x00000000u)

/* rsmp_init_pha, initial phase for resampler b */
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_INIT_PH_B_MASK (0x07000000u)
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_INIT_PH_B_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXA_TXA_6_REG_RSMP_INIT_PH_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_6_REG_SPARE_MASK (0xF8000000u)
#define CSL_DFE_TX_TXA_TXA_6_REG_SPARE_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXA_TXA_6_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_6_REG_ADDR (0x00000018u)
#define CSL_DFE_TX_TXA_TXA_6_REG_RESETVAL (0x00000000u)

/* TXA_TXA_7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mc_mixq : 4;
    Uint32 mc_mixi : 4;
    Uint32 ssel_dcoff : 4;
    Uint32 ssel_mix : 4;
    Uint32 ssel_rsmp_ph_init : 4;
    Uint32 ssel_rsmp_cf_swap : 4;
    Uint32 rsmp_state : 4;
    Uint32 spare : 2;
    Uint32 rsmp_mode : 1;
    Uint32 dit_en : 1;
#else 
    Uint32 dit_en : 1;
    Uint32 rsmp_mode : 1;
    Uint32 spare : 2;
    Uint32 rsmp_state : 4;
    Uint32 ssel_rsmp_cf_swap : 4;
    Uint32 ssel_rsmp_ph_init : 4;
    Uint32 ssel_mix : 4;
    Uint32 ssel_dcoff : 4;
    Uint32 mc_mixi : 4;
    Uint32 mc_mixq : 4;
#endif 
} CSL_DFE_TX_TXA_TXA_7_REG;

/* mixer dither enable */
#define CSL_DFE_TX_TXA_TXA_7_REG_DIT_EN_MASK (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_7_REG_DIT_EN_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_DIT_EN_RESETVAL (0x00000000u)

/* rsmp_mode  0 = 1x; 1 = 2x; */
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_MODE_MASK (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_MODE_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_MODE_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_7_REG_SPARE_MASK (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_7_REG_SPARE_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SPARE_RESETVAL (0x00000000u)

/* rsmp_state_cnt, */
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_STATE_MASK (0x000000F0u)
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_STATE_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_7_REG_RSMP_STATE_RESETVAL (0x00000000u)

/* resampler coef swap sync */
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_CF_SWAP_MASK (0x00000F00u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_CF_SWAP_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_CF_SWAP_RESETVAL (0x00000000u)

/* resampler phase init sync */
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_PH_INIT_MASK (0x0000F000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_PH_INIT_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_RSMP_PH_INIT_RESETVAL (0x00000000u)

/* mix sync sel */
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_MIX_MASK (0x000F0000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_MIX_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_MIX_RESETVAL (0x00000000u)

/* dc offset sync sel */
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_DCOFF_MASK (0x00F00000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_DCOFF_SHIFT (0x00000014u)
#define CSL_DFE_TX_TXA_TXA_7_REG_SSEL_DCOFF_RESETVAL (0x00000000u)

/* mux control for mix I input;  see mc_* column in tx_configs.xlsx */
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXI_MASK (0x0F000000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXI_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXI_RESETVAL (0x00000000u)

/* mux control for mix Q input */
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXQ_MASK (0xF0000000u)
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXQ_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXA_TXA_7_REG_MC_MIXQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_7_REG_ADDR (0x0000001Cu)
#define CSL_DFE_TX_TXA_TXA_7_REG_RESETVAL (0x00000000u)

/* TXA_TXA_8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mc_bucql : 4;
    Uint32 mc_bucqe : 4;
    Uint32 mc_bucil : 4;
    Uint32 mc_bucie : 4;
    Uint32 mc_rsmpbb : 4;
    Uint32 mc_rsmpba : 4;
    Uint32 mc_rsmpab : 4;
    Uint32 mc_rsmpaa : 4;
#else 
    Uint32 mc_rsmpaa : 4;
    Uint32 mc_rsmpab : 4;
    Uint32 mc_rsmpba : 4;
    Uint32 mc_rsmpbb : 4;
    Uint32 mc_bucie : 4;
    Uint32 mc_bucil : 4;
    Uint32 mc_bucqe : 4;
    Uint32 mc_bucql : 4;
#endif 
} CSL_DFE_TX_TXA_TXA_8_REG;

/* mux control resampler A ai/aq inputs */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAA_MASK (0x0000000Fu)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAA_RESETVAL (0x00000000u)

/* mux control resampler A bi/bq inputs */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAB_MASK (0x000000F0u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAB_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPAB_RESETVAL (0x00000000u)

/* mux control resampler B ai/aq inputs */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBA_MASK (0x00000F00u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBA_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBA_RESETVAL (0x00000000u)

/* mux control resampler b bi/bq inputs */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBB_MASK (0x0000F000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBB_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_RSMPBB_RESETVAL (0x00000000u)

/* mux control for buc ie input */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIE_MASK (0x000F0000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIE_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIE_RESETVAL (0x00000000u)

/* mux control for buc il input */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIL_MASK (0x00F00000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIL_SHIFT (0x00000014u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCIL_RESETVAL (0x00000000u)

/* mux control for buc qe input */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQE_MASK (0x0F000000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQE_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQE_RESETVAL (0x00000000u)

/* mux control for buc ql input */
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQL_MASK (0xF0000000u)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXA_TXA_8_REG_MC_BUCQL_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_8_REG_ADDR (0x00000020u)
#define CSL_DFE_TX_TXA_TXA_8_REG_RESETVAL (0x00000000u)

/* TXA_TXA_9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dc_offset_aq : 16;
    Uint32 dc_offset_ai : 16;
#else 
    Uint32 dc_offset_ai : 16;
    Uint32 dc_offset_aq : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_9_REG;

/* dc offsets */
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AI_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AI_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AI_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AQ_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AQ_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_9_REG_DC_OFFSET_AQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_9_REG_ADDR (0x00000024u)
#define CSL_DFE_TX_TXA_TXA_9_REG_RESETVAL (0x00000000u)

/* TXA_TXA_10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dc_offset_bq : 16;
    Uint32 dc_offset_bi : 16;
#else 
    Uint32 dc_offset_bi : 16;
    Uint32 dc_offset_bq : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_10_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BI_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BI_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BI_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BQ_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BQ_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_10_REG_DC_OFFSET_BQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_10_REG_ADDR (0x00000028u)
#define CSL_DFE_TX_TXA_TXA_10_REG_RESETVAL (0x00000000u)

/* TXA_TXA_11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 10;
    Uint32 tb_sel : 5;
    Uint32 ssel_pa : 4;
    Uint32 addb_en : 1;
    Uint32 cc_pa : 2;
    Uint32 cc_mix : 2;
    Uint32 cc_buca : 2;
    Uint32 cc_bucb : 2;
    Uint32 cc_rsa : 2;
    Uint32 cc_rsb : 2;
#else 
    Uint32 cc_rsb : 2;
    Uint32 cc_rsa : 2;
    Uint32 cc_bucb : 2;
    Uint32 cc_buca : 2;
    Uint32 cc_mix : 2;
    Uint32 cc_pa : 2;
    Uint32 addb_en : 1;
    Uint32 ssel_pa : 4;
    Uint32 tb_sel : 5;
    Uint32 spare : 10;
#endif 
} CSL_DFE_TX_TXA_TXA_11_REG;

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSB_MASK (0x00000003u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSB_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSA_MASK (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSA_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_RSA_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCB_MASK (0x00000030u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCB_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCB_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCA_MASK (0x000000C0u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCA_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_BUCA_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_MIX_MASK (0x00000300u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_MIX_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_MIX_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_PA_MASK (0x00000C00u)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_PA_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXA_TXA_11_REG_CC_PA_RESETVAL (0x00000000u)

/* 1 to add other tx to this one */
#define CSL_DFE_TX_TXA_TXA_11_REG_ADDB_EN_MASK (0x00001000u)
#define CSL_DFE_TX_TXA_TXA_11_REG_ADDB_EN_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_11_REG_ADDB_EN_RESETVAL (0x00000000u)

/* pa protect sync select */
#define CSL_DFE_TX_TXA_TXA_11_REG_SSEL_PA_MASK (0x0001E000u)
#define CSL_DFE_TX_TXA_TXA_11_REG_SSEL_PA_SHIFT (0x0000000Du)
#define CSL_DFE_TX_TXA_TXA_11_REG_SSEL_PA_RESETVAL (0x00000000u)

/* test bus select */
#define CSL_DFE_TX_TXA_TXA_11_REG_TB_SEL_MASK (0x003E0000u)
#define CSL_DFE_TX_TXA_TXA_11_REG_TB_SEL_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXA_TXA_11_REG_TB_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_11_REG_SPARE_MASK (0xFFC00000u)
#define CSL_DFE_TX_TXA_TXA_11_REG_SPARE_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXA_TXA_11_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_11_REG_ADDR (0x0000002Cu)
#define CSL_DFE_TX_TXA_TXA_11_REG_RESETVAL (0x00000000u)

/* TXB_TXB_17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 freq_0_lsb : 32;
#else 
    Uint32 freq_0_lsb : 32;
#endif 
} CSL_DFE_TX_TXB_TXB_17_REG;

/* mix anta lower 32 freq */
#define CSL_DFE_TX_TXB_TXB_17_REG_FREQ_0_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_TX_TXB_TXB_17_REG_FREQ_0_LSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_17_REG_FREQ_0_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_17_REG_ADDR (0x00000044u)
#define CSL_DFE_TX_TXB_TXB_17_REG_RESETVAL (0x00000000u)

/* TXB_TXB_18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 phase_0 : 16;
    Uint32 freq_0_msb : 16;
#else 
    Uint32 freq_0_msb : 16;
    Uint32 phase_0 : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_18_REG;

/* mix anta upper 16 freq */
#define CSL_DFE_TX_TXB_TXB_18_REG_FREQ_0_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_18_REG_FREQ_0_MSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_18_REG_FREQ_0_MSB_RESETVAL (0x00000000u)

/* mix anta phase */
#define CSL_DFE_TX_TXB_TXB_18_REG_PHASE_0_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_18_REG_PHASE_0_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_18_REG_PHASE_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_18_REG_ADDR (0x00000048u)
#define CSL_DFE_TX_TXB_TXB_18_REG_RESETVAL (0x00000000u)

/* TXB_TXB_19 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 freq_1_lsb : 32;
#else 
    Uint32 freq_1_lsb : 32;
#endif 
} CSL_DFE_TX_TXB_TXB_19_REG;

/* mix antb lower 32 freq */
#define CSL_DFE_TX_TXB_TXB_19_REG_FREQ_1_LSB_MASK (0xFFFFFFFFu)
#define CSL_DFE_TX_TXB_TXB_19_REG_FREQ_1_LSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_19_REG_FREQ_1_LSB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_19_REG_ADDR (0x0000004Cu)
#define CSL_DFE_TX_TXB_TXB_19_REG_RESETVAL (0x00000000u)

/* TXB_TXB_20 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 phase_1 : 16;
    Uint32 freq_1_msb : 16;
#else 
    Uint32 freq_1_msb : 16;
    Uint32 phase_1 : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_20_REG;

/* mix antb upper 16 freq */
#define CSL_DFE_TX_TXB_TXB_20_REG_FREQ_1_MSB_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_20_REG_FREQ_1_MSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_20_REG_FREQ_1_MSB_RESETVAL (0x00000000u)

/* mix antb phase */
#define CSL_DFE_TX_TXB_TXB_20_REG_PHASE_1_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_20_REG_PHASE_1_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_20_REG_PHASE_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_20_REG_ADDR (0x00000050u)
#define CSL_DFE_TX_TXB_TXB_20_REG_RESETVAL (0x00000000u)

/* TXB_TXB_21 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 5;
    Uint32 rsmp_init_ph_a : 3;
    Uint32 rsmp_ant_ph_a : 24;
#else 
    Uint32 rsmp_ant_ph_a : 24;
    Uint32 rsmp_init_ph_a : 3;
    Uint32 spare : 5;
#endif 
} CSL_DFE_TX_TXB_TXB_21_REG;

/* resampler a antenna phase */
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_ANT_PH_A_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_ANT_PH_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_ANT_PH_A_RESETVAL (0x00000000u)

/* rsmp_init_pha, initial phase for resampler a */
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_INIT_PH_A_MASK (0x07000000u)
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_INIT_PH_A_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXB_TXB_21_REG_RSMP_INIT_PH_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_21_REG_SPARE_MASK (0xF8000000u)
#define CSL_DFE_TX_TXB_TXB_21_REG_SPARE_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXB_TXB_21_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_21_REG_ADDR (0x00000054u)
#define CSL_DFE_TX_TXB_TXB_21_REG_RESETVAL (0x00000000u)

/* TXB_TXB_22 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 5;
    Uint32 rsmp_init_ph_b : 3;
    Uint32 rsmp_ant_ph_b : 24;
#else 
    Uint32 rsmp_ant_ph_b : 24;
    Uint32 rsmp_init_ph_b : 3;
    Uint32 spare : 5;
#endif 
} CSL_DFE_TX_TXB_TXB_22_REG;

/* resampler b antenna phase */
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_ANT_PH_B_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_ANT_PH_B_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_ANT_PH_B_RESETVAL (0x00000000u)

/* rsmp_init_pha, initial phase for resampler b */
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_INIT_PH_B_MASK (0x07000000u)
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_INIT_PH_B_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXB_TXB_22_REG_RSMP_INIT_PH_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_22_REG_SPARE_MASK (0xF8000000u)
#define CSL_DFE_TX_TXB_TXB_22_REG_SPARE_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXB_TXB_22_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_22_REG_ADDR (0x00000058u)
#define CSL_DFE_TX_TXB_TXB_22_REG_RESETVAL (0x00000000u)

/* TXB_TXB_23 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mc_mixq : 4;
    Uint32 mc_mixi : 4;
    Uint32 ssel_dcoff : 4;
    Uint32 ssel_mix : 4;
    Uint32 ssel_rsmp_ph_init : 4;
    Uint32 ssel_rsmp_cf_swap : 4;
    Uint32 rsmp_state : 4;
    Uint32 spare : 2;
    Uint32 rsmp_mode : 1;
    Uint32 dit_en : 1;
#else 
    Uint32 dit_en : 1;
    Uint32 rsmp_mode : 1;
    Uint32 spare : 2;
    Uint32 rsmp_state : 4;
    Uint32 ssel_rsmp_cf_swap : 4;
    Uint32 ssel_rsmp_ph_init : 4;
    Uint32 ssel_mix : 4;
    Uint32 ssel_dcoff : 4;
    Uint32 mc_mixi : 4;
    Uint32 mc_mixq : 4;
#endif 
} CSL_DFE_TX_TXB_TXB_23_REG;

/* mixer dither enable */
#define CSL_DFE_TX_TXB_TXB_23_REG_DIT_EN_MASK (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_23_REG_DIT_EN_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_DIT_EN_RESETVAL (0x00000000u)

/* rsmp_mode  0 = 1x; 1 = 2x; */
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_MODE_MASK (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_MODE_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_MODE_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_23_REG_SPARE_MASK (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_23_REG_SPARE_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SPARE_RESETVAL (0x00000000u)

/* rsmp_state_cnt, */
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_STATE_MASK (0x000000F0u)
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_STATE_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_23_REG_RSMP_STATE_RESETVAL (0x00000000u)

/* resampler coef swap sync */
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_CF_SWAP_MASK (0x00000F00u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_CF_SWAP_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_CF_SWAP_RESETVAL (0x00000000u)

/* resampler phase init sync */
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_PH_INIT_MASK (0x0000F000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_PH_INIT_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_RSMP_PH_INIT_RESETVAL (0x00000000u)

/* mix sync sel */
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_MIX_MASK (0x000F0000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_MIX_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_MIX_RESETVAL (0x00000000u)

/* dc offset sync sel */
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_DCOFF_MASK (0x00F00000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_DCOFF_SHIFT (0x00000014u)
#define CSL_DFE_TX_TXB_TXB_23_REG_SSEL_DCOFF_RESETVAL (0x00000000u)

/* mux control for mix I input;  see mc_* column in tx_configs.xlsx */
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXI_MASK (0x0F000000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXI_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXI_RESETVAL (0x00000000u)

/* mux control for mix Q input */
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXQ_MASK (0xF0000000u)
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXQ_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXB_TXB_23_REG_MC_MIXQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_23_REG_ADDR (0x0000005Cu)
#define CSL_DFE_TX_TXB_TXB_23_REG_RESETVAL (0x00000000u)

/* TXB_TXB_24 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mc_bucql : 4;
    Uint32 mc_bucqe : 4;
    Uint32 mc_bucil : 4;
    Uint32 mc_bucie : 4;
    Uint32 mc_rsmpbb : 4;
    Uint32 mc_rsmpba : 4;
    Uint32 mc_rsmpab : 4;
    Uint32 mc_rsmpaa : 4;
#else 
    Uint32 mc_rsmpaa : 4;
    Uint32 mc_rsmpab : 4;
    Uint32 mc_rsmpba : 4;
    Uint32 mc_rsmpbb : 4;
    Uint32 mc_bucie : 4;
    Uint32 mc_bucil : 4;
    Uint32 mc_bucqe : 4;
    Uint32 mc_bucql : 4;
#endif 
} CSL_DFE_TX_TXB_TXB_24_REG;

/* mux control resampler A ai/aq inputs */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAA_MASK (0x0000000Fu)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAA_RESETVAL (0x00000000u)

/* mux control resampler A bi/bq inputs */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAB_MASK (0x000000F0u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAB_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPAB_RESETVAL (0x00000000u)

/* mux control resampler B ai/aq inputs */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBA_MASK (0x00000F00u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBA_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBA_RESETVAL (0x00000000u)

/* mux control resampler b bi/bq inputs */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBB_MASK (0x0000F000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBB_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_RSMPBB_RESETVAL (0x00000000u)

/* mux control for buc ie input */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIE_MASK (0x000F0000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIE_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIE_RESETVAL (0x00000000u)

/* mux control for buc il input */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIL_MASK (0x00F00000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIL_SHIFT (0x00000014u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCIL_RESETVAL (0x00000000u)

/* mux control for buc qe input */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQE_MASK (0x0F000000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQE_SHIFT (0x00000018u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQE_RESETVAL (0x00000000u)

/* mux control for buc ql input */
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQL_MASK (0xF0000000u)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXB_TXB_24_REG_MC_BUCQL_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_24_REG_ADDR (0x00000060u)
#define CSL_DFE_TX_TXB_TXB_24_REG_RESETVAL (0x00000000u)

/* TXB_TXB_25 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dc_offset_aq : 16;
    Uint32 dc_offset_ai : 16;
#else 
    Uint32 dc_offset_ai : 16;
    Uint32 dc_offset_aq : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_25_REG;

/* dc offsets */
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AI_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AI_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AI_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AQ_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AQ_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_25_REG_DC_OFFSET_AQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_25_REG_ADDR (0x00000064u)
#define CSL_DFE_TX_TXB_TXB_25_REG_RESETVAL (0x00000000u)

/* TXB_TXB_26 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dc_offset_bq : 16;
    Uint32 dc_offset_bi : 16;
#else 
    Uint32 dc_offset_bi : 16;
    Uint32 dc_offset_bq : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_26_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BI_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BI_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BI_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BQ_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BQ_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_26_REG_DC_OFFSET_BQ_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_26_REG_ADDR (0x00000068u)
#define CSL_DFE_TX_TXB_TXB_26_REG_RESETVAL (0x00000000u)

/* TXB_TXB_27 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 10;
    Uint32 tb_sel : 5;
    Uint32 ssel_pa : 4;
    Uint32 addb_en : 1;
    Uint32 cc_pa : 2;
    Uint32 cc_mix : 2;
    Uint32 cc_buca : 2;
    Uint32 cc_bucb : 2;
    Uint32 cc_rsa : 2;
    Uint32 cc_rsb : 2;
#else 
    Uint32 cc_rsb : 2;
    Uint32 cc_rsa : 2;
    Uint32 cc_bucb : 2;
    Uint32 cc_buca : 2;
    Uint32 cc_mix : 2;
    Uint32 cc_pa : 2;
    Uint32 addb_en : 1;
    Uint32 ssel_pa : 4;
    Uint32 tb_sel : 5;
    Uint32 spare : 10;
#endif 
} CSL_DFE_TX_TXB_TXB_27_REG;

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSB_MASK (0x00000003u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSB_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSB_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSA_MASK (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSA_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_RSA_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCB_MASK (0x00000030u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCB_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCB_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCA_MASK (0x000000C0u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCA_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_BUCA_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_MIX_MASK (0x00000300u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_MIX_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_MIX_RESETVAL (0x00000000u)

/* 00, 01 = off; 10 = nen; 11 = men */
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_PA_MASK (0x00000C00u)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_PA_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXB_TXB_27_REG_CC_PA_RESETVAL (0x00000000u)

/* 1 to add other tx to this one */
#define CSL_DFE_TX_TXB_TXB_27_REG_ADDB_EN_MASK (0x00001000u)
#define CSL_DFE_TX_TXB_TXB_27_REG_ADDB_EN_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_27_REG_ADDB_EN_RESETVAL (0x00000000u)

/* pa protect sync select */
#define CSL_DFE_TX_TXB_TXB_27_REG_SSEL_PA_MASK (0x0001E000u)
#define CSL_DFE_TX_TXB_TXB_27_REG_SSEL_PA_SHIFT (0x0000000Du)
#define CSL_DFE_TX_TXB_TXB_27_REG_SSEL_PA_RESETVAL (0x00000000u)

/* test bus select */
#define CSL_DFE_TX_TXB_TXB_27_REG_TB_SEL_MASK (0x003E0000u)
#define CSL_DFE_TX_TXB_TXB_27_REG_TB_SEL_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXB_TXB_27_REG_TB_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_27_REG_SPARE_MASK (0xFFC00000u)
#define CSL_DFE_TX_TXB_TXB_27_REG_SPARE_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXB_TXB_27_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_27_REG_ADDR (0x0000006Cu)
#define CSL_DFE_TX_TXB_TXB_27_REG_RESETVAL (0x00000000u)

/* TXA_TXA_32 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 buca_coef : 18;
#else 
    Uint32 buca_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXA_TXA_32_REG;

/* buca coef */
#define CSL_DFE_TX_TXA_TXA_32_REG_BUCA_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXA_TXA_32_REG_BUCA_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_32_REG_BUCA_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_32_REG_ADDR (0x00000080u)
#define CSL_DFE_TX_TXA_TXA_32_REG_RESETVAL (0x00000000u)

/* TXA_TXA_47 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 15;
    Uint32 in_mux_bb_ctl : 2;
    Uint32 in_mux_ba_ctl : 3;
    Uint32 in_mux_ab_ctl : 2;
    Uint32 b_path_enable : 1;
    Uint32 add_mux_b : 2;
    Uint32 add_mux_a : 2;
    Uint32 interp : 1;
    Uint32 even_b : 1;
    Uint32 even_a : 1;
    Uint32 cascade : 1;
    Uint32 two_ant : 1;
#else 
    Uint32 two_ant : 1;
    Uint32 cascade : 1;
    Uint32 even_a : 1;
    Uint32 even_b : 1;
    Uint32 interp : 1;
    Uint32 add_mux_a : 2;
    Uint32 add_mux_b : 2;
    Uint32 b_path_enable : 1;
    Uint32 in_mux_ab_ctl : 2;
    Uint32 in_mux_ba_ctl : 3;
    Uint32 in_mux_bb_ctl : 2;
    Uint32 spare : 15;
#endif 
} CSL_DFE_TX_TXA_TXA_47_REG;

/* 1 if in two anntenna mode; 0 if 1 antenna */
#define CSL_DFE_TX_TXA_TXA_47_REG_TWO_ANT_MASK (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_47_REG_TWO_ANT_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_47_REG_TWO_ANT_RESETVAL (0x00000000u)

/* cascade 1 if filters cascaded */
#define CSL_DFE_TX_TXA_TXA_47_REG_CASCADE_MASK (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_47_REG_CASCADE_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_47_REG_CASCADE_RESETVAL (0x00000000u)

/* 1 if buca even sym 0 if odd */
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_A_MASK (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_A_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_A_RESETVAL (0x00000000u)

/* 1 if bucb even sym 0 if odd */
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_B_MASK (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_B_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXA_TXA_47_REG_EVEN_B_RESETVAL (0x00000000u)

/* 1 if interpolating */
#define CSL_DFE_TX_TXA_TXA_47_REG_INTERP_MASK (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_47_REG_INTERP_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_47_REG_INTERP_RESETVAL (0x00000000u)

/* 0,1 for 0; 2 for alt, 3 for mpy */
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_A_MASK (0x00000060u)
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_A_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_A_RESETVAL (0x00000000u)

/* 0,1 for 0; 2 for alt, 3 for mpy */
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_B_MASK (0x00000180u)
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_B_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXA_TXA_47_REG_ADD_MUX_B_RESETVAL (0x00000000u)

/* 1 if b path in buc 1 enabled */
#define CSL_DFE_TX_TXA_TXA_47_REG_B_PATH_ENABLE_MASK (0x00000200u)
#define CSL_DFE_TX_TXA_TXA_47_REG_B_PATH_ENABLE_SHIFT (0x00000009u)
#define CSL_DFE_TX_TXA_TXA_47_REG_B_PATH_ENABLE_RESETVAL (0x00000000u)

/* 0,1=0;2=ie;3=il */
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_AB_CTL_MASK (0x00000C00u)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_AB_CTL_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_AB_CTL_RESETVAL (0x00000000u)

/* 0-3=0;4=ie;5=il;6=qe;7=ql */
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BA_CTL_MASK (0x00007000u)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BA_CTL_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BA_CTL_RESETVAL (0x00000000u)

/* 0,1=0;2=qe;3=ql */
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BB_CTL_MASK (0x00018000u)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BB_CTL_SHIFT (0x0000000Fu)
#define CSL_DFE_TX_TXA_TXA_47_REG_IN_MUX_BB_CTL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_47_REG_SPARE_MASK (0xFFFE0000u)
#define CSL_DFE_TX_TXA_TXA_47_REG_SPARE_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXA_TXA_47_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_47_REG_ADDR (0x000000BCu)
#define CSL_DFE_TX_TXA_TXA_47_REG_RESETVAL (0x00000000u)

/* TXA_TXA_48 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 bucb_coef : 18;
#else 
    Uint32 bucb_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXA_TXA_48_REG;

/* bucb coef */
#define CSL_DFE_TX_TXA_TXA_48_REG_BUCB_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXA_TXA_48_REG_BUCB_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_48_REG_BUCB_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_48_REG_ADDR (0x000000C0u)
#define CSL_DFE_TX_TXA_TXA_48_REG_RESETVAL (0x00000000u)

/* TXB_TXB_64 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 buca_coef : 18;
#else 
    Uint32 buca_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXB_TXB_64_REG;

/* buca coef */
#define CSL_DFE_TX_TXB_TXB_64_REG_BUCA_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXB_TXB_64_REG_BUCA_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_64_REG_BUCA_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_64_REG_ADDR (0x00000100u)
#define CSL_DFE_TX_TXB_TXB_64_REG_RESETVAL (0x00000000u)

/* TXB_TXB_79 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 15;
    Uint32 in_mux_bb_ctl : 2;
    Uint32 in_mux_ba_ctl : 3;
    Uint32 in_mux_ab_ctl : 2;
    Uint32 b_path_enable : 1;
    Uint32 add_mux_b : 2;
    Uint32 add_mux_a : 2;
    Uint32 interp : 1;
    Uint32 even_b : 1;
    Uint32 even_a : 1;
    Uint32 cascade : 1;
    Uint32 two_ant : 1;
#else 
    Uint32 two_ant : 1;
    Uint32 cascade : 1;
    Uint32 even_a : 1;
    Uint32 even_b : 1;
    Uint32 interp : 1;
    Uint32 add_mux_a : 2;
    Uint32 add_mux_b : 2;
    Uint32 b_path_enable : 1;
    Uint32 in_mux_ab_ctl : 2;
    Uint32 in_mux_ba_ctl : 3;
    Uint32 in_mux_bb_ctl : 2;
    Uint32 spare : 15;
#endif 
} CSL_DFE_TX_TXB_TXB_79_REG;

/* 1 if in two anntenna mode; 0 if 1 antenna */
#define CSL_DFE_TX_TXB_TXB_79_REG_TWO_ANT_MASK (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_79_REG_TWO_ANT_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_79_REG_TWO_ANT_RESETVAL (0x00000000u)

/* cascade 1 if filters cascaded */
#define CSL_DFE_TX_TXB_TXB_79_REG_CASCADE_MASK (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_79_REG_CASCADE_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_79_REG_CASCADE_RESETVAL (0x00000000u)

/* 1 if bucb even sym 0 if odd */
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_A_MASK (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_A_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_A_RESETVAL (0x00000000u)

/* 1 if bucb even sym 0 if odd */
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_B_MASK (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_B_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXB_TXB_79_REG_EVEN_B_RESETVAL (0x00000000u)

/* 1 if interpolating */
#define CSL_DFE_TX_TXB_TXB_79_REG_INTERP_MASK (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_79_REG_INTERP_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_79_REG_INTERP_RESETVAL (0x00000000u)

/* 0,1 for 0; 2 for alt, 3 for mpy */
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_A_MASK (0x00000060u)
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_A_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_A_RESETVAL (0x00000000u)

/* 0,1 for 0; 2 for alt, 3 for mpy */
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_B_MASK (0x00000180u)
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_B_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXB_TXB_79_REG_ADD_MUX_B_RESETVAL (0x00000000u)

/* 1 if b path in buc 1 enabled */
#define CSL_DFE_TX_TXB_TXB_79_REG_B_PATH_ENABLE_MASK (0x00000200u)
#define CSL_DFE_TX_TXB_TXB_79_REG_B_PATH_ENABLE_SHIFT (0x00000009u)
#define CSL_DFE_TX_TXB_TXB_79_REG_B_PATH_ENABLE_RESETVAL (0x00000000u)

/* 0,1=0;2=ie;3=il */
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_AB_CTL_MASK (0x00000C00u)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_AB_CTL_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_AB_CTL_RESETVAL (0x00000000u)

/* 0-3=0;4=ie;5=il;6=qe;7=ql */
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BA_CTL_MASK (0x00007000u)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BA_CTL_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BA_CTL_RESETVAL (0x00000000u)

/* 0,1=0;2=qe;3=ql */
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BB_CTL_MASK (0x00018000u)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BB_CTL_SHIFT (0x0000000Fu)
#define CSL_DFE_TX_TXB_TXB_79_REG_IN_MUX_BB_CTL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_79_REG_SPARE_MASK (0xFFFE0000u)
#define CSL_DFE_TX_TXB_TXB_79_REG_SPARE_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXB_TXB_79_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_79_REG_ADDR (0x0000013Cu)
#define CSL_DFE_TX_TXB_TXB_79_REG_RESETVAL (0x00000000u)

/* TXB_TXB_80 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 bucb_coef : 18;
#else 
    Uint32 bucb_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXB_TXB_80_REG;

/* bucb coef */
#define CSL_DFE_TX_TXB_TXB_80_REG_BUCB_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXB_TXB_80_REG_BUCB_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_80_REG_BUCB_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_80_REG_ADDR (0x00000140u)
#define CSL_DFE_TX_TXB_TXB_80_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_96 */
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
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_ADDR (0x00000180u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_96_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_97 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG;

/* ramp starting value */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG_ADDR (0x00000184u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_97_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_98 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG;

/* ramp starting value */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG_ADDR (0x00000188u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_98_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_99 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG_ADDR (0x0000018Cu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_99_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_100 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG_ADDR (0x00000190u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_100_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_101 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG_ADDR (0x00000194u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_101_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_102 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG_ADDR (0x00000198u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_102_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_103 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG_ADDR (0x0000019Cu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_103_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN_SIGNAL_GEN_104 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bits : 16;
#else 
    Uint32 bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG_BITS_SHIFT (0x00000000u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG_ADDR (0x000001A0u)
#define CSL_DFE_TX_SIGNAL_GEN_SIGNAL_GEN_104_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHECK_SUM_105 */
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
} CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_MODE_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_SPARE_MASK (0x0000000Eu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_SPARE_SHIFT (0x00000001u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_SPARE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_ADDR (0x000001A4u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_105_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHECK_SUM_106 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG_ADDR (0x000001A8u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_106_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHECK_SUM_107 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chan_sel : 8;
#else 
    Uint32 chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG_ADDR (0x000001ACu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_107_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHECK_SUM_108 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG_ADDR (0x000001B0u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_108_REG_RESETVAL (0x00000000u)

/* CHECK_SUM_CHECK_SUM_109 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG_ADDR (0x000001B4u)
#define CSL_DFE_TX_CHECK_SUM_CHECK_SUM_109_REG_RESETVAL (0x00000000u)

/* TX_TX_110 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 28;
    Uint32 ssel_cksum : 4;
#else 
    Uint32 ssel_cksum : 4;
    Uint32 spare : 28;
#endif 
} CSL_DFE_TX_TX_TX_110_REG;

/* check sum sync select */
#define CSL_DFE_TX_TX_TX_110_REG_SSEL_CKSUM_MASK (0x0000000Fu)
#define CSL_DFE_TX_TX_TX_110_REG_SSEL_CKSUM_SHIFT (0x00000000u)
#define CSL_DFE_TX_TX_TX_110_REG_SSEL_CKSUM_RESETVAL (0x00000000u)

/* cascade 1 if filters cascaded */
#define CSL_DFE_TX_TX_TX_110_REG_SPARE_MASK (0xFFFFFFF0u)
#define CSL_DFE_TX_TX_TX_110_REG_SPARE_SHIFT (0x00000004u)
#define CSL_DFE_TX_TX_TX_110_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TX_TX_110_REG_ADDR (0x000001B8u)
#define CSL_DFE_TX_TX_TX_110_REG_RESETVAL (0x00000000u)

/* TXA_TXA_128 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpa_coef : 18;
#else 
    Uint32 rsmpa_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXA_TXA_128_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_128_REG_RSMPA_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXA_TXA_128_REG_RSMPA_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_128_REG_RSMPA_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_128_REG_ADDR (0x00000200u)
#define CSL_DFE_TX_TXA_TXA_128_REG_RESETVAL (0x00000000u)

/* TXA_TXA_256 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpb_coef : 18;
#else 
    Uint32 rsmpb_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXA_TXA_256_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_256_REG_RSMPB_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXA_TXA_256_REG_RSMPB_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_256_REG_RSMPB_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_256_REG_ADDR (0x00000400u)
#define CSL_DFE_TX_TXA_TXA_256_REG_RESETVAL (0x00000000u)

/* TXB_TXB_384 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpa_coef : 18;
#else 
    Uint32 rsmpa_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXB_TXB_384_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_384_REG_RSMPA_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXB_TXB_384_REG_RSMPA_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_384_REG_RSMPA_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_384_REG_ADDR (0x00000600u)
#define CSL_DFE_TX_TXB_TXB_384_REG_RESETVAL (0x00000000u)

/* TXB_TXB_512 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 rsmpb_coef : 18;
#else 
    Uint32 rsmpb_coef : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_TX_TXB_TXB_512_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_512_REG_RSMPB_COEF_MASK (0x0003FFFFu)
#define CSL_DFE_TX_TXB_TXB_512_REG_RSMPB_COEF_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_512_REG_RSMPB_COEF_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_512_REG_ADDR (0x00000800u)
#define CSL_DFE_TX_TXB_TXB_512_REG_RESETVAL (0x00000000u)

/* TXA_TXA_640 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 factory_test_force_a_output_0 : 1;
    Uint32 two_ant_mode : 1;
    Uint32 tha6_sel : 1;
    Uint32 tha2_sel : 1;
    Uint32 tha1_sel : 1;
    Uint32 mu_1_a : 5;
    Uint32 mu_0_a : 5;
    Uint32 threshold_a : 17;
#else 
    Uint32 threshold_a : 17;
    Uint32 mu_0_a : 5;
    Uint32 mu_1_a : 5;
    Uint32 tha1_sel : 1;
    Uint32 tha2_sel : 1;
    Uint32 tha6_sel : 1;
    Uint32 two_ant_mode : 1;
    Uint32 factory_test_force_a_output_0 : 1;
#endif 
} CSL_DFE_TX_TXA_TXA_640_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_640_REG_THRESHOLD_A_MASK (0x0001FFFFu)
#define CSL_DFE_TX_TXA_TXA_640_REG_THRESHOLD_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_THRESHOLD_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_0_A_MASK (0x003E0000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_0_A_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_0_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_1_A_MASK (0x07C00000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_1_A_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXA_TXA_640_REG_MU_1_A_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a1 */
#define CSL_DFE_TX_TXA_TXA_640_REG_THA1_SEL_MASK (0x08000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA1_SEL_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA1_SEL_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a2 */
#define CSL_DFE_TX_TXA_TXA_640_REG_THA2_SEL_MASK (0x10000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA2_SEL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA2_SEL_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a6 */
#define CSL_DFE_TX_TXA_TXA_640_REG_THA6_SEL_MASK (0x20000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA6_SEL_SHIFT (0x0000001Du)
#define CSL_DFE_TX_TXA_TXA_640_REG_THA6_SEL_RESETVAL (0x00000000u)

/* 1 if in 2 antenna mode */
#define CSL_DFE_TX_TXA_TXA_640_REG_TWO_ANT_MODE_MASK (0x40000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_TWO_ANT_MODE_SHIFT (0x0000001Eu)
#define CSL_DFE_TX_TXA_TXA_640_REG_TWO_ANT_MODE_RESETVAL (0x00000000u)

/* Factory test bit keep programmed to 0 when 1 forces tx ouputs to 0.  */
#define CSL_DFE_TX_TXA_TXA_640_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_MASK (0x80000000u)
#define CSL_DFE_TX_TXA_TXA_640_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_SHIFT (0x0000001Fu)
#define CSL_DFE_TX_TXA_TXA_640_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_640_REG_ADDR (0x00000A00u)
#define CSL_DFE_TX_TXA_TXA_640_REG_RESETVAL (0x00000000u)

/* TXA_TXA_641 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 factory_test_force_b_output_0 : 1;
    Uint32 spare : 1;
    Uint32 thb6_sel : 1;
    Uint32 thb2_sel : 1;
    Uint32 thb1_sel : 1;
    Uint32 mu_1_b : 5;
    Uint32 mu_0_b : 5;
    Uint32 threshold_b : 17;
#else 
    Uint32 threshold_b : 17;
    Uint32 mu_0_b : 5;
    Uint32 mu_1_b : 5;
    Uint32 thb1_sel : 1;
    Uint32 thb2_sel : 1;
    Uint32 thb6_sel : 1;
    Uint32 spare : 1;
    Uint32 factory_test_force_b_output_0 : 1;
#endif 
} CSL_DFE_TX_TXA_TXA_641_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_THRESHOLD_B_MASK (0x0001FFFFu)
#define CSL_DFE_TX_TXA_TXA_641_REG_THRESHOLD_B_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_THRESHOLD_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_0_B_MASK (0x003E0000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_0_B_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_0_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_1_B_MASK (0x07C00000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_1_B_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXA_TXA_641_REG_MU_1_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_THB1_SEL_MASK (0x08000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB1_SEL_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB1_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_THB2_SEL_MASK (0x10000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB2_SEL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB2_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_THB6_SEL_MASK (0x20000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB6_SEL_SHIFT (0x0000001Du)
#define CSL_DFE_TX_TXA_TXA_641_REG_THB6_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_641_REG_SPARE_MASK (0x40000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_SPARE_SHIFT (0x0000001Eu)
#define CSL_DFE_TX_TXA_TXA_641_REG_SPARE_RESETVAL (0x00000000u)

/* Factory test bit keep programmed to 0 when 1 forces tx ouputs to 0.  */
#define CSL_DFE_TX_TXA_TXA_641_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_MASK (0x80000000u)
#define CSL_DFE_TX_TXA_TXA_641_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_SHIFT (0x0000001Fu)
#define CSL_DFE_TX_TXA_TXA_641_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_641_REG_ADDR (0x00000A04u)
#define CSL_DFE_TX_TXA_TXA_641_REG_RESETVAL (0x00000000u)

/* TXA_TXA_642 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cca_cnt : 16;
    Uint32 cca_thr : 16;
#else 
    Uint32 cca_thr : 16;
    Uint32 cca_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_642_REG;

/* see pa.pptx for definitions of thresholds */
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_642_REG_CCA_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_642_REG_ADDR (0x00000A08u)
#define CSL_DFE_TX_TXA_TXA_642_REG_RESETVAL (0x00000000u)

/* TXA_TXA_643 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 ccb_cnt : 16;
    Uint32 ccb_thr : 16;
#else 
    Uint32 ccb_thr : 16;
    Uint32 ccb_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_643_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_643_REG_CCB_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_643_REG_ADDR (0x00000A0Cu)
#define CSL_DFE_TX_TXA_TXA_643_REG_RESETVAL (0x00000000u)

/* TXA_TXA_644 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_0_b : 16;
    Uint32 th_0_a : 16;
#else 
    Uint32 th_0_a : 16;
    Uint32 th_0_b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_644_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_644_REG_TH_0_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_644_REG_ADDR (0x00000A10u)
#define CSL_DFE_TX_TXA_TXA_644_REG_RESETVAL (0x00000000u)

/* TXA_TXA_645 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_1_b : 16;
    Uint32 th_1_a : 16;
#else 
    Uint32 th_1_a : 16;
    Uint32 th_1_b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_645_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_645_REG_TH_1_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_645_REG_ADDR (0x00000A14u)
#define CSL_DFE_TX_TXA_TXA_645_REG_RESETVAL (0x00000000u)

/* TXA_TXA_646 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_2_b : 16;
    Uint32 th_2_a : 16;
#else 
    Uint32 th_2_a : 16;
    Uint32 th_2_b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_646_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_646_REG_TH_2_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_646_REG_ADDR (0x00000A18u)
#define CSL_DFE_TX_TXA_TXA_646_REG_RESETVAL (0x00000000u)

/* TXA_TXA_647 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_4_b : 16;
    Uint32 th_4_a : 16;
#else 
    Uint32 th_4_a : 16;
    Uint32 th_4_b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_647_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_647_REG_TH_4_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_647_REG_ADDR (0x00000A1Cu)
#define CSL_DFE_TX_TXA_TXA_647_REG_RESETVAL (0x00000000u)

/* TXA_TXA_648 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 d50b : 16;
    Uint32 d50a : 16;
#else 
    Uint32 d50a : 16;
    Uint32 d50b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_648_REG;

/* ms 16 bits */
#define CSL_DFE_TX_TXA_TXA_648_REG_D50A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_648_REG_D50A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_648_REG_D50A_RESETVAL (0x00000000u)

/* ms 16 bits */
#define CSL_DFE_TX_TXA_TXA_648_REG_D50B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_648_REG_D50B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_648_REG_D50B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_648_REG_ADDR (0x00000A20u)
#define CSL_DFE_TX_TXA_TXA_648_REG_RESETVAL (0x00000000u)

/* TXA_TXA_649 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 d51b : 16;
    Uint32 d51a : 16;
#else 
    Uint32 d51a : 16;
    Uint32 d51b : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_649_REG;

/* ms 16 bits */
#define CSL_DFE_TX_TXA_TXA_649_REG_D51A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_649_REG_D51A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_649_REG_D51A_RESETVAL (0x00000000u)

/* ms 16 bits */
#define CSL_DFE_TX_TXA_TXA_649_REG_D51B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_649_REG_D51B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_649_REG_D51B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_649_REG_ADDR (0x00000A24u)
#define CSL_DFE_TX_TXA_TXA_649_REG_RESETVAL (0x00000000u)

/* TXA_TXA_650 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peak_a_cnt : 16;
    Uint32 peak_a_thr : 16;
#else 
    Uint32 peak_a_thr : 16;
    Uint32 peak_a_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_650_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_650_REG_PEAK_A_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_650_REG_ADDR (0x00000A28u)
#define CSL_DFE_TX_TXA_TXA_650_REG_RESETVAL (0x00000000u)

/* TXA_TXA_651 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peak_b_cnt : 16;
    Uint32 peak_b_thr : 16;
#else 
    Uint32 peak_b_thr : 16;
    Uint32 peak_b_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_651_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_651_REG_PEAK_B_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_651_REG_ADDR (0x00000A2Cu)
#define CSL_DFE_TX_TXA_TXA_651_REG_RESETVAL (0x00000000u)

/* TXA_TXA_652 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peakgain_a_cnt : 16;
    Uint32 peakgain_a_thr : 16;
#else 
    Uint32 peakgain_a_thr : 16;
    Uint32 peakgain_a_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_652_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_652_REG_PEAKGAIN_A_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_652_REG_ADDR (0x00000A30u)
#define CSL_DFE_TX_TXA_TXA_652_REG_RESETVAL (0x00000000u)

/* TXA_TXA_653 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peakgain_b_cnt : 16;
    Uint32 peakgain_b_thr : 16;
#else 
    Uint32 peakgain_b_thr : 16;
    Uint32 peakgain_b_cnt : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_653_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_653_REG_PEAKGAIN_B_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_653_REG_ADDR (0x00000A34u)
#define CSL_DFE_TX_TXA_TXA_653_REG_RESETVAL (0x00000000u)

/* TXA_TXA_654 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 22;
    Uint32 maskb : 5;
    Uint32 maska : 5;
#else 
    Uint32 maska : 5;
    Uint32 maskb : 5;
    Uint32 spare : 22;
#endif 
} CSL_DFE_TX_TXA_TXA_654_REG;

/* 0 mask 1 enables {a5,a4,a3,a2,a1} */
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKA_MASK (0x0000001Fu)
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKA_RESETVAL (0x00000000u)

/* 0 mask 1 enables {a5,a4,a3,a2,a1} */
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKB_MASK (0x000003E0u)
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKB_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXA_TXA_654_REG_MASKB_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_654_REG_SPARE_MASK (0xFFFFFC00u)
#define CSL_DFE_TX_TXA_TXA_654_REG_SPARE_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXA_TXA_654_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_654_REG_ADDR (0x00000A38u)
#define CSL_DFE_TX_TXA_TXA_654_REG_RESETVAL (0x00000000u)

/* TXA_TXA_655 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 18;
    Uint32 lower_cfr_gain_b : 1;
    Uint32 shutdown_b : 1;
    Uint32 interrupt6b : 1;
    Uint32 interrupt3b : 1;
    Uint32 interrupt2b : 1;
    Uint32 interrupt1b : 1;
    Uint32 stop_dpd_b : 1;
    Uint32 lower_cfr_gain_a : 1;
    Uint32 shutdown_a : 1;
    Uint32 interrupt6a : 1;
    Uint32 interrupt3a : 1;
    Uint32 interrupt2a : 1;
    Uint32 interrupt1a : 1;
    Uint32 stop_dpd_a : 1;
#else 
    Uint32 stop_dpd_a : 1;
    Uint32 interrupt1a : 1;
    Uint32 interrupt2a : 1;
    Uint32 interrupt3a : 1;
    Uint32 interrupt6a : 1;
    Uint32 shutdown_a : 1;
    Uint32 lower_cfr_gain_a : 1;
    Uint32 stop_dpd_b : 1;
    Uint32 interrupt1b : 1;
    Uint32 interrupt2b : 1;
    Uint32 interrupt3b : 1;
    Uint32 interrupt6b : 1;
    Uint32 shutdown_b : 1;
    Uint32 lower_cfr_gain_b : 1;
    Uint32 spare : 18;
#endif 
} CSL_DFE_TX_TXA_TXA_655_REG;

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_A_MASK (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1A_MASK (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1A_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2A_MASK (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2A_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3A_MASK (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3A_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6A_MASK (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6A_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_A_MASK (0x00000020u)
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_A_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_A_MASK (0x00000040u)
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_A_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_B_MASK (0x00000080u)
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_B_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXA_TXA_655_REG_STOP_DPD_B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1B_MASK (0x00000100u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1B_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT1B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2B_MASK (0x00000200u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2B_SHIFT (0x00000009u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT2B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3B_MASK (0x00000400u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3B_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT3B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6B_MASK (0x00000800u)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6B_SHIFT (0x0000000Bu)
#define CSL_DFE_TX_TXA_TXA_655_REG_INTERRUPT6B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_B_MASK (0x00001000u)
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_B_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXA_TXA_655_REG_SHUTDOWN_B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_B_MASK (0x00002000u)
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_B_SHIFT (0x0000000Du)
#define CSL_DFE_TX_TXA_TXA_655_REG_LOWER_CFR_GAIN_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXA_TXA_655_REG_SPARE_MASK (0xFFFFC000u)
#define CSL_DFE_TX_TXA_TXA_655_REG_SPARE_SHIFT (0x0000000Eu)
#define CSL_DFE_TX_TXA_TXA_655_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_655_REG_ADDR (0x00000A3Cu)
#define CSL_DFE_TX_TXA_TXA_655_REG_RESETVAL (0x00000000u)

/* TXA_TXA_656 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 max_magb : 16;
    Uint32 max_maga : 16;
#else 
    Uint32 max_maga : 16;
    Uint32 max_magb : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_656_REG;

/* maximum magnitude of d3 a channel since last read of address 0xA40. Read this address to get max mag of a and also clear it. */
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGA_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGA_RESETVAL (0x00000000u)

/* maximum magnitude of d3 b channel since last read of address 0xA44. Read this address to get max mag of b WITHOUT clearing it. */
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGB_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGB_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_656_REG_MAX_MAGB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_656_REG_ADDR (0x00000A40u)
#define CSL_DFE_TX_TXA_TXA_656_REG_RESETVAL (0x00000000u)

/* TXA_TXA_657 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 max_magb : 16;
    Uint32 max_maga : 16;
#else 
    Uint32 max_maga : 16;
    Uint32 max_magb : 16;
#endif 
} CSL_DFE_TX_TXA_TXA_657_REG;

/* maximum magnitude of d3 a channel since last read of address 0xA40. Read this address to get max mag of a WITHOUT clearing it. */
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGA_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGA_RESETVAL (0x00000000u)

/* maximum magnitude of d3 b channel since last read of address 0xA44. Read this address to get max mag of b and also clear it. */
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGB_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGB_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXA_TXA_657_REG_MAX_MAGB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_657_REG_ADDR (0x00000A44u)
#define CSL_DFE_TX_TXA_TXA_657_REG_RESETVAL (0x00000000u)

/* TXB_TXB_672 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 factory_test_force_a_output_0 : 1;
    Uint32 two_ant_mode : 1;
    Uint32 tha6_sel : 1;
    Uint32 tha2_sel : 1;
    Uint32 tha1_sel : 1;
    Uint32 mu_1_a : 5;
    Uint32 mu_0_a : 5;
    Uint32 threshold_a : 17;
#else 
    Uint32 threshold_a : 17;
    Uint32 mu_0_a : 5;
    Uint32 mu_1_a : 5;
    Uint32 tha1_sel : 1;
    Uint32 tha2_sel : 1;
    Uint32 tha6_sel : 1;
    Uint32 two_ant_mode : 1;
    Uint32 factory_test_force_a_output_0 : 1;
#endif 
} CSL_DFE_TX_TXB_TXB_672_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_672_REG_THRESHOLD_A_MASK (0x0001FFFFu)
#define CSL_DFE_TX_TXB_TXB_672_REG_THRESHOLD_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_THRESHOLD_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_0_A_MASK (0x003E0000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_0_A_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_0_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_1_A_MASK (0x07C00000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_1_A_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXB_TXB_672_REG_MU_1_A_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a1 */
#define CSL_DFE_TX_TXB_TXB_672_REG_THA1_SEL_MASK (0x08000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA1_SEL_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA1_SEL_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a2 */
#define CSL_DFE_TX_TXB_TXB_672_REG_THA2_SEL_MASK (0x10000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA2_SEL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA2_SEL_RESETVAL (0x00000000u)

/* 0 sel d50; 1 sel d51; for a6 */
#define CSL_DFE_TX_TXB_TXB_672_REG_THA6_SEL_MASK (0x20000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA6_SEL_SHIFT (0x0000001Du)
#define CSL_DFE_TX_TXB_TXB_672_REG_THA6_SEL_RESETVAL (0x00000000u)

/* 1 if in 2 antenna mode */
#define CSL_DFE_TX_TXB_TXB_672_REG_TWO_ANT_MODE_MASK (0x40000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_TWO_ANT_MODE_SHIFT (0x0000001Eu)
#define CSL_DFE_TX_TXB_TXB_672_REG_TWO_ANT_MODE_RESETVAL (0x00000000u)

/* Factory test bit keep programmed to 0 when 1 forces tx ouputs to 0.  */
#define CSL_DFE_TX_TXB_TXB_672_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_MASK (0x80000000u)
#define CSL_DFE_TX_TXB_TXB_672_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_SHIFT (0x0000001Fu)
#define CSL_DFE_TX_TXB_TXB_672_REG_FACTORY_TEST_FORCE_A_OUTPUT_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_672_REG_ADDR (0x00000A80u)
#define CSL_DFE_TX_TXB_TXB_672_REG_RESETVAL (0x00000000u)

/* TXB_TXB_673 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 factory_test_force_b_output_0 : 1;
    Uint32 spare : 1;
    Uint32 thb6_sel : 1;
    Uint32 thb2_sel : 1;
    Uint32 thb1_sel : 1;
    Uint32 mu_1_b : 5;
    Uint32 mu_0_b : 5;
    Uint32 threshold_b : 17;
#else 
    Uint32 threshold_b : 17;
    Uint32 mu_0_b : 5;
    Uint32 mu_1_b : 5;
    Uint32 thb1_sel : 1;
    Uint32 thb2_sel : 1;
    Uint32 thb6_sel : 1;
    Uint32 spare : 1;
    Uint32 factory_test_force_b_output_0 : 1;
#endif 
} CSL_DFE_TX_TXB_TXB_673_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_THRESHOLD_B_MASK (0x0001FFFFu)
#define CSL_DFE_TX_TXB_TXB_673_REG_THRESHOLD_B_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_THRESHOLD_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_0_B_MASK (0x003E0000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_0_B_SHIFT (0x00000011u)
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_0_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_1_B_MASK (0x07C00000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_1_B_SHIFT (0x00000016u)
#define CSL_DFE_TX_TXB_TXB_673_REG_MU_1_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_THB1_SEL_MASK (0x08000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB1_SEL_SHIFT (0x0000001Bu)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB1_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_THB2_SEL_MASK (0x10000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB2_SEL_SHIFT (0x0000001Cu)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB2_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_THB6_SEL_MASK (0x20000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB6_SEL_SHIFT (0x0000001Du)
#define CSL_DFE_TX_TXB_TXB_673_REG_THB6_SEL_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_673_REG_SPARE_MASK (0x40000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_SPARE_SHIFT (0x0000001Eu)
#define CSL_DFE_TX_TXB_TXB_673_REG_SPARE_RESETVAL (0x00000000u)

/* Factory test bit keep programmed to 0 when 1 forces tx ouputs to 0.  */
#define CSL_DFE_TX_TXB_TXB_673_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_MASK (0x80000000u)
#define CSL_DFE_TX_TXB_TXB_673_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_SHIFT (0x0000001Fu)
#define CSL_DFE_TX_TXB_TXB_673_REG_FACTORY_TEST_FORCE_B_OUTPUT_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_673_REG_ADDR (0x00000A84u)
#define CSL_DFE_TX_TXB_TXB_673_REG_RESETVAL (0x00000000u)

/* TXB_TXB_674 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cca_cnt : 16;
    Uint32 cca_thr : 16;
#else 
    Uint32 cca_thr : 16;
    Uint32 cca_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_674_REG;

/* see pa.pptx for definitions of thresholds */
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_674_REG_CCA_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_674_REG_ADDR (0x00000A88u)
#define CSL_DFE_TX_TXB_TXB_674_REG_RESETVAL (0x00000000u)

/* TXB_TXB_675 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 ccb_cnt : 16;
    Uint32 ccb_thr : 16;
#else 
    Uint32 ccb_thr : 16;
    Uint32 ccb_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_675_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_675_REG_CCB_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_675_REG_ADDR (0x00000A8Cu)
#define CSL_DFE_TX_TXB_TXB_675_REG_RESETVAL (0x00000000u)

/* TXB_TXB_676 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_0_b : 16;
    Uint32 th_0_a : 16;
#else 
    Uint32 th_0_a : 16;
    Uint32 th_0_b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_676_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_676_REG_TH_0_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_676_REG_ADDR (0x00000A90u)
#define CSL_DFE_TX_TXB_TXB_676_REG_RESETVAL (0x00000000u)

/* TXB_TXB_677 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_1_b : 16;
    Uint32 th_1_a : 16;
#else 
    Uint32 th_1_a : 16;
    Uint32 th_1_b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_677_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_677_REG_TH_1_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_677_REG_ADDR (0x00000A94u)
#define CSL_DFE_TX_TXB_TXB_677_REG_RESETVAL (0x00000000u)

/* TXB_TXB_678 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_2_b : 16;
    Uint32 th_2_a : 16;
#else 
    Uint32 th_2_a : 16;
    Uint32 th_2_b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_678_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_678_REG_TH_2_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_678_REG_ADDR (0x00000A98u)
#define CSL_DFE_TX_TXB_TXB_678_REG_RESETVAL (0x00000000u)

/* TXB_TXB_679 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 th_4_b : 16;
    Uint32 th_4_a : 16;
#else 
    Uint32 th_4_a : 16;
    Uint32 th_4_b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_679_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_A_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_679_REG_TH_4_B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_679_REG_ADDR (0x00000A9Cu)
#define CSL_DFE_TX_TXB_TXB_679_REG_RESETVAL (0x00000000u)

/* TXB_TXB_680 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 d50b : 16;
    Uint32 d50a : 16;
#else 
    Uint32 d50a : 16;
    Uint32 d50b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_680_REG;

/* ms 16 bits */
#define CSL_DFE_TX_TXB_TXB_680_REG_D50A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_680_REG_D50A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_680_REG_D50A_RESETVAL (0x00000000u)

/* ms 16 bits */
#define CSL_DFE_TX_TXB_TXB_680_REG_D50B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_680_REG_D50B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_680_REG_D50B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_680_REG_ADDR (0x00000AA0u)
#define CSL_DFE_TX_TXB_TXB_680_REG_RESETVAL (0x00000000u)

/* TXB_TXB_681 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 d51b : 16;
    Uint32 d51a : 16;
#else 
    Uint32 d51a : 16;
    Uint32 d51b : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_681_REG;

/* ms 16 bits */
#define CSL_DFE_TX_TXB_TXB_681_REG_D51A_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_681_REG_D51A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_681_REG_D51A_RESETVAL (0x00000000u)

/* ms 16 bits */
#define CSL_DFE_TX_TXB_TXB_681_REG_D51B_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_681_REG_D51B_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_681_REG_D51B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_681_REG_ADDR (0x00000AA4u)
#define CSL_DFE_TX_TXB_TXB_681_REG_RESETVAL (0x00000000u)

/* TXB_TXB_682 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peak_a_cnt : 16;
    Uint32 peak_a_thr : 16;
#else 
    Uint32 peak_a_thr : 16;
    Uint32 peak_a_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_682_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_682_REG_PEAK_A_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_682_REG_ADDR (0x00000AA8u)
#define CSL_DFE_TX_TXB_TXB_682_REG_RESETVAL (0x00000000u)

/* TXB_TXB_683 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peak_b_cnt : 16;
    Uint32 peak_b_thr : 16;
#else 
    Uint32 peak_b_thr : 16;
    Uint32 peak_b_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_683_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_683_REG_PEAK_B_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_683_REG_ADDR (0x00000AACu)
#define CSL_DFE_TX_TXB_TXB_683_REG_RESETVAL (0x00000000u)

/* TXB_TXB_684 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peakgain_a_cnt : 16;
    Uint32 peakgain_a_thr : 16;
#else 
    Uint32 peakgain_a_thr : 16;
    Uint32 peakgain_a_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_684_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_684_REG_PEAKGAIN_A_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_684_REG_ADDR (0x00000AB0u)
#define CSL_DFE_TX_TXB_TXB_684_REG_RESETVAL (0x00000000u)

/* TXB_TXB_685 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 peakgain_b_cnt : 16;
    Uint32 peakgain_b_thr : 16;
#else 
    Uint32 peakgain_b_thr : 16;
    Uint32 peakgain_b_cnt : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_685_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_THR_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_THR_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_THR_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_CNT_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_CNT_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_685_REG_PEAKGAIN_B_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_685_REG_ADDR (0x00000AB4u)
#define CSL_DFE_TX_TXB_TXB_685_REG_RESETVAL (0x00000000u)

/* TXB_TXB_686 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 22;
    Uint32 maskb : 5;
    Uint32 maska : 5;
#else 
    Uint32 maska : 5;
    Uint32 maskb : 5;
    Uint32 spare : 22;
#endif 
} CSL_DFE_TX_TXB_TXB_686_REG;

/* 0 mask 1 enables {a5,a4,a3,a2,a1} */
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKA_MASK (0x0000001Fu)
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKA_RESETVAL (0x00000000u)

/* 0 mask 1 enables {a5,a4,a3,a2,a1} */
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKB_MASK (0x000003E0u)
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKB_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXB_TXB_686_REG_MASKB_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_686_REG_SPARE_MASK (0xFFFFFC00u)
#define CSL_DFE_TX_TXB_TXB_686_REG_SPARE_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXB_TXB_686_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_686_REG_ADDR (0x00000AB8u)
#define CSL_DFE_TX_TXB_TXB_686_REG_RESETVAL (0x00000000u)

/* TXB_TXB_687 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 spare : 18;
    Uint32 lower_cfr_gain_b : 1;
    Uint32 shutdown_b : 1;
    Uint32 interrupt6b : 1;
    Uint32 interrupt3b : 1;
    Uint32 interrupt2b : 1;
    Uint32 interrupt1b : 1;
    Uint32 stop_dpd_b : 1;
    Uint32 lower_cfr_gain_a : 1;
    Uint32 shutdown_a : 1;
    Uint32 interrupt6a : 1;
    Uint32 interrupt3a : 1;
    Uint32 interrupt2a : 1;
    Uint32 interrupt1a : 1;
    Uint32 stop_dpd_a : 1;
#else 
    Uint32 stop_dpd_a : 1;
    Uint32 interrupt1a : 1;
    Uint32 interrupt2a : 1;
    Uint32 interrupt3a : 1;
    Uint32 interrupt6a : 1;
    Uint32 shutdown_a : 1;
    Uint32 lower_cfr_gain_a : 1;
    Uint32 stop_dpd_b : 1;
    Uint32 interrupt1b : 1;
    Uint32 interrupt2b : 1;
    Uint32 interrupt3b : 1;
    Uint32 interrupt6b : 1;
    Uint32 shutdown_b : 1;
    Uint32 lower_cfr_gain_b : 1;
    Uint32 spare : 18;
#endif 
} CSL_DFE_TX_TXB_TXB_687_REG;

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_A_MASK (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1A_MASK (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1A_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2A_MASK (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2A_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3A_MASK (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3A_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6A_MASK (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6A_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_A_MASK (0x00000020u)
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_A_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_A_MASK (0x00000040u)
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_A_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_A_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_B_MASK (0x00000080u)
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_B_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXB_TXB_687_REG_STOP_DPD_B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1B_MASK (0x00000100u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1B_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT1B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2B_MASK (0x00000200u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2B_SHIFT (0x00000009u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT2B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3B_MASK (0x00000400u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3B_SHIFT (0x0000000Au)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT3B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6B_MASK (0x00000800u)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6B_SHIFT (0x0000000Bu)
#define CSL_DFE_TX_TXB_TXB_687_REG_INTERRUPT6B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_B_MASK (0x00001000u)
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_B_SHIFT (0x0000000Cu)
#define CSL_DFE_TX_TXB_TXB_687_REG_SHUTDOWN_B_RESETVAL (0x00000000u)

/* sticky bit; when set wrting a 1 to this bit will reset; writing 0 is nop */
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_B_MASK (0x00002000u)
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_B_SHIFT (0x0000000Du)
#define CSL_DFE_TX_TXB_TXB_687_REG_LOWER_CFR_GAIN_B_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_TX_TXB_TXB_687_REG_SPARE_MASK (0xFFFFC000u)
#define CSL_DFE_TX_TXB_TXB_687_REG_SPARE_SHIFT (0x0000000Eu)
#define CSL_DFE_TX_TXB_TXB_687_REG_SPARE_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_687_REG_ADDR (0x00000ABCu)
#define CSL_DFE_TX_TXB_TXB_687_REG_RESETVAL (0x00000000u)

/* TXB_TXB_688 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 max_magb : 16;
    Uint32 max_maga : 16;
#else 
    Uint32 max_maga : 16;
    Uint32 max_magb : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_688_REG;

/* maximum magnitude of d3 a channel since last read of address 0xA40. Read this address to get max mag of a and also clear it. */
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGA_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGA_RESETVAL (0x00000000u)

/* maximum magnitude of d3 b channel since last read of address 0xA44. Read this address to get max mag of b WITHOUT clearing it. */
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGB_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGB_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_688_REG_MAX_MAGB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_688_REG_ADDR (0x00000AC0u)
#define CSL_DFE_TX_TXB_TXB_688_REG_RESETVAL (0x00000000u)

/* TXB_TXB_689 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 max_magb : 16;
    Uint32 max_maga : 16;
#else 
    Uint32 max_maga : 16;
    Uint32 max_magb : 16;
#endif 
} CSL_DFE_TX_TXB_TXB_689_REG;

/* maximum magnitude of d3 a channel since last read of address 0xA40. Read this address to get max mag of a WITHOUT clearing it. */
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGA_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGA_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGA_RESETVAL (0x00000000u)

/* maximum magnitude of d3 b channel since last read of address 0xA44. Read this address to get max mag of b and also clear it. */
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGB_MASK (0xFFFF0000u)
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGB_SHIFT (0x00000010u)
#define CSL_DFE_TX_TXB_TXB_689_REG_MAX_MAGB_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_689_REG_ADDR (0x00000AC4u)
#define CSL_DFE_TX_TXB_TXB_689_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_704 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_TXRX_TXRX_704_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_TX_TXRX_TXRX_704_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXRX_TXRX_704_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_704_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_704_REG_ADDR (0x00000B00u)
#define CSL_DFE_TX_TXRX_TXRX_704_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_705 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_TXRX_TXRX_705_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_TX_TXRX_TXRX_705_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXRX_TXRX_705_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_705_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_705_REG_ADDR (0x00000B04u)
#define CSL_DFE_TX_TXRX_TXRX_705_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_706 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_period : 24;
#else 
    Uint32 tdd_period : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_706_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_TX_TXRX_TXRX_706_REG_TDD_PERIOD_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_706_REG_TDD_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_706_REG_TDD_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_706_REG_ADDR (0x00000B08u)
#define CSL_DFE_TX_TXRX_TXRX_706_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_707 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_0 : 24;
#else 
    Uint32 tdd_on_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_707_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_TX_TXRX_TXRX_707_REG_TDD_ON_0_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_707_REG_TDD_ON_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_707_REG_TDD_ON_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_707_REG_ADDR (0x00000B0Cu)
#define CSL_DFE_TX_TXRX_TXRX_707_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_708 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_0 : 24;
#else 
    Uint32 tdd_off_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_708_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_TX_TXRX_TXRX_708_REG_TDD_OFF_0_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_708_REG_TDD_OFF_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_708_REG_TDD_OFF_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_708_REG_ADDR (0x00000B10u)
#define CSL_DFE_TX_TXRX_TXRX_708_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_709 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_1 : 24;
#else 
    Uint32 tdd_on_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_709_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_TX_TXRX_TXRX_709_REG_TDD_ON_1_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_709_REG_TDD_ON_1_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_709_REG_TDD_ON_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_709_REG_ADDR (0x00000B14u)
#define CSL_DFE_TX_TXRX_TXRX_709_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_710 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_1 : 24;
#else 
    Uint32 tdd_off_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_710_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_TX_TXRX_TXRX_710_REG_TDD_OFF_1_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_710_REG_TDD_OFF_1_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_710_REG_TDD_OFF_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_710_REG_ADDR (0x00000B18u)
#define CSL_DFE_TX_TXRX_TXRX_710_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_711 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step : 16;
#else 
    Uint32 time_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_TXRX_TXRX_711_REG;

/* Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^15)/time_step clocks. Put another way: multiplies the clock rate by ((2^15)-time_step)/(2^15). */
#define CSL_DFE_TX_TXRX_TXRX_711_REG_TIME_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXRX_TXRX_711_REG_TIME_STEP_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_711_REG_TIME_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_711_REG_ADDR (0x00000B1Cu)
#define CSL_DFE_TX_TXRX_TXRX_711_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_712 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int : 16;
#else 
    Uint32 reset_int : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_TX_TXRX_TXRX_712_REG;

/* Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_TX_TXRX_TXRX_712_REG_RESET_INT_MASK (0x0000FFFFu)
#define CSL_DFE_TX_TXRX_TXRX_712_REG_RESET_INT_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_712_REG_RESET_INT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_712_REG_ADDR (0x00000B20u)
#define CSL_DFE_TX_TXRX_TXRX_712_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_713 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_period : 24;
#else 
    Uint32 tdd_period : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_713_REG;

/* TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_TX_TXRX_TXRX_713_REG_TDD_PERIOD_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_713_REG_TDD_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_713_REG_TDD_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_713_REG_ADDR (0x00000B24u)
#define CSL_DFE_TX_TXRX_TXRX_713_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_714 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_0 : 24;
#else 
    Uint32 tdd_on_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_714_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_TX_TXRX_TXRX_714_REG_TDD_ON_0_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_714_REG_TDD_ON_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_714_REG_TDD_ON_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_714_REG_ADDR (0x00000B28u)
#define CSL_DFE_TX_TXRX_TXRX_714_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_715 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_0 : 24;
#else 
    Uint32 tdd_off_0 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_715_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_TX_TXRX_TXRX_715_REG_TDD_OFF_0_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_715_REG_TDD_OFF_0_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_715_REG_TDD_OFF_0_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_715_REG_ADDR (0x00000B2Cu)
#define CSL_DFE_TX_TXRX_TXRX_715_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_716 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_on_1 : 24;
#else 
    Uint32 tdd_on_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_716_REG;

/* TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_TX_TXRX_TXRX_716_REG_TDD_ON_1_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_716_REG_TDD_ON_1_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_716_REG_TDD_ON_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_716_REG_ADDR (0x00000B30u)
#define CSL_DFE_TX_TXRX_TXRX_716_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_717 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 tdd_off_1 : 24;
#else 
    Uint32 tdd_off_1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_TX_TXRX_TXRX_717_REG;

/* TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_TX_TXRX_TXRX_717_REG_TDD_OFF_1_MASK (0x00FFFFFFu)
#define CSL_DFE_TX_TXRX_TXRX_717_REG_TDD_OFF_1_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_717_REG_TDD_OFF_1_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_717_REG_ADDR (0x00000B34u)
#define CSL_DFE_TX_TXRX_TXRX_717_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_718 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 tx_cken_dly : 3;
    Uint32 dpd_bypass : 1;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 dpd_bypass : 1;
    Uint32 tx_cken_dly : 3;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_TX_TXRX_TXRX_718_REG;

/* inits sync select */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* released on inits_ssel */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* released on inits_ssel */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_INIT_STATE_RESETVAL (0x00000001u)

/* released on inits_ssel */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* control bit which indiactes if dpd has been bypassed */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_DPD_BYPASS_MASK (0x00000080u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_DPD_BYPASS_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_DPD_BYPASS_RESETVAL (0x00000000u)

/* register which indicates delay value for clock gate delayer */
#define CSL_DFE_TX_TXRX_TXRX_718_REG_TX_CKEN_DLY_MASK (0x00000700u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_TX_CKEN_DLY_SHIFT (0x00000008u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_TX_CKEN_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_718_REG_ADDR (0x00000B38u)
#define CSL_DFE_TX_TXRX_TXRX_718_REG_RESETVAL (0x00000070u)

/* TXRX_TXRX_719 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 txb_interrupt_6b_intr_mask : 1;
    Uint32 txb_interrupt_6a_intr_mask : 1;
    Uint32 txb_interrupt_5b_intr_mask : 1;
    Uint32 txb_interrupt_5a_intr_mask : 1;
    Uint32 txa_interrupt_6b_intr_mask : 1;
    Uint32 txa_interrupt_6a_intr_mask : 1;
    Uint32 txa_interrupt_5b_intr_mask : 1;
    Uint32 txa_interrupt_5a_intr_mask : 1;
#else 
    Uint32 txa_interrupt_5a_intr_mask : 1;
    Uint32 txa_interrupt_5b_intr_mask : 1;
    Uint32 txa_interrupt_6a_intr_mask : 1;
    Uint32 txa_interrupt_6b_intr_mask : 1;
    Uint32 txb_interrupt_5a_intr_mask : 1;
    Uint32 txb_interrupt_5b_intr_mask : 1;
    Uint32 txb_interrupt_6a_intr_mask : 1;
    Uint32 txb_interrupt_6b_intr_mask : 1;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_TX_TXRX_TXRX_719_REG;

/* Interrupt to indicate Txa PA protect power is approaching saturation. interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5A_INTR_MASK_MASK (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5A_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5A_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txa PA protect power is approaching saturation.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5B_INTR_MASK_MASK (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5B_INTR_MASK_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_5B_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txa PA protect peak is approaching saturation.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6A_INTR_MASK_MASK (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6A_INTR_MASK_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6A_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txa PA protect peak is approaching saturationinterrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6B_INTR_MASK_MASK (0x00000008u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6B_INTR_MASK_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXA_INTERRUPT_6B_INTR_MASK_RESETVAL (0x00000000u)

/* .interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5A_INTR_MASK_MASK (0x00000010u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5A_INTR_MASK_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5A_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txb PA protect power is approaching saturation.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5B_INTR_MASK_MASK (0x00000020u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5B_INTR_MASK_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_5B_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txb PA protect peak is approaching saturation.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6A_INTR_MASK_MASK (0x00000040u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6A_INTR_MASK_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6A_INTR_MASK_RESETVAL (0x00000000u)

/* Interrupt to indicate Txb PA protect peak is approaching saturation.interrupt mask bits - 1 to enable interrupt bit, 0 to disable interrupt bit */
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6B_INTR_MASK_MASK (0x00000080u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6B_INTR_MASK_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_TXB_INTERRUPT_6B_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_719_REG_ADDR (0x00000B3Cu)
#define CSL_DFE_TX_TXRX_TXRX_719_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_720 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 txb_interrupt_6b : 1;
    Uint32 txb_interrupt_6a : 1;
    Uint32 txb_interrupt_5b : 1;
    Uint32 txb_interrupt_5a : 1;
    Uint32 txa_interrupt_6b : 1;
    Uint32 txa_interrupt_6a : 1;
    Uint32 txa_interrupt_5b : 1;
    Uint32 txa_interrupt_5a : 1;
#else 
    Uint32 txa_interrupt_5a : 1;
    Uint32 txa_interrupt_5b : 1;
    Uint32 txa_interrupt_6a : 1;
    Uint32 txa_interrupt_6b : 1;
    Uint32 txb_interrupt_5a : 1;
    Uint32 txb_interrupt_5b : 1;
    Uint32 txb_interrupt_6a : 1;
    Uint32 txb_interrupt_6b : 1;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_TX_TXRX_TXRX_720_REG;

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5A_MASK (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5A_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5A_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5B_MASK (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5B_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_5B_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6A_MASK (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6A_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6A_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6B_MASK (0x00000008u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6B_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXA_INTERRUPT_6B_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5A_MASK (0x00000010u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5A_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5A_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5B_MASK (0x00000020u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5B_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_5B_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6A_MASK (0x00000040u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6A_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6A_RESETVAL (0x00000000u)

/* captured interrupt bits - can only write 0 to clear */
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6B_MASK (0x00000080u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6B_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_TXB_INTERRUPT_6B_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_720_REG_ADDR (0x00000B40u)
#define CSL_DFE_TX_TXRX_TXRX_720_REG_RESETVAL (0x00000000u)

/* TXRX_TXRX_721 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 txb_interrupt_6b_force_intr_bit : 1;
    Uint32 txb_interrupt_6a_force_intr_bit : 1;
    Uint32 txb_interrupt_5b_force_intr_bit : 1;
    Uint32 txb_interrupt_5a_force_intr_bit : 1;
    Uint32 txa_interrupt_6b_force_intr_bit : 1;
    Uint32 txa_interrupt_6a_force_intr_bit : 1;
    Uint32 txa_interrupt_5b_force_intr_bit : 1;
    Uint32 txa_interrupt_5a_force_intr_bit : 1;
#else 
    Uint32 txa_interrupt_5a_force_intr_bit : 1;
    Uint32 txa_interrupt_5b_force_intr_bit : 1;
    Uint32 txa_interrupt_6a_force_intr_bit : 1;
    Uint32 txa_interrupt_6b_force_intr_bit : 1;
    Uint32 txb_interrupt_5a_force_intr_bit : 1;
    Uint32 txb_interrupt_5b_force_intr_bit : 1;
    Uint32 txb_interrupt_6a_force_intr_bit : 1;
    Uint32 txb_interrupt_6b_force_intr_bit : 1;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_TX_TXRX_TXRX_721_REG;

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5A_FORCE_INTR_BIT_MASK (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5A_FORCE_INTR_BIT_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5A_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5B_FORCE_INTR_BIT_MASK (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5B_FORCE_INTR_BIT_SHIFT (0x00000001u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_5B_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6A_FORCE_INTR_BIT_MASK (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6A_FORCE_INTR_BIT_SHIFT (0x00000002u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6A_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6B_FORCE_INTR_BIT_MASK (0x00000008u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6B_FORCE_INTR_BIT_SHIFT (0x00000003u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXA_INTERRUPT_6B_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5A_FORCE_INTR_BIT_MASK (0x00000010u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5A_FORCE_INTR_BIT_SHIFT (0x00000004u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5A_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5B_FORCE_INTR_BIT_MASK (0x00000020u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5B_FORCE_INTR_BIT_SHIFT (0x00000005u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_5B_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6A_FORCE_INTR_BIT_MASK (0x00000040u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6A_FORCE_INTR_BIT_SHIFT (0x00000006u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6A_FORCE_INTR_BIT_RESETVAL (0x00000000u)

/* forced interrupt bits */
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6B_FORCE_INTR_BIT_MASK (0x00000080u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6B_FORCE_INTR_BIT_SHIFT (0x00000007u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_TXB_INTERRUPT_6B_FORCE_INTR_BIT_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXRX_TXRX_721_REG_ADDR (0x00000B44u)
#define CSL_DFE_TX_TXRX_TXRX_721_REG_RESETVAL (0x00000000u)

/* TXA_TXA_65536 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 paa_lut_p : 26;
#else 
    Uint32 paa_lut_p : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXA_TXA_65536_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_65536_REG_PAA_LUT_P_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXA_TXA_65536_REG_PAA_LUT_P_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_65536_REG_PAA_LUT_P_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_65536_REG_ADDR (0x00040000u)
#define CSL_DFE_TX_TXA_TXA_65536_REG_RESETVAL (0x00000000u)

/* TXA_TXA_65664 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 paa_lut_q : 26;
#else 
    Uint32 paa_lut_q : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXA_TXA_65664_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_65664_REG_PAA_LUT_Q_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXA_TXA_65664_REG_PAA_LUT_Q_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_65664_REG_PAA_LUT_Q_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_65664_REG_ADDR (0x00040200u)
#define CSL_DFE_TX_TXA_TXA_65664_REG_RESETVAL (0x00000000u)

/* TXA_TXA_65792 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 paa_lut_t : 26;
#else 
    Uint32 paa_lut_t : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXA_TXA_65792_REG;

/*  */
#define CSL_DFE_TX_TXA_TXA_65792_REG_PAA_LUT_T_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXA_TXA_65792_REG_PAA_LUT_T_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXA_TXA_65792_REG_PAA_LUT_T_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXA_TXA_65792_REG_ADDR (0x00040400u)
#define CSL_DFE_TX_TXA_TXA_65792_REG_RESETVAL (0x00000000u)

/* TXB_TXB_65920 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 pab_lut_p : 26;
#else 
    Uint32 pab_lut_p : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXB_TXB_65920_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_65920_REG_PAB_LUT_P_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXB_TXB_65920_REG_PAB_LUT_P_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_65920_REG_PAB_LUT_P_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_65920_REG_ADDR (0x00040600u)
#define CSL_DFE_TX_TXB_TXB_65920_REG_RESETVAL (0x00000000u)

/* TXB_TXB_66048 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 pab_lut_q : 26;
#else 
    Uint32 pab_lut_q : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXB_TXB_66048_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_66048_REG_PAB_LUT_Q_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXB_TXB_66048_REG_PAB_LUT_Q_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_66048_REG_PAB_LUT_Q_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_66048_REG_ADDR (0x00040800u)
#define CSL_DFE_TX_TXB_TXB_66048_REG_RESETVAL (0x00000000u)

/* TXB_TXB_66176 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 pab_lut_t : 26;
#else 
    Uint32 pab_lut_t : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_TX_TXB_TXB_66176_REG;

/*  */
#define CSL_DFE_TX_TXB_TXB_66176_REG_PAB_LUT_T_MASK (0x03FFFFFFu)
#define CSL_DFE_TX_TXB_TXB_66176_REG_PAB_LUT_T_SHIFT (0x00000000u)
#define CSL_DFE_TX_TXB_TXB_66176_REG_PAB_LUT_T_RESETVAL (0x00000000u)

#define CSL_DFE_TX_TXB_TXB_66176_REG_ADDR (0x00040A00u)
#define CSL_DFE_TX_TXB_TXB_66176_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_TX_H__ */
