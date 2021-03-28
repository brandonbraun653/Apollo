/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *
 * \file   fpd_dsi_test.h
 *
 * \brief  This is the header file for verifying the dsi module
 *         connected to fpd.
 *
 */
#ifndef _FPD_DSI_TEST_H_
#define _FPD_DSI_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/src/devices/board_devices.h>

#include <ti/csl/soc.h>
#include <soc.h>

#include "diag_common_cfg.h"
#include "board.h"
#include "board_cfg.h"
#include "board_i2c_io_exp.h"

#define MAX_BRIGHTNESS                       (100U)
#define MIN_BRIGHTNESS                       (0U)

#define BOARD_DIAG_PWM2_REG_ADDR             (0x04U)

/**
 *  \brief    The function performs the fpd dsi access verification test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_fpd_dsi_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _FPD_DSI_TEST_H_ */
