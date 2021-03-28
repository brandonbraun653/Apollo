/*
 * nimu_eth.c
 *
 * Copyright (C) 2011 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  Note: The NDK nimu driver interface is built based on the examples from the
 *  PDK. Please refer to PDK examples
 *  (<pdk_install_dir>\packages\ti\drv\pa\example\emacExample) directory to get
 *  the knowledge on the QMSS, CPPI, PA LLD configurations/programs.
 *
 */

#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_semAux.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/csl_cache.h>
//#include <ti/csl/csl_device_interrupt.h>
#ifdef _TMS320C6X
#include <ti/csl/csl_cacheAux.h>  /* this is for C66x only */
#include <ti/csl/csl_chipAux.h>
#endif
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

#include <ti/drv/qmss/qmss_drv.h>

#include <ti/transport/ndk/nimu/src/NIMU_drv_log.h>
#include <ti/transport/ndk/nimu/src/nimu_osal.h>
#include <ti/transport/ndk/nimu/src/v5/nimu_eth.h>
#include <ti/transport/ndk/nimu/src/v5/nimu_internal.h>
#include <ti/csl/csl_cpsgmiiAux.h>
#include <ti/csl/cslr_cpsgmii.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_xmcAux.h>
#include <ti/csl/cslr_xmc.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v1.h>

/* The following code and define is used for code timing measurements of the Tx and Rx routines */
#ifdef TIMING
#include <ti/csl/csl_tsc.h>
#define MAX_TIMING_PACKETS    1000
#endif

//#include <ti/sysbios/knl/Task.h>

#define NIMU_EMAC_MAX_PKT_SIZE 1536


#define MAX_CORES    1

uint32_t    coreKey [MAX_CORES];

volatile uint32_t linkUp = 0;


extern int32_t NIMU_stopCppi(NIMU_CPPI_CFG_TYPE       cfg_type);
extern int32_t NIMU_stopQmss(void);







NETIF_DEVICE ptr_device[1];


static uint32_t nimuUtilReadTime32(void)
{
    uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}

/****************************************************************************
 * FUNCTION PURPOSE: Delay function
 ****************************************************************************
 * DESCRIPTION: The function will create NWAL instance which is prerequiite
 *              for any call to NWAL
 ****************************************************************************/
void CycleDelay (int32_t iCount)
{
  if (iCount <= 0)
    return;

  /* If there is need for ARM-RTOS, adjust #ifdef to use the PMU
   * via the __asm__ in nwalUtilReadTime32 and use same code as
   * c66 */
//#ifdef __ARMv7
#if 1
  {
    uint32_t start = nimuUtilReadTime32();
    uint32_t count = (uint32_t)iCount;

    while ((nimuUtilReadTime32() - start) < count);
  }
#else
  {
    uint32_t sat;
    /* This code is for user-mode where PMU is inaccessible */
    for (sat=0; sat<(uint32_t)iCount; sat++);
  }
#endif
}

