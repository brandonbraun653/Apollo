/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file     mcan_test.c
 *
 *  \brief    This file contains MCAN sample code.
 *
 *  Targeted Functionality: Verifying the transmit and receive functionality
 *    of MCAN module.
 *
 *  Operation: MCAN operational mode is set to CAN-FD. This test will need
 *  two MCAN ports.
 *
 *  Supported SoCs: AM65XX & J721E.
 *
 *  Supported Platforms: am65xx_idk & j721e_evm.
 *
 */

#include "mcan_test.h"

MCAN_TxBufElement  txMsg;
MCAN_RxBufElement  rxMsg;

volatile uint32_t gMcanIsrIntr0Flag = 1U;
volatile uint32_t gMcanIsrIntr1Flag = 1U;

uint32_t expBoardDetect = 0;
uint32_t mcanMaxPorts   = 0;

#if defined(am65xx_idk)
mcanDiagportInfo  gmcanDiagportInfo[MCAN_MAX_PORTS] = {{CSL_MCU_MCAN0_MSGMEM_RAM_BASE, 0, CSL_GIC0_INTR_MCU_MCAN0_BUS_MCANSS_MCAN_LVL_INT_0, CSL_GIC0_INTR_MCU_MCAN0_BUS_MCANSS_MCAN_LVL_INT_1, CSL_GIC0_INTR_MCU_MCAN0_BUS_MCANSS_EXT_TS_ROLLOVER_LVL_INT}, 
                                                       {CSL_MCU_MCAN1_MSGMEM_RAM_BASE, 1, CSL_GIC0_INTR_MCU_MCAN1_BUS_MCANSS_MCAN_LVL_INT_0, CSL_GIC0_INTR_MCU_MCAN1_BUS_MCANSS_MCAN_LVL_INT_1, CSL_GIC0_INTR_MCU_MCAN1_BUS_MCANSS_EXT_TS_ROLLOVER_LVL_INT},
                                                      };
#else
mcanDiagportInfo  gmcanDiagportInfo[MCAN_MAX_PORTS_EXP] = {{CSL_MCU_MCAN0_MSGMEM_RAM_BASE, 0, MCU_MCAN0_TX_INT_NUM,  MCU_MCAN0_RX_INT_NUM,  MCU_MCAN0_TS_INT_NUM},
                                                       {CSL_MCU_MCAN1_MSGMEM_RAM_BASE, 1, MCU_MCAN1_TX_INT_NUM,  MCU_MCAN1_RX_INT_NUM,  MCU_MCAN1_TS_INT_NUM},
                                                       {CSL_MCAN0_MSGMEM_RAM_BASE,     0, MAIN_MCAN0_TX_INT_NUM, MAIN_MCAN0_RX_INT_NUM, MAIN_MCAN0_TS_INT_NUM},
                                                       {CSL_MCAN2_MSGMEM_RAM_BASE,     2, MAIN_MCAN2_TX_INT_NUM, MAIN_MCAN2_RX_INT_NUM, MAIN_MCAN2_TS_INT_NUM},
                                                       {CSL_MCAN4_MSGMEM_RAM_BASE,     4, MAIN_MCAN4_TX_INT_NUM, MAIN_MCAN4_RX_INT_NUM, MAIN_MCAN4_TS_INT_NUM},
                                                       {CSL_MCAN5_MSGMEM_RAM_BASE,     5, MAIN_MCAN5_TX_INT_NUM, MAIN_MCAN5_RX_INT_NUM, MAIN_MCAN5_TS_INT_NUM},
                                                       {CSL_MCAN6_MSGMEM_RAM_BASE,     6, MAIN_MCAN6_TX_INT_NUM, MAIN_MCAN6_RX_INT_NUM, MAIN_MCAN6_TS_INT_NUM},
                                                       {CSL_MCAN7_MSGMEM_RAM_BASE,     7, MAIN_MCAN7_TX_INT_NUM, MAIN_MCAN7_RX_INT_NUM, MAIN_MCAN7_TS_INT_NUM},
                                                       {CSL_MCAN9_MSGMEM_RAM_BASE,     9, MAIN_MCAN9_TX_INT_NUM, MAIN_MCAN9_RX_INT_NUM, MAIN_MCAN9_TS_INT_NUM},
                                                       {CSL_MCAN11_MSGMEM_RAM_BASE,   11, MAIN_MCAN11_TX_INT_NUM, MAIN_MCAN11_RX_INT_NUM, MAIN_MCAN11_TS_INT_NUM},
                                                      };
#endif

