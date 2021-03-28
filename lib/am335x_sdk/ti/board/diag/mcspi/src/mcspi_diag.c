
/*
 * Copyright (c) 2014-2017, Texas Instruments Incorporated
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
 */

/* TI-RTOS Header files */
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>
#include <ti/csl/soc/am65xx/src/cslr_soc.h>
#include <stdlib.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#if !defined(SOC_AM65XX)
#include <ti/drv/gpio/soc/GPIO_soc.h>
#else
#include "diag_common_cfg.h"
#endif
#include "board.h"
#include "board_cfg.h"

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
/* Board specific definitions */
#if defined (SOC_AM437x)
#define MCSPI_INSTANCE         (2U)
#endif
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
#define MCSPI_INSTANCE         (3U)
#endif
#ifdef iceAMIC110
#define MCSPI_INSTANCE         (1U)
#endif
#if defined (SOC_AM65XX)
#define MCSPI_INSTANCE         (1U)
#endif

/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)

#ifdef iceAMIC110
#define CSL_MCSPI_PER_CNT   (1U)
#elif defined(SOC_AM65XX)
#define CSL_MCSPI_PER_CNT   (5U)
#else
#define CSL_MCSPI_PER_CNT   (4U)
#endif
#define CSL_QSPI_PER_CNT    1U

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
/* Board init function */
extern void Board_initSPI(void);

int8_t BoardDiag_mcspiFuctionalTest(void);

void AppDelay(uint32_t delayVal);

/* Function to control load signal to the industrial input module */
void LoadData(void);

#ifdef iceAMIC110
#define BUFF_SIZE            (256U)
#define MAX_BUFF_SIZE        (260U)
#define FLASH_TEST_SECTOR    (0x800000U)
#define FLASH_READ_CMD       (0x03U)
#define FLASH_WRITE_CMD      (0x02U)
#define FLASH_SECT_ERASE_CMD (0x20U)
#define FLASH_READ_STS_CMD   (0x05U)
#define FLASH_WE_CMD         (0x06U)
/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[MAX_BUFF_SIZE];
/* Buffer containing the received data */
uint8_t rxBuf[MAX_BUFF_SIZE] ;
uint8_t verifyBuf[BUFF_SIZE];
#endif

/* Function to verify data */
bool VerifyData(uint8_t *expData, uint8_t *rxData, uint32_t length);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/


extern const SPI_Config SPI_config[];

#define BOARD_IDK_SPI_LD_PIN (0U)

/*
 *  ======== test function ========
 */

#ifndef iceAMIC110
int spi_test()
{
    SPI_Params spiParams;                /* SPI params structure */
    SPI_Handle handle;                   /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction */
    bool retVal = false;                 /* return value */
    int index;
    char p = 'r';
    SPI_v1_HWAttrs  spiCfg;

    /* Buffer containing the known data that needs to be written to flash */
    uint8_t txBuf[1U];

    /* Buffer containing the received data */
    uint8_t rxBuf[1U] = {0xFFU};

    /* Transfer length */
    uint32_t transferLength;

    for (index=0; index<CSL_MCSPI_PER_CNT; index++)
    {
         SPI_socGetInitCfg(index, &spiCfg);
         spiCfg.enableIntr = false;
#if defined(SOC_AM65XX)
         spiCfg.chNum      = 1;
#endif
         SPI_socSetInitCfg(index, &spiCfg);
    }

#if !defined(SOC_AM65XX)
    for (index=CSL_MCSPI_PER_CNT; index<CSL_MCSPI_PER_CNT+CSL_QSPI_PER_CNT; index++)
    {
        ((QSPI_HwAttrs *)SPI_config[index].hwAttrs)->intrEnable = false;
    }
#endif

    /* Init GPIO driver */
    GPIO_init();

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);
    spiParams.frameFormat  = SPI_POL1_PHA0;

    /* Open QSPI driver */
    handle = SPI_open((MCSPI_INSTANCE - 1U), &spiParams);

    do {

        /* Load data */
        LoadData();
        /* Initiate transfer */
        txBuf[0] = 0xAAU;
        transferLength = 1U;
        transaction.count = transferLength;
        transaction.txBuf = &txBuf[0];
        transaction.rxBuf = &rxBuf[0];
        retVal = SPI_transfer(handle, &transaction);
        AppDelay(100000);

        if(false == retVal)
        {
            UART_printf("\nError occurred in spi transfer \n");
            UART_printf("Data received: %x\n", rxBuf[0]);
            UART_printf("Status code returned by LLD is: %d\n", (int) transaction.status);
            p = 'n';
        }
        else
        {
            UART_printf("Data transferred: %x\n", txBuf[0]);

#if defined(SOC_AM65XX)
            UART_printf("Data received: %x\n", rxBuf[0]);

            if(rxBuf[0] == 0x55)
            {
                p = 'y';
            }
            else
            {
                p = 'n';
            }
#else
            UART_printf("Data received: %x\n", rxBuf[0]);
            UART_printf("Press 'y' to verify pass, 'r' to read again,\n");
            UART_printf("or any other character to indicate failure: ");
            UART_scanFmt("%c", &p);
            UART_printf("User input: %c\n", p);
#endif
        }
        if (p == 'r') UART_printf("\nReading again\n");
    } while (p == 'r');

    if ( (p == 'y') || (p == 'Y') ) {
        UART_printf("\nTest PASSED!\n");
        return 0;
    }
    else {
        UART_printf("\nTest FAILED!\n");
        return -1;
    }

    SPI_close(handle);

}

