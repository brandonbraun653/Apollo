/**
 * @file  csl_fss.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the FSS IP module.
 *
 *  ============================================================================
 *  @n   (C) Copyright 2019, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorpopated nor the names of
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
#ifndef CSL_FSS_H_
#define CSL_FSS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_fss.h>

/** ===========================================================================
 *
 * @defgroup CSL_FSS_API FSS
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the FSS and FSS_UL modules.
 *
 *  FSS/FSAS CSL-FL API usage
 *    If using the FSS module, there are 2 interfaces provided. These interfaces are
 *    defined in the \ref CSL_FssInterfaceSelect enumerator as follows:
 *      a) CSL_FSS_INTERFACE_SELECT_FSAS - FSAS interface (to OSPI0 or HYPERBUS)
 *      b) CSL_FSS_INTERFACE_SELECT_FSS  - FSS interface (to OSPI1)
 *
 *    If using the FSS_UL module, there is only 1 interface provided:
 *      a) CSL_FSS_INTERFACE_SELECT_FSAS - FSAS interface (to OSPI0)
 *
*      The following FSS API functions require an ifSelect argument set to one
 *      of the values above:
 *        - \ref CSL_fssCfgEcc
 *        - \ref CSL_fssCfgEccRegion
 *        - \ref CSL_fssSetIntrEnable
 *        - \ref CSL_fssSetIntrPendingStatus
 *        - \ref CSL_fssIsIntrPending
 *        - \ref CSL_fssAckIntr
 *        - \ref CSL_fssGetEccBlockErrorInfo
 *        - \ref CSL_fssGetWrErrorInfo
 *
 *    The following is the recommended calling sequence to configure and enable
 *    each interface:
 *      1. Configure the desired ecc regions by calling
 *         \ref CSL_fssCfgEccRegion
 *      2. If using the CSL_FSS_INTERFACE_SELECT_FSAS interface, call the
 *         \ref CSL_fssSelectInterfacePath to select OSPI0 or HYPERBUS
 *      3. Configure desired interrupt support by calling
 *         \ref CSL_fssSetIntrEnable
 *      4. Enable ecc functionality by calling
 *         \ref CSL_fssCfgEcc with true

 *  OTFA CSL-FL API usage
 *    The following is the recommended calling sequence to configure and enable
 *    the OTFA module:
 *      1. Confirm that crypto functionality is available by calling
 *         \ref CSL_fssOtfaIsCryptoAvailable and checking if true
 *         is returned
 *      2. Configure the desired crypto regions by calling
 *         \ref CSL_fssOtfaCfgCryptoRegion
 *      3. Configure the crypto functionality by calling
 *         \ref CSL_fssOtfaCfgCrypto
 *      4. Configure desired interrupt support by calling
 *         \ref CSL_fssOtfaSetIntrEnable
 *      5. Enable crypto functionality by calling
 *         \ref CSL_fssOtfaSetCryptoEnable with true
 *
 *    Software can make changes to the OTFA configuration when it is enabled by
 *    following the protocol below:
 *      1. Pause the OTFA by calling \ref CSL_fssOtfaSetCryptoPause with true
 *      2. Make desired changes to region configuration
 *      3. Resume the OTFA by calling \ref CSL_fssOtfaSetCryptoPause with false
 *
 * @subsection References
 *    - fss Module Specification, version 1.0.12.01
 *    - fss_ul Module Specification, version 1.1.0.03
 *    - otfa_l Module Specification, version 1.1.9
 *
 * ============================================================================
 */
/**
@defgroup CSL_FSS_DATASTRUCT  FSS Data Structures
@ingroup CSL_FSS_API
*/
/**
@defgroup CSL_FSS_FUNCTION  FSS Functions
@ingroup CSL_FSS_API
*/
/**
@defgroup CSL_FSS_ENUM FSS Enumerated Data Types
@ingroup CSL_FSS_API
*/

/** ===========================================================================
 *  @addtogroup CSL_FSS_ENUM
    @{
 * ============================================================================
 */

#define CSL_FSS_MAX_ECC_PROTECTED_MEMORY_REGIONS    ((uint32_t) 4U)
#define CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS   ((uint32_t) 4U)

/* The CSL_FSS_IS_FULL_FEATURED macro is used to conditionally include code that is only
   applicable for the full FSS CSL-RL (not the FSS_UL CSL-RL). If the 
   CSL_FSS_GENREGS_SYSCONFIG_ECC_EN_MASK macro is defined in the CSL-RL, then
   we know we're dealing with the full FSS CSL-RL.
*/
#ifdef CSL_FSS_GENREGS_SYSCONFIG_ECC_EN_MASK
#define CSL_FSS_IS_FULL_FEATURED      (1U)
#else
#define CSL_FSS_IS_FULL_FEATURED      (0U)
#endif

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid interface selections for the FSS.
 *        Note that for fss_ul, only CSL_FSS_INTERFACE_SELECT_FSAS is valid.
 *
 *  \anchor CSL_FssInterfaceSelect
 *  \name Select desired FSS interface
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssInterfaceSelect;
    /**< Select FSAS interface (to OSPI0 or HYPERBUS) */
