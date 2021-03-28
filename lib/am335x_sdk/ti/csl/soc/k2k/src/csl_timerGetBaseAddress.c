/**
 *   @file  csl_timerGetBaseAddress.c
 *
 *   @brief   
 *      The file contains routines which are TIMER Device specific
 *      and need to be modified for each new device which has the 
 *      TIMER IP module. 
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002-2012, Texas Instruments, Inc.
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
#include <ti/csl/csl_tmr.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_tmrGetBaseAddress
 *
 *   @b Description
 *   @n  This function gets the base address of the given GPTIMER instance.
 *
 *   @b Arguments
 *   @verbatim
            tmrNum        Specifies the instance of the gptimer to be opened
            pTmrParam     TIMER module specific parameters
            pBaseAddress  Pointer to base address structure containing base
                          address details
     @endverbatim
 *
 *   <b> Return Value </b> 
 *   @n Success - CSL_SOK
 *   @n Error   - CSL_ESYS_FAIL (Timer Instance is invalid)
 *   @n Error   - CSL_ESYS_INVPARAMS (The parameter passed is invalid)
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Affects
 *   @n None
 *
 *   @b Example
 *   @verbatim
        CSL_Status            status;
        CSL_TmrBaseAddress    baseAddress;
        CSL_TmrContext  context;

        // Initialize the Timer Module.
        CSL_tmrInit(&context);
        ...
        // Get the base address for TIMER Instance 0.
        status = CSL_tmrGetBaseAddress(0, NULL, &baseAddress);
        ...
    @endverbatim
 * ===========================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_tmrGetBaseAddress, ".text:csl_section:tmr")
#endif
CSL_Status CSL_tmrGetBaseAddress 
(
    CSL_InstNum            tmrNum,
    CSL_TmrParam*          pTmrParam,
    CSL_TmrBaseAddress*    pBaseAddress
)
{
    CSL_Status st = CSL_SOK;

    pTmrParam = pTmrParam;

    if (pBaseAddress == NULL)
    {
        st = (CSL_Status)CSL_ESYS_INVPARAMS;
    }
    else
    {
        switch (tmrNum) {
#ifdef CSL_TIMER_0
        case CSL_TIMER_0:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_0_REGS;
            break;
#endif /* CSL_TIMER_0 */
#ifdef CSL_TIMER_1
        case CSL_TIMER_1:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_1_REGS;
            break;
#endif /* CSL_TIMER_1 */
#ifdef CSL_TIMER_2
        case CSL_TIMER_2:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_2_REGS;
            break;
#endif /* CSL_TIMER_2 */
#ifdef CSL_TIMER_3
        case CSL_TIMER_3:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_3_REGS;
            break;
#endif /* CSL_TIMER_3 */
#ifdef CSL_TIMER_4
        case CSL_TIMER_4:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_4_REGS;
            break;
#endif /* CSL_TIMER_4 */
#ifdef CSL_TIMER_5
        case CSL_TIMER_5:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_5_REGS;
            break;
#endif /* CSL_TIMER_5 */
#ifdef CSL_TIMER_6
        case CSL_TIMER_6:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_6_REGS;
            break;
#endif /* CSL_TIMER_6 */
#ifdef CSL_TIMER_7
        case CSL_TIMER_7:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_7_REGS;
            break;
#endif /* CSL_TIMER_7 */
#ifdef CSL_TIMER_8
        case CSL_TIMER_8:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_8_REGS;
            break;   
#endif /* CSL_TIMER_8 */
#ifdef CSL_TIMER_9
        case CSL_TIMER_9:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_9_REGS;
            break;                                
#endif /* CSL_TIMER_9 */
#ifdef CSL_TIMER_10
        case CSL_TIMER_10:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_10_REGS;
            break;                                
#endif /* CSL_TIMER_10 */
#ifdef CSL_TIMER_11
        case CSL_TIMER_11:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_11_REGS;
            break;                                
#endif /* CSL_TIMER_11 */
#ifdef CSL_TIMER_12
        case CSL_TIMER_12:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_12_REGS;
            break;                                
#endif /* CSL_TIMER_12 */
#ifdef CSL_TIMER_13
        case CSL_TIMER_13:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_13_REGS;
            break;                                
#endif /* CSL_TIMER_13 */
#ifdef CSL_TIMER_14
        case CSL_TIMER_14:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_14_REGS;
            break;                                
#endif /* CSL_TIMER_14 */
#ifdef CSL_TIMER_15
        case CSL_TIMER_15:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_15_REGS;
            break;                                                                  
#endif /* CSL_TIMER_15 */
#ifdef CSL_TIMER_16
        case CSL_TIMER_16:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_16_REGS;
            break;                                                                  
#endif /* CSL_TIMER_16 */
#ifdef CSL_TIMER_17
        case CSL_TIMER_17:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_17_REGS;
            break;                                                                  
#endif /* CSL_TIMER_17 */
#ifdef CSL_TIMER_18
        case CSL_TIMER_18:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_18_REGS;
            break;                                                                  
#endif /* CSL_TIMER_18 */
#ifdef CSL_TIMER_19
        case CSL_TIMER_19:
            pBaseAddress->regs = (CSL_TmrRegsOvly)CSL_TIMER_19_REGS;
            break;                                                                  
#endif /* CSL_TIMER_19 */
        default:
            pBaseAddress->regs = (CSL_TmrRegsOvly)NULL;
            st = (CSL_Status)CSL_ESYS_FAIL;
            break;
        }
    }
    return st;
}