/*
 *  ======== Function to control load signal to load data ========
 */
void LoadData(void)
{
    GPIO_write(BOARD_IDK_SPI_LD_PIN, GPIO_PIN_VAL_LOW);
    AppDelay(10000);
    GPIO_write(BOARD_IDK_SPI_LD_PIN, GPIO_PIN_VAL_HIGH);
    AppDelay(10000);
}

#else  /* #ifndef iceAMIC110 */

/* Function to erase a flash sector */
static int spi_erase_sector(SPI_Handle handle, uint32_t sector)
{
    bool retVal = false;
    SPI_Transaction transaction;

    /* Write Enable */
    txBuf[0] = FLASH_WE_CMD;
    transaction.count = 1U;
    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Write Enable Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Sector erase */
    txBuf[0] = FLASH_SECT_ERASE_CMD;
    txBuf[1] = (sector >> 16) & 0xFF;
    txBuf[2] = (sector >> 8) & 0xFF;
    txBuf[3] = sector & 0xFF;
    transaction.count = 4U;
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Sector erase Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Check for Flash Busy */
    do{
        txBuf[0] = FLASH_READ_STS_CMD;
        txBuf[1] = 0xFFU;
        transaction.count = 2U;
        retVal = SPI_transfer(handle, &transaction);
    } while(rxBuf[1] & 0x01);
    
    return 0;
}

