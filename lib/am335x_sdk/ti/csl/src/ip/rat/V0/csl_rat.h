/**
 * @file  V0/csl_rat.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the KSBUS RAT Ip.
 *      =
 *  @n   (C) Copyright 2016-2019, Texas Instruments, Inc.
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
#ifndef CSL_RAT_H_
#define CSL_RAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_rat.h>

/**     
 *
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the Region-based Address Translation
 *  (RAT) module.
 *
 * @subsection References
 *    - ksbus_rat Module Specification, version 1.0.8
 *
 *     
 */
/**
@defgroup CSL_RAT_DATASTRUCT  RAT Data Structures
@ingroup CSL_RAT_API
*/
/**
@defgroup CSL_RAT_FUNCTION  RAT Functions
@ingroup CSL_RAT_API
*/
/**
@defgroup CSL_RAT_ENUM RAT Enumerated Data Types
@ingroup CSL_RAT_API
*/

/**     
 *  @addtogroup CSL_RAT_ENUM
    @{
 * 
 */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the types of possible RAT interrupt sources
 *
 *  \anchor CSL_RatIntrSrcTypes
 *  \name RAT interrupt source types
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_RatIntrSrcTypes;
    /** Exception interrupt */
#define CSL_RAT_INTR_SRC_EXCEPTION  ((uint32_t) 0U)
    /** Denotes an invalid error type */
#define CSL_RAT_INTR_SRC_INVALID    ((uint32_t) 1U)
/* @} */

/** @} */

/**     
 *  @addtogroup CSL_RAT_DATASTRUCT
    @{
 * 
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains exception status information returned by the
 *          CSL_ratGetExceptionInfo function.
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** Identifies the exception type (for the RAT, this field should equal 4) */
    uint32_t    type;
    /** Address */
    uint64_t    address;
    /** Group */
    uint32_t    group;
    /** Code */
    uint32_t    code;
    /** Source ID */
    uint32_t    srcId;
    /** Destination ID */
    uint32_t    destId;
    /** Route ID */
    uint32_t    routeId;
    /** Priv ID */
    uint32_t    privId;
    /** Byte Count */
    uint32_t    byteCnt;
    /** Write */
    bool        bWrite;
    /** Read */
    bool        bRead;
    /** Debug */
    bool        bDebug;
    /** Cacheable */
    bool        bCacheable;
    /** Priv */
    bool        bPriv;
    /** Secure */
    bool        bSecure;
} CSL_RatExceptionInfo;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains information required to configure an
 *          address translation region.
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** The size of the region (in bytes). If this value is not a power-of-2, it is automatically rounded-up to the next power-of-2 size. */
    uint64_t    sizeInBytes;
    /** The 32-bit base address used in the address comparison */
    uint32_t    baseAddress;
    /** The translated address returned on a successful match */
    uint64_t    translatedAddress;
} CSL_RatTranslationCfgInfo;

/** @} */

/**     
 *  @addtogroup CSL_RAT_FUNCTION
    @{
 * 
 */

/**    
 *   @n@b CSL_ratGetRevision
 *
 *   @b Description
 *   @n This function returns the revision information for the RAT
 *
 *   @b Arguments
 *   @n  pRatRegs - A pointer (of type CSL_ratRegs*) to the base
 *                  address of the RAT module
 *
 *   <b> Return Value </b>
 *   @n  Revision information. See design specification for details.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n PID
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t    rev;

       rev = CSL_ratGetRevision(pRatRegs);
    @endverbatim
 * 
 */
uint32_t CSL_ratGetRevision(const CSL_ratRegs *pRatRegs);

/**     
 *   @n@b CSL_ratGetMaxRegions
 *
 *   @b Description
 *   @n This function returns the maximum number of regions that can be configured.
 *
 *   @b Arguments
 *   @n  pRatRegs - A pointer (of type CSL_ratRegs*) to the base
 *                  address of the RAT module
 *
 *   <b> Return Value </b>
 *   @n  The the maximum number of regions that can be configured in this RAT
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n None
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t    maxRegions;

       maxRegions = CSL_ratGetMaxRegions(pRatRegs);
    @endverbatim
 * 
 */
uint32_t CSL_ratGetMaxRegions(const CSL_ratRegs *pRatRegs);

