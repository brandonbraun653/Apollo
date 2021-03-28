/*
 * Copyright (C) 2010-2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *   @file  test_main_keystone.c
 *
 *   @brief
 *      This is the Loopback test code for the EMAC Driver. The test code uses
 *      XDC/BIOS and showcases usage of the EMAC Driver exported API
 *      for sending/receiving Ethernet packets.
 */
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/heaps/HeapBuf.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/hal/Hwi.h>


#ifdef __ARM_ARCH_7A__
#include <ti/sysbios/family/arm/a15/Mmu.h>
#endif

#include <xdc/cfg/global.h>

/* CSL Chip Functional Layer */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>

#include <ti/csl/cslr_emac.h>
#include <ti/csl/csl_pscAux.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/soc/k2g/src/cslr_soc_baseaddress.h>
#include <ti/csl/cslr_msmc.h>
#include <ti/csl/csl_cpsw.h>
/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>

#include <ti/drv/emac/soc/emac_soc_v1.h>

/* Test application local header file */
#include "test_loc.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

extern void Osal_enterSingleCoreCriticalSection(uint32_t      port_num);
extern void Osal_exitSingleCoreCriticalSection(uint32_t      port_num);

extern void Osal_beginMemAccess(void*   addr, uint32_t  size);
extern void Osal_endMemAccess(void*   addr, uint32_t  size);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
static uint32_t app_alloc_failed = 0;
static uint32_t app_alloc_fail_count = 0;
static uint32_t app_entry_count = 0;

static EMAC_LINK_INFO_T app_link_info;

#ifdef _TMS320C6X
/* Memory allocated for the packet buffer. This is 128 bytes aligned. */
static uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE];
#pragma DATA_ALIGN(app_pkt_buffer, CACHE_L2_LINESIZE)

/* Memory allocated for the application control block */
#else
static uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned (128)));
#endif

APP_EMAC_MCB_T   app_mcb;


#define APP_NUM_HOST_DESC 2048

#ifdef _TMS320C6X
#pragma DATA_ALIGN (g_app_host_desc, 128)
uint8_t                                 g_app_host_desc[EMAC_SIZE_HOST_DESC * APP_NUM_HOST_DESC];
#else
uint8_t      g_app_host_desc[EMAC_SIZE_HOST_DESC * APP_NUM_HOST_DESC] __attribute__ ((aligned (128)));
#endif

static uint32_t app_pkt_rcv_count = 0;
static uint32_t app_pkt_rcv = 0;

static EMAC_OPEN_CONFIG_INFO_T app_open_cfg;
static EMAC_HwAttrs_V1 app_emac_cfg;

int32_t static app_open_done = 0;
void app_nss_power_up (void);

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/

#define APP_PKT_SEND_COUNT  128



/* DO NOT CHANGE test_pkt UNLESS TEST_PKT_SIZE IS UPDATED */

#define APP_TEST_PKT_SIZE       64

static const uint8_t app_test_pkt[64] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0xfe,0xfe
};


/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/

/**
 *  @b app_queue_pop
 *  @n
 *      Dequeues a packet descriptor from an app queue.
 *
 *  @param[in]  pq
 *      Packet queue of type APP_PKT_QUEUE_T .
 *
 *  @retval
 *      EMAC_Pkt popped from the queue.
 */
static EMAC_PKT_DESC_T*
app_queue_pop
(
    uint32_t              port_num,
    APP_PKT_QUEUE_T*    pq
)
{
    EMAC_PKT_DESC_T*    pPktHdr;

    if (!pq->Count)
    {
        return 0;
    }

    Osal_enterSingleCoreCriticalSection(port_num);
    pPktHdr = pq->pHead;
    if( pPktHdr )
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }
    Osal_exitSingleCoreCriticalSection(port_num);

    return( pPktHdr );
}

/**
 *  @b app_queue_push
 *  @n
 *      Enqueues a packet in EMAC_Pkt queue.
 *
 *  @param[in]  pq
 *      Packet queue of type EMAC_PKT_QUEUE_T .
 *  @param[in]  pPktHdr
 *      EMAC_PKT_DESC_T type packet to push.
 *
 *  @retval
 *      void
 */
