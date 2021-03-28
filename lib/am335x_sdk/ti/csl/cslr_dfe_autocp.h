/*
 * cslr_dfe_autocp.h
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

/* The file is auto generated at 19:00:07 11/28/12 (Rev 1.68)*/

#ifndef CSLR_DFE_AUTOCP_H__
#define CSLR_DFE_AUTOCP_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 freq_15_0;
    volatile Uint32 freq_31_16;
    volatile Uint32 weight;
    volatile Uint32 cp;
} CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_REGS;

typedef struct
{
    volatile Uint32 ctl0;
    volatile Uint32 ctl1;
} CSL_DFE_AUTOCP_CFR_CTL_CFR_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 autocp_autocp_1;
    /* Addr: h(8), d(8) */
    volatile Uint32 autocp_autocp_2;
    /* Addr: h(C), d(12) */
    volatile Uint32 rsvd1[13];
    /* Addr: h(40), d(64) */
    volatile Uint32 inits;
    /* Addr: h(44), d(68) */
    volatile Uint32 rsvd2[65519];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 procp_ram_main_cp0[256];
    /* Addr: h(40400), d(263168) */
    volatile Uint32 procp_ram_main_cp1[256];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 procp_ram_main_cp2[256];
    /* Addr: h(40C00), d(265216) */
    volatile Uint32 procp_ram_main_cp3[256];
    /* Addr: h(41000), d(266240) */
    volatile Uint32 procp_ram_main_cp4[256];
    /* Addr: h(41400), d(267264) */
    volatile Uint32 procp_ram_main_cp5[256];
    /* Addr: h(41800), d(268288) */
    volatile Uint32 procp_ram_main_cp6[256];
    /* Addr: h(41C00), d(269312) */
    volatile Uint32 procp_ram_main_cp7[256];
    /* Addr: h(42000), d(270336) */
    volatile Uint32 procp_ram_main_cp8[256];
    /* Addr: h(42400), d(271360) */
    volatile Uint32 procp_ram_main_cp9[256];
    /* Addr: h(42800), d(272384) */
    volatile Uint32 procp_ram_main_cp10[256];
    /* Addr: h(42C00), d(273408) */
    volatile Uint32 procp_ram_main_cp11[256];
    /* Addr: h(43000), d(274432) */
    volatile Uint32 procp_ram_main_cp12[256];
    /* Addr: h(43400), d(275456) */
    volatile Uint32 procp_ram_main_cp13[256];
    /* Addr: h(43800), d(276480) */
    volatile Uint32 procp_ram_main_cp14[256];
    /* Addr: h(43C00), d(277504) */
    volatile Uint32 procp_ram_main_cp15[256];
    /* Addr: h(44000), d(278528) */
    volatile Uint32 procp_ram_delay_cp0[256];
    /* Addr: h(44400), d(279552) */
    volatile Uint32 procp_ram_delay_cp1[256];
    /* Addr: h(44800), d(280576) */
    volatile Uint32 procp_ram_delay_cp2[256];
    /* Addr: h(44C00), d(281600) */
    volatile Uint32 procp_ram_delay_cp3[256];
    /* Addr: h(45000), d(282624) */
    volatile Uint32 procp_ram_delay_cp4[256];
    /* Addr: h(45400), d(283648) */
    volatile Uint32 procp_ram_delay_cp5[256];
    /* Addr: h(45800), d(284672) */
    volatile Uint32 procp_ram_delay_cp6[256];
    /* Addr: h(45C00), d(285696) */
    volatile Uint32 procp_ram_delay_cp7[256];
    /* Addr: h(46000), d(286720) */
    volatile Uint32 procp_ram_delay_cp8[256];
    /* Addr: h(46400), d(287744) */
    volatile Uint32 procp_ram_delay_cp9[256];
    /* Addr: h(46800), d(288768) */
    volatile Uint32 procp_ram_delay_cp10[256];
    /* Addr: h(46C00), d(289792) */
    volatile Uint32 procp_ram_delay_cp11[256];
    /* Addr: h(47000), d(290816) */
    volatile Uint32 procp_ram_delay_cp12[256];
    /* Addr: h(47400), d(291840) */
    volatile Uint32 procp_ram_delay_cp13[256];
    /* Addr: h(47800), d(292864) */
    volatile Uint32 procp_ram_delay_cp14[256];
    /* Addr: h(47C00), d(293888) */
    volatile Uint32 procp_ram_delay_cp15[256];
    /* Addr: h(48000), d(294912) */
    volatile CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_REGS selection_ram_selection_ram[256];
    /* Addr: h(49000), d(299008) */
    volatile Uint32 ant_ram_ant_ram_ant_list[256];
    /* Addr: h(49400), d(300032) */
    volatile CSL_DFE_AUTOCP_CFR_CTL_CFR_REGS cfr_ctl_cfr[4];
} CSL_DFE_AUTOCP_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* AUTOCP_AUTOCP_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sel_ram_ssel : 4;
    Uint32 test_bus_sel : 3;
    Uint32 procp_cnt : 6;
    Uint32 delay_en : 1;
    Uint32 num_ant : 2;
