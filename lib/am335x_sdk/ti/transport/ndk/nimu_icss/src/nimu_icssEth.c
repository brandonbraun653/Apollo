/**
 *   @file nimu_icssEth.c
 *   @brief
 *      Implements NDK NIMU transport driver interface for ICSS
 */

/* Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ti/transport/ndk/nimu_icss/nimu_icssEth.h"
#include "ti/transport/ndk/nimu_icss/src/nimu_icssEthDriver.h"
#include "ti/drv/icss_emac/icss_emacFwInit.h"

extern void* OSDRV_getNetifHandle(uint32_t inst);


#define NIMU_ICSS_EMAC_MAX_TBL_ENTRIES   4
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** @brief variable to hold the status of ndk driver */
static uint32_t nimuDeviceStat[NIMU_ICSS_EMAC_MAX_TBL_ENTRIES] = {NIMU_STAT_UNKNOWN};
static uint32_t nimuIcssEmacInstNum=0;
uint8_t nimuIcssEmacIfMac[] = { 0x00, 0x31, 0xDE, 0x00, 0x00, 0x00};
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 * @brief NIMU_IcssData
 *
 * @details
 *  The structure is used to store the private data for the
 *  EMAC controller.
 */
typedef struct NIMU_IcssData_s
{
    NIMU_IcssPdInfo      pdi; /**< Structure for NIMU_IcssPdInfo(private info) */
}NIMU_IcssData;

/**
* @internal
* @brief  The function is used to initialize and start the EMAC
*  controller and device.
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer.
*
* @retval Success -   0
*         Error   -   <0
*/
int_fast32_t NIMU_ICSS_start (NETIF_DEVICE* pNetDevice); /* misra warning */
int_fast32_t NIMU_ICSS_start (NETIF_DEVICE* pNetDevice)
{
    int32_t retVal;
    NIMU_IcssData*  pNimuIcssEmacPrivData;
    uint32_t index;
    /* Get the pointer to the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData *)pNetDevice->pvt_data;
    index = pNimuIcssEmacPrivData->pdi.PhysIdx;

    nimuDeviceStat[index] = NIMU_STAT_PROGRESS;
    /* Call low-level open function */
    if (NIMU_ICSS_open(&pNimuIcssEmacPrivData->pdi) == 0)
    {
        /* Copy the MAC Address into the network interface object here. */
        mmCopy((void*)(&pNetDevice->mac_address[0]), (void*)(&pNimuIcssEmacPrivData->pdi.bMacAddr[0]), 6U);

        /* Set the 'initial' Receive Filter */
        pNimuIcssEmacPrivData->pdi.Filter = ETH_PKTFLT_ALL;

        /* Inform the world that we are operational. */
        nimuDeviceStat[index] = NIMU_STAT_UP;
        retVal = 0;
    }
    else
    {
        nimuDeviceStat[index] = NIMU_STAT_DOWN;
        retVal = -1;
    }
    /* Error: EMAC failed to start. */
    return (retVal);
}


/**
* @internal
* @brief  The function is used to de-initialize and stop the EMAC
*  controller and device.
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer.
*
* @retval Success -   0
*         Error   -   <0
*/
static int_fast32_t NIMU_ICSS_stop (NETIF_DEVICE* pNetDevice); /* misra warning */
static int_fast32_t NIMU_ICSS_stop (NETIF_DEVICE* pNetDevice)
{
    NIMU_IcssData*  pNimuIcssEmacPrivData;
    uint8_t index;
    /* Get the pointer to the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData *)pNetDevice->pvt_data;
    index = pNimuIcssEmacPrivData->pdi.PhysIdx;

    /* Call low-level close function */
    NIMU_ICSS_close (&pNimuIcssEmacPrivData->pdi);

    /* Flush out our pending queue */
    while(PBMQ_count(&pNimuIcssEmacPrivData->pdi.PBMQ_rx))
    {
        PBM_free( PBMQ_deq(&pNimuIcssEmacPrivData->pdi.PBMQ_rx) );
    }
    nimuDeviceStat[index] = NIMU_STAT_DOWN;

    nimuIcssEmacInstNum--;
    /* EMAC Controller has been stopped. */
    return 0;
}


