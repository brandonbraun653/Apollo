/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
 *  ======== delay.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* determine if it is first time to set the 32KHz FCLK timer */
static int32_t gTimerFirstTime  =  0;

/* Timer delay when 32KHz functional clock is driving the Timer, where 1 Tick = 1 ms*/
int32_t Delay_32kFClk(uintptr_t addr, uint32_t initCount, uint32_t rldCount, uint32_t nTicks)
{
  uintptr_t timerBase = addr;
  int32_t  baseTime, sampTime;
  uint32_t endTick = nTicks << 5;
  uint32_t tclrCfg = TIMER_TCLR_AR_MASK | TIMER_TCLR_ST_MASK;
  uint32_t intFlags= (TIMER_INT_TCAR_EN_FLAG | TIMER_INT_OVF_EN_FLAG | TIMER_INT_MAT_EN_FLAG);

  if (gTimerFirstTime == 0) {
    /* Disable the timer */
    TIMERDisable(timerBase);
    TIMERModeConfigure(timerBase, tclrCfg);

    /* Load the counter with the initial count value */
    TIMERCounterSet(timerBase, initCount);
    
    /* Load the load register with the reload count value */
    TIMERReloadSet(timerBase, rldCount);

    /* Disable all the Timer interrupts as there is no ISR registered */
    TIMERIntDisable(timerBase, intFlags);

    /* Enable the timer */
    TIMEREnable(timerBase);

    /* Indicate the first setup is done */
    gTimerFirstTime = 1;
  }

  /* Read the timer value */
  baseTime = TIMERCounterGet(timerBase);
  /* Every 32 cycle increment is 1ms */
  do {
    sampTime = TIMERCounterGet(timerBase);
  } while ((sampTime - baseTime) <= endTick);

  return(osal_OK);
}

/* Osal delay implementation for bare metal,
 * where nTicks is number of ticks in 1ms
 */
int32_t Osal_delay(uint32_t nTicks)
{
  /* Delay by number of ticks */
  return( Delay_32kFClk((uintptr_t) gOsal_HwAttrs.osalDelayTimerBaseAddr, TIMER_INITIAL_COUNT, TIMER_RLD_COUNT, nTicks));

}
/* nothing past this point */
