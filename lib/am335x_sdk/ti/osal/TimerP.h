/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \ingroup DRV_OSAL_MODULE
 *  \defgroup DRV_OSAL_TimerP TimerP
 *            TimerP interface
 *
 *  @{
 */

/** ============================================================================
 *  @file       TimerP.h
 *
 *  @brief      Timer interface for the RTOS Porting Interface
 *
 *  The TimerP module can be used to create a timer (that is, to mark a timer
 *  for use) and configure it to call a tickFxn when the timer expires.
 *
 *  The timer can be configured as a one-shot or a continuous mode timer.
 *  The period can be specified in timer counts or microseconds.
 *  The timer interrupt always uses the Hwi dispatcher. The Timer tickFxn runs
 *  in the context of a Hwi thread. The Timer module automatically creates a
 *  Hwi instance for the timer interrupt.
 *  ============================================================================
 */

#ifndef ti_osal_TimerP__include
#define ti_osal_TimerP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*!
 * Const used to specify any timer
 */
#define TimerP_ANY       (~(uint32_t)0u)

/*!
 * Max value of Timer period for PeriodType_COUNTS
 */
#define TimerP_MAX_PERIOD ((uint32_t)0xffffffffu)

/*!
 * Use default values as provided by the OSAL package
 */
 #define TimerP_USE_DEFAULT   (-(int32_t)1)

/*!
 *  @brief  Frequency-in-hertz struct
 */
typedef struct TimerP_FreqHz_s {
    uint32_t hi;      /*!< most significant 32-bits of frequency */
    uint32_t lo;      /*!< least significant 32-bits of frequency */
} TimerP_FreqHz;

/*!
 *  @brief    Status codes for TimerP APIs
 */
typedef enum TimerP_Status_e {
    TimerP_OK            =             0,
    TimerP_FAILURE       = (-(int32_t) 1),
    TimerP_NOT_AVAILABLE = (-(int32_t) 2),
    TimerP_BAD_INT_NUM   = (-(int32_t) 3),
    TimerP_ISR_HOOK_ERR  = (-(int32_t) 4)
} TimerP_Status;


/*!
 *  @brief  Timer period units for TimerP APIs
 */
typedef enum TimerP_PeriodType_e {
    TimerP_PeriodType_MICROSECS,  /*!< timer period is in micro seconds */
    TimerP_PeriodType_COUNTS      /*!< timer period is in counts */
} TimerP_PeriodType;

/*!
 *  @brief  Timer runtime modes for TimerP APIs
 */
typedef enum TimerP_RunMode_e {
    TimerP_RunMode_CONTINUOUS,  /*!< timer is periodic and runs continuously */
    TimerP_RunMode_ONESHOT      /*!< timer runs for a single period values and stops */
 } TimerP_RunMode;

/*!
 *  @brief  Timer start modes for TimerP APIs
 */
typedef enum TimerP_StartMode_e {
    TimerP_StartMode_AUTO,      /*!< timer starts automatically after create*/
    TimerP_StartMode_USER       /*!< timer will be started by the user */
}TimerP_StartMode;

/*!
 * @brief Timer mode for 64 bit timers (KeyStone devices)
 * @note  this is not applicable for non KeyStone devices such as AM572x etc
 */
typedef enum TimerP_Timer64Mode_e {
  TimerP_Timer64Mode_64BITGPTIMER,
  TimerP_Timer64Mode_UNCHAINED,
  TimerP_Timer64Mode_CHAINED
} TimerP_Timer64Mode;

/*!
 * @brief Timer half when 64 bit timer is split into two 32 bit timer (Keystone devices)
 * @note  this is not applicable for non KeyStone devices such as AM572x etc
 */
typedef enum TimerP_Timer64Half_e {
  TimerP_Timer64Half_LOWER,
  TimerP_Timer64Half_UPPER,
  TimerP_Timer64Half_DEFAULT
}TimerP_Timer64Half;

/*!
 *  @brief    Opaque client reference to an instance of a TimerP
 *
 *  A TimerP_Handle returned from the ::TimerP_create represents that instance.
 *  and then is used in the other instance based functions (e.g. ::TimerP_start,
 *  ::TimerP_stop, etc.).
 */
typedef  void *TimerP_Handle;

/*!
 *  @brief  Prototype for a TimerP function.
 */
typedef void (*TimerP_Fxn)(uintptr_t arg);

/*!
 *  @brief    Basic TimerP Parameters
 *
 *  Structure that contains the parameters passed into ::TimerP_create
 *  when creating a TimerP instance. The ::TimerP_Params_init function should
 *  be used to initialize the fields to default values before the application sets
 *  the fields manually. The TimerP default parameters are noted in
 *  TimerP_Params_init.
 */
typedef struct TimerP_Params_s {
    char    *name;        /*!< Name of the timer instance. Memory must
                             persist for the life of the clock instance.
                             This can be used for debugging purposes, or
                             set to NULL if not needed. */
    uint32_t periodType;  /*!< Period type, default micro seconds */
    int32_t  extfreqLo;   /*!< least siginificant 32-bits of ext frequency
                               set to 0 to use internal clk freq  */
    int32_t  extfreqHi;   /*!< most siginificant 32-bits of ext frequency
                               set to 0 to use internal clk freq  */
    int32_t  intfreqLo;   /*!< least siginificant 32-bits of int frequency
                               set to 0 to use default internal clk freq  */
    int32_t  intfreqHi;   /*!< most siginificant 32-bits of int frequency
                               set to 0 to use default internal clk freq  */
    uint32_t startMode;   /*!< timer start mode */
    uint32_t runMode;     /*!< timer run mode */
    uint32_t period;      /*!< Period of a tick */
    TimerP_Timer64Mode timerMode; /*!< timer mode for 64bit timer */
    TimerP_Timer64Half timerHalf; /*!< timer half for 64bit timer */

    int32_t  intNum;      /*!< Hwi Interrupt number to be used by Timer */
#if defined (_TMS320C6X)
    int32_t  eventId;     /*!< Hwi event Id to be used by the Timer */
#endif
    void*    arg;         /*!< Argument passed into the timer function. */
} TimerP_Params;

/*!
 *  @brief  Function to create a timer object.
 *
 *  @param  id       Timer Id
 *
 *  @param  tickFxn  Function that runs upon timer expiry
 *
 *  @param  timerParams    Pointer to the instance configuration parameters. NULL
 *                    denotes to use the default parameters. The TimerP default
 *                    parameters are noted in ::TimerP_Params_init.
 *
 *  @return A TimerP_Handle on success or a NULL on an error.  This handle can
 *          be passed to TimerP_start()
 */
extern TimerP_Handle TimerP_create(int32_t        id,
                                   TimerP_Fxn     tickFxn,
                                   const TimerP_Params *timerParams);

/*!
 *  @brief  Function to delete a timer.
 *
 *  @param  timerHandle  A TimerP_Handle returned from ::TimerP_create
 *
 *  @return Status of the function.
 *    - TimerP_OK: Deleted the timer instance
 *    - TimerP_FAILURE: Timed out waiting to delete the timer object.
 */
extern TimerP_Status TimerP_delete(TimerP_Handle timerHandle);

/*!
 *  @brief  Function to set timer period specified in micro seconds
 *  A best-effort method will be used to set the period register.
 *  There might be a slight rounding error based on resolution of
 *  timer period register. If the timer frequency cannot support
 *  the requested period, i.e. the timer period register cannot
 *  support the requested period, then this function returns false.
 *  TimerP_setPeriodMicroSecs() invokes TimerP_stop() prior to setting
 *  the period and leaves the timer in the stopped state.
 *
 *  @param  timerHandle  A TimerP_Handle returned from ::TimerP_create
 *
 *  @param  microsecs  time in micro seconds
 *
 *  @return Status of the function.
 *    - TimerP_OK: Deleted the timer instance
 *    - TimerP_FAILURE: Timed out waiting to delete the timer object.
 */
extern TimerP_Status TimerP_setPeriodMicroSecs(TimerP_Handle timerHandle, uint32_t microsecs);

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - name: NULL
 *   - arg: 0
 *
 *  @param timerParams  Pointer to the instance configuration parameters.
 */
extern void TimerP_Params_init(TimerP_Params *timerParams);

/*!
 *  @brief  Function to start a timer.
 *
 *  @param  timerHandle  A TimerP_Handle returned from ::TimerP_create
 *
 *  @return Status of the functions
 *    - TimerP_OK: Scheduled the timer function successfully
 *    - TimerP_FAILURE: The API failed.
 */
extern TimerP_Status TimerP_start(TimerP_Handle timerHandle);

/*!
 *  @brief  Function to stop a timer.
 *
 *  @param  timerHandle  A TimerP_Handle returned from ::TimerP_create
 *
 *  @return Status of the functions
 *    - TimerP_OK: Scheduled the timer function successfully
 *    - TimerP_FAILURE: The API failed.
 */
extern TimerP_Status TimerP_stop(TimerP_Handle timerHandle);

/*!
 *  @brief  Function to clear the interrupt of the timer.
 *
 *  @param  timerHandle  A TimerP_Handle returned from ::TimerP_create
 *
 *  @return Status of the function
 *    - TimerP_OK: Clear the interrupt of the timer function successfully.
 *
 */
extern TimerP_Status TimerP_ClearInterrupt(TimerP_Handle timerHandle);

/*
 *  @brief  Function to return current time in units of micro-secs
 *
 *  @return Current time in units of micro-secs
 *
 * Note: This API is not supported for J7/OMAPL13x platforms and
 *       result in link errors if used in the application
 */
extern uint64_t TimerP_getTimeInUsecs(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_ClockP__include */
/* @} */
