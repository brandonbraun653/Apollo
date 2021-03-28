/**
 * \file   rtc_app_main.c
 *
 * \brief  Example application main source file, which configures the RTC IP
 *         and executes the RTC timer use case.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *            http://www.ti.com/
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
#include <stdio.h>
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_rtc.h>
#include <ti/csl/csl_rtcAux.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGic.h>
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/soc/am572x/src/csl_a15_osal.h>
#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* Application header files */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define RTC_log                UART_printf
#else
#define RTC_log                printf
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * @brief RTC module interface Structure.
 */
typedef struct
{
    /** Pointer to the register overlay structure of the RTC */
    CSL_rtcHandle  regs;

    /**
     * Timer callback function.
     */
    void (*timerCallback)(void* pUserParam, CSL_rtcTimerIntrSts tmrSts);
} RTCObj;

/**
 * @brief This data type is used to return the handle to the CSL of the WDT
 * @brief This data type is the handle to the CSL of the RTC
 */
typedef RTCObj                                *RTCHandle;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

RTCObj oRtc;

RTCHandle hRtc;

CSL_rtcClkSrc clkSrc = CSL_RTC_CLK_SRC_EXTERNAL;

CSL_rtcTimeObj  time1Val =
    {
        10U,                        /* hours */
        23U,                        /* minutes */
        51U,                        /* seconds */
        CSL_RTC_TIME_MODE_24_HR,    /* timeMode */
        CSL_RTC_TIME_MERIDIEM_AM,   /* timeFormat */
    };
CSL_rtcDateObj  date1Val =
    {
        99U,                  /* year */
        04U,                  /* month */
        12U,                  /* day */
        01U,                  /* weekDay */
    };

CSL_rtcTimeObj  timeVal =
    {
        10U,                        /* hours */
        23U,                        /* minutes */
        51U,                        /* seconds */
        CSL_RTC_TIME_MODE_24_HR,    /* timeMode */
        CSL_RTC_TIME_MERIDIEM_AM,   /* timeFormat */
    };
CSL_rtcDateObj  dateVal =
    {
        99U,                  /* year */
        04U,                  /* month */
        12U,                  /* day */
        01U,                  /* weekDay */
    };
Uint32 timerEvt = 0;

static char *dayOfWeek[] =
            {"Sunday",
             "Monday",
             "Tuesday",
             "Wednesday",
             "Thursday",
             "Friday",
             "Saturday",
             };

static char *meridiemMode[] =
            {"AM",
             "PM",
            };

CSL_ArmGicIntrParams_t gRtcIntrParams;

#if 1
void RtcTimerIsr(void *pUserParam);
#else
static void RtcTimerIsr(uintptr_t pUserParam);
#endif

void RtcDisplayDateTime(void);

void RtcTimerCallback(void* pUserParam, CSL_rtcTimerIntrSts tmrSts);

void RtcBoardInit(void);

void RtcTimerIntrInit(void);

extern CSL_ArmGicDistIntrf distrIntrf;

extern CSL_ArmGicCpuIntrf gCpuIntrf;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

