/*
 *  Copyright (c) 2017-2018 Texas Instruments Incorporated
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
 *   @file  csl_navss_mcu.h
 *
 *   @path  $(CSLPATH)
 *
 *   @desc  This file contains the CSL-FL API's for NAVSS_MCU
 *  ============================================================================
 */
#ifndef CSL_NAVSS_MCU_TOP_H_
#define CSL_NAVSS_MCU_TOP_H_

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_navss_mcu.h>

#if defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_AM77X)
#include <ti/csl/csl_ecc_aggr.h>
#include <ti/csl/csl_intaggr.h>
#include <ti/csl/csl_intr_router.h>
#include <ti/csl/csl_proxy.h>
#include <ti/csl/csl_psilcfg.h>
#include <ti/csl/csl_ringacc.h>
#include <ti/csl/csl_sec_proxy.h>
#include <ti/csl/csl_udmap.h>
#endif

#endif
