/*
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
 * 
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>
#endif

#include <ti/csl/soc.h>

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/test/src/test_common_utils.h>
#ifdef SWITCH_EMAC
#include <ti/drv/icss_emac/test/src/tiswitch_pruss_intc_mapping.h>
#else
#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#endif

#ifdef __LINUX_USER_SPACE
/* ICSS EMAC  PHY address definitions */
#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (1U)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (3U)
#else
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#endif

#include <ti/starterware/include/hw/soc_am335x.h>

extern uint8_t ICSS_EMAC_testPkt[];


extern uint8_t    ICSS_EMAC_testTtsModePort1;
extern uint8_t    ICSS_EMAC_testTtsModePort2;


extern ICSS_EmacHandle ICSS_EMAC_testHandle;
extern ICSS_EmacHandle ICSS_EMAC_testHandle1;

extern uint32_t ICSS_EMAC_testPacketRcvdPort0;
extern uint32_t ICSS_EMAC_testPacketRcvdPort1;

extern uint8_t ICSS_EMAC_testLclMac[];
extern uint8_t ICSS_EMAC_testLclMac1[];


uint8_t ICSS_EMAC_testEvmType = ICSS_EMAC_TEST_BOARD_ICEV2AM335x;

PRUICSS_Handle ICSS_EMAC_testPruIcssHandle1 = NULL;
PRUICSS_Handle ICSS_EMAC_testPruIcssHandle2 = NULL;

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


#ifdef __LINUX_USER_SPACE
extern tprussdrv *pruss_drv_handle;
extern PRUICSS_HwAttrs linux_prussHwAttrs[PRUICCSS_INSTANCE_MAX-1];
extern PRUICSS_V1_Object linux_prussObjects[PRUICCSS_INSTANCE_MAX-1];
extern PRUICSS_Config linux_pruss_config[PRUICCSS_INSTANCE_MAX];

pthread_t port0_rxTask_th, port0_txTask_th, port0_ttsCycTask_th, port0_linkTask_th,
          port1_rxTask_th, port1_txTask_th, port1_ttsCycTask_th, port1_linkTask_th;

int eth0_rxIntNum = 0,
    eth0_txIntNum = 2,
    eth0_linkIntNum = 6,
    eth1_rxIntNum = 1,
    eth1_txIntNum = 3,
    eth1_linkIntNum = 7;
#endif

/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/
int32_t ICSS_EMAC_testPruIcssInstanceSetup(void)
{
    PRUICSS_Config  *cfg;
    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
    ICSS_EmacInitConfig* icss_emacTestInitCfg1;

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
    ICSS_EMAC_testPruIcssHandle1 = PRUICSS_create((PRUICSS_Config*) cfg, PRUICCSS_INSTANCE_ONE);

#ifndef SWITCH_EMAC	
    /*Port I initializations*/
    ICSS_EMAC_testHandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((ICSS_EMAC_testHandle == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        PRINT("main: malloc returned null\n");
        return -1;
    }
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;


    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 0;

#ifndef __LINUX_USER_SPACE
    ICSS_EMAC_testSocCtrlGetPortMacAddr(1,ICSS_EMAC_testLclMac);
#endif
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle, 1);

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth0_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth0_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth0_txIntNum);
#endif

    /*  Enable interrupt mode for TTS Cyclic Packet     */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg0->rxIntNum   = eth0_rxIntNum;
    icss_emacTestInitCfg0->linkIntNum = eth0_linkIntNum;
    icss_emacTestInitCfg0->txIntNum   = eth0_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruss_drv_handle = pruss_drv_handle;
#else
    icss_emacTestInitCfg0->rxIntNum = 20;
    icss_emacTestInitCfg0->linkIntNum = 26;
    icss_emacTestInitCfg0->txIntNum = 22;
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->emacInitcfg = icss_emacTestInitCfg0;
#endif

    /*PORT2 Initializations*/
    ICSS_EMAC_testHandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg1->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg1->phyAddr[1]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg1->halfDuplexEnable = 0;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = 1;
#ifndef __LINUX_USER_SPACE
    ICSS_EMAC_testSocCtrlGetPortMacAddr(2,ICSS_EMAC_testLclMac1);
#endif
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;
#else
    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->halfDuplexEnable = 1;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = 0;
#ifndef __LINUX_USER_SPACE
    ICSS_EMAC_testSocCtrlGetPortMacAddr(2,ICSS_EMAC_testLclMac1);
#endif
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle1,1);     // ICSS_M instance 0

