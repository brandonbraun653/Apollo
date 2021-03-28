/*
 * nimu_eth.c
 *
 * Copyright (C) 2011 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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
#include <stdio.h> /* to use printf */
#include <stdint.h>




#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_semAux.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>  /* this is for C66x only */
#include <ti/csl/csl_chipAux.h>
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>


#include <ti/osal/osal.h>

#include <ti/drv/qmss/qmss_drv.h>
#include <ti/transport/ndk/nimu/src/NIMU_drv_log.h>
#include <ti/transport/ndk/nimu/src/nimu_osal.h>
#include <ti/transport/ndk/nimu/src/v1/nimu_eth.h>
#include <ti/transport/ndk/nimu/src/v1/nimu_internal.h>
#include <ti/csl/csl_cpsgmiiAux.h>
#include <ti/csl/cslr_cpsgmii.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_xmcAux.h>
#include <ti/csl/cslr_xmc.h>
#include <ti/csl/csl_serdes_ethernet.h>
#include <ti/csl/soc/c6678/src/csl_qm_queue.h>

/* The following code and define is used for code timing measurements of the Tx and Rx routines */
#ifdef TIMING
#include <ti/csl/csl_tsc.h>
#define MAX_TIMING_PACKETS	1000
#endif


#define MAX_CORES   	8

