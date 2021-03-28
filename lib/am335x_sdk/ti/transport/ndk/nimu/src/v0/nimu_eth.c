/*
 * Copyright (C) 2008-2010 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *   @file  nimu_eth.c
 *
 *   @brief
 *  Ethernet Packet Driver rewritten using the NIMU Packet
 *  Architecture guidelines.
 *
 */


#include <ti/transport/ndk/nimu/src/v0/nimu_eth.h>
#include <ti/transport/ndk/nimu/example/helloWorld/src/nimu_osal_c6657.h>

#include <ti/csl/csl_chipAux.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/drv/emac/soc/emac_soc_v0.h>

static uint32_t coreNum;

static PDINFO*  pPDI[NIMU_NUM_EMAC_PORTS];          /* Handle to Device Info */

typedef struct {
    uint32_t                        port_num;
    /**<Port number of the EMAC port */
    uint32_t         mode;
    /**<Mode of the EMAC port */
    uint8_t                         mac_address[6];
    /**<MAC address of the EMAC port */
} NIMU_EMAC_EXT_info;
/**
 * @brief
 *   NIMUDeviceTable
 *
 * @details
 *  This is the NIMU Device Table for the Platform.
 *  This should be defined for each platform. Since the current platform
 *  has a single network Interface; this has been defined here. If the
 *  platform supports more than one network interface this should be
 *  defined to have a list of "initialization" functions for each of the
 *  interfaces.
 */

NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[] =
{
/**
  * @brief  EmacInit for 6472 EVM
  */
    EmacInit,
    NULL
};
 
int32_t  nimu_get_emac_info(uint32_t port_num, NIMU_EMAC_EXT_info * emac_info)
{
    uint32_t mac_addr2, mac_addr1;


    emac_info->port_num       = port_num;
    emac_info->mode           = 1;

    CSL_BootCfgGetMacIdentifier(&mac_addr1, &mac_addr2);
    emac_info->mac_address[0] = ((mac_addr2 & 0x0000ff00) >> 8);
    emac_info->mac_address[1] =  (mac_addr2 & 0x000000ff);

    emac_info->mac_address[2] = ((mac_addr1 & 0xff000000) >> 24);
    emac_info->mac_address[3] = ((mac_addr1 & 0x00ff0000) >> 16);
    emac_info->mac_address[4] = ((mac_addr1 & 0x0000ff00) >> 8);
    emac_info->mac_address[5] =  (mac_addr1 & 0x000000ff);

    return 0;

}
/**
 *  @b EmacStart
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
static int
EmacStart
(
    NETIF_DEVICE*     ptr_net_device
)
{
    EMAC_OPEN_CONFIG_INFO_T     open_cfg;
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[NIMU_EMAC_NUM_CHANS_PER_CORE];
    EMAC_MAC_ADDR_T             macaddr[NIMU_EMAC_NUM_CHANS_PER_CORE*NIMU_EMAC_NUM_MACADDRS_PER_CHAN];
    EMAC_CONFIG_INFO_T          emac_cfg;
    uint32_t                      i,j;
    EMAC_HwAttrs_V0             emac_cfg_v0;

    EMAC_socGetInitCfg(NIMU_PORT_NUM_USED, &emac_cfg_v0);
    open_cfg.hwAttrs = &emac_cfg_v0;

    EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Set the emac_open configuration */
    if (coreNum ==0)
    {
        open_cfg.master_core_flag       = TRUE;
        open_cfg.mdio_flag              = TRUE;
    }
    else
    {
        open_cfg.master_core_flag       = FALSE;
        open_cfg.mdio_flag              = FALSE;
    }
    open_cfg.loop_back              = FALSE;
    open_cfg.num_of_tx_pkt_desc     = NIMU_EMAC_INIT_TX_PKTS;
    open_cfg.num_of_rx_pkt_desc     = NIMU_EMAC_INIT_RX_PKTS;
    open_cfg.max_pkt_size           = NIMU_EMAC_PKT_SIZE;
    open_cfg.num_of_chans           = NIMU_EMAC_NUM_CHANS_PER_CORE;
    open_cfg.p_chan_mac_addr        = chan_cfg;
    open_cfg.rx_pkt_cb              = EmacRxPkt;
    open_cfg.alloc_pkt_cb           = EmacAllocPkt;
    open_cfg.free_pkt_cb            = EmacFreePkt;
    //open_cfg.phy_addr               = platform_get_phy_addr(NIMU_PORT_NUM_USED);
    open_cfg.phy_addr               =  0x18;

    for (i=0; i<NIMU_EMAC_NUM_CHANS_PER_CORE; i++)
    {
        chan_cfg[i].chan_num            = coreNum*NIMU_EMAC_NUM_CHANS_PER_CORE+i;
        chan_cfg[i].num_of_mac_addrs    = NIMU_EMAC_NUM_MACADDRS_PER_CHAN;
        chan_cfg[i].p_mac_addr          = &macaddr[i*NIMU_EMAC_NUM_MACADDRS_PER_CHAN];

        for (j=0; j<NIMU_EMAC_NUM_MACADDRS_PER_CHAN; j++)
        {
            mmCopy(chan_cfg[i].p_mac_addr[j].addr, &ptr_pvt_data->pdi.bMacAddr[0], 6);
            chan_cfg[i].p_mac_addr[j].addr[5] += (i*NIMU_EMAC_NUM_MACADDRS_PER_CHAN+j);
        }
    }

    /* Call low-level open function */
    if (emac_open(NIMU_PORT_NUM_USED, &open_cfg) == EMAC_DRV_RESULT_OK)
    {
        ptr_pvt_data->pdi.TxFree = 1;

        /* Copy the MAC Address into the network interface object here. */
        mmCopy(&ptr_net_device->mac_address[0], &ptr_pvt_data->pdi.bMacAddr[0], 6);

        /* Set the 'initial' Receive Filter */
        ptr_pvt_data->pdi.Filter = ETH_PKTFLT_MULTICAST;

        emac_cfg.rx_filter       = ptr_pvt_data->pdi.Filter;
        emac_cfg.mcast_cnt       = 0;
        emac_cfg.p_mcast_list    = NULL;

        emac_config(NIMU_PORT_NUM_USED, &emac_cfg);

        return 0;
    }

    /* Error: EMAC failed to start. */
    return -1;
}


