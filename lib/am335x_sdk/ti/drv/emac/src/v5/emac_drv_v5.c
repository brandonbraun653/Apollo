/**
 *  \file   emac_drv_v5.c
 *
 *  \brief  emac driver API implementation for AM6 for ICSS-G and CPSW
 *
 *  This file contains the driver APIs for EMAC peripheral for AM6
 */

/*
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
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

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/
/* CSL Headers */
#include <ti/csl/soc.h>
#include <ti/csl/csl_udmap.h>

#include <ti/csl/cslr_mdio.h>
#include <ti/csl/cslr_ale.h>
#include <ti/csl/csl_cpswitch.h>
#include <ti/csl/cslr_icss.h>

#include <ti/drv/emac/emac_drv.h>
#include "ti/drv/emac/src/v5/emac_drv_v5.h"
#include <ti/drv/emac/soc/emac_soc_v5.h>
#include <ti/drv/emac/src/v5/emac_mdio.h>
#include <ti/drv/emac/src/emac_osal.h>
#include "ti/drv/emac/emac_ioctl.h"

uint32_t gRxDropCounter = 0;
uint32_t gRxDropCounterNoRxAppAllocFail = 0;
uint32_t gTxDropCounter = 0;
uint32_t gTxCounter = 0;

#define EMAC_ALE_THREAD_DEF_REG     ((uint32_t)0x0003E134U)

#define EMAC_ICSSG_TX_STATS_OFFSET  ((uint32_t)40U)

#define EMAC__RX_PKT_CHAN ((uint32_t)(1U))
#define EMAC_RX_MGMT_CHAN ((uint32_t)(2U))
#define EMAC_RX_MGMT2_CHAN ((uint32_t)(3U))

#define EMAC_RX_RING_MGMT_PSI_RESPONSE ((uint32_t)(1U))
#define EMAC_RX_RING_TX_TS_RESPONSE ((uint32_t)(2U))
#define EMAC_MIN_PKT_SIZE ((uint32_t)(60U))

extern EMAC_IOCTL_CMD_T cmd1Icssg;
extern EMAC_IOCTL_CMD_T cmd2Icssg;

extern void emac_hw_mem_write(uint32_t addr, const void *ptr, uint32_t element_count);

/**********************************************************************
 *************************** EMAC Global Variables*********************
 **********************************************************************/
EMAC_MCB_V5_T      emac_mcb;

/* EMAC_v5 local functions */
static EMAC_DRV_ERR_E
EMAC_get_cpsw_stats(CSL_Xge_cpswRegs *hCpswRegs,EMAC_STATISTICS_T*      p_stats);

/* EMAC v5 private/helper functions */
int32_t
emac_udma_ring_dequeue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T     **pHostDescriptor
);

EMAC_DRV_ERR_E
emac_udma_ring_enqueue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T *pHostDescriptor,
    uint32_t packetSize
);

static void
emac_rx_free_push
(
   uint32_t port_num,
   uint32_t size,
   physptr_t phys,
   uint32_t ringNum,
   Udma_RingHandle rxRingHandle
);
static void
emac_tx_ready_push
(
    uint32_t port_num,
    uint32_t size,
    physptr_t phys,
    uint32_t ringNum,
    Udma_RingHandle rxRingHandle
);

static EMAC_DRV_ERR_E
emac_setup_tx_subsystem (uint32_t                 port_num,
                        EMAC_OPEN_CONFIG_INFO_T *p_config,
                        EMAC_HwAttrs_V5         *hwAttrs);

static int32_t
emac_close_tx_subsystem (uint32_t                 port_num);

static EMAC_DRV_ERR_E
emac_setup_rx_subsystem (uint32_t                 port_num,
                        EMAC_OPEN_CONFIG_INFO_T *p_config,
                        EMAC_HwAttrs_V5         *hwAttrs);
static int32_t
emac_close_rx_subsystem (uint32_t                 port_num);

static EMAC_DRV_ERR_E
emac_open_v5_local(uint32_t port_num, uint32_t virt_port_num, EMAC_OPEN_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E
emac_close_v5_local(uint32_t port_num);

static int32_t
emac_open_udma_channel_tx(uint32_t portNum, EMAC_PER_CHANNEL_CFG_TX*pChCfg);

static int32_t
emac_setup_udma_channel_rx(uint32_t portNum,EMAC_PER_CHANNEL_CFG_RX* pChCfg, uint32_t channelType, EMAC_CHANNEL_RX_T* pRxChannel);

static void
emac_poll_tx_ts_resp(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum);


static void
emac_poll_rx_pkts(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum);

static void
emac_poll_mgmt_pkts(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum);


static void
emac_poll_tx_complete(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum);

static void
emac_icssg_update_link_params(uint32_t port_num, uint32_t virt_port_num,  EMAC_LINK_INFO_T *pLinkInfo);

void EMAC_rxIsrFxn(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData);

void EMAC_rxMgmtIsrFxn(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData);

void emac_icssg_switch_eth_setup (uint32_t portNum);

void emac_configure_link_speed_duplexity(uint32_t port_num, uint32_t val);

/* EMAC_v5 API functions */
static EMAC_DRV_ERR_E EMAC_open_v5(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E  EMAC_config_v5(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E EMAC_close_v5(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_poll_pkt_v5(uint32_t port_num);


static EMAC_DRV_ERR_E EMAC_send_v5(uint32_t port_num, EMAC_PKT_DESC_T* p_desc);

static  EMAC_DRV_ERR_E EMAC_poll_v5(uint32_t port_num, EMAC_LINK_INFO_T* p_info);

static EMAC_DRV_ERR_E EMAC_get_stats_v5(uint32_t port_num, EMAC_STATISTICS_T*      p_stats);

static EMAC_DRV_ERR_E EMAC_get_stats_icssg_v5(uint32_t port_num, EMAC_STATISTICS_ICSSG_T *p_stats, bool clear);

static EMAC_DRV_ERR_E EMAC_ioctl_v5(uint32_t port_num, EMAC_IOCTL_CMD emacIoctlCmd, EMAC_IOCTL_PARAMS *emacIoctlParams);

static EMAC_DRV_ERR_E EMAC_poll_ctrl_v5(uint32_t port_num, uint32_t rxPktRings, uint32_t rxMgmtRings, uint32_t txRings);

/* EMAC function table for EMAC_v5 implementation */
const EMAC_FxnTable EMAC_FxnTable_v5 =
{
    EMAC_open_v5,
    EMAC_config_v5,
    EMAC_close_v5,
    EMAC_send_v5,
    EMAC_poll_v5,
    EMAC_get_stats_v5,
    EMAC_poll_pkt_v5,
    EMAC_get_stats_icssg_v5,
    EMAC_ioctl_v5, 
    EMAC_poll_ctrl_v5
};

#if defined (EMAC_INCOHERENT)
static inline void emac_cache_alignment_wb_inv(void *ptr, uint32_t len)
{
    uintptr_t p = (uintptr_t)ptr;
    uint32_t delta;

    delta = p & 0x3f;
    p &= ~0x3f;

    len += delta;

    delta = len & 0x3f;
    if (delta) {
      delta = 64 - delta;
    }  /* else len already aligned */
  

    len += delta;
    ptr = (void *)p;
    EMAC_osalCacheWbInv(ptr, len);
}

static inline void emac_cache_alignment_inv(void *ptr, uint32_t len)
{
    uintptr_t p = (uintptr_t)ptr;
    uint32_t delta;

    delta = p & 0x3f;
    p &= ~0x3f;

    len += delta;

    delta = len & 0x3f;
    if (delta) {
      delta = 64 - delta;
    }  /* else len already aligned */
  
    len += delta;
    ptr = (void *)p;
    EMAC_osalCacheInv(ptr, len);
}
#endif

/*
 *  ======== emac_udma_ring_enqueue ========
 */
EMAC_DRV_ERR_E
emac_udma_ring_enqueue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T *pHostDescriptor,
    uint32_t            packetSize
)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
#if defined (EMAC_INCOHERENT)
    void *virtBufPtr;
#endif
    physptr_t  physDescPtr;
    if (ringHandle == NULL)
    {
        retVal = EMAC_DRV_RESULT_ERR_UDMA_RING_ENQUEUE;
    }
    if (retVal == EMAC_DRV_RESULT_OK)
    {
#if defined (EMAC_INCOHERENT)
        virtBufPtr = (void *)(uintptr_t)pHostDescriptor->hostDesc.bufPtr;
#endif

        pHostDescriptor->hostDesc.bufPtr = Emac_osalVirtToPhys ((void *)(uintptr_t)pHostDescriptor->hostDesc.bufPtr);
        pHostDescriptor->hostDesc.orgBufPtr = Emac_osalVirtToPhys ((void *)(uintptr_t)pHostDescriptor->hostDesc.orgBufPtr);
        physDescPtr = (uint64_t) Emac_osalVirtToPhys ((void *)&pHostDescriptor->hostDesc);

#if defined (EMAC_INCOHERENT)
            /* Wb Invdata cache */
        emac_cache_alignment_wb_inv(virtBufPtr, packetSize);
        emac_cache_alignment_wb_inv((void *)&pHostDescriptor->hostDesc, sizeof(*pHostDescriptor));
#endif

        if (Udma_ringQueueRaw(ringHandle,(uint64_t)physDescPtr) != 0)
        {
            retVal = EMAC_DRV_RESULT_ERR_UDMA_RING_ENQUEUE;
        }
    }
    return retVal;
} /* emac_udma_ring_enqueue */


/*
 *  ======== emac_udma_ring_dequeue ========
 */
int32_t
emac_udma_ring_dequeue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T **pHostDescriptor
)
{
    uint64_t pDesc = 0;
    EMAC_CPPI_DESC_T *pVirtHostDesc;

    if ((pHostDescriptor == NULL) || (ringHandle == NULL))
    {
        return -1;
    }
    Udma_ringDequeueRaw(ringHandle,&pDesc);
    if(pDesc == 0)
     {
        *pHostDescriptor = NULL;
    }
    else
    {
        *pHostDescriptor = pVirtHostDesc = (EMAC_CPPI_DESC_T *)Emac_osalPhysToVirt (pDesc);

#if defined (EMAC_INCOHERENT)
        emac_cache_alignment_inv((void *) pVirtHostDesc, sizeof(EMAC_CPPI_DESC_T));
#endif
        pVirtHostDesc->hostDesc.bufPtr = (uint64_t)Emac_osalPhysToVirt
        (pVirtHostDesc->hostDesc.bufPtr);
        pVirtHostDesc->hostDesc.orgBufPtr = (uint64_t)Emac_osalPhysToVirt
        (pVirtHostDesc->hostDesc.orgBufPtr);

#if defined (EMAC_INCOHERENT)
        uint32_t    pktsize  = CSL_FEXT (pVirtHostDesc->hostDesc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN);
        emac_cache_alignment_inv((void *)(uintptr_t)pVirtHostDesc->hostDesc.bufPtr, (int32_t)pktsize);
#endif
    }

    return 0;
} /* emac_ring_pop */
void emac_setup_cpsw_ss(uint32_t portNum)
{
    CSL_CPSW_PORTSTAT portStatEnable;
    CSL_CPSW_ALE_PORTCONTROL portCtrl;
    CSL_Xge_cpswRegs *hCpswRegs;
    CSL_AleRegs *hCpswAleRegs;
    CSL_CPSW_ALE_POLICER_GLOB_CONFIG policerGblCfg;

#ifdef EMAC_DEBUG
     uint32_t returnVal;
#endif
    hCpswRegs = emac_mcb.port_cb[portNum].hCpswRegs;
    hCpswAleRegs = emac_mcb.port_cb[portNum].hCpswAleRegs;

    /*CPSW2U  Host port0 & Mac port1 Statistics Enable configuration */
    memset(&portStatEnable, 0, sizeof(CSL_CPSW_PORTSTAT));
    portStatEnable.p0StatEnable = 1U;
    portStatEnable.p1StatEnable = 1U;
    CSL_CPSW_setPortStatsEnableReg (hCpswRegs,&portStatEnable);

    /* ALE Configuration */
    CSL_CPSW_enableAle(hCpswAleRegs);

#ifdef EMAC_DEBUG
    returnVal = CSL_CPSW_isAleEnabled(hCpswAleRegs);
#endif
    CSL_CPSW_enableAleBypass(hCpswAleRegs);

#ifdef EMAC_DEBUG
    uint32_t ale;
    /* Wait for some time to check */
    for(ale = 0; ale < 100; ale++);
    returnVal = CSL_CPSW_isAleBypassEnabled(hCpswAleRegs);
#endif

    /*Enable packet forwarding on all ports */
    memset(&portCtrl, 0, sizeof(CSL_CPSW_ALE_PORTCONTROL));
    portCtrl.portState = CSL_ALE_PORTSTATE_FORWARD;
    CSL_CPSW_setAlePortControlReg(hCpswAleRegs,0U, &portCtrl);
    CSL_CPSW_setAlePortControlReg(hCpswAleRegs,1U, &portCtrl);
    /* CPGMAC configuration */
    CSL_CPGMAC_SL_enableFullDuplex(hCpswRegs,0);
    if (EMAC_CFG_LOOPBACK(portNum))
    {
        CSL_CPGMAC_SL_enableLoopback(hCpswRegs,0);
    }
    CSL_CPGMAC_SL_enableGMII(hCpswRegs,0);
    CSL_CPGMAC_SL_enableGigabit(hCpswRegs,0);
    CSL_CPGMAC_SL_enableGigForceMode(hCpswRegs,0);

    /* Setting MAX RX length to 2016 */
    CSL_CPSW_setPortRxMaxLen(hCpswRegs,0,0x7E0);
    CSL_CPSW_setPortRxMaxLen(hCpswRegs,1,0x7E0);

    /* Setup Thread Map Register for flow configuration*/
    policerGblCfg.defThreadEnable = 1;
    policerGblCfg.defThread = emac_mcb.port_cb[portNum].rxPktCh.rxChHandle->defaultFlowObj.flowStart;
    CSL_CPSW_setAlePolicerGlobConfig(emac_mcb.port_cb[portNum].hCpswAleRegs,&policerGblCfg);

    /* Enable Host port 0 */
    CSL_CPSW_enablePort0(hCpswRegs);

}

/*
 *  ======== emac_cppi5InitHostDescQueue ========
 */
void
emac_cppi5InitHostDescQueue( uint32_t portNum, uint32_t retqIdx, uint32_t descCnt,
                    uint32_t descSize, void* descPool, uint32_t ringNum,
                    Udma_RingHandle ringHandle, void (*pfPush)(uint32_t, uint32_t, physptr_t,
                    uint32_t, Udma_RingHandle))
{
    CSL_UdmapCppi5HMPD *pHpd;
    uint32_t        i;
    uint32_t descType;

    if( descSize == 0U)
    {
        descSize = sizeof(CSL_UdmapCppi5HMPD);   /* Use default size of descriptor if descSize==0 */
    }
    pHpd   = (CSL_UdmapCppi5HMPD *)descPool;
    if (descCnt != 0)
    {
        memset (pHpd, 0, descCnt * descSize);

        for(i=0; i<descCnt; i++)
        {
            descType = (uint32_t)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
            CSL_udmapCppi5SetDescType(pHpd, descType);
            CSL_udmapCppi5SetReturnPolicy(
                                pHpd,
                                descType,
                                CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,
                                CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_VAL_NO,
                                CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
                                retqIdx);
            CSL_udmapCppi5SetOrgBufferAddr(pHpd, (uint64_t) pHpd->bufPtr);

            pfPush(portNum, 0, Emac_osalVirtToPhys(pHpd), ringNum, ringHandle );
            pHpd = (CSL_UdmapCppi5HMPD *)(((uint8_t *)pHpd) + descSize);
        }
    }
} /* my_cppi5InitHostDescQueue */

static volatile uint32_t emac_rx_free_push_errors = 0;

/*
 *  ======== emac_rx_free_push ========
 */
static void
emac_rx_free_push
(
    uint32_t port_num,
    uint32_t size,
    physptr_t phys,
    uint32_t ringNum,
    Udma_RingHandle rxRingHandle
)
{
    EMAC_CPPI_DESC_T *pCppiDesc = (EMAC_CPPI_DESC_T *)Emac_osalPhysToVirt (phys);
    EMAC_PKT_DESC_T  *p_rx_pkt_desc;


    /* Allocate the PKT */
    if ((p_rx_pkt_desc = EMAC_ALLOC_PKT(port_num, EMAC_PKT_SIZE(port_num))) != NULL)
    {
        /* Populate the Rx free descriptor with the buffer we just allocated. */
        pCppiDesc->appPtr             = p_rx_pkt_desc;
        pCppiDesc->hostDesc.bufPtr    = (uint64_t)p_rx_pkt_desc->pDataBuffer;
        pCppiDesc->hostDesc.orgBufPtr = (uint64_t)p_rx_pkt_desc->pDataBuffer;
        pCppiDesc->hostDesc.orgBufLen = p_rx_pkt_desc->BufferLen;
        pCppiDesc->hostDesc.bufInfo1  = p_rx_pkt_desc->BufferLen;
        /* Push descriptor to Rx free queue */

        emac_udma_ring_enqueue (rxRingHandle,
                                pCppiDesc,
                                pCppiDesc->hostDesc.orgBufLen);
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: RX pkt allocation error during free ring setup",port_num);
        emac_rx_free_push_errors |= (1u << port_num);
    }
}

/*
 *  ======== emac_tx_ready_push ========
 */
static void
emac_tx_ready_push
(
   uint32_t port_num,
   uint32_t size,
   physptr_t phys,
   uint32_t ringNum,
   Udma_RingHandle ringHandle
)
{
    EMAC_CPPI_DESC_T *pCppiDesc = (EMAC_CPPI_DESC_T *)Emac_osalPhysToVirt (phys);

    pCppiDesc->nextPtr = emac_mcb.port_cb[port_num].txReadyDescs[ringNum];
    emac_mcb.port_cb[port_num].txReadyDescs[ringNum] = pCppiDesc;
} /* emac_tx_ready_push */

/*
 *  ======== emac_open_udma_channel_tx ========
 */
static int32_t
emac_open_udma_channel_tx(uint32_t portNum,EMAC_PER_CHANNEL_CFG_TX*pChCfg)
{
    int32_t retVal = EMAC_DRV_RESULT_OK;
    Udma_ChPrms chPrms;
    Udma_ChTxPrms txPrms;

    /* TX channel parameters */
    UdmaChPrms_init(&chPrms, UDMA_CH_TYPE_TX);
    chPrms.peerChNum            = pChCfg->threadId;
    chPrms.fqRingPrms.ringMem   = pChCfg->freeRingMem;
    chPrms.fqRingPrms.elemCnt   = pChCfg->elementCount;

    chPrms.cqRingPrms.ringMem   = pChCfg->compRingMem;
    chPrms.cqRingPrms.elemCnt   = pChCfg->elementCount;

    /* Open TX channel for transmit */
    retVal = Udma_chOpen(emac_mcb.port_cb[portNum].udmaHandle, (Udma_ChHandle)(pChCfg->chHandle), UDMA_CH_TYPE_TX, &chPrms);

    if(UDMA_SOK == retVal)
    {
        UdmaChTxPrms_init(&txPrms, UDMA_CH_TYPE_TX);
        txPrms.filterPsWords = TISCI_MSG_VALUE_RM_UDMAP_TX_CH_FILT_PSWORDS_ENABLED;
        txPrms.dmaPriority = UDMA_DEFAULT_UTC_CH_DMA_PRIORITY;
        retVal = Udma_chConfigTx((Udma_ChHandle)(pChCfg->chHandle), &txPrms);
        if(UDMA_SOK == retVal)
        {
            retVal = Udma_chEnable((Udma_ChHandle)(pChCfg->chHandle));
            if (UDMA_SOK == retVal)
            {
                retVal =  EMAC_DRV_RESULT_OK;
            }
        }
        else
        {
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA TX channel config error",portNum);
            retVal = EMAC_DRV_RESULT_ERR_UDMA_TX_CHAN_SETUP;
        }
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA TX channel open error",portNum);
        retVal = EMAC_DRV_RESULT_ERR_UDMA_TX_CHAN_SETUP;
    }
    return retVal;
}

/*
 *  ======== emac_setup_udma_channel_interrupt ========
 */
static int32_t
emac_setup_udma_channel_interrupt(uint32_t portNum, EMAC_PER_CHANNEL_CFG_RX*pChCfg, uint32_t eventType, EMAC_CHANNEL_RX_T* pRxChannel)
{
    uintptr_t intArg = 0;
    uintptr_t temp = 0;
    int32_t retVal = EMAC_DRV_RESULT_OK;
    Udma_EventHandle eventHandle;
    Udma_EventPrms eventPrms;
    SemaphoreP_Params semParams;
    uint32_t ringNum= 0;
    intArg =  ringNum;
    temp = portNum << 16;
    intArg = intArg | temp;
    /* Register ring completion callback */
    eventHandle = (Udma_EventHandle)(pChCfg->subChan[ringNum].eventHandle);

    UdmaEventPrms_init(&eventPrms);
    eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
    eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
    eventPrms.chHandle          = (Udma_ChHandle)(pChCfg->chHandle);
    eventPrms.masterEventHandle = NULL;

    pRxChannel->subChan[0].eventHandle = eventHandle;

    if (eventType == EMAC__RX_PKT_CHAN)
    {
        eventPrms.eventCb = EMAC_rxIsrFxn;
    }
    else
    {
        eventPrms.eventCb = EMAC_rxMgmtIsrFxn;
    }

    eventPrms.appData           = (void *)intArg;
    retVal = Udma_eventRegister(emac_mcb.port_cb[portNum].udmaHandle, eventHandle, &eventPrms);
    if (retVal == UDMA_SOK)
    {
        EMAC_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        semParams.name= (char*)("rxSemaphore");
        if (eventType == EMAC__RX_PKT_CHAN)
        {
            semParams.name= (char*)("rxSemaphore");
            EMAC_GLOBAL_RX_SEM_HANDLE(portNum, ringNum) =  EMAC_osalCreateBlockingLock(0,&semParams);
            if((EMAC_GLOBAL_RX_SEM_HANDLE(portNum, ringNum)) ==  NULL)
            {
                retVal =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
            }
        }
        else
        {
            semParams.name= (char*)("rxMgmtSemaphore");
            EMAC_GLOBAL_RX_MGMT_SEM_HANDLE(portNum, ringNum) =  EMAC_osalCreateBlockingLock(0,&semParams);
            if((EMAC_GLOBAL_RX_MGMT_SEM_HANDLE(portNum, ringNum)) ==  NULL)
            {
                retVal =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
            }
        }

    }
    return retVal;
}

/*
 *  ======== emac_setup_additional_flows ========
 */
static int32_t 
emac_setup_additional_flows(uint32_t portNum, EMAC_PER_CHANNEL_CFG_RX*pChCfg, uint32_t channelType, EMAC_CHANNEL_RX_T* pRxChannel)
{
    Udma_RingHandle freeRingHandle, completionRingHandle;
    Udma_FlowPrms flowPrms;
    Udma_RingPrms ringPrms;
    uint32_t subChanNum;
    int32_t retVal = EMAC_DRV_RESULT_OK;
    if (pChCfg->nsubChan > 1)
    {
        /* First allocate flow */
        pRxChannel->flowHandle = (Udma_FlowHandle)pChCfg->flowHandle;
        retVal = Udma_flowAlloc(emac_mcb.port_cb[portNum].udmaHandle,pRxChannel->flowHandle, pChCfg->nsubChan -1);
        if (retVal == 0)
        {
            /* subChan 0 is the default flow, start with subChan 1 for additinal flows*/
            for (subChanNum = 1; subChanNum < pChCfg->nsubChan;subChanNum++)
            {
                 freeRingHandle = (Udma_RingHandle)(pChCfg->subChan[subChanNum].freeRingHandle[0]);
                 completionRingHandle = (Udma_RingHandle)(pChCfg->subChan[subChanNum].compRingHandle);
 
                if (channelType == EMAC__RX_PKT_CHAN)
                {
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[subChanNum].freeRingHandle = freeRingHandle;
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[subChanNum].compRingHandle= completionRingHandle;
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[subChanNum].ringPollFxn =emac_poll_rx_pkts;
                    emac_mcb.port_cb[portNum].rxPktCh.subChan[subChanNum].freeRingMem[0] = pChCfg->subChan[subChanNum].freeRingMem[0];
                    emac_mcb.port_cb[portNum].rxPktCh.subChan[subChanNum].compRingMem = pChCfg->subChan[subChanNum].compRingMem;
                }
                else if (channelType == EMAC_RX_MGMT_CHAN)
                {
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[subChanNum].freeRingHandle = freeRingHandle;
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[subChanNum].compRingHandle= completionRingHandle;
                    emac_mcb.port_cb[portNum].rxMgmtCh.subChan[subChanNum].freeRingMem[0] = pChCfg->subChan[subChanNum].freeRingMem[0];
                    emac_mcb.port_cb[portNum].rxMgmtCh.subChan[subChanNum].compRingMem = pChCfg->subChan[subChanNum].compRingMem;
                }

                UdmaRingPrms_init(&ringPrms);
                ringPrms.elemCnt =  pChCfg->subChan[subChanNum].elementCountFree[0];
                ringPrms.elemSize = UDMA_RING_ES_8BYTES;
                ringPrms.ringMem = pChCfg->subChan[subChanNum].freeRingMem[0];
                /* need to allocate rxfree/rxcompletion ring pair */
                retVal = Udma_ringAlloc(emac_mcb.port_cb[portNum].udmaHandle,freeRingHandle,UDMA_RING_ANY, &ringPrms);
                if (retVal == 0)
                {
                    UdmaRingPrms_init(&ringPrms);
                    ringPrms.elemCnt =  pChCfg->subChan[subChanNum].elementCountCompletion;
                    ringPrms.elemSize = UDMA_RING_ES_8BYTES;
                    ringPrms.ringMem = pChCfg->subChan[subChanNum].compRingMem;
                    retVal = Udma_ringAlloc(emac_mcb.port_cb[portNum].udmaHandle,
                                            completionRingHandle,
                                            UDMA_RING_ANY,
                                            &ringPrms);
                    if (retVal == 0)
                    {
                        memset(&flowPrms, 0, sizeof(Udma_FlowPrms));
                        UdmaFlowPrms_init(&flowPrms, UDMA_CH_TYPE_RX);
                        flowPrms.psInfoPresent = 1U;
                        flowPrms.defaultRxCQ = completionRingHandle->ringNum;
                        flowPrms.fdq0Sz0Qnum    = freeRingHandle->ringNum;
                        flowPrms.fdq0Sz1Qnum    = freeRingHandle->ringNum;
                        flowPrms.fdq0Sz2Qnum    = freeRingHandle->ringNum;
                        flowPrms.fdq0Sz3Qnum    = freeRingHandle->ringNum;
                        flowPrms.fdq1Qnum       = freeRingHandle->ringNum;
                        flowPrms.fdq2Qnum       = freeRingHandle->ringNum;
                        flowPrms.fdq3Qnum       = freeRingHandle->ringNum;
                        retVal = Udma_flowConfig(pRxChannel->flowHandle,(subChanNum  -1), &flowPrms);
                        if (retVal == EMAC_DRV_RESULT_OK)
                        {
                            emac_cppi5InitHostDescQueue(portNum,
                                        0,
                                        emac_mcb.port_cb[portNum].num_of_rx_pkt_desc,
                                        EMAC_CPPI_DESC_SIZE,
                                        pChCfg->subChan[subChanNum].hPdMem[0],
                                        freeRingHandle->ringNum,
                                        freeRingHandle,
                                        emac_rx_free_push);
                        }
                        else
                        {
                            UTILS_trace(UTIL_TRACE_LEVEL_ERR,emac_mcb.drv_trace_cb, "port: %d: UDMA flow config error",portNum);
                            retVal = EMAC_DRV_RESULT_ERR_UDMA_FLOW_SETUP;
                            break;
                        }
                        /* setup the flow */
                    }
                    else
                    {
                        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb,  "port: %d: UDMA ring alloc error",portNum);
                        retVal = EMAC_DRV_RESULT_ERR_UDMA_FLOW_SETUP;
                        break;
                    }
                    /* now setup the flow */
                }
                else
                {
                    UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb,  "port: %d: UDMA ring alloc error",portNum);
                    retVal = EMAC_DRV_RESULT_ERR_UDMA_FLOW_SETUP;
                    break;
                }
            }
        }
        else
        {
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb,  "port: %d: UDMA flow alloc error",portNum);
            retVal = EMAC_DRV_RESULT_ERR_UDMA_FLOW_SETUP;
        }
    }
    return retVal;
}

