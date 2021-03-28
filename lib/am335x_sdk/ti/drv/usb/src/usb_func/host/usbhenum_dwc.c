/****************************************************************************** */
/* Device enumeration code for the USB host library. */
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
#include "debug.h"
#include "usblib.h"
#include "usblibpriv.h"
#include "usbhost.h"
#include "usb_hcd_xhci.h"
#include "error.h"

#include <string.h>


#define IsTimerElapsed() 	(0U)

/****************************************************************************** */
/* External prototypes. */
/****************************************************************************** */
/*extern tUSBMode g_eUSBMode; */
static tUSBMode g_eUSBMode = USB_MODE_HOST;

/****************************************************************************** */
/* USB instance Object */
/****************************************************************************** */
extern tUSBInstanceObject g_USBInstance[];

/****************************************************************************** */
/* Internal function prototypes. */
/****************************************************************************** */
/****************************************************************************** */
/* Automatic power enable. */
/****************************************************************************** */
#define USB_HOST_PWREN_AUTO     0x00000002

/****************************************************************************** */
/* Flags used to signal between the interrupt handler and USBHCDMain(). */
/****************************************************************************** */
#define INT_EVENT_VBUS_ERR      0x01
#define INT_EVENT_CONNECT       0x02
#define INT_EVENT_DISCONNECT    0x04
#define INT_EVENT_POWER_FAULT   0x08
#define INT_EVENT_BABBLE_FAULT   0x10

uint32_t g_ulConnectRetry[USB_NUM_INSTANCE];



/****************************************************************************** */
/* These definitions are used to manipulate the values returned as allocated */
/* USB pipes. */
/****************************************************************************** */
#define EP_PIPE_USE_UDMA        0x01000000
#define EP_PIPE_TYPE_ISOC       0x00800000
#define EP_PIPE_TYPE_INTR       0x00400000
#define EP_PIPE_TYPE_BULK       0x00200000
#define EP_PIPE_TYPE_CONTROL    0x00100000
#define EP_PIPE_TYPE_IN         0x00020000
#define EP_PIPE_TYPE_OUT        0x00010000
#define EP_PIPE_IDX_M           0x0000ffff

/****************************************************************************** */
/* This creates a USB pipe handle from an index. */
/****************************************************************************** */
#define OUT_PIPE_HANDLE(ulIndex, ulIdx)  (g_sUSBHCD[ulIndex].USBOUTPipes[ulIdx].ulType | ulIdx)
#define IN_PIPE_HANDLE(ulIndex, ulIdx)  (g_sUSBHCD[ulIndex].USBINPipes[ulIdx].ulType | ulIdx)

/****************************************************************************** */
/****************************************************************************** */
#define INDEX_TO_USB_EP(x)      ((x) << 4)

/****************************************************************************** */
/* The global to hold all of the state information for a given host controller. */
/****************************************************************************** */
tUSBHCD g_sUSBHCD[USB_NUM_INSTANCE];

/****************************************************************************** */
/* If there is an event driver this function will send out a generic connection */
/* event USB_EVENT_CONNECTED indicating that an unknown connection event has */
/* occurred. */
/****************************************************************************** */
static void
SendUnknownConnect(uint32_t ulIndex, uint32_t ulClass, void* usbClass)
{
     
    if((g_sUSBHCD[ulIndex].iEventDriver != -1) &&
           (g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex]
               .iEventDriver]->pfnIntHandler))
    {
        /* Send the generic connected event. */
        g_sUSBHCD[ulIndex].EventInfo.ulEvent = USB_EVENT_CONNECTED;

        /* Save the class for later incase and application needs it. */
        g_sUSBHCD[ulIndex].ulClass = ulClass;
        g_sUSBHCD[ulIndex].EventInfo.usbClass = usbClass;

        g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iEventDriver]->
                        pfnIntHandler(&g_sUSBHCD[ulIndex].EventInfo);
    }
}


