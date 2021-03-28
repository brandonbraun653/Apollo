/**
 *  \file  usbmsc.h
 *
 *  \brief USB Mass storage device class driver.
 *
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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

#ifndef USBDMSC_H_
#define USBDMSC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C"
{
#endif
#include "usblib.h"
#include "usb_dev_object.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief These defines control the sizes of USB transfers for data and
 *         commands.
 */
#define DEVICE_BLOCK_SIZE       512

/**
 * \brief The size of the memory that should be allocated to create a configuration
 * descriptor for a single instance of the USB Audio Device.
 * This does not include the configuration descriptor which is automatically
 * ignored by the composite device class.
 *
 * For reference this is sizeof(g_pAudioControlInterface) +
 * sizeof(g_pAudioStreamInterface
 */
#define COMPOSITE_DMSC_SIZE   (23)

/* MSC-specific device class driver events */

/** \brief This event indicates that the host has completed other operations
 *         and is no longer accessing the device.
 */
#define USBD_MSC_EVENT_IDLE     (USBD_MSC_EVENT_BASE + 0)

/** \brief This event indicates that the host is reading the storage media.
 */
#define USBD_MSC_EVENT_READING  (USBD_MSC_EVENT_BASE + 1)

/** \brief This event indicates that the host is writing to the storage media. */
#define USBD_MSC_EVENT_WRITING  (USBD_MSC_EVENT_BASE + 2)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/**
 * \brief This enum enumerates the media status values
 *        for USB MSC class
 */
typedef enum
{
    USBDMSC_MEDIA_PRESENT,
    /**< Media present */
    USBDMSC_MEDIA_NOTPRESENT,
    /**< Media Not present */
    USBDMSC_MEDIA_UNKNOWN
    /**< Media unknown */
}
tUSBDMSCMediaStatus;

/**
 * \brief This structure contains the media access functions to be used
 *        by the MSC class driver.
 */
typedef struct
{
    void *(* Open)(uint32_t ulDrive);
    /**< This function is used to initialize and open the physical drive number
     * associated with the parameter ulDrive.  The function will return zero if
     * the drive could not be opened for some reason.  In the case of removable
     * device like an SD card this function should return zero if the SD card
     * is not present.
     * The function returns a pointer to data that should be passed to other
     * APIs or it will return 0 if no drive was found.
     */

    void (* Close)(void * pvDrive);
    /**< This function close the drive number in use by the mass storage class device.
     *
     * \param pvDrive is the pointer that was returned from a call to
     * USBDMSCStorageOpen().
     *
     * This function is used to close the physical drive number associated with the
     * parameter /e pvDrive.  This function will return 0 if the drive was closed
     * successfully and any other value will indicate a failure.
     *
     * \retval Returns 0 if the drive was successfully closed or non-zero for a
     * failure.
     */

    uint32_t (* BlockRead)(void * pvDrive, uint8_t *pucData,
                                uint32_t ulSector,
                                uint32_t ulNumBlocks);
    /**< This function will read a block from a device opened by the
     * USBDMSCStorageOpen() call.
     *
     * \param pvDrive is the pointer that was returned from a call to
     *        USBDMSCStorageOpen().
     * \param pucData is the buffer that data will be written into.
     * \param ulSector is the block address to read.
     * \param ulNumBlocks is the number of blocks to read.
     *
     * This function is use to read blocks from a physical device and return them
     * in the /e pucData buffer.  The data area pointed to by /e pucData should be
     * at least /e ulNumBlocks * Block Size bytes to prevent overwriting data.
     *
     * \retval Returns the number of bytes that were read from the device.
     */

    uint32_t (* BlockWrite)(void * pvDrive, uint8_t *pucData,
                                 uint32_t ulSector,
                                 uint32_t ulNumBlocks);
    /**< This function will write a block to a device opened by the
     *   USBDMSCStorageOpen() call.
     *
     * \param pvDrive is the pointer that was returned from a call to
     * USBDMSCStorageOpen().
     * \param pucData is the buffer that data will be used for writing.
     * \param ulNumBlocks is the number of blocks to write.
     *
     * This function is use to write blocks to a physical device from the buffer
     * pointed to by the /e pucData buffer.  If the number of blocks is greater than
     * one then the block address will increment and write to the next block until
     * /e ulNumBlocks * Block Size bytes have been written.
     *
     * \retval Returns the number of bytes that were written to the device.
     */

    uint32_t (* NumBlocks)(void * pvDrive);
    /**< This function will return the number of blocks present on a device.
     *
     * \param pvDrive is the pointer that was returned from a call to
     * USBDMSCStorageOpen().
     *
     * This function is used to return the total number of blocks on a physical
     * device based on the /e pvDrive parameter.
     *
     * /retval Returns the number of blocks that are present in a device.
     */
} tMSCDMedia;

