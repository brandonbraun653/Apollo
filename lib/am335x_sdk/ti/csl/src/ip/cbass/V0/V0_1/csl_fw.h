/**
 * @file csl_fw.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the fw
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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
#ifndef CSL_FW_H_
#define CSL_FW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_cbass.h>

/** \addtogroup CSL_FW
 *  @{
 */

/**
 *  \anchor CSL_FwExceptionLogging_t
 *  \name Fw Exception Logging
 *  @{
 */
/**
 * \brief  FW CSL_FwExceptionLogging_t: Field value definitions for feature: ExceptionLogging
 */
typedef uint32_t CSL_FwExceptionLogging_t;

#define CSL_FW_EXCEPTIONLOGGING_DISABLE			(1U)
/**< Disable */
#define CSL_FW_EXCEPTIONLOGGING_ENABLE			(0U)
/**< Enable */
/* @} */

/**
 *  \anchor CSL_FwExceptionLogPending_t
 *  \name Fw Exception Log Logging
 *  @{
 */
/**
 * \brief FW CSL_FwExceptionLogPending_t: Field value definitions for feature: ExceptionLogPending
 */
typedef uint32_t CSL_FwExceptionLogPending_t;
#define CSL_FW_EXCEPTIONLOGPENDING_DISABLE		(1U)
/**< Disable */
#define CSL_FW_EXCEPTIONLOGPENDING_ENABLE		(0U)
/**< Enable */
/* @} */


/** \brief FW CSL_FwExceptionData_t: Structure definition for feature: ExceptionData */
typedef struct {
    uint32_t             destId; /**< Destination Id. */
    uint32_t             srcId; /**< Source Id. */
    uint32_t             typeF; /**< Type. */
    uint32_t             code; /**< Code. */
    uint32_t             group; /**< Group. */
    uint32_t             privId; /**< Priv Id. */
    bool                 secure; /**< Secure. */
    bool                 priv; /**< Priv. */
    bool                 cacheable; /**< Cacheable. */
    bool                 debug; /**< Debug. */
    bool                 read; /**< Read. */
    bool                 write; /**< Write. */
    uint32_t             routeid; /**< Route Id. */
    uint32_t             bytecnt; /**< Byte Count. */
    uint64_t             addr; /**< Combination Of Addr_L Addr_H Fields */
} CSL_FwExceptionData_t;

/**
 *  \anchor CSL_FwException_t
 *  \name Fw Exception
 *  @{
 */
/**
 * \brief FW CSL_FwException_t: Field value definitions for feature: Exception
 */
typedef uint32_t CSL_FwException_t;
#define CSL_FW_EXCEPTION_SET			(1U)
/**< Set */
#define CSL_FW_EXCEPTION_CLEAR			(1U)
/**< Clear */
#define CSL_FW_EXCEPTION_CLEARED		(0U)
/**< Cleared */
/* @} */

/**
 *  \anchor CSL_FwRegion_t
 *  \name Fw Region
 *  @{
 */
/**
 * \brief FW CSL_FwRegion_t: Field value definitions for feature: Region
 */
typedef uint32_t CSL_FwRegion_t;
#define CSL_FW_REGION_ENABLE 			(10U)
/**< Enable */
#define CSL_FW_REGION_DISABLE			(0U)
/**< Disable */
/* @} */

/**
 *  \anchor CSL_FwRegionLock_t
 *  \name Fw Region Lock
 *  @{
 */
/**
 * \brief FW CSL_FwRegionLock_t: Field value definitions for feature: RegionLock
 */
typedef uint32_t CSL_FwRegionLock_t;
#define CSL_FW_REGIONLOCK_ENABLE 		(1U)
/**< Enable */
#define CSL_FW_REGIONLOCK_DISABLE		(0U)
/**< Disable */
/* @} */

/**
 *  \anchor CSL_FwBackgroundRegion_t
 *  \name Fw Background Region
 *  @{
 */
/**
 * \brief FW CSL_FwBackgroundRegion_t: Field value definitions for feature: BackgroundRegion
 */
typedef uint32_t CSL_FwBackgroundRegion_t;
#define CSL_FW_BACKGROUNDREGION_SET	 	(1U)
/**< Set */
#define CSL_FW_BACKGROUNDREGION_CLEAR	(0U)
/**< Clear */
/* @} */

