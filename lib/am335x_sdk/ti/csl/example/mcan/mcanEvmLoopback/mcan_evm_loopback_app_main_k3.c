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
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/csl_mcan.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/osal/osal.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/board/board.h>
#include <ti/drv/i2c/I2C.h>
#if defined (SOC_J721E)
#include <ti/drv/sciclient/sciclient.h>
#endif


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#if defined (SOC_AM65XX)
#define APP_ENABLE_UART_PRINT                    (1U)
#elif defined (SOC_J721E)
#define APP_ENABLE_UART_PRINT                    (0U)
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

#define APP_MCU_MCAN_0_INT0                                   (0U)
#define APP_MCU_MCAN_0_INT1                                   (1U)
#define APP_MCU_MCAN_0_TS_INT                                 (4U)
#define APP_MCU_MCAN_1_INT0                                   (2U)
#define APP_MCU_MCAN_1_INT1                                   (3U)
#define APP_MCU_MCAN_1_TS_INT                                 (5U)

#if defined (SOC_J721E)
#if defined (BUILD_MCU1_0)
#define APP_MAIN_MCAN_2_INT0                (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0)
#define APP_MAIN_MCAN_2_INT1                (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_1)
#define APP_MAIN_MCAN_2_TS_INT              (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_2)
#else
#define APP_MAIN_MCAN_0_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_0_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_0_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_2_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN2_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_2_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN2_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_2_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_4_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN4_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_4_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN4_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_4_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN4_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_5_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN5_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_5_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN5_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_5_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN5_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_6_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_6_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_6_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_7_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN7_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_7_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN7_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_7_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_9_INT0                (CSLR_R5FSS1_CORE0_INTR_MCAN9_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_9_INT1                (CSLR_R5FSS1_CORE0_INTR_MCAN9_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_9_TS_INT              (CSLR_R5FSS1_CORE0_INTR_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#define APP_MAIN_MCAN_11_INT0               (CSLR_R5FSS1_CORE0_INTR_MCAN11_MCANSS_MCAN_LVL_INT_0)
#define APP_MAIN_MCAN_11_INT1               (CSLR_R5FSS1_CORE0_INTR_MCAN11_MCANSS_MCAN_LVL_INT_1)
#define APP_MAIN_MCAN_11_TS_INT             (CSLR_R5FSS1_CORE0_INTR_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#endif
#endif

/* Print buffer character limit for prints- UART or CCS Console */
#define APP_PRINT_BUFFER_SIZE                       (4000)
#if defined (SOC_AM65XX)
/* Port and pin number mask for GPIO Load pin.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define AM65XX_IDK_GPIO_CAN0_STB_PIN    (0x012F)
#define AM65XX_IDK_GPIO_CAN1_STB_PIN    (0x0143)
#endif
#if defined (SOC_J721E)
#define J721E_GPIO_GESI_CAN_STB_PIN     (0x003C)
#define J721E_GPIO_MAIN_MCAN2_STB_PIN   (0x007F)
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

uint32_t          gMcanAppdataSize[16] =
{0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
volatile uint32_t gMcanIsrIntr0Flag = 1U;
volatile uint32_t gMcanIsrIntr1Flag = 1U;
MCAN_ECCErrStatus gMcaneccErr;

uint32_t gMcanModAddr;
static uint32_t gMcanMods[] =
                    {
#if defined(SOC_AM65XX) || (defined(SOC_J721E) && defined(BUILD_MCU1_0))
                        CSL_MCU_MCAN0_MSGMEM_RAM_BASE,
                        CSL_MCU_MCAN1_MSGMEM_RAM_BASE,
#endif
#if (defined(SOC_J721E) && defined(BUILD_MCU2_1))
                        CSL_MCAN0_MSGMEM_RAM_BASE,
                        CSL_MCAN2_MSGMEM_RAM_BASE,
                        CSL_MCAN4_MSGMEM_RAM_BASE,
                        CSL_MCAN5_MSGMEM_RAM_BASE,
                        CSL_MCAN6_MSGMEM_RAM_BASE,
                        CSL_MCAN7_MSGMEM_RAM_BASE,
                        CSL_MCAN9_MSGMEM_RAM_BASE,
                        CSL_MCAN11_MSGMEM_RAM_BASE,
#endif
                    };
static char *gMcanModsNames[] =
                    {
#if defined(SOC_AM65XX) || (defined(SOC_J721E) && defined(BUILD_MCU1_0))
                         "MCU_MCAN0",
                         "MCU_MCAN1",
#endif
#if (defined(SOC_J721E) && defined(BUILD_MCU2_1))
                         "MAIN_MCAN0",
                         "MAIN_MCAN2",
                         "MAIN_MCAN4  (GESI Exp Board)",
                         "MAIN_MCAN5  (GESI Exp Board)",
                         "MAIN_MCAN6  (GESI Exp Board)",
                         "MAIN_MCAN7  (GESI Exp Board)",
                         "MAIN_MCAN9  (GESI Exp Board)",
                         "MAIN_MCAN11 (GESI Exp Board)",
#endif
                    };

#if defined (SOC_AM65XX)
/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM65XX_IDK */
    AM65XX_IDK_GPIO_CAN0_STB_PIN | GPIO_CFG_OUTPUT,
    AM65XX_IDK_GPIO_CAN1_STB_PIN | GPIO_CFG_OUTPUT
};
#endif
#if defined (SOC_J721E)
/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : CAN STB */
    J721E_GPIO_GESI_CAN_STB_PIN   | GPIO_CFG_OUTPUT,
    J721E_GPIO_MAIN_MCAN2_STB_PIN | GPIO_CFG_OUTPUT,
};
#endif

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config = {
        gpioPinConfigs,
        gpioCallbackFunctions,
        sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
        sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
        0,
    };
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
static void App_mcanIntr0ISR(uintptr_t arg);

