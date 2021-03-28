/**
 *   @file  csl_pscAux.h
 *
 *   @brief API Auxilary header file for PSC CSL
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016 Texas Instruments, Inc.
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
#ifndef CSL_PSCAUX_H_
#define CSL_PSCAUX_H_

#include <ti/csl/csl_psc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_PSC_FUNCTION
 @{ */


/** ============================================================================
 *   @n@b CSL_PSC_getVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the PSC peripheral identification register
 *      contents for instance 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>  Uint32  - version value
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
        Uint32      versionInfo;

        versionInfo =   CSL_PSC_getVersionInfo ();

	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_PSC_getVersionInfo (void)
{
   return hPscRegs0->REVID;
}

/** ============================================================================
 *   @n@b CSL_PSC_getVersionInfo2
 *
 *   @b Description
 *   @n This function retrieves the PSC peripheral identification register 
 *      contents for instance 1.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>  Uint32  - version value
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
        Uint32      versionInfo;

        versionInfo =   CSL_PSC_getVersionInfo2 ();

	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_PSC_getVersionInfo2 (void)
{
   return hPscRegs1->REVID;
}

/** ============================================================================
 *   @n@b CSL_PSC_isInvalidModuleNumber
 *
 *   @b Description
 *   @n This function checks the LPSC module number is valid ar invalid
 *      contents.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum      LPSC module number 
 *   @n None
 *
 *   <b> Return Value </b>  bool  - valid or invalid LPSC module Number
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
        bool     validModuleNum;

        validModuleNum =   CSL_PSC_isInvalidModuleNumber (CSL_PSC_USB1);

	 @endverbatim
 * =============================================================================
 */
static inline bool CSL_PSC_isInvalidModuleNumber (Uint32 moduleNum)
{
#if defined(SOC_OMAPL137)
   return ((moduleNum == PSC1_MDUNUSED_NO_16) || (moduleNum == PSC1_MDUNUSED_NO_30) ||
           (moduleNum == PSC1_MDUNUSED_NO_31) || (moduleNum == PSC1_MDUNUSED_NO_34) ||
           (moduleNum == PSC1_MDUNUSED_NO_35) || (moduleNum == PSC1_MDUNUSED_NO_38) ||
           (moduleNum == PSC1_MDUNUSED_NO_43) || (moduleNum == PSC1_MDUNUSED_NO_44) ||
           (moduleNum == PSC1_MDUNUSED_NO_45) || (moduleNum == PSC1_MDUNUSED_NO_46));
#else
   return ((moduleNum == PSC1_MDUNUSED_NO_38) || (moduleNum == PSC1_MDUNUSED_NO_39));
#endif
}

