/**
 *  \file   main_mcspi_test.c
 *
 *  \brief  McSpi test main file.
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
 * Copyright (C) 2014-2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <string.h>

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
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include "SPI_log.h"
#include "SPI_test.h"

/* GPIO Header files */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>

#include <ti/board/board.h>

#ifdef SPI_DMA_ENABLE
#include <ti/osal/CacheP.h>

/* EDMA3 Header files */
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/rm/sample/bios6_edma3_rm_sample.h>
#endif

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
/* Maximum # of channels per SPI instance */
#define MCSPI_MAX_NUM_CHN (4U)

/* Transfer length in bytes */
#define MCSPI_XFER_LEN    (1U)

/* Define the SPI test interface */
typedef struct SPI_Tests_s
{
    bool     (*testFunc)(void *);
    int16_t  testId;
    bool     pollMode;
    bool     cbMode;
    bool     dmaMode;
    uint32_t timeout;
    char     testDesc[80];

} SPI_Tests;
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

/* Cross bar specific configurations specific to AM571x and AM572x */
#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
extern void  MCSPI_Board_crossbarInit(void);
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Reference Serializer data */
extern char serializerData[1];

/* Buffer containing the known data that needs to be written to flash */
#ifdef _TMS320C6X
#pragma DATA_ALIGN (txBuf, 128)
uint8_t txBuf[1U];
#else
uint8_t txBuf[1U] __attribute__((aligned(128)));
#endif

/* Buffer containing the received data */
#ifdef _TMS320C6X
#pragma DATA_ALIGN (rxBuf, 128)
uint8_t rxBuf[1U] = {0xFFU};
#else
uint8_t rxBuf[1U] __attribute__((aligned(128))) = {0xFFU};
#endif

/* Transaction data */
SPI_Transaction   transaction;

/* Flag to check transfer completion in callback mode */
uint32_t txCompleteCallbackFlag = 1U;

/* Callback mode variables */
SemaphoreP_Params cbSemParams;
SemaphoreP_Handle cbSem[MCSPI_MAX_NUM_CHN] = {NULL, NULL, NULL, NULL};

/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_LD_PIN = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

#ifdef SPI_DMA_ENABLE
static EDMA3_RM_Handle MCSPIApp_edmaInit(void);
#endif

#ifdef MCSPI_MULT_CHANNEL
uint32_t testChNum = 0;
#endif

/* Callback mode functions */
void SPI_callback(SPI_Handle handle, SPI_Transaction *transaction)
{
    SPI_osalPostLock(cbSem[0]);
}

#ifdef MCSPI_MULT_CHANNEL
void MCSPI_callback0(MCSPI_Handle handle, SPI_Transaction *transaction)
{
    SPI_osalPostLock(cbSem[0]);
}

void MCSPI_callback1(MCSPI_Handle handle, SPI_Transaction *transaction)
{
    SPI_osalPostLock(cbSem[1]);
}

void MCSPI_callback2(MCSPI_Handle handle, SPI_Transaction *transaction)
{
    SPI_osalPostLock(cbSem[2]);
}

void MCSPI_callback3(MCSPI_Handle handle, SPI_Transaction *transaction)
{
    SPI_osalPostLock(cbSem[3]);
}
#endif

/*
 *  ======== SPI init config ========
 */
