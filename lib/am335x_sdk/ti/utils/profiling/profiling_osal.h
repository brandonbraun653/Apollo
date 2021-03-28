/**
 *  @file   profiling_osal.h
 *
 *  @brief  This is the OS Adaptation Layer used by the PDK Utilities
 *          primarily for instantiating interrupt functions for the ARM
 *          platform while profiling is running.
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef profiling_osal_H
#define profiling_osal_H

#ifndef COMMON_OSAL_DATATYPES
#define COMMON_OSAL_DATATYPES

#define OSAL_OK  (0)
#define OSAL_FAILURE (-(1))
#define OSAL_TIMEOUT (2)

/*!
 *  @brief    Status codes for SemaphoreP APIs
 */
typedef enum SemaphoreP_Status_e {
    /*! API completed successfully */
    SemaphoreP_OK = 0,
    /*! API failed */
    SemaphoreP_FAILURE = -1,
    /*! API failed because of a timeout */
    SemaphoreP_TIMEOUT = -2
} SemaphoreP_Status;

/*!
 *  @brief    Wait forever define
 */
#define SemaphoreP_WAIT_FOREVER  (~(0))

/*!
 *  @brief    No wait define
 */
#define SemaphoreP_NO_WAIT       (0)


/*!
 *  @brief    Opaque client reference to an instance of a SemaphoreP
 *
 *  A SemaphoreP_Handle returned from the SemaphoreP_create represents that
 *  instance and  is used in the other instance based functions (e.g.
 *  SemaphoreP_post or SemaphoreP_pend, etc.).
 */
typedef  void *SemaphoreP_Handle;

/*!
 *  @brief    Mode of the semaphore
 */
typedef enum SemaphoreP_Mode_e {
    SemaphoreP_Mode_COUNTING = 0x0,
    SemaphoreP_Mode_BINARY   = 0x1
} SemaphoreP_Mode;

/*!
 *  @brief    Basic SemaphoreP Parameters
 *
 *  Structure that contains the parameters are passed into SemaphoreP_create
 *  when creating a SemaphoreP instance. The SemaphoreP_Params_init function
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
 *  @brief    Opaque client reference to an instance of a HwiP
 *
 *  A HwiP_Handle returned from the HwiP_create represents that instance.
 */
typedef  void *HwiP_Handle;

/*!
 *  @brief    Status codes for HwiP APIs
 */
typedef enum HwiP_Status_e {
    HwiP_OK = 0,
    HwiP_FAILURE = -1
} HwiP_Status;


/*!
 *  @brief  Prototype for the entry function for a hardware interrupt
 */
typedef void (*HwiP_Fxn)(uintptr_t arg);


/*!
 *  @brief    Basic HwiP Parameters
 *
 *  Structure that contains the parameters passed into ::HwiP_create
 *  when creating a HwiP instance. The ::HwiP_Params_init function should
 *  be used to initialize the fields to default values before the application sets
 *  the fields manually. The HwiP default parameters are noted in
 *  HwiP_Params_init.
 */
typedef struct HwiP_Params_s {
    char      *name;      /*!< Name of the clock instance. Memory must
                               persist for the life of the clock instance.
                               This can be used for debugging purposes, or
                               set to NULL if not needed. */
    uintptr_t  arg;       /*!< Argument passed into the Hwi function. */
    uint32_t   priority;  /*!< Device specific priority. */
    uint32_t   evtId;     /*!< Event Id. */
} HwiP_Params;



#define OSAL_Assert(expr)  {                      \
                             if(expr)             \
                             {                    \
                                while(1);         \
                             }                    \
                           }

#endif /* COMMON_OSAL_DATATYPES */
/**********************************************************************
 ************************* Extern Declarations ************************
 **********************************************************************/

extern SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                           SemaphoreP_Params *params);
extern SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle handle);
extern void SemaphoreP_Params_init(SemaphoreP_Params *params);
extern SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle handle,
                                         uint32_t timeout);
extern SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle handle);
extern uintptr_t HwiP_disable(void);
extern void HwiP_restore(uintptr_t key);
extern HwiP_Status HwiP_delete(HwiP_Handle handle);
extern void HwiP_disableInterrupt(int32_t interruptNum);
extern void HwiP_enableInterrupt(int32_t interruptNum);
extern HwiP_Handle HwiP_create(int32_t interruptNum, HwiP_Fxn hwiFxn,
                               HwiP_Params *params);
extern void HwiP_Params_init(HwiP_Params *params);

/**
 * @brief   Assert API. If expression is true then it will stay in the while
 *          loop.
 *
 * @param   expr  Expression which need to be evaluated.
 *
 */
#define profiling_osalAssert(expr)         OSAL_Assert(expr)

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - mode: SemOSAL_Mode_COUNTING
 *   - name: NULL
 *
 *  @param params  Pointer to the instance configuration parameters.
 */
#define profiling_osalSemParamsInit(params)  (SemaphoreP_Params_init(params))

/**
 * @brief   Function to disable interrupts to enter a critical region
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       void HwiOSAL_enterCritical()
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Not Applicable
 *
 *  <b> Return Value </b>
 *  @n  Interrupt key
 */
#define profiling_osalHardwareIntDisable() (HwiP_disable())

/**
 * @brief   Function to restore interrupts to exit a critical region
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       void HwiOSAL_exitCritical(int key)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Interrupt key
 *
 *  <b> Return Value </b>
 *  @n  Not Applicable
 */
#define profiling_osalHardwareIntRestore(X) (HwiP_restore(X))

/**
 * @brief  Function to deregister a interrupt
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       int HwiOSAL_deregisterInterrupt(void* hwiPtr)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Interrupt handler
 *
 *  <b> Return Value </b>
 *  @n  status of operation
 */
#define profiling_osalHardwareIntDestruct(X)  (HwiP_delete(X))

/**
 * @brief  Function to register an interrupt
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       int HwiOSAL_registerInterrupt(X,Y,Z,U,V)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Interrupt number
 *
 *  <b> Parameter </b>
 *  @n  eventID
 *
 *  <b> Parameter </b>
 *  @n  entry entry function of the hardware interrupt
 *
 *  <b> Parameter </b>
 *  @n  arg  argument passed into the entry function
 *
 *  <b> Parameter </b>
 *  @n  priority
 *
 *  <b> Return Value </b>
 *  @n  Interrupt handler
 */
#define profiling_osalRegisterInterrupt(X,Y,Z)     (HwiP_create((X),(Y),(Z)))


/**
 * @brief  Function to initialize hardware interrupt parameters.
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       void HwiP_Params_init(X)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  params pointer to the hardware interrupts parameter structure
 *
 */
#define profiling_osalHwiParamsInit(X)             (HwiP_Params_init(X))


/**
 * @brief  Function to disable specific hardware interrupt
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       void HwiOSAL_disableInterrupt(uint32_t intrNum)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Interrupt number
 *
 */
#define profiling_osalHardwareIntrDisable(X)    (HwiP_disableInterrupt(X))

/**
 * @brief  Function to enable specific hardware interrupt
 *
 * <b> Prototype: </b>
 *  The following is the C prototype for the expected OSAL API.
 *
 *  @verbatim
       void HwiOSAL_enableInterrupt(uint32_t intrNum)
    @endverbatim
 *
 *  <b> Parameter </b>
 *  @n  Interrupt number
 *
 */
#define profiling_osalHardwareIntrEnable(X)     (HwiP_enableInterrupt(X))

#endif /* profiling_osal_H */
