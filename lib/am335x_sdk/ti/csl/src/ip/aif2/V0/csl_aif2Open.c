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
 *   @file  csl_aif2Open.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  Antenna Interface 2 open CSL 3.x function
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

extern CSL_Status CSL_aif2GetBaseAddress (
        CSL_InstNum              aif2Num,
        CSL_Aif2Param *          paif2Param,
        CSL_Aif2BaseAddress *    pBaseAddress 
);

/** ============================================================================
 *   @n@b CSL_aif2Open 
 *   @brief Opens the instance of aif2 requested.
 *
 *   @b Description
 *   @n The open call sets up the data structures for the particular instance of
 *   aif2 device. The device can be re-opened anytime after it has been normally
 *   closed if so required. The handle returned by this call is input as an
 *   essential argument for rest of the APIs described for this module.
 *
 *   @b Arguments
 *   @verbatim            
           paif2LinkObj    Pointer to the object that holds reference to the
                          instance of aif2 requested after the call
                           
           aif2Num         Instance of aif2 to which a handle is requested
           
           paif2Param      Module specific parameters
 
           pStatus        pointer for returning status of the function call

     @endverbatim
 *
 *   <b> Return Value </b>  
 *      CSL_aif2Handle
 *        Valid aif2 instance handle will be returned if status value is
 *        equal to CSL_SOK.
 *
 *   <b> Pre Condition </b>
 *   @n  aif2 must be successfully initialized via @a CSL_aif2Init() before 
 *   calling this function. Memory for the @a CSL_aif2Obj must be allocated 
 *   outside this call. This object must be retained while usage of this peripheral.
 *
 *
 *   <b> Post Condition </b>
 *   @n   1.    The status is returned in the status variable. If status
 *              returned is
 *   @li            CSL_SOK             Valid aif2 handle is returned
 *   @li            CSL_ESYS_FAIL       The aif2 instance is invalid
 *
 *        2.    aif2 object structure is populated
 * 
 *   @b  Writes
 *   @n    1. The status variable
 *           2. aif2 object structure
 *
 *   @b Example:
 *   @verbatim
          // handle for link 0
          CSL_aif2Handle handleaif2Link0;
          //  link object for link 0
          CSL_aif2LinkObj aif2LinkObj0;
          //aif2 module specific parameters
          CSL_aif2Param  aif2Param;
          // CSL status
          CSL_Status status;

          aif2Param.LinkIndex = CSL_aif2_LINK_0;
   
          // Open handle for link 0 - for use 
          handleaif2Link0 = CSL_aif2Open(&aif2LinkObj0, CSL_aif2, &aif2Param, &status);

          if ((handleaif2Link0 == NULL) || (status != CSL_SOK)) 
          {
             printf ("\nError opening CSL_aif2");
             exit(1);
          }
       @endverbatim
 *
 * ===========================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2Open, ".text:csl_section:aif2")
#endif
CSL_Aif2Handle CSL_aif2Open (
   /** Pointer to the object that holds reference to the
    *  instance of aif2 requested after the call
    */
   CSL_Aif2Obj         *paif2Obj,
   /** Instance of aif2 to which a handle is requested
    */
   CSL_InstNum            aif2Num,
   /** Module specific parameters;
    */
   CSL_Aif2Param           *paif2Param,
   /** This returns the status (success/errors) of the call.
    * Could be 'NULL' if the user does not want status information.
    */
   CSL_Status             *pStatus
   )
{
    CSL_Status           st;
    CSL_Aif2Handle       haif2;
    CSL_Aif2BaseAddress  baseAddress;

    if (pStatus == NULL) 
    {
        haif2 = NULL;
    }
    else 
    {
        if (paif2Obj == NULL) 
        {
            *pStatus = CSL_ESYS_INVPARAMS;
            haif2 = NULL;
        }
        else 
        {
            if (CSL_aif2GetBaseAddress(aif2Num, paif2Param, &baseAddress) == CSL_SOK) {
                paif2Obj->regs = baseAddress.regs;
                paif2Obj->arg_link = (CSL_Aif2LinkIndex)0;
                paif2Obj->arg_dioEngine = (CSL_Aif2DioEngineIndex)0;
                paif2Obj->perNum = (CSL_InstNum)aif2Num;
                haif2 = (CSL_Aif2Handle)paif2Obj;
                st = CSL_SOK;
            } else {
                paif2Obj->regs = (CSL_Aif2RegsOvly)NULL;
                paif2Obj->arg_link = (CSL_Aif2LinkIndex)0;
                paif2Obj->arg_dioEngine = (CSL_Aif2DioEngineIndex)0;
                paif2Obj->perNum = (CSL_InstNum)-1;
                haif2 = (CSL_Aif2Handle)NULL;
                st = CSL_ESYS_FAIL;
            }          
            *pStatus = st;
        }
    }
    return haif2;
}



