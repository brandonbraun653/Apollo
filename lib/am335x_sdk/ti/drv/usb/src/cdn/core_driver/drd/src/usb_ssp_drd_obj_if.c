/**********************************************************************
 * Copyright (C) 2012-2019 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************
 * WARNING: This file is auto-generated using api-generator utility.
 *          api-generator: 13.04.5beed88
 *          Do not edit it manually.
 **********************************************************************
 * Cadence Core Driver for USB SSP DRD
 **********************************************************************/

#include "usb_ssp_drd_obj_if.h"

/* parasoft suppress item METRICS-41-3 "Number of blocks of comments per statement, DRV-4926" */

USB_SSP_DRD_OBJ *USB_SSP_DRD_GetInstance(void)
{
    static USB_SSP_DRD_OBJ driver =
    {
        .Probe = USB_SSP_DRD_Probe,
        .Init = USB_SSP_DRD_Init,
        .Isr = USB_SSP_DRD_Isr,
        .Start = USB_SSP_DRD_Start,
        .Stop = USB_SSP_DRD_Stop,
        .Destroy = USB_SSP_DRD_Destroy,
        .CheckIfReady = USB_SSP_DRD_CheckIfReady,
        .CheckStrapMode = USB_SSP_DRD_CheckStrapMode,
        .CheckOperationMode = USB_SSP_DRD_CheckOperationMode,
        .SetOperationMode = USB_SSP_DRD_SetOperationMode,
        .CheckIrq = USB_SSP_DRD_CheckIrq,
        .ProcessIrq = USB_SSP_DRD_ProcessIrq,
    };

    return &driver;
}