int spi_flash_test(void)
{
    SPI_Params spiParams;                /* SPI params structure */
    SPI_Handle handle;                   /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction */
    bool retVal = false;                 /* return value */
    int i;

    for (i=0; i<CSL_MCSPI_PER_CNT; i++)
    {
        ((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->enableIntr = false;
		((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->chNum = 0;
    }

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open QSPI driver */
    handle = SPI_open((MCSPI_INSTANCE - 1U), &spiParams);

    for(i = 4; i < MAX_BUFF_SIZE; i++)
    {
        txBuf[i] = 0x0U;
    }

    /* Erase flash sector before write */
    spi_erase_sector(handle, FLASH_TEST_SECTOR);

    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];

    /* Write Enable */
    txBuf[0] = FLASH_WE_CMD;
    transaction.count = 1U;
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Write Enable Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Write to SPI Flash */
    txBuf[0] = FLASH_WRITE_CMD;
    txBuf[1] = (FLASH_TEST_SECTOR >> 16) & 0xFF;
    txBuf[2] = (FLASH_TEST_SECTOR >> 8) & 0xFF;
    txBuf[3] = (FLASH_TEST_SECTOR) & 0xFF;
    transaction.count = MAX_BUFF_SIZE;
    for(i=4; i<MAX_BUFF_SIZE; i++)
    {
        txBuf[i] = i - 4;
        verifyBuf[i-4] = txBuf[i];
    }

    retVal = SPI_transfer(handle, &transaction);
    if(retVal == true)
        UART_printf("SPI Write Successful \n");
    else
    {
        UART_printf("SPI Write Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Read from SPI flash */
    txBuf[0] = FLASH_READ_CMD;
    txBuf[1] = (FLASH_TEST_SECTOR >> 16) & 0xFF;
    txBuf[2] = (FLASH_TEST_SECTOR >> 8) & 0xFF;
    txBuf[3] = (FLASH_TEST_SECTOR) & 0xFF;
    transaction.count  = MAX_BUFF_SIZE;
    retVal = SPI_transfer(handle, &transaction);

    if(retVal == true)
    {
        UART_printf("SPI Read Successful \n");
    }
    else
    {
        UART_printf("SPI Read Failed \n");
        SPI_close(handle);
        return -1;
    }

    if(VerifyData(&verifyBuf[0],&rxBuf[4],BUFF_SIZE) == true)
    {
        UART_printf("Data Read matches with Data written\n");
        UART_printf("SPI Flash Test Passed!\n");
    }
    else
    {
        UART_printf("SPI Flash Test Failed!\n");
        SPI_close(handle);
        return -1;
    }

    /* Erase flash sector after the test */
    spi_erase_sector(handle, FLASH_TEST_SECTOR);

    SPI_close(handle);

    return 0;
}
#endif   /* #ifndef iceAMIC110 */
#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the mcspi Diagnostic
 *            stress test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_mcspiStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning mcspi Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_mcspiFuctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d mcspi Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\nmcspi Test Failed at iteration - %d\n",iteration);
            failCount++;
        }

        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            iteration++;
            break;
        }
    }

    UART_printf("\n\nMcspi Stress Test Status\n");
    UART_printf("===================================\n");
    UART_printf("Number of Times Executed - %d\n", (iteration - 1));
    UART_printf("Pass Count - %d\n", passCount);
    UART_printf("Fail Count - %d\n", failCount);

    if((iteration != 0) && (failCount == 0))
    {
        UART_printf("Overall Status - PASS\n\n\n" );
    }
    else
    {
        UART_printf("Overall Status - FAIL\n\n\n" );
        ret = -1;
    }

    return ret;
}
#endif


/**
 *  \brief    The function performs the mcspi Diagnostic
 *            functional test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_mcspiFuctionalTest(void)
{
    int8_t ret = 0;

	UART_printf("\n*********************************************\n"); 
	UART_printf  ("*                MCSPI Test                 *\n");
	UART_printf  ("*********************************************\n");

	UART_printf("\nTesting MCSPI...\n");

#ifdef iceAMIC110
    return spi_flash_test();
#else
    ret =  spi_test();
    return ret;
#endif
}

#if defined(SOC_AM65XX)
#if !defined (__aarch64__)
void enableMAINSPI()
{
    SPI_v1_HWAttrs  spiCfg;

    SPI_socGetInitCfg((MCSPI_INSTANCE-1), &spiCfg);

    spiCfg.baseAddr = CSL_MCSPI0_CFG_BASE;
    spiCfg.enableIntr = 0;

    SPI_socSetInitCfg((MCSPI_INSTANCE-1), &spiCfg);
}
#endif
#endif

/*
 *  ======== main ========
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    Board_initCfg boardCfg;
    int8_t ret = 0;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    Board_init(boardCfg);

#if defined(SOC_AM65XX)
#if !defined (__aarch64__)
	enableMAINSPI();
#endif
#endif

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_mcspiStressTest();
#else
    ret = BoardDiag_mcspiFuctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\n mcspi Test Passed\n");
    }
    else
    {
        UART_printf("\n mcspi Test Failed\n");
    }

    return ret;
}

/*
 *  ======== AppDelay ========
 */
void AppDelay(uint32_t delayVal)
{
    uint32_t cnt = 0;
    while(cnt < delayVal)
    {
        asm("");
        cnt++;
    }
}
#endif


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
