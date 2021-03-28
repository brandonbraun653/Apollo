/**
 *   @file  csl_rtc.h
 *
 *   @brief
 *      This is the main header file for the RTC Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002-2011, Texas Instruments, Inc.
 *
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

/** @defgroup CSL_RTC_API RTC
 *
 */

#ifndef CSL_RTC_H_
#define CSL_RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_rtc.h>

/**
@defgroup CSL_RTC_SYMBOL  RTC Symbols Defined
@ingroup CSL_RTC_API
*/

/**
@defgroup CSL_RTC_DATASTRUCT  RTC Data Structures
@ingroup CSL_RTC_API
*/
/**
@defgroup CSL_RTC_FUNCTION  RTC Functions
@ingroup CSL_RTC_API
*/
/**
@defgroup CSL_RTC_ENUM RTC Enumerated Data Types
@ingroup CSL_RTC_API
*/

/** @{ */
/** @brief RTC KICK0 register UNLOCK key used to disable Write Protection. */
#define CSL_RTC_KICK0_UNLOCK_KEY                            (0x83E70B13U)

/** @brief RTC KICK0 register UNLOCK key used to disable Write Protection. */
#define CSL_RTC_KICK1_UNLOCK_KEY                            (0x95A4F1E0U)

/** @brief RTC KICK0 register LOCK key used to enable Write Protection. */
#define CSL_RTC_KICK0_LOCK_KEY                              (0xFFFFFFFFU)

/** @brief RTC KICK1 register LOCK key used to enable Write Protection. */
#define CSL_RTC_KICK1_LOCK_KEY                              (0xFFFFFFFFU)
/** @} */

/** @brief Macro to wait till the RTC registers are free to access.
           Loops continuously till the RTC is busy updating an event. */
#define CSL_RTC_WAIT_FOR_WRITE         while(0x1U == \
                                    (CSL_FEXT(hRtc->STS, \
                                     RTC_STS_BUSY))){}

/** @brief Macro to identify the correct Alarm Seconds register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_SECONDS(alarmNum) ((1U == (alarmNum)) ? \
                hRtc->ALARM_SECONDS: hRtc->ALARM2_SECONDS)

/** @brief Macro to identify the correct Alarm Minutes register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_MINUTES(alarmNum) ((1U == (alarmNum)) ? \
                hRtc->ALARM_MINUTES: hRtc->ALARM2_MINUTES)

/** @brief Macro to identify the correct Alarm Hours register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_HOURS(alarmNum) (((alarmNum) == 1) ? \
                hRtc->ALARM_HOURS: hRtc->ALARM2_HOURS)

/** @brief Macro to identify the correct Alarm Days register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_DAYS(alarmNum) (((alarmNum) == 1) ? \
                hRtc->ALARM_DAYS: hRtc->ALARM2_DAYS)

/** @brief Macro to identify the correct Alarm Months register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_MONTHS(alarmNum) (((alarmNum) == 1) ? \
                hRtc->ALARM_MONTHS: hRtc->ALARM2_MONTHS)

/** @brief Macro to identify the correct Alarm Years register based on Alarm
           Number passed. */
#define CSL_RTC_MAKE_ALARM_YEARS(alarmNum) (((alarmNum) == 1) ? \
                hRtc->ALARM_YEARS: hRtc->ALARM2_YEARS)

/**
@addtogroup CSL_RTC_ENUM
@{
*/

/**
 * General purpose global type def declarations
 */

/** @brief Enumerates the different clock sources for RTC */
typedef enum
{
    /**
     * @brief   External Clock source for the RTC module
     */
    CSL_RTC_CLK_SRC_INTERNAL = 0x0U,

    /**
     * @brief   Internal clock source for the RTC module
     */
    CSL_RTC_CLK_SRC_EXTERNAL = 0x1U
} CSL_rtcClkSrc;

/** @brief Enumerates the different possible Timer Interrupt types */
typedef enum
{
    /**
     * @brief   Periodic Timer Interrupt for Every Second
     */
    CSL_RTC_TIMER_INTR_MASK_EVERY_SEC = 0x0U,

    /**
     * @brief   Periodic Timer Interrupt for Every Minute
     */
    CSL_RTC_TIMER_INTR_MASK_EVERY_MIN = 0x1U,

    /**
     * @brief   Periodic Timer Interrupt for Every Hour
     */
    CSL_RTC_TIMER_INTR_MASK_EVERY_HR = 0x2U,

    /**
     * @brief   Periodic Timer Interrupt for Every Day
     */
    CSL_RTC_TIMER_INTR_MASK_EVERY_DAY = 0x3U
} CSL_rtcTimerIntrMask;

