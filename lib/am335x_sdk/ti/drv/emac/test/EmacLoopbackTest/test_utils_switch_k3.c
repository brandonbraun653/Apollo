/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     test_utils_switch_k3.c
 *
 *  \brief    This file contains common utility functions used by the emac loopback unit 
 *             test applications for switch use case.
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/csl/csl_chip.h>
#include <ti/csl/cslr_icss.h>
/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/emac_ioctl.h>

#include <ti/drv/emac/src/emac_osal.h>
#include <ti/drv/emac/firmware/icss_switch/config/emac_fw_config_switch.h>

/* SOC Include Files. */
#include <ti/drv/emac/soc/emac_soc_v5.h>

/* Test application local header file */
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

/* PRUSS Driver Header File. */
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/csl/arch/csl_arch.h>

#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif

/* Switch FW headers */
#include <ti/drv/emac/firmware/icss_switch/bin/RTU0_SLICE0_bin.h>      /* PDSP1code */
#include <ti/drv/emac/firmware/icss_switch/bin/RTU1_SLICE0_bin.h>      /* PDSP2code */
#include <ti/drv/emac/firmware/icss_switch/bin/RX_PRU_SLICE0_bin.h>    /* PDSP3code */
#include <ti/drv/emac/firmware/icss_switch/bin/TX_PRU_SLICE0_bin.h>    /* PDSP4code */
#include <ti/drv/emac/firmware/icss_switch/bin/RTU0_SLICE1_bin.h>      /* PDSP1code */
#include <ti/drv/emac/firmware/icss_switch/bin/RTU1_SLICE1_bin.h>      /* PDSP2code */
#include <ti/drv/emac/firmware/icss_switch/bin/RX_PRU_SLICE1_bin.h>    /* PDSP3code */
#include <ti/drv/emac/firmware/icss_switch/bin/TX_PRU_SLICE1_bin.h>    /* PDSP4code */

extern uint32_t portNum;
extern uint32_t endPort;
extern int port_en[];

/**********************************************************************
 ************************** Macros **************************
 **********************************************************************/
    /* Macro for test success status return value. */
#define APP_TEST_SUCCESS    0
    /* Macro for test failure status return value. */
#define APP_TEST_FAILURE    -1

/* Ring parameters*/
/*brief Number of ring entries - we can prime this much memcpy operations */
#define EMAC_TEST_APP_RING_ENTRIES      (128)
/* Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define EMAC_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/* Total ring memory */
#define EMAC_TEST_APP_RING_MEM_SIZE     (EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_RING_ENTRY_SIZE)

/* UDMA host mode buffer descriptor memory size.    *  Make it multiple of 128 byte alignment */
#define EMAC_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (128U - sizeof(CSL_UdmapCppi5HMPD)))

#define EMAC_TEST_MAX_CHANS_PER_PORT 4
#define EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT 9

/* UDMA host mode buffer descriptor memory size.    *  Make it multiple of 128 byte alignment */
#define EMAC_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (128U - sizeof(CSL_UdmapCppi5HMPD)))

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
static uint32_t gTestFailCount          = 0;
static uint32_t gTestSendFailCount      = 0;
static uint32_t gInterposerCardPresent  = 0;
static uint8_t  gAppTestSequenceNumber  = 1;
static uint32_t gPollModeEnabled        = 0;
static uint32_t gInitComplete           = 0;
static uint32_t gAppTestId              = 0;
static uint32_t gPktReceived            = 0;
static uint32_t gPktRcvCount            = 0;
static uint32_t gAppAllocFailure        = 0;
static uint32_t gAllocPktCount          = 0;
static uint32_t gAppTestSendFailure     = 0;
static uint32_t gAppTestAllocFailure    = 0;

#ifndef EMAC_BENCHMARK
static uint32_t gAppTesTClonePkt        = 0;
static uint32_t gAppTestCloneCount      = 2;
#endif

static volatile uint32_t gTimestampReceived = 1;
static EMAC_STATISTICS_ICSSG_T gIcssHwStats;

static SemaphoreP_Handle gAppTestIoctlWaitAckSem;

uint8_t gIcssTxPortQueueMem[2][EMAC_TOTAL_PORT_QUEUE_SIZE] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_msmc_mem")));
PRUICSS_Handle gPrussHandle[EMAC_MAX_ICSS] = {NULL, NULL, NULL};
uint8_t gAppPktBuffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned(64))) __attribute__ ((section (".bss:emac_ddr_mem")));

/* UDMA driver object and handle */
struct Udma_DrvObj      gUdmaDrvObj;
Udma_DrvHandle          gDrvHandle = NULL;

/* UDMA Memories for Tx Channels */
struct Udma_ChObj gUdmaTxChanObjMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT];
static uint8_t gTxChanFreeRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gTxChanCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gUdmapTxChanDescRamMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                    __attribute__ ((section (".bss:emac_ddr_mem")));

/* UDMA Memories for RX Packet Channels */
struct Udma_ChObj       gUdmaRxPktChanObjMem[EMAC_MAX_PORTS];
struct Udma_FlowObj gUdmaRxPktChanFlowHndMem[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxPktChanFreeRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                            __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxPktChanCompRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                            __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_EventObj    gUdmaRxPktChanEventHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT];
static uint8_t gRxPktChanFreeRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxPktChanCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));

static uint8_t gUdmapRxPktChanDescRamMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));

/* UDMA Memories for RX Management Channels */

struct Udma_ChObj       gUdmaRxMgmtChanObjMem[EMAC_MAX_PORTS];
struct Udma_FlowObj gUdmaRxMgmtChanFlowHndMem[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxMgmtChanFreeRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxMgmtChanCompRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_EventObj    gUdmaRxMgmtChanEventHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT];

static uint8_t gRxMgmtChanFreeRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxMgmtChanCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                         __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gUdmapRxMgmtChanDescRamMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

/*
 * UDMA Memories for 2nd RX Management Channels
 */
struct Udma_ChObj       gUdmaRxMgmtChan2ObjMem[EMAC_MAX_PORTS];
struct Udma_FlowObj gUdmaRxMgmtChan2FlowHndMem[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxMgmtChan2FreeRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxMgmtChan2CompRingHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_EventObj    gUdmaRxMgmtChan2EventHndMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT];

static uint8_t gRxMgmtChan2FreeRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxMgmtChan2CompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                         __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gUdmapRxMgmtChan2DescRamMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));
EMAC_CHAN_MAC_ADDR_T chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));
EMAC_HwAttrs_V5 app_emac_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));
APP_EMAC_MCB_SWITCH_T app_mcb __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));
EMAC_OPEN_CONFIG_INFO_T app_open_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

/* Test will use switch firmware to verify packet transmission
 * and reception between 2 physical ICSSG ports, each ICSSG port needs to be connected 
 * to another ICSSG port via ethernet cable.
 */
/* EMAC firmware header files */
typedef struct
{
    const uint32_t *pru;
    uint32_t pruSize;
    const uint32_t *rtu;
    uint32_t rtuSize;
} APP_TEST_PRU_RTU_FW_T;

static APP_TEST_PRU_RTU_FW_T gIcssgSwtchFw[2][2] = {
    {   
        { RX_PRU_SLICE0_b00, sizeof(RX_PRU_SLICE0_b00), RTU0_SLICE0_b00, sizeof(RTU0_SLICE0_b00) },
        { TX_PRU_SLICE0_b00, sizeof(TX_PRU_SLICE0_b00), RTU1_SLICE0_b00, sizeof(RTU1_SLICE0_b00) }
    },
    {
        { RX_PRU_SLICE1_b00, sizeof(RX_PRU_SLICE1_b00), RTU0_SLICE1_b00, sizeof(RTU0_SLICE1_b00) },
        { TX_PRU_SLICE1_b00, sizeof(TX_PRU_SLICE1_b00), RTU1_SLICE1_b00, sizeof(RTU1_SLICE1_b00) }
    }
};

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/
/* DO NOT CHANGE app_test_loopback_pkt_vlan UNLESS APP_TEST_PKT_SIZE IS UPDATED */
#define APP_TEST_PKT_SIZE       64
uint8_t lclMac[EMAC_MAC_ADDR_LENTH] = {0x48, 0x93, 0xfe, 0xda, 0x16, 0x4a};

#ifdef EMAC_BENCHMARK
#define APP_TEST_MAX_PKT_SEND_SIZE 1500
#define APP_TEST_PKT_SEND_COUNT  500000

static uint8_t app_test_loopback_pkt_vlan[APP_TEST_MAX_PKT_SEND_SIZE] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // dest
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a, // src
    0x81, 0x00, 0x00,0x64,                      /* priority 0, 02 is vlanId */
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
#else
#define APP_TEST_PKT_SEND_COUNT  16
static uint8_t app_test_loopback_pkt_vlan[APP_TEST_PKT_SIZE+4] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // dest
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a, // src
    0x81, 0x00, 0x00,0x64,                      /* priority 0, 02 is vlanId */
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
#endif
static uint8_t *pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);

int32_t app_test_task_init_pruicss(uint32_t portNum);
int32_t app_test_task_disable_pruicss(uint32_t portNum);
int32_t app_test_setup_default_settings();
int32_t app_test_send_receive(uint32_t startP, uint32_t endP, uint32_t displayResult);
EMAC_DRV_ERR_E app_test_flood_ctrl(void);




/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/

#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}
#endif

/*
 *  ======== app_test_wait_mgmt_resp ========
 */
int32_t app_test_wait_mgmt_resp(uint32_t waitTimeMilliSec)
{
    int32_t retVal = APP_TEST_SUCCESS;

    retVal = EMAC_osalPendLock(gAppTestIoctlWaitAckSem, waitTimeMilliSec);

    if(SemaphoreP_TIMEOUT == retVal)
    {
        UART_printf("ERROR: IOCTL management response not received for %u ms, Semaphore_pend timed out! RC: %d\n\r",
                    waitTimeMilliSec, retVal);
        return APP_TEST_FAILURE;
    }
    return retVal;
}

/*
 *  ======== app_detect_interposer_card ========
 */
