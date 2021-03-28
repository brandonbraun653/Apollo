/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
*  @file       emac_drv_v4.h
 *  ============================================================================
 */

#ifndef EMAC_DRV_V4_H
#define EMAC_DRV_V4_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/emac/src/v4/emac_cpsw.h>

/* only 1 Tx/Rx channel. Resort to Multiple channels when QOS/Prirority is needed
  * When using multiple channels, the switch must be configured for Rx Channel Mapping
  * based on switch prority and also the Rx CPPI service routine will have to be suitably
  * modified for priority/channel based servicing(from CPPI dma perspective all
  * Rx Channels have same priority, hence only way of handling priority is to implement
  * priority handling policy as part of the RX CPPI completion service mechanism) .
  *
  * Similarly on Tx Path, based on priority/vlan tag we should be enqueuing the packet
  * into corresponding TX Channel(also configure the Tx channels to use priority instead
  * of round robin */
#define EMAC_CPSW_INITPARAM_TXNUMCHAN    1U
#define EMAC_CPSW_INITPARAM_RXNUMCHAN    1U

#define EMAC_CPSW_DEFAULT_CPMACBUSFREQ              (125000000U)
#define EMAC_CPSW_DEFAULT_MDIOTICK                  1000U

/* prescalar divides down to 1ms interval*/
#define EMAC_CPSW_DEFAULT_ALEPRESCALE               (EMAC_CPSW_DEFAULT_CPMACBUSFREQ /1000U)

/*ALE time out value*/
#define EMAC_CPSW_ALE_AGE_OUT_TIME                   300000U
#define EMAC_CPSW_ALE_TICK_PERIOD                    100U

/*
 * Pre-Pad Packet Data Offset
 *
 *   The TCP/IP stack library requires that every packet device
 *   include enough L2 header room for all supported headers. In
 *   order to support PPPoE, this requires a 22 byte L2 header.
 *   Thus, since standard Ethernet is only 14 bytes, we must add
 *   on an additional 8 byte offset, or PPPoE can not function
 *   with our driver.
*/
#define     PKT_PREPAD                      0U

/* Macros to get from port field from packet descriptor */
#define EMAC_PKT_FLAG_FROM_PORT_MASK 0x00030000U
#define EMAC_PKT_FLAG_FROM_PORT_SHIFT 16U

/* Macros to set and get to port field from packet descriptor */
#define EMAC_PKT_FLAG_TO_PORT_MASK (0x00030000U)
#define EMAC_PKT_FLAG_TO_PORT_SHIFT (16U)

/* Macros to set to port enable field in packet descriptor */
#define EMAC_PKT_FLAG_TO_PORT_ENABLE_MASK (0x00100000U)
#define EMAC_PKT_FLAG_TO_PORT_ENABLE_SHIFT (20U)


/* Macro to indicate NO PHY address configuration, driver will not configure any MAC port  with this PHY address*/
#define EMAC_CPSW_NO_PHY_ADDR ((uint32_t)0xFFFFFFFFU)
typedef struct EMAC_PortCbV4_s
{
    bool                            master_core_flag;

    bool                mdio_flag;
    /**< True: configure MDIO                                               */
    void*                   hwi_rx;                /* Hwi object */
    void*                   hwi_tx;                /* Hwi object */
    uint32_t                          num_of_rx_pkt_desc;
    /**< Total number of packet descriptors initialized in the RX queues    */
    uint32_t                          num_of_tx_pkt_desc;
    /**< Total number of packet descriptors initialized in the TX queues    */
    uint32_t                          num_of_rxtx_pkt_desc;
    /**< Total number of packet descriptors initialized in both TX and RX queues    */
    uint32_t                          max_pkt_size;
    /**< MAC address for the port     */
    EMAC_MAC_ADDR_T               macaddr_cfg;
    /**<  MAC address configuration */
    bool                            loop_back;

    /**< Pre-allocated/initialized EMAC packet descriptiors for both TX and RX queues */
    /**< True: packets loop back                                            */
    EMAC_PKT_QUEUE_T                txQueue;
    /**< TX packet queue */
    EMAC_PKT_QUEUE_T                rxQueue;
    /**< RX packet queue */
    
    /**< RX packet call back function */
    EMAC_RX_PKT_CALLBACK_FN_T*      rx_pkt_cb;

    /**< Allocate packet call back function */
    EMAC_ALLOC_PKT_CALLBACK_FN_T*   alloc_pkt_cb;
    /**< Free packet call back function */
    EMAC_FREE_PKT_CALLBACK_FN_T*    free_pkt_cb;
    /** <Rx Semaphore Handle for the emac instance.Required for receiving packets */
   void*                      rxSemaphoreHandle;
    /*!emac open == 1, emac closed == 0 */
       int32_t                 emacState;
} EMAC_PortCbV4;