Int32 main()
{
    Uint32 status = 0U;
    Board_initCfg boardCfg;

    /* Call board init functions */
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    hRtc = &oRtc;
    hRtc->regs = (CSL_rtcHandle) CSL_MPU_RTC_SS_REGS;
    hRtc->timerCallback = &RtcTimerCallback;

    RtcBoardInit();

    RtcTimerIntrInit();

    /* Disable Write Protection for RTC registers. */
    CSL_rtcWriteProtectEnable(hRtc->regs, FALSE);

    /* Selecting Clock source to drive the RTC. */
    CSL_rtcClkSrcSelect(hRtc->regs, clkSrc);

    /* Enable the RTC module */
    CSL_rtcEnable(hRtc->regs, TRUE);

    /* Get the current date and time information. */
    CSL_rtcGetTime(hRtc->regs, &time1Val);

    CSL_rtcGetDate(hRtc->regs, &date1Val);

    while(timeVal.hours != time1Val.hours)
    {
        /* Set the Time in the RTC clock */
        CSL_rtcSetTime(hRtc->regs, &timeVal);

        /* Set the Date in the RTC clock */
        CSL_rtcSetDate(hRtc->regs, &dateVal);

        /* Get the current date and time information. */
        CSL_rtcGetTime(hRtc->regs, &time1Val);

        CSL_rtcGetDate(hRtc->regs, &date1Val);
    }

    /* Start the RTC Clock */
    CSL_rtcRun(hRtc->regs);

    RTC_log("\r\nCurrent Date and Time:\r\n");

    /*
    ** Enable the clock to run with periodic interrupt of every second.
    */

    /* Enable One second Periodic Interrupts. */
    CSL_rtcTimerIntrEnable(hRtc->regs, CSL_RTC_TIMER_INTR_MASK_EVERY_SEC);

    while(1)
    {
        /* Check for the occurrence of a per second periodic event. */
        if(0U != timerEvt)
        {
            RtcDisplayDateTime();
        }
    }

    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void RtcBoardInit(void)
{
    CSL_rtc_cm_core_aonRegs *rtcCmReg =
        (CSL_rtc_cm_core_aonRegs *) CSL_MPU_RTC_CM_CORE_AON_REGS;

    CSL_FINS(rtcCmReg->CM_RTC_RTCSS_CLKCTRL_REG,
        RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE,
        CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_ENABLED);

    while(CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_FUNC !=
       CSL_FEXT(rtcCmReg->CM_RTC_RTCSS_CLKCTRL_REG,
        RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST));
}

void RtcTimerIntrInit(void)
{
#if 1
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_39, CSL_XBAR_RTC_SS_IRQ_TIMER);

    /* Do the interrupt related configurations */
    gRtcIntrParams.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gRtcIntrParams.priority = 0x20U;

    /*
     * Assign the ISR to the function pointer to invoke when the
     * interrupt is raised.
     */
    gRtcIntrParams.pFnIntrHandler = &RtcTimerIsr;
    gRtcIntrParams.pUserParam = hRtc;

    /* Configure the interrupt Controller */
    CSL_armGicConfigIntr(&gCpuIntrf, 71U, &gRtcIntrParams);
#else
    HwiP_Params hwiInputParams;
    Uint32 intrNum = 71U;

    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_39, CSL_XBAR_RTC_SS_IRQ_TIMER);

    CSL_osalHwiParamsInit(&hwiInputParams);

    hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)hRtc;
    hwiInputParams.priority = 0x20;
    hwiInputParams.evtId = 0;

    CSL_osalRegisterInterrupt(intrNum, RtcTimerIsr, &hwiInputParams);
#endif
}

#if 1
void RtcTimerIsr(void* pUserParam)
#else
static void RtcTimerIsr(uintptr_t pUserParam)
#endif
{
    Uint32 status = 0U;
    RTCHandle hRtc = (RTCHandle) pUserParam;

    /* Read the Timer Interrupt Status */
    status = CSL_rtcTimerIntrStatus(hRtc->regs);

    if(0U != (status & CSL_RTC_TIMER_INTR_STS_ALL))
    {
        /* Disable the specific Timer interrupt. */
        CSL_rtcTimerIntrDisable(hRtc->regs);

        /* execute the timer event callback */
        if(NULL != hRtc->timerCallback)
        {
            hRtc->timerCallback(pUserParam, CSL_RTC_TIMER_INTR_STS_ONE_SEC);
        }
   }
}

void RtcTimerCallback(void* pUserParam, CSL_rtcTimerIntrSts tmrSts)
{
    /* Return the Timer event status */
    timerEvt = 1U;
}

void RtcDisplayDateTime(void)
{
    /* Get the current date and time information. */
    CSL_rtcGetTime(hRtc->regs, &time1Val);
    CSL_rtcGetDate(hRtc->regs, &date1Val);

    /* Clear the status flag. */
    timerEvt = 0U;

    /* Display the Current Time. */
    RTC_log("%u:%u:%u ", time1Val.hours, time1Val.minutes, time1Val.seconds);

    /* If AM/PM meridiem mode is selected display the appropriate mode. */
    if(CSL_RTC_TIME_MODE_12_HR == time1Val.timeMode)
    {
        RTC_log("%s", meridiemMode[time1Val.meridiemMode]);
    }

    /* Display the Date information. */
    RTC_log(" %u:%u:%u ",date1Val.day, date1Val.month, date1Val.year);

    /* Display the day of the week. */
    RTC_log("%s ", dayOfWeek[date1Val.weekDay - 1]);

    RTC_log("\r");
}
