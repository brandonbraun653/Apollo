/**
 *   @file  nimu_eth.c
 *   @brief
 *     nimu implementation for AM65xx/j721e SOC
 */

/* Copyright (C) {2018-2019} Texas Instruments Incorporated - http://www.ti.com/ 
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
#include <string.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>

#include <ti/drv/udma/udma.h>
#include <ti/osal/osal.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>

#include <ti/transport/ndk/nimu/src/v7/nimu_eth.h>
#include <ti/transport/ndk/nimu/src/NIMU_drv_log.h>
#include <ti/transport/ndk/nimu/src/nimu_osal.h>

#ifdef NIMU_ICSSG
/* PRUSS Driver Header File. */
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
/* DUAL MAC Firmware headers */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii0_bin.h>      /* PDSPcode */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test0_bin.h>             /* PDSP2code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii1_bin.h>      /*PDSP3code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test1_bin.h>             /* PDSP4code */
#include <ti/drv/emac/firmware/icss_dualmac/config/emac_fw_config_dual_mac.h>

/* PRUSS driver handle */
PRUICSS_Handle prussHandle[3] = {NULL, NULL, NULL};

static NIMU_PruRtuFw firmware[2] = {
    { PDSPcode_0, sizeof(PDSPcode_0), PDSP2code_0, sizeof(PDSP2code_0) },
    { PDSP3code_0, sizeof(PDSP3code_0), PDSP4code_0, sizeof(PDSP4code_0) },
};

int32_t nimu_init_pruicss(uint32_t portNum);
int32_t nimu_disable_pruicss(uint32_t portNum);
#endif

extern Udma_DrvHandle nimu_app_get_udma_handle(void);
extern void Osal_TaskCreate_v2(void* pCbFn, uint32_t arg);
extern void* Osal_malloc(uint32_t  num_bytes);
extern void Osal_free(void*       ptr, uint32_t      num_bytes);
extern void Osal_TaskSleep(uint32_t sleepTime);

#define NIMU_CPSW_PORT_NUM ((uint32_t)6U)
#define NIMU_PORT_NAME_LEN ((uint32_t)5U)

#define     NIMU_PKT_MTU_DEFAULT             1518

/* Used to indicate that descriptor is being used during packet TX */
#define NIMU_TX_PKT_DESC ((uint32_t)1U)

/* Number of emac interface instantiated */
static uint32_t gNumEmacInterfaces = 0U;

NETIF_DEVICE   ptr_device[NIMU_NUM_EMAC_PORTS];

static NIMU_PdInfo* pPDI[NIMU_NUM_EMAC_PORTS]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


static int_fast32_t nimu_pkt_tx_next( NIMU_PdInfo *pi );
int32_t nimu_pkt_ioctl(NIMU_PdInfo *pi, uint32_t cmd, void* param, uint32_t size);
static EMAC_PKT_DESC_T* nimu_alloc_pkt(uint32_t port_num, uint32_t pkt_size);
static void nimu_free_pkt(uint32_t port_num,EMAC_PKT_DESC_T*    p_pkt_desc);
static void  nimu_rx_pkt_cb (uint32_t port_num, EMAC_PKT_DESC_T*     p_desc);
static void nimu_addr_get(uint32_t addrIdx, NIMU_MacAddr *p);

/* The NIMU Initialization Functions. */
int32_t NimuEmacInit(uint32_t portNum, STKEVENT_Handle hEvent);