#ifdef _TMS320C6X
extern void NIMU_osalRegisterInterruptDsp(int16_t evt, void* fxn, void* arg, Bool unmask, int32_t vectId);
#endif
extern int32_t NIMU_stopCppi(NIMU_CPPI_CFG_TYPE       cfg_type);
extern int32_t NIMU_stopQmss(void);
void CycleDelay (int32_t count)
{
    if (count <= 0)
        return;

     uint32_t start_val  = CSL_chipReadTSCL();

    while ((CSL_chipReadTSCL() - start_val) < count);
    return;

}
void System_flush(void)
{
    fflush(stdout);
}
int32_t  nimu_get_emac_info(uint32_t port_num, NIMU_EMAC_EXT_info * emac_info)
{
    uint32_t mac_addr2, mac_addr1;

    NIMU_drv_log("nimu_get_emac_info called \n");

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

int32_t
NIMU_qmssQPop
(
    Qmss_QueueHnd           handler,
    NIMU_QHANDLER_TYPE           type,
    Cppi_HostDesc**         pHostDescriptor
)
{

    Cppi_HostDesc*      pHostDesc = *pHostDescriptor;

    pHostDesc = Qmss_queuePop (handler);

    /* Get a Tx free descriptor to send a command to the PA PDSP */
    if (pHostDesc == NULL)
    {
        //gQPopErrorCounter++;
        return -1;
    }
    /* The descriptor address returned from the hardware has the
     * descriptor size appended to the address in the last 4 bits.
     *
     * To get the true descriptor size, always mask off the last
     * 4 bits of the address.
     */
    pHostDesc = (Cppi_HostDesc *) ((uint32_t) pHostDesc & 0xFFFFFFF0);
    *pHostDescriptor = pHostDesc;


    /* Inv cache based on the qhandler type*/
    CACHE_invL1d((void *)pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);
    CACHE_invL2((void *) pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);

    if (type != QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF) {
        /* Not needed for FDQ with no attached buffers pop */
        CACHE_invL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
        CACHE_invL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    asm (" MFENCE " );
    return 0;
}
/** ============================================================================
 *   @n@b NIMU_qmssQPush
 *
 *   @b Description
 *   @n This API implements a the queue push logic with the Cache Management
 *
 *   @param[in]  handler
 *        Queue handler
 *   @param[in]  descAddr
 *        Descriptor address
 *   @param[in]  packetSize
 *        packet Size
 *   @param[in]  descSize
 *        descriptor Size
 *   @param[in]  location
 *        Qmss_Location location
 *   @return    
 *   @n None
 * =============================================================================
 */
void 
NIMU_qmssQPush 
(
    Qmss_QueueHnd          handler,
    void                   *descAddr, 
    uint32_t               packetSize, 
    uint32_t               descSize, 
    Qmss_Location          location 
)
{

    Cppi_HostDesc*         pHostDesc = (Cppi_HostDesc *) descAddr;
    
    if ( descAddr == NULL ) {
        //gQPushErrorCounter ++;
        NIMU_drv_log("NIMU_qmssQPush returing with error\n");
        return;
    }
    /* Wb data cache */
    CACHE_wbL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    CACHE_wbL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    CACHE_wbL1d((void *)pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);
    CACHE_wbL2((void *) pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);

    asm (" MFENCE " );
    Qmss_queuePushDescSize (handler, 
                    pHostDesc, 
                    descSize 
                   );
}

uint32_t    coreKey [MAX_CORES];

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
  * @brief  EmacInit for the EVM
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
    paMacAddr_t     broadcast_mac_addr  = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    paEthInfo_t     ethInfo             = { { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },     /* Src mac = dont care */
                                            { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15 },     /* Default Dest mac */
                                              0,                                        /* vlan = dont care */
                                              0,                                        /* ignore ether type */
                                              0                                         /* MPLS tag = don't care */
                                          };
    paRouteInfo_t   routeInfo           = { pa_DEST_HOST,           /* Route a match to the host */
                                            0,                      /* Flow ID 0 */
                                            0,                      /* Destination queue */
                                            -1,                     /* Multi route disabled */
                                            0xaaaaaaaa,             /* SwInfo 0 */
                                            0,                      /* SwInfo 1 is dont care */
                                            0,                      /* customType = pa_CUSTOM_TYPE_NONE */         \
                                            0,                      /* customIndex: not used */        \
                                            0,                      /* pkyType: for SRIO only */       \
                                            NULL                    /* No commands */
                                          };



    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    /* Setup Tx */
    if (Setup_Tx () != 0)
    {
        NIMU_drv_log ("Tx setup failed \n");
        return -1;
    }

    /* Setup Rx */
    if (Setup_Rx (ptr_net_device) != 0)
    {
    	NIMU_drv_log ("Rx setup failed \n");
        return -1;
    }

    memcpy (&ethInfo.dst[0],  ptr_pvt_data->pdi.bMacAddr,  sizeof(paMacAddr_t));

    /* Set up the MAC Address LUT*/
    if (Add_MACAddress (&ethInfo, &routeInfo) != 0)
    {
    	NIMU_drv_log ("Add_MACAddress failed \n");
        return -1;
    }

    memcpy (&ethInfo.dst[0],  broadcast_mac_addr,  sizeof(paMacAddr_t));
    /* Set up the MAC Address LUT for Broadcast */
    if (Add_MACAddress (&ethInfo, &routeInfo) != 0)
    {
    	NIMU_drv_log ("Add_MACAddress failed \n");
        return -1;
    }
    /* Verify the Tx and Rx Initializations */
    if (Verify_Init () != 0)
    {
    	NIMU_drv_log ("Warning:Queue handler Verification failed \n");
    }

    /* Copy the MAC Address into the network interface object here. */
    mmCopy(&ptr_net_device->mac_address[0], &ptr_pvt_data->pdi.bMacAddr[0], 6);

    /* Set the 'initial' Receive Filter */
    ptr_pvt_data->pdi.Filter = ETH_PKTFLT_MULTICAST;

    ptr_pvt_data->pdi.TxFree = 1;

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
    uint16_t         count, i;
    Cppi_Desc*     pCppiDesc;
    uint8_t*         bufaddr;
    uint32_t         bufLen;

    /* Disable event, interrupt */

    /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;
    Osal_nimuFree((Ptr)ptr_pvt_data, NIMU_roundUp(sizeof(EMAC_DATA), CACHE_LINESZ));

    count = Qmss_getQueueEntryCount(gRxQHnd);

    /* Free the packet data buffer associated with the Rx Descriptor */
    for (i=0; i < count; i++) {
        /* Need to free up the PBM handle */
        /* free the PBM packet */

        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (gRxQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) == -1)
        {
            return -1;
        }

        /* Get the Address and Length for Free */
        Cppi_getOriginalBufInfo(Cppi_DescType_HOST, pCppiDesc, &bufaddr, &bufLen);
        Osal_nimuFree((Ptr)bufaddr, bufLen);
    }

    count = Qmss_getQueueEntryCount(gRxFreeQHnd);
    /* Free the packet data buffer associated with the Rx Descriptor */
    for (i=0; i < count; i++) {
        /* Need to free up the PBM handle */
        /* free the PBM packet */

        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (gRxFreeQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) == -1)
        {
            return -1;
        }

        /* Get the Address and Length for Free */
        Cppi_getOriginalBufInfo(Cppi_DescType_HOST, pCppiDesc, &bufaddr, &bufLen);
        Osal_nimuFree ((Ptr)bufaddr, bufLen);
    }


    /* tear down queues and dmas */
    NIMU_stopQmss();
    Qmss_queueClose (gPaCfgCmdRespQHnd);
    Qmss_queueClose (gTxFreeQHnd);
    Qmss_queueClose (gRxFreeQHnd);
    Qmss_queueClose (gRxQHnd);
    Qmss_queueClose (gTxReturnQHnd);

    for (i = 0; i < NSS_NUM_TX_QUEUES; i++)
      Qmss_queueClose (gPaTxQHnd[i]);

    NIMU_stopCppi(CPPI_CFG_PASS);

    Osal_nimuFree((Ptr)ptr_net_device, NIMU_roundUp(sizeof(NETIF_DEVICE), CACHE_LINESZ));
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
#pragma DATA_SECTION(TxDescArray, ".DbgSection");
Cppi_HostDesc   TxDescArray[NUM_TX_DESC];
int             TxDescArrayIndex = 0;
int             gtotal_pkts_freed = 0;
#pragma DATA_SECTION(DescIndexArray, ".DbgSection");
int32_t DescIndexArray[NIMU_NUM_TX_DESC];
int32_t gDescTest = 0;
printHostDesc (Cppi_HostDesc*      pHostDesc)
{
   NIMU_drv_log1 (" pHostDesc->buffLen       =%ld \n"      ,    pHostDesc->buffLen       );
   NIMU_drv_log1 (" pHostDesc->buffPtr       =%ld \n"      ,    pHostDesc->buffPtr       );
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

#ifdef TIMING
#pragma DATA_SECTION(txisr_time, ".TimingSection");
uint32_t 	txisr_time[MAX_TIMING_PACKETS];
#pragma DATA_SECTION(txisr_time_idx, ".TimingSection");
uint32_t	 	txisr_time_idx = 0;
#pragma DATA_SECTION(txisr_free_count, ".TimingSection");
uint32_t 	txisr_free_count[MAX_TIMING_PACKETS];
#endif

static int
EmacSend (NETIF_DEVICE* ptr_net_device, PBM_Handle hPkt)
{
    EMAC_DATA*          ptr_pvt_data;
    Cppi_Desc*          pCppiDesc;
    uint32_t            dataBufferSize, i,  count=0;
    register uint8_t*   buffer;
    register uint32_t   length;
    Cppi_HostDesc*      pHostDesc;
    uint32_t			coreNum;
    Ptr					key;
#ifdef TIMING
    CSL_Uint64			st,et;
#endif

#ifdef TIMING
    st = 0;
    et = 0;
#endif

#ifdef TIMING_TX
    /* record start time */
    if (txisr_time_idx < MAX_TIMING_PACKETS) {
    	st = CSL_tscRead();
    }
#endif

    /* Begin Critical Section before accessing shared resources. */
    key = Osal_cppiCsEnter();

    /* Get the core number. */
    coreNum = CSL_chipReadDNUM();

    count = Qmss_getQueueEntryCount (gTxReturnQHnd);

    

    /* Check if we got to free up any PBM handles? */
#ifdef TIMING_FREE
    	if (txisr_time_idx < MAX_TIMING_PACKETS) {
    		st = CSL_tscRead();
    		txisr_free_count[txisr_time_idx] = count;
    	}
#endif

   for (i = 0; i < count; i++)  {
        PBM_Handle    hPkt_to_free;

        /* Need to free up the PBM handle */
        /* free the PBM packet */

        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (gTxReturnQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) == -1)
        {
           goto error_cond;
        }
        pHostDesc = (Cppi_HostDesc *)pCppiDesc;
        /* Software info is intended to hold the PBM Pkt Handle for buffer management */
        hPkt_to_free = (PBM_Handle ) pHostDesc->softwareInfo0;

        /* Clear the PBM Handle set in the descriptor  */
        pHostDesc->softwareInfo0 = NULL;

        /* Push descriptor to Tx free queue */
        NIMU_qmssQPush     (gTxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);

        PBM_free( (PBM_Handle) hPkt_to_free);

    }

#ifdef TIMING_FREE
	/* record end time */
	if (txisr_time_idx < MAX_TIMING_PACKETS) {
		et = CSL_tscRead();
		txisr_time[txisr_time_idx++] = (uint32_t) (et - st);
	}
#endif

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

              /* Get a free descriptor from the global free queue we setup
               * during initialization.
               */
              if ((NIMU_qmssQPop (gTxFreeQHnd, QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) == -1)
              {
                    gTxDropCounter++;
                    goto error_cond;
              }
              pHostDesc = (Cppi_HostDesc *)pCppiDesc;

              pHostDesc->softwareInfo0 = (uint32_t) hPkt;

              dataBufferSize  =   length;
              Cppi_setData (  Cppi_DescType_HOST,
                              (Cppi_Desc *) pCppiDesc,
                              (uint8_t *) NIMU_convertCoreLocal2GlobalAddr((uint32_t)buffer),
                              dataBufferSize
                           );
              Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, dataBufferSize);

              count = Qmss_getQueueEntryCount (gTxReturnQHnd);

#ifdef PA_LOOPBACK
              NIMU_qmssQPush (gPaTxQHnd[0], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
#else
              Cppi_setPSFlags (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (1<<gTxPort));
              /* Send the packet out the mac. It will loop back to PA if the mac/switch
               * have been configured properly
               */
			NIMU_qmssQPush (gPaTxQHnd[8], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
#endif

              /* Increment the application transmit counter */
              gTxCounter ++;
        }

        /* Packet has been successfully transmitted. */
        /* End Critical Section */
        Osal_cppiCsExit (key);

#ifdef TIMING_TX
		/* record end time */
		if (txisr_time_idx < MAX_TIMING_PACKETS) {
			et = CSL_tscRead();
			txisr_time[txisr_time_idx++] = (uint32_t) (et - st);
		}
#endif
        return 0;
    }

error_cond:
    {

        /* End Critical Section */
        Osal_cppiCsExit (key);

#ifdef TIMING_TX
		/* record end time */
		if (txisr_time_idx < MAX_TIMING_PACKETS) {
			et = CSL_tscRead();
			txisr_time[txisr_time_idx++] = (uint32_t) (et - st);
		}

#endif
        return -1;
    }
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
static Bool  gIsPingListUsed = 0;

#ifdef TIMING
#pragma DATA_SECTION(rxisr_time, ".TimingSection");
uint32_t	rxisr_time[MAX_TIMING_PACKETS]; /* hold start time, end time, start time, end time, etc */
#pragma DATA_SECTION(rxisr_time_idx, ".TimingSection");
uint32_t		rxisr_time_idx;
#pragma DATA_SECTION(rxisr_pktcount, ".TimingSection");
uint32_t		rxisr_pktcount;
#endif

void
EmacRxPktISR
(
    NETIF_DEVICE*     ptr_net_device
)
{
    uint32_t            protocol, pktLen;
    uint32_t            coreNum;
    uint8_t*            pBuffer;
    Cppi_HostDesc*      pHostDesc;
    PBM_Handle          hPkt;
    Cppi_Desc*          pCppiDesc;
    uint32_t            count, i;
    uint32_t*           ListAddress;
    EMAC_DATA*          ptr_pvt_data;
    PBM_Pkt*            rx_pbm_pkt;
    void*               accum_list_ptr;
#ifdef TIMING
    CSL_Uint64			st, et;
#endif

#ifdef TIMING
    /* record start time */
    if (rxisr_pktcount < MAX_TIMING_PACKETS) {
    	st = CSL_tscRead();
    }
#endif


    coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);

    /* Disable the interrupt */
    coreKey [coreNum] = NIMU_osalHardwareIntDisable();
    NIMU_osalHardwareIntrDisable(NIMU_ETH_INTERRUPT);
    //coreKey [coreNum] =  Osal_DisableInterrupt(NIMU_ETH_INTERRUPT); //Hwi_disable();
    /* Get the core number. */

   /* Get the pointer to the private data */
    ptr_pvt_data = (EMAC_DATA *)ptr_net_device->pvt_data;

    if (!gIsPingListUsed){
        accum_list_ptr = (void *)&gHiPriAccumList[0];
    }
    else {
        accum_list_ptr = (void *)&gHiPriAccumList[MAX_HI_PRI_ACCUM_LIST_SIZE];
    }


    /* Invalidate cache if needed --
     *   if accumulator is in DDR then INV L2.
     *   if accumulator is in shared RAM (MSMC) invalidate L1
     */
    if((uint32_t)(gHiPriAccumList) & EMAC_EXTMEM ){
        CACHE_invL2(accum_list_ptr, sizeof(gHiPriAccumList)/2, CACHE_WAIT);
    }

    else if (((uint32_t)(gHiPriAccumList) & EMAC_MSMCSRAM) == EMAC_MSMCSRAM ) {
        CACHE_invL1d(accum_list_ptr, sizeof(gHiPriAccumList)/2, CACHE_WAIT);
     }

    i           = MAX_HI_PRI_ACCUM_LIST_SIZE - 1 - (RX_INT_THRESHOLD);
    ListAddress = (uint32_t* )NIMU_convertCoreLocal2GlobalAddr((uint32_t) &gHiPriAccumList[i]);

    /* Process ISR.
     *
     * Get the number of entries in accumulator list.
     * The hardware enqueues data alternatively to Ping/Pong buffer lists in
     * the accumulator. Hence, we need to track which list (Ping/Pong)
     * we serviced the last time and accordingly process the other one
     * this time around.
     */
     if (!gIsPingListUsed)
     {
        /* Serviced Pong list last time. So read off the Ping list now */
        count   =   ListAddress[0];
     }
     else
     {
        /* Serviced Pong list last time. So read off the Ping list now */
        count   =   ListAddress[RX_INT_THRESHOLD + 1];
     }

    /* Nothing to receive, so return... */
    if (count == 0) {
        /* End Critical Section */


    NIMU_osalHardwareIntrEnable(NIMU_ETH_INTERRUPT);
    NIMU_osalHardwareIntRestore(coreKey[coreNum]);

     //Osal_Restore(NIMU_ETH_INTERRUPT, coreKey [coreNum]);
        /* Clear INTD */
        Qmss_ackInterrupt(PA_ACC_CHANNEL_NUM + coreNum, 1);
        Qmss_setEoiVector(Qmss_IntdInterruptType_HIGH, PA_ACC_CHANNEL_NUM + coreNum);
        return ; /* Not enough packets are received */
    }

    /* Process all the Results received
     *
     * Skip the first entry in the list that contains the
     * entry count and proceed processing results.
     */
    for (i = 1; i <= count; i ++)
    {

        gRxCounter ++;

        /* Get the result descriptor.
         *
         * The hardware enqueues data alternatively to Ping/Pong buffer lists in
         * the accumulator. Hence, we need to track which list (Ping/Pong)
         * we serviced the last time and accordingly process the other one
         * this time around.
         */
        if (!gIsPingListUsed)
        {
            /* Serviced Pong list last time. So read off the Ping list now */
            pCppiDesc   =   (Cppi_Desc *) ListAddress [i];
        }
        else
        {
            /* Serviced Ping list last time. So read off the Pong list now
             *
             * Skip over Ping list length to arrive at Pong list start.
             */
            pCppiDesc   =   (Cppi_Desc *) ListAddress [i + RX_INT_THRESHOLD + 1];
        }

        /* Descriptor size appended to the address in the last 4 bits.
         *
         * To get the true descriptor size, always mask off the last
         * 4 bits of the address.
         */
        pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);
        pHostDesc = (Cppi_HostDesc *)pCppiDesc;

        /* Invalidate cache based on where the memory is */
        if((uint32_t)(pHostDesc) & EMAC_EXTMEM ){
            CACHE_invL2((void *) pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);
        }

        else if (((uint32_t)(pHostDesc) & EMAC_MSMCSRAM) == EMAC_MSMCSRAM ) {
            CACHE_invL1d((void *)pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);
         }

        if((uint32_t)(pHostDesc->buffPtr) & EMAC_EXTMEM ){
            CSL_XMC_invalidatePrefetchBuffer();
        	CACHE_invL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
        }

        else if (((uint32_t)(pHostDesc->buffPtr) & EMAC_MSMCSRAM) == EMAC_MSMCSRAM ) {
            CSL_XMC_invalidatePrefetchBuffer();
        	CACHE_invL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
         }

        /*
         * We should not see packets too large but check anyways ...
         * Note that we are subtracting off the FCS the switch added to the frame.
         * If its too large then return it to the free queue.
         */
        if ((pHostDesc->buffLen-4) > (ptr_net_device->mtu + ETHHDR_SIZE)) {
        	/* lets try the next one... we should record this as a too large.... */
        	gRxDropCounter++;
            pHostDesc->buffLen = pHostDesc->origBufferLen;
            NIMU_qmssQPush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
            continue;
        }

        /* Allocate the PBM packet for the Max MTU size*/
        if (NULL == (hPkt = PBM_alloc(1514))) {
        	/* could not get a free NDK packet, maybe the next time around we can... */
			gRxDropCounter++;
	        pHostDesc->buffLen = pHostDesc->origBufferLen;
            NIMU_qmssQPush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
			continue;
        }

        rx_pbm_pkt = (PBM_Pkt *) hPkt;

        PBM_setDataOffset((PBM_Handle) hPkt, 0);

        /* removing the FCS length the EMAC switch adds  here */
        pktLen    = (pHostDesc->buffLen-4);

        /* Set to minimum packet size */
        if (pktLen < 60) {
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
        pBuffer =  (uint8_t* )NIMU_convertCoreLocal2GlobalAddr((uint32_t) pHostDesc->buffPtr);

        /* Extract the Ethernet type from the packet. */
        protocol = ( pBuffer[12] << 8) | pBuffer[13] ;
        protocol = (protocol & 0xFFFFu);

        PBM_setIFRx((PBM_Handle) hPkt, (void*) protocol );

        /* Copy the data buffer received to the allocated PBM packet */
        mmCopy((uint8_t* )rx_pbm_pkt->pDataBuffer, (uint8_t* )pBuffer, pktLen) ;

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

       /* Free the packet back to the Rx FDQ */
        pHostDesc->buffLen = pHostDesc->origBufferLen;
        NIMU_qmssQPush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
    }

    ListAddress = (uint32_t *) NIMU_convertCoreLocal2GlobalAddr((uint32_t) &gHiPriAccumList[0]);

    /* Clear the accumulator list and save whether we used Ping/Pong
     * list information for next time around.
     */
     if (!gIsPingListUsed)
    {
        /* Just processed Ping list */
        gIsPingListUsed  =   1;

        i = sizeof (gHiPriAccumList)/2;

        /* Clear the accumulator list after processing */
        memset ((void *) &gHiPriAccumList[0], 0, i);

        if(
            ((uint32_t)(&gHiPriAccumList[0]) & EMAC_EXTMEM ) ||
            (((uint32_t)(&gHiPriAccumList[0]) & EMAC_MSMCSRAM) == EMAC_MSMCSRAM )
          )
        {
            /* This needs to be enabled if gHiPriAccumList is in External Memory or MSMCMEM */
             CACHE_wbL2 ((void *)&gHiPriAccumList[0], i, CACHE_WAIT);
        }
    }
    else
    {
        /* Just processed Pong list */
        gIsPingListUsed  =   0;
        i = sizeof (gHiPriAccumList)/2;

        /* Clear the accumulator list after processing */
        memset ((void *) &gHiPriAccumList[MAX_HI_PRI_ACCUM_LIST_SIZE], 0, i);

        if(
            ((uint32_t)(&gHiPriAccumList[MAX_HI_PRI_ACCUM_LIST_SIZE]) & EMAC_EXTMEM ) ||
            (((uint32_t)(&gHiPriAccumList[MAX_HI_PRI_ACCUM_LIST_SIZE]) & EMAC_MSMCSRAM) == EMAC_MSMCSRAM )
          )
        {
            /* This needs to be enabled if gHiPriAccumList is in External Memory or MSMCMEM */
            CACHE_wbL2((void *) &gHiPriAccumList[MAX_HI_PRI_ACCUM_LIST_SIZE], i, CACHE_WAIT);
        }
    }

    /* Notify NDK stack of pending Rx Ethernet packet */
    STKEVENT_signal( ptr_pvt_data->pdi.hEvent, STKEVENT_ETHERNET, 1 );

    /* End Critical Section */
    NIMU_osalHardwareIntrEnable(NIMU_ETH_INTERRUPT);
    NIMU_osalHardwareIntRestore(coreKey[coreNum]);
    //Osal_Restore(NIMU_ETH_INTERRUPT, coreKey [coreNum]);

#ifdef TIMING
    /* record end time */
	if (rxisr_pktcount < MAX_TIMING_PACKETS) {
		et = CSL_tscRead();
		rxisr_time[rxisr_time_idx++] = (uint32_t) (et-st);
	    rxisr_pktcount += count;
	}
#endif

    /* Clear INTD */
    Qmss_ackInterrupt(PA_ACC_CHANNEL_NUM + coreNum, 1);
    Qmss_setEoiVector(Qmss_IntdInterruptType_HIGH, PA_ACC_CHANNEL_NUM + coreNum);



	return;
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
static int Emacioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size)
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

