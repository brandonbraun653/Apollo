/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   diag_common_cfg.h
 *
 *  \brief  Common protoypes and data structures used by diagnostic tests.
 *
 */
#include <stdbool.h>
#include <stdlib.h>
#include <ti/drv/uart/soc/UART_soc.h>
#include <ti/board/src/j721e_evm/include/board_utils.h>

#include "board.h"
#include "board_cfg.h"

#define DIAG_STRESS_TEST_ITERATIONS			(100)

/* Macros used by test pattern generate function */ 
#define BOARD_DIAG_TEST_PATTERN_FF     (0xFF)
#define BOARD_DIAG_TEST_PATTERN_AA     (0xAA)
#define BOARD_DIAG_TEST_PATTERN_55     (0x55)
#define BOARD_DIAG_TEST_PATTERN_NULL   (0)
#define BOARD_DIAG_TEST_PATTERN_RANDOM (1)
#define BOARD_DIAG_TEST_PATTERN_INC    (2)
#define BOARD_DIAG_TEST_PATTERN_AA_55  (3)

extern UART_HwAttrs uartInitCfg[];

Board_STATUS DIAG_init(void);
bool BoardDiag_memCompare(uint8_t *buf1, uint8_t *buf2, uint32_t length,  
                          uint32_t *failIndex);
void BoardDiag_genPattern(uint8_t *buf, uint32_t length, uint8_t flag);
int8_t BoardDiag_getUserInput(uint8_t instance);
void enableMAINI2C(uint8_t instance, uint32_t baseAddr);
void enableI2C(uint32_t baseAddr);
void BoardDiag_timerIntrDisable(void);
