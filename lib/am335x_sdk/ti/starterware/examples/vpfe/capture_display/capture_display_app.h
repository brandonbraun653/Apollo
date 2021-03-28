/**
 *  \file  capture_display_app.h
 *
 *  \brief This file contains the use case specific function declarations.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef CAPTURE_DISPLAY_APP_H_
#define CAPTURE_DISPLAY_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "vpfe_app.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Number of input buffers. */
#define VPFE_APP_NUM_IN_BUFS   (2U)

/** \brief Number of output buffers. */
#define VPFE_APP_NUM_OUT_BUFS  (2U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the frame buffer configuration parameters. */
typedef struct vpfeAppFrmBufCfg
{
    volatile uint32_t inputBufIdx;
    /**< current active input buffer index. */
    volatile uint32_t inputBufPtr[VPFE_APP_NUM_IN_BUFS];
    /**< Array of pointers holding the addresses of input buffers. */
    volatile uint32_t currInputBuf;
    /**< address of input buffer currently in use. */
    volatile uint32_t nextInputBuf;
    /**< address of the empty input buffer that will be used next. */
    uint32_t outputBufIdx;
    /**< currently active output buffer index.*/
    uint32_t outputBufPtr[VPFE_APP_NUM_OUT_BUFS];
    /**< Array of pointers holding the addresses of output buffers. */
    volatile uint32_t inputBufReady;
    /**< Flag indicating that input buffer is filled with data and is ready. */
    volatile uint32_t inputReadyBufAddr;
    /**< Address of input buffer that is filled with data. */
    volatile uint32_t outputReadyBufAddr;
    /**< Address of the output buffer that is ready for display. */
}vpfeAppFrmBufCfg_t;


/** \brief Structure holding the raster use case configuration parameters. */
typedef struct vpfeAppRasterCfg
{
    uint32_t  inputFrmWidth;
    /**< Frame width in number of pixels per line. */
    uint32_t  inputFrmHeight;
    /**< Frame height in number of lines per image. */
    uint32_t  inputFrmPixelFmt;
    /**< Input image video data pixel format. */
}vpfeAppRasterCfg_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CAPTURE_DISPLAY_APP_H_ */
