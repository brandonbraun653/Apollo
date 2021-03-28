/********************************************************************
 * Copyright (C) 2018-2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_cpsw9.h
*/
#ifndef CSLR_CPSW9_H_
#define CSLR_CPSW9_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t SGMII_IDVER_REG;           /* idver_reg */
    volatile uint32_t SOFT_RESET_REG;            /* soft_reset_reg */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t STATUS_REG;                /* status_reg */
    volatile uint32_t MR_ADV_ABILITY_REG;        /* mr_adv_ability_reg */
    volatile uint32_t MR_NP_TX_REG;              /* mr_np_tx_reg */
    volatile uint32_t MR_LP_ADV_ABILITY_REG;     /* mr_lp_adv_ability_reg */
    volatile uint32_t MR_LP_NP_RX_REG;           /* mr_lp_np_rx_reg */
    volatile uint8_t  Resv_64[24];
    volatile uint32_t DIAG_CLEAR_REG;            /* diag_clear_reg */
    volatile uint32_t DIAG_CONTROL_REG;          /* diag_control_reg */
    volatile uint32_t DIAG_STATUS_REG;           /* diag_status_reg */
    volatile uint8_t  Resv_256[180];
} CSL_cpsw9Regs_CPSGMII;


typedef struct {
    volatile uint32_t USER_ACCESS_REG;           /* user_access_reg */
    volatile uint32_t USER_PHY_SEL_REG;          /* user_phy_sel_reg */
} CSL_cpsw9Regs_MDIO_USER_GROUP;


typedef struct {
    volatile uint32_t MDIO_VERSION_REG;          /* version_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t ALIVE_REG;                 /* alive_reg */
    volatile uint32_t LINK_REG;                  /* link_reg */
    volatile uint32_t LINK_INT_RAW_REG;          /* link_int_raw_reg */
    volatile uint32_t LINK_INT_MASKED_REG;       /* link_int_masked_reg */
    volatile uint32_t LINK_INT_MASK_SET_REG;     /* link_int_mask_set_reg */
    volatile uint32_t LINK_INT_MASK_CLEAR_REG;   /* link_int_mask_clear_reg */
    volatile uint32_t USER_INT_RAW_REG;          /* user_int_raw_reg */
    volatile uint32_t USER_INT_MASKED_REG;       /* user_int_masked_reg */
    volatile uint32_t USER_INT_MASK_SET_REG;     /* user_int_mask_set_reg */
    volatile uint32_t USER_INT_MASK_CLEAR_REG;   /* user_int_mask_clear_reg */
    volatile uint32_t MANUAL_IF_REG;             /* manual_if_reg */
    volatile uint32_t POLL_REG;                  /* poll_reg */
    volatile uint32_t POLL_EN_REG;               /* poll_reg */
    volatile uint32_t CLAUS45_REG;               /* poll_reg */
    volatile uint32_t USER_ADDR0_REG;            /* poll_reg */
    volatile uint32_t USER_ADDR1_REG;            /* poll_reg */
    volatile uint8_t  Resv_128[56];
    CSL_cpsw9Regs_MDIO_USER_GROUP USER_GROUP[2];
} CSL_cpsw9Regs_MDIO;


typedef struct {
    volatile uint32_t REVISION;
    volatile uint8_t  Resv_16[12];
    volatile uint32_t EOI_REG;
    volatile uint32_t INTR_VECTOR_REG;
    volatile uint8_t  Resv_256[232];
    volatile uint32_t ENABLE_REG_OUT_PULSE_0;
    volatile uint8_t  Resv_768[508];
    volatile uint32_t ENABLE_CLR_REG_OUT_PULSE_0;
    volatile uint8_t  Resv_1280[508];
    volatile uint32_t STATUS_REG_OUT_PULSE_0;
    volatile uint8_t  Resv_2688[1404];
    volatile uint32_t INTR_VECTOR_REG_OUT_PULSE;
} CSL_cpsw9Regs_INTD;


typedef struct {
    volatile uint32_t PCSR_TX_CTL_REG;           /* PCSR Transmit Control Register */
    volatile uint32_t PCSR_TX_STATUS_REG;        /* PCSR Transmit Status Register */
    volatile uint32_t PCSR_RX_CTL_REG;           /* PCSR Receive Control Register */
    volatile uint32_t PCSR_RX_STATUS_REG;        /* PCSR Receive Status Register */
    volatile uint32_t PCSR_SEED_A_LO_REG;        /* PCSR Seed A Low Register */
    volatile uint32_t PCSR_SEED_A_HI_REG;        /* PCSR SEED A High Register */
    volatile uint32_t PCSR_SEED_B_LO_REG;        /* PCSR Seed B Low Register */
    volatile uint32_t PCSR_SEED_B_HI_REG;        /* PCSR SEED B High Register */
    volatile uint32_t PCSR_FEC_REG;              /* PCSR FEC Register */
    volatile uint32_t PCSR_CTL_REG;              /* PCSR CTL Register */
    volatile uint32_t PCSR_FEC_CNT_REG;          /* PCSR FEC Count Register */
    volatile uint32_t PCSR_ERROR_FIFO_REG;       /* PCSR Error FIFO Register */
    volatile uint8_t  Resv_256[208];
} CSL_cpsw9Regs_PCSR;


typedef struct {
    volatile uint8_t  Resv_4[4];
    volatile uint32_t P0_CONTROL_REG;            /* p0_control_reg */
    volatile uint32_t P0_FLOW_ID_OFFSET_REG;     /* p0_flow_id_offset_reg */
    volatile uint8_t  Resv_16[4];
    volatile uint32_t P0_BLK_CNT_REG;            /* p0_blk_cnt_reg */
    volatile uint32_t P0_PORT_VLAN_REG;          /* p0_port_vlan_reg */
    volatile uint32_t P0_TX_PRI_MAP_REG;         /* p0_tx_pri_map_reg */
    volatile uint32_t P0_PRI_CTL_REG;            /* p0_pri_ctl_reg */
    volatile uint32_t P0_RX_PRI_MAP_REG;         /* p0_rx_pri_map_reg */
    volatile uint32_t P0_RX_MAXLEN_REG;          /* p0_rx_maxlen_reg */
    volatile uint32_t P0_TX_BLKS_PRI_REG;        /* p0_tx_blks_pri_reg */
    volatile uint8_t  Resv_48[4];
    volatile uint32_t P0_IDLE2LPI_REG;           /* p0_idle2lpi_reg */
    volatile uint32_t P0_LPI2WAKE_REG;           /* p0_lpi2wake_reg */
    volatile uint32_t P0_EEE_STATUS_REG;         /* p0_eee_status_reg */
    volatile uint8_t  Resv_80[20];
    volatile uint32_t P0_FIFO_STATUS_REG;        /* p0_fifo_status_reg */
    volatile uint8_t  Resv_288[204];
    volatile uint32_t P0_RX_DSCP_MAP_REG[8];     /* p0_rx_dscp_map_reg */
    volatile uint32_t P0_PRI_CIR_REG[8];         /* p0_pri_cir_reg */
    volatile uint32_t P0_PRI_EIR_REG[8];         /* p0_pri_eir_reg */
    volatile uint32_t P0_TX_D_THRESH_SET_L_REG;   /* p0_tx_d_thresh_set_l_reg */
    volatile uint32_t P0_TX_D_THRESH_SET_H_REG;   /* p0_tx_d_thresh_set_h_reg */
    volatile uint32_t P0_TX_D_THRESH_CLR_L_REG;   /* p0_tx_d_thresh_clr_l_reg */
    volatile uint32_t P0_TX_D_THRESH_CLR_H_REG;   /* p0_tx_d_thresh_clr_h_reg */
    volatile uint32_t P0_TX_G_BUF_THRESH_SET_L_REG;   /* p0_tx_g_buf_thresh_set_l_reg */
    volatile uint32_t P0_TX_G_BUF_THRESH_SET_H_REG;   /* p0_tx_g_buf_thresh_set_h_reg */
    volatile uint32_t P0_TX_G_BUF_THRESH_CLR_L_REG;   /* p0_tx_g_buf_thresh_clr_l_reg */
    volatile uint32_t P0_TX_G_BUF_THRESH_CLR_H_REG;   /* p0_tx_g_buf_thresh_clr_h_reg */
    volatile uint8_t  Resv_768[352];
    volatile uint32_t P0_SRC_ID_A_REG;           /* p0_src_id_a_reg */
    volatile uint32_t P0_SRC_ID_B_REG;           /* p0_src_id_b_reg */
    volatile uint8_t  Resv_800[24];
    volatile uint32_t P0_HOST_BLKS_PRI_REG;      /* p0_host_blks_pri_reg */
} CSL_cpsw9Regs_CPSW_NU_CPSW_NU_CPPI;


typedef struct {
    volatile uint32_t PN_RESERVED_REG;           /* pn_reserved_reg */
    volatile uint32_t PN_CONTROL_REG;            /* pn_control_reg */
    volatile uint32_t PN_MAX_BLKS_REG;           /* pn_max_blks_reg */
    volatile uint8_t  Resv_16[4];
    volatile uint32_t PN_BLK_CNT_REG;            /* pn_blk_cnt_reg */
    volatile uint32_t PN_PORT_VLAN_REG;          /* pn_port_vlan_reg */
    volatile uint32_t PN_TX_PRI_MAP_REG;         /* pn_tx_pri_map_reg */
    volatile uint32_t PN_PRI_CTL_REG;            /* pn_pri_ctl_reg */
    volatile uint32_t PN_RX_PRI_MAP_REG;         /* pn_rx_pri_map_reg */
    volatile uint32_t PN_RX_MAXLEN_REG;          /* pn_rx_maxlen_reg */
    volatile uint32_t PN_TX_BLKS_PRI_REG;        /* pn_tx_blks_pri_reg */
    volatile uint8_t  Resv_48[4];
    volatile uint32_t PN_IDLE2LPI_REG;           /* pn_idle2lpi_reg */
    volatile uint32_t PN_LPI2WAKE_REG;           /* pn_lpi2wake_reg */
    volatile uint32_t PN_EEE_STATUS_REG;         /* pn_eee_status_reg */
    volatile uint8_t  Resv_64[4];
    volatile uint32_t PN_IET_CONTROL_REG;        /* pn_iet_control_reg */
    volatile uint32_t PN_IET_STATUS_REG;         /* pn_iet_status_reg */
    volatile uint32_t PN_IET_VERIFY_REG;         /* pn_iet_verify_reg */
    volatile uint8_t  Resv_80[4];
    volatile uint32_t PN_FIFO_STATUS_REG;        /* pn_fifo_status_reg */
    volatile uint8_t  Resv_96[12];
    volatile uint32_t PN_EST_CONTROL_REG;        /* pn_est_control_reg */
    volatile uint8_t  Resv_288[188];
    volatile uint32_t PN_RX_DSCP_MAP_REG[8];     /* pn_rx_dscp_map_reg */
    volatile uint32_t PN_PRI_CIR_REG[8];         /* pn_pri_send_reg */
    volatile uint32_t PN_PRI_EIR_REG[8];         /* pn_pri_idle_reg */
    volatile uint32_t PN_TX_D_THRESH_SET_L_REG;   /* pn_tx_d_thresh_set_l_reg */
    volatile uint32_t PN_TX_D_THRESH_SET_H_REG;   /* pn_tx_d_thresh_set_h_reg */
    volatile uint32_t PN_TX_D_THRESH_CLR_L_REG;   /* pn_tx_d_thresh_clr_l_reg */
    volatile uint32_t PN_TX_D_THRESH_CLR_H_REG;   /* pn_tx_d_thresh_clr_h_reg */
    volatile uint32_t PN_TX_G_BUF_THRESH_SET_L_REG;   /* pn_tx_g_buf_thresh_set_l_reg */
    volatile uint32_t PN_TX_G_BUF_THRESH_SET_H_REG;   /* pn_tx_g_buf_thresh_set_h_reg */
    volatile uint32_t PN_TX_G_BUF_THRESH_CLR_L_REG;   /* pn_tx_g_buf_thresh_clr_l_reg */
    volatile uint32_t PN_TX_G_BUF_THRESH_CLR_H_REG;   /* pn_tx_g_buf_thresh_clr_h_reg */
    volatile uint8_t  Resv_768[352];
    volatile uint32_t PN_TX_D_OFLOW_ADDVAL_L_REG;   /* pn_tx_d_oflow_addval_l_reg */
    volatile uint32_t PN_TX_D_OFLOW_ADDVAL_H_REG;   /* pn_tx_d_oflow_addval_h_reg */
    volatile uint32_t PN_SA_L_REG;               /* pn_sa_l_reg */
    volatile uint32_t PN_SA_H_REG;               /* pn_sa_h_reg */
    volatile uint32_t PN_TS_CTL_REG;             /* pn_ts_ctl_reg */
    volatile uint32_t PN_TS_SEQ_LTYPE_REG;       /* pn_ts_seq_ltype_reg */
    volatile uint32_t PN_TS_VLAN_LTYPE_REG;      /* pn_ts_vlan_ltype_reg */
    volatile uint32_t PN_TS_CTL_LTYPE2_REG;      /* pn_ts_ctl_ltype2_reg */
    volatile uint32_t PN_TS_CTL2_REG;            /* pn_ts_ctl2_reg */
    volatile uint8_t  Resv_816[12];
    volatile uint32_t PN_MAC_CONTROL_REG;        /* pn_mac_control_reg */
    volatile uint32_t PN_MAC_STATUS_REG;         /* pn_mac_status_reg */
    volatile uint32_t PN_MAC_SOFT_RESET_REG;     /* pn_mac_soft_reset_reg */
    volatile uint32_t PN_MAC_BOFFTEST_REG;       /* pn_mac_bofftest_reg */
    volatile uint32_t PN_MAC_RX_PAUSETIMER_REG;   /* pn_mac_rx_pausetimer_reg */
    volatile uint8_t  Resv_848[12];
    volatile uint32_t PN_MAC_RXN_PAUSETIMER_REG[8];   /* pn_mac_rxn_pausetimer_reg */
    volatile uint32_t PN_MAC_TX_PAUSETIMER_REG;   /* pn_mac_tx_pausetimer_reg */
    volatile uint8_t  Resv_896[12];
    volatile uint32_t PN_MAC_TXN_PAUSETIMER_REG[8];   /* pn_mac_txn_pausetimer_reg */
    volatile uint32_t PN_MAC_EMCONTROL_REG;      /* pn_mac_emcontrol_reg */
    volatile uint32_t PN_MAC_TX_GAP_REG;         /* pn_mac_tx_gap_reg */
    volatile uint8_t  Resv_940[4];
    volatile uint32_t PN_INTERVLAN_OPX_POINTER_REG;   /* pn_opx_pointer_reg */
    volatile uint32_t PN_INTERVLAN_OPX_A_REG;    /* pn_opx_a_reg */
    volatile uint32_t PN_INTERVLAN_OPX_B_REG;    /* pn_opx_b_reg */
    volatile uint32_t PN_INTERVLAN_OPX_C_REG;    /* pn_opx_c_reg */
    volatile uint32_t PN_INTERVLAN_OPX_D_REG;    /* pn_opx_d_reg */
    volatile uint8_t  Resv_4096[3136];
} CSL_cpsw9Regs_CPSW_NU_CPSW_NU_ETH_MAC;


typedef struct {
    volatile uint32_t FETCH_LOC[1024];           /* Revision Register */
} CSL_cpsw9Regs_CPSW_NU_CPSW_NU_EST;


typedef struct {
    volatile uint32_t RXGOODFRAMES;              /* RxGoodFrames */
    volatile uint32_t RXBROADCASTFRAMES;         /* RxBroadcastFrames */
    volatile uint32_t RXMULTICASTFRAMES;         /* RxMulticastFrames */
    volatile uint32_t RXPAUSEFRAMES;             /* RxPauseFrames */
    volatile uint32_t RXCRCERRORS;               /* RxCRCErrors */
    volatile uint32_t RXALIGNCODEERRORS;         /* RxAlignCodeErrors */
    volatile uint32_t RXOVERSIZEDFRAMES;         /* RxOversizedFrames */
    volatile uint32_t RXJABBERFRAMES;            /* RxJabberFrames */
    volatile uint32_t RXUNDERSIZEDFRAMES;        /* RxUndersizedFrames */
    volatile uint32_t RXFRAGMENTS;               /* RxFragments */
    volatile uint32_t ALE_DROP;                  /* ALE_Drop */
    volatile uint32_t ALE_OVERRUN_DROP;          /* ALE_Overrun_Drop */
    volatile uint32_t RXOCTETS;                  /* RxOctets */
    volatile uint32_t TXGOODFRAMES;              /* TxGoodFrames */
    volatile uint32_t TXBROADCASTFRAMES;         /* TxBroadcastFrames */
    volatile uint32_t TXMULTICASTFRAMES;         /* TxMulticastFrames */
    volatile uint32_t TXPAUSEFRAMES;             /* TxPauseFrames */
    volatile uint32_t TXDEFERREDFRAMES;          /* TxDeferredFrames */
    volatile uint32_t TXCOLLISIONFRAMES;         /* TxCollisionFrames */
    volatile uint32_t TXSINGLECOLLFRAMES;        /* TxSingleCollFrames */
    volatile uint32_t TXMULTCOLLFRAMES;          /* TxMultCollFrames */
    volatile uint32_t TXEXCESSIVECOLLISIONS;     /* TxExcessiveCollisions */
    volatile uint32_t TXLATECOLLISIONS;          /* TxLateCollisions */
    volatile uint32_t RXIPGERROR;                /* RxIPGError */
    volatile uint32_t TXCARRIERSENSEERRORS;      /* TxCarrierSenseErrors */
    volatile uint32_t TXOCTETS;                  /* TxOctets */
    volatile uint32_t OCTETFRAMES64;             /* OctetFrames64 */
    volatile uint32_t OCTETFRAMES65T127;         /* OctetFrames65t127 */
    volatile uint32_t OCTETFRAMES128T255;        /* OctetFrames128t255 */
    volatile uint32_t OCTETFRAMES256T511;        /* OctetFrames256t511 */
    volatile uint32_t OCTETFRAMES512T1023;       /* OctetFrames512t1023 */
    volatile uint32_t OCTETFRAMES1024TUP;        /* OctetFrames1024tUP */
    volatile uint32_t NETOCTETS;                 /* NetOctets */
    volatile uint32_t RX_BOTTOM_OF_FIFO_DROP;    /* Rx_Bottom_of_FIFO_Drop */
    volatile uint32_t PORTMASK_DROP;             /* Portmask_Drop */
    volatile uint32_t RX_TOP_OF_FIFO_DROP;       /* Rx_Top_of_FIFO_Drop */
    volatile uint32_t ALE_RATE_LIMIT_DROP;       /* ALE_Rate_Limit_Drop */
    volatile uint32_t ALE_VID_INGRESS_DROP;      /* ALE_VID_Ingress_Drop */
    volatile uint32_t ALE_DA_EQ_SA_DROP;         /* ALE_DA_EQ_SA_Drop */
    volatile uint32_t ALE_BLOCK_DROP;            /* ALE_Block_Drop */
    volatile uint32_t ALE_SECURE_DROP;           /* ALE_Secure_Drop */
    volatile uint32_t ALE_AUTH_DROP;             /* ALE_Auth_Drop */
    volatile uint32_t ALE_UNKN_UNI;              /* ALE_Unkn_Uni */
    volatile uint32_t ALE_UNKN_UNI_BCNT;         /* ALE_Unkn_Uni_Bcnt */
    volatile uint32_t ALE_UNKN_MLT;              /* ALE_Unkn_Mlt */
    volatile uint32_t ALE_UNKN_MLT_BCNT;         /* ALE_Unkn_Mlt_Bcnt */
    volatile uint32_t ALE_UNKN_BRD;              /* ALE_Unkn_Brd */
    volatile uint32_t ALE_UNKN_BRD_BCNT;         /* ALE_Unkn_Brd_Bcnt */
    volatile uint32_t ALE_POL_MATCH;             /* ALE_Pol_Match */
    volatile uint32_t ALE_POL_MATCH_RED;         /* ALE_Pol_Match_Red */
    volatile uint32_t ALE_POL_MATCH_YELLOW;      /* ALE_Pol_Match_Yellow */
    volatile uint32_t ALE_MULT_SA_DROP;          /* ALE_MULT_SA_DROP */
    volatile uint32_t ALE_DUAL_VLAN_DROP;        /* ALE_DUAL_VLAN_DROP */
    volatile uint32_t ALE_LEN_ERROR_DROP;        /* ALE_LEN_ERROR_DROP */
    volatile uint32_t ALE_IP_NEXT_HDR_DROP;      /* ALE_IP_NEXT_HDR_DROP */
    volatile uint32_t ALE_IPV4_FRAG_DROP;        /* ALE_IPV4_FRAG_DROP */
    volatile uint8_t  Resv_320[96];
    volatile uint32_t IET_RX_ASSEMBLY_ERROR_REG;   /* iet_rx_assembly_error */
    volatile uint32_t IET_RX_ASSEMBLY_OK_REG;    /* iet_rx_assembly_ok */
    volatile uint32_t IET_RX_SMD_ERROR_REG;      /* iet_rx_smd_error */
    volatile uint32_t IET_RX_FRAG_REG;           /* iet_rx_frag */
    volatile uint32_t IET_TX_HOLD_REG;           /* iet_tx_hold */
    volatile uint32_t IET_TX_FRAG_REG;           /* iet_tx_frag */
    volatile uint8_t  Resv_380[36];
    volatile uint32_t TX_MEMORY_PROTECT_ERROR;   /* Tx_Memory_Protect_Error */
    volatile uint32_t ENET_PN_TX_PRI_REG[8];     /* enet_pn_tx_pri */
    volatile uint32_t ENET_PN_TX_PRI_BCNT_REG[8];   /* enet_pn_tx_pri_bcnt */
    volatile uint32_t ENET_PN_TX_PRI_DROP_REG[8];   /* enet_pn_tx_pri_drop */
    volatile uint32_t ENET_PN_TX_PRI_DROP_BCNT_REG[8];   /* enet_pn_tx_pri_drop_bcnt */
} CSL_cpsw9Regs_CPSW_NU_CPSW_NU_STAT;


typedef struct {
    volatile uint32_t COMP_LOW_REG;              /* comp_low_reg */
    volatile uint32_t COMP_HIGH_REG;             /* comp_high_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t LENGTH_REG;                /* length_reg */
    volatile uint32_t PPM_LOW_REG;               /* ppm_low_reg */
    volatile uint32_t PPM_HIGH_REG;              /* ppm_high_reg */
    volatile uint32_t NUDGE_REG;                 /* nudge_reg */
    volatile uint8_t  Resv_32[4];
} CSL_cpsw9Regs_CPSW_NU_CPTS_TS_GENF;


typedef struct {
    volatile uint32_t COMP_LOW_REG;              /* comp_low_reg */
    volatile uint32_t COMP_HIGH_REG;             /* comp_high_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t LENGTH_REG;                /* length_reg */
    volatile uint32_t PPM_LOW_REG;               /* ppm_low_reg */
    volatile uint32_t PPM_HIGH_REG;              /* ppm_high_reg */
    volatile uint32_t NUDGE_REG;                 /* nudge_reg */
    volatile uint8_t  Resv_32[4];
} CSL_cpsw9Regs_CPSW_NU_CPTS_TS_ESTF;


typedef struct {
    volatile uint32_t IDVER_REG;                 /* idver_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t RFTCLK_SEL_REG;            /* rftclk_sel_reg */
    volatile uint32_t TS_PUSH_REG;               /* ts_push_reg */
    volatile uint32_t TS_LOAD_VAL_REG;           /* ts_load_low_val_reg */
    volatile uint32_t TS_LOAD_EN_REG;            /* ts_load_en_reg */
    volatile uint32_t TS_COMP_VAL_REG;           /* ts_comp_low_val_reg */
    volatile uint32_t TS_COMP_LEN_REG;           /* ts_comp_len_reg */
    volatile uint32_t INTSTAT_RAW_REG;           /* intstat_raw_reg */
    volatile uint32_t INTSTAT_MASKED_REG;        /* intstat_masked_reg */
    volatile uint32_t INT_ENABLE_REG;            /* int_enable_reg */
    volatile uint32_t TS_COMP_NUDGE_REG;         /* ts_comp_nudge_reg */
    volatile uint32_t EVENT_POP_REG;             /* event_pop_reg */
    volatile uint32_t EVENT_0_REG;               /* event_0_reg */
    volatile uint32_t EVENT_1_REG;               /* event_1_reg */
    volatile uint32_t EVENT_2_REG;               /* event_2_reg */
    volatile uint32_t EVENT_3_REG;               /* event_3_reg */
    volatile uint32_t TS_LOAD_HIGH_VAL_REG;      /* ts_load_high_val_reg */
    volatile uint32_t TS_COMP_HIGH_VAL_REG;      /* ts_comp_high_val_reg */
    volatile uint32_t TS_ADD_VAL_REG;            /* ts_add_val */
    volatile uint32_t TS_PPM_LOW_VAL_REG;        /* ts_ppm_low_val_reg */
    volatile uint32_t TS_PPM_HIGH_VAL_REG;       /* ts_ppm_high_val_reg */
    volatile uint32_t TS_NUDGE_VAL_REG;          /* ts_nudge_val_reg */
    volatile uint8_t  Resv_224[132];
    CSL_cpsw9Regs_CPSW_NU_CPTS_TS_GENF TS_GENF[2];
    volatile uint8_t  Resv_512[224];
    CSL_cpsw9Regs_CPSW_NU_CPTS_TS_ESTF TS_ESTF[8];
} CSL_cpsw9Regs_CPSW_NU_CPTS;


