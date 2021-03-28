/**
 *  \file  lcdc_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the LCDC.
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

#ifndef LCDC_APP_H_
#define LCDC_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "lcdc.h"
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
typedef struct lcdcAppLcdCfg
{
    lcdcRasterDisplayAttrCfg_t attrCfg;
    /**< Structure holding the LCD display attributes. */
    lcdcRasterTimingCfg_t   timingCfg;
    /**< Structure holding the LCD timing parameters. */
    lcdcRasterPolarityCfg_t polarityCfg;
    /**< Structure holding the LCD control signals polarity information. */
}lcdcAppLcdCfg_t;


/** \brief Structure holding the IP configuration parameters. */
typedef struct lcdcAppCfg
{
    lcdcDmaCfg_t dma;
    /**< LCDC DMA configuration parameters. */
    lcdcAppLcdCfg_t lcd;
    /**< Lcd panel configuration parameters. */
}lcdcAppCfg_t;


/** \brief LCD controller Application data structure. */
typedef struct lcdcAppObj
{
    uint32_t lcdcInstAddr;
    /**< LCD controller instance base address. */
    uint32_t lcdcSysIntrNum;
    /**< LCD controller's system interrupt number. */
    uint32_t lcdcfunctionalClk;
    /**< LCD controller's input functional clock value. */
    uint32_t lcdcLcdDeviceId;
    /**< Device ID of LCD panel that is connected to LCDC. */
    uint8_t *pInputBuf;
    /**< Pointer to the input image buffer. */
    uint32_t inputBufSize;
    /**< Size of the input frame buffer in bytes. */
    lcdcAppCfg_t lcdcCfg;
    /**< LCD controller IP configuration data structure. */
}lcdcAppObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/** \brief Default configuration values of LCDC IP configuration
           data structure. */
extern lcdcAppObj_t LCDCAPPOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   LCDC IP configuration initialization API.
 *
 * \param   pLcdc       Pointer to the lcd controller object.
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed.
 */
int32_t LCDCAppInit(lcdcAppObj_t *pLcdc);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef LCDC_APP_H_ */
