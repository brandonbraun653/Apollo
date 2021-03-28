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
#include <ti/csl/csl_tmr.h>
#include <ti/csl/cslr_tmr.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* determine if it is first time to set the timer configurations */
static int32_t   gTimerFirstTime = 1;
CSL_TmrObj       gTmrObj;
CSL_TmrHandle    gTmrHandle;

/* Function to generate the delay based on the timer ticks. 
 * Configures the timer 0 in dual 32-bit chained mode. 32-bit prescaler 
 * controls the frequency of timer counter increment and 32-bit period  
 * provides the maximum count up value before counter resets */
/* Note: Paramemeter 'addr' is not used by the function but it is kept 
   to make the function prototype compatible with other delay functions */
int32_t Delay_32kFClk(uintptr_t addr, uint32_t prescaler, uint32_t period, uint32_t nTicks)
{
    int32_t  baseTime, sampTime;
    CSL_Status     status;
    CSL_TmrHwSetup hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_TmrEnamode timeCountMode = CSL_TMR_ENAMODE_CONT;

    if (gTimerFirstTime == 1) 
    {
        /* Open the timer. */  
        gTmrHandle = CSL_tmrOpen(&gTmrObj, CSL_TIMER_INSTANCE, NULL_PTR, &status);
        if (gTmrHandle == NULL_PTR) 
            return -1;

        /* Stop the Timer */
        CSL_tmrHwControl(gTmrHandle, CSL_TMR_CMD_RESET64, NULL_PTR);        
        
        /* Set the timer mode to unchained dual mode */
        hwSetup.tmrTimerMode      = CSL_TMR_TIMMODE_DUAL_CHAINED;
        hwSetup.tmrTimerPeriodLo  = period;
        hwSetup.tmrTimerPeriodHi  = prescaler;
        hwSetup.tmrTimerCounterLo = OSAL_TIMER_CNT_LO;
        hwSetup.tmrTimerCounterHi = OSAL_TIMER_CNT_HI;
        CSL_tmrHwSetup(gTmrHandle, &hwSetup);

        /* Start the timer in CONTINUOUS Mode. */
        CSL_tmrHwControl(gTmrHandle, CSL_TMR_CMD_START64, (void *)&timeCountMode);

        gTimerFirstTime = 0;
    }

    CSL_tmrGetHwStatus(gTmrHandle, CSL_TMR_QUERY_COUNT_LO, &baseTime);
    
    /* Every 1 cycle increment is 1ms */
    do 
    {
        CSL_tmrGetHwStatus(gTmrHandle, CSL_TMR_QUERY_COUNT_LO, &sampTime);
    
        /* Check if timer counter restarted and adjust the base 
           and sample time value */
        if(sampTime < baseTime)
        {
            sampTime += period - baseTime;
            baseTime  = 0;
        }
    } while ((sampTime - baseTime) <= nTicks);

    return(osal_OK);
}

/* Osal delay implementation for bare metal,
 * where nTicks is number of ticks in 1ms
 */
int32_t Osal_delay(uint32_t nTicks)
{
  /* Delay by number of ticks */
  /* OSAL_TIMER_PRESCALER and OSAL_TIMER_PERIOD configures the timer to 
     generate clock tick for every 1 msec */
  return( Delay_32kFClk(0, OSAL_TIMER_PRESCALER, OSAL_TIMER_PERIOD, nTicks));
}
/* nothing past this point */
