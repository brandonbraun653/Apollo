/*
 * Copyright (C) 2016-2017 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef EMAC_V1__H
#define EMAC_V1__H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/* CSL include file */
#include <ti/csl/src/ip/mdio/V3/csl_mdio.h> /* directly using V3 version for re-use of existing state machine implementation below*/

/* QMSS LLD include */
#include <ti/drv/qmss/qmss_drv.h>
/* CPPI LLD include */
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

/* EMAC_DRV LLD include */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/nss_if.h>
#include <ti/drv/emac/soc/emac_soc_v1.h>

/* EMAC function table pointer */
extern const EMAC_FxnTable EMAC_FxnTable_v1;

#define EMAC_MAX_NUM_EMAC_PORTS 1
#define EMAC_ETHHDR_SIZE 14
#define EMAC_MIN_ETHERNET_PKT_SIZE 60U
/**
 *  \brief  EMAC_Common_Config
 *
 *  The EMAC_Common_Config structure defines configurations common to all the cors
 *  when the EMAC device is operating. It is passed to the device when the device is 
 *  initialized one time by the master core (EMAC_commonInit()), and remains in effect 
 *  until the device is de-initialized by the master core (EMAC_commonDeInit()).
 *
 *  The following is a short description of the configuration fields:
 *
 *  UseMdio      - Uses MDIO configuration if required. In case of SGMII
 *                 MAC to MAC communication MDIO is not required. If this 
 *                 field is one (1) configures MDIO
 *                          zero (0) does not configure MDIO
 *
 *  ModeFlags    - Specify the Fixed Operating Mode of the Device:
 *      - EMAC_CONFIG_MODEFLG_CHPRIORITY  - Treat TX channels as Priority Levels
 *                                   (Channel 7 is highest, 0 is lowest)
 *      - EMAC_CONFIG_MODEFLG_MACLOOPBACK - Set MAC in Internal Loopback for
 *                                          Testing
 *      - EMAC_CONFIG_MODEFLG_RXCRC       - Include the 4 byte EtherCRC in RX
 *                                          frames
 *      - EMAC_CONFIG_MODEFLG_TXCRC       - Assume TX Frames Include 4 byte
 *                                          EtherCRC
 *      - EMAC_CONFIG_MODEFLG_PASSERROR   - Receive Error Frames for Testing
 *      - EMAC_CONFIG_MODEFLG_PASSCONTROL - Receive Control Frames for
 *                                          Testing
 *
 *  MdioModeFlags - Specify the MDIO/PHY Operation (See csl_MDIO.H)
 *
 *  CoreNum       - Specify the master core which does common initialization
 *                  and de-initialization
 *
 *  PktMTU        - Specify the maximal physical packet size
 */
typedef struct _EMAC_Common_Config {
    Uint8       UseMdio;
    /**< MDIO Configuation select. User has to pass one (1) if MDIO 
         Configuration  is needed, if not should pass zero (0)              */
    Uint32      ModeFlags;
    /**< Configuation Mode Flags                                            */
    Uint32      MdioModeFlags;
    /**< CSL_MDIO Mode Flags (see CSL_MDIO.H)                               */
    Uint32      MdioPhyAddr;
    /**< PHY address (0-31) to be monitored by MDIO, specified by user
         when MDIO_MODEFLG_SPECPHYADDR is set in MdioModeFlags              */
    Uint8       CoreNum;
    /**< This member is for core selction to does the EMAC configuration
          i.e user can select the specific core to configure EMAC one time  */
    Uint32      PktMTU;
    /**< Max physical packet size                                           */
} EMAC_Common_Config;


/******************************************************************************
 * EMAC Driver Version Definitions
 ******************************************************************************/
//#define EMAC_VERSION_STR         " EMAC Driver Revision: 01.00.03.00"


//#define EMAC_CHIP_STR            "SOC_K2G"

/**********************************************************************
 *********************** Common Local Definitions *********************
 **********************************************************************/
/* Initial RX queue number */
#define         EMAC_RX_QUEUE_NUM_INIT           120 /* K2G */

/**
 * @brief   EMAC MCB field functions
 */
#define EMAC_CORE_NUM                       emac_mcb.core_num

#define EMAC_MASTER_CORE(port_num)          emac_mcb.port_cb[port_num].master_core_flag
#define EMAC_MDIO(port_num)                 emac_mcb.port_cb[port_num].mdio_flag
#define EMAC_NUM_RX_PKTS(port_num)          emac_mcb.port_cb[port_num].num_of_rx_pkt_desc
#define EMAC_NUM_TX_PKTS(port_num)          emac_mcb.port_cb[port_num].num_of_tx_pkt_desc
#define EMAC_NUM_TXRX_PKTS(port_num)        emac_mcb.port_cb[port_num].num_of_rxtx_pkt_desc
#define EMAC_PKT_SIZE(port_num)             emac_mcb.port_cb[port_num].max_pkt_size
#define EMAC_MACADDR_CFG(port_num)          emac_mcb.port_cb[port_num].macaddr_cfg.addr
#define EMAC_PKT_DESC(port_num)             emac_mcb.port_cb[port_num].pkt_desc

