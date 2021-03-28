/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
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
/*
 *  ======== TimerP_tirtos.c ========
 */

#include <ti/osal/TimerP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>

#if defined (SOC_AM437x) || defined (SOC_AM335x) || defined (SOC_AM574x) || defined (SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#if defined(TIMER64_SUPPORT)
#undef   TIMER64_SUPPORT
#endif
#include <ti/sysbios/timers/dmtimer/Timer.h>
#elif defined (SOC_C6678) || defined (SOC_K2G) || defined (SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_C6657) || defined(SOC_C6678) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#define  TIMER64_SUPPORT
#include <ti/sysbios/timers/timer64/Timer.h>
#elif defined (SOC_TPR12)
#if defined(TIMER64_SUPPORT)
#undef   TIMER64_SUPPORT
#endif
#define RTI_SUPPORT
#include <ti/sysbios/timers/rti/Timer.h>
#else
#include <ti/sysbios/hal/Timer.h>
#endif

#include <ti/osal/src/tirtos/tirtos_config.h>

extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
#define TIMOSAL_Assert(expression) (Osal_DebugP_assert(((int32_t)((expression)?1:0)),\
                                                  __FILE__, __LINE__))

extern uint32_t  gOsalTimerAllocCnt, gOsalTimerPeak;

/*!
 *  @brief    Timer structure
 */
typedef struct TimerP_tiRtos_s {
    Bool              used;
    Timer_Struct      timer;
} TimerP_tiRtos;

/* global pool of statically allocated semaphore pools */
static TimerP_tiRtos gOsalTimerPTiRtosPool[OSAL_TIRTOS_CONFIGNUM_TIMER];


void TimerP_Params_init(TimerP_Params *params)
{
    TIMOSAL_Assert((params == NULL_PTR));

    if(params != NULL_PTR)
    {
      /* Set the default values */
      params->arg         = NULL_PTR;
      params->extfreqHi   = TimerP_USE_DEFAULT;
      params->extfreqLo   = TimerP_USE_DEFAULT;
      params->name        = (char *) NULL_PTR;
      params->period      = 0;
      params->runMode     = (uint32_t)TimerP_RunMode_CONTINUOUS;
      params->startMode   = (uint32_t)TimerP_StartMode_AUTO;
      params->periodType  = (uint32_t)TimerP_PeriodType_MICROSECS;
#if !defined(RTI_SUPPORT)
      params->intNum      = (int32_t)TimerP_USE_DEFAULT;
#endif
#if defined (TIMER64_SUPPORT)
      params->timerMode   = TimerP_Timer64Mode_UNCHAINED;
      params->timerHalf   = TimerP_Timer64Half_DEFAULT;
#endif

#if defined (_TMS320C6X) && !defined(RTI_SUPPORT)
      params->eventId     = TimerP_USE_DEFAULT;
#endif
    }
    return;
}

TimerP_Handle TimerP_create(int32_t id,
                            TimerP_Fxn tickFxn,
                            const TimerP_Params *params)
{
    TimerP_tiRtos    *handle = (TimerP_tiRtos *) NULL_PTR;
    Timer_Params      timerParams;
    Error_Block       eb;
    uint32_t          i;
    uintptr_t         key;

    /* Grab the memory */
    key = HwiP_disable();

    if(gOsalTimerAllocCnt==0U)
    {
		(void)memset((void *)gOsalTimerPTiRtosPool,0,sizeof(gOsalTimerPTiRtosPool));
	}
    for (i = 0; i < OSAL_TIRTOS_CONFIGNUM_TIMER; i++)
    {
        if (gOsalTimerPTiRtosPool[i].used == FALSE)
        {
            gOsalTimerPTiRtosPool[i].used = TRUE;
            /* Update statistics */
            gOsalTimerAllocCnt++;
            if (gOsalTimerAllocCnt > gOsalTimerPeak)
            {
                gOsalTimerPeak = gOsalTimerAllocCnt;
            }

            break;
        }
    }
    HwiP_restore(key);

    if (i < OSAL_TIRTOS_CONFIGNUM_TIMER)
    {
        /* Grab the memory */
        handle = (TimerP_tiRtos *) &gOsalTimerPTiRtosPool[i];
    }

    if (handle != NULL_PTR)
    {
        if (params == NULL_PTR)
        {
           Timer_construct(&(handle->timer), id, tickFxn, (Timer_Params *) NULL_PTR, (Error_Block *) NULL_PTR);
        }
        else
        {
            Timer_Params_init(&timerParams);
            /*
             * Update the default initializations to user configured values
             */

            if (params->name != NULL_PTR)
            {
                timerParams.instance->name        = params->name;
            }

            /* Convert the enumerations for period type */
            switch (params->periodType)
            {
              case (uint32_t)TimerP_PeriodType_COUNTS:
                 timerParams.periodType = Timer_PeriodType_COUNTS;
                 break;

              case (uint32_t)TimerP_PeriodType_MICROSECS:
              default:
                  timerParams.periodType = Timer_PeriodType_MICROSECS;
                  break;
            }

            /* conver the enumerations for run mode */
            switch (params->runMode)
            {
               case (uint32_t)TimerP_RunMode_ONESHOT:
                   timerParams.runMode = Timer_RunMode_ONESHOT;
                   break;
               case (uint32_t)TimerP_RunMode_CONTINUOUS:
               default:
                   timerParams.runMode = Timer_RunMode_CONTINUOUS;
                   break;
            }

            /* conver the enumerations for start mode */
            switch (params->startMode)
            {
               case (uint32_t)TimerP_StartMode_USER:
                   timerParams.startMode = Timer_StartMode_USER;
                   break;
               case (uint32_t)TimerP_StartMode_AUTO:
               default:
                   timerParams.startMode = Timer_StartMode_AUTO;
                   break;
            }

            if ( params->extfreqLo != TimerP_USE_DEFAULT) {
                timerParams.extFreq.lo            = (Bits32) params->extfreqLo;
            }
            if ( params->extfreqHi != TimerP_USE_DEFAULT) {
                timerParams.extFreq.hi            = (Bits32) params->extfreqHi;
            }

            if ( params->period != 0u) {
                timerParams.period                = params->period;
            }

            if ( params->arg != NULL_PTR) {
                timerParams.arg                   = (xdc_UArg) params->arg;
            }
#if !defined(RTI_SUPPORT)
            if ( params->intNum != TimerP_USE_DEFAULT) {
                timerParams.intNum = params->intNum;
            }
#endif
#if defined (_TMS320C6X) && !defined(TIMER64_SUPPORT) && !defined(RTI_SUPPORT)
            if ( params->eventId != TimerP_USE_DEFAULT) {
                timerParams.eventId = params->eventId;
            }
#endif

#if defined(TIMER64_SUPPORT)
            /* conver the enumerations for timer Half */
            switch (params->timerHalf)
            {
               case TimerP_Timer64Half_LOWER:
                   timerParams.half    = Timer_Half_LOWER;
                   break;
               case TimerP_Timer64Half_UPPER:
                   timerParams.half    = Timer_Half_UPPER;
                   break;
               case TimerP_Timer64Half_DEFAULT:
               default:
                   timerParams.half    = Timer_Half_DEFAULT;
                   break;
            }
#endif
            Error_init(&eb);
            Timer_construct(&handle->timer, (int32_t)id, tickFxn, &timerParams, &eb);
        }
    }
    return ((TimerP_Handle)handle);
}

