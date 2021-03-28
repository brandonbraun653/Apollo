/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/board/board.h>
#include <ti/csl/soc/omapl137/src/cslr_soc_baseaddress.h>

uint32_t uart_baseAddr = CSL_UART_2_REGS; /* 0x01D0D000u */

/**
 * @brief	This function initializes the SOC.
 *
 * @return	int8_t
 *      0 	- Init completed successfully
 *     -1 	- Error occurred
 *
 */
int8_t socInit()
{
    Board_initCfg boardCfg;
	boardCfg = BOARD_INIT_UNLOCK_MMR |
        BOARD_INIT_PLL             |
        BOARD_INIT_MODULE_CLOCK    |
        BOARD_INIT_DDR             |
        BOARD_INIT_PINMUX_CONFIG   |
        BOARD_INIT_EMIF_PINMUX     |
        BOARD_INIT_UART_STDIO;

    /* Board Library Init. */
    if (Board_init(boardCfg))
    {
        return -1;
    }
    return 0;
}
