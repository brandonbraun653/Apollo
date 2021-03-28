/**
 * @file  csl_pat.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the PAT IP.
 *  \par
 *  ============================================================================
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
#ifndef CSL_PAT_H_
#define CSL_PAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_pat.h>

/** ===========================================================================
 *
 * @defgroup CSL_PAT_API Page-based Address Translation (PAT)
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the Page-based Address Translation
 *  (PAT) module.
 *
 * @subsection References
 *    - ksbus_pat Module Specification, version 1.0.7
 *
 * ============================================================================
 */
/**
@defgroup CSL_PAT_DATASTRUCT  PAT Data Structures
@ingroup CSL_PAT_API
*/
/**
@defgroup CSL_PAT_FUNCTION  PAT Functions
@ingroup CSL_PAT_API
*/
/**
@defgroup CSL_PAT_ENUM PAT Enumerated Data Types
@ingroup CSL_PAT_API
*/

/** ===========================================================================
 *  @addtogroup CSL_PAT_ENUM
    @{
 * ============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible page sizes (in Kbytes)
 *
 *  \anchor CSL_PatPageSize
 *  \name PAT page size
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PatPageSize;
    /** 4KB page size */
#define CSL_PAT_PAGE_SIZE_4KB   ((uint32_t) 0U)
    /** 16KB page size */
#define CSL_PAT_PAGE_SIZE_16KB  ((uint32_t) 1U)
    /** 64KB page size */
#define CSL_PAT_PAGE_SIZE_64KB  ((uint32_t) 2U)
    /** 1MB page size */
#define CSL_PAT_PAGE_SIZE_1MB   ((uint32_t) 3U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible PAT arbitration modes
 *
 *  \anchor CSL_PatArbitrationMode
 *  \name PAT arbitration mode
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PatArbitrationMode;
    /** Prioritize table updates before lookups */
#define CSL_PAT_ARBITRATION_MODE_UPDATES_FIRST  ((uint32_t) 0U)
    /** Performs round robin (alternating) between table updates and lookups if both are pending */
#define CSL_PAT_ARBITRATION_MODE_ROUND_ROBIN    ((uint32_t) 2U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the types of PAT interrupt sources
 *
 *  \anchor CSL_PatIntrSrc
 *  \name PAT interrupt source
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_PatIntrSrc;
    /** Exception interrupt */
#define CSL_PAT_INTR_SRC_EXCEPTION  ((uint32_t) 0U)
/* @} */

/** @} */