/** @brief Enumerates the RTC Timer Interrupt Status. */
typedef enum
{
    /**
     * @brief   Indicates 1 Day Interrupt Status
     */
    CSL_RTC_TIMER_INTR_STS_ONE_DAY = CSL_RTC_STS_EVT_1D_MASK,

    /**
     * @brief   Indicates 1 Hour Interrupt Status
     */
    CSL_RTC_TIMER_INTR_STS_ONE_HR = CSL_RTC_STS_EVT_1H_MASK,

    /**
     * @brief   Indicates 1 Minute Interrupt Status
     */
    CSL_RTC_TIMER_INTR_STS_ONE_MIN = CSL_RTC_STS_EVT_1M_MASK,

    /**
     * @brief   Indicates 1 Second Interrupt Status
     */
    CSL_RTC_TIMER_INTR_STS_ONE_SEC = CSL_RTC_STS_EVT_1S_MASK,

    /**
     * @brief   Mask value to determine occurrence of a Timer event
     */
    CSL_RTC_TIMER_INTR_STS_ALL = (CSL_RTC_STS_EVT_1D_MASK |
                               CSL_RTC_STS_EVT_1H_MASK |
                               CSL_RTC_STS_EVT_1M_MASK |
                               CSL_RTC_STS_EVT_1S_MASK)
} CSL_rtcTimerIntrSts;

/** @brief Enumerates the RTC Alarm Interrupt Status. */
typedef enum
{
    /**
     * @brief   Indicates the ALARM Interrupt has occurred
     */
    CSL_RTC_ALARM_INTR_STS_ALARM = CSL_RTC_STS_ALARM_MASK,

    /**
     * @brief   Indicates ALARM2 Interrupt has occurred
     */
    CSL_RTC_ALARM_INTR_STS_ALARM2 = CSL_RTC_STS_ALARM2_MASK,

    /**
     * @brief   Mask value to determine occurrence of an alarm event
     */
    CSL_RTC_ALARM_INTR_STS_ALL = (CSL_RTC_STS_ALARM_MASK |
                              CSL_RTC_STS_ALARM2_MASK)
} CSL_rtcAlarmIntrSts;

/** @brief Enumerates the different Alarm events */
typedef enum
{
    /**
     * @brief   Minimum Alarm Event Number
     */
    CSL_RTC_ALARM_NUM_MIN = 1U,

    /**
     * @brief   Alarm Event number 1
     */
    CSL_RTC_ALARM_NUM_1 = CSL_RTC_ALARM_NUM_MIN,

    /**
     * @brief   Alarm Event number 2
     */
    CSL_RTC_ALARM_NUM_2 = CSL_RTC_ALARM_NUM_1 + 1U,

    /**
     * @brief   Maximum Alarm Event Number
     */
    CSL_RTC_ALARM_NUM_MAX = CSL_RTC_ALARM_NUM_2
} CSL_rtcAlarmNum;

/** @brief Enumerates the different idle modes supported */
typedef enum
{
    /**
     * @brief   Force Idle mode
     */
    CSL_RTC_IDLE_MODE_FORCE_IDLE = 0x0U,

    /**
     * @brief   No idle mode
     */
    CSL_RTC_IDLE_MODE_NO_IDLE    = 0x1U,

    /**
     * @brief   Smart idle mode
     */
    CSL_RTC_IDLE_MODE_SMART_IDLE = 0x2U,

    /**
     * @brief   Smart idle Wakeup mode
     */
    CSL_RTC_IDLE_MODE_SMART_IDLE_WAKEUP = 0x3U
} CSL_rtcIdleMode;

/** @brief Enumerates the different wakeup sources for RTC. */
typedef enum
{
    /**
     * @brief   Minimum Wakeup event source used for validation
     */
    CSL_RTC_WAKEUP_EVT_SRC_MIN = 0U,

    /**
     * @brief   Timer Wakeup event source
     */
    CSL_RTC_WAKEUP_EVT_SRC_TIMER = CSL_RTC_WAKEUP_EVT_SRC_MIN,

    /**
     * @brief   Alarm Wakeup event source
     */
    CSL_RTC_WAKEUP_EVT_SRC_ALARM = CSL_RTC_WAKEUP_EVT_SRC_TIMER + 1U,

    /**
     * @brief   Minimum Wakeup event source used for validation
     */
    CSL_RTC_WAKEUP_EVT_SRC_MAX = CSL_RTC_WAKEUP_EVT_SRC_ALARM
} CSL_rtcWakeupEvtSrc;