#define CSL_FSS_INTERFACE_SELECT_FSAS   ((uint32_t) 0U)
    /**< Select FSS interface (to OSPI1) */
#define CSL_FSS_INTERFACE_SELECT_FSS    ((uint32_t) 1U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator selects the desired path (OSPI0 or HYPERBUS) for the
 *        FSAS interface. Note that for fss_ul, only
 *        CSL_FSS_FSAS_INTERFACE_PATH_SELECT_OSPI0 is valid.
 *
 *  \anchor CSL_FssFsasInterfacePathSelect
 *  \name Select desired path for the FSAS interface
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssFsasInterfacePathSelect;
    /**< Select path to OSPI0 */
#define CSL_FSS_FSAS_INTERFACE_PATH_SELECT_OSPI0    ((uint32_t) 0U)
    /**< Select path to HyperBus */
#define CSL_FSS_FSAS_INTERFACE_PATH_SELECT_HYPERBUS ((uint32_t) 1U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid interrupt sources for the FSS
 *
 *  \anchor CSL_FssInterruptSourceSelect
 *  \name Select desired FSS interrupt source
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssInterruptSourceSelect;
    /**< ECC error on 1 bit, correctable */
#define CSL_FSS_INTERRUPT_SOURCE_SELECT_ECC_ERROR_1BIT      ((uint32_t) 0U)
    /**< ECC error on 2 bits, not correctable */
#define CSL_FSS_INTERRUPT_SOURCE_SELECT_ECC_ERROR_2BIT      ((uint32_t) 1U)
    /**< Write is not aligned to 32B boundary or not a multiple of 32B */
#define CSL_FSS_INTERRUPT_SOURCE_SELECT_ECC_WRITE_NONALIGN  ((uint32_t) 2U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid output interrupts for the FSS
 *
 *  \anchor CSL_FssOutputInterruptSelect
 *  \name Select desired FSS output interrupt
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOutputInterruptSelect;
    /**< ECC error interrupt */
#define CSL_FSS_OUTPUT_INTERRUPT_ECC_ERROR  ((uint32_t) 0U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid interrupt sources for the FSS
 *
 *  \anchor CSL_FssInterruptSourceSelect
 *  \name Select desired FSS interrupt source
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOtfaInterruptSourceSelect;
    /**< AES CTR enabled region violated write once per write key rule */
#define CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_CTR_WKV    ((uint32_t) 0U)
    /**< Region overflow boundary event caused by a burst transaction crossing a start or end of a region */
#define CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_REGION_BV  ((uint32_t) 1U)
    /**< Region write error event, write cmd issues when write is disabled */
#define CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_WRITE_ERR  ((uint32_t) 2U)
    /**< Region MAC compare error event, read MAC did not match the write MAC */
#define CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_MAC_ERR    ((uint32_t) 3U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid OTFA Authentication modes
 *
 *  \anchor CSL_FssOtfaMacMode
 *  \name OTFA Authentication modes
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOtfaMacMode;
    /**< Authentication is disabled */
#define CSL_FSS_OTFA_MAC_MODE_DISABLED  ((uint32_t) 0U)
    /**< GMAC mode, max burst size of 128 Bytes */
#define CSL_FSS_OTFA_MAC_MODE_GMAC      ((uint32_t) 1U)
    /**< CBC-MAC mode, max burst size of 128 Bytes */
#define CSL_FSS_OTFA_MAC_MODE_CBC_MAC   ((uint32_t) 2U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid OTFA Encryption modes
 *
 *  \anchor CSL_FssOtfaEncMode
 *  \name OTFA Encryption modes
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOtfaEncMode;
    /**< Encryption is disabled */
#define CSL_FSS_OTFA_ENC_MODE_DISABLED  ((uint32_t) 0U)
    /**< AES CTR mode */
#define CSL_FSS_OTFA_ENC_MODE_AES_CTR   ((uint32_t) 1U)
    /**< ECB+ mode */
#define CSL_FSS_OTFA_ENC_MODE_AES_ECB   ((uint32_t) 2U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid OTFA key sizes
 *
 *  \anchor CSL_FssOtfaKeySize
 *  \name OTFA key size
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOtfaKeySize;
    /**< 128-bit key size */
#define CSL_FSS_OTFA_KEY_SIZE_128_BITS  ((uint32_t) 0U)
    /**< 256-bit key size */
