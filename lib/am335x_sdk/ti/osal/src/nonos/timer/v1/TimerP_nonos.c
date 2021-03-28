/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
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
 *  ======== TimerP_csl_nonos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/TimerP.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* DM Timer Implementation */
extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
#define TIMOSAL_Assert(expression) (Osal_DebugP_assert(((int32_t)((expression)?1:0)),\
                                                  __FILE__, __LINE__))

/* Local defines for the dm timer */
#define TIMERP_DM_TCLR_START_ONESHOT        (TIMER_ONESHOT_NOCMP_ENABLE)
#define TIMERP_DM_TCLR_START_CONTINUOUS     (TIMER_AUTORLD_CMP_ENABLE)
#define TIMERP_DM_TCLR_START_DYNAMIC        (0x43U)
#define TIMERP_DM_TCLR_STOP_MASK            (0xfffffffeU)
#define TIMERP_DM_TWPS_W_PEND_TMAR          (0x10U)
#define TIMERP_DM_TWPS_W_PEND_TLDR          (0x4U)
#define TIMERP_DM_TWPS_W_PEND_TCRR          (0x2U)
#define TIMERP_DM_TWPS_W_PEND_TCLR          (0x1U)
#define TIMERP_DM_IRQSTATUS_OVF_IT_FLAG     (0x2U)
#define TIMERP_DM_IRQSTATUS_MAT_IT_FLAG     (0x1U)
#define TIMERP_DM_TIOCP_CFG_SOFTRESET_FLAG  (0x1U)
#define TIMERP_DM_TSICR_POSTED              (0x4U)
#define TIMERP_DM_TSICR_READMODE            (0x8U)
#define TIMERP_DM_MAX_PERIOD                (0xffffffffU)


/* Local Timer Struct */
typedef struct TimerP_Struct_s
{
  bool     used;       /* In use or not status */
  uint32_t timerId;    /* timer Id */
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
  uint32_t rollovers;
  uint32_t savedCurrCount;
  uint32_t prevThreshold;
  uint32_t tmar;
  uint32_t tier;
  uint32_t twer;
  uint32_t tclr;
  uint32_t tsicr;
  uint32_t tiocpCfg;

}TimerP_Struct;

/* As static allocation is used, the following provides the structs
 * The TimerP_Struct pool servers to get an available timer
 * handle during timer create API call.
 */
TimerP_Struct gTimerStructs[OSAL_NONOS_CONFIGNUM_TIMER];
static        uint32_t    gTimerInitDone = 0U;
static        uint32_t    gTimerAnyMask;
#if defined (BUILD_MCU)
static        bool        gUpdateFlag = (bool)true;
#endif

/* external variables */
extern uint32_t  gOsalTimerAllocCnt, gOsalTimerPeak;

/* Local functions  */
static uint32_t TimerP_getTimerBaseAddr(uint32_t timer_id);
static void TimerP_dmTimerStub(uintptr_t arg);
static void  TimerP_dmTimerInitDevice(TimerP_Struct *timer, uint32_t baseAddr);
static bool TimerP_dmTimerCheckOverflow(uint32_t a, uint32_t b);
static bool TimerP_dmTimerSetMicroSeconds(TimerP_Struct *timer, uint32_t period);
static TimerP_Status TimerP_dmTimerDeviceCfg(TimerP_Struct *timer, uint32_t baseAddr);
static TimerP_Status TimerP_dmTimerInitObj(TimerP_Struct *timer, TimerP_Fxn tickFxn, const TimerP_Params *params);
static TimerP_Status TimerP_dmTimerInstanceInit(TimerP_Struct *timer, uint32_t id, TimerP_Fxn tickFxn, const TimerP_Params *params);

/*
 * This private function returns the base address of the timer based on
 * the ID passed in.
 */
