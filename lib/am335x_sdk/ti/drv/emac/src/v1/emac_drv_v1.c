/**
 *  \file   emac_drv_v1.c
 *
 *  \brief  EMAC Driver APIs implementation specific to K2G.
 *
 *   The file implements the Ethernet Driver API which can be used to send 
 *      and receive Ethernet packets through the EMAC module.
 */

/*
 * Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* CSL Headers */
#include <ti/csl/csl_utils.h>
#include <ti/csl/csl_chip.h>
#ifdef _TMS320C6X
#include <ti/csl/csl_cacheAux.h>
#endif


#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/cslr_device.h>

/* CPPI LLD include */
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

/* QMSS LLD include */
#include <ti/drv/qmss/qmss_drv.h>

/* EMAC Driver API Header. */
#include <ti/drv/emac/emac_drv.h>

/* EMAC Driver Local Header */
#include "ti/drv/emac/src/v1/emac_v1.h"
#include <ti/drv/emac/src/emac_osal.h>

/* TI Osal header */
#include <ti/osal/osal.h>

extern OsalRegisterIntrParams_t interruptRegParams;
uint32_t gRxDropCounter = 0;
uint32_t gTxDropCounter = 0;
uint32_t gTxCounter = 0;


#define EMAC_MAX_NUM_EMAC_PORTS 1
/**********************************************************************
 *************************** EMAC Global Variables*********************
 **********************************************************************/


#if defined(__GNUC__) && !defined(__ti__)
CSL_SET_DALIGN(256)  /* GCC way of aligning */
#else
CSL_SET_DALIGN(emac_mcb, 256)
#endif

EMAC_MCB_V1_T      emac_mcb;


