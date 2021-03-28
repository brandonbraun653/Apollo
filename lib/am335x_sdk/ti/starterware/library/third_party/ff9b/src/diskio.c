/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

#include <types.h>
#include "diskio.h"     /* FatFs lower layer API */
#include "fatfs_port.h"
#include "fatfs_port_mmcsd.h"

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
    BYTE pdrv               /* Physical drive nmuber (0..) */
)
{
    DSTATUS stat = STA_NOINIT;
    fatFsPortDev_t *pDev = NULL;

    if(pdrv < MAX_DRIVES)
    {
        if(NULL != gPortFatFsDrvs[pdrv])
        {
            stat = RES_OK;
        }
    }

    if(RES_OK == stat)
    {
        pDev = gPortFatFsDrvs[pdrv]->pDev;

        if(NULL == pDev)
        {
            stat = STA_NOINIT;
        }
    }

    if(RES_OK == stat)
    {
        if(RES_OK != pDev->initStatus)
        {
            pDev->initStatus = FATFSPortDiskInitialize(pDev);
            stat = pDev->initStatus;
        }
    }

    return stat;
}



/*-----------------------------------------------------------------------*/
/* Get Disk Status                                                       */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
    BYTE pdrv       /* Physical drive nmuber (0..) */
)
{
    DSTATUS stat = STA_NOINIT;
    fatFsPortDev_t *pDev = NULL;

    if(pdrv < MAX_DRIVES)
    {
        if(NULL != gPortFatFsDrvs[pdrv])
        {
            stat = RES_OK;
        }
    }

    if(RES_OK == stat)
    {
        pDev = gPortFatFsDrvs[pdrv]->pDev;

        if(NULL == pDev)
        {
            stat = STA_NOINIT;
        }
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            pDev->initStatus = FATFSPortDiskStatus(pDev);;
            stat = pDev->initStatus;
        }
    }

    return stat;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
    BYTE pdrv,      /* Physical drive nmuber (0..) */
    BYTE *buff,     /* Data buffer to store read data */
    DWORD sector,   /* Sector address (LBA) */
    BYTE count      /* Number of sectors to read (1..128) */
)
{
    DSTATUS stat = RES_ERROR;
    fatFsPortDev_t *pDev = NULL;

    if(pdrv < MAX_DRIVES)
    {
        if(NULL != gPortFatFsDrvs[pdrv])
        {
            stat = RES_OK;
        }
    }

    if(RES_OK == stat)
    {
        pDev = gPortFatFsDrvs[pdrv]->pDev;

        if(NULL == pDev)
        {
            stat = RES_ERROR;
        }
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            stat = FATFSPortDiskRead(pDev, buff, sector, count);
        }
    }

    return stat;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
    BYTE pdrv,          /* Physical drive nmuber (0..) */
    const BYTE *buff,   /* Data to be written */
    DWORD sector,       /* Sector address (LBA) */
    BYTE count          /* Number of sectors to write (1..128) */
)
{
    DSTATUS stat = RES_ERROR;
    fatFsPortDev_t *pDev = NULL;

    if(pdrv < MAX_DRIVES)
    {
        if(NULL != gPortFatFsDrvs[pdrv])
        {
            stat = RES_OK;
        }
    }

    if(RES_OK == stat)
    {
        pDev = gPortFatFsDrvs[pdrv]->pDev;

        if(NULL == pDev)
        {
            stat = RES_ERROR;
        }
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            stat = FATFSPortDiskWrite(pDev, buff, sector, count);
        }
    }

    return stat;
}
#endif



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
    BYTE pdrv,      /* Physical drive nmuber (0..) */
    BYTE cmd,       /* Control code */
    void *buff      /* Buffer to send/receive control data */
)
{
    DSTATUS stat = RES_ERROR;
    fatFsPortDev_t *pDev = NULL;

    if(pdrv < MAX_DRIVES)
    {
        if(NULL != gPortFatFsDrvs[pdrv])
        {
            stat = RES_OK;
        }
    }

    if(RES_OK == stat)
    {
        pDev = gPortFatFsDrvs[pdrv]->pDev;

        if(NULL == pDev)
        {
            stat = RES_ERROR;
        }
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            stat = FATFSPortDiskIoctl(pDev, cmd, buff);
        }
    }

    return stat;
}
#endif

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
