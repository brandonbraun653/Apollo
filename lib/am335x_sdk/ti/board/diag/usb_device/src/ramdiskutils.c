/**
 *  \file  ramdiskutils.c
 *
 *  \brief This file has function definitions which are used for emulating
 *         ramdisk functionality where a part of RAM is allocated as a RAM
 *         disk/drive and this area can be used by different applications.
 *         Usecase:
 *         1) Currently this functionality is used to demonstrate USB MSC
 *            examples where the windows host system can access a part of
 *            RAM allocated as RAMDisk, format it and can create/delete
 *            files.
 *         2) RAMDisk can be used by fsShell utils where the RAMDisk area
 *            can be formatted and files be stored.
 *         3) DSS example can use the RAMDisk to store the captured video
 *            files
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
#include <stdint.h>
#include <string.h>
#include "ramdiskutils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define RAM_DISK_UTILS_LBA_SIZE         (512U)

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint8_t *gpRamDisk;
uint32_t gRamDiskSize;
uint32_t val = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void RAMDISKUtilsInit(uint8_t *pRamDisk, uint32_t size)
{
    gpRamDisk = pRamDisk;
    gRamDiskSize = size;
}

void RAMDISKUtilsRead(uint32_t lba, uint8_t *pBuffer, uint32_t length)
{
    uint32_t  i;
    uint32_t j;
    lba = lba * RAM_DISK_UTILS_LBA_SIZE;
    length = length * RAM_DISK_UTILS_LBA_SIZE;

    if((lba + length) <= gRamDiskSize)
    {
        //memcpy(pBuffer, &gpRamDisk[lba], length);
        j = lba;
        for(i = 0; i < length; i++)
        {
            pBuffer[i] = gpRamDisk[j];
            j++;
        }
    }
    else
    {
        /* Print the necessary error statement */
    }
}

void RAMDISKUtilsWrite(uint32_t lba, uint8_t *pBuffer, uint32_t length)
{
    lba = lba * RAM_DISK_UTILS_LBA_SIZE;
    length = length * RAM_DISK_UTILS_LBA_SIZE;

    if((lba + length) <= gRamDiskSize)
    {
        memcpy(&gpRamDisk[lba], pBuffer, length);
    }
    else
    {
        /* Print the necessary error statement */
    }
}

void RAMDISKUtilsIoctl(uint32_t cmd, uint32_t *pArg)
{
    switch(cmd)
    {
        case RAM_DISK_UTILS_GET_SECTOR_COUNT:
            *pArg = (gRamDiskSize / RAM_DISK_UTILS_LBA_SIZE);
            break;

        case RAM_DISK_UTILS_GET_SECTOR_SIZE:
            *pArg = RAM_DISK_UTILS_LBA_SIZE;
            break;

        default:
            pArg = 0;
            break;
    }
}

