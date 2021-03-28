/*
 *  Copyright (C) 2019 Texas Instruments Incorporated
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

/**
 *  \file st_crcSemiCPU.c
 *
 *  \brief Common across test-cases using CRC Semi-CPU mode.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_crc.h>
#include <ti/drv/udma/udma.h>
#include <ti/drv/udma/examples/udma_apputils/udma_apputils.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/** \brief Number of times to perform the CRC operation */
#define ITERATION_COUNT          (20U)

/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much CRC operations */
#define UDMA_TEST_APP_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES * \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)
/**
 *  \brief UDMA TR packet descriptor memory.
 *  This contains the CSL_UdmapCppi5TRPD + Padding to sizeof(CSL_UdmapTR15) +
 *  one Type_15 TR (CSL_UdmapTR15) + one TR response of 4 bytes.
 *  Since CSL_UdmapCppi5TRPD is less than CSL_UdmapTR15, size is just two times
 *  CSL_UdmapTR15 for alignment.
 */
#define UDMA_TEST_APP_TRPD_SIZE         ((sizeof(CSL_UdmapTR15) * 2U) + 4U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaChObj;
struct Udma_EventObj    gUdmaCqEventObj;
struct Udma_EventObj    gUdmaTdCqEventObj;

/*
 * UDMA Memories
 */
static uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxTdCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaTprdMem[UDMA_TEST_APP_TRPD_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

/* Semaphore to indicate transfer completion */
static SemaphoreP_Handle gUdmaAppDoneSem = NULL;


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static int32_t st_crcSemiCPU_crcTest(Udma_ChHandle chHandle,
                                     st_CRCTestcaseParams_t *testParams);
static int32_t st_crcSemiCPU_udmaCrc(Udma_ChHandle chHandle,
                           st_CRCTestcaseParams_t *testParams,
                           crcSignature_t           refSignVal);
static void st_crcSemiCPU_udmaEventCb(Udma_EventHandle eventHandle,
                            uint32_t eventType,
                            void *appData);

static int32_t st_crcSemiCPU_create(Udma_DrvHandle drvHandle, Udma_ChHandle chHandle);
static int32_t st_crcSemiCPU_delete(Udma_DrvHandle drvHandle, Udma_ChHandle chHandle);

static void st_crcSemiCPU_udmaTrpdInit(Udma_ChHandle chHandle,
                                       uint8_t *pTrpdMem,
                                       const void *srcBuf,
                                       const void *destBuf,
                                       uint32_t length,
                                       uint32_t patternSize);

static void st_crcSemiCPU_crcInit(st_CRCTestcaseParams_t *testParams);
static void App_print(const char *str);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_crcSemiCPU_init(void)
{
    int32_t         retVal;
    Udma_InitPrms   initPrms;
    uint32_t        instId;
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj;

    /* Use MCU NAVSS for MCU domain cores. Rest all cores uses Main NAVSS */
#if defined (BUILD_MCU1_0) || defined (BUILD_MCU1_1)
    instId = UDMA_INST_ID_MCU_0;
#else
    instId = UDMA_INST_ID_MAIN_0;
#endif
    /* UDMA driver init */
    UdmaInitPrms_init(instId, &initPrms);
#if defined (QT_BUILD)
    initPrms.skipRmOverlapCheck = TRUE;
#endif
    initPrms.printFxn = &App_print;
    retVal = Udma_init(drvHandle, &initPrms);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] UDMA init failed!!\n");
    }

    return (retVal);
}

int32_t st_crcSemiCPU_deinit(void)
{
    int32_t         retVal;
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj;

    retVal = Udma_deinit(drvHandle);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] UDMA deinit failed!!\n");
    }

    return (retVal);
}


