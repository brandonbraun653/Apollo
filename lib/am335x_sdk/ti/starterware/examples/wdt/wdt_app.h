/**
 * \file      wdt_app.h
 *
 * \brief     This file contains the function declarations and data structures
 *            corresponding to WDT application.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef WDT_APP_H_
#define WDT_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef struct wdtAppCtrl
{
    uint32_t enablePrescaler;
    /**< Enable/Disable prescaler. */
}wdtAppCtrl_t;

/**< \brief Structure holding the WDT object data structure. */
typedef struct wdtAppCfgObj
{
    uint32_t instNum;
    /**< WDT instance number. */
    uint32_t instAddr;
    /**< WDT instance address. */
    uint32_t prescaler;
    /**< Prescaler value to be configured. */
    uint32_t counterVal;
    /**< Counter value to be programmed. */
    uint32_t reloadVal;
    /**< Reload value to be programmed. */
    wdtAppCtrl_t wdtCtrl;
    /**< This flag will be used to control the application flow.
         WDT flag structure will allow user to Enable/disable prescaler.
    */
}wdtAppCfgObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    WDT IP configuration initialization function.
 *
 * \details  This function configures the WDT controller with the user passed
 *           values.
 *
 * \param    pCfgWdt       Pointer to the WDT configuration object.
 *                         #wdtAppCfgObj_t
 *
 * \retVal   S_PASS        WDT initialization successful.
 * \retVal   E_FAIL        WDT initialization failed.
 */
int32_t WDTAppInit(wdtAppCfgObj_t *pCfgWdt);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef WDT_APP_H_ */
