
/*
* file:   icss_emacLoc.h
*
* brief:  Local function declarations 
*/

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef ICSS_EMAC_LOC_H
#define ICSS_EMAC_LOC_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>

#include <ti/csl/src/ip/icss/V1/cslr_icss_intc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_iep.h>
#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
#elif defined (SOC_AM65XX)
#include <ti/csl/csl_mdio.h>
#else
#include <ti/csl/csl_mdioAux.h>
#endif
/***************************************************************************
*                       LINK/DUPLEX MACROS & MASKS                         *
*  Bits for Port Status and Duplexity. This is set by ARM and read by FW   *
*          Possible to add more info as bits 2-7 are free                  *
****************************************************************************
*/
#define ICSS_EMAC_PORT_LINK_MASK        	(0x1U)
#define ICSS_EMAC_PORT_IS_HD_MASK         (0x2U)

/* ICSS_EmacPollLink can be called from ISR or from actual poll, these defines depect those 2 cases, local to LLD*/
#define ICSS_EMAC_POLL_FROM_ISR                     0x1U
#define ICSS_EMAC_POLL_FROM_POLL_LINK               0x2U


/* NRT Buffer descriptor definition
 Each buffer descriptor points to a max 32 byte block and has 32 bit in size to have atomic operation.
 PRU can address bytewise into memory.
 Definition of 32 bit desriptor is as follows

 Bits		Name			Meaning
 ==================================================================================================
 0..7 	Index			points to index in buffer queue, max 256 x 32 byte blocks can be addressed
 8..12	Block_length    number of valid bytes in this specific block. Will be <=32 bytes on last block of packet
 13		More			"More" bit indicating that there are more blocks for the 
 14 		Shadow			inidcates that "index" is pointing into shadow buffer
 15		TimeStamp		indicates that this packet has time stamp in seperate buffer - only needed of PTCP runs on host
 16..17	Port			different meaning for ingress and egress, ingress Port=0 inidcates phy port 1 and Port = 1
							inidcates phy port 2. Egress: 0 sends on phy port 1 and 1 sends on phy port 2. Port = 2 goes
 							over MAC table look-up
 18..28   Length			11 bit of total packet length which is put into first BD only so that host access only one BD
 29		VlanTag			indicates that packet has Length/Type field of 0x08100 with VLAN tag in following byte
 30		Broadcast		inidcates that packet goes out on both physical ports,  there will be two bd but only one buffer
 31		Error			indicates there was an error in the packet
  */
 
/* NRT Queue Defintion
 Each port has up to 4 queues with variable length. The queus is processed as ring buffer with read and write pointer.
 Both pointer are address pointers and increment by 4 for each buffer descriptor/position. 
 Queue has a length defined in constants and a status. Status is defined as described below

 Bits		Name 			Meaning
 =====================================================================================================
 0 		Busy_M			This queue is busy by the master port which is the PRU receiving packets from the master
 1		Collision		Slave is/has written into shadow queue, both descriptors and data. 
 2		Overflow		there was not enough space to write to queue and packet was discarded
 4..7    	Reserved		reserved

 There is busy slave flag in different byte address to grant access to queue to master in case
 of simultaneous access. Host will alwasys be slave in this case. The PRU which is sending the
 packet on phy port will be the master. When both PRUs wants to write to host queues PRU0
 is master and PRU1 is slave. 

 Bits		Name 			Meaning
 =====================================================================================================
 0 		Busy_S			This queue is busy by the master port which is the PRU receiving packets from the master
 1..7		Reserved

 Length is the number of 32 byte blocks per queue. max_fill_level tells the minimum distance between write and read pointer.
 over_flow_cnt tells how many times the write pointer runs into the read_pointer.
  */

typedef struct ICSS_EmacQueue_s {
    uint16_t  rd_ptr;
    uint16_t  wr_ptr;
    uint8_t	busy_s;
    uint8_t   status;
    uint8_t   max_fill_level;
    uint8_t   overflow_cnt;
} ICSS_EmacQueue;

