/**
 * \file   rtc_test.c
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
#include <ti/board/board.h>
#if defined(SOC_AM335x) || defined(SOC_AM437x)
#include <ti/starterware/include/interrupt.h>
#endif

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* Application header files */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Macro defining the Base address of RTC module. */
#define RTC_SS_REGS                     (0x44E3E000U)

/* Macro defining the RTC timer interrupt number. */
#ifdef SOC_AM437x
#define RTC_TIMER_INT                   (107U)
#endif
#ifdef SOC_AM335x
#define RTC_TIMER_INT                   (75U)
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

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

RTCObj gRtcObj;

RTCHandle gRtcHandle;

/**< RTC Timer interrupt flag */
volatile uint32_t timerEvt = 0U;

/** \brief Structure which holds the Interrupt Configuration Params. */
static intcIntrParams_t gRtcAppIntrParams;

CSL_rtcClkSrc clkSrc = CSL_RTC_CLK_SRC_EXTERNAL;

CSL_rtcTimeObj  time1Val =
    {
        10U,                        /* hours */
        23U,                        /* minutes */
        51U,                        /* seconds */
        0U,                         /* nanoSec */
        CSL_RTC_TIME_MODE_24_HR,    /* timeMode */
        CSL_RTC_TIME_MERIDIEM_AM,   /* timeFormat */
    };
CSL_rtcDateObj  date1Val =
    {
        21U,                  /* day */
        06U,                  /* month */
        16U,                  /* year */
        01U,                  /* weekDay */
    };

CSL_rtcTimeObj  timeVal =
    {
        10U,                        /* hours */
        23U,                        /* minutes */
        51U,                        /* seconds */
        0U,                         /* nanoSec */
        CSL_RTC_TIME_MODE_24_HR,    /* timeMode */
        CSL_RTC_TIME_MERIDIEM_AM,   /* timeFormat */
    };
CSL_rtcDateObj  dateVal =
    {
        21U,                  /* day */
        06U,                  /* month */
        16U,                  /* year */
        01U,                  /* weekDay */
    };

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

static void RtcTimerIsr(uint32_t intrNum, uint32_t cpuId, void* pUserParam);

void RtcDisplayDateTime(void);

void RtcTimerCallback(void* pUserParam, CSL_rtcTimerIntrSts tmrSts);

void RtcBoardInit(void);

static void RtcTimerIntrInit(uint32_t intNum);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    Uint32 status = 0U;
    Board_initCfg boardCfg;
    uint32_t count = 10U;

    /* Call board init functions */
    #ifdef PDK_RAW_BOOT
    boardCfg = (BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO);
    #else
    boardCfg = BOARD_INIT_UART_STDIO;
    #endif

    status = Board_init(boardCfg);

    UART_printf("\n***********************************************\n"); 
    UART_printf("*                 RTC Test                    *\n");
    UART_printf("***********************************************\n");

    if (status == BOARD_SOK)
    {
        gRtcHandle = &gRtcObj;
        gRtcHandle->regs = (CSL_rtcHandle) RTC_SS_REGS;
        gRtcHandle->timerCallback = &RtcTimerCallback;

        RtcTimerIntrInit(RTC_TIMER_INT);

        /* Disable Write Protection for RTC registers. */
        CSL_rtcWriteProtectEnable(gRtcHandle->regs, FALSE);

        /* Selecting Clock source to drive the RTC. */
        CSL_rtcClkSrcSelect(gRtcHandle->regs, clkSrc);

        /* Enable the RTC module */
        CSL_rtcEnable(gRtcHandle->regs, TRUE);

        /* Get the current date and time information. */
        CSL_rtcGetTime(gRtcHandle->regs, &time1Val);

        CSL_rtcGetDate(gRtcHandle->regs, &date1Val);

        while(timeVal.hours != time1Val.hours)
        {
            /* Set the Time in the RTC clock */
            CSL_rtcSetTime(gRtcHandle->regs, &timeVal);

            /* Set the Date in the RTC clock */
            CSL_rtcSetDate(gRtcHandle->regs, &dateVal);

            /* Get the current date and time information. */
            CSL_rtcGetTime(gRtcHandle->regs, &time1Val);

            CSL_rtcGetDate(gRtcHandle->regs, &date1Val);
        }

        /* Start the RTC Clock */
        CSL_rtcRun(gRtcHandle->regs);

        UART_printf("\r\nCurrent Date and Time:\r\n");

        /*
        ** Enable the clock to run with periodic interrupt of every second.
        */

        /* Enable One second Periodic Interrupts. */
        CSL_rtcTimerIntrEnable(gRtcHandle->regs, CSL_RTC_TIMER_INTR_MASK_EVERY_SEC);

        while(count > 0)
        {
            /* Check for the occurrence of a per second periodic event. */
            if(0U != timerEvt)
            {
                RtcDisplayDateTime();
                timerEvt = 1U;
                count--;
            }
        }
        UART_printf("\nTest Passed!\n");
    }
    else
    {
        UART_printf("Test FAILED!\n");
        status = -1;
    }

    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void RtcTimerIntrInit(uint32_t intNum)
{
    /* Initialize the Interrupt Controller. */
    INTCInit(INTC_NON_SECURE_MODE);

    /* Do the interrupt related configurations */
    gRtcAppIntrParams.triggerType = INTC_TRIG_HIGH_LEVEL;
    gRtcAppIntrParams.priority = 0x20U;
    /*
    ** Assign the ISR to the function pointer to invoke when the
    ** interrupt is raised.
    */
    gRtcAppIntrParams.pFnIntrHandler = &RtcTimerIsr;
    gRtcAppIntrParams.pUserParam = gRtcHandle;
    gRtcAppIntrParams.isIntrSecure = FALSE;
    /* Configure the interrupt Controller */
    INTCConfigIntr(intNum, &gRtcAppIntrParams, FALSE);
}


static void RtcTimerIsr(uint32_t intrNum, uint32_t cpuId, void* pUserParam)
{
    Uint32 status = 0U;
    RTCHandle gRtcHandle = (RTCHandle) pUserParam;

    /* Read the Timer Interrupt Status */
    status = CSL_rtcTimerIntrStatus(gRtcHandle->regs);

    if(0U != (status & CSL_RTC_TIMER_INTR_STS_ALL))
    {
        /* Disable the specific Timer interrupt. */
        CSL_rtcTimerIntrDisable(gRtcHandle->regs);

        /* execute the timer event callback */
        if(NULL != gRtcHandle->timerCallback)
        {
            gRtcHandle->timerCallback(pUserParam, CSL_RTC_TIMER_INTR_STS_ONE_SEC);
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
    CSL_rtcGetTime(gRtcHandle->regs, &time1Val);
    CSL_rtcGetDate(gRtcHandle->regs, &date1Val);

    /* Clear the status flag. */
    timerEvt = 0U;

    /* Display the Current Time. */
    UART_printf("%u:%u:%u ", time1Val.hours, time1Val.minutes, time1Val.seconds);

    /* If AM/PM meridiem mode is selected display the appropriate mode. */
    if(CSL_RTC_TIME_MODE_12_HR == time1Val.timeMode)
    {
        UART_printf("%s", meridiemMode[time1Val.meridiemMode]);
    }

    /* Display the Date information. */
    UART_printf(" %u:%u:%u ",date1Val.day, date1Val.month, date1Val.year);

    /* Display the day of the week. */
    UART_printf("%s ", dayOfWeek[date1Val.weekDay - 1]);

    UART_printf("\r");
}
