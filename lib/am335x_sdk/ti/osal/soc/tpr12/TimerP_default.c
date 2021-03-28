/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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
TimerP_rtiTimerDefault gRtiTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "RTITimer1",                                /* Timer Name */
     CSL_DSS_RTIA_U_BASE,                       /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,         /* Interrupt Number */
     CSL_DSS_INTR_DSS_RTIA_0,                   /* Event Id */
  },
  /* Timer ID 1 */
  {
    "RTITimer2",                                /* Timer Name */
     CSL_DSS_RTIA_U_BASE,                       /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,         /* Interrupt Number */
     CSL_DSS_INTR_DSS_RTIA_1,                   /* Event Id */
  },
  /* Timer ID 2 */
  {
    "RTITimer3",                                /* Timer Name */
     CSL_DSS_RTIB_U_BASE,                       /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,         /* Interrupt Number */
     CSL_DSS_INTR_DSS_RTIB_0,                   /* Event Id */
  },
  /* Timer ID 3 */
  {
    "RTITimer4",                                /* Timer Name */
     CSL_DSS_RTIB_U_BASE,                       /* base address */
     OSAL_REGINT_INTVEC_EVENT_COMBINER,         /* Interrupt Number */
     CSL_DSS_INTR_DSS_RTIB_0,                   /* Event Id */
  }
};
#elif defined (__TI_ARM_V7R4__)
TimerP_rtiTimerDefault gRtiTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "RTITimer1",                                /* Timer Name */
     CSL_MSS_RTIA_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIA_INT0,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
  },
  /* Timer ID 1 */
  {
    "RTITimer2",                                /* Timer Name */
     CSL_MSS_RTIA_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIA_INT1,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
  },
  /* Timer ID 2 */
  {
    "RTITimer3",                                /* Timer Name */
     CSL_MSS_RTIB_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIB_INT0,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
  },
  /* Timer ID 3 */
  {
    "RTITimer4",                                /* Timer Name */
     CSL_MSS_RTIB_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIB_INT1,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
  },
  /* Timer ID 4 */
  {
    "RTITimer5",                                /* Timer Name */
     CSL_MSS_RTIC_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIC_INT0,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
  },
  /* Timer ID 5 */
  {
    "RTITimer6",                                /* Timer Name */
     CSL_MSS_RTIC_U_BASE,                       /* base address */
     CSL_MSS_INTR_MSS_RTIC_INT1,                /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE,                /* Event Id */
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
