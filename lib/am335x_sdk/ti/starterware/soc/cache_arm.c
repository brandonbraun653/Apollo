/**
 *  \file   cache_arm.c
 *
 *  \brief  This file contains the APIs implementation for configuring ARM 
 *          Cache.
 *
 *          Some of the operations on cache like clean/invalidate etc... are
 *          performed at all cache levels together. The term flush is not used
 *          by ARM for naming cache operations, clean and invalidate are used.
 *          Accordingly the API's and comments in this file follow the same
 *          convention.
 *
 *          ARM also provides support for extending the cache levels outside 
 *          the core, so that additional cache levels can be implemented. These 
 *          API's consider that there is only one level of external cache and 
 *          it is unified cache. For other configurations these API's may not
 *          be compatible and need to be changed as required.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "cache.h"
#include "cp15.h"
#include "error.h"
#include "cpu.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#ifdef OUTER_CACHE_ENABLE
    cacheOuterAttr_t* pOuterCache = 0;
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void CACHERegisterOuterCache(cacheOuterAttr_t* pOuterCacheFn)
{
#ifdef OUTER_CACHE_ENABLE
    pOuterCache = pOuterCacheFn;
#endif
}

void CACHEEnable(uint32_t cacheType, uint32_t cacheLevel)
{
    /* Enable L1 ICache. The ICache invalidation is also done inside
       CP15ICacheEnable() */
    if(cacheType & CACHE_ICACHE)
    {
        CP15ICacheEnable();
    }

    /* Enable DCache at all levels. The DCache invalidation is done inside
       CP15DCacheEnable(). This API also enables d-cache at all levels 
       including the unified cache (inner). */
    if(cacheType & CACHE_DCACHE)
    {
        CP15DCacheEnable();

	if(CP15_PRIMARY_PART_CORTEX_A8 == CP15MainIdPrimPartNumGet())
	{
            /* For Cortex A8, L2 cache (unified) is integrated within the 
               ARM core which also need to be enabled. */
            CP15AuxControlFeatureEnable(CP15_CORTEX_A8_L2EN);
        }
    }

#ifdef OUTER_CACHE_ENABLE
    /* For cortex A5 & A9, the presence of L2 (outer) cache is implementation
       defined. If L2 cache is implemented, it will be outside ARM core.
       And the L2 cache should be initialized before calling this API.
       Otherwise L2 cache will not be configured. The clean and invalidate
       operations will be handled within the enable API itself. */
    if((CACHE_INNER_OUTER & cacheLevel ) && (NULL != pOuterCache) &&
                                      (NULL != pOuterCache->pFnOuterCacheEnable))
        pOuterCache->pFnOuterCacheEnable();
#endif
}

void CACHEDisable(uint32_t cacheType, uint32_t cacheLevel)
{

#ifdef OUTER_CACHE_ENABLE
    /* For cortex A5 & A9, the presence of L2 (outer) cache is implementation
       defined. If L2 cache is implemented, it will be outside ARM core.
       And the L2 cache should be initialized before calling this API.
       Otherwise L2 cache will not be configured. The clean and invalidate
       operations will be handled within the disable API itself. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheDisable))
        pOuterCache->pFnOuterCacheDisable();
#endif

    /* Disable L1 ICache. The ICache invalidation is also done inside
       CP15ICacheDisable() */
    if(CACHE_INNER_OUTER & cacheLevel)
    {
        if(cacheType & CACHE_ICACHE)
        {
            CP15ICacheDisable();
        }

        /* Disable DCache at all levels. The DCache clean and invalidation is 
           also done inside CP15DCacheDisable(). This API also disables d-cache
           at all levels including the unified cache (inner). */
        if(cacheType & CACHE_DCACHE)
        {
            CP15DCacheDisable();

            if(CP15_PRIMARY_PART_CORTEX_A8 == CP15MainIdPrimPartNumGet())
            {
                /* For Cortex A8, L2 cache (unified) is integrated within the
                   ARM core which also need to be disabled. */
                CP15AuxControlFeatureDisable(CP15_CORTEX_A8_L2EN);
            }
        }
    }
}

