/**
 *   @file  csl_psc.h
 *
 *   @brief
 *      This is the main Header File for the PSC Module which defines all
 *      the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008-2019 Texas Instruments, Inc.
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
/** @defgroup CSL_PSC_API PSC
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 *
 * The Power and Sleep Controller (PSC) is intended to be used on chips
 * that require granular power control to all the on-chip modules such as
 * peripherals, CPU, and controllers for power savings.
 *
 * @subsection References
 *   -# PSC User Guide.
 *
 * @subsection Assumptions
 *    The abbreviations PSC, psc and Psc have been used throughout this
 *    document to refer to Power and Sleep Controller.
 */
#ifndef CSL_PSC_H_
#define CSL_PSC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_psc.h>

/**
@defgroup CSL_PSC_SYMBOL  PSC Symbols Defined
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_DATASTRUCT  PSC Data Structures
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_FUNCTION  PSC Functions
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_ENUM PSC Enumerated Data Types
@ingroup CSL_PSC_API
*/

/**
@addtogroup CSL_PSC_SYMBOL
@{
*/

/** Constants for passing parameters to the functions.
 */
/** @brief Pointer to the PSC overlay registers */
#define hPscRegs    ((CSL_PscRegs *)(CSL_PSC_REGS))

/**
@}
*/

/** @addtogroup CSL_PSC_ENUM
 @{ */

/** @brief
 *
 *  Possible PSC Power domain states
 */
typedef uint32_t CSL_PSC_PDSTATE;
    /** Power domain is Off */
#define PSC_PDSTATE_OFF             ((uint32_t) 0U)
    /** Power domain is On */
#define PSC_PDSTATE_ON              ((uint32_t) 1U)

/** @brief
 *
 *  Possible PSC Module states
 */
typedef uint32_t CSL_PSC_MODSTATE;
    /** Module is in Reset state. Clock is off. */
#define PSC_MODSTATE_SWRSTDISABLE   ((uint32_t) 0U)
    /** Module is in Sync Reset state. */
#define PSC_MODSTATE_SYNCRST        ((uint32_t) 1U)
    /** Module is in disable state. */
#define PSC_MODSTATE_DISABLE        ((uint32_t) 2U)
    /** Module is in enable state. */
#define PSC_MODSTATE_ENABLE         ((uint32_t) 3U)
    /** Module is in Auto sleep state */
#define PSC_MODSTATE_AUTOSLP        ((uint32_t) 4U)
    /** Module is in Auto wake state */
#define PSC_MODSTATE_AUTOWK         ((uint32_t) 5U)

/** @brief
 *
 *  Possible module local reset status
 */
typedef uint32_t CSL_PSC_MDLRST;
    /** Module local reset asserted */
#define PSC_MDLRST_ASSERTED         ((uint32_t) 0U)
    /** Module local reset deasserted */
#define PSC_MDLRST_DEASSERTED       ((uint32_t) 1U)

/** @brief
 *
 *  Possible module reset status
 */
typedef uint32_t CSL_PSC_MDRST;
    /** Module reset asserted */
#define PSC_MDRST_ASSERTED          ((uint32_t) 0U)
    /** Module reset deasserted */
#define PSC_MDRST_DEASSERTED        ((uint32_t) 1U)

/**
@}
*/

/** @addtogroup CSL_PSC_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_PSC_getVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the PSC peripheral identification register
 *      contents.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
     @endverbatim
 *
 *   <b> Return Value </b>  uint32_t  - version value
 *
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n PSC_PID
 *
 *   @b Example
 *   @verbatim
        uint32_t          versionInfo;
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        versionInfo =   CSL_PSC_getVersionInfo (pPscRegs);

	 @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_PSC_getVersionInfo (const CSL_PscRegs *pPscRegs);

/** ============================================================================
 *   @n@b CSL_PSC_getVoltageControl
 *
 *   @b Description
 *   @n This function retrieves the Smart reflex bits from the voltage
 *      control identification register.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
     @endverbatim
 *
 *   <b> Return Value </b>  uint8_t
 *
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n PSC_VCNTLID_VCNTL
 *
 *   @b Example
 *   @verbatim
        uint32_t      vcntlInfo;
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;

        vcntlInfo =   CSL_PSC_getVoltageControl (pPscRegs);

	 @endverbatim
 * =============================================================================
 */
extern uint8_t CSL_PSC_getVoltageControl(const CSL_PscRegs *pPscRegs);

