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
* file: cslr_iqn_dio2.h
*
* Brief: This file contains the Register Description for iqn_dio2
*
*********************************************************************/
#ifndef CSLR_IQN_DIO2_H_
#define CSLR_IQN_DIO2_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for DIO2_SI_IQ_EFE_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_CHAN_CFG[16]; /* IFE DMA Channel Configuration Register */
    volatile Uint8 RSVD0[448];
    volatile Uint32 DIO2_IQ_EFE_CFG; /* EFE Rx to Tx Loopback Configuration Register */
    volatile Uint8 RSVD1[60];
    volatile Uint32 DIO2_IQ_EFE_GLOBAL_EN_SET_STB; /* Set Global Enable for EFE */
    volatile Uint32 DIO2_IQ_EFE_GLOBAL_EN_CLR_STB; /* Clear Global Enable for EFE */
    volatile Uint32 DIO2_IQ_EFE_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, EFE may still be closing out packets. */
    volatile Uint8 RSVD2[20];
    volatile Uint32 DIO2_IQ_EFE_CHAN_ON_STS; /* Gives current On/Off Status of every available AxC stream. One bit per channel (bit0:ch0 ~ bit31:ch31). Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD3[28];
    volatile Uint32 DIO2_IQ_EFE_IN_PKT_STS; /* Gives current In/Out packet state of packet channels only. Bits are always zero for AxC channels. Bit is activated at SOP, holds high mid packet, deactivates at EOP. Not used for DIO SI */
    volatile Uint8 RSVD4[28];
    volatile Uint32 DIO2_IQ_EFE_DMA_SYNC_STS; /* Gives current DMA SYNC state of AxC channels only. Bits are always zero for OBSAI control channels. Bit is activated when symbol 0 (non-TDD configuation) or first TDD-ON symbol (TDD configuration) of a frame is read from the Residual Buffer and the channel is in the CHAN_ON state. Bit is deactivated on the next SYM/SLOT boundary when channel is disabled or EFE is shutdown. Bit is deactivated immediately when the channel experiences starvation or a protocol error. */
} CSL_Iqn_dio2Dio2_si_iq_efe_config_groupRegs; /* Group containing EFE Channel Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_SI_IQ_EFE_RADIO_STANDARD_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_FRM_TC_CFG[8]; /* EFE Frame Count Register. There are 8 sets of these values in order to support 6 simultaneous radio standard variants */
    volatile Uint32 DIO2_IQ_EFE_RAD_STD_CFG[8]; /* EFE Radio Standard Configuration Register */
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG0[5]; /* Per symbol enables for TDD operation for Radio Standard 0. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD0[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG1[5]; /* Per symbol enables for TDD operation for Radio Standard 1. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD1[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG2[5]; /* Per symbol enables for TDD operation for Radio Standard 2. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD2[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG3[5]; /* Per symbol enables for TDD operation for Radio Standard 3. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD3[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG4[5]; /* Per symbol enables for TDD operation for Radio Standard 4. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD4[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG5[5]; /* Per symbol enables for TDD operation for Radio Standard 5. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD5[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG6[5]; /* Per symbol enables for TDD operation for Radio Standard 6. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD6[12];
    volatile Uint32 DIO2_IQ_EFE_TDD_EN_CFG7[5]; /* Per symbol enables for TDD operation for Radio Standard 7. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
} CSL_Iqn_dio2Dio2_si_iq_efe_radio_standard_groupRegs; /* Group of registers containing EFE configuration which is radio standard specific. Eight radio standards are supported, individual AxC channels are each assigned to one of these. */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_EFE_CHAN_AXC_OFFSET
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_CHAN_AXC_OFFSET_CFG; /* Sets the AXC offset for each channel. */
} CSL_Iqn_dio2Dio2_iq_efe_chan_axc_offsetRegs; /* Group containing IQ_EFE_CHAN_AXC_OFFSET RAM */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_EFE_FRM_SAMP_TC_MMR_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_FRM_SAMP_TC_CFG; /* EFE AxC Radio Framing Sample Terminal Count Configuration Register */
} CSL_Iqn_dio2Dio2_iq_efe_frm_samp_tc_mmr_ramRegs; /* Group containing Egress Sample Terminal Count Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_EFE_CHAN_TDM_LUT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_CHAN_TDM_LUT_CFG; /* EFE Channel TDM LUT configuration register */
} CSL_Iqn_dio2Dio2_iq_efe_chan_tdm_lutRegs; /* Group containing IQ_EFE_CHAN_TDM_LUT RAM */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_EFE_RADIO_STANDARD_SCHEDULER_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EFE_RAD_STD_SCH_CFG[8]; /* EFE Radio Standard Scheduler Configuration Register */
} CSL_Iqn_dio2Dio2_iq_efe_radio_standard_scheduler_groupRegs; /* Group containing EFE Channel Scheduler Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IFE_CHANNEL_CONFIGURATION_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IFE_CHAN_CFG[16]; /* IFE DMA Channel Configuration Register */
} CSL_Iqn_dio2Dio2_iq_ife_channel_configuration_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IFE_RADIO_STANDARD_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IFE_FRM_TC_CFG[8]; /* IFE Frame Count Register. There are 8 sets of these values in order to support 6 simultaneous radio standard variants */
    volatile Uint32 DIO2_IQ_IFE_RAD_STD_CFG[8]; /* IFE Radio Standard Configuration Register */
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG0[5]; /* Per symbol enables for TDD operation for Radio Standard 0. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD0[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG1[5]; /* Per symbol enables for TDD operation for Radio Standard 1. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD1[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG2[5]; /* Per symbol enables for TDD operation for Radio Standard 2. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD2[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG3[5]; /* Per symbol enables for TDD operation for Radio Standard 3. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD3[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG4[5]; /* Per symbol enables for TDD operation for Radio Standard 4. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD4[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG5[5]; /* Per symbol enables for TDD operation for Radio Standard 5. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD5[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG6[5]; /* Per symbol enables for TDD operation for Radio Standard 6. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
    volatile Uint8 RSVD6[12];
    volatile Uint32 DIO2_IQ_IFE_TDD_EN_CFG7[5]; /* Per symbol enables for TDD operation for Radio Standard 7. 5 MMRs of 32 bits each can accommodate 160 symbols. Enable for symbol 0 in bit 0 of first MMR and enable for symbol 159 in bit 31 of last MMR */
} CSL_Iqn_dio2Dio2_iq_ife_radio_standard_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IFE_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IFE_GLOBAL_EN_SET_STB; /* Set Global Enable for IFE */
    volatile Uint32 DIO2_IQ_IFE_GLOBAL_EN_CLR_STB; /* Clear Global Enable for IFE */
    volatile Uint32 DIO2_IQ_IFE_GLOBAL_EN_STS; /* Read Only status of global enable state. Even if this register is OFF, IFE may still be closing out packets. */
    volatile Uint8 RSVD0[4];
    volatile Uint32 DIO2_IQ_IFE_CHAN_ON_STS; /* Gives current On/Off Status of every available AxC stream. One bit per channel. Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status. Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. */
    volatile Uint8 RSVD1[12];
    volatile Uint32 DIO2_IQ_IFE_IN_PKT_STS; /* Gives current In/Out packet state of packet channels only. Bits are always zero for AxC channels. Bit is activated at SOP, holds high mid packet, deactivates at EOP. */
} CSL_Iqn_dio2Dio2_iq_ife_config_groupRegs; /* Group containing IFE Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IDC_GENERAL_STATUS_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IDC_STS; /* IDC Status register. */
    volatile Uint8 RSVD0[8];
    volatile Uint32 DIO2_IQ_IDC_INPKT_STS; /* Indicates when a channel is actively receiving a packet from the IFE */
} CSL_Iqn_dio2Dio2_iq_idc_general_status_groupRegs; /* Group containing IDC Status registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IDC_CONFIGURATION_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IDC_CFG; /* IDC Configuration Register */
} CSL_Iqn_dio2Dio2_iq_idc_configuration_groupRegs; /* Group containing IFE Radio Stanadard registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_IDC_CHANNEL_CONFIG_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IDC_CH_CFG[16]; /* IDC Channel configuration registers. */
} CSL_Iqn_dio2Dio2_iq_idc_channel_config_groupRegs; /* Group containing IDC Channel Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IFE_FRM_SAMP_TC_MMR_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IFE_FRM_SAMP_TC_CFG; /* IFE AxC Framing Sample Terminal Count Configuration Register */
} CSL_Iqn_dio2Dio2_ife_frm_samp_tc_mmr_ramRegs; /* Group containing Sample Terminal Count Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_GEN_CTL
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_CFG; /* This register simply starts the uAT timers running. It is implied that SW is unable to precisely time the start of timers. The intent is for the SW to correct the timers by later writting to the offset register of each timer. */
    volatile Uint32 DIO2_UAT_BCN_TC_CFG; /* UAT BCN terminal count Register */
    volatile Uint32 DIO2_UAT_BCN_OFFSET_CFG; /* UAT BCN offset Register */
    volatile Uint32 DIO2_UAT_SYNC_BCN_CAPTURE_STS; /* UAT SYNC BCN capture Register */
} CSL_Iqn_dio2Dio2_uat_gen_ctlRegs; /* Run bit for all uAT timers and BCN registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_EGR_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_EGR_RADT_TC_CFG; /* UAT RADT terminal count Register */
    volatile Uint32 DIO2_UAT_EGR_RADT_OFFSET_CFG; /* UAT RADT offset Register */
    volatile Uint32 DIO2_UAT_EGR_SYNC_RADT_CAPTURE_STS; /* UAT SYNC RADT capture Register */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_dio2Dio2_uat_egr_radtRegs; /* Egress RADT registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_ING_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_ING_RADT_TC_CFG; /* UAT RADT terminal count Register */
    volatile Uint32 DIO2_UAT_ING_RADT_OFFSET_CFG; /* UAT RADT offset Register */
    volatile Uint32 DIO2_UAT_ING_SYNC_RADT_CAPTURE_STS; /* UAT SYNC RADT capture Register */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_dio2Dio2_uat_ing_radtRegs; /* Ingress RADT registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_RADT_EVT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_EVT_RADT_CMP_CFG; /* UAT RADT event compare Register per RADT. The 0 to 7 are for si egress, 8 to 15 for si ingress, 16 to 18 for dio egress, 19 to 21 for dio ingress */
    volatile Uint32 DIO2_UAT_EVT_CLK_CNT_TC_CFG; /* UAT RADT event clock counter terminal count Register per RADT */
} CSL_Iqn_dio2Dio2_uat_radt_evtRegs; /* (Unused for AIL) RADT event compare registers for Frame strobe and iteration strobe counter config for 4sample Iteration strobe. The 0 to 7 are for si egress, 8 to 15 for si ingress, 16 to 18 for dio egress, 19 to 21 for dio ingress */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_DIO_EGR_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_DIO_EGR_RADT_TC_CFG; /* UAT DIO egress RADT terminal count Register */
    volatile Uint32 DIO2_UAT_DIO_EGR_RADT_OFFSET_CFG; /* UAT DIO egress RADT offset Register */
    volatile Uint32 DIO2_UAT_DIO_EGR_SYNC_RADT_CAPTURE_STS; /* UAT SYNC DIO egress RADT capture Register. RADT timer value is sampled and held in this Register each time the AT2 Master BCN wraps. Used for calculating timing correction offsetRADT count when a uat_mst_slv_sync from the AT occurs. Used by SW to determine correct RADT offset to apply. */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_dio2Dio2_uat_dio_egr_radtRegs; /* (DIO use only) DIO Egress RADT registers. These Radio Timers are used to Pace the DIO DMA start and iteration cycles  */

