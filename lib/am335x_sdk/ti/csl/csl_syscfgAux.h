/**
 *   @file  csl_syscfg.h
 *
 *   @brief
 *      This is the main Header File for the SYSCFG Module which defines all
 *      the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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
#ifndef CSL_SYSCFGAUX_TOP_H
#define CSL_SYSCFGAUX_TOP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_syscfg.h>
#include <ti/csl/cslr_syscfg.h>


#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)

#include <ti/csl/src/ip/syscfg/V0/csl_syscfgAux.h>

#endif

#if defined(SOC_OMAPL138)

#include <ti/csl/src/ip/syscfg/V0/csl_syscfg1Aux.h>

#endif


#ifdef __cplusplus
}
#endif/* #ifdef __cplusplus */

#endif /* CSL_SYSCFGAUX_TOP_H */