void nimu_task_poll_link(unsigned int* arg0, unsigned int* arg1)
{

    EMAC_LINK_INFO_T link_info;
    CSL_CPSW_ALE_PORTCONTROL    alePortCtrl;
    memset(&alePortCtrl, 0, sizeof(CSL_CPSW_ALE_PORTCONTROL));
 


    while(1)
    {
        memset(&link_info, 0, sizeof(EMAC_LINK_INFO_T));
        emac_poll(0, &link_info);
        Osal_TaskSleep(1000);
       
       if(link_info.link_status_change && (link_info.link_status !=EMAC_LINKSTATUS_NOLINK))
       {
            NIMU_drv_log2("LINK: nimu_task_poll_link: link status change: %d, link status: %d\n",(int) link_info.link_status_change,(int) link_info.link_status);
            alePortCtrl.portState = ALE_PORTSTATE_FORWARD;
            CSL_CPSW_setAlePortControlReg(1, &alePortCtrl);
            linkUp = 1;
       }
       if(link_info.link_status_change && (link_info.link_status == EMAC_LINKSTATUS_NOLINK))
       {
           NIMU_drv_log2("NO_LINK: nimu_task_poll_link: link status change: %d, link status: %d\n",(int) link_info.link_status_change, (int) link_info.link_status);
           alePortCtrl.portState = ALE_PORTSTATE_DISABLED;
           CSL_CPSW_setAlePortControlReg(1, &alePortCtrl);
           linkUp = 0;
       }
    }
}


 void nimu_task_poll_pkt (unsigned int*  arg0, unsigned int* arg1)
{
    emac_poll_pkt(0);
}
int32_t  NIMU_getEmacInfo(uint32_t port_num, NIMU_EMAC_EXT_info * emac_info)
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
 * @brief
 *   NIMUDeviceTable
 *
 * @details
 *  This is the NIMU Device Table for the EVM.
 *  This should be defined for each platform. Since the current platform
 *  has a single network Interface; this has been defined here. If the
 *  EVM supports more than one network interface this should be
 *  defined to have a list of "initialization" functions for each of the
 *  interfaces.
 */

NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[] =
{
/**
  * @brief  EmacInit for the SOC
  */
    EmacInit,
    NULL
};

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
static int EmacStart
(
    NETIF_DEVICE*     ptr_net_device
)
{

    EMAC_DATA*      ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Copy the MAC Address into the network interface object here. */
    mmCopy(&ptr_net_device->mac_address[0], &ptr_pvt_data->pdi.bMacAddr[0], 6);

    /* Set the 'initial' Receive Filter */
    ptr_pvt_data->pdi.Filter = ETH_PKTFLT_MULTICAST;

    ptr_pvt_data->pdi.TxFree = 1;

    Osal_TaskCreate((void*)nimu_task_poll_pkt);
    Osal_TaskCreate((void*)nimu_task_poll_link);

    return 0;
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

#if 0
    count = Qmss_getQueueEntryCount(gRxQHnd);

    /* Free the packet data buffer associated with the Rx Descriptor */
    for (i=0; i < count; i++) {
        /* Need to free up the PBM handle */
        /* free the PBM packet */

        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (gRxQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) != NULL)
        {
            return -1;
        }

        /* Get the Address and Length for Free */
        Cppi_getData(Cppi_DescType_HOST, pCppiDesc, &bufaddr, &bufLen);
        Osal_nimuFree ((Ptr)*bufaddr, bufLen);
    }

    count = Qmss_getQueueEntryCount(gRxFreeQHnd);
    /* Free the packet data buffer associated with the Rx Descriptor */
    for (i=0; i < count; i++) {
        /* Need to free up the PBM handle */
        /* free the PBM packet */

        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (gRxFreeQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) != NULL)
        {
            return -1;
        }

        /* Get the Address and Length for Free */
        Cppi_getData(Cppi_DescType_HOST, pCppiDesc, &bufaddr, &bufLen);
        Osal_nimuFree ((Ptr)*bufaddr, bufLen);
    }


    /* tear down queues and dmas */
    NIMU_stopQmss();
    Qmss_queueClose (gTxFreeQHnd);
    Qmss_queueClose (gRxFreeQHnd);
    Qmss_queueClose (gRxQHnd);
    Qmss_queueClose (gTxReturnQHnd);

    //for (i = 0; i < NUM_PA_TX_QUEUES; i++)
    for (i = 0; i < NSS_NUM_TX_QUEUES; i++)

    
     Qmss_queueClose (gPaTxQHnd[i]);

    NIMU_stopCppi(CPPI_CFG_PASS);
#endif
    /* Flush out our pending raw rx queue */
    while( PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rawrx) )
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rawrx) );

    /* Flush out our pending queue */
    while( PBMQ_count(&ptr_pvt_data->pdi.PBMQ_rx) )
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQ_rx) );


    /* EMAC Controller has been stopped. */
    return 0;
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
    return;
}

