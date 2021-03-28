/*
 * Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/uart/UART_stdio.h>
#include<ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>

#include<ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#include<ti/transport/ndk/nimu_icss/nimu_icssEth.h>
#include<ti/transport/ndk/nimu_icss/example/src/osdrv_ndkdeviceconfig.h>

#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#include <ti\drv\icss_emac\firmware\icss_dualemac\bin\am65xx\a53_0\REV2\PRU0_bin.h>
#include <ti\drv\icss_emac\firmware\icss_dualemac\bin\am65xx\a53_0\REV2\PRU1_bin.h>
#include <ti/board/board.h>

#define BOARD_ICSS_EMAC_APP_BOARDID_ADDR   (0x52U)
#define BOARD_BOARD_NAME_LEN     (16U)

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
    while(NIMU_ICSS_getNdkStatus(0)== NIMU_STAT_PROGRESS || NIMU_ICSS_getNdkStatus(0)==NIMU_STAT_UNKNOWN)
    {
        Task_sleep(100);
    }
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);


    uint32_t result_flag = 0;
    result_flag = (PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_IRAM(0) , 0,
                              (uint32_t *) PRU0_b00,
                              sizeof(PRU0_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU0 passed\n");
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }
    result_flag = (PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_IRAM(1) , 0,
                                  (uint32_t *) PRU1_b00,
                                  sizeof(PRU1_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU1 passed\n");
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }

    if( result_flag)
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
    cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY | BOARD_INIT_ICSS_PINMUX;
    Error_init(&eb);
    Board_init(cfg);

    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICCSS_INSTANCE_TWO);
    mii_init();

    Board_STATUS status;
    Board_IDInfo_v2 info = {0};
    status = Board_getIDInfo_v2(&info, BOARD_ICSS_EMAC_APP_BOARDID_ADDR);

    UART_printf("\r\nBoard info return status = %d ", status);
    UART_printf("\r\nBoard Name           : ");
    UART_dataWrite((char *)&info.boardInfo.boardName, BOARD_BOARD_NAME_LEN);
    UART_printf("\r\nBuild Timestamp      : %s %s", __DATE__, __TIME__);

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

    switchEmacCfg->phyAddr[0]=0;
    switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
    switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE1;
    switchEmacCfg->halfDuplexEnable = 1;
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;
    switchEmacCfg->rxIntNum = 294;
    switchEmacCfg->linkIntNum=294+6;

    //NIMU_ICSS_EmacTestGetPortMacAddr(0,lclMac);
    memcpy(lclMac, &info.macInfo.macAddress[0], 6);
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

    switchEmacCfg1->phyAddr[0]=3;
    switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
    switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg1->pacingThreshold = 100;
    switchEmacCfg1->learningEn = 0;
    switchEmacCfg1->rxIntNum = 295;
    switchEmacCfg1->linkIntNum=295+6;

    memcpy(lclMac1, &info.macInfo.macAddress[1], 6);
    switchEmacCfg1->macId = lclMac1;

    NIMU_ICSS_EmacTestDrvInit(emachandle1, 2);

    ((ICSS_EmacObject*)emachandle1->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle1->object)->emacInitcfg = switchEmacCfg1;

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    ICSS_EmacInit(emachandle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
#if 1
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
#endif

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


int32_t ICSS_EMAC_testCallbackRxPacket2(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    UART_printf("packet received by host");
}

int32_t ICSS_EMAC_testCallbackTxComplete(void* ICSS_EmacSubSysHandle, void* queueNum)
{
    UART_printf("packet transmitted by host");
}

uint8_t NIMU_ICSS_EmacTestDrvInit(ICSS_EmacHandle handle, uint8_t instance) {
    uint8_t retVal = -1;

    /* LLD attributes mallocs */
    handle->object = (ICSS_EmacObject*)malloc(sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)malloc(sizeof(ICSS_EmacHwAttrs));
    memset(handle->object, 0, sizeof(ICSS_EmacObject));
    memset(handle->hwAttrs, 0, sizeof(ICSS_EmacHwAttrs));

    /* Callback mallocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)malloc(sizeof(ICSS_EmacCallBackObject));
    memset(callBackObj, 0, sizeof(ICSS_EmacCallBackObject));

    callBackObj->learningExCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxRTCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->txCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack->userArg=NULL;
    memset(callBackObj->learningExCallBack, 0, sizeof(ICSS_EmacCallBackConfig));
    memset(callBackObj->rxRTCallBack, 0, sizeof(ICSS_EmacCallBackConfig));
    memset(callBackObj->rxCallBack, 0, sizeof(ICSS_EmacCallBackConfig));
    memset(callBackObj->txCallBack, 0, sizeof(ICSS_EmacCallBackConfig));
    ICSS_EmacRegisterHwIntTx(handle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);

    ((ICSS_EmacObject*)handle->object)->callBackHandle = callBackObj;

    /*Allocate memory for learning*/
    ((ICSS_EmacObject*)handle->object)->macTablePtr = (HashTable_t*)malloc(NUM_PORTS * sizeof(HashTable_t));

    /*Allocate memory for PRU Statistics*/
    ((ICSS_EmacObject*)handle->object)->pruStat = (ICSS_EmacPruStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacPruStatistics_t));

    /*Allocate memory for Host Statistics*/
    ((ICSS_EmacObject*)handle->object)->hostStat = (ICSS_EmacHostStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacHostStatistics_t));

    /*Allocate memory for Storm Prevention*/
    ((ICSS_EmacObject*)handle->object)->stormPrevPtr = (stormPrevention_t*)malloc(NUM_PORTS * sizeof(stormPrevention_t));

   // ICSS_EmacRegisterHwIntRx(handle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackRxPacket2);
    //ICSS_EmacRegisterHwIntTx(handle, (ICSS_EmacCallBack)ICSS_EMAC_testCallbackTxComplete);
    /* Base address initialization */
    if(NULL == ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg) {
        ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg =
                        (ICSS_EmacBaseAddressHandle_T)malloc(sizeof(ICSS_EmacBaseAddrCfgParams));
    }
    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;

    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );

    emacBaseAddr->l3OcmcBaseAddr =0x70100000;

    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );

    return retVal;
}



    /*
     *  ======== TAskFxn: FTP server init task ========
     */
