/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   cpsw_test.c
 *
 *  \brief  CPSW9G ethernet diagnostic test file
 *
 *  Targeted Functionality: Verification of basic functionality of
 *  CPSW9G Ethernet interface.
 *
 *  Operation: This is the Loopback test code for the Ethernet Interface.
 *  The test code showcases usage of the CPSW Driver exported API for
 *  sending/receiving Ethernet packets.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms:j721e_evm.
 *
 */

/* Test application local header file */
#include "cpsw_eth_test.h"

static volatile bool txSem = false;
static volatile bool rxSem = false;

/* Broadcast address */
static uint8_t bcastAddr[ETH_MAC_ADDR_LEN] =
        { 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU };

/* CPSW configuration */
static CpswDma_OpenTxChPrms   cpswTxChCfg;

static CpswDma_OpenRxFlowPrms cpswRxFlowCfg;

static cpsw_Obj gCpswLpbkObj = {
    .cpswType = CPSW_9G,
};

/**
 * \brief   CPSW receive ISR function
 *
 * \param   hUdmaEvt     [IN]   UDMA event handle
 * \param   eventType    [IN]   Event type
 * \param   appData      [IN]   Pointer to application data
 *
 */
static void BoardDiag_cpswRxIsrFxn(void *appData)
{
    rxSem = true;
}

/**
 * \brief   CPSW transmit ISR function
 *
 * \param   hUdmaEvt     [IN]   UDMA event handle
 * \param   eventType    [IN]   Event type
 * \param   appData      [IN]   Pointer to application data
 *
 */
static void BoardDiag_cpswTxIsrFxn(void *appData)
{
    txSem = true;
}

/**
 * \brief   This function is used to queue the received packets to rx ready queue
 *
 * \return  uint32_t - Receive ready queue count
 *
 */
static uint32_t BoardDiag_cpswReceivePkts(void)
{
    CpswDma_PktInfoQ rxReadyQ;
    CpswDma_PktInfo *pktInfo;
    int32_t          status;
    uint32_t         rxReadyCnt = 0U;

    CpswUtils_initQ(&rxReadyQ);

    /* Retrieve any CPSW packets which are ready */
    status = CpswDma_retrieveRxPackets(gCpswLpbkObj.hRxFlow, &rxReadyQ);
    if (status == CPSW_SOK)
    {
        rxReadyCnt = CpswUtils_getQCount(&rxReadyQ);
        /* Queue the received packet to rxReadyQ and pass new ones from rxFreeQ
        **/
        pktInfo = (CpswDma_PktInfo *) CpswUtils_deQ(&rxReadyQ);
        while (pktInfo != NULL)
        {
            CpswUtils_checkPktState(&pktInfo->pktState,
                                    CPSW_PKTSTATE_MODULE_APP,
                                    CPSW_PKTSTATE_APP_WITH_DRIVER,
                                    CPSW_PKTSTATE_APP_WITH_READYQ);

            CpswUtils_enQ(&gCpswLpbkObj.rxReadyQ, &pktInfo->node);
            pktInfo = (CpswDma_PktInfo *) CpswUtils_deQ(&rxReadyQ);
        }
    }
    else
    {
        UART_printf("receivePkts() failed to retrieve pkts: %d\n",
                           status);
    }

    return rxReadyCnt;
}

/**
 * \brief   This function is used to retrieve's any CPSW packets that may be free now
 *
 * \return  uint32_t - Transmit free queue count
 *
 */
static uint32_t BoardDiag_cpswRetrieveFreeTxPkts(void)
{
    CpswDma_PktInfoQ txFreeQ;
    CpswDma_PktInfo *pktInfo;
    int32_t          status;
    uint32_t         txFreeQCnt = 0U;

    CpswUtils_initQ(&txFreeQ);

    /* Retrieve any CPSW packets that may be free now */
    status = CpswDma_retrieveTxDonePackets(gCpswLpbkObj.hTxCh, &txFreeQ);
    if (status == CPSW_SOK)
    {
        txFreeQCnt = CpswUtils_getQCount(&txFreeQ);

        pktInfo = (CpswDma_PktInfo *) CpswUtils_deQ(&txFreeQ);
        while (pktInfo != NULL)
        {
            CpswUtils_checkPktState(&pktInfo->pktState,
                                    CPSW_PKTSTATE_MODULE_APP,
                                    CPSW_PKTSTATE_APP_WITH_DRIVER,
                                    CPSW_PKTSTATE_APP_WITH_FREEQ);

            CpswUtils_enQ(&gCpswLpbkObj.txFreePktInfoQ, &pktInfo->node);
            pktInfo = (CpswDma_PktInfo *) CpswUtils_deQ(&txFreeQ);
        }
    }
    else
    {
        UART_printf("retrieveFreeTxPkts() failed to retrieve pkts: %d\n",
                           status);
    }

    return txFreeQCnt;
}

/**
 * \brief   CPSW delay function
 *
 * \param   waitTime     [IN]   Wait time
 *
 */
static void BoardDiag_cpswWait(uint32_t waitTime)
{
    volatile uint32_t index;

    /* we multiply waitTime by 10000 as 400MHz R5 takes 2.5ns for single cycle
     * and we assume for loop takes 4 cycles */
    for (index = 0; index < (waitTime*10000); index++);
}

