/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   hdmi_test_v2.h
 *
 * \brief  This is the header file for hdmi diagnostic test.
 *
 */

#ifndef _HDMI_TEST_V2_H_
#define _HDMI_TEST_V2_H_

#include <ti/csl/cslr.h>
#include <ti/csl/csl_dss.h>

#include "board.h"
#include "board_cfg.h"
#include "board_i2c_io_exp.h"
#include "board_control.h"

#include <ti/drv/uart/UART.h>

#include <ti/drv/dss/dss.h>

#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/pm/pmlib.h>

#include "diag_common_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_DIAG_HDMI_HPD_EXP_INSTANCE       (1U)
#define BOARD_DIAG_HDMI_HPD_SLAVE_ADDR         (0x21U)

#define BOARD_DIAG_HDMI_HPD_DETECT_TIMEOUT     (20U)

#define BOARD_DIAG_DSS0_DPI_CLK_FREQ           (148500000U)

/**
 * \brief  HDMI object structure to display color bar
 */
typedef struct
{
    Fvid2_Handle dctrlHandle;
    /**< DCTRL handle */
    Dss_InitParams initParams;
    /**< DSS Initialization Parameters */
    Dss_DctrlVpParams vpParams;
    /**< VP Params */
    Dss_DctrlOverlayParams overlayParams;
    /**< Overlay Params */
} BoardDiag_HdmiDisplayObj;

/**
 * \brief   This function executes HDMI diagnostic test
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
int8_t BoardDiag_HdmiRunTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _HDMI_TEST_V2_H_ */
