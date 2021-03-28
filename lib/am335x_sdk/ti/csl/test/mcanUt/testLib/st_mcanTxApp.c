/*
 *  Copyright (C) 2015 Texas Instruments Incorporated
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
 *  \file     st_mcanNormalMode.c
 *
 *  \brief    This file contains mcan test code.
 *
 *  \details  mcan operational mode is set to normal mode for group 1.
 *            EVE reset interrupt is enabled from group 1 and
 *            it's priority is set as high level interrupt.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/cslr_mcan.h>
#include <ti/csl/csl_mcan.h>
#include <st_mcan.h>
#include <utils_prf.h>
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
#include <ti/csl/csl_edma.h>
#include <ti/csl/cslr_synctimer.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/drv/pm/pmhal.h>
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
#include <ti/drv/udma/udma.h>
#include <ti/drv/udma/examples/udma_apputils/udma_apputils.h>
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define APP_MCAN_STD_ID_MASK              (0x7FFU << 18U)
#define APP_MCAN_EXT_ID_MASK              (0x1FFFFFFFU)
#define APP_MCAN_STD_ID_SHIFT             (18U)
#define APP_MCAN_EXT_ID_SHIFT             (0U)

/**
 * \brief  Mask and shift for Tx Buffers elements.
 */
#define MCANSS_TX_BUFFER_ELEM_ID_SHIFT                           (0U)
#define MCANSS_TX_BUFFER_ELEM_ID_MASK                            (0x1FFFFFFFU)
#define MCANSS_TX_BUFFER_ELEM_RTR_SHIFT                          (29U)
#define MCANSS_TX_BUFFER_ELEM_RTR_MASK                           (0x20000000U)
#define MCANSS_TX_BUFFER_ELEM_XTD_SHIFT                          (30U)
#define MCANSS_TX_BUFFER_ELEM_XTD_MASK                           (0x40000000U)
#define MCANSS_TX_BUFFER_ELEM_ESI_SHIFT                          (31U)
#define MCANSS_TX_BUFFER_ELEM_ESI_MASK                           (0x80000000U)
#define MCANSS_TX_BUFFER_ELEM_DLC_SHIFT                          (16U)
#define MCANSS_TX_BUFFER_ELEM_DLC_MASK                           (0x000F0000U)
#define MCANSS_TX_BUFFER_ELEM_BRS_SHIFT                          (20U)
#define MCANSS_TX_BUFFER_ELEM_BRS_MASK                           (0x00100000U)
#define MCANSS_TX_BUFFER_ELEM_FDF_SHIFT                          (21U)
#define MCANSS_TX_BUFFER_ELEM_FDF_MASK                           (0x00200000U)
#define MCANSS_TX_BUFFER_ELEM_EFC_SHIFT                          (23U)
#define MCANSS_TX_BUFFER_ELEM_EFC_MASK                           (0x00800000U)
#define MCANSS_TX_BUFFER_ELEM_MM_SHIFT                           (24U)
#define MCANSS_TX_BUFFER_ELEM_MM_MASK                            (0xFF000000U)


#define EDMA3_CC_REGION_M4                                (1U)
#ifdef __TI_ARM_V7M4__
    #define XBAR_CPU                          (CSL_XBAR_IRQ_CPU_ID_IPU1)
    /* DMA configuration related macros */
    #define EDMA3_CC_XFER_COMPLETION_INT       (38U)
    #define EDMA3_CC_REGION                    (EDMA3_CC_REGION_M4)
    #define XBAR_DMA_INST                      (CSL_XBAR_INST_IPU1_IRQ_38)
    #define XBAR_DMA_INTR_SOURCE               (CSL_XBAR_EDMA_TPCC_IRQ_REGION1)
#endif


#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* MCAN Tx DMA Event */
    #define DMA_EVENT_SOURCE_TX                (CSL_XBAR_DMA_DCAN2_DREQ_IF1)
    /* MCAN Rx Filter Event */
    #define DMA_EVENT_SOURCE_RX                (CSL_XBAR_DMA_DCAN2_DREQ_IF2)
#elif defined (SOC_TDA2PX)
    /* MCAN Tx DMA Event */
    #define DMA_EVENT_SOURCE_TX                (CSL_XBAR_DMA_MCAN_DREQ_TX)
    /* MCAN Rx Filter Event */
    #define DMA_EVENT_SOURCE_RX                (CSL_XBAR_DMA_MCAN_DREQ_RX_FE1)
#endif

#if defined (SOC_AM65XX) || defined (SOC_J721E)
/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_MCAN_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_MCAN_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_MCAN_RING_MEM_SIZE     (UDMA_MCAN_RING_ENTRIES * \
                                         UDMA_MCAN_RING_ENTRY_SIZE)

/*
 * UDMA parameters
 */
#define UDMA_MCAN_PDMA_TX_CH_NUM    (UDMA_PDMA_CH_MCU_MCAN0_CH0_TX)
#define UDMA_MCAN_PDMA_RX_CH_NUM    (UDMA_PDMA_CH_MCU_MCAN0_CH0_RX)
/**
 *  \brief UDMA host packet descriptor memory.
 *  This contains the CSL_UdmapCppi5HMPD + Protocol specific word (2 words
 *  of MCAN header) + Padding (2 words) (64 bytes aligned)
 */
#define UDMA_MCAN_HPD_SIZE          ((sizeof(CSL_UdmapCppi5HMPD) + 8U + 8U))
/** \brief Cache line size for alignment of descriptor and buffers */
#define CACHELINE_SIZE              (128U)

#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
extern uint32_t                mcanBaseAddr;
extern uint32_t                uartBaseAddr;
extern uint32_t          gMcanAppdataSize[16];
extern volatile uint32_t gMcanIsrIntr0Flag;
extern volatile uint32_t gMcanIsrIntr1Flag;
extern volatile uint32_t gMcanECCIntrFlag;
extern MCAN_ECCErrStatus gMcaneccErr;
extern volatile uint32_t gMcanIsrIntr0Status;
extern volatile uint32_t gMcanIsrIntr1Status;
extern volatile uint32_t gMcanExtTSIntrFlag;
extern MCAN_BitTimingParams canFDBitTimings[];
volatile uint32_t    rxBuffNum;
extern uint32_t autoRunEnable;
volatile uint32_t isrPrintEnable = (uint32_t)FALSE;
uint32_t objSize[8] = {4, 5, 6, 7, 8, 10, 14, 18};
uint32_t dataSize[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
/* 1 full CAN FD message = 18 words and put this in .data section */
uint32_t txBuffer[500U * 18U] __attribute__(( aligned(128), section(".data") )) = {1U};
uint32_t rxBuffer[500U * 18U] __attribute__(( aligned(128), section(".data") )) = {1U};

#if defined (SOC_AM65XX) || defined (SOC_J721E)

/*
 * UDMA driver objects
 */
struct Udma_DrvObj  gUdmaDrvObj;
struct Udma_ChObj   gUdmaTxChObj;
struct Udma_ChObj   gUdmaRxChObj;

/*
 * UDMA Memories
 */
static uint8_t              gTxRingMem[UDMA_MCAN_RING_MEM_SIZE] __attribute__((aligned(CACHELINE_SIZE)));
static uint8_t              gTxCompRingMem[UDMA_MCAN_RING_MEM_SIZE] __attribute__((aligned(CACHELINE_SIZE)));
static uint8_t              gTxHpdMem[UDMA_MCAN_HPD_SIZE] __attribute__((aligned(CACHELINE_SIZE)));

static uint8_t              gRxRingMem[UDMA_MCAN_RING_MEM_SIZE] __attribute__((aligned(CACHELINE_SIZE)));
static uint8_t              gRxCompRingMem[UDMA_MCAN_RING_MEM_SIZE] __attribute__((aligned(CACHELINE_SIZE)));
static uint8_t              gRxHpdMem[UDMA_MCAN_HPD_SIZE] __attribute__((aligned(CACHELINE_SIZE)));

#endif

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
static volatile uint32_t edmaTransferComplete = 1U;
static uint32_t edmaEvtqNumber, edmaTCCNumber, edmaChannelNumber,
                  edmaInterruptNumber;
static uint32_t edmaEvtqNumberCh2, edmaTCCNumberCh2, edmaChannelNumberCh2;
static EDMA3CCPaRAMEntry edmaParam;
#endif
extern uint32_t                gMcanModuleIdx;
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This function will configure MCAN module
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanConfig(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains MCAN Tx Test
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanTxTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains MCAN Tx Test for performance test
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
int32_t App_mcanPerfTxTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function will check TC pass/fail criteria apart from Tx/Rx
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      Execution status.
 */
static int32_t App_mcanCheckTCResultsMisc(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function will check received message against transferred.
 *
 * \param   txMsg       Tx Message.
 * \param   rxMsg       Rx Message.
 *
 * \retval  status      Check status.
 */
static int32_t App_mcanTxRxMessageCheck(MCAN_TxBufElement txMsg,
                                        MCAN_RxBufElement rxMsg);

/**
 * \brief   This function will check received message against transferred.
 *
 * \param   rxMsg       Read Rx Message.
 * \param   status      Interrupt Status.
 *
 * \retval  status      Check status.
 */
static int32_t App_mcanReadRxMSG(MCAN_RxBufElement *rxMsg,
                                 uint32_t status);

/**
 * \brief   This function will configure receiver or other things depending on
 *          TC parameters.
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      Execution status.
 */
static int32_t App_mcanTCEntrySetup(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function will configure receiver or other things for next TC.
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      Execution status.
 */
static int32_t App_mcanTCExitSetup(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function will send a message to change the receiver side
 *          application baud-rate.
 *
 * \param   idx         'canFDBitTimings' array index.
 *
 * \retval  status      Execution status.
 */
static int32_t App_mcanChangeBaudrateMSG(uint32_t idx);

/**
 * \brief   This function will check transmitted message against Tx Event Entry.
 *
 * \param   txMsg       Tx Message.
 * \param   rxMsg       Tx Event Message.
 *
 * \retval  status      Check status.
 */
static int32_t App_mcanTxEventMessageCheck(MCAN_TxBufElement txMsg,
                                           MCAN_TxEventFIFOElement txEventMsg);

/**
 * \brief   This function contains MCAN ECC Test
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanECCTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains code for MCAN ECC Self Test/Diagnostic mode
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanECCSelfTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function used CAN message to DDR. CAN be used for any memory.
 *
 * \param   addr            Address where message to be written.
 * \param   elem            Tx Element.
 *
 * \retval  none.
 */
static void App_mcanWriteMem(uint32_t cnt, uint32_t addr, const MCAN_TxBufElement *elem);

/**
 * \brief   This function contains test code for DMA usage with MCAN
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanDMATest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for DMA configuration for with MCAN Rx
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  none.
 */
static void DMARxConfigure(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for DMA configuration for with MCAN Tx
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  none.
 */
static void DMATxConfigure(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN State transition
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanStateTransnTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN Ext Time Stamp Interrupt
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanExtTSIntrTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN Rx/Tx state
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanTxRxPinStateTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN Rx/Tx state
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanClkStpReqTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN Rx/Tx state
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanTSRstTest(st_mcanTestcaseParams_t *testParams);

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
/**
 * \brief   This Interrupt Service Routine for EDMA completion interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void AppEdmaCompletionISR(void *handle);
#endif

/**
 * \brief   This function contains test code for MCAN Rx/Tx state
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanBusMonTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains test code for MCAN Latency measurement
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanLatencyTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains MCAN Tx Test and then Rx Test for performance
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
int32_t App_mcanPerfTxRxTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains MCAN Message Arbitration test
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
int32_t App_mcanMsgArbTest(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This function contains MCAN Rx FIFO Mode Tests
 *
 * \param   testParams  Test case parameters.
 *
 * \retval  status      configuration status.
 */
int32_t App_mcanRxFIFOModes(st_mcanTestcaseParams_t *testParams);

extern int32_t mcanClockEnable(void);

extern int32_t mcanTestFunc(st_mcanTestcaseParams_t *testParams);

extern void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg);

extern void App_mcanPrintTxMsg(const MCAN_TxBufElement *txMsg);

extern int32_t App_mcanRegisterInterrupt(uint32_t modIdx);
extern int32_t App_mcanUnRegisterInterrupt(uint32_t modIdx);

extern void App_mcanIntr0ISR(void *handle);

extern void App_mcanIntr1ISR(void *handle);

extern void App_mcanECCIntrISR(void *handle);

extern void App_mcanTSIntrISR(void *handle);

extern int32_t mcanClockEnable(void);

extern void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg);

extern int32_t mcanClockEnableandPADConfig(void);

extern uint32_t App_getBitConfigParamId(const MCAN_BitTimingParams *bitTimings);

extern void App_delayFunc(uint32_t timeout);

extern void App_GetCounterValue(uint64_t *value);

extern void App_CounterConfig(void);

extern void App_ConfigCounterSuspendState(void);

extern void App_ConsolePrintf(uint32_t type, uint32_t baseAddr, const char *pcString, ...);

extern uint32_t App_ConsolePuts(uint32_t type, uint32_t baseAddr, const char *pTxBuffer,
                                int32_t numBytesToWrite);

extern int32_t App_ConsoleGetNum(uint32_t baseAddr);

extern uint8_t App_ConsoleGetc(uint32_t baseAddr);

extern void App_ConsoleInit(uint32_t baseAddr, uint32_t baudRate, uint32_t wordLength,
                    uint32_t stopBit, uint32_t parity, uint32_t mode);

extern void App_mcanGetIntStatus(uint32_t baseAddr);

extern void enbaleIsrPrint(uint32_t status);

#if defined (SOC_AM65XX) || defined (SOC_J721E)
static void App_udmaInit(void);
static void App_udmaTxHpdInit(uint8_t *pHpdMem, st_mcanTestcaseParams_t *testParams);
static void App_udmaRxHpdInit(uint8_t *pHpdMem, st_mcanTestcaseParams_t *testParams);

static void App_udmaStart(st_mcanTestcaseParams_t *testParams);
static void App_udmaStop(void);
static void App_udmaDeInit(void);
static void App_print(const char *str);

#endif

extern void App_mcanWriteMsg(uint32_t                 baseAddr,
                      uint32_t                 elemAddr,
                      const MCAN_TxBufElement *elem);

extern void App_mcanReadMsg(uint32_t           baseAddr,
                     uint32_t           elemAddr,
                     MCAN_RxBufElement *elem);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_mcanTxApp_main(st_mcanTestcaseParams_t *testParams)
{
    int32_t                    configStatus = STW_SOK;

    configStatus += mcanClockEnableandPADConfig();
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Clock and PAD Configuration...");
    }
    configStatus += App_mcanRegisterInterrupt(gMcanModuleIdx);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in X-Bar Configuration...");
    }

    /* Reset MCAN Module */
    MCAN_reset(mcanBaseAddr);
    while (MCAN_isInReset(mcanBaseAddr) == (uint32_t)TRUE)
    {
    }
    configStatus += App_mcanConfig(testParams);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Configuration...");
    }

    configStatus += App_mcanTCEntrySetup(testParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Entry Configuration...TC cannot be Run...");
    }
    else
    {
        enbaleIsrPrint(TRUE);
        switch (testParams->testcaseId)
        {
            case 10:
                testParams->testResult = App_mcanECCTest(testParams);
            break;
            case 11:
                testParams->testResult = App_mcanECCSelfTest(testParams);
            break;
            case 12:
                testParams->testResult = App_mcanECCSelfTest(testParams);
            break;
            case 13:
                testParams->testResult = App_mcanDMATest(testParams);
            break;
            case 15:
                testParams->testResult = App_mcanStateTransnTest(testParams);
            break;
            case 16:
                testParams->testResult = App_mcanExtTSIntrTest(testParams);
            break;
            case 17:
                testParams->testResult = App_mcanTxRxPinStateTest(testParams);
            break;
            case 18:
                testParams->testResult = App_mcanClkStpReqTest(testParams);
            break;
            case 19:
                testParams->testResult = App_mcanTSRstTest(testParams);
            break;
            case 20:
                testParams->testResult = App_mcanBusMonTest(testParams);
            break;
            case 21:
                testParams->testResult = App_mcanLatencyTest(testParams);
            break;
            case 22:
                testParams->testResult = App_mcanPerfTxTest(testParams);
            break;
            case 23:
                testParams->testResult = App_mcanPerfTxRxTest(testParams);
            break;
            case 24:
                testParams->testResult = App_mcanMsgArbTest(testParams);
            break;
            case 25:
                testParams->testResult = App_mcanRxFIFOModes(testParams);
            break;
            case 26:
                testParams->testResult = App_mcanPerfTxRxTest(testParams);
            break;
            case 27:
                testParams->testResult = App_mcanDMATest(testParams);
            break;
            default:
                testParams->testResult = App_mcanTxTest(testParams);
            break;
        }
        testParams->testResult += App_mcanCheckTCResultsMisc(testParams);
        configStatus += App_mcanTCExitSetup(testParams);
        if(configStatus != STW_SOK)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Exit Configuration...");
        }
        configStatus += App_mcanUnRegisterInterrupt(gMcanModuleIdx);
    }

    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

void App_mcanWriteMem(uint32_t cnt, uint32_t addr, const MCAN_TxBufElement *elem)
{
    uint32_t regVal;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    regVal = 0U;
    regVal |= (uint32_t)(elem->id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT);
    regVal |= (uint32_t)(elem->rtr << MCANSS_TX_BUFFER_ELEM_RTR_SHIFT);
    regVal |= (uint32_t)(elem->xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT);
    regVal |= (uint32_t)(elem->esi << MCANSS_TX_BUFFER_ELEM_ESI_SHIFT);
    HW_WR_REG32(addr, regVal);
    addr += 4U;

    regVal = 0U;
    regVal |= (uint32_t)(elem->dlc << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT);
    regVal |= (uint32_t)(elem->brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT);
    regVal |= (uint32_t)(elem->fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT);
    regVal |= (uint32_t)(elem->efc << MCANSS_TX_BUFFER_ELEM_EFC_SHIFT);
    regVal |= (uint32_t)(elem->mm << MCANSS_TX_BUFFER_ELEM_MM_SHIFT);
    HW_WR_REG32(addr, regVal);
    addr += 4U;
#endif

#if defined (SOC_AM65XX) || defined (SOC_J721E)
    uint32_t loopCnt = 0U;
    loopCnt = 0U;
    HW_WR_REG32(addr, cnt);
    addr += 4U;
    loopCnt += 4U;
    while(loopCnt < dataSize[elem->dlc])
    {
        regVal  = 0U;
        regVal |= elem->data[(loopCnt / 4U)];
        regVal |= (elem->data[(loopCnt / 4U) + 1U] << 8U);
        regVal |= (elem->data[(loopCnt / 4U) + 2U] << 16U);
        regVal |= (elem->data[(loopCnt / 4U) + 3U] << 24U);
        HW_WR_REG32(addr, regVal);
        addr += 4U;
        loopCnt += 4U;
    }
#endif
}

static int32_t App_mcanConfig(st_mcanTestcaseParams_t *testParams)
{
    uint32_t                   fdoe, loopCnt;
    int32_t                    configStatus = STW_SOK;
    MCAN_RevisionId            revId;

    /* Reset MCAN SS */
    /* Get MCANSS Revision ID */
    MCAN_getRevisionId(mcanBaseAddr, &revId);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "MCANSS Revision ID:\n");
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "scheme:0x%x\n", revId.scheme);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Business Unit:0x%x\n", revId.bu);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Module ID:0x%x\n", revId.modId);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "RTL Revision:0x%x\n", revId.rtlRev);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Major Revision:0x%x\n", revId.major);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Custom Revision:0x%x\n", revId.custom);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Minor Revision:0x%x\n", revId.minor);
    /* Enable Auto wakeup */
    fdoe = MCAN_isFDOpEnable(mcanBaseAddr);
    if ((uint32_t)TRUE == fdoe)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CAN-FD operation is enabled through E-Fuse.\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CAN-FD operation is disabled through E-Fuse.\n");
    }
    /* wait for memory initialization to happen */
    while (FALSE == MCAN_isMemInitDone(mcanBaseAddr))
    {}
    /* Get endianess value */
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Endianess Value: 0x%x\n", MCAN_getEndianVal(mcanBaseAddr));
    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
    {}
    /* Initialize MCAN module */
    configStatus += MCAN_init(mcanBaseAddr, testParams->mcanConfigParams.initParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Initialization FAILED...\n", -1);
    }
    /* Configure MCAN module */
    configStatus += MCAN_config(mcanBaseAddr, testParams->mcanConfigParams.configParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Configuration FAILED...\n", -1);
    }
    /* Configure Bit timings */
    configStatus += MCAN_setBitTime(mcanBaseAddr, testParams->mcanConfigParams.bitTimings);
    if(configStatus != STW_SOK)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Bit Time Configuration FAILED...\n", -1);
    }
    /* Set Extended ID Mask */
    configStatus += MCAN_setExtIDAndMask(mcanBaseAddr, 0x1FFFFFFFU);
    if(configStatus != STW_SOK)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Bit Time Configuration FAILED...\n", -1);
    }
    /* Configure Message RAM Sections */
    configStatus += MCAN_msgRAMConfig(mcanBaseAddr, testParams->mcanConfigParams.ramConfig);
    if(configStatus != STW_SOK)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Message RAM Configuration FAILED...\n", -1);
    }
    for(loopCnt = 0U ; loopCnt < testParams->mcanConfigParams.stdIdFiltNum; loopCnt++)
    {
        /* Configure Standard ID filter element */
        MCAN_addStdMsgIDFilter(mcanBaseAddr, loopCnt, &testParams->mcanConfigParams.stdIDFilter[loopCnt]);
    }
    for(loopCnt = 0U ; loopCnt < testParams->mcanConfigParams.extIdFiltNum; loopCnt++)
    {
        /* Configure Standard ID filter element */
        MCAN_addExtMsgIDFilter(mcanBaseAddr, loopCnt, &testParams->mcanConfigParams.extIDFilter[loopCnt]);
    }
    /* Configure ECC */
    MCAN_eccConfig(mcanBaseAddr, testParams->mcanConfigParams.eccConfigParams);
    /* Enable loopback if autoRunEnable is set/TRUE */
    if ((autoRunEnable == (uint32_t)TRUE) &&
        ((testParams->mcanConfigParams.mcanTestType &
          MCAN_TEST_TYPE_INTERNAL_LOOBACK) ==
          MCAN_TEST_TYPE_INTERNAL_LOOBACK))
    {
        MCAN_lpbkModeEnable(mcanBaseAddr, MCAN_LPBK_MODE_INTERNAL, TRUE);
    }
    /* Enable loopback only if internal loopback is set as test mode */
    if (testParams->mcanConfigParams.mcanTestType == MCAN_TEST_TYPE_INTERNAL_LOOBACK)
    {
        MCAN_lpbkModeEnable(mcanBaseAddr, MCAN_LPBK_MODE_INTERNAL, TRUE);
    }
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
    {}
    return configStatus;
}

