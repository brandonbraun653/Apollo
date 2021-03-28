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
 *  ======== TimerP_default.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* This information is derived from sysbios timer implmentation for multiple SoCs */
#if defined (__TI_ARM_V7R4__)
TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "DMTimer0",        /* Timer Name */
     CSL_MCU_TIMER0_CFG_BASE,  /* base address */
     CSL_MCU0_INTR_TIMER0_INTR_PEND,           /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE               /* Event Id */
  },  
  /* Timer ID 1 */
  {
    "DMTimer1",        /* Timer Name */
     CSL_MCU_TIMER1_CFG_BASE,  /* base address */
     CSL_MCU0_INTR_TIMER1_INTR_PEND,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE               /* Event Id */
  },  
  /* Timer ID 3 */
  {
    "DMTimer2",        /* Timer Name */
     CSL_MCU_TIMER2_CFG_BASE,  /* base address */
     CSL_MCU0_INTR_TIMER2_INTR_PEND,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE               /* Event Id */
  },  
  /* Timer ID 4 */
  {
    "DMTimer3",        /* Timer Name */
     CSL_MCU_TIMER3_CFG_BASE,  /* base address */
     CSL_MCU0_INTR_TIMER3_INTR_PEND,               /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE               /* Event Id */
  }
};
#else
TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices] = {
  /* Timer ID 0 */
  {
    "DMTimer0",        /* Timer Name */
     CSL_TIMER0_CFG_BASE,  /* base address */
     CSL_GIC0_INTR_TIMER0_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
  /* Timer ID 1 */
  {
    "DMTimer1",        /* Timer Name */
     CSL_TIMER1_CFG_BASE,  /* base address */
     CSL_GIC0_INTR_TIMER1_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },
  /* Timer ID 2 */
  {
    "DMTimer2",        /* Timer Name */
     CSL_TIMER2_CFG_BASE,  /* base address */
     CSL_GIC0_INTR_TIMER2_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
  /* Timer ID 3 */
  {
    "DMTimer3",        /* Timer Name */
     CSL_TIMER3_CFG_BASE,  /* base address */
     CSL_GIC0_INTR_TIMER3_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },
  /* Timer ID 4 */
  {
    "DMTimer4",        /* Timer Name */
     CSL_TIMER4_CFG_BASE,  /* base address */
     CSL_GIC0_INTR_TIMER4_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },
  /* Timer ID 5 */
  {
    "DMTimer5",        /* Timer Name */
     CSL_TIMER5_CFG_BASE,                    /* base address */
     CSL_GIC0_INTR_TIMER5_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
  /* Timer ID 6 */
  {
    "DMTimer6",        /* Timer Name */
     CSL_TIMER6_CFG_BASE,                    /* base address */
     CSL_GIC0_INTR_TIMER6_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
   /* Timer ID 7 */
  {
    "DMTimer7",        /* Timer Name */
     CSL_TIMER7_CFG_BASE,                    /* base address */
     CSL_GIC0_INTR_TIMER7_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  }, 
  /* Timer ID 8 */
  {
    "DMTimer8",        /* Timer Name */
     CSL_TIMER8_CFG_BASE,                    /* base address */
     CSL_GIC0_INTR_TIMER8_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
  /* Timer ID 9 */
  {
    "DMTimer9",        /* Timer Name */
     CSL_TIMER9_CFG_BASE,                    /* base address */
     CSL_GIC0_INTR_TIMER9_BUS_INTR_PEND,     /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
  /* Timer ID 10 */
  {
    "DMTimer10",        /* Timer Name */
     CSL_TIMER10_CFG_BASE,                   /* base address */
     CSL_GIC0_INTR_TIMER10_BUS_INTR_PEND,    /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
  },  
   /* Timer ID 11 */
  {
    "DMTimer11",        /* Timer Name */
     CSL_TIMER11_CFG_BASE,                   /* base address */
     CSL_GIC0_INTR_TIMER11_BUS_INTR_PEND,    /* Interrupt Number */
     TIMERP_EVENT_NOT_AVAILABLE              /* Event Id */
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

#if defined (BUILD_MCU)
uint32_t TimerP_mapId(uint32_t id)
{
    /*
     * Pulsar R5 SS is always on the MCU domain
     * use the default info table configuration,
     * no need to map the id.
     */
    return (id);
}
void TimerP_updateDefaultInfoTbl(void)
{
    /*
     * Pulsar R5 SS is always on the MCU domain
     * use the default info table configuration,
     * no need to update the table.
     */
}
#endif

/* Nothing past this point */
