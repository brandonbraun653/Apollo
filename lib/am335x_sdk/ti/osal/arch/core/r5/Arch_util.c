/*
 * Copyright (c) 2016-2018, Texas Instruments Incorporated
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
#include <string.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/osal/src/nonos/Nonos_config.h>

/* Local define */
#define HWIP_R5F_DEFAULT_PRIORITY    ((uint32_t) 0x0FU)

#define OSAL_ARCH_UTIL_ZERO          ((uint32_t) 0U)

/* Local hwi structures */

typedef struct HwiP_nonOs_s {
    bool        used;
    Hwi_Struct  hwi;
} HwiP_nonOs;

/* Local hwi structures */
static HwiP_nonOs hwiStructs[OSAL_NONOS_CONFIGNUM_HWI];

/* local function */
static void osalArch_TimestampCcntAutoRefresh(uintptr_t arg);

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
    OSAL_COMPILE_TIME_SIZE_CHECK ((uint32_t)sizeof(HwiP_nonOs),OSAL_NONOS_HWIP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}

static bool gFirstTime = (bool)true;
static bool gTimestampFirstTime = (bool)true;
static bool gHwiInitialized = (bool)false;
static CSL_vimRegs *gVimRegs;

static TimeStamp_Struct gTimeStamp = {NULL,NULL};
static HwiP_Handle      gHwiPHandle;

/* This function enables the interrupt for a given interrupt number */
void OsalArch_enableInterrupt(uint32_t intNum)
{
    Intc_IntEnable((uint16_t)intNum);
    return;
}

/* This function disables the interrupt for a given interrupt number */
void OsalArch_disableInterrupt(uint32_t intNum)
{
    Intc_IntDisable((uint16_t)intNum);
    return;
}

/* Below function clears interrupt in the chip level */
void OsalArch_clearInterrupt(uint32_t intNum)
{
    Intc_IntClrPend((uint16_t)intNum);
    return;
}
/* Below function globally disable interrupt in the chip level */
uintptr_t OsalArch_globalDisableInterrupt(void)
{
    return ((uintptr_t)Intc_SystemDisable());
}

/* Below function posts the interrupt */
int32_t OsalArch_postInterrupt(uint32_t intrNum)
{
    return (CSL_vimSetIntrPending(gVimRegs, intrNum));
}


/* Below function globally restore interrupt in the chip level */
void OsalArch_globalRestoreInterrupt (uintptr_t restoreValue)
{
    Intc_SystemRestore(restoreValue);
}