static uint32_t TimerP_getTimerBaseAddr(uint32_t timer_id)
{
    uint32_t addr;

    if (timer_id < TimerP_numTimerDevices) {
#if defined (BUILD_MCU)
        if (gUpdateFlag == (bool)true)
        {
            TimerP_updateDefaultInfoTbl();
            gUpdateFlag = (bool)false;
        }
#endif
      addr = (uint32_t) gDmTimerPInfoTbl[timer_id].baseAddr;
    }
    else {
      addr = (uint32_t)0U;
    }
    return (addr);
}

/*
 * This private function is a stub function for the timer ISR
 * function that is registered from the application
 */
static void TimerP_dmTimerStub(uintptr_t arg)
{
  TimerP_Struct *timer = (TimerP_Struct *) arg;
  uint32_t baseAddr = TimerP_getTimerBaseAddr(timer->timerId);

  /* Disable the Timer interrupts */
  (void)TIMERIntDisable(baseAddr, TIMER_INT_OVF_EN_FLAG);

  /* acknowledge the interrupt */
  (void)TIMERIntStatusClear(baseAddr, timer->tier);

  /* call the user's ISR */
  timer->tickFxn((uintptr_t)timer->arg);

   /* Enable the Timer interrupts */
  (void)TIMERIntEnable(baseAddr, TIMER_INT_OVF_EN_FLAG);
}

/*
 * This priviate function initializes the timer counter, period and compare
 * registers
 */
static void  TimerP_dmTimerInitDevice(TimerP_Struct *timer, uint32_t baseAddr)
{
  uint32_t key, status;
  uint32_t tcrr =0, tldr =0;

  key = (uint32_t)HwiP_disable();

  (void)TIMERDisable(baseAddr);
  do {
    status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCLR);
  } while (status != (uint32_t) 0u);

  (void)TIMERCounterSet(baseAddr, tcrr);

   do {
    status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
  } while (status != (uint32_t) 0u);

  (void)TIMERReloadSet(baseAddr, tldr);

  do {
    status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TLDR);
  } while (status != (uint32_t) 0u);


  HwiP_restore(key);
}

/*
 * This priviate function checks if there is any overflow in
 * timer period computations
 */
static bool TimerP_dmTimerCheckOverflow(uint32_t a, uint32_t b)
{
  return ((b > 0u) && (a > (TimerP_MAX_PERIOD/b)));
}

/*
 * This is a private function to set the period of the timer
 * register for a specified micro second value
 */
static bool TimerP_dmTimerSetMicroSeconds(TimerP_Struct *timer, uint32_t period)
{
    uint64_t  counts;
    uint32_t  prdCounts;
    uint32_t  freqKHz;
    uint32_t  roundUp;
    uint32_t  baseAddr = TimerP_getTimerBaseAddr(timer->timerId);
    uint32_t  status;
    bool retVal=(bool)true;

    (void)TimerP_stop(timer);

    roundUp = ((timer->freqLo % 1000U) >= 500U) ? 1U : 0U;

    freqKHz = (timer->freqLo / 1000U) + roundUp;
    if (TimerP_dmTimerCheckOverflow(freqKHz, period/1000U)) {
            retVal = (bool)false;
    }
    else
    {
    counts = ((uint64_t)freqKHz * (uint64_t)period) / (uint64_t)1000U;
    if (counts > 0xffffffffU) {
        retVal = (bool)false;
    }
    else
    {
       prdCounts = (uint32_t)(counts - (uint32_t) 1u);

       timer->period = prdCounts;
       timer->periodType = (uint32_t)TimerP_PeriodType_COUNTS;

       if ((timer->runMode == (uint32_t)TimerP_RunMode_CONTINUOUS) ||
         (timer->runMode == (uint32_t)TimerP_RunMode_ONESHOT)) 
        {
           (void)TIMERCounterSet(baseAddr, TimerP_MAX_PERIOD - prdCounts);

           do {
             status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
           } while (status != (uint32_t) 0u);

           (void)TIMERReloadSet(baseAddr,TimerP_MAX_PERIOD - prdCounts);
           do {
             status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TLDR);
           } while (status != (uint32_t) 0u);
        }
        else
        {
          (void)TIMERCounterSet(baseAddr, 0u);
          do {
          status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
          } while (status != (uint32_t) 0u);

          (void)TIMERCompareSet(baseAddr, prdCounts);
          do {
          status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TMAR);
          } while (status != (uint32_t) 0u);
       }
     }
   }
    return(retVal);
}

