 /*
 *  Copyright (C) 2013-2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mcspiMasterSlave_spi1_spi2_v1.c
 *
 *  \brief This file contains the Master Slave application which demonstrates
 *         simple data transfer from McSPI master to slave using polled mode.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdio.h>
#include <ti/csl/csl_mcspi.h>
#include <ti/csl/soc.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
#define MCSPI_IN_CLK                (48000000U)
#define McSPI_DATA_COUNT            (256U)

#if defined (SOC_AM65XX) || defined (SOC_J721E)
#define MCSPI1_BASE_ADDRESS         (CSL_MCU_MCSPI2_CFG_BASE)
#define MCSPI2_BASE_ADDRESS         (CSL_MCSPI4_CFG_BASE)
#endif

/** \brief MCSPI Tx/Rx buffer base address */
#define MCSPI1_TX0_REG              (MCSPI1_BASE_ADDRESS + (MCSPI_TX0))
#define MCSPI1_RX0_REG              (MCSPI1_BASE_ADDRESS + (MCSPI_RX0))

#define MCSPI2_TX0_REG              (MCSPI2_BASE_ADDRESS + (MCSPI_TX0))
#define MCSPI2_RX0_REG              (MCSPI2_BASE_ADDRESS + (MCSPI_RX0))

/** \brief MCSPI Channel number*/
#define MCSPI_CH_NUM                (0U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint32_t          gChNum  = 0U;
uint8_t           gRxBuffer[McSPI_DATA_COUNT];
uint8_t           gTxBuffer[McSPI_DATA_COUNT];
uint8_t           gTxSlvBuffer[McSPI_DATA_COUNT];
uint8_t           gRxSlvBuffer[McSPI_DATA_COUNT];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static void McSPI1SetUp(void);
static void McSPI2SetUp(void);
static void McSPIMSTransfer(uint16_t length);
static void McSPIVerifyData(void);
static void McSPIInitializeBuffers(void);
static void McSPIMSPolledModeTransfer(uint16_t length);
static void McSPIMasterSlaveAppTest(void);
static void McSPIAppUtilsPrint (const char *pcString, ...);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int main(void)
{

    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        McSPIAppUtilsPrint("[Error] Board init failed!!\n");
    }

    McSPIAppUtilsPrint("\nMasterSlave Application Started");
    McSPIAppUtilsPrint("\nThis application tests MCU McSPI2 and MAIN McSPI4 ");
    McSPIAppUtilsPrint("instance which are connected internally ");
    McSPIAppUtilsPrint("\nThe Mode of transfer is Polled Mode");

    McSPIMasterSlaveAppTest();

    return 0;
}

static void McSPIMasterSlaveAppTest(void)
{

    /* Do the necessary set up configurations for McSPI.*/
    McSPI1SetUp();
    McSPI2SetUp();

    McSPIInitializeBuffers();

    McSPIMSTransfer(McSPI_DATA_COUNT);

    /* Verify whether the data written by Master and the one read by
     * Slave are Equal */
    McSPIVerifyData();
}

/*
** This function will call the necessary McSPI APIs which will configure the
** McSPI controller.
*/
static void McSPI1SetUp(void)
{
    uint32_t status = 1U; /* FALSE */

    /* Reset the McSPI instance.*/
    McSPIReset(MCSPI1_BASE_ADDRESS);

    /* CLOCKACTIVITY bit - OCP and Functional clocks are maintained           */
    /* SIDLEMODE     bit - Ignore the idle request and configure in normal mode
     */
    /* AUTOIDLE      bit - Disable (OCP clock is running free, no gating)     */
    MCSPISysConfigSetup(MCSPI1_BASE_ADDRESS, MCSPI_CLOCKS_OCP_ON_FUNC_ON,
                        MCSPI_SIDLEMODE_NO, MCSPI_WAKEUP_DISABLE,
                        MCSPI_AUTOIDLE_OFF);

    /* Enable chip select pin.*/
    McSPICSEnable(MCSPI1_BASE_ADDRESS);

    /* Enable master mode of operation.*/
    McSPIMasterModeEnable(MCSPI1_BASE_ADDRESS);

    /* Perform the necessary configuration for master mode. */
    status = McSPIMasterModeConfig(MCSPI1_BASE_ADDRESS, MCSPI_SINGLE_CH,
                                   MCSPI_TX_RX_MODE,
                                   MCSPI_DATA_LINE_COMM_MODE_1,
                                   gChNum);

    if (0U == status)
    {
        McSPIAppUtilsPrint("\nCommunication not supported by SPIDAT[1:0]");
    }

    /* Configure the McSPI bus clock depending on clock mode. */
    McSPIClkConfig(MCSPI1_BASE_ADDRESS, MCSPI_IN_CLK, MCSPI_IN_CLK, gChNum,
                   MCSPI_CLK_MODE_0);

    /* Configure the word length.*/
    McSPIWordLengthSet(MCSPI1_BASE_ADDRESS, MCSPI_WORD_LENGTH(8), gChNum);

    /* Set polarity of SPIEN to low.*/
    McSPICSPolarityConfig(MCSPI1_BASE_ADDRESS,
                          (MCSPI_CH0CONF_EPOL_ACTIVELOW <<
                           MCSPI_CH0CONF_EPOL_SHIFT), gChNum);

    /* Enable the transmitter FIFO of McSPI peripheral.*/
    McSPITxFIFOConfig(MCSPI1_BASE_ADDRESS, MCSPI_TX_FIFO_ENABLE, gChNum);

    /* Enable the receiver FIFO of McSPI peripheral.*/
    McSPIRxFIFOConfig(MCSPI1_BASE_ADDRESS, MCSPI_RX_FIFO_ENABLE, gChNum);
}