/**
 * \brief   This is Interrupt Service Routine for MCAN interrupt 1.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanIntr1ISR(uintptr_t arg);

/**
 * \brief   This is Interrupt Service Routine for MCAN TimeStamp interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void App_mcanTSIntrISR(uintptr_t arg);

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

/**
 * \brief   This API will get a number from UART/CCS Console.
 *
 * \param   num        get the user input.
 *
 * \return  None.
 */
static void App_ConsoleGetNum(uint32_t *num);

static int32_t App_mcanRegisterInterrupt(uint32_t intNum, void f(uintptr_t));

#if 0
#if defined (SOC_J721E)
static int32_t App_mcanConfigureIrqRouter(uint32_t devId, uint32_t offset, uint32_t intNum);
#endif
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#define TCA6424_CMD_AUTO_INC            ((uint8_t) 0x80U)

/* Input status register */
#define TCA6424_REG_INPUT0              ((UInt8) 0x00U)
#define TCA6424_REG_INPUT1              ((UInt8) 0x01U)
#define TCA6424_REG_INPUT2              ((UInt8) 0x02U)

/* Output register to change state of output BIT set to 1, output set HIGH */
#define TCA6424_REG_OUTPUT0             ((uint8_t) 0x04U)
#define TCA6424_REG_OUTPUT1             ((uint8_t) 0x05U)
#define TCA6424_REG_OUTPUT2             ((uint8_t) 0x06U)

/* Configuration register. BIT = '1' sets port to input, BIT = '0' sets
 * port to output */
#define TCA6424_REG_CONFIG0             ((uint8_t) 0x0CU)
#define TCA6424_REG_CONFIG1             ((uint8_t) 0x0DU)
#define TCA6424_REG_CONFIG2             ((uint8_t) 0x0EU)

void SetupI2CTransfer(I2C_Handle handle,  uint32_t slaveAddr,
                      uint8_t *writeData, uint32_t numWriteBytes,
                      uint8_t *readData,  uint32_t numReadBytes)
{
    bool status;
    I2C_Transaction i2cTransaction;

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = slaveAddr;
    i2cTransaction.writeBuf = (uint8_t *)&writeData[0];
    i2cTransaction.writeCount = numWriteBytes;
    i2cTransaction.readBuf = (uint8_t *)&readData[0];
    i2cTransaction.readCount = numReadBytes;
    status = I2C_transfer(handle, &i2cTransaction);
    if(FALSE == status)
    {
        printf("\n Data Transfer failed. \n");
    }
}

