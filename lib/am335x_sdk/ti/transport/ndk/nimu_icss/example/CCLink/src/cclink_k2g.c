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

#include <ti/csl/soc.h>
#ifdef __ARM_ARCH_7A__
#include <ti/csl/csl_armGicAux.h>
#endif
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/board/board.h>

#include<ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include<ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>

#include<ti/transport/ndk/nimu_icss/nimu_icssEth.h>
#include<ti/transport/ndk/nimu_icss/example/src/osdrv_ndkdeviceconfig.h>

#ifdef _TMS320C6X
#include <ti/sysbios/family/c66/Cache.h>
#endif
PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;
ICSS_EmacHandle emachandle1;


uint8_t lclMac[6];
uint8_t lclMac1[6];

extern void cclink_thread (UArg a0, UArg a1);

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr);
uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance);
extern ICSS_EmacBaseAddrCfgParams icss_EmacBaseAddrCfgParams[2];

/***********************************************************************/
/* local functions declaration                                         */
/***********************************************************************/

/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/

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
    uint32_t pgVersion;

    while(GetNdkStatus(0)== NIMU_STAT_PROGRESS || GetNdkStatus(0)==NIMU_STAT_UNKNOWN)
    {
        Task_sleep(100);
    }
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);

    if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                                  (uint32_t *) &pru_imem0_rev2_start,
                                  &pru_imem0_rev2_end - &pru_imem0_rev2_start))
    {
        if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                      (uint32_t *) &pru_imem1_rev2_start,
                                      &pru_imem1_rev2_end - &pru_imem1_rev2_start))
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

    Board_initCfg cfg;
    memset(&cfg, 0, sizeof(Board_initCfg));
    cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY ;
    Error_init(&eb);
    Board_init(cfg);

#ifdef _TMS320C6X
    /* Disable L1 Data Cache */
    Cache_disable(Cache_Type_L1D);
#endif
    pruss_iep_Initialization(1);
    pruss_iep_Initialization(2);

    pruss_iep_MDIOInitialization(1);
    pruss_iep_MDIOInitialization(2);


   ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICCSS_INSTANCE_TWO);

    /* Need to explicitly set MII mode for K2G in GPCFG registers*/
    PRUICSS_setGpMuxSel(pruIcssHandle, PRUICCSS_PRU0, 2);
    PRUICSS_setGpMuxSel(pruIcssHandle, PRUICCSS_PRU1, 2);
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create(taskPruss, &taskParams, &eb);

    /*PRU2ETH0*/
    emachandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg;
    switchEmacCfg = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    switchEmacCfg->phyAddr[0]=BOARD_ICSS_EMAC_PORT2_PHY_ADDR;
    switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
    switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE1;


    switchEmacCfg->halfDuplexEnable = 1;
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    switchEmacCfg->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;
    SOCCtrlGetPortMacAddr(0,lclMac);
    switchEmacCfg->macId = lclMac;

    ICSSEmacDRVInit(emachandle, 2); 	// ICSS_M instance 0

#if defined (__ARM_ARCH_7A__)
    switchEmacCfg->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT6);
    switchEmacCfg->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT0);
    switchEmacCfg->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT2);
#else
    switchEmacCfg->linkIntNum= CSL_CIC_ICSSM1_HOST_INT6;
    switchEmacCfg->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT48;
    switchEmacCfg->intrMuxCfgLink.intcMuxNum = 0;
    switchEmacCfg->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT6;
    switchEmacCfg->intrMuxCfgLink.intcMuxOutEvent= 48; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT48 */

    switchEmacCfg->rxIntNum = CSL_CIC_ICSSM1_HOST_INT0;
    switchEmacCfg->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT49;
    switchEmacCfg->intrMuxCfgRxPkt.intcMuxNum = 0;
    switchEmacCfg->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT0;
    switchEmacCfg->intrMuxCfgRxPkt.intcMuxOutEvent= 49; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT49 */

    switchEmacCfg->txIntNum = CSL_CIC_ICSSM1_HOST_INT2;
    switchEmacCfg->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT50;
    switchEmacCfg->intrMuxCfgTxComplete.intcMuxNum = 0;
    switchEmacCfg->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT2;
    switchEmacCfg->intrMuxCfgTxComplete.intcMuxOutEvent= 50; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT50 */
