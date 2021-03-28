/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include "soc.h"

#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include<ti/csl/soc/am572x/src/cslr_soc_eve_baseaddress.h>

uint8_t uart_inst = BOARD_UART_INSTANCE;
uint32_t uart_baseAddr = CSL_EVE_UART3_REGS;

/**
 * @brief	This function initializes settings based on soc.
 *
 * \param   cfg		[IN]	Board initializing value
 *
 * @return	int8_t
 *      0 	- Init completed successfully
 *     -1 	- Error occurred
 *
 */
int8_t UFP_socInit(Board_initCfg *cfg)
{
    Board_initCfg boardCfg;

    if (cfg == NULL)
    {
        boardCfg = BOARD_INIT_PLL |
                    BOARD_INIT_MODULE_CLOCK |
                    BOARD_INIT_PINMUX_CONFIG;
    }
    else
    {
        boardCfg = *cfg;
    }
    
    /* Board Library Init. */
    if (Board_init(boardCfg))
    {
        return -1;
    }
    return 0;
}
