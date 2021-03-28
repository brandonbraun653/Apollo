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
* file: cslr_iqn_ail.h
*
* Brief: This file contains the Register Description for iqn_ail
*
*********************************************************************/
#ifndef CSLR_IQN_AIL_H_
#define CSLR_IQN_AIL_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_EFE_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_EFE_CHAN_CFG[64]; /* IFE DMA Channel Configuration Register */
    volatile Uint8 RSVD0[256];
    volatile Uint32 AIL_IQ_EFE_CFG; /* EFE Rx to Tx Loopback Configuration Register */
    volatile Uint8 RSVD1[60];
    volatile Uint32 AIL_IQ_EFE_GLOBAL_EN_SET_STB; /* Set Global Enable for EFE */
    volatile Uint32 AIL_IQ_EFE_GLOBAL_EN_CLR_STB; /* Clear Global Enable for EFE */
    volatile Uint32 AIL_IQ_EFE_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, EFE may still be closing out packets. */
    volatile Uint8 RSVD2[20];
    volatile Uint32 AIL_IQ_EFE_CHAN_ON_STS[2]; /* Gives current On/Off Status of every available AxC stream. One bit per channel (bit0:ch0 ~ bit31:ch31). Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD3[24];
    volatile Uint32 AIL_IQ_EFE_IN_PKT_STS[2]; /* Gives current In/Out packet state of packet channels only. Bits are always zero for AxC channels. Bit is activated at SOP, holds high mid packet, deactivates at EOP. Not used for DIO SI */
    volatile Uint8 RSVD4[24];
    volatile Uint32 AIL_IQ_EFE_DMA_SYNC_STS[2]; /* Gives current DMA SYNC state of AxC channels only. Bits are always zero for OBSAI control channels. Bit is activated when symbol 0 (non-TDD configuation) or first TDD-ON symbol (TDD configuration) of a frame is read from the Residual Buffer and the channel is in the CHAN_ON state. Bit is deactivated on the next SYM/SLOT boundary when channel is disabled or EFE is shutdown. Bit is deactivated immediately when the channel experiences starvation or a protocol error. */
} CSL_Iqn_ailAil_si_iq_efe_config_groupRegs; /* Group containing EFE Channel Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_EFE_RADIO_STANDARD_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_EFE_FRM_TC_CFG[8]; /* EFE Frame Count Register. There are 8 sets of these values in order to support 6 simultaneous radio standard variants */
    volatile Uint32 AIL_IQ_EFE_RAD_STD_CFG[8]; /* EFE Radio Standard Configuration Register */
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG0[5]; /* Per symbol enables for TDD operation for Radio Standard 0. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD0[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG1[5]; /* Per symbol enables for TDD operation for Radio Standard 1. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD1[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG2[5]; /* Per symbol enables for TDD operation for Radio Standard 2. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD2[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG3[5]; /* Per symbol enables for TDD operation for Radio Standard 3. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD3[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG4[5]; /* Per symbol enables for TDD operation for Radio Standard 4. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD4[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG5[5]; /* Per symbol enables for TDD operation for Radio Standard 5. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD5[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG6[5]; /* Per symbol enables for TDD operation for Radio Standard 6. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD6[12];
    volatile Uint32 AIL_IQ_EFE_TDD_EN_CFG7[5]; /* Per symbol enables for TDD operation for Radio Standard 7. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
} CSL_Iqn_ailAil_si_iq_efe_radio_standard_groupRegs; /* Group of registers containing EFE configuration which is radio standard specific. Eight radio standards are supported, individual AxC channels are each assigned to one of these. */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_EFE_CHAN_AXC_OFFSET
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_EFE_CHAN_AXC_OFFSET_CFG; /* Sets the AXC offset for each channel. */
} CSL_Iqn_ailAil_iq_efe_chan_axc_offsetRegs; /* Group containing IQ_EFE_CHAN_AXC_OFFSET RAM */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_EFE_FRM_SAMP_TC_MMR_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_EFE_FRM_SAMP_TC_CFG; /* EFE AxC Radio Framing Sample Terminal Count Configuration Register */
} CSL_Iqn_ailAil_iq_efe_frm_samp_tc_mmr_ramRegs; /* Group containing Egress Sample Terminal Count Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_TDM_LUT_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_TDM_LUT_CFG; /* TDM AxC LUT. 
CPRI: Used to map steams of CPRI containers to appropriate AxC.  AxC are listed in TDM order within each group (radio standard). Different portions of LUT allocated to different groups (radio standards).  
OBSAI: AxC are listed in TDM order per OBSAI DBMR.  Different portions of LUT are allocated to different DBMR. */
} CSL_Iqn_ailAil_si_iq_e_tdm_lut_ramRegs; /* iq_pe_tdm_lut_cfg RAM */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_SCH_PHY
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_PHY_CFG; /* PE PHY enable Register */
    volatile Uint32 AIL_IQ_PE_PHY_STS; /* PE PHY status Register */
} CSL_Iqn_ailAil_si_iq_e_sch_phyRegs; /* iqn_si_e_ail Group containing PHY specific control and status registers */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_OBSAI_MODTXRULE
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_OBSAI_MODTXRULE_CFG[32]; /* PE Modulo Terminal Count Register */
} CSL_Iqn_ailAil_si_iq_e_obsai_modtxruleRegs; /* iqn_si_e_ail Group containing OBSAI Modulo TX Rule specific control registers */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_OBSAI_DBM_RULE_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_OBSAI_DBM_0_CFG; /* PE OBSAI DBMF Register. OBSAI DBM counts through quad-samples (16 bytes per AxC) */
    volatile Uint32 AIL_IQ_PE_OBSAI_DBM_1_CFG; /* PE OBSAI DBMF Register. OBSAI DBM counts through quad-samples (16 bytes per AxC) */
} CSL_Iqn_ailAil_si_iq_e_obsai_dbm_rule_ramRegs; /* iqn_si_e_ail Group containing OBSAI Dual Bit Map Rule specific control registers */

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_OBSAI_DBM_BITMAP_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_OBSAI_DBM_CFG; /* PE DBMF Bit Map 1 & 2 Register, eight locations for each of 32 different rules (3 address LSBs address 0-7 entries per each of 64 rules) (bit_2==0: bit map1 bit_2==1: bit map2. 000:map1(31:0) 001:map1(63:32) 010:map1(95:64) 011:map1(127:96) 100:map2(31:0) 101:map2(63:32) 110:map2(95:64) 111:unused */
} CSL_Iqn_ailAil_si_iq_e_obsai_dbm_bitmap_ramRegs;

/**************************************************************************\
* Register Overlay Structure for AIL_SI_IQ_E_SCH_CPRI
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_PE_CPRI_CFG; /* PE CPRI container terminal count register */
    volatile Uint8 RSVD0[28];
    volatile Uint32 AIL_IQ_PE_CPRI_BUB_FSM_CFG[8]; /* One-to-one mapping to each radio standard, CPRI Mapping Method 3, Bubble insertion state machine control for total of 8 separate FSMs, one per 8 groups/radio_standards */
    volatile Uint32 AIL_IQ_PE_CPRI_BUB_FSM2_CFG[8]; /* One-to-one mapping to each radio standard, CPRI Mapping Method 3, Bubble insertion state machine control for total of 8 separate FSMs, one per 8 groups/radio_standards. If there are any bubbles present, bub_gap indicates space between bubbles. Program BUB_GAP_INT .GE. KNC for no bubbles */
    volatile Uint32 AIL_IQ_PE_CPRI_TDM_FSM_CFG[8]; /* One-to-one mapping to each radio standard, CPRI AxC TDM. Intended use is one TDM FSM per radio standard (matching AIL_PHY_CI groups) */
    volatile Uint32 AIL_IQ_PE_CPRI_RADSTD_CFG[8]; /* Enables each individual radio standard for the PD for up to 8 radio standards */
    volatile Uint32 AIL_IQ_PE_CPRI_RADSTD1_CFG[8]; /* Defines the Radio Standard level Offset per radio standard. Relative to the PHY SOF. In units of basic frames and hyperframes. */
    volatile Uint32 AIL_IQ_PE_CPRI_RADSTD2_CFG[8]; /* Defines the number of Basic Frames per radio standard frame. i.e. 38,400 (set 38,399) for LTE & WCDMA */
    volatile Uint32 AIL_IQ_PE_CPRI_RADSTD_STS[8]; /* Read Only status of each radio status reflecting enable and satisfying basic frame offset */
    volatile Uint32 AIL_IQ_PE_CPRI_CONT_CFG[64]; /* PE CPRI PHY Container LUT: Maps CPRI containers within a basic frame to 1 of 8 groups (radio standard). LUT replays each basic frame. Only CPRI16x can use full 64 depth of LUT */
} CSL_Iqn_ailAil_si_iq_e_sch_cpriRegs; /* iqn_si_e_ail Group containing CPRI specific control registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IFE_CHANNEL_CONFIGURATION_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IFE_CHAN_CFG[64]; /* IFE DMA Channel Configuration Register */
} CSL_Iqn_ailAil_iq_ife_channel_configuration_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IFE_RADIO_STANDARD_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IFE_FRM_TC_CFG[8]; /* IFE Frame Count Register. There are 8 sets of these values in order to support 6 simultaneous radio standard variants */
    volatile Uint32 AIL_IQ_IFE_RAD_STD_CFG[8]; /* IFE Radio Standard Configuration Register */
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG0[5]; /* Per symbol enables for TDD operation for Radio Standard 0. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD0[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG1[5]; /* Per symbol enables for TDD operation for Radio Standard 1. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD1[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG2[5]; /* Per symbol enables for TDD operation for Radio Standard 2. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD2[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG3[5]; /* Per symbol enables for TDD operation for Radio Standard 3. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD3[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG4[5]; /* Per symbol enables for TDD operation for Radio Standard 4. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD4[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG5[5]; /* Per symbol enables for TDD operation for Radio Standard 5. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD5[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG6[5]; /* Per symbol enables for TDD operation for Radio Standard 6. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD6[12];
    volatile Uint32 AIL_IQ_IFE_TDD_EN_CFG7[5]; /* Per symbol enables for TDD operation for Radio Standard 7. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
} CSL_Iqn_ailAil_iq_ife_radio_standard_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IFE_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IFE_GLOBAL_EN_SET_STB; /* Set Global Enable for IFE */
    volatile Uint32 AIL_IQ_IFE_GLOBAL_EN_CLR_STB; /* Clear Global Enable for IFE */
    volatile Uint32 AIL_IQ_IFE_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, IFE may still be closing out packets. */
    volatile Uint8 RSVD0[4];
    volatile Uint32 AIL_IQ_IFE_CHAN_ON_STS[2]; /* Gives current On/Off Status of every available AxC stream. One bit per channel. Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD1[8];
    volatile Uint32 AIL_IQ_IFE_IN_PKT_STS[2]; /* Gives current In/Out packet state of packet channels only. Bits are always zero for AxC channels. Bit is activated at SOP, holds high mid packet, deactivates at EOP. */
} CSL_Iqn_ailAil_iq_ife_config_groupRegs; /* Group containing IFE Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IDC_GENERAL_STATUS_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IDC_STS; /* IDC Status register. */
    volatile Uint8 RSVD0[8];
    volatile Uint32 AIL_IQ_IDC_INPKT_STS[2]; /* Indicates when a channel is actively receiving a packet from the IFE */
} CSL_Iqn_ailAil_iq_idc_general_status_groupRegs; /* Group containing IDC Status registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IDC_CONFIGURATION_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IDC_CFG; /* IDC Configuration Register */
} CSL_Iqn_ailAil_iq_idc_configuration_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_IDC_CHANNEL_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IDC_CH_CFG[64]; /* IDC Channel configuration registers. */
} CSL_Iqn_ailAil_iq_idc_channel_config_groupRegs; /* Group containing IDC Channel Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IFE_FRM_SAMP_TC_MMR_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IFE_FRM_SAMP_TC_CFG; /* IFE AxC Framing Sample Terminal Count Configuration Register */
} CSL_Iqn_ailAil_ife_frm_samp_tc_mmr_ramRegs; /* Group containing Sample Terminal Count Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_ECTL_PKT_IF
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_ECTL_GLOBAL_EN_SET_STB; /* Set Global Enable for ECTL */
    volatile Uint32 AIL_ECTL_GLOBAL_EN_CLR_STB; /* Clear Global Enable for ECTL */
    volatile Uint32 AIL_ECTL_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, ECTL may still be closing out packets. */
    volatile Uint8 RSVD0[244];
    volatile Uint32 AIL_ECTL_CHAN_ON_STS; /* Gives current On/Off Status of every available CPRI control stream. One bit per channel. Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD1[60];
    volatile Uint32 AIL_ECTL_INPKT_STS; /* Indicates when a channel is actively receiving a packet from the ECTL */
    volatile Uint8 RSVD2[188];
    volatile Uint32 AIL_ECTL_CHAN_CFG[4]; /* ECTL Channel Configuration Enable Register */
    volatile Uint8 RSVD3[496];
    volatile Uint32 AIL_ECTL_DB_THOLD_CFG[4]; /* ECTL Database Threshold Register */
} CSL_Iqn_ailAil_ectl_pkt_ifRegs; /* Group containing ECTL Configuration and Status Registers in the VBUS_CLK domain */

/**************************************************************************\
* Register Overlay Structure for AIL_ICTL_IDC_IF
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_ICTL_CH_CFG[4]; /* Per-channel configuration registers. */
    volatile Uint8 RSVD0[496];
    volatile Uint32 AIL_ICTL_CFG; /* ICTL Configuration Register */
    volatile Uint32 AIL_ICTL_STS; /* ICTL Status register. */
    volatile Uint8 RSVD1[8];
    volatile Uint32 AIL_ICTL_INPKT_STS; /* Indicates when a channel is actively receiving a packet from the ICTL */
} CSL_Iqn_ailAil_ictl_idc_ifRegs; /* Group containing ICTL IDC Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_ICTL_PKT_IF
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_ICTL_GLOBAL_EN_SET_STB; /* Set Global Enable for ICTL */
    volatile Uint32 AIL_ICTL_GLOBAL_EN_CLR_STB; /* Clear Global Enable for ICTL */
    volatile Uint32 AIL_ICTL_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, ICTL may still be closing out packets. */
    volatile Uint8 RSVD0[20];
    volatile Uint32 AIL_ICTL_CHAN_ON_STS; /* Gives current On/Off Status of every available stream. One bit per channel. Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD1[348];
    volatile Uint32 AIL_ICTL_CHAN_EN_CFG[4]; /* ICTL Channel Configuration Enable Register */
} CSL_Iqn_ailAil_ictl_pkt_ifRegs; /* Group containing ICTL Packet Interface Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_UAT_GEN_CTL
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_UAT_CFG; /* This register simply starts the uAT timers running. It is implied that SW is unable to precisely time the start of timers. The intent is for the SW to correct the timers by later writting to the offset register of each timer. */
    volatile Uint32 AIL_UAT_BCN_TC_CFG; /* UAT BCN terminal count Register */
    volatile Uint32 AIL_UAT_BCN_OFFSET_CFG; /* UAT BCN offset Register */
    volatile Uint32 AIL_UAT_SYNC_BCN_CAPTURE_STS; /* UAT SYNC BCN capture Register */
} CSL_Iqn_ailAil_uat_gen_ctlRegs; /* Run bit for all uAT timers and BCN registers */