/*
 * Thi is a private function to configure the timer registers for a given timer
 * period
 */
static TimerP_Status TimerP_dmTimerDeviceCfg(TimerP_Struct *timer, uint32_t baseAddr)
{
    uint32_t key, tsicr;
    uint32_t status;
    TimerP_Status retVal=TimerP_OK;
    /* initialize the timer */
    TimerP_dmTimerInitDevice(timer, baseAddr);

    key = (uint32_t)HwiP_disable();

    /*if doing soft reset: do it first before setting other flags */
    if ((timer->tiocpCfg & TIMERP_DM_TIOCP_CFG_SOFTRESET_FLAG) > 0U) {
     (void)TIMERReset(baseAddr);
    }

    HW_WR_REG32(baseAddr + TIMER_TIOCP_CFG,
                 (~(uint32_t)TIMER_TIOCP_CFG_SOFTRESET_SOFTRESET_VALUE_1));

    /*xfer 'posted' setting if not current */
    tsicr = HW_RD_REG32(baseAddr + TIMER_TSICR);

    if ((timer->tsicr & TIMERP_DM_TSICR_POSTED) > 0U) {
      if ((tsicr & TIMERP_DM_TSICR_POSTED) == 0U) {
          (void)TIMERPostedModeConfig(baseAddr, (tsicr | TIMERP_DM_TSICR_POSTED));
      }
    }
    else {
        if ((tsicr & TIMERP_DM_TSICR_POSTED) != 0U) {
          (void)TIMERPostedModeConfig(baseAddr, (tsicr & (~(uint32_t)TIMERP_DM_TSICR_POSTED)));
        }
    }

    /* xfer 'readmode' setting if not current */
    tsicr = HW_RD_REG32(baseAddr + TIMER_TSICR);

    if ((timer->tsicr & TIMERP_DM_TSICR_READMODE)>0U) {
        if ((tsicr & TIMERP_DM_TSICR_READMODE) == 0U) {
            (void)TIMERReadModeConfig(baseAddr, (tsicr | TIMERP_DM_TSICR_READMODE));
        }
    }
    else {
        if ((tsicr & TIMERP_DM_TSICR_READMODE) != 0U) {
          (void)TIMERReadModeConfig(baseAddr, (tsicr | (~(uint32_t)TIMERP_DM_TSICR_READMODE)));
        }
    }

    /* set the period */
    if (timer->periodType == (uint32_t)TimerP_PeriodType_MICROSECS) {
        if (!TimerP_dmTimerSetMicroSeconds(timer, timer->period)) {
            HwiP_restore(key);
            retVal = TimerP_FAILURE;
        }
    }
    else {
        if ((timer->runMode == (uint32_t)TimerP_RunMode_CONTINUOUS) ||
            (timer->runMode == (uint32_t)TimerP_RunMode_ONESHOT)) {

            (void)TIMERCounterSet(baseAddr, TimerP_MAX_PERIOD - timer->period);
            do {
              status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
            } while (status != (uint32_t) 0u);

            (void)TIMERReloadSet(baseAddr, TimerP_MAX_PERIOD - timer->period);
            do {
              status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TLDR);
            } while (status != (uint32_t) 0u);

        }
        else {
            (void)TIMERCounterSet(baseAddr,0);
            do {
              status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
            } while (status != (uint32_t) 0u);


            (void)TIMERCompareSet(baseAddr, timer->period);
            do {
              status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TMAR);
            } while (status != (uint32_t) 0u);


        }
    }
   
   if(retVal != TimerP_FAILURE)
   {
    if ((timer->runMode == (uint32_t)TimerP_RunMode_CONTINUOUS) ||
        (timer->runMode == (uint32_t)TimerP_RunMode_ONESHOT)) {
        (void)TIMERCompareSet(baseAddr, timer->tmar);
        do {
          status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TMAR);
        } while (status != (uint32_t) 0u);

    }
    /* Enable the Timer Wakeup events represented by wakeFlags */
    HW_WR_REG32(baseAddr + TIMER_IRQWAKEEN, timer->twer);
    HW_WR_REG32(baseAddr + TIMER_IRQENABLE_SET, timer->tier);
    HW_WR_REG32(baseAddr + TIMER_TCLR, timer->tclr);
    do {
      status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCLR);
    } while (status != (uint32_t) 0u);

     HwiP_restore(key);
   } 
    return (retVal);
}