void CACHEDataCleanAll(void)
{
    /* Clean complete d-cache at all levels till Point Of Unification.  */
    CP15DCacheClean();

#ifdef OUTER_CACHE_ENABLE
    /* Clean outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheCleanAll))
        pOuterCache->pFnOuterCacheCleanAll();
#endif
}

void CACHEDataCleanRange(uint32_t* pStartAddr, uint32_t numBytes)
{
    /* Clean d-cache at all levels till the Point Of Unification. */
    CP15DCacheCleanBuff((uint32_t)pStartAddr, numBytes);

#ifdef OUTER_CACHE_ENABLE
    /* Clean outer cache */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheCleanRange))
        pOuterCache->pFnOuterCacheCleanRange(pStartAddr, numBytes);
#endif
}

void CACHEInstInvAll(void)
{
    /* Invalidate all levels till the PoU. */
    CP15ICacheFlush();

#ifdef OUTER_CACHE_ENABLE
    /* Invalidate Outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheInvAll))
        pOuterCache->pFnOuterCacheInvAll();
#endif
}

void CACHEDataInvAll(void)
{
    /* Invalidate all levels till the PoU. */
    CP15DCacheFlush();

#ifdef OUTER_CACHE_ENABLE
    /* Invalidate Outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheInvAll))
        pOuterCache->pFnOuterCacheInvAll();
#endif
}

void CACHEDataInvRange(uint32_t* pStartAddr, uint32_t numBytes)
{
#ifdef OUTER_CACHE_ENABLE
    /* Invalidate Outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheInvRange))
        pOuterCache->pFnOuterCacheInvRange(pStartAddr, numBytes);
#endif

    /* Invalidate all levels till the PoU. */
    CP15DCacheFlushBuff((uint32_t)pStartAddr, numBytes);
}

void CACHEDataCleanInvAll(void)
{
    /* Clean and invalidate d-cache. */
    CP15DCacheCleanFlush();

#ifdef OUTER_CACHE_ENABLE
    /* Clean and Invalidate Outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheCleanInvAll))
        pOuterCache->pFnOuterCacheCleanInvAll();
#endif
}

void CACHEDataCleanInvRange(uint32_t* pStartAddr, uint32_t numBytes)
{
    /* Clean and invalidate d-cache. */
    CP15DCacheCleanFlushBuff((uint32_t)pStartAddr, numBytes);

#ifdef OUTER_CACHE_ENABLE
    /* Clean and Invalidate Outer cache. */
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheCleanInvRange))
        pOuterCache->pFnOuterCacheCleanInvRange(pStartAddr, numBytes);
#endif
}

int32_t CACHELockByWay(uint32_t lockWay, uint32_t* pStartAddr, 
                                                       uint32_t numBytes)
{
    uint32_t intStatus = 0;
    uint32_t status = E_FAIL;

    /* Disable interrupts (alternatively if the interrupts cant be disabled,
       make sure the contents are non-cache-able or already locked. */
    intStatus = CPUIntrDisable();

    /* Make sure to flush clean and invalidate the buffer from internal cache*/
    CACHEDataCleanRange(pStartAddr, numBytes);
    CACHEDataInvRange(pStartAddr, numBytes);

#ifdef OUTER_CACHE_ENABLE
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheLockByWay))
        status = pOuterCache->pFnOuterCacheLockByWay(lockWay, pStartAddr, 
                                                               numBytes);
#endif

    CPUIntrEnable(intStatus);
    return status;
}

int32_t CACHEUnlockByWay(uint32_t unlockWay)
{
    uint32_t status = E_FAIL;
#ifdef OUTER_CACHE_ENABLE
    if((NULL != pOuterCache) && (NULL != pOuterCache->pFnOuterCacheUnlockByWay))
        status = pOuterCache->pFnOuterCacheUnlockByWay(unlockWay);
#endif
    return status;
}

/* ========================================================================== */
/*                      Deprecated Function Definitions                       */
/* ========================================================================== */

void CacheInstInvalidateAll(void)
{
    CACHEInstInvAll();
}

void CacheDataCleanInvalidateAll(void)
{
    CACHEDataCleanInvAll();
}

void CacheDataCleanAll(void)
{
    CACHEDataCleanAll();
}

void CacheDataInvalidateAll(void)
{
    CACHEDataInvAll();
}

void CacheDataCleanBuff(uint32_t startAddr, uint32_t numBytes)
{
    CACHEDataCleanRange((uint32_t*)startAddr, numBytes);
}

void CacheDataInvalidateBuff(uint32_t startAddr, uint32_t numBytes)
{
    CACHEDataInvRange((uint32_t*)startAddr, numBytes);
}

void CacheDataCleanInvalidateBuff(uint32_t startAddr, uint32_t numBytes)
{
    CACHEDataCleanInvRange((uint32_t*)startAddr, numBytes);
}