int32_t st_crcSemiCPU_main(st_CRCTestcaseParams_t *testParams)
{
    int32_t         retVal = CSL_PASS;
    int32_t         retVal1 = CSL_PASS;
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj;
    Udma_ChHandle   chHandle = &gUdmaChObj;

    st_crcSemiCPU_crcInit(testParams);

    retVal = st_crcSemiCPU_create(drvHandle, chHandle);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] crcSemiCPU App create failed!!\n");
    }

    if(CSL_PASS == retVal)
    {
        retVal = st_crcSemiCPU_crcTest(chHandle, testParams);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] crcSemiCPU App CRC test failed!!\n");
        }
    }

    retVal1 = st_crcSemiCPU_delete(drvHandle, chHandle);
    if(CSL_PASS != retVal1)
    {
        UART_printf("[Error] crcSemiCPU App delete failed!!\n");
    }

    return (retVal + retVal1);
}


/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static int32_t st_crcSemiCPU_crcTest(Udma_ChHandle chHandle,
                                     st_CRCTestcaseParams_t *testParams)
{
    int32_t     retVal = CSL_PASS;
    uint32_t    i;
    uint32_t    dataSize;
    uint32_t   *crcSourceMemory;
    uint32_t    loopCnt = 0U;
    uint64_t    timeStampBeforeCrcConfig, timeStampAfterCrcComplete;
    uint32_t    crcCompletionTime;
    Float32     crcSemiCPUPerformance;
    uint32_t    crcSemiCPUPerformanceInt;
    crcSignature_t refSignVal;


    /* Init buffers */
    crcSourceMemory = (uint32_t *) testParams->sourceMemory;
    dataSize = (testParams->dataSize);
    for (i = 0; i < (dataSize / 4); i++)
    {
        crcSourceMemory[i] = i;
    }
    UART_printf("\nCopied reference data into memory @%x.",  testParams->sourceMemory);

    /* Writeback source buffer */
    Udma_appUtilsCacheWb(crcSourceMemory, dataSize);

    /* Get the reference crc sign value. */
    if ((0U == testParams->crcConfigParams.crcSignHigh) &&
        (0U == testParams->crcConfigParams.crcSignLow))
    {
        uint32_t crcModuleBaseAddress = testParams->crcConfigParams.crcInstBaseAddr;
        crcChannel_t crcChannelNumber = testParams->crcConfigParams.crcChannelNumber;
        uint32_t crcPatternSize       = testParams->crcConfigParams.crcPatternSize;
        uint32_t crcPatterCount       = (testParams->dataSize) / crcPatternSize;
        uint32_t crcSectorCount       = testParams->crcConfigParams.crcSectorCount;
        crcSignatureRegAddr_t crcPSASignatureRegAddress;
        uint32_t forLoopCount;

        /* Configure the CRC module in Full CPU mode and get reference CRC. */
        UART_printf("\nCalculating Reference CRC signature Value.");
        /* CRC channel RESET before initialization/configuration. */
        retVal = CRCChannelReset(crcModuleBaseAddress, crcChannelNumber);

        if (retVal == CSL_PASS)
        {
            /* Initialize CRC channel */
            retVal = CRCConfigure(crcModuleBaseAddress,
                                  crcChannelNumber,
                                  crcPatterCount,
                                  crcSectorCount,
                                  CRC_OPERATION_MODE_FULLCPU);
        }

        if (retVal == CSL_PASS)
        {
            /* Get CRC PSA signature register address */
            retVal = CRCGetPSASigRegAddr(crcModuleBaseAddress,
                                         crcChannelNumber,
                                         &crcPSASignatureRegAddress);
        }
        
        if (retVal == CSL_PASS)
        {
            for (forLoopCount = 0;
                 forLoopCount < (dataSize / crcPatternSize);
                 forLoopCount++)
            {
                HW_WR_REG32(crcPSASignatureRegAddress.regL,
                            crcSourceMemory[forLoopCount]);
            }
            /* Fetch CRC signature value       */
            retVal = CRCGetPSASectorSig(crcModuleBaseAddress,
                                        crcChannelNumber,
                                        &refSignVal);
        }
        if (retVal == CSL_PASS)
        {
            UART_printf("\n CRC signature value : 0x%x%xU",
                        refSignVal.regH,
                        refSignVal.regL);
        }
    }
    else
    {
        UART_printf("\nUsing Pre-Defined Reference CRC signature Value.");
        refSignVal.regH = testParams->crcConfigParams.crcSignHigh;
        refSignVal.regL = testParams->crcConfigParams.crcSignLow;
    }

    if (retVal == CSL_PASS)
    {
        /*      Get time-stamp     */
        timeStampBeforeCrcConfig = TimerP_getTimeInUsecs();
        while(loopCnt < ITERATION_COUNT)
        {
            /* Perform UDMA CRC */
            retVal = st_crcSemiCPU_udmaCrc(chHandle, testParams, refSignVal);
            if(CSL_PASS != retVal)
            {
                break;
            }

            loopCnt++;
        }
        /*      get the time-stamp       */
        timeStampAfterCrcComplete = TimerP_getTimeInUsecs();
    }

    if(CSL_PASS == retVal)
    {
        UART_printf("\nCRC signature verification done successfully.");
        if (ST_TT_PERFORMANCE ==
            (testParams->testType & ST_TT_PERFORMANCE))
        {
            crcCompletionTime = (uint32_t) ((timeStampAfterCrcComplete -
                                  timeStampBeforeCrcConfig) / 1000U);
            crcSemiCPUPerformance =
                (Float32) (((Float32) testParams->dataSize) / crcCompletionTime) * 1000U ;
            crcSemiCPUPerformance = ((Float32) crcSemiCPUPerformance) *
                                    ((Float32) ITERATION_COUNT);
            crcSemiCPUPerformance = (Float32) crcSemiCPUPerformance /
                                    (1024U * 1024U);
            crcSemiCPUPerformanceInt = (uint32_t) crcSemiCPUPerformance;
            UART_printf("\nProcessed data of size %u Bytes %d times in %u ms."
                   , testParams->dataSize, ITERATION_COUNT,
                   crcCompletionTime);
            UART_printf("\nCRC performance: %u MB/s", crcSemiCPUPerformanceInt);
        }
        testParams->testResult = CSL_PASS;
    }
    else
    {
        UART_printf("\nCRC signature verification failed.");
        testParams->testResult = CSL_EFAIL;
    }


    return (retVal);
}