#define    ICSS_EMAC_Q_MAX_FILL_LEVEL_OFFSET     (6U)
#define    ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET       (7U)

/* EMAC Time Triggered Send Status Bit Masks */
#define ICSS_EMAC_TTS_PRU_ENABLE_MASK                   ((uint32_t)0x1U)
#define ICSS_EMAC_TTS_MISSED_CYCLE_MASK                 ((ICSS_EMAC_TTS_PRU_ENABLE_MASK) << 1)
#define ICSS_EMAC_TTS_INSERT_CYC_FRAME_MASK             ((ICSS_EMAC_TTS_MISSED_CYCLE_MASK) << 1)
#define ICSS_EMAC_TTS_CYC_TX_SOF_MASK                   ((ICSS_EMAC_TTS_INSERT_CYC_FRAME_MASK) << 1)
#define ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE_MASK         ((ICSS_EMAC_TTS_CYC_TX_SOF_MASK) << 1)

/* With dynamic configuration of queue size the offsets are variablel. For PRU to find which queue and descriptor needs to be served there  */
/* is a look-up table with index of port and queue number.  */
/* table definition to access queue size, buffer descriptor and buffer  */

/* table offset for queue size: 3 ports * 4 Queues * 1 byte offset = 24 bytes  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_SIZE_ADDR                             (0x1E30U)
/* table offset for queue: 3 ports * 4 Queues * 2 byte offset = 24 bytes  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_OFFSET_ADDR                           	(0x1E18U)
/* table offset for queue descriptors: 3 ports * 4 Queues * 2 byte offset = 24 bytes  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_DESCRIPTOR_OFFSET_ADDR                (0x1E00U)


/**< Firmware MemoryMap Init DONE */
#define ICSS_EMAC_DEFAULT_FW_MMAP_INIT_DONE  0xABCD1234U


/* Keeping a copy of default firmware memory map configuration parameters for backward compatibility BEGIN */
#define ICSS_EMAC_DEFAULT_FW_BD_SIZE                         (4U)            /* one buffer descriptor is 4 bytes */
#define ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE                      (32U)           /* bytes derived from ICSS architecture */


/*Memory Usage of DRAM0/DRAM1 and Shared RAM */
#define EMAC_SPECIFIC_DEFAULT_DRAM_START_OFFSET         ((uint32_t)0x1E98U)
#define SWITCH_SPECIFIC_DEFAULT_SRAM_START_OFFSET       ((uint32_t)0x400U)
#define SWITCH_SPECIFIC_DEFAULT_DRAM1_START_OFFSET      ((uint32_t)0x1D00U)


/* Queues on PHY PORT 1/2, setting max to 16, number of queues requird will depend on protocol/firmware,
    for dual emac, 4 queues per port will be used */
#define ICSS_EMAC_DEFAULT_MAX_NUMBER_OF_QUEUES     ((uint32_t)16)
/* 48 blocks per max packet  */
/* 2 full sized ETH packets: 96 blocks, 3 packets = 144, 4 packets = 192  */

/* Default number of queues per Port */
#define ICSS_EMAC_DEFAULT_NUMBER_OF_QUEUES     ((uint32_t)4U)

/* Physical Port queue size. Same for both ports  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_1_SIZE        ((uint32_t)97U)           /* Network Management high  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_2_SIZE        ((uint32_t)97U)       /* Network Management low  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_3_SIZE        ((uint32_t)97U)       /* Protocol specific  */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_4_SIZE        ((uint32_t)97U)       /* NRT (IP,ARP, ICMP, ?)    */
#define ICSS_EMAC_DEFAULT_FW_QUEUE_5_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_6_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_7_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_8_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_9_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_10_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_11_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_12_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_13_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_14_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_15_SIZE        ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_QUEUE_16_SIZE        ((uint32_t)0U)

