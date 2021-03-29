/* parasoft-begin-suppress MISRA2012-RULE-1_1_a_c99-2 "C99 - limits, DRV-4754" parasoft-begin-suppress MISRA2012-RULE-1_1_a_c90-2 "C90 - limits, DRV-4754" */
/* parasoft-begin-suppress item MISRA2012-DIR-4_8 "Consider hiding implementation of structure, DRV-3667" */

/**********************************************************************
* Copyright (C) 2012-2019 Cadence Design Systems, Inc.
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT
*
**********************************************************************/

#ifndef REG_CSITX_REGS_H_
#define REG_CSITX_REGS_H_



typedef struct __attribute__((packed)) CSITX_Regs_s {
    volatile uint32_t device_config;
    volatile uint32_t status;
    volatile uint32_t irq;
    volatile uint32_t irq_mask;
    volatile uint32_t dphy_irq;
    volatile uint32_t dphy_irq_mask;
    volatile char pad__0[0x8U];
    volatile uint32_t tx_conf;
    volatile uint32_t wait_burst_time;
    volatile uint32_t dphy_cfg;
    volatile uint32_t dphy_clk_wakeup;
    volatile uint32_t dphy_ulps_wakeup;
    volatile uint32_t dphy_cfg1;
    volatile uint32_t dphy_status;
    volatile char pad__1[0x4U];
    volatile uint32_t vc0_cfg;
    volatile uint32_t vc1_cfg;
    volatile uint32_t vc2_cfg;
    volatile uint32_t vc3_cfg;
    volatile uint32_t vc4_cfg;
    volatile uint32_t vc5_cfg;
    volatile uint32_t vc6_cfg;
    volatile uint32_t vc7_cfg;
    volatile uint32_t vc8_cfg;
    volatile uint32_t vc9_cfg;
    volatile uint32_t vc10_cfg;
    volatile uint32_t vc11_cfg;
    volatile uint32_t vc12_cfg;
    volatile uint32_t vc13_cfg;
    volatile uint32_t vc14_cfg;
    volatile uint32_t vc15_cfg;
    volatile uint32_t dt0_cfg;
    volatile uint32_t dt0_format;
    volatile uint32_t dt1_cfg;
    volatile uint32_t dt1_format;
    volatile uint32_t dt2_cfg;
    volatile uint32_t dt2_format;
    volatile uint32_t dt3_cfg;
    volatile uint32_t dt3_format;
    volatile uint32_t dt4_cfg;
    volatile uint32_t dt4_format;
    volatile uint32_t dt5_cfg;
    volatile uint32_t dt5_format;
    volatile uint32_t dt6_cfg;
    volatile uint32_t dt6_format;
    volatile uint32_t dt7_cfg;
    volatile uint32_t dt7_format;
    volatile uint32_t dt8_cfg;
    volatile uint32_t dt8_format;
    volatile uint32_t dt9_cfg;
    volatile uint32_t dt9_format;
    volatile uint32_t dt10_cfg;
    volatile uint32_t dt10_format;
    volatile uint32_t dt11_cfg;
    volatile uint32_t dt11_format;
    volatile uint32_t dt12_cfg;
    volatile uint32_t dt12_format;
    volatile uint32_t dt13_cfg;
    volatile uint32_t dt13_format;
    volatile uint32_t dt14_cfg;
    volatile uint32_t dt14_format;
    volatile uint32_t dt15_cfg;
    volatile uint32_t dt15_format;
    volatile uint32_t stream_if_0_cfg;
    volatile uint32_t stream_if_1_cfg;
    volatile uint32_t stream_if_2_cfg;
    volatile uint32_t stream_if_3_cfg;
    volatile char pad__2[0xF0U];
    volatile uint32_t epd_en_ssp;
    volatile uint32_t epd_op_slp;
    volatile uint32_t epd_clkidlehs_min;
    volatile char pad__3[0xAF4U];
    volatile uint32_t debug_cfg;
    volatile uint32_t debug_ln_fsm;
    volatile uint32_t debug_clk_ln_fsm;
    volatile uint32_t debug_data_ln_fsm;
    volatile uint32_t debug_prot0_fsm;
    volatile uint32_t debug_prot1_fsm;
    volatile uint32_t debug_prot2_fsm;
    volatile uint32_t debug_prot3_fsm;
    volatile char pad__4[0xD8U];
    volatile uint32_t test_generic_status;
    volatile uint32_t test_generic_ctrl;
    volatile uint32_t asf_int_status;
    volatile uint32_t asf_int_raw_status;
    volatile uint32_t asf_int_mask;
    volatile uint32_t asf_int_test;
    volatile uint32_t asf_fatal_nonfatal_select;
    volatile char pad__5[0xCU];
    volatile uint32_t asf_sram_corr_fault_status;
    volatile uint32_t asf_sram_uncorr_fault_status;
    volatile uint32_t asf_sram_fault_stats;
    volatile char pad__6[0x4U];
    volatile uint32_t asf_trans_to_ctrl;
    volatile uint32_t asf_trans_to_fault_mask;
    volatile uint32_t asf_trans_to_fault_status;
    volatile char pad__7[0x4U];
    volatile uint32_t asf_protocol_fault_mask;
    volatile uint32_t asf_protocol_fault_status;
    volatile char pad__8[0x1B4U];
    volatile uint32_t id_prod_ver;
} CSITX_Regs;

#endif /* REG_CSITX_REGS_H_ */

/* parasoft-end-suppress MISRA2012-RULE-1_1_a_c99-2 "C99 - limits, DRV-4754" */
/* parasoft-end-suppress MISRA2012-RULE-1_1_a_c90-2 "C90 - limits, DRV-4754" */
/* parasoft-end-suppress MISRA2012-DIR-4_8 "Consider hiding implementation of structure, DRV-3667" */
