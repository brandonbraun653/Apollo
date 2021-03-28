/**
 * \file   rtc_app.c
 *
 * \brief  Source file containing the RTC IP related configuration functions.
 *         These functions will be called by example application.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "chipdb.h"
#include "pinmux.h"
#include "prcm.h"
#include "error.h"

/* Application header files */
#include "rtc_app.h"
#include "console_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   A Interrupt Service routine which is invoked when an RTC interrupt
 *           is raised. The ISR handles different cases like Periodic and
 *           Alarm Interrupts.
 *
 *  \param   intrNum     Interrupt number to which the interrupt event is mapped.
 *  \param   cpuId       Id of the CPU to which interrupt is raised.
 *  \param   puserParam  Parameter to be passed to the ISR.
 */
static void RtcAppIsr(uint32_t intrNum, uint32_t cpuId, void* pUserParam);

/**
 *  \brief   Initializes the interrupt controller and configures it with
 *           different parameters like triggertype, Interrupt Priority
 *           and registers the Interrupt Service Routine to be invoked
 *           when the Interrupt is raised.
 *
 *  \param   pRtcIntrConfig    pointer to the interrupt configuration structure.
 *
 *  \retval  S_PASS     If Interrupt Configuration successful
 *  \retval  E_FAIL     If Interrupt Configuration fails
 */
static int32_t RtcAppIntrConfig(rtcAppRtcObj_t *pRtcAppCfg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Structure which holds the Interrupt Configuration Params. */
static intcIntrParams_t gRtcAppIntrParams;

/** \brief IP default configuration. */
rtcAppRtcObj_t RTCAPPRTCOBJ_DEFAULT =
{
    0U,                             /* baseAddr */
    RTC_CLK_SRC_EXTERNAL,           /* clkSrc */
    {
        0U,                  /* hours */
        0U,                  /* minutes */
        0U,                  /* seconds */
        TIME_MODE_24_HR,     /* timeMode */
        TIME_MERIDIEM_AM,    /* meridiemMode */
    },  /* timeVal */
    {
        0U,                  /* year */
        0U,                  /* month */
        0U,                  /* day */
        0U,                  /* weekDay */
    },  /* dateVal */
    {
        0U,                  /* hours */
        0U,                  /* minutes */
        0U,                  /* seconds */
        TIME_MODE_24_HR,     /* timeMode */
        TIME_MERIDIEM_AM,    /* meridiemMode */
    },  /* alarmTime */
    {
        0U,                  /* year */
        0U,                  /* month */
        0U,                  /* day */
        0U,                  /* weekDay */
    },  /* alarmDate */
    {
        0U,                 /* rtcAppTimerEvt */
        0U                  /* rtcAppAlarmEvt */
    },  /* rtcAppClockEvt_t */
    {
        INTC_TRIG_HIGH_LEVEL,       /* trigType */
        0U,                         /* timerIntrNum */
        0U,                         /* alarmIntrNum */
        0x20U,                      /* intrPriority */
        FALSE,                      /* isIntrSecure */
        NULL,                       /* pFnIntrHandler */
    }   /* rtcAppIntrCfgObj */
};  /* rtcAppRtcObj_t */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t RTCAppInit(rtcAppRtcObj_t *pRtcCtrlCfg)
{
    int32_t status = S_PASS;

    /* RTC Module Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_RTCSS, 0U, 0U);

    if(S_PASS == status)
    {
        /* Disable Write Protection for RTC registers. */
        RTCWriteProtectEnable(pRtcCtrlCfg->baseAddr, FALSE);

        /* Selecting Clock source to drive the RTC. */
        RTCClkSrcSelect(pRtcCtrlCfg->baseAddr, pRtcCtrlCfg->clkSrc);

        /* Enable the RTC module */
        RTCEnable(pRtcCtrlCfg->baseAddr, TRUE);
    }

    return status;
}

int32_t RTCAppClockCfg(rtcAppRtcObj_t *pRtcObj)
{
    int32_t status = S_PASS;

    /* Initialize the interrupt controller */
    status = RtcAppIntrConfig(pRtcObj);

    if(S_PASS == status)
    {
        /* Set the Time in the RTC clock */
        RTCSetTime(pRtcObj->baseAddr, &pRtcObj->timeVal);

        /* Set the Date in the RTC clock */
        RTCSetDate(pRtcObj->baseAddr, &pRtcObj->dateVal);

        /* Start the RTC Clock */
        RTCRun(pRtcObj->baseAddr);
    }

    return status;
}

