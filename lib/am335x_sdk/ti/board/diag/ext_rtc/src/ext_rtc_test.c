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
 *  \file   ext_rtc_test.c
 *
 *  \brief  RTC test file
 *
 *  Targeted Functionality: Verifying the basic functionality of external RTC.
 *
 *  Operation: This test is used to verify the external RTC interface on the
 *  board by setting and reading the time configurations.
 *
 *  Supported SoCs: AM65xx & J721E.
 * 
 *  Supported Platforms: am65xx_evm, am65xx_idk and j721e_evm.
 * 
 */
 
#include "ext_rtc_test.h"

extern I2C_config_list I2C_config;
 
rtcTimeObj gtimeval =
 					 {
						0x53, /* setting MSB for enabling oscillator */
						0x59,
						0x71, /* setting 6th bit for enabling 12 hr mode */
							  /* setting 5th bit for indicating PM */
						0,
						0
					 };

rtcDateObj gdateval =
					 {
						1,
						0x31,
						0x12,
						0x18
					 };
					 
static char *gdayOfWeek[] = {"Sunday",
							 "Monday",
							 "Tuesday",
							 "Wednesday",
							 "Thursday",
							 "Friday",
							 "Saturday"
							};
							
static char *gmeridiem[] = {"AM",
							"PM"
						   };
 
/**
 *  \brief    Function to write a RTC register
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddress        [IN]   Slave Address
 *            regAddr             [IN]   Register address
 *            regData             [IN]   Data to be configured into the
 *                                       register.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcWriteRegister(I2C_Handle handle, uint8_t slaveAddress,
										 uint8_t regAddr, uint8_t regData)
{
    int16_t ret = 0;
    uint8_t tx[2];
    I2C_Transaction transaction;

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddress;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 2;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    tx[0] = regAddr;
	tx[1] = regData;

    BOARD_delay(DELAY);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("Failing while writing data by returning - %d\n\r", ret);
        return -1;
    }

	return 0;
}
 
/**
 *  \brief    Reads data from the specified RTC register.
 *
 *  \param    handle              [IN]       I2C Handler
 *            slaveAddress        [IN]       Slave Address
 *            regAddr             [IN]       Register address
 *            *rdRegval           [OUT]      Pointer to store the read 
 *                                           register value.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcReadRegister(I2C_Handle handle, uint8_t slaveAddress,
										uint8_t regAddr, uint8_t *rdRegval)
{
    int16_t  ret = 0;
    I2C_Transaction transaction;

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddress;
    transaction.writeBuf     = &regAddr;
    transaction.writeCount   = 1;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("Failed while writing the register address\n\r");
        return -1;
    }

    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = rdRegval;
    transaction.readCount    = 1;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("Failed while reading the register data by returning - %d\n\r", ret);
        return -1;
    }

    return 0;
}

/**
 *  \brief Function to display time,day of week and date on the serial console.
 *
 */
static void BoardDiag_rtcDisplayTimeDate(void)
{
	UART_printf("\n\n\rDisplaying time: %x:%x:%x", gtimeval.hour,
				gtimeval.minutes, gtimeval.seconds);
	if (gtimeval.timeMode) /* Checking whether the time is 12 or 24 hour mode */
	{
		UART_printf(" %s", gmeridiem[gtimeval.meridiemMode]); /* If it is 12 hour mode, display AM/PM */
	}

	UART_printf("\n\rDisplaying  Day: %s", gdayOfWeek[gdateval.day-1]);
	UART_printf("\n\rDisplaying Date: %x/%x/%x", gdateval.date, 
				gdateval.month, gdateval.year);
}
 
