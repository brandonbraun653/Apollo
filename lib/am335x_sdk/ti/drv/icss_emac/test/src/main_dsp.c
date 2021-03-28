/**
 * @file   main_dsp.c
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
 */

#include <xdc/std.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>

#include <ti/csl/soc.h>



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

#ifdef _TMS320C6X
#include <ti/sysbios/family/c66/Cache.h>
#endif

int32_t boardInitStatus =-1;


extern uint8_t ICSS_EMAC_testPkt[];
extern uint32_t ICSS_EMAC_testTotalPktRcvd;

/* total number of packets received on all interfaces being tested, cummulative account */

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

/* either idkAM572x or idkAM571x */
uint8_t ICSS_EMAC_testEvmType = 0;



/*
 *  ======== main ========
 */

int32_t ICSS_EMAC_testPruIcssInstance1Setup(void)
{

    Task_Params taskParams;
    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;

    PRUICSS_Config  *cfg;

     int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);

    ICSS_EMAC_testPruIcssHandle1 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_ONE);


    /* For PRU1 Eth0 */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_43, CSL_XBAR_PRUSS1_IRQ_HOST8);  /* link ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_44, CSL_XBAR_PRUSS1_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_45, CSL_XBAR_PRUSS1_IRQ_HOST4);  /* TX PKT ISR */

#ifndef SWITCH_EMAC
    /* For PRU1 Eth1 */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_48, CSL_XBAR_PRUSS1_IRQ_HOST9);  /* link ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_49, CSL_XBAR_PRUSS1_IRQ_HOST3);  /* RX PKT ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_50, CSL_XBAR_PRUSS1_IRQ_HOST5);  /* TX PKT ISR */
#endif

    /*PRU1ETH 0 initializations*/
    ICSS_EMAC_testHandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

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
    ICSS_EMAC_testSocCtrlGetPortMacAddr(0,ICSS_EMAC_testLclMac);
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#else
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 0;
    ICSS_EMAC_testSocCtrlGetPortMacAddr(0,ICSS_EMAC_testLclMac);
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle,1);

#ifndef SWITCH_EMAC	
    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

    icss_emacTestInitCfg0->linkIntNum=43;
    icss_emacTestInitCfg0->rxIntNum = 44;
    icss_emacTestInitCfg0->txIntNum = 45;


    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->emacInitcfg = icss_emacTestInitCfg0;

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

    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
    icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    icss_emacTestInitCfg1->phyAddr[0]= 1;
    icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = 0;
    ICSS_EMAC_testSocCtrlGetPortMacAddr(1,ICSS_EMAC_testLclMac1);
    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac1;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle1, 1);

    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

    icss_emacTestInitCfg1->linkIntNum=48;
    icss_emacTestInitCfg1->rxIntNum = 49;
    icss_emacTestInitCfg1->txIntNum = 50;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->emacInitcfg = icss_emacTestInitCfg1;

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
    //taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    //taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->txTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
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
    //taskParams.priority = 15;
    taskParams.instance->name = (char*)"port0_ttsCycTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTTSCycTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->ttsCycTaskHandle==NULL)
    {
        return -2;
    }
    
    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"port1_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->txTaskHandle==NULL)
    {
        return -2;
    }


    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle1;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
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
    Task_Params taskParams;
    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
#ifndef SWITCH_EMAC	
    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
#endif
    PRUICSS_Config  *cfg;

     int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);

    ICSS_EMAC_testPruIcssHandle2 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_TWO);


    /* For PRU2 Eth0 */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_76, CSL_XBAR_PRUSS2_IRQ_HOST8);  /* link ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_77, CSL_XBAR_PRUSS2_IRQ_HOST2);  /* RX PKT ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_78, CSL_XBAR_PRUSS2_IRQ_HOST4);  /* TX PKT ISR */

#ifndef SWITCH_EMAC	
    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        /* For PRU2 Eth1 */
        CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_89, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
        CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_90, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
        CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_93, CSL_XBAR_PRUSS2_IRQ_HOST5);  /* TX PKT ISR */
    }
#endif

    /*PRU2 ETH0 initializations*/
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
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE2;
    icss_emacTestInitCfg0->pacingThreshold = 100;
    icss_emacTestInitCfg0->learningEn = 1;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#else
    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 1;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;//ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;
#endif

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle2,2);

