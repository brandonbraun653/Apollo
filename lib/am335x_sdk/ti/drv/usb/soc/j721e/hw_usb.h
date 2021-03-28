/**
 * \file  j721e/hw_usb.h
 *
 * \brief Macros for use in accessing the USB registers.
 */

/*
* Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef PDK__HW_USB_H
#define PDK__HW_USB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr_usb.h>    /* USBSS registers */
#include <ti/csl/soc.h>         /* Base addresses */

/******************************************************************************
 *
 * The following are defines for the Univeral Serial Bus register offsets.
 *
 *****************************************************************************/

#define USB0_CDN_WRAPPER_BASE_ADDR      (CSL_USB0_VBP2APB_WRAP_CONTROLLER_VBP_CORE_ADDR_MAP_BASE) 
                                        /* 0x06000000ul */

#define USB1_CDN_WRAPPER_BASE_ADDR      (CSL_USB1_VBP2APB_WRAP_CONTROLLER_VBP_CORE_ADDR_MAP_BASE) 
                                        /* 0x06400000ul */

#define USB0_XHCI_WRAPPER_BASE_ADDR     USB0_CDN_WRAPPER_BASE_ADDR
#define USB1_XHCI_WRAPPER_BASE_ADDR     USB1_CDN_WRAPPER_BASE_ADDR

#define USB_XHCI_CORE_OFFSET            ((uint32_t)0x10000U)


#define USB0_USB_PHY_BASE_ADDR          ((uint32_t)CSL_USB0_PHY2_BASE)
#define USB1_USB_PHY_BASE_ADDR          ((uint32_t)CSL_USB1_PHY2_BASE)


#define USB_CDN_BASE_ADDR(n)            (((n)==0)?(USB0_CDN_WRAPPER_BASE_ADDR):\
                                         (USB1_CDN_WRAPPER_BASE_ADDR))

/* interrupt numbers */
#define SYS_INT_USB0                    ((uint32_t)CSL_GIC0_INTR_USB3SS0_BUS_I00_LVL) /* main MPU IRQ */
#define SYS_INT_USBSS0INT               ((uint32_t)CSL_GIC0_INTR_USB3SS0_BUS_MISC_LVL) /* misc MPU_IRQ */

#define SYS_INT_USB1                    ((uint32_t)CSL_GIC0_INTR_USB3SS1_BUS_I00_LVL) /* main MPU_IRQ */
#define SYS_INT_USBSS1INT               ((uint32_t)CSL_GIC0_INTR_USB3SS1_BUS_MISC_LVL) /* misc MPU_IRQ */

#ifdef __cplusplus
}
#endif

#endif /* PDK__HW_USB_H */
