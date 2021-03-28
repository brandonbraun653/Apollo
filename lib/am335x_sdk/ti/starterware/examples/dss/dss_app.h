/**
 *  \file  dss_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the dss.
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

#ifndef DSS_APP_H_
#define DSS_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "dss.h"
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/** \brief Structure holding the LCD panel configuration parameters. */
typedef struct dssAppLcdCfg
{
    dssDispcLcdAttrCfg_t attrCfg;
    /**< Structure holding the LCD display attributes. */
    dssDispcLcdTimingCfg_t   timingCfg;
    /**< Structure holding the LCD timing parameters. */
    dssDispcLcdPolarityCfg_t polarityCfg;
    /**< Structure holding the LCD control signals polarity information. */
}dssAppLcdCfg_t;


/** \brief Structure holding the video pipeline configuration parameters. */
typedef struct dssAppVidCfg
{
    uint32_t enableVideo;
    /**< Control flag to enable/disable video pipeline. */
    dssDispcDmaCfg_t vidDma;
    /**< Video pipeline DMA configuration parameters. */
    dssVidFmtCfg_t   vidFmt;
    /**< Video pipeline input data format configuration parameters. */
    dssDispcVidWindowCfg_t vidWindow;
    /**< Video window configuration parameters. */
}dssAppVidCfg_t;


typedef struct dssAppCfg
{
    dssAppVidCfg_t vid;
    /**< Video pipeline configuration parameters. */
    dssAppLcdCfg_t lcd;
    /**< Lcd panel configuration parameters. */
    uint32_t solidBackgndColor;
    /**< Solid back ground color of the overlay. */
}dssAppCfg_t;


/** \brief Display Sub System Application data structure. */
typedef struct dssAppObj
{
    uint32_t dssInstAddr;
    /**< Display Sub System instance base address. */
    uint32_t dssSysIntrNum;
    /**< Display Sub System's system interrupt number. */
    uint32_t dssfunctionalClk;
    /**< Display Sub System's input functional clock value. */
    uint32_t dssLcdDeviceId;
    /**< Device ID of LCD panel that is connected to DSS. */
    uint32_t *pInputBuf;
    /**< Pointer to the input image buffer. */
    dssAppCfg_t dssCfg;
    /**< Display sub system IP configuration data structure. */
}dssAppObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/** \brief Default configuration values of DSS IP configuration
           data structure. */
extern dssAppObj_t DSSAPPOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   DSS IP configuration initialization api.
 *
 * \param   pDss        Pointer to the display sub system object.
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed.
 */
int32_t DSSAppInit(dssAppObj_t *pDss);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef DSS_APP_H_ */
