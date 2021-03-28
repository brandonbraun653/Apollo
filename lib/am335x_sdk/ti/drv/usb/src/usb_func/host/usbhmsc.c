/****************************************************************************** */
/* usbhmsc.c - USB MSC host driver. */
/****************************************************************************** */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2016
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


#include "types.h"
#include "usb_spec_defines.h"
#include "usblib.h"
#include "usbmsc.h"
#include "usbhost.h"
#include "usbhmsc.h"
#include "usbhscsi.h"
#include "debug.h"

/****************************************************************************** */
/*! \addtogroup usblib_host_class */
/*! @{ */
/****************************************************************************** */

/****************************************************************************** */
/* Forward declarations for the driver open and close calls. */
/****************************************************************************** */
static void *USBHMSCOpen(tUSBHostDevice *pDevice, void* usbClass);
static void USBHMSCClose(void *pvInstance);

extern tUSBHCD g_sUSBHCD[];

/* buffers that's cache line alligned and used 
   for MSC / SCSI buffers */
static uint8_t mscBuffer[512]   __attribute__ ((aligned (128))); 


/****************************************************************************** */
/* The array of USB MSC host drivers. */
/****************************************************************************** */
tUSBHMSCInstance g_USBHMSCDevice[USB_NUM_INSTANCE];


/****************************************************************************** */
/*! This constant global structure defines the Mass Storage Class Driver that */
/*! is provided with the USB library. */
/****************************************************************************** */
const tUSBHostClassDriver g_USBHostMSCClassDriver =
{
    USB_CLASS_MASS_STORAGE,
    USBHMSCOpen,
    USBHMSCClose,
    0
};

/****************************************************************************** */
/*! This function is used to open an instance of the MSC driver. */
/*! */
/*! \param pDevice is a pointer to the device information structure. */
/*! */
/*! This function will attempt to open an instance of the MSC driver based on */
/*! the information contained in the pDevice structure.  This call can fail if */
/*! there are not sufficient resources to open the device.  The function will */
/*! return a value that should be passed back into USBMSCClose() when the */
/*! driver is no longer needed. */
/*! */
/*! \return The function will return a pointer to a MSC driver instance. */
/****************************************************************************** */

void     USBHCDConfigureEndpoints(uint32_t ulIndex, 
                                  tUSBHostDevice *pDevice, 
                                  uint32_t* inPipe, 
                                  uint32_t* outPipe);

static void *
USBHMSCOpen(tUSBHostDevice *pDevice, void* usbClass)
{

    tUSBHMSCInstance *sUSBHMSCDevice;

    sUSBHMSCDevice = (tUSBHMSCInstance *)usbClass;
    
    uint32_t ulIndex = sUSBHMSCDevice->ulIndex;

    /* Don't allow the device to be opened without closing first. */
    if(sUSBHMSCDevice->pDevice)
    {
        return(0);
    }

    /* calling device specific pipe and endpoint setting functions */
    USBHCDConfigureEndpoints(ulIndex, 
                             pDevice, 
                             &sUSBHMSCDevice->ulBulkInPipe,
                             &sUSBHMSCDevice->ulBulkOutPipe);

    /* Save the device pointer. */
    sUSBHMSCDevice->pDevice = pDevice;

    /* Set the SCSI init flag as zero - not ready yet */
    sUSBHMSCDevice->ulDriveReady = 0U;
    
    /* If the callback exists, call it with an Open event. */
    if(sUSBHMSCDevice->pfnCallback != 0)
    {
       sUSBHMSCDevice->pfnCallback(sUSBHMSCDevice,
                                    MSC_EVENT_OPEN, 0);
    }

    /* Return the only instance of this device. */
    return(sUSBHMSCDevice);
}

/****************************************************************************** */
/*! This function is used to release an instance of the MSC driver. */
/*! */
/*! \param pvInstance is an instance pointer that needs to be released. */
/*! */
/*! This function will free up any resources in use by the MSC driver instance */
/*! that is passed in.  The \e pvInstance pointer should be a valid value that */
/*! was returned from a call to USBMSCOpen(). */
/*! */
/*! \return None. */
/****************************************************************************** */
static void
USBHMSCClose(void *pvInstance)
{

    tUSBHMSCInstance *sUSBHMSCDevice;
    sUSBHMSCDevice = (tUSBHMSCInstance *)pvInstance;
        
    /* Do nothing if there is not a driver open. */
    if(sUSBHMSCDevice->pDevice == 0)
    {
        return;
    }

    /* Reset the device pointer. */
    sUSBHMSCDevice->pDevice = 0;
    /* Clear the SCSI init flag as zero so that this device gets re iniited again */
    sUSBHMSCDevice->ulDriveReady = 0U;
    
    /* Free the Bulk IN pipe. */
    if(sUSBHMSCDevice->ulBulkInPipe != 0)
    {
        USBHCDPipeFree(sUSBHMSCDevice->ulIndex, sUSBHMSCDevice->ulBulkInPipe);
    }

    /* Free the Bulk OUT pipe. */
    if(sUSBHMSCDevice->ulBulkOutPipe != 0)
    {
        USBHCDPipeFree(sUSBHMSCDevice->ulIndex, sUSBHMSCDevice->ulBulkOutPipe);
    }

    /* If the callback exists then call it. */
    if(sUSBHMSCDevice->pfnCallback != 0)
    {
       sUSBHMSCDevice->pfnCallback(sUSBHMSCDevice,
                                   MSC_EVENT_CLOSE, 0);
    }
}

