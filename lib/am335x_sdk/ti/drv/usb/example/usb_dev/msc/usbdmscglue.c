/**
 *  \file  usbdmscglue.c
 *
 *  \brief This file contains the data structures defining the
 *         USB mass storage device.
 */

/**
 * \copyright  Copyright (C) 2013-2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

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

struct
{
    uint32_t ulFlags;
}
g_sDriveInformation;


extern uint32_t g_resetUsb;
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void *
USBDMSCStorageOpen(uint32_t ulDrive)
{
    ASSERT(ulDrive == 0);
    g_sDriveInformation.ulFlags = SDCARD_PRESENT | SDCARD_IN_USE;

    return((void *)&g_sDriveInformation);
}


void
USBDMSCStorageClose(void * pvDrive)
{
    ASSERT(pvDrive != 0);
    /* Clear all flags */
    g_sDriveInformation.ulFlags = 0;

    /* on AM335x SOC, we might need to reset the USB core and restart
       the USB stack */
    g_resetUsb = 1;
}


uint32_t USBDMSCStorageRead(void * pvDrive,
                                 uint8_t *pucData,
                                 uint32_t ulSector,
                                 uint32_t ulNumBlocks)
{
    ASSERT(pvDrive != 0);

    RAMDISKUtilsRead(ulSector, pucData, ulNumBlocks);

    return(ulNumBlocks * 512);
}

uint32_t USBDMSCStorageWrite(void * pvDrive,
                                  uint8_t *pucData,
                                  uint32_t ulSector,
                                  uint32_t ulNumBlocks)
{
    ASSERT(pvDrive != 0);
    RAMDISKUtilsWrite(ulSector, pucData, ulNumBlocks);

    return(ulNumBlocks * 512);
}

uint32_t
USBDMSCStorageNumBlocks(void * pvDrive)
{
    uint32_t ulSectorCount = 0;

    /* Read the number of sectors */
    RAMDISKUtilsIoctl(RAM_DISK_UTILS_GET_SECTOR_COUNT, (uint32_t *)&ulSectorCount);
    return(ulSectorCount);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */
