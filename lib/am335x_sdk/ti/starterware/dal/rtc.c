/**
 * \file    rtc.c
 *
 * \brief   This file contains driver API implementations for
 *          Real Time Clock(RTC) module.
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
#include "hw_types.h"
#include "rtc.h"
#include "dal_misc.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/**
*  \name RTC KICK register default values.
*
*  Used to enable and disable Write Protection to RTC registers
*
*/

/** @{ */
/** \brief RTC KICK0 register UNLOCK key used to disable Write Protection. */
#define RTC_KICK0_UNLOCK_KEY                            (0x83E70B13U)

/** \brief RTC KICK0 register UNLOCK key used to disable Write Protection. */
#define RTC_KICK1_UNLOCK_KEY                            (0x95A4F1E0U)

/** \brief RTC KICK0 register LOCK key used to enable Write Protection. */
#define RTC_KICK0_LOCK_KEY                              (0xFFFFFFFFU)

/** \brief RTC KICK1 register LOCK key used to enable Write Protection. */
#define RTC_KICK1_LOCK_KEY                              (0xFFFFFFFFU)
/** @} */

/** \brief Macro to wait till the RTC registers are free to access.
           Loops continuously till the RTC is busy updating an event. */
#define RTC_WAIT_FOR_WRITE         while(RTCSS_STS_REG_BUSY_UPDATE_EVT == \
                                    (HW_RD_FIELD32(baseAddr + \
                                     RTCSS_STS_REG, \
                                     RTCSS_STS_REG_BUSY)))

/** \brief Macro to identify the correct Alarm Seconds register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_SECONDS(alarmNum) ((1U == alarmNum) ? \
                               RTCSS_ALARM_SECONDS_REG: RTCSS_ALARM2_SECONDS_REG)

/** \brief Macro to identify the correct Alarm Minutes register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_MINUTES(alarmNum) ((1U == alarmNum) ? \
                               RTCSS_ALARM_MINUTES_REG: RTCSS_ALARM2_MINUTES_REG)

/** \brief Macro to identify the correct Alarm Hours register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_HOURS(alarmNum) ((alarmNum == 1) ? \
                                RTCSS_ALARM_HOURS_REG: RTCSS_ALARM2_HOURS_REG)

/** \brief Macro to identify the correct Alarm Days register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_DAYS(alarmNum) ((alarmNum == 1) ? \
                                RTCSS_ALARM_DAYS_REG: RTCSS_ALARM2_DAYS_REG)

/** \brief Macro to identify the correct Alarm Months register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_MONTHS(alarmNum) ((alarmNum == 1) ? \
                                RTCSS_ALARM_MONTHS_REG: RTCSS_ALARM2_MONTHS_REG)

/** \brief Macro to identify the correct Alarm Years register based on Alarm
           Number passed. */
#define RTCSS_MAKE_ALARM_YEARS(alarmNum) ((alarmNum == 1) ? \
                                RTCSS_ALARM_YEARS_REG: RTCSS_ALARM2_YEARS_REG)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t RTCGetRevision(uint32_t baseAddr)
{
    uint32_t revision = 0U;

    revision = HW_RD_REG32(baseAddr + RTCSS_REVISION);

    return revision;
}

void RTCWriteProtectEnable(uint32_t baseAddr, uint32_t enableWriteProtect)
{
    if(TRUE == enableWriteProtect)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_KICK0R, RTCSS_KICK0R_KICK0,
                        RTC_KICK0_LOCK_KEY);

        HW_WR_FIELD32(baseAddr + RTCSS_KICK1R, RTCSS_KICK1R_KICK1,
                        RTC_KICK1_LOCK_KEY);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_KICK0R, RTCSS_KICK0R_KICK0,
                        RTC_KICK0_UNLOCK_KEY);

        HW_WR_FIELD32(baseAddr + RTCSS_KICK1R, RTCSS_KICK1R_KICK1,
                        RTC_KICK1_UNLOCK_KEY);
    }
}

