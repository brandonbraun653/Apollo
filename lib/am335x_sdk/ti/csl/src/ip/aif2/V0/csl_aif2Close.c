/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008, 2009
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
 *   @file  csl_aif2Close.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  Antenna Interface 2 close function
 *
 */                         

/* =============================================================================
 * Revision History
 * ===============
 *  02-June-2009  Albert   File Created.
 *  
 *
 * =============================================================================
 */

#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_aif2Close
 *
 *   @b Description
 *   @n The Close call releases the resources of the peripheral.
 *
 *   @b Arguments
 *   @verbatim
            haif2Link        Handle to the aif2 instance
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Close successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Usage Constraints: </b>
 *   Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before CSL_aif2Close() can be called.
 *   @b Example
 *   @verbatim
       CSL_aif2Handle haif2Link;
       // Properly initialize and open desired link for use
       haif2Link = CSL_aif2Open(&aif2LinkObj0, CSL_aif2, &aif2Param, &status);
       CSL_aif2Close(haif2Link);
     @endverbatim
 * =============================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_aif2Close, ".text:csl_section:aif2")
#endif

CSL_Status  CSL_aif2Close(
    /** Pointer to the object that holds reference to the
     *  instance of aif2  link requested after the CSL_aif2Open(...) call
    */
    CSL_Aif2Handle        haif2
)
{
    CSL_Status  st;
    
    if (haif2 != NULL) {
        haif2->regs = (CSL_Aif2RegsOvly)NULL;
        haif2->perNum   = (CSL_InstNum)-1;
        
        st = CSL_SOK;
    }
    else {
        st = CSL_ESYS_BADHANDLE;
    }
    return st;
}