static int EMACInit_Core (STKEVENT_Handle hEvent)
{
    NETIF_DEVICE*       ptr_device;
    EMAC_DATA*  ptr_pvt_data;
    char names[6][5]={"eth0","eth1","eth2","eth3","eth4","eth5"};
    uint32_t coreNum, i;
    NIMU_EMAC_EXT_info emac_info;

    coreNum = CSL_chipReadDNUM();

    /* Allocate memory for the private data */
    ptr_pvt_data    = (EMAC_DATA *) Osal_nimuMalloc (NIMU_roundUp(sizeof(EMAC_DATA), CACHE_LINESZ), CACHE_LINESZ);

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

#ifndef SIMULATOR_SUPPORT
    for (i = 0; i < NIMU_MAX_EMAC_PORT_NUM; i++)
    {
        nimu_get_emac_info (i, &emac_info);
        if (emac_info.mode == 1)
        {
            break;
        }
    }
    if (i < NIMU_MAX_EMAC_PORT_NUM)
    {
        gTxPort = 1; /* force packet out on switch port 1 */
        memcpy(ptr_pvt_data->pdi.bMacAddr, emac_info.mac_address, 6);
    }
    else
    {
        NIMU_drv_log ("Error: Unable to find a TX EMAC port\n");
        return -1;
    }
#else
    {
        gTxPort = 1;
        nimu_get_emac_info (1, &emac_info);
        memcpy(ptr_pvt_data->pdi.bMacAddr, emac_info.mac_address, 6);
    }
#endif


    /* Init Logical Device */
    /* ptr_pvt_data->pdi.hEther = hEther; */

    /* Allocate memory for the EMAC. */
    ptr_device    = (NETIF_DEVICE *) Osal_nimuMalloc (NIMU_roundUp(sizeof(NETIF_DEVICE), CACHE_LINESZ), CACHE_LINESZ);

    if (ptr_device == NULL)
    {
        NIMU_drv_log ("Error: Unable to allocate memory for the EMAC\n");
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
    ptr_device->flags = NIMU_DEVICE_NO_FREE;

    /* Init PA LLD */
    if (Init_PASS () != 0)
    {
        NIMU_drv_log ("PASS init failed \n");
        return -1;
    }
    else
    {
        NIMU_drv_log ("PASS successfully initialized \n");
    }

    /* Initialize the CPSW switch */
    if (Init_Cpsw ((uint32_t) ptr_device->mtu,  ptr_pvt_data->pdi.bMacAddr) != 0)
    {
        NIMU_drv_log ("Ethernet subsystem init failed \n");
        return -1;
    }
    else
    {
        NIMU_drv_log ("Ethernet subsystem successfully initialized \n");
    }

    /* Register the device with NIMU */
    if (NIMURegister (ptr_device) < 0)
    {
    	NIMU_drv_log ("Error: Unable to register the EMAC\n");
        return -1;
    }

    NIMU_drv_log ("Registration of the EMAC Successful, waiting for link up ..\n");
    return 0;

}


/** ============================================================================
 *   @n@b Setup_Tx
 *
 *   @b Description
 *   @n This API sets up all relevant data structures and configuration required
 *      for sending data to PASS/Ethernet. It sets up a Tx free descriptor queue,
 *      PASS Tx queues required for send.
 *
 *   @param[in]
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Setup_Tx (void)
{
    uint8_t             isAllocated, i;
    Qmss_Queue      qRetInfo;
    Ptr             pCppiDesc;
    uint32_t        mySWInfo[] = {0x00000000, 0x00000000, 0x00000000};

    /* Open all Transmit (Tx) queues.
     *
     * These queues are used to send data to PA PDSP/CPSW.
     */
    for (i = 0; i < NSS_NUM_TX_QUEUES; i ++)
    {

        if ((gPaTxQHnd[i] = Qmss_queueOpen (Qmss_QueueType_PASS_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
        {
            NIMU_drv_log ("Error opening PA Tx queue \n");
            return -1;
        }
    }

    /* Open a Tx Free Descriptor Queue (Tx FDQ).
     *
     * This queue will be used to hold Tx free decriptors that can be filled
     * later with data buffers for transmission onto wire.
     */
    if ((gTxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_STARVATION_COUNTER_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening Tx Free descriptor queue \n");
        return -1;
    }

    /* Open a Tx Return Descriptor Queue (Tx Transmit CompletionQ).
     *
     * This queue will be used to hold Tx completed decriptors that can be filled
     * later with data buffers for transmission onto wire.
     */
    if ((gTxReturnQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening Tx Return descriptor queue \n");
        return -1;
    }

    qRetInfo = Qmss_getQueueNumber (gTxReturnQHnd);

    /* Attach some free descriptors to the Tx free queue we just opened. */
    for (i = 0; i < NIMU_NUM_TX_DESC; i++)
    {
        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (NIMU_qmssGetFreeQ(), QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc )) == -1)
        {
            break;
        }

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the completion q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue ((Cppi_DescType) Cppi_DescType_HOST, pCppiDesc, qRetInfo);

        /* Software info is inteded to hold the PBM Pkt Handle for buffer management */
        mySWInfo[1] = i;
        Cppi_setSoftwareInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *) mySWInfo);

        /* Push descriptor to Tx free queue */
        NIMU_qmssQPushDescSize (gTxFreeQHnd, pCppiDesc, SIZE_HOST_DESC);
    }
    if (i != NIMU_NUM_TX_DESC)
    {
        NIMU_drv_log ("Error allocating Tx free descriptors \n");
        return -1;
    }

    /* Open a Tx Command Free Descriptor Queue (Tx CMD FDQ).
     *
     * This queue will be used to hold Tx Command free decriptors
     */
    if ((gTxCmdFreeQHnd = Qmss_queueOpen (Qmss_QueueType_STARVATION_COUNTER_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening Tx Cmd Free descriptor queue \n");
        return -1;
    }

    /* Open a Tx Cmd Return Descriptor Queue (Tx Cmd Completion Queue).
     *
     * This queue will be used to hold Tx command completed decriptors
     */
    if ((gTxCmdReturnQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening Tx Return descriptor queue \n");
        return -1;
    }
    qRetInfo = Qmss_getQueueNumber (gTxCmdReturnQHnd);

    /* Attach some free descriptors to the Tx CMD free queue we just opened. */
    for (i = 0; i < NIMU_MAX_NUM_TX_CMD_DESC; i++)
    {
        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (NIMU_qmssGetFreeQ(), QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc )) == -1)
        {
            break;
        }

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the completion q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue ((Cppi_DescType) Cppi_DescType_HOST, pCppiDesc, qRetInfo);


        /* Push descriptor to Tx free queue */
        NIMU_qmssQPushDescSize (gTxCmdFreeQHnd, pCppiDesc, SIZE_HOST_DESC);
    }
    if (i != NIMU_MAX_NUM_TX_CMD_DESC)
    {
    	NIMU_drv_log ("Error allocating Tx Command free descriptors \n");
        return -1;
    }

    /* All done with Rx configuration. Return success. */
    return 0;
}


int32_t setup_rx_queue(Qmss_Queue *rxQInfo, NETIF_DEVICE*     ptr_net_device)
{
    uint8_t             isAllocated, accChannelNum;
    uint16_t           numAccEntries, intThreshold;
    Qmss_AccCmdCfg      accCfg;
    int32_t                     vectId;
    int16_t             eventId;
    uint32_t            ListAddress;
    uint32_t            index;

    uint8_t coreNum = CSL_chipReadDNUM();

    index           = MAX_HI_PRI_ACCUM_LIST_SIZE - 1 - (RX_INT_THRESHOLD);

    ListAddress = NIMU_convertCoreLocal2GlobalAddr((uint32_t) &gHiPriAccumList[index]);


    /* Open a Receive (Rx) queue.
     *
     * This queue will be used to hold all the packets received by PASS/CPSW
     *
     * Open the next available High Priority Accumulation queue for Rx.
     */
    if ((gRxQHnd = Qmss_queueOpen (Qmss_QueueType_HIGH_PRIORITY_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening a High Priority Accumulation Rx queue \n");
        return -1;
    }

    *rxQInfo = Qmss_getQueueNumber (gRxQHnd);
    

    /* Setup high priority accumulation interrupts on the Rx queue.
     *
     * Let's configure the accumulator with the following settings:
     *      (1) Interrupt pacing disabled.
     *      (2) Interrupt on every received packet
     */
    intThreshold    =   RX_INT_THRESHOLD;
    numAccEntries   =   (intThreshold + 1) * 2;
    accChannelNum   =   PA_ACC_CHANNEL_NUM + coreNum;

    /* Initialize the accumulator list memory */
    memset ((void *) ListAddress, 0, numAccEntries * 4);

    /* Setup the accumulator settings */
    accCfg.channel             =   accChannelNum;
    accCfg.command             =   Qmss_AccCmd_ENABLE_CHANNEL;
    accCfg.queueEnMask         =   0;
    accCfg.listAddress         =   ListAddress;
    accCfg.maxPageEntries      =   (intThreshold + 1); /* Add an extra entry for holding the entry count */
    accCfg.timerLoadCount      =   40;
    accCfg.timerLoadCount      =   0;
    accCfg.interruptPacingMode =   Qmss_AccPacingMode_LAST_INTERRUPT;
    accCfg.listEntrySize       =   Qmss_AccEntrySize_REG_D;
    accCfg.listCountMode       =   Qmss_AccCountMode_ENTRY_COUNT;
    accCfg.multiQueueMode      =   Qmss_AccQueueMode_SINGLE_QUEUE;
    accCfg.queMgrIndex         =   gRxQHnd;

    /* Program the accumulator */
    if (Qmss_programAccumulator (Qmss_PdspId_PDSP1, &accCfg) != QMSS_ACC_SOK)
    {
        return -1;
    }

   /* Register interrupts for the system event corresponding to the
     * accumulator channel we are using.
     */
    /* System event n - Accumulator Channel 0 */
    eventId         =   NIMU_ETH_EVENTID;

    /* Pick a interrupt vector id to use */
    vectId          =   NIMU_ETH_INTERRUPT;
    NIMU_osalRegisterInterruptDsp(eventId, (void*) &EmacRxPktISR, (void*)ptr_net_device, TRUE, vectId);

    return 0;

}

/** ============================================================================
 *   @n@b Setup_Rx
 *
 *   @b Description
 *   @n This API sets up all relevant data structures and configuration required
 *      for receiving data from PASS/Ethernet. It sets up a Rx free descriptor queue
 *      with some empty pre-allocated buffers to receive data, and an Rx queue
 *      to which the Rxed data is streamed for the example application. This API
 *      also sets up the QM high priority accumulation interrupts required to
 *      receive data from the Rx queue.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Setup_Rx (NETIF_DEVICE*     ptr_net_device)
{
    uint16_t        pktLen;
    Qmss_Queue          rxFreeQInfo, rxQInfo;
    Ptr                 pCppiDesc;
    Cppi_RxFlowCfg      rxFlowCfg;
    Ptr                 pDataBuffer;
    uint32_t            mySWInfo[] = {0x11112222, 0x33334444};
    uint8_t             isAllocated;
    uint8_t             i;
     if ((setup_rx_queue(&rxQInfo, ptr_net_device)) < 0)
    {
        NIMU_drv_log (" Error in setting up receive queue information\n");
        return -1;
    }
     

    pktLen = ptr_net_device->mtu + ETHHDR_SIZE + 4; /* ETh Header + 4 bytes of FCS */


    /* Open a Rx Free Descriptor Queue (Rx FDQ).
     *
     * This queue will hold all the Rx free descriptors. These descriptors will be
     * used by the PASS CPDMA to hold data received via CPSW.
     */
    if ((gRxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_STARVATION_COUNTER_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        NIMU_drv_log ("Error opening Rx Free descriptor queue \n");
        return -1;
    }
    rxFreeQInfo = Qmss_getQueueNumber (gRxFreeQHnd);

    /* Attach some free descriptors to the Rx free queue we just opened. */
    for (i = 0; i < NIMU_NUM_RX_DESC; i++)
    {
        /* Get a free descriptor from the global free queue we setup
         * during initialization.
         */
        if ((NIMU_qmssQPop (NIMU_qmssGetFreeQ(), QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pCppiDesc)) == -1)
        {
            break;
        }

        pktLen = NIMU_roundUp(pktLen, CACHE_LINESZ);
        if ((pDataBuffer = Osal_nimuMalloc (pktLen, CACHE_LINESZ)) == NULL)
        {
            NIMU_drv_log ("Error allocating memory for Rx data buffer \n");
            break;
        }

        /* Populate the Rx free descriptor with the buffer we just allocated. */
        Cppi_setData (Cppi_DescType_HOST, pCppiDesc, (uint8_t *)NIMU_convertCoreLocal2GlobalAddr((uint32_t)pDataBuffer), pktLen);

        /* Save original buffer information */
        Cppi_setOriginalBufInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *)NIMU_convertCoreLocal2GlobalAddr((uint32_t)pDataBuffer), pktLen);

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the free q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue (Cppi_DescType_HOST, pCppiDesc, rxFreeQInfo);

        Cppi_setSoftwareInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *) mySWInfo);

        Cppi_setPacketLen    (Cppi_DescType_HOST, pCppiDesc, pktLen);

        /* Push descriptor to Rx free queue */
        NIMU_qmssQPushDescSize (gRxFreeQHnd, pCppiDesc, SIZE_HOST_DESC);
        //Qmss_queuePushDescSize(gRxFreeQHnd, pCppiDesc, SIZE_HOST_DESC);
    }
    if (i != NIMU_NUM_RX_DESC)
    {
    	NIMU_drv_log ("Error allocating Rx free descriptors \n");
        return -1;
    }

    /* Setup a Rx Flow.
     *
     * A Rx flow encapsulates all relevant data properties that CPDMA would
     * have to know in order to successfully receive data.
     */
    /* Initialize the flow configuration */
    memset (&rxFlowCfg, 0, sizeof(Cppi_RxFlowCfg));
    rxFreeQInfo = Qmss_getQueueNumber (gRxFreeQHnd);

    /* Let CPPI pick the next available flow */
    rxFlowCfg.flowIdNum             =   CPPI_PARAM_NOT_SPECIFIED;

    rxFlowCfg.rx_dest_qmgr          =   rxQInfo.qMgr;
    rxFlowCfg.rx_dest_qnum          =   rxQInfo.qNum;

    rxFlowCfg.rx_desc_type          =   Cppi_DescType_HOST;

    rxFlowCfg.rx_ps_location        =   Cppi_PSLoc_PS_IN_DESC;
    rxFlowCfg.rx_psinfo_present     =   1;    /* Enable PS info */

    rxFlowCfg.rx_error_handling     =   0;    /* Drop the packet, do not retry on starvation by default */
    rxFlowCfg.rx_einfo_present      =   1;    /* EPIB info present */

    rxFlowCfg.rx_dest_tag_lo_sel    =   0;    /* Disable tagging */
    rxFlowCfg.rx_dest_tag_hi_sel    =   0;
    rxFlowCfg.rx_src_tag_lo_sel     =   0;
    rxFlowCfg.rx_src_tag_hi_sel     =   0;

    rxFlowCfg.rx_size_thresh0_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh1_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh2_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh0       =   0x0;
    rxFlowCfg.rx_size_thresh1       =   0x0;
    rxFlowCfg.rx_size_thresh2       =   0x0;

    rxFlowCfg.rx_fdq0_sz0_qmgr      =   rxFreeQInfo.qMgr; /* Setup the Receive free queue for the flow */
    rxFlowCfg.rx_fdq0_sz0_qnum      =   rxFreeQInfo.qNum;
    rxFlowCfg.rx_fdq0_sz1_qnum      =   0x0;
    rxFlowCfg.rx_fdq0_sz1_qmgr      =   0x0;
    rxFlowCfg.rx_fdq0_sz2_qnum      =   0x0;
    rxFlowCfg.rx_fdq0_sz2_qmgr      =   0x0;
    rxFlowCfg.rx_fdq0_sz3_qnum      =   0x0;
    rxFlowCfg.rx_fdq0_sz3_qmgr      =   0x0;

    rxFlowCfg.rx_fdq1_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq1_qmgr          =   rxFreeQInfo.qMgr;
    rxFlowCfg.rx_fdq2_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq2_qmgr          =   rxFreeQInfo.qMgr;
    rxFlowCfg.rx_fdq3_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq3_qmgr          =   rxFreeQInfo.qMgr;

    /* Configure the Rx flow */
    if ((gRxFlowHnd = Cppi_configureRxFlow (NIMU_cppiGetPASSHandle(), &rxFlowCfg, &isAllocated)) == NULL)
    {
    	NIMU_drv_log ("Error configuring Rx flow \n");
        return -1;
    }

    /* All done with Rx configuration. Return success. */
    return 0;
}