/** ============================================================================
 *   @n@b CSL_PSC_setModuleNextState
 *
 *   @b Description
 *   @n This function sets up the "Next" state the module should be
 *      transitioned for a given module.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       LPSC Module for which the next state must be configured.
        state           Next state to which the module must be transitioned.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Module is moved to configured next state after transition is triggered
 *       using @a CSL_PSC_startStateTransition () API.
 *
 *   @b  Writes
 *   @n  PSC_MDCTL_NEXT
 *
 *   @b  Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Enable Module 1's clock.
        CSL_PSC_setModuleNextState (pPscRegs, 1, PSC_MODSTATE_ENABLE);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_setModuleNextState( CSL_PscRegs *pPscRegs, uint32_t moduleNum, CSL_PSC_MODSTATE state );

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleNextState
 *
 *   @b Description
 *   @n This function returns the next state configured for a given module.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the state must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_MODSTATE
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDCTL_NEXT
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's next state configured
        if (CSL_PSC_getModuleNextState (pPscRegs, 2) == PSC_MODSTATE_ENABLE)
        {
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_MODSTATE CSL_PSC_getModuleNextState( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_setModuleLocalReset
 *
 *   @b Description
 *   @n This function configures the Module local reset control.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
        resetState      Assert/Deassert module local reset.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n PSC_MDCTL_LRST
 *
 *   @b Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Assert Module 2's local reset
        CSL_PSC_setModuleLocalReset (pPscRegs, 2, PSC_MDLRST_ASSERTED);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_setModuleLocalReset( CSL_PscRegs *pPscRegs, uint32_t moduleNum, CSL_PSC_MDLRST resetState );

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalReset
 *
 *   @b Description
 *   @n This function reads the Module local reset control configured.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_MDLRST
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDCTL_LRST
 *
 *   @b Example
 *   @verbatim
 *      uint32_t  resetState;
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;

        ...
        // Check Module 2's local reset bit
        resetState = CSL_PSC_getModuleLocalReset (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_MDLRST CSL_PSC_getModuleLocalReset( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_enableModuleResetIsolation
 *
 *   @b Description
 *   @n This function enables the Module reset isolation control.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the configuration must be done.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n PSC_MDCTL_RSTISO=1
 *
 *   @b Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Enable Module 2's reset isolation
        CSL_PSC_enableModuleResetIsolation (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_enableModuleResetIsolation( CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_disableModuleResetIsolation
 *
 *   @b Description
 *   @n This function disables the Module reset isolation control.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the configuration must be done.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n PSC_MDCTL_RSTISO=0
 *
 *   @b Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Disable Module 2's reset isolation
        CSL_PSC_disableModuleResetIsolation (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_disableModuleResetIsolation( CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleResetIsolationEnabled
 *
 *   @b Description
 *   @n This function reads the Module reset isolation control bit.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDCTL_RSTISO
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's reset isolation configuration
        if (CSL_PSC_isModuleResetIsolationEnabled (pPscRegs, 2) == TRUE)
        {
            // Module 2 reset isolation enabled
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern bool CSL_PSC_isModuleResetIsolationEnabled( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleState
 *
 *   @b Description
 *   @n This function returns the current state of a given module.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the state must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_MODSTATE
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Power Domain status is returned
 *
 *   @b Reads
 *   @n PSC_MDSTAT_STATE
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check if Module 2's clock is enabled.
        if (CSL_PSC_getModuleState (pPscRegs, 2) == PSC_MODSTATE_ENABLE)
        {
            // Module 2's clock is enabled.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_MODSTATE CSL_PSC_getModuleState( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalResetStatus
 *
 *   @b Description
 *   @n This function returns the Module local reset actual status.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_MDLRST
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDSTAT_LRST
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's local reset status
        if (CSL_PSC_getModuleLocalResetStatus (pPscRegs, 2) == PSC_MDLRST_ASSERTED)
        {
            // Module 2's local reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_MDLRST CSL_PSC_getModuleLocalResetStatus( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleLocalResetDone
 *
 *   @b Description
 *   @n This function returns the Module local reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDSTAT_LRSTDONE
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's local reset initialization done status
        if (CSL_PSC_isModuleLocalResetDone (pPscRegs, 2))
        {
            // Module 2's local reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern bool CSL_PSC_isModuleLocalResetDone( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleResetStatus
 *
 *   @b Description
 *   @n This function returns the Module reset actual status.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_MDRST
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDSTAT_MRST
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's reset status
        if (CSL_PSC_getModuleResetStatus (pPscRegs, 2) == PSC_MDRST_ASSERTED)
        {
            // Module 2's reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_MDRST CSL_PSC_getModuleResetStatus( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleResetDone
 *
 *   @b Description
 *   @n This function returns the Module reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDSTAT_MRSTDONE
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's reset initialization done status
        if (CSL_PSC_isModuleResetDone (pPscRegs, 2))
        {
            // Module 2's reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern bool CSL_PSC_isModuleResetDone( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleClockOn
 *
 *   @b Description
 *   @n This function returns the actual modclk output to module.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        moduleNum       Module number for which the clock status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n PSC_MDSTAT_MCKOUT
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check Module 2's modclk status
        if (CSL_PSC_isModuleClockOn (pPscRegs, 2))
        {
            // Module 2's modclk on.
            ...
        }
        else
        {
            // Module 2's modclk gated.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern bool CSL_PSC_isModuleClockOn( const CSL_PscRegs *pPscRegs, uint32_t moduleNum );

/** ============================================================================
 *   @n@b CSL_PSC_enablePowerDomain
 *
 *   @b Description
 *   @n This function enables the specified power domain.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        pwrDmnNum       Power domain number that needs to be enabled.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Power domain is enabled.
 *
 *   @b  Writes
 *   @n  PSC_PDCTL_NEXT=1
 *
 *   @b  Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // On the power domain 2
        CSL_PSC_enablePowerDomain (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_enablePowerDomain( CSL_PscRegs *pPscRegs, uint32_t pwrDmnNum );

/** ============================================================================
 *   @n@b CSL_PSC_disablePowerDomain
 *
 *   @b Description
 *   @n This function turns off the specified power domain.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        pwrDmnNum       Power domain number that needs to be disabled.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Power domain is disabled.
 *
 *   @b  Writes
 *   @n  PSC_PDCTL_NEXT=0
 *
 *   @b  Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Off the power domain 2
        CSL_PSC_disablePowerDomain (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_disablePowerDomain( CSL_PscRegs *pPscRegs, uint32_t pwrDmnNum );

/** ===========================================================================
 *   @n@b CSL_PSC_getPowerDomainState
 *
 *   @b Description
 *   @n This function returns the current state of a given power domain.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        pwrDmnNum       Power domain number for which the state must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_PSC_PDSTATE
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Power Domain status is returned
 *
 *   @b Reads
 *   @n PSC_PDSTAT_STATE
 *
 *   @b Example
 *   @verbatim
        const CSL_PscRegs *pPscRegs = (const CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Check if Power domain is On.
        if (CSL_PSC_getPowerDomainState(pPscRegs, 2) == PSC_PDSTATE_ON)
        {
            // Power domain 2 is on
            ...
        }
        else
        {
            // Power domain 2 is off
        }
        ...
     @endverbatim
 * ============================================================================
 */
