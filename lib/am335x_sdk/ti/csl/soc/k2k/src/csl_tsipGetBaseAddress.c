/**
 *   @file  csl_tsipGetBaseAddress.c
 *
 *   @brief   
 *      The file contains routines which are TSIP Device specific
 *      and need to be modified for each new device which has the 
 *      TSIP IP module. 
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008-2011, Texas Instruments, Inc.
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

#include <ti/csl/soc.h>
#include <ti/csl/csl_tsip.h>


/** ============================================================================
 *   @n@b CSL_tsipOpen
 *
 *   @b Description
 *   @n This API opens the TSIP controller instance. This should always
 *      be the first call to the CSL TSIP Functional layer. The handle 
 *      which is returned from this call should be passed in all subsequent
 *      CSL API's.
 *      
 *   <b> Return Value </b> 
 *   @n  CSL_TsipHandle  - Handle to the TSIP Module
 *   @n  0               - Error. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None  
 *
 *   @b  Modifies
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_TsipHandle   hnd;
        ...
        hnd = CSL_tsipOpen (CSL_TSIP_0);    // Opens TSIP Instance 0
        ...
     @endverbatim
 * ===========================================================================
 */
CSL_TsipHandle CSL_tsipOpen (Int32 instNum)
{
    switch (instNum)
    {
        case CSL_TSIP_0:            
        {
            return   (CSL_TsipHandle)CSL_TSIP_0_REGS;              
        }
        case CSL_TSIP_1:
        {
            return   (CSL_TsipHandle)CSL_TSIP_1_REGS;              
        }
    }

    /* Control comes here implies that an invalid instance number was passed */
    return (CSL_TsipHandle)0;
}