/**
 *  \anchor CSL_FwCacheableTrans_t
 *  \name Fw Cacheable Trans
 *  @{
 */
/**
 * \brief FW CSL_FwCacheableTrans_t: Field value definitions for feature: CacheableTrans
 */
typedef uint32_t CSL_FwCacheableTrans_t;
#define CSL_FW_CACHEABLETRANS_IGNORE	(1U)
/**< Ignore */
#define CSL_FW_CACHEABLETRANS_CHECK 	(0U)
/**< Check */
/* @} */

/** \brief FW CSL_FwRegionPermissions_t: Structure definition for feature: RegionPermissions */
typedef struct {
    bool                 secSupvWrite; /**< Secure Supervisor Write Allowed. */
    bool                 secSupvRead; /**< Secure Supervisor Read Allowed. */
    bool                 secSupvCacheable; /**< Secure Supervisor Cacheable Allowed. */
    bool                 secSupvDebug; /**< Secure Supervisor Debug Allowed. */
    bool                 secUserWrite; /**< Secure User Write Allowed. */
    bool                 secUserRead; /**< Secure User Read Allowed. */
    bool                 secUserCacheable; /**< Secure User Cacheable Allowed. */
    bool                 secUserDebug; /**< Secure User Debug Allowed. */
    bool                 nonsecSupvWrite; /**< Non-Secure Supervisor Write Allowed. */
    bool                 nonsecSupvRead; /**< Non-Secure Supervisor Read Allowed. */
    bool                 nonsecSupvCacheable; /**< Non-Secure Supervisor Cacheable Allowed. */
    bool                 nonsecSupvDebug; /**< Non-Secure Supervisor Debug Allowed. */
    bool                 nonsecUserWrite; /**< Non-Secure User Write Allowed. */
    bool                 nonsecUserRead; /**< Non-Secure User Read Allowed. */
    bool                 nonsecUserCacheable; /**< Non-Secure User Cacheable Allowed. */
    bool                 nonsecUserDebug; /**< Non-Secure User Debug Allowed. */
    uint32_t             privId; /**< Allowed Privid. */
} CSL_FwRegionPermissions_t;

/** \brief FW CSL_FwRegionAddrRange_t: Structure definition for feature: RegionAddrRange */
typedef struct {
    uint64_t             startAddr; /**< Combination Of Addr_L Addr_Lsb Addr_H Fields */
    uint64_t             endAddr; /**< Combination Of End_Addr_L End_Addr_Lsb End_Addr_H Fields */
} CSL_FwRegionAddrRange_t;


/* Array Size Definition Macros */
#define CSL_FW_NUM_CBASS_ISC_EP                             8u
#define CSL_FW_NUM_CBASS_QOS_EP                             8u
#define CSL_FW_NUM_CBASS_ISC_EP_REGION                      32u
#define CSL_FW_NUM_CBASS_QOS_EP_MAP                         192u
#define CSL_FW_NUM_CBASS_QOS_EP_GRP                         32u
#define CSL_FW_NUM_CBASS_FWCHV_EP0_VIRT_OWNER               32u
#define CSL_FW_NUM_CBASS_FW_EP                              8192u
#define CSL_FW_NUM_CBASS_FWCHV_EP0                          64u
#define CSL_FW_NUM_CBASS_FW_EP_REGION                       32u
#define CSL_FW_NUM_CBASS_FW_EP_REGION_PERMISSION            3u

/* Functions to access the feature: Revision*/

/**
 * \brief FW Read Revision
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
 * \return value of pid register
 */
extern uint32_t CSL_fwGetRevision(const CSL_cbass_glbRegs *pCbass_GlbRegs);

/**
 *  \brief FW Query value of ExceptionLogging
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the disable_f field inside the exception_logging_control register matches the value: Disable
 */
