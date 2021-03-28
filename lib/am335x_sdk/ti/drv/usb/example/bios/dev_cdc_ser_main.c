/*****************************************************************************
 *
 * usb_dev_cdc_ser_main.c - Main routines for the USB CDC serial example.
 *
 *****************************************************************************/

/*
* Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
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



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

#include <ti/board/board.h>

#include <ti/csl/soc.h>

#include "ti/drv/usb/example/common/hardware.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>

#include "types.h"

#include "usb_drv.h"
#include "usblib.h"  // desire to move away from including this.
#include "usbcdc.h"
#include "usbdcdc.h"
#include "usb_cdc_structs.h"
#include "timer.h"


#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
#include "intRouter.h"
#endif

#include <ti/drv/uart/UART_stdio.h> /* include for UART_printStatus */

#define USB_UART_POLL_MODE /* enable this to enable USB debug.
                              if UART is in interrupt mode the debug print
                              inside USB LLD will die */
//#undef USB_UART_POLL_MODE

#ifdef USB_UART_POLL_MODE
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/soc/UART_soc.h>
#endif

//*****************************************************************************
//
// \addtogroup example_list
// <h1>USB Serial Device (usb_dev_serial)</h1>
//
// This example application creates a virtual serial port when connected 
// to a USB host PC.  
// The application uses the USB Communication Device Class, 
// Abstract Control Model (ACM) to write to and read data from USB host PC
//
//*****************************************************************************


#if (defined (evmAM335x)||defined(evmAM437x)) || \
     defined(evmOMAPL137) || defined(lcdkOMAPL138)
#define USB_DEV_INSTANCE                     0
#else
#define USB_DEV_INSTANCE                     1
#endif

//*****************************************************************************
//
// Variables tracking transmit and receive counts.
//
//*****************************************************************************

//*****************************************************************************
//
// Flag indicating whether or not we are currently sending a Break condition.
//
//*****************************************************************************
static tBoolean g_bSendingBreak = false;


//*****************************************************************************
//
// Flags used to pass commands from interrupt context to the main loop.
//
//*****************************************************************************
#define COMMAND_STATUS_UPDATE   0x00000002
volatile uint32_t g_ulFlags = 0;
char *g_pcStatus;


uint32_t g_ulTxCount = 0;
uint32_t g_ulRxCount = 0;
uint32_t g_rxBytes = 0;
uint32_t g_txBytes = 0;


//*****************************************************************************
//
// Global flag indicating that a USB configuration has been set.
//
//*****************************************************************************
static volatile tBoolean g_bUSBConfigured = false;

/* incoming and outgoing data buffer for bulk transfer */
uint8_t g_cdcTxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));
uint8_t g_cdcRxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));

/* internal status flags */
#define COMMAND_PACKET_RECEIVED 0x00000001
#define COMMAND_STATUS_UPDATE   0x00000002
#define COMMAND_PACKET_SENT     0x00000004


/* status of the CDC USB connection */
typedef enum 
{
    CDC_STATE_DISCONNECT = 1,
    CDC_STATE_CONNECT,
    CDC_STATE_READY
} CDC_STATE_E;

CDC_STATE_E g_cdc_state  = CDC_STATE_DISCONNECT;


//*****************************************************************************
//
// Internal function prototypes.
//
//*****************************************************************************
static void SetControlLineState(unsigned short usState);
static tBoolean SetLineCoding(tLineCoding *psLineCoding);
static void GetLineCoding(tLineCoding *psLineCoding);
static void SendBreak(tBoolean bSend);

void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams);
void consolePrintf(const char *pcString, ...);
void usbCoreIntrHandler(uint32_t* pUsbParam);

static void
convertData(uint8_t *incomingPcData,
            uint8_t *outgoingPcData,
            uint32_t ulNumBytes);

//*****************************************************************************
//
// Set the state of the RS232 RTS and DTR signals.
//
//*****************************************************************************
static void
SetControlLineState(unsigned short usState)
{
    //
    // set them appropriately depending upon the flags passed in the wValue
    // field of the request structure passed.
    //
}

