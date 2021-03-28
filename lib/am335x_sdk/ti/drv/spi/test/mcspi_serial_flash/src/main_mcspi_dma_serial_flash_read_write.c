/**
 *  \file   main_serial_flash_read_write.c
 *
 *  \brief  Example application main file. This application will write and read
 *          the data to/from serial flash through mcspi interface.
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
#include <ti/drv/spi/test/src/SPI_log.h>

/* Flash header file */
#include "W25Q.h"

#include <ti/board/board.h>
#include <ti/drv/spi/soc/SPI_soc.h>

/* EDMA3 Header files */
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/rm/sample/bios6_edma3_rm_sample.h>

#include <ti/sysbios/family/arm/a8/Cache.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

#define MCSPI_INSTANCE      (1U)

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

static EDMA3_RM_Handle MCSPIApp_edmaInit(void);
void Cache_writeBack_Invalidate(void *ptr, int32_t count);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    SPI_Params spiParams;                /* SPI params structure */
    W25QFL_Handle flashHandle;            /* Flash handle */
    bool retVal = false;                 /* return value */
    volatile uint32_t count = 0x6FFFFFU;
    SPI_HWAttrs spi_cfg;

    /* Get the default SPI init configurations */
    SPI_socGetInitCfg(MCSPI_INSTANCE - 1, &spi_cfg);
    spi_cfg.chNum = 0;
    spi_cfg.enableIntr = false;
    spi_cfg.rxTrigLvl = 1;
    spi_cfg.txTrigLvl = 1;
    spi_cfg.edmaHandle = MCSPIApp_edmaInit();
    spi_cfg.dmaMode = true;

    /* Set the SPI init configurations */
    SPI_socSetInitCfg(MCSPI_INSTANCE - 1, &spi_cfg);

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);
    spiParams.bitRate = 24000000U;

    /* Open QSPI driver */
    flashHandle = W25QFL_open((MCSPI_INSTANCE - 1), &spiParams);

    /* Enable flash for writing data. */
    W25QFL_WriteEnable(flashHandle);

    /*
     * Wait until write enable command is successfully written to
     * flash.
     */
    while(FALSE == W25QFL_IsWriteSuccess(flashHandle));

    /* Erase a sector of flash.*/
    W25QFL_SectorErase(flashHandle);

    /* Pass the write enable command to flash.*/
    W25QFL_WriteEnable(flashHandle);

    /* Wait until write enable command is successfully written to flash.*/
    while(FALSE == W25QFL_IsWriteSuccess(flashHandle));

    /* Write data of 1 page size to flash.*/
    /* Currently the data is programmed for 256 bytes
       and is not configurable.*/
    W25QFL_WriteToFlash(flashHandle);

    /* Delay for Write to happen to Flash. */
    while(count--);

    /* Read data of 1 page size from flash.*/
    W25QFL_ReadFromFlash(flashHandle);

    count = 0x6FFFFFU;
    /* Delay for read to happen from Flash. */
    while(count--);

    /* Verify the data written to and read from flash are same or not.*/
    retVal = W25QFL_VerifyData();

    W25QFL_close(flashHandle);

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

    /* Start BIOS */
    BIOS_start();
    return (0);
}

/**
 * \brief      Function to initialize the edma driver and get the handle to the
 *             edma driver;
 *
 */
static EDMA3_RM_Handle MCSPIApp_edmaInit(void)
{
    EDMA3_DRV_Result edmaResult = EDMA3_DRV_E_INVALID_PARAM;
    EDMA3_RM_Handle gEdmaHandle = NULL;
    uint32_t edma3Id = 0;

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

/**
 * \brief  Cache clean and invalidate operation.
 *
 */
void Cache_writeBack_Invalidate(void *ptr, int32_t count)
{
    Cache_wbInv((Ptr) ptr, count, Cache_Type_ALL, (Bool) TRUE);
}
