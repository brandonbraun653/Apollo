/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * ======== diskio.c ========
 * Generic definition of all disk APIs.  This should be shared amongst all media
 *
 */
/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/
/* Definitions of physical drive number for each drive */
#define ATA		0	/* Example: Map ATA harddisk to physical drive 0 */
#define MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define USB		2	/* Example: Map USB MSD to physical drive 2 */

#include <stdio.h>
#include <ffconf.h>
#include <diskio.h>

static diskio_fxns drive_fxn_table[_VOLUMES] = {
    {NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL}
};

extern Int32 ti_sysbios_fatfs_getFatTime(void);
/*
 * ======== disk_register ========
 */
DRESULT disk_register(
        BYTE drive,
        DSTATUS (*d_init)   (BYTE drive),
        DSTATUS (*d_status) (BYTE drive),
        DRESULT (*d_read)  (BYTE drive, BYTE *buf, DWORD start, BYTE num),
        DRESULT (*d_write) (BYTE drive, const BYTE *buf, DWORD start, BYTE num),
        DRESULT (*d_ioctl) (BYTE drive, BYTE cmd, void * buf))
{

    if (drive >= _VOLUMES) {
        return RES_PARERR;
    }

    drive_fxn_table[drive].d_init   = d_init;
    drive_fxn_table[drive].d_status = d_status;
    drive_fxn_table[drive].d_read   = d_read;
    drive_fxn_table[drive].d_write  = d_write;
    drive_fxn_table[drive].d_ioctl  = d_ioctl;

    return RES_OK;
}

/*
 * ======== disk_unregister ========
 */
DRESULT disk_unregister(BYTE drive)
{

    if (drive >= _VOLUMES) {
        return RES_PARERR;
    }

    drive_fxn_table[drive].d_init   = NULL;
    drive_fxn_table[drive].d_status = NULL;
    drive_fxn_table[drive].d_read   = NULL;
    drive_fxn_table[drive].d_write  = NULL;
    drive_fxn_table[drive].d_ioctl  = NULL;

    return RES_OK;
}

/*
 * ======== disk_initialize ========
 */
DSTATUS disk_initialize(BYTE drive)
{
    if (drive_fxn_table[drive].d_init == NULL) {
        return RES_PARERR;
    }
    else {
        /* call registered init function */
        return ( (*(drive_fxn_table[drive].d_init)) (drive) );
    }
}

/*
 * ======== disk_status ========
 */
DSTATUS disk_status(BYTE drive)
{
    if (drive_fxn_table[drive].d_status == NULL) {
        return RES_PARERR;
    }
    else {
        /* call registered status function */
        return ( (*(drive_fxn_table[drive].d_status)) (drive) );
    }
}

/*
 * ======== disk_read ========
 */
DRESULT disk_read(BYTE drive, BYTE * buf, DWORD start, UINT num)
{
    if (drive_fxn_table[drive].d_read == NULL) {
        return RES_PARERR;
    }
    else {
        /* call registered read function */
        return ( (*(drive_fxn_table[drive].d_read)) (drive, buf, start, num) );
    }
}

/*
 * ======== disk_write ========
 */
#if     _READONLY == 0
DRESULT disk_write(BYTE drive, const BYTE * buf, DWORD start, UINT num)
{
    if (drive_fxn_table[drive].d_write == NULL) {
        return RES_PARERR;
    }
    else {
        /* call registered write function */
        return ( (*(drive_fxn_table[drive].d_write)) (drive, buf, start, num) );
    }
}
#endif

/*
 * ======== disk_ioctl ========
 */
DRESULT disk_ioctl(BYTE drive, BYTE cmd, void * buf)
{
    if (drive_fxn_table[drive].d_ioctl == NULL) {
        return RES_PARERR;
    }
    else {
        /* call registered write function */
        return ( (*(drive_fxn_table[drive].d_ioctl)) (drive, cmd, buf) );
    }
}

/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */

DWORD get_fattime (void)
{
    return    ((2007UL-1980) << 25) // Year = 2007
            | (6UL << 21)           // Month = June
            | (5UL << 16)           // Day = 5
            | (11U << 11)           // Hour = 11
            | (38U << 5)            // Min = 38
            | (0U >> 1)             // Sec = 0
            ;
}