//*****************************************************************************
// Set the communication parameters to use on the UART.
// Since we only simulate a UART, there is no real action necessary here
//*****************************************************************************
static tBoolean
SetLineCoding(tLineCoding *psLineCoding)
{
    tBoolean bRetcode;

    consolePrintf("SetLineCoding Databits = 0x%x. Parity=0x%x. Stopbit=%d",
                  psLineCoding->ucDatabits,
                  psLineCoding->ucParity,
                  psLineCoding->ucStop);
    //
    // Assume everything is OK until we detect any problem.
    //
    bRetcode = true;

    //
    // Let the caller know if we had a problem or not.
    //
    return(bRetcode);
}

//*****************************************************************************
//
// Get the communication parameters in use on the UART.
//
//*****************************************************************************
static void
GetLineCoding(tLineCoding *psLineCoding)
{
    //
    // Get the current line coding set in the UART.
    //
    psLineCoding->ulRate = 115200;
    psLineCoding->ucDatabits = 8;
    psLineCoding->ucParity = USB_CDC_PARITY_NONE;
    psLineCoding->ucStop = USB_CDC_STOP_BITS_1;
}

//*****************************************************************************
//
// This function sets or clears a break condition on the redirected UART RX
// line.  A break is started when the function is called with \e bSend set to
// \b true and persists until the function is called again with \e bSend set
// to \b false.
//
//*****************************************************************************
static void
SendBreak(tBoolean bSend)
{
    //
    // Are we being asked to start or stop the break condition?
    //
    if(!bSend)
    {
        //
        // Remove the break condition on the line.
        //
        // remove a break to UART hardware if we have one
        g_bSendingBreak = false;
    }
    else
    {
        //
        // Start sending a break condition on the line.
        //
        // send a break to UART hardware if we have one
        g_bSendingBreak = true;
    }
}

//*****************************************************************************
//
// Handles CDC driver notifications related to control and setup of the device.
//
// \param pvCBData is the client-supplied callback pointer for this channel.
// \param ulEvent identifies the event we are being notified about.
// \param ulMsgValue is an event-specific value.
// \param pvMsgData is an event-specific pointer.
//
// This function is called by the CDC driver to perform control-related
// operations on behalf of the USB host.  These functions include setting
// and querying the serial communication parameters, setting handshake line
// states and sending break conditions.
//
// \return The return value is event-specific.
//
//*****************************************************************************
uint32_t
ControlHandler(struct usbGadgetObj *pGadgetObject,
               void *pvCBData, uint32_t ulEvent,
               uint32_t ulMsgValue, void *pvMsgData)
{
    //
    // Which event are we being asked to process?
    //
    switch(ulEvent)
    {
        //
        // We are connected to a host and communication is now possible.
        //
        case USB_EVENT_CONNECTED:
            g_bUSBConfigured = true;
            g_cdc_state = CDC_STATE_CONNECT;

            g_pcStatus = "Host connected.";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            break;

        //
        // The host has disconnected.
        //
        case USB_EVENT_DISCONNECTED:
            g_bUSBConfigured = false;
            g_pcStatus = "Host disconnected.";
            g_ulFlags |= COMMAND_STATUS_UPDATE;

            g_cdc_state = CDC_STATE_DISCONNECT;
            break;

        //
        // Return the current serial communication parameters.
        //
        case USBD_CDC_EVENT_GET_LINE_CODING:
            g_pcStatus = "GET LINE CODING";
            GetLineCoding(pvMsgData);
            break;

        //
        // Set the current serial communication parameters.
        //
        case USBD_CDC_EVENT_SET_LINE_CODING:
            g_pcStatus = "SET LINE CODING";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            SetLineCoding(pvMsgData);
            break;

        //
        // Set the current serial communication parameters.
        //
        case USBD_CDC_EVENT_SET_CONTROL_LINE_STATE:
            g_pcStatus = "SET CONTROL LINE STATE";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            SetControlLineState((unsigned short)ulMsgValue);
            break;

        //
        // Send a break condition on the serial line.
        //
        case USBD_CDC_EVENT_SEND_BREAK:
            g_pcStatus = "SEND BREAK";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            SendBreak(true);
            break;

        //
        // Clear the break condition on the serial line.
        //
        case USBD_CDC_EVENT_CLEAR_BREAK:
            g_pcStatus = "CLEAR BREAK";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            SendBreak(false);
            break;

        //
        // Ignore SUSPEND and RESUME for now.
        //
        case USB_EVENT_SUSPEND:
        case USB_EVENT_RESUME:
            break;

        //
        // We don't expect to receive any other events.  Ignore any that show
        // up in a release build or hang in a debug build.
        //
        default:
            g_pcStatus = "Received un supported CDC event";
            break;
    }

    return(0);
}


