/********************************************************************
* Copyright (C) 2003-2008 Texas Instruments Incorporated.
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
#ifndef CSLR_AIF2_H
#define CSLR_AIF2_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for SD_LK
\**************************************************************************/
typedef struct  {
    volatile Uint32 SD_RX_EN_CFG; /* RX Enable Register */
    volatile Uint32 SD_RX_CFG; /* RX Configuration Register */
    volatile Uint8 RSVD0[4];
    volatile Uint32 SD_RX_STS; /* RX Status Register */
    volatile Uint32 SD_TX_EN_CFG; /* TX Enable Register */
    volatile Uint32 SD_TX_CFG; /* TX Configuration Register */
    volatile Uint8 RSVD1[2024];
} CSL_Aif2Sd_lkRegs; /* Group containing SD link registers */

/**************************************************************************\
* Register Overlay Structure for AD_DIO_INGRESS
\**************************************************************************/
typedef struct  {
    volatile Uint32 AD_DIO_I_TABLE_SEL; /* AD DIO Ingress Table Select Register */
    volatile Uint32 AD_DIO_I_TABLE_LOOP_CFG; /* AD DIO Ingress Table Loop Configuration Register */
    volatile Uint32 AD_DIO_I_DMA_CFG0; /* AD DIO Ingress DMA Configuration Register 0 */
    volatile Uint32 AD_DIO_I_DMA_CFG1; /* AD DIO Ingress DMA Configuration Register 1 */
    volatile Uint32 AD_DIO_I_DMA_CFG2; /* AD DIO Ingress DMA Configuration Register 2 */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW0; /* AD DIO Ingress BCN Table 0 Row 0  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW1; /* AD DIO Ingress BCN Table 0 Row 1  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW2; /* AD DIO Ingress BCN Table 0 Row 2  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW3; /* AD DIO Ingress BCN Table 0 Row 3  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW4; /* AD DIO Ingress BCN Table 0 Row 4  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW5; /* AD DIO Ingress BCN Table 0 Row 5  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW6; /* AD DIO Ingress BCN Table 0 Row 6  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW7; /* AD DIO Ingress BCN Table 0 Row 7  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW8; /* AD DIO Ingress BCN Table 0 Row 8  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW9; /* AD DIO Ingress BCN Table 0 Row 9  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW10; /* AD DIO Ingress BCN Table 0 Row 10  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW11; /* AD DIO Ingress BCN Table 0 Row 11  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW12; /* AD DIO Ingress BCN Table 0 Row 12  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW13; /* AD DIO Ingress BCN Table 0 Row 13  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW14; /* AD DIO Ingress BCN Table 0 Row 14  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE0_ROW15; /* AD DIO Ingress BCN Table 0 Row 15  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW0; /* AD DIO Ingress BCN Table 1 Row 0  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW1; /* AD DIO Ingress BCN Table 1 Row 1  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW2; /* AD DIO Ingress BCN Table 1 Row 2  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW3; /* AD DIO Ingress BCN Table 1 Row 3  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW4; /* AD DIO Ingress BCN Table 1 Row 4  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW5; /* AD DIO Ingress BCN Table 1 Row 5  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW6; /* AD DIO Ingress BCN Table 1 Row 6  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW7; /* AD DIO Ingress BCN Table 1 Row 7  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW8; /* AD DIO Ingress BCN Table 1 Row 8  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW9; /* AD DIO Ingress BCN Table 1 Row 9  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW10; /* AD DIO Ingress BCN Table 1 Row 10  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW11; /* AD DIO Ingress BCN Table 1 Row 11  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW12; /* AD DIO Ingress BCN Table 1 Row 12  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW13; /* AD DIO Ingress BCN Table 1 Row 13  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW14; /* AD DIO Ingress BCN Table 1 Row 14  Register */
    volatile Uint32 AD_DIO_I_BCN_TABLE1_ROW15; /* AD DIO Ingress BCN Table 1 Row 15  Register */
    volatile Uint8 RSVD0[108];
} CSL_Aif2Ad_dio_ingressRegs; /* Group containing INGRESS configuration registers */

/**************************************************************************\
* Register Overlay Structure for AD_DIO_EGRESS
\**************************************************************************/
typedef struct  {
    volatile Uint32 AD_DIO_E_TABLE_SEL; /* AD DIO Egress Table Select Register */
    volatile Uint32 AD_DIO_E_TABLE_LOOP_CFG; /* AD DIO Egress Table Loop Configuration Register */
    volatile Uint32 AD_DIO_E_DMA_CFG0; /* AD DIO Egress DMA Configuration Register 0 */
    volatile Uint32 AD_DIO_E_DMA_CFG1; /* AD DIO Egress DMA Configuration Register 1 */
    volatile Uint32 AD_DIO_E_DMA_CFG2; /* AD DIO Egress DMA Configuration Register 2 */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW0; /* AD DIO Egress BCN Table 0 Row 0  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW1; /* AD DIO Egress BCN Table 0 Row 1  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW2; /* AD DIO Egress BCN Table 0 Row 2  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW3; /* AD DIO Egress BCN Table 0 Row 3  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW4; /* AD DIO Egress BCN Table 0 Row 4  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW5; /* AD DIO Egress BCN Table 0 Row 5  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW6; /* AD DIO Egress BCN Table 0 Row 6  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW7; /* AD DIO Egress BCN Table 0 Row 7  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW8; /* AD DIO Egress BCN Table 0 Row 8  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW9; /* AD DIO Egress BCN Table 0 Row 9  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW10; /* AD DIO Egress BCN Table 0 Row 10  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW11; /* AD DIO Egress BCN Table 0 Row 11  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW12; /* AD DIO Egress BCN Table 0 Row 12  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW13; /* AD DIO Egress BCN Table 0 Row 13  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW14; /* AD DIO Egress BCN Table 0 Row 14  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE0_ROW15; /* AD DIO Egress BCN Table 0 Row 15  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW0; /* AD DIO Egress BCN Table 1 Row 0  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW1; /* AD DIO Egress BCN Table 1 Row 1  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW2; /* AD DIO Egress BCN Table 1 Row 2  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW3; /* AD DIO Egress BCN Table 1 Row 3  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW4; /* AD DIO Egress BCN Table 1 Row 4  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW5; /* AD DIO Egress BCN Table 1 Row 5  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW6; /* AD DIO Egress BCN Table 1 Row 6  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW7; /* AD DIO Egress BCN Table 1 Row 7  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW8; /* AD DIO Egress BCN Table 1 Row 8  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW9; /* AD DIO Egress BCN Table 1 Row 9  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW10; /* AD DIO Egress BCN Table 1 Row 10  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW11; /* AD DIO Egress BCN Table 1 Row 11  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW12; /* AD DIO Egress BCN Table 1 Row 12  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW13; /* AD DIO Egress BCN Table 1 Row 13  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW14; /* AD DIO Egress BCN Table 1 Row 14  Register */
    volatile Uint32 AD_DIO_E_BCN_TABLE1_ROW15; /* AD DIO Egress BCN Table 1 Row 15  Register */
    volatile Uint8 RSVD0[108];
} CSL_Aif2Ad_dio_egressRegs; /* Group containing EGRESS configuration registers */

/**************************************************************************\
* Register Overlay Structure for TCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 TCHAN_GCFG_REG_A; /* The Tx Channel Configuration Register A contains real-time control and status information for the Tx DMA channel.  The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint32 TCHAN_GCFG_REG_B; /* The Tx Channel Configuration Register B is used to initialize the default return queue information for the Tx DMA channel.  This register may only be written when the channel is disabled (tx_enable is 0). */
    volatile Uint8 RSVD0[24];
} CSL_Aif2TchanRegs; /* tchannel */

/**************************************************************************\
* Register Overlay Structure for RCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 RCHAN_GCFG_REG_A; /* The Rx Channel Configuration Register A contains real-time control and status information for the Rx DMA channel.  The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint8 RSVD0[28];
} CSL_Aif2RchanRegs; /* rchannel */

/**************************************************************************\
* Register Overlay Structure for RFLOW
\**************************************************************************/
typedef struct  {
    volatile Uint32 RFLOW_CFG_REG_A; /* The Rx Flow N Configuration Register A contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_B; /* The Rx Flow N Configuration Register B contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_C; /* The Rx Flow N Configuration Register C contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_D; /* The Rx Flow N Configuration Register D contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_E; /* The Rx Flow N Configuration Register E contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_F; /* The Rx Flow N Configuration Register F contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_G; /* The Rx Flow N Configuration Register G contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_H; /* The Rx Flow N Configuration Register H contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
} CSL_Aif2RflowRegs; /* rflow */

/**************************************************************************\
* Register Overlay Structure for EE_LK
\**************************************************************************/
typedef struct  {
    volatile Uint32 EE_LK_IRS_A; /* EE Link Raw Status A Register */
    volatile Uint32 EE_LK_IRS_SET_A; /* EE Link Set Status A Register */
    volatile Uint32 EE_LK_IRS_CLR_A; /* EE Link Clear Status A Register */
    volatile Uint32 EE_LK_EN_A_EV0; /* EE Link Enable A EV0 Register */
    volatile Uint32 EE_LK_EN_A_SET_EV0; /* EE Link Enable A EV0 Set Register */
    volatile Uint32 EE_LK_EN_A_CLR_EV0; /* EE Link Enable A EV0 Clear Register */
    volatile Uint32 EE_LK_EN_A_EV1; /* EE Link Enable A EV1 Register */
    volatile Uint32 EE_LK_EN_A_SET_EV1; /* EE Link Enable A EV1 Set Register */
    volatile Uint32 EE_LK_EN_A_CLR_EV1; /* EE Link Enable A EV1 Clear Register */
    volatile Uint32 EE_LK_EN_STS_A_EV0; /* EE Link Enabled Status A EV0 Register */
    volatile Uint32 EE_LK_EN_STS_A_EV1; /* EE Link Enabled Status A EV1 Register */
    volatile Uint32 EE_LK_IRS_B; /* EE Link Raw Status B Register */
    volatile Uint32 EE_LK_IRS_SET_B; /* EE Link Set Status B Register */
    volatile Uint32 EE_LK_IRS_CLR_B; /* EE Link Clear Status B Register */
    volatile Uint32 EE_LK_EN_B_EV0; /* EE Link Enable B EV0 Register */
    volatile Uint32 EE_LK_EN_B_SET_EV0; /* EE Link Enable B EV0 Set Register */
    volatile Uint32 EE_LK_EN_B_CLR_EV0; /* EE Link Enable B EV0 Clear Register */
    volatile Uint32 EE_LK_EN_B_EV1; /* EE Link Enable B EV1 Register */
    volatile Uint32 EE_LK_EN_B_SET_EV1; /* EE Link Enable B EV1 Set Register */
    volatile Uint32 EE_LK_EN_B_CLR_EV1; /* EE Link Enable B EV1 Clear Register */
    volatile Uint32 EE_LK_EN_STS_B_EV0; /* EE Link Enabled Status B EV0 Register */
    volatile Uint32 EE_LK_EN_STS_B_EV1; /* EE Link Enabled Status B EV1 Register */
    volatile Uint8 RSVD0[40];
} CSL_Aif2Ee_lkRegs; /* EE link Registers */

/**************************************************************************\
* Register Overlay Structure for PI_Data
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_PIMAX_LK; /* at_pimax_lk */
    volatile Uint32 AT_PIMIN_LK; /* at_pimin_lk */
    volatile Uint32 AT_PIVALUE_LK; /* at_pivalue_lk */
} CSL_Aif2Pi_dataRegs; /* PI Data group */

/**************************************************************************\
* Register Overlay Structure for at_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_EVENT_OFFSET; /* at_event_offset */
    volatile Uint32 AT_EVENT_MOD_TC; /* at_event_mod_tc */
    volatile Uint32 AT_EVENT_MASK_LSBS; /* at_event_mask_lsbs */
    volatile Uint32 AT_EVENT_MASK_MSBS; /* at_event_mask_msbs */
} CSL_Aif2At_eventsRegs; /* AT events group */

/**************************************************************************\
* Register Overlay Structure for at_ad_ingr_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_AD_INGR_EVENT_OFFSET; /* at_ad_ingr_event_offset */
    volatile Uint32 AT_AD_INGR_EVENT_MOD_TC; /* at_ad_ingr_event_mod_tc */
} CSL_Aif2At_ad_ingr_eventsRegs; /* AT AD Ingress Events */

/**************************************************************************\
* Register Overlay Structure for at_ad_egr_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_AD_EGR_EVENT_OFFSET; /* at_ad_egr_event_offset */
    volatile Uint32 AT_AD_EGR_EVENT_MOD_TC; /* at_ad_egr_event_mod_tc */
} CSL_Aif2At_ad_egr_eventsRegs; /* AT AD Egress Event group */

/**************************************************************************\
* Register Overlay Structure for at_tm_delta_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_TM_DELTA_EVENT_OFFSET; /* at_tm_delta_event_offset sets the event offset. Strobe is always PHYT Frame boundary */
    volatile Uint32 AT_TM_DELTA_EVENT_MOD_TC; /* at_tm_delta_event_mod_tc configures the modulus terminal count */
} CSL_Aif2At_tm_delta_eventsRegs; /* AT AD Egress Event group */

/**************************************************************************\
* Register Overlay Structure for at_pe_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_PE_EVENT_OFFSET; /* at_pe_event_offset sets the event at_pe_evt0 offset. Strobe is always PHYT Frame boundary */
    volatile Uint32 AT_PE_EVENT_MOD_TC; /* at_pe_event_mod_tc configures the at_pe_evt0 modulus terminal count */
} CSL_Aif2At_pe_eventsRegs; /* AT PE at_pe_evt0 group */

/**************************************************************************\
* Register Overlay Structure for at_pe_event2s
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_PE_EVENT2_OFFSET; /* at_pe_event2_offset sets the event at_pe_evt1 offset. Strobe is always PHYT Frame boundary */
    volatile Uint32 AT_PE_EVENT2_MOD_TC; /* at_pe_event2_mod_tc configures the at_pe_evt1 modulus terminal count */
} CSL_Aif2At_pe_event2sRegs; /* AT PE at_pe_evt1 group */

/**************************************************************************\
* Register Overlay Structure for G_TM_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 TM_LK_CFG; /* The TM Configuration Register is used to program basic functionality of the Tx Mac Block. Bit 7 can be updated at any time to turn on or off the link, all other bits should only be updated if Bit 7 is 0 */
    volatile Uint32 TM_LK_CTRL; /* TM State Machine Control Register */
    volatile Uint32 TM_LK_SCR_CTRL; /* The Scrambler Configuration Register contains the seed initialization vector for the LFSR scrambler utilized when scrambling is enabled is OBSAI 8x mode, and the scrambler enable bit. This configuration register should only be updated when the Frame Sync state machine is disabled. */
    volatile Uint32 TM_LK_L1_CFG; /* Programs L1 inband control signals for CPRI mode */
    volatile Uint32 TM_LK_L1_EN; /* The L1 Inband Enable Register allows hardware control of the L1 inband control signals for CPRI mode. A 1 for each bit indicates the hardware control is enabled. Each enable bit is a gate on an input condition that could affect an output condition. The nomenclature is defined as TXSIGNAL_RXCOND_EN. The term ERR indicates the error had been determined by the RM, while the term RX refers to the actual L1 inband signal received by the RM. */
    volatile Uint32 TM_LK_LOSERR; /* Selects which RM link is used to drive the LOSERR condition to determine transmit L1 Inband signaling  */
    volatile Uint32 TM_LK_LOFERR; /* Selects which RM link is used to drive the LORERR condition to determine transmit L1 Inband signaling */
    volatile Uint32 TM_LK_LOSRX; /* Selects which RM link is used to drive the LOSRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 TM_LK_LOFRX; /* Selects which RM link is used to drive the LOFRx condition to determine transmit L1 Inband signaling */
    volatile Uint32 TM_LK_RAIRX; /* Selects which RM link is used to drive the RAIRx condition to determine transmit L1 Inband signaling  */
    volatile Uint32 TM_LK_HFN; /* TM CPRI HFN Status */
    volatile Uint32 TM_LK_PTRP; /* Contains Pointer P value */
    volatile Uint32 TM_LK_STRT; /* Contains Startup value */
    volatile Uint32 TM_LK_PROT; /* Contains Protocol Version value */
    volatile Uint32 TM_LK_STAT; /* The TM Status Register contains status of the TM block */
    volatile Uint32 TM_FRM_MODE; /* Enables Short Frame Mode */
    volatile Uint8 RSVD0[1984];
} CSL_Aif2G_tm_lksRegs; /* Group containing TM link registers */

/**************************************************************************\
* Register Overlay Structure for G_RM_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 RM_LK_CFG0; /* RM Link Configuration Register 0 */
    volatile Uint32 RM_LK_CFG1; /* RM Link Configuration Register 1 */
    volatile Uint32 RM_LK_CFG2; /* RM Link Configuration Register 2 */
    volatile Uint32 RM_LK_CFG3; /* RM Link Configuration Register 3 */
    volatile Uint32 RM_LK_CFG4; /* RM Link Configuration Register 4 */
    volatile Uint32 RM_LK_STS0; /* RM Link Status Register 0 */
    volatile Uint32 RM_LK_STS1; /* RM Link Status Register 1 */
    volatile Uint32 RM_LK_STS2; /* RM Link Status Register 2 */
    volatile Uint32 RM_LK_STS3; /* RM Link Status Register 3 */
    volatile Uint32 RM_LK_STS4; /* RM Link Status Register 4 */
    volatile Uint8 RSVD0[2008];
} CSL_Aif2G_rm_lksRegs; /* Group containing RM link registers */

/**************************************************************************\
* Register Overlay Structure for G_RT_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 RT_LK_CFG; /* RT Configuration Register */
    volatile Uint32 RT_LK_DPTH; /* RT FIFO DEPTH Status */
    volatile Uint32 RT_HDR_ERR; /* RT Header Error Status */
    volatile Uint32 RT_LK_STAT; /* The RT Status Register contains status of the RT block */
    volatile Uint8 RSVD0[2032];
} CSL_Aif2G_rt_lksRegs; /* Group containing RT link registers */

/**************************************************************************\
* Register Overlay Structure for G_CI_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 CI_LK_CFG; /* CI Configuration Register */
    volatile Uint8 RSVD0[2044];
} CSL_Aif2G_ci_lksRegs; /* Group containing CI link registers */

/**************************************************************************\
* Register Overlay Structure for G_CO_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 CO_LK_CFG; /* CO Configuration Register */
    volatile Uint8 RSVD0[2044];
} CSL_Aif2G_co_lksRegs; /* Group containing CO link registers */

/**************************************************************************\
* Register Overlay Structure for G_PD_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 PD_LINK_A; /* Link-by-Link:Link Specific parameters */
    volatile Uint32 PD_LINK_B; /* Link-by-Link:Link Specific parameters relating to CPRI usage only */
    volatile Uint32 PD_LK_PACK_CPRI; /* Bit swap controls for each control channel before or after 4B,5B,Null decoding */
    volatile Uint8 RSVD0[8];
    volatile Uint32 PD_CPRI_CRC; /* Link-by-Link: PD dicates CRC to be used for each of 4 possible CPRI packets streams */
    volatile Uint32 PD_PACK_MAP; /* Link-by-Link: PD four custom packet packing circuits for CPRI CW & AxC usage as packet traffic.  This register maps which DMA channel should be used for each of the four custom pack circuts */
    volatile Uint32 PD_DBM; /* Link-by-Link: Parameters for configuring the CPRI Dual Bit Map FSM.  CPRI DBM is used to rate matching and un-packing radio standards with non-WCDMA like sampling frequency */
    volatile Uint32 PD_DBM_1MAP[4]; /* Link-by-Link: PD DBMF bit map1 Registers */
    volatile Uint32 PD_DBM_2MAP[3]; /* Link-by-Link: PD DBMF bit map2 (31:0) Register */
    volatile Uint8 RSVD1[68];
    volatile Uint32 PD_TYPE_LUT[32]; /* Link-by-Link: OBSAI Type Look Up Table.  Allows for new OBSAI types to be defined (and reconfiguation of exisiting Types).  SW should set these values via ROM look up */
    volatile Uint8 RSVD2[256];
    volatile Uint32 PD_CPRI_ID_LUT[128]; /* Link-by-Link x128 CPRI chan per link: PD CPRI Steam LUT Register */
    volatile Uint32 PD_CW_LUT[256]; /* Link-by-Link x256 CPRI CW per hyper frame: PD CPRI CW LUT Register */
} CSL_Aif2G_pd_lksRegs; /* Group containing PD link registers */