#ifdef __LINUX_USER_SPACE
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkInt_fd = prussdrv_open(pruss_drv_handle, eth1_linkIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxInt_fd = prussdrv_open(pruss_drv_handle, eth1_rxIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->ttsCycInt_fd = prussdrv_open(pruss_drv_handle, eth1_txIntNum);
#endif

#ifndef SWITCH_EMAC	
    /*  Enable interrupt mode for TTS Cyclic Packet     */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

#ifdef __LINUX_USER_SPACE
    icss_emacTestInitCfg1->rxIntNum   = eth1_rxIntNum;
    icss_emacTestInitCfg1->linkIntNum = eth1_linkIntNum;
    icss_emacTestInitCfg1->txIntNum   = eth1_txIntNum;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruss_drv_handle = pruss_drv_handle;
#else
#ifdef SWITCH_EMAC
    icss_emacTestInitCfg1->rxIntNum = 20;
    icss_emacTestInitCfg1->linkIntNum = 26;
    icss_emacTestInitCfg1->txIntNum = 22;
#else
    icss_emacTestInitCfg1->rxIntNum = 21;
    icss_emacTestInitCfg1->linkIntNum = 27;
    icss_emacTestInitCfg1->txIntNum = 23;
#endif
#endif

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->emacInitcfg = icss_emacTestInitCfg1;

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_SWITCH);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacInit(ICSS_EMAC_testHandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
#endif

    /* Register TTS Callbacks  */
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);
#endif

    /* Register RX Callbacks: Required for TTS Unit Testing    */
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket);
#endif
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket1);

    /* Register Tx Callbacks */
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
#endif
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);

    /* Register Link ISR Callbacks */
#ifndef SWITCH_EMAC	
    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH0);
#else
    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH0);
#endif
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle1, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU1ETH1);

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
#else

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle==NULL)
    {
        PRINT("main: Task_create rturned NULL handle\n");
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
        PRINT("main: Task_create rturned NULL handle\n");
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_ttsCycTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
#endif

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
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
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

#ifndef SWITCH_EMAC	
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

#ifndef SWITCH_EMAC	
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle);
#endif
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle1);

#ifndef SWITCH_EMAC	
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle);
#endif
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle1);

    return 0;
}

/*
 *  ======== main ========
 */
#ifdef __LINUX_USER_SPACE
uint32_t num_iteration = 10;
uint32_t cycle_period_port1 = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1;
uint32_t cycle_period_port2 = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2;
uint32_t config_time =   ICSS_EMAC_TEST_TTS_CONFIG_TIME;
int main(int argc, char **argv)
{
    uint32_t numPorts = 2;
    int status;
    int switchTask_priority = 10;
    int ttsTask_priority = 10;
    pthread_t ICSS_EMAC_testTaskPruss_th, ICSS_EMAC_testPort1TxTask_th, ICSS_EMAC_testPort2TxTask_th;
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;

    if(argc > 1)
    {
        num_iteration =  atoi(argv[1]);
        cycle_period_port1  = atoi(argv[2]);
        cycle_period_port2  = atoi(argv[3]);
        config_time   = atoi(argv[4]);
    }

    ICSS_EMAC_testPruIcssInstanceSetup();

    pthread_attr_init(&pthread_attr);
    pthread_attr_setinheritsched(&pthread_attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&pthread_attr, SCHED_RR);
    sched_param.sched_priority = switchTask_priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    mlockall(MCL_FUTURE);

    if ((status = pthread_create(&ICSS_EMAC_testTaskPruss_th, &pthread_attr, ICSS_EMAC_testTaskPruss1, NULL))) {
        printf("ERROR: \"SwitchTask1\" task-create failed (%d)\n", status);
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

    pthread_join(ICSS_EMAC_testTaskPruss_th, NULL);
    pthread_join(ICSS_EMAC_testPort1TxTask_th, NULL);
    pthread_join(ICSS_EMAC_testPort2TxTask_th, NULL);

    pthread_attr_destroy(&pthread_attr);

    return(0);
}
#else
int main()
{
    Error_Block eb;
    Task_Params taskParams;
    int32_t ret = -1;
    Error_init(&eb);

    Board_initCfg cfg = BOARD_INIT_PLL| BOARD_INIT_MODULE_CLOCK |  BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;

    ret = Board_init(cfg);
    if (ret != BOARD_SOK)
    {
        PRINT("main: Board_init returned error code: %d\n", ret);
        return -2;
    }

    /* Switch the ICSS clock to 225MHz.
     * Limit it to EMAC switch tests as TTS verification depends on 200MHz clock */
#if defined(icev2AM335x) || defined(iceAMIC110)
#ifdef SWITCH_EMAC
    Board_PLLICSSConfig(BOARD_ICSS_PLL_CLK_225MHZ);
#endif
#endif

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create(ICSS_EMAC_testTaskPruss1, &taskParams, &eb);

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "ttsPort1TxTask";
    Task_create(ICSS_EMAC_testPort1TxTask, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "ttsPort2TxTask";
    Task_create(ICSS_EMAC_testPort2TxTask, &taskParams, &eb);
#endif

    ICSS_EMAC_testPruIcssInstanceSetup();

    BIOS_start();
    return(0);
}
#endif




