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
#if defined (_TMS320C6X)
TimerP_timer64Default gTimer64InfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "Timer0",           /* Timer Name */
     CSL_TIMER_0_CFG_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     32,                /* Event Id lo */
     33,                /* Event Id hi */
  },
  /* Timer ID 1 */
  {
    "Timer1",           /* Timer Name */
     CSL_TIMER_1_CFG_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     34,                /* Event Id lo */
     35,                /* Event Id hi */
  }, 
   /* Timer ID 2 */
  {
    "Timer2",           /* Timer Name */
     CSL_TIMER_2_CFG_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     36,                /* Event Id lo */
     37,                /* Event Id hi */
  },
  /* Timer ID 3 */
  {
    "Timer3",           /* Timer Name */
     CSL_TIMER_3_CFG_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     38,                /* Event Id lo */
     39,                /* Event Id hi */
  }, 
  /* Timer ID 4 */
  {
    "Timer4",           /* Timer Name */
     CSL_TIMER_4_CFG_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     40,                /* Event Id lo */
     41,                /* Event Id hi */
  },
  /* Timer ID 5 */
  {
    "Timer5",           /* Timer Name */
     CSL_TIMER_5_CFG_REGS,              /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     42,                /* Event Id lo */
     43,                /* Event Id hi */
  },
  /* Timer ID 6 */
  {
    "Timer6",           /* Timer Name */
     (uint32_t) NULL,   /* base address, null means not supported */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }  
};
#else
TimerP_timer64Default gTimer64InfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "Timer0",           /* Timer Name */
     (uint32_t) NULL,   /* base address, null means not supported */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 1 */
  {
    "Timer1",           /* Timer Name */
     CSL_TIMER_1_CFG_REGS,  /* base address */
     50,                /* Interrupt Number lo*/
     51,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }, 
   /* Timer ID 2 */
  {
    "Timer2",           /* Timer Name */
     CSL_TIMER_2_CFG_REGS,  /* base address */
     52,                /* Interrupt Number lo*/
     53,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 3 */
  {
    "Timer3",           /* Timer Name */
     CSL_TIMER_3_CFG_REGS,  /* base address */
     54,                /* Interrupt Number lo*/
     55,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }, 
  /* Timer ID 4 */
  {
    "Timer4",           /* Timer Name */
     CSL_TIMER_4_CFG_REGS,  /* base address */
     56,                /* Interrupt Number lo*/
     57,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 5 */
  {
    "Timer5",           /* Timer Name */
     CSL_TIMER_5_CFG_REGS,              /* base address */
     58,                /* Interrupt Number lo*/
     59,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 6 */
  {
    "Timer6",           /* Timer Name */
     CSL_TIMER_6_CFG_REGS,              /* base address */
     60,                /* Interrupt Number lo*/
     61,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }  
};
#endif

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
