/* =============================================================================
 *   Copyright (c) 2017-2019 Texas Instruments Incorporated
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
 *  \file   csl_pvu.h
 *
 *  \brief  This is the CSL header file for the Peripheral Virtualization
 *          Unit (PVU) CSL-FL.
 */
#ifndef CSL_PVU_H_
#define CSL_PVU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_pvu.h>

/** ===========================================================================
 *
 * @defgroup CSL_PVU_API Peripheral Virtualization Unit (PVU) CSL-FL API
 *
 *  The following is the recommended procedure for using the PVU CSL-FL API to
 *  configure, enable, and service the PVU:
 *
 *  1. Configure the PVU
 *     Helper functions: CSL_pvuGetRevision, CSL_pvuGetCfg, CSL_pvuGetTlbNum
 *     a) CSL_pvuSetMaxVirtId (required)
 *     b) CSL_pvuCfgDmaClassSupport (optional)
 *     c) CSL_pvuCfgTlb (required)
 *     d) CSL_pvuSetTlbEnable (required)
 *     e) CSL_pvuChainToTlb (optional)
 *     f) CSL_pvuSetTlbFaultLogging (optional)
 *     g) CSL_pvuSetExceptionTypeLoggingEnable (optional)
 *     h) CSL_pvuSetErrMsgDestId (optional)
 *     i) CSL_pvuSetExceptionLoggingEnable (optional)
 *  2. Enable the PVU
 *     a) CSL_pvuSetEnable (required)
 *  3. Service PVU faults and exceptions
 *     o  CSL_pvuIsTlbFaultSet
 *     o  CSL_pvuClrTlbFault
 *     o  CSL_pvuIsExceptionIntrPending
 *     o  CSL_pvuSetExceptionIntrPendingSet
 *     o  CSL_pvuAckExceptionIntr
 *     o  CSL_pvuSetExceptionIntrEnable
 *     o  CSL_pvuGetExceptionInfo
 * ============================================================================
 */
/**
@defgroup CSL_PVU_DATASTRUCT  PVU Data Structures
@ingroup CSL_PVU_API
*/
/**
@defgroup CSL_PVU_FUNCTION  PVU Functions
@ingroup CSL_PVU_API
*/
/**
@defgroup CSL_PVU_ENUM PVU Enumerated Data Types
@ingroup CSL_PVU_API
*/

/**
 *  \addtogroup CSL_PVU_ENUM
 *  @{
 */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines valid exception types
 *
 *  \anchor CSL_PvuExceptionType
 *  \name PVU exception types
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuExceptionType;
        /** virtID permission fault */
#define CSL_PVU_EXCEPTION_TYPE_VIRTID           ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_VIRTID_DIS_MASK)
        /** read permission fault */
#define CSL_PVU_EXCEPTION_TYPE_READ             ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_READ_DIS_MASK)
        /** write permission fault */
#define CSL_PVU_EXCEPTION_TYPE_WRITE            ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_WRITE_DIS_MASK)
        /** execute permission fault */
#define CSL_PVU_EXCEPTION_TYPE_EXEC             ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_EXEC_DIS_MASK)
        /** prefetch permission fault */
#define CSL_PVU_EXCEPTION_TYPE_PREF             ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_PREF_DIS_MASK)
        /** tlb miss fault */
#define CSL_PVU_EXCEPTION_TYPE_MISS             ((uint32_t) CSL_PVU_EXCEPTION_LOGGING_DISABLE_MISS_DIS_MASK)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines TLB configuration entry modes
 *
 *  \anchor CSL_PvuTlbCfgEntryMode
 *  \name PVU TLB configuration entry modes
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuTlbCfgEntryMode;
        /** tlb entry is invalid */
#define CSL_PVU_TLB_CFG_ENTRY_MODE_INVALID      ((uint32_t) 0U)
        /** tlb entry is valid */
#define CSL_PVU_TLB_CFG_ENTRY_MODE_VALID        ((uint32_t) 2U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines TLB configuration page sizes
 *
 *  \anchor CSL_PvuTlbCfgPageSize
 *  \name PVU TLB configuration page sizes
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuTlbCfgPageSize;
        /** 4KB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_4K            ((uint32_t) 0U)
        /** 16KB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_16K           ((uint32_t) 1U)
        /** 64KB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_64K           ((uint32_t) 2U)
        /** 2MB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_2M            ((uint32_t) 3U)
        /** 32MB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_32M           ((uint32_t) 4U)
        /** 512MB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_512M          ((uint32_t) 5U)
        /** 1GB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_1G            ((uint32_t) 6U)
        /** 16GB page size */
