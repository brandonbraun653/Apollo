/**
 * @file   main_poll_test.c
 *
 * @brief  This file tests the ICSS-EMAC driver APIs in Poll Mode
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

#include <xdc/std.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Cache.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>

#include <ti/csl/soc.h>
#include <ti/csl/csl_armGicAux.h>


#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>


#include <ti/drv/icss_emac/test/src/test_common_utils.h>

#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwConfig.h>

extern int ICSS_EMAC_testAM572xSetup(uint32_t boardType, uint32_t numPorts);

extern uint8_t ICSS_EMAC_testPkt[];
extern uint32_t ICSS_EMAC_testTotalPktRcvd;


PRUICSS_Handle ICSS_EMAC_testPruIcssHandle1 = NULL;
PRUICSS_Handle ICSS_EMAC_testPruIcssHandle2 = NULL;


extern ICSS_EmacHandle ICSS_EMAC_testHandle2;
extern ICSS_EmacHandle ICSS_EMAC_testHandle3;


extern uint8_t ICSS_EMAC_testLclMac2[];
extern uint8_t ICSS_EMAC_testLclMac3[];

extern uint32_t ICSS_EMAC_testPacketRcvdPort2;
extern uint32_t ICSS_EMAC_testPacketRcvdPort3;

extern uint32_t ICSS_EMAC_testLinkIsrPru2Eth0;
extern uint32_t ICSS_EMAC_testLinkIsrPru2Eth1;

extern uint8_t    ICSS_EMAC_testTtsModePort1;
extern uint8_t    ICSS_EMAC_testTtsModePort2;
/* either idkAM572x or idkAM571x */
uint8_t ICSS_EMAC_testEvmType = 0;

int32_t ICSS_EMAC_testPruIcssInstance2Setup(void)
{
    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    PRUICSS_Config  *cfg;
    ICSS_EmacInitConfig* icss_emacTestInitCfg0;
    ICSS_EmacInitConfig* icss_emacTestInitCfg1;
    

    ICSS_EmacFwStaticMmap *pIcssEmacStaticMMap;
    ICSS_EmacFwDynamicMmap *pIcssEmacDynamicMMap;
     int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        return (ret);
    }
    ICSS_EMAC_testPruIcssHandle2 = PRUICSS_create((PRUICSS_Config*)cfg,PRUICCSS_INSTANCE_TWO);

    /*PRU2 ETH0 initializations*/
    ICSS_EMAC_testHandle2 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle2 == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

    icss_emacTestInitCfg0->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    icss_emacTestInitCfg0->portMask = ICSS_EMAC_MODE_MAC1;
    icss_emacTestInitCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    icss_emacTestInitCfg0->halfDuplexEnable = 0;
    icss_emacTestInitCfg0->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    icss_emacTestInitCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE2;
    icss_emacTestInitCfg0->pacingThreshold = 0;
    icss_emacTestInitCfg0->learningEn = 0;
    icss_emacTestInitCfg0->macId = ICSS_EMAC_testLclMac2;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle2,2);
    icss_emacTestInitCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->emacInitcfg = icss_emacTestInitCfg0;

     if (icss_emacGetFwMMapInitConfig(1, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        UART_printf("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
        return -1;
    }

    icss_emacSetFwMMapInitConfig(ICSS_EMAC_testHandle2, 1, pIcssEmacStaticMMap, pIcssEmacDynamicMMap);

    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    /* Test ICSS_EmacDeInit */
    ICSS_EmacDeInit(ICSS_EMAC_testHandle2,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(ICSS_EMAC_testHandle2,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacRegisterPort0ISRCallback(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testLinkIsrCb, (void*)ICSS_EMAC_TEST_PRU2ETH0);
    ICSS_EmacRegisterHwIntRx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket2);
    ICSS_EmacRegisterHwIntTx(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
    ICSS_EmacRegisterHwIntTTSCyc(ICSS_EMAC_testHandle2, (ICSS_EmacCallBack)ICSS_EMAC_testTtsCycPort1Callback);
    /*PRU2 ETH1 initializations*/
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
    icss_emacTestInitCfg1->pacingThreshold = 100;
    icss_emacTestInitCfg1->learningEn = 0;

    icss_emacTestInitCfg1->macId = ICSS_EMAC_testLclMac3;

    ICSS_EMAC_testDrvInit(ICSS_EMAC_testHandle3, 2);

    /*    Enable interrupt mode for TTS Cyclic Packet    */
    icss_emacTestInitCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE;

    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->pruIcssHandle = ICSS_EMAC_testPruIcssHandle2;
    ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->emacInitcfg = icss_emacTestInitCfg1;
    
    if (icss_emacGetFwMMapInitConfig(1, &pIcssEmacStaticMMap, &pIcssEmacDynamicMMap) != 0)
    {
        UART_printf("ICSS_EMAC_testPruIcssInstance2Setup: invalid instance Id when calling icss_emacGetFwStaticConfig\n");
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
    ICSS_EMAC_testTimerSetup(ICSS_EMAC_testHandle2);

    return 0;
}


    Error_Block eb;
    Task_Params taskParams;
int main()
{
    Board_IDInfo info;
    Board_STATUS boardInitStatus =0;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;

    Error_init(&eb);
    boardInitStatus  = Board_init(cfg);

    if (boardInitStatus !=0)
    {
        printf("Board_init failure\n");
        return(0);
    }

    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);
    UART_printf("boardName: %s\n", info.boardName);
    if (!(strcmp(info.boardName, "AM571IDK")))
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM571x;
    }
    else if (!(strcmp(info.boardName, "AM572IDK")))
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM572x;
    }
    else
    {
        ICSS_EMAC_testEvmType =ICSS_EMAC_TEST_BOARD_IDKAM574x;
     }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "SwitchTask2";
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testTaskPruss2, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "PollControlTask";
    taskParams.stackSize = 0x1000;
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testPollControlTask, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port1TxTask";
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testPort1TxTask, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "Port2TxTask";
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testPort2TxTask, &taskParams, &eb);

    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
}