bool app_detect_interposer_card(void)
{
    EMAC_socGetInitCfg(0, &app_emac_cfg);
    CSL_MdioRegs *pBaseAddr = (CSL_MdioRegs*) (uintptr_t)(app_emac_cfg.portCfg[2].mdioRegsBaseAddr);
    if ((CSL_MDIO_isPhyAlive(pBaseAddr,app_emac_cfg.portCfg[2].phyAddr)) ||(CSL_MDIO_isPhyAlive(pBaseAddr,app_emac_cfg.portCfg[3].phyAddr)))
    {
        UART_printf("PHYs for ICSSG1 are ALIVE, interposer card is NOT present\n");
        return FALSE;
    }
    else
    {
        UART_printf("PHYs for ICSSG1 are not ALIVE, interposer card is present\n");
        return TRUE;
    }
}

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
    uint32_t              port_num,
    APP_PKT_QUEUE_T*    pq
)
{
    port_num = port_num;
    EMAC_PKT_DESC_T*    pPktHdr;
#ifndef EMAC_BENCHMARK
    uintptr_t key;
#endif
    if (!pq->Count)
    {
        return 0;
    }
#ifndef EMAC_BENCHMARK
    key = EMAC_osalHardwareIntDisable();
#endif

    pPktHdr = pq->pHead;
    if( pPktHdr )
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }
#ifndef EMAC_BENCHMARK
    EMAC_osalHardwareIntRestore(key);
#endif

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
    uint32_t              port_num,
    APP_PKT_QUEUE_T*    pq,
    EMAC_PKT_DESC_T*    pPktHdr
)
{
    port_num = port_num;
#ifndef EMAC_BENCHMARK
    uintptr_t key;
    key = EMAC_osalHardwareIntDisable();
#endif
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
#ifndef EMAC_BENCHMARK
    EMAC_osalHardwareIntRestore(key);
#endif
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
 EMAC_PKT_DESC_T*
app_alloc_pkt
(
    uint32_t              port_num,
    uint32_t              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;

    if (pkt_size <= APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.freeQueue);
        if(p_pkt_desc)
        {
            p_pkt_desc->AppPrivate  = (uintptr_t)p_pkt_desc;
            p_pkt_desc->BufferLen   = APP_EMAC_MAX_PKT_SIZE;
            p_pkt_desc->DataOffset  = 0;
            p_pkt_desc->pPrev = NULL;
            p_pkt_desc->pNext = NULL;
        }
        else
            gAppAllocFailure++;
    }
    else
    {
        UART_printf ("app_alloc_pkt on port %d failed, packet size %d is too big\n", port_num, pkt_size);
        return NULL;
    }
    gAllocPktCount++;
    return p_pkt_desc;
}
uint32_t gFreePktCount = 0;

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
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    gFreePktCount++;
    /* Free a packet descriptor to the free queue */
    app_queue_push(port_num, &app_mcb.freeQueue,
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
    uint32_t            j;
    EMAC_PKT_DESC_T*    p_pkt_desc;
    uint8_t*            pktbuf_ptr;

    UART_printf ("EMAC loopback test application initialization, size of gAppPktBuffer: 0x%x\n", sizeof(gAppPktBuffer));

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (APP_EMAC_MCB_SWITCH_T));

    pktbuf_ptr = (uint8_t *) ((uintptr_t) gAppPktBuffer);
    
    for (j=0; j<APP_MAX_PKTS; j++)
        {
            p_pkt_desc               = &app_mcb.pkt_desc[j];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = APP_EMAC_MAX_PKT_SIZE;
            app_queue_push(EMAC_SWITCH_PORT, &app_mcb.freeQueue, p_pkt_desc );
            pktbuf_ptr += APP_EMAC_MAX_PKT_SIZE;
        }
}

#define APP_TEST_FDB_ENTRY 0x87
EMAC_IOCTL_FDB_ENTRY app_test_mac_fdb_entries[] =
{
     //Default multicast FDB entrie for testing
    { { 0x01, 0x0E, 0xCF, 0x00, 0x00, 0x00 }, 2, {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x00, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x01, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x01, 0x02 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x04, 0x00 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x04, 0x20 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x04, 0x40 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x00, 0x04, 0x80 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x80, 0xC2, 0x00, 0x00, 0x00 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x80, 0xC2, 0x00, 0x00, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x01, 0x00, 0x00 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x02, 0x00, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x03, 0x01, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x04, 0x01, 0x02 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x05, 0x04, 0x00 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x06, 0x04, 0x20 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x07, 0x04, 0x40 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x0E, 0xCF, 0x08, 0x04, 0x80 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x80, 0xC2, 0x09, 0x00, 0x00 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },
    { { 0x01, 0x80, 0xC2, 0x0a, 0x00, 0x01 }, 2,  {APP_TEST_FDB_ENTRY, APP_TEST_FDB_ENTRY} },

};
void app_test_fdb_ioctl (void)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_IOCTL_PARAMS params = {0};
    EMAC_IOCTL_FDB_ENTRY fdbEntry = {0};
    uint8_t fdbEntries = sizeof(app_test_mac_fdb_entries) / sizeof(EMAC_IOCTL_FDB_ENTRY);
    uint8_t i;

    fdbEntries = fdbEntries;
    UART_printf("app_test_fdb_ioctl IOCTL: BEGIN\n");
    /* Clear the FDB table */
    params.subCommand = EMAC_IOCTL_FDB_ENTRY_DELETE_ALL;
    params.ioctlVal = NULL;
    params.seqNumber = gAppTestSequenceNumber++;
    retVal = emac_ioctl(EMAC_SWITCH_PORT, EMAC_IOCTL_FDB_ENTRY_CTRL, &params);
    if(retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
       UART_printf("app_test_fdb_ioctl:failed with code %d\n", retVal);
       while (1);
    }
    else
    {
        app_test_wait_mgmt_resp(1000);
    }

    /* Verify delete all ageable IOCTL  */
    params.subCommand = EMAC_IOCTL_FDB_ENTRY_DELETE_ALL_AGEABLE;
    params.ioctlVal = NULL;
    params.seqNumber = gAppTestSequenceNumber++;
    retVal = emac_ioctl(EMAC_SWITCH_PORT, EMAC_IOCTL_FDB_ENTRY_CTRL, &params);
    if(retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
       UART_printf("app_test_fdb_ioctl:failed with code %d\n", retVal);
       while (1);
    }
    else
    {
        app_test_wait_mgmt_resp(1000);
    }

    /* Add entry */
    for(i = 0; i < 2; i++)
    {
        params.subCommand = EMAC_IOCTL_FDB_ENTRY_ADD;
        params.seqNumber = gAppTestSequenceNumber++;
        memcpy(&fdbEntry, &app_test_mac_fdb_entries[i], sizeof(EMAC_IOCTL_FDB_ENTRY));
        params.ioctlVal = (void*)&fdbEntry;
        retVal = emac_ioctl(EMAC_SWITCH_PORT, EMAC_IOCTL_FDB_ENTRY_CTRL, &params);
        if(retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            UART_printf("app_test_fdb_ioctl:failed with code %d\n", retVal);
            while (1);
        }
        else
        {
            if (app_test_wait_mgmt_resp(1000) != 0)
            {
                while (1);
            }
        }
        Task_sleep(5000);

        /* Delete entry */
        params.subCommand = EMAC_IOCTL_FDB_ENTRY_DELETE;
        params.seqNumber = gAppTestSequenceNumber++;
        params.ioctlVal = (void*)&fdbEntry;
        retVal = emac_ioctl(EMAC_SWITCH_PORT, EMAC_IOCTL_FDB_ENTRY_CTRL, &params);
        if(retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            UART_printf("app_test_fdb_ioctl:failed with code %d\n", retVal);
            while (1);
        }
        else
        {
            if (app_test_wait_mgmt_resp(1000) != 0)
            {
                while (1);
            }
        }
        Task_sleep(500);
    }
    UART_printf("app_test_fdb_ioctl IOCTL: END\n");
}

/**
 *  @brief  send IOCTL command set table entry
 */
int32_t app_test_vlan_ctrl_set_tbl_entry(uint32_t portNum, uint8_t fid, uint16_t vlanId, EMAC_IOCTL_VLAN_FID_PARAMS *pVlanParams)
{
    int32_t retVal = retVal = APP_TEST_SUCCESS;
    EMAC_IOCTL_PARAMS params;
    EMAC_IOCTL_VLAN_FID_ENTRY vlanEntry = {0};
    /* send packet only to the host */

    params.subCommand = EMAC_IOCTL_VLAN_SET_ENTRY;
    params.ioctlVal = (void*)&vlanEntry;
    memcpy(&vlanEntry.vlanFidPrams, pVlanParams, sizeof(EMAC_IOCTL_VLAN_FID_PARAMS));
    vlanEntry.vlanId = vlanId;
    retVal = emac_ioctl(portNum,EMAC_IOCTL_VLAN_CTRL,&params);
    if (retVal != EMAC_DRV_RESULT_OK)
    {
        retVal = APP_TEST_FAILURE;
    }
    return retVal;
}

/******************************************************************************
 * Function: EMAC test loopback packet
 ******************************************************************************/
/**
 *  @brief  This function is used to loopback the pkt received to sender
 */
void app_test_loopback_pkt(uint32_t portNum, EMAC_PKT_DESC_T* pDesc)
{
    EMAC_DRV_ERR_E sentRetVal;
    uint8_t* temp;
    EMAC_PKT_DESC_T *p_pkt_desc = app_alloc_pkt(portNum, APP_EMAC_MAX_PKT_SIZE);
    if (p_pkt_desc == NULL)
    {
        UART_printf("app_test_loopback_pkt: app alloc pkt failed\n");
        gAppTestAllocFailure++;
    }
    else
    {
        temp = p_pkt_desc->pDataBuffer; // temp is now buffer

        p_pkt_desc->pDataBuffer = pDesc->pDataBuffer;
        pDesc->pDataBuffer = temp;

        p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;
        p_pkt_desc->ValidLen     = pDesc->PktLength-4;
        p_pkt_desc->DataOffset   = 0;
        p_pkt_desc->PktLength    = pDesc->PktLength-4;
        p_pkt_desc->PktFrags     = 1;
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->PktChannel     = 0;
        p_pkt_desc->PktLength      = pDesc->PktLength-4;
        sentRetVal = emac_send(portNum, p_pkt_desc);
        if(sentRetVal != EMAC_DRV_RESULT_OK)
        {
            gAppTestSendFailure++;
            app_free_pkt(portNum,p_pkt_desc);
        }
    }
}