void RTCAppRTCOnlyEnable(rtcAppRtcObj_t *pRtcObj)
{
    /* Disable Timer Interrupt. */
    RTCTimerIntrDisable(pRtcObj->baseAddr);

    /* Enable RTC PMIC. */
    RTCConfigPmicPowerEnable(pRtcObj->baseAddr, TRUE);

    /* Clear the Alarm Interrupt. */
    RTCAlarmIntStatusClear(pRtcObj->baseAddr, RTC_ALARM_NUM_1);

    /* Clear the Alarm2 Interrupt. */
    RTCAlarmIntStatusClear(pRtcObj->baseAddr, RTC_ALARM_NUM_2);

    /* Select External Feedback */
    RTCFeedbackResistanceSelect(pRtcObj->baseAddr, RTC_FEEDBACK_RESISTOR_EXTERNAL);

    /* Enable External Oscillator. */
    RTCClkSrcSelect(pRtcObj->baseAddr, RTC_CLK_SRC_EXTERNAL);

    /* Enable Alarm wakeup. */
    RTCWakeupEnable(pRtcObj->baseAddr, RTC_WAKEUP_EVT_SRC_ALARM);

    /* Disable Timer wakeup. */
    RTCWakeupDisable(pRtcObj->baseAddr, RTC_WAKEUP_EVT_SRC_TIMER);

    /* Enable RTC smart-idle wakeup capable mode. */
    RTCIdleModeConfigure(pRtcObj->baseAddr, RTC_IDLE_MODE_SMART_IDLE_WAKEUP);

    /* Enable Alarm interrupt. */
    RTCIntAlarm2Enable(pRtcObj->baseAddr, RTC_ALARM_NUM_1);

    /* Enable Alarm2 interrupt. */
    RTCIntAlarm2Enable(pRtcObj->baseAddr, RTC_ALARM_NUM_2);

    /* Set the External Wakeup Pin polarity. */
    RTCConfigPmicExtWakePolarity(pRtcObj->baseAddr, RTC_EXT_WAKEUP_SRC_0,
        RTC_WAKEUP_EVT_POL_ACTV_LOW);

    /* Set the External Wakeup Source. */
    RTCPmicExtWakeupEnable(pRtcObj->baseAddr, RTC_EXT_WAKEUP_SRC_0);

    /* Disable the External Wakeup Source. */
    RTCPmicExtWakeupDebounceDisable(pRtcObj->baseAddr, RTC_EXT_WAKEUP_SRC_0);

    /* Clear the External Wakeup Event Status. */
    RTCPmicExtWakeStatusClear(pRtcObj->baseAddr, RTC_EXT_WAKEUP_SRC_0);

    /* Enable RTC PMIC */
    RTCConfigPmicPowerEnable(pRtcObj->baseAddr, TRUE);

    /* Enable the RTC module */
    RTCEnable(pRtcObj->baseAddr, TRUE);

    /* Start the RTC Clock */
    RTCRun(pRtcObj->baseAddr);
}

void RTCAppRTCOnlyConfig(rtcAppRtcObj_t *pRtcObj)
{
    timeObj_t timeOut = {0U, 0U, 0U, 0U, TIME_MODE_MIN, TIME_MERIDIEM_MIN};

    /* Set the sleep time for 10 seconds. */
    timeOut.seconds = 10U;
    /* Make sure the Time mode settings are the same. */
    timeOut.timeMode = pRtcObj->timeVal.timeMode;
    timeOut.meridiemMode = pRtcObj->timeVal.meridiemMode;

    /* Set the time to trigger sleep in the RTC clock */
    RTCSetTime(pRtcObj->baseAddr, &pRtcObj->timeVal);

    /* Set the Date in the RTC clock */
    RTCSetDate(pRtcObj->baseAddr, &pRtcObj->dateVal);

    /* Adding the alarm time. */
    RTCAppTimeAdd(&pRtcObj->alarmTime, &timeOut, &pRtcObj->alarmDate);

    /* Sets the alarm to trigger a Sleep sequence the RTC. */
    RTCSetAlarm(pRtcObj->baseAddr, RTC_ALARM_NUM_2, &pRtcObj->alarmTime,
             &pRtcObj->alarmDate);

    /* Set the Wakeup Time to about 20 seconds. */
    timeOut.seconds = 20U;

    /* Adding the alarm time. */
    RTCAppTimeAdd(&pRtcObj->alarmTime, &timeOut, &pRtcObj->alarmDate);

    /* Sets the alarm to trigger a Wakeup sequence the RTC. */
    RTCSetAlarm(pRtcObj->baseAddr, RTC_ALARM_NUM_1, &pRtcObj->alarmTime,
             &pRtcObj->alarmDate);
}

