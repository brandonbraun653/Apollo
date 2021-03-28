/**
 *  \file   mmcsd_main.c
 *
 *  \brief  Test application main file. The test application demonstrates
 *          raw data write & read on a MMCSD device.
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


/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/board/board.h>
#ifdef DIAG_STRESS_TEST
#include "diag_common_cfg.h"
#endif
/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

/* Global data pointers */
#define HSMMCSD_DATA_SIZE               512

#define PAGE_OFFSET   0x0
#define MMCSTARTSECTOR  0x300000 //@1.5GB //100

#if defined(DIAG_COMPLIANCE_TEST)
#define MMCTESTSECTORS (0x1U)
#else
#define MMCTESTSECTORS  0x20 //0x800 //0x5000  //10MB //512
#endif

#define DATA_PATTERN_00     0
#define DATA_PATTERN_FF     1
#define SDMMC_DATA_PATTERN_AA 2
#define SDMMC_DATA_PATTERN_55 3
#define SDMMC_DATA_PATTERN_AA_55 4
#define SDMMC_DATA_PATTERN_INC  8

#define SECTORSIZE    (512)
#ifdef DIAG_STRESS_TEST
#define TESTSECTORS    512 //16 //1
#else
#define TESTSECTORS    1 //16 //1
#endif

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define MMCSD_log                UART_printf
#else
#define MMCSD_log                printf
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

static int32_t HSMMCSDReadWriteTest(MMCSD_Handle handle);

static int32_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag);

/* Delay function */
static void delay(unsigned int delayValue);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

MMCSD_Handle handle = NULL;
static uint8_t tx[SECTORSIZE*TESTSECTORS];
static uint8_t rx[SECTORSIZE*TESTSECTORS];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
    Board_init(boardCfg);
#ifdef DIAG_STRESS_TEST
	UART_printf("\n*********************************************\n");
    UART_printf  ("*                 MMCSD Stress Test         *\n");
    UART_printf  ("*********************************************\n");
#else
    UART_printf("\n*********************************************\n"); 
    UART_printf  ("*                MMCSD Test                 *\n");
    UART_printf  ("*********************************************\n");
#endif
    MMCSD_init();

    MMCSD_open(BOARD_MMCSD_SD_INSTANCE, NULL, &handle);

    return HSMMCSDReadWriteTest(handle);
}

int32_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag)
{
    int32_t i;
    uint32_t data = 0x00;
    uint8_t incFlag = 0x00;
	uint8_t checkerBoard = 0;

    switch(flag)
    {
        case DATA_PATTERN_00:
            data = 0;
            break;
        case DATA_PATTERN_FF:
            data = 0xFF;
            break;
        case SDMMC_DATA_PATTERN_AA:
            data = 0xAA;
            //MMCSD_log("\nSD Read/Write pattern 0xAA ");
            break;
        case SDMMC_DATA_PATTERN_55:
            data = 0x55;
            //MMCSD_log("\nSD Read/Write pattern 0x55 ");
            break;
        case SDMMC_DATA_PATTERN_AA_55:
            checkerBoard = 1;
            data = 0xAA;
            //MMCSD_log("\nSD Read/Write pattern 0x55 ");
            break;
        case 8:
             data = 0x00;
             incFlag = 0x01;
             //MMCSD_log("\nSD Read/Write incremental data");
             break;
		default:
            return -1;
    }

    for(i =0; i < length; i++)
    {
        *(buf+i) = data;
        if(incFlag)
            data++;
		if(checkerBoard)
            data = ~data;
    }



    return 0;
}

int32_t HSMMCSDReadWriteTest(MMCSD_Handle handle)
{
  int32_t j, testIteration = 0;
  unsigned long int blockNum;
  int32_t retVal = 0;
  
  testIteration = testIteration;
#ifdef DIAG_STRESS_TEST
/* Media configuration such as SD card size, blocksize, blockCount */
  uint32_t blockCount;
  char rdBuf = 'y';
  MMCSD_mediaParams  mediaParams;
  MMCSD_log("Getting SD Card parameters\n");
  if((retVal = MMCSD_control(handle, MMCSD_CMD_GETMEDIAPARAMS, (void *)&mediaParams)) != MMCSD_OK)
  {
    MMCSD_log("Getting SD Card parameters failed !!");
    MMCSD_close(handle);
    return -1;
  }
  blockCount = (unsigned int)(mediaParams.blockCount & 0xFFFFFFFF);
  MMCSD_log("SD Card: BlockCount = 0x%x \n",(unsigned int)(mediaParams.blockCount & 0xFFFFFFFF));
  
  for(blockNum = MMCSTARTSECTOR; blockNum < blockCount; blockNum+=TESTSECTORS)
#else
  for(blockNum = MMCSTARTSECTOR; blockNum < (MMCTESTSECTORS+MMCSTARTSECTOR); blockNum+=TESTSECTORS)
#endif
  {
#if defined(DIAG_COMPLIANCE_TEST)
    testIteration = SDMMC_DATA_PATTERN_AA_55;
#else
    testIteration = SDMMC_DATA_PATTERN_INC;
#endif

    fillMmcPageData(&tx[0], (SECTORSIZE*TESTSECTORS), SDMMC_DATA_PATTERN_AA);

    retVal = MMCSD_write(handle, &tx[0], blockNum, TESTSECTORS);

    if(retVal != MMCSD_OK)
    {
		MMCSD_log("FAIL: Write failed on sector %d", blockNum);
        MMCSD_close(handle);
        return -1;
    }

    delay(100);

    /* Clear receive buffer */
    fillMmcPageData(&rx[0], (SECTORSIZE*TESTSECTORS), DATA_PATTERN_00);

    /* Read a page */
    retVal = MMCSD_read(handle, &rx[0], blockNum, TESTSECTORS);

    if(retVal != MMCSD_OK)
    {
        MMCSD_log("FAIL: Read failed on sector %d", blockNum);
        MMCSD_close(handle);
        return -1;
    }

    /* Check the pattern */
    for ( j = 0 ; j < (SECTORSIZE*TESTSECTORS) ; j++ )
    {
		/* Compare the data read against the expected */
		if ( tx[j] != rx[j])
		{
			MMCSD_log ("FAIL: Data comparison failed @ ");
			MMCSD_log("sector %d", blockNum);
			MMCSD_log(" ,data %d", j);
			MMCSD_log(" ,rx = %x", rx[j]);
			MMCSD_log(" ,tx = %x", tx[j]);
            MMCSD_close(handle);
			return -1;
		}
	}
	if(!(blockNum & 0xfff))
	MMCSD_log ("\nPASS: Read/Write Success for this block-0x%x\r\n",blockNum);

#ifdef DIAG_STRESS_TEST
        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n\n");
            break;
        }
#endif
  }

#ifdef DIAG_STRESS_TEST
    UART_printf("MMCSD Stress Test Status\n");
    UART_printf("============================================\n");
    UART_printf("PASS: Read/Write Success till the block-0x%x\r\n",blockNum);
    UART_printf("MMCSD Stress Test Passed!\n");
#else
  MMCSD_log ("\nPASS: Read/Write Success for this pattern\r\n");
#endif
  MMCSD_close(handle);
  return 0;
}

/*
 *  ======== Delay function ========
 */
static void delay(unsigned int delayValue)
{
    volatile uint32_t delay1 = delayValue*10000;
    while (delay1--) ;
}
