/**
 * @file   main_j7.c
 *
 * @brief  NDK/NIMU example for J721E
 */
/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <stdio.h>
#include <string.h>


/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/family/arm/v8a/Mmu.h>
#include <ti/sysbios/utils/Load.h>
#include <ti/sysbios/knl/Semaphore.h>

/* CSL Header files */
#include <ti/csl/soc.h>

/* NDK headers */
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/stkmain.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* BOARD Header files */
#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* UDMA Header files */
#include <ti/drv/udma/udma.h>

/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>
#include <ti/transport/ndk/nimu/src/v7/nimu_eth.h>

/* Called by nimu driver at time of nimu_start to get udma handle */

/* Semaphore to sync NDK stack init to start after NIMU application init complete */
static Semaphore_Handle gSyncSemHandle;

/* SOC  configuration structure */
EMAC_HwAttrs_V5 emac_cfg;

/* Udma driver handle and object */
Udma_DrvHandle gUdmaDrvHandle = NULL;
struct Udma_DrvObj gUdmaDrvObj;

#ifdef NIMU_FTP_APP
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>
#endif

#ifdef NIMU_APP_ICSSG
#include <ti/drv/emac/firmware/icss_dualmac/config/emac_fw_config_dual_mac.h>
/* PRUSS Driver Header File. */
#include <ti/drv/pruss/soc/pruicss_v1.h>

/* TX port queue memory for 3 icss-g instances */
uint8_t icss_tx_port_queue[1][100352] __attribute__ ((aligned (UDMA_CACHELINE_ALIGNMENT))) __attribute__ ((section (".bss:nimu_ocmc_mem")));
#define TX_BUFF_POOL_SIZE 0X1800u
#define TX_BUFF_POOL_TOTAL_DUAL_MAC (TX_BUFF_POOL_SIZE + 0x80) * 8U //50176 per PORT, total of 100352
#endif


#define NIMU_MAX_TABLE_ENTRIES   9U
#define NIMU_NUM_PORTS 1U
#define NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT 1U
#define NIMU_TEST_MAX_CHANS_PER_PORT 1U

/* brief Number of ring entries - we can prime this much memcpy operations */
#define NIMU_TEST_APP_RING_ENTRIES      (128U)
/* Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define NIMU_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
 /* Total ring memory */
#define NIMU_TEST_APP_RING_MEM_SIZE     (NIMU_TEST_APP_RING_ENTRIES * \
                                          NIMU_TEST_APP_RING_ENTRY_SIZE)

/* UDMA host mode buffer descriptor memory size.    *  Make it multiple of 128 byte alignment */
#define NIMU_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (128U - sizeof(CSL_UdmapCppi5HMPD)))


/* UDMA driver objects
 */
struct Udma_ChObj       gUdmaTxChObj[NIMU_NUM_PORTS][NIMU_TEST_MAX_CHANS_PER_PORT];
struct Udma_ChObj       gUdmaRxChObj[NIMU_NUM_PORTS];
struct Udma_EventObj    gUdmaRxCqEventObj[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT];
struct Udma_ChObj       gUdmaRxCfgPsiChObj[NIMU_NUM_PORTS];
struct Udma_EventObj    gUdmaRxCfgPsiCqEventObj[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT];

