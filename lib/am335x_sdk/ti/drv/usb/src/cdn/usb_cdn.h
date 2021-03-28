/**
 *  \file     usb_cdn.h
 *
 *  \brief    This file contains APIs and DWC specifici data 
 *
 *  \copyright Copyright (C) 2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"

#include "cusb_ch9_if.h"
#include "cusb_ch9_structs_if.h"
#include "cusbd_if.h"
#include "cusbd_obj_if.h"
#include "cusbd_structs_if.h"
#include "cusbdma_if.h"
#include "cusbdma_structs_if.h"


#ifdef USE_CDN_XHCI
#include "cdn_xhci_structs_if.h"
#include "cdn_xhci_if.h"
#else
#include "usb_hcd_xhci.h"
#endif

#include "usb_cdn_dcd.h"
#include "usb_drv.h"

#include "usblib.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef union 
{
    /* The cdn driver object */
    usbCdnDcdDevice_t   cdnDcd; 

    /* xhci global data */
#ifdef USE_CDN_XHCI
    USBSSP_DriverResourcesT xhci_driver_resources;
#else
    XHCI_DATA_S             xhciData;
#endif 
} drv_instance_u;


typedef struct usb_mem {
    drv_instance_u      drv_instances[USB_NUM_INSTANCE];
} USB_MEM_S; 



USB_Handle   USB_open_cdn(USB_Handle handle, USB_Params *params);
void         USB_irqConfig_cdn(USB_Handle handle, USB_Params* params);
void         USB_irqCore_cdn(USB_Handle handle, USB_Params* params);
void         USB_irqMisc_cdn(USB_Handle handle, USB_Params* params);

#ifdef __cplusplus
}
#endif

