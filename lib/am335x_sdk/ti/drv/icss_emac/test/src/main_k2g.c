/**
 * @file   main_k2g.c
 *
 * @brief  This file tests the ICSS-EMAC driver APIs for ICE_K2G
 */
/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *
*/

#ifdef __LINUX_USER_SPACE
#include <sys/mman.h>
#include <unistd.h>
#include "mmap_helper.h"
#else
#include <xdc/std.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#ifndef __LINUX_USER_SPACE
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Cache.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>
#endif

#include <ti/csl/soc.h>
#ifdef __ARM_ARCH_7A__
#include <ti/csl/csl_armGicAux.h>
#endif

#ifdef __LINUX_USER_SPACE
/* ICSS EMAC  PHY address definitions */
#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (0U)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (1U)
#define BOARD_ICSS_EMAC_PORT2_PHY_ADDR       (2U)
#define BOARD_ICSS_EMAC_PORT3_PHY_ADDR       (3U)
#else
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#endif

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>


#include <ti/drv/icss_emac/test/src/test_common_utils.h>
#ifdef SWITCH_EMAC
#include <ti/drv/icss_emac/test/src/tiswitch_pruss_intc_mapping.h>
#else
#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#endif

#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

#ifdef _TMS320C6X
#include <ti/sysbios/family/c66/Cache.h>
#endif

#ifdef __LINUX_USER_SPACE
static inline void linux_sleep_ms(unsigned long ms) {
    struct timespec ts;
    ts.tv_sec = (ms)/1000;
    ms = ms - ts.tv_sec*1000;
    ts.tv_nsec = (ms*1000000);
    nanosleep(&ts, NULL);
}
#define SLEEP(t) linux_sleep_ms(t)
#define PRINT printf
#else
#define SLEEP Task_sleep
#define PRINT UART_printf
#endif

extern uint8_t ICSS_EMAC_testPkt[];
extern uint32_t ICSS_EMAC_testTotalPktRcvd;

/* number of links which actually came up to test the interface */
static uint32_t  ICSS_EMAC_testLinkUpCount = 0;

#ifdef __LINUX_USER_SPACE
extern tprussdrv *pruss_drv_handle;
extern tprussdrv *pruss_drv_handle2;
extern PRUICSS_HwAttrs linux_prussHwAttrs[PRUICCSS_INSTANCE_MAX-1];
extern PRUICSS_V1_Object linux_prussObjects[PRUICCSS_INSTANCE_MAX-1];
extern PRUICSS_Config linux_pruss_config[PRUICCSS_INSTANCE_MAX];

pthread_t port0_rxTask_th, port0_txTask_th, port0_ttsCycTask_th, port0_linkTask_th,
          port1_rxTask_th, port1_txTask_th, port1_ttsCycTask_th, port1_linkTask_th,
          port2_rxTask_th, port2_txTask_th, port2_ttsCycTask_th, port2_linkTask_th,
          port3_rxTask_th, port3_txTask_th, port3_ttsCycTask_th, port3_linkTask_th;

int eth0_rxIntNum = 0,
    eth0_txIntNum = 2,
    eth0_linkIntNum = 6,
    eth1_rxIntNum = 1,
    eth1_txIntNum = 3,
    eth1_linkIntNum = 7;
#endif

PRUICSS_Handle ICSS_EMAC_testPruIcssHandle1 = NULL;
PRUICSS_Handle ICSS_EMAC_testPruIcssHandle2 = NULL;

extern ICSS_EmacHandle ICSS_EMAC_testHandle;
extern ICSS_EmacHandle ICSS_EMAC_testHandle1;
extern ICSS_EmacHandle ICSS_EMAC_testHandle2;
extern ICSS_EmacHandle ICSS_EMAC_testHandle3;

extern uint8_t ICSS_EMAC_testLclMac[];
extern uint8_t ICSS_EMAC_testLclMac1[];
extern uint8_t ICSS_EMAC_testLclMac2[];
extern uint8_t ICSS_EMAC_testLclMac3[];

extern uint32_t ICSS_EMAC_testPacketRcvdPort0;
extern uint32_t ICSS_EMAC_testPacketRcvdPort1;
extern uint32_t ICSS_EMAC_testPacketRcvdPort2;
extern uint32_t ICSS_EMAC_testPacketRcvdPort3;

