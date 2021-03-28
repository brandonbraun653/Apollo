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
 *  ======== HwiP_tirtos.c ========
 */

#include <ti/osal/HwiP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/BIOS.h>
#if  defined(__ARM_ARCH_7A__)

#if defined(gnu_targets_arm_A15F) || defined(gnu_targets_arm_A9F)
#include <ti/sysbios/family/arm/gic/Hwi.h>
#elif defined(ti_targets_arm_elf_A8F) || \
      defined(ti_targets_arm_elf_A8Fnv) || \
      defined(gnu_targets_arm_A8F)
#include  <ti/sysbios/family/arm/a8/intcps/Hwi.h>
#endif

#elif defined(__aarch64__)
#include <ti/sysbios/family/arm/gicv3/Hwi.h>
#elif ((defined (SOC_OMAPL137) || defined (SOC_OMAPL138)) && (!defined(_TMS320C6X)))
	#include <ti/sysbios/family/arm/da830/Hwi.h>
#else
#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#elif defined(__TI_ARM_V7R4__)
#include <ti/sysbios/family/arm/v7r/keystone3/Hwi.h>
#else
#include <ti/sysbios/hal/Hwi.h>
#endif
#endif /* __ARM_ARCH_7A__ */


#include <ti/osal/src/tirtos/tirtos_config.h>

extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
#define HWIPOSAL_Assert(expression) (Osal_DebugP_assert((int32_t)((expression)?1:0),\
                                                  __FILE__, __LINE__))

extern uint32_t  gOsalHwiAllocCnt, gOsalHwiPeak;

/*!
 *  @brief    Hwi structure
 */
typedef struct HwiP_tiRtos_s {
    Bool              used;
    Hwi_Struct        hwi;
} HwiP_tiRtos;

/* global pool of statically allocated semaphore pools */
static HwiP_tiRtos gOsalHwiPTiRtosPool[OSAL_TIRTOS_CONFIGNUM_HWI];

/*
 * Dummy function to check size during compile time
 *  ======== HwiP_compileTime_SizeChk ========
 */

