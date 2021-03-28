/**
 * \file   rtc_only_app_main.c
 *
 * \brief   This is an Example application to demonstrate the RTC-Only mode
 *          of Power Management mechanism.
 *
 *         Application Use-case:
 *         1. Demonstrating the Sleep and Wakeup sequence in RTC Only mode.
 *         2. Wakeup Sequence is demonstrated using both Alarm and external wakeup.
 *
 *         Running the example:
 *         1. Load the example application on the target and run.
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
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "mmu.h"
#include "example_utils_mmu.h"
#include "console_utils.h"

/* Application header files */
#include "rtc_app.h"
#include "clock_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Dummy Value to be written to the Scratch Register */
#define RTC_APP_SCRTACHPAD_VAL                         (0xAABBU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the soc info - base address of RTC module.
 *
 * \param   pRtcObj     Pointer to the RTC object.
 *
 * \retval  S_PASS   SOC info is successfully retrieved.
 * \retval  E_FAIL   SOC info retrieval is failed. Resource is not present.
 */
static uint32_t RtcAppGetSocInfo(rtcAppRtcObj_t *pRtcObj);

/**
 * \brief   This API sets the default configuration for entire RTC module.
 *
 * \param   pRtc      Pointer to the RTC object.
 * \param   pClock    Pointer to Clock use case data structure.
 */
static void RtcAppUpdateCfgParams(rtcAppRtcObj_t *pRtc,
                                   rtcAppClockCfg_t *pClock);

/**
 * \brief   This API sets the default configuration for entire RTC module.
 *
 * \param   pRtcObj     Pointer to the RTC module object to display the
 *                      Current date and time.
 */
static void RtcAppDisplayDateTime(rtcAppRtcObj_t *pRtcObj);

/**
 * \brief   This API gets Clock information like Time and Date information.
 *
 * \param   pRtcClockObj    Pointer to clock Obj
 */
static void RtcAppGetClockInput(rtcAppClockCfg_t *pRtcClockObj);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief variable holding the names of Days of the week. */
static char *gClockAppDayOfWeek[] =
            {"Sunday",
             "Monday",
             "Tuesday",
             "Wednesday",
             "Thursday",
             "Friday",
             "Saturday",
             };

/** \brief Variable for displaying AM/PM mode. */
static char *gClockAppMeridiemMode[] =
            {"AM",
             "PM",
            };

static const rtcAppClockCfg_t RTCAPP_CLOCK_DEFAULT =
{
    {
        10U,                /* hours */
        23U,                /* minutes */
        05U,                /* seconds */
        TIME_MODE_24_HR,    /* timeMode */
        TIME_MERIDIEM_AM,   /* timeFormat */
    },  /* timeVal */
    {
        15U,                  /* year */
        02U,                  /* month */
        15U,                  /* day */
        03U,                  /* weekDay */
    },  /* dateVal */
};  /* rtcAppClockCfg_t */

/** \brief Global object for the RTC Clock use case data structure.  */
static rtcAppClockCfg_t gClockCfg;

