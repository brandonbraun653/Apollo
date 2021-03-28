/**  
 * @file  csl_cpsw_ssAux.h
 *
 * @brief  
 *  API Auxilary header file for Ethernet switch subsystem CSL. 
 *
 *  Contains the different control command and status query functions definations
 *   
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2013, Texas Instruments, Inc.
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

#ifndef CSL_CPSW_SSAUX_H_
#define CSL_CPSW_SSAUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_cpsw_ss_s.h>

/** @addtogroup CSL_CPSW_SS_S_FUNCTION
@{ */

/** ============================================================================
 *   @n@b CSL_CPSW_SS_getVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the ethernet switch subsystem version 
 *      information.
 *
 *   @b Arguments
     @verbatim
        versionInfo         CSL_CPSW_SS_VERSION structure that needs to be populated
                            with the version info read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPSW_5GFSS_S_IDVER_REG_MINOR_VER,
 *      CPSW_5GFSS_S_IDVER_REG_MAJOR_VER,
 *      CPSW_5GFSS_S_IDVER_REG_RTL_VER,
 *      CPSW_5GFSS_S_IDVER_REG_IDENT
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_SS_VERSION    versionInfo;

        CSL_CPSW_SS_getVersionInfo (&versionInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_SS_getVersionInfo (
	CSL_CPSW_SS_VERSION* versionInfo     
)
{
    versionInfo->minorVer   =   CSL_FEXT (hCpsw5gfssRegs->IDVER_REG, CPSW_5GFSS_S_IDVER_REG_MINOR_VER);
    versionInfo->majorVer   =   CSL_FEXT (hCpsw5gfssRegs->IDVER_REG, CPSW_5GFSS_S_IDVER_REG_MAJOR_VER);
    versionInfo->rtlVer     =   CSL_FEXT (hCpsw5gfssRegs->IDVER_REG, CPSW_5GFSS_S_IDVER_REG_RTL_VER);
    versionInfo->id         =   CSL_FEXT (hCpsw5gfssRegs->IDVER_REG, CPSW_5GFSS_S_IDVER_REG_IDENT);

    return;        
}

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
