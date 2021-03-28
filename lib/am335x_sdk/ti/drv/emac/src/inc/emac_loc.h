/*
 * Copyright (C) 2010-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/*******************************************************************************
* FILE PURPOSE: EMAC LLD Header Local Definitions
*
********************************************************************************
* FILE NAME:    emacloc.h
*
* DESCRIPTION:  This file contains all Local definitions for EMAC LLD.
*******************************************************************************/
#ifndef __EMACLOC_H__
#define __EMACLOC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/emac_hwcfg.h>
#include <ti/csl/csl_emac.h>
/******************************************************************************
 * EMAC Driver Version Definitions
 ******************************************************************************/
#define EMAC_VERSION_STR         " EMAC Driver Revision: 01.00.03.00"


/**********************************************************************
 *********************** Common Local Definitions *********************
 **********************************************************************/
/**
 * @brief   Maximum number of channel can be used by a core on one port
 */
#define MAX_NUM_EMAC_CHANS_PER_CORE         8

/**
 * @brief   Maximum number of MAC address per channel
 */
#define MAX_NUM_EMAC_MAC_ADDR_PER_CHAN      4

/**
 * @brief   Maximum number of channel per EMAC port
 */
#define MAX_NUM_EMAC_CHANS_PER_PORT         8

/**
 * @brief   Max packet descriptors allocated for RX channel
 *          # of packet descriptors allocated for TX channel
 *          is (64-MAX_EMAC_RX_PKT_DESC) on CPPI memory
 */
#define MAX_EMAC_RX_PKT_DESC                8


/**
 * @brief   EMAC application handle number
 */
#define EMAC_APP_HANDLE                     0x12345678

/**
 * @brief   External memory base address
 */
#define EMAC_INVALID_CORE_NUM               0xff

/**
 * @brief   EMAC master channel number (RX filter configuration)
 */
#define EMAC_MASTER_CHAN_NUM                0


/**
 * @brief   EMAC MCB field functions
 */
#define EMAC_CORE_NUM                       emac_mcb.core_num

#define EMAC_MASTER_CORE(port_num)          emac_mcb.core_pcb[port_num].master_core_flag
#define EMAC_MDIO(port_num)                 emac_mcb.core_pcb[port_num].mdio_flag
#define EMAC_NUM_RX_PKTS(port_num)          emac_mcb.core_pcb[port_num].num_of_rx_pkt_desc
#define EMAC_NUM_TXRX_PKTS(port_num)        emac_mcb.core_pcb[port_num].num_of_txrx_pkt_desc
#define EMAC_PKT_SIZE(port_num)             emac_mcb.core_pcb[port_num].max_pkt_size
#define EMAC_NUM_CHANS(port_num)            emac_mcb.core_pcb[port_num].num_of_chans
#define EMAC_CHAN_CFG(port_num)             emac_mcb.core_pcb[port_num].chan_cfg
#define EMAC_NUM_MACADDRS(port_num)         emac_mcb.core_pcb[port_num].total_num_of_macaddrs
#define EMAC_MACADDR_CFG(port_num)          emac_mcb.core_pcb[port_num].macaddr_cfg
#define EMAC_CHAN_BITMAP(port_num)          emac_mcb.core_pcb[port_num].chan_bitmap
#define EMAC_PKT_DESC(port_num)             emac_mcb.core_pcb[port_num].pkt_desc

#define EMAC_RX_QUEUE(port_num)             emac_mcb.core_pcb[port_num].rxQueue
#define EMAC_TX_QUEUE(port_num)             emac_mcb.core_pcb[port_num].txQueue

#define EMAC_CSL_ERROR(port_num)            emac_mcb.core_pcb[port_num].csl_error
#define EMAC_MEM_ERROR(port_num)            emac_mcb.core_pcb[port_num].memory_error
#define EMAC_PORT_ERROR(port_num)           emac_mcb.core_pcb[port_num].port_error
#define EMAC_FATAL_ERROR(port_num)          emac_mcb.core_pcb[port_num].fatal_error

