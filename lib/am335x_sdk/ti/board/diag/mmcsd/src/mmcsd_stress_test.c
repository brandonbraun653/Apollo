/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   mmcsd_test.c
 *
 *  \brief  mmcsd diagnostic test file
 *
 *  Targeted Functionality: Verification of basic functionality of
 *  mmcsd external memory interface.
 *
 *  Operation: This test is used for verification of the mmcsd memory access by
 *  writing a test pattern to a sector and reading the same pattern from the 
 *  written sector for data validation in 4-bit mode with maximum possible speed
 *  supported in uHs and DDR modes.
 *
 *  Supported SoCs: AM65XX.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 *
 */

#include "mmcsd_stress_test.h"

/* MMCSD Handle */
MMCSD_Handle handle = NULL;
/* mmcsd transmitt buffer */
static uint8_t tx[SECTORSIZE];
/* mmcsd receive buffer */
static uint8_t rx[SECTORSIZE];

/**
 *  \brief    This writes performs the MMCSD read write test by writting a 
 *            sector with a fixed pattern and reading it back for data 
 *            comparison and it also clears the sectors used for testing at 
 *            the end.
 *
 *  \param    handle              [IN]   MMCSD Handler
 *            sectorNum           [IN]   Offset number of the sector
 *                                       to be verified
 *  \return   int8_t 
 *               0 - Sector read/write successful
 *              -1 - Sector read/write failed
 *
 */
static int8_t BoardDiag_mmcsd_read_write_test(MMCSD_Handle handle,
                                              uint32_t sectorNum)
{
    int32_t retVal = 0;
    uint32_t failIndex = 0;
    bool compareStatus = 1;

    BoardDiag_genPattern(&tx[0], SECTORSIZE, BOARD_DIAG_TEST_PATTERN_RANDOM);

    retVal = MMCSD_write(handle, &tx[0], sectorNum, TESTSECTORS);
    if(retVal != MMCSD_OK)
    {
        MMCSD_log("\nFAIL: Write failed on sector %d\n", sectorNum);
        return -1;
    }

    /* Clear receive buffer */
    BoardDiag_genPattern(&rx[0], SECTORSIZE, BOARD_DIAG_TEST_PATTERN_NULL);
    
    /* Read a page */
    retVal = MMCSD_read(handle, &rx[0], sectorNum, TESTSECTORS);
    if(retVal != MMCSD_OK)
    {
        MMCSD_log("\nFAIL: Read failed on sector %d\n", sectorNum);
        return -1;
    }

    /* Data comparison */
    compareStatus = BoardDiag_memCompare(&tx[0], &rx[0], SECTORSIZE, 
                    &failIndex);
    if(!(compareStatus))
    {
        MMCSD_log ("\nFAIL: Data comparison failed @ \n");
        MMCSD_log("\nsector %d", sectorNum);
        MMCSD_log(" ,data %d", failIndex);
        MMCSD_log(" ,rx = %x", rx[failIndex]);
        MMCSD_log(" ,tx = %x\n", tx[failIndex]);
        return -1;        
    }

    BOARD_delay(100);
  
    /* Clear transmitt buffer */
    BoardDiag_genPattern(&tx[0], SECTORSIZE, BOARD_DIAG_TEST_PATTERN_FF);

    /* Clears the data written on to mmcsd Sectors */
    retVal = MMCSD_write(handle, &tx[0], sectorNum, TESTSECTORS);
    if(retVal != MMCSD_OK)
    {
		MMCSD_log("FAIL: Clearing the sector %d failed\n", sectorNum);
        return -1;
    }

    MMCSD_log ("\nPASS: Read/Write Success for this pattern\r\n");

    return 0;
}

/**
 *  \brief    This test verifies the mmcsd memory under stress conditions by 
 *            performing continuously writting and reading all the mmcsd sectors
 *            with and fixed pattern for a longer period of time.
 *
 *  \param    handle              [IN]   MMCSD Handler
 *            sectorNum           [IN]   Offset number of the sector
 *                                       to be tested.
 *
 *  \return   int8_t 
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
static int8_t BoardDiag_mmcsd_memory_verification_stress_test(MMCSD_Handle handle)
{
    int8_t ret = 0;
    uint32_t sectorNum;
    uint16_t iteration;
    
    for(sectorNum = 0; sectorNum < TEST_SECTOR_OFFSET; sectorNum++)
    {
        UART_printf("\n\rTest Iteration - %d and eMMC Sector number - "
                    "%d\n\r", iteration, sectorNum);
        ret = BoardDiag_mmcsd_read_write_test(handle, sectorNum);
        if(ret != 0)
        {
            UART_printf("\nmmcsd memory verification failed at"
            "sector - %d under stress conditions\n\r", sectorNum);
            break;
        }
    }

    return ret;
}

/**
 *  \brief    Performs the mmcsd read write test to verify mmcsd memory
 *            under stress conditions.
 *
 *  \return   int8_t  
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
static int8_t BoardDiag_run_mmcsd_stress_test(void)
{
    int8_t ret = 0;

#if  defined(SOC_AM571x) || defined(SOC_AM572x)
	if(MMCSD_socGetInitCfg(1,&hwAttrsConfig)!=0) {
		UART_printf ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
		return -1;
	}
	
    /* SBL sets the input clock to 128 Mhz in the CM_L3INIT_MMC2_CLKCTRL */
    hwAttrsConfig.inputClk = 128000000;
	
	if(MMCSD_socSetInitCfg(1,&hwAttrsConfig)!=0) {
		UART_printf("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
		return -1;
	}
#endif

    MMCSD_init();

    MMCSD_open(0U, NULL, &handle); /* MAXIE_TBD: Proper index number should be passed,  
                                                 by checking the Maxwell mmcsd driver */    

    UART_printf("\nrunning MMCSD memory verification test under stress\n\r"
                "conditions...\r\n");

    ret = BoardDiag_mmcsd_memory_verification_stress_test(handle);
    if(ret != 0)
    {
		UART_printf("\nMMCSD memory verification test under stress\n\r"
                    "conditions failed\r\n");
		return ret;        
    }
    
    UART_printf("\nMMCSD memory verification test under stress\n\r"
                "conditions passed\r\n");

    return ret;    
}

/**
 *  \brief   mmcsd stress test main function.
 *
 *  \return  int - mmcsd stress test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
	int8_t ret = 0;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

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

    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 MMCSD Stress Test         *\n");
    UART_printf  ("*********************************************\n");

    ret = BoardDiag_run_mmcsd_stress_test();
    if(ret == 0)
    {
        UART_printf("\nMMCSD stress test Passed\n");            
    }
    else
    {
        UART_printf("\nMMCSD stress test Failed\n");
    }
       
    return ret;
}