void padConfig_prcmEnable()
{
    /* UART Init */
    Board_initCfg   boardCfg;
    Board_STATUS    boardStatus;

#if defined (SOC_J721E)
    I2C_Params      i2cParams;
    I2C_Handle      handle = NULL;
    uint8_t         dataToSlave[4];
#endif

    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG;
#if (APP_ENABLE_UART_PRINT == 1)
    boardCfg |= BOARD_INIT_UART_STDIO;
#endif
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        App_ConsolePrintf("[Error] Board init failed!!\n");
    }

    /* Pin mux for CAN STB used in GESI board */
    *(volatile unsigned int *)(0x0011c0f4) = 0x20007;
    /* Pinmux for MAIN_MCAN4 */
    *(volatile unsigned int *)(0x0011c020) = 0x60006;
    *(volatile unsigned int *)(0x0011c024) = 0x60006;
    /* Pinmux for MAIN_MCAN5 */
    *(volatile unsigned int *)(0x0011c04c) = 0x60006;
    *(volatile unsigned int *)(0x0011c050) = 0x60006;
    /* Pinmux for MAIN_MCAN6 */
    *(volatile unsigned int *)(0x0011c054) = 0x60006;
    *(volatile unsigned int *)(0x0011c06C) = 0x60006;
    /* Pinmux for MAIN_MCAN7 */
    *(volatile unsigned int *)(0x0011c074) = 0x60006;
    *(volatile unsigned int *)(0x0011c078) = 0x60006;
    /* Pinmux for MAIN_MCAN9 */
    *(volatile unsigned int *)(0x0011c0cc) = 0x60006;
    *(volatile unsigned int *)(0x0011c0d0) = 0x60006;
    /* Pinmux for MAIN_MCAN11 */
    *(volatile unsigned int *)(0x0011c11c) = 0x60006;
    *(volatile unsigned int *)(0x0011c120) = 0x60006;

    /* GPIO initialization */
    GPIO_init();

    /* Enable CAN transceivers by setting the STB pins */
#if defined (SOC_AM65XX)
    GPIO_write(0, GPIO_PIN_HIGH);
    GPIO_write(1, GPIO_PIN_HIGH);
#elif defined (SOC_J721E)
    /* Enable the TCAN on GESI board.
     * Main Domain MCAN instances 4,5,6,7,9,11.
     */
    GPIO_write(0, GPIO_PIN_LOW);

    /* Enable MCU MCAN 1, WKUP_GPIO0_2. */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 2, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 2, GPIO_PIN_LOW);

    /* Enable MCU MCAN 0, WKUP_GPIO0_0, WKUP_GPIO0_54 */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 0, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 0, GPIO_PIN_HIGH);
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 54, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 54, GPIO_PIN_HIGH);

    /* Enable Main MCAN 2, GPIO0_127. */
    GPIO_write(1, GPIO_PIN_LOW);

    /*
     * Configuring TCA6424 IO Exp 2 with addr 0x22
     * This io expander is controlled by i2c0
     * For Main MCAN2 P13 and P14 should be set to 0, This should route the MCAN2 STB line to transciver.
     * For Main MCAN0 P06 and P07 should be set to 1.
     */
    /* I2C initialization */
    I2C_init();
    I2C_Params_init(&i2cParams);
    i2cParams.transferMode = I2C_MODE_BLOCKING;
    i2cParams.bitRate = I2C_400kHz;
    i2cParams.transferCallbackFxn = NULL;

    handle = I2C_open(0U, &i2cParams);

    dataToSlave[0] = TCA6424_REG_CONFIG0 | TCA6424_CMD_AUTO_INC;
    dataToSlave[1] = 0x0U;
    SetupI2CTransfer(handle, 0x22, &dataToSlave[0], 2, NULL, 0);

    dataToSlave[0] = TCA6424_REG_INPUT0 | TCA6424_CMD_AUTO_INC;
    dataToSlave[1] = 0x0U;
    dataToSlave[2] = 0x0U;
    dataToSlave[3] = 0x0U;
    SetupI2CTransfer(handle, 0x22, &dataToSlave[0], 1, &dataToSlave[1], 3);

    /* Set P06 and P07 to 1.
     * Set P13 and P14 to 0.
     */
    dataToSlave[0] = TCA6424_REG_OUTPUT0 | TCA6424_CMD_AUTO_INC;
    dataToSlave[1] |= 0xC0;
    dataToSlave[2] &= ~(0x18);
    SetupI2CTransfer(handle, 0x22, &dataToSlave[0], 1, &dataToSlave[1], 3);
#endif
}