extern uint32_t ICSS_EMAC_testLinkIsrPru1Eth0;
extern uint32_t ICSS_EMAC_testLinkIsrPru1Eth1;
extern uint32_t ICSS_EMAC_testLinkIsrPru2Eth0;
extern uint32_t ICSS_EMAC_testLinkIsrPru2Eth1;

extern uint8_t    ICSS_EMAC_testTtsModePort1;
extern uint8_t    ICSS_EMAC_testTtsModePort2;


uint8_t ICSS_EMAC_testEvmType = ICSS_EMAC_TEST_BOARD_ICEK2G;
static uint32_t ICSS_EMAC_testPruInstance2Done = 0;

/***********************************************************************/
/* local functions declaration                                         */
/***********************************************************************/

/*
 *  ======== main ========
 */
int32_t ICSS_EMAC_testPruIcssInstance1Setup(void)
{

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    PRUICSS_Config  *cfg;

#ifdef __LINUX_USER_SPACE
    int status;
    int priority = 20;
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;

    linux_init((void**)&pruss_drv_handle, linux_prussHwAttrs, PRUICCSS_INSTANCE_ONE);
    cfg = linux_pruss_config;
#else
    Task_Params taskParams;
    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
#endif
    ICSS_EMAC_testPruIcssHandle1 = PRUICSS_create((PRUICSS_Config*) cfg,PRUICCSS_INSTANCE_ONE);

    /* Need to explicitly set MII mode for K2G in GPCFG registers*/
    PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle1, PRUICCSS_PRU0, 2);
    PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle1, PRUICCSS_PRU1, 2);

#ifndef SWITCH_EMAC	
    /*PRU1ETH 0 initializations*/
    ICSS_EMAC_testHandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle,1);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth0_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth0_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
#endif

    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg0->rxIntNum   = eth0_rxIntNum;
    icss_emacTestInitCfg0->linkIntNum = eth0_linkIntNum;
    icss_emacTestInitCfg0->txIntNum   = eth0_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruss_drv_handle = pruss_drv_handle;
#else
#if defined (__ARM_ARCH_7A__)
    icss_emacTestInitCfg0->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT6);
    icss_emacTestInitCfg0->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT0);
    icss_emacTestInitCfg0->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT2);
#else
    icss_emacTestInitCfg0->linkIntNum= CSL_CIC_ICSSM0_HOST_INT6;
    icss_emacTestInitCfg0->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT54;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT6;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxOutEvent= 54; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT54 */

    icss_emacTestInitCfg0->rxIntNum = CSL_CIC_ICSSM0_HOST_INT0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT55;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxOutEvent= 55; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT55 */

    icss_emacTestInitCfg0->txIntNum = CSL_CIC_ICSSM0_HOST_INT2;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT56;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT2;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxOutEvent= 56; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT56 */
#endif
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->emacInitcfg = icss_emacTestInitCfg0;

    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH0);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);

#ifdef TTS_TEST
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);
#endif
#endif
    /*PRU1 ETH1  Initializations*/
    ICSS_EMAC_testHandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg1->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg1->phyAddr[1]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->learningEn = 1;
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;
#else
    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->learningEn = 0;
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle1, 1);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth1_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth1_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
#endif

#ifndef SWITCH_EMAC	
    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

#ifdef SWITCH_EMAC
#if defined (__ARM_ARCH_7A__)
    icss_emacTestInitCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT6);
    icss_emacTestInitCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT0);
    icss_emacTestInitCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT2);
#else
    icss_emacTestInitCfg1->linkIntNum= CSL_CIC_ICSSM0_HOST_INT6;
    icss_emacTestInitCfg1->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT54;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT6;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxOutEvent= 54; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT54 */

    icss_emacTestInitCfg1->rxIntNum = CSL_CIC_ICSSM0_HOST_INT0;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT55;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT0;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxOutEvent= 55; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT55 */

    icss_emacTestInitCfg1->txIntNum = CSL_CIC_ICSSM0_HOST_INT2;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT56;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT2;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxOutEvent= 56; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT56 */
#endif
#else
#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg1->rxIntNum   = eth1_rxIntNum;
    icss_emacTestInitCfg1->linkIntNum = eth1_linkIntNum;
    icss_emacTestInitCfg1->txIntNum   = eth1_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruss_drv_handle = pruss_drv_handle;
#else
#if defined (__ARM_ARCH_7A__)
    icss_emacTestInitCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT7); /* CSL_ARM_GIC_ICSSM0_HOST_INT7 == 0xE7 (231) */
    icss_emacTestInitCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT1);
    icss_emacTestInitCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM0_HOST_INT3);
