/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
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
 *  ======== SemaphoreP_tirtos.c ========
 */
#include <ti/osal/SemaphoreP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/osal/src/tirtos/tirtos_config.h>

extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
#define SEMOSAL_Assert(expression) (Osal_DebugP_assert((int32_t)((expression)?1:0),\
                                                  __FILE__, __LINE__))

extern uint32_t  gOsalSemAllocCnt, gOsalSemPeak;

/*!
 *  @brief    Semaphore structure
 */
typedef struct SemaphoreP_tiRtos_s {
    Bool              used;
    Semaphore_Struct  sem;
} SemaphoreP_tiRtos;

/* global pool of statically allocated semaphore pools */
static SemaphoreP_tiRtos gOsalSemPTiRtosPool[OSAL_TIRTOS_CONFIGNUM_SEMAPHORE];

/*
 * Dummy function to check size during compile time
 *  ======== SemaphoreP_compileTime_SizeChk ========
 */

void SemaphoreP_compileTime_SizeChk(void)
{
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#else
/* TI compiler */
#pragma diag_suppress 179
#endif
    OSAL_COMPILE_TIME_SIZE_CHECK ((uint32_t)sizeof(SemaphoreP_tiRtos),OSAL_TIRTOS_SEMAPHOREP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}

/*
 *  ======== SemaphoreP_create ========
 */
SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                    const SemaphoreP_Params *params)
{
    SemaphoreP_Handle ret_handle;
    SemaphoreP_tiRtos *handle = (SemaphoreP_tiRtos *) NULL_PTR;
    Semaphore_Params     semaphoreParams;
    uint32_t          i;
    uintptr_t         key;
    uintptr_t         temp;
    SemaphoreP_tiRtos *semPool;
    uint32_t          maxSemaphores;

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extSemaphorePBlock.base != (uintptr_t)0U)
    {
        /* pick up the external memory block configured */
        semPool        = (SemaphoreP_tiRtos *) gOsal_HwAttrs.extSemaphorePBlock.base;
        temp           = ((uintptr_t) semPool) + gOsal_HwAttrs.extSemaphorePBlock.size;
        maxSemaphores  = (uint32_t)(temp/(sizeof(SemaphoreP_tiRtos)));
    }
    else
    {
        /* Pick up the internal static memory block */
        semPool        = (SemaphoreP_tiRtos *) &gOsalSemPTiRtosPool[0];
        maxSemaphores  = OSAL_TIRTOS_CONFIGNUM_SEMAPHORE;
        
        if(gOsalSemAllocCnt==0U) 
        {
			(void)memset( (void *)gOsalSemPTiRtosPool,0,sizeof(gOsalSemPTiRtosPool));
		}
    }

    key = HwiP_disable();

     for (i = 0; i < maxSemaphores; i++)
     {
         if (semPool[i].used == FALSE)
         {
             semPool[i].used = TRUE;
             /* Update statistics */
             gOsalSemAllocCnt++;
             if (gOsalSemAllocCnt > gOsalSemPeak)
             {
                 gOsalSemPeak = gOsalSemAllocCnt;
             }
             break;
         }
     }
     HwiP_restore(key);

    if (i < maxSemaphores)
    {
        /* Grab the memory */
        handle = (SemaphoreP_tiRtos *) &semPool[i];
    }

    if (handle == NULL_PTR) {
        ret_handle = NULL_PTR;
    }
    else
    {
        if (params == NULL_PTR) {
            Semaphore_construct(&handle->sem, (int32_t)count, (Semaphore_Params *) NULL_PTR);
        }
        else {
            Semaphore_Params_init(&(semaphoreParams));
            /*
             * The default mode for TI-RTOS is counting, so only change if a binary
             * semaphore is requested.
             */
            if (params->mode == SemaphoreP_Mode_BINARY) {
                (semaphoreParams).mode = Semaphore_Mode_BINARY;
            }
            (semaphoreParams).instance->name = params->name;
            Semaphore_construct(&handle->sem, (int32_t)count, &(semaphoreParams));
        }

        ret_handle = ((SemaphoreP_Handle)handle);
    }
    return ret_handle;
}

/*
 *  ======== SemaphoreP_delete ========
 */
SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle handle)
{
    SEMOSAL_Assert((handle == NULL_PTR));

    uintptr_t   key;
    SemaphoreP_Status ret = SemaphoreP_OK;
    SemaphoreP_tiRtos *semaphore = (SemaphoreP_tiRtos *)handle;

    if(semaphore != NULL_PTR)
    {
   
      Semaphore_destruct(&semaphore->sem);

      key = HwiP_disable();
      semaphore->used = FALSE;
      /* Found the osal semaphore object to delete */
      if (gOsalSemAllocCnt > 0U)
      {
        gOsalSemAllocCnt--;
      }
      HwiP_restore(key);
      ret = SemaphoreP_OK;
    } 
    else
    {
       ret = SemaphoreP_FAILURE;
    }  
    return (ret);
}

/*
 *  ======== SemaphoreP_Params_init ========
 */
void SemaphoreP_Params_init(SemaphoreP_Params *params)
{
    SEMOSAL_Assert((params == NULL_PTR));

    if(params != NULL_PTR) {
      params->mode = SemaphoreP_Mode_COUNTING;
      params->name = (char *) NULL_PTR;
    }
}

/*
 *  ======== SemaphoreP_pend ========
 */
SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle handle, uint32_t timeout)
{
    Bool flag;
    SemaphoreP_Status ret_val;
    SemaphoreP_tiRtos *semaphore = (SemaphoreP_tiRtos *)handle;

    SEMOSAL_Assert((handle == NULL_PTR));

    flag = Semaphore_pend((Semaphore_Handle)&semaphore->sem, timeout);
    if (FALSE == flag) {
        ret_val = SemaphoreP_TIMEOUT;
    }
    else
    {
        ret_val = SemaphoreP_OK;
    }

    return (ret_val);
}

/*
 *  ======== SemaphoreP_post ========
 */
SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle handle)
{
    SEMOSAL_Assert((handle == NULL_PTR));
    SemaphoreP_tiRtos *semaphore = (SemaphoreP_tiRtos *)handle;

    Semaphore_post((Semaphore_Handle)&semaphore->sem);
    return (SemaphoreP_OK);
}

/*
 *  ======== SemaphoreP_postFromClock ========
 */
SemaphoreP_Status SemaphoreP_postFromClock(SemaphoreP_Handle handle)
{
    return (SemaphoreP_post(handle));
}

/*
 *  ======== SemaphoreP_postFromISR ========
 */
SemaphoreP_Status SemaphoreP_postFromISR(SemaphoreP_Handle handle)
{
    return (SemaphoreP_post(handle));
}
/*
 *  ======== SemaphoreP_getCount ========
 */
int32_t SemaphoreP_getCount(SemaphoreP_Handle handle)
{
    SEMOSAL_Assert((handle == NULL_PTR));
		
    SemaphoreP_tiRtos *semaphore = (SemaphoreP_tiRtos *)handle;

    return (Semaphore_getCount((Semaphore_Handle)&semaphore->sem));
}

SemaphoreP_Status SemaphoreP_reset(SemaphoreP_Handle handle)
{
    SemaphoreP_Status ret_val = SemaphoreP_OK;
    SemaphoreP_tiRtos *semaphore = (SemaphoreP_tiRtos *)handle;

    SEMOSAL_Assert((handle == NULL_PTR));

    Semaphore_reset((Semaphore_Handle)&semaphore->sem, 0);

    return (ret_val);
}
/* Nothing past this point */
