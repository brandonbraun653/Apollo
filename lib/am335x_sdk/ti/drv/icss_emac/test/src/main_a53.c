/**
 * @file   main_a53.c
 *
 * @brief  This file tests the ICSS-EMAC driver APIs in Poll Mode
 */
/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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

#include <ti/csl/csl_rat.h>

extern uint8_t ICSS_EMAC_testPkt[];
extern uint32_t ICSS_EMAC_testTotalPktRcvd;

/* number of links which actually came up to test the interface */
static uint32_t  ICSS_EMAC_testLinkUpCount = 0;

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

static uint32_t ICSS_EMAC_testPruInstance2Done = 0;

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

    //mii related init
    mii_init();

    /*PRU2 ETH0 initializations*/
    ICSS_EMAC_testHandle2 = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    icss_emacTestInitCfg0 = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));
    if ((ICSS_EMAC_testHandle2 == NULL) || (icss_emacTestInitCfg0 == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

    icss_emacTestInitCfg0->phyAddr[0]=0;
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
    
    icss_emacTestInitCfg1->phyAddr[0]= 3;

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

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY | BOARD_INIT_ICSS_PINMUX;

    Error_init(&eb);
    //HW_WR_REG32(0x3802010U, 0x2);
    boardInitStatus  = Board_init(cfg);
    //Task_sleep(1);

    if (boardInitStatus !=0)
    {
        printf("Board_init failure\n");
        return(0);
    }

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "SwitchTask2";
    taskParams.stackSize = 0x1000;
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testTask_am65xx, &taskParams, &eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "PollControlTask";
    taskParams.stackSize = 0x1000;
    Task_create((ti_sysbios_knl_Task_FuncPtr)ICSS_EMAC_testPollControlTask, &taskParams, NULL);

    ICSS_EMAC_testPruIcssInstance2Setup();

    BIOS_start();
    return(0);
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
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussCfgRegBase) + CSL_ICSSCFG_GPCFG0))) = 0x8000003;
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussCfgRegBase) + CSL_ICSSCFG_GPCFG1))) = 0x8000003;

    // ICSS_G_CFG make it MII
    (*((volatile uint32_t *)((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussMiiRtCfgRegBase) + 0x1000 + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_ICSS_G_CFG))) = (0x10001);

    /* Setting up RX_ER/GPIO pin on the PHY as RX_ERR pin and COL/GPIO pin as LED_3 */
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 1), DPPHY_GPIO_MUX_CTRL2, 0x60);
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 2), DPPHY_GPIO_MUX_CTRL2, 0x60);

    /* Disable RGMII interface */
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 1), DPPHY_RGMIICTL, 0x50);
    MDIO_phyExtRegWrite((((PRUICSS_HwAttrs *)(ICSS_EMAC_testPruIcssHandle2->hwAttrs))->prussMiiMdioRegBase), Board_getPhyAddress(PRUICCSS_INSTANCE_TWO, 2), DPPHY_RGMIICTL, 0x50);

    PRUICSS_pinMuxConfig(ICSS_EMAC_testPruIcssHandle2, 0x0);   // PRUSS pinmuxing

    /* I2C Init */
    //Board_i2cLedInit();

    /* Rotary Switch Init */
    //Board_initRotarySwitch();

    //QSPI_init();

    CSL_ratRegs *pICSSGRat0Regs = (CSL_ratRegs *)((((PRUICSS_HwAttrs *)((
                                      ICSS_EMAC_testPruIcssHandle2)->hwAttrs))->baseAddr) + CSL_ICSS_G_RAT_REGS_0_BASE);
    CSL_ratRegs *pICSSGRat1Regs = (CSL_ratRegs *)((((PRUICSS_HwAttrs *)((
                                      ICSS_EMAC_testPruIcssHandle2)->hwAttrs))->baseAddr) + CSL_ICSS_G_RAT_REGS_1_BASE);
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
}

MmuCfgTbl[] =
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
