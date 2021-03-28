/**
 * @file   omapl138/USB_soc.c
 *
 * @brief  This file defines the USB interface structure specific to OMAPL138
 */
/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================*/

#include "types.h"
#include "error.h"

/* pdk includes */
#include <ti/drv/usb/usb_drv.h>



/* USB_musb functions */
USB_Handle   USB_open_musb(USB_Handle handle, USB_Params *params);
void         USB_irqConfig_musb(USB_Handle handle, USB_Params* params);
void         USB_irqCore_musb(USB_Handle handle, USB_Params* params);
void         USB_irqMisc_musb(USB_Handle handle, USB_Params* params);

/* USB interface function table for USB_musb (Synopsys) implementation */
const USB_FxnTable USB_FxnTable_musb = {
    USB_open_musb,
    USB_irqConfig_musb,
    USB_irqCore_musb,
    USB_irqMisc_musb
};


/* USB configuration structure - for each of
 * the USB instances + the null terminate entry */
USB_Config USB_config[3] = {
    {
        &USB_FxnTable_musb,
        0
    },

    {
        &USB_FxnTable_musb,
        0
    },

    {NULL, 0}
};
