/*
 * Copyright (C) 2010-2017 Texas Instruments Incorporated - http://www.ti.com/
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
 *   @file  emac_drv_v0.c
 *
 *   @brief   
 *      The file implements the Ethernet Driver API which can be used to send 
 *      and receive Ethernet packets through the EMAC module. The driver 
 *      utilizes the CSL EMAC Functional layer.
 *
 */

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Hardware Platform Configuration Header. */
#include <ti/drv/emac/emac_hwcfg.h>

/* CSL Headers */
#include <ti/csl/csl_emac.h>
#include <ti/csl/csl_emacAux.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/cslr_ectl.h>
#ifdef TWO_PORT_DEV
#include <ti/csl/csl_psc.h>
#endif

/* 
 * OSAL defintions: This file can be overriden by customers
 * to point to their copies. 
 */
#include <ti/drv/emac/src/emac_osal.h>

/* EMAC Driver API Header. */
#include <ti/drv/emac/emac_drv.h>

/* EMAC Driver Local Header */
#include "inc/emac_loc.h"
#include <ti/drv/emac/soc/emac_soc_v0.h>

/**********************************************************************
 *************************** EMAC Global Variables*********************
 **********************************************************************/

/*
 * CSL EMAC device control data that are used by all the cores, 
 * which needs to be placed in shared internal or external memory,
 * the data structure needs to be aligned to 128 bytes cache line size
 */
EMAC_Device emac_comm_dev0;
#pragma DATA_SECTION(emac_comm_dev0, "emacComm")
#pragma DATA_ALIGN(emac_comm_dev0, CACHE_L2_LINESIZE)

#ifdef TWO_PORT_DEV
EMAC_Device emac_comm_dev1;
#pragma DATA_SECTION(emac_comm_dev1, "emacComm")
#pragma DATA_ALIGN(emac_comm_dev1, CACHE_L2_LINESIZE)
#endif

/*
 * EMAC common control data that are used by all the cores, 
 * which needs to be placed in shared internal or external memory,
 * the data structure needs to be aligned to 128 bytes cache line size
 */
EMAC_COMMON_PCB_T emac_comm_pcb0;
#pragma DATA_SECTION(emac_comm_pcb0, "emacComm")
#pragma DATA_ALIGN(emac_comm_pcb0, CACHE_L2_LINESIZE)

#ifdef TWO_PORT_DEV
EMAC_COMMON_PCB_T emac_comm_pcb1;
#pragma DATA_SECTION(emac_comm_pcb1, "emacComm")
#pragma DATA_ALIGN(emac_comm_pcb1, CACHE_L2_LINESIZE)
#endif

/*
 * EMAC master control block
 */
EMAC_MCB_T      emac_mcb;
#pragma DATA_ALIGN(emac_mcb, 8);
#pragma DATA_SECTION(emac_mcb, ".far:EMAC_DRV");

/*
 * EMAC version string
 */
const char emac_version_str[] = EMAC_VERSION_STR;

extern void emacLinkUpProcessing(Handle hEMAC );
/* EMAC_v0 functions */
static EMAC_DRV_ERR_E EMAC_open_v0(uint32_t port_num,  EMAC_OPEN_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E  EMAC_config_v0(uint32_t port_num,  EMAC_CONFIG_INFO_T *p_config);

static EMAC_DRV_ERR_E EMAC_close_v0(uint32_t port_num);

static EMAC_DRV_ERR_E EMAC_send_v0(uint32_t port_num, EMAC_PKT_DESC_T* p_desc);

static  EMAC_DRV_ERR_E EMAC_poll_v0(uint32_t port_num, EMAC_LINK_INFO_T* p_info);

static EMAC_DRV_ERR_E EMAC_get_stats_v0(uint32_t port_num, EMAC_STATISTICS_T*      p_stats);

static EMAC_DRV_ERR_E EMAC_interruptInit(uint32_t port_num);

void EMAC_v0_hwiFxn(uintptr_t arg);

/* EMAC function table for EMAC_v0 implementation */
const EMAC_FxnTable EMAC_FxnTable_v0 =
{
    EMAC_open_v0,
    EMAC_config_v0,
    EMAC_close_v0,
    EMAC_send_v0,
    EMAC_poll_v0,
    EMAC_get_stats_v0,
    NULL
};


/**********************************************************************
 *************************** EMAC Utility Functions *******************
 **********************************************************************/

/**
 *  @b emac_queue_pop
 *  @n
 *      Dequeues a packet descriptor from EMAC_PKT_QUEUE_T queue.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @param[in]  pq
 *      Packet descriptor queue of type EMAC_PKT_QUEUE_T.
 *
 *  @retval
 *      EMAC_Pkt popped from the queue.
 */
static EMAC_Pkt*
emac_queue_pop
( 
    Uint32              port_num,
    EMAC_PKT_QUEUE_T*   pq 
)
{
    EMAC_Pkt *pPktHdr;

    if (!pq->Count)
    {
        return 0;
    }

    Emac_osalEnterSingleCoreCriticalSection(port_num);
    pPktHdr = pq->pHead;
    if( pPktHdr )
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }
    Emac_osalExitSingleCoreCriticalSection(port_num);

    return( pPktHdr );
}


/**
 *  @b emac_queue_push
 *  @n
 *      Enqueues a packet descriptor to EMAC_PKT_QUEUE_T queue.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  pq
 *      Packet descriptor queue of type EMAC_PKT_QUEUE_T .
 *  @param[in]  pPktHdr
 *      EMAC_Pkt type packet to push.
 *
 *  @retval
 *      void
 */
static void 
emac_queue_push
( 
    Uint32              port_num,
    EMAC_PKT_QUEUE_T*   pq, 
    EMAC_Pkt*           pPktHdr 
)
{
    Emac_osalEnterSingleCoreCriticalSection(port_num);
    pPktHdr->pNext = 0;

    if( !pq->pHead )
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
    Emac_osalExitSingleCoreCriticalSection(port_num);
}


/**
 *  @b emac_get_packet
 *  @n
 *      Get a packet descriptor from the RxQueue.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *
 *  @retval
 *      EMAC_Pkt pointer of a packet descriptor with buffer to replenish by CSL.
 */
static EMAC_Pkt*
emac_get_packet
( 
    Handle      hApplication 
)
{
    EMAC_Pkt*   pPkt = NULL;
    Uint32      port_num = (Uint32)hApplication - EMAC_APP_HANDLE;

    if( port_num >= MAX_NUM_EMAC_PORTS )
    {
        emac_debug_print(("emac_get_packet core %d wrong app handle %d\n", 
               EMAC_CORE_NUM, hApplication));
        EMAC_PORT_ERROR(port_num)++;
        return NULL;
    }

    pPkt = emac_queue_pop(port_num, &EMAC_RX_QUEUE(port_num));

    if( pPkt )
    {
        pPkt->DataOffset = 0;
    }

    return( pPkt );
}