void RTCClkSrcSelect(uint32_t baseAddr, uint32_t clkSrc)
{
    /* Select the correct Clock Source */
    HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG, RTCSS_OSC_REG_32KCLK_SEL,
                    clkSrc);

    if(RTC_CLK_SRC_INTERNAL == clkSrc)
    {
        /* Disable the XTAL Pins and apply high impedance. */
        HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG, RTCSS_OSC_REG_OSC32K_GZ,
            RTCSS_OSC_REG_OSC32K_GZ_DISABLE);
    }
    else
    {
        /* Enable the XTAL Pins to connect it to the external Clk source. */
        HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG, RTCSS_OSC_REG_OSC32K_GZ,
            RTCSS_OSC_REG_OSC32K_GZ_ENABLE);
    }
}

void RTCEnable(uint32_t baseAddr, uint32_t enableModule)
{
    if(TRUE == enableModule)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG, RTCSS_CTRL_REG_RTC_DISABLE,
                    RTCSS_CTRL_REG_RTC_DISABLE_ENABLE);

        /* Enable the 32kHz clocks */
        HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG, RTCSS_OSC_REG_32KCLK_EN,
                        RTCSS_OSC_REG_32KCLK_EN_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG, RTCSS_CTRL_REG_RTC_DISABLE,
                    RTCSS_CTRL_REG_RTC_DISABLE);

        /* Disable the 32kHz clocks */
        HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG, RTCSS_OSC_REG_32KCLK_EN,
                        RTCSS_OSC_REG_32KCLK_EN_DISABLE);
    }
}

void RTCRun(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG, RTCSS_CTRL_REG_STOP_RTC,
                    RTCSS_CTRL_REG_STOP_RTC_RUNNING);
}

void RTCStop(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG, RTCSS_CTRL_REG_STOP_RTC,
                    RTCSS_CTRL_REG_STOP_RTC_FROZEN);
}

void RTCTimerIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    /* Poll the status register flag until the BUSY  bit equals zero */
    RTC_WAIT_FOR_WRITE;

    /* Enable Periodic Timer interrupts */
    HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG, RTCSS_INTRS_REG_IT_TIMER,
                    RTCSS_INTRS_REG_IT_TIMER_ENABLED);

    /* Set the Timer interrupt period. */
    HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG, RTCSS_INTRS_REG_EVERY,
                    intrMask);
}

void RTCTimerIntrDisable(uint32_t baseAddr)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    RTC_WAIT_FOR_WRITE;

    /* Disable Periodic Timer interrupts */
    HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG, RTCSS_INTRS_REG_IT_TIMER,
                    RTCSS_INTRS_REG_IT_TIMER_DISABLED);
}

uint32_t RTCTimerIntrStatus(uint32_t baseAddr)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + RTCSS_STS_REG);
    regVal = (regVal & (RTCSS_STS_REG_1S_EVT_MASK |
                RTCSS_STS_REG_1M_EVT_MASK | RTCSS_STS_REG_1H_EVT_MASK |
                RTCSS_STS_REG_1D_EVT_MASK));

    return regVal;
}

void RTCAlarmIntrEnable(uint32_t baseAddr, uint32_t alarmNum)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    RTC_WAIT_FOR_WRITE;

    if(RTC_ALARM_NUM_1 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG,
                        RTCSS_INTRS_REG_IT_ALARM,
                        RTCSS_INTRS_REG_IT_ALARM_ENABLED);
    }
    else if(RTC_ALARM_NUM_2 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG,
                        RTCSS_INTRS_REG_IT_ALARM2,
                        RTCSS_INTRS_REG_IT_ALARM2_ENABLED);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

void RTCAlarmIntrDisable(uint32_t baseAddr, uint32_t alarmNum)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    RTC_WAIT_FOR_WRITE;

    if(RTC_ALARM_NUM_1 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG,
                        RTCSS_INTRS_REG_IT_ALARM,
                        RTCSS_INTRS_REG_IT_ALARM_DISABLED);
    }
    else if(RTC_ALARM_NUM_2 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        HW_WR_FIELD32(baseAddr + RTCSS_INTRS_REG,
                        RTCSS_INTRS_REG_IT_ALARM2,
                        RTCSS_INTRS_REG_IT_ALARM2_DISABLED);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

uint32_t RTCAlarmIntrStatus(uint32_t baseAddr)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + RTCSS_STS_REG);
    regVal = (regVal & (RTCSS_STS_REG_ALARM_MASK | RTCSS_STS_REG_ALARM2_MASK));

    return regVal;
}

