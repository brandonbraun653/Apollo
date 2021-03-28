/*
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
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
#include <debug.h>

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
#include <ti/starterware/include/board.h>
#include <ti/starterware/include/am335x/chipdb_defs.h>
#include <ti/starterware/include/hw/soc_am335x.h>


PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;
ICSS_EmacHandle emachandle1;

ICSS_EmacInitConfig* switchEmacCfg;
ICSS_EmacInitConfig* switchEmacCfg1;

uint8_t lclMac[6];
uint8_t lclMac1[6];

/* Static IP Address settings for interface 0 */
char *ipAddr      = "192.168.1.4";
char *ipMask      = "255.255.255.0";
char *ipGateway   = "192.168.1.1";

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr);
uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance);

extern char *LocalIPAddr;
/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/

/*
 * ======== stackInitHook ========
 * hook called from ti_nkd_config_Global_stackThread() to run user setup code
 */
void stackInitHook(void* hCfg)
{
    CI_IPNET NA;
    CI_ROUTE RT;

    /* Add IP address for interface 1 */
    NA.IPAddr = inet_addr(ipAddr);
    NA.IPMask = inet_addr(ipMask);
    CfgAddEntry(hCfg, CFGTAG_IPNET, 1, 0, sizeof(CI_IPNET),
            (uint8_t *)&NA, 0 );

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

/* PRUICSS objects */
PRUICSS_V1_Object prussObjects[2];

/*
 *	---task to initialize PRU---
 */
Void taskPruss(UArg a0, UArg a1)
{
	uint8_t firmwareLoad_done = FALSE;
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
 *  ======== TAskFxn: FTP server init task ========
 */
void TaskFxn(UArg a0, UArg a1)
{
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 0: %s\n\r", ipAddr);
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 1: %s\n\r", LocalIPAddr);
#ifdef NIMU_FTP_APP 
    ftpserver_init();
#endif
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
    
    Board_initCfg cfg = BOARD_INIT_PLL| BOARD_INIT_MODULE_CLOCK |  BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
    ret = Board_init(cfg);
    if (ret != BOARD_SOK)
    {
        UART_printf("main: Board_init returned error code: %d\n", ret);
        return -2;
    }
    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICCSS_INSTANCE_ONE);

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
    switchEmacCfg->rxIntNum = 20;
    switchEmacCfg->linkIntNum=26;
	SOCCtrlGetPortMacAddr(1,lclMac);
	switchEmacCfg->macId = lclMac;

	ICSSEmacDRVInit(emachandle, 0); 	// ICSS_M instance 0




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
    switchEmacCfg1->rxIntNum = 21;
    switchEmacCfg1->linkIntNum=27;


	SOCCtrlGetPortMacAddr(2,lclMac1);
	switchEmacCfg1->macId = lclMac1;

	ICSSEmacDRVInit(emachandle1,0); 	// ICSS_M instance 0

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
    taskParams.priority = 5;
    taskParams.stackSize = 0x1400;
    Task_create (TaskFxn, &taskParams, NULL);
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle) == 0)
        BIOS_exit(0);
    if(OSDRV_addNetifEntry((NIMUInitFn)&EmacInit,emachandle1) == 0)
            BIOS_exit(0);

    BIOS_start();
    return(0);
}


#define CONTROL_MAC_ID_LO(n)   (0x630 + (n * 8))
#define CONTROL_MAC_ID_HI(n)   (0x634 + (n * 8))
void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    uint32_t slavePortNum = portNum - 1U;

    pMacAddr[5U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[4U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum)))
                  & 0xFF;
    pMacAddr[3U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 24U) & 0xFFU;
    pMacAddr[2U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 16U) & 0xFFU;
    pMacAddr[1U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[0U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum)))
                  & 0xFFU;
}



uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance) {
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

        /*      Restricting l3OcmcBaseAddr to 0x40xxxx00.
         *  This is done because L3 OCMC Base Address must be 256 byte aligned and to support OCMC memory usage for Linux Power Management.
         */
        emacBaseAddr->l3OcmcBaseAddr =  (((emacBaseAddr->l3OcmcBaseAddr)&0xFFFF00)|0x40000000);

        ICSS_EmacSocSetInitCfg(instance, emacBaseAddr );
        return 0;
}