#define CSL_FSS_OTFA_KEY_SIZE_256_BITS  ((uint32_t) 1U)

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the valid allocations of the Ctypto cores
 *        to read transactions and write transactions
 *
 *  \anchor CSL_FssOtfaCrypoCoreAlloc
 *  \name OTFA crypto core allocation to read and write pipes
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_FssOtfaCrypoCoreAlloc;
    /**< Read and Write is balanced:
         50% of the cypto cores alocated to the Read Pipe,
         50% of the Cypto cores on the Write Pipe */
#define CSL_FSS_OTFA_CRYPTO_CORE_ALLOCATION_BALANCED        ((uint32_t) 0U)
    /**< Read optimized:
         75% of the cypto cores alocated to the Read Pipe,
         25% of the Cypto cores on the Write Pipe */
#define CSL_FSS_OTFA_CRYPTO_CORE_ALLOCATION_RD_OPTIMIZED    ((uint32_t) 1U)
    /**< Write optimized:
         25% of the cypto cores alocated to the Read Pipe,
         75% of the Cypto cores on the Write Pipe */
#define CSL_FSS_OTFA_CRYPTO_CORE_ALLOCATION_WR_OPTIMIZED    ((uint32_t) 2U)

/** @} */

/** ============================================================================
 *  @addtogroup CSL_FSS_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains configuration parameters for the FSS IP module
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    CSL_fss_genregsRegs         *pFssRegs;  /** Pointer to the FSS configuration register region */
    CSL_fss_fsas_genregsRegs    *pFsasRegs; /** Pointer to the FSAS configuration register region */
    CSL_fss_fsas_otfa_regsRegs  *pOtfaRegs; /** Pointer to the OTFA configuration register region */
    uint32_t                    otfaKeySizeWords;   /** Internal state variable used to store OTFA key size */
} CSL_FssCfg;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains information about an ECC block error
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    uint32_t blockAddr;     /** 32 byte aligned block address */
    uint32_t addr;          /** When set indicates that there was a single error detected within the address field */
    uint32_t mac;           /** When set indicates that there was a single error detected within the MAC field */
    uint32_t da1;           /** When set indicates that there was a single error detected within the High Data word */
    uint32_t da0;           /** When set indicates that there was a single error detected within the Low Data word */
    uint32_t ded;           /** When set indicates that there was a double error detected for the block */
    uint32_t sec;           /** When set indicates that there was a single error detected for the block */
} CSL_FssEccBlockErrorInfo;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains information about a write error
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    uint32_t routeId;       /** Indicates the Route ID for the Master that caused the write error */
    uint32_t byteEnable;    /** When set indicates that there was a write error due to non-contiguous byte enables */
    uint32_t addr;          /** When set indicates that there was a write error due to a non-aligned address */
} CSL_FssWrErrorInfo;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains parameters for configuring the OTFA crypto
 *          function
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    uint32_t keySize;           /** Key size. See \ref CSL_FssOtfaKeySize */
    uint32_t cryptoCoreAlloc;   /** Crypto core allocation. See \ref CSL_FssOtfaCrypoCoreAlloc */
    uint32_t bErrRespEnable;    /** If 0, error response sys_SResp[1:0] will
                                    not be driven on a MAC error event.
                                    Otherwise, it will be driven. */
} CSL_FssOtfaCryptoCfg;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains parameters for configuring an OTFA crypto
 *          region
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /**< Write protection mode: 0=disabled, otherwise enabled. When enabled,
         all write cmds will get forwarded with their byte enables nullified.
         Also a WRITE_ERR event will get set for that region which had the
         violation. */
    uint32_t writeProtect;
    /**< Defines the Authentication mode. See \ref CSL_FssOtfaMacMode */
    uint32_t macMode;
    /**< Defines the Encryption mode. See \ref CSL_FssOtfaEncMode */
    uint32_t encMode;
    /**< Defines the base address of the MAC signatures. Must be 4KB aligned. */
    uint32_t macSignaturesBaseAddr;
    /**< Defines the start of the crypto memory region. Must be 4KB aligned. */
    uint32_t regionAddrStart;
    /**< Defines the size of the crypto memory region. Must be a multiple of 4KB. */
    uint32_t regionSizeBytes;
    /**< Defines the Encryption key for AES-CTR modes. For AES ECB+ modes, this
         key is only used for write operations. */
    uint32_t encKey[8];
    /**< Defines the Encryption Prime key (decryption key) when ECB+ mode
         is enabled. Used only during read operations. SW must generate the
         encPrimeKey based on encKey. */
    uint32_t encPrimeKey[8];
    /**< Defines the Authentication key for GMAC modes. For CBC-MAC modes, this
         key is only used for write operations. */
    uint32_t macKey[4];
    /**< Defines the CBC-MAC Prime key (decryption key) when CBC-MAC mode is
         enabled. Used only during read operations. SW must generate the
         macPrimeKey based on macKey. */
    uint32_t macPrimeKey[4];
    /**< Defines the Initialization Vector used for Encryption/Authentication */
    uint32_t initializationVector[4];
} CSL_FssOtfaCryptoRegionCfg;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains additional IRQ information
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    uint32_t address;   /** Master address which caused the event */
    uint32_t length;    /** Master burst length which caused the event */
    uint32_t seq;       /** Master seq which caused the event. Not avalible for MAC error events. */
    uint32_t cmd;       /** Master cmd which caused the event */
    uint32_t id;        /** Master id which caused the event */
} CSL_FssOtfaIrqInfo;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains OTFA stat counters
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    uint32_t cacheMissCnt;  /** Number of cache miss events */
    uint32_t rmEventCnt;    /** Number of RM events */
    uint32_t rmwEventCnt;   /** Master of RMW events */
} CSL_FssOtfaStats;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_FSS_FUNCTION
    @{
 * ============================================================================
 */

/**
 *  \brief Return revision of the FSS IP module
 *
 *  This function returns the contents of the FSS revision register.
 *  Consult the FSS module documentation for a description of the
 *  contents of the revision register.
 *
 *  \param pFssCfg  [IN]    Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pRev     [OUT]   Pointer to uint32_t where revision is returned
 *
 *  \return CSL_PASS        The function completed successfully
 *          CSL_EBADARGS    pFssCfg and/or pRev are NULL
 */
extern int32_t CSL_fssGetRevision( const CSL_FssCfg *pFssCfg, uint32_t *pRev );

/**
 *  \brief Select the path (OSPI0 or HYPERBUS) for the interface to OSPI0 or HYPERBUS
 *
 *  This function selects to path (OSPI0 or HYPERBUS) for the interface
 *  conntected to OSPI0 or HYPERBUS.
 *
 *  The path will not be switched until traffic through the interface is idle.
 *  It is the responsibility of software to insure interface traffic is stopped
 *  before calling this function to select a different path.
 *
 *  \param pFssCfg      [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pathSelect   [IN] Path selector (\ref CSL_FssFsasInterfacePathSelect)
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The pathSelect argument is out-of-range.
 *                              See \ref CSL_FssFsasInterfacePathSelect.
 */
extern int32_t CSL_fssSelectInterfacePath( CSL_FssCfg *pFssCfg, uint32_t pathSelect );

/**
 *  \brief Configure ECC support for an interface
 *
 *  This function configures the ECC support for the interface specified by
 *  ifSelect.
 *
 *  \param pFssCfg                [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect               [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param bEccEnable             [IN] If true, ECC is enabled for this interface. Otherwise,
 *                                     ECC is disabled.
 *  \param bIncludeBlockAddrInEcc [IN] If true, the block address is included within the ECC
 *                                     calculation. Otherwise, the block address is excluded
 *                                     from the ECC calculation.
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect argument is out-of-range.
 *                              See \ref CSL_FssInterfaceSelect.
 */
extern int32_t CSL_fssCfgEcc( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEccEnable, bool bIncludeBlockAddrInEcc );

/**
 *  \brief Configure fragmentation for HyperBus
 *
 *  This function configures the Dynamic Fragmenter module for HyperBus.
 *
 *  The Dynamic Fragmenter module is responsible for fragmenting write data to
 *  the HyperBus (it will pass all other transactions through unaffected).
 *
 *  HyperBus Flash has a requirement that all writes to the flash region are
 *  done in 16bit chunks. HyperBus SRAM does not have this write fragmentation
 *  requirement.
 *
 *  The Dynamic Fragmenter module is configured to fragment all addresses by
 *  default. You can use this function to disable fragmentation for HyperBus
 *  SRAM areas.
 *
 *  \param pFssCfg  [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param fragAddr [IN] This is the address of a request that the bFragLo or
 *                       bFragHi boundary determination occurs
 *  \param bFragLo  [IN] If true, any address less than frag_addr will be
 *                       fragmented to 16 bits
 *  \param bFragHi  [IN] If true, any address greater than or equal to fragAddr
 *                       will be fragmented to 16 bits
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 */
extern int32_t CSL_fssCfgHyperBusFragmentation( CSL_FssCfg *pFssCfg, uint32_t fragAddr, bool bFragLo, bool bFragHi );

/**
 *  \brief Configure a memory region for ECC protection
 *
 *  This function configures the specified interface's memory region for ECC
 *  protection. Up to 4 ECC protected memory regions can be configured.
 *
 *  This function will automatically truncate the regionAddrStart parameter
 *  to the required 4Kbyte aligned boundary.
 *
 *  This function will automatically round up the regionSizeBytes value to the
 *  required multiple of 4Kbytes size. Specifying a regionSizeBytes of 0 will
 *  disable the region from ECC protection.
 *
 *  An CSL_EINVALID_PARAMS error is returned if the truncated regionAddrStart
 *  + rounded-up regionSizeBytes is > 4Gbytes, as wrap-around addressing is not supported.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param regionNum       [IN] Region number (0..(CSL_FSS_MAX_ECC_PROTECTED_MEMORY_REGIONS-1))
 *  \param regionAddrStart [IN] The starting byte address of the ECC protected memory region
 *  \param regionSizeBytes [IN] The size in bytes of the ECC protected memory region
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EINVALID_PARAMS regionAddrStart + regionSizeBytes is > 4Gbytes
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or regionNum arguments are out-of-range
 */
extern int32_t CSL_fssCfgEccRegion( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t regionNum, uint32_t regionAddrStart, uint32_t regionSizeBytes );

/**
 *  \brief Enable or disable the specified interrupt
 *
 *  This function enables or disables generation of the specified interface's
 *  interrupt.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssInterruptSourceSelect)
 *  \param bEnable         [IN] If true, the interrupt generation is enabled,
 *                              otherwise it is disabled
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssSetIntrEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect, bool bEnable );

/**
 *  \brief Set or clear the specified interrupt pending status
 *
 *  This function is used to set or clear the pending status of the specified
 *  interface's interrupt.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssInterruptSourceSelect)
 *  \param bPend           [IN] If true, the interrupt pending status is set,
 *                              otherwise it is cleared
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssSetIntrPendingStatus( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect, bool bPend );

/**
 *  \brief Determine if the specified masked interrupt is pending
 *
 *  This function returns the pending masked interrupt status of the specified
 *  interface's interrupt. Note that this indication takes into account both
 *  the raw interrupt status and the interrupt enable.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssInterruptSourceSelect)
 *
 *  \return 0                   Masked interrupt is not pending
 *          1                   Masked interrupt is pending
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssIsIntrPending( const CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect );

/**
 *  \brief Determine if the specified raw interrupt is pending
 *
 *  This function returns the pending raw interrupt status of the specified
 *  interface's interrupt. Note that this indication takes into account only
 *  the raw interrupt status and not the interrupt enable.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssInterruptSourceSelect)
 *
 *  \return 0                   Raw interrupt is not pending
 *          1                   Raw interrupt is pending
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssIsRawIntrPending( const CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect );

/**
 *  \brief Acknowledge completion of an ouput interrupt
 *
 *  This function is used to acknowledge completion of the specified
 *  interface's output interrupt. Another output interrupt will be triggered
 *  if enabled and one or more of the output interrupt's sources remain
 *  active.
 *
 *  \param pFssCfg          [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect         [IN] Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param outIntrSelect    [IN] Output interrupt selector (\ref CSL_FssOutputInterruptSelect)
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EOUT_OF_RANGE   The ifSelect and/or outIntrSelect arguments are out-of-range
 */
extern int32_t CSL_fssAckIntr( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t outIntrSelect );

/**
 *  \brief Get information about an ECC block error
 *
 *  This function returns information about an ECC block error (if such an
 *  error exists) on the specified interface.
 *
 *  If error information exists, this function will automatically pop this
 *  error information off the top of the error stack in preparation for the
 *  next error.
 *
 *  \param pFssCfg          [IN]  Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect         [IN]  Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param pEccErrorInfo    [OUT] Pointer to a \ref CSL_FssEccBlockErrorInfo structure
 *
 *  \return CSL_PASS            The function completed successfully and error
 *                              information is returned in the CSL_FssEccBlockErrorInfo structure
 *          CSL_EBADARGS        pFssCfg and/or pEccErrorInfo are NULL
 *          CSL_EFAIL           No error information was available. The CSL_FssEccBlockErrorInfo
 *                              structure is not updated.
 *          CSL_EOUT_OF_RANGE   The ifSelect argument is out-of-range
 */
extern int32_t CSL_fssGetEccBlockErrorInfo( CSL_FssCfg *pFssCfg, uint32_t ifSelect, CSL_FssEccBlockErrorInfo *pEccErrorInfo );

/**
 *  \brief Get information about a write error
 *
 *  This function returns information about a write error (if such an
 *  error exists) on the specified interface.
 *
 *  If error information exists, this function will automatically pop this
 *  error information off the top of the error stack in preparation for the
 *  next error.
 *
 *  \param pFssCfg         [IN]  Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN]  Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param pWrErrorInfo    [OUT] Pointer to a \ref CSL_FssWrErrorInfo structure
 *
 *  \return CSL_PASS            The function completed successfully and error
 *                              information is returned in the CSL_FssWrErrorInfo structure
 *          CSL_EBADARGS        pFssCfg and/or pWrErrorInfo are NULL
 *          CSL_EFAIL           No error information was available. The CSL_FssWrErrorInfo
 *                              structure is not updated.
 *          CSL_EOUT_OF_RANGE   The ifSelect argument is out-of-range
 */
extern int32_t CSL_fssGetWrErrorInfo( CSL_FssCfg *pFssCfg, uint32_t ifSelect, CSL_FssWrErrorInfo *pWrErrorInfo );

/**
 *  \brief Enable or disable OSPI XIP prefetching
 *
 *  This function enables or disables OSPI execute-in-place (XIP) prefetching.
 *
 *  \param pFssCfg         [IN]  Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN]  Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param bEnable         [IN]  If true, XIP prefetching is enabled. If false,
 *                               it is disabled.
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EFAIL           This feature is not available in this version of the FSS
 *          CSL_EOUT_OF_RANGE   The ifSelect argument is out-of-range
 */
extern int32_t CSL_fssOspiSetXipPrefetchEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEnable );

/**
 *  \brief Enable or disable OSPI DDR mode
 *
 *  This function enables or disables OSPI DDR mode.
 *  
 *  When OSPI DDR mode is enabled, all OSPI read requests are turned into 2-
 *  byte aligned, even length, requests due to the OSPI limitation on DDR mode.
 *  In other words, the fss makes the OSPI address and length even and
 *  inclusive of the requested bytes.
 *
 *  When OSPI DDR mode is disabled, all OSPI read requests are passed through
 *  unchanged.
 *
 *  \param pFssCfg         [IN]  Pointer to the \ref CSL_FssCfg configuration structure
 *  \param ifSelect        [IN]  Interface selector (\ref CSL_FssInterfaceSelect)
 *  \param bEnable         [IN]  If true, OSPI DDR mode is enabled. If false,
 *                               it is disabled.
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg is NULL
 *          CSL_EFAIL           This feature is not available in this version of the FSS
 *          CSL_EOUT_OF_RANGE   The ifSelect argument is out-of-range
 */
extern int32_t CSL_fssOspiSetDdrModeEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEnable );

/**
 *  \brief Return revision of the FSS OTFA module
 *
 *  This function returns the contents of the FSS OTFA revision register.
 *  Consult the OTFA module documentation for a description of the
 *  contents of the revision register.
 *
 *  \param pFssCfg  [IN]    Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pRev     [OUT]   Pointer to uint32_t where revision is returned
 *
 *  \return CSL_PASS        The function completed successfully
 *          CSL_EBADARGS    pFssCfg and/or pRev are NULL
 */