/*
 *  ======== emac_setup_udma_channel_rx ========
 */
static int32_t
emac_setup_udma_channel_rx(uint32_t portNum,EMAC_PER_CHANNEL_CFG_RX* pChCfg, uint32_t channelType, EMAC_CHANNEL_RX_T* pRxChannel)
{
    int32_t retVal = EMAC_DRV_RESULT_OK;
    Udma_ChPrms chPrms;
    Udma_ChRxPrms rxPrms;
    Udma_FlowHandle flowHandle;
    Udma_FlowPrms flowParams;
    Udma_ChHandle chHandle;
    uint32_t regVal;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",portNum);
    chHandle = (Udma_ChHandle)(pChCfg->chHandle);

    if (pChCfg->nsubChan > 0)
    {
        retVal = emac_setup_additional_flows(portNum, pChCfg, channelType, pRxChannel);
        if (retVal == EMAC_DRV_RESULT_OK)
        {
            /* RX channel parameters */
            UdmaChPrms_init(&chPrms, UDMA_CH_TYPE_RX);
            chPrms.peerChNum            = pChCfg->threadId;
            /* subChan[0] is default flow */
            chPrms.fqRingPrms.ringMem   = pChCfg->subChan[0].freeRingMem[0];
            chPrms.fqRingPrms.elemCnt   = pChCfg->subChan[0].elementCountFree[0];
            chPrms.fqRingPrms.mode =  CSL_RINGACC_RING_MODE_MESSAGE;
            chPrms.cqRingPrms.ringMem   = pChCfg->subChan[0].compRingMem;
            chPrms.cqRingPrms.elemCnt   = pChCfg->subChan[0].elementCountCompletion;

            /* Open RX channel for receive with default flow */
            retVal = Udma_chOpen(emac_mcb.port_cb[portNum].udmaHandle, chHandle, UDMA_CH_TYPE_RX, &chPrms);
            if(UDMA_SOK == retVal)
            {
                UdmaChRxPrms_init(&rxPrms, UDMA_CH_TYPE_RX);
                rxPrms.dmaPriority = UDMA_DEFAULT_RX_CH_DMA_PRIORITY; 
                
                /* only need to update channel config with additional flow if more than 1 sub channel/flow */
                if (pChCfg->nsubChan > 1)
                {
                    rxPrms.flowIdFwRangeStart = Udma_flowGetNum(pRxChannel->flowHandle);
                    rxPrms.flowIdFwRangeCnt = pChCfg->nsubChan -1;
                    rxPrms.configDefaultFlow = FALSE;
                }
                retVal = Udma_chConfigRx(chHandle, &rxPrms);
                if(UDMA_SOK == retVal)
                {
                    /* need to enable RX timestamping, psInfoPresent flag set to 1 */
                    flowHandle = Udma_chGetDefaultFlowHandle(chHandle);
                    if(NULL == flowHandle)
                    {
                        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb,  "port: %d: UDMA default flow handle is NULL error",portNum);
                        retVal = EMAC_DRV_RESULT_ERR_UDMA_RX_CHAN_SETUP;
                    }
                    else
                    {
                        memset(&flowParams, 0, sizeof(Udma_FlowPrms));
                        UdmaFlowPrms_init(&flowParams, UDMA_CH_TYPE_RX);
                        flowParams.rxChHandle = chHandle;
                        flowParams.psInfoPresent = 1U;
                        flowParams.defaultRxCQ = chHandle->cqRing->ringNum;
                        flowParams.fdq0Sz0Qnum    = chHandle->fqRing->ringNum;
                        flowParams.fdq0Sz1Qnum    = chHandle->fqRing->ringNum;
                        flowParams.fdq0Sz2Qnum    = chHandle->fqRing->ringNum;
                        flowParams.fdq0Sz3Qnum    = chHandle->fqRing->ringNum;
                        flowParams.fdq1Qnum       = chHandle->fqRing->ringNum;
                        flowParams.fdq2Qnum       = chHandle->fqRing->ringNum;
                        flowParams.fdq3Qnum       = chHandle->fqRing->ringNum;

                        retVal = Udma_flowConfig(flowHandle, 0, &flowParams);
                        if (UDMA_SOK != retVal)
                        {
                            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA RX flow config error",portNum);
                            retVal = EMAC_DRV_RESULT_ERR_UDMA_RX_CHAN_SETUP;
                        }
                    }
                }
                else
                {
                    UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA RX channel config error",portNum);
                    retVal = EMAC_DRV_RESULT_ERR_UDMA_RX_CHAN_SETUP;
                }
            }
            else
            {
                UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA RX channel open error",portNum);
                retVal = EMAC_DRV_RESULT_ERR_UDMA_RX_CHAN_SETUP;
            }
        
            if(retVal == UDMA_SOK)
            {
                if (emac_mcb.port_cb[portNum].mode_of_operation == EMAC_MODE_INTERRUPT)
                {
                    retVal = emac_setup_udma_channel_interrupt(portNum, pChCfg,channelType , pRxChannel);
                }

                if ((retVal == EMAC_DRV_RESULT_OK) && (portNum == EMAC_CPSW_PORT_NUM))
                {
                    regVal = 0U;
                    regVal = 1U << CSL_ALE_THREADMAPDEF_DEFTHREAD_EN_SHIFT;
                    regVal = regVal | (chHandle->defaultFlowObj.flowStart << CSL_ALE_THREADMAPDEF_DEFTHREADVAL_SHIFT);
                    /* Setup Thread Map Register for flow configuration*/
                    CSL_REG32_WR((CSL_MCU_CPSW0_NUSS_BASE + EMAC_ALE_THREAD_DEF_REG), regVal);
                }
                if (retVal == EMAC_DRV_RESULT_OK)
                {
                    emac_cppi5InitHostDescQueue(portNum,
                                            0,
                                            emac_mcb.port_cb[portNum].num_of_rx_pkt_desc,
                                            EMAC_CPPI_DESC_SIZE,
                                            pChCfg->subChan[0].hPdMem[0],
                                            chHandle->fqRing->ringNum,
                                            chHandle->fqRing,
                                            emac_rx_free_push);
                    if ((emac_rx_free_push_errors & (1u << portNum)) != 0)
                    {
                        retVal = EMAC_DRV_RESULT_NO_MEM_AVAIL;
                    }
                }
            }
            if (retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = Udma_chEnable(chHandle);
                /* update the free and completion ring handle for default flow in mcb */
                if (channelType == EMAC__RX_PKT_CHAN)
                {
                    emac_mcb.port_cb[portNum].rxPktCh.subChan[0].freeRingMem[0] = pChCfg->subChan[0].freeRingMem[0];
                    emac_mcb.port_cb[portNum].rxPktCh.subChan[0].compRingMem = pChCfg->subChan[0].compRingMem;
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[0].compRingHandle = Udma_chGetCqRingHandle(emac_mcb.port_cb[portNum].rxPktCh.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[0].freeRingHandle = Udma_chGetFqRingHandle(emac_mcb.port_cb[portNum].rxPktCh.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxPkt[0].ringPollFxn =emac_poll_rx_pkts;
                }
                else if (channelType == EMAC_RX_MGMT_CHAN)
                {
                    emac_mcb.port_cb[portNum].rxMgmtCh.subChan[0].freeRingMem[0] = pChCfg->subChan[0].freeRingMem[0];
                    emac_mcb.port_cb[portNum].rxMgmtCh.subChan[0].compRingMem = pChCfg->subChan[0].compRingMem;
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[0].compRingHandle = Udma_chGetCqRingHandle(emac_mcb.port_cb[portNum].rxMgmtCh.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[0].freeRingHandle = Udma_chGetFqRingHandle(emac_mcb.port_cb[portNum].rxMgmtCh.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_TX_TS_RESPONSE].ringPollFxn = emac_poll_tx_ts_resp;
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_MGMT_PSI_RESPONSE].ringPollFxn = emac_poll_mgmt_pkts;
                }
                else
                {
                    emac_mcb.port_cb[portNum].rxMgmtCh2.subChan[0].freeRingMem[0] = pChCfg->subChan[0].freeRingMem[0];
                    emac_mcb.port_cb[portNum].rxMgmtCh2.subChan[0].compRingMem = pChCfg->subChan[0].compRingMem;
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_TX_TS_RESPONSE].compRingHandle = Udma_chGetCqRingHandle(emac_mcb.port_cb[portNum].rxMgmtCh2.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_TX_TS_RESPONSE].freeRingHandle = Udma_chGetFqRingHandle(emac_mcb.port_cb[portNum].rxMgmtCh2.rxChHandle);
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_TX_TS_RESPONSE].ringPollFxn = emac_poll_tx_ts_resp;
                    emac_mcb.port_cb[portNum].pollTable.rxMgmt[EMAC_RX_RING_MGMT_PSI_RESPONSE].ringPollFxn = emac_poll_mgmt_pkts;
                }
            }
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d", portNum, retVal);
    return retVal;
}

/*
 *  ======== EMAC_rxIsrFxn ========
 */
void EMAC_rxIsrFxn(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData)
{
    uint32_t port_num;
    uint32_t ringNum = 0;

    uintptr_t intArg = (uintptr_t)appData;
    port_num = (intArg  & 0xFFFF0000U  )>> 16U;
    ringNum = intArg & 0x0000FFFFU;
    EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num, ringNum));
}


