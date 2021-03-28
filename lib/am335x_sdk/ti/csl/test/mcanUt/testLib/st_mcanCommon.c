/*
 *  Copyright (C) 2014 Texas Instruments Incorporated
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
 *  \file st_mcanCommon.c
 *
 *  \brief Common code that can be shared across test case files.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_mcan.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/csl_mcan.h>
#include <ti/csl/csl_intr_router.h>
#include <st_mcan.h>
#include <utils_prf.h>
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
#include <ti/csl/cslr_synctimer.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#endif
#if defined (SOC_AM65XX)
#include <ti/drv/uart/UART_stdio.h>
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
#include <ti/osal/osal.h>
#endif

#if defined (SOC_J721E)
#include <ti/drv/sciclient/sciclient.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#if defined (SOC_TDA2PX)
    #define APP_MCAN_INT0_M4                                  (78U)
    #define APP_MCAN_INT1_M4                                  (79U)
    #define APP_MCAN_ECC_INT_M4                               (75U)
    #define APP_MCAN_TS_INT_M4                                (72U)
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    #define APP_MCAN_INT0_M4                                  (34U)
    #define APP_MCAN_INT1_M4                                  (35U)
    #define APP_MCAN_ECC_INT_M4                               (36U)
    /* MCAN TS interrupt only goes to IPU 79 Cross bar */
    #define APP_MCAN_TS_INT_M4                                (79U)
#endif

#if defined (SOC_J721E)
#if defined (BUILD_MCU1_0)
#define APP_MAIN_PULSAR0_INTROUTER0_NUM_IN_INTR     (312)
#define APP_MAIN_PULSAR0_INTROUTER0_NUM_OUT_INTR    (64)
#else
#define APP_MAIN_PULSAR0_INTROUTER0_NUM_IN_INTR     (432)
#define APP_MAIN_PULSAR0_INTROUTER0_NUM_OUT_INTR    (256)
#endif
#endif

#ifdef __TI_ARM_V7M4__
    #define APP_MCAN_INT0                     (APP_MCAN_INT0_M4)
    #define APP_MCAN_INT1                     (APP_MCAN_INT1_M4)
    #define APP_MCAN_ECC_INT                  (APP_MCAN_ECC_INT_M4)
    #define APP_MCAN_TS_INT                   (APP_MCAN_TS_INT_M4)
    #define XBAR_CPU                          (CSL_XBAR_IRQ_CPU_ID_IPU1)
    #define XBAR_MCAN_INT0                       (CSL_XBAR_INST_IPU1_IRQ_34)
    #define XBAR_MCAN_INT1                       (CSL_XBAR_INST_IPU1_IRQ_35)
    #define XBAR_MCAN_ECC                        (CSL_XBAR_INST_IPU1_IRQ_36)
    #define XBAR_MCAN_TS                         (CSL_XBAR_INST_IPU1_IRQ_79)
    #define XBAR_INTR0_SOURCE                    (CSL_XBAR_MCAN_IRQ_INT0)
    #define XBAR_INTR1_SOURCE                    (CSL_XBAR_MCAN_IRQ_INT1)
    #define XBAR_INTR_ECC_SOURCE                 (CSL_XBAR_MCAN_IRQ_PARITY)
    #define XBAR_INTR_TS_SOURCE                  (CSL_XBAR_MCAN_IRQ_TS)
#elif defined (_TMS320C6X)
#endif

/** brief 32K Timer frequency */
#define APP_32K_TIMER_FREQ        (32000U)
/** brief Overflow count value for 32bit counter */
#define APP_COUNTER_MAX_COUNT     (0xFFFFFFFFU)
/** \brief Offset of DRM SUSPEND_CTRL31 register */
#define DRM_SUSPEND_CTRL31                 (0x27CU)
/** \brief DRM_SUSPEND_CTRL31 is mapped to COUNTER_32K Suspend Output line */
#define DRM_SUSPEND_CTRL_COUNTER_32K       (SOC_I_DRM_BASE + DRM_SUSPEND_CTRL31)
/** \brief DRM SUSPEND Source as M4 */
#define DRM_SUSPEND_SRC_IPU_C0             (0x3U)

/* Below macros are taken from mcan.c and are only needed for testing purpose */
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

/**
 * \brief  Mask and shift for Rx Buffers elements.
 */
#define MCANSS_RX_BUFFER_ELEM_ID_SHIFT                           (0U)
#define MCANSS_RX_BUFFER_ELEM_ID_MASK                            (0x1FFFFFFFU)
#define MCANSS_RX_BUFFER_ELEM_RTR_SHIFT                          (29U)
#define MCANSS_RX_BUFFER_ELEM_RTR_MASK                           (0x20000000U)
#define MCANSS_RX_BUFFER_ELEM_XTD_SHIFT                          (30U)
#define MCANSS_RX_BUFFER_ELEM_XTD_MASK                           (0x40000000U)
#define MCANSS_RX_BUFFER_ELEM_ESI_SHIFT                          (31U)
#define MCANSS_RX_BUFFER_ELEM_ESI_MASK                           (0x80000000U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT                         (0U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_MASK                          (0x0000FFFFU)
#define MCANSS_RX_BUFFER_ELEM_DLC_SHIFT                          (16U)
#define MCANSS_RX_BUFFER_ELEM_DLC_MASK                           (0x000F0000U)
#define MCANSS_RX_BUFFER_ELEM_BRS_SHIFT                          (20U)
#define MCANSS_RX_BUFFER_ELEM_BRS_MASK                           (0x00100000U)
#define MCANSS_RX_BUFFER_ELEM_FDF_SHIFT                          (21U)
#define MCANSS_RX_BUFFER_ELEM_FDF_MASK                           (0x00200000U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT                         (24U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_MASK                          (0x7F000000U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT                         (31U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_MASK                          (0x80000000U)

/**
 * \brief  Mask and shift for Standard Message ID Filter Elements.
 */
#define MCANSS_STD_ID_FILTER_SFID2_SHIFT                         (0U)
#define MCANSS_STD_ID_FILTER_SFID2_MASK                          (0x000003FFU)
#define MCANSS_STD_ID_FILTER_SFID1_SHIFT                         (16U)
#define MCANSS_STD_ID_FILTER_SFID1_MASK                          (0x03FF0000U)
#define MCANSS_STD_ID_FILTER_SFEC_SHIFT                          (27U)
#define MCANSS_STD_ID_FILTER_SFEC_MASK                           (0x38000000U)
#define MCANSS_STD_ID_FILTER_SFT_SHIFT                           (30U)
#define MCANSS_STD_ID_FILTER_SFT_MASK                            (0xC0000000U)

