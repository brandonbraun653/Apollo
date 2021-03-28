/**
 *  \file  fatfsport.c
 *
 *  \brief This file implements user interface example utils.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#include <string.h>
#include "types.h"
#include "fatfs_port.h"
#include "fatfs_port_mmcsd.h"
#include "ff.h"
#include "diskio.h"
#include "mmcsd_lib.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief A macro to make it easy to add result codes to the table. */
#define FRESULT_ENTRY(f)        { (f), (#f) }

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief A structure that holds a mapping between an FRESULT numerical code,
 *        and a string representation.  FRESULT codes are returned from FatFs
 *        FAT file system driver.
 */
typedef struct fatFsPortResultStr
{
    FRESULT fResult;
    /**< File function return value. */
    char *pResultStr;
    /**< String of file function return value. */
} fatFsPortResultStr_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Check FATFS drive is registered.
 *
 * \param   pDrv        FATFS drive.
 *
 * \retval  TRUE        Registered.
 * \retval  FALSE       Not registered.
 */
static int32_t FatFsPortIsDrvReg(fatFsPortDrv_t *pDrv);

/**
 * \brief   Check FATFS device is registered.
 *
 * \param   pDev        FATFS device.
 *
 * \retval  TRUE        Registered.
 * \retval  FALSE       Not registered.
 */
static int32_t FatFsPortIsDevReg(fatFsPortDev_t *pDev);

/**
 * \brief   Check file system is already mounted.
 *
 * \param   pFatFs      FAT file system.
 *
 * \retval  TRUE        Mounted.
 * \retval  FALSE       Not mounted.
 */
static int32_t FatFsPortIsFatFsReg(FATFS *pFatFs);

/**
 * \brief   Check given drive name is used by registered frive.
 *
 * \param   pDrvName    FATFS drive name.
 *
 * \retval  TRUE        Used.
 * \retval  FALSE       Not used.
 */
static int32_t FatFsPortIsDrvNameUsed(char *pDrvName);

/**
 * \brief   Check given device name is used by registered device.
 *
 * \param   pDevName    FATFS device name.
 *
 * \retval  TRUE        Used.
 * \retval  FALSE       Not used.
 */
static int32_t FatFsPortIsDevNameUsed(char *pDevName);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief String for file function return code. */
fatFsPortResultStr_t gfResultStrings[] =
{
    FRESULT_ENTRY(FR_OK),
    /**< Succeeded. */
    FRESULT_ENTRY(FR_DISK_ERR),
    /**< A hard error occurred in the low level disk I/O layer. */
    FRESULT_ENTRY(FR_INT_ERR),
    /**< Assertion failed. */
    FRESULT_ENTRY(FR_NOT_READY),
    /**< The physical drive cannot work. */
    FRESULT_ENTRY(FR_NO_FILE),
    /**< Could not find the file. */
    FRESULT_ENTRY(FR_NO_PATH),
    /**< Could not find the path. */
    FRESULT_ENTRY(FR_INVALID_NAME),
    /**< The path name format is invalid. */
    FRESULT_ENTRY(FR_DENIED),
    /**< Access denied due to prohibited access or directory full. */
    FRESULT_ENTRY(FR_EXIST),
    /**< Access denied due to prohibited access. */
    FRESULT_ENTRY(FR_INVALID_OBJECT),
    /**< The file/directory object is invalid. */
    FRESULT_ENTRY(FR_WRITE_PROTECTED),
    /**< The physical drive is write protected. */
    FRESULT_ENTRY(FR_INVALID_DRIVE),
    /**< The logical drive number is invalid. */
    FRESULT_ENTRY(FR_NOT_ENABLED),
    /**< The volume has no work area. */
    FRESULT_ENTRY(FR_NO_FILESYSTEM),
    /**< There is no valid FAT volume. */
    FRESULT_ENTRY(FR_MKFS_ABORTED),
    /**< The f_mkfs() aborted due to any parameter error. */
    FRESULT_ENTRY(FR_TIMEOUT),
    /**< Could not get a grant to access the volume within defined period. */
    FRESULT_ENTRY(FR_LOCKED),
    /**< The operation is rejected according to the file sharing policy. */
    FRESULT_ENTRY(FR_NOT_ENOUGH_CORE),
    /**< LFN working buffer could not be allocated. */
    FRESULT_ENTRY(FR_TOO_MANY_OPEN_FILES),
    /**< Number of open files > _FS_SHARE. */
    FRESULT_ENTRY(FR_INVALID_PARAMETER)
    /**< Given parameter is invalid. */
};