/**
* @internal
* @brief  The function is used to poll the EMAC controller to check
*  if there has been any activity
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer
* @param[in]  timer_tick Flag to poll the driver.
*
* @retval none
*/
static void NIMU_ICSS_poll (NETIF_DEVICE* pNetDevice, uint32_t timer_tick); /* misra warning */
static void NIMU_ICSS_poll (NETIF_DEVICE* pNetDevice, uint32_t timer_tick)
{
    NIMU_IcssData*  pNimuIcssEmacPrivData;

    /* Get the pointer to the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData *)pNetDevice->pvt_data;

    /* Poll the driver. */
    NIMU_ICSS_pktPoll (&pNimuIcssEmacPrivData->pdi, (uint32_t)timer_tick);

    return;
}


/**
* @internal
* @brief  The function is the interface routine invoked by the NDK stack to
*  pass packets to the driver
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer
* @param[in]  hPkt Packet to be sent out on wire.
*
* @retval Success -   0
*         Error   -   <0
*/
static int_fast32_t NIMU_ICSS_send (NETIF_DEVICE* pNetDevice, PBM_Handle hPkt); /* misra warning */
static int_fast32_t NIMU_ICSS_send (NETIF_DEVICE* pNetDevice, PBM_Handle hPkt)
{
    NIMU_IcssData*  pNimuIcssEmacPrivData;

    /* Get the pointer to the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData *)pNetDevice->pvt_data;

    /* Make sure the driver does not transmit packet less than min. as per the
     * Ethernet standards. */
    if( PBM_getValidLen(hPkt) < ((uint32_t)60U))
    {
        PBM_setValidLen (hPkt, ((uint32_t)60U));
    }
    /* We do not do any packet size checks here. If the packet
     * is too big to fit in the MTU configured on the peripheral,
     * then the driver/CSL layer catches the error.
     */
    /* Enqueue the packet and send it for transmission. */
    PBMQ_enq (&pNimuIcssEmacPrivData->pdi.PBMQ_tx, hPkt);

    /* Pass the packet to the controller if the transmitter is free. */
    if(pNimuIcssEmacPrivData->pdi.TxFree )
    {
        NIMU_ICSS_pktTxNext(&pNimuIcssEmacPrivData->pdi);
    }

    /* Packet has been successfully transmitted. */
    return 0;
}

/**
* @internal
* @brief  The function is called by the NDK core stack to receive any packets
*  from the driver
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer
*
* @retval none
*/
static void NIMU_ICSS_pktService (NETIF_DEVICE* pNetDevice); /* misra warning */
static void NIMU_ICSS_pktService (NETIF_DEVICE* pNetDevice)
{
    NIMU_IcssData*  pNimuIcssEmacPrivData;
    PBM_Handle          hPacket;
    
    /* Get the pointer to the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData *)pNetDevice->pvt_data;

    /* Give all queued packets to the Ether module */
    while (PBMQ_count(&pNimuIcssEmacPrivData->pdi.PBMQ_rx))
    {    
        
        /* Dequeue a packet from the driver receive queue. */
        hPacket = PBMQ_deq(&pNimuIcssEmacPrivData->pdi.PBMQ_rx);

        /* Prepare the packet so that it can be passed up the networking stack.
         * If this 'step' is not done the fields in the packet are not correct
         * and the packet will eventually be dropped.  */
        PBM_setIFRx (hPacket, pNetDevice);

        /* Pass the packet to the NDK Core stack. */
        NIMUReceivePacket(hPacket);
    }

    /* Work has been completed; the receive queue is empty... */
    return;
}

/**
* @internal
* @brief  The function is called by the NDK core stack to configure the
*   the driver
*
* @param[in] pNetDevice NETIF_DEVICE structure pointer
* @param[in]  cmd Ioctl command
* @param[in]  pBuf Mac address to be added or deleted
* @param[in]  size Size of Mac Address
*
* @retval Success -   0
*         Error   -   <0
*/
static int_fast32_t NIMU_ICSS_ioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size); /* misra warning */
static int_fast32_t NIMU_ICSS_ioctl (NETIF_DEVICE* ptr_net_device, uint32_t cmd, void* pBuf, uint32_t size)
{
    NIMU_IcssData*  ptr_pvt_data;
    int_fast32_t retVal;

    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_IcssData *)ptr_net_device->pvt_data;

    /* call the switch driver's Ioctl handler to take care of this. */
    retVal = NIMU_ICSS_pktIoctl(&ptr_pvt_data->pdi, cmd, pBuf, size);
    return (retVal);

}