/**
 * \brief  Extended Message ID Filter Element.
 */
#define MCANSS_EXT_ID_FILTER_EFID2_SHIFT                        (0U)
#define MCANSS_EXT_ID_FILTER_EFID2_MASK                         (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFID1_SHIFT                        (0U)
#define MCANSS_EXT_ID_FILTER_EFID1_MASK                         (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFEC_SHIFT                         (29U)
#define MCANSS_EXT_ID_FILTER_EFEC_MASK                          (0xE0000000U)
#define MCANSS_EXT_ID_FILTER_EFT_SHIFT                          (30U)
#define MCANSS_EXT_ID_FILTER_EFT_MASK                           (0xC0000000U)

/**
 * \brief  Mask and shift for Tx Event FIFO elements.
 */
#define MCANSS_TX_EVENT_FIFO_ELEM_ID_SHIFT                      (0U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ID_MASK                       (0x1FFFFFFFU)
#define MCANSS_TX_EVENT_FIFO_ELEM_RTR_SHIFT                     (29U)
#define MCANSS_TX_EVENT_FIFO_ELEM_RTR_MASK                      (0x20000000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_XTD_SHIFT                     (30U)
#define MCANSS_TX_EVENT_FIFO_ELEM_XTD_MASK                      (0x40000000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ESI_SHIFT                     (31U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ESI_MASK                      (0x80000000U)

#define MCANSS_TX_EVENT_FIFO_ELEM_TXTS_SHIFT                    (0U)
#define MCANSS_TX_EVENT_FIFO_ELEM_TXTS_MASK                     (0x0000FFFFU)
#define MCANSS_TX_EVENT_FIFO_ELEM_DLC_SHIFT                     (16U)
#define MCANSS_TX_EVENT_FIFO_ELEM_DLC_MASK                      (0x000F0000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_BRS_SHIFT                     (20U)
#define MCANSS_TX_EVENT_FIFO_ELEM_BRS_MASK                      (0x00100000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_FDF_SHIFT                     (21U)
#define MCANSS_TX_EVENT_FIFO_ELEM_FDF_MASK                      (0x00200000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ET_SHIFT                      (22U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ET_MASK                       (0x00C00000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_MM_SHIFT                      (24U)
#define MCANSS_TX_EVENT_FIFO_ELEM_MM_MASK                       (0xFF000000U)

/* Print buffer character limit for prints- UART or CCS Console */
#define APP_PRINT_BUFFER_SIZE                       (4000)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API to enable the clock and PAD config for mcan module.
 *
 * \retval  status          configuration status.
 */
int32_t mcanClockEnableandPADConfig(void);

/**
 * \brief   This API is used to introduce error.
 *
 * \param   testParams        structure to details of testcase to run.
 *
 * \retvsl  status            Run status
 */
int32_t mcanTestFunc(st_mcanTestcaseParams_t *testParams);

/**
 * \brief   This API will MCAN Rx Msg.
 *
 * \param   rxMsg           received message object.
 *
 * \retval  none.
 */
void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg);

/**
 * \brief   This API will MCAN Tx Msg.
 *
 * \param   txMsg           message object to be transmitted.
 *
 * \retval  none.
 */
void App_mcanPrintTxMsg(const MCAN_TxBufElement *txMsg);

/**
 * \brief   This function will configure X-BAR for MCAN interrupts
 *
 * \param   none.
 *
 * \retval  status      configuration status.
 */
int32_t App_mcanRegisterInterrupt(uint32_t modIdx);
int32_t App_mcanUnRegisterInterrupt(uint32_t modIdx);

/**
 * \brief   This is Interrupt Service Routine for MCAN interrupt 0.
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_mcanIntr0ISR(uintptr_t handle);

/**
 * \brief   This is Interrupt Service Routine for MCAN interrupt 1.
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_mcanIntr1ISR(uintptr_t handle);

/**
 * \brief   This is Interrupt Service Routine for MCAN ECC interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_mcanECCIntrISR(void *handle);

/**
 * \brief   This is Interrupt Service Routine for MCAN TimeStamp interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_mcanTSIntrISR(uintptr_t handle);

/**
 * \brief   This API will index of the current bit timing configuration within
 *          'canFDBitTimings'.
 *
 * \param   rxMsg           received message object.
 *
 * \retval  index           Array index within 'canFDBitTimings'.
 *                          Return 0xFFFFFFFF if not found.
 */
uint32_t App_getBitConfigParamId(const MCAN_BitTimingParams *bitTimings);

/**
 * \brief   This function used to enable Counter use for timebase measurement.
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_CounterConfig(void);

/**
 * \brief   This function used to put 32k Counter into free run mode
 *
 * \param   none.
 *
 * \retval  none.
 */
void App_ConfigCounterSuspendState(void);

/**
 * \brief   This function used to insert delays
 *
 * \param   timeout         Delay value in ms.
 *
 * \retval  none.
 */
void App_delayFunc(uint32_t timeout);

/**
 * \brief   This function used to get current time value in clock ticks
 *
 * \param   value           Read COunter value from register.
 *
 * \retval  none.
 */
void App_GetCounterValue(uint64_t *value);

/**
 * \brief   This function used to insert delays
 *
 * \param   value           Initial Value.
 * \param   elapsedValue    Number of clock ticks since 'value'.
 *
 * \retval  none.
 */
void App_GetElapsedValue(uint64_t  value, uint64_t *elapsedValue);

void App_ConsolePrintf(uint32_t type, uint32_t baseAddr, const char *pcString, ...);

int32_t App_ConsoleGetNum(uint32_t baseAddr);

uint8_t App_ConsoleGetc(uint32_t baseAddr);

void App_ConsoleInit(uint32_t baseAddr, uint32_t baudRate, uint32_t wordLength,
                    uint32_t stopBit, uint32_t parity, uint32_t mode);

uint32_t App_ConsolePuts(uint32_t type, uint32_t baseAddr, const char *pTxBuffer,
                        int32_t numBytesToWrite);

/**
 * \brief   This function used to insert delays
 *
 * \param   value           Initial Value.
 * \param   elapsedValue    Number of clock ticks since 'value'.
 *
 * \retval  none.
 */
void App_mcanGetIntStatus(uint32_t baseAddr);