static void SPI_initConfig(uint32_t instance, SPI_Tests *test, bool multiChn)
{
    SPI_HWAttrs spi_cfg;
    bool        pollMode = test->pollMode;
#ifdef SPI_DMA_ENABLE
    bool        dmaMode = test->dmaMode;
#endif

    /* Get the default SPI init configurations */
    SPI_socGetInitCfg(instance, &spi_cfg);

    /*
     * Set blocking mode (dma mode or non-dma interrupt mode)
     * or callback mode
     */
    if (pollMode == true)
    {
        /* polling mode */
        spi_cfg.enableIntr = false;
    }
    else
    {
        /* interrupt enabled */
        spi_cfg.enableIntr = true;
#ifdef SPI_DMA_ENABLE
        if (dmaMode == true)
        {
            /* Set the DMA related init config */
            spi_cfg.edmaHandle = MCSPIApp_edmaInit();
            spi_cfg.dmaMode    = TRUE;
        }
        else
#endif
        {
            spi_cfg.edmaHandle = NULL;
            spi_cfg.dmaMode    = FALSE;
        }
    }

#ifdef MCSPI_MULT_CHANNEL
    testChNum = spi_cfg.chNum;

    /*
     * Set multi or single channel mode
     */
    /*if (multiChn == true)
    {
        spi_cfg.chMode = MCSPI_MULTI_CH;
    }
    else
    {
        spi_cfg.chMode = MCSPI_SINGLE_CH;
    }*/
#endif

    /* Set the SPI init configurations */
    SPI_socSetInitCfg(instance, &spi_cfg);
}

/*
 *  ======== spi_test_transfer ========
 */
bool spi_test_transfer(void *spi, bool cbMode, uint32_t timeout, bool dmaMode, bool multChn)
{
    bool retVal;
    SemaphoreP_Handle sem;

    /* Load data */
    LoadData();

    /* Initiate transfer */
    txBuf[0] = 0xAAU;
    memset(rxBuf, 0, MCSPI_XFER_LEN);

    transaction.status= SPI_TRANSFER_STARTED;
    transaction.count = MCSPI_XFER_LEN;
    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];

#ifdef SPI_DMA_ENABLE
    if (dmaMode)
    {
        CacheP_wb((void *)txBuf, (int32_t)MCSPI_XFER_LEN);
        CacheP_wb((void *)rxBuf, (int32_t)MCSPI_XFER_LEN);
    }
#endif

#ifdef MCSPI_MULT_CHANNEL
    if (multChn == true)
    {
        retVal = MCSPI_transfer((MCSPI_Handle)spi, &transaction);
    }
    else
#endif
    {
        retVal = SPI_transfer((SPI_Handle)spi, &transaction);
    }

#ifdef SPI_DMA_ENABLE
    if (dmaMode == true)
    {
        CacheP_Inv((void *)rxBuf, (int32_t)MCSPI_XFER_LEN);
    }
#endif

    if(false == retVal)
    {
        SPI_log("\n Error occurred in spi transfer \n");
        goto Err;
    }
    else
    {
        /**
         *  wait for the semaphore is posed in the callback mode to indicate the
         *  transfer completion.
         */
        if(cbMode == true)
        {
            if (multChn == true)
            {
                sem = cbSem[testChNum];
            }
            else
            {
                sem = cbSem[0];
            }
            if (SPI_osalPendLock(sem, timeout) != SemaphoreP_OK)
            {
                goto Err;
            }
        }

        retVal = VerifyData((uint8_t *)&serializerData[0], &rxBuf[0], MCSPI_XFER_LEN);

    }
    SPI_log("\n SPI_Transfer returned transaction status = %d\n",transaction.status);

Err:
    return (retVal);
}

#ifdef MCSPI_MULT_CHANNEL
/*
 *  ======== spi_test_multiple_channel ========
 */