/****************************************************************************** */
/*! This function is used to write data to a USB HCD pipe. */
/*                                                                              */
/*! \param ulPipe is the USB pipe to put data into. */
/*! \param pucData is a pointer to the data to send. */
/*! \param ulSize is the amount of data to send. */
/*                                                                              */
/*! This function will block until it has sent as much data as was */
/*! requested using the USB pipe's FIFO.  The caller should have registered a */
/*! callback with the USBHCDPipeAlloc() call in order to be informed when the */
/*! data has been transmitted.  The value returned by this function can be less */
/*! than the \e ulSize requested if the USB pipe has less space available than */
/*! this request is making. */
/*                                                                              */
/*! \return This function returns the number of bytes that were scheduled to */
/*! be sent on the given USB pipe. */
/****************************************************************************** */
uint32_t
USBHCDPipeWrite(uint32_t ulIndex, uint32_t ulPipe, 
                      unsigned char *pucData, uint32_t ulSize)
{
    uint32_t ulEndpoint;
    uint32_t ulPipeIdx;

    /* Determine which endpoint interface that this pipe is using. */
    ulEndpoint = INDEX_TO_USB_EP((EP_PIPE_IDX_M & ulPipe) + 1);

    /* Get index used for looking up pipe data */
    ulPipeIdx = ulPipe & EP_PIPE_IDX_M;


    if (NO_ERROR != USBHostWrite(ulIndex, ulEndpoint, pucData, ulSize))
    {
        return 0;
    }

    /* Send all of the requested data. */
    /* Go Idle once this state has been reached. */
    /*if(!ulRemainingBytes) */
    {
        g_sUSBHCD[ulIndex].USBOUTPipes[ulPipeIdx].eState = PIPE_IDLE;
    }

    return(ulSize);
} /* USBHCDPipeWrite */


/****************************************************************************** */
/*! This function is used to read data from a USB HCD pipe. */
/*                                                                              */
/*! \param ulPipe is the USB pipe to read data from. */
/*! \param pucData is a pointer to store the data that is received. */
/*! \param ulSize is the size in bytes of the buffer pointed to by pucData. */
/*                                                                              */
/*! This function will block and will only return when it has read as much data */
/*! as requested from the USB pipe.  The caller should have registered a */
/*! callback with the USBHCDPipeAlloc() call in order to be informed when the */
/*! data has been received.  The value returned by this function can be less */
/*! than the \e ulSize requested if the USB pipe has less data available than */
/*! was requested. */
/*                                                                              */
/*! \return This function returns the number of bytes that were returned in the */
/*! \e pucData buffer. */
/****************************************************************************** */
uint32_t
USBHCDPipeRead(uint32_t ulIndex, uint32_t ulPipe, 
                      unsigned char *pucData, uint32_t ulSize)
{
    uint32_t ulEndpoint;
    uint32_t ulPipeIdx;
    /* Get index used for looking up pipe data */
    ulPipeIdx = ulPipe & EP_PIPE_IDX_M;

    
    /* Determine which endpoint interface that this pipe is using. */
    ulEndpoint = INDEX_TO_USB_EP(ulPipeIdx + 1);

    /* Set the remaining bytes to received. */
    /*ulRemainingBytes = ulSize; */

    /* Continue until all data requested has been received. */
    USBHostRead(ulIndex, ulEndpoint, pucData, ulSize);
    /*TODO: need to get the actual read bytes from the pipe */


    /* Go Idle once this state has been reached. */
    /*if(!ulRemainingBytes) */
    /*{ */
        g_sUSBHCD[ulIndex].USBINPipes[ulPipeIdx].eState = PIPE_IDLE;
    /*} */

    return(ulSize);
}

/****************************************************************************** */
/*! This function is used to release a USB pipe. */
/*                                                                              */
/*! \param ulPipe is the allocated USB pipe to release. */
/*                                                                              */
/*! This function is used to release a USB pipe that was allocated by a call to */
/*! USBHCDPipeAlloc() for use by some other device endpoint in the system. */
/*! Freeing an unallocated or invalid pipe will not generate an error and will */
/*! instead simply return. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDPipeFree(uint32_t ulIndex, uint32_t ulPipe)
{
    uint32_t iDMAIdx;
    uint32_t pipeIdx;

    pipeIdx = ulPipe & EP_PIPE_IDX_M;

    if (pipeIdx < 15)
    {
        if(ulPipe & EP_PIPE_TYPE_OUT)
        {
            /* Clear the address and type for this endpoint to free it up. */
            g_sUSBHCD[ulIndex].USBOUTPipes[pipeIdx].ulDevAddr = 0;
            g_sUSBHCD[ulIndex].USBOUTPipes[pipeIdx].ulType = 0;
            g_sUSBHCD[ulIndex].USBOUTPipes[pipeIdx].pfnCallback = 0;

            /* Get the dma channel used by this pipe. */
            iDMAIdx = g_sUSBHCD[ulIndex].USBOUTPipes[pipeIdx].ucDMAChannel;

            /* Mark the channel as free for use. */
            g_sUSBHCD[ulIndex].ucDMAChannels[iDMAIdx] = USBHCD_DMA_UNUSED;

            /* Clear out the current channel in use by this pipe. */
            g_sUSBHCD[ulIndex].USBOUTPipes[pipeIdx].ucDMAChannel =
                USBHCD_DMA_UNUSED;

        }
        else if(ulPipe & EP_PIPE_TYPE_IN)
        {
            /* Clear the address and type for this endpoint to free it up. */
            g_sUSBHCD[ulIndex].USBINPipes[pipeIdx].ulDevAddr = 0;
            g_sUSBHCD[ulIndex].USBINPipes[pipeIdx].ulType = 0;
            g_sUSBHCD[ulIndex].USBINPipes[pipeIdx].pfnCallback = 0;

            /* Get the dma channel used by this pipe. */
            iDMAIdx = g_sUSBHCD[ulIndex].USBINPipes[pipeIdx].ucDMAChannel;

            /* Mark the channel as free for use. */
            g_sUSBHCD[ulIndex].ucDMAChannels[iDMAIdx] = USBHCD_DMA_UNUSED;

            /* Clear out the current channel in use by this pipe. */
            g_sUSBHCD[ulIndex].USBINPipes[pipeIdx].ucDMAChannel =
                USBHCD_DMA_UNUSED;

        }
    }
}