static int32_t st_crcSemiCPU_udmaCrc(Udma_ChHandle  chHandle,
                           st_CRCTestcaseParams_t   *testParams,
                           crcSignature_t           refSignVal)
{
    int32_t               retVal = CSL_PASS;
    uint32_t             *pTrResp, trRespStatus;
    uint64_t              pDesc = 0;
    uint8_t              *tprdMem = &gUdmaTprdMem[0U];
    crcSignature_t        sectSignVal;
    crcSignatureRegAddr_t psaSignRegAddr;
    uint32_t              patternCnt, sectCnt;
    uint32_t              crcBaseAddr;
    crcChannel_t          crcChannel;

    sectSignVal.regL = 0U;
    sectSignVal.regH = 0U;
    patternCnt  = testParams->dataSize / testParams->crcConfigParams.crcPatternSize;
    sectCnt     = testParams->crcConfigParams.crcSectorCount;
    crcBaseAddr = testParams->crcConfigParams.crcInstBaseAddr;
    crcChannel  = testParams->crcConfigParams.crcChannelNumber;

    /* Get CRC PSA signature register address */
    CRCGetPSASigRegAddr(crcBaseAddr, crcChannel, &psaSignRegAddr);
    CRCChannelReset(crcBaseAddr, crcChannel);
    CRCConfigure(crcBaseAddr, crcChannel, patternCnt, sectCnt, CRC_OPERATION_MODE_SEMICPU);

    /* Update TR packet descriptor */
    st_crcSemiCPU_udmaTrpdInit(chHandle,
        tprdMem,
        (void *) testParams->sourceMemory,
        (void *)(uintptr_t) psaSignRegAddr.regL,
        testParams->dataSize,
        testParams->crcConfigParams.crcPatternSize);

    /* Submit TRPD to channel */
    retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(chHandle), (uint64_t) tprdMem);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] Channel queue failed!!\n");
    }

    if(CSL_PASS == retVal)
    {
        /* Wait for return descriptor in completion ring - this marks the
         * transfer completion */
        SemaphoreP_pend(gUdmaAppDoneSem, SemaphoreP_WAIT_FOREVER);

        /* Response received in completion queue */
        retVal = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(chHandle), &pDesc);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] No descriptor after callback!!\n");
            retVal = CSL_EFAIL;
        }
    }

    if(CSL_PASS == retVal)
    {
        /*
         * Sanity check
         */
        /* Check returned descriptor pointer */
        if(pDesc != ((uint64_t) tprdMem))
        {
            UART_printf("[Error] TR descriptor pointer returned doesn't "
                   "match the submitted address!!\n");
            retVal = CSL_EFAIL;
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Invalidate cache */
        Udma_appUtilsCacheInv(&gUdmaTprdMem[0U], UDMA_TEST_APP_TRPD_SIZE);

        /* check TR response status */
        pTrResp = (uint32_t *) (tprdMem + (sizeof(CSL_UdmapTR15) * 2U));
        trRespStatus = CSL_FEXT(*pTrResp, UDMAP_TR_RESPONSE_STATUS_TYPE);
        if(trRespStatus != CSL_UDMAP_TR_RESPONSE_STATUS_COMPLETE)
        {
            UART_printf("[Error] TR Response not completed!!\n");
            retVal = CSL_EFAIL;
        }
    }

    if(CSL_PASS == retVal)
    {
        uint32_t intrStatus = 0U;

        while ((intrStatus == 0x0U) && (CSL_PASS == retVal))
        {
            /* Wait here till CRC compression complete is set. */
            retVal = CRCGetIntrStatus(crcBaseAddr, crcChannel, &intrStatus);
        }
    }

    if (CSL_PASS == retVal)
    {
        retVal = CRCGetPSASectorSig(crcBaseAddr, crcChannel, &sectSignVal);
    }

    if (CSL_PASS == retVal)
    {
        /* Compare CRC signature value against reference CRC signature */
        if((sectSignVal.regH == refSignVal.regH) &&
           (sectSignVal.regL == refSignVal.regL))
        {
            /* Sector signature matches - Passed */
        }
        else
        {
            retVal = CSL_EFAIL;
            UART_printf("\nSector signature does not match.");
            UART_printf("\nExpected CRC signature value : 0x%x%xU",
                   refSignVal.regH,
                   refSignVal.regL);
            UART_printf("\nCalculated CRC signature value : 0x%08x%08xU",
                   sectSignVal.regH,
                   sectSignVal.regL);
        }
        retVal = CRCClearIntr(crcBaseAddr, crcChannel, CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL);
    }

    return (retVal);
}


