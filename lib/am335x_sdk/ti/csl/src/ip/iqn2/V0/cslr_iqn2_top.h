/*
 *
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
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

/********************************************************************
* file: cslr_iqn2_top.h
*
* Brief: This file contains the Register Description for iqn2_top
*
*********************************************************************/
#ifndef CSLR_IQN2_TOP_H_
#define CSLR_IQN2_TOP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for vc_sys_sts_cfg
\**************************************************************************/
typedef struct  {
    volatile Uint32 IQN2_VC_PID_STS; /* IQN2 Periperal ID Register */
    volatile Uint32 VC_SCRATCH; /* VC Scratch Register */
    volatile Uint32 VC_SW_RESET_STB; /* VC Software Reset Register */
    volatile Uint32 VC_EMU_CFG; /* IQN2 Emulation Control Register */
    volatile Uint8 RSVD0[4];
    volatile Uint32 VC_DTMUX_CFG; /* Iqn2 data trace mux select Register */
    volatile Uint32 VC_CLKCTL_SYSCLK_SEL_CFG; /* VC clkctl system clock control Register */
} CSL_Iqn2_topVc_sys_sts_cfgRegs; /* VC System Status and Control registers */

/**************************************************************************\
* Register Overlay Structure for vc_cdma_status
\**************************************************************************/
typedef struct  {
    volatile Uint32 VC_CDMA_TSTAT_L_TDOWN_STS; /* PKTDMA TX takedown status lsb Register */
    volatile Uint32 VC_CDMA_TSTAT_H_TDOWN_STS; /* PKTDMA TX takedown status msb Register */
    volatile Uint32 VC_CDMA_TSTAT_L_ENABLE_STS; /* PKTDMA TX enable status lsb Register */
    volatile Uint32 VC_CDMA_TSTAT_H_ENABLE_STS; /* PKTDMA TX enable status msb Register */
    volatile Uint32 VC_CDMA_TSTAT_L_PKT_STS; /* PKTDMA TX packet status lsb Register */
    volatile Uint32 VC_CDMA_TSTAT_H_PKT_STS; /* PKTDMA TX packet status msb Register */
    volatile Uint32 VC_CDMA_RSTAT_L_TDOWN_STS; /* PKTDMA RX takedown status lsb Register */
    volatile Uint32 VC_CDMA_RSTAT_H_TDOWN_STS; /* PKTDMA RX takedown status msb Register */
    volatile Uint32 VC_CDMA_RSTAT_L_ENABLE_STS; /* PKTDMA RX enable status lsb Register */
    volatile Uint32 VC_CDMA_RSTAT_H_ENABLE_STS; /* PKTDMA RX enable status msb Register */
    volatile Uint32 VC_CDMA_RSTAT_L_PKT_STS; /* PKTDMA RX packet status lsb Register */
    volatile Uint32 VC_CDMA_RSTAT_H_PKT_STS; /* PKTDMA RX packet status msb Register */
} CSL_Iqn2_topVc_cdma_statusRegs; /* VC PKTDMA Status registers */

/**************************************************************************\
* Register Overlay Structure for vc_subchip_pid_sts
\**************************************************************************/
typedef struct  {
    volatile Uint32 CLKCTL_VC_PID_STS; /* iqn2 clock control subchip Periperal ID Register */
    volatile Uint32 AIL_VC_PID_STS; /* iqn2 ail subchip Periperal ID Register */
} CSL_Iqn2_topVc_subchip_pid_stsRegs; /* VC subchip PID Status registers */

/**************************************************************************\
* Register Overlay Structure for vc_sd_lk
\**************************************************************************/
typedef struct  {
    volatile Uint32 VC_SD_TX_STS; /* SERDES transmit status Register */
    volatile Uint8 RSVD0[8];
    volatile Uint32 VC_SD_RX_STS; /* (TI Diag Use Only) SERDES receive status Register. User should read SERDES registers directly */
} CSL_Iqn2_topVc_sd_lkRegs; /* VC SERDES link status registers */

/**************************************************************************\
* Register Overlay Structure for IQN2 Top level EE registers
\**************************************************************************/
typedef struct  {
    volatile Uint32 EE_EV0_ORGN_STS; /* EE EV0 Origination Status Register */
    volatile Uint32 EE_EV1_ORGN_STS; /* EE EV1 Origination Status Register */
    volatile Uint8 RSVD0[8];
    volatile Uint32 EE_EOI_0_REG; /* EOI EV 0 Register */
    volatile Uint32 EE_EOI_1_REG; /* EOI EV 1 Register */
    volatile Uint32 EE_EOI_CPPI_REG; /* EOI EV Multicore Navigator Register */
} CSL_Iqn2_topIqn2; /* IQN2 Top level EE registers */

