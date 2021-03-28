/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

/**
 *  \file   ospi_test.c
 *
 *  \brief  ospi diagnostic test main file
 *
 *  Targeted Functionality: This file implements OSPI diagnostic test.
 *
 *  Operation:This test verifies the SPI flash memory read and write access by
 *  writing a test pattern to a memory page and reading the same page for
 *  data verification.
 *
 *  Supported SoCs : AM65XX & J721E
 *
 *  Supported Platforms: am65xx-evm,am65xx-idk & j721e_evm.
 *
 */

#include "ospi_test.h"
#include <ti/board/src/flash/nor/nor.h>

/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[MAX_BUFF_SIZE];
/* Buffer containing the received data */
uint8_t rxBuf[MAX_BUFF_SIZE] ;
uint8_t verifyBuf[MAX_BUFF_SIZE];

#if defined(UDMA_ENABLE)
/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaChObj;
struct Udma_EventObj    gUdmaCqEventObj;

Udma_DrvHandle          gDrvHandle = NULL;
/*
 * UDMA Memories
 */
static uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxTdCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaTprdMem[UDMA_TEST_APP_TRPD_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static OSPI_dmaInfo gUdmaInfo;

/**
 *  \brief		This function initializes the UDMA module .
 *
 *  \param		cfg		[IN]	OSPI HW Attributes.
 *
 *  \return		int32_t
 *				UDMA_SOK in case of success or appropriate error code
 *
 */
static int32_t ospiUdmaInit(OSPI_v0_HwAttrs *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    if (gDrvHandle == NULL)
    {
        /* UDMA driver init */
#if defined (__aarch64__)
        instId = UDMA_INST_ID_MAIN_0;
#else
        instId = UDMA_INST_ID_MCU_0;
#endif
        UdmaInitPrms_init(instId, &initPrms);
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
    }

    if(gDrvHandle != NULL)
    {
        gUdmaInfo.drvHandle      = (void *)gDrvHandle;
        gUdmaInfo.chHandle       = (void *)&gUdmaChObj;
        gUdmaInfo.ringMem        = (void *)&gTxRingMem[0];
        gUdmaInfo.cqRingMem      = (void *)&gTxCompRingMem[0];
        gUdmaInfo.tdCqRingMem    = (void *)&gTxTdCompRingMem[0];
        gUdmaInfo.tprdMem        = (void *)&gUdmaTprdMem[0];
        gUdmaInfo.eventHandle    = (void *)&gUdmaCqEventObj;
        cfg->dmaInfo             = &gUdmaInfo;
    }
    return (retVal);
}


/**
 *  \brief		This function De initializes the UDMA module.
 *
 *  \param		void
 *
 *  \return		int32_t
 *				UDMA_SOK in case of success or appropriate error code
 *
 */
static int32_t ospiUdmaDeinit(void)
{
    int32_t   retVal = UDMA_SOK;

    if (gDrvHandle != NULL)
    {
        retVal = Udma_deinit(gDrvHandle);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = NULL;
        }
    }
    return (retVal);
}
#endif

/**
 * \brief  ospi flash read/write test function
 *
 *  This test executes OSPI NOR flash memory read/write test by writing
 *  a pattern to to the memory and reading the same  for the 
 *  verification.
 *
 * \return  int8_t
 *             0  - In case of success
 *            -1  - In case of failure
 *
 */
static int8_t BoardDiag_ospiReadWriteTest(Board_flashHandle  handle,
                                          uint32_t offset)
{
    uint32_t blockNum, pageNum;      /* Block, page number */
    uint32_t failIndex;
    uint32_t writeMode;
    uint32_t readMode;

    writeMode = OSPI_FLASH_OCTAL_PAGE_PROG;
    readMode = OSPI_FLASH_OCTAL_READ;

    if (Board_flashOffsetToBlkPage(handle,offset,&blockNum, &pageNum))
    {
        UART_printf("\n Board_flashOffsetToBlkPage failed. \n");
        return -1;
    }

    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(handle, blockNum))
    {
        UART_printf("\n Board_flashEraseBlk failed. \n");
        return -1;
    }

    /* Write buffer to flash */
    if (Board_flashWrite(handle, offset,
                        (uint8_t *)&txBuf,TEST_DATA_LEN, &writeMode))
    {
        UART_printf("\n Board_flashWrite failed. \n");
        return -1;
    }

    /* Read the flash memory */
    if (Board_flashRead(handle, offset,
                      (uint8_t *)&rxBuf, TEST_DATA_LEN, &readMode))
    {
        UART_printf("\n Board_flashRead failed. \n");
        return -1;
    }

    /* Verify Data */
    if (BoardDiag_memCompare(&txBuf[0],&rxBuf[0],TEST_DATA_LEN, &failIndex) == false)
    {
        UART_printf("\n Data mismatch at offset = 0x%x\n", failIndex);
        return -1;
    }

    /* Erase block */
    if (Board_flashEraseBlk(handle, blockNum))
    {
        UART_printf("\n Board_flashEraseBlk failed. \n");
        return -1;
    }
    
    return 0;
}