/** ============================================================================
 *   @n@b CSL_PSC_setModuleNextState2
 *
 *   @b Description
 *   @n This function sets up the "Next" state the module should be
 *      transitioned for a given module in LPSC instance 1.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       LPSC Module of instance 1 for which the next state 
		must be configured.
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
        ...
        // Enable Module 1's clock.
        CSL_PSC_setModuleNextState2 (CSL_PSC_USB1, PSC_MODSTATE_ENABLE);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_setModuleNextState2 (
    Uint32                  moduleNum,
    CSL_PSC_MODSTATE        state
)
{
	CSL_FINS (hPscRegs1->MDCTL[moduleNum], PSC_MDCTL_NEXT, state);
}

/** ============================================================================
 *   @n@b CSL_PSC_setModuleNextState
 *
 *   @b Description
 *   @n This function sets up the "Next" state the module should be
 *      transitioned for a given module.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Enable Module 1's clock.
        CSL_PSC_setModuleNextState (CSL_PSC_TC0, PSC_MODSTATE_ENABLE);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_setModuleNextState (
    Uint32                  moduleNum,
    CSL_PSC_MODSTATE        state
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			CSL_PSC_setModuleNextState2(moduleNum, state);
		}
		else
		{
			CSL_FINS (hPscRegs0->MDCTL[moduleNum], PSC_MDCTL_NEXT, state);
		}
	}	
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleNextState2
 *
 *   @b Description
 *   @n This function returns the next state configured for a given module.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the state must 
		be retrieved.
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
        ...
        // Check Module 21's next state configured
        if (CSL_PSC_getModuleNextState2 (CSL_PSC_USB1) == PSC_MODSTATE_ENABLE)
        {
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MODSTATE CSL_PSC_getModuleNextState2  (
    Uint32                  moduleNum
)
{
    return (CSL_PSC_MODSTATE) CSL_FEXT (hPscRegs1->MDCTL[moduleNum], PSC_MDCTL_NEXT);
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleNextState
 *
 *   @b Description
 *   @n This function returns the next state configured for a given module.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Check Module 2's next state configured
        if (CSL_PSC_getModuleNextState (CSL_PSC_TC1) == PSC_MODSTATE_ENABLE)
        {
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MODSTATE CSL_PSC_getModuleNextState  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return CSL_PSC_getModuleNextState2(moduleNum);
		}
		else
		{
			return (CSL_PSC_MODSTATE) CSL_FEXT (hPscRegs0->MDCTL[moduleNum], PSC_MDCTL_NEXT);
		}	
	}
	
	return PSC_MODSTATE_INVALID;
}

/** ===========================================================================
 *   @n@b CSL_PSC_setModuleLocalReset2
 *
 *   @b Description
 *   @n This function configures the Module local reset control.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the status 
		must be retrieved.
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
        ...
        // Assert Module 2's local reset
        CSL_PSC_setModuleLocalReset2 (CSL_PSC_EMAC, PSC_MDLRST_ASSERTED);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_setModuleLocalReset2  (
    Uint32                  moduleNum,
    CSL_PSC_MDLRST          resetState
)
{
    CSL_FINS (hPscRegs1->MDCTL[moduleNum], PSC_MDCTL_LRST, resetState);
}

/** ===========================================================================
 *   @n@b CSL_PSC_setModuleLocalReset
 *
 *   @b Description
 *   @n This function configures the Module local reset control.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Assert Module 2's local reset
        CSL_PSC_setModuleLocalReset (CSL_PSC_TC1, PSC_MDLRST_ASSERTED);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_setModuleLocalReset  (
    Uint32                  moduleNum,
    CSL_PSC_MDLRST          resetState
)
{
   if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			CSL_PSC_setModuleLocalReset2(moduleNum, resetState);
		}
		else
		{
			CSL_FINS (hPscRegs0->MDCTL[moduleNum], PSC_MDCTL_LRST, resetState);
		}
	}	
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalReset2
 *
 *   @b Description
 *   @n This function reads the Module local reset control configured.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instnace 1 for which the status 
		must be retrieved.
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
 *      Uint32  resetState;

        ...
        // Check Module 21's local reset bit
        resetState = CSL_PSC_getModuleLocalReset2 (CSL_PSC_EMAC);
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDLRST CSL_PSC_getModuleLocalReset2  (
    Uint32                  moduleNum
)
{
    return (CSL_PSC_MDLRST) CSL_FEXT (hPscRegs1->MDCTL[moduleNum], PSC_MDCTL_LRST);
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalReset
 *
 *   @b Description
 *   @n This function reads the Module local reset control configured.
 *
 *   @b Arguments
 *   @verbatim
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
 *      Uint32  resetState;

        ...
        // Check Module 2's local reset bit
        resetState = CSL_PSC_getModuleLocalReset (CSL_PSC_TC1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDLRST CSL_PSC_getModuleLocalReset  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_getModuleLocalReset2(moduleNum));
		}
		else
		{
			return (CSL_PSC_MDLRST) CSL_FEXT (hPscRegs0->MDCTL[moduleNum], PSC_MDCTL_LRST);
		}
	}
	
	return PSC_MDLRST_INVALID;
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleState2
 *
 *   @b Description
 *   @n This function returns the current state of a given module.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the state 
		must be retrieved.
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
        ...
        // Check if Module 22's clock is enabled.
        if (CSL_PSC_getModuleState2 (CSL_PSC_EMIFB) == PSC_MODSTATE_ENABLE)
        {
            // Module 2's clock is enabled.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MODSTATE CSL_PSC_getModuleState2  (
    Uint32                  moduleNum
)
{
    return (CSL_PSC_MODSTATE) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_STATE);
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleState
 *
 *   @b Description
 *   @n This function returns the current state of a given module.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Check if Module 2's clock is enabled.
        if (CSL_PSC_getModuleState (CSL_PSC_TC1) == PSC_MODSTATE_ENABLE)
        {
            // Module 2's clock is enabled.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MODSTATE CSL_PSC_getModuleState  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_getModuleState2(moduleNum));
		}
		else
		{
			return (CSL_PSC_MODSTATE) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_STATE);
		}
	}
	return PSC_MODSTATE_INVALID;
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalResetStatus2
 *
 *   @b Description
 *   @n This function returns the Module local reset actual status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the status 
		must be retrieved.
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
        ...
        // Check Module 22's local reset status
        if (CSL_PSC_getModuleLocalResetStatus2 (CSL_PSC_EMIFB) == PSC_MDLRST_ASSERTED)
        {
            // Module 22's local reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDLRST CSL_PSC_getModuleLocalResetStatus2  (
    Uint32                  moduleNum
)
{
    return (CSL_PSC_MDLRST) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_LRST);
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleLocalResetStatus
 *
 *   @b Description
 *   @n This function returns the Module local reset actual status.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Check Module 2's local reset status
        if (CSL_PSC_getModuleLocalResetStatus (CSL_PSC_TC1) == PSC_MDLRST_ASSERTED)
        {
            // Module 2's local reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDLRST CSL_PSC_getModuleLocalResetStatus  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_getModuleLocalResetStatus2(moduleNum));
		}
		else
		{
			return (CSL_PSC_MDLRST) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_LRST);
		}
		
	}
	
	return PSC_MDLRST_INVALID;
}

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleLocalResetDone2
 *
 *   @b Description
 *   @n This function returns the Module local reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the status 
		must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 22's local reset initialization done status
        if (CSL_PSC_isModuleLocalResetDone2 (CSL_PSC_EMIFB))
        {
            // Module 22's local reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline Bool CSL_PSC_isModuleLocalResetDone2  (
    Uint32                  moduleNum
)
{
    return (Bool) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_LRSTDONE);
}

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleLocalResetDone
 *
 *   @b Description
 *   @n This function returns the Module local reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 2's local reset initialization done status
        if (CSL_PSC_isModuleLocalResetDone (CSL_PSC_TC1))
        {
            // Module 2's local reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline Bool CSL_PSC_isModuleLocalResetDone  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_isModuleLocalResetDone2(moduleNum));
		}
		else
		{
			return (Bool) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_LRSTDONE);
		}
	}
	
	return 0;
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleResetStatus2
 *
 *   @b Description
 *   @n This function returns the Module reset actual status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the status 
		must be retrieved.
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
        ...
        // Check Module 22's reset status
        if (CSL_PSC_getModuleResetStatus2 (CSL_PSC_EMIFB) == PSC_MDRST_ASSERTED)
        {
            // Module 22's reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDRST CSL_PSC_getModuleResetStatus2  (
    Uint32                  moduleNum
)
{
    return (CSL_PSC_MDRST) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_MRST);
}

/** ===========================================================================
 *   @n@b CSL_PSC_getModuleResetStatus
 *
 *   @b Description
 *   @n This function returns the Module reset actual status.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Check Module 2's reset status
        if (CSL_PSC_getModuleResetStatus (CSL_PSC_TC1) == PSC_MDRST_ASSERTED)
        {
            // Module 2's reset asserted.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_MDRST CSL_PSC_getModuleResetStatus  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_getModuleResetStatus2(moduleNum));	
		}
		else
		{
			return (CSL_PSC_MDRST) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_MRST);
		}
	}
	
	return PSC_MDRST_INVALID;
}


/** ===========================================================================
 *   @n@b CSL_PSC_isModuleResetDone2
 *
 *   @b Description
 *   @n This function returns the Module reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the status 
		must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 22's reset initialization done status
        if (CSL_PSC_isModuleResetDone2 (CSL_PSC_EMIFB))
        {
            // Module 22's reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline Bool CSL_PSC_isModuleResetDone2  (
    Uint32                  moduleNum
)
{
    return (Bool) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_MRSTDONE);
}

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleResetDone
 *
 *   @b Description
 *   @n This function returns the Module reset initialization done status.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number for which the status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 2's reset initialization done status
        if (CSL_PSC_isModuleResetDone (CSL_PSC_TC1))
        {
            // Module 2's reset init done.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline Bool CSL_PSC_isModuleResetDone  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_isModuleResetDone2(moduleNum));	
		}
		else
		{
			return (Bool) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_MRSTDONE);
		}
	}
	
	return 0;
}


/** ===========================================================================
 *   @n@b CSL_PSC_isModuleClockOn2
 *
 *   @b Description
 *   @n This function returns the actual modclk output to module.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number of instance 1 for which the clock 
		status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 22's modclk status
        if (CSL_PSC_isModuleClockOn2 (CSL_PSC_EMIFB))
        {
            // Module 22's modclk on.
            ...
        }
        else
        {
            // Module 22's modclk gated.
            ...
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline Bool CSL_PSC_isModuleClockOn2  (
    Uint32                  moduleNum
)
{
    return (Bool) CSL_FEXT(hPscRegs1->MDSTAT[moduleNum], PSC_MDSTAT_MCKOUT);
}

/** ===========================================================================
 *   @n@b CSL_PSC_isModuleClockOn
 *
 *   @b Description
 *   @n This function returns the actual modclk output to module.
 *
 *   @b Arguments
 *   @verbatim
        moduleNum       Module number for which the clock status must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
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
        ...
        // Check Module 2's modclk status
        if (CSL_PSC_isModuleClockOn (CSL_PSC_TC1))
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
static inline Bool CSL_PSC_isModuleClockOn  (
    Uint32                  moduleNum
)
{
    if(!CSL_PSC_isInvalidModuleNumber(moduleNum))
	{
		if(moduleNum >= PSC0_MAX_LPSC_MODULE)
		{
			moduleNum = moduleNum - PSC0_MAX_LPSC_MODULE;
			return (CSL_PSC_isModuleClockOn2(moduleNum));	
		}
		else
		{
			return (Bool) CSL_FEXT(hPscRegs0->MDSTAT[moduleNum], PSC_MDSTAT_MCKOUT);
		}
	}	
	return 0;
}

/** ============================================================================
 *   @n@b CSL_PSC_enablePowerDomain
 *
 *   @b Description
 *   @n This function enables the specified power domain.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // On the power domain 1
        CSL_PSC_enablePowerDomain (1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_enablePowerDomain (
    Uint32                  pwrDmnNum
)
{
	switch(pwrDmnNum) {
		case 0	:
		{
			CSL_FINST (hPscRegs0->PDCTL0, PSC_PDCTL0_NEXT, ON);
			break;
		}
		case 1	:
		{
			CSL_FINST (hPscRegs0->PDCTL1, PSC_PDCTL1_NEXT, ON);
			break;
		}

		default	:	break;
	}
}

/** ============================================================================
 *   @n@b CSL_PSC_enablePowerDomain2
 *
 *   @b Description
 *   @n This function enables the specified power domain in LPSC instance 1.
 *
 *   @b Arguments
 *   @verbatim
        pwrDmnNum       Power domain number that needs to be enabled in LPSC instance 1.
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
        ...
        // On the power domain 1 in instance 1
        CSL_PSC_enablePowerDomain2 (1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_enablePowerDomain2 (
    Uint32                  pwrDmnNum
)
{
	switch(pwrDmnNum) {
		case 0	:
		{
			CSL_FINST (hPscRegs1->PDCTL0, PSC_PDCTL0_NEXT, ON);
			break;
		}
		case 1	:
		{
			CSL_FINST (hPscRegs1->PDCTL1, PSC_PDCTL1_NEXT, ON);
			break;
		}

		default	:	break;
	}
}

/** ============================================================================
 *   @n@b CSL_PSC_disablePowerDomain
 *
 *   @b Description
 *   @n This function turns off the specified power domain.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Off the power domain 1
        CSL_PSC_disablePowerDomain (1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_disablePowerDomain (
    Uint32                  pwrDmnNum
)
{
	switch(pwrDmnNum) {
		case 0	:
		{
			CSL_FINST (hPscRegs0->PDCTL0, PSC_PDCTL0_NEXT, OFF);
			break;
		}
		case 1	:
		{
			CSL_FINST (hPscRegs0->PDCTL1, PSC_PDCTL1_NEXT, OFF);
			break;
		}

		default	:	break;
	}
}

/** ============================================================================
 *   @n@b CSL_PSC_disablePowerDomain2
 *
 *   @b Description
 *   @n This function turns off the specified power domain in the LPSC instance 1.
 *
 *   @b Arguments
 *   @verbatim
        pwrDmnNum       Power domain number that needs to be disabled in LPSC instance 1.
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
        ...
        // Off the power domain 1
        CSL_PSC_disablePowerDomain2 (1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_disablePowerDomain2 (
    Uint32                  pwrDmnNum
)
{
	switch(pwrDmnNum) {
		case 0	:
		{
			CSL_FINST (hPscRegs1->PDCTL0, PSC_PDCTL0_NEXT, OFF);
			break;
		}
		case 1	:
		{
			CSL_FINST (hPscRegs1->PDCTL1, PSC_PDCTL1_NEXT, OFF);
			break;
		}

		default	:	break;
	}
}

/** ===========================================================================
 *   @n@b CSL_PSC_getPowerDomainState
 *
 *   @b Description
 *   @n This function returns the current state of a given power domain.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // Check if Power domain is On.
        if (CSL_PSC_getPowerDomainState(1) == PSC_PDSTATE_ON)
        {
            // Power domain 1 is on
            ...
        }
        else
        {
            // Power domain 1 is off
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_PDSTATE CSL_PSC_getPowerDomainState  (
    Uint32                  pwrDmnNum
)
{
	Int8 ret = PSC_PDSTATE_INVALID;
	
	switch(pwrDmnNum) {
		case 0	:
		{
			ret = CSL_FEXT(hPscRegs0->PDSTAT0, PSC_PDSTAT0_STATE);
		}
		break;
		
		case 1	:
		{
			ret = CSL_FEXT(hPscRegs0->PDSTAT1, PSC_PDSTAT1_STATE);
		}
		break;

		default	:
		break;
	}

	return (CSL_PSC_PDSTATE)ret;
}

/** ===========================================================================
 *   @n@b CSL_PSC_getPowerDomainState2
 *
 *   @b Description
 *   @n This function returns the current state of a given power domain in LPSC instance 1.
 *
 *   @b Arguments
 *   @verbatim
        pwrDmnNum       Power domain number for which the state must be retrieved in LPSC instance 1.
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
        ...
        // Check if Power domain is On.
        if (CSL_PSC_getPowerDomainState2(1) == PSC_PDSTATE_ON)
        {
            // Power domain 1 is on
            ...
        }
        else
        {
            // Power domain 1 is off
        }
        ...
     @endverbatim
 * ============================================================================
 */
