/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Cache.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Core.h>

#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/stkmain.h>

#include <ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>

#include <ti/transport/ndk/nimu_icss/nimu_icssEth.h>
#include <ti/transport/ndk/nimu_icss/example/src/osdrv_ndkdeviceconfig.h>

#include <ti/board/board.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/hw/hw_control_am43xx.h>

PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;
ICSS_EmacHandle emachandle1;

ICSS_EmacInitConfig* switchEmacCfg;
ICSS_EmacInitConfig* switchEmacCfg1;

uint8_t lclMac[6];
uint8_t lclMac1[6];

extern void cclink_thread (UArg a0, UArg a1);

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr);
uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance);


/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/

/* PRUICSS objects */
PRUICSS_V1_Object prussObjects[2];

/*
 *    ---task to initialize PRU---
 */
Void taskPruss(UArg a0, UArg a1)
{
    Uint8 firmwareLoad_done = FALSE;
    Uint8 count = 0;
    static Uint8 pktReceived = 0;

    while(GetNdkStatus(0)== NIMU_STAT_PROGRESS || GetNdkStatus(0)==NIMU_STAT_UNKNOWN)
    {
        Task_sleep(100);
    }


    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);
    if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                             (uint32_t *) &pru_imem0_rev1_start,
                             &pru_imem0_rev1_end - &pru_imem0_rev1_start))
     {
         if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                             (uint32_t *) &pru_imem1_rev1_start,
                             &pru_imem1_rev1_end - &pru_imem1_rev1_start))
    
         {
             firmwareLoad_done = TRUE;
         }
     }

    if( firmwareLoad_done)
    {
        PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_2-1);
    }
}

/*
 *  ======== main ========
 */
int main()
{ 
    Error_Block eb;
    Task_Params taskParams;
    int32_t ret;
    PRUICSS_Config  *pruIcssCfg;
    Error_init(&eb);

    Board_initCfg cfg = BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
    ret = Board_init(cfg);
    if (ret != BOARD_SOK)
    {
        UART_printf("main: Board_init returned error code: %d\n", ret);
        return -2;
    }
    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICCSS_INSTANCE_TWO);


    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create(taskPruss, &taskParams, &eb);

    /*Port I initializations*/
    emachandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    switchEmacCfg = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((emachandle == NULL) || (switchEmacCfg == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }
    switchEmacCfg->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
    switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE1;
    switchEmacCfg->halfDuplexEnable = 1;
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    switchEmacCfg->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;
    switchEmacCfg->rxIntNum = 52;
    switchEmacCfg->linkIntNum=58;
    SOCCtrlGetPortMacAddr(1,lclMac);
    switchEmacCfg->macId = lclMac;
    ICSSEmacDRVInit(emachandle, 1);     // ICSS_M instance 0
   

    ((ICSS_EmacObject*)emachandle->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle->object)->emacInitcfg = switchEmacCfg;

    /*PORT2 Initializations*/
    emachandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    switchEmacCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((emachandle1 == NULL) || (switchEmacCfg1 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }
    
    switchEmacCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->halfDuplexEnable = 1;
    switchEmacCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg1->learningEn = 0;
    switchEmacCfg1->rxIntNum = 53;
    switchEmacCfg1->linkIntNum=59;
    SOCCtrlGetPortMacAddr(2,lclMac1);
    switchEmacCfg1->macId = lclMac1;

    ICSSEmacDRVInit(emachandle1,1); 	// ICSS_M instance 0


    ((ICSS_EmacObject*)emachandle1->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle1->object)->emacInitcfg = switchEmacCfg1;

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

    ICSS_EmacInit(emachandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle;

    ((ICSS_EmacObject*)emachandle->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);


    if(((ICSS_EmacObject*)emachandle->object)->rxTaskHandle==NULL)
    {
        UART_printf("main: Task_create rturned NULL handle\n");
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle;
    ((ICSS_EmacObject*)emachandle->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)emachandle->object)->linkTaskHandle==NULL)
    {
        UART_printf("main: Task_create rturned NULL handle\n");
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle1;

    ((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);


    if(((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle==NULL)
    {
        UART_printf("main: Task_create rturned NULL handle\n");
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle1;
    ((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle==NULL)
    {
        UART_printf("main: Task_create rturned NULL handle\n");
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 4;
    taskParams.stackSize = 0x1400;
    Task_create (cclink_thread, &taskParams, NULL);
    
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle) == 0)
			BIOS_exit(0);
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle1) == 0)
			BIOS_exit(0);

    BIOS_start();
    return(0);
}


#define CTRL_MAC_ID0_LO                                             (0x630U)
#define CTRL_MAC_ID0_HI                                             (0x634U)
#define CTRL_MAC_ID1_LO                                             (0x638U)
#define CTRL_MAC_ID1_HI                                             (0x63cU)


void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    switch(portNum)
    {
        case 1U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_47_40);
            break;

        case 2U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_47_40);
            break;

        default:
            break;
    }
}



uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance)
{
    /* LLD attributes mallocs */
    handle->object = (ICSS_EmacObject*)malloc(sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)malloc(sizeof(ICSS_EmacHwAttrs));

    /* Callback mallocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)malloc(sizeof(ICSS_EmacCallBackObject));

    callBackObj->learningExCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxRTCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->txCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    ((ICSS_EmacObject*)handle->object)->callBackHandle = callBackObj;

    /*Allocate memory for learning*/
    ((ICSS_EmacObject*)handle->object)->macTablePtr = (HashTable_t*)malloc(NUM_PORTS * sizeof(HashTable_t));

    /*Allocate memory for PRU Statistics*/
    ((ICSS_EmacObject*)handle->object)->pruStat = (ICSS_EmacPruStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacPruStatistics_t));

    /*Allocate memory for Host Statistics*/
    ((ICSS_EmacObject*)handle->object)->hostStat = (ICSS_EmacHostStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacHostStatistics_t));

    /*Allocate memory for Storm Prevention*/
    ((ICSS_EmacObject*)handle->object)->stormPrevPtr = (stormPrevention_t*)malloc(NUM_PORTS * sizeof(stormPrevention_t));

    /* Base address initialization */
    if(NULL == ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg) {
        ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg =
                        (ICSS_EmacBaseAddressHandle_T)malloc(sizeof(ICSS_EmacBaseAddrCfgParams));
    }
    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;

    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );

    /*  Restricting l3OcmcBaseAddr to 0x40xxxx00.
     *  This is done because L3 OCMC Base Address must be 256 byte aligned and to support OCMC memory usage for Linux Power Management.
    */
    emacBaseAddr->l3OcmcBaseAddr =  (((emacBaseAddr->l3OcmcBaseAddr)&0xFFFF00)|0x40000000);
    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );

    return (0);


}



