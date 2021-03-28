/**
 *   @file  cpsw_nimu_eth.c
 *   @brief
 *     cpsw nimu implementation for AMxxx SOCs
 */

/* Copyright (C) {2012-2017} Texas Instruments Incorporated - http://www.ti.com/ 
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

#include <ti/transport/ndk/nimu/src/v4/cpsw_nimu_eth.h>
#include <ti/transport/ndk/nimu/src/NIMU_drv_log.h>

#include <ti/osal/SemaphoreP.h>
#include <ti/transport/ndk/nimu/src/nimu_osal.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>


#include <ti/csl/hw_types.h>

#ifdef SOC_AM437x
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/hw/hw_control_am43xx.h>
#include <ti/starterware/include/hw/hw_cpsw_ale.h>
#endif

#ifdef SOC_AM335x
#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/starterware/include/hw/hw_control_am335x.h>
#include <ti/starterware/include/hw/hw_cpsw_ale.h>
#endif


#if defined  (SOC_AM574x) || defined  (SOC_AM572x) ||  defined(SOC_AM571x)
#include <ti/csl/soc.h>
#include <ti/csl/csl_cpswAux.h>
#endif

#if defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x)
#include <ti/csl/soc/am572x/src/cslr_control_core.h>
#include <ti/csl/csl_cpswAux.h>
#endif



#define     NIMU_PKT_MTU_DEFAULT             1518

/* Max Number of EMAC ports */
#define NIMU_NUM_EMAC_PORTS                  ((uint32_t)2U)

/* Number of emac interface instantiated */
static uint32_t numEmacInterfaces = 0U;

/* Array of initialized EMAC packet buffers to handle incoming packets */
static EMAC_PKT_DESC_T rcv_pkt[4] __attribute__ ((aligned (64)));;


NETIF_DEVICE   ptr_device[NIMU_NUM_EMAC_PORTS];

static      NIMU_CpswPdInfo                        *pPDI[NIMU_NUM_EMAC_PORTS]= {0,0};         /* Handle to Device Info for port 2 (eth2)*/


void CpswHwPktTxNext( NIMU_CpswPdInfo *pi );
int32_t CpswHwPktIoctl(NIMU_CpswPdInfo *pi, uint32_t cmd, void* param, uint32_t size);
static EMAC_PKT_DESC_T* nimu_alloc_pkt(uint32_t port_num, uint32_t pkt_size);
static void nimu_free_pkt(uint32_t port_num,EMAC_PKT_DESC_T*    p_pkt_desc);

static void  nimu_rx_pkt_cb (uint32_t port_num, EMAC_PKT_DESC_T*     p_desc);

static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p);


/* The EMAC Initialization Function. */
int32_t CpswEmacInit (STKEVENT_Handle hEvent);

/* Used to check status of NDK shutdown */
int32_t shutdown_complete;


uint32_t CpswHwPktOpen( NIMU_CpswPdInfo *pi );


SemaphoreP_Params semParams;
void                      *rxSemaphoreHandle;


/* Defines the num of ports, set using boardType */

/**
 * @brief
 *   CPSW_EMAC_DATA
 *
 * @details
 *  The structure is used to store the private data for the
 *  EMAC controller.
 */
typedef struct CPSW_EMAC_DATA_s
{
/**
  * @brief   Private Information
  */
    NIMU_CpswPdInfo      pdi;
}CPSW_EMAC_DATA;


extern void Osal_TaskCreate(void* pCbFn);
static void nimu_task_poll_pkt (uint32_t*  arg0, uint32_t* arg1); /* misra warning */
static void nimu_task_poll_pkt (uint32_t*  arg0, uint32_t* arg1)
{
    emac_poll_pkt(0);
}


