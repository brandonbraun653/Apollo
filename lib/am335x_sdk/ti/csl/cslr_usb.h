/*
 * Copyright (C) 2012-2019 Texas Instruments Incorporated - http://www.ti.com/
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
* file: cslr_usb.h
*
* Brief: This file contains the Register Description for usb
*
*********************************************************************/
#ifndef CSLR_USB_TOP_H_
#define CSLR_USB_TOP_H_
#ifdef __cplusplus
extern "C"{
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#if defined(SOC_K2G)
#include <ti/csl/src/ip/usb/V0/cslr_usb3ss.h>
#include <ti/csl/src/ip/usb/V0/cslr_usb3ss_dwc.h>
#include <ti/csl/src/ip/usb/V0/cslr_usb3ss_phy.h>
#elif defined(SOC_AM65XX)
#include <ti/csl/src/ip/usb/V4/cslr_usb3ss.h>
#elif defined(SOC_AM574x) || defined(SOC_AM572x) || defined(SOC_AM571x)
#include <ti/csl/src/ip/usb/V1/cslr_dwc_usb3.h>
#include <ti/csl/src/ip/usb/V1/cslr_dwc_ahsata.h>
#include <ti/csl/src/ip/usb/V1/cslr_usb_top.h>
#include <ti/csl/src/ip/usb/V1/cslr_usb2phy.h>
#elif defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#include <ti/csl/src/ip/usb/V3/cslr_usb_ohci.h>
#include <ti/csl/src/ip/usb/V3/cslr_usb_otg.h>
#elif defined(SOC_AM6X)
#include <ti/csl/src/ip/usb/V4/cslr_usb3ss.h>
#elif defined(SOC_J721E) || defined(SOC_AM77X)
#include <ti/csl/src/ip/usb/V5/cslr_usb3p0ss.h>
#elif defined (SOC_J7200)
#include <ti/csl/src/ip/usb/V6/cslr_usb3p0ss.h>
#else /* SOC_K2H/K2L/K2E */
#include <ti/csl/src/ip/usb/V1/cslr_usb3ss_g.h>
#endif /* SOC_XXXXX */

#ifdef __cplusplus
}
#endif
#endif