/**
 *  @brief  This function is used to call back the network application when a
 *          packet is received.
 */
void app_test_rx_pkt_cb(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
#ifndef EMAC_BENCHMARK
    if (p_desc->AppPrivate)
    {
        if (memcmp(p_desc->pDataBuffer, pTestPkt, APP_TEST_PKT_SIZE) == 0)
        {
            UART_printf("app_test_rx_pkt_cb: port %d: ring num: %d, received packet %d, packet length: %d, rx timestamp:  0x%x%08x\n",
                     port_num,
                     p_desc->PktChannel,
                     gPktRcvCount,
                     p_desc->PktLength,
                     (unsigned int)(p_desc->RxTimeStamp >> 32),
                     (unsigned int)(p_desc->RxTimeStamp & 0xFFFFFFFF));
        }
        else
        {
            UART_printf("app_test_rx_pkt_cb: port %u: packet match failed, packet length: %d\n", port_num, p_desc->PktLength);
        }
        app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
        if (gAppTesTClonePkt == 1)
        {
            if (--gAppTestCloneCount == 0)
            {
                gPktReceived = 1;
                gAppTestCloneCount = 2;
            }
        }
        else
        {
            gPktReceived = 1;
        }
    }
    gPktRcvCount++;
#else
    if (p_desc->AppPrivate != 0U)
    {
        if (port_num != 6)
            app_test_loopback_pkt(EMAC_SWITCH_PORT1,p_desc);

        app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
        gPktReceived = gPktReceived;
    }
    gPktRcvCount++;
#endif
}

/**
*  @brief  This function is used to call back the network application when a
*          config response packet is receive from ICSSG firmware.
*/
void app_test_rx_mgmt_response_cb(uint32_t port_num, EMAC_IOCTL_CMD_RESP_T* pCmdResp)
{
    if (pCmdResp != NULL)
    {
        if (pCmdResp->seqNumber == (gAppTestSequenceNumber -1))
        {
            UART_printf("app_test_rx_mgmt_response_cb: port: %d, status: 0x%x, sequence number: 0x%x\n",
                        port_num, pCmdResp->status, pCmdResp->seqNumber);
            if (pCmdResp->respParamsLength)
            {
                UART_printf("app_test_rx_mgmt_response_cb: port: %d, 0x%x, 0x%x, 0x%x\n",
                port_num, pCmdResp->respParams[0],pCmdResp->respParams[1],pCmdResp->respParams[2]);
            }
            EMAC_osalPostLock(gAppTestIoctlWaitAckSem);
        }
        else
        {
            UART_printf("app_test_rx_mgmt_response_cb (incorrect sequence number): port: %d, status: 0x%x, sequence number: 0x%x\n",
                        port_num, pCmdResp->status, pCmdResp->seqNumber);
            if (pCmdResp->respParamsLength)
            {
                UART_printf("app_test_rx_mgmt_response_cb: port: %d, resp length: 0x%x, 0x%x, 0x%x, 0x%x\n",
                port_num,
                pCmdResp->respParamsLength,
                pCmdResp->respParams[0],
                pCmdResp->respParams[1],
                pCmdResp->respParams[2]);
            }
            EMAC_osalPostLock(gAppTestIoctlWaitAckSem);
        }
    }
}

/**
*  @brief  This function is used to call back the network application when a
*          timestamp response packet is receive from ICSSG firmware.
*/
void app_test_ts_response_cb(uint32_t port_num, uint32_t ts_id, uint64_t ts, bool is_valid)
{
    UART_printf("app_test_ts_response_cb: port %d: tx timestamp id: 0x%x, tx timestamp: 0x%x%08x is_valid: %d\n",
                            port_num,
                            ts_id,
                            (unsigned int)(ts >> 32),
                            (unsigned int)(ts& 0xFFFFFFFF),
                            is_valid);
    gTimestampReceived = 1;

}
void app_test_trace_cb(uint8_t traceLevel, const char* traceString, ...)
{
    if (traceLevel <= UTIL_TRACE_LEVEL_ERR)
    {
        System_flush();
        VaList arg_ptr;
        /* print the format string */
        va_start(arg_ptr, traceString);
        System_vprintf(traceString, arg_ptr);
        va_end(arg_ptr);
        /* append newline */
        System_printf("\n");
        System_flush();
    }
}
void app_test_task_poll_pkt (UArg arg0, UArg arg1)
{
    uint32_t port = (uint32_t) arg0;
    while(gInitComplete == 0)
    {
        Task_sleep(1);
    }
    UART_printf("polling rx packets on port: %d\n", port);
    while(1)
    {
        if (gPollModeEnabled == 0)
        {
            emac_poll_pkt(port);
            Task_sleep(5);
            if (gPktRcvCount == APP_TEST_PKT_SEND_COUNT)
                break;
        }
        else
        {
            break;
        }
    }
}

void app_test_task_poll_ctrl (UArg arg0, UArg arg1)
{
    uint32_t port = (uint32_t) arg0;
#ifndef EMAC_BENCHMARK
    uint32_t mgmtRings =EMAC_POLL_RX_MGMT_RING_ALL;
    uint32_t pktRings = EMAC_POLL_RX_PKT_RING_ALL;
    uint32_t txRings = EMAC_POLL_TX_COMPLETION_RING_ALL;
#else
    uint32_t mgmtRings =EMAC_POLL_RX_MGMT_RING_ALL;
    uint32_t pktRings = EMAC_POLL_RX_PKT_RING1 | EMAC_POLL_RX_PKT_RING2;
    uint32_t txRings = EMAC_POLL_TX_COMPLETION_RING1;
#endif
    while(gInitComplete == 0)
    {
        Task_sleep(1);
    }

    UART_printf("polling all pkts on port: %d\n", port);
    while(1)
    {
        if (gPollModeEnabled == 1)
        {
            emac_poll_ctrl(port, pktRings,mgmtRings,txRings);
        }
        else if (gPollModeEnabled == 2)
        {
            emac_poll_ctrl(port, pktRings,mgmtRings,0);
        }
        else
            emac_poll_ctrl(port, 0,0,txRings);
        Task_sleep(2);
    }
}

int32_t app_test_send(uint32_t port_num, uint8_t* pPkt, uint32_t pktChannel, uint32_t pktSize, uint8_t txTsReq)
{
    uint32_t i;
    EMAC_DRV_ERR_E sentRetVal;

    for (i = 0; i < APP_TEST_PKT_SEND_COUNT; i++)
    {
        uint32_t fail_count = 0;
        fail_count = fail_count;
        EMAC_PKT_DESC_T *p_pkt_desc = app_alloc_pkt(port_num, pktSize);
        if (p_pkt_desc == NULL)
        {
            UART_printf("app_test_send: app alloc pkt failed\n");
            Task_sleep(50);
        }
        else
        {
            memcpy (p_pkt_desc->pDataBuffer, pPkt, pktSize);
            p_pkt_desc->AppPrivate = (uint32_t)p_pkt_desc;

            if (txTsReq)
            {
                /* To test TX timestamp, enable the follwing 3 lines */
                p_pkt_desc->Flags = EMAC_PKT_FLAG_TX_TS_REQ;
                p_pkt_desc->TxtimestampId = port_num + i;
                gTimestampReceived = 0;
            }
            else
            {
                p_pkt_desc->Flags = 0;
            }
#ifndef EMAC_BENCHMARK
            p_pkt_desc->TxPktTc      = i % 8;
            p_pkt_desc->PktChannel   = i % 4;
#else
            p_pkt_desc->TxPktTc      = 0;
            p_pkt_desc->PktChannel   = 0;
#endif
            p_pkt_desc->ValidLen     = pktSize;
            p_pkt_desc->DataOffset   = 0;
            p_pkt_desc->PktLength    = pktSize;
            p_pkt_desc->PktFrags     = 1;
            p_pkt_desc->pNext = NULL;
            p_pkt_desc->pPrev = NULL;
            p_pkt_desc->PktLength      = pktSize;
            gPktReceived = 0;
            /* intermix sending mgmt packets with actual packets for every 5th packet */
            if ((i % 5) == 0)
            {
                app_test_flood_ctrl();
            }
            sentRetVal = emac_send(port_num, p_pkt_desc);
            if(sentRetVal != EMAC_DRV_RESULT_OK)
            {
                UART_printf("app_test_send: emac send on port failed with status: : %d: retVal %d, pkt_count: %d\n", port_num, sentRetVal, i+1);
                app_free_pkt(port_num,p_pkt_desc);
                gTestSendFailCount++;
                Task_sleep(50);
            }
#ifndef EMAC_BENCHMARK
            {
                while((gPktReceived == 0) || (gTimestampReceived == 0))
                {
                    fail_count++;
                    Task_sleep(100);
                    if (fail_count == 5)
                    {
                        gPktReceived = 1;
                    }
                }
            }
#endif
        }
    }
    return 0;
}

void app_test_tx_chans(void)
{
    gAppTestId++;
    uint32_t txChannel;
    UART_printf("EMAC_UT_%d begin test_multiple tx chans mode\n", gAppTestId);
    for (txChannel = 0; txChannel < 4;txChannel++)
    {
        app_test_send(EMAC_SWITCH_PORT1, pTestPkt, txChannel, APP_TEST_PKT_SIZE,0);
    }
    for (txChannel = 0; txChannel < 4;txChannel++)
    {
        app_test_send(EMAC_SWITCH_PORT2, pTestPkt, txChannel, APP_TEST_PKT_SIZE,0);
    }
    UART_printf("EMAC_UT_%d end test_multiple tx chans mode\n", gAppTestId);
}

