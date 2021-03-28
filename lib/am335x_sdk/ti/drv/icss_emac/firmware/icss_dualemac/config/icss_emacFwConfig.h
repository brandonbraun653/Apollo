/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*   Copyright (c) 2017-2018 Texas Instruments Incorporated
* 
*  All rights reserved not granted herein.
*  
*  Limited License.  
* 
*  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
*  license under copyrights and patents it now or hereafter owns or controls to 
*  make, have made, use, import, offer to sell and sell ("Utilize") this software 
*  subject to the terms herein.  With respect to the foregoing patent license, 
*  such license is granted  solely to the extent that any such patent is necessary 
*  to Utilize the software alone.  The patent license shall not apply to any 
*  combinations which include this software, other than combinations with devices 
*  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
* 
*  Redistributions must preserve existing copyright notices and reproduce this license 
*  (including the above copyright notice and the disclaimer and (if applicable) source 
*  code license limitations below) in the documentation and/or other materials provided 
*  with the distribution.
*  
*  Redistribution and use in binary form, without modification, are permitted provided 
*  that the following conditions are met:
* 	No reverse engineering, decompilation, or disassembly of this software is 
*   permitted with respect to any software provided in binary form.
* 	Any redistribution and use are licensed by TI for use only with TI Devices.
* 	Nothing shall obligate TI to provide you with source code for the software 
*   licensed and provided to you in object code.
*  
*  If software source code is provided to you, modification and redistribution of the 
*  source code are permitted provided that the following conditions are met:
* 	Any redistribution and use of the source code, including any resulting derivative 
*   works, are licensed by TI for use only with TI Devices.
* 	Any redistribution and use of any object code compiled from the source code
*   and any resulting derivative works, are licensed by TI for use only with TI Devices.
* 
*  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
*  may be used to endorse or promote products derived from this software without 
*  specific prior written permission.
* 
*  DISCLAIMER.
* 
*  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
*  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
*  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
*  GOODS OR SERVICES* LOSS OF USE, DATA, OR PROFITS* OR BUSINESS INTERRUPTION) HOWEVER 
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/ 

/*
* file:   icss_emacFwConfig.h
*
* brief:  Definitions and mapping of Ethernet switch over PRU
*         Includes: 
*         1. Static FW Configuration paramters definition, static configuration is per PRU-ICSS instance
*         2. Dynamic FW Configuration paramers
*         3. Statistics
*         4. Events for switch interaction
*         5. Memory Map and Control Register definition
*
*/

#ifndef ICSS_EMAC_FW_SWITCH__H
#define ICSS_EMAC_FW_SWITCH__H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/icss_emac/icss_emacDrv.h>

#define ICSS_EMAC_FW_BD_SIZE                         (4U)            /* one buffer descriptor is 4 bytes */
#define ICSS_EMAC_FW_BLOCK_SIZE                      (32U)           /* bytes derived from ICSS architecture */


/*Memory Usage of DRAM0/DRAM1 and Shared RAM */
#define EMAC_SPECIFIC_DRAM_START_OFFSET         ((uint32_t)0x1E98U)
#define SWITCH_SPECIFIC_SRAM_START_OFFSET       ((uint32_t)0x400U)
#define SWITCH_SPECIFIC_DRAM1_START_OFFSET      ((uint32_t)0x1D00U)


/* Queues on PHY PORT 1/2, setting max to 16, number of queues requird will depend on protocol/firmware,
    for dual emac, 4 queues per port will be used */
#define ICSS_EMAC_MAX_NUMBER_OF_QUEUES     ((uint32_t)16u)
/* Default number of queues per Port */
#define ICSS_EMAC_NUMBER_OF_QUEUES     ((uint32_t)4u)
/* 48 blocks per max packet  */
/* 2 full sized ETH packets: 96 blocks, 3 packets = 144, 4 packets = 192  */