/****************************************************************************** */
/* This internal function initializes the HCD code. */
/* \param ulIndex specifies which USB controller to use. */
/* \param pvPool is a pointer to the data to use as a memory pool for this */
/* controller. */
/* \param ulPoolSize is the size in bytes of the buffer passed in as pvPool. */
/* This function will perform all the necessary operations to allow the USB */
/* host controller to begin enumeration and communication with a device.  This */
/* function should typically be called once at the start of an application */
/* before any other calls are made to the host controller. */
/* \return None. */
/****************************************************************************** */
static void
USBHCDInitInternal(uint32_t ulIndex, void *pvPool,
                   uint32_t ulPoolSize)
{
    int iIdx;

    ASSERT((ulIndex == 0) || (ulIndex == 1));

    /* Save the base address for this controller. */
    /*g_sUSBHCD[ulIndex].ulUSBBase = g_USBInstance[ulIndex].uiBaseAddr ; */

    /* All Pipes are unused at start. */
    for(iIdx = 0; iIdx < MAX_NUM_PIPES; iIdx++)
    {
        g_sUSBHCD[ulIndex].USBINPipes[iIdx].ulDevAddr = 0;
        g_sUSBHCD[ulIndex].USBINPipes[iIdx].ulType = USBHCD_PIPE_UNUSED;
        g_sUSBHCD[ulIndex].USBINPipes[iIdx].ucDMAChannel = USBHCD_DMA_UNUSED;
        g_sUSBHCD[ulIndex].USBOUTPipes[iIdx].ulDevAddr = 0;
        g_sUSBHCD[ulIndex].USBOUTPipes[iIdx].ulType = USBHCD_PIPE_UNUSED;
        g_sUSBHCD[ulIndex].USBOUTPipes[iIdx].ucDMAChannel = USBHCD_DMA_UNUSED;
    }

    /* All DMA channels are unused at start. */
    for(iIdx = 0; iIdx < MAX_NUM_DMA_CHANNELS; iIdx++)
    {
        g_sUSBHCD[ulIndex].ucDMAChannels[iIdx] = USBHCD_DMA_UNUSED;
    }

    /* Initialized the device structure. */
    g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_IDLE;
    g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor = 0;

    /* Initialize the device descriptor. */
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bLength = 0;
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bMaxPacketSize0 = 0;

    /* Initialize the device address. */
    g_sUSBHCD[ulIndex].USBDevice[0].ulAddress = 0;

    /* Set the current interface to 0. */
    g_sUSBHCD[ulIndex].USBDevice[0].ulInterface = 0;

    /* Allocate the memory needed for reading descriptors. */
    g_sUSBHCD[ulIndex].pvPool = pvPool;
    g_sUSBHCD[ulIndex].ulPoolSize = ulPoolSize;

    /* Initialize the device class. */
    g_sUSBHCD[ulIndex].ulClass = USB_CLASS_EVENTS;

}

