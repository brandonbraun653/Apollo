/**
 *  \file  countdown_timer_app.h
 *
 *  \brief This file contains the function prototypes reqeuired for 
 *  implementing the count down timer example. 
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

#ifndef COUNTDOWN_TIMER_APP_H_
#define COUNTDOWN_TIMER_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "console_utils.h"
#include "dmtimer_app.h"

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

/** \brief  This is the main application data structure. */
typedef struct dmtimerAppCdt
{
    uint32_t cntValue;
    /**< Count value - from what value to count down. */
    dmtimerAppCfg_t  dmtimerObj;
    /**< dmtimer app object. */
    
}dmtimerAppCdt_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Called by main to run the Countdown timer example application .
 *
 * \param   pCountdownTimerObj  Pointer to countdown appliation object. 
 *          - #dmtimerAppCdt_t
 * 
 */
void DMTIMERAppCountdownTimerRun(dmtimerAppCdt_t *pCountdownTimerObj);

/**
 * \brief   Called by the app main for initialising the timer with config params.
 *
 * \param   pCountdownTimerObj  Pointer to countdown appliation object .
 *          - #dmtimerAppCdt_t
 */
void DMTIMERAppCountdownTimerInit(dmtimerAppCdt_t *pCountdownTimerObj);
#ifdef __cplusplus
}
#endif

#endif /* #ifndef COUNTDOWN_TIMER_APP_H_ */
