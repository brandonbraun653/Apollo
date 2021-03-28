/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 *  \file    platform_test.h
 *
 *  \brief  This file contains the common definitions for platform test
 *
 *****************************************************************************/

#ifndef _PLATFORM_TEST_H_
#define _PLATFORM_TEST_H_

#include "platform.h"
//#include "resource_mgr.h"

#define PTR_NULL		((void *) 0)

#define PLATFORM_TEST_VER "01.00.00"

/* Platform test return codes */
#define TEST_PASS     (0)
#define TEST_FAIL     (-1)

/* Default platform init flag values */
#define PLATFORM_INIT_FLAGS_PLL    (0)
#define PLATFORM_INIT_FLAGS_DDR    (0)
#define PLATFORM_INIT_FLAGS_TCSL   (1)
#define PLATFORM_INIT_FLAGS_PHY    (1)
#define PLATFORM_INIT_FLAGS_ECC    (1)

/* Default platform init config values */
#define PLATFORM_INIT_CONFIG_PLLM          (0)
#define PLATFORM_INIT_CONFIG_PLLD          (0)
#define PLATFORM_INIT_CONFIG_PREDIV        (0)
#define PLATFORM_INIT_CONFIG_POSTDIV       (0)
#define PLATFORM_INIT_CONFIG_MASTERCORE    (0)


#ifdef AUDIODC_DIAG_TESTS
/* Maximum supported platform test options */
#define PLATFORM_TEST_COUNT        (3)
#define PLATFORM_TEST_START        (0)
#define PLATFORM_AUTO_TEST_COUNT   (0)

#else
/* Maximum supported platform test options */
#define PLATFORM_TEST_COUNT        (27)
#define PLATFORM_TEST_START        (3)
#define PLATFORM_AUTO_TEST_COUNT   (20)
#endif

#define PLATFORM_MEM_TEST_START    (3)
#define PLATFORM_MEM_TEST_COUNT    (6)

/* UART settings  */
#define PLATFORM_TEST_UART_BAUD    (115200)

/* Flag to enable/disable auto execution for platform tests */
#ifdef ENABLE_AUTO_RUN
#define PLATFORM_TEST_AUTO_RUN  (1)
#else
#define PLATFORM_TEST_AUTO_RUN  (0)
#endif

//#define GALILEO_SIM_TEST         (1)

#define PLATFORM_TEST_AUTO_ALL    (0)
#define PLATFORM_TEST_AUTO_MEM    (1)
#define PLATFORM_TEST_GET_INFO    (98)
#define PLATFORM_TEST_ID_PROG     (99)

/** Value of system clock in Hz */
#define PLATFORM_TEST_SYS_CLK     (600000000)

#define PLATFORM_TEST_DEBUG 1

#if (PLATFORM_TEST_DEBUG)
#define IFDEBUGPRINT(x)   (x)
#else
#define IFDEBUGPRINT(x)
#endif

/** EEPROM and Board ID configuration defines */
#define EEPROM_ID_HEADER_LENGTH       (4)
#define EEPROM_ID_BOARD_LENGTH        (8)
#define EEPROM_ID_VERSION_LENGTH      (4)
#define EEPROM_ID_SERIAL_NO_LENGTH    (12)
#define EEPROM_ID_CONFIG_LENGTH       (32)

#define EEPROM_ID_HEADER_ADDR         (0)
#define EEPROM_ID_BOARD_ADDR          (EEPROM_ID_HEADER_ADDR + EEPROM_ID_HEADER_LENGTH)
#define EEPROM_ID_VERSION_ADDR        (EEPROM_ID_BOARD_ADDR + EEPROM_ID_BOARD_LENGTH)
#define EEPROM_ID_SERIAL_NO_ADDR      (EEPROM_ID_VERSION_ADDR + EEPROM_ID_VERSION_LENGTH)
#define EEPROM_ID_CONFIG_ADDR         (EEPROM_ID_SERIAL_NO_ADDR + EEPROM_ID_SERIAL_NO_LENGTH)

#define UART_ID_DB9                    (0)
#define UART_ID_UART2USB               (1)
#define UART_ID_SERIAL_HEADER          (2)