/**
 *  @b NIMU_start
 *  @n
 *  The function is used to initialize and start the EMAC
 *  controller and device.
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static int_fast32_t NIMU_start (NETIF_DEVICE* ptr_net_device); /* misra warning */
static int_fast32_t NIMU_start (NETIF_DEVICE* ptr_net_device)
{
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[1];
    CPSW_EMAC_DATA*  ptr_pvt_data;
    EMAC_HwAttrs_V4 emac_cfg;
    int32_t retVal = 0;


    /* Get the pointer to the private data */
    ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;

    /* Call low-level open function */
    if (CpswHwPktOpen(&ptr_pvt_data->pdi) == 0U)
    {
        /* Copy the MAC Address into the network interface object here. */
        mmCopy((void*)(&ptr_net_device->mac_address[0]), (void*)(&ptr_pvt_data->pdi.bMacAddr[0]), 6U);

        /* Set the 'initial' Receive Filter */
        ptr_pvt_data->pdi.Filter = ETH_PKTFLT_ALL;

        /* only need to init emac driver for 1st interface */
        if(ptr_pvt_data->pdi.PhysIdx == 0U)
        {
            EMAC_socGetInitCfg(0, &emac_cfg);
            open_cfg.hwAttrs = (void*)&emac_cfg;
            open_cfg.alloc_pkt_cb = &nimu_alloc_pkt;
            open_cfg.free_pkt_cb = &nimu_free_pkt;
            open_cfg.rx_pkt_cb = &nimu_rx_pkt_cb;
            open_cfg.loop_back = 0;
            open_cfg.master_core_flag = 1;
            open_cfg.max_pkt_size = NIMU_PKT_MTU_DEFAULT;
            open_cfg.mdio_flag = 1;
            open_cfg.num_of_chans = 1;
            open_cfg.num_of_rx_pkt_desc = 128U;
            open_cfg.num_of_tx_pkt_desc = 128U;
            open_cfg.phy_addr = 0; /* get this from hwAttrs */
    
            chan_cfg[0].p_mac_addr = (EMAC_MAC_ADDR_T*)&ptr_pvt_data->pdi.bMacAddr[0];
        
            /* Set the channel configuration */
            chan_cfg[0].chan_num = 0;
            chan_cfg[0].num_of_mac_addrs = 1;
        
            open_cfg.p_chan_mac_addr = &chan_cfg[0];
            if ((emac_open(0U, &open_cfg)) != EMAC_DRV_RESULT_OK)
            {
                NIMU_drv_log("EMACInit_Core failed\n");
                retVal = -1;
            }
            else
            {
                Osal_TaskCreate((void*)nimu_task_poll_pkt);
                NIMU_drv_log ("EMAC has been started successfully\n");
                retVal = 0;
            }
        }
    }
    else
    {
        /* Error: EMAC failed to start. */
        retVal =  -1;
    }
    return retVal;
}


/**
 *  @b NIMU_stop
 *  @n
 *  The function is used to de-initialize and stop the EMAC
 *  controller and device.
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static int_fast32_t NIMU_stop (NETIF_DEVICE* ptr_net_device); /*misra warning */
static int_fast32_t NIMU_stop (NETIF_DEVICE* ptr_net_device)
{
    CPSW_EMAC_DATA*  ptr_pvt_data;
    EMAC_DRV_ERR_E closeRetVal;
    uint32_t count;
    
    /* Get the pointer to the private data */
    ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;

    closeRetVal = emac_close(0 );
    if( closeRetVal == EMAC_DRV_RESULT_CLOSE_PORT_ERR )
    {
#ifdef DEBUG_STATS
        csl_errors++;
#endif
        NIMU_drv_log1("EMAC Close Returned error %08x\n",i);
    }

   /* Flush out our pending queue */
    count = PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rx);
    while(count)
    {
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rx) );
        count = PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rx);
    }
    shutdown_complete = 1;

    /* EMAC Controller has been stopped. */
    return 0;
}


/**
 *  @b NIMU_Poll
 *  @n
 *  The function is used to poll the EMAC controller to check
 *  if there has been any activity
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *  @param[in]  timer_tick
 *      Flag to poll the driver.
 *
 *  @retval
 *      void
 */