#define EMAC_RX_PKT(port_num, pkt)          emac_mcb.core_pcb[port_num].rx_pkt_cb(port_num, pkt)
#define EMAC_ALLOC_PKT(port_num, size)      emac_mcb.core_pcb[port_num].alloc_pkt_cb(port_num, size)
#define EMAC_FREE_PKT(port_num, pkt)        emac_mcb.core_pcb[port_num].free_pkt_cb(port_num, pkt)

#define EMAC_CORE_CFG(port_num)             emac_mcb.core_pcb[port_num].core_cfg


#define EMAC_COMM_PCB(port_num)             emac_mcb.comm_pcb[port_num]
#define EMAC_COMM_DEV(port_num)             emac_mcb.comm_dev[port_num]


/**********************************************************************
 ****************** EMAC Local Data structure ********************
 **********************************************************************/

/**
 * @brief
 *  EMAC_Pkt Queue Data Structure
 *
 * @details
 *  Maintains the count of queued elements and head and tail to EMAC_Pkt queue.
 */
typedef struct EMAC_PKT_QUEUE_tag
{
    Uint32            Count;
    /**< Number of packets in queue */
    EMAC_Pkt          *pHead;
    /**< Pointer to the first packet */
    EMAC_Pkt          *pTail;
    /**< Pointer to the last packet */
} EMAC_PKT_QUEUE_T;

/**
 * @brief
 *  EMAC channel configuration
 *
 * @details
 *  Maintains the channel number and number of MAC addresses assigned for this channel.
 */
typedef struct EMAC_CHAN_CFG_tag
{
    Uint16               chan_num;
    /**< channel number configured for this core */
    Uint16               num_of_mac_addrs;
   /**< Total number of MAC addresses configured for this channel */

} EMAC_CHAN_CFG_T;

/**
 * @brief
 *  Core specific EMAC port control block
 *
 * @details
 *  Maintains the EMAC port control information of a core
 */
typedef struct EMAC_CORE_PCB_tag
{
    Bool                            master_core_flag;
    /**< Ture: master core configuration */
    Bool                            mdio_flag;
    /**< Ture: EMAC Managed Data I/O enabled */
    Uint32                          num_of_rx_pkt_desc;
    /**< Total number of packet descriptors initialized in the RX queues    */
    Uint32                          num_of_txrx_pkt_desc;
    /**< Total number of packet descriptors initialized in both TX and RX queues    */
    Uint32                          max_pkt_size;
    /**< Maximum size of the packet in bytes */
    Uint32                          num_of_chans;
    /**< Total number of TX/RX channels configured for this core */
    EMAC_CHAN_CFG_T                 chan_cfg[MAX_NUM_EMAC_CHANS_PER_CORE];
    /**< Channels configuration */
    Uint32                          total_num_of_macaddrs;
    /**< Total number of MAC addresses for all the channels configured for this core */
    EMAC_AddrConfig**               macaddr_cfg;
    /**< CSL MAC address configuration */
    Uint32                          chan_bitmap;
    /**< Bit map of TX/RX channels enabled */
    EMAC_Pkt                        pkt_desc[MAX_EMAC_INIT_PKT_DESC];
    /**< Pre-allocated/initialized EMAC packet descriptiors for both TX and RX queues */
    EMAC_PKT_QUEUE_T                txQueue;
    /**< TX packet queue */
    EMAC_PKT_QUEUE_T                rxQueue;
    /**< RX packet queue */

    EMAC_RX_PKT_CALLBACK_FN_T*      rx_pkt_cb;
    /**< RX packet call back function */
    EMAC_ALLOC_PKT_CALLBACK_FN_T*   alloc_pkt_cb;
    /**< Allocate packet call back function */
    EMAC_FREE_PKT_CALLBACK_FN_T*    free_pkt_cb;
    /**< Free packet call back function */

    EMAC_Core                       core_cfg;
    /**< CSL core_configuration */


    Uint32                          csl_error;
    /**< CSL API call returned error */
    Uint32                          memory_error;
    /**< Out of memory error */
    Uint32                          port_error;
    /**< CSL returned EMAC port number error */
    Uint32                          fatal_error;
    /**< EMAC MAC or link down error */

} EMAC_CORE_PCB_T;