bool spi_test_multiple_channel(void *arg)
{
    MCSPI_Params      mcSpiParams;
    MCSPI_Handle      spi[MCSPI_MAX_NUM_CHN];
    MCSPI_CallbackFxn cbFxn[MCSPI_MAX_NUM_CHN] = {MCSPI_callback0, MCSPI_callback1, MCSPI_callback2, MCSPI_callback3};
    uint32_t          instance, chn;
    bool              retVal = FALSE;
    SPI_Tests        *test = (SPI_Tests *)arg;
    bool              cbMode = test->cbMode;
    bool              dmaMode = test->dmaMode;
    uint32_t          timeout = test->timeout;

    if (cbMode == true)
    {
        /* Create call back semaphore */
        SPI_osalSemParamsInit(&cbSemParams);
        cbSemParams.mode = SemaphoreP_Mode_BINARY;
    }

    instance = BOARD_MCSPI_SERIALIZER_INSTANCE;
    SPI_initConfig(instance, test, true);

    /* Default SPI configuration parameters */
    MCSPI_Params_init(&mcSpiParams);
    mcSpiParams.frameFormat  = SPI_POL1_PHA0;
    mcSpiParams.transferTimeout = timeout;
    if (cbMode)
    {
        mcSpiParams.transferMode = SPI_MODE_CALLBACK;
    }

    /* Open the default channel first */
    chn = testChNum;
    if (cbMode == true)
    {
        cbSem[chn] = SPI_osalCreateBlockingLock(0, &cbSemParams);
        mcSpiParams.transferCallbackFxn = cbFxn[chn];
    }
    spi[chn] = MCSPI_open(instance, chn, &mcSpiParams);
    if (spi[chn] == NULL)
    {
        SPI_log("Error initializing SPI");
        goto Err;
    }
    else
    {
        SPI_log("SPI instance %d channel %d initialized\n",
                instance, chn);
    }

    for (chn = 0; chn < MCSPI_MAX_NUM_CHN; chn++)
    {
        if (chn == testChNum) continue;
        if (cbMode == true)
        {
            cbSem[chn] = SPI_osalCreateBlockingLock(0, &cbSemParams);
            mcSpiParams.transferCallbackFxn = cbFxn[chn];;
        }

        spi[chn] = MCSPI_open(instance, chn, &mcSpiParams);

        if (spi[chn] == NULL)
        {
            SPI_log("Error initializing SPI");
            goto Err;
        }
        else
        {
            SPI_log("SPI instance %d channel %d initialized\n",
                    instance, chn);
        }
    }

    retVal = spi_test_transfer((void *)spi[testChNum], cbMode, timeout, dmaMode, true);

Err:
    for (chn = 0; chn < MCSPI_MAX_NUM_CHN; chn++)
    {
        if (spi[chn])
        {
            MCSPI_close(spi[chn]);
        }

        if (cbSem[chn])
        {
            SPI_osalDeleteBlockingLock(cbSem[chn]);
            cbSem[chn] = NULL;
        }
    }

    return (retVal);
}
#endif

/*
 *  ======== spi_test_single_channel ========
 */
bool spi_test_single_channel(void *arg)
{
    SPI_Params      spiParams;           /* SPI params structure */
    SPI_Handle      spi;                 /* SPI handle */
    uint32_t        instance;
    bool            retVal = false;      /* return value */
    SPI_Tests      *test = (SPI_Tests *)arg;
    bool            cbMode = test->cbMode;
    bool            dmaMode = test->dmaMode;
    uint32_t        timeout = test->timeout;

    if (cbMode == true)
    {
        /* Create call back semaphore */
        SPI_osalSemParamsInit(&cbSemParams);
        cbSemParams.mode = SemaphoreP_Mode_BINARY;
        cbSem[0] = SPI_osalCreateBlockingLock(0, &cbSemParams);
    }

    instance = BOARD_MCSPI_SERIALIZER_INSTANCE;
    SPI_initConfig(instance, test, false);

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);
    spiParams.frameFormat  = SPI_POL1_PHA0;
    spiParams.transferTimeout = timeout;
    if (cbMode)
    {
        spiParams.transferMode = SPI_MODE_CALLBACK;
        spiParams.transferCallbackFxn = SPI_callback;
    }

    /* Open QSPI driver */
    spi = SPI_open(instance, &spiParams);

    if (spi == NULL)
    {
        SPI_log("Error initializing SPI\n");
        goto Err;
    }
    else
    {
        SPI_log("SPI initialized\n");
    }

    retVal = spi_test_transfer((void *)spi, cbMode, timeout, dmaMode, false);