/* Physical Port queue size. Same for both ports  */
#define ICSS_EMAC_FW_QUEUE_1_SIZE        (97U)           /* Network Management high  */
#define ICSS_EMAC_FW_QUEUE_2_SIZE        (97U)       /* Network Management low  */
#define ICSS_EMAC_FW_QUEUE_3_SIZE        (97U)       /* Protocol specific  */
#define ICSS_EMAC_FW_QUEUE_4_SIZE        (97U)       /* NRT (IP,ARP, ICMP, ?)    */
#define ICSS_EMAC_FW_QUEUE_5_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_6_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_7_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_8_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_9_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_10_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_11_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_12_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_13_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_14_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_15_SIZE        (0U)
#define ICSS_EMAC_FW_QUEUE_16_SIZE        (0U)

/* HOST PORT QUEUES can buffer up to 4 full sized frames per queue  */
#define ICSS_EMAC_FW_HOST_QUEUE_1_SIZE       (194U)      /* Protocol and/or VLAN priority 7 and 6  */
#define ICSS_EMAC_FW_HOST_QUEUE_2_SIZE       (194U)      /* Protocol mid  */
#define ICSS_EMAC_FW_HOST_QUEUE_3_SIZE       (194U)      /* Protocol low  */
#define ICSS_EMAC_FW_HOST_QUEUE_4_SIZE       (194U)      /* NRT (IP, ARP, ICMP ?)  */
#define ICSS_EMAC_FW_HOST_QUEUE_5_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_6_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_7_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_8_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_9_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_10_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_11_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_12_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_13_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_14_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_15_SIZE       (0U)
#define ICSS_EMAC_FW_HOST_QUEUE_16_SIZE       (0U)


#define ICSS_EMAC_FW_COLLISION_QUEUE_SIZE    (48U)

#define ICSS_EMAC_FW_P0_BUFFER_DESC_OFFSET   (SWITCH_SPECIFIC_SRAM_START_OFFSET)

/* EMAC Firmware Version and Feature Information - Beginning of PRU0 and PRU1 DRAM */

/* ICSS_EMAC_FW_FEATURE_OFFSET bitmap
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
Bit 19: 1: PROMISCUOUS MODE ENABLE
*/
#define ICSS_EMAC_FW_FEATURE_OFFSET           (ICSS_EMAC_FW_RELEASE_2_OFFSET + 4U)

/* Reserved for enhanced feature set, future use */
#define ICSS_EMAC_FW_RESERVED_FEATURE_OFFSET (ICSS_EMAC_FW_FEATURE_OFFSET + 4U)


/***************************************************************************
*              General Purpose Statistics, these are present on both PRU0 and PRU1 DRAM
****************************************************************************/
/* Base statistics offset  */
#define ICSS_EMAC_FW_STATISTICS_OFFSET           (0x1F00U)
/*  Needs to be updated anytime a new statistic is added or existing statistics is no longer supported (removed).*/
#define ICSS_EMAC_FW_STAT_SIZE               (0x98U)

/* Offsets from ICSS_EMAC_FW_STATISTICS_OFFSET */
#define ICSS_EMAC_FW_STORM_PREVENTION_OFFSET         (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE)         /*4 bytes */
#define ICSS_EMAC_FW_PHY_SPEED_OFFSET                (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 4U)    /*4 bytes*/
#define ICSS_EMAC_FW_PORT_STATUS_OFFSET              (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 8U)    /*1 byte */
#define ICSS_EMAC_FW_COLLISION_COUNTER               (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 9U)    /*1 byte */
#define ICSS_EMAC_FW_RX_PKT_SIZE_OFFSET              (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 10U)   /*4 bytes */
#define ICSS_EMAC_FW_PORT_CONTROL_ADDR               (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 14U)   /*4 bytes   */
#define ICSS_EMAC_FW_PORT_MAC_ADDR                   (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 18U)   /*6 bytes   */
#define ICSS_EMAC_FW_RX_INT_STATUS_OFFSET            (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 24U)   /*1 byte */
#define ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_MC      (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 25U)   /*4 bytes */
#define ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_UC      (ICSS_EMAC_FW_STATISTICS_OFFSET + ICSS_EMAC_FW_STAT_SIZE + 29U)   /*4 bytes */


