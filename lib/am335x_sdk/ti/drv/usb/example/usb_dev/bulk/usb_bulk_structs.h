//*****************************************************************************
//
// usb_bulk_structs.h - Data structures defining this bulk USB device.
//
// This is part of revision 6288 of the DK-LM3S9B96 Firmware Package.
//
//*****************************************************************************

/*
* Copyright (C) 2010-2018 Texas Instruments Incorporated - http://www.ti.com/ 
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

#ifndef _USB_BULK_STRUCTS_H_
#define _USB_BULK_STRUCTS_H_

extern const tUSBDBulkDevice g_sBulkDevice;

extern uint32_t
usbdbulkEventCallback(struct usbGadgetObj *pGadgetObject,
                       void *pvCBData, uint32_t ulEvent,
                       uint32_t ulMsgValue, void *pvMsgData);

/** \brief USB packet length */
#define USB_PACKET_LENGTH       (512)

/** \brief USB transfer size for transfer of data */
#define MAX_TRANSFER_SIZE       USB_PACKET_LENGTH

#define CACHE_LINE_SIZE         (128)

extern uint8_t g_bulkTxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));
extern uint8_t g_bulkRxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));

#endif
