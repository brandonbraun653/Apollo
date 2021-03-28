/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *  ======== TimerP_nonos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <ti/osal/TimerP.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_tmr.h>
#include <ti/csl/csl_tmrAux.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* Timer 64 Implementation */
extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
#define TIMOSAL_Assert(expression) (Osal_DebugP_assert(((int32_t)((expression)?1:0)),\
                                                  __FILE__, __LINE__))


/* Local Timer Struct */
typedef struct TimerP_Struct
{
  bool     used;       /* In use or not status */
  CSL_TmrHandle hTmr;  /* CSL Timer Handle */
  uint32_t id;         /* timer Id */
  uint32_t periodType; /* Period type, default micro seconds */
  uint32_t freqLo;     /* least siginificant 32-bits of frequency */
  uint32_t freqHi;     /* most siginificant 32-bits of frequency  */
  uint32_t startMode;  /* timer start mode */
  uint32_t runMode;    /* timer run mode   */
  uint32_t period;     /* Period of a tick */
  TimerP_Fxn tickFxn;  /* Timer Tick function */
  void*    arg;        /* Argument passed into the timer function. */
  uint32_t availMask;   /* Available timer mask */
  HwiP_Handle hwi;      /* Hwi handle for tickFxn */
#if defined (_TMS320C6X)
  uint32_t eventId;     /* Event Id for C66x */
#endif
  int32_t  intNum;      /* Interrupt Number */
  TimerP_Timer64Mode mode;
  TimerP_Timer64Half timerHalf; /*!< timer half for 64bit timer */
  uint32_t   prescalar;
  uint32_t   intCtl;
  CSL_TmrObj TmrObj;   /* CSL timer Object */
}TimerP_Struct;

/* As static allocation is used, the following provides the structs
 * The TimerP_Struct pool servers to get an available timer
 * handle during timer create API call.
 */
TimerP_Struct gTimerStructs[OSAL_NONOS_CONFIGNUM_TIMER];
static        uint32_t     gTimerInitDone = 0U;
static        uint32_t     gTimerAnyMask;

/* Local functions  */
static uint32_t TimerP_getTimerBaseAddr(uint32_t timer_id);
static void  TimerP_timer64InitDevice(TimerP_Struct *timer, uint32_t baseAddr);
static bool TimerP_timer64CheckOverflow(uint32_t a, uint32_t b);
static bool TimerP_timer64SetMicroSeconds(TimerP_Struct *timer, uint32_t period);
static TimerP_Status TimerP_timer64DeviceCfg(TimerP_Struct *timer, uint32_t baseAddr);
static TimerP_Status TimerP_timer64InitObj(TimerP_Struct *timer, TimerP_Fxn tickFxn,
                                           const TimerP_Params *params);
static TimerP_Status TimerP_timer64InstanceInit(TimerP_Struct *timer, uint32_t id,
                                                TimerP_Fxn tickFxn, const TimerP_Params *params);


/* Below function returns the bit width of the number
 * by computing number of redundant sign bits used or
 * sign extended in the given 32 bits
 */
#if defined(_TMS320C6X)
  #define TimerP_maxbit(bits) (31 - _norm(bits))
#else
#if defined (__TI_ARM__)
static uint32_t TimerP_maxbit(uint32_t bits)
{
      register uint32_t __R5, __R0;

      __R5 = 0; /* to avoid compiler warning*/
	  __R0 = bits;
	  __R0 = __R0;

	  asm("    clz   r5, r0\n"
	      "    rsb   r5, r5, #31\n");

      return (uint32_t)__R5;
  }
#else
static uint32_t TimerP_maxbit(uint32_t bits)
{
      uint32_t retVal;
      __asm__ __volatile__ (
        "clz %0, %1\n\t"
        "rsb %0, %0, #31"
        : "=r" (retVal)
        : "r" (bits)
        : "cc"            );
      return retVal;
  }
#endif
#endif

/*
 * This private function returns the base address of the timer based on
 * the ID passed in.
 */
static uint32_t TimerP_getTimerBaseAddr(uint32_t timer_id)
{
    uint32_t addr;

    if (timer_id < TimerP_numTimerDevices) {
      addr = (uint32_t) gTimer64InfoTbl[timer_id].baseAddr;
    }
    else {
      addr = (uint32_t) NULL_PTR;
    }
    return (addr);
}

/*
 * This priviate function initializes the timer counter, period and compare
 * registers
 */