typedef struct EMAC_McbV4_s
{
    EMAC_PortCbV4 port_cb[EMAC_NUM_MAX_MAC_PORTS];
    EMAC_HwAttrs_V4            hwAttrs[EMAC_NUM_MAX_MAC_PORTS];
    EMAC_Cpsw3gDevice*              localDevice;
} EMAC_McbV4;

/**
 * @brief   EMAC MCB field macros
 */
#define EMAC_LOCAL_DEVICE                           (emac_mcb.localDevice)
#define EMAC_COMM_DEV_CONFIG                        (emac_mcb.localDevice.Config)
#define EMAC_MASTER_CORE(port_num)                  (emac_mcb.port_cb[(port_num)].master_core_flag)
#define EMAC_MDIO(port_num)                         (emac_mcb.port_cb[(port_num)].mdio_flag)
#define EMAC_NUM_RX_PKTS(port_num)                  (emac_mcb.port_cb[(port_num)].num_of_rx_pkt_desc)
#define EMAC_NUM_TX_PKTS(port_num)          (emac_mcb.port_cb[(port_num)].num_of_tx_pkt_desc)
#define EMAC_NUM_TXRX_PKTS(port_num)        (emac_mcb.port_cb[(port_num)].num_of_rxtx_pkt_desc)
#define EMAC_PKT_SIZE(port_num)             (emac_mcb.port_cb[(port_num)].max_pkt_size)
#define EMAC_MACADDR_CFG(port_num)          (emac_mcb.port_cb[(port_num)].macaddr_cfg.addr)
#define EMAC_RX_QUEUE(port_num)             (emac_mcb.port_cb[(port_num)].rxQueue)
#define EMAC_TX_QUEUE(port_num)             (emac_mcb.port_cb[(port_num)].txQueue)
#define EMAC_CSL_ERROR(port_num)            (emac_mcb.port_cb[(port_num)].csl_error)
#define EMAC_MEM_ERROR(port_num)            (emac_mcb.port_cb[(port_num)].memory_error)
#define EMAC_PORT_ERROR(port_num)           (emac_mcb.port_cb[(port_num)].port_error)
#define EMAC_FATAL_ERROR(port_num)          (emac_mcb.port_cb[(port_num)].fatal_error)
#define EMAC_RX_PKT(port_num, pkt)          (emac_mcb.port_cb[(port_num)].rx_pkt_cb((port_num), (pkt)))
#define EMAC_ALLOC_PKT(port_num, size)      (emac_mcb.port_cb[(port_num)].alloc_pkt_cb((port_num), (size)))
#define EMAC_FREE_PKT(port_num, pkt)        (emac_mcb.port_cb[(port_num)].free_pkt_cb((port_num), (pkt)))
#define EMAC_GLOBAL_RX_SEM_HANDLE(port_num) (emac_mcb.port_cb[(port_num)].rxSemaphoreHandle)
#define EMAC_GLOBAL_RX_HWI_HANDLE(port_num) (emac_mcb.port_cb[(port_num)].hwi_rx)
#define EMAC_GLOBAL_TX_HWI_HANDLE(port_num) (emac_mcb.port_cb[(port_num)].hwi_tx)
#define EMAC_CFG_LOOPBACK(port_num)                 (emac_mcb.port_cb[(port_num)].loop_back)

#ifdef __cplusplus
}
#endif

#endif  /* EMAC_DRV_V4_H */

