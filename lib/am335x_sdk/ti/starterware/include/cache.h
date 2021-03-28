/**
 *  \file   cache.h
 *
 *  \brief  This file contains the structure, macros and APIs declarations
 *          of cache. This file contains the APIs for configuring Cache.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/*
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

#ifndef CACHE_H_
#define CACHE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "misc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Instruction Cache */
#define CACHE_ICACHE        (1U)	
/** \brief Data/Unified Cache */
#define CACHE_DCACHE        (2U)
/** \brief Inst and data cache */
#define CACHE_IDCACHE       (3U)

/** \brief Inner cache */
#define CACHE_INNER         (1U)
/** \brief Outer cache */
#define CACHE_OUTER         (2U)
/** \brief Inner and Outer cache */
#define CACHE_INNER_OUTER   (3U)

/** \brief Memory barrier instruction. 
 *   Note: This macro need to be moved to arch specific file instead of cache.h 
 *         which is generic across architectures.
 */
#define DSB()               asm("   dsb")

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Structure defining the function table for outer cache driver 
 *         routines.
 */
typedef struct cacheOuterAttr
{
    uint32_t isOuterCacheEnabled;     
    /**< Flag to indicate if outer cache is present and enabled */
    
    void (*pFnOuterCacheEnable)(void);
    /**< Function pointer to enable outer cache */
    void (*pFnOuterCacheDisable)(void);
    /**< Function pointer to disable outer cache */
    
    void (*pFnOuterCacheInvRange)(uint32_t* pStartAddr, uint32_t numBytes);
    /**< Function pointer to invalidate part of cache */
    void (*pFnOuterCacheInvAll)(void);
    /**< Function pointer to invalidate complete cache */
    
    void (*pFnOuterCacheCleanRange)(uint32_t* pStartAddr, uint32_t numBytes);
    /**< Function pointer to clean part of cache */
    void (*pFnOuterCacheCleanAll)(void);
    /**< Function pointer to clean complete cache */

    void (*pFnOuterCacheCleanInvRange)(uint32_t* pStartAddr, uint32_t numBytes);
    /**< Function pointer to clean and invalidate part of cache */
    void (*pFnOuterCacheCleanInvAll)(void);
    /**< Function pointer to clean and invalidate complete cache */

    int32_t (*pFnOuterCacheLockByWay)(uint32_t lockWay, uint32_t* pStartAddr,
                                                         uint32_t numBytes);
    /**< Function pointer to lock cache */
    int32_t (*pFnOuterCacheUnlockByWay)(uint32_t unlockWay);
    /**< Function pointer to unlock cache */    

    void (*pFnOuterCacheSaveContext)(void);
    /**< Function pointer to save outer cache controller context */
    void (*pFnOuterCacheRestoreContext)(void);
    /**< Function pointer to restore outer cache controller context */
}cacheOuterAttr_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API enables outer-cache drivers to register themselves to the
 *          cache driver. So that when cache maintenance is performed the
 *          corresponding operation can be performed on the outer cache also.
 *
 * \param   pOuterCache   Pointer to outer cache object.
 *
 * \retval  None
 **/
void CACHERegisterOuterCache(cacheOuterAttr_t* pOuterCache);


/**
 * \brief   This API enables cache in the system. Based on the parameter passed,
 *          the corresponding cache type will be enabled. The caches level to be
 *          enabled is indicated by the user. Inner cache alone or both can be
 *          enabled, enabling Outer cache alone is not supported.
 *
 * \param   cacheType   Indicates the type of cache to be enabled. These
 *                      parameters are applicable only if the cache is Harvard
 *                      type.
 *              Possible values are,
 *                #CACHE_ICACHE
 *                #CACHE_DCACHE
 *                #CACHE_IDCACHE
 *
 * \param   cacheLevel  Indicates the levels to be enabled. Possible values are,
 *                #CACHE_INNER
 *                #CACHE_INNER_OUTER
 *
 * \retval  result      Result of enable operation. Error id in-case of any error.
 **/
void CACHEEnable(uint32_t cacheType, uint32_t cacheLevel);


/**
 * \brief   This API disables cache in the system. Based on the parameter passed,
 *          the corresponding cache type will be disabled. The level/s to be
 *          disabled is passed as parameter. Disabling inner cache alone,
 *          leaving outer cache enabled is not supported. However outer-cache
 *          alone can be disabled.
 *
 * Note:    The below implementation needs rework if exclusive cache
 *          configuration is enabled. This implementation assumes that the prior
 *          cache levels are still enabled.
 *
 * \param   cacheType   Indicates the type of cache to be disabled. These
 *                      parameters are applicable only if the cache is Harvard
 *                      type.
 *              Possible values are,
 *                #CACHE_ICACHE
 *                #CACHE_DCACHE
 *                #CACHE_IDCACHE
 *
 * \param   cacheLevel  Indicates the levels to be disabled. Possible values are,
 *                #CACHE_OUTER
 *                #CACHE_INNER_OUTER
 *
 * \retval  result      Result of enable operation. Error id in-case of any error.
 **/