#define CSL_PVU_TLB_CFG_PAGE_SIZE_16G           ((uint32_t) 7U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines TLB configuration page permissions
 *
 *  \anchor CSL_PvuTlbCfgPagePerm
 *  \name PVU TLB configuration page permissions
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuTlbCfgPagePerm;
        /** user read access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_UR            ((uint32_t) (1U<<0))
        /** user write access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_UW            ((uint32_t) (1U<<1))
        /** user execute access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_UX            ((uint32_t) (1U<<2))
        /** supervisor read access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_SR            ((uint32_t) (1U<<3))
        /** supervisor write access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_SW            ((uint32_t) (1U<<4))
        /** supervisor execute access */
#define CSL_PVU_TLB_CFG_PAGE_PERM_SX            ((uint32_t) (1U<<5))
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines TLB configuration page memory types
 *
 *  \anchor CSL_PvuTlbCfgPageMemType
 *  \name PVU TLB configuration page memory types
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuTlbCfgPageMemType;
        /** device memory type */
#define CSL_PVU_TLB_CFG_PAGE_MEM_TYPE_DEVICE    ((uint32_t) 0U)
        /** write-back memory type */
#define CSL_PVU_TLB_CFG_PAGE_MEM_TYPE_WB        ((uint32_t) 1U)
        /** write-through memory type */
#define CSL_PVU_TLB_CFG_PAGE_MEM_TYPE_WT        ((uint32_t) 2U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines TLB configuration page allocation policies
 *
 *  \anchor CSL_PvuTlbCfgPageAllocPolicy
 *  \name PVU TLB configuration page allocation policies
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PvuTlbCfgPageAllocPolicy;
        /** no page allocation policy */
#define CSL_PVU_TLB_CFG_PAGE_ALLOC_POLICY_NO    ((uint32_t) 0U)
        /** allocate page on write */
#define CSL_PVU_TLB_CFG_PAGE_ALLOC_POLICY_W     ((uint32_t) 1U)
        /** allocate page on read */
#define CSL_PVU_TLB_CFG_PAGE_ALLOC_POLICY_R     ((uint32_t) 2U)
        /** allocate page on read and write */
#define CSL_PVU_TLB_CFG_PAGE_ALLOC_POLICY_RW    ((uint32_t) 3U)
/* @} */

/* @} */

/**
 *  \addtogroup CSL_PVU_DATASTRUCT
 *  @{
 */

/** \brief TLB configuration structure passed to the CSL_pvuCfgTlb() function */
typedef struct
{
    uint64_t                        virtBaseAddr;           /** virtual base address */
    uint64_t                        physBaseAddr;           /** physical base address */
    CSL_PvuTlbCfgEntryMode          mode;                   /** mode of the TLB entry (see \ref CSL_PvuTlbCfgEntryMode) */
    bool                            bPageSecure;            /** page secure attribute */
    bool                            bPagePrefetch;          /** page prefetch attribute */
    bool                            bPageInnerShareable;    /** page inner shareable attribute */
    bool                            bPageOuterShareable;    /** page outer shareable attribute */
    bool                            bEnableSecDemote;       /** page secure transaction demotion attribute (if PVU is in secure mode) */
    CSL_PvuTlbCfgPageSize           pageSize;               /** page size (see \ref CSL_PvuTlbCfgPageSize) */
    uint32_t                        pagePerms;              /** page permissions containing logical OR of desired permissions (see \ref CSL_PvuTlbCfgPagePerm) */
    CSL_PvuTlbCfgPageMemType        pageMemType;            /** page memory type (see \ref CSL_PvuTlbCfgPageMemType) */
    CSL_PvuTlbCfgPageAllocPolicy    pageInnerAllocPolicy;   /** page inner allocation type (see \ref CSL_PvuTlbCfgPageAllocPolicy) */
    CSL_PvuTlbCfgPageAllocPolicy    pageOuterAllocPolicy;   /** page outer allocation type (see \ref CSL_PvuTlbCfgPageAllocPolicy) */
} CSL_PvuTlbCfg;

/** \brief Exception information returned by the CSL_pvuGetExceptionInfo() function */
typedef struct
{
    uint32_t    type;               /** Identifies the exception type (for PVU, this field should equal 6) */
    uint64_t    address;            /** Address */
    uint32_t    group;              /** Group */
    uint32_t    code;               /** Code */
    uint32_t    srcId;              /** Source ID */
    uint32_t    destId;             /** Destination ID */
    uint32_t    routeId;            /** Route ID */
    uint32_t    privId;             /** Priv ID */
    uint32_t    byteCnt;            /** Byte Count */
    bool        bWrite;             /** Write */
    bool        bRead;              /** Read */
    bool        bDebug;             /** Debug */
    bool        bCacheable;         /** Cacheable */
    bool        bPriv;              /** Priv */
    bool        bSecure;            /** Secure */
} CSL_PvuExceptionInfo;