static int32_t App_mcanTxTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, iterationCnt = 0U, intrMask, txBufNum;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    uint64_t ts1, ts2;

#if defined (SOC_AM65XX) || defined (SOC_J721E)
    App_CounterConfig();
    App_ConfigCounterSuspendState();
#endif
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
    }
    App_GetCounterValue(&ts1);
    for (iterationCnt = 0U ;
         iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         iterationCnt++)
    {
        for (loopCnt = 0U ;
             loopCnt < testParams->mcanConfigParams.txMsgNum ;
             loopCnt++)
        {
            MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
            if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
            {
                txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
            }
            else
            {
                txBufNum = txFIFOStatus.putIdx;
            }
            /* Calculate Rx Interrupt Mask */
            if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
            {
                intrMask = MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG;
            }
            else
            {
                if(testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum == MCAN_RX_FIFO_NUM_0)
                {
                    intrMask = MCAN_INTR_SRC_RX_FIFO0_NEW_MSG;
                }
                else
                {
                    intrMask = MCAN_INTR_SRC_RX_FIFO1_NEW_MSG;
                }

            }
            switch (testParams->testcaseId)
            {
                case 1004:
                    intrMask = MCAN_INTR_SRC_HIGH_PRIO_MSG;
                break;
                default:
                break;
            }
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Message with following details:\n");
            App_mcanPrintTxMsg(&testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
            {
            }
            gMcanIsrIntr0Flag = 1U;
            while (!((gMcanIsrIntr0Status & intrMask) == intrMask))
            {
            }
            gMcanIsrIntr0Flag = 1U;
            /* Checking for Errors */
            MCAN_getErrCounters(mcanBaseAddr, &errCounter);
            if ((0U == errCounter.recErrCnt) &&
                (0U == errCounter.canErrLogCnt))
            {
                MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
                /* Checking for Errors */
                if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                    ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                    (0U == protStatus.pxe))
                {
                    configStatus += App_mcanReadRxMSG(&rxMsg, gMcanIsrIntr0Status);
                    if(configStatus != STW_SOK)
                    {
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nUnable to read received message(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    }
                    configStatus += App_mcanTxRxMessageCheck(
                                    testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                                    rxMsg);
                    /* Check if Message is stored into appropriate Rx Buffer */
                    if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
                    {
                        if(rxBuffNum != testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum)
                        {
                           testStatus += STW_EFAIL;
                        }
                    }
                    if(configStatus != STW_SOK)
                    {
                        testStatus += STW_EFAIL;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmitted and received message does not match(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    }
                    else
                    {
                        testStatus += STW_SOK;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr,
                            "\nMessage successfully transferred/received(Iteration Count:Message Number): (%d,%d).\n",
                            (iterationCnt + 1U), (loopCnt + 1U));
                    }
                }
                else
                {
                    testStatus += STW_EFAIL;
                    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                               (iterationCnt + 1U), (loopCnt + 1U));
                }
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                           (iterationCnt + 1U), (loopCnt + 1U));
            }
            gMcanIsrIntr0Status = 0U;
        }
    }
    App_GetCounterValue(&ts2);
    printf("\nTime:(%lld,%lld)\n", ts1, ts2);

    return testStatus;
}

