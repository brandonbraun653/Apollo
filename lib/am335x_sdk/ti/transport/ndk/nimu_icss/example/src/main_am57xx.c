/*
 * Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>

#include <ti/csl/soc.h>
#ifdef __ARM_ARCH_7A__
#include <ti/csl/csl_armGicAux.h>
#endif
#include <ti/drv/uart/UART_stdio.h>
#include<ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>

#include<ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#include<ti/transport/ndk/nimu_icss/nimu_icssEth.h>
#include<ti/transport/ndk/nimu_icss/example/src/osdrv_ndkdeviceconfig.h>
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>

#include <ti/drv/icss_emac/test/src/fw_mem_section.h>



#ifdef _TMS320C6X
#include <ti/sysbios/family/c66/Cache.h>
#endif
#include <ti/board/board.h>

PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;
ICSS_EmacHandle emachandle1;
uint8_t lclMac[6];
uint8_t lclMac1[6];


extern char *LocalIPAddr;
extern ICSS_EmacBaseAddrCfgParams icss_EmacBaseAddrCfgParams[3];

/* Static IP Address settings for Interface 0 */
char *ipAddr      = "192.168.1.4";
char *ipMask      = "255.255.255.0";
char *ipGateway   = "192.168.1.1";

/***********************************************************************/
/* local functions declaration                                         */
/***********************************************************************/
uint8_t NIMU_ICSS_EmacTestDrvInit(ICSS_EmacHandle handle, uint8_t instance);
void NIMU_ICSS_EmacTestGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr);
void TaskFxn(UArg a0, UArg a1);
/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/

/*
 *    ---task to initialize PRU---
 */
Void NIMU_ICSS_EmacTestPruIcssInit(UArg a0, UArg a1)
{
    Uint8 firmwareLoad_done = FALSE;
    uint32_t pgVersion;
    while(NIMU_ICSS_getNdkStatus(0)== NIMU_STAT_PROGRESS || NIMU_ICSS_getNdkStatus(0)==NIMU_STAT_UNKNOWN)
    {
        Task_sleep(100);
    }
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);

#ifdef SOC_AM574x
/* The AM574x SOC is returning PG version as 0, but the actual Revision is 2.
 * So it is hardcoded as 2 for future reference.
 */
    pgVersion = 0x2;
#else
    pgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
    /*Added to fix warning*/
    pgVersion = pgVersion;
#endif

#ifdef SOC_AM572x
    if (pgVersion >= 2)
    {
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
    }
     else
    {
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
    }
#else
/* The PG version of AM571x and AM574x is REV2*/
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
#endif

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
    Board_IDInfo info;
    memset(&cfg, 0, sizeof(Board_initCfg));
    cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
    Error_init(&eb);
    Board_init(cfg);

    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);

    UART_printf("boardName: %s\n", info.boardName);

#ifdef _TMS320C6X
    /* Clear pre-fetch bit in MAR to make OCMC un-cacheable */
    Cache_setMar((xdc_Ptr)0x4b000000U, 0x10000U, 0);
    Cache_setMar((xdc_Ptr)0x40000000U, 0x10000U, 0);
#endif
    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICCSS_INSTANCE_TWO);

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "SwitchTask";
    Task_create((Task_FuncPtr)NIMU_ICSS_EmacTestPruIcssInit, &taskParams, &eb);

    /*Port I initializations*/
    emachandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg;
    switchEmacCfg = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((emachandle == NULL) || (switchEmacCfg == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

#ifdef _TMS320C6X
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_76, CSL_XBAR_PRUSS2_IRQ_HOST8);  /* link ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_77, CSL_XBAR_PRUSS2_IRQ_HOST2);  /* RX PKT ISR */
    switchEmacCfg->linkIntNum=76;
    switchEmacCfg->rxIntNum = 77;
    /* For PRU2 Eth0 */
#elif defined (__TI_ARM_V7M4__)
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_27, CSL_XBAR_PRUSS2_IRQ_HOST8);
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_28, CSL_XBAR_PRUSS2_IRQ_HOST2);
    switchEmacCfg->linkIntNum=27;
    switchEmacCfg->rxIntNum = 28;
#elif defined(__ARM_ARCH_7A__)
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_120, CSL_XBAR_PRUSS2_IRQ_HOST8);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_121, CSL_XBAR_PRUSS2_IRQ_HOST2);  /* RX PKT ISR */
    switchEmacCfg->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(120);
    switchEmacCfg->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(121);
#endif




    switchEmacCfg->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
    switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
    switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE1;
    switchEmacCfg->halfDuplexEnable = 1;
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;

    NIMU_ICSS_EmacTestGetPortMacAddr(0,lclMac);
    switchEmacCfg->macId = lclMac;

    NIMU_ICSS_EmacTestDrvInit(emachandle, 2);     // ICSS_M instance 0

    ((ICSS_EmacObject*)emachandle->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle->object)->emacInitcfg = switchEmacCfg;


    /*PORT2 Initializations*/
    emachandle1 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg1;
    switchEmacCfg1 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((emachandle1 == NULL) || (switchEmacCfg1 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

#ifdef _TMS320C6X
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_89, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_90, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
    switchEmacCfg1->linkIntNum=89;
    switchEmacCfg1->rxIntNum = 90;
#elif defined (__TI_ARM_V7M4__)
    /* For PRU2 Eth1 */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_29, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU2_IRQ_30, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
    switchEmacCfg1->linkIntNum=29;
    switchEmacCfg1->rxIntNum = 30;
#elif defined(__ARM_ARCH_7A__)
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_122, CSL_XBAR_PRUSS2_IRQ_HOST9);  /* link ISR */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_123, CSL_XBAR_PRUSS2_IRQ_HOST3);  /* RX PKT ISR */
    switchEmacCfg1->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(122);
    switchEmacCfg1->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(123);