/*
** This function will call the necessary McSPI APIs which will configure the
** McSPI controller.
*/
static void McSPI2SetUp(void)
{
    uint32_t status = 1U; // FALSE

    /* Reset the McSPI instance.*/
    McSPIReset(MCSPI2_BASE_ADDRESS);

    /* CLOCKACTIVITY bit - OCP and Functional clocks are maintained           */
    /* SIDLEMODE     bit - Ignore the idle request and configure in normal mode
     */
    /* AUTOIDLE      bit - Disable (OCP clock is running free, no gating)     */
    MCSPISysConfigSetup(MCSPI2_BASE_ADDRESS, MCSPI_CLOCKS_OCP_ON_FUNC_ON,
                        MCSPI_SIDLEMODE_NO, MCSPI_WAKEUP_DISABLE,
                        MCSPI_AUTOIDLE_OFF);

    /* Enable chip select pin.*/
    McSPICSEnable(MCSPI2_BASE_ADDRESS);

    /* Enable slave mode of operation.*/
    McSPISlaveModeEnable(MCSPI2_BASE_ADDRESS);

    /* Configure the Pin Direction.*/
    status = MCSPIPinDirSet(MCSPI2_BASE_ADDRESS, MCSPI_TX_RX_MODE,
                            MCSPI_DATA_LINE_COMM_MODE_1, gChNum);

    if (1 == status)
    {
        McSPIAppUtilsPrint("\nCommunication not supported by SPIDAT[1:0]");
    }

    /* Configure the word length.*/
    McSPIWordLengthSet(MCSPI2_BASE_ADDRESS, MCSPI_WORD_LENGTH(8), gChNum);

    /* Set polarity of SPIEN to low.*/
    McSPICSPolarityConfig(MCSPI2_BASE_ADDRESS,
                          (MCSPI_CH0CONF_EPOL_ACTIVELOW <<
                           MCSPI_CH0CONF_EPOL_SHIFT), gChNum);

    /* Enable the transmitter FIFO of McSPI peripheral.*/
    McSPITxFIFOConfig(MCSPI2_BASE_ADDRESS, MCSPI_TX_FIFO_ENABLE, gChNum);

    /* Enable the receiver FIFO of McSPI peripheral.*/
    McSPIRxFIFOConfig(MCSPI2_BASE_ADDRESS, MCSPI_RX_FIFO_ENABLE, gChNum);
}

static void McSPIInitializeBuffers(void)
{
    uint32_t index = 0;

    for (index = 0; index < McSPI_DATA_COUNT; index++)
    {
        /* Initialize the gTxBuffer McSPI1 with a known pattern of data */
        gTxBuffer[index] = (uint8_t) index + 1U;
        /* Initialize the gRxBuffer McSPI1 with 0 */
        gRxBuffer[index] = (uint8_t) 0;
    }
    for (index = 0; index < McSPI_DATA_COUNT; index++)
    {
        /* Initialize the gTxBuffer McSPI1 with a known pattern of data */
        gTxSlvBuffer[index] = (uint8_t) index + 1U;
        /* Initialize the gRxBuffer McSPI1 with 0 */
        gRxSlvBuffer[index] = 0;
    }
}

static void McSPIMSTransfer(uint16_t length)
{
    /* Enable the McSPI channel for communication.*/
    McSPIChannelEnable(MCSPI2_BASE_ADDRESS, gChNum);

    /* SPIEN line is forced to low state.*/
    McSPICSAssert(MCSPI2_BASE_ADDRESS, gChNum);

    /* Enable the McSPI channel for communication.*/
    McSPIChannelEnable(MCSPI1_BASE_ADDRESS, gChNum);

    /* SPIEN line is forced to low state.*/
    McSPICSAssert(MCSPI1_BASE_ADDRESS, gChNum);

    /* Initiate Transfer */
    McSPIMSPolledModeTransfer(length);

    /* Force SPIEN line to the inactive state.*/
    McSPICSDeAssert(MCSPI1_BASE_ADDRESS, gChNum);

    /* Disable the McSPI channel.*/
    McSPIChannelDisable(MCSPI1_BASE_ADDRESS, gChNum);

    /* Force SPIEN line to the inactive state.*/
    McSPICSDeAssert(MCSPI2_BASE_ADDRESS, gChNum);

    /* Disable the McSPI channel.*/
    McSPIChannelDisable(MCSPI2_BASE_ADDRESS, gChNum);
}