static void NIMU_Poll (NETIF_DEVICE* ptr_net_device, uint32_t timer_tick); /* misra warning */
static void NIMU_Poll (NETIF_DEVICE* ptr_net_device, uint32_t timer_tick)
{
    EMAC_LINK_INFO_T info;
    CPSW_EMAC_DATA*  ptr_pvt_data;
    uint32_t port_num;

      /* Get the pointer to the private data  to poll specified port */
        ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;
      
    /* If running in SWITCH mode, need to call poll routine for both ports to see if any link is up */
    if (numEmacInterfaces == 1U)
   {
       
        if(timer_tick)
        {   
            memset(&info,0, sizeof(EMAC_LINK_INFO_T));
            emac_poll(0U, &info);
            if(info.link_status != EMAC_LINKSTATUS_NOLINK)
            {
                ptr_pvt_data->pdi.TxFree =1;
                CpswHwPktTxNext(&ptr_pvt_data->pdi);
            }
            else
            {
                memset(&info,0, sizeof(EMAC_LINK_INFO_T));
                emac_poll(1U, &info);
                if(info.link_status != EMAC_LINKSTATUS_NOLINK)
                {
                    ptr_pvt_data->pdi.TxFree =1;
                    CpswHwPktTxNext(&ptr_pvt_data->pdi);
                }
            }
        }
    }
    else
    {
        port_num = ptr_pvt_data->pdi.PhysIdx;
        if(timer_tick)
        {
            memset(&info,0, sizeof(EMAC_LINK_INFO_T));
            emac_poll(port_num, &info);
            if(info.link_status != EMAC_LINKSTATUS_NOLINK)
            {
                ptr_pvt_data->pdi.TxFree =1;
                CpswHwPktTxNext(&ptr_pvt_data->pdi);
            }
        }
    }
}

/**
 *  @b NIMU_send
 *  @n
 *  The function is the interface routine invoked by the NDK stack to
 *  pass packets to the driver.
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *  @param[in]  hPkt
 *      Packet to be sent out on wire.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static int_fast32_t NIMU_send (NETIF_DEVICE* ptr_net_device, PBM_Handle hPkt); /* misra warning */
static int_fast32_t NIMU_send (NETIF_DEVICE* ptr_net_device, PBM_Handle hPkt)
{
    CPSW_EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;

    /* Make sure the driver does not transmit packet less than min. as per the
     * Ethernet standards. */
    if( PBM_getValidLen(hPkt) < 60U )
    {
        PBM_setValidLen (hPkt, 60U );
    }
    /* We do not do any packet size checks here. If the packet
     * is too big to fit in the MTU configured on the peripheral,
     * then the driver/CSL layer catches the error.
     */

      if(ptr_pvt_data->pdi.TxFree )
     {
        /* Enqueue the packet and send it for transmission. */
        PBMQ_enq (&ptr_pvt_data->pdi.PBMQ_tx, hPkt);

        /* Pass the packet to the controller if the transmitter is free. */
        CpswHwPktTxNext(&ptr_pvt_data->pdi);
    }

    /* Packet has been successfully transmitted. */
    return 0;
}


/**
 *  @b NIMU_pktService
 *  @n
 *  The function is called by the NDK core stack to receive any packets
 *  from the driver.
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *
 *  @retval
 *      void
 */
static void NIMU_pktService (NETIF_DEVICE* ptr_net_device); /* misra warning */
static void NIMU_pktService (NETIF_DEVICE* ptr_net_device)
{
    CPSW_EMAC_DATA*  ptr_pvt_data;
    PBM_Handle          hPacket;

    /* Get the pointer to the private data */
    ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;

    /* Give all queued packets to the Ether module */
    while (PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rx))
    {

        /* Dequeue a packet from the driver receive queue. */
        hPacket = PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rx);

        /* Prepare the packet so that it can be passed up the networking stack.
         * If this 'step' is not done the fields in the packet are not correct
         * and the packet will eventually be dropped.  */
        PBM_setIFRx (hPacket, ptr_net_device);

        /* Pass the packet to the NDK Core stack. */
        NIMUReceivePacket(hPacket);
#ifdef DEBUG_STATS
        cpsw_raweth_stat.nimuRxCnt++;
#endif
    }

    /* Work has been completed; the receive queue is empty... */
    return;
}


/**
 *  @b NIMU_ioctl 
 *  @n
 *  The function is called by the NDK core stack to configure the
 *  driver
 *
 *  @param[in]  ptr_net_device
 *      NETIF_DEVICE structure pointer.
 *  @param[in]  cmd
 *      Ioctl command.
 *  @param[in]  pBuf
 *      Mac address to be added or deleted.
 *  @param[in]  size
 *      Size of Mac Address.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static int_fast32_t NIMU_ioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size);/* misra warning */
