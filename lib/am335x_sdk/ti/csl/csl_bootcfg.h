/**
 *   @file  csl_bootcfg.h
 *
 *   @brief
 *      This is the main Header File for the BOOTCFG Module which defines all
 *      the data structures and exported API.
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
#ifndef CSL_BOOTCFG_TOP_H
#define CSL_BOOTCFG_TOP_H

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>

#if defined(SOC_K2K)

#include <ti/csl/src/ip/bootcfg/V0/csl_bootcfg.h>

#elif defined(SOC_K2H)

#include <ti/csl/src/ip/bootcfg/V0/csl_bootcfg.h>

#elif defined(SOC_K2E)

#include <ti/csl/src/ip/bootcfg/V1/csl_bootcfg.h>

#elif defined(SOC_K2L)

#include <ti/csl/src/ip/bootcfg/V2/csl_bootcfg.h>

#elif defined(SOC_K2G)

#include <ti/csl/src/ip/bootcfg/V3/csl_bootcfg.h>

#elif defined(SOC_C6678)

#include <ti/csl/src/ip/bootcfg/V4/csl_bootcfg.h>

#elif defined(SOC_C6657)

#include <ti/csl/src/ip/bootcfg/V5/csl_bootcfg.h>

#endif /* SOC_XXXXX */

#endif /* CSL_BOOTCFG_TOP_H */
