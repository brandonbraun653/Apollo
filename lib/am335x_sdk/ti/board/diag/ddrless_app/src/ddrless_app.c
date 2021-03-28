/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tistdtypes.h>
#include "soc_am335x.h"
#include "board.h"
#include "board_cfg.h"
#include "app_data.h"

/* Board init function */
extern void Board_initSPI(void);

void AppDelay(uint32_t delayVal);

/* Function to control load signal to the industrial input module */
void LoadData(void);

/* Function to verify data */
Bool VerifyData(uint8_t *expData, uint8_t *rxData, uint32_t length);

#define PDK_RAW_BOOT

int ddrless_app_test()
{
    char p = 'r';
	unsigned int i,clk_val, reset_val;
	uint8_t * expectedData;
	uint8_t * actualData;
				
	UART_printf("\n*********************************************\n"); 
	UART_printf  ("*                 DDRless App               *\n");
	UART_printf  ("*********************************************\n");

	UART_printf("\nRunning application from OCMC Memory\n");
	
	UART_printf("\nChecking PRU State\n");
	
	/* Verify PRU clock and reset states */
	clk_val = *((unsigned int*) (SOC_CM_PER_REGS+0xE8));
	reset_val = *((unsigned int*) SOC_PRM_PER_REGS); 
	if ( ((clk_val & 0x2) == 0x2) && ((reset_val & 0x2) != 0x2))
		UART_printf("PRU is Enabled\n\n");
	else 
		UART_printf("PRU is Disabled\n");
	
	/* Verify the loading of the binaries in device memory */
	UART_printf("Validating binary load using default binary vectors\n", p);

	for (i = 0; i < NUM_BIN_IMAGES; i++)
	{
		actualData = (uint8_t *) bin_loc[i];
		expectedData = (uint8_t *)bin_data[i];
		if(VerifyData(&expectedData[0],&actualData[0],bin_size[i]) == TRUE)
		{
			UART_printf("Binary Data #%x loaded matches with expected binary data\n",i);
			p = 'y'; 
		}
		else
		{
			UART_printf("Binary data load Failed!\n");
			p = 'n'; 
			break;
		}
	}
	
	if ( (p == 'y') || (p == 'Y') ) {
		UART_printf("\nDDRless application boot test Passed!\n");
		UART_printf("\nTest PASSED!\n\n");
		return 0;
	}
	else {
		UART_printf("\nTest FAILED!\n\n");
		return -1;
	}

}

int main(void)
{
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
	boardCfg = BOARD_INIT_PLL |
               BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    return ddrless_app_test();
}


/*
 *  ======== CompareData ========
 */
Bool VerifyData(uint8_t *expData, uint8_t *rxData, uint32_t length)
{
    uint32_t idx = 0;
    uint32_t match = 1;
    Bool retVal = FALSE;
    for(idx = 0; ((idx < length) && (match != 0)); idx++)
    {
        if(*expData != *rxData) match = 0; 
        expData++;
        rxData++;
    }
    if(match == 1) retVal = TRUE;

    return retVal;
}