int32_t RTCAppTimeAdd(timeObj_t *pTime1, timeObj_t *pTime2, dateObj_t *pDate)
{
    timeObj_t timeOut = {0U, 0U, 0U, 0U, TIME_MODE_MIN, TIME_MERIDIEM_MIN};
    dateObj_t dateOut = {0U, 0U, 0U, WEEK_DAY_MIN};
    uint32_t lastDay = 0;

    /*  BCD addition    */
    timeOut.timeMode = pTime1->timeMode;

    timeOut.seconds = pTime1->seconds + pTime2->seconds;
    if(timeOut.seconds >= 60U)
    {
        timeOut.minutes++;
        timeOut.seconds %= 60U;
    }

    timeOut.minutes += pTime1->minutes + pTime2->minutes;
    if(timeOut.minutes >= 60U)
    {
        timeOut.hours++;
        timeOut.minutes %= 60U;
    }

    timeOut.hours += pTime1->hours;
    if((TIME_MODE_12_HR == pTime1->timeMode) &&
       (TIME_MERIDIEM_PM == pTime1->meridiemMode))
    {
        timeOut.hours += 12U;
    }

    timeOut.hours += pTime2->hours;
    if((TIME_MODE_12_HR == pTime2->timeMode) &&
       (TIME_MERIDIEM_PM == pTime2->meridiemMode))
    {
        timeOut.hours += 12U;
    }

    if(timeOut.hours >= 24U)
    {
        dateOut.day++;
        dateOut.weekDay++;
        timeOut.hours %= 24U;
    }

    if((TIME_MODE_12_HR == timeOut.timeMode) &&
       (timeOut.hours >= 12U))

    {
        timeOut.meridiemMode = TIME_MERIDIEM_PM;
    }

    if(1U == dateOut.day)
    {
        /*  adjust day  */
        switch(pDate->month)
        {
            case 1U:
            case 3U:
            case 5U:
            case 7U:
            case 8U:
            case 10U:
            case 12U:
                lastDay = 31U;
                break;

            case 4U:
            case 6U:
            case 9U:
            case 11U:
                lastDay = 30U;
                break;

            case 2U:
                /*  Leap year   */
                if(0 == (pDate->year%4))
                {
                    lastDay = 29U;
                }
                else /* Not leap year   */
                {
                    lastDay = 28U;
                }
                break;
        }

        if(lastDay == pDate->day)
        {
            dateOut.month++;
            dateOut.day = 1;
        }
        else
        {
            dateOut.day += pDate->day;
        }

        /*  adjust date of week */
        dateOut.weekDay += pDate->weekDay;
        dateOut.weekDay = dateOut.weekDay % 6U;

        /*  adjust month    */
        dateOut.month += pDate->month;
        if(dateOut.month >= 12U)
        {
            dateOut.year++;
            dateOut.month = dateOut.month - 12U;
        }

        /*  adjust year */
        dateOut.year += pDate->year;

        pDate->day = dateOut.day;
        pDate->month = dateOut.month;
        pDate->year = dateOut.year;
        pDate->weekDay = dateOut.weekDay;
    }

    pTime1->hours = timeOut.hours;
    pTime1->minutes = timeOut.minutes;
    pTime1->seconds = timeOut.seconds;
    pTime1->timeMode = timeOut.timeMode;
    pTime1->meridiemMode = timeOut.meridiemMode;

    if(1U == dateOut.day)
    {
        pDate->day = dateOut.day;
        pDate->month = dateOut.month;
        pDate->year = dateOut.year;
        pDate->weekDay = dateOut.weekDay;
    }

    return S_PASS;
}

/* ========================================================================== */
/*                 Internal Function Definitions                             */
/* ========================================================================== */

int32_t RtcAppIntrConfig(rtcAppRtcObj_t *pRtcAppCfg)
{
    int32_t status = S_PASS;

    /* Initialize the Interrupt Controller */
    if(TRUE == pRtcAppCfg->rtcAppIntrCfgObj.isIntrSecure)
    {
        INTCInit(INTC_SECURE_MODE);
    }
    else
    {
        INTCInit(INTC_NON_SECURE_MODE);
    }

    if(S_PASS == status)
    {
        /* Do the interrupt related configurations */
        gRtcAppIntrParams.triggerType =
                         pRtcAppCfg->rtcAppIntrCfgObj.intrTrigType;
        gRtcAppIntrParams.priority =
                         pRtcAppCfg->rtcAppIntrCfgObj.intrPriority;
        /*
        ** Assign the ISR to the function pointer to invoke when the
        ** interrupt is raised.
        */
        gRtcAppIntrParams.pFnIntrHandler = &RtcAppIsr;
        gRtcAppIntrParams.pUserParam = pRtcAppCfg;
        gRtcAppIntrParams.isIntrSecure =
                              pRtcAppCfg->rtcAppIntrCfgObj.isIntrSecure;

        /* Configure the interrupt Controller */
        status = INTCConfigIntr(pRtcAppCfg->rtcAppIntrCfgObj.timerIntrNum,
                                &gRtcAppIntrParams,
                                 pRtcAppCfg->rtcAppIntrCfgObj.isIntrSecure);
    }

    return status;
}

void RtcAppIsr(uint32_t intrNum, uint32_t cpuId, void* pUserParam)
{
    uint32_t status = 0U;
    rtcAppRtcObj_t *pRtcObj = (rtcAppRtcObj_t *) pUserParam;

    /* Read the Timer Interrupt Status */
    status = RTCEventUpdateGet(pRtcObj->baseAddr);

    if(0U != (status & RTC_TIMER_INTR_STS_ALL))
    {
        /* Disable the specific Timer interrupt. */
        RTCTimerIntrDisable(pRtcObj->baseAddr);

        /* Return the Timer event status */
        pRtcObj->clockEvent.timerEvt = status;
    }
}
