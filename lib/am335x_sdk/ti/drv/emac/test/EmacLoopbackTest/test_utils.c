/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2015
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
 *  \file     test_utils.c
 *
 *  \brief    This file contains common utility functions used by the emac loopback unit 
 *             test applications.
 *
 */

#include <string.h>

#include <xdc/std.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/csl/csl_chip.h>
/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>

/* SOC Include Files. */
#include <ti/drv/emac/soc/emac_soc_v4.h>

/* Test application local header file */
#include "test_loc.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

extern EMAC_MAC_ADDR_T macAddr1;
extern EMAC_OPEN_CONFIG_INFO_T open_cfg;
extern uint32_t linkStatus;
extern void Osal_enterSingleCoreCriticalSection(Uint32      port_num);
extern void Osal_exitSingleCoreCriticalSection(Uint32      port_num);

extern void Osal_beginMemAccess(void*   addr, Uint32  size);
extern void Osal_endMemAccess(void*   addr, Uint32  size);
/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
#ifdef _TMS320C6X
/* Memory allocated for the packet buffer. This is 128 bytes aligned. */
uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE];
#pragma DATA_ALIGN(app_pkt_buffer, 64)

/* Memory allocated for the application control block */
#else
uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned (64)));
#endif

APP_EMAC_MCB_T   app_mcb;

static uint32_t pkt_rcv_count = 0;
static uint32_t pkt_received = 0;


/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/
#define PKT_SEND_COUNT  100

/* DO NOT CHANGE test_pkt UNLESS TEST_PKT_SIZE IS UPDATED */
#define TEST_PKT_SIZE       64

static const uint8_t test_pkt[64] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04,
    0x00,0x01,0x01, 0xbb,
    0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0xfe,0xfe, 0x00, 0x00
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
EMAC_PKT_DESC_T*
app_queue_pop
(
    Uint32              port_num,
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
void
app_queue_push
(
    Uint32              port_num,
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


uint32_t allocFailed = 0;
#ifndef EMAC_TEST_ALLOC_FAIL
/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to allocate a packet descriptor.
 *
 *  @retval
 *      pointer to the allocated packet descriptor.
 */
 EMAC_PKT_DESC_T*
app_alloc_pkt
(
    Uint32              port_num,
    Uint32              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;
    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
        p_pkt_desc->AppPrivate  = (Uint32)p_pkt_desc;
        p_pkt_desc->BufferLen   = APP_EMAC_MAX_PKT_SIZE;
        p_pkt_desc->DataOffset  = 0;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->pNext = NULL;
    }
    else
    {
        UART_printf ("app_alloc_pkt on port %d failed, packet size %d is too big\n", port_num, pkt_size);
        return NULL;
    }
    return p_pkt_desc;
}
#else
/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to allocate a packet descriptor.
 *
 *  @retval
 *      pointer to the allocated packet descriptor.
 */
 EMAC_PKT_DESC_T*
app_alloc_pkt
(
    Uint32              port_num,
    Uint32              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;
    static uint32_t allocFailCount = 0;
    static uint32_t entryCount = 0;

    /* testing pkt allocation failure for idkAM437x */
    if (entryCount++ > 64)
    {
        if ((++allocFailCount % 50) == 0 )
        {
            allocFailed++;
            return NULL;
        }
    }

    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
        p_pkt_desc->AppPrivate  = (Uint32)p_pkt_desc;
        p_pkt_desc->BufferLen   = APP_EMAC_MAX_PKT_SIZE;
        p_pkt_desc->DataOffset  = 0;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->pNext = NULL;
    }
    else
    {
        UART_printf ("app_alloc_pkt on port %d failed, packet size %d is too big\n", port_num, pkt_size);
        return NULL;
    }
    return p_pkt_desc;
}
#endif
/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to free a packet descriptor.
 *
 *  @retval
 *      None.
 */
