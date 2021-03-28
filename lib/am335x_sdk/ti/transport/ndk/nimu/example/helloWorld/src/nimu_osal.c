/****************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
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
 *****************************************************************************/

/*
 *   @file  nimu_osal.c
 *
 *   @brief
 *      This file implements the OSAL layers for the various LLD's and libraries that the application
 *      use.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


/* Resource manager for QMSS, PA, CPPI */
#include "ti/transport/ndk/nimu/example/helloWorld/src/nimu_cppi_qmss_iface.h"

/* NIMU */
//#include "ti/transport/ndk/nimu/src/v2/nimu_eth.h"

#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/csl/csl_semAux.h>
/* CSL CHIP, SEM Functional layer includes */
#include <ti/csl/csl_chip.h>
#ifdef _TMS320C6X
#include <ti/csl/csl_semAux.h>
/* CSL Cache module includes */
#include <ti/csl/csl_cacheAux.h>
#endif

/* XDC/BIOS includes */
#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/heaps/HeapBuf.h>
#include <ti/sysbios/heaps/HeapMem.h>

#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#else
#include <ti/sysbios/family/arm/gic/Hwi.h>
#include <ti/sysbios/family/arm/a15/Mmu.h>
#endif

/* Resource manager for QMSS, PA, CPPI */
#include "ti/transport/ndk/nimu/example/helloWorld/src/nimu_cppi_qmss_iface.h"
#include <ti/drv/cppi/cppi_desc.h>

    /* Invalidate L2 cache. This should invalidate L1D as well. 
     * Wait until operation is complete. */    
#define SYS_CACHE_INV_L2(addr, size, code)    CACHE_invL2 (addr, size, code)

    /* Writeback L2 cache. This should Writeback L1D as well. 
     * Wait until operation is complete. */ 
#define SYS_CACHE_WB_L2(addr, size, code)     CACHE_wbL2 (addr, size, code)

    /* Invalidate L1D cache and wait until operation is complete. 
     * Use this approach if L2 cache is not enabled */    
#define SYS_CACHE_INV_L1(addr, size, code)    CACHE_invL1d (addr, size, code)
    /* Writeback L1D cache and wait until operation is complete. 
     * Use this approach if L2 cache is not enabled */    
#define SYS_CACHE_WB_L1(addr, size, code)     CACHE_wbL1d (addr, size, code)

uint32_t    rmMallocCounter         =   0;
uint32_t    rmFreeCounter           =   0;

#define     EMAC_HW_SEM         5 
#define MAX_NUM_CORES 1
UInt32      coreKey [MAX_NUM_CORES];




void Osal_TaskSleep(uint32_t sleepTime)
{
    Task_sleep(sleepTime);
}
void Osal_TaskCreate(void* pCbFn)
{

    Task_Params     taskParams;
    Error_Block eb;

    Error_init(&eb);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacPollLink";
    Task_create((ti_sysbios_knl_Task_FuncPtr)pCbFn, &taskParams, &eb);


}
/**
 *  @b Description
 *  @n
 *      The function is used to provide critical section to prevent access of shared
 *      resources from single core and multiple threads.
 *
 *  @param[in]  port_num
 *      EMAC port number which needs critical section to protect its resources.
 *
 *  @retval
 *      None
 */
void
Osal_enterSingleCoreCriticalSection
(
    Uint32      port_num
)
{
    uint32_t coreNum = 0;
#ifdef _TMS320C6X
    coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);
#else
    coreNum = 0;
#endif
    /* Get the hardware semaphore. 
     *
     * Acquire Multi core EMAC synchronization lock 
     */
    while ((CSL_semAcquireDirect (EMAC_HW_SEM)) == 0);

    /* Disable all interrupts and OS scheduler. 
     *
     * Acquire Multi threaded / process synchronization lock.
     */
    coreKey [coreNum] = Hwi_disable();

    return;



}
/**
 *  @b Description
 *  @n
 *      The function is called to end the critical section access of shared resources
 *      from single cores.
 *
 *  @param[in]  port_num
 *      EMAC port number which needs critical section to protect its resources.
 *
 *  @retval
 *      None
 */
