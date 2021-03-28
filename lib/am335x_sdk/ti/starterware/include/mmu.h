/**
 *  \file   mmu.h
 *
 *  \brief  MMU configuration API prototypes
 *
 *  This file contains the API prototypes and structure definitions
 *  for configuring MMU.
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

#ifndef MMU_H_
#define MMU_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enum defining the possible memory configurations in MMU page table.
 *
 *  The parameters considered are memory type (Strongly Ordered(SO), Device, 
 *  Normal) and share-ability.
 *
 *  \note The enum sequence is not supposed to be changed, as the corresponding
 *        implementation relies on this. Additional entities can be added to
 *        the end.
 */
typedef enum mmuMemAttr
{
	MMU_MEM_ATTR_MIN, /**< Indicates the minimum supported value */
    MMU_MEM_ATTR_SO_SHAREABLE = MMU_MEM_ATTR_MIN, /**< Strongly-Ordered memory
														(always shareable) */
    MMU_MEM_ATTR_DEVICE_SHAREABLE,     /**< Device memory, Shareable */
    MMU_MEM_ATTR_DEVICE_NON_SHAREABLE, /**< Device memory, Non shareable  */
    MMU_MEM_ATTR_NORMAL_SHAREABLE,     /**< Normal memory, Shareable */
    MMU_MEM_ATTR_NORMAL_NON_SHAREABLE,  /**< Normal memory, Non shareable */
	MMU_MEM_ATTR_MAX = MMU_MEM_ATTR_NORMAL_NON_SHAREABLE
	/**< Indicates the maximum supported value in this enum */
}mmuMemAttr_t;

/**
 *  \brief Enum defining the possible cache configurations for memory sections.
 *
 *  The parameters considered are cache-ability, write back/through and 
 *  write/no-write allocate.
 */
typedef enum mmuCachePolicy
{
	MMU_CACHE_POLICY_MIN, /**< Indicates the minimum supported value */
    MMU_CACHE_POLICY_NON_CACHEABLE = MMU_CACHE_POLICY_MIN,/**< Non-cache-able*/
    MMU_CACHE_POLICY_WB_WA,          /**< Write back, Write allocate */
    MMU_CACHE_POLICY_WT_NOWA,        /**< Write through, No write allocate */
    MMU_CACHE_POLICY_WB_NOWA,        /**< Write back, No write allocate */
	MMU_CACHE_POLICY_MAX = MMU_CACHE_POLICY_WB_NOWA
	/**< Indicates the maximum supported value in this enum */
}mmuCachePolicy_t;

/**
 *  \brief Enum defining the possible access configurations for memory 
 *         sections.
 *
 *  The parameters considered are privileged and user mode read/write access 
 *  and executable property. 
 *
 *  \note The enum sequence is not supposed to be changed, as the corresponding
 *        implementation relies on this. Additional entities can be added to
 *        the end.
 */
typedef enum mmuAccessCtrl
{
	MMU_ACCESS_CTRL_MIN, /**< Indicates the minimum supported value */
    MMU_ACCESS_CTRL_PRV_NA_USR_NA = MMU_ACCESS_CTRL_MIN, 
	/**< privilege and User mode - No Access */
	
    MMU_ACCESS_CTRL_PRV_RW_USR_NA, /**< privilege (R/W), User (No Access) */
    MMU_ACCESS_CTRL_PRV_RW_USR_RO, /**< privilege (R/W), User (Read Only) */
    MMU_ACCESS_CTRL_PRV_RW_USR_RW, /**< privilege and user mode -(R/W) */
    MMU_ACCESS_CTRL_PRV_RO_USR_NA, /**< privilege (RO), User (No Access) */
    MMU_ACCESS_CTRL_PRV_RO_USR_RO, /**< privilege (RO), User (RO) */
    MMU_ACCESS_CTRL_PRV_NO_EXEC,    /**< NO Execute, If the section is read 
                                        sensitive this value can be OR'ed with
                                        the above values. */
	MMU_ACCESS_CTRL_MAX = MMU_ACCESS_CTRL_PRV_NO_EXEC
	/**< Indicates the maximum supported value in this enum */
}mmuAccessCtrl_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Structure defining the different properties that define the memory 
 *         regions for MMU configuration.
 *
 *  Assumed Virtual Address = Physical Address.
 */
