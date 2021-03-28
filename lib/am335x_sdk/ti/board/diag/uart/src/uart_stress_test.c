/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   uart_stress_test.c
 *
 *  \brief  UART diagnostic stress test main file
 *
 *  This file implements the UART diagnostic stress test to verify the
 *  UART TX and RX at maximum possible baud rate by receiving test string
 *  from host pc
 *
 *  Supported SoCs : AM65XX
 *
 *  Supported Platforms: am65xx_evm, am65xx_idk
 *
 */

#include "uart_stress_test.h"

uint8_t txBuf[TEST_DATA_LEN] __attribute__ ((section ("uartbuffer")));
uint8_t rxBuf[TEST_DATA_LEN] __attribute__ ((section ("uartbuffer")));

/**
 * \brief  Generate pattern function
 *
 * This function generates a test pattern to verify the UART interface
 * read/write access.
 *
 * \param   txBuf  [IN]   Transmit data buffer
 * \param   length [IN]   length of the buffer
 *
 */
static void GeneratePattern(uint8_t *txBuf, uint32_t length)
{
    uint32_t idx;
    uint32_t data = 48;

    for(idx = 0; idx < length; idx++)
    {
        txBuf[idx] = (uint8_t)data;
        data++;
        if(data > 126)
        {
            data = 48;
        }
    }
}

/**
 * \brief  UART stress test function
 *
 * This function initializes the specified UART instance for running
 * the stress test, based on a configuration parameters specified.
 * Writes data from the data buffer to the transmitter FIFO of UART
 * and reads data from the receiver FIFO to read buffer in the receiver.
 * Compares the read and write buffers to verify the data.
 *
 * \param   uartInstance  [IN]  UART instance
 *          setPort       [IN]  Variable to set the port number
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_UartStressTest(uint32_t uartInstance, uint8_t setPort)
{
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    uint32_t          ret = 0;
    uint32_t          index;
    uint32_t          failIndex;
    UART_HwAttrs uart_hwAttrs;
    uint8_t testPassMsg[] = "UART Stress Test Passed\n";
    uint8_t testFailMsg[] = "UART Stress Test Failed\n";
    uint8_t input = '\n';

    if(setPort == 1)
    {
        /* Enable MCU UART port */
        UART_socGetInitCfg(uartInstance, &uart_hwAttrs);
        uart_hwAttrs.baseAddr = CSL_MCU_UART0_BASE;
        uart_hwAttrs.enableInterrupt = 0;
        uart_hwAttrs.frequency = 96000000;
        UART_socSetInitCfg(uartInstance, &uart_hwAttrs);
    }
    if(setPort == 2)
    {
        /* Enable Wake-up UART port */
        UART_socGetInitCfg(uartInstance, &uart_hwAttrs);
        uart_hwAttrs.baseAddr = CSL_WKUP_UART0_BASE;
        uart_hwAttrs.enableInterrupt = 0;
        uart_hwAttrs.frequency = 96000000;
        UART_socSetInitCfg(uartInstance, &uart_hwAttrs);
    }
    else
    {
        UART_socGetInitCfg(uartInstance, &uart_hwAttrs);
        uart_hwAttrs.enableInterrupt = 0;
        UART_socSetInitCfg(uartInstance, &uart_hwAttrs);
    }

    UART_Params_init(&uartParams);

    uartParams.baudRate  = BAUDRATE_MAX;

    uart = UART_open(uartInstance, &uartParams);
    if(uart == NULL)
    {
        return -1;
    }

    /* Generate the data */
    GeneratePattern(txBuf, TEST_DATA_LEN);

    for(index = 0; index < TEST_DATA_LEN; index += FIFO_SIZE)
    {
        ret = UART_write(uart, (uint8_t *)&txBuf[index], FIFO_SIZE);
        if(!ret)
        {
            UART_close(uart);
            return -1;
        }

        ret = UART_read(uart,(uint8_t *)&rxBuf[index], FIFO_SIZE);
        if(ret != FIFO_SIZE)
        {
            UART_close(uart);
            return -1;
        }
    }

    /* Verify Data */
    if (BoardDiag_memCompare(&txBuf[0], &rxBuf[0], TEST_DATA_LEN, &failIndex) == false)
    {
        UART_write(uart,&input,1U);
        UART_write(uart,testFailMsg,sizeof(testFailMsg));
        UART_close(uart);
        return -1;
    }
    else
    {
        UART_write(uart,&input,1U);
        UART_write(uart,testPassMsg,sizeof(testPassMsg));
        UART_close(uart);
    }

    return 0;
}

#if defined(am65xx_evm)
/* Function to enable SoC UART1 */
static void BoardDiag_enableUART1Sel(void)
{
    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_5,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the UART1 SEL line to low */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_1,
                              PIN_NUM_5,
                              GPIO_SIGNAL_LEVEL_LOW);
}
#endif

/* Function to enable MCU UART selection */
static void BoardDiag_enableMCUUARTSel(void)
{
    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_6,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the MCU UART SEL line to low */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_1,
                              PIN_NUM_6,
                              GPIO_SIGNAL_LEVEL_HIGH);
}

/* Function to enable Wakeup UART selection */
static void BoardDiag_enableWkUPUARTSel(void)
{
    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_4,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the MCU UART SEL line to low */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_1,
                              PIN_NUM_4,
                              GPIO_SIGNAL_LEVEL_HIGH);
}


/**
 * \brief  main function
 *
 *  This function performs board initializations and calls UART stress test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    Board_initCfg boardCfg;
    int8_t ret;

    boardCfg = BOARD_INIT_UNLOCK_MMR |
               BOARD_INIT_PINMUX_CONFIG;

    Board_init(boardCfg);

    Board_i2cIoExpInit();
#if defined(am65xx_evm)
    BoardDiag_enableUART1Sel();
#endif
    BoardDiag_enableMCUUARTSel();
    BoardDiag_enableWkUPUARTSel();

    ret = BoardDiag_UartStressTest(BOARD_UART_INSTANCE, 0);
    if(ret != 0)
    {
        ret = -1;
    }
#if defined(am65xx_evm)
    ret = BoardDiag_UartStressTest(BOARD_UART1_INSTANCE, 0);
    if (ret != 0)
    {
        ret = -1;
    }
#endif
    ret = BoardDiag_UartStressTest(BOARD_UART_INSTANCE, 1);
    if (ret != 0)
    {
        ret = -1;
    }

    ret = BoardDiag_UartStressTest(BOARD_UART_INSTANCE, 2);
    if (ret != 0)
    {
        ret = -1;
    }

    return ret;
}
#endif /* #ifndef SPI_BOOT_FRAMEWORK */
