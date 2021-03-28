/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation.
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2009-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
*/

/**
 *  \file   audio_evmInit.c
 *
 *  \brief  This file contains the board specific code for enabling the use of
 *          audio driver.
 *
 *  (C) Copyright 2009, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#define SW_I2C
#ifndef SW_I2C
#include <ti/drv/i2c/I2c.h>
#endif

#include <Audio_evmInit.h>
#include <mcasp_cfg.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_bootcfg.h>
#include <board.h>
#include <ti/csl/cslr_syscfg.h>

#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include "MCASP_log.h"
extern Board_STATUS Board_init(Board_initCfg);

void configureAudio(void)
{
	Board_STATUS stat = BOARD_SOK;
	Board_initCfg arg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;
	stat = Board_init(arg);

    if( BOARD_SOK != stat)
    {
        MCASP_log("Board init failed!!");
        return;
    }

   return;
}

void configMcASP_SocHwInfo(void)
{
    /* Configure the interrupts for the McASP Instance MCASP_NUM */
    Mcasp_HwInfo hwInfo;

    Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);


/* Change anything if needed */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