/**
 *  @b emac_free_packet
 *  @n
 *      Called by CSL to free the packet descriptor.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  p_cslPkt_desc
 *      Pointer to EMAC_Pkt type packet descriptor passed by CSL.
 *
 *  @retval
 *      void
 */
static void 
emac_free_packet
( 
    Handle      hApplication, 
    EMAC_Pkt*   p_cslPkt_desc 
)
{
    Uint32      port_num = (Uint32)hApplication - EMAC_APP_HANDLE;

    if( port_num >= MAX_NUM_EMAC_PORTS )
    {
        emac_debug_print(("emac_free_packet core %d wrong app handle %d\n", 
               EMAC_CORE_NUM, hApplication));
        EMAC_PORT_ERROR(port_num)++;
        return;
    }

    EMAC_FREE_PKT(port_num, (EMAC_PKT_DESC_T *)p_cslPkt_desc);
    emac_queue_push( port_num, &EMAC_TX_QUEUE(port_num), p_cslPkt_desc );
}

/**
 *  @b emac_rx_packet
 *  @n
 *      Called by CSL to pass the received packet descriptor to the driver.
 *
 *  @param[in]  hApplication
 *      Driver's handle.
 *  @param[in]  p_cslPkt_desc
 *      Pointer of EMAC_Pkt type packet descriptor passed by CSL.
 *
 *  @retval
 *      EMAC_Pkt pointer of a new packet descriptor with buffer to replenish by CSL.
 */
static EMAC_Pkt*
emac_rx_packet
(
    Handle      hApplication, 
    EMAC_Pkt*   p_cslPkt_desc
)
{
    Uint32              port_num = (Uint32)hApplication - EMAC_APP_HANDLE;
    EMAC_PKT_DESC_T*    p_new_pkt_desc;

    if( port_num >= MAX_NUM_EMAC_PORTS )
    {
        emac_debug_print(("emac_rx_packet core %d wrong app handle %d\n", 
               EMAC_CORE_NUM, hApplication));
        EMAC_PORT_ERROR(port_num)++;
        return NULL;
    }

    if (p_new_pkt_desc=EMAC_ALLOC_PKT(port_num, EMAC_PKT_SIZE(port_num)))
    {
        EMAC_RX_PKT(port_num, (EMAC_PKT_DESC_T *)p_cslPkt_desc);
        memcpy((void *)p_cslPkt_desc, (void *)p_new_pkt_desc, sizeof(EMAC_Pkt));
        return( p_cslPkt_desc );
    }

    /* Increment the statistics to account for packets dropped because
     * of memory squeeze
     */
    EMAC_MEM_ERROR(port_num)++;
    return p_cslPkt_desc;
}


/**
 *  @b emac_status_update
 *  @n
 *      Called from CSL on Rx/Tx MACFATAL error and from CSL timer tick function.
 *      Tells the driver of a status update.
 *
 *  @param[in]  hApplication
 *     Driver's Handle.
 *
 *  @retval
 *      void
 */
static void 
emac_status_update
( 
    Handle      hApplication 
)
{
    Uint32  port_num = (Uint32)hApplication - EMAC_APP_HANDLE;

    if( port_num >= MAX_NUM_EMAC_PORTS )
    {
        emac_debug_print(("emac_status_update core %d wrong app handle %d\n", 
               EMAC_CORE_NUM, hApplication));
        EMAC_PORT_ERROR(port_num)++;
        return;
    }

    EMAC_FATAL_ERROR(port_num)++;
}

/**
 *  @b emac_statistics_update
 *  @n
 *     Called by CSL to indicate a statistic update
 *     interrupt.
 *
 *  @param[in]  hApplication
 *     Driver's Handle.
 *
 *  @retval
 *      void
 */
static void 
emac_statistics_update
( 
    Handle      hApplication 
)
{
    Uint32  port_num = (Uint32)hApplication - EMAC_APP_HANDLE;

    if( port_num >= MAX_NUM_EMAC_PORTS )
    {
        emac_debug_print(("emac_statistics_update core %d wrong app handle %d\n", 
               EMAC_CORE_NUM, hApplication));
        EMAC_PORT_ERROR(port_num)++;
        return;
    }
    /* EMAC_Statistics updated, application can get the stats by calling emac_get_stats API */
}

#ifdef  TWO_PORT_DEV
/**
 *  @b emac_enable
 *  @n
 *     Enable the EMAC port
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      void
 */
void 
emac_enable
(
    Uint32              port_num
)
{
    CSL_PscObj          pscObj;
    CSL_PscHandle       hPsc;
    CSL_Status          status;
    CSL_PscPowerDomain  pwrDmn = CSL_PSC_PWRDMN_ALWAYSON;
    Uint32              response;
    CSL_PscPeripherals  module;

    memset(&pscObj, 0, sizeof(CSL_PscObj));

    /* Init PSC module */
    CSL_pscInit(NULL);

    /* Open PSC module to get a Handle */
    hPsc = CSL_pscOpen(&pscObj, CSL_PSC, NULL, &status);

    /* Enable clock for the specified module EMAC */
    if (port_num == CSL_EMAC_0)
    {
       module = CSL_PSC_MODULE_EMAC0;
    }
    else if (port_num == CSL_EMAC_1)
    {
       module = CSL_PSC_MODULE_EMAC1;
    }
    CSL_pscHwControl(hPsc, CSL_PSC_CMD_ENABLE_MODULE, &module);
    /*Enable EMAC Power domain GO transition */
    CSL_pscHwControl(hPsc, CSL_PSC_CMD_PWRDMN_TRNS, &pwrDmn);

    do
    {
        CSL_pscGetHwStatus(hPsc, CSL_PSC_QUERY_PWRDMN_TRANS_STAT, (void *)&response);
        response &= (1 << CSL_PSC_PWRDMN_ALWAYSON);
    }while(response != 0x0);

    /* Close the PSC module */
    CSL_pscClose(hPsc);
}
#endif /* TWO_PORT_DEV */

/**
 *  @b emac_reset_queue
 *  @n
 *     Reset the TX/RX queues
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      void
 */
void
emac_reset_queue 
(
    Uint32      port_num
)
{
    Uint32      i;
    EMAC_Pkt*   pkt_desc = EMAC_PKT_DESC(port_num);

    if (pkt_desc)
    {
        /* Free the RX queue pkt buffers */
        for( i=0; i<EMAC_NUM_RX_PKTS(port_num); i++ )
        {
            if (pkt_desc[i].AppPrivate)
            {
                EMAC_FREE_PKT(port_num, (EMAC_PKT_DESC_T *)&pkt_desc[i]);
            }
        }
        
        /* Reset the RX/TX queues */
        memset(&EMAC_RX_QUEUE(port_num), 0, sizeof(EMAC_PKT_QUEUE_T));
        memset(&EMAC_TX_QUEUE(port_num), 0, sizeof(EMAC_PKT_QUEUE_T));
    }
}