static inline CSL_PSC_PDSTATE CSL_PSC_getPowerDomainState2  (
    Uint32                  pwrDmnNum
)
{
	Int8 ret = PSC_PDSTATE_INVALID;
	
	switch(pwrDmnNum) {
		case 0	:
		{
			ret = CSL_FEXT(hPscRegs1->PDSTAT0, PSC_PDSTAT0_STATE);
		}
		break;
		
		case 1	:
		{
			ret = CSL_FEXT(hPscRegs1->PDSTAT1, PSC_PDSTAT1_STATE);
		}
		break;

		default	:	
		 break;
	}
	
	return (CSL_PSC_PDSTATE)ret;
}

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
        ...
        // To Enable Power domain 1 and modules 3, 4
        CSL_PSC_enablePowerDomain (1);
        CSL_PSC_setModuleNextState  (3, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (4, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (1);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_startStateTransition (
    Uint32                  pwrDmnNum
)
{
    hPscRegs0->PTCMD =   (1 << pwrDmnNum);
}

/** ============================================================================
 *   @n@b CSL_PSC_startStateTransition2
 *
 *   @b Description
 *   @n This function sets the 'GO' bit in the PSC Command register. All state
 *      transitions marked for a specified power domain and all its modules are
 *      initiated by the hardware with respect to LPSC instance 1.
 *
 *      This function starts a given Power domain and all its modules state
 *      transition.
 *
 *   @b Arguments
 *   @verbatim
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
        ...
        // To Enable Power domain 1 and modules 23, 24
        CSL_PSC_enablePowerDomain2 (1);
        CSL_PSC_setModuleNextState  (CSL_PSC_MCASP0, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (CSL_PSC_MCASP1, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (CSL_PSC_MCASP0);
        ...
     @endverbatim
 * ============================================================================
 */
static inline void CSL_PSC_startStateTransition2 (
    Uint32                  pwrDmnNum
)
{
    hPscRegs1->PTCMD =   (1 << pwrDmnNum);
}

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
        pwrDmnNum       Power domain number for which the state transition status
                        must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
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
        ...
        // Ensure no transition in progress for Power domain 1
        // before we start a new one.
        while (!CSL_PSC_isStateTransitionDone (1));

        // To Enable Power domain 1 and modules 3, 4
        CSL_PSC_enablePowerDomain (1);
        CSL_PSC_setModuleNextState (CSL_PSC_EMIFA, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (CSL_PSC_SPI0, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (1);

        // Wait until the transition process is completed.
        while (!CSL_PSC_isStateTransitionDone (1));
        ...
     @endverbatim
 * ============================================================================
 */
static inline Uint32 CSL_PSC_isStateTransitionDone (
    Uint32                  pwrDmnNum
)
{
    Uint32  pdTransStatus, ret = 0;

    pdTransStatus =   CSL_FEXTR (hPscRegs0->PTSTAT, pwrDmnNum, pwrDmnNum);

    if (pdTransStatus)
    {
        /* Power domain transition is in progress. Return 0 to indicate not yet done. */
        ret = 0;
    }
    else
    {
        /* Power domain transition is done. */
        ret = 1;
    }
	return ret;
}

/** ===========================================================================
 *   @n@b CSL_PSC_isStateTransitionDone2
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
        pwrDmnNum       Power domain number for which the state transition status
                        must be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
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
        ...
        // Ensure no transition in progress for Power domain 1
        // before we start a new one.
        while (!CSL_PSC_isStateTransitionDone2 (1));

        // To Enable Power domain 1 and modules 3, 4
        CSL_PSC_enablePowerDomain2 (1);
        CSL_PSC_setModuleNextState (CSL_PSC_MCASP1, PSC_MODSTATE_ENABLE);
        CSL_PSC_setModuleNextState (CSL_PSC_MCASP2, PSC_MODSTATE_ENABLE);
        CSL_PSC_startStateTransition (1);

        // Wait until the transition process is completed.
        while (!CSL_PSC_isStateTransitionDone2 (1));
        ...
     @endverbatim
 * ============================================================================
 */
static inline Uint32 CSL_PSC_isStateTransitionDone2 (
    Uint32                  pwrDmnNum
)
{
    Uint32  pdTransStatus, ret = 0;

    pdTransStatus =   CSL_FEXTR (hPscRegs1->PTSTAT, pwrDmnNum, pwrDmnNum);

    if (pdTransStatus)
    {
        /* Power domain transition is in progress. Return 0 to indicate not yet done. */
        ret = 0;
    }
    else
    {
        /* Power domain transition is done. */
        ret = 1;
    }
	
	return ret;
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_PSCAUX_H_ */
