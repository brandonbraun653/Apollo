//*****************************************************************************
//
// dev_bulk_main.c - Main routines for the generic bulk device example.
//
//*****************************************************************************

/*
* Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
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
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <stdlib.h>
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
#include "usbdbulk.h"
#include "usb_bulk_structs.h"
#include "timer.h"


#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(BUILD_MCU))
#include "intRouter.h"
#endif

#include <ti/drv/uart/UART_stdio.h>

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>USB Generic Bulk Device (usb_dev_bulk)</h1>
//!
//! This example provides a generic USB device offering simple bulk data
//! transfer to and from the host.  The device uses a vendor-specific class ID
//! and supports a single bulk IN endpoint and a single bulk OUT endpoint.
//! Data received from the host is assumed to be ASCII text and it is
//! echoed back with the case of all alphabetic characters swapped.
//!
//! A sample python script is provided at ti/drv/usb/example/usb_devbulk
//! that can send a test string to the device and expects the echoed string back
//!
//*****************************************************************************


#if (defined (evmAM335x)||defined(evmAM437x) || defined(evmOMAPL137) || \
    defined(lcdkOMAPL138) || defined(j721e_evm))
/* only USB#0 on these EVM can be USB DEV */
#define USB_DEV_INSTANCE                     0
#else
/* on idkAM572x, USB1 is attached to a USB device connector */
#define USB_DEV_INSTANCE                     1
#endif

//*****************************************************************************
//
// Variables tracking transmit and receive counts.
//
//*****************************************************************************
unsigned int g_ulTxCount = 0;
unsigned int g_ulRxCount = 0;
unsigned int g_rxBytes = 0;
unsigned int g_txBytes = 0;

unsigned int g_ulFlags = 0;
char *g_pcStatus;

/* incoming and outgoing data buffer for bulk transfer */
uint8_t g_bulkTxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));
uint8_t g_bulkRxBuffer[MAX_TRANSFER_SIZE] __attribute__ ((aligned (CACHE_LINE_SIZE)));

/* internal status flags */
#define COMMAND_PACKET_RECEIVED 0x00000001
#define COMMAND_STATUS_UPDATE   0x00000002
#define COMMAND_PACKET_SENT     0x00000004

/* internal status of the bulk connection */
typedef enum 
{
    BULK_STATE_DISCONNECT = 1,
    BULK_STATE_CONNECT,
    BULK_STATE_READY
} BULK_STATE_E;

BULK_STATE_E g_bulk_state  = BULK_STATE_DISCONNECT;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams);
void consolePrintf(const char *pcString, ...);
void usbCoreIntrHandler(uint32_t* pUsbParam);

static void convertData(uint8_t *incomingPcData,
                        uint8_t *outgoingPcData,
                        uint32_t ulNumBytes);




void doUsbBulkWriteThroughput(USB_Handle usb_handle, uint32_t transferSize);
void doUsbBulkReadThroughput(USB_Handle usb_handle, uint32_t transferSize);



/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
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


/* 
 * USB bulk write throughput test 
 * USB host sends bulk packets to us 
 *
 * Write == USB OUT
 * i.e USB host write to USB device (which does the read)
 * 
 * We know when host finishes sending the packets when the data size is 
 * less than max packet size
 */
void doUsbBulkWriteThroughput(USB_Handle usb_handle, uint32_t transferSize)
{
    uint32_t rxBytes;
    uint32_t totalSize = 0;

    while (1)
    {
        USBD_bulkRead(usb_handle, g_bulkRxBuffer, &rxBytes);

        totalSize += rxBytes;

        if (rxBytes < MAX_TRANSFER_SIZE)
        {
            /* last packet has size smaller than the max packet size 
               means we aleady receive last packet */
            break;
        }

        if (totalSize >= transferSize)
        {
            /* we already receive all data neccessary for test. Stop this test */
            break;
        }
    }
    consolePrintf("Finish write throughput test\n");
}


/* 
 * USB bulk read throughput test 
 * USB host expects us to send out bulk packets 
 * We agree with USB host that we would send 10MB worth of packets
 *
 * Read means USB IN in this case - so we write to host.
 *
 */