extern int32_t CSL_fssOtfaGetRevision( const CSL_FssCfg *pFssCfg, uint32_t *pRev );

/**
 *  \brief Determine if the encryption/authentication function is enabled
 *
 *  This function returns a boolean true or false indicating if the
 *  encryption/authentication function is hardware enabled (via EFUSE) for the
 *  interface to OSPI0 or HYPERBUS.
 *
 *  \param pFssCfg  [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *
 *  \return 0   the encryption/authentication function is hardware disabled
 *          1   the encryption/authentication function is hardware enabled
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaIsCryptoAvailable( const CSL_FssCfg *pFssCfg );

/**
 *  \brief Determine if the OTFA is busy
 *
 *  This function returns a status indicating if the OTFA is busy (one or more
 *  crypto or non-crypto transactions are active) or not busy (no crypto or
 *  non-crypto transactions are active).
 *
 *  Software needs to read 2 consecutive falses with at least 100ns delay
 *  between samples to insure the pipe is fully empty.
 *
 *  \param pFssCfg  [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *
 *  \return 0   the OTFA is not busy
 *          1   the OTFA is busy
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaIsBusy( const CSL_FssCfg *pFssCfg );

/**
 *  \brief Determine if the OTFA crypto engine is busy
 *
 *  This function returns a status indicating if the OTFA crypto engine is busy (one
 *  or more crypto transactions are active) or not busy (no crypto transactions
 *  are active).
 *
 *  Software needs to read 2 consecutive falses with at least 100ns delay
 *  between samples to insure the pipe is fully empty.
 *
 *  \param pFssCfg  [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *
 *  \return 0   the OTFA crypto engine is not busy
 *          1   the OTFA crypto engine is busy
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaIsCryptoBusy( const CSL_FssCfg *pFssCfg );

/**
 *  \brief Read pipe stall event counters
 *
 *  This function returns and clears the current pipe stall event counters.
 *  These counters can be used to fine tune the AES core allocation to the
 *  read and write pipes per the \ref CSL_fssOtfaCfgCrypto function.
 *
 *  \param pFssCfg          [IN]  Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pRdStallEventCnt [OUT] Pointer to uint32_t where the read pipe stall event counter is returned
 *  \param pWrStallEventCnt [OUT] Pointer to uint32_t where the write pipe stall event counter is returned
 *
 *  \return CSL_PASS        The function completed successfully
 *          CSL_EBADARGS    pFssCfg, pFssCfg->pOtfaRegs, pRdStallEventCnt and/or wrStallEventCnt are NULL
 */