/*
 * This is a private function to initialize the timer counter, period and compare
 * registers before starting the timers
 */
static TimerP_Status TimerP_dmTimerInitObj(TimerP_Struct *timer, TimerP_Fxn tickFxn, const TimerP_Params *params)
{
  uint8_t softreset = 1u, emufree = 0u, idlemode = 0u;
  uint8_t mat_it_ena =0u, ovf_it_ena = 1u, tcar_it_ena =0u;
  uint8_t mat_wup_ena =0u, ovf_wup_ena = 0u, tcar_wup_ena =0u;


  timer->tickFxn = tickFxn;

  timer->tiocpCfg = (uint32_t)( ((uint32_t)softreset << 0U) |
                                ((uint32_t)emufree   << 1U) |
                                ((uint32_t)idlemode  << 2U));

  timer->tier     = (uint32_t)( ((uint32_t)mat_it_ena << 0U) |
                                ((uint32_t)ovf_it_ena << 1U) |
                                ((uint32_t)tcar_it_ena << 2U));

  timer->twer     = (uint32_t)( ((uint32_t)mat_wup_ena << 0U) |
                                ((uint32_t)ovf_wup_ena << 1U) |
                                ((uint32_t)tcar_wup_ena << 2U));

  timer->tclr = 0u;

  timer->tsicr = 0u;

  /*
   * Update the default initializations to user configured values
   */
  if ( params->extfreqLo != TimerP_USE_DEFAULT) {
    timer->freqLo            =  (uint32_t)params->extfreqLo;
  }
  else  {
    if (params->intfreqLo != TimerP_USE_DEFAULT)  {
      timer->freqLo            = (uint32_t)params->intfreqLo;
    }
    else {
      timer->freqLo            =  (uint32_t)TimerP_getDefaultFreqLo(timer->timerId);
    }
  }

  if ( params->extfreqHi != TimerP_USE_DEFAULT) {
    timer->freqHi            =  (uint32_t)params->extfreqHi;
  }
  else  {
    if (params->intfreqHi != TimerP_USE_DEFAULT)  {
      timer->freqHi          = (uint32_t)params->intfreqHi;
    }
    else {
      timer->freqHi          =  (uint32_t)TimerP_getDefaultFreqHi(timer->timerId);
    }
  }

  if ( params->period != 0u) {
    timer->period                = params->period;
  }
  else  {
    timer->period                = 0u;
  }

   if ( params->arg != NULL_PTR) {
     timer->arg                   = params->arg;
   }

   if ( params->intNum != TimerP_USE_DEFAULT) {
     timer->intNum = params->intNum;
   }
   else {
     timer->intNum = gDmTimerPInfoTbl[timer->timerId].intNum;
   }

#if defined (_TMS320C6X)
   if ( params->eventId != TimerP_USE_DEFAULT) {
     timer->eventId = (uint32_t)params->eventId;
   }
   else {
     timer->eventId = (uint32_t)gDmTimerPInfoTbl[timer->timerId].eventId;
   }
#endif

   timer->periodType = params->periodType;
   timer->startMode  = params->startMode;
   timer->runMode    = params->runMode;
   return(TimerP_OK);
}