/**
 * \brief   This function will configure MCAN module
 *
 * \param   index  [IN]  - MCAN index number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanConfig(uint8_t index)
{
    uint32_t                   fdoe;
    uint32_t                   baseAddr;
    MCAN_RevisionId            revId;
    MCAN_InitParams            initParams;
    MCAN_ConfigParams          configParams;
    MCAN_MsgRAMConfigParams    msgRAMConfigParams;
    MCAN_StdMsgIDFilterElement stdFiltelem;
    MCAN_BitTimingParams       bitTimes;
    
    /* Set base address */
    baseAddr = gmcanDiagportInfo[index].mcanBaseAddrs;

    /* Initialize MCAN Init params */
    initParams.fdMode          = 0x1U;
    initParams.brsEnable       = 0x1U;
    initParams.txpEnable       = 0x0U;
    initParams.efbi            = 0x0U;
    initParams.pxhddisable     = 0x0U;
    initParams.darEnable       = 0x1U;
    initParams.wkupReqEnable   = 0x1U;
    initParams.autoWkupEnable  = 0x1U;
    initParams.emulationEnable = 0x1U;
    initParams.emulationFAck   = 0x0U;
    initParams.clkStopFAck     = 0x0U;
    initParams.wdcPreload      = 0xFFU;
    initParams.tdcEnable       = 0x1U;
    initParams.tdcConfig.tdcf  = 0xAU;
    initParams.tdcConfig.tdco  = 0x6U;

    /* Initialize MCAN Config params */
    configParams.monEnable         = 0x0U;
    configParams.asmEnable         = 0x0U;
    configParams.tsPrescalar       = 0xFU;
    configParams.tsSelect          = 0x0U;
    configParams.timeoutSelect     = MCAN_TIMEOUT_SELECT_CONT;
    configParams.timeoutPreload    = 0xFFFFU;
    configParams.timeoutCntEnable  = 0x0U;
    configParams.filterConfig.rrfs = 0x1U;
    configParams.filterConfig.rrfe = 0x1U;
    configParams.filterConfig.anfe = 0x1U;
    configParams.filterConfig.anfs = 0x1U;

    /* Initialize Message RAM Sections Configuration Parameters */
    msgRAMConfigParams.flssa                = APP_MCAN_STD_ID_FILT_START_ADDR;
    msgRAMConfigParams.lss                  = APP_MCAN_STD_ID_FILTER_NUM;
    msgRAMConfigParams.flesa                = APP_MCAN_EXT_ID_FILT_START_ADDR;
    msgRAMConfigParams.lse                  = APP_MCAN_EXT_ID_FILTER_NUM;

    msgRAMConfigParams.txStartAddr          = APP_MCAN_TX_BUFF_START_ADDR;
    msgRAMConfigParams.txBufNum             = APP_MCAN_TX_BUFF_SIZE;
    msgRAMConfigParams.txFIFOSize           = 0U;
    msgRAMConfigParams.txBufMode            = 0U;
    msgRAMConfigParams.txBufElemSize        = MCAN_ELEM_SIZE_64BYTES;
    msgRAMConfigParams.txEventFIFOStartAddr = APP_MCAN_TX_EVENT_START_ADDR;
    msgRAMConfigParams.txEventFIFOSize      = APP_MCAN_TX_BUFF_SIZE;
    msgRAMConfigParams.txEventFIFOWaterMark = 3U;

    msgRAMConfigParams.rxFIFO0startAddr     = APP_MCAN_FIFO_0_START_ADDR;
    msgRAMConfigParams.rxFIFO0size          = APP_MCAN_FIFO_0_NUM;
    msgRAMConfigParams.rxFIFO0waterMark     = 3U;
    msgRAMConfigParams.rxFIFO0OpMode        = 0U;
    msgRAMConfigParams.rxFIFO1startAddr     = APP_MCAN_FIFO_1_START_ADDR;
    msgRAMConfigParams.rxFIFO1size          = APP_MCAN_FIFO_1_NUM;
    msgRAMConfigParams.rxFIFO1waterMark     = 3U;
    msgRAMConfigParams.rxFIFO1OpMode        = 0U;
    msgRAMConfigParams.rxBufStartAddr       = APP_MCAN_RX_BUFF_START_ADDR;
    msgRAMConfigParams.rxBufElemSize        = MCAN_ELEM_SIZE_64BYTES;
    msgRAMConfigParams.rxFIFO0ElemSize      = MCAN_ELEM_SIZE_64BYTES;
    msgRAMConfigParams.rxFIFO1ElemSize      = MCAN_ELEM_SIZE_64BYTES;

    /* Initialize Tx Buffer Config params */
    stdFiltelem.sfid2 = 0x0U;
    stdFiltelem.sfid1 = 0x4U;
    stdFiltelem.sfec  = 0x7U;
    stdFiltelem.sft   = 0x0U;

    /* Initialize bit timings
     * Configuring 1Mbps and 5Mbps as nominal and data bit-rate respectively */
    bitTimes.nomRatePrescalar   = 0x7U;
    bitTimes.nomTimeSeg1        = 0x5U;
    bitTimes.nomTimeSeg2        = 0x2U;
    bitTimes.nomSynchJumpWidth  = 0x0U;
    bitTimes.dataRatePrescalar  = 0x1U;
    bitTimes.dataTimeSeg1       = 0x3U;
    bitTimes.dataTimeSeg2       = 0x2U;
    bitTimes.dataSynchJumpWidth = 0x0U;

    /* Get MCANSS Revision ID */
    MCAN_getRevisionId(baseAddr, &revId);
    UART_printf("MCANSS Revision ID:\n");
    UART_printf("scheme:0x%x\n",revId.scheme);
    UART_printf("Business Unit:0x%x\n",revId.bu);
    UART_printf("Module ID:0x%x\n",revId.modId);
    UART_printf("RTL Revision:0x%x\n",revId.rtlRev);
    UART_printf("Major Revision:0x%x\n",revId.major);
    UART_printf("Custom Revision:0x%x\n",revId.custom);
    UART_printf("Minor Revision:0x%x\n",revId.minor);

    /* Enable Auto wakeup */
    fdoe = MCAN_isFDOpEnable(baseAddr);
    if ((uint32_t)TRUE == fdoe)
    {
        UART_printf("CAN-FD operation is enabled through E-Fuse.\n");
    }
    else
    {
        UART_printf("CAN-FD operation is disabled through E-Fuse.\n");
    }

    /* wait for memory initialization to happen */
    while (FALSE == MCAN_isMemInitDone(baseAddr))
    {}

    /* Get endianess value */
    UART_printf("Endianess Value:0x%x\n",MCAN_getEndianVal(baseAddr));

    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(baseAddr, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(baseAddr))
    {}

    /* Initialize MCAN module */
    MCAN_init(baseAddr, &initParams);

    /* Configure MCAN module */
    MCAN_config(baseAddr, &configParams);

    /* Configure Bit timings */
    MCAN_setBitTime(baseAddr, &bitTimes);

    /* Set Extended ID Mask */
    MCAN_setExtIDAndMask(baseAddr, APP_MCAN_EXT_ID_AND_MASK);

    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig(baseAddr, &msgRAMConfigParams);

    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter(baseAddr, 0U, &stdFiltelem);

    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(baseAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(baseAddr))
    {}

    return 0;
}

