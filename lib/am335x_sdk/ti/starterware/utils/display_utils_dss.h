/**
 *  \file     display_utils_dss.h
 *
 *  \brief    This file contains the display utility APIs.
 *
 *  \copyright Copyright (C) 2013 - 2018 Texas Instruments Incorporated -
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

#ifndef  DISPLAY_UTILS_DSS_H_
#define  DISPLAY_UTILS_DSS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "dss.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief Function pointer typedef for ISR call back function.
 *
 *  \details This function gets the pointer the image buffer which has to be
 *           displayed next. This will also pass the address of the buffer
 *           which is displayed currently.
 */
typedef uint32_t (*DISPLAYUtilsIsrCallbackFxn)(uint32_t currBufAddr);


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the overlay configuration parameters. */
typedef struct displayUtilsDssDispcOvlyCfg_t
{
    uint32_t solidBackGndColor;
    /**< Solid back ground colour. */
}displayUtilsDssDispcOvlyCfg_t;


/** \brief Structure holding the LCD panel configuration parameters. */
typedef struct displayUtilsDssDispcLcdCfg
{
    dssDispcLcdAttrCfg_t attrCfg;
    /**< Structure holding the LCD display attributes. */
    dssDispcLcdTimingCfg_t   timingCfg;
    /**< Structure holding the LCD timing parameters. */
    dssDispcLcdPolarityCfg_t polarityCfg;
    /**< Structure holding the LCD control signals polarity information. */
}displayUtilsDssDispcLcdCfg_t;


/** \brief Structure holding the video pipeline configuration parameters. */
typedef struct displayUtilsDssDispcVidCfg
{
    uint32_t enableVideo;
    /**< Control flag to enable/disable video pipeline. */
    dssDispcDmaCfg_t vidDma;
    /**< Video pipeline DMA configuration parameters. */
    dssVidFmtCfg_t   vidFmt;
    /**< Video pipeline input data format configuration parameters. */
    dssDispcVidWindowCfg_t vidWindow;
    /**< Video window configuration parameters. */
}displayUtilsDssDispcVidCfg_t;


/** \brief Structure holding the display sub system configuration parameters. */
typedef struct displayUtilsDssCfg
{
    displayUtilsDssDispcVidCfg_t vid;
    /**< Video pipeline configuration parameters. */
    displayUtilsDssDispcLcdCfg_t lcd;
    /**< Lcd panel configuration parameters. */
    displayUtilsDssDispcOvlyCfg_t ovly;
    /**< Overlay configuration parameters. */
}displayUtilsDssCfg_t;


/** \brief Display Sub System Application data structure. */
typedef struct displayUtilsDssObj
{
    uint32_t dssInstAddr;
    /**< Display Sub System instance base address. */
    uint32_t dssSysIntrNum;
    /**< Display Sub System's system interrupt number. */
    uint32_t dssfunctionalClk;
    /**< Display Sub System's input functional clock value. */
    uint32_t dssLcdDeviceId;
    /**< Device ID of LCD panel that is connected to DSS. */
    uint32_t inputBufAddr;
    /**< Starting address of the input buffer. */
    DISPLAYUtilsIsrCallbackFxn pFnIsrCb;
    /**< ISR call back function to get the next buffer pointer that has to be
         displayed. */
    uint32_t currBufAddr;
    /**< Starting address of the image buffer that is currently displayed. */
    uint32_t nextBufAddr;
    /**< Starting address of the image buffer that will be displayed next. */
    displayUtilsDssCfg_t dssCfg;
    /**< Display sub system IP configuration data structure. */
}displayUtilsDssObj_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DISPLAY_UTILS_DSS_H_ */