#endif

    ((ICSS_EmacObject*)emachandle->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle->object)->emacInitcfg = switchEmacCfg;


    /*PRU2ETH1 Initializations*/
    emachandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg1;
    switchEmacCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    switchEmacCfg1->phyAddr[0]= BOARD_ICSS_EMAC_PORT3_PHY_ADDR;

    switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;

    switchEmacCfg1->learningEn = 0;

    SOCCtrlGetPortMacAddr(1,lclMac1);
    switchEmacCfg1->macId = lclMac1;

    ICSSEmacDRVInit(emachandle1, 2); 	// ICSS_M instance 0

#if defined (__ARM_ARCH_7A__)
    switchEmacCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT7);      /* CSL_ARM_GIC_ICSSM1_HOST_INT7 == 0xEF (239) */
    switchEmacCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT1);
    switchEmacCfg1->txIntNum = CSL_armGicGetGicIdForIrqInputLine(CSL_ARM_GIC_ICSSM1_HOST_INT3);
#else
    switchEmacCfg1->linkIntNum= CSL_CIC_ICSSM1_HOST_INT7;
    switchEmacCfg1->intrMuxCfgLink.eventId = CSL_C66X_COREPAC_CIC_0_OUT51;
    switchEmacCfg1->intrMuxCfgLink.intcMuxNum = 0;
    switchEmacCfg1->intrMuxCfgLink.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT7;
    switchEmacCfg1->intrMuxCfgLink.intcMuxOutEvent= 51; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT51 */

    switchEmacCfg1->rxIntNum = CSL_CIC_ICSSM1_HOST_INT1;
    switchEmacCfg1->intrMuxCfgRxPkt.eventId = CSL_C66X_COREPAC_CIC_0_OUT52;
    switchEmacCfg1->intrMuxCfgRxPkt.intcMuxNum = 0;
    switchEmacCfg1->intrMuxCfgRxPkt.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT1;
    switchEmacCfg1->intrMuxCfgRxPkt.intcMuxOutEvent= 52; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT52 */

    switchEmacCfg1->txIntNum = CSL_CIC_ICSSM1_HOST_INT3;
    switchEmacCfg1->intrMuxCfgTxComplete.eventId = CSL_C66X_COREPAC_CIC_0_OUT53;
    switchEmacCfg1->intrMuxCfgTxComplete.intcMuxNum = 0;
    switchEmacCfg1->intrMuxCfgTxComplete.intcMuxInEvent= CSL_CIC_ICSSM1_HOST_INT3;
    switchEmacCfg1->intrMuxCfgTxComplete.intcMuxOutEvent= 53; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT53 */
#endif

    ((ICSS_EmacObject*)emachandle1->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle1->object)->emacInitcfg = switchEmacCfg1;

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(emachandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);




    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)emachandle;

    ((ICSS_EmacObject*)emachandle->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)emachandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }
    
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port2_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle;

    ((ICSS_EmacObject*)emachandle->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)emachandle->object)->linkTaskHandle==NULL)
    {
        return -2;
    }



    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x3000;
    taskParams.arg0 = (UArg)emachandle1;
    ((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle = Task_create(ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = (char*)"port3_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle1;

    ((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle = Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 4;
    taskParams.stackSize = 0x1400;
    Task_create (cclink_thread, &taskParams, NULL);

    PRUICSS_pinMuxConfig(pruIcssHandle, 0x0); // PRUSS pinmuxing
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle) == 0)
        BIOS_exit(0);
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle1) == 0)
            BIOS_exit(0);
    BIOS_start();
    return(0);
}

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{

    uint32_t mac_addr2, mac_addr1;
    CSL_BootCfgGetMacIdentifier(&mac_addr1, &mac_addr2);
    pMacAddr[0U] = ((mac_addr2 & 0x0000ff00) >> 8);
    pMacAddr[1U] =  (mac_addr2 & 0x000000ff);
    pMacAddr[2U] = ((mac_addr1 & 0xff000000) >> 24);
    pMacAddr[3U] = ((mac_addr1 & 0x00ff0000) >> 16);
    pMacAddr[4U] = ((mac_addr1 & 0x0000ff00) >> 8);
    pMacAddr[5U]=  (mac_addr1 & 0x000000ff);

}

uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance) {
    uint8_t retVal = -1;

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

    ICSS_EmacSocGetInitCfg(instance, emacBaseAddr );

    return 0U;
}