#if defined(MCAN_DIAG_INTR_ENABLE)
/**
 * \brief   This API will disable the TX and RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanTxIntDisable(uint32_t baseAddr)
{
    /* Disable Interrupts */
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32_t)FALSE);
    MCAN_enableIntr(baseAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(baseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_0);
    /* Disable Interrupt Line */
    MCAN_enableIntrLine(baseAddr,
                        MCAN_INTR_LINE_NUM_0,
                        0U);
}

/**
 * \brief   This API will disable the RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanRxIntDisable(uint32_t baseAddr)
{
    /* Disable Interrupts */
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32_t)FALSE);
    MCAN_enableIntr(baseAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(baseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_1);
    /* Disable Interrupt Line */
    MCAN_enableIntrLine(baseAddr,
                        MCAN_INTR_LINE_NUM_1,
                        0U);
}
/**
 * \brief   This API will enables the RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanRxIntEnable(uint32_t baseAddr)
{
    /* Enable Interrupts */
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(baseAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(baseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_1);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(baseAddr,
                        MCAN_INTR_LINE_NUM_1,
                        1U);
}

/**
 * \brief   This API will enables the TX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static int32_t BoardDiag_mcanTxIntEnable(uint32_t baseAddr)
{
    int32_t  status = 0;
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(baseAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(baseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_0);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(baseAddr,
                        MCAN_INTR_LINE_NUM_0,
                        1U);
    /* Enable Transmission interrupt */
    status = MCAN_txBufTransIntrEnable(baseAddr,
                                       1U,
                                       (uint32_t)TRUE);
    return status;

}

/**
 * \brief   This is Interrupt Service Routine for MCAN Tx interrupt.
 *
 * \param   handle [IN/OUT] mcasp info structure
 *
 */