static int32_t App_mcanReadRxMSG(MCAN_RxBufElement *rxMsg,
                                 uint32_t status)
{
    uint32_t    readBuffNum, bitPos;
    MCAN_RxFIFOStatus fifoStatus;
    MCAN_RxNewDataStatus newDataStatus;
    int32_t retStatus = STW_EFAIL;

    if((status & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ==
                                    MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG)
    {
        MCAN_getNewDataStatus(mcanBaseAddr, &newDataStatus);
        for(readBuffNum = 0U ; readBuffNum < 64U ; readBuffNum++)
        {
            if(readBuffNum < 32U)
            {
                status = newDataStatus.statusLow;
                bitPos = 1U << readBuffNum;
                newDataStatus.statusLow = (0U | bitPos);
            }
            else
            {
                status = newDataStatus.statusHigh;
                bitPos = 1U << (readBuffNum - 32U);
                newDataStatus.statusHigh = (0U | bitPos);
            }
            MCAN_clearNewDataStatus(mcanBaseAddr, &newDataStatus);

            rxBuffNum = readBuffNum;
            if(bitPos == (status & bitPos))
            {
                MCAN_readMsgRam(mcanBaseAddr,
                                MCAN_MEM_TYPE_BUF,
                                readBuffNum,
                                MCAN_RX_FIFO_NUM_0,
                                rxMsg);
                if (isrPrintEnable == (uint32_t)TRUE)
                {
                    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx Buffer: Received message with following details:");
                }
                retStatus = STW_SOK;
                break;
            }
        }
    }
    else if(((status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ||
        ((status & MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO1_NEW_MSG))
    {
        retStatus = STW_SOK;
        readBuffNum = 0U;
        if(((status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO0_NEW_MSG))
        {
            fifoStatus.num = (uint32_t)MCAN_RX_FIFO_NUM_0;
            if (isrPrintEnable == (uint32_t)TRUE)
            {
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx FIFO 0: Received message with following details:");
            }
        }
        else
        {
            fifoStatus.num = (uint32_t)MCAN_RX_FIFO_NUM_1;
            if (isrPrintEnable == (uint32_t)TRUE)
            {
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx FIFO 1: Received message with following details:");
            }
        }
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        MCAN_readMsgRam(mcanBaseAddr,
                        MCAN_MEM_TYPE_FIFO,
                        fifoStatus.getIdx,
                        (uint32_t)fifoStatus.num,
                        rxMsg);
        (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                   (uint32_t)fifoStatus.num,
                                   fifoStatus.getIdx);
    }
    if (isrPrintEnable == (uint32_t)TRUE)
    {
        App_mcanPrintRxMsg(rxMsg);
    }

    return retStatus;
}

static int32_t App_mcanTxRxMessageCheck(MCAN_TxBufElement txMsg,
                                        MCAN_RxBufElement rxMsg)
{
    uint32_t msgMask, loopCnt;
    int32_t retStatus = STW_SOK;

    /* Check/Compare Rx message with Tx message */
    if(txMsg.xtd == 1U)
    {
        msgMask = APP_MCAN_EXT_ID_MASK;
    }
    else
    {
        msgMask = APP_MCAN_STD_ID_MASK;
    }
    if (((txMsg.id & msgMask) == (rxMsg.id & msgMask)) &&
        (txMsg.rtr == rxMsg.rtr) &&
        (txMsg.xtd == rxMsg.xtd) &&
        (txMsg.esi == rxMsg.esi) &&
        (txMsg.dlc == rxMsg.dlc) &&
        (txMsg.brs == rxMsg.brs) &&
        (txMsg.fdf == rxMsg.fdf))
    {
        for (loopCnt = 0U;
             loopCnt < gMcanAppdataSize[rxMsg.dlc];
             loopCnt++)
        {
            if (txMsg.data[loopCnt] != rxMsg.data[loopCnt])
            {
                break;
            }
        }
        if(loopCnt == gMcanAppdataSize[rxMsg.dlc])
        {
            retStatus = STW_SOK;
        }
        else
        {
            retStatus = STW_EFAIL;
        }
    }
    else
    {
        retStatus = STW_EFAIL;
    }

    return retStatus;
}

static int32_t App_mcanTCEntrySetup(st_mcanTestcaseParams_t *testParams)
{
    int32_t status = STW_SOK, configStatus = STW_SOK;
    uint32_t    configId;

     App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nIn TC Entry Config Func...\n", -1);
    configId = App_getBitConfigParamId(testParams->mcanConfigParams.bitTimings);
    /* send a message to change baud-rate of receiver and this is valid only for
       B2B and not for loop back */
    if((configId != 0U) && (configId != 0xFFFFFFFFU))
    {
        /* change Tx baud-rate to default */
        /* Put MCAN in SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
        while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
        {}
        /* Configure Bit timings */
        configStatus += MCAN_setBitTime(mcanBaseAddr, &canFDBitTimings[0U]);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nDEFAULT MCAN Bit Time Configuration FAILED...\n", -1);
        }
        /* Take MCAN out of the SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
        while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
        {}
        status += App_mcanChangeBaudrateMSG(configId);
        /* change Tx baud-rate to configured by TC */
        /* Put MCAN in SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
        while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
        {}
        /* Configure Bit timings */
        configStatus += MCAN_setBitTime(mcanBaseAddr, &canFDBitTimings[configId]);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCONFIGURRED MCAN Bit Time Configuration FAILED...\n", -1);
        }
        /* Take MCAN out of the SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
        while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
        {}
    }
    switch (testParams->testcaseId)
    {
        case 4:
            MCAN_extTSCounterConfig(mcanBaseAddr, 0xFF);
            MCAN_extTSCounterEnable(mcanBaseAddr, (uint32_t)TRUE);
        break;
        case 16:
            MCAN_extTSCounterConfig(mcanBaseAddr, 0x3FFF);
            MCAN_extTSCounterEnable(mcanBaseAddr, (uint32_t)TRUE);
        break;
        case 1003:
            MCAN_extTSCounterConfig(mcanBaseAddr, 0xFFFF);
            MCAN_extTSCounterEnable(mcanBaseAddr, (uint32_t)TRUE);
        break;
        default:
        break;
    }
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nExiting TC Entry Config Func...\n", -1);

    return status;
}

static int32_t App_mcanTCExitSetup(st_mcanTestcaseParams_t *testParams)
{
    int32_t status = STW_SOK;
    uint32_t    configId;

    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nIn TC Exit Config Func...\n", -1);
    configId = App_getBitConfigParamId(testParams->mcanConfigParams.bitTimings);
    /* send a message to change baud-rate of receiver and this is valid only for
       B2B and not for loop back */
    if((configId != 0U) && (configId != 0xFFFFFFFFU))
    {
        status += App_mcanChangeBaudrateMSG(0U);

    }
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nExiting TC Exit Config Func...\n", -1);

    return status;
}

static int32_t App_mcanChangeBaudrateMSG(uint32_t idx)
{
    int32_t configStatus = STW_SOK;
    MCAN_RxBufElement    rxMsg;
    MCAN_TxBufElement    txMsg;
    MCAN_RxNewDataStatus newDataStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_ProtocolStatus protStatus;
    uint32_t    readBuffNum, bitPos, status;
    MCAN_RxFIFOStatus fifoStatus;

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\n===============Sending Change Baud-rate message to Receiver===============\n");
    /* Message will be sent using Tx buffer 1 */
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(mcanBaseAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_1);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        MCAN_INTR_LINE_NUM_1,
                        1U);
    if(idx == 0U)
    {
        txMsg.id =  (0x16 << 18);
    }
    else
    {
        txMsg.id =  (0x44 << 18);
    }
    txMsg.rtr = 0U;
    txMsg.xtd = 0U;
    txMsg.esi = 0U;
    txMsg.dlc = 1U;
    txMsg.brs = 1U;
    txMsg.fdf = 1U;
    txMsg.efc = 0U;
    txMsg.mm = 0xAAU;
    txMsg.data[0U] = (uint8_t)(idx & 0xFFU);
    /* Enable Transmission interrupt */
    configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                                             1U,
                                             (uint32_t)TRUE);
    if(configStatus != STW_SOK)
    {
         App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in enabling Transmission Interrupt...\n", -1);
    }
    /* Always writing to Tx Buffer number 1 for echoing back */
    MCAN_writeMsgRam(mcanBaseAddr,
                     MCAN_MEM_TYPE_BUF,
                     1U,
                     (const MCAN_TxBufElement*) &txMsg);
    /* Add request for transmission */
    configStatus += MCAN_txBufAddReq(mcanBaseAddr, 1U);
    if (STW_SOK != configStatus)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
    }
    while (!(MCAN_INTR_SRC_TRANS_COMPLETE ==
            (gMcanIsrIntr1Status & MCAN_INTR_SRC_TRANS_COMPLETE)))
    {
    }
    gMcanIsrIntr1Flag = 1U;
    while (!((((gMcanIsrIntr1Status & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ==
                        MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ||
             ((gMcanIsrIntr1Status & MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ==
                        MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ||
             ((gMcanIsrIntr1Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                        MCAN_INTR_SRC_RX_FIFO0_NEW_MSG))))
    {
    }
    gMcanIsrIntr1Flag = 1U;
    /* Checking for Errors */
    MCAN_getErrCounters(mcanBaseAddr, &errCounter);
    if ((0U != errCounter.recErrCnt) &&
        (0U != errCounter.canErrLogCnt))
    {
        configStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception\n");
    }
    MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    /* Checking for Errors */
    if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
         (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
        ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
         (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
        (0U == protStatus.pxe))
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMessage successfully transferred.\n");
    }
    else
    {
        configStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission message.\n");
    }
    if((gMcanIsrIntr1Status & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ==
                                MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG)
    {
        MCAN_getNewDataStatus(mcanBaseAddr, &newDataStatus);
        MCAN_clearNewDataStatus(mcanBaseAddr, &newDataStatus);
        for(readBuffNum = 0U ; readBuffNum < 64U ; readBuffNum++)
        {
            if(readBuffNum < 32U)
            {
                status = newDataStatus.statusLow;
                bitPos = 1U << readBuffNum;
            }
            else
            {
                status = newDataStatus.statusHigh;
                bitPos = 1U << (readBuffNum - 32U);
            }

            if(bitPos == (status & bitPos))
            {
                MCAN_readMsgRam(mcanBaseAddr,
                                MCAN_MEM_TYPE_BUF,
                                readBuffNum,
                                MCAN_RX_FIFO_NUM_0,
                                &rxMsg);
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx Buffer: Received message.");
            }
        }
    }
    else if(((gMcanIsrIntr1Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ||
        ((gMcanIsrIntr1Status & MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO1_NEW_MSG))
    {
        readBuffNum = 0U;
        if(((gMcanIsrIntr1Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO0_NEW_MSG))
        {
            fifoStatus.num = (uint32_t)MCAN_RX_FIFO_NUM_0;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx FIFO 0: Received message.");

        }
        else
        {
            fifoStatus.num = (uint32_t)MCAN_RX_FIFO_NUM_1;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRx FIFO 1: Received message.");
        }
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        MCAN_readMsgRam(mcanBaseAddr,
                        MCAN_MEM_TYPE_FIFO,
                        fifoStatus.getIdx,
                        (uint32_t)fifoStatus.num,
                        &rxMsg);
        (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                   (uint32_t)fifoStatus.num,
                                   fifoStatus.getIdx);

    }
    configStatus += App_mcanTxRxMessageCheck(txMsg, rxMsg);

    /* Revert configuration done by this  function to send the baud-rate change message */
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, MCAN_INTR_MASK_ALL, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_0);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        MCAN_INTR_LINE_NUM_1,
                        0U);
    /* Enable Transmission interrupt */
    configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                                             1U,
                                             (uint32_t)FALSE);
    if(configStatus != STW_SOK)
    {
         App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nRerverting Config: Error in disabling Transmission Interrupt...\n", -1);
    }
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\n===============Change in Baud-rate for Receiver FAILED===============\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\n===============Change in Baud-rate for Receiver is SUCCESSFUL===============\n");
    }
    /* Wait for sometime, this could be needed by receiver to change the baud rate */
    /* Added Delay - This is needed by Rx node to change the baudrate */
    App_delayFunc(50U);

    return configStatus;
}

static int32_t App_mcanCheckTCResultsMisc(st_mcanTestcaseParams_t *testParams)
{
    int32_t status = STW_SOK;
    uint32_t iterationCnt, loopCnt, oldTimeStamp = 0U;
    MCAN_TxEventFIFOElement txEventElem;
    MCAN_TxEventFIFOStatus txEventFIFOStatus;

    switch (testParams->testcaseId)
    {
        case 1:
            for (iterationCnt = 0U ;
             iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
             iterationCnt++)
            {
                for (loopCnt = 0U ;
                     loopCnt < testParams->mcanConfigParams.txMsgNum ;
                     loopCnt++)
                {
                    MCAN_getTxEventFIFOStatus(mcanBaseAddr, &txEventFIFOStatus);
                    MCAN_readTxEventFIFO(mcanBaseAddr, &txEventElem);
                    MCAN_writeTxEventFIFOAck(mcanBaseAddr, txEventFIFOStatus.getIdx);

                    if(App_mcanTxEventMessageCheck(
                        testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                        txEventElem) == STW_SOK)
                    {
                        oldTimeStamp = txEventElem.txts;
                        status += STW_SOK;
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element matches with transmitted message.\n", -1);
                    }
                    else
                    {
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element does not matche with transmitted message.\n", -1);
                        status += STW_EFAIL;
                    }
                }
            }
        break;
        case 4:
            for (iterationCnt = 0U ;
             iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
             iterationCnt++)
            {
                for (loopCnt = 0U ;
                     loopCnt < testParams->mcanConfigParams.txMsgNum ;
                     loopCnt++)
                {
                    MCAN_getTxEventFIFOStatus(mcanBaseAddr, &txEventFIFOStatus);
                    MCAN_readTxEventFIFO(mcanBaseAddr, &txEventElem);
                    MCAN_writeTxEventFIFOAck(mcanBaseAddr, txEventFIFOStatus.getIdx);

                    if ((App_mcanTxEventMessageCheck(
                        testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                        txEventElem) == STW_SOK)  &&
                        (oldTimeStamp != txEventElem.txts))
                    {
                        oldTimeStamp = txEventElem.txts;
                        status += STW_SOK;
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element matches with transmitted message.\n", -1);
                    }
                    else
                    {
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element does not matche with transmitted message.\n", -1);
                        status += STW_EFAIL;
                    }
                }
            }
        break;
        case 1000:
            for (iterationCnt = 0U ;
             iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
             iterationCnt++)
            {
                for (loopCnt = 0U ;
                     loopCnt < testParams->mcanConfigParams.txMsgNum ;
                     loopCnt++)
                {
                    MCAN_getTxEventFIFOStatus(mcanBaseAddr, &txEventFIFOStatus);
                    MCAN_readTxEventFIFO(mcanBaseAddr, &txEventElem);
                    MCAN_writeTxEventFIFOAck(mcanBaseAddr, txEventFIFOStatus.getIdx);

                    if(App_mcanTxEventMessageCheck(
                        testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                        txEventElem) == STW_SOK)
                    {
                        oldTimeStamp = txEventElem.txts;
                        status += STW_SOK;
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element matches with transmitted message.\n", -1);
                    }
                    else
                    {
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element does not matche with transmitted message.\n", -1);
                        status += STW_EFAIL;
                    }
                }
            }
        break;
        case 1003:
            for (iterationCnt = 0U ;
             iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
             iterationCnt++)
            {
                for (loopCnt = 0U ;
                     loopCnt < testParams->mcanConfigParams.txMsgNum ;
                     loopCnt++)
                {
                    MCAN_getTxEventFIFOStatus(mcanBaseAddr, &txEventFIFOStatus);
                    MCAN_readTxEventFIFO(mcanBaseAddr, &txEventElem);
                    MCAN_writeTxEventFIFOAck(mcanBaseAddr, txEventFIFOStatus.getIdx);

                    if ((App_mcanTxEventMessageCheck(
                        testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                        txEventElem) == STW_SOK)  &&
                        (oldTimeStamp != txEventElem.txts))
                    {
                        oldTimeStamp = txEventElem.txts;
                        status += STW_SOK;
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element matches with transmitted message.\n", -1);
                    }
                    else
                    {
                        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Event FIFO element does not match with transmitted message.\n", -1);
                        status += STW_EFAIL;
                    }
                }
            }
        break;
        default:
        break;
    }

    return status;
}

static int32_t App_mcanTxEventMessageCheck(MCAN_TxBufElement txMsg,
                                           MCAN_TxEventFIFOElement txEventMsg)
{
    int32_t retStatus = STW_SOK;

    if ((txMsg.id == txEventMsg.id) &&
        (txMsg.rtr == txEventMsg.rtr) &&
        (txMsg.xtd == txEventMsg.xtd) &&
        (txMsg.esi == txEventMsg.esi) &&
        (txMsg.dlc == txEventMsg.dlc) &&
        (txMsg.brs == txEventMsg.brs) &&
        (txMsg.fdf == txEventMsg.fdf) &&
        (txMsg.mm == txEventMsg.mm))
    {
        retStatus += STW_SOK;
    }
    else
    {
        retStatus += STW_EFAIL;
    }

    return retStatus;
}

SemaphoreP_Handle   gTxDoneSem = NULL;
SemaphoreP_Handle   gRxDoneSem = NULL;

int32_t App_mcanPerfTxTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, iterationCnt = 0U, txBufNum, maxMsgCnt;
    // uint32_t ;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    // MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    uint64_t ts1, ts2, tsDiff, hwUtiln, tsFreq;
    uint64_t numOfMsgPerSec;
    SemaphoreP_Params   semPrms;

// #if (BUILD_OS_TYPE == baremetal)
    SemaphoreP_Params_init(&semPrms);
    gTxDoneSem = SemaphoreP_create(0, &semPrms);
    gRxDoneSem = SemaphoreP_create(0, &semPrms);
// #endif

    enbaleIsrPrint(FALSE);
    configStatus += mcanClockEnableandPADConfig();
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Clock and PAD Configuration...");
    }
    configStatus += App_mcanRegisterInterrupt(gMcanModuleIdx);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in X-Bar Configuration...");
    }

#if defined (SOC_AM65XX) || defined (SOC_J721E)
    App_CounterConfig();
    App_ConfigCounterSuspendState();
#endif
    /* Reset MCAN Module */
    MCAN_reset(mcanBaseAddr);
    while (MCAN_isInReset(mcanBaseAddr) == (uint32_t)TRUE)
    {
    }
    configStatus += App_mcanConfig(testParams);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Configuration...");
    }

    configStatus += App_mcanTCEntrySetup(testParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Entry Configuration...TC cannot be Run...");
    }
    else
    {
    }
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
    }

    /* Check for STD vs EXT ID and FD vs Classic messages for CAN message */
    if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 1U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 1U))
    {
        maxMsgCnt = MCAN_THEOROTICAL_MAX_EXT_1_5_MBPS;
    }
    else if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 1U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 0U))
    {
        maxMsgCnt = MCAN_CLASSIC_CAN_THEOROTICAL_MAX_EXT_1_MBPS;
    }
    else if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 0U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 0U))
    {
        maxMsgCnt = MCAN_CLASSIC_CAN_THEOROTICAL_MAX_STD_1_MBPS;
    }
    else
    {
        maxMsgCnt = MCAN_THEOROTICAL_MAX_STD_1_5_MBPS;
    }
    /* capture time stamp before triggering Tx */
    App_GetCounterValue(&ts1);
    for (iterationCnt = 0U ;
         iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         iterationCnt++)
    {
        for (loopCnt = 0U ;
             loopCnt < testParams->mcanConfigParams.txMsgNum ;
             loopCnt++)
        {
            MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
            if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
            {
                txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
            }
            else
            {
                txBufNum = txFIFOStatus.putIdx;
            }
            /* Calculate Rx Interrupt Mask */
            // if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
            // {
                // intrMask = MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG;
            // }
            // else
            // {
                // if(testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum == MCAN_RX_FIFO_NUM_0)
                // {
                    // intrMask = MCAN_INTR_SRC_RX_FIFO0_NEW_MSG;
                // }
                // else
                // {
                    // intrMask = MCAN_INTR_SRC_RX_FIFO1_NEW_MSG;
                // }

            // }
            // switch (testParams->testcaseId)
            // {
                // case 5:
                    // intrMask = MCAN_INTR_SRC_HIGH_PRIO_MSG;
                // break;
                // case 1004:
                    // intrMask = MCAN_INTR_SRC_HIGH_PRIO_MSG;
                // break;
                // default:
                // break;
            // }
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            if (gTxDoneSem == NULL)
            {
                while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                    MCAN_INTR_SRC_TRANS_COMPLETE))
                {
                }
            }
            else
            {
                SemaphoreP_pend(gTxDoneSem, SemaphoreP_WAIT_FOREVER);
            }
            // if (gRxDoneSem == NULL)
            // {
                // gMcanIsrIntr0Flag = 1U;
                // while (!((gMcanIsrIntr0Status & intrMask) == intrMask))
                // {
                // }
                // gMcanIsrIntr0Flag = 1U;
            // }
            // else
            // {
                // SemaphoreP_pend(gRxDoneSem, SemaphoreP_WAIT_FOREVER);
            // }
            /* Checking for Errors */
            MCAN_getErrCounters(mcanBaseAddr, &errCounter);
            if ((0U == errCounter.recErrCnt) &&
                (0U == errCounter.canErrLogCnt))
            {
                MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
                /* Checking for Errors */
                if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                    ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                    (0U == protStatus.pxe))
                {
                    // configStatus += App_mcanReadRxMSG(&rxMsg, gMcanIsrIntr0Status);
                    // if(configStatus != STW_SOK)
                    // {
                        // App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nUnable to read received message(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    // }
                    // configStatus += App_mcanTxRxMessageCheck(
                                    // testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                                    // rxMsg);
                    // /* Check if Message is stored into appropriate Rx Buffer */
                    // if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
                    // {
                        // if(rxBuffNum != testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum)
                        // {
                           // testStatus += STW_EFAIL;
                        // }
                    // }
                    // if(configStatus != STW_SOK)
                    // {
                        // testStatus += STW_EFAIL;
                        // App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmitted and received message does not match(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    // }
                    // else
                    // {
                        // testStatus += STW_SOK;
                    // }
                }
                else
                {
                    testStatus += STW_EFAIL;
                    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                               (iterationCnt + 1U), (loopCnt + 1U));
                }
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                           (iterationCnt + 1U), (loopCnt + 1U));
            }
            gMcanIsrIntr0Status = 0U;
        }
    }
    /* capture time stamp After Tx completion */
    App_GetCounterValue(&ts2);
    tsDiff = ts2 - ts1;
#if defined (SOC_J721E)
    tsFreq = Utils_prfTsGetFreq() * 1000;
#else
    tsFreq = MCAN_APP_CNT_FREQ_KHZ;
#endif

    numOfMsgPerSec = (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum * tsFreq) / tsDiff;
    /* If internal loopback then no need of x2 as Tx and Rx nodes are same */
    if (testParams->mcanConfigParams.mcanTestType == MCAN_TEST_TYPE_INTERNAL_LOOBACK)
    {
        numOfMsgPerSec *= 2U;
    }
    hwUtiln = ((numOfMsgPerSec * 100) / maxMsgCnt);
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    printf("\nThroughPut: %lld Msg/sec\n", numOfMsgPerSec);
    printf("HW Utilization: %lld", hwUtiln);
#else
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nThroughPut: %d Msg/sec\n", numOfMsgPerSec);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "HW Utilization: %d", hwUtiln);
#endif
    testParams->testResult += App_mcanCheckTCResultsMisc(testParams);
    configStatus += App_mcanTCExitSetup(testParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Exit Configuration...");
    }
    if(hwUtiln < 70U)
    {
        testParams->testResult += STW_EFAIL;
        testStatus += STW_EFAIL;
    }
    testParams->isRun      = STW_SOK;
    if (gTxDoneSem != NULL)
    {
        SemaphoreP_delete(gTxDoneSem);
        gTxDoneSem = NULL;
    }
    if (gRxDoneSem != NULL)
    {
        SemaphoreP_delete(gRxDoneSem);
        gRxDoneSem = NULL;
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nPer TX Test: %d", testStatus);

    return testStatus;
}