/*
 *  ======== EMAC_rxMgmtIsrFxn ========
 */
void EMAC_rxMgmtIsrFxn(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData)
{
    uint32_t port_num;
    uint32_t ringNum = 0;

    uintptr_t intArg = (uintptr_t)appData;
    port_num = (intArg  & 0xFFFF0000U  )>> 16U;
    ringNum = intArg & 0x0000FFFFU;
    EMAC_osalPostLock(EMAC_GLOBAL_RX_MGMT_SEM_HANDLE(port_num, ringNum));
}

/*
 *  ======== emac_setup_tx_subsystem ========
 */
static EMAC_DRV_ERR_E
emac_setup_tx_subsystem (uint32_t                 port_num,
                        EMAC_OPEN_CONFIG_INFO_T *p_config,
                        EMAC_HwAttrs_V5         *hwAttrs)
{
    int32_t retVal = EMAC_DRV_RESULT_OK;
    int32_t chanNum;
    Udma_ChHandle txChHandle;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    emac_mcb.port_cb[port_num].numTxChans = hwAttrs->portCfg[port_num].nTxChans;
    for (chanNum = 0; chanNum < hwAttrs->portCfg[port_num].nTxChans; chanNum++)
    {
        txChHandle = (Udma_ChHandle)(hwAttrs->portCfg[port_num].txChannel[chanNum].chHandle);
        emac_mcb.port_cb[port_num].txChHandle[chanNum] = txChHandle;
        retVal = emac_open_udma_channel_tx(port_num,
                                &(hwAttrs->portCfg[port_num].txChannel[chanNum]));
        if (retVal == EMAC_DRV_RESULT_OK)
        {
            emac_mcb.port_cb[port_num].pollTable.txCompletion[chanNum].ringPollFxn = emac_poll_tx_complete;
            emac_mcb.port_cb[port_num].pollTable.txCompletion[chanNum].compRingHandle =txChHandle->cqRing;

            emac_mcb.port_cb[port_num].txReadyDescs[chanNum] = NULL;
            emac_cppi5InitHostDescQueue(port_num,
                                      txChHandle->cqRing->ringNum,
                                      p_config->num_of_tx_pkt_desc,
                                      EMAC_CPPI_DESC_SIZE,
                                      hwAttrs->portCfg[port_num].txChannel[chanNum].hPdMem,
                                      chanNum,
                                      NULL,
                                      emac_tx_ready_push);
        }
        else
        {
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: UDMA TX channel open error", port_num);
            break;
        }
    }
    /* All done with Tx configuration. Return success. */
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",
                                            port_num, retVal);

    return (EMAC_DRV_ERR_E)retVal;
} /* emac_setup_tx_subsystem */

/*
 *  ======== emac_close_tx_subsystem ========
 */
static int32_t
emac_close_tx_subsystem (uint32_t port_num)
{
    EMAC_CPPI_DESC_T *pCppiDesc;
    uint32_t chanNum;
    Udma_ChHandle txChHandle;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    for (chanNum = 0; chanNum < emac_mcb.port_cb[port_num].numTxChans;chanNum++)
    {
        txChHandle = emac_mcb.port_cb[port_num].txChHandle[chanNum];
        /* Lets free back resources to the application prior to resetting the rings */
        do
        {
            /* Go through the TX Completion queue */
            pCppiDesc = NULL;
            if ((emac_udma_ring_dequeue (Udma_chGetCqRingHandle(txChHandle), &pCppiDesc)) == 0)
            {
                if (pCppiDesc)
                {
                    EMAC_FREE_PKT(port_num, pCppiDesc->appPtr);
                    pCppiDesc->nextPtr =  emac_mcb.port_cb[port_num].txReadyDescs[chanNum];
                    emac_mcb.port_cb[port_num].txReadyDescs[chanNum] = pCppiDesc;
                }
            }
        } while (pCppiDesc != NULL);

        emac_mcb.port_cb[port_num].txReadyDescs[chanNum] = NULL;
        Udma_chClose(txChHandle);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);
    return 0;
}

/*
 *  ======== emac_setup_rx_subsystem ========
 */
static EMAC_DRV_ERR_E
emac_setup_rx_subsystem (uint32_t port_num,
                                  EMAC_OPEN_CONFIG_INFO_T *p_config,
                                  EMAC_HwAttrs_V5         *hwAttrs)
{
    int32_t retVal = EMAC_DRV_RESULT_OK;
    Udma_ChHandle rxChHandle;
    Udma_ChHandle rxMgmtChHandle;
    Udma_ChHandle rxMgmt2ChHandle;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    rxChHandle = (Udma_ChHandle)(hwAttrs->portCfg[port_num].rxChannel.chHandle);
    emac_mcb.port_cb[port_num].rxPktCh.rxChHandle= rxChHandle;
    emac_mcb.port_cb[port_num].rxPktCh.nsubChan = hwAttrs->portCfg[port_num].rxChannel.nsubChan;
    if (port_num == EMAC_CPSW_PORT_NUM)
    {
        /* Initialize CPSW base address */
        emac_mcb.port_cb[port_num].hCpswRegs = (CSL_Xge_cpswRegs *)
            (hwAttrs->portCfg[port_num].cpswSSRegsBaseAddr + CPSW_NU_OFFSET);
        emac_mcb.port_cb[port_num].hCpswAleRegs = (CSL_AleRegs *)
            (hwAttrs->portCfg[port_num].cpswSSRegsBaseAddr + CPSW_ALE_OFFSET);
    }
    /* Setup UDMA RX channel for data packets */
    retVal = emac_setup_udma_channel_rx(port_num,
                            &(hwAttrs->portCfg[port_num].rxChannel),
                            EMAC__RX_PKT_CHAN,
                            &emac_mcb.port_cb[port_num].rxPktCh);

    if((retVal == EMAC_DRV_RESULT_OK) && (port_num != EMAC_CPSW_PORT_NUM))
    {
        /* Setup UDMA RX channel for rx config responses over PSI for ICSSG only*/
        rxMgmtChHandle = (Udma_ChHandle)(hwAttrs->portCfg[port_num].rxChannelCfgOverPSI.chHandle);
        emac_mcb.port_cb[port_num].rxMgmtCh.nsubChan = hwAttrs->portCfg[port_num].rxChannelCfgOverPSI.nsubChan;
        emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle= rxMgmtChHandle;
        retVal = emac_setup_udma_channel_rx(port_num,
                                 &(hwAttrs->portCfg[port_num].rxChannelCfgOverPSI),
                                 EMAC_RX_MGMT_CHAN,
                                 &emac_mcb.port_cb[port_num].rxMgmtCh);
        if((retVal == EMAC_DRV_RESULT_OK) && (hwAttrs->portCfg[port_num].rxChannel2CfgOverPSI.chHandle))
        {
            /* Setup UDMA RX channel for rx config responses over PSI for ICSSG only*/
            rxMgmt2ChHandle = (Udma_ChHandle)(hwAttrs->portCfg[port_num].rxChannel2CfgOverPSI.chHandle);
            emac_mcb.port_cb[port_num].rxMgmtCh2.nsubChan = hwAttrs->portCfg[port_num].rxChannel2CfgOverPSI.nsubChan;
            emac_mcb.port_cb[port_num].rxMgmtCh2.rxChHandle= rxMgmt2ChHandle;
            retVal = emac_setup_udma_channel_rx(port_num,
                                 &(hwAttrs->portCfg[port_num].rxChannel2CfgOverPSI),
                                 EMAC_RX_MGMT2_CHAN,
                                 &emac_mcb.port_cb[port_num].rxMgmtCh2);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",
                                            port_num, retVal);
    return (EMAC_DRV_ERR_E)retVal;
} /* emac_setup_rx_subsystem */

/*
 *  ======== emac_free_ring_desc========
 */
static void
emac_cleanup_comp_ring (uint32_t port_num, Udma_RingHandle ringHandle)
{
    EMAC_CPPI_DESC_T *pCppiDesc;

    do
    {
        /* Go through the Rx Completion queue */
        pCppiDesc = NULL;
        if ((emac_udma_ring_dequeue (ringHandle, &pCppiDesc)) == 0)
        {
            if (pCppiDesc)
            {
                EMAC_FREE_PKT(port_num, pCppiDesc->appPtr);
                pCppiDesc->nextPtr = NULL;
            }
        }
    } while (pCppiDesc != NULL);

}

/*
 *  ======== emac_cleanup_free_ring ========
 */
void emac_cleanup_free_ring(uint32_t portNum, uint64_t *pRingMem)
{
    uint32_t descNum;
    EMAC_CPPI_DESC_T *pCppiDesc;

    if (pRingMem)
    {
        /* free all the packet descriptors back to the application */
        for (descNum = 0; descNum < emac_mcb.port_cb[portNum].num_of_rx_pkt_desc;descNum++)
        {
            pCppiDesc = (EMAC_CPPI_DESC_T*)(uintptr_t)pRingMem[descNum];
            EMAC_FREE_PKT(portNum, pCppiDesc->appPtr);
        }
    }
}

/*
 *  ======== emac_close_rx_subsystem ========
 */

static int32_t
emac_close_rx_subsystem (uint32_t port_num)
{
    uint32_t subChanNum ;
    Udma_RingHandle ringHandle = NULL;

    uint32_t numSubChan;

    subChanNum = 0;
    if (emac_mcb.port_cb[port_num].mode_of_operation == EMAC_MODE_INTERRUPT)
    {
        EMAC_osalDeleteBlockingLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num, subChanNum));
        Udma_eventUnRegister((Udma_EventHandle)(emac_mcb.port_cb[port_num].rxPktCh.subChan[subChanNum].eventHandle));
        if (port_num != EMAC_CPSW_PORT_NUM)
        {
            EMAC_osalDeleteBlockingLock(EMAC_GLOBAL_RX_MGMT_SEM_HANDLE(port_num, subChanNum));
            Udma_eventUnRegister((Udma_EventHandle)(emac_mcb.port_cb[port_num].rxMgmtCh.subChan[subChanNum].eventHandle));
        }
    }

    /* free up resources for rx packet channel and sub-channels */
    if (emac_mcb.port_cb[port_num].rxPktCh.rxChHandle)
    {
        Udma_chClose(emac_mcb.port_cb[port_num].rxPktCh.rxChHandle);
        emac_cleanup_comp_ring(port_num, emac_mcb.port_cb[port_num].rxPktCh.rxChHandle->cqRing);
        emac_cleanup_free_ring(port_num, (uint64_t *)(emac_mcb.port_cb[port_num].rxPktCh.subChan[0].freeRingMem[0]));
        numSubChan = emac_mcb.port_cb[port_num].rxPktCh.nsubChan;
        if (numSubChan > 1)
        {
            Udma_flowFree(emac_mcb.port_cb[port_num].rxPktCh.flowHandle);
            for(subChanNum = 1; subChanNum < numSubChan;subChanNum++)
            {
                ringHandle = emac_mcb.port_cb[port_num].pollTable.rxPkt[subChanNum].compRingHandle;
                emac_cleanup_comp_ring(port_num, ringHandle);
                Udma_ringFree(ringHandle);

                ringHandle = emac_mcb.port_cb[port_num].pollTable.rxPkt[subChanNum].freeRingHandle;
                emac_cleanup_free_ring(port_num, (uint64_t *)(emac_mcb.port_cb[port_num].rxPktCh.subChan[subChanNum].freeRingMem[0]));
                Udma_ringFree(ringHandle);
            }
        }
    }

    /* free up resources for rx mgmt channel2, this has no sub-channels*/
    if (emac_mcb.port_cb[port_num].rxMgmtCh2.rxChHandle)
    {
        Udma_chClose(emac_mcb.port_cb[port_num].rxMgmtCh2.rxChHandle);
        emac_cleanup_free_ring(port_num, (uint64_t *)(emac_mcb.port_cb[port_num].rxMgmtCh2.subChan[0].freeRingMem[0]));
    }

    /* free up resources for rx mgmt channel and sub-channels */
    if (emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle)
    {
        Udma_chClose(emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle);
        emac_cleanup_comp_ring(port_num, emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle->cqRing);
        emac_cleanup_free_ring(port_num, (uint64_t *)(emac_mcb.port_cb[port_num].rxMgmtCh.subChan[0].freeRingMem[0]));
        numSubChan = emac_mcb.port_cb[port_num].rxMgmtCh.nsubChan;
        if (numSubChan > 1)
        {
            Udma_flowFree(emac_mcb.port_cb[port_num].rxMgmtCh.flowHandle);
            for(subChanNum = 1;subChanNum < numSubChan;subChanNum++)
            {
                ringHandle = emac_mcb.port_cb[port_num].pollTable.rxMgmt[subChanNum].compRingHandle;
                emac_cleanup_comp_ring(port_num, ringHandle);
                Udma_ringFree(ringHandle);
    
                ringHandle = emac_mcb.port_cb[port_num].pollTable.rxMgmt[subChanNum].freeRingHandle;
                emac_cleanup_free_ring(port_num, (uint64_t *)(emac_mcb.port_cb[port_num].rxMgmtCh.subChan[subChanNum].freeRingMem[0]));
                Udma_ringFree(ringHandle);
            }
        }
    }

    return 0;
}

/*
 *  ======== emac_interposer_setup ========
 */
static EMAC_DRV_ERR_E emac_interposer_setup(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_OPEN_CONFIG_INFO_T openCfg;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_HwAttrs_V5 *hwAttrs = (EMAC_HwAttrs_V5*)p_config->hwAttrs;

    memset(&openCfg, 0, sizeof(EMAC_OPEN_CONFIG_INFO_T));
    memcpy(&openCfg, p_config, sizeof(EMAC_OPEN_CONFIG_INFO_T));

    if ((port_num == 3U) || (port_num == 1U))
    {
        /* lets setup TX port for interposer card config */
        openCfg.num_of_rx_pkt_desc = 0;
        retVal = emac_open_v5_local(port_num, port_num, &openCfg);
    }
    if ((port_num == 2U) || (port_num == 0))
    {
        /* lets setup RX port for interposer card config */
        openCfg.num_of_tx_pkt_desc = 0;
        hwAttrs->portCfg[port_num].nTxChans = 0;
        EMAC_socSetInitCfg(0, hwAttrs);
        retVal = emac_open_v5_local(port_num, port_num, &openCfg);
    }
    return retVal;
}

/*
 *  ======== emac_interposer_setup_switch ========
 */
static EMAC_DRV_ERR_E emac_interposer_setup_switch(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_OPEN_CONFIG_INFO_T openCfg;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_HwAttrs_V5 *hwAttrs = (EMAC_HwAttrs_V5*)p_config->hwAttrs;

    memset(&openCfg, 0, sizeof(EMAC_OPEN_CONFIG_INFO_T));
    memcpy(&openCfg, p_config, sizeof(EMAC_OPEN_CONFIG_INFO_T));

    if ((port_num == 3U) || (port_num == 1U))
    {
        /* Ports 3 and 1 are not used for DMA transactions with Firmware*/
        openCfg.num_of_rx_pkt_desc = 0;
        openCfg.num_of_tx_pkt_desc = 0;
        hwAttrs->portCfg[port_num].nTxChans = 0;
        EMAC_socSetInitCfg(0, hwAttrs);
        retVal = emac_open_v5_local(port_num, EMAC_SWITCH_PORT,&openCfg);
    }
    /* Ports 2 and 0 are  used for DMA transactions with Firmware */
    if ((port_num == 2U) || (port_num == 0))
    {
        /* lets setup RX port for interposer card config */
        EMAC_socSetInitCfg(0, hwAttrs);
        retVal = emac_open_v5_local(port_num,EMAC_SWITCH_PORT, &openCfg);
    }

    return retVal;
}