/**
 *  @b emac_init_queue
 *  @n
 *     Allocate RX packet buffer and initialize the TX/RX queues
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      void
 */
EMAC_DRV_ERR_E
emac_init_queue 
(
    Uint32      port_num
)
{
    Uint32             i;
    EMAC_Pkt*          pkt_desc;
    EMAC_PKT_DESC_T*   p_rx_pkt_desc;

    /* Allocate packet descriptors for RX/TX queues, first num_of_pkts descriptors
       are used in the RX queue, second num_of_pkts descriptors are used in the TX queue */
    pkt_desc = EMAC_PKT_DESC(port_num);
    memset ((void *)pkt_desc, 0, sizeof(EMAC_Pkt)*EMAC_NUM_TXRX_PKTS(port_num));

    /* Initialize RX queue, allocate packet descriptors with pkt buffer from the application */
    for( i=0; i<EMAC_NUM_RX_PKTS(port_num); i++ )
    {
        if ((p_rx_pkt_desc=EMAC_ALLOC_PKT(port_num, EMAC_PKT_SIZE(port_num)))==NULL)
        {
            emac_reset_queue (port_num);
            EMAC_MEM_ERROR(port_num)++;
            return EMAC_DRV_RESULT_NO_MEM_AVAIL;
        }
        memcpy((void *)&pkt_desc[i], (void *)p_rx_pkt_desc, sizeof(EMAC_Pkt));
        emac_queue_push( port_num, &EMAC_RX_QUEUE(port_num), &pkt_desc[i] );
    }

    /* Initialize TX queue */
    for ( i=EMAC_NUM_RX_PKTS(port_num); i<EMAC_NUM_TXRX_PKTS(port_num); i++ )
    {
        emac_queue_push( port_num, &EMAC_TX_QUEUE(port_num), &pkt_desc[i] );
    }
          
    return EMAC_DRV_RESULT_OK;
}

/**
 *  @b emac_free_chan_comm_pcb
 *  @n
 *     Free the channels used by the cores in common control block
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      void
 */
void
emac_free_chan_comm_pcb
(
    Uint32          port_num
)
{
    Uint32          i;
    
#ifdef MULTI_CORE_DEV
    Emac_osalEnterMultipleCoreCriticalSection(port_num);
    Emac_osalBeginMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
    for (i=0; i<MAX_NUM_EMAC_CHANS_PER_PORT; i++)
    {
        if (EMAC_COMM_PCB(port_num)->core_num[i] == EMAC_CORE_NUM)
        {
            EMAC_COMM_PCB(port_num)->core_num[i] = EMAC_INVALID_CORE_NUM;
            EMAC_COMM_PCB(port_num)->chans_used--;
        }
    }
#ifdef MULTI_CORE_DEV
    Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
    Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
}

/**
 *  @b emac_free_macaddr
 *  @n
 *     Free the buffer allocated to store the MAC addresses
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  macaddr_cfg
 *      Pointer to EMAC_AddrConfig type configuration data.
 *
 *  @retval
 *      void
 */
void
emac_free_macaddr
(
    Uint32                  port_num,
    EMAC_AddrConfig**       macaddr_cfg
)
{
    Uint32          i;
    
    if (macaddr_cfg)
    {
        for (i=0; i<EMAC_NUM_MACADDRS(port_num); i++)
        {
            if (macaddr_cfg[i])
            {
                Emac_osalFree((void *)macaddr_cfg[i], sizeof(EMAC_AddrConfig));
            }
        }
        Emac_osalFree((void *)macaddr_cfg, 
                      sizeof(EMAC_AddrConfig *)*EMAC_NUM_MACADDRS(port_num));
    }
}

/**
 *  @b emac_reset
 *  @n
 *     Reset the EMAC port
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      void
 */
void
emac_reset
(
    Uint32                      port_num
)
{
    /* Reset EMAC MCB when closing a port */
    emac_free_chan_comm_pcb(port_num);
    emac_free_macaddr(port_num, EMAC_MACADDR_CFG(port_num));
    emac_reset_queue(port_num);

    emac_mcb.core_num = EMAC_INVALID_CORE_NUM;
    memset (&emac_mcb.core_pcb, 0, sizeof(EMAC_CORE_PCB_T)*MAX_NUM_EMAC_PORTS);
}

/**
 *  @b EMAC_HwIntRx
 *  @n
 *      EMAC Receive ISR.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static void EMAC_HwIntRx(uintptr_t arg); /* for misra warning */
static void EMAC_HwIntRx(uintptr_t arg)
{
    emac_int_service((Uint32)arg, TRUE);
    return;
}

/**
 *  @b EMAC_HwIntTx
 *  @n
 *      EMAC Transmit ISR.
 *
 *  @param[in]  void
 *
 *  @retval
 *      void
 */
static void EMAC_HwIntTx(uintptr_t arg); /* for misra warning */
static void EMAC_HwIntTx(uintptr_t arg)
{
   emac_int_service((Uint32)arg, FALSE);
   return;
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

    EMAC_HwAttrs_V0 hwAttrs;
    OsalRegisterIntrParams_t interruptRegParams;
    void*                   hwi_rx;                /* Hwi object */
    void*                   hwi_tx;                /* Hwi object */

    EMAC_DRV_ERR_E status = EMAC_DRV_RESULT_OK;

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    static uint32_t cookie = 0;

    cookie = EMAC_osalHardwareIntDisable();

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.arg  = (uintptr_t)port_num;
    interruptRegParams.corepacConfig.corepacEventNum = hwAttrs.rxEventId;

#if defined(__TI_ARM_V5__)
    /* SYS/BIOS ARMV5 core dispatches the ISR based on priority.
     * As the Timer interrupt has high priority(0x15), EMAC interrupt
     * priority is set based on the timer priority for OMAPL13x platform.
     */
    interruptRegParams.corepacConfig.priority = 0x10;
#else
    interruptRegParams.corepacConfig.priority = 0x20;
#endif

    interruptRegParams.corepacConfig.intVecNum = hwAttrs.rxIntrNum;
    interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))&EMAC_HwIntRx;

    EMAC_osalRegisterInterrupt(&interruptRegParams,&(hwi_rx));

    if(hwi_rx == NULL)
    {
        status =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    else
    {
        EMAC_osalHardwareIntrEnable(hwAttrs.rxEventId,hwAttrs.rxIntrNum);
    }

    if (status == EMAC_DRV_RESULT_OK)
    {

        /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);
        interruptRegParams.corepacConfig.name=NULL;
        interruptRegParams.corepacConfig.arg  = (uintptr_t)port_num;
        interruptRegParams.corepacConfig.corepacEventNum = hwAttrs.txEventId;

#if defined(__TI_ARM_V5__)
         /* SYS/BIOS ARMV5 core dispatches the ISR based on priority.
          * As the Timer interrupt has high priority(0x15), EMAC interrupt
          * priority is set based on the timer priority for OMAPL13x platform.
          */
        interruptRegParams.corepacConfig.priority = 0x10;
#else
        interruptRegParams.corepacConfig.priority = 0x20;
#endif

        interruptRegParams.corepacConfig.intVecNum = hwAttrs.txIntrNum;
        interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))&EMAC_HwIntTx;

        EMAC_osalRegisterInterrupt(&interruptRegParams,&(hwi_tx));


        if (hwi_tx == NULL)
        {
            status =  EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
        else
        {
           EMAC_osalHardwareIntrEnable(hwAttrs.txEventId,hwAttrs.txIntrNum);
        }
    }
    /* Restore global interrupts */
    EMAC_osalHardwareIntRestore(cookie);
    return status;
}
/**
 *  @b emac_init
 *  @n
 *     Initialize the EMAC port when it is opened
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_config
 *      Pointer of the emac open cofiguration data.
 *
 *  @retval
 *      void
 */