static int32_t App_mcanECCTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, iterationCnt = 0U, intrMask, txBufNum;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    uint32_t startAddr, elemSize, elemAddr;

    gMcanECCIntrFlag = 1U;
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
            /* Enable Transmission Cancellation interrupt */
            configStatus += MCAN_getTxBufCancellationIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Cancellation Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
        /* Enable Transmission Cancellation interrupt */
        configStatus += MCAN_getTxBufCancellationIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Cancellation Interrupt Enable FAILED...\n", -1);
        }
    }
    /* Enable ECC Interrupts */
    MCAN_eccEnableIntr(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC, TRUE);
    MCAN_eccEnableIntr(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED, TRUE);
    if (testParams->mcanConfigParams.txMsg[0U].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
    {
        loopCnt = 0U;
        startAddr = testParams->mcanConfigParams.ramConfig->txStartAddr;
        elemSize  = objSize[testParams->mcanConfigParams.ramConfig->txBufElemSize];
        elemSize *= 4U;
        elemAddr  = startAddr + (elemSize * testParams->mcanConfigParams.txMsg[0U].bufferNum);
        /* Access data bytes of the message */
        elemAddr += 12U;
        elemAddr += MCAN_MCAN_MSG_MEM;
        elemAddr += mcanBaseAddr;

        MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                    MCAN_MEM_TYPE_BUF)
        {
            txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
        }
        else
        {
            txBufNum = txFIFOStatus.putIdx;
        }
        /* Calculate Rx Interrupt Mask */
        if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
        {
            intrMask = MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG;
        }
        else
        {
            if(testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum == MCAN_RX_FIFO_NUM_0)
            {
                intrMask = MCAN_INTR_SRC_RX_FIFO0_NEW_MSG;
            }
            else
            {
                intrMask = MCAN_INTR_SRC_RX_FIFO1_NEW_MSG;
            }

        }
        switch (testParams->testcaseId)
        {
            case 1004:
                intrMask = MCAN_INTR_SRC_HIGH_PRIO_MSG;
            break;
            default:
            break;
        }
        /* SEC error test */
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Message with following details:\n");
            App_mcanPrintTxMsg(&testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Disable ECC */
            testParams->mcanConfigParams.eccConfigParams->enable = 0U;
            testParams->mcanConfigParams.eccConfigParams->enableChk = 0U;
            MCAN_eccConfig(mcanBaseAddr, testParams->mcanConfigParams.eccConfigParams);
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Before single Bit Error/Bit Flip:0x%x\n", HW_RD_REG32(elemAddr));
            /* Introduce single bit error */
            HW_WR_REG32(elemAddr, HW_RD_REG32(elemAddr)^0x8U);
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "After single Bit Error/Bit Flip:0x%x\n", HW_RD_REG32(elemAddr));
            /* Enable ECC */
            testParams->mcanConfigParams.eccConfigParams->enable = 1U;
            testParams->mcanConfigParams.eccConfigParams->enableChk = 1U;
            MCAN_eccConfig(mcanBaseAddr, testParams->mcanConfigParams.eccConfigParams);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            while (gMcanECCIntrFlag)
            {
            }
            gMcanECCIntrFlag = 1U;
            while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
            {}
            gMcanIsrIntr0Flag = 1U;
            while (!((gMcanIsrIntr0Status & intrMask) == intrMask))
            {
            }
            gMcanIsrIntr0Flag = 1U;
            /* Check for ECC Error */
            if ((gMcaneccErr.secErr == 1U) &&
                (gMcaneccErr.dedErr != 1U) &&
                (gMcaneccErr.row == ((elemAddr - (MCAN_MCAN_MSG_MEM + mcanBaseAddr))/4)) &&
                (gMcaneccErr.bit1 == 3U))
            {
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC SEC Error location matched.\n");
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC SEC Error location does not match.\n");
            }
            /* Checking for Errors */
            MCAN_getErrCounters(mcanBaseAddr, &errCounter);
            if ((0U == errCounter.recErrCnt) &&
                (0U == errCounter.canErrLogCnt))
            {
                MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
                /* Checking for Errors */
                if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                    ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                     (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                    (0U == protStatus.pxe))
                {
                    configStatus += App_mcanReadRxMSG(&rxMsg, gMcanIsrIntr0Status);
                    if(configStatus != STW_SOK)
                    {
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nUnable to read received message(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    }
                    configStatus += App_mcanTxRxMessageCheck(
                                    testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                                    rxMsg);
                    /* Check if Message is stored into appropriate Rx Buffer */
                    if(testParams->mcanConfigParams.txMsg[loopCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
                    {
                        if(rxBuffNum != testParams->mcanConfigParams.txMsg[loopCnt].rxBuffNum)
                        {
                           testStatus += STW_EFAIL;
                        }
                    }
                    if(configStatus != STW_SOK)
                    {
                        testStatus += STW_EFAIL;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmitted and received message does not match(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                    }
                    else
                    {
                        testStatus += STW_SOK;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr,
                            "\nMessage successfully transferred/received(Iteration Count:Message Number): (%d,%d).\n",
                            (iterationCnt + 1U), (loopCnt + 1U));
                    }
                }
                else
                {
                    testStatus += STW_EFAIL;
                    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                               (iterationCnt + 1U), (loopCnt + 1U));
                }
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                           (iterationCnt + 1U), (loopCnt + 1U));
            }
            gMcanIsrIntr0Status = 0U;
        }
        /* DED error test */
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Message with following details:\n");
            App_mcanPrintTxMsg(&testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Disable ECC */
            testParams->mcanConfigParams.eccConfigParams->enable = 0U;
            testParams->mcanConfigParams.eccConfigParams->enableChk = 0U;
            MCAN_eccConfig(mcanBaseAddr, testParams->mcanConfigParams.eccConfigParams);
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Before Double Bit Error/Bit Flip:0x%x\n", HW_RD_REG32(elemAddr));
            /* Introduce Double bit error */
            HW_WR_REG32(elemAddr, HW_RD_REG32(elemAddr)^0xAU);
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "After Double Bit Error/Bit Flip:0x%x\n", HW_RD_REG32(elemAddr));
            /* Enable ECC */
            testParams->mcanConfigParams.eccConfigParams->enable = 1U;
            testParams->mcanConfigParams.eccConfigParams->enableChk = 1U;
            MCAN_eccConfig(mcanBaseAddr, testParams->mcanConfigParams.eccConfigParams);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            while (gMcanECCIntrFlag)
            {
            }
            gMcanECCIntrFlag = 1U;
            if (MCAN_OPERATION_MODE_SW_INIT == MCAN_getOpMode(mcanBaseAddr))
            {
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmission of corrupted message stopped.\n");
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nSent out Corrupted Message.\n");
            }
            /* cancel transmission of corrupted message */
            MCAN_txBufCancellationReq(mcanBaseAddr, txBufNum);
            while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_CANCEL_FINISH) ==
                                MCAN_INTR_SRC_TRANS_CANCEL_FINISH))
            {}
            gMcanIsrIntr0Flag = 1U;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nTx Buffer Transmission Cancellation Interrupt Happened.\n");
            /* Take MCAN out of the SW initialization mode */
            MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
            while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
            {}
            /* Check for ECC Error */
            if ((gMcaneccErr.secErr != 1U) &&
                (gMcaneccErr.dedErr == 1U) &&
                (gMcaneccErr.row == ((elemAddr - (MCAN_MCAN_MSG_MEM + mcanBaseAddr))/4)))
            {
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC DED Error location matched.\n");
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC DED Error location does not match.\n");
            }
            gMcanIsrIntr0Status = 0U;
        }
    }
    return testStatus;
}

static int32_t App_mcanECCSelfTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  testStatus = STW_SOK;
    uint32_t accessAddr, secErrFlag = 0U, dedErrFlag = 0U;

    gMcanECCIntrFlag = 1U;
    /* Enable ECC Interrupts */
    MCAN_eccEnableIntr(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC, TRUE);
    MCAN_eccEnableIntr(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED, TRUE);
    MCAN_eccForceError(mcanBaseAddr, testParams->mcanConfigParams.eccFrcParams);
    if (testParams->mcanConfigParams.eccFrcParams->errType == MCAN_ECC_ERR_TYPE_SEC)
    {
        secErrFlag = 1U;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "SEC Error Test:\n");
    }
    if (testParams->mcanConfigParams.eccFrcParams->errType == MCAN_ECC_ERR_TYPE_DED)
    {
        dedErrFlag = 1U;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "DED Error Test:\n");
    }
    accessAddr = mcanBaseAddr;
    accessAddr += MCAN_MCAN_MSG_MEM;
    accessAddr += (testParams->mcanConfigParams.eccFrcParams->rowNum * 4U);
    HW_RD_REG32(accessAddr);
    while (gMcanECCIntrFlag)
    {
    }
    gMcanECCIntrFlag = 1U;
    /* Check for ECC Error */
    if ((gMcaneccErr.secErr == secErrFlag) &&
        (gMcaneccErr.dedErr == dedErrFlag) &&
        (gMcaneccErr.row == testParams->mcanConfigParams.eccFrcParams->rowNum))
    {
        if (secErrFlag == 1U)
        {
            if (gMcaneccErr.bit1 != testParams->mcanConfigParams.eccFrcParams->bit1)
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC SEC Error bit location match failed.\n");
            }
        }
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC Error location matched.\n");
    }
    else
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nECC Error location does not match.\n");
    }

    return testStatus;
}

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
static void AppEdmaCompletionISR(void *handle)
{
    edmaTransferComplete = 0U;
    //MCAN_txBuffAddReq(APP_MCAN_MODULE, 0U);
    EDMA3ClrIntr(SOC_EDMA_TPCC_BASE_VIRT, edmaTCCNumber);
    EDMA3ClrIntr(SOC_EDMA_TPCC_BASE_VIRT, edmaTCCNumberCh2);
}
#endif

static void DMATxConfigure(st_mcanTestcaseParams_t *testParams)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    uint32_t edmaRegion;
    uint32_t buffAddReqMem = 0x82000000, destAddr;
    uint32_t          chain_param =
        (EDMA3_OPT_TCCHEN_MASK |
         EDMA3_OPT_ITCCHEN_MASK |
         EDMA3_OPT_TCINTEN_MASK);

    /* Enable TPTC1 Clocks */
    HW_WR_REG32(0x4a008778, 0x1U);
    edmaRegion = EDMA3_CC_REGION;
    EDMAsetRegion(edmaRegion);
    EDMA3Init(SOC_EDMA_TPCC_BASE_VIRT, 0);
    edmaInterruptNumber = EDMA3_CC_XFER_COMPLETION_INT;
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_DMA_INST, XBAR_DMA_INTR_SOURCE);
    {
        /* Successfully configured CrossBar */
        Intc_Init();
        Intc_IntEnable(edmaInterruptNumber);
        Intc_IntRegister(edmaInterruptNumber, (IntrFuncPtr) AppEdmaCompletionISR,
                         0);
        Intc_IntPrioritySet(edmaInterruptNumber, 1, 0);
        Intc_SystemEnable(edmaInterruptNumber);
    }
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    destAddr = (uint32_t) mcanBaseAddr +
                         (uint32_t) testParams->mcanConfigParams.ramConfig->txStartAddr;
#elif defined (SOC_TDA2PX)
    /* For J6P, MCAN address is a virtual address which needs to be converted
       physical address for DMA
    */
    destAddr = (uint32_t) mcanBaseAddr +
                         (uint32_t) testParams->mcanConfigParams.ramConfig->txStartAddr;
    destAddr -= 0x20000000U;
#endif
    /* Configure EDMA parameters */
    edmaChannelNumber  = 16U;
    edmaEvtqNumber     = 0x0U;
    edmaTCCNumber      = 16U;
    edmaChannelNumberCh2  = 0x2U;
    edmaEvtqNumberCh2     = 0x0U;
    edmaTCCNumberCh2      = 0x2U;
    edmaParam.opt      = 0U;
    edmaParam.srcAddr  = (uint32_t) &txBuffer[0];
    edmaParam.destAddr = destAddr;
    /* Supporting only fill CAN FD message:64bytes data and 8 bytes header */
    edmaParam.aCnt     = (uint32_t) (72U);
    edmaParam.bCnt     = testParams->mcanConfigParams.txMSGInterationCnt;
    edmaParam.cCnt     = 1U;
    edmaParam.srcBIdx  = edmaParam.aCnt;
    edmaParam.destBIdx = 0U;
    edmaParam.srcCIdx  = 0U;
    edmaParam.destCIdx = 0U;
    edmaParam.linkAddr = 0xFFFFU;
    edmaParam.opt     |=
        (
         ((edmaTCCNumber << EDMA3_OPT_TCC_SHIFT) & EDMA3_OPT_TCC_MASK));
    /* Configure EDMA */
    EDMA3RequestChannel(SOC_EDMA_TPCC_BASE_VIRT,
                        EDMA3_CHANNEL_TYPE_DMA,
                        edmaChannelNumber,
                        edmaTCCNumber,
                        edmaEvtqNumber);
    EDMA3SetPaRAM(SOC_EDMA_TPCC_BASE_VIRT, edmaChannelNumber, &edmaParam);
    /* Configure the MCAN TX event. */
    CSL_xbarDmaConfigure(CSL_XBAR_DMA_CPU_ID_EDMA,
                         (edmaChannelNumber + 1),
                         DMA_EVENT_SOURCE_TX);
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    destAddr = (uint32_t) mcanBaseAddr + (uint32_t) MCAN_TXBAR;
#elif defined (SOC_TDA2PX)
    /* For J6P, MCAN address is a virtual address which needs to be converted
       physical address for DMA
    */
    destAddr = (uint32_t) mcanBaseAddr + (uint32_t) MCAN_TXBAR;
    destAddr -= 0x20000000U;
#endif
    /* Configure EDMA parameters */
    edmaParam.opt      = 0U;
    edmaParam.srcAddr  =  buffAddReqMem;
    edmaParam.destAddr = destAddr;
    edmaParam.aCnt     = 4U;
    edmaParam.bCnt     = testParams->mcanConfigParams.txMSGInterationCnt;
    edmaParam.cCnt     = 1U;
    edmaParam.srcBIdx  = 0U;
    edmaParam.destBIdx = 0U;
    edmaParam.srcCIdx  = 0U;
    edmaParam.destCIdx = 0U;
    edmaParam.linkAddr = 0xFFFFU;
    edmaParam.opt     |=
        (EDMA3_OPT_TCINTEN_MASK |
        ((edmaTCCNumberCh2 << EDMA3_OPT_TCC_SHIFT) & EDMA3_OPT_TCC_MASK));
    EDMA3RequestChannel(SOC_EDMA_TPCC_BASE_VIRT,
                        EDMA3_CHANNEL_TYPE_DMA,
                        edmaChannelNumberCh2,
                        edmaTCCNumberCh2,
                        edmaEvtqNumberCh2);
    EDMA3SetPaRAM(SOC_EDMA_TPCC_BASE_VIRT, edmaChannelNumberCh2, &edmaParam);
    /*Set params for chain transfer. Chain two channels*/
    EDMA3ChainChannel(SOC_EDMA_TPCC_BASE_VIRT,
                      edmaChannelNumber,
                      edmaChannelNumberCh2,
                      chain_param);
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    App_udmaInit();

    App_udmaTxHpdInit(&gTxHpdMem[0U], testParams);
    App_udmaRxHpdInit(&gRxHpdMem[0U], testParams);
#endif
}

static void DMARxConfigure(st_mcanTestcaseParams_t *testParams)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    uint32_t edmaRegion, srcAddr;
    uint32_t buffAddReqMem = 0x82000040;
    uint32_t          chain_param =
        (EDMA3_OPT_TCCHEN_MASK |
         EDMA3_OPT_ITCCHEN_MASK |
         EDMA3_OPT_TCINTEN_MASK);

    /* Enable TPTC1 Clocks */
    HW_WR_REG32(0x4a008778, 0x1U);
    edmaRegion = EDMA3_CC_REGION;
    EDMAsetRegion(edmaRegion);
    EDMA3Init(SOC_EDMA_TPCC_BASE_VIRT, 0);
    edmaInterruptNumber = EDMA3_CC_XFER_COMPLETION_INT;
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_DMA_INST, XBAR_DMA_INTR_SOURCE);
    {
        /* Successfully configured CrossBar */
        Intc_Init();
        Intc_IntEnable(edmaInterruptNumber);
        Intc_IntRegister(edmaInterruptNumber, (IntrFuncPtr) AppEdmaCompletionISR,
                         0);
        Intc_IntPrioritySet(edmaInterruptNumber, 1, 0);
        Intc_SystemEnable(edmaInterruptNumber);
    }
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    srcAddr = (uint32_t) mcanBaseAddr +
                         (uint32_t) testParams->mcanConfigParams.ramConfig->rxBufStartAddr;
#elif defined (SOC_TDA2PX)
    /* For J6P, MCAN address is a virtual address which needs to be converted
       physical address for DMA
    */
    srcAddr = (uint32_t) mcanBaseAddr +
                         (uint32_t) testParams->mcanConfigParams.ramConfig->rxBufStartAddr;
    srcAddr -= 0x20000000U;
#endif
    /* Configure EDMA parameters */
    edmaChannelNumber  = 17U;
    edmaEvtqNumber     = 0x0U;
    edmaTCCNumber      = 17U;
    edmaChannelNumberCh2  = 0x3U;
    edmaEvtqNumberCh2     = 0x0U;
    edmaTCCNumberCh2      = 0x3U;
    edmaParam.opt      = 0U;
    edmaParam.srcAddr  = srcAddr;
    edmaParam.destAddr = (uint32_t)&rxBuffer[0];
    edmaParam.aCnt     = (uint32_t) (72U);
    edmaParam.bCnt     = testParams->mcanConfigParams.txMSGInterationCnt;
    edmaParam.cCnt     = 1U;
    edmaParam.srcBIdx  = 0U;
    edmaParam.destBIdx = edmaParam.aCnt;
    edmaParam.srcCIdx  = 0U;
    edmaParam.destCIdx = edmaParam.aCnt * edmaParam.bCnt;
    edmaParam.linkAddr = 0xFFFFU;
   edmaParam.opt     |=
        (
         ((edmaTCCNumber << EDMA3_OPT_TCC_SHIFT) & EDMA3_OPT_TCC_MASK));
    /* Configure EDMA */
    EDMA3RequestChannel(SOC_EDMA_TPCC_BASE_VIRT,
                        EDMA3_CHANNEL_TYPE_DMA,
                        edmaChannelNumber,
                        edmaTCCNumber,
                        edmaEvtqNumber);
    EDMA3SetPaRAM(SOC_EDMA_TPCC_BASE_VIRT, edmaChannelNumber, &edmaParam);
    /* Configure the MCAN TX event. */
    CSL_xbarDmaConfigure(CSL_XBAR_DMA_CPU_ID_EDMA,
                   (edmaChannelNumber + 1),
                   DMA_EVENT_SOURCE_RX);
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    srcAddr = (uint32_t) mcanBaseAddr + (uint32_t) MCAN_NDAT1;
#elif defined (SOC_TDA2PX)
    /* For J6P, MCAN address is a virtual address which needs to be converted
       physical address for DMA
    */
    srcAddr = (uint32_t) mcanBaseAddr + (uint32_t) MCAN_NDAT1;
    srcAddr -= 0x20000000U;