/** ============================================================================
 *   @n@b Init_MAC
 *
 *   @b Description
 *   @n This API initializes the CPGMAC Sliver (MAC Port) port.
 *
 *   @param[in]
 *   @n macPortNum      MAC port number for which the initialization must be done.
 *
 *   @param[in]
 *   @n macAddress      MAC address to configure on this port.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on this port.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void Init_MAC (uint32_t macPortNum, uint8_t macAddress[6], uint32_t mtu)
{
    /* Reset MAC Sliver 0 */
    CSL_CPGMAC_SL_resetMac (macPortNum);
    while (CSL_CPGMAC_SL_isMACResetDone (macPortNum) != TRUE);

    /* Setup the MAC Control Register for this port:
     *      (1) Enable Full duplex
     *      (2) Enable GMII
     *      (3) Enable Gigabit
     *      (4) Enable External Configuration. This enables
     *          the "Full duplex" and "Gigabit" settings to be
     *          controlled externally from SGMII
     *      (5) Don't Enable any control/error frames
     *      (6) Enable short frames
     */
    CSL_CPGMAC_SL_enableFullDuplex (macPortNum);
    CSL_CPGMAC_SL_enableGMII (macPortNum);
    CSL_CPGMAC_SL_enableGigabit (macPortNum);
    CSL_CPGMAC_SL_enableExtControl (macPortNum);

    /* Adding these configurations to allow the switch not to ignore any packets */
    CSL_CPGMAC_SL_enableRxCSF(macPortNum);

    /* Configure the MAC address for this port */
    CSL_CPSW_nGF_setPortMACAddress (macPortNum, macAddress);

    /* Configure VLAN ID/CFI/Priority.
     *
     * For now, we are not using VLANs so just configure them
     * to all zeros.
     */
    CSL_CPSW_nGF_setPortVlanReg (macPortNum, 0, 0, 0);

    /* Configure the Receive Maximum length on this port,
     * i.e., the maximum size the port can receive without
     * any errors.
     *
     * Set the Rx Max length to the MTU configured for the
     * interface.
     */
    CSL_CPGMAC_SL_setRxMaxLen (macPortNum, mtu);

    /* Done setting up the MAC port */
    return;
}