int32_t main(void)
{
    int32_t                    configStatus = CSL_PASS;
    uint32_t                   mode         = 0U, loopCnt = 0U;
    MCAN_TxBufElement          txMsg;
    uint32_t                   numInst;

    /* Do Pad Config for UART and MCAN */
    padConfig_prcmEnable();

    App_ConsolePrintf("\n Starting Application...\n");
    App_ConsolePrintf("Available MCAN Module for usage:\n");
    numInst = sizeof(gMcanMods)/sizeof(gMcanMods[0]);
    for (loopCnt = 0U ; loopCnt < numInst ; loopCnt++)
    {
        App_ConsolePrintf("%d. BA: 0x%x - %s.\n",
                          loopCnt,
                          gMcanMods[loopCnt],
                          gMcanModsNames[loopCnt]);
    }

    App_ConsolePrintf("Enter MCAN Module to use:\n");
    App_ConsoleGetNum(&mode);

    if (mode >= numInst)
    {
        App_ConsolePrintf("Read from UART/CCS Console failed\n");
        return (0);
    }
    else
    {
        gMcanModAddr = gMcanMods[mode];
    }

    App_ConsolePrintf("MCAN Clock Configuration Successful.\n");

    App_ConsolePrintf("MCAN Node Type:\n");
    App_ConsolePrintf("1. Transmitter Side.\n");
    App_ConsolePrintf("2. Receiver Side.\n");
    App_ConsolePrintf("Enter type of the node:\n");
    App_ConsoleGetNum(&mode);

    /* CrossBar Configuration */
    configStatus = App_mcanXBarConfig();

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
    if (CSL_PASS == configStatus)
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
static int32_t App_mcanRegisterInterrupt(uint32_t intNum, void f(uintptr_t))
{
    int32_t configStatus = STW_SOK;
    OsalRegisterIntrParams_t    intrPrms;
    OsalInterruptRetCode_e      osalRetVal;
    HwiP_Handle                 hwiHandle = NULL;

    /* Enable CPU Interrupts and register ISR - MCAN0 Intr0 */
    Osal_RegisterInterrupt_initParams(&intrPrms);
    /* Populate the interrupt parameters */
    intrPrms.corepacConfig.arg              = (uintptr_t) NULL;
    intrPrms.corepacConfig.isrRoutine       = f;
    intrPrms.corepacConfig.priority         = 0U;
    intrPrms.corepacConfig.corepacEventNum  = 0U;
    intrPrms.corepacConfig.intVecNum        = intNum;

    /* Register interrupts */
    osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
    if(OSAL_INT_SUCCESS != osalRetVal)
    {
        configStatus = CSL_EFAIL;
    }
    return configStatus;
}

#if 0
#if defined (SOC_J721E)
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
        App_ConsolePrintf("Error in SciClient Interrupt Params Configuration!!!");
        App_ConsolePrintf("offset: %d \n", offset);
    }
    else
    {
        App_ConsolePrintf("SciClient Interrupt Params Configuration passed for offset: %d \n", offset);
    }
    return retVal;
}
#endif
#endif