#endif
    /* Configure EDMA parameters */
    edmaParam.opt      = 0U;
    edmaParam.srcAddr =  buffAddReqMem;
    edmaParam.destAddr  = srcAddr;
    edmaParam.aCnt     = 4U;
    edmaParam.bCnt     = testParams->mcanConfigParams.txMSGInterationCnt;
    edmaParam.cCnt     = 1U;
    edmaParam.srcBIdx  = 0U;
    edmaParam.destBIdx = 0U;
    edmaParam.srcCIdx  = 0U;
    edmaParam.destCIdx = 0U;
    edmaParam.linkAddr = 0xFFFFU;
    edmaParam.opt     |=
        (EDMA3_OPT_TCINTEN_MASK |
        ((edmaTCCNumberCh2 << EDMA3_OPT_TCC_SHIFT) & EDMA3_OPT_TCC_MASK));
    EDMA3RequestChannel(SOC_EDMA_TPCC_BASE_VIRT,
                        EDMA3_CHANNEL_TYPE_DMA,
                        edmaChannelNumberCh2,
                        edmaTCCNumberCh2,
                        edmaEvtqNumberCh2);
    EDMA3SetPaRAM(SOC_EDMA_TPCC_BASE_VIRT, edmaChannelNumberCh2, &edmaParam);
    /*Set params for chain transfer. Chain two channels*/
    EDMA3ChainChannel(SOC_EDMA_TPCC_BASE_VIRT,
                      edmaChannelNumber,
                      edmaChannelNumberCh2,
                      chain_param);
#endif
}

static int32_t App_mcanDMATest(st_mcanTestcaseParams_t *testParams)
{
    int32_t testStatus = STW_SOK;
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    int32_t retVal = CSL_PASS, regVal;
    uint64_t pDesc = 0;
    uint64_t startTime, endTime, tsDiff, numOfMsgPerSec, tsFreq;
#endif
    uint32_t srcAddr, eleAddr, loopCnt, txDataAddr, rxDataAddr;
    uint32_t txData, rxData, innerLoopCnt;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    srcAddr = (uint32_t)&txBuffer[0];
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    Udma_ChHandle   txChHandle = &gUdmaTxChObj;
    Udma_ChHandle   rxChHandle = &gUdmaRxChObj;

    srcAddr = (uint32_t)&txBuffer[0];
    regVal = 0U;
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.rtr << MCANSS_TX_BUFFER_ELEM_RTR_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.esi << MCANSS_TX_BUFFER_ELEM_ESI_SHIFT);
    HW_WR_REG32(srcAddr, regVal);
    srcAddr += 4U;

    regVal = 0U;
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.dlc << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.efc << MCANSS_TX_BUFFER_ELEM_EFC_SHIFT);
    regVal |= (uint32_t)(testParams->mcanConfigParams.txMsg[0U].txElem.mm << MCANSS_TX_BUFFER_ELEM_MM_SHIFT);
    HW_WR_REG32(srcAddr, regVal);
    srcAddr += 4U;
    App_CounterConfig();
    App_ConfigCounterSuspendState();

    /* Clear Rx Buffer (uint32_t)&rxBuffer[0] */
    for (loopCnt = 0U ;
         loopCnt <= testParams->mcanConfigParams.txMSGInterationCnt;
         loopCnt++)
    {
        eleAddr = (uint32_t)&rxBuffer[0] + (loopCnt * 18U * 4U);
        for (innerLoopCnt = 0U ; innerLoopCnt < 18 ; innerLoopCnt++)
        {
            HW_WR_REG32((eleAddr + (innerLoopCnt * 4U)), 0U);
        }
    }
    Udma_appUtilsCacheWb(&rxBuffer[0], sizeof(rxBuffer));

    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMSGInterationCnt;
         loopCnt++)
    {
        eleAddr = srcAddr + (loopCnt * dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]);
        App_mcanWriteMem(loopCnt, eleAddr, &testParams->mcanConfigParams.txMsg[0U].txElem);
    }
    Udma_appUtilsCacheWb(&txBuffer[0], sizeof(txBuffer));

    DMATxConfigure(testParams);
    DMARxConfigure(testParams);

    App_udmaStart(testParams);

    /* Submit HPD to RX channel before start */
    retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(rxChHandle), (uint64_t) &gRxHpdMem[0U]);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] RX Channel queue failed!!\n");
    }

    App_GetCounterValue(&startTime);
    /* Submit HPD to TX channel to start */
    retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(txChHandle), (uint64_t) &gTxHpdMem[0U]);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] TX Channel queue failed!!\n");
    }

    /* Wait for TR response in TX completion ring - this marks the
     * transfer completion */
    while (1U)
    {
        retVal = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(txChHandle), &pDesc);
        if (UDMA_SOK == retVal)
        {
            /* Response received */
            break;
        }
    }
    /* Wait for TR response in RX completion ring - this marks the
     * transfer completion */
    while (1U)
    {
        retVal = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(rxChHandle), &pDesc);
        if (UDMA_SOK == retVal)
        {
            /* Response received */
            break;
        }
    }

    App_GetCounterValue(&endTime);
    if (CSL_PASS != retVal)
    {
    }
    App_udmaStop();
    /* Check for Tx and Rx data available in MS RAM */
    txDataAddr = (uint32_t)&txBuffer[0];
    rxDataAddr = (uint32_t)&rxBuffer[0];
    /* Skip header */
    txDataAddr += 0x8U;
    rxDataAddr += 0x8U;
    Udma_appUtilsCacheInv(&txBuffer[0], sizeof(txBuffer));
    Udma_appUtilsCacheInv(&rxBuffer[0], sizeof(rxBuffer));
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         loopCnt++)
    {
        for (innerLoopCnt = 0U ; innerLoopCnt < 16U ; innerLoopCnt++)
        {
            txData = HW_RD_REG32((txDataAddr + (loopCnt * 16U * 4U) + (innerLoopCnt * 4U)));
            rxData = HW_RD_REG32((rxDataAddr + (loopCnt * 16U* 4U) + (innerLoopCnt * 4U)));
            if (txData != rxData)
            {
                break;
            }
        }
        if (innerLoopCnt < 16U)
        {
            break;
        }
    }
    if (loopCnt < testParams->mcanConfigParams.txMSGInterationCnt)
    {
        testStatus += STW_EFAIL;
        printf("\nReceived data does not match with sent data...");
    }
    else
    {
        printf("\nReceived data matches with sent data...");
    }
    tsDiff = endTime - startTime;
#if defined (SOC_J721E)
    tsFreq = Utils_prfTsGetFreq() * 1000;
#else
    tsFreq = MCAN_APP_CNT_FREQ_KHZ;
#endif
    printf("\n%lld Cycles (%lldKhz) for %d messages.", tsDiff, (tsFreq / 1000), testParams->mcanConfigParams.txMSGInterationCnt);
    numOfMsgPerSec = ((uint64_t)testParams->mcanConfigParams.txMSGInterationCnt *
                      (uint64_t)testParams->mcanConfigParams.txMsgNum * (uint64_t)tsFreq) / tsDiff;
    printf("\nThroughput :%lld MSG/sec", numOfMsgPerSec);

    App_udmaDeInit();
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nDMA Tx Side Test Application\n");
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMSGInterationCnt;
         loopCnt++)
    {
        /* Full CAN FD message supported only i.e. 18 words */
        eleAddr = srcAddr + (loopCnt * 18U * 4U);
        App_mcanWriteMem(loopCnt, eleAddr, &testParams->mcanConfigParams.txMsg[0U].txElem);
    }
    HW_WR_REG32(0x82000000, 0x1U);
    HW_WR_REG32(0x82000040, 0x1U);
    DMATxConfigure(testParams);

    App_delayFunc(100U);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Data:\n");
    EDMA3EnableTransfer(SOC_EDMA_TPCC_BASE_VIRT,
                        edmaChannelNumber,
                        EDMA3_TRIG_MODE_EVENT);
    EDMA3EnableTransfer(SOC_EDMA_TPCC_BASE_VIRT,
                        edmaChannelNumber,
                        EDMA3_TRIG_MODE_MANUAL);
    edmaTransferComplete = 1U;
    while(edmaTransferComplete)
    {
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nReceiving Data:\n");
    edmaTransferComplete = 1U;
    DMARxConfigure(testParams);
    EDMA3EnableTransfer(SOC_EDMA_TPCC_BASE_VIRT,
                        edmaChannelNumber,
                        EDMA3_TRIG_MODE_EVENT);

    UARTConfigPrintf(uartBaseAddr, "\nReceiving Data:\n");
    while(edmaTransferComplete)
    {
    }

    /* Check for Tx and Rx data available in DDR */
    txDataAddr = (uint32_t)&txBuffer[0];
    rxDataAddr = (uint32_t)&rxBuffer[0];
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         loopCnt++)
    {
        for (innerLoopCnt = 2U ; innerLoopCnt < 18U ; innerLoopCnt++)
        {
            txData = HW_RD_REG32((txDataAddr + (loopCnt * 18U * 4U) + (innerLoopCnt * 4U)));
            rxData = HW_RD_REG32((rxDataAddr + (loopCnt * 18U* 4U) + (innerLoopCnt * 4U)));
            if (txData != rxData)
            {
                break;
            }
        }
        if (innerLoopCnt < 18U)
        {
            break;
        }
    }
    if (loopCnt < testParams->mcanConfigParams.txMSGInterationCnt)
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Received Data does not match with  Sent data.\n");
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Message Number: %d and Word Number: %d\n", loopCnt, innerLoopCnt);
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Addr: 0x%x and Rx Addr: 0x%x\n", ((txDataAddr + (loopCnt * 18U * 4U) + (innerLoopCnt * 4U))), ((rxDataAddr + (loopCnt * 18U * 4U) + (innerLoopCnt * 4U))));
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Tx Data: 0x%x and Rx Data: 0x%x\n", txData, rxData);
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Received Data matched with  Sent data.\n");
    }

#endif
    return testStatus;
}

static int32_t App_mcanStateTransnTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, txBufNum;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus errCnt;
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    uint32_t regVal;
#endif

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Un-do the PAD config */
    /* tx PAD */
    HW_WR_REG32(0x4A0035BCU, 0x6000FU);
    /* rx PAD */
    HW_WR_REG32(0x4A0035C0U, 0x6000FU);
#elif defined (SOC_TDA2PX)
    /*Pad configurations - MCAN */
    /* Configure mcan_tx, mcan_rx pads on dcan1_tx and dcan1_rx pads */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE+CTRL_CORE_CONTROL_SPARE_RW,
        CTRL_CORE_CONTROL_SPARE_RW_SEL_ALT_MCAN,
        0x0U);

    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_TX,0x0004000F);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_RX,0x0004000F);
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    /* Un-do the PAD config */
    /* MCAN 0 Tx PAD configuration */
    regVal = HW_RD_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U);
    regVal &= 0U;//0xFFF00000;
    regVal |= 0x260000U;
    HW_WR_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U, regVal);
    /* MCAN 0 Rx PAD configuration */
    regVal = HW_RD_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU);
    regVal &= 0U;//0xFFF00000;
    regVal |= 0x260000U;
    HW_WR_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU, regVal);
#endif
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
                testStatus += STW_EFAIL;
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
            testStatus += STW_EFAIL;
        }
    }

    loopCnt = 0U;
    txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Message with following details:\n");
    App_mcanPrintTxMsg(&testParams->mcanConfigParams.txMsg[loopCnt].txElem);

    /* Write message to Msg RAM */
    MCAN_writeMsgRam(mcanBaseAddr,
                     testParams->mcanConfigParams.txMsg[0U].storageId,
                     txBufNum,
                     &testParams->mcanConfigParams.txMsg[0U].txElem);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCurrent State: Error Active\n");
    while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_ERR_PASSIVE) ==
                                MCAN_INTR_SRC_ERR_PASSIVE))
    {
        /* add transmission request only if previous transmission is completed */
        if ((MCAN_getTxBufReqPend(mcanBaseAddr) & (1U << txBufNum)) != (1U << txBufNum))
        {
            loopCnt++;
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
                testStatus += STW_EFAIL;
            }
        }
    }
    gMcanIsrIntr0Status = 0U;
    MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    if ((protStatus.errPassive == 1U) && (protStatus.busOffStatus != 1U))
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCurrent State: Error Passive\n");
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Message transmitted unsuccessfully: %d\n", loopCnt);

    }

    while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_BUS_OFF_STATUS) ==
                                MCAN_INTR_SRC_BUS_OFF_STATUS))
    {
        /* add transmission request only if previous transmission is completed */
        if ((MCAN_getTxBufReqPend(mcanBaseAddr) & (1U << txBufNum)) != (1U << txBufNum))
        {
            loopCnt++;
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
        }
    }
    gMcanIsrIntr0Status = 0U;
    MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    if ((protStatus.errPassive == 1U) &&
        (protStatus.busOffStatus == 1U) &&
        (MCAN_OPERATION_MODE_SW_INIT == MCAN_getOpMode(mcanBaseAddr)))
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCurrent State: Bus Off\n");
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Message transmitted unsuccessfully: %d\n", loopCnt);

    }
    loopCnt = 0U;
    /* Configure MCAN Tx and Rx pins for successful transmission of message */
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* tx PAD */
    HW_WR_REG32(0x4A0035BCU, 0x6000CU);
    /* rx PAD */
    HW_WR_REG32(0x4A0035C0U, 0x6000CU);
#elif defined (SOC_TDA2PX)
    /*Pad configurations - MCAN */
    /* Configure mcan_tx, mcan_rx pads on dcan1_tx and dcan1_rx pads */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE+CTRL_CORE_CONTROL_SPARE_RW,
        CTRL_CORE_CONTROL_SPARE_RW_SEL_ALT_MCAN,
        CTRL_CORE_CONTROL_SPARE_RW_SEL_ALT_MCAN_MCAN_DCAN1_PADS);

    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_TX,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_RX,0x00040000);
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    /* do the PAD config */
    /* MCAN 0 Tx PAD configuration */
    regVal = HW_RD_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U);
    regVal &= 0U;//0xFFF00000;
    regVal |= 0x60000U;
    HW_WR_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U, regVal);
    /* MCAN 0 Rx PAD configuration */
    regVal = HW_RD_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU);
    regVal &= 0U;//0xFFF00000;
    regVal |= 0x60000U;
    HW_WR_REG32(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU, regVal);
#endif
    /* Clear pending Tx request */
    MCAN_txBufCancellationReq(mcanBaseAddr, 0U);
    while ((MCAN_txBufCancellationStatus(mcanBaseAddr)  & (0x1 << 0)) != (0x1 << 0))
    {
    }
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
    {}
    /* wait for 129 occurrences of Bus Idle (129 × 11 consecutive recessive bits)
       before resuming normal operation. */
    /* The MCAN_ECR[14:8] REC field is used to count these sequences */
    /* Wait till first 11 consecutive recessive bits are detected */
    /* After resetting CCCR.INIT bit, MCAN writes to '5'(MCAN_ERR_CODE_BIT0_ERROR) to PSR.LEC */
    MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    while (protStatus.lastErrCode != MCAN_ERR_CODE_BIT0_ERROR)
    {
        MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    }
    /* This is 7 bit field(max value 127), so wait till it becomes none zero */
    /* wait for rest 128 occurrences */
    MCAN_getErrCounters(mcanBaseAddr, &errCnt);
    while (errCnt.recErrCnt != 0U)
    {
        MCAN_getErrCounters(mcanBaseAddr, &errCnt);
    }
    MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
    if ((protStatus.errPassive == 0U) &&
        (protStatus.busOffStatus == 0U) &&
        (protStatus.warningStatus == 0U))
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCurrent State: Error Active\n");
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Message transmitted Successfully: %d\n", loopCnt);
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nCurrent State: Error Warning/Passive or Bus Off\n");
        testStatus += STW_EFAIL;
    }

    return testStatus;
}

static int32_t App_mcanExtTSIntrTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t testStatus = STW_SOK;

    gMcanExtTSIntrFlag = 1U;
    /* Enable External Time Stamp Interrupt */
    MCAN_extTSEnableIntr(mcanBaseAddr, TRUE);

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Waiting for 1st Interrupt...\n");
    while (gMcanExtTSIntrFlag)
    {
    }
    gMcanExtTSIntrFlag = 1U;
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Waiting for 2nd Interrupt...\n");
    while (gMcanExtTSIntrFlag)
    {
    }
    gMcanExtTSIntrFlag = 1U;
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Waiting for 3rd Interrupt...\n");
    while (gMcanExtTSIntrFlag)
    {
    }
    gMcanExtTSIntrFlag = 1U;
    /* Disable External Time Stamp Interrupt */
    MCAN_extTSEnableIntr(mcanBaseAddr, FALSE);

    return testStatus;
}

static int32_t App_mcanTxRxPinStateTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t testStatus = STW_SOK;

    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
    {}

    if (MCAN_getRxPinState(mcanBaseAddr) == 1U)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Recessive\n");
    }
    else
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Dominant\n");
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Setting Rx PAD into Dominant mode.\n");
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* put UART1_TXD into mcan_rx mode */
    HW_WR_REG32(0x4A0035C0U, 0x0000CU);
#elif defined (SOC_TDA2PX)
    /* put IO PAD into mcan_rx mode */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_DCAN1_RX,0x00000000);