#else
    icss_emacTestInitCfg1->linkIntNum= CSL_CIC_ICSSM0_HOST_INT7;
    icss_emacTestInitCfg1->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT57;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT7;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxOutEvent= 57; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT57 */

    icss_emacTestInitCfg1->rxIntNum = CSL_CIC_ICSSM0_HOST_INT1;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT58;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT1;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxOutEvent= 58; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT58 */

    icss_emacTestInitCfg1->txIntNum = CSL_CIC_ICSSM0_HOST_INT3;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT59;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM0_HOST_INT3;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxOutEvent= 59; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT59 */
#endif
#endif
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->emacInitcfg = icss_emacTestInitCfg1;

#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_SWITCH);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
#endif

#ifdef SWITCH_EMAC	
    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH0);
#endif
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH1);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle1,(ICSS_EmacCallBack) ICSS_EMAC_testCallbackRxPacket1);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle1,(ICSS_EmacCallBack) ICSS_EMAC_testCallbackTxComplete);
#ifndef SWITCH_EMAC	
#ifdef TTS_TEST
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);
#endif
#ifdef __LINUX_USER_SPACE
    pthread_attr_init(&pthread_attr);
    pthread_attr_setinheritsched(&pthread_attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_FIFO);
    sched_param.sched_priority = priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    if (status = pthread_create(&port0_linkTask_th,
                &pthread_attr, ICSS_EMacOsLinkTaskFnc, (void *)ICSS_EMAC_testHandle)) {
        printf("ERROR: \"port0_linkTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle = &port0_rxTask_th;
    if (status = pthread_create(&port0_rxTask_th,
                &pthread_attr, ICSS_EMacOsRxTaskFnc, (void *)ICSS_EMAC_testHandle)) {
        printf("ERROR: \"port0_rxTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle = &port0_txTask_th;
    if (status = pthread_create(&port0_txTask_th,
                &pthread_attr, ICSS_EMacOsTxTaskFnc, (void *)ICSS_EMAC_testHandle)) {
        printf("ERROR: \"port0_txTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#ifdef TTS_TEST
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = &port0_ttsCycTask_th;
    if (status = pthread_create(&port0_ttsCycTask_th,
                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle)) {
        printf("ERROR: \"port0_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#endif
#else  // TI-RTOS
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_linkTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_txTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);
    
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle==NULL)
    {
        return -2;
    }
#ifdef TTS_TEST
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_ttsCycTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);
    
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif
#endif
#endif
#ifdef __LINUX_USER_SPACE
    if (status = pthread_create(&port1_linkTask_th,
                &pthread_attr, ICSS_EMacOsLinkTaskFnc, (void *)ICSS_EMAC_testHandle1)) {
        printf("ERROR: \"port1_linkTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle = &port1_rxTask_th;
    if (status = pthread_create(&port1_rxTask_th,
                &pthread_attr, ICSS_EMacOsRxTaskFnc, (void *)ICSS_EMAC_testHandle1)) {
        printf("ERROR: \"port1_rxTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle = &port1_txTask_th;
    if (status = pthread_create(&port1_txTask_th,
                &pthread_attr, ICSS_EMacOsTxTaskFnc, (void *)ICSS_EMAC_testHandle1)) {
        printf("ERROR: \"port1_txTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#ifndef SWITCH_EMAC
#ifdef TTS_TEST
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle = &port1_ttsCycTask_th;
    if (status = pthread_create(&port1_ttsCycTask_th,
                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle1)) {
        printf("ERROR: \"port1_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#endif
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle);
#endif
    pthread_attr_destroy(&pthread_attr);

#else //RTOS
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_txTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);
    
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle==NULL)
    {
        return -2;
    }
#ifndef SWITCH_EMAC
#ifdef TTS_TEST
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_ttsCycTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);
    
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle);
#endif
#endif
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle1);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle1);
    return 0;
}

int32_t ICSS_EMAC_testPruIcssInstance2Setup(void)
{
    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    PRUICSS_Config  *cfg;
    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
#ifndef SWITCH_EMAC	
    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
#endif

#ifdef __LINUX_USER_SPACE
    int status;
    int priority = 20;
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;

    linux_init((void**)&pruss_drv_handle2, linux_prussHwAttrs, PRUICCSS_INSTANCE_TWO);
    cfg = linux_pruss_config;
#else
    Task_Params taskParams;
    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
#endif

    ICSS_EMAC_testPruIcssHandle2 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_TWO);

    /*PRU2 ETH0 initializations*/
    ICSS_EMAC_testHandle2 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    /* Need to explicitly set MII mode for K2G in GPCFG registers*/
    PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle2, PRUICCSS_PRU0, 2);
    PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle2, PRUICCSS_PRU1, 2);

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT2_PHY_ADDR;
    icss_emacTestInitCfg0->phyAddr[1]=BOARD_ICSS_EMAC_PORT3_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 1;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#else
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT2_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;//ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle2,2);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkInt_fd = prussdrv_open(pruss_drv_handle2, eth0_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxInt_fd = prussdrv_open(pruss_drv_handle2, eth0_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txInt_fd = prussdrv_open(pruss_drv_handle2, eth0_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle2, eth0_txIntNum);
#endif

#ifndef SWITCH_EMAC	
    /*Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg0->rxIntNum   = eth0_rxIntNum;
    icss_emacTestInitCfg0->linkIntNum = eth0_linkIntNum;
    icss_emacTestInitCfg0->txIntNum   = eth0_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->pruss_drv_handle = pruss_drv_handle2;
#else
#if defined (__ARM_ARCH_7A__)
    icss_emacTestInitCfg0->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT6);
    icss_emacTestInitCfg0->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT0);
    icss_emacTestInitCfg0->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT2);
#else
    icss_emacTestInitCfg0->linkIntNum= CSL_CIC_ICSSM1_HOST_INT6;
    icss_emacTestInitCfg0->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT48;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT6;
    icss_emacTestInitCfg0->intrMuxCfgLink.intcMuxOutEvent= 48; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT48 */

    icss_emacTestInitCfg0->rxIntNum = CSL_CIC_ICSSM1_HOST_INT0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT49;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT0;
    icss_emacTestInitCfg0->intrMuxCfgRxPkt.intcMuxOutEvent= 49; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT49 */

    icss_emacTestInitCfg0->txIntNum = CSL_CIC_ICSSM1_HOST_INT2;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT50;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxNum = 0;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT2;
    icss_emacTestInitCfg0->intrMuxCfgTxComplete.intcMuxOutEvent= 50; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT50 */
#endif
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->emacInitcfg = icss_emacTestInitCfg0;

#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2,ICSS_EMAC_MODE_SWITCH);
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1);
#endif

    PRUICSS_pinMuxConfig(ICSS_EMAC_testPruIcssHandle2, 0x0); // PRUSS pinmuxing

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH0);
#ifdef SWITCH_EMAC	
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
#endif
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket2);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);