/** Indicates audio test in loopback mode */
#define AUDIO_TEST_MODE_LOOPBACK       (0)
/** Indicates audio test in playback mode */
#define AUDIO_TEST_MODE_PLAYBACK       (1)

/* Platform test return type */
typedef	int16_t TEST_STATUS;

/**
 *  \brief Platform test table structure
 *
 */
typedef struct diagTestTable_s
{
    uint8_t testName[50];
	TEST_STATUS (*testFunction)(void *);
	void  *args;
	uint32_t pass;
	uint32_t fail;
} diagTestTable_t;

/*
   Intention of test arguments is to maintain all the configurations
   in one place instead of fixing in each test function.
   Test arguments are primarily required for memory test functions
   for communicating the information like sector, block, size etc.
   Test arguments are provided for all the tests for
   maintaining consistent API signature and for future use.
   Some of the test functions may not use the test arguments in the
   current implementation.

   Test argument structures shall be extended during the test
   implementation based on the need.
*/

/**
 *  \brief DDR test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun; /** Flag to enable/disable test auto run */
    uint32_t region1;
    uint32_t region2;
    uint32_t count;
	uint32_t clkSel;
} ddrTestArgs_t;

/**
 *  \brief NAND test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;     /** Flag to enable/disable test auto run */
    uint32_t blockNum;    /** NAND flash block number to execute read/write */
    uint32_t blockLen;    /** Length in bytes to read/write from NAND flash */
    uint32_t devId;       /** NAND flash device ID */
    uint8_t  testPattern; /** Test Pattern */

} nandTestArgs_t;

/**
 *  \brief QSPI flash test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;     /** Flag to enable/disable test auto run */
    uint32_t sectNum;     /** QSPI flash sector number to execute read/write */
    uint32_t blockLen;    /** Length in bytes to read/write from QSPI flash */
    uint32_t devId;       /** QSPI flash device ID */
    uint8_t  testPattern; /** Test Pattern */

} qspiFlashTestArgs_t;

/**
 *  \brief SPI nor test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;     /** Flag to enable/disable test auto run */
    uint32_t sectNum;     /** NOR flash sector number to execute read/write */
    uint32_t blockLen;    /** Length in bytes to read/write from NOR flash */
    uint32_t devId;       /** NOR flash device ID */
    uint8_t  testPattern; /** Test Pattern */

} spiNorTestArgs_t;

/**
 *  \brief I2C EEPROM test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;    /** Flag to enable/disable test auto run */
    uint16_t offset;     /** EEPROM offset to execute read/write */
    uint16_t blockLen;   /** Length in bytes to read/write from EEPROM */
    uint8_t  i2cPortNum; /** EEPROM I2C port number */
    uint8_t  slaveAddr;  /** Slave address of I2C device */

} i2cEepromTestArgs_t;

/**
 *  \brief EMMC test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} emmcTestArgs_t;

/**
 *  \brief SD test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} sdTestArgs_t;

/**
 *  \brief PCIe test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;       /** Flag to enable/disable test auto run */
    uint8_t  mode;          /** Test mode */

} pcieTestArgs_t;

/**
 *  \brief DCAN test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} dcanTestArgs_t;

/**
 *  \brief HDMI test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} hdmiTestArgs_t;

/**
 *  \brief LCD test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} lcdTestArgs_t;

/**
 *  \brief Touch test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} touchTestArgs_t;

/**
 *  \brief Ethernet test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} ethernetTestArgs_t;

/**
 *  \brief UART test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;   /** Flag to enable/disable test auto run */
    uint32_t baudRate;  /** UART baudrate to run the test */
    uint8_t  uartPort;  /** UART port number */
    uint8_t  uartId;    /** UART port ID on EVM
                            0 - DB9 connector
                            1 - UART to USB port
                            2 - SoC Serial Header */
	uint8_t  loopback;  /** Flag to indicate UART loopback tesr
	                        0 - UART serial test on ports indicated by 'uartPort'
	                        1 - UART loopback test with ports indicated by uartPort'
	                            and 'uartLBPort' */
    uint8_t  uartLBPort; /** Second UART port number for loopback test */
    uint8_t  uartLBId;  /** Second UART port ID for loopback test
                            0 - DB9 connector
                            1 - UART to USB port
                            2 - SoC Serial Header */
} uartTestArgs_t;