//*****************************************************************************
// task function
//
//*****************************************************************************
Void taskFxn(UArg a0, UArg a1)
{
    USB_Params  usb_dev_params;
    USB_Handle  usb_handle;

    uint32_t rxBytes;


    consolePrintf("\nRTOS USB Dev CDC example!!\n");

    usb_dev_params.usbMode = USB_DEVICE_CDC_MODE;
    usb_dev_params.instanceNo = USB_DEV_INSTANCE;  /* USB port # */
    usb_dev_params.usbClassData = (void*)&g_sCDCDevice;

    usb_handle = USB_open(usb_dev_params.instanceNo, &usb_dev_params);

    if (usb_handle == 0)
    {
        consolePrintf("Failed to open USB driver\n");
        UART_printStatus("\n Some tests have failed.\n");
        while(1);
    }

    usbdIntrConfig(usb_handle, &usb_dev_params);

    consolePrintf("Done configuring USB and its interrupt. Example is ready!\n");

    UART_printStatus("\n Test in progress.\n");

    //
    // Wait for initial configuration to complete.
    //
    consolePrintf("Waiting for host.... \n");

    //
    // Main application loop.
    //
    while(1)
    {
        if (g_ulFlags & COMMAND_STATUS_UPDATE)
        {
            consolePrintf("%s\n", g_pcStatus);
            g_ulFlags &= ~COMMAND_STATUS_UPDATE;
            
            if (g_cdc_state == CDC_STATE_CONNECT)
            {
                /* we received received "SetConfig" from host, and the LLD has 
                 * finished handling SetConfig.
                 * Need to wait a little just in case the host sends some extra 
                 * request (observed Linux host sending 2 Get String Descriptors 
                 * but not on Windows)
                 */
                g_cdc_state = CDC_STATE_READY;

                /* start a bulk OUT transaction - this is a non-blocking call
                 * data will arrive in the provided buffer when the host actually
                 * sends data to us. Data is arrived when usbdCdcEventCallback function is called with
                 * event USB_EVENT_RX_AVAILABLE 
                 */
                USBD_cdcRead(usb_handle, g_cdcRxBuffer, &rxBytes);
            }
        }
        
        if (g_cdc_state == CDC_STATE_READY)
        {
            if (g_ulFlags & COMMAND_PACKET_RECEIVED)
            {
                /* we receive a packet from the host */
                convertData(g_cdcRxBuffer, /* *incomingPcData, */
                            g_cdcTxBuffer, /* *outgoingPcData */
                            g_rxBytes);

                /* echo back to host */
                USBD_cdcWrite(usb_handle, g_cdcTxBuffer, g_rxBytes);

                /* printf will cause problem if host PC keeps sending data */
                consolePrintf("Rx: %d bytes\n", g_rxBytes);
                g_ulFlags &= ~COMMAND_PACKET_RECEIVED;
            }
            if (g_ulFlags & COMMAND_PACKET_SENT)
            {
                /* we have finished the TX (Bulk IN) transaction */

                /* start another bulk OUT transaction */
                USBD_cdcRead(usb_handle, g_cdcRxBuffer, &rxBytes);

                /* printf will cause problem if host PC keeps sending data */
                consolePrintf("Done Tx: %d\n", g_txBytes);
                g_ulFlags &= ~COMMAND_PACKET_SENT;
            }

        }

    }

}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------r- */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams)
{
    HwiP_Params hwiInputParams;
    int32_t mainIntNo = 0;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbDevParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;

    if (usbDevParams->instanceNo == 0)
    {
        mainIntNo = SYS_INT_USB0;
    }
#if !defined(SOC_OMAPL137) && !defined(SOC_OMAPL138)
    else
    {
        mainIntNo = SYS_INT_USB1;
    }

#if defined(__ARM_ARCH_7A__)
    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif
#endif

    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
                              &hwiInputParams);

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbDevParams->instanceNo,TRUE);
#endif

    USB_irqConfig(usbHandle, usbDevParams);

}