void doUsbBulkReadThroughput(USB_Handle usb_handle, uint32_t transferSize)
{
    uint32_t txBytes = MAX_TRANSFER_SIZE;
    uint32_t numBlocks = transferSize / MAX_TRANSFER_SIZE;
    uint32_t numRemain = transferSize % MAX_TRANSFER_SIZE;
    uint32_t i;

    memset(g_bulkTxBuffer, 0xAA, MAX_TRANSFER_SIZE);

    for (i = 0; i<numBlocks; i++)
    {
        USBD_bulkWrite(usb_handle, g_bulkTxBuffer, txBytes);
    }

    if (numRemain > 0)
    {
        USBD_bulkWrite(usb_handle, g_bulkTxBuffer, numRemain);
    }
    
    consolePrintf("Finish read throughput test\n");
}

/* 
 * USB bulk demo/test 
 * USB host sends bulk packets of ascii string to us 
 * We swap the letter case and send the string back to host.
 *
 * We know when host finishes sending the packets when the packet contains a string of "ENDDEMO"
 */
void doUsbBulkDemo(USB_Handle usb_handle)
{
    uint32_t rxBytes;

    while(1)
    {
        /* start waiting for bulk transfer from USB host 
           USB device cannot send anything to USB host unless USB host asks for it */
        USBD_bulkRead(usb_handle, g_bulkRxBuffer, &rxBytes);

        /* check to see if the USB host wants to end the test. */
        if (strncmp((char*)g_bulkRxBuffer, "ENDDEMO", 7) != 0)
        {
            /* convert the data and echo back to host */
            convertData(g_bulkRxBuffer, /* *incomingPcData, */
                    g_bulkTxBuffer, /* *outgoingPcData */
                    rxBytes);

            USBD_bulkWrite(usb_handle, g_bulkTxBuffer, rxBytes);
        }
        else
        {
            consolePrintf("Finish echo test\n");
            break;
        }
    }
}



/* 
 *  find the transfer size specified in a command string which has the following format
 *  WRITE_THROUGHPUT=4000; 
 *  or
 *  READ_THROUGHPUT=8000;
 *  The transfer size is the value 4000 or 8000 in the above examples
 */