extern int32_t CSL_fssOtfaGetPipeStallEventCnts( CSL_FssCfg *pFssCfg, uint32_t *pRdStallEventCnt, uint32_t *pWrStallEventCnt );

/**
 *  \brief Configure the OTFA crypto engine
 *
 *  This function is used to configure the OTFA crypto engine. It must be
 *  called before enabling the crypto engine via the \ref CSL_fssOtfaSetCryptoEnable
 *  function.
 *
 *  \param pFssCfg    [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pCryptoCfg [IN] Pointer to a \ref CSL_FssOtfaCryptoCfg structure containing configuration parameters
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg, pFssCfg->pOtfaRegs, and/or pCryptoCfg are NULL
 *          CSL_EFAIL           The function was called while the crypto engine is enabled
 *          CSL_EINVALID_PARAMS One or more parameters in the \ref CSL_FssOtfaCryptoCfg structure are illegal
 */
extern int32_t CSL_fssOtfaCfgCrypto( CSL_FssCfg *pFssCfg, const CSL_FssOtfaCryptoCfg *pCryptoCfg );

/**
 *  \brief Configure a crypto memory region
 *
 *  This function configures the specified memory region for crypto
 *  protection. Up to 4 protected memory regions can be configured.
 *
 *  An CSL_EFAIL error is returned if this function is called while OTFA
 *  transactions are active. Call the \ref CSL_fssOtfaIsBusy until it returns
 *  false before calling this function.
 *
 *  This function will automatically truncate the pRegionCfg->regionAddrStart
 *  and pRegionCfg->macSignaturesBaseAddr parameters to the required 4Kbyte
 *  aligned boundary.
 *
 *  This function will automatically round up the pRegionCfg->regionSizeBytes
 *  value to the required multiple of 4Kbytes size. Specifying a regionSizeBytes
 *  of 0 will disable the region from crypto protection.
 *
 *  An CSL_EINVALID_PARAMS error is returned under the following conditions:
 *  a) if the truncated regionAddrStart + rounded-up regionSizeBytes is
 *     > 4Gbytes, as wrap-around addressing is not supported.
 *  b) If the truncated macSignaturesBaseAddr + ((rounded-up regionSizeBytes)/8)
 *     > 4Gbytes, as wrap-around addressing is not supported.
 *  c) If the specified pRegionCfg->macMode and pRegionCfg->encMode result in
 *     an invalid combination per the table below:
 *
 *                          +------------------------------+
 *                          |           encMode            |
 *                          +----------+---------+---------+
 *                          | DISABLED | AES_CTR | AES_ECB |
 *     +---------+----------+----------+---------+---------+
 *     |         | DISABLED |    OK    |    OK   |    OK   |
 *     |         +----------+----------+---------+---------+
 *     | macMode | GMAC     |    OK    |    OK   | INVALID |
 *     |         +----------+----------+---------+---------+
 *     |         | CBC-MAC  | INVALID  |    OK   | INVALID |
 *     +---------+----------+----------+---------+---------+
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param regionNum       [IN] Region number (0..(CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS-1))
 *  \param pRegionCfg      [IN] Pointer to a \ref CSL_FssOtfaCryptoRegionCfg structure containing configuration parameters
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg, pFssCfg->pOtfaRegs, and/or pRegionCfg are NULL
 *          CSL_EFAIL           The function was called before \ref CSL_fssOtfaCfgCrypto or while the crypto engine was busy
 *          CSL_EINVALID_PARAMS One or more parameters in the \ref CSL_FssOtfaCryptoRegionCfg structure are illegal
 *          CSL_EOUT_OF_RANGE   The regionNum argument is out-of-range
 */