/*
 *  ======== emac_config_icssg_dual_mac_fw ========
 */
static void emac_config_icssg_dual_mac_fw(uint32_t port_num, EMAC_HwAttrs_V5 *hwAttrs, uint8_t* macAddr)
{
    uint32_t bufferPoolNum;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_PRU_CFG_T pruCfg;
    Udma_FlowHandle flowHandle;
    Udma_ChHandle chHandle;
    EMAC_ICSSG_DUALMAC_FW_CFG *pDmFwCfg;
    uint64_t seed;
    uint32_t temp;
    uint32_t regVal;

    /* work-around to use PG1.0 firmware on J7 for bringup */
#ifdef SOC_J721E
    uintptr_t addr;
    uint32_t tempVal = 0;

    emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr = hwAttrs->portCfg[port_num].icssgCfgRegBaseAddr;

    /* turn off early rx-eof feature (on by default) */
    addr = emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr + 0x30;// 0xb033030
    emac_hw_mem_write(addr, (void*) &tempVal, 1);
    /* turn off rx max frm cnt feature */
    addr = CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_BASE + 0x4C;// 0xb03204c
    tempVal = 0x1;
    emac_hw_mem_write(addr, (void*) &tempVal, 1);
    addr = CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_BASE + 0x48;// 0xb03204c
    emac_hw_mem_write(addr, (void*) &tempVal, 1);
    
#endif

    /* Set CORE_CLK as the source of CORE_IEP_CLK (sync mode)*/
    regVal = CSL_REG32_RD (emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSSCFG_REGS_BASE +CSL_ICSSCFG_IEPCLK);
    regVal |= 0x1U << CSL_ICSSCFG_IEPCLK_OCP_EN_SHIFT;
    CSL_REG32_WR (emac_mcb.port_cb[port_num].icssDram0BaseAddr +
                CSL_ICSSCFG_REGS_BASE + CSL_ICSSCFG_IEPCLK,
                regVal);

    /* Set internal CORE_CLK to be ICSSGn_ICLK (250Mhz) */
    regVal = CSL_REG32_RD (emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSSCFG_REGS_BASE +CSL_ICSSCFG_CORE_SYNC_REG);
    regVal |= 0x1U << CSL_ICSSCFG_CORE_SYNC_REG_CORE_VBUSP_SYNC_EN_SHIFT;
    CSL_REG32_WR (emac_mcb.port_cb[port_num].icssDram0BaseAddr +
                CSL_ICSSCFG_REGS_BASE +CSL_ICSSCFG_CORE_SYNC_REG,
                regVal);

    memset(&pruCfg, 0, sizeof(EMAC_PRU_CFG_T));
    if (hwAttrs->portCfg[port_num].getFwCfg)
    {
        hwAttrs->portCfg[port_num].getFwCfg(port_num,&pEmacFwCfg);
        pDmFwCfg = (EMAC_ICSSG_DUALMAC_FW_CFG*)pEmacFwCfg->pFwPortCfg;
        pruCfg.addr_lo = pEmacFwCfg->fwAppCfg.txPortQueueLowAddr;
        pruCfg.addr_hi = pEmacFwCfg->fwAppCfg.txPortQueueHighAddr;

        /*  flow for rx packet. if only 1 subChan use default flow */
        if (emac_mcb.port_cb[port_num].rxPktCh.nsubChan > 1)
        {
            pruCfg.def_flow = Udma_flowGetNum(emac_mcb.port_cb[port_num].rxPktCh.flowHandle);
        }
        else
        {
            chHandle = emac_mcb.port_cb[port_num].rxPktCh.rxChHandle;
            flowHandle = Udma_chGetDefaultFlowHandle(chHandle);
            pruCfg.def_flow= Udma_flowGetNum( flowHandle);
        }
        /* Flow for rx config mgmt. 1 subChan use default flow */
        if (emac_mcb.port_cb[port_num].rxMgmtCh.nsubChan > 1)
        {
            pruCfg.mgr_flow = Udma_flowGetNum(emac_mcb.port_cb[port_num].rxMgmtCh.flowHandle);
        }
        else
        {
            chHandle = emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle;
            flowHandle = Udma_chGetDefaultFlowHandle(chHandle);
            pruCfg.mgr_flow= Udma_flowGetNum( flowHandle);
        }

        /* Reading time to generate seed for random generator, used by FW to calculate backoff retransmission time for half duplex mode */
        seed = TimerP_getTimeInUsecs();
        pruCfg.seed = (uint32_t)((uint32_t)(seed) & (uint32_t)(0xFFFFFFFFU));
        /* xor with unique mac to ensure unique seed */
        temp = macAddr[2] << 24 | macAddr[3] << 16 | macAddr[4] << 8 | macAddr[5];
        pruCfg.seed ^= temp;

        for (bufferPoolNum = 8U; bufferPoolNum < EMAC_NUM_TRANSMIT_FW_QUEUES*2;bufferPoolNum++)
        {
            pruCfg.tx_bs[bufferPoolNum] = pDmFwCfg->txHostQueueSize[bufferPoolNum-8U];
        }
    
        emac_hw_mem_write(hwAttrs->portCfg[port_num].icssSharedRamBaseAddr, &(pruCfg),(sizeof(EMAC_PRU_CFG_T)/4));
    }
}