/**     
 *   @n@b CSL_ratIsRegionTranslationEnabled
 *
 *   @b Description
 *   @n This function returns the enable status of the specified region address
 *      translation
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  regionIndex    - The index of the region to configure. This value must
 *                        be in the range 0..(CSL_ratGetMaxRegions()-1) inclusive.
 *
 *   <b> Return Value </b>
 *   @n  true           - The specified region address translation is enabled
 *   @n  false          - The specified region address translation is not enabled
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CSL_RAT_CTRL
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t    regionIndex = 0;
       bool        bIsEnabled;

       bIsEnabled = CSL_ratIsRegionTranslationEnabled(pRatRegs,regionIndex);
       printf("Address translation for region %u is %s\n", regionIndex, bIsEnabled ? "enabled" : "not enabled" );
    @endverbatim
 * 
 */
bool CSL_ratIsRegionTranslationEnabled(const CSL_ratRegs *pRatRegs, uint32_t regionIndex);

/**     
 *   @n@b CSL_ratSetErrMsgDestId
 *
 *   @b Description
 *   @n This function is used to set the destination ID for error messages.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  destId     - The destination ID for future error messages
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n DESTINATION_ID
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs   *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t      destId = 0;

       CSL_ratSetErrMsgDestId(pRatRegs, destId);
    @endverbatim
 *   @n  CSL_PASS   - Set destination ID for error messages is successful
 *   @n  CS:_EFAIL  - An error occurred. Either 1) base address pointer is NULL,
 *                    2) destination ID value is invalid.
 * 
 */
int32_t CSL_ratSetErrMsgDestId(CSL_ratRegs *pRatRegs, uint32_t destId);

/**     
 *   @n@b CSL_ratGetErrMsgDestId
 *
 *   @b Description
 *   @n This function is used to read the destination ID for error messages.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  pDestId    - A pointer to hold the destination ID register value
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS   - Get destination ID for error messages is successful.
 *   @n  CS:_EFAIL  - An error occurred. Either 1) base address pointer is NULL,
 *                    2) destination ID pointer is NULL.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b reads
 *   @n DESTINATION_ID
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs   *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t      destId;

       CSL_ratGetErrMsgDestId(pRatRegs, &destId);
     @endverbatim
 * 
 */
int32_t CSL_ratGetErrMsgDestId(const CSL_ratRegs *pRatRegs, uint32_t *pDestId);
 
/**     
 *   @n@b CSL_ratEnableExceptionLogging
 *
 *   @b Description
 *   @n This function enables the exception logging capability. It also enables
 *      exception interrupt generation. The module's exception interrupt signal
 *      is asserted if the exception logging capability is enabled and the
 *      exception interrupt source is enabled by calling the
 *      \ref CSL_ratEnableIntr function.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_LOGGING_CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratEnableExceptionLogging(pRatRegs);
    @endverbatim
 *   @n  CSL_PASS   - Enable the exception logging capability is successful.
 *   @n  CS:_EFAIL  - An error occurred, base address pointer is NULL.
 * 
 */
int32_t CSL_ratEnableExceptionLogging(CSL_ratRegs *pRatRegs);

/**     
 *   @n@b CSL_ratDisableExceptionLogging
 *
 *   @b Description
 *   @n This function disables the exception logging capability. It also
 *      disables the module's exception interrupt signal generation, regardless
 *      of whether the exception interrupt source is enabled or disabled.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS   - Disable the exception logging capability is successful.
 *   @n  CS:_EFAIL  - An error occurred, base address pointer is NULL.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_LOGGING_CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratDisableExceptionLogging(pRatRegs);
    @endverbatim
 * 
 */
int32_t CSL_ratDisableExceptionLogging(CSL_ratRegs *pRatRegs);


/**     
 *   @n@b CSL_ratIsExceptionLoggingEnabled
 *
 *   @b Description
 *   @n This function is used to determine if the exception logging capability
 *      is enabled or disabled.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *
 *   <b> Return Value </b>
 *   @n  Returns true if exception logging is enabled otherwise false
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_LOGGING_CONTROL
 *
 *   @b Example
 *   @verbatim
	   CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
	   uint32_t        status;
	   status = CSL_ratIsExceptionLoggingEnabled(pRatRegs);
	@endverbatim
 * 
 */
uint32_t CSL_ratIsExceptionLoggingEnabled(const CSL_ratRegs *pRatRegs);