/**
 * \brief   This function is used to initialize the receive ready packet queue
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t boarDiag_cpswInitRxReadyPktQ(void)
{
    CpswDma_PktInfoQ rxReadyQ;
    int32_t          status;
    uint32_t         index;
    CpswDma_PktInfo *pPktInfo;

    CpswUtils_initQ(&gCpswLpbkObj.rxFreeQ);
    CpswUtils_initQ(&gCpswLpbkObj.rxReadyQ);
    CpswUtils_initQ(&rxReadyQ);

    for (index = 0U; index < CPSW_APPMEMUTILS_NUM_RX_PKTS; index++)
    {
        pPktInfo = CpswAppMemUtils_allocEthPktFxn(&gCpswLpbkObj,
                                                  CPSW_APPMEMUTILS_LARGE_POOL_PKT_SIZE,
                                                  UDMA_CACHELINE_ALIGNMENT);
        if(pPktInfo == NULL)
        {
           UART_printf("\n");
        }
        CPSW_UTILS_SET_PKT_APP_STATE(&pPktInfo->pktState,
                                     CPSW_PKTSTATE_APP_WITH_FREEQ);
        CpswUtils_enQ(&gCpswLpbkObj.rxFreeQ,
                      &pPktInfo->node);
    }

    /* Retrieve any CPSW packets which are ready */
    status = CpswDma_retrieveRxPackets(gCpswLpbkObj.hRxFlow,
                                       &rxReadyQ);
    if( status != CPSW_SOK )
    {
        UART_printf("Failed to retrive the CPSW RX packets\n");
        return -1;
    }

    /* There should not be any packet with DMA during init */
    if(CpswUtils_getQCount(&rxReadyQ) != 0U )
    {
        UART_printf("rxReadyQ is not zero,...Exiting\n");
        return -1;
    }

    CpswAppUtils_validatePacketState(&gCpswLpbkObj.rxFreeQ,
                                     CPSW_PKTSTATE_APP_WITH_FREEQ,
                                     CPSW_PKTSTATE_APP_WITH_DRIVER);

    CpswAppUtils_submitRxPackets(gCpswLpbkObj.hRxFlow,
                                 &gCpswLpbkObj.rxFreeQ);
    /* Assert here as during init no. of DMA descriptors should be equal to
     * no. of free Ethernet buffers available with app */

    if(CpswUtils_getQCount(&gCpswLpbkObj.rxFreeQ) != 0)
    {
        UART_printf("rxFreeQ is not '0',...Exiting\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function is used to initialize the free packet
 *          info queue with the Ethernet packets to be transmitted.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_cpswInitTxFreePktQ(void)
{
    CpswDma_PktInfo *pktInfo;
    uint32_t         index;

    /* Initialize all queues */
    CpswUtils_initQ(&gCpswLpbkObj.txFreePktInfoQ);

    /* Initialize TX EthPkts and queue them to txFreePktInfoQ */
    for(index = 0U; index < CPSWAPPUTILS_ARRAY_SIZE(gCpswLpbkObj.txFreePktInfo); index++)
    {
        pktInfo = &gCpswLpbkObj.txFreePktInfo[index];
        if(pktInfo == NULL)
        {
            return -1;
        }

        CpswDma_pktInfoInit(pktInfo);

        memset (&pktInfo->node, 0U, sizeof(pktInfo->node));
        pktInfo->bufPtr     = (uint8_t *)&gCpswLpbkObj.txBufMem[index][0U];
        pktInfo->orgBufLen  = ETH_MAX_FRAME_LEN;
        pktInfo->userBufLen = ETH_MAX_FRAME_LEN;
        pktInfo->appPriv    = NULL;

        CPSW_UTILS_SET_PKT_APP_STATE(&pktInfo->pktState,
                                     CPSW_PKTSTATE_APP_WITH_FREEQ);

        CpswUtils_enQ(&gCpswLpbkObj.txFreePktInfoQ,
                      &pktInfo->node);
    }

    UART_printf("initQs() txFreePktInfoQ initialized with %d pkts\n",
                 CpswUtils_getQCount(&gCpswLpbkObj.txFreePktInfoQ));
    return 0;
}

/**
 * \brief   This function is used to set the ALE port state to forward.
 *
 * \param   macAddr     [IN]   host MAC address
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int32_t BoardDiag_cpswChangeHostAleEntry(uint8_t macAddr[])
{
    int32_t status;
    Cpsw_IoctlPrms prms;
    CpswAle_AddEntryOutArgs setUcastOutArgs;
    CpswAle_SetUcastEntryInArgs setUcastInArgs;

    memcpy(&setUcastInArgs.addr.addr[0U],
            macAddr,
            sizeof(setUcastInArgs.addr.addr));

    setUcastInArgs.addr.vlanId  = 0U;
    setUcastInArgs.info.portNum = 0U;
    setUcastInArgs.info.blocked = false;
    setUcastInArgs.info.secure  = false;
    setUcastInArgs.info.super   = 0U;
    setUcastInArgs.info.ageable = false;


    CPSW_IOCTL_SET_INOUT_ARGS(&prms,
                              &setUcastInArgs,
                              &setUcastOutArgs);

    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_ALE_IOCTL_ADD_UNICAST,
                        &prms);
    if (status != CPSW_SOK)
    {
        UART_printf("Setting the ALE port state to forward failed with error status - %d\n\r", status);
        return status;
    }

    return status;
}

/**
 * \brief   This function is used for converting the virtual address
 *          to physical address
 *
 * \param   virtAddr   [IN/OUT]   Pointer to virtual address
 * \param   appData    [IN]       Pointer to application data
 *
 * \return  uint64_t  -  CPSW physical address
 *
 */
static uint64_t BoardDiag_cpswvirtToPhyFx(const void *virtAddr,
                                          void       *appData)
{
    return ((uint64_t)virtAddr);
}

/**
 * \brief   This function is used for converting the physical address
 *          to virtual address
 *
 * \param   phyAddr     [IN]   Pointer to physical address
 * \param   appData     [IN]   Pointer to application data
 *
 * \return  void  -  Pointer to virtual address
 *
 */
static void *BoardDiag_cpswPhyToVirtFxn(uint64_t phyAddr,
                                        void    *appData)
{
#if defined (__aarch64__)
    uint64_t temp = phyAddr;
#else
    /* R5 is 32-bit machine, need to truncate to avoid void * typecast error */
    uint32_t temp = (uint32_t)phyAddr;
#endif
    return ((void *) temp);
}

/**
 * \brief   This function is used for initialize the ALE submodule.
 *
 * \param   aleConfig  [IN]   Pointer to ALE configuration structure
 *
 */
static void BoardDiag_cpswInitAleConfig(CpswAle_Config *aleConfig)
{
    aleConfig->modeFlags =
        (CPSW_ALE_CONFIG_MASK_ALE_MODULE_ENABLE);
    aleConfig->agingConfig.enableAutoAging = TRUE;
    aleConfig->agingConfig.agingPeriodInMs = 1000;
    aleConfig->nwSecCfg.enableVid0Mode = TRUE;
    aleConfig->vlanConfig.aleVlanAwareMode = FALSE;
    aleConfig->vlanConfig.cpswVlanAwareMode = FALSE;
    aleConfig->vlanConfig.unknownUnregMcastFloodMask = CPSW_ALE_ALL_PORTS_MASK;
    aleConfig->vlanConfig.unknownRegMcastFloodMask = CPSW_ALE_ALL_PORTS_MASK;
    aleConfig->vlanConfig.unknownVlanMemberListMask = CPSW_ALE_ALL_PORTS_MASK;
}

/**
 * \brief   This function is used for de-initialize the CPSW module.
 *
 */
void BoardDiag_cpswClose(void)
{
    int32_t status;
    Cpsw_IoctlPrms prms;

    Cpsw_GenericPortLinkInArgs args0 = {
        .portNum = gCpswLpbkObj.portNum0,
    };


    Cpsw_GenericPortLinkInArgs args1 = {
        .portNum = gCpswLpbkObj.portNum1,
    };

    CPSW_IOCTL_SET_IN_ARGS(&prms,
                           &gCpswLpbkObj.coreKey);

    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_IOCTL_DETACH_CORE,
                        &prms);
    if (status != CPSW_SOK)
    {
        UART_printf("close() failed to close MAC port: %d\n", status);
    }

    CPSW_IOCTL_SET_IN_ARGS(&prms, &args0);
    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_IOCTL_CLOSE_PORT_LINK,
                        &prms);
    if (status != CPSW_SOK)
    {
        UART_printf("close() failed to close MAC port0: %d\n", status);
    }

    CPSW_IOCTL_SET_IN_ARGS(&prms, &args1);
    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_IOCTL_CLOSE_PORT_LINK,
                        &prms);
    if (status != CPSW_SOK)
    {
        UART_printf("close() failed to close MAC port1: %d\n", status);
    }

    Cpsw_close(gCpswLpbkObj.hCpsw);

    Cpsw_deinit(gCpswLpbkObj.cpswType);
}