void
Osal_exitSingleCoreCriticalSection
(
    Uint32      port_num
)
{
    uint32_t coreNum = 0;
#ifdef _TMS320C6X
    coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);
#else
    coreNum = 0;
#endif
   /* Enable all interrupts and enables the OS scheduler back on.
     *
     * Release multi-threaded / multi-process lock on this core.
     */
    Hwi_restore(coreKey [coreNum]);

    /* Release the hardware semaphore 
     *
     * Release multi-core lock.
     */ 
    CSL_semReleaseSemaphore (EMAC_HW_SEM);

    return;
}
/**
 * ============================================================================
 *  @n@b Osal_platformMalloc
 *
 *  @b  brief
 *  @n  This routine implements the memory handler for Platform Library.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @return
 *      Allocated block address
 * =============================================================================
 */
uint8_t *Osal_platformMalloc (uint32_t num_bytes, uint32_t alignment)
{
    Error_Block        errorBlock;

    /* Allocate memory.  */
    Error_init(&errorBlock);

    return Memory_alloc(NULL, num_bytes, alignment, &errorBlock);
}

/**
 * ============================================================================
 *  @n@b Osal_platformFree
 *
 *  @b  brief
 *  @n  This routine implements the memory free handler for Platform Library.
 *        Frees up memory allocated using
 *      @a Osal_platformMalloc ()
 *
 *  @param[in]  dataPtr
 *      Pointer to the memory block to be cleaned up.
 *
 *  @param[in]  num_bytes
 *      Size of the memory block to be cleaned up.
 *
 *  @return
 *      Not Applicable
 * =============================================================================
 */
void Osal_platformFree (uint8_t *dataPtr, uint32_t num_bytes)
{

    /* Free up the memory */
    if (dataPtr)
    {
        Memory_free(NULL, dataPtr, num_bytes);
    }
}

/**
 * ============================================================================
 *  @n@b Osal_platformSpiCsEnter
 *
 *  @b  brief
 *  @n  This API ensures multi-core and multi-threaded
 *      synchronization for the SPI bus.
 *
 *      This is a BLOCKING API.
 *.
 *
 *  @param[in]
 *  @n  None
 *
 *  @return
 *  @n  Nothing
 * =============================================================================
 */
void Osal_platformSpiCsEnter(void)
{
    /* Get the hardware semaphore.
     *
     * Acquire Multi core CPPI synchronization lock
     */
    while ((CSL_semAcquireDirect (NIMU_SPI_HW_SEM)) == 0);

    return;
}

/**
 * ============================================================================
 *  @n@b Osal_platformSpiCsExit
 *
 *  @b  brief
 *  @n  This API needs to be called to exit a previously
 *      acquired critical section lock using @a Osal_platformSpiCsEnter ()
 *      API. It resets the multi-core and multi-threaded lock,
 *      enabling another process/core to grab the SPI bus.
 *     
 *
 *  @return     None
 * =============================================================================
 */
void Osal_platformSpiCsExit (void)
{
    /* Release the hardware semaphore
     *
     * Release multi-core lock.
     */
    CSL_semReleaseSemaphore (NIMU_SPI_HW_SEM);

    return;
}


/**********************************************************************
 *********************** NIMU OSAL Functions **************************
 **********************************************************************/
/**
 * ============================================================================
 *  @n@b Osal_nimuMalloc
 *
 *  @b  brief
 *  @n  This routine implements the memory handler for the NIMU library. The API
 *      allocates a memory block of a given size specified by input parameter 'num_bytes'.
 *
 *      This API should allocate memory from shared memory.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @return
 *      Allocated block address
 * =============================================================================
 */
Ptr Osal_nimuMalloc (uint32_t num_bytes, uint32_t alignment)
{
#ifdef _TMS320C6X
    Error_Block        errorBlock;

    /* Allocate memory.  */
    Error_init(&errorBlock);

    return Memory_alloc(NULL, num_bytes, alignment, &errorBlock);
#else
    uint8_t* pDataBuffer = NULL;
    if ((pDataBuffer = (Ptr) Memory_alloc(NULL, num_bytes, 0, NULL)) == NULL)
    {
        platform_write ("Error allocating memory for Rx data buffer \n");
    }
    return (pDataBuffer);
#endif
    
}