/* EMAC_v1 functions */
static EMAC_DRV_ERR_E EMAC_open_v1(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E  EMAC_config_v1(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E EMAC_close_v1(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_poll_pkt_v1(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_send_v1(uint32_t port_num, EMAC_PKT_DESC_T* p_desc);

static  EMAC_DRV_ERR_E EMAC_poll_v1(uint32_t port_num, EMAC_LINK_INFO_T* p_info);

static EMAC_DRV_ERR_E EMAC_get_stats_v1(uint32_t port_num, EMAC_STATISTICS_T*      p_stats);

void EMAC_v1_hwiFxn(uintptr_t arg);

/* EMAC function table for EMAC_v1 implementation */
const EMAC_FxnTable EMAC_FxnTable_v1 =
{
    EMAC_open_v1,
    EMAC_config_v1,
    EMAC_close_v1,
    EMAC_send_v1,
    EMAC_poll_v1,
    EMAC_get_stats_v1,
    EMAC_poll_pkt_v1
};



/** ============================================================================
 *   @n@b emac_qmss_qpop
 *
 *   @b Description
 *   @n This API implements a the queue pop logic with the Cache Management
 *
 *   @param[in]  handler
 *        Queue handler
 *   @param[in]  type
 *        Queue handler type
 *   @param[in]  pHostDescriptor
 *       pointer to  descriptor 
 * 
 *   @return
 *   @n None
 * =============================================================================
 */
int32_t 
emac_qmss_qpop
(
    Qmss_QueueHnd           handler,  
    Cppi_HostDesc**         pHostDescriptor
) 
{

    Cppi_HostDesc*      pHostDesc = *pHostDescriptor;

    pHostDesc = (Cppi_HostDesc*)(Qmss_queuePop (handler));

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
#ifdef _TMS320C6X
    EMAC_osalCacheInv((void *) pHostDesc, sizeof(Cppi_HostDesc));
    EMAC_osalCacheInv((void *)pHostDesc->buffPtr, pHostDesc->buffLen);
#endif

    return 0;

}

/** ============================================================================
 *   @n@b emac_qmss_qpush_descsize
 *
 *   @b Description
 *   @n This API implements a the queue push logic with the Cache Management
 *
 *   @param[in]  handler
 *        Queue handler
 *   @param[in]  descAddr
 *        Descriptor address
 *   @param[in]  descSize
 *        descriptor Size
 *   @return    
 *   @n None
 * =============================================================================
 */
void 
emac_qmss_qpush_descsize 
(
    Qmss_QueueHnd          handler,
    void                   *descAddr, 
    uint32_t               descSize
)
{

    Cppi_HostDesc*         pHostDesc = (Cppi_HostDesc *) descAddr;

    if ( descAddr == NULL ) {
        //gQPushErrorCounter++;
        return;
    }
    /* WbInv data cache */
#ifdef _TMS320C6X
    EMAC_osalCacheWbInv((void *)pHostDesc->buffPtr, pHostDesc->buffLen);
    EMAC_osalCacheWbInv((void *) pHostDesc, sizeof(Cppi_HostDesc));
#endif

    Qmss_queuePushDescSize (handler, 
                    pHostDesc, 
                    descSize 
                   );
    
}


/*
 *  ======== EMAC_open_v1 ========
 */
 
static EMAC_DRV_ERR_E  EMAC_open_v1(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_HwAttrs_V1       *hwAttrs;
    EMAC_Common_Config commonCfg;
    SemaphoreP_Params semParams;


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
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }

    /* Initialize EMAC MCB when opening a port */
    memset (&emac_mcb.port_cb[port_num], 0, sizeof(EMAC_PORT_CB_V1_T));

    /* Get the pointer to the hwAttrs ans socAttrs */
    hwAttrs = (EMAC_HwAttrs_V1*)p_config->hwAttrs;

    if (p_config->master_core_flag)
    {
        if (hwAttrs->initQmss)
        {
            if ((emac_init_qmss(port_num, p_config, hwAttrs)) == -1)
            {
                return EMAC_DRV_RESULT_OPEN_PORT_ERR;
            }
        }
        if (hwAttrs->initCppi)
        {
            if ((emac_init_cppi( port_num, p_config, hwAttrs)) == -1)
            {
                return EMAC_DRV_RESULT_OPEN_PORT_ERR;
            }
        }
        EMAC_PKT_SIZE(port_num)                 = p_config->max_pkt_size; /* this should be 1514 - 14 */
        memcpy(&emac_mcb.port_cb[port_num].macaddr_cfg.addr, p_config->p_chan_mac_addr->p_mac_addr, sizeof(EMAC_MAC_ADDR_T));
        emac_mcb.port_cb[port_num].loop_back = p_config->loop_back;
        /* Init the CPSW switch */
        if (emac_init_cpsw (p_config->max_pkt_size, 
            &emac_mcb.port_cb[port_num].macaddr_cfg,
            emac_mcb.port_cb[port_num].loop_back) != 0)
        {
            return EMAC_DRV_RESULT_GENERAL_ERR;
        }
   }


    /* Setup Tx */
    if ((emac_setup_tx_subsysem (port_num, p_config, hwAttrs)) != 0)
    {
        return EMAC_DRV_RESULT_GENERAL_ERR;
    }

    /* Setup Rx */
    if (emac_setup_rx_subsysem (port_num, p_config,  hwAttrs) != 0)
    {
        return EMAC_DRV_RESULT_GENERAL_ERR;
    }

    commonCfg.MdioModeFlags = MDIO_MODEFLG_AUTONEG;
    if (p_config->phy_addr < EMAC_MAX_NUM_PHY_ADDR)
    {
        commonCfg.MdioModeFlags |= MDIO_MODEFLG_SPECPHYADDR;
    }
    commonCfg.UseMdio       = p_config->mdio_flag;
    commonCfg.MdioPhyAddr   = p_config->phy_addr;
    commonCfg.CoreNum       = 0; /* for now just use core 0 */

    if (p_config->mdio_flag)
    {
        /* MDIO settings must be valid - at least one bit must be set */
        if (!(commonCfg.MdioModeFlags & (MDIO_MODEFLG_AUTONEG |
            MDIO_MODEFLG_HD10  | MDIO_MODEFLG_FD10 |
            MDIO_MODEFLG_HD100 | MDIO_MODEFLG_FD100 |
            MDIO_MODEFLG_FD1000)))
            return (EMAC_DRV_RESULT_GENERAL_ERR);
    }

    if (MDIO_open(0, commonCfg.MdioModeFlags, commonCfg.MdioPhyAddr, &emac_mcb.MdioDev, 0) == 0)
    {
        EMAC_MDIO(port_num) = p_config->mdio_flag;
    }


    EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    semParams.name= "rxSemaphore";

   EMAC_GLOBAL_RX_SEM_HANDLE(port_num) =  EMAC_osalCreateBlockingLock(0,&semParams);
    if((EMAC_GLOBAL_RX_SEM_HANDLE(port_num))==NULL)
    {
        return EMAC_DRV_RESULT_GENERAL_ERR;
    }

    EMAC_MASTER_CORE(port_num)              = p_config->master_core_flag;
    EMAC_NUM_RX_PKTS(port_num)              = p_config->num_of_rx_pkt_desc;
    EMAC_NUM_RX_PKTS(port_num)              = p_config->num_of_tx_pkt_desc;
    EMAC_NUM_TXRX_PKTS(port_num)            =  p_config->num_of_tx_pkt_desc + p_config->num_of_rx_pkt_desc;

    /* Intialize the call back function pointers in EMAC MCB */
    emac_mcb.port_cb[port_num].rx_pkt_cb      = p_config->rx_pkt_cb;
    emac_mcb.port_cb[port_num].alloc_pkt_cb   = p_config->alloc_pkt_cb;
    emac_mcb.port_cb[port_num].free_pkt_cb    = p_config->free_pkt_cb;

    emac_mcb.port_cb[port_num].emacState    = 1;
    return EMAC_DRV_RESULT_OK;
}


/*
 *  ======== EMAC_v1_hwiFxn ========
 *  Hwi interrupt handler to service the EMAC peripheral for Rx Packets
 *
 */
void EMAC_v1_hwiFxn(uintptr_t arg)
{
    uint32_t count;
    count = Qmss_getQueueEntryCount (EMAC_GLOBAL_RX_QUEUE_HND);

    if(count == 0)
    {
        /* TODO restore the interrupt and return, dont know what to pass at this time, putting 0 to compile the code */
        EMAC_osalHardwareIntRestore(0);
        return;
    }
    else
        Qmss_queueDivert(EMAC_GLOBAL_RX_QUEUE_HND, EMAC_GLOBAL_DIV_QUEUE_HND,Qmss_Location_TAIL );

    EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(0));
}

/*
 *  ======== EMAC_config_v1 ========
 */

static EMAC_DRV_ERR_E  EMAC_config_v1(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config)
{
    return EMAC_DRV_RESULT_OK;
}
/*
 *  ======== EMAC_close_v1 ========
 */
static EMAC_DRV_ERR_E EMAC_close_v1( uint32_t port_num)
{
    emac_mcb.port_cb[port_num].emacState    = 0;

    EMAC_osalPostLock(EMAC_GLOBAL_RX_SEM_HANDLE(0));

    emac_deinit_cppi(port_num);
    emac_deinit_qmss(port_num);


    EMAC_osalHardwareIntDestruct(EMAC_GLOBAL_RX_HWI_HANDLE(port_num), interruptRegParams.corepacConfig.corepacEventNum);

    EMAC_osalDeleteBlockingLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num));


    return EMAC_DRV_RESULT_OK;
}

