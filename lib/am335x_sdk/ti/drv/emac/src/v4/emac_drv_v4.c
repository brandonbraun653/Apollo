/**
 *  \file   emac_drv_v4.c
 *
 *  \brief  emac driver API implementation for AM57x,AM335x,AM437x, DRA7XX
 *
 *  This file contains the driver APIs for EMAC peripheral for AM57x,AM335x,AM437x,
 *  DRA7XX
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include <string.h>
#include <ti/csl/csl_utils.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_cpgmac_sl.h>
#include <ti/csl/src/ip/cpgmac/V2/cslr_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_sl.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_slAux.h>
#include <ti/csl/cslr_cpsw.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_cpsw_3g.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_wr.h>
#include <ti/csl/src/ip/cpdma/V0/cslr_cpdma.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/src/ip/cpsw/V3/csl_cpswAux.h>
#include <ti/csl/src/ip/ale/V2/cslr_ale.h>



#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>
#include <ti/drv/emac/soc/emac_soc_v4.h>
#include <ti/drv/emac/src/emac_osal.h>

/*
 * EMAC master control block
 */
EMAC_McbV4      emac_mcb;


#define     EXTMEM                      0x80000000U
#define     EMAC_MAX_PKTS                    512U
#define     EMAC_PKT_MTU_DEFAULT             1518U

#define EMAC_APP_HANDLE                     0x12345678U



#define EMAC_CPSW_ALE_CONTROL   (0x8U)
#define EMAC_CPSW_ALE_PORTCTL(n)   ((0x40U) + ((n) * (4U)))


/* Globals, internal to LLD */
/* Array of EMAC packet placeholders to handle tx packets, internal to LLD */
EMAC_PKT_DESC_T    send_packet[EMAC_MAX_PKTS] __attribute__ ((aligned (64)));

/* Array of EMAC packet placeholders to handle rx packets, internal to LLD*/
EMAC_PKT_DESC_T    receive_packet[EMAC_MAX_PKTS] __attribute__ ((aligned (64)));

EMAC_Cpsw3gDevice      localDev;

/* Local functions */
static EMAC_PKT_DESC_T* EMAC_queuePop(EMAC_PKT_QUEUE_T*   pq);
static void EMAC_queuePush(EMAC_PKT_QUEUE_T*   pq, EMAC_PKT_DESC_T*           pPktHdr);