extern int32_t CSL_fssOtfaCfgCryptoRegion( CSL_FssCfg *pFssCfg, uint32_t regionNum, const CSL_FssOtfaCryptoRegionCfg *pRegionCfg );

/**
 *  \brief Enable or disable the OTFA crypto functionality
 *
 *  This function enables or disables the OTFA crypto functionality.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param bEnable         [IN] If true, the OTFA crypto functionslity is enabled,
 *                              otherwise it is disabled (bypassed)
 *
 *  \return CSL_PASS        The function completed successfully
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaSetCryptoEnable( CSL_FssCfg *pFssCfg, bool bEnable );

/**
 *  \brief Pause or resume the OTFA crypto functionality
 *
 *  This function pauses or resumes the OTFA crypto functionality. The crypto
 *  functionality must be paused before software can safely change the OTFA
 *  configuration.
 *
 *  \param pFssCfg  [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param bPause   [IN] If true, the OTFA crypto functionality is paused,
 *                       otherwise it is resumed
 *
 *  \return CSL_PASS        The function completed successfully
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaSetCryptoPause( CSL_FssCfg *pFssCfg, bool bPause );

/**
 *  \brief Determine if the OTFA crypto functionality is enabled
 *
 *  This function returns a status indicating if the OTFA crypto
 *  functionality is enabled or disabled.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *
 *  \return 0   the OTFA crypto functionality is disabled (bypass mode is active)
 *          1   the OTFA crypto functionality is enabled
 *          CSL_EBADARGS    pFssCfg is NULL
 */
