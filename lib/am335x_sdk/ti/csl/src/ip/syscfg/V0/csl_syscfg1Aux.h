/**
 *   @file  csl_syscfgaux.h
 *
 *   @brief
 *      This is the Boot Configuration Auxilary Header File which exposes
 *      the various CSL Functional Layer API's to configure the SYSCFG Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2017, Texas Instruments, Inc.
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

#ifndef CSL_SYSCFG1AUX_V0_H_
#define CSL_SYSCFG1AUX_V0_H_

#include <ti/csl/csl_syscfg.h>
#include <ti/csl/csl_pllc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_SYSCFG_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_SysCfg1ReadReg
 *
 *   @b Description
 *   @n The function is used to read the SysCfg register values
 *
 *   @b Arguments
     @verbatim
		reg		Register enum ID
        info    Register information populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Example
 *   @verbatim
        Uint32  info;

        // Get the boot configuration revision information.
        CSL_SysCfg1ReadReg ( 0 ,&info);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfg1ReadReg (Uint16 reg, Uint32* info)
{
	Uint32 val;
	switch(reg)
	{
		case VtpIOCTL : 
			val = hSysCfg1->VTPIO_CTL;
			break;
		case DDRSlew : 
			val = hSysCfg1->DDR_SLEW;
			break;
		case DeepSleep : 
			val = hSysCfg1->DEEPSLEEP;
			break;
		case PUPDEna : 
			val = hSysCfg1->PUPD_ENA;
			break;
		case PUPDSel : 
			val = hSysCfg1->PUPD_SEL;
			break;
		case RxAxtive : 
			val = hSysCfg1->RXACTIVE;
			break;
		case Pwrdn : 
			val = hSysCfg1->PWRDN;
			break;
		default:
			val = 0xFF;
			break;
	}
    *info = val;
}

/** ============================================================================
 *   @n@b CSL_SysCfg1WriteReg
 *
 *   @b Description
 *   @n The function is used to write the SysCfg register values
 *
 *   @b Arguments
     @verbatim
		reg		Register enum ID
        val     Register value to write
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Example
 *   @verbatim
        Uint32  info;

        // Get the boot configuration revision information.
        CSL_SysCfg1WriteReg ( 0 ,val);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfg1WriteReg (Uint16 reg, Uint32 val)
{
	switch(reg)
	{
		case VtpIOCTL : 
			hSysCfg1->VTPIO_CTL = val;
			break;
		case DDRSlew : 
			hSysCfg1->DDR_SLEW = val;
			break;
		case DeepSleep : 
			hSysCfg1->DEEPSLEEP = val;
			break;
		case PUPDEna : 
			hSysCfg1->PUPD_ENA = val;
			break;
		case PUPDSel : 
			hSysCfg1->PUPD_SEL = val;
			break;
		case RxAxtive : 
			hSysCfg1->RXACTIVE = val;
			break;
		case Pwrdn : 
			hSysCfg1->PWRDN = val;
			break;
		default:
			break;
	}
}


/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_SYSCFG1AUX_V0_H_ */
