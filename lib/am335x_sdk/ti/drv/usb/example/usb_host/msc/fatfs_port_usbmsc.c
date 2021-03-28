
/*-----------------------------------------------------------------------*/
/* USB - FATFS interface                                                 */
/*-----------------------------------------------------------------------*/

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

#include <ti/fs/fatfs/diskio.h>
#include "usblib.h"
#include "usbmsc.h"
#include "usbhost.h"
#include "usbhmsc.h"
#include <ti/fs/fatfs/ff.h>

extern tUSBHMSCInstance g_USBHMSCDevice[];

static volatile
uint32_t USBStat = STA_NOINIT;    /* Disk status */

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/

int32_t
FATFSPortUSBDiskInitialize(void)         

{
	void* ulMSCInstance;

	ulMSCInstance = &g_USBHMSCDevice[0];/* Physical drive number (0) - no hub support */
	
	/* Set the not initialized flag again. If all goes well and the disk is */
    /* present, this will be cleared at the end of the function.            */
    USBStat |= STA_NOINIT;

    /* Find out if drive is ready yet. */
    if (USBHMSCDriveReady(ulMSCInstance)) return(FR_NOT_READY);

    /* Clear the not init flag. */
    USBStat &= ~STA_NOINIT;

    return 0;
}



/*-----------------------------------------------------------------------*/
/* Returns the current status of a drive                                 */
/*-----------------------------------------------------------------------*/

uint32_t FATFSPortUSBDiskStatus (
    uint32_t drv)                      /* Physical drive number (0) */
{
    if (drv) return STA_NOINIT;        /* Supports only single drive */
    return USBStat;
}



/*-----------------------------------------------------------------------*/
/* This function reads sector(s) from the disk drive                     */
/*-----------------------------------------------------------------------*/

int32_t FATFSPortUSBDiskRead (
    void* drv,
    uint8_t* buff,          /* Pointer to the data buffer to store read data */
    uint32_t sector,        /* Starting sector */
    uint32_t count)         /* Sector count (1..255) */
{
	void* ulMSCInstance;

	if(USBStat & STA_NOINIT)
    {
        return(RES_NOTRDY);
    }

    ulMSCInstance = &g_USBHMSCDevice[0]; // no hub support so only one drive

    /* READ BLOCK */
    if (USBHMSCBlockRead(ulMSCInstance, sector, buff, count) == 0)
        return RES_OK;

    return RES_ERROR;
}



/*-----------------------------------------------------------------------*/
/* This function writes sector(s) to the disk drive                     */
/*-----------------------------------------------------------------------*/
int32_t FATFSPortUSBDiskWrite (
    void* usbDrv,           
    uint8_t* buff,       /* Pointer to the data to be written */
    uint32_t sector,           /* Start sector number (LBA) */
    uint32_t count)             /* Sector count (1..255) */
{
	void* ulMSCInstance;

	ulMSCInstance = &g_USBHMSCDevice[0];  /* Physical drive number (0) */

	
    if (!count) return RES_PARERR;
    if (USBStat & STA_NOINIT) return RES_NOTRDY;
    if (USBStat & STA_PROTECT) return RES_WRPRT;

    /* WRITE BLOCK */
    if(USBHMSCBlockWrite(ulMSCInstance, sector, (uint8_t *)buff, count) == 0)
        return RES_OK;

    return RES_ERROR;
}

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

int32_t FATFSPortUSBDiskIoctl (
    void* usbDrv,               /* Physical drive number (0) */
    uint32_t ctrl,              /* Control code */
    void *buff)                 /* Buffer to send/receive control data */
{
    if(USBStat & STA_NOINIT)
    {
        return(RES_NOTRDY);
    }

    switch(ctrl)
    {
        case CTRL_SYNC:
            return(RES_OK);

        default:
            return(RES_PARERR);
    }
}

/*-----------------------------------------------------------------------*/
/* closeDrvFxn                                                           */
/*-----------------------------------------------------------------------*/
int32_t FATFSPortUSBDiskClose(void* handle)
{
    return RES_OK;
}

/*-----------------------------------------------------------------------*/
/* openDrvFxn                                                            */
/*-----------------------------------------------------------------------*/
int32_t FATFSPortUSBDiskOpen(uint32_t index, void* params, void** handle)
{
    return RES_OK;
}