static void BoardDiag_mcanTxIntrISR(void *handle)
{
    uint32_t intrStatus;
    uint32_t baseAddrs;
    mcanDiagportInfo *intrInfo;

    intrInfo = (mcanDiagportInfo *)handle;
    baseAddrs = intrInfo -> mcanBaseAddrs;

    intrStatus = MCAN_getIntrStatus(baseAddrs);
    MCAN_clearIntrStatus(baseAddrs, intrStatus);
    if (MCAN_INTR_SRC_TRANS_COMPLETE ==
        (intrStatus & MCAN_INTR_SRC_TRANS_COMPLETE))
    {
        gMcanIsrIntr0Flag = 0U;
    }

}


/**
 * \brief   This is Interrupt Service Routine for MCAN Rx interrupt.
 *
 * \param   handle [IN/OUT] mcasp info structure
 *
 */
static void BoardDiag_mcanRxIntrISR(void *handle)
{
    uint32_t intrStatus;
    uint32_t baseAddrs;
    mcanDiagportInfo *intrInfo;

    intrInfo = (mcanDiagportInfo *)handle;
    baseAddrs = intrInfo -> mcanBaseAddrs;

    intrStatus = MCAN_getIntrStatus(baseAddrs);
    MCAN_clearIntrStatus(baseAddrs, intrStatus);
    if (MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG ==
        (intrStatus & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG))
    {
        gMcanIsrIntr1Flag = 0U;
    }
}

/**
 * \brief   This function will configure MCAN Tx interrupts
 *
 * \param   index  [IN]  - MCAN index number
 *
 */
static void BoardDiag_mcanTxIntrConfig(uint32_t index)
{
#if defined (__aarch64__)
    Intc_Init(0);

    /* Enable CPU Interrupts and register ISR - MCAN Intr0 */
    Intc_IntRegister(gmcanDiagportInfo[index].mcanTxIntNum,
                    (IntrFuncPtr) BoardDiag_mcanTxIntrISR, (void*)(&gmcanDiagportInfo[index]));
    Intc_IntPrioritySet(gmcanDiagportInfo[index].mcanTxIntNum, 1U, 0U);
    Intc_SystemEnable(gmcanDiagportInfo[index].mcanTxIntNum);
    UART_printf("Tx Interrupt Configuration done.\n");
#endif
}

/**
 * \brief   This function will configure MCAN Rx interrupts
 *
 * \param   index  [IN]  - MCAN index number
 *
 */
static void BoardDiag_mcanRxIntrConfig(uint32_t index)
{
#if defined (__aarch64__)
    Intc_Init(0);

    /* Enable CPU Interrupts and register ISR - MCAN Intr0 */
    Intc_IntRegister(gmcanDiagportInfo[index].mcanRxIntNum,
                    (IntrFuncPtr) BoardDiag_mcanRxIntrISR, (void*)(&gmcanDiagportInfo[index]));
    Intc_IntPrioritySet(gmcanDiagportInfo[index].mcanRxIntNum, 1U, 0U);
    Intc_SystemEnable(gmcanDiagportInfo[index].mcanRxIntNum);
    UART_printf("Rx Interrupt Configuration done.\n");
#endif
}

#if defined(TS_INT_ENABLE)
/**
 * \brief   This is Interrupt Service Routine for MCAN TimeStamp interrupt.
 *
 * \param   handle [IN/OUT] mcasp info structure
 *
 */
static void BoardDiag_mcanTsIntrISR(void *handle)
{
    uint32_t baseAddrs;
    mcanDiagportInfo *intrInfo;

    intrInfo = (mcanDiagportInfo *)handle;
    baseAddrs = intrInfo -> mcanBaseAddrs;
    if(MCAN_extTSIsIntrEnable(baseAddrs) == (uint32_t)TRUE)
    {
        UART_printf("MCAN Time Stamp overflow happened.\n");
    }

    MCAN_extTSClearRawStatus(baseAddrs);
    MCAN_extTSWriteEOI(baseAddrs);
}

/**
 * \brief   This function will configure MCAN Rx interrupts
 *
 * \param   index  [IN]  - MCAN index number
 *
 */
static void BoardDiag_mcanTsIntrConfig(uint32_t index)
{
#if defined (__aarch64__)
    Intc_Init(0);

    /* Enable CPU Interrupts and register ISR - MCAN Intr0 */
    Intc_IntRegister(gmcanDiagportInfo[index].mcanTsIntNum,
                    (IntrFuncPtr) BoardDiag_mcanTsIntrISR, (void*)(&gmcanDiagportInfo[index]));
    Intc_IntPrioritySet(gmcanDiagportInfo[index].mcanTsIntNum, 1U, 0U);
    Intc_SystemEnable(gmcanDiagportInfo[index].mcanTsIntNum);
    UART_printf("Tx Interrupt Configuration done.\n");
#endif
}
#endif
#endif  /* #if defined(MCAN_DIAG_INTR_ENABLE) */

