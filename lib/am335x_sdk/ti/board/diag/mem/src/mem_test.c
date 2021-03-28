/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
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
 
/**
 *  \file   mem_test.c
 *
 *  \brief  DDR diagnostic test main file
 *
 *  This file implements the DDR memory test function to verify the DDR
 *  memory access by writing a test pattern to all the locations and reading
 *  the same for verification.
 *
 */

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "board.h"
#include "board_cfg.h"
#if (defined(SOC_AM65XX) || defined(SOC_J721E))
#include "diag_common_cfg.h"
#endif

#define BIT_COUNT		(32)
#define ONE			    (0x00000001)
#define MSG_FREQ        (0xFFFFFFc)

#if !defined(SOC_AM65XX) && !defined(SOC_J721E)
#define BOARD_DDR_START_ADDR (BOARD_DDR3_START_ADDR)
#define BOARD_DDR_END_ADDR   (BOARD_DDR3_END_ADDR)
#define BOARD_DDR_SIZE       (BOARD_DDR3_SIZE)
#endif

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__)
#define BOARD_DDR_EXT_MEM_START_ADDR                            (0x900000000U)
#define BOARD_DDR_EXT_MEM_END_ADDR                              (0x9ffffffffU)

#define BIT_COUNT_EXT_MEM		(64)

#define BOARD_DIAG_MEM_LWORD_SPLIT(lw) ((lw >> 32) & 0xFFFFFFFF), (lw & 0xFFFFFFFF)

#endif

char rdBuf = 'y';

#ifdef DIAG_STRESS_TEST

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__)
/**
 * \brief  walking1s test function
 *
 * This function verifies the DDR memory interface lines by performing
 * the walking 1's test.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
int32_t board_walking1s_test (uint64_t start_address,
                              uint64_t end_address)
{
	uint64_t shift;
	uint64_t index;
	uint64_t value;
	uint64_t one =1;

    UART_printf("\nRunning Walking 1s Test. Enter 'b' to Break the Test...\n");

	for (index = start_address; (index >= start_address) &&
         (index < end_address); index += 8)
	{
		for (shift = 0; shift < BIT_COUNT_EXT_MEM; shift++)
		{
			value = *(volatile uint64_t *) index = (one << shift);
			if(value != *(volatile uint64_t *) index)
			{
				UART_printf("DDR Walking 1's Test Failed at Location 0x%x08x\n",
                             BOARD_DIAG_MEM_LWORD_SPLIT(index));
				return (-1);
			}
		}

        if (!(index & MSG_FREQ))
		{
            UART_printf("\tWrite up to 0x%x%08x done\n",
                        BOARD_DIAG_MEM_LWORD_SPLIT(index));
		}

		/* Check if there is a input from console to break the test */
		rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
		if((rdBuf == 'b') || (rdBuf == 'B'))
		{
			UART_printf("Received Test Termination... Exiting the Test\n");
			UART_printf("walking 1s test verified up to 0x%x08%x\n\n",
                        BOARD_DIAG_MEM_LWORD_SPLIT(index));
			break;
		}
	}

	return (0);
}

/**
 * \brief  walking0s test function
 *
 * This function verifies the DDR memory interface lines by performing
 * the walking 0's test.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
int32_t board_walking0s_test (uint64_t start_address,
                              uint64_t end_address)
{
	uint64_t shift;
	uint64_t index;
	uint64_t value;
	uint64_t one =1;

    UART_printf("\nRunning Walking 0s Test. Enter 'b' to Break the Test...\n");

	for (index = start_address; (index >= start_address) &&
         (index < end_address); index += 8)
	{
		for (shift = 0; shift < BIT_COUNT_EXT_MEM; shift++)
		{
			value = *(volatile uint64_t *) index = ~(one << shift);
			if( value != *(volatile uint64_t *)index)
			{
				UART_printf("DDR Walking 0's Test Failed at Location 0x%x08%x\n",
                            BOARD_DIAG_MEM_LWORD_SPLIT(index));
				return (-1);
			}
		}

		if (!(index & MSG_FREQ))
		{
            UART_printf("\tWrite up to 0x%x08%x done\n", BOARD_DIAG_MEM_LWORD_SPLIT(index));
		}

		/* Check if there is a input from console to break the test */
		rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
		if((rdBuf == 'b') || (rdBuf == 'B'))
		{
			UART_printf("Received Test Termination... Exiting the Test\n");
			UART_printf("walking 0s test verified up to 0x%x08%x\n\n",
                        BOARD_DIAG_MEM_LWORD_SPLIT(index));
			break;
		}
	}

	return (0);
}

