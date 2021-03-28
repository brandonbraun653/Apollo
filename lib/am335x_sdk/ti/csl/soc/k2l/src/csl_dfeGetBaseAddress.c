/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2012-2013
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
 *   @file  csl_dfeGetBaseAddress.c
 *
 *   @brief File for functional layer of CSL API  CSL_dfeGetBaseAddress () 
 *
 *   @path  $(CSLPATH)\src\common
 *
 *   @desc  The  CSL_dfeGetBaseAddress  function definition.
 */
/* =============================================================================
 * Revision History
 * ===============
 *  
 *
 * =============================================================================
 */
#include <ti/csl/soc.h>
#include <ti/csl/csl_dfe.h>

/** ============================================================================
 *   @n@b CSL_dfeGetBaseAddress
 *
 *   @b Description
 *   @n  Function to get the base address of the peripheral instance.
 *       This function is used for getting the base address of the peripheral
 *       instance. This function will be called inside the CSL_dfeOpen()
 *       function call. This function is open for re-implementing if the user
 *       wants to modify the base address of the peripheral object to point to
 *       a different location and there by allow CSL initiated write/reads into
 *       peripheral. MMR's go to an alternate location.
 *
 *   @b Arguments
 *   @verbatim
            dfeNum         Specifies the instance of the DFE to be opened.

            pdfe2Param     Module specific parameters.

            pBaseAddress      Pointer to baseaddress structure containing base
                              address details.

     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            Successful on getting the base 
 *                                             address of bwmngmt
 *   @li                    CSL_ESYS_FAIL      The instance number is invalid.
 *   @li                    CSL_ESYS_INVPARAMS Inavlid parameters 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Base Address structure is populated
 *
 *   @b Affects
 *   @n    1. The status variable
 *
 *         2. Base address structure is modified.
 *
 *   @b Example
 *   @verbatim
        CSL_Status              status;
        CSL_dfeBaseAddress      baseAddress;

       ...
      status = CSL_dfeGetBaseAddress(CSL_DFE, NULL, &baseAddress);

     @endverbatim
 * ===========================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_dfeGetBaseAddress, ".text:csl_section:dfe");
#endif

CSL_Status
CSL_dfeGetBaseAddress (
        CSL_InstNum 	         dfeNum,
        CSL_DfeParam *           pDfeParam,
        CSL_DfeBaseAddress *     pBaseAddress 
)
{
    if (pBaseAddress == NULL || dfeNum != 0) 
    {
        return CSL_ESYS_INVPARAMS;
    }

    pBaseAddress->regs = (CSL_DfeRegsOvly)CSL_DFE_CFG_REGS;

    return CSL_SOK;
}


