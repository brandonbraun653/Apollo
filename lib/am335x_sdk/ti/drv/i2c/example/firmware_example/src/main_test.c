/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/board.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

#define I2C_EEPROM_ADDR_SIZE            (2)           /* in bytes */
#define I2C_EEPROM_TEST_LENGTH          (10)          /* Read (and write) test in bytes */

#define I2C_EEPROM_INSTANCE             (0)
#define I2C_EEPROM_ADDR                 (0x50)
#define I2C_SMBUS_DEV_ADDR              (0x22)
#define WRITE_SMBUS_COMMAND_CODE        (0x84)
#define READ_SMBUS_COMMAND_CODE         (0x80)
#define I2C_EEPROM_TEST_ADDR            (0x0001)      /* Read and write test start address */

#define I2C_TRANSACTION_TIMEOUT         (10000U)

#if defined(idkAM572x) || defined(idkAM574x)
#define I2C_TEST_INSTANCE1              (5U)           /* in bytes */
#elif defined(icev2AM335x) || defined(bbbAM335x)
#define I2C_TEST_INSTANCE1              (3U)           /* in bytes */
#elif defined(idkAM437x)
#define I2C_TEST_INSTANCE1              (3U)           /* in bytes */
#define I2C_TEST_INSTANCE2              (4U)           /* in bytes */
#endif

#define Sleep Task_sleep

#ifndef IO_CONSOLE
#define I2C_log                UART_printf
#else
#define I2C_log                printf
#endif

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

extern void UART_printf(const char *pcString, ...);

/* Data compare function */
bool CompareData(char *expData, char *rxData, unsigned int length);

#if defined(idkAM437x)
/* Configure pin mux for unused I2C PRU GPI/GPO pins */
void pruGpioMuxConfigI2cUnused(void);
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

#if defined (idkAM572x) || defined (idkAM574x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0xD5, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x32, 0x49, 0x44};
#elif defined (idkAM571x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x31, 0x49, 0x44};
#elif defined (SOC_AM335x) || defined (SOC_AM437x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x31, 0x49, 0x44};
#endif

#if defined (idkAM437x)
#define I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C    ( 2 )   // number of ICSS PRU GPO pins unused per I2C instance
#define I2C_MAX_NUM_TEST_INSTANCE               ( 2 )   // maximum number test I2C instances
#define I2C_NUM_PRU_GPIO_PINS_UNUSED            ( I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C * I2C_MAX_NUM_TEST_INSTANCE )
static I2C_PRU_IOPinMuxAttrs i2cPruGpioPinsUnused[I2C_NUM_PRU_GPIO_PINS_UNUSED] = 
{
#if !defined (AM437X_ICSS0)
    // These AM437x IDK ICSS0 pins are unused.
    {0x44E108F0,  8, 0x6, 0x5}, // I2C0 sclOutputPin
    {0x44E108F4,  9, 0x6, 0x5}, // I2C0 sdaInputPin
    {0x44E108F8, 10, 0x6, 0x5}, // I2C1 sclOutputPin
    {0x44E108FC, 11, 0x6, 0x5}, // I2C1 sdaInputPin
#else   // AM437X_ICSS0
    // These AM437x IDK ICSS1 pins are unused.
    {0x44E10880,  8, 0x6, 0x5}, // I2C0 sclOutputPin
    {0x44E10884,  9, 0x6, 0x5}, // I2C0 sdaInputPin
    {0x44E10830, 10, 0x6, 0x9}, // I2C1 sclOutputPin
    {0x44E10834, 11, 0x6, 0x9}, // I2C1 sdaInputPin
#endif  // AM437X_ICSS0
};
#endif

/*
 *  ======== test function ========
 */
