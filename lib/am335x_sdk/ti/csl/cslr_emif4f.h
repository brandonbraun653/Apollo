/********************************************************************
 * Copyright (C) 2011-2017 Texas Instruments Incorporated.
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
/*********************************************************************
* file: cslr_emif4f.h
*
* Brief: This file contains the Register Description for emif4fv
*
*********************************************************************/
#ifndef CSLR_EMIF4F_TOP_H
#define CSLR_EMIF4F_TOP_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#if defined(SOC_K2K)

#include <ti/csl/src/ip/emif4/V0/cslr_emif4f.h>

#elif defined(SOC_K2H)

#include <ti/csl/src/ip/emif4/V0/cslr_emif4f.h>

#elif defined(SOC_K2E)

#include <ti/csl/src/ip/emif4/V1/cslr_emif4fv.h>

#elif defined(SOC_K2L)

#include <ti/csl/src/ip/emif4/V1/cslr_emif4fv.h>

#elif defined(SOC_C6678)||defined(SOC_C6657)

#include <ti/csl/src/ip/emif4/V3/cslr_emif4f.h>

#elif defined(SOC_K2G)

#include <ti/csl/src/ip/emif4/V1/cslr_emif4fv.h>

#elif defined(SOC_OMAPL137)

#include <ti/csl/src/ip/emif4/V4/cslr_emifa2.h>
#include <ti/csl/src/ip/emif4/V4/cslr_emifb.h>

#elif defined(SOC_OMAPL138)

#include <ti/csl/src/ip/emif4/V4/cslr_emifa2.h>

#elif defined(SOC_AM574x) || defined(SOC_AM572x)||defined(SOC_AM571x)

#include <ti/csl/src/ip/emif4/V2/cslr_emif4d5.h>

#endif /* SOC_XXXXX */

#endif /* CSLR_EMIF4F_H_ */
