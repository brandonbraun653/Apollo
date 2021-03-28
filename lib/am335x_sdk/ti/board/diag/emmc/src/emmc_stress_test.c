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
 *  \file   emmc_stress_test.c
 *
 *  \brief  eMMC stress test file
 *
 *  Targeted Functionality: Verification of eMMC memory interface
 *  under stress conditions.
 *
 *  Operation: This test is used for verification of the eMMC memory access by
 *  writing a random test pattern to all the sectors one at a time and reading
 *  the same pattern from the written sector with the max clock speed
 *  supported in 8-bit mode.
 *
 *  Supported SoCs: AM65x.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 *
 */

#include "emmc_stress_test.h"
 
/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM572X EMMC_RST */
    GPIO_DEVICE_CONFIG(GPIO_EMMC_RST_PORT_NUM, GPIO_EMMC_RST_PIN_NUM) | \
    GPIO_CFG_OUTPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

#ifdef SOC_K2G
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#else
/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#endif

/* MMCSD Handle */
MMCSD_Handle handle = NULL;
/* EMMC transmit buffer */
static uint8_t tx[SECTORSIZE];
/* EMMC receive buffer */
static uint8_t rx[SECTORSIZE];

/**
 *
 *  \brief    This function is used to reset the EMMC module.
 *
 */
static void EmmcReset(void)
{
    /* EMMC reset */
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_LOW);
    BOARD_delay(100);
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_HIGH);
    BOARD_delay(100);
}

/**
 *  \brief    Performs the MMCSD Read Write Test by writing a 
 *            sector with a random pattern generated and reading it back
 *            for data comparison. Clears the sectors used for testing
 *            at the end.
 *
 *  \param    handle              [IN]   MMCSD Handler
 *            sectorNum           [IN]   eMMC Sector offset number to be   
 *                                       verified
 *
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
    
    BOARD_delay(100);

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
                                   
    /* Clear transmit buffer */
    BoardDiag_genPattern(&tx[0], SECTORSIZE, BOARD_DIAG_TEST_PATTERN_FF);

    /* Clears the data written on to eMMC Sectors */
    retVal = MMCSD_write(handle, &tx[0], sectorNum, TESTSECTORS);

    if(retVal != MMCSD_OK)
    {
		MMCSD_log("FAIL: Clearing the sector %d failed\n", sectorNum);
        return -1;
    }
    
    return 0;
}

/**
 *  \brief    This test verifies all the eMMC sectors continuously over  
 *            6 to 8 hours.
 *
 *  \param    handle              [IN]   MMCSD Handler.
 *
 *  \return   int8_t 
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
static int8_t BoardDiag_emmc_verify_all_sectors(MMCSD_Handle handle)
{
    int8_t  ret = 0;
    uint8_t writePattern;
    int32_t sectorNum;    

	for(sectorNum = 0; sectorNum < TOTAL_EMMC_SECTORS; sectorNum++)/* MAXIE_TBD: TOTAL_EMMC_SECTORS Macro need to be
																		         updated with the actual no:of sectors 
																		         exists on the Maxwell eMMC card*/
	{
		UART_printf("\n\r eMMC Sector number - %d\n\r", sectorNum);
		ret = BoardDiag_mmcsd_read_write_test(handle, sectorNum);
		if(ret != 0)
		{
			UART_printf("\neMMC sector - %d verification failed\r\n", sectorNum);
			return ret;
		}
	}

    MMCSD_log("\nPASS: Read/Write Success for this pattern\r\n");

    return ret;
}

/**
 *  \brief    Resets the eMMC and performs the MMCSD read write test
 *            to verify eMMC memory under stress conditions.
 *
 *  \return   int8_t  
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
static int8_t BoardDiag_EmmcStressTest(void)
{
    int8_t ret = 0;
	int32_t retVal = 0;

    GPIO_init();

    EmmcReset();/* MAXIE_TBD: For Maxwell the EMMC reset GPIO pin is not directly 
                               connected to SOC but it it connectd to a I2C IO Expander.
                               So, need to add the support for Maxwell EMMC Reset. */
    retVal = MMCSD_init();
	if(retVal != MMCSD_OK)
    {
		UART_printf("FAIL: MMCSD Initialization failed\n");
        return -1;
    }

    retVal = MMCSD_open(1U, NULL, &handle); /* MAXIE_TBD: Proper index number should be passed,  
											              by checking the Maxwell mmcsd driver */
	if(retVal != MMCSD_OK)
    {
		UART_printf("FAIL: MMCSD Open failed\n");
        return -1;
    }

    UART_printf("\nVerifying the eMMC memory interface under stress\n\r"
                "conditions....\r\n");    

    ret = BoardDiag_emmc_verify_all_sectors(handle);
    if(ret != 0)
    {
		UART_printf("\nVerification of eMMC memory interface under stress\n\r"
                    "conditions failed\r\n");
		return ret;        
    }
    
    UART_printf("\nVerification of eMMC memory interface under stress\n\r"
                "conditions Passed\r\n");

    return ret;    
}

/**
 *  \brief   eMMC Stress test main function.
 *
 *  \return  int - eMMC Stress test status.
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
    UART_printf("*                 eMMC Stress Test            *\n");
    UART_printf("***********************************************\n");
  
    ret = BoardDiag_EmmcStressTest();
    if(ret == 0)
    {
        UART_printf("\neMMC stress test Passed\n");            
    }
    else
    {
        UART_printf("\neMMC stress test Failed\n");
    }
       
    return ret;
}