static void
app_queue_push
(
    uint32_t              port_num,
    APP_PKT_QUEUE_T*    pq,
    EMAC_PKT_DESC_T*    pPktHdr
)
{
	Osal_enterSingleCoreCriticalSection(port_num);
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
    Osal_exitSingleCoreCriticalSection(port_num);
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
app_alloc_pkt
(
    uint32_t              port_num,
    uint32_t              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;

#ifdef EMAC_TEST_ALLOC_FAIL
    if (app_entry_count++ > 32)
    {
       if ((++app_alloc_fail_count % 10) == 0 )
       {
           app_alloc_failed++;
           return NULL;
       }
    }
#endif

    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
        if (p_pkt_desc)
        {
            p_pkt_desc->AppPrivate  = (uint32_t)p_pkt_desc;
            p_pkt_desc->BufferLen   = pkt_size;
            p_pkt_desc->DataOffset  = 0;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        UART_printf ("app_alloc_pkt on port %d failed, packet size %d is too big\n", port_num, pkt_size);
        return NULL;
    }
    return p_pkt_desc;
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
app_alloc_pkt_for_send
(
    uint32_t              port_num,
    uint32_t              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;

    /* testing pkt allocation failure for idkAM437x */

    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
        if (p_pkt_desc)
        {
            p_pkt_desc->AppPrivate  = (uint32_t)p_pkt_desc;
            p_pkt_desc->BufferLen   = pkt_size;
            p_pkt_desc->DataOffset  = 0;
        }
        else
        {
            UART_printf ("app_alloc_pkt_for_send on port %d failed, out of descriptors\n", port_num);
            return NULL;
        }
    }
    else
    {
        UART_printf ("app_alloc_pkt_for_send on port %d failed, packet size %d is too big\n", port_num, pkt_size);
        return NULL;
    }
    return p_pkt_desc;
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
app_free_pkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    /* Free a packet descriptor to the free queue */
    app_queue_push(port_num, &app_mcb.emac_pcb[port_num].freeQueue,
                   (EMAC_PKT_DESC_T *)p_pkt_desc->AppPrivate);
}

/**
 *  @b app_display_linkstatus
 *  @n
 *      This function is called whenever there is a change in link state on
 *      master core.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  link_status
 *      Status of the link.
 *
 *  @retval
 *      void
 */
void
app_display_linkstatus
(
    uint32_t              port_num,
    uint32_t              link_status
)
{
    /* This string array corresponds to link state as defined in csl_mdio.h */
    char *LinkStr[] = { "No Link",
                        "10Mb/s Half Duplex",
                        "10Mb/s Full Duplex",
                        "100Mb/s Half Duplex",
                        "100Mb/s Full Duplex",
                        "1000Mb/s Full Duplex" };

    if (app_mcb.core_num == APP_MASTER_CORE_NUM)
    {
        UART_printf("Port %d Link Status: %s on PHY %d\n",
                      port_num, LinkStr[link_status],
                      app_mcb.emac_pcb[port_num].phy_addr);
    }
}


/**
*  @b Description
*  @n
*      Intialize the application control block, free/rx packet queue.
*
*  @retval
*      None.
*/
void
app_init(void)
{
    uint32_t              i, j;
    EMAC_PKT_DESC_T*    p_pkt_desc;
    Uint8*              pktbuf_ptr;

    UART_printf ("EMAC loopback test application initialization\n");

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (APP_EMAC_MCB_T));

#ifdef _TMS320C6X
    app_mcb.core_num = CSL_chipReadReg (CSL_CHIP_DNUM);
#else
    app_mcb.core_num = 0;
#endif
    pktbuf_ptr = (Uint8 *) ((uint32_t) app_pkt_buffer | 0x10000000);


    /* Initialize the free packet queue */
    for (i=0; i<MAX_NUM_EMAC_PORTS; i++)
    {
        app_mcb.emac_pcb[i].freeQueue.pHead = NULL;
        app_mcb.emac_pcb[i].freeQueue.pTail  = NULL;
        if (i == 0)
        {
            app_mcb.emac_pcb[0].phy_addr   = APP_PORT0_PHY_ADDR;
        }

        for (j=0; j<APP_MAX_PKTS; j++)
        {
            p_pkt_desc               = &app_mcb.emac_pcb[i].pkt_desc[j];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = APP_EMAC_MAX_PKT_SIZE;
            app_queue_push( i, &app_mcb.emac_pcb[i].freeQueue, p_pkt_desc );
            pktbuf_ptr += APP_EMAC_MAX_PKT_SIZE;
        }
    }
}


