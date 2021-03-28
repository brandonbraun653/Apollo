/**
 * @file   main.c
 *
 * @brief  This file tests the ICSS-EMAC driver APIs
 */
/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#ifdef __LINUX_USER_SPACE
#include <sys/mman.h>
#include <unistd.h>
#include "mmap_helper.h"
#else

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Cache.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>
#include <ti/drv/uart/UART_stdio.h>
#ifdef __JAILHOUSE_INMATE
#include <ti/drv/uart/soc/UART_soc.h>
#endif
#include <ti/board/board.h>
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl_armGicAux.h>

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/icss_emac/test/src/test_common_utils.h>
#ifdef SWITCH_EMAC
#include <ti/drv/icss_emac/test/src/tiswitch_pruss_intc_mapping.h>
#else
#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#endif
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_rx_int_pacing_mmap.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwConfig.h>

/* Handle's to pru-icss instances */
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

#ifdef __LINUX_USER_SPACE
/* ICSS EMAC  PHY address definitions */
#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (0U)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (1U)

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
#else
#include <ti/drv/uart/UART_stdio.h>
#ifdef __JAILHOUSE_INMATE
#include <ti/drv/uart/soc/UART_soc.h>
#endif
#include <ti/board/board.h>
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



/* either idkAM572x or idkAM571x */
uint8_t ICSS_EMAC_testEvmType = 0;

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
    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
#ifndef SWITCH_EMAC	
    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
#endif
    ICSS_EmacFwStaticMmap *pIcssEmacStaticMMap;
    ICSS_EmacFwDynamicMmap *pIcssEmacDynamicMMap;

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

    /* PRUSS Internal PINMUX settings for AM571x */
    if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
    {
        PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle1, PRUICCSS_PRU1, 4);
    }

#ifndef __LINUX_USER_SPACE
    /* For PRU1 Eth0 */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_141, CSL_XBAR_PRUSS1_IRQ_HOST8);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_142, CSL_XBAR_PRUSS1_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_143, CSL_XBAR_PRUSS1_IRQ_HOST4);  /* TX PKT ISR */

#ifndef SWITCH_EMAC	
    /* For PRU1 Eth1 */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_144, CSL_XBAR_PRUSS1_IRQ_HOST9);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_145, CSL_XBAR_PRUSS1_IRQ_HOST3);  /* RX PKT ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_146, CSL_XBAR_PRUSS1_IRQ_HOST5);  /* TX PKT ISR */
#endif
#endif

    /*PRU1ETH 0 initializations*/
    ICSS_EMAC_testHandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((ICSS_EMAC_testHandle == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        PRINT("main: malloc returned null\n");
    }
#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->phyAddr[1]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
#ifdef STP_SWITCH
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_FW_LEARNING_EN;
#else
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_LEARNING_EN;
#endif
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#else
	icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_LEARNING_DIS;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#endif
    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle,1);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth0_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth0_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
#endif

#ifndef SWITCH_EMAC	
    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg0->rxIntNum   = eth0_rxIntNum;
    icss_emacTestInitCfg0->linkIntNum = eth0_linkIntNum;
    icss_emacTestInitCfg0->txIntNum   = eth0_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruss_drv_handle = pruss_drv_handle;
#else
    icss_emacTestInitCfg0->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(141);
    icss_emacTestInitCfg0->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(142);
    icss_emacTestInitCfg0->txIntNum = CSL_armGicGetGicIdForIrqInputLine(143);
#endif


    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->emacInitcfg = icss_emacTestInitCfg0;



    if (icss_emacGetFwMMapInitConfig(0, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        PRINT("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
        return -1;
    }
    icss_emacSetFwMMapInitConfig(ICSS_EMAC_testHandle, 0, pIcssEmacStaticMMap, pIcssEmacDynamicMMap);


#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle, ICSS_EMAC_MODE_SWITCH);
    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
#endif

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH0);
#ifdef SWITCH_EMAC	
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH1);
#endif
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);
    /*PRU1 ETH1  Initializations*/
    ICSS_EMAC_testHandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle1 == NULL) || (icss_emacTestInitCfg1 == NULL))
    {
        PRINT("main: malloc returned null\n");
    }

    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = ICSS_EMAC_LEARNING_DIS;
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle1, 1);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth1_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth1_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
#endif

    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg1->rxIntNum   = eth1_rxIntNum;
    icss_emacTestInitCfg1->linkIntNum = eth1_linkIntNum;
    icss_emacTestInitCfg1->txIntNum   = eth1_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruss_drv_handle = pruss_drv_handle;