/** \brief PVU configuration structure passed to all API functions */
typedef struct
{
    CSL_pvuRegs     *pPvuRegs;          /** Pointer to PVU register structure base address */
    CSL_pvu_tlbRegs *pPvuTlbRegs;       /** Pointer to PVU TLB register structure base address */
    uint32_t        numTlbs;            /* Internal storage for number of TLBs supported in the PVU */
    uint32_t        numEntriesPerTlb;   /* Internal storage for number of entried per TLB supported in the PVU */
    uint32_t        numVirtIds;         /* Internal storage for the number of virtid's considered valid */
    uint32_t        numDmaVirtIds;      /* Internal storage for the number of DMA virtid's */
} CSL_PvuCfg;

/* @} */

/**
 *  \addtogroup CSL_PSILCFG_FUNCTION
 *  @{
 */

/**
 *  \brief Return revision of the PVU module
 *
 *  This function returns the contents of the PVU revision register.
 *  Consult the PVU module documentation for a description of the
 *  contents of the revision register.
 *
 *  \param pPvuCfg  [IN]    Pointer to the CSL_PvuCfg config structure
 *
 *  \return The 32-bit revision register is returned.
 */
uint32_t CSL_pvuGetRevision( const CSL_PvuCfg *pPvuCfg );

/**
 *  \brief Get PVU configuration
 *
 *  This function returns the PVU hardware configuration, specifically the
 *  number of TLBs supported in the PVU and the number of entries available
 *  per TLB.
 *
 *  These values can be queried by the caller to determine the TLB resources
 *  available in the PVU.
 *
 *  \param pPvuCfg           [IN]  Pointer to the CSL_PvuCfg config structure
 *  \param pNumTlbs          [OUT] Number of TLBs supported is returned
 *  \param pNumEntriesPerTlb [OUT] Number of entries per TLB is returned
 *
 *  \return None
 */
void CSL_pvuGetCfg( CSL_PvuCfg *pPvuCfg, uint32_t *pNumTlbs, uint32_t *pNumEntriesPerTlb );

/**
 *  \brief Set the maximum number of virtid values
 *
 *  This function allows the caller to set the maximum number of virtid values
 *  (0..numVirtIds-1) considered valid by the PVU. This value must be <= the #
 *  of TLB's supported by the PVU (see the pNumTlbs value in
 *  #CSL_pvuGetCfg).
 *
 *  Note: The caller must call this function prior to enabling the PVU via
 *  #CSL_pvuSetEnable.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param numVirtIds   [IN]    Maximum number of virtid's
 *
 *  \return  0 = success
 *          -1 = numVirtIds is invalid
 */
int32_t CSL_pvuSetMaxVirtId( CSL_PvuCfg *pPvuCfg, uint32_t numVirtIds );

/**
 *  \brief Configure DMA class support
 *
 *  This function configures the DMA class support in the PVU.
 *
 *  The numDmaVirtIds specifies the maximum number of virtid values
 *  (0..numDmaVirtIds-1) used for DMA purposes. This value must be <= the # of
 *  TLB's supported by the PVU (see the pNumTlbs value in #CSL_pvuGetCfg).
 *
 *  The mapSubClass0 .. mapSubClass3 arguments specify the TLB select offset
 *  (0..3) for the given DMA virtid/TLB. For example, if the DMA virtid is 6,
 *  and mapSubClass2 is 2, then the corresponding TLB for this DMA subclass is
 *  26 ((6*4)+2).
 *
 *  Note: This function needs to be called only when DMA class support is
 *  desired in the PVU.
 *
 *  \param pPvuCfg       [IN]   Pointer to the CSL_PvuCfg config structure
 *  \param numDmaVirtIds [IN]   Max DMA virtid value
 *  \param mapSubClass0  [IN]   TLB select offset for DMA sub-class 0
 *  \param mapSubClass1  [IN]   TLB select offset for DMA sub-class 1
 *  \param mapSubClass2  [IN]   TLB select offset for DMA sub-class 2
 *  \param mapSubClass3  [IN]   TLB select offset for DMA sub-class 3
 *
 *  \return  0 = success
 *          -1 = numDmaVirtIds is invalid
 *          -2 = one or more mapSubClass arguments are invalid (must be 0..3)
 */