/**
 * ============================================================================
 *  @n@b Osal_nimuFree
 *
 *  @b  brief
 *  @n  This API frees and restores a given memory location
 *      pointer 'dataPtr' of size 'num_bytes' to its
 *      original heap location. Frees up memory allocated using
 *      @a Osal_nimuMalloc ()
 *
 *  @param[in]  dataPtr
 *      Pointer to the memory block to be cleaned up.
 *
 *  @param[in]  num_bytes
 *      Size of the memory block to be cleaned up.
 *
 *  @return
 *      Not Applicable
 * =============================================================================
 */
void Osal_nimuFree (Ptr dataPtr, uint32_t num_bytes)
{

    /* Free up the memory */
    if (dataPtr)
    {
        Memory_free(NULL, dataPtr, num_bytes);
    }
}

/**********************************************************************
 *********************** CPPI OSAL Functions **************************
 **********************************************************************/

/**
 * ============================================================================
 *  @n@b Osal_cppiCsEnter
 *
 *  @b  brief
 *  @n  This API ensures multi-core and multi-threaded
 *      synchronization to the caller.
 *
 *      This is a BLOCKING API.
 *
 *      This API ensures multi-core synchronization between
 *      multiple processes trying to access CPPI shared
 *      library at the same time.
 *
 *  @param[in]
 *  @n  None
 *
 *  @return
 *  @n  Handle used to lock critical section
 * =============================================================================
 */
Ptr Osal_cppiCsEnter (void)
{
    /* Get the hardware semaphore.
     *
     * Acquire Multi core CPPI synchronization lock
     */
    while ((CSL_semAcquireDirect (NIMU_CPPI_HW_SEM)) == 0);

    return NULL;
}

/**
 * ============================================================================
 *  @n@b Osal_cppiCsExit
 *
 *  @b  brief
 *  @n  This API needs to be called to exit a previously
 *      acquired critical section lock using @a Osal_cppiCsEnter ()
 *      API. It resets the multi-core and multi-threaded lock,
 *      enabling another process/core to grab CPPI access.
 *
 *  @param[in]  CsHandle
 *      Handle for unlocking critical section.
 *
 *  @return     None
 * =============================================================================
 */
void Osal_cppiCsExit (Ptr CsHandle)
{
    /* Release the hardware semaphore
     *
     * Release multi-core lock.
     */
    CSL_semReleaseSemaphore (NIMU_CPPI_HW_SEM);

    return;
}


/**
 * ============================================================================
 *  @n@b Osal_cppiMalloc
 *
 *  @b  brief
 *  @n  This API allocates a memory block of a given
 *      size specified by input parameter 'num_bytes'.
 *
 *      This API should allocate memory from shared memory if the test applications
 *      are to be run on multiple cores.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @return
 *      Allocated block address
 * =============================================================================
 */
Ptr Osal_cppiMalloc (uint32_t num_bytes)
{
    Error_Block        errorBlock;

    /* Allocate memory.  */
    Error_init(&errorBlock);

    return Memory_alloc(NULL, num_bytes, CACHE_LINESZ, &errorBlock);
}

/**
 * ============================================================================
 *  @n@b Osal_cppiFree
 *
 *  @b  brief
 *  @n  This API frees and restores a given memory location
 *      pointer 'dataPtr' of size 'num_bytes' to its
 *      original heap location. Frees up memory allocated using
 *      @a Osal_cppiMalloc ()
 *
 *  @param[in]  dataPtr
 *      Pointer to the memory block to be cleaned up.
 *
 *  @param[in]  num_bytes
 *      Size of the memory block to be cleaned up.
 *
 *  @return
 *      Not Applicable
 * =============================================================================
 */
