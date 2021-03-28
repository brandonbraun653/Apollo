/*
 * cslr_dfe_fb.h
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

/* The file is auto generated at 12:21:32 01/11/13 (Rev 1.68)*/

#ifndef CSLR_DFE_FB_H__
#define CSLR_DFE_FB_H__

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
} CSL_DFE_FB_NCO_FREQ_WORD_REGS;

typedef struct
{
    volatile Uint32 real;
    volatile Uint32 imag;
    volatile Uint32 rsvd0[2];
} CSL_DFE_FB_GAIN_GAIN_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[128];
    /* Addr: h(200), d(512) */
    volatile Uint32 inits;
    /* Addr: h(204), d(516) */
    volatile Uint32 nco_bypass;
    /* Addr: h(208), d(520) */
    volatile Uint32 r2c_global;
    /* Addr: h(20C), d(524) */
    volatile Uint32 io_control;
    /* Addr: h(210), d(528) */
    volatile Uint32 nco_dither_enable;
    /* Addr: h(214), d(532) */
    volatile Uint32 df_dec;
    /* Addr: h(218), d(536) */
    volatile Uint32 lut_bypass;
    /* Addr: h(21C), d(540) */
    volatile Uint32 rsvd1[4];
    /* Addr: h(22C), d(556) */
    volatile Uint32 testbus;
    /* Addr: h(230), d(560) */
    volatile Uint32 dc_testbus;
    /* Addr: h(234), d(564) */
    volatile Uint32 rsvd2[3];
    /* Addr: h(240), d(576) */
    volatile CSL_DFE_FB_NCO_FREQ_WORD_REGS nco_freq_word[5];
    /* Addr: h(290), d(656) */
    volatile Uint32 rsvd3[8];
    /* Addr: h(2B0), d(688) */
    volatile CSL_DFE_FB_GAIN_GAIN_REGS gain_gain[5];
    /* Addr: h(300), d(768) */
    volatile Uint32 r2c_ssel;
    /* Addr: h(304), d(772) */
    volatile Uint32 nco_ssel;
    /* Addr: h(308), d(776) */
    volatile Uint32 eqr_ssel;
    /* Addr: h(30C), d(780) */
    volatile Uint32 rsvd4[1];
    /* Addr: h(310), d(784) */
    volatile Uint32 gain_ssel;
    /* Addr: h(314), d(788) */
    volatile Uint32 rsvd5[1];
    /* Addr: h(318), d(792) */
    volatile Uint32 dc_ssel;
    /* Addr: h(31C), d(796) */
    volatile Uint32 rsvd6[1];
    /* Addr: h(320), d(800) */
    volatile Uint32 test_ssel;
    /* Addr: h(324), d(804) */
    volatile Uint32 rsvd7[25];
    /* Addr: h(388), d(904) */
    volatile Uint32 dc_gsg_ssel;
    /* Addr: h(38C), d(908) */
    volatile Uint32 rsvd8[221];
    /* Addr: h(700), d(1792) */
    volatile Uint32 dc_global;
    /* Addr: h(704), d(1796) */
    volatile Uint32 dc_init[2];
    /* Addr: h(70C), d(1804) */
    volatile Uint32 rsvd9[6];
    /* Addr: h(724), d(1828) */
    volatile Uint32 dc_interval_w0;
    /* Addr: h(728), d(1832) */
    volatile Uint32 dc_interval_w1;
    /* Addr: h(72C), d(1836) */
    volatile Uint32 dc_update_delay;
    /* Addr: h(730), d(1840) */
    volatile Uint32 rsvd10[3];
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
    volatile Uint32 rsvd11[1];
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
    volatile Uint32 siggen_q_ramp_incr_w0;
    /* Addr: h(77C), d(1916) */
    volatile Uint32 siggen_q_ramp_incr_w1;
    /* Addr: h(780), d(1920) */
    volatile Uint32 siggen_q_pulse_width;
    /* Addr: h(784), d(1924) */
    volatile Uint32 rsvd12[1];
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
    volatile Uint32 rsvd13[65049];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 eqr_taps_ii0[8];
    /* Addr: h(40020), d(262176) */
    volatile Uint32 eqr_taps_iq0[8];
    /* Addr: h(40040), d(262208) */
    volatile Uint32 eqr_taps_qi0[8];
    /* Addr: h(40060), d(262240) */
    volatile Uint32 eqr_taps_qq0[8];
    /* Addr: h(40080), d(262272) */
    volatile Uint32 eqr_taps_ii1[8];
    /* Addr: h(400A0), d(262304) */
    volatile Uint32 eqr_taps_iq1[8];
    /* Addr: h(400C0), d(262336) */
    volatile Uint32 eqr_taps_qi1[8];
    /* Addr: h(400E0), d(262368) */
    volatile Uint32 eqr_taps_qq1[8];
    /* Addr: h(40100), d(262400) */
    volatile Uint32 eqr_taps_ii2[8];
    /* Addr: h(40120), d(262432) */
    volatile Uint32 eqr_taps_iq2[8];
    /* Addr: h(40140), d(262464) */
    volatile Uint32 eqr_taps_qi2[8];
    /* Addr: h(40160), d(262496) */
    volatile Uint32 eqr_taps_qq2[8];
    /* Addr: h(40180), d(262528) */
    volatile Uint32 eqr_taps_ii3[8];
    /* Addr: h(401A0), d(262560) */
    volatile Uint32 eqr_taps_iq3[8];
    /* Addr: h(401C0), d(262592) */
    volatile Uint32 eqr_taps_qi3[8];
    /* Addr: h(401E0), d(262624) */
    volatile Uint32 eqr_taps_qq3[8];
    /* Addr: h(40200), d(262656) */
    volatile Uint32 eqr_taps_ii4[8];
    /* Addr: h(40220), d(262688) */
    volatile Uint32 eqr_taps_iq4[8];
    /* Addr: h(40240), d(262720) */
    volatile Uint32 eqr_taps_qi4[8];
    /* Addr: h(40260), d(262752) */
    volatile Uint32 eqr_taps_qq4[8];
    /* Addr: h(40280), d(262784) */
    volatile Uint32 rsvd14[352];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 lut_mem[128];
} CSL_DFE_FB_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* INITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
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
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_FB_INITS_REG;