/**
 * \brief   This API will write the message object to Message RAM.
 *
 * \param   baseAddr        Base Address of the MCAN Registers.
 * \param   elemAddr        Address of the message object.
 * \param   elem            Message Object.
 *                          Refer struct #MCAN_TxBufElement.
 *
 * \return  None.
 */
void App_mcanWriteMsg(uint32_t                 baseAddr,
                      uint32_t                 elemAddr,
                      const MCAN_TxBufElement *elem);

/**
 * \brief   This API will read the message object from Message RAM.
 *
 * \param   baseAddr        Base Address of the MCAN Registers.
 * \param   elemAddr        Address of the message object.
 * \param   elem            Message Object.
 *                          Refer struct #MCAN_RxBufElement.
 *
 * \return  None.
 */
void App_mcanReadMsg(uint32_t           baseAddr,
                     uint32_t           elemAddr,
                     MCAN_RxBufElement *elem);

/**
 * \brief   This API will return payload depending on 'dlc'  field.
 *
 * \param   dlc             Data Length Code.
 *
 * \return  data size       Size of the payload.
 */
uint32_t App_mcangetMsgObjSize(uint32_t elemSize);

/**
 * \brief   This API will return message object size.
 *
 * \param   dlc             Data Length Code.
 *
 * \return  message object size
 *                          Size of the message object stored in Message RAM.
 */
uint32_t App_mcanGetDataSize(uint32_t dlc);

#if defined (SOC_AM65XX) || defined (SOC_J721E)
static int32_t App_mcanRegIntrInternal(HwiP_Handle *hwiHandle, uint32_t intNum, void f(uintptr_t));
#endif
#if 0
#if defined (SOC_J721E) && defined (BUILD_MCU1_0)
static int32_t App_mcanConfigureIrqRouter(uint32_t devId, uint32_t offset, uint32_t intNum);
#endif
#endif
static int32_t App_mcanConfigureIrqRouter (uint32_t inputIntrNum, uint32_t outputIntrNum);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint32_t          mcanBaseAddr = DEF_MCAN_MODULE;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
extern uint32_t                uartBaseAddr;
#elif defined (SOC_AM65XX) || defined (SOC_J721E)
uint32_t                uartBaseAddr;
#endif

uint32_t          gMcanAppdataSize[16] =
{0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
volatile uint32_t gMcanIsrIntr0Flag = 1U;
volatile uint32_t gMcanIsrIntr1Flag = 1U;
volatile uint32_t gMcanECCIntrFlag = 1U;
volatile uint32_t gMcanIsrIntr0Status = 0U;
volatile uint32_t gMcanIsrIntr1Status = 0U;
volatile uint32_t gMcanExtTSIntrFlag = 1U;
MCAN_ECCErrStatus gMcaneccErr;
extern MCAN_BitTimingParams canFDBitTimings[];
extern uint32_t bitTimingsListSize;
extern volatile uint32_t isrPrintEnable;

#if defined (SOC_AM65XX)
st_mcanModuleInfo gMcanModInfo[] =
{
    {
        .mcanModuleBaseAddr = CSL_MCU_MCAN0_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MCU_MCAN0",
        .mcanInt0IntNum = CSL_MCU0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSL_MCU0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSL_MCU0_INTR_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCU_MCAN1_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MCU_MCAN1",
        .mcanInt0IntNum = CSL_MCU0_INTR_MCAN1_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSL_MCU0_INTR_MCAN1_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSL_MCU0_INTR_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
};
#endif

#if defined (SOC_J721E)
st_mcanModuleInfo gMcanModInfo[] =
{
    {
        .mcanModuleBaseAddr = CSL_MCU_MCAN0_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MCU_MCAN0",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #else
        .mcanInt0IntNum = CSLR_R5FSS0_CORE1_INTR_R5FSS0_INTROUTER0_OUTL_0,
        .mcanInt1IntNum = CSLR_R5FSS0_CORE1_INTR_R5FSS0_INTROUTER0_OUTL_1,
        .mcanTsIntNum   = CSLR_R5FSS0_CORE1_INTR_R5FSS0_INTROUTER0_OUTL_2,
        .mcanInt0IrqRouterInpNum = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN0_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN0_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCU_MCAN1_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MCU_MCAN1",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_R5FSS1_INTROUTER0_OUTL_3,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_R5FSS1_INTROUTER0_OUTL_4,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_R5FSS1_INTROUTER0_OUTL_5,
        .mcanInt0IrqRouterInpNum = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN1_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN1_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_R5FSS1_INTROUTER0_IN_MCU_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN0_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN0",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_1,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_2,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN0_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN0_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN1_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN1 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_3,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_4,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_5,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN1_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN1_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN2_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN2",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_6,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_7,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_8,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN2_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN2_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN3_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN3 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN3_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN3_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN3_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN4_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN4  (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN4_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN4_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN4_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN5_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN5  (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN5_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN5_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN5_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN6_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN6  (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN6_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN6_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN7_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN7  (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN7_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN7_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN8_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN8 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN8_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN8_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN8_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN9_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN9  (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN9_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN9_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN10_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN10 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN10_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN10_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN10_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN11_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN11 (GESI Exp Board)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN11_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN11_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN12_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN12 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN12_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN12_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN12_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
    {
        .mcanModuleBaseAddr = CSL_MCAN13_MSGMEM_RAM_BASE,
        .mcanModDesc    = "MAIN_MCAN13 (Internal Loopback Only)",
    #if defined (BUILD_MCU1_0)
        .mcanInt0IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_9,
        .mcanInt1IntNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_10,
        .mcanTsIntNum   = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_11,
        .mcanInt0IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IrqRouterInpNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIrqRouterInpNum   = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
    #else
        .mcanInt0IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN13_MCANSS_MCAN_LVL_INT_0,
        .mcanInt1IntNum = CSLR_R5FSS1_CORE1_INTR_MCAN13_MCANSS_MCAN_LVL_INT_1,
        .mcanTsIntNum   = CSLR_R5FSS1_CORE1_INTR_MCAN13_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
        .mcanInt0IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanInt1IrqRouterInpNum = IRQ_ROUTER_CFG_NOT_REQUIRED,
        .mcanTsIrqRouterInpNum   = IRQ_ROUTER_CFG_NOT_REQUIRED,
    #endif
        .mcanInt0HwiHandle       = NULL,
        .mcanInt1HwiHandle       = NULL,
        .mcanTsHwiHandle         = NULL,
    },
};
#endif

uint32_t    gMcanNumInst = sizeof(gMcanModInfo)/sizeof(gMcanModInfo[0]);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t mcanClockEnableandPADConfig(void)
{
    int32_t status = STW_SOK;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    uint32_t siliconRev;
    /* Configure I/O PAD */
    /* PlatformUnlockMMR();*/
    /*Pad configurations - MCAN */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_RXD,
                0x0006000C);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_TXD,
                0x0004000C);

    siliconRev = CSL_getSocSiliconRev();
    if (2U > siliconRev)
    {
        App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr,
            "\r\nMCAN Evm/B2B Loopback is not supported for Tda3xx PG1.0 Silicon",
            -1);
    }
    /* Configure MCAN io clock */
    if (PM_SUCCESS == PMLIBClkRateSet(PMHAL_PRCM_MOD_MCAN,
                                      PMHAL_PRCM_CLK_MCAN_CLK,
                                      80000000U))
    {
        status = STW_SOK;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "MCAN Clock Configuration Successful.\n");
        status = PMHALModuleModeSet(PMHAL_PRCM_MOD_MCAN,
                                          PMHAL_PRCM_MODULE_MODE_ENABLED,
                                          PM_TIMEOUT_INFINITE);

        if (PM_SUCCESS != status)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Error in MCAN module enable.\n");
            status = STW_EFAIL;
        }
        else
        {
            status = STW_SOK;
        }
    }
    else
    {
        status = STW_EFAIL;
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Error in MCAN Clock Configuration.\n");
    }

#elif defined (SOC_TDA2PX)
    uint32_t                   postDivider;
    /*Pad configurations- UART  */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00000000);
    /*Pad configurations - MCAN */
    /* Configure mcan_tx, mcan_rx pads on dcan1_tx and dcan1_rx pads */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE+CTRL_CORE_CONTROL_SPARE_RW,
        CTRL_CORE_CONTROL_SPARE_RW_SEL_ALT_MCAN,
        CTRL_CORE_CONTROL_SPARE_RW_SEL_ALT_MCAN_MCAN_DCAN1_PADS);

    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_TX,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_RX,0x00040000);

    /* Enable MCAN clock. */
    HW_WR_FIELD32(SOC_WKUPAON_CM_BASE+CM_WKUPAON_ADC_CLKCTRL,
        CM_WKUPAON_ADC_CLKCTRL_MODULEMODE,
        CM_WKUPAON_ADC_CLKCTRL_MODULEMODE_ENABLE);
    while (CM_WKUPAON_ADC_CLKCTRL_IDLEST_FUNC !=
                HW_RD_FIELD32(SOC_WKUPAON_CM_BASE+CM_WKUPAON_ADC_CLKCTRL,
                CM_WKUPAON_ADC_CLKCTRL_IDLEST))
    {
        /* wait for module to be enabled */
    }
    postDivider = 24U;
    /* Set the postDividers reg */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_HSDIV,
                  postDivider);
    /* Select the mux value */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_TENABLEDIV,
                  1U);
    /* Select the Toggle sequence 010 */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_HSDIV_LATCH_EN,
                  0U);
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_HSDIV_LATCH_EN,
                  1U);
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_HSDIV_LATCH_EN,
                  0U);
    /* Enable the HSDIV post div clock */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE+CTRL_CORE_SMA_SW_0,
                  CTRL_CORE_SMA_SW_0_MCAN_CLK_HSDIV_EN,
                  1U);