/**
 * @brief
 *  Common EMAC Port Control Block used by all the cores
 *
 * @details
 *  Maintains the common control information (channel/MAC address, etc).
 */
typedef struct EMAC_COMMON_PCB_tag
{
    Uint32              chans_used;
    /**< Number of channels used */
    EMAC_LINK_INFO_T    link_info;
    /**< Link status infomation */
    Uint8               core_num[MAX_NUM_EMAC_CHANS_PER_PORT];
    /**< DSP core number of the core that is using the channel,
         if the channel is free, core_num is set to EMAC_INVALID_CORE_NUM */

    /**< To support local packet switching, we also need to add local switching queue,
         channel/MAC address table, the packet descriptor should include # of channels
         completed switch, etc.*/

} EMAC_COMMON_PCB_T;

/**
 * @brief
 *  EMAC Master Control Block
 *
 * @details
 *  Maintains the EMAC control information and error statistics.
 */
typedef struct EMAC_MCB_tag
{
    Uint32              core_num;
    /**< DSP core number */
    EMAC_CORE_PCB_T     core_pcb[MAX_NUM_EMAC_PORTS];
    /**< EMAC port control block */

    EMAC_COMMON_PCB_T*  comm_pcb[MAX_NUM_EMAC_PORTS];
    /**< EMAC common port control block accessed by all the cores */
    EMAC_Device*        comm_dev[MAX_NUM_EMAC_PORTS];
    /**< EMAC common device data passed to CSL */
} EMAC_MCB_T;


/**********************************************************************
 ****************** EMAC Local Functions ********************
 **********************************************************************/

static EMAC_Pkt*
emac_queue_pop
(
    Uint32              port_num,
    EMAC_PKT_QUEUE_T*   pq
);

static void
emac_queue_push
(
    Uint32              port_num,
    EMAC_PKT_QUEUE_T*   pq,
    EMAC_Pkt*           pPktHdr
);

uint32_t MDIO_open( int instNum, uint32_t mdioModeFlags, uint32_t phyAddr, Handle hMDIO,uint32_t macSel);
void MDIO_close( Handle hMDIO );
void MDIO_getStatus( Handle hMDIO, uint32_t *pPhy, uint32_t *pLinkStatus );
uint32_t MDIO_phyRegWrite( volatile uint32_t phyIdx, volatile uint32_t phyReg, Uint16 data );
uint32_t MDIO_timerTick( Handle hMDIO);
uint32_t MDIO_initPHY( Handle hMDIO, volatile uint32_t phyAddr );

Uint32 EMAC_commonInit( int instNum, EMAC_Common_Config *pEMACCommonConfig, Handle hEMAC, Uint32 macsel);
Uint32 EMAC_coreDeInit(Handle hEMAC);
Uint32 EMAC_coreInit(Handle hEMAC, Handle hApplication, EMAC_Core_Config *pEMACCoreConfig, Handle hCore);
Uint32 EMAC_close(Handle hEMAC);
Uint32 EMAC_setReceiveFilter(Handle hEMAC, Uint32 ReceiveFilter, Uint8 masterChannel);
Uint32 EMAC_setMulticast(Handle hEMAC, Uint32 AddrCnt, Uint8 *pMCastList);
Uint32 EMAC_sendPacket(Handle hEMAC, EMAC_Pkt *pPkt);
Uint32 EMAC_getStatistics(Handle hEMAC, EMAC_Statistics *pStatistics);
Uint32 EMAC_TxServiceCheck(Handle hEMAC);
Uint32 EMAC_RxServiceCheck(Handle hEMAC);

/**********************************************************************
 ***************************** EMAC Macros ****************************
 **********************************************************************/
#ifdef EMAC_DEBUG
#define emac_debug_print(args)      printf args  
#else
#define emac_debug_print(args)      /* Do nothing */
#endif

#ifdef __cplusplus
}
#endif


#endif /* __EMACLOC_H__ */
