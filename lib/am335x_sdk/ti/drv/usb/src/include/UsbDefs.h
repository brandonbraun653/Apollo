/*
*   Description: This file contains definitions for the USB module
*/
/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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

#ifndef _USBHOST_H_
#define _USBHOST_H_

#ifdef __cplusplus
extern "C" {
#endif

#define USB_HOST_OUT            0
#define USB_HOST_IN             1

#define USB_FEATURE_EP_HALT 0x0000

#define USB_RTYPE_DIR_IN        0x80
#define USB_RTYPE_DIR_OUT       0x00

#define USB_RTYPE_TYPE_M        0x60
#define USB_RTYPE_VENDOR        0x40
#define USB_RTYPE_CLASS         0x20
#define USB_RTYPE_STANDARD      0x00

#define USB_RTYPE_RECIPIENT_M   0x1f
#define USB_RTYPE_OTHER         0x03
#define USB_RTYPE_ENDPOINT      0x02
#define USB_RTYPE_INTERFACE     0x01
#define USB_RTYPE_DEVICE        0x00

#define USB_DEV_DESC_EP0_SIZE_OFFSET 0x7

//Defined in a way to directly use it for TYPE register of musb

//Types of Transfers

// conflicting and redefined compared to usb.h
//#define USB_TRANS_SETUP 		0x0A //Setupand TxPktReady Seet
//#define USB_TRANS_OUT           0x01 //TXPktRdySet

#define USB_HOST_EP0_RXPKTRDY   0x00000001  // Receive data packet ready
#define USB_HOST_EP0_TXPKTRDY   0x00000002  // Receive data packet ready
#define USB_HOST_EP0_STATUS     0x00000040  // This was a status packet

#define USB_HOST_DEVICE_ADDRESS         0x01
#define USB_HOST_DEVICE_CONFIGURATION   0x01

#define USB_HOST_BULK_OUT_EP_FIFOSTART 	0x040
#define USB_HOST_BULK_IN_EP_FIFOSTART  	0x240
#define USB_HOST_BULK_OUT_EP_FIFOSIZE 		0x06 //DPB 1 and size of 2K
#define USB_HOST_BULK_IN_EP_FIFOSIZE 		0x06 //DPB 1 ans size of 2K


//Mass storage specific defines
#define USB_INTERFACE_CLASS_MSC		0x8
#define USB_INTERFACE_PROTOCOL_MASS_STORAGE	0x50
#define USB_INTERFACE_SUBCLASS_RBC	0x1
#define USB_INTERFACE_SUBCLASS_SCSI 0x6
#define USB_MIN_ENDPOINT_MSC_BOT	0x2

#define USB_EP_ATTR_BULK			0x02
#define USB_EP_ATTR_INTR			0x03
#define USB_EP_ATTR_TYPE_MASK       0x03

#define USB_EP_DESC_DIR_IN			0x80

#define USBH_BOOTING_FILE        "MLO        "

#define USB_DESCRIPTOR_TYPE_CONFIG		0x2
#define USB_DESCRIPTOR_TYPE_INTERFACE	0x4

//#define USB_HOST_RTL_SIMULATION   1

//No of retries of Test Unit Ready Command of SCSI
#define USB_HOST_TUR_RETRY_COUNT  10



//*****************************************************************************
//
//! This structure describes the USB configuration descriptor as defined in
//! USB 2.0 specification section 9.6.3.  This structure also applies to the
//! USB other speed configuration descriptor defined in section 9.6.4.
//
//*****************************************************************************
 typedef struct __attribute__((packed))
{
    //
    //! The length of this descriptor in bytes.  All configuration descriptors
    //! are 9 bytes long.
    //
    unsigned char bLength;

    //
    //! The type of the descriptor.  For a configuration descriptor, this will
    //! be USB_DTYPE_CONFIGURATION (2).
    //
    unsigned char bDescriptorType;

    //
    //! The total length of data returned for this configuration.  This
    //! includes the combined length of all descriptors (configuration,
    //! interface, endpoint and class- or vendor-specific) returned for this
    //! configuration.
    //
    unsigned short wTotalLength;

    //
    //! The number of interface supported by this configuration.
    //
    unsigned char bNumInterfaces;

    //
    //! The value used as an argument to the SetConfiguration standard request
    //! to select this configuration.
    //
    unsigned char bConfigurationValue;

    //
    //! The index of a string descriptor describing this configuration.
    //
    unsigned char iConfiguration;

    //
    //! Attributes of this configuration.
    //
    unsigned char bmAttributes;

    //
    //! The maximum power consumption of the USB device from the bus in this
    //! configuration when the device is fully operational.  This is expressed
    //! in units of 2mA so, for example, 100 represents 200mA.
    //
    unsigned char bMaxPower;
}
 tConfigDescriptor_t ;

typedef struct __attribute__((packed))
 {
     //
     //! The length of this descriptor in bytes.  All interface descriptors
     //! are 9 bytes long.
     //
     unsigned char bLength;

     //
     //! The type of the descriptor.  For an interface descriptor, this will
     //! be USB_DTYPE_INTERFACE (4).
     //
     unsigned char bDescriptorType;

     //
     //! The number of this interface.  This is a zero based index into the
     //! array of concurrent interfaces supported by this configuration.
     //
     unsigned char bInterfaceNumber;

     //
     //! The value used to select this alternate setting for the interface
     //! defined in bInterfaceNumber.
     //
     unsigned char bAlternateSetting;

     //
     //! The number of endpoints used by this interface (excluding endpoint
     //! zero).
     //
     unsigned char bNumEndpoints;

     //
     //! The interface class code as assigned by the USB-IF.
     //
     unsigned char bInterfaceClass;

     //
     //! The interface subclass code as assigned by the USB-IF.
     //
     unsigned char bInterfaceSubClass;

     //
     //! The interface protocol code as assigned by the USB-IF.
     //
     unsigned char bInterfaceProtocol;

     //
     //! The index of a string descriptor describing this interface.
     //
     unsigned char iInterface;
 }
 tInterfaceDescriptor_t;


  typedef struct __attribute__((packed))
 {
     //
     //! The length of this descriptor in bytes.  All endpoint descriptors
     //! are 7 bytes long.
     //
     unsigned char bLength;

     //
     //! The type of the descriptor.  For an endpoint descriptor, this will
     //! be USB_DTYPE_ENDPOINT (5).
     //
     unsigned char bDescriptorType;

     //
     //! The address of the endpoint.  This field contains the endpoint number
     //! ORed with flag USB_EP_DESC_OUT or USB_EP_DESC_IN to indicate the
     //! endpoint direction.
     //
     unsigned char bEndpointAddress;

     //
     //! The endpoint transfer type, USB_EP_ATTR_CONTROL, USB_EP_ATTR_ISOC,
     //! USB_EP_ATTR_BULK or USB_EP_ATTR_INT and, if isochronous, additional
     //! flags indicating usage type and synchronization method.
     //
     unsigned char bmAttributes;

     //
     //! The maximum packet size this endpoint is capable of sending or
     //! receiving when this configuration is selected.  For high speed
     //! isochronous or interrupt endpoints, bits 11 and 12 are used to
     //! pass additional information.
     //
     unsigned short wMaxPacketSize;

     //
     //! The polling interval for data transfers expressed in frames or
     //! micro frames depending upon the operating speed.
     //
     unsigned char bInterval;
 }
tEndpointDescriptor_t ; 

#ifdef __cplusplus
}
#endif

#endif //USBHOST_H
