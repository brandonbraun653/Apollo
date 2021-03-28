/**  
 * @file csl_cpsw.h
 *
 * @brief 
 *  Header file for CSL functional layer of 3 Port Ethernet Switch Subsystem.
 *
 *  It contains the various enumerations, structure definitions and function 
 *  declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2015, Texas Instruments, Inc.
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

#ifndef CSL_CPSW_TOP_H_
#define CSL_CPSW_TOP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_cpsw_ssAux.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/csl_cptsAux.h>

#if defined(SOC_K2K) || defined(SOC_K2H)
#include <ti/csl/src/ip/cpsw/V0/csl_cpsw_5gfssAux.h>
#include <ti/csl/src/ip/cpsw/V0/csl_cpsw_5gfAux.h>
#elif defined(SOC_C6678)
#include <ti/csl/src/ip/cpsw/V4/csl_cpsw_3gfssAux.h>
#include <ti/csl/src/ip/cpsw/V4/csl_cpsw_3gfAux.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* CSL_CPSW_H */                        