/*
 * Routine to debug transmit descriptors
 */
#define DEBUG_TX_DESC 0
#if DEBUG_TX_DESC
#ifdef _TMS320C6X
#pragma DATA_SECTION(TxDescArray, ".DbgSection");
#pragma DATA_SECTION(DescIndexArray, ".DbgSection");
#endif

Cppi_HostDesc   TxDescArray[NUM_TX_DESC];
int             TxDescArrayIndex = 0;
int             gtotal_pkts_freed = 0;
int32_t DescIndexArray[NIMU_NUM_TX_DESC];
int32_t gDescTest = 0;


void printHostDesc (Cppi_HostDesc*      pHostDesc)
{
   NIMU_drv_log1 (" pHostDesc->buffLen       =%ld \n"      ,    pHostDesc->buffLen       );
   NIMU_drv_log1(" pHostDesc->buffPtr       =%ld \n"      ,    pHostDesc->buffPtr       );
   NIMU_drv_log1 (" pHostDesc->descInfo      =%ld \n"      ,    pHostDesc->descInfo    );
   NIMU_drv_log1 (" pHostDesc->nextBDPtr     =%ld \n"      ,    pHostDesc->nextBDPtr   );
   NIMU_drv_log1 (" pHostDesc->origBufferLen =%ld \n"      ,    pHostDesc->origBufferLen);
   NIMU_drv_log1 (" pHostDesc->origBuffPtr   =%ld \n"      ,    pHostDesc->origBuffPtr  );
   NIMU_drv_log1 (" pHostDesc->packetInfo    =%ld \n"      ,    pHostDesc->packetInfo   );
   NIMU_drv_log1 (" pHostDesc->psData        =%ld \n"      ,    pHostDesc->psData       );
   NIMU_drv_log1 (" pHostDesc->softwareInfo0 =%ld \n"      ,    pHostDesc->softwareInfo0);
   NIMU_drv_log1 (" pHostDesc->softwareInfo1 =%ld \n"      ,    pHostDesc->softwareInfo1);
   NIMU_drv_log1 (" pHostDesc->softwareInfo2 =%ld \n"      ,    pHostDesc->softwareInfo2);
   NIMU_drv_log1 (" pHostDesc->tagInfo       =%ld \n"      ,    pHostDesc->tagInfo      );
   NIMU_drv_log1 (" pHostDesc->timeStamp     =%ld \n"      ,    pHostDesc->timeStamp    );
}
#endif

#ifdef TIMING
#ifdef _TMS320C6X
#pragma DATA_SECTION(txisr_time, ".TimingSection");
#pragma DATA_SECTION(txisr_time_idx, ".TimingSection");
#pragma DATA_SECTION(txisr_free_count, ".TimingSection");
#endif
uint32_t     txisr_time[MAX_TIMING_PACKETS];
uint32_t         txisr_time_idx = 0;
uint32_t     txisr_free_count[MAX_TIMING_PACKETS];
#endif



/******************************************************************************
 * Function: EMAC RX packet call back function
 ******************************************************************************/
/**
 *  @brief  This function is used to call back the network application when a
 *          packet is received.
 */