/**
 * \brief   This function is used for de-initialize the CPSW DMA driver.
 *
 */
void BoardDiag_cpswCloseDma(void)
{
    CpswDma_PktInfoQ fqPktInfoQ;
    CpswDma_PktInfoQ cqPktInfoQ;

    CpswUtils_initQ(&fqPktInfoQ);
    CpswUtils_initQ(&cqPktInfoQ);

    /* Close RX Flow */
    CpswAppUtils_closeRxFlow(gCpswLpbkObj.hCpsw,
                             gCpswLpbkObj.coreKey,
                             gCpswLpbkObj.coreId,
                             true,
                             &fqPktInfoQ,
                             &cqPktInfoQ,
                             gCpswLpbkObj.rxStartFlowIdx,
                             gCpswLpbkObj.rxFlowIdx,
                             gCpswLpbkObj.hostMacAddr,
                             gCpswLpbkObj.hRxFlow);

    CpswAppUtils_freePktInfoQ(&fqPktInfoQ);
    CpswAppUtils_freePktInfoQ(&cqPktInfoQ);

    /* Close TX channel */
    CpswUtils_initQ(&fqPktInfoQ);
    CpswUtils_initQ(&cqPktInfoQ);

    CpswAppUtils_closeTxCh(gCpswLpbkObj.hCpsw,
                           gCpswLpbkObj.coreKey,
                           gCpswLpbkObj.coreId,
                           &fqPktInfoQ,
                           &cqPktInfoQ,
                           gCpswLpbkObj.hTxCh,
                           gCpswLpbkObj.txChNum);

    CpswAppUtils_freePktInfoQ(&fqPktInfoQ);
    CpswAppUtils_freePktInfoQ(&cqPktInfoQ);

    CpswAppUtils_freePktInfoQ(&gCpswLpbkObj.rxFreeQ);
    CpswAppUtils_freePktInfoQ(&gCpswLpbkObj.txFreePktInfoQ);

    CpswAppMemUtils_deInit();
}

