/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_XGE_CPSW_H_
#define CSLR_XGE_CPSW_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for enetport
**************************************************************************/
typedef struct {
    volatile Uint32 PN_RESERVED_REG;
    volatile Uint32 PN_CONTROL_REG;
    volatile Uint32 PN_MAX_BLKS_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 PN_BLK_CNT_REG;
    volatile Uint32 PN_PORT_VLAN_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 PN_PRI_CTL_REG;
    volatile Uint32 PN_RX_PRI_MAP_REG;
    volatile Uint32 PN_RX_MAXLEN_REG;
    volatile Uint8  RSVD2[8];
    volatile Uint32 PN_IDLE2LPI_REG;
    volatile Uint32 PN_LPI2WAKE_REG;
    volatile Uint32 PN_EEE_STATUS_REG;
    volatile Uint8  RSVD3[228];
    volatile Uint32 PN_RX_DSCP_MAP_REG[8];
    volatile Uint32 PN_PRI_SEND_REG[8];
    volatile Uint32 PN_PRI_IDLE_REG[8];
    volatile Uint8  RSVD4[392];
    volatile Uint32 PN_SA_L_REG;
    volatile Uint32 PN_SA_H_REG;
    volatile Uint32 PN_TS_CTL_REG;
    volatile Uint32 PN_TS_SEQ_LTYPE_REG;
    volatile Uint32 PN_TS_VLAN_LTYPE_REG;
    volatile Uint32 PN_TS_CTL_LTYPE2_REG;
    volatile Uint32 PN_TS_CTL2_REG;
    volatile Uint8  RSVD5[12];
    volatile Uint32 PN_MAC_CONTROL_REG;
    volatile Uint32 PN_MAC_STATUS_REG;
    volatile Uint32 PN_MAC_SOFT_RESET_REG;
    volatile Uint32 PN_MAC_BOFFTEST_REG;
    volatile Uint32 PN_MAC_RX_PAUSETIMER_REG;
    volatile Uint8  RSVD6[44];
    volatile Uint32 PN_MAC_TX_PAUSETIMER_REG;
    volatile Uint8  RSVD7[44];
    volatile Uint32 PN_MAC_EMCONTROL_REG;
    volatile Uint32 PN_MAC_TX_GAP_REG;
    volatile Uint8  RSVD8[3160];
} CSL_Xge_cpswEnetportRegs;


/**************************************************************************
* Register Overlay Structure for stats
**************************************************************************/
typedef struct {
    volatile Uint32 RXGOODFRAMES;
    volatile Uint32 RXBROADCASTFRAMES;
    volatile Uint32 RXMULTICASTFRAMES;
    volatile Uint32 RXPAUSEFRAMES;
    volatile Uint32 RXCRCERRORS;
    volatile Uint32 RXALIGNCODEERRORS;
    volatile Uint32 RXOVERSIZEDFRAMES;
    volatile Uint32 RXJABBERFRAMES;
    volatile Uint32 RXUNDERSIZEDFRAMES;
    volatile Uint32 RXFRAGMENTS;
    volatile Uint32 ALE_DROP;
    volatile Uint32 ALE_OVERRUN_DROP;
    volatile Uint32 RXOCTETS;
    volatile Uint32 TXGOODFRAMES;
    volatile Uint32 TXBROADCASTFRAMES;
    volatile Uint32 TXMULTICASTFRAMES;
    volatile Uint32 TXPAUSEFRAMES;
    volatile Uint32 TXDEFERREDFRAMES;
    volatile Uint32 TXCOLLISIONFRAMES;
    volatile Uint32 TXSINGLECOLLFRAMES;
    volatile Uint32 TXMULTCOLLFRAMES;
    volatile Uint32 TXEXCESSIVECOLLISIONS;
    volatile Uint32 TXLATECOLLISIONS;
    volatile Uint32 RXIPGERROR;
    volatile Uint32 TXCARRIERSENSEERRORS;
    volatile Uint32 TXOCTETS;
    volatile Uint32 OCTETFRAMES64;
    volatile Uint32 OCTETFRAMES65T127;
    volatile Uint32 OCTETFRAMES128T255;
    volatile Uint32 OCTETFRAMES256T511;
    volatile Uint32 OCTETFRAMES512T1023;
    volatile Uint32 OCTETFRAMES1024TUP;
    volatile Uint32 NETOCTETS;
    volatile Uint32 RX_BOTTOM_OF_FIFO_DROP;
    volatile Uint32 PORTMASK_DROP;
    volatile Uint32 RX_TOP_OF_FIFO_DROP;
    volatile Uint32 ALE_RATE_LIMIT_DROP;
    volatile Uint32 ALE_VID_INGRESS_DROP;
    volatile Uint32 ALE_DA_EQ_SA_DROP;
    volatile Uint8  RSVD0[12];
    volatile Uint32 ALE_UNKN_UNI;
    volatile Uint32 ALE_UNKN_UNI_BCNT;
    volatile Uint32 ALE_UNKN_MLT;
    volatile Uint32 ALE_UNKN_MLT_BCNT;
    volatile Uint32 ALE_UNKN_BRD;
    volatile Uint32 ALE_UNKN_BRD_BCNT;
    volatile Uint32 ALE_POL_MATCH;
    volatile Uint8  RSVD1[184];
    volatile Uint32 TX_MEMORY_PROTECT_ERROR;
    volatile Uint8  RSVD2[128];
} CSL_Xge_cpswStatsRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 ID_VER_REG;
    volatile Uint32 CONTROL_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 EM_CONTROL_REG;
    volatile Uint32 STAT_PORT_EN_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 SOFT_IDLE_REG;
    volatile Uint8  RSVD2[12];
    volatile Uint32 EEE_PRESCALE_REG;
    volatile Uint8  RSVD3[4052];
    volatile Uint32 P0_CONTROL_REG;
    volatile Uint32 P0_FLOW_ID_OFFSET_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 P0_BLK_CNT_REG;
    volatile Uint32 P0_PORT_VLAN_REG;
    volatile Uint8  RSVD5[4];
    volatile Uint32 P0_PRI_CTL_REG;
    volatile Uint32 P0_RX_PRI_MAP_REG;
    volatile Uint32 P0_RX_MAXLEN_REG;
    volatile Uint8  RSVD6[8];
    volatile Uint32 P0_IDLE2LPI_REG;
    volatile Uint32 P0_LPI2WAKE_REG;
    volatile Uint32 P0_EEE_STATUS_REG;
    volatile Uint8  RSVD7[228];
    volatile Uint32 P0_RX_DSCP_MAP_REG[8];
    volatile Uint32 P0_PRI_SEND_REG[8];
    volatile Uint32 P0_PRI_IDLE_REG[8];
    volatile Uint8  RSVD8[384];
    volatile Uint32 P0_SRC_ID_A_REG;
    volatile Uint8  RSVD9[3324];
    CSL_Xge_cpswEnetportRegs	ENETPORT[8];
    volatile Uint8  RSVD10[65536];
    CSL_Xge_cpswStatsRegs	STATS[9];
} CSL_Xge_cpswRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Reserved */
#define CSL_XGE_CPSW_PN_RESERVED_REG(n)                         (0x2000U + ((n) * (0x1000U)))

/* Enet Port N Control */
#define CSL_XGE_CPSW_PN_CONTROL_REG(n)                          (0x2004U + ((n) * (0x1000U)))

/* Enet Port N FIFO Max Blocks */
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG(n)                         (0x2008U + ((n) * (0x1000U)))

/* Enet Port N FIFO Block Usage Count */
#define CSL_XGE_CPSW_PN_BLK_CNT_REG(n)                          (0x2010U + ((n) * (0x1000U)))

/* Enet Port N VLAN */
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG(n)                        (0x2014U + ((n) * (0x1000U)))

/* Enet Port N Priority Control */
#define CSL_XGE_CPSW_PN_PRI_CTL_REG(n)                          (0x201CU + ((n) * (0x1000U)))

/* Enet Port N RX Pkt Pri to Header Pri Map */
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG(n)                       (0x2020U + ((n) * (0x1000U)))

/* Enet Port N Receive Frame Max Length */
#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG(n)                        (0x2024U + ((n) * (0x1000U)))

/* Enet Port N EEE Idle to LPI counter */
#define CSL_XGE_CPSW_PN_IDLE2LPI_REG(n)                         (0x2030U + ((n) * (0x1000U)))

/* Enet Port N EEE LPI to wake counter */
#define CSL_XGE_CPSW_PN_LPI2WAKE_REG(n)                         (0x2034U + ((n) * (0x1000U)))