/** \brief This structure defines the private instance data and state variables for the
 *         mass storage class.  The memory for this structure is pointed to by
 *         the psPrivateData field in the tUSBDMSCDevice structure passed on
 *         USBDMSCInit() and should not be modified by any code outside of the mass
 *         storage device code.
 */

typedef struct
{
    uint32_t ulUSBBase;
    tDeviceInfo *psDevInfo;
    tConfigDescriptor *psConfDescriptor;

    struct usbGadgetObj * pUsbGadgetObj;

    /** These three values are used to return the current sense data for an
     * instance of the mass storage class.
     */
    uint8_t ucErrorCode;
    uint8_t ucSenseKey;
    uint16_t usAddSenseCode;

    void *pvMedia;
    /**< The pointer to the instance returned from the Open call to the media.
     */

    volatile uint32_t bConnected;

    uint32_t ulFlags;
    /**< Holds the flag settings for this instance.
     */

    tUSBDMSCMediaStatus eMediaStatus;

    /* msc related data buffer. For DMA operation this
       buffer needs to be cache-size aligned */
    void*   pulBuffer;

    uint32_t ulBytesToTransfer;
    uint32_t ulCurrentLBA;

    uint8_t ucINEndpoint;
    uint8_t ucINDMA;
    uint8_t ucOUTEndpoint;
    uint8_t ucOUTDMA;
    uint8_t ucInterface;
    uint8_t ucSCSIState;
}
tMSCInstance;

/**
 * \brief The structure used by the application to define operating parameters for
 * the mass storage device.
 */
typedef struct
{
    uint16_t usVID;
    /**< The vendor ID that this device is to present in the device descriptor. */

    uint16_t usPID;
    /**< The product ID that this device is to present in the device descriptor. */

    uint8_t pucVendor[8];
    /**< 8 byte vendor string. */

    uint8_t pucProduct[16];
    /**< 16 byte vendor string. */

    uint8_t pucVersion[4];
    /**< 4 byte vendor string */

    uint16_t usMaxPowermA;
    /**< The maximum power consumption of the device, expressed in milliamps. */

    uint8_t ucPwrAttributes;
    /**< Indicates whether the device is self or bus-powered and whether or not
     * it supports remote wakeup.  Valid values are USB_CONF_ATTR_SELF_PWR or
     * USB_CONF_ATTR_BUS_PWR, optionally ORed with USB_CONF_ATTR_RWAKE.
     */

    uint8_t **ppStringDescriptors;
    /**< A pointer to the string descriptor array for this device.  This array
     * must contain the following string descriptor pointers in this order.
     * Language descriptor, Manufacturer name string (language 1), Product
     * name string (language 1), Serial number string (language 1), MSC
     * Interface description string (language 1), Configuration description
     * string (language 1).
     *
     * If supporting more than 1 language, the descriptor block (except for
     * string descriptor 0) must be repeated for each language defined in the
     * language descriptor.
     */

    uint32_t ulNumStringDescriptors;
    /**< The number of descriptors provided in the ppStringDescriptors
     * array.  This must be 1 + ((5 + (num HID strings)) * (num languages)).
     */

    tMSCDMedia sMediaFunctions;
    /**< This structure holds the access functions for the media used by this
     * instance of the mass storage class device.  All of the functions in this
     * structure are required to be filled out with valid functions.
     */

    tUSBCallback pfnEventCallback;
    /**< This is the callback function for various events that occur during
     * mass storage class operation.
     */

    tMSCInstance *psPrivateData;
    /**< A pointer to the private instance data for this device.  This memory
     * must remain accessible for as long as the MSC device is in use and must
     * not be modified by any code outside the MSC class driver.
     */
}
tUSBDMSCDevice;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