void
app_free_pkt
(
    Uint32              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    /* Free a packet descriptor to the free queue */
    app_queue_push(port_num, &app_mcb.emac_pcb[port_num].freeQueue,
                   (EMAC_PKT_DESC_T *)p_pkt_desc->AppPrivate);
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
    Uint32              i, j;
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
    pktbuf_ptr = (Uint8 *) ((Uint32) app_pkt_buffer);

    /* Initialize the free packet queue */
    for (i=0; i<MAX_NUM_EMAC_PORTS; i++)
    {

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
void app_test_rx_pkt_cb(Uint32               port_num, EMAC_PKT_DESC_T*     p_desc)
{
    EMAC_STATISTICS_T stats;
    pkt_rcv_count++;
    if (memcmp(p_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE) == 0)
    {
        if (pkt_rcv_count <=PKT_SEND_COUNT)
         UART_printf("received packet: %d\n", pkt_rcv_count);

        if ((pkt_rcv_count + allocFailed) ==  PKT_SEND_COUNT)
        {
#ifdef EMAC_TEST_ALLOC_FAIL
            UART_printf("Test case to validate burst packet RX at host which could could result in buffer allocation failure\n");
            UART_printf("Expected alloc failed to be >0 in logs\n");
#endif
            UART_printf("packet received; %d, alloc failed: %d\n", pkt_rcv_count, allocFailed);
            UART_printStatus("All tests have passed\n");
            memset(&stats, 0, sizeof(EMAC_STATISTICS_T));
            emac_get_statistics(0,&stats);
            UART_printf("stats: rx: 0x%d, tx: 0x%d, RxOctets: %d\n", stats.RxGoodFrames, stats.TxGoodFrames, stats.RxOctets);
            emac_close(0);
        }
    }
    else
    {
        if ((pkt_rcv_count  + allocFailed) <=PKT_SEND_COUNT)
            UART_printStatus("packet match failed\n");
    }
    if (p_desc->AppPrivate != NULL)
        app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
    pkt_received = 1;
}

void app_test_task_poll_pkt (UArg arg0, UArg arg1)
{
    while(linkStatus == 0)
    {
        Task_sleep(100);
    }
    while(1)
    {
        emac_poll_pkt(0);
         Task_sleep(10);
    }

}

#if defined (SOC_AM571x)  || defined (SOC_DRA72x)| defined (SOC_DRA75x) || defined (SOC_DRA78x)

void app_test_task_send_pkts(UArg arg0, UArg arg1)
{
    uint32_t i;
    uint32_t port_num = 0;
    int32_t fail_count = 0;
    EMAC_PKT_DESC_T *p_pkt_desc;
    EMAC_DRV_ERR_E ret;

    while(linkStatus == 0)
    {
        Task_sleep(1000);
    }
    for (i = 0; i < PKT_SEND_COUNT/2; i++)
    {
        p_pkt_desc = app_alloc_pkt(0, TEST_PKT_SIZE);
        memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE);
        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
        p_pkt_desc->ValidLen     = TEST_PKT_SIZE;
        p_pkt_desc->DataOffset   = 0;

        p_pkt_desc->PktLength    = TEST_PKT_SIZE;
        p_pkt_desc->PktFrags     = 1;
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->PktChannel     = 0;
        p_pkt_desc->PktLength      = TEST_PKT_SIZE;

        UART_printf("sending packet: %d\n", i+1);
        emac_send(port_num, p_pkt_desc);

        while(pkt_received == 0)
        {
           Task_sleep(100);
            fail_count++;
            if(fail_count == 5)
            {
                fail_count = 0;
                break;
            }
        }
       
        pkt_received = 0;
    }

      if ((ret = emac_close(0)) == EMAC_DRV_RESULT_OPEN_PORT_ERR)
     {
         UART_printf("main: emac_close failure: %d\n", ret);
     }
     else
         UART_printf("main: emac_close sucess\n");

     if ((ret = emac_open(0, &open_cfg)) == EMAC_DRV_RESULT_OPEN_PORT_ERR)
    {
        UART_printf("main: emac_open failure: %d\n", ret);
    }
    else
        UART_printf("main: emac_open1 sucess\n");

   Task_sleep(50);


    while(linkStatus == 0)
    {
        Task_sleep(100);
    }

    for (i = 0; i < PKT_SEND_COUNT/2; i++)
    {
        p_pkt_desc = app_alloc_pkt(0, TEST_PKT_SIZE);
        memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE);
        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
        p_pkt_desc->ValidLen     = TEST_PKT_SIZE;
        p_pkt_desc->DataOffset   = 0;

        p_pkt_desc->PktLength    = TEST_PKT_SIZE;
        p_pkt_desc->PktFrags     = 1;
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->PktChannel     = 0;
        p_pkt_desc->PktLength      = TEST_PKT_SIZE;

        UART_printf("sending packet: %d\n", i+1);
        emac_send(port_num, p_pkt_desc);
                while(pkt_received == 0)
                {
                    Task_sleep(100);
                     fail_count++;
                     if(fail_count == 5)
                     {
                         fail_count = 0;
                         break;
                     }
                
                }
         
        pkt_received = 0;
    }
}
#else
void app_test_task_send_pkts(UArg arg0, UArg arg1)
{
    uint32_t i;
    uint32_t port_num = 0;
    static uint32_t pkt_send_count =0;
    uint32_t fail_count = 0;
    EMAC_PKT_DESC_T *p_pkt_desc;
    while(linkStatus == 0)
    {
        Task_sleep(1000);
    }
    Task_sleep(1000);
    for (i = 0; i < PKT_SEND_COUNT; i++)
    {
        p_pkt_desc = app_alloc_pkt(0, TEST_PKT_SIZE);
        /* app_alloc_pkt can return NULL because of logic added test allocation failure when app_alloc_pkt is called from the driver to replenish
           packet descriptor during packet receive, just alloc again and it will pass */
        if (p_pkt_desc == NULL)
        {
            p_pkt_desc = app_alloc_pkt(0, TEST_PKT_SIZE);
        }
        memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE);
        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
        p_pkt_desc->ValidLen     = TEST_PKT_SIZE;
        p_pkt_desc->DataOffset   = 0;

        p_pkt_desc->PktLength    = TEST_PKT_SIZE;
        p_pkt_desc->PktFrags     = 1;
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->PktChannel     = 0;
        p_pkt_desc->PktLength      = TEST_PKT_SIZE;

        
        emac_send(port_num, p_pkt_desc);

        fail_count = 0;
        while(pkt_received == 0)
        {
            Task_sleep(100);
             fail_count++;
             if(fail_count == 5)
             {
                 fail_count = 0;
                 break;
             }
        }
        pkt_received = 0;
        pkt_send_count++;
    }

}
#endif

/*
 *  ======== Delay function ========
 */
void app_delay(int32_t delayValue)
{
    volatile int32_t delay = delayValue*100;
    while (delay--);
}

void app_output_log(Char* str, UInt numChar)
{
    if (numChar > 0)
    {
        UART_printf(str);
    }
}