#else
    icss_emacTestInitCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(144);
    icss_emacTestInitCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(145);
    icss_emacTestInitCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(146);
#endif
    
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->emacInitcfg = icss_emacTestInitCfg1;

    if (icss_emacGetFwMMapInitConfig(0, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        PRINT("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
        return -1;
    }
    icss_emacSetFwMMapInitConfig(ICSS_EMAC_testHandle1, 0, pIcssEmacStaticMMap, pIcssEmacDynamicMMap);

    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH1);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle1,(ICSS_EmacCallBack) ICSS_EMAC_testCallbackRxPacket1);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle1,(ICSS_EmacCallBack) ICSS_EMAC_testCallbackTxComplete);
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);

    /* Configure firmware rx interrupt pacing */
    ICSS_EMAC_fwIntrPacingConfig(ICSS_EMAC_testHandle, 0, INTR_PAC_DIS_ADP_LGC_DIS, 123*200);
    ICSS_EMAC_fwIntrPacingConfig(ICSS_EMAC_testHandle1, 1, INTR_PAC_DIS_ADP_LGC_DIS, 123*200);
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
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = &port0_ttsCycTask_th;
    if (status = pthread_create(&port0_ttsCycTask_th,
                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle)) {
        printf("ERROR: \"port0_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }

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
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle = &port1_ttsCycTask_th;
    if (status = pthread_create(&port1_ttsCycTask_th,
                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle1)) {
        printf("ERROR: \"port1_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }
    pthread_attr_destroy(&pthread_attr);
#else  // TI-RTOS
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_ttsCycTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
    
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle==NULL)
    {
        return -2;
    }


    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_ttsCycTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif
#endif

    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle);
#ifndef SWITCH_EMAC	
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle1);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle1);
#endif
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle);
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
    

    ICSS_EmacFwStaticMmap *pIcssEmacStaticMMap;
    ICSS_EmacFwDynamicMmap *pIcssEmacDynamicMMap;

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
    {
        return (ret);
    }
#endif

    ICSS_EMAC_testPruIcssHandle2 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_TWO);

    /* PRUSS Internal PINMUX settings for AM571x */
    if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
    {
        PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle2, PRUICCSS_PRU0, 4);
        PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle2, PRUICCSS_PRU1, 4);
    }

#ifndef __LINUX_USER_SPACE
    /* For PRU2 Eth0 */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_127, CSL_XBAR_PRUSS2_IRQ_HOST8);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_137, CSL_XBAR_PRUSS2_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_129, CSL_XBAR_PRUSS2_IRQ_HOST4);  /* TX PKT ISR */
#ifndef SWITCH_EMAC	
    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
    /* For PRU2 Eth1 */
        CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_134, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
        CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_135, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
        CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_136, CSL_XBAR_PRUSS2_IRQ_HOST5);  /* TX PKT ISR */
    }
#endif
#endif

    /*PRU2 ETH0 initializations*/
    ICSS_EMAC_testHandle2 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle2 == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        PRINT("main: malloc returned null\n");
    }
#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->phyAddr[1]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE2;
    icss_emacTestInitCfg0->pacingThreshold = 100;