/**************************************************************************\
* Register Overlay Structure for G_PE_LKS
\**************************************************************************/
typedef struct  {
    volatile Uint32 PE_LINK; /* PE Link Register */
    volatile Uint32 PE_CRC; /* CRC configuration */
    volatile Uint32 PE_CPRI_DBM; /* Link-by-Link: Parameters for configuring the CPRI Dual Bit Map FSM.  CPRI DBM is used to rate matching and un-packing radio standards with non-WCDMA like sampling frequency.  CPRI DBM counts through samples (nominally 4bytes per AxC) */
    volatile Uint32 PE_CPRI_BITSWAP; /* Bit swap controls for each control channel before or after 4B,5B,Null encoding */
    volatile Uint32 PE_CPRIDBM_1MAP[4]; /* Link-by-Link: PE DBMF bit map1 (127:0) Register */
    volatile Uint32 PE_CPRIDBM_2MAP[3]; /* Link-by-Link: PE DBMF bit map2 (95:0) Register */
    volatile Uint32 PE_CPRI0; /* Link-by-Link:Link Specific parameters relating to CPRI usage only */
    volatile Uint32 PE_CPRI1; /* Link-by-Link: PE four custom packet packing circuits for CPRI CW & AxC usage as packet traffic.  This register maps which DMA channel should be used for each of the four custom pack circuts */
    volatile Uint8 RSVD0[972];
    volatile Uint32 PE_CPRI_CW_LUT[256]; /* Link-by-Link x256 CPRI CW per hyper frame: pe CPRI CW LUT Register */
} CSL_Aif2G_pe_lksRegs; /* Group containing PE link registers. */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 AIF2_PID; /* aif2 Periperal ID Register */
    volatile Uint32 AIF2_SCRATCH; /* VC Scratch Register */
    volatile Uint32 AIF2_RESET; /* at sw sync */
    volatile Uint32 AIF2_EMU; /* aif2 Emulation Control Register */
    volatile Uint32 VC_STAT; /* VC Status Register */
    volatile Uint8 RSVD0[16364];
    volatile Uint32 EE_VB_EOI; /* This register supports the End of Interrupt (EOI) interface between the AIF2 and the external Interrupt Distributor Component used in the Highlander 0.1 Interrupt Architecture.  It is a common register that is used for servicing both of the AIF2 interrupts. This register is written by software to acknowledge the interrupt has been cleared so another interrupt of the same type can be generated by the Interrupt Distributor Component.  This register is written after a AIF2 interrupt has been cleared via the associated Interrupt Clear register. Writes to this register have no effect on the internal interrupt processing of the AIF2. */
    volatile Uint32 EE_VB_INTR_SET; /* This register allows software to create an AIF2 Error Interrupt or AIF2 Alarm Interrupt by writing bits in this register.  This register is provided for debug and diagnostics. */
    volatile Uint32 EE_VB_INTR_CLR; /* This register allows software to clear an AIF2 Error Interrupt or AIF2 Alarm Interrupt by writing bits in this register.  This register is provided for debug and diagnostics. */
    volatile Uint8 RSVD1[244];
    volatile Uint32 EE_DB_IRS; /* EE DB Raw Status Register */
    volatile Uint32 EE_DB_IRS_SET; /* EE DB Set Status Register */
    volatile Uint32 EE_DB_IRS_CLR; /* EE DB Clear Status Register */
    volatile Uint32 EE_DB_EN_EV0; /* EE DB Enable EV0 Register */
    volatile Uint32 EE_DB_EN_SET_EV0; /* EE DB Set Enable EV0 Register */
    volatile Uint32 EE_DB_EN_CLR_EV0; /* EE DB Clear Enable EV0 Register */
    volatile Uint32 EE_DB_EN_EV1; /* EE DB Enable EV1 Register */
    volatile Uint32 EE_DB_EN_SET_EV1; /* EE DB Set Enable EV1 Register */
    volatile Uint32 EE_DB_EN_CLR_EV1; /* EE DB Clear Enable EV1 Register */
    volatile Uint32 EE_DB_EN_STS_EV0; /* EE DB Enabled Status EV0 Register */
    volatile Uint32 EE_DB_EN_STS_EV1; /* EE DB Enabled Status EV1 Register */
    volatile Uint8 RSVD2[212];
    volatile Uint32 EE_AD_IRS; /* EE AD Raw Status Register */
    volatile Uint32 EE_AD_IRS_SET; /* EE AD Set Status Register */
    volatile Uint32 EE_AD_IRS_CLR; /* EE AD Clear Status Register */
    volatile Uint32 EE_AD_EN_EV0; /* EE AD Enable EV0 Register */
    volatile Uint32 EE_AD_EN_SET_EV0; /* EE AD Set Enable EV0 Register */
    volatile Uint32 EE_AD_EN_CLR_EV0; /* EE AD Clear Enable EV0 Register */
    volatile Uint32 EE_AD_EN_EV1; /* EE AD Enable EV1 Register */
    volatile Uint32 EE_AD_EN_SET_EV1; /* EE AD Set Enable EV1 Register */
    volatile Uint32 EE_AD_EN_CLR_EV1; /* EE AD Clear Enable EV1 Register */
    volatile Uint32 EE_AD_EN_STS_EV0; /* EE AD Enabled Status EV0 Register */
    volatile Uint32 EE_AD_EN_STS_EV1; /* EE AD Enabled Status EV1 Register */
    volatile Uint8 RSVD3[212];
    volatile Uint32 EE_CD_IRS; /* EE CD Raw Status Register */
    volatile Uint32 EE_CD_IRS_SET; /* EE CD Set Status Register */
    volatile Uint32 EE_CD_IRS_CLR; /* EE CD Clear Status Register */
    volatile Uint32 EE_CD_EN_EV; /* EE CD Enable EV0 Register */
    volatile Uint32 EE_CD_EN_SET_EV; /* EE CD Set Enable EV0 Register */
    volatile Uint32 EE_CD_EN_CLR_EV; /* EE CD Clear Enable EV0 Register */
    volatile Uint32 EE_CD_EN_STS_EV; /* EE CD Enabled Status EV0 Register */
    volatile Uint8 RSVD4[228];
    volatile Uint32 EE_SD_IRS; /* EE SD Raw Status Register */
    volatile Uint32 EE_SD_IRS_SET; /* EE SD Set Status Register */
    volatile Uint32 EE_SD_IRS_CLR; /* EE SD Clear Status Register */
    volatile Uint32 EE_SD_EN_EV0; /* EE SD Enable EV0 Register */
    volatile Uint32 EE_SD_EN_SET_EV0; /* EE SD Enable Set EV0 Register */
    volatile Uint32 EE_SD_EN_CLR_EV0; /* EE SD Enable Clear EV0 Register */
    volatile Uint32 EE_SD_EN_EV1; /* EE SD Enable EV1 Register */
    volatile Uint32 EE_SD_EN_SET_EV1; /* EE SD Enable Set EV1 Register */
    volatile Uint32 EE_SD_EN_CLR_EV1; /* EE SD Enable Clear EV1 Register */
    volatile Uint32 EE_SD_EN_STS_EV0; /* EE SD Enabled Status EV0 Register */
    volatile Uint32 EE_SD_EN_STS_EV1; /* EE SD Enabled Status EV1 Register */
    volatile Uint8 RSVD5[212];
    volatile Uint32 EE_VC_IRS; /* EE VC Raw Status Register */
    volatile Uint32 EE_VC_IRS_SET; /* EE VC Set Status Register */
    volatile Uint32 EE_VC_IRS_CLR; /* EE VC Clear Status Register */
    volatile Uint32 EE_VC_EN_EV0; /* EE VC Enable EV0 Register */
    volatile Uint32 EE_VC_EN_SET_EV0; /* EE VC Enable Set EV0 Register */
    volatile Uint32 EE_VC_EN_CLR_EV0; /* EE VC Enable Clear EV0 Register */
    volatile Uint32 EE_VC_EN_EV1; /* EE VC Enable EV1 Register */
    volatile Uint32 EE_VC_EN_SET_EV1; /* EE VC Enable Set EV1 Register */
    volatile Uint32 EE_VC_EN_CLR_EV1; /* EE VC Enable Clear EV1 Register */
    volatile Uint32 EE_VC_EN_STS_EV0; /* EE VC Enabled Status EV0 Register */
    volatile Uint32 EE_VC_EN_STS_EV1; /* EE VC Enabled Status EV1 Register */
    volatile Uint8 RSVD6[212];
    volatile Uint32 EE_AIF2_RUN_STS; /* This register is used to indicate the state of AIF2  */
    volatile Uint32 EE_AIF2_RUN_CTL; /* This register is used to indicate the state of AIF2  */
    volatile Uint8 RSVD7[248];
    volatile Uint32 EE_ERR_ALRM_ORGN; /* EE Register used to determine which EN_STSregister contains the error/alarm that caused an event */
    volatile Uint8 RSVD8[14588];
    CSL_Aif2Sd_lkRegs SD_LK[6];
    volatile Uint32 SD_PLL_B8_EN_CFG; /* B8 PLL configuration Register */
    volatile Uint32 SD_PLL_B4_EN_CFG; /* B4 PLL configuration Register */
    volatile Uint8 RSVD9[8];
    volatile Uint32 SD_PLL_B8_STS; /* B8 PLL Status Register */
    volatile Uint32 SD_PLL_B4_STS; /* B4 PLL Status Register */
    volatile Uint32 SD_CLK_SEL_CFG; /* Clock selection */
    volatile Uint32 SD_LK_CLK_DIS_CFG; /* Link clock Enable Register */
    volatile Uint8 RSVD10[4064];
    CSL_Aif2Ad_dio_ingressRegs AD_DIO_INGRESS[3];
    CSL_Aif2Ad_dio_egressRegs AD_DIO_EGRESS[3];
    volatile Uint32 AD_DIO_DT_DMA_CFG0; /* AD DIO Data Trace DMA Configuration Register 0 */
    volatile Uint32 AD_DIO_DT_DMA_CFG1; /* AD DIO Data Trace DMA Configuration Register 1 */
    volatile Uint32 AD_DIO_DT_DMA_CFG2; /* AD DIO Data Trace DMA Configuration Register 2 */
    volatile Uint32 AD_DIO_DT_DMA_CFG3; /* AD DIO Data Trace DMA Configuration Register 3 */
    volatile Uint32 AD_DIO_I_GLOBAL_EN_SET; /* Set Global Enable for AD Ingress DIO */
    volatile Uint32 AD_DIO_I_GLOBAL_EN_CLR; /* Clear Global Enable for AD Ingress DIO */
    volatile Uint32 AD_DIO_I_GLOBAL_EN_STS; /* Read Only status of AD Ingress DIO global enable state. */
    volatile Uint32 AD_DIO_E_GLOBAL_EN_SET; /* Set Global Enable for AD Egress DIO */
    volatile Uint32 AD_DIO_E_GLOBAL_EN_CLR; /* Clear Global Enable for AD Egress DIO */
    volatile Uint32 AD_DIO_E_GLOBAL_EN_STS; /* Read Only status of AD Egress DIO global enable state. */
    volatile Uint8 RSVD11[6616];
    volatile Uint32 AD_ISCH_CFG; /* AD Scheduler Ingress Configuration Register */
    volatile Uint32 AD_ISCH_GLOBAL_EN_SET; /* Set Global Enable for AD Ingress Scheduler */
    volatile Uint32 AD_ISCH_GLOBAL_EN_CLR; /* Clear Global Enable for AD Ingress Scheduler */
    volatile Uint32 AD_ISCH_GLOBAL_EN_STS; /* Read Only status of AD Ingress Scheduler global enable state. */
    volatile Uint32 AD_ISCH_EOP_CNT; /* This register provides a count of the EOPs sent to the CPPI DMA Controller for activity monitoring. */
    volatile Uint8 RSVD12[236];
    volatile Uint32 AD_ESCH_CFG; /* AD Scheduler Egress Configuration Register */
    volatile Uint32 AD_ESCH_GLOBAL_EN_SET; /* Set Global Enable for AD Egress Scheduler */
    volatile Uint32 AD_ESCH_GLOBAL_EN_CLR; /* Clear Global Enable for AD Egress Scheduler */
    volatile Uint32 AD_ESCH_GLOBAL_EN_STS; /* Read Only status of AD Egress Scheduler global enable state. */
    volatile Uint8 RSVD13[7920];
    volatile Uint32 DB_IDB_CFG; /* Ingress Data Buffer Configuration Register */
    volatile Uint32 DB_IDB_GLOBAL_EN_SET; /* Set Global Enable for Ingress DB */
    volatile Uint32 DB_IDB_GLOBAL_EN_CLR; /* Clear Global Enable for Ingress DB */
    volatile Uint32 DB_IDB_GLOBAL_EN_STS; /* Read Only status of Ingress DB global enable state. */
    volatile Uint32 DB_IDB_CH_EN[4]; /* Ingress Data Buffer Channel Enable Register. Enables for 32 contiguous Ingress data buffer channels as follows:  DB_IDB_CH_EN[0] -> channels[31:0]; DB_IDB_CH_EN[1] -> channels[63:32]; DB_IDB_CH_EN[2] -> channels[95:64]; DB_IDB_CH_EN[3] -> channels[127:96]; */
    volatile Uint8 RSVD14[224];
    volatile Uint32 DB_IDB_DEBUG_D0; /* Ingress DB Debug Data Register 0 */
    volatile Uint32 DB_IDB_DEBUG_D1; /* Ingress DB Debug Data Register 1 */
    volatile Uint32 DB_IDB_DEBUG_D2; /* Ingress DB Debug Data Register 2 */
    volatile Uint32 DB_IDB_DEBUG_D3; /* Ingress DB Debug Data Register 3 */
    volatile Uint32 DB_IDB_DEBUG_SBND; /* This register provides sideband data that is written into the Ingress DB RAM during debug.  */
    volatile Uint32 DB_IDB_DEBUG_DB_WR; /* A write of any value to this register writes the data in the following registers into the Ingress DB RAM and sideband RAMS:  DB_IDB_DEBUG_D0, DB_IDB_DEBUG_D1, DB_IDB_DEBUG_D2, DB_IDB_DEBUG_D3, DB_IDB_DEBUG_SBDN0, DB_IDB_DEBUG_SBDN1 */
    volatile Uint32 DB_IDB_DEBUG_OFS; /* This register provides the addresses to access the Ingress read and write offset RAMs for debug. */
    volatile Uint32 DB_IDB_DEBUG_OFS_DAT; /* This register contains the offset value read from the Ingress read and write offset RAMs for debug. */
    volatile Uint8 RSVD15[224];
    volatile Uint32 DB_IDB_PTR_CH[128]; /* There is a separate register for each of the 128 Ingress Data Buffer channels.  These registers are used to create the read and write addresses to the Ingress DB RAM.  */
    volatile Uint32 DB_IDB_CFG_CH[128]; /* There is a separate register for each of the 128 Ingress Buffer channels.  These registers provide configuration data for each channel when it is read. */
    volatile Uint32 DB_IDB_CH_EMPTY[4]; /* Ingress Data Buffer Channel Empty Register. Empty bits for 32 contiguous Ingress data buffer channels as follows:  DB_IDB_CH_EMPTY[0] -> channels[31:0]; DB_IDB_CH_EMPTY[1] -> channels[63:32]; DB_IDB_CH_EMPTY[2] -> channels[95:64]; DB_IDB_CH_EMPTY[3] -> channels[127:96]; */
    volatile Uint8 RSVD16[2544];
    volatile Uint32 DB_EDB_CFG; /* Egress Data Buffer Configuration Register */
    volatile Uint32 DB_EDB_GLOBAL_EN_SET; /* Set Global Enable for Egress DB */
    volatile Uint32 DB_EDB_GLOBAL_EN_CLR; /* Clear Global Enable for Egress DB */
    volatile Uint32 DB_EDB_GLOBAL_EN_STS; /* Read Only status of Egress DB global enable state. */
    volatile Uint32 DB_EDB_CH_EN[4]; /* Egress Data Buffer Channel Enable Register. Enables for 32 contiguous Egress data buffer channels as follows:  DB_EDB_CH_EN[0] -> channels[31:0]; DB_EDB_CH_EN[1] -> channels[63:32]; DB_EDB_CH_EN[2] -> channels[95:64]; DB_EDB_CH_EN[3] -> channels[127:96]; */
    volatile Uint8 RSVD17[224];
    volatile Uint32 DB_EDB_DEBUG_D0; /* Egress DB Debug Data Register 0. */
    volatile Uint32 DB_EDB_DEBUG_D1; /* Egress DB Debug Data Register 1. */
    volatile Uint32 DB_EDB_DEBUG_D2; /* Egress DB Debug Data Register 2. */
    volatile Uint32 DB_EDB_DEBUG_D3; /* Egress DB Debug Data Register 3. */
    volatile Uint32 DB_EDB_DEBUG_SBND; /* This register provides part of the sideband data that is written into the Egress DB RAM during debug. */
    volatile Uint32 DB_EDB_DEBUG_RD_CNTL; /* This register provides the controls necessary to read the Egress DB RAM during debug. */
    volatile Uint8 RSVD18[4];
    volatile Uint32 DB_EDB_DEBUG_DB_RD; /* A write of any value to this register initiates a read to the Egress DB data and sideband RAMs and writes the contents into the following registers:   DB_EDB_DEBUG_D0, DB_EDB_DEBUG_D1, DB_EDB_DEBUG_D2, DB_EDB_DEBUG_D3, DB_EDB_DEBUG_SBND */
    volatile Uint32 DB_EDB_DEBUG_OFS; /* This register provides the addresses to access the Egress read and write offset RAMs for debug. */
    volatile Uint32 DB_EDB_DEBUG_OFS_DAT; /* This register contains the offset value read from the Egress read and write offset RAMs for debug. */
    volatile Uint32 DB_EDB_DEBUG_WR_TOK; /* A write of any value to this register results in a token with the value loaded into DB_EDB_DEBUG_RD_CNTL.CH_ID being issued to the AxC Token FIFO  */
    volatile Uint32 DB_EDB_EOP_CNT; /* This register provides a count of the Egress EOPs received from the CPPI DMA Controller for activity monitoring. */
    volatile Uint8 RSVD19[208];
    volatile Uint32 DB_EDB_PTR_CH[128]; /* There is a separate register for each of the 128 Egress Data Buffer channels.  These registers are used to create the read and write addresses to the Egress DB RAM.  */
    volatile Uint32 DB_EDB_CFG_CH[128]; /* There is a separate register for each of the 128 Egress Buffer channels.  These registers provide configuration data for each channel when it is read. */
    volatile Uint8 RSVD20[10752];
    volatile Uint32 REVISION_REG; /* The Revision Register contains the major and minor revisions for the module. */
    volatile Uint32 PERF_CTRL_REG; /* The performance control register contains fields which can be used to adjust the performance of the CDMAHP in the system. */
    volatile Uint32 EMU_CTRL_REG; /* The emulation control register is used to control the behavior of the DMA when the emususp input is asserted. */
    volatile Uint32 PRI_CTRL_REG; /* The priority control register is used to control the priority of the transactions which the DMA generates on it's master interface. */
    volatile Uint32 QM0_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 0. */
    volatile Uint32 QM1_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 1. */
    volatile Uint32 QM2_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 2. */
    volatile Uint32 QM3_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 3. */
    volatile Uint8 RSVD21[8160];
    CSL_Aif2TchanRegs TCHAN[129];
    volatile Uint8 RSVD22[4064];
    CSL_Aif2RchanRegs RCHAN[129];
    volatile Uint8 RSVD23[4064];
    CSL_Aif2RflowRegs RFLOW[129];
    volatile Uint8 RSVD24[151520];
    CSL_Aif2Ee_lkRegs EE_LK[6];
    volatile Uint32 EE_AT_IRS; /* EE AT Raw Status Register */
    volatile Uint32 EE_AT_IRS_SET; /* EE AT Set Status Register */
    volatile Uint32 EE_AT_IRS_CLR; /* EE AT Clear Status Register */
    volatile Uint32 EE_AT_EN_EV0; /* EE AT Enable EVO Register */
    volatile Uint32 EE_AT_EN_SET_EV0; /* EE AT Enable Set EV0 Register */
    volatile Uint32 EE_AT_EN_CLR_EV0; /* EE AT Enable Clear EV0 Register */
    volatile Uint32 EE_AT_EN_EV1; /* EE AT Enable EV1 Register */
    volatile Uint32 EE_AT_EN_SET_EV1; /* EE AT Enable Set EV1 Register */
    volatile Uint32 EE_AT_EN_CLR_EV1; /* EE AT Enable Clear EV1 Register */
    volatile Uint32 EE_AT_EN_STS_EV0; /* EE AT Enabled Status EV0 Register */
    volatile Uint32 EE_AT_EN_STS_EV1; /* EE AT Enabled Status EV1 Register */
    volatile Uint8 RSVD25[212];
    volatile Uint32 EE_PD_COMMON_IRS; /* EE PD Common Raw Status Register */
    volatile Uint32 EE_PD_COMMON_IRS_SET; /* EE PD Common Set Status Register */
    volatile Uint32 EE_PD_COMMON_IRS_CLR; /* EE PD Common Clear Status Register */
    volatile Uint32 EE_PD_COMMON_EN_EV0; /* EE PD Common Enable EVO Register */
    volatile Uint32 EE_PD_COMMON_EN_SET_EV0; /* EE PD Common Enable Set EV0 Register */
    volatile Uint32 EE_PD_COMMON_EN_CLR_EV0; /* EE PD Common Enable Clear EV0 Register */
    volatile Uint32 EE_PD_COMMON_EN_EV1; /* EE PD Common Enable EV1 Register */
    volatile Uint32 EE_PD_COMMON_EN_SET_EV1; /* EE PD Common Enable Set EV1 Register */
    volatile Uint32 EE_PD_COMMON_EN_CLR_EV1; /* EE PD Common Enable Clear EV1 Register */
    volatile Uint32 EE_PD_COMMON_EN_STS_EV0; /* EE PD Common Enabled Status EV0 Register */
    volatile Uint32 EE_PD_COMMON_EN_STS_EV1; /* EE PD Common Enabled Status EV1 Register */
    volatile Uint8 RSVD26[212];
    volatile Uint32 EE_PE_COMMON_IRS; /* EE PE Common Raw Status Register */
    volatile Uint32 EE_PE_COMMON_IRS_SET; /* EE PE Common Set Status Register */
    volatile Uint32 EE_PE_COMMON_IRS_CLR; /* EE PE Common Clear Status Register */
    volatile Uint32 EE_PE_COMMON_EN_EV0; /* EE PE Common Enable EVO Register */
    volatile Uint32 EE_PE_COMMON_EN_SET_EV0; /* EE PE Common Enable Set EV0 Register */
    volatile Uint32 EE_PE_COMMON_EN_CLR_EV0; /* EE PE Common Enable Clear EV0 Register */
    volatile Uint32 EE_PE_COMMON_EN_EV1; /* EE PE Common Enable EV1 Register */
    volatile Uint32 EE_PE_COMMON_EN_SET_EV1; /* EE PE Common Enable Set EV1 Register */
    volatile Uint32 EE_PE_COMMON_EN_CLR_EV1; /* EE PE Common Enable Clear EV1 Register */
    volatile Uint32 EE_PE_COMMON_EN_STS_EV0; /* EE PE Common Enabled Status EV0 Register */
    volatile Uint32 EE_PE_COMMON_EN_STS_EV1; /* EE PE Common Enabled Status EV1 Register */
    volatile Uint8 RSVD27[31444];
    volatile Uint32 AT_CONTROL1; /* at_control1 */
    volatile Uint32 AT_CONTROL2; /* at_control2 */
    volatile Uint32 AT_SW_SYNC; /* at sw sync */
    volatile Uint32 AT_PHYT_CMP_RADSYNC; /* at phyt radsync compare */
    volatile Uint32 AT_RP1_TYPE; /* at rp1 type */
    volatile Uint32 AT_CAPTRADT; /* Capture RADT clock and symbol and 5bit frame lsb counts on PHYT frame boundary */
    volatile Uint8 RSVD28[8];
    volatile Uint32 AT_RP1_TYPE_CAPTURE; /* at rp1 type capture */
    volatile Uint32 AT_RP1_TOD_CAPTURE_L; /* at_rp1_tod_capture_l */
    volatile Uint32 AT_RP1_TOD_CAPTURE_H; /* at_rp1_tod_capture_h */
    volatile Uint32 AT_RP1_RP3_CAPTURE_L; /* at_rp1_rp3_capture_l */
    volatile Uint32 AT_RP1_RP3_CAPTURE_H; /* at_rp1_rp3_capture_h */
    volatile Uint32 AT_RP1_RAD_CAPTURE_L; /* at_rp1_rad_capture_l */
    volatile Uint32 AT_RP1_RAD_CAPTURE_H; /* at_rp1_rad_capture_h */
    volatile Uint8 RSVD29[4];
    volatile Uint32 AT_PHYT_CLKCNT_VALUE; /* at_phyt_clkcnt_value */
    volatile Uint32 AT_PHYT_FRM_VALUE_LSBS; /* at_phyt_frm_value_lsbs */
    volatile Uint32 AT_PHYT_FRM_VALUE_MSBS; /* at_phyt_frm_value_msbs */
    volatile Uint32 AT_RADT_VALUE_LSBS; /* at_radt_value_lsbs */
    volatile Uint32 AT_RADT_VALUE_MID; /* at_radt_value_mid */
    volatile Uint32 AT_RADT_VALUE_MSBS; /* at_radt_value_msbs */
    volatile Uint32 AT_ULRADT_VALUE_LSBS; /* at_ulradt_value_lsbs */
    volatile Uint32 AT_ULRADT_VALUE_MID; /* at_ulradt_value_mid */
    volatile Uint32 AT_ULRADT_VALUE_MSBS; /* at_ulradt_value_msbs */
    volatile Uint32 AT_DLRADT_VALUE_LSBS; /* at_dlradt_value_lsbs */
    volatile Uint32 AT_DLRADT_VALUE_MID; /* at_dlradt_value_mid */
    volatile Uint32 AT_DLRADT_VALUE_MSBS; /* at_dlradt_value_msbs */
    volatile Uint32 AT_RADT_WCDMA_VALUE; /* at_radt_wcdma_value */
    volatile Uint32 AT_ULRADT_WCDMA_VALUE; /* at_ulradt_wcdma_value */
    volatile Uint32 AT_DLRADT_WCDMA_VALUE; /* at_dlradt_wcdma_value */
    volatile Uint32 AT_RADT_WCDMA_DIV; /* at radt wcdma clock divider terminal count. */
    volatile Uint32 AT_PHYT_INIT_LSBS; /* at_phyt_init_lsbs */
    volatile Uint32 AT_PHYT_INIT_MID; /* at_phyt_init_mid */
    volatile Uint32 AT_PHYT_INIT_MSBS; /* at_phyt_init_msbs */
    volatile Uint32 AT_PHYT_TC_LSBS; /* at_phyt_tc_lsbs */
    volatile Uint32 AT_PHYT_FRAME_TC_LSBS; /* at_phyt_frame_tc_lsbs */
    volatile Uint32 AT_PHYT_FRAME_TC_MSBS; /* at_phyt_frame_tc_msbs */
    volatile Uint32 AT_RADT_INIT_LSBS; /* at_radt_init_lsbs */
    volatile Uint32 AT_RADT_INIT_MID; /* at_radt_init_mid */
    volatile Uint32 AT_RADT_INIT_MSBS; /* at_radt_init_msbs */
    volatile Uint32 AT_ULRADT_INIT_LSBS; /* at_ulradt_init_lsbs */
    volatile Uint32 AT_RADT_TSTAMP_VALUE; /* at_radt_tstamp_value */
    volatile Uint8 RSVD30[4];
    volatile Uint32 AT_DLRADT_INIT_LSBS; /* at_dlradt_init_lsbs */
    volatile Uint32 AT_GSM_TCOUNT_INIT; /* at_gsm_tcount initialization */
    volatile Uint32 AT_GSM_TCOUNT_VALUE; /* at_gsm_tcount value */
    volatile Uint32 AT_RADT_SYMB_LUT_INDEX_TC; /* at_radt_symb_lut_index_tc */
    volatile Uint8 RSVD31[8];
    volatile Uint32 AT_RADT_FRAME_TC_LSBS; /* at_radt_frame_tc_msbs */
    volatile Uint32 AT_RADT_FRAME_TC_MSBS; /* at_radt_frame_tc_lsbs */
    volatile Uint8 RSVD32[16];
    volatile Uint32 AT_ULRADT_INIT_MID; /* at_ulradt_init_mid */
    volatile Uint32 AT_ULRADT_INIT_MSBS; /* at_ulradt_init_msbs */
    volatile Uint32 AT_DLRADT_INIT_MID; /* at_dlradt_init_mid */
    volatile Uint32 AT_DLRADT_INIT_MSBS; /* at_dlradt_init_msbs */
    volatile Uint8 RSVD33[4];
    volatile Uint32 AT_RADT_INIT_LUT_INDEX; /* at_radt LUT Index initial value */
    volatile Uint32 AT_ULRADT_INIT_LUT_INDEX; /* at_ulradt LUT Index initial value */
    volatile Uint32 AT_DLRADT_INIT_LUT_INDEX; /* at_dlradt LUT Index initial value */
    CSL_Aif2Pi_dataRegs PI_DATA[6];
    volatile Uint32 AT_NEG_DELTA; /* Negative delta control */
    volatile Uint8 RSVD34[172];
    volatile Uint32 AT_EVT_ENABLE; /* at_evt_enable */
    volatile Uint32 AT_EVT_FORCE; /* at_evt_force */
    CSL_Aif2At_eventsRegs AT_EVENTS[24];
    volatile Uint8 RSVD35[120];
    volatile Uint32 AT_INTERNAL_EVT_ENABLE; /* at_internal_evt_enable. LSB for each field corresponds to the lowest event number for that field. */
    volatile Uint32 AT_INTERNAL_EVT_FORCE; /* at_internal_evt_force */
    CSL_Aif2At_ad_ingr_eventsRegs AT_AD_INGR_EVENTS[6];
    volatile Uint8 RSVD36[208];
    CSL_Aif2At_ad_egr_eventsRegs AT_AD_EGR_EVENTS[6];
    volatile Uint8 RSVD37[16];
    CSL_Aif2At_tm_delta_eventsRegs AT_TM_DELTA_EVENTS[6];
    volatile Uint8 RSVD38[16];
    CSL_Aif2At_pe_eventsRegs AT_PE_EVENTS[6];
    CSL_Aif2At_pe_event2sRegs AT_PE_EVENT2S[6];
    volatile Uint8 RSVD39[6688];
    volatile Uint32 AT_RADT_SYM_LUT_RAM[128]; /* at_radt_sym_lut_ram */
    volatile Uint8 RSVD40[7680];
    CSL_Aif2G_tm_lksRegs G_TM_LKS[6];
    volatile Uint8 RSVD41[4096];
    CSL_Aif2G_rm_lksRegs G_RM_LKS[6];
    volatile Uint32 RM_CFG; /* RM Configuration Register */
    volatile Uint8 RSVD42[4092];
    CSL_Aif2G_rt_lksRegs G_RT_LKS[6];
    volatile Uint8 RSVD43[4096];
    CSL_Aif2G_ci_lksRegs G_CI_LKS[6];
    volatile Uint8 RSVD44[4096];
    CSL_Aif2G_co_lksRegs G_CO_LKS[6];
    volatile Uint8 RSVD45[4096];
    CSL_Aif2G_pd_lksRegs G_PD_LKS[6];
    volatile Uint32 PD_GLOBAL; /* Fields which are global for the entire PD */
    volatile Uint32 DB_PD_GLOBAL_EN_SET; /* Set Global Enable for PD */
    volatile Uint32 DB_PD_GLOBAL_EN_CLR; /* Clear Global Enable for PD */
    volatile Uint32 PD_GLOBAL_EN_STS; /* Read Only status of global enable state.  Even if this register is OFF, PD may still be closing out packets. */
    volatile Uint32 PD_DMA; /* Controls DMA funcationality which is common ammong all links */
    volatile Uint32 PD_RADT_TC; /* OBSAI timing control, RadT usage (used for OBSAI LTE & WiMax */
    volatile Uint8 RSVD46[8];
    volatile Uint32 PD_CHAN_STS[4]; /* Gives current On/Off Status of every available stream.  One bit per channel.  Required because channels only turn on/off on radio frame or packet frame boundaries so the chan_en alone does not give channel status (Each of 4 registers represents 32 of 128 channels) */
    volatile Uint32 PD_PKT_STS[4]; /* Gives current In/Out Packet Status of every available stream.  One bit per channel.  Helps debug if PD is not shutting down */
    volatile Uint32 PD_FRM_TC[6]; /* For framing state machine, supplies terminal counts of some of the state counters and some start counts.  Six different versions of this register are used to support LTE variations, 3 BW an d2 symbol lengths simultaniously */
    volatile Uint8 RSVD47[936];
    volatile Uint32 PD_ROUTE[128]; /* x128 DMA chan: Information used to decode OBSAI header information for routing into DMA channels. */
    volatile Uint32 PD_DMACHAN[128]; /* x128 DMA chan: PD Channel Control Fields Register 0 */
    volatile Uint8 RSVD48[2048];
    volatile Uint32 PD_DMACHAN_A[128]; /* x128 DMA chan: PD Channel Control Fields Register 0 */
    volatile Uint32 PD_DMACHAN_B[128]; /* x128 DMA chan: PD Channel Control Fields Register 1 */
    volatile Uint32 PD_DMACHAN_C[128]; /* x128 DMA chan: 2nd portion of TDD_EN */
    volatile Uint32 PD_DMACHAN_D[128]; /* x128 DMA chan: 3rd portion of TDD_EN */
    volatile Uint32 PD_DMACHAN_E[128]; /* x128 DMA chan: 4th portion of TDD_EN */
    volatile Uint32 PD_DMACHAN_F[128]; /* x128 DMA chan: 5th portion of TDD_EN */
    volatile Uint32 PD_FRM_MSG_TC[128]; /* x128 LUT Depth: PD Frame Message Count Register */
    volatile Uint8 RSVD49[12800];
    CSL_Aif2G_pe_lksRegs G_PE_LKS[6];
    volatile Uint8 RSVD50[4096];
    volatile Uint32 PE_GLOBAL; /* PE Global Register */
    volatile Uint32 PE_GLOBAL_EN_SET; /* Set Global Enable for PE */
    volatile Uint32 PE_GLOBAL_EN_CLR; /* Clear Global Enable for PE */
    volatile Uint32 PE_GLOBAL_EN_STS; /* Read Only status of global enable state.  Even if this register is OFF, PE may still be closing out packets. */
    volatile Uint32 PE_CHAN_STS[4]; /* Gives current On/Off Status of every available stream.  One bit per channel.  Required because channels only turn on/off on radio frame so the chan_en alone does not give channel status.  Chan on/off is not tracked for packet channels; These bits are 0 for packet channels. (Each of 4 registers represents 32 of 128 channels) */
    volatile Uint32 PE_PKT_STS[4]; /* Gives current In/Out packet state of packet channels only.  Bits are always zero for AxC channels.  Bit is activated at SOP, holds high mid packet, deactivates at EOP. (Each of 4 registers represents 32 of 128 channels) */
    volatile Uint8 RSVD51[80];
    volatile Uint32 PE_FRM_TC[6]; /* PE Frame Count Register.  There are six sets of these cound value in order to support 6 simultanious LTE configurations (Use only 1 for other standards) */
    volatile Uint8 RSVD52[360];
    volatile Uint32 PE_DMACHAN_EN[128]; /* PE DMA Channel Enable Register */
    volatile Uint32 PE_DMA0CHAN[128]; /* PE DMA Channel 0 Register */
    volatile Uint32 PE_IN_FIFO[128]; /* PE DMA Channel 1 Register */
    volatile Uint32 PE_AXC_OFFSET[128]; /* PE DMA Channel 1 Register */
    volatile Uint32 PE_FRM_MSG_TC[128]; /* PE AxC Framing Counter Register */
    volatile Uint32 PE_MODTXRULE[64]; /* PE Modulo Terminal Count Register */
    volatile Uint8 RSVD53[256];
    volatile Uint32 PE_OBSAI_HDR[128]; /* PE DMA Channel which controls the creation of OBSAI headers */
    volatile Uint8 RSVD54[12288];
    volatile Uint32 PE_OBSAI_DBM[64]; /* PE OBSAI DBMF Register (CPRI is handled in different MMRs). OBSAI DBM counts through quad-samples (16 bytes per AxC) */
    volatile Uint8 RSVD55[1792];
    volatile Uint32 PE_DBM_MAP[512]; /* PE DBMF Bit Map 1 & 2 Register, eight locations for each of 64 different rules (3 address LSBs address 0-7 entries per each of 64 rules) (bit_2==0 bit map1  bit_2==1 bit map2.  000:map1(31:0)  001:map1(63:32)  010:map1(95:64) 01l:map1(127:96) 100:map2(31:0)  101:map2(63:32)  110:map2(95:64) 11l:unused */
    volatile Uint8 RSVD56[12288];
    volatile Uint32 PE_RULE_CHANLUT0[512]; /* PE Channel Rule LUT OBSAI: part0 CPRI: link0 */
    volatile Uint32 PE_RULE_CHANLUT1[512]; /* PE Channel Rule LUT OBSAI: part1 CPRI: link1 */
    volatile Uint32 PE_RULE_CHANLUT2[512]; /* PE Channel Rule LUT OBSAI: part2 CPRI: link2 */
    volatile Uint32 PE_RULE_CHANLUT3[512]; /* PE Channel Rule LUT OBSAI: part3 CPRI: link3 */
    volatile Uint32 PE_RULE_CHANLUT4[512]; /* PE Channel Rule LUT OBSAI: part4 CPRI: link4 */
    volatile Uint32 PE_RULE_CHANLUT5[512]; /* PE Channel Rule LUT OBSAI: part5 CPRI: link5 */
    volatile Uint32 PE_RULE_CHANLUT6[512]; /* PE Channel Rule LUT OBSAI: part6 CPRI: unused */
    volatile Uint32 PE_RULE_CHANLUT7[512]; /* PE Channel Rule LUT OBSAI: part7 CPRI: unused */
} CSL_Aif2Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* SD_RX_EN_CFG */

#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_MASK (0x00000003u)
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_RESETVAL (0x00000000u)
/*----RX enable Tokens----*/
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_DISABLE (0x00000000u)
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_SLEEP (0x00000001u)
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_SNOOZE (0x00000002u)
#define CSL_AIF2_SD_RX_EN_CFG_RXENABLE_ENABLE (0x00000003u)


#define CSL_AIF2_SD_RX_EN_CFG_RESETVAL (0x00000000u)

/* SD_RX_CFG */


#define CSL_AIF2_SD_RX_CFG_RXRATE_MASK (0x00000060u)
#define CSL_AIF2_SD_RX_CFG_RXRATE_SHIFT (0x00000005u)
#define CSL_AIF2_SD_RX_CFG_RXRATE_RESETVAL (0x00000000u)
/*----RX Rate Tokens----*/
#define CSL_AIF2_SD_RX_CFG_RXRATE_FULL_RATE (0x00000000u)
#define CSL_AIF2_SD_RX_CFG_RXRATE_HALF_RATE (0x00000001u)
#define CSL_AIF2_SD_RX_CFG_RXRATE_QUARTER_RATE (0x00000002u)
#define CSL_AIF2_SD_RX_CFG_RXRATE_EIGHT_RATE (0x00000003u)


#define CSL_AIF2_SD_RX_CFG_RXDISABLE_COMMA_DETECT_AND_BYTE_ALIGNMENT_MASK (0x00000400u)
#define CSL_AIF2_SD_RX_CFG_RXDISABLE_COMMA_DETECT_AND_BYTE_ALIGNMENT_SHIFT (0x0000000Au)
#define CSL_AIF2_SD_RX_CFG_RXDISABLE_COMMA_DETECT_AND_BYTE_ALIGNMENT_RESETVAL (0x00000000u)

#define CSL_AIF2_SD_RX_CFG_RXLOSS_OF_SIGNAL_DETECT_ENABLE_MASK (0x00000800u)
#define CSL_AIF2_SD_RX_CFG_RXLOSS_OF_SIGNAL_DETECT_ENABLE_SHIFT (0x0000000Bu)
#define CSL_AIF2_SD_RX_CFG_RXLOSS_OF_SIGNAL_DETECT_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_SD_RX_CFG_RXPOLARITY_MASK (0x00008000u)
#define CSL_AIF2_SD_RX_CFG_RXPOLARITY_SHIFT (0x0000000Fu)
#define CSL_AIF2_SD_RX_CFG_RXPOLARITY_RESETVAL (0x00000000u)

#define CSL_AIF2_SD_RX_CFG_RESETVAL    (0x00000000u)

/* SD_RX_STS */

#define CSL_AIF2_SD_RX_STS_RXSYNC_MASK (0x00000001u)
#define CSL_AIF2_SD_RX_STS_RXSYNC_SHIFT (0x00000000u)
#define CSL_AIF2_SD_RX_STS_RXSYNC_RESETVAL (0x00000000u)

#define CSL_AIF2_SD_RX_STS_RXLOSS_OF_SIGNAL_MASK (0x00000002u)
#define CSL_AIF2_SD_RX_STS_RXLOSS_OF_SIGNAL_SHIFT (0x00000001u)
#define CSL_AIF2_SD_RX_STS_RXLOSS_OF_SIGNAL_RESETVAL (0x00000000u)

#define CSL_AIF2_SD_RX_STS_RXADAPT_DONE_MASK (0x00000004u)
#define CSL_AIF2_SD_RX_STS_RXADAPT_DONE_SHIFT (0x00000002u)
#define CSL_AIF2_SD_RX_STS_RXADAPT_DONE_RESETVAL (0x00000000u)


#define CSL_AIF2_SD_RX_STS_RESETVAL    (0x00000000u)

/* SD_TX_EN_CFG */

#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_MASK (0x00000003u)
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_RESETVAL (0x00000000u)
/*----TX enable Tokens----*/
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_DISABLE (0x00000000u)
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_SLEEP (0x00000001u)
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_SNOOZE (0x00000002u)
#define CSL_AIF2_SD_TX_EN_CFG_TXENABLE_ENABLE (0x00000003u)


#define CSL_AIF2_SD_TX_EN_CFG_RESETVAL (0x00000000u)

/* SD_TX_CFG */


#define CSL_AIF2_SD_TX_CFG_TXRATE_MASK (0x00000060u)
#define CSL_AIF2_SD_TX_CFG_TXRATE_SHIFT (0x00000005u)
#define CSL_AIF2_SD_TX_CFG_TXRATE_RESETVAL (0x00000000u)
/*----TX Rate Tokens----*/
#define CSL_AIF2_SD_TX_CFG_TXRATE_FULL_RATE (0x00000000u)
#define CSL_AIF2_SD_TX_CFG_TXRATE_HALF_RATE (0x00000001u)
#define CSL_AIF2_SD_TX_CFG_TXRATE_QUARTER_RATE (0x00000002u)
#define CSL_AIF2_SD_TX_CFG_TXRATE_EIGHT_RATE (0x00000003u)


#define CSL_AIF2_SD_TX_CFG_RESETVAL    (0x00000000u)

/* AD_DIO_I_TABLE_SEL */

