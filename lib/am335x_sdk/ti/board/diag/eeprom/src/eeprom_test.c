/**
 *  \file   main.c
 *
 *  \brief  Example application main file. This application will toggle the led.
 *          The led toggling will be done inside an callback function, which
 *          will be called by Interrupt Service Routine. Interrupts are
 *          triggered manually and no external source is used to trigger
 *          interrupts.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/drv/uart/UART_stdio.h>

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

#include "board.h"
#include "board_cfg.h"

#define DIAG_BOARD_INFO_HEADER (0xEE3355AA)

int eeprom_test()
{
	int ret = 0;
	int i;
	Board_IDInfo eepromInfo;
	Board_STATUS stat;
	uint32_t *header;

	UART_printf("\n*********************************************\n"); 
	UART_printf  ("*              EEPROM Test                  *\n");
	UART_printf  ("*********************************************\n");

	stat = Board_getIDInfo(&eepromInfo);

	header = (uint32_t *)&eepromInfo.header;
	if(*header != DIAG_BOARD_INFO_HEADER)
	{
		UART_printf("\nInvalid Board ID Info Header!!\n\n");
		ret = -1;
	}

	UART_printf("header: ");
	for (i = 0; i<BOARD_EEPROM_HEADER_LENGTH; i++)
		UART_printf("%x", eepromInfo.header[i]);
	UART_printf("\nboardName: %s\n", eepromInfo.boardName);
	UART_printf("version: %s\n", eepromInfo.version);
	UART_printf("serialNum: %s\n", eepromInfo.serialNum);


#ifdef ICE_K2G
	UART_printf("MACID0: ");
	for (i = 0; i<BOARD_EEPROM_MACID_LENGTH; i++)
	{
		UART_printf("%x", eepromInfo.indEthMacID0[i]);
		if(i < (BOARD_EEPROM_MACID_LENGTH - 1))
			UART_printf("-");
	}

	UART_printf("\nMACID3: ");
	for (i = 0; i<BOARD_EEPROM_MACID_LENGTH; i++)
	{
		UART_printf("%x", eepromInfo.indEthMacID3[i]);
		if(i < (BOARD_EEPROM_MACID_LENGTH - 1))
			UART_printf("-");
	}
#endif

	UART_printf("\n");

	if ((stat != BOARD_SOK) || (ret != 0))
	{
		UART_printf("Test FAILED!\n");
		ret = -1;
	}
	else
	{
		UART_printf("Test PASSED!\n");
	}
	return ret;
}

#ifndef SPI_BOOT_FRAMEWORK
/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | 
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

	return eeprom_test();
}
#endif  /* #ifndef SPI_BOOT_FRAMEWORK */