int32_t app_test_port_prio_map_cfg(uint32_t portNum)
{
    uint8_t i;
    int32_t retVal = 0;
    EMAC_IOCTL_PARAMS params;
    EMAC_IOCTL_PORT_PRIO_MAP testPortPrioMap;

    for (i =0; i< 8; i++)
    {
        testPortPrioMap.portPrioMap[i] = i;
    }
    params.ioctlVal = (void*)&testPortPrioMap;

    retVal = emac_ioctl(portNum,EMAC_IOCTL_PORT_PRIO_MAPPING_CTRL,&params);
    return retVal;
}

int32_t app_test_configure_default_prio_regen_tbl(uint32_t port_num)
{
    uint8_t i;
    int32_t retVal = 0;
    EMAC_IOCTL_PARAMS params;
    EMAC_IOCTL_PRIO_REGEN_MAP testPortPrioRegenTbl;

    for (i =0; i< 8; i++)
    {
        testPortPrioRegenTbl.prioRegenMap[i] = i;
    }
    params.ioctlVal = (void*)&testPortPrioRegenTbl;

    retVal = emac_ioctl(port_num,EMAC_IOCTL_PRIO_REGEN_CTRL,&params);
    return retVal;
}

int32_t app_test_configure_cut_through_or_prempt_select_ctrl(uint32_t port_num)
{
    int32_t queue_num;
    int32_t retVal = 0;
    EMAC_IOCTL_PARAMS params;
    EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP entry;
    uint8_t temp_byte;
    uintptr_t expressPremptiveQueueAddr;

    memset(&entry, 0, sizeof(EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP));

    for (queue_num = 0; queue_num < EMAC_IOCTL_PRIO_MAX; queue_num++)
    {
        entry.pcpPreemptMap[queue_num] = queue_num;
        entry.pcpCutThroughMap[queue_num] = queue_num;
    }

    params.ioctlVal = (void*)&entry;
    retVal = emac_ioctl(port_num,EMAC_IOCTL_CUT_THROUGH_PREEMPT_SELECT,&params);

    /* now just read the value back */
    if (retVal == 0)
    {
        EMAC_socGetInitCfg(0, &app_emac_cfg);
        if (port_num == EMAC_SWITCH_PORT1)
        {
            expressPremptiveQueueAddr = app_emac_cfg.portCfg[0].icssDram0BaseAddr+ EXPRESS_PRE_EMPTIVE_Q_MAP;
        }
        else
        {
            expressPremptiveQueueAddr = app_emac_cfg.portCfg[2].icssDram0BaseAddr+ EXPRESS_PRE_EMPTIVE_Q_MAP;
        }
        for (queue_num = 0; queue_num < EMAC_IOCTL_PRIO_MAX; queue_num++)
        {
            temp_byte = CSL_REG8_RD(expressPremptiveQueueAddr+(queue_num*4));
            temp_byte = (temp_byte &0x70)>> 4;
            UART_printf("app_test_configure_cut_through_or_prempt_select_ctrl: port_num: %d, addr: 0x%x, value: 0x%x\n",
                    port_num, expressPremptiveQueueAddr,
                    temp_byte);
            if (entry.pcpPreemptMap[queue_num] != temp_byte)
                 retVal = -1;
        }
    }

    return retVal;
}
 
void app_test_port_priority(void)
{
    uint8_t pcp;

    UART_printf("app_test_port_priority: BEGIN\n");
    pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);
    for (pcp = 0;pcp < 8; pcp++)
    {
        app_test_loopback_pkt_vlan[14] = pcp << 5;
        app_test_send(EMAC_SWITCH_PORT1, pTestPkt, 0, APP_TEST_PKT_SIZE+4,0);
    }

    for (pcp = 0;pcp < 8; pcp++)
    {
        app_test_loopback_pkt_vlan[14] = pcp << 5;
        app_test_send(EMAC_SWITCH_PORT2, pTestPkt, 0, APP_TEST_PKT_SIZE+4,0);
    }
    UART_printf("app_test_port_priority: END\n");
}

EMAC_DRV_ERR_E app_test_flood_ctrl(void)
{
    EMAC_DRV_ERR_E status;
    EMAC_IOCTL_PARAMS params = {0};
    UART_printf("app_test_flood_ctrl: BEGIN\n");

    /* Issue IOCTL to disable */
    params.seqNumber = gAppTestSequenceNumber++;
    params.subCommand = EMAC_IOCTL_PORT_UC_FLOODING_DISABLE;
    status = emac_ioctl(EMAC_SWITCH_PORT1, EMAC_IOCTL_UC_FLOODING_CTRL, &params);

    if(status != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        UART_printf("UC Flood control IOCTL to disable returned error for = %d\n", EMAC_SWITCH_PORT1);
    }
    else
    {
        app_test_wait_mgmt_resp(10000);
    }

    params.seqNumber = gAppTestSequenceNumber++;
    params.subCommand = EMAC_IOCTL_PORT_UC_FLOODING_ENABLE;
    status = emac_ioctl(EMAC_SWITCH_PORT1, EMAC_IOCTL_UC_FLOODING_CTRL, &params);

    if(status != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        UART_printf("UC Flood control IOCTL to disable returned error for = %d\n", EMAC_SWITCH_PORT1);
    }
    else
    {
        app_test_wait_mgmt_resp(10000);
    }
    UART_printf("app_test_flood_ctrl: END\n");

    return status;
}

void app_test_pkt_clone(void)
{
    UART_printf("app_test_pkt_clone: BEGIN\n");
    pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);
    app_test_send(EMAC_SWITCH_PORT, pTestPkt, 0, APP_TEST_PKT_SIZE+4,0);
    UART_printf("app_test_pkt_clone: END\n");

}

void app_test_local_injection(void)
{
    EMAC_STATISTICS_ICSSG_T stats;
    UART_printf("app_test_local_injection: BEGIN\n");
    pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);

    app_test_send(EMAC_SWITCH_PORT1, pTestPkt, 0, APP_TEST_PKT_SIZE+4,1);
    /* When directing packet out of port1, query for emac lld software port 3 */
    memset(&stats, 0, sizeof(EMAC_STATISTICS_ICSSG_T));
    emac_get_statistics_icssg(3, &stats, false);
    if (stats.TXGoodFrame != APP_TEST_PKT_SEND_COUNT)
    {
        gTestFailCount++;
        UART_printf("fail1\n");
    }

    app_test_send(EMAC_SWITCH_PORT2, pTestPkt, 0, APP_TEST_PKT_SIZE+4,1);
    /* When directing packet out of port2, query for emac lld software port 1 */
    memset(&stats, 0, sizeof(EMAC_STATISTICS_ICSSG_T));
    emac_get_statistics_icssg(1, &stats, false);
    if (stats.TXGoodFrame != APP_TEST_PKT_SEND_COUNT)
    {
        gTestFailCount++;
        UART_printf("fail2\n");
    }

    UART_printf("app_test_local_injection: END\n");
}


void app_test_reopen(void)
{
    UART_printf("app_test_reopen: BEGIN\n");
    pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);

    app_test_send(EMAC_SWITCH_PORT1, pTestPkt, 0, APP_TEST_PKT_SIZE+4,1);
    /* When directing packet out of port1, query for emac lld software port 3 */

    app_test_send(EMAC_SWITCH_PORT2, pTestPkt, 0, APP_TEST_PKT_SIZE+4,1);
    /* When directing packet out of port2, query for emac lld software port 1 */
    UART_printf("app_test_reopen: END\n");
}

void  app_test_send_ioctl_cmd(uint32_t port_num, EMAC_IOCTL_CMD ioctl_cmd, uint32_t sub_cmd)
{
    EMAC_DRV_ERR_E status;
    EMAC_IOCTL_PARAMS params = {0};
    
    params.subCommand = sub_cmd;
    params.seqNumber = gAppTestSequenceNumber++;

    status = emac_ioctl(port_num,ioctl_cmd,&params);

    if(status != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        UART_printf("app_test_send_ioctl_cmd: port num: %d:ioctl_cmd: %d, sub command %d failed with RC: %d\n",port_num, ioctl_cmd, sub_cmd, status);
        while(1);
    }
    Task_sleep(100);
}

void app_test_verify_port_ctrl_ioctl(void)
{
    UART_printf("\napp_test_verify_port_ctrl_ioctl: BEGIN\n");

    /* EMAC_SWITCH_PORT1  */
    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_DISABLE);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_BLOCKING);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_FORWARD);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    /* EMAC_SWITCH_PORT1  */
    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_DISABLE);
    if (app_test_wait_mgmt_resp(10000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_BLOCKING);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_PORT_STATE_CTRL, EMAC_IOCTL_PORT_STATE_FORWARD);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
    Task_sleep(1000);

    UART_printf("\napp_test_verify_port_ctrl_ioctl: END\n");
}


void app_test_verify_afc_ctrl_ioctl(void)
{
    UART_printf("app_test_verify_afc_ioctl: BEGIN\n");

    /* EMAC_SWITCH_PORT1  */
    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED);
    if (app_test_wait_mgmt_resp(10000) != 0)
        while (1);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT1, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES);
    if (app_test_wait_mgmt_resp(10000) != 0)
        while (1);

    /* EMAC_SWITCH_PORT2  */
    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED);
    if (app_test_wait_mgmt_resp(10000) != 0)
        while (1);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);

    app_test_send_ioctl_cmd(EMAC_SWITCH_PORT2, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES);
    if (app_test_wait_mgmt_resp(10000) != 0)
        while (1);

    UART_printf("app_test_verify_afc_ioctl: END\n");

}

int32_t app_test_send_receive(uint32_t startP, uint32_t endP, uint32_t displayResult)
{
    uint32_t port_num;
    int32_t status = 0;
    for (port_num = startP; port_num  <= endP; port_num++)
    {
        if (!port_en[port_num])
            continue;

        if (1 == gInterposerCardPresent)
        {
            if((port_num == 0) || (port_num == 2))
                 continue;
        }
        UART_printf("app_test_send_receive: testing port: %d\n", port_num);
        status = app_test_send(port_num, pTestPkt, 0,APP_TEST_PKT_SIZE,0);

        if ((port_num == endPort) && (displayResult == 1))
        {
            UART_printf("All tests have passed\n");
        }
    }
    return status;
}