/****************************************************************************** */
/*! This function is used to set the power pin and power fault configuration. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*! \param ulPwrConfig is the power configuration to use for the application. */
/*                                                                              */
/*! This function must be called before HCDInit() is called so that the power */
/*! pin configuration can be set before power is enabled.  The \e ulPwrConfig */
/*! flags specify the power fault level sensitivity, the power fault action, */
/*! and the power enable pin level and source. */
/*                                                                              */
/*! One of the following can be selected as the power fault level sensitivity: */
/*                                                                              */
/*! - \b USBHCD_FAULT_LOW - An external power fault is indicated by the pin */
/*!                         being driven low. */
/*! - \b USBHCD_FAULT_HIGH - An external power fault is indicated by the pin */
/*!                          being driven high. */
/*                                                                              */
/*! One of the following can be selected as the power fault action: */
/*                                                                              */
/*! - \b USBHCD_FAULT_VBUS_NONE - No automatic action when power fault */
/*!   detected. */
/*! - \b USBHCD_FAULT_VBUS_TRI - Automatically Tri-state the USBnEPEN pin on a */
/*!                              power fault. */
/*! - \b USBHCD_FAULT_VBUS_DIS - Automatically drive the USBnEPEN pin to it's */
/*!                              inactive state on a power fault. */
/*                                                                              */
/*! One of the following can be selected as the power enable level and source: */
/*                                                                              */
/*! - \b USBHCD_VBUS_MANUAL - Power control is completely managed by the */
/*!                           application, the USB library will provide a */
/*!                           power callback to request power state changes. */
/*! - \b USBHCD_VBUS_AUTO_LOW - USBEPEN is driven low by the USB controller */
/*!                             automatically if USBOTGSessionRequest() has */
/*!                             enabled a session. */
/*! - \b USBHCD_VBUS_AUTO_HIGH - USBEPEN is driven high by the USB controller */
/*!                              automatically if USBOTGSessionRequest() has */
/*!                              enabled a session. */
/*                                                                              */
/*! If USBHCD_VBUS_MANUAL is used then the application must provide an */
/*! event driver to receive the USB_EVENT_POWER_ENABLE and */
/*! USB_EVENT_POWER_DISABLE events and enable and disable power to VBUS when */
/*! requested by the USB library.  The application should respond to a power */
/*! control callback by enabling or disabling VBUS as soon as possible and */
/*! before returning from the callback function. */
/*                                                                              */
/*! \note The following values should no longer be used with the USB library: */
/*! USB_HOST_PWRFLT_LOW, USB_HOST_PWRFLT_HIGH, USB_HOST_PWRFLT_EP_NONE, */
/*! USB_HOST_PWRFLT_EP_TRI, USB_HOST_PWRFLT_EP_LOW, USB_HOST_PWRFLT_EP_HIGH, */
/*! USB_HOST_PWREN_LOW, USB_HOST_PWREN_HIGH, USB_HOST_PWREN_VBLOW, and */
/*! USB_HOST_PWREN_VBHIGH. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDPowerConfigInit(uint32_t ulIndex, uint32_t ulPwrConfig)
{
    ASSERT((ulIndex == 0) || (ulIndex == 1));

    /* Save the value as it will be used later. */
    g_sUSBHCD[ulIndex].ulPowerConfig = ulPwrConfig;
}

/****************************************************************************** */
/*! This function is used to get the power pin and power fault configuration. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*                                                                              */
/*! This function will return the current power control pin configuration as */
/*! set by the USBHCDPowerConfigInit() function or the defaults if not yet set. */
/*! See the USBHCDPowerConfigInit() documentation for the meaning of the bits */
/*! that are returned by this function. */
/*                                                                              */
/*! \return The configuration of the power control pins. */
/*                                                                              */
/****************************************************************************** */
uint32_t
USBHCDPowerConfigGet(uint32_t ulIndex)
{
    ASSERT(ulIndex == 0);

    /* Save the value as it will be used later. */
    return(g_sUSBHCD[ulIndex].ulPowerConfig);
}

/****************************************************************************** */
/*! This function is used to set the power pin and power fault configuration. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*! \param ulConfig specifies which USB power configuration to use. */
/*                                                                              */
/*! This function will set the current power control pin configuration as */
/*! set by the USBHCDPowerConfigInit() function or the defaults if not yet set. */
/*! See the USBHCDPowerConfigInit() documentation for the meaning of the bits */
/*! that are set by this function. */
/*                                                                              */
/*! \return Returns zero to indicate the power setting is now active. */
/*                                                                              */
/****************************************************************************** */
/****************************************************************************** */
/*! This function returns if the current power settings will automatically */
/*! handle enabling and disabling VBUS power. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to query. */
/*                                                                              */
/*! This function returns if the current power control pin configuration will */
/*! automatically apply power or whether it will be left to the application */
/*! to turn on power when it is notified. */
/*                                                                              */
/*! \return A non-zero value indicates that power is automatically applied and */
/*! a value of zero indicates that the application must manually apply power. */
/*                                                                              */
/****************************************************************************** */
uint32_t
USBHCDPowerAutomatic(uint32_t ulIndex)
{
    /* Check if the controller is automatically applying power or not. */
    if(g_sUSBHCD[ulIndex].ulPowerConfig & USBHCD_VBUS_MANUAL)
    {
        return(0);
    }
    return(1);
}