/** ============================================================================
 *  @addtogroup CSL_PAT_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains configuration parameters for the PAT
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** Pointer to the PAT configuration registers */
    CSL_patRegs           *pPatRegs;
    /** Pointer to the PAT table registers */
    CSL_pat_tableRegs     *pPatTableRegs;
    /** Pointer to the PAT scratch ram */
    CSL_pat_scratchRegs   *pPatScratchRam;
} CSL_PatConfigParms;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains exception status information returned by the
 *          CSL_patGetExceptionInfo function.
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** Identifies the exception type (for the PAT, this field should equal 5) */
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
    uint32_t    bWrite;
    /** Read */
    uint32_t    bRead;
    /** Debug */
    uint32_t    bDebug;
    /** Cacheable */
    uint32_t    bCacheable;
    /** Priv */
    uint32_t    bPriv;
    /** Secure */
    uint32_t    bSecure;
} CSL_PatExceptionInfo;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_PAT_FUNCTION
    @{
 * ============================================================================
 */

/** ============================================================================
 *   @n@b CSL_patGetRevision
 *
 *   @b Description
 *   @n This function returns the revision information for the PAT.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t rev;

       rev = CSL_patGetRevision(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_patGetRevision(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patGetMaxPages
 *
 *   @b Description
 *   @n This function returns the maximum number of pages that can be
 *      configured for this PAT.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *
 *   <b> Return Value </b>
 *   @n  The maximum number of pages that can be configured
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t MaxPages;

       MaxPages = CSL_patGetMaxPages(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_patGetMaxPages(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patGetArbitrationMode
 *
 *   @b Description
 *   @n This function returns the arbitration mode currently configured for PAT
 *      translation table updates and look-ups.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *
 *   <b> Return Value </b>
 *   @n  Currently configured arbitration mode of type CSL_PatArbitrationMode
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms            patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t  arbMode;

       arbMode = CSL_patGetArbitrationMode(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_patGetArbitrationMode(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patSetArbitrationMode
 *
 *   @b Description
 *   @n This function configures the arbitration mode for PAT translation table
 *      updates and look-ups.
 *
 *   @b Arguments
 *   @n  pPatCfg            - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                            configuration structure
 *   @n  arbitrationMode    - The desired arbitration mode of type \ref CSL_PatArbitrationMode
 *
 *   <b> Return Value </b>
 *   @n  0                  - Success
 *   @n  -1                 - The specified arbitration mode is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms      patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t arbMode = CSL_PAT_ARBITRATION_MODE_UPDATES_FIRST;

       CSL_patSetArbitrationMode(&patCfg, arbMode );
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patSetArbitrationMode(const CSL_PatConfigParms *pPatCfg, uint32_t arbitrationMode);

/** ============================================================================
 *   @n@b CSL_patGetPageSize
 *
 *   @b Description
 *   @n This function returns the page size currently configured.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *
 *   <b> Return Value </b>
 *   @n  The page size of type \ref CSL_PatPageSize
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms      patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t pageSize;

       pageSize = CSL_patGetPageSize(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_patGetPageSize(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patSetPageSize
 *
 *   @b Description
 *   @n This function configures the page size.
 *
 *   @b Arguments
 *   @n  pPatCfg            - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                            configuration structure
 *   @n  pageSize           - The page size of type \ref CSL_PatPageSize
 *
 *   <b> Return Value </b>
 *   @n  0                  - The specified page size was set successfully
 *   @n  -1                 - The specified page size is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms      patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetPageSize(&patCfg, CSL_PAT_PAGE_SIZE_16KB);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patSetPageSize(const CSL_PatConfigParms *pPatCfg, uint32_t pageSize);

/** ============================================================================
 *   @n@b CSL_patSetReplaceOrderIdEnable
 *
 *   @b Description
 *   @n This function enables or disables the replace orderid feature allowing a
 *      hypervisor or OS to globally disable the feature if applications or VM's
 *      should not be able to modify orderid values. The page based enables are
 *      used if globally enabled and are always ignored if globally disabled.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *   @n  bEnable - If not 0, the replace orderid feature is enabled.
 *                 If 0, it is disabled.
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
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetReplaceOrderIdEnable(&patCfg, true);
       CSL_patSetReplaceOrderIdEnable(&patCfg, false);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patSetReplaceOrderIdEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable);

/** ============================================================================
 *   @n@b CSL_patSetPatEnable
 *
 *   @b Description
 *   @n This function enables or disables the page address translation function.
 *      When enabled, input addresses are translated via page translation table
 *      entries.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *   @n  bEnable - If true, the page address translation function is enabled.
 *                 If false, it is disabled.
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
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetPatEnable(&patCfg, true);
       CSL_patSetPatEnable(&patCfg, false);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patSetPatEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable);

/** ============================================================================
 *   @n@b CSL_patEnablePat
 *
 *   @b Description
 *   @n This function enables the page address translation function.
 *      When enabled, input addresses are translated via page translation table
 *      entries.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
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
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patEnablePat(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patEnablePat(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patDisablePat
 *
 *   @b Description
 *   @n This function disables the page address translation function.
 *      When disabled, the page translation table SRAM can be used as
 *      general scratch memory.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
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
 *   @n CONTROL
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patDisablePat(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patDisablePat(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patSetErrMsgDestId
 *
 *   @b Description
 *   @n This function is used to set the destination ID for error messages.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
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
       CSL_PatConfigParms  patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t       destId = 0;

       CSL_patSetErrMsgDestId(&patCfg, destId);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patSetErrMsgDestId(const CSL_PatConfigParms *pPatCfg, uint32_t destId);

/** ============================================================================
 *   @n@b CSL_patSetExceptionLoggingEnable
 *
 *   @b Description
 *   @n This function enables or disables the exception logging capability.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
 *   @n  bEnable - If true, the exception logging capability is enabled.
 *                 If false, it is disabled.
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetExceptionLoggingEnable(&patCfg, true);
       CSL_patSetExceptionLoggingEnable(&patCfg, false);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patSetExceptionLoggingEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable);

/** ============================================================================
 *   @n@b CSL_patEnableExceptionLogging
 *
 *   @b Description
 *   @n This function enables the exception logging capability. It also enables
 *      exception interrupt generation. The module's exception interrupt signal
 *      is asserted if the exception logging capability is enabled and the
 *      exception interrupt source is enabled by calling the
 *      \ref CSL_patEnableIntr function.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patEnableExceptionLogging(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patEnableExceptionLogging(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patDisableExceptionLogging
 *
 *   @b Description
 *   @n This function disables the exception logging capability. It also
 *      disables the module's exception interrupt signal generation, regardless
 *      of whether the exception interrupt source is enabled or disabled.
 *
 *   @b Arguments
 *   @n  pPatCfg - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                 configuration structure
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patDisableExceptionLogging(&patCfg);
     @endverbatim
 * =============================================================================
 */
extern void CSL_patDisableExceptionLogging(const CSL_PatConfigParms *pPatCfg);

/** ============================================================================
 *   @n@b CSL_patIsIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status of the specified
 *      interrupt source.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  true    - An interrupt of the specified source is pending
 *   @n  false   - An interrupt of the specified source is not pending
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint32_t bIntPending;

       bIntPending = CSL_patIsIntrPending(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
       printf("Exception interrupt is %s\n", bIntPending ? "pending" : "not pending" );
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_patIsIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patSetIntrPending
 *
 *   @b Description
 *   @n This function is used to forceably set the pending status of the
 *      specified interrupt source.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetIntrPending(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patSetIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patClrIntrPending
 *
 *   @b Description
 *   @n This function is used to clear the pending status of the
 *      specified interrupt source.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patClrIntrPending(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patClrIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patAckIntr
 *
 *   @b Description
 *   @n This function is used to acknowledge the specified interrupt source.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patAckExceptionInt(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patAckIntr(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patSetIntrEnable
 *
 *   @b Description
 *   @n This function enables or disables the interrupt for the specified
 *      interrupt source.
 *
 *      If intrSrc == CSL_PAT_INTR_SRC_EXCEPTION and bEnable != 0, then this
 *      function also calls \ref CSL_patEnableExceptionLogging to enable
 *      exception logging as there is no valid reason to enable the exception
 *      interrupt source and not log the exception information and assert the
 *      module's exception interrupt signal. 
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *   @n  bEnable    - If true, the interrupt for the specified interrupt source
 *                    is enabled. If false, it is disabled.
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patSetIntrEnable(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION, true);
       CSL_patSetIntrEnable(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION, false);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patSetIntrEnable(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc, uint32_t bEnable);

/** ============================================================================
 *   @n@b CSL_patEnableIntr
 *
 *   @b Description
 *   @n This function enables the specified interrupt source.
 *
 *      If intrSrc == CSL_PAT_INTR_SRC_EXCEPTION, then this function also calls
 *      \ref CSL_patEnableExceptionLogging to enable exception logging as there
 *      is no valid reason to enable the exception interrupt source and not log
 *      the exception information and assert the module's exception interrupt
 *      signal. 
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patEnableIntr(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
       CSL_patDisableIntr(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patEnableIntr(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patDisableIntr
 *
 *   @b Description
 *   @n This function disables the specified interrupt source. This prevents
 *      the module's exception interrupt signal from being asserted. Note that
 *      software can still call \ref CSL_patIsIntrPending to poll for an
 *      exception event and call \ref CSL_patGetExceptionInfo to read exception
 *      event information if exception logging is enabled.
 *
 *   @b Arguments
 *   @n  pPatCfg    - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                    configuration structure
 *   @n  intrSrc    - The interrupt source of type \ref CSL_PatIntrSrc
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - The specified interrupt source is invalid
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
       CSL_PatConfigParms patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };

       CSL_patDisableIntr(&patCfg, CSL_PAT_INTR_SRC_EXCEPTION);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patDisableIntr( const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc);

/** ============================================================================
 *   @n@b CSL_patGetExceptionInfo
 *
 *   @b Description
 *   @n This function is used to get information for the last boundary crossing
 *      transaction exception captured. The log is automatically cleared by this
 *      function so that a future exception can be captured.
 *
 *   @b Arguments
 *   @n  pPatCfg        - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                        configuration structure
 *   @n  pExceptionInfo - A pointer to a CSL_PatExceptionInfo structure containing
 *                        returned exception information
 *
 *   <b> Return Value </b>
 *   @n  0          - Success
 *   @n  -1         - Automatic clearing of the log failed
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
       CSL_PatConfigParms    patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       CSL_PatExceptionInfo ExceptionInfo;

       CSL_patGetExceptionInfo(&patCfg, &ExceptionInfo);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patGetExceptionInfo(const CSL_PatConfigParms *pPatCfg, CSL_PatExceptionInfo *pExceptionInfo);

/** ============================================================================
 *   @n@b CSL_patSetPageTranslationEnable
 *
 *   @b Description
 *   @n This function enables or disables page address translation for the
 *      page corresponding to the specified input address.
 *
 *   @b Arguments
 *   @n  pPatCfg        - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                        configuration structure
 *   @n  inputAddress   - The input address
 *   @n  bEnable        - If true, the page address translation for the page
 *                        corresponding to the specified input address is
 *                        enabled. If false, it is disabled.
 *
 *   <b> Return Value </b>
 *   @n  0              - The page was enabled properly
 *   @n  -1             - An error occurred. The specified input address
 *                        exceeded the page table size.
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_patSetPageSize
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n BASE_REG_H
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms    patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint64_t            inputAddress = 0x00001000UL;

       CSL_patSetPageSize(&patCfg, CSL_PAT_PAGE_SIZE_4KB);
       CSL_patSetPageTranslationEnable(&patCfg, inputAddress, true);
       CSL_patSetPageTranslationEnable(&patCfg, inputAddress, false);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patSetPageTranslationEnable(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress, uint32_t bEnable);

/** ============================================================================
 *   @n@b CSL_patEnablePageTranslation
 *
 *   @b Description
 *   @n This function enables page address translation for the
 *      page corresponding to the specified input address.
 *
 *   @b Arguments
 *   @n  pPatCfg        - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                        configuration structure
 *   @n  inputAddress   - The input address
 *
 *   <b> Return Value </b>
 *   @n  0              - The page was enabled properly
 *   @n  -1             - An error occurred. The specified input address
 *                        exceeded the page table size.
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_patSetPageSize
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n BASE_REG_H
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms    patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint64_t            inputAddress = 0x00001000UL;

       CSL_patSetPageSize(&patCfg, CSL_PAT_PAGE_SIZE_4KB);
       CSL_patEnablePageTranslation(&patCfg, inputAddress);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patEnablePageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress);

/** ============================================================================
 *   @n@b CSL_patDisablePageTranslation
 *
 *   @b Description
 *   @n This function disables page address translation for the
 *      page corresponding to the specified input address.
 *
 *   @b Arguments
 *   @n  pPatCfg        - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                        configuration structure
 *   @n  inputAddress   - The input address
 *
 *   <b> Return Value </b>
 *   @n  0              - The page was enabled properly
 *   @n  -1             - An error occurred. The specified input address
 *                        exceeded the page table size.
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_patSetPageSize
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n BASE_REG_H
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms    patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint64_t            inputAddress = 0x00001000UL;

       CSL_patSetPageSize(&patCfg, CSL_PAT_PAGE_SIZE_4KB);
       CSL_patDisablePageTranslation(&patCfg, inputAddress);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patDisablePageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress);

/** ============================================================================
 *   @n@b CSL_patConfigPageTranslation
 *
 *   @b Description
 *   @n This function is used to configure a page address translation for the
 *      specified input address using the specified translation address. The
 *      translation is automatically enabled after it is configured.
 *
 *   @b Arguments
 *   @n  pPatCfg            - A pointer (of type CSL_PatConfigParms*) to the PAT
 *                            configuration structure
 *   @n  inputAddress       - The input address to translate
 *   @n  translatedAddress  - The translated address to use
 *
 *   <b> Return Value </b>
 *   @n  0       - The page address translation was configured properly
 *   @n  -1      - An error occurred. The specified input address exceeded the
 *                 page table size.
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_patSetPageSize
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n BASE_REG_L, BASE_REG_H
 *
 *   @b Example
 *   @verbatim
       CSL_PatConfigParms    patCfg = { (CSL_patRegs *)PAT_BASE_ADDRESS, (CSL_pat_tableRegs *)PAT_TABLE_BASE_ADDRESS };
       uint64_t            inputAddress        = 0x00001000UL;
       uint64_t            translatedAddress   = 0x01000000UL;

       CSL_patSetPageSize(&patCfg, CSL_PAT_PAGE_SIZE_4KB);
       CSL_patConfigPageTranslation(&patCfg, inputAddress, translatedAddress );
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_patConfigPageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress, uint64_t translatedAddress);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
