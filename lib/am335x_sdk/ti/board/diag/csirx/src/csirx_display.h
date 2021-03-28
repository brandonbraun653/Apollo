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
 *  \file csirx_display.h
 *
 *  \brief CSIRX display API Header file.
 */

#ifndef CSIRX_DISPLAY_H_
#define CSIRX_DISPLAY_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "board.h"
#include "board_cfg.h"
#include "board_i2c_io_exp.h"
#include "board_control.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/dss/dss.h>

#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/pm/pmlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_DIAG_CSIRX_HDMI_HPD_EXP_INSTANCE       (1U)
#define BOARD_DIAG_CSIRX_HDMI_HPD_SLAVE_ADDR         (0x21U)

#define BOARD_DIAG_CSIRX_HDMI_HPD_DETECT_TIMEOUT     (20U)

#define BOARD_DIAG_CSIRX_DSS0_DPI_CLK_FREQ           (148500000U)

#define BOARD_DIAG_CSIRX_HDMI_WIDTH                  (1920U)
#define BOARD_DIAG_CSIRX_HDMI_HEIGHT                 (1080U)

/* Worst case frames per handle */
#define BOARD_DIAG_CSIRX_DISP_MAX_FRAME              (2U)

#define BOARD_DIAG_CSIRX_HDMI_VP_ID                  (CSL_DSS_VP_ID_2)
#define BOARD_DIAG_CSIRX_HDMI_OVERLAY_ID             (CSL_DSS_OVERLAY_ID_2)
#define BOARD_DIAG_CSIRX_HDMI_OVERLAY_NODE_ID        (DSS_DCTRL_NODE_OVERLAY2)
#define TEST_DCTRL_VP_NODE_ID                        (DSS_DCTRL_NODE_VP2)
#define TEST_DCTRL_OUT_NODE_ID                       (DSS_DCTRL_NODE_DPI_DPI0)

/**
 *  \brief Display application test parameters.
 *  
 *   The test case execution happens based on values of this structure.
 */
typedef struct
{
    uint32_t numTestPipes;
    /**< Number of pipes in test params */
    uint32_t bpp;
    /**< Number of bytes per pixel */
    uint32_t instId[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Driver instance id */
    uint32_t pipeId[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Pipe id */
    uint32_t pipeNodeId[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Pipe Node id */
    uint32_t pipeType[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Video pipe type */
    uint32_t inDataFmt[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Data format */
    uint32_t inWidth[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Input buffer resolution width in pixels */
    uint32_t inHeight[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Input buffer resolution height in lines */
    uint32_t pitch[CSL_DSS_VID_PIPE_ID_MAX][FVID2_MAX_PLANES];
    /**< Pitch of input buffer */
    uint32_t inScanFmt[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Scan format */
    uint32_t outWidth[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Output buffer resolution width in pixels */
    uint32_t outHeight[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Output buffer resolution height in lines */
    uint32_t scEnable[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Scaler enable */
    uint32_t globalAlpha[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Global Alpha value */
    uint32_t preMultiplyAlpha[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Pre-multiply Alpha value */
    uint32_t posx[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Input buffer position x. */
    uint32_t posy[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Input buffer position y. */
    uint32_t invalidPipeId[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Pipe id */
} DispApp_TestParams;

/**
 *  \brief Driver instance information.
 */
typedef struct
{
    uint32_t instId;
    /**< Instance ID */
    Dss_DispCreateParams createParams;
    /**< Create time parameters */
    Dss_DispCreateStatus createStatus;
    /**< Create status returned by driver during Fvid2_create() */
    Dss_DispParams dispParams;
    /**< DSS display parameters */
    Dss_DispPipeMflagParams mflagParams;
    /**< DSS mflag parameters */
    Fvid2_Handle drvHandle;
    /**< FVID2 display driver handle */
    Fvid2_CbParams cbParams;
    /**< Callback parameters */
    Fvid2_Frame frames[BOARD_DIAG_CSIRX_DISP_MAX_FRAME];
    /**< FVID2 Frames that will be used for display */
    SemaphoreP_Handle syncSem;
    /**< Semaphore for ISR */
} DispApp_InstObj;

/**
 *  \brief Test application data structure.
 */
typedef struct
{
    DispApp_InstObj instObj[CSL_DSS_VID_PIPE_ID_MAX];
    /**< Display driver instance objects */
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
    Dss_DctrlOverlayLayerParams layerParams;
    /**< Layer Params */
    Dss_DctrlVpErrorStats errorStats;
    /**< Error Stats */
    Dss_DctrlAdvVpParams advVpParams;
    /**< Advance VP Params */
    Dss_DctrlGlobalDssParams globalDssParams;
    /**< Global DSS Params */
} BoardDiag_CsirxDispObj;


// int8_t BaordDiag_csirxDispRunTest(BoardDiag_CsirxDispObj *dispObj);

/* ========================================================================== */
/*                              Global Variables                              */
/* ========================================================================== */

static const DispApp_TestParams gDispAppTestParams=
{
    /* Number of Pipes */
    2U,
    /* bpp */
    4U,
    /* Instance Id */
    {
        DSS_DISP_INST_VID1,
        DSS_DISP_INST_VIDL1
    },
    /* Pipe Id */
    {
        CSL_DSS_VID_PIPE_ID_VID1,
        CSL_DSS_VID_PIPE_ID_VIDL1
    },
    /* Pipe Node Id */
    {
        DSS_DCTRL_NODE_VID1,
        DSS_DCTRL_NODE_VIDL1
    },
    /* Pipe Type */
    {
        CSL_DSS_VID_PIPE_TYPE_VID,
        CSL_DSS_VID_PIPE_TYPE_VIDL
    },
    /* Data format */
    {
        FVID2_DF_BGRX32_8888,
        FVID2_DF_BGRX32_8888
    },
    /* Input buffer width */
    {
        1920U,
        1920U
    },
    /* Input buffer height */
    {
        1080U,
        1080U
    },
    /* Pitch */
    {
        {
            1920U*4U, 0U, 0U, 0U, 0U, 0U
        },
        {
            1920U*4U, 0U, 0U, 0U, 0U, 0U
        }
    },
    /* Scan format */
    {
        FVID2_SF_PROGRESSIVE,
        FVID2_SF_PROGRESSIVE
    },
    /* Output buffer width */
    {
        720U,
        480U
    },
    /* Output buffer height */
    {
        540U,
        360U
    },
    /* Scaler enable */
    {
        TRUE,
        FALSE
    },
    /* Global Alpha */
    {
        0xFFU,
        0xFFU
    },
    /* Pre-multiply alpha */
    {
        FALSE,
        FALSE
    },
    /* X Position */
    {
        0U,
        1440U
    },
    /* Y position */
    {
        0U,
        720U
    },
    /* Invalid Pipe Id */
    {
        CSL_DSS_VID_PIPE_ID_VID2,
        CSL_DSS_VID_PIPE_ID_VIDL2
    }
};

/**
 *  \brief   This function configures HDMI
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_csirxConfigHdmi(void);

/**
 * \brief   This function runs csirx display test.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
int8_t BoardDiag_csirxDispRunTest(BoardDiag_CsirxDispObj *dispObj);

/**
 * \brief   This function de-initialize dss.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
int8_t BoardDiag_csirxDispDeInit(void);

/* None */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CSIRX_DISPLAY_H_ */