/** \brief Global object for the RTC IP configuration data structure.  */
static rtcAppRtcObj_t gRtcCfg;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int main()
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    status = BOARDInit(NULL);

    /* Initialize the Clock use case object with default values. */
    gClockCfg = RTCAPP_CLOCK_DEFAULT;

    /* Initialize the global IP configuration with default configuration. */
    gRtcCfg = RTCAPPRTCOBJ_DEFAULT;

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare RTC-Only Mode Application!!\n");

    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get SoC info */
    status = RtcAppGetSocInfo(&gRtcCfg);

    if(S_PASS == status)
    {
        if(RTC_APP_SCRTACHPAD_VAL == RTCScratchPadGet(gRtcCfg.baseAddr,
            RTC_SCRATCH_PAD_REG_0))
        {
            CONSOLEUtilsPrintf("\n********************************************\n");
            CONSOLEUtilsPrintf("******* Resuming from RTC-only mode! *******\n");
            CONSOLEUtilsPrintf("********************************************\r\n");
            CONSOLEUtilsPrintf("The Current Time is:");
            /* Display the Time */
            RTCGetTime(gRtcCfg.baseAddr, &gRtcCfg.timeVal);
            RTCGetDate(gRtcCfg.baseAddr, &gRtcCfg.dateVal);
            RtcAppDisplayDateTime(&gRtcCfg);
            CONSOLEUtilsPrintf("\nResetting the RTC Scratch Register\r\n");
            RTCScratchPadSet(gRtcCfg.baseAddr, RTC_SCRATCH_PAD_REG_0, 0U);
        }

        /* RTC module initialization */
        status = RTCAppInit(&gRtcCfg);

        if(S_PASS == status)
        {
            /* Get the Time and Date information to be set from the User*/
            RtcAppGetClockInput(&gClockCfg);

            /*
            ** Update the IP configuration parameters of RTC with date and time
            ** information.
            */
            RtcAppUpdateCfgParams(&gRtcCfg, &gClockCfg);

            /*
            ** Configure the Time, Wake Source and Triggers to demonstrate
            ** RTC-Only mode.
            */
            RTCAppRTCOnlyConfig(&gRtcCfg);

            /* Enable the RTC Only mode. */
            RTCAppRTCOnlyEnable(&gRtcCfg);

            /* Set a Dummy value to Scratch Pad register to test the
            ** Sleep/Wakeup Sequence.
            */
            RTCScratchPadSet(gRtcCfg.baseAddr, RTC_SCRATCH_PAD_REG_0,
                RTC_APP_SCRTACHPAD_VAL);

            CONSOLEUtilsPrintf("\n******************************************\n");
            CONSOLEUtilsPrintf("Device will Enter RTC-only mode in 10 seconds");
            CONSOLEUtilsPrintf("\r\nThe System will resume after 20 Seconds or");
            CONSOLEUtilsPrintf("\r\nPress the Power Reset Pin for wakeup\r\n");
            CONSOLEUtilsPrintf("******************************************\n");
        }
        else
        {
            CONSOLEUtilsPrintf("FAILURE!! Module Initialization failed\r\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf(
                "FAILURE!! RTC module not present on the device.\r\n", status);
    }

    while(1);

    return (S_PASS);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t RtcAppGetSocInfo(rtcAppRtcObj_t *pRtcObj)
{
    uint32_t status = S_PASS;

    /* Get the base address of the Module */
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_RTCSS, 0U))
    {
        pRtcObj->baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_RTCSS, 0U);

         /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pRtcObj->rtcAppIntrCfgObj.timerIntrNum = 107U;
            pRtcObj->rtcAppIntrCfgObj.alarmIntrNum = 108U;
        }
        else
        {
            pRtcObj->rtcAppIntrCfgObj.timerIntrNum = 75U;
            pRtcObj->rtcAppIntrCfgObj.alarmIntrNum = 76U;
        }
    }
    else
    {
       status = E_FAIL;
    }

    return status;
}

