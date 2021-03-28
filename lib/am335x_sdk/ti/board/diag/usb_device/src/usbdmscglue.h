/******************************************************************************
 * Copyright (c) 2017-2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
*  \file  usbdmscglue.h
*
*  \brief   Prototypes for functions supplied for use by the mass storage
*           class device.
*/
 
#ifndef USBDMSCGLUE_H_
#define USBDMSCGLUE_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "usblib.h"
#include "usbdevice.h"
#include "usbdmsc.h"
#include "usb_msc_structs.h"
#include "ramdiskutils.h"
#include "usb-ids.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */
#ifdef DEBUG
#define ASSERT(expr) {                                      \
                         if(!(expr))                        \
                         {                                  \
                             __error__(__FILE__, __LINE__); \
                         }                                  \
                     }
#else
#define ASSERT(expr)
#endif

#define SDCARD_PRESENT          0x00000001
#define SDCARD_IN_USE           0x00000002

#define USBDMSC_IDLE            0x00000000
#define USBDMSC_NOT_PRESENT     0x00000001


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief This function opens the drive number and prepares it for use by the Mass
 *         storage class device.
 *
 *  \param ulDrive is the driver number to open.
 *
 * This function is used to initialize and open the physical drive number
 * associated with the parameter /e ulDrive.  The function will return zero if
 * the drive could not be opened for some reason.  In the case of removable
 * device like an SD card this function should return zero if the SD card is
 * not present.
 *
 * \retval Returns a pointer to data that should be passed to other APIs or it
 *         will return 0 if no drive was found.
 */
extern void * USBDMSCStorageOpen(uint32_t ulDrive);

/**
 * \brief This function closes the drive number in use by the mass storage class device.
 *
 * \param pvDrive is the pointer that was returned from a call to
 *        USBDMSCStorageOpen().
 *
 * This function is used to close the physical drive number associated with the
 * parameter /e pvDrive.  This function will return 0 if the drive was closed
 * successfully and any other value will indicate a failure.
 *
 * \retval Returns 0 if the drive was successfully closed or non-zero for a
 * failure.
 */extern void USBDMSCStorageClose(void * pvDrive);

/**
 *  \brief This function will read a block from a device opened by the
 *         USBDMSCStorageOpen() call.
 *
 *  \param pvDrive is the pointer that was returned from a call to
 *         USBDMSCStorageOpen().
 *  \param pucData is the buffer that data will be written into.
 *  \param ulNumBlocks is the number of blocks to read.
 *
 * This function is use to read blocks from a physical device and return them
 * in the /e pucData buffer.  The data area pointed to by /e pucData should be
 * at least /e ulNumBlocks * Block Size bytes to prevent overwriting data.
 *
 * /retval Returns the number of bytes that were read from the device.
 */
extern uint32_t USBDMSCStorageRead(void * pvDrive,
                                   uint8_t *pucData,
                                   uint32_t ulSector,
                                   uint32_t ulNumBlocks);

/**
 *  \brief This function will write a block to a device opened by the
 *         USBDMSCStorageOpen() call.
 *
 *  \param pvDrive is the pointer that was returned from a call to
 *         USBDMSCStorageOpen().
 *  \param pucData is the buffer that data will be used for writing.
 *  \param ulNumBlocks is the number of blocks to write.
 *
 * This function is use to write blocks to a physical device from the buffer
 * pointed to by the /e pucData buffer.  If the number of blocks is greater than
 * one then the block address will increment and write to the next block until
 * /e ulNumBlocks * Block Size bytes have been written.
 *
 * /return Returns the number of bytes that were written to the device.
 */
extern uint32_t USBDMSCStorageWrite(void * pvDrive,
                                    uint8_t *pucData,
                                    uint32_t ulSector,
                                    uint32_t ulNumBlocks);


/**
 * \brief This function will return the number of blocks present on a device.
 *
 *  \param pvDrive is the pointer that was returned from a call to
 *         USBDMSCStorageOpen().
 *
 * This function is used to return the total number of blocks on a physical
 * device based on the /e pvDrive parameter.
 *
 * \retval return Returns the number of blocks that are present in a device.
 */
uint32_t USBDMSCStorageNumBlocks(void * pvDrive);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef USBDMSCGLUE_H */