/* EMAC_v4 functions */
static EMAC_DRV_ERR_E EMAC_open_v4(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E  EMAC_config_v4(uint32_t port_num, EMAC_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E EMAC_close_v4(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_poll_pkt_v4(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_send_v4(uint32_t port_num, EMAC_PKT_DESC_T* p_pkt_desc);

static  EMAC_DRV_ERR_E EMAC_poll_v4(uint32_t port_num, EMAC_LINK_INFO_T* p_info);

static EMAC_DRV_ERR_E EMAC_get_stats_v4(uint32_t port_num, EMAC_STATISTICS_T*      p_stats);

void EMAC_v4_hwiFxn(uintptr_t arg);

/* EMAC function table for EMAC_v4 implementation */
CSL_PUBLIC_CONST  EMAC_FxnTable EMAC_FxnTable_v4 =
{
    &EMAC_open_v4,
    &EMAC_config_v4,
    &EMAC_close_v4,
    &EMAC_send_v4,
    &EMAC_poll_v4,
    &EMAC_get_stats_v4,
    &EMAC_poll_pkt_v4,
    NULL,
    NULL,
    NULL
};


extern int32_t  ENETPHY_Init(ENETPHY_Handle hPhyDev, uint32_t miibase, uint32_t inst, uint32_t PhyMask,
                        uint32_t MLinkMask, uint32_t MdixMask, uint32_t PhyAddr, uint32_t ResetBit, uint32_t MdioBusFreq,
                        uint32_t MdioClockFreq,int32_t verbose);

/*Called every 100 milli Seconds, returns TRUE if there has been a mode change */
extern int32_t ENETPHY_Tic(ENETPHY_Handle hPhyDev, uint32_t* mdioStatus);

/*Called to set Phy mode */
extern void ENETPHY_SetPhyMode(ENETPHY_Handle hPhyDev,uint32_t PhyMode);

/*Called to Get Phy mode */
extern uint32_t ENETPHY_GetPhyMode(ENETPHY_Handle hPhyDev);

/*Calls to retreive info after a mode change! */
extern int32_t  ENETPHY_GetDuplex(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetSpeed(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetPhyNum(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetLinked(ENETPHY_Handle hPhyDev);
extern void ENETPHY_LinkChange(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetLoopback(ENETPHY_Handle hPhyDev);

/*  Shut Down  */
extern void ENETPHY_Close(ENETPHY_Handle hPhyDev, int32_t Full);



static Handle                                   emac_cpsw_handle = NULL;           /* Handle to our EMAC instance */


static EMAC_LINK_INFO_T mLinkStatusInfo[EMAC_NUM_MAX_MAC_PORTS];


/* Defines the num of ports, mac ports*/

static EMAC_DRV_ERR_E EMAC_interruptInit(uint32_t port_num);
static void EMAC_interruptEnd(uint32_t port_num);

static void EMAC_cpswALEAgeOutNow(uint32_t baseAddr);
static uint32_t EMAC_cpswALEPortStateGetAny(uint32_t baseAddr, uint32_t portNum);


/**
 *  @b EMAC_enableInterrupts
 *  @n
 *      This function enables the EMAC interrupts
 *
 *  @retval
 *      None.
 */
static void EMAC_enableInterrupts(uint32_t port_num); /* for misra warning */
static void EMAC_enableInterrupts(uint32_t port_num)
{
    uint32_t key = 0;
    EMAC_HwAttrs_V4 hwAttrs;

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    key = EMAC_osalHardwareIntDisable();

    EMAC_osalHardwareIntrEnable(hwAttrs.rxEventId,hwAttrs.rxIntrNum);

    EMAC_osalHardwareIntrEnable(hwAttrs.txEventId,hwAttrs.txIntrNum);

    EMAC_osalHardwareIntRestore(key);
}

/**
 *  @b EMAC_disableInterrupts
 *  @n
 *      This function disables the EMAC interrupts
 *
 *  @retval
 *      None.
 */
static void EMAC_disableInterrupts(uint32_t port_num); /* for misra warning */
static void EMAC_disableInterrupts(uint32_t port_num)
{
    uint32_t key;
    EMAC_HwAttrs_V4 hwAttrs;

    EMAC_socGetInitCfg(port_num, &hwAttrs);
    
    key = EMAC_osalHardwareIntDisable();

    EMAC_osalHardwareIntrDisable(hwAttrs.rxEventId,hwAttrs.rxIntrNum);

    EMAC_osalHardwareIntrDisable(hwAttrs.txEventId,hwAttrs.txIntrNum);

    EMAC_osalHardwareIntRestore(key);
}

/**
 *  @b EMAC_getPacket
 *  @n
 *      Get a packet descriptor from the RxQueue.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *
 *  @retval
 *      EMAC_PKT_DESC_T pointer of a packet descriptor with buffer to replenish by CSL.
 */
static EMAC_PKT_DESC_T* EMAC_getPacket(Handle      hApplication); /* for misra warning */
static EMAC_PKT_DESC_T* EMAC_getPacket(Handle      hApplication)
{
    EMAC_PKT_DESC_T*   pPkt;
    uint32_t      port_num = (uint32_t)hApplication - EMAC_APP_HANDLE;

    if( port_num >= EMAC_NUM_MAX_MAC_PORTS )
    {
        pPkt = NULL;
    }
    else
    {
        pPkt = EMAC_queuePop(&EMAC_RX_QUEUE(port_num));
    }
    return( pPkt );
}



/**
 *  @b Queue_push
 *  @n
 *      Enqueues a packet in CPSW_Pkt queue.
 *
 *  @param[in]  pq
 *      Packet queue of type PKT_QUEUE .
 *  @param[in]  pPktHdr
 *      CPSW_Pkt type packet to push.
 *
 *  @retval
 *      void
 */
static void EMAC_queuePush( EMAC_PKT_QUEUE_T*pq, EMAC_PKT_DESC_T*pPktHdr )
{
    uint32_t key = 0;
    key = EMAC_osalHardwareIntDisable();

    pPktHdr->pNext = 0;

    if( pq->pHead == NULL )
    {
        /* Queue is empty - Initialize it with this one packet */
        pq->pHead = pPktHdr;
        pq->pTail = pPktHdr;
    }
    else
    {
        /* Queue is not empty - Push onto end */
        pq->pTail->pNext = pPktHdr;
        pq->pTail        = pPktHdr;
    }
    pq->Count++;

    EMAC_osalHardwareIntRestore(key);
}


/**
 *  @b Queue_pop
 *  @n
 *      Dequeues a packet from EMAC_PKT_QUEUE_T queue.
 *
 *  @param[in]  pq
 *      Packet queue of type EMAC_PKT_QUEUE_T .
 *
 *  @retval
 *      EMAC_PKT_DESC_T popped from the queue.
 */
static EMAC_PKT_DESC_T *EMAC_queuePop( EMAC_PKT_QUEUE_T *pq )
{
    EMAC_PKT_DESC_T *pPktHdr = NULL;
    uint32_t key = 0;

    key = EMAC_osalHardwareIntDisable();

    pPktHdr = pq->pHead;

    if( pPktHdr)
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }

    EMAC_osalHardwareIntRestore(key);

    return( pPktHdr );
}

/**
 *  @b EMAC_freePacket
 *  @n
 *      Called by CSL to free the packet descriptor.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  p_cslPkt_desc
 *      Pointer to EMAC_PKT_DESC_T type packet descriptor passed by CSL.
 *  @param[in]  direction
 *      RX or Tx, will specify which queue to push the EMAC_PKT_DESC_T
 *
 *  @retval
 *      void
 */
static void EMAC_freePacket(Handle      hApplication, EMAC_PKT_DESC_T*   p_cslPkt_desc, uint32_t direction ); /* for misra warning */
static void EMAC_freePacket(Handle      hApplication, EMAC_PKT_DESC_T*   p_cslPkt_desc, uint32_t direction)
{
    uint32_t      port_num = (uint32_t)hApplication - EMAC_APP_HANDLE;

    if( port_num <  EMAC_NUM_MAX_MAC_PORTS )
    {
        EMAC_FREE_PKT(port_num, (EMAC_PKT_DESC_T *)p_cslPkt_desc);
		if (direction == CPSW_NET_CH_DIR_TX )
		{
			EMAC_queuePush(&EMAC_TX_QUEUE(port_num), p_cslPkt_desc );
		}
		else
		{
			EMAC_queuePush(&EMAC_RX_QUEUE(port_num), p_cslPkt_desc );
		}
    }
}

/* receive packet drop counter, will get pegged each time
 *   EMAC_ALLOC_PKT failure occurs, indicates packet 
 *   packet desriptor replenish failure */
uint32_t gRxDropCounter = 0;
/**
 *  @b EMAC_rxPacket
 *  @n
 *      Called by CSL to pass the received packet descriptor to the driver.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  p_cslPkt_desc
 *      Pointer of EMAC_PKT_DESC_T type packet descriptor passed by CSL.
 *
 *  @retval
 *      EMAC_PKT_DESC_T pointer of a new packet descriptor with buffer to replenish by CSL.
 */
static EMAC_PKT_DESC_T* EMAC_rxPacket(Handle      hApplication, EMAC_PKT_DESC_T*   p_cslPkt_desc); /* for misra warning */
static EMAC_PKT_DESC_T* EMAC_rxPacket(Handle      hApplication, EMAC_PKT_DESC_T*   p_cslPkt_desc)
{
    EMAC_PKT_DESC_T*    p_new_pkt_desc;
    uint32_t from_port = 0U;
    uint32_t bufLen = 0U;
    uint8_t* bufPtr = NULL;
    uint32_t dataOffset = 0U;
    uintptr_t appPrivate = 0U;

    from_port = ((p_cslPkt_desc->Flags & EMAC_PKT_FLAG_FROM_PORT_MASK) >> EMAC_PKT_FLAG_FROM_PORT_SHIFT) -1U;
    if( from_port < EMAC_NUM_MAX_MAC_PORTS )
    {
        /* Allocate the PKT to replenish the RX_FREE_QUEUE queue first.
          * Only provide packet to the applicaton if EMAC_ALLOC_PKT suceeds, 
          * otherwise re-use the packet descriptor */
        p_new_pkt_desc = EMAC_ALLOC_PKT(from_port, EMAC_PKT_SIZE(from_port));
        if (p_new_pkt_desc != NULL)
        {
            EMAC_RX_PKT(from_port, p_cslPkt_desc);
            memcpy((void *)p_cslPkt_desc, (void *)p_new_pkt_desc, sizeof(EMAC_PKT_DESC_T));
        }
        else
        {
            bufLen = p_cslPkt_desc->BufferLen;
            bufPtr = p_cslPkt_desc->pDataBuffer;
            dataOffset = p_cslPkt_desc->DataOffset;
            appPrivate = p_cslPkt_desc->AppPrivate;
            memset(p_cslPkt_desc, 0, sizeof(EMAC_PKT_DESC_T));
            p_cslPkt_desc->BufferLen = bufLen;
            p_cslPkt_desc->pDataBuffer = bufPtr;
            p_cslPkt_desc->DataOffset = dataOffset;
            p_cslPkt_desc->AppPrivate = appPrivate;
            gRxDropCounter++;
        }
    }
    return p_cslPkt_desc;
}

/**
 *  @b EMAC_setupCpswInitConfig
 *  @n
 *     Populate the configuration structures with
 *     the switch's default initialization parameters.
 *
 *  @param[in]
 *      void
 *
 *  @retval
 *      void
 */
static void EMAC_setupCpswInitConfig(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config); /* for misra warning */
static void EMAC_setupCpswInitConfig(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_Cpsw3gInitConfig    *iCfg = NULL;
    uint32_t               i, j;
    EMAC_HwAttrs_V4 hwAttrs;

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    iCfg = &(EMAC_LOCAL_DEVICE->Config);

    /* Configure the Number of Rx, Tx channels */
    iCfg->dmaInitCfg.numChannels[CPSW_NET_CH_DIR_TX] = EMAC_CPSW_INITPARAM_TXNUMCHAN;
    iCfg->dmaInitCfg.numChannels[CPSW_NET_CH_DIR_RX] = EMAC_CPSW_INITPARAM_RXNUMCHAN;

    /* Initialize Tx,Rx channels with number of BDs to be allocated for
     * each of them.
     */
    for(i=0U; i<iCfg->dmaInitCfg.numChannels[CPSW_NET_CH_DIR_TX]; i++)
    {
        EMAC_CpswChInfo *txChCfg = &(iCfg->chInfo[CPSW_NET_CH_DIR_TX][i]);
        txChCfg->chNum = i;
        txChCfg->chDir = CPSW_NET_CH_DIR_TX;
        txChCfg->numBD = EMAC_NUM_TX_PKTS(port_num);
    }
    for(i=0U; i<iCfg->dmaInitCfg.numChannels[CPSW_NET_CH_DIR_RX]; i++)
    {
        EMAC_CpswChInfo *rxChCfg = &(iCfg->chInfo[CPSW_NET_CH_DIR_RX][i]);
        rxChCfg->chNum = i;
        rxChCfg->chDir = CPSW_NET_CH_DIR_RX;
        /* Configure the Buffer size for plain ethernet packets. VLANs disabled by
         * default. If using VLANs make sure to add in 4 bytes to the buffer size
         * below to accomodate VLAN header.
         */
        rxChCfg->bufSize = 1522;
        rxChCfg->numBD =  EMAC_NUM_RX_PKTS(port_num);
    }

    /* Program Default ALE Configuration */
    iCfg->aleCfg.aleModeFlags = CPSW_CONFIG_ALE_ENABLE
                                 | CPSW_CONFIG_ALE_CLRTABLE;

    /** CHECK: Set this to correct value.Set Ratelimit counter for 1msec*/
    iCfg->aleCfg.alePrescale =  EMAC_CPSW_DEFAULT_ALEPRESCALE;



    iCfg->baseConfig.ss_base = hwAttrs.ss_base;
    iCfg->baseConfig.mdio_base = hwAttrs.mdio_base;
    iCfg->baseConfig.wrpr_base = hwAttrs.wrpr_base;
    iCfg->baseConfig.cpdma_base = hwAttrs.cpdma_base;
    iCfg->baseConfig.ale_base = hwAttrs.ale_base;
    iCfg->baseConfig.stat_base = hwAttrs.stat_base;
    iCfg->baseConfig.cppi_ram_base = hwAttrs.cppi_ram_base;
    iCfg->baseConfig.host_port_base = hwAttrs.host_port_base;
    iCfg->baseConfig.numPorts = hwAttrs.numPorts;
    iCfg->baseConfig.port[EMAC_PORT_1].sliver_base = hwAttrs.port[EMAC_PORT_1].sliver_base;
    iCfg->baseConfig.port[EMAC_PORT_1].port_base = hwAttrs.port[EMAC_PORT_1].port_base;
    iCfg->baseConfig.port[EMAC_PORT_2].port_base = hwAttrs.port[EMAC_PORT_2].port_base;
    iCfg->baseConfig.port[EMAC_PORT_2].sliver_base = hwAttrs.port[EMAC_PORT_2].sliver_base;
    iCfg->baseConfig.port[EMAC_PORT_1].phy_addr= hwAttrs.port[EMAC_PORT_1].phy_addr;
    iCfg->baseConfig.port[EMAC_PORT_2].phy_addr = hwAttrs.port[EMAC_PORT_2].phy_addr;

    /* Ale Port Config */
    for(i=0U; i < iCfg->baseConfig.numPorts + 1U; i++)
    {
        iCfg->alePortCfg[i].portState = CPSW_ALE_PORT_STATE_FWD;
    }
    /*CPSW3G default config*/
    iCfg->cpswCfg.cpswStatModeFlags = CPSW_CONFIG_STAT_ENABLE;

    iCfg->cpswCfg.mdioBusFrequency = MDIO_FREQ_INPUT;
    iCfg->cpswCfg.mdioClockFrequency = MDIO_FREQ_OUTPUT;
    /* Program default MAC SL config , this might have to be emac_cpsw_num_ports instead*/
    for(i=0U; i < iCfg->baseConfig.numPorts; i++)
   {
        /* if no phy address is specified for the port, continue with next port */
        if (iCfg->baseConfig.port[i].phy_addr != EMAC_CPSW_NO_PHY_ADDR)
        {
            /* parse the default speed/duplex params. Use Auto Neg*/
            iCfg->macInitCfg[i].mdioModeFlags |= CPSW_MDIO_MODEFLG_AUTONEG;
    
            if (p_config->loop_back)
            {
                 iCfg->macInitCfg[i].mdioModeFlags |=CPSW_MDIO_MODEFLG_LOOPBACK;
            }
    
            if(0U == i)
            {
                /* program phy_mask for port 1 */
                iCfg->macInitCfg[i].PhyMask = ((uint32_t)1U) << (iCfg->baseConfig.port[i].phy_addr);
                iCfg->macInitCfg[i].MLinkMask = 0x0U;
            }
            else
            {
                /* program phy_mask for port 2 */
                iCfg->macInitCfg[i].PhyMask = ((uint32_t)1U)<<(iCfg->baseConfig.port[i].phy_addr);/*corresponding to address 2 */
                iCfg->macInitCfg[i].MLinkMask = 0x1U;
            }/* end of else block covering settings for port 1 */
            iCfg->macInitCfg[i].macModeFlags |= hwAttrs.macModeFlags;
        }
    }/* end of for loop over CPSW3G_NUM_MAC_PORTS */

    /* We count in 100ms Ticks */
   iCfg->aleTicks = (EMAC_CPSW_ALE_AGE_OUT_TIME / EMAC_CPSW_ALE_TICK_PERIOD);
   iCfg->aleTimerActive        = 0U;

   iCfg->CoreNum               = 0U;

    /* Add 4 bytes for VLAN header if configuring for VLANs */
    iCfg->PktMTU                = EMAC_PKT_MTU_DEFAULT;

    /* Configure the callback functions which will call the user configured functions */
    iCfg->pfcbGetPacket          = &EMAC_getPacket;
    iCfg->pfcbFreePacket         = &EMAC_freePacket;
    iCfg->pfcbRxPacket           = &EMAC_rxPacket;

    iCfg->totalNumMacAddrs     =  p_config->p_chan_mac_addr->num_of_mac_addrs;

    for ( j=0U; j < iCfg->totalNumMacAddrs; j++)
    {
        memcpy((void*)&(iCfg->MacAddr[j].Addr[0]), (void *)p_config->p_chan_mac_addr->p_mac_addr[j].addr, 6U );
        iCfg->MacAddr[j].ChannelNum = p_config->p_chan_mac_addr->chan_num;
    }
    return;
}

/* local function */
static EMAC_DRV_ERR_E EMAC_initQueue (uint32_t      port_num); /* for misra warning */
static EMAC_DRV_ERR_E EMAC_initQueue (uint32_t      port_num)
{
    uint32_t i;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_PKT_DESC_T* p_rx_pkt_desc;

    memset(&EMAC_RX_QUEUE(port_num), 0, sizeof(EMAC_PKT_QUEUE_T));
    memset(&EMAC_TX_QUEUE(port_num), 0, sizeof(EMAC_PKT_QUEUE_T));

    memset(&receive_packet[0], 0, sizeof(EMAC_PKT_DESC_T)* EMAC_MAX_PKTS);

    for( i=0; i< EMAC_NUM_RX_PKTS(port_num); i++ )
    {
        p_rx_pkt_desc = EMAC_ALLOC_PKT(port_num,  EMAC_PKT_SIZE(port_num));
        if (p_rx_pkt_desc == NULL)
        {
            retVal = EMAC_DRV_RESULT_NO_MEM_AVAIL;
        }
        else
        {
            memcpy((void *)&receive_packet[i], (void *)p_rx_pkt_desc, sizeof(EMAC_PKT_DESC_T));
            EMAC_queuePush(&EMAC_RX_QUEUE(port_num), &receive_packet[i] );
        }
    }

    if (retVal != EMAC_DRV_RESULT_NO_MEM_AVAIL)
    {
        memset(&send_packet[0], 0, sizeof(EMAC_PKT_DESC_T)* EMAC_MAX_PKTS);
        /* Queue up some transmit buffers */
        for( i=0; i<EMAC_NUM_TX_PKTS(port_num); i++ )
        {
            EMAC_queuePush( &EMAC_TX_QUEUE(port_num), &send_packet[i] );
        }
    }
    return retVal;
}

/*
 *  ======== EMAC_open_v4 ========
 */
 
extern uint32_t cpswNumBdsAllocated;
static EMAC_DRV_ERR_E  EMAC_open_v4(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    SemaphoreP_Params semParams;
    uint32_t tempVar;

    /* Input parameter validation */
    if ((p_config == NULL)                              ||
        (p_config->num_of_chans == 0)                   ||
        (p_config->p_chan_mac_addr == NULL)             ||
        (p_config->rx_pkt_cb == NULL)                   ||
        (p_config->alloc_pkt_cb == NULL)                ||
        (p_config->free_pkt_cb == NULL)                 ||
        (p_config->num_of_tx_pkt_desc+p_config->num_of_rx_pkt_desc > MAX_EMAC_INIT_PKT_DESC)
       )
    {
        retVal =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    else
    {
        /* Initialize EMAC MCB when opening a port*/
        memset (&emac_mcb.port_cb[port_num], 0, sizeof(EMAC_PortCbV4));
    
        memcpy(&emac_mcb.hwAttrs, p_config->hwAttrs, sizeof(EMAC_HwAttrs_V4));
    
        if (port_num == 0)
        {
            EMAC_LOCAL_DEVICE = &localDev;
            memset(EMAC_LOCAL_DEVICE, 0, sizeof(EMAC_Cpsw3gDevice));
        }

        EMAC_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        semParams.name= "rxSemaphore";
    
       EMAC_GLOBAL_RX_SEM_HANDLE(port_num) =  EMAC_osalCreateBlockingLock(0,&semParams);
        if((EMAC_GLOBAL_RX_SEM_HANDLE(port_num)) ==  NULL)
        {
            retVal =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
        else
        {
            /* Intialize the call back function pointers in EMAC MCB, update to use macros */
            emac_mcb.port_cb[port_num].rx_pkt_cb      = p_config->rx_pkt_cb;
            emac_mcb.port_cb[port_num].alloc_pkt_cb   = p_config->alloc_pkt_cb;
            emac_mcb.port_cb[port_num].free_pkt_cb    = p_config->free_pkt_cb;
            emac_mcb.port_cb[port_num+1U].rx_pkt_cb      = p_config->rx_pkt_cb;
            emac_mcb.port_cb[port_num+1U].alloc_pkt_cb   = p_config->alloc_pkt_cb;
            emac_mcb.port_cb[port_num+1U].free_pkt_cb    = p_config->free_pkt_cb;
        
            EMAC_MASTER_CORE(port_num)              = p_config->master_core_flag;
            EMAC_NUM_RX_PKTS(port_num)              = p_config->num_of_rx_pkt_desc;
            EMAC_NUM_TX_PKTS(port_num)              = p_config->num_of_tx_pkt_desc;
            EMAC_NUM_TXRX_PKTS(port_num)            =  p_config->num_of_tx_pkt_desc + p_config->num_of_rx_pkt_desc;
        
            if (p_config->master_core_flag)
            {
                EMAC_PKT_SIZE(port_num)                 = p_config->max_pkt_size; /* this should be 1514 - 14 */
                emac_mcb.port_cb[port_num].loop_back = p_config->loop_back;
           }
            /* Initialize EMAC setup */
            mLinkStatusInfo[port_num].link_status_change = 0;
            mLinkStatusInfo[port_num].link_status = 0;
        
            EMAC_setupCpswInitConfig(port_num, p_config);
        
            retVal = EMAC_initQueue(port_num);
            if (retVal == EMAC_DRV_RESULT_OK)
            {
                tempVar = CPSW_HANDLE_VALUE + port_num;
                retVal = (EMAC_DRV_ERR_E)EMAC_cpswOpen(1, (Handle)tempVar, &EMAC_LOCAL_DEVICE->Config, &emac_cpsw_handle );
                if (retVal == EMAC_DRV_RESULT_OK)
                {
                    retVal = EMAC_interruptInit(port_num);
                    if (retVal == EMAC_DRV_RESULT_OK)
                    {
                        EMAC_enableInterrupts(port_num);
                    }
                }
            }
        }
    }
    if (retVal == EMAC_DRV_RESULT_OK)
    {
         emac_mcb.port_cb[port_num].emacState    = 1;
    }
    return retVal;
}



static EMAC_DRV_ERR_E  EMAC_config_v4(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config)
{
    return EMAC_DRV_RESULT_OK;
}

static EMAC_DRV_ERR_E EMAC_close_v4( uint32_t port_num)
{
    uint32_t i;
    EMAC_DRV_ERR_E retVal;
    if (port_num >= EMAC_NUM_MAX_MAC_PORTS)
    {
        retVal =  EMAC_DRV_RESULT_INVALID_PORT;
    }
    else
    {
        i = EMAC_cpswClose( emac_cpsw_handle );
        if( i )
        {
            retVal =  EMAC_DRV_RESULT_CLOSE_PORT_ERR;
        }
        else
        {
            cpswNumBdsAllocated = 0;
            emac_mcb.port_cb[port_num].emacState  = 0;
            /* Need to post the lock so the semaphore can be deleted as part of cleanup */
            EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(0));
            EMAC_disableInterrupts(port_num);
            EMAC_interruptEnd(port_num);
            EMAC_osalDeleteBlockingLock(EMAC_GLOBAL_RX_SEM_HANDLE(0));
            
            emac_cpsw_handle = 0;
            retVal = EMAC_DRV_RESULT_OK;
        }
    }
    return retVal;
}

static EMAC_DRV_ERR_E EMAC_get_stats_v4(uint32_t port_num, EMAC_STATISTICS_T*      p_stats)
{
    uint32_t              i;

    uint32_t *pStatAddr;
    uint32_t          statval;
    EMAC_HwAttrs_V4 hwAttrs;

    EMAC_socGetInitCfg(port_num, &hwAttrs);
    pStatAddr = (uint32_t*)(p_stats);

    /*
     * There are "CPSW_NUMSTATS" statistics registers
     * Note that when GMIIEN is set in MACCONTROL, these registers
     * are "write to decrement".
     */
    for (i = 0U; i < CPSW_NUMSTATS; i++)
    {
        statval = EMAC_cpswStatsRead(hwAttrs.stat_base, i);
        *pStatAddr += statval;
        pStatAddr++;
    }


    return EMAC_DRV_RESULT_OK;
}

static EMAC_DRV_ERR_E EMAC_send_v4(uint32_t port_num, EMAC_PKT_DESC_T* p_pkt_desc)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_PKT_DESC_T*           csl_send_pkt;

    if (port_num >= EMAC_NUM_MAX_MAC_PORTS)
    {
        retVal =  EMAC_DRV_RESULT_INVALID_PORT;
    }
    else
    {
        if (p_pkt_desc==NULL)
        {
            retVal =  EMAC_DRV_RESULT_SEND_ERR;
        }
        else
        {
            csl_send_pkt = EMAC_queuePop(&EMAC_TX_QUEUE(port_num) );
            if (csl_send_pkt == NULL)
            {
                retVal =  EMAC_DRV_RESULT_SEND_ERR;
            }
            else
            {
                memcpy ((void *)csl_send_pkt, (void *)p_pkt_desc, sizeof(EMAC_PKT_DESC_T));
                EMAC_sendPacket(emac_cpsw_handle, csl_send_pkt);
            }
        }
    }
    return retVal;
}


static  EMAC_DRV_ERR_E EMAC_poll_v4(uint32_t port_num, EMAC_LINK_INFO_T* p_info)
{
    EMAC_DRV_ERR_E retVal =  EMAC_DRV_RESULT_POLL_ERR;

    uint32_t            mdioStatus = 0U;
    uint32_t            linkStatus = EMAC_LINKSTATUS_NOLINK;
    EMAC_Cpsw3gDevice*  devPtr = EMAC_LOCAL_DEVICE;
    static uint32_t     aleTickCount = 0;

    /* Assume the link status has not changed */
    mLinkStatusInfo[port_num].link_status_change = FALSE;

    if (p_info == NULL)
    {
        retVal =  EMAC_DRV_RESULT_POLL_ERR;
    }
    else
    {
        if( (0u != devPtr->Config.aleTimerActive) && (0 != devPtr->Config.aleTicks) )
        {
            /* aleTickCount can become greater if timeout period is changed in between */
            aleTickCount++;
            if( (aleTickCount) >=  devPtr->Config.aleTicks)
            {
                /* age out now */
                EMAC_cpswALEAgeOutNow(devPtr->Config.baseConfig.ale_base);
                aleTickCount = 0;
            }
        }

        /* Signal the MDIO */
        {
            /* check for port in forward state, not NO_PHY mode */
            if ((0U != (EMAC_cpswALEPortStateGetAny(devPtr->Config.baseConfig.ale_base , port_num)))  &&
                (0U == (devPtr->Config.macInitCfg[port_num].phyMode & NWAY_NOPHY)))
            {
                EMAC_CPGMacObj *gmacObject  = &devPtr->cpgmacMac[port_num];
                int32_t tickChange;
                EMAC_CPGMacStatus macStat;
    
                tickChange = ENETPHY_Tic(&gmacObject->PhyDev,&mdioStatus);

                if ((mdioStatus == MDIO_EVENT_LINKDOWN)  || (mdioStatus ==  MDIO_EVENT_LINKUP))
                {
                    /* Link_status_change is boolean */
                    mLinkStatusInfo[port_num].link_status_change = TRUE;

                    /* Determine the link status. */
                    if(mdioStatus == MDIO_EVENT_LINKDOWN)
                    {
                        linkStatus = EMAC_LINKSTATUS_NOLINK;
                    }
                    else
                    {
                        /* Link is up */
                        /*  Has Configuration has changed */
                        if(tickChange == 1)
                        {
                            /* Yes. Update. */
                            EMAC_cpswUpdatePhyStatus(gmacObject, port_num);
                            macStat.PhyDuplex = gmacObject->PhyDuplex;
                            macStat.PhyLinked =  gmacObject->PhyLinked;
                            macStat.PhyNum = gmacObject->PhyNum;
                            macStat.PhySpeed = gmacObject->PhySpeed;
                            EMAC_cpswControlCb(devPtr, CPSW3G_PHY_STATUS_UPDATE, &macStat, &devPtr->cpsw3gPort[port_num]);
                        }

                        linkStatus = ((gmacObject->PhySpeed + ((uint32_t)1U)) << ((uint32_t)1U)) + gmacObject->PhyDuplex ;
                    }

                    mLinkStatusInfo[port_num].link_status = linkStatus;
                    retVal = EMAC_DRV_RESULT_OK;
                }
            }
        }

        /* Return the link status info.*/
        p_info->link_status_change = mLinkStatusInfo[port_num].link_status_change;
        p_info->link_status = mLinkStatusInfo[port_num].link_status;
    }

    return retVal;
}

static EMAC_DRV_ERR_E EMAC_poll_pkt_v4(uint32_t port_num)
{
    EMAC_Cpsw3gDevice    *pd = (EMAC_Cpsw3gDevice *)&localDev;
    uint32_t Desc=0;
    uint32_t channelNum = 0;
    EMAC_DescCh  *rxChan;
    int32_t success = 1;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;

    if( emac_mcb.port_cb[port_num].emacState  == 0)
    {
            retVal =  EMAC_DRV_RESULT_GENERAL_ERR;
    }
    else
    {
        /* Validate our handle */
        if ((pd == NULL) || (pd->DevMagic != CPSW_DEVMAGIC))
        {
            retVal = EMAC_DRV_RESULT_POLL_ERR;
        }
        else
        {
            while(success)
            {
                EMAC_osalPendLock(EMAC_GLOBAL_RX_SEM_HANDLE(0), SemaphoreP_WAIT_FOREVER);
                /* check to see if post lock done due to emac_close */
                if( emac_mcb.port_cb[port_num].emacState  == 0)
                {
                    retVal =   EMAC_DRV_RESULT_GENERAL_ERR;
                    break;
                }
                CSL_CPSW_getCpdmaRxCp((CSL_cpdmaHandle) pd->Config.baseConfig.cpdma_base,channelNum, &Desc);
                if (Desc == 0U)
                {
                    success = 0;
                }
                else if (Desc == EMAC_TEARDOWN_DESC)
                {
                    success = 0;
                    CSL_CPSW_setCpdmaRxCp((CSL_cpdmaHandle) pd->Config.baseConfig.cpdma_base,channelNum, EMAC_TEARDOWN_DESC);
                }
                else
                {
                    rxChan = &pd->cpdma.rxCppi[channelNum];
                    EMAC_dequeueRx(rxChan, (EMAC_Desc *)Desc);
                    /* Re-fill Rx buffer queue if needed */
                    if (rxChan->DescCount != rxChan->DescMax)
                    {
                        EMAC_enqueueRx(rxChan, 1U);
                    }
                    CSL_CPSW_setCpdmaRxCp((CSL_cpdmaHandle) pd->Config.baseConfig.cpdma_base,channelNum, Desc);
                    CSL_CPSW_enableCpdmaRxInt((CSL_cpdmaHandle) localDev.Config.baseConfig.cpdma_base, 0);
                    CSL_CPSW_enableWrRxInt((CSL_wrHandle) localDev.Config.baseConfig.wrpr_base, 0, 0);
                }
            }
        }
    }
    return retVal;
}

/**********************************************************************
 *************************** EMAC Functions ***************************
 **********************************************************************/

/**
 *  @b EMAC_cpswHwIntRx
 *  @n
 *      EMAC Receive ISR.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static void EMAC_cpswHwIntRx(uintptr_t arg); /* for misra warning */
static void EMAC_cpswHwIntRx(uintptr_t arg)
{

        EMAC_cpswRxEoiWrite();
        /*disable Rx Interrupt on this channel  and wrapper, will be enabled by task function processing the packet */
        CSL_CPSW_disableCpdmaRxInt((CSL_cpdmaHandle) localDev.Config.baseConfig.cpdma_base, 0);
        /* also disable in the wrapper */
        CSL_CPSW_disableWrRxInt((CSL_wrHandle) localDev.Config.baseConfig.wrpr_base, 0, 0);
        EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(0));

    return;
}

/**
 *  @b EMAC_cpswHwIntTx
 *  @n
 *      EMAC Transmit ISR.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static void EMAC_cpswHwIntTx(uintptr_t arg); /* for misra warning */
static void EMAC_cpswHwIntTx(uintptr_t arg)
{
    if ( emac_cpsw_handle )
    {
        EMAC_cpswTxServiceCheck(emac_cpsw_handle);
        /* write the EOI register */
        EMAC_cpswTxEoiWrite();
    }
   return;
}

/**
 *  @b EMAC_interruptEnd
 *  @n
 *      Deregistering the interrupts and disabling global interrupts.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static void EMAC_interruptEnd(uint32_t port_num)
{
    EMAC_HwAttrs_V4 hwAttrs;
    EMAC_socGetInitCfg(port_num, &hwAttrs);
    
    EMAC_osalHardwareIntDestruct((HwiP_Handle)(EMAC_GLOBAL_RX_HWI_HANDLE(port_num)),hwAttrs.rxEventId);
    EMAC_osalHardwareIntDestruct((HwiP_Handle)(EMAC_GLOBAL_TX_HWI_HANDLE(port_num)),hwAttrs.txEventId);
}

/**
 *  @b EMAC_interruptInit
 *  @n
 *      Registering Interrupts and Enabling global interrupts.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static EMAC_DRV_ERR_E EMAC_interruptInit(uint32_t port_num)
{

    EMAC_HwAttrs_V4 hwAttrs;
    OsalRegisterIntrParams_t interruptRegParams;
    
    EMAC_DRV_ERR_E status = EMAC_DRV_RESULT_OK;

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    static uint32_t cookie = 0;

    cookie = EMAC_osalHardwareIntDisable();
    
/* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);
    
    interruptRegParams.corepacConfig.arg  = (uintptr_t)port_num;
    interruptRegParams.corepacConfig.corepacEventNum = hwAttrs.rxEventId;

    interruptRegParams.corepacConfig.priority = 0x20;
    
    interruptRegParams.corepacConfig.intVecNum = hwAttrs.rxIntrNum;
    interruptRegParams.corepacConfig.isrRoutine = &EMAC_cpswHwIntRx;
    
    EMAC_osalRegisterInterrupt(&interruptRegParams,&(EMAC_GLOBAL_RX_HWI_HANDLE(port_num)));

    if(EMAC_GLOBAL_RX_HWI_HANDLE(port_num) == NULL)
    {
        status =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    if (status == EMAC_DRV_RESULT_OK)
    {

        /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);
    
        interruptRegParams.corepacConfig.arg  = (uintptr_t)NULL;
        interruptRegParams.corepacConfig.corepacEventNum = hwAttrs.txEventId;

        interruptRegParams.corepacConfig.priority = 0x20;
    
        interruptRegParams.corepacConfig.intVecNum = hwAttrs.txIntrNum;
        interruptRegParams.corepacConfig.isrRoutine = &EMAC_cpswHwIntTx;
    
        EMAC_osalRegisterInterrupt(&interruptRegParams,&(EMAC_GLOBAL_TX_HWI_HANDLE(port_num)));

        if (EMAC_GLOBAL_TX_HWI_HANDLE(port_num) == NULL)
        {
            status =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
    }
    /* Restore global interrupts */
    EMAC_osalHardwareIntRestore(cookie);
    return status;
}

/**
 * \brief   Setting this bit causes the ALE hardware to remove
 * (free up) any ageable table entry that does not have a set touch bit.
 *
 * \param   baseAddr    Base address of the ALE module
 *
 * \return  None
 **/
static void EMAC_cpswALEAgeOutNow(uint32_t baseAddr)
{
    uint32_t address = baseAddr + EMAC_CPSW_ALE_CONTROL;
    HWREG(address) |= CSL_ALE_CONTROL_AGE_OUT_NOW_MASK;
}

/**
 * \brief   Gets the port state in the ALE for a given port
 *
 * \param   baseAddr    Base address of the ALE module
 * \param   portNum     The port number
 * 'portState' can take one of the below values \n
 *
 * \return  port State
 **/
static uint32_t EMAC_cpswALEPortStateGetAny(uint32_t baseAddr, uint32_t portNum)
{
    uint32_t address = baseAddr + EMAC_CPSW_ALE_PORTCTL(portNum);
   return (HWREG(address) & CSL_ALE_PORTCTL0_PORT_STATE_MASK);
}