/**     
 *   @n@b CSL_ratIsIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status of the specified
 *      interrupt source.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - An interrupt of the specified source is pending
 *   @n  false      - An interrupt of the specified source is not pending
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n EXCEPTION_PEND_SET
 *
 *   @b Example
 *   @verbatim
 *      CSL_ratRegs   *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
 *      bool                    bIntPending;
 *
 *      bIntPending = CSL_ratIsIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
 *      printf("Exception interrupt is %s\n", bIntPending ? "pending" : "not pending" );
 *   @endverbatim
 * 
 */
bool CSL_ratIsIntrPending(const CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratSetIntrPending
 *
 *   @b Description
 *   @n This function is used to forceably set the pending status of the
 *      specified interrupt source.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - Success
 *   @n  false      - The specified interrupt source is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_PEND_SET
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratSetIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * 
 */
bool CSL_ratSetIntrPending(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratClrIntrPending
 *
 *   @b Description
 *   @n This function is used to clear the pending status of the
 *      specified interrupt source.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - Success
 *   @n  false      - The specified interrupt source is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_PEND_CLEAR
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratClrIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * 
 */
bool CSL_ratClrIntrPending(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratAckIntr
 *
 *   @b Description
 *   @n This function is used to acknowledge the specified interrupt source.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - Success
 *   @n  false      - The specified interrupt source is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EOI_REG
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratAckIntr(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * 
 */
bool CSL_ratAckIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratEnableIntr
 *
 *   @b Description
 *   @n This function enables the specified interrupt source. It also calls
 *      \ref CSL_ratEnableExceptionLogging to enable exception logging as there
 *      is no valid reason to enable the exception interrupt source and not log
 *      the exception information and assert the module's exception interrupt
 *      signal. 
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - Success
 *   @n  false      - The specified interrupt source is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_ENABLE_SET
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratEnableIntr(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * 
 */
bool CSL_ratEnableIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratDisableIntr
 *
 *   @b Description
 *   @n This function disables the specified interrupt source. This prevents
 *      the module's exception interrupt signal from being asserted. Note that
 *      software can still call \ref CSL_ratIsIntrPending to poll for an
 *      exception event and call \ref CSL_ratGetExceptionInfo to read exception
 *      event information if exception logging is enabled.
 *
 *   @b Arguments
 *   @n  pRatRegs   - A pointer (of type CSL_ratRegs*) to the base
 *                    address of the RAT module
 *   @n  intrSrc    - The interrupt source of type \ref CSL_RatIntrSrcTypes
 *
 *   <b> Return Value </b>
 *   @n  true       - Success
 *   @n  false      - The specified interrupt source is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_ENABLE_CLEAR
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;

       CSL_ratDisableIntr(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * 
 */
bool CSL_ratDisableIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc);

/**     
 *   @n@b CSL_ratGetExceptionInfo
 *
 *   @b Description
 *   @n This function is used to get information for the last boundary crossing
 *      transaction exception captured. The log is automatically cleared by this
 *      function so that a future exception can be captured.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  pExceptionInfo - A pointer to a CSL_RatExceptionInfo structure containing
 *                        returned exception information
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n EXCEPTION_LOGGING_HEADER0, EXCEPTION_LOGGING_HEADER1, EXCEPTION_LOGGING_DATA0, EXCEPTION_LOGGING_DATA1, EXCEPTION_LOGGING_DATA2, EXCEPTION_LOGGING_DATA3
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs   *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       CSL_RatExceptionInfo     ExceptionInfo;

       CSL_ratGetExceptionInfo(pRatRegs, &ExceptionInfo);
    @endverbatim
 * 
 */
bool CSL_ratGetExceptionInfo(CSL_ratRegs *pRatRegs, CSL_RatExceptionInfo *pExceptionInfo);

/**     
 *   @n@b CSL_ratEnableRegionTranslation
 *
 *   @b Description
 *   @n This function enables address translation for the specified region.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  regionIndex    - The index of the region to configure. This value must
 *                        be in the range 0..(CSL_ratGetMaxRegions()-1) inclusive.
 *
 *   <b> Return Value </b>
 *   @n  true       - The function completed successfully
 *   @n  false      - An error occurred. Either 1) the regionIndex was out of range,
 *                    or if enabling, 2) the region base address and translated base
 *                    address are not aligned to the region size, or 3) this region
 *                    overlaps another enabled region's address range.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RAT_CTRL
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t    regionIndex = CSL_ratGetMaxRegions(pRatRegs) - 1;

       CSL_ratEnableRegionTranslation(pRatRegs, regionIndex);
    @endverbatim
 * 
 */
bool CSL_ratEnableRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex);

/**     
 *   @n@b CSL_ratDisableRegionTranslation
 *
 *   @b Description
 *   @n This function disables address translation for the specified region.
 *
 *   @b Arguments
 *   @n  pRatRegs       - A pointer (of type CSL_ratRegs*) to the base
 *                        address of the RAT module
 *   @n  regionIndex    - The index of the region to configure. This value must
 *                        be in the range 0..(CSL_ratGetMaxRegions()-1) inclusive.
 *
 *   <b> Return Value </b>
 *   @n  true       - The function completed successfully
 *   @n  false      - An error occurred. Either 1) the regionIndex was out of range,
 *                    or if enabling, 2) the region base address and translated base
 *                    address are not aligned to the region size, or 3) this region
 *                    overlaps another enabled region's address range.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RAT_CTRL
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs    *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       uint32_t       regionIndex = CSL_ratGetMaxRegions(pRatRegs) - 1;

       CSL_ratDisableRegionTranslation(pRatRegs, regionIndex);
    @endverbatim
 * 
 */
bool CSL_ratDisableRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex);

/**     
 *   @n@b CSL_ratConfigRegionTranslation
 *
 *   @b Description
 *   @n This function is used to configure a region address translation for the
 *      specified region index. The translation is automatically enabled after
 *      it is configured.
 *
 *   @b Arguments
 *   @n  pRatRegs           - A pointer (of type CSL_ratRegs*) to the base
 *                            address of the RAT module
 *   @n  regionIndex        - The index of the region to configure. This value must
 *                            be in the range 0..(CSL_ratGetMaxRegions()-1) inclusive.
 *   @n  pTranslationCfg    - A pointer of type CSL_RatTranslationCfgInfo containing
 *                            configuration information
 *
 *   <b> Return Value </b>
 *   @n  true       - The region address translation was configured properly
 *   @n  false      - An error occurred. Either 1) the regionIndex was out of range,
 *                    2) the region base address and translated base address are not
 *                    aligned to the region size, or 3) this region overlaps another
 *                    enabled region's address range.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RAT_CTRL, CSL_RAT_BASE, CSL_RAT_LOWER, CSL_RAT_UPPER
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs       *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       CSL_RatTranslationCfgInfo   TranslationCfg =
       {
           0x00010000,     // sizeInBytes
           0x00020000,     // baseAddress
           0x01000000      // translatedAddress
       };

       CSL_ratConfigRegionTranslation(pRatRegs, 0, &TranslationCfg);
    @endverbatim
 * 
 */
bool CSL_ratConfigRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg);

/**     
 *   @n@b CSL_ratVerifyConfigRegionTranslation
 *
 *   @b Description
 *   @n This function is used to check configure a region address translation for the
 *      specified region index. The translation is checked for enable after
 *      it is configured.
 *
 *   @b Arguments
 *   @n  pRatRegs           - A pointer (of type CSL_ratRegs*) to the base
 *                            address of the RAT module
 *   @n  regionIndex        - The index of the region to configure. This value must
 *                            be in the range 0..(CSL_ratGetMaxRegions()-1) inclusive.
 *   @n  pTranslationCfg    - A pointer of type CSL_RatTranslationCfgInfo containing
 *                            configuration information
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS       - The region address translation was configured properly
 *   @n  CS:_EFAIL      - An error occurred. Either 1) the regionIndex was out of range,
 *                    2) the region base address and translated base address are not
 *                    aligned to the region size, or 3) this region overlaps another
 *                    enabled region's address range.
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_ratConfigRegionTranslation() API is called to prior for RAT config
 *       and returned true (success)
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CSL_RAT_CTRL, CSL_RAT_BASE, CSL_RAT_LOWER, CSL_RAT_UPPER
 *
 *   @b Example
 *   @verbatim
       CSL_ratRegs       *pRatRegs = (CSL_ratRegs *)RAT_BASE_ADDRESS;
       int32_t            status;
       CSL_RatTranslationCfgInfo   TranslationCfg =
       {
           0x00010000,     // sizeInBytes
           0x00020000,     // baseAddress
           0x01000000      // translatedAddress
       };

       status = CSL_ratVerifyConfigRegionTranslation(pRatRegs, 0, &TranslationCfg);
    @endverbatim
 * 
 */
int32_t CSL_ratVerifyConfigRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