extern tDeviceInfo g_sMSCDeviceInfo;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *\brief This function should be called once for the mass storage class device to
 *        initialized basic operation and prepare for enumeration.
 *
 * \param pDcdObject pointer to the USB DCD object.
 * \param psMSCDevice points to a structure containing parameters customizing
 *        the operation of the mass storage device.
 *
 * In order for an application to initialize the USB device mass storage
 * class, it must first call this function with the a valid mass storage
 * device class structure in the \e psDevice parameter.  This allows this
 * function to initialize the USB controller and device code to be prepared to
 * enumerate and function as a USB mass storage device.
 *
 * This function returns a void pointer that must be passed in to all other
 * APIs used by the mass storage class.
 *
 * See the documentation on the tUSBDMSCDevice structure for more information
 * on how to properly fill the structure members.
 *
 * \retval Returns 0 on failure or a non-zero void pointer on success.
 */
extern void *USBDMSCInit(void * pDcdObject,
                         tUSBDMSCDevice *psMSCDevice);

/**
 *  \brief This function should be called once for the mass storage class device to
 *        initialized basic operation and prepare for enumeration.
 *
 *  \param pDcdObject pointer to the USB DCD object.
 *  \param psMSCDevice points to a structure containing parameters customizing
 *       the operation of the mass storage device.
 *
 * An application wishing to make use of a composite
 * USB bulk communication channel for MSC class needs to call this function.
 * This function is used for initializing an instance related information of the
 * MSC device.
 *
 * This function returns a void pointer that must be passed in to all other
 * APIs used by the mass storage class.
 *
 * See the documentation on the tUSBDMSCDevice structure for more information
 * on how to properly fill the structure members.
 *
 * \retval Returns 0 on failure or a non-zero void pointer on success.
 */
extern void *USBDMSCCompositeInit(void * pDcdObject,
                                  tUSBDMSCDevice *psMSCDevice);

/** \brief  Shuts down the mass storage device.
 *
 *  \param pvInstance is the pointer to the device instance structure as
 *        returned by USBDMSCInit() or USBDMSCInitComposite().
 *
 * This function terminates mass storage operation for the instance supplied
 * and removes the device from the USB bus.  Following this call, the
 * \e psDevice instance may not me used in any other call to the mass storage
 * device other than USBDMSCInit() or USBDMSCInitComposite().
 */

extern void USBDMSCTerm(void *pvInstance);

/** \brief This function is used by an application if it can detect insertion or
 * removal of the media.
 *
 * \param pvInstance is the mass storage device instance that had a media
 * change.
 * \param eMediaStatus is the updated status for the media.
 *
 * This function should be called by an application when it detects a change
 * in the status of the media in use by the USB mass storage class.  The
 * \e eMediaStatus parameter will indicate the new status of the media and
 * can also indicate that the application has no knowledge of the media state.
 *
 * There are currently the three following values for the \e eMediaStatus
 * parameter:
 * - USBDMSC_MEDIA_PRESENT indicates that the media is present or has been
 * added.
 * - USBDMSC_MEDIA_NOTPRESENT indicates that the media is not present or was
 * removed.
 * - USBDMSC_MEDIA_UNKNOWN indicates that the application has no knowledge of
 * the media state and the USB mass storage class.
 *
 * It will be left up to the application to call this function whenever it
 * detects a change or simply call it once with USBDMSC_MEDIA_UNKNOWN and
 * allow the mass storage class to infer the state from the remaining device
 * APIs.
 *
 * \note It is recommended that the application use this function to inform
 * the mass storage class of media state changes as it will lead to a more
 * responsive system.
 *
 */
extern void USBDMSCMediaChange(void *pvInstance,
                               tUSBDMSCMediaStatus eMediaStatus);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef USBDMSC_H_ */