#define EMAC_RX_QUEUE(port_num)             emac_mcb.port_cb[port_num].rxQueue
#define EMAC_TX_QUEUE(port_num)             emac_mcb.port_cb[port_num].txQueue



#define EMAC_CSL_ERROR(port_num)            emac_mcb.port_cb[port_num].csl_error
#define EMAC_MEM_ERROR(port_num)            emac_mcb.port_cb[port_num].memory_error
#define EMAC_PORT_ERROR(port_num)           emac_mcb.port_cb[port_num].port_error
#define EMAC_FATAL_ERROR(port_num)          emac_mcb.port_cb[port_num].fatal_error

#define EMAC_RX_PKT(port_num, pkt)          emac_mcb.port_cb[port_num].rx_pkt_cb(port_num, pkt)
#define EMAC_ALLOC_PKT(port_num, size)      emac_mcb.port_cb[port_num].alloc_pkt_cb(port_num, size)
#define EMAC_FREE_PKT(port_num, pkt)        emac_mcb.port_cb[port_num].free_pkt_cb(port_num, pkt)



#define EMAC_COMM_PCB(port_num)             emac_mcb.comm_pcb[port_num]


#define EMAC_GLOBAL_FREE_QUEUE     emac_mcb.gGlobalFreeQHnd

#define EMAC_CPDMA_GLOBAL_HND    emac_mcb.gCppiHandle

#define EMAC_CPDMA_TX_CHAN_HND(chan_num) emac_mcb.gCpdmaTxChanHnd[chan_num]
#define EMAC_CPDMA_RX_CHAN_HND(chan_num) emac_mcb.gCpdmaRxChanHnd[chan_num]
#define EMAC_GLOBAL_CPPI_FLOW_HND emac_mcb.gRxFlowHnd


#define EMAC_GLOBAL_QMSS_MEMORY_REGION emac_mcb.memRegion
#define EMAC_GLOBAL_TX_QUEUE_HND(chan_num) emac_mcb.gPaTxQHnd[chan_num]

#define EMAC_GLOBAL_TX_FREE_QUEUE_HND emac_mcb.gTxFreeQHnd

#define EMAC_GLOBAL_TX_RETURN_QUEUE_HND  emac_mcb.gTxReturnQHnd

#define EMAC_GLOBAL_RX_FREE_QUEUE_HND emac_mcb.gRxFreeQHnd

#define EMAC_GLOBAL_RX_QUEUE_HND emac_mcb.gRxQHnd

#define EMAC_GLOBAL_DIV_QUEUE_HND emac_mcb.gDivQHnd


#define EMAC_GLOBAL_RX_SEM_HANDLE(port_num) emac_mcb.port_cb[port_num].rxSemaphoreHandle
#define EMAC_GLOBAL_RX_HWI_HANDLE(port_num) emac_mcb.port_cb[port_num].hwi


/**********************************************************************
 ****************** EMAC Local Data structure ********************
 **********************************************************************/


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
   /**< Total number of MAC addresses configured for this channel, should always be 1 for K2 devices*/

} EMAC_CHAN_CFG_T;

/**
 * @brief
 *  Core specific EMAC port control block
 *
 * @details
 *  Maintains the EMAC port control information of a core
 */
typedef struct EMAC_PORT_CB_V1_tag
{
    Bool                            master_core_flag;
    /**< Ture: master core configuration */
    Bool                mdio_flag;
    /**< True: configure MDIO                                               */
    void*                   hwi;                /* Hwi object */
    Uint32                          num_of_rx_pkt_desc;
    /**< Total number of packet descriptors initialized in the RX queues    */
    Uint32                          num_of_tx_pkt_desc;
    /**< Total number of packet descriptors initialized in the TX queues    */
    Uint32                          num_of_rxtx_pkt_desc;
    /**< Total number of packet descriptors initialized in both TX and RX queues    */
    Uint32                          max_pkt_size;
    /**< MAC address for the port     */
    EMAC_MAC_ADDR_T               macaddr_cfg;
    /**<  MAC address configuration */
    Bool                            loop_back;
    /**< True: packets loop back                                            */
    /**< RX packet call back function */
    EMAC_RX_PKT_CALLBACK_FN_T*      rx_pkt_cb;

    /**< Allocate packet call back function */
    EMAC_ALLOC_PKT_CALLBACK_FN_T*   alloc_pkt_cb;
    /**< Free packet call back function */
    EMAC_FREE_PKT_CALLBACK_FN_T*    free_pkt_cb;
    
    /*! Rx Semaphore Handle for the emac instance.Required for receiving packets */
   void*                      rxSemaphoreHandle;
    /*! emac open == 1, emac closed == 0  */
   int32_t                 emacState;
} EMAC_PORT_CB_V1_T;