static int_fast32_t NIMU_ioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size)
{
    CPSW_EMAC_DATA*  ptr_pvt_data;
    int32_t retVal;
    /* Get the pointer to the private data */
    ptr_pvt_data = (CPSW_EMAC_DATA *)ptr_net_device->pvt_data;

    /* call the switch driver's Ioctl handler to take care of this. */
    retVal = CpswHwPktIoctl(&ptr_pvt_data->pdi, cmd, pBuf, size);
    return retVal;
}

/**
 *  @b CpswEmacInit
 *  @n
 *  The function is used to initialize and register the EMAC
 *  with the Network Interface Management Unit (NIMU)
 *
 *  @param[in]  hEvent
 *      Stack Event Handle.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
int32_t CpswEmacInit(STKEVENT_Handle hEvent)
{
    int32_t retVal = 0;
    CPSW_EMAC_DATA*      ptr_pvt_data;
    EMAC_HwAttrs_V4 emac_cfg;
    /* memset netif device struct */
    mmZeroInit((void*)(&ptr_device[numEmacInterfaces]), sizeof(NETIF_DEVICE));

    /* Allocate memory for the private data */
    ptr_pvt_data = mmAlloc(sizeof(CPSW_EMAC_DATA));
    if (ptr_pvt_data == NULL)
    {
        NIMU_drv_log ("Error: Unable to allocate private memory data\n");
        retVal= -1;
    }
    else
    {
        /* Initialize the allocated memory block for private data. */
        mmZeroInit (ptr_pvt_data, sizeof(CPSW_EMAC_DATA));

        /* Initialize the RX Queue */
        PBMQ_init(&ptr_pvt_data->pdi.PBMQ_rx);

       /* Retrieve MAC address */
        CpswEmacAddrGet((numEmacInterfaces+1U), (NIMU_CpswMacAddr*)(&( ptr_pvt_data->pdi.bMacAddr[0])));
        /* Set physical index */
        ptr_pvt_data->pdi.PhysIdx = numEmacInterfaces;
        ptr_pvt_data->pdi.hEvent  = hEvent;
        /* MCast List is EMPTY */
        ptr_pvt_data->pdi.MCastCnt    = 0;

        /* Populate the Network Interface Object. */
        if (numEmacInterfaces == 0U)
        {
            strcpy (ptr_device[numEmacInterfaces].name, "eth0");
        }
        else
        {
            strcpy (ptr_device[numEmacInterfaces].name, "eth1");
        }
        ptr_device[numEmacInterfaces].mtu         = ETH_MAX_PAYLOAD - ETHHDR_SIZE;
        ptr_device[numEmacInterfaces].pvt_data    = (void *)ptr_pvt_data;
    
        /* Populate the Driver Interface Functions. */
        ptr_device[numEmacInterfaces].start       = &NIMU_start;
        ptr_device[numEmacInterfaces].stop        = &NIMU_stop;
        ptr_device[numEmacInterfaces].poll        = &NIMU_Poll;
        ptr_device[numEmacInterfaces].send        = &NIMU_send;
        ptr_device[numEmacInterfaces].pkt_service = &NIMU_pktService;
        ptr_device[numEmacInterfaces].ioctl       = &NIMU_ioctl;
        ptr_device[numEmacInterfaces].add_header  = &NIMUAddEthernetHeader;
        ptr_device[numEmacInterfaces].flags       = NIMU_DEVICE_NO_FREE;
        /* Register the device with NIMU */
        if (NIMURegister (&ptr_device[numEmacInterfaces]) < 0)
        {
            NIMU_drv_log ("Error: Unable to register the EMAC\n");
            retVal = -1;
        }
        else
        {
            numEmacInterfaces++;
            if (numEmacInterfaces == 2U)
            {
                 /* for dualMacMode, need to enableAleBypass */
                EMAC_socGetInitCfg(0, &emac_cfg);
#if defined (SOC_AM335x) || defined(SOC_AM437x)
               
                HW_WR_FIELD32((emac_cfg.ale_base +  CPSW_ALE_CTRL),
                CPSW_ALE_CTRL_BYPASS, CPSW_ALE_CTRL_BYPASS_ENABLE);
#else
    CSL_CPSW_enableAle((CSL_cpswHandle)emac_cfg.ss_base);
#endif
                NIMU_drv_log ("Registeration of the EMAC Successful\n");
                retVal = 0;
            }
        }
    }
     return retVal;
}