#endif
    if (MCAN_getRxPinState(mcanBaseAddr) == 1U)
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Recessive\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Dominant\n");
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Setting Tx PAD into Dominant mode.\n");
    MCAN_setTxPinState(mcanBaseAddr, 0x2);
    if (MCAN_getTxPinState(mcanBaseAddr) == 0x2U)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Tx Pin Mode: Dominant\n");
    }
    else
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Recessive\n");
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Setting Tx PAD into Recessive mode.\n");
    MCAN_setTxPinState(mcanBaseAddr, 0x3);
    if (MCAN_getTxPinState(mcanBaseAddr) == 0x3U)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Tx Pin Mode: Recessive\n");
    }
    else
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Rx Pin Mode: Dominant\n");
    }

    return testStatus;
}

static int32_t App_mcanClkStpReqTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t testStatus = STW_SOK;

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Asserting Clock Stop Request..\n");
    MCAN_addClockStopRequest(mcanBaseAddr, TRUE);
    while (MCAN_getClkStopAck(mcanBaseAddr) != 1U)
    {
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Clock Stop Request ACKed!!\n");
    if (MCAN_OPERATION_MODE_SW_INIT == MCAN_getOpMode(mcanBaseAddr))
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "MCAN is in SW Init Mode.\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "MCAN is in not SW Init Mode.\n");
        testStatus += STW_EFAIL;
    }

    return testStatus;
}

static int32_t App_mcanTSRstTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t testStatus = STW_SOK;
    uint32_t oldTimeStamp, timeStamp;

    timeStamp = MCAN_getTSCounterVal(mcanBaseAddr);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "TS at (t) ms: %d\n", timeStamp);
    /* Delay added for getting new timeStamp- so that there will difference between two timeStamps */
    App_delayFunc(10);
    oldTimeStamp = timeStamp;
    timeStamp = MCAN_getTSCounterVal(mcanBaseAddr);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "TS at (t + 10) ms: %d\n", timeStamp);

    /* reset TS counter */
    MCAN_resetTSCounter(mcanBaseAddr);
    oldTimeStamp = timeStamp;
    timeStamp = MCAN_getTSCounterVal(mcanBaseAddr);
    /* wrap around condition is not taken care */
    if (timeStamp < oldTimeStamp)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "TS Counter Reset done!!\n");
    }
    else
    {
        testStatus += STW_EFAIL;
    }


    return testStatus;
}

static int32_t App_mcanBusMonTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t configStatus = STW_SOK, testStatus = STW_SOK;
    MCAN_RxBufElement rxMsg;

    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    gMcanIsrIntr0Status = 0U;
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Send message over the CAN network(TDA3xx MCAN and only one another node).\n");
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Same message shall be received by MCAN but transmitter node shall get ACK Error.\n");
    while  (!(((gMcanIsrIntr0Status & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ==
                                    MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG) ||
            ((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ||
            ((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ==
                                    MCAN_INTR_SRC_RX_FIFO1_NEW_MSG)))
    {
    }
    /* Disable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        0U);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Message received:\n");
    configStatus += App_mcanReadRxMSG(&rxMsg, gMcanIsrIntr0Status);
    if(configStatus != STW_SOK)
    {
        testStatus += STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nUnable to read received message.\n");
    }
    gMcanIsrIntr0Status = 0U;

    return testStatus;
}

static int32_t App_mcanLatencyTest(st_mcanTestcaseParams_t *testParams)
{
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    // volatile uint32_t flag = 1U;
    uint64_t startTime, endTime, latency;
    uint64_t regVal;
    uint32_t interationCnt = 1000U, loopCnt;
    MCAN_TxBufElement txMsg = testParams->mcanConfigParams.txMsg[0U].txElem;
    MCAN_RxBufElement rxMsg;

    App_CounterConfig();
    App_ConfigCounterSuspendState();

    /* Read Latency */
    App_GetCounterValue(&startTime);
    for (loopCnt = 0U ; loopCnt <  interationCnt ; loopCnt++)
    {
        HW_RD_REG32(mcanBaseAddr + MCAN_IE);
    }
    App_GetCounterValue(&endTime);
    latency = (endTime - startTime);
    printf("\nCycles taken for %d reads(200Mhz Clock):%lld\n", interationCnt, latency);

    /* Write Latency */
    regVal = HW_RD_REG32(mcanBaseAddr + MCAN_IE);
    App_GetCounterValue(&startTime);
    for (loopCnt = 0U ; loopCnt <  interationCnt ; loopCnt++)
    {
        HW_WR_REG32(mcanBaseAddr + MCAN_IE, regVal);
    }
    App_GetCounterValue(&endTime);
    latency = (endTime - startTime);
    printf("\nCycles taken for %d writes(200Mhz Clock):%lld\n", interationCnt, latency);

    /* Message Read Latency */
    /* Write pre-defined message to 1st Rx Buffer */
    App_mcanWriteMsg(mcanBaseAddr, (testParams->mcanConfigParams.ramConfig->rxBufStartAddr), &txMsg);
    App_GetCounterValue(&startTime);
    for (loopCnt = 0U ; loopCnt <  interationCnt ; loopCnt++)
    {
        MCAN_readMsgRam(mcanBaseAddr,
                        MCAN_MEM_TYPE_BUF,
                        0U,
                        0U,
                        &rxMsg);
    }
    App_GetCounterValue(&endTime);
    latency = (endTime - startTime);
    /* Check read message with pre-defined written message:checking only payload */
    if (STW_SOK == App_mcanTxRxMessageCheck(txMsg, rxMsg))
    {
        printf("\nRead message from MSG RAM matches with pre-defined message");
    }
    else
    {
        printf("\nRead message from MSG RAM does not match with pre-defined message");
    }
    printf("\nCycles taken for %d messages read(200Mhz Clock):%lld\n", interationCnt, latency);

    /* Message Write Latency */
    /* Write a message to 1st Tx Buffer */
    App_GetCounterValue(&startTime);
    for (loopCnt = 0U ; loopCnt <  interationCnt ; loopCnt++)
    {
        MCAN_writeMsgRam(mcanBaseAddr,
                         MCAN_MEM_TYPE_BUF,
                         0U,
                         &txMsg);
    }
    App_GetCounterValue(&endTime);
    /* Read pre-defined message written to 1st Tx Buffer */
    App_mcanReadMsg(mcanBaseAddr, (testParams->mcanConfigParams.ramConfig->txStartAddr), &rxMsg);
    /* Check read message with pre-defined written message:checking only payload */
    if (STW_SOK == App_mcanTxRxMessageCheck(txMsg, rxMsg))
    {
        printf("\nWritten message to MSG RAM matches with pre-defined message");
    }
    else
    {
        printf("\nWritten message to MSG RAM does not match with pre-defined message");
    }
    latency = (endTime - startTime);
    printf("\nCycles taken for %d messages write(200Mhz Clock):%lld\n", interationCnt, latency);
#endif
    return (STW_SOK);
}

int32_t App_mcanPerfTxRxTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    MCAN_RxFIFOStatus fifoStatus;
    MCAN_RxBufElement rxMsg;
    uint32_t loopCnt      = 1U, iterationCnt = 0U, txBufNum, maxMsgCnt;
    MCAN_ErrCntStatus    errCounter;
    MCAN_TxFIFOStatus txFIFOStatus;
    uint64_t ts1, ts2, tsDiff, hwUtiln, tsFreq;
    uint64_t numOfMsgPerSec;

    enbaleIsrPrint(FALSE);
    configStatus += mcanClockEnableandPADConfig();
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Clock and PAD Configuration...");
    }
    configStatus += App_mcanRegisterInterrupt(gMcanModuleIdx);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in X-Bar Configuration...");
    }

#if defined (SOC_AM65XX) || defined (SOC_J721E)
    App_CounterConfig();
    App_ConfigCounterSuspendState();
#endif
    /* Reset MCAN Module */
    MCAN_reset(mcanBaseAddr);
    while (MCAN_isInReset(mcanBaseAddr) == (uint32_t)TRUE)
    {
    }
    configStatus += App_mcanConfig(testParams);
    if (STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN Configuration...");
    }

    configStatus += App_mcanTCEntrySetup(testParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Entry Configuration...TC cannot be Run...");
    }
    else
    {
    }
    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
    }

    /* Check for STD vs EXT ID and FD vs Classic messages for CAN message */
    if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 1U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 1U))
    {
        maxMsgCnt = MCAN_THEOROTICAL_MAX_EXT_1_5_MBPS;
    }
    else if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 1U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 0U))
    {
        maxMsgCnt = MCAN_CLASSIC_CAN_THEOROTICAL_MAX_EXT_1_MBPS;
    }
    else if ((testParams->mcanConfigParams.txMsg[0U].txElem.xtd == 0U) && (testParams->mcanConfigParams.txMsg[0U].txElem.fdf == 0U))
    {
        maxMsgCnt = MCAN_CLASSIC_CAN_THEOROTICAL_MAX_STD_1_MBPS;
    }
    else
    {
        maxMsgCnt = MCAN_THEOROTICAL_MAX_STD_1_5_MBPS;
    }
    /* Throughput measurement for Tx only */
    /* capture time stamp before triggering Tx */
    App_GetCounterValue(&ts1);
    for (iterationCnt = 0U ;
         iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         iterationCnt++)
    {
        for (loopCnt = 0U ;
             loopCnt < testParams->mcanConfigParams.txMsgNum ;
             loopCnt++)
        {
            MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
            if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
            {
                txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
            }
            else
            {
                txBufNum = txFIFOStatus.putIdx;
            }
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
            {
            }
            gMcanIsrIntr0Flag = 1U;
            /* Checking for Errors */
            MCAN_getErrCounters(mcanBaseAddr, &errCounter);
            if ((0U != errCounter.recErrCnt) &&
                (0U != errCounter.transErrLogCnt))
            {
                /* Error occurred in transmission*/
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception(Iteration Count:Message Number): (%d,%d).\n",
                           (iterationCnt + 1U), (loopCnt + 1U));
                break;
            }
            gMcanIsrIntr0Status = 0U;
        }
    }
    /* capture time stamp After Tx completion */
    App_GetCounterValue(&ts2);
    tsDiff = ts2 - ts1;
#if defined (SOC_J721E)
    tsFreq = Utils_prfTsGetFreq() * 1000;
#else
    tsFreq = MCAN_APP_CNT_FREQ_KHZ;
#endif
    numOfMsgPerSec = ((uint64_t)testParams->mcanConfigParams.txMSGInterationCnt *
                      (uint64_t)testParams->mcanConfigParams.txMsgNum * tsFreq) / tsDiff;
    /* If internal loopback then no need of x2 as Tx and Rx nodes are same */
    if (!(testParams->mcanConfigParams.mcanTestType == MCAN_TEST_TYPE_INTERNAL_LOOBACK))
    {
        numOfMsgPerSec *= 2U;
    }
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nThroughPut: %lld Msg/sec\n", numOfMsgPerSec);
    hwUtiln = ((numOfMsgPerSec * 100) / maxMsgCnt);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "HW Utilization: %lld", hwUtiln);
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    printf("\nTx:: Iteration Count:%d\tNumber of messages:%d", testParams->mcanConfigParams.txMSGInterationCnt, testParams->mcanConfigParams.txMsgNum);
    printf("\nTx:: Elapsed Iteration Count: %d", iterationCnt);
    printf("\nTx:: Numer of Ticks(200Mhz): (%lld - %lld)%lld", ts2, ts1, tsDiff);
    printf("\nTx:: ThroughPut: %lld Msg/sec", numOfMsgPerSec);
    printf("\nTx:: HW Utilization: %lld", hwUtiln);
#endif
    /* Throughput measurement for Rx only */
    /* capture time stamp before triggering Tx */
    App_GetCounterValue(&ts1);
    for (iterationCnt = 0U ;
         iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         iterationCnt++)
    {
        for (loopCnt = 0U ;
             loopCnt < testParams->mcanConfigParams.txMsgNum ;
             loopCnt++)
        {
            /* Messages will be stored in FIFO1 as these will fail filters and non-matching messages are stored into FIFO 1 */
            fifoStatus.num = (uint32_t)MCAN_RX_FIFO_NUM_1;
            MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
            MCAN_readMsgRam(mcanBaseAddr,
                            MCAN_MEM_TYPE_FIFO,
                            fifoStatus.getIdx,
                            (uint32_t)fifoStatus.num,
                            &rxMsg);
            (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                       (uint32_t)fifoStatus.num,
                                       fifoStatus.getIdx);
            configStatus += App_mcanTxRxMessageCheck(
                                testParams->mcanConfigParams.txMsg[loopCnt].txElem,
                                rxMsg);
            if(configStatus != STW_SOK)
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmitted and received message does not match(Iteration Count:Message Number): (%d,%d).\n", (iterationCnt + 1U), (loopCnt + 1U));
                break;
            }
        }
        if (loopCnt < testParams->mcanConfigParams.txMsgNum)
        {
            break;
        }
    }
    if (iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt)
    {
        printf("\nSent and received messages does not match...%d, %d", iterationCnt, loopCnt);
        testStatus += STW_EFAIL;
    }
    else
    {
        /* capture time stamp After Tx completion */
        App_GetCounterValue(&ts2);
        tsDiff = ts2 - ts1;
        numOfMsgPerSec = ((uint64_t)testParams->mcanConfigParams.txMSGInterationCnt *
                          (uint64_t)testParams->mcanConfigParams.txMsgNum * tsFreq) / tsDiff;
        /* If internal loopback then no need of x2 as Tx and Rx nodes are same */
        if (!(testParams->mcanConfigParams.mcanTestType == MCAN_TEST_TYPE_INTERNAL_LOOBACK))
        {
            numOfMsgPerSec *= 2U;
        }
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nThroughPut: %lld Msg/sec\n", numOfMsgPerSec);
        hwUtiln = ((numOfMsgPerSec * 100) / maxMsgCnt);
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "HW Utilization: %lld", hwUtiln);
#if defined (SOC_AM65XX) || defined (SOC_J721E)
        printf("\nRx:: Iteration Count:%d\tNumber of messages:%d", testParams->mcanConfigParams.txMSGInterationCnt, testParams->mcanConfigParams.txMsgNum);
        printf("\nRx:: Elapsed Iteration Count: %d", iterationCnt);
        printf("\nRx:: Numer of Ticks(200Mhz): (%lld - %lld)%lld", ts2, ts1, tsDiff);
#endif
    }
    testParams->testResult += App_mcanCheckTCResultsMisc(testParams);
    configStatus += App_mcanTCExitSetup(testParams);
    if(configStatus != STW_SOK)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in MCAN TC Exit Configuration...");
    }
    if(hwUtiln < 70U)
    {
        testParams->testResult += STW_EFAIL;
        testStatus += STW_EFAIL;
    }
    testParams->isRun      = STW_SOK;
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nPer TX Test: %d", testStatus);

    return testStatus;
}

int32_t App_mcanMsgArbTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, iterationCnt = 0U, txBufNum, lastMsgId, idMask;
    uint32_t cnt = 0U, idShift;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    MCAN_RxFIFOStatus fifoStatus;

    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
    }
    for (iterationCnt = 0U ;
         iterationCnt < testParams->mcanConfigParams.txMSGInterationCnt ;
         iterationCnt++)
    {
        /* Add transmission request for the message in single go.
         * This is not possible with current API implementation, so put MCAN into SW Init mode
         * then add transmission request for buffers and then put MCAN into Normal operational mode */
        /* Put MCAN in SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
        while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
        {}
        /* First write all messages to message RAM and then trigger their transmission in single go */
        for (loopCnt = 0U ;
             loopCnt < testParams->mcanConfigParams.txMsgNum ;
             loopCnt++)
        {
            MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
            if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
            {
                txBufNum = testParams->mcanConfigParams.txMsg[loopCnt].bufferNum;
            }
            else
            {
                txBufNum = txFIFOStatus.putIdx;
            }
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(mcanBaseAddr,
                             testParams->mcanConfigParams.txMsg[loopCnt].storageId,
                             txBufNum,
                             &testParams->mcanConfigParams.txMsg[loopCnt].txElem);
            /* Add request for transmission */
            configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
            if (STW_SOK != configStatus)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
            }
            gMcanIsrIntr0Status = 0U;
        }
        /* Take MCAN out of the SW initialization mode */
        MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
        while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
        {}
        /* wait till all messages has been received - not checking for each message individually */
        fifoStatus.num = (uint32_t)testParams->mcanConfigParams.txMsg[0U].rxBuffNum;
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        while (fifoStatus.fillLvl < testParams->mcanConfigParams.txMsgNum)
        {
            MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        }
        /* All the messages has been received */
        /* Checking for Errors */
        MCAN_getErrCounters(mcanBaseAddr, &errCounter);
        if ((0U == errCounter.recErrCnt) &&
            (0U == errCounter.canErrLogCnt))
        {
            MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
            /* Checking for Errors */
            if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                (0U == protStatus.pxe))
            {
                lastMsgId = 0U;
                /* Read messages from Rx FIFO */
                fifoStatus.num = (uint32_t)testParams->mcanConfigParams.txMsg[0U].rxBuffNum;
                for (loopCnt = 0U ;
                     loopCnt < testParams->mcanConfigParams.txMsgNum ;
                     loopCnt++)
                {
                    MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
                    MCAN_readMsgRam(mcanBaseAddr,
                                    (uint32_t)MCAN_MEM_TYPE_FIFO,
                                    fifoStatus.getIdx,
                                    (uint32_t)fifoStatus.num,
                                    &rxMsg);
                    (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                               (uint32_t)fifoStatus.num,
                                               fifoStatus.getIdx);
                    if (rxMsg.xtd == 1U)
                    {
                        idMask = APP_MCAN_EXT_ID_MASK;
                        idShift = APP_MCAN_EXT_ID_SHIFT;
                    }
                    else
                    {
                        idMask = APP_MCAN_STD_ID_MASK;
                        idShift = APP_MCAN_STD_ID_SHIFT;
                    }
                    if ((lastMsgId & idMask) > (rxMsg.id & idMask))
                    {
                        testStatus += STW_EFAIL;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError: Messages did not receive in expected order.\n");
                        break;
                    }
                    else
                    {
                        lastMsgId = rxMsg.id;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "(%d)th message received: (ID: 0x%x)(TS: %d)\n", (loopCnt + 1U), ((rxMsg.id & idMask) >> idShift), rxMsg.rxts);
                        /* check received message against sent message */
                        for (cnt = 0U ;
                             cnt < testParams->mcanConfigParams.txMsgNum ;
                             cnt++)
                        {
                            if ((testParams->mcanConfigParams.txMsg[cnt].txElem.id & idMask) ==
                                (rxMsg.id & idMask))
                            {
                                break;
                            }
                        }
                        configStatus += App_mcanTxRxMessageCheck(
                                        testParams->mcanConfigParams.txMsg[cnt].txElem,
                                        rxMsg);
                        if(configStatus != STW_SOK)
                        {
                            testStatus += STW_EFAIL;
                            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nTransmitted and received message does not match.\n");
                        }
                    }
                }
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count): (%d).\n",
                           (iterationCnt + 1U));
            }
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception(Iteration Count): (%d).\n",
                       (iterationCnt + 1U));
        }
    }

    return testStatus;
}