extern int32_t CSL_fssOtfaIsCryptoEnabled( const CSL_FssCfg *pFssCfg );

/**
 *  \brief Enable or disable the specified OTFA interrupt
 *
 *  This function enables or disables generation of the specified OTFA region's
 *  interrupt.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param regionSelect    [IN] Region selector (0..(CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS-1))
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssOtfaInterruptSourceSelect)
 *  \param bEnable         [IN] If true, the interrupt generation is enabled,
 *                              otherwise it is disabled
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg and/or pFssCfg->pOtfaRegs are NULL
 *          CSL_EOUT_OF_RANGE   The regionSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssOtfaSetIntrEnable( CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect, bool bEnable );

/**
 *  \brief Set or clear the specified OTFA interrupt pending status
 *
 *  This function is used to set or clear the pending status of the specified
 *  OTFA region's  interrupt.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param regionSelect    [IN] Region selector (0..(CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS-1))
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssOtfaInterruptSourceSelect)
 *  \param bPend           [IN] If true, the interrupt pending status is set,
 *                              otherwise it is cleared
 *
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg and/or pFssCfg->pOtfaRegs are NULL
 *          CSL_EOUT_OF_RANGE   The regionSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssOtfaSetIntrPendingStatus( CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect, bool bPend );

/**
 *  \brief Determine if the specified OTFA masked interrupt is pending
 *
 *  This function returns the pending masked interrupt status of the specified
 *  OTFA region's interrupt. Note that this indication takes into account both
 *  the raw interrupt status and the interrupt enable.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param regionSelect    [IN] Region selector (0..(CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS-1))
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssOtfaInterruptSourceSelect)
 *
 *  \return 0                   Masked interrupt is not pending
 *          1                   Masked interrupt is pending
 *          CSL_EBADARGS        pFssCfg and/or pFssCfg->pOtfaRegs are NULL
 *          CSL_EOUT_OF_RANGE   The regionSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssOtfaIsIntrPending( const CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect );

/**
 *  \brief Determine if the specified OTFA raw interrupt is pending
 *
 *  This function returns the pending raw interrupt status of the specified
 *  OTFA region's interrupt. Note that this indication takes into account only
 *  the raw interrupt status and not the interrupt enable.
 *
 *  \param pFssCfg         [IN] Pointer to the \ref CSL_FssCfg configuration structure
 *  \param regionSelect    [IN] Region selector (0..(CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS-1))
 *  \param intrSelect      [IN] Interrupt selector (\ref CSL_FssOtfaInterruptSourceSelect)
 *
 *  \return 0                   Raw interrupt is not pending
 *          1                   Raw interrupt is pending
 *          CSL_EBADARGS        pFssCfg and/or pFssCfg->pOtfaRegs are NULL
 *          CSL_EOUT_OF_RANGE   The regionSelect and/or intrSelect arguments are out-of-range
 */
extern int32_t CSL_fssOtfaIsRawIntrPending( const CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect );

/**
 *  \brief Get additional OTFA IRQ information
 *
 *  This function returns additional OTFA IRQ information following an IRQ event.
 *
 *  \param pFssCfg      [IN]    Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pIrqInfo     [OUT]   Pointer to a \ref CSL_FssOtfaIrqInfo structure
 *                              where the IRQ information is returned
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg and/or pIrqInfo are NULL
 */
extern int32_t CSL_fssOtfaGetIrqInfo( const CSL_FssCfg *pFssCfg, CSL_FssOtfaIrqInfo *pIrqInfo );

/**
 *  \brief Get OTFA statistics
 *
 *  This function returns OTFA statistic counts. The hardware statistic
 *  counters are automatically cleared by this function.
 *
 *  \param pFssCfg      [IN]    Pointer to the \ref CSL_FssCfg configuration structure
 *  \param pStats       [OUT]   Pointer to a \ref CSL_FssOtfaStats structure
 *                              where the statistic counters are returned
 *  \return CSL_PASS            The function completed successfully
 *          CSL_EBADARGS        pFssCfg and/or pStats are NULL
 */
extern int32_t CSL_fssOtfaGetStats( CSL_FssCfg *pFssCfg, CSL_FssOtfaStats *pStats );

/** @} */

#ifdef __cplusplus
}
#endif

#endif