void RTCAlarmIntrClear(uint32_t baseAddr, uint32_t alarmNum)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + RTCSS_STS_REG);

    if(RTC_ALARM_NUM_1 == alarmNum)
    {
        regVal = (regVal & ~RTCSS_STS_REG_ALARM_MASK);
        regVal |= (0x1U << RTCSS_STS_REG_ALARM_SHIFT);
    }
    else if(RTC_ALARM_NUM_2 == alarmNum)
    {
        regVal = (regVal & ~RTCSS_STS_REG_ALARM2_MASK);
        regVal |= (0x1U << RTCSS_STS_REG_ALARM2_SHIFT);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
    /* Write the updated value back to the register. */
    HW_WR_REG32(baseAddr + RTCSS_STS_REG, regVal);
}

uint32_t RTCIsBusy(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(RTCSS_STS_REG_BUSY_UPDATE_EVT ==
        HW_RD_FIELD32(baseAddr + RTCSS_STS_REG, RTCSS_STS_REG_BUSY))
    {
        status = TRUE;
    }

    return status;
}

void RTCRoundingEnable(uint32_t baseAddr, uint32_t enableRounding)
{
    if(enableRounding == TRUE)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                        RTCSS_CTRL_REG_ROUND_30S,
                        RTCSS_CTRL_REG_ROUND_30S_ROUNDED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                        RTCSS_CTRL_REG_ROUND_30S,
                        RTCSS_CTRL_REG_ROUND_30S_NO_UPDATE);
    }
}

void RTCSetTime(uint32_t baseAddr, timeObj_t *pTime)
{
    uint32_t timeVal = 0U;
    uint32_t regVal = 0U;

    /* Get The BCD equivalent of the seconds value */
    timeVal = MISCDecToBcd(pTime->seconds);

    regVal = HW_RD_REG32(baseAddr + RTCSS_SECONDS_REG);
    /* Clear the Seconds field */
    regVal &= ~(RTCSS_SECONDS_REG_SEC0_MASK |
                    RTCSS_SECONDS_REG_SEC1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /* Write the seconds value */
    HW_WR_REG32(baseAddr + RTCSS_SECONDS_REG, regVal);

    /* Get The BCD equivalent of the minutes value */
    timeVal = MISCDecToBcd(pTime->minutes);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MINUTES_REG);
    /* Clear the Minutes field */
    regVal &= ~(RTCSS_MINUTES_REG_MIN0_MASK |
                    RTCSS_MINUTES_REG_MIN1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /* Write the seconds value */
    HW_WR_REG32(baseAddr + RTCSS_MINUTES_REG, regVal);

    /* Get the Time mode. */
    timeVal = pTime->timeMode;

    HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                    RTCSS_CTRL_REG_MODE_12_24,
                    timeVal);

    /* Get The BCD equivalent of the hours value*/
    timeVal = MISCDecToBcd(pTime->hours);

    /* Get the Hours value. */
    regVal = HW_RD_REG32(baseAddr + RTCSS_HOURS_REG);

    /* Clear the Hours field */
    regVal &= ~(RTCSS_HOURS_REG_HOUR0_MASK |
                    RTCSS_HOURS_REG_HOUR1_MASK);
    regVal |= timeVal;

    if(TIME_MODE_12_HR == pTime->timeMode)
    {
        timeVal = pTime->meridiemMode;

        HW_SET_FIELD(regVal, RTCSS_HOURS_REG_PM_NAM, timeVal);
    }

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /* Write the Hours value. */
    HW_WR_REG32(baseAddr + RTCSS_HOURS_REG, regVal);
}

