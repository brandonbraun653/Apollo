/**
 *  \file   main_mcspi_example.c
 *
 *  \brief  Example application main file.
 *
 *  \details This application will read the input data generated from the
 *           industrial input module. The data will be read through MCSPI
 *           interface. This application will read one byte of data from the
 *           industrial input module. To generate the data from the industrial
 *           input module, first load signal has to be asserted using the
 *           gpio pins. On the IDK EVM, in the header J37, short the pins
 *           1 and 2. This should generate an input "0x01" and the same should
 *           be read through the MCSPI interface.
 *           The received data will vary based on the shorting of pins:
 *           Default input(no pins are shorted)   :  received data - 0x00
 *           Pins 1 and 2 shorted                 :  received data - 0x01
 *           Pins 3 and 4 shorted                 :  received data - 0x02
 *           Pins 5 and 6 shorted                 :  received data - 0x04
 *           Pins 7 and 8 shorted                 :  received data - 0x08
 *           Pins 9 and 10  shorted               :  received data - 0x10
 *           Pins 11 and 12 shorted               :  received data - 0x20
 *           Pins 13 and 14 shorted               :  received data - 0x40
 *           Pins 15 and 16 shorted               :  received data - 0x80
 *
 */

/*
 * Copyright (C) 2014 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_v1.h>
#include <ti/drv/spi/test/src/SPI_log.h>
#include <ti/drv/spi/test/src/SPI_test.h>

/* GPIO Header files */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>

#include <ti/board/board.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/


/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
/* Delay function */
static void delay(unsigned int delayValue);

/* Function to control load signal to the industrial input module */
void LoadData(void);

/* Callback function to be called in callback mode */
void MCSPICallbackFxn(SPI_Handle handle, SPI_Transaction * transaction);

/* Function to verify data */
bool VerifyData(uint8_t *expData, uint8_t *rxData, uint32_t length);

#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
extern void  MCSPI_Board_crossbarInit(void);
#endif

#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
#if defined (__TI_ARM_V7M4__)
#define DELAY_VALUE       (100U)
#else
#define DELAY_VALUE       (1000U)
#endif
#else
#define DELAY_VALUE       (1000U)
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Reference Serializer data */
extern char serializerData[1];

/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[1U];

/* Buffer containing the received data */
uint8_t rxBuf[1U] = {0xFFU};

/* Flag to check transfer completion in callback mode */
uint32_t txCompleteCallbackFlag = 1U;

/* Transfer length */
uint32_t transferLength;


/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_LD_PIN = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    SPI_Params spiParams;                /* SPI params structure */
    SPI_Handle handle;                   /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction */
    bool retVal = false;                 /* return value */

    /* Init GPIO driver */
    GPIO_init();

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);
    spiParams.frameFormat  = SPI_POL1_PHA0;

    /* Uncomment below lines of code to test callback mode */
    /* spiParams.transferMode = SPI_MODE_CALLBACK; */
    /* spiParams.transferCallbackFxn = MCSPICallbackFxn; */

    /* Open QSPI driver */
    handle = SPI_open(BOARD_MCSPI_SERIALIZER_INSTANCE, &spiParams);

    /* Load data */
    LoadData();

    /* Initiate transfer */
    txBuf[0] = 0xAAU;
    transferLength = 1U;

    transaction.count = transferLength;
    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];
    retVal = SPI_transfer(handle, &transaction);
    delay(DELAY_VALUE);

    if(false == retVal)
    {
        SPI_log("\n Error occurred in spi transfer \n");
    }
    else
    {
        /**
         *  This below is check is required for callback mode to indicate the
         *  transfer completion.
         */
        if(SPI_MODE_CALLBACK == spiParams.transferMode)
        {
            while(txCompleteCallbackFlag == 1U);
        }

        retVal = VerifyData((uint8_t *)&serializerData[0], &rxBuf[0], transferLength);

        if(true == retVal)
        {
            SPI_log("\n All tests have passed. \n");
        }
        else
        {
            SPI_log("\n Some tests have failed. \n");
        }
    }

    SPI_close(handle);

    while(1);
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;

#if defined(SOC_AM335x) || defined (SOC_AM437x)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(spi_test, NULL, &eb);
        if (task == NULL) {
            System_printf("Task_create() failed!\n");
            BIOS_exit(0);
        }
#endif


    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);


#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
    MCSPI_Board_crossbarInit();
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}


/*
 *  ======== Function to control load signal to load data ========
 */
void LoadData(void)
{
    GPIO_write(GPIO_PIN_LD_PIN, GPIO_PIN_VAL_LOW);
    delay(1);
    GPIO_write(GPIO_PIN_LD_PIN, GPIO_PIN_VAL_HIGH);
    delay(1);
}


/*
 *  ======== Delay function ========
 */
void delay(unsigned int delayValue)
{
    volatile uint32_t delay1 = delayValue*10000;
    while (delay1--) ;
}

/*
 *  ======== Callback function ========
 */
void MCSPICallbackFxn(SPI_Handle handle, SPI_Transaction * transaction)
{
    txCompleteCallbackFlag = 0;
}

/*
 *  ======== CompareData ========
 */
bool VerifyData(uint8_t *expData, uint8_t *rxData, uint32_t length)
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
