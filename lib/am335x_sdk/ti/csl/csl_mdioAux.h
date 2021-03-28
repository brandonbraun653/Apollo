/**  
 * @file  csl_mdioAux.h
 *
 * @brief  
 *  API Auxilary header file for MDIO CSL. Contains the different control 
 *  command and status query functions definations
 *   
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2017, Texas Instruments, Inc.
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

#ifndef CSL_MDIOAUX_TOP_H
#define CSL_MDIOAUX_TOP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>

#if defined(SOC_K2K) || defined(SOC_C6678) || defined(SOC_K2H) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)

#include <ti/csl/src/ip/mdio/V0/csl_mdioAux.h>

#elif defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G)

#include <ti/csl/src/ip/mdio/V1/csl_mdioAux.h>

#elif defined (SOC_AM574x) || defined(SOC_AM572x)||defined(SOC_AM571x) || defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x)

#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>

#endif /* DEVICE_XXXXX */


#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
