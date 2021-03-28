/*
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
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
 */

/**
 *   @file  test_osal.c
 *
 *   @brief
 *      This is the OS abstraction layer and is used by the EMAC
 *      driver for the EMAC Unit Test Application.
 */

/* Standard C-native includes  */
#include <stdlib.h>
#include <string.h>

 
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <xdc/cfg/global.h>

/* CSL CHIP, SEM Functional layer includes */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_semAux.h>


/* CSL Cache module includes */
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>


#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

#include <ti/drv/emac/emac_hwcfg.h>
#include <ti/drv/emac/emac_drv.h>
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"

/* Hardware Semaphore to synchronize access from
 * multiple applications (PA applications and non-PASS applications)
 * across different cores to the QMSS library.
 */
#define     QMSS_HW_SEM         3 

/* Hardware Semaphore to synchronize access from
 * multiple applications (PASS applications and non-PASS applications)
 * across different cores to the CPPI library.
 */
#define     CPPI_HW_SEM         4 

/* Hardware Semaphore to synchronize access from
 * multiple applications (PASS applications and non-PASS applications)
 * across different cores to the EMAC library.
 */
#define     EMAC_HW_SEM         5 

#undef L2_CACHE
#ifdef L2_CACHE
    /* Invalidate L2 cache. This should invalidate L1D as well. 
     * Wait until operation is complete. */    
#define SYS_CACHE_INV(addr, size, code)    CACHE_invL2 (addr, size, code)

    /* Writeback L2 cache. This should Writeback L1D as well. 
     * Wait until operation is complete. */ 
#define SYS_CACHE_WB(addr, size, code)     CACHE_wbL2 (addr, size, code)

#else       
    /* Invalidate L1D cache and wait until operation is complete. 
     * Use this approach if L2 cache is not enabled */    
#define SYS_CACHE_INV(addr, size, code)    CACHE_invL1d (addr, size, code)
    /* Writeback L1D cache and wait until operation is complete. 
     * Use this approach if L2 cache is not enabled */    
#define SYS_CACHE_WB(addr, size, code)     CACHE_wbL1d (addr, size, code)

#endif


