 /******************************************************************************
 *
 * usbdbulkint.h - Internal USBLib support for a generic bulk device.
 *
 * Copyright (c) 2008-2019 Texas Instruments Incorporated.
 *
 ******************************************************************************/
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


#ifndef PDK__USBDBULK_INT_H__
#define PDK__USBDBULK_INT_H__

#include "types.h"
#include "usblib.h"
/******************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 *
 *! \addtogroup bulk_device_class_api
 *! @{
 *
 ******************************************************************************/

/******************************************************************************
 *
 * PRIVATE
 *
 * The first few sections of this header are private defines that are used by
 * the USB Bulk example code and are here only to help with the application
 * allocating the correct amount of memory for the Bulk example device code.
 *
 ******************************************************************************/

/******************************************************************************
 *
 * PRIVATE
 *
 * This enumeration holds the various states that the device can be in during
 * normal operation.
 *
 ******************************************************************************/
typedef enum
{
    /*
     * Unconfigured.
     */
    BULK_STATE_UNCONFIGURED,

    /*
     * No outstanding transaction remains to be completed.
     */
    BULK_STATE_IDLE,

    /*
     * Waiting on completion of a send or receive transaction.
     */
    BULK_STATE_WAIT_DATA,

    /*
     * Waiting for client to process data.
     */
    BULK_STATE_WAIT_CLIENT
} tBulkState;

/******************************************************************************
 *
 * PRIVATE
 *
 * This structure defines the private instance data and state variables for the
 * Bulk only example device.  The memory for this structure is pointed to by
 * the psPrivateBulkData field in the tUSBDBulkDevice structure passed on
 * USBDBulkInit().
 *
 ******************************************************************************/
typedef struct
{
    tDeviceInfo *psDevInfo;
    tConfigDescriptor *psConfDescriptor;
    volatile tBulkState eBulkRxState;
    volatile tBulkState eBulkTxState;
    volatile uint16_t usDeferredOpFlags;
    uint16_t usLastTxSize;
    uint16_t usLastRxSize;
    volatile tBoolean bConnected;
    uint8_t ucINEndpoint;
    uint8_t ucOUTEndpoint;
    uint8_t ucInterface;
    void*   readSem;
    void*   writeSem;
}
tBulkInstance;


/******************************************************************************
 *
 * Close the Doxygen group.
 *! @}
 *
 ******************************************************************************/

/******************************************************************************
 *
 * Mark the end of the C bindings section for C++ compilers.
 *
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif  /* PDK_USBDBULK_INT_H__*/