int32_t CSL_pvuCfgDmaClassSupport( CSL_PvuCfg *pPvuCfg, uint32_t numDmaVirtIds, uint32_t mapSubClass0, uint32_t mapSubClass1, uint32_t mapSubClass2, uint32_t mapSubClass3 );

/**
 *  \brief Return the TLB number associated with the specified virtId
 *
 *  This function returns the TLB number associated with the specified virtId.
 *  It uses the following formula:
 *
 *    if( virtId < numDmaVirtIds )
 *    {
 *      tlbNum = (virtId * 4) + dmaSubClass;
 *    }
 *    else
 *    {
 *      tlbNum = (numDmaVirtIds * 4) + (virtId - numDmaVirtIds).
 *    }
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param virtId       [IN]    virtid
 *  \param dmaSubClass  [IN]    dma sub-class (valid only if virtId belongs
 *                              to a DMA class)
 *
 *  \return >=0 = success (the TLB number is returned)
 *           -1 = virtId is invalid
 *           -2 = dmaSubClass is invalid (must be 0..3)
 */
int32_t CSL_pvuGetTlbNum( const CSL_PvuCfg *pPvuCfg, uint32_t virtId, uint32_t dmaSubClass );

/**
 *  \brief Configure a TLB entry
 *
 *  This function is used to configure the specified TLB entry.
 *
 *  Note that the TLB must be disabled before it can be configured.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *  \param entryNum     [IN]    TLB entry number
 *  \param pTlbCfg      [IN]    Pointer to TLB configuration structure (see
 *                              #CSL_PvuTlbCfg)
 *
 *  \return  0 = success
 *          -1 = tlbNum or entryNum arguments are invalid
 *          -2 = TLB is currently enabled (disable it first)
 */
int32_t CSL_pvuCfgTlb( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, uint32_t entryNum, const CSL_PvuTlbCfg *pTlbCfg );

/**
 *  \brief Enable or disable a TLB
 *
 *  This function is used to enable or disable the specified TLB.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *  \param bEnable      [IN]    If true, the TLB is enabled. If false, it is
 *                              disabled.
 *
 *  \return  0 = success
 *          -1 = tlbNum argument is invalid
 */
int32_t CSL_pvuSetTlbEnable( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, bool bEnable );

/**
 *  \brief Chain to another TLB
 *
 *  This function is used chain a TLB to another TLB.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg       [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum        [IN]    The TLB number to chain
 *  \param chainToTlbNum [IN]    The TLB number to chain to
 *
 *  \return  0 = success
 *          -1 = tlbNum or chainToTlbNum arguments are invalid
 */
int32_t CSL_pvuChainToTlb( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, uint32_t chainToTlbNum );

/**
 *  \brief Enable or disable fault logging for a TLB
 *
 *  This function is used to enable or disable fault logging for the specified
 *  TLB.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *  \param bEnable      [IN]    If true, fault logging for the TLB is enabled.
 *                              If false, it is disabled.
 *
 *  \return  0 = success
 *          -1 = tlbNum argument is invalid
 */
int32_t CSL_pvuSetTlbFaultLogging( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, bool bEnable );

/**
 *  \brief Enable or disable logging of the specified exception types
 *
 *  This function is used to enable or disable logging of the specified
 *  exception types.
 *
 *  The exceptionTypes argument is a logical OR of the exception types to
 *  enable or disable. See \ref CSL_PvuExceptionType for a list of valid exception
 *  types.
 *
 *  \param pPvuCfg        [IN]  Pointer to the CSL_PvuCfg config structure
 *  \param exceptionTypes [IN]  Logical OR of exception types
 *  \param bEnable        [IN]  If true, logging of the specified exception
 *                              types is enabled. If false, they are disabled.
 *
 *  \return  None
 */
void CSL_pvuSetExceptionTypeLoggingEnable( const CSL_PvuCfg *pPvuCfg, uint32_t exceptionTypes, bool bEnable );

/**
 *  \brief Set the destination ID value for error messages
 *
 *  This function is used to set the destination ID for error messages
 *  produced by the PVU.
 *
 *  \param pPvuCfg      [IN]  Pointer to the CSL_PvuCfg config structure
 *  \param destId       [IN]  Destination ID
 *
 *  \return  None
 */
void CSL_pvuSetErrMsgDestId( const CSL_PvuCfg *pPvuCfg, uint32_t destId );

