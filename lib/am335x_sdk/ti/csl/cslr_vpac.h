/********************************************************************
 * Copyright (C) 2018-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_VPAC_TOP_H_
#define CSLR_VPAC_TOP_H_

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>

#if defined (SOC_J721E) || defined (SOC_AM77X)
#include <ti/csl/src/ip/vpac/V0/cslr_flexcc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_flexcfa.h>
#include <ti/csl/src/ip/vpac/V0/cslr_flexee.h>
#include <ti/csl/src/ip/vpac/V0/cslr_glbce.h>
#include <ti/csl/src/ip/vpac/V0/cslr_ldc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_msc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_nsf4v.h>
#include <ti/csl/src/ip/vpac/V0/cslr_rawfe.h>
#include <ti/csl/src/ip/vpac/V0/cslr_viss.h>
#include <ti/csl/src/ip/vpac/V0/cslr_viss_fcp.h>
#include <ti/csl/src/ip/vpac/V0/cslr_viss_flexcc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_viss_nsf4v.h>
#include <ti/csl/src/ip/vpac/V0/cslr_viss_rawfe.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac_ldc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac_msc.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac_nf.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac_nf_core.h>
#include <ti/csl/src/ip/vpac/V0/cslr_vpac_viss.h>
#include <ti/csl/cslr_ctset2.h>
#include <ti/csl/cslr_ecc_aggr.h>
#include <ti/csl/cslr_hts.h>
#include <ti/csl/cslr_lse.h>
#endif

#endif