EMAC_TX_QUEUE_CONTEXT host_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT port_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT host_egress_q_msmc_context[EMAC_NUM_HOST_EGRESS_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT host_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT port_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT host_egress_q_desc_context[EMAC_NUM_HOST_EGRESS_FW_QUEUES];


/*
 *  ======== emac_config_icssg_switch_fw========
 */
static EMAC_DRV_ERR_E emac_config_icssg_switch_fw(uint32_t port_num, EMAC_HwAttrs_V5 *hwAttrs)
{
    uint8_t queue_num;
    uint32_t smem_offset;
    uint32_t start_of_host_Q_offset;
    uint32_t start_of_host_egress_Q_offset;
    uint32_t sMemBase;
    uint32_t txPortQBaseAddr;
    uint32_t smem_offset_start_host_Q_context;
    uint32_t smem_offset_start_host_egress_Q_context;
    uint32_t smem_offset_start_port_desc_Q_context;
    uint32_t smem_offset_start_host_desc_Q_context;
    uint32_t smem_offset_start_host_egress_desc_Q_context;
    uint32_t start_of_port_desc_Q_offset;
    uint32_t start_of_host_desc_Q_offset;
    uint32_t start_of_host_egress_desc_Q_offset;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    Udma_FlowHandle flowHandle;
    Udma_ChHandle chHandle;
    uint32_t flowIdBase;
    uint32_t descQueueSize;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    emac_icssg_switch_eth_setup(port_num);

    hwAttrs->portCfg[port_num].getFwCfg(port_num,&pEmacFwCfg);

    pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*)pEmacFwCfg->pFwPortCfg;
    txPortQBaseAddr = pEmacFwCfg->fwAppCfg.txPortQueueLowAddr;

    if((port_num & 1) ==0)
    {
        sMemBase = hwAttrs->portCfg[port_num].icssSharedRamBaseAddr;
        /* write context for all Port queues to SMEM */
        for(queue_num = 0; queue_num < EMAC_NUM_TRANSMIT_FW_QUEUES; queue_num++)
        {
            port_tx_q_msmc_context[queue_num].start_addr = txPortQBaseAddr + 
                                                        ((pSwitchFwCfg->txPortQueueSize[queue_num]+ pSwitchFwCfg->mtuSize)* queue_num);
            port_tx_q_msmc_context[queue_num].rd_ptr = port_tx_q_msmc_context[queue_num].start_addr;
            port_tx_q_msmc_context[queue_num].wr_ptr = port_tx_q_msmc_context[queue_num].start_addr;
            port_tx_q_msmc_context[queue_num].end_addr = port_tx_q_msmc_context[queue_num].start_addr +
                                                            pSwitchFwCfg->txPortQueueSize[queue_num] +
                                                            pSwitchFwCfg->mtuSize;
            smem_offset = sMemBase + pSwitchFwCfg->queueContextOffset+ EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num;
            emac_hw_mem_write (smem_offset, &(port_tx_q_msmc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
            emac_hw_mem_write (hwAttrs->portCfg[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->startOfPortQueueReadPtrsOffset + 4*queue_num, &(port_tx_q_msmc_context[queue_num].rd_ptr),1);
        }

        /* write context for all Host port queues to SMEM */
        smem_offset_start_host_Q_context = smem_offset + EMAC_NRT_QUEUE_CONTEXT_SIZE;
        start_of_host_Q_offset = port_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES-1].end_addr;
        for(queue_num = 0; queue_num < EMAC_NUM_TRANSMIT_FW_QUEUES; queue_num++)
        {
            host_tx_q_msmc_context[queue_num].start_addr = start_of_host_Q_offset + ((pSwitchFwCfg->txHostQueueSize[queue_num] + pSwitchFwCfg->mtuSize) * queue_num);
            host_tx_q_msmc_context[queue_num].rd_ptr = host_tx_q_msmc_context[queue_num].start_addr;
            host_tx_q_msmc_context[queue_num].wr_ptr = host_tx_q_msmc_context[queue_num].start_addr;
            host_tx_q_msmc_context[queue_num].end_addr = host_tx_q_msmc_context[queue_num].start_addr + pSwitchFwCfg->txHostQueueSize[queue_num] + pSwitchFwCfg->mtuSize;
            smem_offset = smem_offset_start_host_Q_context + EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num;
            emac_hw_mem_write (smem_offset, &(host_tx_q_msmc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
            emac_hw_mem_write (hwAttrs->portCfg[port_num].icssSharedRamBaseAddr + (pSwitchFwCfg->startOfPortQueueReadPtrsOffset +EMAC_NUM_TRANSMIT_FW_QUEUES*4)  + 4*queue_num, &(host_tx_q_msmc_context[queue_num].rd_ptr),1);
        }

        smem_offset_start_host_egress_Q_context = smem_offset + EMAC_NRT_QUEUE_CONTEXT_SIZE;
        start_of_host_egress_Q_offset = host_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES-1].end_addr;
        /* write context for all host host_egress queues */
        for(queue_num = 0; queue_num < 2; queue_num++)
        {
            host_egress_q_msmc_context[queue_num].start_addr = start_of_host_egress_Q_offset + ((pSwitchFwCfg->txPortQueueSize[queue_num] +  pSwitchFwCfg->mtuSize) * queue_num);
            host_egress_q_msmc_context[queue_num].rd_ptr = host_egress_q_msmc_context[queue_num].start_addr;
            host_egress_q_msmc_context[queue_num].wr_ptr = host_egress_q_msmc_context[queue_num].start_addr;
            host_egress_q_msmc_context[queue_num].end_addr = host_egress_q_msmc_context[queue_num].start_addr + pSwitchFwCfg->txPortQueueSize[queue_num] +  pSwitchFwCfg->mtuSize;

            smem_offset = smem_offset_start_host_egress_Q_context + EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num;
            emac_hw_mem_write (smem_offset, &(host_egress_q_msmc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
        }

        /* need size check to make sure memory for port queue is big enough */
        if ((host_egress_q_msmc_context[1].end_addr - txPortQBaseAddr) > pEmacFwCfg->fwAppCfg.txPortQueueSize)
        {
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: allocated port queue size memory is too small",port_num);
            retVal = EMAC_DRV_RESULT_TX_PORT_QUEUE_SIZE_ERR;
        }

        if (retVal == EMAC_DRV_RESULT_OK)
        {
            /* write context for all Port descriptor queues to SMEM */
            smem_offset_start_port_desc_Q_context = smem_offset + EMAC_NRT_QUEUE_CONTEXT_SIZE;
            start_of_port_desc_Q_offset = pSwitchFwCfg->descQueueOffset;
            for(queue_num = 0; queue_num < EMAC_NUM_TRANSMIT_FW_QUEUES; queue_num++) 
            {
                descQueueSize = pSwitchFwCfg->txPortQueueDescSize;
                port_tx_q_desc_context[queue_num].start_addr = start_of_port_desc_Q_offset + descQueueSize * queue_num;
                port_tx_q_desc_context[queue_num].rd_ptr = port_tx_q_desc_context[queue_num].start_addr;
                port_tx_q_desc_context[queue_num].wr_ptr = port_tx_q_desc_context[queue_num].start_addr;
                port_tx_q_desc_context[queue_num].end_addr = port_tx_q_desc_context[queue_num].start_addr + descQueueSize;
                smem_offset = smem_offset_start_port_desc_Q_context +  EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num;
                emac_hw_mem_write (smem_offset, &(port_tx_q_desc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
            }
    
            /* write context for all Host descriptor queues to SMEM */
            smem_offset_start_host_desc_Q_context = smem_offset + EMAC_NRT_QUEUE_CONTEXT_SIZE;
            start_of_host_desc_Q_offset = port_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES-1].end_addr;
            for(queue_num = 0; queue_num < EMAC_NUM_TRANSMIT_FW_QUEUES; queue_num++) 
            {
                descQueueSize = pSwitchFwCfg->txHostQueueDescSize;
                host_tx_q_desc_context[queue_num].start_addr = start_of_host_desc_Q_offset + descQueueSize * queue_num;
                host_tx_q_desc_context[queue_num].rd_ptr = host_tx_q_desc_context[queue_num].start_addr;
                host_tx_q_desc_context[queue_num].wr_ptr = host_tx_q_desc_context[queue_num].start_addr;
                host_tx_q_desc_context[queue_num].end_addr = host_tx_q_desc_context[queue_num].start_addr+ descQueueSize ;
                smem_offset = smem_offset_start_host_desc_Q_context + EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num; 
                emac_hw_mem_write (smem_offset, &(host_tx_q_desc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
            }
    
            /* write context for all Host egress descriptor queues to SMEM */
            smem_offset_start_host_egress_desc_Q_context = smem_offset + EMAC_NRT_QUEUE_CONTEXT_SIZE;
            start_of_host_egress_desc_Q_offset = host_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES-1].end_addr;
            for(queue_num = 0; queue_num < EMAC_NUM_HOST_EGRESS_FW_QUEUES; queue_num++) 
            {
                descQueueSize = pSwitchFwCfg->txPortQueueDescSize;
                host_egress_q_desc_context[queue_num].start_addr = start_of_host_egress_desc_Q_offset + descQueueSize * queue_num;
                host_egress_q_desc_context[queue_num].rd_ptr = host_egress_q_desc_context[queue_num].start_addr;
                host_egress_q_desc_context[queue_num].wr_ptr = host_egress_q_desc_context[queue_num].start_addr;
                host_egress_q_desc_context[queue_num].end_addr = host_egress_q_desc_context[queue_num].start_addr+ descQueueSize ;
                smem_offset = smem_offset_start_host_egress_desc_Q_context + EMAC_NRT_QUEUE_CONTEXT_SIZE * queue_num; 
                emac_hw_mem_write (smem_offset, &(host_egress_q_desc_context[queue_num]), (sizeof(EMAC_TX_QUEUE_CONTEXT)/sizeof(uint32_t)));
            }

            /* write pkt flow Id start to SMEM */
            smem_offset = hwAttrs->portCfg[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->pktFlowIdOffset;
    
            /* Flow for rx pkt. 1 subChan use default flow */
            if (emac_mcb.port_cb[port_num].rxPktCh.nsubChan > 1)
            {
                flowIdBase = Udma_flowGetNum(emac_mcb.port_cb[port_num].rxPktCh.flowHandle);
            }
            else
            {
                chHandle = emac_mcb.port_cb[port_num].rxPktCh.rxChHandle;
                flowHandle = Udma_chGetDefaultFlowHandle(chHandle);
                flowIdBase= Udma_flowGetNum( flowHandle);
            }
    
            /* Flow for rx mgmt, 1 subChan use default flow */
            if (emac_mcb.port_cb[port_num].rxMgmtCh.nsubChan > 1)
            {
                flowIdBase |= (Udma_flowGetNum(emac_mcb.port_cb[port_num].rxMgmtCh.flowHandle) << 16);
            }
            else
            {
                chHandle = emac_mcb.port_cb[port_num].rxMgmtCh.rxChHandle;
                flowHandle = Udma_chGetDefaultFlowHandle(chHandle);
                flowIdBase |= Udma_flowGetNum( flowHandle) << 16;
            }
            emac_hw_mem_write (smem_offset, &(flowIdBase), 1);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",
                                            port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_open_v5_local ========
 */
static EMAC_DRV_ERR_E  emac_open_v5_local(uint32_t port_num, uint32_t virt_port_num, EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_HwAttrs_V5       *hwAttrs;
    uint32_t regId;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OPEN_PORT_ERR;

    if (p_config != NULL)
    {
        hwAttrs = (EMAC_HwAttrs_V5*)p_config->hwAttrs;

        /* Initialize EMAC MCB when opening a port */
        memset (&emac_mcb.port_cb[port_num], 0, sizeof(EMAC_PORT_CB_V5_T));
        emac_mcb.drv_trace_cb = NULL;

        /* register trace callback if provided */
        if (p_config->drv_trace_cb)
        {
            emac_mcb.drv_trace_cb = p_config->drv_trace_cb;
        }

        UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

        /* Input parameter validation */
        if ((p_config->num_of_chans == 0U)                  ||
            (p_config->p_chan_mac_addr == NULL)             ||
            (p_config->rx_pkt_cb == NULL)                   ||
            (p_config->alloc_pkt_cb == NULL)                ||
            (p_config->free_pkt_cb == NULL) ||
            ((virt_port_num != EMAC_CPSW_PORT_NUM) && (hwAttrs->portCfg[port_num].getFwCfg == NULL)))
        {
            UTILS_trace(UTIL_TRACE_LEVEL_ERR,emac_mcb.drv_trace_cb,"port: %d: invalid params", port_num);
            retVal = EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
        else
        {
            emac_mcb.port_cb[port_num].udmaHandle = (Udma_DrvHandle)p_config->udmaHandle;
            emac_mcb.port_cb[port_num].mode_of_operation = p_config->mode_of_operation;
            if (p_config->master_core_flag)
            {
                emac_mcb.ioctl_cb.pCmd1Icssg = &cmd1Icssg;
                emac_mcb.ioctl_cb.pCmd2Icssg = &cmd2Icssg;
                uint32_t size = p_config->max_pkt_size;
                uint32_t rem = size % 4;
                if (rem != 0)
                {
                    size += 4-rem;
                }
                EMAC_PKT_SIZE(port_num) = size;
                memcpy(&emac_mcb.port_cb[port_num].macaddr_cfg.addr, p_config->p_chan_mac_addr->p_mac_addr, sizeof(EMAC_MAC_ADDR_T));
                emac_mcb.port_cb[port_num].loop_back = p_config->loop_back;
            }

            EMAC_MASTER_CORE(port_num)              = p_config->master_core_flag;
            EMAC_NUM_RX_PKTS(port_num)              = p_config->num_of_rx_pkt_desc;
            EMAC_NUM_TX_PKTS(port_num)              = p_config->num_of_tx_pkt_desc;
            EMAC_NUM_TXRX_PKTS(port_num)            = p_config->num_of_tx_pkt_desc + p_config->num_of_rx_pkt_desc;
            EMAC_CFG_LOOPBACK(port_num)             = p_config->loop_back;

            /* Intialize the call back function pointers in EMAC MCB */
            emac_mcb.port_cb[port_num].rx_pkt_cb      =     p_config->rx_pkt_cb;
            emac_mcb.port_cb[port_num].alloc_pkt_cb   =     p_config->alloc_pkt_cb;
            emac_mcb.port_cb[port_num].free_pkt_cb    =     p_config->free_pkt_cb;
            emac_mcb.port_cb[port_num].rx_mgmt_response_cb = p_config->rx_mgmt_response_cb;
            emac_mcb.port_cb[port_num].tx_ts_cb= p_config->tx_ts_cb;

            /* Setup Tx */
            if ((retVal = emac_setup_tx_subsystem (port_num, p_config, hwAttrs)) != EMAC_DRV_RESULT_OK)
            {
                return retVal;
            }

            /* Setup Rx */
            if ((retVal = emac_setup_rx_subsystem (port_num, p_config, hwAttrs)) != EMAC_DRV_RESULT_OK)
            {
                return retVal;
            }

            if (port_num == EMAC_CPSW_PORT_NUM)
            {
                emac_setup_cpsw_ss(port_num);
            }
            else
            {
                emac_mcb.port_cb[port_num].getFwCfg= hwAttrs->portCfg[port_num].getFwCfg;
                emac_mcb.port_cb[port_num].icssSharedRamBaseAddr = hwAttrs->portCfg[port_num].icssSharedRamBaseAddr;
                emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr = hwAttrs->portCfg[port_num].icssgCfgRegBaseAddr;
                emac_mcb.port_cb[port_num].icssDram0BaseAddr = hwAttrs->portCfg[port_num].icssDram0BaseAddr;
                emac_mcb.port_cb[port_num].icssDram1BaseAddr = hwAttrs->portCfg[port_num].icssDram1BaseAddr;

                /* disable all classifiers */
                emac_classifier_disable(port_num);
                /* lets configure the switch firmware based on switch port */
                if (virt_port_num== EMAC_SWITCH_PORT)
                {
                    if ((retVal = emac_config_icssg_switch_fw(port_num, hwAttrs)) != EMAC_DRV_RESULT_OK)
                    {
                        return retVal;
                    }
                    emac_switch_vlan_init(port_num, p_config);
                    emac_switch_config_ft3_priority_tag(port_num);
                }
                else
                {
                    emac_config_icssg_dual_mac_fw(port_num, hwAttrs, p_config->p_chan_mac_addr->p_mac_addr->addr);
                    /* Update classifier/filters for PORT_MAC address */
                    emac_ioctl_icss_add_mac(port_num,p_config->p_chan_mac_addr->p_mac_addr->addr);
                }
            }

            if (hwAttrs->portCfg[port_num].phyAddr > EMAC_MAX_NUM_PHY_ADDR)
            {
                UTILS_trace(UTIL_TRACE_LEVEL_ERR,emac_mcb.drv_trace_cb,"port: %d: invalid phy address: %d",
                port_num, hwAttrs->portCfg[port_num].phyAddr);
                return EMAC_DRV_RESULT_ERR_INVALID_PHY_ADDR;
            }

            /* need to figure out the instNum, for icss-g, there are 2 ports using the same MDIO IP block, 
                port 0,2,4,6 are part of  USERGROUP0 and USER PHY0 and will use  index 0,
                port 1,3,5 are part of  USERGROUP1 and USER PHY1 and will use  index 1
            */
            if ((port_num % 2U) == 0)
            {
                regId = 0U;
            }
            else
            {
                regId = 1U;
            }
            emac_mcb.port_cb[port_num].MdioDev.mdioBaseAddr = (uint32_t)(hwAttrs->portCfg[port_num].mdioRegsBaseAddr);
            emac_mcb.port_cb[port_num].mdio_flag = p_config->mdio_flag;
            EMAC_mdioOpen(port_num, regId, hwAttrs->portCfg[port_num].phyAddr, &emac_mcb.port_cb[port_num].MdioDev);
            emac_mcb.port_cb[port_num].emacState =EMAC_PORT_STATE_OPEN;

            UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",
                                                    port_num, retVal);
        }
    }
    return retVal;
}

/*
 *  ======== EMAC_open_v5 ========
 */
static EMAC_DRV_ERR_E  EMAC_open_v5(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;

    switch (port_num)
     {
        case EMAC_INTERPOSER_PORT0:
            retVal = emac_interposer_setup(0, p_config);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_interposer_setup(3, p_config);
            }
            break;
        case EMAC_INTERPOSER_PORT1:
            retVal = emac_interposer_setup(2U, p_config);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_interposer_setup(1U, p_config);
            }
            break;
        case EMAC_SWITCH_PORT:
            retVal = emac_interposer_setup_switch(0U, p_config);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_interposer_setup_switch(1U, p_config);
                if(retVal == EMAC_DRV_RESULT_OK)
                {
                    retVal = emac_interposer_setup_switch(2U, p_config);
                    if(retVal == EMAC_DRV_RESULT_OK)
                    {
                        retVal = emac_interposer_setup_switch(3U, p_config);
                    }
                }
            }
            break;
        default:
            if (port_num < EMAC_MAX_PORTS)
            {
                retVal = emac_open_v5_local(port_num,port_num, p_config);
            }
            else
            {
                retVal = EMAC_DRV_RESULT_INVALID_PORT;
            }
            break;
    }
    return retVal;
} /* EMAC_open_v5 */


/*
 *  ======== EMAC_config_v5 ========
 */
static EMAC_DRV_ERR_E  EMAC_config_v5(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config)
{
    return EMAC_DRV_RESULT_OK;
} /* EMAC_config_v5 */

/*
 *  ======== EMAC_close_v5_local ========
 */
static EMAC_DRV_ERR_E emac_close_v5_local( uint32_t port_num)
{
    uint32_t ringNum = 0;
    emac_mcb.port_cb[port_num].emacState = EMAC_PORT_STATE_CLOSED;
    if (emac_mcb.port_cb[port_num].mode_of_operation == EMAC_MODE_INTERRUPT)
    {
        EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num, ringNum));
        if(port_num != EMAC_CPSW_PORT_NUM)
        {
            EMAC_osalPostLock(EMAC_GLOBAL_RX_MGMT_SEM_HANDLE(port_num, ringNum));
        }
    }
    emac_close_tx_subsystem(port_num);
    emac_close_rx_subsystem(port_num);
    return EMAC_DRV_RESULT_OK;
}

/*
 *  ======== EMAC_close_v5 ========
 */
static EMAC_DRV_ERR_E  EMAC_close_v5(uint32_t port_num)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;

    switch (port_num)
     {
        case EMAC_INTERPOSER_PORT0:
            retVal = emac_close_v5_local(0);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_close_v5_local(3);
            }
            break;
        case EMAC_INTERPOSER_PORT1:
            retVal = emac_close_v5_local(2U);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_close_v5_local(1U);
            }
            break;
        case EMAC_SWITCH_PORT:
            retVal = emac_close_v5_local(0U);
            if(retVal == EMAC_DRV_RESULT_OK)
            {
                retVal = emac_close_v5_local(1U);
                if(retVal == EMAC_DRV_RESULT_OK)
                {
                    retVal = emac_close_v5_local(2U);
                    if(retVal == EMAC_DRV_RESULT_OK)
                    {
                        retVal = emac_close_v5_local(3U);
                    }
                }
            }
            break;
        default:
            if (port_num < EMAC_MAX_PORTS)
            {
                retVal = emac_close_v5_local(port_num);
            }
            else
            {
                retVal = EMAC_DRV_RESULT_INVALID_PORT;
            }
            break;
    }
    return retVal;
} /* EMAC_open_v5 */

/*
 *  ======== EMAC_get_stats_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_get_stats_v5(uint32_t port_num, EMAC_STATISTICS_T*      p_stats)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
    if (p_stats)
    {
        if (port_num == EMAC_CPSW_PORT_NUM)
        {
            retVal = EMAC_get_cpsw_stats(emac_mcb.port_cb[port_num].hCpswRegs, p_stats);
        }
        else
        {
            retVal = EMAC_DRV_RESULT_INVALID_PORT;
        }
    }
    return retVal;
} /* EMAC_get_stats_v5 */

/*
 *  ======== emac_read_icssg_hw_stats ========
 */
void emac_read_icssg_hw_stats(uintptr_t statsBaseAddr, uint32_t* statPtr, uint8_t statsOffset, bool clear)

{
    uint32_t *tempStatsPtr = (uint32_t*)statPtr;
    uint8_t i;
    for (i = statsOffset;  i < sizeof(EMAC_STATISTICS_ICSSG_T)/4; i++)
    {
        *tempStatsPtr = CSL_REG32_RD(statsBaseAddr+ (i *4));
        if (clear == TRUE)
        {
            CSL_REG32_WR(statsBaseAddr+ (i *4), *tempStatsPtr);
        }
        tempStatsPtr++;
    }
}

/*
 *  ======== emac_is_port_open ========
 */
bool emac_is_port_open(uint32_t port_num1, uint32_t port_num2)
{
    bool retVal = true;
    if ((emac_mcb.port_cb[port_num1].emacState == EMAC_PORT_STATE_CLOSED) || (emac_mcb.port_cb[port_num2].emacState == EMAC_PORT_STATE_CLOSED))
    {
        retVal = false;
    }
    return retVal;
}
/*
 *  ======== EMAC_get_stats_icssg_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_get_stats_icssg_v5(uint32_t port_num, EMAC_STATISTICS_ICSSG_T *p_stats, bool clear)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_ERR_PORT_CLOSED;
    uint32_t * statPtr;

    if (p_stats)
    {
        statPtr = (uint32_t*)p_stats;
        switch (port_num)
        {
            case EMAC_INTERPOSER_PORT0:
                if ((emac_is_port_open(0,3) == true))
                {
                    /* need to query port 0 for RX*/
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[0].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU0, statPtr, 0U, clear);
                    /* need to query port 3 for TX*/
                    statPtr = (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET ;
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[3].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU1, (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET, EMAC_ICSSG_TX_STATS_OFFSET, clear);
                    retVal = EMAC_DRV_RESULT_OK;
                }
                break;

            case EMAC_INTERPOSER_PORT1:
                if ((emac_is_port_open(2,1) == true))
                {
                    /* need to query port 2 for RX */
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[2].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU0, statPtr, 0U, clear);
                    /* need to query port 1 for TX */
                    statPtr = (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET;
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[1].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU1, (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET , EMAC_ICSSG_TX_STATS_OFFSET, clear);
                    retVal = EMAC_DRV_RESULT_OK;
                }
                break;

            case EMAC_SWITCH_PORT1:
                if ((emac_is_port_open(0,3) == true))
                {
                    /* need to query port 0 for RX*/
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[0].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU0, statPtr, 0U, clear);
                    /* need to query port 3 for TX*/
                    statPtr = (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET;
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[3].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU1, (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET, EMAC_ICSSG_TX_STATS_OFFSET, clear);
                    retVal = EMAC_DRV_RESULT_OK;
                }
                break;

            case EMAC_SWITCH_PORT2:
                if ((emac_is_port_open(1,1) == true))
                {
                    /* need to query port 2 for RX*/
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[2].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU0, statPtr, 0U, clear);
                    /* need to query port 1 for TX*/
                    statPtr = (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET;
                    emac_read_icssg_hw_stats(emac_mcb.port_cb[1].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU1, (uint32_t*)p_stats + EMAC_ICSSG_TX_STATS_OFFSET , EMAC_ICSSG_TX_STATS_OFFSET, clear);
                    retVal = EMAC_DRV_RESULT_OK;
                }
                break;

            default:
                if (port_num < (EMAC_MAC_PORTS_PER_ICSS*EMAC_MAX_ICSS))
                {
                    if ((emac_is_port_open(port_num,port_num) == true))
                    {
                        if ((port_num & 1) == 0)
                        {
                            emac_read_icssg_hw_stats(emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU0, statPtr, 0U, clear);
                        }
                        else
                        {
                            emac_read_icssg_hw_stats(emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr +  CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_STAT_GOOD_PRU1, statPtr, 0U, clear);
                        }
                        retVal = EMAC_DRV_RESULT_OK;
                    }
                }
                else
                {
                    retVal = EMAC_DRV_RESULT_INVALID_PORT;
                }
                break;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_get_hw_cppi_tx_desc ========
 */
void emac_free_hw_cppi_tx_desc(uint32_t p1, uint32_t ch1, EMAC_CPPI_DESC_T* pCppiDesc)
{
    uintptr_t key;
    key = EMAC_osalHardwareIntDisable();
    pCppiDesc->nextPtr = emac_mcb.port_cb[p1].txReadyDescs[ch1];
    emac_mcb.port_cb[p1].txReadyDescs[ch1] = pCppiDesc;
    EMAC_osalHardwareIntRestore(key);
}

/*
 *  ======== emac_get_hw_cppi_tx_desc ========
 */
bool emac_get_hw_cppi_tx_desc(uint32_t p1, uint32_t ch1, EMAC_CPPI_DESC_T** pCppiDesc)
{
    bool retVal = FALSE;
    EMAC_CPPI_DESC_T *temp1;
    uintptr_t key;
    key = EMAC_osalHardwareIntDisable();
    *pCppiDesc = emac_mcb.port_cb[p1].txReadyDescs[ch1];
    if(*pCppiDesc)
    {
        temp1 = *pCppiDesc;
        emac_mcb.port_cb[p1].txReadyDescs[ch1] = temp1->nextPtr;
        retVal = TRUE;
    }
    EMAC_osalHardwareIntRestore(key);
    return retVal;
}

/*
 *  ======== emac_get_hw_cppi_tx_descs ========
 */

bool emac_get_hw_cppi_tx_descs(uint32_t p1, uint32_t ch1, uint32_t p2, uint32_t ch2, EMAC_CPPI_DESC_T** pCppiDesc1, EMAC_CPPI_DESC_T** pCppiDesc2)
{
    bool retVal = FALSE;
    uintptr_t key;
    EMAC_CPPI_DESC_T *temp1, *temp2;

    key = EMAC_osalHardwareIntDisable();
    *pCppiDesc1 = emac_mcb.port_cb[p1].txReadyDescs[ch1];
    *pCppiDesc2 = emac_mcb.port_cb[p2].txReadyDescs[ch2];
    if(*pCppiDesc1 && *pCppiDesc2)
    {
        temp1 = *pCppiDesc1;
        temp2 = *pCppiDesc2;
        emac_mcb.port_cb[p1].txReadyDescs[ch1] = temp1->nextPtr;
        emac_mcb.port_cb[p2].txReadyDescs[ch2] = temp2->nextPtr;
        retVal = TRUE;
    }
    EMAC_osalHardwareIntRestore(key);

    return retVal;
}




/*
 *  ======== emac_poll_tx_ring ========
 */
static EMAC_DRV_ERR_E emac_poll_tx_ring(uint32_t port_num, Udma_RingHandle compRingHandle, uint32_t ringNum)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_SEND_ERR;
    EMAC_CPPI_DESC_T *pCppiDesc = NULL;
    EMAC_PKT_DESC_T  *pPktDesc;
    int32_t refCount;
    uintptr_t key;

    do
    {
        if ((emac_udma_ring_dequeue(compRingHandle, &pCppiDesc)) ==0)
        {
            retVal = EMAC_DRV_RESULT_OK;
            if (pCppiDesc != NULL)
            {
                pPktDesc = pCppiDesc->appPtr;
                if ((pPktDesc) && (!(pCppiDesc->hostDesc.pktInfo2 & EMAC_FW_MGMT_PKT)))
                {
                    if (pPktDesc->RefCount)
                    {
                        refCount = emac_mAtomic32Sub(&(pPktDesc->RefCount), 1);
                        if(refCount == 1)
                        {
                            EMAC_FREE_PKT(port_num, pCppiDesc->appPtr);
                        }
                    }
                    else
                    {
                        EMAC_FREE_PKT(port_num, pCppiDesc->appPtr);
                    }
                }
                key = EMAC_osalHardwareIntDisable();
                pCppiDesc->nextPtr = emac_mcb.port_cb[port_num].txReadyDescs[ringNum];
                emac_mcb.port_cb[port_num].txReadyDescs[ringNum] = pCppiDesc;
                EMAC_osalHardwareIntRestore(key);
            }
        }
    } while (pCppiDesc != NULL);
    return retVal;
}

/*
 *  ======== EMAC_send_v5_local ========
 */
static EMAC_DRV_ERR_E EMAC_send_v5_local(uint32_t port_num, uint32_t virt_port_num, EMAC_PKT_DESC_T* p_desc, EMAC_CPPI_DESC_T* p_tx_cppi_desc)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_CPPI_DESC_T *pCppiDesc = NULL;
    Udma_ChHandle txChHandle;
    uint32_t chNum =p_desc->PktChannel;
    uintptr_t key;

    txChHandle = emac_mcb.port_cb[port_num].txChHandle[chNum];
    retVal = emac_poll_tx_ring(port_num,Udma_chGetCqRingHandle(txChHandle), chNum);
    if (retVal == EMAC_DRV_RESULT_OK)
    {
        if (p_desc->PktLength < EMAC_MIN_PKT_SIZE)
        {
            p_desc->PktLength = EMAC_MIN_PKT_SIZE;
        }
        if (p_tx_cppi_desc != NULL)
        {
            pCppiDesc = p_tx_cppi_desc;
        }
        else
        {
            emac_get_hw_cppi_tx_desc(port_num, chNum, &pCppiDesc);
        }
        if (pCppiDesc != NULL)
        {
            uint64_t bufPtr = (uint64_t)p_desc->pDataBuffer + p_desc->DataOffset;
            pCppiDesc->hostDesc.bufPtr    = bufPtr;
            pCppiDesc->hostDesc.orgBufPtr = bufPtr;
            pCppiDesc->hostDesc.orgBufLen = p_desc->BufferLen;
            pCppiDesc->hostDesc.bufInfo1  = p_desc->PktLength;
            /* Clear packet type flag bits in case its set, default of 0 indicates TX packet type*/
            pCppiDesc->hostDesc.pktInfo2 &= 0x07FFFFFF;

            /* bits 0-7: specify the port number to direct the packet out */
            /* bits 8-15: specify the tx port queue to use */
            pCppiDesc->hostDesc.srcDstTag = 0;
            pCppiDesc->hostDesc.srcDstTag = p_desc->TxPktTc <<8;
            if (virt_port_num == EMAC_SWITCH_PORT1)
            {
                pCppiDesc->hostDesc.srcDstTag |= 1;
            }
            else if(virt_port_num == EMAC_SWITCH_PORT2)
            {
                pCppiDesc->hostDesc.srcDstTag |= 2;
            }
            /* For CPSW port, always direct packet out of MAC port 1 */
            if (port_num ==EMAC_CPSW_PORT_NUM)
            {
                pCppiDesc->hostDesc.srcDstTag =1U;
            }
            CSL_FINS (pCppiDesc->hostDesc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN, p_desc->PktLength);
            if ((port_num != EMAC_CPSW_PORT_NUM) && (p_desc->Flags & EMAC_PKT_FLAG_TX_TS_REQ))
            {
                pCppiDesc->hostDesc.descInfo |= 0x20000000;
                pCppiDesc->psinfo[0] = p_desc->TxtimestampId;
                pCppiDesc->psinfo[1] = 0x80000000; /*tx_ts_request */
            }
            else
            {
                /* clear flag for TX timestamp */
                pCppiDesc->hostDesc.descInfo &= 0xDFFFFFFF;
            }
            pCppiDesc->appPtr = p_desc;

            /*enqueue packet for transmission */
            if ((retVal = emac_udma_ring_enqueue (Udma_chGetFqRingHandle(txChHandle),pCppiDesc, p_desc->PktLength)) != EMAC_DRV_RESULT_OK)
            {
                gTxDropCounter++;
                key = EMAC_osalHardwareIntDisable();
                pCppiDesc->nextPtr = emac_mcb.port_cb[port_num].txReadyDescs[chNum];
                emac_mcb.port_cb[port_num].txReadyDescs[chNum] = pCppiDesc;
                    EMAC_osalHardwareIntRestore(key);
                UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, Udma ring enqueue error emac_send",port_num);
            }
        }
        else
        {
            retVal = EMAC_DRV_RESULT_IOCTL_ERR_NO_FREE_DESC;
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, NO TX free descriptor available at emac_send",port_num)
        }
    }
    return retVal;
}