/* DRAM1 Offsets for Switch*/
#define ICSS_EMAC_FW_P0_COL_QUEUE_DESC_OFFSET    (0x1E64U)      /* collision descriptor of port 0  */
#define ICSS_EMAC_FW_P0_QUEUE_DESC_OFFSET    (0x1E7CU)           /* 4 queue descriptors for port 0 (host receive)  */

#define ICSS_EMAC_FW_INTERFACE_MAC_ADDR_OFFSET              (0x1E58U)      /* Interface MAC Address  */
#define ICSS_EMAC_FW_COLLISION_STATUS_ADDR       (0x1E60U)      /* Collision Status Register, P0: bit 0 is pending flag, bit 1..2 inidicates which queue,  */
                                                       /* P1: bit 8 is pending flag, 9..10 is queue number  */
                                                       /* p2: bit 16 is pending flag, 17..18 is queue number, remaining bits are 0.  */

/*  DRAM Offsets for EMAC. Present on Both DRAM0 and DRAM1 */
/* EMAC Time Triggered Send Base Offset Base, the following offsets are calcuated during init time by the driver, no changes expected in FW:
    used by the driver, do not expect these offsets to change, same for all variants of Firmware 
 *       ICSS_EMAC_TTS_CYCLE_START_OFFSET           (ICSS_EMAC_FW_TTS_BASE_OFFSET)
 *       ICSS_EMAC_TTS_CYCLE_PERIOD_OFFSET          (ICSS_EMAC_TTS_CYCLE_START_OFFSET + 8U)
 *       ICSS_EMAC_TTS_CFG_TIME_OFFSET              (ICSS_EMAC_TTS_CYCLE_PERIOD_OFFSET + 4U)
 *       ICSS_EMAC_TTS_STATUS_OFFSET                (ICSS_EMAC_TTS_CFG_TIME_OFFSET + 4U)
 *       ICSS_EMAC_TTS_MISSED_CYCLE_CNT_OFFSET      (ICSS_EMAC_TTS_STATUS_OFFSET + 4U)
 *       ICSS_EMAC_TTS_PREV_TX_SOF                  (ICSS_EMAC_TTS_MISSED_CYCLE_CNT_OFFSET + 4U)  
 *       ICSS_EMAC_TTS_CYC_TX_SOF                   (ICSS_EMAC_TTS_PREV_TX_SOF + 8U)
*/
#define ICSS_EMAC_FW_TTS_BASE_OFFSET                  (EMAC_SPECIFIC_DRAM_START_OFFSET)



/* Used to calculate end of buffer bd offset, not part of Mmap configuration, local usage only */
#define ICSS_EMAC_FW_HOST_BD_SIZE            ((ICSS_EMAC_FW_HOST_QUEUE_1_SIZE + ICSS_EMAC_FW_HOST_QUEUE_2_SIZE + ICSS_EMAC_FW_HOST_QUEUE_3_SIZE + ICSS_EMAC_FW_HOST_QUEUE_4_SIZE) * ICSS_EMAC_FW_BD_SIZE)
#define ICSS_EMAC_FW_PORT_BD_SIZE            ((ICSS_EMAC_FW_QUEUE_1_SIZE + ICSS_EMAC_FW_QUEUE_2_SIZE + ICSS_EMAC_FW_QUEUE_3_SIZE + ICSS_EMAC_FW_QUEUE_4_SIZE) * 2U * ICSS_EMAC_FW_BD_SIZE)


#define ICSS_EMAC_FW_EOF_BUFFER_BD           (ICSS_EMAC_FW_P0_BUFFER_DESC_OFFSET + ICSS_EMAC_FW_HOST_BD_SIZE + ICSS_EMAC_FW_PORT_BD_SIZE)
#define ICSS_EMAC_FW_P0_COL_BD_OFFSET        (ICSS_EMAC_FW_EOF_BUFFER_BD)