void app_test_setup_fw_switch(uint32_t port_num, EMAC_HwAttrs_V5 *pEmacCfg)
{
    EMAC_FW_APP_CONFIG *pFwAppCfg;
    emacGetSwitchFwAppInitCfg(port_num, &pFwAppCfg);
    if ((port_num & 1) == 0)
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uint32_t) &gIcssTxPortQueueMem[port_num >> 1][0]);
        pFwAppCfg->txPortQueueSize = sizeof(gIcssTxPortQueueMem) / 2;
    }
    pFwAppCfg->txPortQueueHighAddr = 0;

    emacSetSwitchFwAppInitCfg(port_num, pFwAppCfg);

    /* Need to update the emac configuraiton with  function required by the driver to get the FW configuration to write to shared mem */
    pEmacCfg->portCfg[port_num].getFwCfg = &emacGetSwitchFwConfig;
}

int32_t app_test_emac_open_switch(uint32_t mode)
{
    EMAC_socGetInitCfg(0, &app_emac_cfg);
    int32_t chanNum = 0;
    int32_t subChanNum = 0;
    uint32_t port_num;
    EMAC_MAC_ADDR_T macTest;
    gAppTestId++;
    UART_printf("EMAC_UT_%d begin, test emac open\n", gAppTestId);

    for (port_num = portNum; port_num <= endPort; port_num++)
    {
        if (!port_en[port_num])
            continue;
        app_test_task_disable_pruicss(port_num);
    }

    for (port_num = portNum; port_num <= endPort; port_num++)
    {
        if (!port_en[port_num])
            continue;

#ifdef EMAC_BENCHMARK
        app_emac_cfg.portCfg[port_num].nTxChans = 1;
        app_emac_cfg.portCfg[port_num].rxChannel.nsubChan = 2;
        app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.nsubChan= 3;
        app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.nsubChan= 3;
#endif

        for (chanNum = 0; chanNum < app_emac_cfg.portCfg[port_num].nTxChans; chanNum++)
        {
            app_emac_cfg.portCfg[port_num].txChannel[chanNum].chHandle = (void *)&gUdmaTxChanObjMem[port_num][chanNum];
            app_emac_cfg.portCfg[port_num].txChannel[chanNum].freeRingMem= (void*)&gTxChanFreeRingMem[port_num][chanNum][0];
            app_emac_cfg.portCfg[port_num].txChannel[chanNum].compRingMem= (void*)&gTxChanCompRingMem[port_num][chanNum][0];
            app_emac_cfg.portCfg[port_num].txChannel[chanNum].hPdMem = (void*)&gUdmapTxChanDescRamMem[port_num][chanNum][0];
        }
        app_emac_cfg.portCfg[port_num].rxChannel.chHandle = (void *)&gUdmaRxPktChanObjMem[port_num];
        app_emac_cfg.portCfg[port_num].rxChannel.flowHandle= (void *)&gUdmaRxPktChanFlowHndMem[port_num];
        /* each subChan is a flow which is required 1 ring pair, subChanNum 0 is used for default flow*/
        for (subChanNum = 0; subChanNum < app_emac_cfg.portCfg[port_num].rxChannel.nsubChan; subChanNum++)
        {
            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].freeRingMem[0] = (void*)&gRxPktChanFreeRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxPktChanFreeRingHndMem[port_num][subChanNum];

            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].compRingMem= (void*)&gRxPktChanCompRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxPktChanCompRingHndMem[port_num][subChanNum];

            
            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapRxPktChanDescRamMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].eventHandle = (void *)&gUdmaRxPktChanEventHndMem[port_num][subChanNum];
        }

        app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.chHandle = (void *)&gUdmaRxMgmtChanObjMem[port_num];
        app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.flowHandle= (void *)&gUdmaRxMgmtChanFlowHndMem[port_num];
        for (subChanNum = 0; subChanNum < app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.nsubChan; subChanNum++)
        {
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].freeRingMem[0] = (void*)&gRxMgmtChanFreeRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxMgmtChanFreeRingHndMem[port_num][subChanNum];
        
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].compRingMem= (void*)&gRxMgmtChanCompRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxMgmtChanCompRingHndMem[port_num][subChanNum];
        
                    
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapRxMgmtChanDescRamMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannelCfgOverPSI.subChan[subChanNum].eventHandle = (void *)&gUdmaRxMgmtChanEventHndMem[port_num][subChanNum];
        }

        app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.chHandle = (void *)&gUdmaRxMgmtChan2ObjMem[port_num];
        app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.flowHandle= (void *)&gUdmaRxMgmtChan2FlowHndMem[port_num];
        for (subChanNum = 0; subChanNum < app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.nsubChan; subChanNum++)
        {
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].freeRingMem[0] = (void*)&gRxMgmtChan2FreeRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxMgmtChan2FreeRingHndMem[port_num][subChanNum];
        
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].compRingMem= (void*)&gRxMgmtChan2CompRingMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxMgmtChan2CompRingHndMem[port_num][subChanNum];
        
                    
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapRxMgmtChan2DescRamMem[port_num][subChanNum][0];
            app_emac_cfg.portCfg[port_num].rxChannel2CfgOverPSI.subChan[subChanNum].eventHandle = (void *)&gUdmaRxMgmtChan2EventHndMem[port_num][subChanNum];
        }
    }

    for (port_num = portNum; port_num <= endPort; port_num++)
    {
        if (!port_en[port_num])
            continue;

        app_test_setup_fw_switch(port_num, &app_emac_cfg);
        EMAC_socSetInitCfg(0, &app_emac_cfg);
    }
    EMAC_socGetInitCfg(0, &app_emac_cfg);
    app_emac_cfg.portCfg[1].nTxChans = 0;
    app_emac_cfg.portCfg[1].rxChannel.nsubChan = 0;
    app_emac_cfg.portCfg[1].rxChannelCfgOverPSI.nsubChan = 0;
    app_emac_cfg.portCfg[1].rxChannel2CfgOverPSI.nsubChan = 0;

    app_emac_cfg.portCfg[3].nTxChans = 0;
    app_emac_cfg.portCfg[3].rxChannel.nsubChan = 0;
    app_emac_cfg.portCfg[3].rxChannelCfgOverPSI.nsubChan = 0;
    app_emac_cfg.portCfg[3].rxChannel2CfgOverPSI.nsubChan = 0;

    app_open_cfg.hwAttrs = (void*)&app_emac_cfg;
    app_open_cfg.free_pkt_cb = app_free_pkt;
    app_open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;
    app_open_cfg.rx_mgmt_response_cb = app_test_rx_mgmt_response_cb;
    app_open_cfg.tx_ts_cb = app_test_ts_response_cb;
    app_open_cfg.drv_trace_cb = app_test_trace_cb;
    app_open_cfg.loop_back = 0U;
#ifndef EMAC_BENCHMARK
    app_open_cfg.num_of_rx_pkt_desc = 8U;
    app_open_cfg.num_of_tx_pkt_desc = 8U;
#else
    app_open_cfg.num_of_rx_pkt_desc = 128U;
    app_open_cfg.num_of_tx_pkt_desc = 128U;
#endif
    app_open_cfg.master_core_flag = 1;
    app_open_cfg.max_pkt_size = APP_EMAC_MAX_PKT_SIZE; 
    app_open_cfg.mdio_flag = 1;
    app_open_cfg.num_of_chans = 1;
    app_open_cfg.udmaHandle = (void*)gDrvHandle;

    macTest.addr[0] = 0x48;
    macTest.addr[1] = 0x93;
    macTest.addr[2] = 0xfe;
    macTest.addr[3] = 0xfa;
    macTest.addr[4] = 0x18;
    macTest.addr[5] = 0x44;
    app_open_cfg.p_chan_mac_addr = &chan_cfg[0];
    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;
    chan_cfg[0].p_mac_addr = & macTest;
    app_open_cfg.mode_of_operation = mode;

    /* create failure case with null alloc_pkt_cb */
    app_open_cfg.alloc_pkt_cb = NULL;
    if (emac_open(EMAC_SWITCH_PORT, &app_open_cfg) != EMAC_DRV_RESULT_OK)
    {
        UART_printf("app_test_emac_open_switch: emac open returned error for SWITCH PORT, expected result\n");
    }
    app_open_cfg.alloc_pkt_cb = app_alloc_pkt;
    if (emac_open(EMAC_SWITCH_PORT, &app_open_cfg) == EMAC_DRV_RESULT_OK)
    {
        UART_printf("main: emac_open sucess for SWITCH PORT\n");
        app_test_task_init_pruicss(0);
        app_test_task_init_pruicss(1);
        app_test_task_init_pruicss(2);
        app_test_task_init_pruicss(3);
    }
    else
    {
        UART_printf("app_test_emac_open_switch: emac_open failure for SWITCH PORT\n");
        while(1);
    }

    UART_printf("EMAC_UT_%d end, test emac open passed\n", gAppTestId);
    return 0;
}

int32_t  app_test_emac_close(void)
{
    gAppTestId++;
    UART_printf("EMAC_UT_%d begin, test emac close\n", gAppTestId);

    uint32_t port_num;
    for (port_num = portNum; port_num  <= endPort; port_num++)
    {
        if (!port_en[port_num])
            continue;
        if (emac_close(port_num) == EMAC_DRV_RESULT_OK)
        {
            UART_printf("app_test_emac_close: emac close for port %d success\n", port_num);
        }
        else
        {
            UART_printf("app_test_emac_close: emac close for port %d failed\n", port_num);
            return -1;
        }
    }
    UART_printf("EMAC_UT_%d end, test emac close\n", gAppTestId);
    return 0;

}

void app_test_udma_init(void)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    instId = UDMA_INST_ID_MAIN_0;
    UdmaInitPrms_init(instId, &initPrms);

    initPrms.rmInitPrms.numIrIntr = EMAC_MAX_PORTS*8;
    initPrms.rmInitPrms.numRxCh = EMAC_MAX_PORTS*4;
    initPrms.rmInitPrms.numTxCh= EMAC_MAX_PORTS*4;

    initPrms.rmInitPrms.startFreeFlow = 0;
    initPrms.rmInitPrms.numFreeFlow = 120;

    initPrms.rmInitPrms.startFreeRing= 2;
    initPrms.rmInitPrms.numFreeRing = 300;

    /* UDMA driver init */
    retVal = Udma_init(&gUdmaDrvObj, &initPrms);
    if(UDMA_SOK == retVal)
    {
        gDrvHandle = &gUdmaDrvObj;
    }
}