/**
 *  @b RxPacket
 *  @n
 *      Function called by CSL to pass the received packet to the driver.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  cslPkt
 *      CPSW_Pkt type packet passed by CSL.
 *
 *  @retval
 *        EMAC_PKT_DESC_T pointer of a packet with buffer to replenish CSL.
 */
static void  nimu_rx_pkt_cb (uint32_t port_num, EMAC_PKT_DESC_T*     p_desc)
{
    if (numEmacInterfaces == 2U)
    {
        /* Remove the 4 byte header from the packet. Not sure as to why the EMAC
        * is adding an extra 4bytes to the header. This is causing stack to
        * fail checksum validations on IPv6 packets. So, remove the extra 4 bytes
        * tagged by the EMAC.
        */
        if (port_num == 0U)
        {
            PBM_setValidLen((PBM_Handle) p_desc->AppPrivate, (p_desc->ValidLen - 4));
            PBM_setIFRx((PBM_Handle) p_desc->AppPrivate, pPDI[0]->hEther );
    
            PBMQ_enq( &pPDI[0]->PBMQ_rx, (PBM_Handle) p_desc->AppPrivate );
    
            /* Notify NDK stack of pending Rx Ethernet packet */
            STKEVENT_signal( pPDI[0]->hEvent, STKEVENT_ETHERNET, 1U );
        }
        else
        {
            PBM_setValidLen((PBM_Handle) p_desc->AppPrivate, (p_desc->ValidLen - 4));
            PBM_setIFRx((PBM_Handle) p_desc->AppPrivate, pPDI[1]->hEther );
    
            PBMQ_enq( &pPDI[1]->PBMQ_rx, (PBM_Handle) p_desc->AppPrivate );
    
            /* Notify NDK stack of pending Rx Ethernet packet */
            STKEVENT_signal( pPDI[1]->hEvent, STKEVENT_ETHERNET, 1U );
        }
    }
    else
    {
        PBM_setValidLen((PBM_Handle) p_desc->AppPrivate, (p_desc->ValidLen - 4));
        PBM_setIFRx((PBM_Handle) p_desc->AppPrivate, pPDI[0]->hEther );
    
        PBMQ_enq( &pPDI[0]->PBMQ_rx, (PBM_Handle) p_desc->AppPrivate );
    
        /* Notify NDK stack of pending Rx Ethernet packet */
        STKEVENT_signal( pPDI[0]->hEvent, STKEVENT_ETHERNET, 1U );
    }
}

/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to allocate a packet descriptor.
 *
 *  @retval
 *      pointer to the allocated packet descriptor.
 */
static EMAC_PKT_DESC_T*
nimu_alloc_pkt
(
    uint32_t              port_num,
    uint32_t              pkt_size
)
{
    PBM_Handle hPkt;
    EMAC_PKT_DESC_T* pktDesc;

    /* ADD SIZE CHECK */
    hPkt = PBM_alloc(pkt_size + 4U + NIMU_PKT_PREPAD);
    if (hPkt != NULL)
    {
        PBM_setDataOffset(hPkt,NIMU_PKT_PREPAD);

        rcv_pkt[port_num].AppPrivate   = (uint32_t)hPkt;
        rcv_pkt[port_num].pDataBuffer  = PBM_getDataBuffer(hPkt);
        rcv_pkt[port_num].BufferLen    = PBM_getBufferLen(hPkt);
        rcv_pkt[port_num].DataOffset = PBM_getDataOffset(hPkt);
        rcv_pkt[port_num].pPrev = NULL;
        rcv_pkt[port_num].pNext = NULL;
        pktDesc = &rcv_pkt[port_num];
    }
    else
    {
        pktDesc = NULL;
    }
    return pktDesc;
}