#if defined(BOARD_DEBUG_MCAN)
/**
 * \brief   This API will print MCAN Tx Msg.
 *
 */
static void BoardDiag_mcanPrintTxMsg(void)
{
    uint32_t loopCnt;

    UART_printf("\nMessage ID:0x%x\n", txMsg.id);

    UART_printf("\nMessage Remote Transmission Request:0x%x\n",txMsg.rtr);

    UART_printf("\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID):0x%x\n",
                                                              txMsg.xtd);

    UART_printf("\nMessage Error State Indicator(0:Error Active/1:Error Passive):0x%x\n",txMsg.esi);

    UART_printf("\nMessage Data Length Code:0x%x\n",txMsg.dlc);

    UART_printf("\nMessage BRS:0x%x\n",txMsg.brs);

    UART_printf("\nMessage CAN FD format:0x%x\n",txMsg.fdf);

    UART_printf("\nMessage Store Tx Events:0x%x\n",txMsg.efc);

    UART_printf("\nMessage Marker:0x%x\n",txMsg.mm);

    for (loopCnt = 0U; loopCnt < txMsg.dlc; loopCnt++)
    {
        UART_printf("\nMessage DataByte%d:0x%x\n",loopCnt,txMsg.data[loopCnt]);
    }
}

/**
 * \brief   This API will print MCAN Rx Msg.
 *
 */
static void BoardDiag_mcanPrintRxMsg(void)
{
    uint32_t loopCnt;

    UART_printf("\nReceived last message with following details:");

    UART_printf("\nMessage ID:0x%x\n",rxMsg.id);

    UART_printf("\nMessage Remote Transmission Request:0x%x\n",rxMsg.rtr);
    
    UART_printf("\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID):0x%x\n",
                                                                   rxMsg.xtd);
    
    UART_printf("\nMessage Error State Indicator(0:Error Active/1:Error Passive):0x%x\n", rxMsg.esi);
    
    UART_printf("\nMessage TimeStamp:0x%x\n",rxMsg.rxts);

    UART_printf("\nMessage Data Length Code:0x%x\n",rxMsg.dlc);

    UART_printf("\nMessage BRS:0x%x\n",rxMsg.brs);

    UART_printf("\nMessage CAN FD format:0x%x\n",rxMsg.fdf);

    UART_printf("\nMessage Filter Index:0x%x\n",rxMsg.fidx);

    UART_printf("\nMessage Accept Non-matching Frame:0x%x\n",rxMsg.anmf);

    for (loopCnt = 0U; loopCnt < rxMsg.dlc; loopCnt++)
    {
        UART_printf("\nMessage DataByte%d:0x%x\n",loopCnt,rxMsg.data[loopCnt]);
    }
}
#endif

/**
 * \brief   This API will load the data to the message ram and checking
 *          the error status
 *
 * \param   instance  [IN]  - MCAN instance number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanTxTest(uint8_t instance)
{
    int8_t   configStatus = 0;
    uint32_t baseAddr;
    MCAN_ProtocolStatus protStatus;
    
    /* Set base address */
    baseAddr = gmcanDiagportInfo[instance].mcanBaseAddrs;
  
#if defined(MCAN_DIAG_INTR_ENABLE)
    BoardDiag_mcanTxIntrConfig(instance);
    configStatus = BoardDiag_mcanTxIntEnable(baseAddr);
#endif

    /* Write message to Msg RAM */
    MCAN_writeMsgRam(baseAddr,
                     MCAN_MEM_TYPE_BUF,
                     APP_MCAN_TX_BUF_NUM,
                     &txMsg);

    /* Add request for transmission */
    configStatus += MCAN_txBufAddReq(baseAddr, APP_MCAN_TX_BUF_NUM);
    if (configStatus != 0)
    {
        UART_printf("\nError in Adding Transmission Request...\n");
        return -1;
    }


#if defined(MCAN_DIAG_INTR_ENABLE)
    while (gMcanIsrIntr0Flag)
    {}
    gMcanIsrIntr0Flag = 1U;
#else   
    /* Waiting for Transmission Complete */
    while(((MCAN_getTxBufReqPend(baseAddr) >>
            APP_MCAN_TX_BUF_NUM) & 0x1) == 0x1);
#endif

    MCAN_getProtocolStatus(baseAddr, &protStatus);
    /* Checking for Errors */
    if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
         (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
        ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
         (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
        (0U == protStatus.pxe))
    {
        UART_printf("\nMessage successfully transferred with payload Bytes:0x%x\n",txMsg.dlc);
    }
    else
    {
        UART_printf("\nError in transmission with payload Bytes:0x%x\n", txMsg.dlc);
        configStatus = -1;
    }

    return configStatus;
}