/*
 *  ======== EMAC_send_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_send_v5(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_CPPI_DESC_T *pCppiDescTx1 = NULL;
    EMAC_CPPI_DESC_T *pCppiDescTx2 = NULL;
    
    uint32_t virt_port_num =0;
    switch (port_num)
    {
        case EMAC_INTERPOSER_PORT0:
            port_num = 3U;
            break;
        case EMAC_INTERPOSER_PORT1:
            port_num = 1U;
            break;
        case EMAC_SWITCH_PORT1:
            virt_port_num = port_num;
            port_num = 2U;
            break;
        case EMAC_SWITCH_PORT2:
            virt_port_num = port_num;
            port_num = 0U;
            break;
        default:
            break;
    }
    if (p_desc->PktChannel > (EMAC_TX_MAX_CHANNELS_PER_PORT -1))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR,emac_mcb.drv_trace_cb,"port: %d: TX channel number invalid during emac_send: %d",port_num);
        retVal = EMAC_DRV_RESULT_ERR_INVALID_CHANNEL;
    }
    else
    {
        if (port_num == EMAC_SWITCH_PORT)
        {
            /* make sure there is hw descriptor for boths switch ports prior to actually sending */
            if (emac_get_hw_cppi_tx_descs(0, p_desc->PktChannel,2U, p_desc->PktChannel, &pCppiDescTx1, &pCppiDescTx2))
            {
                p_desc->RefCount = 2U;
                retVal = EMAC_send_v5_local(0, port_num, p_desc, pCppiDescTx1);
                if (retVal == EMAC_DRV_RESULT_OK)
                {
                    retVal = EMAC_send_v5_local(2U, port_num, p_desc, pCppiDescTx2);
                    if (retVal != EMAC_DRV_RESULT_OK)
                    {
                         UTILS_trace(UTIL_TRACE_LEVEL_UNEXPECTED,emac_mcb.drv_trace_cb,"port: %d: Send failure for 1st switch port, unexpected: %d",port_num);
                    }
                }
                else
                {
                    /* need to free 2nd desciptor since 1st send failed,
                     * dont need to free 1st desciptor because emac_send frees on failure
                     */
                    UTILS_trace(UTIL_TRACE_LEVEL_UNEXPECTED,emac_mcb.drv_trace_cb,"port: %d: Send failure for 2nd switch port, unexpected: %d",port_num);
                    emac_free_hw_cppi_tx_desc(2, p_desc->PktChannel, pCppiDescTx2);
                    p_desc->RefCount = 0;
                }
            }
        }
        else
        {
            p_desc->RefCount = 0;
            retVal = EMAC_send_v5_local(port_num, virt_port_num, p_desc, NULL);
        }
    }
    return retVal;
} /* EMAC_send_v5 */

/*
 *  ======== EMAC_poll_v5 ========
 */
static  EMAC_DRV_ERR_E EMAC_poll_v5(uint32_t port_num, EMAC_LINK_INFO_T* p_info)
{
    EMAC_DRV_ERR_E      result = EMAC_DRV_RESULT_OK;
    uint32_t              phy_addr;
    uint32_t mdioStatus;
    uint32_t virt_port_num =0;

    switch (port_num)
    {
        case EMAC_INTERPOSER_PORT0:
        case EMAC_SWITCH_PORT1:
            virt_port_num = port_num;
            port_num = 0;
            break;
        case EMAC_INTERPOSER_PORT1:
        case EMAC_SWITCH_PORT2:
            virt_port_num = port_num;
            port_num = 1U;
            break;
        default:
            break;
    }

    if (port_num >= EMAC_MAX_NUM_EMAC_PORTS)
    {
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_info==NULL)
    {
        return EMAC_DRV_RESULT_POLL_ERR;
    }

    p_info->link_status_change = FALSE;

    /* Only Master Core polls for the Link */
    if( EMAC_MDIO(port_num) )
    {
        /* Signal the MDIO*/
        mdioStatus = EMAC_mdioTimerTick( &emac_mcb.port_cb[port_num].MdioDev);

        /* Track new or lost link */
        if( mdioStatus == EMAC_MDIO_EVENT_LINKDOWN || mdioStatus == EMAC_MDIO_EVENT_LINKUP )
        {
            p_info->link_status_change = TRUE;

            EMAC_mdioGetStatus( &emac_mcb.port_cb[port_num].MdioDev, &phy_addr, &p_info->link_status );
            emac_icssg_update_link_params(port_num, virt_port_num, p_info);

        }
        else if ( mdioStatus == EMAC_MDIO_EVENT_PHYERROR)
        {
            result = EMAC_DRV_RESULT_POLL_ERR;
        }
    }
    return result;
} /* EMAC_poll_v5 */

/*
 *  ======== emac_pkt_too_big ========
 */
static inline bool emac_pkt_too_big(uint32_t port_num, EMAC_CPPI_DESC_T *pCppiDesc, uint32_t *pPktSize)
{
    bool tooBig = FALSE;
    *pPktSize = CSL_FEXT (pCppiDesc->hostDesc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN);

    /* Subtract 4 byte CRC from packet size*/
    *pPktSize -= 4;
    if ((*pPktSize) > (EMAC_PKT_SIZE(port_num) + EMAC_ETHHDR_SIZE))
    {
        tooBig = TRUE;
    }
    return tooBig;
}

/*
 *  ======== emac_poll_rx_pkts ========
 */
static void emac_poll_rx_pkts(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum)
{
    EMAC_CPPI_DESC_T *pCppiDesc =NULL;
    EMAC_PKT_DESC_T  *pPktDesc;
    uint32_t          pktSize;
    bool              dropPacket;

    do
    {
        if ((emac_udma_ring_dequeue(compRingHandle, &pCppiDesc)) == 0)
        {
            if(pCppiDesc != NULL)
            {
                dropPacket = FALSE;
                if (emac_pkt_too_big(port_num, pCppiDesc, &pktSize))
                {
                    dropPacket = true;
                }
                else
                {
                    /* Update the software desciptor being passed to application */
                    pPktDesc            = pCppiDesc->appPtr;
                    pPktDesc->ValidLen = pktSize;
                    pPktDesc->PktLength = pktSize;
                    pPktDesc->RxTimeStamp =  ((uint64_t)pCppiDesc->psinfo[1] << 32U) | pCppiDesc->psinfo[0] ;
                    pPktDesc->PktChannel = ringNum;
                    /* Allocate the PKT to replenish the RX_FREE_QUEUE queue */
                    if ((pPktDesc = EMAC_ALLOC_PKT(port_num, EMAC_PKT_SIZE(port_num))) != NULL)
                    {
                        /* Call the callback */
                        emac_mcb.port_cb[port_num].rx_pkt_cb(port_num, pCppiDesc->appPtr);
                        /* Populate the Rx free descriptor with the buffer we just allocated. */
                        pCppiDesc->appPtr             = pPktDesc;
                        pCppiDesc->hostDesc.bufPtr    = (uint64_t)pPktDesc->pDataBuffer;
                        pCppiDesc->hostDesc.orgBufPtr = (uint64_t)pPktDesc->pDataBuffer;
                        pCppiDesc->hostDesc.orgBufLen = pPktDesc->BufferLen;
                        pCppiDesc->hostDesc.bufInfo1  = pPktDesc->BufferLen;
                        emac_udma_ring_enqueue(freeRingHandle,pCppiDesc, pCppiDesc->hostDesc.orgBufLen);
                    }
                    else
                    {
                        gRxDropCounterNoRxAppAllocFail++;
                        /* Drop this packet since we couldn't get new buffer */
                        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: RX pkt allocation error during replinish of RX free queue, packet dropped",
                                                port_num);
                        dropPacket = true;
                    }
                }
                if (dropPacket == true) 
                {
                    /* It was either too big, or no replacement buffer so avoid leaking descriptors */
                    gRxDropCounter++;
                    CSL_FINS (pCppiDesc->hostDesc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN,
                                          pCppiDesc->hostDesc.orgBufLen);
                    emac_udma_ring_enqueue(freeRingHandle, pCppiDesc, pCppiDesc->hostDesc.orgBufLen);
                }
            }
        }
    } while (pCppiDesc != 0);
}

/*
 *  ======== emac_poll_tx_complete ========
 */
static void emac_poll_tx_complete(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum)
{
    emac_poll_tx_ring(port_num,compRingHandle, ringNum);
}

/*
 *  ======== emac_poll_mgmt_pkts ========
 */
static void emac_poll_mgmt_pkts(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum)
{
    EMAC_CPPI_DESC_T *pCppiDesc = NULL;
    EMAC_IOCTL_CMD_RESP_T cmdResponse;
    EMAC_IOCTL_CMD_T *pIoctlData;
    do
    {
        if ((emac_udma_ring_dequeue(compRingHandle, &pCppiDesc)) == 0)
        {
            if(pCppiDesc != NULL)
            {
                if (emac_mcb.ioctl_cb.ioctlCount)
                {
                    if (--emac_mcb.ioctl_cb.ioctlCount == 0)
                    {
                        pIoctlData = (EMAC_IOCTL_CMD_T*)pCppiDesc->appPtr->pDataBuffer;
                        cmdResponse.status = pIoctlData->commandParam;
                        cmdResponse.seqNumber = pIoctlData->seqNumber;
                        cmdResponse.respParamsLength = 0;
                        /* for command response with status 0x3, its cmd response for ADD FDB entry.
                           if adding entry results in removing aged-out FDB entry, that is returned to caller
                           in response Params*/
                        if (cmdResponse.status == 0x3)
                        {
                            cmdResponse.respParamsLength = 2;
                            memcpy(&cmdResponse.respParams, pIoctlData->spare, 2);
                        }
                        if ((emac_mcb.port_cb[port_num].rx_mgmt_response_cb != NULL) && (emac_mcb.ioctl_cb.internalIoctl == FALSE))
                        {
                            emac_mcb.port_cb[port_num].rx_mgmt_response_cb(port_num, &cmdResponse);
                        }
                        emac_mcb.ioctl_cb.internalIoctl = FALSE;
                    }
                }
                emac_udma_ring_enqueue(freeRingHandle,pCppiDesc, pCppiDesc->hostDesc.orgBufLen);
            }
        }
    } while (pCppiDesc != 0);
}

/*
 *  ======== emac_poll_tx_ts_resp ========
 */
static void emac_poll_tx_ts_resp(uint32_t port_num, Udma_RingHandle compRingHandle, Udma_RingHandle freeRingHandle, uint32_t ringNum)
{
    EMAC_CPPI_DESC_T *pCppiDesc = NULL;
    EMAC_TX_TS_RESPONSE *tx_ts;
    uint64_t tx_timestamp;
    bool is_valid;
    do
    {
        if ((emac_udma_ring_dequeue(compRingHandle, &pCppiDesc)) == 0)
        {
           if(pCppiDesc != NULL)
           {
               tx_ts = (EMAC_TX_TS_RESPONSE*)(uintptr_t)pCppiDesc->hostDesc.bufPtr;
               tx_timestamp = tx_ts->hi_txts;
               tx_timestamp = (tx_timestamp << 32) | tx_ts->lo_txts ;
               is_valid = (bool) tx_ts->ts_valid;
               if(emac_mcb.port_cb[port_num].tx_ts_cb != NULL)
               {
                   emac_mcb.port_cb[port_num].tx_ts_cb(port_num, tx_ts->ts_id, tx_timestamp, is_valid);
               }
               emac_udma_ring_enqueue(freeRingHandle,pCppiDesc, pCppiDesc->hostDesc.orgBufLen);
           }
        }
    } while (pCppiDesc != 0);
}

/*
 *  ======== emac_get_sw_port_num ========
 */
static uint32_t emac_get_sw_port_num(uint32_t port_num)
{
    uint32_t pNum;
    pNum = port_num;
    switch (port_num)
    {
        case EMAC_INTERPOSER_PORT0:
        case EMAC_SWITCH_PORT1:
            pNum = 0U;
            break;
        case EMAC_INTERPOSER_PORT1:
        case EMAC_SWITCH_PORT2:
            pNum = 2U;
            break;
        default:
            break;
    }
    return pNum;
}

/*
 *  ======== EMAC_poll_pkt_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_poll_pkt_v5(uint32_t port_num)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    int32_t ringNum = 0;

    port_num = emac_get_sw_port_num(port_num);

    if( emac_mcb.port_cb[port_num].emacState  == EMAC_PORT_STATE_CLOSED)
    {
            retVal =  EMAC_DRV_RESULT_GENERAL_ERR;
    }
    else
    {
        /* Poll the rx completion queue for receive packet */
        if (emac_mcb.port_cb[port_num].mode_of_operation == EMAC_MODE_POLL)
        {
            EMAC_poll_ctrl_v5(port_num, EMAC_POLL_RX_PKT_RING1, 0, 0);
            return EMAC_DRV_RESULT_OK;
        }
        /* wait for ISR to hit for receive packet */
        else
        {
            while(retVal == EMAC_DRV_RESULT_OK )
            {
                EMAC_osalPendLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num,ringNum), SemaphoreP_WAIT_FOREVER);
                if( emac_mcb.port_cb[port_num].emacState  == EMAC_PORT_STATE_CLOSED)
                {
                    retVal =   EMAC_DRV_RESULT_GENERAL_ERR;
                    break;
                }
                /* poll rx pkt on default flow */
                EMAC_poll_ctrl_v5(port_num, EMAC_POLL_RX_PKT_RING1, 0, 0);
            }
        }
    }
   return retVal;
} /* EMAC_poll_pkt_v5 */