typedef struct {
    volatile uint32_t MOD_VER;                   /* Module and Version */
    volatile uint32_t ALE_STATUS;                /* ALE Status */
    volatile uint32_t ALE_CONTROL;               /* ALE Control */
    volatile uint32_t ALE_CTRL2;                 /* ALE Control 2 */
    volatile uint32_t ALE_PRESCALE;              /* ALE Prescale */
    volatile uint32_t ALE_AGING_CTRL;            /* ALE Aging Control */
    volatile uint8_t  Resv_28[4];
    volatile uint32_t ALE_NXT_HDR;               /* ALE Next Header */
    volatile uint32_t ALE_TBLCTL;                /* ALE Table Control */
    volatile uint8_t  Resv_52[16];
    volatile uint32_t ALE_TBLW2;                 /* ALE LUT Table word 2 */
    volatile uint32_t ALE_TBLW1;                 /* ALE LUT Table word 1 */
    volatile uint32_t ALE_TBLW0;                 /* ALE LUT Table word 0 */
    volatile uint32_t I0_ALE_PORTCTL0[9];        /* ALE Port Control X */
    volatile uint8_t  Resv_144[44];
    volatile uint32_t ALE_UVLAN_MEMBER;          /* ALE Unknown VLAN Member Mask Register */
    volatile uint32_t ALE_UVLAN_URCAST;          /* ALE Unknown VLAN Unregistered Multicast Flood Mask Register */
    volatile uint32_t ALE_UVLAN_RMCAST;          /* ALE Unknown VLAN Registered Multicast Flood Mask Register */
    volatile uint32_t ALE_UVLAN_UNTAG;           /* ALE Unknown VLAN force Untagged Egress Mask Register */
    volatile uint8_t  Resv_184[24];
    volatile uint32_t ALE_STAT_DIAG;             /* ALE Statistic Output Diagnostic Register */
    volatile uint32_t ALE_OAM_LB_CTRL;           /* ALE OAM Loopback Control */
    volatile uint8_t  Resv_252[60];
    volatile uint32_t EGRESSOP;                  /* Egress Operation */
    volatile uint32_t POLICECFG0;                /* Policing Config 0 */
    volatile uint32_t POLICECFG1;                /* Policing Config 1 */
    volatile uint32_t POLICECFG2;                /* Policing Config 2 */
    volatile uint32_t POLICECFG3;                /* Policing Config 3 */
    volatile uint32_t POLICECFG4;                /* Policing Config 4 */
    volatile uint8_t  Resv_280[4];
    volatile uint32_t POLICECFG6;                /* Policing Config 6 */
    volatile uint32_t POLICECFG7;                /* Policing Config 7 */
    volatile uint32_t POLICETBLCTL;              /* Policing Table Control */
    volatile uint32_t POLICECONTROL;             /* Policing Control */
    volatile uint32_t POLICETESTCTL;             /* Policing Test Control */
    volatile uint32_t POLICEHSTAT;               /* Policing Hit Status */
    volatile uint8_t  Resv_308[4];
    volatile uint32_t THREADMAPDEF;              /* THREAD Mapping Default Value */
    volatile uint32_t THREADMAPCTL;              /* THREAD Mapping Control */
    volatile uint32_t THREADMAPVAL;              /* THREAD Mapping Value */
} CSL_cpsw9Regs_CPSW_NU_ALE;


typedef struct {
    volatile uint32_t CPSW_ID_VER_REG;           /* idver_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t EM_CONTROL_REG;            /* em_control_reg */
    volatile uint32_t STAT_PORT_EN_REG;          /* stat_port_en_reg */
    volatile uint32_t PTYPE_REG;                 /* ptype_reg */
    volatile uint32_t SOFT_IDLE_REG;             /* soft_idle_reg */
    volatile uint32_t THRU_RATE_REG;             /* thru_rate_reg */
    volatile uint32_t GAP_THRESH_REG;            /* gap_thresh_reg */
    volatile uint32_t TX_START_WDS_REG;          /* tx_start_wds_reg */
    volatile uint32_t EEE_PRESCALE_REG;          /* eee_prescale_reg */
    volatile uint32_t TX_G_OFLOW_THRESH_SET_REG;   /* tx_g_oflow_thresh_set_reg */
    volatile uint32_t TX_G_OFLOW_THRESH_CLR_REG;   /* tx_g_oflow_thresh_clr_reg */
    volatile uint32_t TX_G_BUF_THRESH_SET_L_REG;   /* tx_g_buf_thresh_set_l_reg */
    volatile uint32_t TX_G_BUF_THRESH_SET_H_REG;   /* tx_g_buf_thresh_set_h_reg */
    volatile uint32_t TX_G_BUF_THRESH_CLR_L_REG;   /* tx_g_buf_thresh_clr_l_reg */
    volatile uint32_t TX_G_BUF_THRESH_CLR_H_REG;   /* tx_g_buf_thresh_clr_h_reg */
    volatile uint8_t  Resv_80[8];
    volatile uint32_t VLAN_LTYPE_REG;            /* vlan_ltype_reg */
    volatile uint32_t EST_TS_DOMAIN_REG;         /* est_ts_domain_reg */
    volatile uint8_t  Resv_256[168];
    volatile uint32_t TX_PRI0_MAXLEN_REG;        /* tx_pri0_maxlen_reg */
    volatile uint32_t TX_PRI1_MAXLEN_REG;        /* tx_pri1_maxlen_reg */
    volatile uint32_t TX_PRI2_MAXLEN_REG;        /* tx_pri2_maxlen_reg */
    volatile uint32_t TX_PRI3_MAXLEN_REG;        /* tx_pri3_maxlen_reg */
    volatile uint32_t TX_PRI4_MAXLEN_REG;        /* tx_pri4_maxlen_reg */
    volatile uint32_t TX_PRI5_MAXLEN_REG;        /* tx_pri5_maxlen_reg */
    volatile uint32_t TX_PRI6_MAXLEN_REG;        /* tx_pri6_maxlen_reg */
    volatile uint32_t TX_PRI7_MAXLEN_REG;        /* tx_pri7_maxlen_reg */
    volatile uint8_t  Resv_4096[3808];
    CSL_cpsw9Regs_CPSW_NU_CPSW_NU_CPPI CPSW_NU_CPPI;
    volatile uint8_t  Resv_8192[3292];
    CSL_cpsw9Regs_CPSW_NU_CPSW_NU_ETH_MAC CPSW_NU_ETH_MAC[8];
    volatile uint8_t  Resv_73728[32768];
    CSL_cpsw9Regs_CPSW_NU_CPSW_NU_EST CPSW_NU_EST;
    volatile uint8_t  Resv_106496[28672];
    CSL_cpsw9Regs_CPSW_NU_CPSW_NU_STAT CPSW_NU_STAT[9];
    volatile uint8_t  Resv_118784[7680];
    CSL_cpsw9Regs_CPSW_NU_CPTS CPTS;
    volatile uint8_t  Resv_122880[3328];
    CSL_cpsw9Regs_CPSW_NU_ALE ALE;
} CSL_cpsw9Regs_CPSW_NU;