static void McSPIMSPolledModeTransfer(uint16_t length)
{
    uint32_t          channelStatus = 0;
    volatile uint32_t timeout1      = 0xFFFFU;
    uint8_t          *p_rx;
    uint8_t          *p_tx;
    uint8_t          *p_rxSlv;
    uint8_t          *p_txSlv;

    p_tx    = gTxBuffer;
    p_rx    = gRxBuffer;
    p_txSlv = gTxSlvBuffer;
    p_rxSlv = gRxSlvBuffer;

    while (0 != length)
    {
        timeout1      = 0xFFFF;
        channelStatus = McSPIChannelStatusGet(MCSPI2_BASE_ADDRESS, gChNum);
        while (0 == (channelStatus & MCSPI_CH0STAT_TXS_MASK))
        {
            channelStatus = 0;
            channelStatus = McSPIChannelStatusGet(MCSPI2_BASE_ADDRESS, gChNum);
            --timeout1;
            if (0 == timeout1)
            {
                McSPIAppUtilsPrint("\nMAIN McSPI4 TX Timed out!!");
                while (1) ;
            }
        }
        McSPITransmitData(MCSPI2_BASE_ADDRESS, (uint32_t) (*p_txSlv++), gChNum);

        timeout1      = 0xFFFF;
        channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, gChNum);
        while (0 == (channelStatus & MCSPI_CH0STAT_TXS_MASK))
        {
            channelStatus = 0;
            channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, gChNum);
            --timeout1;
            if (0 == timeout1)
            {
                McSPIAppUtilsPrint("\nMCU McSPI2 TX Timed out!!");
                while (1) ;
            }
        }
        McSPITransmitData(MCSPI1_BASE_ADDRESS, (uint32_t) (*p_tx++), gChNum);

        timeout1      = 0xFFFF;
        channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, gChNum);
        while (0 == (channelStatus & MCSPI_CH0STAT_RXS_MASK))
        {
            channelStatus = 0;
            channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, gChNum);
            --timeout1;
            if (0 == timeout1)
            {
                McSPIAppUtilsPrint("\nMCU McSPI2 RX Timed out!!");
                while (1) ;
            }
        }
        *p_rx++ = (uint8_t)  McSPIReceiveData(MCSPI1_BASE_ADDRESS, gChNum);

        timeout1      = 0xFFFF;
        channelStatus = McSPIChannelStatusGet(MCSPI2_BASE_ADDRESS, gChNum);
        while (0 == (channelStatus & MCSPI_CH0STAT_RXS_MASK))
        {
            channelStatus = 0;
            channelStatus = McSPIChannelStatusGet(MCSPI2_BASE_ADDRESS, gChNum);
            --timeout1;
            if (0 == timeout1)
            {
                McSPIAppUtilsPrint("\nMAIN McSPI4 RX Timed out!!");
                while (1) ;
            }
        }
        *p_rxSlv++ = (uint8_t)  McSPIReceiveData(MCSPI2_BASE_ADDRESS, gChNum);

        length--;
    }
}

/*
** This function will verify the data written to and read from flash and print
** the appropriate message.
*/
static void McSPIVerifyData(void)
{
    uint32_t index = 0;
    uint32_t error = 0;

    for (index = 0; index < McSPI_DATA_COUNT; index++)
    {
        if ((gRxSlvBuffer[index] != gTxBuffer[index]) ||
            (gTxSlvBuffer[index] != gRxBuffer[index]))
        {
            McSPIAppUtilsPrint("\nData Mismatch found at index : %u\r", index);
            error = 1;
            break;
        }
    }

    if (error == 0)
    {
        McSPIAppUtilsPrint("\nThe data written by Master and the one read by ");
        McSPIAppUtilsPrint("Slave are Equal, Test Passed.");
    }
    else
    {
        McSPIAppUtilsPrint("\nThe data written by Master and the one read by ");
        McSPIAppUtilsPrint("Slave are not Equal, Test Failed. ");
    }
}

static void McSPIAppUtilsPrint (const char *pcString, ...)
{
    static char printBuffer[2000U];
    va_list arguments;

    /* Start the varargs processing. */
    va_start(arguments, pcString);
    vsnprintf (printBuffer, sizeof(printBuffer), pcString, arguments);

    printf(printBuffer);
    UART_printf(printBuffer);

    /* End the varargs processing. */
    va_end(arguments);

    return;
}

/********************************* End Of File ******************************/