/* HOST PORT QUEUES can buffer up to 4 full sized frames per queue  */
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_1_SIZE       ((uint32_t)194U)      /* Protocol and/or VLAN priority 7 and 6  */
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_2_SIZE       ((uint32_t)194U)      /* Protocol mid  */
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_3_SIZE       ((uint32_t)194U)      /* Protocol low  */
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_4_SIZE       ((uint32_t)194U)      /* NRT (IP, ARP, ICMP ?)  */
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_5_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_6_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_7_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_8_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_9_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_10_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_11_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_12_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_13_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_14_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_15_SIZE       ((uint32_t)0U)
#define ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_16_SIZE       ((uint32_t)0U)


#define ICSS_EMAC_DEFAULT_FW_COLLISION_QUEUE_SIZE    (48U)

#define ICSS_EMAC_DEFAULT_FW_P0_BUFFER_DESC_OFFSET   (SWITCH_SPECIFIC_DEFAULT_SRAM_START_OFFSET)



/*  Shared RAM offsets for EMAC, Q2/Q3/Q4 derived from Q1 */
/* Host Port Rx Context OFFSET*/

#define ICSS_EMAC_DEFAULT_FW_PROMISCUOUS_MODE_OFFSET                 (ICSS_EMAC_DEFAULT_FW_EOF_BUFFER_BD + 4U)
#define ICSS_EMAC_DEFAULT_FW_HOST_Q1_RX_CONTEXT_OFFSET               (ICSS_EMAC_DEFAULT_FW_PROMISCUOUS_MODE_OFFSET + 4U)


/* EMAC Firmware Version Information */
#define ICSS_EMAC_DEFAULT_FW_RELEASE_2_OFFSET         (ICSS_EMAC_DEFAULT_FW_RELEASE_1_OFFSET + 4U)
#define ICSS_EMAC_DEFAULT_FW_RELEASE_1_OFFSET         (0U)

/* ICSS_EMAC_FIRMWARE_FEATURE_OFFSET bitmap
Bit 0 1: TTS support
Bit 1 0 : MAC mode 1 : Switch Mode
Bit 2 1: VLAN
Bit 3 : 1 : Storm prevention
Bit 4-Bit 7 : 0: No redundancy 1 : MRP 2 : DLR 3 : HSR 4 : PRP 5 : MRPD
Bit 8-Bit 10 : PTP (0: None 1: IEEE1588 2: PTCP 3: gPTP)
Bit 11 : Reserved
Bit 12-Bit 14 : Number of queues -1
Bit 15: Reserved
Bit 16: 1: PROFINET( CPM/PPM)
Bit 17: 1: DCP filer (PROFINET)
Bit 18: 1: ARP filter (PROFINET)
Bit 19-25: RSVD for other features
Bit 26: Multicast filter
Bit 27: VLAN filtering
*/
#define ICSS_EMAC_DEFAULT_FW_FEATURE_OFFSET           (ICSS_EMAC_DEFAULT_FW_RELEASE_2_OFFSET + 4U)
#define ICSS_EMAC_DEFAULT_FW_RESERVED_FEATURE_OFFSET           (ICSS_EMAC_DEFAULT_FW_FEATURE_OFFSET + 4U)



/***************************************************************************
*              General Purpose Statistics, these are present on both PRU0 and PRU1 DRAM
****************************************************************************/
/* Base statistics offset  */
#define ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET           (0x1F00U)
/*  Needs to be updated anytime a new statistic is added or existing statistics is no longer supported (removed).*/
#define ICSS_EMAC_DEFAULT_FW_STAT_SIZE               (0x98U)

