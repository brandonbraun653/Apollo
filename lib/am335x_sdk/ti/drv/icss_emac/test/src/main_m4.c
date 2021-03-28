/**
 * @file   main_m4.c
 *
 * @brief  This file tests the ICSS-EMAC driver APIs on idkAM47x M4 core
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

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Cache.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>
#include <ti/sysbios/utils/Load.h>

#include <ti/csl/soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>


#include <ti/drv/icss_emac/test/src/test_common_utils.h>
#ifdef SWITCH_EMAC
#include <ti/drv/icss_emac/test/src/tiswitch_pruss_intc_mapping.h>
#else
#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#endif
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwConfig.h>

/* either idkAM572x or idkAM571x */
uint8_t ICSS_EMAC_testICSS_EMAC_testEvmType = 0;
//#define EMAC_BENCHMARK

#ifdef EMAC_BENCHMARK
volatile uint32_t *counter_32khz = (uint32_t *) 0x4AE04030;
#define ICSS_EMAC_TEST_BENCHMARK_RX_PKT_COUNT 100000U
#define ICSS_EMAC_TEST_BENCHMARK_32K_COUNT 32000U
uint32_t totalPktLength = 0;
uint32_t totalPktCount = 0;
uint32_t cpu_load = 0;

void cpu_load_task(UArg arg0, UArg arg1);
void app_stats(UArg arg0, UArg arg1);
void app_recv_cb(void* queueNum, void* ICSS_EmacSubSysHandle);
void ICSS_EMAC_testTaskPruss2BenchMark(UArg a0, UArg a1);
#endif

extern uint8_t ICSS_EMAC_testPkt[];
extern uint32_t ICSS_EMAC_testTotalPktRcvd;

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


extern uint32_t ICSS_EMAC_testPacketRcvdPort2;
extern uint32_t ICSS_EMAC_testPacketRcvdPort3;

extern uint8_t ICSS_EMAC_testPacketArrayInstance2[];

uint8_t ICSS_EMAC_testEvmType = 0;





#ifdef EMAC_BENCHMARK
/*
 *    ---task to initialize PRU---
 */
void ICSS_EMAC_testTaskPruss2BenchMark(UArg a0, UArg a1)
{
    uint32_t ICSS_EMAC_testPgVersion = 0;
    Uint8 retVal = FALSE;
    uint32_t count = 0;
    ICSS_EmacTxArgument txArgs;


    ICSS_EMAC_testPgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);


    retVal = ICSS_EMAC_testIMemInit(ICSS_EMAC_testPruIcssHandle2);
    if (!retVal)
        return;
    retVal = ICSS_EMAC_testDMemInit(ICSS_EMAC_testPruIcssHandle2);

    if( retVal)
    {
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
    }

    while (!(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] || ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0]))
    {
        UART_printf("ICSS_EMAC_testTaskPruss2Temp: link down\n");
        Task_sleep(100);
    }

    UART_printf("benchmark: link is finally up \n");
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle2, app_recv_cb);
    
}
#endif


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

    Task_Params taskParams;
    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);

    ICSS_EMAC_testPruIcssHandle1 = PRUICSS_create((PRUICSS_Config*) cfg,PRUICCSS_INSTANCE_ONE);

    /* PRUSS Internal PINMUX settings for AM571x */
    if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
    {
        PRUICSS_setGpMuxSel(ICSS_EMAC_testPruIcssHandle1, PRUICCSS_PRU1, 4);
    }

    /* For PRU1 Eth0 */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_IPU2_IRQ_69, CSL_XBAR_PRUSS1_IRQ_HOST8);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_70, CSL_XBAR_PRUSS1_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_71, CSL_XBAR_PRUSS1_IRQ_HOST4);  /* TX PKT ISR */

#ifndef SWITCH_EMAC	
    /* For PRU1 Eth1 */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_75, CSL_XBAR_PRUSS1_IRQ_HOST9);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_78, CSL_XBAR_PRUSS1_IRQ_HOST3);  /* RX PKT ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_79, CSL_XBAR_PRUSS1_IRQ_HOST5);  /* TX PKT ISR */