/**
 * \brief   This function is used to display Mac and Host port statistics
 *
 */
static void BoardDiag_cpswShowStats(void)
{
    Cpsw_IoctlPrms prms;
    CpswStats_GenericMacPortInArgs inArgs;
    CpswStats_PortStats portStats;
    int32_t status = CPSW_SOK;

    CPSW_IOCTL_SET_OUT_ARGS(&prms,
                            &portStats);
    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_STATS_IOCTL_GET_HOSTPORT_STATS,
                        &prms);
    if (status != CPSW_SOK)
    {
        UART_printf("CpswApp_showStats() failed to get host stats: %d\n",
                     status);
    }

    if (status == CPSW_SOK)
    {
        inArgs.portNum = CPSW_MAC_PORT_0;
        CPSW_IOCTL_SET_INOUT_ARGS(&prms,
                                  &inArgs,
                                  &portStats);

        status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                            gCpswLpbkObj.coreId,
                            CPSW_STATS_IOCTL_GET_MACPORT_STATS,
                            &prms);
        if (status != CPSW_SOK)
        {
            UART_printf("CpswApp_showStats() failed to get MAC stats: %d\n",
                         status);
        }
    }
}

/**
 * \brief   This function is used for CPSW packet transmission
 *          and reception
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int32_t BoardDiag_cpswPktRxTx(void)
{
    CpswDma_PktInfoQ txSubmitQ;
    CpswDma_PktInfo  *pktInfo;
    EthFrame         *frame;
    uint32_t         txRetrievePktCnt;
    uint32_t         loopTxPktCnt;
    uint32_t         totalTxCnt;
    uint32_t         rxReadyCnt;
    uint32_t         loopCnt;
    uint32_t         pktCnt;
    uint32_t         loopRxPktCnt;
    int32_t          status = CPSW_SOK;

    totalTxCnt = 0U;
    for (loopCnt = 0U; loopCnt < TEST_NUM_LOOP; loopCnt++)
    {
        pktCnt = 0U;
        while (pktCnt < TEST_PTK_NUM)
        {
            loopRxPktCnt = loopTxPktCnt = 0U;
            /* Transmit a single packet */
            CpswUtils_initQ(&txSubmitQ);

            /* Dequeue one free TX Eth packet */
            pktInfo = (CpswDma_PktInfo *)CpswUtils_deQ(&gCpswLpbkObj.txFreePktInfoQ);

            while ( NULL != pktInfo )
            {
                pktCnt++;
                /* Fill the TX Eth frame with test content */
                frame = (EthFrame *)pktInfo->bufPtr;

                memcpy(frame->hdr.dstMac,
                       bcastAddr,
                       ETH_MAC_ADDR_LEN);

                memcpy(frame->hdr.srcMac,
                       &gCpswLpbkObj.hostMacAddr[0U],
                       ETH_MAC_ADDR_LEN);

                frame->hdr.etherType = htons(ETHERTYPE_EXPERIMENTAL1);
                memset(&frame->payload[0U],
                       (uint8_t)(0xA5 + pktCnt),
                       TEST_LEN);
                pktInfo->userBufLen = TEST_LEN + sizeof (EthFrameHeader);
                pktInfo->appPriv    = &gCpswLpbkObj;
                CpswUtils_checkPktState(&pktInfo->pktState,
                                        CPSW_PKTSTATE_MODULE_APP,
                                        CPSW_PKTSTATE_APP_WITH_FREEQ,
                                        CPSW_PKTSTATE_APP_WITH_DRIVER);

                /* Enqueue the packet for later transmission */
                CpswUtils_enQ(&txSubmitQ,
                              &pktInfo->node);

                if (pktCnt >= TEST_PTK_NUM)
                {
                    break;
                }
                /* Dequeue one free TX Eth packet */
                pktInfo = (CpswDma_PktInfo *)CpswUtils_deQ(&gCpswLpbkObj.txFreePktInfoQ);
            }

            loopTxPktCnt = CpswUtils_getQCount(&txSubmitQ);
            while (0U != CpswUtils_getQCount(&txSubmitQ))
            {
                uint32_t txCnt = CpswUtils_getQCount(&txSubmitQ);
                status = CpswAppUtils_submitTxPackets(gCpswLpbkObj.hTxCh,
                                                      &txSubmitQ);
                while (txSem != true);
                txSem = false;

                /* Retrieve TX free packets */
                if (status == CPSW_SOK)
                {
                    txCnt = txCnt - CpswUtils_getQCount(&txSubmitQ);
                    txRetrievePktCnt = 0U;
                    while (txRetrievePktCnt != txCnt)
                    {
                        BOARD_delay(1);
                        txRetrievePktCnt |= BoardDiag_cpswRetrieveFreeTxPkts();
                    }
                }
                else
                {
                    break;
                }
            }

            /* Wait for packet reception */
            do
            {
                while (rxSem != true);
                rxSem = false;

                /* Get the packets received so far */
                rxReadyCnt = BoardDiag_cpswReceivePkts();
                if (rxReadyCnt > 0U)
                {
                    /* Consume the received packets and release them */
                    pktInfo = (CpswDma_PktInfo *)CpswUtils_deQ(&gCpswLpbkObj.rxReadyQ);
                    while (pktInfo != NULL)
                    {
                        CpswUtils_checkPktState(&pktInfo->pktState,
                                                CPSW_PKTSTATE_MODULE_APP,
                                                CPSW_PKTSTATE_APP_WITH_READYQ,
                                                CPSW_PKTSTATE_APP_WITH_FREEQ);

                        /* Consume the packet by just printing its content */
                        frame = (EthFrame *)pktInfo->bufPtr;
                        if (gCpswLpbkObj.printFrame)
                        {
                            CpswAppUtils_printFrame(frame,
                                                    (pktInfo->userBufLen - sizeof (EthFrameHeader)));
                        }

                        /* Release the received packet */
                        CpswUtils_enQ(&gCpswLpbkObj.rxFreeQ,
                                      &pktInfo->node);
                        pktInfo = (CpswDma_PktInfo *)CpswUtils_deQ(&gCpswLpbkObj.rxReadyQ);
                    }

                    /*Submit now processed buffers */
                    if (status == CPSW_SOK)
                    {
                        CpswAppUtils_validatePacketState(&gCpswLpbkObj.rxFreeQ,
                                                         CPSW_PKTSTATE_APP_WITH_FREEQ,
                                                         CPSW_PKTSTATE_APP_WITH_DRIVER);

                        CpswAppUtils_submitRxPackets(gCpswLpbkObj.hRxFlow,
                                                     &gCpswLpbkObj.rxFreeQ);
                    }
                }
                loopRxPktCnt |= rxReadyCnt;
            }
            while (loopRxPktCnt < loopTxPktCnt);

            totalTxCnt |= loopTxPktCnt;
        }
    }

    if (status == CPSW_SOK)
    {
        UART_printf("Transmitted & Received %d packets\n", totalTxCnt);
    }
    else
    {
        UART_printf("Failed to transmit/receive packets: %d, transmitted: %d \n", TEST_PTK_NUM, totalTxCnt);
    }

    return status;
}