/**************************************************************************\
* Register Overlay Structure for DIO2_UAT_DIO_ING_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_UAT_DIO_ING_RADT_TC_CFG; /* UAT DIO ingress RADT terminal count Register */
    volatile Uint32 DIO2_UAT_DIO_ING_RADT_OFFSET_CFG; /* UAT DIO ingress RADT offset Register */
    volatile Uint32 DIO2_UAT_DIO_ING_SYNC_RADT_CAPTURE_STS; /* UAT SYNC DIO ingress RADT capture Register. RADT timer value is sampled and held in this Register each time the AT2 Master BCN wraps. Used for calculating timing correction offsetRADT count when a master sync from the AT occurs. Used by SW to determine correct RADT offset to apply. */
    volatile Uint8 RSVD0[4];
} CSL_Iqn_dio2Dio2_uat_dio_ing_radtRegs; /* (DIO use only) DIO Ingress RADT registers. These Radio Timers are used to Pace the DIO DMA start and iteration cycles  */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_EDC_REGISTER_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_EDC_CFG; /* EDC Configuration Register */
    volatile Uint32 DIO2_IQ_EDC_SOP_CNTR_STS; /* Counts the number of SOPs seen by the IQ EDC */
    volatile Uint32 DIO2_IQ_EDC_EOP_CNTR_STS; /* Counts the number of EOPs seen by the IQ EDC */
    volatile Uint8 RSVD0[116];
    volatile Uint32 DIO2_IQ_EDC_OCC_CNTR_STS[4]; /* EDC Status Occupancy counter for each channel register. User can ignore this (TI debug only)  */
    volatile Uint8 RSVD1[368];
    volatile Uint32 DIO2_IQ_EDC_CH_CFG[16]; /* Per-channel configuration registers. */
} CSL_Iqn_dio2Dio2_iq_edc_register_groupRegs; /* Group containing EDC Configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_IQ_INGRESS_VBUS_MMR_GROUP
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_IQ_IDC_RATE_CTL_CFG; /* IDC Rate Control Configuration register. Programmable rate control for OBSAI control word and generic packet mode */
    volatile Uint32 DIO2_IQ_IDC_SOP_CNTR_STS; /* This register provides a count of the Ingress SOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
    volatile Uint32 DIO2_IQ_IDC_EOP_CNTR_STS; /* This register provides a count of the Ingress EOPs sent on the PSI to the IQN2 buffer or switch for activity monitoring. */
} CSL_Iqn_dio2Dio2_iq_ingress_vbus_mmr_groupRegs; /* Group containing VBUS Ingress IQ MMR registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_GLOBAL
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_GLOBAL_EN_SET_STB; /* 
The Set Global Enable for Ingress DIO. A write of any value to this register sets the global enable for the Ingress DIO. */
    volatile Uint32 DIO2_I_GLOBAL_EN_CLR_STB; /* 
Clear Global Enable for Ingress DIO. A write of any value to this register clears the global enable for the Ingress DIO. */
    volatile Uint32 DIO2_I_GLOBAL_EN_STS; /* 
This register is Read Only and provides the status of the Ingress DIO global enable state. */
    volatile Uint8 RSVD0[4];
    volatile Uint32 DIO2_E_GLOBAL_EN_SET_STB; /* 
Set Global Enable for Egress DIO. A write of any value to this register sets the global enable for the Egress DIO.. */
    volatile Uint32 DIO2_E_GLOBAL_EN_CLR_STB; /* 
Clear Global Enable for Egress DIO. A write of any value to this register clears the global enable for the Egress DIO. */
    volatile Uint32 DIO2_E_GLOBAL_EN_STS; /* 
This register is Read Only and provides the status of the Egress DIO global enable state. */
    volatile Uint8 RSVD1[4];
    volatile Uint32 DIO2_DT_GLOBAL_EN_SET_STB; /* 
Set Global Enable for Data Trace DIO. A write of any value to this register sets the global enable for the Data Trace DIO. */
    volatile Uint32 DIO2_DT_GLOBAL_EN_CLR_STB; /* 
Clear Global Enable for Data Trace DIO. A write of any value to this register clears the global enable for the Data Trace DIO. */
    volatile Uint32 DIO2_DT_GLOBAL_EN_STS; /* 
This register is Read Only and provides the status of the Data Trace DIO global enable state. */
    volatile Uint8 RSVD2[20];
    volatile Uint32 DIO2_GLOBAL_CFG; /* 
The DIO Global Configuration Register allows the user to select priority on the VBUSM as well as control the Endianess of RSA Data Format Conversian */
} CSL_Iqn_dio2Dio2_globalRegs; /* Group containing GLOBAL configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_CORE_INGRESS
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_TABLE_SEL_CFG; /* 
This register selects which table to use so that channels may be added or deleted for Ingress.Programmed at the same time is the number of AxCs referenced in the table.
The user indicates to the DMA engine, which table is to be active during the next frame.
When bcn_table_sel =0, Table A is selected and when bcn_table_sel=1, Table B is selected.The non-selected table may be written any time between frame boundary strobes from the uAT. Switching tables, must be done in the middle, between frame boundary strobes in order to assure that the new table takes effect in the next frame */
    volatile Uint32 DIO2_I_DMA_CFG0; /* 
This register alows the user to program the number of quad words in a burst,the number of quad words per AxC and the number of data blocks to transfer before wrapping back to dma_base_addr  for Ingress.
This register also allows the user to enable RSA mode and the DMA engine itself. */
    volatile Uint32 DIO2_I_DMA_CFG1; /* 
This register enables the user to set the DMA block address stride between block transfers for Ingress. */
    volatile Uint8 RSVD0[52];
} CSL_Iqn_dio2Dio2_core_ingressRegs; /* Group containing INGRESS configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_I_AXC_OFF_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_AXC_OFFSET_CFG; /* 
A per-channel, Modulo 8 AxC offset in 4 sample (like DIO offset in AIF2)
i.e. 1 QW increments that determine the starting address within a circular data buffer. 
e.g. a value of 0 would cause zero offset. A value of 1 would cause a 4 sample offset. A value of 0 would also represent an offset of 8, 16, etc. */
} CSL_Iqn_dio2Dio2_i_axc_off_mmrRegs; /* Group containing the Ingress AxC offset registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_CORE_EGRESS
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_E_TABLE_SEL_CFG; /* 
This register selects which table to use so that channels may be added or deleted for Egress. Programmed at the same time is the number of AxCs referenced in the table.
The user indicates to the DMA engine, which table is to be active during the next frame.
When bcn_table_sel =0, Table A is selected and when bcn_table_sel=1, Table B is selected. The non-selected table may be written any time between frame boundary strobes from the uAT. Switching tables, must be done in the middle, between frame boundary strobes in order to assure that the new table takes effect in the next frame. */
    volatile Uint32 DIO2_E_DMA_CFG0; /* 
This register alows the user to program the number of quad words in a burst, the number of quad words per AxC and the number of data blocks to transfer before wrapping back to dma_base_addr  for Egress.
This register also allows the user to enable RSA mode and the DMA engine itself. */
    volatile Uint32 DIO2_E_DMA_CFG1; /* 
This register enables the user to set the DMA block address stride between block transfers for Egress. */
    volatile Uint8 RSVD0[52];
} CSL_Iqn_dio2Dio2_core_egressRegs; /* Group containing EGRESS configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_DT
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_DT_CFG0; /* This register allows the user to program the various mode of Data Trace operation */
    volatile Uint32 DIO2_DT_CFG1; /* 
This register allows the user to program the destination VBUS base address for Data Trace. */
    volatile Uint32 DIO2_DT_CFG2; /* 
This register allows the user to program the number of burst transfers before the destination address wraps back to the base address for Data Trace */
    volatile Uint32 DIO2_DT_START_STB; /* 
A write of any value to this register will start Data Trace operation if dt_en = 1. */
    volatile Uint32 DIO2_DT_START_STS; /* 
Read Only status of Data Trace operational state. */
} CSL_Iqn_dio2Dio2_dtRegs; /* Group containing Data Trace configuration registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_I_DBCNT0_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_TABLE0_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 0 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_I_TABLE0_CTRL_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 0 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_i_dbcnt0_ram_mmrRegs; /* Group containing Ingress DBCNT0 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_I_DBCNT1_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_TABLE1_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 1 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_I_TABLE1_CTRL_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 1 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_i_dbcnt1_ram_mmrRegs; /* Group containing Ingress DBCNT1 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_I_DBCNT2_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_I_TABLE2_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 2 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_I_TABLE2_CTRL_CFG; /* 
A per AxC register that is a field in the DIO Ingress DBCNT 2 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_i_dbcnt2_ram_mmrRegs; /* Group containing Ingress DBCNT2 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_E_AOG_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_E_AXC_OFF_CFG; /* 
These registers are per channel and allow the user the ability to program the Egress AxC offset from the Frame Boundary in 4 sample (1 QW) increments. 
e.g. a value of 0 would cause zero offset from frame boundary. A value of 1 would cause a 4 sample offset from frame boundary. */
} CSL_Iqn_dio2Dio2_e_aog_ram_mmrRegs; /* Group containing the AxC offset registers */

