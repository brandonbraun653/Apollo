/**
 * \file   timer.c
 *
 * \brief  This file contains various delay & timer functions that use
 *         OSAL timer.
 */

/*
* Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#include <ti/osal/osal.h>

#if (defined (evmAM335x) || defined (bbbAM335x))

#define CM_PER_TIMER3_CLKCTRL       0x44e00084
#define CM_DPLL_CLKSEL_TIMER3_CLK   0x44e0050c

#define DMTIMER3					1
#define TIMER_ID					DMTIMER3
#endif

#if defined (evmAM437x)

#define CM_PER_TIMER3_CLKCTRL       (0x44DF8800 + 0x538)		// PRCM_CM_PER_TIMER3_CLKCTRL
#define CM_DPLL_CLKSEL_TIMER3_CLK   (0x44DF4200 + 0x8)

#define DMTIMER3					3
#define TIMER_ID					DMTIMER3
#endif

#if (defined (idkAM574x) || defined (idkAM572x) || (defined (idkAM571x)) || defined (evmAM572x) || defined (evmAM571x))

#define GPTIMER2                    1
#define TIMER_ID					GPTIMER2
#endif

#if (defined (evmK2G))
#define TIMER4                      4       
#define TIMER_ID                    TIMER4
#endif

#if defined (evmOMAPL137) || defined (lcdkOMAPL138) || defined (lcdkC6748)
#define TIMER1                      1
#define TIMER_ID                    TIMER1
#endif

#if defined (SOC_AM65XX) || defined (SOC_AM65xx)
#define TIMER1                      1
#define TIMER_ID                    TIMER1
#endif

#if defined (SOC_J721E)
/* The timer ID is different between MCU and MPU domains.
   Using TimerP_ANY so that the osal / bios can pick
   proper timer ID for the core the code runs on */
#define TIMER_ANY                   TimerP_ANY
#define TIMER_ID                    TIMER_ANY
#endif

extern void consolePrintf(const char *pcString, ...);

void delayTmrIsr(void* arg);


TimerP_Params   delayTimerParams;
TimerP_Handle   delayTimerHandle;
TimerP_Status   timerStatus;
volatile unsigned int    delayTimerFlag;
volatile unsigned int    delayTimerCount;

void delayTimerSetup()
{
#if (defined (evmAM437x) || defined (evmAM335x) || defined (bbbAM335x))

    // clock source to CLK_M_OSC: 0x1   - high frequency input clock
    //                 CLK_32KHz: 0x2
    //                 TCLKIN   : 0x0   - external clock pin - not used.
	*(unsigned int*)CM_DPLL_CLKSEL_TIMER3_CLK = 0x1;

	// enable the TIMER
	*(unsigned int*)CM_PER_TIMER3_CLKCTRL = 0x2;
#endif


    TimerP_Params_init(&delayTimerParams);

    delayTimerParams.period = 1000000;  // 1s
    delayTimerParams.periodType = TimerP_PeriodType_MICROSECS;
    delayTimerParams.arg = 0;

#if (defined (evmAM335x) || defined (bbbAM335x))
    delayTimerParams.intfreqLo = 24000000;  /* AM335EVM uses 24MHz clock */
    delayTimerParams.intfreqHi = 0;  
#endif

    delayTimerParams.startMode = TimerP_StartMode_USER;

    delayTimerParams.runMode = TimerP_RunMode_ONESHOT;

    delayTimerHandle = TimerP_create(TIMER_ID,  
                                     (TimerP_Fxn)&delayTmrIsr,
                                     &delayTimerParams);
    if (delayTimerHandle == NULL) {
        consolePrintf("Timer create failed\n");
    }
    
    delayTimerCount = 0;
    delayTimerFlag  = 0;
}

void delayTmrIsr(void* arg)
{
#if defined (evmOMAPL137) || defined (lcdkOMAPL138) || defined (lcdkC6748)
#ifndef TIRTOS
    TimerP_ClearInterrupt(delayTimerHandle);
#endif
#endif
    delayTimerCount++;
    delayTimerFlag  = 1;
}

void osalTimerStart(unsigned int ms)
{
    delayTimerCount = 0;
    delayTimerFlag  = 0;

    TimerP_setPeriodMicroSecs(delayTimerHandle, 
                              (uint32_t)(ms*1000));

    TimerP_start(delayTimerHandle);
}

void osalTimerStop()
{
    TimerP_stop(delayTimerHandle);

    delayTimerCount = 0;
    delayTimerFlag  = 0;
}

unsigned int osalTimerExpired()
{
    if (delayTimerFlag == 1) return 1; else return 0;
}


// a blocking delay function
void osalTimerDelay(unsigned int ms)
{
    osalTimerStart(ms);
    while (delayTimerFlag == 0);
}

/* A function to validate the delay length
 * calling delay(20ms) 250 times - which equates to about 5 seconds 
*/
void osalTimerTest()
{
    int i,j;

    consolePrintf("Test timer duration. Each + should be 5s apart\n");
    for (i = 0; i<10; i++)
    {
        for (j=0;j<250;j++)
        {
            osalTimerDelay(20); // 20ms
        }

        consolePrintf("+\n");
    }
}