EMAC_DRV_ERR_E
emac_init
(
    Uint32                      port_num,
    EMAC_OPEN_CONFIG_INFO_T*    p_config
)
{
    Uint32                      i, j, chan_idx, macaddr_idx;
    EMAC_CHAN_CFG_T*            chan_cfg;
    EMAC_AddrConfig **          macaddr_cfg;
    EMAC_CHAN_MAC_ADDR_T*       p_chan_macaddr;
    EMAC_DRV_ERR_E              result;
    static Bool                 first_time0 = TRUE;
#ifdef TWO_PORT_DEV
    static Bool                 first_time1 = TRUE;
#endif
    Bool                        first_time[MAX_NUM_EMAC_PORTS];
#ifdef _TMS320C6X
    EMAC_HwAttrs_V0       *hwAttrs;
    hwAttrs = (EMAC_HwAttrs_V0*)p_config->hwAttrs;
#endif
    /* Initialize EMAC MCB when opening a port */
    memset (&emac_mcb.core_pcb[port_num], 0, sizeof(EMAC_CORE_PCB_T));

    if (port_num == 0)
    {
        EMAC_COMM_PCB(0) = &emac_comm_pcb0;
        EMAC_COMM_DEV(0) = &emac_comm_dev0;
        first_time[0]    = first_time0;
    }
#ifdef  TWO_PORT_DEV
    else
    {
        EMAC_COMM_PCB(1) = &emac_comm_pcb1;
        EMAC_COMM_DEV(1) = &emac_comm_dev1;
        first_time[1]    = first_time1;
    }
#endif        

#ifdef MULTI_CORE_DEV
    Emac_osalBeginMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif

    if (first_time[port_num] && p_config->master_core_flag)
    {
        /* 
         * Initialize common emac pcb only once 
         * when the master core first opens an port 
         */
        memset(EMAC_COMM_PCB(port_num), 0, sizeof(EMAC_COMMON_PCB_T));
        
        for (j=0; j<MAX_NUM_EMAC_CHANS_PER_PORT; j++)
        {
            EMAC_COMM_PCB(port_num)->core_num[j] = EMAC_INVALID_CORE_NUM;
        }
        
        if (port_num == 0)
        {
            first_time0 = FALSE;
        }
#ifdef  TWO_PORT_DEV
        else
        {
            first_time1 = FALSE;
        }
#endif
    }

    if ((p_config->num_of_chans+EMAC_COMM_PCB(port_num)->chans_used)>MAX_NUM_EMAC_CHANS_PER_PORT)
    {
        emac_debug_print(("emac_init core %d port %d channel not available, channel used/allocting: %d/%d\n", 
               EMAC_CORE_NUM, port_num, EMAC_COMM_PCB(port_num)->chans_used, p_config->num_of_chans));
#ifdef MULTI_CORE_DEV
        Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
        return EMAC_DRV_RESULT_NO_CHAN_AVAIL;
    }
    
    chan_cfg = EMAC_CHAN_CFG(port_num);
#ifdef _TMS320C6X
    if(hwAttrs->coreNum < 0)
    {
        EMAC_CORE_NUM = CSL_chipReadReg(CSL_CHIP_DNUM);
    }
    else
    {
        EMAC_CORE_NUM = hwAttrs->coreNum;
    }
#endif
    EMAC_MASTER_CORE(port_num)              = p_config->master_core_flag;
    EMAC_MDIO(port_num)                     = p_config->mdio_flag;
    EMAC_NUM_RX_PKTS(port_num)              = p_config->num_of_rx_pkt_desc;
    EMAC_NUM_TXRX_PKTS(port_num)            = EMAC_NUM_RX_PKTS(port_num) + p_config->num_of_tx_pkt_desc;
    EMAC_PKT_SIZE(port_num)                 = p_config->max_pkt_size;
    EMAC_NUM_CHANS(port_num)                = p_config->num_of_chans;
    
    /* Initialize Channel/MAC address configurations */
    chan_idx = 0;
    for (i=0; i<MAX_NUM_EMAC_CHANS_PER_PORT; i++)
    {
        if (EMAC_COMM_PCB(port_num)->core_num[i] == EMAC_INVALID_CORE_NUM)
        {
            /* Allocate a free channel */
            EMAC_COMM_PCB(port_num)->core_num[i]            = EMAC_CORE_NUM;
            EMAC_COMM_PCB(port_num)->chans_used++;
            
            /* Save the channel number to local MCB */ 
            chan_cfg[chan_idx].chan_num                     = i;
            chan_cfg[chan_idx].num_of_mac_addrs             = 
                p_config->p_chan_mac_addr[chan_idx].num_of_mac_addrs;
            /* Save the channel number which will be returned to application */ 
            p_config->p_chan_mac_addr[chan_idx].chan_num    = i;
            
            /* Save the total number of MAC addresses configured */
            EMAC_NUM_MACADDRS(port_num) += chan_cfg[chan_idx++].num_of_mac_addrs;
            /* Save the enable bit in the channel bitmap for the allocated channel */
            EMAC_CHAN_BITMAP(port_num) |= (1<<i);
        }
        
        if (chan_idx == p_config->num_of_chans)
        {
            break;
        }
    }
 
    /* Allocate MAC address memory and initialize MAC address */
    macaddr_cfg = (EMAC_AddrConfig **)
        Emac_osalMalloc(sizeof(EMAC_AddrConfig *)*EMAC_NUM_MACADDRS(port_num));
        
    if (macaddr_cfg == NULL)
    {
        EMAC_MEM_ERROR(port_num)++;
        emac_free_macaddr(port_num, macaddr_cfg);
#ifdef MULTI_CORE_DEV
        Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
        return EMAC_DRV_RESULT_NO_MEM_AVAIL;
    }
    memset(macaddr_cfg, 0, sizeof(EMAC_AddrConfig *)*EMAC_NUM_MACADDRS(port_num));

    emac_debug_print(("emac_init: core %d, port %d, total number of channels/MAC addresses: %d/%d\n", 
           EMAC_CORE_NUM, port_num, EMAC_NUM_CHANS(port_num), EMAC_NUM_MACADDRS(port_num)));
    
    chan_idx        = 0;
    macaddr_idx     = 0;
    p_chan_macaddr  = &p_config->p_chan_mac_addr[0];
    emac_debug_print(("MAC addresses configured for channel %d:\n", p_chan_macaddr->chan_num));

    for (i=0; i<EMAC_NUM_MACADDRS(port_num); i++)
    {
        macaddr_cfg[i] = (EMAC_AddrConfig *)Emac_osalMalloc(sizeof(EMAC_AddrConfig));
        if (macaddr_cfg[i] == NULL)
        {
            EMAC_MEM_ERROR(port_num)++;
            emac_free_macaddr(port_num, macaddr_cfg);
            emac_debug_print(("emac_init core %d port %d, MAC address config allocate memory error\n", 
                   EMAC_CORE_NUM, port_num));
#ifdef MULTI_CORE_DEV
            Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
            return EMAC_DRV_RESULT_NO_MEM_AVAIL;
        }
        macaddr_cfg[i]->ChannelNum = p_chan_macaddr->chan_num;
        memcpy (macaddr_cfg[i]->Addr, 
                p_chan_macaddr->p_mac_addr[macaddr_idx].addr,
                EMAC_MAC_ADDR_LENTH);
        emac_debug_print(("%02X-%02X-%02X-%02X-%02X-%02X\n",
               macaddr_cfg[i]->Addr[0], macaddr_cfg[i]->Addr[1], macaddr_cfg[i]->Addr[2],
               macaddr_cfg[i]->Addr[3], macaddr_cfg[i]->Addr[4], macaddr_cfg[i]->Addr[5]));

        if(++macaddr_idx == p_chan_macaddr->num_of_mac_addrs)
        {
            if (++chan_idx == p_config->num_of_chans)
            {
                break;
            }
            else
            {
                macaddr_idx       = 0;
                p_chan_macaddr    = &p_config->p_chan_mac_addr[chan_idx];
                emac_debug_print(("MAC addresses configured for channel %d:\n", p_chan_macaddr->chan_num));
            }
        }
    }
    
    /* Save the channel config pointer to EMAC MCB */
    EMAC_MACADDR_CFG(port_num) = macaddr_cfg;
    
    /* Intialize the call back function pointers in EMAC MCB */
    emac_mcb.core_pcb[port_num].rx_pkt_cb      = p_config->rx_pkt_cb;
    emac_mcb.core_pcb[port_num].alloc_pkt_cb   = p_config->alloc_pkt_cb;
    emac_mcb.core_pcb[port_num].free_pkt_cb    = p_config->free_pkt_cb;
    
    if ((result=emac_init_queue(port_num)) != EMAC_DRV_RESULT_OK)
    {
        emac_debug_print(("emac_init core %d port %d TX/RX queue initialization error %d\n", 
               EMAC_CORE_NUM, port_num, result));
        emac_reset(port_num);
#ifdef MULTI_CORE_DEV
        Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
        return result;
    }

#ifdef MULTI_CORE_DEV
    Emac_osalEndMemAccess((void *)EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T));