/**************************************************************************\
* Register Overlay Structure for PSR_CONFIG_REGS
\**************************************************************************/
typedef struct  {
    volatile Uint32 PSR_EGR_CFG; /* Selects the setting of the amount of bandwidth limit for flushing packets */
    volatile Uint32 PSR_ING_CFG; /* Controls extraction of PS_DATA from the ingress path */
    volatile Uint8 RSVD0[504];
    volatile Uint32 PSR_ING_CHAN_CFG[48]; /* Selects if forces the channel into continuous flush and if it drops packets on error. */
    volatile Uint8 RSVD1[320];
    volatile Uint32 PSR_EGR_CHAN_CFG[48]; /* Enables packing PS data for the channel. Sets the arbitration priority for the channel. */
} CSL_Iqn2_topPsr_config_regsRegs; /* PSR Configuration MMRs */

/**************************************************************************\
* Register Overlay Structure for PSR_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 ING_FLUSH_A_RAW_STS; /* Ingress flush errors for register ing_flush_a with channels 0 through 31. */
    volatile Uint32 ING_FLUSH_A_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 ING_FLUSH_A_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 ING_FLUSH_A_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 ING_FLUSH_A_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 ING_FLUSH_A_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 ING_FLUSH_A_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 ING_FLUSH_A_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 ING_FLUSH_A_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 ING_FLUSH_A_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 ING_FLUSH_A_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 ING_FLUSH_B_RAW_STS; /* Ingress flush errors for reguster ing_flush_b with channels 32 through 47. */
    volatile Uint32 ING_FLUSH_B_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 ING_FLUSH_B_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 ING_FLUSH_B_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 ING_FLUSH_B_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 ING_FLUSH_B_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 ING_FLUSH_B_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 ING_FLUSH_B_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 ING_FLUSH_B_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 ING_FLUSH_B_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 ING_FLUSH_B_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint8 RSVD0[88];
    volatile Uint32 EGR_PROTOCOL_ERR_A_RAW_STS; /* Egress protocol errors for register egr_protocol_err_a with channels 0 through 31. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 EGR_PROTOCOL_ERR_A_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_RAW_STS; /* Egress protocol errors for register egr_protocol_err_b with channels 32 through 47. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 EGR_PROTOCOL_ERR_B_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint8 RSVD1[88];
    volatile Uint32 PSR_ORIG_REG; /* This is the origination register indicating which PSR interrupt register group caused the interrupt. */
} CSL_Iqn2_topPsr_eeRegs; /* IQN_PSR_EE EE register group */