#endif

#endif
    return status;
}

int32_t mcanTestFunc(st_mcanTestcaseParams_t *testParams)
{
    int32_t           status = STW_SOK;

    return status;
}

void App_mcanPrintTxMsg(const MCAN_TxBufElement *txMsg)
{
    uint32_t loopCnt;

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage ID: 0x%x", txMsg->id);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Remote Transmission Request: 0x%x", txMsg->rtr);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID): 0x%x",
               txMsg->xtd);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr,
        "\nMessage Error State Indicator(0:Error Active/1:Error Passive): 0x%x",
        txMsg->esi);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Data Length Code: 0x%x", txMsg->dlc);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage BRS: 0x%x", txMsg->brs);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage CAN FD format: 0x%x", txMsg->fdf);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Store Tx Events: 0x%x", txMsg->efc);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Marker: 0x%x", txMsg->mm);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Data(byte no:byte data):\n");
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "{", -1);
    for (loopCnt = 0U; loopCnt < gMcanAppdataSize[txMsg->dlc]; loopCnt++)
    {
        if((loopCnt % 8) == 0U)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\n", -1);
        }
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, " (%d:0x%x) ", loopCnt, txMsg->data[loopCnt]);
    }
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\n}\n", -1);
}

void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg)
{
    uint32_t loopCnt;

    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage ID: 0x%x", rxMsg->id);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Remote Transmission Request: 0x%x", rxMsg->rtr);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID): 0x%x",
               rxMsg->xtd);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr,
        "\nMessage Error State Indicator(0:Error Active/1:Error Passive): 0x%x",
        rxMsg->esi);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage TimeStamp: 0x%x", rxMsg->rxts);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Data Length Code: 0x%x", rxMsg->dlc);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage BRS: 0x%x", rxMsg->brs);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage CAN FD format: 0x%x", rxMsg->fdf);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Filter Index: 0x%x", rxMsg->fidx);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Accept Non-matching Frame: 0x%x", rxMsg->anmf);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\nMessage Data(byte no:byte data):\n");
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "{", -1);
    for (loopCnt = 0U; loopCnt < gMcanAppdataSize[rxMsg->dlc]; loopCnt++)
    {
        if((loopCnt % 8) == 0U)
        {
            App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\n", -1);
        }
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, " (%d:0x%x) ", loopCnt, rxMsg->data[loopCnt]);
    }
    App_ConsolePuts((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "\n}\n", -1);
}

#if defined (SOC_AM65XX) || defined (SOC_J721E)
static int32_t App_mcanRegIntrInternal(HwiP_Handle *hwiHandle, uint32_t intNum, void f(uintptr_t))
{
    int32_t configStatus = STW_SOK;
    OsalRegisterIntrParams_t    intrPrms;
    OsalInterruptRetCode_e      osalRetVal;

    /* Enable CPU Interrupts and register ISR - MCAN0 Intr0 */
    Osal_RegisterInterrupt_initParams(&intrPrms);
    /* Populate the interrupt parameters */
    intrPrms.corepacConfig.arg              = (uintptr_t) NULL;
    intrPrms.corepacConfig.isrRoutine       = f;
    intrPrms.corepacConfig.priority         = 0U;
    intrPrms.corepacConfig.corepacEventNum  = 0U;
    intrPrms.corepacConfig.intVecNum        = intNum;

    /* Register interrupts */
    osalRetVal = Osal_RegisterInterrupt(&intrPrms, hwiHandle);
    if(OSAL_INT_SUCCESS != osalRetVal)
    {
        configStatus = CSL_EFAIL;
    }
    return configStatus;
}
#endif