/**************************************************************************\
* Register Overlay Structure for AIL_UAT_AIL_REGS
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_UAT_PI_BCN_CAPTURE_STS; /* UAT pi BCN capture Register */
    volatile Uint32 AIL_UAT_PIMAX_CFG; /* AT AIL pi max register */
    volatile Uint32 AIL_UAT_PIMIN_CFG; /* AT AIL pi min register */
    volatile Uint32 AIL_UAT_RP301_BCN_CAPTURE_STS; /* UAT rp3-01 BCN capture Register */
    volatile Uint32 AIL_UAT_TM_BFN_CFG; /* UAT TM Frame Count (BFN) configuration  */
    volatile Uint32 AIL_UAT_TM_BFN_STS; /* UAT TM Frame status */
    volatile Uint32 AIL_UAT_RT_FB_CFG; /* UAT RT frame boundary compare Register */
    volatile Uint32 AIL_UAT_PE_FB_CFG; /* UAT pe frame boundary compare Register */
    volatile Uint32 AIL_UAT_TM_FB_CFG; /* UAT tm frame boundary (Delta) compare Register */
} CSL_Iqn_ailAil_uat_ail_regsRegs; /* BCN related Registers which are for AIL use only. (not used for DIO or AID2) */

/**************************************************************************\
* Register Overlay Structure for AIL_UAT_EGR_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_UAT_EGR_RADT_TC_CFG; /* UAT RADT terminal count Register */
    volatile Uint32 AIL_UAT_EGR_RADT_OFFSET_CFG; /* UAT RADT offset Register */
    volatile Uint32 AIL_UAT_EGR_SYNC_RADT_CAPTURE_STS; /* UAT SYNC RADT capture Register */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_ailAil_uat_egr_radtRegs; /* Egress RADT registers */

/**************************************************************************\
* Register Overlay Structure for AIL_UAT_ING_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_UAT_ING_RADT_TC_CFG; /* UAT RADT terminal count Register */
    volatile Uint32 AIL_UAT_ING_RADT_OFFSET_CFG; /* UAT RADT offset Register */
    volatile Uint32 AIL_UAT_ING_SYNC_RADT_CAPTURE_STS; /* UAT SYNC RADT capture Register */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_ailAil_uat_ing_radtRegs; /* Ingress RADT registers */

/**************************************************************************\
* Register Overlay Structure for AIL_UAT_RADT_EVT
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_UAT_EVT_RADT_CMP_CFG; /* UAT RADT event compare Register per RADT. The 0 to 7 are for si egress, 8 to 15 for si ingress, 16 to 18 for dio egress, 19 to 21 for dio ingress */
    volatile Uint32 AIL_UAT_EVT_CLK_CNT_TC_CFG; /* UAT RADT event clock counter terminal count Register per RADT */
} CSL_Iqn_ailAil_uat_radt_evtRegs; /* (Unused for AIL) RADT event compare registers for Frame strobe and iteration strobe counter config for 4sample Iteration strobe. The 0 to 7 are for si egress, 8 to 15 for si ingress, 16 to 18 for dio egress, 19 to 21 for dio ingress */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_EDC_REGISTER_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_EDC_CFG; /* EDC Configuration Register */
    volatile Uint32 AIL_IQ_EDC_SOP_CNTR_STS; /* Counts the number of SOPs seen by the IQ EDC */
    volatile Uint32 AIL_IQ_EDC_EOP_CNTR_STS; /* Counts the number of EOPs seen by the IQ EDC */
    volatile Uint8 RSVD0[116];
    volatile Uint32 AIL_IQ_EDC_OCC_CNTR_STS[16]; /* EDC Status Occupancy counter for each channel register. User can ignore this (TI debug only)  */
    volatile Uint8 RSVD1[320];
    volatile Uint32 AIL_IQ_EDC_CH_CFG[64]; /* Per-channel configuration registers. */
} CSL_Iqn_ailAil_iq_edc_register_groupRegs; /* Group containing EDC Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQ_INGRESS_VBUS_MMR_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_IQ_IDC_RATE_CTL_CFG; /* IDC Rate Control Configuration register. Programmable rate control for OBSAI control word and generic packet mode */
    volatile Uint32 AIL_IQ_IDC_SOP_CNTR_STS; /* This register provides a count of the Ingress SOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
    volatile Uint32 AIL_IQ_IDC_EOP_CNTR_STS; /* This register provides a count of the Ingress EOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
} CSL_Iqn_ailAil_iq_ingress_vbus_mmr_groupRegs; /* Group containing VBUS Ingress IQ MMR registers */

/**************************************************************************\
* Register Overlay Structure for AIL_ECTL_REGISTER_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_ECTL_RATE_CTL_CFG; /* ECTL Rate Control Configuration register. Programmable rate control for Rate Controller. */
    volatile Uint32 AIL_ECTL_SOP_CNTR_STS; /* Counts the number of SOPs seen by the ECTL */
    volatile Uint32 AIL_ECTL_EOP_CNTR_STS; /* Counts the number of EOPs seen by the ECTL */
    volatile Uint8 RSVD0[244];
    volatile Uint32 AIL_ECTL_OCC_CNTR_STS; /* ECTL Status Occupancy counter for each channel register. User can ignore this (TI debug only) */
    volatile Uint8 RSVD1[252];
    volatile Uint32 AIL_ECTL_CH_CFG[4]; /* ECTL Per-channel configuration registers. */
} CSL_Iqn_ailAil_ectl_register_groupRegs; /* Group containing ECTL Configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_CTL_INGRESS_VBUS_MMR_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_ICTL_RATE_CTL_CFG; /* ICTL Rate Control Configuration register. Programmable rate control for Rate Controller. */
    volatile Uint32 AIL_ICTL_SOP_CNTR_STS; /* This register provides a count of the Ingress SOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
    volatile Uint32 AIL_ICTL_EOP_CNTR_STS; /* This register provides a count of the Ingress EOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
} CSL_Iqn_ailAil_ctl_ingress_vbus_mmr_groupRegs; /* Group containing VBUS Ingress CTL MMR registers */

/**************************************************************************\
* Register Overlay Structure for AIL_PE_COMMON
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PE_GLOBAL_CFG; /* AIL PE Global Register  */
    volatile Uint8 RSVD0[252];
    volatile Uint32 AIL_PE_CHAN_CFG[64]; /* Channel-by-Channel control. OBSAI: 64 generic AxC or control channels CPRI: 64 AxC Channels, 4 CPRI control channels are configured elsewhere. For CPRI, only RT_CTL field is used */
} CSL_Iqn_ailAil_pe_commonRegs; /* Group containing IQN_AIL_PE GLOBAL & AxC & OBSAI_Pkt configuration registers which are used for both OBSAI and CPRI operating modes */

/**************************************************************************\
* Register Overlay Structure for AIL_PE_OBSAI_HEADER_LUT
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PE_OBSAI_HDR_CFG; /* OBSAI chan-by-chan, control of OBSAI header creation */
} CSL_Iqn_ailAil_pe_obsai_header_lutRegs; /* Group containing IQN_AIL_PE OBSAI_Pkt LUT, a RAM based set of MMRs which control the OBSAI header for each channel. */

/**************************************************************************\
* Register Overlay Structure for AIL_PE_CPRI_CW
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PE_CPRI_CW_CHAN_CFG[4]; /* PE CPRI, Primary register for configuring CPRI Control words. Contains primary selection of dilineation type plus many fields which are common. One MMR per each of four channels */
    volatile Uint32 AIL_PE_CPRI_HYPFRM0_LUT_CFG; /* PE CPRI Hyperframe Enable Part0, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels (Hyper frame 0 ~ 31) */
    volatile Uint32 AIL_PE_CPRI_HYPFRM1_LUT_CFG; /* PE CPRI Hyperframe Enable Part1, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels (Hyper frame 32 ~ 63) */
    volatile Uint32 AIL_PE_CPRI_HYPFRM2_LUT_CFG; /* PE CPRI Hyperframe Enable Part2, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels (Hyper frame 64 ~ 95) */
    volatile Uint32 AIL_PE_CPRI_HYPFRM3_LUT_CFG; /* PE CPRI Hyperframe Enable Part3, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels (Hyper frame 96 ~ 127) */
    volatile Uint32 AIL_PE_CPRI_HYPFRM4_LUT_CFG; /* PE CPRI Hyperframe Enable Part4, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels (Hyper frame 128 ~ 149) */
    volatile Uint32 AIL_PE_CPRI_NULL_CFG; /* PE CPRI NULL delineator register */
    volatile Uint32 AIL_PE_CPRI_CRC_CFG; /* PE CPRI CRC8 control register */
    volatile Uint32 AIL_PE_CPRI_STS; /* channel-by-channel packet status. When shutting down a link, it is good practice for APP SW to wait until all channels are out of packet */
    volatile Uint32 AIL_PE_CPRI_4B5B_CFG[4]; /* PE CPRI fast ethernet control register */
    volatile Uint8 RSVD0[960];
    volatile Uint32 AIL_PE_CPRI_CW_LUT_CFG[256]; /* CPRI CW Channel Register, one register location for each of 256 possible CPRI CW per Hyperframe. Maps the CW to one of four control flows, or unallocated BW */
} CSL_Iqn_ailAil_pe_cpri_cwRegs; /* Group containing IQN_AIL_PE CPRI CW configuration registers */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_COMMON_CHAN_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_CHAN_CFG; /* PD channel 0-63: configuration register */
} CSL_Iqn_ailAil_pd_common_chan_cfgRegs; /* PD Common channel registers */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_CPRI_AXC_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_CPRI_AXC0_CFG[64]; /* PD CPRI PHY Container LUT: Maps CPRI transports containers to 1 of 8 groups (radio standard), Only CPRI16x can use full 64 depth of LUT */
    volatile Uint32 AIL_PD_CPRI_BUB_FSM_CFG[8]; /* CPRI Mapping Method 3, Bubble insertion state machine control, total of 8 separate FSMs, one per 8 groups/radio_standards */
    volatile Uint32 AIL_PD_CPRI_BUB_FSM2_CFG[8]; /* CPRI Mapping Method 3, Bubble insertion state machine control, total of 8 separate FSMs, one per 8 groups/radio_standards */
    volatile Uint32 AIL_PD_CPRI_TDM_FSM_CFG[8]; /* FSM-by-FSM, CPRI AxC TDM. Intended use is one FSM per radio standard (matching AIL_PHY_CI groups) */
    volatile Uint32 AIL_PD_CPRI_RADSTD_CFG[8]; /* Enables each individual radio standard for the PD for up to 8 radio standards */
    volatile Uint32 AIL_PD_CPRI_RADSTD1_CFG[8]; /* Defines the Radio Standard Offset per radio standard */
    volatile Uint32 AIL_PD_CPRI_RADSTD2_CFG[8]; /* Defines the number of Basic Frames per radio standard */
    volatile Uint32 AIL_PD_CPRI_RADSTD_STS[8]; /* Read Only status of each radio status reflecting enable and satisfying basic frame offset */
} CSL_Iqn_ailAil_pd_cpri_axc_cfgRegs; /* PD CPRI AXC registers */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_CPRI_AXC_TDM_LUT_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_CPRI_AXC_TDM_LUT_CFG; /* TDM AxC LUT. Used to map streams of CPRI containers to appropriate AxC. AxC are listed in order that they are represented on the CPRI link, different portions of LUT allocated to different groups (radio standards) */
} CSL_Iqn_ailAil_pd_cpri_axc_tdm_lut_cfgRegs; /* PD CPRI AxC TDM RAM */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_CPRI_CW_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_CPRI_CW_CHAN_CFG[4]; /* PD CPRI Codeword Configuration register */
    volatile Uint8 RSVD0[1008];
    volatile Uint32 AIL_PD_CPRI_CW_LUT_CFG[256]; /* CPRI CW Channel LUT Register */
    volatile Uint32 AIL_PD_CPRI_HYPFRM0_LUT_CFG; /* PD CPRI Hyperframe Enable Part0, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels */
    volatile Uint32 AIL_PD_CPRI_HYPFRM1_LUT_CFG; /* PD CPRI Hyperframe Enable Part1, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels */
    volatile Uint32 AIL_PD_CPRI_HYPFRM2_LUT_CFG; /* PD CPRI Hyperframe Enable Part2, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels */
    volatile Uint32 AIL_PD_CPRI_HYPFRM3_LUT_CFG; /* PD CPRI Hyperframe Enable Part3, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels */
    volatile Uint32 AIL_PD_CPRI_HYPFRM4_LUT_CFG; /* PD CPRI Hyperframe Enable Part4, used to support RTWP, use enabled by cw_chan register, only one hyperframe_lut for all 4 channels */
    volatile Uint32 AIL_PD_CPRI_NULL_CFG; /* PD CPRI NULL Delimiter control register */
    volatile Uint32 AIL_PD_CPRI_CRC_CFG; /* PD CPRI CRC8 control register */
    volatile Uint8 RSVD1[4];
    volatile Uint32 AIL_PD_CPRI_4B5B_CFG[4]; /* PD CPRI Fast Ethernet control register */
} CSL_Iqn_ailAil_pd_cpri_cw_cfgRegs; /* PD CPRI CW registers */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_OBSAI_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_OBSAI_GSM_BBHOP_CFG[2]; /* chan-by-chan strobe signal: OBSAI GSM base band hopping control. Indicates to PD that next timeslot will not have PHY data. pd_gsm_bbhop_cfg[1]: chan 63-to-32 pd_gsm_bbhop_cfg[0]: chan 31-to-0. Value is cleared once used or if channel is OFF and not enabled. */
    volatile Uint8 RSVD0[8];
    volatile Uint32 AIL_PD_OBSAI_RP3_01_STS[4]; /* RP3_01 FCB capture from received OBSAI msg. Capture is OBSAI Type triggered, Type LUT has capture control. Whole OBSAI qwd payload is captured to 4 MMRs */
    volatile Uint32 AIL_PD_OBSAI_RADSTD_CFG[8]; /* OBSAI timing control, RadT usage  */
    volatile Uint32 AIL_PD_OBSAI_RADT_CFG[8]; /* OBSAI timing control, RadT usage  */
    volatile Uint32 AIL_PD_OBSAI_FRM_TC_CFG[8]; /* For framing state machine, supplies terminal counts of some of the state counters and some start counts. Eight different versions of this register are used to support 8 different radio standard variants simultaneously */
} CSL_Iqn_ailAil_pd_obsai_cfgRegs; /* PD OBSAI control */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_OBSAI_LUT_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_OBSAI_CHAN_CFG[64]; /* PD Channel Control Register  */
    volatile Uint32 AIL_PD_OBSAI_ROUTE_CFG[64]; /* Information used to decode OBSAI header information for routing into PD channels. */
    volatile Uint32 AIL_PD_OBSAI_TYPE_LUT_CFG[32]; /* OBSAI Type Look Up Table. Allows for new OBSAI types to be defined (and reconfiguation of exisiting Types)  */
} CSL_Iqn_ailAil_pd_obsai_lut_cfgRegs; /* PD OBSAI LUTs */