Err:
    if (spi)
    {
        SPI_close(spi);
    }

    if (cbSem[0])
    {
        SPI_osalDeleteBlockingLock(cbSem[0]);
        cbSem[0] = NULL;
    }

    return (retVal);
}

void SPI_test_print_test_desc(SPI_Tests *test)
{
    char        testId[16] = {0, };

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
    SPI_log("\r\n SPI UT %s\r\n", testId);

    /* Print test description */
    SPI_log("\r\n %s\r\n", test->testDesc);
}

#ifdef MCSPI_MULT_CHANNEL
#ifdef SPI_DMA_ENABLE
#define SPI_NUM_TESTS   8
#else
#define SPI_NUM_TESTS   6
#endif
#else
#ifdef SPI_DMA_ENABLE
#define SPI_NUM_TESTS   4
#else
#define SPI_NUM_TESTS   3
#endif
#endif

SPI_Tests spi_tests[SPI_NUM_TESTS] =
{
    /* testFunc          testID pollMode cbMode dmaMode, timeout              testDesc */
#ifdef SPI_DMA_ENABLE
    {spi_test_single_channel, 0, false, false, true, SemaphoreP_WAIT_FOREVER, "\r\n SPI single channel test in dma mode"},
#endif
    {spi_test_single_channel, 1, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI single channel test in non-dma interrupt mode"},
    {spi_test_single_channel, 2, true, false, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI single channel test in polling mode"},
    {spi_test_single_channel, 3, false, true, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI single channel test in callback mode"},
#ifdef MCSPI_MULT_CHANNEL
#ifdef SPI_DMA_ENABLE
    {spi_test_multiple_channel, 4, false, false, true, SemaphoreP_WAIT_FOREVER, "\r\n SPI multiple channel test in dma mode"},
#endif
    {spi_test_multiple_channel, 5, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI multiple channel test in non-dma interrupt mode"},
    {spi_test_multiple_channel, 6, true, false, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI multiple channel test in polling mode"},
    {spi_test_multiple_channel, 7, false, true, false, SemaphoreP_WAIT_FOREVER, "\r\n SPI multiple channel test in callback mode"},
#endif
};


/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    uint32_t   i;
    bool       testFail = false;
    SPI_Tests *test;

    /* Init GPIO driver */
    GPIO_init();

    /* Init SPI driver */
    SPI_init();

    for (i = 0; i < SPI_NUM_TESTS; i++)
    {
        test = &spi_tests[i];
        SPI_test_print_test_desc(test);
        if (test->testFunc((void *)test) == true)
        {
            SPI_log("\r\n %s have passed\r\n", test->testDesc);
        }
        else
        {
            SPI_log("\r\n %s have failed\r\n", test->testDesc);
            testFail = true;
            break;
        }
    }

    if(testFail == true)
    {
        SPI_log("\n Some tests have failed. \n");
    }
    else
    {
        SPI_log("\n All tests have passed. \n");
    }

    SPI_log("Done\n");

     Task_exit();
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

#ifdef SPI_DMA_ENABLE
EDMA3_RM_Handle gEdmaHandle = NULL;

/**
 * \brief      Function to initialize the edma driver and get the handle to the
 *             edma driver;
 */
static EDMA3_RM_Handle MCSPIApp_edmaInit(void)
{
    EDMA3_DRV_Result edmaResult = EDMA3_DRV_E_INVALID_PARAM;
    uint32_t         edma3Id;

    if (gEdmaHandle != NULL)
    {
        return (gEdmaHandle);
    }

    edma3Id = 0;
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(edma3Id, &edmaResult);
    if (edmaResult != EDMA3_DRV_SOK)
    {
        /* Report EDMA Error */
        System_printf("\nEDMA driver initialization FAIL\n");
    }
    else
    {
        System_printf("\nEDMA driver initialization PASS.\n");
    }
    return(gEdmaHandle);
}
#endif