/****************************************************************************** */
/*! This function is used to initialize the HCD code. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*! \param pvPool is a pointer to the data to use as a memory pool for this */
/*! controller. */
/*! \param ulPoolSize is the size in bytes of the buffer passed in as pvPool. */
/*                                                                              */
/*! This function will perform all the necessary operations to allow the USB */
/*! host controller to begin enumeration and communication with devices.  This */
/*! function should typically be called once at the start of an application */
/*! once all of the device and class drivers are ready for normal operation. */
/*! This call will start up the USB host controller and any connected device */
/*! will immediately start the enumeration sequence. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDInit(uint32_t ulIndex, void *pvPool, uint32_t ulPoolSize)
{
    int iDriver;

    /* Check the arguments. */
    ASSERT((ulIndex == 0) || (ulIndex == 1));

    /* Make sure there is at least enough to read the configuration descriptor. */
    ASSERT(ulPoolSize >= sizeof(tConfigDescriptor));

    /* Should not call this if the stack is in device mode. */
    ASSERT(g_eUSBMode != USB_MODE_DEVICE)

   g_sUSBHCD[ulIndex].USBHTimeOut.Value.slEP0 = USB_EP0_TIMEOUT_MILLISECS;
   g_sUSBHCD[ulIndex].USBHTimeOut.Value.slNonEP0= USB_NONEP0_TIMEOUT_MILLISECS;
   g_sUSBHCD[ulIndex].USBHTimeOut.Status.slEP0 = 0;
   g_sUSBHCD[ulIndex].USBHTimeOut.Status.slNonEP0= 0;
    /* If no mode is set then make the mode become host mode. */
    if(g_eUSBMode == USB_MODE_NONE)
    {
        g_eUSBMode = USB_MODE_HOST;
    }

    /* Call our internal function to perform the initialization. */
    USBHCDInitInternal(ulIndex, pvPool, ulPoolSize);

    /* No event driver is present by default. */
    g_sUSBHCD[ulIndex].iEventDriver = -1;
	
    /* No active driver now @present. */
    g_sUSBHCD[ulIndex].iUSBHActiveDriver = -1;

    /* Retry recovery and comunication with device on error. */
    g_sUSBHCD[ulIndex].ulConnectRetry = USBHCD_DEV_RECOVER_RETRY;

    /* Search through the Host Class driver list for the devices class. */
    for(iDriver = 0; iDriver < g_sUSBHCD[ulIndex].ulNumClassDrivers; iDriver++)
    {
        if(g_sUSBHCD[ulIndex].pClassDrivers[iDriver]->ulInterfaceClass ==
           USB_CLASS_EVENTS)
        {
            /* Event driver was found so remember it. */
            g_sUSBHCD[ulIndex].iEventDriver = iDriver;
        }
    }    
    
}

/****************************************************************************** */
/*! This function is used to initialize the HCD class driver list. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*! \param ppHClassDrvs is an array of host class drivers that are */
/*! supported on this controller. */
/*! \param ulNumDrivers is the number of entries in the \e pHostClassDrivers */
/*! array. */
/*                                                                              */
/*! This function will set the host classes supported by the host controller */
/*! specified by the \e ulIndex parameter.  This function should be called */
/*! before enabling the host controller driver with the USBHCDInit() function. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDRegisterDrivers(uint32_t ulIndex,
                      const tUSBHostClassDriver * const *ppHClassDrvs,
                      uint32_t ulNumDrivers)
{
    ASSERT((ulIndex == 0) || (ulIndex == 1));

    /* clear the Host Driver Structure first */
    memset(&g_sUSBHCD, 0, sizeof(g_sUSBHCD));

    g_sUSBHCD[ulIndex].ulIndex = ulIndex;

    /* Save the class drivers. */
    g_sUSBHCD[ulIndex].pClassDrivers = ppHClassDrvs;

    /* Save the number of class drivers. */
    g_sUSBHCD[ulIndex].ulNumClassDrivers = ulNumDrivers;
}

/****************************************************************************** */
/*! This function is used to terminate the HCD code. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to release. */
/*                                                                              */
/*! This function will clean up the USB host controller and disable it in */
/*! preparation for shutdown or a switch to USB device mode.  Once this call is */
/*! made, \e USBHCDInit() may be called to reinitialize the controller and */
/*! prepare for host mode operation. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDTerm(uint32_t ulIndex)
{
    ASSERT(ulIndex == 0);

    debug_printf("%s:%d. \n", __FUNCTION__, __LINE__);

    /* End the session. */
    /*USBOTGSessionRequest(g_USBInstance[ulIndex].uiBaseAddr , FALSE); */

    /* Remove power from the USB bus. */
    /*USBHostPwrDisable(g_USBInstance[ulIndex].uiBaseAddr ); */

    /* Disable USB interrupts. */

    /*USBIntDisableControl(g_USBInstance[ulIndex].uiBaseAddr , USB_INTCTRL_ALL); */

    /*USBIntDisableEndpoint(g_USBInstance[ulIndex].uiBaseAddr , USB_INTEP_ALL); */

    /* Set the host controller state back to it's initial values. */
    g_sUSBHCD[ulIndex].USBINPipes[0].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].USBINPipes[1].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].USBINPipes[2].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].USBOUTPipes[0].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].USBOUTPipes[1].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].USBOUTPipes[2].ulType = USBHCD_PIPE_UNUSED;
    g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_IDLE;
    g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor = 0;
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bLength = 0;
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bMaxPacketSize0 = 0;
    g_sUSBHCD[ulIndex].USBDevice[0].ulAddress = 0;
    g_sUSBHCD[ulIndex].USBDevice[0].ulInterface = 0;
    g_sUSBHCD[ulIndex].pvPool = 0;
    g_sUSBHCD[ulIndex].ulPoolSize = 0;
}