/* Enet Port N EEE status */
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG(n)                       (0x2038U + ((n) * (0x1000U)))

/* Enet Port N Receive IPV4/IPV6 DSCP Map M */
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG(n,i)                    (0x2120U + ((n) * (0x1000U)) + (i * (0x4U))

/* Enet Port N Rx Priority P Send Count Value */
#define CSL_XGE_CPSW_PN_PRI_SEND_REG(n,i)                       (0x2140U + ((n) * (0x1000U)) + (i * (0x4U))

/* Enet Port N Rx Priority P Idle Count Value */
#define CSL_XGE_CPSW_PN_PRI_IDLE_REG(n,i)                       (0x2160U + ((n) * (0x1000U)) + (i * (0x4U))

/* Enet Port N Tx Pause Frame Source Address Low */
#define CSL_XGE_CPSW_PN_SA_L_REG(n)                             (0x2308U + ((n) * (0x1000U)))

/* Enet Port N Tx Pause Frame Source Address High */
#define CSL_XGE_CPSW_PN_SA_H_REG(n)                             (0x230CU + ((n) * (0x1000U)))

/* Enet Port N Time Sync Control */
#define CSL_XGE_CPSW_PN_TS_CTL_REG(n)                           (0x2310U + ((n) * (0x1000U)))

/* Enet Port N Time Sync LTYPE (and SEQ_ID_OFFSET) */
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG(n)                     (0x2314U + ((n) * (0x1000U)))

/* Enet Port N Time Sync VLAN2 and VLAN2 */
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG(n)                    (0x2318U + ((n) * (0x1000U)))

/* Enet Port N Time Sync Control and LTYPE 2 */
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG(n)                    (0x231CU + ((n) * (0x1000U)))

/* Enet Port N Time Sync Control 2 */
#define CSL_XGE_CPSW_PN_TS_CTL2_REG(n)                          (0x2320U + ((n) * (0x1000U)))

/* Enet Port N Mac Control */
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG(n)                      (0x2330U + ((n) * (0x1000U)))

/* Enet Port N Mac Status */
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG(n)                       (0x2334U + ((n) * (0x1000U)))

/* Enet Port N Mac Soft Reset */
#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG(n)                   (0x2338U + ((n) * (0x1000U)))

/* Enet Port N Mac Backoff Test */
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG(n)                     (0x233CU + ((n) * (0x1000U)))

/* Enet Port N 802.3 Receive Pause Timer */
#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG(n)                (0x2340U + ((n) * (0x1000U)))

/* Enet Port N 802.3 Tx Pause Timer */
#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG(n)                (0x2370U + ((n) * (0x1000U)))

/* Enet Port N Emulation Control */
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG(n)                    (0x23A0U + ((n) * (0x1000U)))

/* Enet Port N Tx Inter Packet Gap */
#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG(n)                       (0x23A4U + ((n) * (0x1000U)))

/* Total number of good frames received */
#define CSL_XGE_CPSW_RXGOODFRAMES(n)                            (0x1A000U + ((n) * (0x200U)))

/* Total number of good broadcast frames received */
#define CSL_XGE_CPSW_RXBROADCASTFRAMES(n)                       (0x1A004U + ((n) * (0x200U)))

/* Total number of good multicast frames received */
#define CSL_XGE_CPSW_RXMULTICASTFRAMES(n)                       (0x1A008U + ((n) * (0x200U)))

/* Total number of pause frames received */
#define CSL_XGE_CPSW_RXPAUSEFRAMES(n)                           (0x1A00CU + ((n) * (0x200U)))

/* Total number of CRC errors frames received */
#define CSL_XGE_CPSW_RXCRCERRORS(n)                             (0x1A010U + ((n) * (0x200U)))

/* Total number of alignment/code errors received */
#define CSL_XGE_CPSW_RXALIGNCODEERRORS(n)                       (0x1A014U + ((n) * (0x200U)))

/* Total number of oversized frames received */
#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES(n)                       (0x1A018U + ((n) * (0x200U)))

/* Total number of jabber frames received */
#define CSL_XGE_CPSW_RXJABBERFRAMES(n)                          (0x1A01CU + ((n) * (0x200U)))

/* Total number of undersized frames received */
#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES(n)                      (0x1A020U + ((n) * (0x200U)))

/* Total number of fragmented frames received */
#define CSL_XGE_CPSW_RXFRAGMENTS(n)                             (0x1A024U + ((n) * (0x200U)))

/* Total number of frames dropped by the ALE */
#define CSL_XGE_CPSW_ALE_DROP(n)                                (0x1A028U + ((n) * (0x200U)))

/* Total number of overrun frames dropped by the ALE */
#define CSL_XGE_CPSW_ALE_OVERRUN_DROP(n)                        (0x1A02CU + ((n) * (0x200U)))

/* Total number of received bytes in good frames */
#define CSL_XGE_CPSW_RXOCTETS(n)                                (0x1A030U + ((n) * (0x200U)))

/* Total number of good frames transmitted */
#define CSL_XGE_CPSW_TXGOODFRAMES(n)                            (0x1A034U + ((n) * (0x200U)))

/* Total number of good broadcast frames transmitted */
#define CSL_XGE_CPSW_TXBROADCASTFRAMES(n)                       (0x1A038U + ((n) * (0x200U)))

/* Total number of good multicast frames transmitted */
#define CSL_XGE_CPSW_TXMULTICASTFRAMES(n)                       (0x1A03CU + ((n) * (0x200U)))

/* Total number of pause frames transmitted */
#define CSL_XGE_CPSW_TXPAUSEFRAMES(n)                           (0x1A040U + ((n) * (0x200U)))

/* Total number of deferred frames transmitted */
#define CSL_XGE_CPSW_TXDEFERREDFRAMES(n)                        (0x1A044U + ((n) * (0x200U)))

/* Total number of transmitted frames experiencing a collision */
#define CSL_XGE_CPSW_TXCOLLISIONFRAMES(n)                       (0x1A048U + ((n) * (0x200U)))

/* Total number of transmitted frames experiencing a single collision */
#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES(n)                      (0x1A04CU + ((n) * (0x200U)))

/* Total number of transmitted frames experiencing multiple collisions */
#define CSL_XGE_CPSW_TXMULTCOLLFRAMES(n)                        (0x1A050U + ((n) * (0x200U)))

/* Total number of transmitted frames abandoned due to excessive collisions */
#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS(n)                   (0x1A054U + ((n) * (0x200U)))

/* Total number of transmitted frames abandoned due to a late collision */
#define CSL_XGE_CPSW_TXLATECOLLISIONS(n)                        (0x1A058U + ((n) * (0x200U)))

/* Total number of receive inter-packet gap errors (10G only) */
#define CSL_XGE_CPSW_RXIPGERROR(n)                              (0x1A05CU + ((n) * (0x200U)))

/* Total number of transmitted frames that experienced a carrier loss */
#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS(n)                    (0x1A060U + ((n) * (0x200U)))

/* Total number of bytes in all good frames transmitted */
#define CSL_XGE_CPSW_TXOCTETS(n)                                (0x1A064U + ((n) * (0x200U)))

/* Total number of 64-byte frames received and transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES64(n)                           (0x1A068U + ((n) * (0x200U)))

/* Total number of frames of size 65 to 127 bytes received and transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES65T127(n)                       (0x1A06CU + ((n) * (0x200U)))

/* Total number of frames of size 128 to 255 bytes received and transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES128T255(n)                      (0x1A070U + ((n) * (0x200U)))

/* Total number of frames of size 256 to 511 bytes received and transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES256T511(n)                      (0x1A074U + ((n) * (0x200U)))

/* Total number of frames of size 512 to 1023 bytes received and transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES512T1023(n)                     (0x1A078U + ((n) * (0x200U)))

/* Total number of frames of size 1024 to rx_maxlen bytes received and 1024 
 * bytes or greater transmitted */
#define CSL_XGE_CPSW_OCTETFRAMES1024TUP(n)                      (0x1A07CU + ((n) * (0x200U)))

/* Total number of bytes received and transmitted */
#define CSL_XGE_CPSW_NETOCTETS(n)                               (0x1A080U + ((n) * (0x200U)))

/* Receive Bottom of FIFO Drop */
#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP(n)                  (0x1A084U + ((n) * (0x200U)))

/* Total number of dropped frames received due to portmask */
#define CSL_XGE_CPSW_PORTMASK_DROP(n)                           (0x1A088U + ((n) * (0x200U)))

/* Receive Top of FIFO Drop */
#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP(n)                     (0x1A08CU + ((n) * (0x200U)))

/* Total number of dropped frames due to ALE Rate Limiting */
#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP(n)                     (0x1A090U + ((n) * (0x200U)))

/* Total number of dropped frames due to ALE VID Ingress */
#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP(n)                    (0x1A094U + ((n) * (0x200U)))

/* Total number of dropped frames due to DA=SA */
#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP(n)                       (0x1A098U + ((n) * (0x200U)))

/* ALE Receive Unknown Unicast */
#define CSL_XGE_CPSW_ALE_UNKN_UNI(n)                            (0x1A0A8U + ((n) * (0x200U)))

/* ALE Receive Unknown Unicast Bytecount */
#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT(n)                       (0x1A0ACU + ((n) * (0x200U)))

/* ALE Receive Unknown Multicast */
#define CSL_XGE_CPSW_ALE_UNKN_MLT(n)                            (0x1A0B0U + ((n) * (0x200U)))

/* ALE Receive Unknown Multicast Bytecount */
#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT(n)                       (0x1A0B4U + ((n) * (0x200U)))

/* ALE Receive Unknown Broadcast */
#define CSL_XGE_CPSW_ALE_UNKN_BRD(n)                            (0x1A0B8U + ((n) * (0x200U)))

/* ALE Receive Unknown Broadcast Bytecount */
#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT(n)                       (0x1A0BCU + ((n) * (0x200U)))

/* ALE Policer Matched */
#define CSL_XGE_CPSW_ALE_POL_MATCH(n)                           (0x1A0C0U + ((n) * (0x200U)))

/* Transmit Memory Protect CRC Error */
#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR(n)                 (0x1A17CU + ((n) * (0x200U)))

/* CPSW ID Version */
#define CSL_XGE_CPSW_ID_VER_REG                                 (0x0U)

/* CPSW Switch Control */
#define CSL_XGE_CPSW_CONTROL_REG                                (0x4U)

/* CPSW Emulation Control */
#define CSL_XGE_CPSW_EM_CONTROL_REG                             (0x10U)

/* CPSW Statistics Port Enable */
#define CSL_XGE_CPSW_STAT_PORT_EN_REG                           (0x14U)

/* CPSW Software Idle */
#define CSL_XGE_CPSW_SOFT_IDLE_REG                              (0x1CU)

/* CPSW Energy Efficient Ethernet Prescale Value */
#define CSL_XGE_CPSW_EEE_PRESCALE_REG                           (0x2CU)

/* CPPI Port 0 Control */
#define CSL_XGE_CPSW_P0_CONTROL_REG                             (0x1004U)

/* CPPI Port 0 Flow ID Offset */
#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG                      (0x1008U)

/* CPPI Port 0 FIFO Block Usage Count */
#define CSL_XGE_CPSW_P0_BLK_CNT_REG                             (0x1010U)

/* CPPI Port 0 VLAN */
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG                           (0x1014U)

/* CPPI Port 0 Priority Control */
#define CSL_XGE_CPSW_P0_PRI_CTL_REG                             (0x101CU)

/* CPPI Port 0 RX Pkt Pri to Header Pri Map */
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG                          (0x1020U)

/* CPPI Port 0 Receive Frame Max Length */
#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG                           (0x1024U)

/* Port 0 EEE Idle to LPI counter */
#define CSL_XGE_CPSW_P0_IDLE2LPI_REG                            (0x1030U)

/* Port 0 EEE LPI to wake counter */
#define CSL_XGE_CPSW_P0_LPI2WAKE_REG                            (0x1034U)

/* Port 0 EEE status */
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG                          (0x1038U)

/* CPPI Port 0 Receive IPV4/IPV6 DSCP Map N */
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG(i)                      (0x1120U + ((i) * (0x4U)))

/* CPPI Port 0 Rx Priority P Send Count Value */
#define CSL_XGE_CPSW_P0_PRI_SEND_REG(i)                         (0x1140U + ((i) * (0x4U)))

/* CPPI Port 0 Rx Priority P Idle Count Value */
#define CSL_XGE_CPSW_P0_PRI_IDLE_REG(i)                         (0x1160U + ((i) * (0x4U)))

/* CPPI Port 0 CPPI Source ID A */
#define CSL_XGE_CPSW_P0_SRC_ID_A_REG                            (0x1300U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PN_RESERVED_REG */

#define CSL_XGE_CPSW_PN_RESERVED_REG_RESETVAL                   (0x00000000U)

/* PN_CONTROL_REG */

#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN_MASK           (0x00000002U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN_SHIFT          (1U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN_MASK           (0x00000004U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN_SHIFT          (2U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_MASK      (0x00001000U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_SHIFT     (12U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN_MAX       (0x00000001U)

#define CSL_XGE_CPSW_PN_CONTROL_REG_RESETVAL                    (0x00000000U)

/* PN_MAX_BLKS_REG */

#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS_MASK           (0x0000000FU)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS_SHIFT          (0U)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS_MAX            (0x0000000fU)

#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS_MASK           (0x00000F00U)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS_SHIFT          (8U)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS_MAX            (0x0000000fU)

#define CSL_XGE_CPSW_PN_MAX_BLKS_REG_RESETVAL                   (0x00000000U)

/* PN_BLK_CNT_REG */

#define CSL_XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT_MASK             (0x0000003FU)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT_SHIFT            (0U)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT_MAX              (0x0000003fU)

#define CSL_XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT_MASK             (0x00003E00U)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT_SHIFT            (9U)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT_MAX              (0x0000001fU)

#define CSL_XGE_CPSW_PN_BLK_CNT_REG_RESETVAL                    (0x00000000U)

/* PN_PORT_VLAN_REG */

#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID_MASK             (0x00000FFFU)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID_SHIFT            (0U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID_MAX              (0x00000fffU)

#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI_MASK             (0x00001000U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI_SHIFT            (12U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI_MASK             (0x0000E000U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI_SHIFT            (13U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI_MAX              (0x00000007U)

#define CSL_XGE_CPSW_PN_PORT_VLAN_REG_RESETVAL                  (0x00000000U)

/* PN_PRI_CTL_REG */

#define CSL_XGE_CPSW_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_MASK       (0x0000F000U)
#define CSL_XGE_CPSW_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_SHIFT      (12U)
#define CSL_XGE_CPSW_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_PRI_CTL_REG_TX_HOST_BLKS_REM_MAX        (0x0000000fU)

#define CSL_XGE_CPSW_PN_PRI_CTL_REG_RESETVAL                    (0x00000000U)

/* PN_RX_PRI_MAP_REG */

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0_MASK                (0x00000007U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0_SHIFT               (0U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1_MASK                (0x00000070U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1_SHIFT               (4U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2_MASK                (0x00000700U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2_SHIFT               (8U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3_MASK                (0x00007000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3_SHIFT               (12U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4_MASK                (0x00070000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4_SHIFT               (16U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5_MASK                (0x00700000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5_SHIFT               (20U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6_MASK                (0x07000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6_SHIFT               (24U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7_MASK                (0x70000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7_SHIFT               (28U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_PRI_MAP_REG_RESETVAL                 (0x00000000U)

/* PN_RX_MAXLEN_REG */

#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN_MASK            (0x00003FFFU)
#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN_SHIFT           (0U)
#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN_MAX             (0x00003fffU)

#define CSL_XGE_CPSW_PN_RX_MAXLEN_REG_RESETVAL                  (0x00000000U)

/* PN_IDLE2LPI_REG */

#define CSL_XGE_CPSW_PN_IDLE2LPI_REG_COUNT_MASK                 (0x00FFFFFFU)
#define CSL_XGE_CPSW_PN_IDLE2LPI_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_PN_IDLE2LPI_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_PN_IDLE2LPI_REG_COUNT_MAX                  (0x00ffffffU)

#define CSL_XGE_CPSW_PN_IDLE2LPI_REG_RESETVAL                   (0x00000000U)

/* PN_LPI2WAKE_REG */

#define CSL_XGE_CPSW_PN_LPI2WAKE_REG_COUNT_MASK                 (0x00FFFFFFU)
#define CSL_XGE_CPSW_PN_LPI2WAKE_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_PN_LPI2WAKE_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_PN_LPI2WAKE_REG_COUNT_MAX                  (0x00ffffffU)

#define CSL_XGE_CPSW_PN_LPI2WAKE_REG_RESETVAL                   (0x00000000U)

/* PN_EEE_STATUS_REG */

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_MASK       (0x00000001U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_SHIFT      (0U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI_MAX        (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI_MASK              (0x00000002U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI_SHIFT             (1U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI_MAX               (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI_MASK              (0x00000004U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI_SHIFT             (2U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI_MAX               (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE_MASK             (0x00000008U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE_SHIFT            (3U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD_MASK        (0x00000010U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD_SHIFT       (4U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_MASK       (0x00000020U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_SHIFT      (5U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY_MAX        (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_MASK       (0x00000040U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_SHIFT      (6U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY_MAX        (0x00000001U)

#define CSL_XGE_CPSW_PN_EEE_STATUS_REG_RESETVAL                 (0x00000000U)

/* PN_RX_DSCP_MAP_REG */

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0_MASK               (0x00000007U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0_SHIFT              (0U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1_MASK               (0x00000070U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1_SHIFT              (4U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2_MASK               (0x00000700U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2_SHIFT              (8U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3_MASK               (0x00007000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3_SHIFT              (12U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4_MASK               (0x00070000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4_SHIFT              (16U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5_MASK               (0x00700000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5_SHIFT              (20U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6_MASK               (0x07000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6_SHIFT              (24U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7_MASK               (0x70000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7_SHIFT              (28U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7_MAX                (0x00000007U)

#define CSL_XGE_CPSW_PN_RX_DSCP_MAP_REG_RESETVAL                (0x00000000U)

/* PN_PRI_SEND_REG */

#define CSL_XGE_CPSW_PN_PRI_SEND_REG_COUNT_MASK                 (0x0003FFFFU)
#define CSL_XGE_CPSW_PN_PRI_SEND_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_PN_PRI_SEND_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_PN_PRI_SEND_REG_COUNT_MAX                  (0x0003ffffU)

#define CSL_XGE_CPSW_PN_PRI_SEND_REG_RESETVAL                   (0x00000000U)

/* PN_PRI_IDLE_REG */

#define CSL_XGE_CPSW_PN_PRI_IDLE_REG_COUNT_MASK                 (0x0003FFFFU)
#define CSL_XGE_CPSW_PN_PRI_IDLE_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_PN_PRI_IDLE_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_PN_PRI_IDLE_REG_COUNT_MAX                  (0x0003ffffU)

#define CSL_XGE_CPSW_PN_PRI_IDLE_REG_RESETVAL                   (0x00000000U)

/* PN_SA_L_REG */

#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8_MASK           (0x000000FFU)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8_SHIFT          (0U)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8_MAX            (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0_MASK            (0x0000FF00U)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0_SHIFT           (8U)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0_MAX             (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_L_REG_RESETVAL                       (0x00000000U)

/* PN_SA_H_REG */

#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40_MASK          (0x000000FFU)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40_SHIFT         (0U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40_MAX           (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32_MASK          (0x0000FF00U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32_SHIFT         (8U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32_MAX           (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24_MASK          (0x00FF0000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24_SHIFT         (16U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24_MAX           (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16_MASK          (0xFF000000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16_SHIFT         (24U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16_MAX           (0x000000ffU)

#define CSL_XGE_CPSW_PN_SA_H_REG_RESETVAL                       (0x00000000U)

/* PN_TS_CTL_REG */

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_MASK        (0x00000001U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_SHIFT       (0U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_MASK    (0x00000002U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_SHIFT   (1U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN_MAX     (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_MASK    (0x00000004U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_SHIFT   (2U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN_MAX     (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_MASK        (0x00000008U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_SHIFT       (3U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_MASK        (0x00000010U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_SHIFT       (4U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_MASK    (0x00000020U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_SHIFT   (5U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN_MAX     (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_MASK    (0x00000040U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_SHIFT   (6U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN_MAX     (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_MASK        (0x00000080U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_SHIFT       (7U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN_MASK            (0x00000100U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN_SHIFT           (8U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN_MAX             (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_MASK        (0x00000200U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_SHIFT       (9U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_MASK        (0x00000400U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_SHIFT       (10U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_MASK        (0x00000800U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_SHIFT       (11U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN_MASK          (0xFFFF0000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN_SHIFT         (16U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN_MAX           (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_CTL_REG_RESETVAL                     (0x00000000U)

/* PN_TS_SEQ_LTYPE_REG */

#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_MASK         (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_SHIFT        (0U)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1_MAX          (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_MASK  (0x003F0000U)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_SHIFT  (16U)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET_MAX   (0x0000003fU)

#define CSL_XGE_CPSW_PN_TS_SEQ_LTYPE_REG_RESETVAL               (0x00000000U)

/* PN_TS_VLAN_LTYPE_REG */

#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_MASK   (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_SHIFT  (0U)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1_MAX    (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_MASK   (0xFFFF0000U)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_SHIFT  (16U)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2_MAX    (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_VLAN_LTYPE_REG_RESETVAL              (0x00000000U)

/* PN_TS_CTL_LTYPE2_REG */

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_MASK        (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_SHIFT       (0U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2_MAX         (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107_MASK           (0x00010000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107_SHIFT          (16U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129_MASK           (0x00020000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129_SHIFT          (17U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130_MASK           (0x00040000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130_SHIFT          (18U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131_MASK           (0x00080000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131_SHIFT          (19U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132_MASK           (0x00100000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132_SHIFT          (20U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319_MASK           (0x00200000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319_SHIFT          (21U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320_MASK           (0x00400000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320_SHIFT          (22U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_MASK   (0x00800000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_SHIFT  (23U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO_MAX    (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_MASK        (0x01000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_SHIFT       (24U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN_MAX         (0x00000001U)

#define CSL_XGE_CPSW_PN_TS_CTL_LTYPE2_REG_RESETVAL              (0x00000000U)

/* PN_TS_CTL2_REG */

#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_MASK       (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_SHIFT      (0U)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN_MAX        (0x0000ffffU)

#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_MASK       (0x003F0000U)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_SHIFT      (16U)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET_MAX        (0x0000003fU)

#define CSL_XGE_CPSW_PN_TS_CTL2_REG_RESETVAL                    (0x00000000U)

/* PN_MAC_CONTROL_REG */

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_FULLDUPLEX_MASK         (0x00000001U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_FULLDUPLEX_SHIFT        (0U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_FULLDUPLEX_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_FULLDUPLEX_MAX          (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_LOOPBACK_MASK           (0x00000002U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_LOOPBACK_SHIFT          (1U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_LOOPBACK_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_LOOPBACK_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_MTEST_MASK              (0x00000004U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_MTEST_SHIFT             (2U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_MTEST_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_MTEST_MAX               (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_FLOW_EN_MASK         (0x00000008U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_FLOW_EN_SHIFT        (3U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_FLOW_EN_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_FLOW_EN_MAX          (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_FLOW_EN_MASK         (0x00000010U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_FLOW_EN_SHIFT        (4U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_FLOW_EN_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_FLOW_EN_MAX          (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GMII_EN_MASK            (0x00000020U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GMII_EN_SHIFT           (5U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GMII_EN_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GMII_EN_MAX             (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_PACE_MASK            (0x00000040U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_PACE_SHIFT           (6U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_PACE_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_TX_PACE_MAX             (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_MASK                (0x00000080U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_SHIFT               (7U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_MAX                 (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CMD_IDLE_MASK           (0x00000800U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CMD_IDLE_SHIFT          (11U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CMD_IDLE_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CMD_IDLE_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CRC_TYPE_MASK           (0x00001000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CRC_TYPE_SHIFT          (12U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CRC_TYPE_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CRC_TYPE_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_XGMII_EN_MASK           (0x00002000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_XGMII_EN_SHIFT          (13U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_XGMII_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_XGMII_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_A_MASK            (0x00008000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_A_SHIFT           (15U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_A_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_A_MAX             (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_B_MASK            (0x00010000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_B_SHIFT           (16U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_B_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_IFCTL_B_MAX             (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_FORCE_MASK          (0x00020000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_FORCE_SHIFT         (17U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_FORCE_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_GIG_FORCE_MAX           (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CTL_EN_MASK             (0x00040000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CTL_EN_SHIFT            (18U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CTL_EN_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_CTL_EN_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_MASK     (0x00080000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_SHIFT    (19U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_RX_FLOW_EN_MAX      (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_MASK     (0x00100000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_SHIFT    (20U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_EXT_TX_FLOW_EN_MAX      (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CEF_EN_MASK          (0x00400000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CEF_EN_SHIFT         (22U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CEF_EN_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CEF_EN_MAX           (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CSF_EN_MASK          (0x00800000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CSF_EN_SHIFT         (23U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CSF_EN_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CSF_EN_MAX           (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CMF_EN_MASK          (0x01000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CMF_EN_SHIFT         (24U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CMF_EN_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RX_CMF_EN_MAX           (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_CONTROL_REG_RESETVAL                (0x00000000U)

/* PN_MAC_STATUS_REG */

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_TX_FLOW_ACT_MASK         (0x00000001U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_TX_FLOW_ACT_SHIFT        (0U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_TX_FLOW_ACT_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_TX_FLOW_ACT_MAX          (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_RX_FLOW_ACT_MASK         (0x00000002U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_RX_FLOW_ACT_SHIFT        (1U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_RX_FLOW_ACT_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_RX_FLOW_ACT_MAX          (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_MASK      (0x00000008U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_SHIFT     (3U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_FULLDUPLEX_MAX       (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_GIG_MASK             (0x00000010U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_GIG_SHIFT            (4U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_GIG_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_GIG_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_MASK      (0x00000020U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_SHIFT     (5U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_TX_FLOW_EN_MAX       (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_MASK      (0x00000040U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_SHIFT     (6U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_EXT_RX_FLOW_EN_MAX       (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_IDLE_MASK                (0x80000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_IDLE_SHIFT               (31U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_IDLE_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_IDLE_MAX                 (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_STATUS_REG_RESETVAL                 (0x00000000U)

/* PN_MAC_SOFT_RESET_REG */

#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG_SOFT_RESET_MASK      (0x00000001U)
#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG_SOFT_RESET_SHIFT     (0U)
#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG_SOFT_RESET_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG_SOFT_RESET_MAX       (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_SOFT_RESET_REG_RESETVAL             (0x00000000U)

/* PN_MAC_BOFFTEST_REG */

#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_TX_BACKOFF_MASK        (0x000003FFU)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_TX_BACKOFF_SHIFT       (0U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_TX_BACKOFF_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_TX_BACKOFF_MAX         (0x000003ffU)

#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_COLL_COUNT_MASK        (0x0000F000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_COLL_COUNT_SHIFT       (12U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_COLL_COUNT_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_COLL_COUNT_MAX         (0x0000000fU)

#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_RNDNUM_MASK            (0x03FF0000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_RNDNUM_SHIFT           (16U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_RNDNUM_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_RNDNUM_MAX             (0x000003ffU)

#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_PACEVAL_MASK           (0x7C000000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_PACEVAL_SHIFT          (26U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_PACEVAL_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_PACEVAL_MAX            (0x0000001fU)

#define CSL_XGE_CPSW_PN_MAC_BOFFTEST_REG_RESETVAL               (0x00000000U)

/* PN_MAC_RX_PAUSETIMER_REG */

#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_MASK  (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_SHIFT  (0U)
#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG_RX_PAUSETIMER_MAX  (0x0000ffffU)

#define CSL_XGE_CPSW_PN_MAC_RX_PAUSETIMER_REG_RESETVAL          (0x00000000U)

/* PN_MAC_TX_PAUSETIMER_REG */

#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_MASK  (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_SHIFT  (0U)
#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG_TX_PAUSETIMER_MAX  (0x0000ffffU)

#define CSL_XGE_CPSW_PN_MAC_TX_PAUSETIMER_REG_RESETVAL          (0x00000000U)

/* PN_MAC_EMCONTROL_REG */

#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_FREE_MASK             (0x00000001U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_FREE_SHIFT            (0U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_FREE_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_FREE_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_SOFT_MASK             (0x00000002U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_SOFT_SHIFT            (1U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_SOFT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_SOFT_MAX              (0x00000001U)

#define CSL_XGE_CPSW_PN_MAC_EMCONTROL_REG_RESETVAL              (0x00000000U)

/* PN_MAC_TX_GAP_REG */

#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG_TX_GAP_MASK              (0x0000FFFFU)
#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG_TX_GAP_SHIFT             (0U)
#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG_TX_GAP_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG_TX_GAP_MAX               (0x0000ffffU)

#define CSL_XGE_CPSW_PN_MAC_TX_GAP_REG_RESETVAL                 (0x00000000U)

/* RXGOODFRAMES */

#define CSL_XGE_CPSW_RXGOODFRAMES_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXGOODFRAMES_COUNT_SHIFT                   (0U)
#define CSL_XGE_CPSW_RXGOODFRAMES_COUNT_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_RXGOODFRAMES_COUNT_MAX                     (0xffffffffU)

#define CSL_XGE_CPSW_RXGOODFRAMES_RESETVAL                      (0x00000000U)

/* RXBROADCASTFRAMES */

#define CSL_XGE_CPSW_RXBROADCASTFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXBROADCASTFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_RXBROADCASTFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_RXBROADCASTFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_RXBROADCASTFRAMES_RESETVAL                 (0x00000000U)

/* RXMULTICASTFRAMES */

#define CSL_XGE_CPSW_RXMULTICASTFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXMULTICASTFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_RXMULTICASTFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_RXMULTICASTFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_RXMULTICASTFRAMES_RESETVAL                 (0x00000000U)

/* RXPAUSEFRAMES */

#define CSL_XGE_CPSW_RXPAUSEFRAMES_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXPAUSEFRAMES_COUNT_SHIFT                  (0U)
#define CSL_XGE_CPSW_RXPAUSEFRAMES_COUNT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_RXPAUSEFRAMES_COUNT_MAX                    (0xffffffffU)

#define CSL_XGE_CPSW_RXPAUSEFRAMES_RESETVAL                     (0x00000000U)

/* RXCRCERRORS */

#define CSL_XGE_CPSW_RXCRCERRORS_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXCRCERRORS_COUNT_SHIFT                    (0U)
#define CSL_XGE_CPSW_RXCRCERRORS_COUNT_RESETVAL                 (0x00000000U)
#define CSL_XGE_CPSW_RXCRCERRORS_COUNT_MAX                      (0xffffffffU)

#define CSL_XGE_CPSW_RXCRCERRORS_RESETVAL                       (0x00000000U)

/* RXALIGNCODEERRORS */

#define CSL_XGE_CPSW_RXALIGNCODEERRORS_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXALIGNCODEERRORS_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_RXALIGNCODEERRORS_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_RXALIGNCODEERRORS_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_RXALIGNCODEERRORS_RESETVAL                 (0x00000000U)

/* RXOVERSIZEDFRAMES */

#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_RXOVERSIZEDFRAMES_RESETVAL                 (0x00000000U)

/* RXJABBERFRAMES */

#define CSL_XGE_CPSW_RXJABBERFRAMES_COUNT_MASK                  (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXJABBERFRAMES_COUNT_SHIFT                 (0U)
#define CSL_XGE_CPSW_RXJABBERFRAMES_COUNT_RESETVAL              (0x00000000U)
#define CSL_XGE_CPSW_RXJABBERFRAMES_COUNT_MAX                   (0xffffffffU)

#define CSL_XGE_CPSW_RXJABBERFRAMES_RESETVAL                    (0x00000000U)

/* RXUNDERSIZEDFRAMES */

#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES_COUNT_SHIFT             (0U)
#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES_COUNT_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES_COUNT_MAX               (0xffffffffU)

#define CSL_XGE_CPSW_RXUNDERSIZEDFRAMES_RESETVAL                (0x00000000U)

/* RXFRAGMENTS */

#define CSL_XGE_CPSW_RXFRAGMENTS_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXFRAGMENTS_COUNT_SHIFT                    (0U)
#define CSL_XGE_CPSW_RXFRAGMENTS_COUNT_RESETVAL                 (0x00000000U)
#define CSL_XGE_CPSW_RXFRAGMENTS_COUNT_MAX                      (0xffffffffU)

#define CSL_XGE_CPSW_RXFRAGMENTS_RESETVAL                       (0x00000000U)

/* ALE_DROP */

#define CSL_XGE_CPSW_ALE_DROP_COUNT_MASK                        (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_DROP_COUNT_SHIFT                       (0U)
#define CSL_XGE_CPSW_ALE_DROP_COUNT_RESETVAL                    (0x00000000U)
#define CSL_XGE_CPSW_ALE_DROP_COUNT_MAX                         (0xffffffffU)

#define CSL_XGE_CPSW_ALE_DROP_RESETVAL                          (0x00000000U)

/* ALE_OVERRUN_DROP */

#define CSL_XGE_CPSW_ALE_OVERRUN_DROP_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_OVERRUN_DROP_COUNT_SHIFT               (0U)
#define CSL_XGE_CPSW_ALE_OVERRUN_DROP_COUNT_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_ALE_OVERRUN_DROP_COUNT_MAX                 (0xffffffffU)

#define CSL_XGE_CPSW_ALE_OVERRUN_DROP_RESETVAL                  (0x00000000U)

/* RXOCTETS */

#define CSL_XGE_CPSW_RXOCTETS_COUNT_MASK                        (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXOCTETS_COUNT_SHIFT                       (0U)
#define CSL_XGE_CPSW_RXOCTETS_COUNT_RESETVAL                    (0x00000000U)
#define CSL_XGE_CPSW_RXOCTETS_COUNT_MAX                         (0xffffffffU)

#define CSL_XGE_CPSW_RXOCTETS_RESETVAL                          (0x00000000U)

/* TXGOODFRAMES */

#define CSL_XGE_CPSW_TXGOODFRAMES_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXGOODFRAMES_COUNT_SHIFT                   (0U)
#define CSL_XGE_CPSW_TXGOODFRAMES_COUNT_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_TXGOODFRAMES_COUNT_MAX                     (0xffffffffU)

#define CSL_XGE_CPSW_TXGOODFRAMES_RESETVAL                      (0x00000000U)

/* TXBROADCASTFRAMES */

#define CSL_XGE_CPSW_TXBROADCASTFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXBROADCASTFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_TXBROADCASTFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_TXBROADCASTFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_TXBROADCASTFRAMES_RESETVAL                 (0x00000000U)

/* TXMULTICASTFRAMES */

#define CSL_XGE_CPSW_TXMULTICASTFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXMULTICASTFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_TXMULTICASTFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_TXMULTICASTFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_TXMULTICASTFRAMES_RESETVAL                 (0x00000000U)

/* TXPAUSEFRAMES */

#define CSL_XGE_CPSW_TXPAUSEFRAMES_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXPAUSEFRAMES_COUNT_SHIFT                  (0U)
#define CSL_XGE_CPSW_TXPAUSEFRAMES_COUNT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_TXPAUSEFRAMES_COUNT_MAX                    (0xffffffffU)

#define CSL_XGE_CPSW_TXPAUSEFRAMES_RESETVAL                     (0x00000000U)

/* TXDEFERREDFRAMES */

#define CSL_XGE_CPSW_TXDEFERREDFRAMES_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXDEFERREDFRAMES_COUNT_SHIFT               (0U)
#define CSL_XGE_CPSW_TXDEFERREDFRAMES_COUNT_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_TXDEFERREDFRAMES_COUNT_MAX                 (0xffffffffU)

#define CSL_XGE_CPSW_TXDEFERREDFRAMES_RESETVAL                  (0x00000000U)

/* TXCOLLISIONFRAMES */

#define CSL_XGE_CPSW_TXCOLLISIONFRAMES_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXCOLLISIONFRAMES_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_TXCOLLISIONFRAMES_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_TXCOLLISIONFRAMES_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_TXCOLLISIONFRAMES_RESETVAL                 (0x00000000U)

/* TXSINGLECOLLFRAMES */

#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES_COUNT_SHIFT             (0U)
#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES_COUNT_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES_COUNT_MAX               (0xffffffffU)

#define CSL_XGE_CPSW_TXSINGLECOLLFRAMES_RESETVAL                (0x00000000U)

/* TXMULTCOLLFRAMES */

#define CSL_XGE_CPSW_TXMULTCOLLFRAMES_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXMULTCOLLFRAMES_COUNT_SHIFT               (0U)
#define CSL_XGE_CPSW_TXMULTCOLLFRAMES_COUNT_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_TXMULTCOLLFRAMES_COUNT_MAX                 (0xffffffffU)

#define CSL_XGE_CPSW_TXMULTCOLLFRAMES_RESETVAL                  (0x00000000U)

/* TXEXCESSIVECOLLISIONS */

#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS_COUNT_SHIFT          (0U)
#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS_COUNT_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS_COUNT_MAX            (0xffffffffU)

#define CSL_XGE_CPSW_TXEXCESSIVECOLLISIONS_RESETVAL             (0x00000000U)

/* TXLATECOLLISIONS */

#define CSL_XGE_CPSW_TXLATECOLLISIONS_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXLATECOLLISIONS_COUNT_SHIFT               (0U)
#define CSL_XGE_CPSW_TXLATECOLLISIONS_COUNT_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_TXLATECOLLISIONS_COUNT_MAX                 (0xffffffffU)

#define CSL_XGE_CPSW_TXLATECOLLISIONS_RESETVAL                  (0x00000000U)

/* RXIPGERROR */

#define CSL_XGE_CPSW_RXIPGERROR_COUNT_MASK                      (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RXIPGERROR_COUNT_SHIFT                     (0U)
#define CSL_XGE_CPSW_RXIPGERROR_COUNT_RESETVAL                  (0x00000000U)
#define CSL_XGE_CPSW_RXIPGERROR_COUNT_MAX                       (0xffffffffU)

#define CSL_XGE_CPSW_RXIPGERROR_RESETVAL                        (0x00000000U)

/* TXCARRIERSENSEERRORS */

#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS_COUNT_SHIFT           (0U)
#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS_COUNT_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS_COUNT_MAX             (0xffffffffU)

#define CSL_XGE_CPSW_TXCARRIERSENSEERRORS_RESETVAL              (0x00000000U)

/* TXOCTETS */

#define CSL_XGE_CPSW_TXOCTETS_COUNT_MASK                        (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TXOCTETS_COUNT_SHIFT                       (0U)
#define CSL_XGE_CPSW_TXOCTETS_COUNT_RESETVAL                    (0x00000000U)
#define CSL_XGE_CPSW_TXOCTETS_COUNT_MAX                         (0xffffffffU)

#define CSL_XGE_CPSW_TXOCTETS_RESETVAL                          (0x00000000U)

/* OCTETFRAMES64 */

#define CSL_XGE_CPSW_OCTETFRAMES64_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES64_COUNT_SHIFT                  (0U)
#define CSL_XGE_CPSW_OCTETFRAMES64_COUNT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES64_COUNT_MAX                    (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES64_RESETVAL                     (0x00000000U)

/* OCTETFRAMES65T127 */

#define CSL_XGE_CPSW_OCTETFRAMES65T127_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES65T127_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_OCTETFRAMES65T127_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES65T127_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES65T127_RESETVAL                 (0x00000000U)

/* OCTETFRAMES128T255 */

#define CSL_XGE_CPSW_OCTETFRAMES128T255_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES128T255_COUNT_SHIFT             (0U)
#define CSL_XGE_CPSW_OCTETFRAMES128T255_COUNT_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES128T255_COUNT_MAX               (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES128T255_RESETVAL                (0x00000000U)

/* OCTETFRAMES256T511 */

#define CSL_XGE_CPSW_OCTETFRAMES256T511_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES256T511_COUNT_SHIFT             (0U)
#define CSL_XGE_CPSW_OCTETFRAMES256T511_COUNT_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES256T511_COUNT_MAX               (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES256T511_RESETVAL                (0x00000000U)

/* OCTETFRAMES512T1023 */

#define CSL_XGE_CPSW_OCTETFRAMES512T1023_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES512T1023_COUNT_SHIFT            (0U)
#define CSL_XGE_CPSW_OCTETFRAMES512T1023_COUNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES512T1023_COUNT_MAX              (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES512T1023_RESETVAL               (0x00000000U)

/* OCTETFRAMES1024TUP */

#define CSL_XGE_CPSW_OCTETFRAMES1024TUP_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_XGE_CPSW_OCTETFRAMES1024TUP_COUNT_SHIFT             (0U)
#define CSL_XGE_CPSW_OCTETFRAMES1024TUP_COUNT_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_OCTETFRAMES1024TUP_COUNT_MAX               (0xffffffffU)

#define CSL_XGE_CPSW_OCTETFRAMES1024TUP_RESETVAL                (0x00000000U)

/* NETOCTETS */

#define CSL_XGE_CPSW_NETOCTETS_COUNT_MASK                       (0xFFFFFFFFU)
#define CSL_XGE_CPSW_NETOCTETS_COUNT_SHIFT                      (0U)
#define CSL_XGE_CPSW_NETOCTETS_COUNT_RESETVAL                   (0x00000000U)
#define CSL_XGE_CPSW_NETOCTETS_COUNT_MAX                        (0xffffffffU)

#define CSL_XGE_CPSW_NETOCTETS_RESETVAL                         (0x00000000U)

/* RX_BOTTOM_OF_FIFO_DROP */

#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP_COUNT_SHIFT         (0U)
#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP_COUNT_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP_COUNT_MAX           (0xffffffffU)

#define CSL_XGE_CPSW_RX_BOTTOM_OF_FIFO_DROP_RESETVAL            (0x00000000U)

/* PORTMASK_DROP */

#define CSL_XGE_CPSW_PORTMASK_DROP_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_XGE_CPSW_PORTMASK_DROP_COUNT_SHIFT                  (0U)
#define CSL_XGE_CPSW_PORTMASK_DROP_COUNT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_PORTMASK_DROP_COUNT_MAX                    (0xffffffffU)

#define CSL_XGE_CPSW_PORTMASK_DROP_RESETVAL                     (0x00000000U)

/* RX_TOP_OF_FIFO_DROP */

#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP_COUNT_SHIFT            (0U)
#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP_COUNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP_COUNT_MAX              (0xffffffffU)

#define CSL_XGE_CPSW_RX_TOP_OF_FIFO_DROP_RESETVAL               (0x00000000U)

/* ALE_RATE_LIMIT_DROP */

#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP_COUNT_SHIFT            (0U)
#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP_COUNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP_COUNT_MAX              (0xffffffffU)

#define CSL_XGE_CPSW_ALE_RATE_LIMIT_DROP_RESETVAL               (0x00000000U)

/* ALE_VID_INGRESS_DROP */

#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP_COUNT_SHIFT           (0U)
#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP_COUNT_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP_COUNT_MAX             (0xffffffffU)

#define CSL_XGE_CPSW_ALE_VID_INGRESS_DROP_RESETVAL              (0x00000000U)

/* ALE_DA_EQ_SA_DROP */

#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_ALE_DA_EQ_SA_DROP_RESETVAL                 (0x00000000U)

/* ALE_UNKN_UNI */

#define CSL_XGE_CPSW_ALE_UNKN_UNI_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_COUNT_SHIFT                   (0U)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_COUNT_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_COUNT_MAX                     (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_UNI_RESETVAL                      (0x00000000U)

/* ALE_UNKN_UNI_BCNT */

#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_UNI_BCNT_RESETVAL                 (0x00000000U)

/* ALE_UNKN_MLT */

#define CSL_XGE_CPSW_ALE_UNKN_MLT_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_COUNT_SHIFT                   (0U)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_COUNT_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_COUNT_MAX                     (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_MLT_RESETVAL                      (0x00000000U)

/* ALE_UNKN_MLT_BCNT */

#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_MLT_BCNT_RESETVAL                 (0x00000000U)

/* ALE_UNKN_BRD */

#define CSL_XGE_CPSW_ALE_UNKN_BRD_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_COUNT_SHIFT                   (0U)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_COUNT_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_COUNT_MAX                     (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_BRD_RESETVAL                      (0x00000000U)

/* ALE_UNKN_BRD_BCNT */

#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT_COUNT_MASK               (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT_COUNT_SHIFT              (0U)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT_COUNT_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT_COUNT_MAX                (0xffffffffU)

#define CSL_XGE_CPSW_ALE_UNKN_BRD_BCNT_RESETVAL                 (0x00000000U)

/* ALE_POL_MATCH */

#define CSL_XGE_CPSW_ALE_POL_MATCH_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_XGE_CPSW_ALE_POL_MATCH_COUNT_SHIFT                  (0U)
#define CSL_XGE_CPSW_ALE_POL_MATCH_COUNT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_ALE_POL_MATCH_COUNT_MAX                    (0xffffffffU)

#define CSL_XGE_CPSW_ALE_POL_MATCH_RESETVAL                     (0x00000000U)

/* TX_MEMORY_PROTECT_ERROR */

#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR_COUNT_SHIFT        (0U)
#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR_COUNT_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR_COUNT_MAX          (0xffffffffU)

#define CSL_XGE_CPSW_TX_MEMORY_PROTECT_ERROR_RESETVAL           (0x00000000U)

/* ID_VER_REG */

#define CSL_XGE_CPSW_ID_VER_REG_MINOR_VER_MASK                  (0x0000003FU)
#define CSL_XGE_CPSW_ID_VER_REG_MINOR_VER_SHIFT                 (0U)
#define CSL_XGE_CPSW_ID_VER_REG_MINOR_VER_RESETVAL              (0x00000000U)
#define CSL_XGE_CPSW_ID_VER_REG_MINOR_VER_MAX                   (0x0000003fU)

#define CSL_XGE_CPSW_ID_VER_REG_CUSTOM_VER_MASK                 (0x000000C0U)
#define CSL_XGE_CPSW_ID_VER_REG_CUSTOM_VER_SHIFT                (6U)
#define CSL_XGE_CPSW_ID_VER_REG_CUSTOM_VER_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_ID_VER_REG_CUSTOM_VER_MAX                  (0x00000003U)

#define CSL_XGE_CPSW_ID_VER_REG_MAJOR_VER_MASK                  (0x00000700U)
#define CSL_XGE_CPSW_ID_VER_REG_MAJOR_VER_SHIFT                 (8U)
#define CSL_XGE_CPSW_ID_VER_REG_MAJOR_VER_RESETVAL              (0x00000000U)
#define CSL_XGE_CPSW_ID_VER_REG_MAJOR_VER_MAX                   (0x00000007U)

#define CSL_XGE_CPSW_ID_VER_REG_RTL_VER_MASK                    (0x0000F800U)
#define CSL_XGE_CPSW_ID_VER_REG_RTL_VER_SHIFT                   (11U)
#define CSL_XGE_CPSW_ID_VER_REG_RTL_VER_RESETVAL                (0x00000000U)
#define CSL_XGE_CPSW_ID_VER_REG_RTL_VER_MAX                     (0x0000001fU)

#define CSL_XGE_CPSW_ID_VER_REG_IDENT_MASK                      (0xFFFF0000U)
#define CSL_XGE_CPSW_ID_VER_REG_IDENT_SHIFT                     (16U)
#define CSL_XGE_CPSW_ID_VER_REG_IDENT_RESETVAL                  (0x00000000U)
#define CSL_XGE_CPSW_ID_VER_REG_IDENT_MAX                       (0x0000ffffU)

#define CSL_XGE_CPSW_ID_VER_REG_RESETVAL                        (0x00000000U)

/* CONTROL_REG */

#define CSL_XGE_CPSW_CONTROL_REG_VLAN_AWARE_MASK                (0x00000002U)
#define CSL_XGE_CPSW_CONTROL_REG_VLAN_AWARE_SHIFT               (1U)
#define CSL_XGE_CPSW_CONTROL_REG_VLAN_AWARE_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_VLAN_AWARE_MAX                 (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_ENABLE_MASK                 (0x00000004U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_ENABLE_SHIFT                (2U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_ENABLE_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_ENABLE_MAX                  (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED_MASK        (0x00000008U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED_SHIFT       (3U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED_MAX         (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED_MASK        (0x00000010U)
#define CSL_XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED_SHIFT       (4U)
#define CSL_XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED_MAX         (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_TYPE_MASK            (0x00001000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_TYPE_SHIFT           (12U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_TYPE_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_TYPE_MAX             (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE_MASK          (0x00002000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE_SHIFT         (13U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE_MAX           (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PAD_MASK                 (0x00004000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PAD_SHIFT                (14U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PAD_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PAD_MAX                  (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR_MASK        (0x00008000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR_SHIFT       (15U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR_MAX         (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_EEE_ENABLE_MASK                (0x00010000U)
#define CSL_XGE_CPSW_CONTROL_REG_EEE_ENABLE_SHIFT               (16U)
#define CSL_XGE_CPSW_CONTROL_REG_EEE_ENABLE_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_EEE_ENABLE_MAX                 (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_ECC_CRC_MODE_MASK              (0x80000000U)
#define CSL_XGE_CPSW_CONTROL_REG_ECC_CRC_MODE_SHIFT             (31U)
#define CSL_XGE_CPSW_CONTROL_REG_ECC_CRC_MODE_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_CONTROL_REG_ECC_CRC_MODE_MAX               (0x00000001U)

#define CSL_XGE_CPSW_CONTROL_REG_RESETVAL                       (0x00000000U)

/* EM_CONTROL_REG */

#define CSL_XGE_CPSW_EM_CONTROL_REG_FREE_MASK                   (0x00000001U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_FREE_SHIFT                  (0U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_FREE_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_FREE_MAX                    (0x00000001U)

#define CSL_XGE_CPSW_EM_CONTROL_REG_SOFT_MASK                   (0x00000002U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_SOFT_SHIFT                  (1U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_SOFT_RESETVAL               (0x00000000U)
#define CSL_XGE_CPSW_EM_CONTROL_REG_SOFT_MAX                    (0x00000001U)

#define CSL_XGE_CPSW_EM_CONTROL_REG_RESETVAL                    (0x00000000U)

/* STAT_PORT_EN_REG */

#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN_MASK           (0x00000001U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN_SHIFT          (0U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN_MASK           (0x00000002U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN_SHIFT          (1U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_STAT_PORT_EN_REG_RESETVAL                  (0x00000000U)

/* SOFT_IDLE_REG */

#define CSL_XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE_MASK               (0x00000001U)
#define CSL_XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE_SHIFT              (0U)
#define CSL_XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE_MAX                (0x00000001U)

#define CSL_XGE_CPSW_SOFT_IDLE_REG_RESETVAL                     (0x00000000U)

/* EEE_PRESCALE_REG */

#define CSL_XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE_MASK         (0x00000FFFU)
#define CSL_XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE_SHIFT        (0U)
#define CSL_XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE_MAX          (0x00000fffU)

#define CSL_XGE_CPSW_EEE_PRESCALE_REG_RESETVAL                  (0x00000000U)

/* P0_CONTROL_REG */

#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN_MASK           (0x00000002U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN_SHIFT          (1U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN_MASK           (0x00000004U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN_SHIFT          (2U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN_MAX            (0x00000001U)

#define CSL_XGE_CPSW_P0_CONTROL_REG_RESETVAL                    (0x00000000U)

/* P0_FLOW_ID_OFFSET_REG */

#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE_MASK           (0x000000FFU)
#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE_SHIFT          (0U)
#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE_MAX            (0x000000ffU)

#define CSL_XGE_CPSW_P0_FLOW_ID_OFFSET_REG_RESETVAL             (0x00000000U)

/* P0_BLK_CNT_REG */

#define CSL_XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT_MASK             (0x0000003FU)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT_SHIFT            (0U)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT_MAX              (0x0000003fU)

#define CSL_XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT_MASK             (0x00001F00U)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT_SHIFT            (8U)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT_MAX              (0x0000001fU)

#define CSL_XGE_CPSW_P0_BLK_CNT_REG_RESETVAL                    (0x00000000U)

/* P0_PORT_VLAN_REG */

#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID_MASK             (0x00000FFFU)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID_SHIFT            (0U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID_MAX              (0x00000fffU)

#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI_MASK             (0x00001000U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI_SHIFT            (12U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI_MAX              (0x00000001U)

#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI_MASK             (0x0000E000U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI_SHIFT            (13U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI_MAX              (0x00000007U)

#define CSL_XGE_CPSW_P0_PORT_VLAN_REG_RESETVAL                  (0x00000000U)

/* P0_PRI_CTL_REG */

#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM_MASK                (0x000000FFU)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM_SHIFT               (0U)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM_MAX                 (0x000000ffU)

#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_PTYPE_MASK               (0x00000100U)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_PTYPE_SHIFT              (8U)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_PTYPE_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RX_PTYPE_MAX                (0x00000001U)

#define CSL_XGE_CPSW_P0_PRI_CTL_REG_RESETVAL                    (0x00000000U)

/* P0_RX_PRI_MAP_REG */

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0_MASK                (0x00000007U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0_SHIFT               (0U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1_MASK                (0x00000070U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1_SHIFT               (4U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2_MASK                (0x00000700U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2_SHIFT               (8U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3_MASK                (0x00007000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3_SHIFT               (12U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4_MASK                (0x00070000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4_SHIFT               (16U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5_MASK                (0x00700000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5_SHIFT               (20U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6_MASK                (0x07000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6_SHIFT               (24U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7_MASK                (0x70000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7_SHIFT               (28U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7_MAX                 (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_PRI_MAP_REG_RESETVAL                 (0x00000000U)

/* P0_RX_MAXLEN_REG */

#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN_MASK            (0x00003FFFU)
#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN_SHIFT           (0U)
#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN_MAX             (0x00003fffU)

#define CSL_XGE_CPSW_P0_RX_MAXLEN_REG_RESETVAL                  (0x00000000U)

/* P0_IDLE2LPI_REG */

#define CSL_XGE_CPSW_P0_IDLE2LPI_REG_COUNT_MASK                 (0x00FFFFFFU)
#define CSL_XGE_CPSW_P0_IDLE2LPI_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_P0_IDLE2LPI_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_P0_IDLE2LPI_REG_COUNT_MAX                  (0x00ffffffU)

#define CSL_XGE_CPSW_P0_IDLE2LPI_REG_RESETVAL                   (0x00000000U)

/* P0_LPI2WAKE_REG */

#define CSL_XGE_CPSW_P0_LPI2WAKE_REG_COUNT_MASK                 (0x00FFFFFFU)
#define CSL_XGE_CPSW_P0_LPI2WAKE_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_P0_LPI2WAKE_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_P0_LPI2WAKE_REG_COUNT_MAX                  (0x00ffffffU)

#define CSL_XGE_CPSW_P0_LPI2WAKE_REG_RESETVAL                   (0x00000000U)

/* P0_EEE_STATUS_REG */

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_MASK       (0x00000001U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_SHIFT      (0U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI_MAX        (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI_MASK              (0x00000002U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI_SHIFT             (1U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI_MAX               (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI_MASK              (0x00000004U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI_SHIFT             (2U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI_MAX               (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE_MASK             (0x00000008U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE_SHIFT            (3U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE_RESETVAL         (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE_MAX              (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD_MASK        (0x00000010U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD_SHIFT       (4U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD_MAX         (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_MASK       (0x00000020U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_SHIFT      (5U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY_MAX        (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_MASK       (0x00000040U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_SHIFT      (6U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_RESETVAL   (0x00000000U)
#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY_MAX        (0x00000001U)

#define CSL_XGE_CPSW_P0_EEE_STATUS_REG_RESETVAL                 (0x00000000U)

/* P0_RX_DSCP_MAP_REG */

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0_MASK               (0x00000007U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0_SHIFT              (0U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1_MASK               (0x00000070U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1_SHIFT              (4U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2_MASK               (0x00000700U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2_SHIFT              (8U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3_MASK               (0x00007000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3_SHIFT              (12U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4_MASK               (0x00070000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4_SHIFT              (16U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5_MASK               (0x00700000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5_SHIFT              (20U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6_MASK               (0x07000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6_SHIFT              (24U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7_MASK               (0x70000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7_SHIFT              (28U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7_MAX                (0x00000007U)

#define CSL_XGE_CPSW_P0_RX_DSCP_MAP_REG_RESETVAL                (0x00000000U)

/* P0_PRI_SEND_REG */

#define CSL_XGE_CPSW_P0_PRI_SEND_REG_COUNT_MASK                 (0x0003FFFFU)
#define CSL_XGE_CPSW_P0_PRI_SEND_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_P0_PRI_SEND_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_P0_PRI_SEND_REG_COUNT_MAX                  (0x0003ffffU)

#define CSL_XGE_CPSW_P0_PRI_SEND_REG_RESETVAL                   (0x00000000U)

/* P0_PRI_IDLE_REG */

#define CSL_XGE_CPSW_P0_PRI_IDLE_REG_COUNT_MASK                 (0x0003FFFFU)
#define CSL_XGE_CPSW_P0_PRI_IDLE_REG_COUNT_SHIFT                (0U)
#define CSL_XGE_CPSW_P0_PRI_IDLE_REG_COUNT_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_P0_PRI_IDLE_REG_COUNT_MAX                  (0x0003ffffU)

#define CSL_XGE_CPSW_P0_PRI_IDLE_REG_RESETVAL                   (0x00000000U)

/* P0_SRC_ID_A_REG */

#define CSL_XGE_CPSW_P0_SRC_ID_A_REG_PORT1_MASK                 (0x000000FFU)
#define CSL_XGE_CPSW_P0_SRC_ID_A_REG_PORT1_SHIFT                (0U)
#define CSL_XGE_CPSW_P0_SRC_ID_A_REG_PORT1_RESETVAL             (0x00000000U)
#define CSL_XGE_CPSW_P0_SRC_ID_A_REG_PORT1_MAX                  (0x000000ffU)

#define CSL_XGE_CPSW_P0_SRC_ID_A_REG_RESETVAL                   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