/* Inits sync selection. */
#define CSL_DFE_FB_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* FB block init clock gate control. */
#define CSL_DFE_FB_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_FB_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_FB_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* FB block init state control. */
#define CSL_DFE_FB_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_FB_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_FB_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* FB block clear data control. */
#define CSL_DFE_FB_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_FB_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_FB_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* FB block clock enable delay control. */
#define CSL_DFE_FB_INITS_REG_CKEN_DLY_MASK (0x00000380u)
#define CSL_DFE_FB_INITS_REG_CKEN_DLY_SHIFT (0x00000007u)
#define CSL_DFE_FB_INITS_REG_CKEN_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_FB_INITS_REG_ADDR (0x00000200u)
#define CSL_DFE_FB_INITS_REG_RESETVAL (0x00000070u)

/* NCO_BYPASS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 bypass4 : 1;
    Uint32 bypass3 : 1;
    Uint32 bypass2 : 1;
    Uint32 bypass1 : 1;
    Uint32 bypass0 : 1;
#else 
    Uint32 bypass0 : 1;
    Uint32 bypass1 : 1;
    Uint32 bypass2 : 1;
    Uint32 bypass3 : 1;
    Uint32 bypass4 : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_FB_NCO_BYPASS_REG;

/*  */
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS0_MASK (0x00000001u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS0_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS1_MASK (0x00000002u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS1_SHIFT (0x00000001u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS2_MASK (0x00000004u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS2_SHIFT (0x00000002u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS3_MASK (0x00000008u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS3_SHIFT (0x00000003u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS3_RESETVAL (0x00000000u)

/* NCO/Mixer block bypass control.  */
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS4_MASK (0x00000010u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS4_SHIFT (0x00000004u)
#define CSL_DFE_FB_NCO_BYPASS_REG_BYPASS4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_BYPASS_REG_ADDR (0x00000204u)
#define CSL_DFE_FB_NCO_BYPASS_REG_RESETVAL (0x00000000u)

/* R2C_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 real_in4 : 1;
    Uint32 real_in3 : 1;
    Uint32 real_in2 : 1;
    Uint32 real_in1 : 1;
    Uint32 real_in0 : 1;
    Uint32 rsvd0 : 3;
    Uint32 spec_inv4 : 1;
    Uint32 spec_inv3 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv0 : 1;
#else 
    Uint32 spec_inv0 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv3 : 1;
    Uint32 spec_inv4 : 1;
    Uint32 rsvd0 : 3;
    Uint32 real_in0 : 1;
    Uint32 real_in1 : 1;
    Uint32 real_in2 : 1;
    Uint32 real_in3 : 1;
    Uint32 real_in4 : 1;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_FB_R2C_GLOBAL_REG;

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV0_MASK (0x00000001u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV0_SHIFT (0x00000000u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV1_MASK (0x00000002u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV1_SHIFT (0x00000001u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV2_MASK (0x00000004u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV2_SHIFT (0x00000002u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV3_MASK (0x00000008u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV3_SHIFT (0x00000003u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV3_RESETVAL (0x00000000u)

/* Real-to-Complex block spectral inversion control.  Enables spectral inversion of the Real-to-Complex block inputs as part of the real-to-complex mixing process (i.e. the spectrally inverted signal.) Only applies to real input signals. */
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV4_MASK (0x00000010u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV4_SHIFT (0x00000004u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_SPEC_INV4_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN0_MASK (0x00000100u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN0_SHIFT (0x00000008u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN1_MASK (0x00000200u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN1_SHIFT (0x00000009u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN2_MASK (0x00000400u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN2_SHIFT (0x0000000Au)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN3_MASK (0x00000800u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN3_SHIFT (0x0000000Bu)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN3_RESETVAL (0x00000000u)

/* Real-toComplex block mode control. */
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN4_MASK (0x00001000u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN4_SHIFT (0x0000000Cu)
#define CSL_DFE_FB_R2C_GLOBAL_REG_REAL_IN4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_R2C_GLOBAL_REG_ADDR (0x00000208u)
#define CSL_DFE_FB_R2C_GLOBAL_REG_RESETVAL (0x00000000u)

/* IO_CONTROL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 cb_output_select : 1;
    Uint32 host_config_select : 3;
    Uint32 config_select_mode : 1;
#else 
    Uint32 config_select_mode : 1;
    Uint32 host_config_select : 3;
    Uint32 cb_output_select : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_FB_IO_CONTROL_REG;

/* FB block configuration select mode control. */
#define CSL_DFE_FB_IO_CONTROL_REG_CONFIG_SELECT_MODE_MASK (0x00000001u)
#define CSL_DFE_FB_IO_CONTROL_REG_CONFIG_SELECT_MODE_SHIFT (0x00000000u)
#define CSL_DFE_FB_IO_CONTROL_REG_CONFIG_SELECT_MODE_RESETVAL (0x00000000u)

/* FB block host configuration select control. This allows for selecting the appropriate configuration based what signal (one of four possible Marconi input antennas or an antenna for sniffing mode) is to be processed. Bit 3 is used to indicate whether on not FB is in sniffing mode, bit 2 indicates which Marconi input (i.e. JESDFB input) to select and bit 1 indicates which antenna of a given Marconi input is selected. Therefore the association is made as follows: */
#define CSL_DFE_FB_IO_CONTROL_REG_HOST_CONFIG_SELECT_MASK (0x0000000Eu)
#define CSL_DFE_FB_IO_CONTROL_REG_HOST_CONFIG_SELECT_SHIFT (0x00000001u)
#define CSL_DFE_FB_IO_CONTROL_REG_HOST_CONFIG_SELECT_RESETVAL (0x00000000u)

/* FB block capture buffer i/q parallel output signal select */
#define CSL_DFE_FB_IO_CONTROL_REG_CB_OUTPUT_SELECT_MASK (0x00000010u)
#define CSL_DFE_FB_IO_CONTROL_REG_CB_OUTPUT_SELECT_SHIFT (0x00000004u)
#define CSL_DFE_FB_IO_CONTROL_REG_CB_OUTPUT_SELECT_RESETVAL (0x00000000u)

#define CSL_DFE_FB_IO_CONTROL_REG_ADDR (0x0000020Cu)
#define CSL_DFE_FB_IO_CONTROL_REG_RESETVAL (0x00000000u)

/* NCO_DITHER_ENABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 dither_enable4 : 1;
    Uint32 dither_enable3 : 1;
    Uint32 dither_enable2 : 1;
    Uint32 dither_enable1 : 1;
    Uint32 dither_enable0 : 1;
#else 
    Uint32 dither_enable0 : 1;
    Uint32 dither_enable1 : 1;
    Uint32 dither_enable2 : 1;
    Uint32 dither_enable3 : 1;
    Uint32 dither_enable4 : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_FB_NCO_DITHER_ENABLE_REG;

/*  */
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_MASK (0x00000001u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_MASK (0x00000002u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_SHIFT (0x00000001u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_MASK (0x00000004u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_SHIFT (0x00000002u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_MASK (0x00000008u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_SHIFT (0x00000003u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_RESETVAL (0x00000000u)

/* NCO/Mixer block dither enable. */
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE4_MASK (0x00000010u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE4_SHIFT (0x00000004u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_DITHER_ENABLE4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_ADDR (0x00000210u)
#define CSL_DFE_FB_NCO_DITHER_ENABLE_REG_RESETVAL (0x00000000u)

/* DF_DEC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 dec_rate : 2;
#else 
    Uint32 dec_rate : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_FB_DF_DEC_REG;

/* Decimation filter decimation rate */
#define CSL_DFE_FB_DF_DEC_REG_DEC_RATE_MASK (0x00000003u)
#define CSL_DFE_FB_DF_DEC_REG_DEC_RATE_SHIFT (0x00000000u)
#define CSL_DFE_FB_DF_DEC_REG_DEC_RATE_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DF_DEC_REG_ADDR (0x00000214u)
#define CSL_DFE_FB_DF_DEC_REG_RESETVAL (0x00000000u)

/* LUT_BYPASS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 bypass4 : 1;
    Uint32 bypass3 : 1;
    Uint32 bypass2 : 1;
    Uint32 bypass1 : 1;
    Uint32 bypass0 : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 bypass0 : 1;
    Uint32 bypass1 : 1;
    Uint32 bypass2 : 1;
    Uint32 bypass3 : 1;
    Uint32 bypass4 : 1;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_FB_LUT_BYPASS_REG;

/*  */
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS0_MASK (0x00000100u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS0_SHIFT (0x00000008u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS0_RESETVAL (0x00000001u)

/*  */
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS1_MASK (0x00000200u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS1_SHIFT (0x00000009u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS1_RESETVAL (0x00000001u)

/*  */
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS2_MASK (0x00000400u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS2_SHIFT (0x0000000Au)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS2_RESETVAL (0x00000001u)

/*  */
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS3_MASK (0x00000800u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS3_SHIFT (0x0000000Bu)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS3_RESETVAL (0x00000001u)

/* Single-tap non-linear LUT block bypass control.  */
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS4_MASK (0x00001000u)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS4_SHIFT (0x0000000Cu)
#define CSL_DFE_FB_LUT_BYPASS_REG_BYPASS4_RESETVAL (0x00000001u)

#define CSL_DFE_FB_LUT_BYPASS_REG_ADDR (0x00000218u)
#define CSL_DFE_FB_LUT_BYPASS_REG_RESETVAL (0x00001F00u)

/* TESTBUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 top_test_ctrl : 4;
    Uint32 rsvd0 : 12;
#else 
    Uint32 rsvd0 : 12;
    Uint32 top_test_ctrl : 4;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_FB_TESTBUS_REG;

/* Testbus control. Top level FB sub-block node selection.   */
#define CSL_DFE_FB_TESTBUS_REG_TOP_TEST_CTRL_MASK (0x0000F000u)
#define CSL_DFE_FB_TESTBUS_REG_TOP_TEST_CTRL_SHIFT (0x0000000Cu)
#define CSL_DFE_FB_TESTBUS_REG_TOP_TEST_CTRL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_TESTBUS_REG_ADDR (0x0000022Cu)
#define CSL_DFE_FB_TESTBUS_REG_RESETVAL (0x00000000u)

/* DC_TESTBUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 dc_test_ctrl : 9;
#else 
    Uint32 dc_test_ctrl : 9;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_FB_DC_TESTBUS_REG;

/* Testbus control. Feagc & DC node selection. */
#define CSL_DFE_FB_DC_TESTBUS_REG_DC_TEST_CTRL_MASK (0x000001FFu)
#define CSL_DFE_FB_DC_TESTBUS_REG_DC_TEST_CTRL_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_TESTBUS_REG_DC_TEST_CTRL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_TESTBUS_REG_ADDR (0x00000230u)
#define CSL_DFE_FB_DC_TESTBUS_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_NCO_FREQ_WORD_W0_REG;

/* NCO/Mixer block frequency control words. */
#define CSL_DFE_FB_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_FREQ_WORD_W0_REG_ADDR (0x00000240u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_NCO_FREQ_WORD_W1_REG;

/*  */
#define CSL_DFE_FB_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_FREQ_WORD_W1_REG_ADDR (0x00000244u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_NCO_FREQ_WORD_W2_REG;

/*  */
#define CSL_DFE_FB_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_FB_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_FREQ_WORD_W2_REG_ADDR (0x00000248u)
#define CSL_DFE_FB_NCO_FREQ_WORD_W2_REG_RESETVAL (0x00000000u)

/* GAIN_GAIN_REAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gain_real : 16;
#else 
    Uint32 gain_real : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_FB_GAIN_GAIN_REAL_REG;

/* Output complex gain real part (3.13 format.) */
#define CSL_DFE_FB_GAIN_GAIN_REAL_REG_GAIN_REAL_MASK (0x0000FFFFu)
#define CSL_DFE_FB_GAIN_GAIN_REAL_REG_GAIN_REAL_SHIFT (0x00000000u)
#define CSL_DFE_FB_GAIN_GAIN_REAL_REG_GAIN_REAL_RESETVAL (0x00002000u)

#define CSL_DFE_FB_GAIN_GAIN_REAL_REG_ADDR (0x000002B0u)
#define CSL_DFE_FB_GAIN_GAIN_REAL_REG_RESETVAL (0x00002000u)

/* GAIN_GAIN_IMAG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gain_imag : 16;
#else 
    Uint32 gain_imag : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_FB_GAIN_GAIN_IMAG_REG;

/* Output complex gain imaginary part (3.13 format.) */
#define CSL_DFE_FB_GAIN_GAIN_IMAG_REG_GAIN_IMAG_MASK (0x0000FFFFu)
#define CSL_DFE_FB_GAIN_GAIN_IMAG_REG_GAIN_IMAG_SHIFT (0x00000000u)
#define CSL_DFE_FB_GAIN_GAIN_IMAG_REG_GAIN_IMAG_RESETVAL (0x00002000u)

#define CSL_DFE_FB_GAIN_GAIN_IMAG_REG_ADDR (0x000002B4u)
#define CSL_DFE_FB_GAIN_GAIN_IMAG_REG_RESETVAL (0x00002000u)

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
} CSL_DFE_FB_R2C_SSEL_REG;

/* Real-to-Complex block sync selection control for resetting the Fs/4 mixer phase. */
#define CSL_DFE_FB_R2C_SSEL_REG_PHASE_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_R2C_SSEL_REG_PHASE_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_R2C_SSEL_REG_PHASE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_R2C_SSEL_REG_ADDR (0x00000300u)
#define CSL_DFE_FB_R2C_SSEL_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_NCO_SSEL_REG;

/* NCO/Mixer block sync selection control for syncing frequency control words into the NCO. */
#define CSL_DFE_FB_NCO_SSEL_REG_FREQ_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_NCO_SSEL_REG_FREQ_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_NCO_SSEL_REG_FREQ_SSEL_RESETVAL (0x00000000u)

/* NCO/Mixer block sync selection control to zero the NCO phase accumulator. */
#define CSL_DFE_FB_NCO_SSEL_REG_PHASE_SSEL_MASK (0x000000F0u)
#define CSL_DFE_FB_NCO_SSEL_REG_PHASE_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_FB_NCO_SSEL_REG_PHASE_SSEL_RESETVAL (0x00000000u)

/* NCO/Mixer block sync selection control to reset the NCO dither generator. */
#define CSL_DFE_FB_NCO_SSEL_REG_DITHER_SSEL_MASK (0x00000F00u)
#define CSL_DFE_FB_NCO_SSEL_REG_DITHER_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_FB_NCO_SSEL_REG_DITHER_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_NCO_SSEL_REG_ADDR (0x00000304u)
#define CSL_DFE_FB_NCO_SSEL_REG_RESETVAL (0x00000000u)

/* EQR_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 ssel0 : 4;
#else 
    Uint32 ssel0 : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_FB_EQR_SSEL_REG;

/*  */
#define CSL_DFE_FB_EQR_SSEL_REG_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_FB_EQR_SSEL_REG_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_SSEL_REG_SSEL0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_SSEL_REG_ADDR (0x00000308u)
#define CSL_DFE_FB_EQR_SSEL_REG_RESETVAL (0x00000000u)

/* GAIN_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 ssel0 : 4;
#else 
    Uint32 ssel0 : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_FB_GAIN_SSEL_REG;

/* Output gain control sync select. */
#define CSL_DFE_FB_GAIN_SSEL_REG_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_FB_GAIN_SSEL_REG_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_FB_GAIN_SSEL_REG_SSEL0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_GAIN_SSEL_REG_ADDR (0x00000310u)
#define CSL_DFE_FB_GAIN_SSEL_REG_RESETVAL (0x00000000u)

/* DC_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 dkacc_ssel : 4;
#else 
    Uint32 dkacc_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_FB_DC_SSEL_REG;

/* DC Canceller sync source select for loading  */
#define CSL_DFE_FB_DC_SSEL_REG_DKACC_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_DC_SSEL_REG_DKACC_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_SSEL_REG_DKACC_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_SSEL_REG_ADDR (0x00000318u)
#define CSL_DFE_FB_DC_SSEL_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_TEST_SSEL_REG;

/* Signal generator sync selection control. */
#define CSL_DFE_FB_TEST_SSEL_REG_SIGGEN_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_TEST_SSEL_REG_SIGGEN_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_TEST_SSEL_REG_SIGGEN_SSEL_RESETVAL (0x00000000u)

/* Checksum signature analyzer sync selection control. */
#define CSL_DFE_FB_TEST_SSEL_REG_CHKSUM_SSEL_MASK (0x000000F0u)
#define CSL_DFE_FB_TEST_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_FB_TEST_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_TEST_SSEL_REG_ADDR (0x00000320u)
#define CSL_DFE_FB_TEST_SSEL_REG_RESETVAL (0x00000000u)

/* DC_GSG_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 gsg_update_sync_ssel : 4;
#else 
    Uint32 gsg_update_sync_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_FB_DC_GSG_SSEL_REG;

/* gsg_update sync source select */
#define CSL_DFE_FB_DC_GSG_SSEL_REG_GSG_UPDATE_SYNC_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_FB_DC_GSG_SSEL_REG_GSG_UPDATE_SYNC_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_GSG_SSEL_REG_GSG_UPDATE_SYNC_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_GSG_SSEL_REG_ADDR (0x00000388u)
#define CSL_DFE_FB_DC_GSG_SSEL_REG_RESETVAL (0x00000000u)

/* DC_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 19;
    Uint32 dc_frz_rst_int0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 dc_freeze : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 dc_freeze : 1;
    Uint32 rsvd1 : 3;
    Uint32 dc_frz_rst_int0 : 1;
    Uint32 rsvd2 : 19;
#endif 
} CSL_DFE_FB_DC_GLOBAL_REG;

/* DC Canceller freeze control.  Set to 1 to suspend dc cancellation function. */
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FREEZE_MASK (0x00000100u)
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FREEZE_SHIFT (0x00000008u)
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FREEZE_RESETVAL (0x00000000u)

/* Controls behavior of dc integration accumulator s(k) (power measurement) on “freeze” signal.  */
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FRZ_RST_INT0_MASK (0x00001000u)
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FRZ_RST_INT0_SHIFT (0x0000000Cu)
#define CSL_DFE_FB_DC_GLOBAL_REG_DC_FRZ_RST_INT0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_GLOBAL_REG_ADDR (0x00000700u)
#define CSL_DFE_FB_DC_GLOBAL_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_DC_INIT_REG;

/* Initial values for the 8 dc correction accumulator (d(k)) registers (2 per antenna) per dc cancellation block.  */
#define CSL_DFE_FB_DC_INIT_REG_DC_INIT_MASK (0x0000FFFFu)
#define CSL_DFE_FB_DC_INIT_REG_DC_INIT_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_INIT_REG_DC_INIT_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_INIT_REG_ADDR (0x00000704u)
#define CSL_DFE_FB_DC_INIT_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_DC_INTERVAL_W0_REG;

/* Integration interval value (0 to 2^24 – 1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate) between dc_update pulses. Must be > 0 for normal operation. */
#define CSL_DFE_FB_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_INTERVAL_W0_REG_ADDR (0x00000724u)
#define CSL_DFE_FB_DC_INTERVAL_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_DC_INTERVAL_W1_REG;

/*  */
#define CSL_DFE_FB_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_FB_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_INTERVAL_W1_REG_ADDR (0x00000728u)
#define CSL_DFE_FB_DC_INTERVAL_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_DC_UPDATE_DELAY_REG;

/* DC Canceller delay value from sync to first dc_update pulse (0 to 2^16 -1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate). */
#define CSL_DFE_FB_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_MASK (0x0000FFFFu)
#define CSL_DFE_FB_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_UPDATE_DELAY_REG_ADDR (0x0000072Cu)
#define CSL_DFE_FB_DC_UPDATE_DELAY_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_DC_SHIFT_MODE_REG;

/* DC Canceller shift control. Right shift value to apply to the integrated dc signal. Range 0 to 31. Typically set to log2(dc_interval) + 3 for fast tracking and log2(dc_interval) + 7 for slow tracking. */
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_SHIFT_RESETVAL (0x00000000u)

/* DC Canceller mode control. */
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_MODE_MASK (0x00008000u)
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_MODE_SHIFT (0x0000000Fu)
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_DC_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_FB_DC_SHIFT_MODE_REG_ADDR (0x0000073Cu)
#define CSL_DFE_FB_DC_SHIFT_MODE_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_MODE_REG;

/* I bus input signal generator enable.  Broadcast to both the inline and cross I inputs. */
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_MASK (0x00000001u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_RESETVAL (0x00000000u)

/* I bus input signal generator frame enable. */
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_MASK (0x00000002u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_RESETVAL (0x00000000u)

/* I bus input signal generator ramp enable. */
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_MASK (0x00000004u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_SHIFT (0x00000002u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_MASK (0x00000008u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_SHIFT (0x00000003u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_RESETVAL (0x00000000u)

/* I bus input signal generator frame length in clocks when sig_gen_I_frame is enabled. */
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_SHIFT (0x00000004u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_MODE_REG_ADDR (0x00000740u)
#define CSL_DFE_FB_SIGGEN_I_MODE_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG;

/* I bus input ramp start value.  If ramp mode is enabled, the ramp generator starts at this value. */
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG_ADDR (0x00000744u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG_ADDR (0x00000748u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_START_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG;

/* I bus input ramp stop value.  If ramp mode is enabled, the ramp generator rolls over to the ramp start value when this value is hit.   */
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG_ADDR (0x0000074Cu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG_ADDR (0x00000750u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_STOP_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG;

/* I bus input ramp increment value.  If ramp mode is enabled, the ramp generator increments by this value every clock. */
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG_ADDR (0x00000754u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG_ADDR (0x00000758u)
#define CSL_DFE_FB_SIGGEN_I_RAMP_INC_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG_ADDR (0x0000075Cu)
#define CSL_DFE_FB_SIGGEN_I_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_MODE_REG;

/* Q bus input signal generator enable.  Broadcast to both the inline and cross Q inputs. */
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_MASK (0x00000001u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_RESETVAL (0x00000000u)

/* Q bus input signal generator frame enable. */
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_MASK (0x00000002u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_RESETVAL (0x00000000u)

/* Q bus input signal generator ramp enable. */
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_MASK (0x00000004u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_SHIFT (0x00000002u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_MASK (0x00000008u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_SHIFT (0x00000003u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_RESETVAL (0x00000000u)

/* Q bus input signal generator frame length in clocks when sig_gen_Q_frame is enabled. */
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_SHIFT (0x00000004u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_ADDR (0x00000764u)
#define CSL_DFE_FB_SIGGEN_Q_MODE_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG;

/* Q bus input ramp start value.  If ramp mode is enabled, the ramp generator starts at this value. */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG_ADDR (0x00000768u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG_ADDR (0x0000076Cu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_START_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG;

/* Q bus input ramp stop value.  If ramp mode is enabled, the ramp generator rolls over to the ramp start value when this value is hit.   */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG_ADDR (0x00000770u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG_ADDR (0x00000774u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_STOP_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_INCR_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_inc_15_0 : 16;
#else 
    Uint32 siggen_q_ramp_inc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG;

/* Q bus input ramp increment value.  If ramp mode is enabled, the ramp generator increments by this value every clock. */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG_SIGGEN_Q_RAMP_INC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG_SIGGEN_Q_RAMP_INC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG_SIGGEN_Q_RAMP_INC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG_ADDR (0x00000778u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_INCR_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_inc_31_16 : 16;
#else 
    Uint32 siggen_q_ramp_inc_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG;

/*  */
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG_SIGGEN_Q_RAMP_INC_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG_SIGGEN_Q_RAMP_INC_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG_SIGGEN_Q_RAMP_INC_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG_ADDR (0x0000077Cu)
#define CSL_DFE_FB_SIGGEN_Q_RAMP_INCR_W1_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG_ADDR (0x00000780u)
#define CSL_DFE_FB_SIGGEN_Q_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_CHKSUM_MODE_REG;

/* Checksum mode control: 1 = return latency, 0 = return checksum */
#define CSL_DFE_FB_CHKSUM_MODE_REG_CHKSUM_MODE_MASK (0x00000001u)
#define CSL_DFE_FB_CHKSUM_MODE_REG_CHKSUM_MODE_SHIFT (0x00000000u)
#define CSL_DFE_FB_CHKSUM_MODE_REG_CHKSUM_MODE_RESETVAL (0x00000000u)

/* Latency mode number of clocks that data must remain stable for after pulse */
#define CSL_DFE_FB_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_FB_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_FB_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_FB_CHKSUM_MODE_REG_ADDR (0x00000788u)
#define CSL_DFE_FB_CHKSUM_MODE_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_CHKSUM_SIG_LEN_REG;

/* Latency mode width of data pulse from signal generator */
#define CSL_DFE_FB_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_FB_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_FB_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_FB_CHKSUM_SIG_LEN_REG_ADDR (0x0000078Cu)
#define CSL_DFE_FB_CHKSUM_SIG_LEN_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_CHKSUM_CHAN_SEL_REG;

/* Latency mode channel select (specified by clocks after frame signal) */
#define CSL_DFE_FB_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_FB_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_FB_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_FB_CHKSUM_CHAN_SEL_REG_ADDR (0x00000790u)
#define CSL_DFE_FB_CHKSUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_CHKSUM_W0_REG;

/* Lower 16 bits of rx subchip output checksum signature analyzer result. */
#define CSL_DFE_FB_CHKSUM_W0_REG_CHKSUM_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_FB_CHKSUM_W0_REG_CHKSUM_15_0_SHIFT (0x00000000u)
#define CSL_DFE_FB_CHKSUM_W0_REG_CHKSUM_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_CHKSUM_W0_REG_ADDR (0x00000794u)
#define CSL_DFE_FB_CHKSUM_W0_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_FB_CHKSUM_W1_REG;

/* Upper 16 bits of rx subchip output checksum signature analyzer result. */
#define CSL_DFE_FB_CHKSUM_W1_REG_CHKSUM_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_FB_CHKSUM_W1_REG_CHKSUM_31_16_SHIFT (0x00000000u)
#define CSL_DFE_FB_CHKSUM_W1_REG_CHKSUM_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_FB_CHKSUM_W1_REG_ADDR (0x00000798u)
#define CSL_DFE_FB_CHKSUM_W1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_ii0 : 32;
#else 
    Uint32 taps_ii0 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_II0_REG;

/* Equalizer block i-taps on i-data path. The lower 16-bits of each word are the even indexed taps (0, 2, 4, …, 14) and the upper 16-bits are the odd indexed taps (1,3,5, …, 15) */
#define CSL_DFE_FB_EQR_TAPS_II0_REG_TAPS_II0_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_II0_REG_TAPS_II0_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_II0_REG_TAPS_II0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_II0_REG_ADDR (0x00040000u)
#define CSL_DFE_FB_EQR_TAPS_II0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_iq0 : 32;
#else 
    Uint32 taps_iq0 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_IQ0_REG;

/* Equalizer block q-taps on i-data path. The lower 16-bits of each word are the even indexed taps (0, 2, 4, …, 14) and the upper 16-bits are the odd indexed taps (1,3,5, …, 15) */
#define CSL_DFE_FB_EQR_TAPS_IQ0_REG_TAPS_IQ0_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_IQ0_REG_TAPS_IQ0_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_IQ0_REG_TAPS_IQ0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_IQ0_REG_ADDR (0x00040020u)
#define CSL_DFE_FB_EQR_TAPS_IQ0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qi0 : 32;
#else 
    Uint32 taps_qi0 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QI0_REG;

/* Equalizer block i-taps on q-data path. The lower 16-bits of each word are the even indexed taps (0, 2, 4, …, 14) and the upper 16-bits are the odd indexed taps (1,3,5, …, 15) */
#define CSL_DFE_FB_EQR_TAPS_QI0_REG_TAPS_QI0_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QI0_REG_TAPS_QI0_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QI0_REG_TAPS_QI0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QI0_REG_ADDR (0x00040040u)
#define CSL_DFE_FB_EQR_TAPS_QI0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qq0 : 32;
#else 
    Uint32 taps_qq0 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QQ0_REG;

/* Equalizer block q-taps on q-data path. The lower 16-bits of each word are the even indexed taps (0, 2, 4, …, 14) and the upper 16-bits are the odd indexed taps (1,3,5, …, 15) */
#define CSL_DFE_FB_EQR_TAPS_QQ0_REG_TAPS_QQ0_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QQ0_REG_TAPS_QQ0_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QQ0_REG_TAPS_QQ0_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QQ0_REG_ADDR (0x00040060u)
#define CSL_DFE_FB_EQR_TAPS_QQ0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_ii1 : 32;
#else 
    Uint32 taps_ii1 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_II1_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_II1_REG_TAPS_II1_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_II1_REG_TAPS_II1_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_II1_REG_TAPS_II1_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_II1_REG_ADDR (0x00040080u)
#define CSL_DFE_FB_EQR_TAPS_II1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_iq1 : 32;
#else 
    Uint32 taps_iq1 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_IQ1_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_IQ1_REG_TAPS_IQ1_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_IQ1_REG_TAPS_IQ1_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_IQ1_REG_TAPS_IQ1_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_IQ1_REG_ADDR (0x000400A0u)
#define CSL_DFE_FB_EQR_TAPS_IQ1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qi1 : 32;
#else 
    Uint32 taps_qi1 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QI1_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QI1_REG_TAPS_QI1_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QI1_REG_TAPS_QI1_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QI1_REG_TAPS_QI1_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QI1_REG_ADDR (0x000400C0u)
#define CSL_DFE_FB_EQR_TAPS_QI1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qq1 : 32;
#else 
    Uint32 taps_qq1 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QQ1_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QQ1_REG_TAPS_QQ1_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QQ1_REG_TAPS_QQ1_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QQ1_REG_TAPS_QQ1_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QQ1_REG_ADDR (0x000400E0u)
#define CSL_DFE_FB_EQR_TAPS_QQ1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_ii2 : 32;
#else 
    Uint32 taps_ii2 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_II2_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_II2_REG_TAPS_II2_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_II2_REG_TAPS_II2_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_II2_REG_TAPS_II2_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_II2_REG_ADDR (0x00040100u)
#define CSL_DFE_FB_EQR_TAPS_II2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_iq2 : 32;
#else 
    Uint32 taps_iq2 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_IQ2_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_IQ2_REG_TAPS_IQ2_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_IQ2_REG_TAPS_IQ2_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_IQ2_REG_TAPS_IQ2_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_IQ2_REG_ADDR (0x00040120u)
#define CSL_DFE_FB_EQR_TAPS_IQ2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qi2 : 32;
#else 
    Uint32 taps_qi2 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QI2_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QI2_REG_TAPS_QI2_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QI2_REG_TAPS_QI2_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QI2_REG_TAPS_QI2_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QI2_REG_ADDR (0x00040140u)
#define CSL_DFE_FB_EQR_TAPS_QI2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qq2 : 32;
#else 
    Uint32 taps_qq2 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QQ2_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QQ2_REG_TAPS_QQ2_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QQ2_REG_TAPS_QQ2_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QQ2_REG_TAPS_QQ2_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QQ2_REG_ADDR (0x00040160u)
#define CSL_DFE_FB_EQR_TAPS_QQ2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_ii3 : 32;
#else 
    Uint32 taps_ii3 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_II3_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_II3_REG_TAPS_II3_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_II3_REG_TAPS_II3_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_II3_REG_TAPS_II3_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_II3_REG_ADDR (0x00040180u)
#define CSL_DFE_FB_EQR_TAPS_II3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_iq3 : 32;
#else 
    Uint32 taps_iq3 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_IQ3_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_IQ3_REG_TAPS_IQ3_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_IQ3_REG_TAPS_IQ3_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_IQ3_REG_TAPS_IQ3_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_IQ3_REG_ADDR (0x000401A0u)
#define CSL_DFE_FB_EQR_TAPS_IQ3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qi3 : 32;
#else 
    Uint32 taps_qi3 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QI3_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QI3_REG_TAPS_QI3_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QI3_REG_TAPS_QI3_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QI3_REG_TAPS_QI3_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QI3_REG_ADDR (0x000401C0u)
#define CSL_DFE_FB_EQR_TAPS_QI3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qq3 : 32;
#else 
    Uint32 taps_qq3 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QQ3_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QQ3_REG_TAPS_QQ3_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QQ3_REG_TAPS_QQ3_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QQ3_REG_TAPS_QQ3_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QQ3_REG_ADDR (0x000401E0u)
#define CSL_DFE_FB_EQR_TAPS_QQ3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_ii4 : 32;
#else 
    Uint32 taps_ii4 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_II4_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_II4_REG_TAPS_II4_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_II4_REG_TAPS_II4_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_II4_REG_TAPS_II4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_II4_REG_ADDR (0x00040200u)
#define CSL_DFE_FB_EQR_TAPS_II4_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_iq4 : 32;
#else 
    Uint32 taps_iq4 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_IQ4_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_IQ4_REG_TAPS_IQ4_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_IQ4_REG_TAPS_IQ4_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_IQ4_REG_TAPS_IQ4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_IQ4_REG_ADDR (0x00040220u)
#define CSL_DFE_FB_EQR_TAPS_IQ4_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qi4 : 32;
#else 
    Uint32 taps_qi4 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QI4_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QI4_REG_TAPS_QI4_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QI4_REG_TAPS_QI4_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QI4_REG_TAPS_QI4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QI4_REG_ADDR (0x00040240u)
#define CSL_DFE_FB_EQR_TAPS_QI4_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 taps_qq4 : 32;
#else 
    Uint32 taps_qq4 : 32;
#endif 
} CSL_DFE_FB_EQR_TAPS_QQ4_REG;

/*  */
#define CSL_DFE_FB_EQR_TAPS_QQ4_REG_TAPS_QQ4_MASK (0xFFFFFFFFu)
#define CSL_DFE_FB_EQR_TAPS_QQ4_REG_TAPS_QQ4_SHIFT (0x00000000u)
#define CSL_DFE_FB_EQR_TAPS_QQ4_REG_TAPS_QQ4_RESETVAL (0x00000000u)

#define CSL_DFE_FB_EQR_TAPS_QQ4_REG_ADDR (0x00040260u)
#define CSL_DFE_FB_EQR_TAPS_QQ4_REG_RESETVAL (0x00000000u)

/* LUT_MEM */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 slope : 10;
    Uint32 dc : 16;
#else 
    Uint32 dc : 16;
    Uint32 slope : 10;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_FB_LUT_MEM_REG;

/* Single-tap non-linear LUT dc component. */
#define CSL_DFE_FB_LUT_MEM_REG_DC_MASK (0x0000FFFFu)
#define CSL_DFE_FB_LUT_MEM_REG_DC_SHIFT (0x00000000u)
#define CSL_DFE_FB_LUT_MEM_REG_DC_RESETVAL (0x00000000u)

/* Single-tap non-linear LUT slope component. */
#define CSL_DFE_FB_LUT_MEM_REG_SLOPE_MASK (0x03FF0000u)
#define CSL_DFE_FB_LUT_MEM_REG_SLOPE_SHIFT (0x00000010u)
#define CSL_DFE_FB_LUT_MEM_REG_SLOPE_RESETVAL (0x00000000u)

#define CSL_DFE_FB_LUT_MEM_REG_ADDR (0x00040800u)
#define CSL_DFE_FB_LUT_MEM_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_FB_H__ */