/****************************************************************************** */
/*! This function retrieves the maximum number of the logical units on a */
/*! mass storage device. */
/*! */
/*! \param ulAddress is the device address on the USB bus. */
/*! \param ulInterface is the interface number on the device specified by the */
/*! \e ulAddress parameter. */
/*! \param pucMaxLUN is the byte value returned from the device for the */
/*! device's maximum logical unit. */
/*! */
/*! The device will return one byte of data that contains the maximum LUN */
/*! supported by the device.  For example, if the device supports four LUNs */
/*! then the LUNs would be numbered from 0 to 3 and the return value would be */
/*! 3.  If no LUN is associated with the device, the value returned shall be 0. */
/*! */
/*! \return None. */
/****************************************************************************** */
static void
USBHMSCGetMaxLUN(uint32_t ulIndex, uint32_t ulAddress, 
                          uint32_t ulInterface, uint8_t *pucMaxLUN)
{
    tUSBRequest* setupPacket;
    *pucMaxLUN = 0;

    setupPacket = (tUSBRequest*)mscBuffer;
    
    /* This is a Class specific interface IN request. */
    setupPacket->bmRequestType = USB_RTYPE_DIR_IN | 
                                 USB_RTYPE_CLASS | 
                                 USB_RTYPE_INTERFACE;

    /* Request a the Max LUN for this interface. */
    setupPacket->bRequest = USBREQ_GET_MAX_LUN;
    setupPacket->wValue = 0;

    /* Indicate the interface to use. */
    setupPacket->wIndex = (unsigned short)ulInterface;

    /* Only request a single byte of data. */
    setupPacket->wLength = 1;

    /* Put the setup packet in the buffer and send the command. */
    USBHCDControlTransfer(ulIndex, setupPacket, ulAddress, pucMaxLUN,
                          1, MAX_PACKET_SIZE_EP0);
}