#endif

    /*PRU1ETH 0 initializations*/
    ICSS_EMAC_testHandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((ICSS_EMAC_testHandle == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        UART_printf("main: malloc returned null\n");
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
    icss_emacTestInitCfg0->learningEn = 1;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#else
	icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#endif
    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle,1);



#ifndef SWITCH_EMAC	
    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

    icss_emacTestInitCfg0->linkIntNum=69;
    icss_emacTestInitCfg0->rxIntNum = 70;
    icss_emacTestInitCfg0->txIntNum = 71;


    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->emacInitcfg = icss_emacTestInitCfg0;



    if (icss_emacGetFwMMapInitConfig(0, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        UART_printf("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
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
        UART_printf("main: malloc returned null\n");
    }

    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = 0;
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle1, 1);


    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

    icss_emacTestInitCfg1->linkIntNum=75;
    icss_emacTestInitCfg1->rxIntNum = 78;
    icss_emacTestInitCfg1->txIntNum = 79;
    
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->emacInitcfg = icss_emacTestInitCfg1;

    if (icss_emacGetFwMMapInitConfig(0, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        UART_printf("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
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
#endif


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
    Task_Params taskParams;

    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        return (ret);
    }

    ICSS_EMAC_testPruIcssHandle2 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_TWO);

    /* Crosssbar confiiguration */
    /* For PRU2 Eth0 */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_27, CSL_XBAR_PRUSS2_IRQ_HOST8);  /* link ISR */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_28, CSL_XBAR_PRUSS2_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_48, CSL_XBAR_PRUSS2_IRQ_HOST4);  /* TX PKT ISR */

#ifndef SWITCH_EMAC	
    /* For PRU2 Eth1 */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_29, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_30, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_49, CSL_XBAR_PRUSS2_IRQ_HOST5);  /* TX PKT ISR */
#endif

    /*Port I initializations*/
    ICSS_EMAC_testHandle2 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle2 == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

#ifdef SWITCH_EMAC	
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->phyAddr[1]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_SWITCH;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE4;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg0->learningEn = 1;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#else
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle2, 2);

    icss_emacTestInitCfg0->linkIntNum=27;
    icss_emacTestInitCfg0->rxIntNum = 28;
    icss_emacTestInitCfg0->txIntNum = 48;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->emacInitcfg = icss_emacTestInitCfg0;

#ifndef SWITCH_EMAC	
    /*PORT2 Initializations*/
    ICSS_EMAC_testHandle3 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle3 == NULL) || (icss_emacTestInitCfg1 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

    icss_emacTestInitCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;

    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;

    icss_emacTestInitCfg1->learningEn = 0;

    ICSS_EMAC_testSocCtrlGetPortMacAddr(1,ICSS_EMAC_testLclMac3);
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac3;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle3, 2);

    icss_emacTestInitCfg1->linkIntNum=29;
    icss_emacTestInitCfg1->rxIntNum = 30;
    icss_emacTestInitCfg1->txIntNum = 49;
    
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->emacInitcfg = icss_emacTestInitCfg1;
#endif

#ifdef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_SWITCH);
#else
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1);
#endif

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH0);
#ifdef SWITCH_EMAC	
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
#endif
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket2);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
    
#ifndef SWITCH_EMAC	
    ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2);
    ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket3);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
#endif

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);


    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
#ifndef SWITCH_EMAC
#ifdef EMAC_BENCHMARK
    Task_Params_init(&taskParams);
    taskParams.instance->name = "CPU_LOAD";
    taskParams.priority = 9;
    Task_create(cpu_load_task, &taskParams,NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 9;
    taskParams.instance->name = "EmacStats";
    Task_create(app_stats, &taskParams, NULL);
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

     if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle==NULL)
    {
        return -2;
    }
#endif
#endif

    PRUICSS_pinMuxConfig(ICSS_EMAC_testPruIcssHandle2, 0x0); // PRUSS pinmuxing
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle2);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle2);