/*
    have 1 memRegion, have 1 gGlobalFreeQHnd, gTxFreeQHnd and gRxFreeeQHnd, gTxReturnQHnd is per port,
    gCpdmaTxChanHndand gCpdmaRxChanHnd  is only 1, 
*/
typedef struct EMAC_MCB_V1_T {

   Qmss_MemRegion              memRegion;                                /* QMSS memory region */
    Qmss_QueueHnd               gGlobalFreeQHnd;                        /*Global free queue handle with pre-initialized descriptors done by application, 
                                                                                               emac-lld will be passed this to then 
                                                                                               populate gTxFreeQHnd and gRxFreeQHnd*/
    Qmss_QueueHnd               gTxFreeQHnd;                               /* Tx Free Queue handle, this will get initally populated with descriptors from gGlobalFreeQHnd
                                                                                                during emac_setup_tx_subsysem inside of emac_open */
    Qmss_QueueHnd               gTxReturnQHnd;                              /* This queue will be used to hold Tx completed decriptors that can be filled
                                                                                                     later with data buffers for transmission onto wire.*/
    Qmss_QueueHnd               gRxFreeQHnd;                             /* Rx Free Queue handle, this will get initally populated with descriptors from gGlobalFreeQHnd 
                                                                                                during emac_setup_rx_subsysem inside of emac_open */
    Qmss_QueueHnd               gRxQHnd;                                    /* Rx queue to receive all packets from CPSW for K2G */
    Qmss_QueueHnd               gDivQHnd;
    Qmss_QueueHnd               gPaTxQHnd [NSS_NUM_TX_QUEUES]; /* NOt really Queues used by PA, used to send packets to CPSW fo K2G */

    Cppi_Handle                     gCppiHandle;
    Cppi_ChHnd                     gCpdmaTxChanHnd [NSS_NUM_TX_PKTDMA_CHANNELS];
    Cppi_ChHnd                     gCpdmaRxChanHnd [NSS_NUM_RX_PKTDMA_CHANNELS];
    Cppi_FlowHnd                  gRxFlowHnd;
    MDIO_Device     MdioDev;
    EMAC_PORT_CB_V1_T port_cb[EMAC_MAX_NUM_EMAC_PORTS];
    EMAC_HwAttrs_V1            hwAttrs[EMAC_MAX_NUM_EMAC_PORTS];
} EMAC_MCB_V1_T;

/**********************************************************************
 ***************************** EMAC Macros ****************************
 **********************************************************************/
#ifdef EMAC_DEBUG
#define emac_debug_print(args)      printf args  
#else
#define emac_debug_print(args)      /* Do nothing */
#endif


/**********************************************************************
 ****************** EMAC local/internal functions ********************
 **********************************************************************/

int32_t emac_init_cppi (uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T* p_config, EMAC_HwAttrs_V1* p_hwAttrs);
int32_t emac_init_qmss (uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T*                  p_config, EMAC_HwAttrs_V1           *p_hwAttrs);
int32_t emac_setup_rx_subsysem (uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T* p_config, EMAC_HwAttrs_V1 *hwAttrs);
int32_t emac_setup_tx_subsysem (uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T* p_config, EMAC_HwAttrs_V1 *hwAttrs);
int32_t emac_init_cpsw (uint32_t mtu, EMAC_MAC_ADDR_T* pMacAddr, Bool loop_back);
int32_t emac_qmss_qpop(Qmss_QueueHnd handler, Cppi_HostDesc **pHostDescriptor);
void emac_qmss_qpush (Qmss_QueueHnd handler,void *descAddr, uint32_t packetSize, uint32_t descSize, Qmss_Location location);
void emac_qmss_qpush_descsize(Qmss_QueueHnd handler, void *descAddr, uint32_t descSize);
uint32_t emac_convert_coreLocal2GlobalAddr (uint32_t  addr);

uint32_t MDIO_open( int instNum, uint32_t mdioModeFlags, uint32_t phyAddr, Handle hMDIO,uint32_t macSel);
uint32_t MDIO_timerTick( Handle hMDIO );
void MDIO_getStatus( Handle hMDIO, uint32_t *pPhy, uint32_t *pLinkStatus );
Uint32 MDIO_initPHY( Handle hMDIO, volatile Uint32 phyAddr );
int32_t emac_deinit_qmss (uint32_t port_num);
int32_t emac_deinit_cppi (uint32_t port_num);

#ifdef __cplusplus
}
#endif

#endif /* EMAC_V1__H */