void RTCGetTime(uint32_t baseAddr, timeObj_t *pTime)
{
    uint32_t timeVal = 0U;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /* Read the Seconds value. */
    timeVal = HW_RD_REG32(baseAddr + RTCSS_SECONDS_REG);
    timeVal &= (RTCSS_SECONDS_REG_SEC0_MASK |
                    RTCSS_SECONDS_REG_SEC1_MASK);
    /* Get the Decimal equivalent of the seconds value in BCD */
    pTime->seconds = MISCBcdToDec(timeVal);

    /* Read the Minutes value. */
    timeVal = HW_RD_REG32(baseAddr + RTCSS_MINUTES_REG);
    timeVal &= (RTCSS_MINUTES_REG_MIN0_MASK |
                    RTCSS_MINUTES_REG_MIN1_MASK);
    /* Get the Decimal equivalent of the minutes value in BCD */
    pTime->minutes = MISCBcdToDec(timeVal);

    /* Read the Time mode */
    timeVal = HW_RD_FIELD32(baseAddr + RTCSS_CTRL_REG,
                               RTCSS_CTRL_REG_MODE_12_24);
    pTime->timeMode = timeVal;

    /* Read the Hours value. */
    timeVal = HW_RD_REG32(baseAddr + RTCSS_HOURS_REG);

    /*
    ** If the Time mode is in 12 hour format get the meridiem mode of the
    ** current time set.
    */
    if(TIME_MODE_12_HR == pTime->timeMode)
    {
        pTime->meridiemMode = HW_GET_FIELD(timeVal, RTCSS_HOURS_REG_PM_NAM);
    }

    timeVal &= (RTCSS_HOURS_REG_HOUR0_MASK |
                    RTCSS_HOURS_REG_HOUR1_MASK);
    /* Get the Decimal equivalent of the hours value in BCD */
    pTime->hours = MISCBcdToDec(timeVal);

}

