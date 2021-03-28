/*
 * cslr_dfe_misc.h
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

/* The file is auto generated at 16:45:20 02/08/13 (Rev 1.68)*/

#ifndef CSLR_DFE_MISC_H__
#define CSLR_DFE_MISC_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 mem0;
    volatile Uint32 mem1;
} CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_REGS;

typedef struct
{
    volatile Uint32 mem0;
    volatile Uint32 mem1;
} CSL_DFE_MISC_ARBITER_LOG_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 cfg1;
    /* Addr: h(8), d(8) */
    volatile Uint32 cfg2;
    /* Addr: h(C), d(12) */
    volatile Uint32 rsvd1[13];
    /* Addr: h(40), d(64) */
    volatile Uint32 cpp_cfg10;
    /* Addr: h(44), d(68) */
    volatile Uint32 cpp_cfg11;
    /* Addr: h(48), d(72) */
    volatile Uint32 cpp_cfg12;
    /* Addr: h(4C), d(76) */
    volatile Uint32 cpp_cfg13;
    /* Addr: h(50), d(80) */
    volatile Uint32 cpp_cfg14;
    /* Addr: h(54), d(84) */
    volatile Uint32 cpp_cfg15;
    /* Addr: h(58), d(88) */
    volatile Uint32 cpp_cfg16;
    /* Addr: h(5C), d(92) */
    volatile Uint32 cpp_cfg17;
    /* Addr: h(60), d(96) */
    volatile Uint32 cpp_cfg18;
    /* Addr: h(64), d(100) */
    volatile Uint32 cpp_cfg19;
    /* Addr: h(68), d(104) */
    volatile Uint32 cpp_cfg20;
    /* Addr: h(6C), d(108) */
    volatile Uint32 cpp_cfg21;
    /* Addr: h(70), d(112) */
    volatile Uint32 rsvd2[4];
    /* Addr: h(80), d(128) */
    volatile Uint32 cpp_dma[32];
    /* Addr: h(100), d(256) */
    volatile Uint32 rsvd3[192];
    /* Addr: h(400), d(1024) */
    volatile CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_REGS cpp_dma_descriptor[128];
    /* Addr: h(800), d(2048) */
    volatile Uint32 rsvd4[513];
    /* Addr: h(1004), d(4100) */
    volatile Uint32 arbiter_cfg_arb1;
    /* Addr: h(1008), d(4104) */
    volatile Uint32 arbiter_cfg_arb2;
    /* Addr: h(100C), d(4108) */
    volatile Uint32 arbiter_cfg_arb3;
    /* Addr: h(1010), d(4112) */
    volatile Uint32 arbiter_cfg_arb4;
    /* Addr: h(1014), d(4116) */
    volatile Uint32 arbiter_cfg_arb5;
    /* Addr: h(1018), d(4120) */
    volatile Uint32 rsvd5[1];
    /* Addr: h(101C), d(4124) */
    volatile Uint32 arbiter_cfg_arb7;
    /* Addr: h(1020), d(4128) */
    volatile Uint32 arbiter_cfg_arb8;
    /* Addr: h(1024), d(4132) */
    volatile Uint32 arbiter_cfg_arb9;
    /* Addr: h(1028), d(4136) */
    volatile Uint32 arbiter_cfg_arb10;
    /* Addr: h(102C), d(4140) */
    volatile Uint32 arbiter_cfg_arb11;
    /* Addr: h(1030), d(4144) */
    volatile Uint32 arbiter_cfg_arb12;
    /* Addr: h(1034), d(4148) */
    volatile Uint32 rsvd6[3];
    /* Addr: h(1040), d(4160) */
    volatile Uint32 arbiter_cfg_arb16;
    /* Addr: h(1044), d(4164) */
    volatile Uint32 arbiter_cfg_arb17;
    /* Addr: h(1048), d(4168) */
    volatile Uint32 arbiter_cfg_arb18;
    /* Addr: h(104C), d(4172) */
    volatile Uint32 arbiter_cfg_arb19;
    /* Addr: h(1050), d(4176) */
    volatile Uint32 arbiter_cfg_arb20;
    /* Addr: h(1054), d(4180) */
    volatile Uint32 arbiter_cfg_arb21;
    /* Addr: h(1058), d(4184) */
    volatile Uint32 arbiter_cfg_arb22;
    /* Addr: h(105C), d(4188) */
    volatile Uint32 arbiter_cfg_arb23;
    /* Addr: h(1060), d(4192) */
    volatile Uint32 arbiter_cfg_arb24;
    /* Addr: h(1064), d(4196) */
    volatile Uint32 rsvd7[1];
    /* Addr: h(1068), d(4200) */
    volatile Uint32 arbiter_cfg_arb26;
    /* Addr: h(106C), d(4204) */
    volatile Uint32 rsvd8[37];
    /* Addr: h(1100), d(4352) */
    volatile Uint32 arbiter_cfg_arb64;
    /* Addr: h(1104), d(4356) */
    volatile Uint32 arbiter_cfg_arb65;
    /* Addr: h(1108), d(4360) */
    volatile Uint32 arbiter_cfg_arb66;
    /* Addr: h(110C), d(4364) */
    volatile Uint32 arbiter_cfg_arb67;
    /* Addr: h(1110), d(4368) */
    volatile Uint32 arbiter_cfg_arb68;
    /* Addr: h(1114), d(4372) */
    volatile Uint32 arbiter_cfg_arb69;
    /* Addr: h(1118), d(4376) */
    volatile Uint32 arbiter_cfg_arb70;
    /* Addr: h(111C), d(4380) */
    volatile Uint32 rsvd9[185];
    /* Addr: h(1400), d(5120) */
    volatile CSL_DFE_MISC_ARBITER_LOG_REGS arbiter_log[72];
    /* Addr: h(1640), d(5696) */
    volatile Uint32 rsvd10[624];
    /* Addr: h(2000), d(8192) */
    volatile Uint32 misc_intr_mask_r0;
    /* Addr: h(2004), d(8196) */
    volatile Uint32 misc_intr_mask_r1;
    /* Addr: h(2008), d(8200) */
    volatile Uint32 misc_intr_mask_r2;
    /* Addr: h(200C), d(8204) */
    volatile Uint32 misc_intr_mask_r3;
    /* Addr: h(2010), d(8208) */
    volatile Uint32 misc_intr_mask_r4;
    /* Addr: h(2014), d(8212) */
    volatile Uint32 misc_intr_mask_r5;
    /* Addr: h(2018), d(8216) */
    volatile Uint32 misc_intr_mask_r6;
    /* Addr: h(201C), d(8220) */
    volatile Uint32 misc_intr_mask_r7;
    /* Addr: h(2020), d(8224) */
    volatile Uint32 misc_intr_mask_r8;
    /* Addr: h(2024), d(8228) */
    volatile Uint32 rsvd11[55];
    /* Addr: h(2100), d(8448) */
    volatile Uint32 master_int_master_lp_intr_mask_r0;
    /* Addr: h(2104), d(8452) */
    volatile Uint32 master_int_master_lp_intr_mask_r1;
    /* Addr: h(2108), d(8456) */
    volatile Uint32 master_int_master_lp_intr_mask_r2;
    /* Addr: h(210C), d(8460) */
    volatile Uint32 rsvd12[61];
    /* Addr: h(2200), d(8704) */
    volatile Uint32 master_int_master_hp_intr_mask_r0;
    /* Addr: h(2204), d(8708) */
    volatile Uint32 master_int_master_hp_intr_mask_r1;
    /* Addr: h(2208), d(8712) */
    volatile Uint32 master_int_master_hp_intr_mask_r2;
    /* Addr: h(220C), d(8716) */
    volatile Uint32 rsvd13[61];
    /* Addr: h(2300), d(8960) */
    volatile Uint32 gpio_cntrl_gpio_map0;
    /* Addr: h(2304), d(8964) */
    volatile Uint32 gpio_cntrl_gpio_map1;
    /* Addr: h(2308), d(8968) */
    volatile Uint32 gpio_cntrl_gpio_map2;
    /* Addr: h(230C), d(8972) */
    volatile Uint32 gpio_cntrl_gpio_map3;
    /* Addr: h(2310), d(8976) */
    volatile Uint32 gpio_cntrl_gpio_map4;
    /* Addr: h(2314), d(8980) */
    volatile Uint32 gpio_cntrl_gpio_map5;
    /* Addr: h(2318), d(8984) */
    volatile Uint32 rsvd14[58];
    /* Addr: h(2400), d(9216) */
    volatile Uint32 sync_gen_mpu_sync;
    /* Addr: h(2404), d(9220) */
    volatile Uint32 sync_gen_one_shot_ctrl_0_7;
    /* Addr: h(2408), d(9224) */
    volatile Uint32 sync_gen_one_shot_ctrl_8_13;
    /* Addr: h(240C), d(9228) */
    volatile Uint32 sync_gen_iq0_sync_ch_sel;
    /* Addr: h(2410), d(9232) */
    volatile Uint32 rsvd15[1];
    /* Addr: h(2414), d(9236) */
    volatile Uint32 sync_gen_cntr0_sync_gen_cntr0_ctrl;
    /* Addr: h(2418), d(9240) */
    volatile Uint32 sync_gen_cntr0_sync_gen_cntr0_period;
    /* Addr: h(241C), d(9244) */
    volatile Uint32 sync_gen_cntr0_sync_gen_cntr0_delay;
    /* Addr: h(2420), d(9248) */
    volatile Uint32 sync_gen_cntr0_sync_gen_cntr0_pulse;
    /* Addr: h(2424), d(9252) */
    volatile Uint32 sync_gen_cntr1_sync_gen_cntr1_ctrl;
    /* Addr: h(2428), d(9256) */
    volatile Uint32 sync_gen_cntr1_sync_gen_cntr1_period;
    /* Addr: h(242C), d(9260) */
    volatile Uint32 sync_gen_cntr1_sync_gen_cntr1_delay;
    /* Addr: h(2430), d(9264) */
    volatile Uint32 sync_gen_cntr1_sync_gen_cntr1_pulse;
    /* Addr: h(2434), d(9268) */
    volatile Uint32 sync_gen_cntr2_sync_gen_cntr2_ctrl;
    /* Addr: h(2438), d(9272) */
    volatile Uint32 sync_gen_cntr2_sync_gen_cntr2_period;
    /* Addr: h(243C), d(9276) */
    volatile Uint32 sync_gen_cntr2_sync_gen_cntr2_delay;
    /* Addr: h(2440), d(9280) */
    volatile Uint32 sync_gen_cntr2_sync_gen_cntr2_pulse;
    /* Addr: h(2444), d(9284) */
    volatile Uint32 rsvd16[47];
    /* Addr: h(2500), d(9472) */
    volatile Uint32 dvga_dvga0;
    /* Addr: h(2504), d(9476) */
    volatile Uint32 dvga_dvga1;
    /* Addr: h(2508), d(9480) */
    volatile Uint32 dvga_dvga2;
    /* Addr: h(250C), d(9484) */
    volatile Uint32 dvga_dvga3;
    /* Addr: h(2510), d(9488) */
    volatile Uint32 dvga_dvga4;
    /* Addr: h(2514), d(9492) */
    volatile Uint32 dvga_dvga5;
    /* Addr: h(2518), d(9496) */
    volatile Uint32 dvga_dvga6;
    /* Addr: h(251C), d(9500) */
    volatile Uint32 dvga_dvga7;
    /* Addr: h(2520), d(9504) */
    volatile Uint32 dvga_dvga8;
} CSL_DFE_MISC_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 misc_clear_data : 1;
    Uint32 misc_inits_state : 1;
    Uint32 misc_inits_clk_gate : 1;
    Uint32 misc_inits_ssel : 4;
