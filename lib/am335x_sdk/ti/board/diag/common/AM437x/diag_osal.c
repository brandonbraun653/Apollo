/**
 *   @file  diag_osal.c
 *
 *   @brief
 *      This is the OS abstraction layer and is used by the GPIO application.
 *
 *  \par
 */

/*
 * Copyright (C) 2014-2016 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef COMMON_OSAL_PROTOTYPE
#define COMMON_OSAL_PROTOTYPE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ti/drv/uart/src/UART_osal.h>
//#include <ti/drv/spi/SPI_osal.h>

#define OSAL_OK 0
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
//void* SemOSAL_create(unsigned int count,SemOSAL_Params *params)
//{
//	return (void *) -1;
//}

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
int SemOSAL_delete(void* handle)
{
	return 0;
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
//void SemOSAL_Params_init(SemOSAL_Params *params)
//{
//}

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
int SemOSAL_pend(void* handle,unsigned int timeout)
{
    return (OSAL_OK);
}

/*!
 *  @brief  Function to post (signal) a semaphore.
 *
 *  @param  handle  A SemOSAL_Handle returned from ::SemOSAL_create
 *
 *  @return Status of the functions
 *    - OSAL_OK: Released the semaphore
 */
int SemOSAL_post(void* semHandle)
{
    return (OSAL_OK);
}

/*!
 *  @brief  Function to disable interrupts to enter a critical region
 *
 *  TODO more details
 *
 *  @return todo key
 */
int HwiOSAL_enterCritical()
{
   return(0);
}

/*!
 *  @brief  Function to restore interrupts to exit a critical region
 *
 *  TODO more details
 *
 *  @param  key
 */
void HwiOSAL_exitCritical(int key)
{
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

int HwiOSAL_deregisterInterrupt(void* hwiPtr)
{
    return (OSAL_OK);
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
#if 0
void* HwiOSAL_registerInterrupt(int intNum,
                                    int eventID,
                                    HwiOSAL_EntryFxn entry,
                                    void* arg,
                                    unsigned char priority)
{
	return (void *) -1;
}
#endif
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
void HwiOSAL_disableInterrupt(unsigned int intrNum)
{
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
void HwiOSAL_enableInterrupt(unsigned int intrNum)
{
}


/*!
 *  @brief  Debug log function with 1 parameters
 *
 *  TODO more detail
 *
 *  @param  format "printf" format string
 *  @param  p1 first parameter to format string
 */
void UART_log1(const char *format, unsigned int p1)
{

}

/*!
 *  @brief  Debug log function with 2 parameters
 *
 *  TODO more detail
 *
 *  @param  format "printf" format string
 *  @param  p1 first parameter to format string
 *  @param  p2 second parameter to format string
 */
void UART_log2(const char *format, unsigned int p1, unsigned int p2)
{

}
/*!
 *  @brief  Debug log function with 3 parameters
 *
 *  TODO more detail
 *
 *  @param  format "printf" format string
 *  @param  p1 first parameter to format string
 *  @param  p2 second parameter to format string
 *  @param  p3 third parameter to format string
 */
void UART_log3(const char *format, unsigned int p1, unsigned int p2, unsigned int p3)
{

}

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
SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                    SemaphoreP_Params *params)
{
    return NULL;
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
    return 0;
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
    return (HwiP_OK);
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
void HwiP_disableInterrupt(int32_t interruptNum)
{
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
void HwiP_enableInterrupt(int32_t interruptNum)
{
}

void HwiP_Params_init(HwiP_Params *params)
{
}

HwiP_Handle HwiP_create(int32_t interruptNum, HwiP_Fxn hwiFxn,
                        HwiP_Params *params)
{
    return (void *) -1;
}

void _DebugP_assert(int32_t expression, const char *file, int32_t line)
{
  if (expression)
     while (1);
}

Osal_ThreadType Osal_getThreadType(void)
{
    return (Osal_ThreadType_Main);
}

int32_t Osal_delay(uint32_t nTicks)
{
    return osal_OK;
}
#endif  /* COMMON_OSAL_PROTOTYPE */