/**
 * \brief   This function is used to open the CPSW DMA module
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int32_t BoardDiag_cpswOpenDma(void)
{
    int32_t status = CPSW_SOK;

    /* Open the CPSW TX channel  */
    CpswDma_initTxChParams(&cpswTxChCfg);

    cpswTxChCfg.hUdmaDrv  = gCpswLpbkObj.hUdmaDrv;
    cpswTxChCfg.hCbArg    = &gCpswLpbkObj;
    cpswTxChCfg.notifyCb  = BoardDiag_cpswTxIsrFxn;

    CpswAppUtils_setCommonTxChPrms(&cpswTxChCfg);

    CpswAppUtils_openTxCh(gCpswLpbkObj.hCpsw,
                          gCpswLpbkObj.coreKey,
                          gCpswLpbkObj.coreId,
                          &gCpswLpbkObj.txChNum,
                          &gCpswLpbkObj.hTxCh,
                          &cpswTxChCfg);

    BoardDiag_cpswInitTxFreePktQ();

    if (NULL != gCpswLpbkObj.hTxCh)
    {
        status = CpswDma_enableTxEvent(gCpswLpbkObj.hTxCh);
        if (CPSW_SOK != status)
        {
            /* Free the Ch Num if enable event failed */
            CpswAppUtils_freeTxCh(gCpswLpbkObj.hCpsw,
                                  gCpswLpbkObj.coreKey,
                                  gCpswLpbkObj.coreId,
                                  gCpswLpbkObj.txChNum);
            UART_printf("CpswDma_startTxCh() failed: %d\n", status);
            status = CPSW_EFAIL;
        }
    }
    else
    {
        /* Free the Ch Num if open Tx Ch failed */
        CpswAppUtils_freeTxCh(gCpswLpbkObj.hCpsw,
                              gCpswLpbkObj.coreKey,
                              gCpswLpbkObj.coreId,
                              gCpswLpbkObj.txChNum);
        UART_printf("CpswDma_openTxCh() failed to open: %d\n",
                     status);
        status = CPSW_EFAIL;
    }

    /* Open the CPSW RX flow  */
    if (status == CPSW_SOK)
    {
        CpswDma_initRxFlowParams(&cpswRxFlowCfg);
        cpswRxFlowCfg.notifyCb  = BoardDiag_cpswRxIsrFxn;
        cpswRxFlowCfg.hUdmaDrv  = gCpswLpbkObj.hUdmaDrv;
        cpswRxFlowCfg.hCbArg    = &gCpswLpbkObj;

        CpswAppUtils_setCommonRxFlowPrms(&cpswRxFlowCfg);

        CpswAppUtils_openRxFlow(gCpswLpbkObj.hCpsw,
                                gCpswLpbkObj.coreKey,
                                gCpswLpbkObj.coreId,
                                true,
                                &gCpswLpbkObj.rxStartFlowIdx,
                                &gCpswLpbkObj.rxFlowIdx,
                                &gCpswLpbkObj.hostMacAddr[0U],
                                &gCpswLpbkObj.hRxFlow,
                                &cpswRxFlowCfg);

        if (NULL == gCpswLpbkObj.hRxFlow)
        {
            CpswAppUtils_freeRxFlow(gCpswLpbkObj.hCpsw,
                                    gCpswLpbkObj.coreKey,
                                    gCpswLpbkObj.coreId,
                                    gCpswLpbkObj.rxFlowIdx);
            UART_printf("CpswDma_openRxFlow() failed to open: %d\n",
                         status);
            if(gCpswLpbkObj.hRxFlow == NULL)
            {
                return -1;
            }
        }
        else
        {
            CpswAppUtils_print("Host MAC address: ");
            CpswAppUtils_printMacAddr(gCpswLpbkObj.hostMacAddr);
            /* For MAC loopback disable secure flag for the host port entry */
            BoardDiag_cpswChangeHostAleEntry(&gCpswLpbkObj.hostMacAddr[0U]);

            /* Submit all ready RX buffers to DMA.*/
            boarDiag_cpswInitRxReadyPktQ();
        }
    }

    return status;
}