void RTCSetDate(uint32_t baseAddr, dateObj_t *pDate)
{
    uint32_t dateVal = 0U;
    uint32_t regVal = 0U;

    /* Get The BCD equivalent of the years value*/
    dateVal = MISCDecToBcd(pDate->year);

    regVal = HW_RD_REG32(baseAddr + RTCSS_YEARS_REG);
    /* Clear the years field */
    regVal &= ~(RTCSS_YEARS_REG_YEAR0_MASK |
                    RTCSS_YEARS_REG_YEAR1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Set the years value */
    HW_WR_REG32(baseAddr + RTCSS_YEARS_REG, regVal);

    /* Get the BCD equivalent of the month value. */
    dateVal = MISCDecToBcd(pDate->month);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MONTHS_REG);
    /* Clear the month field */
    regVal &= ~(RTCSS_MONTHS_REG_MONTH0_MASK |
                    RTCSS_MONTHS_REG_MONTH1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Set the month value */
    HW_WR_REG32(baseAddr + RTCSS_MONTHS_REG, regVal);

    /* Get the BCD equivalent of the Day value. */
    dateVal = MISCDecToBcd(pDate->day);

    regVal = HW_RD_REG32(baseAddr + RTCSS_DAYS_REG);
    /* Clear the years field */
    regVal &= ~(RTCSS_DAYS_REG_DAY0_MASK |
                    RTCSS_DAYS_REG_DAY1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Set the Day value */
    HW_WR_REG32(baseAddr + RTCSS_DAYS_REG, regVal);

    /* Get the Day of the Week. */
    dateVal = MISCDecToBcd(pDate->weekDay);

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /* Set the Day of the Week value */
    HW_WR_FIELD32(baseAddr + RTCSS_WEEKS_REG, RTCSS_WEEKS_REG_WEEK,
                        dateVal);
}

void RTCGetDate(uint32_t baseAddr, dateObj_t *pDate)
{
    uint32_t dateVal = 0U;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;

    /*
    ** Doing a dummy read of seconds register which internally
    ** fetches all the Time and Date register into shadow register.
    ** This ensures the same date and time is read when the last second read
    ** register was done.
    */
    HW_RD_REG32(baseAddr + RTCSS_SECONDS_REG);

    /* Read the Year value */
    dateVal = HW_RD_REG32(baseAddr + RTCSS_YEARS_REG);
    dateVal &= (RTCSS_YEARS_REG_YEAR0_MASK |
                    RTCSS_YEARS_REG_YEAR1_MASK);
    /* Get the decimal equivalent of the year value in BCD */
    pDate->year = MISCBcdToDec(dateVal);

    /* Read the Month value */
    dateVal = HW_RD_REG32(baseAddr + RTCSS_MONTHS_REG);
    dateVal &= (RTCSS_MONTHS_REG_MONTH0_MASK |
                    RTCSS_MONTHS_REG_MONTH1_MASK);
    /* Get the decimal equivalent of the month value in BCD */
    pDate->month = MISCBcdToDec(dateVal);

    /* Read the Day value */
    dateVal = HW_RD_REG32(baseAddr + RTCSS_DAYS_REG);
    dateVal &= (RTCSS_DAYS_REG_DAY0_MASK |
                    RTCSS_DAYS_REG_DAY1_MASK);
    /* Get the decimal equivalent of the date value in BCD */
    pDate->day = MISCBcdToDec(dateVal);

    /* Read the Days of the Week Value. */
    dateVal = HW_RD_FIELD32(baseAddr + RTCSS_WEEKS_REG,
                RTCSS_WEEKS_REG_WEEK);
    /* Get the decimal equivalent of the date value in BCD */
    pDate->weekDay = MISCBcdToDec(dateVal);

}

void RTCSetAlarm(uint32_t baseAddr,
                 uint32_t alarmNum,
                 timeObj_t *pAlarmTime,
                 dateObj_t *pAlarmDate)
{
    uint32_t timeVal = 0U;
    uint32_t regVal = 0U;

    /* Get the BCD equivalent of the seconds value. */
    timeVal = MISCDecToBcd(pAlarmTime->seconds);
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_SECONDS(alarmNum));
    /* Clear the Seconds field */
    regVal &= ~(RTCSS_ALARM_SECONDS_REG_ALARMSEC0_MASK |
                    RTCSS_ALARM_SECONDS_REG_ALARMSEC1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the seconds value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_SECONDS(alarmNum), regVal);

    /* Get BCD equivalent of the minutes value. */
    timeVal = MISCDecToBcd(pAlarmTime->minutes);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_MINUTES(alarmNum));
    /* Clear the Seconds field */
    regVal &= ~(RTCSS_ALARM_MINUTES_REG_MIN0_MASK |
                    RTCSS_ALARM_MINUTES_REG_MIN1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the seconds value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_MINUTES(alarmNum), regVal);

    /* Get the Time mode format. */
    timeVal = pAlarmTime->timeMode;

    HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                    RTCSS_CTRL_REG_MODE_12_24,
                    timeVal);

    /* Get the BCD equivalent of the Hours Value */
    timeVal = MISCDecToBcd(pAlarmTime->hours);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_HOURS(alarmNum));
    /* Clear the Hours field */
    regVal &= ~(RTCSS_ALARM_HOURS_REG_HOUR0_MASK |
                    RTCSS_ALARM_HOURS_REG_HOUR1_MASK);
    regVal |= timeVal;

    if(TIME_MODE_12_HR == pAlarmTime->timeMode)
    {
        timeVal = pAlarmTime->meridiemMode;

        HW_SET_FIELD(regVal, RTCSS_ALARM_HOURS_REG_PM_NAM, timeVal);
    }

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the hours value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_HOURS(alarmNum), regVal);

    /* Get the BCD equivalent of the year value. */
    timeVal = MISCDecToBcd(pAlarmDate->year);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_YEARS(alarmNum));
    /* Clear the year field */
    regVal &= ~(RTCSS_ALARM_YEARS_REG_YEAR0_MASK |
                    RTCSS_ALARM_YEARS_REG_YEAR1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the year value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_YEARS(alarmNum), regVal);

    /* Get the BCD equivalent of the month value. */
    timeVal = MISCDecToBcd(pAlarmDate->month);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_MONTHS(alarmNum));
    /* Clear the months field */
    regVal &= ~(RTCSS_ALARM_MONTHS_REG_MONTH0_MASK |
                    RTCSS_ALARM_MONTHS_REG_MONTH1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the months value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_MONTHS(alarmNum), regVal);

    /* Get the BCD equivalent of the day value. */
    timeVal = MISCDecToBcd(pAlarmDate->day);

    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_DAYS(alarmNum));
    /* Clear the day field */
    regVal &= ~(RTCSS_ALARM_DAYS_REG_DAY0_MASK |
                    RTCSS_ALARM_DAYS_REG_DAY1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    RTC_WAIT_FOR_WRITE;
    /* Write the day value */
    HW_WR_REG32(baseAddr + RTCSS_MAKE_ALARM_DAYS(alarmNum), regVal);
}