#else
/**
 * \brief  walking1s test function
 *
 * This function verifies the DDR memory interface lines by performing
 * the walking 1's test.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
int32_t board_walking1s_test (uint32_t start_address, uint32_t end_address)
{
	uint32_t shift;
	uint32_t index;
	volatile uint32_t value;

    UART_printf("\nRunning Walking 1s Test. Enter 'b' to Break the Test...\n");

	for (index = start_address; (index >= start_address) &&
         (index < end_address); index += 4)
	{
		for (shift = 0; shift < BIT_COUNT; shift++)
		{
			value = *(volatile uint32_t *) index = (ONE << shift);
			if(value != *(volatile uint32_t *) index)
			{
				UART_printf("DDR Walking 1's Test Failed at \
                                        Location 0x%X\n", index);
				return (-1);
			}
		}
        if (!(index & MSG_FREQ))
            UART_printf("\t walking1s test verified up to 0x%08x \
                                                        done\n", index);

        /* Check if there is a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            UART_printf("walking 1s test verified up to 0x%08x\n\n", index);
            break;
        }
	}

	return (0);
}

/**
 * \brief  walking0s test function
 *
 * This function verifies the DDR memory interface lines by performing
 * the walking 0's test.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
int32_t board_walking0s_test (uint32_t start_address,
                              uint32_t end_address)
{
	uint32_t shift;
	uint32_t index;
	volatile uint32_t value;

    UART_printf("\nRunning Walking 0s Test. Enter 'b' to Break the Test...\n");

	for (index = start_address; (index >= start_address) &&
         (index < end_address); index += 4)
	{
		for (shift = 0; shift < BIT_COUNT; shift++)
		{
            value = *(volatile uint32_t *) index = ~(ONE << shift);
			if( value != *(volatile uint32_t *)index)
			{
				UART_printf("DDR Walking 0's Test Failed at Location \
                                                            0x%X\n", index);
				return (-1);
			}
		}
        if (!(index & MSG_FREQ))
            UART_printf("\t walking0s test verified up to 0x%08x \
                                                            done\n", index);

        /* Check if there is a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            UART_printf("walking 0s test verified up to 0x%08x\n\n", index);
            break;
        }
	}

	return (0);
}
#endif  /* #if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__) */
#endif  /* #ifdef DIAG_STRESS_TEST */

