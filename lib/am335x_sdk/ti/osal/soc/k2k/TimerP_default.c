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
     CSL_TIMER_0_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  },
  /* Timer ID 1 */
  {
    "Timer1",           /* Timer Name */
     CSL_TIMER_1_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  }, 
   /* Timer ID 2 */
  {
    "Timer2",           /* Timer Name */
     CSL_TIMER_2_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  },
  /* Timer ID 3 */
  {
    "Timer3",           /* Timer Name */
     CSL_TIMER_3_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  }, 
  /* Timer ID 4 */
  {
    "Timer4",           /* Timer Name */
     CSL_TIMER_4_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  },
  /* Timer ID 5 */
  {
    "Timer5",           /* Timer Name */
     CSL_TIMER_5_REGS,              /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  }, 
  /* Timer ID 6 */
  {
    "Timer6",           /* Timer Name */
     CSL_TIMER_6_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  },
  /* Timer ID 7*/
  {
    "Timer7",           /* Timer Name */
     CSL_TIMER_7_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     64,                /* Event Id lo */
     65                 /* Event Id hi */
  },  
  /* Timer ID 8 */
  {
    "Timer8",           /* Timer Name */
     CSL_TIMER_8_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     66,                /* Event Id lo */
     67                 /* Event Id hi */
  },

  /* Timer ID 9 */
  {
    "Timer9",           /* Timer Name */
     CSL_TIMER_9_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     68,                /* Event Id lo */
     69                 /* Event Id hi */
  },

  /* Timer ID 10 */
  {
    "Timer10",           /* Timer Name */
     CSL_TIMER_10_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     70,                /* Event Id lo */
     71                 /* Event Id hi */
  },
  /* Timer ID 11 */
  {
    "Timer11",           /* Timer Name */
     CSL_TIMER_11_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     72,                /* Event Id lo */
     73                 /* Event Id hi */
  },
  /* Timer ID 12 */
  {
    "Timer12",           /* Timer Name */
     (uint32_t) NULL,    /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     27,                /* Event Id lo */
     28                 /* Event Id hi */
  },
  /* Timer ID 13 */
  {
    "Timer13",           /* Timer Name */
     CSL_TIMER_13_REGS,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     27,                /* Event Id lo */
     28                 /* Event Id hi */
  },
  /* Timer ID 14 */
  {
    "Timer14",           /* Timer Name */
     CSL_TIMER_14_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     78,                  /* Event Id lo */
     79                   /* Event Id hi */
  },
  /* Timer ID 15 */
  {
    "Timer15",           /* Timer Name */
     CSL_TIMER_15_REGS,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                /* Interrupt Number lo*/
     OSAL_REGINT_INTVEC_EVENT_COMBINER,                 /* Interrupt Number hi*/
     80,                /* Event Id lo */
     81                 /* Event Id hi */
  }
};
#else
TimerP_timer64Default gTimer64InfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "Timer0",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 1 */
  {
    "Timer1",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }, 
   /* Timer ID 2 */
  {
    "Timer2",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 3 */
  {
    "Timer3",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }, 
  /* Timer ID 4 */
  {
    "Timer4",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 5 */
  {
    "Timer5",           /* Timer Name */
     (uint32_t) NULL,              /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  }, 
  /* Timer ID 6 */
  {
    "Timer6",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 7*/
  {
    "Timer7",           /* Timer Name */
     (uint32_t) NULL,  /* base address */
     -1,                /* Interrupt Number lo*/
     -1,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },  
  /* Timer ID 8 */
  {
    "Timer8",           /* Timer Name */
     CSL_TIMER_8_REGS,  /* base address */
     128,                /* Interrupt Number lo*/
     129,                /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },

  /* Timer ID 9 */
  {
    "Timer9",           /* Timer Name */
     CSL_TIMER_9_REGS,  /* base address */
     130,                /* Interrupt Number lo*/
     131,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },

  /* Timer ID 10 */
  {
    "Timer10",           /* Timer Name */
     CSL_TIMER_10_REGS,  /* base address */
     132,                /* Interrupt Number lo*/
     133,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 11 */
  {
    "Timer11",           /* Timer Name */
     CSL_TIMER_11_REGS,  /* base address */
     134,                /* Interrupt Number lo*/
     135,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 12 */
  {
    "Timer12",           /* Timer Name */
     CSL_TIMER_11_REGS,  /* base address */
     136,                /* Interrupt Number lo*/
     137,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 13 */
  {
    "Timer13",           /* Timer Name */
     CSL_TIMER_13_REGS,  /* base address */
     138,                /* Interrupt Number lo*/
     139,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 14 */
  {
    "Timer14",           /* Timer Name */
     CSL_TIMER_14_REGS,  /* base address */
     140,                /* Interrupt Number lo*/
     141,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 15 */
  {
    "Timer15",           /* Timer Name */
     CSL_TIMER_15_REGS,  /* base address */
     142,                /* Interrupt Number lo*/
     143,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 16 */
  {
    "Timer16",           /* Timer Name */
     CSL_TIMER_16_REGS,  /* base address */
     144,                /* Interrupt Number lo*/
     145,                 /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 17 */
  {
    "Timer17",           /* Timer Name */
     CSL_TIMER_17_REGS,  /* base address */
     146,                /* Interrupt Number lo*/
     147,                /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 18 */
  {
    "Timer18",           /* Timer Name */
     CSL_TIMER_18_REGS,  /* base address */
     148,                /* Interrupt Number lo*/
     149,                /* Interrupt Number hi*/
     -1,                /* Event Id lo */
     -1,                /* Event Id hi */
  },
  /* Timer ID 19 */
  {
    "Timer19",           /* Timer Name */
     CSL_TIMER_19_REGS,  /* base address */
     150,                /* Interrupt Number lo*/
     151,                /* Interrupt Number hi*/
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