/* Offsets from ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET */
#define ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET         (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE)         /*4 bytes */
#define ICSS_EMAC_DEFAULT_FW_PHY_SPEED_OFFSET                (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 4U)    /*4 bytes*/
#define ICSS_EMAC_DEFAULT_FW_PORT_STATUS_OFFSET              (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 8U)    /*1 byte */
#define ICSS_EMAC_DEFAULT_FW_COLLISION_COUNTER               (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 9U)    /*1 byte */
#define ICSS_EMAC_DEFAULT_FW_RX_PKT_SIZE_OFFSET              (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 10U)   /*4 bytes */
#define ICSS_EMAC_DEFAULT_FW_PORT_CONTROL_ADDR               (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 14U)   /*4 bytes   */
#define ICSS_EMAC_DEFAULT_FW_PORT_MAC_ADDR                   (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 18U)   /*6 bytes   */
#define ICSS_EMAC_DEFAULT_FW_RX_INT_STATUS_OFFSET            (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 24U)   /*1 byte */
#define ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_MC      (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 25U)   /*4 bytes */
#define ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_UC      (ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET + ICSS_EMAC_DEFAULT_FW_STAT_SIZE + 29U)   /*4 bytes */


/* DRAM1 Offsets for Switch*/
#define ICSS_EMAC_DEFAULT_FW_P0_COL_QUEUE_DESC_OFFSET    (0x1E64U)      /* collision descriptor of port 0  */
#define ICSS_EMAC_DEFAULT_FW_P0_QUEUE_DESC_OFFSET    (0x1E7CU)           /* 4 queue descriptors for port 0 (host receive)  */

#define ICSS_EMAC_DEFAULT_FW_INTERFACE_MAC_ADDR_OFFSET              (0x1E58U)      /* Interface MAC Address  */
#define ICSS_EMAC_DEFAULT_FW_COLLISION_STATUS_ADDR       (0x1E60U)      /* Collision Status Register, P0: bit 0 is pending flag, bit 1..2 inidicates which queue,  */
                                                       /* P1: bit 8 is pending flag, 9..10 is queue number  */
                                                       /* p2: bit 16 is pending flag, 17..18 is queue number, remaining bits are 0.  */

/*  DRAM Offsets for EMAC. Present on Both DRAM0 and DRAM1 */
/* EMAC Time Triggered Send Base Offset Base, the following offsets are calcuated during init time by the driver, no changes expected in FW:
    used by the driver, do not expect these offsets to change, same for all variants of Firmware 
 *       ICSS_EMAC_TTS_CYCLE_START_OFFSET           (ICSS_EMAC_DEFAULT_FW_TTS_BASE_OFFSET)
 *       ICSS_EMAC_TTS_CYCLE_PERIOD_OFFSET          (ICSS_EMAC_TTS_CYCLE_START_OFFSET + 8U)
 *       ICSS_EMAC_TTS_CFG_TIME_OFFSET              (ICSS_EMAC_TTS_CYCLE_PERIOD_OFFSET + 4U)
 *       ICSS_EMAC_TTS_STATUS_OFFSET                (ICSS_EMAC_TTS_CFG_TIME_OFFSET + 4U)
 *       ICSS_EMAC_TTS_MISSED_CYCLE_CNT_OFFSET      (ICSS_EMAC_TTS_STATUS_OFFSET + 4U)
 *       ICSS_EMAC_TTS_PREV_TX_SOF                  (ICSS_EMAC_TTS_MISSED_CYCLE_CNT_OFFSET + 4U)  
 *       ICSS_EMAC_TTS_CYC_TX_SOF                   (ICSS_EMAC_TTS_PREV_TX_SOF + 8U)
*/
#define ICSS_EMAC_DEFAULT_FW_TTS_BASE_OFFSET                  (EMAC_SPECIFIC_DEFAULT_DRAM_START_OFFSET)



/* Used to calculate end of buffer bd offset, not part of Mmap configuration, local usage only */
#define ICSS_EMAC_DEFAULT_FW_HOST_BD_SIZE            ((ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_1_SIZE + ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_2_SIZE + ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_3_SIZE + ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_4_SIZE) * ICSS_EMAC_DEFAULT_FW_BD_SIZE)
#define ICSS_EMAC_DEFAULT_FW_PORT_BD_SIZE            ((ICSS_EMAC_DEFAULT_FW_QUEUE_1_SIZE + ICSS_EMAC_DEFAULT_FW_QUEUE_2_SIZE + ICSS_EMAC_DEFAULT_FW_QUEUE_3_SIZE + ICSS_EMAC_DEFAULT_FW_QUEUE_4_SIZE) * 2U * ICSS_EMAC_DEFAULT_FW_BD_SIZE)