/** \brief Devices configured with FATFS. */
fatFsPortDev_t *gPortFatFsDevs[MAX_DEVICES];

/** \brief Drives configured with FATFS. */
fatFsPortDrv_t *gPortFatFsDrvs[MAX_DRIVES];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

uint32_t FATFSPortDiskInitialize(fatFsPortDev_t *pDev)
{
    uint32_t stat = STA_NOINIT;

    if(NULL != pDev)
    {
        stat = RES_OK;
    }

    if(RES_OK == stat)
    {
        if(RES_OK != pDev->initStatus)
        {
            switch (pDev->devType)
            {
                case FATFS_PORT_DEV_TYPE_MMCSD:
                {
                    stat = FATFSPortMmcsdDiskInitialize((mmcsdLibCardInfo_t *) pDev->pIntrf);
                    pDev->initStatus = RES_OK;
                    break;
                }
                default:
                {
                    stat = STA_NOINIT;
                    break;
                }
            }
        }
    }

    return stat;
}

uint32_t FATFSPortDiskStatus(fatFsPortDev_t *pDev)
{
    uint32_t stat = STA_NOINIT;

    if(NULL != pDev)
    {
        stat = RES_OK;
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            switch (pDev->devType)
            {
                case FATFS_PORT_DEV_TYPE_MMCSD:
                {
                    stat = FATFSPortMmcsdDiskStatus((mmcsdLibCardInfo_t *) pDev->pIntrf);
                    break;
                }
                default:
                {
                    stat = STA_NOINIT;
                    break;
                }
            }
        }
    }

    return stat;
}

uint32_t FATFSPortDiskRead(fatFsPortDev_t *pDev, uint8_t *pBuf, uint32_t sector, uint8_t cnt)
{
    uint32_t stat = RES_ERROR;

    if(NULL != pDev)
    {
        stat = RES_OK;
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            switch (pDev->devType)
            {
                case FATFS_PORT_DEV_TYPE_MMCSD:
                {
                    stat = FATFSPortMmcsdDiskRead((mmcsdLibCardInfo_t *) pDev->pIntrf, pBuf, sector, cnt);
                    break;
                }
                default:
                {
                    stat = RES_ERROR;
                    break;
                }
            }
        }
    }

    return stat;}

uint32_t FATFSPortDiskWrite(fatFsPortDev_t *pDev, const uint8_t *pBuf, uint32_t sector, uint8_t cnt)
{
    uint32_t stat = RES_ERROR;

    if(NULL != pDev)
    {
        stat = RES_OK;
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            switch (pDev->devType)
            {
                case FATFS_PORT_DEV_TYPE_MMCSD:
                {
                    stat = FATFSPortMmcsdDiskWrite((mmcsdLibCardInfo_t *) pDev->pIntrf, pBuf, sector, cnt);
                    break;
                }
                default:
                {
                    stat = RES_ERROR;
                    break;
                }
            }
        }
    }

    return stat;
}

uint32_t FATFSPortDiskIoctl(fatFsPortDev_t *pDev, uint8_t cmd, void *pBuf)
{
    uint32_t stat = RES_ERROR;

    if(NULL != pDev)
    {
        stat = RES_OK;
    }

    if(RES_OK == stat)
    {
        if(RES_OK == pDev->initStatus)
        {
            switch (pDev->devType)
            {
                case FATFS_PORT_DEV_TYPE_MMCSD:
                {
                    stat = FATFSPortMmcsdDiskIoctl((mmcsdLibCardInfo_t *) pDev->pIntrf, cmd, pBuf);
                    break;
                }
                default:
                {
                    stat = RES_ERROR;
                    break;
                }
            }
        }
    }

    return stat;
}