/** ============================================================================
 *   @n@b Init_MDIO
 *
 *   @b Description
 *   @n Not supported at moment. MDIO is not simulated yet.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void Init_MDIO (void)
{
    /* There is nothing to be done for C6678 EVM */
     return;
}

/** ============================================================================
 *   @n@b Init_Switch
 *
 *   @b Description
 *   @n This API sets up the ethernet switch subsystem and its Address Lookup
 *      Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on the switch.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void Init_Switch (uint32_t mtu)
{
    CSL_CPSW_3GF_PORTSTAT               portStatCfg;
    uint32_t  rx_max_len = mtu + ETHHDR_SIZE + 4; /* 4 bytes of FCS */

    /* Enable the CPPI port, i.e., port 0 that does all
     * the data streaming in/out of EMAC.
     */
    CSL_CPSW_nGF_enablePort0 ();
    CSL_CPSW_nGF_disableVlanAware ();
    CSL_CPSW_nGF_setPort0VlanReg (0, 0, 0);
    CSL_CPSW_nGF_setPort0RxMaxLen (rx_max_len);

    /* Enable statistics on both the port groups:
     *
     * MAC Sliver ports -   Port 1, Port 2
     * CPPI Port        -   Port 0
     */
    portStatCfg.p0AStatEnable   =   1;
    portStatCfg.p0BStatEnable   =   1;
    portStatCfg.p1StatEnable    =   1;
    portStatCfg.p2StatEnable    =   1;
    CSL_CPSW_nGF_setPortStatsEnableReg (&portStatCfg);

    /* Setup the Address Lookup Engine (ALE) Configuration:
     *      (1) Enable ALE.
     *      (2) Clear stale ALE entries.
     *      (3) Disable VLAN Aware lookups in ALE since
     *          we are not using VLANs by default.
     *      (4) No Flow control
     *      (5) Configure the Unknown VLAN processing
     *          properties for the switch, i.e., which
     *          ports to send the packets to.
     */
    CSL_CPSW_nGF_enableAle ();
    CSL_CPSW_nGF_clearAleTable ();
    CSL_CPSW_nGF_disableAleVlanAware ();
    CSL_CPSW_nGF_disableAleTxRateLimit ();

    /* Setting the Switch MTU Size to more than needed */
    CSL_CPGMAC_SL_setRxMaxLen(0, rx_max_len);
    CSL_CPGMAC_SL_setRxMaxLen(1, rx_max_len);