#if defined(DIAG_COMPLIANCE_TEST)
/**
 * \brief  walking0s test function
 *
 * This function verifies the DDR memory  access by writing a address
 * and its compliment to all the locations and reading the same for
 * verification.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
static inline int32_t board_memory_test (uint32_t start_address,
                                                uint32_t end_address)
{
	uint32_t index, value;
    uint32_t pattern = 0xAAAAAAAA;
    uint32_t inc = 2;
    int32_t ret = 0;

	UART_printf("Address Bus Test Started\n");
	UART_printf("Writing to test area...\n");
	/* Write a pattern */
	for (index = start_address; (index >= start_address) &&
                        (index < end_address) && (inc < 32);
						index = start_address | (1 << inc++)) {

        UART_printf("\tWriting Memory 0x%08x\n", index);
		*(volatile uint32_t *) index = (uint32_t)pattern;
        pattern = ~pattern;
	}

	UART_printf("Write finished!\n");
	UART_printf("Checking values...\n");
    inc = 2;
    pattern = 0xAAAAAAAA;
	/* Read and check the pattern */
	for (index = start_address; (index >= start_address) &&
                        (index < end_address) && (inc < 32);
						index = start_address | (1 << inc++)) {

        UART_printf("\tReading Memory 0x%08x\n", index);
		value = *(uint32_t *) index;

		if (value  != pattern) {
			UART_printf("board_memory_test: Failed at address index = 0x%x \
                                              Expected value = 0x%x Read value = 0x%x\n",
                                index, index, value);
			ret = -1;
		}
        pattern = ~pattern;
	}

	return ret;
}
#else

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__)
/**
 * \brief  Memory test for extended access beyond 2GB
 *
 * This function verifies the DDR memory  access by writing a data
 * and its compliment to all the locations and reading the same for
 * verification.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
static inline int32_t board_memory_test (uint64_t start_address, uint64_t end_address)
{
    uint64_t index;
    uint64_t value = 0;
    uint64_t lsb = 0;
    uint64_t msb = 4;

    UART_printf("First test started\n");
    UART_printf("Writing to test area...\n");

    /* Write a pattern */
    for (index = start_address; (index >= start_address) && (index < end_address); index += 8)
    {
        value = ((msb << 32) | lsb);

        *(uint64_t *)index = value;

        if (!(index & (uint32_t)MSG_FREQ))
        {
            UART_printf("\tWrite up to 0x%x%08x done\n", BOARD_DIAG_MEM_LWORD_SPLIT(index));
        }

        msb += 8;
        lsb += 8;
    }

    UART_printf("Write finished!\n");
    UART_printf("Checking values...\n");

    /* Read and check the pattern */
    msb     = 4;
    lsb     = 0;
    for (index = start_address;  (index >= start_address) && (index < end_address); index += 8)
    {
        value = *(uint64_t *)index;

        if((value != ((msb << 32) | lsb)))
        {
            UART_printf("board_memory_test: Failed at address index = 0x%x%08x value = 0x%x%08x\n",
                        BOARD_DIAG_MEM_LWORD_SPLIT(index),
                        BOARD_DIAG_MEM_LWORD_SPLIT(value));
            return (-1);
        }

        if (!(index & MSG_FREQ))
        {
            UART_printf("\tRead up to 0x%x%08x done\n", BOARD_DIAG_MEM_LWORD_SPLIT(index));
        }

        msb += 8;
        lsb += 8;
    }

    UART_printf("\nSecond test started\n");
    UART_printf("Writing complementary values to test area...\n");
    msb     = 4;
    lsb     = 0;
    /* Write a pattern for complementary values */
    for (index = start_address; (index >= start_address) && (index < end_address); index += 8)
    {
        value = ((msb << 32) | lsb);

        *(uint64_t *)index = ~value;

        if (!(index & MSG_FREQ))
        {
            UART_printf("\tWrite up to 0x%x%08x done\n", BOARD_DIAG_MEM_LWORD_SPLIT(index));
        }

        msb += 8;
        lsb += 8;
    }

    UART_printf("Write finished!\n");
    UART_printf("Checking values...\n");
    /* Read and check the pattern */
    msb     = 4;
    lsb     = 0;
    for (index = start_address;  (index >= start_address) && (index < end_address); index += 8)
    {
        value = *(uint64_t *)index;

        if((~value != ((msb << 32) | lsb)))
        {
            UART_printf("board_memory_test: Failed at address index = 0x%x%08x value = 0x%x%08x\n",
                        BOARD_DIAG_MEM_LWORD_SPLIT(index),
                        BOARD_DIAG_MEM_LWORD_SPLIT(value));
            return (-1);
        }

        if (!(index & MSG_FREQ))
        {
            UART_printf("\tRead up to 0x%x%08x done\n", BOARD_DIAG_MEM_LWORD_SPLIT(index));
        }

        msb += 8;
        lsb += 8;
    }

    return 0;
}
#else
/**
 * \brief  walking0s test function
 *
 * This function verifies the DDR memory  access by writing a address
 * and its compliment to all the locations and reading the same for
 * verification.
 *
 * \param   start_address  [IN]   Starting address of the DDR memory
 * \param   end_address    [IN]   Ending address of the DDR memory
 *
 * \return  int32_t
 *              0  - In case of success
 *             -1  - In case of failure
 *
 */
static inline int32_t board_memory_test (uint32_t start_address,
                                                uint32_t end_address)
{
	uint32_t index, value;

	UART_printf("First test started\n");
	UART_printf("Writing to test area...\n");
	/* Write a pattern */
	for (index = start_address; (index >= start_address) &&
                        (index < end_address); index += 4) {
        HW_WR_REG32(index, (uint32_t)index);
		if (!(index & MSG_FREQ))
            UART_printf("\tWrite up to 0x%08x done\n", index);
	}

	UART_printf("Write finished!\n");
	UART_printf("Checking values...\n");

	/* Read and check the pattern */
	for (index = start_address;  (index >= start_address) &&
                            (index < end_address); index += 4) {

        value = HW_RD_REG32(index);

		if (value  != index) {
			UART_printf("board_memory_test: Failed at address index = 0x%x \
                                            value = 0x%x *(index) = 0x%x\n",
                                index, value, HW_RD_REG32(index));
			return (-1);
		}
		if (!(index & MSG_FREQ))
            UART_printf("\tRead up to 0x%08x okay\n", index);
	}

	UART_printf("Second test started\n");
	UART_printf("Writing complementary values to test area...\n");
	/* Write a pattern for complementary values */
	for (index = start_address; (index >= start_address) &&
                        (index < end_address); index += 4) {
        HW_WR_REG32(index, (uint32_t)~index);
		if (!(index & MSG_FREQ))
            UART_printf("\tWrite up to 0x%08x done\n", index);
	}

	UART_printf("Write finished!\n");
	UART_printf("Checking values...\n");
	/* Read and check the pattern */
	for (index = start_address;  (index >= start_address) &&
                        (index < end_address); index += 4) {

		value = HW_RD_REG32(index);

		if (value  != ~index) {
			UART_printf("board_memory_test: Failed at address index = 0x%x \
                            value = 0x%x *(index) = 0x%x\n", \
                            index, value, HW_RD_REG32(index));
			return (-1);
		}
		if (!(index & MSG_FREQ))
            UART_printf("\tRead up to 0x%08x okay\n", index);
	}

	return 0;
}
#endif  /* #if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__) */
#endif

