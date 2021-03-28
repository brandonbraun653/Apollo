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

/**
 *  \ingroup DRV_OSAL_MODULE
 *  \defgroup DRV_OSAL_SemaphoreP SemaphoreP
 *            SemaphoreP interface
 *
 *  @{
 */

/** ============================================================================
 *  @file       SemaphoreP.h
 *
 *  @brief      Semaphore module for the RTOS Porting Interface
 *
 *  Semaphores can be counting semaphores or binary semaphores. Counting
 *  semaphores keep track of the number of times the semaphore has been posted
 *  with post functions. This is useful, for example, if you have a group of
 *  resources that are shared between tasks. Such tasks might call pend() to see
 *  if a resource is available before using one. A count of zero for a counting
 *  semaphore denotes that it is not available. A positive count denotes
 *  how many times a SemaphoreP_pend can be called before it is blocked (or
 *  returns SemaphoreP_TIMEOUT).
 *
 *  Binary semaphores can have only two states: available (count = 1) and
 *  unavailable (count = 0). They can be used to share a single resource
 *  between tasks. They can also be used for a basic signalling mechanism, where
 *  the semaphore can be posted multiple times. Binary semaphores do not keep
 *  track of the count; they simply track whether the semaphore has been posted
 *  or not.
 *
 *  ============================================================================
 */

#ifndef ti_osal_SemaphoreP__include
#define ti_osal_SemaphoreP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 *  \anchor SemaphoreP_Status
 *  \name Semaphore status code
 *  @{
 */
/*!
 *  @brief    Status codes for SemaphoreP APIs
 */
typedef int32_t SemaphoreP_Status;
#define SemaphoreP_OK                           (0)
/*! API completed successfully */
#define SemaphoreP_FAILURE                      (-(int32_t)1)
/*! API failed */
#define SemaphoreP_TIMEOUT                      (-(int32_t)2)
/*! API failed because of a timeout */
#define SemaphoreP_UNSUPPORTED                  (-(int32_t)3)
/*! API failed because of not supported */
/* @} */

/*!
 *  @brief    Wait forever define
 */
#define SemaphoreP_WAIT_FOREVER (~((uint32_t)0U))

/*!
 *  @brief    No wait define
 */
#define SemaphoreP_NO_WAIT       ((uint32_t)0U)

/*!
 *  @brief    Opaque client reference to an instance of a SemaphoreP
 *
 *  A SemaphoreP_Handle returned from the ::SemaphoreP_create represents that
 *  instance and  is used in the other instance based functions (e.g.
 *  ::SemaphoreP_post or ::SemaphoreP_pend, etc.).
 */
typedef  void *SemaphoreP_Handle;

/**
 *  \anchor SemaphoreP_Mode
 *  \name Mode of Semaphore
 *  @{
 */
/*!
 *  @brief    Mode of the semaphore
 */
typedef uint32_t SemaphoreP_Mode;
#define SemaphoreP_Mode_COUNTING                (0x0U)
#define SemaphoreP_Mode_BINARY                  (0x1U)
/* @} */

/*!
 *  @brief    Basic SemaphoreP Parameters
 *
 *  Structure that contains the parameters are passed into ::SemaphoreP_create
 *  when creating a SemaphoreP instance. The ::SemaphoreP_Params_init function
 *  should be used to initialize the fields to default values before the
 *  application sets the fields manually. The SemaphoreP default parameters are
 *  noted in SemaphoreP_Params_init.
 */
typedef struct SemaphoreP_Params_s {
    char *name;           /*!< Name of the semaphore instance. Memory must
                               persist for the life of the semaphore instance */
    SemaphoreP_Mode mode; /*!< Mode for the semaphore */
    uint32_t maxCount;    /*!< The max count allowed for counting semaphore */
} SemaphoreP_Params;

/*!
 *  @brief  Function to create a semaphore.
 *
 *  @param  count  Initial count of the semaphore. For binary semaphores,
 *                 only values of 0 or 1 are valid.
 *
 *  @param  semParams  Pointer to the instance configuration parameters. NULL
 *                  denotes to use the default parameters (SemaphoreP default
 *                  parameters as noted in ::SemaphoreP_Params_init.
 *
 *  @return A SemaphoreP_Handle on success or a NULL on an error
 */
extern SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                           const SemaphoreP_Params *semParams);

/*!
 *  @brief  Function to delete a semaphore.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @return Status of the functions
 *    - SemaphoreP_OK: Deleted the semaphore instance
 *    - SemaphoreP_FAILED: Failed to delete the semaphore instance
 */
extern SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle semPhandle);

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - mode: SemaphoreP_Mode_COUNTING
 *   - name: NULL
 *
 *  @param semParams  Pointer to the instance configuration parameters.
 */
extern void SemaphoreP_Params_init(SemaphoreP_Params *semParams);

/*!
 *  @brief  Function to pend (wait) on a semaphore.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @param  timeout Timeout (in milliseconds) to wait for the semaphore to
 *                  be posted (signalled).
 *
 *  @return Status of the functions
 *    - SemaphoreP_OK: Obtain the semaphore
 *    - SemaphoreP_TIMEOUT: Timed out. Semaphore was not obtained.
 *    - SemaphoreP_FAILED: Non-time out failure.
 */
extern SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle semPhandle,
                                         uint32_t timeout);

/*!
 *  @brief  Function to post (signal) a semaphore.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @return Status of the functions
 *    - SemaphoreP_OK: Released the semaphore
 *    - SemaphoreP_FAILED: Failed to post the semaphore
 */
extern SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle semPhandle);

/*!
 *  @brief  Function to post (signal) a semaphore from an ClockP function.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @return Status of the functions
 *    - SemaphoreP_OK: Released the semaphore
 *    - SemaphoreP_FAILED: Failed to post the semaphore
 */
extern SemaphoreP_Status SemaphoreP_postFromClock(SemaphoreP_Handle semPhandle);

/*!
 *  @brief  Function to post (signal) a semaphore from an ISR.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @return Status of the functions
 *    - SemaphoreP_OK: Released the semaphore
 *    - SemaphoreP_FAILED: Failed to post the semaphore
 */
extern SemaphoreP_Status SemaphoreP_postFromISR(SemaphoreP_Handle semPhandle);
/*!
 *  @brief  Function to return the count of a semaphore.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 *
 *  @return The count of the semaphore
 */

extern int32_t SemaphoreP_getCount(SemaphoreP_Handle semPhandle);

/*!
 *  @brief  Function to clear a semaphore for resuse.
 *
 *  @param  semPhandle  A SemaphoreP_Handle returned from ::SemaphoreP_create
 */

extern SemaphoreP_Status SemaphoreP_reset(SemaphoreP_Handle semPhandle);
#ifdef __cplusplus
}
#endif

#endif /* ti_osal_SemaphoreP__include */
/* @} */
