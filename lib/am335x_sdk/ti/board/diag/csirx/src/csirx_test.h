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
 * \file   csirx_test.h
 *
 * \brief  This is the header file for CSI-Rx diagnostic test.
 *
 */

#ifndef _CSIRX_TEST_H_
#define _CSIRX_TEST_H_

#include <stdio.h>
#include <string.h>

#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/csirx/csirx.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/src/devices/common/common.h>
#include <ti/board/board.h>
#include <ti/board/src/devices/board_devices.h>
#include "csirx_display.h"

#ifdef __cplusplus
extern "C" {
#endif

/**< Number of channels */
#define BOARD_DIAG_CSIRX_MAX_CH                           ((uint32_t)1U)
/**< Input Image Data format */
#define BOARD_DIAG_CSIRX_IMAGE_DF                         (FVID2_CSI2_DF_RGB888)
/**< Frame storage format. Only valid for RAW12 DT. */
#define BOARD_DIAG_CSIRX_IMAGE_STORAGE_FORMAT             (FVID2_CCSF_BITS12_UNPACKED16)
/**< Number of frames to capture. Set it to '0' for indefinite capture */
#define BOARD_DIAG_CSIRX_NUM_OF_FRAMES                    ((uint32_t)1U) //change it in dss_display_test.c also
/**< Number of frames per stream */
#define BOARD_DIAG_CSIRX_FRAMES_PER_CH                    ((uint32_t)4U)
/**< Frame Attribute: Width in pixels */
#define BOARD_DIAG_CSIRX_FRAME_WIDTH                      ((uint32_t)1920U)
/**< Frame Attribute: Height in pixels */
#define BOARD_DIAG_CSIRX_FRAME_HEIGHT                     ((uint32_t)1080U)
/**< Frame Attribute: Bytes per pixel */
#define BOARD_DIAG_CSIRX_FRAME_BPP                        ((uint32_t)4U)
/**< Frame Attribute: Pitch in bytes */
#define BOARD_DIAG_CSIRX_FRAME_PITCH                      ((uint32_t)\
                                (BOARD_DIAG_CSIRX_FRAME_WIDTH * BOARD_DIAG_CSIRX_FRAME_BPP))
/**< Frame Attribute: size in bytes */
#define BOARD_DIAG_CSIRX_FRAME_SIZE                       ((uint32_t)\
            (BOARD_DIAG_CSIRX_FRAME_HEIGHT * BOARD_DIAG_CSIRX_FRAME_WIDTH * BOARD_DIAG_CSIRX_FRAME_BPP))

/**< Maximum number of error frame logs to store.
     It stores most recent errors.*/
#define BOARD_DIAG_CSIRX_ERR_FRAME_LOG_MAX                                  ((uint32_t)500U)

/**< CSIRX sensor slave address */
#define BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR                      (0x3DU)

/**
 *  \brief Capture application object.
 */
typedef struct
{
    uint32_t instId;
    /**< Csirx Drv Instance ID. */
    Csirx_InitParams initPrms;
    /**< Csirx init time parameters */
    Csirx_CreateParams createPrms;
    /**< Csirx create time parameters */
    Csirx_CreateStatus createStatus;
    /**< Csirx create time status */
    Fvid2_Handle drvHandle;
    /**< FVID2 capture driver handle. */
    Fvid2_CbParams cbPrms;
    /**< Callback params. */
    uint32_t numFramesToCapture;
    /**< Number of frames to receive for a given configuration */
    volatile uint32_t numFramesRcvd;
    /**< Number of frames received */
    uint32_t frameErrorCnt;
    /**< Number of erroneous frames received */
    uint32_t maxWidth;
    /**< Max width in pixels - used for buffer allocation for all instance. */
    uint32_t maxHeight;
    /**< Max height in lines - used for buffer allocation for all instance. */
    Fvid2_Frame frames[BOARD_DIAG_CSIRX_FRAMES_PER_CH * BOARD_DIAG_CSIRX_MAX_CH];
    /**< FVID2 Frames that will be used for capture. */
    Csirx_InstStatus captStatus;
    /**< CSIRX Capture status. */
    uint32_t chFrmCnt[BOARD_DIAG_CSIRX_MAX_CH];
    /**< Number of frames captured per channel. */
    uint32_t errFrmCh[BOARD_DIAG_CSIRX_ERR_FRAME_LOG_MAX];
    /**< Channel to which error frame belongs. */
    uint32_t errFrmNo[BOARD_DIAG_CSIRX_ERR_FRAME_LOG_MAX];
    /**< Error frame number for the channel. */
    uint32_t errFrmTs[BOARD_DIAG_CSIRX_ERR_FRAME_LOG_MAX];
    /**< TS in ms. */
}BoardDiag_CsirxObj;

/**
 * \brief   This function executes CSI-Rx diagnostic test
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
int8_t BoardDiag_CsirxTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CSIRX_TEST_H_ */