#ifdef DIAG_STRESS_TEST
/**
 * \brief  ospi flash stress test function
 *
 *  This test verifies the OSPI flash memory by Writing and reading
 *  whole memory of OSPI flash
 *
 * \return  int8_t
 *             0  - in case of success
 *            -1  - in case of failure
 *
 */
static int8_t BoardDiag_ospiFlashStressTest(void)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    bool testStatus = 0;          /* return value */
    uint32_t offset;
    char rdBuf = 'y';
    OSPI_v0_HwAttrs ospi_cfg;

    /* Get the default OSPI init configurations */
    OSPI_socGetInitCfg(BOARD_OSPI_INSTANCE, &ospi_cfg);

    /* Modify the default OSPI configurations if necessary */
    ospi_cfg.intrEnable = false;

#if defined(UDMA_ENABLE)
    ospi_cfg.dmaEnable  = true;
    ospiUdmaInit(&ospi_cfg);
#else
    ospi_cfg.dmaEnable  = false;
#endif

    /* Set the default OSPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_INSTANCE, &ospi_cfg);

    /* Open the Board OSPI NOR device with SPI port 0
       and use default OSPI configurations */
    boardHandle = Board_flashOpen(BOARD_FLASH_ID_MT35XU512ABA1G12,
                                  BOARD_OSPI_INSTANCE, NULL);
    if (!boardHandle)
    {
        UART_printf("\n Board_flashOpen Failed. \n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\nOSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    /* Generate the data */
    BoardDiag_genPattern((uint8_t *)&txBuf[0], TEST_DATA_LEN,
                         BOARD_DIAG_TEST_PATTERN_RANDOM);

    UART_printf("\nVerifying the OSPI Flash ...\n");
    /* This loop verifies the read/write access of whole memory */

    for(offset=BOARD_OSPI_FIRST_PAGE; offset<=BOARD_OSPI_LAST_PAGE; offset+=NOR_PAGE_SIZE)
    {
        testStatus = BoardDiag_ospiReadWriteTest(boardHandle,offset);
        if(testStatus != 0)
        {
            UART_printf("OSPI NOR Flash page verification Failed at \
                                offset 0x%x\n",offset);
            Board_flashClose(boardHandle);
            return -1;
        }

        if(!(offset % 0x1000))
        {
            UART_printf("\nVerified upto Page - 0x%X\n", offset);
        }
        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            offset+=NOR_PAGE_SIZE;
            UART_printf("OSPI NOR Flash Stress Test Status\n");
            UART_printf("============================================\n");
            UART_printf("\nOSPI NOR Flash Verified up-to Page - 0x%X\n", offset);
            break;
        }
    }

    UART_printf("\nOSPI NOR Flash verification Successful\n");

    Board_flashClose(boardHandle);

#if defined(UDMA_ENABLE)
    ospiUdmaDeinit();
#endif

    return testStatus;
}
#else
/**
 * \brief  ospi flash test function
 *
 *  This test executes OSPI NOR flash memory test by writing a pattern to
 *  to the first and last pages of the memory and reading the same  for the
 *  verification.
 *
 * \return  int8_t
 *             0  - In case of success
 *            -1  - In case of failure
 *
 */
static int8_t BoardDiag_ospiFlashTest(void)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    bool testStatus = true;          /* return value */
    OSPI_v0_HwAttrs ospi_cfg;

    /* Get the default OSPI init configurations */
    OSPI_socGetInitCfg(BOARD_OSPI_INSTANCE, &ospi_cfg);

    /* Modify the default OSPI configurations if necessary */
    /* Turning off interrupts for baremetal mode. May be re-enabled by app */
    ospi_cfg.intrEnable = false;