/**
 *  @b EmacStop
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
static int
EmacStop
(
    NETIF_DEVICE*    ptr_net_device
)
{
    EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Call low-level close function */
    emac_close (NIMU_PORT_NUM_USED);

    /* Flush out our pending raw rx queue */
    while( PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rawrx) )
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rawrx) );

    /* Flush out our pending queue */
    while( PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rx) )
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rx) );


    /* EMAC Controller has been stopped. */
    return 0;
}

static EMAC_DRV_ERR_E
EmacSendPkt
(
    EMAC_DATA*      ptr_pvt_data
)
{
    PBM_Handle hPkt;
    EMAC_DRV_ERR_E emac_send_status;
    register uint8_t*     buffer;
    register uint32_t       length;
    EMAC_PKT_DESC_T     pkt_desc;

    /* Checking for any queued packets to be transmitted */

    /* First check the Raw Packet Tx Queue. If there are any
    * pending packets in this queue, always transmit them
    * first over the IP packets.
    */
    hPkt = PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rawtx);

    /* Check if no raw packet to transmit and if any
    * IP packet to transmit. If no raw or IP packets to
    * transmit, set the "Transmitter Free" TxFree
    * flag for this device to 1.
    */
    if( !hPkt && !(hPkt = PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_tx)) )
    {
        return EMAC_DRV_RESULT_SEND_ERR;
    }

    buffer = (Uint8 *)Convert_CoreLocal2GlobalAddr((uint32_t)(PBM_getDataBuffer(hPkt))) + PBM_getDataOffset(hPkt);
    length = PBM_getBufferLen(hPkt);

    /* Clean the cache for external addesses */
    if( ((uint32_t)buffer & EMAC_EXTMEM) || (((uint32_t)buffer & EMAC_MSMCMEM) == EMAC_MSMCMEM) )
       CacheP_wbInv( (void *)buffer, length );

    pkt_desc.AppPrivate  = (uint32_t)hPkt;
    pkt_desc.pPrev       = NULL;
    pkt_desc.pNext       = NULL;
    pkt_desc.pDataBuffer = (Uint8 *)Convert_CoreLocal2GlobalAddr((uint32_t)(PBM_getDataBuffer(hPkt)));
    pkt_desc.BufferLen   = PBM_getBufferLen(hPkt);
    pkt_desc.Flags       = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
    pkt_desc.ValidLen    = PBM_getValidLen(hPkt);
    pkt_desc.DataOffset  = PBM_getDataOffset(hPkt);
    pkt_desc.PktChannel  = coreNum;
    pkt_desc.PktLength   = PBM_getValidLen(hPkt);
    pkt_desc.PktFrags    = 1;

    CacheP_wbInv((void *)&pkt_desc, sizeof(EMAC_PKT_DESC_T));
    emac_send_status = emac_send(NIMU_PORT_NUM_USED, &pkt_desc);
    return emac_send_status;
}

