/*
 *   Copyright (c) Texas Instruments Incorporated 2016-2019
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
 *  \file     mcan_evm_loopback_app_main.c
 *
 *  \brief    This file contains MCAN sample code.
 *
 *  \details  MCAN operational mode is set to CAN-FD. This test will need
 *            two MCAN nodes present two different EVM connected to each other..
 *            Arbitration bit-rate and data phase bit-rate is set to 1Mbit/s and
 *            5Mbit/s receptively.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_edma.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/cslr_mcan.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/csl/csl_mcan.h>
#include <ti/csl/cslr_synctimer.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#if defined (SOC_TDA2PX)
/* For TDA2Px MCAN address is in bit band region. So use the virtual address. */
#define APP_MCAN_MODULE                          (SOC_MCAN_BASE_VIRT)
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#define APP_MCAN_MODULE                          (SOC_MCAN_BASE)
#endif

#define APP_MCAN_STD_ID_FILT_START_ADDR          (0U)
#define APP_MCAN_STD_ID_FILTER_NUM               (1U)
#define APP_MCAN_EXT_ID_FILT_START_ADDR          (48U)
#define APP_MCAN_EXT_ID_FILTER_NUM               (1U)
#define APP_MCAN_TX_EVENT_START_ADDR             (100U)
#define APP_MCAN_TX_EVENT_SIZE                   (5U)
#define APP_MCAN_TX_BUFF_START_ADDR              (148U)
#define APP_MCAN_TX_BUFF_SIZE                    (5U)
#define APP_MCAN_TX_FIFO_SIZE                    (5U)
#define APP_MCAN_FIFO_0_START_ADDR               (548U)
#define APP_MCAN_FIFO_0_NUM                      (5U)
#define APP_MCAN_FIFO_1_START_ADDR               (748U)
#define APP_MCAN_FIFO_1_NUM                      (5U)
#define APP_MCAN_RX_BUFF_START_ADDR              (948U)

#define APP_MCAN_EXT_ID_AND_MASK                 (0x1FFFFFFFU)

#if defined (SOC_TDA2PX)
#define APP_MCAN_INT0_M4                                  (78U)
#define APP_MCAN_INT1_M4                                  (79U)
#define APP_MCAN_ECC_INT_M4                               (75U)
#define APP_MCAN_TS_INT_M4                                (72U)
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#define APP_MCAN_INT0_M4                                  (34U)
#define APP_MCAN_INT1_M4                                  (35U)
#define APP_MCAN_ECC_INT_M4                               (36U)
#define APP_MCAN_TS_INT_M4                                (37U)
#endif

#if defined (__TI_ARM_V7M4__)
    #define APP_MCAN_INT0                     (APP_MCAN_INT0_M4)
    #define APP_MCAN_INT1                     (APP_MCAN_INT1_M4)
    #define APP_MCAN_ECC_INT                  (APP_MCAN_ECC_INT_M4)
    #define APP_MCAN_TS_INT                   (APP_MCAN_TS_INT_M4)
    #define XBAR_CPU                          (CSL_XBAR_IRQ_CPU_ID_IPU1)
    #define XBAR_MCAN_INT0                       (CSL_XBAR_INST_IPU1_IRQ_34)
    #define XBAR_MCAN_INT1                       (CSL_XBAR_INST_IPU1_IRQ_35)
    #define XBAR_MCAN_ECC                        (CSL_XBAR_INST_IPU1_IRQ_36)
    #define XBAR_MCAN_TS                         (CSL_XBAR_INST_IPU1_IRQ_37)
    #define XBAR_INTR0_SOURCE                    (CSL_XBAR_MCAN_IRQ_INT0)
    #define XBAR_INTR1_SOURCE                    (CSL_XBAR_MCAN_IRQ_INT1)
    #define XBAR_INTR_ECC_SOURCE                 (CSL_XBAR_MCAN_IRQ_PARITY)
    #define XBAR_INTR_TS_SOURCE                  (CSL_XBAR_MCAN_IRQ_TS)
#elif defined (_TMS320C6X)
    /* Not yet supported */
#endif
/* Print buffer character limit for prints- UART or CCS Console */
#define APP_PRINT_BUFFER_SIZE                       (4000)
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