/**************************************************************************\
* Register Overlay Structure for DIO2_E_DBCNT0_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_E_TABLE0_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Egress DBCNT 0 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_E_TABLE0_CTRL_CFG; /* A per AxC register that is a field in the DIO Egress DBCNT 0 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_e_dbcnt0_ram_mmrRegs; /* Group containing Egress DBCNT0 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_E_DBCNT1_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_E_TABLE1_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Egress DBCNT 1 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_E_TABLE1_CTRL_CFG; /* 
A per AxC register that is a field in the DIO Egress DBCNT 1 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_e_dbcnt1_ram_mmrRegs; /* Group containing Egress DBCNT1 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_E_DBCNT2_RAM_MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_E_TABLE2_BASE_ADDR_CFG; /* 
A per AxC register that is a field in the DIO Egress DBCNT 2 LUT that enables the user to program the associated AxC's destination VBUS base address. 
This LUT is comprised of two parts. Table A is the lower half of the LUT's address and Table B which is the upper half of the LUT's address. */
    volatile Uint32 DIO2_E_TABLE2_CTRL_CFG; /* 
A per AxC register that is a field in the DIO Egress DBCNT 2 LUT that enables the user to program the associated AxC's channel ID and channel enable. */
} CSL_Iqn_dio2Dio2_e_dbcnt2_ram_mmrRegs; /* Group containing Egress DBCNT2 registers. Table A addressed 0 to 15. Table B addressed 16 to 31 */