#define ICSS_EMAC_DEFAULT_FW_EOF_BUFFER_BD           (ICSS_EMAC_DEFAULT_FW_P0_BUFFER_DESC_OFFSET + ICSS_EMAC_DEFAULT_FW_HOST_BD_SIZE + ICSS_EMAC_DEFAULT_FW_PORT_BD_SIZE)
#define ICSS_EMAC_DEFAULT_FW_P0_COL_BD_OFFSET        (ICSS_EMAC_DEFAULT_FW_EOF_BUFFER_BD)



/*DRAM1 Offsets for EMAC */
/*table offset for Port queue descriptors: 1 ports * 4 Queues * 2 byte offset = 8 bytes */
#define ICSS_EMAC_DEFAULT_FW_PORT_QUEUE_DESC_OFFSET              (EMAC_SPECIFIC_DEFAULT_DRAM_START_OFFSET + 32U + 8U)                /* 4 queue descriptors for port tx. 32 bytes  */
#define ICSS_EMAC_DEFAULT_FW_EMAC_Q1_TX_CONTEXT_OFFSET           (ICSS_EMAC_DEFAULT_FW_PORT_QUEUE_DESC_OFFSET + 32U)

/*DRAM1 Offsets for Switch */
/* TX/RX context offsets */
/* Port 1  */
#define ICSS_EMAC_DEFAULT_FW_SWITCH_P1_Q1_TX_CONTEXT_OFFSET            (SWITCH_SPECIFIC_DEFAULT_DRAM1_START_OFFSET)



/* Memory Usage of L3 OCMC RAM */
/* L3 64KB Memory - mainly buffer Pool
 * put collision buffer at end of L3 memory. Simplifies PRU coding to be on same memory as queue buffer  
    Note: Buffer queues for port 1 and port 2 are derived from base offset of Port 0*/
#define ICSS_EMAC_DEFAULT_FW_HOST_P0_Q1_BUFFER_OFFSET         (0x0000U)


#define ICSS_EMAC_DEFAULT_FW_P0_COL_BUFFER_OFFSET        (0xEE00U) /* 1536 byte collision buffer for port 0 send queue  */



#define ICSS_EMAC_DEFAULT_FW_TX_QUEUES_BUFFER_OFFSET   (0U)


/* Keeping a copy of firmware memory map configuration parameters for backward compatibility END */

/* Firmware feature set defines*/
#define ICSS_EMAC_FW_TTS_FEATURE_SHIFT                  ((uint32_t)0U)
#define ICSS_EMAC_FW_TTS_FEATURE_CTRL                   (((uint32_t)1U) << ICSS_EMAC_FW_TTS_FEATURE_SHIFT)


/* MODE indicates firmware running configuration which can be either dual emac(0U) or switch (1U) MODE */
#define ICSS_EMAC_FW_MODE_FEATURE_SHIFT                 ((uint32_t)1U)
#define ICSS_EMAC_FW_MODE_FEATURE_CTRL                  (((uint32_t)1U) << ICSS_EMAC_FW_MODE_FEATURE_SHIFT)

#define ICSS_EMAC_FW_VLAN_FEATURE_SHIFT                 ((uint32_t)2U)
#define ICSS_EMAC_FW_VLAN_FEATURE_CTRL                  (((uint32_t)1U) << ICSS_EMAC_FW_VLAN_FEATURE_SHIFT)

#define ICSS_EMAC_FW_STORM_PREVENTIION_FEATURE_SHIFT    ((uint32_t)3U)
#define ICSS_EMAC_FW_STORM_PREVENTIION_FEATURE_CTRL     (((uint32_t)1U) << ICSS_EMAC_FW_STORM_PREVENTIION_FEATURE_SHIFT)