#else 
    Uint32 misc_inits_ssel : 4;
    Uint32 misc_inits_clk_gate : 1;
    Uint32 misc_inits_state : 1;
    Uint32 misc_clear_data : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_MISC_CFG1_REG;

/* MISC module Sync select for init_clk_gate, init_state and clear_data */
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_SSEL_RESETVAL (0x00000000u)

/* MISC module Value of init_clk_gate. Updates when gsync[misc_inits_ssel] is true */
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_CLK_GATE_RESETVAL (0x00000001u)

/* MISC module Value of init_state. Updates when gsync[misc_inits_ssel] is true */
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_STATE_MASK (0x00000020u)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_STATE_SHIFT (0x00000005u)
#define CSL_DFE_MISC_CFG1_REG_MISC_INITS_STATE_RESETVAL (0x00000001u)

/* MISC module Value of clear. Updates when gsync[misc_inits_ssel] is true */
#define CSL_DFE_MISC_CFG1_REG_MISC_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_MISC_CFG1_REG_MISC_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_MISC_CFG1_REG_MISC_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_MISC_CFG1_REG_ADDR (0x00000004u)
#define CSL_DFE_MISC_CFG1_REG_RESETVAL (0x00000070u)

/* CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mem_mpu_access : 16;
#else 
    Uint32 mem_mpu_access : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_CFG2_REG;

/* Memory MPU ACCESS control word        [15:0]=  arb_mem_mpu_access, cb_mem_mpu_access,  fb_mem_mpu_access,  rx_mem_mpu_access, jesd_mem_mpu_access, tx_mem_mpu_access,  dpda_mem_mpu_access,  dpd_mem_mpu_access,  acl_mem_mpu_access, cfr1_mem_mpu_access,  cfr0_mem_mpu_access,  dduc3_mem_mpu_access,  dduc2_mem_mpu_access,  dduc1_mem_mpu_access,  dduc0_mem_mpu_access,  bb_mem_mpu_access */
#define CSL_DFE_MISC_CFG2_REG_MEM_MPU_ACCESS_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_CFG2_REG_MEM_MPU_ACCESS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CFG2_REG_MEM_MPU_ACCESS_RESETVAL (0x0000FFFFu)

#define CSL_DFE_MISC_CFG2_REG_ADDR (0x00000008u)
#define CSL_DFE_MISC_CFG2_REG_RESETVAL (0x0000FFFFu)

/* CPP_CFG10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 ctl_dma_config : 3;
#else 
    Uint32 ctl_dma_config : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_MISC_CPP_CFG10_REG;

/* General CPP config.  0= Do not generate error when First dl DMA word is not sop.  1-Do not generate error when last dl DMA word is not eop.  2=endian control where 0 is big endian. */
#define CSL_DFE_MISC_CPP_CFG10_REG_CTL_DMA_CONFIG_MASK (0x00000007u)
#define CSL_DFE_MISC_CPP_CFG10_REG_CTL_DMA_CONFIG_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG10_REG_CTL_DMA_CONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG10_REG_ADDR (0x00000040u)
#define CSL_DFE_MISC_CPP_CFG10_REG_RESETVAL (0x00000000u)

/* CPP_CFG11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 ctl_dma_start : 1;
    Uint32 ctl_dma_abort : 1;
    Uint32 ctl_dma_process : 5;
#else 
    Uint32 ctl_dma_process : 5;
    Uint32 ctl_dma_abort : 1;
    Uint32 ctl_dma_start : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_MISC_CPP_CFG11_REG;

/* DMA process to start/stop */
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_PROCESS_MASK (0x0000001Fu)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_PROCESS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_PROCESS_RESETVAL (0x00000000u)

/* Control bit to manually stop a DMA process */
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_ABORT_MASK (0x00000020u)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_ABORT_SHIFT (0x00000005u)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_ABORT_RESETVAL (0x00000000u)

/* Control bit to manually start a DMA process */
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_START_MASK (0x00000040u)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_START_SHIFT (0x00000006u)
#define CSL_DFE_MISC_CPP_CFG11_REG_CTL_DMA_START_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG11_REG_ADDR (0x00000044u)
#define CSL_DFE_MISC_CPP_CFG11_REG_RESETVAL (0x00000000u)

/* CPP_CFG12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 ctl_dma_active_status : 32;
#else 
    Uint32 ctl_dma_active_status : 32;
#endif 
} CSL_DFE_MISC_CPP_CFG12_REG;

/* When set each bit indicates the corresponding DMA process is active */
#define CSL_DFE_MISC_CPP_CFG12_REG_CTL_DMA_ACTIVE_STATUS_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_CPP_CFG12_REG_CTL_DMA_ACTIVE_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG12_REG_CTL_DMA_ACTIVE_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG12_REG_ADDR (0x00000048u)
#define CSL_DFE_MISC_CPP_CFG12_REG_RESETVAL (0x00000000u)

/* CPP_CFG13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 ctl_timer14_interval : 24;
#else 
    Uint32 ctl_timer14_interval : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_CPP_CFG13_REG;

/* CPP Timer 14 repetiion interval. */
#define CSL_DFE_MISC_CPP_CFG13_REG_CTL_TIMER14_INTERVAL_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_CPP_CFG13_REG_CTL_TIMER14_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG13_REG_CTL_TIMER14_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG13_REG_ADDR (0x0000004Cu)
#define CSL_DFE_MISC_CPP_CFG13_REG_RESETVAL (0x00000000u)

/* CPP_CFG14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 ctl_timer14_sync_dly : 24;
#else 
    Uint32 ctl_timer14_sync_dly : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_CPP_CFG14_REG;

/* CPP Timer 14 delay from sync to start count */
#define CSL_DFE_MISC_CPP_CFG14_REG_CTL_TIMER14_SYNC_DLY_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_CPP_CFG14_REG_CTL_TIMER14_SYNC_DLY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG14_REG_CTL_TIMER14_SYNC_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG14_REG_ADDR (0x00000050u)
#define CSL_DFE_MISC_CPP_CFG14_REG_RESETVAL (0x00000000u)

/* CPP_CFG15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 ctl_timer14_ssel : 6;
#else 
    Uint32 ctl_timer14_ssel : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_MISC_CPP_CFG15_REG;

/* CPP Timer 14 sync select.  When bit 4 is high alternate syncs are selected. */
#define CSL_DFE_MISC_CPP_CFG15_REG_CTL_TIMER14_SSEL_MASK (0x0000003Fu)
#define CSL_DFE_MISC_CPP_CFG15_REG_CTL_TIMER14_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG15_REG_CTL_TIMER14_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG15_REG_ADDR (0x00000054u)
#define CSL_DFE_MISC_CPP_CFG15_REG_RESETVAL (0x00000000u)

/* CPP_CFG16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 ctl_timer15_interval : 24;
#else 
    Uint32 ctl_timer15_interval : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_CPP_CFG16_REG;

/* CPP Timer 15 repetiion interval. */
#define CSL_DFE_MISC_CPP_CFG16_REG_CTL_TIMER15_INTERVAL_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_CPP_CFG16_REG_CTL_TIMER15_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG16_REG_CTL_TIMER15_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG16_REG_ADDR (0x00000058u)
#define CSL_DFE_MISC_CPP_CFG16_REG_RESETVAL (0x00000000u)

/* CPP_CFG17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 ctl_timer15_sync_dly : 24;
#else 
    Uint32 ctl_timer15_sync_dly : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_CPP_CFG17_REG;

/*  CPP Timer 15 delay from sync to start count */
#define CSL_DFE_MISC_CPP_CFG17_REG_CTL_TIMER15_SYNC_DLY_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_CPP_CFG17_REG_CTL_TIMER15_SYNC_DLY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG17_REG_CTL_TIMER15_SYNC_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG17_REG_ADDR (0x0000005Cu)
#define CSL_DFE_MISC_CPP_CFG17_REG_RESETVAL (0x00000000u)

/* CPP_CFG18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 ctl_timer15_ssel : 6;
#else 
    Uint32 ctl_timer15_ssel : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_MISC_CPP_CFG18_REG;

/* CPP Timer 15 sync select.  When bit 4 is high alternate syncs are selected. */
#define CSL_DFE_MISC_CPP_CFG18_REG_CTL_TIMER15_SSEL_MASK (0x0000003Fu)
#define CSL_DFE_MISC_CPP_CFG18_REG_CTL_TIMER15_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG18_REG_CTL_TIMER15_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG18_REG_ADDR (0x00000060u)
#define CSL_DFE_MISC_CPP_CFG18_REG_RESETVAL (0x00000000u)

/* CPP_CFG19 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cpp_discrete_trigger_en : 8;
#else 
    Uint32 cpp_discrete_trigger_en : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_MISC_CPP_CFG19_REG;

/* Enable the output of the triggers.  They are dma completes to discrete devices */
#define CSL_DFE_MISC_CPP_CFG19_REG_CPP_DISCRETE_TRIGGER_EN_MASK (0x000000FFu)
#define CSL_DFE_MISC_CPP_CFG19_REG_CPP_DISCRETE_TRIGGER_EN_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG19_REG_CPP_DISCRETE_TRIGGER_EN_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG19_REG_ADDR (0x00000064u)
#define CSL_DFE_MISC_CPP_CFG19_REG_RESETVAL (0x00000000u)