typedef struct region {
    uint32_t        startAddr;    /**< Start Address of the page */
    uint32_t        numPages;     /**< Number of Pages in the region */
    uint32_t        pgSize;       /**< Size of the Page (in bytes) */
    mmuMemAttr_t    memAttrib;    /**< SO, Device, Normal (shareable ?) */
    mmuCachePolicy_t   innerCachePolicy; /**< Applicable for normal mem only */
    mmuCachePolicy_t   outerCachePolicy; /**< Applicable for normal mem only */
    mmuAccessCtrl_t    accessCtrl;   /**< Access Permissions for the page */
    uint32_t         isMemSecure;  /**< Secure or non secure (TRUE or FALSE) */
} mmuMemRegionConfig_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initializes the Page Table with fault entries and initializes MMU.
 *          The Page Table base addr is passed by the application.
 *
 * \param   pMasterPt          Master Page Table Base Address
 * \param   numPageTableEntry  Number of entries in the page table
 *
 * \retval  None.
 *
 * \note    Only a single level paging is supported.
 **/
void MMUInit(uint32_t *pMasterPt, uint32_t numPageTableEntry);


/**
 * \brief   Maps a specific region for Virtual Address to Physical Address
 *          conversion. This API actually updates the corresponding page table 
 *          entries. The mapping for any region is such that Virtual Address
 *          = Physical Address.
 *          Any region can be mapped as per the attributes given.
 *          
 * \param   pRegion     Memory Region to be mapped.
 *          #mmuMemRegionConfig_t
 *
 *            Example Configuration:
 *              A 512MB RAM memory region starting at address 0x80000000 can be
 *              configured as shown below. The memory is to be cache-able, with
 *              Inner Cache - Write Back Write Allocate and Outer Cache -
 *              Non-Cache-able. Accessible(Read/Write) in both privilege and 
 *              user modes. The security type is secure.
 *
 *              mmuMemRegionConfig_t regionRam = { 0x80000000,
 *                                                 512,
 *                                                 1*MEM_SIZE_MB,
 *                                                 MMU_MEM_ATTR_NORMAL_SHAREABLE,
 *                                                 MMU_CACHE_POLICY_WB_WA,
 *                                                 MMU_CACHE_POLICY_NON_CACHEABLE,
 *                                                 MMU_ACCESS_CTRL_PRV_RW_USR_RW,
 *                                                 TRUE
 *                                               };
 *
 * \param   pMasterPt   Page table base address.
 *
 * \retval  status  The return value can be any of,
 *                  S_PASS - Region configuration success
 *                  E_INVALID_PARAM - Invalid parameter
 *
 * \note    The regions specify the desired cache policies only. However,
 *          enabling of cache at all desired levels shall be done separately
 *          using cache API's.
 **/
int32_t MMUMemRegionMap(mmuMemRegionConfig_t *pRegion, uint32_t *pMasterPt);


/**
 * \brief   Updates the Translation Table Base with the address of Master Page
 *          Table and enables MMU.
 *
 * \param   pMasterPt      Master Page Table Base Address
 *
 * \retval  None.
 *
 * \note    Only TTB0 is used for page table walking.
 **/
void MMUEnable(uint32_t *pMasterPt);


/**
 * \brief   Disables MMU. 
 *
 * \note    It is expected that the cache is disabled before calling this API.
 *          Also unaligned access will not work after disabling the MMU.
 **/
void MMUDisable(void);


#ifdef __cplusplus
}
#endif
#endif /* MMU_H_ */