/**************************************************************************\
* Register Overlay Structure for PKTDMA_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_DESC_STARVE_RAW_STS; /* PKTDMA SOP and MOP descriptor starvation errors. */
    volatile Uint32 PKTDMA_DESC_STARVE_RAW_SET; /* Raw Set */
    volatile Uint32 PKTDMA_DESC_STARVE_RAW_CLR; /* Raw Clear */
    volatile Uint32 PKTDMA_DESC_STARVE_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 PKTDMA_DESC_STARVE_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 PKTDMA_DESC_STARVE_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 PKTDMA_DESC_STARVE_EV0_ENABLED_STS; /* EV0 Enabled Status */
} CSL_Iqn2_topPktdma_eeRegs; /* IQN_PSR_PKTDMA_EE EE register group */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn2_topVc_sys_sts_cfgRegs VC_SYS_STS_CFG;
    volatile Uint8 RSVD0[4];
    CSL_Iqn2_topVc_cdma_statusRegs VC_CDMA_STATUS;
    volatile Uint8 RSVD1[48];
    CSL_Iqn2_topVc_subchip_pid_stsRegs VC_SUBCHIP_PID_STS;
    volatile Uint8 RSVD2[120];
    CSL_Iqn2_topVc_sd_lkRegs VC_SD_LK[4];
    volatile Uint8 RSVD3[16064];
    CSL_Iqn2_topIqn2 TOP_LEVEL_EE;
    volatile Uint8 RSVD4[16356];
    CSL_Iqn2_topPsr_config_regsRegs PSR_CONFIG_REGS;
    volatile Uint8 RSVD5[832];
    CSL_Iqn2_topPsr_eeRegs PSR_EE;
    volatile Uint8 RSVD6[668];
    CSL_Iqn2_topPktdma_eeRegs PKTDMA_EE;
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD7[29668];
/******************************************/
} CSL_Iqn2_topRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* iqn2_vc_pid_sts */

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MINOR_MASK (0x0000003Fu)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MINOR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MINOR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_CUSTOM_MASK (0x000000C0u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_CUSTOM_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_CUSTOM_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MAJOR_MASK (0x00000700u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MAJOR_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_MAJOR_RESETVAL (0x00000001u)

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_RTL_MASK (0x0000F800u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_RTL_SHIFT (0x0000000Bu)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_RTL_RESETVAL (0x0000000Au)

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_FUNC_MASK (0x0FFF0000u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_FUNC_SHIFT (0x00000010u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_FUNC_RESETVAL (0x00000841u)


#define CSL_IQN2_TOP_IQN2_VC_PID_STS_SCHEME_MASK (0xC0000000u)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_SCHEME_SHIFT (0x0000001Eu)
#define CSL_IQN2_TOP_IQN2_VC_PID_STS_SCHEME_RESETVAL (0x00000001u)

#define CSL_IQN2_TOP_IQN2_VC_PID_STS_RESETVAL (0x48415100u)

/* vc_scratch */

#define CSL_IQN2_TOP_VC_SCRATCH_SCRATCH_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_SCRATCH_SCRATCH_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_SCRATCH_SCRATCH_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SCRATCH_RESETVAL (0x00000000u)

/* vc_sw_reset_stb */

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_MASK (0x00000001u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AID_MASK (0x00000002u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AID_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AID_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_DIO_MASK (0x00000004u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_DIO_SHIFT (0x00000002u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_DIO_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_PKTDMA_MASK (0x00000008u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_PKTDMA_SHIFT (0x00000003u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_PKTDMA_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL0_MASK (0x00000010u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL0_SHIFT (0x00000004u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL0_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL1_MASK (0x00000020u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL1_SHIFT (0x00000005u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL1_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL2_MASK (0x00000040u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL2_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL2_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL3_MASK (0x00000080u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL3_SHIFT (0x00000007u)
#define CSL_IQN2_TOP_VC_SW_RESET_STB_SW_RESET_AIL3_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_SW_RESET_STB_RESETVAL (0x00000000u)

/* vc_emu_cfg */

#define CSL_IQN2_TOP_VC_EMU_CFG_FREERUN_MASK (0x00000001u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FREERUN_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FREERUN_RESETVAL (0x00000000u)
/*----FREERUN Tokens----*/
#define CSL_IQN2_TOP_VC_EMU_CFG_FREERUN_RESPOND (0x00000000u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FREERUN_IGNORE (0x00000001u)

#define CSL_IQN2_TOP_VC_EMU_CFG_SOFT_MASK (0x00000002u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SOFT_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SOFT_RESETVAL (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_IQN2_TOP_VC_EMU_CFG_SOFT_HARD_STOP (0x00000000u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SOFT_SOFT_STOP (0x00000001u)

#define CSL_IQN2_TOP_VC_EMU_CFG_RT_SEL_MASK (0x00000004u)
#define CSL_IQN2_TOP_VC_EMU_CFG_RT_SEL_SHIFT (0x00000002u)
#define CSL_IQN2_TOP_VC_EMU_CFG_RT_SEL_RESETVAL (0x00000000u)
/*----RT_SEL Tokens----*/
#define CSL_IQN2_TOP_VC_EMU_CFG_RT_SEL_EMU_DBGSUSP (0x00000000u)
#define CSL_IQN2_TOP_VC_EMU_CFG_RT_SEL_EMU_DBGSUSP_RT (0x00000001u)

#define CSL_IQN2_TOP_VC_EMU_CFG_FRC_SHUTDOWN_MASK (0x00000008u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FRC_SHUTDOWN_SHIFT (0x00000003u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FRC_SHUTDOWN_RESETVAL (0x00000000u)
/*----frc_shutdown Tokens----*/
#define CSL_IQN2_TOP_VC_EMU_CFG_FRC_SHUTDOWN_RUN (0x00000000u)
#define CSL_IQN2_TOP_VC_EMU_CFG_FRC_SHUTDOWN_SHUTDOWN (0x00000001u)


#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_ON_MASK (0x00000100u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_ON_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_ON_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_DONE_MASK (0x00000200u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_DONE_SHIFT (0x00000009u)
#define CSL_IQN2_TOP_VC_EMU_CFG_SHUTDOWN_DONE_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_EMU_CFG_RESETVAL (0x00000000u)

/* vc_dtmux_cfg */

#define CSL_IQN2_TOP_VC_DTMUX_CFG_VC_DTMUX_MASK (0x00000003u)
#define CSL_IQN2_TOP_VC_DTMUX_CFG_VC_DTMUX_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_DTMUX_CFG_VC_DTMUX_RESETVAL (0x00000000u)
/*----vc_dtmux Tokens----*/
#define CSL_IQN2_TOP_VC_DTMUX_CFG_VC_DTMUX_AIL0 (0x00000000u)
#define CSL_IQN2_TOP_VC_DTMUX_CFG_VC_DTMUX_AIL1 (0x00000001u)


#define CSL_IQN2_TOP_VC_DTMUX_CFG_RESETVAL (0x00000000u)

/* vc_clkctl_sysclk_sel_cfg */

#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_MASK (0x00000007u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_RESETVAL (0x00000000u)
/*----sysclk_sel Tokens----*/
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_AIL0 (0x00000000u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_AIL1 (0x00000001u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_AIL0_CPRI16X (0x00000004u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_SYSCLK_SEL_AIL1_CPRI16X (0x00000005u)

#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_AT_DFE_CLK_SEL_MASK (0x00000008u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_AT_DFE_CLK_SEL_SHIFT (0x00000003u)
#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_AT_DFE_CLK_SEL_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CLKCTL_SYSCLK_SEL_CFG_RESETVAL (0x00000000u)

/* vc_cdma_tstat_l_tdown_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_TDOWN_STS_TDOWN_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_TDOWN_STS_TDOWN_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_TDOWN_STS_TDOWN_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_TDOWN_STS_RESETVAL (0x00000000u)

/* vc_cdma_tstat_h_tdown_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_TDOWN_STS_TDOWN_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_TDOWN_STS_TDOWN_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_TDOWN_STS_TDOWN_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_TDOWN_STS_RESETVAL (0x00000000u)

/* vc_cdma_tstat_l_enable_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_ENABLE_STS_ENABLE_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_ENABLE_STS_ENABLE_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_ENABLE_STS_ENABLE_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_ENABLE_STS_RESETVAL (0x00000000u)

/* vc_cdma_tstat_h_enable_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_ENABLE_STS_ENABLE_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_ENABLE_STS_ENABLE_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_ENABLE_STS_ENABLE_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_ENABLE_STS_RESETVAL (0x00000000u)

/* vc_cdma_tstat_l_pkt_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_PKT_STS_PKT_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_PKT_STS_PKT_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_PKT_STS_PKT_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_L_PKT_STS_RESETVAL (0x00000000u)

/* vc_cdma_tstat_h_pkt_sts */

#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_PKT_STS_PKT_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_PKT_STS_PKT_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_PKT_STS_PKT_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_TSTAT_H_PKT_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_l_tdown_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_TDOWN_STS_TDOWN_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_TDOWN_STS_TDOWN_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_TDOWN_STS_TDOWN_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_TDOWN_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_h_tdown_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_TDOWN_STS_TDOWN_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_TDOWN_STS_TDOWN_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_TDOWN_STS_TDOWN_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_TDOWN_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_l_enable_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_ENABLE_STS_ENABLE_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_ENABLE_STS_ENABLE_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_ENABLE_STS_ENABLE_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_ENABLE_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_h_enable_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_ENABLE_STS_ENABLE_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_ENABLE_STS_ENABLE_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_ENABLE_STS_ENABLE_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_ENABLE_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_l_pkt_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_PKT_STS_PKT_STATUS_L_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_PKT_STS_PKT_STATUS_L_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_PKT_STS_PKT_STATUS_L_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_L_PKT_STS_RESETVAL (0x00000000u)

/* vc_cdma_rstat_h_pkt_sts */

#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_PKT_STS_PKT_STATUS_H_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_PKT_STS_PKT_STATUS_H_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_PKT_STS_PKT_STATUS_H_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_CDMA_RSTAT_H_PKT_STS_RESETVAL (0x00000000u)

/* clkctl_vc_pid_sts */

#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MINOR_MASK (0x0000003Fu)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MINOR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MINOR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_CUSTOM_MASK (0x000000C0u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_CUSTOM_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_CUSTOM_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MAJOR_MASK (0x00000700u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MAJOR_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_MAJOR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_RTL_MASK (0x0000F800u)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_RTL_SHIFT (0x0000000Bu)
#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_RTL_RESETVAL (0x00000001u)


#define CSL_IQN2_TOP_CLKCTL_VC_PID_STS_RESETVAL (0x00000800u)

/* ail_vc_pid_sts */

#define CSL_IQN2_TOP_AIL_VC_PID_STS_MINOR_MASK (0x0000003Fu)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_MINOR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_MINOR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_AIL_VC_PID_STS_CUSTOM_MASK (0x000000C0u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_CUSTOM_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_CUSTOM_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_AIL_VC_PID_STS_MAJOR_MASK (0x00000700u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_MAJOR_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_MAJOR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_AIL_VC_PID_STS_RTL_MASK (0x0000F800u)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_RTL_SHIFT (0x0000000Bu)
#define CSL_IQN2_TOP_AIL_VC_PID_STS_RTL_RESETVAL (0x00000009u)


#define CSL_IQN2_TOP_AIL_VC_PID_STS_RESETVAL (0x00004800u)

/* vc_sd_tx_sts */

#define CSL_IQN2_TOP_VC_SD_TX_STS_LINKSTATUS_OK_MASK (0x00000001u)
#define CSL_IQN2_TOP_VC_SD_TX_STS_LINKSTATUS_OK_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_SD_TX_STS_LINKSTATUS_OK_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_SD_TX_STS_RESETVAL (0x00000000u)

/* vc_sd_rx_sts */

#define CSL_IQN2_TOP_VC_SD_RX_STS_RXCOMMA_DET_MASK (0x00000001u)
#define CSL_IQN2_TOP_VC_SD_RX_STS_RXCOMMA_DET_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_VC_SD_RX_STS_RXCOMMA_DET_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_VC_SD_RX_STS_RXLOSS_OF_SIGNAL_MASK (0x00000002u)
#define CSL_IQN2_TOP_VC_SD_RX_STS_RXLOSS_OF_SIGNAL_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_VC_SD_RX_STS_RXLOSS_OF_SIGNAL_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_VC_SD_RX_STS_RESETVAL (0x00000000u)

/* ee_ev0_orgn_sts */

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AT_EE_STS_MASK (0x00000001u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AT_EE_STS_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AT_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AID_EE_STS_MASK (0x00000002u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AID_EE_STS_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AID_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DFE_EE_STS_MASK (0x00000004u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DFE_EE_STS_SHIFT (0x00000002u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DFE_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DIO_EE_STS_MASK (0x00000008u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DIO_EE_STS_SHIFT (0x00000003u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_DIO_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_IQS_EE_STS_MASK (0x00000010u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_IQS_EE_STS_SHIFT (0x00000004u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_IQS_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL0_EE_STS_MASK (0x00000020u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL0_EE_STS_SHIFT (0x00000005u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL0_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL1_EE_STS_MASK (0x00000040u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL1_EE_STS_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL1_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL2_EE_EV1_MASK (0x00000080u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL2_EE_EV1_SHIFT (0x00000007u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL2_EE_EV1_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL3_EE_EV1_MASK (0x00000100u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL3_EE_EV1_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_AIL3_EE_EV1_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_PSR_EE_STS_MASK (0x00000200u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_PSR_EE_STS_SHIFT (0x00000009u)
#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_PSR_EE_STS_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EE_EV0_ORGN_STS_RESETVAL (0x00000000u)

/* ee_ev1_orgn_sts */

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AT_EE_STS_MASK (0x00000001u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AT_EE_STS_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AT_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AID_EE_STS_MASK (0x00000002u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AID_EE_STS_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AID_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DFE_EE_STS_MASK (0x00000004u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DFE_EE_STS_SHIFT (0x00000002u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DFE_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DIO_EE_STS_MASK (0x00000008u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DIO_EE_STS_SHIFT (0x00000003u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_DIO_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_IQS_EE_STS_MASK (0x00000010u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_IQS_EE_STS_SHIFT (0x00000004u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_IQS_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL0_EE_STS_MASK (0x00000020u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL0_EE_STS_SHIFT (0x00000005u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL0_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL1_EE_STS_MASK (0x00000040u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL1_EE_STS_SHIFT (0x00000006u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL1_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL2_EE_STS_MASK (0x00000080u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL2_EE_STS_SHIFT (0x00000007u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL2_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL3_EE_STS_MASK (0x00000100u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL3_EE_STS_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_AIL3_EE_STS_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_PSR_EE_STS_MASK (0x00000200u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_PSR_EE_STS_SHIFT (0x00000009u)
#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_PSR_EE_STS_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EE_EV1_ORGN_STS_RESETVAL (0x00000000u)

/* ee_eoi_0_reg */

#define CSL_IQN2_TOP_EE_EOI_0_REG_EOI_0_VECTOR_REG_MASK (0x000000FFu)
#define CSL_IQN2_TOP_EE_EOI_0_REG_EOI_0_VECTOR_REG_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EE_EOI_0_REG_EOI_0_VECTOR_REG_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EE_EOI_0_REG_RESETVAL (0x00000000u)

/* ee_eoi_1_reg */

#define CSL_IQN2_TOP_EE_EOI_1_REG_EOI_1_VECTOR_REG_MASK (0x000000FFu)
#define CSL_IQN2_TOP_EE_EOI_1_REG_EOI_1_VECTOR_REG_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EE_EOI_1_REG_EOI_1_VECTOR_REG_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EE_EOI_1_REG_RESETVAL (0x00000000u)

/* ee_eoi_cppi_reg */

#define CSL_IQN2_TOP_EE_EOI_CPPI_REG_EOI_CPPI_VECTOR_REG_MASK (0x000000FFu)
#define CSL_IQN2_TOP_EE_EOI_CPPI_REG_EOI_CPPI_VECTOR_REG_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EE_EOI_CPPI_REG_EOI_CPPI_VECTOR_REG_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EE_EOI_CPPI_REG_RESETVAL (0x00000000u)

/* psr_egr_cfg */


#define CSL_IQN2_TOP_PSR_EGR_CFG_BW_LIMIT_MASK (0x00000F00u)
#define CSL_IQN2_TOP_PSR_EGR_CFG_BW_LIMIT_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_PSR_EGR_CFG_BW_LIMIT_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PSR_EGR_CFG_RESETVAL (0x00000000u)

/* psr_ing_cfg */

#define CSL_IQN2_TOP_PSR_ING_CFG_PS_DATA_EXT_MASK (0x00000001u)
#define CSL_IQN2_TOP_PSR_ING_CFG_PS_DATA_EXT_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PSR_ING_CFG_PS_DATA_EXT_RESETVAL (0x00000000u)
/*----ps_data_ext Tokens----*/
#define CSL_IQN2_TOP_PSR_ING_CFG_PS_DATA_EXT_ENABLE (0x00000000u)
#define CSL_IQN2_TOP_PSR_ING_CFG_PS_DATA_EXT_DISABLE (0x00000001u)


#define CSL_IQN2_TOP_PSR_ING_CFG_RESETVAL (0x00000000u)

/* psr_ing_chan_cfg */


#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_DROP_PKT_MASK (0x00000002u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_DROP_PKT_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_DROP_PKT_RESETVAL (0x00000000u)
/*----drop_pkt Tokens----*/
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_DROP_PKT_KEEP (0x00000000u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_DROP_PKT_DROP (0x00000001u)

#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_FORCE_FLUSH_MASK (0x00000004u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_FORCE_FLUSH_SHIFT (0x00000002u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_FORCE_FLUSH_RESETVAL (0x00000000u)
/*----force_flush Tokens----*/
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_FORCE_FLUSH_NO_FLUSH (0x00000000u)
#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_FORCE_FLUSH_FLUSH (0x00000001u)


#define CSL_IQN2_TOP_PSR_ING_CHAN_CFG_RESETVAL (0x00000000u)

/* psr_egr_chan_cfg */

#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_PACK_PS_DATA_MASK (0x00000001u)
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_PACK_PS_DATA_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_PACK_PS_DATA_RESETVAL (0x00000000u)
/*----pack_ps_data Tokens----*/
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_PACK_PS_DATA_DO_NOT_PACK (0x00000000u)
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_PACK_PS_DATA_PACK (0x00000001u)


#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_ARB_PRIORITY_MASK (0x00000700u)
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_ARB_PRIORITY_SHIFT (0x00000008u)
#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_ARB_PRIORITY_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PSR_EGR_CHAN_CFG_RESETVAL (0x00000000u)

/* ing_flush_a_raw_sts */

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_STS_RESETVAL (0x00000000u)

/* ing_flush_a_raw_set */

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_SET_RESETVAL (0x00000000u)

/* ing_flush_a_raw_clr */

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_RAW_CLR_RESETVAL (0x00000000u)

/* ing_flush_a_ev0_en_sts */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* ing_flush_a_ev0_en_set */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* ing_flush_a_ev0_en_clr */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ing_flush_a_ev1_en_sts */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* ing_flush_a_ev1_en_set */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* ing_flush_a_ev1_en_clr */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ing_flush_a_ev0_enabled_sts */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_ENABLED_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_ENABLED_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ing_flush_a_ev1_enabled_sts */

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_ENABLED_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_ENABLED_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_ING_FLUSH_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ing_flush_b_raw_sts */

#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_STS_RESETVAL (0x00000000u)

/* ing_flush_b_raw_set */

#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_SET_RESETVAL (0x00000000u)

/* ing_flush_b_raw_clr */

#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_RAW_CLR_RESETVAL (0x00000000u)

/* ing_flush_b_ev0_en_sts */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_STS_RESETVAL (0x00000000u)

/* ing_flush_b_ev0_en_set */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_SET_RESETVAL (0x00000000u)

/* ing_flush_b_ev0_en_clr */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ing_flush_b_ev1_en_sts */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_STS_RESETVAL (0x00000000u)

/* ing_flush_b_ev1_en_set */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_SET_RESETVAL (0x00000000u)

/* ing_flush_b_ev1_en_clr */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ing_flush_b_ev0_enabled_sts */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_ENABLED_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_ENABLED_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ing_flush_b_ev1_enabled_sts */

#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_ENABLED_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_ENABLED_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_ING_FLUSH_B_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_a_raw_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_a_raw_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_a_raw_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_RAW_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev0_en_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev0_en_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev0_en_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev1_en_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev1_en_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_SET_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_SET_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev1_en_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_CLR_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_CLR_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev0_enabled_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_ENABLED_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_ENABLED_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_a_ev1_enabled_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_ENABLED_STS_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_ENABLED_STS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_b_raw_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_b_raw_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_b_raw_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_RAW_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev0_en_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev0_en_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev0_en_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_EN_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev1_en_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev1_en_set */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_SET_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_SET_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_SET_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_SET_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev1_en_clr */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_CLR_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_CLR_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_CLR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_EN_CLR_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev0_enabled_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_ENABLED_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_ENABLED_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* egr_protocol_err_b_ev1_enabled_sts */

#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_ENABLED_STS_ERR_MASK (0x0000FFFFu)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_ENABLED_STS_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_ENABLED_STS_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_EGR_PROTOCOL_ERR_B_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* psr_orig_reg */

#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_A_MASK (0x00000001u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_A_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_A_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_B_MASK (0x00000002u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_B_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_ING_FLUSH_B_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_A_MASK (0x00000010u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_A_SHIFT (0x00000004u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_A_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_B_MASK (0x00000020u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_B_SHIFT (0x00000005u)
#define CSL_IQN2_TOP_PSR_ORIG_REG_EE_EGR_PROTOCOL_ERR_B_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PSR_ORIG_REG_RESETVAL (0x00000000u)

/* pktdma_desc_starve_raw_sts */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_STS_RESETVAL (0x00000000u)

/* pktdma_desc_starve_raw_set */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_SET_RESETVAL (0x00000000u)

/* pktdma_desc_starve_raw_clr */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_RAW_CLR_RESETVAL (0x00000000u)

/* pktdma_desc_starve_ev0_en_sts */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_STS_RESETVAL (0x00000000u)

/* pktdma_desc_starve_ev0_en_set */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_SET_RESETVAL (0x00000000u)

/* pktdma_desc_starve_ev0_en_clr */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_EN_CLR_RESETVAL (0x00000000u)

/* pktdma_desc_starve_ev0_enabled_sts */

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_SOP_ERR_MASK (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_SOP_ERR_SHIFT (0x00000000u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_MOP_ERR_MASK (0x00000002u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_MOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_MOP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN2_TOP_PKTDMA_DESC_STARVE_EV0_ENABLED_STS_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