#if 0
#if defined (SOC_J721E)
/* TODO: Enable testing of cross domain instances using sciclient API.
 *       Currently done using the CSL API directly.
 *       Issue in sciclient to set the offset values for the device interrupts.
 */
static int32_t App_mcanConfigureIrqRouter(uint32_t devId, uint32_t offset, uint32_t intNum)
{
    int32_t retVal;
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;

    rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
    rmIrqReq.src_id                 = devId;
    rmIrqReq.global_event           = 0U;
    rmIrqReq.src_index              = offset;
    rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
    rmIrqReq.dst_host_irq           = intNum;
    rmIrqReq.ia_id                  = 0U;
    rmIrqReq.vint                   = 0U;
    rmIrqReq.vint_status_bit_index  = 0U;
    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
    retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
    if(CSL_PASS != retVal)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr,
        "Error in SciClient Interrupt Params Configuration!!!");
        printf("offset: %d \n", offset);
    }
    else
    {
        printf("SciClient Interrupt Params Configuration passed for offset: %d \n", offset);
    }
    return retVal;
}
#endif
#endif

static int32_t App_mcanConfigureIrqRouter (uint32_t inputIntrNum, uint32_t outputIntrNum)
{
    int32_t status = 0U;
#if defined (SOC_J721E)
    /* Irq router configuration not required for AM65xx. */
    CSL_IntrRouterCfg irRegs;
#if defined (BUILD_MCU1_0)
    /* For Routing MAIN MCAN interrupts to MCU Domain R5 */
    irRegs.pIntrRouterRegs =(CSL_intr_router_cfgRegs *)
                        CSL_MAIN2MCU_LVL_INTRTR0_CFG_BASE;
    /* We need to pass the offset value only */
    outputIntrNum = outputIntrNum - CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0;
#else
    /* For Routing MCU MCAN interrupts to Main Domain R5 */
    irRegs.pIntrRouterRegs =(CSL_intr_router_cfgRegs *)
                        CSL_R5FSS0_INTROUTER0_INTR_ROUTER_CFG_BASE;
    outputIntrNum = outputIntrNum - CSLR_R5FSS1_CORE1_INTR_R5FSS1_INTROUTER0_OUTL_0;
#endif
    irRegs.pIntdRegs       = (CSL_intr_router_intd_cfgRegs *) NULL;
    irRegs.numInputIntrs       = APP_MAIN_PULSAR0_INTROUTER0_NUM_IN_INTR;
    irRegs.numOutputIntrs      = APP_MAIN_PULSAR0_INTROUTER0_NUM_OUT_INTR;

    status += CSL_intrRouterCfgMux(&irRegs, inputIntrNum, outputIntrNum);
#endif
    return status;
}

int32_t App_mcanRegisterInterrupt(uint32_t modIdx)
{
    int32_t configStatus = STW_SOK;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    Intc_Init();

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* XBar configuration */
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_INT0, XBAR_INTR0_SOURCE);
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_INT1, XBAR_INTR1_SOURCE);
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_ECC, XBAR_INTR_ECC_SOURCE);
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_TS, XBAR_INTR_TS_SOURCE);
#endif

    /* Enable CPU Interrupts and register ISR */
    Intc_IntEnable(APP_MCAN_INT0_M4);
    Intc_IntRegister(APP_MCAN_INT0_M4,
                     (IntrFuncPtr) App_mcanIntr0ISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_INT0_M4, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_INT0_M4);
    Intc_IntEnable(APP_MCAN_INT1_M4);
    Intc_IntRegister(APP_MCAN_INT1_M4,
                     (IntrFuncPtr) App_mcanIntr1ISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_INT1_M4, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_INT1_M4);
    Intc_IntEnable(APP_MCAN_ECC_INT);
    Intc_IntRegister(APP_MCAN_ECC_INT,
                     (IntrFuncPtr) App_mcanECCIntrISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_ECC_INT, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_ECC_INT);
    Intc_IntEnable(APP_MCAN_TS_INT);
    Intc_IntRegister(APP_MCAN_TS_INT,
                     (IntrFuncPtr) App_mcanTSIntrISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_TS_INT, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_TS_INT);
    if (STW_SOK == configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "CrossBar Configuration done.\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Error in configuring CrossBar.\n");
    }
#endif


    if (gMcanModInfo[modIdx].mcanInt0IrqRouterInpNum != IRQ_ROUTER_CFG_NOT_REQUIRED)
    {
        App_mcanConfigureIrqRouter(gMcanModInfo[modIdx].mcanInt0IrqRouterInpNum,
                                   gMcanModInfo[modIdx].mcanInt0IntNum);
    }
    configStatus =  App_mcanRegIntrInternal(&gMcanModInfo[modIdx].mcanInt0HwiHandle,
                                               gMcanModInfo[modIdx].mcanInt0IntNum,
                                              &App_mcanIntr0ISR);
    if (gMcanModInfo[modIdx].mcanInt1IrqRouterInpNum != IRQ_ROUTER_CFG_NOT_REQUIRED)
    {
        App_mcanConfigureIrqRouter(gMcanModInfo[modIdx].mcanInt1IrqRouterInpNum,
                                   gMcanModInfo[modIdx].mcanInt1IntNum);
    }
    configStatus += App_mcanRegIntrInternal(&gMcanModInfo[modIdx].mcanInt1HwiHandle,
                                               gMcanModInfo[modIdx].mcanInt1IntNum,
                                              &App_mcanIntr1ISR);
    if (gMcanModInfo[modIdx].mcanTsIrqRouterInpNum != IRQ_ROUTER_CFG_NOT_REQUIRED)
    {
        App_mcanConfigureIrqRouter(gMcanModInfo[modIdx].mcanTsIrqRouterInpNum,
                                   gMcanModInfo[modIdx].mcanTsIntNum);
    }
    configStatus += App_mcanRegIntrInternal(&gMcanModInfo[modIdx].mcanTsHwiHandle,
                                               gMcanModInfo[modIdx].mcanTsIntNum,
                                              &App_mcanTSIntrISR);

    if(STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CrossBar/Interrupt Configuration failed.\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CrossBar/Interrupt Configuration done.\n");
    }

    return STW_SOK;
}

