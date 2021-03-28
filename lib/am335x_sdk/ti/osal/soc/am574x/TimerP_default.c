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
 *  ======== TimerP_default.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* This information is derived from sysbios timer implmentation for multiple SoCs */
#if defined (_TMS320C6X)
TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "GPTimer1",        /* Timer Name */
     SOC_TIMER1_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,/* Interrupt Number */
     63,               /* Event Id */
  },
  /* Timer ID 1 */
  {
    "GPTimer2",        /* Timer Name */
     SOC_TIMER2_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     64,               /* Event Id */
  },
  /* Timer ID 2 */
  {
    "GPTimer3",        /* Timer Name */
     SOC_TIMER3_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     65,               /* Event Id */
  },
  /* Timer ID 3 */
  {
    "GPTimer4",        /* Timer Name */
     SOC_TIMER4_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     66,               /* Event Id */
  },
  /* Timer ID 4 */
  {
    "GPTimer5",        /* Timer Name */
     SOC_TIMER5_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     67,               /* Event Id */
  },
  /* Timer ID 5 */
  {
    "GPTimer6",        /* Timer Name */
     SOC_TIMER6_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     68,               /* Event Id */
  },
  /* Timer ID 6 */
  {
    "GPTimer7",        /* Timer Name */
     SOC_TIMER7_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,/* Interrupt Number */
     69,               /* Event Id */
  },
  /* Timer ID 7 */
  {
    "GPTimer8",        /* Timer Name */
     SOC_TIMER8_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,/* Interrupt Number */
     70,               /* Event Id */
  },
  /* Timer ID 8 */
  {
    "GPTimer9",        /* Timer Name */
     SOC_TIMER9_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     71,               /* Event Id */
  },
  /* Timer ID 9 */
  {
    "GPTimer10",        /* Timer Name */
     SOC_TIMER10_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     72,               /* Event Id */
  },
  /* Timer ID 10 */
  {
    "GPTimer11",        /* Timer Name */
     SOC_TIMER11_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     73,               /* Event Id */
  },
  /* Timer ID 11 */
  {
    "GPTimer12",        /* Timer Name */
     SOC_TIMER12_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     75,               /* Event Id */
  },
  /* Timer ID 12 */
  {
    "GPTimer13",        /* Timer Name */
     SOC_TIMER13_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     76,               /* Event Id */
  },
  /* Timer ID 13 */
  {
    "GPTimer14",        /* Timer Name */
     SOC_TIMER14_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     77,               /* Event Id */
  },
  /* Timer ID 14 */
  {
    "GPTimer15",        /* Timer Name */
     SOC_TIMER15_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     78,               /* Event Id */
  },
  /* Timer ID 15 */
  {
    "GPTimer16",        /* Timer Name */
     SOC_TIMER16_BASE,  /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER, /* Interrupt Number */
     81,               /* Event Id */
  }
};
#elif defined (__TI_ARM_V7M4__)
TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "GPTimer1",        /* Timer Name */
     SOC_TIMER1_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 1 */
  {
    "GPTimer2",        /* Timer Name */
     SOC_TIMER2_BASE,  /* base address */
     53,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 2 */
  {
    "GPTimer3",        /* Timer Name */
     SOC_TIMER3_BASE,  /* base address */
     54,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 3 */
  {
    "GPTimer4",        /* Timer Name */
     SOC_TIMER4_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 4 */
  {
    "GPTimer5",        /* Timer Name */
     SOC_TIMER5_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 5 */
  {
    "GPTimer6",        /* Timer Name */
     SOC_TIMER6_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 6 */
  {
    "GPTimer7",        /* Timer Name */
     SOC_TIMER7_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 7 */
  {
    "GPTimer8",        /* Timer Name */
     SOC_TIMER8_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 8 */
  {
    "GPTimer9",        /* Timer Name */
     SOC_TIMER9_BASE,  /* base address */
     55,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 9 */
  {
    "GPTimer10",        /* Timer Name */
     SOC_TIMER10_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 10 */
  {
    "GPTimer11",        /* Timer Name */
     SOC_TIMER11_BASE,  /* base address */
     56,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 11 */
  {
    "GPTimer12",        /* Timer Name */
     SOC_TIMER12_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 12 */
  {
    "GPTimer13",        /* Timer Name */
     SOC_TIMER13_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 13 */
  {
    "GPTimer14",        /* Timer Name */
     SOC_TIMER14_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 14 */
  {
    "GPTimer15",        /* Timer Name */
     SOC_TIMER15_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 15 */
  {
    "GPTimer16",        /* Timer Name */
     SOC_TIMER16_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  }
};
#else
TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "GPTimer1",        /* Timer Name */
     SOC_TIMER1_BASE,  /* base address */
     69,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 1 */
  {
    "GPTimer2",        /* Timer Name */
     SOC_TIMER2_BASE,  /* base address */
     70,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 2 */
  {
    "GPTimer3",        /* Timer Name */
     SOC_TIMER3_BASE,  /* base address */
     71,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 3 */
  {
    "GPTimer4",        /* Timer Name */
     SOC_TIMER4_BASE,  /* base address */
     72,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 4 */
  {
    "GPTimer5",        /* Timer Name */
     SOC_TIMER5_BASE,  /* base address */
     73,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 5 */
  {
    "GPTimer6",        /* Timer Name */
     SOC_TIMER6_BASE,  /* base address */
     74,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 6 */
  {
    "GPTimer7",        /* Timer Name */
     SOC_TIMER7_BASE,  /* base address */
     75,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 7 */
  {
    "GPTimer8",        /* Timer Name */
     SOC_TIMER8_BASE,  /* base address */
     76,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 8 */
  {
    "GPTimer9",        /* Timer Name */
     SOC_TIMER9_BASE,  /* base address */
     77,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 9 */
  {
    "GPTimer10",        /* Timer Name */
     SOC_TIMER10_BASE,  /* base address */
     78,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 10 */
  {
    "GPTimer11",        /* Timer Name */
     SOC_TIMER11_BASE,  /* base address */
     79,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 11 */
  {
    "GPTimer12",        /* Timer Name */
     SOC_TIMER12_BASE,  /* base address */
     127,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 12 */
  {
    "GPTimer13",        /* Timer Name */
     SOC_TIMER13_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 13 */
  {
    "GPTimer14",        /* Timer Name */
     SOC_TIMER14_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 14 */
  {
    "GPTimer15",        /* Timer Name */
     SOC_TIMER15_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
  },
  /* Timer ID 15 */
  {
    "GPTimer16",        /* Timer Name */
     SOC_TIMER16_BASE,  /* base address */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,               /* Event Id */
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