#ifndef SWITCH_EMAC
#ifndef EMAC_BENCHMARK
    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle3);
    ICSS_EMAC_testInterruptEnable(ICSS_EMAC_testHandle3);
#endif
#endif
    return (ret);
}
int main()
{
    Board_IDInfo info;
    Error_Block eb;
    Task_Params taskParams;
    uint32_t numPorts = 2;
    Board_STATUS boardStatus = 0;
    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_ICSS_ETH_PHY | BOARD_INIT_MODULE_CLOCK;

    Error_init(&eb);

    boardStatus = Board_init(cfg);
    if (boardStatus != BOARD_SOK)
    {
        return(0);
    }
    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);
    UART_printf("boardName: %s\n", info.boardName);
    if (!(strcmp(info.boardName, "AM571IDK")))
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM571x;
        UART_printf("board type is AM571IDK, numPorts: %d\n", numPorts);
    }
    else if (!(strcmp(info.boardName, "AM572IDK")))
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM572x;
        UART_printf("board type is AM572IDK, numPorts: %d\n", numPorts);
    }
    else
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM574x;
        UART_printf("board type is AM574IDK, numPorts: %d\n", numPorts);
     }
#if defined (idkAM571x)
#ifndef SWITCH_EMAC
        Task_Params_init(&taskParams);
        taskParams.priority = 10;
        taskParams.instance->name = "SwitchTask1";
        Task_create(ICSS_EMAC_testTaskPruss1, &taskParams, &eb);
    
        ICSS_EMAC_testPruIcssInstance1Setup();
#endif
#endif

#ifndef EMAC_BENCHMARK
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create(ICSS_EMAC_testTaskPruss2, &taskParams, &eb);
#else
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create(ICSS_EMAC_testTaskPruss2BenchMark, &taskParams, &eb);
#endif

    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
}

#ifdef EMAC_BENCHMARK
void cpu_load_task(UArg arg0, UArg arg1)
{
    UInt32 load;

    while(1)
    {
        load = Load_getCPULoad();
        if (load > cpu_load)
            cpu_load = load;
        Task_sleep(1000);
    }
}

void app_recv_cb(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    static uint32_t start = 0;
    static uint32_t end = 0;
    char *pPayload;
    uint16_t payload;
    uint8_t         j;
    uint32_t        tmp;
    int32_t         packetLength;
    ICSS_EmacRxArgument rxArgs;
    ICSS_EmacPktInfo rxPktInfo;
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle) ICSS_EmacSubSysHandle;
    rxArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
    rxArgs.queueNumber = *((uint32_t *)(queueNum));
    rxArgs.more = 0;
    rxArgs.port = 0;
    rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testPacketArrayInstance2[0]);

    for (tmp = 1; tmp; )
    {
        memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));

        totalPktLength += ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);

        if (totalPktCount == 0)
        {
            start = *counter_32khz;
            UART_printf("starting timer using 32Khz clock\n");
        }

        if ((++totalPktCount) >=  ICSS_EMAC_TEST_BENCHMARK_RX_PKT_COUNT)
        {
            end = *counter_32khz;
            UART_printf("num packets: %u, totalPktLen: %u, start: %u, end: %u\n",
                        totalPktCount, totalPktLength, start, end);
            start = 0;
            end = 0;
            totalPktCount = 0;
            totalPktLength = 0;

        }
        ICSS_EmacRxPktGet(&rxArgs, NULL);
        if(rxArgs.more== 0)
        {
            tmp = 0;    // exit if there are no more packets
        }
    }
}

void app_stats(UArg arg0, UArg arg1)
{

    while(1)
    {
        if(ICSS_EMAC_testHandle2)
        {
            UART_printf("\n--------------------------------------------------------------------------------------\n");
            ICSS_EMAC_testGetPruStats(2, ICSS_EMAC_testHandle2);
            UART_printf("MAX CPU load: %u\n", cpu_load);
            UART_printf("--------------------------------------------------------------------------------------\n");
    
            Task_sleep(10000);
        }
    }
}
#endif