void USBHCDDisconnect(uint32_t ulIndex)
{
    debug_printf("%s:%d. \n", __FUNCTION__, __LINE__);
    g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_DEV_DISCONNECTED;
}

/****************************************************************************** */
/*! This function generates reset signaling on the USB bus. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*                                                                              */
/*! This function handles sending out reset signaling on the USB bus.  After */
/*! returning from this function, any attached device on the USB bus should */
/*! have returned to it's reset state. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDReset(uint32_t ulIndex)
{
    xhci_reset_device(ulIndex);
}

/****************************************************************************** */
/*! This function will generate suspend signaling on the USB bus. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*                                                                              */
/*! This function is used to generate suspend signaling on the USB bus.  In */
/*! order to leave the suspended state, the application should call */
/*! USBHCDResume(). */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDSuspend(uint32_t ulIndex)
{

    /* Start the suspend signaling. */
    /*USBHostSuspend(g_USBInstance[ulIndex].uiBaseAddr ); */
}

/****************************************************************************** */
/*! This function will generate resume signaling on the USB bus. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*                                                                              */
/*! This function is used to generate resume signaling on the USB bus in order */
/*! to cause  USB devices to leave their suspended state.  This call should */
/*! not be made unless a preceding call to USBHCDSuspend() has been made. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */
void
USBHCDResume(uint32_t ulIndex)
{
    ASSERT(ulIndex == 0);

}


/****************************************************************************** */
/*! This function opens the class driver. */
/*                                                                              */
/*! \param ulIndex specifies which USB controller to use. */
/*! \param ulDeviceNum is the device number for the driver to load. */
/*                                                                              */
/*! This function opens the driver needed based on the class value found in */
/*! the device's interface descriptor. */
/*                                                                              */
/*! \return This function returns -1 if no driver is found, or it returns the */
/*! index of the driver found in the list of host class drivers. */
/****************************************************************************** */
static int
USBHCDOpenDriver(uint32_t ulIndex, void* usbClass)
{
    int iDriver;
    uint32_t ulClass;
    tInterfaceDescriptor *pInterface;

    ASSERT((ulIndex == 0) || (ulIndex == 1));

    debug_printf("%s:%d. \n", __FUNCTION__, __LINE__);

    /* Get the interface descriptor. */
    pInterface = USBDescGetInterface(g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor,
                                     g_sUSBHCD[ulIndex].USBDevice[0].ulInterface,
                                     USB_DESC_ANY);

    if (pInterface != 0)
    {
        /* Read the interface class. */
        ulClass = pInterface->bInterfaceClass;
    }
    else
    {
        return ERROR_USB_HOST_GET_INTERFACE_FAILED; 
    }

    /* Search through the Host Class driver list for the devices class. */
    for(iDriver = 0; iDriver < g_sUSBHCD[ulIndex].ulNumClassDrivers; iDriver++)
    {
        /* If a driver was found call the open for this driver and save which */
        /* driver is in use. */
        if(g_sUSBHCD[ulIndex].pClassDrivers[iDriver]->ulInterfaceClass == ulClass)
        {
            debug_printf("%s:%d.open class driver\n", __FUNCTION__, __LINE__);

            /* Call the open function for the class driver. */
            g_sUSBHCD[ulIndex].pvDriverInstance = 
                g_sUSBHCD[ulIndex].pClassDrivers[iDriver]->
                    pfnOpen(&g_sUSBHCD[ulIndex].USBDevice[0], usbClass);

            /* If the driver was successfully loaded then break out of the */
            /* loop. */
            if(g_sUSBHCD[ulIndex].pvDriverInstance != 0)
            {
                break;
            }
        }
    }

    /* If no drivers were found then return -1 to indicate an invalid */
    /* driver instance. */
    if(iDriver == g_sUSBHCD[ulIndex].ulNumClassDrivers)
    {
        /* Send an unknown connection event. */
        SendUnknownConnect(ulIndex, ulClass,  usbClass);

        /* Indicate that no driver was found. */
        iDriver = -1;
    }

    return(iDriver);
} /* USBHCDOpenDriver */