uint32_t          gMcanAppdataSize[16] =
{0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
volatile uint32_t gMcanIsrIntr0Flag = 1U;
volatile uint32_t gMcanIsrIntr1Flag = 1U;
MCAN_ECCErrStatus gMcaneccErr;

#if defined (SOC_TDA2PX)
uint32_t uartBaseAddr = SOC_UART1_BASE;
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
uint32_t uartBaseAddr = SOC_UART3_BASE;
#endif

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function will configure MCAN module
 *
 * \param   none.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanConfig(void);

/**
 * \brief   This function will configure X-BAR for MCAN interrupts
 *
 * \param   none.
 *
 * \retval  status      configuration status.
 */
static int32_t App_mcanXBarConfig(void);

/**
 * \brief   This is Interrupt Service Routine for MCAN interrupt 0.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanIntr0ISR(void *handle);

/**
 * \brief   This is Interrupt Service Routine for MCAN interrupt 1.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanIntr1ISR(void *handle);

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_TDA2PX)
/**
 * \brief   This is Interrupt Service Routine for MCAN ECC interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanECCIntrISR(void *handle);
#endif

/**
 * \brief   This is Interrupt Service Routine for MCAN TimeStamp interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanTSIntrISR(void *handle);

/**
 * \brief   This API will MCAN Rx Msg.
 *
 * \param   rxMsg           received message object.
 *
 * \retval  none.
 */
static void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg);

/**
 * \brief   This API will MCAN Tx Msg.
 *
 * \param   txMsg           message object to be transmitted.
 *
 * \retval  none.
 */
static void App_mcanPrintTxMsg(const MCAN_TxBufElement *txMsg);

/**
 * \brief   This API will load the register from ECC memory bank.
 *
 * \param   txMsg           message object to be transmitted.
 *
 * \return  None.
 */
static void APP_mcanTxTest(MCAN_TxBufElement *txMsg);

/**
 * \brief   This API will load the register from ECC memory bank.
 *
 * \param   txMsg           message object to be transmitted
 *                          (Needed for Message validation).
 *
 * \return  None.
 */
static void APP_mcanRxTest(const MCAN_TxBufElement *txMsg);

/**
 * \brief   This API will print on UART/CCS Console.
 *
 * \param   pcString        string to be printed.
 *
 * \return  None.
 */
void App_ConsolePrintf(const char *pcString, ...);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void padConfig_prcmEnable()
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /*Pad configurations- UART  */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
    /*Pad configurations - MCAN */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_RXD,0x0006000C);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_TXD,0x0004000C);
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
                    UART_STOP_BIT_1, UART_NO_PARITY,
                    UART_16x_MODE);
#elif defined (SOC_TDA2PX)
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
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
                    UART_STOP_BIT_1, UART_NO_PARITY,
                    UART_16x_MODE);
#endif
}

int32_t main(void)
{
    int32_t                    configStatus = STW_EFAIL;
    uint32_t                   mode         = 0U, loopCnt = 0U;
    MCAN_TxBufElement          txMsg;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_TDA2PX)
    uint32_t                   postDivider;
#endif

#if defined (SOC_TDA2PX)
    /* Wait for SBL running on A15 to finish all UART prints. */
    volatile int32_t          delayVal = 0x0FFFFFU;
    while (delayVal != 0)
    {
        delayVal --;
    }
#endif

    /* Do Pad Config for UART */
    padConfig_prcmEnable();
    /* UART Init */

    App_ConsolePrintf("\n Starting Application...\n");
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Configure MCAN io clock */
    /* Set the post div value of 25. MCAN HSDIV registers is part of Control
     * module registers, which needs an adjustment value to be subtracted for
     * the HS dividers to properly divide the DPLL outputs to have the right
     * frequency values.
     */
    postDivider = 24U;
    /* Set the postDividers reg */
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLKHSDIV,
                  postDivider);
    /* Select the mux value */
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_TENABLEDIV_SEL,
                  1U);
    /* Select the Toggle sequence 010 */
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_TENABLEDIV_SEL,
                  0U);
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_TENABLEDIV_SEL,
                  1U);
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_TENABLEDIV_SEL,
                  0U);
    /* Re Select the mux value */
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_TENABLEDIV_SEL,
                  0U);
    /* Enable the HSDIV post div clock */
    HW_WR_FIELD32(SOC_SEC_EFUSE_REGISTERS_BASE+CTRL_CORE_SEC_SMA_SW_17,
                  CTRL_CORE_SEC_SMA_SW_17_MCAN_CLK_HSDIV_EN,
                  1U);
