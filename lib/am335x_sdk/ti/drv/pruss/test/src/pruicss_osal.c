/**
 *   @file  PRUICSS_osal.c
 *
 *   @brief
 *      This is the OS abstraction layer and is used by the Uart, The example application
 *      works on multiple cores.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2014, Texas Instruments, Inc.
 *
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
 *  \par
*/
#ifndef COMMON_OSAL_PROTOTYPE
#define COMMON_OSAL_PROTOTYPE
#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/heaps/HeapBuf.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/hal/Hwi.h>
#include <xdc/cfg/global.h>

/**********************************************************************
 ************************** Local Definitions *************************
 **********************************************************************/


/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/**********************************************************************
 **************************** OSAL Functions **************************
 **********************************************************************/



/**
 *  @b Description
 *  @n
 *      The function is used to create a critical section.
 *
 *    *  @param[in]  count
 *      Semaphore count value
 *
 *    *  @param[in]  params
 *
 *  @retval
 *      Semaphore Handle created
 */

/*
 *  ======== SemaphoreP_create ========
 */
SemaphoreP_Handle SemaphoreP_create(unsigned int count,
                                    SemaphoreP_Params *params)
{
    Semaphore_Struct *handle;
    union {
        Error_Block          eb;
        Semaphore_Params     semaphoreParams;
    } createUnion;

    Error_init(&(createUnion.eb));
    handle = (Semaphore_Struct *)Memory_alloc(NULL, sizeof(Semaphore_Struct),
                                              0, &(createUnion.eb));
    if (handle == NULL) {
        return (NULL);
    }

    if (params == NULL) {
        Semaphore_construct(handle, count, NULL);
    }
    else {
        Semaphore_Params_init(&(createUnion.semaphoreParams));
        /*
         * The default mode for TI-RTOS is counting, so only change if a binary
         * semaphore is requested.
         */
        if (params->mode == SemaphoreP_Mode_BINARY) {
            (createUnion.semaphoreParams).mode = Semaphore_Mode_BINARY;
        }
        (createUnion.semaphoreParams).instance->name = params->name;
        Semaphore_construct(handle, count, &(createUnion.semaphoreParams));
    }

    return ((SemaphoreP_Handle)handle);
}

/**
 *  @b Description
 *  @n
 *      The function is used to delete a critical section.
 *
 *  @param[in]  semHandle
 *      Semaphore handle to be deleted
 *
 *  @retval
 *      Not Applicable
 */
/*
 *  ======== SemaphoreP_delete ========
 */
SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL));

    Semaphore_Struct *semaphore = (Semaphore_Struct *)handle;

    Semaphore_destruct(semaphore);

    /* Release or free the memory */
    Memory_free(NULL, (Semaphore_Struct *)handle, sizeof(Semaphore_Struct));

    return (SemaphoreP_OK);
}


/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - mode: SemOSAL_Mode_COUNTING
 *   - name: NULL
 *
 *  @param params  Pointer to the instance configuration parameters.
 */

/*
 *  ======== SemaphoreP_Params_init ========
 */
void SemaphoreP_Params_init(SemaphoreP_Params *params)
{
    OSAL_Assert((params == NULL));

    params->mode = SemaphoreP_Mode_COUNTING;
    params->name = NULL;
}

/*!
 *  @brief  Function to pend (wait) on a semaphore.
 *
 *  @param  handle  A SemOSAL_Handle returned from ::SemOSAL_create
 *
 *  @param  timeout Timeout (in milliseconds) to wait for the semaphore to
 *                  be posted (signalled).
 *
 *  @return Status of the functions
 *    - OSAL_OK: Obtain the semaphore
 *    - OSAL_TIMEOUT: Timed out. Semaphore was not obtained.
 */
/*
 *  ======== SemaphoreP_pend ========
 */
SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle handle, uint32_t timeout)
{
    Bool flag;

    OSAL_Assert((handle == NULL));

    flag = Semaphore_pend((Semaphore_Handle)handle, timeout);
    if (FALSE == flag) {
        return (SemaphoreP_TIMEOUT);
    }

    return (SemaphoreP_OK);
}