#else 
    Uint32 num_ant : 2;
    Uint32 delay_en : 1;
    Uint32 procp_cnt : 6;
    Uint32 test_bus_sel : 3;
    Uint32 sel_ram_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG;

/* number of antennas 0 = 4; 1 = 8; 2,3 = 16 */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_NUM_ANT_MASK (0x00000003u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_NUM_ANT_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_NUM_ANT_RESETVAL (0x00000000u)

/* 1 to enable calc of delayed filter */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_DELAY_EN_MASK (0x00000004u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_DELAY_EN_SHIFT (0x00000002u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_DELAY_EN_RESETVAL (0x00000000u)

/* filter coef count counts from value to 0 */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_PROCP_CNT_MASK (0x000001F8u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_PROCP_CNT_SHIFT (0x00000003u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_PROCP_CNT_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_TEST_BUS_SEL_MASK (0x00000E00u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_TEST_BUS_SEL_SHIFT (0x00000009u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_TEST_BUS_SEL_RESETVAL (0x00000000u)

/* selection ram swap sync control */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_SEL_RAM_SSEL_MASK (0x0000F000u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_SEL_RAM_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_SEL_RAM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_ADDR (0x00000004u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_1_REG_RESETVAL (0x00000000u)

/* AUTOCP_AUTOCP_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_busy_cnt : 16;
#else 
    Uint32 cfr_busy_cnt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG;

/* Time value to wait for CFR to have it's swap ram available */
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG_CFR_BUSY_CNT_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG_CFR_BUSY_CNT_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG_CFR_BUSY_CNT_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG_ADDR (0x00000008u)
#define CSL_DFE_AUTOCP_AUTOCP_AUTOCP_2_REG_RESETVAL (0x00000000u)

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
} CSL_DFE_AUTOCP_INITS_REG;

/* Sync to release init_clk_gate, init_state and clear_data */
#define CSL_DFE_AUTOCP_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_AUTOCP_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* When set to 1, all clock gating logic is held in initial state. When set to 0 AND an inits_ssel is sent, clock gating logic is released from initial state. */
#define CSL_DFE_AUTOCP_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_AUTOCP_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_AUTOCP_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* When set to 1, all state machine logic is held in initial state. When set to 0 AND an inits_ssel is sent, state machine logic is released from initial state. */
#define CSL_DFE_AUTOCP_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_AUTOCP_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_AUTOCP_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* When set to 1, all data is forced to zero. When set to 0 AND an inits_ssel is sent, data is allowed to flow through. */
#define CSL_DFE_AUTOCP_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_AUTOCP_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_AUTOCP_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_AUTOCP_INITS_REG_ADDR (0x00000040u)
#define CSL_DFE_AUTOCP_INITS_REG_RESETVAL (0x00000070u)

/* PROCP_RAM_MAIN_CP0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp0 : 16;
#else 
    Uint32 main_cp0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG_MAIN_CP0_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG_MAIN_CP0_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG_MAIN_CP0_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG_ADDR (0x00040000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP0_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp1 : 16;
#else 
    Uint32 main_cp1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG_MAIN_CP1_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG_MAIN_CP1_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG_MAIN_CP1_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG_ADDR (0x00040400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP1_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp2 : 16;
#else 
    Uint32 main_cp2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG_MAIN_CP2_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG_MAIN_CP2_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG_MAIN_CP2_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG_ADDR (0x00040800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP2_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp3 : 16;
#else 
    Uint32 main_cp3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG_MAIN_CP3_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG_MAIN_CP3_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG_MAIN_CP3_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG_ADDR (0x00040C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP3_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp4 : 16;
#else 
    Uint32 main_cp4 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG_MAIN_CP4_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG_MAIN_CP4_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG_MAIN_CP4_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG_ADDR (0x00041000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP4_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp5 : 16;
#else 
    Uint32 main_cp5 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG_MAIN_CP5_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG_MAIN_CP5_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG_MAIN_CP5_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG_ADDR (0x00041400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP5_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp6 : 16;
#else 
    Uint32 main_cp6 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG_MAIN_CP6_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG_MAIN_CP6_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG_MAIN_CP6_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG_ADDR (0x00041800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP6_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp7 : 16;
#else 
    Uint32 main_cp7 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG_MAIN_CP7_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG_MAIN_CP7_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG_MAIN_CP7_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG_ADDR (0x00041C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP7_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp8 : 16;
#else 
    Uint32 main_cp8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG_MAIN_CP8_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG_MAIN_CP8_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG_MAIN_CP8_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG_ADDR (0x00042000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP8_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp9 : 16;
#else 
    Uint32 main_cp9 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG_MAIN_CP9_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG_MAIN_CP9_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG_MAIN_CP9_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG_ADDR (0x00042400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP9_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp10 : 16;
#else 
    Uint32 main_cp10 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG_MAIN_CP10_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG_MAIN_CP10_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG_MAIN_CP10_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG_ADDR (0x00042800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP10_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp11 : 16;
#else 
    Uint32 main_cp11 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG_MAIN_CP11_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG_MAIN_CP11_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG_MAIN_CP11_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG_ADDR (0x00042C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP11_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp12 : 16;
#else 
    Uint32 main_cp12 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG_MAIN_CP12_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG_MAIN_CP12_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG_MAIN_CP12_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG_ADDR (0x00043000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP12_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp13 : 16;
#else 
    Uint32 main_cp13 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG_MAIN_CP13_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG_MAIN_CP13_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG_MAIN_CP13_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG_ADDR (0x00043400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP13_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp14 : 16;
#else 
    Uint32 main_cp14 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG_MAIN_CP14_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG_MAIN_CP14_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG_MAIN_CP14_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG_ADDR (0x00043800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP14_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_MAIN_CP15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 main_cp15 : 16;
#else 
    Uint32 main_cp15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG_MAIN_CP15_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG_MAIN_CP15_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG_MAIN_CP15_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG_ADDR (0x00043C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_MAIN_CP15_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp0 : 16;
#else 
    Uint32 delay_cp0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG_DELAY_CP0_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG_DELAY_CP0_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG_DELAY_CP0_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG_ADDR (0x00044000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP0_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp1 : 16;
#else 
    Uint32 delay_cp1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG_DELAY_CP1_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG_DELAY_CP1_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG_DELAY_CP1_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG_ADDR (0x00044400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP1_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp2 : 16;
#else 
    Uint32 delay_cp2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG_DELAY_CP2_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG_DELAY_CP2_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG_DELAY_CP2_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG_ADDR (0x00044800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP2_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp3 : 16;
#else 
    Uint32 delay_cp3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG_DELAY_CP3_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG_DELAY_CP3_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG_DELAY_CP3_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG_ADDR (0x00044C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP3_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp4 : 16;
#else 
    Uint32 delay_cp4 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG_DELAY_CP4_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG_DELAY_CP4_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG_DELAY_CP4_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG_ADDR (0x00045000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP4_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp5 : 16;
#else 
    Uint32 delay_cp5 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG_DELAY_CP5_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG_DELAY_CP5_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG_DELAY_CP5_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG_ADDR (0x00045400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP5_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp6 : 16;
#else 
    Uint32 delay_cp6 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG_DELAY_CP6_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG_DELAY_CP6_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG_DELAY_CP6_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG_ADDR (0x00045800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP6_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp7 : 16;
#else 
    Uint32 delay_cp7 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG_DELAY_CP7_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG_DELAY_CP7_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG_DELAY_CP7_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG_ADDR (0x00045C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP7_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp8 : 16;
#else 
    Uint32 delay_cp8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG_DELAY_CP8_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG_DELAY_CP8_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG_DELAY_CP8_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG_ADDR (0x00046000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP8_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp9 : 16;
#else 
    Uint32 delay_cp9 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG_DELAY_CP9_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG_DELAY_CP9_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG_DELAY_CP9_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG_ADDR (0x00046400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP9_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp10 : 16;
#else 
    Uint32 delay_cp10 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG_DELAY_CP10_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG_DELAY_CP10_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG_DELAY_CP10_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG_ADDR (0x00046800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP10_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp11 : 16;
#else 
    Uint32 delay_cp11 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG_DELAY_CP11_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG_DELAY_CP11_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG_DELAY_CP11_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG_ADDR (0x00046C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP11_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp12 : 16;
#else 
    Uint32 delay_cp12 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG_DELAY_CP12_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG_DELAY_CP12_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG_DELAY_CP12_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG_ADDR (0x00047000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP12_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp13 : 16;
#else 
    Uint32 delay_cp13 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG_DELAY_CP13_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG_DELAY_CP13_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG_DELAY_CP13_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG_ADDR (0x00047400u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP13_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp14 : 16;
#else 
    Uint32 delay_cp14 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG_DELAY_CP14_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG_DELAY_CP14_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG_DELAY_CP14_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG_ADDR (0x00047800u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP14_REG_RESETVAL (0x00000000u)

/* PROCP_RAM_DELAY_CP15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 delay_cp15 : 16;
#else 
    Uint32 delay_cp15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG;

/* proto cp coeficents */
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG_DELAY_CP15_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG_DELAY_CP15_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG_DELAY_CP15_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG_ADDR (0x00047C00u)
#define CSL_DFE_AUTOCP_PROCP_RAM_DELAY_CP15_REG_RESETVAL (0x00000000u)

/* SELECTION_RAM_SELECTION_RAM_FREQ_15_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_15_0 : 16;
#else 
    Uint32 freq_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG;

/* freq[15:0] */
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG_FREQ_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG_FREQ_15_0_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG_FREQ_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG_ADDR (0x00048000u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_15_0_REG_RESETVAL (0x00000000u)

/* SELECTION_RAM_SELECTION_RAM_FREQ_31_16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_31_16 : 16;
#else 
    Uint32 freq_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG;

/* freq[31:16] */
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG_FREQ_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG_FREQ_31_16_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG_FREQ_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG_ADDR (0x00048004u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_FREQ_31_16_REG_RESETVAL (0x00000000u)

/* SELECTION_RAM_SELECTION_RAM_WEIGHT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 weight : 16;
#else 
    Uint32 weight : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG;

/* weight */
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG_WEIGHT_MASK (0x0000FFFFu)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG_WEIGHT_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG_WEIGHT_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG_ADDR (0x00048008u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_WEIGHT_REG_RESETVAL (0x00000000u)

/* SELECTION_RAM_SELECTION_RAM_CP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 bypass : 1;
    Uint32 cp : 4;
#else 
    Uint32 cp : 4;
    Uint32 bypass : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG;

/* cp */
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_CP_MASK (0x0000000Fu)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_CP_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_CP_RESETVAL (0x00000000u)

/* bypass */
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_BYPASS_MASK (0x00000010u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_BYPASS_SHIFT (0x00000004u)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_ADDR (0x0004800Cu)
#define CSL_DFE_AUTOCP_SELECTION_RAM_SELECTION_RAM_CP_REG_RESETVAL (0x00000000u)

/* ANT_RAM_ANT_RAM_ANT_LIST */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 ant_list : 8;
#else 
    Uint32 ant_list : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG;

/* ant list */
#define CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG_ANT_LIST_MASK (0x000000FFu)
#define CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG_ANT_LIST_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG_ANT_LIST_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG_ADDR (0x00049000u)
#define CSL_DFE_AUTOCP_ANT_RAM_ANT_RAM_ANT_LIST_REG_RESETVAL (0x00000000u)

/* CFR_CTL_CFR_CTL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_cken : 8;
    Uint32 cfr_len_m1 : 8;
#else 
    Uint32 cfr_len_m1 : 8;
    Uint32 cfr_cken : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG;

/* number of cfr writes - 1 */
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_LEN_M1_MASK (0x000000FFu)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_LEN_M1_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_LEN_M1_RESETVAL (0x00000000u)

/* cfr_cken */
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_CKEN_MASK (0x0000FF00u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_CKEN_SHIFT (0x00000008u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_CFR_CKEN_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_ADDR (0x00049400u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL0_REG_RESETVAL (0x00000000u)

/* CFR_CTL_CFR_CTL1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 two_per_flag : 1;
#else 
    Uint32 two_per_flag : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG;

/* 2 per flag */
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG_TWO_PER_FLAG_MASK (0x00000001u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG_TWO_PER_FLAG_SHIFT (0x00000000u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG_TWO_PER_FLAG_RESETVAL (0x00000000u)

#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG_ADDR (0x00049404u)
#define CSL_DFE_AUTOCP_CFR_CTL_CFR_CTL1_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_AUTOCP_H__ */