static int32_t App_mcanXBarConfig(void)
{
    int32_t configStatus = STW_SOK;
#if defined (BUILD_MCU1_0)
    /* Running Code from Mcu R5 */
    /* MCU MCAN Inst 0 */
    configStatus =  App_mcanRegisterInterrupt(APP_MCU_MCAN_0_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MCU_MCAN_0_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MCU_MCAN_0_TS_INT, &App_mcanTSIntrISR);
    /* MCU MCAN Inst 1 */
    configStatus += App_mcanRegisterInterrupt(APP_MCU_MCAN_1_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MCU_MCAN_1_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MCU_MCAN_1_TS_INT, &App_mcanTSIntrISR);
#if 0
/* TODO: Enable testing of cross domain instances.
 *       Issue in sciclient to set the offset values for the device interrupts.
 */
    #if defined (SOC_J721E)
    /* Main MCAN Inst 2 */
    /* Needs Interrupt router configuration for getting interrupts to Mcu R5. */
    configStatus += App_mcanConfigureIrqRouter(TISCI_DEV_MCAN2, 0U, APP_MAIN_MCAN_2_INT0);
    configStatus += App_mcanRegisterInterrupt (APP_MAIN_MCAN_2_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanConfigureIrqRouter(TISCI_DEV_MCAN2, 1U, APP_MAIN_MCAN_2_INT1);
    configStatus += App_mcanRegisterInterrupt (APP_MAIN_MCAN_2_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanConfigureIrqRouter(TISCI_DEV_MCAN2, 0U, APP_MAIN_MCAN_2_TS_INT);
    configStatus += App_mcanRegisterInterrupt (APP_MAIN_MCAN_2_TS_INT, &App_mcanTSIntrISR);
    #endif
#endif
#else
    /* Running Code from Main R5 */
    #if defined (SOC_J721E)
    /* Main MCAN Inst 0 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_0_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_0_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_0_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 2 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_2_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_2_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_2_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 4 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_4_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_4_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_4_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 5 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_5_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_5_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_5_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 6 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_6_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_6_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_6_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 7 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_7_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_7_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_7_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 9 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_9_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_9_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_9_TS_INT, &App_mcanTSIntrISR);
    /* Main MCAN Inst 11 */
    configStatus =  App_mcanRegisterInterrupt(APP_MAIN_MCAN_11_INT0, &App_mcanIntr0ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_11_INT1, &App_mcanIntr1ISR);
    configStatus += App_mcanRegisterInterrupt(APP_MAIN_MCAN_11_TS_INT, &App_mcanTSIntrISR);
    #endif
#endif
    if(STW_SOK != configStatus)
    {
        App_ConsolePrintf("CrossBar/Interrupt Configuration failed.\n");
    }
    else
    {
        App_ConsolePrintf("CrossBar/Interrupt Configuration done.\n");
    }

    return configStatus;
}

static int32_t App_mcanConfig(void)
{
    uint32_t                   fdoe;
    int32_t                    configStatus = CSL_PASS;
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
    MCAN_getRevisionId(gMcanModAddr, &revId);
    App_ConsolePrintf("MCANSS Revision ID:\n");
    App_ConsolePrintf("scheme:0x%x\n", revId.scheme);
    App_ConsolePrintf("Business Unit:0x%x\n", revId.bu);
    App_ConsolePrintf("Module ID:0x%x\n", revId.modId);
    App_ConsolePrintf("RTL Revision:0x%x\n", revId.rtlRev);
    App_ConsolePrintf("Major Revision:0x%x\n", revId.major);
    App_ConsolePrintf("Custom Revision:0x%x\n", revId.custom);
    App_ConsolePrintf("Minor Revision:0x%x\n", revId.minor);
    /* Enable Auto wakeup */
    fdoe = MCAN_isFDOpEnable(gMcanModAddr);
    if ((uint32_t)TRUE == fdoe)
    {
        App_ConsolePrintf("CAN-FD operation is enabled through E-Fuse.\n");
    }
    else
    {
        App_ConsolePrintf("CAN-FD operation is disabled through E-Fuse.\n");
    }
    /* wait for memory initialization to happen */
    while (FALSE == MCAN_isMemInitDone(gMcanModAddr))
    {}
    /* Get endianess value */
    App_ConsolePrintf("Endianess Value: 0x%x\n",
                       MCAN_getEndianVal(gMcanModAddr));
    /* Put MCAN in SW initialization mode */
    MCAN_setOpMode(gMcanModAddr, MCAN_OPERATION_MODE_SW_INIT);
    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(gMcanModAddr))
    {}
    /* Initialize MCAN module */
    MCAN_init(gMcanModAddr, &initParams);
    /* Configure MCAN module */
    MCAN_config(gMcanModAddr, &configParams);
    /* Configure Bit timings */
    MCAN_setBitTime(gMcanModAddr, &bitTimes);
    /* Set Extended ID Mask */
    MCAN_setExtIDAndMask(gMcanModAddr, APP_MCAN_EXT_ID_AND_MASK);
    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig(gMcanModAddr, &msgRAMConfigParams);
    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter(gMcanModAddr, 0U, &stdFiltelem);
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode(gMcanModAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode(gMcanModAddr))
    {}
    return configStatus;
}

static void App_mcanIntr0ISR(uintptr_t arg)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(gMcanModAddr);
    MCAN_clearIntrStatus(gMcanModAddr, intrStatus);
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

static void App_mcanIntr1ISR(uintptr_t arg)
{
    uint32_t intrStatus;

    intrStatus = MCAN_getIntrStatus(gMcanModAddr);
    MCAN_clearIntrStatus(gMcanModAddr, intrStatus);
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

static void App_mcanTSIntrISR(uintptr_t arg)
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
    int32_t  testStatus = CSL_PASS;
    uint32_t loopCnt      = 1U;
    MCAN_ProtocolStatus protStatus;

    /* Enable Interrupts */
    MCAN_enableIntr(gMcanModAddr, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(gMcanModAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(gMcanModAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_0);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(gMcanModAddr,
                        MCAN_INTR_LINE_NUM_0,
                        1U);
    /* Enable Transmission interrupt */
    testStatus = MCAN_txBufTransIntrEnable(gMcanModAddr,
                                           1U,
                                           (uint32_t)TRUE);
    if (CSL_PASS != testStatus)
    {
        App_ConsolePrintf("\nError in enabling buffer Transmit interrupt...\n");
    }
    else
    {
        for (loopCnt = 1U; loopCnt < 16U; loopCnt++)
        {
            txMsg->dlc = loopCnt;
            /* Write message to Msg RAM */
            MCAN_writeMsgRam(gMcanModAddr,
                             MCAN_MEM_TYPE_BUF,
                             1U,
                             txMsg);
            /* Add request for transmission */
            testStatus = MCAN_txBufAddReq(gMcanModAddr, 1U);
            if (CSL_PASS != testStatus)
            {
                App_ConsolePrintf("\nError in Adding Transmission Request...\n");
                break;
            }
            while (gMcanIsrIntr0Flag)
            {}
            gMcanIsrIntr0Flag = 1U;
            MCAN_getProtocolStatus(gMcanModAddr, &protStatus);
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
                testStatus = CSL_EFAIL;
                break;
            }
        }
    }
    if (CSL_EFAIL == testStatus)
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
    int32_t              testStatus = CSL_PASS;
    MCAN_RxBufElement    rxMsg;
    MCAN_RxNewDataStatus newDataStatus;
    MCAN_ErrCntStatus    errCounter;

    /* Enable Interrupts */
    MCAN_enableIntr(gMcanModAddr, MCAN_INTR_MASK_ALL, (uint32_t)TRUE);
    MCAN_enableIntr(gMcanModAddr,
                    MCAN_INTR_SRC_RES_ADDR_ACCESS, (uint32_t)FALSE);
    /* Select Interrupt Line */
    MCAN_selectIntrLine(gMcanModAddr,
                        MCAN_INTR_MASK_ALL,
                        MCAN_INTR_LINE_NUM_1);
    /* Enable Interrupt Line */
    MCAN_enableIntrLine(gMcanModAddr,
                        MCAN_INTR_LINE_NUM_1,
                        1U);
    for (loopCnt = 1U; loopCnt < 16U; loopCnt++)
    {
        while (gMcanIsrIntr1Flag)
        {}
        gMcanIsrIntr1Flag = 1U;
        /* Checking for Errors */
        MCAN_getErrCounters(gMcanModAddr, &errCounter);
        if ((0U == errCounter.recErrCnt) &&
            (0U == errCounter.canErrLogCnt))
        {
            MCAN_getNewDataStatus(gMcanModAddr, &newDataStatus);
            MCAN_clearNewDataStatus(gMcanModAddr, &newDataStatus);
            MCAN_readMsgRam(gMcanModAddr,
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
                testStatus = CSL_EFAIL;
            }
        }
        else
        {
            App_ConsolePrintf(
            "\nError in reception with payload Bytes:%d",
            gMcanAppdataSize[txMsg->dlc]);
            testStatus = CSL_EFAIL;
        }
    }
    App_ConsolePrintf("\nReceived last message with following details:");
    App_mcanPrintRxMsg(&rxMsg);
    if (CSL_EFAIL == testStatus)
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
#if (APP_ENABLE_UART_PRINT == 1)
    UART_printf(printBuffer);
#else
    printf(printBuffer);
#endif

    /* End the varargs processing. */
    va_end(arguments);
}

static void App_ConsoleGetNum(uint32_t *num)
{
#if (APP_ENABLE_UART_PRINT == 1)
    uint32_t  status;
    status = UART_scanFmt("%d", num);
    if (status != S_PASS)
    {
        App_ConsolePrintf("UART Scan failed \n");
    }
#else
    scanf("%d", (int32_t *)num);
#endif
}
