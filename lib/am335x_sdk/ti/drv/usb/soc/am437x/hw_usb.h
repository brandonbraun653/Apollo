/**
 * \file  am437x/hw_usb.h
 *
 * \brief Macros for use in accessing the USB registers.
 */

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
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


#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//
// The following are defines for the Univeral Serial Bus register offsets.
//
//*****************************************************************************

#if defined(AM43XX_FAMILY_BUILD)
#define USB0_DWC_WRAPPER_BASE_ADDR      (0x48380000)
#define USB1_DWC_WRAPPER_BASE_ADDR      (0x483C0000)
#define USB_DWC_CORE_OFFSET             (0x10000)


#define USB_DWC3_WRAPPER_BASE_ADDR(n)   ((n==0)?USB0_DWC_WRAPPER_BASE_ADDR:\
                                         USB1_DWC_WRAPPER_BASE_ADDR)

/* interrupt numbers */
#define SYS_INT_USB0                    200     /* USB0_MAIN0_INT */
#define SYS_INT_USBSS0INT               204     /* USB0_MISC_INT */

#define SYS_INT_USB1                    206
#define SYS_INT_USBSS1INT               210
#endif

#ifdef __cplusplus
}
#endif

#endif // __HW_USB_H__