void RTCGetAlarm(uint32_t baseAddr,
                 uint32_t alarmNum,
                 timeObj_t *pAlarmTime,
                 dateObj_t *pAlarmDate)
{
    uint32_t regVal = 0U;

    /* Read the Seconds value. */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_SECONDS(alarmNum));
    regVal &= (RTCSS_ALARM_SECONDS_REG_ALARMSEC0_MASK |
                    RTCSS_ALARM_SECONDS_REG_ALARMSEC1_MASK);
    /* Get the decimal equivalent of the seconds value in BCD */
    pAlarmTime->seconds = MISCBcdToDec(regVal);

    /* Read the minutes value. */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_MINUTES(alarmNum));
    regVal &= (RTCSS_ALARM_MINUTES_REG_MIN0_MASK |
                    RTCSS_ALARM_MINUTES_REG_MIN1_MASK);
    /* Get the decimal equivalent of the minutes value in BCD */
    pAlarmTime->minutes = MISCBcdToDec(regVal);

    /* Read the Hours value. */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_HOURS(alarmNum));
    regVal &= (RTCSS_ALARM_HOURS_REG_HOUR0_MASK |
                    RTCSS_ALARM_HOURS_REG_HOUR1_MASK);
    /* Get the decimal equivalent of the hours value in BCD */
    pAlarmTime->hours = MISCBcdToDec(regVal);

    regVal = HW_RD_FIELD32(baseAddr + RTCSS_CTRL_REG,
                               RTCSS_CTRL_REG_MODE_12_24);
    pAlarmTime->timeMode = regVal;

    /*
    ** If the Time mode is in 12 hour format get the meridiem mode of the
    ** current time set.
    */
    if(TIME_MODE_12_HR == pAlarmTime->timeMode)
    {
        pAlarmTime->meridiemMode = HW_GET_FIELD(regVal,
            RTCSS_ALARM_HOURS_REG_PM_NAM);
    }

    /* Read the Year value */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_YEARS(alarmNum));
    regVal &= (RTCSS_ALARM_YEARS_REG_YEAR0_MASK |
                    RTCSS_ALARM_YEARS_REG_YEAR1_MASK);

    /* Get the Decimal equivalent of the year value */
    pAlarmDate->year = MISCBcdToDec(regVal);

    /* Read the Month value */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_MONTHS(alarmNum));
    regVal &= (RTCSS_ALARM_MONTHS_REG_MONTH0_MASK |
                    RTCSS_ALARM_MONTHS_REG_MONTH1_MASK);
    /* Get the decimal equivalent of the month value */
    pAlarmDate->month = MISCBcdToDec(regVal);

     /* Read the Day value */
    regVal = HW_RD_REG32(baseAddr + RTCSS_MAKE_ALARM_DAYS(alarmNum));
    regVal &= (RTCSS_ALARM_DAYS_REG_DAY0_MASK |
                    RTCSS_ALARM_DAYS_REG_DAY1_MASK);
    /* Get the decimal equivalent of the day value */
    pAlarmDate->day = MISCBcdToDec(regVal);
}

void RTCSetScratchPadVal(uint32_t baseAddr,
                         uint32_t regNum,
                         uint32_t scratchVal)
{
    uint32_t offset = regNum * 4U;

    HW_WR_REG32(baseAddr + RTCSS_SCRATCH0_REG + offset, scratchVal);
}

uint32_t RTCGetScratchPadVal(uint32_t baseAddr, uint32_t regNum)
{
    uint32_t offset = 0U;
    uint32_t scratchVal = 0U;

    offset = regNum * 4U;
    scratchVal = HW_RD_REG32(baseAddr + RTCSS_SCRATCH0_REG + offset);

    return scratchVal;
}

void RTCSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    /* Set the Idle mode in the SYS Config register */
    HW_WR_FIELD32(baseAddr + RTCSS_SYSCONFIG,
                    RTCSS_SYSCONFIG_IDLEMODE, idleMode);
}

void RTCWakeupEnable(uint32_t baseAddr, uint32_t wakeupSrc)
{
    if(RTC_WAKEUP_EVT_SRC_TIMER == wakeupSrc)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_IRQWAKEEN,
                    RTCSS_IRQWAKEEN_TIMER_WAKEEN,
                    RTCSS_IRQWAKEEN_TIMER_WAKEEN_ENABLED);
    }
    else if(RTC_WAKEUP_EVT_SRC_ALARM == wakeupSrc)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_IRQWAKEEN,
                    RTCSS_IRQWAKEEN_ALARM_WAKEEN,
                    RTCSS_IRQWAKEEN_ALARM_WAKEEN_ENABLED);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

void RTCWakeupDisable(uint32_t baseAddr, uint32_t wakeupSrc)
{
    if(RTC_WAKEUP_EVT_SRC_TIMER == wakeupSrc)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_IRQWAKEEN,
                    RTCSS_IRQWAKEEN_TIMER_WAKEEN,
                    RTCSS_IRQWAKEEN_TIMER_WAKEEN_DISABLED);
    }
    else if(RTC_WAKEUP_EVT_SRC_ALARM == wakeupSrc)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_IRQWAKEEN,
                    RTCSS_IRQWAKEEN_ALARM_WAKEEN,
                    RTCSS_IRQWAKEEN_ALARM_WAKEEN_DISABLED);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

void RTCPmicPowerEnable(uint32_t baseAddr, uint32_t enablePmicPower)
{
    if(TRUE == enablePmicPower)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_PMIC,
                    RTCSS_PMIC_PWR_EN,
                    RTCSS_PMIC_PWR_EN_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_PMIC,
                    RTCSS_PMIC_PWR_EN,
                    RTCSS_PMIC_PWR_EN_DISABLE);
    }
}