#ifdef STP_SWITCH
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_FW_LEARNING_EN;
#else
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_LEARNING_EN;
#endif
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#else
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;//ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE2;
    icss_emacTestInitCfg0->pacingThreshold = 0;
    icss_emacTestInitCfg0->learningEn = ICSS_EMAC_LEARNING_DIS;
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
    icss_emacTestInitCfg0->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(137);
    icss_emacTestInitCfg0->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(127);
    icss_emacTestInitCfg0->txIntNum = CSL_armGicGetGicIdForIrqInputLine(129);
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->emacInitcfg = icss_emacTestInitCfg0;

    if (icss_emacGetFwMMapInitConfig(1, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        PRINT("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
        return -1;
    }

    icss_emacSetFwMMapInitConfig(ICSS_EMAC_testHandle2, 1, pIcssEmacStaticMMap, pIcssEmacDynamicMMap);

#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2,ICSS_EMAC_MODE_SWITCH);
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
#endif

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH0);
#ifdef SWITCH_EMAC	
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
#endif
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket2);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);

    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        /*PRU2 ETH1 initializations*/
        ICSS_EMAC_testHandle3 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));
    
        
        icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
        if ((ICSS_EMAC_testHandle3 == NULL) || (icss_emacTestInitCfg1 == NULL))
        {
            PRINT("main: malloc returned null\n");
        }
        icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    
        icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
        icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
        icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
        icss_emacTestInitCfg1->pacingThreshold = 100;
    
        icss_emacTestInitCfg1->learningEn = ICSS_EMAC_LEARNING_DIS;
    
    
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
        icss_emacTestInitCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(135);
        icss_emacTestInitCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(134);
        icss_emacTestInitCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(136);
#endif


        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->emacInitcfg = icss_emacTestInitCfg1;



         if (icss_emacGetFwMMapInitConfig(1, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
         {
             PRINT("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
             return -1;
         }
         icss_emacSetFwMMapInitConfig(ICSS_EMAC_testHandle3, 1, pIcssEmacStaticMMap, pIcssEmacDynamicMMap);


        ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        /* Test ICSS_EmacDeInit */
        ICSS_EmacDeInit(ICSS_EMAC_testHandle3, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
        ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket3);
        ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
        ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);

        /* Configure firmware rx interrupt pacing */
        ICSS_EMAC_fwIntrPacingConfig(ICSS_EMAC_testHandle2, 0, INTR_PAC_DIS_ADP_LGC_DIS, 123*200);
        ICSS_EMAC_fwIntrPacingConfig(ICSS_EMAC_testHandle3, 1, INTR_PAC_DIS_ADP_LGC_DIS, 123*200);
    }
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
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle = &port2_ttsCycTask_th;
    if (status = pthread_create(&port2_ttsCycTask_th,
                                &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle2)) {
        printf("ERROR: \"port2_ttsCycTaskFnc\" task-create failed (%d)\n", status);
        return (-2);
    }

    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
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
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle = &port3_ttsCycTask_th;
        if (status = pthread_create(&port3_ttsCycTask_th,
                                    &pthread_attr, ICSS_EMacOsTTSCycTaskFnc, (void *)ICSS_EMAC_testHandle3)) {
            printf("ERROR: \"port3_ttsCycTaskFnc\" task-create failed (%d)\n", status);
            return (-2);
        }
    }
    pthread_attr_destroy(&pthread_attr);
#else // TI-RTOS
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_ttsCycTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }

    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        Task_Params_init(&taskParams);
        taskParams.priority = 15;
        taskParams.instance->name = (char*)"port3_rxTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle==NULL)
        {
            return -2;
        }

        Task_Params_init(&taskParams);
        taskParams.priority = 15;
        taskParams.instance->name = (char*)"port3_txTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);
    
    
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle==NULL)
        {
            return -2;
        }


    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

        Task_Params_init(&taskParams);
        taskParams.priority = 15;
        taskParams.instance->name = (char*)"port3_ttsCycTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->ttsCycTaskHandle==NULL)
        {
            return -2;
        }
    }
#endif
#endif

    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle2);