/* main entry point for DWC core interrupt handler with USB Wrapper setup
* Matching interrupt call-back function API */
void usbCoreIntrHandler(uint32_t* pUsbParam)
{
    USB_coreIrqHandler(((USB_Params*)pUsbParam)->usbHandle, (USB_Params*)pUsbParam);
}


/*****************************************************************************
 *  main
*****************************************************************************/

int main(void)
{

    Task_Handle task;
    Task_Params tskParams;
    Error_Block eb;
         
#ifdef USB_UART_POLL_MODE
    UART_HwAttrs uart_cfg;
    uint32_t uartInstance = 0;

    /* change UART to poll mode to prevent crashing in debug mode since
     * USB LLD has a lot of debug print in debug mode
     */

    /* Get the default UART init configurations */
    UART_socGetInitCfg(uartInstance, &uart_cfg);

    uart_cfg.enableInterrupt=0; /* Disabling interrupt forcefully */

    /* Get the default UART init configurations */
    UART_socSetInitCfg(uartInstance, &uart_cfg);
#endif

    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;

   Board_init(boardCfg);

    Error_init(&eb);

    Task_Params_init(&tskParams);
    tskParams.stackSize = 0x4000;
    task = Task_create(taskFxn, &tskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    delayTimerSetup();


    BIOS_start();    /* does not return */

    return 0;
}



/*****************************************************************************
 * This function is called back from USB LLD CDC class
 * it is mostly running in interrupt context.
 * pvCBData is the callbackData associated with the CDC Device struct (g_sCDCDevice) 
 * ulEvent is USB Lib USB events
 * ulMsgValue value depends on the Events.
 *   For RX_AVAILABLE, TX_COMPLETE events:
 *     + ulMsgValue will be the number of bytes received or transmitted, respectively
 *     + pvMsgData is the buffer provided to USBD_cdcWrite or USBD_cdcRead
 *****************************************************************************/
uint32_t
usbdCdcEventCallback(struct usbGadgetObj *pGadgetObject,
                       void *pvCBData, uint32_t ulEvent,
                       uint32_t ulMsgValue, void *pvMsgData)
{
    //
    // Which event have we been sent?
    //
    switch(ulEvent)
    {
        //
        // Data is available from the lower layer.
        //
        case USB_EVENT_RX_AVAILABLE:
        {
            g_ulFlags |= COMMAND_PACKET_RECEIVED;
            g_ulRxCount += ulMsgValue;
            g_rxBytes = ulMsgValue;
            break;
        }

        //
        // A previous transmission has completed.
        //
        case USB_EVENT_TX_COMPLETE:
        {
            g_ulFlags |= COMMAND_PACKET_SENT;
            g_ulTxCount += ulMsgValue;
            g_txBytes = ulMsgValue;
            break;
        }

        //
        // All other events are merely passed through to the client.
        //
        default:
        {
            break;
        }
    }
    return 0;
}

/*****************************************************************************
revert the ASCII case of the incoming string and put it to the outgoing string
*****************************************************************************/
static void
convertData(uint8_t *incomingPcData,
            uint8_t *outgoingPcData,
            uint32_t ulNumBytes)
{
    int ulReadIndex = 0;

    if (ulNumBytes <=  MAX_TRANSFER_SIZE)
    {
        for (ulReadIndex = 0; ulReadIndex < ulNumBytes; ulReadIndex ++)
        {
            //
            // Is this a lower case character?
            //
            if((incomingPcData[ulReadIndex] >= 'a') &&
               (incomingPcData[ulReadIndex] <= 'z'))
            {
                //
                // Convert to upper case and write to the transmit buffer.
                //
                outgoingPcData[ulReadIndex] =
                    (incomingPcData[ulReadIndex] - 'a') + 'A';
            }
            else
            {
                //
                // Is this an upper case character?
                //
                if((incomingPcData[ulReadIndex] >= 'A') &&
                   (incomingPcData[ulReadIndex] <= 'Z'))
                {
                    //
                    // Convert to lower case and write to the transmit buffer.
                    //
                    outgoingPcData[ulReadIndex] =
                        (incomingPcData[ulReadIndex] - 'Z') + 'z';
                }
                else
                {
                    //
                    // Copy the received character to the transmit buffer.
                    //
                    outgoingPcData[ulReadIndex] = incomingPcData[ulReadIndex];
                }
            }
        }
    }

}