/**
 *  @b EmacPoll
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
static void EmacPoll (NETIF_DEVICE* ptr_net_device, uint32_t timer_tick)
{
    EMAC_LINK_INFO_T linkInfo;
    memset(&linkInfo,0,sizeof(EMAC_LINK_INFO_T));
    emac_poll(NIMU_PORT_NUM_USED, &linkInfo);
}


/**
 *  @b EmacSend
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
static int EmacSend (NETIF_DEVICE* ptr_net_device, PBM_Handle hPkt)
{
    EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Make sure the driver does not transmit packet less than min. as per the
     * Ethernet standards. */
    if( PBM_getValidLen(hPkt) < 60 )
        PBM_setValidLen (hPkt, 60 );

    /* We do not do any packet size checks here. If the packet
     * is too big to fit in the MTU configured on the peripheral,
     * then the driver/CSL layer catches the error.
     */
    /* Enqueue the packet and send it for transmission. */
    if( 1 )
    {
        /* Peek into the packet to check out if any
         * prioritization is needed.
         *
         * All raw ethernet packets are tagged with the EMAC
         * channel number onto which they need to be sent out
         * in the PktPriority field.
         */
        if (((PBM_Pkt *)hPkt)->PktPriority != PRIORITY_UNDEFINED)
        {
            /* Enqueue the packet in the Raw Tx Queue and send it
             * for transmission.
             */
            PBMQ_enq (&ptr_pvt_data->pdi.PBMQ_rawtx, hPkt);

            /* PktPriority contains the EMAC channel number on which
             * the packet needs to be txed.
             */
            ptr_pvt_data->pdi.PhysIdx = (((PBM_Pkt *)hPkt)->PktPriority);
        }
        else
        {
            /* This is just a normal IP packet. Enqueue the packet in the
             * Tx queue and send it for transmission.
             */
            PBMQ_enq (&ptr_pvt_data->pdi.PBMQ_tx, hPkt);

            /* We are assuming here that the IP packets are transmitted
             * on Channel 0 -> Core 0; Channel 1 --> Core 1; Channel 2 --> Core 2.
             * and that the Raw packets can be transmitted on any channel.
             */
                ptr_pvt_data->pdi.PhysIdx = coreNum;
        }

        /* Pass the packet to the controller if the transmitter is free. */
        if(ptr_pvt_data->pdi.TxFree )
        {
           EmacSendPkt(ptr_pvt_data);
        }

        /* Packet has been successfully transmitted. */
        return 0;
    }
}


/**
 *  @b EmacPktService
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
static void EmacPktService (NETIF_DEVICE* ptr_net_device)
{
    EMAC_DATA*  ptr_pvt_data;
    PBM_Handle          hPacket;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Give all queued Raw packets first to the Ether module */
    while (PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rawrx))
    {
        /* Dequeue a packet from the driver's Raw receive queue. */
        hPacket = PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rawrx);

        /* Prepare the packet so that it can be passed up the networking stack.
         * If this 'step' is not done the fields in the packet are not correct
         * and the packet will eventually be dropped.  */
        PBM_setIFRx (hPacket, ptr_net_device);

        /* Pass the packet to the NDK Core stack. */
        NIMUReceivePacket(hPacket);
    }

    /* Give all queued IP packets to the Ether module */
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
    }

    /* Work has been completed; the receive queue is empty... */
    return;
}


