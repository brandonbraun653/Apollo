/**
 * \file   dmtimer_util.c
 *
 * \brief  This file contains time utility API's implementation which are 
 *         SoC/IP specific.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "misc.h"
#include "chipdb.h"
#include "debug.h"
#include "interrupt.h"
#include "prcm.h"
#include "dmtimer.h"
#include "console_utils.h"
#include "time_utils.h"
#include "timer_util_priv.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define TIMER_INITIAL_COUNT     (0U)
#define TIMER_RLD_COUNT         (0U)

/* Timer 2 interrupt number */
#define SYS_INT_TIMER_INT       (101U)

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/** \brief   Free running timer ISR. */
static void TimerFreeRunIsr(uint32_t intrNum, uint32_t cpuId,void* pUserParam);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint32_t gFreeRunTimerClockRateHz = 0;
static uint64_t gFreeRunTimerCount = 0;
static uint32_t gBaseAddr = 0;

/* SoC specific array based on #timeClockSel_t */
static uint32_t gTimerClkSel[] = {
                            32 * FREQ_KHZ,
                            32 * FREQ_KHZ,
                            32 * FREQ_KHZ,
                            24 * FREQ_MHZ,
                            0
                         };

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t TIMERUtilFreeRunInit(timeUtilsObj_t *pFreeRunTimer)
{
    uint32_t status = S_PASS;
    intcIntrParams_t intrParams;
    gBaseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DMTIMER, pFreeRunTimer->timerInst);
     
    if((CHIPDB_INVALID_ADDRESS != (int32_t)gBaseAddr) && 
                                                (NULL != pFreeRunTimer))
    {
        /* Timer clock configuration (mux config) 
        TBD: To be updated with PRCM APIs (once implemented). 
        Defalut is M_OSC - 24Mhz.
        TimerClockConfig(gBaseAddr, pFreeRunTimer->inputClockSel); 
        HW_WR_REG32(0x44df4210, 0x1); */
        
        gFreeRunTimerClockRateHz = gTimerClkSel[pFreeRunTimer->inputClockSel];
        
        ASSERT(0 == gFreeRunTimerClockRateHz);
        
        /* PRCM Module clock enable */
        status = PRCMModuleEnable(CHIPDB_MOD_ID_DMTIMER, pFreeRunTimer->timerInst, FALSE);

        /* Configure the timer counters and mode */
        DMTimerCounterSet(gBaseAddr, TIMER_INITIAL_COUNT);
        /* Load the load register with the reload count value */
        DMTimerReloadSet(gBaseAddr, TIMER_RLD_COUNT);
        /* Configure the DMTimer for Auto-reload and compare mode */
        DMTimerModeConfigure(gBaseAddr, DMTIMER_MODE_CFG_AUTORLD_CMP_DISABLE);
        /* Disable pre-scalar */
        DMTimerPreScalerClkDisable(gBaseAddr);
        
        /* Perform initialization of Interrupt controller*/
        status &= INTCInit(FALSE);
        
        /* Configure timer interrupt */
        intrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
        intrParams.priority       = 0x10;
        intrParams.pFnIntrHandler = TimerFreeRunIsr;
        intrParams.pUserParam     = 0;
        intrParams.isIntrSecure   = FALSE;

        if(S_PASS != INTCConfigIntr(SYS_INT_TIMER_INT, &intrParams, FALSE))
        {
            CONSOLEUtilsPuts("Interrupt configuration failed for timer interrupt.\r\n");
        }
        
        /* Enable the DMTimer interrupts */
        DMTimerIntEnable(gBaseAddr, DMTIMER_INTR_MASK_OVF);
        
        /* Start the DMTimer */
        DMTIMEREnable(gBaseAddr, TRUE);
    }
    else
    {
        status = E_FAIL;
    }
    return status;
}

void TIMERUtilSetTimeStamp(uint64_t nanoSec)
{
    gFreeRunTimerCount = (uint64_t)(gFreeRunTimerClockRateHz * (nanoSec/TIME_NANO_SEC_FL));
    DMTimerCounterSet(gBaseAddr, (uint32_t)gFreeRunTimerCount);
    gFreeRunTimerCount = gFreeRunTimerCount & (0xFFFFFFFF00000000);    
}

uint64_t TIMERUtilGetTimeStamp(void)
{
    uint32_t counterVal = 0;
    uint64_t curTS = gFreeRunTimerCount;
    
    counterVal = DMTimerCounterGet(gBaseAddr);
    
    /* To avoid the race condition below check is needed. 
       The simpler implementation 
           curTS = gFreeRunTimerCount | (uint64_t)DMTimerCounterGet(gBaseAddr);
       will fail if the HW timer overflows after the count value is read. In 
       this case the gFreeRunTimerCount will get incremented, but the count 
       value read from HW timer is of the previous cycle value.
    */
    if(curTS == gFreeRunTimerCount)
    {
        curTS = curTS | (uint64_t)counterVal;
    }
    else
    {
        /* When control comes here the HW timer would have just overflowed, so 
           it is not expected to overflow again, so the below statement will 
           not fail. */
        curTS = gFreeRunTimerCount | (uint64_t)DMTimerCounterGet(gBaseAddr);
    }
    
    curTS = (uint64_t)(curTS * (TIME_NANO_SEC_FL/gFreeRunTimerClockRateHz));
    return curTS;
}

void TimerFreeRunIsr(uint32_t intrNum, uint32_t cpuId, void* pUserParam)
{
    /* Disable the DMTimer interrupts */
    DMTimerIntDisable(gBaseAddr, DMTIMER_INTR_MASK_OVF);
    
    gFreeRunTimerCount += ((uint64_t)0x1 << 32);

    /* Clear the status of the interrupt flags */         
    DMTimerIntStatusClear(gBaseAddr, DMTIMER_INTR_MASK_OVF);

    /* Enable the DMTimer interrupts */
    DMTimerIntEnable(gBaseAddr, DMTIMER_INTR_MASK_OVF);
}
