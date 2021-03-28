/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2018-2020
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
 *  \file     test_utils_k3.c
 *
 *  \brief    This file contains common utility functions used by the emac loopback unit
 *             test applications.
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

#include <ti/drv/emac/src/emac_osal.h>
#include <ti/drv/emac/emac_ioctl.h>
/* SOC Include Files. */
#include <ti/drv/emac/soc/emac_soc_v5.h>

/* Test application local header file */
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

#ifdef SOC_J721E
#include <ti/board/src/j721e_evm/include/board_pinmux.h>
#include <ti/board/src/j721e_evm/include/board_control.h>
#endif

#ifdef EMAC_TEST_APP_ICSSG
#include <ti/drv/emac/firmware/icss_dualmac/config/emac_fw_config_dual_mac.h>
#include <ti/drv/emac/firmware/icss_switch/config/emac_fw_config_switch.h>
/* PRUSS Driver Header File. */
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#endif


#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif


extern uint32_t portNum;
extern uint32_t endPort;
extern int port_en[];

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

#ifdef SOC_J721E
uint8_t icss_tx_port_queue[2][100352] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_ocmc_mem")));
#else
#ifdef EMAC_TEST_APP_WITHOUT_DDR
/* DDR less test, can only test with 2 ports due to msmc memory constraints */
uint8_t icss_tx_port_queue[1][100352] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_msmc_mem")));
#else
#ifdef EMAC_BENCHMARK
uint8_t icss_tx_port_queue[1][100352] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_msmc_mem")));
#else /* test all port for DUAL MAC */
uint8_t icss_tx_port_queue[3][100352] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:emac_msmc_mem")));
#endif
#endif
#endif

uint32_t interposerCardPresent = 0;

#ifdef EMAC_TEST_APP_ICSSG
PRUICSS_Handle prussHandle[EMAC_MAX_ICSS] = {NULL, NULL, NULL};
int hs_index[EMAC_MAX_ICSS * EMAC_MAC_PORTS_PER_ICSS];    //one per icss slice
#endif


#define APP_TEST_AM65XX_PG1_0_VERSION (0x0BB5A02FU)

/* Maxwell PG version */
uint32_t gPgVersion;


/* Test will use network firmware to verify packet transmission
  * and reception between 2 physical ICSSG ports, each ICSSG port needs to be connected
  * to another ICSSG port via ethernet cable.

  * NOTE that for CPSW port, test will always test loopback mode of operation
  * with CPSW sub-system.
  */

#ifdef EMAC_TEST_APP_ICSSG
/* EMAC firmware header files */



/* PG 1.0 Firmware */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii0_bin.h>      /* PDSPcode */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test0_bin.h>             /* PDSP2code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii1_bin.h>      /* PDSP3code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test1_bin.h>             /* PDSP4code */


/* PG2.0 firmware */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rxl2_rgmii0_bin.h>      /* PDSPcode */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rtu_test0_bin.h>        /* PDSP2code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rxl2_rgmii1_bin.h>      /* PDSP3code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rtu_test1_bin.h>        /* PDSP4code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/txl2_rgmii0_bin.h>      /* PDSP5code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/txl2_rgmii1_bin.h>      /* PDSP6code */

typedef struct {
    const uint32_t *pru;
    uint32_t pru_size;
    const uint32_t *rtu;
    uint32_t rtu_size;
    const uint32_t *txpru;
    uint32_t txpru_size;
} app_test_pru_rtu_fw_t;

app_test_pru_rtu_fw_t firmware_pg1[2] = {
    { PDSPcode_0, sizeof(PDSPcode_0), PDSP2code_0, sizeof(PDSP2code_0), NULL, 0},
    { PDSP3code_0, sizeof(PDSP3code_0), PDSP4code_0, sizeof(PDSP4code_0), NULL, 0}
};

app_test_pru_rtu_fw_t firmware_pg2[2] = {
    { PDSPcode_0_PG2, sizeof(PDSPcode_0_PG2), PDSP2code_0_PG2, sizeof(PDSP2code_0_PG2), PDSP5code_0_PG2, sizeof(PDSP5code_0_PG2)},
    { PDSP3code_0_PG2, sizeof(PDSP3code_0_PG2), PDSP4code_0_PG2, sizeof(PDSP4code_0_PG2),  PDSP6code_0_PG2, sizeof(PDSP6code_0_PG2)}
};

#endif

int32_t app_test_task_init_pruicss(uint32_t portNum);
int32_t app_test_task_disable_pruicss(uint32_t portNum);




uint32_t pollModeEnabled = 0;
uint32_t linkStatus = 0;
uint32_t initComplete = 0;
uint32_t app_test_id = 0;
#if defined (EMAC_BENCHMARK)
#if defined  (EMAC_TEST_APP_ICSSG)
uint32_t app_test_send_port = 4U;
uint32_t app_test_recv_port = 4U;
#else
uint32_t app_test_send_port = 6U;
uint32_t app_test_recv_port = 6U;
#endif
#endif
#ifdef _TMS320C6X
/* Memory allocated for the packet buffer. This is 128 bytes aligned. */
uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE];
#pragma DATA_ALIGN(app_pkt_buffer, 64)

/* Memory allocated for the application control block */
#else
#ifdef EMAC_TEST_APP_WITHOUT_DDR
uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned(64)));
#else
uint8_t   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned(64))) __attribute__ ((section (".bss:emac_ddr_mem")));
#endif
#endif

int32_t gFail_count;

int32_t testPktClone = 0;
#ifndef EMAC_TEST_APP_WITHOUT_DDR
#define EMAC_TEST_MAX_CHANS_PER_PORT 4
#define EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT 9
#else
#define EMAC_TEST_MAX_CHANS_PER_PORT 1
#define EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT 3
#endif
/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT];
struct Udma_ChObj       gUdmaRxChObj[EMAC_MAX_PORTS];
struct Udma_EventObj    gUdmaRxCqEventObj[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT];


struct Udma_ChObj       gUdmaRxMgmtPsiChObj[EMAC_MAX_PORTS];
struct Udma_EventObj    gUdmaRxMgmtPsiCqEventObj[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT];

Udma_DrvHandle          gDrvHandle = NULL;