static void  TimerP_timer64InitDevice(TimerP_Struct *timer, uint32_t baseAddr)
{
    uint32_t hwiKey;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_Status                  status;

    /* Clear local data structures */
    (void)memset(&timer->TmrObj, 0, sizeof(CSL_TmrObj));

    hwiKey = HwiP_disable();

    /* Open the timer. */
    timer->hTmr =  CSL_tmrOpen(&timer->TmrObj, timer->id, NULL_PTR, &status);

    if (timer->hTmr != NULL_PTR) {
      /* Configure the timer. */
      CSL_tmrHwSetup(timer->hTmr, &hwSetup);

      if (timer->hwi) {
          /* clear any previously latched timer interrupts */
          HwiP_clearInterrupt(timer->intNum);
          HwiP_disableInterrupt(timer->intNum);
      }
    }

    HwiP_restore(hwiKey);
}

/*
 * This priviate function checks if there is any overflow in
 * timer period computations
 */
static bool TimerP_timer64CheckOverflow(uint32_t a, uint32_t b)
{
  return ((b > 0) && (a > TimerP_MAX_PERIOD/b));
}

/*
 * This is a private function to set the period of the timer
 * register for a specified micro second value
 */
static bool TimerP_timer64SetMicroSeconds(TimerP_Struct *timer, uint32_t period)
{
    uint64_t  counts;
    uint32_t  prdCounts, pscCounts;
    uint32_t  freqKHz, shift = 0;
    bool      ret = TRUE;

    TimerP_stop(timer);

    freqKHz = (timer->freqLo / 1000);
    if (TimerP_timer64CheckOverflow(freqKHz, period/1000)) {
            return (FALSE);
    }

    counts = ((uint64_t)freqKHz * (uint64_t)period) / (uint64_t)1000;
    if (counts > 0xffffffff) {
      pscCounts = counts >> 32;
      if (pscCounts) {
          shift = TimerP_maxbit(pscCounts) + 1;
          pscCounts = (1 << shift) - 1;
      }
      prdCounts = (counts >> shift);
    }
    else {
      prdCounts = counts;
      pscCounts = 0;
    }

    timer->period     = prdCounts;
    timer->periodType = TimerP_PeriodType_COUNTS;
    timer->prescalar  = pscCounts;

    if (timer->mode != TimerP_Timer64Mode_64BITGPTIMER ) {
      if (pscCounts != 0) {
        ret = FALSE;
      }
    }

    return(ret);
}

/*
 * Thi is a private function to configure the timer registers for a given timer
 * period
 */
static TimerP_Status TimerP_timer64DeviceCfg(TimerP_Struct *timer, uint32_t baseAddr)
{
  uint32_t      key;

  key = HwiP_disable();

  /* initialize the timer */
  TimerP_timer64InitDevice(timer, baseAddr);

  /* compute and get the period */
  if (timer->periodType == TimerP_PeriodType_MICROSECS) {
      if (!TimerP_timer64SetMicroSeconds(timer, timer->period)) {
          HwiP_restore(key);
          return (TimerP_FAILURE);
      }
  }

  HwiP_restore(key);

  return (TimerP_OK);
}

/*
 * This is a private function to initialize the timer counter, period and compare
 * registers before starting the timers
 */
static TimerP_Status TimerP_timer64InitObj(TimerP_Struct *timer, TimerP_Fxn tickFxn, const TimerP_Params *params)
{
  timer->tickFxn = tickFxn;

  /*
   * Update the default initializations to user configured values
   */
  if ( params->extfreqLo != TimerP_USE_DEFAULT) {
    timer->freqLo            =  params->extfreqLo;
  }
  else  {
    if (params->intfreqLo != TimerP_USE_DEFAULT)  {
      timer->freqLo            = params->intfreqLo;
    }
    else {
      timer->freqLo            =  TimerP_getDefaultFreqLo(timer->id);
    }
  }

  if ( params->extfreqHi != TimerP_USE_DEFAULT) {
    timer->freqHi            =  params->extfreqHi;
  }
  else  {
    if (params->intfreqHi != TimerP_USE_DEFAULT)  {
      timer->freqHi          = params->intfreqHi;
    }
    else {
      timer->freqHi            =  TimerP_getDefaultFreqHi(timer->id);
    }
  }

  if ( params->period != 0) {
    timer->period                = params->period;
  }
  else  {
    timer->period                = 0;
  }

   if ( params->arg != (void*) NULL_PTR) {
     timer->arg                   = params->arg;
   }

   if ( params->intNum != TimerP_USE_DEFAULT) {
     timer->intNum = params->intNum;
   }
   else {
     timer->intNum = gTimer64InfoTbl[timer->id].intNumLo;
   }

#if defined (_TMS320C6X)
   if ( params->eventId != TimerP_USE_DEFAULT) {
     timer->eventId = params->eventId;
   }
   else {
     timer->eventId = gTimer64InfoTbl[timer->id].eventIdLo;
   }
#endif

   timer->periodType = params->periodType;
   timer->startMode  = params->startMode;
   timer->runMode    = params->runMode;
   timer->mode       = params->timerMode;
   return(TimerP_OK);
}