static void RtcAppGetClockInput(rtcAppClockCfg_t *pRtcClockObj)
{
    CONSOLEUtilsPrintf("\r\nPlease enter the Date and Time information..\r\n");

    CONSOLEUtilsPrintf("The Time is to be entered in the following format"
                        " HH MM SS \r\n"
                        "Ex:10 23 51 \r\n");
    CONSOLEUtilsScanf("%u%u%u",&pRtcClockObj->timeVal.hours,
                        &pRtcClockObj->timeVal.minutes,
                        &pRtcClockObj->timeVal.seconds);

    CONSOLEUtilsPrintf("Please Enter the Hour mode\r\n"
                        "1: For 24 Hour Mode\r\n"
                        "2: For 12 Hour Mode\r\n");
    CONSOLEUtilsScanf("%u",&pRtcClockObj->timeVal.timeMode);

    if(TIME_MODE_12_HR == (pRtcClockObj->timeVal.timeMode - 1U))
    {
        CONSOLEUtilsPrintf("Please Enter the Meridiem mode\r\n"
                            "1: For AM Mode\r\n"
                            "2: For PM Mode\r\n");
        CONSOLEUtilsScanf("%u",&pRtcClockObj->timeVal.meridiemMode);
    }

    CONSOLEUtilsPrintf("Please Enter the Date in the following format\r\n"
                        "DD MM YY and Day of the Week\r\n"
                        "Ex: 12 04 99 01 (01 for Sunday, 07 for Saturday)\r\n");
    CONSOLEUtilsScanf("%u%u%u%u",&pRtcClockObj->dateVal.day,
                        &pRtcClockObj->dateVal.month,
                        &pRtcClockObj->dateVal.year,
                        &pRtcClockObj->dateVal.weekDay);
}

static void RtcAppUpdateCfgParams(rtcAppRtcObj_t *pRtc,
                                   rtcAppClockCfg_t *pClock)
{
    /* Update the RTC configuration parameters including date and time. */
    pRtc->timeVal.hours = pClock->timeVal.hours;
    pRtc->timeVal.minutes = pClock->timeVal.minutes;
    pRtc->timeVal.seconds = pClock->timeVal.seconds;
    /*
    ** Time and Meridiem Mode value should be one less than the user entered
    ** value.
    */
    pRtc->timeVal.timeMode = pClock->timeVal.timeMode - 1U;
    pRtc->timeVal.meridiemMode = pClock->timeVal.meridiemMode - 1U;
    pRtc->dateVal.day = pClock->dateVal.day;
    pRtc->dateVal.month = pClock->dateVal.month;
    pRtc->dateVal.year = pClock->dateVal.year;
    pRtc->dateVal.weekDay = pClock->dateVal.weekDay;

    /* Update the information to set the alarm. */
    pRtc->alarmTime.hours = pClock->timeVal.hours;
    pRtc->alarmTime.minutes = pClock->timeVal.minutes;
    pRtc->alarmTime.seconds = pClock->timeVal.seconds;

    /*
    ** Time and Meridiem Mode value should be one less than the user entered
    ** value.
    */
    pRtc->alarmTime.timeMode = pClock->timeVal.timeMode - 1U;
    pRtc->alarmTime.meridiemMode = pClock->timeVal.meridiemMode - 1U;
    pRtc->alarmDate.day = pClock->dateVal.day;
    pRtc->alarmDate.month = pClock->dateVal.month;
    pRtc->alarmDate.year = pClock->dateVal.year;
    pRtc->alarmDate.weekDay = pClock->dateVal.weekDay;
}

void RtcAppDisplayDateTime(rtcAppRtcObj_t *pRtcObj)
{
    /* Display the Current Time. */
    CONSOLEUtilsPrintf("%u:%u:%u ", pRtcObj->timeVal.hours,
                                   pRtcObj->timeVal.minutes,
                                   pRtcObj->timeVal.seconds);

    /* If AM/PM meridiem mode is selected display the appropriate mode. */
    if(TIME_MODE_12_HR == pRtcObj->timeVal.timeMode)
    {
        CONSOLEUtilsPrintf("%s",
            gClockAppMeridiemMode[pRtcObj->timeVal.meridiemMode]);
    }

    /* Display the Date information. */
    CONSOLEUtilsPrintf(" %u:%u:%u ",pRtcObj->dateVal.day,
                                   pRtcObj->dateVal.month,
                                   pRtcObj->dateVal.year);

    /* Display the day of the week. */
    CONSOLEUtilsPrintf("%s ", gClockAppDayOfWeek[pRtcObj->dateVal.weekDay - 1]);

    CONSOLEUtilsPrintf("\r");
}