/**
 *  @b Emacioctl
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
static int Emacioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size)
{
    EMAC_DATA*  ptr_pvt_data;
    int                 count = 0;
    uint8_t*              mac_address_add_del = (uint8_t *)pBuf;
    uint16_t              index;
    EMAC_CONFIG_INFO_T  emac_cfg;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Process the command. */
    switch (cmd)
    {
        case NIMU_ADD_MULTICAST_ADDRESS:
        {
            /* Validate the arguments. */
            if ((pBuf == NULL) || (size != 6))
                return -NDK_EINVAL;

            /* We need to add an address to the NIMU Network Interface Object's multicast
             * list. Check for duplicate addresses. */
            while (count < ptr_pvt_data->pdi.MCastCnt)
            {
                uint8_t* mac_address_list = (uint8_t *)&ptr_pvt_data->pdi.bMCast[count*6];

                /* Match the MAC Addresses  */
                for (index=0; index<6; index++)
                {
                    if( *(mac_address_add_del+index) != *(mac_address_list+index))
                        break;
                }

                /* Check if there is a hit or not? */
                if (index == 6)
                {
                    /* Duplicate MAC address; the address was already present in the list.
                     * This is not an error we will still return SUCCESS here */
                    return 0;
                }
                else
                {
                    /* No HIT! Goto the next entry in the device multicast list. */
                    count++;
                }
            }

            /* Control comes here implies that the MAC Address needs to be added to the
             * device list. The variable 'count' is pointing to the free location available
             * in which the multicast address can be added. But before we do so check if
             * we dont exceed the upper limit? */
            if (count >= PKT_MAX_MCAST)
                return -NDK_ENOMEM;

            /* Add the multicast address to the end of the list. */
            mmCopy (&ptr_pvt_data->pdi.bMCast[count*6], mac_address_add_del, 6);
            ptr_pvt_data->pdi.MCastCnt++;

            /* Configure the Ethernet controller with the new multicast list. */
            ptr_pvt_data->pdi.Filter = ETH_PKTFLT_MULTICAST;

            emac_cfg.rx_filter       = ptr_pvt_data->pdi.Filter;
            emac_cfg.mcast_cnt       = ptr_pvt_data->pdi.MCastCnt;
            emac_cfg.p_mcast_list    = ptr_pvt_data->pdi.bMCast;
            emac_config(NIMU_PORT_NUM_USED, &emac_cfg);

            break;
        }
        case NIMU_DEL_MULTICAST_ADDRESS:
        {
            /* Validate the arguments. */
            if ((pBuf == NULL) || (size != 6))
                return -NDK_EINVAL;

            /* We need to delete an address from the NIMU Network Interface Object's multicast
             * list. First cycle through and make sure the entry exists. */
            while (count < ptr_pvt_data->pdi.MCastCnt)
            {
                uint8_t* mac_address_list = (uint8_t *)&ptr_pvt_data->pdi.bMCast[count*6];

                /* Match the MAC Addresses  */
                for ( index=0; index<6; index++)
                {
                    if( *(mac_address_add_del+index) != *(mac_address_list+index))
                        break;
                }

                /* Check if there is a hit or not? */
                if (index == 6)
                {
                    /* Found the matching entry. We can now delete this! */
                    break;
                }
                else
                {
                    /* No HIT! Goto the next entry in the device multicast list. */
                    count++;
                }
            }

            /* Did we find a match or not? If not then report the error back */
            if (count == ptr_pvt_data->pdi.MCastCnt)
                return -NDK_EINVAL;

            /* At this time 'count' points to the entry being deleted. We now need to copy all
             * the entries after the 'del' entry back one space in the multicast array. */
            for (index = count; index < (ptr_pvt_data->pdi.MCastCnt - 1); index++)
                mmCopy (&ptr_pvt_data->pdi.bMCast[index*6], &ptr_pvt_data->pdi.bMCast[(index+1)*6], 6);

            /* Decrement the multicast entries. */
            ptr_pvt_data->pdi.MCastCnt--;

            /* Configure the Ethernet controller with the new multicast list. */
            emac_cfg.rx_filter       = ptr_pvt_data->pdi.Filter;
            emac_cfg.mcast_cnt       = ptr_pvt_data->pdi.MCastCnt;
            emac_cfg.p_mcast_list    = ptr_pvt_data->pdi.bMCast;
            emac_config(NIMU_PORT_NUM_USED, &emac_cfg);
            break;
        }
        default:
        {
            /* The command is NOT handled by the driver. */
            return -1;
        }
    }
    return 0;
}


