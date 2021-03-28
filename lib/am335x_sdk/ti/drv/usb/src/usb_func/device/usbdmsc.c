/**
 *  \file  usbdmsc.c
 *
 *  \brief USB Mass storage device class driver.
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
 *    notice, this list of conditions and the fosllowing disclaimer.
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
#include "usbdmsc.h"
#include "usbmsc.h"
#include "usblib.h"
#include "usbdevice.h"
#include "usblibpriv.h"
#include "usb_dev_object.h"
#include "usb_dev_dman.h"
#include "debug.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define BUF_ALIGN_SIZE          (8)
/* These macros defines the sizes of USB transfers for Data and command */

/** \brief USB packet length */
#define USB_PACKET_LENGTH       512

/** \brief USB transfer size for transfer of data */
#define MAX_TRANSFER_SIZE       USB_PACKET_LENGTH

/** \brief USB transfer size for transfer fo command */
#define COMMAND_BUFFER_SIZE     64



/** \brief These are fields that are used by the USB descriptors
 *         for the Mass Storage Class.
 */
#define USB_MSC_SUBCLASS_SCSI   0x6
#define USB_MSC_PROTO_BULKONLY  0x50

/** Endpoints to use for each of the endpoints in the driver */

/** \brief Data In endpoitn */
#define DATA_IN_ENDPOINT        1

/** \brief Data out endpoint */
#define DATA_OUT_ENDPOINT       2

/** \brief Max packet size for bulk in endpoint */
#define DATA_IN_EP_MAX_SIZE     MAX_TRANSFER_SIZE

/** \brief Max packet size for bulk out endpoint */
#define DATA_OUT_EP_MAX_SIZE    MAX_TRANSFER_SIZE


/** The current state for the SCSI commands that are being handled and are
 * stored in the tMSCInstance.ucSCSIState structure member.
 */

/** \brief No command in progress */
#define STATE_SCSI_IDLE             0x00

/** \brief Sending and reading logical blocks */
#define STATE_SCSI_SEND_BLOCKS      0x01


/** \brief Receiving and writing logical blocks */
#define STATE_SCSI_RECEIVE_BLOCKS   0x02


/** \brief Send the status once the previous command is complete */
#define STATE_SCSI_SEND_STATUS      0x03


/** \brief Status was prepared to be sent and now waiting for it
 *         to have gone out.
 */
#define STATE_SCSI_SENT_STATUS      0x04

/** \brief Reserved SCSI command */
#define STATE_SCSI_COMMAND_RCVD     0x05


/* number of LUN - only 1 LUN supported */
#define MSC_MAX_LUN                 (1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/** \brief This function is called by the USB device stack whenever the device is
 *         disconnected from the host.
 *
 * \param pvInstance Instance data for this request.
 */
static void HandleDisconnect(void *pvInstance);

/** \brief This function is called by the USB device stack whenever the device
 * configuration changes.
 */

static void ConfigChangeHandler(void *pvInstance, uint32_t ulValue,
                                                uint32_t ulIndex);

/** \brief This function is called to handle the interrupts on the Bulk endpoints for
 * the mass storage class.
 */
static void HandleEndpoints(struct usbGadgetObj *pGadgetObject,
    usbGenericEvent_t endptEvent, uint32_t epNo, uint32_t length);

/** \brief This function is called by the USB device stack whenever a non-standard
 * request is received.
 *
 * \param pGadgetObject pointer to the gadget object.
 * \param endptEvnt Type of the endpoint event which has occured.
 * \param setup The setup packet received from the host.
 *
 * This call parses the provided request structure to determine the command.
 * The only mass storage command supported over endpoint 0 is the Get Max LUN
 * command.
 *
 * \retval None.
 */
static void HandleRequests(struct usbGadgetObj *pGadgetObject,
    usbEndpt0event_t endptEvent, usbSetupPkt_t * setup);

/** \brief This function is used to send out the response data based on the current
 * status of the mass storage class.
 */

static void USBDSCSISendStatus(const tUSBDMSCDevice *psDevice,
                                            void * pUsbGadgetObj);
/** \brief This function is used to handle all SCSI commands.
 */
uint32_t USBDSCSICommand(const tUSBDMSCDevice *psDevice,
                            tMSCCBW *pSCSICBW, void * pUsbGadgetObj);
/** \brief Device instance specific handler.
 */
static void HandleDevice(void *pvInstance, uint32_t ulRequest,
                         void *pvRequestData);

/** \brief This function is used to handle the SCSI Mode Sense 6 command when it is
 * received from the host.
 */
static void
USBDSCSIModeSense6(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                                    void * pUsbGadgetObj);

/** \brief This function is used to handle the SCSI Read 10 command when it is
 * received from the host.
 */
static void
USBDSCSIWrite10(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                            void * pUsbGadgetObj);

/** This function is used to handle the SCSI Read 10 command when it is
 * received from the host.
 */
static void
USBDSCSIRead10(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                            void * pUsbGadgetObj);

/** \brief This function is used to handle the SCSI Request Sense command when it is
 * received from the host.
 */
static void
USBDSCSIRequestSense(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj);

/** \brief This function is used to handle the SCSI Read Capacity command when it is
 * received from the host.
 *
 *  \param psDevice Pointer to the USBMSCDevice.
 *  \param pUsbGaddetObj Pointer to the USB gadget object.
 */
static void
USBDSCSIReadCapacity(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj);
/** This function is used to handle the SCSI Read Capacities command when it is
 *  received from the host.
 *
 *  \param psDevice Pointer to the USBMSCDevice.
 *  \param pUsbGaddetObj Pointer to the USB gadget object.
 */

static void
USBDSCSIReadCapacities(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj);
/** \brief This function is used to handle the SCSI Inquiry command
 *         when it is received from the host.
 *
 *  \param psDevice Pointer to the USBMSCDevice.
 *  \param pUsbGaddetObj Pointer to the USB gadget object.
 */