/**
 * \brief   This API will receive the data and compares with the transmit data
 *
 * \param   instance  [IN]  - MCAN instance number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanRxTest(uint8_t index)
{
    uint32_t chkCnt     = 0U;
    uint32_t errFlag    = 0U;
    uint32_t baseAddr;
    int8_t  testStatus  = 0;
    MCAN_RxNewDataStatus newDataStatus;
    MCAN_ErrCntStatus    errCounter;

    /* Set base address */
    baseAddr = gmcanDiagportInfo[index].mcanBaseAddrs;

#if defined(MCAN_DIAG_INTR_ENABLE)
    BoardDiag_mcanRxIntrConfig(index);
    BoardDiag_mcanRxIntEnable(baseAddr);
#endif

#if defined(MCAN_DIAG_INTR_ENABLE)
    while (gMcanIsrIntr1Flag)
    {}
    gMcanIsrIntr1Flag = 1U;
#else
    /* Waiting for Transmission Complete */
    while(MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG !=
        (MCAN_getIntrStatus(baseAddr) &
        MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG));
    
#endif
    /* Checking for Errors */
    MCAN_getErrCounters(baseAddr, &errCounter);
    if ((0U == errCounter.recErrCnt) &&
        (0U == errCounter.canErrLogCnt))
    {
        MCAN_getNewDataStatus(baseAddr, &newDataStatus);
        MCAN_clearNewDataStatus(baseAddr, &newDataStatus);
        MCAN_readMsgRam(baseAddr,
                        MCAN_MEM_TYPE_BUF,
                        0U,
                        0U,
                        &rxMsg);

        errFlag = 0U;

        for (chkCnt = 0U; chkCnt < rxMsg.dlc; chkCnt++)
        {
            if (txMsg.data[chkCnt] != rxMsg.data[chkCnt])
            {
                errFlag = 1U;
                break;
            }
        }

        if (0U == errFlag)
        {
            UART_printf("\nMessage successfully received with payload Bytes:0x%x\n",rxMsg.dlc);
        }
        else
        {
            UART_printf("\nWrong data received in message with payload Bytes:0x%x\n",rxMsg.dlc);
            testStatus = -1;
        }
    }
    else
    {
        UART_printf("\nError in reception with payload Bytes:0x%x\n", txMsg.dlc);
        testStatus = -1;
    }
#if defined(BOARD_DEBUG_MCAN)
    BoardDiag_mcanPrintRxMsg();
#endif
    return testStatus;
}

#if defined(SOC_J721E)
/**
 * \brief   This function enables the Main CAN module and transceiver by setting
 *          the Enable and STB Pins
 *
 */
static void BoardDiag_mcanMainconfigs(void)
{
    Board_IoExpCfg_t ioExpCfg;
    Board_STATUS status = BOARD_SOK;

    ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE2_ADDR;
    ioExpCfg.enableIntr  = false;    
    ioExpCfg.ioExpType   = THREE_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_0;
    ioExpCfg.pinNum      = PIN_NUM_6;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;
    
    status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, &ioExpCfg);
    if(status != BOARD_SOK)
    {
        UART_printf("Failed to enable the main MCAN0 \n");
    }

    ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE2_ADDR;
    ioExpCfg.enableIntr  = false;    
    ioExpCfg.ioExpType   = THREE_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_0;
    ioExpCfg.pinNum      = PIN_NUM_7;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;
    
    status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, &ioExpCfg);
    if(status != BOARD_SOK)
    {
        UART_printf("Failed to set the mcan0 stb pin to normal mode\n");
    }

    ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE2_ADDR;
    ioExpCfg.enableIntr  = false;    
    ioExpCfg.ioExpType   = THREE_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_1;
    ioExpCfg.pinNum      = PIN_NUM_4;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;
    
    status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, &ioExpCfg);
    if(status != BOARD_SOK)
    {
        UART_printf("Failed to enable the MCAN mux selection\n");
    }
}
#endif

/**
 * \brief   This API Initializes the GPIO module
 *
 * \param    gpioBaseAddrs [IN]  GPIO base address to configure
 * \param    port          [IN]  GPIO Port number
 *
 */
static void BoardDiag_mcanGpioConfig(uint32_t gpioBaseAddrs,uint32_t port)
{
    GPIO_v0_HwAttrs gpioCfg;
    GPIO_socGetInitCfg(port, &gpioCfg);
    gpioCfg.baseAddr = gpioBaseAddrs;
    GPIO_socSetInitCfg(port, &gpioCfg);
    /* GPIO initialization */
    GPIO_init();
}