uint32_t FATFSPortDrvConfig(fatFsPortDrv_t *pDrv, uint32_t mnt)
{
    uint32_t retValue = MAX_DRIVES;
    uint32_t status = FALSE;
    uint32_t idx = 0U;
    char drive_path[5];

    if(NULL != pDrv)
    {
        if(TRUE == mnt)
        {
            uint32_t freeDrv = MAX_DRIVES;

            if(FALSE == FatFsPortIsDrvReg(pDrv))
            {
                if(FALSE == FatFsPortIsFatFsReg(pDrv->pFatFs))
                {
                    if(FALSE == FatFsPortIsDrvNameUsed(pDrv->pName))
                    {
                        status = TRUE;
                    }
                }
            }

            if(TRUE == status)
            {
                if(FALSE == FatFsPortIsDevReg(pDrv->pDev))
                {
                    if(FALSE == FATFSPortDevConfig(pDrv->pDev, TRUE))
                    {
                        status = FALSE;
                    }
                }
            }

            if(TRUE == status)
            {
                for(idx = 0U; ((TRUE == status) && (idx < MAX_DRIVES)); idx++)
                {
                    if(NULL != gPortFatFsDrvs[idx])
                    {
                        if(pDrv == gPortFatFsDrvs[idx])
                        {
                            status = FALSE;
                        }
                    }
                    else
                    {
                        freeDrv = idx;
                    }

                    if((MAX_DRIVES != freeDrv) && (TRUE == status))
                    {
                        snprintf(drive_path,sizeof(drive_path),"%d:",(int)idx);
                        gPortFatFsDrvs[idx] = pDrv;
                        f_mount(pDrv->pFatFs, drive_path, 0);
                        retValue = idx;
                    }
                }

                if(TRUE == status)
                {
                    if((MAX_DRIVES != freeDrv) && (MAX_DRIVES == idx))
                    {
                        status = FALSE;
                    }
                }
            }
        }
        else if(FALSE == mnt)
        {
            for(idx = 0U; ((FALSE == status) && (idx < MAX_DRIVES)); idx++)
            {
                if(NULL != gPortFatFsDrvs[idx])
                {
                    if(pDrv == gPortFatFsDrvs[idx])
                    {
                        status = TRUE;
                        snprintf(drive_path,sizeof(drive_path),"%d:",(int)idx);
                        FATFSPortDevConfig(pDrv->pDev, FALSE);
                        gPortFatFsDrvs[idx] = NULL;
                        f_mount(NULL, drive_path, 0);
                        retValue = idx;
                    }
                }
            }
        }
        else
        {
            status = FALSE;
        }
    }

    return retValue;
}

uint32_t FATFSPortDevConfig(fatFsPortDev_t *pDev, uint32_t reg)
{
    uint32_t retValue = MAX_DEVICES;
    uint32_t status = FALSE;
    uint32_t idx = 0U;
    uint32_t freeDev = MAX_DEVICES;

    if(NULL != pDev)
    {
        if(TRUE == reg)
        {
            if(FALSE == FatFsPortIsDevNameUsed(pDev->pName))
            {
                if(NULL != pDev->pIntrf)
                {
                    if(pDev->devType < FATFS_PORT_DEV_TYPE_MAX)
                    {
                        status = TRUE;
                    }
                }
            }

            for(idx = 0U; ((TRUE == status) && (idx < MAX_DEVICES)); idx++)
            {
                if(NULL != gPortFatFsDevs[idx])
                {
                    if(pDev == gPortFatFsDevs[idx])
                    {
                        status = FALSE;
                    }
                }
                else
                {
                    freeDev = idx;
                }
            }

            if(TRUE == status)
            {
                if(MAX_DRIVES != freeDev)
                {
                    status = TRUE;
                    gPortFatFsDevs[freeDev] = pDev;
                    retValue = freeDev;
                }
            }
        }
        else if(FALSE == reg)
        {
            for(idx = 0U; ((FALSE == status) && (idx < MAX_DRIVES)); idx++)
            {
                if(NULL != gPortFatFsDevs[idx])
                {
                    if(pDev == gPortFatFsDevs[idx])
                    {
                        status = TRUE;
                        gPortFatFsDevs[idx] = NULL;
                        retValue = idx;
                    }
                }
            }
        }
        else
        {
            status = FALSE;
        }
    }

    return retValue;
}