/**
 *  \brief Enable or disable exception error logging
 *
 *  This function is used to enable or disable exception error logging.
 *
 *  When enabled, information is logged when an exception occurs and can be
 *  read by calling \ref CSL_pvuGetExceptionInfo. Also, the module's exception
 *  interrupt signal is asserted if the exception interrupt source is enabled.
 *
 *  When disabled, no information is logged when an exception occurs. Also, the
 *  module's exception interrupt signal generation is disabled, regardless of
 *  whether the exception interrupt source is enabled or disabled.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param bEnable      [IN]    If true, exception error logging is enabled.
 *                              If false, it is disabled.
 *
 *  \return  None
 */
void CSL_pvuSetExceptionLoggingEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable );

/**
 *  \brief Enable or disable the PVU
 *
 *  This function is used to enable or disable the PVU.
 *
 *  Prior to enabling the PVU, the following functions must/may be
 *  called to configure the PVU:
 *
 *     a) CSL_pvuSetMaxVirtId (required)
 *     b) CSL_pvuCfgDmaClassSupport (optional)
 *     c) CSL_pvuCfgTlb (required)
 *     d) CSL_pvuSetTlbEnable (required)
 *     e) CSL_pvuChainToTlb (optional)
 *     f) CSL_pvuSetTlbFaultLogging (optional)
 *     g) CSL_pvuSetExceptionTypeLoggingEnable (optional)
 *     h) CSL_pvuSetErrMsgDestId (optional)
 *     i) CSL_pvuSetExceptionLoggingEnable (optional)
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param bEnable      [IN]    If true, the PVU is enabled.
 *                              If false, it is disabled.
 *
 *  \return  0 = success
 *          -1 = Required configuration functions have not been called
 */
int32_t CSL_pvuSetEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable );

/**
 *  \brief Has a TLB fault been detected that could not be logged?
 *
 *  This function is used to determine if a fault has been detected that could
 *  not be logged for the specified TLB.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *
 *  \return  1 = true (fault detected)
 *           0 = false (fault not detected)
 *          -1 = tlbNum argument is invalid
 */
int32_t CSL_pvuIsTlbFaultSet( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum );

/**
 *  \brief Clear TLB fault
 *
 *  This function is used to clear a TLB fault.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *
 *  \return  0 = success
 *          -1 = tlbNum argument is invalid
 */
int32_t CSL_pvuClrTlbFault( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum );

/**
 *  \brief Is the exception interrupt pending?
 *
 *  This function is used to determine if the exception interrupt is pending.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *
 *  \return  true  = The exception interrupt is pending
 *           false = The exception interrupt is not pending
 */
bool CSL_pvuIsExceptionIntrPending( const CSL_PvuCfg *pPvuCfg );

/**
 *  \brief Set or clear a pending exception interrupt
 *
 *  This function is used to forcibly set or clear the exception interrupt.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param bSet         [IN]    If true, the exception interrupt is forcibly
 *                              set. If false, the exception interrupt is
 *                              cleared.
 *
 *  \return  None
 */
void CSL_pvuSetExceptionIntrPendingSet( const CSL_PvuCfg *pPvuCfg, bool bSet );

/**
 *  \brief Acknowledge exception interrupt
 *
 *  This function is used to acknowledge the exception interrupt.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *
 *  \return  None
 */
void CSL_pvuAckExceptionIntr( const CSL_PvuCfg *pPvuCfg );

/**
 *  \brief Enable or disable the assertion of the exception interrupt signal
 *
 *  This function is used to enable or disable assertion of the exception
 *  interrupt signal.
 *
 *  If enabled, this function also calls \ref CSL_pvuSetExceptionLoggingEnable
 *  to enable exception logging as there is no valid reason to enable the
 *  exception interrupt source and not log the exception information and assert
 *  the module's exception interrupt signal.
 * 
 *  If disabled, the module's exception interrupt signal is prevented from
 *  being asserted. Note that software can still call
 *  \ref CSL_pvuIsExceptionIntrPending to poll for an exception event and call
 *  \ref CSL_pvuGetExceptionInfo to read exception event information if
 *  exception logging is enabled.
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param bEnable      [IN]    If true, assertion of the exception interrupt
 *                              signal is enabled. If false, it is disabled.
 *
 *  \return  None
 */
void CSL_pvuSetExceptionIntrEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable );

/**
 *  \brief Get exception information
 *
 *  This function is used to get detailed exception information.
 *
 *  \param pPvuCfg        [IN]  Pointer to the CSL_PvuCfg config structure
 *  \param pExceptionInfo [IN]  Pointer to a #CSL_PvuExceptionInfo structure
 *                              where the exception information is written to
 *
 *  \return  None
 */
void CSL_pvuGetExceptionInfo( const CSL_PvuCfg *pPvuCfg, CSL_PvuExceptionInfo *pExceptionInfo );

/* @} */

#ifdef __cplusplus
}
#endif

#endif
