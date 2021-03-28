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
 *  ======== SemaphoreP_nonos.c ========
 */
#include <ti/osal/SemaphoreP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/osal.h>
#include <ti/osal/src/nonos/Nonos_config.h>

extern uint32_t  gOsalSemAllocCnt, gOsalSemPeak;

/*!
 *  @brief    Semaphore structure
 */
typedef struct Sem_Struct_s {
    bool              used;
    uint32_t          sem;
    uint32_t          count;
    SemaphoreP_Mode   mode;
} Sem_Struct;

Sem_Struct semStructs[OSAL_NONOS_CONFIGNUM_SEMAPHORE];
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
    OSAL_COMPILE_TIME_SIZE_CHECK ((uint32_t)sizeof(Sem_Struct),OSAL_NONOS_SEMAPHOREP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}
static void semaphoreInit( Sem_Struct *semPool, uint32_t maxSemaphores)
{
  uint32_t i;
  Sem_Struct *semPool_ptr = semPool;
  for(i=0;i<maxSemaphores;i++)
  {
    semPool_ptr->used = (bool)false;
    semPool_ptr->sem =  i;
    semPool_ptr->count = 0;
    semPool_ptr->mode = SemaphoreP_Mode_COUNTING;
    semPool_ptr++;
  }

}
/*
 *  ======== SemaphoreP_create ========
 */
SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                    const SemaphoreP_Params *params)
{
    uint32_t          i;
    uintptr_t         key;
    SemaphoreP_Handle ret_val;
    uintptr_t         temp;
    Sem_Struct       *semPool;
    uint32_t          maxSemaphores;

    key = HwiP_disable();

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extSemaphorePBlock.base != (uintptr_t)0U)
    {
        /* pick up the external memory block configured */
        semPool        = (Sem_Struct *) gOsal_HwAttrs.extSemaphorePBlock.base;
        temp           = ((uintptr_t) semPool) + gOsal_HwAttrs.extSemaphorePBlock.size;
        maxSemaphores  = (uint32_t)(temp/(sizeof(Sem_Struct)));
    }
    else
    {
        /* Pick up the internal static memory block */
        semPool        = (Sem_Struct *) &semStructs[0];
        maxSemaphores  = OSAL_NONOS_CONFIGNUM_SEMAPHORE;
    }
    /* First time, semaphores are not initialized */
    if(gOsalSemAllocCnt==0U)
    {
       semaphoreInit(semPool,maxSemaphores);
	}
    
    for (i = 0; i < maxSemaphores; i++)
    {
        if (semPool[i].used == (bool)false)
        {
            semPool[i].used = (bool)true;

            /* Update statistics */
            gOsalSemAllocCnt++;
            if (gOsalSemAllocCnt > gOsalSemPeak)
            {
                gOsalSemPeak = gOsalSemAllocCnt;
            }

            semPool[i].sem = i;
            semPool[i].count = count;
            if (params != NULL_PTR)
            {
                semPool[i].mode = params->mode;
            }

            break;
        }
    }
    HwiP_restore(key);

    if (i == maxSemaphores)
    {
        ret_val = NULL_PTR;
    }
    else
    {
        ret_val = ((SemaphoreP_Handle)&semPool[i]);
    }
    return (ret_val);
}

/*
 *  ======== SemaphoreP_delete ========
 */
SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL_PTR));
    SemaphoreP_Status ret = SemaphoreP_OK;
    uintptr_t   key;
    Sem_Struct *semS = (Sem_Struct *)handle;
    
    if(semS != NULL_PTR) 
    {
      key = HwiP_disable();
      semS->used = (bool)false;
      /* Found the bsp osal semaphore object to delete */
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
    OSAL_Assert((params == NULL_PTR));
    if(params!=NULL_PTR) {
      params->mode = SemaphoreP_Mode_COUNTING;
      params->name = (char *) NULL_PTR;
    }  
}

/*
 *  ======== SemaphoreP_pend ========
 */
SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle handle, uint32_t timeout)
{
    OSAL_Assert((handle == NULL_PTR));

    uintptr_t           key;
    Sem_Struct         *semS        = (Sem_Struct *)handle;
    uint32_t            semTimeout  = timeout;
    SemaphoreP_Status   ret_val     = SemaphoreP_OK;
    bool iterate = (bool)true;
    
    if(semS!=NULL) {
      while ( (ret_val == SemaphoreP_OK) && (iterate== (bool)true))
      {
        key = HwiP_disable();
        if (semS->count > 0U)
        {
            if (semS->mode == SemaphoreP_Mode_BINARY)
            {
				semS->count = 0;
            }
            else
            {
                semS->count--;
            }
            HwiP_restore(key);
            iterate=(bool)false;
        }
	  else
        {
            HwiP_restore(key);
            if (semTimeout == SemaphoreP_NO_WAIT)
            {
                ret_val = (SemaphoreP_TIMEOUT);
                iterate=(bool)false;
            }
            else if  (semTimeout == SemaphoreP_WAIT_FOREVER)
            {
               /* Wait forever */
            }
            else /* Timed wait */
            {
                (void)Osal_delay(1);
                semTimeout--;
            }
        }
      }
   } else
   {
	   ret_val = SemaphoreP_FAILURE;
   }   

    return (ret_val);
}

/*
 *  ======== SemaphoreP_post ========
 */
SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL_PTR));
    SemaphoreP_Status ret = SemaphoreP_OK;
    uintptr_t   key;
    Sem_Struct *semS = (Sem_Struct *)handle;
    if(semS != NULL_PTR)
    {
      
      key = HwiP_disable();
      if (semS->mode == SemaphoreP_Mode_BINARY)
      {
        semS->count = 1;
      }
      else
      {
        semS->count++;
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
 *  ======== SemaphoreP_getCount ========
 */
int32_t SemaphoreP_getCount(SemaphoreP_Handle handle)

{
    int32_t ret=0;
    OSAL_Assert((handle == NULL_PTR));
    Sem_Struct *semS = (Sem_Struct *)handle;
    if(semS !=NULL_PTR) {
       ret = (int32_t)semS->count;
    } else {
       ret = 0;
    }
    return (ret);
}

/* Nothing past this point */