//#ifdef SIMULATOR_SUPPORT
    CSL_CPSW_nGF_enableAleBypass();
//#endif
    /* Done with switch configuration */
    return;
}


/** ============================================================================
 *   @n@b Switch_update_addr
 *
 *   @b Description
 *   @n This API add/delete entries in the Address Lookup Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n portNum         Switch port number.

 *   @param[in]
 *   @n macAddress      MAC address to configure on the switch.
 *
 *   @param[in]
 *   @n add             0:add; 1:delete.
 *
 *   @return
 *   @n None
 *
 *   @Note  It supports "add" operation only now.
 * =============================================================================
 */
int Switch_update_addr (uint32_t portNum, uint8_t macAddress[6], Uint16 add)
{
    CSL_CPSW_3GF_ALE_PORTCONTROL        alePortControlCfg;
#ifdef SIMULATOR_SUPPORT
    uint32_t                              i;
    CSL_CPSW_3GF_ALE_UNICASTADDR_ENTRY  ucastAddrCfg;
#endif


    /* Configure the address in "Learning"/"Forward" state */
    alePortControlCfg.portState             =   ALE_PORTSTATE_FORWARD;
    alePortControlCfg.dropUntaggedEnable    =   0;
    alePortControlCfg.vidIngressCheckEnable =   0;
    alePortControlCfg.noLearnModeEnable     =   0;
    alePortControlCfg.mcastLimit            =   0;
    alePortControlCfg.bcastLimit            =   0;

    CSL_CPSW_nGF_setAlePortControlReg (portNum, &alePortControlCfg);

#ifdef SIMULATOR_SUPPORT
    /* Program the ALE with the MAC address.
     *
     * The ALE entries determine the switch port to which any
     * matching received packet must be forwarded to.
     */
    /* Get the next free ALE entry to program */
    for (i = 0; i < CSL_CPSW_3GF_NUMALE_ENTRIES; i++)
    {
        if (CSL_CPSW_nGF_getALEEntryType (i) == ALE_ENTRYTYPE_FREE)
        {
            /* Found a free entry */
            break;
        }
    }
    if (i == CSL_CPSW_3GF_NUMALE_ENTRIES)
    {
        /* No free ALE entry found. return error. */
        return -1;
    }
    else
    {
        /* Found a free ALE entry to program our MAC address */
        memcpy (ucastAddrCfg.macAddress, macAddress, 6);    // Set the MAC address
        ucastAddrCfg.ucastType      =      ALE_UCASTTYPE_UCAST_NOAGE;   // Add a permanent unicast address entryALE_UCASTTYPE_UCAST_NOAGE.
        ucastAddrCfg.secureEnable   =      FALSE;
        ucastAddrCfg.blockEnable    =      FALSE;
        ucastAddrCfg.portNumber     =      portNum;   // Add the ALE entry for this port

        /* Setup the ALE entry for this port's MAC address */
        CSL_CPSW_nGF_setAleUnicastAddrEntry (i, &ucastAddrCfg);
    }
#endif
    /* Done with upading address */
    return 0;
}

