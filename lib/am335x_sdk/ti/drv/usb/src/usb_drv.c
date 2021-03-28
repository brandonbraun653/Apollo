/**
 * @file   USB_drv.c
 *
 * @brief  This file contains the USB driver interface APIs
 *         These APIs are used for configuration of instance
 *         transmission and reception of data.
 */
/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
/*
 *  ======== usb_drv.c ========
 */

#include <stdint.h>
#include <ti/drv/usb/usb_drv.h>

/* Externs */
extern USB_Config USB_config[];

/* Used to check status and initialization */


/*
 *  ======== USB_open ========
 */
USB_Handle USB_open(unsigned int index, USB_Params *params)
{
    USB_Handle         handle;

    /* Get handle for this driver instance */
    handle = (USB_Handle)&(USB_config[index]);

    return (handle->fxnTablePtr->openFxn(handle, params));
}


/*
 *  ======== USB_irqConfig ========
 */
void USB_irqConfig(USB_Handle handle, USB_Params *params)
{
    handle->fxnTablePtr->irqConfigFxn(handle, params);
}

/*
 *  ======== USB_miscIrqHandler ========
 */
void USB_miscIrqHandler(USB_Handle handle, USB_Params *params)
{
    handle->fxnTablePtr->irqMiscFxn(handle, params);
}


/*
 *  ======== USB_coreIrqHandler ========
 */
void USB_coreIrqHandler(USB_Handle handle, USB_Params *params)
{
    handle->fxnTablePtr->irqCoreFxn(handle, params);
}