#endif

    switchEmacCfg1->phyAddr[0]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
    switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg1->pacingThreshold = 100;
    switchEmacCfg1->learningEn = 0;

    NIMU_ICSS_EmacTestGetPortMacAddr(1,lclMac1);
    switchEmacCfg1->macId = lclMac1;

    NIMU_ICSS_EmacTestDrvInit(emachandle1, 2);

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

        ((ICSS_EmacObject*)emachandle->object)->rxTaskHandle = Task_create((Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)emachandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port0_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle;
    ((ICSS_EmacObject*)emachandle->object)->linkTaskHandle = Task_create((Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);

    if(((ICSS_EmacObject*)emachandle->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port1_rxTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle1;
    ((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle = Task_create((Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams, NULL);
    if(((ICSS_EmacObject*)emachandle1->object)->rxTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"port1_linkTaskFnc";
    taskParams.stackSize = 0x1000;
    taskParams.arg0 = (UArg)emachandle1;
    ((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle = Task_create((Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams, NULL);


    if(((ICSS_EmacObject*)emachandle1->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 5;
    taskParams.stackSize = 0x1400;
    Task_create ((Task_FuncPtr)TaskFxn, &taskParams, NULL);

    if(OSDRV_addNetifEntry((NIMUInitFn)&NIMU_ICSS_EmacInit,emachandle) == 0)
        BIOS_exit(0);
    if(OSDRV_addNetifEntry((NIMUInitFn)&NIMU_ICSS_EmacInit,emachandle1) == 0)
            BIOS_exit(0);



    BIOS_start();
    return(0);
}

void NIMU_ICSS_EmacTestGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    uint32_t tempVal;

    if(portNum == 0)
    {

        tempVal = HW_RD_REG32(0x4A002518);
        pMacAddr[0U] =  (uint8_t)((tempVal >> 16U) & 0xFFU);
        pMacAddr[1U] =  (uint8_t)((tempVal >> 8U) & 0xFFU);
        pMacAddr[2U] =  (uint8_t)(tempVal & 0xFFU);

        tempVal = HW_RD_REG32(0x4A002514);
        pMacAddr[3U] =  (uint8_t)((tempVal >> 16U) & 0xFFU);
        pMacAddr[4U] =  (uint8_t)((tempVal >> 8U) & 0xFFU);
        pMacAddr[5U] =  (uint8_t)(tempVal & 0xFFU);
     }
    else
    {
        tempVal = HW_RD_REG32(0x4A002520);
        pMacAddr[0U] =  (uint8_t)((tempVal >> 16U) & 0xFFU);
        pMacAddr[1U] =  (uint8_t)((tempVal >> 8U) & 0xFFU);
        pMacAddr[2U] =  (uint8_t)(tempVal  & 0xFFU);

        tempVal = HW_RD_REG32(0x4A00251c);
        pMacAddr[3U] =  (uint8_t)((tempVal >> 16U) & 0xFFU);
        pMacAddr[4U] =  (uint8_t)((tempVal >> 8U) & 0xFFU);
        pMacAddr[5U] =  (uint8_t)(tempVal & 0xFFU);
    }
}

uint8_t NIMU_ICSS_EmacTestDrvInit(ICSS_EmacHandle handle, uint8_t instance) {

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

    /*      Restricting l3OcmcBaseAddr to 0x40xxxx00.
      *  This is done because L3 OCMC Base Address must be 256 byte aligned and to support OCMC memory usage for Linux Power Management.
     */
    emacBaseAddr->l3OcmcBaseAddr =                                              (((emacBaseAddr->l3OcmcBaseAddr)&0xFFFF00)|0x40000000);
     
    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );
    return 0U;
}



    /*
     *  ======== TAskFxn: FTP server init task ========
     */
void TaskFxn(UArg a0, UArg a1)
{
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 0: %s\n\r", ipAddr);
    #ifdef idkAM572x
    	UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 1: %s\n\r", LocalIPAddr);
    #endif
    #ifdef NIMU_FTP_APP
        ftpserver_init();
    #endif
}
/*
 * ======== stackInitHook ========
 * hook called from ti_nkd_config_Global_stackThread() to run user setup code
 */
void stackInitHook(HANDLE hCfg)
{
    CI_IPNET NA;
    CI_ROUTE RT;

    /* Add IP address for interface 1 */
    NA.IPAddr = inet_addr(ipAddr);
    NA.IPMask = inet_addr(ipMask);
    CfgAddEntry(hCfg, CFGTAG_IPNET, 1, 0, sizeof(CI_IPNET),
                (uint8_t *)&NA, 0);

    /*
     * Add gateway for interface 1
     * --> I *think* the below should work but you may need different values ...
     */
    bzero(&RT, sizeof(RT));
    RT.IPDestAddr = 0;
    RT.IPDestMask = 0;
    RT.IPGateAddr = inet_addr(ipGateway);

    CfgAddEntry(hCfg, CFGTAG_ROUTE, 0, 0,
                sizeof(CI_ROUTE), (uint8_t *)&RT, 0);
}

