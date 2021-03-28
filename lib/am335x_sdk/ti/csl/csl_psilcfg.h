/*
 *  Copyright (c) Texas Instruments Incorporated 2016-2019
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
/** ============================================================================
 *   @file  csl_psilcfg.h
 *
 *   @path  $(CSLPATH)
 *
 *   @desc  This file contains the CSL-FL API's for PSILCFG
 *  ============================================================================
 */
#ifndef CSL_PSILCFG_TOP_H_
#define CSL_PSILCFG_TOP_H_

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_psilcfg.h>

#if defined (SOC_AM65XX)
#include <ti/csl/src/ip/psilcfg/V0/csl_psilcfg.h>
#include <ti/csl/soc/am65xx/src/csl_psilcfg_thread_map.h>
#endif

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_AM77X)
#include <ti/csl/src/ip/psilcfg/V0/csl_psilcfg.h>
#if defined (SOC_J721E) || defined (SOC_AM77X)
#include <ti/csl/soc/j721e/src/csl_psilcfg_thread_map.h>
#elif defined (SOC_J7200)
#include <ti/csl/soc/j7200/src/csl_psilcfg_thread_map.h>
#endif
#endif

#endif
