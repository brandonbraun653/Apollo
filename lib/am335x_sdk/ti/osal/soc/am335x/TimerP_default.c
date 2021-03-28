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
 *  ======== TimerP_default.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* This information is derived from sysbios timer implmentation for multiple SoCs */

TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "DMTimer2",        /* Timer Name */
     SOC_DMTIMER_2_REGS,  /* base address */
     68,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 1 */
  {
    "DMTimer3",        /* Timer Name */
     SOC_DMTIMER_3_REGS,  /* base address */
     69,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 2*/
  {
    "DMTimer4",        /* Timer Name */
     SOC_DMTIMER_4_REGS,  /* base address */
     92,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 3 */
  {
    "DMTimer5",        /* Timer Name */
     SOC_DMTIMER_5_REGS,  /* base address */
     93,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 4 */
  {
    "DMTimer6",        /* Timer Name */
     SOC_DMTIMER_6_REGS,  /* base address */
     94,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 5 */
  {
    "DMTimer7",        /* Timer Name */
     SOC_DMTIMER_7_REGS,  /* base address */
     95,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  }
};

/* Returns the default frquency lower 32 bits */
int32_t TimerP_getDefaultFreqLo(uint32_t timerId)
{
  uint32_t freq;
  freq = TIMERP_TIMER_FREQ_LO;
  return (freq);
}

/* Returns the default frquency higher 32 bits */
int32_t TimerP_getDefaultFreqHi(uint32_t timerId)
{
  uint32_t freq;
  freq = TIMERP_TIMER_FREQ_HI;
  return (freq);
}

/* Nothing past this point */