void TaskFxn(UArg a0, UArg a1)
{
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 0: %s\n\r", ipAddr);
    #ifdef NIMU_FTP_APP
        ftpserver_init();
    #endif

        //while(1){
            //ICSS_EmacPollControl(emachandle,7);
            //Task_sleep(1);
        //}

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
    bzero(&NA, sizeof(NA));
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


/**********************************************************************************************************/
#include <ti/board/src/am65xx_idk/include/pinmux.h>
#include <ti/board/src/am65xx_idk/am65xx_idk_pinmux.h>
#include <ti/csl/src/ip/icss/V2/cslr_icss_g.h>
#include <ti/sysbios/family/arm/v8a/Mmu.h>
#include <ti/csl/csl_rat.h>
int8_t Board_getPhyAddress(uint8_t instance, uint8_t portNumber);

#define DPPHY_REGCR_REG         0x0D
#define DPPHY_ADDR_REG          0x0E
#define DPPHY_RGMIICTL          0x32
#define DPPHY_GPIO_MUX_CTRL2    0x172
#define EXT_REG_ADDRESS_ACCESS      0x001F
#define EXT_REG_DATA_NORMAL_ACCESS  0x401F

void mii_init()
{
    //MII pinmux
    tiesc_mii_pinmuxConfig();
    //Making the clock for ICSSG core and IEP same
    (*((volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_ICSSG0_CLKSEL))) |= 0x01;
    (*((volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_ICSSG1_CLKSEL))) |= 0x01;
    (*((volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_ICSSG2_CLKSEL))) |= 0x01;

    /* Selecting MII-RT mode in GPCFG mux */
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussCfgRegBase) + CSL_ICSSCFG_GPCFG0))) = 0x8000003;
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussCfgRegBase) + CSL_ICSSCFG_GPCFG1))) = 0x8000003;

    // ICSS_G_CFG make it MII
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussMiiRtCfgRegBase) + 0x1000 + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG))) = (0x10001);

    /* Setting up RX_ER/GPIO pin on the PHY as RX_ERR pin and COL/GPIO pin as LED_3 */
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 1), DPPHY_GPIO_MUX_CTRL2, 0x60);
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 2), DPPHY_GPIO_MUX_CTRL2, 0x60);

    /* Disable RGMII interface */
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 1), DPPHY_RGMIICTL, 0x50);
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(pruIcssHandle->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 2), DPPHY_RGMIICTL, 0x50);

    PRUICSS_pinMuxConfig(pruIcssHandle, 0x0);   // PRUSS pinmuxing

    /* I2C Init */
    //Board_i2cLedInit();

    /* Rotary Switch Init */
    //Board_initRotarySwitch();

    //QSPI_init();

    CSL_ratRegs *pICSSGRat0Regs = (CSL_ratRegs *)((((PRUICSS_HwAttrs *)((
                                      pruIcssHandle)->hwAttrs))->baseAddr) + CSL_ICSS_G_RAT_REGS_0_BASE);
    CSL_ratRegs *pICSSGRat1Regs = (CSL_ratRegs *)((((PRUICSS_HwAttrs *)((
                                      pruIcssHandle)->hwAttrs))->baseAddr) + CSL_ICSS_G_RAT_REGS_1_BASE);
    CSL_RatTranslationCfgInfo TranslationCfg;

    /*ICSSG RAT Entry 0 pointing to ICSSG_CROSS_PRU0_DMEM_CONST -> c15 */
    TranslationCfg.sizeInBytes =
            0xE2000;     // sizeInBytes
    TranslationCfg.baseAddress =
            (0xE0100000);//0x60000000;                            // c15 baseAddress
    TranslationCfg.translatedAddress =
            0x70100000;//cross_ICSSG_dmem0_offset;               // translatedAddress

    CSL_ratEnableRegionTranslation(pICSSGRat0Regs, 0);
    CSL_ratConfigRegionTranslation(pICSSGRat0Regs, 0, &TranslationCfg);

    CSL_ratEnableRegionTranslation(pICSSGRat1Regs, 0);
    CSL_ratConfigRegionTranslation(pICSSGRat1Regs, 0, &TranslationCfg);
}