/****************************************************************************** */
/*! This function checks if a drive is ready to be accessed. */
/*! */
/*! \param usbClassInstance is the device instance to use for this read. */
/*! */
/*! This function checks if the current device is ready to be accessed. */
/*! It uses the \e ulInstance parameter to determine which device to check and */
/*! will return zero when the device is ready.  Any non-zero return code */
/*! indicates that the device was not ready. */
/*! */
/*! \return This function will return zero if the device is ready and it will */
/*! return a other value if the device is not ready or if an error occurred. */
/****************************************************************************** */
int
USBHMSCDriveReady(void* usbClassInstance)
{
    uint8_t ucMaxLUN = 0;
    uint8_t* pBuffer;
    uint32_t ulSize;
    tUSBHMSCInstance *pMSCDevice;

    pBuffer = mscBuffer;
    memset(pBuffer, 0, SCSI_INQUIRY_DATA_SZ);

    /* Get the instance pointer in a more usable form. */
    pMSCDevice = (tUSBHMSCInstance *)usbClassInstance;

    /* If there is no device present then return an error. */
    if(pMSCDevice->pDevice == 0)
    {
        return(-1);
    }
    /* If there is no device present then return an error. */
     if(1U == pMSCDevice->ulDriveReady )
    {
        return(0);
    }   
  
    /* Get the Maximum LUNs on this device. */
    USBHMSCGetMaxLUN(pMSCDevice->ulIndex, pMSCDevice->pDevice->ulAddress,
                     pMSCDevice->pDevice->ulInterface, &ucMaxLUN);

    /* Save the Maximum number of LUNs on this device. */
    pMSCDevice->ulMaxLUN = ucMaxLUN;

    /* Issue a SCSI Inquiry to get basic information on the device */
    ulSize = SCSI_INQUIRY_DATA_SZ;
    if((USBHSCSIInquiry(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe, 
                        pMSCDevice->ulBulkOutPipe,
                        pBuffer, &ulSize) != SCSI_CMD_STATUS_PASS))
    {
        return(-1);
    }
    /* See if the drive is ready to use. */
    if(USBHSCSITestUnitReady(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe,
                             pMSCDevice->ulBulkOutPipe) != SCSI_CMD_STATUS_PASS)
    {
        /* Get the current sense data from the device to see why it failed */
        /* the Test Unit Ready command. */
        ulSize = SCSI_REQUEST_SENSE_SZ;
        USBHSCSIRequestSense(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe,
                             pMSCDevice->ulBulkOutPipe, pBuffer, &ulSize);    
    }
    
    /*	    */
    /* Send Request Sense agian, return if device returnss command fail  */
    ulSize = SCSI_REQUEST_SENSE_SZ;
    if(USBHSCSIRequestSense(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe, 
                            pMSCDevice->ulBulkOutPipe, pBuffer, &ulSize) 
                            != SCSI_CMD_STATUS_PASS)
    {
        return(-1);
    }

    if((pBuffer[SCSI_RS_SKEY] == SCSI_RS_KEY_UNIT_ATTN) &&
       (pBuffer[SCSI_RS_SKEY_AD_SKEY] == SCSI_RS_KEY_NOTPRSNT))
    {
        return(-1);
    }

    /* Get the size of the drive. */
    ulSize = SCSI_INQUIRY_DATA_SZ;
    if(USBHSCSIReadCapacity(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe, 
                            pMSCDevice->ulBulkOutPipe,
                            pBuffer, &ulSize) != SCSI_CMD_STATUS_PASS)
    {
        /* Get the current sense data from the device to see why it failed */
        /* the Read Capacity command. */
        ulSize = SCSI_REQUEST_SENSE_SZ;
        USBHSCSIRequestSense(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe,
                             pMSCDevice->ulBulkOutPipe, pBuffer, &ulSize);
        return(-1);
    }
    else
    {
        /* Read the block size out, value is stored big endian. */
        pMSCDevice->ulBlockSize =
            (pBuffer[7] | (pBuffer[6] << 8) | pBuffer[5] << 16 |
             (pBuffer[4] << 24));

        /* Read the block size out. */
        pMSCDevice->ulNumBlocks =
            (pBuffer[3] | (pBuffer[2] << 8) | pBuffer[1] << 16 |
             (pBuffer[0] << 24));
    }
   
    /* Check whether unit is ready again */
    if(USBHSCSITestUnitReady(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe,
                             pMSCDevice->ulBulkOutPipe) != SCSI_CMD_STATUS_PASS)
    {
        /* Get the current sense data from the device to see why it failed */
        /* the Test Unit Ready command. */
        ulSize = SCSI_REQUEST_SENSE_SZ;
        USBHSCSIRequestSense(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe,
                             pMSCDevice->ulBulkOutPipe, pBuffer, &ulSize);
        return(-1);
    }	
    else
    {
        debug_printf("%s:%d. Set Drive ready !\n", __FUNCTION__, __LINE__);

        /* Success. */
        /* Set the SCSI init flag as 1 so that this device does not get re inited  */
        /* Some non standard drives fail when this happens. */
        pMSCDevice->ulDriveReady = 1U;    
        return(0);
    }
}

/****************************************************************************** */
/*! This function should be called before any devices are present to enable */
/*! the mass storage device class driver. */
/*! */
/*! \param ulDrive is the drive number to open. */
/*! \param pfnCallback is the driver callback for any mass storage events. */
/*! */
/*! This function is called to open an instance of a mass storage device.  It */
/*! should be called before any devices are connected to allow for proper */
/*! notification of drive connection and disconnection.  The \e ulDrive */
/*! parameter is a zero based index of the drives present in the system. */
/*! There are a constant number of drives, and this number should only */
/*! be greater than 0 if there is a USB hub present in the system.  The */
/*! application should also provide the \e pfnCallback to be notified of mass */
/*! storage related events like device enumeration and device removal. */
/*! */
/*! \return This function will return the driver instance to use for the other */
/*! mass storage functions.  If there is no driver available at the time of */
/*! this call, this function will return zero. */
/****************************************************************************** */
tUSBHMSCInstance* 
USBHMSCDriveOpen(uint32_t ulIndex, uint32_t ulDrive, 
                            tUSBHMSCCallback pfnCallback)
{
    memset(&g_USBHMSCDevice[ulDrive], 0, sizeof(g_USBHMSCDevice[ulDrive]));

    /* Save the callback. */
    g_USBHMSCDevice[ulDrive].pfnCallback = pfnCallback;
    

    g_USBHMSCDevice[ulDrive].ulIndex = ulIndex;

    /* Return the requested device instance. */
    return &(g_USBHMSCDevice[ulDrive]);
}

