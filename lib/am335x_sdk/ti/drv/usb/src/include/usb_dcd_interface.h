/**
 * \file    usb_dcd_interface.h
 *
 * \brief
 *
 *          This file defines the interface between the usb device core and the
 *          device controller drivers. Device controller drivers(dcd) register
 *          with usb device protocol core. The protocol core expects a set of
 *          function pointers to be populated by the device controller driver
 *          with its  own implementation and uses them to take care of
 *          enumeration and  normal data traffic. The dcd inturn uses a set of
 *          call backs to interact with the host for event handling.
 *
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

#ifndef USB_DCD_INTERFACE_H
#define USB_DCD_INTERFACE_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "usb_dev_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/* TODO : get this information from SOC specific config file*/
#define MAX_NUM_DEVICE_CONTROLLERS (2U)
/** \brief Maximum number of Device controllers in the system.*/

#define MAX_NUM_DCDS (MAX_NUM_DEVICE_CONTROLLERS)
/** \brief Maximum number of Device controllers supported.*/

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/*List of Call backs available to the dcd driver to interact with the core  */

/*  calling metheod - using pointer to parent gadget object
        dcdObject.gadgetObject ->pFnDevEndpt0Handler( gadgetObject);
*/
/* 1. handle Endpoint zero Request - pFnDevEndpt0Handler ( )
   2. Reset handler - pFnResetHandler ()
   3. Suspend Handler - pFnDevSuspendHandler ()
   4. Disconnect Handler - pFnDevDisconnectHandler ()
   5. Generic Interrupt handler - pFnDevGenericIntrHandler
   6. PM handler - pFnDevPMHandler()
*/

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This function returns the first free dcd object - which binds the
 *          specific dcd( for example DWC3) implementation to the core.This is
 *          the first function that the dcd's should call to begin the
 *          registration process.
 *
 * \retval  usbDcd_t - pointer to the dcd core object which is a part of the
 *          the usb device gadget object.
 *          - #usbDcd_t
 */
usbDcd_t * USBDcdIntfAllocateDcdObject( void );

/**
 * \brief   This function registers the dcd object (in turn the Device controller)
 *          with the device protocol core. The gadget object obtains a pointer
 *          to the device controller object through this function.
 *
 * \param   pDcdObjPtr - pointer to pointer to dcdobject. Instantiated by the
 *          specific dcd ( for example DWC3 driver) so that the dcd interface
 *          layer can copy its contents to the usb gadget object to complete
 *          the registration process.
 * \param   name - check for a match between core object name and the specific
 *          dcd name.This way we are able to ensure that any gadget can be
 *          mounted on any particular controller.
 * \note    This function is not re-entrant and hence need to be executed
 *          atomically.
 *
 * \retval error status- Status of the API call. Can be any of the following,
 *      S_PASS - indicates the operation is success
 *      E_FAIL - indicates that registration failed
 *      E_INVALID_PARAM - dcd object pointer not valid
 */
uint32_t USBDcdIntfRegisterDcd( usbDcd_t **pDcdObjPtr, const char * name );


/**
 * \brief   Unregister the dcd from the core.
 *
 * \param   pDcdObj pointer to dcd core object
 *          - #usbDcd_t
 */
void USBDcdIntfUnRegisterDcd( usbDcd_t *pDcdObj );



#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_DCD_INTERFACE_H */