/**
 *  \brief Audio clock test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;      /** Flag to enable/disable test auto run */
    uint32_t sysClk;       /** CPU clock value */
    uint32_t cptsCmpRate;  /** CPTS comparator rate */
    uint32_t tsCmpOutClks; /** TS comparator clock count */
    uint8_t  i2cPortNum;   /** CS2000 I2C port number */
    uint8_t  i2cSlaveAddr; /** I2C slave address for CS2000 */
    uint8_t  spiPortNum;   /** DAC 8550 SPI port number */
    uint32_t spiCs;        /** DAC 8550 SPI chip select */
    uint32_t spiClk;       /** SPI clock value */

} audioClkTestArgs_t;

/**
 *  \brief MLB test argument structure
 *
 */
typedef struct
{
    uint8_t autoRun; /** Flag to enable/disable test auto run */

} mlbTestArgs_t;

/**
 *  \brief Temperature sensor test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;      /** Flag to enable/disable test auto run */
    uint8_t  i2cPortNum;   /** Temperature sensor I2C port number */
    uint8_t  i2cSlaveAddr; /** I2C slave address for temperature sensor */
} tempSensorTestArgs_t;


/**
 *  \brief Audio test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;      /** Flag to enable/disable test auto run */
    uint8_t  mcaspNum;     /** McASP instance number */
    uint8_t  mode;         /** Mode of the test
    						   0 - Loopback Mode
    						   1 - Tone Play Mode */
} audioTestArgs_t;

/**
 *  \brief LED test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;      /** Flag to enable/disable test auto run */
} ledTestArgs_t;

/**
 *  \brief Expansion connector test argument structure
 *
 */
typedef struct
{
    uint8_t  autoRun;      /** Flag to enable/disable test auto run */
} expConnTestArgs_t;

/**
 *  \brief Test arguments for external tests
 *
 */
typedef struct
{
    uint8_t  autoRun;       /** Flag to enable/disable test auto run */
    uint8_t* testImageName; /** Name of the test Image */
} extTestArgs_t;


/**
 *  \brief    Diagnostic test main function
 *
 *  \return   Platform_STATUS
 */
Platform_STATUS diag_main (void);

/**
 *  \brief    Executes all the diagnostic tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 *  \return   TEST_STATUS
 */
TEST_STATUS run_external_tests(void *testArgs);

/**
 *  \brief    Initializes platform test modules
 *
 *  \return    - Platform_EOK on Success or error code
 */
Platform_STATUS initPlatform(void);

/**
 *  \brief    Reads user input for deciding the test result
 *
 *  \return    - Platform_EOK on Success or error code
 */
Platform_STATUS getTestResult(char *str);

/**
 *  \brief    Function to generate delay in secs
 *
 *  \return    - None
 */
void delay_secs(uint32_t secs);

/**
 *  \brief    Function to exit the test
 *
 *  This function should be called by standalone diagnostic
 *  tests at the end of the test to return to diagnostic test framework
 *
 *  \param result [IN]  Test result
 *                      0 - Test Pass
 *                      1 - Test Fail
 *
 */
void testExit(int result);

uint32_t CheckId(void);
void id_programming(void);
void displayBoardInfo(void);
Platform_STATUS GetIdValues(void);
void DisplayBoardIdError(void);

TEST_STATUS bmcTest(void *);

void extTestExit(void);

/**
 *  \brief    Configures GPIO switch for serial port
 *
 *  This function selects the GPIO configuration for serial switch
 *  between DB9 and 'UART to USB' ports on K2G EVM
 *
 *  \param portId [IN]  - Port ID; DB9 or 'UART to USB'
 *
 *  \return    - None
 */
void configSerPortSwitch(uint8_t portId);

#endif // _PLATFORM_TEST_H_

/* Nothing past this point */