static void
USBDSCSIInquiry(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Local buffer to read in data and process them */
uint8_t g_pucCommand[MAX_TRANSFER_SIZE] \
                      __attribute__ ((aligned (BUF_ALIGN_SIZE))) \
                      __attribute__ ((section (".bss:extMemNonCache:usbXhci")));

uint8_t g_mscMainBuffer[DEVICE_BLOCK_SIZE]  
                      __attribute__ ((aligned (BUF_ALIGN_SIZE))) \
                      __attribute__ ((section (".bss:extMemNonCache:usbXhci")));

uint8_t intStatus = 0;
uint32_t g_bytesRead = 0;
uint32_t g_bytesWritten = 0;


/** \brief The current transfer state */
tMSCCSW g_sSCSICSW __attribute__ ((aligned (BUF_ALIGN_SIZE))) \
                      __attribute__ ((section (".bss:extMemNonCache:usbXhci")));

#define BCD_USB_VER     (0x200)
#define BCD_DEV_VER     (0x200)


#define BCD_USB_VER_SS  (0x300)
#define BCD_DEV_VER_SS  (0x0001)

/**
 *  \brief Device Descriptor. This is stored in RAM to allow
 *         several fields to be changed at runtime based on
 *         the application requirements.
 *
 */
static const uint8_t g_pMSCDeviceDescriptor[] =
{
    18,                     /* Size of this structure. */
    USB_DTYPE_DEVICE,       /* Type of this structure. */
    USBShort(BCD_USB_VER),  /* USB version 1.1 (if we say 2.0, hosts assume
                             * high-speed - see USB 2.0 spec 9.2.6.6) */
    0,                      /* USB Device Class (spec 5.1.1) */
    0,                      /* USB Device Sub-class (spec 5.1.1) */
    0,                      /* USB Device protocol (spec 5.1.1) */
    64,                     /* Maximum packet size for default pipe. */
    USBShort(0),            /* Vendor ID (filled in during USBDCDCInit). */
    USBShort(0),            /* Product ID (filled in during USBDCDCInit). */
    USBShort(BCD_DEV_VER),  /* Device Version BCD. */
    1,                      /* Manufacturer string identifier. */
    2,                      /* Product string identifier. */
    3,                      /* Product serial number. */
    1                       /* Number of configurations. */
};

/** \brief Mass storage device configuration descriptor.
 *
 * It is vital that the configuration descriptor bConfigurationValue field
 * (byte 6) is 1 for the first configuration and increments by 1 for each
 * additional configuration defined here.  This relationship is assumed in the
 * device stack for simplicity even though the USB 2.0 specification imposes
 * no such restriction on the bConfigurationValue values.
 *
 * Note that this structure is deliberately located in RAM since we need to
 * be able to patch some values in it based on client requirements.
 *
 */
static uint8_t g_pMSCDescriptor[] =
{
    /** Configuration descriptor header */
    9,                          /* Size of the configuration descriptor. */
    USB_DTYPE_CONFIGURATION,    /* Type of this descriptor. */
    USBShort(32),               /* The total size of this full structure. */
    1,                          /* The number of interfaces in this
                                 * configuration. */
    1,                          /* The unique value for this configuration. */
    0,                          /* The string identifier that describes this
                                 * configuration. */
    USB_CONF_ATTR_SELF_PWR,     /* Bus Powered, Self Powered, remote wake up. */
    250,                        /* The maximum power in 2mA increments. */
};

/** \brief The remainder of the configuration descriptor is stored in flash since we
 * don't need to modify anything in it at runtime.
 */
const uint8_t g_pMSCInterface[] =
{
   /* Vendor specific interface descriptor */
    9,                          /* Size of the interface descriptor. */
    USB_DTYPE_INTERFACE,        /* Type of this descriptor. */
    0,                          /* The index for this interface. */
    0,                          /* The alternate setting for this interface. */
    2,                          /* The number of endpoints used by this
                                 * interface. */
    USB_CLASS_MASS_STORAGE,     /* The interface class */
    USB_MSC_SUBCLASS_SCSI,      /* The interface sub-class. */
    USB_MSC_PROTO_BULKONLY,     /* The interface protocol for the sub-class
                                 * specified above. */
    0,                          /* The string index for this interface. */

    /** Endpoint descriptor */
    7,                               /* The size of the endpoint descriptor. */
    USB_DTYPE_ENDPOINT,              /* Descriptor type is an endpoint. */
    USB_EP_DESC_IN | DATA_IN_ENDPOINT,
    USB_EP_ATTR_BULK,                /* Endpoint is a bulk endpoint. */
    USBShort(DATA_IN_EP_MAX_SIZE),   /* The maximum packet size. */
    0,                               /* The polling interval for this endpoint. */

    /* Endpoint descriptor */
    7,                               /* The size of the endpoint descriptor.*/
    USB_DTYPE_ENDPOINT,              /* Descriptor type is an endpoint. */
    USB_EP_DESC_OUT | DATA_OUT_ENDPOINT,
    USB_EP_ATTR_BULK,                /* Endpoint is a bulk endpoint. */
    USBShort(DATA_OUT_EP_MAX_SIZE),  /* The maximum packet size. */
    0,                               /* The polling interval for this endpoint. */
};

/** The mass storage configuration descriptor is defined as two sections,
 *  one containing just the 9 byte USB configuration descriptor and the other
 *  containing everything else that is sent to the host along with it.
 */
usbConfigSection_t g_sMSCConfigSection =
{
    sizeof(g_pMSCDescriptor),
    g_pMSCDescriptor
};

usbConfigSection_t g_sMSCInterfaceSection =
{
    sizeof(g_pMSCInterface),
    g_pMSCInterface
};

/** \brief This array lists all the sections that must be concatenated to make a
 *  single, complete bulk device configuration descriptor.
 */
usbConfigSection_t *g_psMSCSections[] =
{
    &g_sMSCConfigSection,
    &g_sMSCInterfaceSection
};

#define NUM_MSC_SECTIONS (sizeof(g_psMSCSections) / sizeof(tConfigSection *))

/* \brief The header for the single configuration we support.  This is the root of
 * the data structure that defines all the bits and pieces that are pulled
 * together to generate the configuration descriptor.
 */
usbConfigHeader_t g_sMSCConfigHeader =
{
    NUM_MSC_SECTIONS,
    g_psMSCSections
};

/** Confguration descriptor */
usbConfigHeader_t *g_pMSCConfigDescriptors[] =
{
    &g_sMSCConfigHeader
};

/** \brief Device information structure for USB MSC device */
tDeviceInfo g_sMSCDeviceInfo =
{
    /** Device event callback handlers */
    {
        0,                  /* pfnGetDescriptor - Get Descriptor */
        HandleRequests,     /* pfnRequestHandler -  Request handler */
        0,                  /* pfnInterfaceChange - Interface change */
        ConfigChangeHandler,/* pfnConfigChange - Config change */
        0,                  /* pfnDataReceived - Data received */
        0,                  /* Data Sent back call back */
        0,                  /* pfnResetHandler - Reset handler */
        0,                  /* pfnSuspendHandler - Suspend handler */
        0,                  /* pfnResumeHandler - Resume handler */
        HandleDisconnect,   /* pfnDisconnectHandler - Disconnect handler */
        HandleEndpoints,    /* pfnEndpointHandler - Endpoint handler */
        HandleDevice        /* pfnDevicehandler - Device Handler */
    },
    g_pMSCDeviceDescriptor,
    g_pMSCConfigDescriptors,
    0,
    0,
    0
};
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void *
USBDMSCInit(void * pUsbGadgetObj, tUSBDMSCDevice *psDevice)
{
    /* Call usb composite init function */
    USBDMSCCompositeInit(pUsbGadgetObj, psDevice);

    /*
     * All is well so now pass the descriptors to the lower layer and put
     * the bulk device on the bus.
     */
    ((struct usbGadgetObj  *)pUsbGadgetObj)->dcd.dcdActions.pFnDcInit(&((struct usbGadgetObj  *)pUsbGadgetObj)->dcd);

    return ((void *)psDevice);
}

void *
USBDMSCCompositeInit(void * pUsbGadgetObj, tUSBDMSCDevice *psDevice)
{
    tMSCInstance *psInst;
    tDeviceDescriptor *psDevDesc;
    struct usbGadgetObj* pGadgetObj;

    /*
     * Initialize the workspace in the passed instance structure.
     */
    psInst = psDevice->psPrivateData;
    psInst->psConfDescriptor = (tConfigDescriptor *)g_pMSCDescriptor;
    psInst->psDevInfo = &g_sMSCDeviceInfo;
    psInst->bConnected = FALSE;
    psInst->eMediaStatus = USBDMSC_MEDIA_UNKNOWN;

    /* find the DMA-friendly buffer */
    psInst->pulBuffer = g_mscMainBuffer;

    /*
     * Set the initial interface and endpoints.
     */
    psInst->ucInterface = 0;
    psInst->ucOUTEndpoint = DATA_OUT_ENDPOINT;
    psInst->ucINEndpoint = DATA_IN_ENDPOINT;

    /*
     * Set the initial SCSI state to idle.
     */
    psInst->ucSCSIState = STATE_SCSI_IDLE;

    /*
     * Fix up the device descriptor with the client-supplied values.
     */
    psDevDesc = (tDeviceDescriptor *)psInst->psDevInfo->pDeviceDescriptor;
    psDevDesc->idVendor = psDevice->usVID;
    psDevDesc->idProduct = psDevice->usPID;

    /*
     * Fix up the configuration descriptor with client-supplied values.
     */
    psInst->psConfDescriptor->bmAttributes = psDevice->ucPwrAttributes;
    psInst->psConfDescriptor->bMaxPower =
                        (uint8_t)(psDevice->usMaxPowermA / 2);

    /*
     * Plug in the client's string stable to the device information
     * structure.
     */
    psInst->psDevInfo->ppStringDescriptors = psDevice->ppStringDescriptors;
    psInst->psDevInfo->ulNumStringDescriptors
        = psDevice->ulNumStringDescriptors;
    psInst->psDevInfo->pvInstance = (void *)psDevice;

    /*
     * Open the drive requested.
     */
    psInst->pvMedia = psDevice->sMediaFunctions.Open(0);

    if(psInst->pvMedia == 0)
    {
        /*
         * There is no media currently present.
         */
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;
    }
    else
    {
        /*
         * Media is now ready for use.
         */
        psInst->ucSenseKey = SCSI_RS_KEY_UNIT_ATTN;
        psInst->usAddSenseCode = SCSI_RS_MED_NOTRDY2RDY;
    }

    pGadgetObj = (struct usbGadgetObj*)pUsbGadgetObj;

    /* Set the pointer of msc device in the gadget object */
    pGadgetObj->usbClass.privateData = psDevice;
    pGadgetObj->usbClass.classAction.epHandler = HandleEndpoints;
    pGadgetObj->usbClass.classAction.ep0Handler = HandleRequests;

    /* Set the values of the descriptors required */
    /* Device descriptor */
    pGadgetObj->pDesc.pDeviceDesc = (usbDeviceDesc_t *)psInst->psDevInfo->pDeviceDescriptor;
    pGadgetObj->pDesc.ppConfigDesc = psInst->psDevInfo->ppConfigDescriptors;
    pGadgetObj->pDesc.ppStringDesc = psDevice->ppStringDescriptors;
    pGadgetObj->pDesc.numStringDesc = psDevice->ulNumStringDescriptors;

    /*  setup the device instance and pvInstance in the dcd info */
    pGadgetObj->dcd.ptDeviceInfo = psInst->psDevInfo;
    
    return((void *)psDevice);
}
#if 0
void
USBDMSCTerm(void *pvInstance)
{
    const tUSBDMSCDevice *psDevice;

    /*
     * Create a device instance pointer.
     */
    psDevice = pvInstance;

    /*
     * If the media was opened the close it out.
     */
    if(psDevice->psPrivateData->pvMedia == 0)
    {
        psDevice->psPrivateData->pvMedia = 0;
        psDevice->sMediaFunctions.Close(0);
    }

    /*
     * Cleanly exit device mode.
     */
    USBDCDTerm(0);
}
#endif

void
USBDMSCMediaChange(void *pvInstance, tUSBDMSCMediaStatus eMediaStatus)
{
    const tUSBDMSCDevice *psDevice;

    /*
     * Create a device instance pointer.
     */
    psDevice = (tUSBDMSCDevice*)pvInstance;

    /*
     * Save the current media status.
     */
    psDevice->psPrivateData->eMediaStatus = eMediaStatus;
}
/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void
HandleEndpoints(struct usbGadgetObj *pUsbGadgetObj,
    usbGenericEvent_t endptEvent, uint32_t epNo, uint32_t length)
{
    tUSBDMSCDevice *psDevice;
    tMSCInstance *psInst;
    tMSCCBW *pSCSICBW;

    /*
     * Determine if the serial device is in single or composite mode because
     * the meaning of ulIndex is different in both cases.
     */

    psDevice = (tUSBDMSCDevice*)pUsbGadgetObj->usbClass.privateData;
    /*
     * Initialize the workspace in the passed instance structure.
     */
    psInst = psDevice->psPrivateData;

    /*
     * Handler for the bulk IN data endpoint.
     */
    switch(endptEvent)
    {
        case USB_GENERIC_EVENT_DATA_IN_COMPLETE:
        {

            switch(psInst->ucSCSIState)
            {
                /*
                 * Handle the case where we are sending out data due to a read
                 * command.
                 */
                case STATE_SCSI_SEND_BLOCKS:
                {
                    /*
                     * Decrement the number of bytes left to send.
                     */

                    psInst->ulBytesToTransfer -= MAX_TRANSFER_SIZE;

                    /*
                     * Add the bytes transfered
                     */
                    g_bytesRead = g_bytesRead + MAX_TRANSFER_SIZE;

                    /*
                     * If we are done then move on to the status phase.
                     */
                    if(psInst->ulBytesToTransfer == 0)
                    {

                        /*
                         * Set the status so that it can be sent when this
                         * response has has be successfully sent.
                         */
                        g_sSCSICSW.bCSWStatus = 0;
                        g_sSCSICSW.dCSWDataResidue = 0;
                        g_bytesRead = 0;

                        /*
                         * Send back the status once this transfer is complete.
                         */
                        psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;

                        USBDSCSISendStatus(psDevice, pUsbGadgetObj);

                        /*
                         * The transfer is complete so don't read anymore data.
                         */
                        break;
                    }

                    if(g_bytesRead == DEVICE_BLOCK_SIZE)
                    {
                        /*
                         * Move on to the next Logical Block.
                         */
                        psInst->ulCurrentLBA++;
                        g_bytesRead = 0;
                    }

                    /*
                     * Read the new data and send it out.
                     */
                    psDevice->sMediaFunctions.BlockRead(psInst->pvMedia,
                                                       (uint8_t *)psInst->pulBuffer,
                                                        psInst->ulCurrentLBA,
                                                        1);

                   usbSetupEpReq(pUsbGadgetObj,
                                 psInst->ucINEndpoint,
                                (uint32_t *)psInst->pulBuffer,
                                 USB_TOKEN_TYPE_IN,
                                 MAX_TRANSFER_SIZE,
                                 USB_TRANSFER_TYPE_BULK);

                    break;
                }

                /*
                 * Handle sending status.
                 */
                case STATE_SCSI_SEND_STATUS:
                {
                    /*
                     * Indicate success and no extra data coming.
                     */
                    USBDSCSISendStatus(psDevice, pUsbGadgetObj);

                    break;
                }

                /*
                 * Handle completing sending status.
                 */
                case STATE_SCSI_SENT_STATUS:
                {
                    /* Setup request for next OUT transfer */
                    usbSetupEpReq(pUsbGadgetObj,
                                  psInst->ucOUTEndpoint,
                                  (uint32_t *)&g_pucCommand ,
                                  USB_TOKEN_TYPE_OUT,
                                  MAX_TRANSFER_SIZE,
                                  USB_TRANSFER_TYPE_BULK);
                    psInst->ucSCSIState = STATE_SCSI_IDLE;
                    break;
                }

                /*
                 * These cases should not occur as the being in the IDLE state due
                 * to an IN interrupt is invalid.
                 */
                case STATE_SCSI_IDLE:
                default:
                {
                    break;
                }
            }
            break;
        }

        /*
         * Handler for the bulk OUT data endpoint.
         */
        case USB_GENERIC_EVENT_DATA_OUT_COMPLETE:
        {
            switch(psInst->ucSCSIState)
            {
                /*
                 * Receiving and writing bytes to the storage device.
                 */
                case STATE_SCSI_RECEIVE_BLOCKS:
                {
                    /*
                     * Get the data from the FIFO and send Ack
                     */

                    /*
                     * Write the data to the block media
                     */
                    psDevice->sMediaFunctions.BlockWrite(psInst->pvMedia,
                                                        (uint8_t *)psInst->pulBuffer,
                                                         psInst->ulCurrentLBA,
                                                         1U);

                    psInst->ulBytesToTransfer -= MAX_TRANSFER_SIZE;
                    g_bytesWritten = g_bytesWritten + MAX_TRANSFER_SIZE;

                    if(g_bytesWritten == DEVICE_BLOCK_SIZE)
                    {
                        g_bytesWritten = 0;
                        psInst->ulCurrentLBA++;
                    }

                    /*
                     * Check if all bytes have been received.
                     */
                    if(psInst->ulBytesToTransfer == 0)
                    {
                        /*
                         * Set the status so that it can be sent when this response
                         * has be successfully sent.
                         */
                        g_sSCSICSW.bCSWStatus = 0;
                        g_sSCSICSW.dCSWDataResidue = 0;
                        g_bytesWritten = 0;
                        psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;

                        /*
                         * Indicate success and no extra data coming.
                         */

                        USBDSCSISendStatus(psDevice, pUsbGadgetObj);

                     }
                     else
                     {
                         usbSetupEpReq(pUsbGadgetObj,
                                       psInst->ucOUTEndpoint,
                                       (uint32_t *)psInst->pulBuffer,
                                       USB_TOKEN_TYPE_OUT,
                                       MAX_TRANSFER_SIZE,
                                       USB_TRANSFER_TYPE_BULK);
                     }

                    break;
                }

                /*
                 * If there is an OUT transfer in idle state then it was a new
                 * command.
                 */
                case STATE_SCSI_IDLE:
                {
                    /*
                     * Receive the command.
                     */

                    /* We assume that this buffer has already been filled by the lower layer driver */
                    pSCSICBW = (tMSCCBW *)g_pucCommand;

                    /*
                     * If this is a valid CBW then handle it.
                     */
                    if(pSCSICBW->dCBWSignature == CBW_SIGNATURE)
                    {
                        g_sSCSICSW.dCSWSignature = CSW_SIGNATURE;
                        g_sSCSICSW.dCSWTag = pSCSICBW->dCBWTag;
                        g_sSCSICSW.dCSWDataResidue = 0;
                        g_sSCSICSW.bCSWStatus = 0;
                        USBDSCSICommand(psDevice, pSCSICBW, pUsbGadgetObj);

                    }
                    else
                    {
                        /*
                         * Just return to the idle state since we are now out of
                         * sync with the host.  This should not happen, but this
                         * should allow the device to synchronize with the host
                         * controller.
                         */
                        psInst->ucSCSIState = STATE_SCSI_IDLE;

                    }

                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        /* Nothing to be done for these cases */
        case USB_GENERIC_EVENT_SOF_INTERRUPT:
            break;
        case USB_GENERIC_EVENT_NAK_TIMEOUT:
            break;
        case USB_GENERIC_EVENT_DATA_IN_NAK:
            break;
        case USB_GENERIC_EVENT_DATA_IN_PARTIAL:
            break;
        case USB_GENERIC_EVENT_DATA_OUT_NAK:
            break;
        case USB_GENERIC_EVENT_DATA_OUT_PARTIAL:
            break;
        case USB_GENERIC_EVENT_DATA_TOGGLE_ERROR:
            break;
        case USB_GENERIC_EVENT_TIMEOUT_ERROR:
            break;
        case USB_GENERIC_EVENT_BUS_ERROR:
            break;
        default:
            break;
    }
}

static void
HandleDevice(void *pvInstance, uint32_t ulRequest, void *pvRequestData)
{
    tMSCInstance *psInst;
    uint8_t *pucData;

    /*
     * Create the serial instance data.
     */
    psInst = ((tUSBDMSCDevice *)pvInstance)->psPrivateData;

    /*
     * Create the char array used by the events supported by the USB CDC
     * serial class.
     */
    pucData = (uint8_t *)pvRequestData;

    switch(ulRequest)
    {
        /*
         * This was an interface change event.
         */
        case USB_EVENT_COMP_IFACE_CHANGE:
        {
            psInst->ucInterface = pucData[1];
            break;
        }

        /*
         * This was an endpoint change event.
         */
        case USB_EVENT_COMP_EP_CHANGE:
        {
            /*
             * Determine if this is an IN or OUT endpoint that has changed.
             */
            if(pucData[0] & USB_EP_DESC_IN)
            {
                /* TODO */
                /* psInst->ucINEndpoint = INDEX_TO_USB_EP((pucData[1] & 0x7f)); */

            }
            else
            {
                /*
                 * Extract the new endpoint number.
                 */
               /*TODO*/
               /* psInst->ucOUTEndpoint = INDEX_TO_USB_EP(pucData[1] & 0x7f); */

            }
            break;
        }
        default:
        {
            break;
        }
    }
}

static void
HandleDisconnect(void *pvInstance)
{
    const tUSBDMSCDevice *psDevice;

    memset(&g_sSCSICSW, 0, sizeof(g_sSCSICSW));

    /*
     * Create the instance pointer.
     */
    psDevice = (const tUSBDMSCDevice *)pvInstance;
    psDevice->psPrivateData->ucSCSIState = STATE_SCSI_IDLE;

    psDevice->psPrivateData->ulBytesToTransfer = 0;
    psDevice->psPrivateData->ulCurrentLBA = 0;

    /*
     * Close the drive requested.
     */
    if(psDevice->psPrivateData->pvMedia != 0)
    {
        psDevice->psPrivateData->pvMedia = 0;
        psDevice->sMediaFunctions.Close(0);
    }
}

static void
ConfigChangeHandler(void *pvInstance, uint32_t ulValue,
                                    uint32_t ulIndex)
{
    /* TODO This feature is yet to be implemented */
}

static void
HandleRequests(struct usbGadgetObj *pGadgetObj,
    usbEndpt0event_t endptEvent, usbSetupPkt_t * setup )
{
    /*
     * Determine the type of request.
     */
    switch(setup->bRequest)
    {
        /*
         * A Set Report request is received from the host when it sends an
         * Output report via endpoint 0.
         */
        case USBREQ_GET_MAX_LUN:
        {
            /*
             * Send our response to the host.
             */

            /* copy LUN number to DMA friendly buffer */
            pGadgetObj->gadgetBufferPtr[0] = MSC_MAX_LUN-1; 
            usbSetupEpReq(pGadgetObj,
                          0U,
                          (uint32_t*)pGadgetObj->gadgetBufferPtr,
                          USB_TOKEN_TYPE_IN,
                          1U,
                          USB_TRANSFER_TYPE_CONTROL);
            break;
        }

        /*
         * This request was not recognized so stall.
         */
        default:
        {
            /* TODO : Stall endpoint 0 */
            break;
        }
    }


    /* Setup request for the lower layer to be ready for first OUT transfer */
    usbSetupEpReq(pGadgetObj,
                  DATA_OUT_ENDPOINT,
                  (uint32_t *)g_pucCommand,
                  USB_TOKEN_TYPE_OUT,
                  MAX_TRANSFER_SIZE,
                  USB_TRANSFER_TYPE_BULK);

} /* HandleRequests */

static void
USBDSCSIInquiry(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj)
{
    int iIdx;
    tMSCInstance *psInst;
    /*
     * Create the serial instance data.
     */
    psInst = psDevice->psPrivateData;

    /*
     * Direct Access device, Removable storage and SCSI 1 responses.
     */

    g_pucCommand[0] = SCSI_INQ_PDT_SBC;
    g_pucCommand[1] = SCSI_INQ_RMB;
    g_pucCommand[2] = 0x00;
    g_pucCommand[3] = 0x00;

    /*
     * Additional Length is fixed at 31 bytes.
     */

    g_pucCommand[4] = 31;
    g_pucCommand[5] = 0x00;
    g_pucCommand[6] = 0x00;
    g_pucCommand[7] = 0x00;

    /*
     * Copy the Vendor string.
     */
    for(iIdx = 0; iIdx < 8; iIdx++)
    {
        g_pucCommand[iIdx + 8] = psDevice->pucVendor[iIdx];
    }

    /*
     * Copy the Product string.
     */
    for(iIdx = 0; iIdx < 16; iIdx++)
    {
        g_pucCommand[iIdx + 16] = psDevice->pucProduct[iIdx];
    }

    /*
     * Copy the Version string.
     */
    for(iIdx = 0; iIdx < 4; iIdx++)
    {
        g_pucCommand[iIdx + 32] = psDevice->pucVersion[iIdx];
    }

    usbSetupEpReq(pUsbGadgetObj,
                  psInst->ucINEndpoint,
                  (uint32_t *)g_pucCommand ,
                  USB_TOKEN_TYPE_IN,
                  36,
                  USB_TRANSFER_TYPE_BULK);

    /*
     * Set the status so that it can be sent when this response has
     * has be successfully sent.
     */
    g_sSCSICSW.bCSWStatus = 0;
    g_sSCSICSW.dCSWDataResidue = 0;

    psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
}

static void
USBDSCSIReadCapacities(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj)
{
    uint32_t ulBlocks;
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    if(psInst->pvMedia != 0)
    {
        ulBlocks = psDevice->sMediaFunctions.NumBlocks(psInst->pvMedia);

        g_pucCommand[0] = 0x00;
        g_pucCommand[1] = 0x00;
        g_pucCommand[2] = 0x00;
        g_pucCommand[3] = 0x08;

        /*
         * Fill in the number of blocks, the bytes endianness must be changed.
         */
        g_pucCommand[4] = ulBlocks >> 24;
        g_pucCommand[5] = 0xff & (ulBlocks >> 16);
        g_pucCommand[6] = 0xff & (ulBlocks >> 8);
        g_pucCommand[7] = 0xff & (ulBlocks);

        /*
         * Current media capacity
         */
        g_pucCommand[8] = 0x02;

        /*
         * Fill in the block size, which is fixed at DEVICE_BLOCK_SIZE.
         */
        g_pucCommand[9] = 0xff & (DEVICE_BLOCK_SIZE >> 16);
        g_pucCommand[10] = 0xff & (DEVICE_BLOCK_SIZE >> 8);
        g_pucCommand[11] = 0xff & DEVICE_BLOCK_SIZE;

        /*
         * Send out the 12 bytes that are in this response.
         */

        usbSetupEpReq(pUsbGadgetObj,
               psInst->ucINEndpoint,
               (uint32_t *)g_pucCommand ,
               USB_TOKEN_TYPE_IN,
               12,
               USB_TRANSFER_TYPE_BULK);

        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 0;
        g_sSCSICSW.dCSWDataResidue = 0;
    }
    else
    {
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 1;
        g_sSCSICSW.dCSWDataResidue = 0;

        /*
         * Stall the IN endpoint
         */

        /* USBDevEndpointStall(g_USBInstance[ulIndex].uiBaseAddr, psInst->ucINEndpoint, USB_EP_DEV_IN); */

        /*
         * Mark the sense code as valid and indicate that these is no media
         * present.
         */
        psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;
    }

    psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
}

static void
USBDSCSIReadCapacity(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj)
{
    uint32_t ulBlocks;
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    ulBlocks = psDevice->sMediaFunctions.NumBlocks(psInst->pvMedia);

    /*
     * Only decrement if any blocks were found.
     */
    if(ulBlocks != 0)
    {
        /*
         * One less than the maximum number is the last addressable
         * block.
         */
        ulBlocks--;
    }

    if(psInst->pvMedia != 0)
    {
        /*
         * Fill in the number of blocks, the bytes endianness must be changed.
         */
        g_pucCommand[0] = 0xff & (ulBlocks >> 24);
        g_pucCommand[1] = 0xff & (ulBlocks >> 16);
        g_pucCommand[2] = 0xff & (ulBlocks >> 8);
        g_pucCommand[3] = 0xff & (ulBlocks);

        g_pucCommand[4] = 0;

        /*
         * Fill in the block size, which is fixed at DEVICE_BLOCK_SIZE.
         */
        g_pucCommand[5] = 0xff & (DEVICE_BLOCK_SIZE >> 16);
        g_pucCommand[6] = 0xff & (DEVICE_BLOCK_SIZE >> 8);
        g_pucCommand[7] = 0xff & DEVICE_BLOCK_SIZE;

        /*
         * Send the SCSI Inquiry Response.
         */
        usbSetupEpReq(pUsbGadgetObj,
                      psInst->ucINEndpoint,
                      (uint32_t *)g_pucCommand ,
                      USB_TOKEN_TYPE_IN,
                      8U,
                      USB_TRANSFER_TYPE_BULK);
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 0;
        g_sSCSICSW.dCSWDataResidue = 0;
    }
    else
    {
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 1;
        g_sSCSICSW.dCSWDataResidue = 0;

        /*
         * TODO : Stall the IN endpoint
         */

        /*
         * Mark the sense code as valid and indicate that these is no media
         * present.
         */
        psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;
    }

    psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
}

static void
USBDSCSIRequestSense(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj)
{
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    /*
     * The request sense response.
     */
    g_pucCommand[0] = psInst->ucErrorCode;
    g_pucCommand[1] = 0;
    g_pucCommand[2] = psInst->ucSenseKey;
    g_pucCommand[3] = 0;
    g_pucCommand[4] = 0;
    g_pucCommand[5] = 0;
    g_pucCommand[6] = 0;

    /*
     * There are 10 more bytes of data.
     */
    g_pucCommand[7] = 10;
    g_pucCommand[8] = 0;
    g_pucCommand[9] = 0;
    g_pucCommand[10] = 0;
    g_pucCommand[11] = 0;

    /*
     * Transition from not ready to ready.
     */
    g_pucCommand[12] = 0xff & (psInst->usAddSenseCode >> 8);
    g_pucCommand[12] = 0xff & (psInst->usAddSenseCode);
    g_pucCommand[14] = 0;
    g_pucCommand[15] = 0;
    g_pucCommand[16] = 0;
    g_pucCommand[17] = 0;

    /*
     * Setup a request to send the SCSI Inquiry Response.
     */
    usbSetupEpReq(pUsbGadgetObj,
           psInst->ucINEndpoint,
           (uint32_t *)g_pucCommand ,
           USB_TOKEN_TYPE_IN,
           18,
           USB_TRANSFER_TYPE_BULK);

    /*
     * Reset the valid flag on errors.
     */
    psInst->ucErrorCode = SCSI_RS_CUR_ERRORS;

    /*
     * Set the status so that it can be sent when this response has
     * has be successfully sent.
     */
    g_sSCSICSW.bCSWStatus = 0;
    g_sSCSICSW.dCSWDataResidue = 0;

    /*
     * Move on to the status phase.
     */
    psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
}

static void
USBDSCSIRead10(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                            void * pUsbGadgetObj)
{
    tMSCInstance *psInst;
    uint32_t usNumBlocks;

    /*
     * Default the number of blocks.
     */
    usNumBlocks = 0;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;


    if(psInst->pvMedia != 0)
    {
        /*
         * Get the logical block from the CBW structure. This switching
         * is required to convert from big to little endian.
         */
        psInst->ulCurrentLBA = (pSCSICBW->CBWCB[2] << 24) |
                               (pSCSICBW->CBWCB[3] << 16) |
                               (pSCSICBW->CBWCB[4] << 8) |
                               (pSCSICBW->CBWCB[5] << 0);

        /*
         * More bytes to read.
         */
        usNumBlocks = (pSCSICBW->CBWCB[7] << 8) | pSCSICBW->CBWCB[8];

        /*
         * Read the next logical block from the storage device.
         */
        if(psDevice->sMediaFunctions.BlockRead(psInst->pvMedia,
            ((uint8_t *)psInst->pulBuffer),
            psInst->ulCurrentLBA, 1) == 0)
            {
                psInst->pvMedia = 0;
                psDevice->sMediaFunctions.Close(0);
            }
    }
    /*
     * If there is media present then start transferring the data.
     */
    if(psInst->pvMedia != 0)
    {
        /*
         * Schedule the remaining bytes to send.
         */
        psInst->ulBytesToTransfer = (DEVICE_BLOCK_SIZE * usNumBlocks);

        usbSetupEpReq(pUsbGadgetObj,
                      psInst->ucINEndpoint,
                      (uint32_t *)psInst->pulBuffer ,
                      USB_TOKEN_TYPE_IN,
                      MAX_TRANSFER_SIZE,
                      USB_TRANSFER_TYPE_BULK);
        /*
         * Move on and start sending blocks.
         */
        psInst->ucSCSIState = STATE_SCSI_SEND_BLOCKS;
    }
    else
    {
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 1;
        g_sSCSICSW.dCSWDataResidue = 0;

        /*
         * Stall the IN endpoint
         */
        /* Stall is yet to be implemented */
        /* USBDevEndpointStall(g_USBInstance[ulIndex].uiBaseAddr, psInst->ucINEndpoint, USB_EP_DEV_IN); */

        /*
         * Mark the sense code as valid and indicate that these is no media
         * present.
         */
        psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;

        psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
    }
}

static void
USBDSCSIWrite10(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                            void * pUsbGadgetObj)
{

    uint16_t usNumBlocks;
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    /*
     * If there is media present then start transferring the data.
     */
    if(psInst->pvMedia != 0)
    {
        /*
         * Get the logical block from the CBW structure. This switching
         * is required to convert from big to little endian.
         */
        psInst->ulCurrentLBA = (pSCSICBW->CBWCB[2] << 24) |
                               (pSCSICBW->CBWCB[3] << 16) |
                               (pSCSICBW->CBWCB[4] << 8) |
                               (pSCSICBW->CBWCB[5] << 0);
        /*
         * More bytes to read.
         */
        usNumBlocks = (pSCSICBW->CBWCB[7] << 8) | pSCSICBW->CBWCB[8];

        psInst->ulBytesToTransfer = DEVICE_BLOCK_SIZE * usNumBlocks;

        /*
         * Start sending logical blocks, these are always multiples of
         * DEVICE_BLOCK_SIZE bytes.
         */
        usbSetupEpReq(pUsbGadgetObj,
                      psInst->ucOUTEndpoint,
                      (uint32_t *)psInst->pulBuffer ,
                      USB_TOKEN_TYPE_OUT,
                      512U,
                      USB_TRANSFER_TYPE_BULK);

        psInst->ucSCSIState = STATE_SCSI_RECEIVE_BLOCKS;

    }
    else
    {
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 1;
        g_sSCSICSW.dCSWDataResidue = 0;

        /*
         * TODO : Stall the IN endpoint
         */


        /*
         * Mark the sense code as valid and indicate that these is no media
         * present.
         */
        psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;
        psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
    }
}

static void
USBDSCSIModeSense6(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                                    void * pUsbGadgetObj)
{
    tMSCInstance *psInst;
    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    /*
     * If there is media present send the response.
     */
    if(psInst->pvMedia != 0)
    {
        /*
         * Three extra bytes in this response.
         */
        g_pucCommand[0] = 3;
        g_pucCommand[1] = 0;
        g_pucCommand[2] = 0;
        g_pucCommand[3] = 0;

        /*
         * Manually send the response back to the host.
         */
        usbSetupEpReq(pUsbGadgetObj,
                      psInst->ucINEndpoint,
                      (uint32_t *)g_pucCommand,
                      USB_TOKEN_TYPE_IN,
                      4,
                      USB_TRANSFER_TYPE_BULK);
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 0;
        g_sSCSICSW.dCSWDataResidue = pSCSICBW->dCBWDataTransferLength - 4;
    }
    else
    {
        /*
         * Set the status so that it can be sent when this response has
         * has be successfully sent.
         */
        g_sSCSICSW.bCSWStatus = 1;
        g_sSCSICSW.dCSWDataResidue = 0;

        /*
         * TODO : Stall the IN endpoint
         */

        /*
         * Mark the sense code as valid and indicate that these is no media
         * present.
         */
        psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
        psInst->ucSenseKey = SCSI_RS_KEY_NOT_READY;
        psInst->usAddSenseCode = SCSI_RS_MED_NOT_PRSNT;
    }

    psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
}

static void
USBDSCSISendStatus(const tUSBDMSCDevice *psDevice, void * pUsbGadgetObj)
{
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    /* Respond with the requested status */

    usbSetupEpReq(pUsbGadgetObj,
                  psInst->ucINEndpoint,
                 (uint32_t *)&g_sSCSICSW,
                  USB_TOKEN_TYPE_IN,
                  13,
                  USB_TRANSFER_TYPE_BULK);
    /*
     * Move the state to status sent so that the next interrupt will move the
     * statue to idle.
     */
    psInst->ucSCSIState = STATE_SCSI_SENT_STATUS;
}

uint32_t
USBDSCSICommand(const tUSBDMSCDevice *psDevice, tMSCCBW *pSCSICBW,
                                                void * pUsbGadgetObj)
{
    uint32_t ulRetCode;
    uint32_t ulTransferLength;
    tMSCInstance *psInst;

    /*
     * Get our instance data pointer.
     */
    psInst = psDevice->psPrivateData;

    /*
     * Initialize the return code.
     */
    ulRetCode = 1;

    debug_printf("%s:%d.CBWCB[0]=0x%x\n",
                __FUNCTION__, __LINE__, pSCSICBW->CBWCB[0]);
    /*
     * Save the transfer length because it may be overwritten by some calls.
     */
    ulTransferLength = pSCSICBW->dCBWDataTransferLength;
    switch(pSCSICBW->CBWCB[0])
    {
        /*
         * Respond to the SCSI Inquiry command.
         */
        case SCSI_INQUIRY_CMD:
        {
            /* on Windows, the Windows host sends INQUIRY_CMD then
             * READ_CAPACITIES. Linux host sends INQUIRY_CMD then
             * TEST_UNIT_READY then READ_CAPACITY.
             *
             * Need to open the storage media here to satisfy both Windows
             * and Linux enumerations.
             */
            if(psInst->pvMedia == 0)
            {
                /*
                 * Since there was no media, check for media here.
                 */
                psInst->pvMedia = psDevice->sMediaFunctions.Open(0);
            }

            USBDSCSIInquiry(psDevice, pUsbGadgetObj);
            break;
        }

        /*
         * Respond to the test unit ready command.
         */
        case SCSI_TEST_UNIT_READY:
        {
            g_sSCSICSW.dCSWDataResidue = 0;

            if(psInst->pvMedia != 0)
            {
                /*
                 * Set the status to success for now, this could be different
                 * if there is no media present.
                 */
                g_sSCSICSW.bCSWStatus = 0;
            }
            else
            {
                /*
                 * Since there was no media, check for media here.
                 */
                psInst->pvMedia = psDevice->sMediaFunctions.Open(0);

                /*
                 * If it is still not present then fail this command.
                 */
                if(psInst->pvMedia != 0)
                {
                    g_sSCSICSW.bCSWStatus = 0;
                }
                else
                {
                    g_sSCSICSW.bCSWStatus = 1;
                }
            }
            break;
        }

        /*
         * Handle the Read Capacities command.
         */
        case SCSI_READ_CAPACITIES:
        {
            USBDSCSIReadCapacities(psDevice, pUsbGadgetObj);
            break;
        }

        /*
         * Handle the Read Capacity command.
         */
        case SCSI_READ_CAPACITY:
        {
            USBDSCSIReadCapacity(psDevice, pUsbGadgetObj);
            break;
        }

        /*
         * Handle the Request Sense command.
         */
        case SCSI_REQUEST_SENSE:
        {
            USBDSCSIRequestSense(psDevice, pUsbGadgetObj);

            break;
        }

        /*
         * Handle the Read 10 command.
         */
        case SCSI_READ_10:
        {
            USBDSCSIRead10(psDevice, pSCSICBW, pUsbGadgetObj);
            break;
        }

        /*
         * Handle the Write 10 command.
         */
        case SCSI_WRITE_10:
        {
            USBDSCSIWrite10(psDevice, pSCSICBW, pUsbGadgetObj);
            break;
        }

        /*
         * Handle the Mode Sense 6 command.
         */
        case SCSI_MODE_SENSE_6:
        {
            USBDSCSIModeSense6(psDevice, pSCSICBW, pUsbGadgetObj);

            break;
        }

        case SCSI_VERIFY_10:
        {
            psInst->ucSCSIState = STATE_SCSI_IDLE;
            g_sSCSICSW.bCSWStatus = 0;
            g_sSCSICSW.dCSWDataResidue = pSCSICBW->dCBWDataTransferLength;
            break;
        }

        default:
        {
            psInst->ucSCSIState = STATE_SCSI_IDLE;

            /*
             * Set the status so that it can be sent when this response has
             * has be successfully sent.
             */
            g_sSCSICSW.bCSWStatus = 1;
            g_sSCSICSW.dCSWDataResidue = pSCSICBW->dCBWDataTransferLength;

            /*
             * If there is data then there is more work to do.
             */
            if(pSCSICBW->dCBWDataTransferLength != 0)
            {
                if(pSCSICBW->bmCBWFlags & CBWFLAGS_DIR_IN)
                {
                    /*
                     * TODO : Stall the IN endpoint
                     */
                }
                else
                {
                    /*
                     * TODO : Stall the OUT endpoint
                     */

                }
                /*
                 * Send the status once the stall occurs.
                 */
                psInst->ucSCSIState = STATE_SCSI_SEND_STATUS;
            }

            /*
             * Set the sense codes.
             */
            psInst->ucErrorCode = SCSI_RS_VALID | SCSI_RS_CUR_ERRORS;
            psInst->ucSenseKey = SCSI_RS_KEY_ILGL_RQST;
            psInst->usAddSenseCode = SCSI_RS_PV_INVALID;

            break;
        }
    }

    /*
     * If there is no data then send out the current status.
     */
    if(ulTransferLength == 0)
    {
        USBDSCSISendStatus(psDevice, pUsbGadgetObj);
    }
    return(ulRetCode);
}