/*
 * This is a private function to initialize the timer instance, that sets up the timer ISR to
 * a specified timer id and sets up the timer compare, counter and period registers
 */
static TimerP_Status TimerP_dmTimerInstanceInit(TimerP_Struct *timer, uint32_t id, TimerP_Fxn tickFxn, const TimerP_Params *params)
{
  TimerP_Status ret = TimerP_OK;
  uint32_t      key;
  uint32_t      i;
  uint32_t      tempId = 0xffffu;
  OsalRegisterIntrParams_t interruptRegParams;
  uint32_t      baseAddr;
  int32_t       intNum;
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

    key = (uint32_t)HwiP_disable();

    if (id == TimerP_ANY) {
        for (i = 0u; i < TimerP_numTimerDevices; i++) {
            uint32_t shift, nshift;
            shift  = ((uint32_t) 1u) << i;
            nshift = ~shift;
            if (((timerPAnyMask    & shift) != (uint32_t) 0u ) &&
                ((timer->availMask & shift) != (uint32_t) 0u )) {
                 timer->availMask &= nshift;
                 tempId = i;
                 break;
            }
        }
    }
    else
    {
	  if ((timer->availMask & ((uint32_t)1u << id)) > 0U) 
	  {
        uint32_t shift, nshift;
        shift  = ((uint32_t) 1u) << id;
        nshift = ~shift;
        timer->availMask &= nshift;
        tempId = id;
      }
    }  

    gTimerAnyMask =  timer->availMask;

#if defined (BUILD_MCU)
    tempId = TimerP_mapId(tempId);
#endif

    /* Initialize the timer state object */
    timer->timerId = tempId; /* Record the timer Id */
    baseAddr = TimerP_getTimerBaseAddr(timer->timerId);

    HwiP_restore(key);

    if (tempId == 0xffffU) {
      ret = TimerP_NOT_AVAILABLE;
    }
  }

  /* Initialize the timer state object */
  if (ret == TimerP_OK) {
    ret = TimerP_dmTimerInitObj(timer, tickFxn, params);
  }

  /* Create the Hwi Funtion for the tick funtion */
  if (ret == TimerP_OK)
  {
    if (timer->tickFxn != (TimerP_Fxn) NULL_PTR)
    {
      intNum          = timer->intNum;
      /* Initialize with defaults */
      Osal_RegisterInterrupt_initParams(&interruptRegParams);

      /* Populate the interrupt parameters */
      interruptRegParams.corepacConfig.arg=(uintptr_t) timer;
      interruptRegParams.corepacConfig.name=(char *) NULL_PTR;
      interruptRegParams.corepacConfig.isrRoutine=TimerP_dmTimerStub;

#if defined (__ARM_ARCH_7A__) || defined (__aarch64__) || defined (__TI_ARM_V7R4__)
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
      interruptRegParams.corepacConfig.triggerSensitivity =  (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
      interruptRegParams.corepacConfig.priority = 0x20U;
#else
      interruptRegParams.corepacConfig.triggerSensitivity =  (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_EDGE;
#endif
#endif

#if defined(_TMS320C6X)
      interruptRegParams.corepacConfig.corepacEventNum=(int32_t)timer->eventId; /* Event going in to CPU */
#endif
      interruptRegParams.corepacConfig.intVecNum=intNum; /* Host Interrupt vector */

      /* Register interrupts */
      (void)Osal_RegisterInterrupt(&interruptRegParams,&(timer->hwi));

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
     ret = TimerP_dmTimerDeviceCfg(timer, baseAddr);

     if (timer->startMode == (uint32_t)TimerP_StartMode_AUTO) {
         (void)TimerP_start(timer);
     }
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

    if(params != NULL_PTR) {
      /* Set the default values */
      params->arg         = NULL_PTR;
      params->extfreqHi   = TimerP_USE_DEFAULT;
      params->extfreqLo   = TimerP_USE_DEFAULT;
      params->intfreqHi   = TimerP_USE_DEFAULT;
      params->intfreqLo   = TimerP_USE_DEFAULT;
      params->name        = (char *) NULL_PTR;
      params->period      = 0;
      params->runMode     = (uint32_t)TimerP_RunMode_CONTINUOUS;
      params->startMode   = (uint32_t)TimerP_StartMode_AUTO;
      params->periodType  = (uint32_t)TimerP_PeriodType_MICROSECS;
      params->intNum      = (int32_t)TimerP_USE_DEFAULT;
#if defined (_TMS320C6X)
    params->eventId     = TimerP_USE_DEFAULT;
#endif
    }  
    return;
}

/* Timer create module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Handle TimerP_create(int32_t id,
                            TimerP_Fxn tickFxn,
                            const TimerP_Params *inParams)

{
    uint32_t          i;
    uintptr_t         key;
    TimerP_Handle     ret_handle;
    TimerP_Params    params;

    if (inParams != NULL_PTR)
    {
        params = *inParams;
    }
    else
    {
        TimerP_Params_init(&params);
    }

    key = HwiP_disable();

    for (i = 0; i < OSAL_NONOS_CONFIGNUM_TIMER; i++)
    {
        if (gTimerStructs[i].used == (bool)false)
        {
            gTimerStructs[i].used = (bool)true;

            /* Update statistics */
            gOsalTimerAllocCnt++;
            if (gOsalTimerAllocCnt > gOsalTimerPeak)
            {
                gOsalTimerPeak = gOsalTimerAllocCnt;
            }

            gTimerStructs[i].timerId  = (uint32_t)id;

            break;
        }
    }
    HwiP_restore(key);

    if (i == OSAL_NONOS_CONFIGNUM_TIMER)
    {
        ret_handle = NULL_PTR;
    }
    else
    {
        /* Start the timer for that period/mode */
        ret_handle = ((TimerP_Handle)&gTimerStructs[i]);
    }

    if (ret_handle != NULL_PTR)
    {
      if (TimerP_dmTimerInstanceInit(&gTimerStructs[i], (uint32_t) id, tickFxn, &params) != TimerP_OK) {
        /* Free up the consumed timer memory */
        gTimerStructs[i].used = (bool)false;
        ret_handle = NULL_PTR;
      }
    }

    /* start timer if it is auto mode */
    if ((params.startMode == (uint32_t)TimerP_StartMode_AUTO) &&
        (ret_handle != NULL_PTR) )
    {
       if(TimerP_start((TimerP_Handle)&gTimerStructs[i]) != TimerP_OK) {
          gTimerStructs[i].used = (bool)false;
          ret_handle = NULL_PTR;
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
    uint32_t index = (uint32_t)(( ((uintptr_t) handle) - ((uintptr_t) gTimerStructs) )/sizeof(TimerP_Struct)); /* struct subtraction */
    TimerP_Status ret = TimerP_OK;
    TimerP_Struct *timer = (TimerP_Struct *) handle;
    TIMOSAL_Assert((handle == NULL_PTR));

    if(timer != NULL_PTR)
    {
      /* clear the ISR that was set before */
      (void)HwiP_delete(timer->hwi);

      key = (uint32_t)HwiP_disable();
      gTimerStructs[index].used = (bool)false;
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


/* Timer start module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Status TimerP_start(TimerP_Handle handle)
{
  uint32_t  key, runMode, status;
  TimerP_Struct *timer = (TimerP_Struct *) handle;
  uint32_t max_period = (uint32_t) 0xffffffffU;
  TimerP_Status retVal = TimerP_OK;
  
  uint32_t baseAddr = TimerP_getTimerBaseAddr(timer->timerId);

  if (baseAddr == 0U) {
    retVal = TimerP_NOT_AVAILABLE;
  }
  else
  {

  key = (uint32_t)HwiP_disable();

  (void)TimerP_stop(handle);

  if ((timer->runMode == (uint32_t)TimerP_RunMode_CONTINUOUS) ||
      (timer->runMode == (uint32_t)TimerP_RunMode_ONESHOT)) {
    (void)TIMERCounterSet(baseAddr, (max_period - timer->period));             /* set timer count back to period value */
  }
  else {
    (void)TIMERCounterSet(baseAddr, 0);             /* set timer count back to initial value */
    (void)TIMERCompareSet(baseAddr, timer->period); /* set threshold for first interrupt */

    timer->prevThreshold  = 0;    /* init previous threshold */
    timer->rollovers      = 0;    /* init total rollover count */
    timer->savedCurrCount = 0;
  }

  do {
    status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCRR);
  } while (status != (uint32_t) 0u);

  if(timer->hwi != NULL_PTR) {
    HwiP_clearInterrupt(timer->intNum);
    HwiP_enableInterrupt(timer->intNum);
  }

  if (timer->runMode == (uint32_t)TimerP_RunMode_CONTINUOUS) {
      runMode = TIMERP_DM_TCLR_START_CONTINUOUS;
  }
  else if (timer->runMode == (uint32_t)TimerP_RunMode_ONESHOT) {
      runMode = TIMERP_DM_TCLR_START_ONESHOT;
  }
  else {
      runMode = TIMERP_DM_TCLR_START_DYNAMIC;
  }

  (void)TIMERModeConfigure(baseAddr, runMode);

  do {
    status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCLR);
  } while (status != (uint32_t) 0u);

  (void)TIMEREnable(baseAddr);

  HwiP_restore(key);
  }
  return (retVal);
}