/** ============================================================================
 *   @n@b Verify_Init
 *
 *   @b Description
 *   @n This API initializes the CPPI LLD, opens the PASS CPDMA and opens up
 *      the Tx, Rx channels required for data transfers.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Verify_Init (void)
{
    int32_t count, returnVal = 0, i;
    int32_t num_tx_desc = NIMU_NUM_TX_DESC;
    int32_t num_rx_desc = NIMU_NUM_RX_DESC;
    int32_t max_queue_number = QMSS_MAX_LOW_PRIORITY_QUEUE          +
                             QMSS_MAX_PASS_QUEUE                    +
                             QMSS_MAX_LOW_PRIORITY_QUEUE         	+
                             QMSS_MAX_PASS_QUEUE                 	+
                             QMSS_MAX_INTC_QUEUE                 	+
                             QMSS_MAX_SRIO_QUEUE                 	+
                             QMSS_MAX_HIGH_PRIORITY_QUEUE        	+
                             QMSS_MAX_STARVATION_COUNTER_QUEUE   	+
                             QMSS_MAX_INFRASTRUCTURE_QUEUE       	+
                             QMSS_MAX_TRAFFIC_SHAPING_QUEUE      	+
                             QMSS_MAX_GENERAL_PURPOSE_QUEUE      	;

    /*Verify if we got NIMU_NUM_TX_DESC Tx Free Q*/
    if ((count = Qmss_getQueueEntryCount (gTxFreeQHnd)) != num_tx_desc)  {
    	NIMU_drv_log3 ("Verify_Init: Expected %d entry count for gTxFreeQHnd queue %d, found %d entries\n", num_tx_desc, gTxFreeQHnd, count);
        returnVal =  -1;
    }

    /* Verify if we got NIMU_NUM_RX_DESC Rx FDQ */
    if ((count = Qmss_getQueueEntryCount (gRxFreeQHnd)) != num_rx_desc)  {
    	NIMU_drv_log3 ("Verify_Init: Expected %d entry count for gRxFreeQHnd queue %d, found %d entries\n", num_rx_desc, gRxFreeQHnd, count);
         returnVal = -1;
    }

    /* Verify if we got empty Tx completion Q*/
    if ((count = Qmss_getQueueEntryCount (gTxReturnQHnd)) != 0)  {
    	NIMU_drv_log2 ("Verify_Init: Expected 0 entry count for gTxReturnQHnd queue %d, found %d entries\n", gTxReturnQHnd, count);
        returnVal = -1;
    }

    /* Verify if we got NIMU_NUM_RX_DESC Rx FDQ */
    if ((count = Qmss_getQueueEntryCount (gRxQHnd)) != 0)  {
    	NIMU_drv_log2 ("Verify_Init: Expected 0 entry count for gRxQHnd= %d, found %d entries\n", gRxQHnd, count);
         returnVal = -1;
    }

    for (i = 0; i < max_queue_number; i++ ) {
        if ( (i == gRxFreeQHnd) || (i == gTxFreeQHnd) || (i == gTxCmdFreeQHnd))
            continue;

        count = Qmss_getQueueEntryCount (i);
        if (count != 0) {
            NIMU_drv_log2 ("Verify_Init: Expected 0 entry count for Queue number = %d, found %d entries\n", i, count);
        }
    }

    /* Verify_Init Done. Return success */
    return (returnVal);
}

/** ============================================================================
 *   @n@b Init_Cpsw
 *
 *   @b Description
 *   @n This API sets up the entire ethernet subsystem and all its associated
 *      components.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
int32_t Init_Cpsw (uint32_t mtu, uint8_t* myMACAddress)
{                      
#ifdef SIMULATOR_SUPPORT

    uint8_t bcMACAddress[6] = {0xff,0xff,0xff,0xff,0xff,0xff};
    extern  uint8_t clientMACAddress [6];

    /* Initialize the SGMII/Sliver submodules for the MAC port. */
    Init_SGMII (0);
    Init_MAC (0, myMACAddress, mtu);

    Init_SGMII (1);
    Init_MAC (1, myMACAddress, mtu);

    /* Setup the Ethernet switch finally. */
    Init_Switch (mtu);


   /* Update the ALE Entries and ensure that these are correctly configured.
    * There are 2 Entries created here:
    *  Entry1: My OWN MAC Address goes to Port 0
    *  Entry2: Destination MAC Address is forwarded to Port1
    * If there are more destination MAC Addresses to which packets need to be sent
    * than additional entries need to be configured. */

   /* This is needed only for testing in Simulator*/
   Switch_update_addr(0, myMACAddress, 0);
   Switch_update_addr(1, clientMACAddress, 0);
   Switch_update_addr(1, myMACAddress, 0);  // testing a hybrid between cooked up ping and the original app (cooked up raw message)

   // checking out if adding bc message still work for unicast
   Switch_update_addr(1, bcMACAddress, 0);     // verified needed for BCAST tx

   // add this to see if BC packet response can come into the PA
   Switch_update_addr(0, bcMACAddress, 0);     // verfied needed for BCast Rx

#else

    uint32_t  i;
    uint8_t   backplaneMac[6] = {0x1, 0x1, 0x1, 0x1, 0x1, 0x1}; /* Mask for creating mac address by flipping LSB */
    uint8_t   cppiMac [6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};  /* MAC address for (CPPI) Port 0 - we made it up*/


	/* we need to create a mac address for the Backplane Ethernet port
	 * using the Ethernet MAC Adress
	 */
    for (i=0; i < 6; i++) {
        backplaneMac[i] |= myMACAddress[i];
    }
	Init_MAC (0, backplaneMac, mtu);

	/* set the silver port to the stacks ethernet address */
	Init_MAC (1, myMACAddress, mtu);

    /* Setup the Phys by initializing the MDIO - not needed for Simulator*/
    Init_MDIO ();

    /* Setup the Ethernet switch finally. */
    Init_Switch (mtu);

    /* This is a little confusing but different APIs use different numbering */
    Switch_update_addr(0, cppiMac, 0);
    Switch_update_addr(1, backplaneMac, 0);
    Switch_update_addr(2, myMACAddress, 0);
#endif

    /* CPSW subsystem setup done. Return success */
    return 0;
}

/* ============================================================================
 *   @n@b Init_PASS
 *
 *   @b Description
 *   @n This API initializes the PASS/PDSP and opens a queue that the application
 *      can use to receive command responses from the PASS.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Init_PASS (void)
{
    uint8_t			isAllocated;

    /* Open a PA Command Response Queue.
     *
     * This queue will be used to hold responses from the PA PDSP for all the
     * commands issued by NIMU.
     *
     * This queue is used only when configuring the PA PDSP. We will use it when adding our mac address.
     */
    if ((gPaCfgCmdRespQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
    	NIMU_drv_log ("Error opening a PA Command Response queue \n");
        return -1;
    }

    /* Init done. Return success. */
    return 0;
}


