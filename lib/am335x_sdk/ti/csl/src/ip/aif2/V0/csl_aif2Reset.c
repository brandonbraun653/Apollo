/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008,2009
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
 *   @file  csl_aif2Reset.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  Antenna Interface 2 reset CSL 3.x function
 */

/* =============================================================================
 * Revision History
 * ===============
 *  08-May-2009 Albert File Created.
 *  
 *
 * =============================================================================
 */

#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_aif2Reset
 *   @brief Reset whole AIF2 module.
 *
 *   @b Description
 *   @n Reset whole AIF2 devices and MMRs
 *        The handle returned by this call is input as an
 *        essential argument for rest of the APIs described for this module.
 *
 *   @b Arguments
 *   @verbatim            
           pAif2Handle    Pointer to the object that holds reference to the
                          instance of AIF2 requested after the call

     @endverbatim
 *
 *   <b> Return Value </b>  
 *      CSL_Status
 *        Valid AIF2 status will be returned if status value is
 *        equal to CSL_SOK.
 *
 *   <b> Pre Condition </b>
 *   @n  AIF2 must be successfully initialized via @a CSL_AIF2Init(), CSL_AIF2Open() before 
 *   calling this function. Memory for the @a CSL_Aif2Obj must be allocated 
 *   outside this call. This object must be retained while usage of this peripheral.
 *
 *
 *   <b> Post Condition </b>
 *   @n   1.    The status is returned in the status variable. If status
 *              returned is
 *   @li            CSL_SOK             Valid AIF2 handle is returned
 *   @li            CSL_ESYS_FAIL       The AIF2 instance is invalid
 *
 *        
 * 
 *   @b  Writes
 *   @n  AIF2_AIF2_RESET_SW_RST
 *
 *   @b Example:
 *   @verbatim
          //aif2  handle
          CSL_Aif2Handle hAif2;
         
          // CSL status
          CSL_Status status;
   
          //Reset handle  - for use 
          status = CSL_aif2Reset(hAif2);

          if (status != CSL_SOK) 
          {
             printf ("\nError resetting CSL_AIF2");
             exit(1);
          }
       @endverbatim
 *
 * ===========================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2Reset, ".text:csl_section:aif2")
#endif
CSL_Status CSL_aif2Reset (
   /** Pointer to the object that holds reference to the
    *  instance of AIF2 requested after the call
    */
   CSL_Aif2Handle         pAif2Handle)
{
    CSL_Status           st;
    
    if (pAif2Handle == NULL) 
    {
        st = CSL_ESYS_INVPARAMS;
    }
    else 
    {
        CSL_FINST(pAif2Handle->regs->AIF2_RESET, AIF2_AIF2_RESET_SW_RST, PULSE_RESET);
        st = CSL_SOK;
    }
    return st;
}