/* Below function registers the interrupt for a given ISR */
HwiP_Handle OsalArch_HwiPCreate(int32_t interruptNum, HwiP_Fxn hwiFxn,
                         const HwiP_Params *params)
{
    Hwi_Struct                   *hwi_handle = NULL;

    uint32_t i;
    uintptr_t key;
    uint16_t priority;
    uintptr_t         temp;
    HwiP_nonOs       *hwiPool;
    uint32_t          maxHwi;
    HwiP_Handle       retHandle = NULL_PTR;
    CSL_ArmR5CPUInfo  info;

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extHwiPBlock.base != 0U)
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
        
        if(gHwiInitialized==(bool)false) 
        {
          /* Initializing the first time */
          (void)memset((void *)hwiStructs,0,sizeof(hwiStructs));
          gHwiInitialized = (bool)true; 
        }
    }

    if (params != NULL_PTR)
    {

    key = OsalArch_globalDisableInterrupt();
    for (i = 0u; i < maxHwi; i++) {
        if (hwiPool[i].used == (bool)false) {
            hwiPool[i].used = (bool)true;
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
      retHandle  = (HwiP_Handle)(NULL);
    }

    if (hwi_handle != NULL_PTR)
    {
        if (gFirstTime == (bool)true)
        {
            Intc_Init();
            CSL_armR5GetCpuID(&info);
            if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
            {
                /* MCU SS Pulsar R5 SS */
                if (info.cpuID == CSL_ARM_R5_CPU_ID_0)
                {
                    gVimRegs = (CSL_vimRegs *)(uintptr_t)CSL_MCU_DOMAIN_VIM_BASE_ADDR0;
                }
                else
                {
                    gVimRegs = (CSL_vimRegs *)(uintptr_t)CSL_MCU_DOMAIN_VIM_BASE_ADDR1;
                }
            }
            else
            {
                /* MAIN SS Pulsar R5 SS */
                if (info.cpuID == CSL_ARM_R5_CPU_ID_0)
                {
                    gVimRegs = (CSL_vimRegs *)(uintptr_t)CSL_MAIN_DOMAIN_VIM_BASE_ADDR0;
                }
                else
                {
                    gVimRegs = (CSL_vimRegs *)(uintptr_t)CSL_MAIN_DOMAIN_VIM_BASE_ADDR1;
                }
            }
            gFirstTime = (bool)false;
            Intc_SystemEnable();
        }

        /* Disable the interrupt first */
        Intc_IntDisable((uint16_t)interruptNum);

        /* Set the trigger type */
        if ((params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL) ||
            (params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL) ||
            (params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LOW_LEVEL))
        {
            Intc_IntSetSrcType((uint16_t)interruptNum, CSL_VIM_INTR_TYPE_LEVEL);
        }
        else
        {
            Intc_IntSetSrcType((uint16_t)interruptNum, CSL_VIM_INTR_TYPE_PULSE);
        }

        hwi_handle->intNum = (uint32_t)interruptNum;

        /* Registering the Interrupt Service Routine(ISR). */
        Intc_IntRegister((uint16_t)interruptNum, (IntrFuncPtr) hwiFxn, (void *)params->arg);

        /* Set the priority to default priority if priority is set un-initialized */
        if (params->priority == HWIP_USE_DEFAULT_PRIORITY)
        {
            priority = (uint16_t)HWIP_R5F_DEFAULT_PRIORITY;
        } 
        else
        {
			priority = (uint16_t)params->priority;
		}

        /* Setting the priority for the UART interrupt in INTC. */
        Intc_IntPrioritySet((uint16_t)interruptNum, priority, 0);

        /* Enabling the interrupt if configured */
        if (params->enableIntr == 1U)
        {
            /* Enabling the interrupt in INTC. */
            Intc_IntEnable((uint16_t)interruptNum);
        }
        else
        {
            /* Disabling the interrupt in INTC. */
            Intc_IntDisable((uint16_t)interruptNum);
        }
    }
  } 
    return ((HwiP_Handle) (retHandle) );

}

HwiP_Status OsalArch_HwiPDelete(HwiP_Handle handle)
{
    HwiP_nonOs *hwi_hnd = (HwiP_nonOs*) handle;
    uintptr_t   key;

    /* mark that handle as free */
    key = OsalArch_globalDisableInterrupt();
    hwi_hnd->used = (bool)false;
    Intc_IntUnregister((uint16_t)hwi_hnd->hwi.intNum );
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

    if (gTimestampFirstTime == (bool)true)
    {
        osal_TimestampProvider_initCCNT();
        /* One time initialization is done */
        gTimestampFirstTime = (bool)false;

        /* Initialize the parameters */
        TimerP_Params_init(&timerParams);
        timerParams.startMode = (uint32_t)TimerP_StartMode_USER;
        timerParams.periodType = (uint32_t)TimerP_PeriodType_MICROSECS;
        timerParams.period    = 1000000u;
        timerHandle = TimerP_create((int32_t)TimerP_ANY, (TimerP_Fxn)&osalArch_TimestampCcntAutoRefresh, &timerParams);

        if ( timerHandle != NULL_PTR)
        {
            /* start the timer */
            (void)TimerP_start(timerHandle);
        }
    }

    return;
}

/* Osal time stamp provider implementations */
void osalArch_TimestampGet64(TimeStamp_Struct *tStamp)
{
    uint32_t    lo, ovsrStatus;
    uintptr_t   key;

    if (tStamp !=  NULL_PTR)
    {
        key        = HwiP_disable();
        /* Make sure init is done, if not done already */
        osalArch_TimestampInit();
        lo = CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);

        ovsrStatus = osal_TimestampProvider_getOverflowCCNT();

        if (ovsrStatus != OSAL_ARCH_UTIL_ZERO)
        {
            lo = CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
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
        gTimeStamp.lo = CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
        gTimeStamp.hi++;
    }

    /* restore */
    HwiP_restore(key);

    /* return time in micro seconds */
    return;
}

/* Nothing past this point */