/** ============================================================================
 *   @n@b Add_MACAddress
 *
 *   @b Description
 *   @n This API adds the switch MAC address to the PA PDSP Lookup table. This
 *      ensures that all packets destined for this MAC address get processed
 *      for forwarding to the host.
 *
 *   @param[in]
 *   @n ethInfo         Pointer to PA Ethernet Info table.
 *
 *   @param[in]
 *   @n routeInfo       Pointer to PA Route Info table.
 *
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t 
Add_MACAddress 
(
    paEthInfo_t         *ethInfo, 
    paRouteInfo_t       *routeInfo
)
{
    int32_t              j;
    uint16_t			cmdSize;
    Qmss_Queue          cmdReplyQInfo;

    paRouteInfo_t       nFailInfo =     {   pa_DEST_DISCARD,                            /* Toss the packet  */
                                                    0,                                          /* Flow Id = dont care */
                                                    0,                                          /* queue = dont care */
                                                    0,                                          /* mutli route = dont care */
                                                    0,                                          /* swinfo0 = dont care */
                                                    0,                                          /* swinfo1 = dont care */
                                                    0,                                          /* customType = pa_CUSTOM_TYPE_NONE */         \
                                                    0,                                          /* customIndex: not used */        \
                                                    0,                                          /* pkyType: for SRIO only */       \
                                                    NULL                                        /* No commands */
                                                };
    paCmdReply_t        cmdReplyInfo =  {   pa_DEST_HOST,                               /* Replies go to the host */
                                                    0,                                          /* User chosen ID to go to swinfo0 */
                                                    0,                                          /* Destination queue */
                                                    0                                           /* Flow ID */
                                                };
    paReturn_t          retVal;
    paEntryHandle_t     retHandle;
    int32_t				handleType, cmdDest;
    uint32_t            psCmd       =   ((uint32_t)(4 << 5) << 24);
    uint32_t            myswinfo[]  =   {0x11112222, 0x33334444};
    uint32_t            myswinfo_orig[] =   {0x00000000, 0x00000000, 0x00000000};;
    uint8_t*            pCmdDataBuffer;
    Cppi_HostDesc*      pHostDesc = NULL;
    Qmss_Queue          rxQInfo;
    uint32_t            count, cmdbuf_len = 320;
    int32_t             ret_val = 0;

    /* Get a Tx free descriptor to send a command to the PA PDSP */
    if ((NIMU_qmssQPop (gTxCmdFreeQHnd, QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pHostDesc )) == -1)
    {
    	NIMU_drv_log ("Error obtaining a Tx free descriptor \n");
        return -1;
    }

    /* Allocate a Tx buffer and attach the command info to it. */
    cmdbuf_len = NIMU_roundUp(cmdbuf_len, CACHE_LINESZ);
    if ((pCmdDataBuffer = (Ptr) Osal_nimuMalloc (cmdbuf_len, CACHE_LINESZ)) == NULL)
    {
    	NIMU_drv_log ("Error allocating memory for PA Command data buffer \n");
        return -1;
    }

    /* Populate the Tx free descriptor with the buffer we just allocated. */
    Cppi_setData (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, (uint8_t *)NIMU_convertCoreLocal2GlobalAddr((uint32_t)pCmdDataBuffer), cmdbuf_len);

    /* Save original buffer information */
    Cppi_setOriginalBufInfo (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, (uint8_t *)NIMU_convertCoreLocal2GlobalAddr((uint32_t)pCmdDataBuffer), cmdbuf_len);

    cmdSize                 =   pHostDesc->buffLen;
    cmdReplyInfo.replyId    =   0x11111111;  /* unique for each add mac command */

    /* Get the PA response queue number and populate the destination queue number
     * in the PA response configuration.
     */
    cmdReplyQInfo           =   Qmss_getQueueNumber (gPaCfgCmdRespQHnd);
    cmdReplyInfo.queue      =   cmdReplyQInfo.qNum;

    /* Setup the Rx queue as destination for the packets */
    rxQInfo                 =   Qmss_getQueueNumber (gRxQHnd);
    routeInfo->queue        =   rxQInfo.qNum;

    retVal  =   Pa_addMac  (NIMU_getPAInstance(),
                            pa_LUT1_INDEX_NOT_SPECIFIED,
                            ethInfo,
                            routeInfo,
                            &nFailInfo,
                            &gPaL2Handles[0],
                            (paCmd_t) pHostDesc->buffPtr,
                            &cmdSize,
                            &cmdReplyInfo,
                            &cmdDest);
    if (retVal != pa_OK)
    {
    	NIMU_drv_log1 ("Pa_addMac returned error %d\n", retVal);
        ret_val = -1;
        goto return_fail;
    }


    /* This sets the extended info for descriptors, and this is required so PS info
     * goes to the right spot
     */
    Cppi_setSoftwareInfo (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, (uint8_t *)myswinfo);

    /* Set the buffer length to the size used. It will be restored when the descriptor
     * is returned
     */
    Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, cmdSize);
    pHostDesc->buffLen  =   cmdSize;

    /* Mark the packet as a configuration packet */
    Cppi_setPSData (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, (uint8_t *)&psCmd, 4);

    /* Send the command to the PA and wait for the return */
    NIMU_qmssQPush    (gPaTxQHnd[cmdDest - pa_CMD_TX_DEST_0],
                    pHostDesc,
                    pHostDesc->buffLen,
                    SIZE_HOST_DESC,
                    Qmss_Location_TAIL
                   );

    /* Poll on the PA response queue to see if response from PA has come */
    for (j = 0; j < 100; j++)
    {
        CycleDelay (1000);

        /* Verify if we got empty Tx completion Q*/
        count = Qmss_getQueueEntryCount (gTxCmdReturnQHnd);

        if (count != 0)  {

            if ((NIMU_qmssQPop (gTxCmdReturnQHnd, QHANDLER_QPOP_FDQ_ATTACHEDBUF, (Cppi_HostDesc **)&pHostDesc)) == -1)
            {
                ret_val = -1;
                goto return_fail;
            }

            /* Restore the states */
            Cppi_setSoftwareInfo(Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, (uint8_t *)myswinfo_orig);
            Cppi_setPSData (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, NULL, NULL);
            Cppi_setData (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, NULL, NULL);
            Cppi_setOriginalBufInfo (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, NULL, NULL);
            Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, NULL);
            pHostDesc->buffLen = 0;

            NIMU_qmssQPushDescSize (gTxCmdFreeQHnd, pHostDesc, SIZE_HOST_DESC);
        }

        if (Qmss_getQueueEntryCount (gPaCfgCmdRespQHnd) > 0)
        {

            /* We have a response from PA PDSP for the command we submitted earlier for
             * MAC address addition.
             */
            if ((NIMU_qmssQPop (gPaCfgCmdRespQHnd, QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF, (Cppi_HostDesc **)&pHostDesc)) == -1)
            {
                ret_val = -1;
                goto return_fail;
            }

            if (pHostDesc->softwareInfo0 != cmdReplyInfo.replyId)
            {
                pHostDesc->buffLen  =   pHostDesc->origBufferLen;
                NIMU_qmssQPush (gTxCmdFreeQHnd, pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
                ret_val = -1;
                goto return_fail;

            }

            retVal  =   Pa_forwardResult (NIMU_getPAInstance(), (Ptr)pHostDesc->buffPtr, &retHandle, &handleType, &cmdDest);
            if (retVal != pa_OK)
            {
                NIMU_drv_log ("PA sub-system rejected Pa_addMac command\n");
                ret_val = -1;
                goto return_fail;
            }

            /* Reset the buffer length and put the descriptor back on the Rx free queue */
            pHostDesc->buffLen = pHostDesc->origBufferLen;
            NIMU_qmssQPush (gRxFreeQHnd, pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
            break;
        }
    }

    if (j == 100)
    {
    	NIMU_drv_log ("Timeout waiting for reply from PA to Pa_addMac command\n");
        ret_val = -1;
    }

return_fail:

	Osal_nimuFree (pCmdDataBuffer, cmdbuf_len);

    return (ret_val);
}



/**
 *  @b Description
 *  @n
 *      Returns the number of received packet drops, most likely due to NDK buffer starvation.
 *
 *  @retval
 *      None.
 */
uint32_t nimu_getrxdrops(void) {
	return  gRxDropCounter;
}

/**
 *  @b Description
 *  @n
 *      Returns the number of transmit packet drops due to Tx descriptor starvation.
 *
 *  @retval
 *      None.
 */
uint32_t nimu_gettxdrops(void) {
	return  gTxDropCounter;
}


#ifdef TIMING
/*
 * Routine to print out timing measurements.. meant to be called from application as we dont
 * want to print in an interrupt context.
 */
void print_nimu_timing(void) {
	uint32_t	avg_rxisr, avg_txisr, max_rxisr, min_rxisr, max_txisr, min_txisr;
	uint32_t	total_rx, total_tx;
	uint32_t	i, x, n;
    void*       key;

    /* Begin Critical Section before accessing shared resources. */
    key = Osal_qmssCsEnter ();

	/* Calculate min, max, avg times for display */
	avg_rxisr = 0;
	avg_txisr = 0;
	max_rxisr = 0;
	min_rxisr = (uint32_t) (rxisr_time[0]); /* seed the value */
	max_txisr = 0;
	min_txisr = (uint32_t) (txisr_time[0]);	/* seed the value */
	total_rx  = 0;
	total_tx  = 0;

	for (i=0, n=0; i < MAX_TIMING_PACKETS; i++) {

		x = (uint32_t) (rxisr_time[i]);

		if (rxisr_time[i] != 0) {
			n++;
			if (min_rxisr > x) {
				min_rxisr = x;
			}

			if ( max_rxisr < x) {
				max_rxisr = x;
			}
			total_rx += x;
		}

		x = (uint32_t) (txisr_time[i]);

		if (txisr_time[i] != 0) {
			if ( min_txisr > x && x > 0) {
				min_txisr = x;
			}
			if ( max_txisr < x) {
				max_txisr = x;
			}
			total_tx += x;
		}
	}
	/* End Critical Section */
    Osal_qmssCsExit (key);

	avg_rxisr = total_rx / n;		/* have to avg over number of times it was called */
	avg_txisr = total_tx / MAX_TIMING_PACKETS;

	NIMU_drv_log5("NIMU Rx (%d Packets): Total = %d Min = %d Max = %d Avg = %d \n", MAX_TIMING_PACKETS, total_rx, min_rxisr, max_rxisr, avg_rxisr);
	NIMU_drv_log5("NIMU Tx (%d Packets): Total = %d Min = %d Max = %d Avg = %d \n", MAX_TIMING_PACKETS, total_tx, min_txisr, max_txisr, avg_txisr);


}

/* reset timing counters */
void reset_nimu_timing(void) {
    void*   key;

    /* Begin Critical Section before accessing shared resources. */
    key = Osal_qmssCsEnter ();

	memset (&rxisr_time[0], 0, MAX_TIMING_PACKETS);
	memset (&txisr_time[0], 0, MAX_TIMING_PACKETS);

	rxisr_time_idx = 0; txisr_time_idx = 0;
	rxisr_pktcount = 0;

    /* End Critical Section */
    Osal_qmssCsExit (key);
}

#endif


/* Nothing past this point */