extern CSL_PSC_PDSTATE CSL_PSC_getPowerDomainState( const CSL_PscRegs *pPscRegs, uint32_t pwrDmnNum );

/** ============================================================================
 *   @n@b CSL_PSC_startStateTransition
 *
 *   @b Description
 *   @n This function sets the 'GO' bit in the PSC Command register. All state
 *      transitions marked for a specified power domain and all its modules are
 *      initiated by the hardware.
 *
 *      This function starts a given Power domain and all its modules state
 *      transition.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        pwrDmnNum       Power domain number for which the state transition
                        must be initiated.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Power domain and modules are moved to a new "Next" state as marked
 *       earlier using APIs: @a CSL_PSC_setModuleNextState  (),
 *       @a CSL_PSC_enablePowerDomain (), @a CSL_PSC_disablePowerDomain ().
 *
 *   @b  Writes
 *   @n  PSC_PTCMD
 *
 *   @b  Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // To Enable Power domain 2 and modules 3, 4
        CSL_PSC_enablePowerDomain (pPscRegs, 2);
        CSL_PSC_setModuleNextState  (pPscRegs, 3, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (pPscRegs, 4, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (pPscRegs, 2);
        ...
     @endverbatim
 * ============================================================================
 */
extern void CSL_PSC_startStateTransition( CSL_PscRegs *pPscRegs, uint32_t pwrDmnNum );

/** ===========================================================================
 *   @n@b CSL_PSC_isStateTransitionDone
 *
 *   @b Description
 *   @n This function gets the transition status of the power domain. This function
 *      returns 0 to indicate that the state transition initiated earlier using
 *      @a CSL_PSC_startStateTransition () API for the specified power domain has not
 *      yet been completed, and is in progress still. This function returns 1
 *      to indicate when this transition is completed in the hardware.
 *
 *   @b Arguments
 *   @verbatim
        pPscRegs        Pointer to PSC register structure.
        pwrDmnNum       Power domain number for which the state transition status
                        must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Power domain transition status value is read
 *
 *   @b Reads
 *   @n PSC_PTSTAT
 *
 *   @b Example
 *   @verbatim
        CSL_PscRegs *pPscRegs = (CSL_PscRegs *)CSL_PSC0_BASE;
        ...
        // Ensure no transition in progress for Power domain 2
        // before we start a new one.
        while (!CSL_PSC_isStateTransitionDone (pPscRegs, 2));

        // To Enable Power domain 2 and modules 3, 4
        CSL_PSC_enablePowerDomain (pPscRegs, 2);
        CSL_PSC_setModuleNextState (pPscRegs, 3, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (pPscRegs, 4, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (pPscRegs, 2);

        // Wait until the transition process is completed.
        while (!CSL_PSC_isStateTransitionDone (pPscRegs, 2));
        ...
     @endverbatim
 * ============================================================================
 */
extern uint32_t CSL_PSC_isStateTransitionDone( const CSL_PscRegs *pPscRegs, uint32_t pwrDmnNum );

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif  /* CSL_PSC_H_ */
