/* ========================================================================== */
/**
 *  @file   board_internal.h
 *
 *  @brief  Private definitions for the Board Library.
 *
 *  ============================================================================
 */
/* --COPYRIGHT--,BSD
 * Copyright (c) 2011-2017, Texas Instruments Incorporated
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
 * --/COPYRIGHT--*/

#ifndef BOARD_INTERNAL_H_
#define BOARD_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/board/board.h>

/* PLL multipliers and dividers for confuring ICSS clock */
#define BOARD_DISP_DPLL_DEFAULT_MULT          (2)
#define BOARD_DISP_DPLL_DEFAULT_DIV           (0)
#define BOARD_DISP_DPLL_DEFAULT_POST_DIVM2    (1)

#define BOARD_ICSS_CLK_225MHZ_DISP_DPLL_MULT        (900)
#define BOARD_ICSS_CLK_225MHZ_DISP_DPLL_DIV         (23)
#define BOARD_ICSS_CLK_225MHZ_DISP_DPLL_POST_DIVM2  (4)

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
extern I2C_config_list I2C_config;

typedef struct
{
    I2C_Handle i2cHandle;
} Board_gblObj;
extern Board_gblObj Board_obj;

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/

Board_STATUS Board_PLLInit();
Board_STATUS Board_moduleClockInit();
Board_STATUS Board_DDR3Init();
Board_STATUS Board_pinmuxConfig();
Board_STATUS Board_uartStdioInit();
Board_STATUS Board_internalInitI2C();
Board_STATUS Board_icssEthConfig(void);

#ifdef __cplusplus
}
#endif

#endif