void HwiP_compileTime_SizeChk(void)
{
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#else
/* TI compiler */
#pragma diag_suppress 179
#endif
    OSAL_COMPILE_TIME_SIZE_CHECK ((uint32_t)sizeof(HwiP_tiRtos),OSAL_TIRTOS_HWIP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}

/*
 *  ======== HwiP_clearInterrupt ========
 */
void HwiP_clearInterrupt(int32_t interruptNum)
{
    Hwi_clearInterrupt((uint32_t)interruptNum);
}

/*
 *  ======== HwiP_create ========
 */
HwiP_Handle HwiP_create(int32_t interruptNum, HwiP_Fxn hwiFxn,
                        const HwiP_Params *params)
{
    HwiP_tiRtos *handle = (HwiP_tiRtos *) NULL_PTR;
    Hwi_Params  hwiParams;
    Error_Block eb;
    uint32_t          i;
    uintptr_t         key;
    uintptr_t         temp;
    HwiP_tiRtos      *hwiPool;
    uint32_t          maxHwi;

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extHwiPBlock.base != (uintptr_t)0U)
    {
        /* pick up the external memory block configured */
        hwiPool        = (HwiP_tiRtos *) gOsal_HwAttrs.extHwiPBlock.base;
        temp           = ((uintptr_t) hwiPool) + gOsal_HwAttrs.extHwiPBlock.size;
        maxHwi         = (uint32_t)(temp/(sizeof(HwiP_tiRtos)));
    }
    else
    {
        /* Pick up the internal static memory block */
        hwiPool        = (HwiP_tiRtos *) &gOsalHwiPTiRtosPool[0];
        maxHwi         = OSAL_TIRTOS_CONFIGNUM_HWI;
        
        if(gOsalHwiAllocCnt==0U) 
        {
            (void)memset((void *)gOsalHwiPTiRtosPool,0,sizeof(gOsalHwiPTiRtosPool));
		}
    }

    /* Grab the memory */
    key = HwiP_disable();

    for (i = 0U; i < maxHwi; i++)
    {
        if (hwiPool[i].used == FALSE)
        {
            hwiPool[i].used = TRUE;
            /* Update statistics */
            gOsalHwiAllocCnt++;
            if (gOsalHwiAllocCnt > gOsalHwiPeak)
            {
                gOsalHwiPeak = gOsalHwiAllocCnt;
            }
            break;
        }
    }
    HwiP_restore(key);

    if (i < maxHwi)
    {
        /* Grab the memory */
        handle = (HwiP_tiRtos *) &hwiPool[i];
    }

    if (handle != NULL_PTR)
    {
        /* Initialize the error */
        Error_init(&eb);

        if (params == NULL_PTR)
        {
            Hwi_construct(&handle->hwi, interruptNum, (Hwi_FuncPtr)hwiFxn, (Hwi_Params *) NULL_PTR, &eb);
        }
        else
        {
            Hwi_Params_init(&hwiParams);
            hwiParams.instance->name = params->name;
            hwiParams.arg            = (xdc_UArg)(params->arg);

            if (params->priority==0U) 
            {
               /* A priority of 0 is invalid for many targets. -1 forces 
                  sysbios to assign a default priority */
               hwiParams.priority       = -1;
            }
            else
            {
               hwiParams.priority       = (int32_t)params->priority;
            }

            hwiParams.eventId        = (int32_t)params->evtId;
            if (params->enableIntr == TRUE)
            {
                hwiParams.enableInt      = TRUE;
            }
            else
            {
                hwiParams.enableInt      = FALSE;
            }
#ifdef __aarch64__
            hwiParams.maskSetting    = Hwi_MaskingOption_LOWER;
#else
            hwiParams.maskSetting    = Hwi_MaskingOption_SELF;
#endif
#if defined (__ARM_ARCH_7A__) || defined(__aarch64__)
#if defined(gnu_targets_arm_A15F) || defined(gnu_targets_arm_A9F) || defined(__aarch64__)
            hwiParams.triggerSensitivity = (UInt)params->triggerSensitivity;
#endif
#if defined(gnu_targets_arm_A15F)
            /*
             * Set target processor list ID to handle interrupt in all available a15 cores
             * of any given platform.
             */
            if(!BIOS_smpEnabled)
            {
                if(gOsal_HwAttrs.a15TargetProcMask == OSAL_TARGET_PROC_MASK_DEFAULT)
                {
                    hwiParams.targetProcList = 1 << Osal_getCoreId();
                }
                else
                {
                    hwiParams.targetProcList = gOsal_HwAttrs.a15TargetProcMask;
                }

            }
#endif
#endif
#if defined (__TI_ARM_V7R4__)
            /* Set the trigger type */
            if ((params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL) ||
                (params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL) ||
                (params->triggerSensitivity == (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LOW_LEVEL))
            {
                hwiParams.triggerType = Hwi_TriggerType_LEVEL;
            }
            else
            {
                hwiParams.triggerType = Hwi_TriggerType_PULSE;
            }
#endif
            Hwi_construct(&handle->hwi, interruptNum, (Hwi_FuncPtr)hwiFxn,
                          &hwiParams, &eb);

            if (Error_check(&eb)>0U)
            {
                /* Free the allocated memory and return null */
                handle->used = FALSE;
                handle = (HwiP_tiRtos *) NULL_PTR;
            }
        }
    }

    return ((HwiP_Handle)handle);
}

/*
 *  ======== HwiP_delete ========
 */
HwiP_Status HwiP_delete(HwiP_Handle handle)
{
    HWIPOSAL_Assert((handle == NULL_PTR));

    uintptr_t   key;
    HwiP_Status ret;
    
    HwiP_tiRtos *hwi = (HwiP_tiRtos *)handle;
    
    if(hwi!=NULL_PTR) {
      Hwi_destruct(&hwi->hwi);
      key = HwiP_disable();
      hwi->used = FALSE;
      /* Found the osal hwi object to delete */
      if (gOsalHwiAllocCnt > 0U)
      {
        gOsalHwiAllocCnt--;
      }

      HwiP_restore(key);
      ret = HwiP_OK;
    }
    else
    {
       ret = HwiP_FAILURE;
    } 
    return (ret);
}

/*
 *  ======== HwiP_disable ========
 */
uintptr_t HwiP_disable(void)
{
    uintptr_t key;

    key = Hwi_disable();

    return (key);
}

/*
 *  ======== HwiP_disableInterrupt ========
 */
void HwiP_disableInterrupt(int32_t interruptNum)
{
    (void)Hwi_disableInterrupt((uint32_t)interruptNum);
}

/*
 *  ======== HwiP_enableInterrupt ========
 */
void HwiP_enableInterrupt(int32_t interruptNum)
{
    (void)Hwi_enableInterrupt((uint32_t)interruptNum);
}

/*
 *  ======== HwiP_Params_init ========
 */
void HwiP_Params_init(HwiP_Params *params)
{
    params->name = (char *) NULL_PTR;
    params->arg = 0;
    params->priority = HWIP_USE_DEFAULT_PRIORITY;
    params->evtId    = 0;
    params->enableIntr = TRUE;
#if defined (__ARM_ARCH_7A__) || defined(__aarch64__) || defined (__TI_ARM_V7R4__) || defined(gnu_targets_arm_A15F) || defined(gnu_targets_arm_A9F)
    params->triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL;
#endif

#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

    OSAL_COMPILE_TIME_SIZE_CHECK ((uint32_t)sizeof(HwiP_tiRtos),OSAL_TIRTOS_HWIP_SIZE_BYTES);

#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif

}

/*
 *  ======== HwiP_postInterrupt ========
 */

int32_t HwiP_post(uint32_t interruptNum)
{
    Hwi_post(interruptNum);
    
    return osal_OK; 
    /* Please note that in future,for targets which do not support Hwi_Post,
       add #ifdefs appropriately to return osal_UNSUPPORTED */
}


/*
 *  ======== HwiP_restore ========
 */
void HwiP_restore(uintptr_t key)
{
    (void)Hwi_restore((uint32_t)key);
}