static TimerP_Status TimerP_timer64InstanceInit(TimerP_Struct *timer, uint32_t id, TimerP_Fxn tickFxn, const TimerP_Params *params)
{
  TimerP_Status ret = TimerP_OK;
  uint32_t      key;
  int32_t       i;
  uint32_t      tempId = 0xffff;
  OsalRegisterIntrParams_t interruptRegParams;
  uint32_t      baseAddr, intNum;
  uint32_t      timerPAnyMask = (uint32_t)(TIMERP_ANY_MASK);

  if ((id != TimerP_ANY) && (id >= TimerP_numTimerDevices)) {
    ret = TimerP_FAILURE;
  }

  /* Get the timer Id */
  if (ret == TimerP_OK)
  {
    /* Set the available timer id mask to all */
    if (gTimerInitDone == 0U)
    {
        gTimerAnyMask  = TIMERP_AVAILABLE_MASK;
        gTimerInitDone = 1U;
    }

    timer->availMask = gTimerAnyMask;

    key = HwiP_disable();

    if (id == TimerP_ANY) {
        for (i = 0; i < TimerP_numTimerDevices; i++) {
            if ((timerPAnyMask & (1 << i)) &&
                (timer->availMask & (1 << i))) {
                 timer->availMask &= ~(1 << i);
                tempId = i;
                break;
            }
        }
    }
    else if (timer->availMask & (1 << id)) {
        timer->availMask &= ~(1 << id);
        tempId = id;
    }

    gTimerAnyMask = timer->availMask;

    HwiP_restore(key);

    if (tempId == 0xffff) {
      ret = TimerP_NOT_AVAILABLE;
    }
  }

  /* Initialize the timer state object */
  timer->id = tempId; /* Record the timer Id */
  if (ret == TimerP_OK) {
     baseAddr = TimerP_getTimerBaseAddr(tempId);
     ret = TimerP_timer64InitObj(timer, tickFxn, params);
  }

  /* Create the Hwi Funtion for the tick funtion */
  if (ret == TimerP_OK)
  {
    if (timer->tickFxn != NULL_PTR)
    {
      intNum          = timer->intNum;
      /* Initialize with defaults */
      Osal_RegisterInterrupt_initParams(&interruptRegParams);

      /* Populate the interrupt parameters */
      interruptRegParams.corepacConfig.arg=(uintptr_t) timer;
      interruptRegParams.corepacConfig.name=NULL_PTR;
      interruptRegParams.corepacConfig.isrRoutine=timer->tickFxn;
      interruptRegParams.corepacConfig.priority = 0x20U;
#if defined (__ARM_ARCH_7A__) && !defined(SOC_K2G)
      interruptRegParams.corepacConfig.triggerSensitivity =  OSAL_ARM_GIC_TRIG_TYPE_EDGE;
#endif

#if defined(_TMS320C6X)
      interruptRegParams.corepacConfig.corepacEventNum=timer->eventId; /* Event going in to CPU */
#endif
      interruptRegParams.corepacConfig.intVecNum=intNum; /* Host Interrupt vector */
      /* Register interrupts */
      Osal_RegisterInterrupt(&interruptRegParams,&(timer->hwi));

      if (timer->hwi == NULL_PTR)
      {
        ret = TimerP_ISR_HOOK_ERR;
      }
    }
    else
    {
      timer->hwi = NULL_PTR;
    }
  }

  /* timer post init */
  if (ret == TimerP_OK)
  {
     ret = TimerP_timer64DeviceCfg(timer, baseAddr);

     if (timer->startMode == TimerP_StartMode_AUTO)
        TimerP_start(timer);
  }

  return (ret);
}


/* Interface functions */