#define CSL_AIF2_AD_DIO_I_TABLE_SEL_BCN_TABLE_SEL_MASK (0x00000001u)
#define CSL_AIF2_AD_DIO_I_TABLE_SEL_BCN_TABLE_SEL_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_TABLE_SEL_BCN_TABLE_SEL_RESETVAL (0x00000000u)
/*----bcn_table_sel Tokens----*/
#define CSL_AIF2_AD_DIO_I_TABLE_SEL_BCN_TABLE_SEL_TABLE0 (0x00000000u)
#define CSL_AIF2_AD_DIO_I_TABLE_SEL_BCN_TABLE_SEL_TABLE1 (0x00000001u)


#define CSL_AIF2_AD_DIO_I_TABLE_SEL_RESETVAL (0x00000000u)

/* AD_DIO_I_TABLE_LOOP_CFG */

#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_MASK (0x00000003u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_RESETVAL (0x00000000u)
/*----num_qw Tokens----*/
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_1QUAD (0x00000000u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_2QUAD (0x00000001u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_QW_4QUAD (0x00000002u)


#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_AXC_MASK (0x00003F00u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_AXC_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_NUM_AXC_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_TABLE_LOOP_CFG_RESETVAL (0x00000000u)

/* AD_DIO_I_DMA_CFG0 */

#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_MASK (0x00000003u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_RESETVAL (0x00000000u)
/*----dma_brst_ln Tokens----*/
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_1QUAD (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_2QUAD (0x00000001u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_BRST_LN_4QUAD (0x00000002u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RSA_EN_MASK (0x00000010u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RSA_EN_SHIFT (0x00000004u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RSA_EN_RESETVAL (0x00000000u)
/*----rsa_en Tokens----*/
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RSA_EN_RSADIS (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RSA_EN_RSAEN (0x00000001u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_CH_EN_MASK (0x00000100u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_CH_EN_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_CH_EN_RESETVAL (0x00000000u)
/*----dma_ch_en Tokens----*/
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_CH_EN_DMACLR (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_CH_EN_DMAEN (0x00000001u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_NUM_BLKS_MASK (0x1FFF0000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_NUM_BLKS_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG0_DMA_NUM_BLKS_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG0_RESETVAL (0x00000000u)

/* AD_DIO_I_DMA_CFG1 */

#define CSL_AIF2_AD_DIO_I_DMA_CFG1_DMA_BASE_ADDR_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AD_DIO_I_DMA_CFG1_DMA_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG1_DMA_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG1_RESETVAL (0x00000000u)

/* AD_DIO_I_DMA_CFG2 */

#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BRST_ADDR_STRIDE_MASK (0x00000FFFu)
#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BRST_ADDR_STRIDE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BRST_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BLK_ADDR_STRIDE_MASK (0x0FFF0000u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BLK_ADDR_STRIDE_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_DMA_CFG2_DMA_BLK_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_DMA_CFG2_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW0 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN0_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN0_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN0_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN1_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN1_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN1_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN2_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN2_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN2_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN3_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN3_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_DBCN3_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW0_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW1 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN4_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN4_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN4_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN5_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN5_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN5_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN6_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN6_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN6_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN7_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN7_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_DBCN7_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW1_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW2 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN8_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN8_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN8_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN9_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN9_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN9_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN10_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN10_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN10_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN11_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN11_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_DBCN11_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW2_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW3 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN12_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN12_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN12_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN13_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN13_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN13_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN14_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN14_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN14_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN15_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN15_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_DBCN15_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW3_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW4 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN16_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN16_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN16_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN17_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN17_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN17_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN18_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN18_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN18_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN19_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN19_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_DBCN19_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW4_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW5 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN20_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN20_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN20_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN21_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN21_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN21_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN22_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN22_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN22_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN23_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN23_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_DBCN23_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW5_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW6 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN24_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN24_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN24_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN25_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN25_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN25_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN26_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN26_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN26_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN27_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN27_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_DBCN27_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW6_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW7 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN28_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN28_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN28_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN29_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN29_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN29_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN30_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN30_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN30_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN31_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN31_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_DBCN31_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW7_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW8 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN32_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN32_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN32_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN33_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN33_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN33_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN34_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN34_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN34_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN35_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN35_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_DBCN35_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW8_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW9 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN36_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN36_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN36_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN37_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN37_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN37_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN38_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN38_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN38_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN39_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN39_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_DBCN39_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW9_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW10 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN40_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN40_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN40_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN41_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN41_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN41_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN42_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN42_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN42_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN43_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN43_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_DBCN43_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW10_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW11 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN44_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN44_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN44_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN45_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN45_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN45_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN46_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN46_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN46_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN47_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN47_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_DBCN47_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW11_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW12 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN48_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN48_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN48_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN49_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN49_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN49_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN50_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN50_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN50_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN51_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN51_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_DBCN51_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW12_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW13 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN52_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN52_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN52_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN53_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN53_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN53_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN54_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN54_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN54_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN55_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN55_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_DBCN55_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW13_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW14 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN56_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN56_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN56_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN57_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN57_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN57_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN58_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN58_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN58_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN59_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN59_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_DBCN59_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW14_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE0_ROW15 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN60_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN60_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN60_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN61_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN61_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN61_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN62_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN62_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN62_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN63_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN63_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_DBCN63_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE0_ROW15_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW0 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN0_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN0_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN0_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN1_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN1_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN1_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN2_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN2_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN2_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN3_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN3_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_DBCN3_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW0_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW1 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN4_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN4_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN4_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN5_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN5_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN5_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN6_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN6_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN6_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN7_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN7_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_DBCN7_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW1_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW2 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN8_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN8_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN8_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN9_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN9_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN9_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN10_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN10_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN10_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN11_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN11_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_DBCN11_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW2_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW3 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN12_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN12_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN12_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN13_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN13_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN13_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN14_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN14_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN14_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN15_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN15_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_DBCN15_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW3_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW4 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN16_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN16_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN16_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN17_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN17_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN17_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN18_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN18_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN18_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN19_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN19_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_DBCN19_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW4_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW5 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN20_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN20_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN20_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN21_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN21_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN21_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN22_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN22_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN22_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN23_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN23_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_DBCN23_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW5_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW6 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN24_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN24_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN24_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN25_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN25_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN25_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN26_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN26_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN26_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN27_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN27_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_DBCN27_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW6_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW7 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN28_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN28_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN28_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN29_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN29_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN29_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN30_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN30_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN30_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN31_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN31_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_DBCN31_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW7_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW8 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN32_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN32_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN32_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN33_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN33_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN33_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN34_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN34_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN34_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN35_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN35_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_DBCN35_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW8_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW9 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN36_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN36_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN36_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN37_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN37_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN37_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN38_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN38_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN38_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN39_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN39_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_DBCN39_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW9_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW10 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN40_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN40_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN40_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN41_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN41_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN41_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN42_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN42_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN42_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN43_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN43_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_DBCN43_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW10_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW11 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN44_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN44_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN44_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN45_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN45_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN45_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN46_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN46_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN46_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN47_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN47_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_DBCN47_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW11_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW12 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN48_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN48_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN48_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN49_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN49_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN49_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN50_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN50_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN50_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN51_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN51_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_DBCN51_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW12_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW13 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN52_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN52_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN52_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN53_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN53_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN53_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN54_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN54_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN54_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN55_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN55_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_DBCN55_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW13_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW14 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN56_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN56_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN56_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN57_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN57_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN57_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN58_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN58_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN58_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN59_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN59_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_DBCN59_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW14_RESETVAL (0x00000000u)

/* AD_DIO_I_BCN_TABLE1_ROW15 */

#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN60_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN60_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN60_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN61_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN61_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN61_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN62_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN62_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN62_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN63_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN63_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_DBCN63_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_BCN_TABLE1_ROW15_RESETVAL (0x00000000u)

/* AD_DIO_E_TABLE_SEL */

#define CSL_AIF2_AD_DIO_E_TABLE_SEL_BCN_TABLE_SEL_MASK (0x00000001u)
#define CSL_AIF2_AD_DIO_E_TABLE_SEL_BCN_TABLE_SEL_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_TABLE_SEL_BCN_TABLE_SEL_RESETVAL (0x00000000u)
/*----bcn_table_sel Tokens----*/
#define CSL_AIF2_AD_DIO_E_TABLE_SEL_BCN_TABLE_SEL_TABLE0 (0x00000000u)
#define CSL_AIF2_AD_DIO_E_TABLE_SEL_BCN_TABLE_SEL_TABLE1 (0x00000001u)


#define CSL_AIF2_AD_DIO_E_TABLE_SEL_RESETVAL (0x00000000u)

/* AD_DIO_E_TABLE_LOOP_CFG */

#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_MASK (0x00000003u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_RESETVAL (0x00000000u)
/*----num_qw Tokens----*/
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_1QUAD (0x00000000u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_2QUAD (0x00000001u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_QW_4QUAD (0x00000002u)


#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_AXC_MASK (0x00003F00u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_AXC_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_NUM_AXC_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_TABLE_LOOP_CFG_RESETVAL (0x00000000u)

/* AD_DIO_E_DMA_CFG0 */

#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_MASK (0x00000003u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_RESETVAL (0x00000000u)
/*----dma_brst_ln Tokens----*/
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_1QUAD (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_2QUAD (0x00000001u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_BRST_LN_4QUAD (0x00000002u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RSA_EN_MASK (0x00000010u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RSA_EN_SHIFT (0x00000004u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RSA_EN_RESETVAL (0x00000000u)
/*----rsa_en Tokens----*/
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RSA_EN_RSADIS (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RSA_EN_RSAEN (0x00000001u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_CH_EN_MASK (0x00000100u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_CH_EN_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_CH_EN_RESETVAL (0x00000000u)
/*----dma_ch_en Tokens----*/
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_CH_EN_DMACLR (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_CH_EN_DMAEN (0x00000001u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_NUM_BLKS_MASK (0x1FFF0000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_NUM_BLKS_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG0_DMA_NUM_BLKS_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG0_RESETVAL (0x00000000u)

/* AD_DIO_E_DMA_CFG1 */

#define CSL_AIF2_AD_DIO_E_DMA_CFG1_DMA_BASE_ADDR_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AD_DIO_E_DMA_CFG1_DMA_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG1_DMA_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG1_RESETVAL (0x00000000u)

/* AD_DIO_E_DMA_CFG2 */

#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BRST_ADDR_STRIDE_MASK (0x00000FFFu)
#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BRST_ADDR_STRIDE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BRST_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BLK_ADDR_STRIDE_MASK (0x0FFF0000u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BLK_ADDR_STRIDE_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_DMA_CFG2_DMA_BLK_ADDR_STRIDE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_DMA_CFG2_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW0 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN0_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN0_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN0_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN1_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN1_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN1_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN2_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN2_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN2_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN3_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN3_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_DBCN3_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW0_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW1 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN4_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN4_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN4_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN5_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN5_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN5_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN6_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN6_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN6_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN7_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN7_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_DBCN7_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW1_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW2 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN8_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN8_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN8_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN9_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN9_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN9_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN10_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN10_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN10_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN11_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN11_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_DBCN11_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW2_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW3 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN12_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN12_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN12_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN13_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN13_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN13_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN14_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN14_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN14_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN15_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN15_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_DBCN15_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW3_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW4 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN16_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN16_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN16_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN17_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN17_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN17_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN18_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN18_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN18_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN19_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN19_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_DBCN19_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW4_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW5 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN20_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN20_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN20_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN21_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN21_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN21_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN22_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN22_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN22_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN23_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN23_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_DBCN23_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW5_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW6 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN24_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN24_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN24_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN25_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN25_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN25_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN26_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN26_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN26_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN27_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN27_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_DBCN27_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW6_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW7 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN28_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN28_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN28_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN29_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN29_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN29_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN30_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN30_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN30_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN31_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN31_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_DBCN31_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW7_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW8 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN32_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN32_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN32_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN33_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN33_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN33_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN34_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN34_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN34_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN35_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN35_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_DBCN35_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW8_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW9 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN36_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN36_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN36_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN37_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN37_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN37_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN38_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN38_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN38_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN39_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN39_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_DBCN39_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW9_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW10 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN40_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN40_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN40_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN41_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN41_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN41_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN42_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN42_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN42_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN43_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN43_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_DBCN43_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW10_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW11 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN44_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN44_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN44_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN45_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN45_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN45_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN46_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN46_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN46_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN47_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN47_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_DBCN47_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW11_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW12 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN48_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN48_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN48_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN49_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN49_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN49_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN50_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN50_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN50_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN51_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN51_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_DBCN51_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW12_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW13 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN52_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN52_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN52_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN53_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN53_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN53_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN54_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN54_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN54_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN55_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN55_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_DBCN55_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW13_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW14 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN56_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN56_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN56_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN57_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN57_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN57_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN58_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN58_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN58_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN59_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN59_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_DBCN59_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW14_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE0_ROW15 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN60_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN60_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN60_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN61_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN61_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN61_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN62_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN62_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN62_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN63_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN63_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_DBCN63_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE0_ROW15_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW0 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN0_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN0_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN0_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN1_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN1_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN1_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN2_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN2_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN2_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN3_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN3_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_DBCN3_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW0_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW1 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN4_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN4_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN4_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN5_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN5_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN5_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN6_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN6_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN6_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN7_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN7_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_DBCN7_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW1_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW2 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN8_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN8_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN8_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN9_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN9_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN9_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN10_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN10_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN10_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN11_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN11_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_DBCN11_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW2_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW3 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN12_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN12_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN12_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN13_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN13_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN13_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN14_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN14_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN14_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN15_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN15_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_DBCN15_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW3_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW4 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN16_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN16_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN16_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN17_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN17_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN17_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN18_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN18_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN18_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN19_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN19_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_DBCN19_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW4_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW5 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN20_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN20_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN20_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN21_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN21_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN21_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN22_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN22_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN22_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN23_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN23_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_DBCN23_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW5_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW6 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN24_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN24_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN24_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN25_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN25_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN25_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN26_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN26_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN26_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN27_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN27_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_DBCN27_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW6_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW7 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN28_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN28_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN28_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN29_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN29_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN29_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN30_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN30_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN30_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN31_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN31_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_DBCN31_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW7_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW8 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN32_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN32_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN32_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN33_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN33_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN33_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN34_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN34_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN34_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN35_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN35_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_DBCN35_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW8_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW9 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN36_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN36_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN36_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN37_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN37_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN37_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN38_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN38_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN38_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN39_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN39_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_DBCN39_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW9_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW10 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN40_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN40_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN40_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN41_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN41_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN41_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN42_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN42_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN42_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN43_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN43_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_DBCN43_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW10_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW11 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN44_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN44_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN44_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN45_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN45_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN45_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN46_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN46_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN46_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN47_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN47_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_DBCN47_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW11_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW12 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN48_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN48_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN48_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN49_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN49_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN49_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN50_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN50_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN50_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN51_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN51_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_DBCN51_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW12_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW13 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN52_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN52_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN52_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN53_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN53_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN53_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN54_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN54_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN54_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN55_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN55_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_DBCN55_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW13_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW14 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN56_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN56_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN56_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN57_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN57_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN57_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN58_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN58_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN58_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN59_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN59_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_DBCN59_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW14_RESETVAL (0x00000000u)

/* AD_DIO_E_BCN_TABLE1_ROW15 */

#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN60_MASK (0x0000007Fu)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN60_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN60_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN61_MASK (0x00007F00u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN61_SHIFT (0x00000008u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN61_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN62_MASK (0x007F0000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN62_SHIFT (0x00000010u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN62_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN63_MASK (0x7F000000u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN63_SHIFT (0x00000018u)
#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_DBCN63_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_BCN_TABLE1_ROW15_RESETVAL (0x00000000u)

/* TCHAN_GCFG_REG_A */

#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_ENABLE_MASK (0x80000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_TEARDOWN_MASK (0x40000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_PAUSE_MASK (0x20000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_PAUSE_SHIFT (0x0000001Du)
#define CSL_AIF2_TCHAN_GCFG_REG_A_TX_PAUSE_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* TCHAN_GCFG_REG_B */

#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_EINFO_MASK (0x40000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_EINFO_SHIFT (0x0000001Eu)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_EINFO_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_MASK (0x20000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_SHIFT (0x0000001Du)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_MASK (0x01000000u)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_SHIFT (0x00000018u)
#define CSL_AIF2_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_RESETVAL (0x00000000u)

#define CSL_AIF2_TCHAN_GCFG_REG_B_RESETVAL (0x00000000u)

/* RCHAN_GCFG_REG_A */

#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_ENABLE_MASK (0x80000000u)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_TEARDOWN_MASK (0x40000000u)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_PAUSE_MASK (0x20000000u)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_PAUSE_SHIFT (0x0000001Du)
#define CSL_AIF2_RCHAN_GCFG_REG_A_RX_PAUSE_RESETVAL (0x00000000u)

#define CSL_AIF2_RCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_A */

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_MASK (0x40000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_SHIFT (0x0000001Eu)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_MASK (0x20000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_SHIFT (0x0000001Du)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_MASK (0x10000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_SHIFT (0x0000001Cu)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DESC_TYPE_MASK (0x0C000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DESC_TYPE_SHIFT (0x0000001Au)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DESC_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PS_LOCATION_MASK (0x02000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PS_LOCATION_SHIFT (0x00000019u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_PS_LOCATION_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_SOP_OFFSET_MASK (0x01FF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_SOP_OFFSET_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_SOP_OFFSET_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QMGR_MASK (0x00003000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QMGR_SHIFT (0x0000000Cu)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QNUM_MASK (0x00000FFFu)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QNUM_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_A_RX_DEST_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_A_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_B */

#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_MASK (0xFF000000u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_SHIFT (0x00000018u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_MASK (0x00FF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_MASK (0x0000FF00u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_SHIFT (0x00000008u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_MASK (0x000000FFu)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_B_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_C */

#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_MASK (0x70000000u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_SHIFT (0x0000001Cu)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_MASK (0x07000000u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_SHIFT (0x00000018u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_MASK (0x00700000u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_SHIFT (0x00000014u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_MASK (0x00070000u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_MASK (0x0000000Fu)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_C_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_D */

#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_MASK (0x30000000u)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_SHIFT (0x0000001Cu)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_MASK (0x0FFF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_MASK (0x00003000u)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_SHIFT (0x0000000Cu)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_MASK (0x00000FFFu)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_D_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_E */

#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_MASK (0x30000000u)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_SHIFT (0x0000001Cu)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_MASK (0x0FFF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_MASK (0x00003000u)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_SHIFT (0x0000000Cu)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_MASK (0x00000FFFu)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_E_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_F */

#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_MASK (0xFFFF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_MASK (0x0000FFFFu)
#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_F_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_G */

#define CSL_AIF2_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_MASK (0xFFFF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_MASK (0x00003000u)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_SHIFT (0x0000000Cu)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_MASK (0x00000FFFu)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_G_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_H */

#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_MASK (0x30000000u)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_SHIFT (0x0000001Cu)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_MASK (0x0FFF0000u)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_SHIFT (0x00000010u)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_MASK (0x00003000u)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_SHIFT (0x0000000Cu)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_MASK (0x00000FFFu)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_SHIFT (0x00000000u)
#define CSL_AIF2_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_RFLOW_CFG_REG_H_RESETVAL (0x00000000u)

/* ee_lk_irs_a */

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_A_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_A_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_A_RESETVAL  (0x00000000u)

/* ee_lk_irs_set_a */

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_SET_A_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_SET_A_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_A_RESETVAL (0x00000000u)

/* ee_lk_irs_clr_a */

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_CLR_A_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_A_RESETVAL (0x00000000u)

/* ee_lk_en_a_ev0 */

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_EV0_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_a_set_ev0 */

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV0_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_SET_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_a_clr_ev0 */

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_CLR_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_a_ev1 */

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_EV1_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_a_set_ev1 */

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_SET_EV1_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_SET_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_a_clr_ev1 */

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_A_CLR_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_sts_a_ev0 */

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_A_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_sts_a_ev1 */

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_NUM_LOS_DET_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_NUM_LOS_DET_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_NUM_LOS_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LCV_DET_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LCV_DET_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LCV_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P5_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P5_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P7_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P7_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P7_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_K30P7_DET_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_K30P7_DET_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_K30P7_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOC_DET_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOC_DET_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOC_DET_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RX_FIFO_OVF_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RX_FIFO_OVF_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RX_FIFO_OVF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOS_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOS_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOF_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOF_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_RAI_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_RAI_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_RAI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_SDI_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_SDI_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_SDI_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOS_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOS_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_HFNSYNC_STATE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_HFNSYNC_STATE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_HFNSYNC_STATE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_STATE_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_STATE_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_STATE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FRM_MISALIGN_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FRM_MISALIGN_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FRM_MISALIGN_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FIFO_STARVE_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FIFO_STARVE_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FIFO_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_A_EV1_RESETVAL (0x00000000u)

/* ee_lk_irs_b */

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_B_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_B_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_IRS_B_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_B_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_B_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_IRS_B_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_B_RESETVAL  (0x00000000u)

/* ee_lk_irs_set_b */

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_IRS_SET_B_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_IRS_SET_B_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_SET_B_RESETVAL (0x00000000u)

/* ee_lk_irs_clr_b */

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_IRS_CLR_B_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_IRS_CLR_B_RESETVAL (0x00000000u)

/* ee_lk_en_b_ev0 */

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_EV0_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_EV0_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_b_set_ev0 */

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_b_clr_ev0 */

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_b_ev1 */

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_EV1_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_EV1_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_b_set_ev1 */

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_SET_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_b_clr_ev1 */

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_B_CLR_EV1_RESETVAL (0x00000000u)

/* ee_lk_en_sts_b_ev0 */

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV0_RESETVAL (0x00000000u)

/* ee_lk_en_sts_b_ev1 */

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_EOP_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_EOP_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_EOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CRC_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CRC_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CPRI_FRAME_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CPRI_FRAME_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CPRI_FRAME_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_AXC_FAIL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_AXC_FAIL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_AXC_FAIL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_SOP_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_SOP_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_SOP_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_OBSAI_FRM_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_OBSAI_FRM_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_OBSAI_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_WR2DB_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_WR2DB_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PD_EE_WR2DB_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MODRULE_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MODRULE_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MODRULE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_SYM_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_SYM_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_SYM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_MASK (0x00080000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_SHIFT (0x00000013u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_DB_STARVE_ERR_MASK (0x00100000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_DB_STARVE_ERR_SHIFT (0x00000014u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_DB_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_RT_IF_ERR_MASK (0x00200000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_RT_IF_ERR_SHIFT (0x00000015u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_RT_IF_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_PKT_STARVE_ERR_MASK (0x00400000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_PKT_STARVE_ERR_SHIFT (0x00000016u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_PE_EE_PKT_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_FRM_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_FRM_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_FRM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_OVFL_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_OVFL_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_UNFL_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_UNFL_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_UNFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_EM_ERR_MASK (0x08000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_EM_ERR_SHIFT (0x0000001Bu)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_EM_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_HDR_ERR_MASK (0x10000000u)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_HDR_ERR_SHIFT (0x0000001Cu)
#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RT_EE_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_LK_EN_STS_B_EV1_RESETVAL (0x00000000u)

/* at_pimax_lk */

#define CSL_AIF2_AT_PIMAX_LK_PIMAX_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PIMAX_LK_PIMAX_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PIMAX_LK_PIMAX_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PIMAX_LK_RESETVAL  (0x00000000u)

/* at_pimin_lk */

#define CSL_AIF2_AT_PIMIN_LK_PIMIN_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PIMIN_LK_PIMIN_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PIMIN_LK_PIMIN_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PIMIN_LK_RESETVAL  (0x00000000u)

/* at_pivalue_lk */

#define CSL_AIF2_AT_PIVALUE_LK_PICAPTURED_VALUE_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PIVALUE_LK_PICAPTURED_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PIVALUE_LK_PICAPTURED_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PIVALUE_LK_RESETVAL (0x00000000u)

/* at_event_offset */

#define CSL_AIF2_AT_EVENT_OFFSET_EVENTINDEX_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_EVENT_OFFSET_EVENTINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVENT_OFFSET_EVENTINDEX_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_MASK (0x07000000u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_SHIFT (0x00000018u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_RESETVAL (0x00000000u)
/*----Strobe Select Tokens----*/
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_RADT_SYMB (0x00000000u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_RADT_FRAME (0x00000001u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_ULRADT_SYMB (0x00000002u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_ULRADT_FRAME (0x00000003u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_DLRADT_SYMB (0x00000004u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_DLRADT_FRAME (0x00000005u)
#define CSL_AIF2_AT_EVENT_OFFSET_STROBESELECT_PHYT_FRAME (0x00000006u)


#define CSL_AIF2_AT_EVENT_OFFSET_RESETVAL (0x00000000u)

/* at_event_mod_tc */

#define CSL_AIF2_AT_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_EVENT_MOD_TC_RESETVAL (0x00000000u)

/* at_event_mask_lsbs */

#define CSL_AIF2_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_EVENT_MASK_LSBS_RESETVAL (0x00000000u)

/* at_event_mask_msbs */

#define CSL_AIF2_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_EVENT_MASK_MSBS_RESETVAL (0x00000000u)

/* at_ad_ingr_event_offset */

#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_EVENTINDEX_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_EVENTINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_EVENTINDEX_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_MASK (0x07000000u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_SHIFT (0x00000018u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_RESETVAL (0x00000000u)
/*----Strobe Select Tokens----*/
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_RADT_SYMB (0x00000000u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_RADT_FRAME (0x00000001u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_ULRADT_SYMB (0x00000002u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_ULRADT_FRAME (0x00000003u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_DLRADT_SYMB (0x00000004u)
#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_STROBESELECT_DLRADT_FRAME (0x00000005u)


#define CSL_AIF2_AT_AD_INGR_EVENT_OFFSET_RESETVAL (0x00000000u)

/* at_ad_ingr_event_mod_tc */

#define CSL_AIF2_AT_AD_INGR_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_AD_INGR_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_AD_INGR_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_AD_INGR_EVENT_MOD_TC_RESETVAL (0x00000000u)

/* at_ad_egr_event_offset */

#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_EVENTINDEX_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_EVENTINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_EVENTINDEX_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_MASK (0x07000000u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_SHIFT (0x00000018u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_RESETVAL (0x00000000u)
/*----Strobe Select Tokens----*/
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_RADT_SYMB (0x00000000u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_RADT_FRAME (0x00000001u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_ULRADT_SYMB (0x00000002u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_ULRADT_FRAME (0x00000003u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_DLRADT_SYMB (0x00000004u)
#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_STROBESELECT_DLRADT_FRAME (0x00000005u)


#define CSL_AIF2_AT_AD_EGR_EVENT_OFFSET_RESETVAL (0x00000000u)

/* at_ad_egr_event_mod_tc */

#define CSL_AIF2_AT_AD_EGR_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_AD_EGR_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_AD_EGR_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_AD_EGR_EVENT_MOD_TC_RESETVAL (0x00000000u)

/* at_tm_delta_event_offset */

#define CSL_AIF2_AT_TM_DELTA_EVENT_OFFSET_EVENTOFFSET_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_TM_DELTA_EVENT_OFFSET_EVENTOFFSET_SHIFT (0x00000000u)
#define CSL_AIF2_AT_TM_DELTA_EVENT_OFFSET_EVENTOFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_TM_DELTA_EVENT_OFFSET_RESETVAL (0x00000000u)

/* at_tm_delta_event_mod_tc */

#define CSL_AIF2_AT_TM_DELTA_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_TM_DELTA_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_TM_DELTA_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_TM_DELTA_EVENT_MOD_TC_RESETVAL (0x00000000u)

/* at_pe_event_offset */

#define CSL_AIF2_AT_PE_EVENT_OFFSET_EVENTOFFSET_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PE_EVENT_OFFSET_EVENTOFFSET_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PE_EVENT_OFFSET_EVENTOFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PE_EVENT_OFFSET_RESETVAL (0x00000000u)

/* at_pe_event_mod_tc */

#define CSL_AIF2_AT_PE_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PE_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PE_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PE_EVENT_MOD_TC_RESETVAL (0x00000000u)

/* at_pe_event2_offset */

#define CSL_AIF2_AT_PE_EVENT2_OFFSET_EVENTOFFSET_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PE_EVENT2_OFFSET_EVENTOFFSET_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PE_EVENT2_OFFSET_EVENTOFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PE_EVENT2_OFFSET_RESETVAL (0x00000000u)

/* at_pe_event2_mod_tc */

#define CSL_AIF2_AT_PE_EVENT2_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PE_EVENT2_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PE_EVENT2_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PE_EVENT2_MOD_TC_RESETVAL (0x00000000u)

/* TM_LK_CFG */

#define CSL_AIF2_TM_LK_CFG_LINKRATE_MASK (0x00000003u)
#define CSL_AIF2_TM_LK_CFG_LINKRATE_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_CFG_LINKRATE_RESETVAL (0x00000000u)
/*----Link Rate Tokens----*/
#define CSL_AIF2_TM_LK_CFG_LINKRATE_8X (0x00000000u)
#define CSL_AIF2_TM_LK_CFG_LINKRATE_4X (0x00000001u)
#define CSL_AIF2_TM_LK_CFG_LINKRATE_2X (0x00000002u)
#define CSL_AIF2_TM_LK_CFG_LINKRATE_5X (0x00000003u)

#define CSL_AIF2_TM_LK_CFG_OBSAI_CPRI_MASK (0x00000004u)
#define CSL_AIF2_TM_LK_CFG_OBSAI_CPRI_SHIFT (0x00000002u)
#define CSL_AIF2_TM_LK_CFG_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----OBSAI_CPRI Tokens----*/
#define CSL_AIF2_TM_LK_CFG_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_TM_LK_CFG_OBSAI_CPRI_OBSAI (0x00000001u)


#define CSL_AIF2_TM_LK_CFG_TM_EN_MASK  (0x00000080u)
#define CSL_AIF2_TM_LK_CFG_TM_EN_SHIFT (0x00000007u)
#define CSL_AIF2_TM_LK_CFG_TM_EN_RESETVAL (0x00000000u)
/*----TM_EN Tokens----*/
#define CSL_AIF2_TM_LK_CFG_TM_EN_DISABLE (0x00000000u)
#define CSL_AIF2_TM_LK_CFG_TM_EN_ENABLE (0x00000001u)


#define CSL_AIF2_TM_LK_CFG_RESETVAL    (0x00000000u)

/* TM_LK_CTRL */

#define CSL_AIF2_TM_LK_CTRL_TM_FLUSH_MASK (0x00000001u)
#define CSL_AIF2_TM_LK_CTRL_TM_FLUSH_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_CTRL_TM_FLUSH_RESETVAL (0x00000000u)
/*----TM_Flush Tokens----*/
#define CSL_AIF2_TM_LK_CTRL_TM_FLUSH_NO_ACTION (0x00000000u)
#define CSL_AIF2_TM_LK_CTRL_TM_FLUSH_FLUSH_FIFO (0x00000001u)

#define CSL_AIF2_TM_LK_CTRL_TM_IDLE_MASK (0x00000002u)
#define CSL_AIF2_TM_LK_CTRL_TM_IDLE_SHIFT (0x00000001u)
#define CSL_AIF2_TM_LK_CTRL_TM_IDLE_RESETVAL (0x00000000u)
/*----TM_Idle Tokens----*/
#define CSL_AIF2_TM_LK_CTRL_TM_IDLE_NO_ACTION (0x00000000u)
#define CSL_AIF2_TM_LK_CTRL_TM_IDLE_IDLE (0x00000001u)

#define CSL_AIF2_TM_LK_CTRL_TM_RESYNC_MASK (0x00000004u)
#define CSL_AIF2_TM_LK_CTRL_TM_RESYNC_SHIFT (0x00000002u)
#define CSL_AIF2_TM_LK_CTRL_TM_RESYNC_RESETVAL (0x00000000u)
/*----TM_RESYNC Tokens----*/
#define CSL_AIF2_TM_LK_CTRL_TM_RESYNC_NO_ACTION (0x00000000u)
#define CSL_AIF2_TM_LK_CTRL_TM_RESYNC_RESYNC (0x00000001u)

#define CSL_AIF2_TM_LK_CTRL_LOS_EN_MASK (0x00000008u)
#define CSL_AIF2_TM_LK_CTRL_LOS_EN_SHIFT (0x00000003u)
#define CSL_AIF2_TM_LK_CTRL_LOS_EN_RESETVAL (0x00000000u)
/*----LOS_EN Tokens----*/
#define CSL_AIF2_TM_LK_CTRL_LOS_EN_DISABLE (0x00000000u)
#define CSL_AIF2_TM_LK_CTRL_LOS_EN_ENABLE (0x00000001u)


#define CSL_AIF2_TM_LK_CTRL_RESETVAL   (0x00000000u)

/* TM_LK_SCR_CTRL */

#define CSL_AIF2_TM_LK_SCR_CTRL_SEED_VALUE_MASK (0x0000007Fu)
#define CSL_AIF2_TM_LK_SCR_CTRL_SEED_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_SCR_CTRL_SEED_VALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_TM_LK_SCR_CTRL_SCR_EN_MASK (0x00000080u)
#define CSL_AIF2_TM_LK_SCR_CTRL_SCR_EN_SHIFT (0x00000007u)
#define CSL_AIF2_TM_LK_SCR_CTRL_SCR_EN_RESETVAL (0x00000000u)
/*----SCR_EN Tokens----*/
#define CSL_AIF2_TM_LK_SCR_CTRL_SCR_EN_DISABLE (0x00000000u)
#define CSL_AIF2_TM_LK_SCR_CTRL_SCR_EN_ENABLE (0x00000001u)


#define CSL_AIF2_TM_LK_SCR_CTRL_RESETVAL (0x00000000u)

/* TM_LK_L1_CFG */

#define CSL_AIF2_TM_LK_L1_CFG_L1_INBAND_CFG_MASK (0x0000001Fu)
#define CSL_AIF2_TM_LK_L1_CFG_L1_INBAND_CFG_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_L1_CFG_L1_INBAND_CFG_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_L1_CFG_RESETVAL (0x00000000u)

/* TM_LK_L1_EN */

#define CSL_AIF2_TM_LK_L1_EN_L1_INBAND_EN_MASK (0x000001FFu)
#define CSL_AIF2_TM_LK_L1_EN_L1_INBAND_EN_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_L1_EN_L1_INBAND_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_L1_EN_RESETVAL  (0x00000000u)

/* TM_LK_LOSERR */

#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_MASK (0x00000007u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_RESETVAL (0x00000000u)
/*----RM_Link_LOSERR Tokens----*/
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR0 (0x00000000u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR1 (0x00000001u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR2 (0x00000002u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR3 (0x00000003u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR4 (0x00000004u)
#define CSL_AIF2_TM_LK_LOSERR_RM_LINK_LOSERR_LOSERR5 (0x00000005u)


#define CSL_AIF2_TM_LK_LOSERR_RESETVAL (0x00000000u)

/* TM_LK_LOFERR */

#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_MASK (0x00000007u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_RESETVAL (0x00000000u)
/*----RM_Link_LOFERR Tokens----*/
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR0 (0x00000000u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR1 (0x00000001u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR2 (0x00000002u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR3 (0x00000003u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR4 (0x00000004u)
#define CSL_AIF2_TM_LK_LOFERR_RM_LINK_LOFERR_LOFERR5 (0x00000005u)


#define CSL_AIF2_TM_LK_LOFERR_RESETVAL (0x00000000u)

/* TM_LK_LOSRx */

#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_MASK (0x00000007u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_RESETVAL (0x00000000u)
/*----RM_Link_LOSRx Tokens----*/
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX0 (0x00000000u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX1 (0x00000001u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX2 (0x00000002u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX3 (0x00000003u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX4 (0x00000004u)
#define CSL_AIF2_TM_LK_LOSRX_RM_LINK_LOSRX_LOSRX5 (0x00000005u)


#define CSL_AIF2_TM_LK_LOSRX_RESETVAL  (0x00000000u)

/* TM_LK_LOFRx */

#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_MASK (0x00000007u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_RESETVAL (0x00000000u)
/*----RM_Link_LOFRx Tokens----*/
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX0 (0x00000000u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX1 (0x00000001u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX2 (0x00000002u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX3 (0x00000003u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX4 (0x00000004u)
#define CSL_AIF2_TM_LK_LOFRX_RM_LINK_LOFRX_LOFRX5 (0x00000005u)


#define CSL_AIF2_TM_LK_LOFRX_RESETVAL  (0x00000000u)

/* TM_LK_RAIRx */

#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_MASK (0x00000007u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RESETVAL (0x00000000u)
/*----RM_Link_RAIRx Tokens----*/
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX0 (0x00000000u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX1 (0x00000001u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX2 (0x00000002u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX3 (0x00000003u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX4 (0x00000004u)
#define CSL_AIF2_TM_LK_RAIRX_RM_LINK_RAIRX_RAIRX5 (0x00000005u)


#define CSL_AIF2_TM_LK_RAIRX_RESETVAL  (0x00000000u)

/* TM_LK_HFN */

#define CSL_AIF2_TM_LK_HFN_HFN_MASK    (0x000000FFu)
#define CSL_AIF2_TM_LK_HFN_HFN_SHIFT   (0x00000000u)
#define CSL_AIF2_TM_LK_HFN_HFN_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_HFN_RESETVAL    (0x00000000u)

/* TM_LK_PTRP */

#define CSL_AIF2_TM_LK_PTRP_PTR_P_MASK (0x000000FFu)
#define CSL_AIF2_TM_LK_PTRP_PTR_P_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_PTRP_PTR_P_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_PTRP_RESETVAL   (0x00000000u)

/* TM_LK_STRT */

#define CSL_AIF2_TM_LK_STRT_STARTUP_MASK (0x000000FFu)
#define CSL_AIF2_TM_LK_STRT_STARTUP_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_STRT_STARTUP_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_STRT_RESETVAL   (0x00000000u)

/* TM_LK_PROT */

#define CSL_AIF2_TM_LK_PROT_PROT_VERS_MASK (0x000000FFu)
#define CSL_AIF2_TM_LK_PROT_PROT_VERS_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_PROT_PROT_VERS_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_LK_PROT_RESETVAL   (0x00000000u)

/* TM_LK_STAT */

#define CSL_AIF2_TM_LK_STAT_TM_FAIL_MASK (0x00000001u)
#define CSL_AIF2_TM_LK_STAT_TM_FAIL_SHIFT (0x00000000u)
#define CSL_AIF2_TM_LK_STAT_TM_FAIL_RESETVAL (0x00000000u)

#define CSL_AIF2_TM_LK_STAT_FIFO_UNFL_MASK (0x00000002u)
#define CSL_AIF2_TM_LK_STAT_FIFO_UNFL_SHIFT (0x00000001u)
#define CSL_AIF2_TM_LK_STAT_FIFO_UNFL_RESETVAL (0x00000000u)

#define CSL_AIF2_TM_LK_STAT_FRM_MISALIGN_MASK (0x00000004u)
#define CSL_AIF2_TM_LK_STAT_FRM_MISALIGN_SHIFT (0x00000002u)
#define CSL_AIF2_TM_LK_STAT_FRM_MISALIGN_RESETVAL (0x00000000u)

#define CSL_AIF2_TM_LK_STAT_FRM_STATE_MASK (0x00000078u)
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_SHIFT (0x00000003u)
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_RESETVAL (0x00000001u)
/*----FRM_STATE Tokens----*/
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_OFF (0x00000001u)
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_IDLE (0x00000002u)
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_RE_SYNC (0x00000004u)
#define CSL_AIF2_TM_LK_STAT_FRM_STATE_FRAME_SYNC (0x00000008u)


#define CSL_AIF2_TM_LK_STAT_RESETVAL   (0x00000008u)

/* TM_FRM_MODE */

#define CSL_AIF2_TM_FRM_MODE_FRM_MODE_MASK (0x00000001u)
#define CSL_AIF2_TM_FRM_MODE_FRM_MODE_SHIFT (0x00000000u)
#define CSL_AIF2_TM_FRM_MODE_FRM_MODE_RESETVAL (0x00000000u)


#define CSL_AIF2_TM_FRM_MODE_RESETVAL  (0x00000000u)

/* RM_LK_CFG0 */

#define CSL_AIF2_RM_LK_CFG0_MODE_SEL_MASK (0x00000001u)
#define CSL_AIF2_RM_LK_CFG0_MODE_SEL_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_MODE_SEL_RESETVAL (0x00000000u)
/*----mode_sel Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_MODE_SEL_CPRI (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_MODE_SEL_OBSAI (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_RX_EN_MASK (0x00000002u)
#define CSL_AIF2_RM_LK_CFG0_RX_EN_SHIFT (0x00000001u)
#define CSL_AIF2_RM_LK_CFG0_RX_EN_RESETVAL (0x00000000u)
/*----rx_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_RX_EN_DISABLE (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_RX_EN_ENABLE (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_MASK (0x0000000Cu)
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_SHIFT (0x00000002u)
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_RESETVAL (0x00000000u)
/*----link_rate Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_8X (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_4X (0x00000001u)
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_2X (0x00000002u)
#define CSL_AIF2_RM_LK_CFG0_LINK_RATE_5X (0x00000003u)

#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_MASK (0x00000030u)
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_SHIFT (0x00000004u)
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_RESETVAL (0x00000000u)
/*----fifo_thold Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_IMMEDIATELY (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_4_DUAL (0x00000001u)
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_8_DUAL (0x00000002u)
#define CSL_AIF2_RM_LK_CFG0_FIFO_THOLD_16_DUAL (0x00000003u)


#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_MASK (0x00000700u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_SHIFT (0x00000008u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_RESETVAL (0x00000000u)
/*----force_rx_state Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST4 (0x00000002u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST5 (0x00000003u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST0 (0x00000004u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST1 (0x00000005u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST2 (0x00000006u)
#define CSL_AIF2_RM_LK_CFG0_FORCE_RX_STATE_ST3 (0x00000007u)

#define CSL_AIF2_RM_LK_CFG0_ERROR_SUPPRESS_MASK (0x00000800u)
#define CSL_AIF2_RM_LK_CFG0_ERROR_SUPPRESS_SHIFT (0x0000000Bu)
#define CSL_AIF2_RM_LK_CFG0_ERROR_SUPPRESS_RESETVAL (0x00000000u)
/*----error_suppress Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_ERROR_SUPPRESS_ALLOW (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_ERROR_SUPPRESS_SUPPRESS (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_SD_AUTO_ALIGN_EN_MASK (0x00001000u)
#define CSL_AIF2_RM_LK_CFG0_SD_AUTO_ALIGN_EN_SHIFT (0x0000000Cu)
#define CSL_AIF2_RM_LK_CFG0_SD_AUTO_ALIGN_EN_RESETVAL (0x00000000u)
/*----sd_auto_align_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_SD_AUTO_ALIGN_EN_DISABLE (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_SD_AUTO_ALIGN_EN_ENABLE (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_SCR_EN_MASK (0x00002000u)
#define CSL_AIF2_RM_LK_CFG0_SCR_EN_SHIFT (0x0000000Du)
#define CSL_AIF2_RM_LK_CFG0_SCR_EN_RESETVAL (0x00000000u)
/*----scr_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_SCR_EN_DISABLE (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_SCR_EN_ENABLE (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_LCV_UNSYNC_EN_MASK (0x00004000u)
#define CSL_AIF2_RM_LK_CFG0_LCV_UNSYNC_EN_SHIFT (0x0000000Eu)
#define CSL_AIF2_RM_LK_CFG0_LCV_UNSYNC_EN_RESETVAL (0x00000000u)
/*----lcv_unsync_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_LCV_UNSYNC_EN_NO_EFFECT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_LCV_UNSYNC_EN_ENABLE_TRANSITION (0x00000001u)

#define CSL_AIF2_RM_LK_CFG0_LCV_CNTR_EN_MASK (0x00008000u)
#define CSL_AIF2_RM_LK_CFG0_LCV_CNTR_EN_SHIFT (0x0000000Fu)
#define CSL_AIF2_RM_LK_CFG0_LCV_CNTR_EN_RESETVAL (0x00000000u)
/*----lcv_cntr_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG0_LCV_CNTR_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_AIF2_RM_LK_CFG0_LCV_CNTR_EN_ENABLED (0x00000001u)


#define CSL_AIF2_RM_LK_CFG0_RESETVAL   (0x00000000u)

/* RM_LK_CFG1 */

#define CSL_AIF2_RM_LK_CFG1_WD_WRAP_MASK (0x000000FFu)
#define CSL_AIF2_RM_LK_CFG1_WD_WRAP_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG1_WD_WRAP_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG1_WD_EN_MASK (0x00000100u)
#define CSL_AIF2_RM_LK_CFG1_WD_EN_SHIFT (0x00000008u)
#define CSL_AIF2_RM_LK_CFG1_WD_EN_RESETVAL (0x00000000u)
/*----wd_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG1_WD_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_AIF2_RM_LK_CFG1_WD_EN_ENABLED (0x00000001u)

#define CSL_AIF2_RM_LK_CFG1_CQ_EN_MASK (0x00000200u)
#define CSL_AIF2_RM_LK_CFG1_CQ_EN_SHIFT (0x00000009u)
#define CSL_AIF2_RM_LK_CFG1_CQ_EN_RESETVAL (0x00000000u)
/*----cq_en Tokens----*/
#define CSL_AIF2_RM_LK_CFG1_CQ_EN_DISABLED_CLEARED (0x00000000u)
#define CSL_AIF2_RM_LK_CFG1_CQ_EN_ENABLED (0x00000001u)


#define CSL_AIF2_RM_LK_CFG1_MON_WRAP_MASK (0xFFFF0000u)
#define CSL_AIF2_RM_LK_CFG1_MON_WRAP_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_CFG1_MON_WRAP_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG1_RESETVAL   (0x00000000u)

/* RM_LK_CFG2 */

#define CSL_AIF2_RM_LK_CFG2_LOS_DET_THOLD_MASK (0x0000FFFFu)
#define CSL_AIF2_RM_LK_CFG2_LOS_DET_THOLD_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG2_LOS_DET_THOLD_RESETVAL (0x00000000u)


#define CSL_AIF2_RM_LK_CFG2_RESETVAL   (0x00000000u)

/* RM_LK_CFG3 */

#define CSL_AIF2_RM_LK_CFG3_SYNC_T_MASK (0x0000FFFFu)
#define CSL_AIF2_RM_LK_CFG3_SYNC_T_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG3_SYNC_T_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG3_FRAME_SYNC_T_MASK (0xFFFF0000u)
#define CSL_AIF2_RM_LK_CFG3_FRAME_SYNC_T_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_CFG3_FRAME_SYNC_T_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG3_RESETVAL   (0x00000000u)

/* RM_LK_CFG4 */

#define CSL_AIF2_RM_LK_CFG4_UNSYNC_T_MASK (0x0000FFFFu)
#define CSL_AIF2_RM_LK_CFG4_UNSYNC_T_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_CFG4_UNSYNC_T_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG4_FRAME_UNSYNC_T_MASK (0xFFFF0000u)
#define CSL_AIF2_RM_LK_CFG4_FRAME_UNSYNC_T_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_CFG4_FRAME_UNSYNC_T_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_CFG4_RESETVAL   (0x00000000u)

/* RM_LK_STS0 */

#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_MASK (0x0000003Fu)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_RESETVAL (0x00000008u)
/*----sync_status Tokens----*/
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST0 (0x00000008u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST1 (0x00000004u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST2 (0x00000002u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST3 (0x00000001u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST4 (0x00000010u)
#define CSL_AIF2_RM_LK_STS0_SYNC_STATUS_ST5 (0x00000020u)


#define CSL_AIF2_RM_LK_STS0_LOS_MASK   (0x00000100u)
#define CSL_AIF2_RM_LK_STS0_LOS_SHIFT  (0x00000008u)
#define CSL_AIF2_RM_LK_STS0_LOS_RESETVAL (0x00000000u)
/*----los Tokens----*/
#define CSL_AIF2_RM_LK_STS0_LOS_NOT_ST0 (0x00000000u)
#define CSL_AIF2_RM_LK_STS0_LOS_ST0    (0x00000001u)

#define CSL_AIF2_RM_LK_STS0_NUM_LOS_DET_MASK (0x00000200u)
#define CSL_AIF2_RM_LK_STS0_NUM_LOS_DET_SHIFT (0x00000009u)
#define CSL_AIF2_RM_LK_STS0_NUM_LOS_DET_RESETVAL (0x00000000u)
/*----num_los_det Tokens----*/
#define CSL_AIF2_RM_LK_STS0_NUM_LOS_DET_NEW_THOLD_OR_ERRORS (0x00000000u)
#define CSL_AIF2_RM_LK_STS0_NUM_LOS_DET_THOLD_REACHED (0x00000001u)

#define CSL_AIF2_RM_LK_STS0_LOC_MASK   (0x00000400u)
#define CSL_AIF2_RM_LK_STS0_LOC_SHIFT  (0x0000000Au)
#define CSL_AIF2_RM_LK_STS0_LOC_RESETVAL (0x00000000u)
/*----loc Tokens----*/
#define CSL_AIF2_RM_LK_STS0_LOC_NOT_ENABLED_OR_NOT_MISSING_CLK (0x00000000u)
#define CSL_AIF2_RM_LK_STS0_LOC_MISSING_CLK (0x00000001u)

#define CSL_AIF2_RM_LK_STS0_FIFO_OVF_MASK (0x00000800u)
#define CSL_AIF2_RM_LK_STS0_FIFO_OVF_SHIFT (0x0000000Bu)
#define CSL_AIF2_RM_LK_STS0_FIFO_OVF_RESETVAL (0x00000000u)
/*----fifo_ovf Tokens----*/
#define CSL_AIF2_RM_LK_STS0_FIFO_OVF_NO_OVERFLOW (0x00000000u)
#define CSL_AIF2_RM_LK_STS0_FIFO_OVF_OVERFLOW (0x00000001u)


#define CSL_AIF2_RM_LK_STS0_RESETVAL   (0x00000008u)

/* RM_LK_STS1 */

#define CSL_AIF2_RM_LK_STS1_NUM_LOS_MASK (0x0000FFFFu)
#define CSL_AIF2_RM_LK_STS1_NUM_LOS_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_STS1_NUM_LOS_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS1_LCV_CNTR_VALUE_MASK (0xFFFF0000u)
#define CSL_AIF2_RM_LK_STS1_LCV_CNTR_VALUE_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_STS1_LCV_CNTR_VALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS1_RESETVAL   (0x00000000u)

/* RM_LK_STS2 */

#define CSL_AIF2_RM_LK_STS2_CLK_QUAL_MASK (0x0000FFFFu)
#define CSL_AIF2_RM_LK_STS2_CLK_QUAL_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_STS2_CLK_QUAL_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS2_SCR_VALUE_MASK (0x007F0000u)
#define CSL_AIF2_RM_LK_STS2_SCR_VALUE_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_STS2_SCR_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_RM_LK_STS2_RESETVAL   (0x00000000u)

/* RM_LK_STS3 */

#define CSL_AIF2_RM_LK_STS3_HFN_MASK   (0x000000FFu)
#define CSL_AIF2_RM_LK_STS3_HFN_SHIFT  (0x00000000u)
#define CSL_AIF2_RM_LK_STS3_HFN_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS3_BFN_LOW_MASK (0x0000FF00u)
#define CSL_AIF2_RM_LK_STS3_BFN_LOW_SHIFT (0x00000008u)
#define CSL_AIF2_RM_LK_STS3_BFN_LOW_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS3_BFN_HIGH_MASK (0x00FF0000u)
#define CSL_AIF2_RM_LK_STS3_BFN_HIGH_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_STS3_BFN_HIGH_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS3_HFSYNC_STATE_MASK (0x01000000u)
#define CSL_AIF2_RM_LK_STS3_HFSYNC_STATE_SHIFT (0x00000018u)
#define CSL_AIF2_RM_LK_STS3_HFSYNC_STATE_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS3_LOF_STATE_MASK (0x02000000u)
#define CSL_AIF2_RM_LK_STS3_LOF_STATE_SHIFT (0x00000019u)
#define CSL_AIF2_RM_LK_STS3_LOF_STATE_RESETVAL (0x00000000u)


#define CSL_AIF2_RM_LK_STS3_RESETVAL   (0x00000000u)

/* RM_LK_STS4 */

#define CSL_AIF2_RM_LK_STS4_L1_VERSION_MASK (0x000000FFu)
#define CSL_AIF2_RM_LK_STS4_L1_VERSION_SHIFT (0x00000000u)
#define CSL_AIF2_RM_LK_STS4_L1_VERSION_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_START_UP_MASK (0x0000FF00u)
#define CSL_AIF2_RM_LK_STS4_L1_START_UP_SHIFT (0x00000008u)
#define CSL_AIF2_RM_LK_STS4_L1_START_UP_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RST_MASK (0x00010000u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RST_SHIFT (0x00000010u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RST_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RAI_MASK (0x00020000u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RAI_SHIFT (0x00000011u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_RAI_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_RCVD_SDI_MASK (0x00040000u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_SDI_SHIFT (0x00000012u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_SDI_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOS_MASK (0x00080000u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOS_SHIFT (0x00000013u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOS_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOF_MASK (0x00100000u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOF_SHIFT (0x00000014u)
#define CSL_AIF2_RM_LK_STS4_L1_RCVD_LOF_RESETVAL (0x00000000u)


#define CSL_AIF2_RM_LK_STS4_L1_PNTR_P_MASK (0xFF000000u)
#define CSL_AIF2_RM_LK_STS4_L1_PNTR_P_SHIFT (0x00000018u)
#define CSL_AIF2_RM_LK_STS4_L1_PNTR_P_RESETVAL (0x00000000u)

#define CSL_AIF2_RM_LK_STS4_RESETVAL   (0x00000000u)

/* RT_LK_CFG */

#define CSL_AIF2_RT_LK_CFG_LINK_RATE_MASK (0x00000003u)
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_SHIFT (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_RESETVAL (0x00000000u)
/*----Link_rate Tokens----*/
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_8X (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_4X (0x00000001u)
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_2X (0x00000002u)
#define CSL_AIF2_RT_LK_CFG_LINK_RATE_5X (0x00000003u)

#define CSL_AIF2_RT_LK_CFG_OBSAI_CPRI_MASK (0x00000004u)
#define CSL_AIF2_RT_LK_CFG_OBSAI_CPRI_SHIFT (0x00000002u)
#define CSL_AIF2_RT_LK_CFG_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----OBSAI_CPRI Tokens----*/
#define CSL_AIF2_RT_LK_CFG_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_OBSAI_CPRI_OBSAI (0x00000001u)

#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_MASK (0x00000018u)
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_SHIFT (0x00000003u)
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_RESETVAL (0x00000000u)
/*----sample_width Tokens----*/
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_7_BIT (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_8_BIT (0x00000001u)
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_15_BIT (0x00000002u)
#define CSL_AIF2_RT_LK_CFG_SAMPLE_WIDTH_16_BIT (0x00000003u)

#define CSL_AIF2_RT_LK_CFG_CI_SELECT_MASK (0x000000E0u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_SHIFT (0x00000005u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_RESETVAL (0x00000000u)
/*----CI_Select Tokens----*/
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK0 (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK1 (0x00000001u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK2 (0x00000002u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK3 (0x00000003u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK4 (0x00000004u)
#define CSL_AIF2_RT_LK_CFG_CI_SELECT_LINK5 (0x00000005u)

#define CSL_AIF2_RT_LK_CFG_EM_ENABLE_MASK (0x00000100u)
#define CSL_AIF2_RT_LK_CFG_EM_ENABLE_SHIFT (0x00000008u)
#define CSL_AIF2_RT_LK_CFG_EM_ENABLE_RESETVAL (0x00000000u)
/*----EM_Enable Tokens----*/
#define CSL_AIF2_RT_LK_CFG_EM_ENABLE_DISABLED (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_EM_ENABLE_ENABLED (0x00000001u)

#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_MASK (0x00000600u)
#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_SHIFT (0x00000009u)
#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_RESETVAL (0x00000000u)
/*----RT_Config Tokens----*/
#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_RETRANSMIT (0x00000000u)
#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_AGGREGATE (0x00000001u)
#define CSL_AIF2_RT_LK_CFG_RT_CONFIG_TRANSMIT (0x00000002u)


#define CSL_AIF2_RT_LK_CFG_RESETVAL    (0x00000000u)

/* RT_LK_DPTH */

#define CSL_AIF2_RT_LK_DPTH_RT_DEPTH_MASK (0x000000FFu)
#define CSL_AIF2_RT_LK_DPTH_RT_DEPTH_SHIFT (0x00000000u)
#define CSL_AIF2_RT_LK_DPTH_RT_DEPTH_RESETVAL (0x00000000u)


#define CSL_AIF2_RT_LK_DPTH_RESETVAL   (0x00000000u)

/* RT_HDR_ERR */

#define CSL_AIF2_RT_HDR_ERR_DMA_CHAN_MASK (0x0000007Fu)
#define CSL_AIF2_RT_HDR_ERR_DMA_CHAN_SHIFT (0x00000000u)
#define CSL_AIF2_RT_HDR_ERR_DMA_CHAN_RESETVAL (0x00000000u)

#define CSL_AIF2_RT_HDR_ERR_HDR_ERR_MASK (0x00000080u)
#define CSL_AIF2_RT_HDR_ERR_HDR_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_RT_HDR_ERR_HDR_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_RT_HDR_ERR_RESETVAL   (0x00000000u)

/* RT_LK_STAT */

#define CSL_AIF2_RT_LK_STAT_RT_HDR_ERR_STS_MASK (0x00000001u)
#define CSL_AIF2_RT_LK_STAT_RT_HDR_ERR_STS_SHIFT (0x00000000u)
#define CSL_AIF2_RT_LK_STAT_RT_HDR_ERR_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_RT_LK_STAT_RT_EM_STS_MASK (0x00000002u)
#define CSL_AIF2_RT_LK_STAT_RT_EM_STS_SHIFT (0x00000001u)
#define CSL_AIF2_RT_LK_STAT_RT_EM_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_RT_LK_STAT_RT_UNFL_STS_MASK (0x00000004u)
#define CSL_AIF2_RT_LK_STAT_RT_UNFL_STS_SHIFT (0x00000002u)
#define CSL_AIF2_RT_LK_STAT_RT_UNFL_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_RT_LK_STAT_RT_OVFL_STS_MASK (0x00000008u)
#define CSL_AIF2_RT_LK_STAT_RT_OVFL_STS_SHIFT (0x00000003u)
#define CSL_AIF2_RT_LK_STAT_RT_OVFL_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_RT_LK_STAT_RT_FRM_ERR_STS_MASK (0x00000010u)
#define CSL_AIF2_RT_LK_STAT_RT_FRM_ERR_STS_SHIFT (0x00000004u)
#define CSL_AIF2_RT_LK_STAT_RT_FRM_ERR_STS_RESETVAL (0x00000000u)


#define CSL_AIF2_RT_LK_STAT_RESETVAL   (0x00000000u)

/* CI_LK_CFG */

#define CSL_AIF2_CI_LK_CFG_LINK_RATE_MASK (0x00000003u)
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_SHIFT (0x00000000u)
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_RESETVAL (0x00000000u)
/*----Link_rate Tokens----*/
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_8X (0x00000000u)
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_4X (0x00000001u)
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_2X (0x00000002u)
#define CSL_AIF2_CI_LK_CFG_LINK_RATE_5X (0x00000003u)

#define CSL_AIF2_CI_LK_CFG_OBSAI_CPRI_MASK (0x00000004u)
#define CSL_AIF2_CI_LK_CFG_OBSAI_CPRI_SHIFT (0x00000002u)
#define CSL_AIF2_CI_LK_CFG_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----OBSAI_CPRI Tokens----*/
#define CSL_AIF2_CI_LK_CFG_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_CI_LK_CFG_OBSAI_CPRI_OBSAI (0x00000001u)

#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_MASK (0x00000018u)
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_SHIFT (0x00000003u)
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_RESETVAL (0x00000000u)
/*----sample_width Tokens----*/
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_7_BIT (0x00000000u)
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_8_BIT (0x00000001u)
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_15_BIT (0x00000002u)
#define CSL_AIF2_CI_LK_CFG_SAMPLE_WIDTH_16_BIT (0x00000003u)


#define CSL_AIF2_CI_LK_CFG_RESETVAL    (0x00000000u)

/* CO_LK_CFG */

#define CSL_AIF2_CO_LK_CFG_LINK_RATE_MASK (0x00000003u)
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_SHIFT (0x00000000u)
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_RESETVAL (0x00000000u)
/*----Link_rate Tokens----*/
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_8X (0x00000000u)
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_4X (0x00000001u)
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_2X (0x00000002u)
#define CSL_AIF2_CO_LK_CFG_LINK_RATE_5X (0x00000003u)

#define CSL_AIF2_CO_LK_CFG_OBSAI_CPRI_MASK (0x00000004u)
#define CSL_AIF2_CO_LK_CFG_OBSAI_CPRI_SHIFT (0x00000002u)
#define CSL_AIF2_CO_LK_CFG_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----OBSAI_CPRI Tokens----*/
#define CSL_AIF2_CO_LK_CFG_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_CO_LK_CFG_OBSAI_CPRI_OBSAI (0x00000001u)

#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_MASK (0x00000018u)
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_SHIFT (0x00000003u)
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_RESETVAL (0x00000000u)
/*----sample_width Tokens----*/
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_7_BIT (0x00000000u)
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_8_BIT (0x00000001u)
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_15_BIT (0x00000002u)
#define CSL_AIF2_CO_LK_CFG_SAMPLE_WIDTH_16_BIT (0x00000003u)


#define CSL_AIF2_CO_LK_CFG_RESETVAL    (0x00000000u)

/* pd_link_a */

#define CSL_AIF2_PD_LINK_A_LINK_EN_MASK (0x00000001u)
#define CSL_AIF2_PD_LINK_A_LINK_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_LINK_A_LINK_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_LINK_A_OBSAI_CPRI_MASK (0x00000010u)
#define CSL_AIF2_PD_LINK_A_OBSAI_CPRI_SHIFT (0x00000004u)
#define CSL_AIF2_PD_LINK_A_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----obsai_cpri Tokens----*/
#define CSL_AIF2_PD_LINK_A_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_PD_LINK_A_OBSAI_CPRI_OBSAI (0x00000001u)


#define CSL_AIF2_PD_LINK_A_ETHNET_STRIP_MASK (0x00000F00u)
#define CSL_AIF2_PD_LINK_A_ETHNET_STRIP_SHIFT (0x00000008u)
#define CSL_AIF2_PD_LINK_A_ETHNET_STRIP_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_LINK_A_CRC8_POLY_MASK (0x00FF0000u)
#define CSL_AIF2_PD_LINK_A_CRC8_POLY_SHIFT (0x00000010u)
#define CSL_AIF2_PD_LINK_A_CRC8_POLY_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LINK_A_CRC8_SEED_MASK (0xFF000000u)
#define CSL_AIF2_PD_LINK_A_CRC8_SEED_SHIFT (0x00000018u)
#define CSL_AIF2_PD_LINK_A_CRC8_SEED_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LINK_A_RESETVAL    (0x00000000u)

/* pd_link_b */

#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_MASK (0x00000003u)
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_SHIFT (0x00000000u)
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_RESETVAL (0x00000000u)
/*----cpri_lk_rate Tokens----*/
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_8X_RATE (0x00000000u)
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_4X_RATE (0x00000001u)
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_2X_RATE (0x00000002u)
#define CSL_AIF2_PD_LINK_B_CPRI_LK_RATE_5X_RATE (0x00000003u)

#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_MASK (0x0000000Cu)
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_SHIFT (0x00000002u)
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_RESETVAL (0x00000000u)
/*----cpri_axc_pack Tokens----*/
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_7_BIT (0x00000000u)
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_8_BIT (0x00000001u)
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_15_BIT (0x00000002u)
#define CSL_AIF2_PD_LINK_B_CPRI_AXC_PACK_16_BIT (0x00000003u)


#define CSL_AIF2_PD_LINK_B_CPRI_NULLDELM_MASK (0x001FF000u)
#define CSL_AIF2_PD_LINK_B_CPRI_NULLDELM_SHIFT (0x0000000Cu)
#define CSL_AIF2_PD_LINK_B_CPRI_NULLDELM_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_MASK (0x03000000u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_SHIFT (0x00000018u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_RESETVAL (0x00000000u)
/*----pkt_delim_ch0 Tokens----*/
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_NO_CW (0x00000000u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_4B5B (0x00000001u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_NULLDELM (0x00000002u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH0_HYP_FRM (0x00000003u)

#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH1_MASK (0x0C000000u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH1_SHIFT (0x0000001Au)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH1_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH2_MASK (0x30000000u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH2_SHIFT (0x0000001Cu)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH2_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH3_MASK (0xC0000000u)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH3_SHIFT (0x0000001Eu)
#define CSL_AIF2_PD_LINK_B_PKT_DELIM_CH3_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LINK_B_RESETVAL    (0x00000000u)

/* pd_lk_pack_cpri */

#define CSL_AIF2_PD_LK_PACK_CPRI_PRE_ENC_BITSWAP_MASK (0x0000000Fu)
#define CSL_AIF2_PD_LK_PACK_CPRI_PRE_ENC_BITSWAP_SHIFT (0x00000000u)
#define CSL_AIF2_PD_LK_PACK_CPRI_PRE_ENC_BITSWAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_LK_PACK_CPRI_POST_ENC_BITSWAP_MASK (0x000000F0u)
#define CSL_AIF2_PD_LK_PACK_CPRI_POST_ENC_BITSWAP_SHIFT (0x00000004u)
#define CSL_AIF2_PD_LK_PACK_CPRI_POST_ENC_BITSWAP_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_LK_PACK_CPRI_RESETVAL (0x00000000u)

/* pd_cpri_crc */

#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_MASK (0x00000003u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_SHIFT (0x00000000u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_RESETVAL (0x00000000u)
/*----crc0_type Tokens----*/
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_32BIT_CRC (0x00000000u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_16BIT_CRC (0x00000001u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_8BIT_CRC (0x00000002u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_TYPE_RESERVED (0x00000003u)

#define CSL_AIF2_PD_CPRI_CRC_CRC0_EN_MASK (0x00000004u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_EN_SHIFT (0x00000002u)
#define CSL_AIF2_PD_CPRI_CRC_CRC0_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_CPRI_CRC_CRC1_TYPE_MASK (0x00000030u)
#define CSL_AIF2_PD_CPRI_CRC_CRC1_TYPE_SHIFT (0x00000004u)
#define CSL_AIF2_PD_CPRI_CRC_CRC1_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CPRI_CRC_CRC1_EN_MASK (0x00000040u)
#define CSL_AIF2_PD_CPRI_CRC_CRC1_EN_SHIFT (0x00000006u)
#define CSL_AIF2_PD_CPRI_CRC_CRC1_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_CPRI_CRC_CRC2_TYPE_MASK (0x00000300u)
#define CSL_AIF2_PD_CPRI_CRC_CRC2_TYPE_SHIFT (0x00000008u)
#define CSL_AIF2_PD_CPRI_CRC_CRC2_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CPRI_CRC_CRC2_EN_MASK (0x00000400u)
#define CSL_AIF2_PD_CPRI_CRC_CRC2_EN_SHIFT (0x0000000Au)
#define CSL_AIF2_PD_CPRI_CRC_CRC2_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_CPRI_CRC_CRC3_TYPE_MASK (0x00003000u)
#define CSL_AIF2_PD_CPRI_CRC_CRC3_TYPE_SHIFT (0x0000000Cu)
#define CSL_AIF2_PD_CPRI_CRC_CRC3_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CPRI_CRC_CRC3_EN_MASK (0x00004000u)
#define CSL_AIF2_PD_CPRI_CRC_CRC3_EN_SHIFT (0x0000000Eu)
#define CSL_AIF2_PD_CPRI_CRC_CRC3_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_CPRI_CRC_RESETVAL  (0x00000000u)

/* pd_pack_map */

#define CSL_AIF2_PD_PACK_MAP_PACK0_DMA_CH_MASK (0x0000007Fu)
#define CSL_AIF2_PD_PACK_MAP_PACK0_DMA_CH_SHIFT (0x00000000u)
#define CSL_AIF2_PD_PACK_MAP_PACK0_DMA_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK0_EN_MASK (0x00000080u)
#define CSL_AIF2_PD_PACK_MAP_PACK0_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PD_PACK_MAP_PACK0_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK1_DMA_CH_MASK (0x00007F00u)
#define CSL_AIF2_PD_PACK_MAP_PACK1_DMA_CH_SHIFT (0x00000008u)
#define CSL_AIF2_PD_PACK_MAP_PACK1_DMA_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK1_EN_MASK (0x00008000u)
#define CSL_AIF2_PD_PACK_MAP_PACK1_EN_SHIFT (0x0000000Fu)
#define CSL_AIF2_PD_PACK_MAP_PACK1_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK2_DMA_CH_MASK (0x007F0000u)
#define CSL_AIF2_PD_PACK_MAP_PACK2_DMA_CH_SHIFT (0x00000010u)
#define CSL_AIF2_PD_PACK_MAP_PACK2_DMA_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK2_EN_MASK (0x00800000u)
#define CSL_AIF2_PD_PACK_MAP_PACK2_EN_SHIFT (0x00000017u)
#define CSL_AIF2_PD_PACK_MAP_PACK2_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK3_DMA_CH_MASK (0x7F000000u)
#define CSL_AIF2_PD_PACK_MAP_PACK3_DMA_CH_SHIFT (0x00000018u)
#define CSL_AIF2_PD_PACK_MAP_PACK3_DMA_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_PACK3_EN_MASK (0x80000000u)
#define CSL_AIF2_PD_PACK_MAP_PACK3_EN_SHIFT (0x0000001Fu)
#define CSL_AIF2_PD_PACK_MAP_PACK3_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_PACK_MAP_RESETVAL  (0x00000000u)

/* pd_dbm */

#define CSL_AIF2_PD_DBM_DBM_X_MASK     (0x0000007Fu)
#define CSL_AIF2_PD_DBM_DBM_X_SHIFT    (0x00000000u)
#define CSL_AIF2_PD_DBM_DBM_X_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DBM_DBM_XBUBBLE_MASK (0x00000780u)
#define CSL_AIF2_PD_DBM_DBM_XBUBBLE_SHIFT (0x00000007u)
#define CSL_AIF2_PD_DBM_DBM_XBUBBLE_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DBM_DBM_1MULT_MASK (0x0000F800u)
#define CSL_AIF2_PD_DBM_DBM_1MULT_SHIFT (0x0000000Bu)
#define CSL_AIF2_PD_DBM_DBM_1MULT_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DBM_DBM_1SIZE_MASK (0x007F0000u)
#define CSL_AIF2_PD_DBM_DBM_1SIZE_SHIFT (0x00000010u)
#define CSL_AIF2_PD_DBM_DBM_1SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_DBM_DBM_2SIZE_MASK (0x7F000000u)
#define CSL_AIF2_PD_DBM_DBM_2SIZE_SHIFT (0x00000018u)
#define CSL_AIF2_PD_DBM_DBM_2SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_DBM_RESETVAL       (0x00000000u)

/* pd_dbm_1map */

#define CSL_AIF2_PD_DBM_1MAP_DBM_1MAP_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DBM_1MAP_DBM_1MAP_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DBM_1MAP_DBM_1MAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DBM_1MAP_RESETVAL  (0x00000000u)

/* pd_dbm_2map */

#define CSL_AIF2_PD_DBM_2MAP_DBM_2MAP_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DBM_2MAP_DBM_2MAP_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DBM_2MAP_DBM_2MAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DBM_2MAP_RESETVAL  (0x00000000u)

/* pd_type_lut */

#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_MASK (0x00000007u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_SHIFT (0x00000000u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_RESETVAL (0x00000000u)
/*----ts_format Tokens----*/
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_NO_TS (0x00000000u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_NORM_TS (0x00000001u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_GSM (0x00000002u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_GEN_PKT (0x00000003u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_ETHERNET (0x00000004u)
#define CSL_AIF2_PD_TYPE_LUT_TS_FORMAT_CTR_PKT (0x00000005u)


#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_MASK (0x00000030u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_SHIFT (0x00000004u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_RESETVAL (0x00000000u)
/*----crc_type Tokens----*/
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_32BIT_CRC (0x00000000u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_16BIT_CRC (0x00000001u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_8BIT_CRC (0x00000002u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_TYPE_RESERVED (0x00000003u)

#define CSL_AIF2_PD_TYPE_LUT_CRC_EN_MASK (0x00000040u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_EN_SHIFT (0x00000006u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_TYPE_LUT_OBSAI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PD_TYPE_LUT_OBSAI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PD_TYPE_LUT_OBSAI_PKT_EN_RESETVAL (0x00000000u)
/*----obsai_pkt_en Tokens----*/
#define CSL_AIF2_PD_TYPE_LUT_OBSAI_PKT_EN_OBSAI_AXC (0x00000000u)
#define CSL_AIF2_PD_TYPE_LUT_OBSAI_PKT_EN_OBSAI_PKT (0x00000001u)


#define CSL_AIF2_PD_TYPE_LUT_ENET_STRIP_MASK (0x00000800u)
#define CSL_AIF2_PD_TYPE_LUT_ENET_STRIP_SHIFT (0x0000000Bu)
#define CSL_AIF2_PD_TYPE_LUT_ENET_STRIP_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_TYPE_LUT_CRC_HDR_MASK (0x00010000u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_HDR_SHIFT (0x00000010u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_HDR_RESETVAL (0x00000000u)
/*----crc_hdr Tokens----*/
#define CSL_AIF2_PD_TYPE_LUT_CRC_HDR_CRC_HDR_ON (0x00000001u)
#define CSL_AIF2_PD_TYPE_LUT_CRC_HDR_CRC_HDR_OFF (0x00000000u)


#define CSL_AIF2_PD_TYPE_LUT_RESETVAL  (0x00000000u)

/* pd_cpri_id_lut */

#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_DMACHAN_MASK (0x0000007Fu)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_DMACHAN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_DMACHAN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_X_EN_MASK (0x00000080u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_X_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_X_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_8WD_OFSET_MASK (0x00007000u)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_8WD_OFSET_SHIFT (0x0000000Cu)
#define CSL_AIF2_PD_CPRI_ID_LUT_CPRI_8WD_OFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_CPRI_ID_LUT_RESETVAL (0x00000000u)

/* pd_cw_lut */

#define CSL_AIF2_PD_CW_LUT_CW_CHAN_MASK (0x00000003u)
#define CSL_AIF2_PD_CW_LUT_CW_CHAN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_CW_LUT_CW_CHAN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CW_LUT_CW_EN_MASK  (0x00000004u)
#define CSL_AIF2_PD_CW_LUT_CW_EN_SHIFT (0x00000002u)
#define CSL_AIF2_PD_CW_LUT_CW_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CW_LUT_HYPFM_EOP_MASK (0x00000008u)
#define CSL_AIF2_PD_CW_LUT_HYPFM_EOP_SHIFT (0x00000003u)
#define CSL_AIF2_PD_CW_LUT_HYPFM_EOP_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CW_LUT_RESETVAL    (0x00000000u)

/* pe_link */

#define CSL_AIF2_PE_LINK_LK_EN_MASK    (0x00000001u)
#define CSL_AIF2_PE_LINK_LK_EN_SHIFT   (0x00000000u)
#define CSL_AIF2_PE_LINK_LK_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_LINK_DIO_CPPI_MASK (0x00000002u)
#define CSL_AIF2_PE_LINK_DIO_CPPI_SHIFT (0x00000001u)
#define CSL_AIF2_PE_LINK_DIO_CPPI_RESETVAL (0x00000000u)
/*----dio_cppi Tokens----*/
#define CSL_AIF2_PE_LINK_DIO_CPPI_CPPI (0x00000000u)
#define CSL_AIF2_PE_LINK_DIO_CPPI_DIO  (0x00000001u)

#define CSL_AIF2_PE_LINK_TDD_AXC_MASK  (0x00000004u)
#define CSL_AIF2_PE_LINK_TDD_AXC_SHIFT (0x00000002u)
#define CSL_AIF2_PE_LINK_TDD_AXC_RESETVAL (0x00000000u)
/*----tdd_axc Tokens----*/
#define CSL_AIF2_PE_LINK_TDD_AXC_OTHER (0x00000000u)
#define CSL_AIF2_PE_LINK_TDD_AXC_TDD   (0x00000001u)

#define CSL_AIF2_PE_LINK_GSM_COMPRESS_MASK (0x00000008u)
#define CSL_AIF2_PE_LINK_GSM_COMPRESS_SHIFT (0x00000003u)
#define CSL_AIF2_PE_LINK_GSM_COMPRESS_RESETVAL (0x00000000u)
/*----gsm_compress Tokens----*/
#define CSL_AIF2_PE_LINK_GSM_COMPRESS_GSMC_OFF (0x00000000u)
#define CSL_AIF2_PE_LINK_GSM_COMPRESS_GSMC_ON (0x00000001u)

#define CSL_AIF2_PE_LINK_OBSAI_CPRI_MASK (0x00000010u)
#define CSL_AIF2_PE_LINK_OBSAI_CPRI_SHIFT (0x00000004u)
#define CSL_AIF2_PE_LINK_OBSAI_CPRI_RESETVAL (0x00000000u)
/*----obsai_cpri Tokens----*/
#define CSL_AIF2_PE_LINK_OBSAI_CPRI_CPRI (0x00000000u)
#define CSL_AIF2_PE_LINK_OBSAI_CPRI_OBSAI (0x00000001u)


#define CSL_AIF2_PE_LINK_LK_RATE_MASK  (0x00030000u)
#define CSL_AIF2_PE_LINK_LK_RATE_SHIFT (0x00000010u)
#define CSL_AIF2_PE_LINK_LK_RATE_RESETVAL (0x00000000u)
/*----lk_rate Tokens----*/
#define CSL_AIF2_PE_LINK_LK_RATE_8X_RATE (0x00000000u)
#define CSL_AIF2_PE_LINK_LK_RATE_4X_RATE (0x00000001u)
#define CSL_AIF2_PE_LINK_LK_RATE_2X_RATE (0x00000002u)
#define CSL_AIF2_PE_LINK_LK_RATE_5X_RATE (0x00000003u)


#define CSL_AIF2_PE_LINK_OBSAIBUBBLE_BW_MASK (0x00100000u)
#define CSL_AIF2_PE_LINK_OBSAIBUBBLE_BW_SHIFT (0x00000014u)
#define CSL_AIF2_PE_LINK_OBSAIBUBBLE_BW_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_LINK_MEMFETCH_DELAY_MASK (0x1F000000u)
#define CSL_AIF2_PE_LINK_MEMFETCH_DELAY_SHIFT (0x00000018u)
#define CSL_AIF2_PE_LINK_MEMFETCH_DELAY_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_LINK_RESETVAL      (0x00000000u)

/* pe_crc */

#define CSL_AIF2_PE_CRC_CRC8_POLY_MASK (0x000000FFu)
#define CSL_AIF2_PE_CRC_CRC8_POLY_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CRC_CRC8_POLY_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CRC_CRC8_SEED_MASK (0x0000FF00u)
#define CSL_AIF2_PE_CRC_CRC8_SEED_SHIFT (0x00000008u)
#define CSL_AIF2_PE_CRC_CRC8_SEED_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CRC_RESETVAL       (0x00000000u)

/* pe_cpri_dbm */

#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_X_MASK (0x0000007Fu)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_X_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_X_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_XBUBBLE_MASK (0x00000780u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_XBUBBLE_SHIFT (0x00000007u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_XBUBBLE_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1MULT_MASK (0x0000F800u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1MULT_SHIFT (0x0000000Bu)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1MULT_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1SIZE_MASK (0x007F0000u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1SIZE_SHIFT (0x00000010u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_1SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_2SIZE_MASK (0x7F000000u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_2SIZE_SHIFT (0x00000018u)
#define CSL_AIF2_PE_CPRI_DBM_CPRI_DBM_2SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CPRI_DBM_RESETVAL  (0x00000000u)

/* pe_cpri_bitswap */

#define CSL_AIF2_PE_CPRI_BITSWAP_PRE_ENC_BITSWAP_MASK (0x0000000Fu)
#define CSL_AIF2_PE_CPRI_BITSWAP_PRE_ENC_BITSWAP_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRI_BITSWAP_PRE_ENC_BITSWAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI_BITSWAP_POST_ENC_BITSWAP_MASK (0x000000F0u)
#define CSL_AIF2_PE_CPRI_BITSWAP_POST_ENC_BITSWAP_SHIFT (0x00000004u)
#define CSL_AIF2_PE_CPRI_BITSWAP_POST_ENC_BITSWAP_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CPRI_BITSWAP_RESETVAL (0x00000000u)

/* pe_cpridbm_1map */

#define CSL_AIF2_PE_CPRIDBM_1MAP_CPRI_DBM_1MAP_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_CPRIDBM_1MAP_CPRI_DBM_1MAP_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRIDBM_1MAP_CPRI_DBM_1MAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRIDBM_1MAP_RESETVAL (0x00000000u)

/* pe_cpridbm_2map */

#define CSL_AIF2_PE_CPRIDBM_2MAP_CPRI_DBM_2MAP_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_CPRIDBM_2MAP_CPRI_DBM_2MAP_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRIDBM_2MAP_CPRI_DBM_2MAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRIDBM_2MAP_RESETVAL (0x00000000u)

/* pe_cpri0 */

#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_MASK (0x00000003u)
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_RESETVAL (0x00000000u)
/*----cpri_axc_pack Tokens----*/
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_7_BIT (0x00000000u)
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_8_BIT (0x00000001u)
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_15_BIT (0x00000002u)
#define CSL_AIF2_PE_CPRI0_CPRI_AXC_PACK_16_BIT (0x00000003u)


#define CSL_AIF2_PE_CPRI0_CPRI_NULLDELM_MASK (0x001FF000u)
#define CSL_AIF2_PE_CPRI0_CPRI_NULLDELM_SHIFT (0x0000000Cu)
#define CSL_AIF2_PE_CPRI0_CPRI_NULLDELM_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_MASK (0x03000000u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_SHIFT (0x00000018u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_RESETVAL (0x00000000u)
/*----pkt_delim_ch0 Tokens----*/
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_NO_CW (0x00000000u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_4B5B (0x00000001u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_NULLDELM (0x00000002u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH0_HYP_FRM (0x00000003u)

#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH1_MASK (0x0C000000u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH1_SHIFT (0x0000001Au)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH1_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH2_MASK (0x30000000u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH2_SHIFT (0x0000001Cu)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH2_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH3_MASK (0xC0000000u)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH3_SHIFT (0x0000001Eu)
#define CSL_AIF2_PE_CPRI0_PKT_DELIM_CH3_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI0_RESETVAL     (0x00000000u)

/* pe_cpri1 */

#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_MASK (0x0000007Fu)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT0_CH_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_MASK (0x00007F00u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_SHIFT (0x00000008u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_EN_MASK (0x00008000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_EN_SHIFT (0x0000000Fu)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT1_CH_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_MASK (0x007F0000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_SHIFT (0x00000010u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_EN_MASK (0x00800000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_EN_SHIFT (0x00000017u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT2_CH_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_MASK (0x7F000000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_SHIFT (0x00000018u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_EN_MASK (0x80000000u)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_EN_SHIFT (0x0000001Fu)
#define CSL_AIF2_PE_CPRI1_CPRI_PKT3_CH_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI1_RESETVAL     (0x00000000u)

/* pe_cpri_cw_lut */

#define CSL_AIF2_PE_CPRI_CW_LUT_CW_CHAN_MASK (0x00000003u)
#define CSL_AIF2_PE_CPRI_CW_LUT_CW_CHAN_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CPRI_CW_LUT_CW_CHAN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CPRI_CW_LUT_CW_EN_MASK (0x00000004u)
#define CSL_AIF2_PE_CPRI_CW_LUT_CW_EN_SHIFT (0x00000002u)
#define CSL_AIF2_PE_CPRI_CW_LUT_CW_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_CPRI_CW_LUT_RESETVAL (0x00000000u)

/* aif2_pid */

#define CSL_AIF2_AIF2_PID_MINOR_MASK   (0x0000003Fu)
#define CSL_AIF2_AIF2_PID_MINOR_SHIFT  (0x00000000u)
#define CSL_AIF2_AIF2_PID_MINOR_RESETVAL (0x00000001u)

#define CSL_AIF2_AIF2_PID_CUSTOM_MASK  (0x000000C0u)
#define CSL_AIF2_AIF2_PID_CUSTOM_SHIFT (0x00000006u)
#define CSL_AIF2_AIF2_PID_CUSTOM_RESETVAL (0x00000000u)

#define CSL_AIF2_AIF2_PID_MAJOR_MASK   (0x00000700u)
#define CSL_AIF2_AIF2_PID_MAJOR_SHIFT  (0x00000008u)
#define CSL_AIF2_AIF2_PID_MAJOR_RESETVAL (0x00000001u)

#define CSL_AIF2_AIF2_PID_RTL_MASK     (0x0000F800u)
#define CSL_AIF2_AIF2_PID_RTL_SHIFT    (0x0000000Bu)
#define CSL_AIF2_AIF2_PID_RTL_RESETVAL (0x00000006u)

#define CSL_AIF2_AIF2_PID_FUNC_MASK    (0x0FFF0000u)
#define CSL_AIF2_AIF2_PID_FUNC_SHIFT   (0x00000010u)
#define CSL_AIF2_AIF2_PID_FUNC_RESETVAL (0x00000806u)


#define CSL_AIF2_AIF2_PID_SCHEME_MASK  (0xC0000000u)
#define CSL_AIF2_AIF2_PID_SCHEME_SHIFT (0x0000001Eu)
#define CSL_AIF2_AIF2_PID_SCHEME_RESETVAL (0x00000001u)

#define CSL_AIF2_AIF2_PID_RESETVAL     (0x48063101u)

/* aif2_scratch */

#define CSL_AIF2_AIF2_SCRATCH_SCRATCH_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AIF2_SCRATCH_SCRATCH_SHIFT (0x00000000u)
#define CSL_AIF2_AIF2_SCRATCH_SCRATCH_RESETVAL (0x00000000u)

#define CSL_AIF2_AIF2_SCRATCH_RESETVAL (0x00000000u)

/* aif2_reset */

#define CSL_AIF2_AIF2_RESET_SW_RST_MASK (0x00000001u)
#define CSL_AIF2_AIF2_RESET_SW_RST_SHIFT (0x00000000u)
#define CSL_AIF2_AIF2_RESET_SW_RST_RESETVAL (0x00000000u)
/*----sw_rst Tokens----*/
#define CSL_AIF2_AIF2_RESET_SW_RST_NO_RESET (0x00000000u)
#define CSL_AIF2_AIF2_RESET_SW_RST_PULSE_RESET (0x00000001u)


#define CSL_AIF2_AIF2_RESET_RESETVAL   (0x00000000u)

/* aif2_emu */

#define CSL_AIF2_AIF2_EMU_FREERUN_MASK (0x00000001u)
#define CSL_AIF2_AIF2_EMU_FREERUN_SHIFT (0x00000000u)
#define CSL_AIF2_AIF2_EMU_FREERUN_RESETVAL (0x00000000u)
/*----FREERUN Tokens----*/
#define CSL_AIF2_AIF2_EMU_FREERUN_RESPOND (0x00000000u)
#define CSL_AIF2_AIF2_EMU_FREERUN_IGNORE (0x00000001u)

#define CSL_AIF2_AIF2_EMU_SOFT_MASK    (0x00000002u)
#define CSL_AIF2_AIF2_EMU_SOFT_SHIFT   (0x00000001u)
#define CSL_AIF2_AIF2_EMU_SOFT_RESETVAL (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_AIF2_AIF2_EMU_SOFT_HARD_STOP (0x00000000u)
#define CSL_AIF2_AIF2_EMU_SOFT_SOFT_STOP (0x00000001u)

#define CSL_AIF2_AIF2_EMU_RT_SEL_MASK  (0x00000004u)
#define CSL_AIF2_AIF2_EMU_RT_SEL_SHIFT (0x00000002u)
#define CSL_AIF2_AIF2_EMU_RT_SEL_RESETVAL (0x00000000u)
/*----RT_SEL Tokens----*/
#define CSL_AIF2_AIF2_EMU_RT_SEL_EMU_DBGSUSP (0x00000000u)
#define CSL_AIF2_AIF2_EMU_RT_SEL_EMU_DBGSUSP_RT (0x00000001u)


#define CSL_AIF2_AIF2_EMU_RESETVAL     (0x00000000u)

/* vc_stat */

#define CSL_AIF2_VC_STAT_EMU_HALT_MASK (0x00000001u)
#define CSL_AIF2_VC_STAT_EMU_HALT_SHIFT (0x00000000u)
#define CSL_AIF2_VC_STAT_EMU_HALT_RESETVAL (0x00000000u)


#define CSL_AIF2_VC_STAT_RESETVAL      (0x00000000u)

/* EE_VB_EOI */

#define CSL_AIF2_EE_VB_EOI_EOI_VECTOR_MASK (0x000000FFu)
#define CSL_AIF2_EE_VB_EOI_EOI_VECTOR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VB_EOI_EOI_VECTOR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VB_EOI_RESETVAL    (0x00000000u)

/* EE_VB_INTR_SET */

#define CSL_AIF2_EE_VB_INTR_SET_ERR_INTR_SET_MASK (0x00000001u)
#define CSL_AIF2_EE_VB_INTR_SET_ERR_INTR_SET_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_SET_ERR_INTR_SET_RESETVAL (0x00000000u)
/*----err_intr_set Tokens----*/
#define CSL_AIF2_EE_VB_INTR_SET_ERR_INTR_SET_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_SET_ERR_INTR_SET_SET_INTERRUPT (0x00000001u)

#define CSL_AIF2_EE_VB_INTR_SET_ALARM_INTR_SET_MASK (0x00000002u)
#define CSL_AIF2_EE_VB_INTR_SET_ALARM_INTR_SET_SHIFT (0x00000001u)
#define CSL_AIF2_EE_VB_INTR_SET_ALARM_INTR_SET_RESETVAL (0x00000000u)
/*----alarm_intr_set Tokens----*/
#define CSL_AIF2_EE_VB_INTR_SET_ALARM_INTR_SET_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_SET_ALARM_INTR_SET_SET_INTERRUPT (0x00000001u)

#define CSL_AIF2_EE_VB_INTR_SET_CDMA_INTR_SET_MASK (0x00000004u)
#define CSL_AIF2_EE_VB_INTR_SET_CDMA_INTR_SET_SHIFT (0x00000002u)
#define CSL_AIF2_EE_VB_INTR_SET_CDMA_INTR_SET_RESETVAL (0x00000000u)
/*----cdma_intr_set Tokens----*/
#define CSL_AIF2_EE_VB_INTR_SET_CDMA_INTR_SET_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_SET_CDMA_INTR_SET_SET_INTERRUPT (0x00000001u)


#define CSL_AIF2_EE_VB_INTR_SET_RESETVAL (0x00000000u)

/* EE_VB_INTR_CLR */

#define CSL_AIF2_EE_VB_INTR_CLR_ERR_INTR_CLR_MASK (0x00000001u)
#define CSL_AIF2_EE_VB_INTR_CLR_ERR_INTR_CLR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_CLR_ERR_INTR_CLR_RESETVAL (0x00000000u)
/*----err_intr_clr Tokens----*/
#define CSL_AIF2_EE_VB_INTR_CLR_ERR_INTR_CLR_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_CLR_ERR_INTR_CLR_CLEAR_INTERRUPT (0x00000001u)

#define CSL_AIF2_EE_VB_INTR_CLR_ALARM_INTR_CLR_MASK (0x00000002u)
#define CSL_AIF2_EE_VB_INTR_CLR_ALARM_INTR_CLR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_VB_INTR_CLR_ALARM_INTR_CLR_RESETVAL (0x00000000u)
/*----alarm_intr_clr Tokens----*/
#define CSL_AIF2_EE_VB_INTR_CLR_ALARM_INTR_CLR_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_CLR_ALARM_INTR_CLR_CLEAR_INTERRUPT (0x00000001u)

#define CSL_AIF2_EE_VB_INTR_CLR_CDMA_INTR_CLR_MASK (0x00000004u)
#define CSL_AIF2_EE_VB_INTR_CLR_CDMA_INTR_CLR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_VB_INTR_CLR_CDMA_INTR_CLR_RESETVAL (0x00000000u)
/*----cdma_intr_clr Tokens----*/
#define CSL_AIF2_EE_VB_INTR_CLR_CDMA_INTR_CLR_NO_ACTION (0x00000000u)
#define CSL_AIF2_EE_VB_INTR_CLR_CDMA_INTR_CLR_CLEAR_INTERRUPT (0x00000001u)


#define CSL_AIF2_EE_VB_INTR_CLR_RESETVAL (0x00000000u)

/* ee_db_irs */

#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_IRS_RESETVAL    (0x00000000u)

/* ee_db_irs_set */

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_IRS_SET_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_IRS_SET_RESETVAL (0x00000000u)

/* ee_db_irs_clr */

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_IRS_CLR_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_IRS_CLR_RESETVAL (0x00000000u)

/* ee_db_en_ev0 */

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_EV0_RESETVAL (0x00000000u)

/* ee_db_en_set_ev0 */

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_SET_EV0_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_db_en_clr_ev0 */

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_CLR_EV0_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_db_en_ev1 */

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_EV1_RESETVAL (0x00000000u)

/* ee_db_en_set_ev1 */

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_SET_EV1_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_db_en_clr_ev1 */

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_CLR_EV1_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_db_en_sts_ev0 */

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_db_en_sts_ev1 */

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TRC_RAM_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TOKEN_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TOKEN_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TOKEN_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_FIFO_OVFL_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_FIFO_OVFL_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_FIFO_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_PD2DB_FULL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_PD2DB_FULL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_I_PD2DB_FULL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_PS_AXC_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_PS_AXC_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_PS_AXC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_TYPE_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_TYPE_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_TYPE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_DB_EN_STS_EV1_RESETVAL (0x00000000u)

/* ee_ad_irs */

#define CSL_AIF2_EE_AD_IRS_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_IRS_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_RESETVAL    (0x00000000u)

/* ee_ad_irs_set */

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_IRS_SET_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_SET_RESETVAL (0x00000000u)

/* ee_ad_irs_clr */

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_IRS_CLR_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_IRS_CLR_RESETVAL (0x00000000u)

/* ee_ad_en_ev0 */

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV0_RESETVAL (0x00000000u)

/* ee_ad_en_set_ev0 */

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_SET_EV0_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_ad_en_clr_ev0 */

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_CLR_EV0_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_ad_en_ev1 */

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_EV1_RESETVAL (0x00000000u)

/* ee_ad_en_set_ev1 */

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_SET_EV1_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_ad_en_clr_ev1 */

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_CLR_EV1_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_ad_en_sts_ev0 */

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_ad_en_sts_ev1 */

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_CD_DATA_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_CD_DATA_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_CD_DATA_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_CD_SCH_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_CD_SCH_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_CD_SCH_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_0_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_0_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_1_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_1_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_2_ERR_MASK (0x00040000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_2_ERR_SHIFT (0x00000012u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_0_ERR_MASK (0x01000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_0_ERR_SHIFT (0x00000018u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_1_ERR_MASK (0x02000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_1_ERR_SHIFT (0x00000019u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_2_ERR_MASK (0x04000000u)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_2_ERR_SHIFT (0x0000001Au)
#define CSL_AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_2_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AD_EN_STS_EV1_RESETVAL (0x00000000u)

/* ee_cd_irs */

#define CSL_AIF2_EE_CD_IRS_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_IRS_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_IRS_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_IRS_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_IRS_RESETVAL    (0x00000000u)

/* ee_cd_irs_set */

#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_SET_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_IRS_SET_RESETVAL (0x00000000u)

/* ee_cd_irs_clr */

#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_IRS_CLR_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_IRS_CLR_RESETVAL (0x00000000u)

/* ee_cd_en_ev */

#define CSL_AIF2_EE_CD_EN_EV_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_EN_EV_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_EN_EV_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_EN_EV_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_EN_EV_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_EN_EV_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_EN_EV_RESETVAL  (0x00000000u)

/* ee_cd_en_set_ev */

#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_EN_SET_EV_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_EN_SET_EV_RESETVAL (0x00000000u)

/* ee_cd_en_clr_ev */

#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_EN_CLR_EV_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_EN_CLR_EV_RESETVAL (0x00000000u)

/* ee_cd_en_sts_ev */

#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_SOP_DESC_STARVE_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_SOP_DESC_STARVE_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_SOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_MOP_DESC_STARVE_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_MOP_DESC_STARVE_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_CD_EN_STS_EV_CD_EE_MOP_DESC_STARVE_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_CD_EN_STS_EV_RESETVAL (0x00000000u)

/* ee_sd_irs */

#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_IRS_RESETVAL    (0x00000000u)

/* ee_sd_irs_set */

#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_SET_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_IRS_SET_RESETVAL (0x00000000u)

/* ee_sd_irs_clr */

#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_IRS_CLR_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_IRS_CLR_RESETVAL (0x00000000u)

/* ee_sd_en_ev0 */

#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_EV0_RESETVAL (0x00000000u)

/* ee_sd_en_set_ev0 */

#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_SET_EV0_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_sd_en_clr_ev0 */

#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_CLR_EV0_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_sd_en_ev1 */

#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_EV1_RESETVAL (0x00000000u)

/* ee_sd_en_set_ev1 */

#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_SET_EV1_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_sd_en_clr_ev1 */

#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_CLR_EV1_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_sd_en_sts_ev0 */

#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_sd_en_sts_ev1 */

#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B4_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B4_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B8_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B8_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B8_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_SD_EN_STS_EV1_RESETVAL (0x00000000u)

/* ee_vc_irs */

#define CSL_AIF2_EE_VC_IRS_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_IRS_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_IRS_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_IRS_RESETVAL    (0x00000000u)

/* ee_vc_irs_set */

#define CSL_AIF2_EE_VC_IRS_SET_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_IRS_SET_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_IRS_SET_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_IRS_SET_RESETVAL (0x00000000u)

/* ee_vc_irs_clr */

#define CSL_AIF2_EE_VC_IRS_CLR_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_IRS_CLR_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_IRS_CLR_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_IRS_CLR_RESETVAL (0x00000000u)

/* ee_vc_en_ev0 */

#define CSL_AIF2_EE_VC_EN_EV0_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_EV0_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_EV0_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_EV0_RESETVAL (0x00000000u)

/* ee_vc_en_set_ev0 */

#define CSL_AIF2_EE_VC_EN_SET_EV0_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_SET_EV0_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_SET_EV0_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_vc_en_clr_ev0 */

#define CSL_AIF2_EE_VC_EN_CLR_EV0_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_CLR_EV0_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_CLR_EV0_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_vc_en_ev1 */

#define CSL_AIF2_EE_VC_EN_EV1_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_EV1_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_EV1_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_EV1_RESETVAL (0x00000000u)

/* ee_vc_en_set_ev1 */

#define CSL_AIF2_EE_VC_EN_SET_EV1_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_SET_EV1_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_SET_EV1_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_vc_en_clr_ev1 */

#define CSL_AIF2_EE_VC_EN_CLR_EV1_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_CLR_EV1_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_CLR_EV1_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_vc_en_sts_ev0 */

#define CSL_AIF2_EE_VC_EN_STS_EV0_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_STS_EV0_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_STS_EV0_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_vc_en_sts_ev1 */

#define CSL_AIF2_EE_VC_EN_STS_EV1_VC_EE_VBUS_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_VC_EN_STS_EV1_VC_EE_VBUS_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_VC_EN_STS_EV1_VC_EE_VBUS_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_VC_EN_STS_EV1_RESETVAL (0x00000000u)

/* EE_AIF2_RUN_STS */

#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN_MASK (0x00000001u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN_RESETVAL (0x00000000u)
/*----aif2_phy_run Tokens----*/
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN_NOT_RUNNING (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN_RUNNING (0x00000001u)

#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN_MASK (0x00000002u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN_RESETVAL (0x00000000u)
/*----aif2_global_run Tokens----*/
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN_NOT_RUNNING (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN_RUNNING (0x00000001u)


#define CSL_AIF2_EE_AIF2_RUN_STS_RESETVAL (0x00000000u)

/* EE_AIF2_RUN_CTL */

#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_PHY_RUN_MASK (0x00000001u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_PHY_RUN_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_PHY_RUN_RESETVAL (0x00000000u)
/*----aif2_phy_run Tokens----*/
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_PHY_RUN_NOT_RUNNING (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_PHY_RUN_RUNNING (0x00000001u)

#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_GLOBAL_RUN_MASK (0x00000002u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_GLOBAL_RUN_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_GLOBAL_RUN_RESETVAL (0x00000000u)
/*----aif2_global_run Tokens----*/
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_GLOBAL_RUN_NOT_RUNNING (0x00000000u)
#define CSL_AIF2_EE_AIF2_RUN_CTL_AIF2_GLOBAL_RUN_RUNNING (0x00000001u)


#define CSL_AIF2_EE_AIF2_RUN_CTL_RESETVAL (0x00000000u)

/* ee_err_alrm_orgn */

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0_MASK (0x00000001u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0_SHIFT (0x00000000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0_MASK (0x00000002u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0_SHIFT (0x00000001u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A1_MASK (0x00000004u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A1_SHIFT (0x00000002u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A1_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B1_MASK (0x00000008u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B1_SHIFT (0x00000003u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B1_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A2_MASK (0x00000010u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A2_SHIFT (0x00000004u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A2_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B2_MASK (0x00000020u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B2_SHIFT (0x00000005u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B2_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A3_MASK (0x00000040u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A3_SHIFT (0x00000006u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A3_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B3_MASK (0x00000080u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B3_SHIFT (0x00000007u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B3_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A4_MASK (0x00000100u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A4_SHIFT (0x00000008u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A4_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B4_MASK (0x00000200u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B4_SHIFT (0x00000009u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B4_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A5_MASK (0x00000400u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A5_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A5_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B5_MASK (0x00000800u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B5_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B5_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_AT_EN_STS_MASK (0x00001000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_AT_EN_STS_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_AT_EN_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_SD_EN_STS_MASK (0x00002000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_SD_EN_STS_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_SD_EN_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_DB_EN_STS_MASK (0x00004000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_DB_EN_STS_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_DB_EN_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_AD_EN_STS_MASK (0x00008000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_AD_EN_STS_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_AD_EN_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_CD_EN_STS_MASK (0x00010000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_CD_EN_STS_SHIFT (0x00000010u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_CD_EN_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_ERR_ALRM_ORGN_VC_EN_STS_MASK (0x00020000u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_VC_EN_STS_SHIFT (0x00000011u)
#define CSL_AIF2_EE_ERR_ALRM_ORGN_VC_EN_STS_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_ERR_ALRM_ORGN_RESETVAL (0x00000000u)

/* SD_PLL_B8_EN_CFG */

#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_MASK (0x00000003u)
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_SHIFT (0x00000000u)
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_RESETVAL (0x00000000u)
/*----Enable B8 PLL Tokens----*/
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_DISABLE (0x00000000u)
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_SLEEP (0x00000001u)
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_SNOOZE (0x00000002u)
#define CSL_AIF2_SD_PLL_B8_EN_CFG_ENABLEB8_PLL_ENABLE (0x00000003u)


#define CSL_AIF2_SD_PLL_B8_EN_CFG_RESETVAL (0x00000000u)

/* SD_PLL_B4_EN_CFG */

#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_MASK (0x00000003u)
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_SHIFT (0x00000000u)
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_RESETVAL (0x00000000u)
/*----Enable B4 PLL Tokens----*/
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_DISABLE (0x00000000u)
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_SLEEP (0x00000001u)
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_SNOOZE (0x00000002u)
#define CSL_AIF2_SD_PLL_B4_EN_CFG_ENABLEB4_PLL_ENABLE (0x00000003u)


#define CSL_AIF2_SD_PLL_B4_EN_CFG_RESETVAL (0x00000000u)

/* SD_PLL_B8_STS */

#define CSL_AIF2_SD_PLL_B8_STS_B8PLL_LOCK_MASK (0x00000001u)
#define CSL_AIF2_SD_PLL_B8_STS_B8PLL_LOCK_SHIFT (0x00000000u)
#define CSL_AIF2_SD_PLL_B8_STS_B8PLL_LOCK_RESETVAL (0x00000000u)


#define CSL_AIF2_SD_PLL_B8_STS_RESETVAL (0x00000000u)

/* SD_PLL_B4_STS */

#define CSL_AIF2_SD_PLL_B4_STS_B4PLL_LOCK_MASK (0x00000001u)
#define CSL_AIF2_SD_PLL_B4_STS_B4PLL_LOCK_SHIFT (0x00000000u)
#define CSL_AIF2_SD_PLL_B4_STS_B4PLL_LOCK_RESETVAL (0x00000000u)


#define CSL_AIF2_SD_PLL_B4_STS_RESETVAL (0x00000000u)

/* SD_CLK_SEL_CFG */

#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_MASK (0x00000003u)
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_SHIFT (0x00000000u)
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_RESETVAL (0x00000000u)
/*----serdes clksel Tokens----*/
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_B8_B4_DEFAULT_LOCKDET (0x00000000u)
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_B8_LOCKDET (0x00000001u)
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_B4_LOCKDET (0x00000002u)
#define CSL_AIF2_SD_CLK_SEL_CFG_SERDESCLKSEL_B8_B4_LOCKDET (0x00000003u)


#define CSL_AIF2_SD_CLK_SEL_CFG_RESETVAL (0x00000000u)

/* SD_LK_CLK_DIS_CFG */

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_0_MASK (0x00000001u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_0_SHIFT (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_0_RESETVAL (0x00000000u)
/*----Disable Link clock 0 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_0_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_0_DISABLE (0x00000001u)

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_1_MASK (0x00000002u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_1_SHIFT (0x00000001u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_1_RESETVAL (0x00000000u)
/*----Disable Link clock 1 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_1_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_1_DISABLE (0x00000001u)

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_2_MASK (0x00000004u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_2_SHIFT (0x00000002u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_2_RESETVAL (0x00000000u)
/*----Disable Link clock 2 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_2_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_2_DISABLE (0x00000001u)

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_3_MASK (0x00000008u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_3_SHIFT (0x00000003u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_3_RESETVAL (0x00000000u)
/*----Disable Link clock 3 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_3_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_3_DISABLE (0x00000001u)

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_4_MASK (0x00000010u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_4_SHIFT (0x00000004u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_4_RESETVAL (0x00000000u)
/*----Disable Link clock 4 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_4_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_4_DISABLE (0x00000001u)

#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_5_MASK (0x00000020u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_5_SHIFT (0x00000005u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_5_RESETVAL (0x00000000u)
/*----Disable Link clock 5 Tokens----*/
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_5_ENABLE (0x00000000u)
#define CSL_AIF2_SD_LK_CLK_DIS_CFG_DISABLELINK_CLOCK_5_DISABLE (0x00000001u)


#define CSL_AIF2_SD_LK_CLK_DIS_CFG_RESETVAL (0x00000000u)

/* AD_DIO_DT_DMA_CFG0 */

#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_RD_CH_EN_MASK (0x00000001u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_RD_CH_EN_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_RD_CH_EN_RESETVAL (0x00000000u)
/*----dt_dma_rd_ch_en Tokens----*/
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_RD_CH_EN_RDMACLR (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_RD_CH_EN_RDMAEN (0x00000001u)

#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_FM_CH_EN_MASK (0x00000002u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_FM_CH_EN_SHIFT (0x00000001u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_FM_CH_EN_RESETVAL (0x00000000u)
/*----dt_dma_fm_ch_en Tokens----*/
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_FM_CH_EN_FDMACLR (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_DT_DMA_FM_CH_EN_FDMAEN (0x00000001u)


#define CSL_AIF2_AD_DIO_DT_DMA_CFG0_RESETVAL (0x00000000u)

/* AD_DIO_DT_DMA_CFG1 */

#define CSL_AIF2_AD_DIO_DT_DMA_CFG1_DT_DMA_RD_BASE_ADDR_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG1_DT_DMA_RD_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG1_DT_DMA_RD_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_DT_DMA_CFG1_RESETVAL (0x00000000u)

/* AD_DIO_DT_DMA_CFG2 */

#define CSL_AIF2_AD_DIO_DT_DMA_CFG2_DT_DMA_FM_BASE_ADDR_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG2_DT_DMA_FM_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG2_DT_DMA_FM_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_DT_DMA_CFG2_RESETVAL (0x00000000u)

/* AD_DIO_DT_DMA_CFG3 */

#define CSL_AIF2_AD_DIO_DT_DMA_CFG3_DT_DMA_WRAP_MASK (0x0003FFFFu)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG3_DT_DMA_WRAP_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_DT_DMA_CFG3_DT_DMA_WRAP_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_DT_DMA_CFG3_RESETVAL (0x00000000u)

/* AD_DIO_I_GLOBAL_EN_SET */

#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* AD_DIO_I_GLOBAL_EN_CLR */

#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* AD_DIO_I_GLOBAL_EN_STS */

#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_I_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* AD_DIO_E_GLOBAL_EN_SET */

#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* AD_DIO_E_GLOBAL_EN_CLR */

#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* AD_DIO_E_GLOBAL_EN_STS */

#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_DIO_E_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* AD_ISCH_CFG */

#define CSL_AIF2_AD_ISCH_CFG_FAIL_MODE_MASK (0x00000001u)
#define CSL_AIF2_AD_ISCH_CFG_FAIL_MODE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ISCH_CFG_FAIL_MODE_RESETVAL (0x00000000u)
/*----fail_mode Tokens----*/
#define CSL_AIF2_AD_ISCH_CFG_FAIL_MODE_DROP (0x00000000u)
#define CSL_AIF2_AD_ISCH_CFG_FAIL_MODE_MARK (0x00000001u)


#define CSL_AIF2_AD_ISCH_CFG_PRI_MASK  (0x00010000u)
#define CSL_AIF2_AD_ISCH_CFG_PRI_SHIFT (0x00000010u)
#define CSL_AIF2_AD_ISCH_CFG_PRI_RESETVAL (0x00000000u)
/*----pri Tokens----*/
#define CSL_AIF2_AD_ISCH_CFG_PRI_DIOPRI (0x00000000u)
#define CSL_AIF2_AD_ISCH_CFG_PRI_PKTPRI (0x00000001u)


#define CSL_AIF2_AD_ISCH_CFG_RESETVAL  (0x00000000u)

/* AD_ISCH_GLOBAL_EN_SET */

#define CSL_AIF2_AD_ISCH_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_ISCH_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* AD_ISCH_GLOBAL_EN_CLR */

#define CSL_AIF2_AD_ISCH_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_ISCH_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* AD_ISCH_GLOBAL_EN_STS */

#define CSL_AIF2_AD_ISCH_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ISCH_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_ISCH_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* AD_ISCH_EOP_CNT */

#define CSL_AIF2_AD_ISCH_EOP_CNT_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_AIF2_AD_ISCH_EOP_CNT_EOP_CNT_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ISCH_EOP_CNT_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_ISCH_EOP_CNT_RESETVAL (0x00000000u)

/* AD_ESCH_CFG */

#define CSL_AIF2_AD_ESCH_CFG_TXQ_QMGR_MASK (0x00000003u)
#define CSL_AIF2_AD_ESCH_CFG_TXQ_QMGR_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ESCH_CFG_TXQ_QMGR_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_ESCH_CFG_TXQ_QNUM_MASK (0x0000FFF0u)
#define CSL_AIF2_AD_ESCH_CFG_TXQ_QNUM_SHIFT (0x00000004u)
#define CSL_AIF2_AD_ESCH_CFG_TXQ_QNUM_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_ESCH_CFG_PRI_MASK  (0x00010000u)
#define CSL_AIF2_AD_ESCH_CFG_PRI_SHIFT (0x00000010u)
#define CSL_AIF2_AD_ESCH_CFG_PRI_RESETVAL (0x00000000u)
/*----pri Tokens----*/
#define CSL_AIF2_AD_ESCH_CFG_PRI_DIOPRI (0x00000000u)
#define CSL_AIF2_AD_ESCH_CFG_PRI_PKTPRI (0x00000001u)


#define CSL_AIF2_AD_ESCH_CFG_RESETVAL  (0x00000000u)

/* AD_ESCH_GLOBAL_EN_SET */

#define CSL_AIF2_AD_ESCH_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_ESCH_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* AD_ESCH_GLOBAL_EN_CLR */

#define CSL_AIF2_AD_ESCH_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_AD_ESCH_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* AD_ESCH_GLOBAL_EN_STS */

#define CSL_AIF2_AD_ESCH_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AD_ESCH_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AD_ESCH_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* DB_IDB_CFG */

#define CSL_AIF2_DB_IDB_CFG_IDB_DEBUG_EN_MASK (0x00000001u)
#define CSL_AIF2_DB_IDB_CFG_IDB_DEBUG_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_IDB_DEBUG_EN_RESETVAL (0x00000000u)
/*----IDB_DEBUG_EN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_IDB_DEBUG_EN_NO_DEBUG (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_IDB_DEBUG_EN_DEBUG (0x00000001u)

#define CSL_AIF2_DB_IDB_CFG_DIO_LEN_MASK (0x00000002u)
#define CSL_AIF2_DB_IDB_CFG_DIO_LEN_SHIFT (0x00000001u)
#define CSL_AIF2_DB_IDB_CFG_DIO_LEN_RESETVAL (0x00000000u)
/*----DIO_LEN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_DIO_LEN_128_BYTES (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_DIO_LEN_256_BYTES (0x00000001u)


#define CSL_AIF2_DB_IDB_CFG_DTB_EN_MASK (0x00000010u)
#define CSL_AIF2_DB_IDB_CFG_DTB_EN_SHIFT (0x00000004u)
#define CSL_AIF2_DB_IDB_CFG_DTB_EN_RESETVAL (0x00000000u)
/*----DTB_EN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_DTB_EN_NO_CAPTURE (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_DTB_EN_CAPTURE (0x00000001u)

#define CSL_AIF2_DB_IDB_CFG_DTF_EN_MASK (0x00000020u)
#define CSL_AIF2_DB_IDB_CFG_DTF_EN_SHIFT (0x00000005u)
#define CSL_AIF2_DB_IDB_CFG_DTF_EN_RESETVAL (0x00000000u)
/*----DTF_EN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_DTF_EN_NO_CAPTURE (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_DTF_EN_CAPTURE (0x00000001u)

#define CSL_AIF2_DB_IDB_CFG_DT_SYNC_MASK (0x00000040u)
#define CSL_AIF2_DB_IDB_CFG_DT_SYNC_SHIFT (0x00000006u)
#define CSL_AIF2_DB_IDB_CFG_DT_SYNC_RESETVAL (0x00000000u)
/*----DT_SYNC Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_DT_SYNC_NO_SYNC (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_DT_SYNC_SYNC (0x00000001u)

#define CSL_AIF2_DB_IDB_CFG_DT_EN_MASK (0x00000080u)
#define CSL_AIF2_DB_IDB_CFG_DT_EN_SHIFT (0x00000007u)
#define CSL_AIF2_DB_IDB_CFG_DT_EN_RESETVAL (0x00000000u)
/*----DT_EN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_DT_EN_NO_ENABLE (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_DT_EN_ENABLE (0x00000001u)


#define CSL_AIF2_DB_IDB_CFG_RESETVAL   (0x00000000u)

/* DB_IDB_GLOBAL_EN_SET */

#define CSL_AIF2_DB_IDB_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* DB_IDB_GLOBAL_EN_CLR */

#define CSL_AIF2_DB_IDB_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* DB_IDB_GLOBAL_EN_STS */

#define CSL_AIF2_DB_IDB_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* DB_IDB_CH_EN */

#define CSL_AIF2_DB_IDB_CH_EN_EN_MASK  (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_CH_EN_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_CH_EN_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_CH_EN_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_D0 */

#define CSL_AIF2_DB_IDB_DEBUG_D0_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_DEBUG_D0_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_D0_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_D0_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_D1 */

#define CSL_AIF2_DB_IDB_DEBUG_D1_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_DEBUG_D1_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_D1_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_D1_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_D2 */

#define CSL_AIF2_DB_IDB_DEBUG_D2_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_DEBUG_D2_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_D2_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_D2_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_D3 */

#define CSL_AIF2_DB_IDB_DEBUG_D3_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_DEBUG_D3_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_D3_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_D3_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_SBND */

#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_WR_EN_MASK (0x00000001u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_WR_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_WR_EN_RESETVAL (0x00000000u)
/*----dio_wr_en Tokens----*/
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_WR_EN_DIO_DIS (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_WR_EN_DIO_EN (0x00000001u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_FIFO_WR_EN_MASK (0x00000002u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_FIFO_WR_EN_SHIFT (0x00000001u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_FIFO_WR_EN_RESETVAL (0x00000000u)
/*----fifo_wr_en Tokens----*/
#define CSL_AIF2_DB_IDB_DEBUG_SBND_FIFO_WR_EN_FIFO_DIS (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_FIFO_WR_EN_FIFO_EN (0x00000001u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_SOP_MASK (0x00000004u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SOP_SHIFT (0x00000002u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SOP_RESETVAL (0x00000000u)
/*----sop Tokens----*/
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SOP_NOT_SOP (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SOP_SOP (0x00000001u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_EOP_MASK (0x00000008u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_EOP_SHIFT (0x00000003u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_EOP_RESETVAL (0x00000000u)
/*----eop Tokens----*/
#define CSL_AIF2_DB_IDB_DEBUG_SBND_EOP_NOT_EOP (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_EOP_EOP (0x00000001u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_CH_ID_MASK (0x000007F0u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_CH_ID_SHIFT (0x00000004u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_CH_ID_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_ADDR_MASK (0x0000F000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_ADDR_SHIFT (0x0000000Cu)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_MASK (0x001F0000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_SHIFT (0x00000010u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_RESETVAL (0x00000000u)
/*----xcnt Tokens----*/
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_ZERO (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_ONE (0x00000001u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_TWO (0x00000002u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_THREE (0x00000003u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_FOUR (0x00000004u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_FIVE (0x00000005u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_SIX (0x00000006u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_SEVEN (0x00000007u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_EIGHT (0x00000008u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_NINE (0x00000009u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_TEN (0x0000000au)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_ELEVEN (0x0000000bu)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_TWELVE (0x0000000cu)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_THIRTEEN (0x0000000du)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_FOURTEEN (0x0000000eu)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_FIFTEEN (0x0000000fu)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_XCNT_SIXTEEN (0x00000010u)


#define CSL_AIF2_DB_IDB_DEBUG_SBND_SYMBOL_MASK (0xFF000000u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SYMBOL_SHIFT (0x00000018u)
#define CSL_AIF2_DB_IDB_DEBUG_SBND_SYMBOL_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_SBND_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_DB_WR */

#define CSL_AIF2_DB_IDB_DEBUG_DB_WR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_DEBUG_DB_WR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_DB_WR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_DB_WR_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_OFS */

#define CSL_AIF2_DB_IDB_DEBUG_OFS_WADDR_MASK (0x0000007Fu)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_WADDR_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_WADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_DEBUG_OFS_RADDR_MASK (0x00007F00u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_RADDR_SHIFT (0x00000008u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_RADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_DEBUG_OFS_RESETVAL (0x00000000u)

/* DB_IDB_DEBUG_OFS_DAT */

#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_WOFF_MASK (0x000000FFu)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_WOFF_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_WOFF_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_ROFF_MASK (0x0000FF00u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_ROFF_SHIFT (0x00000008u)
#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_ROFF_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_DEBUG_OFS_DAT_RESETVAL (0x00000000u)

/* DB_IDB_PTR_CH */

#define CSL_AIF2_DB_IDB_PTR_CH_BASE_ADDR_MASK (0x0000007Fu)
#define CSL_AIF2_DB_IDB_PTR_CH_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_PTR_CH_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_MASK (0x00000700u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_SHIFT (0x00000008u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_RESETVAL (0x00000000u)
/*----BUF_DEPTH Tokens----*/
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW8 (0x00000000u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW16 (0x00000001u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW32 (0x00000002u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW64 (0x00000003u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW128 (0x00000004u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW256 (0x00000005u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW256A (0x00000006u)
#define CSL_AIF2_DB_IDB_PTR_CH_BUF_DEPTH_QW256B (0x00000007u)


#define CSL_AIF2_DB_IDB_PTR_CH_RESETVAL (0x00000000u)

/* DB_IDB_CFG_CH */

#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_MASK (0x00000003u)
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_NONE (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_BYTE (0x00000001u)
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_HALF (0x00000002u)
#define CSL_AIF2_DB_IDB_CFG_CH_DAT_SWAP_WORD (0x00000003u)


#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_MASK (0x00000030u)
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_BYTE (0x00000002u)
#define CSL_AIF2_DB_IDB_CFG_CH_IQ_ORDER_HALF (0x00000003u)


#define CSL_AIF2_DB_IDB_CFG_CH_PS_EN_MASK (0x00000100u)
#define CSL_AIF2_DB_IDB_CFG_CH_PS_EN_SHIFT (0x00000008u)
#define CSL_AIF2_DB_IDB_CFG_CH_PS_EN_RESETVAL (0x00000000u)
/*----PS_EN Tokens----*/
#define CSL_AIF2_DB_IDB_CFG_CH_PS_EN_DONT_PREPEND (0x00000000u)
#define CSL_AIF2_DB_IDB_CFG_CH_PS_EN_PREPEND (0x00000001u)


#define CSL_AIF2_DB_IDB_CFG_CH_PKT_TYPE_MASK (0x001F0000u)
#define CSL_AIF2_DB_IDB_CFG_CH_PKT_TYPE_SHIFT (0x00000010u)
#define CSL_AIF2_DB_IDB_CFG_CH_PKT_TYPE_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_IDB_CFG_CH_RESETVAL (0x00000000u)

/* DB_IDB_CH_EMPTY */

#define CSL_AIF2_DB_IDB_CH_EMPTY_EMPTY_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_IDB_CH_EMPTY_EMPTY_SHIFT (0x00000000u)
#define CSL_AIF2_DB_IDB_CH_EMPTY_EMPTY_RESETVAL (0xFFFFFFFFu)

#define CSL_AIF2_DB_IDB_CH_EMPTY_RESETVAL (0xFFFFFFFFu)

/* DB_EDB_CFG */

#define CSL_AIF2_DB_EDB_CFG_EDB_DEBUG_EN_MASK (0x00000001u)
#define CSL_AIF2_DB_EDB_CFG_EDB_DEBUG_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_EDB_DEBUG_EN_RESETVAL (0x00000000u)
/*----EDB_DEBUG_EN Tokens----*/
#define CSL_AIF2_DB_EDB_CFG_EDB_DEBUG_EN_NO_DEBUG (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_EDB_DEBUG_EN_DEBUG (0x00000001u)

#define CSL_AIF2_DB_EDB_CFG_DIO_LEN_MASK (0x00000002u)
#define CSL_AIF2_DB_EDB_CFG_DIO_LEN_SHIFT (0x00000001u)
#define CSL_AIF2_DB_EDB_CFG_DIO_LEN_RESETVAL (0x00000000u)
/*----DIO_LEN Tokens----*/
#define CSL_AIF2_DB_EDB_CFG_DIO_LEN_128_BYTES (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_DIO_LEN_256_BYTES (0x00000001u)

#define CSL_AIF2_DB_EDB_CFG_PM_CTL_MASK (0x00000004u)
#define CSL_AIF2_DB_EDB_CFG_PM_CTL_SHIFT (0x00000002u)
#define CSL_AIF2_DB_EDB_CFG_PM_CTL_RESETVAL (0x00000000u)
/*----PM_CTL Tokens----*/
#define CSL_AIF2_DB_EDB_CFG_PM_CTL_PM_FIFO (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_PM_CTL_AXC_FIFO (0x00000001u)


#define CSL_AIF2_DB_EDB_CFG_RESETVAL   (0x00000000u)

/* DB_EDB_GLOBAL_EN_SET */

#define CSL_AIF2_DB_EDB_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* DB_EDB_GLOBAL_EN_CLR */

#define CSL_AIF2_DB_EDB_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* DB_EDB_GLOBAL_EN_STS */

#define CSL_AIF2_DB_EDB_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* DB_EDB_CH_EN */

#define CSL_AIF2_DB_EDB_CH_EN_EN_MASK  (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_CH_EN_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_CH_EN_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_CH_EN_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_D0 */

#define CSL_AIF2_DB_EDB_DEBUG_D0_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_D0_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_D0_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_D0_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_D1 */

#define CSL_AIF2_DB_EDB_DEBUG_D1_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_D1_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_D1_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_D1_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_D2 */

#define CSL_AIF2_DB_EDB_DEBUG_D2_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_D2_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_D2_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_D2_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_D3 */

#define CSL_AIF2_DB_EDB_DEBUG_D3_DATA_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_D3_DATA_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_D3_DATA_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_D3_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_SBND */

#define CSL_AIF2_DB_EDB_DEBUG_SBND_SOP_MASK (0x00000001u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SOP_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SOP_RESETVAL (0x00000000u)
/*----sop Tokens----*/
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SOP_NOT_SOP (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SOP_SOP (0x00000001u)

#define CSL_AIF2_DB_EDB_DEBUG_SBND_EOP_MASK (0x00000002u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_EOP_SHIFT (0x00000001u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_EOP_RESETVAL (0x00000000u)
/*----eop Tokens----*/
#define CSL_AIF2_DB_EDB_DEBUG_SBND_EOP_NOT_EOP (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_EOP_EOP (0x00000001u)


#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_MASK (0x000001F0u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_SHIFT (0x00000004u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_RESETVAL (0x00000000u)
/*----xcnt Tokens----*/
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_ZERO (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_ONE (0x00000001u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_TWO (0x00000002u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_THREE (0x00000003u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_FOUR (0x00000004u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_FIVE (0x00000005u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_SIX (0x00000006u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_SEVEN (0x00000007u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_EIGHT (0x00000008u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_NINE (0x00000009u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_TEN (0x0000000au)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_ELEVEN (0x0000000bu)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_TWELVE (0x0000000cu)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_THIRTEEN (0x0000000du)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_FOURTEEN (0x0000000eu)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_FIFTEEN (0x0000000fu)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_XCNT_SIXTEEN (0x00000010u)


#define CSL_AIF2_DB_EDB_DEBUG_SBND_SYMBOL_MASK (0x00FF0000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SYMBOL_SHIFT (0x00000010u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_SYMBOL_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_SBND_AXC_MASK (0x7F000000u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_AXC_SHIFT (0x00000018u)
#define CSL_AIF2_DB_EDB_DEBUG_SBND_AXC_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_DEBUG_SBND_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_RD_CNTL */

#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_DIO_RD_EN_MASK (0x00000001u)
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_DIO_RD_EN_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_DIO_RD_EN_RESETVAL (0x00000000u)
/*----dio_rd_en Tokens----*/
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_DIO_RD_EN_DIO_DIS (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_DIO_RD_EN_DIO_EN (0x00000001u)


#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_CH_ID_MASK (0x000007F0u)
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_CH_ID_SHIFT (0x00000004u)
#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_CH_ID_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_DEBUG_RD_CNTL_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_DB_RD */

#define CSL_AIF2_DB_EDB_DEBUG_DB_RD_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_DB_RD_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_DB_RD_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_DB_RD_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_OFS */

#define CSL_AIF2_DB_EDB_DEBUG_OFS_WADDR_MASK (0x0000007Fu)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_WADDR_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_WADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_DEBUG_OFS_RADDR_MASK (0x00007F00u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_RADDR_SHIFT (0x00000008u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_RADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_DEBUG_OFS_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_OFS_DAT */

#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_WOFF_MASK (0x000000FFu)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_WOFF_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_WOFF_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_ROFF_MASK (0x0000FF00u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_ROFF_SHIFT (0x00000008u)
#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_ROFF_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_DEBUG_OFS_DAT_RESETVAL (0x00000000u)

/* DB_EDB_DEBUG_WR_TOK */

#define CSL_AIF2_DB_EDB_DEBUG_WR_TOK_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_EDB_DEBUG_WR_TOK_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_DEBUG_WR_TOK_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_EDB_DEBUG_WR_TOK_RESETVAL (0x00000000u)

/* DB_EDB_EOP_CNT */

#define CSL_AIF2_DB_EDB_EOP_CNT_EOP_CNT_MASK (0x00FFFFFFu)
#define CSL_AIF2_DB_EDB_EOP_CNT_EOP_CNT_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_EOP_CNT_EOP_CNT_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_EOP_CNT_RESETVAL (0x00000000u)

/* DB_EDB_PTR_CH */

#define CSL_AIF2_DB_EDB_PTR_CH_BASE_ADDR_MASK (0x0000007Fu)
#define CSL_AIF2_DB_EDB_PTR_CH_BASE_ADDR_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_PTR_CH_BASE_ADDR_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_MASK (0x00000700u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_SHIFT (0x00000008u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_RESETVAL (0x00000000u)
/*----BUF_DEPTH Tokens----*/
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW8 (0x00000000u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW16 (0x00000001u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW32 (0x00000002u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW64 (0x00000003u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW128 (0x00000004u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW256 (0x00000005u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW256A (0x00000006u)
#define CSL_AIF2_DB_EDB_PTR_CH_BUF_DEPTH_QW256B (0x00000007u)


#define CSL_AIF2_DB_EDB_PTR_CH_RESETVAL (0x00000000u)

/* DB_EDB_CFG_CH */

#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_MASK (0x00000003u)
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_SHIFT (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_RESETVAL (0x00000000u)
/*----DAT_SWAP Tokens----*/
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_NONE (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_BYTE (0x00000001u)
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_HALF (0x00000002u)
#define CSL_AIF2_DB_EDB_CFG_CH_DAT_SWAP_WORD (0x00000003u)


#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_MASK (0x00000030u)
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_SHIFT (0x00000004u)
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_RESETVAL (0x00000000u)
/*----IQ_ORDER Tokens----*/
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_NONE1 (0x00000000u)
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_NONE2 (0x00000001u)
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_BYTE (0x00000002u)
#define CSL_AIF2_DB_EDB_CFG_CH_IQ_ORDER_HALF (0x00000003u)


#define CSL_AIF2_DB_EDB_CFG_CH_DIO_OFFSET_MASK (0x00000F00u)
#define CSL_AIF2_DB_EDB_CFG_CH_DIO_OFFSET_SHIFT (0x00000008u)
#define CSL_AIF2_DB_EDB_CFG_CH_DIO_OFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_DB_EDB_CFG_CH_RESETVAL (0x00000000u)

/* REVISION_REG */

#define CSL_AIF2_REVISION_REG_MODID_MASK (0xFFFF0000u)
#define CSL_AIF2_REVISION_REG_MODID_SHIFT (0x00000010u)
#define CSL_AIF2_REVISION_REG_MODID_RESETVAL (0x00004E5Au)

#define CSL_AIF2_REVISION_REG_REVRTL_MASK (0x0000F800u)
#define CSL_AIF2_REVISION_REG_REVRTL_SHIFT (0x0000000Bu)
#define CSL_AIF2_REVISION_REG_REVRTL_RESETVAL (0x00000019u)

#define CSL_AIF2_REVISION_REG_REVMAJ_MASK (0x00000700u)
#define CSL_AIF2_REVISION_REG_REVMAJ_SHIFT (0x00000008u)
#define CSL_AIF2_REVISION_REG_REVMAJ_RESETVAL (0x00000001u)

#define CSL_AIF2_REVISION_REG_CUSTOM_MASK (0x000000C0u)
#define CSL_AIF2_REVISION_REG_CUSTOM_SHIFT (0x00000006u)
#define CSL_AIF2_REVISION_REG_CUSTOM_RESETVAL (0x00000000u)

#define CSL_AIF2_REVISION_REG_REVMIN_MASK (0x0000003Fu)
#define CSL_AIF2_REVISION_REG_REVMIN_SHIFT (0x00000000u)
#define CSL_AIF2_REVISION_REG_REVMIN_RESETVAL (0x00000000u)

#define CSL_AIF2_REVISION_REG_RESETVAL (0x4E5AC900u)

/* PERF_CTRL_REG */

#define CSL_AIF2_PERF_CTRL_REG_WARB_FIFO_DEPTH_MASK (0x003F0000u)
#define CSL_AIF2_PERF_CTRL_REG_WARB_FIFO_DEPTH_SHIFT (0x00000010u)
#define CSL_AIF2_PERF_CTRL_REG_WARB_FIFO_DEPTH_RESETVAL (0x00000020u)

#define CSL_AIF2_PERF_CTRL_REG_TIMEOUT_CNT_MASK (0x0000FFFFu)
#define CSL_AIF2_PERF_CTRL_REG_TIMEOUT_CNT_SHIFT (0x00000000u)
#define CSL_AIF2_PERF_CTRL_REG_TIMEOUT_CNT_RESETVAL (0x00000000u)

#define CSL_AIF2_PERF_CTRL_REG_RESETVAL (0x00200000u)

/* EMU_CTRL_REG */

#define CSL_AIF2_EMU_CTRL_REG_LOOPBACK_EN_MASK (0x80000000u)
#define CSL_AIF2_EMU_CTRL_REG_LOOPBACK_EN_SHIFT (0x0000001Fu)
#define CSL_AIF2_EMU_CTRL_REG_LOOPBACK_EN_RESETVAL (0x00000001u)

#define CSL_AIF2_EMU_CTRL_REG_SOFT_MASK (0x00000002u)
#define CSL_AIF2_EMU_CTRL_REG_SOFT_SHIFT (0x00000001u)
#define CSL_AIF2_EMU_CTRL_REG_SOFT_RESETVAL (0x00000000u)

#define CSL_AIF2_EMU_CTRL_REG_FREE_MASK (0x00000001u)
#define CSL_AIF2_EMU_CTRL_REG_FREE_SHIFT (0x00000000u)
#define CSL_AIF2_EMU_CTRL_REG_FREE_RESETVAL (0x00000000u)

#define CSL_AIF2_EMU_CTRL_REG_RESETVAL (0x80000000u)

/* PRI_CTRL_REG */

#define CSL_AIF2_PRI_CTRL_REG_RX_PRIORITY_MASK (0x00070000u)
#define CSL_AIF2_PRI_CTRL_REG_RX_PRIORITY_SHIFT (0x00000010u)
#define CSL_AIF2_PRI_CTRL_REG_RX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_AIF2_PRI_CTRL_REG_TX_PRIORITY_MASK (0x00000007u)
#define CSL_AIF2_PRI_CTRL_REG_TX_PRIORITY_SHIFT (0x00000000u)
#define CSL_AIF2_PRI_CTRL_REG_TX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_AIF2_PRI_CTRL_REG_RESETVAL (0x00000000u)

/* QM0_BA_REG */

#define CSL_AIF2_QM0_BA_REG_QM0_BASE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_QM0_BA_REG_QM0_BASE_SHIFT (0x00000000u)
#define CSL_AIF2_QM0_BA_REG_QM0_BASE_RESETVAL (0x34020000u)

#define CSL_AIF2_QM0_BA_REG_RESETVAL   (0x34020000u)

/* QM1_BA_REG */

#define CSL_AIF2_QM1_BA_REG_QM1_BASE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_QM1_BA_REG_QM1_BASE_SHIFT (0x00000000u)
#define CSL_AIF2_QM1_BA_REG_QM1_BASE_RESETVAL (0x00000000u)

#define CSL_AIF2_QM1_BA_REG_RESETVAL   (0x00000000u)

/* QM2_BA_REG */

#define CSL_AIF2_QM2_BA_REG_QM2_BASE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_QM2_BA_REG_QM2_BASE_SHIFT (0x00000000u)
#define CSL_AIF2_QM2_BA_REG_QM2_BASE_RESETVAL (0x00000000u)

#define CSL_AIF2_QM2_BA_REG_RESETVAL   (0x00000000u)

/* QM3_BA_REG */

#define CSL_AIF2_QM3_BA_REG_QM3_BASE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_QM3_BA_REG_QM3_BASE_SHIFT (0x00000000u)
#define CSL_AIF2_QM3_BA_REG_QM3_BASE_RESETVAL (0x00000000u)

#define CSL_AIF2_QM3_BA_REG_RESETVAL   (0x00000000u)

/* ee_at_irs */

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_IRS_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_IRS_RESETVAL    (0x00000000u)

/* ee_at_irs_set */

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_IRS_SET_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_IRS_SET_RESETVAL (0x00000000u)

/* ee_at_irs_clr */

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_IRS_CLR_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_IRS_CLR_RESETVAL (0x00000000u)

/* ee_at_en_ev0 */

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_EV0_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_EV0_RESETVAL (0x00000000u)

/* ee_at_en_set_ev0 */

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_SET_EV0_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_at_en_clr_ev0 */

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_CLR_EV0_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_at_en_ev1 */

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_EV1_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_EV1_RESETVAL (0x00000000u)

/* ee_at_en_set_ev1 */

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_SET_EV1_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_at_en_clr_ev1 */

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_CLR_EV1_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_at_en_sts_ev0 */

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_STS_EV0_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_at_en_sts_ev1 */

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_UNSEL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SPARE_ERR_MASK (0x00000010u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SPARE_ERR_SHIFT (0x00000004u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SPARE_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RSVD_ERR_MASK (0x00000020u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RSVD_ERR_SHIFT (0x00000005u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RSVD_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_BIT_WIDTH_ERR_MASK (0x00000040u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_BIT_WIDTH_ERR_SHIFT (0x00000006u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_BIT_WIDTH_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_CRC_ERR_MASK (0x00000080u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_CRC_ERR_SHIFT (0x00000007u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_RP3_ERR_MASK (0x00000100u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_RP3_ERR_SHIFT (0x00000008u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_RP3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_SYS_ERR_MASK (0x00000200u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_SYS_ERR_SHIFT (0x00000009u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_SYS_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI0_ERR_MASK (0x00000400u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI0_ERR_SHIFT (0x0000000Au)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI0_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI1_ERR_MASK (0x00000800u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI1_ERR_SHIFT (0x0000000Bu)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI1_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI2_ERR_MASK (0x00001000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI2_ERR_SHIFT (0x0000000Cu)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI2_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI3_ERR_MASK (0x00002000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI3_ERR_SHIFT (0x0000000Du)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI3_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI4_ERR_MASK (0x00004000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI4_ERR_SHIFT (0x0000000Eu)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI4_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI5_ERR_MASK (0x00008000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI5_ERR_SHIFT (0x0000000Fu)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PI5_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PHYT_SYNC_ERR_MASK (0x00010000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PHYT_SYNC_ERR_SHIFT (0x00000010u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_PHYT_SYNC_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RADT_SYNC_ERR_MASK (0x00020000u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RADT_SYNC_ERR_SHIFT (0x00000011u)
#define CSL_AIF2_EE_AT_EN_STS_EV1_AT_EE_RADT_SYNC_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_AT_EN_STS_EV1_RESETVAL (0x00000000u)

/* ee_pd_common_irs */

#define CSL_AIF2_EE_PD_COMMON_IRS_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_IRS_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_IRS_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_IRS_RESETVAL (0x00000000u)

/* ee_pd_common_irs_set */

#define CSL_AIF2_EE_PD_COMMON_IRS_SET_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_IRS_SET_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_IRS_SET_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_IRS_SET_RESETVAL (0x00000000u)

/* ee_pd_common_irs_clr */

#define CSL_AIF2_EE_PD_COMMON_IRS_CLR_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_IRS_CLR_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_IRS_CLR_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_IRS_CLR_RESETVAL (0x00000000u)

/* ee_pd_common_en_ev0 */

#define CSL_AIF2_EE_PD_COMMON_EN_EV0_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_EV0_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_EV0_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_EV0_RESETVAL (0x00000000u)

/* ee_pd_common_en_set_ev0 */

#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV0_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV0_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV0_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_pd_common_en_clr_ev0 */

#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV0_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV0_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV0_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_pd_common_en_ev1 */

#define CSL_AIF2_EE_PD_COMMON_EN_EV1_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_EV1_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_EV1_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_EV1_RESETVAL (0x00000000u)

/* ee_pd_common_en_set_ev1 */

#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV1_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV1_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV1_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_pd_common_en_clr_ev1 */

#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV1_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV1_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV1_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_pd_common_en_sts_ev0 */

#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV0_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV0_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV0_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_pd_common_en_sts_ev1 */

#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV1_PD_EE_TS_WDOG_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV1_PD_EE_TS_WDOG_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV1_PD_EE_TS_WDOG_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PD_COMMON_EN_STS_EV1_RESETVAL (0x00000000u)

/* ee_pe_common_irs */

#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_IRS_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_IRS_RESETVAL (0x00000000u)

/* ee_pe_common_irs_set */

#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_IRS_SET_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_IRS_SET_RESETVAL (0x00000000u)

/* ee_pe_common_irs_clr */

#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_IRS_CLR_RESETVAL (0x00000000u)

/* ee_pe_common_en_ev0 */

#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV0_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_EV0_RESETVAL (0x00000000u)

/* ee_pe_common_en_set_ev0 */

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV0_RESETVAL (0x00000000u)

/* ee_pe_common_en_clr_ev0 */

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV0_RESETVAL (0x00000000u)

/* ee_pe_common_en_ev1 */

#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_EV1_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_EV1_RESETVAL (0x00000000u)

/* ee_pe_common_en_set_ev1 */

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_SET_EV1_RESETVAL (0x00000000u)

/* ee_pe_common_en_clr_ev1 */

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_CLR_EV1_RESETVAL (0x00000000u)

/* ee_pe_common_en_sts_ev0 */

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV0_RESETVAL (0x00000000u)

/* ee_pe_common_en_sts_ev1 */

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_RD2DB_ERR_MASK (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_RD2DB_ERR_SHIFT (0x00000000u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_RD2DB_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_MASK (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_SHIFT (0x00000001u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_REQ_OVFL_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_WR_ERR_MASK (0x00000004u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_WR_ERR_SHIFT (0x00000002u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_WR_ERR_RESETVAL (0x00000000u)

#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_DAT_REQ_OVFL_ERR_MASK (0x00000008u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_DAT_REQ_OVFL_ERR_SHIFT (0x00000003u)
#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_DAT_REQ_OVFL_ERR_RESETVAL (0x00000000u)


#define CSL_AIF2_EE_PE_COMMON_EN_STS_EV1_RESETVAL (0x00000000u)

/* at_control1 */

#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_MASK (0x00000007u)
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_SHIFT (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_RESETVAL (0x00000000u)
/*----PHY syncsel Tokens----*/
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_RP1_PHYT_SYNC (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_PHYTSYNC (0x00000001u)
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_SW_PHYT_SYNC (0x00000002u)
#define CSL_AIF2_AT_CONTROL1_PHYSYNCSEL_RM_AT_SYNC (0x00000003u)

#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_MASK (0x00000078u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_SHIFT (0x00000003u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_RESETVAL (0x00000000u)
/*----RAD syncsel Tokens----*/
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_RP1_RADT_SYNC (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_RADTSYNC (0x00000001u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_SW_RADT_SYNC (0x00000002u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_RM_AT_SYNC (0x00000003u)
#define CSL_AIF2_AT_CONTROL1_RADSYNCSEL_PHYT_CMP_SYNC (0x00000004u)

#define CSL_AIF2_AT_CONTROL1_RP1MODE_MASK (0x00000080u)
#define CSL_AIF2_AT_CONTROL1_RP1MODE_SHIFT (0x00000007u)
#define CSL_AIF2_AT_CONTROL1_RP1MODE_RESETVAL (0x00000000u)
/*----RP1 mode Tokens----*/
#define CSL_AIF2_AT_CONTROL1_RP1MODE_RP1 (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_RP1MODE_NONRP1 (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_AUTORESYNC_MASK (0x00000100u)
#define CSL_AIF2_AT_CONTROL1_AUTORESYNC_SHIFT (0x00000008u)
#define CSL_AIF2_AT_CONTROL1_AUTORESYNC_RESETVAL (0x00000000u)
/*----Auto resync Tokens----*/
#define CSL_AIF2_AT_CONTROL1_AUTORESYNC_NORESYNC (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_AUTORESYNC_RESYNC (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_CRCUSE_MASK (0x00000200u)
#define CSL_AIF2_AT_CONTROL1_CRCUSE_SHIFT (0x00000009u)
#define CSL_AIF2_AT_CONTROL1_CRCUSE_RESETVAL (0x00000000u)
/*----CRC use Tokens----*/
#define CSL_AIF2_AT_CONTROL1_CRCUSE_DONT_USE (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_CRCUSE_USE (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_CRCFLIP_MASK (0x00000400u)
#define CSL_AIF2_AT_CONTROL1_CRCFLIP_SHIFT (0x0000000Au)
#define CSL_AIF2_AT_CONTROL1_CRCFLIP_RESETVAL (0x00000000u)
/*----CRC flip Tokens----*/
#define CSL_AIF2_AT_CONTROL1_CRCFLIP_NORMAL (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_CRCFLIP_REVERSE (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_CRCINIT_ONES_MASK (0x00000800u)
#define CSL_AIF2_AT_CONTROL1_CRCINIT_ONES_SHIFT (0x0000000Bu)
#define CSL_AIF2_AT_CONTROL1_CRCINIT_ONES_RESETVAL (0x00000000u)
/*----CRC init ones Tokens----*/
#define CSL_AIF2_AT_CONTROL1_CRCINIT_ONES_INIT0 (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_CRCINIT_ONES_INIT1 (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_CRCINVERT_MASK (0x00001000u)
#define CSL_AIF2_AT_CONTROL1_CRCINVERT_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_CONTROL1_CRCINVERT_RESETVAL (0x00000000u)
/*----CRC invert Tokens----*/
#define CSL_AIF2_AT_CONTROL1_CRCINVERT_NOINVERT (0x00000000u)
#define CSL_AIF2_AT_CONTROL1_CRCINVERT_INVERT (0x00000001u)

#define CSL_AIF2_AT_CONTROL1_SYNC_SAMPL_WINDOW_MASK (0x0001E000u)
#define CSL_AIF2_AT_CONTROL1_SYNC_SAMPL_WINDOW_SHIFT (0x0000000Du)
#define CSL_AIF2_AT_CONTROL1_SYNC_SAMPL_WINDOW_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_CONTROL1_RP1RADT_FRAME_LOAD_MASK (0x007E0000u)
#define CSL_AIF2_AT_CONTROL1_RP1RADT_FRAME_LOAD_SHIFT (0x00000011u)
#define CSL_AIF2_AT_CONTROL1_RP1RADT_FRAME_LOAD_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_CONTROL1_RP1PHYT_FRAME_LOAD_MASK (0x1F800000u)
#define CSL_AIF2_AT_CONTROL1_RP1PHYT_FRAME_LOAD_SHIFT (0x00000017u)
#define CSL_AIF2_AT_CONTROL1_RP1PHYT_FRAME_LOAD_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_CONTROL1_RESETVAL  (0x00000000u)

/* at_control2 */

#define CSL_AIF2_AT_CONTROL2_HALT_TIMER_MASK (0x00000001u)
#define CSL_AIF2_AT_CONTROL2_HALT_TIMER_SHIFT (0x00000000u)
#define CSL_AIF2_AT_CONTROL2_HALT_TIMER_RESETVAL (0x00000000u)
/*----halt_timer Tokens----*/
#define CSL_AIF2_AT_CONTROL2_HALT_TIMER_NOHALT (0x00000000u)
#define CSL_AIF2_AT_CONTROL2_HALT_TIMER_HALT (0x00000001u)

#define CSL_AIF2_AT_CONTROL2_ARM_TIMER_MASK (0x00000002u)
#define CSL_AIF2_AT_CONTROL2_ARM_TIMER_SHIFT (0x00000001u)
#define CSL_AIF2_AT_CONTROL2_ARM_TIMER_RESETVAL (0x00000000u)
/*----arm_timer Tokens----*/
#define CSL_AIF2_AT_CONTROL2_ARM_TIMER_NOARM (0x00000000u)
#define CSL_AIF2_AT_CONTROL2_ARM_TIMER_ARM (0x00000001u)


#define CSL_AIF2_AT_CONTROL2_RESETVAL  (0x00000000u)

/* at_sw_sync */

#define CSL_AIF2_AT_SW_SYNC_RAD_SYNC_MASK (0x00000001u)
#define CSL_AIF2_AT_SW_SYNC_RAD_SYNC_SHIFT (0x00000000u)
#define CSL_AIF2_AT_SW_SYNC_RAD_SYNC_RESETVAL (0x00000000u)
/*----RAD_sync Tokens----*/
#define CSL_AIF2_AT_SW_SYNC_RAD_SYNC_NOSYNC (0x00000000u)
#define CSL_AIF2_AT_SW_SYNC_RAD_SYNC_SYNC (0x00000001u)

#define CSL_AIF2_AT_SW_SYNC_PHY_SYNC_MASK (0x00000002u)
#define CSL_AIF2_AT_SW_SYNC_PHY_SYNC_SHIFT (0x00000001u)
#define CSL_AIF2_AT_SW_SYNC_PHY_SYNC_RESETVAL (0x00000000u)
/*----PHY_sync Tokens----*/
#define CSL_AIF2_AT_SW_SYNC_PHY_SYNC_NOSYNC (0x00000000u)
#define CSL_AIF2_AT_SW_SYNC_PHY_SYNC_SYNC (0x00000001u)


#define CSL_AIF2_AT_SW_SYNC_RESETVAL   (0x00000000u)

/* at_phyt_cmp_radsync */

#define CSL_AIF2_AT_PHYT_CMP_RADSYNC_RP1RAD_TYPE_SELECT_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PHYT_CMP_RADSYNC_RP1RAD_TYPE_SELECT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_CMP_RADSYNC_RP1RAD_TYPE_SELECT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_CMP_RADSYNC_RESETVAL (0x00000000u)

/* at_rp1_type */

#define CSL_AIF2_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_MASK (0x000000FFu)
#define CSL_AIF2_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RP1_TYPE_RESETVAL  (0x00000000u)

/* at_captradt */

#define CSL_AIF2_AT_CAPTRADT_RADTCLOCKCOUNT_CAPTURE_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_CAPTRADT_RADTCLOCKCOUNT_CAPTURE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_CAPTRADT_RADTCLOCKCOUNT_CAPTURE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_CAPTRADT_RADTSYMBOLCOUNT_CAPTURE_MASK (0x07F80000u)
#define CSL_AIF2_AT_CAPTRADT_RADTSYMBOLCOUNT_CAPTURE_SHIFT (0x00000013u)
#define CSL_AIF2_AT_CAPTRADT_RADTSYMBOLCOUNT_CAPTURE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_CAPTRADT_RADTFRAMECOUNT_CAPTURE_MASK (0xF8000000u)
#define CSL_AIF2_AT_CAPTRADT_RADTFRAMECOUNT_CAPTURE_SHIFT (0x0000001Bu)
#define CSL_AIF2_AT_CAPTRADT_RADTFRAMECOUNT_CAPTURE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_CAPTRADT_RESETVAL  (0x00000000u)

/* at_rp1_type_capture */

#define CSL_AIF2_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_MASK (0x000000FFu)
#define CSL_AIF2_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RP1_TYPE_CAPTURE_RESETVAL (0x00000000u)

/* at_rp1_tod_capture_l */

#define CSL_AIF2_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_TOD_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_tod_capture_h */

#define CSL_AIF2_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_TOD_CAPTURE_H_RESETVAL (0x00000000u)

/* at_rp1_rp3_capture_l */

#define CSL_AIF2_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_RP3_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_rp3_capture_h */

#define CSL_AIF2_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_RP3_CAPTURE_H_RESETVAL (0x00000000u)

/* at_rp1_rad_capture_l */

#define CSL_AIF2_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_RAD_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_rad_capture_h */

#define CSL_AIF2_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RP1_RAD_CAPTURE_H_RESETVAL (0x00000000u)

/* at_phyt_clkcnt_value */

#define CSL_AIF2_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_MASK (0x00FFFFFFu)
#define CSL_AIF2_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_CLKCNT_VALUE_RESETVAL (0x00000000u)

/* at_phyt_frm_value_lsbs */

#define CSL_AIF2_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_FRM_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_phyt_frm_value_msbs */

#define CSL_AIF2_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_FRM_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_radt_value_lsbs */

#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTCLOCK_COUNT_VALUE_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_MASK (0x07F80000u)
#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_SHIFT (0x00000013u)
#define CSL_AIF2_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_radt_value_mid */

#define CSL_AIF2_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_radt_value_msbs */

#define CSL_AIF2_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_value_lsbs */

#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTCLOCK_COUNT_VALUE_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_MASK (0x07F80000u)
#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_SHIFT (0x00000013u)
#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_ulradt_value_mid */

#define CSL_AIF2_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_ulradt_value_msbs */

#define CSL_AIF2_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_dlradt_value_lsbs */

#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_MASK (0x07F80000u)
#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_SHIFT (0x00000013u)
#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_dlradt_value_mid */

#define CSL_AIF2_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_dlradt_value_msbs */

#define CSL_AIF2_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_radt_wcdma_value */

#define CSL_AIF2_AT_RADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AIF2_AT_RADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_ulradt_wcdma_value */

#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_dlradt_wcdma_value */

#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_radt_wcdma_div */

#define CSL_AIF2_AT_RADT_WCDMA_DIV_TERMINALCOUNT_MASK (0x0000007Fu)
#define CSL_AIF2_AT_RADT_WCDMA_DIV_TERMINALCOUNT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_WCDMA_DIV_TERMINALCOUNT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_WCDMA_DIV_RESETVAL (0x00000000u)

/* at_phyt_init_lsbs */

#define CSL_AIF2_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_phyt_init_mid */

#define CSL_AIF2_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_INIT_MID_RESETVAL (0x00000000u)

/* at_phyt_init_msbs */

#define CSL_AIF2_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_phyt_tc_lsbs */

#define CSL_AIF2_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_MASK (0x003FFFFFu)
#define CSL_AIF2_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_TC_LSBS_RESETVAL (0x00000000u)

/* at_phyt_frame_tc_lsbs */

#define CSL_AIF2_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_PHYT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_phyt_frame_tc_msbs */

#define CSL_AIF2_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AIF2_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_PHYT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_radt_init_lsbs */

#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_MASK (0x07F80000u)
#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_SHIFT (0x00000013u)
#define CSL_AIF2_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_radt_init_mid */

#define CSL_AIF2_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_INIT_MID_RESETVAL (0x00000000u)

/* at_radt_init_msbs */

#define CSL_AIF2_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_init_lsbs */

#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_MASK (0x07F80000u)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_SHIFT (0x00000013u)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_MASK (0x80000000u)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_SHIFT (0x0000001Fu)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RESETVAL (0x00000000u)
/*----ULFCB_minusone Tokens----*/
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RADF (0x00000000u)
#define CSL_AIF2_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RADF_MINUS_1 (0x00000001u)

#define CSL_AIF2_AT_ULRADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_radt_tstamp_value */

#define CSL_AIF2_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_MASK (0x01FFFFFFu)
#define CSL_AIF2_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_TSTAMP_VALUE_RESETVAL (0x00000000u)

/* at_dlradt_init_lsbs */

#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_MASK (0x07F80000u)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_SHIFT (0x00000013u)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_MASK (0x80000000u)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_SHIFT (0x0000001Fu)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RESETVAL (0x00000000u)
/*----DLFCB_minusone Tokens----*/
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RADF (0x00000000u)
#define CSL_AIF2_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RADF_MINUS_1 (0x00000001u)

#define CSL_AIF2_AT_DLRADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_gsm_tcount_init */

#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T1_MASK (0x000007FFu)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T1_SHIFT (0x00000000u)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T1_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T2_MASK (0x0000F800u)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T2_SHIFT (0x0000000Bu)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T2_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T3_MASK (0x003F0000u)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T3_SHIFT (0x00000010u)
#define CSL_AIF2_AT_GSM_TCOUNT_INIT_T3_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_GSM_TCOUNT_INIT_RESETVAL (0x00000000u)

/* at_gsm_tcount_value */

#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T1_MASK (0x000007FFu)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T1_SHIFT (0x00000000u)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T1_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T2_MASK (0x0000F800u)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T2_SHIFT (0x0000000Bu)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T2_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T3_MASK (0x003F0000u)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T3_SHIFT (0x00000010u)
#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_T3_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_GSM_TCOUNT_VALUE_RESETVAL (0x00000000u)

/* at_radt_symb_lut_index_tc */

#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_MASK (0x0000007Fu)
#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_MASK (0x0000FF00u)
#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_SHIFT (0x00000008u)
#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_SYMB_LUT_INDEX_TC_RESETVAL (0x00000000u)

/* at_radt_frame_tc_lsbs */

#define CSL_AIF2_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_RADT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_radt_frame_tc_msbs */

#define CSL_AIF2_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AIF2_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_init_mid */

#define CSL_AIF2_AT_ULRADT_INIT_MID_RADTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_ULRADT_INIT_MID_RADTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_INIT_MID_RADTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_INIT_MID_RESETVAL (0x00000000u)

/* at_ulradt_init_msbs */

#define CSL_AIF2_AT_ULRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_ULRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_dlradt_init_mid */

#define CSL_AIF2_AT_DLRADT_INIT_MID_RADTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AIF2_AT_DLRADT_INIT_MID_RADTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_INIT_MID_RADTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_INIT_MID_RESETVAL (0x00000000u)

/* at_dlradt_init_msbs */

#define CSL_AIF2_AT_DLRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AIF2_AT_DLRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_INIT_MSBS_RADTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_radt_init_lut_index */

#define CSL_AIF2_AT_RADT_INIT_LUT_INDEX_LUTINDEX_INIT_MASK (0x0000007Fu)
#define CSL_AIF2_AT_RADT_INIT_LUT_INDEX_LUTINDEX_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_INIT_LUT_INDEX_LUTINDEX_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_INIT_LUT_INDEX_RESETVAL (0x00000000u)

/* at_ulradt_init_lut_index */

#define CSL_AIF2_AT_ULRADT_INIT_LUT_INDEX_LUTINDEX_INIT_MASK (0x0000007Fu)
#define CSL_AIF2_AT_ULRADT_INIT_LUT_INDEX_LUTINDEX_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_ULRADT_INIT_LUT_INDEX_LUTINDEX_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_ULRADT_INIT_LUT_INDEX_RESETVAL (0x00000000u)

/* at_dlradt_init_lut_index */

#define CSL_AIF2_AT_DLRADT_INIT_LUT_INDEX_LUTINDEX_INIT_MASK (0x0000007Fu)
#define CSL_AIF2_AT_DLRADT_INIT_LUT_INDEX_LUTINDEX_INIT_SHIFT (0x00000000u)
#define CSL_AIF2_AT_DLRADT_INIT_LUT_INDEX_LUTINDEX_INIT_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_DLRADT_INIT_LUT_INDEX_RESETVAL (0x00000000u)

/* at_neg_delta */

#define CSL_AIF2_AT_NEG_DELTA_LK0_DELTA_MASK (0x00000001u)
#define CSL_AIF2_AT_NEG_DELTA_LK0_DELTA_SHIFT (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK0_DELTA_RESETVAL (0x00000000u)
/*----lk0_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK0_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK0_DELTA_NEG (0x00000001u)

#define CSL_AIF2_AT_NEG_DELTA_LK1_DELTA_MASK (0x00000002u)
#define CSL_AIF2_AT_NEG_DELTA_LK1_DELTA_SHIFT (0x00000001u)
#define CSL_AIF2_AT_NEG_DELTA_LK1_DELTA_RESETVAL (0x00000000u)
/*----lk1_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK1_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK1_DELTA_NEG (0x00000001u)

#define CSL_AIF2_AT_NEG_DELTA_LK2_DELTA_MASK (0x00000004u)
#define CSL_AIF2_AT_NEG_DELTA_LK2_DELTA_SHIFT (0x00000002u)
#define CSL_AIF2_AT_NEG_DELTA_LK2_DELTA_RESETVAL (0x00000000u)
/*----lk2_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK2_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK2_DELTA_NEG (0x00000001u)

#define CSL_AIF2_AT_NEG_DELTA_LK3_DELTA_MASK (0x00000008u)
#define CSL_AIF2_AT_NEG_DELTA_LK3_DELTA_SHIFT (0x00000003u)
#define CSL_AIF2_AT_NEG_DELTA_LK3_DELTA_RESETVAL (0x00000000u)
/*----lk3_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK3_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK3_DELTA_NEG (0x00000001u)

#define CSL_AIF2_AT_NEG_DELTA_LK4_DELTA_MASK (0x00000010u)
#define CSL_AIF2_AT_NEG_DELTA_LK4_DELTA_SHIFT (0x00000004u)
#define CSL_AIF2_AT_NEG_DELTA_LK4_DELTA_RESETVAL (0x00000000u)
/*----lk4_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK4_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK4_DELTA_NEG (0x00000001u)

#define CSL_AIF2_AT_NEG_DELTA_LK5_DELTA_MASK (0x00000020u)
#define CSL_AIF2_AT_NEG_DELTA_LK5_DELTA_SHIFT (0x00000005u)
#define CSL_AIF2_AT_NEG_DELTA_LK5_DELTA_RESETVAL (0x00000000u)
/*----lk5_delta Tokens----*/
#define CSL_AIF2_AT_NEG_DELTA_LK5_DELTA_POS (0x00000000u)
#define CSL_AIF2_AT_NEG_DELTA_LK5_DELTA_NEG (0x00000001u)


#define CSL_AIF2_AT_NEG_DELTA_RESETVAL (0x00000000u)

/* at_evt_enable */

#define CSL_AIF2_AT_EVT_ENABLE_EVENTENABLE_MASK (0x00FFFFFFu)
#define CSL_AIF2_AT_EVT_ENABLE_EVENTENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVT_ENABLE_EVENTENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_EVT_ENABLE_RESETVAL (0x00000000u)

/* at_evt_force */

#define CSL_AIF2_AT_EVT_FORCE_EVENTFORCE_MASK (0x00FFFFFFu)
#define CSL_AIF2_AT_EVT_FORCE_EVENTFORCE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_EVT_FORCE_EVENTFORCE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_EVT_FORCE_RESETVAL (0x00000000u)

/* at_internal_evt_enable */

#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADINGR_EVENT_ENABLE_MASK (0x0000003Fu)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADINGR_EVENT_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADINGR_EVENT_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADEGR_EVENT_ENABLE_MASK (0x00000FC0u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADEGR_EVENT_ENABLE_SHIFT (0x00000006u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_ADEGR_EVENT_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_TMDELTA_EVENT_ENABLE_MASK (0x0003F000u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_TMDELTA_EVENT_ENABLE_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_TMDELTA_EVENT_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT_ENABLE_MASK (0x00FC0000u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT_ENABLE_SHIFT (0x00000012u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT_ENABLE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT2_ENABLE_MASK (0x3F000000u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT2_ENABLE_SHIFT (0x00000018u)
#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_PEEVENT2_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_INTERNAL_EVT_ENABLE_RESETVAL (0x00000000u)

/* at_internal_evt_force */

#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADINGR_EVENT_FORCE_MASK (0x0000003Fu)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADINGR_EVENT_FORCE_SHIFT (0x00000000u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADINGR_EVENT_FORCE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADEGR_EVENT_FORCE_MASK (0x00000FC0u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADEGR_EVENT_FORCE_SHIFT (0x00000006u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_ADEGR_EVENT_FORCE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_TMDELTA_EVENT_FORCE_MASK (0x0003F000u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_TMDELTA_EVENT_FORCE_SHIFT (0x0000000Cu)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_TMDELTA_EVENT_FORCE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT_FORCE_MASK (0x00FC0000u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT_FORCE_SHIFT (0x00000012u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT_FORCE_RESETVAL (0x00000000u)

#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT2_FORCE_MASK (0x3F000000u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT2_FORCE_SHIFT (0x00000018u)
#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_PEEVENT2_FORCE_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_INTERNAL_EVT_FORCE_RESETVAL (0x00000000u)

/* at_radt_sym_lut_ram */

#define CSL_AIF2_AT_RADT_SYM_LUT_RAM_RADT_CLOCK_TC_MASK (0x0007FFFFu)
#define CSL_AIF2_AT_RADT_SYM_LUT_RAM_RADT_CLOCK_TC_SHIFT (0x00000000u)
#define CSL_AIF2_AT_RADT_SYM_LUT_RAM_RADT_CLOCK_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_AT_RADT_SYM_LUT_RAM_RESETVAL (0x00000000u)

/* RM_CFG */

#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_MASK (0x00000007u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_SHIFT (0x00000000u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_RESETVAL (0x00000000u)
/*----raw_data_sel Tokens----*/
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK0 (0x00000000u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK1 (0x00000001u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK2 (0x00000002u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK3 (0x00000003u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK4 (0x00000004u)
#define CSL_AIF2_RM_CFG_RAW_DATA_SEL_LINK5 (0x00000005u)


#define CSL_AIF2_RM_CFG_SHORT_FRM_EN_MASK (0x00000100u)
#define CSL_AIF2_RM_CFG_SHORT_FRM_EN_SHIFT (0x00000008u)
#define CSL_AIF2_RM_CFG_SHORT_FRM_EN_RESETVAL (0x00000000u)
/*----short_frm_en Tokens----*/
#define CSL_AIF2_RM_CFG_SHORT_FRM_EN_LONG (0x00000000u)
#define CSL_AIF2_RM_CFG_SHORT_FRM_EN_SHORT (0x00000001u)


#define CSL_AIF2_RM_CFG_RESETVAL       (0x00000000u)

/* pd_global */

#define CSL_AIF2_PD_GLOBAL_SHRT_FRM_MODE_MASK (0x00000001u)
#define CSL_AIF2_PD_GLOBAL_SHRT_FRM_MODE_SHIFT (0x00000000u)
#define CSL_AIF2_PD_GLOBAL_SHRT_FRM_MODE_RESETVAL (0x00000000u)
/*----shrt_frm_mode Tokens----*/
#define CSL_AIF2_PD_GLOBAL_SHRT_FRM_MODE_OFF (0x00000000u)
#define CSL_AIF2_PD_GLOBAL_SHRT_FRM_MODE_ON (0x00000001u)

#define CSL_AIF2_PD_GLOBAL_DIO_CPPI_MASK (0x00000002u)
#define CSL_AIF2_PD_GLOBAL_DIO_CPPI_SHIFT (0x00000001u)
#define CSL_AIF2_PD_GLOBAL_DIO_CPPI_RESETVAL (0x00000000u)
/*----dio_cppi Tokens----*/
#define CSL_AIF2_PD_GLOBAL_DIO_CPPI_CPPI (0x00000000u)
#define CSL_AIF2_PD_GLOBAL_DIO_CPPI_DIO (0x00000001u)


#define CSL_AIF2_PD_GLOBAL_AXCOFFSET_WIN_MASK (0x0FFF0000u)
#define CSL_AIF2_PD_GLOBAL_AXCOFFSET_WIN_SHIFT (0x00000010u)
#define CSL_AIF2_PD_GLOBAL_AXCOFFSET_WIN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_GLOBAL_RESETVAL    (0x00000000u)

/* db_pd_global_en_set */

#define CSL_AIF2_DB_PD_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_PD_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_PD_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_PD_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* db_pd_global_en_clr */

#define CSL_AIF2_DB_PD_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_DB_PD_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_DB_PD_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_DB_PD_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* pd_global_en_sts */

#define CSL_AIF2_PD_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_PD_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_PD_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* pd_dma */

#define CSL_AIF2_PD_DMA_TS_WDOG_CNT_MASK (0x00000FFFu)
#define CSL_AIF2_PD_DMA_TS_WDOG_CNT_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMA_TS_WDOG_CNT_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DMA_WDOG_EOP_ADD_MASK (0x00001000u)
#define CSL_AIF2_PD_DMA_WDOG_EOP_ADD_SHIFT (0x0000000Cu)
#define CSL_AIF2_PD_DMA_WDOG_EOP_ADD_RESETVAL (0x00000000u)
/*----wdog_eop_add Tokens----*/
#define CSL_AIF2_PD_DMA_WDOG_EOP_ADD_INFO_ONLY (0x00000000u)
#define CSL_AIF2_PD_DMA_WDOG_EOP_ADD_ADD_EOP (0x00000001u)

#define CSL_AIF2_PD_DMA_WDOG_EE_CTRL_MASK (0x00002000u)
#define CSL_AIF2_PD_DMA_WDOG_EE_CTRL_SHIFT (0x0000000Du)
#define CSL_AIF2_PD_DMA_WDOG_EE_CTRL_RESETVAL (0x00000000u)
/*----wdog_ee_ctrl Tokens----*/
#define CSL_AIF2_PD_DMA_WDOG_EE_CTRL_REPORT_ALL (0x00000000u)
#define CSL_AIF2_PD_DMA_WDOG_EE_CTRL_REPORT_EOP (0x00000001u)


#define CSL_AIF2_PD_DMA_RESETVAL       (0x00000000u)

/* pd_radt_tc */

#define CSL_AIF2_PD_RADT_TC_RADT_TC_MASK (0x01FFFFFFu)
#define CSL_AIF2_PD_RADT_TC_RADT_TC_SHIFT (0x00000000u)
#define CSL_AIF2_PD_RADT_TC_RADT_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_RADT_TC_RESETVAL   (0x00000000u)

/* pd_chan_sts */

#define CSL_AIF2_PD_CHAN_STS_CHAN_ON_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_CHAN_STS_CHAN_ON_SHIFT (0x00000000u)
#define CSL_AIF2_PD_CHAN_STS_CHAN_ON_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_CHAN_STS_RESETVAL  (0x00000000u)

/* pd_pkt_sts */

#define CSL_AIF2_PD_PKT_STS_CHAN_PKT_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_PKT_STS_CHAN_PKT_SHIFT (0x00000000u)
#define CSL_AIF2_PD_PKT_STS_CHAN_PKT_RESETVAL (0x00000000u)
/*----chan_pkt Tokens----*/
#define CSL_AIF2_PD_PKT_STS_CHAN_PKT_OUT_PKT (0x00000000u)
#define CSL_AIF2_PD_PKT_STS_CHAN_PKT_IN_PKT (0x00000001u)

#define CSL_AIF2_PD_PKT_STS_RESETVAL   (0x00000000u)

/* pd_frm_tc */

#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_TC_MASK (0x000000FFu)
#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_TC_SHIFT (0x00000000u)
#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_TC_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_SC_MASK (0x0000FF00u)
#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_SC_SHIFT (0x00000008u)
#define CSL_AIF2_PD_FRM_TC_FRM_INDEX_SC_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_FRM_TC_FRM_SYM_TC_MASK (0x00FF0000u)
#define CSL_AIF2_PD_FRM_TC_FRM_SYM_TC_SHIFT (0x00000010u)
#define CSL_AIF2_PD_FRM_TC_FRM_SYM_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_FRM_TC_RESETVAL    (0x00000000u)

/* pd_route */

#define CSL_AIF2_PD_ROUTE_ROUTE_TS_MASK (0x0000003Fu)
#define CSL_AIF2_PD_ROUTE_ROUTE_TS_SHIFT (0x00000000u)
#define CSL_AIF2_PD_ROUTE_ROUTE_TS_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_ROUTE_ROUTE_TYPE_MASK (0x000007C0u)
#define CSL_AIF2_PD_ROUTE_ROUTE_TYPE_SHIFT (0x00000006u)
#define CSL_AIF2_PD_ROUTE_ROUTE_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_ROUTE_ROUTE_ADR_MASK (0x00FFF800u)
#define CSL_AIF2_PD_ROUTE_ROUTE_ADR_SHIFT (0x0000000Bu)
#define CSL_AIF2_PD_ROUTE_ROUTE_ADR_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_ROUTE_ROUTE_LK_MASK (0x07000000u)
#define CSL_AIF2_PD_ROUTE_ROUTE_LK_SHIFT (0x00000018u)
#define CSL_AIF2_PD_ROUTE_ROUTE_LK_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_MASK (0x30000000u)
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_SHIFT (0x0000001Cu)
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_RESETVAL (0x00000000u)
/*----route_mask Tokens----*/
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_NONE (0x00000000u)
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_4LSB (0x00000001u)
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_ALL (0x00000002u)
#define CSL_AIF2_PD_ROUTE_ROUTE_MASK_RESERVED (0x00000003u)


#define CSL_AIF2_PD_ROUTE_RESETVAL     (0x00000000u)

/* pd_dmachan */

#define CSL_AIF2_PD_DMACHAN_CHAN_EN_MASK (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_CHAN_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_CHAN_EN_RESETVAL (0x00000000u)
/*----chan_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_CHAN_EN_CHAN_OFF (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_CHAN_EN_CHAN_ON (0x00000001u)


#define CSL_AIF2_PD_DMACHAN_DATA_FORMAT_MASK (0x00000100u)
#define CSL_AIF2_PD_DMACHAN_DATA_FORMAT_SHIFT (0x00000008u)
#define CSL_AIF2_PD_DMACHAN_DATA_FORMAT_RESETVAL (0x00000000u)
/*----data_format Tokens----*/
#define CSL_AIF2_PD_DMACHAN_DATA_FORMAT_NORMAL (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_DATA_FORMAT_RSA (0x00000001u)


#define CSL_AIF2_PD_DMACHAN_RESETVAL   (0x00000000u)

/* pd_dmachan_a */

#define CSL_AIF2_PD_DMACHAN_A_AXC_OFFSET_MASK (0x01FFFFFFu)
#define CSL_AIF2_PD_DMACHAN_A_AXC_OFFSET_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_A_AXC_OFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_DMACHAN_A_RESETVAL (0x00000000u)

/* pd_dmachan_b */

#define CSL_AIF2_PD_DMACHAN_B_TS_WDOG_EN_MASK (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_B_TS_WDOG_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_B_TS_WDOG_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_DMACHAN_B_GSM_UL_MASK (0x00000010u)
#define CSL_AIF2_PD_DMACHAN_B_GSM_UL_SHIFT (0x00000004u)
#define CSL_AIF2_PD_DMACHAN_B_GSM_UL_RESETVAL (0x00000000u)
/*----gsm_ul Tokens----*/
#define CSL_AIF2_PD_DMACHAN_B_GSM_UL_OTHER (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_B_GSM_UL_GSM_UL (0x00000001u)

#define CSL_AIF2_PD_DMACHAN_B_FRM_GRP_MASK (0x000000E0u)
#define CSL_AIF2_PD_DMACHAN_B_FRM_GRP_SHIFT (0x00000005u)
#define CSL_AIF2_PD_DMACHAN_B_FRM_GRP_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_DMACHAN_B_DIO_OFFSET_MASK (0x0000F000u)
#define CSL_AIF2_PD_DMACHAN_B_DIO_OFFSET_SHIFT (0x0000000Cu)
#define CSL_AIF2_PD_DMACHAN_B_DIO_OFFSET_RESETVAL (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_B_TDD_EN_MASK (0xFFFF0000u)
#define CSL_AIF2_PD_DMACHAN_B_TDD_EN_SHIFT (0x00000010u)
#define CSL_AIF2_PD_DMACHAN_B_TDD_EN_RESETVAL (0x00000000u)
/*----tdd_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_B_TDD_EN_SYM_ON (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_B_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_B_RESETVAL (0x00000000u)

/* pd_dmachan_c */

#define CSL_AIF2_PD_DMACHAN_C_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DMACHAN_C_TDD_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_C_TDD_EN_RESETVAL (0x00000000u)
/*----tdd_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_C_TDD_EN_SYM_ON (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_C_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_C_RESETVAL (0x00000000u)

/* pd_dmachan_d */

#define CSL_AIF2_PD_DMACHAN_D_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DMACHAN_D_TDD_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_D_TDD_EN_RESETVAL (0x00000000u)
/*----tdd_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_D_TDD_EN_SYM_ON (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_D_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_D_RESETVAL (0x00000000u)

/* pd_dmachan_e */

#define CSL_AIF2_PD_DMACHAN_E_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DMACHAN_E_TDD_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_E_TDD_EN_RESETVAL (0x00000000u)
/*----tdd_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_E_TDD_EN_SYM_ON (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_E_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_E_RESETVAL (0x00000000u)

/* pd_dmachan_f */

#define CSL_AIF2_PD_DMACHAN_F_TDD_EN_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PD_DMACHAN_F_TDD_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PD_DMACHAN_F_TDD_EN_RESETVAL (0x00000000u)
/*----tdd_en Tokens----*/
#define CSL_AIF2_PD_DMACHAN_F_TDD_EN_SYM_ON (0x00000001u)
#define CSL_AIF2_PD_DMACHAN_F_TDD_EN_SYM_OFF (0x00000000u)

#define CSL_AIF2_PD_DMACHAN_F_RESETVAL (0x00000000u)

/* pd_frm_msg_tc */

#define CSL_AIF2_PD_FRM_MSG_TC_FRME_MSG_TC_MASK (0x0000FFFFu)
#define CSL_AIF2_PD_FRM_MSG_TC_FRME_MSG_TC_SHIFT (0x00000000u)
#define CSL_AIF2_PD_FRM_MSG_TC_FRME_MSG_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PD_FRM_MSG_TC_RESETVAL (0x00000000u)

/* pe_global */

#define CSL_AIF2_PE_GLOBAL_SHRT_FRM_MODE_MASK (0x00000001u)
#define CSL_AIF2_PE_GLOBAL_SHRT_FRM_MODE_SHIFT (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_SHRT_FRM_MODE_RESETVAL (0x00000000u)
/*----shrt_frm_mode Tokens----*/
#define CSL_AIF2_PE_GLOBAL_SHRT_FRM_MODE_OFF (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_SHRT_FRM_MODE_ON (0x00000001u)


#define CSL_AIF2_PE_GLOBAL_TOKEN_PHASE_MASK (0x00000070u)
#define CSL_AIF2_PE_GLOBAL_TOKEN_PHASE_SHIFT (0x00000004u)
#define CSL_AIF2_PE_GLOBAL_TOKEN_PHASE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_GLOBAL_ENET_HDR_SEL_MASK (0x00000100u)
#define CSL_AIF2_PE_GLOBAL_ENET_HDR_SEL_SHIFT (0x00000008u)
#define CSL_AIF2_PE_GLOBAL_ENET_HDR_SEL_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_GLOBAL_DIO_LEN_MASK (0x00001000u)
#define CSL_AIF2_PE_GLOBAL_DIO_LEN_SHIFT (0x0000000Cu)
#define CSL_AIF2_PE_GLOBAL_DIO_LEN_RESETVAL (0x00000000u)
/*----dio_len Tokens----*/
#define CSL_AIF2_PE_GLOBAL_DIO_LEN_128_BYTES (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_DIO_LEN_256_BYTES (0x00000001u)


#define CSL_AIF2_PE_GLOBAL_RESETVAL    (0x00000000u)

/* pe_global_en_set */

#define CSL_AIF2_PE_GLOBAL_EN_SET_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_GLOBAL_EN_SET_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_EN_SET_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_GLOBAL_EN_SET_RESETVAL (0x00000000u)

/* pe_global_en_clr */

#define CSL_AIF2_PE_GLOBAL_EN_CLR_DONT_CARE_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_GLOBAL_EN_CLR_DONT_CARE_SHIFT (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_EN_CLR_DONT_CARE_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_GLOBAL_EN_CLR_RESETVAL (0x00000000u)

/* pe_global_en_sts */

#define CSL_AIF2_PE_GLOBAL_EN_STS_ENABLE_MASK (0x00000001u)
#define CSL_AIF2_PE_GLOBAL_EN_STS_ENABLE_SHIFT (0x00000000u)
#define CSL_AIF2_PE_GLOBAL_EN_STS_ENABLE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_GLOBAL_EN_STS_RESETVAL (0x00000000u)

/* pe_chan_sts */

#define CSL_AIF2_PE_CHAN_STS_CHAN_ON_STS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_CHAN_STS_CHAN_ON_STS_SHIFT (0x00000000u)
#define CSL_AIF2_PE_CHAN_STS_CHAN_ON_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_CHAN_STS_RESETVAL  (0x00000000u)

/* pe_pkt_sts */

#define CSL_AIF2_PE_PKT_STS_PKT_STS_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_PKT_STS_PKT_STS_SHIFT (0x00000000u)
#define CSL_AIF2_PE_PKT_STS_PKT_STS_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_PKT_STS_RESETVAL   (0x00000000u)

/* pe_frm_tc */

#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_TC_MASK (0x0000007Fu)
#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_TC_SHIFT (0x00000000u)
#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_SC_MASK (0x00007F00u)
#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_SC_SHIFT (0x00000008u)
#define CSL_AIF2_PE_FRM_TC_FRM_INDEX_SC_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_FRM_TC_FRM_SYM_TC_MASK (0x00FF0000u)
#define CSL_AIF2_PE_FRM_TC_FRM_SYM_TC_SHIFT (0x00000010u)
#define CSL_AIF2_PE_FRM_TC_FRM_SYM_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_FRM_TC_RESETVAL    (0x00000000u)

/* pe_dmachan_en */

#define CSL_AIF2_PE_DMACHAN_EN_CH_EN_MASK (0x00000001u)
#define CSL_AIF2_PE_DMACHAN_EN_CH_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PE_DMACHAN_EN_CH_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_DMACHAN_EN_RESETVAL (0x00000000u)

/* pe_dma0chan */

#define CSL_AIF2_PE_DMA0CHAN_CRC_EN_MASK (0x00000001u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_EN_SHIFT (0x00000000u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_EN_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_DMA0CHAN_FRM_TC_MASK (0x00000070u)
#define CSL_AIF2_PE_DMA0CHAN_FRM_TC_SHIFT (0x00000004u)
#define CSL_AIF2_PE_DMA0CHAN_FRM_TC_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_MASK (0x00000180u)
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_SHIFT (0x00000007u)
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_RESETVAL (0x00000000u)
/*----rt_ctl Tokens----*/
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_ADD8 (0x00000003u)
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_ADD16 (0x00000002u)
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_INSERTPE (0x00000001u)
#define CSL_AIF2_PE_DMA0CHAN_RT_CTL_RETRANS (0x00000000u)

#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_MASK (0x00000600u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_SHIFT (0x00000009u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_RESETVAL (0x00000000u)
/*----crc_type Tokens----*/
#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_32BIT_CRC (0x00000000u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_16BIT_CRC (0x00000001u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_TYPE_8BIT_CRC (0x00000002u)


#define CSL_AIF2_PE_DMA0CHAN_ETHERNET_MASK (0x00001000u)
#define CSL_AIF2_PE_DMA0CHAN_ETHERNET_SHIFT (0x0000000Cu)
#define CSL_AIF2_PE_DMA0CHAN_ETHERNET_RESETVAL (0x00000000u)
/*----ethernet Tokens----*/
#define CSL_AIF2_PE_DMA0CHAN_ETHERNET_ENET_ON (0x00000001u)
#define CSL_AIF2_PE_DMA0CHAN_ETHERNET_ENET_OFF (0x00000000u)


#define CSL_AIF2_PE_DMA0CHAN_CRC_HDR_MASK (0x00010000u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_HDR_SHIFT (0x00000010u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_HDR_RESETVAL (0x00000000u)
/*----crc_hdr Tokens----*/
#define CSL_AIF2_PE_DMA0CHAN_CRC_HDR_CRC_HDR_ON (0x00000001u)
#define CSL_AIF2_PE_DMA0CHAN_CRC_HDR_CRC_HDR_OFF (0x00000000u)


#define CSL_AIF2_PE_DMA0CHAN_RESETVAL  (0x00000000u)

/* pe_in_fifo */

#define CSL_AIF2_PE_IN_FIFO_MF_WMARK_MASK (0x0000000Fu)
#define CSL_AIF2_PE_IN_FIFO_MF_WMARK_SHIFT (0x00000000u)
#define CSL_AIF2_PE_IN_FIFO_MF_WMARK_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_IN_FIFO_MF_FULL_LEV_MASK (0x000000F0u)
#define CSL_AIF2_PE_IN_FIFO_MF_FULL_LEV_SHIFT (0x00000004u)
#define CSL_AIF2_PE_IN_FIFO_MF_FULL_LEV_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_IN_FIFO_SYNC_SYM_MASK (0x00FF0000u)
#define CSL_AIF2_PE_IN_FIFO_SYNC_SYM_SHIFT (0x00000010u)
#define CSL_AIF2_PE_IN_FIFO_SYNC_SYM_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_IN_FIFO_RESETVAL   (0x00000000u)

/* pe_axc_offset */

#define CSL_AIF2_PE_AXC_OFFSET_AXC_OFFSET_MASK (0x01FFFFFFu)
#define CSL_AIF2_PE_AXC_OFFSET_AXC_OFFSET_SHIFT (0x00000000u)
#define CSL_AIF2_PE_AXC_OFFSET_AXC_OFFSET_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_AXC_OFFSET_RESETVAL (0x00000000u)

/* pe_frm_msg_tc */

#define CSL_AIF2_PE_FRM_MSG_TC_FRME_MSG_TC_MASK (0x0000FFFFu)
#define CSL_AIF2_PE_FRM_MSG_TC_FRME_MSG_TC_SHIFT (0x00000000u)
#define CSL_AIF2_PE_FRM_MSG_TC_FRME_MSG_TC_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_FRM_MSG_TC_RESETVAL (0x00000000u)

/* pe_modtxrule */

#define CSL_AIF2_PE_MODTXRULE_RULE_MOD_MASK (0x00000FFFu)
#define CSL_AIF2_PE_MODTXRULE_RULE_MOD_SHIFT (0x00000000u)
#define CSL_AIF2_PE_MODTXRULE_RULE_MOD_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_MODTXRULE_RULE_EN_MASK (0x00001000u)
#define CSL_AIF2_PE_MODTXRULE_RULE_EN_SHIFT (0x0000000Cu)
#define CSL_AIF2_PE_MODTXRULE_RULE_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_MODTXRULE_RULE_CTL_MSG_MASK (0x00002000u)
#define CSL_AIF2_PE_MODTXRULE_RULE_CTL_MSG_SHIFT (0x0000000Du)
#define CSL_AIF2_PE_MODTXRULE_RULE_CTL_MSG_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_MODTXRULE_RULE_INDEX_MASK (0x0FFF0000u)
#define CSL_AIF2_PE_MODTXRULE_RULE_INDEX_SHIFT (0x00000010u)
#define CSL_AIF2_PE_MODTXRULE_RULE_INDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_MODTXRULE_RULE_LK_MASK (0x70000000u)
#define CSL_AIF2_PE_MODTXRULE_RULE_LK_SHIFT (0x0000001Cu)
#define CSL_AIF2_PE_MODTXRULE_RULE_LK_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_MODTXRULE_RESETVAL (0x00000000u)

/* pe_obsai_hdr */

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_ADR_MASK (0x0000003Fu)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_ADR_SHIFT (0x00000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_ADR_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TYPE_MASK (0x000007C0u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TYPE_SHIFT (0x00000006u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TYPE_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_ADR_MASK (0x00FFF800u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_ADR_SHIFT (0x0000000Bu)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_ADR_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_MASK (0x03000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_SHIFT (0x00000018u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_RESETVAL (0x00000000u)
/*----obsai_ts_mask Tokens----*/
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_NONE (0x00000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_4LSB (0x00000001u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_ALL (0x00000002u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_MASK_RESERVED (0x00000003u)

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_MASK (0x1C000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_SHIFT (0x0000001Au)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_RESETVAL (0x00000000u)
/*----obsai_ts_frmt Tokens----*/
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_NO_TS (0x00000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_NORM_TS (0x00000001u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_GSM_UL (0x00000002u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_GEN_PKT (0x00000003u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_ETHERNET (0x00000004u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_CTR_PKT (0x00000005u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_TS_FRMT_GSM_DL (0x00000006u)

#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_PKT_MASK (0x20000000u)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_PKT_SHIFT (0x0000001Du)
#define CSL_AIF2_PE_OBSAI_HDR_OBSAI_PKT_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_OBSAI_HDR_BB_HOP_MASK (0x40000000u)
#define CSL_AIF2_PE_OBSAI_HDR_BB_HOP_SHIFT (0x0000001Eu)
#define CSL_AIF2_PE_OBSAI_HDR_BB_HOP_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_OBSAI_HDR_RESETVAL (0x00000000u)

/* pe_obsai_dbm */

#define CSL_AIF2_PE_OBSAI_DBM_DBM_X_MASK (0x0000007Fu)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_X_SHIFT (0x00000000u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_X_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_OBSAI_DBM_DBM_1MULT_MASK (0x00001F00u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_1MULT_SHIFT (0x00000008u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_1MULT_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_OBSAI_DBM_DBM_1SIZE_MASK (0x007F0000u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_1SIZE_SHIFT (0x00000010u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_1SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_OBSAI_DBM_DBM_2SIZE_MASK (0x7F000000u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_2SIZE_SHIFT (0x00000018u)
#define CSL_AIF2_PE_OBSAI_DBM_DBM_2SIZE_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_OBSAI_DBM_RESETVAL (0x00000000u)

/* pe_dbm_map */

#define CSL_AIF2_PE_DBM_MAP_DBM_BIT_MAP_MASK (0xFFFFFFFFu)
#define CSL_AIF2_PE_DBM_MAP_DBM_BIT_MAP_SHIFT (0x00000000u)
#define CSL_AIF2_PE_DBM_MAP_DBM_BIT_MAP_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_DBM_MAP_RESETVAL   (0x00000000u)

/* pe_rule_chanlut0 */

#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT0_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT0_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT0_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT0_RESETVAL (0x00000000u)

/* pe_rule_chanlut1 */

#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT1_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT1_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT1_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT1_RESETVAL (0x00000000u)

/* pe_rule_chanlut2 */

#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT2_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT2_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT2_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT2_RESETVAL (0x00000000u)

/* pe_rule_chanlut3 */

#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT3_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT3_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT3_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT3_RESETVAL (0x00000000u)

/* pe_rule_chanlut4 */

#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT4_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT4_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT4_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT4_RESETVAL (0x00000000u)

/* pe_rule_chanlut5 */

#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT5_CPRI_PKT_EN_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CPRI_PKT_EN_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CPRI_PKT_EN_RESETVAL (0x00000000u)
/*----cpri_pkt_en Tokens----*/
#define CSL_AIF2_PE_RULE_CHANLUT5_CPRI_PKT_EN_CPRI_AXC (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT5_CPRI_PKT_EN_CPRI_PKT (0x00000001u)


#define CSL_AIF2_PE_RULE_CHANLUT5_RESETVAL (0x00000000u)

/* pe_rule_chanlut6 */

#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT6_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT6_UNUSED_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT6_UNUSED_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT6_UNUSED_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_RULE_CHANLUT6_RESETVAL (0x00000000u)

/* pe_rule_chanlut7 */

#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_MASK (0x0000007Fu)
#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_SHIFT (0x00000000u)
#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_EN_MASK (0x00000080u)
#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_EN_SHIFT (0x00000007u)
#define CSL_AIF2_PE_RULE_CHANLUT7_CHANINDEX_EN_RESETVAL (0x00000000u)

#define CSL_AIF2_PE_RULE_CHANLUT7_UNUSED_MASK (0x00000100u)
#define CSL_AIF2_PE_RULE_CHANLUT7_UNUSED_SHIFT (0x00000008u)
#define CSL_AIF2_PE_RULE_CHANLUT7_UNUSED_RESETVAL (0x00000000u)


#define CSL_AIF2_PE_RULE_CHANLUT7_RESETVAL (0x00000000u)

#endif
