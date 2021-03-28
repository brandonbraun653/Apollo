/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
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
 *  ======== TimerP_default.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* This information is derived from sysbios timer implmentation for multiple SoCs */
TimerP_timer64Default gTimer64InfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "Timer0",           /* Timer Name */
     CSL_TIMER_0_REGS,  /* base address */
     14,                /* Interrupt Number lo*/
     4,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65,                /* Event Id hi */
  },

  /* Timer ID 1 */
  {
    "Timer1",           /* Timer Name */
     CSL_TIMER_1_REGS,  /* base address */
     14,                /* Interrupt Number lo*/
     4,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65,                /* Event Id hi */
  },

  /* Timer ID 2 */
  {
    "Timer2",           /* Timer Name */
     CSL_TIMER_2_REGS,  /* base address */
     15,                /* Interrupt Number lo*/
      5,                 /* Interrupt Number hi*/
     66,                /* Event Id lo */
     67,                /* Event Id hi */
  },
  /* Timer ID 3 */
  {
    "Timer3",           /* Timer Name */
     CSL_TIMER_3_REGS,  /* base address */
     15,                /* Interrupt Number lo*/
     5,                 /* Interrupt Number hi*/
     68,                /* Event Id lo */
     69,                /* Event Id hi */
  }
}; /* SOC_C6657 */

/* Returns the default frquency lower 32 bits */
int32_t TimerP_getDefaultFreqLo(uint32_t timerId)
{
    /* return the same default frequency for all timer Ids */
    return(TIMERP_TIMER_FREQ_LO);
}

/* Returns the default frquency higher 32 bits */
int32_t TimerP_getDefaultFreqHi(uint32_t timerId)
{
    /* return the same default frequency for all timer Ids */
    return(TIMERP_TIMER_FREQ_HI);
}

/* Nothing past this point */
