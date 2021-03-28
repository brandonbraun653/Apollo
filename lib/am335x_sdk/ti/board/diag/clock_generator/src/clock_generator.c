/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file  clock_generator.c
 *
 * \brief This file contains clock generator test functions.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#if defined(SOC_K2G) || defined(SOC_J721E)
#include "diag_common_cfg.h"
#endif

#include "board.h"
#include "board_cfg.h"

#if defined(SOC_J721E)
#include "board_i2c_io_exp.h"

/* Platform test return type */
typedef short TEST_STATUS;

/* Platform test return codes */
#define TEST_PASS               (0)
#define TEST_FAIL               (-1)

#define NUM_CLOCK_GEN           (3U)
#endif

#if defined(SOC_K2G)
#define NUM_CLOCK_GEN           (1U)
#endif

typedef enum
{
    REG_SIZE_8 = 0,
    REG_SIZE_16 = 1
}regSize_t;

typedef enum
{
    CDCE937_ETHERNET = 0,
    CDCI6214_SERDES = 1,
    CDCI6214_QSGMII = 2,
    CDCEL937_PERIPH = 3
}clockGenMod_t;

typedef struct clockGenCfg
{
    char clkGenName[20];
    regSize_t regSize;
    clockGenMod_t clockGenModule;
    int32_t clkGenInst;
    uint8_t slaveAddr;
}clockGenCfg_t;

#if defined(SOC_K2G)
clockGenCfg_t clockConfig[NUM_CLOCK_GEN] =
{
    {
        "Ethernet",
        REG_SIZE_8,
        CDCE937_ETHERNET,
        BOARD_CLOCK_GENERATOR_INSTANCE,
        BOARD_I2C_CLOCK_GENERATOR
    }
};
#elif defined(SOC_J721E)
clockGenCfg_t clockConfig[NUM_CLOCK_GEN] =
{
    {
        "Serdes 2",
        REG_SIZE_16,
        CDCI6214_SERDES,
        BOARD_CLOCK_GENERATOR_INSTANCE,
        BOARD_I2C_CLOCK_GENERATOR2_ADDR1
    },
    {
        "QSGMII",
        REG_SIZE_16,
        CDCI6214_QSGMII,
        BOARD_CLOCK_GENERATOR_INSTANCE,
        BOARD_I2C_QSGMII_CLOCK_GENERATOR_ADDR1
    },
    {
        "Peripheral",
        REG_SIZE_8,
        CDCEL937_PERIPH,
        BOARD_CLOCK_GENERATOR_INSTANCE,
        BOARD_I2C_PERI_CLOCK_GENERATOR
    }
};
#endif

extern I2C_config_list I2C_config;
extern void BOARD_delay(uint32_t usecs);

/**
 *  \brief    This function executes clock generator detection test
 *
 *  \param    void   
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS clock_generator_detect_test(int32_t clkIndex)
{
	uint32_t index;
	I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    uint8_t tx[2];
    uint8_t rx[2];
	I2C_Transaction i2cTransaction;
    int32_t rdCnt;
    int32_t wrCnt;
	
	for (index=0; I2C_config[index].fxnTablePtr != NULL; index++)
	{
		((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
	}

	I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(clockConfig[clkIndex].clkGenInst, &i2cParams);
	if(handle == NULL)
	{
		UART_printf("I2C Handle open failed");
		return(TEST_FAIL);
	}

    if(clockConfig[clkIndex].regSize == REG_SIZE_16)
    {
        rdCnt = 2;
        wrCnt = 2;
    }
    else /* REG_SIZE_8 */
    {
        rdCnt = 1;
        wrCnt = 1;
    }

	I2C_transactionInit(&i2cTransaction);

    i2cTransaction.slaveAddress = clockConfig[clkIndex].slaveAddr;
    i2cTransaction.writeBuf = &tx;
    i2cTransaction.writeCount = wrCnt;
    i2cTransaction.readBuf = &rx;
    i2cTransaction.readCount = rdCnt;
    if(clockConfig[clkIndex].clockGenModule == CDCEL937_PERIPH)
    {
        tx[0] = 0x00 | 0x80;
    }
    else
    {
        tx[0] = 0x00;
    }
    tx[1] = 0x00;
    rx[0] = 0x00;
    rx[1] = 0x00;
    I2C_transfer(handle, &i2cTransaction);
    BOARD_delay(1000);
    if(rx[0] == 0x00 && rx[1] == 0x00)
    {
        UART_printf ("Clock generator Detection Failed!\n");
        I2C_close(handle);
        return(TEST_FAIL);
    }

    UART_printf ("\nClock generator Detection Successful!\n");

    I2C_close(handle);

    return (TEST_PASS);
}

