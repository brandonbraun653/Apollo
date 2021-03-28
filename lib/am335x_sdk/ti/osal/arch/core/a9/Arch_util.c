/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
 *  ======== HwiP_tirtos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include "interrupt.h"
#include <ti/csl/tistdtypes.h>

#define OSAL_ARCH_UTIL_ZERO          ((uint32_t) 0U)

/* Local structure definition */
typedef struct HwiP_nonOs_s {
    Bool        used;
    Hwi_Struct  hwi;
} HwiP_nonOs;

/* Local hwi structures */
static HwiP_nonOs hwiStructs[OSAL_NONOS_CONFIGNUM_HWI] = {{0}};

/* local function */
static void osalArch_TimestampCcntAutoRefresh(uintptr_t arg);
extern uint32_t osal_TimestampProvider_readCntr(void);

/*
 * Dummy function to check size during compile time
 *  ======== HwiP_compileTime_SizeChk ========
 */

void OsalArch_compileTime_SizeChk(void)
{
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#else
/* TI compiler */
#pragma diag_suppress 179
#endif
    OSAL_COMPILE_TIME_SIZE_CHECK (sizeof(HwiP_nonOs),OSAL_NONOS_HWIP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}
static bool gTimestampFirstTime = TRUE;

static TimeStamp_Struct gTimeStamp = {0U};

/* Local function */

static void OsalArch_ISRStub(uint32_t intNum, uint32_t cpuId, void* pUserParam)
{
  Hwi_Struct *handle = (Hwi_Struct *)pUserParam;

  handle->fxn((uintptr_t)handle->arg);

}

/* This function enables the interrupt for a given interrupt number */
void OsalArch_enableInterrupt(uint32_t intNum)
{
    INTCEnableIntr(intNum);
}

/* This function disables the interrupt for a given interrupt number */
void OsalArch_disableInterrupt(uint32_t intNum)
{
    INTCDisableIntr(intNum);
}

/* Below function clears interrupt in the chip level */
void OsalArch_clearInterrupt(uint32_t intNum)
{
    INTCClearIntr(intNum);
}
/* Below function globally disable interrupt in the chip level */
uintptr_t OsalArch_globalDisableInterrupt(void)
{
    return ( (uintptr_t)INTCDisableCpuIntr());
}

/* Below function globally restore interrupt in the chip level */
void OsalArch_globalRestoreInterrupt (uintptr_t restoreValue)
{
    INTCEnableCpuIntr((uint32_t)restoreValue);
}

/* Below function registers the interrupt for a given ISR */
HwiP_Handle OsalArch_HwiPCreate(int32_t interruptNum, HwiP_Fxn hwiFxn,
                          const HwiP_Params *params)
{
    Hwi_Struct                   *hwi_handle = (Hwi_Struct *) NULL_PTR;
    intcIntrParams_t             intrParams;
    uint32_t i;
    uintptr_t key;

    uintptr_t         temp;
    HwiP_nonOs       *hwiPool;
    uint32_t          maxHwi;
    HwiP_Handle       retHandle;

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extHwiPBlock.base != (uintptr_t)NULL_PTR)
    {
        /* pick up the external memory block configured */
        hwiPool        = (HwiP_nonOs *) gOsal_HwAttrs.extHwiPBlock.base;
        temp           = ((uintptr_t) hwiPool) + gOsal_HwAttrs.extHwiPBlock.size;
        maxHwi         = (uint32_t)(temp/(sizeof(Hwi_Struct)));
    }
    else
    {
        /* Pick up the internal static memory block */
        hwiPool        = (HwiP_nonOs *) &hwiStructs[0];
        maxHwi         = OSAL_NONOS_CONFIGNUM_HWI;
    }

    if (params == NULL_PTR)
    {
        return (NULL_PTR);
    }
    
    key = OsalArch_globalDisableInterrupt();
    for (i = 0u; i < maxHwi; i++) {
        if (hwiPool[i].used == FALSE) {
            hwiPool[i].used = TRUE;
            break;
        }
    }
    OsalArch_globalRestoreInterrupt(key);

    if (i != maxHwi)
    {
      hwi_handle = &(hwiPool[i].hwi);
      retHandle  = (HwiP_Handle)&hwiPool[i];
    }
    else
    {
      retHandle  = (HwiP_Handle)(NULL_PTR);
    }


    INTCInit(FALSE);

    switch (params->triggerSensitivity)
    {
        case OSAL_ARM_GIC_TRIG_TYPE_EDGE:
             intrParams.triggerType = INTC_TRIG_BOTH_EDGE;
             break;
        case OSAL_ARM_GIC_TRIG_TYPE_FALLING_EDGE:
             intrParams.triggerType = INTC_TRIG_FALLING_EDGE;
             break;
        case OSAL_ARM_GIC_TRIG_TYPE_RISING_EDGE:
             intrParams.triggerType = INTC_TRIG_RISING_EDGE;
             break;
        case OSAL_ARM_GIC_TRIG_TYPE_LOW_LEVEL:
             intrParams.triggerType = INTC_TRIG_LOW_LEVEL;
             break;
        case OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL:
        case OSAL_ARM_GIC_TRIG_TYPE_LEVEL:
        default:
             intrParams.triggerType = INTC_TRIG_HIGH_LEVEL;
             break;
    }
    if (hwi_handle != (Hwi_Struct *) NULL_PTR)
    {
        /* Record the hwiFxn and argument */
        hwi_handle->arg           = (void*) params->arg;
        hwi_handle->fxn           = hwiFxn;
        hwi_handle->intNum        = interruptNum;
    
        /* set the priority */
        intrParams.priority       = params->priority;
        intrParams.pFnIntrHandler = &OsalArch_ISRStub;
        intrParams.pUserParam     = (void* )hwi_handle;
        intrParams.isIntrSecure   = FALSE;
    
        /* Configure the interrupt Controller */
        INTCConfigIntr(interruptNum,&intrParams, FALSE);

        /* Enabling the interrupt if configured */
        if (params->enableIntr == TRUE)
        {
            /* Enabling the interrupt in INTC. */
            OsalArch_enableInterrupt(interruptNum);
        }
        else
        {
            /* Disabling the interrupt in INTC. */
            OsalArch_disableInterrupt(interruptNum);
        }
    }
    return ( (HwiP_Handle) (retHandle) );

}