/******************************************************************************
 * Function: EMAC RX packet call back function
 ******************************************************************************/
/**
 *  @brief  This function is used to call back the network application when a
 *          packet is received.
 */
void app_test_rx_pkt_cb(uint32_t               port_num, EMAC_PKT_DESC_T*     p_desc)
{
    if (memcmp(p_desc->pDataBuffer, app_test_pkt, p_desc->BufferLen) == 0)
    {
        app_pkt_rcv_count++;
        UART_printf("received packet: %d\n", app_pkt_rcv_count);
    }
    else
    {
        UART_printf("packet match failed\n");
    }
    
    app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
    app_pkt_rcv = 1;
}


static void app_test_task_emac_init(UArg arg0, UArg arg1)
{
    uint32_t mac1 = 0;
    uint32_t mac2 = 0;
    int32_t i;
    EMAC_MAC_ADDR_T app_mac_test;
    EMAC_DRV_ERR_E app_open_ret;
    EMAC_CHAN_MAC_ADDR_T app_chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];
    app_nss_power_up();
    
    EMAC_socGetInitCfg(0, &app_emac_cfg);
    /* Need to update the descriptor base address */
    app_emac_cfg.p_desc_base = &g_app_host_desc;
    
     /* Now set the config after updating desc base address */
     EMAC_socSetInitCfg(0, &app_emac_cfg);
    
     app_init();
    
    app_open_cfg.hwAttrs = (void*)&app_emac_cfg;
    app_open_cfg.alloc_pkt_cb = app_alloc_pkt;
    app_open_cfg.free_pkt_cb = app_free_pkt;
    app_open_cfg.loop_back = 1;
    app_open_cfg.master_core_flag = 1;
    app_open_cfg.max_pkt_size = 1514; /* need to check this */
    app_open_cfg.mdio_flag = 1;
    app_open_cfg.num_of_chans = 1;
#ifdef _TMS320C6X
    app_open_cfg.num_of_rx_pkt_desc = 16;
    app_open_cfg.num_of_tx_pkt_desc = 16;
#else
app_open_cfg.num_of_rx_pkt_desc = 512;
app_open_cfg.num_of_tx_pkt_desc = 512;
#endif
    app_open_cfg.phy_addr = 0;
    
    app_open_cfg.p_chan_mac_addr = &app_chan_cfg[0];
        
    app_open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;
    
    
    /* Set the channel configuration */
    app_chan_cfg[0].chan_num = 0;
    app_chan_cfg[0].num_of_mac_addrs = 1;
    CSL_BootCfgGetMacIdentifier(&mac1, &mac2);
    
    app_mac_test.addr[0] = ((mac2 & 0x0000ff00) >> 8);
    app_mac_test.addr[1] =  (mac2 & 0x000000ff);
    app_mac_test.addr[2] = ((mac1 & 0xff000000) >> 24);
    app_mac_test.addr[3] = ((mac1 & 0x00ff0000) >> 16);
    app_mac_test.addr[4] = ((mac1 & 0x0000ff00) >> 8);
    app_mac_test.addr[5] =  (mac1 & 0x000000ff);
    app_chan_cfg[0].p_mac_addr = & app_mac_test;
    
    for (i=0;i<6;i++)
    {
        UART_printf("app_mac_test[%d]: 0x%x\n", i, app_mac_test.addr[i]);
    }
    
    
    
        if ((app_open_ret = emac_open(0, &app_open_cfg)) == EMAC_DRV_RESULT_OPEN_PORT_ERR)
        {
            UART_printf("main: emac_open failure: %d\n", app_open_ret);
        }
        else
            UART_printf("main: emac_open sucess\n");
    

        app_open_done =1;

}
static void app_test_task_poll_link(UArg arg0, UArg arg1)
{
    memset(&app_link_info, 0, sizeof(EMAC_LINK_INFO_T));

   while(app_open_done == 0)
        Task_sleep(1000);

    CSL_CPSW_ALE_PORTCONTROL    app_ale_port_ctrl;
    memset(&app_ale_port_ctrl, 0, sizeof(CSL_CPSW_ALE_PORTCONTROL));
    while(1)
    {
        emac_poll(0, &app_link_info);
        Task_sleep(1000);
       
       if(app_link_info.link_status_change && (app_link_info.link_status !=EMAC_LINKSTATUS_NOLINK))
       {
           app_ale_port_ctrl.portState = ALE_PORTSTATE_FORWARD;
            CSL_CPSW_setAlePortControlReg(1, &app_ale_port_ctrl);
       }
       if(app_link_info.link_status_change && (app_link_info.link_status == EMAC_LINKSTATUS_NOLINK))
       {
           app_ale_port_ctrl.portState = ALE_PORTSTATE_DISABLED;
            CSL_CPSW_setAlePortControlReg(1, &app_ale_port_ctrl);
       }

        }
}