void CACHEDisable(uint32_t cacheType, uint32_t cacheLevel);


/**
 * \brief   This API cleans the complete data cache. Cleaning here means writing
 *          back updated data to main memory. However the cache entries will not
 *          be invalidated by this API.
 **/
void CACHEDataCleanAll(void);


/**
 * \brief   This API cleans the given memory range from data cache. Cleaning here
 *          means writing back updated data to main memory. However the cache
 *          entries will not be invalidated by this API.
 *
 * \param   pStartAddr   Starting address of the memory range to be cleaned from
 *                      cache
 * \param   numBytes    Number of byte to be cleaned
 **/
void CACHEDataCleanRange(uint32_t* pStartAddr, uint32_t numBytes);

/**
 * \brief   This API invalidates all the contents in instruction cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 **/
void CACHEInstInvAll(void);


/**
 * \brief   This API invalidates all the contents in data cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 **/
void CACHEDataInvAll(void);


/**
 * \brief   This API invalidates range of memory from the corresponding cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 *
 * \param   pStartAddr   Starting address of the memory range to be invalidated
 *                      from cache
 * \param   numBytes    Number of bytes to be invalidated
 **/
void CACHEDataInvRange(uint32_t* pStartAddr, uint32_t numBytes);


/**
 * \brief   This API cleans and invalidates complete cache. Cleaning here means
 *          writing back updated data to main memory. Invalidating here means
 *          marking the cache entries as invalid which can be overwritten with
 *          new entries.
 **/
void CACHEDataCleanInvAll(void);


/**
 * \brief   This API cleans and invalidates range of memory from the data
 *          cache. Cleaning here means writing back updated data to main memory.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 *
 * \param   pStartAddr   Starting address of the memory range to be cleaned and
 *                      invalidated from the cache
 * \param   numBytes    Number of bytes to be invalidated
 **/
void CACHEDataCleanInvRange(uint32_t* pStartAddr, uint32_t numBytes);


 /**
 * \brief   This API locks the cache by Way. Before locking the cache, this
 *          function loads the contents indicated by the start address and
 *          number of bytes into the cache.
 *
 * \param   lockWay     Indicates the way to be locked from eviction
 * \param   pStartAddr   Start address from where the content should be loaded
 *                      in to cache before cache is locked.
 * \param   numBytes    Number of bytes from the start address to be locked
 *
 * \retval  result      Result of lock operation or error id incase of any error.
 **/
int32_t CACHELockByWay(uint32_t lockWay, uint32_t* pStartAddr, uint32_t numBytes);


/**
 * \brief   This API unlocks the cache by Way.
 *
 * \param   unlockWay  Indicates the way to be unlocked, so that it can be evicted.
 *
 * \retval  result      Result of unlock operation or error id incase of any error.
 **/
int32_t CACHEUnlockByWay(uint32_t unlockWay);

/* ========================================================================== */
/*                    Function Declarations (deprecated)                      */
/* ========================================================================== */

/**
 * \brief   This API invalidates all the contents in instruction cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries. This API is deprecated equivalent
 *          of #CACHEInstInvAll.
 **/
DEPRECATED(void CacheInstInvalidateAll(void));

/**
 * \brief   This API cleans and invalidates complete cache. Cleaning here means
 *          writing back updated data to main memory. Invalidating here means
 *          marking the cache entries as invalid which can be overwritten with
 *          new entries. This API is deprecated equivalent of 
 *          #CACHEDataCleanInvAll.
 **/
DEPRECATED(void CacheDataCleanInvalidateAll(void));

/**
 * \brief   This API cleans the complete data cache. Cleaning here means writing
 *          back updated data to main memory. However the cache entries will not
 *          be invalidated by this API. This API is deprecated equivalent of
 *          #CACHEDataCleanAll.
 **/
DEPRECATED(void CacheDataCleanAll(void));

/**
 * \brief   This API invalidates all the contents in data cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries. This API is deprecated
 *          equivalent of #CACHEDataInvAll.
 **/
DEPRECATED(void CacheDataInvalidateAll(void));

/**
 * \brief   This API cleans the given memory range from data cache. Cleaning here
 *          means writing back updated data to main memory. However the cache
 *          entries will not be invalidated by this API. This API is deprecated
 *          equivalent of #CACHEDataCleanRange.
 **/
DEPRECATED(void CacheDataCleanBuff(uint32_t pStartAddr, uint32_t numBytes));

/**
 * \brief   This API invalidates range of memory from the corresponding cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries. This API is deprecated
 *          equivalent of #CACHEDataInvRange.
 **/
DEPRECATED(void CacheDataInvalidateBuff(uint32_t pStartAddr, uint32_t numBytes));

/**
 * \brief   This API cleans and invalidates range of memory from the data
 *          cache. Cleaning here means writing back updated data to main memory.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries. This API is deprecated
 *          equivalent of #CACHEDataCleanInvRange.
 **/
DEPRECATED(void CacheDataCleanInvalidateBuff(uint32_t pStartAddr, uint32_t numBytes));


#ifdef __cplusplus
}
#endif
#endif /* ifndef CACHE_H_ */
