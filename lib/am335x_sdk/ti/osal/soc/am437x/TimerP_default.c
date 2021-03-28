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
 *  ======== TimerP_nonos_info.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* This information is derived from sysbios timer implmentation for multiple SoCs */

TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "DMTimer0",        /* Timer Name */
     SOC_DMTIMER0_REG,  /* base address */
     98,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 1 */
  {
    "DMTimer1",        /* Timer Name */
     SOC_DMTIMER1_1MS_REG,  /* base address */
     99,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },  
  /* Timer ID 2 */
  {
    "DMTimer2",        /* Timer Name */
     SOC_DMTIMER2_REG,  /* base address */
     100,              /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 3 */
  {
    "DMTimer3",        /* Timer Name */
     SOC_DMTIMER3_REG,  /* base address */
     101,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 4 */
  {
    "DMTimer4",        /* Timer Name */
     SOC_DMTIMER4_REG,  /* base address */
     124,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 5 */
  {
    "DMTimer5",        /* Timer Name */
     SOC_DMTIMER5_REG,  /* base address */
     125,              /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 6 */
  {
    "DMTimer6",        /* Timer Name */
     SOC_DMTIMER6_REG,  /* base address */
     126,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 7 */
  {
    "DMTimer7",        /* Timer Name */
     SOC_DMTIMER7_REG,  /* base address */
     127,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 8 */
  {
    "DMTimer8",        /* Timer Name */
     SOC_DMTIMER8_REG,  /* base address */
     163,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 9 */
  {
    "DMTimer9",        /* Timer Name */
     SOC_DMTIMER9_REG,  /* base address */
     164,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 10 */
  {
    "DMTimer10",        /* Timer Name */
     SOC_DMTIMER10_REG,  /* base address */
     165,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  },
  /* Timer ID 11 */
  {
    "DMTimer11",        /* Timer Name */
     SOC_DMTIMER11_REG,  /* base address */
     166,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id - Not Used*/
  }
};


/* Returns the default frquency lower 32 bits */
int32_t TimerP_getDefaultFreqLo(uint32_t timerId)
{
  uint32_t freq;

  if ((timerId == 0) || (timerId == 2)) {
    freq = TIMERP_TIMER_FREQ_LO1;
  }
  else {
    freq = TIMERP_TIMER_FREQ_LO2;
  }

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