static void app_test_task_poll_pkt (UArg arg0, UArg arg1)
{
    while(1)
    {
        emac_poll_pkt(0);
         Task_sleep(10);
    }
}


EMAC_STATISTICS_T stats;

static void app_test_task_send_pkts(UArg arg0, UArg arg1)
{
    uint32_t i;
    uint32_t port_num = 0;
    static uint32_t pkt_send_count =0;
    EMAC_PKT_DESC_T *p_pkt_desc;
    int32_t fail_count = 0;

    while(app_open_done == 0)
        Task_sleep(100);

    for (i = 0; i < APP_PKT_SEND_COUNT/2; i++)
    {

        p_pkt_desc = app_alloc_pkt_for_send(0, APP_TEST_PKT_SIZE);
        memcpy (p_pkt_desc->pDataBuffer, &app_test_pkt[0], APP_TEST_PKT_SIZE);
        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->Flags        = 0;
        p_pkt_desc->ValidLen     = APP_TEST_PKT_SIZE;  /* make the APP_TEST_PKT_SIZE 64 bytes */
        p_pkt_desc->DataOffset   = 0;
        p_pkt_desc->PktChannel   = 0;
        p_pkt_desc->PktLength    = APP_TEST_PKT_SIZE;
        p_pkt_desc->BufferLen = APP_TEST_PKT_SIZE;
        p_pkt_desc->PktFrags     = 1;   /* need to check this */
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;

        pkt_send_count++;

        UART_printf("sending packet: %d\n", pkt_send_count);
        emac_send(port_num, p_pkt_desc);

        while(app_pkt_rcv == 0)
        {
            Task_sleep(100);
            
            fail_count++;
            if(fail_count == 5)
            {
                fail_count = 0;
                break;
            }
        }
        app_pkt_rcv = 0;
    }

    app_alloc_fail_count = 0;
    app_entry_count = 0;

    if (emac_close(0) == EMAC_DRV_RESULT_OK)
    {
        UART_printf("emac close sucess\n");
    }
    else
    {
        UART_printf("emac close failed\n");
        while(1);
    }
    /* re-int the app */
    app_init();
    UART_printf("calling emac_open again\n");
    if (emac_open(0, &app_open_cfg) == EMAC_DRV_RESULT_OK)
    {
        UART_printf("emac open  sucess\n");
    }
    else
    {
        UART_printf("emac open failed\n");
        while(1);
    }

    for (i = 0; i < APP_PKT_SEND_COUNT/2; i++)
    {
        p_pkt_desc = app_alloc_pkt_for_send(0, APP_TEST_PKT_SIZE);
        memcpy (p_pkt_desc->pDataBuffer, &app_test_pkt[0], APP_TEST_PKT_SIZE);
        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->Flags        = 0;
        p_pkt_desc->ValidLen     = APP_TEST_PKT_SIZE;  /* make the APP_TEST_PKT_SIZE 64 bytes */
        p_pkt_desc->DataOffset   = 0;
        p_pkt_desc->PktChannel   = 0;
        p_pkt_desc->PktLength    = APP_TEST_PKT_SIZE;
        p_pkt_desc->BufferLen = APP_TEST_PKT_SIZE;
        p_pkt_desc->PktFrags     = 1;   /* need to check this */
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;

        pkt_send_count++;
        UART_printf("sending packet: %d\n",  pkt_send_count);
        

        emac_send(port_num, p_pkt_desc);

        while(app_pkt_rcv == 0)
        {
            Task_sleep(100);
            fail_count++;
            if(fail_count == 5)
            {
                fail_count = 0;
                break;
            }
        }
        app_pkt_rcv = 0;
       
    }

     UART_printf("Test case to validate burst packet RX at host which could could result in buffer allocation failure\n");
     UART_printf("Expected alloc failed to be >= 0 in logs\n");
     UART_printf("packets sent: %d, packets received: %d, alloc failures: %d\n", APP_PKT_SEND_COUNT, app_pkt_rcv_count, app_alloc_failed);
    if ((app_pkt_rcv_count + app_alloc_failed)==  APP_PKT_SEND_COUNT)
    {
        UART_printf("All tests have passed\n");
     }
}


