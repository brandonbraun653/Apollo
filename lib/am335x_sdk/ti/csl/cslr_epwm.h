/********************************************************************
 * Copyright (C) 2017-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_PWM_TOP_H_
#define CSLR_PWM_TOP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#if defined(SOC_AM574x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x) || defined (SOC_AM437x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined(SOC_AM335x) 
#include <ti/csl/cslr_pwmss.h>
#endif

#include <ti/csl/src/ip/epwm/hw_pwmss_submodule_offsets.h>

#if defined(SOC_AM574x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x) || defined (SOC_AM437x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined(SOC_AM335x) || defined (SOC_K2G) || defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
#include <ti/csl/src/ip/epwm/V0/cslr_epwm.h>
#endif

#if defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_J7200)
#include <ti/csl/src/ip/epwm/V0_1/cslr_epwm.h>
#endif

/* Including the HRPWM for below SoCs */
#if defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_J7200)
#include <ti/csl/src/ip/epwm/V0_1/cslr_hrpwm.h>
#endif

#endif
