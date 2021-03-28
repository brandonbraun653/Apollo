/**
 *  \file   main_flash_read_test.c
 *
 *  \brief  Example application main file. This application will write and read
 *          the data to/from nor flash through qspi interface.
 *
 */

/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/soc.h>
/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/QSPI_v1.h>
#include "SPI_log.h"

/* Flash header file */
#include <ti/drv/spi/test/qspi_flash/src/Flash_S25FL/S25FL.h>

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
#define QSPI_PER_CNT            (1U)
#define QSPI_INSTANCE           (1U)

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#define QSPI_OFFSET             (5U)
#endif
#if defined(SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x)
#define QSPI_OFFSET             (4U)
#endif

#define QSPI_TEST_LENGTH        (75U)  /* read/write test data size in 32-bit words */

/* Unit test IDs */
#define QSPI_TEST_ID_CMD          0   /* Command mode test */
#define QSPI_TEST_ID_MMAP         1   /* Memory map with DMA disabled mode test */
#define QSPI_TEST_ID_MMAP_DMA     2   /* Memory map with DMA enabled mode test */


/* Define the SPI test interface */
typedef struct QSPI_Tests_s
{
    bool     (*testFunc)(void *);
    int32_t  testId;
    bool     intrMode;
    bool     dmaMode;
    bool     mmapMode;
    char     testDesc[80];

} QSPI_Tests;

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Function to generate known data */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length);

/* Data compare function */
bool VerifyData(unsigned char *expData,
                unsigned char *rxData,
                unsigned int length);

#if defined(SOC_AM574x) || defined (SOC_AM571x) || defined (SOC_AM572x)
void QSPI_board_crossbarInit(void);
#endif

#ifdef SPI_DMA_ENABLE
static EDMA3_RM_Handle QSPIApp_edmaInit(void);
extern QSPI_HwAttrs qspiInitCfg[];
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Buffer containing the known data that needs to be written to flash */
#if (defined(_TMS320C6X) || defined (__TI_ARM_V7M4__))
#pragma DATA_ALIGN (txBuf, 128)
uint32_t txBuf[1024];
#pragma DATA_ALIGN (rxBuf, 128)
uint32_t rxBuf[1024];
#else
uint32_t txBuf[1024] __attribute__((aligned(128)));
uint32_t rxBuf[1024] __attribute__((aligned(128)));
#endif

unsigned int addrValue = 0x000000U;

/* hardware attributes */
extern QSPI_HwAttrs qspiInitCfg[QSPI_PER_CNT];

/* transfer length */
uint32_t transferLength = 0;

#ifdef SPI_DMA_ENABLE
EDMA3_RM_Handle gEdmaHandle = NULL;

/**
 * \brief      Function to initialize the edma driver and get the handle to the
 *             edma driver;
 */
static EDMA3_RM_Handle QSPIApp_edmaInit(void)
{
    EDMA3_DRV_Result edmaResult = EDMA3_DRV_E_INVALID_PARAM;
    uint32_t         edma3Id;

    if (gEdmaHandle != NULL)
    {
        return (gEdmaHandle);
    }

    edma3Id = 0;
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(edma3Id, &edmaResult);

    return(gEdmaHandle);
}
#endif

void QSPI_test_print_test_desc(QSPI_Tests *test)
{
    char        testId[16] = {0, };

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
    SPI_log("\r\n QSPI UT %s\r\n", testId);

    /* Print test description */
    SPI_log("\r\n %s\r\n", test->testDesc);
}

/*
 *  ======== QSPI init config ========
 */
static void QSPI_initConfig(uint32_t instance, QSPI_Tests *test)
{
    QSPI_HwAttrs *cfg = &qspiInitCfg[instance];
    bool          intrMode = test->intrMode;
#ifdef SPI_DMA_ENABLE
    bool          dmaMode = test->dmaMode;
#endif

    if (intrMode == true)
    {
        /* polling mode */
        cfg->intrEnable = true;
    }
    else
    {
        /* interrupt mode */
        cfg->intrEnable = false;
    }

#ifdef SPI_DMA_ENABLE
    if (dmaMode == true)
    {
        cfg->edmaHandle = QSPIApp_edmaInit();
        cfg->dmaEnable  = true;
    }
    else
#endif
    {
        cfg->edmaHandle = NULL;
        cfg->dmaEnable  = false;
    }
}


