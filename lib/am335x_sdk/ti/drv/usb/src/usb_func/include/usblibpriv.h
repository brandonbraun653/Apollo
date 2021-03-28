/****************************************************************************** */
/* usblibpriv.h - Private header file used to share internal variables and */
/*                function prototypes between the various modules in the USB */
/*                library.  This header MUST NOT be used by application code. */
/****************************************************************************** */
/**
 *
 *  ============================================================
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


#ifndef PDK__USBLIBPRIV_H
#define PDK__USBLIBPRIV_H

/****************************************************************************** */
/* If building with a C++ compiler, make all of the definitions in this header */
/* have a C binding. */
/****************************************************************************** */
#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************** */
/* Internal interrupt handlers called from the main vectors in device and */
/* host mode. */
/****************************************************************************** */
extern void USBDeviceIntHandlerInternal(uint32_t ulIndex,
                                 uint32_t ulStatus, uint32_t *ePStatus);
extern void USBHostIntHandlerInternal(uint32_t ulIndex,
                                      uint32_t ulStatus, uint32_t *endPStatus);

/****************************************************************************** */
/* These defines are used to register the tick handlers used by the stack. */
/* These handlers are internal to the stack and should never be called directly */
/* by an application. */
/****************************************************************************** */
#define USB_TICK_HANDLER_OTG        0   /* OTG mode tick handler. */
#define USB_TICK_HANDLER_DEVICE     1   /* Device mode tick handler. */
#define USB_TICK_HANDLER_HOST       2   /* Host mode tick handler. */
#define USB_TICK_HANDLER_NUM        3   /* Total number of tick handlers. */

/****************************************************************************** */
/* This value defines the number of SOF ticks that must pass before a call */
/* is made to InternalUSBStartOfFrameTick.  The value 5 ensures that the */
/* function is called every 5 milliseconds assuming that SOF interrupts are */
/* enabled and SOF is present. */
/****************************************************************************** */
#define USB_SOF_TICK_DIVIDE 5

/****************************************************************************** */
/* Tick handler function pointer type. */
/****************************************************************************** */
typedef void(* tUSBTickHandler)(void *pvInstance, uint32_t ulTicksmS,
                                                        uint32_t ulIndex);

/****************************************************************************** */
/* Internal functions use to initialize the tick handler and register tick */
/* callbacks. */
/****************************************************************************** */
extern void InternalUSBTickInit(void);
extern void InternalUSBRegisterTickHandler(uint32_t ulHandler,
                                           tUSBTickHandler pfHandler,
                                           void *pvInstance);
extern void InternalUSBStartOfFrameTick(uint32_t ulTicksmS,
                                        uint32_t ulIndex);
extern void InternalUSBHCDSendEvent(uint32_t ulIndex, uint32_t ulEvent);

/****************************************************************************** */
/* g_ulCurrentUSBTick holds the elapsed time in milliseconds since the */
/* tick module was first initialized based on calls to the function */
/* InternalUSBStartOfFrameTick.  The granularity is USB_SOF_TICK_DIVIDE */
/* milliseconds. */
/****************************************************************************** */
extern uint32_t g_ulCurrentUSBTick;

/****************************************************************************** */
/* g_ulUSBSOFCount is a global counter for Start of Frame interrupts.  It is */
/* incremented by the low level device- or host-mode interrupt handlers. */
/****************************************************************************** */
extern uint32_t g_ulUSBSOFCount;

/****************************************************************************** */
/* InternalUSBGetTime is a macro which will return the system time in */
/* milliseconds as calculated based on calls to the function */
/* InternalUSBStartOfFrameTick.  The granularity is USB_SOF_TICK_DIVIDE */
/* milliseconds. */
/* Currently, this merely returns the value of a global variable. */
/****************************************************************************** */
#define InternalUSBGetTime() g_ulCurrentUSBTick

/****************************************************************************** */
/* Mark the end of the C bindings section for C++ compilers. */
/****************************************************************************** */
#ifdef __cplusplus
}
#endif

#endif /* PDK__USBLIBPRIV_H */