const char *FATFSPortFResultStringGet(FRESULT fResult)
{
    uint32_t uIdx;

    /* Enter a loop to search the error code table for a matching error code. */
    for(uIdx = 0; uIdx < FR_MAX; uIdx++)
    {
        /*
         * If a match is found, then return the string name of the error code.
         */
        if(gfResultStrings[uIdx].fResult == fResult)
        {
            return(gfResultStrings[uIdx].pResultStr);
        }
    }

    /*
     * At this point no matching code was found, so return a string indicating
     * unknown error.
     */
    return("UNKNOWN ERROR CODE");
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t FatFsPortIsDrvReg(fatFsPortDrv_t *pDrv)
{
    uint32_t retStat = FALSE;
    uint32_t idx = 0U;

    if(NULL != pDrv)
    {
        for(idx = 0U; ((FALSE == retStat) && (idx < MAX_DRIVES)); idx++)
        {
            if(NULL != gPortFatFsDrvs[idx])
            {
                if(pDrv == gPortFatFsDrvs[idx])
                {
                    retStat = TRUE;
                }
            }
        }
    }

    return retStat;
}

static int32_t FatFsPortIsDevReg(fatFsPortDev_t *pDev)
{
    uint32_t retStat = FALSE;
    uint32_t idx = 0U;

    if(NULL != pDev)
    {
        for(idx = 0U; ((FALSE == retStat) && (idx < MAX_DEVICES)); idx++)
        {
            if(NULL != gPortFatFsDevs[idx])
            {
                if(pDev == gPortFatFsDevs[idx])
                {
                    retStat = TRUE;
                }
            }
        }
    }

    return retStat;
}

static int32_t FatFsPortIsFatFsReg(FATFS *pFatFs)
{
    uint32_t retStat = FALSE;
    uint32_t idx = 0U;

    if(NULL != pFatFs)
    {
        for(idx = 0U; ((FALSE == retStat) && (idx < MAX_DRIVES)); idx++)
        {
            if(NULL != gPortFatFsDrvs[idx])
            {
                if(pFatFs == gPortFatFsDrvs[idx]->pFatFs)
                {
                    retStat = TRUE;
                }
            }
        }
    }

    return retStat;
}

static int32_t FatFsPortIsDrvNameUsed(char *pDrvName)
{
    uint32_t retStat = FALSE;
    uint32_t idx = 0U;

    if(NULL != pDrvName)
    {
        for(idx = 0U; ((FALSE == retStat) && (idx < MAX_DRIVES)); idx++)
        {
            if(NULL != gPortFatFsDrvs[idx])
            {
                if(0U == strcmp((char *)pDrvName, (char *)gPortFatFsDrvs[idx]->pName))
                {
                    retStat = TRUE;
                }
            }
        }
    }

    return retStat;
}

static int32_t FatFsPortIsDevNameUsed(char *pDevName)
{
    uint32_t retStat = FALSE;
    uint32_t idx = 0U;

    if(NULL != pDevName)
    {
        for(idx = 0U; ((FALSE == retStat) && (idx < MAX_DEVICES)); idx++)
        {
            if(NULL != gPortFatFsDevs[idx])
            {
                if(0U == strcmp((char *)pDevName, (char *)gPortFatFsDevs[idx]->pName))
                {
                    retStat = TRUE;
                }
            }
        }
    }

    return retStat;
}
