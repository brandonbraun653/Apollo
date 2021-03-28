/**
 *  \file     date_time.h
 *
 *  \brief    This file contains declarations of structures and enums
 *            which represent Time and Date information.
 */

/**
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

#ifndef DATE_TIME_H_
#define DATE_TIME_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None. */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Enumerates the different Time modes. */
typedef enum timeMode
{
    TIME_MODE_MIN = 0U,
    /**< Minimum time mode used for input validation. */
    TIME_MODE_24_HR = TIME_MODE_MIN,
    /**< 12 Hour Time mode */
    TIME_MODE_12_HR,
    /**< 24 Hour Time mode */
    TIME_MODE_MAX = TIME_MODE_24_HR
    /**< Maximum time mode used for input validation. */
}timeMode_t;

/** \brief Enumerates the different Time Meridiem formats. */
typedef enum timeMeridiem
{
    TIME_MERIDIEM_MIN = 0U,
    /**< Minimum Time meridiem mode. */
    TIME_MERIDIEM_AM = TIME_MERIDIEM_MIN,
    /**< AM (Ante-Meridiem) Time Format */
    TIME_MERIDIEM_PM,
    /**< PM (Post-Meridiem) Time Format */
    TIME_MERIDIEM_MAX = TIME_MERIDIEM_PM
}timeMeridiem_t;

/** \brief enumerates the different day of the week */
typedef enum weekDay
{
    WEEK_DAY_MIN = 0U,
    /**< Minimum value of the Week Day */
    WEEK_DAY_SUNDAY = WEEK_DAY_MIN,
    /**< Indicates Sunday */
    WEEK_DAY_MONDAY,
    /**< Indicates Monday */
    WEEK_DAY_TUESDAY,
    /**< Indicates Tuesday */
    WEEK_DAY_WEDNESDAY,
    /**< Indicates Wednesday */
    WEEK_DAY_THURSDAY,
    /**< Indicates Thursday */
    WEEK_DAY_FRIDAY,
    /**< Indicates Friday */
    WEEK_DAY_SATURDAY,
    /**< Indicates Saturday */
    WEEK_DAY_MAX = WEEK_DAY_SATURDAY
    /**< Maximum value of the Week Day */
}weekDay_t;

/** \brief Structure representing the Time information. */
typedef struct timeObj
{
    uint32_t       hours;
    /**< Time value in hours. */
    uint32_t       minutes;
    /**< Time value in minutes. */
    uint32_t       seconds;
    /**< Time value in seconds */
    uint32_t       nanoSec;
    /**< Time value in nano seconds */    
    timeMode_t     timeMode;
    /**< Hour Mode which can take any of the two values
         from the enum #timeMode_t to represent either
         12 Hour mode or 24 Hour mode. */
    timeMeridiem_t meridiemMode;
    /**< Meridiem type to indicate either AM mode or PM mode which
         can take any of the values from the following enum
         #timeMeridiem_t */
}timeObj_t;

/** \brief Structure representing the Date information. */
typedef struct dateObj
{
    uint32_t      day;
    /**< Value to represent the Day. */
    uint32_t      month;
    /**< Value to represent the Month. */
    uint32_t      year;
    /**< Value to represent the Year. */
    weekDay_t     weekDay;
    /**< Value to represent the day of the week which can
         can take any of the values from the following enum
         #weekDay_t */
}dateObj_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DATE_TIME_H_ */