/*
 *  ======== EMAC_ioctl_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_ioctl_v5(uint32_t port_num, EMAC_IOCTL_CMD emacIoctlCmd, EMAC_IOCTL_PARAMS *emacIoctlParams)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    void *ioctlData = emacIoctlParams->ioctlVal;
    uint32_t port_map[EMAC_MAX_NUM_EMAC_PORTS] = {0,0,0,0,0,0,0};
    uint32_t i;
    if (emac_mcb.ioctl_cb.ioctlCount == 0)
    {
        switch (port_num)
        {
           case EMAC_INTERPOSER_PORT0:
               port_map[0] = 1;
               break;
           case EMAC_INTERPOSER_PORT1:
               port_map[2] = 1;
               break;
           case EMAC_SWITCH_PORT1:
               port_map[0] = 1;
               break;
           case EMAC_SWITCH_PORT2:
               port_map[2] = 1;
               break;
           case EMAC_SWITCH_PORT:
           case EMAC_SWITCH_PORT0:
               port_map[0] = 1;
               port_map[2] = 1;
               break;
           default:
               port_map[port_num] = 1;
               break;
        }

        for (i = 0;i < EMAC_MAX_NUM_EMAC_PORTS;i++)
        {
            /* check if port map set, otherwise move to next port */
            if (!port_map[i])
                continue;
            /* retVal should be either OK or in progress, if anyhting else, means error has occured*/
            /* this can occur is sending IOCTL to 2 ports, if 1st port fails, no need to send to 2nd port, 
               just return error to the caller */
            if (!((retVal == EMAC_DRV_RESULT_OK) || (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)))
                break;
            if (emac_mcb.port_cb[i].emacState == EMAC_PORT_STATE_OPEN)
            {
                switch (emacIoctlCmd)
                {
                    case EMAC_IOCTL_PROMISCOUS_MODE_CTRL:
                        emac_ioctl_icss_promiscous_ctrl(i, ioctlData);
                        break;
                    case EMAC_IOCTL_VLAN_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_VLAN_SET_DEFAULT_TBL:
                                emac_ioctl_vlan_ctrl_set_default_tbl(i, ioctlData);
                                break;
                            case EMAC_IOCTL_VLAN_SET_ENTRY:
                                retVal = emac_ioctl_vlan_ctrl_set_entry(i, ioctlData);
                                break;
                            case EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID:
                                if (port_num == EMAC_SWITCH_PORT0)
                                {
                                    retVal = emac_ioctl_vlan_ctrl_set_default_vlan_id_host_port(i, ioctlData);
                                }
                                else
                                {
                                    retVal = emac_ioctl_vlan_ctrl_set_default_vlan_id(i, ioctlData);
                                }
                                break;
                            case EMAC_IOCTL_VLAN_GET_ENTRY:
                                retVal = emac_ioctl_vlan_ctrl_get_entry(i, ioctlData);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_PORT_PRIO_MAPPING_CTRL:
                        emac_ioctl_port_prio_mapping_ctrl(i, ioctlData);
                        break;
                    case EMAC_IOCTL_PORT_STATE_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_PORT_STATE_DISABLE:
                            case EMAC_IOCTL_PORT_STATE_BLOCKING:
                            case EMAC_IOCTL_PORT_STATE_FORWARD:
                            case EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING:
                            case EMAC_IOCTL_PORT_STATE_TAS_TRIGGER:
                            case EMAC_IOCTL_PORT_STATE_TAS_ENABLE:
                            case EMAC_IOCTL_PORT_STATE_TAS_RESET:
                            case EMAC_IOCTL_PORT_STATE_TAS_DISABLE:
                                retVal = emac_ioctl_port_state_ctrl(i, (void*)emacIoctlParams);
                            break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_FDB_ENTRY_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_FDB_ENTRY_ADD:
                            case EMAC_IOCTL_FDB_ENTRY_DELETE:
                                /* emac_ioctl_fdb_entry_ctrl will update both instances */
                                port_map[2] = 0;
                                retVal = emac_ioctl_fdb_entry_ctrl(i, (void*)emacIoctlParams);
                                break;
                            case EMAC_IOCTL_FDB_ENTRY_DELETE_ALL:
                            case EMAC_IOCTL_FDB_ENTRY_DELETE_ALL_AGEABLE:
                                port_map[2] = 0;
                                /* emac_ioctl_fdb_entry_ctrl will update both instances */
                                retVal = emac_ioctl_fdb_del_all(i,(void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED:
                            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED:
                            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES:
                                retVal = emac_ioctl_accept_frame_check_ctrl(i, (void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_PRIO_REGEN_CTRL:
                        retVal = emac_ioctl_prio_regen_mapping_ctrl(i, ioctlData);
                        break;
                    case EMAC_IOCTL_UC_FLOODING_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_PORT_UC_FLOODING_ENABLE:
                            case EMAC_IOCTL_PORT_UC_FLOODING_DISABLE:
                                retVal = emac_ioctl_uc_flooding_ctrl(i, port_num, (void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_INTERFACE_MAC_CONFIG:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_INTERFACE_MAC_ADD:
                                retVal = emac_ioctl_configure_interface_mac_ctrl(i, port_num, (void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_FRAME_PREEMPTION_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_PREEMPT_TX_ENABLE:
                            case EMAC_IOCTL_PREEMPT_TX_DISABLE:
                            case EMAC_IOCTL_PREEMPT_GET_TX_ENABLE_STATUS:
                            case EMAC_IOCTL_PREEMPT_GET_TX_ACTIVE_STATUS:
                            case EMAC_IOCTL_PREEMPT_VERIFY_ENABLE:
                            case EMAC_IOCTL_PREEMPT_VERIFY_DISABLE:
                            case EMAC_IOCTL_PREEMPT_GET_VERIFY_STATE:
                            case EMAC_IOCTL_PREEMPT_GET_MIN_FRAG_SIZE_LOCAL:
                            case EMAC_IOCTL_PREEMPT_SET_MIN_FRAG_SIZE_REMOTE:
                                retVal = emac_ioctl_frame_premption_ctrl(i, port_num, (void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                        break;
                    case EMAC_IOCTL_CUT_THROUGH_PREEMPT_SELECT:
                        emac_ioctl_configure_cut_through_or_prempt_select_ctrl(i, port_num, (void*)emacIoctlParams);
                        break;
                    case EMAC_IOCTL_SPECIAL_FRAME_PRIO_CONFIG:
                        emac_ioctl_configure_special_frame_prio_ctrl(i, port_num, (void*)emacIoctlParams);
                        break;
                    case EMAC_IOCTL_FDB_AGEING_TIMEOUT_CTRL:
                        emac_ioctl_configure_fdb_ageing_interval(i, port_num, (void*)emacIoctlParams);
                        break;
                    case EMAC_IOCTL_TEST_MULTI_FLOW:
                        emac_ioctl_test_multi_flow(i, ioctlData);
                        break;
                    case EMAC_IOCTL_SPEED_DUPLEXITY_CTRL:
                        switch (emacIoctlParams->subCommand)
                        {
                            case EMAC_IOCTL_SPEED_DUPLEXITY_10HD:
                            case EMAC_IOCTL_SPEED_DUPLEXITY_10FD:
                            case EMAC_IOCTL_SPEED_DUPLEXITY_100HD:
                            case EMAC_IOCTL_SPEED_DUPLEXITY_100FD:
                            case EMAC_IOCTL_SPEED_DUPLEXITY_GIGABIT:
                            case EMAC_IOCTL_SPEED_DUPLEXITY_DISABLE:
                                retVal = emac_ioctl_speed_duplexity_cfg(i, (void*)emacIoctlParams);
                                break;
                            default:
                                retVal = EMAC_DRV_RESULT_IOCTL_ERR;
                                break;
                        }
                    default:
                        break;
                }
            }
            else
            {
                retVal =  EMAC_DRV_RESULT_IOCTL_ERR_PORT_CLOSED;
            }
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_IOCTL_ERR_IN_PROGRESS;
    }
    return retVal;
}

/*
 *  ======== EMAC_poll_ctrl_v5 ========
 */
static EMAC_DRV_ERR_E EMAC_poll_ctrl_v5(uint32_t port_num, uint32_t rxPktRings, uint32_t rxMgmtRings, uint32_t txRings)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    int32_t i;
    uint32_t pollMask;
    uint32_t pNum;

    pNum = emac_get_sw_port_num(port_num);

    if( emac_mcb.port_cb[pNum].emacState  == EMAC_PORT_STATE_CLOSED)
    {
        /* when port is down, only want to process management rings */
        rxPktRings = 0;
        txRings = 0;
    }
    /* Poll the rx completion queue for receive packet */
    if (emac_mcb.port_cb[pNum].rxPktCh.nsubChan > 0)
    {
        pollMask = 1 << (emac_mcb.port_cb[pNum].rxPktCh.nsubChan - 1);
        for (i = emac_mcb.port_cb[pNum].rxPktCh.nsubChan-1; i >= 0;i--)
        {
            if ((rxPktRings & pollMask) && (emac_mcb.port_cb[pNum].pollTable.rxPkt[i].ringPollFxn))
            {
                emac_mcb.port_cb[pNum].pollTable.rxPkt[i].ringPollFxn(pNum,
                                        emac_mcb.port_cb[pNum].pollTable.rxPkt[i].compRingHandle,
                                        emac_mcb.port_cb[pNum].pollTable.rxPkt[i].freeRingHandle,
                                        i);
            }
            pollMask = pollMask >> 1;
        }
    }

    /* Poll the rx management completion queue  management response or TX TS response */
    if (emac_mcb.port_cb[pNum].rxMgmtCh.nsubChan > 0)
    {
        pollMask = 1 << (emac_mcb.port_cb[pNum].rxMgmtCh.nsubChan - 1);
        for (i = emac_mcb.port_cb[pNum].rxMgmtCh.nsubChan-1; i >= 0;i--)
        {
            if ((rxMgmtRings & pollMask) && (emac_mcb.port_cb[pNum].pollTable.rxMgmt[i].ringPollFxn))
            {
                emac_mcb.port_cb[pNum].pollTable.rxMgmt[i].ringPollFxn(pNum,
                                        emac_mcb.port_cb[pNum].pollTable.rxMgmt[i].compRingHandle,
                                        emac_mcb.port_cb[pNum].pollTable.rxMgmt[i].freeRingHandle,
                                        i);
            }
            pollMask = pollMask >> 1;
        }
    }

    /* polling of TX completion rings has different port mapping than rx channels for switch*/
    if (port_num == EMAC_SWITCH_PORT1)
    {
        pNum = 2;
    }
    else if (port_num == EMAC_SWITCH_PORT2)
    {
        pNum = 0;
    }
    /* Poll the TX completion queue for tx completion events*/
    if (emac_mcb.port_cb[pNum].numTxChans > 0)
    {
        pollMask = 1 << (emac_mcb.port_cb[pNum].numTxChans - 1);
        for (i = emac_mcb.port_cb[pNum].numTxChans - 1; i >= 0;i--)
        {
            if ((txRings & pollMask) && (emac_mcb.port_cb[pNum].pollTable.txCompletion[i].ringPollFxn))
            {
                emac_mcb.port_cb[pNum].pollTable.txCompletion[i].ringPollFxn(pNum,
                                        emac_mcb.port_cb[pNum].pollTable.txCompletion[i].compRingHandle,
                                        emac_mcb.port_cb[pNum].pollTable.txCompletion[i].freeRingHandle,
                                        i);
            }
            pollMask = pollMask >> 1;
        }
    }
    return retVal;
}

static EMAC_DRV_ERR_E EMAC_get_cpsw_stats(CSL_Xge_cpswRegs *hCpswRegs, EMAC_STATISTICS_T*      p_stats)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_ERR_PORT_CLOSED;

    if (emac_mcb.port_cb[EMAC_CPSW_PORT_NUM].emacState == EMAC_PORT_STATE_OPEN)
    {
        CSL_CPSW_STATS stats[CSL_CPSW_NUMSTATBLOCKS];

        memset (&stats, 0, sizeof(CSL_CPSW_STATS)*CSL_CPSW_NUMSTATBLOCKS);
        CSL_CPSW_getStats(hCpswRegs,(CSL_CPSW_STATS*)&stats[0]);
        p_stats->RxGoodFrames += stats[1].RxGoodFrames;
        p_stats->RxBCastFrames += stats[1].RxBCastFrames;
        p_stats->RxMCastFrames += stats[1].RxMCastFrames;
        p_stats->RxPauseFrames += stats[1].RxPauseFrames;
        p_stats->RxCRCErrors += stats[1].RxCRCErrors;
        p_stats->RxAlignCodeErrors += stats[1].RxAlignCodeErrors;
        p_stats->RxJabber += stats[1].RxJabber;
        p_stats->RxUndersized += stats[1].RxUndersized;
        p_stats->RxFragments += stats[1].RxFragments;
        p_stats->RxOctets += stats[1].RxOctets;
        p_stats->TxGoodFrames += stats[1].TxGoodFrames;
        p_stats->TxBCastFrames += stats[1].TxBCastFrames;
        p_stats->TxMCastFrames += stats[1].TxMCastFrames;
        p_stats->TxDeferred += stats[1].TxDeferred;
        p_stats->TxCollision += stats[1].TxCollision;
        p_stats->TxSingleColl += stats[1].TxSingleColl;
        p_stats->TxMultiColl += stats[1].TxMultiColl;
        p_stats->TxExcessiveColl += stats[1].TxExcessiveColl;
        p_stats->TxLateColl += stats[1].TxLateColl;
        p_stats->TxCarrierSLoss += stats[1].TxCarrierSLoss;
        p_stats->TxOctets += stats[1].TxOctets;
        retVal = EMAC_DRV_RESULT_OK;
    }
    return retVal;
}

/****************************************************
 * Function: icssg_eth_setup,
 * Description: ICSS MII, CFG, MIIG initializations
 ***************************************************/
void emac_icssg_switch_eth_setup (uint32_t portNum)
{
    uint32_t reg_val;
    uint32_t numFDBBuckets =0;
    uintptr_t fdbAgeingIntervalAddr;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;

    uintptr_t icssgBaseAddr = emac_mcb.port_cb[portNum].icssDram0BaseAddr;

    /* Program c28_pointer to 0x100, so that firmware can access 0x10000 via C28 */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_PDSP0_IRAM_REGS_BASE + 0x28), 0x100);    /* RX_PRU */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_RTU0_PR1_RTU0_IRAM_REGS_BASE + 0x28), 0x100);    /* RTU0 */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_RTU1_PR1_RTU1_IRAM_REGS_BASE + 0x28), 0x100);    /* RTU1 */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_PDSP1_IRAM_REGS_BASE + 0x28), 0x100);    /*PRU1 as TX_PRU */

    /* Program c24_pointer to 0x0, so that firmware can access 0x00000 via C24*/
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_PDSP0_IRAM_REGS_BASE + 0x24), 0x0);    /* RX_PRU */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_RTU0_PR1_RTU0_IRAM_REGS_BASE + 0x24), 0x0);    /* RTU0 */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_RTU1_PR1_RTU1_IRAM_REGS_BASE + 0x24), 0x0);    /*RTU1 */

    /* MII mode (icss_wrap mux sel[29:26]=2), (MII GPI mode [1:0] =3) for RX_PRU/PRU0 */
    reg_val =
        CSL_REG32_RD (icssgBaseAddr + CSL_ICSSCFG_REGS_BASE +
                        CSL_ICSSCFG_GPCFG0);
    reg_val |=
        (0x3 << CSL_ICSSCFG_GPCFG0_PRU0_GPI_MODE_SHIFT) | (0x2 <<
                CSL_ICSSCFG_GPCFG0_PR1_PRU0_GP_MUX_SEL_SHIFT);
    CSL_REG32_WR (icssgBaseAddr + CSL_ICSSCFG_REGS_BASE +
                     CSL_ICSSCFG_GPCFG0, reg_val);
    
    /* MII mode (icss_wrap mux sel[29:26]=2), (MII GPI mode [1:0] =3) for TX_PRU/PRU1 */
    reg_val =
        CSL_REG32_RD (icssgBaseAddr + CSL_ICSSCFG_REGS_BASE +
                        CSL_ICSSCFG_GPCFG1);
    reg_val |=
        (0x3 << CSL_ICSSCFG_GPCFG1_PRU1_GPI_MODE_SHIFT) | (0x2 <<
                CSL_ICSSCFG_GPCFG1_PR1_PRU1_GP_MUX_SEL_SHIFT);
    CSL_REG32_WR (icssgBaseAddr + CSL_ICSSCFG_REGS_BASE +
                     CSL_ICSSCFG_GPCFG1, reg_val);

    /* RX_L2_EOF_SCLR_DIS - EOF not self clear in RXL2 mode(Bit9), RXL2 enable (Bit4), RX enable (Bit0) */
    /*Only on RX_PRU/PRU0 */
    reg_val =
        CSL_REG32_RD (icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_REGS_BASE +
                        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0);
    reg_val |=
        (1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_L2_EN0_SHIFT) | (1 <<
                CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_ENABLE0_SHIFT)
        | (1 <<
           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_EOF_SCLR_DIS0_SHIFT);
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_REGS_BASE +
                      CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0), reg_val);

    /* Not that TX_START_DELAY H/W reset value is 320ns by default
     * 32 bit push mode (Bit11), Auto Preamble (Bit1), TX enable (Bit0)
     *TX data from PRU1/TX_PRU mux sel (Bit8) -> On Port 2 */
    reg_val =
        CSL_REG32_RD (icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_REGS_BASE +
                        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1);
    reg_val |=
        (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_ENABLE1_SHIFT) |
        (0x1 <<
         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE1_SHIFT) |
        (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_32_MODE_EN1_SHIFT) |
        (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_MUX_SEL1_SHIFT); /* P1 -> PRU1 */
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_REGS_BASE +
                      CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1), reg_val);

    /* ICSS G CFG */
    reg_val =
        CSL_REG32_RD (icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE
                        +
                        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG);
    reg_val &=
        ~(CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_MII0_MODE_MASK)
        |
        (CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_MII1_MODE_MASK);

    reg_val |=
        (0x1 <<
         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_TX_L1_EN_SHIFT)
        | (0x1 <<
           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_TX_L2_EN_SHIFT)
        | (0x1 <<
           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_RX_L2_G_EN_SHIFT)
        | (0x1 <<
           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_MII0_MODE_SHIFT)
        | (0x1 <<
           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG_MII1_MODE_SHIFT);
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE
                      +
                      CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG),
                     reg_val);

    /*Configure task manager TXL2 watermark. TBD: Need to move to firmware */
    /*TX_WM ask runs on TX_PRU/PRU1 */
    reg_val = 0;
    emac_hw_mem_write
    (icssgBaseAddr + CSL_ICSS_G_PR1_TASKS_MGR_PRU1_PR1_TASKS_MGR_PRU1_MMR_REGS_BASE +
     CSL_ICSS_G_PR1_TASKS_MGR_PRU1_PR1_TASKS_MGR_PRU1_MMR_TX_CFG, &reg_val,1);
    /* RX tasks run on RX_PRU/PRU0 */
    /*Configure RXBK1 Size = 20Bytes, RXBK2 Size = 12 Bytes, RXBKn Size = 32 Bytes. */
    reg_val =
        (19 <<
         CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_RX_CFG_BK1_SIZE_SHIFT)
        | (11 <<
           CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_RX_CFG_BK2_SIZE_SHIFT)
        | (31 <<
           CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_RX_CFG_BKN_SIZE_SHIFT);
    emac_hw_mem_write
    (icssgBaseAddr + CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_REGS_BASE +
     CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_RX_CFG, &reg_val, 1);
    /* Configure RXBKn task to capture new event CAP_NEW_EN */
    /* configure similar values for RTU0 */
     reg_val =
        (19 <<
         CSL_ICSS_G_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_RX_CFG_BK1_SIZE_SHIFT)
        | (11 <<
           CSL_ICSS_G_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_RX_CFG_BK2_SIZE_SHIFT)
        | (31 <<
           CSL_ICSS_G_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_RX_CFG_BKN_SIZE_SHIFT);
    emac_hw_mem_write
    (icssgBaseAddr+ CSL_ICSS_G_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_REGS_BASE +
     CSL_ICSS_G_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_RX_CFG, &reg_val, 1);

    /* enable only for TS 1 task due to HW errata*/
    reg_val = 0x1f;
    emac_hw_mem_write
    (icssgBaseAddr + CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_REGS_BASE +
     CSL_ICSS_G_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_CAP_EN_CFG, &reg_val,1);

    /*For reducing IEP latency. Enable OCP clock */
    CSL_REG32_WR (icssgBaseAddr + CSL_ICSSCFG_REGS_BASE +
                     CSL_ICSSCFG_IEPCLK,
                     (0x1 <<
                      CSL_ICSSCFG_IEPCLK_OCP_EN_SHIFT));


    /* Enable IEP0 counter and set default increment as 4 */
    reg_val = (0x1 << CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_SHIFT)
              | (0x4 << CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_SHIFT)
              | (0x4 << CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_SHIFT);
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_IEP0_SLV_REGS_BASE +
                      CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG), reg_val);

    /*Enable IEP1 counter and set default increment as 4 */
    reg_val = (0x1 << CSL_ICSS_G_PR1_IEP1_SLV_GLOBAL_CFG_REG_CNT_ENABLE_SHIFT)
              | (0x4 << CSL_ICSS_G_PR1_IEP1_SLV_GLOBAL_CFG_REG_DEFAULT_INC_SHIFT)
              | (0x4 << CSL_ICSS_G_PR1_IEP1_SLV_GLOBAL_CFG_REG_CMP_INC_SHIFT);
    CSL_REG32_WR ((icssgBaseAddr + CSL_ICSS_G_PR1_IEP1_SLV_REGS_BASE +
                      CSL_ICSS_G_PR1_IEP1_SLV_GLOBAL_CFG_REG), reg_val);

    /* Enable stats block, 0 64-bit counters */
    CSL_REG32_WR (icssgBaseAddr + CSL_ICSS_G_PA_STAT_WRAP_PA_SLV_REGS_BASE + 8, EMAC_BIT(31));


    /* Configure Default Ageing value for firmware to use*/
    /* The actual value written to memory is ageing timeout divided by number of buckets
     * because in firmware we iterate per bucket not for entire FDB. See NRT design doc for more details */
    if (emac_mcb.port_cb[portNum].getFwCfg)
    {
        emac_mcb.port_cb[portNum].getFwCfg(portNum,&pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        /*Calculate number of buckets*/
        numFDBBuckets = pSwitchFwCfg->fdbSize / pSwitchFwCfg->numFdbBucketEntries;

        fdbAgeingIntervalAddr = emac_mcb.port_cb[portNum].icssDram1BaseAddr + pSwitchFwCfg->fdbAgeingTimeoutOffset;
        /*The actual value written to memory is ageing timeout divided by number of buckets
          because in firmware we iterate per bucket not for entire FDB. See NRT design doc for more details*/
        CSL_REG64_WR(fdbAgeingIntervalAddr, pSwitchFwCfg->defaultAgeingTimeout/(uint64_t)numFDBBuckets);
    }
}