int32_t App_mcanRxFIFOModes(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U, loopBreakFlag = 1U, txBufNum;
    uint32_t getIdx, putIdx, fifoLength;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    MCAN_RxFIFOStatus fifoStatus;
    MCAN_ConfigParams configParams;

    /* Enable Interrupts */
    MCAN_enableIntr(mcanBaseAddr, testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLineSelectMask,
                        testParams->mcanConfigParams.intrLine);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(mcanBaseAddr,
                        testParams->mcanConfigParams.intrLine,
                        1U);
    /* Enable interrupts for Tx Buffers */
    for (loopCnt = 0U ;
         loopCnt < testParams->mcanConfigParams.txMsgNum ;
         loopCnt++)
    {
        if (testParams->mcanConfigParams.txMsg[loopCnt].storageId ==
                                                        MCAN_MEM_TYPE_BUF)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                    testParams->mcanConfigParams.txMsg[loopCnt].bufferNum,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
            }
        }
    }
    /* Enable interrupts for Tx FIFO/Queue */
    for (loopCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
         loopCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                    testParams->mcanConfigParams.ramConfig->txBufNum);
         loopCnt++)
    {
        /* Enable Transmission interrupt */
        configStatus += MCAN_txBufTransIntrEnable(mcanBaseAddr,
                loopCnt,
                (uint32_t)TRUE);
        if(configStatus != STW_SOK)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
        }
    }
    /* FIFO Block mode Test - Start */
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nFIFO 1 Blocking Mode Test:\n", -1);
    fifoLength = testParams->mcanConfigParams.ramConfig->rxFIFO1size;
    /* Accept non-matching messages into FIFO1 */
    /* Send messages until FIFO1 condition is reached */
    loopCnt = 0U;
    while (loopBreakFlag == 1U)
    {
        loopCnt++;
        MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
        if (testParams->mcanConfigParams.txMsg[0U].storageId ==
                                                    MCAN_MEM_TYPE_BUF)
        {
            txBufNum = testParams->mcanConfigParams.txMsg[0U].bufferNum;
        }
        else
        {
            txBufNum = txFIFOStatus.putIdx;
        }
        /* Write message to Msg RAM-sending message with extended ID only */
        testParams->mcanConfigParams.txMsg[0U].txElem.id = loopCnt;
        testParams->mcanConfigParams.txMsg[0U].txElem.xtd = 1U;
        MCAN_writeMsgRam(mcanBaseAddr,
                         testParams->mcanConfigParams.txMsg[0U].storageId,
                         txBufNum,
                         &testParams->mcanConfigParams.txMsg[0U].txElem);
        /* Add request for transmission */
        configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
        if (STW_SOK != configStatus)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
        {
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO1_NEW_MSG) ==
                                MCAN_INTR_SRC_RX_FIFO1_NEW_MSG))
        {
        }
        if ((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO1_FULL) ==
                                MCAN_INTR_SRC_RX_FIFO1_FULL)
        {
            loopBreakFlag = 0U;
        }
        gMcanIsrIntr0Status = 0U;
        /* Checking for Errors */
        MCAN_getErrCounters(mcanBaseAddr, &errCounter);
        if ((0U == errCounter.recErrCnt) &&
            (0U == errCounter.canErrLogCnt))
        {
            MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
            /* Checking for Errors */
            if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                (0U == protStatus.pxe))
            {
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count).\n");
                loopBreakFlag = 0U;
            }
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception.\n");
            loopBreakFlag = 0U;
        }
    }
    fifoStatus.num = MCAN_RX_FIFO_NUM_1;
    MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
    if (fifoStatus.fifoFull == 1U)
    {
        getIdx = fifoStatus.getIdx;
        putIdx = fifoStatus.putIdx;
        loopCnt++;
        /* Send another message to cause overflow */
        /* Write message to Msg RAM-sending message with extended ID only */
        testParams->mcanConfigParams.txMsg[0U].txElem.id = loopCnt;
        testParams->mcanConfigParams.txMsg[0U].txElem.xtd = 1U;
        MCAN_writeMsgRam(mcanBaseAddr,
                         testParams->mcanConfigParams.txMsg[0U].storageId,
                         txBufNum,
                         &testParams->mcanConfigParams.txMsg[0U].txElem);
        /* Add request for transmission */
        configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
        if (STW_SOK != configStatus)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
        {
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO1_MSG_LOST) ==
                                MCAN_INTR_SRC_RX_FIFO1_MSG_LOST))
        {
        }
        /* get FIFO status, since FIFO is in Blocking mode, latest message will
         * lost and get/put index will not be updated */
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        if ((getIdx == fifoStatus.getIdx) && (putIdx == fifoStatus.putIdx))
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nGet and Put Indices are not updated after sending message after FIFO Full Condition.\n", -1);
        }
        /* Read first message in FIFO - this should be oldest message(with EXT ID: 1) */
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        MCAN_readMsgRam(mcanBaseAddr,
                        MCAN_MEM_TYPE_FIFO,
                        fifoStatus.getIdx,
                        (uint32_t)fifoStatus.num,
                        &rxMsg);
        (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                   (uint32_t)fifoStatus.num,
                                   fifoStatus.getIdx);
        if (rxMsg.id == 1U)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nOldest message is not overwritten, FIFO is in Blocking Mode.\n", -1);
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nOldest message is overwritten, FIFO is not in Blocking Mode.\n", -1);
        }
    }
    else
    {
        testStatus += STW_EFAIL;
    }
    /* FIFO Block mode Test - End */
    /* FIFO Overwrite mode Test - Start */
    fifoLength = testParams->mcanConfigParams.ramConfig->rxFIFO0size;
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nFIFO 0 Overwrite Mode Test:\n", -1);
    /* Accept non-matching messages into FIFO0(previously was FIFO1) */
    configParams.monEnable = testParams->mcanConfigParams.configParams->monEnable;
    configParams.asmEnable = testParams->mcanConfigParams.configParams->asmEnable;
    configParams.tsPrescalar = testParams->mcanConfigParams.configParams->tsPrescalar;
    configParams.tsSelect = testParams->mcanConfigParams.configParams->tsSelect;
    configParams.timeoutPreload = testParams->mcanConfigParams.configParams->timeoutPreload;
    configParams.timeoutCntEnable = testParams->mcanConfigParams.configParams->timeoutCntEnable;
    configParams.filterConfig.rrfe = testParams->mcanConfigParams.configParams->filterConfig.rrfe;
    configParams.filterConfig.rrfs = testParams->mcanConfigParams.configParams->filterConfig.rrfs;
    configParams.filterConfig.anfe = 0U;
    configParams.filterConfig.anfs = 0U;
    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(mcanBaseAddr))
    {}
    MCAN_config(mcanBaseAddr, &configParams);
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(mcanBaseAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(mcanBaseAddr))
    {}
    /* Send messages until FIFO1 condition is reached */
    loopCnt = 0U;
    gMcanIsrIntr0Status = 0U;
    loopBreakFlag = 1U;
    while (loopBreakFlag == 1U)
    {
        loopCnt++;
        MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
        if (testParams->mcanConfigParams.txMsg[0U].storageId ==
                                                    MCAN_MEM_TYPE_BUF)
        {
            txBufNum = testParams->mcanConfigParams.txMsg[0U].bufferNum;
        }
        else
        {
            txBufNum = txFIFOStatus.putIdx;
        }
        /* Write message to Msg RAM-sending message with extended ID only */
        testParams->mcanConfigParams.txMsg[0U].txElem.id = loopCnt;
        testParams->mcanConfigParams.txMsg[0U].txElem.xtd = 1U;
        MCAN_writeMsgRam(mcanBaseAddr,
                         testParams->mcanConfigParams.txMsg[0U].storageId,
                         txBufNum,
                         &testParams->mcanConfigParams.txMsg[0U].txElem);
        /* Add request for transmission */
        configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
        if (STW_SOK != configStatus)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
        {
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                MCAN_INTR_SRC_RX_FIFO0_NEW_MSG))
        {
        }
        if ((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO0_FULL) ==
                                MCAN_INTR_SRC_RX_FIFO0_FULL)
        {
            loopBreakFlag = 0U;
        }
        gMcanIsrIntr0Status = 0U;
        /* Checking for Errors */
        MCAN_getErrCounters(mcanBaseAddr, &errCounter);
        if ((0U == errCounter.recErrCnt) &&
            (0U == errCounter.canErrLogCnt))
        {
            MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
            /* Checking for Errors */
            if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                 (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                (0U == protStatus.pxe))
            {
            }
            else
            {
                testStatus += STW_EFAIL;
                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in transmission/reception(Iteration Count).\n");
                loopBreakFlag = 0U;
            }
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError Counters: Error in transmission/reception.\n");
            loopBreakFlag = 0U;
        }
    }
    fifoStatus.num = MCAN_RX_FIFO_NUM_0;
    MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
    if (fifoStatus.fifoFull == 1U)
    {
        getIdx = fifoStatus.getIdx;
        putIdx = fifoStatus.putIdx;
        loopCnt++;
        /* Send another message to cause overflow */
        /* Write message to Msg RAM-sending message with extended ID only */
        testParams->mcanConfigParams.txMsg[0U].txElem.id = loopCnt;
        testParams->mcanConfigParams.txMsg[0U].txElem.xtd = 1U;
        MCAN_writeMsgRam(mcanBaseAddr,
                         testParams->mcanConfigParams.txMsg[0U].storageId,
                         txBufNum,
                         &testParams->mcanConfigParams.txMsg[0U].txElem);
        /* Add request for transmission */
        configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
        if (STW_SOK != configStatus)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nError in Adding Transmission Request...\n", -1);
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) ==
                                MCAN_INTR_SRC_TRANS_COMPLETE))
        {
        }
        while (!((gMcanIsrIntr0Status & MCAN_INTR_SRC_RX_FIFO0_NEW_MSG) ==
                                MCAN_INTR_SRC_RX_FIFO0_NEW_MSG))
        {
        }
        gMcanIsrIntr0Status = 0U;
        /* get FIFO status, since FIFO is in Blocking mode, latest message will
         * lost and get/put index will not be updated */
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        if ((getIdx == (fifoStatus.getIdx - 1U)) && (putIdx == (fifoStatus.putIdx - 1U)))
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nGet and Put Indices are  updated after sending message after FIFO Full Condition.\n", -1);
        }
        /* Read first message in FIFO - this should be second oldest message(with EXT ID: 2) */
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        MCAN_readMsgRam(mcanBaseAddr,
                        MCAN_MEM_TYPE_FIFO,
                        fifoStatus.getIdx,
                        (uint32_t)fifoStatus.num,
                        &rxMsg);
        (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                   (uint32_t)fifoStatus.num,
                                   fifoStatus.getIdx);
        if (rxMsg.id == 2U)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nFirst message in the FIFO is second oldest message.\n", -1);
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nFirst message in the FIFO is not second oldest message.\n", -1);
        }
        MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        while (fifoStatus.fillLvl > 0U)
        {
            MCAN_readMsgRam(mcanBaseAddr,
                            MCAN_MEM_TYPE_FIFO,
                            fifoStatus.getIdx,
                            (uint32_t)fifoStatus.num,
                            &rxMsg);
            (void) MCAN_writeRxFIFOAck(mcanBaseAddr,
                                       (uint32_t)fifoStatus.num,
                                       fifoStatus.getIdx);
            MCAN_getRxFIFOStatus(mcanBaseAddr, &fifoStatus);
        }
        if (rxMsg.id == (fifoLength + 1U))
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nOldest message is overwritten, FIFO is in Overwriting Mode.\n", -1);
        }
        else
        {
            testStatus += STW_EFAIL;
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nOldest message is not overwritten, FIFO is not in Overwriting Mode.\n", -1);
        }
    }
    else
    {
        testStatus += STW_EFAIL;
    }
    /* FIFO Overwrite mode Test - End */

    return testStatus;
}

#if defined (SOC_AM65XX) || defined (SOC_J721E)
static void App_udmaStart(st_mcanTestcaseParams_t *testParams)
{
    int32_t         retVal;
    Udma_ChHandle   txChHandle = &gUdmaTxChObj;
    Udma_ChHandle   rxChHandle = &gUdmaRxChObj;
    Udma_ChPdmaPrms pdmaPrms;

    UdmaChPdmaPrms_init(&pdmaPrms);
    pdmaPrms.elemSize   = UDMA_PDMA_ES_8BITS;
    pdmaPrms.elemCnt    = (8U + (dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]));
    pdmaPrms.fifoCnt    = 0U;   /* Don't care for write */
    retVal = Udma_chConfigPdma(txChHandle, &pdmaPrms);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA TX PDMA config failed!!\n");
    }

    if(UDMA_SOK == retVal)
    {
        UdmaChPdmaPrms_init(&pdmaPrms);
        pdmaPrms.elemSize   = UDMA_PDMA_ES_8BITS;
        pdmaPrms.elemCnt    = (8U + (dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]));
        pdmaPrms.fifoCnt    = (testParams->mcanConfigParams.txMSGInterationCnt *
                               testParams->mcanConfigParams.txMsgNum);
        retVal = Udma_chConfigPdma(rxChHandle, &pdmaPrms);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA RX PDMA config failed!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(txChHandle);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA TX channel enable failed!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(rxChHandle);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA RX channel enable failed!!\n");
        }
    }

    return;
}

static void App_udmaStop(void)
{
    int32_t         retVal;
    Udma_ChHandle   txChHandle = &gUdmaTxChObj;
    Udma_ChHandle   rxChHandle = &gUdmaRxChObj;

    retVal = Udma_chDisable(txChHandle, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA TX channel disable failed!!\n");
    }

    retVal += Udma_chDisable(rxChHandle, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA RX channel disable failed!!\n");
    }

    return;
}

static void App_udmaInit(void)
{
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj;
    Udma_ChHandle   txChHandle = &gUdmaTxChObj;
    Udma_ChHandle   rxChHandle = &gUdmaRxChObj;
    int32_t         retVal;
    uint32_t        chType;
    Udma_InitPrms   initPrms;
    Udma_ChPrms     chPrms;
    Udma_ChTxPrms   txPrms;
    Udma_ChRxPrms   rxPrms;

    /* UDMA driver init */
    UdmaInitPrms_init(UDMA_INST_ID_MCU_0, &initPrms);
    initPrms.printFxn = &App_print;
    retVal = Udma_init(drvHandle, &initPrms);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA init failed!!\n");
    }

    if(UDMA_SOK == retVal)
    {
        /* Init Tx channel parameters */
        chType = UDMA_CH_TYPE_PDMA_TX;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.chNum                = UDMA_DMA_CH_ANY;
        chPrms.peerChNum            = UDMA_MCAN_PDMA_TX_CH_NUM;
        chPrms.fqRingPrms.ringMem   = &gTxRingMem[0U];
        chPrms.cqRingPrms.ringMem   = &gTxCompRingMem[0U];
        chPrms.fqRingPrms.elemCnt   = UDMA_MCAN_RING_ENTRIES;
        chPrms.cqRingPrms.elemCnt   = UDMA_MCAN_RING_ENTRIES;

        /* Open TX channel for transmit */
        retVal = Udma_chOpen(drvHandle, txChHandle, chType, &chPrms);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA TX channel open failed!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        UdmaChTxPrms_init(&txPrms, chType);
        retVal = Udma_chConfigTx(txChHandle, &txPrms);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA TX channel config failed!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Init Rx channel parameters */
        chType = UDMA_CH_TYPE_PDMA_RX;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.chNum                = UDMA_DMA_CH_ANY;
        chPrms.peerChNum            = UDMA_MCAN_PDMA_RX_CH_NUM;
        chPrms.fqRingPrms.ringMem   = &gRxRingMem[0U];
        chPrms.cqRingPrms.ringMem   = &gRxCompRingMem[0U];
        chPrms.fqRingPrms.elemCnt   = UDMA_MCAN_RING_ENTRIES;
        chPrms.cqRingPrms.elemCnt   = UDMA_MCAN_RING_ENTRIES;

        /* Open RX channel for transmit */
        retVal = Udma_chOpen(drvHandle, rxChHandle, chType, &chPrms);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA RX channel open failed!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        UdmaChRxPrms_init(&rxPrms, chType);
        retVal = Udma_chConfigRx(rxChHandle, &rxPrms);
        if(UDMA_SOK != retVal)
        {
            App_print("[Error] UDMA RX channel config failed!!\n");
        }
    }

    return;
}

