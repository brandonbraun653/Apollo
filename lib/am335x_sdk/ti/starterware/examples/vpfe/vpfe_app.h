/**
 *  \file  vpfe_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the vpfe.
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

#ifndef VPFE_APP_H_
#define VPFE_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "vpfe.h"
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Function pointer call back for VPFE ISR.
 *
 *  \param currBufAddr Address of the buffer currently in use.
 */
typedef uint32_t (*VPFEAppCallbackFxn)(uint32_t currBufAddr);

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure containing the VPFE IP configuration parameters. */
typedef struct vpfeAppCfg
{
    vpfeCfg_t ioCfg;
    /**< VPFE IP Input and Output configurations. */
    vpfeAdvCfg_t *pAdvCfg;
    /**< VPFE advanced image processing configurations. */
}vpfeAppCfg_t;


/** \brief VPFE Application data structure. */
typedef struct vpfeAppObj
{
    uint32_t vpfeInstNum;
    /**< VPFE instance number. */
    uint32_t vpfeInstAddr;
    /**< VPFE instance base address. */
    uint32_t vpfeSysIntrNum;
    /**< VPFE's system interrupt number. */
    uint32_t vpfeCameraDeviceId;
    /**< Camera sensor device id which is connected on the board. */
    uint32_t cameraI2cInstNum;
    /**< I2C instance number to which camera sensor control interface is
        connected. */
    VPFEAppCallbackFxn pFnIsrCb;
    /**< VPFE application ISR call back function. */
    uint32_t inputBufAddr;
    /**< Address of the input buffer. */
    uint32_t outputBufAddr;
    /**< Address of the input buffer. */
    uint32_t outputBufSize;
    /**< Size of the output buffer. */
    uint32_t inputFrmWidth;
    /**< Input frame width in pixels per line. */
    uint32_t inputFrmHeight;
    /**< Input frame height in lines per panel. */
    uint32_t inputPixelFmt;
    /**< Input data pixel format. */
    vpfeAppCfg_t vpfeCfg;
    /**< VPFE IP configuration data structure. */
}vpfeAppObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/** \brief Default configuration values of VPFE IP configuration
           data structure. */
extern vpfeAppObj_t VPFEAPPOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   VPFE IP configuration initialization API. This API performs clocks,
 *          pin mux and IP configurations.
 *
 * \param   pVpfe       Pointer to the VPFE object.
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed.
 */
int32_t VPFEAppInit(vpfeAppObj_t *pVpfe);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef VPFE_APP_H_ */