/**
 * \brief   This function is used to open the CPSW driver
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int32_t BoardDiag_cpswOpen(void)
{
    Cpsw_Config    cpswCfg;
    CpswOsal_Prms  osalPrms;
    CpswUtils_Prms utilsPrms;
    int32_t status = CPSW_SOK;
    Cpsw_IoctlPrms prms;
    Cpsw_AttachCoreOutArgs attachCoreOutArgs;

    /* Set configuration parameters */
    Cpsw_initParams(&cpswCfg);
    cpswCfg.vlanConfig.vlanAware          = false;
    cpswCfg.hostPortConfig.removeCrc      = true;
    cpswCfg.hostPortConfig.padShortPacket = true;
    cpswCfg.hostPortConfig.passCrcErrors  = true;
    CpswAppUtils_initResourceConfig(gCpswLpbkObj.cpswType,
                                    gCpswLpbkObj.coreId,
                                    &cpswCfg.resourceConfig);
    BoardDiag_cpswInitAleConfig(&cpswCfg.aleConfig);

    UART_printf("CPSW_9G Test on MAIN NAVSS\n");

    cpswCfg.dmaConfig.rxChInitPrms.dmaPriority = UDMA_DEFAULT_RX_CH_DMA_PRIORITY;




    /* App should open UDMA first as UDMA handle is needed to initialize
     * CPSW RX channel */
    gCpswLpbkObj.hUdmaDrv = CpswAppUtils_udmaOpen(gCpswLpbkObj.cpswType, NULL);
    if(gCpswLpbkObj.hUdmaDrv != NULL)
    {
        cpswCfg.dmaConfig.hUdmaDrv = gCpswLpbkObj.hUdmaDrv;
    }
    else
    {
        UART_printf("Failed to get the UDMA handle\n");
        return -1;
    }

    /* Initialize CPSW driver with default OSAL, utils */
    utilsPrms.printFxn     = UART_printf;
    utilsPrms.traceFxn     = UART_printf;
    utilsPrms.phyToVirtFxn = &BoardDiag_cpswPhyToVirtFxn;
    utilsPrms.virtToPhyFxn = &BoardDiag_cpswvirtToPhyFx;

    Cpsw_initOsalPrms(&osalPrms);

    Cpsw_init(gCpswLpbkObj.cpswType,
              &osalPrms,
              &utilsPrms);

    /* Open the CPSW driver */
    gCpswLpbkObj.hCpsw = Cpsw_open(gCpswLpbkObj.cpswType,
                                   &cpswCfg);
    if(gCpswLpbkObj.hCpsw == NULL)
    {
        UART_printf("BoardDiag_cpswOpen() failed to open: %d\n", status);
        status = CPSW_EFAIL;
    }

    if(status == CPSW_SOK)
    {
        /* Attach the core with RM */
        CPSW_IOCTL_SET_INOUT_ARGS(&prms,
                                  &gCpswLpbkObj.coreId,
                                  &attachCoreOutArgs);

        status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                            gCpswLpbkObj.coreId,
                            CPSW_IOCTL_ATTACH_CORE,
                            &prms);
        if(status != CPSW_SOK)
        {
            UART_printf("CpswApp_loopbackTest failed CPSW_IOCTL_ATTACH_CORE: %d\n",
                         status);
        }
        else
        {
            gCpswLpbkObj.coreKey = attachCoreOutArgs.coreKey;
        }
    }

    if (status == CPSW_SOK)
    {
        status = CpswAppUtils_allocMac(gCpswLpbkObj.hCpsw,
                                       gCpswLpbkObj.coreKey,
                                       gCpswLpbkObj.coreId,
                                       gCpswLpbkObj.hostMacAddr);
        if(status != CPSW_SOK)
        {
            UART_printf("CpswApp_loopbackTest failed CpswAppUtils_allocMac: %d\n",
                         status);
        }
        else
        {
            CpswAppUtils_addHostPortEntry(gCpswLpbkObj.hCpsw,
                                          gCpswLpbkObj.coreId,
                                          gCpswLpbkObj.hostMacAddr);
        }
    }

    if(status == CPSW_SOK)
    {
        /* memutils open should happen after Cpsw is opened as it uses CpswUtils_Q
         * functions */
        status = CpswAppMemUtils_init();
        if(status != CPSW_SOK)
        {
            UART_printf("cpsw memutils open function failed\n");
        }
    }

    if(status == CPSW_SOK)
    {
        Cpsw_OpenPortLinkInArgs linkArgs0 = {
            .portNum = gCpswLpbkObj.portNum0,
        };
        CpswMacPort_Config     *macConfig  = &linkArgs0.macConfig;
        CpswMacPort_LinkConfig *linkConfig = &linkArgs0.linkConfig;
        CpswPhy_Config         *phyConfig  = &linkArgs0.phyConfig;
        CpswMacPort_Interface  *interface  = &linkArgs0.interface;

        Cpsw_initMacPortParams(macConfig);

        BoardDiag_cpswChangeHostAleEntry(&gCpswLpbkObj.hostMacAddr[0U]);

        CpswAppBoardUtils_setPhyConfig(gCpswLpbkObj.cpswType,
                                       linkArgs0.portNum,
                                       macConfig,
                                       interface,
                                       phyConfig);

        macConfig->enableLoopback = false;
        linkConfig->speed     = CPSW_SPEED_AUTO;
        linkConfig->duplexity = CPSW_DUPLEX_AUTO;

        Cpsw_OpenPortLinkInArgs linkArgs1 = {
            .portNum = gCpswLpbkObj.portNum1,
        };

        macConfig = &linkArgs1.macConfig;
        linkConfig = &linkArgs1.linkConfig;
        phyConfig = &linkArgs1.phyConfig;
        interface = &linkArgs1.interface;

        Cpsw_initMacPortParams(macConfig);

        BoardDiag_cpswChangeHostAleEntry(&gCpswLpbkObj.hostMacAddr[0U]);

        CpswAppBoardUtils_setPhyConfig(gCpswLpbkObj.cpswType,
                                       linkArgs1.portNum,
                                       macConfig,
                                       interface,
                                       phyConfig);
        if(status == CPSW_PHY_INVALID_PHYADDR)
        {
            UART_printf("PHY configuration failed\n\r");
            return -1;
        }

        macConfig->enableLoopback = false;
        linkConfig->speed     = CPSW_SPEED_AUTO;
        linkConfig->duplexity = CPSW_DUPLEX_AUTO;

        CPSW_IOCTL_SET_IN_ARGS(&prms, &linkArgs0);

        status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                            gCpswLpbkObj.coreId,
                            CPSW_IOCTL_OPEN_PORT_LINK,
                            &prms);
        if (status != CPSW_SOK)
        {
            UART_printf("CpswApp_openCpsw() failed to open MAC port: %d\n",
                         status);
        }

        CPSW_IOCTL_SET_IN_ARGS(&prms, &linkArgs1);
        status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                            gCpswLpbkObj.coreId,
                            CPSW_IOCTL_OPEN_PORT_LINK,
                            &prms);
        if(status != CPSW_SOK)
        {
            UART_printf("CpswApp_openCpsw() failed to open MAC port: %d\n",
                         status);
        }

    }

    return status;
}