int32_t App_mcanUnRegisterInterrupt(uint32_t modIdx)
{
    int32_t configStatus = STW_SOK;
    if(gMcanModInfo[modIdx].mcanInt0HwiHandle != NULL)
    {
        configStatus = Osal_DeleteInterrupt(gMcanModInfo[modIdx].mcanInt0HwiHandle, 0U);
        gMcanModInfo[modIdx].mcanInt0HwiHandle = NULL;
    }
    if(gMcanModInfo[modIdx].mcanInt1HwiHandle != NULL)
    {
        configStatus += Osal_DeleteInterrupt(gMcanModInfo[modIdx].mcanInt1HwiHandle, 0U);
        gMcanModInfo[modIdx].mcanInt1HwiHandle = NULL;
    }
    if(gMcanModInfo[modIdx].mcanTsHwiHandle != NULL)
    {
        configStatus += Osal_DeleteInterrupt(gMcanModInfo[modIdx].mcanTsHwiHandle, 0U);
        gMcanModInfo[modIdx].mcanTsHwiHandle = NULL;
    }
    if(STW_SOK != configStatus)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CrossBar/Interrupt Unregister failed.\n");
    }
    else
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "CrossBar/Interrupt Unregister done.\n");
    }

    return configStatus;
}
extern SemaphoreP_Handle   gTxDoneSem;
extern SemaphoreP_Handle   gRxDoneSem;

void App_mcanIntr0ISR(uintptr_t handle)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(mcanBaseAddr);
    MCAN_clearIntrStatus(mcanBaseAddr, intrStatus);
    gMcanIsrIntr0Status = (intrStatus &
                          (~MCAN_getIntrLineSelectStatus(mcanBaseAddr)));
    if(isrPrintEnable == (uint32_t)TRUE)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nInterrupt Status: 0x%x.\n", intrStatus);
    }
    if (gTxDoneSem != NULL)
    {
        if ((gMcanIsrIntr0Status & MCAN_INTR_SRC_TRANS_COMPLETE) == MCAN_INTR_SRC_TRANS_COMPLETE)
        {
            SemaphoreP_post(gTxDoneSem);
        }
    }
    if (gRxDoneSem != NULL)
    {
        uint32_t rxIntrMask = MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG |
             MCAN_INTR_SRC_RX_FIFO0_NEW_MSG |
             MCAN_INTR_SRC_RX_FIFO1_NEW_MSG |
             MCAN_INTR_SRC_HIGH_PRIO_MSG;
        if ((gMcanIsrIntr0Status & rxIntrMask) != 0U)
        {
            /* If any of the Rx interrupts are set,
             * Post the RxSem
             */
            SemaphoreP_post(gRxDoneSem);
        }
    }
    gMcanIsrIntr0Flag = 0U;
}

void App_mcanIntr1ISR(uintptr_t handle)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(mcanBaseAddr);
    MCAN_clearIntrStatus(mcanBaseAddr, intrStatus);
    gMcanIsrIntr1Status = (intrStatus &
                          (MCAN_getIntrLineSelectStatus(mcanBaseAddr)));
    if(isrPrintEnable == (uint32_t)TRUE)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nInterrupt Status: 0x%x.\n", intrStatus);
    }
    gMcanIsrIntr1Flag = 0U;
}

void App_mcanECCIntrISR(void *handle)
{
    MCAN_ECCErrStatus mcanECCErr;

    MCAN_eccGetErrorStatus(mcanBaseAddr, &gMcaneccErr);
    if (MCAN_eccGetIntrStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC))
    {
        MCAN_eccClearIntrStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC);
        if(isrPrintEnable == (uint32_t)TRUE)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "ECC SEC interrupt happened.\n");
        }
    }
    if (MCAN_eccGetIntrStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED))
    {
        MCAN_eccClearIntrStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED);
        if(isrPrintEnable == (uint32_t)TRUE)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "ECC DED interrupt happened.\n");
        }
    }
    if (1U == gMcaneccErr.secErr)
    {
        MCAN_eccClearErrorStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC);
        MCAN_eccGetErrorStatus(mcanBaseAddr, &mcanECCErr);
        while (mcanECCErr.secErr == 1U)
        {
            MCAN_eccGetErrorStatus(mcanBaseAddr, &mcanECCErr);
        }
        MCAN_eccWriteEOI(mcanBaseAddr, MCAN_ECC_ERR_TYPE_SEC);
    }
    if (1U == gMcaneccErr.dedErr)
    {
        MCAN_eccClearErrorStatus(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED);
        MCAN_eccGetErrorStatus(mcanBaseAddr, &mcanECCErr);
        while (mcanECCErr.dedErr == 1U)
        {
            MCAN_eccGetErrorStatus(mcanBaseAddr, &mcanECCErr);
        }
        MCAN_eccWriteEOI(mcanBaseAddr, MCAN_ECC_ERR_TYPE_DED);
    }
    gMcanECCIntrFlag = 0U;
}

void App_mcanTSIntrISR(uintptr_t handle)
{
    if(isrPrintEnable == (uint32_t)TRUE)
    {
        if (MCAN_extTSIsIntrEnable(mcanBaseAddr) == (uint32_t)TRUE)
        {
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Time Stamp overflow happened.\n");
            App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "Unserviced Interrupt Count: %d\n", MCAN_extTSGetUnservicedIntrCount(mcanBaseAddr));
        }
    }
    MCAN_extTSClearRawStatus(mcanBaseAddr);
    gMcanExtTSIntrFlag = 0U;
    MCAN_extTSWriteEOI(mcanBaseAddr);
}

uint32_t App_getBitConfigParamId(const MCAN_BitTimingParams *bitTimings)
{
    uint32_t loopCnt;

    for(loopCnt = 0U ; loopCnt < bitTimingsListSize ; loopCnt++)
    {
        if ((canFDBitTimings[loopCnt].nomRatePrescalar == bitTimings->nomRatePrescalar) &&
            (canFDBitTimings[loopCnt].nomTimeSeg1 == bitTimings->nomTimeSeg1) &&
            (canFDBitTimings[loopCnt].nomTimeSeg2 == bitTimings->nomTimeSeg2) &&
            (canFDBitTimings[loopCnt].nomSynchJumpWidth == bitTimings->nomSynchJumpWidth) &&
            (canFDBitTimings[loopCnt].dataRatePrescalar == bitTimings->dataRatePrescalar) &&
            (canFDBitTimings[loopCnt].dataTimeSeg1 == bitTimings->dataTimeSeg1) &&
            (canFDBitTimings[loopCnt].dataTimeSeg2 == bitTimings->dataTimeSeg2) &&
            (canFDBitTimings[loopCnt].dataSynchJumpWidth == bitTimings->dataSynchJumpWidth))
        {
            break;
        }
    }
    if(loopCnt == bitTimingsListSize)
    {
        loopCnt = 0xFFFFFFFFU;
    }

    return loopCnt;
}