/**************************************************************************\
* Register Overlay Structure for AIL_PD_OBSAI_FRM_MSG_TC_CFG
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_OBSAI_FRM_MSG_TC_CFG; /* PD Frame Message Terminal Count Register. This table is shared between all 8 radio standards. The index values control the mapping of different portions of this table to the different radio standards */
} CSL_Iqn_ailAil_pd_obsai_frm_msg_tc_cfgRegs; /* pd_obsai_frm_msg_tc_cfg RAM */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_glb
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_GLB_CFG; /* The AIL PHY Global Configuration Register defines the global operation of the AIL PHY */
} CSL_Iqn_ailAil_phy_glbRegs; /*  Group of Global Configuration Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_rt
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_RT_CFG; /* The AIL PHY RT Configuration Register defines the basic operation of the RT block */
    volatile Uint32 AIL_PHY_RT_DP_STS; /* The AIL PHY RT Depth Status Register displays the real time depth of the Link Buffer in the RT Block */
    volatile Uint32 AIL_PHY_RT_HDR_ERR_STS; /* The AIL PHY RT Header Error Status Register displays the status of the last header error determined during aggregation operations while the RT block is in OBSAI Mode */
} CSL_Iqn_ailAil_phy_rtRegs; /*  Group of RT Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_ci_lut
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CI_LUT_CFG; /* The AIL PHY CI LUT Select Register selects between the LUT A table and the LUT B table for CI CPRI Conversion control. Used for dynamic modification of CI effectively giving the user a Ping Pong buffer. Select takes effect on next PHY frame boundary. */
} CSL_Iqn_ailAil_phy_ci_lutRegs; /*  Group of CI LUT Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_co_lut
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CO_LUT_CFG; /* The AIL PHY CO LUT Select Register selects between the LUT A table and the LUT B table for CO CPRI Conversion control Used for dynamic modification of CO effectively giving the user a Ping Pong buffer. Select takes effect on next PHY frame boundary. */
} CSL_Iqn_ailAil_phy_co_lutRegs; /*  Group of CO LUT Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_ci_lut_a
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CI_LUTA_CFG; /* The AIL PHY CI Look-up Table A Registers control up to eight groups of AxC containers for every given CPRI basic frame. */
} CSL_Iqn_ailAil_phy_ci_lut_aRegs; /*  Group of CI LUT A Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_ci_lut_b
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CI_LUTB_CFG; /* The AIL PHY CI Look-up Table B Registers control up to eight groups of AxC containers for every given CPRI basic frame. */
} CSL_Iqn_ailAil_phy_ci_lut_bRegs; /*  Group of CI LUT B Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_co_lut_a
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CO_LUTA_CFG; /* The AIL PHY CO Look-up Table A Registers control up to eight groups of AxC containers for every given CPRI basic frame. */
} CSL_Iqn_ailAil_phy_co_lut_aRegs; /*  Group of CO LUT A Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_co_lut_b
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_CO_LUTB_CFG; /* The AIL PHY CO Look-up Table B Registers control up to eight groups of AxC containers for every given CPRI basic frame. */
} CSL_Iqn_ailAil_phy_co_lut_bRegs; /*  Group of CO LUT B Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_tm
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_TM_CFG; /* The TM Configuration Register is used to program basic functionality of the Tx Mac Block. Bit 0 can be updated at any time to turn on or off the link */
    volatile Uint32 AIL_PHY_TM_CTRL_CFG; /* TM State Machine Control Register */
    volatile Uint32 AIL_PHY_TM_SCR_CTRL_CFG; /* The Scrambler Configuration Register contains the seed initialization vector for the LFSR scrambler utilized when scrambling is enabled in OBSAI 8x mode or CPRI 8x,10x,16x mode (for CPRI, it is optional), and the scrambler enable bit is set. This configuration register should only be updated when the Frame Sync state machine is disabled. */
    volatile Uint32 AIL_PHY_TM_L1_INBAND_CFG; /* (CPRI Only) SW supplied L1 inband alarm signals for for insertion into Egres CPRI link.  */
    volatile Uint32 AIL_PHY_TM_L1_INBAND_EN_CFG; /* (CPRI Only)The L1 Inband Enable Register allows hardware control of the L1 inband alarm signals. A 1 for each bit indicates the hardware control is enabled. Each enable bit is a gate on an input condition that could affect an output condition. The nomenclature is defined as TXSIGNAL_RXCOND_EN. The term ERR indicates the error had been determined by the RM, while the term RX refers to the actual L1 inband signal received by the RM. */
    volatile Uint32 AIL_PHY_TM_LOSERR_SEL_CFG; /* Selects which RM link is used to drive the LOSERR condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_LOFERR_SEL_CFG; /* Selects which RM link is used to drive the LORERR condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_LOSRX_SEL_CFG; /* Selects which RM link is used to drive the LOSRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_LOFRX_SEL_CFG; /* Selects which RM link is used to drive the LOFRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_RAIRX_SEL_CFG; /* Selects which RM link is used to drive the RAIRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_RSTRX_SEL_CFG; /* Selects which RM link is used to drive the RSTRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 AIL_PHY_TM_CPRI_HFN_STS; /* TM CPRI HFN Status */
    volatile Uint32 AIL_PHY_TM_CPRI_PTRP_CFG;
    volatile Uint32 AIL_PHY_TM_CPRI_STARTUP_CFG; /* Contains Startup value */
    volatile Uint32 AIL_PHY_TM_CPRI_VERSION_CFG; /* Contains Protocol Version value */
    volatile Uint32 AIL_PHY_TM_STS; /* The TM Status Register contains status of the TM block */
    volatile Uint32 AIL_PHY_TM_CPRI_PORTID_A_CFG; /* TM CPRI PORT ID bits 31 to 0 which are inserted into the CPRI Egress Link at specific CPRI CW */
    volatile Uint32 AIL_PHY_TM_CPRI_PORTID_B_CFG; /* TM CPRI PORT ID bits 63 to 32 which are inserted into the CPRI Egress Link at specific CPRI CW */
    volatile Uint32 AIL_PHY_TM_CPRI_SCR_CTRL_CFG; /* (CPRI only) The Scrambler Configuration Register contains the seed initialization vector for the CPRI LFSR scrambler utilized in CPRI 8x,10x,16x mode. This configuration register should only be updated when the TM Frame Sync state machine is disabled. */
} CSL_Iqn_ailAil_phy_tmRegs; /*  Group of PHY TM Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_phy_rm
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PHY_RM_CFG; /* RM Configuration Register */
    volatile Uint32 AIL_PHY_RM_DP_CFG; /* Controls the RM Data Path Configuration */
    volatile Uint32 AIL_PHY_RM_LCV_CTRL_CFG; /* Controls the counting of LCV Errors in the RM */
    volatile Uint32 AIL_PHY_RM_FSM_SYNC_CFG; /* RM FSM Sync Count Configuration Register */
    volatile Uint32 AIL_PHY_RM_FSM_UNSYNC_CFG; /* RM FSM Unsync Count Configuration Register */
    volatile Uint32 AIL_PHY_RM_DSCR_CTRL_CFG; /* Controls the descrambling operation of the RM */
    volatile Uint32 AIL_PHY_RM_CLK_DET_CFG; /* RM Clock Detection Configuration */
    volatile Uint32 AIL_PHY_RM_CPRI_HFN_STS; /* Contains the last received CPRI HFN value */
    volatile Uint32 AIL_PHY_RM_CPRI_BFN_STS; /* Contains the last received CPRI BFN value */
    volatile Uint32 AIL_PHY_RM_CPRI_STATE_STS; /* Defines the RM CPRI State Status */
    volatile Uint32 AIL_PHY_RM_CPRI_VERSION_STS; /* Contains the last received CPRI Version Value */
    volatile Uint32 AIL_PHY_RM_CPRI_STARTUP_STS; /* Contains the last received CPRI Startup Value */
    volatile Uint32 AIL_PHY_RM_CPRI_L1_INBAND_STS; /* Contains the last received CPRI L1 Inband Signals */
    volatile Uint32 AIL_PHY_RM_CPRI_PTRP_STS; /* Contains the last received CPRI PtrP Value */
    volatile Uint32 AIL_PHY_RM_CPRI_SCR_SEED_STS; /* RM CPRI De-scrambler Seed */
    volatile Uint8 RSVD0[4];
    volatile Uint32 AIL_PHY_RM_STS; /* RM Status Register */
    volatile Uint32 AIL_PHY_RM_LCV_LOS_CNT_STS; /* RM LCV LOS Count */
    volatile Uint32 AIL_PHY_RM_LCV_CNT_STS; /* RM LCV Count */
    volatile Uint32 AIL_PHY_RM_CLK_QUAL_STS; /* RM Clock Quality */
    volatile Uint32 AIL_PHY_RM_OBSAI_SCR_SEED_STS; /* RM OBSAI De-scrambler Seed */
    volatile Uint32 AIL_PHY_RM_CPRI_PORTID_A_STS; /* RM CPRI PORT ID Z53 and Z116 */
    volatile Uint32 AIL_PHY_RM_CPRI_PORTID_B_STS; /* RM CPRI PORT ID Z180 and Z244 */
} CSL_Iqn_ailAil_phy_rmRegs; /* PHY RM Registers */

/**************************************************************************\
* Register Overlay Structure for AIL_IQN_AIL_EE_VBUSCLK_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_EE_SII_E_RAW_STS; /* SI si_i IQ info. */
    volatile Uint32 AIL_EE_SII_E_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_E_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_E_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_E_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_E_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_E_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_E_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_E_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_E_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_E_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_F_RAW_STS; /* SI si_i CTL info. */
    volatile Uint32 AIL_EE_SII_F_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_F_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_F_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_F_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_F_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_F_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_F_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_F_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_F_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_F_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_G_0_RAW_STS; /* SI si_i IQ per-channel SOP transmitted to PSI info */
    volatile Uint32 AIL_EE_SII_G_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_G_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_G_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_G_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_G_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_G_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_G_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_G_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_G_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_G_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_G_1_RAW_STS; /* SI si_i IQ per-channel SOP transmitted to PSI info */
    volatile Uint32 AIL_EE_SII_G_1_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_G_1_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_G_1_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_G_1_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_G_1_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_G_1_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_G_1_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_G_1_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_G_1_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_G_1_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD0[88];
    volatile Uint32 AIL_EE_SII_H_RAW_STS; /* SI si_i CTL per-channel SOP transmitted to PSI info */
    volatile Uint32 AIL_EE_SII_H_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_H_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_H_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_H_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_H_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_H_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_H_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_H_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_H_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_H_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD1[132];
    volatile Uint32 AIL_EE_SIE_D_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 AIL_EE_SIE_D_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_D_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_D_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_D_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_D_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_D_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_D_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_D_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_D_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_D_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SIE_E_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 AIL_EE_SIE_E_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_E_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_E_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_E_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_E_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_E_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_E_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_E_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_E_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_E_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SIE_F_0_RAW_STS; /* SI si_e IQ per-channel SOP received from PSI info */
    volatile Uint32 AIL_EE_SIE_F_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_F_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_F_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_F_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_F_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_F_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_F_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_F_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_F_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_F_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SIE_F_1_RAW_STS; /* SI si_e IQ per-channel SOP received from PSI info */
    volatile Uint32 AIL_EE_SIE_F_1_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_F_1_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_F_1_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_F_1_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_F_1_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_F_1_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_F_1_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_F_1_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_F_1_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_F_1_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD2[88];
    volatile Uint32 AIL_EE_SIE_G_RAW_STS; /* SI si_e CTL per-channel SOP received from PSI info */
    volatile Uint32 AIL_EE_SIE_G_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_G_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_G_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_G_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_G_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_G_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_G_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_G_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_G_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_G_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD3[132];
    volatile Uint32 AIL_VBUSCLK_ORIG_REG; /* This is the vbusclk origination register indicating which interrupt register group caused the interrupt. */
} CSL_Iqn_ailAil_iqn_ail_ee_vbusclk_eeRegs; /* IQN_AIL_EE_VBUSCLK EE register group */

/**************************************************************************\
* Register Overlay Structure for AIL_IQN_AIL_EE_SYSCLK_PHY_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_RM_0_RAW_STS; /* AIL RM error register. */
    volatile Uint32 AIL_RM_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_RM_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_RM_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_RM_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_RM_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_RM_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_RM_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_RM_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_RM_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_RM_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_RT_TM_0_RAW_STS; /* AIL RT and TM error register. */
    volatile Uint32 AIL_RT_TM_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_RT_TM_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_RT_TM_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_RT_TM_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_RT_TM_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_RT_TM_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_RT_TM_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_RT_TM_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_RT_TM_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_RT_TM_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_CI_CO_0_RAW_STS; /* AIL CI and CO error register. */
    volatile Uint32 AIL_CI_CO_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_CI_CO_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_CI_CO_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_CI_CO_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_CI_CO_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_CI_CO_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_CI_CO_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_CI_CO_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_CI_CO_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_CI_CO_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_SYSCLK_PHY_ORIG_REG; /* This is the sysclk origination register indicating which interrupt register group caused the interrupt. */
} CSL_Iqn_ailAil_iqn_ail_ee_sysclk_phy_eeRegs; /* IQN_AIL_EE_SYSCLK_PHY EE register group */