/**
 *  \brief    	The function reads week, date, month and year 
 *				from the specified registers of RTC.
 *
 *	\param    	handle              [IN]       I2C Handler
 *            	SlaveDevices        [IN]       Slave Address
 *                                             value.
 *  \return   	int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcGetDate(I2C_Handle handle, uint8_t slaveAddress)
{
	uint8_t rdData;
	int8_t ret;
	
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									WEEK_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Week value register failed\n\r");
		return -1;
	}
	else
	{
		gdateval.day = WEEK_MASK_VALUE & rdData;
	}
	
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									DATE_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Date value register failed\n\r");
		return -1;
	}
	else
	{
		gdateval.date = DATE_MASK_VALUE & rdData;
	}
	
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									MONTH_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Month value register failed\n\r");
		return -1;
	}
	else
	{
		gdateval.month = MONTH_MASK_VALUE & rdData;
	}
	
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									YEAR_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Year value register failed\n\r");
		return -1;
	}
	else
	{
		gdateval.year = YEAR_MASK_VALUE & rdData;
	}

	return 0;
}

/**
 *  \brief    	The function reads second, minute and hour value from
 *				specified RTC time registers.
 *
 *	\param    	handle			[IN]	I2C Handler
 *            	slaveAddress	[IN]	Slave Address value.
 *
 *  \return   	int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcGetTime(I2C_Handle handle, uint8_t slaveAddress)
{
	int8_t  ret;
	uint8_t rdData;
	
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									SEC_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Seconds value register failed\n\r");
		return -1;
	}
	else
	{
		gtimeval.seconds = SECOND_MASK_VALUE & rdData;
	}
		
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									MIN_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Minutes value register failed\n\r");
		return -1;
	}
	else
	{
		gtimeval.minutes = MINUTES_MASK_VALUE & rdData;
	}
								  
	ret = BoardDiag_rtcReadRegister(handle, slaveAddress,
									HOUR_REG, &rdData);
	if(ret != 0)
	{
		UART_printf("Reading Hours value register failed\n\r");
		return -1;
	}
	else
	{
		gtimeval.hour = HOUR_MASK_VALUE & rdData;
		if ((gtimeval.timeMode = (rdData & TIME_MODE_12_HOUR)))
		{
			if (rdData & MERIDIEM_MASK)
				gtimeval.meridiemMode = 1;
			else
				gtimeval.meridiemMode = 0;
		}
	}

	return 0;
}

/**
 *  \brief		This function writes week, date, month and year values
 *				on the specified registers of RTC.
 *
 *	\param		handle			[IN]	I2C Handler
 *         		slaveAddress	[IN]	Slave Address value.
 *
 *  \return		int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcSetDate(I2C_Handle handle, uint8_t slaveAddress)
{
	int8_t ret;
			
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 WEEK_REG, gdateval.day);
	if(ret != 0)
	{
		UART_printf("Writing Week value register failed\n\r");
		return -1;
	}
	
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 DATE_REG, gdateval.date);
	if(ret != 0)
	{
		UART_printf("Writing Date value register failed\n\r");
		return -1;
	}
	
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 MONTH_REG, gdateval.month);
	if(ret != 0)
	{
		UART_printf("Writing Month value register failed\n\r");
		return -1;
	}
	
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 YEAR_REG, gdateval.year);
	if(ret != 0)
	{
		UART_printf("Writing Year value register failed\n\r");
		return -1;
	}

	return 0;
}
 
/**
 *  \brief    	This function writes second, minute and hour values 
 *				on the specified registers of RTC.
 *
 *	\param    	handle			[IN]	I2C Handler
 *            	slaveAddress	[IN]	Slave Address
 *										value.
 *
 *  \return   	int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_rtcSetTime(I2C_Handle handle, uint8_t slaveAddress)
{
	int8_t ret;
	
	/*Enabling oscillator */
	gtimeval.seconds |= 0x80;
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 SEC_REG, gtimeval.seconds);
	if(ret != 0)
	{
		UART_printf("writing on Seconds value register failed\n\r");
		return -1;
	}
	
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 MIN_REG, gtimeval.minutes);
	if(ret != 0)
	{
		UART_printf("writing on Minutes value register failed\n\r");
		return -1;
	}
								  
	ret = BoardDiag_rtcWriteRegister(handle, slaveAddress,
									 HOUR_REG, gtimeval.hour);
	if(ret != 0)
	{
		UART_printf("writing on Hours value register failed\n\r");
		return -1;
	}

	return 0;
}
 
 /**
 *  \brief    	This function runs the RTC test by reading and
 *            	writing on the RTC registers and displaying on the 
 *				serial console.
 *
 *  \return   	int8_t
 *              	0 - in case of success
 *                 -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_RtcTest(void)
{
    int8_t ret = 0;
    uint16_t index;
    uint8_t rtcSlaveAddr = BOARD_I2C_EXT_RTC_ADDR;
#if !defined(DIAG_COMPLIANCE_TEST)
	uint16_t count = 5;
	uint8_t input = 'y';
#endif
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;

    for (index = 0; I2C_config[index].fxnTablePtr != NULL; index++)
    {
        ((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(BOARD_I2C_EXT_RTC_INSTANCE, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        return -1;
    }
	
	UART_printf("\nSetting Time... \n");
	ret = BoardDiag_rtcSetTime(handle, rtcSlaveAddr);
	if (ret == -1)
	{
		UART_printf("RTC test failed...\n");
		return -1;
	}
	
	UART_printf("\nSetting Date... \n");
	ret = BoardDiag_rtcSetDate(handle, rtcSlaveAddr);
	if (ret == -1)
	{
		UART_printf("RTC test failed...\n");
		return -1;
	}
	
	UART_printf("\nReading Time... \n");
	ret = BoardDiag_rtcGetTime(handle, rtcSlaveAddr);
	if (ret == -1)
	{
		UART_printf("RTC test failed...\n");
		return -1;
	}
	
	UART_printf("\nReading Date... \n");
	ret = BoardDiag_rtcGetDate(handle, rtcSlaveAddr);
	if (ret == -1)
	{
		UART_printf("RTC test failed...\n");
		return -1;
	}

	BoardDiag_rtcDisplayTimeDate();
#if !defined(DIAG_COMPLIANCE_TEST)
	while(count > 0)
	{
	    BOARD_delay(5000000); /* waiting for 5 sec */
		ret = BoardDiag_rtcGetTime(handle, rtcSlaveAddr);
		if (ret == -1)
		{
			UART_printf("RTC test failed...\n");
			return -1;
		}
		
		ret = BoardDiag_rtcGetDate(handle, rtcSlaveAddr);
		if (ret == -1)
		{
			UART_printf("RTC test failed...\n");
			return -1;
		}
		BoardDiag_rtcDisplayTimeDate();
		count--;
		
	}

	UART_printf("\nIf the time and date increment, press 'y' to indicate pass");
	UART_printf(" or any other character to indicate failure\n");
