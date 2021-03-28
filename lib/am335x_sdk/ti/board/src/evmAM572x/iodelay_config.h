/**
 *  \file   sbl_idkAM572x.h
 *
 *  \brief  This file contains build macros for different modes of operations.
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

#ifndef IODELAY_CONFIG_H_
#define IODELAY_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "boardPadDelay.h"

/**
 * \brief   This function implements IODelay Recalibration and configures the
 *          pinmux to all the control core pad configuration registers.
 *
 **/
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#ifndef __cplusplus
#pragma CODE_SECTION (BoardCtrlPadIoDelayConfig, "BOARD_IO_DELAY_CODE");
#endif
void BoardCtrlPadIoDelayConfig(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize);
#else
void BoardCtrlPadIoDelayConfig(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

#ifdef __cplusplus
}
#endif
#endif /* IODELAY_CONFIG_H_ */