#ifndef SWITCH_EMAC	
    /*Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;
#endif

    icss_emacTestInitCfg0->linkIntNum=76;
    icss_emacTestInitCfg0->rxIntNum = 77;
    icss_emacTestInitCfg0->txIntNum = 78;
    
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
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
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

        /*PRU2 ETH1 initializations*/
        ICSS_EMAC_testHandle3 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));
        
        icss_emacTestInitCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle3 == NULL) || (icss_emacTestInitCfg1 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }
        icss_emacTestInitCfg1->phyAddr[0]= 1;
    
        icss_emacTestInitCfg1->portMask = ICSS_EMAC_MODE_MAC2;
        icss_emacTestInitCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
        icss_emacTestInitCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
        icss_emacTestInitCfg1->pacingThreshold = 100;
    
        icss_emacTestInitCfg1->learningEn = 0;
    
    
       icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac3;
    
        ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle3, 2);
    
        /*    Enable interrupt mode for TTS Cyclic Packet    */
        icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

        icss_emacTestInitCfg1->linkIntNum=89;
        icss_emacTestInitCfg1->rxIntNum = 90;
        icss_emacTestInitCfg1->txIntNum=93;

        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->emacInitcfg = icss_emacTestInitCfg1;
    
        ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        /* Test ICSS_EmacDeInit */
        ICSS_EmacDeInit(ICSS_EMAC_testHandle3, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        ICSS_EmacInit(ICSS_EMAC_testHandle3,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    
        ICSS_EmacRegisterPort1ISRCallback(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH1);
        ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket3);
        ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
        ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle3, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort2Callback);
#endif 
    
    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"port2_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"port2_txTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)ICSS_EMAC_testHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->txTaskHandle==NULL)
    {
        return -2;
    }


    Task_Params_init(&taskParams);
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
        taskParams.instance->name = (char*)"port3_rxTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
    
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->rxTaskHandle==NULL)
        {
            return -2;
        }

        Task_Params_init(&taskParams);
        taskParams.instance->name = (char*)"port3_txTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsTxTaskFnc, &taskParams, NULL);
    
    
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->txTaskHandle==NULL)
        {
            return -2;
        }


        Task_Params_init(&taskParams);
        taskParams.instance->name = (char*)"port3_linkTaskFnc";
        taskParams.stackSize = 0x1000;
        taskParams.arg0 = (UArg)ICSS_EMAC_testHandle3;
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);
    
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkTaskHandle==NULL)
        {
            return -2;
        }


        Task_Params_init(&taskParams);
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

    ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle2);

#ifndef SWITCH_EMAC	
    if ((ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM572x) || (ICSS_EMAC_testEvmType  == ICSS_EMAC_TEST_BOARD_IDKAM574x))
    {
        ICSS_EMAC_testInterruptInit(ICSS_EMAC_testHandle3);
    }
#endif

    return 0;
}

    Error_Block eb;
    Task_Params taskParams;
    
int main()
{
    Board_IDInfo info;
    uint32_t numPorts = 4;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;

    Error_init(&eb);
    boardInitStatus  = Board_init(cfg);

    if (boardInitStatus !=0)
    {
        UART_printf("Board_init failure\n");
        return(0);
    }

#ifdef _TMS320C6X
    /* Clear pre-fetch bit in MAR to make OCMC un-cacheable */
    Cache_setMar((xdc_Ptr)0x4b000000U, 0x10000U, 0);
    Cache_setMar((xdc_Ptr)0x40000000U, 0x10000U, 0);
#endif

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

#ifndef SWITCH_EMAC	
#if defined (idkAM571x)
    Task_Params_init(&taskParams);
    taskParams.instance->name = "SwitchTask1";
    Task_create(ICSS_EMAC_testTaskPruss1, &taskParams, &eb);

    ICSS_EMAC_testPruIcssInstance1Setup();
#endif
#endif

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.instance->name = "Port1TxTask";
    Task_create(ICSS_EMAC_testPort1TxTask, &taskParams, &eb);
#endif

    Task_Params_init(&taskParams);
    taskParams.instance->name = "SwitchTask2";
    Task_create(ICSS_EMAC_testTaskPruss2, &taskParams, &eb);

#ifndef SWITCH_EMAC	
    Task_Params_init(&taskParams);
    taskParams.instance->name = "Port2TxTask";
    Task_create(ICSS_EMAC_testPort2TxTask, &taskParams, &eb);
#endif

    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
}