void i2c_test(UArg arg0, UArg arg1)
{
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Transaction i2cTransaction;
    char txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char rxBuf[4*I2C_EEPROM_TEST_LENGTH];
    bool copyStatus;
    int32_t status = 0;
    I2C_SwIPAttrs i2c_cfg;

#if defined (I2C_TEST_INSTANCE1)
    /* testing instance at 100KHz board rate */
    I2C_log("\n I2C Test: Instance %d: Baud Rate 100KHz: \n ", I2C_TEST_INSTANCE1);

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */
    memcpy(&txBuf[I2C_EEPROM_ADDR_SIZE], eepromTestData, I2C_EEPROM_TEST_LENGTH);

    ///I2C_log("\n size of I2C_config %d. \n", sizeof(I2C_config));
    I2C_init();

    I2C_Params_init(&i2cParams);
    
    /* BitRate : 100 Kbps */
    i2cParams.bitRate = I2C_100kHz;

    handle = I2C_open(I2C_TEST_INSTANCE1, &i2cParams);

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    status = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_SUCCESS != status)
    {
        I2C_log("\n Error: Standard Write Data Transfer failed. \n");
        I2C_log("\n Some tests have failed. \n");
        while(1);
    }

    Sleep(1000);

    /* Read from EEPROM */
    memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    status = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_SUCCESS != status)
    {
        I2C_log("\n Error: Standard Read Data Transfer failed. \n");
        I2C_log("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        copyStatus = CompareData(&eepromTestData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
        if(TRUE != copyStatus)
        {
            I2C_log("\n Error: Standard Data Mismatch \n");
            I2C_log("\n Some tests have failed. \n");
            while(1);
        }
    }

#endif

    I2C_log("\n All tests have passed. \n");
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Handle       task;
    Error_Block       eb;
    Task_Params       taskParams;
    Board_initCfg     boardCfg;
    Board_STATUS      boardStatus;
    I2C_SwIPAttrs     i2c_cfg;

    Error_init(&eb);

#if defined (I2C_TEST_INSTANCE1)
    /* Initialize the I2C fw configuration */
    I2C_socInitFwCfg();
    
    /* Get the default I2C init configurations */
    I2C_socGetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */

    /* Set the default I2C init configurations */
    I2C_socSetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);
#endif

#if defined (idkAM572x) || defined (idkAM574x) || defined (idkAM571x)
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
#endif
#if defined(icev2AM335x) || defined(idkAM437x) || defined(bbbAM335x)
    boardCfg = BOARD_INIT_PLL| BOARD_INIT_MODULE_CLOCK |  BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
#endif
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        return (0);
    }

#if defined(idkAM437x)
    pruGpioMuxConfigI2cUnused();
#endif    
    
    Task_Params_init(&taskParams);
#ifndef _TMS320C6X
    taskParams.priority = 10;
#endif
    taskParams.instance->name = "i2cTest1";
    task = Task_create(i2c_test, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    return (0);
}

/*
 *  ======== CompareData ========
 */
bool CompareData(char *expData, char *rxData, unsigned int length)
{
    uint32_t idx = 0;
    uint32_t match = 1;
    bool retVal = false;

    for(idx = 0; ((idx < length) && (match != 0)); idx++)
    {
        if(*expData != *rxData) match = 0;
        expData++;
        rxData++;
    }

    if(match == 1) retVal = true;

    return retVal;
}

#if defined(idkAM437x)
/* Configure pin mux for unused I2C PRU GPI/GPO pins */
void pruGpioMuxConfigI2cUnused(void)
{
    uint32_t idx;
    uint32_t regVal;
    
#ifdef I2C_TEST_INSTANCE1    
    for (idx = 0; idx < I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C; idx++)
    {
        regVal = *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr);        
        regVal &= I2C_PRU_GPI_SELECT_MASK;
        regVal |= I2C_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(i2cPruGpioPinsUnused[idx].inputModeVal);
        *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr) = regVal;
    }
#endif

#ifdef I2C_TEST_INSTANCE2
    for (idx = I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C; idx < I2C_NUM_PRU_GPIO_PINS_UNUSED; idx++)
    {
        regVal = *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr);        
        regVal &= I2C_PRU_GPI_SELECT_MASK;
        regVal |= I2C_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(i2cPruGpioPinsUnused[idx].inputModeVal);
        *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr) = regVal;
    }
#endif
}
#endif // defined(idkAM437x)