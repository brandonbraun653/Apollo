/**
 *  \file   main_flash_read_write.c
 *
 *  \brief  Example application main file. This application will write and read
 *          the data to/from nor flash through qspi interface.
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
#include <ti/csl/soc.h>
/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/QSPI_v1.h>
#include <ti/drv/spi/test/qspi_flash/src/SPI_log.h>

/* Flash header file */
#include <ti/drv/spi/test/qspi_flash/src/Flash_S25FL/S25FL.h>

#include <ti/board/board.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#define QSPI_PER_CNT            (1U)
#define QSPI_INSTANCE           (1U)

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#define QSPI_OFFSET             (5U)
#endif
#if defined (SOC_AM572x) || defined (SOC_AM574x) || defined (SOC_AM571x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x)
#define QSPI_OFFSET             (4U)
#endif


/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Function to generate known data */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length);

/* Data compare function */
bool VerifyData(unsigned char *expData,
                unsigned char *rxData,
                unsigned int length);

#if defined(SOC_AM574x) || defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x)
void QSPI_board_crossbarInit(void);
#endif


/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Buffer containing the known data that needs to be written to flash */
unsigned int txBuf[1024];

/* Buffer containing the received data */
unsigned int rxBuf[1024];

/* hardware attributes */
extern QSPI_HwAttrs qspiInitCfg[QSPI_PER_CNT];

/* transfer length */
uint32_t transferLength = 0;


bool spi_read_write(S25FL_Handle flashHandle, uint32_t blockNum, uint32_t transferLength)
{
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    SPI_Handle        handle;            /* SPI handle */
    QSPI_HwAttrs     *hwAttrs;           /* QSPI hardware attributes */
    bool              retVal = false;    /* return value */
    uint32_t          addressValue, addrValue;

    /* Extract hardware attributes */
    handle = flashHandle->spiHandle;
    hwAttrs = (QSPI_HwAttrs *)handle->hwAttrs;

    /* Erase block, to which data has to be written */
    S25FLFlash_BlockErase(flashHandle, blockNum);

    /* Generate the data */
    GeneratePattern((uint8_t *)&txBuf[0], (uint8_t *)&rxBuf[0], transferLength);

    /* Update target address based on the modes. For config mode pass the
       address of the variable containing the flash offset value.
       For memory mapped mode directly pass the flash offset value. */
    addrValue = blockNum * S25FL_FLASH_BLOCK_SIZE;
    addressValue = (QSPI_OPER_MODE_CFG == hwAttrs->operMode) ?
        (uint32_t)&addrValue: addrValue;

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)&txBuf[0];
    flashTransaction.address    = addressValue;
    flashTransaction.dataSize   = transferLength * 4;  /* In bytes */

    /* Write buffer to flash */
    retVal = SF25FL_bufferWrite(flashHandle, &flashTransaction);
    if (retVal == false)
        goto Err;

    if(QSPI_RX_LINES_QUAD == hwAttrs->rxLines)
    {
        S25FLFlash_QuadModeEnable(flashHandle);
    }

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)&rxBuf[0];
    flashTransaction.address    = addressValue;
    flashTransaction.dataSize   = transferLength * 4; /* In bytes */

    /* Read data from flash */
    retVal = SF25FL_bufferRead(flashHandle, &flashTransaction);
    if (retVal == false)
        goto Err;

    /* Verify Data */
    retVal = VerifyData((unsigned char *)&txBuf[0], (unsigned char *)&rxBuf[0],
        transferLength);

Err:
    return (retVal);
}

/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    SPI_Params   spiParams;              /* SPI params structure */
    S25FL_Handle flashHandle;            /* Flash handle */
    bool         retVal = false;         /* return value */

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open QSPI driver */
    flashHandle = SF25FL_open(((QSPI_INSTANCE - 1)+(QSPI_OFFSET)), &spiParams);

    /* Print flash Id */
    FlashPrintId(flashHandle);

    /* Set the transfer length in number of 32 bit words */
    transferLength = 50;

    /* read/write test on block 0, address 0 */
    retVal = spi_read_write(flashHandle, 0, transferLength);
    if (retVal == true)
    {
        /* read/write test on block 256, address 16M */
        retVal = spi_read_write(flashHandle, 256, transferLength);
    }

    SF25FL_close(flashHandle);

    if(true == retVal)
    {
        SPI_log("\n All tests have passed. \n");
    }
    else
    {
        SPI_log("\n Some tests have failed. \n");
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

#if defined(SOC_AM574x) || defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x)
    QSPI_board_crossbarInit();
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}


/*
 *  ======== QSPI_board_crossbarInit ========
 */
#if defined(SOC_AM574x) || defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x)
void QSPI_board_crossbarInit(void) {
#ifndef __ARM_ARCH_7A__
    CSL_XbarIrqCpuId                   cpu;
    uint32_t                           cpuEvent;
    uint32_t                           xbarIndex;
#endif
#ifdef _TMS320C6X
    /* Configure xbar connect for MCSPI3: DSP_IRQ_38 mapped to MCSPI3 intr */
    cpu = CSL_XBAR_IRQ_CPU_ID_DSP1;
    cpuEvent = 38;
    xbarIndex = cpuEvent - 31;

    /* Configure xbar */
    CSL_xbarIrqConfigure (cpu, xbarIndex, CSL_XBAR_QSPI_IRQ);

#elif __ARM_ARCH_7A__
    /* Configure xbar connect for QSPI: MPU_IRQ_35 mapped to QSPI intr */
    CSL_xbarIrqConfigure (CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_35, CSL_XBAR_QSPI_IRQ);

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