#elif defined (SOC_TDA2PX)
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
    App_ConsolePrintf("MCAN Clock Configuration Successful.\n");

    App_ConsolePrintf("MCAN Node Type:\n");
    App_ConsolePrintf("1. Transmitter Side.\n");
    App_ConsolePrintf("2. Receiver Side.\n");
    App_ConsolePrintf("Enter type of the node:\n");

    mode = UARTConfigGetNum(uartBaseAddr);

    /* CrossBar Configuration */
    configStatus = App_mcanXBarConfig();

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_TDA2PX)
    if (STW_SOK == configStatus)
    {
        /* Enable MCAN module */
        HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE+CM_L4PER2_DCAN2_CLKCTRL,
                      CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE,
                      CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_ENABLE);
        while (CM_L4PER2_DCAN2_CLKCTRL_IDLEST_FUNC !=
               HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE+CM_L4PER2_DCAN2_CLKCTRL,
                             CM_L4PER2_DCAN2_CLKCTRL_IDLEST))
        {
            /* Wait till MCAN module is enabled */
        }
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
    for (loopCnt = 0; loopCnt < MCAN_MAX_PAYLOAD_BYTES; loopCnt++)
    {
        txMsg.data[loopCnt] = loopCnt;
    }

    configStatus = App_mcanConfig();
    if (STW_SOK == configStatus)
    {
        switch (mode)
        {
            case 1:
                /* This is transmitter side application */
                App_ConsolePrintf("\nTransmitter Side application:\n");
                App_ConsolePrintf(
                    "This test will send 15  messages with various payload varying from 1byte to 64bytes.\n"
                    );
                App_ConsolePrintf("Message Object:\n");
                App_mcanPrintTxMsg(&txMsg);
                APP_mcanTxTest(&txMsg);
                break;
            case 2:
                /* This is receiver side application */
                App_ConsolePrintf("\nReceiver Side application:\n");
                App_ConsolePrintf(
                    "This test will receive 15  messages with various payload varying from 1byte to 64bytes.\n"
                    );
                APP_mcanRxTest(&txMsg);
                break;
            default:
                App_ConsolePrintf("Wrong option...\n");
                break;
        }
    }
    App_ConsolePrintf("\n Application is completed.\n");

    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static int32_t App_mcanXBarConfig(void)
{
    int32_t configStatus = STW_SOK;

    Intc_Init();

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_TDA2PX)
    /* XBar configuration */
    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_INT0, XBAR_INTR0_SOURCE);
    Intc_IntEnable(APP_MCAN_INT0_M4);
    Intc_IntRegister(APP_MCAN_INT0_M4,
                     (IntrFuncPtr) App_mcanIntr0ISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_INT0_M4, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_INT0_M4);

    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_INT1, XBAR_INTR1_SOURCE);
    Intc_IntEnable(APP_MCAN_INT1_M4);
    Intc_IntRegister(APP_MCAN_INT1_M4,
                     (IntrFuncPtr) App_mcanIntr1ISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_INT1_M4, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_INT1_M4);

    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_ECC, XBAR_INTR_ECC_SOURCE);
    Intc_IntEnable(APP_MCAN_ECC_INT);
    Intc_IntRegister(APP_MCAN_ECC_INT,
                     (IntrFuncPtr) App_mcanECCIntrISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_ECC_INT, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_ECC_INT);

    CSL_xbarIrqConfigure(XBAR_CPU, XBAR_MCAN_TS, XBAR_INTR_TS_SOURCE);
    Intc_IntEnable(APP_MCAN_TS_INT);
    Intc_IntRegister(APP_MCAN_TS_INT,
                     (IntrFuncPtr) App_mcanTSIntrISR, 0U);
    Intc_IntPrioritySet(APP_MCAN_TS_INT, 1U, 0U);
    Intc_SystemEnable(APP_MCAN_TS_INT);
#endif
    App_ConsolePrintf("CrossBar/Interrupt Configuration done.\n");

    return configStatus;
}