#endif
    return EMAC_DRV_RESULT_OK;
}

/** 
 *  @b  emac_get_version()
 *
 *  @n Retrieves the version version string.
 *
 *  @retval
 *      pointer to the version string 
 *
 * ============================================================================
 */
/**
  @brief    Retrieves the version string
*/
const char *
emac_get_version
(
    void
)
{
    return (const char *)emac_version_str;
}

/**
 *  @b emac_open
 *  @n
 *     Open the EMAC port 
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_config
 *      Pointer of the emac open cofiguration data.
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
EMAC_open_v0
(
    Uint32                      port_num,
    EMAC_OPEN_CONFIG_INFO_T*    p_config
)
{
    Uint32                  i;
    EMAC_Common_Config      commonCfg;
    EMAC_Core_Config        coreCfg;
    EMAC_DRV_ERR_E          result;
    EMAC_HwAttrs_V0       *hwAttrs;

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_open core %d wrong port number %d\n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if ((p_config == NULL)                              ||
        (p_config->num_of_chans == 0)                   ||
        (p_config->p_chan_mac_addr == NULL)             ||
        (p_config->rx_pkt_cb == NULL)                   ||
        (p_config->alloc_pkt_cb == NULL)                ||
        (p_config->free_pkt_cb == NULL)                 ||
        (p_config->num_of_tx_pkt_desc+p_config->num_of_rx_pkt_desc > MAX_EMAC_INIT_PKT_DESC)
       )
    {
        emac_debug_print(("emac_open core %d port %d wrong configurations\n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    
#ifdef MULTI_CORE_DEV
    Emac_osalEnterMultipleCoreCriticalSection(port_num);
#endif

    /* Initialize the EMAC interrupt*/
    EMAC_interruptInit(port_num);

    if ((result = emac_init(port_num, p_config)) != EMAC_DRV_RESULT_OK)
    {
        emac_debug_print(("emac_open core %d port %d initialization error %d\n", 
               EMAC_CORE_NUM, port_num, result));
#ifdef MULTI_CORE_DEV
        Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
        return result;
    }

#ifdef MULTI_CORE_DEV
    Emac_osalBeginMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