/* Default parameter initialization module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
void TimerP_Params_init(TimerP_Params *params)
{
    TIMOSAL_Assert((params == NULL_PTR));

    /* Set the default values */
    params->arg         = (void *) NULL_PTR;
    params->extfreqHi   = TimerP_USE_DEFAULT;
    params->extfreqLo   = TimerP_USE_DEFAULT;
    params->intfreqHi   = TimerP_USE_DEFAULT;
    params->intfreqLo   = TimerP_USE_DEFAULT;
    params->name        = NULL_PTR;
    params->period      = 0;
    params->runMode     = TimerP_RunMode_CONTINUOUS;
    params->startMode   = TimerP_StartMode_AUTO;
    params->periodType  = TimerP_PeriodType_MICROSECS;
    params->intNum      = TimerP_USE_DEFAULT;
    params->timerHalf   = TimerP_Timer64Half_DEFAULT;
    params->timerMode   = TimerP_Timer64Mode_UNCHAINED;

#if defined (_TMS320C6X)
    params->eventId     = TimerP_USE_DEFAULT;
#endif

    return;
}

/* Timer create module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Handle TimerP_create(int32_t id,
                            TimerP_Fxn tickFxn,
                            const TimerP_Params *params)

{
    uint32_t          i;
    uintptr_t         key;
    TimerP_Handle     ret_handle;
    key = HwiP_disable();

    for (i = 0u; i < OSAL_NONOS_CONFIGNUM_TIMER; i++)
    {
        if (gTimerStructs[i].used == false)
        {
            gTimerStructs[i].used = true;
            if (params != NULL_PTR)
            {
                gTimerStructs[i].id  = id;
            }

            break;
        }
    }
    HwiP_restore(key);

    if (i == OSAL_NONOS_CONFIGNUM_TIMER)
    {
        ret_handle = (TimerP_Handle) NULL_PTR;
    }
    else
    {
        /* Start the timer for that period/mode */
        ret_handle = ((TimerP_Handle)&gTimerStructs[i]);
    }

    if (ret_handle != (TimerP_Handle)NULL_PTR)
    {
      if (TimerP_timer64InstanceInit(&gTimerStructs[i], id, tickFxn, params) != TimerP_OK) {
        /* Free up the consumed timer memory */
        gTimerStructs[i].used = false;
        ret_handle = (TimerP_Handle) NULL_PTR;
      }
    }

    /* start timer if it is auto mode */
    if ((params->startMode == TimerP_StartMode_AUTO) &&
        (ret_handle != (TimerP_Handle)(NULL_PTR)) )
    {
       if(TimerP_start((TimerP_Handle)&gTimerStructs[i]) != TimerP_OK) {
          gTimerStructs[i].used = false;
          ret_handle = (TimerP_Handle)NULL_PTR;
       }
    }
    return (ret_handle);
}


/* Timer delete module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Status TimerP_delete(TimerP_Handle handle)
{
      /* Release or free the memory */
      uint32_t key;
      int index = ((uint32_t) handle - (uint32_t) gTimerStructs); /* struct subtraction */
      TimerP_Struct *timer = (TimerP_Struct *) handle;

      TIMOSAL_Assert((handle == NULL_PTR));

      /* clear the ISR that was set before */
      HwiP_delete(timer->hwi);

      key = HwiP_disable();
      gTimerStructs[index].used  = false;
      HwiP_restore(key);

      return (TimerP_OK);
}