void App_CounterConfig(void)
{
#if defined (SOC_AM65XX)
    /* Enable DMTimer 0 and put it in continuous mode */
    HW_WR_REG32(CSL_MCU_TIMER0_CFG_BASE + 0x38U, 0x3);
    /* Configure GTC Timer - running at 200MHz as per config and default mux mode */
    /* 200 MHz depends on 'MCU_PLL1' and is selected through 'GTCCLK_SEL' mux */
    /* Enable GTC */
    HW_WR_REG32(CSL_GTC0_GTC_CFG1_BASE + 0x0U, 0x1);
#endif
}

void App_ConfigCounterSuspendState(void)
{
#if defined (SOC_TDA3XX) && !(defined (__TI_ARM_V7M4__))
    /* Suspend Input Line : IPU_C0
     * Suspend Output Line : DRM_SUSPEND_CTRL_COUNTER_32K
     * This makes sure when M4 is halt, 32K Counter is not halted
     */
    HW_WR_REG32(DRM_SUSPEND_CTRL_COUNTER_32K,
                (((uint32_t) DRM_SUSPEND_SRC_IPU_C0 << 4U) | 0x0U));

#elif defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX)
    /* As L3_INSTR is not connected to EVE1_P1 , so we cant able to configure
     * DRM_SUSPEND_CTRL_COUNTER_32K for EVE
     */
#if defined (__TI_ARM_V7M4__) || defined (_TMS320C6X)
    /* Suspend Input Line : MPU_C0
     * Suspend Output Line : DRM_SUSPEND_CTRL_COUNTER_32K
     * This makes sure when A15 is halt, 32K Counter is not halted
     */
    HW_WR_REG32(DRM_SUSPEND_CTRL_COUNTER_32K,
                (((uint32_t) DRM_SUSPEND_SRC_IPU_C0 << 4U) | 0x0U));
#endif
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    /* Put DMTimer 0 in free running mode and no idle mode */
    /* Keeping it here for reference */
    /* HW_WR_REG32(CSL_MCU_TIMER0_CFG_BASE + 0x10U, 0x6); */
#endif
}

void App_GetCounterValue(uint64_t *value)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    *value = (uint64_t)HW_RD_REG32(SOC_COUNTER_32K_BASE + COUNTER_32K_CR);
#endif
#if defined (SOC_AM65XX)
    *value = *((uint64_t *)(CSL_GTC0_GTC_CFG1_BASE + 0x8U));
    /* *value = HW_RD_REG32(CSL_MCU_TIMER0_CFG_BASE + 0x3CU); */
#endif
#if defined (SOC_J721E)
    *value = Utils_prfTsGet64();
#endif
}

void App_GetElapsedValue(uint64_t  value, uint64_t *elapsedValue)
{
    uint64_t currVal;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    currVal = HW_RD_REG32(SOC_COUNTER_32K_BASE + COUNTER_32K_CR);
    if (currVal < value)
    {
        /* Counter overflow occured */
        currVal       = (APP_COUNTER_MAX_COUNT - value) + currVal + 1U;
        *elapsedValue = currVal;
    }
    else
    {
        *elapsedValue = currVal - value;
    }
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
    /* Currently wrap-around condition is not taken care */
    /* Keeping it here for reference */
    /* currVal = (HW_RD_REG32(CSL_MCU_TIMER0_CFG_BASE + 0x3CU) + 1U); */
    /* GTC is 64 bit timer */
    currVal = *((uint64_t *)(CSL_GTC0_GTC_CFG1_BASE + 0x8U));
    *elapsedValue = currVal - value;
#endif
}

void App_delayFunc(uint32_t timeout)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    uint64_t startCount, elapsedCount, cycleDelay;

    /* To config 32K Counter in run state when A15(Tda2xx)/M4(Tda3xx) is
     * halted */
    App_ConfigCounterSuspendState();

    App_GetCounterValue(&startCount);
    cycleDelay = (timeout * APP_32K_TIMER_FREQ) / 1000U;
    do
    {
        App_GetElapsedValue(startCount, &elapsedCount);
    } while (elapsedCount <= cycleDelay);
    App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_NORMAL, uartBaseAddr, "Delayed for %dms!!\n", timeout);
#endif
}

void App_ConsolePrintf(uint32_t type, uint32_t baseAddr, const char *pcString, ...)
{
    char printBuffer[APP_PRINT_BUFFER_SIZE];
    va_list arguments;

    /* Start the varargs processing. */
    va_start(arguments, pcString);
    vsnprintf (printBuffer, sizeof(printBuffer), pcString, arguments);
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
        UARTConfigPrintf(baseAddr, printBuffer);
        printf(printBuffer);
    }
#endif
#if defined (SOC_AM65XX)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
        UART_printf(printBuffer);
        printf(printBuffer);
    }
#endif
#if defined (SOC_AM65XX) || defined (SOC_J721E)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
        printf(printBuffer);
    }
#endif
    /* End the varargs processing. */
    va_end(arguments);
}

uint32_t App_ConsolePuts(uint32_t type, uint32_t baseAddr,const char *pTxBuffer,
                         int32_t numBytesToWrite)
{
    uint32_t retVal = 0U;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
    retVal = UARTConfigPuts(baseAddr, pTxBuffer, numBytesToWrite);
    }
#endif
#if defined (SOC_AM65XX)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
        UART_printf(pTxBuffer);
        printf(pTxBuffer);
    }
#endif
#if defined (SOC_J721E)
#if (APP_ENABLE_STATUS_PRINTS_ONLY)
    if ((type & PRINT_MSG_TYPE_STATUS) == PRINT_MSG_TYPE_STATUS)
#endif
    {
        printf(pTxBuffer);
    }
#endif
    return retVal;
}

int32_t App_ConsoleGetNum(uint32_t baseAddr)
{
    int32_t retVal = 0;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    retVal = UARTConfigGetNum(baseAddr);
#endif
#if defined (SOC_AM65XX)
    UART_scanFmt("%d", &retVal);
#elif defined (SOC_J721E)
    scanf ("%d", &retVal);
#endif
    return retVal;
}