/**
* @brief The EMAC Initialization Function
* @details The function is used to initialize and register the EMAC
*  with the Network Interface Management Unit (NIMU)
*
* @internal
*
* @param[in]  hEvent Stack Event Handle.
*
* @retval Success -   0
*         Error   -   <0
*/
int32_t NIMU_ICSS_EmacInit (STKEVENT_Handle hEvent)
{
    int32_t retVal = 0;
    NIMU_IcssData*      pNimuIcssEmacPrivData;
    NETIF_DEVICE*   pNimuIcssEmacDevice;
    int_fast32_t             hdrSize, trailSize;
    uint32_t           j;

    /* Allocate memory for the private data */
    pNimuIcssEmacPrivData = (NIMU_IcssData*)mmAlloc(sizeof(NIMU_IcssData));
    if (pNimuIcssEmacPrivData == NULL)
    {
        retVal = -1;
    }
    else
    {
        /* Initialize the allocated memory block. */
        mmZeroInit (pNimuIcssEmacPrivData, sizeof(NIMU_IcssData));
    
        /* Initialize the RX Queue */
        PBMQ_init(&pNimuIcssEmacPrivData->pdi.PBMQ_rx);

        /* Initialize the private data */
        mmZeroInit(&pNimuIcssEmacPrivData->pdi, sizeof(NIMU_IcssPdInfo));
    
        /* Set physical index */
        pNimuIcssEmacPrivData->pdi.PhysIdx = nimuIcssEmacInstNum;
        pNimuIcssEmacPrivData->pdi.hEvent  = hEvent;
        pNimuIcssEmacPrivData->pdi.nimuDrvHandle = (ICSS_EmacHandle)(OSDRV_getNetifHandle(nimuIcssEmacInstNum));

        for (j=0U; j<6U; j++)
        {
            pNimuIcssEmacPrivData->pdi.bMacAddr[j] = nimuIcssEmacIfMac[j];
        }
    
        /* Init Logical Device */
        /* pNimuIcssEmacPrivData->pdi.hEther = hEther; */
    
        /* Allocate memory for the EMAC. */
        pNimuIcssEmacDevice = (NETIF_DEVICE*)mmAlloc(sizeof(NETIF_DEVICE));
        if (pNimuIcssEmacDevice == NULL)
        {
             retVal = -1;
        }
        else
        {
            /* Initialize the allocated memory block. */
            mmZeroInit (pNimuIcssEmacDevice, sizeof(NETIF_DEVICE));

            /* Populate the Network Interface Object. */
            if(nimuIcssEmacInstNum)
            {
                strcpy (pNimuIcssEmacDevice->name, "eth1");
            }
            else
            {
                strcpy (pNimuIcssEmacDevice->name, "eth0");
            }
            pNimuIcssEmacDevice->mtu         = ETH_MAX_PAYLOAD - ETHHDR_SIZE;
            pNimuIcssEmacDevice->pvt_data    = (void *)pNimuIcssEmacPrivData;
        
            /* Populate the Driver Interface Functions. */
            pNimuIcssEmacDevice->start       = &NIMU_ICSS_start;
            pNimuIcssEmacDevice->stop        = &NIMU_ICSS_stop;
            pNimuIcssEmacDevice->poll        = &NIMU_ICSS_poll;
            pNimuIcssEmacDevice->send        = &NIMU_ICSS_send;
            pNimuIcssEmacDevice->pkt_service = &NIMU_ICSS_pktService;
            pNimuIcssEmacDevice->ioctl       = &NIMU_ICSS_ioctl;
            pNimuIcssEmacDevice->add_header  = &NIMUAddEthernetHeader;
        
        
            nimuIcssEmacInstNum++;
        
            /* Register the device with NIMU */
            if (NIMURegister (pNimuIcssEmacDevice) < 0)
            {
                retVal = -1;
            }
            else
            {
                NIMUGetRsvdSizeInfo(&hdrSize, &trailSize);    /* FW usual result is 20 which is 6 more than normal header offset */
                hdrSize = 0;                                /*set to allow 32 bit aligned buffers */
                NIMUSetRsvdSizeInfo(hdrSize, trailSize);
            }
        }
    }
    return retVal;

}

/**
* @brief The function is used to get the status of ndk driver
*
* @param[in]  instID Stack Driver instance(0 in the implementation)
*
* @retval ndk driver status
*/
uint32_t NIMU_ICSS_getNdkStatus(uint8_t instID)
{
    return nimuDeviceStat[instID];
}