/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to free a packet descriptor.
 *
 *  @retval
 *      None.
 */
static void
nimu_free_pkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    (void)port_num;
    PBM_free((PBM_Handle)(p_pkt_desc->AppPrivate));
}


/**
 *  @b CpswHwPktOpen
 *  @n
 *      Opens and configures EMAC. Configures Interrupts, SGMII,
 *      and send and receive queues.
 *
 *  @param[in]  pi
 *      PDINFO structure pointer.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   >0
 */
uint32_t CpswHwPktOpen( NIMU_CpswPdInfo *pi )
{

    pPDI[pi->PhysIdx] = pi;

    /* Init internal bookkeeping fields */
    pi->OldMCastCnt = 0U;

    /* Wait for link to come up */
    pi->TxFree = 0U;


    return 0U;
}




/**
 *  @b CpswHwPktTxNext
 *  @n
 *      Routine to send out a packet.
 *
 *  @param[in]  pi
 *      PDINFO structure pointer.
 *
 *  @retval
 *      void
 */
void CpswHwPktTxNext( NIMU_CpswPdInfo *pi )
{
    PBM_Handle          hPkt;
    EMAC_PKT_DESC_T     csl_send_pkt;
    EMAC_DRV_ERR_E sendResult;
    uint32_t portFlag = 0U;

    /* Checking for any queued packets to be transmitted */
    hPkt = PBMQ_deq(&pi->PBMQ_tx);
    if (hPkt == NULL)
    {
        pi->TxFree = 1;
    }
    else
    {
        csl_send_pkt.AppPrivate     = (uint32_t)hPkt;
        csl_send_pkt.pDataBuffer    = PBM_getDataBuffer(hPkt);
        csl_send_pkt.BufferLen      = PBM_getBufferLen(hPkt);
        csl_send_pkt.ValidLen       = PBM_getValidLen(hPkt);
        csl_send_pkt.DataOffset     = PBM_getDataOffset(hPkt);
        csl_send_pkt.pNext = NULL;
        csl_send_pkt.pPrev = NULL;


        csl_send_pkt.Flags          = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;

        /* for dual emac mode, need to update the flags to direct packet out specified port */
        if(numEmacInterfaces == 2U)
        {
            portFlag = (pi->PhysIdx + 1U) << EMAC_PKT_FLAG_TO_PORT_SHIFT;
            
            csl_send_pkt.Flags  |= portFlag;
        }
            /* We only use one Tx DMA channel  now. If QOS/Priority has to be
             * supported, identify the channel number based on vlan/priority tag or
             * any other field from the header fields of the ethernet frame.
             */
        csl_send_pkt.PktChannel     = 0; 
        csl_send_pkt.PktLength      = PBM_getValidLen(hPkt);
        csl_send_pkt.PktFrags       = 1;
    
    
            sendResult = emac_send(0, &csl_send_pkt);
    
            if(sendResult)
            {
            
                NIMU_drv_log1("CPSW_sendPacket() returned error %08x\n",i);
    
                /* Free the packet as the packet did not go on the wire*/
                PBM_free( (PBM_Handle)csl_send_pkt.AppPrivate );
            }
    }
}


int32_t CpswHwPktIoctl(NIMU_CpswPdInfo *pi, uint32_t cmd, void* param, uint32_t size)
{
    return 0;
}



/**
 * \brief   This function returns the MAC address for the EVM
 *
 * \param   addrIdx    the MAC address index.
 * \param   macAddr    the Pointer where the MAC address shall be stored
 *     'addrIdx' can be either 1 or 2
 *
 * \return  None.
 */
#ifdef SOC_AM437x
static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p); /* misra warning */
static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p)
{
    int32_t retVal = 0;
    switch(addrIdx)
    {
        case 1U:
            p->macAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            p->macAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            p->macAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_23_16);
            p->macAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_31_24);
            p->macAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_39_32);
            p->macAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_47_40);
            break;

        case 2U:
            p->macAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID1_LO_MACADDR_7_0);
            p->macAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID1_LO_MACADDR_15_8);
            p->macAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID1_HI_MACADDR_23_16);
            p->macAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_31_24);
            p->macAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_39_32);
            p->macAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_47_40);
            break;

        default:
            retVal =  -1;
            break;
    }
    return retVal;
}
#endif

