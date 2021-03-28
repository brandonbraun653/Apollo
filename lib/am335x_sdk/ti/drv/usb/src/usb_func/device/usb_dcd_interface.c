/**
 * \file    usb_dcd_interface.c
 *
 * \brief
 *
 *          This file defines the interface between the usb device core and the
 *          device controller drivers. Device controller drivers(dcd) register
 *          with usb device protocol core. The protocol core expects a set of
 *          function pointers to be populated by the device controller with its
 *          own implementation and uses them to take care of enumeration and
 *          normal data traffic. The dcd inturn uses a set of call backs to
 *          interact with the host for event handling.
 *
 */
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




/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include <string.h>
/*Stack specific header files follow.*/
#include "usb_dcd_interface.h"
#include "usb_dev_dman.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
extern usbGadgetObj_t gadgetList [ MAX_NUM_DEVICE_CONTROLLERS ];
 /** \brief extern'd Gadget list.*/
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

usbDcd_t * USBDcdIntfAllocateDcdObject( void )
{
    uint32_t index = 0U;
    usbDcd_t *pDcd = NULL;
    /*Iterate through the gadget list and check for a free object */
    for (index = 0U; index < MAX_NUM_DCDS; ++index)
    {
        if ( 0 == gadgetList[index].objectUsed )
        {
          pDcd = &(gadgetList[index].dcd);
        }

    }
    return (pDcd);
}

/*
 This function registers the dcd object (in turn the Device controller)
 with the device protocol core. The gadget object obtains a pointer
 to the device controller object through this function.
*/
uint32_t USBDcdIntfRegisterDcd(usbDcd_t **pDcdObjPtr, const char * name )
{

/*
    1. check if the max number of dcds have been already registered. If yes ,
    return fail status . If no, copy the dcd object pointer to the first
    available  gadget object. Additionaly check whether this dcd object has been
    registered before.
*/
    uint32_t index = 0U;
    uint32_t registrationStatus = (uint32_t)E_FAIL;
    #ifdef DEBUG_MACRO
    /* Put debug prints here */
    #endif
    if (NULL == pDcdObjPtr)
    {
        registrationStatus = (uint32_t)E_INVALID_PARAM;
    }
    else
    {
        /* forcing reuse of the gadget Idx 0 - until 
         * we can support multiple gadget at same time.
         */
        gadgetList[0].objectUsed = 0;

        /*Iterate through the gadget list and check for a free slot */
        for (index = 0U; index < MAX_NUM_DCDS; ++index)
        {
            if (0 == gadgetList[index].objectUsed)
            {
               /* free slot*/
               gadgetList[index].objectUsed = 1U;
               /*this assignment takes care of gadget object pointer for dcd for
               callbacks. */
               *pDcdObjPtr = &(gadgetList[index].dcd);

               gadgetList[index].dcd.pGadgetObject =  &(gadgetList[index]);
               gadgetList[index].dcd.registered = 1U;

               USBDeviceInit( &gadgetList[index], gadgetList[index].name );
               registrationStatus = S_PASS;
               break;
            }
            else if ( (&gadgetList[index].dcd )== *pDcdObjPtr )
            {
                /* Already registered */
                registrationStatus = S_PASS;
                break;
            }

        }
    }
    return( registrationStatus );
}

/**
 * \brief   Unregister the dcd from the core.
 *
 * \param   pDcdObj pointer to usb dcd interface object
 *          - #usbDcd_t
 */
void USBDcdIntfUnRegisterDcd( usbDcd_t *pDcdObj )
{
    uint32_t index = 0U;
    /*Iterate through the gadget list and free the registration */
    for (index = 0U; index < MAX_NUM_DCDS; ++index)
    {
        if ( gadgetList[index].dcd.privateData == pDcdObj )
        {
          gadgetList[index].objectUsed = 0U;
          gadgetList[index].dcd.pGadgetObject = NULL;
          gadgetList[index].dcd.privateData = 0U;
        }

    }
}