#ifndef SWITCH_EMAC	
#ifdef TTS_TEST
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);
#endif
    /*PRU2 ETH1 initializations*/
    ICSS_EMAC_testHandle3 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));


    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT3_PHY_ADDR;

    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;

    icss_emacTestInitCfg1->learningEn = 0;


    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac3;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle3, 2);

#ifdef __LINUX_USER_SPACE
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkInt_fd = prussdrv_open(pruss_drv_handle2, eth1_linkIntNum);
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxInt_fd = prussdrv_open(pruss_drv_handle2, eth1_rxIntNum);
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txInt_fd = prussdrv_open(pruss_drv_handle2, eth1_txIntNum);
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle2, eth1_txIntNum);
#endif

    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

#ifdef __LINUX_USER_SPACE
        icss_emacTestInitCfg1->rxIntNum   = eth1_rxIntNum;
        icss_emacTestInitCfg1->linkIntNum = eth1_linkIntNum;
        icss_emacTestInitCfg1->txIntNum   = eth1_txIntNum;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruss_drv_handle = pruss_drv_handle2;
#else
#if defined (__ARM_ARCH_7A__)
    icss_emacTestInitCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT7);      /* CSL_ARM_GIC_ICSSM1_HOST_INT7 == 0xEF (239) */
    icss_emacTestInitCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT1);
    icss_emacTestInitCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT3);
#else
    icss_emacTestInitCfg1->linkIntNum= CSL_CIC_ICSSM1_HOST_INT7;
    icss_emacTestInitCfg1->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT51;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT7;
    icss_emacTestInitCfg1->intrMuxCfgLink.intcMuxOutEvent= 51; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT51 */

    icss_emacTestInitCfg1->rxIntNum = CSL_CIC_ICSSM1_HOST_INT1;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT52;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT1;
    icss_emacTestInitCfg1->intrMuxCfgRxPkt.intcMuxOutEvent= 52; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT52 */

    icss_emacTestInitCfg1->txIntNum = CSL_CIC_ICSSM1_HOST_INT3;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT53;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxNum = 0;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT3;
    icss_emacTestInitCfg1->intrMuxCfgTxComplete.intcMuxOutEvent= 53; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT53 */