/*!
 *  @brief  Function to post (signal) a semaphore.
 *
 *  @param  handle  A SemOSAL_Handle returned from ::SemOSAL_create
 *
 *  @return Status of the functions
 *    - OSAL_OK: Released the semaphore
 */
/*
 *  ======== SemaphoreP_post ========
 */
SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL));

    Semaphore_post((Semaphore_Handle)handle);
    return (SemaphoreP_OK);
}

/*!
 *  @brief  Function to disable interrupts to enter a critical region
 *
 *  TODO more details
 *
 *  @return todo key
 */
/*
 *  ======== HwiP_disable ========
 */
uintptr_t HwiP_disable(void)
{
      return (Hwi_disable());
}

/*!
 *  @brief  Function to restore interrupts to exit a critical region
 *
 *  TODO more details
 *
 *  @param  key
 */
/*
 *  ======== HwiP_restore ========
 */
void HwiP_restore(uintptr_t key)
{
    Hwi_restore(key);
}

/*!
 *  @brief  Function to deregister a interrupt
 *
 *  TODO more detail
 *
 *  @param  hwiPtr
 *
 *  @return
 */

/*
 *  ======== HwiP_delete ========
 */
HwiP_Status HwiP_delete(HwiP_Handle handle)
{
    OSAL_Assert((handle == NULL));

    Hwi_Struct *hwi = (Hwi_Struct *)handle;

    Hwi_destruct(hwi);

    Memory_free(NULL, (Hwi_Struct *)handle, sizeof(Hwi_Struct));

    return (HwiP_OK);
}


/*!
 *  @brief  Function to register an interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 *
 *  @param  eventID
 *
 *  @param  entry entry function of the hardware interrupt
 *
 *  @param  arg  argument passed into hte entry function
 *
 *  @param  priority
 *
 *  @return
 */
HwiP_Handle HwiP_create(int interruptNum, HwiP_Fxn hwiFxn,
                        HwiP_Params *params)
{
    Hwi_Struct *handle;
    Error_Block eb;
    Hwi_Params  hwiParams;

    Error_init(&eb);

     /* Grab the memory from the above static array or from the system heap */
    handle = (Hwi_Struct *)Memory_alloc(NULL, sizeof(Hwi_Struct),
                                        0, &eb);
    if (handle == NULL) {
        return (NULL);
    }

    if (params == NULL) {
        Hwi_construct(handle, interruptNum, (Hwi_FuncPtr)hwiFxn, NULL, &eb);
    }
    else {
        Hwi_Params_init(&hwiParams);
        hwiParams.instance->name = params->name;
        hwiParams.arg            = (xdc_UArg)(params->arg);
        hwiParams.priority       = (int)params->priority;
        hwiParams.eventId        = params->evtId;
        Hwi_construct(handle, interruptNum, (Hwi_FuncPtr)hwiFxn,
                      &hwiParams, &eb);
    }

    return ((HwiP_Handle)handle);
}


/*!
 *  @brief  Function to initialize Hwi parameters
 *
 *
 *  @param  params
 *
 *  @return
 */
void HwiP_Params_init(HwiP_Params *params)
{
    params->name = NULL;
    params->arg = 0;
    params->priority = ~0;
}

/**
 *  @b Description
 *  @n
 *      The function is used to disable specific hardware interrupt.
 *
 *  @param[in]  intrNum  number of hardware interrupt which should be disabled.
 *
 *  @retval
 *      Not Applicable
 */
/*
 *  ======== HwiP_disableInterrupt ========
 */
void HwiP_disableInterrupt(int interruptNum)
{
    Hwi_disableInterrupt(interruptNum);
}

/**
 *  @b Description
 *  @n
 *      The function is used to enable specific hardware interrupt.
 *
 *  @param[in]  intrNum  number of hardware interrupt which should be enabled.
 *
 *  @retval
 *      Not Applicable
 */
/*
 *  ======== HwiP_enableInterrupt ========
 */
void HwiP_enableInterrupt(int interruptNum)
{
    Hwi_enableInterrupt(interruptNum);
}

#endif