#ifndef SWITCH_EMAC	
    ICSS_EMAC_testTimerSetup(ICSS_EMAC_testHandle2);

    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle3);
    }
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

    // Set board type: BOARD_IDKAM571x or BOARD_IDKAM572x
    FILE *fp = popen("cat /proc/device-tree/model", "r");
    char *ln = NULL;
    size_t len = 0;

    getline(&ln, &len, fp);
    if(strstr(ln, "TI AM5728 IDK") != NULL)
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM572x;
    }
    else if (strstr(ln, "TI AM5718 IDK") != NULL)
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM571x;
    }
    else if (strstr(ln, "TI AM5748 IDK") != NULL)
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM574x;
    } else
    {
        PRINT("board type %s is not supported\n", ln);
        return (-1);
    }

    /* Prompt to set core affinity for AM572x */
    if((ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        PRINT("Set core affinity before continuing the process: taskset -p 2 [pid] \n");
        PRINT("Enter character: ");
        getchar();
    }

#ifdef idkAM571x
    ICSS_EMAC_testPruIcssInstance1Setup();
#endif
    ICSS_EMAC_testPruIcssInstance2Setup();

    pthread_attr_init(&pthread_attr);
    pthread_attr_setinheritsched(&pthread_attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_RR);
    sched_param.sched_priority = switchTask_priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    mlockall(MCL_FUTURE);

#ifdef idkAM571x
    if ((status = pthread_create(&ICSS_EMAC_testTaskPruss1_th, &pthread_attr, ICSS_EMAC_testTaskPruss1, NULL))) {
        printf("ERROR: \"SwitchTask1\" task-create failed (%d)\n", status);
        return (-1);
    }
#endif
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

#ifdef idkAM571x
    pthread_join(ICSS_EMAC_testTaskPruss1_th, NULL);
#endif
    pthread_join(ICSS_EMAC_testTaskPruss2_th, NULL);
    pthread_join(ICSS_EMAC_testPort1TxTask_th, NULL);
    pthread_join(ICSS_EMAC_testPort2TxTask_th, NULL);

    pthread_attr_destroy(&pthread_attr);

    return(0);
}
#else // RTOS
    Error_Block eb;
    Task_Params taskParams;
int main()
{
    Board_IDInfo info;
    Board_STATUS boardInitStatus =0;

#ifdef __JAILHOUSE_INMATE
#define BOARD_UART_INSTANCE 2
    UART_HwAttrs uart_hwAttrs;

    /* Make sure non-interrupt mode is used for UART */
    /* Get the UART default configuration */
    UART_socGetInitCfg(BOARD_UART_INSTANCE, &uart_hwAttrs);
    /* Disabling interrupt mode, forcing UART to use the polling mode */
    uart_hwAttrs.enableInterrupt = 0;
    /* Write back the config */
    UART_socSetInitCfg(BOARD_UART_INSTANCE, &uart_hwAttrs);

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
#else
    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
#endif

    Error_init(&eb);
    boardInitStatus  = Board_init(cfg);

    if (boardInitStatus !=0)
    {
        printf("Board_init failure\n");
        return(0);
    }

#ifdef __JAILHOUSE_INMATE
    if (!(strcmp(info.boardName, "AM572IDK")))
    {
        PRINT("boardName: %s\n", "idkAM572x");
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM572x;
    }
    else
    {
        PRINT("boardName: %s\n", "idkAM574x");
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM574x;
    }
#else
    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);
    PRINT("boardName: %s\n", info.boardName);
    if (!(strcmp(info.boardName, "AM571IDK")))
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM571x;
    }
    else if(!(strcmp(info.boardName, "AM572IDK")))
    {
       ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM572x;
    }
    else
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM574x;
     }
#endif

#if defined (idkAM571x)
#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "SwitchTask1";
    Task_create(ICSS_EMAC_testTaskPruss1, &taskParams, &eb);

    ICSS_EMAC_testPruIcssInstance1Setup();
#endif
#endif


#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port1TxTask";
    Task_create(ICSS_EMAC_testPort1TxTask, &taskParams, &eb);
#endif

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "SwitchTask2";
    Task_create(ICSS_EMAC_testTaskPruss2, &taskParams, &eb);

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port2TxTask";
    Task_create(ICSS_EMAC_testPort2TxTask, &taskParams, &eb);
#endif

    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
}
#endif