/**************************************************************************\
* Register Overlay Structure for AIL_IQN_AIL_EE_SYSCLK_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIL_PD_0_RAW_STS; /* AIL PD error register. */
    volatile Uint32 AIL_PD_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_PD_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_PD_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_PD_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_PD_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_PD_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_PD_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_PD_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_PD_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_PD_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_PD_1_RAW_STS; /* AIL PD error register. */
    volatile Uint32 AIL_PD_1_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_PD_1_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_PD_1_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_PD_1_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_PD_1_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_PD_1_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_PD_1_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_PD_1_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_PD_1_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_PD_1_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_PD_2_0_RAW_STS; /* AIL PD error register. */
    volatile Uint32 AIL_PD_2_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_PD_2_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_PD_2_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_PD_2_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_PD_2_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_PD_2_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_PD_2_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_PD_2_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_PD_2_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_PD_2_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_PD_2_1_RAW_STS; /* AIL PD error register. */
    volatile Uint32 AIL_PD_2_1_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_PD_2_1_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_PD_2_1_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_PD_2_1_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_PD_2_1_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_PD_2_1_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_PD_2_1_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_PD_2_1_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_PD_2_1_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_PD_2_1_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD0[88];
    volatile Uint32 AIL_PE_0_RAW_STS; /* AIL PE error register. */
    volatile Uint32 AIL_PE_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_PE_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_PE_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_PE_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_PE_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_PE_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_PE_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_PE_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_PE_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_PE_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_AIL_SI_0_RAW_STS; /* AIL uAT and SI_AIL_PE_SCH error register. */
    volatile Uint32 AIL_AIL_SI_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_AIL_SI_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_AIL_SI_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_AIL_SI_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_AIL_SI_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_AIL_SI_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_AIL_SI_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_AIL_SI_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_AIL_SI_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_AIL_SI_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_A_RAW_STS; /* SI si_i IQ errors and info. */
    volatile Uint32 AIL_EE_SII_A_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_B_RAW_STS; /* SI si_i CTL errors and info. */
    volatile Uint32 AIL_EE_SII_B_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_B_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_B_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_B_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_B_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_B_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_B_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_B_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_B_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_B_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_C_0_RAW_STS; /* SI si_i IQ per-channel start of frame errors */
    volatile Uint32 AIL_EE_SII_C_0_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_C_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_C_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_C_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_C_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_C_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_C_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_C_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_C_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_C_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SII_C_1_RAW_STS; /* SI si_i IQ per-channel start of frame errors */
    volatile Uint32 AIL_EE_SII_C_1_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_C_1_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_C_1_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_C_1_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_C_1_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_C_1_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_C_1_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_C_1_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_C_1_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_C_1_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD1[88];
    volatile Uint32 AIL_EE_SII_D_RAW_STS; /* SI si_i CTL per-channel SOP received from ICC info */
    volatile Uint32 AIL_EE_SII_D_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SII_D_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SII_D_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SII_D_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SII_D_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SII_D_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SII_D_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SII_D_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SII_D_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SII_D_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD2[132];
    volatile Uint32 AIL_EE_SIE_A_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 AIL_EE_SIE_A_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SIE_B_RAW_STS; /* SI si_e CTL info. */
    volatile Uint32 AIL_EE_SIE_B_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_B_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_B_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_B_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_B_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_B_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_B_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_B_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_B_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_B_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 AIL_EE_SIE_C_RAW_STS; /* SI si_e CTL per-channel SOP transmitted to ICC */
    volatile Uint32 AIL_EE_SIE_C_RAW_SET; /* Raw Set */
    volatile Uint32 AIL_EE_SIE_C_RAW_CLR; /* Raw Clear */
    volatile Uint32 AIL_EE_SIE_C_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AIL_EE_SIE_C_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AIL_EE_SIE_C_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AIL_EE_SIE_C_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AIL_EE_SIE_C_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AIL_EE_SIE_C_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AIL_EE_SIE_C_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AIL_EE_SIE_C_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD3[132];
    volatile Uint32 AIL_SYSCLK_ORIG_REG; /* This is the sysclk origination register indicating which interrupt register group caused the interrupt. */
} CSL_Iqn_ailAil_iqn_ail_ee_sysclk_eeRegs; /* IQN_AIL_EE_SYSCLK EE register group */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn_ailAil_si_iq_efe_config_groupRegs AIL_SI_IQ_EFE_CONFIG_GROUP;
    volatile Uint8 RSVD0[344];
    CSL_Iqn_ailAil_si_iq_efe_radio_standard_groupRegs AIL_SI_IQ_EFE_RADIO_STANDARD_GROUP;
    volatile Uint8 RSVD1[204];
    CSL_Iqn_ailAil_iq_efe_chan_axc_offsetRegs AIL_IQ_EFE_CHAN_AXC_OFFSET[64];
    volatile Uint8 RSVD2[256];
    CSL_Iqn_ailAil_iq_efe_frm_samp_tc_mmr_ramRegs AIL_IQ_EFE_FRM_SAMP_TC_MMR_RAM[256];
    CSL_Iqn_ailAil_si_iq_e_tdm_lut_ramRegs AIL_SI_IQ_E_TDM_LUT_RAM[256];
    CSL_Iqn_ailAil_si_iq_e_sch_phyRegs AIL_SI_IQ_E_SCH_PHY;
    volatile Uint8 RSVD3[120];
    CSL_Iqn_ailAil_si_iq_e_obsai_modtxruleRegs AIL_SI_IQ_E_OBSAI_MODTXRULE;
    CSL_Iqn_ailAil_si_iq_e_obsai_dbm_rule_ramRegs AIL_SI_IQ_E_OBSAI_DBM_RULE_RAM[32];
    volatile Uint8 RSVD4[512];
    CSL_Iqn_ailAil_si_iq_e_obsai_dbm_bitmap_ramRegs AIL_SI_IQ_E_OBSAI_DBM_BITMAP_RAM[256];
    CSL_Iqn_ailAil_si_iq_e_sch_cpriRegs AIL_SI_IQ_E_SCH_CPRI;
    volatile Uint8 RSVD5[1536];
    CSL_Iqn_ailAil_iq_ife_channel_configuration_groupRegs AIL_IQ_IFE_CHANNEL_CONFIGURATION_GROUP;
    volatile Uint8 RSVD6[256];
    CSL_Iqn_ailAil_iq_ife_radio_standard_groupRegs AIL_IQ_IFE_RADIO_STANDARD_GROUP;
    volatile Uint8 RSVD7[12];
    CSL_Iqn_ailAil_iq_ife_config_groupRegs AIL_IQ_IFE_CONFIG_GROUP;
    volatile Uint8 RSVD8[28];
    CSL_Iqn_ailAil_iq_idc_general_status_groupRegs AIL_IQ_IDC_GENERAL_STATUS_GROUP;
    volatile Uint8 RSVD9[40];
    CSL_Iqn_ailAil_iq_idc_configuration_groupRegs AIL_IQ_IDC_CONFIGURATION_GROUP;
    volatile Uint8 RSVD10[60];
    CSL_Iqn_ailAil_iq_idc_channel_config_groupRegs AIL_IQ_IDC_CHANNEL_CONFIG_GROUP;
    volatile Uint8 RSVD11[768];
    CSL_Iqn_ailAil_ife_frm_samp_tc_mmr_ramRegs AIL_IFE_FRM_SAMP_TC_MMR_RAM[256];
    volatile Uint8 RSVD12[1024];
    CSL_Iqn_ailAil_ectl_pkt_ifRegs AIL_ECTL_PKT_IF;
    volatile Uint8 RSVD13[3056];
    CSL_Iqn_ailAil_ictl_idc_ifRegs AIL_ICTL_IDC_IF;
    volatile Uint8 RSVD14[108];
    CSL_Iqn_ailAil_ictl_pkt_ifRegs AIL_ICTL_PKT_IF;
    volatile Uint8 RSVD15[3056];
    CSL_Iqn_ailAil_uat_gen_ctlRegs AIL_UAT_GEN_CTL;
    CSL_Iqn_ailAil_uat_ail_regsRegs AIL_UAT_AIL_REGS;
    volatile Uint8 RSVD16[76];
    CSL_Iqn_ailAil_uat_egr_radtRegs AIL_UAT_EGR_RADT[8];
    CSL_Iqn_ailAil_uat_ing_radtRegs AIL_UAT_ING_RADT[8];
    volatile Uint8 RSVD17[128];
    CSL_Iqn_ailAil_uat_radt_evtRegs AIL_UAT_RADT_EVT[22];
    volatile Uint8 RSVD18[11600];
    CSL_Iqn_ailAil_iq_edc_register_groupRegs AIL_IQ_EDC_REGISTER_GROUP;
    volatile Uint8 RSVD19[7424];
    CSL_Iqn_ailAil_iq_ingress_vbus_mmr_groupRegs AIL_IQ_INGRESS_VBUS_MMR_GROUP;
    volatile Uint8 RSVD20[4084];
    CSL_Iqn_ailAil_ectl_register_groupRegs AIL_ECTL_REGISTER_GROUP;
    volatile Uint8 RSVD21[3568];
    CSL_Iqn_ailAil_ctl_ingress_vbus_mmr_groupRegs AIL_CTL_INGRESS_VBUS_MMR_GROUP;
    volatile Uint8 RSVD22[81908];
    CSL_Iqn_ailAil_pe_commonRegs AIL_PE_COMMON;
    CSL_Iqn_ailAil_pe_obsai_header_lutRegs AIL_PE_OBSAI_HEADER_LUT[64];
    volatile Uint8 RSVD23[3328];
    CSL_Iqn_ailAil_pe_cpri_cwRegs AIL_PE_CPRI_CW;
    volatile Uint8 RSVD24[26880];
    CSL_Iqn_ailAil_pd_common_chan_cfgRegs AIL_PD_COMMON_CHAN_CFG[64];
    volatile Uint8 RSVD25[1536];
    CSL_Iqn_ailAil_pd_cpri_axc_cfgRegs AIL_PD_CPRI_AXC_CFG;
    volatile Uint8 RSVD26[544];
    CSL_Iqn_ailAil_pd_cpri_axc_tdm_lut_cfgRegs AIL_PD_CPRI_AXC_TDM_LUT_CFG[256];
    CSL_Iqn_ailAil_pd_cpri_cw_cfgRegs AIL_PD_CPRI_CW_CFG;
    volatile Uint8 RSVD27[2000];
    CSL_Iqn_ailAil_pd_obsai_cfgRegs AIL_PD_OBSAI_CFG;
    volatile Uint8 RSVD28[128];
    CSL_Iqn_ailAil_pd_obsai_lut_cfgRegs AIL_PD_OBSAI_LUT_CFG;
    volatile Uint8 RSVD29[128];
    CSL_Iqn_ailAil_pd_obsai_frm_msg_tc_cfgRegs AIL_PD_OBSAI_FRM_MSG_TC_CFG[256];
    volatile Uint8 RSVD30[22528];
    CSL_Iqn_ailAil_phy_glbRegs AIL_PHY_GLB;
    volatile Uint8 RSVD31[60];
    CSL_Iqn_ailAil_phy_rtRegs AIL_PHY_RT;
    volatile Uint8 RSVD32[52];
    CSL_Iqn_ailAil_phy_ci_lutRegs AIL_PHY_CI_LUT;
    volatile Uint8 RSVD33[60];
    CSL_Iqn_ailAil_phy_co_lutRegs AIL_PHY_CO_LUT;
    volatile Uint8 RSVD34[60];
    CSL_Iqn_ailAil_phy_ci_lut_aRegs AIL_PHY_CI_LUT_A[8];
    volatile Uint8 RSVD35[32];
    CSL_Iqn_ailAil_phy_ci_lut_bRegs AIL_PHY_CI_LUT_B[8];
    volatile Uint8 RSVD36[32];
    CSL_Iqn_ailAil_phy_co_lut_aRegs AIL_PHY_CO_LUT_A[8];
    volatile Uint8 RSVD37[32];
    CSL_Iqn_ailAil_phy_co_lut_bRegs AIL_PHY_CO_LUT_B[8];
    volatile Uint8 RSVD38[32];
    CSL_Iqn_ailAil_phy_tmRegs AIL_PHY_TM;
    volatile Uint8 RSVD39[52];
    CSL_Iqn_ailAil_phy_rmRegs AIL_PHY_RM;
    volatile Uint8 RSVD40[7460];
    CSL_Iqn_ailAil_iqn_ail_ee_vbusclk_eeRegs AIL_IQN_AIL_EE_VBUSCLK_EE;
    volatile Uint8 RSVD41[7308];
    CSL_Iqn_ailAil_iqn_ail_ee_sysclk_phy_eeRegs AIL_IQN_AIL_EE_SYSCLK_PHY_EE;
    volatile Uint8 RSVD42[1912];
    CSL_Iqn_ailAil_iqn_ail_ee_sysclk_eeRegs AIL_IQN_AIL_EE_SYSCLK_EE;
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD43[46044];
/******************************************/
} CSL_Iqn_ailRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ail_iq_efe_chan_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_EN_DISABLED (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_OBSAI_CTL_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_OBSAI_CTL_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_OBSAI_CTL_RESETVAL (0x00000000u)
/*----CHAN_OBSAI_CTL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_OBSAI_CTL_NON_OBSAI_CTL (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_OBSAI_CTL_OBSAI_CTL (0x00000001u)

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_ENET_CTL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_ENET_CTL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_ENET_CTL_RESETVAL (0x00000000u)
/*----CHAN_ENET_CTL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_ENET_CTL_NON_ENET (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_ENET_CTL_ENET (0x00000001u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_AXC_FINE_OFFSET_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_AXC_FINE_OFFSET_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_AXC_FINE_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_TDD_FRC_OFF Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_FRC_SYM_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_NO_FRC_OFF_SYM (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_MASK (0x00007000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RESETVAL (0x00000000u)
/*----CHAN_RADIO_SEL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS0 (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS1 (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS2 (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS3 (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS4 (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS5 (0x00000005u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS6 (0x00000006u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS7 (0x00000007u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_iq_efe_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_CFG_LOOPBACK_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CFG_LOOPBACK_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CFG_LOOPBACK_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CFG_RESETVAL (0x00000000u)

/* ail_iq_efe_global_en_set_stb */

#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* ail_iq_efe_global_en_clr_stb */

#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* ail_iq_efe_global_en_sts */

#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* ail_iq_efe_chan_on_sts */

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_ON_STS_CHAN_ON_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_ON_STS_RESETVAL (0x00000000u)

/* ail_iq_efe_in_pkt_sts */

#define CSL_IQN_AIL_AIL_IQ_EFE_IN_PKT_STS_IN_PKT_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_IN_PKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_IN_PKT_STS_IN_PKT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_IN_PKT_STS_RESETVAL (0x00000000u)

/* ail_iq_efe_dma_sync_sts */

#define CSL_IQN_AIL_AIL_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_DMA_SYNC_STS_RESETVAL (0x00000000u)

/* ail_iq_efe_frm_tc_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_SYM_TC_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_SYM_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_SYM_TC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_SC_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_SC_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_TC_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_TC_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_INDEX_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_TC_CFG_RESETVAL (0x00000000u)

/* ail_iq_efe_rad_std_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_RESETVAL (0x00000000u)
/*----TDD_LUT_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_DISABLED (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_AXC_BBHOP_MODE_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_AXC_BBHOP_MODE_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_AXC_BBHOP_MODE_RESETVAL (0x00000000u)
/*----GSM_AXC_BBHOP_MODE Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_AXC_BBHOP_MODE_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_AXC_BBHOP_MODE_DISABLED (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_CMP_MODE_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_CMP_MODE_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_CMP_MODE_RESETVAL (0x00000000u)
/*----GSM_CMP_MODE Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_CMP_MODE_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_GSM_CMP_MODE_DISABLED (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_RAD_STD_CFG_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg0 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG0_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg1 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG1_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg2 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG2_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg3 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG3_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg4 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG4_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg5 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG5_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg6 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG6_RESETVAL (0x00000000u)

/* ail_iq_efe_tdd_en_cfg7 */

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EFE_TDD_EN_CFG7_RESETVAL (0x00000000u)

/* ail_iq_efe_chan_axc_offset_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_CHAN_AXC_OFFSET_CFG_RESETVAL (0x00000000u)

/* ail_iq_efe_frm_samp_tc_cfg */

#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EFE_FRM_SAMP_TC_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_tdm_lut_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_AXC_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_AXC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_AXC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_TDM_LUT_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_phy_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_PHY_CFG_PHY_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_PE_PHY_CFG_PHY_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_PHY_CFG_PHY_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_PHY_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_phy_sts */

#define CSL_IQN_AIL_AIL_IQ_PE_PHY_STS_PHY_ON_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_PE_PHY_STS_PHY_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_PHY_STS_PHY_ON_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_PHY_STS_RESETVAL (0x00000000u)

/* ail_iq_pe_obsai_modtxrule_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_MOD_MASK (0x00000FFFu)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_MOD_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_MOD_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_EN_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_EN_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_CTL_MSG_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_CTL_MSG_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_CTL_MSG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_INDEX_MASK (0x0FFF0000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_INDEX_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RULE_INDEX_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_MODTXRULE_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_obsai_dbm_0_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_RADSTD_MASK (0x00000078u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_RADSTD_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_RADSTD_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_X_MASK (0x00007F00u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_X_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_X_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_1MULT_MASK (0x001F0000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_1MULT_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_DBM_1MULT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_0_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_obsai_dbm_1_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_1SIZE_MASK (0x0000007Fu)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_1SIZE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_1SIZE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_2SIZE_MASK (0x00007F00u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_2SIZE_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_2SIZE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_LUTSTRT_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_LUTSTRT_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_LUTSTRT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_XBUBBLE_MASK (0x7F000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_XBUBBLE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_DBM_XBUBBLE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_1_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_obsai_dbm_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_CFG_DBM_BIT_MAP_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_CFG_DBM_BIT_MAP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_CFG_DBM_BIT_MAP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_OBSAI_DBM_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CFG_AXC_CONT_TC_MASK (0x0000007Fu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CFG_AXC_CONT_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CFG_AXC_CONT_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_bub_fsm_cfg */


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM_CFG_KNC_MASK (0xFFFFC000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM_CFG_KNC_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM_CFG_KNC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_bub_fsm2_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_FRAC_MASK (0x00000FFFu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_FRAC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_FRAC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_INT_MASK (0x3FFFF000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_INT_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_GAP_INT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_BUB_FSM2_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_tdm_fsm_cfg */


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_NCONT_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_NCONT_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_NCONT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_LUTSTRT_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_LUTSTRT_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_LUTSTRT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_TDM_FSM_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_radstd_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_CFG_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_CFG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_CFG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_radstd1_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_BFRM_OFFSET_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_BFRM_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_BFRM_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_HFRM_OFFSET_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_HFRM_OFFSET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_HFRM_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD1_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_radstd2_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD2_CFG_BFRM_NUM_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD2_CFG_BFRM_NUM_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD2_CFG_BFRM_NUM_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD2_CFG_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_radstd_sts */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_STS_ON_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_STS_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_STS_ON_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_RADSTD_STS_RESETVAL (0x00000000u)

/* ail_iq_pe_cpri_cont_cfg */

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_GRP_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_GRP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_GRP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_EN_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_EN_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_EN_RESETVAL (0x00000000u)
/*----lut_en Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_EN_CONT_DIS (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_LUT_EN_CONT_EN (0x00000001u)


#define CSL_IQN_AIL_AIL_IQ_PE_CPRI_CONT_CFG_RESETVAL (0x00000000u)

/* ail_iq_ife_chan_cfg */

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_EN_DISABLED (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_MASK (0x0000000Cu)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_RESETVAL (0x00000000u)
/*----CHAN_AXC_OFFSET Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_ONE (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_TWO (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_THREE (0x00000003u)

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_MASK (0x00000070u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RESETVAL (0x00000000u)
/*----CHAN_RADIO_SEL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS0 (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS1 (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS2 (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS3 (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS4 (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS5 (0x00000005u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS6 (0x00000006u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS7 (0x00000007u)


#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_TDD_FRC_OFF Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_FRC_SYM_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_NO_FRC_OFF_SYM (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_OBSAI_CTL_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_OBSAI_CTL_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_OBSAI_CTL_RESETVAL (0x00000000u)
/*----CHAN_OBSAI_CTL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_OBSAI_CTL_OBSAI_CTL (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_OBSAI_CTL_NON_OBSAI_CTL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_ENET_CTL_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_ENET_CTL_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_ENET_CTL_RESETVAL (0x00000000u)
/*----CHAN_ENET_CTL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_ENET_CTL_ENET (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_CHAN_ENET_CTL_NON_ENET (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_iq_ife_frm_tc_cfg */

#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_SYM_TC_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_SYM_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_SYM_TC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_SC_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_SC_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_TC_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_TC_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_INDEX_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_TC_CFG_RESETVAL (0x00000000u)

/* ail_iq_ife_rad_std_cfg */

#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_RESETVAL (0x00000000u)
/*----TDD_LUT_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_DISABLED (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_RAD_STD_CFG_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg0 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG0_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg1 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG1_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg2 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG2_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg3 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG3_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg4 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG4_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg5 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG5_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg6 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG6_RESETVAL (0x00000000u)

/* ail_iq_ife_tdd_en_cfg7 */

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_TDD_EN_CFG7_RESETVAL (0x00000000u)

/* ail_iq_ife_global_en_set_stb */

#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* ail_iq_ife_global_en_clr_stb */

#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* ail_iq_ife_global_en_sts */

#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* ail_iq_ife_chan_on_sts */

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_ON_STS_CHAN_ON_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_CHAN_ON_STS_RESETVAL (0x00000000u)

/* ail_iq_ife_in_pkt_sts */

#define CSL_IQN_AIL_AIL_IQ_IFE_IN_PKT_STS_IN_PKT_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_IN_PKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_IN_PKT_STS_IN_PKT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IFE_IN_PKT_STS_RESETVAL (0x00000000u)

/* ail_iq_idc_sts */

#define CSL_IQN_AIL_AIL_IQ_IDC_STS_EMPTY_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_STS_EMPTY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_STS_EMPTY_RESETVAL (0x00000001u)
/*----EMPTY Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_STS_EMPTY_FIFO_NOT_EMPTY (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_STS_EMPTY_FIFO_EMPTY (0x00000001u)


#define CSL_IQN_AIL_AIL_IQ_IDC_STS_RESETVAL (0x00000001u)

/* ail_iq_idc_inpkt_sts */

#define CSL_IQN_AIL_AIL_IQ_IDC_INPKT_STS_INPKT_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IDC_INPKT_STS_INPKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_INPKT_STS_INPKT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IDC_INPKT_STS_RESETVAL (0x00000000u)

/* ail_iq_idc_cfg */

#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FAIL_MARK_ONLY_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FAIL_MARK_ONLY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FAIL_MARK_ONLY_RESETVAL (0x00000000u)
/*----FAIL_MARK_ONLY Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FAIL_MARK_ONLY_DROP (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FAIL_MARK_ONLY_MARK (0x00000001u)

#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FRC_OFF_ALL_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FRC_OFF_ALL_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FRC_OFF_ALL_RESETVAL (0x00000000u)
/*----FRC_OFF_ALL Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FRC_OFF_ALL_FRC_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_FRC_OFF_ALL_NOP (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RM_FAIL_FRC_OFF_EN_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RM_FAIL_FRC_OFF_EN_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RM_FAIL_FRC_OFF_EN_RESETVAL (0x00000000u)
/*----RM_FAIL_FRC_OFF_EN Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RM_FAIL_FRC_OFF_EN_FRC_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RM_FAIL_FRC_OFF_EN_NOP (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IDC_CFG_RESETVAL (0x00000000u)

/* ail_iq_idc_ch_cfg */

#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_PKT_TYPE_MASK (0x001F0000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_PKT_TYPE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_PKT_TYPE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_CHAN_FRC_OFF_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_CHAN_FRC_OFF_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_CHAN_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_FRC_OFF Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_CHAN_FRC_OFF_FRC_OFF (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_CHAN_FRC_OFF_NOP (0x00000001u)


#define CSL_IQN_AIL_AIL_IQ_IDC_CH_CFG_RESETVAL (0x00000000u)

/* ail_iq_ife_frm_samp_tc_cfg */

#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IFE_FRM_SAMP_TC_CFG_RESETVAL (0x00000000u)

/* ail_ectl_global_en_set_stb */

#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* ail_ectl_global_en_clr_stb */

#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* ail_ectl_global_en_sts */

#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* ail_ectl_chan_on_sts */

#define CSL_IQN_AIL_AIL_ECTL_CHAN_ON_STS_CHAN_ON_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ECTL_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_CHAN_ON_STS_RESETVAL (0x00000000u)

/* ail_ectl_inpkt_sts */

#define CSL_IQN_AIL_AIL_ECTL_INPKT_STS_IN_PKT_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ECTL_INPKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_INPKT_STS_IN_PKT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_INPKT_STS_RESETVAL (0x00000000u)

/* ail_ectl_chan_cfg */

#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_CHAN_EN_DISABLED (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_ectl_db_thold_cfg */

#define CSL_IQN_AIL_AIL_ECTL_DB_THOLD_CFG_CHANNEL_MASK (0x0000001Fu)
#define CSL_IQN_AIL_AIL_ECTL_DB_THOLD_CFG_CHANNEL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_DB_THOLD_CFG_CHANNEL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_DB_THOLD_CFG_RESETVAL (0x00000000u)

/* ail_ictl_ch_cfg */

#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_PKT_TYPE_MASK (0x001F0000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_PKT_TYPE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_PKT_TYPE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_CHAN_FRC_OFF_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_CHAN_FRC_OFF_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_CHAN_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_FRC_OFF Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_CHAN_FRC_OFF_FRC_OFF (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_CHAN_FRC_OFF_NOP (0x00000001u)


#define CSL_IQN_AIL_AIL_ICTL_CH_CFG_RESETVAL (0x00000000u)

/* ail_ictl_cfg */

#define CSL_IQN_AIL_AIL_ICTL_CFG_FAIL_MARK_ONLY_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FAIL_MARK_ONLY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FAIL_MARK_ONLY_RESETVAL (0x00000000u)
/*----FAIL_MARK_ONLY Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CFG_FAIL_MARK_ONLY_DROP (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FAIL_MARK_ONLY_MARK (0x00000001u)

#define CSL_IQN_AIL_AIL_ICTL_CFG_FRC_OFF_ALL_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FRC_OFF_ALL_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FRC_OFF_ALL_RESETVAL (0x00000000u)
/*----FRC_OFF_ALL Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CFG_FRC_OFF_ALL_FRC_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CFG_FRC_OFF_ALL_NOP (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_CFG_RESETVAL (0x00000000u)

/* ail_ictl_sts */

#define CSL_IQN_AIL_AIL_ICTL_STS_EMPTY_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_STS_EMPTY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_STS_EMPTY_RESETVAL (0x00000001u)
/*----EMPTY Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_STS_EMPTY_FIFO_NOT_EMPTY (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_STS_EMPTY_FIFO_EMPTY (0x00000001u)


#define CSL_IQN_AIL_AIL_ICTL_STS_RESETVAL (0x00000001u)

/* ail_ictl_inpkt_sts */

#define CSL_IQN_AIL_AIL_ICTL_INPKT_STS_IN_PKT_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ICTL_INPKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_INPKT_STS_IN_PKT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_INPKT_STS_RESETVAL (0x00000000u)

/* ail_ictl_global_en_set_stb */

#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* ail_ictl_global_en_clr_stb */

#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* ail_ictl_global_en_sts */

#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* ail_ictl_chan_on_sts */

#define CSL_IQN_AIL_AIL_ICTL_CHAN_ON_STS_CHAN_ON_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ICTL_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_CHAN_ON_STS_RESETVAL (0x00000000u)

/* ail_ictl_chan_en_cfg */

#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_CHAN_EN_DISABLED (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_CHAN_EN_CFG_RESETVAL (0x00000000u)

/* ail_uat_cfg */

#define CSL_IQN_AIL_AIL_UAT_CFG_UAT_RUN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_UAT_CFG_UAT_RUN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_CFG_UAT_RUN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_UAT_CFG_DIAG_SYNC_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_UAT_CFG_DIAG_SYNC_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_UAT_CFG_DIAG_SYNC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_CFG_RESETVAL (0x00000000u)

/* ail_uat_bcn_tc_cfg */

#define CSL_IQN_AIL_AIL_UAT_BCN_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_BCN_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_BCN_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_BCN_TC_CFG_RESETVAL (0x00000000u)

/* ail_uat_bcn_offset_cfg */

#define CSL_IQN_AIL_AIL_UAT_BCN_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_BCN_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_BCN_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_BCN_OFFSET_CFG_RESETVAL (0x00000000u)

/* ail_uat_sync_bcn_capture_sts */

#define CSL_IQN_AIL_AIL_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_SYNC_BCN_CAPTURE_STS_RESETVAL (0x00000000u)

/* ail_uat_pi_bcn_capture_sts */

#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_KCHAR_POSITION_MASK (0x80000000u)
#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_KCHAR_POSITION_SHIFT (0x0000001Fu)
#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_KCHAR_POSITION_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_UAT_PI_BCN_CAPTURE_STS_RESETVAL (0x00000000u)

/* ail_uat_pimax_cfg */

#define CSL_IQN_AIL_AIL_UAT_PIMAX_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_PIMAX_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_PIMAX_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_PIMAX_CFG_RESETVAL (0x00000000u)

/* ail_uat_pimin_cfg */

#define CSL_IQN_AIL_AIL_UAT_PIMIN_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_PIMIN_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_PIMIN_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_PIMIN_CFG_RESETVAL (0x00000000u)

/* ail_uat_rp301_bcn_capture_sts */

#define CSL_IQN_AIL_AIL_UAT_RP301_BCN_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_RP301_BCN_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_RP301_BCN_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_RP301_BCN_CAPTURE_STS_RESETVAL (0x00000000u)

/* ail_uat_tm_bfn_cfg */

#define CSL_IQN_AIL_AIL_UAT_TM_BFN_CFG_WR_VAL_MASK (0x00000FFFu)
#define CSL_IQN_AIL_AIL_UAT_TM_BFN_CFG_WR_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_TM_BFN_CFG_WR_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_TM_BFN_CFG_RESETVAL (0x00000000u)

/* ail_uat_tm_bfn_sts */

#define CSL_IQN_AIL_AIL_UAT_TM_BFN_STS_RD_VAL_MASK (0x00000FFFu)
#define CSL_IQN_AIL_AIL_UAT_TM_BFN_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_TM_BFN_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_TM_BFN_STS_RESETVAL (0x00000000u)

/* ail_uat_rt_fb_cfg */

#define CSL_IQN_AIL_AIL_UAT_RT_FB_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_RT_FB_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_RT_FB_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_RT_FB_CFG_RESETVAL (0x00000000u)

/* ail_uat_pe_fb_cfg */

#define CSL_IQN_AIL_AIL_UAT_PE_FB_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_PE_FB_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_PE_FB_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_PE_FB_CFG_RESETVAL (0x00000000u)

/* ail_uat_tm_fb_cfg */

#define CSL_IQN_AIL_AIL_UAT_TM_FB_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_TM_FB_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_TM_FB_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_TM_FB_CFG_RESETVAL (0x00000000u)

/* ail_uat_egr_radt_tc_cfg */

#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_TC_CFG_RESETVAL (0x00000000u)

/* ail_uat_egr_radt_offset_cfg */

#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_EGR_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* ail_uat_egr_sync_radt_capture_sts */

#define CSL_IQN_AIL_AIL_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_EGR_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* ail_uat_ing_radt_tc_cfg */

#define CSL_IQN_AIL_AIL_UAT_ING_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_ING_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_ING_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_ING_RADT_TC_CFG_RESETVAL (0x00000000u)

/* ail_uat_ing_radt_offset_cfg */

#define CSL_IQN_AIL_AIL_UAT_ING_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_ING_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_ING_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_ING_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* ail_uat_ing_sync_radt_capture_sts */

#define CSL_IQN_AIL_AIL_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_ING_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* ail_uat_evt_radt_cmp_cfg */

#define CSL_IQN_AIL_AIL_UAT_EVT_RADT_CMP_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_UAT_EVT_RADT_CMP_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_EVT_RADT_CMP_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_EVT_RADT_CMP_CFG_RESETVAL (0x00000000u)

/* ail_uat_evt_clk_cnt_tc_cfg */

#define CSL_IQN_AIL_AIL_UAT_EVT_CLK_CNT_TC_CFG_VAL_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_UAT_EVT_CLK_CNT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_UAT_EVT_CLK_CNT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_UAT_EVT_CLK_CNT_TC_CFG_RESETVAL (0x00000000u)

/* ail_iq_edc_cfg */

#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_RESETVAL (0x00000000u)
/*----PSI_ERR_CHK_DISABLE Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_DROP (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_NO_DROP (0x00000001u)


#define CSL_IQN_AIL_AIL_IQ_EDC_CFG_RESETVAL (0x00000000u)

/* ail_iq_edc_sop_cntr_sts */

#define CSL_IQN_AIL_AIL_IQ_EDC_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EDC_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EDC_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_iq_edc_eop_cntr_sts */

#define CSL_IQN_AIL_AIL_IQ_EDC_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_EDC_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_EDC_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_iq_edc_occ_cntr_sts */

#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_IQ_EDC_OCC_CNTR_STS_RESETVAL (0x00000000u)

/* ail_iq_edc_ch_cfg */

#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_AIL_AIL_IQ_EDC_CH_CFG_RESETVAL (0x00000000u)

/* ail_iq_idc_rate_ctl_cfg */

#define CSL_IQN_AIL_AIL_IQ_IDC_RATE_CTL_CFG_RATE_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_IQ_IDC_RATE_CTL_CFG_RATE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_RATE_CTL_CFG_RATE_RESETVAL (0x0000000Fu)


#define CSL_IQN_AIL_AIL_IQ_IDC_RATE_CTL_CFG_RESETVAL (0x0000000Fu)

/* ail_iq_idc_sop_cntr_sts */

#define CSL_IQN_AIL_AIL_IQ_IDC_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IDC_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IDC_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_iq_idc_eop_cntr_sts */

#define CSL_IQN_AIL_AIL_IQ_IDC_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_IQ_IDC_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_IQ_IDC_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_IQ_IDC_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_ectl_rate_ctl_cfg */

#define CSL_IQN_AIL_AIL_ECTL_RATE_CTL_CFG_RATE_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ECTL_RATE_CTL_CFG_RATE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_RATE_CTL_CFG_RATE_RESETVAL (0x0000000Fu)


#define CSL_IQN_AIL_AIL_ECTL_RATE_CTL_CFG_RESETVAL (0x0000000Fu)

/* ail_ectl_sop_cntr_sts */

#define CSL_IQN_AIL_AIL_ECTL_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_ECTL_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_ectl_eop_cntr_sts */

#define CSL_IQN_AIL_AIL_ECTL_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_ECTL_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ECTL_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_ectl_occ_cntr_sts */

#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_A_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_A_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_A_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_B_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_B_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_B_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_C_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_C_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_C_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_D_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_D_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_OCC_CNTR_D_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_ECTL_OCC_CNTR_STS_RESETVAL (0x00000000u)

/* ail_ectl_ch_cfg */

#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_AIL_AIL_ECTL_CH_CFG_RESETVAL (0x00000000u)

/* ail_ictl_rate_ctl_cfg */

#define CSL_IQN_AIL_AIL_ICTL_RATE_CTL_CFG_RATE_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_ICTL_RATE_CTL_CFG_RATE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_RATE_CTL_CFG_RATE_RESETVAL (0x0000000Fu)


#define CSL_IQN_AIL_AIL_ICTL_RATE_CTL_CFG_RESETVAL (0x0000000Fu)

/* ail_ictl_sop_cntr_sts */

#define CSL_IQN_AIL_AIL_ICTL_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_ICTL_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_ictl_eop_cntr_sts */

#define CSL_IQN_AIL_AIL_ICTL_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_AIL_AIL_ICTL_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_ICTL_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_ICTL_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* ail_pe_global_cfg */


#define CSL_IQN_AIL_AIL_PE_GLOBAL_CFG_ENET_HDR_SEL_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PE_GLOBAL_CFG_ENET_HDR_SEL_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_GLOBAL_CFG_ENET_HDR_SEL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_GLOBAL_CFG_RESETVAL (0x00000000u)

/* ail_pe_chan_cfg */

#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_MASK (0x00000180u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_RESETVAL (0x00000000u)
/*----rt_ctl Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_ADD8 (0x00000003u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_ADD16 (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_INSERTPE (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RT_CTL_FWD_RM (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_TYPE_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_TYPE_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_TYPE_RESETVAL (0x00000000u)
/*----crc_type Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_TYPE_32BIT_CRC (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_TYPE_16BIT_CRC (0x00000001u)


#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_ETHERNET_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_ETHERNET_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_ETHERNET_RESETVAL (0x00000000u)
/*----ethernet Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_ETHERNET_ENET_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_ETHERNET_ENET_OFF (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_HDR_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_HDR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_HDR_RESETVAL (0x00000000u)
/*----crc_hdr Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_HDR_CRC_HDR_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_CRC_HDR_CRC_HDR_OFF (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_pe_obsai_hdr_cfg */

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_ADR_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_ADR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_ADR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TYP_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TYP_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TYP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_ADR_MASK (0x00FFF800u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_ADR_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_ADR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_MASK (0x03000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_RESETVAL (0x00000000u)
/*----ts_mask Tokens----*/
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_4LSB (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_ALL (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_MASK_RSVD_MSK (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_MASK (0x1C000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_RESETVAL (0x00000000u)
/*----ts_frmt Tokens----*/
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_NO_TS (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_NORM_TS (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_GSM_UL (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_GEN_PKT (0x00000003u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_ETHERNET (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_CTR_PKT (0x00000005u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_TS_FRMT_GSM_DL (0x00000006u)


#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_MASK (0xC0000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_SHIFT (0x0000001Eu)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_RESETVAL (0x00000000u)
/*----ps_insert Tokens----*/
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_NO_PS (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_ADR_PS (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_ALL_PS (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_PS_INSERT_RSVD_PS (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_OBSAI_HDR_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_cw_chan_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_RESETVAL (0x00000000u)
/*----crc_rvrs Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_NO_RVRS (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_RVRS_BITS (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_RVRS_BYTES (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_RVRS_RVRS_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_MASK (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_RESETVAL (0x00000000u)
/*----delin_sel Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_NULL (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_FAST_ETH (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_HYP_FRM (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DELIN_SEL_HDLC (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_RESETVAL (0x00000000u)
/*----crc_sel Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_NO_CRC (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_CRC32 (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_CRC16 (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_SEL_CRC8 (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_INIT_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_INIT_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_INIT_RESETVAL (0x00000000u)
/*----crc_init Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_INIT_ZEROS (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_CRC_INIT_ONES (0x00000001u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_HF_LUT_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_HF_LUT_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_HF_LUT_EN_RESETVAL (0x00000000u)
/*----hf_lut_en Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_HF_LUT_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_HF_LUT_EN_ENABLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_MASK (0x00000300u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_RESETVAL (0x00000000u)
/*----dlmt_imux Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_MASK (0x00000C00u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_RESETVAL (0x00000000u)
/*----dlmt_omux Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_MASK (0x00003000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_RESETVAL (0x00000000u)
/*----imux Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_IMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_MASK (0x0000C000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_RESETVAL (0x00000000u)
/*----rt_ctl Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_ADD8 (0x00000003u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_ADD16 (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_INSERTPE (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RT_CTL_FWD_RM (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_BYTE_EN_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_BYTE_EN_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_BYTE_EN_RESETVAL (0x0000FFFFu)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_CHAN_CFG_RESETVAL (0xFFFF0000u)

/* ail_pe_cpri_hypfrm0_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM0_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM0_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM0_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_hypfrm1_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM1_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM1_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM1_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_hypfrm2_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM2_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM2_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM2_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_hypfrm3_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM3_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM3_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM3_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_hypfrm4_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM4_LUT_CFG_HF_EN_MASK (0x003FFFFFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM4_LUT_CFG_HF_EN_SHIFT (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CPRI_HYPFRM4_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_null_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_NULL_CFG_NULL_CHAR_MASK (0x000001FFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_NULL_CFG_NULL_CHAR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_NULL_CFG_NULL_CHAR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CPRI_NULL_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_crc_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_CRC_CFG_CRC8_POLY_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PE_CPRI_CRC_CFG_CRC8_POLY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CRC_CFG_CRC8_POLY_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CPRI_CRC_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_sts */

#define CSL_IQN_AIL_AIL_PE_CPRI_STS_IN_PKT_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_CPRI_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_STS_IN_PKT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_CPRI_STS_RESETVAL (0x00000000u)

/* ail_pe_cpri_4b5b_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_BIT_ORDER_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_BIT_ORDER_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_BIT_ORDER_RESETVAL (0x00000000u)
/*----bit_order Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_BIT_ORDER_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_BIT_ORDER_BIT_SWAP (0x00000001u)

#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_SSD_ORDER_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_SSD_ORDER_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_SSD_ORDER_RESETVAL (0x00000000u)
/*----ssd_order Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_SSD_ORDER_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_SSD_ORDER_SWAP_NIBBLES (0x00000001u)


#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_MASK (0x0000C000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_RESETVAL (0x00000000u)
/*----hdr Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_NO_PREAMBLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_7 (0x00000001u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_8 (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_RES (0x00000003u)

#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_PREAMBLE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_SOP_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_SOP_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_HDR_SOP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_4B5B_CFG_RESETVAL (0x00000000u)

/* ail_pe_cpri_cw_lut_cfg */

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_CHAN_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_CHAN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_EN_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_EN_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_EN_RESETVAL (0x00000000u)
/*----cw_en Tokens----*/
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_CW_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PE_CPRI_CW_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_chan_cfg */

#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_AXC_OFFSET_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_AXC_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_AXC_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_RAD_STD_MASK (0x70000000u)
#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_RAD_STD_SHIFT (0x0000001Cu)
#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_RAD_STD_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_axc0_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_GRP_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_GRP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_GRP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_EN_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_EN_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_EN_RESETVAL (0x00000000u)
/*----cont_lut_en Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_EN_CONT_DIS (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_CONT_LUT_EN_CONT_EN (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_CPRI_AXC0_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_bub_fsm_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM_CFG_KNC_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM_CFG_KNC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM_CFG_KNC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_bub_fsm2_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_INT_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_INT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_INT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_FRAC_MASK (0x3FFC0000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_FRAC_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_GAP_FRAC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_BUB_FSM2_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_tdm_fsm_cfg */


#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_NCONT_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_NCONT_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_NCONT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_STRT_LUT_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_STRT_LUT_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_STRT_LUT_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_TDM_FSM_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_radstd_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_CFG_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_CFG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_CFG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_radstd1_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_BFRM_OFFSET_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_BFRM_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_BFRM_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_HFRM_OFFSET_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_HFRM_OFFSET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_HFRM_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD1_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_radstd2_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD2_CFG_BFRM_NUM_MASK (0x0003FFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD2_CFG_BFRM_NUM_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD2_CFG_BFRM_NUM_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD2_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_radstd_sts */

#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_STS_ON_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_STS_ON_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_STS_ON_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_RADSTD_STS_RESETVAL (0x00000000u)

/* ail_pd_cpri_axc_tdm_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_AXC_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_AXC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_AXC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_AXC_TDM_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_cw_chan_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----chan_en Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CHAN_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CHAN_EN_ENABLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HF_LUT_EN_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HF_LUT_EN_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HF_LUT_EN_RESETVAL (0x00000000u)
/*----hf_lut_en Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HF_LUT_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HF_LUT_EN_ENABLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_MASK (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_RESETVAL (0x00000000u)
/*----delin_sel Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_NULL (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_FAST_ETH (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_HYP_FRM (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DELIN_SEL_HDLC (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_MASK (0x00000030u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_RESETVAL (0x00000000u)
/*----crc_sel Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_NO_CRC (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_CRC32 (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_CRC16 (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_SEL_CRC8 (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_INIT_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_INIT_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_INIT_RESETVAL (0x00000000u)
/*----crc_init Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_INIT_ZEROS (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_CRC_INIT_ONES (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_MASK (0x00000300u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_RESETVAL (0x00000000u)
/*----dlmt_imux Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_IMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_MASK (0x00000C00u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_RESETVAL (0x00000000u)
/*----dlmt_omux Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_DLMT_OMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_MASK (0x00003000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_RESETVAL (0x00000000u)
/*----qwd_omux Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_NO_SWAP (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_SWAP_NIBBLES (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_SWAP_NIBBLE_BITS (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_QWD_OMUX_SWAP_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_MASK (0x0000C000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_RESETVAL (0x00000000u)
/*----hdlc_rvrs_crc Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_RVRS_CRC_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_RVRS_CRC_BIT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_RVRS_CRC_BYTE (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_HDLC_RVRS_CRC_RVRS_CRC_BOTH (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_BYTE_EN_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_BYTE_EN_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_BYTE_EN_RESETVAL (0x0000FFFFu)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_CHAN_CFG_RESETVAL (0xFFFF0000u)

/* ail_pd_cpri_cw_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_CHAN_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_CHAN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_EN_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_EN_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_EN_RESETVAL (0x00000000u)
/*----cw_en Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_CW_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_CPRI_CW_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_hypfrm0_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM0_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM0_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM0_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_hypfrm1_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM1_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM1_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM1_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_hypfrm2_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM2_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM2_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM2_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_hypfrm3_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM3_LUT_CFG_HF_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM3_LUT_CFG_HF_EN_SHIFT (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM3_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_hypfrm4_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM4_LUT_CFG_HF_EN_MASK (0x003FFFFFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM4_LUT_CFG_HF_EN_SHIFT (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_HYPFRM4_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_null_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_NULL_CFG_NULL_CHAR_MASK (0x000001FFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_NULL_CFG_NULL_CHAR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_NULL_CFG_NULL_CHAR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_NULL_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_crc_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_POLY_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_POLY_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_POLY_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_COMP_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_COMP_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_CRC8_COMP_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_CPRI_CRC_CFG_RESETVAL (0x00000000u)

/* ail_pd_cpri_4b5b_cfg */

#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_RESETVAL (0x00000000u)
/*----hdr Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_NO_STRIP (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_STRIP_7 (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_STRIP_8 (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_HDR_NO_CRC (0x00000003u)

#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_BIT_ORDER_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_BIT_ORDER_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_BIT_ORDER_RESETVAL (0x00000000u)
/*----bit_order Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_BIT_ORDER_NORMAL (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_BIT_ORDER_REVERSE (0x00000001u)

#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_SSD_ORDER_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_SSD_ORDER_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_SSD_ORDER_RESETVAL (0x00000000u)
/*----ssd_order Tokens----*/
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_SSD_ORDER_NORMAL (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_SSD_ORDER_REVERSE (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_CPRI_4B5B_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_gsm_bbhop_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_GSM_BBHOP_CFG_OFF_STB_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_GSM_BBHOP_CFG_OFF_STB_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_GSM_BBHOP_CFG_OFF_STB_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_GSM_BBHOP_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_rp3_01_sts */

#define CSL_IQN_AIL_AIL_PD_OBSAI_RP3_01_STS_CAPTURE_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RP3_01_STS_CAPTURE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RP3_01_STS_CAPTURE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_RP3_01_STS_RESETVAL (0x00000000u)

/* ail_pd_obsai_radstd_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_WDOG_TC_MASK (0x00000FFFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_WDOG_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_WDOG_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_AXCOFFSET_WIN_MASK (0x0FFF0000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_AXCOFFSET_WIN_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_AXCOFFSET_WIN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_RADSTD_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_radt_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_RADT_CFG_TC_MASK (0x01FFFFFFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADT_CFG_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_RADT_CFG_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_RADT_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_frm_tc_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_TC_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_TC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_SC_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_SC_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_SYM_TC_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_SYM_TC_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_SYM_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_TC_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_chan_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_WDOG_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_WDOG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_WDOG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_GSM_UL_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_GSM_UL_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_GSM_UL_RESETVAL (0x00000000u)
/*----gsm_ul Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_GSM_UL_OTHER (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_GSM_UL_GSM_UL (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_CHAN_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_route_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TS_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TS_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TYPE_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TYPE_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_TYPE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_ADR_MASK (0x00FFF800u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_ADR_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_ADR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_MASK (0x30000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_SHIFT (0x0000001Cu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_RESETVAL (0x00000000u)
/*----chan_mask Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_NONE (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_4LSB (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_ALL (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_MASK_RESERVED (0x00000003u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_EN_MASK (0x80000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_EN_SHIFT (0x0000001Fu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_CHAN_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_ROUTE_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_type_lut_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_RESETVAL (0x00000000u)
/*----ts_format Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_NO_TS (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_NORM_TS (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_GSM (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_GEN_PKT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_ETHERNET (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_TS_FORMAT_CTR_PKT (0x00000005u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_TYPE_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_TYPE_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_TYPE_RESETVAL (0x00000000u)
/*----crc_type Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_TYPE_32BIT_CRC (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_TYPE_16BIT_CRC (0x00000001u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_EN_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_EN_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_HDR_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_HDR_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_HDR_RESETVAL (0x00000000u)
/*----crc_hdr Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_HDR_CRC_HDR_ON (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_CRC_HDR_CRC_HDR_OFF (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_OBSAI_PKT_EN_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_OBSAI_PKT_EN_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_OBSAI_PKT_EN_RESETVAL (0x00000000u)
/*----obsai_pkt_en Tokens----*/
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_OBSAI_PKT_EN_OBSAI_AXC (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_OBSAI_PKT_EN_OBSAI_PKT (0x00000001u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_ENET_STRIP_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_ENET_STRIP_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_ENET_STRIP_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_RST_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_RST_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RP3_01_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_TYPE_LUT_CFG_RESETVAL (0x00000000u)

/* ail_pd_obsai_frm_msg_tc_cfg */

#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_MSG_TC_CFG_TC_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_MSG_TC_CFG_TC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_MSG_TC_CFG_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_OBSAI_FRM_MSG_TC_CFG_RESETVAL (0x00000000u)

/* ail_phy_glb_cfg */

#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_RESETVAL (0x00000000u)
/*----link_rate Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_8X (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_4X (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_2X (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_5X (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_10X (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_LINK_RATE_16X (0x00000005u)

#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_OBSAI_CPRI_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_OBSAI_CPRI_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----obsai_cpri Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_OBSAI_CPRI_OBSAI (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_SHORT_FRM_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_SHORT_FRM_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_SHORT_FRM_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_GLB_CFG_RESETVAL (0x00000000u)

/* ail_phy_rt_cfg */

#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_MASK (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_RESETVAL (0x00000000u)
/*----config Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_FWDG_MODE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_AGGR_MODE (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_TRANS_MODE (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CONFIG_CPRI_ULNK_MODE (0x00000003u)

#define CSL_IQN_AIL_AIL_PHY_RT_CFG_EM_EN_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_EM_EN_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_EM_EN_RESETVAL (0x00000000u)
/*----em_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_EM_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_EM_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_MASK (0x000000E0u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_RESETVAL (0x00000000u)
/*----ci_link Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_CI_LINK_SEL_LINK7 (0x00000007u)

#define CSL_IQN_AIL_AIL_PHY_RT_CFG_BF_DELAY_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_BF_DELAY_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RT_CFG_BF_DELAY_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RT_CFG_RESETVAL (0x00000000u)

/* ail_phy_rt_dp_sts */

#define CSL_IQN_AIL_AIL_PHY_RT_DP_STS_VALUE_MASK (0x000001FFu)
#define CSL_IQN_AIL_AIL_PHY_RT_DP_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_DP_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RT_DP_STS_RESETVAL (0x00000000u)

/* ail_phy_rt_hdr_err_sts */

#define CSL_IQN_AIL_AIL_PHY_RT_HDR_ERR_STS_CHAN_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PHY_RT_HDR_ERR_STS_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RT_HDR_ERR_STS_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RT_HDR_ERR_STS_RESETVAL (0x00000000u)

/* ail_phy_ci_lut_cfg */

#define CSL_IQN_AIL_AIL_PHY_CI_LUT_CFG_SEL_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUT_CFG_SEL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUT_CFG_SEL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CI_LUT_CFG_RESETVAL (0x00000000u)

/* ail_phy_co_lut_cfg */

#define CSL_IQN_AIL_AIL_PHY_CO_LUT_CFG_SEL_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUT_CFG_SEL_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUT_CFG_SEL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CO_LUT_CFG_RESETVAL (0x00000000u)

/* ail_phy_ci_luta_cfg */

#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_COUNT_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_COUNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_COUNT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_OFFSET_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_OFFSET_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_MASK (0x00001800u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_RESETVAL (0x00000000u)
/*----smpl_type Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_7BIT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_8BIT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_15BIT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_TYPE_16BIT (0x00000003u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_LAST_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_LAST_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_SMPL_LAST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CI_LUTA_CFG_RESETVAL (0x00000000u)

/* ail_phy_ci_lutb_cfg */

#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_COUNT_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_COUNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_COUNT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_OFFSET_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_OFFSET_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_MASK (0x00001800u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_RESETVAL (0x00000000u)
/*----smpl_type Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_7BIT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_8BIT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_15BIT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_TYPE_16BIT (0x00000003u)

#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_LAST_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_LAST_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_SMPL_LAST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CI_LUTB_CFG_RESETVAL (0x00000000u)

/* ail_phy_co_luta_cfg */

#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_COUNT_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_COUNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_COUNT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_OFFSET_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_OFFSET_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_MASK (0x00001800u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_RESETVAL (0x00000000u)
/*----smpl_type Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_7BIT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_8BIT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_15BIT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_TYPE_16BIT (0x00000003u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_LAST_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_LAST_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_SMPL_LAST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CO_LUTA_CFG_RESETVAL (0x00000000u)

/* ail_phy_co_lutb_cfg */

#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_COUNT_MASK (0x0000003Fu)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_COUNT_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_COUNT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_OFFSET_MASK (0x000007C0u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_OFFSET_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_MASK (0x00001800u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_RESETVAL (0x00000000u)
/*----smpl_type Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_7BIT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_8BIT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_15BIT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_TYPE_16BIT (0x00000003u)

#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_LAST_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_LAST_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_SMPL_LAST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_CO_LUTB_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CFG_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_CFG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CFG_EN_RESETVAL (0x00000000u)
/*----en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_CFG_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CFG_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_TM_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_ctrl_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_FLUSH_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_FLUSH_RESETVAL (0x00000000u)
/*----flush Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_FLUSH_NO_ACTION (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_FLUSH_FLUSH_FIFO (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_IDLE_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_IDLE_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_IDLE_RESETVAL (0x00000000u)
/*----idle Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_IDLE_NO_ACTION (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_IDLE_IDLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESYNC_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESYNC_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESYNC_RESETVAL (0x00000000u)
/*----resync Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESYNC_NO_ACTION (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESYNC_RESYNC (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_LOS_EN_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_LOS_EN_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_LOS_EN_RESETVAL (0x00000000u)
/*----los_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_LOS_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_LOS_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_TM_CTRL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_scr_ctrl_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SEED_VALUE_MASK (0x0000007Fu)
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SEED_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SEED_VALUE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SCR_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SCR_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SCR_EN_RESETVAL (0x00000000u)
/*----scr_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SCR_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_SCR_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_TM_SCR_CTRL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_l1_inband_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RST_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RST_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RAI_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RAI_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_SDI_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_SDI_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOS_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOS_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOF_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOF_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_L1_INBAND_LOF_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_l1_inband_en_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_RAIRX_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_RAIRX_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_RAIRX_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFRX_EN_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFRX_EN_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFRX_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFERR_EN_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFERR_EN_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOFERR_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSRX_EN_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSRX_EN_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSRX_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSERR_EN_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSERR_EN_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RAI_LOSERR_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFRX_EN_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFRX_EN_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFRX_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFERR_EN_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFERR_EN_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOF_LOFERR_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSRX_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSRX_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSRX_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSERR_EN_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSERR_EN_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_LOS_LOSERR_EN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_SDI_RSTRX_EN_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_SDI_RSTRX_EN_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_SDI_RSTRX_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_L1_INBAND_EN_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_loserr_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_RESETVAL (0x00000000u)
/*----link_loserr Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_LINK_LOSERR_LOSERR7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_LOSERR_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_loferr_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_RESETVAL (0x00000000u)
/*----link_loferr Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_LINK_LOFERR_LOFERR7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_LOFERR_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_losrx_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_RESETVAL (0x00000000u)
/*----link_losrx Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_LINK_LOSRX_LOSRX7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_LOSRX_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_lofrx_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_RESETVAL (0x00000000u)
/*----link_lofrx Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_LINK_LOFRX_LOFRX7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_LOFRX_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_rairx_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RESETVAL (0x00000000u)
/*----link_rairx Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_LINK_RAIRX_RAIRX7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_RAIRX_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_rstrx_sel_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_MASK (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RESETVAL (0x00000000u)
/*----link_rstrx Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX0 (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX1 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX3 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX4 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX5 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX6 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_LINK_RSTRX_RSTRX7 (0x00000007u)


#define CSL_IQN_AIL_AIL_PHY_TM_RSTRX_SEL_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_hfn_sts */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_HFN_STS_HFN_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_HFN_STS_HFN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_HFN_STS_HFN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_HFN_STS_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_ptrp_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PTRP_CFG_PTR_P_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PTRP_CFG_PTR_P_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PTRP_CFG_PTR_P_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PTRP_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_startup_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_STARTUP_CFG_STARTUP_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_STARTUP_CFG_STARTUP_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_STARTUP_CFG_STARTUP_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_STARTUP_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_version_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_VERSION_CFG_PROT_VERS_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_VERSION_CFG_PROT_VERS_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_VERSION_CFG_PROT_VERS_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_VERSION_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_sts */


#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_MASK (0x000001E0u)
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_RESETVAL (0x00000001u)
/*----frm_state Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_OFF (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_IDLE (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_RE_SYNC (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_TM_STS_FRM_STATE_FRAME_SYNC (0x00000008u)


#define CSL_IQN_AIL_AIL_PHY_TM_STS_RESETVAL (0x00000020u)

/* ail_phy_tm_cpri_portid_a_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_0_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_1_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_1_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z52_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_0_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_0_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_1_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_1_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_Z116_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_A_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_portid_b_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_0_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_1_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_1_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z180_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_0_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_0_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_1_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_1_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_Z244_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_PORTID_B_CFG_RESETVAL (0x00000000u)

/* ail_phy_tm_cpri_scr_ctrl_cfg */

#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_SCR_CTRL_CFG_SEED_VALUE_MASK (0x7FFFFFFFu)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_SCR_CTRL_CFG_SEED_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_SCR_CTRL_CFG_SEED_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_TM_CPRI_SCR_CTRL_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_cfg */

#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RX_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RX_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RX_EN_RESETVAL (0x00000000u)
/*----rx_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RX_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RX_EN_ENABLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_RM_CFG_DATA_TRC_SEL_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_DATA_TRC_SEL_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_DATA_TRC_SEL_RESETVAL (0x00000000u)
/*----data_trc_sel Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_DATA_TRC_SEL_RAW_DATA_SEL (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_DATA_TRC_SEL_FRM_DATA_SEL (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RST_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RST_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RST_EN_RESETVAL (0x00000000u)
/*----rst_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RST_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RST_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_dp_cfg */


#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_MASK (0x0000001Cu)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_RESETVAL (0x00000000u)
/*----force_rx_state Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST4 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST5 (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST0 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST1 (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST2 (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_ST3 (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_FORCE_RX_STATE_OFF (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_ERROR_SUPPRESS_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_ERROR_SUPPRESS_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_ERROR_SUPPRESS_RESETVAL (0x00000000u)
/*----error_suppress Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_ERROR_SUPPRESS_ALLOW (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_ERROR_SUPPRESS_SUPPRESS (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_SD_AUTO_ALIGN_EN_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_SD_AUTO_ALIGN_EN_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_SD_AUTO_ALIGN_EN_RESETVAL (0x00000000u)
/*----sd_auto_align_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_SD_AUTO_ALIGN_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_SD_AUTO_ALIGN_EN_ENABLE (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_LCV_UNSYNC_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_LCV_UNSYNC_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_LCV_UNSYNC_EN_RESETVAL (0x00000000u)
/*----lcv_unsync_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_LCV_UNSYNC_EN_NO_EFFECT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_LCV_UNSYNC_EN_ENABLE_TRANSITION (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_DP_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_lcv_ctrl_cfg */

#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_EN_RESETVAL (0x00000000u)
/*----en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_EN_ENABLED (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_LOS_DET_THOLD_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_LOS_DET_THOLD_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_LOS_DET_THOLD_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CTRL_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_fsm_sync_cfg */

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_SYNC_T_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_SYNC_T_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_SYNC_T_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_FRAME_SYNC_T_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_FRAME_SYNC_T_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_FRAME_SYNC_T_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_SYNC_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_fsm_unsync_cfg */

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_UNSYNC_T_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_UNSYNC_T_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_UNSYNC_T_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_FRAME_UNSYNC_T_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_FRAME_UNSYNC_T_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_FRAME_UNSYNC_T_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_FSM_UNSYNC_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_dscr_ctrl_cfg */


#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_SCR_EN_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_SCR_EN_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_SCR_EN_RESETVAL (0x00000000u)
/*----scr_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_SCR_EN_DISABLE (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_SCR_EN_ENABLE (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_DSCR_CTRL_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_clk_det_cfg */

#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_EN_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_EN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_EN_RESETVAL (0x00000000u)
/*----wd_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_EN_ENABLED (0x00000001u)

#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_CQ_EN_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_CQ_EN_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_CQ_EN_RESETVAL (0x00000000u)
/*----cq_en Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_CQ_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_CQ_EN_ENABLED (0x00000001u)


#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_WRAP_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_WRAP_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_WD_WRAP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_MON_WRAP_MASK (0xFFFF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_MON_WRAP_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_MON_WRAP_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CLK_DET_CFG_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_hfn_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_HFN_STS_HFN_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_HFN_STS_HFN_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_HFN_STS_HFN_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_HFN_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_bfn_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_LOW_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_LOW_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_LOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_HIGH_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_HIGH_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_HIGH_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_BFN_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_state_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_HFSYNC_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_HFSYNC_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_HFSYNC_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_LOF_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_LOF_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_LOF_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STATE_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_version_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_VERSION_STS_VALUE_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_VERSION_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_VERSION_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_VERSION_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_startup_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STARTUP_STS_VALUE_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STARTUP_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STARTUP_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_STARTUP_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_l1_inband_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RST_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RST_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RAI_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RAI_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_SDI_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_SDI_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOS_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOS_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOF_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOF_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_LOF_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_L1_INBAND_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_ptrp_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PTRP_STS_PNTR_P_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PTRP_STS_PNTR_P_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PTRP_STS_PNTR_P_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PTRP_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_scr_seed_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_SCR_SEED_STS_VALUE_MASK (0x7FFFFFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_SCR_SEED_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_SCR_SEED_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_SCR_SEED_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_sts */


#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_MASK (0x0000FC00u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_RESETVAL (0x00000008u)
/*----rx_sync Tokens----*/
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST0 (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST1 (0x00000004u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST2 (0x00000002u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST3 (0x00000001u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST4 (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_STS_RX_SYNC_ST5 (0x00000020u)


#define CSL_IQN_AIL_AIL_PHY_RM_STS_RESETVAL (0x00002000u)

/* ail_phy_rm_lcv_los_cnt_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_LCV_LOS_CNT_STS_NUM_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_LOS_CNT_STS_NUM_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_LOS_CNT_STS_NUM_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_LCV_LOS_CNT_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_lcv_cnt_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CNT_STS_VALUE_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CNT_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CNT_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_LCV_CNT_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_clk_qual_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CLK_QUAL_STS_VALUE_MASK (0x0000FFFFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_QUAL_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CLK_QUAL_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_CLK_QUAL_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_obsai_scr_seed_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_OBSAI_SCR_SEED_STS_VALUE_MASK (0x0000007Fu)
#define CSL_IQN_AIL_AIL_PHY_RM_OBSAI_SCR_SEED_STS_VALUE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_OBSAI_SCR_SEED_STS_VALUE_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PHY_RM_OBSAI_SCR_SEED_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_portid_a_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_0_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_1_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_1_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z52_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_0_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_0_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_1_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_1_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_Z116_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_A_STS_RESETVAL (0x00000000u)

/* ail_phy_rm_cpri_portid_b_sts */

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_0_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_1_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_1_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z180_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_0_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_0_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_1_MASK (0xFF000000u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_1_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_Z244_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PHY_RM_CPRI_PORTID_B_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_e_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_e_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_e_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_e_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_E_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_f_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_f_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_f_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_f_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_SI_ING_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_F_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_g_1_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_G_1_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_h_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_STS_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_STS_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_STS_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_h_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_SET_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_SET_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_SET_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_h_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_CLR_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_CLR_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_CLR_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_STS_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_STS_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_STS_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_SET_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_SET_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_SET_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_STS_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_STS_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_STS_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_SET_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_SET_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_SET_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_CLR_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_h_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_ENABLED_STS_SI_ING_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_H_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_d_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_d_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_d_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_d_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_D_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_e_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_e_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_e_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_e_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_SI_EGR_CTL_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_E_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_f_1_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_F_1_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_g_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_STS_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_STS_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_STS_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_g_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_SET_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_SET_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_SET_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_g_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_CLR_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_CLR_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_CLR_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_STS_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_SET_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_CLR_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_g_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_ENABLED_STS_SI_EGR_CTL_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_G_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_vbusclk_orig_reg */

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_0_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_1_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_1_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_2_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_2_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_3_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_3_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_4_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_4_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_5_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_5_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_6_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_6_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_6_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_7_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_7_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_8_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_8_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_8_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_9_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_9_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_9_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_10_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_10_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_10_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_11_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_11_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_11_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_12_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_12_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_12_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_13_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_13_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_13_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_14_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_14_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_14_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_15_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_15_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_15_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_16_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_16_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_16_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_17_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_17_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_17_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_18_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_18_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_18_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_19_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_19_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_ORIG_EE_19_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_VBUSCLK_ORIG_REG_RESETVAL (0x00000000u)

/* ail_rm_0_raw_sts */

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_rm_0_raw_set */

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_rm_0_raw_clr */

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_rm_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_rm_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_rm_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_rm_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_rm_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_rm_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_rm_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_rm_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE0_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE0_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE1_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE1_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE2_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE2_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE3_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE3_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE4_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE4_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE5_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE5_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_STATUS_STATE5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_NUM_LOS_DET_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_NUM_LOS_DET_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_NUM_LOS_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LCV_DET_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LCV_DET_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LCV_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_FRAME_BNDRY_DET_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_FRAME_BNDRY_DET_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_FRAME_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_BLOCK_BNDRY_DET_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_BLOCK_BNDRY_DET_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_BLOCK_BNDRY_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P5_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P5_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P7_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P7_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_MISSING_K28P7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_K30P7_DET_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_K30P7_DET_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_K30P7_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOC_DET_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOC_DET_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOC_DET_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RX_FIFO_OVF_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RX_FIFO_OVF_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RX_FIFO_OVF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOS_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOS_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOF_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOF_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_LOF_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RAI_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RAI_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_SDI_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_SDI_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RST_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RST_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOS_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOS_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_HFNSYNC_STATE_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_HFNSYNC_STATE_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_HFNSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_STATE_MASK (0x01000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_STATE_SHIFT (0x00000018u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_LOF_STATE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_RST_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_RST_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RM_RST_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RM_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_rt_tm_0_raw_sts */

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_rt_tm_0_raw_set */

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_rt_tm_0_raw_clr */

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_rt_tm_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_HDR_ERROR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_HDR_ERROR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_HDR_ERROR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_EM_INSERT_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_EM_INSERT_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_EM_INSERT_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNFL_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNFL_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_OVFL_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_OVFL_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_OVFL_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_FRM_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_FRM_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNALIGN_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNALIGN_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_UNALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_AGGR_STATE_INFO_MASK (0x000003C0u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_AGGR_STATE_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RT_AGGR_STATE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_SYNC_STATUS_CHANGE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_INACTIVE_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_INACTIVE_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_INACTIVE_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_MODIFIED_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_MODIFIED_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_DELTA_MODIFIED_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FRAME_MISALIGN_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FRAME_MISALIGN_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FRAME_MISALIGN_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FIFO_UNDEFLOW_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FIFO_UNDEFLOW_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_FIFO_UNDEFLOW_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_TM_FAIL_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_TM_FAIL_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_TM_FAIL_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_RT_TM_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ci_co_0_raw_sts */

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_ci_co_0_raw_set */

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_ci_co_0_raw_clr */

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ci_co_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CI_TBLTOOLONG_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CI_TBLTOOLONG_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CI_TBLTOOLONG_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CO_TBLTOOLONG_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CO_TBLTOOLONG_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_CO_TBLTOOLONG_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_CI_CO_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_sysclk_phy_orig_reg */

#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_0_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_1_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_1_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_2_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_2_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_ORIG_EE_2_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_SYSCLK_PHY_ORIG_REG_RESETVAL (0x00000000u)

/* ail_pd_0_raw_sts */

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_pd_0_raw_set */

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_pd_0_raw_clr */

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_pd_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_FRM_WIN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_SOP_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_SOP_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_MISS_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_TS_WDOG_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_AXC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_SOC_RST_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_ROUTE_FAIL_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CAPTURE_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_RP3_01_CRC_FAIL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_GSM_OFF_STB_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_CPRI_CW_4B5B_CHAR_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_MASK (0x02000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_SHIFT (0x00000019u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_MASK (0x04000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_SHIFT (0x0000001Au)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_MASK (0x08000000u)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_SHIFT (0x0000001Bu)
#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_PD_EE_OBSAI_SOF_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_1_raw_sts */

#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_RAW_STS_RESETVAL (0x00000000u)

/* ail_pd_1_raw_set */

#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_RAW_SET_RESETVAL (0x00000000u)

/* ail_pd_1_raw_clr */

#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_RAW_CLR_RESETVAL (0x00000000u)

/* ail_pd_1_ev0_en_sts */

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_1_ev0_en_set */

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_1_ev0_en_clr */

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_1_ev1_en_sts */

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_1_ev1_en_set */

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_1_ev1_en_clr */

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_1_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_1_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_MASK (0x000000FFu)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_MASK (0x0000FF00u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_TDM_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_MASK (0x00FF0000u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_PD_EE_CPRI_RADSTD_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PD_1_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_2_0_raw_sts */


#define CSL_IQN_AIL_AIL_PD_2_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_pd_2_0_raw_set */


#define CSL_IQN_AIL_AIL_PD_2_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_pd_2_0_raw_clr */


#define CSL_IQN_AIL_AIL_PD_2_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev0_en_sts */


#define CSL_IQN_AIL_AIL_PD_2_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev0_en_set */


#define CSL_IQN_AIL_AIL_PD_2_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev0_en_clr */


#define CSL_IQN_AIL_AIL_PD_2_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev1_en_sts */


#define CSL_IQN_AIL_AIL_PD_2_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev1_en_set */


#define CSL_IQN_AIL_AIL_PD_2_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev1_en_clr */


#define CSL_IQN_AIL_AIL_PD_2_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev0_enabled_sts */


#define CSL_IQN_AIL_AIL_PD_2_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_2_0_ev1_enabled_sts */


#define CSL_IQN_AIL_AIL_PD_2_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_2_1_raw_sts */


#define CSL_IQN_AIL_AIL_PD_2_1_RAW_STS_RESETVAL (0x00000000u)

/* ail_pd_2_1_raw_set */


#define CSL_IQN_AIL_AIL_PD_2_1_RAW_SET_RESETVAL (0x00000000u)

/* ail_pd_2_1_raw_clr */


#define CSL_IQN_AIL_AIL_PD_2_1_RAW_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev0_en_sts */


#define CSL_IQN_AIL_AIL_PD_2_1_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev0_en_set */


#define CSL_IQN_AIL_AIL_PD_2_1_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev0_en_clr */


#define CSL_IQN_AIL_AIL_PD_2_1_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev1_en_sts */


#define CSL_IQN_AIL_AIL_PD_2_1_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev1_en_set */


#define CSL_IQN_AIL_AIL_PD_2_1_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev1_en_clr */


#define CSL_IQN_AIL_AIL_PD_2_1_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev0_enabled_sts */


#define CSL_IQN_AIL_AIL_PD_2_1_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pd_2_1_ev1_enabled_sts */


#define CSL_IQN_AIL_AIL_PD_2_1_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pe_0_raw_sts */

#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_pe_0_raw_set */

#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_pe_0_raw_clr */

#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_pe_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_pe_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_pe_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_pe_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_pe_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_pe_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_pe_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_pe_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_NULL_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_MASK (0x000000F0u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_4B5B_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_MASK (0x00000F00u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_MASK (0x0000F000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HDLC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_MASK (0x000F0000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_CPRI_CW_HYPFM_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_PE_EE_OFIFO_OFLOW_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_PE_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ail_si_0_raw_sts */

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_ail_si_0_raw_set */

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_ail_si_0_raw_clr */

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ail_si_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_UAT_PI_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_UAT_PI_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_UAT_PI_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_TDM_LUT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_TDM_LUT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_TDM_LUT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_BUB_FSM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_BUB_FSM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_CPRI_BUB_FSM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_PHY_SYNC_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_PHY_SYNC_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_PHY_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_MULTRULEFIRE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_DBM_WRAP_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_DBM_WRAP_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_OBSAI_DBM_WRAP_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_AIL_SI_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_a_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_a_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_a_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_a_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_b_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_b_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_b_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_b_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_PKT_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_PKT_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_SI_ING_CTL_FIFO_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_B_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_STS_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_SET_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_CLR_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_STS_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_SET_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_STS_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_SET_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_0_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_STS_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_STS_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_STS_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_SET_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_SET_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_SET_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_CLR_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_CLR_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_CLR_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_STS_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_STS_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_STS_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_SET_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_SET_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_SET_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_STS_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_STS_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_STS_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_SET_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_SET_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_SET_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_c_1_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_MASK (0xFFFFFFFFu)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_64_32_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SII_C_1_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_d_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_STS_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_STS_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_STS_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_d_raw_set */

#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_SET_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_SET_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_SET_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_d_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_CLR_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_CLR_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_CLR_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_STS_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_STS_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_STS_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_SET_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_SET_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_SET_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_STS_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_STS_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_STS_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_SET_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_SET_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_SET_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_CLR_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sii_d_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_ENABLED_STS_SI_ING_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SII_D_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_a_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_a_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_a_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_a_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_b_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_b_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_b_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_b_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_SI_EGR_CTL_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_B_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_c_raw_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_STS_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_STS_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_STS_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_c_raw_set */

#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_SET_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_SET_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_SET_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_c_raw_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_CLR_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_CLR_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_CLR_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_RAW_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev0_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev0_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev0_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev1_en_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_STS_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev1_en_set */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_SET_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_SET_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev1_en_clr */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_CLR_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_EN_CLR_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev0_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_ee_sie_c_ev1_enabled_sts */

#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_MASK (0x0000000Fu)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_ENABLED_STS_SI_EGR_CTL_ICC_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_EE_SIE_C_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* ail_sysclk_orig_reg */

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_0_MASK (0x00000001u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_0_SHIFT (0x00000000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_0_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_1_MASK (0x00000002u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_1_SHIFT (0x00000001u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_1_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_2_MASK (0x00000004u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_2_SHIFT (0x00000002u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_2_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_3_MASK (0x00000008u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_3_SHIFT (0x00000003u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_3_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_4_MASK (0x00000010u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_4_SHIFT (0x00000004u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_4_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_5_MASK (0x00000020u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_5_SHIFT (0x00000005u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_5_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_6_MASK (0x00000040u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_6_SHIFT (0x00000006u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_6_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_7_MASK (0x00000080u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_7_SHIFT (0x00000007u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_7_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_8_MASK (0x00000100u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_8_SHIFT (0x00000008u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_8_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_9_MASK (0x00000200u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_9_SHIFT (0x00000009u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_9_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_10_MASK (0x00000400u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_10_SHIFT (0x0000000Au)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_10_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_11_MASK (0x00000800u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_11_SHIFT (0x0000000Bu)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_11_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_12_MASK (0x00001000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_12_SHIFT (0x0000000Cu)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_12_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_13_MASK (0x00002000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_13_SHIFT (0x0000000Du)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_13_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_14_MASK (0x00004000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_14_SHIFT (0x0000000Eu)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_14_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_15_MASK (0x00008000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_15_SHIFT (0x0000000Fu)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_15_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_16_MASK (0x00010000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_16_SHIFT (0x00000010u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_16_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_17_MASK (0x00020000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_17_SHIFT (0x00000011u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_17_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_18_MASK (0x00040000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_18_SHIFT (0x00000012u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_18_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_19_MASK (0x00080000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_19_SHIFT (0x00000013u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_19_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_20_MASK (0x00100000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_20_SHIFT (0x00000014u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_20_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_21_MASK (0x00200000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_21_SHIFT (0x00000015u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_21_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_22_MASK (0x00400000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_22_SHIFT (0x00000016u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_22_RESETVAL (0x00000000u)

#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_23_MASK (0x00800000u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_23_SHIFT (0x00000017u)
#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_ORIG_EE_23_RESETVAL (0x00000000u)


#define CSL_IQN_AIL_AIL_SYSCLK_ORIG_REG_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