/* Timer start module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Status TimerP_start(TimerP_Handle handle)
{
  uint32_t key;
  CSL_TmrHwSetup hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
  CSL_TmrMode    runMode = CSL_TMR_TIMMODE_DUAL_UNCHAINED;
  CSL_TmrEnamode timeCountMode;
  CSL_TmrHwControlCmd startCmd;
  TimerP_Struct *timer = (TimerP_Struct *) handle;
  TIMOSAL_Assert((handle == NULL_PTR));

  key = HwiP_disable();

  switch (timer->mode)
  {
      case TimerP_Timer64Mode_64BITGPTIMER:
        runMode = CSL_TMR_TIMMODE_GPT;
        break;
      case TimerP_Timer64Mode_CHAINED:
        runMode = CSL_TMR_TIMMODE_DUAL_CHAINED;
        break;
      case TimerP_Timer64Mode_UNCHAINED:
        runMode = CSL_TMR_TIMMODE_DUAL_UNCHAINED;
        break;
  }

  switch (timer->runMode)
  {
      case TimerP_RunMode_CONTINUOUS:
        timeCountMode = CSL_TMR_ENAMODE_CONT;
        break;
      case TimerP_RunMode_ONESHOT:
        timeCountMode = CSL_TMR_ENAMODE_ENABLE;
        break;
  }

  switch (timer->timerHalf)
  {
      case TimerP_Timer64Half_LOWER:
        startCmd = CSL_TMR_CMD_START_TIMLO;
        break;
      case TimerP_Timer64Half_UPPER:
        startCmd = CSL_TMR_CMD_START_TIMHI;
        break;
      default:
        startCmd = CSL_TMR_CMD_START64;
        break;
  }

  if (timer->hwi) {
      HwiP_clearInterrupt(timer->intNum);
      HwiP_enableInterrupt(timer->intNum);
  }

  /* Load the period values */
  if (timer->mode == TimerP_Timer64Mode_64BITGPTIMER) {
    /* Reset the Timer */
    CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_RESET64, NULL_PTR);

    /* Set the timer mode*/
    hwSetup.tmrTimerMode = runMode;
    CSL_tmrHwSetup(timer->hTmr, &hwSetup);

    /* Load the period register */
    CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_LOAD_PRDLO, (void *)&timer->period);

    /* Load the period register */
    CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_LOAD_PRDHI, (void *)&timer->prescalar);
  }
  else {
    if (timer->timerHalf == TimerP_Timer64Half_LOWER) {
      /* Reset the Timer */
      CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_RESET_TIMLO, NULL_PTR);

      /* Set the timer mode*/
      hwSetup.tmrTimerMode = runMode;
      CSL_tmrHwSetup(timer->hTmr, &hwSetup);

      /* Load the period register */
      CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_LOAD_PRDLO, (void *)&timer->period);
    }
    else {
      /* Reset the Timer */
      CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL_PTR);

      /* Set the timer mode*/
      hwSetup.tmrTimerMode = runMode;
      CSL_tmrHwSetup(timer->hTmr, &hwSetup);

      /* Load the period register */
      CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_LOAD_PRDHI, (void *)&timer->period);
    }
  }

  /* Start the timer in a given Mode. */
  CSL_tmrHwControl(timer->hTmr, startCmd, (void *)&timeCountMode);

  HwiP_restore(key);

  return (TimerP_OK);
}

/* Timer stop module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */

TimerP_Status TimerP_stop(TimerP_Handle handle)
{
  TimerP_Struct *timer = (TimerP_Struct *) handle;
  TIMOSAL_Assert((handle == NULL_PTR));

  if ((timer->mode == TimerP_Timer64Mode_CHAINED) || (timer->timerHalf == TimerP_Timer64Half_LOWER)) {
    /* Stop the Timer */
    CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_RESET_TIMLO, NULL_PTR);
  }
  else {
    /* Stop the Timer */
    CSL_tmrHwControl(timer->hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL_PTR);
  }

  if (timer->hwi) {
      HwiP_disableInterrupt(timer->intNum);
  }

  return(TimerP_OK);
}

/* Timer set micro seconds module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Status TimerP_setPeriodMicroSecs(TimerP_Handle handle, uint32_t microsecs)
{
  TimerP_Struct *timer = (TimerP_Struct *) handle;

  if (!TimerP_timer64SetMicroSeconds(timer, microsecs)) {
    return (TimerP_FAILURE);
  }
  else {
    return (TimerP_OK);
  }
}

/* Timer clear the interrupt module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 */
TimerP_Status TimerP_ClearInterrupt(TimerP_Handle handle)
{
    TimerP_Struct *timer = (TimerP_Struct *) handle;
    HwiP_clearInterrupt(timer->intNum);

    return (TimerP_OK);
}
#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
/* Below API is not supported for OMAPL13X SoCs for bare metal */
#else
/* Get time in micro seconds */
uint64_t TimerP_getTimeInUsecs(void)
{
    TimeStamp_Struct timestamp64;
    uint64_t         cur_ts, freq;
    int32_t             tsFreqKHz;

    osalArch_TimestampGet64(&timestamp64);

    /* Get the frequency of the timeStatmp provider */
    tsFreqKHz  = osalArch_TimeStampGetFreqKHz();

    cur_ts = ((uint64_t) timestamp64.hi << 32) | timestamp64.lo;
    freq = ((uint64_t) 0U << 32) | (tsFreqKHz);

    return ((cur_ts*1000u)/freq);
}
#endif
/* This would implement the gp timer on KeyStone devices */