/*
 *  ======== TimerP_delete ========
 */
TimerP_Status TimerP_delete(TimerP_Handle handle)
{
    TIMOSAL_Assert((handle == NULL_PTR));
    TimerP_Status ret = TimerP_OK;
    uintptr_t   key;
    TimerP_tiRtos *timer = (TimerP_tiRtos *)handle;

    if(timer != NULL_PTR)
    {
      Timer_destruct(&timer->timer);
      key = HwiP_disable();
      timer->used = FALSE;
      /* Found the osal timer object to delete */
      if (gOsalTimerAllocCnt > 0U)
      {
        gOsalTimerAllocCnt--;
      }
      HwiP_restore(key);
      ret = TimerP_OK;
    }
    else
    {
      ret = TimerP_FAILURE;
    }

    return (ret);
}


TimerP_Status TimerP_start(TimerP_Handle handle)
{
    TIMOSAL_Assert((handle == NULL_PTR));
    uintptr_t   key;
    TimerP_tiRtos *timer = (TimerP_tiRtos *)handle;

   /* disable interrupts if an interrupt could lead to
    * another call to Timer_start()*/
    key = Hwi_disable();
    Timer_stop((Timer_Handle)&timer->timer);
    Timer_start((Timer_Handle)&timer->timer);
    (void)Hwi_restore((uint32_t)key);
    return (TimerP_OK);
}

TimerP_Status TimerP_stop(TimerP_Handle handle)
{
    TIMOSAL_Assert((handle == NULL_PTR));
    uintptr_t   key;
    TimerP_tiRtos *timer = (TimerP_tiRtos *)handle;

   /* disable interrupts if an interrupt could lead to
    * another call to Timer_stop()*/
    key = Hwi_disable();
    Timer_stop((Timer_Handle)&timer->timer);
    (void)Hwi_restore((uint32_t)key);
    return (TimerP_OK);
}

TimerP_Status TimerP_setPeriodMicroSecs(TimerP_Handle handle, uint32_t microsecs)
{
  TIMOSAL_Assert((handle == NULL_PTR));
  uintptr_t   key;
  TimerP_tiRtos *timer = (TimerP_tiRtos *)handle;
  TimerP_Status ret = TimerP_OK;

  key = Hwi_disable();
  if (Timer_setPeriodMicroSecs((Timer_Handle)&timer->timer, microsecs)!=1U) {
    ret = TimerP_FAILURE;
  }
  if (ret == TimerP_OK) {
    Timer_start((Timer_Handle)&timer->timer);
  }
  (void)Hwi_restore((uint32_t)key);
  return(ret);
}

uint64_t TimerP_getTimeInUsecs(void)
{
    Types_Timestamp64 bios_timestamp64 = {0, 0};
    Types_FreqHz bios_freq = {0, 400000000U};
    uint64_t cur_ts, freq;

    Timestamp_get64(&bios_timestamp64);
    Timestamp_getFreq(&bios_freq);

    cur_ts = ((uint64_t) bios_timestamp64.hi << 32) | bios_timestamp64.lo;
    freq = ((uint64_t) bios_freq.hi << 32) | bios_freq.lo;

    return (cur_ts*1000000u)/freq;
}

/* Nothing past this point */