struct Udma_FlowObj gUdmaFlowHnd[NIMU_NUM_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxRingHnd[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxCompRingHnd[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxRingHndCfgPsi[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_RingObj gUdmaRxCompRingHndCfgPsi[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
struct Udma_FlowObj gUdmaFlowHndCfgPsi[NIMU_NUM_PORTS] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmapDescRamTx[NIMU_NUM_PORTS][NIMU_TEST_MAX_CHANS_PER_PORT][NIMU_TEST_APP_RING_ENTRIES * NIMU_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gUdmapDescRamRx[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_ENTRIES * NIMU_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gUdmapDescRamRxCfgPsi[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_ENTRIES * NIMU_TEST_APP_DESC_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
/*
 * UDMA Memories
 */
static uint8_t gTxRingMem[NIMU_NUM_PORTS][NIMU_TEST_MAX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gTxCompRingMem[NIMU_NUM_PORTS][NIMU_TEST_MAX_CHANS_PER_PORT][NIMU_TEST_MAX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gRxRingMem[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gRxCompRingMem[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gRxRingMemCfgPsi[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));
static uint8_t gRxCompRingMemCfgPsi[NIMU_NUM_PORTS][NIMU_TEST_MAX_SUB_RX_CHANS_PER_PORT][NIMU_TEST_APP_RING_MEM_SIZE] __attribute__ ((aligned(UDMA_CACHELINE_ALIGNMENT)))
    __attribute__ ((section (".bss:nimu_ddr_mem")));

#define NIMU_EMAC_PORT_ICSS 0U
#define NIMU_EMAC_PORT_CPSW 6U

#ifdef NIMU_APP_CPSW
uint32_t portNum = NIMU_EMAC_PORT_CPSW;
#else
/* ICSSG case */
uint32_t portNum = NIMU_EMAC_PORT_ICSS;
#endif

Task_Handle main_task;

NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[NIMU_NUM_EMAC_PORTS];
extern int32_t (*NimuEmacInitFxn[NIMU_NUM_EMAC_PORTS])(STKEVENT_Handle hEvent);

extern char *LocalIPAddr;

void TaskFxn(UArg a0, UArg a1);

/* get handle to UDMA driver */
Udma_DrvHandle nimu_app_get_udma_handle(void)
{
    return gUdmaDrvHandle;
}

#ifdef NIMU_APP_ICSSG
void app_test_setup_fw_dualmac(uint32_t port_num, EMAC_HwAttrs_V5 *pEmacCfg)
{
    EMAC_FW_APP_CONFIG *pFwAppCfg;
    emacGetDualMacFwAppInitCfg(port_num, &pFwAppCfg);
    if ((port_num % 2) == 0)
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uintptr_t) &icss_tx_port_queue[0][0]);
    }
    else
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uintptr_t) &icss_tx_port_queue[0][TX_BUFF_POOL_TOTAL_DUAL_MAC]);
    }

    pFwAppCfg->txPortQueueHighAddr = 0;

    emacSetDualMacFwAppInitCfg(port_num, pFwAppCfg);

    /* Need to update the emac configuraiton with  function required by the driver to get the FW configuration to write to shared mem */
    pEmacCfg->portCfg[port_num].getFwCfg = &emacGetDualMacFwConfig;
}
#endif

/*
 *  ======== app_test_init_emac_k3========
 */
void app_test_init_emac_k3(uint32_t portNum, uint32_t index)
{
    EMAC_socGetInitCfg(0, &emac_cfg);
    int32_t chanNum = 0;
    int32_t subChanNum = 0;

    /* For ICSSG SOC config is or max channel/sub-channel config, only require 1 TX/RX channel and 1 RX sub-channel/flow for NIMU ICSSG example*/
    if (portNum != NIMU_EMAC_PORT_CPSW)
    {
        emac_cfg.portCfg[portNum].nTxChans = 1;
        emac_cfg.portCfg[portNum].rxChannel.nsubChan = 1;
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.nsubChan = 1;
    }
    for (chanNum = 0; chanNum < emac_cfg.portCfg[portNum].nTxChans; chanNum++)
    {
        emac_cfg.portCfg[portNum].txChannel[chanNum].chHandle = (void *)&gUdmaTxChObj[index][chanNum];
        emac_cfg.portCfg[portNum].txChannel[chanNum].freeRingMem= (void*)&gTxRingMem[index][chanNum][0];
        emac_cfg.portCfg[portNum].txChannel[chanNum].compRingMem= (void*)&gTxCompRingMem[index][chanNum][0];
        emac_cfg.portCfg[portNum].txChannel[chanNum].hPdMem = (void*)&gUdmapDescRamTx[index][chanNum][0];
    }
    emac_cfg.portCfg[portNum].rxChannel.chHandle = (void *)&gUdmaRxChObj[index];
    emac_cfg.portCfg[portNum].rxChannel.flowHandle= (void *)&gUdmaFlowHnd[index];

    for (subChanNum = 0; subChanNum < emac_cfg.portCfg[portNum].rxChannel.nsubChan; subChanNum++)
    {
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMem[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxRingHnd[index][subChanNum];
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMem[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxCompRingHnd[index][subChanNum];
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRx[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCqEventObj[index][subChanNum];
    }
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.chHandle = (void *)&gUdmaRxCfgPsiChObj[index];
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.flowHandle= (void *)&gUdmaFlowHndCfgPsi[index];

    for (subChanNum = 0; subChanNum < emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.nsubChan; subChanNum++)
    {
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMemCfgPsi[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].freeRingHandle[0] = (void*)&gUdmaRxRingHndCfgPsi[index][subChanNum];
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMemCfgPsi[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].compRingHandle= (void*)&gUdmaRxCompRingHndCfgPsi[index][subChanNum];
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRxCfgPsi[index][subChanNum][0];
        emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCfgPsiCqEventObj[index][subChanNum];
    }

#ifdef NIMU_APP_ICSSG
    app_test_setup_fw_dualmac(portNum, &emac_cfg);
#endif

    EMAC_socSetInitCfg(0, &emac_cfg);
}

/**
 *  \name NIMUStartUpTask
 *  \brief NIMU Startup Task
 *  \param a0
 *  \param a1
 *  \return none
 *
 */
void NIMUStartUpTask(UArg a0, UArg a1)
{
    int32_t retVal;
    uint32_t nimu_device_index = 0U;
    Udma_InitPrms initPrms;

#if defined (__aarch64__)
    UdmaInitPrms_init(UDMA_INST_ID_MAIN_0, &initPrms);
#else
    UdmaInitPrms_init(UDMA_INST_ID_MCU_0, &initPrms);
#endif

    gUdmaDrvHandle = &gUdmaDrvObj;
    retVal = Udma_init(gUdmaDrvHandle, &initPrms);
    if(UDMA_SOK == retVal)
    {
        UART_printf("Udma_init success\n");
    }
    else
    {
        UART_printf("Udma_init failure\n");
        while(1);
    }
    app_test_init_emac_k3(portNum, nimu_device_index);

    NIMUDeviceTable[nimu_device_index++].init =  NimuEmacInitFxn[portNum];
    NIMUDeviceTable[nimu_device_index].init =  NULL;

    /* NIMUStartUpTask complete can post the semaphore now */
    Semaphore_post(gSyncSemHandle);
}

/**
 *  \name TaskFxn
 *  \brief Task Fxn
 *  \param a0
 *  \param a1
 *  \return none
 *
 */
void TaskFxn(UArg a0, UArg a1)
{
    UART_printf("\n\rSYS/BIOS Ethernet/IP () Sample application, EVM IP address I/F 1: %s\n\r", LocalIPAddr);
#ifdef NIMU_FTP_APP
    UART_printf("TaskFxn: calling ftpserver_init\n");
    ftpserver_init();
#endif
}

/**
 *  \name app_test_task_get_stats
 *  \brief get statistics
 *  \param a0
 *  \param a1
 *  \return none
 *
 */
void app_test_task_get_stats(UArg a0, UArg a1)
{

#ifdef NIMU_APP_ICSSG
    EMAC_STATISTICS_ICSSG_T icssStats;
#else
    EMAC_STATISTICS_T cpswStats;
#endif
    uint32_t pNum = (uint32_t) a0;
    while (1)
    {
#ifdef NIMU_APP_ICSSG
        memset(&icssStats, 0, sizeof(EMAC_STATISTICS_ICSSG_T));
        if ((pNum != 6) &&  (emac_get_statistics_icssg(pNum, &icssStats, FALSE) == EMAC_DRV_RESULT_OK))
        {
            UART_printf("**********ICSSG HW stats for PORT NUMBER %d**********\n", pNum);
            UART_printf("-----------------------------------------------------------------------------------------------------------------\n");
            UART_printf(" RX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct:          %12u |\n",
                            icssStats.RxGoodFrames,
                            icssStats.RxBCastFrames,
                            icssStats.RxMCastFrames,
                            icssStats.RXTotalByte);
            UART_printf(" RX |     CRC :      %12u | MIIErr:      %12u | OddNibble: %12u | MaxSizeLimit: %12u |\n",
                            icssStats.RxCRCErrors,
                            icssStats.RxMIIErrors,
                            icssStats.RXOddNibbleFrame,
                            icssStats.RXMaxSizeFrame);
            UART_printf(" RX |     MaxSizeErr:%12u | MinSizeLimit:%12u | MinSizeErr:%12u | OverrunFrame :%12u |\n",
                            icssStats.RXMaxSizeErrFrame,
                            icssStats.RXMinSizeFrame,
                            icssStats.RXMinSizeErrFrame,
                            icssStats.RXoverrunFrame);
            UART_printf(" RX |     Class0:    %12u | Class1:      %12u | Class2:    %12u | Class3:       %12u |\n",
                            icssStats.RXClass0,
                            icssStats.RXClass1,
                            icssStats.RXClass2,
                            icssStats.RXClass3);
            UART_printf(" RX |     Class4:    %12u | Class5:      %12u | Class6:    %12u | Class7:       %12u |\n",
                            icssStats.RXClass4,
                            icssStats.RXClass5,
                            icssStats.RXClass6,
                            icssStats.RXClass7);
            UART_printf(" RX |     Class8:    %12u | Class9:      %12u | Class10:   %12u | Class11:      %12u |\n",
                            icssStats.RXClass8,
                            icssStats.RXClass9,
                            icssStats.RXClass10,
                            icssStats.RXClass11);
            UART_printf(" RX |     Class12:   %12u | Class13:     %12u | Class14:   %12u | Class15:      %12u |\n",
                            icssStats.RXClass12,
                            icssStats.RXClass13,
                            icssStats.RXClass14,
                            icssStats.RXClass15);
            UART_printf(" TX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct           %12u |\n",
                            icssStats.TXGoodFrame,
                            icssStats.TXBCFrame,
                            icssStats.TXMCFrame,
                            icssStats.TXTotalByte);
            UART_printf(" TX |     OddNibble: %12u | UnderFlowErr:%12u | MaxSize:   %12u | MaxSizeErr:   %12u |\n",
                            icssStats.TXOddNibbleFrame,
                            icssStats.TXUnderFlowErr,
                            icssStats.TXMaxSizeFrame,
                            icssStats.TXMaxSizeErrFrame);
            UART_printf("---------------------------------------------------------------------------------------------------------------\n");
        }
#else
        memset(&cpswStats, 0, sizeof(EMAC_STATISTICS_T));
        if ((pNum == 6) &&  (emac_get_statistics(pNum, &cpswStats) == EMAC_DRV_RESULT_OK))
        {
            UART_printf("**********CPSW stats for PORT NUMBER %d**********\n", pNum);
            UART_printf("-----------------------------------------------------------------------------------------------------------------\n");
            UART_printf(" RX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct:          %12u |\n",
                            cpswStats.RxGoodFrames,
                            cpswStats.RxBCastFrames,
                            cpswStats.RxMCastFrames,
                            cpswStats.RxOctets);
            UART_printf(" TX |     Good:      %12u | Bcast:       %12u | Mcast:     %12u | Oct           %12u |\n",
                            cpswStats.TxGoodFrames,
                            cpswStats.TxBCastFrames,
                            cpswStats.TxMCastFrames,
                            cpswStats.TxOctets);
            UART_printf("---------------------------------------------------------------------------------------------------------------\n");
        }
#endif
        Task_sleep(10000);
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params taskParams;
    Semaphore_Params semParams;
    Board_STATUS boardInitStatus =0;
    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ETH_PHY | BOARD_INIT_ENETCTRL_CPSW2G;
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=BOARD_SOK)
    {
        UART_printf("Board_init failure\n");
        return(0);
    }
    UART_printf("Board_init success\n");

    Semaphore_Params_init(&semParams);
    semParams.mode = Semaphore_Mode_BINARY;
    gSyncSemHandle =  Semaphore_create(0,&semParams, NULL);

    if (gSyncSemHandle == NULL)
    {
        UART_printf("Semaphore creation failure\n");
        return 0;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x1400;
    main_task = Task_create (TaskFxn, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x1400;
    taskParams.arg0 = (UArg)portNum;
    main_task = Task_create (NIMUStartUpTask, &taskParams, NULL);


    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x4000;
    taskParams.arg0 = (UArg)portNum;
    Task_create (app_test_task_get_stats, &taskParams, NULL);

    BIOS_start ();
   return 0;
}

#if defined (__aarch64__)
void InitMmu(void)
{
    bool retVal;
    uint32_t     mapIdx = 0;
    Mmu_MapAttrs attrs;

    Mmu_initMapAttrs(&attrs);

    attrs.attrIndx = 0;

    retVal = Mmu_map(0x00100000, 0x00100000, 0x00900000, &attrs); /* Main MMR0 cfg  */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x00400000, 0x00400000, 0x00001000, &attrs); /* PSC0          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x01800000, 0x01800000, 0x00200000, &attrs); /* gicv3       */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }
    
    mapIdx++;
    retVal = Mmu_map(0x02400000, 0x02400000, 0x000c0000, &attrs); /* dmtimer     */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }
    
    mapIdx++;
    retVal = Mmu_map(0x02800000, 0x02800000, 0x00001000, &attrs); /* uart        */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02000000, 0x02000000, 0x00100000, &attrs); /* I2C            */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02100000, 0x02100000, 0x00080000, &attrs); /* McSPI          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    /* SCICLIENT UDMA */
    mapIdx++;
    retVal = Mmu_map(0x20000000ul, 0x20000000ul, 0x10000000ul, &attrs);
    if (retVal == FALSE)
    {
         goto mmu_exit;
    }
    
    mapIdx++;
    retVal = Mmu_map(0x40F00000, 0x40F00000, 0x00020000, &attrs); /* MCU MMR0 CFG   */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x40d00000, 0x40d00000, 0x00002000, &attrs); /* PLL0     CFG       */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x43000000, 0x43000000, 0x00020000, &attrs); /* WKUP     MMR0 cfg  */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02C40000, 0x02C40000, 0x00100000, &attrs); /* pinmux     ctrl    */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

        mapIdx++;
        retVal = Mmu_map(0x30800000, 0x30800000, 0x0C000000, &attrs); /* main  navss          */
        if(retVal == FALSE)
        {
            goto mmu_exit;
        }
        mapIdx++;
    retVal = Mmu_map(0x28380000, 0x28380000, 0x03880000, &attrs); /* mcu navss          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x30000000ul, 0x30000000ul, 0x10000000ul, &attrs); /* ctcontro10 */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    /* for CPSW */
    retVal = Mmu_map(CSL_MCU_CPSW0_NUSS_BASE, CSL_MCU_CPSW0_NUSS_BASE, 
                                    (CSL_MCU_CPSW0_NUSS_SIZE*2), &attrs); 
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    /* ICSS-G 0 */
    mapIdx++;
    retVal = Mmu_map(0xb000000ul, 0xb000000ul, 0x0100000ul, &attrs);
    if (retVal == FALSE)
   {
        goto mmu_exit;
   }

     /* ICSS-G 1 */
     mapIdx++;
     retVal = Mmu_map(0xb100000ul, 0xb100000ul, 0x0100000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }

     /* ICSS-G 2 */
     mapIdx++;
     retVal = Mmu_map(0xb200000ul, 0xb200000ul, 0x0100000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }

     /* PSC WKUP*/
     mapIdx++;
     retVal = Mmu_map(0x42000000ul, 0x42000000ul, 0x00001000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }


    attrs.attrIndx = 7;
    mapIdx++;
    retVal = Mmu_map(0x70000000, 0x70000000, 0x04000000, &attrs); /* msmc        */
   if (retVal == FALSE)
    {
        goto mmu_exit;
    }

#define DDR_TEST
#ifdef DDR_TEST
  attrs.attrIndx = 7;
  mapIdx++;
  retVal = Mmu_map(0x80000000, 0x80000000, 0x10000000, &attrs); /* ddr_0        */
 if (retVal == FALSE)
  {
      goto mmu_exit;
  }
#endif


 attrs.attrIndx = 7;
 mapIdx++;
 retVal = Mmu_map(0x41C00000, 0x41C00000, 0x00080000, &attrs); /* ocmc        */
if (retVal == FALSE)
 {
     goto mmu_exit;
 }



mmu_exit:
    if(retVal == FALSE)
    {
        UART_printf("Mmu_map idx %d returned error %d", mapIdx, retVal);
        while(1);
    }
}
#endif


void stackInitHook(void* hCfg)
{
    int rc;

    rc = 16384; // increase stack size
    CfgAddEntry(hCfg, CFGTAG_OS, CFGITEM_OS_TASKSTKBOOT,CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );
    /* Wait for NIMU startup to complete before proceeding */
    Semaphore_pend(gSyncSemHandle, SemaphoreP_WAIT_FOREVER);
}