/***************************************************************************************
 * FUNCTION PURPOSE: Power up PA subsystem
 ***************************************************************************************
 * DESCRIPTION: this function powers up the PA subsystem domains
 ***************************************************************************************/
void app_nss_power_up (void)
{
    /* PASS power domain is turned OFF by default. It needs to be turned on before doing any 
     * PASS device register access. This not required for the simulator. */

    /* Set NSS Power domain to ON */        
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NSS);

    /* Enable the clocks for NSS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS, PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NSS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NSS));
}
/**
*  @b Description
*  @n
*      Entry point for the application test code.
*
*  @retval
*      None.
*/
int main(void)
{
    Task_Params     taskParams;

    Board_STATUS boardInitStatus =0;
    Error_Block eb;
    Error_init(&eb);


#ifdef __ARM_ARCH_7A__
    /* Add MMU entries for MMR's required for PCIE example */
    uint32_t privid, index;
    CSL_MsmcRegs *msmc = (CSL_MsmcRegs *)CSL_MSMC_CFG_REGS;
    Mmu_DescriptorAttrs attrs;
    extern char ti_sysbios_family_arm_a15_Mmu_Module_State_0_secondLevelTableBuf_1__A;
    uint32_t addr = (uint32_t)&ti_sysbios_family_arm_a15_Mmu_Module_State_0_secondLevelTableBuf_1__A;

    Mmu_initDescAttrs(&attrs);

    attrs.type = Mmu_DescriptorType_TABLE;
    attrs.shareable = 0;            // non-shareable
    attrs.accPerm = 1;              // read/write at any privelege level
    attrs.attrIndx = 0;             // Use MAIR0 Register Byte 3 for
                                    // determining the memory attributes
                                    // for each MMU entry


    // Update the first level table's MMU entry for 0x80000000 with the
    // new attributes.
    Mmu_setFirstLevelDesc((Ptr)0x40000000, (UInt64)addr, &attrs);

    // Set up SES & SMS to make all masters coherent
    for (privid = 0; privid < 16; privid++)
    {
      for (index = 0; index < 8; index++)
      {
        uint32_t ses_mpaxh = msmc->SES_MPAX_PER_PRIVID[privid].SES[index].MPAXH;
        uint32_t sms_mpaxh = msmc->SMS_MPAX_PER_PRIVID[privid].SMS[index].MPAXH;
        if (CSL_FEXT (ses_mpaxh, MSMC_SES_MPAXH_0_SEGSZ) != 0)
        {
          // Clear the "US" bit to make coherent.  This is at 0x80.
          ses_mpaxh &= ~0x80;
          msmc->SES_MPAX_PER_PRIVID[privid].SES[index].MPAXH = ses_mpaxh;
       }
        if (CSL_FEXT (sms_mpaxh, MSMC_SMS_MPAXH_0_SEGSZ) != 0)
        {
          // Clear the "US" bit to make coherent.  This is at 0x80.
          sms_mpaxh &= ~0x80;
          msmc->SMS_MPAX_PER_PRIVID[privid].SMS[index].MPAXH = sms_mpaxh;
        }
      }
    }
#endif

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK;
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=0)
    {
        UART_printf("Board_init failure\n");
        while(1);
    }
    UART_printf("Board_init success\n");

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "EmacDrvInit";
    Task_create(app_test_task_emac_init, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacPollLink";
    Task_create(app_test_task_poll_link, &taskParams, &eb);

    /* Create the UnitTest Task.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacSendPkt";
    Task_create(app_test_task_send_pkts, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacPktPkt";
    Task_create(app_test_task_poll_pkt, &taskParams, NULL);


    /* Start BIOS */
    BIOS_start();
}