void RTCPmicExtWakeupEnable(uint32_t baseAddr, uint32_t extWakeupSrc)
{
    uint32_t regVal = 0U;

    /* Enable external wakeup inputs */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal |= (RTCSS_PMIC_EXT_WAKEUP_EN_ENABLED << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_EN_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCPmicExtWakeupDisable(uint32_t baseAddr, uint32_t extWakeupSrc)
{
    uint32_t regVal = 0U;

    /* Disable external wakeup inputs */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal &= ~(RTCSS_PMIC_EXT_WAKEUP_EN_ENABLED << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_EN_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCPmicExtWakeupPol(uint32_t baseAddr,
                         uint32_t extWakeupSrc,
                         uint32_t wakeupEvtPol)
{
    uint32_t regVal = 0U;

    /* Configure the polarity of external wakeup inputs */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal &= ~(RTCSS_PMIC_EXT_WAKEUP_POL_ACTIVE_LOW << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_POL_SHIFT));
    regVal |= (wakeupEvtPol << (extWakeupSrc + RTCSS_PMIC_EXT_WAKEUP_POL_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCPmicExtWakeupClear(uint32_t baseAddr, uint32_t extWakeupSrc)
{
    uint32_t regVal = 0U;

    /* Clears the external wakeup pin status */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal |= (RTCSS_PMIC_EXT_WAKEUP_STS_OCCURED << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_STS_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCFeedbackResistorSel(uint32_t baseAddr, uint32_t resistorSel)
{
    /* Select the Feedback resistor type to either external or internal */
    HW_WR_FIELD32(baseAddr + RTCSS_OSC_REG,
                    RTCSS_OSC_REG_RES_SELECT, resistorSel);
}

void RTCPmicExtWakeupDebounceEnable(uint32_t baseAddr, uint32_t extWakeupSrc)
{
    uint32_t regVal = 0U;

    /* Enable external wakeup inputs */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal |= (RTCSS_PMIC_EXT_WAKEUP_DB_EN_ENABLE << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_DB_EN_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCPmicExtWakeupDebounceDisable(uint32_t baseAddr, uint32_t extWakeupSrc)
{
    uint32_t regVal = 0U;

    /* Disable external wakeup inputs */
    regVal = HW_RD_REG32(baseAddr + RTCSS_PMIC);
    regVal &= ~(RTCSS_PMIC_EXT_WAKEUP_DB_EN_DISABLE << (extWakeupSrc +
        RTCSS_PMIC_EXT_WAKEUP_DB_EN_SHIFT));
    HW_WR_REG32(baseAddr + RTCSS_PMIC, regVal);
}

void RTCSetDebounceTime(uint32_t baseAddr, uint32_t debounceTime)
{
    /* Set the Debounce Time */
    HW_WR_FIELD32(baseAddr + RTCSS_DEBOUNCE, RTCSS_DEBOUNCE_REG,
                    debounceTime);
}

void RTCTestModeEnable(uint32_t baseAddr, uint32_t enableTestMode)
{
    if(TRUE == enableTestMode)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                        RTCSS_CTRL_REG_TEST_MODE,
                        RTCSS_CTRL_REG_TEST_MODE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                        RTCSS_CTRL_REG_TEST_MODE,
                        RTCSS_CTRL_REG_TEST_MODE_FUNC);
    }
}

void RTCCompensationEnable(uint32_t baseAddr, uint32_t enableCompensation)
{
    if(TRUE == enableCompensation)
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                         RTCSS_CTRL_REG_AUTO_COMP,
                         RTCSS_CTRL_REG_AUTO_COMP_ENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + RTCSS_CTRL_REG,
                         RTCSS_CTRL_REG_AUTO_COMP,
                         RTCSS_CTRL_REG_AUTO_COMP_DISABLED);
    }
}

void RTCSetCompensationVal(uint32_t baseAddr, int32_t compVal)
{
    uint32_t lsbVal = 0U;
    uint32_t msbVal = 0U;

    /* Get the 2's complement Value of the compensation value. */
    compVal = ~compVal + 1;

    lsbVal = (compVal & RTCSS_COMP_LSB_REG_RTC_MASK);
    msbVal = ((compVal >> RTCSS_COMP_MSB_REG_RTC_SHIFT) &
                 RTCSS_COMP_MSB_REG_RTC_MASK);

    /* Poll the status register flag until the BUSY bit equals zero */
    RTC_WAIT_FOR_WRITE;

    /* Set the compensation value to account for oscillator drift. */
    HW_WR_REG32(baseAddr + RTCSS_COMP_LSB_REG, lsbVal);
    HW_WR_REG32(baseAddr + RTCSS_COMP_MSB_REG, msbVal);
}

int32_t RTCGetCompensationVal(uint32_t baseAddr)
{
    uint32_t lsbVal = 0U;
    uint32_t msbVal = 0U;
    int32_t compVal = 0U;

    lsbVal = HW_RD_REG32(baseAddr + RTCSS_COMP_LSB_REG);
    msbVal = HW_RD_REG32(baseAddr + RTCSS_COMP_LSB_REG);

    msbVal = ((msbVal << RTCSS_COMP_MSB_REG_RTC_SHIFT) &
                RTCSS_COMP_MSB_REG_RTC_MASK);
    compVal = (msbVal | lsbVal);

    compVal = ~compVal + 1;

    return compVal;
}

/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */

uint32_t RTCEnableStatus(uint32_t baseAddr)
{
    uint32_t regVal = 0U;
    uint32_t status = RTC_DISABLED;

    regVal = HW_RD_FIELD32(baseAddr + RTCSS_CTRL_REG,
                RTCSS_CTRL_REG_RTC_DISABLE);

    if(RTCSS_CTRL_REG_RTC_DISABLE_ENABLE == regVal)
    {
        status = RTC_ENABELD;
    }

    return status;
}

uint32_t RTCRunStatusGet(uint32_t baseAddr)
{
    uint32_t status = RTC_STATUS_FROZEN;

    if(RTCSS_CTRL_REG_STOP_RTC_RUNNING ==
         HW_RD_FIELD32(baseAddr + RTCSS_CTRL_REG, RTCSS_CTRL_REG_STOP_RTC))
    {
        status = RTC_STATUS_RUNNING;
    }

    return status;
}
