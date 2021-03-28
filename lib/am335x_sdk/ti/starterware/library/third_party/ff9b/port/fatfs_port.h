/**
 *  \file  fatfsport.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
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

#ifndef FATFS_PORT_H_
#define FATFS_PORT_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include "ff.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*****************************************************************************
A macro to make it easy to add result codes to the table.
******************************************************************************/
#define MAX_DRIVES               (_VOLUMES)

/*****************************************************************************
A macro to make it easy to add result codes to the table.
******************************************************************************/
#define MAX_DEVICES              (2U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates configurations for device type.
 */
typedef enum
{
    FATFS_PORT_DEV_TYPE_MMCSD,
    /**< MMCSD. */
    FATFS_PORT_DEV_TYPE_USB,
    /**< USB. */
    FATFS_PORT_DEV_TYPE_MAX
    /**< Invalid. */
} fatFsPortDevType_t;

/**
 *  \brief Structure defining a device for FATFS.
 */
typedef struct fatFsPortDev
{
    uint32_t devType;
    /**< Device type. */
    char *pName;
    /**< Device name. */
    void *pIntrf;
    /**< Device interface. */
    uint32_t initStatus;
    /**< Device initialization status. */
} fatFsPortDev_t;

/**
 *  \brief Structure defining a drive for FATFS.
 */
typedef struct fatFsPortDrv
{
    char *pName;
    /**< Drive name. */
    fatFsPortDev_t *pDev;
    /**< FATFS device. */
    FATFS *pFatFs;
    /**< FATFS File system entry for the drive. */
} fatFsPortDrv_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief Devices configured with FATFS. */
extern fatFsPortDev_t *gPortFatFsDevs[MAX_DEVICES];

/** \brief Drives configured with FATFS. */
extern fatFsPortDrv_t *gPortFatFsDrvs[MAX_DRIVES];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initialize drive of a device.
 *
 * \param   pDev        FATFS device.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  STA_NOINIT  Drive not initialized.
 * \retval  STA_NODISK  No medium in the drive.
 * \retval  STA_PROTECT Write protected.
 */
uint32_t FATFSPortDiskInitialize(fatFsPortDev_t *pDev);

/**
 * \brief   Check initialize drive of a device.
 *
 * \param   pDev        FATFS device.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  STA_NOINIT  Drive not initialized.
 * \retval  STA_NODISK  No medium in the drive.
 * \retval  STA_PROTECT Write protected.
 */
uint32_t FATFSPortDiskStatus(fatFsPortDev_t *pDev);

/**
 * \brief   Read data from drive of a device.
 *
 * \param   pDev        FATFS device.
 * \param   pBuf        Buffer to read data.
 * \param   sector      Start sector.
 * \param   cnt         Number of sectors to be read.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  RES_ERROR   R/W Error.
 * \retval  RES_WRPRT   Write Protected.
 * \retval  RES_NOTRDY  Not Ready.
 * \retval  RES_PARERR  Invalid Parameter.
 */
uint32_t FATFSPortDiskRead(fatFsPortDev_t *pDev, uint8_t *pBuf, uint32_t sector, uint8_t cnt);

/**
 * \brief   Write data to drive of a device.
 *
 * \param   pDev        FATFS device.
 * \param   pBuf        Buffer to write data.
 * \param   sector      Start sector.
 * \param   cnt         Number of sectors to be written.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  RES_ERROR   R/W Error.
 * \retval  RES_WRPRT   Write Protected.
 * \retval  RES_NOTRDY  Not Ready.
 * \retval  RES_PARERR  Invalid Parameter.
 */
uint32_t FATFSPortDiskWrite(fatFsPortDev_t *pDev, const uint8_t *pBuf, uint32_t sector, uint8_t cnt);

/**
 * \brief   Write data to drive of a device.
 *
 * \param   pDev        FATFS device.
 * \param   cmd         Command to be executed.
 * \param   pBuf        Data buffer.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  RES_ERROR   R/W Error.
 * \retval  RES_WRPRT   Write Protected.
 * \retval  RES_NOTRDY  Not Ready.
 * \retval  RES_PARERR  Invalid Parameter.
 */
uint32_t FATFSPortDiskIoctl(fatFsPortDev_t *pDev, uint8_t cmd, void *pBuf);

/**
 * \brief   Mount/Unmount a drive.
 *
 * \param   pDrv        FATFS drive.
 * \param   mnt         Mount/Unmount. Possible values are.
 *                      - TRUE  Mount.
 *                      - FALSE Unmount.
 *
 * \retval  TRUE        Success.
 * \retval  FALSE       Failed.
 */
uint32_t FATFSPortDrvConfig(fatFsPortDrv_t *pDrv, uint32_t mnt);

/**
 * \brief   Register/Unregister a device.
 *
 * \param   pDev        FATFS device.
 * \param   reg         Register/Unregister. Possible values are.
 *                      - TRUE  Register.
 *                      - FALSE Unregister.
 *
 * \retval  TRUE        Success.
 * \retval  FALSE       Failed.
 */
uint32_t FATFSPortDevConfig(fatFsPortDev_t *pDev, uint32_t reg);

/**
 * \brief   Status string for given file function return value.
 *
 * \param   fResult File function return value.
 *
 * \retval  string - String for file function return value.
 */
const char *FATFSPortFResultStringGet(FRESULT fResult);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef FATFS_PORT_H_ */