int32_t NimuEmacInitP0(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP1(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP2(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP3(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP4(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP5(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP6(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP7(STKEVENT_Handle hEvent);
int32_t NimuEmacInitP8(STKEVENT_Handle hEvent);

int32_t (*NimuEmacInitFxn[NIMU_NUM_EMAC_PORTS ])(STKEVENT_Handle hEvent) =
{
    NimuEmacInitP0,
    NimuEmacInitP1,
    NimuEmacInitP2,
    NimuEmacInitP3,
    NimuEmacInitP4,
    NimuEmacInitP5,
    NimuEmacInitP6,
    NimuEmacInitP7,
    NimuEmacInitP8
};

/**
 * @brief
 *   NIMU_EMAC_DATA
 *
 * @details
 *  The structure is used to store the private data for the
 *  NIMU  controller.
 */
typedef struct NIMU_EMAC_DATA_s
{
/**
  * @brief   Private Information
  */
    NIMU_PdInfo      pdi;
}NIMU_EMAC_DATA;

volatile int32_t nimuPollLoop = 1U;

static void nimu_task_poll_pkt (uint32_t arg0, uint32_t arg1); /* misra warning */
static void nimu_task_poll_pkt (uint32_t arg0, uint32_t arg1)
{
    uint32_t pollStatus;
    uint32_t portNum = (uint32_t) arg0;
    (void)arg1;
    while (nimuPollLoop == 1U)
    {
        /* If poll pkt returns error, then port is down, re-check after sleep period */
        pollStatus = emac_poll_pkt(portNum);
        if (pollStatus != 0U)
        {
            Osal_TaskSleep(1);
        }
    }
}

#ifdef NIMU_ICSSG
static void nimu_task_poll_ctrl (uint32_t arg0, uint32_t arg1)
{
    uint32_t portNum = (uint32_t) arg0;
    (void)arg1;
    while (nimuPollLoop == 1U)
    {
        /* Poll for EMAC_POLL_RX_MGMT_RING2 for mgmt responses from FW */
        emac_poll_ctrl(portNum, 0, EMAC_POLL_RX_MGMT_RING2, EMAC_POLL_TX_COMPLETION_RING1);
        Osal_TaskSleep(100);
    }
}
#endif

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
    NIMU_EMAC_DATA*  ptr_pvt_data;
    EMAC_HwAttrs_V5 emac_cfg;
    int32_t retVal = 0;
    uint32_t port_num;

#ifdef NIMU_ICSSG
    PRUICSS_Config *prussCfg;
#endif
    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;

    port_num = ptr_pvt_data->pdi.portNum;
#ifdef NIMU_ICSSG
    PRUICSS_socGetInitCfg(&prussCfg);

    switch( port_num)
     {
        case 0:
        case 1:
            prussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg, PRUICCSS_INSTANCE_ONE);
            nimu_disable_pruicss(port_num);
            break;
        case 2:
        case 3:
            prussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg, PRUICCSS_INSTANCE_TWO);
            nimu_disable_pruicss(port_num);
            break;
        case 4:
        case 5:
            prussHandle[2] =  PRUICSS_create((PRUICSS_Config*)prussCfg, PRUICCSS_INSTANCE_MAX);
            nimu_disable_pruicss(port_num);
            break;
        default:
            break;
     }
#endif
    pPDI[port_num] = &(ptr_pvt_data->pdi);
    /* Wait for link to come up */
#if defined(SOC_J721E) /// if it is J721E simluator then set txTree to 1    
    ptr_pvt_data->pdi.txFree = 1U;
#else
    ptr_pvt_data->pdi.txFree = 0U;
#endif
    /* Copy the MAC Address into the network interface object here. */
    mmCopy((void*)(&ptr_net_device->mac_address[0]), (void*)(&ptr_pvt_data->pdi.bMacAddr[0]), 6U);

    /* Set the 'initial' Receive Filter */
    ptr_pvt_data->pdi.rxFilter = ETH_PKTFLT_ALL;

    memset(&open_cfg, 0, sizeof(EMAC_OPEN_CONFIG_INFO_T));
    EMAC_socGetInitCfg(0, &emac_cfg);
    open_cfg.udmaHandle = nimu_app_get_udma_handle();
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
    open_cfg.phy_addr = 0;
    open_cfg.mode_of_operation = EMAC_MODE_INTERRUPT;

    chan_cfg[0].p_mac_addr = (EMAC_MAC_ADDR_T*)&ptr_pvt_data->pdi.bMacAddr[0];

    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;
    open_cfg.p_chan_mac_addr = &chan_cfg[0];

    if ((port_num % 2) == 0)
        open_cfg.phy_addr = 0;
    else
        open_cfg.phy_addr = 3;

    if ((emac_open(port_num, &open_cfg)) != EMAC_DRV_RESULT_OK)
    {
        NIMU_drv_log("EMACInit_Core failed\n");
        retVal = -1;
    }
    else
    {
#ifdef NIMU_ICSSG
        nimu_init_pruicss(port_num);
#endif
        Osal_TaskCreate_v2((void*)nimu_task_poll_pkt, port_num);
#ifdef NIMU_ICSSG
        Osal_TaskCreate_v2((void*)nimu_task_poll_ctrl, port_num);
#endif

        NIMU_drv_log ("EMAC has been started successfully\n");
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
    NIMU_EMAC_DATA*  ptr_pvt_data;
    EMAC_DRV_ERR_E closeRetVal;
    uint32_t count;
    
    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;

    closeRetVal = emac_close(ptr_pvt_data->pdi.portNum);
    if( closeRetVal == EMAC_DRV_RESULT_CLOSE_PORT_ERR )
    {
        NIMU_drv_log1("EMAC Close Returned error %08x\n",closeRetVal);
    }

   /* Flush out our pending queue */
    count = PBMQ_count(&ptr_pvt_data->pdi.PBMQRx);
    while(count)
    {
        PBM_free( PBMQ_deq(&ptr_pvt_data->pdi.PBMQRx) );
        count = PBMQ_count(&ptr_pvt_data->pdi.PBMQRx);
    }
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
    NIMU_EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data  to poll specified port */
    if(timer_tick)
    {
        ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;
        memset(&info,0, sizeof(EMAC_LINK_INFO_T));
        emac_poll(ptr_pvt_data->pdi.portNum, &info);
        if(info.link_status != EMAC_LINKSTATUS_NOLINK)
        {
            ptr_pvt_data->pdi.txFree =1;
            nimu_pkt_tx_next(&ptr_pvt_data->pdi);
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
    NIMU_EMAC_DATA*  ptr_pvt_data;

    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;

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

     if(ptr_pvt_data->pdi.txFree )
     {
        /* Enqueue the packet and send it for transmission. */
        PBMQ_enq (&ptr_pvt_data->pdi.PBMQTx, hPkt);

        /* Pass the packet to the controller if the transmitter is free. */
        nimu_pkt_tx_next(&ptr_pvt_data->pdi);
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
    NIMU_EMAC_DATA*  ptr_pvt_data;
    PBM_Handle          hPacket;

    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;

    /* Give all queued packets to the Ether module */
    while (PBMQ_count(&ptr_pvt_data->pdi.PBMQRx))
    {

        /* Dequeue a packet from the driver receive queue. */
        hPacket = PBMQ_deq(&ptr_pvt_data->pdi.PBMQRx);

        /* Prepare the packet so that it can be passed up the networking stack.
         * If this 'step' is not done the fields in the packet are not correct
         * and the packet will eventually be dropped.  */
        PBM_setIFRx (hPacket, ptr_net_device);

        /* Pass the packet to the NDK Core stack. */
        NIMUReceivePacket(hPacket);
    }

    /* Work has been completed; the receive queue is empty... */
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
    NIMU_EMAC_DATA*  ptr_pvt_data;
    int32_t retVal;
    /* Get the pointer to the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA *)ptr_net_device->pvt_data;

    /* call the switch driver's Ioctl handler to take care of this. */
    retVal = nimu_pkt_ioctl(&ptr_pvt_data->pdi, cmd, pBuf, size);
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
int32_t NimuEmacInit(uint32_t portNum, STKEVENT_Handle hEvent)
{
    int32_t retVal = 0;
    NIMU_EMAC_DATA*      ptr_pvt_data;
    char names[NIMU_CPSW_PORT_NUM][NIMU_PORT_NAME_LEN]={"eth0","eth1","eth2","eth3","eth4","eth5"};

    /* memset netif device struct */
    mmZeroInit((void*)(&ptr_device[portNum]), sizeof(NETIF_DEVICE));

    /* Allocate memory for the private data */
    ptr_pvt_data = (NIMU_EMAC_DATA*)(mmAlloc(sizeof(NIMU_EMAC_DATA)));
    if (ptr_pvt_data == NULL)
    {
        NIMU_drv_log ("Error: Unable to allocate private memory data\n");
        retVal= -1;
    }
    else
    {
        /* Initialize the allocated memory block for private data. */
        mmZeroInit (ptr_pvt_data, sizeof(NIMU_EMAC_DATA));

        /* Initialize the RX Queue */
        PBMQ_init(&ptr_pvt_data->pdi.PBMQRx);

       /* Retrieve MAC address */
        nimu_addr_get((portNum), (NIMU_MacAddr*)(&( ptr_pvt_data->pdi.bMacAddr[0])));

        ptr_pvt_data->pdi.hEvent  = hEvent;
        /* MCast List is EMPTY */
        ptr_pvt_data->pdi.mCastCnt    = 0;
        ptr_pvt_data->pdi.portNum = portNum;
        strcpy(ptr_device[portNum].name, names[portNum]);
        ptr_device[portNum].mtu         = ETH_MAX_PAYLOAD - ETHHDR_SIZE;
        ptr_device[portNum].pvt_data    = (void *)ptr_pvt_data;
    
        /* Populate the Driver Interface Functions. */
        ptr_device[portNum].start       = &NIMU_start;
        ptr_device[portNum].stop        = &NIMU_stop;
        ptr_device[portNum].poll        = &NIMU_Poll;
        ptr_device[portNum].send        = &NIMU_send;
        ptr_device[portNum].pkt_service = &NIMU_pktService;
        ptr_device[portNum].ioctl       = &NIMU_ioctl;
        ptr_device[portNum].add_header  = &NIMUAddEthernetHeader;
        ptr_device[portNum].flags       = NIMU_DEVICE_NO_FREE;
    
        /* Register the device with NIMU */
        if (NIMURegister (&ptr_device[portNum]) < 0)
        {
            NIMU_drv_log ("Error: Unable to register the EMAC\n");
            retVal = -1;
        }
        else
        {
            gNumEmacInterfaces++;
        }
    }
     return retVal;
}

 int32_t NimuEmacInitP0(STKEVENT_Handle hEvent)
{
    NimuEmacInit(0U, hEvent);
    return 0;
}
int32_t NimuEmacInitP1(STKEVENT_Handle hEvent)
{
    NimuEmacInit(1U, hEvent);
    return 0;
}

 int32_t NimuEmacInitP2(STKEVENT_Handle hEvent)
{
    NimuEmacInit(2U, hEvent);
    return 0;
}
int32_t NimuEmacInitP3(STKEVENT_Handle hEvent)
{
    NimuEmacInit(3U, hEvent);
    return 0;
}

int32_t NimuEmacInitP4(STKEVENT_Handle hEvent)
{
    NimuEmacInit(4U, hEvent);
    return 0;
}

int32_t NimuEmacInitP5(STKEVENT_Handle hEvent)
{
    NimuEmacInit(5U, hEvent);
    return 0;
}
int32_t NimuEmacInitP6(STKEVENT_Handle hEvent)
{
    NimuEmacInit(6U, hEvent);
    return 0;
}
int32_t NimuEmacInitP7(STKEVENT_Handle hEvent)
{
    NimuEmacInit(7U, hEvent);
    return 0;
}
int32_t NimuEmacInitP8(STKEVENT_Handle hEvent)
{
    NimuEmacInit(8U, hEvent);
    return 0;
}
/**
 *  @b RxPacket
 *  @n
 *      Function called by EMAC driver to pass the received packet to the NIMU driver.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  cslPkt
 *      EMAC_PKT_DESC_Ttype packet passed by EMAC driver.
 *
 *  @retval
 *        EMAC_PKT_DESC_T pointer of a packet with buffer to replenish CSL.
 */
static void  nimu_rx_pkt_cb (uint32_t port_num, EMAC_PKT_DESC_T*     p_desc)
{

    PBM_setValidLen((PBM_Handle) p_desc->AppPrivate, p_desc->ValidLen);
    PBM_setIFRx((PBM_Handle) p_desc->AppPrivate, pPDI[port_num]->hEther );
    PBMQ_enq( &pPDI[port_num]->PBMQRx, (PBM_Handle) p_desc->AppPrivate );

        /* Notify NDK stack of pending Rx Ethernet packet */
        STKEVENT_signal( pPDI[port_num]->hEvent, STKEVENT_ETHERNET, 1U );
}

/**
 *  @b Description
 *  @n
 *      Function registered with emac driver  mac driver
 *      for packet allocation request.
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
    EMAC_PKT_DESC_T *pktDesc = NULL;
    uint8_t         *bufferPtr;

    hPkt = PBM_alloc(pkt_size + sizeof(EMAC_PKT_DESC_T));
    if (hPkt != NULL)
    {
        PBM_setDataOffset(hPkt,0);
        bufferPtr =  PBM_getDataBuffer(hPkt);
        pktDesc   =  (EMAC_PKT_DESC_T*)&bufferPtr[pkt_size];

        pktDesc->AppPrivate   = (uintptr_t)hPkt;
        pktDesc->pDataBuffer  = bufferPtr;
        pktDesc->BufferLen    = PBM_getBufferLen(hPkt);
        pktDesc->DataOffset   = PBM_getDataOffset(hPkt);
        pktDesc->pPrev = NULL;
        pktDesc->pNext = NULL;
        pktDesc->PktFrags = 0;
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

    /* if PktFlags is set to NIMU_TX_PKT_DESC, free is 
     * being called for tx recycle, need to free p_pkt_desc
     */
    if(p_pkt_desc->PktFrags == NIMU_TX_PKT_DESC)
    {
        Osal_free(p_pkt_desc, sizeof(EMAC_PKT_DESC_T));
    }
}

/**
 *  @b nimu_pkt_tx_next
 *  @n
 *      Routine to send out a packet.
 *
 *  @param[in]  pi
 *      PDINFO structure pointer.
 *
 *  @retval
 *      void
 */
static int_fast32_t nimu_pkt_tx_next( NIMU_PdInfo *pi )
{
    PBM_Handle          hPkt;
    //EMAC_PKT_DESC_T     csl_send_pkt;
    EMAC_DRV_ERR_E sendResult = EMAC_DRV_RESULT_OK;
    uint32_t port_num = pi->portNum;

    EMAC_PKT_DESC_T* pkt_desc = (EMAC_PKT_DESC_T*)Osal_malloc(sizeof(EMAC_PKT_DESC_T));

    /* Checking for any queued packets to be transmitted */
    hPkt = PBMQ_deq(&pi->PBMQTx);
    if (hPkt == NULL)
    {
        pi->txFree = 1;
    }
    else
    {
        pkt_desc->AppPrivate     = (uintptr_t)hPkt;
        pkt_desc->pDataBuffer    = PBM_getDataBuffer(hPkt);
        pkt_desc->BufferLen      = PBM_getBufferLen(hPkt);
        pkt_desc->ValidLen       = PBM_getValidLen(hPkt);
        pkt_desc->DataOffset     = PBM_getDataOffset(hPkt);
        pkt_desc->pNext          = NULL;
        pkt_desc->pPrev          = NULL;
        pkt_desc->Flags          = 0;

        /* We only use one Tx DMA channel  now. If QOS/Priority has to be
          * supported, identify the channel number based on vlan/priority tag or
          * any other field from the header fields of the ethernet frame.
          */
        pkt_desc->PktChannel     = 0U;
        pkt_desc->PktLength      = PBM_getValidLen(hPkt);
        /* use PktFrags field to indicate this is desriptor used for tx 
          * and needs to be freed at time of nimu_free_pkt
          */
        pkt_desc->PktFrags       = NIMU_TX_PKT_DESC;
        sendResult = emac_send(port_num, pkt_desc);

        if(sendResult)
        {
            NIMU_drv_log1("CPSW_sendPacket() returned error %08x\n",sendResult);
        }
    }
    return sendResult;
}


int32_t nimu_pkt_ioctl(NIMU_PdInfo *pi, uint32_t cmd, void* param, uint32_t size)
{
    return 0;
}


static void nimu_addr_get(uint32_t addrIdx, NIMU_MacAddr *p)
{
        p->macAddr[0] = 0xd8;
        p->macAddr[1] = 0x93;
        p->macAddr[2] = 0xfe;
        p->macAddr[3] = 0xfa;
        p->macAddr[4] = 0x18;
        p->macAddr[5] = 0xe6 + addrIdx;
}

#ifdef NIMU_ICSSG
/*
 *  ======== nimu_init_pruicss========
 */
int32_t  nimu_disable_pruicss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t pru_n, rtu_n, slice_n ;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;

    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;

    if (PRUICSS_pruDisable(prussDrvHandle, pru_n) != 0)
        return -1;

    if (PRUICSS_pruDisable(prussDrvHandle, rtu_n) != 0)
        return -1;

    /* CLEAR SHARED MEM which is used for host/firmware handshake */
    PRUICSS_pruInitMemory(prussDrvHandle, PRU_ICSS_SHARED_RAM); 


    return 0;
}

/*
 *  ======== nimu_init_pruicss========
 */
int32_t  nimu_init_pruicss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t firmwareLoad_done = FALSE;
    uint8_t pru_n, rtu_n, slice_n ;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;

    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;

    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM(slice_n), 0,
                               firmware[slice_n].pru, firmware[slice_n].pru_size)) {
        if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM(slice_n + 2), 0,
                                   firmware[slice_n].rtu, firmware[slice_n].rtu_size))
            firmwareLoad_done = TRUE;
    }

    if( firmwareLoad_done)
    {
        if (PRUICSS_pruEnable(prussDrvHandle, pru_n) != 0)
            return -1;
        if (PRUICSS_pruEnable(prussDrvHandle, rtu_n) != 0)
            return -1;
    }

    return 0;
}

#endif
