/**
 *  \file  epwm_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the epwm IP configuration.
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

#ifndef EPWM_APP_H_
#define EPWM_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "epwm.h"
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

/** \brief Structure holding the EPWM configuration parameters. */
typedef struct epwmAppPwmCfg
{
    epwmTimebaseCfg_t tbCfg;
    /**< Timebase Sub-module configuration data structure. */
    epwmCounterCmpCfg_t ccCfg;
    /**< Counter comparator values . */
    epwmAqActionCfg_t aqCfg;
    /**< Action Qualifier Sub-module configuration data structure. */
    epwmDeadbandCfg_t dbCfg;
    /**< Dead band Sub-module configuration data structure. */
    epwmChopperCfg_t chpCfg;
    /**< Chopper sub-module configuration data structure. */
    epwmTripzoneCfg_t tzCfg;
    /**< Trip-zone sub-module configuration data structure. */
    epwmEtCfg_t etCfg;
    /**< Event Trigger sub-module configuration data structure. */
    epwmHighResolutionCfg_t hrCfg;
    /**< High Resolution sub-module configuration data structure. */
}epwmAppPwmCfg_t;


/**< \brief Structure holding the EPWM object data structure. */
typedef struct epwmAppPwmObj
{
    uint32_t pwmCh;
    /**< EPWM channel [A or B]. */
    uint32_t instNum;
    /**< EPWM instance number. */
    uint32_t instAddr;
    /**< EPWM instance address. */
    uint32_t funcClk;
    /**< Functional clock(in Hz) input to the PWMSS. */
    uint32_t enableDeadband;
    /**< Enable dead band sub-module processing. */
    uint32_t enableChopper;
    /**< Enable chopper sub-module processing. */
    uint32_t enableTripZone;
    /**< Enable Trip zone processing. */
    uint32_t enableEventTrigger;
    /**< Enable Event trigger. */
    uint32_t enableHighResolution;
    /**< Enable High resolution pwm feature. */
    epwmAppPwmCfg_t pwmCfg;
    /**< EPWM configuration data structure. */
}epwmAppPwmObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* Global structure containing the IP configuration defaults */
extern epwmAppPwmObj_t EPWMAPPPWMOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   EPWM IP configuration functional API.
 *
 * \param   pPwm        Pointer to the pwm object.
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed(either Pinmux or Clock
 *                      configuration is failed) is failed.
 */
uint32_t EPWMAppInit(epwmAppPwmObj_t *pPwm);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef EPWM_APP_H_ */
