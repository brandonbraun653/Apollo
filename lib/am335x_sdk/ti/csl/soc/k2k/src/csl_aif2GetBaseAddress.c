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
 *   @file  csl_aif2GetBaseAddress.c
 *
 *   @brief File for functional layer of CSL API  CSL_aif2GetBaseAddress () 
 *
 *   @path  $(CSLPATH)\src\common
 *
 *   @desc  The  CSL_aif2GetBaseAddress  function definition.
 */
/* =============================================================================
 * Revision History
 * ===============
 *  
 *
 * =============================================================================
 */
#include <ti/csl/soc.h>
#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_aif2GetBaseAddress
 *
 *   @b Description
 *   @n  Function to get the base address of the peripheral instance.
 *       This function is used for getting the base address of the peripheral
 *       instance. This function will be called inside the CSL_aif2Open()
 *       function call. This function is open for re-implementing if the user
 *       wants to modify the base address of the peripheral object to point to
 *       a different location and there by allow CSL initiated write/reads into
 *       peripheral. MMR's go to an alternate location.
 *
 *   @b Arguments
 *   @verbatim
            aif2Num        Specifies the instance of the bwmngmt to be opened.

            paif2Param     Module specific parameters.

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
        CSL_aif2BaseAddress  baseAddress;

       ...
      status = CSL_aif2GetBaseAddress(CSL_AIF2, NULL, &baseAddress);

     @endverbatim
 * ===========================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2GetBaseAddress, ".text:csl_section:aif2")
#endif
CSL_Status CSL_aif2GetBaseAddress ( CSL_InstNum aif2Num, CSL_Aif2Param *paif2Param, CSL_Aif2BaseAddress *pBaseAddress); /*for misra warnings*/
CSL_Status
CSL_aif2GetBaseAddress (
        CSL_InstNum              aif2Num,
        CSL_Aif2Param *          paif2Param,
        CSL_Aif2BaseAddress *    pBaseAddress 
)
{
    CSL_Status st = CSL_SOK;

    if (pBaseAddress == NULL) {
        st = CSL_ESYS_INVPARAMS;
    }
    else
    {
        pBaseAddress->regs = (CSL_Aif2RegsOvly)CSL_AIF_CFG_REGS;
        st = CSL_SOK;
    }
    return st;
}