static void App_udmaDeInit(void)
{
    int32_t         retVal;
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj;
    Udma_ChHandle   txChHandle = &gUdmaTxChObj;
    Udma_ChHandle   rxChHandle = &gUdmaRxChObj;

    retVal = Udma_chClose(txChHandle);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA TX channel close failed!!\n");
    }

    retVal = Udma_chClose(rxChHandle);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA RX channel close failed!!\n");
    }

    retVal += Udma_deinit(drvHandle);
    if(UDMA_SOK != retVal)
    {
        App_print("[Error] UDMA deinit failed!!\n");
    }

    return;
}

static void App_udmaTxHpdInit(uint8_t *pHpdMem, st_mcanTestcaseParams_t *testParams)
{
    CSL_UdmapCppi5HMPD *pHpd = (CSL_UdmapCppi5HMPD *) pHpdMem;
    uint32_t descType = (uint32_t)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
    uint32_t regVal;
    MCAN_TxBufElement elem = testParams->mcanConfigParams.txMsg[0U].txElem;
    uint32_t cqRingNum = Udma_chGetCqRingNum(&gUdmaTxChObj);

    /* Setup descriptor  - TODO */
    CSL_udmapCppi5SetDescType(pHpd, descType);
    CSL_udmapCppi5SetEpiDataPresent(pHpd, FALSE);
    CSL_udmapCppi5SetPsDataLoc(pHpd, 0U);
    CSL_udmapCppi5SetPsDataLen(pHpd, 0U);
    CSL_udmapCppi5SetPktLen(pHpd, descType, (8U + ((dataSize[elem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))));
    CSL_udmapCppi5SetPsFlags(pHpd, 0U);
    CSL_udmapCppi5SetIds(pHpd, descType, 0x321, 0x3FFFU);
    CSL_udmapCppi5SetSrcTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetDstTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetReturnPolicy(
        pHpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,   /* Don't care for TR */
        FALSE,                                                  /* Early return */
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);

    CSL_udmapCppi5LinkDesc(pHpd, 0U);

    CSL_udmapCppi5SetBufferAddr(pHpd, (uint32_t)&txBuffer[0]);
    CSL_udmapCppi5SetBufferLen(pHpd, (8U + ((dataSize[elem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))) );

    CSL_udmapCppi5SetOrgBufferAddr(pHpd, (uint32_t)&txBuffer[0]);
    CSL_udmapCppi5SetOrgBufferLen(pHpd, (8U + ((dataSize[elem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))));
    regVal = 0U;
    regVal |= (uint32_t)(elem.id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT);
    regVal |= (uint32_t)(elem.rtr << MCANSS_TX_BUFFER_ELEM_RTR_SHIFT);
    regVal |= (uint32_t)(elem.xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT);
    regVal |= (uint32_t)(elem.esi << MCANSS_TX_BUFFER_ELEM_ESI_SHIFT);
    // pCanHeader[0U] = regVal;
    HW_WR_REG32((uint32_t)&txBuffer[0], regVal);

    regVal = 0U;
    regVal |= (uint32_t)(elem.dlc << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT);
    regVal |= (uint32_t)(elem.brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT);
    regVal |= (uint32_t)(elem.fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT);
    regVal |= (uint32_t)(elem.efc << MCANSS_TX_BUFFER_ELEM_EFC_SHIFT);
    regVal |= (uint32_t)(elem.mm << MCANSS_TX_BUFFER_ELEM_MM_SHIFT);
    // pCanHeader[1U] = regVal;
    HW_WR_REG32((uint32_t)&txBuffer[0] + 0x4, regVal);

    /* Writeback cache */
    Udma_appUtilsCacheWb(pHpdMem, UDMA_MCAN_HPD_SIZE);

    return;
}

static void App_udmaRxHpdInit(uint8_t *pHpdMem, st_mcanTestcaseParams_t *testParams)
{
    CSL_UdmapCppi5HMPD *pHpd = (CSL_UdmapCppi5HMPD *) pHpdMem;
    uint32_t descType = (uint32_t)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
    uint32_t cqRingNum = Udma_chGetCqRingNum(&gUdmaRxChObj);

    /* Setup descriptor  - TODO */
    CSL_udmapCppi5SetDescType(pHpd, descType);
    CSL_udmapCppi5SetEpiDataPresent(pHpd, FALSE);
    CSL_udmapCppi5SetPsDataLoc(pHpd, 0U);
    CSL_udmapCppi5SetPsDataLen(pHpd, 0U);
    CSL_udmapCppi5SetPktLen(pHpd, descType, (8U + ((dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))));
    CSL_udmapCppi5SetPsFlags(pHpd, 0U);
    CSL_udmapCppi5SetIds(pHpd, descType, 0x321, 0x3FFFU);
    CSL_udmapCppi5SetSrcTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetDstTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetReturnPolicy(
        pHpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,   /* Don't care for TR */
        FALSE,                                                  /* Early return */
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);

    CSL_udmapCppi5LinkDesc(pHpd, 0U);

    CSL_udmapCppi5SetBufferAddr(pHpd, (uint32_t)&rxBuffer[0]);
    CSL_udmapCppi5SetBufferLen(pHpd, (8U + ((dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))));

    CSL_udmapCppi5SetOrgBufferAddr(pHpd, (uint32_t)&rxBuffer[0]);
    CSL_udmapCppi5SetOrgBufferLen(pHpd, (8U + ((dataSize[testParams->mcanConfigParams.txMsg[0U].txElem.dlc]) * (testParams->mcanConfigParams.txMSGInterationCnt *
                      testParams->mcanConfigParams.txMsgNum))));
    /* Writeback cache */
    Udma_appUtilsCacheWb(pHpdMem, UDMA_MCAN_HPD_SIZE);

    return;
}

static void App_print(const char *str)
{
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, str, -1);

    return;
}

#endif

#if 0
#if defined (SOC_J721E)
int32_t App_mcanGatewayTest(st_mcanTestcaseParams_t *testParams)
{
    int32_t  configStatus = STW_SOK, testStatus = STW_SOK;
    uint32_t loopCnt      = 0U, iterationCnt = 0U, txBufNum;
    uint32_t firstMsg = 1U, ackMsg, msgReqAdded;
    MCAN_ProtocolStatus protStatus;
    MCAN_ErrCntStatus    errCounter;
    MCAN_RxBufElement rxMsg;
    MCAN_TxFIFOStatus txFIFOStatus;
    uint64_t ts1, ts2;

    App_CounterConfig();
    App_ConfigCounterSuspendState();
    /* Configure MCAN Modules */
    for (loopCnt = 0U ;
         loopCnt < APP_MCAN_MODULE_NUM ;
         loopCnt++)
    {
        configStatus += App_mcanConfig(&mcanModuleBaseAddr[loopCnt], testParams);
        if (STW_SOK != configStatus)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                              uartBaseAddr,
                              "\nError in MCAN Configuration...");
            break;
        }
        /* Enable Interrupts */
        MCAN_enableIntr(&mcanModuleBaseAddr[loopCnt], testParams->mcanConfigParams.intrEnable, (uint32_t)TRUE);
        /* Select Interrupt Line */
        MCAN_selectIntrLine(&mcanModuleBaseAddr[loopCnt],
                            testParams->mcanConfigParams.intrLineSelectMask,
                            testParams->mcanConfigParams.intrLine);
        /* Enable Interrupt Line */
        MCAN_enableIntrLine(&mcanModuleBaseAddr[loopCnt],
                            testParams->mcanConfigParams.intrLine,
                            1U);
        /* Enable interrupts for Tx Buffers */
        for (msgCnt = 0U ;
             msgCnt < testParams->mcanConfigParams.txMsgNum ;
             msgCnt++)
        {
            if (testParams->mcanConfigParams.txMsg[msgCnt].storageId ==
                                                            MCAN_MEM_TYPE_BUF)
            {
                /* Enable Transmission interrupt */
                configStatus += MCAN_txBufTransIntrEnable(
                        &mcanModuleBaseAddr[loopCnt],
                        testParams->mcanConfigParams.txMsg[msgCnt].bufferNum,
                        (uint32_t)TRUE);
                if(configStatus != STW_SOK)
                {
                    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx Buffer Interrupt Enable FAILED...\n", -1);
                }
            }
        }
        /* Enable interrupts for Tx FIFO/Queue */
        for (msgCnt = testParams->mcanConfigParams.ramConfig->txBufNum ;
             msgCnt < (testParams->mcanConfigParams.ramConfig->txFIFOSize +
                        testParams->mcanConfigParams.ramConfig->txBufNum);
             msgCnt++)
        {
            /* Enable Transmission interrupt */
            configStatus += MCAN_txBufTransIntrEnable(
                    &mcanModuleBaseAddr[loopCnt],
                    msgCnt,
                    (uint32_t)TRUE);
            if(configStatus != STW_SOK)
            {
                App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nMCAN Tx FIFO Interrupt Enable FAILED...\n", -1);
            }
        }
    }

    gMcanIsrTxDoneStatus = 0U;
    gMcanIsrRxDoneStatus = 0U;
    /* Since only one message can be sent */
    iterationCnt = 0U;
    msgCnt = 0U;
    rxMsgCnt = 0U;
    ackMsg = 0U;
    msgReqAdded = 0U;
    for (loopCnt = 0U ;
         loopCnt < APP_MCAN_MODULE_NUM ;
         loopCnt++)
    {
        msgSent[loopCnt] = 0U;
        msgRcvd[loopCnt] = 0U;

    }

    App_GetCounterValue(&ts1);
    while (ackMsg
                < (testParams->mcanConfigParams.txMSGInterationCnt * APP_MCAN_MODULE_NUM))
    {
        for (loopCnt = 0U ;
             loopCnt < APP_MCAN_MODULE_NUM ;
             loopCnt++)
        {
            mcanBaseAddr = &mcanModuleBaseAddr[loopCnt];
            if ((firstMsg == 1U) ||
                (((gMcanIsrRxDoneStatus >> loopCnt) & 0x1U) == 1U))
            {
                gMcanIsrRxDoneStatus &= (~(1U << loopCnt));
                gMcanIsrIntr0Flag = 1U;
                if ((firstMsg != 1U))
                {
                    ackMsg++;
#if (APP_ENABLE_PROFILING)
                    gEvent[gTSIndex] = APP_EVENT_ACK_MSG_START;
                    App_GetCounterValue(&gTimeStamp[gTSIndex++]);
#endif
                    /* Read previous message */
                    /* Checking for Errors */
                    MCAN_getErrCounters(mcanBaseAddr, &errCounter);
                    if ((0U == errCounter.recErrCnt) &&
                        (0U == errCounter.canErrLogCnt))
                    {
                        MCAN_getProtocolStatus(mcanBaseAddr, &protStatus);
                        /* Checking for Errors */
                        if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
                             (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
                            ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
                             (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
                            (0U == protStatus.pxe))
                        {
                            configStatus += App_mcanReadRxMSG(&rxMsg, MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG);
                            if(configStatus != STW_SOK)
                            {
                                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                uartBaseAddr,
                                "\n0x%x:Unable to read received message(Message Number): (%d).\n",
                                &mcanBaseAddr->mcanCoreRegs->CREL,
                                rxMsgCnt);
                            }
                            configStatus += App_mcanTxRxMessageCheck(
                                            testParams->mcanConfigParams.txMsg[iterationCnt].txElem,
                                            rxMsg);
                            /* Check if Message is stored into appropriate Rx Buffer */
                            // if(testParams->mcanConfigParams.txMsg[iterationCnt].rxMSGStorageId == MCAN_MEM_TYPE_BUF)
                            // {
                                // if(rxBuffNum != testParams->mcanConfigParams.txMsg[iterationCnt].rxBuffNum)
                                // {
                                   // testStatus += STW_EFAIL;
                                   // break;
                                // }
                            // }
                            if(configStatus != STW_SOK)
                            {
                                testStatus += STW_EFAIL;
                                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                    uartBaseAddr,
                                    "\n0x%x:Transmitted and received message does not match(Message Number): (%d).\n",
                                    &mcanBaseAddr->mcanCoreRegs->CREL,
                                    ackMsg);
                                break;
                            }
                            else
                            {
                                testStatus += STW_SOK;
#if !(APP_ENABLE_PROFILING)
                                App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                    uartBaseAddr,
                                    "\n0x%x:Message successfully transferred/received (Message Number): (%d).\n",
                                    &mcanBaseAddr->mcanCoreRegs->CREL,
                                    ackMsg);
#endif
                            }
                        }
                        else
                        {
                            testStatus += STW_EFAIL;
                            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                    uartBaseAddr,
                                    "\n0x%x:Error in transmission/reception (Message Number): (%d).\n",
                                    &mcanBaseAddr->mcanCoreRegs->CREL,
                                    ackMsg);
                            break;
                        }
                    }
                    else
                    {
                        testStatus += STW_EFAIL;
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                    uartBaseAddr,
                                    "\n0x%x:Error Counters: Error in transmission/reception (Module:Message Number): (%d,%d).\n",
                                    &mcanBaseAddr->mcanCoreRegs->CREL,
                                    loopCnt,
                                    ackMsg);
                        break;
                    }
#if (APP_ENABLE_PROFILING)
                    gEvent[gTSIndex] = APP_EVENT_ACK_MSG_END;
                    App_GetCounterValue(&gTimeStamp[gTSIndex++]);
#endif
                }
                if (msgReqAdded <
                    (testParams->mcanConfigParams.txMSGInterationCnt * APP_MCAN_MODULE_NUM))
                {
                    msgReqAdded++;
#if (APP_ENABLE_PROFILING)
                    gEvent[gTSIndex] = APP_EVENT_WRITE_START;
                    App_GetCounterValue(&gTimeStamp[gTSIndex++]);
#endif
                    if (testParams->mcanConfigParams.txMsg[iterationCnt].storageId ==
                                                                MCAN_MEM_TYPE_BUF)
                    {
                        txBufNum = testParams->mcanConfigParams.txMsg[iterationCnt].bufferNum;
                    }
                    else
                    {
                        MCAN_getTxFIFOQueStatus(mcanBaseAddr, &txFIFOStatus);
                        txBufNum = txFIFOStatus.putIdx;
                    }
                    // App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nSending Message with following details:\n");
                    // App_mcanPrintTxMsg(&testParams->mcanConfigParams.txMsg[iterationCnt].txElem);
                    /* Write message to Msg RAM */
                    MCAN_writeMsgRam(mcanBaseAddr,
                                     testParams->mcanConfigParams.txMsg[iterationCnt].storageId,
                                     txBufNum,
                                     &testParams->mcanConfigParams.txMsg[iterationCnt].txElem);
                    /* Add request for transmission */
                    configStatus += MCAN_txBufAddReq(mcanBaseAddr, txBufNum);
                    if (STW_SOK != configStatus)
                    {
                        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
                                       uartBaseAddr,
                                       "\n0x%x:Error in Adding Transmission Request...\n",
                                       &mcanBaseAddr->mcanCoreRegs->CREL);
                    }
#if (APP_ENABLE_PROFILING)
                    gEvent[gTSIndex] = APP_EVENT_WRITE_END;
                    App_GetCounterValue(&gTimeStamp[gTSIndex++]);
#endif
                }

                gMcanIsrIntr0Status = 0U;
            }
        }
        firstMsg = 0U;
         if (STW_SOK != configStatus)
         {
             break;
         }
    }
    App_GetCounterValue(&ts2);
    printf("\nTime:(%lld,%lld)\n", ts1, ts2);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
           uartBaseAddr,
           "\nMessage Details(Sent,Received,Total):(%d,%d,%d) \n",
           msgCnt,
           ackMsg,
           (testParams->mcanConfigParams.txMSGInterationCnt * APP_MCAN_MODULE_NUM));
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
           uartBaseAddr,
           "Message sent per module(Module, Messages Sent, Messages Received)... \n");
    for (loopCnt = 0U ;
         loopCnt < APP_MCAN_MODULE_NUM ;
         loopCnt++)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
           uartBaseAddr,
           "(0x%x, %d, %d) \n",
           &mcanModuleBaseAddr[loopCnt].mcanCoreRegs->CREL,
           msgSent[loopCnt],
           msgRcvd[loopCnt]);
    }
#if (APP_ENABLE_PROFILING)
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
           uartBaseAddr,
           "Profiling Points(Event, Time)... \n");
    for (loopCnt = 0U ;
         loopCnt < gTSIndex ;
         loopCnt++)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS,
           uartBaseAddr,
           "(%d, %lld) \n",
           gEvent[loopCnt],
           gTimeStamp[loopCnt]);
    }
#endif

    return testStatus;
}
#endif
#endif