/**
 *  @b EmacInit
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
static int EmacInit (STKEVENT_Handle hEvent)
{
    coreNum = CSL_chipReadDNUM();
    EMACInit_Core(hEvent);

    return 0;
}


static int EMACInit_Core (STKEVENT_Handle hEvent)
{
    NETIF_DEVICE*       ptr_device;
    EMAC_DATA*  ptr_pvt_data;
    char names[6][5]={"eth0","eth1","eth2","eth3","eth4","eth5"};
    NIMU_EMAC_EXT_info emac_info;

    /* Allocate memory for the private data */
    ptr_pvt_data = mmAlloc(sizeof(EMAC_DATA));
    if (ptr_pvt_data == NULL)
    {
        return -1;
    }

    /* Initialize the allocated memory block. */
    mmZeroInit (ptr_pvt_data, sizeof(EMAC_DATA));

    /* Initialize the RX Queue */
    PBMQ_init(&ptr_pvt_data->pdi.PBMQ_rx);
    PBMQ_init(&ptr_pvt_data->pdi.PBMQ_rawrx);

    /* Initialize the private data */
    mmZeroInit(&ptr_pvt_data->pdi, sizeof(PDINFO));

    /* Set physical index */
    ptr_pvt_data->pdi.PhysIdx = coreNum;
    ptr_pvt_data->pdi.hEvent  = hEvent;

    /* MCast List is EMPTY */
    ptr_pvt_data->pdi.MCastCnt    = 0;
    nimu_get_emac_info (0, &emac_info);
    memcpy(ptr_pvt_data->pdi.bMacAddr, emac_info.mac_address, 6);


    /* Init Logical Device */
    /* ptr_pvt_data->pdi.hEther = hEther; */

    /* Allocate memory for the EMAC. */
    ptr_device = mmAlloc(sizeof(NETIF_DEVICE));
    if (ptr_device == NULL)
    {
        return -1;
    }

    /* Initialize the allocated memory block. */
    mmZeroInit (ptr_device, sizeof(NETIF_DEVICE));

    /* Populate the Network Interface Object. */
    strcpy (ptr_device->name, names[coreNum]);
    ptr_device->mtu         = ETH_MAX_PAYLOAD - ETHHDR_SIZE;
    ptr_device->pvt_data    = (void *)ptr_pvt_data;

    /* Populate the Driver Interface Functions. */
    ptr_device->start       = EmacStart;
    ptr_device->stop        = EmacStop;
    ptr_device->poll        = EmacPoll;
    ptr_device->send        = EmacSend;
    ptr_device->pkt_service = EmacPktService;
    ptr_device->ioctl       = Emacioctl;
    ptr_device->add_header  = NIMUAddEthernetHeader;

    /* Register the device with NIMU */
    if (NIMURegister (ptr_device) < 0)
    {
        return -1;
    }

    pPDI[NIMU_PORT_NUM_USED] = &ptr_pvt_data->pdi;

    return 0;

}

/**
 * @brief
 *   NIMU wrapper functions for EMAC LLD
 */

static EMAC_PKT_DESC_T         emac_pkt_desc[NIMU_NUM_EMAC_PORTS];
/**
 *  @b Description
 *  @n
 *      Call back function provided by application to allocate
 *      a packet descriptor.
 *
 *  @retval
 *      pointer to the allocated packet descriptor.
 */