void Osal_cppiFree (Ptr dataPtr, uint32_t num_bytes)
{

    /* Free up the memory */
    if (dataPtr)
    {
        /* Convert the global address to local address since
         * thats what the heap understands.
         */
        Memory_free(NULL, dataPtr, num_bytes);
    }
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that a block of memory is
 *      about to be accessed. If the memory block is cached then this
 *      indicates that the application would need to ensure that the
 *      cache is updated with the data from the actual memory.
 *
 *  @param[in]  blockPtr
 *       Address of the block which is to be invalidated
 *
 *  @param[in]  size
 *       Size of the block to be invalidated

 *  @retval
 *      Not Applicable
 */
void Osal_cppiBeginMemAccess (void *blockPtr, uint32_t size)
{
    /* Cache coherence protection is only required for multi-core application */
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that the block of memory has
 *      finished being accessed. If the memory block is cached then the
 *      application would need to ensure that the contents of the cache
 *      are updated immediately to the actual memory.
 *
 *  @param[in]  blockPtr
 *       Address of the block which is to be written back
 *
 *  @param[in]  size
 *       Size of the block to be written back

 *  @retval
 *      Not Applicable
 */
void Osal_cppiEndMemAccess (void *blockPtr, uint32_t size)
{
    /* Cache coherence protection is only required for multi-core application */
    return;
}

/**********************************************************************
 *********************** QMSS OSAL Functions **************************
 **********************************************************************/

/**
 * ============================================================================
 *  @n@b Osal_qmssCsEnter
 *
 *  @b  brief
 *  @n  This API ensures multi-core and multi-threaded
 *      synchronization to the caller.
 *
 *      This is a BLOCKING API.
 *
 *      This API ensures multi-core synchronization between
 *      multiple processes trying to access QMSS shared
 *      library at the same time.
 *
 *  @param[in]  None
 *
 *  @return
 *      Handle used to lock critical section
 * =============================================================================
 */
Ptr Osal_qmssCsEnter (void)
{
    /* Get the hardware semaphore.
     *
     * Acquire Multi core QMSS synchronization lock
     */
    while ((CSL_semAcquireDirect (NIMU_QMSS_HW_SEM)) == 0);

    return NULL;
}

/**
 * ============================================================================
 *  @n@b Osal_qmssCsExit
 *
 *  @b  brief
 *  @n  This API needs to be called to exit a previously
 *      acquired critical section lock using @a Osal_cpswQmssCsEnter ()
 *      API. It resets the multi-core and multi-threaded lock,
 *      enabling another process/core to grab QMSS access.
 *
 *  @param[in]  CsHandle
 *      Handle for unlocking critical section.
 *
 *  @return     None
 * =============================================================================
 */
void Osal_qmssCsExit (Ptr CsHandle)
{
    /* Release the hardware semaphore
     *
     * Release multi-core lock.
     */
    CSL_semReleaseSemaphore (NIMU_QMSS_HW_SEM);

    return;
}

/**
 * ============================================================================
 *  @n@b Osal_qmssMtCsEnter
 *
 *  @b  brief
 *  @n  This API ensures ONLY multi-threaded
 *      synchronization to the QMSS user.
 *
 *      This is a BLOCKING API.
 *
 *  @param[in] None
 *
 *  @return
 *       Handle used to lock critical section
 * =============================================================================
 */
Ptr Osal_qmssMtCsEnter (void)
{
    /*
     * Current demos are not multi-threaded.
     */
    return NULL;
}

/**
 * ============================================================================
 *  @n@b Osal_qmssMtCsExit
 *
 *  @b  brief
 *  @n  This API needs to be called to exit a previously
 *      acquired critical section lock using @a Osal_cpswQmssMtCsEnter ()
 *      API. It resets the multi-threaded lock, enabling another process
 *      on the current core to grab it.
 *
 *  @param[in]  CsHandle
 *      Handle for unlocking critical section.
 *
 *  @return     None
 * =============================================================================
 */
void Osal_qmssMtCsExit (Ptr CsHandle)
{
    /*
     * Release multi-threaded / multi-process lock on this core.
     */
    return;
}

/**
* ============================================================================
*  @n@b Osal_qmssAccCsEnter
*
*  @b  brief
*  @n  This API ensures multi-core and multi-threaded
*      synchronization to the caller.
*
*      This is a BLOCKING API.
*
*      This API ensures multi-core synchronization between
*      multiple processes trying to access QMSS shared
*      library at the same time.
*
*  @param[in]  None
*
*  @return     
 *      Handle used to lock critical section
* =============================================================================
*/
Ptr Osal_qmssAccCsEnter (Void)
{
    /* This is a suboptimal implementation for this OSAL, please refer to
       * QMSS examples for optimal implementation of this function 
        */

  return (Osal_qmssCsEnter());
}

/**
* ============================================================================
*  @n@b Osal_qmssAccCsExit
*
*  @b  brief
*  @n  This API needs to be called to exit a previously
*      acquired critical section lock using @a Osal_qmssAccCsEnter ()
*      API. It resets the multi-core and multi-threaded lock,
*      enabling another process/core to grab QMSS access.
*
*  @param[in]  CsHandle
*      Handle for unlocking critical section.
*
*  @return     None
* =============================================================================
*/
Void Osal_qmssAccCsExit (Ptr CsHandle)
{
    /* This is a suboptimal implementation for this OSAL, please refer to
       * QMSS examples for optimal implementation of this function 
        */   
   Osal_qmssCsExit(CsHandle);
   return;
}

/**
 * ============================================================================
 *  @n@b Osal_qmssMalloc
 *
 *  @b  brief
 *  @n  This API allocates a memory block of a given
 *      size specified by input parameter 'num_bytes'.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @return
 *      Allocated block address
 * =============================================================================
 */
Ptr Osal_qmssMalloc (uint32_t num_bytes)
{
    Error_Block        errorBlock;

    /* Allocate memory.  */
    Error_init(&errorBlock);

    return Memory_alloc(NULL, num_bytes, CACHE_LINESZ, &errorBlock);
}

/**
 * ============================================================================
 *  @n@b Osal_qmssFree
 *
 *  @b  brief
 *  @n  This API frees and restores a given memory location
 *      pointer 'dataPtr' of size 'num_bytes' to its
 *      original heap location. Frees up memory allocated using
 *      @a Osal_qmssMalloc ()
 *
 *  @param[in]  dataPtr
 *      Pointer to the memory block to be cleaned up.
 *
 *  @param[in]  num_bytes
 *      Size of the memory block to be cleaned up.
 *
 *  @return
 *      Not Applicable
 * =============================================================================
 */
void Osal_qmssFree (Ptr dataPtr, uint32_t num_bytes)
{

    /* Free up the memory */
    if (dataPtr)
    {
        /* Convert the global address to local address since
         * thats what the heap understands.
         */
        Memory_free(NULL, dataPtr, num_bytes);
    }
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that a block of memory is
 *      about to be accessed. If the memory block is cached then this
 *      indicates that the application would need to ensure that the
 *      cache is updated with the data from the actual memory.
 *
 *  @param[in]  blockPtr
 *       Address of the block which is to be invalidated
 *
 *  @param[in]  size
 *       Size of the block to be invalidated

 *  @retval
 *      Not Applicable
 */
void Osal_qmssBeginMemAccess (void *blockPtr, uint32_t size)
{

    /* Cache coherence protection is only required for multi-core application */
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that the block of memory has
 *      finished being accessed. If the memory block is cached then the
 *      application would need to ensure that the contents of the cache
 *      are updated immediately to the actual memory.
 *
 *  @param[in]  blockPtr
 *       Address of the block which is to be written back
 *
 *  @param[in]  size
 *       Size of the block to be written back

 *  @retval
 *      Not Applicable
 */
void Osal_qmssEndMemAccess (void *blockPtr, uint32_t size)
{

    /* Cache coherence protection is only required for multi-core application */
    return;
}

/**********************************************************************
 *********************** PASS OSAL Functions **************************
 **********************************************************************/
/**
 *  @b Description
 *  @n
 *      The function is used to indicate that a block of memory is
 *      about to be accessed. If the memory block is cached then this
 *      indicates that the application would need to ensure that the
 *      cache is updated with the data from the actual memory.
 *
 *  @param[in]  blockPtr
 *       Address of the block which is to be invalidated
 *
 *  @param[in]  size
 *       Size of the block to be invalidated

 *  @retval
 *      Not Applicable
 */
void Osal_paBeginMemAccess (Ptr addr, uint32_t size)
{
    /* Cache coherence protection is only required for multi-core application */
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that the block of memory has
 *      finished being accessed. If the memory block is cached then the
 *      application would need to ensure that the contents of the cache
 *      are updated immediately to the actual memory.
 *
 *  @param[in]  addr
 *       Address of the block which is to be written back
 *
 *  @param[in]  size
 *       Size of the block to be written back

 *  @retval
 *      Not Applicable
 */
void Osal_paEndMemAccess (Ptr addr, uint32_t size)
{
    /* Cache coherence protection is only required for multi-core application */
    return;
}

/* OSAL Functions for the PA LLDs */
Void Osal_paMtCsEnter (uint32_t *key)
{
}

Void Osal_paMtCsExit (uint32_t key)
{
}

#ifdef _TMS320C6X
void NIMU_osalRegisterInterruptDsp(int16_t evt, EventCombiner_FuncPtr fxn, UArg arg, Bool unmask, int32_t vectId)
{
    EventCombiner_dispatchPlug (evt, (EventCombiner_FuncPtr)fxn, (UArg)arg, TRUE);
    EventCombiner_enableEvent(evt);

    /* Map the event id to hardware interrupt 7. */
    Hwi_eventMap(vectId, evt >> 5);

    /* Enable interrupt */
    Hwi_enableInterrupt(vectId);
}
#endif


static uint32_t UtilReadTime32(void)
{
    uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}

void cycleDelayLoc (int32_t iCount)
{
  if (iCount <= 0)
    return;

  /* If there is need for ARM-RTOS, adjust #ifdef to use the PMU
   * via the __asm__ in nwalUtilReadTime32 and use same code as
   * c66 */
//#ifdef __ARMv7
#if 1
  {
    uint32_t start = UtilReadTime32();
    uint32_t count = (uint32_t)iCount;

    while ((UtilReadTime32() - start) < count);
  }
#else
  {
    uint32_t sat;
    /* This code is for user-mode where PMU is inaccessible */
    for (sat=0; sat<(uint32_t)iCount; sat++);
  }
#endif
}


#ifdef __ARM_ARCH_7A__
/**
 *  @b Description
 *  @n
 *     General Memory Barrier guarantees that all LOAD and STORE operations that were issued before the
 *     barrier occur before the LOAD and STORE operations issued after the barrier
 *
 */
static inline void memBarrier(void) {__sync_synchronize();}
void* Osal_qmssMemBarrier(uint32_t QID, void *descAddr)
{
    /* Issue memory barrier */
    memBarrier();
    return descAddr;
}
#else
/******************************************************************************
* Function to issue memory barrier
*
* NOTE: 
******************************************************************************/
void* Osal_qmssMemBarrier(uint32_t QID, void *descAddr)
{
    asm (" MFENCE " );
    return descAddr;
}
#endif



/**
 *  @b Description
 *  @n
 *      The function is used to allocate a memory block of the specified size.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @retval
 *      Allocated block address
 */
void *Osal_rmMalloc (uint32_t num_bytes)
{
    Error_Block    errorBlock;

    /* Increment the allocation counter. */
    rmMallocCounter++;

    /* Allocate memory. */
    return Memory_alloc(NULL, num_bytes, 0, &errorBlock);
}

/**
 *  @b Description
 *  @n
 *      The function is used to free a memory block of the specified size.
 *
 *  @param[in]  ptr
 *      Pointer to the memory block to be cleaned up.
 *
 *  @param[in]  size
 *      Size of the memory block to be cleaned up.
 *
 *  @retval
 *      Not Applicable
 */
void Osal_rmFree (void *ptr, uint32_t size)
{
    /* Increment the free counter. */
    rmFreeCounter++;
    Memory_free(NULL, ptr, size);
}

/* FUNCTION PURPOSE: Critical section enter
 ***********************************************************************
 * DESCRIPTION: The function is used to enter a critical section.
 *              Function protects against
 *
 *              access from multiple cores
 *              and
 *              access from multiple threads on single core
 */
void *Osal_rmCsEnter(void)
{

    return NULL;
}

/* FUNCTION PURPOSE: Critical section exit
 ***********************************************************************
 * DESCRIPTION: The function is used to exit a critical section
 *              protected using Osal_cppiCsEnter() API.
 */
void Osal_rmCsExit(void *CsHandle)
{

}

/* FUNCTION PURPOSE: Multi-threaded critical section enter
***********************************************************************
* DESCRIPTION: The function is used to enter a multi-threaded critical
*              section. Function protects against
 *
 *              access from multiple threads on single core
*/
void *Osal_rmMtCsEnter(void *mtSemObj)
{

    return NULL;
}

/* FUNCTION PURPOSE: Multi-threaded critical section exit
***********************************************************************
* DESCRIPTION: The function is used to exit a multi-threaded critical
*              section protected using Osal_rmMtCsEnter() API.
*/
void Osal_rmMtCsExit(void *mtSemObj, void *CsHandle)
{

}

/* FUNCTION PURPOSE: Critical section exit
 ***********************************************************************
 * DESCRIPTION: The function is used to indicate that a block of memory is
 *              about to be accessed. If the memory block is cached then this
 *              indicates that the application would need to ensure that the
 *              cache is updated with the data from the actual memory.
 */
void Osal_rmBeginMemAccess(void *ptr, uint32_t size)
{
#ifdef _TMS320C6X
    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

    /* Cleanup the prefetch buffer also. */
    CSL_XMC_invalidatePrefetchBuffer();

#ifdef L2_CACHE
    /* Invalidate L2 cache. This should invalidate L1D as well.
     * Wait until operation is complete. */
    CACHE_invL2 (ptr, size, CACHE_FENCE_WAIT);
#else
    /* Invalidate L1D cache and wait until operation is complete.
     * Use this approach if L2 cache is not enabled */
    CACHE_invL1d (ptr, size, CACHE_FENCE_WAIT);
#endif

    /* Reenable Interrupts. */
    Hwi_restore(key);
#endif
    return;
}

/* FUNCTION PURPOSE: Critical section exit
 ***********************************************************************
 * DESCRIPTION: The function is used to indicate that the block of memory has
 *              finished being accessed. If the memory block is cached then the
 *              application would need to ensure that the contents of the cache
 *              are updated immediately to the actual memory.
 */
void Osal_rmEndMemAccess(void *ptr, uint32_t size)
{
#ifdef _TMS320C6X
    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

#ifdef L2_CACHE
    /* Writeback L2 cache. This should Writeback L1D as well.
     * Wait until operation is complete. */
    CACHE_wbL2 (ptr, size, CACHE_FENCE_WAIT);

#else
    /* Writeback L1D cache and wait until operation is complete.
     * Use this approach if L2 cache is not enabled */
    CACHE_wbL1d (ptr, size, CACHE_FENCE_WAIT);
#endif

    /* Reenable Interrupts. */
    Hwi_restore(key);
#endif
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to create a task blocking object
 *      capable of blocking the task a RM instance is running
 *      within
 *
 *  @retval
 *      Allocated task blocking object
 */
void *Osal_rmTaskBlockCreate(void)
{
    Semaphore_Params semParams;

    Semaphore_Params_init(&semParams);
    return((void *)Semaphore_create(0, &semParams, NULL));
}

/**
 *  @b Description
 *  @n
 *      The function is used to block a task whose context a
 *      RM instance is running within.
 *
 *  @param[in]  handle
 *      Task blocking object handle.
 *
 *  @retval
 *      Not Applicable
 */
void Osal_rmTaskBlock(void *handle)
{
    Semaphore_pend((Semaphore_Handle)handle, BIOS_WAIT_FOREVER);
}

/**
 *  @b Description
 *  @n
 *      The function is used to unblock a task whose context a
 *      RM instance is running within.
 *
 *  @param[in]  handle
 *      Task blocking object handle.
 *
 *  @retval
 *      Not Applicable
 */
void Osal_rmTaskUnblock(void *handle)
{
    Semaphore_post((Semaphore_Handle)handle);
}

/**
 *  @b Description
 *  @n
 *      The function is used to delete a task blocking object
 *      provided to a RM instance
 *
 *  @param[in]  handle
 *      Task blocking object handle.
 *
 *  @retval
 *      Not Applicable
 */
void Osal_rmTaskBlockDelete(void *handle)
{
    Semaphore_delete((Semaphore_Handle *)&handle);
}

/**
 *  @b Description
 *  @n
 *      The function is the RM OSAL Logging API which logs
 *      the messages on the console.
 *
 *  @param[in]  fmt
 *      Formatted String.
 *
 *  @retval
 *      Not Applicable
 */
void Osal_rmLog (char *fmt, ... )
{
    VaList ap;

    va_start(ap, fmt);
    System_vprintf(fmt, ap);
    va_end(ap);
}

#ifdef SOC_K2G
/**
 *  @b Description
 *  @n
 *      The function is used to indicate that a block of memory is
 *      about to be accessed. If the memory block is cached then this
 *      indicates that the application would need to ensure that the
 *      cache is updated with the data from the actual memory.
 *
 *  @param[in]  addr
 *       Address of memory block
 *  @param[in]  size
 *       Size of memory block in bytes
 *
 *  @retval
 *      None
 */
void Osal_beginMemAccess
(
    void*   addr,
    Uint32  size
)
{
#ifdef _TMS320C6X
    uint32_t    key;
    Cppi_HostDesc * pHostDesc = (Cppi_HostDesc*) addr;

    /* Disable Interrupts */
    key = Hwi_disable();

    /* Cleanup the prefetch buffer also. */
    CSL_XMC_invalidatePrefetchBuffer();

    /* Invalidate cache based on where the memory is */
    if(((uint32_t)(addr) & CSL_DDR_0_DATA ) || ((uint32_t)(addr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        SYS_CACHE_INV_L2((void *) addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }
    if ((uint32_t)(addr) & CSL_MSMC_SRAM_REGS )
    {
            SYS_CACHE_INV_L1((void *)addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }

    if(((uint32_t)(pHostDesc->buffPtr) & CSL_DDR_0_DATA ) ||
        ((uint32_t)(pHostDesc->buffPtr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS))
    {
        SYS_CACHE_INV_L2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    if ((uint32_t)(pHostDesc->buffPtr) & CSL_MSMC_SRAM_REGS )
    {
        SYS_CACHE_INV_L1((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    
    return;
#else
    return;
#endif
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that the block of memory has
 *      finished being accessed. If the memory block is cached then the
 *      application would need to ensure that the contents of the cache
 *      are updated immediately to the actual memory.
 *
 *  @param[in]  addr
 *       Address of memory block
 *  @param[in]  size
 *       Size of memory block in bytes
 *
 *  @retval
 *      None
 */
void
Osal_endMemAccess
(
    void*   addr,
    Uint32  size
)
{
#ifdef _TMS320C6X
    uint32_t    key;
    Cppi_HostDesc * pHostDesc = (Cppi_HostDesc*) addr;
    /* Disable Interrupts */
    key = Hwi_disable();
    CSL_XMC_invalidatePrefetchBuffer();
    /* Cleanup the prefetch buffer also. */
    /* Invalidate cache based on where the memory is */
    if(((uint32_t)(addr) & CSL_DDR_0_DATA ) || ((uint32_t)(addr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        SYS_CACHE_WB_L2((void *) addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }
    
    if ((uint32_t)(addr) & CSL_MSMC_SRAM_REGS )
    {
        SYS_CACHE_WB_L1((void *)addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }

    if(((uint32_t)(pHostDesc->buffPtr) & CSL_DDR_0_DATA ) ||
      ((uint32_t)(pHostDesc->buffPtr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        SYS_CACHE_WB_L2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    if ((uint32_t)(pHostDesc->buffPtr) & CSL_MSMC_SRAM_REGS )
    {
        SYS_CACHE_WB_L1((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }


    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    return;
#else
    return;
#endif
}
#else
void Osal_beginMemAccess
(
    void*   addr,
    Uint32  size
)
{
    return;
}

void Osal_endMemAccess
(
    void*   addr,
    Uint32  size
)
{
    return;
}
#endif