#endif
    hwAttrs = (EMAC_HwAttrs_V0*)p_config->hwAttrs;

    if(EMAC_MASTER_CORE(port_num))
    {
        /* Configure the Master core, i.e.,
         * core which does all the common EMAC
         * configuration (not channel specific).
         */

        memset(EMAC_COMM_DEV(port_num), 0, sizeof(EMAC_Device));

        /* Setup the EMAC configuration */
        if (p_config->loop_back)
        {
            commonCfg.ModeFlags     = EMAC_CONFIG_MODEFLG_FULLDUPLEX         |
                                      EMAC_CONFIG_MODEFLG_GMIIEN             |
                                      EMAC_CONFIG_MODEFLG_MACLOOPBACK;
        }
        else
        {
            commonCfg.ModeFlags     = hwAttrs->modeFlags;
        }

        commonCfg.MdioModeFlags = MDIO_MODEFLG_AUTONEG;
        if (p_config->phy_addr < EMAC_MAX_NUM_PHY_ADDR)
        {
            commonCfg.MdioModeFlags |= MDIO_MODEFLG_SPECPHYADDR;
        }
        commonCfg.UseMdio       = p_config->mdio_flag;
        commonCfg.MdioPhyAddr   = p_config->phy_addr;
        commonCfg.CoreNum       = EMAC_CORE_NUM;
        /* packet size */
        commonCfg.PktMTU        = EMAC_PKT_SIZE(port_num);
    if ((!p_config->loop_back) && EMAC_MASTER_CORE(port_num))
    {
        EMAC_sgmiiInitCfg();
    }

        i = EMAC_commonInit(port_num, &commonCfg, (Handle)EMAC_COMM_DEV(port_num), hwAttrs->macSel);
        if(i)
        {
            emac_debug_print(("emac_open core %d port %d EMAC_commonInit returned error %d\n", 
                   EMAC_CORE_NUM, port_num, i));
            EMAC_CSL_ERROR(port_num)++;
            EMAC_coreDeInit( (Handle)EMAC_COMM_DEV(port_num) );
            emac_reset(port_num);
#ifdef MULTI_CORE_DEV
            Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
            Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
            return EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
    }

#ifdef C6474
    /* Do semaphore module Initialization for the RX Path*/
    CSL_semInit(&rx_sem_context);

    /* Open a Module specific Handle*/
    rx_sem_param.flags                  = EMAC_RX_SEM_NUM; 
    EMAC_CORE_RX_SEM_HANDLE(port_num)   = CSL_semOpen(&EMAC_CORE_RX_SEM_OBJ(port_num),CSL_SEM,&rx_sem_param,&rx_sem_stat);
    if (EMAC_CORE_RX_SEM_HANDLE(port_num) == NULL)
    {
        emac_debug_print(("emac_open core %d port %d RX semaphore open error \n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    
    /* Do semaphore module Initialization for the TX Path*/
    CSL_semInit(&tx_sem_context);

    /* Open a Module specific Handle*/
    tx_sem_param.flags                  = EMAC_TX_SEM_NUM;
    EMAC_CORE_TX_SEM_HANDLE(port_num)   = CSL_semOpen(&EMAC_CORE_TX_SEM_OBJ(port_num), CSL_SEM,&tx_sem_param, &tx_sem_stat);
    if (EMAC_CORE_TX_SEM_HANDLE(port_num) == NULL)
    {
        emac_debug_print(("emac_open core %d port %d TX semaphore open error \n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
#endif

    /* Initialize the core specific configurations */
    coreCfg.ChannelInfo.TxChanEnable    = EMAC_CHAN_BITMAP(port_num);
    coreCfg.ChannelInfo.RxChanEnable    = EMAC_CHAN_BITMAP(port_num);
    coreCfg.RxMaxPktPool                = EMAC_NUM_RX_PKTS(port_num)/EMAC_NUM_CHANS(port_num);
    coreCfg.pfcbGetPacket               = &emac_get_packet;
    coreCfg.pfcbFreePacket              = &emac_free_packet;
    coreCfg.pfcbRxPacket                = &emac_rx_packet;
    coreCfg.pfcbStatus                  = &emac_status_update;
    coreCfg.pfcbStatistics              = &emac_statistics_update;

    /* selects CPPI RAM for Descriptor memory */
    coreCfg.DescBase                    = EMAC_DESC_BASE_CPPI;

    /* Set MAC address config for coreCfg */
    coreCfg.NumOfMacAddrs               = EMAC_NUM_MACADDRS(port_num);
    coreCfg.MacAddr                     = EMAC_MACADDR_CFG(port_num);

    /* Deint core */
    i = EMAC_coreDeInit((Handle)EMAC_COMM_DEV(port_num));

    if(i)
    {
        emac_debug_print(("emac_open core %d port %d EMAC_coreDeInit returned error %08x\n", 
               EMAC_CORE_NUM, port_num, i));
        EMAC_CSL_ERROR(port_num)++;
    }

    /*
     * EMAC core initialization
     */
    i = EMAC_coreInit((Handle)EMAC_COMM_DEV(port_num), 
                      (Handle)(EMAC_APP_HANDLE+port_num), &coreCfg, &EMAC_CORE_CFG(port_num));
    if(i)
    {
        emac_debug_print(("emac_open core %d port %d EMAC_coreInit returned error %08x\n", 
               EMAC_CORE_NUM, port_num, i));
        EMAC_CSL_ERROR(port_num)++;
        EMAC_coreDeInit( (Handle)EMAC_COMM_DEV(port_num) );
        emac_reset(port_num);
#ifdef MULTI_CORE_DEV
        Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
        Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }


#ifdef MULTI_CORE_DEV
    Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
    Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif

    emac_debug_print(("emac_open core %d port %d successfully\n", 
           EMAC_CORE_NUM, port_num));

    return EMAC_DRV_RESULT_OK;
}


/**
 *  @b emac_close
 *  @n
 *      Closes EMAC and disables interrupts.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
EMAC_close_v0
(
    Uint32                  port_num
)
{
    Uint32      i;
    Uint32      key;
    EMAC_HwAttrs_V0 hwAttrs;

    EMAC_socGetInitCfg(port_num, &hwAttrs);

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_close core %d wrong port number %d\n",
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    Emac_osalEnterSingleCoreCriticalSection(port_num);

#ifdef MULTI_CORE_DEV
    Emac_osalEnterMultipleCoreCriticalSection(port_num);
    Emac_osalBeginMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
#endif
    /* Disable the interrupt of the EMAC port_num */
    key = EMAC_osalHardwareIntDisable();

    EMAC_osalHardwareIntrDisable(hwAttrs.rxEventId,hwAttrs.rxIntrNum);

    EMAC_osalHardwareIntrDisable(hwAttrs.txEventId,hwAttrs.txIntrNum);

    EMAC_osalHardwareIntRestore(key);
    i = EMAC_close( (Handle)EMAC_COMM_DEV(port_num) );
#ifdef MULTI_CORE_DEV
    Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
    Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif

    if( i )
    {
        EMAC_CSL_ERROR(port_num)++;
        emac_debug_print(("EMAC_close core %d port %d Returned error %08x\n", 
               EMAC_CORE_NUM, port_num, i));
        return EMAC_DRV_RESULT_CLOSE_PORT_ERR;
    }

#ifdef EMAC_DEBUG
    emac_debug_print(("emac_close core %d port %d\n", 
           EMAC_CORE_NUM, port_num));
#endif
    emac_reset(port_num);

    return EMAC_DRV_RESULT_OK;
}

/**
 *  @b emac_config
 *  @n
 *      Sets the configuration for an EMAC port, RX filtering, multicast addresses, etc.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_config
 *      Pointer of EMAC configuration data.
 *
 *  @retval
 *      void
 */
EMAC_DRV_ERR_E
EMAC_config_v0
(
    Uint32                  port_num,
    EMAC_CONFIG_INFO_T*     p_config
)
{
    int         i;

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_config core %d wrong port number %d\n",
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_config==NULL)
    {
        emac_debug_print(("emac_config port %d wrong configurations\n", port_num));
        return EMAC_DRV_RESULT_CONFIG_PORT_ERR;
    }
    
    Emac_osalEnterSingleCoreCriticalSection(port_num);
#ifdef MULTI_CORE_DEV
    Emac_osalEnterMultipleCoreCriticalSection(port_num);
    Emac_osalBeginMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
#endif

    /* Only set the receive filter configuration on the master channel */
    i = EMAC_setReceiveFilter( (Handle)EMAC_COMM_DEV(port_num), 
                               p_config->rx_filter, 
                               EMAC_MASTER_CHAN_NUM );
    
    if( i )
    {
        emac_debug_print(("emac_config core %d port %d EMAC_setReceiveFilter returned error %08x\n", 
            EMAC_CORE_NUM, port_num, i));
        EMAC_CSL_ERROR(port_num)++;
#ifdef MULTI_CORE_DEV
        Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
        Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
        Emac_osalExitSingleCoreCriticalSection(port_num);
        return EMAC_DRV_RESULT_CONFIG_PORT_ERR;
    }
    
    if (p_config->mcast_cnt && p_config->p_mcast_list)
    {
        i = EMAC_setMulticast((Handle)EMAC_COMM_DEV(port_num), p_config->mcast_cnt, p_config->p_mcast_list);
        
        if( i )
        {
            emac_debug_print(("emac_config core %d port %d EMAC_setMulticast returned error %08x\n", 
                EMAC_CORE_NUM, port_num, i));
            EMAC_CSL_ERROR(port_num)++;
#ifdef MULTI_CORE_DEV
            Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
            Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
            Emac_osalExitSingleCoreCriticalSection(port_num);
            return EMAC_DRV_RESULT_CONFIG_PORT_ERR;
        }
    }

#ifdef MULTI_CORE_DEV
    Emac_osalEndMemAccess((void *)EMAC_COMM_DEV(port_num), sizeof(EMAC_Device));
    Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
    Emac_osalExitSingleCoreCriticalSection(port_num);
    return EMAC_DRV_RESULT_OK;
}


/**
 *  @b emac_send
 *  @n
 *      Send out a packet.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_pkt_desc
 *      Pointer of the packet descriptor.
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
EMAC_send_v0
(
    Uint32                  port_num,
    EMAC_PKT_DESC_T*        p_pkt_desc
)
{
    EMAC_Pkt*           csl_send_pkt;
    Uint32              i;

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_send core %d wrong port number %d\n",
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_pkt_desc==NULL)
    {
        emac_debug_print(("emac_send core %d port %d packet descriptor is NULL\n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_SEND_ERR;
    }

    csl_send_pkt = emac_queue_pop( port_num, &EMAC_TX_QUEUE(port_num) );

    if( csl_send_pkt )
    {
        memcpy ((void *)csl_send_pkt, (void *)p_pkt_desc, sizeof(EMAC_Pkt));

        Emac_osalEnterSingleCoreCriticalSection(port_num);
        i = EMAC_sendPacket((Handle)EMAC_COMM_DEV(port_num), csl_send_pkt);
        Emac_osalExitSingleCoreCriticalSection(port_num);

        if( i )
        {
            emac_debug_print(("EMAC_sendPacket() core %d port %d returned error %08x\n", 
                   EMAC_CORE_NUM, port_num, i));
            EMAC_CSL_ERROR(port_num)++;

            /* Free the packet as the packet did not go on the wire*/
            EMAC_FREE_PKT(port_num, p_pkt_desc);

            emac_queue_push( port_num, &EMAC_TX_QUEUE(port_num), csl_send_pkt );

            return EMAC_DRV_RESULT_SEND_ERR;
        }

        /* Packet has been transmitted */
        return EMAC_DRV_RESULT_OK;
    }
    else
    {
        emac_debug_print(("emac_send core %d port %d TX queue is empty\n", 
               EMAC_CORE_NUM, port_num));
        /* Free the packet as the packet did not go on the wire. */
        EMAC_FREE_PKT(port_num, p_pkt_desc);
        return EMAC_DRV_RESULT_SEND_ERR;
    }
}

Bool checkMDIOlink()
{
	if (MDIO_REGS->LINK == 0)
		return FALSE;
	else
		return TRUE;
}

/**
 *  @b emac_poll
 *  @n
 *      This function is called at least every 100ms, faster in a
 *      polling environment. 
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_info
 *      Pointer of the EMAC link status info.
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
EMAC_poll_v0
(
    Uint32                  port_num,
    EMAC_LINK_INFO_T*       p_info
)
{
    CSL_EmacRegs*       emacRegs;
    EMAC_DRV_ERR_E      result = EMAC_DRV_RESULT_POLL_ERR;
    Uint32              phy_addr;
    static Bool mdioLinkStatus = FALSE;
    Bool PrevLinkStatus = FALSE;
    uint32_t currentLinkStatus = 0;

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_poll core %d wrong port number %d\n",
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_info==NULL)
    {
        emac_debug_print(("emac_poll core %d port %d stats pointer is NULL\n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_POLL_ERR;
    }

    Emac_osalEnterSingleCoreCriticalSection(port_num);

    /* Validate our handle */
    if (!EMAC_COMM_DEV(port_num)->DevMagic)
    {
        emac_debug_print(("emac_poll core %d port %d not opened \n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_POLL_ERR;
    }

    p_info->link_status_change = FALSE;

    emacRegs = EMAC_COMM_DEV(port_num)->emacRegs;

    /* Only Master Core polls for the Link */
    if(EMAC_MASTER_CORE(port_num))
    {
        Uint32 mdioStatus;

        if( EMAC_MDIO(port_num) )
        {
            /* Signal the MDIO*/
            mdioStatus = MDIO_timerTick( &EMAC_COMM_DEV(port_num)->MdioDev );

            /*mdioStatus = MDIO_EVENT_LINKDOWN;
            if (checkMDIOlink())
                mdioStatus = MDIO_EVENT_LINKUP;*/
            PrevLinkStatus = mdioLinkStatus;
            mdioLinkStatus = checkMDIOlink();

            if (mdioLinkStatus != PrevLinkStatus)
            {
                /* link status has changed since last poll */
                if(mdioLinkStatus)
                {
                    currentLinkStatus = MDIO_EVENT_LINKUP;
                }
                else
                {
                    currentLinkStatus = MDIO_EVENT_LINKDOWN;
                }

                  
                if(currentLinkStatus ==  MDIO_EVENT_LINKUP)
                {
                    emacLinkUpProcessing((Handle)EMAC_COMM_DEV(0));
                }
        }   
            /* Track new or lost link */
            if( mdioStatus == MDIO_EVENT_LINKDOWN || mdioStatus == MDIO_EVENT_LINKUP )
            {
                p_info->link_status_change = TRUE;

                MDIO_getStatus( &EMAC_COMM_DEV(port_num)->MdioDev, &phy_addr, &p_info->link_status );

                /* On a new link, set the EMAC duplex */
                if( mdioStatus == MDIO_EVENT_LINKUP )
                {
                    if( p_info->link_status == MDIO_LINKSTATUS_FD10     || 
                        p_info->link_status == MDIO_LINKSTATUS_FD100    || 
                        p_info->link_status == MDIO_LINKSTATUS_FD1000 
                      )
                    {
                        CSL_FINST( emacRegs->MACCONTROL, EMAC_MACCONTROL_FULLDUPLEX, ENABLE );
                    }
                    else
                    {
                        CSL_FINST( emacRegs->MACCONTROL, EMAC_MACCONTROL_FULLDUPLEX, DISABLE );
                    }

                    if( p_info->link_status == MDIO_LINKSTATUS_FD1000 )
                    {
                        CSL_FINST(emacRegs->MACCONTROL, EMAC_MACCONTROL_GIG, ENABLE );
                    }
                }

#ifdef MULTI_CORE_DEV
                Emac_osalEnterMultipleCoreCriticalSection(port_num);
                Emac_osalBeginMemAccess(EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T) );
                memcpy (&EMAC_COMM_PCB(port_num)->link_info, p_info, sizeof(EMAC_LINK_INFO_T));
                Emac_osalEndMemAccess(EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T) );
                Emac_osalExitMultipleCoreCriticalSection(port_num);
#endif
                result = EMAC_DRV_RESULT_OK;
            }
            else if ( mdioStatus == MDIO_EVENT_PHYERROR)
            {
                emac_debug_print(("emac_poll core %d port %d NO PHY CONNECTED \n", 
                        EMAC_CORE_NUM, port_num));
                result = EMAC_DRV_RESULT_POLL_ERR;
            }
        }
    }/* MASTER_CORE*/
    else
    {
#ifdef MULTI_CORE_DEV
        Emac_osalBeginMemAccess(EMAC_COMM_PCB(port_num), sizeof(EMAC_COMMON_PCB_T) );
        memcpy(p_info, &EMAC_COMM_PCB(port_num)->link_info, sizeof(EMAC_LINK_INFO_T));
        /* only read from common PCB, no need to write cache back */
        result = EMAC_DRV_RESULT_OK;
#endif
    }

    Emac_osalExitSingleCoreCriticalSection(port_num);

    return result;
}