/**************************************************************************\
* Register Overlay Structure for DIO2_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 DIO2_EE_DMA_ING_A_RAW_STS; /* DIO Ingress Interrupt Raw Status Register A */
    volatile Uint32 DIO2_EE_DMA_ING_A_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_DMA_ING_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_DMA_ING_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_DMA_ING_B_RAW_STS; /* DIO Ingress Interrupt Raw Status Register B */
    volatile Uint32 DIO2_EE_DMA_ING_B_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_DMA_ING_B_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_DMA_ING_B_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD0[132];
    volatile Uint32 DIO2_EE_DMA_EGR_A_RAW_STS; /* DIO Egress Interrupt Raw Status Register A */
    volatile Uint32 DIO2_EE_DMA_EGR_A_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_DMA_EGR_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_DT_A_RAW_STS; /* DIO DataTrace Interrupt Raw Status Register A  */
    volatile Uint32 DIO2_EE_DT_A_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_DT_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_DT_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_DT_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_DT_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_DT_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_DT_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_DT_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_DT_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_DT_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SII_A_RAW_STS; /* SI si_i IQ errors and info. */
    volatile Uint32 DIO2_EE_SII_A_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SII_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SII_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SII_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SII_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SII_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SII_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SII_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SII_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SII_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SII_C_RAW_STS; /* SI si_i IQ per-channel start of frame errors */
    volatile Uint32 DIO2_EE_SII_C_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SII_C_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SII_C_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SII_C_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SII_C_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SII_C_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SII_C_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SII_C_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SII_C_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SII_C_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD1[132];
    volatile Uint32 DIO2_EE_SIE_A_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 DIO2_EE_SIE_A_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SIE_A_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SIE_A_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SIE_A_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SIE_A_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_A_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SIE_A_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SIE_A_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_A_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_A_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SII_E_RAW_STS; /* SI si_i IQ info. */
    volatile Uint32 DIO2_EE_SII_E_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SII_E_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SII_E_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SII_E_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SII_E_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SII_E_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SII_E_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SII_E_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SII_E_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SII_E_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SII_G_RAW_STS; /* SI si_i IQ per-channel SOP transmitted to PSI info */
    volatile Uint32 DIO2_EE_SII_G_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SII_G_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SII_G_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SII_G_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SII_G_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SII_G_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SII_G_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SII_G_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SII_G_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SII_G_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD2[132];
    volatile Uint32 DIO2_EE_SIE_D_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 DIO2_EE_SIE_D_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SIE_D_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SIE_D_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SIE_D_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SIE_D_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_D_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SIE_D_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SIE_D_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_D_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_D_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_E_RAW_STS; /* SI si_e IQ errors and info. */
    volatile Uint32 DIO2_EE_SIE_E_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SIE_E_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SIE_E_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SIE_E_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SIE_E_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_E_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SIE_E_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SIE_E_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_E_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_E_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_F_RAW_STS; /* SI si_e IQ per-channel SOP received from PSI info */
    volatile Uint32 DIO2_EE_SIE_F_RAW_SET; /* Raw Set */
    volatile Uint32 DIO2_EE_SIE_F_RAW_CLR; /* Raw Clear */
    volatile Uint32 DIO2_EE_SIE_F_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 DIO2_EE_SIE_F_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 DIO2_EE_SIE_F_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_F_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 DIO2_EE_SIE_F_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 DIO2_EE_SIE_F_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 DIO2_EE_SIE_F_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 DIO2_EE_SIE_F_EV1_ENABLED_STS; /* EV1 Enabled Status */
    volatile Uint8 RSVD3[132];
    volatile Uint32 DIO2_DIO2_ORIG_REG; /* This is the DIO2 origination register provided as a shortcut way to determine where an interrupt originated. */
} CSL_Iqn_dio2Dio2_eeRegs; /* IQN_DIO2_EE EE register group */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn_dio2Dio2_si_iq_efe_config_groupRegs DIO2_SI_IQ_EFE_CONFIG_GROUP;
    volatile Uint8 RSVD0[348];
    CSL_Iqn_dio2Dio2_si_iq_efe_radio_standard_groupRegs DIO2_SI_IQ_EFE_RADIO_STANDARD_GROUP;
    volatile Uint8 RSVD1[204];
    CSL_Iqn_dio2Dio2_iq_efe_chan_axc_offsetRegs DIO2_IQ_EFE_CHAN_AXC_OFFSET[16];
    volatile Uint8 RSVD2[448];
    CSL_Iqn_dio2Dio2_iq_efe_frm_samp_tc_mmr_ramRegs DIO2_IQ_EFE_FRM_SAMP_TC_MMR_RAM[256];
    CSL_Iqn_dio2Dio2_iq_efe_chan_tdm_lutRegs DIO2_IQ_EFE_CHAN_TDM_LUT[256];
    CSL_Iqn_dio2Dio2_iq_efe_radio_standard_scheduler_groupRegs DIO2_IQ_EFE_RADIO_STANDARD_SCHEDULER_GROUP;
    volatile Uint8 RSVD3[4064];
    CSL_Iqn_dio2Dio2_iq_ife_channel_configuration_groupRegs DIO2_IQ_IFE_CHANNEL_CONFIGURATION_GROUP;
    volatile Uint8 RSVD4[448];
    CSL_Iqn_dio2Dio2_iq_ife_radio_standard_groupRegs DIO2_IQ_IFE_RADIO_STANDARD_GROUP;
    volatile Uint8 RSVD5[12];
    CSL_Iqn_dio2Dio2_iq_ife_config_groupRegs DIO2_IQ_IFE_CONFIG_GROUP;
    volatile Uint8 RSVD6[32];
    CSL_Iqn_dio2Dio2_iq_idc_general_status_groupRegs DIO2_IQ_IDC_GENERAL_STATUS_GROUP;
    volatile Uint8 RSVD7[44];
    CSL_Iqn_dio2Dio2_iq_idc_configuration_groupRegs DIO2_IQ_IDC_CONFIGURATION_GROUP;
    volatile Uint8 RSVD8[60];
    CSL_Iqn_dio2Dio2_iq_idc_channel_config_groupRegs DIO2_IQ_IDC_CHANNEL_CONFIG_GROUP;
    volatile Uint8 RSVD9[960];
    CSL_Iqn_dio2Dio2_ife_frm_samp_tc_mmr_ramRegs DIO2_IFE_FRM_SAMP_TC_MMR_RAM[256];
    volatile Uint8 RSVD10[9216];
    CSL_Iqn_dio2Dio2_uat_gen_ctlRegs DIO2_UAT_GEN_CTL;
    volatile Uint8 RSVD11[112];
    CSL_Iqn_dio2Dio2_uat_egr_radtRegs DIO2_UAT_EGR_RADT[8];
    CSL_Iqn_dio2Dio2_uat_ing_radtRegs DIO2_UAT_ING_RADT[8];
    volatile Uint8 RSVD12[128];
    CSL_Iqn_dio2Dio2_uat_radt_evtRegs DIO2_UAT_RADT_EVT[22];
    volatile Uint8 RSVD13[80];
    CSL_Iqn_dio2Dio2_uat_dio_egr_radtRegs DIO2_UAT_DIO_EGR_RADT[3];
    volatile Uint8 RSVD14[16];
    CSL_Iqn_dio2Dio2_uat_dio_ing_radtRegs DIO2_UAT_DIO_ING_RADT[3];
    volatile Uint8 RSVD15[11408];
    CSL_Iqn_dio2Dio2_iq_edc_register_groupRegs DIO2_IQ_EDC_REGISTER_GROUP;
    volatile Uint8 RSVD16[7616];
    CSL_Iqn_dio2Dio2_iq_ingress_vbus_mmr_groupRegs DIO2_IQ_INGRESS_VBUS_MMR_GROUP;
    volatile Uint8 RSVD17[24564];
    CSL_Iqn_dio2Dio2_globalRegs DIO2_GLOBAL;
    volatile Uint8 RSVD18[188];
    CSL_Iqn_dio2Dio2_core_ingressRegs DIO2_CORE_INGRESS[3];
    volatile Uint8 RSVD19[64];
    CSL_Iqn_dio2Dio2_i_axc_off_mmrRegs DIO2_I_AXC_OFF_MMR[16];
    volatile Uint8 RSVD20[192];
    CSL_Iqn_dio2Dio2_core_egressRegs DIO2_CORE_EGRESS[3];
    volatile Uint8 RSVD21[64];
    CSL_Iqn_dio2Dio2_dtRegs DIO2_DT;
    volatile Uint8 RSVD22[1004];
    CSL_Iqn_dio2Dio2_i_dbcnt0_ram_mmrRegs DIO2_I_DBCNT0_RAM_MMR[32];
    volatile Uint8 RSVD23[1792];
    CSL_Iqn_dio2Dio2_i_dbcnt1_ram_mmrRegs DIO2_I_DBCNT1_RAM_MMR[32];
    volatile Uint8 RSVD24[1792];
    CSL_Iqn_dio2Dio2_i_dbcnt2_ram_mmrRegs DIO2_I_DBCNT2_RAM_MMR[32];
    volatile Uint8 RSVD25[3840];
    CSL_Iqn_dio2Dio2_e_aog_ram_mmrRegs DIO2_E_AOG_RAM_MMR[16];
    volatile Uint8 RSVD26[1984];
    CSL_Iqn_dio2Dio2_e_dbcnt0_ram_mmrRegs DIO2_E_DBCNT0_RAM_MMR[32];
    volatile Uint8 RSVD27[1792];
    CSL_Iqn_dio2Dio2_e_dbcnt1_ram_mmrRegs DIO2_E_DBCNT1_RAM_MMR[32];
    volatile Uint8 RSVD28[1792];
    CSL_Iqn_dio2Dio2_e_dbcnt2_ram_mmrRegs DIO2_E_DBCNT2_RAM_MMR[32];
    volatile Uint8 RSVD29[16128];
    CSL_Iqn_dio2Dio2_eeRegs DIO2_EE;
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD30[555996];
/******************************************/
} CSL_Iqn_dio2Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* dio2_iq_efe_chan_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_EN_DISABLED (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_TDD_FRC_OFF Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_FRC_SYM_OFF (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_TDD_FRC_OFF_NO_FRC_OFF_SYM (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_MASK (0x00007000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RESETVAL (0x00000000u)
/*----CHAN_RADIO_SEL Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS0 (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS1 (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS2 (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS3 (0x00000003u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS4 (0x00000004u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS5 (0x00000005u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS6 (0x00000006u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_CHAN_RADIO_SEL_RS7 (0x00000007u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_CFG_LOOPBACK_EN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CFG_LOOPBACK_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CFG_LOOPBACK_EN_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_global_en_set_stb */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* dio2_iq_efe_global_en_clr_stb */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* dio2_iq_efe_global_en_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* dio2_iq_efe_chan_on_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_ON_STS_CHAN_ON_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_ON_STS_RESETVAL (0x00000000u)

/* dio2_iq_efe_in_pkt_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_IN_PKT_STS_IN_PKT_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_IN_PKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_IN_PKT_STS_IN_PKT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_IN_PKT_STS_RESETVAL (0x00000000u)

/* dio2_iq_efe_dma_sync_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_DMA_SYNC_STS_DMA_SYNC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_DMA_SYNC_STS_RESETVAL (0x00000000u)

/* dio2_iq_efe_frm_tc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_SYM_TC_MASK (0x000000FFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_SYM_TC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_SYM_TC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_SC_MASK (0x0000FF00u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_SC_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_TC_MASK (0x00FF0000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_TC_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_INDEX_TC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_TC_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_rad_std_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_MASK (0x000000FFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_FIRST_SYM_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_RESETVAL (0x00000000u)
/*----TDD_LUT_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_ENABLED (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_TDD_LUT_EN_DISABLED (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg0 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG0_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg1 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG1_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg2 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG2_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg3 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG3_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg4 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG4_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg5 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG5_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg6 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG6_RESETVAL (0x00000000u)

/* dio2_iq_efe_tdd_en_cfg7 */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_TDD_EN_CFG7_RESETVAL (0x00000000u)

/* dio2_iq_efe_chan_axc_offset_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_MASK (0x000FFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_AXC_OFFSET_CFG_AXC_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_AXC_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_frm_samp_tc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_MASK (0x0003FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_SAMP_TC_CFG_SAMP_TC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_FRM_SAMP_TC_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_chan_tdm_lut_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_CFG_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_CFG_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_CFG_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_EN_CFG_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_EN_CFG_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_CHAN_INDEX_EN_CFG_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_CHAN_TDM_LUT_CFG_RESETVAL (0x00000000u)

/* dio2_iq_efe_rad_std_sch_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_START_MASK (0x000000FFu)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_START_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_START_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_LEN_MASK (0x0000FF00u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_LEN_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_LEN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_EN_MASK (0x00010000u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_EN_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_EN_RESETVAL (0x00000000u)
/*----TDM_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_EN_ENABLED (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_TDM_EN_DISABLED (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EFE_RAD_STD_SCH_CFG_RESETVAL (0x00000000u)

/* dio2_iq_ife_chan_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_EN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_EN_RESETVAL (0x00000000u)
/*----CHAN_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_EN_ENABLED (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_EN_DISABLED (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_MASK (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_RESETVAL (0x00000000u)
/*----CHAN_AXC_OFFSET Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_NONE (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_ONE (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_TWO (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_AXC_OFFSET_THREE (0x00000003u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RESETVAL (0x00000000u)
/*----CHAN_RADIO_SEL Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS0 (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS1 (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS2 (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS3 (0x00000003u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS4 (0x00000004u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS5 (0x00000005u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS6 (0x00000006u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_RADIO_SEL_RS7 (0x00000007u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_TDD_FRC_OFF Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_FRC_SYM_OFF (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_CHAN_TDD_FRC_OFF_NO_FRC_OFF_SYM (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_CFG_RESETVAL (0x00000000u)

/* dio2_iq_ife_frm_tc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_SYM_TC_MASK (0x000000FFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_SYM_TC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_SYM_TC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_SC_MASK (0x0000FF00u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_SC_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_TC_MASK (0x00FF0000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_TC_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_INDEX_TC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_TC_CFG_RESETVAL (0x00000000u)

/* dio2_iq_ife_rad_std_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_RESETVAL (0x00000000u)
/*----TDD_LUT_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_ENABLED (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_TDD_LUT_EN_DISABLED (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_RAD_STD_CFG_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg0 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG0_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg1 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG1_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg2 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG2_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg3 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG3_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg4 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG4_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg5 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG5_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg6 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG6_RESETVAL (0x00000000u)

/* dio2_iq_ife_tdd_en_cfg7 */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_TDD_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_TDD_EN_RESETVAL (0x00000000u)
/*----TDD_EN Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_TDD_EN_SYM_ON (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_TDD_EN_CFG7_RESETVAL (0x00000000u)

/* dio2_iq_ife_global_en_set_stb */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* dio2_iq_ife_global_en_clr_stb */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* dio2_iq_ife_global_en_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* dio2_iq_ife_chan_on_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_ON_STS_CHAN_ON_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_ON_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_ON_STS_CHAN_ON_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_CHAN_ON_STS_RESETVAL (0x00000000u)

/* dio2_iq_ife_in_pkt_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_IN_PKT_STS_IN_PKT_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_IN_PKT_STS_IN_PKT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_IN_PKT_STS_IN_PKT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_IN_PKT_STS_RESETVAL (0x00000000u)

/* dio2_iq_idc_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_EMPTY_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_EMPTY_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_EMPTY_RESETVAL (0x00000001u)
/*----EMPTY Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_EMPTY_FIFO_NOT_EMPTY (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_EMPTY_FIFO_EMPTY (0x00000001u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_STS_RESETVAL (0x00000001u)

/* dio2_iq_idc_inpkt_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_INPKT_STS_INPKT_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_INPKT_STS_INPKT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_INPKT_STS_INPKT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_INPKT_STS_RESETVAL (0x00000000u)

/* dio2_iq_idc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FAIL_MARK_ONLY_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FAIL_MARK_ONLY_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FAIL_MARK_ONLY_RESETVAL (0x00000000u)
/*----FAIL_MARK_ONLY Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FAIL_MARK_ONLY_DROP (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FAIL_MARK_ONLY_MARK (0x00000001u)

#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FRC_OFF_ALL_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FRC_OFF_ALL_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FRC_OFF_ALL_RESETVAL (0x00000000u)
/*----FRC_OFF_ALL Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FRC_OFF_ALL_FRC_OFF (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_FRC_OFF_ALL_NOP (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_CFG_RESETVAL (0x00000000u)

/* dio2_iq_idc_ch_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_PKT_TYPE_MASK (0x001F0000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_PKT_TYPE_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_PKT_TYPE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_CHAN_FRC_OFF_MASK (0x01000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_CHAN_FRC_OFF_SHIFT (0x00000018u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_CHAN_FRC_OFF_RESETVAL (0x00000000u)
/*----CHAN_FRC_OFF Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_CHAN_FRC_OFF_FRC_OFF (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_CHAN_FRC_OFF_NOP (0x00000001u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_CH_CFG_RESETVAL (0x00000000u)

/* dio2_iq_ife_frm_samp_tc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_MASK (0x0003FFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_SAMP_TC_CFG_SAMP_TC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IFE_FRM_SAMP_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_CFG_UAT_RUN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_UAT_CFG_UAT_RUN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_CFG_UAT_RUN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_UAT_CFG_DIAG_SYNC_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_UAT_CFG_DIAG_SYNC_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_UAT_CFG_DIAG_SYNC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_CFG_RESETVAL (0x00000000u)

/* dio2_uat_bcn_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_BCN_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_BCN_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_BCN_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_BCN_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_bcn_offset_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_BCN_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_BCN_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_BCN_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_BCN_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_uat_sync_bcn_capture_sts */

#define CSL_IQN_DIO2_DIO2_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_SYNC_BCN_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_SYNC_BCN_CAPTURE_STS_RESETVAL (0x00000000u)

/* dio2_uat_egr_radt_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_egr_radt_offset_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_EGR_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_uat_egr_sync_radt_capture_sts */

#define CSL_IQN_DIO2_DIO2_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_EGR_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* dio2_uat_ing_radt_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_ing_radt_offset_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_ING_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_uat_ing_sync_radt_capture_sts */

#define CSL_IQN_DIO2_DIO2_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_ING_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* dio2_uat_evt_radt_cmp_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_EVT_RADT_CMP_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_EVT_RADT_CMP_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_EVT_RADT_CMP_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_EVT_RADT_CMP_CFG_RESETVAL (0x00000000u)

/* dio2_uat_evt_clk_cnt_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_EVT_CLK_CNT_TC_CFG_VAL_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_EVT_CLK_CNT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_EVT_CLK_CNT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_EVT_CLK_CNT_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_dio_egr_radt_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_dio_egr_radt_offset_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_uat_dio_egr_sync_radt_capture_sts */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_EGR_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* dio2_uat_dio_ing_radt_tc_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_TC_CFG_RESETVAL (0x00000000u)

/* dio2_uat_dio_ing_radt_offset_cfg */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_RADT_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_uat_dio_ing_sync_radt_capture_sts */

#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_SYNC_RADT_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_UAT_DIO_ING_SYNC_RADT_CAPTURE_STS_RESETVAL (0x00000000u)

/* dio2_iq_edc_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_RESETVAL (0x00000000u)
/*----PSI_ERR_CHK_DISABLE Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_DROP (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_PSI_ERR_CHK_DISABLE_NO_DROP (0x00000001u)


#define CSL_IQN_DIO2_DIO2_IQ_EDC_CFG_RESETVAL (0x00000000u)

/* dio2_iq_edc_sop_cntr_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EDC_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EDC_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* dio2_iq_edc_eop_cntr_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EDC_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_EDC_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* dio2_iq_edc_occ_cntr_sts */

#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_MASK (0x000000FFu)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_A_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_MASK (0x0000FF00u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_B_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_MASK (0x00FF0000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_C_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_MASK (0xFF000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_SHIFT (0x00000018u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_OCC_CNTR_D_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_IQ_EDC_OCC_CNTR_STS_RESETVAL (0x00000000u)

/* dio2_iq_edc_ch_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_MASK (0x00000003u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_NONE (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_BYTE (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_HALF (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_DAT_SWAP_WORD (0x00000003u)


#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_MASK (0x00000030u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_BYTE (0x00000002u)
#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_IQ_ORDER_HALF (0x00000003u)


#define CSL_IQN_DIO2_DIO2_IQ_EDC_CH_CFG_RESETVAL (0x00000000u)

/* dio2_iq_idc_rate_ctl_cfg */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_RATE_CTL_CFG_RATE_MASK (0x0000000Fu)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_RATE_CTL_CFG_RATE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_RATE_CTL_CFG_RATE_RESETVAL (0x0000000Fu)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_RATE_CTL_CFG_RESETVAL (0x0000000Fu)

/* dio2_iq_idc_sop_cntr_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_SOP_CNTR_STS_SOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_SOP_CNTR_STS_SOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_SOP_CNTR_STS_SOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_SOP_CNTR_STS_RESETVAL (0x00000000u)

/* dio2_iq_idc_eop_cntr_sts */

#define CSL_IQN_DIO2_DIO2_IQ_IDC_EOP_CNTR_STS_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_EOP_CNTR_STS_EOP_CNT_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_IQ_IDC_EOP_CNTR_STS_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_IQ_IDC_EOP_CNTR_STS_RESETVAL (0x00000000u)

/* dio2_i_global_en_set_stb */

#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* dio2_i_global_en_clr_stb */

#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* dio2_i_global_en_sts */

#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_I_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* dio2_e_global_en_set_stb */

#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* dio2_e_global_en_clr_stb */

#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* dio2_e_global_en_sts */

#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_E_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* dio2_dt_global_en_set_stb */

#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_SET_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_SET_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_SET_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_SET_STB_RESETVAL (0x00000000u)

/* dio2_dt_global_en_clr_stb */

#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_CLR_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_CLR_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_CLR_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_CLR_STB_RESETVAL (0x00000000u)

/* dio2_dt_global_en_sts */

#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DT_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* dio2_global_cfg */

#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_VBUSM_PRIORITY_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_VBUSM_PRIORITY_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_VBUSM_PRIORITY_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RSA_BIG_ENDIAN_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RSA_BIG_ENDIAN_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RSA_BIG_ENDIAN_RESETVAL (0x00000000u)
/*----rsa_big_endian Tokens----*/
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RSA_BIG_ENDIAN_RSALTL (0x00000000u)
#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RSA_BIG_ENDIAN_RSABIG (0x00000001u)


#define CSL_IQN_DIO2_DIO2_GLOBAL_CFG_RESETVAL (0x00000000u)

/* dio2_i_table_sel_cfg */

#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_BCN_TABLE_SEL_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_BCN_TABLE_SEL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_BCN_TABLE_SEL_RESETVAL (0x00000000u)
/*----bcn_table_sel Tokens----*/
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_BCN_TABLE_SEL_TABLE_A (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_BCN_TABLE_SEL_TABLE_B (0x00000001u)


#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_DMA_NUM_AXC_MASK (0x00000F00u)
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_DMA_NUM_AXC_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_DMA_NUM_AXC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_I_TABLE_SEL_CFG_RESETVAL (0x00000000u)

/* dio2_i_dma_cfg0 */

#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_MASK (0x00000003u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_RESETVAL (0x00000000u)
/*----dma_brst_ln Tokens----*/
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_1QUAD (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_2QUAD (0x00000001u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_BRST_LN_4QUAD (0x00000002u)


#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_MASK (0x00000030u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_RESETVAL (0x00000000u)
/*----dma_num_qwd Tokens----*/
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_1QUAD (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_2QUAD (0x00000001u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_QWD_4QUAD (0x00000002u)


#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RSA_CNVRT_EN_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RSA_CNVRT_EN_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RSA_CNVRT_EN_RESETVAL (0x00000000u)
/*----rsa_cnvrt_en Tokens----*/
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RSA_CNVRT_EN_NORSA (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RSA_CNVRT_EN_RSAEN (0x00000001u)

#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_ENG_EN_MASK (0x00000200u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_ENG_EN_SHIFT (0x00000009u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_ENG_EN_RESETVAL (0x00000000u)
/*----dma_eng_en Tokens----*/
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_ENG_EN_DMACLR (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_ENG_EN_DMAEN (0x00000001u)


#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_BLKS_MASK (0x1FFF0000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_BLKS_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_DMA_NUM_BLKS_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_I_DMA_CFG0_RESETVAL (0x00000000u)

/* dio2_i_dma_cfg1 */

#define CSL_IQN_DIO2_DIO2_I_DMA_CFG1_DMA_BLK_ADDR_STRIDE_MASK (0x00000FFFu)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG1_DMA_BLK_ADDR_STRIDE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_DMA_CFG1_DMA_BLK_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_I_DMA_CFG1_RESETVAL (0x00000000u)

/* dio2_i_axc_offset_cfg */

#define CSL_IQN_DIO2_DIO2_I_AXC_OFFSET_CFG_DIO_I_AXC_4SAMP_OFFSET_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_I_AXC_OFFSET_CFG_DIO_I_AXC_4SAMP_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_AXC_OFFSET_CFG_DIO_I_AXC_4SAMP_OFFSET_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_I_AXC_OFFSET_CFG_RESETVAL (0x00000000u)

/* dio2_e_table_sel_cfg */

#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_BCN_TABLE_SEL_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_BCN_TABLE_SEL_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_BCN_TABLE_SEL_RESETVAL (0x00000000u)
/*----bcn_table_sel Tokens----*/
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_BCN_TABLE_SEL_TABLE_A (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_BCN_TABLE_SEL_TABLE_B (0x00000001u)


#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_DMA_NUM_AXC_MASK (0x00000F00u)
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_DMA_NUM_AXC_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_DMA_NUM_AXC_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_E_TABLE_SEL_CFG_RESETVAL (0x00000000u)

/* dio2_e_dma_cfg0 */

#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_MASK (0x00000003u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_RESETVAL (0x00000000u)
/*----dma_brst_ln Tokens----*/
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_1QUAD (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_2QUAD (0x00000001u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_BRST_LN_4QUAD (0x00000002u)


#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_MASK (0x00000030u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_RESETVAL (0x00000000u)
/*----dma_num_qwd Tokens----*/
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_1QUAD (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_2QUAD (0x00000001u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_QWD_4QUAD (0x00000002u)


#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RSA_CNVRT_EN_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RSA_CNVRT_EN_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RSA_CNVRT_EN_RESETVAL (0x00000000u)
/*----rsa_cnvrt_en Tokens----*/
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RSA_CNVRT_EN_NORSA (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RSA_CNVRT_EN_RSAEN (0x00000001u)

#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_ENG_EN_MASK (0x00000200u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_ENG_EN_SHIFT (0x00000009u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_ENG_EN_RESETVAL (0x00000000u)
/*----dma_eng_en Tokens----*/
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_ENG_EN_DMACLR (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_ENG_EN_DMAEN (0x00000001u)


#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_BLKS_MASK (0x1FFF0000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_BLKS_SHIFT (0x00000010u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_DMA_NUM_BLKS_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_E_DMA_CFG0_RESETVAL (0x00000000u)

/* dio2_e_dma_cfg1 */

#define CSL_IQN_DIO2_DIO2_E_DMA_CFG1_DMA_BLK_ADDR_STRIDE_MASK (0x00000FFFu)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG1_DMA_BLK_ADDR_STRIDE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_DMA_CFG1_DMA_BLK_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_E_DMA_CFG1_RESETVAL (0x00000000u)

/* dio2_dt_cfg0 */

#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_EN_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_EN_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_EN_RESETVAL (0x00000000u)
/*----dt_en Tokens----*/
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_EN_NODT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_EN_DTEN (0x00000001u)

#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_START_MODE_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_START_MODE_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_START_MODE_RESETVAL (0x00000000u)
/*----dt_start_mode Tokens----*/
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_START_MODE_CAPRAW (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_START_MODE_CAPSOF (0x00000001u)

#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_STOP_MODE_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_STOP_MODE_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_STOP_MODE_RESETVAL (0x00000000u)
/*----dt_stop_mode Tokens----*/
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_STOP_MODE_CIRCULAR (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_STOP_MODE_ONESHOT (0x00000001u)

#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_ENDIAN_SEL_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_ENDIAN_SEL_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_ENDIAN_SEL_RESETVAL (0x00000000u)
/*----dt_endian_sel Tokens----*/
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_ENDIAN_SEL_BIG (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG0_DT_ENDIAN_SEL_LITTLE (0x00000001u)


#define CSL_IQN_DIO2_DIO2_DT_CFG0_RESETVAL (0x00000000u)

/* dio2_dt_cfg1 */

#define CSL_IQN_DIO2_DIO2_DT_CFG1_DT_DMA_BASE_ADDR_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_DT_CFG1_DT_DMA_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG1_DT_DMA_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DT_CFG1_RESETVAL (0x00000000u)

/* dio2_dt_cfg2 */

#define CSL_IQN_DIO2_DIO2_DT_CFG2_DT_DMA_WRAP_MASK (0x0003FFFFu)
#define CSL_IQN_DIO2_DIO2_DT_CFG2_DT_DMA_WRAP_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_CFG2_DT_DMA_WRAP_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DT_CFG2_RESETVAL (0x00000000u)

/* dio2_dt_start_stb */

#define CSL_IQN_DIO2_DIO2_DT_START_STB_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_IQN_DIO2_DIO2_DT_START_STB_DONT_CARE_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_START_STB_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DT_START_STB_RESETVAL (0x00000000u)

/* dio2_dt_start_sts */

#define CSL_IQN_DIO2_DIO2_DT_START_STS_DT_IN_PROGRESS_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DT_START_STS_DT_IN_PROGRESS_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DT_START_STS_DT_IN_PROGRESS_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DT_START_STS_RESETVAL (0x00000000u)

/* dio2_i_table0_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE0_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_i_table0_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE0_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_i_table1_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE1_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_i_table1_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE1_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_i_table2_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE2_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_i_table2_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_I_TABLE2_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_e_axc_off_cfg */


#define CSL_IQN_DIO2_DIO2_E_AXC_OFF_CFG_DIO_E_AXC_4SAMP_OFFSET_MASK (0x0001FFFFu)
#define CSL_IQN_DIO2_DIO2_E_AXC_OFF_CFG_DIO_E_AXC_4SAMP_OFFSET_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_AXC_OFF_CFG_DIO_E_AXC_4SAMP_OFFSET_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_AXC_OFF_CFG_RESETVAL (0x00000000u)

/* dio2_e_table0_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE0_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_e_table0_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE0_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_e_table1_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE1_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_e_table1_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE1_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_e_table2_base_addr_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_MASK (0x0FFFFFFFu)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_BASE_ADDR_CFG_DMA_VBUS_BASE_ADDR_AXC_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE2_BASE_ADDR_CFG_RESETVAL (0x00000000u)

/* dio2_e_table2_ctrl_cfg */


#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_EN_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_EN_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_EN_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_ID_MASK (0x0000007Fu)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_ID_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_CH_ID_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_E_TABLE2_CTRL_CFG_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_a_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_DMA_ING_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_STS_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_STS_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_STS_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_SET_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_SET_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_SET_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_CLR_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_CLR_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_CLR_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_STS_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_STS_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_STS_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_SET_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_SET_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_SET_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_CLR_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_CLR_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_CLR_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_STS_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_STS_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_STS_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_SET_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_SET_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_SET_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_CLR_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_CLR_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_CLR_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_ENABLED_STS_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_ENABLED_STS_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_ENABLED_STS_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_ing_b_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_ENABLED_STS_DMA_ING_BUF_OVF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_ENABLED_STS_DMA_ING_BUF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_ENABLED_STS_DMA_ING_BUF_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_ING_B_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dma_egr_a_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_MASK (0x00000007u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PEND_QUE_OVF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PROG_ERR_MASK (0x00000070u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PROG_ERR_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_PROG_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_MASK (0x00000700u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_DMA_EGR_XFER_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_SI_ING_IQ_FIFO_FULL_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DMA_EGR_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_dt_a_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_BUFF_OVF_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_BUFF_OVF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_BUFF_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_DONE_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_DONE_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_DT_DONE_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_DT_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_a_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_SOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_SI_ING_IQ_IFE_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_STS_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_SET_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_CLR_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_STS_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_SET_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_STS_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_SET_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_SET_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_SET_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_CLR_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_ENABLED_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_c_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_ENABLED_STS_SI_ING_IQ_SOF_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_C_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_a_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_PKT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_EFE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_MASK (0x00000008u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_SHIFT (0x00000003u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_SOF_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_MASK (0x00000010u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_SHIFT (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_SI_EGR_IQ_ICC_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_A_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_e_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_SI_ING_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_E_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_SET_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_CLR_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sii_g_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_ENABLED_STS_SI_ING_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SII_G_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_d_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DATA_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_EOP_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_MASK (0x00000004u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_SHIFT (0x00000002u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_SI_EGR_IQ_PSI_DAT_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_D_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_raw_sts */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_raw_set */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_raw_clr */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev0_en_sts */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev0_en_set */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev0_en_clr */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev1_en_sts */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev1_en_set */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev1_en_clr */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev0_enabled_sts */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_e_ev1_enabled_sts */


#define CSL_IQN_DIO2_DIO2_EE_SIE_E_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_raw_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_raw_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_raw_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_RAW_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev0_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev0_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev0_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev1_en_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev1_en_set */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_SET_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_SET_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev1_en_clr */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_CLR_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_EN_CLR_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev0_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_ee_sie_f_ev1_enabled_sts */

#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_MASK (0x0000FFFFu)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_ENABLED_STS_SI_EGR_IQ_PSI_SOP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_EE_SIE_F_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* dio2_dio2_orig_reg */

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_A_MASK (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_A_SHIFT (0x00000000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_A_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_B_MASK (0x00000002u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_B_SHIFT (0x00000001u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_B_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_A_MASK (0x00000020u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_A_SHIFT (0x00000005u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_A_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_DT_A_MASK (0x00000040u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_DT_A_SHIFT (0x00000006u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_DT_A_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_B_MASK (0x00000080u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_B_SHIFT (0x00000007u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_B_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_C_MASK (0x00000100u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_C_SHIFT (0x00000008u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_C_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_C_MASK (0x00001000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_C_SHIFT (0x0000000Cu)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_C_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_D_MASK (0x00002000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_D_SHIFT (0x0000000Du)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_D_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_E_MASK (0x00004000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_E_SHIFT (0x0000000Eu)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_EGR_E_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_D_MASK (0x00040000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_D_SHIFT (0x00000012u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_D_RESETVAL (0x00000000u)

#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_E_MASK (0x00080000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_E_SHIFT (0x00000013u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_E_RESETVAL (0x00000000u)


#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_F_MASK (0x00800000u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_F_SHIFT (0x00000017u)
#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_ORIG_BITFIELD_ING_F_RESETVAL (0x00000000u)



#define CSL_IQN_DIO2_DIO2_DIO2_ORIG_REG_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