/** @brief Enumerates the different external Wakeup event sources which
           can be used to wakeup the RTC module. */
typedef enum
{
    /**
     * @brief   Minimum External Wakeup Source
     */
    CSL_RTC_EXT_WAKEUP_SRC_MIN = 0U,

    /**
     * @brief   External Wakeup Source 0 used to wakeup RTC
     */
    CSL_RTC_EXT_WAKEUP_SRC_0 = CSL_RTC_EXT_WAKEUP_SRC_MIN,

    /**
     * @brief   External Wakeup Source 1 used to wakeup RTC
     */
    CSL_RTC_EXT_WAKEUP_SRC_1 = CSL_RTC_EXT_WAKEUP_SRC_0 + 1U,

    /**
     * @brief   External Wakeup Source 2 used to wakeup RTC
     */
    CSL_RTC_EXT_WAKEUP_SRC_2 = CSL_RTC_EXT_WAKEUP_SRC_1 + 1U,

    /**
     * @brief   External Wakeup Source 3 used to wakeup RTC
     */
    CSL_RTC_EXT_WAKEUP_SRC_3 = CSL_RTC_EXT_WAKEUP_SRC_2 + 1U,

    /**
     * @brief   Maximum External Wakeup Source
     */
    CSL_RTC_EXT_WAKEUP_SRC_MAX = CSL_RTC_EXT_WAKEUP_SRC_3
} CSL_rtcExtWakeupSrc;

/** @brief Enumerates the external event polarity */
typedef enum
{
    /**
     * @brief   RTC WAKEUP EVENT POLARITY ACTIVE HIGH
     */
    CSL_RTC_WAKEUP_EVT_POL_ACTV_HIGH = 0x0U,

    /**
     * @brief   RTC WAKEUP EVENT POLARITY ACTIVE LOW
     */
    CSL_RTC_WAKEUP_EVT_POL_ACTV_LOW = 0x1U
} CSL_rtcWakeupEvtPol;

/** @brief Enumerates the different scratch pad registers. */
typedef enum
{
    /**
     * @brief   Minimum Scratch pad register number
     */
    CSL_RTC_SCRATCH_PAD_MIN = 0U,

    /**
     * @brief   Scratch pad register number 0
     */
    CSL_RTC_SCRATCH_PAD_0 = CSL_RTC_SCRATCH_PAD_MIN,

    /**
     * @brief   Scratch pad register number 1
     */
    CSL_RTC_SCRATCH_PAD_1 = CSL_RTC_SCRATCH_PAD_0 + 1U,

    /**
     * @brief   Scratch pad register number 2
     */
    CSL_RTC_SCRATCH_PAD_2 = CSL_RTC_SCRATCH_PAD_1 + 1U,

    /**
     * @brief   Maximum Scratch pad register number
     */
    CSL_RTC_SCRATCH_PAD_MAX = CSL_RTC_SCRATCH_PAD_2
} CSL_rtcScratchPadReg;

/** @brief Enumerates the Feedback resistor types */
typedef enum
{
    /**
     * @brief   Internal oscillator feedback resistor
     */
    CSL_RTC_FEEDBACK_RESISTOR_INTERNAL = 0x0U,

    /**
     * @brief   External oscillator feedback resistor
     */
    CSL_RTC_FEEDBACK_RESISTOR_EXTERNAL = 0x1U
} CSL_rtcFeedbackResistor;

/** @brief Enumerates the different Time modes. */
typedef enum
{
    /**
     * @brief   Minimum time mode used for input validation
     */
    CSL_RTC_TIME_MODE_MIN = 0U,

    /**
     * @brief   24 Hour Time mode
     */
    CSL_RTC_TIME_MODE_24_HR = CSL_RTC_TIME_MODE_MIN,

    /**
     * @brief   24 Hour Time mode
     */
    CSL_RTC_TIME_MODE_12_HR = CSL_RTC_TIME_MODE_24_HR + 1U,

    /**
     * @brief   Maximum time mode used for input validation
     */
    CSL_RTC_TIME_MODE_MAX = CSL_RTC_TIME_MODE_24_HR
} CSL_rtcTimeMode;