#if defined(UDMA_ENABLE)
    ospi_cfg.dmaEnable  = true;
    ospiUdmaInit(&ospi_cfg);
#else
    ospi_cfg.dmaEnable  = false;
#endif
#if defined(j721e_evm)
    ospi_cfg.phyEnable  = false;
#endif

    /* Set the default OSPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_INSTANCE, &ospi_cfg);

    /* Open the Board OSPI NOR device with OSPI port 0
       and use default OSPI configurations */

    boardHandle = Board_flashOpen(BOARD_FLASH_ID_MT35XU512ABA1G12,
                                  BOARD_OSPI_INSTANCE, NULL);
    if (!boardHandle)
    {
        UART_printf("\n Board_flashOpen Failed. \n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\nOSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

#if defined(DIAG_COMPLIANCE_TEST)
	/* Generate the data */
    BoardDiag_genPattern((uint8_t *)&txBuf[0], TEST_DATA_LEN,
                         BOARD_DIAG_TEST_PATTERN_AA_55);
#else
    /* Generate the data */
    BoardDiag_genPattern((uint8_t *)&txBuf[0], TEST_DATA_LEN,
                         BOARD_DIAG_TEST_PATTERN_RANDOM);
#endif

    UART_printf("\n Verifying the OSPI Flash first page...\n");
    testStatus = BoardDiag_ospiReadWriteTest(boardHandle, BOARD_OSPI_FIRST_PAGE);
    if(testStatus == 0)
    {
        UART_printf("OSPI NOR Flash first page verification Successful\n");
    }
    else
    {
        UART_printf("OSPI NOR Flash first page verification Failed\n");
        return -1;
    }
#if !defined(DIAG_COMPLIANCE_TEST)
    UART_printf("\n Verifying the OSPI Flash last page...\n");
    testStatus = BoardDiag_ospiReadWriteTest(boardHandle, BOARD_OSPI_LAST_PAGE);
    if(testStatus == 0)
    {
        UART_printf("OSPI NOR Flash last page verification Successful\n");
    }
    else
    {
        UART_printf("OSPI NOR Flash last page verification Failed\n");
        return -1;
    }
#endif
    UART_printf("\nOSPI NOR Flash verification Successful\n");

#if defined(UDMA_ENABLE)
    ospiUdmaDeinit();
#endif
    Board_flashClose(boardHandle);

    return 0;
}
#endif

/**
 * \brief  OSPI mux selection function.
 *
 * This function selects OSPI lines by enabling the GPIO pin which is used
 * for selecting OSPI/HYPER flash interfaces by muxer.
 *
 */
#if defined(SOC_J721E)
static void BoardDiag_ospiHyperFlashMux(void)
{
#if defined(SOC_J721E)
    GPIO_v0_HwAttrs gpioCfg;
    GPIO_socGetInitCfg(0, &gpioCfg);
    gpioCfg.baseAddr = CSL_WKUP_GPIO0_BASE;
    GPIO_socSetInitCfg(0, &gpioCfg);
#endif
    GPIO_init();
    GPIO_write(OSPI_HYPER_BUS_SEL_PIN, GPIO_PIN_LOW);
}
#endif

/**
 * \brief  spi test function
 *
 * This function executes spi flash test
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 */
int8_t BoardDiag_OspiTest(void)
{
    int8_t ret;

#if defined(SOC_J721E)
    BoardDiag_ospiHyperFlashMux();
#endif

#ifdef DIAG_STRESS_TEST
	UART_printf("\n****************************************************\n");
	UART_printf  ("*            OSPI FLASH Stress Test                *\n");
	UART_printf  ("****************************************************\n");
    ret = BoardDiag_ospiFlashStressTest();
#else
	UART_printf("\n*********************************************\n");
	UART_printf  ("*            OSPI FLASH Test                *\n");
	UART_printf  ("*********************************************\n");    
    ret = BoardDiag_ospiFlashTest();
#endif /* #ifndef DIAG_STRESS_TEST */

    if(ret)
    {
        UART_printf("\nOSPI Flash Test Failed!!\n");
    }
    else
    {
        UART_printf("\nOSPI Flash Test Passed!\n");
    }

    return ret;
}

/**
 * \brief  main function
 *
 *  This function performs board intializations and calls spi test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    return BoardDiag_OspiTest();
}
#endif

