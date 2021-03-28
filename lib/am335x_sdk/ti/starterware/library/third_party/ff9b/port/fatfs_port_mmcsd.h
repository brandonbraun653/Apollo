/**
 *  \file  FATFSPort_mmcsd.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         port mmcsd to FATFS.
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

#ifndef FATFS_PORT_MMCSD_H_
#define FATFS_PORT_MMCSD_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "mmcsd_lib.h"
#include "fatfs_port.h"

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
uint32_t FATFSPortMmcsdDiskInitialize(mmcsdLibCardInfo_t *pCard);

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
uint32_t FATFSPortMmcsdDiskStatus(mmcsdLibCardInfo_t *pCard);

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
uint32_t FATFSPortMmcsdDiskRead(mmcsdLibCardInfo_t *pCard, uint8_t *pBuf, uint32_t sector, uint8_t cnt);

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
uint32_t FATFSPortMmcsdDiskWrite(mmcsdLibCardInfo_t *pCard, const uint8_t *pBuf, uint32_t sector, uint8_t cnt);

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
uint32_t FATFSPortMmcsdDiskIoctl(mmcsdLibCardInfo_t *pCard, uint8_t cmd, void *pBuf);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef FATFS_PORT_MMCSD_H_ */
