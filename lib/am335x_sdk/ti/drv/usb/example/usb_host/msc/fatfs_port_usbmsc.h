/**
 *  \file  FATFSPort_usbmsc.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         port usbmsc to FATFS.
 *
 *  \copyright Copyright (C) 2013-2016 Texas Instruments Incorporated -
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

#ifndef FATFS_PORT_USBMSC_H_
#define FATFS_PORT_USBMSC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


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
int32_t FATFSPortUSBDiskInitialize(void);

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
int32_t FATFSPortUSBDiskStatus(uint32_t usbdrv);

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
int32_t FATFSPortUSBDiskRead(void* usbdrv, uint8_t *pBuf, uint32_t sector, uint32_t cnt);

/**
 * \brief   Write data to drive of a device.
 *
 * \param   usbdrv      FATFS device.
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
int32_t FATFSPortUSBDiskWrite(void* usbdrv, uint8_t *pBuf, uint32_t sector, uint32_t cnt);

/**
 * \brief   Write data to drive of a device.
 *
 * \param   usbDrv      FATFS device.
 * \param   cmd         Command to be executed.
 * \param   pBuf        Data buffer.
 *
 * \retval  RES_OK      Initialized successfully.
 * \retval  RES_ERROR   R/W Error.
 * \retval  RES_WRPRT   Write Protected.
 * \retval  RES_NOTRDY  Not Ready.
 * \retval  RES_PARERR  Invalid Parameter.
 */
int32_t FATFSPortUSBDiskIoctl(void* usbdrv, uint32_t cmd, void *pBuf);


int32_t FATFSPortUSBDiskClose(void* handle);

int32_t FATFSPortUSBDiskOpen(uint32_t index, void* params, void** handle);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef FATFS_PORT_USBMSC_H_ */
