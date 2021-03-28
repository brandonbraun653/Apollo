/**
 * \file  k2g/hw_usb.h
 *
 * \brief Macros for use in accessing the USB registers.
 */

/*
* Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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


#ifndef __HW_USB_H__
#define __HW_USB_H__


#include <ti/csl/cslr_bootcfg.h>
#include <ti/csl/cslr_usb.h>

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//
// The following are defines for the Univeral Serial Bus register offsets.
//
//*****************************************************************************

#ifdef  SOC_K2G
#define USB0_DWC_WRAPPER_BASE_ADDR          (0x02680000U)
#define USB1_DWC_WRAPPER_BASE_ADDR          (0x02580000U)
#define USB_DWC_CORE_OFFSET                 (0x10000U)

#define USB_DWC3_WRAPPER_BASE_ADDR(n)       ((n==0)?USB0_DWC_WRAPPER_BASE_ADDR:\
                                            USB1_DWC_WRAPPER_BASE_ADDR)

/* USB phy control registers */
#define USB_BOOTCFG_USB_PHYCTL(port, reg)   (0x2620738U+((port)*0x18U)+((reg)*4))
#define USB_BOOTCFG_USB_CLKCTL(x)           (0x262069CU+((x)*4))

#endif /* SOC_K2G */

#ifdef __cplusplus
}
#endif

#endif // __HW_USB_H__