/**
 *  @b emac_get_stats
 *  @n
 *      This function is called to get EMAC statistics.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  p_stats
 *      Pointer of the EMAC statistics data which represent the
 *      delta values from the last time the statistics were read.
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
EMAC_get_stats_v0
(
    Uint32                  port_num,
    EMAC_STATISTICS_T*      p_stats
)
{

    if (port_num >= MAX_NUM_EMAC_PORTS)
    {
        emac_debug_print(("emac_get_stats core %d wrong port number %d\n",
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (p_stats==NULL)
    {
        emac_debug_print(("emac_get_stats core %d port %d stats pointer is NULL\n", 
               EMAC_CORE_NUM, port_num));
        return EMAC_DRV_RESULT_POLL_ERR;
    }

    if (EMAC_getStatistics((Handle)EMAC_COMM_DEV(port_num), (EMAC_Statistics *)p_stats) == 0)
    {
        emac_debug_print(("EMAC_getStatistics() core %d port %d returned error\n", 
               EMAC_CORE_NUM, port_num));
        EMAC_CSL_ERROR(port_num)++;
        
        return EMAC_DRV_RESULT_POLL_ERR;
    }
    return EMAC_DRV_RESULT_OK;
}

/**
 *  @b emac_int_service
 *  @n
 *      This function services the RX/TX interrupts.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  rx_flag
 *      RX interrupt flag
 *
 *  @retval
 *      Return code of EMAC_DRV_ERR_E type
 */
