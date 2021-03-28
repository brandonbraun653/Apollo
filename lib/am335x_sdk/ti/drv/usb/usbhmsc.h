/****************************************************************************** */
/* usbhmsc.h - Definitions for the USB MSC host driver.                         */
/****************************************************************************** */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2019
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


#ifndef PDK__USBHMSC_H
#define PDK__USBHMSC_H

#include "usbhost.h"
/****************************************************************************** */
/* If building with a C++ compiler, make all of the definitions in this header  */
/* have a C binding.                                                            */
/****************************************************************************** */
#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************** */
/*! \addtogroup usblib_host_class */
/*! @{ */
/****************************************************************************** */

/****************************************************************************** */
/* These defines are the the events that will be passed in the \e ulEvent       */
/* parameter of the callback from the driver.                                   */
/****************************************************************************** */
#define MSC_EVENT_OPEN          1
#define MSC_EVENT_CLOSE         2

/****************************************************************************** */
/* The prototype for the USB MSC host driver callback function.                 */
/****************************************************************************** */
typedef void (*tUSBHMSCCallback)(void* usbClasslInstance,
                                 uint32_t ulEvent,
                                 void *pvEventData);

/****************************************************************************** */
/* This is the structure for an instance of a USB MSC host driver.              */
/****************************************************************************** */
typedef struct
{
    /* Save the device instance. */
    tUSBHostDevice *pDevice;

    /* Used to save the callback. */
    tUSBHMSCCallback pfnCallback;

    /* drive ready flag marked as 1 once SCSI init is complete */
    uint32_t ulDriveReady;
    
    /* The Maximum LUNs */
    uint32_t ulMaxLUN;

    /* The total number of blocks associated with this device. */
    uint32_t ulNumBlocks;

    /* The size of the blocks associated with this device. */
    uint32_t ulBlockSize;

    /* Bulk IN pipe. */
    uint32_t ulBulkInPipe;

    /* Bulk OUT pipe. */
    uint32_t ulBulkOutPipe;

    /*HCD Index. */
    uint32_t ulIndex;
}
tUSBHMSCInstance;


/****************************************************************************** */
/* Prototypes for the USB MSC host driver APIs. */
/****************************************************************************** */
extern tUSBHMSCInstance*
USBHMSCDriveOpen    (uint32_t ulIndex,
                     uint32_t ulDrive,
                     tUSBHMSCCallback pfnCallback);

extern void USBHMSCDriveClose(void* usbClassInstance);
extern int USBHMSCDriveReady(void* ulInstance);
extern int USBHMSCBlockRead(void* usbClassInstance, 
                            uint32_t ulLBA,
                            unsigned char *pucData,
                            uint32_t ulNumBlocks);

extern int USBHMSCBlockWrite(void* usbClassInstance, 
                             uint32_t ulLBA,
                             unsigned char *pucData,
                             uint32_t ulNumBlocks);

/****************************************************************************** */
/*! @} */
/****************************************************************************** */

/****************************************************************************** */
/* Mark the end of the C bindings section for C++ compilers. */
/****************************************************************************** */
#ifdef __cplusplus
}
#endif

#endif /* PDK__USBHMSC_H */