/*  Shared RAM offsets for EMAC, Q2/Q3/Q4 derived from Q1 */
/* Host Port Rx Context OFFSET*/

/* EMAC Firmware Version Information */
#define ICSS_EMAC_FW_RELEASE_1_OFFSET                       (0U)
#define ICSS_EMAC_FW_RELEASE_2_OFFSET                       (ICSS_EMAC_FW_RELEASE_1_OFFSET + 4U)

#define ICSS_EMAC_FW_PROMISCUOUS_MODE_OFFSET                (ICSS_EMAC_FW_EOF_BUFFER_BD + 4U)
#define ICSS_EMAC_FW_HOST_Q1_RX_CONTEXT_OFFSET              (ICSS_EMAC_FW_PROMISCUOUS_MODE_OFFSET + 4U)

/*DRAM1 Offsets for EMAC */
/*table offset for Port queue descriptors: 1 ports * 4 Queues * 2 byte offset = 8 bytes */
#define ICSS_EMAC_FW_PORT_QUEUE_DESC_OFFSET              (EMAC_SPECIFIC_DRAM_START_OFFSET + 32U + 8U)                /* 4 queue descriptors for port tx. 32 bytes  */
#define ICSS_EMAC_FW_EMAC_Q1_TX_CONTEXT_OFFSET           (ICSS_EMAC_FW_PORT_QUEUE_DESC_OFFSET + 32U)

/*DRAM1 Offsets for Switch */
/* TX/RX context offsets */
/* Port 1  */
#define ICSS_EMAC_FW_SWITCH_P1_Q1_TX_CONTEXT_OFFSET            (SWITCH_SPECIFIC_DRAM1_START_OFFSET)

/* Memory Usage of L3 OCMC RAM */
/* L3 64KB Memory - mainly buffer Pool
 * put collision buffer at end of L3 memory. Simplifies PRU coding to be on same memory as queue buffer  
    Note: Buffer queues for port 1 and port 2 are derived from base offset of Port 0*/
#define ICSS_EMAC_FW_HOST_P0_Q1_BUFFER_OFFSET         (0x0000U)


#define ICSS_EMAC_FW_P0_COL_BUFFER_OFFSET        (0xEE00U) /* 1536 byte collision buffer for port 0 send queue  */



#define ICSS_EMAC_FW_TX_QUEUES_BUFFER_OFFSET   (0U)

/**
 * \brief  This API gets the ICSS-EMAC  firmware Memory Map intial configuration
 *
 *  @param[in]  instance      PRU-ICSS instance
 *  @param[in]  ppStaticMMap  Address of pointer to be set to static MMap configuration structure.
 *  @param[in]  ppDynamicMMap Address of pointer to be set to dynamic MMap configuration structure.
 *
 * \return 0 success: -1: error
 *
 */
int32_t icss_emacGetFwMMapInitConfig(uint32_t instance, ICSS_EmacFwStaticMmap **ppStaticMMap, ICSS_EmacFwDynamicMmap **ppDynamicMMap);


/**
 * \brief  This API sets the ICSS-EMAC firmware Memory Map intial configuration, this API MUST be
 *         called prior to calling ICSS_EmacInit()
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  instance     PRU-ICSS instance
 *  @param[in]  staticCfg       Pointer to ICSS-EMAC firmware Memory Map initial static config.
 *  @param[in]  dynamicCfg       Pointer to ICSS-EMAC firmware Memory Map initial dynamic config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t icss_emacSetFwMMapInitConfig(ICSS_EmacHandle icssEmacHandle, uint32_t instance, ICSS_EmacFwStaticMmap *staticCfg, ICSS_EmacFwDynamicMmap *dynamicCfg);



#ifdef __cplusplus
}
#endif

#endif  /* ICSS_EMAC_FW_SWITCH__H */