extern bool CSL_fwIsExceptionLoggingDisable(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Query value of ExceptionLogging
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the disable_f field inside the exception_logging_control register matches the value: Enable
 */
extern bool CSL_fwIsExceptionLoggingEnable(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Set the value of ExceptionLogging
 *
 * This function set the value of the disable_f field of the exception_logging_control register to the argument value
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureExceptionLogging(CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionLogging_t);
/**
 *  \brief FW Query value of ExceptionLogPending
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the disable_pend field inside the exception_logging_control register matches the value: Disable
 */
extern bool CSL_fwIsExceptionLogPendingDisable(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Query value of ExceptionLogPending
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the disable_pend field inside the exception_logging_control register matches the value: Enable
 */
extern bool CSL_fwIsExceptionLogPendingEnable(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Set the value of ExceptionLogPending
 *
 * This function set the value of the disable_pend field of the exception_logging_control register to the argument value
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureExceptionLogPending(CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionLogPending_t);

/* Functions to access the feature: ExceptionData*/

/**
 *  \brief FW Read the attributes of ExceptionData
 *
 * This function reads the attributes of the ExceptionData feature and fills out the user-supplied structure pCSL_FwExceptionData_t
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 * \param pCSL_FwExceptionData_t [OUT] Pointer to user-supplied structure to be populated from register overlay.
 *
\return int32_t. CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwGetExceptionData(const CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionData_t *pCSL_FwExceptionData_t);
/* Functions to access the feature: Exception*/

/**
 *  \brief FW Query value of Exception
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the pend_set field inside the exception_pend_set register matches the value: Set
 */
extern bool CSL_fwIsExceptionSet(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Query value of Exception
 *
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the pend_clr field inside the exception_pend_clear register matches the value: Cleared
 */
extern bool CSL_fwIsExceptionCleared(const CSL_cbass_glbRegs *pCbass_GlbRegs);
/**
 *  \brief FW Set the Exception
 *
 * This function set the value of the pend_set field of the exception_pend_set register to the value: Set
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwSetException(CSL_cbass_glbRegs *pCbass_GlbRegs);

/**
 *  \brief FW Clear the Exception
 *
 * This function set the value of the pend_clr field of the exception_pend_clear register to the value: Clear
 *
 * \param pCbass_GlbRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwClearException(CSL_cbass_glbRegs *pCbass_GlbRegs);

/* Functions to access the feature: Region*/

/**
 *  \brief FW Query value of Region
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionEpIndex [IN] ep index
 * \param regionRegionIndex [IN] region index
 *
\return true if value of the enable field inside the control register matches the value: Enable
 */
extern bool CSL_fwIsRegionEnable(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex);
/**
 *  \brief FW Query value of Region
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionEpIndex [IN] ep index
 * \param regionRegionIndex [IN] region index
 *
\return true if value of the enable field inside the control register matches the value: Disable
 */
extern bool CSL_fwIsRegionDisable(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex);
/**
 *  \brief FW Set the value of Region
 *
 * This function set the value of the enable field of the control register to the argument value
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionEpIndex [IN] ep index
 * \param regionRegionIndex [IN] region index
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureRegion(CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex, CSL_FwRegion_t);
/**
 *  \brief FW Query value of RegionLock
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionLockEpIndex [IN] ep index
 * \param regionLockRegionIndex [IN] region index
 *
\return true if value of the lock field inside the control register matches the value: Enable
 */
extern bool CSL_fwIsRegionLockEnable(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex);
/**
 *  \brief FW Query value of RegionLock
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionLockEpIndex [IN] ep index
 * \param regionLockRegionIndex [IN] region index
 *
\return true if value of the lock field inside the control register matches the value: Disable
 */
extern bool CSL_fwIsRegionLockDisable(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex);
/**
 *  \brief FW Set the value of RegionLock
 *
 * This function set the value of the lock field of the control register to the argument value
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionLockEpIndex [IN] ep index
 * \param regionLockRegionIndex [IN] region index
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureRegionLock(CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex, CSL_FwRegionLock_t);
/**
 *  \brief FW Query value of BackgroundRegion
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param backgroundRegionEpIndex [IN] ep index
 * \param backgroundRegionRegionIndex [IN] region index
 *
\return true if value of the background field inside the control register matches the value: Set
 */
extern bool CSL_fwIsBackgroundRegionSet(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex);
/**
 *  \brief FW Query value of BackgroundRegion
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param backgroundRegionEpIndex [IN] ep index
 * \param backgroundRegionRegionIndex [IN] region index
 *
\return true if value of the background field inside the control register matches the value: Clear
 */
extern bool CSL_fwIsBackgroundRegionClear(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex);
/**
 *  \brief FW Set the value of BackgroundRegion
 *
 * This function set the value of the background field of the control register to the argument value
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param backgroundRegionEpIndex [IN] ep index
 * \param backgroundRegionRegionIndex [IN] region index
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureBackgroundRegion(CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex, CSL_FwBackgroundRegion_t);
/**
 *  \brief FW Query value of CacheableTrans
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param cacheableTransEpIndex [IN] ep index
 * \param cacheableTransRegionIndex [IN] region index
 *
\return true if value of the cache_mode field inside the control register matches the value: Ignore
 */
extern bool CSL_fwIsCacheableTransIgnore(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex);
/**
 *  \brief FW Query value of CacheableTrans
 *
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param cacheableTransEpIndex [IN] ep index
 * \param cacheableTransRegionIndex [IN] region index
 *
\return true if value of the cache_mode field inside the control register matches the value: Check
 */
extern bool CSL_fwIsCacheableTransCheck(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex);
/**
 *  \brief FW Set the value of CacheableTrans
 *
 * This function set the value of the cache_mode field of the control register to the argument value
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param cacheableTransEpIndex [IN] ep index
 * \param cacheableTransRegionIndex [IN] region index
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwConfigureCacheableTrans(CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex, CSL_FwCacheableTrans_t);

/* Functions to access the feature: RegionPermissions*/

/**
 *  \brief FW Read the attributes of RegionPermissions
 *
 * This function reads the attributes of the RegionPermissions feature and fills out the user-supplied structure pCSL_FwRegionPermissions_t
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionPermissionsEpIndex [IN] ep index
 * \param regionPermissionsRegionIndex [IN] region index
 * \param regionPermissionsPermissionIndex [IN] permission index
 * \param pCSL_FwRegionPermissions_t [OUT] Pointer to user-supplied structure to be populated from register overlay.
 *
\return int32_t. CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwGetRegionPermissions(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionPermissionsEpIndex, uint32_t regionPermissionsRegionIndex, uint32_t regionPermissionsPermissionIndex, CSL_FwRegionPermissions_t *pCSL_FwRegionPermissions_t);
/**
 *  \brief FW Set up the attributes of RegionPermissions
 *
 * This function sets up the attributes of the RegionPermissions feature by reading the user-supplied structure pCSL_FwRegionPermissions_t
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionPermissionsEpIndex [IN] ep index
 * \param regionPermissionsRegionIndex [IN] region index
 * \param regionPermissionsPermissionIndex [IN] permission index
 * \param pCSL_FwRegionPermissions_t [IN] Pointer to user-supplied structure whose contents are used to set up the register overlay.
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwSetRegionPermissions(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionPermissionsEpIndex, uint32_t regionPermissionsRegionIndex, uint32_t regionPermissionsPermissionIndex, const CSL_FwRegionPermissions_t *pCSL_FwRegionPermissions_t);
/* Functions to access the feature: RegionAddrRange*/

/**
 *  \brief FW Read the attributes of RegionAddrRange
 *
 * This function reads the attributes of the RegionAddrRange feature and fills out the user-supplied structure pCSL_FwRegionAddrRange_t
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionAddrRangeEpIndex [IN] ep index
 * \param regionAddrRangeRegionIndex [IN] region index
 * \param pCSL_FwRegionAddrRange_t [OUT] Pointer to user-supplied structure to be populated from register overlay.
 *
\return int32_t. CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwGetRegionAddrRange(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionAddrRangeEpIndex, uint32_t regionAddrRangeRegionIndex, CSL_FwRegionAddrRange_t *pCSL_FwRegionAddrRange_t);
/**
 *  \brief FW Set up the attributes of RegionAddrRange
 *
 * This function sets up the attributes of the RegionAddrRange feature by reading the user-supplied structure pCSL_FwRegionAddrRange_t
 *
 * \param pCbass_FwRegs [IN]  Pointer to IP Register Overlay
 * \param regionAddrRangeEpIndex [IN] ep index
 * \param regionAddrRangeRegionIndex [IN] region index
 * \param pCSL_FwRegionAddrRange_t [IN] Pointer to user-supplied structure whose contents are used to set up the register overlay.
 *
\return CSL_PASS if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_fwSetRegionAddrRange(const CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionAddrRangeEpIndex, uint32_t regionAddrRangeRegionIndex, const CSL_FwRegionAddrRange_t *pCSL_FwRegionAddrRange_t);
/** @}*/


#ifdef __cplusplus
}
#endif
#endif
