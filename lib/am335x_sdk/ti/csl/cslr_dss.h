/*
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/********************************************************************
* file: cslr_dss.h
*
* Brief: This file contains the Register Description for dss
*
*********************************************************************/
#ifndef CSLR_DSS_TOP_H_
#define CSLR_DSS_TOP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#if defined(SOC_K2G)
#include <ti/csl/src/ip/dss/V0/cslr_dss.h>
#include <ti/csl/src/ip/dss/V0/cslr_dss_common.h>
#include <ti/csl/src/ip/dss/V0/cslr_dss_ovr.h>
#include <ti/csl/src/ip/dss/V0/cslr_dss_rfbi.h>
#include <ti/csl/src/ip/dss/V0/cslr_dss_vid.h>
#include <ti/csl/src/ip/dss/V0/cslr_dss_vp.h>
#elif defined(SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined(SOC_AM571x) || defined(SOC_TDA2EX) || defined(SOC_DRA72x)
#include <ti/csl/src/ip/dss/V1/cslr_dss.h>
#include <ti/csl/src/ip/dss/V1/cslr_dsi_phy.h>
#include <ti/csl/src/ip/dss/V1/cslr_dsi_protocol_engine.h>
#include <ti/csl/src/ip/dss/V1/cslr_dss_dispc.h>
#include <ti/csl/src/ip/dss/V1/cslr_dss_rfbi.h>
#include <ti/csl/src/ip/dss/V1/cslr_pllctrl.h>
#include <ti/csl/src/ip/dss/V1/hw_dispc.h>
#include <ti/csl/src/ip/dss/V1/hw_dss_family.h>
#include <ti/csl/src/ip/dss/V1/hw_hdmi_dwc_tx.h>
#include <ti/csl/src/ip/dss/V1/hw_hdmi_phy.h>
#include <ti/csl/src/ip/dss/V1/hw_hdmi_pll.h>
#include <ti/csl/src/ip/dss/V1/hw_hdmi_wp.h>
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#include <ti/csl/src/ip/dss/V2/hw_dss_common.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_dssreg.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_gfx.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_glbce.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_ovr.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_venc.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_vid.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_vp.h>
#include <ti/csl/src/ip/dss/V2/hw_dss_wb.h>
#elif defined (SOC_AM65XX)
#include <ti/csl/src/ip/dss/V3/cslr_dss.h>
#elif defined (SOC_J721E) || defined (SOC_J7200)
#include <ti/csl/src/ip/dss/V4/cslr_dss.h>
#include <ti/csl/src/ip/dss/V4/cslr_dptx.h>
#include <ti/csl/src/ip/dss/V4/cslr_dsi_wrap.h>
#endif /* SOC_XXXXX */

#endif