/**
 * \brief   This API enables the CAN transceivers by setting the STB pins
 *
 */
static void BoardDiag_mcanEnable(void)
{

#if defined(SOC_J721E)
    Board_IoExpCfg_t ioExpCfg;
    Board_STATUS status = BOARD_SOK;
#endif

#if defined (am65xx_idk)
    BoardDiag_mcanGpioConfig(CSL_GPIO1_BASE, 1);
    GPIO_write(0, 1);
    GPIO_write(1, 1);
#else
    BoardDiag_mcanGpioConfig(CSL_WKUP_GPIO0_BASE,0);
    /* Enable MCU CAN transceivers by setting the STB pins */
    GPIO_write(0, 1); /* MCU_CAN0_STB -> WKUP_GPIO0_54 */
    GPIO_write(1, 0); /* MCU_CAN1_STB -> WKUP_GPIO0_2  */
    /* MCU_MCAN0_EN */
    GPIO_write(2, 1); /* WKUP_GPIO0_0 */

    /* Enable CP board MAIN CAN transceivers by setting the STB pins */
    BoardDiag_mcanMainconfigs();

    /* MAIN CAN2 STB */
    BoardDiag_mcanGpioConfig(CSL_GPIO0_BASE, 0);
    GPIO_write(3, 0); /* GPIO0_127 */

    if(expBoardDetect)
    {
        UART_printf("GESI board Detected\n");
        ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE1_INSTANCE;
        ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
        ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE1_ADDR;
        ioExpCfg.enableIntr  = false;    
        ioExpCfg.ioExpType   = TWO_PORT_IOEXP;
        ioExpCfg.portNum     = PORTNUM_1;
        ioExpCfg.pinNum      = PIN_NUM_4;
        ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;
        
        status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, &ioExpCfg);
        if(status != BOARD_SOK)
        {
            UART_printf("Failed to set the GESI board mcan stb pin to normal mode \n");
        }
        /* GPIO0_60 */
        BoardDiag_mcanGpioConfig(CSL_GPIO0_BASE, 0);
        GPIO_write(4, 0);
    }
#endif
}

/**
 * \brief  This function executes MCAN Diagnostic test
 *
 * \return  int8_t
 *           0  - in case of success
 *          -1  - in case of failure
 *
 */