static int32_t App_mcanConfig(void)
{
    uint32_t                   fdoe;
    int32_t                    configStatus = STW_SOK;
    MCAN_RevisionId            revId;
    MCAN_InitParams            initParams;
    MCAN_ConfigParams          configParams;
    MCAN_MsgRAMConfigParams    msgRAMConfigParams;
    MCAN_StdMsgIDFilterElement stdFiltelem;
    MCAN_BitTimingParams       bitTimes;

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
    MCAN_getRevisionId(APP_MCAN_MODULE, &revId);
    App_ConsolePrintf("MCANSS Revision ID:\n");
    App_ConsolePrintf("scheme:0x%x\n", revId.scheme);
    App_ConsolePrintf("Business Unit:0x%x\n", revId.bu);
    App_ConsolePrintf("Module ID:0x%x\n", revId.modId);
    App_ConsolePrintf("RTL Revision:0x%x\n", revId.rtlRev);
    App_ConsolePrintf("Major Revision:0x%x\n", revId.major);
    App_ConsolePrintf("Custom Revision:0x%x\n", revId.custom);
    App_ConsolePrintf("Minor Revision:0x%x\n", revId.minor);
    /* Enable Auto wakeup */
    fdoe = MCAN_isFDOpEnable(APP_MCAN_MODULE);
    if ((uint32_t)TRUE == fdoe)
    {
        App_ConsolePrintf("CAN-FD operation is enabled through E-Fuse.\n");
    }
    else
    {
        App_ConsolePrintf("CAN-FD operation is disabled through E-Fuse.\n");
    }
    /* wait for memory initialization to happen */
    while (FALSE == MCAN_isMemInitDone(APP_MCAN_MODULE))
    {}
    /* Get endianess value */
    App_ConsolePrintf("Endianess Value: 0x%x\n",
                       MCAN_getEndianVal(APP_MCAN_MODULE));
    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(APP_MCAN_MODULE, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(APP_MCAN_MODULE))
    {}
    /* Initialize MCAN module */
    MCAN_init(APP_MCAN_MODULE, &initParams);
    /* Configure MCAN module */
    MCAN_config(APP_MCAN_MODULE, &configParams);
    /* Configure Bit timings */
    MCAN_setBitTime(APP_MCAN_MODULE, &bitTimes);
    /* Set Extended ID Mask */
    MCAN_setExtIDAndMask(APP_MCAN_MODULE, APP_MCAN_EXT_ID_AND_MASK);
    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig(APP_MCAN_MODULE, &msgRAMConfigParams);
    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter(APP_MCAN_MODULE, 0U, &stdFiltelem);
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(APP_MCAN_MODULE, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(APP_MCAN_MODULE))
    {}
    return configStatus;
}

static void App_mcanIntr0ISR(void *handle)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(APP_MCAN_MODULE);
    MCAN_clearIntrStatus(APP_MCAN_MODULE, intrStatus);
    if (MCAN_INTR_SRC_TRANS_COMPLETE ==
        (intrStatus & MCAN_INTR_SRC_TRANS_COMPLETE))
    {
        gMcanIsrIntr0Flag = 0U;
    }
    else
    {
        App_ConsolePrintf("\nInterrupt Status: 0x%x\n", intrStatus);
    }
}

static void App_mcanIntr1ISR(void *handle)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(APP_MCAN_MODULE);
    MCAN_clearIntrStatus(APP_MCAN_MODULE, intrStatus);
    if (MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG ==
        (intrStatus & MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG))
    {
        gMcanIsrIntr1Flag = 0U;
    }
    else
    {
        App_ConsolePrintf("\nInterrupt Status: 0x%x\n", intrStatus);
    }
}

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_TDA2PX)
static void App_mcanECCIntrISR(void *handle)
{
    MCAN_eccGetErrorStatus(APP_MCAN_MODULE, &gMcaneccErr);
    if (1U == gMcaneccErr.secErr)
    {
        MCAN_eccClearErrorStatus(APP_MCAN_MODULE, MCAN_ECC_ERR_TYPE_SEC);
        MCAN_eccWriteEOI(APP_MCAN_MODULE, MCAN_ECC_ERR_TYPE_SEC);
    }
    if (1U == gMcaneccErr.dedErr)
    {
        MCAN_eccClearErrorStatus(APP_MCAN_MODULE, MCAN_ECC_ERR_TYPE_DED);
        MCAN_eccWriteEOI(APP_MCAN_MODULE, MCAN_ECC_ERR_TYPE_DED);
    }
    App_ConsolePrintf("ECC interrupt happened.\n");
}
#endif

static void App_mcanTSIntrISR(void *handle)
{
    App_ConsolePrintf("Time Stamp overflow happened.\n");
}

