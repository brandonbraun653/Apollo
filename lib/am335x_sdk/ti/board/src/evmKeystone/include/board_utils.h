/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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

#ifndef BOARD_UTILS_H
#define BOARD_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_pllc.h>

/* external clock frequency definitions */
#define EXT_CLK_19M2    19200000
#define EXT_CLK_24M     24000000
#define EXT_CLK_25M     25000000
#define EXT_CLK_26M     26000000
#define EXT_CLK_48M     48000000
#define EXT_CLK_50M     50000000
#define EXT_CLK_66M67   66670000
#define EXT_CLK_80M     80000000
#define EXT_CLK_100M    100000000
#define EXT_CLK_125M    125000000
#define EXT_CLK_122M88  122880000
#define EXT_CLK_156M25  156250000
#define EXT_CLK_250M    250000000
#define EXT_CLK_312M5   312500000

extern const uint32_t Board_ext_clk[];

uint32_t BOARD_getExternalClk(CSL_PllcType pll);
void BOARD_delay(uint32_t usecs);
void BOARD_initPerfCounters();

#ifdef __cplusplus
}
#endif

#endif