static bool QSPI_test_func (void *arg)
{
    QSPI_Tests        *test = (QSPI_Tests *)arg;
    SPI_Params         spiParams;
    S25FL_Handle       flashHandle;            /* Flash handle */
    uint32_t           blockNumber = 0U;       /* Block number */
    S25FL_Transaction  flashTransaction;       /* Flash transaction structure */
    SPI_Handle         handle;                 /* SPI handle */
    QSPI_HwAttrs      *hwAttrs;                /* QSPI hardware attributes */
    bool               retVal = true;          /* return value */
    uint32_t           rxLines;
    uint32_t           qspiMode;

    QSPI_initConfig(0, test);

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open QSPI driver */
    flashHandle = SF25FL_open(((QSPI_INSTANCE - 1)+(QSPI_OFFSET)), &spiParams);

    /* Extract hardware attributes */
    handle = flashHandle->spiHandle;
    hwAttrs = (QSPI_HwAttrs *)handle->hwAttrs;

    /* Print flash Id */
    FlashPrintId(flashHandle);

    for (rxLines = QSPI_RX_LINES_SINGLE; rxLines < (QSPI_RX_LINES_QUAD + 1); rxLines++)
    {
        if (test->mmapMode)
        {
            qspiMode = QSPI_OPER_MODE_MMAP;
            SPI_control(handle, SPI_V1_CMD_SETMEMMORYMAPMODE, (void *)&qspiMode);
        }
        else
        {
            qspiMode = QSPI_OPER_MODE_CFG;
            SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, (void *)&qspiMode);
        }

        SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

        /* Erase block, to which data has to be written */
        S25FLFlash_BlockErase(flashHandle, blockNumber);

        /* Set the transfer length in number of 32 bit words */
        transferLength = QSPI_TEST_LENGTH;

        /* Generate the data */
        GeneratePattern((uint8_t *)&txBuf[0], (uint8_t *)&rxBuf[0], transferLength);

#ifdef SPI_DMA_ENABLE
        if (test->dmaMode)
        {
            CacheP_wbInv((void *)rxBuf, (int32_t)sizeof(rxBuf));
            CacheP_wbInv((void *)txBuf, (int32_t)sizeof(txBuf));
        }
#endif
        /* Update transaction parameters */
        flashTransaction.data        = (uint8_t *)&txBuf[0];

        if (test->mmapMode)
        {
            flashTransaction.address = addrValue;
        }
        else
        {
            /*
             * For CFG Mode,flashTransaction.address should be assigned with the
             * address of the variable which contains the flash offset value
             */
            flashTransaction.address = (uint32_t)&addrValue;
        }
        flashTransaction.dataSize    = transferLength * 4;  /* In bytes */

        /* Write buffer to flash */
        retVal = SF25FL_bufferWrite(flashHandle, &flashTransaction);

        if(QSPI_RX_LINES_QUAD == hwAttrs->rxLines)
        {
            S25FLFlash_QuadModeEnable(flashHandle);
        }

        /* Update transaction parameters */
        flashTransaction.data        = (uint8_t *)&rxBuf[0];
        if (test->mmapMode)
        {
            flashTransaction.address = addrValue;
        }
        else
        {
            /*
             * For CFG Mode,flashTransaction.address should be assigned with the
             * address of the variable which contains the flash offset value
             */
            flashTransaction.address = (uint32_t)&addrValue;
        }
        flashTransaction.dataSize    = transferLength * 4; /* In bytes */

        /* Read data from flash */
        retVal = SF25FL_bufferRead(flashHandle, &flashTransaction);

        /* Verify Data */
        retVal = VerifyData((unsigned char *)&txBuf[0], (unsigned char *)&rxBuf[0],
            transferLength);

        if (retVal == false)
        {
            break;
        }
    }

    SF25FL_close(flashHandle);

    return (retVal);
}