void nimu_rx_pkt_cb(Uint32               port_num, EMAC_PKT_DESC_T*     p_desc)
{
    uint32_t protocol, pktLen;
    EMAC_DATA*          ptr_pvt_data;
    PBM_Handle      hPkt;
    uint8_t*        pBuffer;
    NETIF_DEVICE* ptr_net_device;

    ptr_net_device = &ptr_device[port_num];

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;



    hPkt = (PBM_Handle*) p_desc->AppPrivate;

    PBM_setDataOffset((PBM_Handle) hPkt, 0);


    /* removing the FCS length the EMAC switch adds  here */
    pktLen    = (p_desc->BufferLen-4);

    /* Set to minimum packet size */
    if (pktLen < 60)
    {
        pktLen = 64;
    }

    PBM_setValidLen((PBM_Handle) hPkt, pktLen);
    /* Handle raw frames separately, i.e. check the
      * Ethernet Protocol type in this packet and see
      * if its a well known ether type. If so, this is normal
      * IP stream, enqueue this is in usual Rx queue and let the
      * stack know that a packet has arrived for it. However, if
      * the Ethernet type in the packet is not a well known one,
      * this could be a custom raw Ethernet packet, enqueue it
      * separately in the Raw Rx queue and notify stack. The Raw
      * Ethernet packets when being handed over are given
      * preferential treatment and are serviced before the normal
      * IP traffic. Hence the 2 queues.
      */
      //pBuffer =  (uint8_t* )Convert_CoreLocal2GlobalAddr((uint32_t) p_desc->pDataBuffer);
     pBuffer =  (uint8_t*) p_desc->pDataBuffer;

    /* Extract the Ethernet type from the packet. */
    protocol = ( pBuffer[12] << 8) | pBuffer[13] ;
    protocol = (protocol & 0xFFFFu);

    PBM_setIFRx((PBM_Handle) hPkt, (void*) protocol );

    /* Is it a standard ethernet type? */
    if (protocol != ETHERTYPE_IP && protocol != ETHERTYPE_IPv6 && protocol != ETHERTYPE_VLAN
            && protocol != ETHERTYPE_PPPOECTL && protocol != ETHERTYPE_PPPOEDATA )
    {
        /* This is a raw packet, enqueue in Raw Rx Queue */
        PBMQ_enq( &ptr_pvt_data->pdi.PBMQ_rawrx, (PBM_Handle) hPkt);
    }
    else
    {   /* This is a normal IP packet. Enqueue in Rx Queue */
        PBMQ_enq( &ptr_pvt_data->pdi.PBMQ_rx, (PBM_Handle) hPkt );
    }



    /* Notify NDK stack of pending Rx Ethernet packet */
    STKEVENT_signal( ptr_pvt_data->pdi.hEvent, STKEVENT_ETHERNET, 1 );
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



static int
EmacSend (NETIF_DEVICE* ptr_net_device, PBM_Handle hPkt)
{
    EMAC_DATA*          ptr_pvt_data;
    register uint8_t*       buffer;
    register uint32_t       length;
    uint32_t                coreNum;
    EMAC_DRV_ERR_E retVal;

#ifdef _TMS320C6X
    coreNum = CSL_chipReadDNUM();
#else
    coreNum = 0;
#endif


   if (linkUp == 0)
   {
    return EMAC_DRV_RESULT_SEND_ERR;
   }

    /* Begin Critical Section before accessing shared resources. */
    //key = Osal_cppiCsEnter();
    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;


    /* Make sure the driver does not transmit packet less than min. as per the
     * Ethernet standards. */
    if( PBM_getValidLen(hPkt) < 60 )
        PBM_setValidLen (hPkt, 60 );

    /* We do not do any packet size checks here. If the packet
     * is too big to fit in the MTU configured on the peripheral,
     * then the driver/CSL layer should catch the error.
     */
    if(1)
    {
        /* Peek into the packet to check out if any
         * prioritization is needed.
         *
         * All raw Ethernet packets are tagged with the EMAC
         * channel number onto which they need to be sent out
         * in the PktPriority field.
         */
        if (((PBM_Pkt *)hPkt)->PktPriority != PRIORITY_UNDEFINED)
        {
            /* PktPriority contains the EMAC channel number on which
             * the packet needs to be txed.
             */
            ptr_pvt_data->pdi.PhysIdx = (((PBM_Pkt *)hPkt)->PktPriority);
        }
        else
        {
            /* This is just a normal IP packet. Enqueue the packet in the
             * Tx queue and send it for transmission.
             * We are assuming here that the IP packets are transmitted
             * on Channel 0 -> Core 0; Channel 1 --> Core 1; Channel 2 --> Core 2.
             * and that the Raw packets can be transmitted on any channel.
             */
                ptr_pvt_data->pdi.PhysIdx = coreNum;
        }

        /* Pass the packet to the controller if the transmitter is free. */
        if(ptr_pvt_data->pdi.TxFree )
        {
            buffer = PBM_getDataBuffer(hPkt) + PBM_getDataOffset(hPkt);
            length = PBM_getValidLen(hPkt);
              /* Clean the cache for external/L2 addresses */
              if( ((uint32_t)buffer & EMAC_EXTMEM  ) ||
                  ((uint32_t)buffer & EMAC_LL2SRAM ) ) {
                  CacheP_wbInv( (void *)buffer, length );
              }
            }
    }

        /* End Critical Section */
        //Osal_cppiCsExit (key);

    length = PBM_getValidLen(hPkt);
    buffer = PBM_getDataBuffer(hPkt) + PBM_getDataOffset(hPkt);


    EMAC_PKT_DESC_T* pkt_desc = (EMAC_PKT_DESC_T *) Osal_nimuMalloc (sizeof(EMAC_PKT_DESC_T), CACHE_LINESZ);
    if(pkt_desc == NULL)
    {
        return EMAC_DRV_RESULT_SEND_ERR;
    }

    pkt_desc->AppPrivate = (uint32_t)hPkt;
    pkt_desc->BufferLen = length;
    pkt_desc->DataOffset  = 0;
    pkt_desc->Flags = 0;
    pkt_desc->PktChannel = 0;
    pkt_desc->ValidLen = length;
    pkt_desc->PktLength = length;
    pkt_desc->PktFrags = 1;    /* need to check this */
    pkt_desc->pNext = NULL;
    pkt_desc->pPrev= NULL;
    pkt_desc->pDataBuffer = buffer;

    retVal = emac_send(0, pkt_desc);



    return (retVal);

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
    PBM_Handle  hPacket;

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
static int Emacioctl (NETIF_DEVICE* ptr_net_device, uint32_t  cmd, void* pBuf, uint32_t size)
{
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
    EMACInit_Core(hEvent);

    return 0;
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
    Uint32              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{

    PBM_free((PBM_Handle)(p_pkt_desc->AppPrivate));
    Osal_nimuFree(p_pkt_desc, sizeof(EMAC_PKT_DESC_T));
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
    Uint32              port_num,
    Uint32              pkt_size
)
{
    PBM_Handle pbmHandle = NULL;
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;
     uint8_t* bufferPtr;

    if (pkt_size < (NIMU_EMAC_MAX_PKT_SIZE + sizeof(EMAC_PKT_DESC_T)))
    {
        pbmHandle = PBM_alloc(pkt_size + sizeof (EMAC_PKT_DESC_T));
    }

    if (pbmHandle == NULL)
    {
        NIMU_drv_log("nimu_alloc_pkt: PBM_alloc returned NULL\n");
        return NULL;
    }
    PBM_setDataOffset(pbmHandle, 0);


    bufferPtr =  PBM_getDataBuffer(pbmHandle);

    p_pkt_desc =  (EMAC_PKT_DESC_T*)&bufferPtr[pkt_size];

    p_pkt_desc->BufferLen = pkt_size;
    p_pkt_desc->pDataBuffer = bufferPtr;
    p_pkt_desc->AppPrivate = (uint32_t )pbmHandle;

    p_pkt_desc->DataOffset = 0;
    
    
    return p_pkt_desc;
}






static int EMACInit_Core (STKEVENT_Handle hEvent)
{

    
    //NETIF_DEVICE*       ptr_device;
    EMAC_DATA*  ptr_pvt_data;
    char names[6][5]={"eth0","eth1","eth2","eth3","eth4","eth5"};
    uint32_t coreNum;
    uint32_t i;
    NIMU_EMAC_EXT_info emac_info;
    EMAC_HwAttrs_V1 emac_cfg;
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CONFIG_INFO_T cfg_info;
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[1];


#ifdef _TMS320C6X
    coreNum = CSL_chipReadDNUM();
#else
    coreNum = 0;
#endif

    /* memset netif device struct */
    memset(&ptr_device[0], 0, sizeof(ptr_device));

    NIMU_drv_log1("EMACInitCore: coreNum: %d\n", (int)coreNum);
    /* Allocate memory for the private data */
    ptr_pvt_data    = (EMAC_DATA *)Osal_nimuMalloc (NIMU_roundUp(sizeof(EMAC_DATA), CACHE_LINESZ), CACHE_LINESZ);

    if (ptr_pvt_data == NULL)
    {
        NIMU_drv_log ("Error: Unable to allocate private memory data\n");
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


    for (i = 0; i < NIMU_MAX_EMAC_PORT_NUM; i++)
    {
        NIMU_getEmacInfo (i, &emac_info);
        if (emac_info.mode == 1)
        {
            gTxPort = 0;
            break;
        }
    }
    if (i < NIMU_MAX_EMAC_PORT_NUM)
    {
        gTxPort = 0;
        memcpy(ptr_pvt_data->pdi.bMacAddr, emac_info.mac_address, 6);
    }

    
    else
    {
        NIMU_drv_log ("Error: Unable to find a TX EMAC port\n");
        return -1;
    }

    /* Populate the Network Interface Object. */
    strcpy (ptr_device[0].name, names[coreNum]);
    ptr_device[0].mtu         = ETH_MAX_PAYLOAD - ETHHDR_SIZE;
    ptr_device[0].pvt_data    = (void *)ptr_pvt_data;

    /* Populate the Driver Interface Functions. */
    ptr_device[0].start       = EmacStart;
    ptr_device[0].stop        = EmacStop;
    ptr_device[0].poll        = EmacPoll;
    ptr_device[0].send        = EmacSend;
    ptr_device[0].pkt_service = EmacPktService;
    ptr_device[0].ioctl       = Emacioctl;
    ptr_device[0].add_header  = NIMUAddEthernetHeader;


    EMAC_socGetInitCfg(0, &emac_cfg);

    open_cfg.hwAttrs = (void*)&emac_cfg;
    open_cfg.phy_addr = emac_cfg.phyAddr;
    open_cfg.alloc_pkt_cb = nimu_alloc_pkt;
    open_cfg.free_pkt_cb = nimu_free_pkt;
    open_cfg.rx_pkt_cb = nimu_rx_pkt_cb;
    open_cfg.loop_back = 0;
    open_cfg.master_core_flag = 1;
#ifdef _TMS320C6X
    open_cfg.max_pkt_size = 1514;
#else
    open_cfg.max_pkt_size = 1408; /* current limitation due to NDK PBM buffer size  for A15*/
#endif
    open_cfg.mdio_flag = 1;
    open_cfg.num_of_chans = 1;
    open_cfg.num_of_rx_pkt_desc = 64;
    open_cfg.num_of_tx_pkt_desc = 64;
   

    chan_cfg[0].p_mac_addr = (EMAC_MAC_ADDR_T*)&ptr_pvt_data->pdi.bMacAddr[0];
#if 0
    for (i=0;i<6;i++)
    {
        chan_cfg[0].p_mac_addr->addr[i] = ptr_pvt_data->pdi.bMacAddr[i];
    }
#endif
    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    open_cfg.p_chan_mac_addr = &chan_cfg[0];
    if ( emac_open(0, &open_cfg) != EMAC_DRV_RESULT_OK)
    {
        return -1;
    }

    cfg_info.mcast_cnt = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter = EMAC_PKTFLT_MULTICAST;;
    emac_config(0, &cfg_info);

    /* Register the device with NIMU */
    if (NIMURegister (ptr_device) < 0)
    {
        NIMU_drv_log ("Error: Unable to register the EMAC\n");
        return -1;
    }
    NIMU_drv_log ("Registration of the EMAC Successful, waiting for link up ..\n");
    return 0;

}