static void st_crcSemiCPU_udmaEventCb(Udma_EventHandle eventHandle,
                            uint32_t eventType,
                            void *appData)
{
    int32_t         retVal;
    CSL_UdmapTdResponse tdResp;

    if(UDMA_EVENT_TYPE_DMA_COMPLETION == eventType)
    {
        SemaphoreP_post(gUdmaAppDoneSem);
    }
    if(UDMA_EVENT_TYPE_TEARDOWN_PACKET == eventType)
    {
        /* Response received in Teardown completion queue */
        retVal = Udma_chDequeueTdResponse(&gUdmaChObj, &tdResp);
        if(CSL_PASS != retVal)
        {
            /* [Error] No TD response after callback!! */
        }
    }

    return;
}

static int32_t st_crcSemiCPU_create(Udma_DrvHandle drvHandle, Udma_ChHandle chHandle)
{
    int32_t             retVal = CSL_PASS;
    uint32_t            chType;
    Udma_ChPrms         chPrms;
    Udma_ChTxPrms       txPrms;
    Udma_ChRxPrms       rxPrms;
    Udma_EventHandle    eventHandle;
    Udma_EventPrms      eventPrms;
    SemaphoreP_Params   semPrms;

    SemaphoreP_Params_init(&semPrms);
    gUdmaAppDoneSem = SemaphoreP_create(0, &semPrms);
    if(NULL == gUdmaAppDoneSem)
    {
        UART_printf("[Error] Sem create failed!!\n");
        retVal = CSL_EFAIL;
    }

    if(CSL_PASS == retVal)
    {
        /* Init channel parameters */
        chType = UDMA_CH_TYPE_TR_BLK_COPY;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.fqRingPrms.ringMem   = &gTxRingMem[0U];
        chPrms.cqRingPrms.ringMem   = &gTxCompRingMem[0U];
        chPrms.tdCqRingPrms.ringMem = &gTxTdCompRingMem[0U];
        chPrms.fqRingPrms.ringMemSize   = UDMA_TEST_APP_RING_MEM_SIZE;
        chPrms.cqRingPrms.ringMemSize   = UDMA_TEST_APP_RING_MEM_SIZE;
        chPrms.tdCqRingPrms.ringMemSize = UDMA_TEST_APP_RING_MEM_SIZE;
        chPrms.fqRingPrms.elemCnt   = UDMA_TEST_APP_RING_ENTRIES;
        chPrms.cqRingPrms.elemCnt   = UDMA_TEST_APP_RING_ENTRIES;
        chPrms.tdCqRingPrms.elemCnt = UDMA_TEST_APP_RING_ENTRIES;

        /* Open channel for block copy */
        retVal = Udma_chOpen(drvHandle, chHandle, chType, &chPrms);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA channel open failed!!\n");
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Config TX channel */
        UdmaChTxPrms_init(&txPrms, chType);
        retVal = Udma_chConfigTx(chHandle, &txPrms);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA TX channel config failed!!\n");
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Config RX channel - which is implicitly paired to TX channel in
         * block copy mode */
        UdmaChRxPrms_init(&rxPrms, chType);
        retVal = Udma_chConfigRx(chHandle, &rxPrms);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA RX channel config failed!!\n");
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Register ring completion callback */
        eventHandle = &gUdmaCqEventObj;
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = chHandle;
        eventPrms.masterEventHandle = NULL;
        eventPrms.eventCb           = &st_crcSemiCPU_udmaEventCb;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA CQ event register failed!!\n");
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Register teardown ring completion callback */
        eventHandle = &gUdmaTdCqEventObj;
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_TEARDOWN_PACKET;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = chHandle;
        eventPrms.masterEventHandle = &gUdmaCqEventObj;
        eventPrms.eventCb           = &st_crcSemiCPU_udmaEventCb;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA Teardown CQ event register failed!!\n");
        }
    }

    if(CSL_PASS == retVal)
    {
        /* Channel enable */
        retVal = Udma_chEnable(chHandle);
        if(CSL_PASS != retVal)
        {
            UART_printf("[Error] UDMA channel enable failed!!\n");
        }
    }

    return (retVal);
}

