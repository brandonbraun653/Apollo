/*
 * \file     time_utils.h
 *
 * \brief    This file contains prototypes of time utilities like timer init, 
 *           time-stamp, and software timer. These APIs are platform 
 *           independent and the definitions/implementations are specific to 
 *           the platform.
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

#ifndef TIME_UTILS_H_
#define TIME_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "error.h"
#include "date_time.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief  Invalid handle for timer object  */
#define TIME_TIMER_HANDLE_INVALID       (0xFFFFFFFFU)
#define TIMER_MAX_SW_TIMERS             (10U)

#define TIME_NANO_SEC                   (1000000000U)
#define TIME_NANO_SEC_FL                (1000000000.0f)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Structures and Enums                              */
/* ========================================================================== */

/** \brief Enumerates mode of transfer operation. */
typedef enum timeClockSel
{
    TIME_CLOCK_SEL_32KHZ_PLL = 0x0U,
    /**< Input clock rate is 32Khz from PLL. */
    TIME_CLOCK_SEL_32KHZ_INT_RC_OSC = 0x1U,
    /**< Input clock rate is 32Khz from internal RC oscillator. */
    TIME_CLOCK_SEL_32KHZ_EXT_CRY_OSC = 0x2U,
    /**< Input clock rate is 32Khz from external crystal oscillator. */
    TIME_CLOCK_SEL_24MHZ_EXT_CRY_OSC = 0x3U
    /**< Input clock rate is 24Mhz from external crystal oscillator. */
}timeClockSel_t;

/** \brief This structure defines the properties of clock source timer. */
typedef struct timeUtilsObj
{
    uint32_t timerInst;
    /**< HW timer instance number */
    timeClockSel_t inputClockSel;
    /**< Input clock selection for HW timer module */
    uint32_t isRegAccessPosted;
    /**< Timer reg access is posted or not. */
    uint32_t tickResolution;
    /**< Output tick resolution in micro seconds. Applicable only for tick 
         timer and not for free running timer. */
}timeUtilsObj_t;

/** /brief Time and date. */
typedef struct timeDate
{
    timeObj_t time;
    /**< Time object which can store time in standard format. */
    dateObj_t date;
    /**< Date object which can store date in standard format. */
}timeDate_t;

/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */

/**
 * \brief   This API configures the timers which will be used to maintain the
 *          64-bit free running counter and basic tick of the system.
 *
 * \param   pFreeRunTimer- Parameters for timer instance which will be
 *          used for maintaining free running 64-bit counter.
 *
 * \param   pTickTimer- Parameter for timer instance which will be used for
 *          maintaining the tick of the system. The tick will be used to implement
 *          delay, sleep and software timer functionalities. The tick period
 *          can be configured during initialization.
 *
 * Note: One of the parameters for this API can be NULL, based on the usage 
 *       requirement, just that the API's depending on that timer will not work 
 *       as expected. In such cases the API will not return failure (E_FAIL).
 *       pFreeRunTimer is needed for time-stamp, delay and sleep API's.
 *       pTickTimer is needed for software timer API's.
 *
 * \retval S_PASS Timer initialization succeeded
 * \retval E_FAIL Timer initialization failed
 **/
int32_t TIMEUtilsInit(timeUtilsObj_t *pFreeRunTimer, timeUtilsObj_t *pTickTimer);

/**
 * \brief   This API sets the time-stamp of the free running timer.
 *
 * \param   nanoSec- time-stamp value equivalent to nano sec time to be set.
 *
 * Note: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *       API.
 **/
void TIMESetTimeStamp(uint64_t nanoSec);

/**
 * \brief   This API gets the time-stamp of the free running timer.
 *
 * Note: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call 
 *       this API.
 *
 * \retval  Time-stamp value in nano sec.
 **/
uint64_t TIMEGetTimeStamp(void);

/**
 * \brief   This API converts the time-stamp to timeDate_t format.
 *
 * \param   time-stamp in nano sec
 *
 * \retval  Time and date in the format #timeDate_t
 **/
timeDate_t TIMEStamp2TimeDate(uint64_t timeStamp);

/**
 * \brief   This API converts the wall clock time to time-stamp.
 *
 * \param   timeDate- Time and date in the format #timeDate_t
 *
 * \retval  Time-stamp in nano sec
 **/
uint64_t TIMEDate2TimeStamp(timeDate_t *pTimeDate);

/**
 * \brief   This API registers a software timer and provides callback on timer 
 *          expiry. It also starts the timer.
 *
 * \param   pCallBackfunc Call back function pointer to be called on timer 
 *                        expiry.
 * \param   expiryTimeUs  Expiry time for the timer in micro seconds.
 * \param   isOneShot     Flag to indicate if the timer is one shot timer(TRUE)
 *                        or recurring timer (FALSE).
 *
 * Note: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *       API. 
 *
 * \retval  Handle (+ve values)- Timer handle to the software timer
 * \retval  TIME_TIMER_HANDLE_INVALID - Timer can't be registered.
 **/
int32_t TIMEUtilsRegisterTimer(void(*pCallBackFunc)(void*),
                                uint32_t expiryTimeUs, uint32_t isOneShot );

/**
 * \brief   This API stops the software timer registered using the API 
 *          TimerRegister().
 *
 * \param   handle- Software timer handle returned by #TimerRegister
 *
 * Note: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *       API.
 *
 * \retval  S_PASS Timer is stopped successfully
 * \retval  E_FAIL Timer can't be stopped
 **/
int32_t TIMEUtilsUnregisterTimer(int32_t handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TIME_H_ */
