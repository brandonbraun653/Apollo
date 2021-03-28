/**
 *  \file  usbdmscglue.c
 *
 *  \brief This file contains the data structures defining the
 *         USB mass storage device.
 */

/**
 * \copyright  Copyright (C) 2017-2019 Texas Instruments Incorporated -
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
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
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

#define MMCSD_INSTANCE_SDCARD   0
#define MMCSD_INSTANCE_EMMC   1

#ifdef USB_DEVICE_EMMC
#define MMCSD_INSTANCE MMCSD_INSTANCE_EMMC
#else
#define MMCSD_INSTANCE MMCSD_INSTANCE_SDCARD
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


MMCSD_Handle handle = NULL;

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
    MMCSD_open(MMCSD_INSTANCE, NULL, &handle);
    return((void *)handle);
}


void
USBDMSCStorageClose(void * pvDrive)
{
    ASSERT(pvDrive != 0);
    /* Clear all flags */
    MMCSD_close(handle);

    /* on AM335x SOC, we might need to reset the USB core and restart
       the USB stack */
    g_resetUsb = 1;
}


uint32_t USBDMSCStorageRead(void * pvDrive,
                                 uint8_t *pucData,
                                 uint32_t ulSector,
                                 uint32_t ulNumBlocks)
{
    MMCSD_Error retVal = MMCSD_OK;

    ASSERT(pvDrive != 0);

    retVal = MMCSD_read(pvDrive, pucData, ulSector, ulNumBlocks);
    if (retVal == MMCSD_OK)
    {
        return(ulNumBlocks * 512);
    }
    else
    {
        return 0;
    }
}

uint32_t USBDMSCStorageWrite(void * pvDrive,
                                  uint8_t *pucData,
                                  uint32_t ulSector,
                                  uint32_t ulNumBlocks)
{
    MMCSD_Error retVal = MMCSD_OK;

    ASSERT(pvDrive != 0);
    retVal = MMCSD_write(pvDrive, pucData, ulSector, ulNumBlocks);

    if (retVal == MMCSD_OK)
        return(ulNumBlocks * 512);
    else
        return 0;
}

uint64_t
USBDMSCStorageNumBlocks(void * pvDrive)
{
    MMCSD_mediaParams  mediaParams;
    MMCSD_Error ret;

    uint64_t ulSectorCount = 0;

    ret=MMCSD_control(handle, MMCSD_CMD_GETMEDIAPARAMS, (void *)&mediaParams);

    if(ret != MMCSD_OK)
    {
       return 0;
    }

    //consolePrintf("SD Card: BlockSize = %d,  BlockCount = %d, CardSize = %d\n",
    //              mediaParams.blockSize, mediaParams.blockCount, mediaParams.size);

    ulSectorCount = mediaParams.blockCount;

    return(ulSectorCount);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */
