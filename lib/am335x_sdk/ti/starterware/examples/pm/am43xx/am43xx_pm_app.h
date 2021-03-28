/**
 *  \file  am43xx_pm_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the PM.
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

#ifndef AM43XX_PM_APP_H_
#define AM43XX_PM_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "am43xx_pm_app_modules.h"

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

/** \brief enumerates the wake configurations */
typedef enum pmAppPwrModes
{
    PM_APP_PWR_MODES_MIN = 0U,
    /**< Minimum value of the Week Day */
    PM_APP_PWR_MODES_DS0 = PM_APP_PWR_MODES_MIN,
    /**< Indicates Sunday */
    PM_APP_PWR_MODES_DS1,
    /**< Indicates Monday */
    PM_APP_PWR_MODES_STANDBY,
    /**< Indicates Tuesday */
    PM_APP_PWR_MODES_MAX = PM_APP_PWR_MODES_STANDBY
    /**< Maximum value of the Week Day */
}pmAppPwrModes_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void PMAppInit(pmAppInitObj_t *pInitObj);

/**
 * \brief  Suspend and resume system.
 *
 * \param  sleepMode     Sleep mode to configured.
 * \param  deviceVersion SoC device version.
 *
 * \retval S_PASS on successful executed system suspend and resume.
 * \retval E_FAIL on failure to suspend and resume system.
 */
void PMAppPowerSaveModeEnter(pmAppCfgObj_t *pSuspendCfg, uint32_t slpMode);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef AM43XX_PM_APP_H_ */