/****************************************************************************** */
/* This function will send an event to a registered event driver. */
/* \param ulIndex is one of the USB_EVENT_* values. */
/* This function is only used internally to the USB library and will check */
/* if an event driver is registered and send on the event. */
/* Note: This function should not be called outside of the USB library. */
/* \return None. */
/****************************************************************************** */
void
InternalUSBHCDSendEvent(uint32_t ulIndex, uint32_t ulEvent)
{
    /* Make sure that an event driver has been registered. */
    if((g_sUSBHCD[ulIndex].iEventDriver != -1) &&
       (g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iEventDriver]->pfnIntHandler))
    {
        /* Send an event to the application. */
        g_sUSBHCD[ulIndex].EventInfo.ulEvent = ulEvent;

        g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iEventDriver]->pfnIntHandler(
           &g_sUSBHCD[ulIndex].EventInfo);
    }
}


/****************************************************************************** */
/* This function handles the necessary clean up for device disconnect. */
/* \param ulIndex is the device number for the device that was disconnected. */
/* This function handles all of the necessary clean up after a device */
/* disconnect has been detected by the stack.  This includes calling back the */
/* appropriate driver if necessary. */
/* \return None. */
/****************************************************************************** */
static void
USBHCDDeviceDisconnected(uint32_t ulIndex, void* usbClass)
{
    ASSERT(ulIndex == 0);

    debug_printf("%s:%d.\n", __FUNCTION__, __LINE__);

    if(g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor)
    {
        /* Invalidate the configuration descriptor. */
        g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor = 0;
    }

    /* Reset the max packet size so that this will be re-read from new devices. */
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bMaxPacketSize0 = 0;

    /* No longer have a device descriptor. */
    g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bLength = 0;

    /* No longer addressed. */
    g_sUSBHCD[ulIndex].USBDevice[0].ulAddress = 0;

    /* If this was an active driver then close it out. */
    if(g_sUSBHCD[ulIndex].iUSBHActiveDriver >= 0)
    {
        /* Call the driver Close entry point. */
        g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iUSBHActiveDriver]->
            pfnClose(usbClass);

        /* No active driver now present. */
        g_sUSBHCD[ulIndex].iUSBHActiveDriver = -1;
        g_sUSBHCD[ulIndex].pvDriverInstance = 0;
    }
    else
    {
        if((g_sUSBHCD[ulIndex].iEventDriver != -1) &&
           (g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iEventDriver]->pfnIntHandler))
        {
            /* Send the generic disconnect event. */
            g_sUSBHCD[ulIndex].EventInfo.ulEvent = USB_EVENT_DISCONNECTED;

            g_sUSBHCD[ulIndex].pClassDrivers[g_sUSBHCD[ulIndex].iEventDriver]->pfnIntHandler(
               &g_sUSBHCD[ulIndex].EventInfo);

            /* Reset the class and the instance. */
            g_sUSBHCD[ulIndex].ulClass = USB_CLASS_EVENTS;
            g_sUSBHCD[ulIndex].EventInfo.usbClass = 0;
        }
    }
    
}

/****************************************************************************** */
/*! This function is the main routine for the Host Controller Driver. */
/*                                                                              */
/*! This function is the main routine for the host controller driver, and must */
/*! be called periodically by the main application outside of a callback */
/*! context.  This allows for a simple cooperative system to access the the */
/*! host controller driver interface without the need for an RTOS.  All time */
/*! critical operations are handled in interrupt context but all blocking */
/*! operations are run from the this function to allow them to block and wait */
/*! for completion without holding off other interrupts. */
/*                                                                              */
/*! \return None. */
/****************************************************************************** */

uint32_t
USBHCDMain(uint32_t ulIndex, void* usbClass)
{
    /*uint32_t ulIntState; */
    /*tUSBHDeviceState eOldState; */
    uint32_t rc = NO_ERROR;

    switch(g_sUSBHCD[ulIndex].eDeviceState[0])
    {
        case HCD_IDLE:
        {
            rc = xhci_enum(ulIndex);


            if (rc != NO_ERROR)
            {
                if (rc == NO_DEVICE_CONNECTED)
                {
                    return NO_ERROR;
                }
                else
                {
                    return rc;
                }
            }
            else
            {
                /* a device has enumerated */
                g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_DEV_CONFIGURED;
            }

            break;
        }

        /* Trigger a reset to the connected device. */
        case HCD_DEV_RESET:
        {
            /* Trigger a Reset. */
            USBHCDReset(ulIndex);

            /* The state moves to connected but not configured. */
            g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_DEV_CONNECTED;

            break;
        }
        /* Device connection has been established now start enumerating */
        /* the device. */
        case HCD_DEV_CONNECTED:
        {
            break;
        }
        case HCD_DEV_ADDRESSED:
        {
            break;
        }
        /* The device was making a request and is now complete. */
        case HCD_DEV_REQUEST:
        {
            break;
        }
        /* The strings are currently not accessed. */
        case HCD_DEV_GETSTRINGS:
        {
            break;
        }
        /* Basically Idle at this point. */
        case HCD_DEV_DISCONNECTED:
        {
            /* Handle device disconnect. */
            USBHCDDeviceDisconnected(ulIndex, usbClass);

            /* Return to the Idle state. */
            g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_IDLE;
            break;
        }

        /* Connection and enumeration is complete so allow this function */
        /* to exit. */
        case HCD_DEV_CONFIGURED:
        {
            /* make sure the config descriptos have been copied. hacky hack since  */
            /* we skip a lot of enumeration states. Need to work on this when we  */
            /* impletement a full statemachine for xhci device/slot. */
            if ((g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor.bLength == 0) ||
                (g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor == 0)) 
            {
                rc = ERR_USB_HOST_GET_CONF_DESC; 
                break;
            }
            /* Open the driver for device 0. */
            g_sUSBHCD[ulIndex].iUSBHActiveDriver = 
                    USBHCDOpenDriver(ulIndex, usbClass);

            g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_DEV_RUNNING;
            break;
        }

        case HCD_DEV_RUNNING:
            break;

        default:
        {
            break;
        }
    }
    g_sUSBHCD[ulIndex].ulConnectRetry = g_ulConnectRetry[ulIndex];

    return rc;
}