typedef struct {
    volatile uint32_t CPSW_NUSS_IDVER_REG;       /* ID Version Register */
    volatile uint32_t SYNCE_COUNT_REG;           /* SyncE Count Register */
    volatile uint32_t SYNCE_MUX_REG;             /* SyncE Mux Register */
    volatile uint32_t CONTROL_REG;               /* Control Register */
    volatile uint32_t SGMII_NON_FIBER_MODE_REG;   /* SGMII NON FIBER Mode Register */
    volatile uint32_t SERDES_RESET_ISO_REG;      /* SyncE Mux Register */
    volatile uint8_t  Resv_28[4];
    volatile uint32_t SUBSSYSTEM_STATUS_REG;     /* Subsystem Status Register */
    volatile uint8_t  Resv_48[16];
    volatile uint32_t RGMII1_STATUS_REG;         /* RGMII1 Status Register */
    volatile uint32_t RGMII2_STATUS_REG;         /* RGMII2 Status Register */
    volatile uint32_t RGMII3_STATUS_REG;         /* RGMII3 Status Register */
    volatile uint32_t RGMII4_STATUS_REG;         /* RGMII4 Status Register */
    volatile uint32_t RGMII5_STATUS_REG;         /* RGMII5 Status Register */
    volatile uint32_t RGMII6_STATUS_REG;         /* RGMII6 Status Register */
    volatile uint32_t RGMII7_STATUS_REG;         /* RGMII7 Status Register */
    volatile uint32_t RGMII8_STATUS_REG;         /* RGMII8 Status Register */
    volatile uint8_t  Resv_96[16];
    volatile uint32_t QSGMII_CONTROL_REG;        /* QSGMII Control Register */
    volatile uint32_t QSGMII_STATUS_REG;         /* QSGMII Status Register */
    volatile uint8_t  Resv_116[12];
    volatile uint32_t STATUS_XGMII_LINK_REG;     /* XGMII Link Status Register */
    volatile uint32_t STATUS_SGMII_LINK_REG;     /* SGMII Link Status Register */
    volatile uint8_t  Resv_256[132];
    CSL_cpsw9Regs_CPSGMII CPSGMII[8];
    volatile uint8_t  Resv_3840[1536];
    CSL_cpsw9Regs_MDIO MDIO;
    volatile uint8_t  Resv_4096[112];
    CSL_cpsw9Regs_INTD INTD;
    volatile uint8_t  Resv_8448[1660];
    CSL_cpsw9Regs_PCSR PCSR[2];
    volatile uint8_t  Resv_131072[122112];
    CSL_cpsw9Regs_CPSW_NU CPSW_NU;
} CSL_cpsw9Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CPSW9_CPSW_NUSS_IDVER_REG                                          (0x00000000U)
#define CSL_CPSW9_SYNCE_COUNT_REG                                              (0x00000004U)
#define CSL_CPSW9_SYNCE_MUX_REG                                                (0x00000008U)
#define CSL_CPSW9_CONTROL_REG                                                  (0x0000000CU)
#define CSL_CPSW9_SGMII_NON_FIBER_MODE_REG                                     (0x00000010U)
#define CSL_CPSW9_SERDES_RESET_ISO_REG                                         (0x00000014U)
#define CSL_CPSW9_SUBSSYSTEM_STATUS_REG                                        (0x0000001CU)
#define CSL_CPSW9_RGMII1_STATUS_REG                                            (0x00000030U)
#define CSL_CPSW9_RGMII2_STATUS_REG                                            (0x00000034U)
#define CSL_CPSW9_RGMII3_STATUS_REG                                            (0x00000038U)
#define CSL_CPSW9_RGMII4_STATUS_REG                                            (0x0000003CU)
#define CSL_CPSW9_RGMII5_STATUS_REG                                            (0x00000040U)
#define CSL_CPSW9_RGMII6_STATUS_REG                                            (0x00000044U)
#define CSL_CPSW9_RGMII7_STATUS_REG                                            (0x00000048U)
#define CSL_CPSW9_RGMII8_STATUS_REG                                            (0x0000004CU)
#define CSL_CPSW9_QSGMII_CONTROL_REG                                           (0x00000060U)
#define CSL_CPSW9_QSGMII_STATUS_REG                                            (0x00000064U)
#define CSL_CPSW9_STATUS_XGMII_LINK_REG                                        (0x00000074U)
#define CSL_CPSW9_STATUS_SGMII_LINK_REG                                        (0x00000078U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG(CPSGMII)                             (0x00000100U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG(CPSGMII)                              (0x00000104U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_CONTROL_REG(CPSGMII)                                 (0x00000110U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_STATUS_REG(CPSGMII)                                  (0x00000114U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_MR_ADV_ABILITY_REG(CPSGMII)                          (0x00000118U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_MR_NP_TX_REG(CPSGMII)                                (0x0000011CU+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_MR_LP_ADV_ABILITY_REG(CPSGMII)                       (0x00000120U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_MR_LP_NP_RX_REG(CPSGMII)                             (0x00000124U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_DIAG_CLEAR_REG(CPSGMII)                              (0x00000140U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG(CPSGMII)                            (0x00000144U+((CPSGMII)*0x100U))
#define CSL_CPSW9_CPSGMII_DIAG_STATUS_REG(CPSGMII)                             (0x00000148U+((CPSGMII)*0x100U))
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG                                        (0x00000F00U)
#define CSL_CPSW9_MDIO_CONTROL_REG                                             (0x00000F04U)
#define CSL_CPSW9_MDIO_ALIVE_REG                                               (0x00000F08U)
#define CSL_CPSW9_MDIO_LINK_REG                                                (0x00000F0CU)
#define CSL_CPSW9_MDIO_LINK_INT_RAW_REG                                        (0x00000F10U)
#define CSL_CPSW9_MDIO_LINK_INT_MASKED_REG                                     (0x00000F14U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_SET_REG                                   (0x00000F18U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_CLEAR_REG                                 (0x00000F1CU)
#define CSL_CPSW9_MDIO_USER_INT_RAW_REG                                        (0x00000F20U)
#define CSL_CPSW9_MDIO_USER_INT_MASKED_REG                                     (0x00000F24U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_SET_REG                                   (0x00000F28U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_CLEAR_REG                                 (0x00000F2CU)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG                                           (0x00000F30U)
#define CSL_CPSW9_MDIO_POLL_REG                                                (0x00000F34U)
#define CSL_CPSW9_MDIO_POLL_EN_REG                                             (0x00000F38U)
#define CSL_CPSW9_MDIO_CLAUS45_REG                                             (0x00000F3CU)
#define CSL_CPSW9_MDIO_USER_ADDR0_REG                                          (0x00000F40U)
#define CSL_CPSW9_MDIO_USER_ADDR1_REG                                          (0x00000F44U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG(USER_GROUP)                  (0x00000F80U+((USER_GROUP)*0x8U))
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG(USER_GROUP)                 (0x00000F84U+((USER_GROUP)*0x8U))
#define CSL_CPSW9_INTD_REVISION                                                (0x00001000U)
#define CSL_CPSW9_INTD_EOI_REG                                                 (0x00001010U)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG                                         (0x00001014U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0                                  (0x00001100U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0                              (0x00001300U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0                                  (0x00001500U)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG_OUT_PULSE                               (0x00001A80U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG(PCSR)                                   (0x00002100U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_TX_STATUS_REG(PCSR)                                (0x00002104U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG(PCSR)                                   (0x00002108U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG(PCSR)                                (0x0000210CU+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_SEED_A_LO_REG(PCSR)                                (0x00002110U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_SEED_A_HI_REG(PCSR)                                (0x00002114U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_SEED_B_LO_REG(PCSR)                                (0x00002118U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_SEED_B_HI_REG(PCSR)                                (0x0000211CU+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_FEC_REG(PCSR)                                      (0x00002120U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_CTL_REG(PCSR)                                      (0x00002124U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG(PCSR)                                  (0x00002128U+((PCSR)*0x100U))
#define CSL_CPSW9_PCSR_PCSR_ERROR_FIFO_REG(PCSR)                               (0x0000212CU+((PCSR)*0x100U))
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG                                      (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG                                          (0x00020004U)
#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG                                       (0x00020010U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG                                     (0x00020014U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG                                            (0x00020018U)
#define CSL_CPSW9_CPSW_NU_SOFT_IDLE_REG                                        (0x0002001CU)
#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG                                        (0x00020020U)
#define CSL_CPSW9_CPSW_NU_GAP_THRESH_REG                                       (0x00020024U)
#define CSL_CPSW9_CPSW_NU_TX_START_WDS_REG                                     (0x00020028U)
#define CSL_CPSW9_CPSW_NU_EEE_PRESCALE_REG                                     (0x0002002CU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG                            (0x00020030U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG                            (0x00020034U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG                            (0x00020038U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG                            (0x0002003CU)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG                            (0x00020040U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG                            (0x00020044U)
#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG                                       (0x00020050U)
#define CSL_CPSW9_CPSW_NU_EST_TS_DOMAIN_REG                                    (0x00020054U)
#define CSL_CPSW9_CPSW_NU_TX_PRI0_MAXLEN_REG                                   (0x00020100U)
#define CSL_CPSW9_CPSW_NU_TX_PRI1_MAXLEN_REG                                   (0x00020104U)
#define CSL_CPSW9_CPSW_NU_TX_PRI2_MAXLEN_REG                                   (0x00020108U)
#define CSL_CPSW9_CPSW_NU_TX_PRI3_MAXLEN_REG                                   (0x0002010CU)
#define CSL_CPSW9_CPSW_NU_TX_PRI4_MAXLEN_REG                                   (0x00020110U)
#define CSL_CPSW9_CPSW_NU_TX_PRI5_MAXLEN_REG                                   (0x00020114U)
#define CSL_CPSW9_CPSW_NU_TX_PRI6_MAXLEN_REG                                   (0x00020118U)
#define CSL_CPSW9_CPSW_NU_TX_PRI7_MAXLEN_REG                                   (0x0002011CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG                          (0x00021004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FLOW_ID_OFFSET_REG                   (0x00021008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG                          (0x00021010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG                        (0x00021014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG                       (0x00021018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG                          (0x0002101CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG                       (0x00021020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_MAXLEN_REG                        (0x00021024U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG                      (0x00021028U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_IDLE2LPI_REG                         (0x00021030U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_LPI2WAKE_REG                         (0x00021034U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG                       (0x00021038U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FIFO_STATUS_REG                      (0x00021050U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG(P0_RX_DSCP_MAP_REG)  (0x00021120U+((P0_RX_DSCP_MAP_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CIR_REG(P0_PRI_CIR_REG)          (0x00021140U+((P0_PRI_CIR_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_EIR_REG(P0_PRI_EIR_REG)          (0x00021160U+((P0_PRI_EIR_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG                (0x00021180U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG                (0x00021184U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG                (0x00021188U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG                (0x0002118CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG            (0x00021190U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG            (0x00021194U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG            (0x00021198U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG            (0x0002119CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG                         (0x00021300U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG                         (0x00021304U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG                    (0x00021320U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RESERVED_REG(CPSW_NU_ETH_X)         (0x00022000U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG(CPSW_NU_ETH_X)          (0x00022004U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG(CPSW_NU_ETH_X)         (0x00022008U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG(CPSW_NU_ETH_X)          (0x00022010U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG(CPSW_NU_ETH_X)        (0x00022014U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG(CPSW_NU_ETH_X)       (0x00022018U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG(CPSW_NU_ETH_X)          (0x0002201CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG(CPSW_NU_ETH_X)       (0x00022020U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_MAXLEN_REG(CPSW_NU_ETH_X)        (0x00022024U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG(CPSW_NU_ETH_X)      (0x00022028U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IDLE2LPI_REG(CPSW_NU_ETH_X)         (0x00022030U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_LPI2WAKE_REG(CPSW_NU_ETH_X)         (0x00022034U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG(CPSW_NU_ETH_X)       (0x00022038U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG(CPSW_NU_ETH_X)      (0x00022040U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG(CPSW_NU_ETH_X)       (0x00022044U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_VERIFY_REG(CPSW_NU_ETH_X)       (0x00022048U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG(CPSW_NU_ETH_X)      (0x00022050U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG(CPSW_NU_ETH_X)      (0x00022060U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG(CPSW_NU_ETH_X,PN_RX_DSCP_MAP_REG) (0x00022120U+((CPSW_NU_ETH_X)*0x1000U)+((PN_RX_DSCP_MAP_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CIR_REG(CPSW_NU_ETH_X,PN_PRI_CIR_REG) (0x00022140U+((CPSW_NU_ETH_X)*0x1000U)+((PN_PRI_CIR_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_EIR_REG(CPSW_NU_ETH_X,PN_PRI_EIR_REG) (0x00022160U+((CPSW_NU_ETH_X)*0x1000U)+((PN_PRI_EIR_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG(CPSW_NU_ETH_X) (0x00022180U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG(CPSW_NU_ETH_X) (0x00022184U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG(CPSW_NU_ETH_X) (0x00022188U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG(CPSW_NU_ETH_X) (0x0002218CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG(CPSW_NU_ETH_X) (0x00022190U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG(CPSW_NU_ETH_X) (0x00022194U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG(CPSW_NU_ETH_X) (0x00022198U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG(CPSW_NU_ETH_X) (0x0002219CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG(CPSW_NU_ETH_X) (0x00022300U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG(CPSW_NU_ETH_X) (0x00022304U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG(CPSW_NU_ETH_X)             (0x00022308U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG(CPSW_NU_ETH_X)             (0x0002230CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG(CPSW_NU_ETH_X)           (0x00022310U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG(CPSW_NU_ETH_X)     (0x00022314U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG(CPSW_NU_ETH_X)    (0x00022318U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG(CPSW_NU_ETH_X)    (0x0002231CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG(CPSW_NU_ETH_X)          (0x00022320U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG(CPSW_NU_ETH_X)      (0x00022330U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG(CPSW_NU_ETH_X)       (0x00022334U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_SOFT_RESET_REG(CPSW_NU_ETH_X)   (0x00022338U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG(CPSW_NU_ETH_X)     (0x0002233CU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RX_PAUSETIMER_REG(CPSW_NU_ETH_X) (0x00022340U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RXN_PAUSETIMER_REG(CPSW_NU_ETH_X,PN_MAC_RXN_PAUSETIMER_REG) (0x00022350U+((CPSW_NU_ETH_X)*0x1000U)+((PN_MAC_RXN_PAUSETIMER_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_PAUSETIMER_REG(CPSW_NU_ETH_X) (0x00022370U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TXN_PAUSETIMER_REG(CPSW_NU_ETH_X,PN_MAC_TXN_PAUSETIMER_REG) (0x00022380U+((CPSW_NU_ETH_X)*0x1000U)+((PN_MAC_TXN_PAUSETIMER_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG(CPSW_NU_ETH_X)    (0x000223A0U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_GAP_REG(CPSW_NU_ETH_X)       (0x000223A4U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_POINTER_REG(CPSW_NU_ETH_X) (0x000223ACU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_A_REG(CPSW_NU_ETH_X)  (0x000223B0U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_B_REG(CPSW_NU_ETH_X)  (0x000223B4U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_C_REG(CPSW_NU_ETH_X)  (0x000223B8U+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_D_REG(CPSW_NU_ETH_X)  (0x000223BCU+((CPSW_NU_ETH_X)*0x1000U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_EST_FETCH_LOC(FETCH_LOC)                     (0x00032000U+((FETCH_LOC)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXGOODFRAMES(CPSW_NU_STAT)              (0x0003A000U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXBROADCASTFRAMES(CPSW_NU_STAT)         (0x0003A004U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXMULTICASTFRAMES(CPSW_NU_STAT)         (0x0003A008U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXPAUSEFRAMES(CPSW_NU_STAT)             (0x0003A00CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXCRCERRORS(CPSW_NU_STAT)               (0x0003A010U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXALIGNCODEERRORS(CPSW_NU_STAT)         (0x0003A014U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOVERSIZEDFRAMES(CPSW_NU_STAT)         (0x0003A018U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXJABBERFRAMES(CPSW_NU_STAT)            (0x0003A01CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXUNDERSIZEDFRAMES(CPSW_NU_STAT)        (0x0003A020U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXFRAGMENTS(CPSW_NU_STAT)               (0x0003A024U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DROP(CPSW_NU_STAT)                  (0x0003A028U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_OVERRUN_DROP(CPSW_NU_STAT)          (0x0003A02CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOCTETS(CPSW_NU_STAT)                  (0x0003A030U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXGOODFRAMES(CPSW_NU_STAT)              (0x0003A034U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXBROADCASTFRAMES(CPSW_NU_STAT)         (0x0003A038U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTICASTFRAMES(CPSW_NU_STAT)         (0x0003A03CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXPAUSEFRAMES(CPSW_NU_STAT)             (0x0003A040U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXDEFERREDFRAMES(CPSW_NU_STAT)          (0x0003A044U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCOLLISIONFRAMES(CPSW_NU_STAT)         (0x0003A048U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXSINGLECOLLFRAMES(CPSW_NU_STAT)        (0x0003A04CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTCOLLFRAMES(CPSW_NU_STAT)          (0x0003A050U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXEXCESSIVECOLLISIONS(CPSW_NU_STAT)     (0x0003A054U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXLATECOLLISIONS(CPSW_NU_STAT)          (0x0003A058U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXIPGERROR(CPSW_NU_STAT)                (0x0003A05CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCARRIERSENSEERRORS(CPSW_NU_STAT)      (0x0003A060U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXOCTETS(CPSW_NU_STAT)                  (0x0003A064U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES64(CPSW_NU_STAT)             (0x0003A068U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES65T127(CPSW_NU_STAT)         (0x0003A06CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES128T255(CPSW_NU_STAT)        (0x0003A070U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES256T511(CPSW_NU_STAT)        (0x0003A074U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES512T1023(CPSW_NU_STAT)       (0x0003A078U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES1024TUP(CPSW_NU_STAT)        (0x0003A07CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_NETOCTETS(CPSW_NU_STAT)                 (0x0003A080U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_BOTTOM_OF_FIFO_DROP(CPSW_NU_STAT)    (0x0003A084U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_PORTMASK_DROP(CPSW_NU_STAT)             (0x0003A088U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_TOP_OF_FIFO_DROP(CPSW_NU_STAT)       (0x0003A08CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_RATE_LIMIT_DROP(CPSW_NU_STAT)       (0x0003A090U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_VID_INGRESS_DROP(CPSW_NU_STAT)      (0x0003A094U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DA_EQ_SA_DROP(CPSW_NU_STAT)         (0x0003A098U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_BLOCK_DROP(CPSW_NU_STAT)            (0x0003A09CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_SECURE_DROP(CPSW_NU_STAT)           (0x0003A0A0U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_AUTH_DROP(CPSW_NU_STAT)             (0x0003A0A4U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI(CPSW_NU_STAT)              (0x0003A0A8U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_BCNT(CPSW_NU_STAT)         (0x0003A0ACU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT(CPSW_NU_STAT)              (0x0003A0B0U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_BCNT(CPSW_NU_STAT)         (0x0003A0B4U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD(CPSW_NU_STAT)              (0x0003A0B8U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_BCNT(CPSW_NU_STAT)         (0x0003A0BCU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH(CPSW_NU_STAT)             (0x0003A0C0U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_RED(CPSW_NU_STAT)         (0x0003A0C4U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_YELLOW(CPSW_NU_STAT)      (0x0003A0C8U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_MULT_SA_DROP(CPSW_NU_STAT)          (0x0003A0CCU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DUAL_VLAN_DROP(CPSW_NU_STAT)        (0x0003A0D0U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_LEN_ERROR_DROP(CPSW_NU_STAT)        (0x0003A0D4U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IP_NEXT_HDR_DROP(CPSW_NU_STAT)      (0x0003A0D8U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IPV4_FRAG_DROP(CPSW_NU_STAT)        (0x0003A0DCU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_ERROR_REG(CPSW_NU_STAT) (0x0003A140U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_OK_REG(CPSW_NU_STAT)    (0x0003A144U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_SMD_ERROR_REG(CPSW_NU_STAT)      (0x0003A148U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_FRAG_REG(CPSW_NU_STAT)           (0x0003A14CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_HOLD_REG(CPSW_NU_STAT)           (0x0003A150U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_FRAG_REG(CPSW_NU_STAT)           (0x0003A154U+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TX_MEMORY_PROTECT_ERROR(CPSW_NU_STAT)   (0x0003A17CU+((CPSW_NU_STAT)*0x200U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_REG(CPSW_NU_STAT,ENET_PN_TX_PRI_REG) (0x0003A180U+((CPSW_NU_STAT)*0x200U)+((ENET_PN_TX_PRI_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_BCNT_REG(CPSW_NU_STAT,ENET_PN_TX_PRI_BCNT_REG) (0x0003A1A0U+((CPSW_NU_STAT)*0x200U)+((ENET_PN_TX_PRI_BCNT_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_REG(CPSW_NU_STAT,ENET_PN_TX_PRI_DROP_REG) (0x0003A1C0U+((CPSW_NU_STAT)*0x200U)+((ENET_PN_TX_PRI_DROP_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_BCNT_REG(CPSW_NU_STAT,ENET_PN_TX_PRI_DROP_BCNT_REG) (0x0003A1E0U+((CPSW_NU_STAT)*0x200U)+((ENET_PN_TX_PRI_DROP_BCNT_REG)*0x4U))
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG                                       (0x0003D000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG                                     (0x0003D004U)
#define CSL_CPSW9_CPSW_NU_CPTS_RFTCLK_SEL_REG                                  (0x0003D008U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PUSH_REG                                     (0x0003D00CU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_VAL_REG                                 (0x0003D010U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_EN_REG                                  (0x0003D014U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_VAL_REG                                 (0x0003D018U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_LEN_REG                                 (0x0003D01CU)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_RAW_REG                                 (0x0003D020U)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_MASKED_REG                              (0x0003D024U)
#define CSL_CPSW9_CPSW_NU_CPTS_INT_ENABLE_REG                                  (0x0003D028U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_NUDGE_REG                               (0x0003D02CU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_POP_REG                                   (0x0003D030U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_0_REG                                     (0x0003D034U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG                                     (0x0003D038U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_2_REG                                     (0x0003D03CU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_3_REG                                     (0x0003D040U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_HIGH_VAL_REG                            (0x0003D044U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_HIGH_VAL_REG                            (0x0003D048U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ADD_VAL_REG                                  (0x0003D04CU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_LOW_VAL_REG                              (0x0003D050U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_HIGH_VAL_REG                             (0x0003D054U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_NUDGE_VAL_REG                                (0x0003D058U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_LOW_REG(TS_GENF)                   (0x0003D0E0U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_HIGH_REG(TS_GENF)                  (0x0003D0E4U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG(TS_GENF)                    (0x0003D0E8U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_LENGTH_REG(TS_GENF)                     (0x0003D0ECU+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_LOW_REG(TS_GENF)                    (0x0003D0F0U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_HIGH_REG(TS_GENF)                   (0x0003D0F4U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_NUDGE_REG(TS_GENF)                      (0x0003D0F8U+((TS_GENF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_LOW_REG(TS_ESTF)                   (0x0003D200U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_HIGH_REG(TS_ESTF)                  (0x0003D204U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG(TS_ESTF)                    (0x0003D208U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_LENGTH_REG(TS_ESTF)                     (0x0003D20CU+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_LOW_REG(TS_ESTF)                    (0x0003D210U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_HIGH_REG(TS_ESTF)                   (0x0003D214U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_NUDGE_REG(TS_ESTF)                      (0x0003D218U+((TS_ESTF)*0x20U))
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER                                          (0x0003E000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS                                       (0x0003E004U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL                                      (0x0003E008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2                                        (0x0003E00CU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_PRESCALE                                     (0x0003E010U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL                                   (0x0003E014U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR                                      (0x0003E01CU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL                                       (0x0003E020U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW2                                        (0x0003E034U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW1                                        (0x0003E038U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW0                                        (0x0003E03CU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0(I0_ALE_PORTCTL0)                 (0x0003E040U+((I0_ALE_PORTCTL0)*0x4U))
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_MEMBER                                 (0x0003E090U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_URCAST                                 (0x0003E094U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_RMCAST                                 (0x0003E098U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_UNTAG                                  (0x0003E09CU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG                                    (0x0003E0B8U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_OAM_LB_CTRL                                  (0x0003E0BCU)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP                                         (0x0003E0FCU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0                                       (0x0003E100U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1                                       (0x0003E104U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2                                       (0x0003E108U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3                                       (0x0003E10CU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4                                       (0x0003E110U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG6                                       (0x0003E118U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG7                                       (0x0003E11CU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL                                     (0x0003E120U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL                                    (0x0003E124U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL                                    (0x0003E128U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT                                      (0x0003E12CU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF                                     (0x0003E134U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPCTL                                     (0x0003E138U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL                                     (0x0003E13CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* SGMII_IDVER_REG */

#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MINOR_VER_MASK                       (0x000000FFU)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MINOR_VER_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MINOR_VER_MAX                        (0x000000FFU)

#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MAJOR_VER_MASK                       (0x00000700U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MAJOR_VER_SHIFT                      (0x00000008U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_MAJOR_VER_MAX                        (0x00000007U)

#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_RTL_VER_MASK                         (0x0000F800U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_RTL_VER_SHIFT                        (0x0000000BU)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_RTL_VER_MAX                          (0x0000001FU)

#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_TX_IDENT_MASK                        (0xFFFF0000U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_TX_IDENT_SHIFT                       (0x00000010U)
#define CSL_CPSW9_CPSGMII_SGMII_IDVER_REG_TX_IDENT_MAX                         (0x0000FFFFU)

/* SOFT_RESET_REG */

#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_SOFT_RESET_MASK                       (0x00000001U)
#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_SOFT_RESET_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_SOFT_RESET_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_MASK                    (0x00000002U)
#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_SHIFT                   (0x00000001U)
#define CSL_CPSW9_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_MAX                     (0x00000001U)

/* CONTROL_REG */

#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_ENABLE_MASK                        (0x00000001U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_ENABLE_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_ENABLE_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_RESTART_MASK                       (0x00000002U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_RESTART_SHIFT                      (0x00000001U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_AN_RESTART_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_MASK                     (0x00000004U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_SHIFT                    (0x00000002U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_NP_LOADED_MASK                        (0x00000008U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_NP_LOADED_SHIFT                       (0x00000003U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MR_NP_LOADED_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_LOOPBACK_MASK                            (0x00000010U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_LOOPBACK_SHIFT                           (0x00000004U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_LOOPBACK_MAX                             (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_MASTER_MASK                              (0x00000020U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MASTER_SHIFT                             (0x00000005U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_MASTER_MAX                               (0x00000001U)

#define CSL_CPSW9_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_MASK                     (0x00000040U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_SHIFT                    (0x00000006U)
#define CSL_CPSW9_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_MAX                      (0x00000001U)

/* STATUS_REG */

#define CSL_CPSW9_CPSGMII_STATUS_REG_LINK_MASK                                 (0x00000001U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_LINK_SHIFT                                (0x00000000U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_LINK_MAX                                  (0x00000001U)

#define CSL_CPSW9_CPSGMII_STATUS_REG_AN_ERROR_MASK                             (0x00000002U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_AN_ERROR_SHIFT                            (0x00000001U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_AN_ERROR_MAX                              (0x00000001U)

#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_AN_COMPLETE_MASK                       (0x00000004U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_AN_COMPLETE_SHIFT                      (0x00000002U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_AN_COMPLETE_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_PAGE_RX_MASK                           (0x00000008U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_PAGE_RX_SHIFT                          (0x00000003U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_MR_PAGE_RX_MAX                            (0x00000001U)

#define CSL_CPSW9_CPSGMII_STATUS_REG_LOCK_MASK                                 (0x00000010U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_LOCK_SHIFT                                (0x00000004U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_LOCK_MAX                                  (0x00000001U)

#define CSL_CPSW9_CPSGMII_STATUS_REG_FIB_SIG_DETECT_MASK                       (0x00000020U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_FIB_SIG_DETECT_SHIFT                      (0x00000005U)
#define CSL_CPSW9_CPSGMII_STATUS_REG_FIB_SIG_DETECT_MAX                        (0x00000001U)

/* MR_ADV_ABILITY_REG */

#define CSL_CPSW9_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_MASK               (0x0000FFFFU)
#define CSL_CPSW9_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_MAX                (0x0000FFFFU)

/* MR_NP_TX_REG */

#define CSL_CPSW9_CPSGMII_MR_NP_TX_REG_MR_NP_TX_MASK                           (0x0000FFFFU)
#define CSL_CPSW9_CPSGMII_MR_NP_TX_REG_MR_NP_TX_SHIFT                          (0x00000000U)
#define CSL_CPSW9_CPSGMII_MR_NP_TX_REG_MR_NP_TX_MAX                            (0x0000FFFFU)

/* MR_LP_ADV_ABILITY_REG */

#define CSL_CPSW9_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_MASK         (0x0000FFFFU)
#define CSL_CPSW9_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_MAX          (0x0000FFFFU)

/* MR_LP_NP_RX_REG */

#define CSL_CPSW9_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_MASK                     (0x0000FFFFU)
#define CSL_CPSW9_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_MAX                      (0x0000FFFFU)

/* DIAG_CLEAR_REG */

#define CSL_CPSW9_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_MASK                       (0x00000001U)
#define CSL_CPSW9_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_MAX                        (0x00000001U)

/* DIAG_CONTROL_REG */

#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_MASK                  (0x00000003U)
#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_MAX                   (0x00000003U)

#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_MASK                    (0x00000070U)
#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_SHIFT                   (0x00000004U)
#define CSL_CPSW9_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_MAX                     (0x00000007U)

/* DIAG_STATUS_REG */

#define CSL_CPSW9_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_MASK                     (0x0000FFFFU)
#define CSL_CPSW9_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_MAX                      (0x0000FFFFU)

/* USER_ACCESS_REG */

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_DATA_MASK                    (0x0000FFFFU)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_DATA_SHIFT                   (0x00000000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_DATA_MAX                     (0x0000FFFFU)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR_MASK                  (0x001F0000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR_SHIFT                 (0x00000010U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR_MAX                   (0x0000001FU)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR_MASK                  (0x03E00000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR_SHIFT                 (0x00000015U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR_MAX                   (0x0000001FU)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_ACK_MASK                     (0x20000000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_ACK_SHIFT                    (0x0000001DU)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_ACK_MAX                      (0x00000001U)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE_MASK                   (0x40000000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE_SHIFT                  (0x0000001EU)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE_MAX                    (0x00000001U)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_GO_MASK                      (0x80000000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_GO_SHIFT                     (0x0000001FU)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_ACCESS_REG_GO_MAX                       (0x00000001U)

/* USER_PHY_SEL_REG */

#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_PHYADR_MON_MASK             (0x0000001FU)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_PHYADR_MON_SHIFT            (0x00000000U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_PHYADR_MON_MAX              (0x0000001FU)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKINT_ENABLE_MASK         (0x00000040U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKINT_ENABLE_SHIFT        (0x00000006U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKINT_ENABLE_MAX          (0x00000001U)

#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKSEL_MASK                (0x00000080U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKSEL_SHIFT               (0x00000007U)
#define CSL_CPSW9_MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKSEL_MAX                 (0x00000001U)

/* MDIO_VERSION_REG */

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_SCHEME_MASK                            (0xC0000000U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_SCHEME_SHIFT                           (0x0000001EU)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_SCHEME_MAX                             (0x00000003U)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_BU_MASK                                (0x30000000U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_BU_SHIFT                               (0x0000001CU)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_BU_MAX                                 (0x00000003U)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_MODULE_ID_MASK                         (0x0FFF0000U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_MODULE_ID_SHIFT                        (0x00000010U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_MODULE_ID_MAX                          (0x00000FFFU)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVRTL_MASK                            (0x0000F800U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVRTL_SHIFT                           (0x0000000BU)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVRTL_MAX                             (0x0000001FU)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMAJ_MASK                            (0x00000700U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMAJ_SHIFT                           (0x00000008U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMAJ_MAX                             (0x00000007U)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_CUSTOM_MASK                            (0x000000C0U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_CUSTOM_SHIFT                           (0x00000006U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_CUSTOM_MAX                             (0x00000003U)

#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMIN_MASK                            (0x0000003FU)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMIN_SHIFT                           (0x00000000U)
#define CSL_CPSW9_MDIO_MDIO_VERSION_REG_REVMIN_MAX                             (0x0000003FU)

/* CONTROL_REG */

#define CSL_CPSW9_MDIO_CONTROL_REG_CLKDIV_MASK                                 (0x0000FFFFU)
#define CSL_CPSW9_MDIO_CONTROL_REG_CLKDIV_SHIFT                                (0x00000000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_CLKDIV_MAX                                  (0x0000FFFFU)

#define CSL_CPSW9_MDIO_CONTROL_REG_INT_TEST_ENABLE_MASK                        (0x00020000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_INT_TEST_ENABLE_SHIFT                       (0x00000011U)
#define CSL_CPSW9_MDIO_CONTROL_REG_INT_TEST_ENABLE_MAX                         (0x00000001U)

#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_DETECT_ENABLE_MASK                    (0x00040000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_DETECT_ENABLE_SHIFT                   (0x00000012U)
#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_DETECT_ENABLE_MAX                     (0x00000001U)

#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_MASK                                  (0x00080000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_SHIFT                                 (0x00000013U)
#define CSL_CPSW9_MDIO_CONTROL_REG_FAULT_MAX                                   (0x00000001U)

#define CSL_CPSW9_MDIO_CONTROL_REG_PREAMBLE_MASK                               (0x00100000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_PREAMBLE_SHIFT                              (0x00000014U)
#define CSL_CPSW9_MDIO_CONTROL_REG_PREAMBLE_MAX                                (0x00000001U)

#define CSL_CPSW9_MDIO_CONTROL_REG_HIGHEST_USER_CHANNEL_MASK                   (0x1F000000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_HIGHEST_USER_CHANNEL_SHIFT                  (0x00000018U)
#define CSL_CPSW9_MDIO_CONTROL_REG_HIGHEST_USER_CHANNEL_MAX                    (0x0000001FU)

#define CSL_CPSW9_MDIO_CONTROL_REG_ENABLE_MASK                                 (0x40000000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_ENABLE_SHIFT                                (0x0000001EU)
#define CSL_CPSW9_MDIO_CONTROL_REG_ENABLE_MAX                                  (0x00000001U)

#define CSL_CPSW9_MDIO_CONTROL_REG_IDLE_MASK                                   (0x80000000U)
#define CSL_CPSW9_MDIO_CONTROL_REG_IDLE_SHIFT                                  (0x0000001FU)
#define CSL_CPSW9_MDIO_CONTROL_REG_IDLE_MAX                                    (0x00000001U)

/* ALIVE_REG */

#define CSL_CPSW9_MDIO_ALIVE_REG_ALIVE_MASK                                    (0xFFFFFFFFU)
#define CSL_CPSW9_MDIO_ALIVE_REG_ALIVE_SHIFT                                   (0x00000000U)
#define CSL_CPSW9_MDIO_ALIVE_REG_ALIVE_MAX                                     (0xFFFFFFFFU)

/* LINK_REG */

#define CSL_CPSW9_MDIO_LINK_REG_LINK_MASK                                      (0xFFFFFFFFU)
#define CSL_CPSW9_MDIO_LINK_REG_LINK_SHIFT                                     (0x00000000U)
#define CSL_CPSW9_MDIO_LINK_REG_LINK_MAX                                       (0xFFFFFFFFU)

/* LINK_INT_RAW_REG */

#define CSL_CPSW9_MDIO_LINK_INT_RAW_REG_LINKINTRAW_MASK                        (0x00000003U)
#define CSL_CPSW9_MDIO_LINK_INT_RAW_REG_LINKINTRAW_SHIFT                       (0x00000000U)
#define CSL_CPSW9_MDIO_LINK_INT_RAW_REG_LINKINTRAW_MAX                         (0x00000003U)

/* LINK_INT_MASKED_REG */

#define CSL_CPSW9_MDIO_LINK_INT_MASKED_REG_LINKINTMASKED_MASK                  (0x00000003U)
#define CSL_CPSW9_MDIO_LINK_INT_MASKED_REG_LINKINTMASKED_SHIFT                 (0x00000000U)
#define CSL_CPSW9_MDIO_LINK_INT_MASKED_REG_LINKINTMASKED_MAX                   (0x00000003U)

/* LINK_INT_MASK_SET_REG */

#define CSL_CPSW9_MDIO_LINK_INT_MASK_SET_REG_LINKINTMASKSET_MASK               (0x00000001U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_SET_REG_LINKINTMASKSET_SHIFT              (0x00000000U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_SET_REG_LINKINTMASKSET_MAX                (0x00000001U)

/* LINK_INT_MASK_CLEAR_REG */

#define CSL_CPSW9_MDIO_LINK_INT_MASK_CLEAR_REG_LINKINTMASKCLR_MASK             (0x00000001U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_CLEAR_REG_LINKINTMASKCLR_SHIFT            (0x00000000U)
#define CSL_CPSW9_MDIO_LINK_INT_MASK_CLEAR_REG_LINKINTMASKCLR_MAX              (0x00000001U)

/* USER_INT_RAW_REG */

#define CSL_CPSW9_MDIO_USER_INT_RAW_REG_USERINTRAW_MASK                        (0x00000003U)
#define CSL_CPSW9_MDIO_USER_INT_RAW_REG_USERINTRAW_SHIFT                       (0x00000000U)
#define CSL_CPSW9_MDIO_USER_INT_RAW_REG_USERINTRAW_MAX                         (0x00000003U)

/* USER_INT_MASKED_REG */

#define CSL_CPSW9_MDIO_USER_INT_MASKED_REG_USERINTMASKED_MASK                  (0x00000003U)
#define CSL_CPSW9_MDIO_USER_INT_MASKED_REG_USERINTMASKED_SHIFT                 (0x00000000U)
#define CSL_CPSW9_MDIO_USER_INT_MASKED_REG_USERINTMASKED_MAX                   (0x00000003U)

/* USER_INT_MASK_SET_REG */

#define CSL_CPSW9_MDIO_USER_INT_MASK_SET_REG_USERINTMASKSET_MASK               (0x00000003U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_SET_REG_USERINTMASKSET_SHIFT              (0x00000000U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_SET_REG_USERINTMASKSET_MAX                (0x00000003U)

/* USER_INT_MASK_CLEAR_REG */

#define CSL_CPSW9_MDIO_USER_INT_MASK_CLEAR_REG_USERINTMASKCLR_MASK             (0x00000003U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_CLEAR_REG_USERINTMASKCLR_SHIFT            (0x00000000U)
#define CSL_CPSW9_MDIO_USER_INT_MASK_CLEAR_REG_USERINTMASKCLR_MAX              (0x00000003U)

/* MANUAL_IF_REG */

#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_PIN_MASK                             (0x00000001U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_PIN_SHIFT                            (0x00000000U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_PIN_MAX                              (0x00000001U)

#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_OE_MASK                              (0x00000002U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_OE_SHIFT                             (0x00000001U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_OE_MAX                               (0x00000001U)

#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_MDCLK_O_MASK                         (0x00000004U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_MDCLK_O_SHIFT                        (0x00000002U)
#define CSL_CPSW9_MDIO_MANUAL_IF_REG_MDIO_MDCLK_O_MAX                          (0x00000001U)

/* POLL_REG */

#define CSL_CPSW9_MDIO_POLL_REG_IPG_MASK                                       (0x000000FFU)
#define CSL_CPSW9_MDIO_POLL_REG_IPG_SHIFT                                      (0x00000000U)
#define CSL_CPSW9_MDIO_POLL_REG_IPG_MAX                                        (0x000000FFU)

#define CSL_CPSW9_MDIO_POLL_REG_STATECHANGEMODE_MASK                           (0x40000000U)
#define CSL_CPSW9_MDIO_POLL_REG_STATECHANGEMODE_SHIFT                          (0x0000001EU)
#define CSL_CPSW9_MDIO_POLL_REG_STATECHANGEMODE_MAX                            (0x00000001U)

#define CSL_CPSW9_MDIO_POLL_REG_MANUALMODE_MASK                                (0x80000000U)
#define CSL_CPSW9_MDIO_POLL_REG_MANUALMODE_SHIFT                               (0x0000001FU)
#define CSL_CPSW9_MDIO_POLL_REG_MANUALMODE_MAX                                 (0x00000001U)

/* POLL_EN_REG */

#define CSL_CPSW9_MDIO_POLL_EN_REG_POLL_EN_MASK                                (0xFFFFFFFFU)
#define CSL_CPSW9_MDIO_POLL_EN_REG_POLL_EN_SHIFT                               (0x00000000U)
#define CSL_CPSW9_MDIO_POLL_EN_REG_POLL_EN_MAX                                 (0xFFFFFFFFU)

/* CLAUS45_REG */

#define CSL_CPSW9_MDIO_CLAUS45_REG_CLAUSE45_MASK                               (0xFFFFFFFFU)
#define CSL_CPSW9_MDIO_CLAUS45_REG_CLAUSE45_SHIFT                              (0x00000000U)
#define CSL_CPSW9_MDIO_CLAUS45_REG_CLAUSE45_MAX                                (0xFFFFFFFFU)

/* USER_ADDR0_REG */

#define CSL_CPSW9_MDIO_USER_ADDR0_REG_USER_ADDR0_MASK                          (0x0000FFFFU)
#define CSL_CPSW9_MDIO_USER_ADDR0_REG_USER_ADDR0_SHIFT                         (0x00000000U)
#define CSL_CPSW9_MDIO_USER_ADDR0_REG_USER_ADDR0_MAX                           (0x0000FFFFU)

/* USER_ADDR1_REG */

#define CSL_CPSW9_MDIO_USER_ADDR1_REG_USER_ADDR1_MASK                          (0x0000FFFFU)
#define CSL_CPSW9_MDIO_USER_ADDR1_REG_USER_ADDR1_SHIFT                         (0x00000000U)
#define CSL_CPSW9_MDIO_USER_ADDR1_REG_USER_ADDR1_MAX                           (0x0000FFFFU)

/* REVISION */

#define CSL_CPSW9_INTD_REVISION_SCHEME_MASK                                    (0xC0000000U)
#define CSL_CPSW9_INTD_REVISION_SCHEME_SHIFT                                   (0x0000001EU)
#define CSL_CPSW9_INTD_REVISION_SCHEME_MAX                                     (0x00000003U)

#define CSL_CPSW9_INTD_REVISION_BU_MASK                                        (0x30000000U)
#define CSL_CPSW9_INTD_REVISION_BU_SHIFT                                       (0x0000001CU)
#define CSL_CPSW9_INTD_REVISION_BU_MAX                                         (0x00000003U)

#define CSL_CPSW9_INTD_REVISION_FUNCTION_MASK                                  (0x0FFF0000U)
#define CSL_CPSW9_INTD_REVISION_FUNCTION_SHIFT                                 (0x00000010U)
#define CSL_CPSW9_INTD_REVISION_FUNCTION_MAX                                   (0x00000FFFU)

#define CSL_CPSW9_INTD_REVISION_RTLVER_MASK                                    (0x0000F800U)
#define CSL_CPSW9_INTD_REVISION_RTLVER_SHIFT                                   (0x0000000BU)
#define CSL_CPSW9_INTD_REVISION_RTLVER_MAX                                     (0x0000001FU)

#define CSL_CPSW9_INTD_REVISION_MAJREV_MASK                                    (0x00000700U)
#define CSL_CPSW9_INTD_REVISION_MAJREV_SHIFT                                   (0x00000008U)
#define CSL_CPSW9_INTD_REVISION_MAJREV_MAX                                     (0x00000007U)

#define CSL_CPSW9_INTD_REVISION_CUSTOM_MASK                                    (0x000000C0U)
#define CSL_CPSW9_INTD_REVISION_CUSTOM_SHIFT                                   (0x00000006U)
#define CSL_CPSW9_INTD_REVISION_CUSTOM_MAX                                     (0x00000003U)

#define CSL_CPSW9_INTD_REVISION_MINREV_MASK                                    (0x0000003FU)
#define CSL_CPSW9_INTD_REVISION_MINREV_SHIFT                                   (0x00000000U)
#define CSL_CPSW9_INTD_REVISION_MINREV_MAX                                     (0x0000003FU)

/* EOI_REG */

#define CSL_CPSW9_INTD_EOI_REG_EOI_VECTOR_MASK                                 (0x000000FFU)
#define CSL_CPSW9_INTD_EOI_REG_EOI_VECTOR_SHIFT                                (0x00000000U)
#define CSL_CPSW9_INTD_EOI_REG_EOI_VECTOR_MAX                                  (0x000000FFU)

/* INTR_VECTOR_REG */

#define CSL_CPSW9_INTD_INTR_VECTOR_REG_INTR_VECTOR_MASK                        (0xFFFFFFFFU)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG_INTR_VECTOR_SHIFT                       (0x00000000U)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG_INTR_VECTOR_MAX                         (0xFFFFFFFFU)

/* ENABLE_REG_OUT_PULSE_0 */

#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_MASK (0x00000001U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_SHIFT (0x00000000U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_MAX (0x00000001U)

#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_MASK (0x00000002U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_SHIFT (0x00000001U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_MAX (0x00000001U)

#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_MASK (0x00000004U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_SHIFT (0x00000002U)
#define CSL_CPSW9_INTD_ENABLE_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_MAX (0x00000001U)

/* ENABLE_CLR_REG_OUT_PULSE_0 */

#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_CLR_MASK (0x00000001U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_CLR_SHIFT (0x00000000U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_EVNT_PENDA_CLR_MAX (0x00000001U)

#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_CLR_MASK (0x00000002U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_CLR_SHIFT (0x00000001U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_MDIO_PENDA_CLR_MAX (0x00000001U)

#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_CLR_MASK (0x00000004U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_CLR_SHIFT (0x00000002U)
#define CSL_CPSW9_INTD_ENABLE_CLR_REG_OUT_PULSE_0_ENABLE_OUT_PULSE_EN_STAT_PENDA_CLR_MAX (0x00000001U)

/* STATUS_REG_OUT_PULSE_0 */

#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_EVNT_PENDA_MASK (0x00000001U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_EVNT_PENDA_SHIFT (0x00000000U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_EVNT_PENDA_MAX  (0x00000001U)

#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_MDIO_PENDA_MASK (0x00000002U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_MDIO_PENDA_SHIFT (0x00000001U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_MDIO_PENDA_MAX  (0x00000001U)

#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_STAT_PENDA_MASK (0x00000004U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_STAT_PENDA_SHIFT (0x00000002U)
#define CSL_CPSW9_INTD_STATUS_REG_OUT_PULSE_0_STATUS_OUT_PULSE_STAT_PENDA_MAX  (0x00000001U)

/* INTR_VECTOR_REG_OUT_PULSE */

#define CSL_CPSW9_INTD_INTR_VECTOR_REG_OUT_PULSE_INTR_VECTOR_OUT_PULSE_MASK    (0xFFFFFFFFU)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG_OUT_PULSE_INTR_VECTOR_OUT_PULSE_SHIFT   (0x00000000U)
#define CSL_CPSW9_INTD_INTR_VECTOR_REG_OUT_PULSE_INTR_VECTOR_OUT_PULSE_MAX     (0xFFFFFFFFU)

/* PCSR_TX_CTL_REG */

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_DATAPATH_EN_MASK                     (0x00000100U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_DATAPATH_EN_SHIFT                    (0x00000008U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_DATAPATH_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_BPYASS_MASK                      (0x00000080U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_BPYASS_SHIFT                     (0x00000007U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_BPYASS_MAX                       (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_EN_MASK                         (0x00000040U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_EN_SHIFT                        (0x00000006U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_EN_MAX                          (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_SEL_MASK                        (0x00000020U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_SEL_SHIFT                       (0x00000005U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_SEL_MAX                         (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_DAT_SEL_MASK                    (0x00000010U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_DAT_SEL_SHIFT                   (0x00000004U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_TEST_DAT_SEL_MAX                     (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS31_EN_MASK                       (0x00000008U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS31_EN_SHIFT                      (0x00000003U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS31_EN_MAX                        (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS9_EN_MASK                        (0x00000004U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS9_EN_SHIFT                       (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_PRBS9_EN_MAX                         (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_LOOPBACK_EN_MASK                     (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_LOOPBACK_EN_SHIFT                    (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_LOOPBACK_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_LOOPBK_EN_MASK                   (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_LOOPBK_EN_SHIFT                  (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_TX_CTL_REG_TX_SCR_LOOPBK_EN_MAX                    (0x00000001U)

/* PCSR_TX_STATUS_REG */

#define CSL_CPSW9_PCSR_PCSR_TX_STATUS_REG_TX_FAULT_MASK                        (0x00000100U)
#define CSL_CPSW9_PCSR_PCSR_TX_STATUS_REG_TX_FAULT_SHIFT                       (0x00000008U)
#define CSL_CPSW9_PCSR_PCSR_TX_STATUS_REG_TX_FAULT_MAX                         (0x00000001U)

/* PCSR_RX_CTL_REG */

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS9_EN_MASK                        (0x00000100U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS9_EN_SHIFT                       (0x00000008U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS9_EN_MAX                         (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_EN_MASK                         (0x00000080U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_EN_SHIFT                        (0x00000007U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_EN_MAX                          (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_DAT_SEL_MASK                    (0x00000040U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_DAT_SEL_SHIFT                   (0x00000006U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_DAT_SEL_MAX                     (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS31_EN_MASK                       (0x00000020U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS31_EN_SHIFT                      (0x00000005U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_PRBS31_EN_MAX                        (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_ERR_BLK_CNT_RST_MASK                 (0x00000010U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_ERR_BLK_CNT_RST_SHIFT                (0x00000004U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_ERR_BLK_CNT_RST_MAX                  (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_BER_CNT_RST_MASK                     (0x00000008U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_BER_CNT_RST_SHIFT                    (0x00000003U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_BER_CNT_RST_MAX                      (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_PRE_MASK                    (0x00000004U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_PRE_SHIFT                   (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_PRE_MAX                     (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_125US_MASK                  (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_125US_SHIFT                 (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TEST_CNT_125US_MAX                   (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TPTER_CNT_RST_MASK                   (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TPTER_CNT_RST_SHIFT                  (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_RX_CTL_REG_RX_TPTER_CNT_RST_MAX                    (0x00000001U)

/* PCSR_RX_STATUS_REG */

#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_HI_BER_MASK                       (0x80000000U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_HI_BER_SHIFT                      (0x0000001FU)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_HI_BER_MAX                        (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BLOCK_LOCK_MASK                   (0x40000000U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BLOCK_LOCK_SHIFT                  (0x0000001EU)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BLOCK_LOCK_MAX                    (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BER_COUNT_MASK                    (0x3F000000U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BER_COUNT_SHIFT                   (0x00000018U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_BER_COUNT_MAX                     (0x0000003FU)

#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_ERR_BLK_CNT_MASK                  (0x00FF0000U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_ERR_BLK_CNT_SHIFT                 (0x00000010U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_ERR_BLK_CNT_MAX                   (0x000000FFU)

#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_TPT_ERR_CNT_MASK                  (0x0000FFFFU)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_TPT_ERR_CNT_SHIFT                 (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_RX_STATUS_REG_RX_TPT_ERR_CNT_MAX                   (0x0000FFFFU)

/* PCSR_SEED_A_LO_REG */

#define CSL_CPSW9_PCSR_PCSR_SEED_A_LO_REG_SEED_A_LO_MASK                       (0xFFFFFFFFU)
#define CSL_CPSW9_PCSR_PCSR_SEED_A_LO_REG_SEED_A_LO_SHIFT                      (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_SEED_A_LO_REG_SEED_A_LO_MAX                        (0xFFFFFFFFU)

/* PCSR_SEED_A_HI_REG */

#define CSL_CPSW9_PCSR_PCSR_SEED_A_HI_REG_SEED_A_HI_MASK                       (0x03FFFFFFU)
#define CSL_CPSW9_PCSR_PCSR_SEED_A_HI_REG_SEED_A_HI_SHIFT                      (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_SEED_A_HI_REG_SEED_A_HI_MAX                        (0x03FFFFFFU)

/* PCSR_SEED_B_LO_REG */

#define CSL_CPSW9_PCSR_PCSR_SEED_B_LO_REG_SEED_B_LO_MASK                       (0xFFFFFFFFU)
#define CSL_CPSW9_PCSR_PCSR_SEED_B_LO_REG_SEED_B_LO_SHIFT                      (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_SEED_B_LO_REG_SEED_B_LO_MAX                        (0xFFFFFFFFU)

/* PCSR_SEED_B_HI_REG */

#define CSL_CPSW9_PCSR_PCSR_SEED_B_HI_REG_SEED_B_HI_MASK                       (0x03FFFFFFU)
#define CSL_CPSW9_PCSR_PCSR_SEED_B_HI_REG_SEED_B_HI_SHIFT                      (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_SEED_B_HI_REG_SEED_B_HI_MAX                        (0x03FFFFFFU)

/* PCSR_FEC_REG */

#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENA_ERR_IND_MASK                       (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENA_ERR_IND_SHIFT                      (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENA_ERR_IND_MAX                        (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENABLE_MASK                            (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENABLE_SHIFT                           (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_FEC_REG_FEC_ENABLE_MAX                             (0x00000001U)

/* PCSR_CTL_REG */

#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_EN_MASK                          (0x00000002U)
#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_EN_SHIFT                         (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_EN_MAX                           (0x00000001U)

#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_MASK                             (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_SHIFT                            (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_CTL_REG_SIGNAL_OK_MAX                              (0x00000001U)

/* PCSR_FEC_CNT_REG */

#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_CORR_CNT_MASK                      (0xFFFF0000U)
#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_CORR_CNT_SHIFT                     (0x00000010U)
#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_CORR_CNT_MAX                       (0x0000FFFFU)

#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_UNCORRCNT_MASK                     (0x0000FFFFU)
#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_UNCORRCNT_SHIFT                    (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_FEC_CNT_REG_FEC_UNCORRCNT_MAX                      (0x0000FFFFU)

/* PCSR_ERROR_FIFO_REG */

#define CSL_CPSW9_PCSR_PCSR_ERROR_FIFO_REG_ERROR_FIFO_CTC_MASK                 (0x00000001U)
#define CSL_CPSW9_PCSR_PCSR_ERROR_FIFO_REG_ERROR_FIFO_CTC_SHIFT                (0x00000000U)
#define CSL_CPSW9_PCSR_PCSR_ERROR_FIFO_REG_ERROR_FIFO_CTC_MAX                  (0x00000001U)

/* P0_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_CHECKSUM_EN_MASK      (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_CHECKSUM_EN_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_CHECKSUM_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV4_EN_MASK        (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV4_EN_SHIFT       (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV4_EN_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV6_EN_MASK        (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV6_EN_SHIFT       (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_DSCP_IPV6_EN_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_TX_ECC_ERR_EN_MASK       (0x00004000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_TX_ECC_ERR_EN_SHIFT      (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_TX_ECC_ERR_EN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_ECC_ERR_EN_MASK       (0x00008000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_ECC_ERR_EN_SHIFT      (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_ECC_ERR_EN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_VLAN_MASK       (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_VLAN_SHIFT      (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_VLAN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V4_MASK    (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V4_SHIFT   (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V4_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V6_MASK    (0x00040000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V6_SHIFT   (0x00000012U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_CONTROL_REG_RX_REMAP_DSCP_V6_MAX     (0x00000001U)

/* P0_FLOW_ID_OFFSET_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FLOW_ID_OFFSET_REG_VALUE_MASK        (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FLOW_ID_OFFSET_REG_VALUE_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FLOW_ID_OFFSET_REG_VALUE_MAX         (0x00003FFFU)

/* P0_BLK_CNT_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_RX_BLK_CNT_MASK          (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_RX_BLK_CNT_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_RX_BLK_CNT_MAX           (0x0000003FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_TX_BLK_CNT_MASK          (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_TX_BLK_CNT_SHIFT         (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_BLK_CNT_REG_TX_BLK_CNT_MAX           (0x0000001FU)

/* P0_PORT_VLAN_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_VID_MASK          (0x00000FFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_VID_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_VID_MAX           (0x00000FFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_CFI_MASK          (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_CFI_SHIFT         (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_CFI_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_PRI_MASK          (0x0000E000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_PRI_SHIFT         (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PORT_VLAN_REG_PORT_PRI_MAX           (0x00000007U)

/* P0_TX_PRI_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI0_MASK             (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI0_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI0_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI1_MASK             (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI1_SHIFT            (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI1_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI2_MASK             (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI2_SHIFT            (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI2_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI3_MASK             (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI3_SHIFT            (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI3_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI4_MASK             (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI4_SHIFT            (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI4_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI5_MASK             (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI5_SHIFT            (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI5_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI6_MASK             (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI6_SHIFT            (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI6_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI7_MASK             (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI7_SHIFT            (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_PRI_MAP_REG_PRI7_MAX              (0x00000007U)

/* P0_PRI_CTL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_PTYPE_MASK            (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_PTYPE_SHIFT           (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_PTYPE_MAX             (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_FLOW_PRI_MASK         (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_FLOW_PRI_SHIFT        (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CTL_REG_RX_FLOW_PRI_MAX          (0x000000FFU)

/* P0_RX_PRI_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI0_MASK             (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI0_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI0_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI1_MASK             (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI1_SHIFT            (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI1_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI2_MASK             (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI2_SHIFT            (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI2_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI3_MASK             (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI3_SHIFT            (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI3_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI4_MASK             (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI4_SHIFT            (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI4_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI5_MASK             (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI5_SHIFT            (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI5_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI6_MASK             (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI6_SHIFT            (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI6_MAX              (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI7_MASK             (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI7_SHIFT            (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_PRI_MAP_REG_PRI7_MAX              (0x00000007U)

/* P0_RX_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_MAXLEN_REG_RX_MAXLEN_MASK         (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_MAXLEN_REG_RX_MAXLEN_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_MAXLEN_REG_RX_MAXLEN_MAX          (0x00003FFFU)

/* P0_TX_BLKS_PRI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI0_MASK            (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI0_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI0_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI1_MASK            (0x000000F0U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI1_SHIFT           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI1_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI2_MASK            (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI2_SHIFT           (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI2_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI3_MASK            (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI3_SHIFT           (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI3_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI4_MASK            (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI4_SHIFT           (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI4_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI5_MASK            (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI5_SHIFT           (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI5_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI6_MASK            (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI6_SHIFT           (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI6_MAX             (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI7_MASK            (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI7_SHIFT           (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_BLKS_PRI_REG_PRI7_MAX             (0x0000000FU)

/* P0_IDLE2LPI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_IDLE2LPI_REG_COUNT_MASK              (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_IDLE2LPI_REG_COUNT_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_IDLE2LPI_REG_COUNT_MAX               (0x00FFFFFFU)

/* P0_LPI2WAKE_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_LPI2WAKE_REG_COUNT_MASK              (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_LPI2WAKE_REG_COUNT_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_LPI2WAKE_REG_COUNT_MAX               (0x00FFFFFFU)

/* P0_EEE_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_MASK    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_LPI_MASK           (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_LPI_SHIFT          (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_LPI_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_LPI_MASK           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_LPI_SHIFT          (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_LPI_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_WAKE_MASK          (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_WAKE_SHIFT         (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_WAKE_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_HOLD_MASK     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_HOLD_SHIFT    (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_HOLD_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_MASK    (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_SHIFT   (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_MASK    (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_SHIFT   (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_MAX     (0x00000001U)

/* P0_FIFO_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FIFO_STATUS_REG_TX_PRI_ACTIVE_MASK   (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FIFO_STATUS_REG_TX_PRI_ACTIVE_SHIFT  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_FIFO_STATUS_REG_TX_PRI_ACTIVE_MAX    (0x000000FFU)

/* P0_RX_DSCP_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI0_MASK            (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI0_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI0_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI1_MASK            (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI1_SHIFT           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI1_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI2_MASK            (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI2_SHIFT           (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI2_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI3_MASK            (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI3_SHIFT           (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI3_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI4_MASK            (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI4_SHIFT           (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI4_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI5_MASK            (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI5_SHIFT           (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI5_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI6_MASK            (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI6_SHIFT           (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI6_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI7_MASK            (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI7_SHIFT           (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_RX_DSCP_MAP_REG_PRI7_MAX             (0x00000007U)

/* P0_PRI_CIR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CIR_REG_PRI_CIR_MASK             (0x0FFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CIR_REG_PRI_CIR_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_CIR_REG_PRI_CIR_MAX              (0x0FFFFFFFU)

/* P0_PRI_EIR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_EIR_REG_PRI_EIR_MASK             (0x0FFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_EIR_REG_PRI_EIR_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_PRI_EIR_REG_PRI_EIR_MAX              (0x0FFFFFFFU)

/* P0_TX_D_THRESH_SET_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI0_MASK      (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI0_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI0_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI1_MASK      (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI1_SHIFT     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI1_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI2_MASK      (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI2_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI2_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI3_MASK      (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI3_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_L_REG_PRI3_MAX       (0x0000001FU)

/* P0_TX_D_THRESH_SET_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI4_MASK      (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI4_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI4_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI5_MASK      (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI5_SHIFT     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI5_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI6_MASK      (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI6_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI6_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI7_MASK      (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI7_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_SET_H_REG_PRI7_MAX       (0x0000001FU)

/* P0_TX_D_THRESH_CLR_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI0_MASK      (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI0_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI0_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI1_MASK      (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI1_SHIFT     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI1_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI2_MASK      (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI2_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI2_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI3_MASK      (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI3_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_L_REG_PRI3_MAX       (0x0000001FU)

/* P0_TX_D_THRESH_CLR_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI4_MASK      (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI4_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI4_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI5_MASK      (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI5_SHIFT     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI5_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI6_MASK      (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI6_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI6_MAX       (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI7_MASK      (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI7_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_D_THRESH_CLR_H_REG_PRI7_MAX       (0x0000001FU)

/* P0_TX_G_BUF_THRESH_SET_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI0_MASK  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI0_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI0_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI1_MASK  (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI1_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI1_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI2_MASK  (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI2_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI2_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI3_MASK  (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI3_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_L_REG_PRI3_MAX   (0x0000001FU)

/* P0_TX_G_BUF_THRESH_SET_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI4_MASK  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI4_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI4_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI5_MASK  (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI5_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI5_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI6_MASK  (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI6_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI6_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI7_MASK  (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI7_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_SET_H_REG_PRI7_MAX   (0x0000001FU)

/* P0_TX_G_BUF_THRESH_CLR_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MASK  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI0_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MASK  (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI1_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MASK  (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI2_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MASK  (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI3_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MAX   (0x0000001FU)

/* P0_TX_G_BUF_THRESH_CLR_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MASK  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI4_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MASK  (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI5_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MASK  (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI6_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MAX   (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MASK  (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI7_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MAX   (0x0000001FU)

/* P0_SRC_ID_A_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT1_MASK              (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT1_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT1_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT2_MASK              (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT2_SHIFT             (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT2_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT3_MASK              (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT3_SHIFT             (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT3_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT4_MASK              (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT4_SHIFT             (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_A_REG_PORT4_MAX               (0x000000FFU)

/* P0_SRC_ID_B_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT5_MASK              (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT5_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT5_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT6_MASK              (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT6_SHIFT             (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT6_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT7_MASK              (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT7_SHIFT             (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT7_MAX               (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT8_MASK              (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT8_SHIFT             (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_SRC_ID_B_REG_PORT8_MAX               (0x000000FFU)

/* P0_HOST_BLKS_PRI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI0_MASK          (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI0_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI0_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI1_MASK          (0x000000F0U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI1_SHIFT         (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI1_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI2_MASK          (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI2_SHIFT         (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI2_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI3_MASK          (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI3_SHIFT         (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI3_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI4_MASK          (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI4_SHIFT         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI4_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI5_MASK          (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI5_SHIFT         (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI5_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI6_MASK          (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI6_SHIFT         (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI6_MAX           (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI7_MASK          (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI7_SHIFT         (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_CPPI_P0_HOST_BLKS_PRI_REG_PRI7_MAX           (0x0000000FU)

/* PN_RESERVED_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RESERVED_REG_RESERVED_MASK          (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RESERVED_REG_RESERVED_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RESERVED_REG_RESERVED_MAX           (0xFFFFFFFFU)

/* PN_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV4_EN_MASK       (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV4_EN_SHIFT      (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV4_EN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV6_EN_MASK       (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV6_EN_SHIFT      (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_DSCP_IPV6_EN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_MASK  (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_SHIFT (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_ECC_ERR_EN_MASK      (0x00004000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_ECC_ERR_EN_SHIFT     (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_TX_ECC_ERR_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_RX_ECC_ERR_EN_MASK      (0x00008000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_RX_ECC_ERR_EN_SHIFT     (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_RX_ECC_ERR_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_IET_PORT_EN_MASK        (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_IET_PORT_EN_SHIFT       (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_IET_PORT_EN_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_EST_PORT_EN_MASK        (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_EST_PORT_EN_SHIFT       (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_CONTROL_REG_EST_PORT_EN_MAX         (0x00000001U)

/* PN_MAX_BLKS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_RX_MAX_BLKS_MASK       (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_RX_MAX_BLKS_SHIFT      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_RX_MAX_BLKS_MAX        (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_TX_MAX_BLKS_MASK       (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_TX_MAX_BLKS_SHIFT      (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAX_BLKS_REG_TX_MAX_BLKS_MAX        (0x000000FFU)

/* PN_BLK_CNT_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_E_MASK       (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_E_SHIFT      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_E_MAX        (0x0000003FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_TX_BLK_CNT_MASK         (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_TX_BLK_CNT_SHIFT        (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_TX_BLK_CNT_MAX          (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_P_MASK       (0x003F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_P_SHIFT      (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_BLK_CNT_REG_RX_BLK_CNT_P_MAX        (0x0000003FU)

/* PN_PORT_VLAN_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_VID_MASK         (0x00000FFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_VID_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_VID_MAX          (0x00000FFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_CFI_MASK         (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_CFI_SHIFT        (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_CFI_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_PRI_MASK         (0x0000E000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_PRI_SHIFT        (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PORT_VLAN_REG_PORT_PRI_MAX          (0x00000007U)

/* PN_TX_PRI_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI0_MASK            (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI0_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI0_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI1_MASK            (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI1_SHIFT           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI1_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI2_MASK            (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI2_SHIFT           (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI2_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI3_MASK            (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI3_SHIFT           (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI3_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI4_MASK            (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI4_SHIFT           (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI4_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI5_MASK            (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI5_SHIFT           (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI5_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI6_MASK            (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI6_SHIFT           (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI6_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI7_MASK            (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI7_SHIFT           (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_PRI_MAP_REG_PRI7_MAX             (0x00000007U)

/* PN_PRI_CTL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_MASK   (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_SHIFT  (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_MAX    (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_RX_FLOW_PRI_MASK        (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_RX_FLOW_PRI_SHIFT       (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_RX_FLOW_PRI_MAX         (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_FLOW_PRI_MASK        (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_FLOW_PRI_SHIFT       (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CTL_REG_TX_FLOW_PRI_MAX         (0x000000FFU)

/* PN_RX_PRI_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI0_MASK            (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI0_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI0_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI1_MASK            (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI1_SHIFT           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI1_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI2_MASK            (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI2_SHIFT           (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI2_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI3_MASK            (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI3_SHIFT           (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI3_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI4_MASK            (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI4_SHIFT           (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI4_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI5_MASK            (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI5_SHIFT           (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI5_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI6_MASK            (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI6_SHIFT           (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI6_MAX             (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI7_MASK            (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI7_SHIFT           (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_PRI_MAP_REG_PRI7_MAX             (0x00000007U)

/* PN_RX_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_MAXLEN_REG_RX_MAXLEN_MASK        (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_MAXLEN_REG_RX_MAXLEN_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_MAXLEN_REG_RX_MAXLEN_MAX         (0x00003FFFU)

/* PN_TX_BLKS_PRI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI0_MASK           (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI0_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI0_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI1_MASK           (0x000000F0U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI1_SHIFT          (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI1_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI2_MASK           (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI2_SHIFT          (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI2_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI3_MASK           (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI3_SHIFT          (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI3_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI4_MASK           (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI4_SHIFT          (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI4_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI5_MASK           (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI5_SHIFT          (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI5_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI6_MASK           (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI6_SHIFT          (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI6_MAX            (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI7_MASK           (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI7_SHIFT          (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_BLKS_PRI_REG_PRI7_MAX            (0x0000000FU)

/* PN_IDLE2LPI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IDLE2LPI_REG_COUNT_MASK             (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IDLE2LPI_REG_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IDLE2LPI_REG_COUNT_MAX              (0x00FFFFFFU)

/* PN_LPI2WAKE_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_LPI2WAKE_REG_COUNT_MASK             (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_LPI2WAKE_REG_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_LPI2WAKE_REG_COUNT_MAX              (0x00FFFFFFU)

/* PN_EEE_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_MASK   (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_SHIFT  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_MAX    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_LPI_MASK          (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_LPI_SHIFT         (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_LPI_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_LPI_MASK          (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_LPI_SHIFT         (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_LPI_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_WAKE_MASK         (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_WAKE_SHIFT        (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_WAKE_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_HOLD_MASK    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_HOLD_SHIFT   (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_HOLD_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_MASK   (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_SHIFT  (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_MAX    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_MASK   (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_SHIFT  (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_MAX    (0x00000001U)

/* PN_IET_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PENABLE_MASK    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PENABLE_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PENABLE_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_HOLD_MASK       (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_HOLD_SHIFT      (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_HOLD_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_DISABLEVERIFY_MASK (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_DISABLEVERIFY_SHIFT (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_DISABLEVERIFY_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_LINKFAIL_MASK   (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_LINKFAIL_SHIFT  (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_LINKFAIL_MAX    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_ADDFRAGSIZE_MASK (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_ADDFRAGSIZE_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_ADDFRAGSIZE_MAX (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PREMPT_MASK     (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PREMPT_SHIFT    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_CONTROL_REG_MAC_PREMPT_MAX      (0x000000FFU)

/* PN_IET_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFIED_MASK    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFIED_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFIED_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_FAIL_MASK (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_FAIL_SHIFT (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_FAIL_MAX  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_RESPOND_ERR_MASK (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_RESPOND_ERR_SHIFT (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_RESPOND_ERR_MAX  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_ERR_MASK  (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_ERR_SHIFT (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_STATUS_REG_MAC_VERIFY_ERR_MAX   (0x00000001U)

/* PN_IET_VERIFY_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_VERIFY_REG_MAC_VERIFY_CNT_MASK  (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_VERIFY_REG_MAC_VERIFY_CNT_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_IET_VERIFY_REG_MAC_VERIFY_CNT_MAX   (0x00FFFFFFU)

/* PN_FIFO_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_PRI_ACTIVE_MASK  (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_PRI_ACTIVE_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_PRI_ACTIVE_MAX   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_E_MAC_ALLOW_MASK (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_E_MAC_ALLOW_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_TX_E_MAC_ALLOW_MAX  (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_CNT_ERR_MASK    (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_CNT_ERR_SHIFT   (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_CNT_ERR_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_ADD_ERR_MASK    (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_ADD_ERR_SHIFT   (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_ADD_ERR_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_BUFACT_MASK     (0x00040000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_BUFACT_SHIFT    (0x00000012U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_FIFO_STATUS_REG_EST_BUFACT_MAX      (0x00000001U)

/* PN_EST_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_ONEBUF_MASK     (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_ONEBUF_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_ONEBUF_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_BUFSEL_MASK     (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_BUFSEL_SHIFT    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_BUFSEL_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_EN_MASK      (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_EN_SHIFT     (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_FIRST_MASK   (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_FIRST_SHIFT  (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_FIRST_MAX    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_ONEPRI_MASK  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_ONEPRI_SHIFT (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_ONEPRI_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_PRI_MASK     (0x000000E0U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_PRI_SHIFT    (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_TS_PRI_MAX      (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_EN_MASK    (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_EN_SHIFT   (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_MARGIN_MASK (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_MARGIN_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_EST_CONTROL_REG_EST_FILL_MARGIN_MAX (0x000003FFU)

/* PN_RX_DSCP_MAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI0_MASK           (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI0_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI0_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI1_MASK           (0x00000070U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI1_SHIFT          (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI1_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI2_MASK           (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI2_SHIFT          (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI2_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI3_MASK           (0x00007000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI3_SHIFT          (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI3_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI4_MASK           (0x00070000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI4_SHIFT          (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI4_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI5_MASK           (0x00700000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI5_SHIFT          (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI5_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI6_MASK           (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI6_SHIFT          (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI6_MAX            (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI7_MASK           (0x70000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI7_SHIFT          (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_RX_DSCP_MAP_REG_PRI7_MAX            (0x00000007U)

/* PN_PRI_CIR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CIR_REG_PRI_CIR_MASK            (0x0FFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CIR_REG_PRI_CIR_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_CIR_REG_PRI_CIR_MAX             (0x0FFFFFFFU)

/* PN_PRI_EIR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_EIR_REG_PRI_EIR_MASK            (0x0FFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_EIR_REG_PRI_EIR_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_PRI_EIR_REG_PRI_EIR_MAX             (0x0FFFFFFFU)

/* PN_TX_D_THRESH_SET_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI0_MASK     (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI0_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI0_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI1_MASK     (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI1_SHIFT    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI1_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI2_MASK     (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI2_SHIFT    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI2_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI3_MASK     (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI3_SHIFT    (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_L_REG_PRI3_MAX      (0x0000001FU)

/* PN_TX_D_THRESH_SET_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI4_MASK     (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI4_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI4_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI5_MASK     (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI5_SHIFT    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI5_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI6_MASK     (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI6_SHIFT    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI6_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI7_MASK     (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI7_SHIFT    (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_SET_H_REG_PRI7_MAX      (0x0000001FU)

/* PN_TX_D_THRESH_CLR_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI0_MASK     (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI0_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI0_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI1_MASK     (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI1_SHIFT    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI1_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI2_MASK     (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI2_SHIFT    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI2_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI3_MASK     (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI3_SHIFT    (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_L_REG_PRI3_MAX      (0x0000001FU)

/* PN_TX_D_THRESH_CLR_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI4_MASK     (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI4_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI4_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI5_MASK     (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI5_SHIFT    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI5_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI6_MASK     (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI6_SHIFT    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI6_MAX      (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI7_MASK     (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI7_SHIFT    (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_THRESH_CLR_H_REG_PRI7_MAX      (0x0000001FU)

/* PN_TX_G_BUF_THRESH_SET_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI0_MASK (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI0_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI0_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI1_MASK (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI1_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI1_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI2_MASK (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI2_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI2_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI3_MASK (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI3_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_L_REG_PRI3_MAX  (0x0000001FU)

/* PN_TX_G_BUF_THRESH_SET_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI4_MASK (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI4_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI4_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI5_MASK (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI5_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI5_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI6_MASK (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI6_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI6_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI7_MASK (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI7_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_SET_H_REG_PRI7_MAX  (0x0000001FU)

/* PN_TX_G_BUF_THRESH_CLR_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MASK (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI0_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MASK (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI1_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MASK (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI2_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MASK (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI3_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MAX  (0x0000001FU)

/* PN_TX_G_BUF_THRESH_CLR_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MASK (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI4_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MASK (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI5_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MASK (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI6_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MAX  (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MASK (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI7_SHIFT (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MAX  (0x0000001FU)

/* PN_TX_D_OFLOW_ADDVAL_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI0_MASK   (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI0_SHIFT  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI0_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI1_MASK   (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI1_SHIFT  (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI1_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI2_MASK   (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI2_SHIFT  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI2_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI3_MASK   (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI3_SHIFT  (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_L_REG_PRI3_MAX    (0x0000001FU)

/* PN_TX_D_OFLOW_ADDVAL_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI4_MASK   (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI4_SHIFT  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI4_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI5_MASK   (0x00001F00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI5_SHIFT  (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI5_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI6_MASK   (0x001F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI6_SHIFT  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI6_MAX    (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI7_MASK   (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI7_SHIFT  (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TX_D_OFLOW_ADDVAL_H_REG_PRI7_MAX    (0x0000001FU)

/* PN_SA_L_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_15_8_MASK       (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_15_8_SHIFT      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_15_8_MAX        (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_7_0_MASK        (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_7_0_SHIFT       (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_L_REG_MACSRCADDR_7_0_MAX         (0x000000FFU)

/* PN_SA_H_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_47_40_MASK      (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_47_40_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_47_40_MAX       (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_39_32_MASK      (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_39_32_SHIFT     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_39_32_MAX       (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_31_24_MASK      (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_31_24_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_31_24_MAX       (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_23_16_MASK      (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_23_16_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_SA_H_REG_MACSRCADDR_23_16_MAX       (0x000000FFU)

/* PN_TS_CTL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_MASK    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_MASK (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_SHIFT (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_MASK (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_SHIFT (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_MASK    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_SHIFT   (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_MASK    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_SHIFT   (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_MASK (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_SHIFT (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_MASK (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_SHIFT (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_MASK    (0x00000080U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_SHIFT   (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_LTYPE2_EN_MASK        (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_LTYPE2_EN_SHIFT       (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_LTYPE2_EN_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_MASK    (0x00000200U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_SHIFT   (0x00000009U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_MASK    (0x00000400U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_SHIFT   (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_MASK    (0x00000800U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_SHIFT   (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_MSG_TYPE_EN_MASK      (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_MSG_TYPE_EN_SHIFT     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_REG_TS_MSG_TYPE_EN_MAX       (0x0000FFFFU)

/* PN_TS_SEQ_LTYPE_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_MASK     (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_MAX      (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_MASK (0x003F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_MAX (0x0000003FU)

/* PN_TS_VLAN_LTYPE_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_MAX (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_MASK (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_MAX (0x0000FFFFU)

/* PN_TS_CTL_LTYPE2_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_MASK    (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_MAX     (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_107_MASK       (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_107_SHIFT      (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_107_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_129_MASK       (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_129_SHIFT      (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_129_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_130_MASK       (0x00040000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_130_SHIFT      (0x00000012U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_130_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_131_MASK       (0x00080000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_131_SHIFT      (0x00000013U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_131_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_132_MASK       (0x00100000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_132_SHIFT      (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_132_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_319_MASK       (0x00200000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_319_SHIFT      (0x00000015U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_319_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_320_MASK       (0x00400000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_320_SHIFT      (0x00000016U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_320_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_MASK (0x00800000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_SHIFT (0x00000017U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_MASK    (0x01000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_SHIFT   (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_MAX     (0x00000001U)

/* PN_TS_CTL2_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_MASK   (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_SHIFT  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_MAX    (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_MASK   (0x003F0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_SHIFT  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_MAX    (0x0000003FU)

/* PN_MAC_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_FULLDUPLEX_MASK     (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_FULLDUPLEX_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_FULLDUPLEX_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_LOOPBACK_MASK       (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_LOOPBACK_SHIFT      (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_LOOPBACK_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_MTEST_MASK          (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_MTEST_SHIFT         (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_MTEST_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_FLOW_EN_MASK     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_FLOW_EN_SHIFT    (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_FLOW_EN_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_FLOW_EN_MASK     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_FLOW_EN_SHIFT    (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_FLOW_EN_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GMII_EN_MASK        (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GMII_EN_SHIFT       (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GMII_EN_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_PACE_MASK        (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_PACE_SHIFT       (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_PACE_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_MASK            (0x00000080U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_SHIFT           (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_MAX             (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGIG_MASK           (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGIG_SHIFT          (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGIG_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_ENABLE_MASK (0x00000400U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_ENABLE_SHIFT (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_ENABLE_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CMD_IDLE_MASK       (0x00000800U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CMD_IDLE_SHIFT      (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CMD_IDLE_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CRC_TYPE_MASK       (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CRC_TYPE_SHIFT      (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_CRC_TYPE_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGMII_EN_MASK       (0x00002000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGMII_EN_SHIFT      (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_XGMII_EN_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_A_MASK        (0x00008000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_A_SHIFT       (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_A_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_B_MASK        (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_B_SHIFT       (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_IFCTL_B_MAX         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_FORCE_MASK      (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_FORCE_SHIFT     (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_GIG_FORCE_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_MASK         (0x00040000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_SHIFT        (0x00000012U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_MASK (0x00080000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_SHIFT (0x00000013U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_MAX  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_MASK (0x00100000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_SHIFT (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_MAX  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_LIM_EN_MASK (0x00200000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_LIM_EN_SHIFT (0x00000015U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_TX_SHORT_GAP_LIM_EN_MAX (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CEF_EN_MASK      (0x00400000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CEF_EN_SHIFT     (0x00000016U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CEF_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CSF_EN_MASK      (0x00800000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CSF_EN_SHIFT     (0x00000017U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CSF_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CMF_EN_MASK      (0x01000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CMF_EN_SHIFT     (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_RX_CMF_EN_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_XGIG_MASK    (0x02000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_XGIG_SHIFT   (0x00000019U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_CONTROL_REG_EXT_EN_XGIG_MAX     (0x00000001U)

/* PN_MAC_STATUS_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_FLOW_ACT_MASK     (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_FLOW_ACT_SHIFT    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_FLOW_ACT_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_FLOW_ACT_MASK     (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_FLOW_ACT_SHIFT    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_FLOW_ACT_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_MASK  (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_SHIFT (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_GIG_MASK         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_GIG_SHIFT        (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_GIG_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_MASK  (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_SHIFT (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_MASK  (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_SHIFT (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_PFC_FLOW_ACT_MASK (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_PFC_FLOW_ACT_SHIFT (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_RX_PFC_FLOW_ACT_MAX  (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_PFC_FLOW_ACT_MASK (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_PFC_FLOW_ACT_SHIFT (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TX_PFC_FLOW_ACT_MAX  (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_PRI_MASK        (0x07000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_PRI_SHIFT       (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_PRI_MAX         (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_MASK            (0x08000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_SHIFT           (0x0000001BU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_TORF_MAX             (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_MAC_TX_IDLE_MASK     (0x10000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_MAC_TX_IDLE_SHIFT    (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_MAC_TX_IDLE_MAX      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_P_IDLE_MASK          (0x20000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_P_IDLE_SHIFT         (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_P_IDLE_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_E_IDLE_MASK          (0x40000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_E_IDLE_SHIFT         (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_E_IDLE_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_IDLE_MASK            (0x80000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_IDLE_SHIFT           (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_STATUS_REG_IDLE_MAX             (0x00000001U)

/* PN_MAC_SOFT_RESET_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_SOFT_RESET_REG_SOFT_RESET_MASK  (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_SOFT_RESET_REG_SOFT_RESET_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_SOFT_RESET_REG_SOFT_RESET_MAX   (0x00000001U)

/* PN_MAC_BOFFTEST_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_TX_BACKOFF_MASK    (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_TX_BACKOFF_SHIFT   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_TX_BACKOFF_MAX     (0x000003FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_COLL_COUNT_MASK    (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_COLL_COUNT_SHIFT   (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_COLL_COUNT_MAX     (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_RNDNUM_MASK        (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_RNDNUM_SHIFT       (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_RNDNUM_MAX         (0x000003FFU)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_PACEVAL_MASK       (0x7C000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_PACEVAL_SHIFT      (0x0000001AU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_BOFFTEST_REG_PACEVAL_MAX        (0x0000001FU)

/* PN_MAC_RX_PAUSETIMER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_MAX (0x0000FFFFU)

/* PN_MAC_RXN_PAUSETIMER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RXN_PAUSETIMER_REG_RX_PAUSETIMER_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RXN_PAUSETIMER_REG_RX_PAUSETIMER_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_RXN_PAUSETIMER_REG_RX_PAUSETIMER_MAX (0x0000FFFFU)

/* PN_MAC_TX_PAUSETIMER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_MAX (0x0000FFFFU)

/* PN_MAC_TXN_PAUSETIMER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TXN_PAUSETIMER_REG_TX_PAUSETIMER_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TXN_PAUSETIMER_REG_TX_PAUSETIMER_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TXN_PAUSETIMER_REG_TX_PAUSETIMER_MAX (0x0000FFFFU)

/* PN_MAC_EMCONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_FREE_MASK         (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_FREE_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_FREE_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_SOFT_MASK         (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_SOFT_SHIFT        (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_EMCONTROL_REG_SOFT_MAX          (0x00000001U)

/* PN_MAC_TX_GAP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_GAP_REG_TX_GAP_MASK          (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_GAP_REG_TX_GAP_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_MAC_TX_GAP_REG_TX_GAP_MAX           (0x0000FFFFU)

/* PN_INTERVLAN_OPX_POINTER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_POINTER_REG_INTERVLAN_OPX_POINTER_MASK (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_POINTER_REG_INTERVLAN_OPX_POINTER_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_POINTER_REG_INTERVLAN_OPX_POINTER_MAX (0x00000007U)

/* PN_INTERVLAN_OPX_A_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_A_REG_INTERVLAN_OPX_A_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_A_REG_INTERVLAN_OPX_A_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_A_REG_INTERVLAN_OPX_A_MAX (0xFFFFFFFFU)

/* PN_INTERVLAN_OPX_B_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_B_REG_INTERVLAN_OPX_B_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_B_REG_INTERVLAN_OPX_B_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_B_REG_INTERVLAN_OPX_B_MAX (0xFFFFFFFFU)

/* PN_INTERVLAN_OPX_C_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_C_REG_INTERVLAN_OPX_C_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_C_REG_INTERVLAN_OPX_C_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_C_REG_INTERVLAN_OPX_C_MAX (0xFFFFFFFFU)

/* PN_INTERVLAN_OPX_D_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_D_REG_INTERVLAN_OPX_D_MASK (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_D_REG_INTERVLAN_OPX_D_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_ETH_MAC_PN_INTERVLAN_OPX_D_REG_INTERVLAN_OPX_D_MAX (0x0000FFFFU)

/* FETCH_LOC */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_EST_FETCH_LOC_LOC_MASK                       (0x003FFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_EST_FETCH_LOC_LOC_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_EST_FETCH_LOC_LOC_MAX                        (0x003FFFFFU)

/* RXGOODFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXGOODFRAMES_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXGOODFRAMES_COUNT_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXGOODFRAMES_COUNT_MAX                  (0xFFFFFFFFU)

/* RXBROADCASTFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXBROADCASTFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXBROADCASTFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXBROADCASTFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* RXMULTICASTFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXMULTICASTFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXMULTICASTFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXMULTICASTFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* RXPAUSEFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXPAUSEFRAMES_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXPAUSEFRAMES_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXPAUSEFRAMES_COUNT_MAX                 (0xFFFFFFFFU)

/* RXCRCERRORS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXCRCERRORS_COUNT_MASK                  (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXCRCERRORS_COUNT_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXCRCERRORS_COUNT_MAX                   (0xFFFFFFFFU)

/* RXALIGNCODEERRORS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXALIGNCODEERRORS_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXALIGNCODEERRORS_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXALIGNCODEERRORS_COUNT_MAX             (0xFFFFFFFFU)

/* RXOVERSIZEDFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOVERSIZEDFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOVERSIZEDFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOVERSIZEDFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* RXJABBERFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXJABBERFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXJABBERFRAMES_COUNT_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXJABBERFRAMES_COUNT_MAX                (0xFFFFFFFFU)

/* RXUNDERSIZEDFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXUNDERSIZEDFRAMES_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXUNDERSIZEDFRAMES_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXUNDERSIZEDFRAMES_COUNT_MAX            (0xFFFFFFFFU)

/* RXFRAGMENTS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXFRAGMENTS_COUNT_MASK                  (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXFRAGMENTS_COUNT_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXFRAGMENTS_COUNT_MAX                   (0xFFFFFFFFU)

/* ALE_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DROP_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DROP_COUNT_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DROP_COUNT_MAX                      (0xFFFFFFFFU)

/* ALE_OVERRUN_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_OVERRUN_DROP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_OVERRUN_DROP_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_OVERRUN_DROP_COUNT_MAX              (0xFFFFFFFFU)

/* RXOCTETS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOCTETS_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOCTETS_COUNT_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXOCTETS_COUNT_MAX                      (0xFFFFFFFFU)

/* TXGOODFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXGOODFRAMES_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXGOODFRAMES_COUNT_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXGOODFRAMES_COUNT_MAX                  (0xFFFFFFFFU)

/* TXBROADCASTFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXBROADCASTFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXBROADCASTFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXBROADCASTFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* TXMULTICASTFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTICASTFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTICASTFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTICASTFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* TXPAUSEFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXPAUSEFRAMES_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXPAUSEFRAMES_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXPAUSEFRAMES_COUNT_MAX                 (0xFFFFFFFFU)

/* TXDEFERREDFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXDEFERREDFRAMES_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXDEFERREDFRAMES_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXDEFERREDFRAMES_COUNT_MAX              (0xFFFFFFFFU)

/* TXCOLLISIONFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCOLLISIONFRAMES_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCOLLISIONFRAMES_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCOLLISIONFRAMES_COUNT_MAX             (0xFFFFFFFFU)

/* TXSINGLECOLLFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXSINGLECOLLFRAMES_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXSINGLECOLLFRAMES_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXSINGLECOLLFRAMES_COUNT_MAX            (0xFFFFFFFFU)

/* TXMULTCOLLFRAMES */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTCOLLFRAMES_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTCOLLFRAMES_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXMULTCOLLFRAMES_COUNT_MAX              (0xFFFFFFFFU)

/* TXEXCESSIVECOLLISIONS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXEXCESSIVECOLLISIONS_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXEXCESSIVECOLLISIONS_COUNT_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXEXCESSIVECOLLISIONS_COUNT_MAX         (0xFFFFFFFFU)

/* TXLATECOLLISIONS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXLATECOLLISIONS_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXLATECOLLISIONS_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXLATECOLLISIONS_COUNT_MAX              (0xFFFFFFFFU)

/* RXIPGERROR */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXIPGERROR_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXIPGERROR_COUNT_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RXIPGERROR_COUNT_MAX                    (0xFFFFFFFFU)

/* TXCARRIERSENSEERRORS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCARRIERSENSEERRORS_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCARRIERSENSEERRORS_COUNT_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXCARRIERSENSEERRORS_COUNT_MAX          (0xFFFFFFFFU)

/* TXOCTETS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXOCTETS_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXOCTETS_COUNT_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TXOCTETS_COUNT_MAX                      (0xFFFFFFFFU)

/* OCTETFRAMES64 */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES64_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES64_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES64_COUNT_MAX                 (0xFFFFFFFFU)

/* OCTETFRAMES65T127 */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES65T127_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES65T127_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES65T127_COUNT_MAX             (0xFFFFFFFFU)

/* OCTETFRAMES128T255 */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES128T255_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES128T255_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES128T255_COUNT_MAX            (0xFFFFFFFFU)

/* OCTETFRAMES256T511 */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES256T511_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES256T511_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES256T511_COUNT_MAX            (0xFFFFFFFFU)

/* OCTETFRAMES512T1023 */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES512T1023_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES512T1023_COUNT_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES512T1023_COUNT_MAX           (0xFFFFFFFFU)

/* OCTETFRAMES1024TUP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES1024TUP_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES1024TUP_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_OCTETFRAMES1024TUP_COUNT_MAX            (0xFFFFFFFFU)

/* NETOCTETS */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_NETOCTETS_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_NETOCTETS_COUNT_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_NETOCTETS_COUNT_MAX                     (0xFFFFFFFFU)

/* RX_BOTTOM_OF_FIFO_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_BOTTOM_OF_FIFO_DROP_COUNT_MASK       (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_BOTTOM_OF_FIFO_DROP_COUNT_SHIFT      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_BOTTOM_OF_FIFO_DROP_COUNT_MAX        (0xFFFFFFFFU)

/* PORTMASK_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_PORTMASK_DROP_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_PORTMASK_DROP_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_PORTMASK_DROP_COUNT_MAX                 (0xFFFFFFFFU)

/* RX_TOP_OF_FIFO_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_TOP_OF_FIFO_DROP_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_TOP_OF_FIFO_DROP_COUNT_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_RX_TOP_OF_FIFO_DROP_COUNT_MAX           (0xFFFFFFFFU)

/* ALE_RATE_LIMIT_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_RATE_LIMIT_DROP_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_RATE_LIMIT_DROP_COUNT_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_RATE_LIMIT_DROP_COUNT_MAX           (0xFFFFFFFFU)

/* ALE_VID_INGRESS_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_VID_INGRESS_DROP_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_VID_INGRESS_DROP_COUNT_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_VID_INGRESS_DROP_COUNT_MAX          (0xFFFFFFFFU)

/* ALE_DA_EQ_SA_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DA_EQ_SA_DROP_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DA_EQ_SA_DROP_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DA_EQ_SA_DROP_COUNT_MAX             (0xFFFFFFFFU)

/* ALE_BLOCK_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_BLOCK_DROP_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_BLOCK_DROP_COUNT_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_BLOCK_DROP_COUNT_MAX                (0xFFFFFFFFU)

/* ALE_SECURE_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_SECURE_DROP_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_SECURE_DROP_COUNT_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_SECURE_DROP_COUNT_MAX               (0xFFFFFFFFU)

/* ALE_AUTH_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_AUTH_DROP_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_AUTH_DROP_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_AUTH_DROP_COUNT_MAX                 (0xFFFFFFFFU)

/* ALE_UNKN_UNI */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_COUNT_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_COUNT_MAX                  (0xFFFFFFFFU)

/* ALE_UNKN_UNI_BCNT */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_BCNT_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_BCNT_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_UNI_BCNT_COUNT_MAX             (0xFFFFFFFFU)

/* ALE_UNKN_MLT */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_COUNT_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_COUNT_MAX                  (0xFFFFFFFFU)

/* ALE_UNKN_MLT_BCNT */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_BCNT_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_BCNT_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_MLT_BCNT_COUNT_MAX             (0xFFFFFFFFU)

/* ALE_UNKN_BRD */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_COUNT_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_COUNT_MAX                  (0xFFFFFFFFU)

/* ALE_UNKN_BRD_BCNT */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_BCNT_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_BCNT_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_UNKN_BRD_BCNT_COUNT_MAX             (0xFFFFFFFFU)

/* ALE_POL_MATCH */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_COUNT_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_COUNT_MAX                 (0xFFFFFFFFU)

/* ALE_POL_MATCH_RED */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_RED_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_RED_COUNT_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_RED_COUNT_MAX             (0xFFFFFFFFU)

/* ALE_POL_MATCH_YELLOW */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_YELLOW_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_YELLOW_COUNT_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_POL_MATCH_YELLOW_COUNT_MAX          (0xFFFFFFFFU)

/* ALE_MULT_SA_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_MULT_SA_DROP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_MULT_SA_DROP_COUNT_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_MULT_SA_DROP_COUNT_MAX              (0xFFFFFFFFU)

/* ALE_DUAL_VLAN_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DUAL_VLAN_DROP_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DUAL_VLAN_DROP_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_DUAL_VLAN_DROP_COUNT_MAX            (0xFFFFFFFFU)

/* ALE_LEN_ERROR_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_LEN_ERROR_DROP_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_LEN_ERROR_DROP_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_LEN_ERROR_DROP_COUNT_MAX            (0xFFFFFFFFU)

/* ALE_IP_NEXT_HDR_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IP_NEXT_HDR_DROP_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IP_NEXT_HDR_DROP_COUNT_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IP_NEXT_HDR_DROP_COUNT_MAX          (0xFFFFFFFFU)

/* ALE_IPV4_FRAG_DROP */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IPV4_FRAG_DROP_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IPV4_FRAG_DROP_COUNT_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ALE_IPV4_FRAG_DROP_COUNT_MAX            (0xFFFFFFFFU)

/* IET_RX_ASSEMBLY_ERROR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_ERROR_REG_IET_RX_ASSEMBLY_ERROR_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_ERROR_REG_IET_RX_ASSEMBLY_ERROR_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_ERROR_REG_IET_RX_ASSEMBLY_ERROR_MAX (0xFFFFFFFFU)

/* IET_RX_ASSEMBLY_OK_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_OK_REG_IET_RX_ASSEMBLY_OK_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_OK_REG_IET_RX_ASSEMBLY_OK_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_ASSEMBLY_OK_REG_IET_RX_ASSEMBLY_OK_MAX (0xFFFFFFFFU)

/* IET_RX_SMD_ERROR_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_SMD_ERROR_REG_IET_RX_SMD_ERROR_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_SMD_ERROR_REG_IET_RX_SMD_ERROR_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_SMD_ERROR_REG_IET_RX_SMD_ERROR_MAX (0xFFFFFFFFU)

/* IET_RX_FRAG_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_FRAG_REG_IET_RX_FRAG_MASK        (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_FRAG_REG_IET_RX_FRAG_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_RX_FRAG_REG_IET_RX_FRAG_MAX         (0xFFFFFFFFU)

/* IET_TX_HOLD_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_HOLD_REG_IET_TX_HOLD_MASK        (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_HOLD_REG_IET_TX_HOLD_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_HOLD_REG_IET_TX_HOLD_MAX         (0xFFFFFFFFU)

/* IET_TX_FRAG_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_FRAG_REG_IET_TX_FRAG_MASK        (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_FRAG_REG_IET_TX_FRAG_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_IET_TX_FRAG_REG_IET_TX_FRAG_MAX         (0xFFFFFFFFU)

/* TX_MEMORY_PROTECT_ERROR */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TX_MEMORY_PROTECT_ERROR_COUNT_MASK      (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TX_MEMORY_PROTECT_ERROR_COUNT_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_TX_MEMORY_PROTECT_ERROR_COUNT_MAX       (0x000000FFU)

/* ENET_PN_TX_PRI_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_REG_PN_TX_PRIN_MASK      (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_REG_PN_TX_PRIN_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_REG_PN_TX_PRIN_MAX       (0xFFFFFFFFU)

/* ENET_PN_TX_PRI_BCNT_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_BCNT_REG_PN_TX_PRIN_BCNT_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_BCNT_REG_PN_TX_PRIN_BCNT_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_BCNT_REG_PN_TX_PRIN_BCNT_MAX (0xFFFFFFFFU)

/* ENET_PN_TX_PRI_DROP_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_REG_PN_TX_PRIN_DROP_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_REG_PN_TX_PRIN_DROP_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_REG_PN_TX_PRIN_DROP_MAX (0xFFFFFFFFU)

/* ENET_PN_TX_PRI_DROP_BCNT_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_BCNT_REG_PN_TX_PRIN_DROP_BCNT_MASK (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_BCNT_REG_PN_TX_PRIN_DROP_BCNT_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_NU_STAT_ENET_PN_TX_PRI_DROP_BCNT_REG_PN_TX_PRIN_DROP_BCNT_MAX (0xFFFFFFFFU)

/* COMP_LOW_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_LOW_REG_COMP_LOW_MASK              (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_LOW_REG_COMP_LOW_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_LOW_REG_COMP_LOW_MAX               (0xFFFFFFFFU)

/* COMP_HIGH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_HIGH_REG_COMP_HIGH_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_HIGH_REG_COMP_HIGH_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_COMP_HIGH_REG_COMP_HIGH_MAX             (0xFFFFFFFFU)

/* CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_PPM_DIR_MASK                (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_PPM_DIR_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_PPM_DIR_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_POLARITY_INV_MASK           (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_POLARITY_INV_SHIFT          (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_CONTROL_REG_POLARITY_INV_MAX            (0x00000001U)

/* LENGTH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_LENGTH_REG_LENGTH_MASK                  (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_LENGTH_REG_LENGTH_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_LENGTH_REG_LENGTH_MAX                   (0xFFFFFFFFU)

/* PPM_LOW_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_LOW_REG_PPM_LOW_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_LOW_REG_PPM_LOW_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_LOW_REG_PPM_LOW_MAX                 (0xFFFFFFFFU)

/* PPM_HIGH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_HIGH_REG_PPM_HIGH_MASK              (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_HIGH_REG_PPM_HIGH_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_PPM_HIGH_REG_PPM_HIGH_MAX               (0x000003FFU)

/* NUDGE_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_NUDGE_REG_NUDGE_MASK                    (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_NUDGE_REG_NUDGE_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_GENF_NUDGE_REG_NUDGE_MAX                     (0x000000FFU)

/* COMP_LOW_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_LOW_REG_COMP_LOW_MASK              (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_LOW_REG_COMP_LOW_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_LOW_REG_COMP_LOW_MAX               (0xFFFFFFFFU)

/* COMP_HIGH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_HIGH_REG_COMP_HIGH_MASK            (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_HIGH_REG_COMP_HIGH_SHIFT           (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_COMP_HIGH_REG_COMP_HIGH_MAX             (0xFFFFFFFFU)

/* CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_PPM_DIR_MASK                (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_PPM_DIR_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_PPM_DIR_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_POLARITY_INV_MASK           (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_POLARITY_INV_SHIFT          (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_CONTROL_REG_POLARITY_INV_MAX            (0x00000001U)

/* LENGTH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_LENGTH_REG_LENGTH_MASK                  (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_LENGTH_REG_LENGTH_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_LENGTH_REG_LENGTH_MAX                   (0xFFFFFFFFU)

/* PPM_LOW_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_LOW_REG_PPM_LOW_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_LOW_REG_PPM_LOW_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_LOW_REG_PPM_LOW_MAX                 (0xFFFFFFFFU)

/* PPM_HIGH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_HIGH_REG_PPM_HIGH_MASK              (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_HIGH_REG_PPM_HIGH_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_PPM_HIGH_REG_PPM_HIGH_MAX               (0x000003FFU)

/* NUDGE_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_NUDGE_REG_NUDGE_MASK                    (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_NUDGE_REG_NUDGE_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ESTF_NUDGE_REG_NUDGE_MAX                     (0x000000FFU)

/* IDVER_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MINOR_VER_MASK                        (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MINOR_VER_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MINOR_VER_MAX                         (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MAJOR_VER_MASK                        (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MAJOR_VER_SHIFT                       (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_MAJOR_VER_MAX                         (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_RTL_VER_MASK                          (0x0000F800U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_RTL_VER_SHIFT                         (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_RTL_VER_MAX                           (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_TX_IDENT_MASK                         (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_TX_IDENT_SHIFT                        (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPTS_IDVER_REG_TX_IDENT_MAX                          (0x0000FFFFU)

/* CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_CPTS_EN_MASK                        (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_CPTS_EN_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_CPTS_EN_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_INT_TEST_MASK                       (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_INT_TEST_SHIFT                      (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_INT_TEST_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_POLARITY_MASK               (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_POLARITY_SHIFT              (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_POLARITY_MAX                (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TSTAMP_EN_MASK                      (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TSTAMP_EN_SHIFT                     (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TSTAMP_EN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_SEQUENCE_EN_MASK                    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_SEQUENCE_EN_SHIFT                   (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_SEQUENCE_EN_MAX                     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_MODE_MASK                           (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_MODE_SHIFT                          (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_MODE_MAX                            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_TOG_MASK                    (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_TOG_SHIFT                   (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_COMP_TOG_MAX                     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_PPM_DIR_MASK                     (0x00000080U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_PPM_DIR_SHIFT                    (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_PPM_DIR_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_MASK                 (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_SHIFT                (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_MASK                 (0x00000200U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_SHIFT                (0x00000009U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_MASK                 (0x00000400U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_SHIFT                (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_MASK                 (0x00000800U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_SHIFT                (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_MASK                 (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_SHIFT                (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_MASK                 (0x00002000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_SHIFT                (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_MASK                 (0x00004000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_SHIFT                (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_MASK                 (0x00008000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_SHIFT                (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_RX_NO_EVENT_MASK                 (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_RX_NO_EVENT_SHIFT                (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_RX_NO_EVENT_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_SYNC_SEL_MASK                    (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_SYNC_SEL_SHIFT                   (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_CPTS_CONTROL_REG_TS_SYNC_SEL_MAX                     (0x0000000FU)

/* RFTCLK_SEL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_MASK                  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_MAX                   (0x0000001FU)

/* TS_PUSH_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_PUSH_REG_TS_PUSH_MASK                        (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PUSH_REG_TS_PUSH_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PUSH_REG_TS_PUSH_MAX                         (0x00000001U)

/* TS_LOAD_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_VAL_REG_TS_LOAD_VAL_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_VAL_REG_TS_LOAD_VAL_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_VAL_REG_TS_LOAD_VAL_MAX                 (0xFFFFFFFFU)

/* TS_LOAD_EN_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_MASK                  (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_MAX                   (0x00000001U)

/* TS_COMP_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_VAL_REG_TS_COMP_VAL_MASK                (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_VAL_REG_TS_COMP_VAL_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_VAL_REG_TS_COMP_VAL_MAX                 (0xFFFFFFFFU)

/* TS_COMP_LEN_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_MASK             (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_SHIFT            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_MAX              (0xFFFFFFFFU)

/* INTSTAT_RAW_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_MASK                (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_SHIFT               (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_MAX                 (0x00000001U)

/* INTSTAT_MASKED_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_MASKED_REG_TS_PEND_MASK                 (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_MASKED_REG_TS_PEND_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_INTSTAT_MASKED_REG_TS_PEND_MAX                  (0x00000001U)

/* INT_ENABLE_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_INT_ENABLE_REG_TS_PEND_EN_MASK                  (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_INT_ENABLE_REG_TS_PEND_EN_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_INT_ENABLE_REG_TS_PEND_EN_MAX                   (0x00000001U)

/* TS_COMP_NUDGE_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_NUDGE_REG_NUDGE_MASK                    (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_NUDGE_REG_NUDGE_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_NUDGE_REG_NUDGE_MAX                     (0x000000FFU)

/* EVENT_POP_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_POP_REG_EVENT_POP_MASK                    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_POP_REG_EVENT_POP_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_POP_REG_EVENT_POP_MAX                     (0x00000001U)

/* EVENT_0_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_0_REG_TIME_STAMP_MASK                     (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_0_REG_TIME_STAMP_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_0_REG_TIME_STAMP_MAX                      (0xFFFFFFFFU)

/* EVENT_1_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_SEQUENCE_ID_MASK                    (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_SEQUENCE_ID_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_SEQUENCE_ID_MAX                     (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_MESSAGE_TYPE_MASK                   (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_MESSAGE_TYPE_SHIFT                  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_MESSAGE_TYPE_MAX                    (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_EVENT_TYPE_MASK                     (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_EVENT_TYPE_SHIFT                    (0x00000014U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_EVENT_TYPE_MAX                      (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PORT_NUMBER_MASK                    (0x1F000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PORT_NUMBER_SHIFT                   (0x00000018U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PORT_NUMBER_MAX                     (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PREMPT_QUEUE_MASK                   (0x20000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PREMPT_QUEUE_SHIFT                  (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_1_REG_PREMPT_QUEUE_MAX                    (0x00000001U)

/* EVENT_2_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_2_REG_DOMAIN_MASK                         (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_2_REG_DOMAIN_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_2_REG_DOMAIN_MAX                          (0x000000FFU)

/* EVENT_3_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_3_REG_TIME_STAMP_MASK                     (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_3_REG_TIME_STAMP_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_EVENT_3_REG_TIME_STAMP_MAX                      (0xFFFFFFFFU)

/* TS_LOAD_HIGH_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_MASK           (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_SHIFT          (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_MAX            (0xFFFFFFFFU)

/* TS_COMP_HIGH_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_HIGH_VAL_MASK      (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_HIGH_VAL_SHIFT     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_HIGH_VAL_MAX       (0xFFFFFFFFU)

/* TS_ADD_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_ADD_VAL_REG_ADD_VAL_MASK                     (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ADD_VAL_REG_ADD_VAL_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_ADD_VAL_REG_ADD_VAL_MAX                      (0x00000007U)

/* TS_PPM_LOW_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_LOW_VAL_REG_TS_PPM_LOW_VAL_MASK          (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_LOW_VAL_REG_TS_PPM_LOW_VAL_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_LOW_VAL_REG_TS_PPM_LOW_VAL_MAX           (0xFFFFFFFFU)

/* TS_PPM_HIGH_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_HIGH_VAL_REG_TS_PPM_HIGH_VAL_MASK        (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_HIGH_VAL_REG_TS_PPM_HIGH_VAL_SHIFT       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_PPM_HIGH_VAL_REG_TS_PPM_HIGH_VAL_MAX         (0x000003FFU)

/* TS_NUDGE_VAL_REG */

#define CSL_CPSW9_CPSW_NU_CPTS_TS_NUDGE_VAL_REG_TS_NUDGE_VAL_MASK              (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_NUDGE_VAL_REG_TS_NUDGE_VAL_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPTS_TS_NUDGE_VAL_REG_TS_NUDGE_VAL_MAX               (0x000000FFU)

/* MOD_VER */

#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MODULE_ID_MASK                           (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MODULE_ID_SHIFT                          (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MODULE_ID_MAX                            (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_RTL_VERSION_MASK                         (0x0000F800U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_RTL_VERSION_SHIFT                        (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_RTL_VERSION_MAX                          (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MAJOR_REVISION_MASK                      (0x00000700U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MAJOR_REVISION_SHIFT                     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MAJOR_REVISION_MAX                       (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_CUSTOM_REVISION_MASK                     (0x000000C0U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_CUSTOM_REVISION_SHIFT                    (0x00000006U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_CUSTOM_REVISION_MAX                      (0x00000003U)

#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MINOR_REVISION_MASK                      (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MINOR_REVISION_SHIFT                     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_MOD_VER_MINOR_REVISION_MAX                       (0x0000003FU)

/* ALE_STATUS */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK12_MASK                  (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK12_SHIFT                 (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK12_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK08_MASK                  (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK08_SHIFT                 (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_UREGANDREGMSK08_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_POLCNTDIV8_MASK                       (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_POLCNTDIV8_SHIFT                      (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_POLCNTDIV8_MAX                        (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH128_MASK                      (0x00000080U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH128_SHIFT                     (0x00000007U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH128_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH32_MASK                       (0x00000040U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH32_SHIFT                      (0x00000006U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_RAMDEPTH32_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_KLUENTRIES_MASK                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_KLUENTRIES_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STATUS_KLUENTRIES_MAX                        (0x0000001FU)

/* ALE_CONTROL */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_ALE_MASK                      (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_ALE_SHIFT                     (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_ALE_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_CLEAR_TABLE_MASK                     (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_CLEAR_TABLE_SHIFT                    (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_CLEAR_TABLE_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_AGE_OUT_NOW_MASK                     (0x20000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_AGE_OUT_NOW_SHIFT                    (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_AGE_OUT_NOW_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DP_MASK                       (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DP_SHIFT                      (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DP_MAX                        (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_BW_CTRL_MASK                     (0x00E00000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_BW_CTRL_SHIFT                    (0x00000015U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_BW_CTRL_MAX                      (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_TOP_MASK                      (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_TOP_SHIFT                     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_TOP_MAX                       (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_STATIC_MASK                      (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_STATIC_SHIFT                     (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UPD_STATIC_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UVLAN_NO_LEARN_MASK                  (0x00002000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UVLAN_NO_LEARN_SHIFT                 (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_UVLAN_NO_LEARN_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_MEN_MASK                      (0x00001000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_MEN_SHIFT                     (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_MEN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DEN_MASK                      (0x00000800U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DEN_SHIFT                     (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_DEN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_SEN_MASK                      (0x00000400U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_SEN_SHIFT                     (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_MIRROR_SEN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_EN_HOST_UNI_FLOOD_MASK               (0x00000100U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_EN_HOST_UNI_FLOOD_SHIFT              (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_EN_HOST_UNI_FLOOD_MAX                (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_LEARN_NO_VLANID_MASK                 (0x00000080U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_LEARN_NO_VLANID_SHIFT                (0x00000007U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_LEARN_NO_VLANID_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_VID0_MODE_MASK                (0x00000040U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_VID0_MODE_SHIFT               (0x00000006U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_VID0_MODE_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_OUI_DENY_MASK                 (0x00000020U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_OUI_DENY_SHIFT                (0x00000005U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_OUI_DENY_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_BYPASS_MASK                   (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_BYPASS_SHIFT                  (0x00000004U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_BYPASS_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_BCAST_MCAST_CTL_MASK                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_BCAST_MCAST_CTL_SHIFT                (0x00000003U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_BCAST_MCAST_CTL_MAX                  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ALE_VLAN_AWARE_MASK                  (0x00000004U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ALE_VLAN_AWARE_SHIFT                 (0x00000002U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ALE_VLAN_AWARE_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_AUTH_MODE_MASK                (0x00000002U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_AUTH_MODE_SHIFT               (0x00000001U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_AUTH_MODE_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_RATE_LIMIT_MASK               (0x00000001U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_RATE_LIMIT_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CONTROL_ENABLE_RATE_LIMIT_MAX                (0x00000001U)

/* ALE_CTRL2 */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DST_MASK                        (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DST_SHIFT                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DST_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SRC_MASK                        (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SRC_SHIFT                       (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SRC_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_PRI_MASK                        (0x20000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_PRI_SHIFT                       (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_PRI_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_IVLAN_MASK                      (0x08000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_IVLAN_SHIFT                     (0x0000001BU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_IVLAN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SIP_MASK                        (0x02000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SIP_SHIFT                       (0x00000019U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_SIP_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DIP_MASK                        (0x01000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DIP_SHIFT                       (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_EN_DIP_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DROP_BADLEN_MASK                       (0x00800000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DROP_BADLEN_SHIFT                      (0x00000017U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DROP_BADLEN_MAX                        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_NODROP_SRCMCST_MASK                    (0x00400000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_NODROP_SRCMCST_SHIFT                   (0x00000016U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_NODROP_SRCMCST_MAX                     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFNOFRAG_MASK                         (0x00200000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFNOFRAG_SHIFT                        (0x00000015U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFNOFRAG_MAX                          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFLMTNXTHDR_MASK                      (0x00100000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFLMTNXTHDR_SHIFT                     (0x00000014U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_DEFLMTNXTHDR_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_BASE_MASK                          (0x00070000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_BASE_SHIFT                         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_TRK_BASE_MAX                           (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_MIRROR_MIDX_MASK                       (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_MIRROR_MIDX_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_CTRL2_MIRROR_MIDX_MAX                        (0x000003FFU)

/* ALE_PRESCALE */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_PRESCALE_ALE_PRESCALE_MASK                   (0x000FFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_PRESCALE_ALE_PRESCALE_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_PRESCALE_ALE_PRESCALE_MAX                    (0x000FFFFFU)

/* ALE_AGING_CTRL */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_2_DISABLE_MASK           (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_2_DISABLE_SHIFT          (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_2_DISABLE_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_1_DISABLE_MASK           (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_1_DISABLE_SHIFT          (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_PRESCALE_1_DISABLE_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_ALE_AGING_TIMER_MASK              (0x00FFFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_ALE_AGING_TIMER_SHIFT             (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_AGING_CTRL_ALE_AGING_TIMER_MAX               (0x00FFFFFFU)

/* ALE_NXT_HDR */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR3_MASK                     (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR3_SHIFT                    (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR3_MAX                      (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR2_MASK                     (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR2_SHIFT                    (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR2_MAX                      (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR1_MASK                     (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR1_SHIFT                    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR1_MAX                      (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR0_MASK                     (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR0_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_NXT_HDR_IP_NXT_HDR0_MAX                      (0x000000FFU)

/* ALE_TBLCTL */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEWR_MASK                          (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEWR_SHIFT                         (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEWR_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEIDX_MASK                         (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEIDX_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLCTL_TABLEIDX_MAX                          (0x000003FFU)

/* ALE_TBLW2 */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW2_TABLEWRD2_MASK                         (0x000007FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW2_TABLEWRD2_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW2_TABLEWRD2_MAX                          (0x000007FFU)

/* ALE_TBLW1 */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW1_TABLEWRD1_MASK                         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW1_TABLEWRD1_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW1_TABLEWRD1_MAX                          (0xFFFFFFFFU)

/* ALE_TBLW0 */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW0_TABLEWRD0_MASK                         (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW0_TABLEWRD0_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_TBLW0_TABLEWRD0_MAX                          (0xFFFFFFFFU)

/* I0_ALE_PORTCTL0 */

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_BCAST_LIMIT_MASK       (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_BCAST_LIMIT_SHIFT      (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_BCAST_LIMIT_MAX        (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MCAST_LIMIT_MASK       (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MCAST_LIMIT_SHIFT      (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MCAST_LIMIT_MAX        (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DOUBLE_VLAN_MASK  (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DOUBLE_VLAN_SHIFT (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DOUBLE_VLAN_MAX   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DUAL_VLAN_MASK    (0x00004000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DUAL_VLAN_SHIFT   (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_DUAL_VLAN_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_CAF_MASK       (0x00002000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_CAF_SHIFT      (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_CAF_MAX        (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DIS_PAUTHMOD_MASK      (0x00001000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DIS_PAUTHMOD_SHIFT     (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DIS_PAUTHMOD_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_MASK           (0x00000800U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_SHIFT          (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MACONLY_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKEN_MASK           (0x00000400U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKEN_SHIFT          (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKEN_MAX            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKNUM_MASK          (0x00000300U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKNUM_SHIFT         (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_TRUNKNUM_MAX           (0x00000003U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MIRROR_SP_MASK         (0x00000080U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MIRROR_SP_SHIFT        (0x00000007U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_MIRROR_SP_MAX          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_SA_UPDATE_MASK      (0x00000020U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_SA_UPDATE_SHIFT     (0x00000005U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_SA_UPDATE_MAX       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_LEARN_MASK          (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_LEARN_SHIFT         (0x00000004U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_NO_LEARN_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_VID_INGRESS_CHECK_MASK (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_VID_INGRESS_CHECK_SHIFT (0x00000003U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_VID_INGRESS_CHECK_MAX  (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_UN_TAGGED_MASK    (0x00000004U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_UN_TAGGED_SHIFT   (0x00000002U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_DROP_UN_TAGGED_MAX     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_PORTSTATE_MASK         (0x00000003U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_PORTSTATE_SHIFT        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_I0_ALE_PORTCTL0_I0_REG_P0_PORTSTATE_MAX          (0x00000003U)

/* ALE_UVLAN_MEMBER */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_MEMBER_UVLAN_MEMBER_LIST_MASK          (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_MEMBER_UVLAN_MEMBER_LIST_SHIFT         (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_MEMBER_UVLAN_MEMBER_LIST_MAX           (0x000001FFU)

/* ALE_UVLAN_URCAST */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_URCAST_UVLAN_UNREG_MCAST_FLOOD_MASK_MASK (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_URCAST_UVLAN_UNREG_MCAST_FLOOD_MASK_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_URCAST_UVLAN_UNREG_MCAST_FLOOD_MASK_MAX (0x000001FFU)

/* ALE_UVLAN_RMCAST */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_RMCAST_UVLAN_REG_MCAST_FLOOD_MASK_MASK (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_RMCAST_UVLAN_REG_MCAST_FLOOD_MASK_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_RMCAST_UVLAN_REG_MCAST_FLOOD_MASK_MAX  (0x000001FFU)

/* ALE_UVLAN_UNTAG */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_UNTAG_UVLAN_FORCE_UNTAGGED_EGRESS_MASK (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_UNTAG_UVLAN_FORCE_UNTAGGED_EGRESS_SHIFT (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_UVLAN_UNTAG_UVLAN_FORCE_UNTAGGED_EGRESS_MAX  (0x000001FFU)

/* ALE_STAT_DIAG */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PBCAST_DIAG_MASK                   (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PBCAST_DIAG_SHIFT                  (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PBCAST_DIAG_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PORT_DIAG_MASK                     (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PORT_DIAG_SHIFT                    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_PORT_DIAG_MAX                      (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_STAT_DIAG_MASK                     (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_STAT_DIAG_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_STAT_DIAG_STAT_DIAG_MAX                      (0x0000000FU)

/* ALE_OAM_LB_CTRL */

#define CSL_CPSW9_CPSW_NU_ALE_ALE_OAM_LB_CTRL_OAM_LB_CTRL_MASK                 (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_OAM_LB_CTRL_OAM_LB_CTRL_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_ALE_OAM_LB_CTRL_OAM_LB_CTRL_MAX                  (0x000001FFU)

/* EGRESSOP */

#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_OP_MASK                          (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_OP_SHIFT                         (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_OP_MAX                           (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_TRK_MASK                         (0x00E00000U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_TRK_SHIFT                        (0x00000015U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_EGRESS_TRK_MAX                          (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_TTL_CHECK_MASK                          (0x00100000U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_TTL_CHECK_SHIFT                         (0x00000014U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_TTL_CHECK_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_DEST_PORTS_MASK                         (0x000001FFU)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_DEST_PORTS_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_EGRESSOP_DEST_PORTS_MAX                          (0x000001FFU)

/* POLICECFG0 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_MEN_MASK                         (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_MEN_SHIFT                        (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_MEN_MAX                          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_TRUNKID_MASK                          (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_TRUNKID_SHIFT                         (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_TRUNKID_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_NUM_MASK                         (0x1E000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_NUM_SHIFT                        (0x00000019U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PORT_NUM_MAX                          (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_MEN_MASK                          (0x00080000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_MEN_SHIFT                         (0x00000013U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_MEN_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_VAL_MASK                          (0x00070000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_VAL_SHIFT                         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_PRI_VAL_MAX                           (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_MEN_MASK                          (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_MEN_SHIFT                         (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_MEN_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_INDEX_MASK                        (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_INDEX_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG0_ONU_INDEX_MAX                         (0x000003FFU)

/* POLICECFG1 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_MEN_MASK                          (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_MEN_SHIFT                         (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_MEN_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_INDEX_MASK                        (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_INDEX_SHIFT                       (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_DST_INDEX_MAX                         (0x000003FFU)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_MEN_MASK                          (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_MEN_SHIFT                         (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_MEN_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_INDEX_MASK                        (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_INDEX_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG1_SRC_INDEX_MAX                         (0x000003FFU)

/* POLICECFG2 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_MEN_MASK                        (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_MEN_SHIFT                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_MEN_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_INDEX_MASK                      (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_INDEX_SHIFT                     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_OVLAN_INDEX_MAX                       (0x000003FFU)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_MEN_MASK                        (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_MEN_SHIFT                       (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_MEN_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_INDEX_MASK                      (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_INDEX_SHIFT                     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG2_IVLAN_INDEX_MAX                       (0x000003FFU)

/* POLICECFG3 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_MEN_MASK                    (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_MEN_SHIFT                   (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_MEN_MAX                     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_INDEX_MASK                  (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_INDEX_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_ETHERTYPE_INDEX_MAX                   (0x000003FFU)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_MEN_MASK                        (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_MEN_SHIFT                       (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_MEN_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_INDEX_MASK                      (0x000003FFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_INDEX_SHIFT                     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG3_IPSRC_INDEX_MAX                       (0x000003FFU)

/* POLICECFG4 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_MEN_MASK                        (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_MEN_SHIFT                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_MEN_MAX                         (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_INDEX_MASK                      (0x03FF0000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_INDEX_SHIFT                     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG4_IPDST_INDEX_MAX                       (0x000003FFU)

/* POLICECFG6 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG6_PIR_IDLE_INC_VAL_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG6_PIR_IDLE_INC_VAL_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG6_PIR_IDLE_INC_VAL_MAX                  (0xFFFFFFFFU)

/* POLICECFG7 */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG7_CIR_IDLE_INC_VAL_MASK                 (0xFFFFFFFFU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG7_CIR_IDLE_INC_VAL_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECFG7_CIR_IDLE_INC_VAL_MAX                  (0xFFFFFFFFU)

/* POLICETBLCTL */

#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_WRITE_ENABLE_MASK                   (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_WRITE_ENABLE_SHIFT                  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_WRITE_ENABLE_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_POL_TBL_IDX_MASK                    (0x0000007FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_POL_TBL_IDX_SHIFT                   (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETBLCTL_POL_TBL_IDX_MAX                     (0x0000007FU)

/* POLICECONTROL */

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLICING_EN_MASK                   (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLICING_EN_SHIFT                  (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLICING_EN_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_RED_DROP_EN_MASK                   (0x20000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_RED_DROP_EN_SHIFT                  (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_RED_DROP_EN_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOW_DROP_EN_MASK                (0x10000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOW_DROP_EN_SHIFT               (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOW_DROP_EN_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOWTHRESH_MASK                  (0x07000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOWTHRESH_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_YELLOWTHRESH_MAX                   (0x00000007U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLMCHMODE_MASK                    (0x00C00000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLMCHMODE_SHIFT                   (0x00000016U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_POLMCHMODE_MAX                     (0x00000003U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_PRIORITY_THREAD_EN_MASK            (0x00200000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_PRIORITY_THREAD_EN_SHIFT           (0x00000015U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_PRIORITY_THREAD_EN_MAX             (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_MAC_ONLY_DEF_DIS_MASK              (0x00100000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_MAC_ONLY_DEF_DIS_SHIFT             (0x00000014U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICECONTROL_MAC_ONLY_DEF_DIS_MAX               (0x00000001U)

/* POLICETESTCTL */

#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_HIT_MASK                (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_HIT_SHIFT               (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_HIT_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_REDHIT_MASK             (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_REDHIT_SHIFT            (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_REDHIT_MAX              (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_YELLOWHIT_MASK          (0x20000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_YELLOWHIT_SHIFT         (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRALL_YELLOWHIT_MAX           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRSEL_ALL_MASK                (0x10000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRSEL_ALL_SHIFT               (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_CLRSEL_ALL_MAX                 (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_TEST_IDX_MASK                  (0x0000007FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_TEST_IDX_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICETESTCTL_POL_TEST_IDX_MAX                   (0x0000007FU)

/* POLICEHSTAT */

#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_HIT_MASK                         (0x80000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_HIT_SHIFT                        (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_HIT_MAX                          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_REDHIT_MASK                      (0x40000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_REDHIT_SHIFT                     (0x0000001EU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_REDHIT_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_YELLOWHIT_MASK                   (0x20000000U)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_YELLOWHIT_SHIFT                  (0x0000001DU)
#define CSL_CPSW9_CPSW_NU_ALE_POLICEHSTAT_POL_YELLOWHIT_MAX                    (0x00000001U)

/* THREADMAPDEF */

#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREAD_EN_MASK                   (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREAD_EN_SHIFT                  (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREAD_EN_MAX                    (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREADVAL_MASK                   (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREADVAL_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPDEF_DEFTHREADVAL_MAX                    (0x0000003FU)

/* THREADMAPCTL */

#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPCTL_CLASSINDEX_MASK                     (0x0000007FU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPCTL_CLASSINDEX_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPCTL_CLASSINDEX_MAX                      (0x0000007FU)

/* THREADMAPVAL */

#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREAD_EN_MASK                      (0x00008000U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREAD_EN_SHIFT                     (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREAD_EN_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREADVAL_MASK                      (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREADVAL_SHIFT                     (0x00000000U)
#define CSL_CPSW9_CPSW_NU_ALE_THREADMAPVAL_THREADVAL_MAX                       (0x0000003FU)

/* CPSW_ID_VER_REG */

#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MINOR_VER_MASK                       (0x0000003FU)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MINOR_VER_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MINOR_VER_MAX                        (0x0000003FU)

#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_CUSTOM_VER_MASK                      (0x000000C0U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_CUSTOM_VER_SHIFT                     (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_CUSTOM_VER_MAX                       (0x00000003U)

#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MAJOR_VER_MASK                       (0x00000700U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MAJOR_VER_SHIFT                      (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_MAJOR_VER_MAX                        (0x00000007U)

#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_RTL_VER_MASK                         (0x0000F800U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_RTL_VER_SHIFT                        (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_RTL_VER_MAX                          (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_IDENT_MASK                           (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_IDENT_SHIFT                          (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CPSW_ID_VER_REG_IDENT_MAX                            (0x0000FFFFU)

/* CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_S_CN_SWITCH_MASK                         (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_S_CN_SWITCH_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_S_CN_SWITCH_MAX                          (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_VLAN_AWARE_MASK                          (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_VLAN_AWARE_SHIFT                         (0x00000001U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_VLAN_AWARE_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_ENABLE_MASK                           (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_ENABLE_SHIFT                          (0x00000002U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_ENABLE_MAX                            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_PASS_PRI_TAGGED_MASK                  (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_PASS_PRI_TAGGED_SHIFT                 (0x00000003U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P1_PASS_PRI_TAGGED_MASK                  (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P1_PASS_PRI_TAGGED_SHIFT                 (0x00000004U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P1_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P2_PASS_PRI_TAGGED_MASK                  (0x00000020U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P2_PASS_PRI_TAGGED_SHIFT                 (0x00000005U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P2_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P3_PASS_PRI_TAGGED_MASK                  (0x00000040U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P3_PASS_PRI_TAGGED_SHIFT                 (0x00000006U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P3_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P4_PASS_PRI_TAGGED_MASK                  (0x00000080U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P4_PASS_PRI_TAGGED_SHIFT                 (0x00000007U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P4_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P5_PASS_PRI_TAGGED_MASK                  (0x00000100U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P5_PASS_PRI_TAGGED_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P5_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P6_PASS_PRI_TAGGED_MASK                  (0x00000200U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P6_PASS_PRI_TAGGED_SHIFT                 (0x00000009U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P6_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P7_PASS_PRI_TAGGED_MASK                  (0x00000400U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P7_PASS_PRI_TAGGED_SHIFT                 (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P7_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P8_PASS_PRI_TAGGED_MASK                  (0x00000800U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P8_PASS_PRI_TAGGED_SHIFT                 (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P8_PASS_PRI_TAGGED_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_TYPE_MASK                      (0x00001000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_TYPE_SHIFT                     (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_TYPE_MAX                       (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_REMOVE_MASK                    (0x00002000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_REMOVE_SHIFT                   (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_TX_CRC_REMOVE_MAX                     (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PAD_MASK                           (0x00004000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PAD_SHIFT                          (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PAD_MAX                            (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PASS_CRC_ERR_MASK                  (0x00008000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PASS_CRC_ERR_SHIFT                 (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_P0_RX_PASS_CRC_ERR_MAX                   (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EEE_ENABLE_MASK                          (0x00010000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EEE_ENABLE_SHIFT                         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EEE_ENABLE_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_IET_ENABLE_MASK                          (0x00020000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_IET_ENABLE_SHIFT                         (0x00000011U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_IET_ENABLE_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EST_ENABLE_MASK                          (0x00040000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EST_ENABLE_SHIFT                         (0x00000012U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_EST_ENABLE_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_CONTROL_REG_ECC_CRC_MODE_MASK                        (0x80000000U)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_ECC_CRC_MODE_SHIFT                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_CONTROL_REG_ECC_CRC_MODE_MAX                         (0x00000001U)

/* EM_CONTROL_REG */

#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_FREE_MASK                             (0x00000001U)
#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_FREE_SHIFT                            (0x00000000U)
#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_FREE_MAX                              (0x00000001U)

#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_SOFT_MASK                             (0x00000002U)
#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_SOFT_SHIFT                            (0x00000001U)
#define CSL_CPSW9_CPSW_NU_EM_CONTROL_REG_SOFT_MAX                              (0x00000001U)

/* STAT_PORT_EN_REG */

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P0_STAT_EN_MASK                     (0x00000001U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P0_STAT_EN_SHIFT                    (0x00000000U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P0_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P1_STAT_EN_MASK                     (0x00000002U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P1_STAT_EN_SHIFT                    (0x00000001U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P1_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P2_STAT_EN_MASK                     (0x00000004U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P2_STAT_EN_SHIFT                    (0x00000002U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P2_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P3_STAT_EN_MASK                     (0x00000008U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P3_STAT_EN_SHIFT                    (0x00000003U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P3_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P4_STAT_EN_MASK                     (0x00000010U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P4_STAT_EN_SHIFT                    (0x00000004U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P4_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P5_STAT_EN_MASK                     (0x00000020U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P5_STAT_EN_SHIFT                    (0x00000005U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P5_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P6_STAT_EN_MASK                     (0x00000040U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P6_STAT_EN_SHIFT                    (0x00000006U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P6_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P7_STAT_EN_MASK                     (0x00000080U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P7_STAT_EN_SHIFT                    (0x00000007U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P7_STAT_EN_MAX                      (0x00000001U)

#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P8_STAT_EN_MASK                     (0x00000100U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P8_STAT_EN_SHIFT                    (0x00000008U)
#define CSL_CPSW9_CPSW_NU_STAT_PORT_EN_REG_P8_STAT_EN_MAX                      (0x00000001U)

/* PTYPE_REG */

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_ESC_PRI_LD_VAL_MASK                        (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_ESC_PRI_LD_VAL_SHIFT                       (0x00000000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_ESC_PRI_LD_VAL_MAX                         (0x0000001FU)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P0_PTYPE_ESC_MASK                          (0x00000100U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P0_PTYPE_ESC_SHIFT                         (0x00000008U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P0_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P1_PTYPE_ESC_MASK                          (0x00000200U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P1_PTYPE_ESC_SHIFT                         (0x00000009U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P1_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P2_PTYPE_ESC_MASK                          (0x00000400U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P2_PTYPE_ESC_SHIFT                         (0x0000000AU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P2_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P3_PTYPE_ESC_MASK                          (0x00000800U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P3_PTYPE_ESC_SHIFT                         (0x0000000BU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P3_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P4_PTYPE_ESC_MASK                          (0x00001000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P4_PTYPE_ESC_SHIFT                         (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P4_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P5_PTYPE_ESC_MASK                          (0x00002000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P5_PTYPE_ESC_SHIFT                         (0x0000000DU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P5_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P6_PTYPE_ESC_MASK                          (0x00004000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P6_PTYPE_ESC_SHIFT                         (0x0000000EU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P6_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P7_PTYPE_ESC_MASK                          (0x00008000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P7_PTYPE_ESC_SHIFT                         (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P7_PTYPE_ESC_MAX                           (0x00000001U)

#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P8_PTYPE_ESC_MASK                          (0x00010000U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P8_PTYPE_ESC_SHIFT                         (0x00000010U)
#define CSL_CPSW9_CPSW_NU_PTYPE_REG_P8_PTYPE_ESC_MAX                           (0x00000001U)

/* SOFT_IDLE_REG */

#define CSL_CPSW9_CPSW_NU_SOFT_IDLE_REG_SOFT_IDLE_MASK                         (0x00000001U)
#define CSL_CPSW9_CPSW_NU_SOFT_IDLE_REG_SOFT_IDLE_SHIFT                        (0x00000000U)
#define CSL_CPSW9_CPSW_NU_SOFT_IDLE_REG_SOFT_IDLE_MAX                          (0x00000001U)

/* THRU_RATE_REG */

#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_P0_RX_THRU_RATE_MASK                   (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_P0_RX_THRU_RATE_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_P0_RX_THRU_RATE_MAX                    (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_SL_RX_THRU_RATE_MASK                   (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_SL_RX_THRU_RATE_SHIFT                  (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_THRU_RATE_REG_SL_RX_THRU_RATE_MAX                    (0x0000000FU)

/* GAP_THRESH_REG */

#define CSL_CPSW9_CPSW_NU_GAP_THRESH_REG_GAP_THRESH_MASK                       (0x0000001FU)
#define CSL_CPSW9_CPSW_NU_GAP_THRESH_REG_GAP_THRESH_SHIFT                      (0x00000000U)
#define CSL_CPSW9_CPSW_NU_GAP_THRESH_REG_GAP_THRESH_MAX                        (0x0000001FU)

/* TX_START_WDS_REG */

#define CSL_CPSW9_CPSW_NU_TX_START_WDS_REG_TX_START_WDS_MASK                   (0x000007FFU)
#define CSL_CPSW9_CPSW_NU_TX_START_WDS_REG_TX_START_WDS_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_START_WDS_REG_TX_START_WDS_MAX                    (0x000007FFU)

/* EEE_PRESCALE_REG */

#define CSL_CPSW9_CPSW_NU_EEE_PRESCALE_REG_EEE_PRESCALE_MASK                   (0x00000FFFU)
#define CSL_CPSW9_CPSW_NU_EEE_PRESCALE_REG_EEE_PRESCALE_SHIFT                  (0x00000000U)
#define CSL_CPSW9_CPSW_NU_EEE_PRESCALE_REG_EEE_PRESCALE_MAX                    (0x00000FFFU)

/* TX_G_OFLOW_THRESH_SET_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI0_MASK                  (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI0_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI0_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI1_MASK                  (0x000000F0U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI1_SHIFT                 (0x00000004U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI1_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI2_MASK                  (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI2_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI2_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI3_MASK                  (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI3_SHIFT                 (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI3_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI4_MASK                  (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI4_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI4_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI5_MASK                  (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI5_SHIFT                 (0x00000014U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI5_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI6_MASK                  (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI6_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI6_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI7_MASK                  (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI7_SHIFT                 (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_SET_REG_PRI7_MAX                   (0x0000000FU)

/* TX_G_OFLOW_THRESH_CLR_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI0_MASK                  (0x0000000FU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI0_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI0_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI1_MASK                  (0x000000F0U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI1_SHIFT                 (0x00000004U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI1_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI2_MASK                  (0x00000F00U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI2_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI2_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI3_MASK                  (0x0000F000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI3_SHIFT                 (0x0000000CU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI3_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI4_MASK                  (0x000F0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI4_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI4_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI5_MASK                  (0x00F00000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI5_SHIFT                 (0x00000014U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI5_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI6_MASK                  (0x0F000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI6_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI6_MAX                   (0x0000000FU)

#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI7_MASK                  (0xF0000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI7_SHIFT                 (0x0000001CU)
#define CSL_CPSW9_CPSW_NU_TX_G_OFLOW_THRESH_CLR_REG_PRI7_MAX                   (0x0000000FU)

/* TX_G_BUF_THRESH_SET_L_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI0_MASK                  (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI0_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI0_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI1_MASK                  (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI1_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI1_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI2_MASK                  (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI2_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI2_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI3_MASK                  (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI3_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_L_REG_PRI3_MAX                   (0x000000FFU)

/* TX_G_BUF_THRESH_SET_H_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI4_MASK                  (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI4_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI4_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI5_MASK                  (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI5_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI5_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI6_MASK                  (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI6_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI6_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI7_MASK                  (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI7_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_SET_H_REG_PRI7_MAX                   (0x000000FFU)

/* TX_G_BUF_THRESH_CLR_L_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MASK                  (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI0_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI0_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MASK                  (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI1_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI1_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MASK                  (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI2_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI2_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MASK                  (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI3_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_L_REG_PRI3_MAX                   (0x000000FFU)

/* TX_G_BUF_THRESH_CLR_H_REG */

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MASK                  (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI4_SHIFT                 (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI4_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MASK                  (0x0000FF00U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI5_SHIFT                 (0x00000008U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI5_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MASK                  (0x00FF0000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI6_SHIFT                 (0x00000010U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI6_MAX                   (0x000000FFU)

#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MASK                  (0xFF000000U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI7_SHIFT                 (0x00000018U)
#define CSL_CPSW9_CPSW_NU_TX_G_BUF_THRESH_CLR_H_REG_PRI7_MAX                   (0x000000FFU)

/* VLAN_LTYPE_REG */

#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_INNER_MASK                 (0x0000FFFFU)
#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_INNER_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_INNER_MAX                  (0x0000FFFFU)

#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_OUTER_MASK                 (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_OUTER_SHIFT                (0x00000010U)
#define CSL_CPSW9_CPSW_NU_VLAN_LTYPE_REG_VLAN_LTYPE_OUTER_MAX                  (0x0000FFFFU)

/* EST_TS_DOMAIN_REG */

#define CSL_CPSW9_CPSW_NU_EST_TS_DOMAIN_REG_EST_TS_DOMAIN_MASK                 (0x000000FFU)
#define CSL_CPSW9_CPSW_NU_EST_TS_DOMAIN_REG_EST_TS_DOMAIN_SHIFT                (0x00000000U)
#define CSL_CPSW9_CPSW_NU_EST_TS_DOMAIN_REG_EST_TS_DOMAIN_MAX                  (0x000000FFU)

/* TX_PRI0_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI0_MAXLEN_REG_TX_PRI0_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI0_MAXLEN_REG_TX_PRI0_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI0_MAXLEN_REG_TX_PRI0_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI1_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI1_MAXLEN_REG_TX_PRI1_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI1_MAXLEN_REG_TX_PRI1_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI1_MAXLEN_REG_TX_PRI1_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI2_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI2_MAXLEN_REG_TX_PRI2_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI2_MAXLEN_REG_TX_PRI2_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI2_MAXLEN_REG_TX_PRI2_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI3_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI3_MAXLEN_REG_TX_PRI3_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI3_MAXLEN_REG_TX_PRI3_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI3_MAXLEN_REG_TX_PRI3_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI4_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI4_MAXLEN_REG_TX_PRI4_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI4_MAXLEN_REG_TX_PRI4_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI4_MAXLEN_REG_TX_PRI4_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI5_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI5_MAXLEN_REG_TX_PRI5_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI5_MAXLEN_REG_TX_PRI5_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI5_MAXLEN_REG_TX_PRI5_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI6_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI6_MAXLEN_REG_TX_PRI6_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI6_MAXLEN_REG_TX_PRI6_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI6_MAXLEN_REG_TX_PRI6_MAXLEN_MAX                (0x00003FFFU)

/* TX_PRI7_MAXLEN_REG */

#define CSL_CPSW9_CPSW_NU_TX_PRI7_MAXLEN_REG_TX_PRI7_MAXLEN_MASK               (0x00003FFFU)
#define CSL_CPSW9_CPSW_NU_TX_PRI7_MAXLEN_REG_TX_PRI7_MAXLEN_SHIFT              (0x00000000U)
#define CSL_CPSW9_CPSW_NU_TX_PRI7_MAXLEN_REG_TX_PRI7_MAXLEN_MAX                (0x00003FFFU)

/* CPSW_NUSS_IDVER_REG */

#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MINOR_VER_MASK                           (0x000000FFU)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MINOR_VER_SHIFT                          (0x00000000U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MINOR_VER_MAX                            (0x000000FFU)

#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MAJOR_VER_MASK                           (0x00000700U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MAJOR_VER_SHIFT                          (0x00000008U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_MAJOR_VER_MAX                            (0x00000007U)

#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_RTL_VER_MASK                             (0x0000F800U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_RTL_VER_SHIFT                            (0x0000000BU)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_RTL_VER_MAX                              (0x0000001FU)

#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_IDENT_MASK                               (0xFFFF0000U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_IDENT_SHIFT                              (0x00000010U)
#define CSL_CPSW9_CPSW_NUSS_IDVER_REG_IDENT_MAX                                (0x0000FFFFU)

/* SYNCE_COUNT_REG */

#define CSL_CPSW9_SYNCE_COUNT_REG_SYNCE_CNT_MASK                               (0xFFFFFFFFU)
#define CSL_CPSW9_SYNCE_COUNT_REG_SYNCE_CNT_SHIFT                              (0x00000000U)
#define CSL_CPSW9_SYNCE_COUNT_REG_SYNCE_CNT_MAX                                (0xFFFFFFFFU)

/* SYNCE_MUX_REG */

#define CSL_CPSW9_SYNCE_MUX_REG_SYNCE_SEL_MASK                                 (0x0000003FU)
#define CSL_CPSW9_SYNCE_MUX_REG_SYNCE_SEL_SHIFT                                (0x00000000U)
#define CSL_CPSW9_SYNCE_MUX_REG_SYNCE_SEL_MAX                                  (0x0000003FU)

/* CONTROL_REG */

#define CSL_CPSW9_CONTROL_REG_EEE_EN_MASK                                      (0x00000001U)
#define CSL_CPSW9_CONTROL_REG_EEE_EN_SHIFT                                     (0x00000000U)
#define CSL_CPSW9_CONTROL_REG_EEE_EN_MAX                                       (0x00000001U)

#define CSL_CPSW9_CONTROL_REG_EEE_PHY_ONLY_MASK                                (0x00000002U)
#define CSL_CPSW9_CONTROL_REG_EEE_PHY_ONLY_SHIFT                               (0x00000001U)
#define CSL_CPSW9_CONTROL_REG_EEE_PHY_ONLY_MAX                                 (0x00000001U)

/* SGMII_NON_FIBER_MODE_REG */

#define CSL_CPSW9_SGMII_NON_FIBER_MODE_REG_SGMII_NON_FIBER_MODE_MASK           (0x000000FFU)
#define CSL_CPSW9_SGMII_NON_FIBER_MODE_REG_SGMII_NON_FIBER_MODE_SHIFT          (0x00000000U)
#define CSL_CPSW9_SGMII_NON_FIBER_MODE_REG_SGMII_NON_FIBER_MODE_MAX            (0x000000FFU)

/* SERDES_RESET_ISO_REG */

#define CSL_CPSW9_SERDES_RESET_ISO_REG_SERDES_RESET_ISO_MASK                   (0x000000FFU)
#define CSL_CPSW9_SERDES_RESET_ISO_REG_SERDES_RESET_ISO_SHIFT                  (0x00000000U)
#define CSL_CPSW9_SERDES_RESET_ISO_REG_SERDES_RESET_ISO_MAX                    (0x000000FFU)

/* SUBSSYSTEM_STATUS_REG */

#define CSL_CPSW9_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MASK                   (0x00000001U)
#define CSL_CPSW9_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_SHIFT                  (0x00000000U)
#define CSL_CPSW9_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MAX                    (0x00000001U)

/* RGMII1_STATUS_REG */

#define CSL_CPSW9_RGMII1_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII1_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII1_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII1_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII1_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII1_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII1_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII1_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII1_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII2_STATUS_REG */

#define CSL_CPSW9_RGMII2_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII2_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII2_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII2_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII2_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII2_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII2_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII2_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII2_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII3_STATUS_REG */

#define CSL_CPSW9_RGMII3_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII3_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII3_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII3_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII3_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII3_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII3_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII3_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII3_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII4_STATUS_REG */

#define CSL_CPSW9_RGMII4_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII4_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII4_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII4_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII4_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII4_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII4_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII4_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII4_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII5_STATUS_REG */

#define CSL_CPSW9_RGMII5_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII5_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII5_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII5_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII5_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII5_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII5_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII5_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII5_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII6_STATUS_REG */

#define CSL_CPSW9_RGMII6_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII6_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII6_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII6_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII6_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII6_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII6_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII6_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII6_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII7_STATUS_REG */

#define CSL_CPSW9_RGMII7_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII7_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII7_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII7_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII7_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII7_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII7_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII7_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII7_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* RGMII8_STATUS_REG */

#define CSL_CPSW9_RGMII8_STATUS_REG_LINK_MASK                                  (0x00000001U)
#define CSL_CPSW9_RGMII8_STATUS_REG_LINK_SHIFT                                 (0x00000000U)
#define CSL_CPSW9_RGMII8_STATUS_REG_LINK_MAX                                   (0x00000001U)

#define CSL_CPSW9_RGMII8_STATUS_REG_SPEED_MASK                                 (0x00000006U)
#define CSL_CPSW9_RGMII8_STATUS_REG_SPEED_SHIFT                                (0x00000001U)
#define CSL_CPSW9_RGMII8_STATUS_REG_SPEED_MAX                                  (0x00000003U)

#define CSL_CPSW9_RGMII8_STATUS_REG_FULLDUPLEX_MASK                            (0x00000008U)
#define CSL_CPSW9_RGMII8_STATUS_REG_FULLDUPLEX_SHIFT                           (0x00000003U)
#define CSL_CPSW9_RGMII8_STATUS_REG_FULLDUPLEX_MAX                             (0x00000001U)

/* QSGMII_CONTROL_REG */

#define CSL_CPSW9_QSGMII_CONTROL_REG_Q0_RDCD_MASK                              (0x00000001U)
#define CSL_CPSW9_QSGMII_CONTROL_REG_Q0_RDCD_SHIFT                             (0x00000000U)
#define CSL_CPSW9_QSGMII_CONTROL_REG_Q0_RDCD_MAX                               (0x00000001U)

#define CSL_CPSW9_QSGMII_CONTROL_REG_Q1_RDCD_MASK                              (0x00000002U)
#define CSL_CPSW9_QSGMII_CONTROL_REG_Q1_RDCD_SHIFT                             (0x00000001U)
#define CSL_CPSW9_QSGMII_CONTROL_REG_Q1_RDCD_MAX                               (0x00000001U)

/* QSGMII_STATUS_REG */

#define CSL_CPSW9_QSGMII_STATUS_REG_Q0_RDCD_MASK                               (0x00000001U)
#define CSL_CPSW9_QSGMII_STATUS_REG_Q0_RDCD_SHIFT                              (0x00000000U)
#define CSL_CPSW9_QSGMII_STATUS_REG_Q0_RDCD_MAX                                (0x00000001U)

#define CSL_CPSW9_QSGMII_STATUS_REG_Q1_RDCD_MASK                               (0x00000002U)
#define CSL_CPSW9_QSGMII_STATUS_REG_Q1_RDCD_SHIFT                              (0x00000001U)
#define CSL_CPSW9_QSGMII_STATUS_REG_Q1_RDCD_MAX                                (0x00000001U)

/* STATUS_XGMII_LINK_REG */

#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII1_LINK_MASK                       (0x00000001U)
#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII1_LINK_SHIFT                      (0x00000000U)
#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII1_LINK_MAX                        (0x00000001U)

#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII2_LINK_MASK                       (0x00000002U)
#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII2_LINK_SHIFT                      (0x00000001U)
#define CSL_CPSW9_STATUS_XGMII_LINK_REG_XGMII2_LINK_MAX                        (0x00000001U)

/* STATUS_SGMII_LINK_REG */

#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII1_LINK_MASK                       (0x00000001U)
#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII1_LINK_SHIFT                      (0x00000000U)
#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII1_LINK_MAX                        (0x00000001U)

#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII2_LINK_MASK                       (0x00000002U)
#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII2_LINK_SHIFT                      (0x00000001U)
#define CSL_CPSW9_STATUS_SGMII_LINK_REG_SGMII2_LINK_MAX                        (0x00000001U)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REV;                       /* Aggregator Revision Register */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t VECTOR;                    /* ECC Vector Register */
    volatile uint32_t STAT;                      /* Misc Status */
    volatile uint32_t RESERVED_SVBUS[8];         /* Reserved Area for Serial VBUS Registers */
    volatile uint8_t  Resv_60[12];
    volatile uint32_t SEC_EOI_REG;               /* EOI Register */
    volatile uint32_t SEC_STATUS_REG0;           /* Interrupt Status Register 0 */
    volatile uint8_t  Resv_128[60];
    volatile uint32_t SEC_ENABLE_SET_REG0;       /* Interrupt Enable Set Register 0 */
    volatile uint8_t  Resv_192[60];
    volatile uint32_t SEC_ENABLE_CLR_REG0;       /* Interrupt Enable Clear Register 0 */
    volatile uint8_t  Resv_316[120];
    volatile uint32_t DED_EOI_REG;               /* EOI Register */
    volatile uint32_t DED_STATUS_REG0;           /* Interrupt Status Register 0 */
    volatile uint8_t  Resv_384[60];
    volatile uint32_t DED_ENABLE_SET_REG0;       /* Interrupt Enable Set Register 0 */
    volatile uint8_t  Resv_448[60];
    volatile uint32_t DED_ENABLE_CLR_REG0;       /* Interrupt Enable Clear Register 0 */
    volatile uint8_t  Resv_512[60];
    volatile uint32_t AGGR_ENABLE_SET;           /* AGGR interrupt enable set Register */
    volatile uint32_t AGGR_ENABLE_CLR;           /* AGGR interrupt enable clear Register */
    volatile uint32_t AGGR_STATUS_SET;           /* AGGR interrupt status set Register */
    volatile uint32_t AGGR_STATUS_CLR;           /* AGGR interrupt status clear Register */
} CSL_cpsw9_eccRegs_ECC;


typedef struct {
    CSL_cpsw9_eccRegs_ECC ECC;
} CSL_cpsw9_eccRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CPSW9_ECC_ECC_REV                                                  (0x00000000U)
#define CSL_CPSW9_ECC_ECC_VECTOR                                               (0x00000008U)
#define CSL_CPSW9_ECC_ECC_STAT                                                 (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_RESERVED_SVBUS(RESERVED_SVBUS)                       (0x00000010U+((RESERVED_SVBUS)*0x4U))
#define CSL_CPSW9_ECC_ECC_SEC_EOI_REG                                          (0x0000003CU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0                                      (0x00000040U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0                                  (0x00000080U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0                                  (0x000000C0U)
#define CSL_CPSW9_ECC_ECC_DED_EOI_REG                                          (0x0000013CU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0                                      (0x00000140U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0                                  (0x00000180U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0                                  (0x000001C0U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET                                      (0x00000200U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR                                      (0x00000204U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET                                      (0x00000208U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR                                      (0x0000020CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REV */

#define CSL_CPSW9_ECC_ECC_REV_SCHEME_MASK                                      (0xC0000000U)
#define CSL_CPSW9_ECC_ECC_REV_SCHEME_SHIFT                                     (0x0000001EU)
#define CSL_CPSW9_ECC_ECC_REV_SCHEME_MAX                                       (0x00000003U)

#define CSL_CPSW9_ECC_ECC_REV_BU_MASK                                          (0x30000000U)
#define CSL_CPSW9_ECC_ECC_REV_BU_SHIFT                                         (0x0000001CU)
#define CSL_CPSW9_ECC_ECC_REV_BU_MAX                                           (0x00000003U)

#define CSL_CPSW9_ECC_ECC_REV_MODULE_ID_MASK                                   (0x0FFF0000U)
#define CSL_CPSW9_ECC_ECC_REV_MODULE_ID_SHIFT                                  (0x00000010U)
#define CSL_CPSW9_ECC_ECC_REV_MODULE_ID_MAX                                    (0x00000FFFU)

#define CSL_CPSW9_ECC_ECC_REV_REVRTL_MASK                                      (0x0000F800U)
#define CSL_CPSW9_ECC_ECC_REV_REVRTL_SHIFT                                     (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_REV_REVRTL_MAX                                       (0x0000001FU)

#define CSL_CPSW9_ECC_ECC_REV_REVMAJ_MASK                                      (0x00000700U)
#define CSL_CPSW9_ECC_ECC_REV_REVMAJ_SHIFT                                     (0x00000008U)
#define CSL_CPSW9_ECC_ECC_REV_REVMAJ_MAX                                       (0x00000007U)

#define CSL_CPSW9_ECC_ECC_REV_CUSTOM_MASK                                      (0x000000C0U)
#define CSL_CPSW9_ECC_ECC_REV_CUSTOM_SHIFT                                     (0x00000006U)
#define CSL_CPSW9_ECC_ECC_REV_CUSTOM_MAX                                       (0x00000003U)

#define CSL_CPSW9_ECC_ECC_REV_REVMIN_MASK                                      (0x0000003FU)
#define CSL_CPSW9_ECC_ECC_REV_REVMIN_SHIFT                                     (0x00000000U)
#define CSL_CPSW9_ECC_ECC_REV_REVMIN_MAX                                       (0x0000003FU)

/* VECTOR */

#define CSL_CPSW9_ECC_ECC_VECTOR_ECC_VECTOR_MASK                               (0x000007FFU)
#define CSL_CPSW9_ECC_ECC_VECTOR_ECC_VECTOR_SHIFT                              (0x00000000U)
#define CSL_CPSW9_ECC_ECC_VECTOR_ECC_VECTOR_MAX                                (0x000007FFU)

#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_MASK                                 (0x00008000U)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_SHIFT                                (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_MAX                                  (0x00000001U)

#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_ADDRESS_MASK                         (0x00FF0000U)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_ADDRESS_SHIFT                        (0x00000010U)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_ADDRESS_MAX                          (0x000000FFU)

#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_DONE_MASK                            (0x01000000U)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_DONE_SHIFT                           (0x00000018U)
#define CSL_CPSW9_ECC_ECC_VECTOR_RD_SVBUS_DONE_MAX                             (0x00000001U)

/* STAT */

#define CSL_CPSW9_ECC_ECC_STAT_NUM_RAMS_MASK                                   (0x000007FFU)
#define CSL_CPSW9_ECC_ECC_STAT_NUM_RAMS_SHIFT                                  (0x00000000U)
#define CSL_CPSW9_ECC_ECC_STAT_NUM_RAMS_MAX                                    (0x000007FFU)

/* RESERVED_SVBUS */

#define CSL_CPSW9_ECC_ECC_RESERVED_SVBUS_DATA_MASK                             (0xFFFFFFFFU)
#define CSL_CPSW9_ECC_ECC_RESERVED_SVBUS_DATA_SHIFT                            (0x00000000U)
#define CSL_CPSW9_ECC_ECC_RESERVED_SVBUS_DATA_MAX                              (0xFFFFFFFFU)

/* SEC_EOI_REG */

#define CSL_CPSW9_ECC_ECC_SEC_EOI_REG_EOI_WR_MASK                              (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_EOI_REG_EOI_WR_SHIFT                             (0x00000000U)
#define CSL_CPSW9_ECC_ECC_SEC_EOI_REG_EOI_WR_MAX                               (0x00000001U)

/* SEC_STATUS_REG0 */

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC0_PEND_MASK                    (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC0_PEND_SHIFT                   (0x00000000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC0_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC1_PEND_MASK                    (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC1_PEND_SHIFT                   (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC1_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC2_PEND_MASK                    (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC2_PEND_SHIFT                   (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC2_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC3_PEND_MASK                    (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC3_PEND_SHIFT                   (0x00000003U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC3_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC4_PEND_MASK                    (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC4_PEND_SHIFT                   (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC4_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC5_PEND_MASK                    (0x00000020U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC5_PEND_SHIFT                   (0x00000005U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC5_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC6_PEND_MASK                    (0x00000040U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC6_PEND_SHIFT                   (0x00000006U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC6_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC7_PEND_MASK                    (0x00000080U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC7_PEND_SHIFT                   (0x00000007U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC7_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC8_PEND_MASK                    (0x00000100U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC8_PEND_SHIFT                   (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC8_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC9_PEND_MASK                    (0x00000200U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC9_PEND_SHIFT                   (0x00000009U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC9_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC10_PEND_MASK                   (0x00000400U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC10_PEND_SHIFT                  (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC10_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC11_PEND_MASK                   (0x00000800U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC11_PEND_SHIFT                  (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC11_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC12_PEND_MASK                   (0x00001000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC12_PEND_SHIFT                  (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC12_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC13_PEND_MASK                   (0x00002000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC13_PEND_SHIFT                  (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC13_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC14_PEND_MASK                   (0x00004000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC14_PEND_SHIFT                  (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC14_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC15_PEND_MASK                   (0x00008000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC15_PEND_SHIFT                  (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC15_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC16_PEND_MASK                   (0x00010000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC16_PEND_SHIFT                  (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC16_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC17_PEND_MASK                   (0x00020000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC17_PEND_SHIFT                  (0x00000011U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC17_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC18_PEND_MASK                   (0x00040000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC18_PEND_SHIFT                  (0x00000012U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC18_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC19_PEND_MASK                   (0x00080000U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC19_PEND_SHIFT                  (0x00000013U)
#define CSL_CPSW9_ECC_ECC_SEC_STATUS_REG0_RAMECC19_PEND_MAX                    (0x00000001U)

/* SEC_ENABLE_SET_REG0 */

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_MASK          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_SHIFT         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_MASK          (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_SHIFT         (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_MASK          (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_SHIFT         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_MASK          (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_SHIFT         (0x00000003U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_MASK          (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_SHIFT         (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_MASK          (0x00000020U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_SHIFT         (0x00000005U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_MASK          (0x00000040U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_SHIFT         (0x00000006U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_MASK          (0x00000080U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_SHIFT         (0x00000007U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_MASK          (0x00000100U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_SHIFT         (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_MASK          (0x00000200U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_SHIFT         (0x00000009U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_MASK         (0x00000400U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_SHIFT        (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_MASK         (0x00000800U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_SHIFT        (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_MASK         (0x00001000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_SHIFT        (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_MASK         (0x00002000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_SHIFT        (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_MASK         (0x00004000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_SHIFT        (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_MASK         (0x00008000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_SHIFT        (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_MASK         (0x00010000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_SHIFT        (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_MASK         (0x00020000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_SHIFT        (0x00000011U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_MASK         (0x00040000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_SHIFT        (0x00000012U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_MASK         (0x00080000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_SHIFT        (0x00000013U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_MAX          (0x00000001U)

/* SEC_ENABLE_CLR_REG0 */

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_MASK          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_SHIFT         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_MASK          (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_SHIFT         (0x00000001U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_MASK          (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_SHIFT         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_MASK          (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_SHIFT         (0x00000003U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_MASK          (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_SHIFT         (0x00000004U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_MASK          (0x00000020U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_SHIFT         (0x00000005U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_MASK          (0x00000040U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_SHIFT         (0x00000006U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_MASK          (0x00000080U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_SHIFT         (0x00000007U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_MASK          (0x00000100U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_SHIFT         (0x00000008U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_MASK          (0x00000200U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_SHIFT         (0x00000009U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_MASK         (0x00000400U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_SHIFT        (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_MASK         (0x00000800U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_SHIFT        (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_MASK         (0x00001000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_SHIFT        (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_MASK         (0x00002000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_SHIFT        (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_MASK         (0x00004000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_SHIFT        (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_MASK         (0x00008000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_SHIFT        (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_MASK         (0x00010000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_SHIFT        (0x00000010U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_MASK         (0x00020000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_SHIFT        (0x00000011U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_MASK         (0x00040000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_SHIFT        (0x00000012U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_MASK         (0x00080000U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_SHIFT        (0x00000013U)
#define CSL_CPSW9_ECC_ECC_SEC_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_MAX          (0x00000001U)

/* DED_EOI_REG */

#define CSL_CPSW9_ECC_ECC_DED_EOI_REG_EOI_WR_MASK                              (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_EOI_REG_EOI_WR_SHIFT                             (0x00000000U)
#define CSL_CPSW9_ECC_ECC_DED_EOI_REG_EOI_WR_MAX                               (0x00000001U)

/* DED_STATUS_REG0 */

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC0_PEND_MASK                    (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC0_PEND_SHIFT                   (0x00000000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC0_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC1_PEND_MASK                    (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC1_PEND_SHIFT                   (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC1_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC2_PEND_MASK                    (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC2_PEND_SHIFT                   (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC2_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC3_PEND_MASK                    (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC3_PEND_SHIFT                   (0x00000003U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC3_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC4_PEND_MASK                    (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC4_PEND_SHIFT                   (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC4_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC5_PEND_MASK                    (0x00000020U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC5_PEND_SHIFT                   (0x00000005U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC5_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC6_PEND_MASK                    (0x00000040U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC6_PEND_SHIFT                   (0x00000006U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC6_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC7_PEND_MASK                    (0x00000080U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC7_PEND_SHIFT                   (0x00000007U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC7_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC8_PEND_MASK                    (0x00000100U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC8_PEND_SHIFT                   (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC8_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC9_PEND_MASK                    (0x00000200U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC9_PEND_SHIFT                   (0x00000009U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC9_PEND_MAX                     (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC10_PEND_MASK                   (0x00000400U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC10_PEND_SHIFT                  (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC10_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC11_PEND_MASK                   (0x00000800U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC11_PEND_SHIFT                  (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC11_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC12_PEND_MASK                   (0x00001000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC12_PEND_SHIFT                  (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC12_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC13_PEND_MASK                   (0x00002000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC13_PEND_SHIFT                  (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC13_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC14_PEND_MASK                   (0x00004000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC14_PEND_SHIFT                  (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC14_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC15_PEND_MASK                   (0x00008000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC15_PEND_SHIFT                  (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC15_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC16_PEND_MASK                   (0x00010000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC16_PEND_SHIFT                  (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC16_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC17_PEND_MASK                   (0x00020000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC17_PEND_SHIFT                  (0x00000011U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC17_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC18_PEND_MASK                   (0x00040000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC18_PEND_SHIFT                  (0x00000012U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC18_PEND_MAX                    (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC19_PEND_MASK                   (0x00080000U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC19_PEND_SHIFT                  (0x00000013U)
#define CSL_CPSW9_ECC_ECC_DED_STATUS_REG0_RAMECC19_PEND_MAX                    (0x00000001U)

/* DED_ENABLE_SET_REG0 */

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_MASK          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_SHIFT         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC0_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_MASK          (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_SHIFT         (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC1_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_MASK          (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_SHIFT         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC2_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_MASK          (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_SHIFT         (0x00000003U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC3_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_MASK          (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_SHIFT         (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC4_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_MASK          (0x00000020U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_SHIFT         (0x00000005U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC5_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_MASK          (0x00000040U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_SHIFT         (0x00000006U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC6_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_MASK          (0x00000080U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_SHIFT         (0x00000007U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC7_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_MASK          (0x00000100U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_SHIFT         (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC8_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_MASK          (0x00000200U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_SHIFT         (0x00000009U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC9_ENABLE_SET_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_MASK         (0x00000400U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_SHIFT        (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC10_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_MASK         (0x00000800U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_SHIFT        (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC11_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_MASK         (0x00001000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_SHIFT        (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC12_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_MASK         (0x00002000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_SHIFT        (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC13_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_MASK         (0x00004000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_SHIFT        (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC14_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_MASK         (0x00008000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_SHIFT        (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC15_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_MASK         (0x00010000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_SHIFT        (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC16_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_MASK         (0x00020000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_SHIFT        (0x00000011U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC17_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_MASK         (0x00040000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_SHIFT        (0x00000012U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC18_ENABLE_SET_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_MASK         (0x00080000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_SHIFT        (0x00000013U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_SET_REG0_RAMECC19_ENABLE_SET_MAX          (0x00000001U)

/* DED_ENABLE_CLR_REG0 */

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_MASK          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_SHIFT         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC0_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_MASK          (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_SHIFT         (0x00000001U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC1_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_MASK          (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_SHIFT         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC2_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_MASK          (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_SHIFT         (0x00000003U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC3_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_MASK          (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_SHIFT         (0x00000004U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC4_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_MASK          (0x00000020U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_SHIFT         (0x00000005U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC5_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_MASK          (0x00000040U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_SHIFT         (0x00000006U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC6_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_MASK          (0x00000080U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_SHIFT         (0x00000007U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC7_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_MASK          (0x00000100U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_SHIFT         (0x00000008U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC8_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_MASK          (0x00000200U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_SHIFT         (0x00000009U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC9_ENABLE_CLR_MAX           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_MASK         (0x00000400U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_SHIFT        (0x0000000AU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC10_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_MASK         (0x00000800U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_SHIFT        (0x0000000BU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC11_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_MASK         (0x00001000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_SHIFT        (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC12_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_MASK         (0x00002000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_SHIFT        (0x0000000DU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC13_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_MASK         (0x00004000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_SHIFT        (0x0000000EU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC14_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_MASK         (0x00008000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_SHIFT        (0x0000000FU)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC15_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_MASK         (0x00010000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_SHIFT        (0x00000010U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC16_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_MASK         (0x00020000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_SHIFT        (0x00000011U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC17_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_MASK         (0x00040000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_SHIFT        (0x00000012U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC18_ENABLE_CLR_MAX          (0x00000001U)

#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_MASK         (0x00080000U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_SHIFT        (0x00000013U)
#define CSL_CPSW9_ECC_ECC_DED_ENABLE_CLR_REG0_RAMECC19_ENABLE_CLR_MAX          (0x00000001U)

/* AGGR_ENABLE_SET */

#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_PARITY_MASK                          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_PARITY_SHIFT                         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_PARITY_MAX                           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_TIMEOUT_MASK                         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_TIMEOUT_SHIFT                        (0x00000001U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_SET_TIMEOUT_MAX                          (0x00000001U)

/* AGGR_ENABLE_CLR */

#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_PARITY_MASK                          (0x00000001U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_PARITY_SHIFT                         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_PARITY_MAX                           (0x00000001U)

#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_TIMEOUT_MASK                         (0x00000002U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_TIMEOUT_SHIFT                        (0x00000001U)
#define CSL_CPSW9_ECC_ECC_AGGR_ENABLE_CLR_TIMEOUT_MAX                          (0x00000001U)

/* AGGR_STATUS_SET */

#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_PARITY_MASK                          (0x00000003U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_PARITY_SHIFT                         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_PARITY_MAX                           (0x00000003U)

#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_TIMEOUT_MASK                         (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_TIMEOUT_SHIFT                        (0x00000002U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_SET_TIMEOUT_MAX                          (0x00000003U)

/* AGGR_STATUS_CLR */

#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_PARITY_MASK                          (0x00000003U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_PARITY_SHIFT                         (0x00000000U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_PARITY_MAX                           (0x00000003U)

#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_TIMEOUT_MASK                         (0x0000000CU)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_TIMEOUT_SHIFT                        (0x00000002U)
#define CSL_CPSW9_ECC_ECC_AGGR_STATUS_CLR_TIMEOUT_MAX                          (0x00000003U)

#ifdef __cplusplus
}
#endif
#endif