EMAC_DRV_ERR_E
emac_int_service
(
    Uint32                  port_num,
    bool                    rx_flag
)
{
    Uint32      i;
#ifdef C6474
    CSL_SemVal  response;
#endif

    if (EMAC_COMM_DEV(port_num)->DevMagic)
    {
        if (rx_flag)
        {
            /* Received a packet */
            Emac_osalEnterSingleCoreCriticalSection(port_num);
            i = EMAC_RxServiceCheck((Handle)EMAC_COMM_DEV(port_num));
            if (i)
            {
                emac_debug_print(("emac_int_service core %d port %d EMAC_RxServiceCheck() returned error %08x\n", 
                    EMAC_CORE_NUM, port_num, i));
                EMAC_CSL_ERROR(port_num)++;
	            Emac_osalExitSingleCoreCriticalSection(port_num);
                return EMAC_DRV_RESULT_ISR_ERR;
            }

#ifdef C6474
            /* Check whether Handle opened successfully and then read module status*/
            if(EMAC_CORE_RX_SEM_HANDLE(port_num) != NULL)
            {
                /* Check whether semaphore resource is Free or not */
                do{
                    /* Get the semaphore*/
                    CSL_semGetHwStatus(EMAC_CORE_RX_SEM_HANDLE(port_num), CSL_SEM_QUERY_DIRECT, &response);
                }while(response.semFree != CSL_SEM_FREE);
                
                /* write the EOI register */
                EMAC_rxEoiWrite(EMAC_CORE_NUM);
                
                /* Release the semaphore*/
                CSL_semHwControl(EMAC_CORE_RX_SEM_HANDLE(port_num), CSL_SEM_CMD_FREE_DIRECT, NULL);
            }
#endif
            Emac_osalExitSingleCoreCriticalSection(port_num);
        }
        else
        {
            /* Sent a packet */
            i = EMAC_TxServiceCheck((Handle)EMAC_COMM_DEV(port_num));
            if (i)
            {
                emac_debug_print(("emac_int_service core %d port %d EMAC_TxServiceCheck() returned error %08x\n", 
                       EMAC_CORE_NUM, port_num, i));
                EMAC_CSL_ERROR(port_num)++;
                return EMAC_DRV_RESULT_ISR_ERR;
            }

#ifdef C6474
            /* Check whether Handle opened successfully and then read module status*/
            if(EMAC_CORE_TX_SEM_HANDLE(port_num) != NULL)
            {
                /* Check whether semaphore resource is Free or not */
                do{
                    /* Get the semaphore*/
                    CSL_semGetHwStatus(EMAC_CORE_TX_SEM_HANDLE(port_num), CSL_SEM_QUERY_DIRECT, &response);
                }while(response.semFree != CSL_SEM_FREE);
                
                /* write the EOI register */
                EMAC_txEoiWrite(EMAC_CORE_NUM);
                
                /* Release the semaphore*/
                CSL_semHwControl(EMAC_CORE_TX_SEM_HANDLE(port_num), CSL_SEM_CMD_FREE_DIRECT, NULL);
            }
#endif
        }
    }
    return EMAC_DRV_RESULT_OK;
}