/* CPP_CFG20 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 3;
    Uint32 cpp_discrete_trigger_sel3 : 5;
    Uint32 rsvd2 : 3;
    Uint32 cpp_discrete_trigger_sel2 : 5;
    Uint32 rsvd1 : 3;
    Uint32 cpp_discrete_trigger_sel1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cpp_discrete_trigger_sel0 : 5;
#else 
    Uint32 cpp_discrete_trigger_sel0 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cpp_discrete_trigger_sel1 : 5;
    Uint32 rsvd1 : 3;
    Uint32 cpp_discrete_trigger_sel2 : 5;
    Uint32 rsvd2 : 3;
    Uint32 cpp_discrete_trigger_sel3 : 5;
    Uint32 rsvd3 : 3;
#endif 
} CSL_DFE_MISC_CPP_CFG20_REG;

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL0_MASK (0x0000001Fu)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL0_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL1_MASK (0x00001F00u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL1_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL2_MASK (0x001F0000u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL2_SHIFT (0x00000010u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL2_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL3_MASK (0x1F000000u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL3_SHIFT (0x00000018u)
#define CSL_DFE_MISC_CPP_CFG20_REG_CPP_DISCRETE_TRIGGER_SEL3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG20_REG_ADDR (0x00000068u)
#define CSL_DFE_MISC_CPP_CFG20_REG_RESETVAL (0x00000000u)

/* CPP_CFG21 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 3;
    Uint32 cpp_discrete_trigger_sel7 : 5;
    Uint32 rsvd2 : 3;
    Uint32 cpp_discrete_trigger_sel6 : 5;
    Uint32 rsvd1 : 3;
    Uint32 cpp_discrete_trigger_sel5 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cpp_discrete_trigger_sel4 : 5;
#else 
    Uint32 cpp_discrete_trigger_sel4 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cpp_discrete_trigger_sel5 : 5;
    Uint32 rsvd1 : 3;
    Uint32 cpp_discrete_trigger_sel6 : 5;
    Uint32 rsvd2 : 3;
    Uint32 cpp_discrete_trigger_sel7 : 5;
    Uint32 rsvd3 : 3;
#endif 
} CSL_DFE_MISC_CPP_CFG21_REG;

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL4_MASK (0x0000001Fu)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL4_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL4_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL5_MASK (0x00001F00u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL5_SHIFT (0x00000008u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL5_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL6_MASK (0x001F0000u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL6_SHIFT (0x00000010u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL6_RESETVAL (0x00000000u)

/* Select of dma for trigger output */
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL7_MASK (0x1F000000u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL7_SHIFT (0x00000018u)
#define CSL_DFE_MISC_CPP_CFG21_REG_CPP_DISCRETE_TRIGGER_SEL7_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_CFG21_REG_ADDR (0x0000006Cu)
#define CSL_DFE_MISC_CPP_CFG21_REG_RESETVAL (0x00000000u)

/* CPP_DMA */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dma_mode : 2;
    Uint32 dma_ssel : 6;
    Uint32 dma_start_address : 8;
#else 
    Uint32 dma_start_address : 8;
    Uint32 dma_ssel : 6;
    Uint32 dma_mode : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_CPP_DMA_REG;

/* DMA start address pointer into DMA descriptor table (programmed mode) or channel # (embedded address mode). */
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_START_ADDRESS_MASK (0x000000FFu)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_START_ADDRESS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_START_ADDRESS_RESETVAL (0x00000000u)

/* sync to start DMA  When MSB (bit4) set alternate syncs are used if dma_ssel=31 use timer15, dma_ssel=30 use timer14, dma_ssel=29:24 use TBD, dma_ssel=23:16use dl_ctl_data_avail[7:0] */
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_SSEL_MASK (0x00003F00u)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_SSEL_RESETVAL (0x00000000u)

/* Type of DMA the channel is to operate in.  0=disabled, 1= programmed mode, 2=embedded address mode (dl only). */
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_MODE_MASK (0x0000C000u)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_MODE_SHIFT (0x0000000Eu)
#define CSL_DFE_MISC_CPP_DMA_REG_DMA_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_DMA_REG_ADDR (0x00000080u)
#define CSL_DFE_MISC_CPP_DMA_REG_RESETVAL (0x00000000u)

/* CPP_DMA_DESCRIPTOR_MEM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dma_descriptor_rwb : 1;
    Uint32 dma_descriptor_channel_num : 5;
    Uint32 dma_descriptor_mpu_address : 26;
#else 
    Uint32 dma_descriptor_mpu_address : 26;
    Uint32 dma_descriptor_channel_num : 5;
    Uint32 dma_descriptor_rwb : 1;
#endif 
} CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG;

/* Indirect DMA Descriptor memory starting MPU Address (in bytes) */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_MPU_ADDRESS_MASK (0x03FFFFFFu)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_MPU_ADDRESS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_MPU_ADDRESS_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory IQN channel number to use for DMA operation */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_CHANNEL_NUM_MASK (0x7C000000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_CHANNEL_NUM_SHIFT (0x0000001Au)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_CHANNEL_NUM_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory  Direction of DMA.  rwb=0 is downlink from AID to DFE */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_RWB_MASK (0x80000000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_RWB_SHIFT (0x0000001Fu)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_DMA_DESCRIPTOR_RWB_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_ADDR (0x00000400u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM0_REG_RESETVAL (0x00000000u)

/* CPP_DMA_DESCRIPTOR_MEM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dma_descriptor_linklistnext : 8;
    Uint32 dma_descriptor_midpkt : 1;
    Uint32 dma_descriptor_pktsize : 3;
    Uint32 dma_descriptor_incperxfer : 2;
    Uint32 dma_descriptor_bytestoxfer : 2;
    Uint32 dma_descriptor_num_bytes : 16;
#else 
    Uint32 dma_descriptor_num_bytes : 16;
    Uint32 dma_descriptor_bytestoxfer : 2;
    Uint32 dma_descriptor_incperxfer : 2;
    Uint32 dma_descriptor_pktsize : 3;
    Uint32 dma_descriptor_midpkt : 1;
    Uint32 dma_descriptor_linklistnext : 8;
#endif 
} CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG;

/* Indirect DMA Descriptor memory number of bytes to transfer in DMA */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_NUM_BYTES_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_NUM_BYTES_SHIFT (0x00000000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_NUM_BYTES_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory CTL data word increment 0=2bytes, 1=4bytes, 2=8bytes, 3=16bytes */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_BYTESTOXFER_MASK (0x00030000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_BYTESTOXFER_SHIFT (0x00000010u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_BYTESTOXFER_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory MPU address increment 0=2bytes, 1=4bytes, 2=8bytes, 3=16bytes */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_INCPERXFER_MASK (0x000C0000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_INCPERXFER_SHIFT (0x00000012u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_INCPERXFER_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory maximum packet size.  Packet size=2^^(16-pkt_blksize) */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_PKTSIZE_MASK (0x00700000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_PKTSIZE_SHIFT (0x00000014u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_PKTSIZE_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory when set shall prevent the generation of EOP (for >1 DMA/packet) */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_MIDPKT_MASK (0x00800000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_MIDPKT_SHIFT (0x00000017u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_MIDPKT_RESETVAL (0x00000000u)

/* Indirect DMA Descriptor memory address of the next DMA Descriptor in chain of DMA operations.Set to current address for final word */
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_LINKLISTNEXT_MASK (0xFF000000u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_LINKLISTNEXT_SHIFT (0x00000018u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_DMA_DESCRIPTOR_LINKLISTNEXT_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_ADDR (0x00000404u)
#define CSL_DFE_MISC_CPP_DMA_DESCRIPTOR_MEM1_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 arbiter_cfg : 32;
#else 
    Uint32 arbiter_cfg : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB1_REG;

/* Arbiter block general configuration.  0=arbiter enable, 1=32/64 bit access of log memory, 2=when high log memory accessed directly when low read as circular buffer, 3=log overflow mode where low is dump old data and high is freeze, 4: CB-F/CBC shared, 5: enable direct actice antenna table write, 6=CBF Set Back Wanted, 14:8 cpp trigger number of words to dump, 23:16= timestamp resolution in cycles/step, 24: CBC/CBF timers use timer resolution,   25=CBC TDD control 0: interrupt and idle on UL;  1: wait for DL, no interrupt */
#define CSL_DFE_MISC_ARBITER_CFG_ARB1_REG_ARBITER_CFG_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB1_REG_ARBITER_CFG_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB1_REG_ARBITER_CFG_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB1_REG_ADDR (0x00001004u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB1_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 arbiter_cmd : 32;
#else 
    Uint32 arbiter_cmd : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB2_REG;

/* Command to set an Arbiter event. Bits 4:0= cmd, 7:5=Antenna#, 19:8= CB-C mode/options or poly2lut interrupt address  */
#define CSL_DFE_MISC_ARBITER_CFG_ARB2_REG_ARBITER_CMD_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB2_REG_ARBITER_CMD_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB2_REG_ARBITER_CMD_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB2_REG_ADDR (0x00001008u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB2_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 arbiter_cmd_params : 32;
#else 
    Uint32 arbiter_cmd_params : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB3_REG;

/* Command to set an Arbiter event parameters when needed.  CBC Static Capture Request time or poly2lut param2/param1  Note when needed must be loaded before arbiter_cmd. */
#define CSL_DFE_MISC_ARBITER_CFG_ARB3_REG_ARBITER_CMD_PARAMS_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB3_REG_ARBITER_CMD_PARAMS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB3_REG_ARBITER_CMD_PARAMS_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB3_REG_ADDR (0x0000100Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB3_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 arbiter_event_mask : 32;
#else 
    Uint32 arbiter_event_mask : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB4_REG;

/* When corresponding bit is set the event is prevented from being processed by the arbiter note this only works for discrete events and not DSP initiated events. */
#define CSL_DFE_MISC_ARBITER_CFG_ARB4_REG_ARBITER_EVENT_MASK_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB4_REG_ARBITER_EVENT_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB4_REG_ARBITER_EVENT_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB4_REG_ADDR (0x00001010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB4_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 active_antenna_table : 8;
#else 
    Uint32 active_antenna_table : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB5_REG;

/* Table of active antennas */
#define CSL_DFE_MISC_ARBITER_CFG_ARB5_REG_ACTIVE_ANTENNA_TABLE_MASK (0x000000FFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB5_REG_ACTIVE_ANTENNA_TABLE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB5_REG_ACTIVE_ANTENNA_TABLE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB5_REG_ADDR (0x00001014u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB5_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 arbiter_status : 32;
#else 
    Uint32 arbiter_status : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB7_REG;

/* arbiter status.  TBD */
#define CSL_DFE_MISC_ARBITER_CFG_ARB7_REG_ARBITER_STATUS_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB7_REG_ARBITER_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB7_REG_ARBITER_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB7_REG_ADDR (0x0000101Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB7_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 log_timer : 32;
#else 
    Uint32 log_timer : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB8_REG;

/* Log time stamp generator current value */
#define CSL_DFE_MISC_ARBITER_CFG_ARB8_REG_LOG_TIMER_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB8_REG_LOG_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB8_REG_LOG_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB8_REG_ADDR (0x00001020u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB8_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 log_timer_syncmode : 1;
    Uint32 log_timer_ssel : 4;
#else 
    Uint32 log_timer_ssel : 4;
    Uint32 log_timer_syncmode : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB9_REG;

/* Log time stamp generator sync select */
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SSEL_RESETVAL (0x00000000u)

/* Log time stamp generator sync select 0: sync resets whole timer. 1: sync resets only 24LSBs */
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SYNCMODE_MASK (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SYNCMODE_SHIFT (0x00000004u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_LOG_TIMER_SYNCMODE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_ADDR (0x00001024u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB9_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 log_timer_initval : 32;
#else 
    Uint32 log_timer_initval : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB10_REG;

/* Log time stamp generator initial value (primarily for debug). */
#define CSL_DFE_MISC_ARBITER_CFG_ARB10_REG_LOG_TIMER_INITVAL_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB10_REG_LOG_TIMER_INITVAL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB10_REG_LOG_TIMER_INITVAL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB10_REG_ADDR (0x00001028u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB10_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 capture_timer_ssel : 4;
#else 
    Uint32 capture_timer_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB11_REG;

/* Capture timer sync select */
#define CSL_DFE_MISC_ARBITER_CFG_ARB11_REG_CAPTURE_TIMER_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB11_REG_CAPTURE_TIMER_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB11_REG_CAPTURE_TIMER_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB11_REG_ADDR (0x0000102Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB11_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 poly2lut_cmd_timeout : 32;
#else 
    Uint32 poly2lut_cmd_timeout : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB12_REG;

/* Timeout value for response from poly2lut command */
#define CSL_DFE_MISC_ARBITER_CFG_ARB12_REG_POLY2LUT_CMD_TIMEOUT_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB12_REG_POLY2LUT_CMD_TIMEOUT_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB12_REG_POLY2LUT_CMD_TIMEOUT_RESETVAL (0x00000FFFu)

#define CSL_DFE_MISC_ARBITER_CFG_ARB12_REG_ADDR (0x00001030u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB12_REG_RESETVAL (0x00000FFFu)

/* ARBITER_CFG_ARB16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 23;
    Uint32 fb_mux_override : 1;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_override_value : 6;
#else 
    Uint32 fb_mux_override_value : 6;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_override : 1;
    Uint32 rsvd1 : 23;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB16_REG;

/* mpu override value for fb_mux_cntl */
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_VALUE_MASK (0x0000003Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_VALUE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_VALUE_RESETVAL (0x00000000u)

/* When asserted use mpu override value for fb_mux_cntl */
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_MASK (0x00000100u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_SHIFT (0x00000008u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_FB_MUX_OVERRIDE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_ADDR (0x00001040u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB16_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 2;
    Uint32 fb_mux_cntl3 : 6;
    Uint32 rsvd2 : 2;
    Uint32 fb_mux_cntl2 : 6;
    Uint32 rsvd1 : 2;
    Uint32 fb_mux_cntl1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_cntl0 : 6;
#else 
    Uint32 fb_mux_cntl0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_cntl1 : 6;
    Uint32 rsvd1 : 2;
    Uint32 fb_mux_cntl2 : 6;
    Uint32 rsvd2 : 2;
    Uint32 fb_mux_cntl3 : 6;
    Uint32 rsvd3 : 2;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB17_REG;

/* gpio mux control setting for dpd mode antsel0 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL0_MASK (0x0000003Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL0_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel1 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL1_MASK (0x00003F00u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL1_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel2 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL2_MASK (0x003F0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL2_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL2_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel3 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL3_MASK (0x3F000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL3_SHIFT (0x00000018u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_FB_MUX_CNTL3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_ADDR (0x00001044u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB17_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 2;
    Uint32 fb_mux_cntl7 : 6;
    Uint32 rsvd2 : 2;
    Uint32 fb_mux_cntl6 : 6;
    Uint32 rsvd1 : 2;
    Uint32 fb_mux_cntl5 : 6;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_cntl4 : 6;
#else 
    Uint32 fb_mux_cntl4 : 6;
    Uint32 rsvd0 : 2;
    Uint32 fb_mux_cntl5 : 6;
    Uint32 rsvd1 : 2;
    Uint32 fb_mux_cntl6 : 6;
    Uint32 rsvd2 : 2;
    Uint32 fb_mux_cntl7 : 6;
    Uint32 rsvd3 : 2;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB18_REG;

/* gpio mux control setting for dpd mode antsel4 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL4_MASK (0x0000003Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL4_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL4_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel5 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL5_MASK (0x00003F00u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL5_SHIFT (0x00000008u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL5_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel6 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL6_MASK (0x003F0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL6_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL6_RESETVAL (0x00000000u)

/* gpio mux control setting for dpd mode antsel7 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL7_MASK (0x3F000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL7_SHIFT (0x00000018u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_FB_MUX_CNTL7_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_ADDR (0x00001048u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB18_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB19 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 fb_mux_port_free_value : 6;
#else 
    Uint32 fb_mux_port_free_value : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB19_REG;

/* When FB mux is free the gpio shall be set to this value (unless overridden) */
#define CSL_DFE_MISC_ARBITER_CFG_ARB19_REG_FB_MUX_PORT_FREE_VALUE_MASK (0x0000003Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB19_REG_FB_MUX_PORT_FREE_VALUE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB19_REG_FB_MUX_PORT_FREE_VALUE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB19_REG_ADDR (0x0000104Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB19_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB20 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 fbpath_loop_delay_ant1 : 16;
    Uint32 fbpath_loop_delay_ant0 : 16;
#else 
    Uint32 fbpath_loop_delay_ant0 : 16;
    Uint32 fbpath_loop_delay_ant1 : 16;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB20_REG;

/* Loop delay from reference signal to feedback from antenna 0 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT0_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT0_RESETVAL (0x00000000u)

/* Loop delay from reference signal to feedback from antenna 1 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT1_MASK (0xFFFF0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT1_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_FBPATH_LOOP_DELAY_ANT1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_ADDR (0x00001050u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB20_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB21 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 fbpath_loop_delay_ant3 : 16;
    Uint32 fbpath_loop_delay_ant2 : 16;
#else 
    Uint32 fbpath_loop_delay_ant2 : 16;
    Uint32 fbpath_loop_delay_ant3 : 16;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB21_REG;

/* Loop delay from reference signal to feedback from antenna 2 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT2_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT2_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT2_RESETVAL (0x00000000u)

/* Loop delay from reference signal to feedback from antenna 3 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT3_MASK (0xFFFF0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT3_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_FBPATH_LOOP_DELAY_ANT3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_ADDR (0x00001054u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB21_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB22 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 fbpath_loop_delay_ant5 : 16;
    Uint32 fbpath_loop_delay_ant4 : 16;
#else 
    Uint32 fbpath_loop_delay_ant4 : 16;
    Uint32 fbpath_loop_delay_ant5 : 16;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB22_REG;

/* Loop delay from reference signal to feedback from antenna 4 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT4_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT4_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT4_RESETVAL (0x00000000u)

/* Loop delay from reference signal to feedback from antenna 5 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT5_MASK (0xFFFF0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT5_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_FBPATH_LOOP_DELAY_ANT5_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_ADDR (0x00001058u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB22_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB23 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 fbpath_loop_delay_ant7 : 16;
    Uint32 fbpath_loop_delay_ant6 : 16;
#else 
    Uint32 fbpath_loop_delay_ant6 : 16;
    Uint32 fbpath_loop_delay_ant7 : 16;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB23_REG;

/* Loop delay from reference signal to feedback from antenna 6 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT6_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT6_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT6_RESETVAL (0x00000000u)

/* Loop delay from reference signal to feedback from antenna 7 */
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT7_MASK (0xFFFF0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT7_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_FBPATH_LOOP_DELAY_ANT7_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_ADDR (0x0000105Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB23_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB24 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 cbf_capture_duration : 32;
#else 
    Uint32 cbf_capture_duration : 32;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB24_REG;

/* Amount of time for capture buffer to run. */
#define CSL_DFE_MISC_ARBITER_CFG_ARB24_REG_CBF_CAPTURE_DURATION_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB24_REG_CBF_CAPTURE_DURATION_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB24_REG_CBF_CAPTURE_DURATION_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB24_REG_ADDR (0x00001060u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB24_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB26 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pa_map3 : 4;
    Uint32 pa_map2 : 4;
    Uint32 pa_map1 : 4;
    Uint32 pa_map0 : 4;
#else 
    Uint32 pa_map0 : 4;
    Uint32 pa_map1 : 4;
    Uint32 pa_map2 : 4;
    Uint32 pa_map3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB26_REG;

/* txa_stop_dpd_a map to antenna#.  Used to assign pa protection signal to pa event */
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP0_MASK (0x0000000Fu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP0_RESETVAL (0x00000000u)

/* txa_stop_dpd_a map to antenna#.  Used to assign pa protection signal to pa event */
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP1_MASK (0x000000F0u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP1_SHIFT (0x00000004u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP1_RESETVAL (0x00000000u)

/* txa_stop_dpd_a map to antenna#.  Used to assign pa protection signal to pa event */
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP2_MASK (0x00000F00u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP2_SHIFT (0x00000008u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP2_RESETVAL (0x00000000u)

/* txa_stop_dpd_a map to antenna#.  Used to assign pa protection signal to pa event */
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP3_MASK (0x0000F000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP3_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_PA_MAP3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_ADDR (0x00001068u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB26_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB64 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 8;
    Uint32 txtdd_sample_interval : 8;
    Uint32 rsvd1 : 8;
    Uint32 txtdd_ssel : 4;
    Uint32 rsvd0 : 2;
    Uint32 txtdd_oneshot : 1;
    Uint32 txtdd_en : 1;
#else 
    Uint32 txtdd_en : 1;
    Uint32 txtdd_oneshot : 1;
    Uint32 rsvd0 : 2;
    Uint32 txtdd_ssel : 4;
    Uint32 rsvd1 : 8;
    Uint32 txtdd_sample_interval : 8;
    Uint32 rsvd2 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB64_REG;

/* Tx TDD timer enable 0:disabled */
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_EN_MASK (0x00000001u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_EN_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_EN_RESETVAL (0x00000000u)

/* Tx TDD timer oneshot mode */
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_ONESHOT_MASK (0x00000002u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_ONESHOT_SHIFT (0x00000001u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_ONESHOT_RESETVAL (0x00000000u)

/* TX TDD sync select to start operation */
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SSEL_MASK (0x000000F0u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SSEL_RESETVAL (0x00000000u)

/* TX TDD clock interval to count by */
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SAMPLE_INTERVAL_MASK (0x00FF0000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SAMPLE_INTERVAL_SHIFT (0x00000010u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_TXTDD_SAMPLE_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_ADDR (0x00001100u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB64_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB65 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_delayfromsync : 24;
#else 
    Uint32 txtdd_delayfromsync : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB65_REG;

/* TX TDD interval in samples from sync to start of initial subframe minus1. */
#define CSL_DFE_MISC_ARBITER_CFG_ARB65_REG_TXTDD_DELAYFROMSYNC_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB65_REG_TXTDD_DELAYFROMSYNC_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB65_REG_TXTDD_DELAYFROMSYNC_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB65_REG_ADDR (0x00001104u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB65_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB66 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_timer_dl1 : 24;
#else 
    Uint32 txtdd_timer_dl1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB66_REG;

/* Initial downlink duration in samples. From txtdd_delayfromsync time to initial uplink time. */
#define CSL_DFE_MISC_ARBITER_CFG_ARB66_REG_TXTDD_TIMER_DL1_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB66_REG_TXTDD_TIMER_DL1_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB66_REG_TXTDD_TIMER_DL1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB66_REG_ADDR (0x00001108u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB66_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB67 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_timer_ul1 : 24;
#else 
    Uint32 txtdd_timer_ul1 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB67_REG;

/* duration in samples of first Uplink period */
#define CSL_DFE_MISC_ARBITER_CFG_ARB67_REG_TXTDD_TIMER_UL1_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB67_REG_TXTDD_TIMER_UL1_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB67_REG_TXTDD_TIMER_UL1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB67_REG_ADDR (0x0000110Cu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB67_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB68 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_timer_dl2 : 24;
#else 
    Uint32 txtdd_timer_dl2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB68_REG;

/* duration in samples of second Downlink period */
#define CSL_DFE_MISC_ARBITER_CFG_ARB68_REG_TXTDD_TIMER_DL2_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB68_REG_TXTDD_TIMER_DL2_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB68_REG_TXTDD_TIMER_DL2_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB68_REG_ADDR (0x00001110u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB68_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB69 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_timer_ul2 : 24;
#else 
    Uint32 txtdd_timer_ul2 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB69_REG;

/* duration in samples of second Uplink period */
#define CSL_DFE_MISC_ARBITER_CFG_ARB69_REG_TXTDD_TIMER_UL2_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB69_REG_TXTDD_TIMER_UL2_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB69_REG_TXTDD_TIMER_UL2_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB69_REG_ADDR (0x00001114u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB69_REG_RESETVAL (0x00000000u)

/* ARBITER_CFG_ARB70 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 txtdd_timer_dl3 : 24;
#else 
    Uint32 txtdd_timer_dl3 : 24;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_ARBITER_CFG_ARB70_REG;

/* duration in samples of third Downlink period */
#define CSL_DFE_MISC_ARBITER_CFG_ARB70_REG_TXTDD_TIMER_DL3_MASK (0x00FFFFFFu)
#define CSL_DFE_MISC_ARBITER_CFG_ARB70_REG_TXTDD_TIMER_DL3_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB70_REG_TXTDD_TIMER_DL3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_CFG_ARB70_REG_ADDR (0x00001118u)
#define CSL_DFE_MISC_ARBITER_CFG_ARB70_REG_RESETVAL (0x00000000u)

/* ARBITER_LOG_MEM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 log_31_0 : 32;
#else 
    Uint32 log_31_0 : 32;
#endif 
} CSL_DFE_MISC_ARBITER_LOG_MEM0_REG;

/* arbiter log memory */
#define CSL_DFE_MISC_ARBITER_LOG_MEM0_REG_LOG_31_0_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_LOG_MEM0_REG_LOG_31_0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_LOG_MEM0_REG_LOG_31_0_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_LOG_MEM0_REG_ADDR (0x00001400u)
#define CSL_DFE_MISC_ARBITER_LOG_MEM0_REG_RESETVAL (0x00000000u)

/* ARBITER_LOG_MEM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 log_63_32 : 32;
#else 
    Uint32 log_63_32 : 32;
#endif 
} CSL_DFE_MISC_ARBITER_LOG_MEM1_REG;

/* arbiter log memory */
#define CSL_DFE_MISC_ARBITER_LOG_MEM1_REG_LOG_63_32_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_ARBITER_LOG_MEM1_REG_LOG_63_32_SHIFT (0x00000000u)
#define CSL_DFE_MISC_ARBITER_LOG_MEM1_REG_LOG_63_32_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_ARBITER_LOG_MEM1_REG_ADDR (0x00001404u)
#define CSL_DFE_MISC_ARBITER_LOG_MEM1_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_intr_mask : 16;
#else 
    Uint32 sync_intr_mask : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R0_REG;

/* sync bus interrupt mask bits - 1 to enable interrupt, 0 to disable */
#define CSL_DFE_MISC_MISC_INTR_MASK_R0_REG_SYNC_INTR_MASK_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R0_REG_SYNC_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R0_REG_SYNC_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R0_REG_ADDR (0x00002000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R0_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dma_done_intr_mask : 32;
#else 
    Uint32 dma_done_intr_mask : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R1_REG;

/* cpp dma interrupt mask bits - 1 to enable interrupt, 0 to disable */
#define CSL_DFE_MISC_MISC_INTR_MASK_R1_REG_DMA_DONE_INTR_MASK_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R1_REG_DMA_DONE_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R1_REG_DMA_DONE_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R1_REG_ADDR (0x00002004u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R1_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 misc_intr_mask : 32;
#else 
    Uint32 misc_intr_mask : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R2_REG;

/* other misc interrupt mask bits - 1 to enable interrupt, 0 to disable */
#define CSL_DFE_MISC_MISC_INTR_MASK_R2_REG_MISC_INTR_MASK_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R2_REG_MISC_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R2_REG_MISC_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R2_REG_ADDR (0x00002008u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R2_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_intr : 16;
#else 
    Uint32 sync_intr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R3_REG;

/* sync bus captured interrupt bits.  Can only write 0 to clear */
#define CSL_DFE_MISC_MISC_INTR_MASK_R3_REG_SYNC_INTR_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R3_REG_SYNC_INTR_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R3_REG_SYNC_INTR_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R3_REG_ADDR (0x0000200Cu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R3_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dma_done_intr : 32;
#else 
    Uint32 dma_done_intr : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R4_REG;

/* cpp dma captured interrupt bits.  Can only write 0 to clear */
#define CSL_DFE_MISC_MISC_INTR_MASK_R4_REG_DMA_DONE_INTR_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R4_REG_DMA_DONE_INTR_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R4_REG_DMA_DONE_INTR_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R4_REG_ADDR (0x00002010u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R4_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 misc_intr : 32;
#else 
    Uint32 misc_intr : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R5_REG;

/* other misc captured interrupt bits.  Can only write 0 to clear */
#define CSL_DFE_MISC_MISC_INTR_MASK_R5_REG_MISC_INTR_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R5_REG_MISC_INTR_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R5_REG_MISC_INTR_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R5_REG_ADDR (0x00002014u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R5_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_intr_force : 16;
#else 
    Uint32 sync_intr_force : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R6_REG;

/* sync bus force interrupt bits. Set to 1 to force. */
#define CSL_DFE_MISC_MISC_INTR_MASK_R6_REG_SYNC_INTR_FORCE_MASK (0x0000FFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R6_REG_SYNC_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R6_REG_SYNC_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R6_REG_ADDR (0x00002018u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R6_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 dma_done_intr_force : 32;
#else 
    Uint32 dma_done_intr_force : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R7_REG;

/* cpp dma force interrupt bits. Set to 1 to force. */
#define CSL_DFE_MISC_MISC_INTR_MASK_R7_REG_DMA_DONE_INTR_FORCE_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R7_REG_DMA_DONE_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R7_REG_DMA_DONE_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R7_REG_ADDR (0x0000201Cu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R7_REG_RESETVAL (0x00000000u)

/* MISC_INTR_MASK_R8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 misc_intr_force : 32;
#else 
    Uint32 misc_intr_force : 32;
#endif 
} CSL_DFE_MISC_MISC_INTR_MASK_R8_REG;

/* other misc force interrupt bits. Set to 1 to force. */
#define CSL_DFE_MISC_MISC_INTR_MASK_R8_REG_MISC_INTR_FORCE_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_MISC_INTR_MASK_R8_REG_MISC_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R8_REG_MISC_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MISC_INTR_MASK_R8_REG_ADDR (0x00002020u)
#define CSL_DFE_MISC_MISC_INTR_MASK_R8_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_LP_INTR_MASK_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr_mask : 20;
#else 
    Uint32 intr_mask : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG;

/* Master Low Priority interrupt 0 mask bits - 1 to enable interrupt, 0 to disable */
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG_INTR_MASK_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG_ADDR (0x00002100u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R0_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_LP_INTR_MASK_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr : 20;
#else 
    Uint32 intr : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG;

/* Master Low Priority interrupt 0 captured interrupt bits.  Can only write 0 to clear */
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG_INTR_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG_INTR_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG_INTR_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG_ADDR (0x00002104u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R1_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_LP_INTR_MASK_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr_force : 20;
#else 
    Uint32 intr_force : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG;

/* Master Low Priority interrupt 0 forced interrupt bits. */
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG_INTR_FORCE_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG_ADDR (0x00002108u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_LP_INTR_MASK_R2_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_HP_INTR_MASK_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr_mask : 20;
#else 
    Uint32 intr_mask : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG;

/* Master High Priority interrupt 1 mask bits - 1 to enable interrupt, 0 to disable */
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG_INTR_MASK_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG_ADDR (0x00002200u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R0_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_HP_INTR_MASK_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr : 20;
#else 
    Uint32 intr : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG;

/* Master High Priority interrupt 1 captured interrupt bits.  Can only write 0 to clear */
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG_INTR_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG_INTR_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG_INTR_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG_ADDR (0x00002204u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R1_REG_RESETVAL (0x00000000u)

/* MASTER_INT_MASTER_HP_INTR_MASK_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 12;
    Uint32 intr_force : 20;
#else 
    Uint32 intr_force : 20;
    Uint32 rsvd0 : 12;
#endif 
} CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG;

/* Master High Priority interrupt 1 forced interrupt bits. */
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG_INTR_FORCE_MASK (0x000FFFFFu)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG_ADDR (0x00002208u)
#define CSL_DFE_MISC_MASTER_INT_MASTER_HP_INTR_MASK_R2_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 mpu_gpio_read : 18;
#else 
    Uint32 mpu_gpio_read : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG;

/* Value currently on given GPIO pin (regardless of gpio_map setting or even if it is input/output) */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG_MPU_GPIO_READ_MASK (0x0003FFFFu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG_MPU_GPIO_READ_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG_MPU_GPIO_READ_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG_ADDR (0x00002300u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP0_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 14;
    Uint32 mpu_gpio_drive : 18;
#else 
    Uint32 mpu_gpio_drive : 18;
    Uint32 rsvd0 : 14;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG;

/* Value to drive out the gpio pins if the gpio_mux_sel for a bit is set to 27 (0x1b) */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG_MPU_GPIO_DRIVE_MASK (0x0003FFFFu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG_MPU_GPIO_DRIVE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG_MPU_GPIO_DRIVE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG_ADDR (0x00002304u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP1_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 gpio_sync_out_ssel1 : 4;
    Uint32 gpio_sync_out_ssel0 : 4;
#else 
    Uint32 gpio_sync_out_ssel0 : 4;
    Uint32 gpio_sync_out_ssel1 : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG;

/* Select to output sync to gpio pin */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL0_RESETVAL (0x00000000u)

/* Select to output sync to gpio pin */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_GPIO_SYNC_OUT_SSEL1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_ADDR (0x00002308u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP2_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 2;
    Uint32 gpio_mux_sel5 : 5;
    Uint32 gpio_mux_sel4 : 5;
    Uint32 gpio_mux_sel3 : 5;
    Uint32 gpio_mux_sel2 : 5;
    Uint32 gpio_mux_sel1 : 5;
    Uint32 gpio_mux_sel0 : 5;
#else 
    Uint32 gpio_mux_sel0 : 5;
    Uint32 gpio_mux_sel1 : 5;
    Uint32 gpio_mux_sel2 : 5;
    Uint32 gpio_mux_sel3 : 5;
    Uint32 gpio_mux_sel4 : 5;
    Uint32 gpio_mux_sel5 : 5;
    Uint32 rsvd0 : 2;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG;

/* Select for gpio pin 0 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL0_MASK (0x0000001Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL0_RESETVAL (0x00000000u)

/* Select for gpio pin 1 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL1_MASK (0x000003E0u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL1_SHIFT (0x00000005u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL1_RESETVAL (0x00000000u)

/* Select for gpio pin 2 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL2_MASK (0x00007C00u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL2_SHIFT (0x0000000Au)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL2_RESETVAL (0x00000000u)

/* Select for gpio pin 3 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL3_MASK (0x000F8000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL3_SHIFT (0x0000000Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL3_RESETVAL (0x00000000u)

/* Select for gpio pin 4 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL4_MASK (0x01F00000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL4_SHIFT (0x00000014u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL4_RESETVAL (0x00000000u)

/* Select for gpio pin 5 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL5_MASK (0x3E000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL5_SHIFT (0x00000019u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_GPIO_MUX_SEL5_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_ADDR (0x0000230Cu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP3_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 2;
    Uint32 gpio_mux_sel11 : 5;
    Uint32 gpio_mux_sel10 : 5;
    Uint32 gpio_mux_sel9 : 5;
    Uint32 gpio_mux_sel8 : 5;
    Uint32 gpio_mux_sel7 : 5;
    Uint32 gpio_mux_sel6 : 5;
#else 
    Uint32 gpio_mux_sel6 : 5;
    Uint32 gpio_mux_sel7 : 5;
    Uint32 gpio_mux_sel8 : 5;
    Uint32 gpio_mux_sel9 : 5;
    Uint32 gpio_mux_sel10 : 5;
    Uint32 gpio_mux_sel11 : 5;
    Uint32 rsvd0 : 2;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG;

/* Select for gpio pin 6 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL6_MASK (0x0000001Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL6_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL6_RESETVAL (0x00000000u)

/* Select for gpio pin 7 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL7_MASK (0x000003E0u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL7_SHIFT (0x00000005u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL7_RESETVAL (0x00000000u)

/* Select for gpio pin 8 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL8_MASK (0x00007C00u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL8_SHIFT (0x0000000Au)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL8_RESETVAL (0x00000000u)

/* Select for gpio pin 9 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL9_MASK (0x000F8000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL9_SHIFT (0x0000000Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL9_RESETVAL (0x00000000u)

/* Select for gpio pin 10 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL10_MASK (0x01F00000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL10_SHIFT (0x00000014u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL10_RESETVAL (0x00000000u)

/* Select for gpio pin 11 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL11_MASK (0x3E000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL11_SHIFT (0x00000019u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_GPIO_MUX_SEL11_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_ADDR (0x00002310u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP4_REG_RESETVAL (0x00000000u)

/* GPIO_CNTRL_GPIO_MAP5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 2;
    Uint32 gpio_mux_sel17 : 5;
    Uint32 gpio_mux_sel16 : 5;
    Uint32 gpio_mux_sel15 : 5;
    Uint32 gpio_mux_sel14 : 5;
    Uint32 gpio_mux_sel13 : 5;
    Uint32 gpio_mux_sel12 : 5;
#else 
    Uint32 gpio_mux_sel12 : 5;
    Uint32 gpio_mux_sel13 : 5;
    Uint32 gpio_mux_sel14 : 5;
    Uint32 gpio_mux_sel15 : 5;
    Uint32 gpio_mux_sel16 : 5;
    Uint32 gpio_mux_sel17 : 5;
    Uint32 rsvd0 : 2;
#endif 
} CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG;

/* Select for gpio pin 12 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL12_MASK (0x0000001Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL12_SHIFT (0x00000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL12_RESETVAL (0x00000000u)

/* Select for gpio pin 13 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL13_MASK (0x000003E0u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL13_SHIFT (0x00000005u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL13_RESETVAL (0x00000000u)

/* Select for gpio pin 14 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL14_MASK (0x00007C00u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL14_SHIFT (0x0000000Au)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL14_RESETVAL (0x00000000u)

/* Select for gpio pin 15 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL15_MASK (0x000F8000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL15_SHIFT (0x0000000Fu)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL15_RESETVAL (0x00000000u)

/* Select for gpio pin 16 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL16_MASK (0x01F00000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL16_SHIFT (0x00000014u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL16_RESETVAL (0x00000000u)

/* Select for gpio pin 17 */
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL17_MASK (0x3E000000u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL17_SHIFT (0x00000019u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_GPIO_MUX_SEL17_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_ADDR (0x00002314u)
#define CSL_DFE_MISC_GPIO_CNTRL_GPIO_MAP5_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_MPU_SYNC */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 mpu_sync : 1;
#else 
    Uint32 mpu_sync : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG;

/* mpu_sync */
#define CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG_MPU_SYNC_MASK (0x00000001u)
#define CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG_MPU_SYNC_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG_MPU_SYNC_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG_ADDR (0x00002400u)
#define CSL_DFE_MISC_SYNC_GEN_MPU_SYNC_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_ONE_SHOT_CTRL_0_7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 one_shot_ctrl_jesd_sync_in : 4;
    Uint32 one_shot_ctrl_gpio_sync_in1 : 4;
    Uint32 one_shot_ctrl_gpio_sync_in0 : 4;
    Uint32 one_shot_ctrl_dl_iq0_frame_start_sync1 : 4;
    Uint32 one_shot_ctrl_dl_iq0_frame_start_sync0 : 4;
    Uint32 one_shot_ctrl_ul_iq0_frame_strobe_sync1 : 4;
    Uint32 one_shot_ctrl_ul_iq0_frame_strobe_sync0 : 4;
    Uint32 one_shot_ctrl_mpu_sync : 4;
#else 
    Uint32 one_shot_ctrl_mpu_sync : 4;
    Uint32 one_shot_ctrl_ul_iq0_frame_strobe_sync0 : 4;
    Uint32 one_shot_ctrl_ul_iq0_frame_strobe_sync1 : 4;
    Uint32 one_shot_ctrl_dl_iq0_frame_start_sync0 : 4;
    Uint32 one_shot_ctrl_dl_iq0_frame_start_sync1 : 4;
    Uint32 one_shot_ctrl_gpio_sync_in0 : 4;
    Uint32 one_shot_ctrl_gpio_sync_in1 : 4;
    Uint32 one_shot_ctrl_jesd_sync_in : 4;
#endif 
} CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG;

/* 0 = use raw mpu_sync, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_MPU_SYNC_MASK (0x0000000Fu)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_MPU_SYNC_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_MPU_SYNC_RESETVAL (0x00000000u)

/* 0 = use raw ul_iq0_frame_strobe_sync0, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC0_MASK (0x000000F0u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC0_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC0_RESETVAL (0x00000000u)

/* 0 = use raw ul_iq0_frame_strobe_sync1, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC1_MASK (0x00000F00u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_UL_IQ0_FRAME_STROBE_SYNC1_RESETVAL (0x00000000u)

/* 0 = use raw dl_iq0_frame_start_sync0, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC0_MASK (0x0000F000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC0_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC0_RESETVAL (0x00000000u)

/* 0 = use raw dl_iq0_frame_start_sync1, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC1_MASK (0x000F0000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC1_SHIFT (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_DL_IQ0_FRAME_START_SYNC1_RESETVAL (0x00000000u)

/* 0 = use raw gpio_sync_in0, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN0_MASK (0x00F00000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN0_SHIFT (0x00000014u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN0_RESETVAL (0x00000000u)

/* 0 = use raw gpio_sync_in1, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN1_MASK (0x0F000000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN1_SHIFT (0x00000018u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_GPIO_SYNC_IN1_RESETVAL (0x00000000u)

/* 0 = use raw jesd_sync_in, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_JESD_SYNC_IN_MASK (0xF0000000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_JESD_SYNC_IN_SHIFT (0x0000001Cu)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ONE_SHOT_CTRL_JESD_SYNC_IN_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_ADDR (0x00002404u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_0_7_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_ONE_SHOT_CTRL_8_13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 8;
    Uint32 one_shot_ctrl_cntr2 : 4;
    Uint32 one_shot_ctrl_cntr1 : 4;
    Uint32 one_shot_ctrl_cntr0 : 4;
    Uint32 one_shot_ctrl_master_intr1 : 4;
    Uint32 one_shot_ctrl_master_intr0 : 4;
    Uint32 one_shot_ctrl_sysref : 4;
#else 
    Uint32 one_shot_ctrl_sysref : 4;
    Uint32 one_shot_ctrl_master_intr0 : 4;
    Uint32 one_shot_ctrl_master_intr1 : 4;
    Uint32 one_shot_ctrl_cntr0 : 4;
    Uint32 one_shot_ctrl_cntr1 : 4;
    Uint32 one_shot_ctrl_cntr2 : 4;
    Uint32 rsvd0 : 8;
#endif 
} CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG;

/* 0 = use raw sysref, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_SYSREF_MASK (0x0000000Fu)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_SYSREF_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_SYSREF_RESETVAL (0x00000000u)

/* 0 = use raw master_intr0, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR0_MASK (0x000000F0u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR0_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR0_RESETVAL (0x00000000u)

/* 0 = use raw master_intr1, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR1_MASK (0x00000F00u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_MASTER_INTR1_RESETVAL (0x00000000u)

/* 0 = use raw cntr_sync0, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR0_MASK (0x0000F000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR0_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR0_RESETVAL (0x00000000u)

/* 0 = use raw cntr_sync1, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR1_MASK (0x000F0000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR1_SHIFT (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR1_RESETVAL (0x00000000u)

/* 0 = use raw cntr_sync2, n = use one-shot with length n clock cycles */
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR2_MASK (0x00F00000u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR2_SHIFT (0x00000014u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ONE_SHOT_CTRL_CNTR2_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_ADDR (0x00002408u)
#define CSL_DFE_MISC_SYNC_GEN_ONE_SHOT_CTRL_8_13_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_IQ0_SYNC_CH_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 1;
    Uint32 dl_iq0_frame_start_sync1_ch : 7;
    Uint32 rsvd3 : 1;
    Uint32 dl_iq0_frame_start_sync0_ch : 7;
    Uint32 rsvd2 : 7;
    Uint32 jesd_sync_in_mux : 1;
    Uint32 rsvd1 : 1;
    Uint32 ul_iq0_frame_strobe_sync1_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 ul_iq0_frame_strobe_sync0_sel : 3;
#else 
    Uint32 ul_iq0_frame_strobe_sync0_sel : 3;
    Uint32 rsvd0 : 1;
    Uint32 ul_iq0_frame_strobe_sync1_sel : 3;
    Uint32 rsvd1 : 1;
    Uint32 jesd_sync_in_mux : 1;
    Uint32 rsvd2 : 7;
    Uint32 dl_iq0_frame_start_sync0_ch : 7;
    Uint32 rsvd3 : 1;
    Uint32 dl_iq0_frame_start_sync1_ch : 7;
    Uint32 rsvd4 : 1;
#endif 
} CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG;

/* select which bit of ul_iq0_frame_strobe to use as ul_iq0_frame_strobe_sync0 */
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC0_SEL_MASK (0x00000007u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC0_SEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC0_SEL_RESETVAL (0x00000000u)

/* select which bit of ul_iq0_frame_strobe to use as ul_iq0_frame_strobe_sync1 */
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC1_SEL_MASK (0x00000070u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC1_SEL_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_UL_IQ0_FRAME_STROBE_SYNC1_SEL_RESETVAL (0x00000000u)

/* select which jesd_sync_in to put on sync bus */
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_JESD_SYNC_IN_MUX_MASK (0x00000100u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_JESD_SYNC_IN_MUX_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_JESD_SYNC_IN_MUX_RESETVAL (0x00000000u)

/* dl_iq0_frame_start_sync0 is only registered when dl_iq0_ch equals this value */
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC0_CH_MASK (0x007F0000u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC0_CH_SHIFT (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC0_CH_RESETVAL (0x00000000u)

/* dl_iq0_frame_start_sync1 is only registered when dl_iq0_ch equals this value */
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC1_CH_MASK (0x7F000000u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC1_CH_SHIFT (0x00000018u)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_DL_IQ0_FRAME_START_SYNC1_CH_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_ADDR (0x0000240Cu)
#define CSL_DFE_MISC_SYNC_GEN_IQ0_SYNC_CH_SEL_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 16;
    Uint32 sync_cntr0_ssel_update_ssel : 4;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr0_invert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr0_rpt : 1;
    Uint32 sync_cntr0_sync_sel : 4;
#else 
    Uint32 sync_cntr0_sync_sel : 4;
    Uint32 sync_cntr0_rpt : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr0_invert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr0_ssel_update_ssel : 4;
    Uint32 rsvd2 : 16;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG;

/* sync counter 0 sync select; sync counter does NOT start until a sync is sent.  This is a shadow register, updated by sync_cntr0_ssel_update_ssel. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SYNC_SEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SYNC_SEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SYNC_SEL_RESETVAL (0x00000000u)

/* sync counter 0 repeat */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_RPT_MASK (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_RPT_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_RPT_RESETVAL (0x00000000u)

/* sync counter 0 invert */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_INVERT_MASK (0x00000100u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_INVERT_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_INVERT_RESETVAL (0x00000000u)

/* This sync does NOT start the counter. This sync updates sync_cntr0_sync_sel (which is the real sync to start the counter) from shadow to active. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SSEL_UPDATE_SSEL_MASK (0x0000F000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SSEL_UPDATE_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_SYNC_CNTR0_SSEL_UPDATE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_ADDR (0x00002414u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_CTRL_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr0_period : 32;
#else 
    Uint32 sync_cntr0_period : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG;

/* sync counter 0 period (set to X for period of X clocks; 0 resets sync counter) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG_SYNC_CNTR0_PERIOD_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG_SYNC_CNTR0_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG_SYNC_CNTR0_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG_ADDR (0x00002418u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PERIOD_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr0_delay : 32;
#else 
    Uint32 sync_cntr0_delay : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG;

/* sync counter 0 delay (if set to 0, sync counter output will be high if sync select source is high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG_SYNC_CNTR0_DELAY_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG_SYNC_CNTR0_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG_SYNC_CNTR0_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG_ADDR (0x0000241Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_DELAY_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr0_pulse : 32;
#else 
    Uint32 sync_cntr0_pulse : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG;

/* sync counter 0 pulse (set to X for pulse width of X clocks; 0 means it will never go high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG_SYNC_CNTR0_PULSE_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG_SYNC_CNTR0_PULSE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG_SYNC_CNTR0_PULSE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG_ADDR (0x00002420u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR0_SYNC_GEN_CNTR0_PULSE_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 16;
    Uint32 sync_cntr1_ssel_update_ssel : 4;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr1_invert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr1_rpt : 1;
    Uint32 sync_cntr1_sync_sel : 4;
#else 
    Uint32 sync_cntr1_sync_sel : 4;
    Uint32 sync_cntr1_rpt : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr1_invert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr1_ssel_update_ssel : 4;
    Uint32 rsvd2 : 16;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG;

/* sync counter 1 sync select; sync counter does NOT start until a sync is sent. This is a shadow register, updated by sync_cntr1_ssel_update_ssel. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SYNC_SEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SYNC_SEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SYNC_SEL_RESETVAL (0x00000000u)

/* sync counter 1 repeat */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_RPT_MASK (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_RPT_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_RPT_RESETVAL (0x00000000u)

/* sync counter 1 invert */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_INVERT_MASK (0x00000100u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_INVERT_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_INVERT_RESETVAL (0x00000000u)

/* This sync does NOT start the counter. This sync updates sync_cntr1_sync_sel (which is the real sync to start the counter) from shadow to active. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SSEL_UPDATE_SSEL_MASK (0x0000F000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SSEL_UPDATE_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_SYNC_CNTR1_SSEL_UPDATE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_ADDR (0x00002424u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_CTRL_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr1_period : 32;
#else 
    Uint32 sync_cntr1_period : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG;

/* sync counter 1 period (set to X for period of X clocks; 0 resets sync counter) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG_SYNC_CNTR1_PERIOD_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG_SYNC_CNTR1_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG_SYNC_CNTR1_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG_ADDR (0x00002428u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PERIOD_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr1_delay : 32;
#else 
    Uint32 sync_cntr1_delay : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG;

/* sync counter 1 delay (if set to 0, sync counter output will be high if sync select source is high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG_SYNC_CNTR1_DELAY_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG_SYNC_CNTR1_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG_SYNC_CNTR1_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG_ADDR (0x0000242Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_DELAY_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr1_pulse : 32;
#else 
    Uint32 sync_cntr1_pulse : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG;

/* sync counter 1 pulse (set to X for pulse width of X clocks; 0 means it will never go high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG_SYNC_CNTR1_PULSE_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG_SYNC_CNTR1_PULSE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG_SYNC_CNTR1_PULSE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG_ADDR (0x00002430u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR1_SYNC_GEN_CNTR1_PULSE_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 16;
    Uint32 sync_cntr2_ssel_update_ssel : 4;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr2_invert : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr2_rpt : 1;
    Uint32 sync_cntr2_sync_sel : 4;
#else 
    Uint32 sync_cntr2_sync_sel : 4;
    Uint32 sync_cntr2_rpt : 1;
    Uint32 rsvd0 : 3;
    Uint32 sync_cntr2_invert : 1;
    Uint32 rsvd1 : 3;
    Uint32 sync_cntr2_ssel_update_ssel : 4;
    Uint32 rsvd2 : 16;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG;

/* sync counter 2 sync select; sync counter does NOT start until a sync is sent. This is a shadow register, updated by sync_cntr1_ssel_update_ssel. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SYNC_SEL_MASK (0x0000000Fu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SYNC_SEL_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SYNC_SEL_RESETVAL (0x00000000u)

/* sync counter 2 repeat */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_RPT_MASK (0x00000010u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_RPT_SHIFT (0x00000004u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_RPT_RESETVAL (0x00000000u)

/* sync counter 2 invert */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_INVERT_MASK (0x00000100u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_INVERT_SHIFT (0x00000008u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_INVERT_RESETVAL (0x00000000u)

/* This sync does NOT start the counter. This sync updates sync_cntr2_sync_sel (which is the real sync to start the counter) from shadow to active. */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SSEL_UPDATE_SSEL_MASK (0x0000F000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SSEL_UPDATE_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_SYNC_CNTR2_SSEL_UPDATE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_ADDR (0x00002434u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_CTRL_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr2_period : 32;
#else 
    Uint32 sync_cntr2_period : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG;

/* sync counter 2 period (set to X for period of X clocks; 0 resets sync counter */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG_SYNC_CNTR2_PERIOD_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG_SYNC_CNTR2_PERIOD_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG_SYNC_CNTR2_PERIOD_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG_ADDR (0x00002438u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PERIOD_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr2_delay : 32;
#else 
    Uint32 sync_cntr2_delay : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG;

/* sync counter 2 delay (if set to 0, sync counter output will be high if sync select source is high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG_SYNC_CNTR2_DELAY_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG_SYNC_CNTR2_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG_SYNC_CNTR2_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG_ADDR (0x0000243Cu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_DELAY_REG_RESETVAL (0x00000000u)

/* SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 sync_cntr2_pulse : 32;
#else 
    Uint32 sync_cntr2_pulse : 32;
#endif 
} CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG;

/* sync counter 2 pulse (set to X for pulse width of X clocks; 0 means it will never go high) */
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG_SYNC_CNTR2_PULSE_MASK (0xFFFFFFFFu)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG_SYNC_CNTR2_PULSE_SHIFT (0x00000000u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG_SYNC_CNTR2_PULSE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG_ADDR (0x00002440u)
#define CSL_DFE_MISC_SYNC_GEN_CNTR2_SYNC_GEN_CNTR2_PULSE_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 27;
    Uint32 dvga_mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 dvga_en : 1;
#else 
    Uint32 dvga_en : 1;
    Uint32 rsvd0 : 3;
    Uint32 dvga_mode : 1;
    Uint32 rsvd1 : 27;
#endif 
} CSL_DFE_MISC_DVGA_DVGA0_REG;

/* 0 = off (zero outputs), 1 = enabled */
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_EN_MASK (0x00000001u)
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_EN_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_EN_RESETVAL (0x00000000u)

/* 0 = transparent mode (no latch enable signals), 1 = clocked mode */
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_MODE_MASK (0x00000010u)
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_MODE_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA0_REG_DVGA_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA0_REG_ADDR (0x00002500u)
#define CSL_DFE_MISC_DVGA_DVGA0_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 dvga_tr_mode_str_sel3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 dvga_tr_mode_str_sel2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 dvga_tr_mode_str_sel1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 dvga_tr_mode_str_sel0 : 2;
#else 
    Uint32 dvga_tr_mode_str_sel0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 dvga_tr_mode_str_sel1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 dvga_tr_mode_str_sel2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 dvga_tr_mode_str_sel3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_MISC_DVGA_DVGA1_REG;

/* transparent mode bit 0 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL0_MASK (0x00000003u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL0_RESETVAL (0x00000000u)

/* transparent mode bit 1 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL1_MASK (0x00000030u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL1_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL1_RESETVAL (0x00000000u)

/* transparent mode bit 2 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL2_MASK (0x00000300u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL2_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL2_RESETVAL (0x00000000u)

/* transparent mode bit 3 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL3_MASK (0x00003000u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_DVGA_TR_MODE_STR_SEL3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA1_REG_ADDR (0x00002504u)
#define CSL_DFE_MISC_DVGA_DVGA1_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 dvga_tr_mode_str_sel7 : 2;
    Uint32 rsvd2 : 2;
    Uint32 dvga_tr_mode_str_sel6 : 2;
    Uint32 rsvd1 : 2;
    Uint32 dvga_tr_mode_str_sel5 : 2;
    Uint32 rsvd0 : 2;
    Uint32 dvga_tr_mode_str_sel4 : 2;
#else 
    Uint32 dvga_tr_mode_str_sel4 : 2;
    Uint32 rsvd0 : 2;
    Uint32 dvga_tr_mode_str_sel5 : 2;
    Uint32 rsvd1 : 2;
    Uint32 dvga_tr_mode_str_sel6 : 2;
    Uint32 rsvd2 : 2;
    Uint32 dvga_tr_mode_str_sel7 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_MISC_DVGA_DVGA2_REG;

/* transparent mode bit 4 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL4_MASK (0x00000003u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL4_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL4_RESETVAL (0x00000000u)

/* transparent mode bit 5 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL5_MASK (0x00000030u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL5_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL5_RESETVAL (0x00000000u)

/* transparent mode bit 6 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL6_MASK (0x00000300u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL6_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL6_RESETVAL (0x00000000u)

/* transparent mode bit 7 stream select (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL7_MASK (0x00003000u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL7_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_DVGA_TR_MODE_STR_SEL7_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA2_REG_ADDR (0x00002508u)
#define CSL_DFE_MISC_DVGA_DVGA2_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 dvga_tr_mode_bit_sel3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 dvga_tr_mode_bit_sel2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 dvga_tr_mode_bit_sel1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 dvga_tr_mode_bit_sel0 : 3;
#else 
    Uint32 dvga_tr_mode_bit_sel0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 dvga_tr_mode_bit_sel1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 dvga_tr_mode_bit_sel2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 dvga_tr_mode_bit_sel3 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_MISC_DVGA_DVGA3_REG;

/* transparent mode bit 0 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL0_MASK (0x00000007u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL0_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL0_RESETVAL (0x00000000u)

/* transparent mode bit 1 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL1_MASK (0x00000070u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL1_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL1_RESETVAL (0x00000000u)

/* transparent mode bit 2 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL2_MASK (0x00000700u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL2_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL2_RESETVAL (0x00000000u)

/* transparent mode bit 3 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL3_MASK (0x00007000u)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_DVGA_TR_MODE_BIT_SEL3_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA3_REG_ADDR (0x0000250Cu)
#define CSL_DFE_MISC_DVGA_DVGA3_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 dvga_tr_mode_bit_sel7 : 3;
    Uint32 rsvd2 : 1;
    Uint32 dvga_tr_mode_bit_sel6 : 3;
    Uint32 rsvd1 : 1;
    Uint32 dvga_tr_mode_bit_sel5 : 3;
    Uint32 rsvd0 : 1;
    Uint32 dvga_tr_mode_bit_sel4 : 3;
#else 
    Uint32 dvga_tr_mode_bit_sel4 : 3;
    Uint32 rsvd0 : 1;
    Uint32 dvga_tr_mode_bit_sel5 : 3;
    Uint32 rsvd1 : 1;
    Uint32 dvga_tr_mode_bit_sel6 : 3;
    Uint32 rsvd2 : 1;
    Uint32 dvga_tr_mode_bit_sel7 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_MISC_DVGA_DVGA4_REG;

/* transparent mode bit 4 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL4_MASK (0x00000007u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL4_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL4_RESETVAL (0x00000000u)

/* transparent mode bit 5 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL5_MASK (0x00000070u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL5_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL5_RESETVAL (0x00000000u)

/* transparent mode bit 6 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL6_MASK (0x00000700u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL6_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL6_RESETVAL (0x00000000u)

/* transparent mode bit 7 bit select (0-7) */
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL7_MASK (0x00007000u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL7_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_DVGA_TR_MODE_BIT_SEL7_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA4_REG_ADDR (0x00002510u)
#define CSL_DFE_MISC_DVGA_DVGA4_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 dvga_num_strs_m1 : 2;
#else 
    Uint32 dvga_num_strs_m1 : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_MISC_DVGA_DVGA5_REG;

/* clocked mode - number of streams minus 1 (0-3) */
#define CSL_DFE_MISC_DVGA_DVGA5_REG_DVGA_NUM_STRS_M1_MASK (0x00000003u)
#define CSL_DFE_MISC_DVGA_DVGA5_REG_DVGA_NUM_STRS_M1_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA5_REG_DVGA_NUM_STRS_M1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA5_REG_ADDR (0x00002514u)
#define CSL_DFE_MISC_DVGA_DVGA5_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 19;
    Uint32 dvga_le3_polarity : 1;
    Uint32 rsvd2 : 3;
    Uint32 dvga_le2_polarity : 1;
    Uint32 rsvd1 : 3;
    Uint32 dvga_le1_polarity : 1;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le0_polarity : 1;
#else 
    Uint32 dvga_le0_polarity : 1;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le1_polarity : 1;
    Uint32 rsvd1 : 3;
    Uint32 dvga_le2_polarity : 1;
    Uint32 rsvd2 : 3;
    Uint32 dvga_le3_polarity : 1;
    Uint32 rsvd3 : 19;
#endif 
} CSL_DFE_MISC_DVGA_DVGA6_REG;

/* clocked mode - latch enable 0 polarity - 0 = positive pulse, 1 = negative pulse */
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE0_POLARITY_MASK (0x00000001u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE0_POLARITY_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE0_POLARITY_RESETVAL (0x00000000u)

/* clocked mode - latch enable 1 polarity - 0 = positive pulse, 1 = negative pulse */
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE1_POLARITY_MASK (0x00000010u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE1_POLARITY_SHIFT (0x00000004u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE1_POLARITY_RESETVAL (0x00000000u)

/* clocked mode - latch enable 2 polarity - 0 = positive pulse, 1 = negative pulse */
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE2_POLARITY_MASK (0x00000100u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE2_POLARITY_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE2_POLARITY_RESETVAL (0x00000000u)

/* clocked mode - latch enable 3 polarity - 0 = positive pulse, 1 = negative pulse */
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE3_POLARITY_MASK (0x00001000u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE3_POLARITY_SHIFT (0x0000000Cu)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_DVGA_LE3_POLARITY_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA6_REG_ADDR (0x00002518u)
#define CSL_DFE_MISC_DVGA_DVGA6_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 dvga_le1_width_m1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le0_width_m1 : 5;
#else 
    Uint32 dvga_le0_width_m1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le1_width_m1 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_MISC_DVGA_DVGA7_REG;

/* clocked mode - latch enable 0 pulse width (clock cycles minus 1) */
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE0_WIDTH_M1_MASK (0x0000001Fu)
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE0_WIDTH_M1_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE0_WIDTH_M1_RESETVAL (0x00000000u)

/* clocked mode - latch enable 1 pulse width (clock cycles minus 1) */
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE1_WIDTH_M1_MASK (0x00001F00u)
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE1_WIDTH_M1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA7_REG_DVGA_LE1_WIDTH_M1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA7_REG_ADDR (0x0000251Cu)
#define CSL_DFE_MISC_DVGA_DVGA7_REG_RESETVAL (0x00000000u)

/* DVGA_DVGA8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 dvga_le3_width_m1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le2_width_m1 : 5;
#else 
    Uint32 dvga_le2_width_m1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 dvga_le3_width_m1 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_MISC_DVGA_DVGA8_REG;

/* clocked mode - latch enable 2 pulse width (clock cycles minus 1) */
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE2_WIDTH_M1_MASK (0x0000001Fu)
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE2_WIDTH_M1_SHIFT (0x00000000u)
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE2_WIDTH_M1_RESETVAL (0x00000000u)

/* clocked mode - latch enable 3 pulse width (clock cycles minus 1) */
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE3_WIDTH_M1_MASK (0x00001F00u)
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE3_WIDTH_M1_SHIFT (0x00000008u)
#define CSL_DFE_MISC_DVGA_DVGA8_REG_DVGA_LE3_WIDTH_M1_RESETVAL (0x00000000u)

#define CSL_DFE_MISC_DVGA_DVGA8_REG_ADDR (0x00002520u)
#define CSL_DFE_MISC_DVGA_DVGA8_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_MISC_H__ */