uint8_t App_ConsoleGetc(uint32_t baseAddr)
{
    uint8_t retVal = 0U;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    retVal = UARTConfigGetc(baseAddr);
#endif
#if defined (SOC_AM65XX)
    UART_scanFmt("%c", &retVal);
#elif defined (SOC_J721E)
    scanf (" %c", &retVal);
#endif
    return retVal;
}

void App_ConsoleInit(uint32_t baseAddr, uint32_t baudRate, uint32_t wordLength,
                    uint32_t stopBit, uint32_t parity, uint32_t mode)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
    UARTConfigInit(baseAddr, baudRate, wordLength, stopBit, parity, mode);
#endif
}

void App_mcanGetIntStatus(uint32_t baseAddr)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(baseAddr);
    MCAN_clearIntrStatus(baseAddr, intrStatus);
    gMcanIsrIntr0Status = (intrStatus &
                          (~MCAN_getIntrLineSelectStatus(baseAddr)));
    if(isrPrintEnable == (uint32_t)TRUE)
    {
        App_ConsolePrintf((uint32_t)PRINT_MSG_TYPE_STATUS, uartBaseAddr, "\nInterrupt Status: 0x%x.\n", intrStatus);
    }
}

void App_mcanReadMsg(uint32_t           baseAddr,
                     uint32_t           elemAddr,
                     MCAN_RxBufElement *elem)
{
    uint32_t regVal = 0U, loopCnt = 0U;

    regVal   = HW_RD_REG32(baseAddr + elemAddr);
    elem->id = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_ID_MASK)
                           >> MCANSS_RX_BUFFER_ELEM_ID_SHIFT);
    elem->rtr = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_RTR_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_RTR_SHIFT);
    elem->xtd = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_XTD_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_XTD_SHIFT);
    elem->esi = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_ESI_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_ESI_SHIFT);

    elemAddr  += 4U;
    regVal     = HW_RD_REG32(baseAddr + elemAddr);
    elem->rxts = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_RXTS_MASK)
                             >> MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT);
    elem->dlc = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_DLC_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_DLC_SHIFT);
    elem->brs = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_BRS_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_BRS_SHIFT);
    elem->fdf = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_FDF_MASK)
                            >> MCANSS_RX_BUFFER_ELEM_FDF_SHIFT);
    elem->fidx = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_FIDX_MASK)
                             >> MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT);
    elem->anmf = (uint32_t) ((regVal & MCANSS_RX_BUFFER_ELEM_ANMF_MASK)
                             >> MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT);
    elemAddr += 4U;

    loopCnt = 0U;
    /* Reading words from message RAM and forming payload bytes out of it */
    while ((4U <= (App_mcanGetDataSize(elem->dlc) - loopCnt)) &&
           (0U != (App_mcanGetDataSize(elem->dlc) - loopCnt)))
    {
        regVal = HW_RD_REG32(baseAddr + elemAddr);
        elem->data[loopCnt]       = (uint8_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)] = (uint8_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)] = (uint8_t)((regVal & 0x00FF0000U) >> 16U);
        elem->data[(loopCnt + 3U)] = (uint8_t)((regVal & 0xFF000000U) >> 24U);
        elemAddr += 4U;
        loopCnt  += 4U;
    }
    /* Reading remaining bytes from message RAM */
    if (0U < (App_mcanGetDataSize(elem->dlc) - loopCnt))
    {
        regVal = HW_RD_REG32(baseAddr + elemAddr);
        elem->data[loopCnt]       = (uint8_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)] = (uint8_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)] = (uint8_t)((regVal & 0x00FF0000U) >> 16U);
    }
}

void App_mcanWriteMsg(uint32_t                 baseAddr,
                      uint32_t                 elemAddr,
                      const MCAN_TxBufElement *elem)
{
    uint32_t regVal = 0, loopCnt = 0U;

    regVal  = 0U;
    regVal |= (((uint32_t) (elem->id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT)) |
               ((uint32_t) (elem->rtr << MCANSS_TX_BUFFER_ELEM_RTR_SHIFT)) |
               ((uint32_t) (elem->xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT)) |
               ((uint32_t) (elem->esi << MCANSS_TX_BUFFER_ELEM_ESI_SHIFT)));
    HW_WR_REG32(baseAddr + elemAddr, regVal);
    elemAddr += 4U;

    regVal  = 0U;
    regVal |= ((uint32_t) (elem->dlc << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT)) |
              ((uint32_t) (elem->brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT)) |
              ((uint32_t) (elem->fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT)) |
              ((uint32_t) (elem->efc << MCANSS_TX_BUFFER_ELEM_EFC_SHIFT)) |
              ((uint32_t) (elem->mm << MCANSS_TX_BUFFER_ELEM_MM_SHIFT));
    HW_WR_REG32(baseAddr + elemAddr, regVal);
    elemAddr += 4U;

    loopCnt = 0U;
    /* Framing words out of the payload bytes and writing it to message RAM */
    while ((4U <= (App_mcanGetDataSize(elem->dlc) - loopCnt)) &&
           (0U != (App_mcanGetDataSize(elem->dlc) - loopCnt)))
    {
        regVal  = 0U;
        regVal |= ((uint32_t)elem->data[loopCnt] |
                   ((uint32_t)elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t)elem->data[(loopCnt + 2U)] << 16U) |
                   ((uint32_t)elem->data[(loopCnt + 3U)] << 24U));
        HW_WR_REG32(baseAddr + elemAddr, regVal);
        elemAddr += 4U;
        loopCnt  += 4U;
    }
    /* Framing a word out of remaining payload bytes and writing it to
     * message RAM */
    if (0U < (App_mcanGetDataSize(elem->dlc) - loopCnt))
    {
        regVal  = 0U;
        regVal |= ((uint32_t)elem->data[loopCnt] |
                   ((uint32_t)elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t)elem->data[(loopCnt + 2U)] << 16U) |
                   ((uint32_t)elem->data[(loopCnt + 3U)] << 24U));
        HW_WR_REG32(baseAddr + elemAddr, regVal);
    }
}

uint32_t App_mcanGetDataSize(uint32_t dlc)
{
    uint32_t dataSize[16] = {0,  1,  2,  3,  4,  5,  6, 7, 8,
                             12, 16, 20, 24, 32, 48, 64};

    return (dataSize[dlc]);
}

uint32_t App_mcangetMsgObjSize(uint32_t elemSize)
{
    uint32_t objSize[8] = {4, 5, 6, 7, 8, 10, 14, 18};

    return (objSize[elemSize]);
}