int32_t board_external_memory_test(void)
{

    int32_t status;
    int ret;

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__) && !defined(DIAG_COMPLIANCE_TEST)
    /* Printf complication due to UART_printf not supporting 64-bit */
    UART_printf("board_external_memory_test: Start address (0x%x%08x), \
           end address (0x%x%08x)\n",
           BOARD_DIAG_MEM_LWORD_SPLIT(BOARD_DDR_EXT_MEM_START_ADDR),
           BOARD_DIAG_MEM_LWORD_SPLIT(BOARD_DDR_EXT_MEM_END_ADDR));
	status = board_memory_test(BOARD_DDR_EXT_MEM_START_ADDR, BOARD_DDR_EXT_MEM_END_ADDR);
#else
	UART_printf("board_external_memory_test: Start address (0x%08x), \
           end address (0x%08x)\n",BOARD_DDR_START_ADDR, BOARD_DDR_END_ADDR);
	status = board_memory_test(BOARD_DDR_START_ADDR, BOARD_DDR_END_ADDR);
#endif
	if (status < 0)
	{
		UART_printf("Board memory test failed!\n");
		ret = -1;
	}
	else
	{
		UART_printf("Board memory test passed!\n");
		ret = 0;
	}

#ifdef DIAG_STRESS_TEST
#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__) && !defined(DIAG_COMPLIANCE_TEST)
    status = board_walking1s_test(BOARD_DDR_EXT_MEM_START_ADDR, BOARD_DDR_EXT_MEM_END_ADDR);
#else
    status = board_walking1s_test(BOARD_DDR_START_ADDR,BOARD_DDR_END_ADDR);
#endif
	if (status < 0)
	{
		UART_printf("walking1s test failed!\n");
		ret = -1;
	}
	else
	{
		UART_printf("walking1s test passed!\n");
		ret = 0;
	}

    if((rdBuf == 'b') || (rdBuf == 'B'))
    {
        /* Walking 1s test is terminated before completion.
           No need to run walking 0s. Return from here */
        UART_printf("\nSkipping walking0s test!!\n\n");
        return ret;
    }

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(__aarch64__) && !defined(DIAG_COMPLIANCE_TEST)
    status = board_walking0s_test(BOARD_DDR_EXT_MEM_START_ADDR, BOARD_DDR_EXT_MEM_END_ADDR);
#else
    status = board_walking0s_test(BOARD_DDR_START_ADDR,BOARD_DDR_END_ADDR);
#endif
	if (status < 0)
	{
		UART_printf("walking0s test failed!\n");
		ret = -1;
	}
	else
	{
		UART_printf("walking0s test passed!\n");
		ret = 0;
	}
#endif

    return ret;
}

int mem_test()
{
	int32_t status;
	int ret;

#ifdef DIAG_STRESS_TEST
	UART_printf("\n****************************************************\n");
	UART_printf  ("*            DDR Memory Stress Test                *\n");
	UART_printf  ("****************************************************\n");
#else
	UART_printf("\n*********************************************\n");
	UART_printf  ("*              DDR Memory Test              *\n");
	UART_printf  ("*********************************************\n");
#endif

	UART_printf("\nTesting writing and reading memory\n");
	status = board_external_memory_test();
	if (status < 0)
	{
		UART_printf("Memory test failed!\n");
		ret = -1;
	}
	else
	{
		UART_printf("Memory test passed!\n");
		ret = 0;
	}
	return ret;
}

/*
 *  ======== main ========
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    Board_initCfg boardCfg;
    
#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif  /*  #ifdef PDK_RAW_BOOT */
    Board_init(boardCfg);
    
    return mem_test();
}
#endif
