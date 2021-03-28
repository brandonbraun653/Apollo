/**
 * \file   time_utils.c
 *
 * \brief  This file contains time utility API's implementation. The SoC/IP 
 *         independent code is present in this file and the IP specific code 
 *         is present in IP specific file (eg: dmtimer_util.c).
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "time_utils.h"
#include "timer_util_priv.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* The below array defines the number of days of each month per leap year 
   cycle. */
static uint16_t gDays4Year[4][12] =
{
    {   0U,  31U,  60U,  91U, 121U, 152U, 182U, 213U, 244U, 274U, 305U, 335U},
    { 366U, 397U, 425U, 456U, 486U, 517U, 547U, 578U, 609U, 639U, 670U, 700U},
    { 731U, 762U, 790U, 821U, 851U, 882U, 912U, 943U, 974U,1004U,1035U,1065U},
    {1096U,1127U,1155U,1186U,1216U,1247U,1277U,1308U,1339U,1369U,1400U,1430U},
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t TIMEUtilsInit(timeUtilsObj_t *pFreeRunTimer, timeUtilsObj_t *pTickTimer)
{
    int32_t status = E_FAIL;
    
    /* IP and SoC specific configurations */
    TIMERUtilFreeRunInit(pFreeRunTimer);

    /* TODO: Tick timer - yet to be implemented
       TODO: Initialize the handle for timer objects */

    return status;
}

void TIMESetTimeStamp(uint64_t nanoSec)
{
    TIMERUtilSetTimeStamp(nanoSec);
}

uint64_t TIMEGetTimeStamp(void)
{
    return TIMERUtilGetTimeStamp();
}

timeDate_t TIMEStamp2TimeDate(uint64_t timeStamp)
{
    timeDate_t timeDate;
    uint32_t year;
    uint32_t month;
    
    timeDate.time.nanoSec  = timeStamp % TIME_NANO_SEC; 
    timeStamp /= TIME_NANO_SEC;
    timeDate.time.seconds   = timeStamp % 60U;    
    timeStamp /= 60U;
    timeDate.time.minutes   = timeStamp % 60U;    
    timeStamp /= 60U;
    timeDate.time.hours     = timeStamp % 24U;    
    timeStamp /= 24U;
    timeDate.time.timeMode = TIME_MODE_24_HR;
    
    timeDate.date.year = (timeStamp/(365*4+1))*4;
    timeStamp %= 365U*4U+1U;

    for (year=3U; year>0U; year--)
    {
        if (timeStamp >= gDays4Year[year][0])
            break;
    }

    for (month=11U; month>0U; month--)
    {
        if (timeStamp >= gDays4Year[year][month])
            break;
    }

    timeDate.date.year  += year;
    timeDate.date.month = month+1;
    timeDate.date.day = timeStamp-gDays4Year[year][month]+1;
    timeDate.date.weekDay = 0;
    
    return timeDate;
}

uint64_t TIMEDate2TimeStamp(timeDate_t *pTimeDate)
{
    uint64_t timestamp = 0;
    uint32_t nanoSec = pTimeDate->time.nanoSec; 
    uint32_t sec     = pTimeDate->time.seconds; 
    uint32_t min     = pTimeDate->time.minutes;
    uint32_t hr      = pTimeDate->time.hours;
    uint32_t day     = pTimeDate->date.day-1;
    uint32_t month   = pTimeDate->date.month-1;
    uint32_t year    = pTimeDate->date.year;
    timestamp = (year/4U*(365U*4U+1U)+gDays4Year[year%4U][month]+day);
    timestamp = (((timestamp*24U+hr)*60U+min)*60U+sec)*TIME_NANO_SEC+nanoSec;
               
    return timestamp;
}

int32_t DELAYUsec(uint32_t usec)
{
    uint64_t delayTS = TIMEGetTimeStamp() + ((uint64_t)usec*1000U);
    while(delayTS > TIMEGetTimeStamp());
    
    return S_PASS;
}

int32_t DELAYMsec(uint32_t msec)
{
    uint64_t delayTS = TIMEGetTimeStamp() + ((uint64_t)msec*1000000U);
    while(delayTS > TIMEGetTimeStamp());
    
    return S_PASS;    
}