/** @brief Enumerates the different Time Meridiem formats. */
typedef enum
{
    /**
     * @brief   Minimum Time meridiem mode
     */
    CSL_RTC_TIME_MERIDIEM_MIN = 0U,

    /**
     * @brief   AM (Ante-Meridiem) Time Format
     */
    CSL_RTC_TIME_MERIDIEM_AM = CSL_RTC_TIME_MERIDIEM_MIN,

    /**
     * @brief   PM (Post-Meridiem) Time Format
     */
    CSL_RTC_TIME_MERIDIEM_PM = CSL_RTC_TIME_MERIDIEM_AM + 1U,

    /**
     * @brief   Maximum Time meridiem mode
     */
    CSL_RTC_TIME_MERIDIEM_MAX = CSL_RTC_TIME_MERIDIEM_PM
} CSL_rtcTimeMeridiem;

/** @brief enumerates the different day of the week */
typedef enum
{
    /**
     * @brief   Minimum value of the Week Day
     */
    CSL_RTC_WEEK_DAY_MIN = 0U,

    /**
     * @brief   Indicates Sunday
     */
    CSL_RTC_WEEK_DAY_SUNDAY = CSL_RTC_WEEK_DAY_MIN,

    /**
     * @brief   Indicates Monday
     */
    CSL_RTC_WEEK_DAY_MONDAY = CSL_RTC_WEEK_DAY_SUNDAY + 1U,

    /**
     * @brief   Indicates Tuesday
     */
    CSL_RTC_WEEK_DAY_TUESDAY = CSL_RTC_WEEK_DAY_MONDAY + 1U,

    /**
     * @brief   Indicates Wednesday
     */
    CSL_RTC_WEEK_DAY_WEDNESDAY = CSL_RTC_WEEK_DAY_TUESDAY + 1U,

    /**
     * @brief   Indicates Thursday
     */
    CSL_RTC_WEEK_DAY_THURSDAY = CSL_RTC_WEEK_DAY_WEDNESDAY + 1U,

    /**
     * @brief   Indicates Friday
     */
    CSL_RTC_WEEK_DAY_FRIDAY = CSL_RTC_WEEK_DAY_THURSDAY + 1U,

    /**
     * @brief   Indicates Saturday
     */
    CSL_RTC_WEEK_DAY_SATURDAY = CSL_RTC_WEEK_DAY_FRIDAY + 1U,

    /**
     * @brief   Maximum value of the Week Day
     */
    CSL_RTC_WEEK_DAY_MAX = CSL_RTC_WEEK_DAY_SATURDAY
} CSL_rtcWeekDay;

/**
@}
*/

/** @addtogroup CSL_RTC_DATASTRUCT
 @{ */

/** @brief Structure representing the Time information. */
typedef struct
{
    /** Time value in hours. */
    Uint32       hours;
    /** Time value in minutes. */
    Uint32       minutes;
    /** Time value in seconds */
    Uint32       seconds;
    /** Time value in nano seconds */
    Uint32       nanoSec;
    /** Hour Mode which can take any of the two values
        from the enum #CSL_rtcTimeMode to represent either
        12 Hour mode or 24 Hour mode. */
    CSL_rtcTimeMode     timeMode;
    /** Meridiem type to indicate either AM mode or PM mode which
        can take any of the values from the following enum
        #CSL_rtcTimeMeridiem */
    CSL_rtcTimeMeridiem meridiemMode;
} CSL_rtcTimeObj;

/** @brief Structure representing the Date information. */
typedef struct
{
    /** Value to represent the Day. */
    Uint32      day;
    /** Value to represent the Month. */
    Uint32      month;
    /** Value to represent the Year. */
    Uint32      year;
    /** Value to represent the day of the week which can
        can take any of the values from the following enum
        #CSL_rtcWeekDay */
    CSL_rtcWeekDay     weekDay;
} CSL_rtcDateObj;

/**
 * @brief This data type is the handle to the CSL of the RTC
 */
typedef CSL_RtcRegs                      *CSL_rtcHandle;

/**
@}
*/

/**
@addtogroup CSL_RTC_SYMBOL
@{
*/


/**
@}
*/

/** @addtogroup CSL_RTC_FUNCTION
 @{ */

/*******************************************************************************
 * Timer global function declarations
 ******************************************************************************/


/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif  /* CSL_RTC_H_ */