/*
 *  ======== emac_get_icssg_cfg_base_addr ========
 */
uintptr_t emac_get_icssg_cfg_base_addr(uint32_t port_num, uint32_t virt_port_num)
{
    uintptr_t baseAddr = 0;

    switch (virt_port_num)
    {
        case EMAC_SWITCH_PORT1:
            baseAddr = emac_mcb.port_cb[3].icssDram0BaseAddr;
            break;
        case EMAC_SWITCH_PORT2:
            baseAddr = emac_mcb.port_cb[1].icssDram0BaseAddr;
            break;
        default:
            baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr;
            break;
    }
    return baseAddr;
}

/*
 *  ======== emac_get_icssg_rgmii_cfg_base_addr ========
 */
uintptr_t emac_get_icssg_rgmii_cfg_base_addr(uint32_t port_num, uint32_t virt_port_num)
{
    uintptr_t baseAddr = emac_get_icssg_cfg_base_addr(port_num, virt_port_num);
    baseAddr += CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE +
               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG;
    return baseAddr;
}

/*
 *  ======== emac_get_icssg_tx_ipg_cfg_base_addr ========
 */
uintptr_t emac_get_icssg_tx_ipg_cfg_base_addr(uint32_t port_num, uint32_t virt_port_num)
{
    uintptr_t baseAddr = emac_get_icssg_cfg_base_addr(port_num, virt_port_num);
    baseAddr += CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_REGS_BASE +
               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1;
    return baseAddr;
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_100hd ========
 */
void emac_icssg_update_rgmii_cfg_100hd(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(icssgRgmiiCfgBaseAddr);
    /* Need tup update ICSSG_RGMII_CFG for both ICSSG instances if virt_port_num is a switch port*/
    /* Need to clear bit 17 for slice 0 or bit 21 for slice 1 of ICSSG_RGMII_CFG to configure 100 mpbs */
    /* Need to clear bit 18 for slice 0 or bit 22 for slice 1 of ICSSG_RGMII_CFG to configure half duplex */
    if ((port_num & 1) == 0)
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
    }
    else
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;
    }
    CSL_REG32_WR (icssgRgmiiCfgBaseAddr, regVal);
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_100fd ========
 */
void emac_icssg_update_rgmii_cfg_100fd(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr)
{
    uint32_t regVal;
    regVal = CSL_REG32_RD(icssgRgmiiCfgBaseAddr);

    /* Need to update ICSSG_RGMII_CFG for both ICSSG instances if virt_port_num is a switch port*/
    /* Need to clear bit 17 for slice 0 or bit 21 for slice 1 of ICSSG_RGMII_CFG to configure 100 mpbs */
    /* Need to set bit 18 for slice 0 or bit 22 for slice 1 of ICSSG_RGMII_CFG to configure full duplex */
    if ((port_num & 1) == 0)
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
    }
    else
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;

    }
    CSL_REG32_WR(icssgRgmiiCfgBaseAddr, regVal);
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_100MB ========
 */
void emac_icssg_update_rgmii_cfg_100MB(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr, uint32_t link_status)
{
    if (link_status == EMAC_MDIO_LINKSTATUS_HD100)
    {
        emac_icssg_update_rgmii_cfg_100hd(port_num, icssgRgmiiCfgBaseAddr);
    }
    else
    {
        emac_icssg_update_rgmii_cfg_100fd(port_num, icssgRgmiiCfgBaseAddr);
    }
}

#define EMAC_ICSSG_CONFIG_TX_IPG_960_NS ((uint32_t)(0x166)) /* configure 960 nano-second TX IPG */
/*
 *  ======== emac_icssg_update_link_speed_100MB ========
 */
void emac_icssg_update_link_speed_100MB(uint32_t port_num, uint32_t virt_port_num, uint32_t link_status)
{
    uintptr_t icssgRgmiiCfgAddr, icssgTxIpg1CfgAddr;
    uint32_t regVal;


    if ((virt_port_num == EMAC_SWITCH_PORT1) ||(virt_port_num == EMAC_SWITCH_PORT2))
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT1);
        emac_icssg_update_rgmii_cfg_100MB(~(port_num&1), icssgRgmiiCfgAddr, link_status);

        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT2);
        emac_icssg_update_rgmii_cfg_100MB((port_num&1), icssgRgmiiCfgAddr, link_status);
    }
    else
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, port_num);
        emac_icssg_update_rgmii_cfg_100MB(port_num, icssgRgmiiCfgAddr, link_status);
        if (link_status == EMAC_MDIO_LINKSTATUS_HD100)
        {
            emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_100HD);
        }
        else
        {
            emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_100FD);
        }
    }

    /*Configuring 960ns TX IPG in ICSSG HW MMR*/
    regVal = EMAC_ICSSG_CONFIG_TX_IPG_960_NS;
    icssgTxIpg1CfgAddr  = emac_get_icssg_tx_ipg_cfg_base_addr(port_num, virt_port_num);
    CSL_REG32_WR (icssgTxIpg1CfgAddr, regVal);
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_1G ========
 */
void emac_icssg_update_rgmii_cfg_1G(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(icssgRgmiiCfgBaseAddr);
    if ((port_num & 1) == 0)
    {
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
    }
    else
    {
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;
    }
    CSL_REG32_WR (icssgRgmiiCfgBaseAddr, regVal);
}

#define EMAC_ICSSG_CONFIG_TX_IPG_104_NS ((uint32_t)(0x1A)) /* configure 104 nano-second TX IPG */
/*
 *  ======== emac_icssg_update_link_speed_1G ========
 */
void emac_icssg_update_link_speed_1G(uint32_t port_num, uint32_t virt_port_num)
{
    uintptr_t icssgRgmiiCfgAddr, icssgTxIpg1CfgAddr;
    uint32_t regVal;

    if ((virt_port_num == EMAC_SWITCH_PORT1) ||(virt_port_num == EMAC_SWITCH_PORT2))
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT1);
        emac_icssg_update_rgmii_cfg_1G(~(port_num&1), icssgRgmiiCfgAddr);

        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT2);
        emac_icssg_update_rgmii_cfg_1G((port_num&1), icssgRgmiiCfgAddr);
    }
    else
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, port_num);
        emac_icssg_update_rgmii_cfg_1G(port_num, icssgRgmiiCfgAddr);
        /* issue speed_duplexity ioctl to fw */
        emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_GIGABIT);
    }
    /*Configuring 104ns TX IPG ICSSG HW MMR */
    regVal = EMAC_ICSSG_CONFIG_TX_IPG_104_NS;
    icssgTxIpg1CfgAddr  = emac_get_icssg_tx_ipg_cfg_base_addr(port_num, virt_port_num);
    CSL_REG32_WR (icssgTxIpg1CfgAddr, regVal);
}



/*
 *  ======== emac_icssg_update_rgmii_cfg_10hd ========
 */
void emac_icssg_update_rgmii_cfg_10hd(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(icssgRgmiiCfgBaseAddr);
    if ((port_num & 1) == 0)
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_INBAND_MASK;
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
    }
    else
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_INBAND_MASK;
           regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;
    }

    CSL_REG32_WR (icssgRgmiiCfgBaseAddr, regVal);
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_10fd ========
 */
void emac_icssg_update_rgmii_cfg_10fd(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(icssgRgmiiCfgBaseAddr);
    if ((port_num & 1) == 0)
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_INBAND_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
    }
    else
    {
        regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_INBAND_MASK;
        regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;
    }

    CSL_REG32_WR (icssgRgmiiCfgBaseAddr, regVal);
}

/*
 *  ======== emac_icssg_update_rgmii_cfg_10MB ========
 */
void emac_icssg_update_rgmii_cfg_10MB(uint32_t port_num, uintptr_t icssgRgmiiCfgBaseAddr, uint32_t link_status)
{
    if (link_status == EMAC_MDIO_LINKSTATUS_HD10)
    {
        emac_icssg_update_rgmii_cfg_10hd(port_num, icssgRgmiiCfgBaseAddr);
    }
    else
    {
        emac_icssg_update_rgmii_cfg_10fd(port_num, icssgRgmiiCfgBaseAddr);
    }
}

/*
 *  ======== emac_icssg_update_link_speed_10MB ========
 */
void emac_icssg_update_link_speed_10MB(uint32_t port_num, uint32_t virt_port_num, uint32_t link_status)
{
    uintptr_t icssgRgmiiCfgAddr;

    if ((virt_port_num == EMAC_SWITCH_PORT1) ||(virt_port_num == EMAC_SWITCH_PORT2))
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT1);
        emac_icssg_update_rgmii_cfg_10MB(~(port_num&1), icssgRgmiiCfgAddr, link_status);

        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, EMAC_SWITCH_PORT2);
        emac_icssg_update_rgmii_cfg_10MB((port_num&1), icssgRgmiiCfgAddr, link_status);
    }
    else
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, port_num);
        emac_icssg_update_rgmii_cfg_10MB(port_num, icssgRgmiiCfgAddr, link_status);
         /* issue speed_duplexity ioctl to fw */
        if (link_status == EMAC_MDIO_LINKSTATUS_HD10)
        {
            emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_10HD);
        }
        else
        {
            emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_10FD);
        }
    }

}
/*
 *  ======== emac_icssg_link_down ========
 */
void emac_icssg_link_down(uint32_t port_num, uint32_t virt_port_num)
{
    uint32_t regVal;
    uintptr_t icssgRgmiiCfgAddr;

    if ((virt_port_num != EMAC_SWITCH_PORT1) && (virt_port_num != EMAC_SWITCH_PORT2))
    {
        icssgRgmiiCfgAddr = emac_get_icssg_rgmii_cfg_base_addr(port_num, port_num);
        regVal = CSL_REG32_RD(icssgRgmiiCfgAddr);
        if ((port_num & 1) == 0)
        {
            regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_GIG_IN_MASK;
            regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_FULLDUPLEX_IN_MASK;
            regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII0_INBAND_MASK;
        }
        else
        {
            regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_GIG_IN_MASK;
            regVal |= CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_FULLDUPLEX_IN_MASK;
            regVal &= ~CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RGMII_CFG_RGMII1_INBAND_MASK;
        }
        CSL_REG32_WR (icssgRgmiiCfgAddr, regVal);
        emac_configure_link_speed_duplexity(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_DISABLE);
    }
}

static void emac_icssg_update_link_params(uint32_t port_num, uint32_t virt_port_num, EMAC_LINK_INFO_T *p_info)
{
    if(port_num == EMAC_CPSW_PORT_NUM)
    {
        if (p_info->link_status == EMAC_MDIO_LINKSTATUS_FD10     ||
            p_info->link_status == EMAC_MDIO_LINKSTATUS_FD100    ||
            p_info->link_status == EMAC_MDIO_LINKSTATUS_FD1000)
        {
            CSL_CPGMAC_SL_enableFullDuplex(emac_mcb.port_cb[port_num].hCpswRegs,0);
            if (p_info->link_status == EMAC_MDIO_LINKSTATUS_FD1000)
            {
                CSL_CPGMAC_SL_enableGigabit(emac_mcb.port_cb[port_num].hCpswRegs,0);
            }
            else
            {
                CSL_CPGMAC_SL_disableGigabit(emac_mcb.port_cb[port_num].hCpswRegs,0);
            }
        }
        else
        {
            CSL_CPGMAC_SL_disableFullDuplex(emac_mcb.port_cb[port_num].hCpswRegs,0);
            CSL_CPGMAC_SL_disableGigabit(emac_mcb.port_cb[port_num].hCpswRegs,0);
        }
    }
    /* ICSSG ports */
    else
    {
        switch(p_info->link_status)
        {
            case EMAC_MDIO_LINKSTATUS_FD1000:
                emac_icssg_update_link_speed_1G(port_num, virt_port_num);
                break;
            case EMAC_MDIO_LINKSTATUS_FD100:
            case EMAC_MDIO_LINKSTATUS_HD100:
                emac_icssg_update_link_speed_100MB(port_num, virt_port_num, p_info->link_status);
                break;
            case EMAC_MDIO_LINKSTATUS_FD10:
            case EMAC_MDIO_LINKSTATUS_HD10:
                emac_icssg_update_link_speed_10MB(port_num, virt_port_num, p_info->link_status);
                break;
            default:
                emac_icssg_link_down(port_num, virt_port_num);
                break;
        }
    }
}

/*
 *  ======== emac_configure_link_speed_duplexity ========
 */
void emac_configure_link_speed_duplexity(uint32_t port_num, uint32_t val)
{
    EMAC_IOCTL_PARAMS params = {0};
    EMAC_DRV_ERR_E status;
    if (port_num < (EMAC_MAX_PORTS -1))
    {
        params.subCommand = val;
        params.seqNumber = emac_mcb.ioctl_cb.sequenceNumber++;

        emac_mcb.ioctl_cb.internalIoctl = TRUE;
        status = EMAC_ioctl_v5(port_num, EMAC_IOCTL_SPEED_DUPLEXITY_CTRL, &params);
        if (status != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            emac_mcb.ioctl_cb.internalIoctl = FALSE;
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d: error in sending speed duplexity IOCTL",port_num);
        }
    }
}

/* Nothing past this point */

