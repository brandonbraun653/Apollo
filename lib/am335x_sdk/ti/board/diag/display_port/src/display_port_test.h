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
 * \file   display_port_test.h
 *
 * \brief  This is the header file for display_port diagnostic test.
 *
 */

#ifndef _DISPLAY_PORT_TEST_H_
#define _DISPLAY_PORT_TEST_H_

#include <ti/csl/cslr.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/soc/cslr_soc_ctrl_mmr.h>
#include <ti/csl/csl_dss.h>

#include "board.h"
#include "board_cfg.h"
#include "board_internal.h"

#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/pm/pmlib.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/dss/dss.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_DIAG_DP_VP_ID                      (CSL_DSS_VP_ID_1)
#define BOARD_DIAG_DP_OVERLAY_ID                 (CSL_DSS_OVERLAY_ID_1)
#define BOARD_DIAG_DP_DCTRL_VID_NODE_ID          (DSS_DCTRL_NODE_VID1)
#define BOARD_DIAG_DP_DCTRL_OVERLAY_NODE_ID      (DSS_DCTRL_NODE_OVERLAY1)
#define BOARD_DIAG_DP_DCTRL_VP_NODE_ID           (DSS_DCTRL_NODE_VP1)
#define BOARD_DIAG_DP_DCTRL_OUT_NODE_ID          (DSS_DCTRL_NODE_EDP_DPI0)

#define BOARD_DIAG_DP_DISPLAY_CLOCK              (148500000ULL)

#define ADDITIONAL_CLK_STATE_FLAG                (0U)
/**
 * \brief  DisplayPort object structure to display color bar
 */
typedef struct
{
    Fvid2_Handle dctrlHandle;
    /**< DCTRL handle */
    Dss_InitParams initParams;
    /**< DSS Initialization Parameters */
    Dss_DctrlPathInfo dctrlPathInfo;
    /**< DSS Path Information */
    Dss_DctrlVpParams vpParams;
    /**< VP Params */
    Dss_DctrlOverlayParams overlayParams;
    /**< Overlay Params */
    Dss_DctrlAdvVpParams advVpParams;
    /**< Advance VP Params */
} BoardDiag_DpDisplayObj;

/**
 * \brief   This function executes DisplayPort diagnostic test
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
int8_t BoardDiag_DpRunTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DISPLAY_PORT_TEST_H_ */