#endif
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->emacInitcfg = icss_emacTestInitCfg1;

    ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle3, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket3);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);

#ifdef TTS_TEST
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);
#endif
#endif

#ifdef __LINUX_USER_SPACE
    pthread_attr_init(&pthread_attr);
    pthread_attr_setinheritsched(&pthread_attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_FIFO);
    sched_param.sched_priority = priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    if (status = pthread_create(&port2_linkTask_th,
                                &pthread_attr, ICSS_EMacOsLinkTaskFnc, (void *)ICSS_EMAC_testHandle2)) {
        printf("ERROR: \"port2_linkTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle = &port2_rxTask_th;
    if (status = pthread_create(&port2_rxTask_th,
                                &pthread_attr, ICSS_EMacOsRxTaskFnc, (void *)ICSS_EMAC_testHandle2)) {
        printf("ERROR: \"port2_rxTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle = &port2_txTask_th;
    if (status = pthread_create(&port2_txTask_th,
                                &pthread_attr, ICSS_EMacOsTxTaskFnc, (void *)ICSS_EMAC_testHandle2)) {
        printf("ERROR: \"port2_txTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_linkTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_txTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle==NULL)
    {
        return -2;
    }
#endif

#ifndef SWITCH_EMAC	
#ifdef TTS_TEST
#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle = &port2_ttsCycTask_th;
    if (status = pthread_create(&port2_ttsCycTask_th,
                                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle2)) {
        printf("ERROR: \"port2_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_ttsCycTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif
#endif

#ifdef __LINUX_USER_SPACE
    if (status = pthread_create(&port3_linkTask_th,
                                &pthread_attr, ICSS_EMacOsLinkTaskFnc, (void *)ICSS_EMAC_testHandle3)) {
        printf("ERROR: \"port3_linkTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle = &port3_rxTask_th;
    if (status = pthread_create(&port3_rxTask_th,
                                &pthread_attr, ICSS_EMacOsRxTaskFnc, (void *)ICSS_EMAC_testHandle3)) {
        printf("ERROR: \"port3_rxTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle = &port3_txTask_th;
    if (status = pthread_create(&port3_txTask_th,
                                &pthread_attr, ICSS_EMacOsTxTaskFnc, (void *)ICSS_EMAC_testHandle3)) {
        printf("ERROR: \"port3_txTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_linkTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_txTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle==NULL)
    {
        return -2;
    }
#endif

#ifdef TTS_TEST
#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle = &port3_ttsCycTask_th;
    if (status = pthread_create(&port3_ttsCycTask_th,
                                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle3)) {
        printf("ERROR: \"port3_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_ttsCycTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif
#endif
#endif

#ifndef SOC_K2G
    ICSS_EMAC_testTimerSetup(ICSS_EMAC_testHandle2);
#endif

    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle2);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle2);
#ifndef SWITCH_EMAC	
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle3);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle3);
#endif
    return 0;
}

#ifdef __LINUX_USER_SPACE
uint32_t num_iteration = 10;
uint32_t cycle_period_port1 = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1;
uint32_t cycle_period_port2 = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2;
uint32_t config_time =   ICSS_EMAC_TEST_TTS_CONFIG_TIME;
int main(int argc, char **argv)
{
    uint32_t numPorts = 4;
    int status;
    int switchTask_priority = 10;
    int ttsTask_priority = 10;
    pthread_t ICSS_EMAC_testTaskPruss1_th, ICSS_EMAC_testTaskPruss2_th, ICSS_EMAC_testPort1TxTask_th, ICSS_EMAC_testPort2TxTask_th;
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;

    if(argc > 1)
    {
        num_iteration =  atoi(argv[1]);
        cycle_period_port1  = atoi(argv[2]);
        cycle_period_port2  = atoi(argv[3]);
        config_time   = atoi(argv[4]);
    }

    ICSS_EMAC_testPruIcssInstance1Setup();
    ICSS_EMAC_testPruIcssInstance2Setup();

    pthread_attr_init(&pthread_attr);
    pthread_attr_setinheritsched(&pthread_attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_RR);
    sched_param.sched_priority = switchTask_priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    mlockall(MCL_FUTURE);

    if ((status = pthread_create(&ICSS_EMAC_testTaskPruss1_th, &pthread_attr, ICSS_EMAC_testTaskPruss1, NULL))) {
        printf("ERROR: \"SwitchTask1\" task-create failed (%d)\n", status);
        return (-1);
    }
    if ((status = pthread_create(&ICSS_EMAC_testTaskPruss2_th, NULL, ICSS_EMAC_testTaskPruss2, NULL))) {
        printf("ERROR: \"SwitchTask2\" task-create failed (%d)\n", status);
        return (-1);
    }
    // Set TTS tasks priority
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_FIFO);
    sched_param.sched_priority = ttsTask_priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    if ((status = pthread_create(&ICSS_EMAC_testPort1TxTask_th, &pthread_attr, ICSS_EMAC_testPort1TxTask, NULL))) {
        printf("ERROR: \"ttsPort1TxTask\" task-create failed (%d)\n", status);
        return (-1);
    }
    if ((status = pthread_create(&ICSS_EMAC_testPort2TxTask_th, &pthread_attr, ICSS_EMAC_testPort2TxTask, NULL))) {
        printf("ERROR: \"ttsPort2TxTask\" task-create failed (%d)\n", status);
        return (-1);
    }

    pthread_join(ICSS_EMAC_testTaskPruss1_th, NULL);
    pthread_join(ICSS_EMAC_testTaskPruss2_th, NULL);
    pthread_join(ICSS_EMAC_testPort1TxTask_th, NULL);
    pthread_join(ICSS_EMAC_testPort2TxTask_th, NULL);

    pthread_attr_destroy(&pthread_attr);

    return(0);
}
#else // RTOS
    Error_Block eb;
    Task_Params taskParams;

void ICSS_EMAC_testDelay(uint32_t delay)
{
    volatile uint32_t delay1 = delay*2;
    while (delay1--) ;
}

void pruss_iep_Initialization(uint8_t prussn)
{
    uint32_t pruss_base=0;

    if(prussn==1)
        pruss_base = CSL_ICSS_0_CFG_REGS;
    else
        pruss_base = CSL_ICSS_1_CFG_REGS;

    HWREG(pruss_base + 0x04)=0x06; //NO_STANDBY

    ICSS_EMAC_testDelay(50);
}

void pruss_iep_MDIOInitialization(uint8_t instance)
{
    uint32_t pruss_base = 0;
    ICSS_EmacBaseAddrCfgParams cfg;
    memset(&cfg, 0, sizeof(ICSS_EmacBaseAddrCfgParams));

    ICSS_EmacSocGetInitCfg((instance-1), &cfg );
    pruss_base = cfg.prussMiiMdioRegs + 0x04;

    /* Initialize the MDIO pin */
    HWREG(pruss_base) = 0x4000009F;//increase speed
                         /*200/(0x9F+1) = 1.25 MHz*/
    ICSS_EMAC_testDelay(50);
}

    
int main()
{
    Board_STATUS boardInitStatus =0;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;

    Error_init(&eb);
    boardInitStatus  = Board_init(cfg);

    if (boardInitStatus !=0)
    {
        printf("Board_init failure\n");
        return(0);
    }

    /* Switch the ICSS clock to 225MHz.
     * Limit it to EMAC switch tests as TTS verification depends on 200MHz clock */
#if defined(iceK2G)
#ifdef SWITCH_EMAC
    Board_PLLICSSConfig(BOARD_ICSS_PLL_CLK_225MHZ);
#endif
#endif

#ifdef _TMS320C6X
    /* Disable L1 Data Cache */
    Cache_disable(Cache_Type_L1D);
#endif
    pruss_iep_Initialization(1);
    pruss_iep_Initialization(2);

    pruss_iep_MDIOInitialization(1);
    pruss_iep_MDIOInitialization(2);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.stackSize = 0x1500;
    taskParams.instance->name = "SwitchTask1";
    Task_create(ICSS_EMAC_testTaskPruss1, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.stackSize = 0x1500;
    taskParams.instance->name = "SwitchTask2";
    Task_create(ICSS_EMAC_testTaskPruss2, NULL, &eb);

#ifndef SWITCH_EMAC	
#ifdef TTS_TEST
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port1TxTask";
    Task_create(ICSS_EMAC_testPort1TxTask, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port2TxTask";
    Task_create(ICSS_EMAC_testPort2TxTask, NULL, &eb);
#endif
#endif

    ICSS_EMAC_testPruIcssInstance1Setup();
    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
}

#endif