/**
 *  \brief    This function executes clock generator probe test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS clock_generator_probe_test(void)
{
	TEST_STATUS testStatus;
	int8_t op;

	UART_printf("Probe the clock generator clock outputs\n");
	UART_printf("Are the signals generated properly ? \n");
	UART_printf("Press 'Y' to confirm, any other key to deny \n");
	UART_scanFmt("%c",&op);
	if(op == 'Y' || op == 'y')
	{
		testStatus = TEST_PASS;
	}
	else
	{
		testStatus = TEST_FAIL;
	}
	return(testStatus);
}

/**
 *  \brief    This function is used to perform Clock generator detection
 *            test and Clock generator probe test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_clock_generator_test(void)
{
    TEST_STATUS testStatus = TEST_FAIL;
    uint32_t index;

#if defined(SOC_J721E)
    Board_I2cInitCfg_t i2cCfg;
    int32_t boardDetect = 0;
#endif
    UART_printf("\nRunning Clock generator Detect Test\n");

#if defined(SOC_J721E)
    /* Quad ENET Expansion board detect */
    if(Board_detectBoard(BOARD_ID_ENET))
    {
        boardDetect = 1;
    }

    /* Bring CDCI6214_SERDES reset out */
    i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    Board_i2cIoExpInit();
    /* Setting the CDCI2_RSTz direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  THREE_PORT_IOEXP,
                                  PORTNUM_1,
                                  PIN_NUM_7,
                                  PIN_DIRECTION_OUTPUT);
    /* Setting the CDCI2_RSTz line to high */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              THREE_PORT_IOEXP,
                              PORTNUM_1,
                              PIN_NUM_7,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cIoExpDeInit();
#endif

    for(index = 0; index < NUM_CLOCK_GEN; index++)
    {
#if defined(SOC_J721E)
        enableI2C(CSL_I2C0_CFG_BASE);

        if(clockConfig[index].clockGenModule == CDCI6214_QSGMII && boardDetect)
        {
            /* Reset */
            i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
            i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
            i2cCfg.enableIntr = false;
            Board_setI2cInitConfig(&i2cCfg);
            /* CDCI6214_SERDES in reset */
            Board_i2cIoExpInit();
            /* Setting the CDCI2_RSTz direction as output */
            Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                          THREE_PORT_IOEXP,
                                          PORTNUM_1,
                                          PIN_NUM_7,
                                          PIN_DIRECTION_OUTPUT);
            /* Setting the CDCI2_RSTz line to Low */
            Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                      THREE_PORT_IOEXP,
                                      PORTNUM_1,
                                      PIN_NUM_7,
                                      GPIO_SIGNAL_LEVEL_LOW);
            /* Enable I2C lines */
            /* Setting the I2C mux select pin direction as output */
            Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                          THREE_PORT_IOEXP,
                                          PORTNUM_2,
                                          PIN_NUM_2,
                                          PIN_DIRECTION_OUTPUT);
            /* Setting the I2C mux select pin line high */
            Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                      THREE_PORT_IOEXP,
                                      PORTNUM_2,
                                      PIN_NUM_2,
                                      GPIO_SIGNAL_LEVEL_HIGH);
            Board_i2cIoExpDeInit();

            UART_printf("Testing %s clock generator\n", clockConfig[index].clkGenName);
            testStatus = clock_generator_detect_test(index);
        }
        else if(clockConfig[index].clockGenModule == CDCI6214_QSGMII && (boardDetect == 0))
        {
            continue;
        }
        else
        {
            UART_printf("Testing %s clock generator\n", clockConfig[index].clkGenName);
            testStatus = clock_generator_detect_test(index);
        }
#elif defined(SOC_K2G)
        UART_printf("Testing %s clock generator\n", clockConfig[index].clkGenName);
        testStatus = clock_generator_detect_test(index);
#endif
    }

    if(testStatus != TEST_PASS)
	{
		UART_printf("\nClock generator Detect Test Failed!!\n");
		return (testStatus);
	}
	else
	{
		UART_printf("\nClock generator Detect Test Passed!\n");
	}
	
    UART_printf("\n\nRunning Clock generator probe Test\n\n");

    testStatus = clock_generator_probe_test();
    if(testStatus != TEST_PASS)
    {
   	    UART_printf("\nClock generator probe Test Failed!!\n");
   		return (testStatus);
   	}
   	else
   	{
		UART_printf("\nClock generator probe Test Passed!\n");
	}

    return (testStatus);
}

/**
 * \brief This function performs clock generatorTest test
 *
 * \param void
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
static TEST_STATUS clockgeneratorTest(void)
{
	TEST_STATUS testStatus = 0;

	UART_printf("\n**********************************\n");
	UART_printf(  "       CLOCK GENERATOR Test       \n");
	UART_printf(  "**********************************\n");

	testStatus = run_clock_generator_test();
	if(testStatus != 0)
	{
		UART_printf("\nClock generator Test Failed!\n");
	}
	else
	{
		UART_printf("\nClock generator Test Passed!\n");
	}

	UART_printf("\nClock generator Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

	return (testStatus);

} // clockgeneratorTest

/**
 * \brief Invokes clock generator test functions
 *
 */
int main(void)
{
    TEST_STATUS      testStatus;
    Board_initCfg    boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    /* Invoke Clock generator Test */
    testStatus = clockgeneratorTest();
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}
/* Nothing past this point */