/****************************************************************************** */
/*! This function should be called to release a drive instance. */
/*! */
/*! \param ulInstance is the device instance that is to be released. */
/*! */
/*! This function is called when an MSC drive is to be released in preparation */
/*! for shutdown or a switch to USB device mode, for example.  Following this */
/*! call, the drive is available for other clients who may open it again using */
/*! a call to USBHMSCDriveOpen(). */
/*! */
/*! \return None. */
/****************************************************************************** */
void
USBHMSCDriveClose(void* usbClassInstance)
{
    tUSBHMSCInstance *pMSCDevice;

    /* Get a pointer to the device instance data from the handle. */
    pMSCDevice = (tUSBHMSCInstance *)usbClassInstance;

    /* Close the drive (if it is already open) */
    USBHMSCClose((void *)pMSCDevice);

    /* Clear the callback indicating that the device is now closed. */
    pMSCDevice->pfnCallback = 0;
}

/****************************************************************************** */
/*! This function performs a block read to an MSC device. */
/*! */
/*! \param ulInstance is the device instance to use for this read. */
/*! \param ulLBA is the logical block address to read on the device. */
/*! \param pucData is a pointer to the returned data buffer. */
/*! \param ulNumBlocks is the number of blocks to read from the device. */
/*! */
/*! This function will perform a block sized read from the device associated */
/*! with the \e ulInstance parameter.  The \e ulLBA parameter specifies the */
/*! logical block address to read on the device.  This function will only */
/*! perform \e ulNumBlocks block sized reads.  In most cases this is a read */
/*! of 512 bytes of data.  The \e *pucData buffer should be at least */
/*! \e ulNumBlocks * 512 bytes in size. */
/*! */
/*! \return The function returns zero for success and any negative value */
/*! indicates a failure. */
/****************************************************************************** */
int
USBHMSCBlockRead(void* usbClassInstance, uint32_t ulLBA,
                 uint8_t *pucData, uint32_t ulNumBlocks)
{
    tUSBHMSCInstance *pMSCDevice;
    uint32_t ulSize;

    /* Get the instance pointer in a more usable form. */
    pMSCDevice = (tUSBHMSCInstance *)usbClassInstance;

    /* If there is no device present then return an error. */
    if(pMSCDevice->pDevice == 0)
    {
        return(-1);
    }

    /* Calculate the actual byte size of the read. */
    ulSize = pMSCDevice->ulBlockSize * ulNumBlocks;

    /* Perform the SCSI read command. */
    if(USBHSCSIRead10(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe, 
                      pMSCDevice->ulBulkOutPipe, ulLBA, pucData, &ulSize,
                      ulNumBlocks) != SCSI_CMD_STATUS_PASS)
    {
        return(-1);
    }

    /* Success. */
    return(0);
}

/****************************************************************************** */
/*! This function performs a block write to an MSC device. */
/*! */
/*! \param ulInstance is the device instance to use for this write. */
/*! \param ulLBA is the logical block address to write on the device. */
/*! \param pucData is a pointer to the data to write out. */
/*! \param ulNumBlocks is the number of blocks to write to the device. */
/*! */
/*! This function will perform a block sized write to the device associated */
/*! with the \e ulInstance parameter.  The \e ulLBA parameter specifies the */
/*! logical block address to write on the device.  This function will only */
/*! perform \e ulNumBlocks block sized writes.  In most cases this is a write */
/*! of 512 bytes of data.  The \e *pucData buffer should contain at least */
/*! \e ulNumBlocks * 512 bytes in size to prevent unwanted data being written */
/*! to the device. */
/*! */
/*! \return The function returns zero for success and any negative value */
/*! indicates a failure. */
/****************************************************************************** */
int
USBHMSCBlockWrite(void* usbClassInstance, uint32_t ulLBA,
                  uint8_t *pucData, uint32_t ulNumBlocks)
{
    tUSBHMSCInstance *pMSCDevice;
    uint32_t ulSize;

    /* Get the instance pointer in a more usable form. */
    pMSCDevice = (tUSBHMSCInstance *)usbClassInstance;

    /* If there is no device present then return an error. */
    if(pMSCDevice->pDevice == 0)
    {
        return(-1);
    }

    /* Calculate the actual byte size of the write. */
    ulSize = pMSCDevice->ulBlockSize * ulNumBlocks;

    /* Perform the SCSI write command. */
    if(USBHSCSIWrite10(pMSCDevice->ulIndex, pMSCDevice->ulBulkInPipe, 
                       pMSCDevice->ulBulkOutPipe, ulLBA, pucData, &ulSize,
                       ulNumBlocks) != SCSI_CMD_STATUS_PASS)
    {
        return(-1);
    }

    /* Success. */
    return(0);
}

/****************************************************************************** */
/* Close the Doxygen group. */
/*! @} */
/****************************************************************************** */