void app_test_check_port_link_switch(uint32_t portNum)
{
    EMAC_LINK_INFO_T linkInfo;

    memset(&linkInfo, 0, sizeof(EMAC_LINK_INFO_T));
    do
    {
        emac_poll(portNum, &linkInfo);
        Task_sleep(100);
        UART_printf("Link for port %d is DOWN\n", portNum);
    } while(linkInfo.link_status == EMAC_LINKSTATUS_NOLINK);
    UART_printf("Link for port %d is now UP, change: %d, link status: %d\n", portNum, linkInfo.link_status_change, linkInfo.link_status);
}

#if defined (EMAC_CHECK_LINK_STATUS) && defined (__aarch64__)
#define APP_TEST_PMU_SAMPLE_COUNT 100 
#define APP_TEST_LINK_DOWN 0
#define APP_TEST_LINK_100HD 1
#define APP_TEST_LINK_1G 2
#define APP_TEST_LINK_POLL_TOO_LONG 3
#define APP_TEST_MAX_STRING_SIZE 64
#define APP_TEST_PMU_CYLE_POLL_DURATION_CRITERIA 350000 /* 350000 cycles @800 MHz */

uint64_t cyclesPmu[APP_TEST_PMU_SAMPLE_COUNT];
char app_test_link_results_array[][APP_TEST_MAX_STRING_SIZE] =
{
    "LINK IS DOWN",
    "100 mbps FD LINK ESTABLISED",
    "1000 FD LINK ESTABLISHED",
    "POLL period took too long"
};

void app_test_print_results(uint32_t portNum, uint32_t linkSpeed, uint64_t cyclesPmu)
{
    UART_printf("link status for port: %d: %s,  PMU CYLES: 0x%x%08x\n",
                                       portNum,
                                       app_test_link_results_array[linkSpeed],
                                       (unsigned int)(cyclesPmu >> 32),
                                       (unsigned int)(cyclesPmu & 0xFFFFFFFF));
}

/* Verification of link speed/duplexity and emac poll period duration*/
void app_test_get_link_status(uint32_t portNum)
{
    EMAC_LINK_INFO_T linkInfo;
    uint64_t overHeadPmu =0;
    overHeadPmu = CSL_getPmuCycleCountOverhead();
    uint32_t countPmu = 0;
    char     input;
    linkInfo.link_status = 0;
    linkInfo.link_status_change = 0;
    uint32_t connectCable = 0;
    while(1)
    {
        UART_printf ("Please enter E to exit LINK STATUS CHECK, or any other character to continue\n");
        input = (char) UART_getc();

        if ((int8_t) 'E' == (int8_t)(input))
        {
            UART_printf ("Exiting link status check\n");
            break;
        }
        else
        {
            /* at this point, link should be active */
            if (connectCable == 0)
                UART_printf ("unplug the ethernet cable for SWITCH PORT 1\n");
            else
                UART_printf ("plug the ethernet cable for SWITCH PORT 1 with either GIGABIT port or 100 MBPS full duplex port\n");
            do
            {
                memset(&linkInfo, 0, sizeof(EMAC_LINK_INFO_T));
                CSL_startPmuCycleCounter();
                emac_poll(portNum, &linkInfo);
                CSL_stopPmuCycleCounter();
                if (linkInfo.link_status_change == 1)
                {
                    cyclesPmu[countPmu] = CSL_getPmuCycleCount() - overHeadPmu;
                    CSL_clearPmuCycleCounter();
                    if (cyclesPmu[countPmu] > APP_TEST_PMU_CYLE_POLL_DURATION_CRITERIA)
                    {
                        app_test_print_results(portNum, APP_TEST_LINK_POLL_TOO_LONG,cyclesPmu[countPmu]);
                        gTestFailCount++;
                        UART_printf("fail3\n");
                    }
                    switch(linkInfo.link_status)
                    {
                        case 0:
                            connectCable = 1;
                            app_test_print_results(portNum, APP_TEST_LINK_DOWN,cyclesPmu[countPmu]);
                            break;
                        case 4:
                            connectCable = 0;
                            app_test_print_results(portNum, APP_TEST_LINK_100HD,cyclesPmu[countPmu]);
                            break;
                        case 5:
                            connectCable = 0;
                            app_test_print_results(portNum, APP_TEST_LINK_1G,cyclesPmu[countPmu]);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                CSL_clearPmuCycleCounter();
            } while(linkInfo.link_status == EMAC_LINKSTATUS_NOLINK);
            if (++countPmu == APP_TEST_PMU_SAMPLE_COUNT)
                countPmu = 0;
            Osal_delay(100);
        }
    }
}
#endif

void app_test_port_set_state(uint32_t portNum, uint8_t state)
{
    EMAC_IOCTL_PARAMS params;
    params.subCommand = state;
    params.seqNumber = gAppTestSequenceNumber++;
    emac_ioctl(portNum, EMAC_IOCTL_PORT_STATE_CTRL, &params);
    if (app_test_wait_mgmt_resp(1000) != 0)
        while (1);
}

void app_test_get_icssg_stats(uint32_t pNum)
{
    gAppTestId++;
    UART_printf("EMAC_UT_%d begin collecting icssg stats\n", gAppTestId);
    memset(&gIcssHwStats, 0, sizeof(EMAC_STATISTICS_ICSSG_T));
    if ((emac_get_statistics_icssg(pNum, &gIcssHwStats, FALSE) == EMAC_DRV_RESULT_OK))
     {
        UART_printf("**********ICSSG HW stats for PORT NUMBER %d**********\n", pNum);
        UART_printf("-----------------------------------------------------------------------------------------------------------------\n");
        UART_printf(" RX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct:          %12u |\n",
                        gIcssHwStats.RxGoodFrames,
                        gIcssHwStats.RxBCastFrames,
                        gIcssHwStats.RxMCastFrames,
                        gIcssHwStats.RXTotalByte);
        UART_printf(" RX |     CRC :      %12u | MIIErr:      %12u | OddNibble: %12u | MaxSizeLimit: %12u |\n",
                        gIcssHwStats.RxCRCErrors,
                        gIcssHwStats.RxMIIErrors,
                        gIcssHwStats.RXOddNibbleFrame,
                        gIcssHwStats.RXMaxSizeFrame);
        UART_printf(" RX |     MaxSizeErr:%12u | MinSizeLimit:%12u | MinSizeErr:%12u | OverrunFrame :%12u |\n",
                        gIcssHwStats.RXMaxSizeErrFrame,
                        gIcssHwStats.RXMinSizeFrame,
                        gIcssHwStats.RXMinSizeErrFrame,
                        gIcssHwStats.RXoverrunFrame);
        UART_printf(" RX |     Class0:    %12u | Class1:      %12u | Class2:    %12u | Class3:       %12u |\n",
                        gIcssHwStats.RXClass0,
                        gIcssHwStats.RXClass1,
                        gIcssHwStats.RXClass2,
                        gIcssHwStats.RXClass3);
        UART_printf(" RX |     Class4:    %12u | Class5:      %12u | Class6:    %12u | Class7:       %12u |\n",
                        gIcssHwStats.RXClass4,
                        gIcssHwStats.RXClass5,
                        gIcssHwStats.RXClass6,
                        gIcssHwStats.RXClass7);
        UART_printf(" RX |     Class8:    %12u | Class9:      %12u | Class10:   %12u | Class11:      %12u |\n",
                        gIcssHwStats.RXClass8,
                        gIcssHwStats.RXClass9,
                        gIcssHwStats.RXClass10,
                        gIcssHwStats.RXClass11);
        UART_printf(" RX |     Class12:   %12u | Class13:     %12u | Class14:   %12u | Class15:      %12u |\n",
                        gIcssHwStats.RXClass12,
                        gIcssHwStats.RXClass13,
                        gIcssHwStats.RXClass14,
                        gIcssHwStats.RXClass15);
        UART_printf(" TX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct           %12u |\n",
                        gIcssHwStats.TXGoodFrame,
                        gIcssHwStats.TXBCFrame,
                        gIcssHwStats.TXMCFrame,
                        gIcssHwStats.TXTotalByte);
        UART_printf(" TX |     OddNibble: %12u | UnderFlowErr:%12u | MaxSize:   %12u | MaxSizeErr:   %12u |\n",
                        gIcssHwStats.TXOddNibbleFrame,
                        gIcssHwStats.TXUnderFlowErr,
                        gIcssHwStats.TXMaxSizeFrame,
                        gIcssHwStats.TXMaxSizeErrFrame);
        UART_printf("---------------------------------------------------------------------------------------------------------------\n");
    }
    UART_printf("EMAC_UT_%d  collecting icssg stats passed\n", gAppTestId);
}


#ifdef EMAC_BENCHMARK
uint32_t app_test_start_send = 1;
void app_test_task_benchmark(UArg arg0, UArg arg1)
{
    uint32_t port = (uint32_t) arg0;
    Board_STATUS boardInitStatus =0;
    PRUICSS_Config *prussCfg;
    SemaphoreP_Params emac_app_test_sem_params;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
    
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=BOARD_SOK)
    {
        UART_printf("Board_init failure\n");
        while(1);
    }
    UART_printf("Board_init success for UT switch\n");


    EMAC_osalSemParamsInit(&emac_app_test_sem_params);
    emac_app_test_sem_params.mode = SemaphoreP_Mode_BINARY;
    gAppTestIoctlWaitAckSem =  EMAC_osalCreateBlockingLock(0,&emac_app_test_sem_params);

    if (app_detect_interposer_card() == TRUE)
    {
        UART_printf("Interposer card is  present\n");
        gInterposerCardPresent = 1;
    }
    else
    {
        UART_printf("Interposer card is NOT present\n");
    }

    app_init();
    PRUICSS_socGetInitCfg(&prussCfg);
    gPrussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
    gPrussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);

    app_test_udma_init();
    gPollModeEnabled =1;

    if (app_test_emac_open_switch(EMAC_MODE_POLL) != 0)
    {
        UART_printf("app_test_emac_open failed\n");
    }
     gInitComplete = 1;
    app_test_check_port_link_switch(port);

    /*Set up default setting for test app */
    app_test_setup_default_settings();

    /*Set port state to Forward*/
    app_test_port_set_state(port,EMAC_IOCTL_PORT_STATE_FORWARD);

    Task_sleep(2000);

    pTestPkt = (uint8_t*)(&app_test_loopback_pkt_vlan[0]);

    while (1)
    {
        if (app_test_start_send == 1)
        {
            app_test_send(port, pTestPkt, 0, APP_TEST_MAX_PKT_SEND_SIZE,0);
            app_test_start_send = 0;
        }
        Task_sleep(5000);
        app_test_get_icssg_stats(EMAC_SWITCH_PORT1);
        app_test_get_icssg_stats(EMAC_SWITCH_PORT2);
    }
}
#else