/* Timer stop module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */

TimerP_Status TimerP_stop(TimerP_Handle handle)
{
  uint32_t  tisr, status;
  TimerP_Struct *timer = (TimerP_Struct *) handle;
  TimerP_Status retVal = TimerP_OK;
  
  uint32_t baseAddr = TimerP_getTimerBaseAddr(timer->timerId);

  if (baseAddr == 0U) {
    retVal = TimerP_NOT_AVAILABLE;
  }
  else
  {
    (void)TIMERDisable(baseAddr);

    do {
      status = (TIMERWritePostedStatusGet(baseAddr) & TIMERP_DM_TWPS_W_PEND_TCLR);
    } while (status != (uint32_t) 0u);


    tisr = TIMERIntStatusGet(baseAddr);

    if(tisr > 0U) {
    /* Clear all pending interrupts */
    (void)TIMERIntStatusClear(baseAddr, tisr);
    }
  }
  return(retVal);
}

/* Timer set micro seconds module function
 * more details on the documentation of this interface
 * function can be found in the TimerP.h interface
 * header file */
TimerP_Status TimerP_setPeriodMicroSecs(TimerP_Handle handle, uint32_t microsecs)
{
  TimerP_Struct *timer = (TimerP_Struct *) handle;
  TimerP_Status retVal = TimerP_OK;
  if (!TimerP_dmTimerSetMicroSeconds(timer, microsecs)) {
    retVal = TimerP_FAILURE;
  }
  return (retVal);
}

/* Get time in micro seconds */
uint64_t TimerP_getTimeInUsecs(void)
{
    TimeStamp_Struct timestamp64;
    uint64_t         cur_ts, freq;
    uint32_t             tsFreqKHz;

    /* Get the timestamp */
    osalArch_TimestampGet64(&timestamp64);

    /* Get the frequency of the timeStatmp provider */
    tsFreqKHz  = (uint32_t)osalArch_TimeStampGetFreqKHz();

    cur_ts = ((uint64_t) timestamp64.hi << 32U) | timestamp64.lo;
    freq = (uint64_t) (tsFreqKHz);

    return ((cur_ts*1000u)/freq);
}
/* This file implements the DM timer osal functions on AM devices */