static void App_mcanPrintTxMsg(const MCAN_TxBufElement *txMsg)
{
    uint32_t loopCnt;

    App_ConsolePrintf("\nMessage ID: 0x%x", txMsg->id);

    App_ConsolePrintf("\nMessage Remote Transmission Request: 0x%x",
                       txMsg->rtr);

    App_ConsolePrintf(
        "\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID): 0x%x",
        txMsg->xtd);

    App_ConsolePrintf(
        "\nMessage Error State Indicator(0:Error Active/1:Error Passive): 0x%x",
        txMsg->esi);

    App_ConsolePrintf("\nMessage Data Length Code: 0x%x", txMsg->dlc);

    App_ConsolePrintf("\nMessage BRS: 0x%x", txMsg->brs);

    App_ConsolePrintf("\nMessage CAN FD format: 0x%x", txMsg->fdf);

    App_ConsolePrintf("\nMessage Store Tx Events: 0x%x", txMsg->efc);

    App_ConsolePrintf("\nMessage Marker: 0x%x", txMsg->mm);

    for (loopCnt = 0U; loopCnt < gMcanAppdataSize[txMsg->dlc]; loopCnt++)
    {
        App_ConsolePrintf("\nMessage DataByte%d", loopCnt);
        App_ConsolePrintf(": 0x%x", txMsg->data[loopCnt]);
    }
}

static void App_mcanPrintRxMsg(const MCAN_RxBufElement *rxMsg)
{
    uint32_t loopCnt;

    App_ConsolePrintf("\nMessage ID: 0x%x", rxMsg->id);
    App_ConsolePrintf("\nMessage Remote Transmission Request: 0x%x", rxMsg->rtr);
    App_ConsolePrintf(
        "\nMessage Extended Frame ID(0:11Bit ID/1:29bit ID): 0x%x",
        rxMsg->xtd);
    App_ConsolePrintf(
        "\nMessage Error State Indicator(0:Error Active/1:Error Passive): 0x%x",
        rxMsg->esi);
    App_ConsolePrintf("\nMessage TimeStamp: 0x%x", rxMsg->rxts);
    App_ConsolePrintf("\nMessage Data Length Code: 0x%x", rxMsg->dlc);
    App_ConsolePrintf("\nMessage BRS: 0x%x", rxMsg->brs);
    App_ConsolePrintf("\nMessage CAN FD format: 0x%x", rxMsg->fdf);
    App_ConsolePrintf("\nMessage Filter Index: 0x%x", rxMsg->fidx);
    App_ConsolePrintf("\nMessage Accept Non-matching Frame: 0x%x", rxMsg->anmf);
    for (loopCnt = 0U; loopCnt < gMcanAppdataSize[rxMsg->dlc]; loopCnt++)
    {
        App_ConsolePrintf("\nMessage DataByte%d", loopCnt);
        App_ConsolePrintf(": 0x%x", rxMsg->data[loopCnt]);
    }
}