/**
 * \brief   This function is used to perform the CPSW9G
 *          Ethernet port to port external loopback test
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int32_t BoardDiag_cpswLoopbackTest(void)
{
    int32_t       status;
    bool          alive;
    uint8_t       index;

    Cpsw_IoctlPrms prms;
    CpswAle_SetPortStateInArgs setPortStateInArgs;

    CpswAppBoardUtils_init();
    CpswAppUtils_enableClocks(gCpswLpbkObj.cpswType);

    gCpswLpbkObj.coreId = CpswAppSoc_getCoreId();

    /* Open the CPSW */
    status = BoardDiag_cpswOpen();
    if (status != CPSW_SOK)
    {
        UART_printf("Failed to open CPSW: %d\n", status);
    }

    /* Open CPSW DMA driver */
    if (status == CPSW_SOK)
    {
        status = BoardDiag_cpswOpenDma();
        if (status != CPSW_SOK)
        {
            UART_printf("Failed to open CPSW DMA: %d\n", status);
        }
    }

    /* Enable host port */
    if (status == CPSW_SOK)
    {
        setPortStateInArgs.portNum   = CPSW_ALE_HOST_PORT_NUM;
        setPortStateInArgs.portState = CPSW_ALE_PORTSTATE_FORWARD;

        CPSW_IOCTL_SET_IN_ARGS(&prms,
                               &setPortStateInArgs);
        prms.outArgs = NULL;

        status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                            gCpswLpbkObj.coreId,
                            CPSW_ALE_IOCTL_SET_PORT_STATE,
                            &prms);
        if (status != CPSW_SOK)
        {
            UART_printf("CpswApp_openCpsw() failed CPSW_ALE_IOCTL_SET_PORT_STATE: %d\n", status);
        }

        if (status == CPSW_SOK)
        {
            status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                                gCpswLpbkObj.coreId,
                                CPSW_HOSTPORT_IOCTL_ENABLE,
                                NULL);
            if (status != CPSW_SOK)
            {
                UART_printf("Failed to enable host port: %d\n", status);
            }
        }
    }

    /* Show alive PHYs */
    if (status == CPSW_SOK)
    {
        for (index = CPSW_PHY_START_ADDRESS; index < CPSW_PHY_END_ADDRESS; index++)
        {
            CPSW_IOCTL_SET_INOUT_ARGS(&prms, &index, &alive);

            status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                                gCpswLpbkObj.coreId,
                                CPSW_MDIO_IOCTL_GET_ALIVE_STATUS,
                                &prms);
            if (status == CPSW_SOK)
            {
                if (alive == true)
                {
                    UART_printf("PHY %d is alive\n", index);
                }
            }
            else
            {
                UART_printf("Failed to get PHY %d alive status: %d\n", index,
                             status);
            }
        }
    }

    UART_printf("Waiting for link to up for portNum-%d and portNum-%d...\n\r",
                 gCpswLpbkObj.portNum0,
                 gCpswLpbkObj.portNum1);

    if (status == CPSW_SOK)
    {

        while (!CpswAppUtils_isPortLinkUp(gCpswLpbkObj.hCpsw,
                                          gCpswLpbkObj.coreId,
                                          gCpswLpbkObj.portNum0))
        {
            Cpsw_periodicTick(gCpswLpbkObj.hCpsw);
            BoardDiag_cpswWait(1000);
        }

        while (!CpswAppUtils_isPortLinkUp(gCpswLpbkObj.hCpsw,
                                          gCpswLpbkObj.coreId,
                                          gCpswLpbkObj.portNum1))
        {
            Cpsw_periodicTick(gCpswLpbkObj.hCpsw);
            BoardDiag_cpswWait(1000);
        }

        UART_printf("Link up for portNum-%d and portNum-%d\n\r",
                     gCpswLpbkObj.portNum0,
                     gCpswLpbkObj.portNum1);

        BoardDiag_cpswWait(20000);
        UART_printf("Started with the packet rx tx test\n\r");
        status = BoardDiag_cpswPktRxTx();
        if (status != CPSW_SOK)
        {
            UART_printf("Failed to enable host port: %d\n", status);
            return -1;
        }
    }

    /* Print CPSW statistics of all ports */
    BoardDiag_cpswShowStats();

    /* Disable host port */
    status = Cpsw_ioctl(gCpswLpbkObj.hCpsw,
                        gCpswLpbkObj.coreId,
                        CPSW_HOSTPORT_IOCTL_DISABLE,
                        NULL);
    if (status != CPSW_SOK)
    {
        UART_printf("Failed to disable host port: %d\n", status);
        return -1;
    }

    /* Close CPSW DMA driver */
    BoardDiag_cpswCloseDma();
    /* Close CPSW */
    BoardDiag_cpswClose();
    /* Close UDMA driver */
    CpswAppUtils_udmaclose(gCpswLpbkObj.hUdmaDrv);

    CpswAppUtils_disableClocks(gCpswLpbkObj.cpswType);
    CpswAppBoardUtils_deInit();

    return 0;
}