/****************************************************************************** */
/*! This function completes a control transaction to a device.                  */
/*                                                                              */
/*! \param ulIndex is the controller index to use for this transfer.            */
/*! \param pSetupPacket is the setup request to be sent.                        */
/*! \param ulDevAddress is the address of the device for this request.          */
/*! \param pData is the data to send for OUT requests or the receive buffer     */
/*! for IN requests.                                                            */
/*! \param ulSize is the size of the buffer in pData.                           */
/*! \param ulMaxPacketSize is the maximum packet size for the device for this   */
/*! request.                                                                    */
/*                                                                              */
/*! This function handles the state changes necessary to send a control         */
/*! transaction to a device.  This function should not be called from within    */
/*! an interrupt callback as it is a blocking function.                         */
/*                                                                              */
/*! \return The number of bytes of data that were sent or received as a result  */
/*! of this request.                                                            */
/****************************************************************************** */
uint32_t
USBHCDControlTransfer(uint32_t ulIndex, tUSBRequest *pSetupPacket,
                      uint32_t ulDevAddress, unsigned char *pData,
                      uint32_t ulSize, uint32_t ulMaxPacketSize)
{
    uint32_t retStatus = 1;
    usbSetupPkt_t setupPacket;


    ASSERT((ulIndex == 0) || (ulIndex == 1));
    
    /* the usbSetupPkt is not packed, so it may not be casted properly. */
    setupPacket.bmRequestType = pSetupPacket->bmRequestType;
    setupPacket.bRequest      = pSetupPacket->bRequest;
    setupPacket.wValue        = pSetupPacket->wValue;
    setupPacket.wIndex        = pSetupPacket->wIndex;
    setupPacket.wLength       = pSetupPacket->wLength;

    USBHostControlTransfer(ulIndex, &setupPacket, pData, ulSize);
    
    return retStatus;
}



/****************************************************************************** */
/* This function sets the timeout value applicable communication types. */
/* This API should be called after 'USBHCDInit' call. */
/* \return None. */
/****************************************************************************** */
void
USBHCDTimeOutHook(uint32_t ulIndex, tUSBHTimeOut **USBHTimeOut)
{
   (*USBHTimeOut) = &(g_sUSBHCD[ulIndex].USBHTimeOut);
}

/****************************************************************************** */
/* called from xhci driver to save the descriptors to usblib internal datastructure. */
/****************************************************************************** */
void saveDeviceDescriptor(uint32_t ulIndex, uint8_t* buffer)
{
    uint8_t len;

    len = sizeof(tDeviceDescriptor); 
    memcpy(&g_sUSBHCD[ulIndex].USBDevice[0].DeviceDescriptor, buffer, len); 

}

/****************************************************************************** */
/* called from xhci driver to save the descriptors to usblib internal datastructure. */
/****************************************************************************** */
void saveConfigDescriptor(uint32_t ulIndex, uint8_t* buffer, uint32_t length)
{
    g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor = 
                        (tConfigDescriptor*)g_sUSBHCD[ulIndex].pvPool;

    if (length > g_sUSBHCD[ulIndex].ulPoolSize) 
        length = g_sUSBHCD[ulIndex].ulPoolSize;

    g_sUSBHCD[ulIndex].USBDevice[0].ulConfigDescriptorSize = length;
    memcpy(g_sUSBHCD[ulIndex].USBDevice[0].pConfigDescriptor, buffer, length);
}

/****************************************************************************** */
/* Close the Doxygen group. */
/*! @} */
/****************************************************************************** */