#ifdef SOC_AM335x
static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p); /* misra warning */
static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p)
{
    uint32_t slavePortNum = addrIdx - 1U;
    int32_t retVal = 0;

    switch(addrIdx)
    {
        case 1U:
        p->macAddr[5U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum))
                           & CONTROL_MAC_ID0_LO_MACADDR_7_0) >> CONTROL_MAC_ID0_LO_MACADDR_7_0_SHIFT;
        p->macAddr[4U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum)))
                          & CONTROL_MAC_ID0_LO_MACADDR_15_8;
        p->macAddr[3U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_23_16) >> CONTROL_MAC_ID0_HI_MACADDR_23_16_SHIFT;
        p->macAddr[2U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_31_24) >> CONTROL_MAC_ID0_HI_MACADDR_31_24_SHIFT;
        p->macAddr[1U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_39_32) >> CONTROL_MAC_ID0_HI_MACADDR_39_32_SHIFT;
        p->macAddr[0U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum)))
                          & CONTROL_MAC_ID0_HI_MACADDR_47_40;
            break;

        case 2U:
        p->macAddr[5U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum))
                           & CONTROL_MAC_ID0_LO_MACADDR_7_0) >> CONTROL_MAC_ID0_LO_MACADDR_7_0_SHIFT;
        p->macAddr[4U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum)))
                          & CONTROL_MAC_ID0_LO_MACADDR_15_8;
        p->macAddr[3U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_23_16) >> CONTROL_MAC_ID0_HI_MACADDR_23_16_SHIFT;
        p->macAddr[2U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_31_24) >> CONTROL_MAC_ID0_HI_MACADDR_31_24_SHIFT;
        p->macAddr[1U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                           & CONTROL_MAC_ID0_HI_MACADDR_39_32) >> CONTROL_MAC_ID0_HI_MACADDR_39_32_SHIFT;
        p->macAddr[0U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum)))
                          & CONTROL_MAC_ID0_HI_MACADDR_47_40;
            break;

        default:
            retVal =  -1;
            break;
    }
    return retVal;
}
#endif


#if defined  (SOC_AM574x) || defined  (SOC_AM572x) ||  defined(SOC_AM571x) || defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x)

static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p); /* misra warning */
static int32_t CpswEmacAddrGet(uint32_t addrIdx, NIMU_CpswMacAddr *p)
{
    int32_t retVal = 0;

    uint32_t tempVal;
    CSL_control_coreRegs * tempAddr;
    tempAddr =   (CSL_control_coreRegs*)SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE;

    switch(addrIdx)
    {
        case 1U:
            tempVal = tempAddr->MAC_ID_SW_1;
            p->macAddr[0U] = (uint8_t)((tempVal >> 16U) & 0xFFU);
            p->macAddr[1U] = (uint8_t)((tempVal >> 8U) & 0xFFU);
            p->macAddr[2U] = (uint8_t)(tempVal & 0xFFU);

            tempVal = tempAddr->MAC_ID_SW_0;
            p->macAddr[3U] = (uint8_t)((tempVal >> 16U) & 0xFFU);
            p->macAddr[4U] = (uint8_t)((tempVal >> 8U) & 0xFFU);
            p->macAddr[5U] = (uint8_t)((tempVal) & 0xFFU);
            break;

        case 2U:

            tempVal = tempAddr->MAC_ID_SW_3;
            p->macAddr[0U] = (uint8_t)((tempVal >> 16U) & 0xFFU);
            p->macAddr[1U] = (uint8_t)((tempVal >> 8U) & 0xFFU);
            p->macAddr[2U] = (uint8_t)(tempVal & 0xFFU);

            tempVal = tempAddr->MAC_ID_SW_2;
            p->macAddr[3U] = (uint8_t)((tempVal >> 16U) & 0xFFU);
            p->macAddr[4U] = (uint8_t)((tempVal >> 8U) & 0xFFU);
            p->macAddr[5U] = (uint8_t)((tempVal) & 0xFFU);
            break;
        default:
            retVal = -1;
            break;
    }
    return retVal;
}
#endif