static int32_t st_crcSemiCPU_delete(Udma_DrvHandle drvHandle, Udma_ChHandle chHandle)
{
    int32_t             retVal;
    Udma_EventHandle    eventHandle;

    retVal = Udma_chDisable(chHandle, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] UDMA channel disable failed!!\n");
    }

    /* Unregister master event at the end */
    eventHandle = &gUdmaTdCqEventObj;
    retVal += Udma_eventUnRegister(eventHandle);
    eventHandle = &gUdmaCqEventObj;
    retVal += Udma_eventUnRegister(eventHandle);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] UDMA event unregister failed!!\n");
    }

    retVal += Udma_chClose(chHandle);
    if(CSL_PASS != retVal)
    {
        UART_printf("[Error] UDMA channel close failed!!\n");
    }

    if(gUdmaAppDoneSem != NULL)
    {
        SemaphoreP_delete(gUdmaAppDoneSem);
        gUdmaAppDoneSem = NULL;
    }

    return (retVal);
}

static void st_crcSemiCPU_udmaTrpdInit(Udma_ChHandle chHandle,
                                       uint8_t *pTrpdMem,
                                       const void *srcBuf,
                                       const void *destBuf,
                                       uint32_t length,
                                       uint32_t patternSize)
{
    CSL_UdmapCppi5TRPD *pTrpd = (CSL_UdmapCppi5TRPD *) pTrpdMem;
    CSL_UdmapTR15 *pTr = (CSL_UdmapTR15 *)(pTrpdMem + sizeof(CSL_UdmapTR15));
    uint32_t *pTrResp = (uint32_t *) (pTrpdMem + (sizeof(CSL_UdmapTR15) * 2U));
    uint32_t cqRingNum = Udma_chGetCqRingNum(chHandle);
    uint32_t cCnt;

    /* Make TRPD */
    UdmaUtils_makeTrpd(pTrpd, UDMA_TR_TYPE_15, 1U, cqRingNum);

    /* Setup TR */
    cCnt = 1;
    while ((length / cCnt) > 0x7FFFU)
    {
        cCnt = cCnt * 2;
    }
    pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, 15)                                            |
                    CSL_FMK(UDMAP_TR_FLAGS_STATIC, 0U)                                          |
                    CSL_FMK(UDMAP_TR_FLAGS_EOL, 0U)                                             |   /* NA */
                    CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                    CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, 0x25U)                                       |   /* This will come back in TR response */
                    CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, 0U)                                     |
                    CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, 0U)                                     |
                    CSL_FMK(UDMAP_TR_FLAGS_EOP, 1U);
    pTr->icnt0    = patternSize;
    pTr->icnt1    = (length / patternSize) / cCnt;
    pTr->icnt2    = cCnt;
    pTr->icnt3    = 1U;
    pTr->dim1     = pTr->icnt0;
    pTr->dim2     = (pTr->icnt0 * pTr->icnt1);
    pTr->dim3     = (pTr->icnt0 * pTr->icnt1 * pTr->icnt2);
    pTr->addr     = (uint64_t) srcBuf;
    pTr->fmtflags = 0x00000000U;        /* Linear addressing, 1 byte per elem.
                                           Replace with CSL-FL API */
    pTr->dicnt0   = patternSize;
    pTr->dicnt1   = (length / pTr->dicnt0) / cCnt;
    pTr->dicnt2   = cCnt;
    pTr->dicnt3   = 1U;
    pTr->ddim1    = 0U;
    pTr->ddim2    = 0U;
    pTr->ddim3    = 0U;
    pTr->daddr    = (uint64_t) destBuf;

    /* Clear TR response memory */
    *pTrResp = 0xFFFFFFFFU;

    /* Writeback cache */
    Udma_appUtilsCacheWb(pTrpdMem, UDMA_TEST_APP_TRPD_SIZE);

    return;
}

static void st_crcSemiCPU_crcInit(st_CRCTestcaseParams_t *testParams)
{
    /* Configure CRC channel */
    CRCInitialize(
        testParams->crcConfigParams.crcInstBaseAddr,
        testParams->crcConfigParams.crcChannelNumber,
        testParams->crcConfigParams.crcWatchdogPreload,
        testParams->crcConfigParams.crcBlockPreload);

    return;
}

static void App_print(const char *str)
{
    UART_printf("%s", str);
    return;
}