static void APP_mcanTxTest(MCAN_TxBufElement *txMsg)
{
    int32_t  configStatus = STW_EFAIL, testStatus = STW_SOK;
    uint32_t loopCnt      = 1U;
    MCAN_ProtocolStatus protStatus;

    /* Enable Interrupts */
    MCAN_enableIntr(APP_MCAN_MODULE, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(APP_MCAN_MODULE,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(APP_MCAN_MODULE,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_0);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(APP_MCAN_MODULE,
                        MCAN_INTR_LINE_NUM_0,
                        1U);
    /* Enable Transmission interrupt */
    configStatus = MCAN_txBufTransIntrEnable(APP_MCAN_MODULE,
                                             1U,
                                             (uint32_t)TRUE);
    for (loopCnt = 1U; loopCnt < 16U; loopCnt++)
    {
        txMsg->dlc = loopCnt;
        /* Write message to Msg RAM */
        MCAN_writeMsgRam(APP_MCAN_MODULE,
                         MCAN_MEM_TYPE_BUF,
                         1U,
                         txMsg);
        /* Add request for transmission */
        configStatus += MCAN_txBufAddReq(APP_MCAN_MODULE, 1U);
        if (STW_SOK != configStatus)
        {
            App_ConsolePrintf("\nError in Adding Transmission Request...\n");
        }
        while (gMcanIsrIntr0Flag)
        {}
        gMcanIsrIntr0Flag = 1U;
        MCAN_getProtocolStatus(APP_MCAN_MODULE, &protStatus);
        /* Checking for Errors */
        if (((MCAN_ERR_CODE_NO_ERROR == protStatus.lastErrCode) ||
             (MCAN_ERR_CODE_NO_CHANGE == protStatus.lastErrCode)) &&
            ((MCAN_ERR_CODE_NO_ERROR == protStatus.dlec) ||
             (MCAN_ERR_CODE_NO_CHANGE == protStatus.dlec)) &&
            (0U == protStatus.pxe))
        {
            App_ConsolePrintf(
                "\nMessage successfully transferred with payload Bytes:%d",
                gMcanAppdataSize[txMsg->dlc]);
        }
        else
        {
            App_ConsolePrintf(
            "\nError in transmission with payload Bytes:%d",
            gMcanAppdataSize[txMsg->dlc]);
            testStatus = STW_EFAIL;
        }
    }
    if (STW_EFAIL == testStatus)
    {
        App_ConsolePrintf("\nTx Test FAILED...\n");
    }
    else
    {
        App_ConsolePrintf("\nTx Test PASSED...\n");
    }
}

static void APP_mcanRxTest(const MCAN_TxBufElement *txMsg)
{
    uint32_t             loopCnt    = 1U, chkCnt = 0U, errFlag = 0U;
    int32_t              testStatus = STW_SOK;
    MCAN_RxBufElement    rxMsg;
    MCAN_RxNewDataStatus newDataStatus;
    MCAN_ErrCntStatus    errCounter;

    /* Enable Interrupts */
    MCAN_enableIntr(APP_MCAN_MODULE, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(APP_MCAN_MODULE,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(APP_MCAN_MODULE,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_1);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(APP_MCAN_MODULE,
                        MCAN_INTR_LINE_NUM_1,
                        1U);
    for (loopCnt = 1U; loopCnt < 16U; loopCnt++)
    {
        while (gMcanIsrIntr1Flag)
        {}
        gMcanIsrIntr1Flag = 1U;
        /* Checking for Errors */
        MCAN_getErrCounters(APP_MCAN_MODULE, &errCounter);
        if ((0U == errCounter.recErrCnt) &&
            (0U == errCounter.canErrLogCnt))
        {
            MCAN_getNewDataStatus(APP_MCAN_MODULE, &newDataStatus);
            MCAN_clearNewDataStatus(APP_MCAN_MODULE, &newDataStatus);
            MCAN_readMsgRam(APP_MCAN_MODULE,
                            MCAN_MEM_TYPE_BUF,
                            0U,
                            0U,
                            &rxMsg);
            errFlag = 0U;
            for (chkCnt = 0U; chkCnt < gMcanAppdataSize[rxMsg.dlc]; chkCnt++)
            {
                if (txMsg->data[chkCnt] != rxMsg.data[chkCnt])
                {
                    errFlag = 1U;
                    break;
                }
            }
            if (0U == errFlag)
            {
                App_ConsolePrintf(
                    "\nMessage successfully received with payload Bytes: %d",
                    gMcanAppdataSize[rxMsg.dlc]);
            }
            else
            {
                App_ConsolePrintf(
                    "\nWrong data received in message with payload Bytes: ",
                    gMcanAppdataSize[rxMsg.dlc]);
                testStatus = STW_EFAIL;
            }
        }
        else
        {
            App_ConsolePrintf(
            "\nError in reception with payload Bytes:%d",
            gMcanAppdataSize[txMsg->dlc]);
            testStatus = STW_EFAIL;
        }
    }
    App_ConsolePrintf("\nReceived last message with following details:");
    App_mcanPrintRxMsg(&rxMsg);
    if (STW_EFAIL == testStatus)
    {
        App_ConsolePrintf("\nRx Test FAILED...\n");
    }
    else
    {
        App_ConsolePrintf("\nRx Test PASSED...\n");
    }
}

void App_ConsolePrintf(const char *pcString, ...)
{
    static char printBuffer[APP_PRINT_BUFFER_SIZE];
    va_list arguments;

    /* Start the varargs processing. */
    va_start(arguments, pcString);
    vsnprintf (printBuffer, sizeof(printBuffer), pcString, arguments);
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x) || (SOC_TDA2PX)
        UARTConfigPrintf(uartBaseAddr, printBuffer);
#endif
    /* End the varargs processing. */
    va_end(arguments);
}