/*
 *  ======== EMAC_get_stats_v1 ========
 */
static EMAC_DRV_ERR_E EMAC_get_stats_v1(uint32_t port_num, EMAC_STATISTICS_T*      p_stats)
{
    CSL_CPSW_STATS stats[2];
    
    memset (&stats, 0, sizeof(CSL_CPSW_STATS)*2);
    CSL_CPSW_getStats((CSL_CPSW_STATS*)&stats[0]);
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
    //p_stats->TxUnderrun = stats[0].TxUnderrun;
    p_stats->TxCarrierSLoss += stats[1].TxCarrierSLoss;
    p_stats->TxOctets += stats[1].TxOctets;

    return EMAC_DRV_RESULT_OK;
}


 

/*
 *  ======== EMAC_send_v1 ========
 */
static EMAC_DRV_ERR_E EMAC_send_v1(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
    Cppi_Desc*          pCppiDesc;
    uint32_t              i, count=0;
    Cppi_DescTag      tag;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    uintptr_t *appPtr;
    EMAC_HwAttrs_V1       hwAttrs;

    if(p_desc == NULL)
    {
        return EMAC_DRV_RESULT_SEND_ERR;
       
    }

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    /* return queue processing begin */
    count = Qmss_getQueueEntryCount (EMAC_GLOBAL_TX_RETURN_QUEUE_HND);

    for (i = 0; i < count; i++)
    {
        /* Need to free up the EMAC_PKT_DESC_T back to the application */
    
        /* Go through the TX Return queue which is where the descriptor is re-cycled after it is transmitted on the wire
            get the buffer which is this case is a EMAC_PKT_DESC_T and return it to the application/stack */

        if ((emac_qmss_qpop (EMAC_GLOBAL_TX_RETURN_QUEUE_HND, (Cppi_HostDesc **)&pCppiDesc)) != 0)
        {
            gTxDropCounter++;
            retVal = EMAC_DRV_RESULT_SEND_ERR;
            goto error_cond;
        }
        appPtr = (uintptr_t *)(((char *)pCppiDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
        if (appPtr)
        {
            EMAC_FREE_PKT(port_num, (EMAC_PKT_DESC_T*)*appPtr);

        }
        emac_qmss_qpush (EMAC_GLOBAL_TX_FREE_QUEUE_HND,
                                pCppiDesc,
                                p_desc->BufferLen, 
                                EMAC_SIZE_HOST_DESC,
                                Qmss_Location_TAIL);
    /* return queue processing end */
    }


    if (p_desc->BufferLen < EMAC_MIN_ETHERNET_PKT_SIZE)
    {
        p_desc->BufferLen = EMAC_MIN_ETHERNET_PKT_SIZE;
    }

    /* Get a free descriptor from the global free tx queue we setup during initialization. */
    if ((emac_qmss_qpop (EMAC_GLOBAL_TX_FREE_QUEUE_HND, (Cppi_HostDesc **)&pCppiDesc)) != 0)
    {
        gTxDropCounter++;
        goto error_cond;
    }


    Cppi_setData (  Cppi_DescType_HOST,
                              (Cppi_Desc *) pCppiDesc,
                              (uint8_t *) hwAttrs.local2GlobalAddr((uint32_t)p_desc->pDataBuffer),
                              p_desc->BufferLen);

    Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, p_desc->BufferLen);

    tag.srcTagHi  = 0;
    tag.srcTagLo  = 0;
    tag.destTagHi = 0;
    tag.destTagLo = port_num + 1; /* emac port */
    Cppi_setTag(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (Cppi_DescTag *)&tag);

    Cppi_setPSLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, 0);

    appPtr = (uintptr_t *)(((char *)pCppiDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
    *appPtr =(uintptr_t)p_desc;

    Osal_qmssMemBarrier(0,0);

    emac_qmss_qpush (EMAC_GLOBAL_TX_QUEUE_HND(1),
                            pCppiDesc,
                            p_desc->BufferLen, 
                            EMAC_SIZE_HOST_DESC,
                            Qmss_Location_TAIL);
    gTxCounter++;

    return EMAC_DRV_RESULT_OK;

error_cond:
{
    return retVal;
}
        }
/*
 *  ======== EMAC_poll_v1 ========
 */
static  EMAC_DRV_ERR_E EMAC_poll_v1(uint32_t port_num, EMAC_LINK_INFO_T* p_info)
{
    EMAC_DRV_ERR_E      result = EMAC_DRV_RESULT_POLL_ERR;
    uint32_t              phy_addr;
    uint32_t mdioStatus;

    if (port_num >= EMAC_MAX_NUM_EMAC_PORTS)
    {
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_info==NULL)
    {
        return EMAC_DRV_RESULT_POLL_ERR;
    }

    Emac_osalEnterSingleCoreCriticalSection(port_num);

    p_info->link_status_change = FALSE;


    /* Only Master Core polls for the Link */
    if(EMAC_MASTER_CORE(port_num))
    {
        if( EMAC_MDIO(port_num) )
        {
            /* Signal the MDIO*/
            mdioStatus = MDIO_timerTick( &emac_mcb.MdioDev);

            /* Track new or lost link */
            if( mdioStatus == MDIO_EVENT_LINKDOWN || mdioStatus == MDIO_EVENT_LINKUP )
            {
                p_info->link_status_change = TRUE;

                MDIO_getStatus( &emac_mcb.MdioDev, &phy_addr, &p_info->link_status );

                /* On a new link, set the EMAC duplex */
                if( mdioStatus == MDIO_EVENT_LINKUP )
                {
                    if( p_info->link_status == MDIO_LINKSTATUS_FD10     || 
                        p_info->link_status == MDIO_LINKSTATUS_FD100    || 
                        p_info->link_status == MDIO_LINKSTATUS_FD1000 
                      )
                    {
                        CSL_CPGMAC_SL_enableFullDuplex(port_num);
                    }
                    else
                    {
                        CSL_CPGMAC_SL_disableFullDuplex(port_num);
                    }

                    if( p_info->link_status == MDIO_LINKSTATUS_FD1000 )
                    {
                        CSL_CPGMAC_SL_enableGigabit(port_num);
                    }
                }
                result = EMAC_DRV_RESULT_OK;
            }
            else if ( mdioStatus == MDIO_EVENT_PHYERROR)
            {
                result = EMAC_DRV_RESULT_POLL_ERR;
            }
        }
    }/* MASTER_CORE*/
    else
    {
        result = EMAC_DRV_RESULT_OK;
    }

    Emac_osalExitSingleCoreCriticalSection(port_num);

    return result;
}

/** ============================================================================
 *   @n@b emac_qmss_qpush
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
emac_qmss_qpush 
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
        return;
    }
#ifdef _TMS320C6X
    /* Wb Invdata cache */ 
    EMAC_osalCacheWbInv((void *)pHostDesc->buffPtr, pHostDesc->buffLen);
    EMAC_osalCacheWbInv((void *) pHostDesc, sizeof(Cppi_HostDesc));
#endif


    Qmss_queuePushDescSize (handler, pHostDesc, descSize);
}




/*
 *  ======== EMAC_poll_pkt_v1 ========
 */
static EMAC_DRV_ERR_E EMAC_poll_pkt_v1(uint32_t port_num)
{
    Cppi_Desc*     pCppiDesc;
    Cppi_HostDesc*              pHostDesc;
    uint32_t count =            0;
    uint32_t                        i;
    EMAC_PKT_DESC_T*       p_rx_pkt_desc;
    Qmss_Queue                  rxFreeQInfo;
    uintptr_t                      *appPtr;
    uintptr_t                        key;
    int32_t  retVal;
    uint8_t *origBufPtr;
    EMAC_HwAttrs_V1       hwAttrs;
    if( emac_mcb.port_cb[port_num].emacState  == 0)
    {
            return EMAC_DRV_RESULT_GENERAL_ERR;
    }

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    while(1)
    {
        EMAC_osalPendLock(EMAC_GLOBAL_RX_SEM_HANDLE(port_num), SemaphoreP_WAIT_FOREVER);

        /* check to see if post lock done due to emac_close */
        if( emac_mcb.port_cb[port_num].emacState  == 0)
        {
            retVal =   EMAC_DRV_RESULT_GENERAL_ERR;
            break;
        }
        else
        {
            key = EMAC_osalHardwareIntDisable();
            if (key == 0U)
            {
                break;
            }
             /* Get the pointer to the private data */
            count = Qmss_getQueueEntryCount (EMAC_GLOBAL_DIV_QUEUE_HND);
    
            for (i=0;i < count;i++)
            {
                if ((emac_qmss_qpop (EMAC_GLOBAL_DIV_QUEUE_HND, (Cppi_HostDesc **)&pCppiDesc)) != 0)
                {
                    break;
                }
                pHostDesc = (Cppi_HostDesc *)pCppiDesc;
    
                if(pHostDesc == NULL)
                {
                    break;
                }
                else
                {
#ifdef _TMS320C6X
                    EMAC_osalCacheInv((void *) pHostDesc, sizeof(Cppi_HostDesc));
                    EMAC_osalCacheInv((void *)pHostDesc->buffPtr, pHostDesc->buffLen);

#endif
                /*
                 * We should not see packets too large but check anyways ...
                 * Note that we are subtracting off the FCS the switch added to the frame.
                 * If its too large then return it to the free queue.
                 */

                    if ((pHostDesc->buffLen-4) > (EMAC_PKT_SIZE(0)+ EMAC_ETHHDR_SIZE))
                    {
                        /* lets try the next one... we should record this as a too large.... */
                        gRxDropCounter++;
                        pHostDesc->buffLen = pHostDesc->origBufferLen;
                        emac_qmss_qpush (EMAC_GLOBAL_RX_FREE_QUEUE_HND,
                                (Ptr)pHostDesc,
                                pHostDesc->buffLen,
                                EMAC_SIZE_HOST_DESC,
                                Qmss_Location_TAIL);
                        continue;
                    }

                    appPtr = (uintptr_t *)(((char *)pHostDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
                    /* Update the software desciptor being passed to application */
                    p_rx_pkt_desc = (EMAC_PKT_DESC_T*) *appPtr;
                    p_rx_pkt_desc->BufferLen = pHostDesc->buffLen;
                    /* Allocate the PKT to replenish the RX_FREE_QUEUE queue */
                    if ((p_rx_pkt_desc = EMAC_ALLOC_PKT(port_num, EMAC_PKT_SIZE(port_num))) != NULL)
                    {
                        /* Call the callback */
                        EMAC_RX_PKT(0, (EMAC_PKT_DESC_T*)*appPtr);
                        /* Populate the Rx free descriptor with the buffer we just allocated. */
                        Cppi_setData (Cppi_DescType_HOST,
                                        pCppiDesc, (uint8_t *)hwAttrs.local2GlobalAddr((uint32_t)p_rx_pkt_desc->pDataBuffer),p_rx_pkt_desc->BufferLen);
    
                        /* Save original buffer information */
                        Cppi_setOriginalBufInfo (Cppi_DescType_HOST, pCppiDesc, 
                                        (uint8_t *)hwAttrs.local2GlobalAddr((uint32_t)p_rx_pkt_desc->pDataBuffer),p_rx_pkt_desc->BufferLen);

                        appPtr = (uintptr_t *)(((char *)pCppiDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
                        *appPtr =(uintptr_t)p_rx_pkt_desc;

                        /* Setup the return policy for this desc to return to the free q we just
                         * setup instead of the global free queue.
                         */
                        rxFreeQInfo = Qmss_getQueueNumber (EMAC_GLOBAL_RX_FREE_QUEUE_HND);
                        Cppi_setReturnQueue (Cppi_DescType_HOST, pCppiDesc, rxFreeQInfo);
                        Cppi_setSoftwareInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *) p_rx_pkt_desc);
                        Cppi_setPacketLen    (Cppi_DescType_HOST, pCppiDesc,p_rx_pkt_desc->BufferLen);
                        /* Push descriptor to Rx free queue */
                        emac_qmss_qpush_descsize (EMAC_GLOBAL_RX_FREE_QUEUE_HND, pCppiDesc, EMAC_SIZE_HOST_DESC);
                    }
                    else
                    /* dont free to application since replenish failed, re-use current application descriptor */
                    {
                        appPtr = (uintptr_t *)(((char *)pHostDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
                        p_rx_pkt_desc = (EMAC_PKT_DESC_T*) *appPtr;

                        Cppi_getOriginalBufInfo (Cppi_DescType_HOST,
                                                 pCppiDesc, 
                                                 &origBufPtr,
                                                 &(p_rx_pkt_desc->BufferLen));
                        Cppi_setSoftwareInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *) p_rx_pkt_desc);
                        Cppi_setPacketLen(Cppi_DescType_HOST, pCppiDesc,p_rx_pkt_desc->BufferLen);
                        /* Push descriptor to Rx free queue */
                        emac_qmss_qpush_descsize (EMAC_GLOBAL_RX_FREE_QUEUE_HND, pCppiDesc, EMAC_SIZE_HOST_DESC);
                    }
                }
            }
            EMAC_osalHardwareIntRestore(key);
        }
    }
    return (EMAC_DRV_ERR_E)(retVal);
}