#ifndef DIAG_STRESS_TEST
	UART_scanFmt("%c", &input);
#endif
	I2C_close(handle);

	if ( (input == 'y') || (input == 'Y') )
	{
		ret = 0;
	}
	else
	{
		ret = -1;
	}
#else
    UART_printf("\nRTC test passed...");
#endif
    return ret;
}

int8_t BoardDiag_extRtcFunctionalTest(void)
{
    int8_t ret = 0;

    UART_printf("\nRunning RTC Test...\n");

    ret = BoardDiag_run_RtcTest();

    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the RTC test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_extRtcStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("Running RTC Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        /*Setting to initial values*/
        gtimeval.seconds = 0x53;
        gtimeval.minutes = 0x59;
        gtimeval.hour = 0x71;
        gtimeval.timeMode =    0;
        gtimeval.meridiemMode = 0;

        gdateval.day = 1;
        gdateval.date = 0x31;
        gdateval.month = 0x12;
        gdateval.year = 0x18;

        ret = BoardDiag_extRtcFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\nIteration : %d RTC Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\nRTC Test Failed at iteration - %d\n",iteration);
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

    UART_printf("RTC Stress Test Status\n");
    UART_printf("===================================\n");
    UART_printf("Number of Times Executed - %d\n", (iteration - 1));
    UART_printf("Pass Count - %d\n", passCount);
    UART_printf("Fail Count - %d\n", failCount);

    if((iteration != 0) && (failCount == 0))
    {
        UART_printf("Overall Status - PASS\n" );
    }
    else
    {
        UART_printf("Overall Status - FAIL\n" );
        ret = -1;
    }

    return ret;
}
#endif

/**
 *  \brief   RTC test main function
 *
 *  \return  int - RTC test status.
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
    UART_printf  ("*                 RTC Test                  *\n");
    UART_printf  ("*********************************************\n");

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

#if defined(SOC_J721E) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
	enableI2C(CSL_I2C0_CFG_BASE);
#endif

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_extRtcStressTest();
#else
    ret = BoardDiag_extRtcFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nRTC Test Passed\n");
    }
    else
    {
        UART_printf("\nRTC Test Failed\n");
    }

    return(ret);

}