QSPI_Tests qspi_tests[] =
{
    /* testFunc      testID                 intrMode dmaMode mmapMode testDesc */
    {QSPI_test_func, QSPI_TEST_ID_CMD,      true,    false,  false,  "\r\n QSPI flash command mode test", },
    {QSPI_test_func, QSPI_TEST_ID_MMAP,     false,   false,  true,   "\r\n QSPI flash memory map mode test", },
#ifdef SPI_DMA_ENABLE
    {QSPI_test_func, QSPI_TEST_ID_MMAP_DMA, false,   true,   true,   "\r\n QSPI flash memory map mode with DMA enabled test", },
#endif
    {NULL, },
};

/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    uint32_t    i;
    QSPI_Tests *test;
    bool        testFail = false;

    /* Init SPI driver */
    SPI_init();

    for (i = 0; ; i++)
    {
        test = &qspi_tests[i];
        if (test->testFunc == NULL)
            break;

        QSPI_test_print_test_desc(test);
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

    if(true == testFail)
    {
        SPI_log("\n All tests have failed. \n");
    }
    else
    {
        SPI_log("\n All tests have passed. \n");
    }

    while(1);
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;

#if defined (SOC_AM335x) || defined (SOC_AM437x)
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

#if defined (SOC_AM571x) || defined (SOC_AM572x) || defined(SOC_AM574x)
    QSPI_board_crossbarInit();
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}

/*
 *  ======== Board_initQSPI ========
 */
#if defined (SOC_AM571x) || defined (SOC_AM572x) || defined(SOC_AM574x)
void QSPI_board_crossbarInit(void) {
#ifndef __ARM_ARCH_7A__
    CSL_XbarIrqCpuId                   cpu;
    uint32_t                           cpuEvent;
    uint32_t                           xbarIndex;
#endif
#ifdef C66X
    /* Configure xbar connect for MCSPI3: DSP_IRQ_38 mapped to MCSPI3 intr */
    cpu = CSL_XBAR_IRQ_CPU_ID_DSP1;
    cpuEvent = 38;
    xbarIndex = cpuEvent - 31;

    /* Configure xbar */
    CSL_xbarIrqConfigure (cpu, xbarIndex, CSL_XBAR_QSPI_IRQ);

#elif __ARM_ARCH_7A__
    /* Configure xbar connect for QSPI: MPU_IRQ_35 mapped to QSPI intr */
    *(unsigned int*)0x4A002A80 = (unsigned int)(0x0157001D);

#else

    /* Configure xbar connect for MCSPI3: DSP_IRQ_38 mapped to MCSPI3 intr */
    cpu = CSL_XBAR_IRQ_CPU_ID_IPU1;
    cpuEvent = 62;
    xbarIndex = cpuEvent - 22;

    /* Configure xbar */
    CSL_xbarIrqConfigure (cpu, xbarIndex, CSL_XBAR_QSPI_IRQ);
#endif

}
#endif

/*
 *  ======== CompareData ========
 */
bool VerifyData(unsigned char *expData,
                unsigned char *rxData,
                unsigned int length)
{
    unsigned int idx = 0;
    unsigned int match = 1;
    bool retVal = false;
    unsigned int lenInBytes = length * 4;

    for(idx = 0; ((idx < lenInBytes) && (match != 0)); idx++)
    {
        if(*expData != *rxData) match = 0;
        expData++;
        rxData++;
    }

    if(match == 1) retVal = true;

    return retVal;
}

/*
 *  ======== GeneratePattern ========
 */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length)
{
    unsigned int idx;
    unsigned int lenInBytes = length * 4;

    for(idx = 0; idx < lenInBytes; idx++)
    {
        txBuf[idx] = (uint8_t)idx;
        rxBuf[idx] = (uint8_t)0U;
    }
}