void test_EMAC_verify_icssg_switch(void)
{
    /* @description:Unit test for ICSSG switch use case
    
       @requirements: PRSDK-3848, PRSDK-3789, PRSDK-3790, PRSDK-3800, PRSDK-3805,
                      PRSDK-3840, PRSDK-3842, PRSDK-3846, PRSDK-5180, PRSDK-5181,
                      PRSDK-7722
    
       @cores: mpu1_0, mcu1_0 */

    Board_STATUS boardInitStatus =0;
    PRUICSS_Config *prussCfg;
    SemaphoreP_Params emac_app_test_sem_params;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
    
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=BOARD_SOK)
    {
        UART_printf("Board_init failure\n");
        while(1);
    }
    UART_printf("Board_init success for UT switch\n");


    EMAC_osalSemParamsInit(&emac_app_test_sem_params);
    emac_app_test_sem_params.mode = SemaphoreP_Mode_BINARY;
    gAppTestIoctlWaitAckSem =  EMAC_osalCreateBlockingLock(0,&emac_app_test_sem_params);

    if (app_detect_interposer_card() == TRUE)
    {
        UART_printf("Interposer card is  present\n");
        gInterposerCardPresent = 1;
    }
    else
    {
        UART_printf("Interposer card is NOT present\n");
    }

    app_init();

    PRUICSS_socGetInitCfg(&prussCfg);
    gPrussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
    gPrussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);

    app_test_udma_init();

    if (app_test_emac_open_switch(EMAC_MODE_POLL) != 0)
    {
        UART_printf("app_test_emac_open failed\n");
    }
    gInitComplete = 1;

    app_test_check_port_link_switch(EMAC_SWITCH_PORT1);

#if defined (EMAC_CHECK_LINK_STATUS) && defined (__aarch64__)
    app_test_get_link_status(EMAC_SWITCH_PORT1);
    if (gTestFailCount == 0)
    {
        UART_printf("All tests have passed\n");
    }
    else
    {
        UART_printf("Some tests have failed: failure count: %d\n", gTestFailCount);
    }
#else
    app_test_check_port_link_switch(EMAC_SWITCH_PORT2);
    /*Set up default setting for test app */

    gPollModeEnabled =1;
    app_test_setup_default_settings();

    /*Set port state to Forward*/
    app_test_port_set_state(EMAC_SWITCH_PORT1,EMAC_IOCTL_PORT_STATE_FORWARD);
    app_test_port_set_state(EMAC_SWITCH_PORT2,EMAC_IOCTL_PORT_STATE_FORWARD);


    gPollModeEnabled =2;
    /* Verify local injection using loopback connection between SW1 and SW2 */
    app_test_local_injection();
    gPollModeEnabled =1;
    /* Verify Port Priority by sending packets with different PCP to ensure recieved on correct flow/ring pair*/
    app_test_port_priority();

    /* FDB control ioctl verification */
    app_test_fdb_ioctl();
    Task_sleep(1000);

    /* Acceptable frame check (afc) control ioctl verification */
    app_test_verify_afc_ctrl_ioctl();
    Task_sleep(1000);

    /* UC flood control ioctl verification */
    app_test_flood_ctrl();
    Task_sleep(1000);

    /* Port port control ioctl verification */
    app_test_verify_port_ctrl_ioctl();

    /* Cut through/prempt select ioctl verification */
    app_test_configure_cut_through_or_prempt_select_ctrl(EMAC_SWITCH_PORT1);
    app_test_configure_cut_through_or_prempt_select_ctrl(EMAC_SWITCH_PORT2);

    gInitComplete = 0;
    emac_close(EMAC_SWITCH_PORT);

    /* verify open->close->open scenario */
    if (app_test_emac_open_switch(EMAC_MODE_POLL) != 0)
    {
        UART_printf("app_test_emac_open failed\n");
    }
    gInitComplete = 1;

    app_test_setup_default_settings();

    /*Set port state to Forward*/
    app_test_port_set_state(EMAC_SWITCH_PORT1,EMAC_IOCTL_PORT_STATE_FORWARD);
    app_test_port_set_state(EMAC_SWITCH_PORT2,EMAC_IOCTL_PORT_STATE_FORWARD);

    /* verify send/rx after close and re-open */
    app_test_reopen();

    app_test_get_icssg_stats(EMAC_SWITCH_PORT1);
    app_test_get_icssg_stats(EMAC_SWITCH_PORT2);

    if (gTestFailCount == 0)
    {
        UART_printf("All tests have passed\n");
        TEST_PASS();
    }
    else
    {
        UART_printf("Some tests have failed: failure count: %d\n", gTestFailCount);
        TEST_FAIL();
    }
    while(1)
    {
       Task_sleep(1000);
    }
#endif
}

void test_Emac_Icssg_Switch_TestApp_runner(void)
{
    /* @description:Test runner for EMAC icssg switch tests

       @requirements: PRSDK-3848, PRSDK-3789, PRSDK-3790, PRSDK-3800, PRSDK-3805,
                      PRSDK-3840, PRSDK-3842, PRSDK-3846, PRSDK-5180, PRSDK-5181,
                      PRSDK-7722

       @cores: mpu1_0, mcu1_0 */

    UNITY_BEGIN();
    RUN_TEST(test_EMAC_verify_icssg_switch);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
}

void app_test_task_verify_ut_switch(UArg arg0, UArg arg1)
{
    test_Emac_Icssg_Switch_TestApp_runner();
}
#endif

/*
 *  ======== app_test_task_init_pruicss========
 */
int32_t  app_test_task_disable_pruicss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t pru_n, rtu_n, slice_n ;

    if (portNum > 5)
        return -1;

    prussDrvHandle =gPrussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;

    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;

    if (PRUICSS_pruDisable(prussDrvHandle, pru_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_PRU%d failed\n", slice_n);

    if (PRUICSS_pruDisable(prussDrvHandle, rtu_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_RTU%d failed\n", slice_n);

    /* CLEAR SHARED MEM which is used for host/firmware handshake */
    PRUICSS_pruInitMemory(prussDrvHandle, PRU_ICSS_SHARED_RAM); 


    return 0;
}

/*
 *  ======== app_test_task_init_pruicss========
 */
int32_t  app_test_task_init_pruicss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t firmwareLoad_done = FALSE;
    uint8_t pru_n, rtu_n, slice_n ;
    uint32_t icssGInst;

    if (portNum > 3)
        return -1;
    icssGInst = portNum >> 1;

    prussDrvHandle =gPrussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;
    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;


    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM(slice_n), 0,
                               gIcssgSwtchFw[icssGInst][slice_n].pru, gIcssgSwtchFw[icssGInst][slice_n].pruSize)) {
        if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM(slice_n + 2), 0,
                                   gIcssgSwtchFw[icssGInst][slice_n].rtu, gIcssgSwtchFw[icssGInst][slice_n].rtuSize))
            firmwareLoad_done = TRUE;
        else
            UART_printf("PRUICSS_pruWriteMemory for PRUICCSS_PRU%d failed\n", slice_n);
    }
    else
        UART_printf("PRUICSS_pruWriteMemory for PRUICCSS_RTU%d failed\n", slice_n);
    if( firmwareLoad_done)
    {
        if (PRUICSS_pruEnable(prussDrvHandle, pru_n) != 0)
            UART_printf("PRUICSS_pruEnable for PRUICCSS_PRU%d failed\n", slice_n);
        if (PRUICSS_pruEnable(prussDrvHandle, rtu_n) != 0)
            UART_printf("PRUICSS_pruEnable for PRUICCSS_RTU%d failed\n", slice_n);
    }

    return 0;
}


/* VLAN ID's for testing */
uint16_t vlan_id_host_port = 0x2;
uint16_t vlan_id_switch_port1 = 0x4;
uint16_t vlan_id_switch_port2 = 0x6;

uint16_t new_common_vlan_id = 100;
uint16_t new_common_vlan_id_tag_pkt = 101;


EMAC_IOCTL_PARAMS params;
EMAC_IOCTL_FDB_ENTRY fdb_entry;

/*
* @brief
 *This function is configure default host vlan 
 */
int32_t app_test_config_default_host_vlan(uint32_t vlan_id, uint8_t pcp)
{
    int32_t retVal = APP_TEST_SUCCESS;
    EMAC_IOCTL_VLAN_DEFAULT_ENTRY vlanDefaultEntry;

    vlanDefaultEntry.pcp = pcp;
    vlanDefaultEntry.vlanId = (uint16_t)vlan_id;

    /* Set default VLAN ID for the host port */
    params.subCommand = EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID;
    params.ioctlVal = (void *)&vlanDefaultEntry;
    retVal = emac_ioctl(EMAC_SWITCH_PORT0, EMAC_IOCTL_VLAN_CTRL, &params);

    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("VLAN is not set for HOST = %u \n", vlan_id);
        retVal = APP_TEST_FAILURE;
    }

    return retVal;
}

/*
 * @brief
 * This function is used to add FDB entry
 */