int8_t BoardDiag_McanTest(void)
{
    int8_t    ret     = 0;
    uint32_t  index;
    uint32_t  portNum;

#if defined(DIAG_STRESS_TEST) && (defined(am65xx_idk) || defined(SOC_J721E))
    char rdBuf = 'y';
#endif

#if defined(DIAG_STRESS_TEST) && ((defined(am65xx_idk)) || defined(SOC_J721E))
    UART_printf  ("***********************************************\n");
    UART_printf  ("*                MCAN Stress Test             *\n");
    UART_printf  ("***********************************************\n");
#else
    UART_printf  ("***********************************************\n");
    UART_printf  ("*                MCAN Test                    *\n");
    UART_printf  ("***********************************************\n");
#endif

    BoardDiag_mcanEnable();
#if defined(am65xx_idk)
    mcanMaxPorts = MCAN_MAX_PORTS;
#else
    if(expBoardDetect)
    {
        mcanMaxPorts = MCAN_MAX_PORTS_EXP;
    }
    else
    {
        mcanMaxPorts = MCAN_MAX_PORTS_CP;
    }
#endif

    /* Initialize message to transmit */
    txMsg.id  = (uint32_t)((uint32_t)(0x4U) << 18U);
    txMsg.rtr = 0U;
    txMsg.xtd = 0U;
    txMsg.esi = 0U;
    txMsg.dlc = 0xFU;
    txMsg.brs = 1U;
    txMsg.fdf = 1U;
    txMsg.efc = 1U;
    txMsg.mm  = 0xAAU;

    for(portNum=0; portNum<mcanMaxPorts;)
    {
        /* Configure MCAN */
        ret = BoardDiag_mcanConfig(portNum);
        if(ret == 0)
        {
            UART_printf("Successfully configured MCAN%d\n",portNum);
        }

        ret = BoardDiag_mcanConfig(portNum+1);
        if(ret == 0)
        {
            UART_printf("Successfully configured MCAN%d\n",portNum+1);
        }

        UART_printf("\n\nTransmitting Data on MCAN Port%d and Receiving on MCAN port%d\n",portNum, portNum+1);

        for(index = 0; index < PKT_SEND_COUNT; index++)
        {
            UART_printf("\nSending Packet - %d\n", (index + 1));
            /* Fill the Tx buffer with random data */
            BoardDiag_genPattern(txMsg.data, MCAN_MAX_PAYLOAD_BYTES,
                                 BOARD_DIAG_TEST_PATTERN_RANDOM);

            /* Transmiting port */
            ret = BoardDiag_mcanTxTest(portNum);
            if(ret != 0)
            {
                UART_printf("Failed to transmit data on port%d\n",portNum);
                return (-1);
            }
#if defined(BOARD_DEBUG_MCAN)
            BoardDiag_mcanPrintTxMsg();
#endif
            /* Receiving port*/
            ret = BoardDiag_mcanRxTest(portNum+1);
            if(ret != 0)
            {
                UART_printf("Failed to receive data on port%d",portNum);
                return (-1);
            }

            UART_printf("\nReceived Packet - %d\n\n", (index + 1));
#if defined(DIAG_STRESS_TEST) && ((defined(am65xx_idk)) || defined(SOC_J721E))
            /* Check if there a input from console to break the test */
            rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
            if((rdBuf == 'b') || (rdBuf == 'B'))
            {
                UART_printf("Received Test Termination... Exiting the Test\n\n");
                UART_printf("MCAN Stress Test Status\n");
                UART_printf("============================================\n");
                UART_printf("Total Number of Packets sent: %d\nTotal Number of Packets Received: %d\n",index + 1,index + 1);
                break;
            }
#endif
#if defined(MCAN_DIAG_INTR_ENABLE)
            /* Disable the TX and RX interrupts */
            BoardDiag_mcanTxIntDisable(gmcanDiagportInfo[portNum].mcanBaseAddrs);
            BoardDiag_mcanRxIntDisable(gmcanDiagportInfo[portNum+1].mcanBaseAddrs);
#endif
        }

        UART_printf("\n\nTransmitting Data on MCAN Port%d and Receiving on MCAN port%d\n",portNum+1, portNum);
        for(index = 0; index < PKT_SEND_COUNT; index++)
        {
            UART_printf("\nSending Packet - %d\n", (index + 1));
            /* Fill the Tx buffer with random data */
            BoardDiag_genPattern(txMsg.data, MCAN_MAX_PAYLOAD_BYTES,
                                 BOARD_DIAG_TEST_PATTERN_RANDOM);

            /* Transmitting port*/
            ret = BoardDiag_mcanTxTest(portNum+1);
            if(ret != 0)
            {
                UART_printf("Failed to transmit data on port%d",portNum+1);
                return -1;
            }
#if defined(BOARD_DEBUG_MCAN)
            BoardDiag_mcanPrintTxMsg();
            UART_printf("Receiving data on port%d\n", portNum);
#endif

            /* Receiving port */
            ret = BoardDiag_mcanRxTest(portNum);
            if(ret != 0)
            {
                UART_printf("Failed to receive data on port%d\n",portNum);
                return (-1);
            }

            UART_printf("\nReceived Packet - %d\n\n", (index + 1));
#if defined(DIAG_STRESS_TEST) && ((defined(am65xx_idk)) || defined(SOC_J721E))
            /* Check if there a input from console to break the test */
            rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
            if((rdBuf == 'b') || (rdBuf == 'B'))
            {
                UART_printf("Received Test Termination... Exiting the Test\n\n");
                UART_printf("MCAN Stress Test Status\n");
                UART_printf("============================================\n");
                UART_printf("Total Number of Packets sent: %d\nTotal Number of Packets Received: %d\n",index + 1,index + 1);
                break;
            }
#endif
#if defined(MCAN_DIAG_INTR_ENABLE)
            /* Disable the TX and RX interrupts */
            BoardDiag_mcanTxIntDisable(gmcanDiagportInfo[portNum+1].mcanBaseAddrs);
            BoardDiag_mcanRxIntDisable(gmcanDiagportInfo[portNum].mcanBaseAddrs);
#endif
        }

        portNum +=2;
    }
    UART_printf("\n MCAN diagnostic test completed.\n");

    return  0;
}


/**
 * \brief  main function
 *
 *  This function performs board initializations and calls MCAN test
 *
 * \return  int
 *           0  - in case of success
 *          -1  - in case of failure
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
#if defined(SOC_J721E)
    Board_PinmuxConfig_t gesiIcssgPinmux;
    if(Board_detectBoard(BOARD_ID_GESI) == TRUE)
    {
        Board_pinmuxGetCfg(&gesiIcssgPinmux);
        gesiIcssgPinmux.autoCfg = BOARD_PINMUX_CUSTOM;
        gesiIcssgPinmux.gesiExp = BOARD_PINMUX_GESI_ICSSG;
        Board_pinmuxSetCfg(&gesiIcssgPinmux);
        expBoardDetect = 1;
    }
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG ;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    return BoardDiag_McanTest();
}