#define MAX_NUM_CORES 1
/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
UInt32      cpswCppiMallocCounter   =   0;
UInt32      cpswCppiFreeCounter     =   0;
UInt32      cpswQmssMallocCounter   =   0;
UInt32      cpswQmssFreeCounter     =   0;
uint32_t    rmMallocCounter         =   0;
uint32_t    rmFreeCounter           =   0;
UInt32      coreKey [MAX_NUM_CORES];



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
Ptr Osal_cppiCsEnter (Void)
{
    /* Get the hardware semaphore. 
     *
     * Acquire Multi core CPPI synchronization lock 
     */
    while ((CSL_semAcquireDirect (CPPI_HW_SEM)) == 0);

    /* Disable all interrupts and OS scheduler. 
     *
     * Acquire Multi threaded / process synchronization lock.
     */
    coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)] = Hwi_disable();

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
Void Osal_cppiCsExit (Ptr CsHandle)
{
    /* Enable all interrupts and enables the OS scheduler back on.
     *
     * Release multi-threaded / multi-process lock on this core.
     */
    Hwi_restore(coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)]);

    /* Release the hardware semaphore 
     *
     * Release multi-core lock.
     */ 
    CSL_semReleaseSemaphore (CPPI_HW_SEM);

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
Ptr Osal_cppiMalloc (UInt32 num_bytes)
{
	Error_Block	    errorBlock;

    /* Increment the allocation counter. */
    cpswCppiMallocCounter++;	

	/* Allocate memory.  */
	return Memory_alloc(NULL, num_bytes, 0, &errorBlock);
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
Void Osal_cppiFree (Ptr dataPtr, UInt32 num_bytes)
{
    /* Increment the free counter. */
    cpswCppiFreeCounter++;	

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

    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

    /* Cleanup the prefetch buffer also. */
    CSL_XMC_invalidatePrefetchBuffer();
    
    SYS_CACHE_INV (blockPtr, size, CACHE_FENCE_WAIT);
    
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    
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
    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

    SYS_CACHE_WB (blockPtr, size, CACHE_FENCE_WAIT);

    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
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
Ptr Osal_qmssCsEnter (Void)
{
    /* Get the hardware semaphore. 
     *
     * Acquire Multi core QMSS synchronization lock 
     */
    while ((CSL_semAcquireDirect (QMSS_HW_SEM)) == 0);

    /* Disable all interrupts and OS scheduler. 
     *
     * Acquire Multi threaded / process synchronization lock.
     */
    coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)] = Hwi_disable();

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
Void Osal_qmssCsExit (Ptr CsHandle)
{
    /* Enable all interrupts and enables the OS scheduler back on.
     *
     * Release multi-threaded / multi-process lock on this core.
     */
    Hwi_restore(coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)]);

    /* Release the hardware semaphore 
     *
     * Release multi-core lock.
     */ 
    CSL_semReleaseSemaphore (QMSS_HW_SEM);

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
Ptr Osal_qmssMtCsEnter (Void)
{
    /* Disable all interrupts and OS scheduler. 
     *
     * Acquire Multi threaded / process synchronization lock.
     */
    //coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)] = Hwi_disable();

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
Void Osal_qmssMtCsExit (Ptr CsHandle)
{
    /* Enable all interrupts and enables the OS scheduler back on.
     *
     * Release multi-threaded / multi-process lock on this core.
     */
    //Hwi_restore(key);

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
Ptr Osal_qmssMalloc (UInt32 num_bytes)
{
	Error_Block	    errorBlock;

    /* Increment the allocation counter. */
    cpswQmssMallocCounter++;	

	/* Allocate memory.  */
	return Memory_alloc(NULL, num_bytes, 0, &errorBlock);
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
Void Osal_qmssFree (Ptr dataPtr, UInt32 num_bytes)
{
    /* Increment the free counter. */
    cpswQmssFreeCounter++;	

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
    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

    /* Cleanup the prefetch buffer also. */
    CSL_XMC_invalidatePrefetchBuffer();
    
    SYS_CACHE_INV (blockPtr, size, CACHE_FENCE_WAIT);
    
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    
    return;
}

/******************************************************************************
* Function to issue memory barrier
*
* NOTE: QMSS unit tests are not using CPPI descriptors
******************************************************************************/
void* Osal_qmssMemBarrier(uint32_t QID, void *descAddr)
{
    return descAddr;
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
    uint32_t    key;

    /* Disable Interrupts */
    key = Hwi_disable();

    SYS_CACHE_WB (blockPtr, size, CACHE_FENCE_WAIT);

    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    return;
}



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
    uint32_t    key;
    Cppi_HostDesc * pHostDesc = (Cppi_HostDesc*) addr;

    /* Disable Interrupts */
    key = Hwi_disable();

    /* Cleanup the prefetch buffer also. */
    CSL_XMC_invalidatePrefetchBuffer();

    /* Invalidate cache based on where the memory is */
    if(((uint32_t)(addr) & CSL_DDR_0_DATA ) || ((uint32_t)(addr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        CACHE_invL2((void *) addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }
    if ((uint32_t)(addr) & CSL_MSMC_SRAM_REGS )
    {
            CACHE_invL1d((void *)addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }

    if(((uint32_t)(pHostDesc->buffPtr) & CSL_DDR_0_DATA ) ||
        ((uint32_t)(pHostDesc->buffPtr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS))
    {
        CACHE_invL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    if ((uint32_t)(pHostDesc->buffPtr) & CSL_MSMC_SRAM_REGS )
    {
        CACHE_invL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    
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
    uint32_t    key;
    Cppi_HostDesc * pHostDesc = (Cppi_HostDesc*) addr;
    /* Disable Interrupts */
    key = Hwi_disable();
    CSL_XMC_invalidatePrefetchBuffer();
    /* Cleanup the prefetch buffer also. */
    /* Invalidate cache based on where the memory is */
    if(((uint32_t)(addr) & CSL_DDR_0_DATA ) || ((uint32_t)(addr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        CACHE_wbL2((void *) addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }
    
    if ((uint32_t)(addr) & CSL_MSMC_SRAM_REGS )
    {
        CACHE_wbL1d((void *)addr, sizeof(Cppi_HostDesc), CACHE_WAIT);
    }

    if(((uint32_t)(pHostDesc->buffPtr) & CSL_DDR_0_DATA ) ||
      ((uint32_t)(pHostDesc->buffPtr) & CSL_C66X_COREPAC_0_L2_SRAM_REGS ))
    {
        CACHE_wbL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }

    if ((uint32_t)(pHostDesc->buffPtr) & CSL_MSMC_SRAM_REGS )
    {
        CACHE_wbL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    }


    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    asm   (" nop      4");
    
    /* Reenable Interrupts. */
    Hwi_restore(key);
    return;
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

    /* Get the hardware semaphore. 
     *
     * Acquire Multi core EMAC synchronization lock 
     */
    while ((CSL_semAcquireDirect (EMAC_HW_SEM)) == 0);

    /* Disable all interrupts and OS scheduler. 
     *
     * Acquire Multi threaded / process synchronization lock.
     */
    coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)] = Hwi_disable();

    return NULL;



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
   /* Enable all interrupts and enables the OS scheduler back on.
     *
     * Release multi-threaded / multi-process lock on this core.
     */
    Hwi_restore(coreKey [CSL_chipReadReg (CSL_CHIP_DNUM)]);

    /* Release the hardware semaphore 
     *
     * Release multi-core lock.
     */ 
    CSL_semReleaseSemaphore (EMAC_HW_SEM);

    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to provide critical section to prevent access of shared
 *      resources from multiple cores
 *
 *  @retval
 *      None
 */
void
Osal_enterMultipleCoreCriticalSection
(
    Uint32      port_num
)
{
    (void)port_num;
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is called to end the critical section access of shared resources
 *      from multiple cores.
 *
 *  @param[in]
 *
 *  @retval
 *      None
 */
void
Osal_exitMultipleCoreCriticalSection
(
    Uint32      port_num
)
{
    (void)port_num;
    return;
}

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
void* Osal_malloc
(
    Uint32  num_bytes
)
{
    Error_Block     errorBlock;
    Void*           ptr;

    /* Allocate memory */
    ptr = Memory_alloc(NULL, num_bytes, 4, &errorBlock);
    if (ptr == NULL)
    {
        return NULL;
    }

    /* Return the allocated memory block. */
    return ptr;
}

/**
 *  @b Description
 *  @n
 *      The function is used to clean up a specific memory block
 *
 *  @param[in]  ptr
 *      Pointer to the memory block to be cleaned up.
 *  @param[in]  num_bytes
 *      Size of the memory block being cleaned up.
 *
 *  @retval
 *      Not Applicable
 */
void
Osal_free
(
    void*       ptr,
    Uint32      num_bytes
)
{
    Memory_free(NULL, ptr, num_bytes);
}