//MII pin mux code
#if 1
static pinmuxPerCfg_t gPru_icssg0_mii_g_rt0PinCfg[] =
{
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii_mt0_clk -> AC24 */
    {
        PIN_PRG0_PRU1_GPO16, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_txen -> AE27 */
    {
        PIN_PRG0_PRU1_GPO15, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_txd3 -> AD24 */
    {
        PIN_PRG0_PRU1_GPO14, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_txd2 -> AD25 */
    {
        PIN_PRG0_PRU1_GPO13, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_txd1 -> AC25 */
    {
        PIN_PRG0_PRU1_GPO12, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_txd0 -> AB24 */
    {
        PIN_PRG0_PRU1_GPO11, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxdv -> Y24 */
    {
        PIN_PRG0_PRU0_GPO4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii_mr0_clk -> Y25 */
    {
        PIN_PRG0_PRU0_GPO6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxd3 -> AA27 */
    {
        PIN_PRG0_PRU0_GPO3, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxd2 -> W24 */
    {
        PIN_PRG0_PRU0_GPO2, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxer -> V28 */
    {
        PIN_PRG0_PRU0_GPO5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxd1 -> W25 */
    {
        PIN_PRG0_PRU0_GPO1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxd0 -> V24 */
    {
        PIN_PRG0_PRU0_GPO0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii0_rxlink -> V27 */
    {
        PIN_PRG0_PRU0_GPO8, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii_mt1_clk -> AD28 */
    {
        PIN_PRG0_PRU0_GPO16, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_txen -> AA24 */
    {
        PIN_PRG0_PRU0_GPO15, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_txd3 -> AD26 */
    {
        PIN_PRG0_PRU0_GPO14, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_txd2 -> AC26 */
    {
        PIN_PRG0_PRU0_GPO13, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_txd1 -> AD27 */
    {
        PIN_PRG0_PRU0_GPO12, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_txd0 -> AB25 */
    {
        PIN_PRG0_PRU0_GPO11, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxdv -> AA25 */
    {
        PIN_PRG0_PRU1_GPO4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii_mr1_clk -> AB27 */
    {
        PIN_PRG0_PRU1_GPO6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxd3 -> AB26 */
    {
        PIN_PRG0_PRU1_GPO3, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxd2 -> AC27 */
    {
        PIN_PRG0_PRU1_GPO2, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxer -> U23 */
    {
        PIN_PRG0_PRU1_GPO5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxd1 -> AC28 */
    {
        PIN_PRG0_PRU1_GPO1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxd0 -> AB28 */
    {
        PIN_PRG0_PRU1_GPO0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG0_MII_G_RT1 -> pr0_mii1_rxlink -> W27 */
    {
        PIN_PRG0_PRU1_GPO8, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg0_mii_g_rtPinCfg[] =
{
    {0, TRUE, gPru_icssg0_mii_g_rt0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg1_mii_g_rt0PinCfg[] =
{
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii_mt0_clk -> AE19 */
    {
        PIN_PRG1_PRU1_GPO16, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_txen -> AG19 */
    {
        PIN_PRG1_PRU1_GPO15, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_txd3 -> AH19 */
    {
        PIN_PRG1_PRU1_GPO14, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_txd2 -> AF19 */
    {
        PIN_PRG1_PRU1_GPO13, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_txd1 -> AE20 */
    {
        PIN_PRG1_PRU1_GPO12, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_txd0 -> AC20 */
    {
        PIN_PRG1_PRU1_GPO11, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxdv -> AG23 */
    {
        PIN_PRG1_PRU0_GPO4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii_mr0_clk -> AF22 */
    {
        PIN_PRG1_PRU0_GPO6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxd3 -> AD21 */
    {
        PIN_PRG1_PRU0_GPO3, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxd2 -> AF23 */
    {
        PIN_PRG1_PRU0_GPO2, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxer -> AF27 */
    {
        PIN_PRG1_PRU0_GPO5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxd1 -> AG24 */
    {
        PIN_PRG1_PRU0_GPO1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxd0 -> AE22 */
    {
        PIN_PRG1_PRU0_GPO0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii0_rxlink -> AF28 */
    {
        PIN_PRG1_PRU0_GPO8, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii_mt1_clk -> AD20 */
    {
        PIN_PRG1_PRU0_GPO16, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_txen -> AD19 */
    {
        PIN_PRG1_PRU0_GPO15, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_txd3 -> AG20 */
    {
        PIN_PRG1_PRU0_GPO14, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_txd2 -> AH21 */
    {
        PIN_PRG1_PRU0_GPO13, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_txd1 -> AH20 */
    {
        PIN_PRG1_PRU0_GPO12, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_txd0 -> AF21 */
    {
        PIN_PRG1_PRU0_GPO11, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxdv -> AE21 */
    {
        PIN_PRG1_PRU1_GPO4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii_mr1_clk -> AG22 */
    {
        PIN_PRG1_PRU1_GPO6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxd3 -> AH22 */
    {
        PIN_PRG1_PRU1_GPO3, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxd2 -> AG21 */
    {
        PIN_PRG1_PRU1_GPO2, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxer -> AC22 */
    {
        PIN_PRG1_PRU1_GPO5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxd1 -> AH23 */
    {
        PIN_PRG1_PRU1_GPO1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxd0 -> AH24 */
    {
        PIN_PRG1_PRU1_GPO0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MyPRU_ICSSG1_MII_G_RT1 -> pr1_mii1_rxlink -> AE24 */
    {
        PIN_PRG1_PRU1_GPO8, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg1_mii_g_rtPinCfg[] =
{
    {0, TRUE, gPru_icssg1_mii_g_rt0PinCfg},
    {PINMUX_END}
};

pinmuxBoardCfg_t gAM65xxMIIPinmuxData[] =
{
    {0, gPru_icssg0_mii_g_rtPinCfg},
    {1, gPru_icssg1_mii_g_rtPinCfg},
    {PINMUX_END}
};

void tiesc_mii_pinmuxConfig (void)
{
    pinmuxModuleCfg_t* pModuleData = NULL;
    pinmuxPerCfg_t* pInstanceData = NULL;
    int32_t i, j, k;
    uint32_t rdRegVal;

    for(i = 0; PINMUX_END != gAM65xxMIIPinmuxData[i].moduleId; i++)
    {
        pModuleData = gAM65xxMIIPinmuxData[i].modulePinCfg;
        for(j = 0; (PINMUX_END != pModuleData[j].modInstNum); j++)
        {
            if(pModuleData[j].doPinConfig == TRUE)
            {
                pInstanceData = pModuleData[j].instPins;
                for(k = 0; (PINMUX_END != pInstanceData[k].pinOffset); k++)
                {
                    rdRegVal = HW_RD_REG32((MAIN_PMUX_CTRL + pInstanceData[k].pinOffset));
                    rdRegVal = (rdRegVal & PINMUX_BIT_MASK);
                    HW_WR_REG32((MAIN_PMUX_CTRL + pInstanceData[k].pinOffset),
                                (pInstanceData[k].pinSettings));
                }
            }
        }
    }

    return;
}
#endif


//board setting related API's
int8_t Board_getPhyAddress(uint8_t instance, uint8_t portNumber)
{
    if(1u == portNumber)
    {
        return 0;
    }

    else if(2u == portNumber)
    {
        return 3;
    }
}

void MDIO_phyExtRegWrite(uint32_t mdioBaseAddress, uint32_t phyNum,
                         uint32_t regNum, uint16_t phyregval)
{
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, DPPHY_REGCR_REG,
                         EXT_REG_ADDRESS_ACCESS);
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, DPPHY_ADDR_REG, regNum);
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, DPPHY_REGCR_REG,
                         EXT_REG_DATA_NORMAL_ACCESS);
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, DPPHY_ADDR_REG, phyregval);
    return;
}

//mmu configuration
#if defined (__aarch64__)
struct MmuCfg_t
{
    uint64_t    vaddr;
    uint64_t    paddr;
    size_t      size;
    int         attrInd;
} MmuCfgTbl[] =
{
    { 0x00100000, 0x00100000, 0x00900000, 0 }, /* Main MMR0     */
    { 0x00400000, 0x00400000, 0x00001000, 0 }, /* PSC0          */
    { 0x00A40000, 0x00A40000, 0x00001000, 0 }, /* TimeSyncRouter     */
    { 0x01800000, 0x01800000, 0x00100000, 0 }, /* gicv3         */
    { 0x02400000, 0x02400000, 0x000c0000, 0 }, /* dmtimer       */
    { 0x02800000, 0x02800000, 0x00001000, 0 }, /* uart          */
    { 0x02000000, 0x02000000, 0x00100000, 0 }, /* I2C           */
    { 0x02100000, 0x02100000, 0x00080000, 0 }, /* McSPI         */
    { 0x40F00000, 0x40F00000, 0x00020000, 0 }, /* MCU MMR0      */
    { 0x40d00000, 0x40d00000, 0x00002000, 0 }, /* PLL0          */
    { 0x47000000, 0x47000000, 0x00100000, 0 }, /* FSS0 cfg          */
    { 0x400000000, 0x400000000, 0x400000000, 0 }, /* FSS0 data          */
    { 0x40f90000, 0x40f90000, 0x00001000, 0 }, /* RAT cfg          */
    { 0x42120000, 0x42120000, 0x00001000, 0 }, /* WKUP I2C0     */
    { 0x43000000, 0x43000000, 0x00020000, 0 }, /* WKUP MMR0     */
    { 0x02C40000, 0x02C40000, 0x00100000, 0 }, /* pinmux ctrl   */
    { 0x30800000, 0x30800000, 0x0C000000, 0 }, /* main navss    */
    { 0x28380000, 0x28380000, 0x03880000, 0 }, /* mcu navss     */
    { 0x30000000, 0x30000000, 0x0F000000, 0 }, /* ctrcontrol0   */
   // { 0x01000000, 0x01000000, 0x00400000, 0 }, /* GIC0 ITS   */
    //{ 0x02a22000, 0x02a22000, 0x00000400, 0 }, /* GIC0 AGGR   */
    {
        CSL_MCU_CPSW0_NUSS_BASE, CSL_MCU_CPSW0_NUSS_BASE,
        (CSL_MCU_CPSW0_NUSS_SIZE * 2), 0
    },      /* for CPSW      */
    { 0x0b000000, 0x0b000000, 0x00100000, 0 }, /* ICSS-G 0      */
    { 0x0b100000, 0x0b100000, 0x00100000, 0 }, /* ICSS-G 1      */
    { 0x0b200000, 0x0b200000, 0x00100000, 0 }, /* ICSS-G 2      */
    { 0x42000000, 0x42000000, 0x00001000, 0 }, /* PSC WKUP      */
    { 0x03802000, 0x03802000, 0x00001000, 0 }, /* NB0_CFG_MMRS  */
    { 0x70000000, 0x70000000, 0x04000000, 7 }, /* msmc          */
    { 0x41C00000, 0x41C00000, 0x00080000, 7 }, /* ocmc          */
    { 0x80000000, 0x80000000, 0x10000000, 7 }, /* ddr_0          */
    { 0, 0, 0, 8 } /* attrInd = 8 -> end of table */
};

void InitMmu(void)
{
    bool        retVal = FALSE;
    uint32_t    j = 0;
    Mmu_MapAttrs attrs;
    Mmu_initMapAttrs(&attrs);

    while(MmuCfgTbl[j].attrInd < 8)
    {
        attrs.attrIndx = MmuCfgTbl[j].attrInd;
        retVal = Mmu_map(MmuCfgTbl[j].vaddr, MmuCfgTbl[j].paddr, MmuCfgTbl[j].size,
                         &attrs);

        if(retVal == FALSE)
        {
            break;
        }

        j++;
    }

    if(retVal == FALSE)
    {
        UART_printf("Mmu_map idx %d returned error %d", j, retVal);

        while(1);
    }
}
#endif // __aarch64__

/**********************************************************************************************************/
