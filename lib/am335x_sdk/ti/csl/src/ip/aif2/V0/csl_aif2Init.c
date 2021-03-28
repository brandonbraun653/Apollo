/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008. 2009
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



/** ===========================================================================
 *   @file  csl_aif2Init.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  Antenna Interface 2 Intialization CSL 3.x funtion
 *
 */


/* =============================================================================
 *  Revision History
 * ===============
 *  02-June-2009  Albert   File Created.
 *  
 *
 * =============================================================================
 */

#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** global variable definitions **/

/**************************************************************************\
* aif2 global function declarations
\**************************************************************************/

/** ============================================================================
 *   @n@b CSL_aif2Init
 *   @brief Peripheral specific initialization function.
 *
 *   @b Description
 *   @n This is the peripheral specific intialization function. This function is
 *   idempotent in that calling it many times is same as calling it once.
 *   This function initializes the CSL data structures, and doesn't touches
 *   the hardware.
 *
 *   @b Arguments
 *   @verbatim
        pContext    Pointer to module-context. As aif2 doesn't
                    have any context based information user is expected to pass
                    NULL.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li  CSL_SOK - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  This function should be called before using any of the CSL APIs in the aif2
 *   module.
 *
 *   <b> Post Condition </b>
 *   @n  The CSL for aif2 is initialized
 *
 *   @b Writes
 *   @n  None
 *
 *   @b Example
 *   @verbatim
          CSL_aif2Init(NULL); // Init CSL for aif2 module
     @endverbatim
 * =============================================================================
 */
#if defined (_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2Init, ".text:csl_section:aif2")
#endif
CSL_Status  CSL_aif2Init(
    CSL_Aif2Context    *pContext
)
{
   /* nothing to do, so return CSL_OK */
   return CSL_SOK;
}