/* Ring parameters*/
/*brief Number of ring entries - we can prime this much memcpy operations */
#ifdef EMAC_TEST_APP_WITHOUT_DDR
#define EMAC_TEST_APP_RING_ENTRIES      (32)
#else
#define EMAC_TEST_APP_RING_ENTRIES      (128)
#endif
/* Size (in bytes) of each ring entry (Size of pointer - 64-bit) */

#define EMAC_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/* Total ring memory */

#define EMAC_TEST_APP_RING_MEM_SIZE     (EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_RING_ENTRY_SIZE)

/* UDMA host mode buffer descriptor memory size.    *  Make it multiple of 128 byte alignment */
#define EMAC_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (128U - sizeof(CSL_UdmapCppi5HMPD)))

/*
 * UDMA Memories
 */
#ifdef EMAC_TEST_APP_WITHOUT_DDR
static uint8_t gTxRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_FlowObj gUdmaFlowHnd[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxRingHnd[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxCompRingHnd[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxRingHndCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxCompRingHndCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxRingMemCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxCompRingMemCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_FlowObj gUdmaFlowHndCfgPsi[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
/* TX/RX ring CPPI descriptor memory */
static uint8_t gUdmapDescRamTx[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmapDescRamRx[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmapDescRamRxMgmtPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
#else
static uint8_t gTxRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gTxCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxRingHnd[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                            __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxCompRingHnd[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                            __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_FlowObj gUdmaFlowHnd[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxRingHndCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_RingObj gUdmaRxCompRingHndCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxCompRingMem[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));

static uint8_t gRxRingMemCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                        __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gRxCompRingMemCfgPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                         __attribute__ ((section (".bss:emac_ddr_mem")));
struct Udma_FlowObj gUdmaFlowHndCfgPsi[EMAC_MAX_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
/* TX/RX ring CPPI descriptor memory */
static uint8_t gUdmapDescRamTx[EMAC_MAX_PORTS][EMAC_TEST_MAX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                    __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gUdmapDescRamRx[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                      __attribute__ ((section (".bss:emac_ddr_mem")));
static uint8_t gUdmapDescRamRxMgmtPsi[EMAC_MAX_PORTS][EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT][EMAC_TEST_APP_RING_ENTRIES * EMAC_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

#endif



#ifdef EMAC_TEST_APP_WITHOUT_DDR
EMAC_CHAN_MAC_ADDR_T chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
EMAC_HwAttrs_V5 emac_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
APP_EMAC_MCB_T   app_mcb __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
EMAC_OPEN_CONFIG_INFO_T open_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
#else
EMAC_CHAN_MAC_ADDR_T chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

EMAC_HwAttrs_V5 emac_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

APP_EMAC_MCB_T   app_mcb __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));

EMAC_OPEN_CONFIG_INFO_T open_cfg __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
                                  __attribute__ ((section (".bss:emac_ddr_mem")));
#endif

uint32_t pkt_rcv_count = 0;
static volatile uint32_t pkt_received = 0;
static volatile uint32_t timestamp_received = 1;

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

int32_t app_test_send_receive(uint32_t startP, uint32_t endP, uint32_t displayResult);

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/


#define APP_TEST_PKT_SEND_COUNT  16
#define APP_TEST_MIN_PKT_SEND_SIZE 60
#define APP_TEST_MAX_PKT_SEND_SIZE 1500

/* DO NOT CHANGE app_test_uc_pkt UNLESS APP_TEST_PKT_SIZE IS UPDATED */
#define APP_TEST_PKT_SIZE       64
static uint8_t app_test_uc_pkt[APP_TEST_PKT_SIZE] = {
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x44,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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
static uint8_t app_test_bc_pkt[APP_TEST_PKT_SIZE] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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

static uint8_t app_test_mc_pkt[APP_TEST_PKT_SIZE] = {
    0x01, 0x93, 0x20, 0x21, 0x22, 0x2a,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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

static uint8_t mac1_mc[6] = {0x01, 0x93, 0x20, 0x21, 0x22, 0x22};
static uint8_t app_test_mc1_pkt[APP_TEST_PKT_SIZE] = {
    0x01, 0x93, 0x20, 0x21, 0x22, 0x22,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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


static uint8_t mac2_mc[6] = {0x01, 0x93, 0x20, 0x21, 0x22, 0x24};
static uint8_t mac3_mc[6] = {0x01, 0x93, 0x20, 0x21, 0x22, 0x26};
static uint8_t mac4_mc[6] = {0x01, 0x93, 0x20, 0x21, 0x22, 0x28};


static uint8_t app_test_mc2_pkt[APP_TEST_PKT_SIZE] = {
    0x01, 0x93, 0x20, 0x21, 0x22, 0x24,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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

static uint8_t app_test_mc3_pkt[APP_TEST_PKT_SIZE] = {
    0x01, 0x93, 0x20, 0x21, 0x22, 0x26,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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

static uint8_t app_test_mc4_pkt[APP_TEST_PKT_SIZE] = {
    0x01, 0x93, 0x20, 0x21, 0x22, 0x28,
    0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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

uint8_t app_test_128_pkt[128] = {
        0x48, 0x93, 0xfe, 0xfa, 0x18, 0x44,
        0x48, 0x93, 0xfe, 0xfa, 0x18, 0x4a,
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
        0xfe,0xfe, 0x00, 0x00,
        0x48, 0x93, 0xfe, 0xfa,
        0x18, 0x44, 0x18, 0x4a,
        0x48, 0x93, 0xfe, 0xfa,
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

static uint8_t *pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);

/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/

/*
 *  ======== app_detect_interposer_card ========
 */
bool app_detect_interposer_card(void)
{
#ifdef am65xx_idk
    EMAC_socGetInitCfg(0, &emac_cfg);
    CSL_MdioRegs *pBaseAddr = (CSL_MdioRegs*) (uintptr_t)(emac_cfg.portCfg[2].mdioRegsBaseAddr);
#ifdef EMAC_TEST_APP_WITHOUT_DDR
    Task_sleep(5000);
#endif
    if ((CSL_MDIO_isPhyAlive(pBaseAddr,emac_cfg.portCfg[2].phyAddr)) ||(CSL_MDIO_isPhyAlive(pBaseAddr,emac_cfg.portCfg[3].phyAddr)))
    {
        UART_printf("PHYs for ICSSG1 are ALIVE, interposer card is NOT present\n");
        return FALSE;
    }
    else
    {
        UART_printf("PHYs for ICSSG1 are not ALIVE, interposer card is present\n");
        return TRUE;
    }
#else
    return FALSE;
#endif
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

uint32_t allocCount = 0;
uint32_t allocFailed = 0;
uint32_t gAppAllocFailure = 0;

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
    uint32_t              port_num,
    uint32_t              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;
    if (pkt_size <= APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
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
    return p_pkt_desc;
}
#else
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
    uint32_t              port_num,
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
    uint32_t            i, j;
    EMAC_PKT_DESC_T*    p_pkt_desc;
    uint8_t*            pktbuf_ptr;

    UART_printf ("EMAC loopback test application initialization\n");

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (APP_EMAC_MCB_T));

#ifdef _TMS320C6X
    app_mcb.core_num = CSL_chipReadReg (CSL_CHIP_DNUM);
#else
    app_mcb.core_num = 0;
#endif
    pktbuf_ptr = (uint8_t *) ((uintptr_t) app_pkt_buffer);
    /* Initialize the free packet queue */
    for (i=portNum; i <=endPort; i++)
    {
        if (!port_en[i])
            continue;
#ifndef EMAC_BENCHMARK
        for (j=0; j<APP_MAX_PKTS/MAX_NUM_EMAC_PORTS; j++)
#else
        for (j=0; j<(APP_MAX_PKTS); j++)
#endif
        {
            p_pkt_desc               = &app_mcb.emac_pcb[i].pkt_desc[j];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = APP_EMAC_MAX_PKT_SIZE;
            app_queue_push( i, &app_mcb.emac_pcb[i].freeQueue, p_pkt_desc );
            pktbuf_ptr += APP_EMAC_MAX_PKT_SIZE;
        }
    }
}

#if defined (EMAC_BENCHMARK)
uint32_t app_test_send_fail = 0;
uint32_t app_test_alloc_fail = 0;

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
        app_test_alloc_fail++;
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
            app_test_send_fail++;
            app_free_pkt(portNum,p_pkt_desc);
        }
    }
}
#endif


/******************************************************************************
 * Function: EMAC RX packet call back function
 ******************************************************************************/
/**
 *  @brief  This function is used to call back the network application when a
 *          packet is received.
 */
void app_test_rx_pkt_cb(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
#if !defined (EMAC_BENCHMARK)
    if (memcmp(p_desc->pDataBuffer, pTestPkt, APP_TEST_PKT_SIZE) == 0)
    {
        pkt_rcv_count++;
        if (port_num != EMAC_PORT_CPSW)
        {
            UART_printf("app_test_rx_pkt_cb: port %d: ring num: %d, received packet %d, rx timestamp:  0x%x%08x\n",
                                            port_num,
                                            p_desc->PktChannel,
                                            pkt_rcv_count,
                                            (unsigned int)(p_desc->RxTimeStamp >> 32),
                                            (unsigned int)(p_desc->RxTimeStamp & 0xFFFFFFFF));
        }
        else
        {
                    UART_printf("app_test_rx_pkt_cb: port %d: ring num: %d, received packet %d\n",port_num, p_desc->PktChannel, pkt_rcv_count);
        }
    }
    else
    {
        UART_printf("app_test_rx_pkt_cb: port %u: ring num %d: packet match failed\n", port_num, p_desc->PktChannel);
        while(1);
    }
    if (p_desc->AppPrivate != 0U)
    {
        app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
    }
    pkt_received = 1;
#else
    if (p_desc->AppPrivate != 0U)
    {
        if (port_num != EMAC_PORT_CPSW)
        app_test_loopback_pkt(app_test_send_port,p_desc);
        app_free_pkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
        pkt_received = 1;
    }
    pkt_rcv_count++;
#endif
}



/******************************************************************************
* Function: EMAC RX timestamp_response back function
******************************************************************************/
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
    timestamp_received = 1;

}
void app_test_task_poll_pkt (UArg arg0, UArg arg1)
{
    uint32_t port = (uint32_t) arg0;
    linkStatus = 1;
    while(initComplete == 0)
    {
        Task_sleep(1);
    }
    UART_printf("polling rx packets on port: %d\n", port);
    while(1)
    {
        if (pollModeEnabled == 0)
        {
            emac_poll_pkt(port);
#ifndef EMAC_BENCHMARK
            Task_sleep(5);
            if (pkt_rcv_count == APP_TEST_PKT_SEND_COUNT)
                break;
#endif
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
#ifdef EMAC_TEST_APP_ICSSG
    uint32_t mgmtRings =0x7;
    uint32_t pktRings =0x1ff;
    uint32_t txRings = 0xf;
#else
    uint32_t mgmtRings =0x0;
    uint32_t pktRings =0x1;
    uint32_t txRings = 0x0;
#endif
    linkStatus = 1;
    while(initComplete == 0)
    {
        Task_sleep(1);
    }

    UART_printf("polling all pkts on port: %d\n", port);
    while(1)
    {
        if (pollModeEnabled == 1)
            emac_poll_ctrl(port, pktRings,mgmtRings,txRings);
        else
            emac_poll_ctrl(port, 0,EMAC_POLL_RX_MGMT_RING2,txRings);
        Task_sleep(2);
    }
}

int32_t emac_send_fail = 0;


int32_t app_test_send(uint32_t pNum, uint8_t* pPkt, uint32_t pktChannel, uint32_t pktSize)
{
    uint32_t i;
    static uint32_t pkt_send_count =0;
    EMAC_DRV_ERR_E sentRetVal;

    gFail_count = 0;
    for (i = 0; i < APP_TEST_PKT_SEND_COUNT/2; i++)
    {

        EMAC_PKT_DESC_T *p_pkt_desc = app_alloc_pkt(pNum, pktSize);
        if (p_pkt_desc == NULL)
        {
            UART_printf("app_test_send: app alloc pkt failed\n");
            while(1);
        }
        memcpy (p_pkt_desc->pDataBuffer, pPkt, pktSize);
        p_pkt_desc->AppPrivate = (uintptr_t)p_pkt_desc;
        /* only enable TX timestamp when in poll mode of operation, currently not support for SWITCH use case */
        if (pollModeEnabled)
        {
            /* PG2.0 test firmware does not currently support TX TS */
            if ((pNum != EMAC_CPSW_PORT_NUM) && (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION))
            {
                p_pkt_desc->Flags = EMAC_PKT_FLAG_TX_TS_REQ;
                p_pkt_desc->TxtimestampId = pNum + i;
                timestamp_received = 0;
            }
        }
        p_pkt_desc->TxPktTc = i % 8;
        p_pkt_desc->ValidLen     = pktSize;
        p_pkt_desc->DataOffset   = 0;
        p_pkt_desc->PktLength    = pktSize;
        p_pkt_desc->PktFrags     = 1;
        p_pkt_desc->pNext = NULL;
        p_pkt_desc->pPrev = NULL;
        p_pkt_desc->PktChannel     = pktChannel;
        p_pkt_desc->PktLength      = pktSize;
        sentRetVal = emac_send(pNum, p_pkt_desc);
        if(sentRetVal != EMAC_DRV_RESULT_OK)
        {
            UART_printf("app_test_send: emac send on port failed with status: : %d: retVal %d, pkt_count: %d\n", pNum, sentRetVal, i+1);
            app_free_pkt(pNum,p_pkt_desc);
            emac_send_fail++;
        }
        
#if !defined(EMAC_BENCHMARK)

    while((pkt_received == 0) || (timestamp_received == 0))
    {
        Task_sleep(100);
    }
#endif

        pkt_received = 0;
        pkt_send_count++;
        
    }
    return gFail_count;
}

void app_test_pkt_clone(void)
{
    int32_t status;
    testPktClone = 1;
    app_test_id++;
    pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);
    UART_printf("EMAC_UT_%d begin: app_test_pkt_clone\n", app_test_id);
    status = app_test_send_receive(portNum, endPort,0);
    if(status == 0)
        UART_printf("EMAC_UT_%d begin: app_test_pkt_clone passed\n", app_test_id);
    testPktClone = 0;

}
void app_test_port_mac(void)
{
    int32_t status;
    Task_sleep(500);
    app_test_id++;
    pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);
    UART_printf("EMAC_UT_%d begin: sending UC packet with PORT_MAC\n", app_test_id);
    status = app_test_send_receive(portNum, endPort,0);
    if(status == 0)
        UART_printf("EMAC_UT_%d begin: sending UC packet with PORT_MAC passed\n", app_test_id);

    app_test_id++;
    pTestPkt = (uint8_t*)(&app_test_bc_pkt[0]);
    UART_printf("EMAC_UT_%d begin: sending BC packet\n", app_test_id);
    status = app_test_send_receive(portNum, endPort,0);
    if(status == 0)
        UART_printf("EMAC_UT_%d begin: sending BC packet passed\n", app_test_id);
}
void app_test_interrrupt_mode(void)
{
    app_test_id++;
    pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);
    UART_printf("EMAC_UT_%d begin test interrupt mode\n", app_test_id);
    app_test_send_receive(portNum, endPort,0);
    UART_printf("EMAC_UT_%d begin test interrupt mode passed\n", app_test_id);
}

void app_test_tx_chans(void)
{
    app_test_id++;
    uint32_t pNum;
    uint32_t txChannel;
    UART_printf("EMAC_UT_%d begin test_multiple tx chans mode\n", app_test_id);
    for (pNum = portNum; pNum  <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;

        if (1 == interposerCardPresent)
        {
            if((pNum == 0) || (pNum == 2) ||  (pNum == 6))
                 continue;
        }
        for (txChannel = 0; txChannel < 4;txChannel++)
        {
            app_test_send(pNum, pTestPkt, txChannel, APP_TEST_PKT_SIZE);
        }
    }

    UART_printf("EMAC_UT_%d end test_multiple tx chans mode\n", app_test_id);

}

void app_test_poll_mode(void)
{
    pollModeEnabled = 1;
    app_test_id++;
    pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);
    UART_printf("EMAC_UT_%d begin test poll mode\n", app_test_id);
    app_test_send_receive(portNum, endPort,0);
    UART_printf("EMAC_UT_%d begin test poll mode passed\n", app_test_id);
}

void app_test_multi_flows(void)
{
    uint32_t pNum;
    EMAC_IOCTL_PARAMS params;
    EMAC_MAC_ADDR_T macAddrs[4];

    memcpy (&macAddrs[0], &mac1_mc[0], sizeof(EMAC_MAC_ADDR_T));
    memcpy (&macAddrs[1], &mac2_mc[0], sizeof(EMAC_MAC_ADDR_T));
    memcpy (&macAddrs[2], &mac3_mc[0], sizeof(EMAC_MAC_ADDR_T));
    memcpy (&macAddrs[3], &mac4_mc[0], sizeof(EMAC_MAC_ADDR_T));

    params.ioctlVal = (void*)&macAddrs[0];

    for (pNum =portNum; pNum  <= endPort; pNum++)
    {
        if ((!port_en[pNum]) || (pNum == 6))
            continue;
        emac_ioctl(pNum,EMAC_IOCTL_TEST_MULTI_FLOW,(void*)(&params));
    }
    for (pNum =portNum; pNum  <= endPort; pNum++)
    {
        if (1 == interposerCardPresent)
        {
            if((pNum == 0) || (pNum == 2) ||  (pNum == 6))
                continue;
        }
        if (!port_en[pNum])
            continue;
        pTestPkt = (uint8_t*)(&app_test_mc1_pkt[0]);
        app_test_send(pNum, pTestPkt, 0,APP_TEST_PKT_SIZE);

        pTestPkt = (uint8_t*)(&app_test_mc2_pkt[0]);
        app_test_send(pNum, pTestPkt, 0, APP_TEST_PKT_SIZE);

        pTestPkt = (uint8_t*)(&app_test_mc3_pkt[0]);
        app_test_send(pNum, pTestPkt, 0,APP_TEST_PKT_SIZE);

        pTestPkt = (uint8_t*)(&app_test_mc4_pkt[0]);
        app_test_send(pNum, pTestPkt, 0,APP_TEST_PKT_SIZE);
    }

}

int32_t app_test_send_receive(uint32_t startP, uint32_t endP, uint32_t displayResult)
{
    uint32_t pNum;
    int32_t status = 0;
    for (pNum = startP; pNum  <= endP; pNum++)
    {
        if (!port_en[pNum])
            continue;

        if (1 == interposerCardPresent)
        {
            if((pNum == 0) || (pNum == 2))
                 continue;
        }
        UART_printf("app_test_send_receive: testing port: %d\n", pNum);
        status = app_test_send(pNum, pTestPkt, 0,APP_TEST_PKT_SIZE);

        if ((pNum == endPort) && (displayResult == 1))
        {
            UART_printf("All tests have passed\n");
        }
    }
    return status;
}

#ifdef EMAC_TEST_APP_ICSSG
#define TX_BUFF_POOL_SIZE 0X1800u
#define TX_BUFF_POOL_TOTAL_DUAL_MAC (TX_BUFF_POOL_SIZE + 0x80) * 8U /* //50176 per PORT, total of 100352 */
void app_test_setup_fw_dualmac(uint32_t port_num, EMAC_HwAttrs_V5 *pEmacCfg)
{
    EMAC_FW_APP_CONFIG *pFwAppCfg;
    emacGetDualMacFwAppInitCfg(port_num, &pFwAppCfg);
    if ((port_num % 2) == 0)
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uintptr_t) &icss_tx_port_queue[port_num >> 1][0]);
    }
    else
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uintptr_t) &icss_tx_port_queue[port_num >> 1][TX_BUFF_POOL_TOTAL_DUAL_MAC]);
    }

    pFwAppCfg->txPortQueueHighAddr = 0;

    emacSetDualMacFwAppInitCfg(port_num, pFwAppCfg);

    /* Need to update the emac configuraiton with  function required by the driver to get the FW configuration to write to shared mem */
    pEmacCfg->portCfg[port_num].getFwCfg = &emacGetDualMacFwConfig;

}
#endif

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

int32_t app_test_emac_open(uint32_t mode)
{
    EMAC_socGetInitCfg(0, &emac_cfg);
    int32_t chanNum = 0;
    int32_t subChanNum = 0;
    uint32_t pNum;
    EMAC_MAC_ADDR_T macTest;
    app_test_id++;
    UART_printf("EMAC_UT_%d begin, test emac open\n", app_test_id);

#ifdef EMAC_TEST_APP_ICSSG
    for (pNum = portNum; pNum <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;
        app_test_task_disable_pruicss(pNum);
    }
#endif

    for (pNum = portNum; pNum <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;
#if defined(EMAC_TEST_APP_WITHOUT_DDR) || defined(EMAC_BENCHMARK)
    emac_cfg.portCfg[pNum].nTxChans = 1U;
    emac_cfg.portCfg[pNum].rxChannel.nsubChan = 1U;
    emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.nsubChan = EMAC_TEST_MAX_SUB_RX_CHANS_PER_PORT;
    emac_cfg.portCfg[pNum].rxChannel2CfgOverPSI.nsubChan = 0;
#endif
        for (chanNum = 0; chanNum < emac_cfg.portCfg[pNum].nTxChans; chanNum++)
        {
            emac_cfg.portCfg[pNum].txChannel[chanNum].chHandle = (void *)&gUdmaTxChObj[pNum][chanNum];
            emac_cfg.portCfg[pNum].txChannel[chanNum].freeRingMem= (void*)&gTxRingMem[pNum][chanNum][0];
            emac_cfg.portCfg[pNum].txChannel[chanNum].compRingMem= (void*)&gTxCompRingMem[pNum][chanNum][0];
            emac_cfg.portCfg[pNum].txChannel[chanNum].hPdMem = (void*)&gUdmapDescRamTx[pNum][chanNum][0];
        }
        emac_cfg.portCfg[pNum].rxChannel.chHandle = (void *)&gUdmaRxChObj[pNum];
        emac_cfg.portCfg[pNum].rxChannel.flowHandle= (void *)&gUdmaFlowHnd[pNum];
        /* each subChan is a flow which is required 1 ring pair, subChanNum 0 is used for default flow*/
        for (subChanNum = 0; subChanNum < emac_cfg.portCfg[pNum].rxChannel.nsubChan; subChanNum++)
        {
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMem[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxRingHnd[pNum][subChanNum];
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMem[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxCompRingHnd[pNum][subChanNum];
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRx[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannel.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCqEventObj[pNum][subChanNum];
        }

        emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.chHandle = (void *)&gUdmaRxMgmtPsiChObj[pNum];
        emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.flowHandle= (void *)&gUdmaFlowHndCfgPsi[pNum];
        for (subChanNum = 0; subChanNum < emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.nsubChan; subChanNum++)
        {
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMemCfgPsi[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxRingHndCfgPsi[pNum][subChanNum];
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMemCfgPsi[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxCompRingHndCfgPsi[pNum][subChanNum];
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRxMgmtPsi[pNum][subChanNum][0];
            emac_cfg.portCfg[pNum].rxChannelCfgOverPSI.subChan[subChanNum].eventHandle = (void *)&gUdmaRxMgmtPsiCqEventObj[pNum][subChanNum];
        }
    }

    for (pNum = portNum; pNum <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;
        if (pNum != EMAC_PORT_CPSW)
        {

#ifdef EMAC_TEST_APP_ICSSG
            app_test_setup_fw_dualmac(pNum, &emac_cfg);
#endif
        }
        EMAC_socSetInitCfg(0, &emac_cfg);
        EMAC_socGetInitCfg(0, &emac_cfg);

        open_cfg.hwAttrs = (void*)&emac_cfg;
        open_cfg.alloc_pkt_cb = app_alloc_pkt;
        open_cfg.free_pkt_cb = app_free_pkt;
        open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;
        open_cfg.tx_ts_cb = app_test_ts_response_cb;
        open_cfg.loop_back = 0U;
        /* Only need to enbale loopback for CPSW test application and when not doing benchmark testing */
#ifndef EMAC_BENCHMARK
        if (pNum == EMAC_PORT_CPSW)
        {
            open_cfg.loop_back = 1U;
        }
        open_cfg.num_of_rx_pkt_desc = 8U;
        open_cfg.num_of_tx_pkt_desc = 8U;
#else
        open_cfg.num_of_rx_pkt_desc = 128U;
        open_cfg.num_of_tx_pkt_desc = 128U;
#endif
        open_cfg.master_core_flag = 1;
        open_cfg.max_pkt_size = APP_EMAC_MAX_PKT_SIZE;
        open_cfg.mdio_flag = 1;
        open_cfg.num_of_chans = 1;
        open_cfg.udmaHandle = (void*)gDrvHandle;

        macTest.addr[0] = 0x48;
        macTest.addr[1] = 0x93;
        macTest.addr[2] = 0xfe;
        macTest.addr[3] = 0xfa;
        macTest.addr[4] = 0x18;
        macTest.addr[5] = 0x44;

        open_cfg.p_chan_mac_addr = &chan_cfg[0];
        /* Set the channel configuration */
        chan_cfg[0].chan_num = 0;
        chan_cfg[0].num_of_mac_addrs = 1;
        chan_cfg[0].p_mac_addr = & macTest;
        open_cfg.mode_of_operation = mode;

        if (emac_open(pNum, &open_cfg) == EMAC_DRV_RESULT_OK)
        {
            UART_printf("main: emac_open sucess for port %d\n", pNum);
#ifdef EMAC_TEST_APP_ICSSG
            app_test_task_init_pruicss(pNum);
#endif
        }
        else
        {
            UART_printf("main: emac_open failure for port: %d\n",pNum);
            return -1;
        }

    }
    UART_printf("EMAC_UT_%d end, test emac open passed\n", app_test_id);

    return 0;
}

int32_t  app_test_emac_close(void)
{
    app_test_id++;
    UART_printf("EMAC_UT_%d begin, test emac close\n", app_test_id);

    uint32_t pNum;
    for (pNum = portNum; pNum  <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;
        if (emac_close(pNum) == EMAC_DRV_RESULT_OK)
        {
            UART_printf("app_test_emac_close: emac close for port %d success\n", pNum);
        }
        else
        {
            UART_printf("app_test_emac_close: emac close for port %d failed\n", pNum);
            return -1;
        }
    }
    UART_printf("EMAC_UT_%d end, test emac close\n", app_test_id);
    return 0;

}

void app_test_config_promiscous_mode(uint32_t enable)
{
    uint32_t pNum;
    uint32_t promisEnableFlag = 0;
    EMAC_IOCTL_PARAMS params;

    if (enable == 1)
        promisEnableFlag = 1;
    params.ioctlVal = (void*)(&promisEnableFlag);

    for (pNum =portNum; pNum  <= endPort; pNum++)
    {
        if ((!port_en[pNum]) || (pNum == 6))
            continue;
        emac_ioctl(pNum,EMAC_IOCTL_PROMISCOUS_MODE_CTRL,(void*)(&params));
    }

}

void  app_test_promiscous_mode(void)
{
    app_test_id++;
    UART_printf("EMAC_UT_%d begin test promiscous mode\n", app_test_id);

    pTestPkt = (uint8_t*)(&app_test_mc_pkt[0]);
    app_test_send_receive(portNum, endPort, 0);
    UART_printf("app_test_promiscous_mode with MC pkt success\n");
    pTestPkt = (uint8_t*)(&app_test_bc_pkt[0]);
    app_test_send_receive(portNum, endPort, 0);
    UART_printf("app_test_promiscous_mode with BC pkt success\n");

    pTestPkt = (uint8_t*)(&app_test_uc_pkt[0]);
    app_test_send_receive(portNum, endPort, 0);
    UART_printf("app_test_promiscous_mode with UC  pkt success\n");

    UART_printf("EMAC_UT_%d test poll promiscous passed\n", app_test_id);
}

void emac_test_get_icssg_stats(void)
{
    uint32_t pNum;
    EMAC_STATISTICS_ICSSG_T stats;
    app_test_id++;

    UART_printf("EMAC_UT_%d begin collecting icssg stats\n", app_test_id);
    for (pNum = portNum; pNum  <= endPort; pNum++)
    {
        if (!port_en[pNum])
            continue;
        memset(&stats, 0, sizeof(EMAC_STATISTICS_ICSSG_T));
        if (emac_get_statistics_icssg(pNum, &stats, 0) == EMAC_DRV_RESULT_OK)
        {
            UART_printf("port:%d: rx packets:          %d, tx packets:        %d\n", pNum, stats.RxGoodFrames, stats.TXGoodFrame);
        }
        else
        {
            UART_printf("emac_test_get_icssg_stats: emac_get_statistics_icssg for port %d failed\n", pNum);
            while(1);
        }
    }
    UART_printf("EMAC_UT_%d  collecting icssg stats passed\n", app_test_id);
}

void emac_test_get_cpsw_stats(void)
{
    EMAC_STATISTICS_T stats;
    memset(&stats, 0, sizeof(EMAC_STATISTICS_T));
    if (!port_en[EMAC_PORT_CPSW])
        return;
    app_test_id++;

    UART_printf("EMAC_UT_%d begin collecting cpsw stats\n", app_test_id);
    if (emac_get_statistics(endPort, &stats) == EMAC_DRV_RESULT_OK)
    {
        UART_printf("port: %d: rx packets: %d, tx packets: %d\n", endPort, stats.RxGoodFrames, stats.TxGoodFrames);
    }
    else
    {
        UART_printf("emac_test_get_cpsw_stats: emac_get_statistics for port %d failed\n", endPort);
        while(1);
    }
    UART_printf("EMAC_UT_%d  collecting cpsw stats passed\n", app_test_id);
}


void app_test_udma_init(void)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

#if defined (SOC_AM65XX)
#if defined (EMAC_TEST_APP_CPSW)
    /* if A53 and pg 1.0 use mcu navss due to hw errata*/
#if defined (BUILD_MPU1_0)
    if (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION)
    {
        instId = UDMA_INST_ID_MCU_0;
    }
    else
    {
        instId = UDMA_INST_ID_MAIN_0;
    }
#else
    instId = UDMA_INST_ID_MCU_0;
#endif
#else
    /* icssg use case */
    instId = UDMA_INST_ID_MAIN_0;
#endif
#endif

#if defined (SOC_J721E)
#if defined (EMAC_TEST_APP_CPSW)
#if defined (BUILD_MPU1_0)
    instId = UDMA_INST_ID_MAIN_0;
#else
    instId = UDMA_INST_ID_MCU_0;
#endif
#else
    /* icssg use case */
    instId = UDMA_INST_ID_MAIN_0;
#endif
#endif

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

void app_test_check_port_link(uint32_t startP, uint32_t endP)
{
    uint32_t pNum;
    EMAC_LINK_INFO_T linkInfo;

    for (pNum = startP; pNum  <= endP; pNum++)
    {
        if (!port_en[pNum])
            continue;
        if (1 == interposerCardPresent)
        {
            if((pNum == 2) || (pNum == 3))
                continue;
        }
        memset(&linkInfo, 0, sizeof(EMAC_LINK_INFO_T));
        do
        {
            emac_poll(pNum, &linkInfo);
            Osal_delay(100);
            UART_printf("Link for port %d is DOWN\n", pNum);
        } while(linkInfo.link_status == EMAC_LINKSTATUS_NOLINK);
        UART_printf("Link for port %d is now UP\n", pNum);
    }

}

#ifdef EMAC_BENCHMARK
void app_test_task_benchmark(UArg arg0, UArg arg1)
{
    Board_STATUS boardInitStatus =0;
#ifdef EMAC_TEST_APP_ICSSG
    PRUICSS_Config *prussCfg;
#endif

#ifdef EMAC_TEST_APP_WITHOUT_DDR
    Task_sleep(5000);
#endif
    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK  | BOARD_INIT_ICSS_ETH_PHY | BOARD_INIT_ETH_PHY;

    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=BOARD_SOK)
    {
        UART_printf("Board_init failure\n");
        while(1);
    }
    UART_printf("Board_init success benchmark\n");
#if defined(SOC_J721E)
#else
    if (app_detect_interposer_card() == TRUE)
    {
        UART_printf("Interposer card is  present\n");
        interposerCardPresent = 1;
    }
#endif
    else
    {
        UART_printf("Interposer card is NOT present\n");
    }

    app_init();
#ifdef EMAC_TEST_APP_ICSSG
    PRUICSS_socGetInitCfg(&prussCfg);
    prussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
    prussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);
#if defined(SOC_AM65XX)
    prussHandle[2] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_THREE);
#endif
#endif

    app_test_udma_init();

    if (app_test_emac_open(EMAC_MODE_POLL) != 0)
    {
        while(1);
    }
    app_test_check_port_link(portNum, endPort);
    app_test_config_promiscous_mode(1);

    initComplete = 1;

    UART_printf("app_test_task_benchmark: getting stats\n");
    while (1)
    {
        Task_sleep(1000*60);
        emac_test_get_icssg_stats();
    }
}
#endif


#ifdef EMAC_TEST_APP_ICSSG
void test_EMAC_verify_ut_dual_mac_icssg(void)
{
    /* @description:Unit test for ICSSG dual mac use case

       @requirements: PRSDK-3771, PRSDK-3767, PRSDK-3768, PRSDK-3774, PRSDK-3776,
                      PRSDK-3780, PRSDK-3782, PRSDK-3813, PRSDK-3815, PRSDK-4029,
                      PRSDK-7156

       @cores: mpu1_0, mcu1_0 */
    Board_STATUS boardInitStatus =0;
#ifdef EMAC_TEST_APP_ICSSG
    PRUICSS_Config *prussCfg;
#endif

#ifdef EMAC_TEST_APP_WITHOUT_DDR
        Task_sleep(2000);
#endif
    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY | BOARD_INIT_ETH_PHY;

#if defined(SOC_J721E)
    /* PINMUX config of GESI for ICSSG */
    Board_PinmuxConfig_t gesiIcssgPinmux;
    Board_pinmuxGetCfg(&gesiIcssgPinmux);
    gesiIcssgPinmux.autoCfg = BOARD_PINMUX_CUSTOM;
    gesiIcssgPinmux.gesiExp = BOARD_PINMUX_GESI_ICSSG;
    Board_pinmuxSetCfg(&gesiIcssgPinmux);
#endif
        boardInitStatus = Board_init(cfg);
        if (boardInitStatus !=BOARD_SOK)
        {
            UART_printf("Board_init failure\n");
            while(1);
        }
        UART_printf("Board_init success for UT\n");

    gPgVersion = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_JTAGID);

#if defined(SOC_J721E)
#else
        if (app_detect_interposer_card() == TRUE)
        {
            UART_printf("Interposer card is  present\n");
            interposerCardPresent = 1;
        }
        else
#endif
        {
            UART_printf("Interposer card is NOT present\n");
        }

        app_init();
#ifdef EMAC_TEST_APP_ICSSG
        PRUICSS_socGetInitCfg(&prussCfg);
        prussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
        prussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);
#if defined(SOC_AM65XX)
        prussHandle[2] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_THREE);
#endif
#endif

    app_test_udma_init();

    if (app_test_emac_open(EMAC_MODE_INTERRUPT) != 0)
    {
        while(1);
    }
    initComplete = 1;
   
    /* Need to poll for link for ICSSG ports as they are port 2 port tests */
    /* For standalone CPSW test, we use internal loopback at CPSW-SS */
    app_test_check_port_link(portNum, endPort);

    /* Test with PORT_MAC address */
    app_test_port_mac();

#ifndef BUILD_MCU1_0
    app_test_tx_chans();
#endif
    app_test_interrrupt_mode();

    if (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION)
    {
        /* test close -re open sequence */
        if(app_test_emac_close() == -1)
        {
            UART_printf("emac unit test app_test_emac_close failed\n");
            while(1);
        }
        /* re-init the app */
        app_init();

        /* re-open in polling mode */
        if (app_test_emac_open(EMAC_MODE_POLL) != 0)
        {
            while(1);
        }

        app_test_poll_mode();
#ifndef BUILD_MCU1_0
            app_test_multi_flows();
#endif
        app_test_config_promiscous_mode(1);
        app_test_promiscous_mode();
        emac_test_get_icssg_stats();
    }
    else
    {
        emac_test_get_icssg_stats();
        /* test close -re open sequence */
        if(app_test_emac_close() == -1)
        {
            UART_printf("emac unit test app_test_emac_close failed\n");
            while(1);
        }
    }
    UART_printf("All tests have passed\n");
#ifdef UNITY_INCLUDE_CONFIG_H
    TEST_PASS();
#endif
}

#else
void test_EMAC_verify_ut_cpsw(void)
{
    /* @description:Unit test for ICSSG dual mac and CPSW use cases

       @requirements: PRSDK-3485, PRSDK-3486, PRSDK-3487, PRSDK-3509,
                      PRSDK-3726, PRSDK-3755, PRSDK-3765, PRSDK-5567

       @cores: mpu1_0, mcu1_0 */

    Board_STATUS boardInitStatus =0;
#ifdef EMAC_TEST_APP_WITHOUT_DDR
        Task_sleep(2000);
#endif
        Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ETH_PHY | BOARD_INIT_ENETCTRL_CPSW2G;

    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=BOARD_SOK)
    {
        UART_printf("Board_init failure\n");
        while(1);
    }
    UART_printf("Board_init success for UT\n");


    app_init();

    app_test_udma_init();

    if (app_test_emac_open(EMAC_MODE_INTERRUPT) != 0)
    {
        while(1);
    }
    initComplete = 1;

    /* Test with PORT_MAC address */
    app_test_port_mac();

    app_test_interrrupt_mode();

    /* test close -re open sequence */
    if(app_test_emac_close() == -1)
    {
        UART_printf("emac unit test app_test_emac_close failed\n");
        while(1);
    }
    /* re-init the app */
    app_init();

    /* re-open in polling mode */
    if (app_test_emac_open(EMAC_MODE_POLL) != 0)
    {
        while(1);
    }

    app_test_poll_mode();

    app_test_config_promiscous_mode(1);
    app_test_promiscous_mode();

    emac_test_get_cpsw_stats();

    UART_printf("All tests have passed\n");
#ifdef UNITY_INCLUDE_CONFIG_H
    TEST_PASS();
#endif
}

#endif

#ifdef UNITY_INCLUDE_CONFIG_H
#ifdef EMAC_TEST_APP_ICSSG
void test_Emac_Icssg_TestApp_runner(void)
{
    /* @description: Test runner for EMAC ICSSG tests

       @requirements: PRSDK-3771, PRSDK-3767, PRSDK-3768, PRSDK-3774, PRSDK-3776,
                      PRSDK-3780, PRSDK-3782, PRSDK-3813, PRSDK-3815, PRSDK-4029

       @cores: mpu1_0, mcu1_0 */

    UNITY_BEGIN();
    RUN_TEST(test_EMAC_verify_ut_dual_mac_icssg);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
}

#else
void test_Emac_Cpsw_TestApp_runner(void)
{
    /* @description: Test runner for EMAC CPSW tests

       @requirements: PRSDK-3485, PRSDK-3486, PRSDK-3487, PRSDK-3509,
                      PRSDK-3726, PRSDK-3755, PRSDK-3765, PRSDK-5567

       @cores: mpu1_0, mcu1_0 */

    UNITY_BEGIN();
    RUN_TEST(test_EMAC_verify_ut_cpsw);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
}
#endif
#endif

void app_test_task_verify_ut_dual_mac_cpsw(UArg arg0, UArg arg1)
{
#ifdef UNITY_INCLUDE_CONFIG_H
#ifdef EMAC_TEST_APP_ICSSG
    test_Emac_Icssg_TestApp_runner();
#else
    test_Emac_Cpsw_TestApp_runner();
#endif
#endif
}

#ifdef EMAC_TEST_APP_ICSSG
/*
 *  ======== app_test_task_init_pruicss========
 */
int32_t  app_test_task_disable_pruicss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t pru_n, rtu_n, txpru_n, slice_n;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;

    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;
    txpru_n = (slice_n) ? PRUICCSS_TPRU1 : PRUICCSS_TPRU0;

    if (PRUICSS_pruDisable(prussDrvHandle, pru_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_PRU%d failed\n", slice_n);

    if (PRUICSS_pruDisable(prussDrvHandle, rtu_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_RTU%d failed\n", slice_n);

    /* pg version check: only disable txpru if NOT version PG1.0 */
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruDisable(prussDrvHandle, txpru_n) != 0)
            UART_printf("PRUICSS_pruDisable for PRUICCSS_RTU%d failed\n", slice_n);
    }

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
    uint8_t pru_n, rtu_n, txpru_n, slice_n;
    app_test_pru_rtu_fw_t *firmware;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;
    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;
    txpru_n = (slice_n) ? PRUICCSS_TPRU1 : PRUICCSS_TPRU0;

    firmware = (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION)?firmware_pg1:firmware_pg2;

    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_PRU(slice_n), 0,
                               firmware[slice_n].pru, firmware[slice_n].pru_size) == 0)
    {
         UART_printf("PRUICSS_pruWriteMemory for PRUICCSS_PRU%d failed\n", slice_n);
         return -1;
    }
    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_RTU(slice_n), 0,
                                   firmware[slice_n].rtu, firmware[slice_n].rtu_size) == 0)
    {
        UART_printf("PRUICSS_pruWriteMemory for PRUICCSS_RTU%d failed\n", slice_n);
        return -1;
    }
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_TXPRU(slice_n), 0,
                               firmware[slice_n].txpru, firmware[slice_n].txpru_size) == 0)
        {
            UART_printf("PRUICSS_pruWriteMemory for PRUICCSS_TXPRU%d failed\n", slice_n);
            return -1;
        }
    }
    if (PRUICSS_pruEnable(prussDrvHandle, pru_n) != 0)
    {
        UART_printf("PRUICSS_pruEnable for PRUICCSS_PRU%d failed\n", slice_n);
        return -1;
    }
    if (PRUICSS_pruEnable(prussDrvHandle, rtu_n) != 0)
    {
        UART_printf("PRUICSS_pruEnable for PRUICCSS_RTU%d failed\n", slice_n);
        return -1;
    }
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruEnable(prussDrvHandle, txpru_n) != 0)
        {
            UART_printf("PRUICSS_pruEnable for PRUICCSS_TXPRU%d failed\n", slice_n);
            return -1;
        }
    }

    return 0;
}
#endif

void app_output_log(Char* str, UInt numChar)
{
    if (numChar > 0)
    {
        UART_printf(str);
    }
}

