/**
 *  \file  ramdiskutils.h
 *
 *  \brief This file has functions prototypes which are used for emulating
 *         ramdisk functionality where a part of RAM is allocated as a RAM
 *         disk/drive and this area can be used by different applications.
 *         Usecase:
 *         1) Currently this functionality is used to demonstrate USB MSC
 *            examples where the windows host system can access a part of RAM
 *            allocated as RAMDisk, format it and can create/delete files.
 *         2) RAMDisk can be used by fsShell Utils where the RAMDisk area
 *            can be formatted and files be stored.
 *         3) DSS example can use the RAMDisk to store the captured video
 *            files
 *
 *  \copyright Copyright (C) 2013 - 2017 Texas Instruments Incorporated -
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

#ifndef RAM_DISK_UTILS_H_
#define RAM_DISK_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*
 *  \brief Boot Sector Table Signature Lower 8 bits
 */
#define BOOT_SECTOR_SIGNATURE_55                  (0x55)

/*
 *  \brief Boot Sector Table Signature Higher 8 bits
 */
#define BOOT_SECTOR_SIGNATURE_AA                  (0xAA)

/*
 *  \brief Fat File system Media Type descriptors. Fatfs entry
 *         0 should have this valid media descriptor
 */
#define FATFS_MEDIA_DESCRIPTOR_0                  (0xFFFFFFF8)

#define FATFS_MEDIA_DESCRIPTOR_1                  (0xFFFF0000)

/*
 *  \brief Boot Sector Table Signature offset
 */
#define BS_SIGN_OFFSET                            (510)

/*
 *  \brief FAT FS entry 0 offset for first reserved entry.
 */
#define FF_ENTRY_0                                (0x200/4)

/*
 *  \brief FAT FS entry 1 offset for second reserved entry.
 */
#if defined(SOC_OMAPl137) || defined (SOC_OMAPL138)
#define FF_ENTRY_1                                (0x0A00/4)
#else
#define FF_ENTRY_1                                (0x4200/4)
#endif

/*
 *  \brief FAT FS entry offset for directory cluster 0.
 */
#define FF_DIR_CLUSTER                            (0x8200/4)

/*
 *  \brief FAT FS entry offset for file content.
 */
#define FF_ENTRY_FC                               (0xCA00/4)

/*
 *  \brief FAT FS entry offset for file size.
 */
#define FF_ENTRY_FS                               (0x825C/4)

/*
 *  \brief This macro is passed as a parameter to the function RAMDISKUtilsIoctl
 *         to get the sector size
 */
#define RAM_DISK_UTILS_GET_SECTOR_SIZE             (1U)

/*
 *  \brief This macro is passed as a parameter to the function RAMDISKUtilsIoctl
 *         to get the sector count
 */
#define RAM_DISK_UTILS_GET_SECTOR_COUNT            (2U)

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/*
 * \brief   Initialize the area of RAM to be allocated as a RAMDisk in which
 *          the start address and size of the RAM area are given by the user.
 *
 * \param   pRamDisk             Pointer to the start of memory which is to be
 *                               allocated as RAMDisk
 * \param   size                 Size of the RAMDisk in KBs
 *
 */
void RAMDISKUtilsInit(uint8_t *pRamDisk, uint32_t size);

/*
 * \brief   Read the specified number of blocks from start of RAM disk to the
 *          specified buffer\n
 *
 * \param   lba                  Logical block address
 * \param   pBuffer              Will hold the blocks to be read from the RAM disk
 * \param   length               Number of blocks to be read to the buffer where
 *                               the size of each block is 512 bytes
 *
 */
void RAMDISKUtilsRead(uint32_t lba, uint8_t *pBuffer, uint32_t length);

/*
 * \brief   Write the specified number of blocks from the buffer to the RAM
 *          disk\n
 *
 * \param   lba                  Logical block address
 * \param   pBuffer              Will hold the blocks to be written to RAM disk
 * \param   length               Number of blocks to be written to RAM disk where
 *                               the size of each block is 512 bytes
 *
 */
void RAMDISKUtilsWrite(uint32_t lba, uint8_t *pBuffer, uint32_t length);

/*
 * \brief   Sends a control code to the application causing the application
 *          to perform the corresponding operation\n
 *
 * \param   cmd                  Control code to perform a operation
 * \param   pArg                 Pointer which shall hold the cmd output
 *
 */
void RAMDISKUtilsIoctl(uint32_t cmd, uint32_t *pArg);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef RAM_DISK_UTILS_H_ */