static EMAC_PKT_DESC_T*
EmacAllocPkt
(
    uint32_t      port_num,
    uint32_t      pkt_size
)
{
    PBM_Handle          hPkt;

    if (hPkt = PBM_alloc(pkt_size))
    {
        emac_pkt_desc[port_num].AppPrivate  = (uint32_t)hPkt;
        emac_pkt_desc[port_num].pDataBuffer = (Uint8 *)Convert_CoreLocal2GlobalAddr((uint32_t)(PBM_getDataBuffer(hPkt)));
        emac_pkt_desc[port_num].BufferLen   = PBM_getBufferLen(hPkt);
        emac_pkt_desc[port_num].DataOffset  = 0;
        return &emac_pkt_desc[port_num];
    }
    else
    {
        return NULL;
    }
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
EmacFreePkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_desc
)
{
    (void)port_num;

    /**
     * Note: NDK application only supports one EMAC port access, it needs to be modified
     * to have separate PBM queue per port for multiple EMAC ports access
     */
    PBM_free( (PBM_Handle)p_desc->AppPrivate );
}

/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to report a received packet descriptor.
 *
 *  @retval
 *      None.
 */
static void
EmacRxPkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_desc
)
{
    uint32_t              dataOffset, protocol;
    uint8_t*              pBuffer;

    (void)port_num;

    PBM_setValidLen((PBM_Handle) p_desc->AppPrivate, p_desc->ValidLen);
    PBM_setIFRx((PBM_Handle) p_desc->AppPrivate, pPDI[NIMU_PORT_NUM_USED]->hEther );

    /* Handle raw frames separately, i.e. check the
    * Ethernet Protocol type in this packet and see
    * if its a well known ether type. If so, this is normal
    * IP stream, enqueue this is in usual Rx queue and let the
    * stack know that a packet has arrived for it. However, if
    * the ethernet type in the packet is not a well known one,
    * this could be a custom raw ethernet packet, enqueue it
    * separately in the Raw Rx queue and notiofy stack. The Raw
    * Ethernet packets when being handed over are given
    * preferential treatment and are serviced before the normal
    * IP traffic. Hence the 2 queues.
    */
    dataOffset = PBM_getDataOffset((PBM_Handle) p_desc->AppPrivate);
    pBuffer = (Uint8 *)Convert_CoreLocal2GlobalAddr((uint32_t)(PBM_getDataBuffer((PBM_Handle) p_desc->AppPrivate))) + dataOffset;

    /* Extract the ethernet type from the packet. */
    protocol = ( pBuffer[12] << 8) | pBuffer[13] ;
    protocol = (protocol & 0xFFFFu);

    /* Is it a standard ethernet type? */
    if (protocol != ETHERTYPE_IP && protocol != ETHERTYPE_IPv6 && protocol != ETHERTYPE_VLAN
        && protocol != ETHERTYPE_PPPOECTL && protocol != ETHERTYPE_PPPOEDATA )
    {
        /* This is a raw packet, enqueue in Raw Rx Queue */
        PBMQ_enq( &pPDI[NIMU_PORT_NUM_USED]->PBMQ_rawrx, (PBM_Handle) p_desc->AppPrivate );
    }
    else
    {            /* This is a normal IP packet. Enqueue in Rx Queue */
        PBMQ_enq( &pPDI[NIMU_PORT_NUM_USED]->PBMQ_rx, (PBM_Handle) p_desc->AppPrivate );
    }

    /* Notify NDK stack of pending Rx Ethernet packet */
    STKEVENT_signal( pPDI[NIMU_PORT_NUM_USED]->hEvent, STKEVENT_ETHERNET, 1 );

    /* Clean the cache for external addesses */
    if( ((uint32_t)(PBM_getDataBuffer(p_desc->AppPrivate)) & EMAC_EXTMEM) || (((uint32_t)(PBM_getDataBuffer(p_desc->AppPrivate)) & EMAC_MSMCMEM) == EMAC_MSMCMEM) )
    {
        CacheP_wbInv( (void *)(PBM_getDataBuffer(p_desc->AppPrivate)), PBM_getBufferLen(p_desc->AppPrivate) );
    }
}