/**
 *  \brief    This function runs CPSW9G ethernet test
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_CpswEthRunTest(void)
{
    int8_t ret;
    uint8_t userInput;

    UART_printf  ("************************************************\n");
    UART_printf  ("*             CPSW Ethernet Test           *\n");
    UART_printf  ("************************************************\n");

    /* This should not be removed, as this is fix for linker issue in release mode.
     * If removed linker will complain "undefined reference to `_sbrk'".
     * This arises whenever library invokes printf() but the app doesn't.
     */
#ifndef UART_ENABLED
    printf( "CPSW Bare metal Loopback App \n");
#endif

    UART_printf("Loopback test for Port 0\n\r");

    UART_printf("Select any one option from below\n\r");
    UART_printf("1 - PRG0 ports verification\n\r");
    UART_printf("2 - PRG1 ports verification\n\r");

    UART_scanFmt("%d", &userInput);

    while((userInput != PRG0_PORT_VERIFICATION) &&
          (userInput != PRG1_PORT_VERIFICATION))
    {
        UART_printf("Invalid userInput, Please try again\n\r");
        UART_scanFmt("%d", &userInput);
    }

    if(userInput == PRG0_PORT_VERIFICATION)
    {
        gCpswLpbkObj.portNum0 = CPSW_MAC_PORT_2;
        gCpswLpbkObj.portNum1 = CPSW_MAC_PORT_3;
    }
    else
    {
        gCpswLpbkObj.portNum0 = CPSW_MAC_PORT_0;
        gCpswLpbkObj.portNum1 = CPSW_MAC_PORT_1;
    }

    /* Run the loopback test */
    ret = BoardDiag_cpswLoopbackTest();
    if(ret == -1)
    {
        UART_printf("CPSW Loopback Test failed\n\r");
        return -1;
    }

    return ret;
}

/**
 * \brief  CPSW diagnostic test main function
 *
 *  This function performs board initializations and calls cpsw9g ethernet test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
int main(void)
{
    Board_initCfg boardCfg;
    Board_STATUS status;
    int8_t ret = 0;

    Board_PinmuxConfig_t gesiIcssgPinmux;

    Board_pinmuxGetCfg(&gesiIcssgPinmux);
    gesiIcssgPinmux.autoCfg = BOARD_PINMUX_CUSTOM;
    gesiIcssgPinmux.gesiExp = BOARD_PINMUX_GESI_CPSW9G;
    Board_pinmuxSetCfg(&gesiIcssgPinmux);

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO |
               BOARD_INIT_ETH_PHY;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    /* Enable CPSW9G MDIO mux */
    status = Board_control(BOARD_CTRL_CMD_SET_CPSW9G_MDIO_MUX,
                           NULL);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    boardCfg = BOARD_INIT_CPSW9G_ETH_PHY;
    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }


    ret = BoardDiag_CpswEthRunTest();
    if(ret == 0)
    {
        UART_printf("CPSW loopback test completed successfully\n");
    }

    return ret;

}
