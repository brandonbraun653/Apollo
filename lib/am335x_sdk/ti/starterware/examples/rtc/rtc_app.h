/**
 *  \file       rtc.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the RTC IP configuration.
 *
 */

/**
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

#ifndef RTC_APP_H_
#define RTC_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "rtc.h"
#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Structure holding I2C Interrupt configuration Parameters. */
typedef struct rtcAppIntrCfgObj
{
    intcTrigType_t intrTrigType;
    /**< Type of interrupt Edge/Level. */
    uint32_t timerIntrNum;
    /**< Timer Interrupt number. */
    uint32_t alarmIntrNum;
    /**< Alarm Interrupt number. */
    uint32_t intrPriority;
    /**< Interrupt priority level. */
    uint32_t isIntrSecure;
    /**< Secure Interrupt or not */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this.
     */
}rtcAppIntrCfgObj_t;

/** \brief Structure containing status flags for RTC Clock events. */
typedef struct rtcAppTimerEvt
{
    uint32_t timerEvt;
    /**< Value holding the status of timer events. */
    uint32_t alarmEvt;
    /**< Value holding the status of alarm events. */
}rtcAppClockEvt_t;

/** \brief Structure holding the RTC Object data structure. */
 typedef struct rtcAppRtcObj
 {
    uint32_t baseAddr;
    /**< RTC module base address. */
    rtcClkSrc_t clkSrc;
    /**< Clock source to be used for the RTC module. */
    timeObj_t  timeVal;
    /**< Structure holding the Time value information. */
    dateObj_t  dateVal;
    /**< Structure holding the Date value information. */
    timeObj_t  alarmTime;
    /**< Structure holding the Alarm Time information. */
    dateObj_t  alarmDate;
    /**< Structure holding the Alarm Date information. */
    volatile rtcAppClockEvt_t  clockEvent;
    /**< Structure holding Clock events information. */
    rtcAppIntrCfgObj_t rtcAppIntrCfgObj;
    /**< RTC interrupt configuration structure */
 }rtcAppRtcObj_t;

/** \brief enumerates the wake configurations */
typedef enum rtcAppWakeSrcCfg
{
    RTC_APP_WAKE_SRC_CFG_MIN = 0U,
    /**< Minimum value of the Week Day */
    RTC_APP_WAKE_SRC_CFG_WKUP_TIMER = RTC_APP_WAKE_SRC_CFG_MIN,
    /**< Indicates Sunday */
    RTC_APP_WAKE_SRC_CFG_WKUP_ALARM,
    /**< Indicates Monday */
    RTC_APP_WAKE_CFG_INT_TIMER,
    /**< Indicates Tuesday */
    RTC_APP_WAKE_CFG_INT_ALARM,
    /**< Indicates Wednesday */
    RTC_APP_WAKE_SRC_CFG_MAX = RTC_APP_WAKE_CFG_INT_ALARM
    /**< Maximum value of the Week Day */
}rtcAppWakeCfg_t;

/** \brief Structure for holding the RTC PM configuration. */
typedef struct rtcAppWakeConfig
{
    timeObj_t offsetTime;
    /**< offset time for the alarm to be set. */
}rtcAppPmWakeCfg_t;

/**
 * \brief  Initializes the RTC module by enabling module clocks, selecting
 *         the clock source for the RTC Timer and configures the interrupts.
 *
 * \param   pRtcCtrlCfg    Pointer to the RTC #rtcAppRtcObj_t structure holding
 *                         information like baseAddr, clock sources and
 *                         interrupt configuration.
 *
 * \retval  S_PASS on Successful Initialization
 * \retval  E_FAIL on failure to initialize the RTC module.
 */
int32_t RTCAppInit(rtcAppRtcObj_t *pRtcCtrlCfg);

/**
 * \brief    Configures the date and time for RTC clock and sets the RTC
 *           counter running.
 *
 * \param   pRtcCtrlCfg    Pointer to the RTC #rtcAppRtcObj_t structure holding
 *                         information like baseAddr, date and time information.
 *
 * \retval  S_PASS on Successful Initialization
 * \retval  E_FAIL on failure
 */
int32_t RTCAppClockCfg(rtcAppRtcObj_t *pRtcObj);

/**
 * \brief    Enables the RTC-Only Power Management mode feature.
 *
 * \param   pRtcObj    Pointer to the RTC #rtcAppRtcObj_t structure holding
 *                     information like baseAddr, date and time information.
 */
void RTCAppRTCOnlyEnable(rtcAppRtcObj_t *pRtcObj);

/**
 * \brief    Configures the Time, Wakeup Sources and Alarm Times to demonstrate
 *           the RTC-Only Power Management mode feature.
 *
 * \param    pRtcObj    Pointer to the RTC #rtcAppRtcObj_t structure holding
 *                      information like baseAddr, date and time information.
 */
void RTCAppRTCOnlyConfig(rtcAppRtcObj_t *pRtcObj);

/**
 *  \brief     This function adds two time values in 24 hour format and
 *             updates date.
 *
 *  \param     pTime1  Pointer to the First time value
 *  \param     pTime2  Pointer to the Second time value
 *  \param     pDate   Pointer to the Input date for time1 and
 *                     effective date after adding time2
 *
 *  \retval    Sum of two given time values.
 */
int32_t RTCAppTimeAdd(timeObj_t *pTime1, timeObj_t *pTime2, dateObj_t *pDate);

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef RTC_APP_H_ */