int32_t  app_test_add_fdb_entry(int16_t vlanId)
{
    int32_t retVal = APP_TEST_SUCCESS;

    fdb_entry.vlanId = vlanId;
    /**< FDB entry with the following bit fields starting with bit 0: fdb_host, fdb_port1, fdb_port2, fdb_ageable, fdb_block, fdb_secure, fdb_touched, fdb_valid.
    Two entries for two ports */
    /* fdb entry for PORT1 */
    fdb_entry.fdbEntry[0] = (uint8_t)0x81;

    /*fdb entry for PORT2 */
    fdb_entry.fdbEntry[1] = (uint8_t)0x81;

    params.subCommand = EMAC_IOCTL_FDB_ENTRY_ADD;
    params.ioctlVal = (void *)&fdb_entry;
    params.seqNumber = gAppTestSequenceNumber++;

    retVal = emac_ioctl(EMAC_SWITCH_PORT, EMAC_IOCTL_FDB_ENTRY_CTRL, (void *)(&params));
    if(retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        UART_printf("Success: IOCTL command sent for making FDB entry \n");
        //asynchronous IOCTL so wait for acknowledgment
        retVal = app_test_wait_mgmt_resp(20);
    }
    else
    {
        UART_printf("ERROR: IOCTL command sent for making FDB entry \n");
        retVal = APP_TEST_FAILURE;
    }

    return retVal;
}
/*
 * @brief
 * This function is used to configure HOST MAC address
 * This MAC address will be updated in MMR register
 * as well as make an entry in FDB
 */
int32_t app_test_config_host_mac_address(EMAC_MAC_ADDR_T app_test_host_mac)
{
    int32_t retVal = APP_TEST_SUCCESS;
    int32_t i = 0;

    //synchronous IOCTL to make entry in MMR for HOST MAC address
    params.subCommand = EMAC_IOCTL_INTERFACE_MAC_ADD;
    params.ioctlVal = (void *)&app_test_host_mac;

    retVal = emac_ioctl(EMAC_SWITCH_PORT0, EMAC_IOCTL_INTERFACE_MAC_CONFIG, (void *)(&params));

    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("Entry in MMR for HOST MAC address is not done successfully\n");
        retVal = APP_TEST_FAILURE;
    }
    else
    {
        //Now make an entry in FDB for the HOST MAC address using Asynchronous IOCTL
        for(i = 0; i <= 5; i++)
        {
            fdb_entry.mac[i] = app_test_host_mac.addr[i];
            app_test_loopback_pkt_vlan[i] = app_test_host_mac.addr[i];
        }
        retVal = app_test_add_fdb_entry(new_common_vlan_id);
    }
    return retVal;

}

/*
 * @brief
 * This function is used to configure PORT1 MAC address
 * This MAC address will be updated in MMR register
 * as well as make an entry in FDB
 */
int32_t app_test_config_port1_mac_address(EMAC_MAC_ADDR_T app_test_sw_port1_mac)
{
    int32_t retVal = 0;
    uint32_t i = 0;

    //synchronous IOCTL to make entry in MMR for PORT1 MAC address
    params.subCommand = EMAC_IOCTL_INTERFACE_MAC_ADD;
    params.ioctlVal = (void *)&app_test_sw_port1_mac;
    retVal = emac_ioctl(EMAC_SWITCH_PORT1, EMAC_IOCTL_INTERFACE_MAC_CONFIG, (void *)(&params));

    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("Entry in MMR for PORT1 MAC address is not done successfully\n");
        retVal = APP_TEST_FAILURE;
    }
    else
    {
        //FDB entry for PORT1 MAC address
        for(i = 0; i <= 5; i++)
        {
            fdb_entry.mac[i] = app_test_sw_port1_mac.addr[i];
        }
        retVal = app_test_add_fdb_entry(new_common_vlan_id);
    }
    return retVal;
}

/*
 * @brief
 * This function is used to configure PORT2 MAC address
 * This MAC address will be updated in MMR register
 * as well as make an entry in FDB
 */
int32_t app_test_config_port2_mac_address(EMAC_MAC_ADDR_T app_test_sw_port2_mac)
{
    int32_t retVal = APP_TEST_SUCCESS;
    uint32_t i = 0;

    //synchronous IOCTL to make entry in MMR for PORT2 MAC address
    params.subCommand = EMAC_IOCTL_INTERFACE_MAC_ADD;
    params.ioctlVal = (void *)&app_test_sw_port2_mac;
    retVal = emac_ioctl(EMAC_SWITCH_PORT2, EMAC_IOCTL_INTERFACE_MAC_CONFIG, (void *)(&params));

    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("Entry in MMR for PORT2 MAC address is not done successfully\n");
        retVal = APP_TEST_FAILURE;
    }
    else
    {
        //FDB entry for PORT2
        for(i = 0; i <= 5; i++)
        {
            fdb_entry.mac[i] = app_test_sw_port2_mac.addr[i];
        }
        retVal = app_test_add_fdb_entry(new_common_vlan_id);
    }
        return retVal;
}

int32_t app_test_config_default_port_vlan(uint32_t port_num, uint32_t vlan_id, uint8_t pcp)
{
    int32_t retVal;
    EMAC_IOCTL_VLAN_DEFAULT_ENTRY vlanDefaultEntry;

    /* Set default VLAN ID for the SW port */
    vlanDefaultEntry.pcp = pcp;
    vlanDefaultEntry.vlanId = (uint16_t)vlan_id;
    params.subCommand = EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID;
    params.ioctlVal = (void *)&vlanDefaultEntry;
    retVal = emac_ioctl(port_num, EMAC_IOCTL_VLAN_CTRL, &params);

    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("Default VLAN = %u is not set for PORT = %u \n", vlan_id, port_num);
        retVal = APP_TEST_FAILURE;
    }

    return retVal;

}

int32_t app_test_setup_default_settings()
{
    int32_t retVal = 0;
    int32_t i = 0;


    EMAC_IOCTL_VLAN_FID_PARAMS vlanParams = {/*.fid = */new_common_vlan_id, /*.host_member =*/ 1, /*.p1_member =*/ 1,  /*.p2_member =*/ 1, \
                                                        /*.host_tagged = */0, /*.p1_tagged = */1, /*.p2_tagged = */1, /*.stream_vid =*/ 0, /*.flood_to_host = */0
                                            };
    EMAC_IOCTL_VLAN_FID_PARAMS vlanParamsForPrioTag = {/*.fid = */0, /*.host_member =*/ 1, /*.p1_member =*/ 1,  /*.p2_member =*/ 1, \
                                                                  /*.host_tagged = */0, /*.p1_tagged = */1, /*.p2_tagged = */1, /*.stream_vid =*/ 0, /*.flood_to_host = */0
                                                      };

    EMAC_MAC_ADDR_T app_test_host_mac;
    EMAC_MAC_ADDR_T app_test_sw_port1_mac;
    EMAC_MAC_ADDR_T app_test_sw_port2_mac;

    for(i = 0; i < EMAC_MAC_ADDR_LENTH; i++)
    {
        app_test_host_mac.addr[i] = lclMac[i];
        app_test_sw_port1_mac.addr[i] = lclMac[i];
        app_test_sw_port2_mac.addr[i] = lclMac[i];
    }

    //change the last bytes of PORT1 and PORT2 MAC address
    app_test_sw_port1_mac.addr[EMAC_MAC_ADDR_LENTH-1] = lclMac[EMAC_MAC_ADDR_LENTH-1] + 1; // uint8_t lclMac[6] = {0x48, 0x93, 0xfe, 0xda, 0x16, 0x4b};
    app_test_sw_port2_mac.addr[EMAC_MAC_ADDR_LENTH-1] = lclMac[EMAC_MAC_ADDR_LENTH-1] + 2; // uint8_t lclMac[6] = {0x48, 0x93, 0xfe, 0xda, 0x16, 0x4c};

    /* Make default entry for common vlan id */
    retVal = app_test_vlan_ctrl_set_tbl_entry(EMAC_SWITCH_PORT, new_common_vlan_id, new_common_vlan_id, &vlanParams);
    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("FID VLAN entry is not done for HOST successfully\n");
    }

    /* Make an entry for Priority tag */
    retVal = app_test_vlan_ctrl_set_tbl_entry(EMAC_SWITCH_PORT, 0, 0, &vlanParamsForPrioTag);
    if(retVal != EMAC_DRV_RESULT_OK)
    {
        UART_printf("FID VLAN entry is not done for VID = 0 successfully\n");
    }

    /* Configure default host vlan id */ 
    retVal = app_test_config_default_host_vlan(new_common_vlan_id, 2);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating default VLAN for Host \n");
    }

    /* Configure Host Port MAC in MMR and make FDB entry */
    retVal = app_test_config_host_mac_address(app_test_host_mac);

    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating HOST_MAC address \n");
    }

    /* Set default vlan for  P1 */
    retVal = app_test_config_default_port_vlan(EMAC_SWITCH_PORT1, new_common_vlan_id, 4);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating default VLAN for P1 \n");
    }

    /* Configure Port 1 MAC in MMR and make FDB entry */
    retVal = app_test_config_port1_mac_address(app_test_sw_port1_mac);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT1_MAC address \n");
    }

    /* Set default vlan for  P1 */
    retVal = app_test_config_default_port_vlan(EMAC_SWITCH_PORT2, new_common_vlan_id, 6);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating default VLAN for P2 \n");
    }

    /* Configure Port 2 MAC in MMR and make FDB entry */
    retVal = app_test_config_port2_mac_address(app_test_sw_port2_mac);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT2_MAC address \n");
    }

    /*Configure default priority map table*/
    retVal = app_test_port_prio_map_cfg(EMAC_SWITCH_PORT1);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT 1 priority map table \n");
    }

    retVal = app_test_port_prio_map_cfg(EMAC_SWITCH_PORT2);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT 2 priority map table \n");
    }
    /*Configure default priority regeneration table*/
    retVal = app_test_configure_default_prio_regen_tbl(EMAC_SWITCH_PORT1);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT 1 priority regeneration \n");
    }

    retVal = app_test_configure_default_prio_regen_tbl(EMAC_SWITCH_PORT2);
    if(retVal != APP_TEST_SUCCESS)
    {
        UART_printf("\n ERROR: In updating PORT 2 priority regeneration \n");
    }

    return retVal;
}

void app_output_log(Char* str, UInt numChar)
{
    if (numChar > 0)
    {
        UART_printf(str);
    }
}