#define ICSS_EMAC_FW_PROMISCOUS_MODE_FEATURE_SHIFT    ((uint32_t)19U)
#define ICSS_EMAC_FW_PROMISCOUS_MODE_FEATURE_CTRL     (((uint32_t)1U) << ICSS_EMAC_FW_PROMISCOUS_MODE_FEATURE_SHIFT)

#define ICSS_EMAC_FW_PTP_FEATURE_SHIFT                ((uint32_t)8U)
#define ICSS_EMAC_FW_PTP_FEATURE_CTRL                 (((uint32_t)1U) << ICSS_EMAC_FW_PTP_FEATURE_SHIFT)

#define ICSS_EMAC_FW_MULTICAST_FILTER_FEATURE_SHIFT   ((uint32_t)26U)
#define ICSS_EMAC_FW_MULTICAST_FILTER_FEATURE_CTRL    (((uint32_t)1U) << ICSS_EMAC_FW_MULTICAST_FILTER_FEATURE_SHIFT)

#define ICSS_EMAC_FW_VLAN_FILTER_FEATURE_SHIFT        ((uint32_t)27U)
#define ICSS_EMAC_FW_VLAN_FILTER_FEATURE_CTRL         (((uint32_t)1U) << ICSS_EMAC_FW_VLAN_FILTER_FEATURE_SHIFT)

/**This value in the MDIO Reg means 10 mbps mode is enabled*/
#define Ten_Mbps  0xa
/**This value in the MDIO Reg means 100 mbps mode is enabled*/
#define Hundread_Mbps 0x64

#define LINK0_PRU_EVT_MASK              (0x200U)
#define LINK1_PRU_EVT_MASK              (0x200000U)
#define TX_COMPLETION0_PRU_EVT_MASK        (((uint32_t)1U) << 22)
#define TX_COMPLETION1_PRU_EVT_MASK        (((uint32_t)1U) << 23)
#define TTS_CYC0_PRU_EVT_MASK            (((uint32_t)1U) << 24)
#define TTS_CYC1_PRU_EVT_MASK            (((uint32_t)1U) << 25)
/* Local Functions to LLD to Calculate Offsets and BD/Buffer sizes*/
void ICSS_EmacCalcPort0BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES]);
void ICSS_EmacCalcPort1BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES]);
void ICSS_EmacCalcPort2BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES]);
uint32_t ICSS_EmacCalcTotalPortBDSize(ICSS_EmacHandle icssEmacHandle);
uint32_t ICSS_EmacCalcTotalHostBDSize(ICSS_EmacHandle icssEmacHandle);
uint32_t ICSS_EmacCalcEndOfBufferBD(ICSS_EmacHandle icssEmacHandle);
uint32_t ICSS_EmacCalcEndOfColBufferBD(ICSS_EmacHandle icssEmacHandle);
uint32_t  ICSS_EmacCalcTotalHostBDSize(ICSS_EmacHandle icssEmacHandle);
uint32_t ICSS_EmacCalcTotalPortBDSize(ICSS_EmacHandle icssEmacHandle);
uint32_t ICSS_EmacCalcTotalBufferPoolSize(ICSS_EmacHandle icssEmacHandle);

int32_t ICSS_EmacGetFwMMapInitConfigLocal(ICSS_EmacHandle icssEmacHandle, uint32_t instance);
int8_t ICSS_EmacValidateFeatureSet(ICSS_EmacHandle icssEmacHandle, uint8_t portNo, uint32_t featureCtrl);
void ICSS_EmacMemInit(uint32_t* addr, uint32_t size);
void ICSS_EmacInitLinkState(ICSS_EmacHandle icssEmacHandle, uint8_t interfaceId, uint8_t portNo);

#ifdef __cplusplus
}
#endif

#endif