uint32_t findTransferSize(char* cmdStr, uint32_t cmdLen)
{
    uint32_t i, j, valid;

    char valStr[80];

    i = 0;
    while (i<cmdLen)
    {
        if (cmdStr[i] == '=')
        {
            break;
        }
        i++;
    }

    i++; /* skip the '=' */
    j = 0;
    valid = 0;
    while (i<cmdLen-1)
    {
        valStr[j] = cmdStr[i];

        if (cmdStr[i+1]==';')
        {
            /* found end of the command */
            valid = 1;
            break;
        }
        
        j++;
        i++;
    }
    
    if (valid==1)
    {
        return atoi(valStr);
    }
    else
    {
        return 0;
    }
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
    uint32_t transferSize;


    consolePrintf("\nRTOS USB Dev Bulk example!!\n");

    usb_dev_params.usbMode = USB_DEVICE_BULK_MODE;
    usb_dev_params.instanceNo = USB_DEV_INSTANCE;  /* USB port # */
    usb_dev_params.usbClassData = (void*)&g_sBulkDevice;

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
            
            if (g_bulk_state == BULK_STATE_CONNECT)
            {
                /* we received received "SetConfig" from host, and the LLD has 
                 * finished handling SetConfig.
                 * Need to wait a little just in case the host sends some extra 
                 * request (observed Linux host sending 2 Get String Descriptors 
                 * but not on Windows)
                 */
                usb_osalDelayMs(500);
                g_bulk_state = BULK_STATE_READY;
            }
        }
        
        if (g_bulk_state == BULK_STATE_READY)
        {
            /* start waiting for bulk transfer from USB host 
               USB device cannot send anything to USB host unless USB host asks for it */
            USBD_bulkRead(usb_handle, g_bulkRxBuffer, &rxBytes);

            /* check to see what USB host wants: 
               i.e if USB host wants a demo or a throughput test */
            if (strncmp((char*)g_bulkRxBuffer, "WRITE_THROUGHPUT", 16) == 0)
            {
                /* USB Host wants to do a write throughput. Find out how much data it wants to send us */
                transferSize = findTransferSize((char*)g_bulkRxBuffer, MAX_TRANSFER_SIZE); 

                if (transferSize == 0)
                {
                    consolePrintf("Cannot find the test length info!\n");
                }
                else
                {
                    /* note that console printf prints to UART which is slow and causes USB host to retry 
                       many times resulting many POLL or NAK.
                       Since we intentionally leave the printf here, the host program needs 
                       to delay a bit after it sends the string command out before it actually performs the test */
                    consolePrintf("About to do write throughput test by receving %d bytes\n", transferSize);

                    /* USB host is about to send to us a lot of bulk packets */
                    doUsbBulkWriteThroughput(usb_handle, transferSize);
                }
            }
            else if (strncmp((char*)g_bulkRxBuffer, "READ_THROUGHPUT", 15) == 0)
            {
                /* USB Host wants to do a read throughput. Find out how much data it wants us to send */
                transferSize = findTransferSize((char*)g_bulkRxBuffer, MAX_TRANSFER_SIZE);

                if (transferSize == 0)
                {
                    consolePrintf("Cannot find the test length info!\n");
                }
                else
                {
                    /* note console printf prints to UART which is very slow 
                       The USB host might time out with these prints. 
                       Since we intentionally leave the printf here, the host program needs 
                       to delay a bit after it sends the string command out before it actually 
                       performs the test. Or we can implement some handsake mechanism which the device 
                       sends back to host a message saying it's ready for multiple packets */
                    consolePrintf("About to do read throughput test by sending %d bytes\n", transferSize);

                    doUsbBulkReadThroughput(usb_handle, transferSize);
                }
            }
            else if (strncmp((char*)g_bulkRxBuffer, "DEMO", 4) == 0)
            {
                /* we aren't asked to do any of the new throughput test. Doing regular demo then */
                consolePrintf("About to do echo test\n");
                doUsbBulkDemo(usb_handle);
            }
              
        }

        if (g_ulFlags & COMMAND_PACKET_RECEIVED)
        {
            /* printf will cause problem if host PC keeps sending or expecting data 
               since it will delay our response to host PC */
            /* consolePrintf("Rx: %d bytes\n", g_rxBytes); */
            g_ulFlags &= ~COMMAND_PACKET_RECEIVED;
        }
        if (g_ulFlags & COMMAND_PACKET_SENT)
        {
            /* printf to UART console is slow. It will delay our reponse to host PC 
               and causes time out at host PC if host PC is doing a lot of reading / sending */
            /* consolePrintf("Total Tx: %d\n", g_ulTxCount); */
            g_ulFlags &= ~COMMAND_PACKET_SENT;
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

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(BUILD_MCU))
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

//*****************************************************************************
// This function is called back from USB LLD generic bulk class
// it is mostly running in interrupt context.
// pvCBData is the
// ulEvent is USB Lib USB events
// ulMsgValue value depends on the Events.
//    For RX_AVAILABLE, TX_COMPLETE events, the ulMsgValue will be the number
//    of bytes received or transmitted, respectively
// for Generic Bulk class, pvMsgData will be mostly NULL
//
//*****************************************************************************
uint32_t
usbdbulkEventCallback(struct usbGadgetObj *pGadgetObject,
                       void *pvCBData, uint32_t ulEvent,
                       uint32_t ulMsgValue, void *pvMsgData)
{
    //
    // Which event have we been sent?
    //
    switch(ulEvent)
    {
        case USB_EVENT_CONNECTED:
        {
            g_pcStatus = "host connected\n";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            
            g_bulk_state = BULK_STATE_CONNECT;
            break;
        }

        case USB_EVENT_DISCONNECTED:
        {
            g_pcStatus = "host disconnected\n";
            g_ulFlags |= COMMAND_STATUS_UPDATE;
            
            g_bulk_state = BULK_STATE_DISCONNECT;
            break;
        }
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