HwiP_Status OsalArch_HwiPDelete(HwiP_Handle handle)
{
    HwiP_nonOs *hwi_hnd = (HwiP_nonOs*) handle;
    uintptr_t   key;

    /* mark that index as free */
    key = OsalArch_globalDisableInterrupt();
    hwi_hnd->used = FALSE;
    OsalArch_globalRestoreInterrupt(key);

    return (HwiP_OK);
}

/* Return the cycle frequency used for timeStamp */
int32_t  osalArch_TimeStampGetFreqKHz(void)
{
    /* R5F time Stamp is via PMU, which runs at CPU speed */
    return (gOsal_HwAttrs.cpuFreqKHz);
}

/* Initialize the time stamp module */
void    osalArch_TimestampInit(void)
{
    TimerP_Params  timerParams;
    TimerP_Handle  timerHandle;

    if (gTimestampFirstTime == TRUE)
    {
        osal_TimestampProvider_initCCNT();
        /* One time initialization is done */
        gTimestampFirstTime = FALSE;

        /* Initialize the parameters */
        TimerP_Params_init(&timerParams);
        timerParams.startMode = TimerP_StartMode_USER;
        timerParams.periodType = TimerP_PeriodType_MICROSECS;
        timerParams.period    = 1000000u;
        timerHandle = TimerP_create(TimerP_ANY, (TimerP_Fxn)&osalArch_TimestampCcntAutoRefresh, &timerParams);

        if ( timerHandle != (TimerP_Handle) NULL_PTR)
        {
            /* start the timer */
            TimerP_start(timerHandle);
        }
    }

    return;
}

/* Osal time stamp provider implementations */
void osalArch_TimestampGet64(TimeStamp_Struct *tStamp)
{
    uint32_t    lo, ovsrStatus;
    uintptr_t   key;

    if (tStamp != (TimeStamp_Struct *) NULL_PTR)
    {
        key        = HwiP_disable();
        /* Make sure init is done, if not done already */
        osalArch_TimestampInit();
        lo = osal_TimestampProvider_readCntr();

        ovsrStatus = osal_TimestampProvider_getOverflowCCNT();

        if (ovsrStatus != OSAL_ARCH_UTIL_ZERO)
        {
            lo = osal_TimestampProvider_readCntr();
            gTimeStamp.hi++;
        }

        gTimeStamp.lo      = lo;
        tStamp->lo         = lo;
        tStamp->hi         = gTimeStamp.hi;
        /* restore */
        HwiP_restore(key);
    }
    /* return time in micro seconds */
    return;
}

/* Needs to be run at least once after a over flow happens and before next overflow */
static void osalArch_TimestampCcntAutoRefresh(uintptr_t arg)
{
    uint32_t    ovsrStatus;
    uintptr_t   key;

    key        = HwiP_disable();

    ovsrStatus = osal_TimestampProvider_getOverflowCCNT();

    if (ovsrStatus != OSAL_ARCH_UTIL_ZERO)
    {
        gTimeStamp.lo = osal_TimestampProvider_readCntr();
        gTimeStamp.hi++;
    }

    /* restore */
    HwiP_restore(key);

    /* return time in micro seconds */
    return;
}

/* Nothing past this point */
