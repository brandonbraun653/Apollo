/**
 *  \file  sbl_mmcsd.c
 *
 * \brief  This file copy the application binary from card to DDR.
 *
 *  \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
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
#include "mmcsd_lib.h"
#include "ff.h"
#include "diskio.h"
#include "fatfs_port.h"
#include "fatfs_port_mmcsd.h"
#include "console_utils.h"
#include "hsmmcsd_app_pol.h"
#include "sbl_copy.h"
#include "sbl_mmcsd.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum buffer size. */
#define SBL_MMCSD_DATA_BUF_SIZE                 (512U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function initializes the MMCSD controller and mounts the device.
 *
 * \param instNum  MMCSD Instance number.
 */
static void SblMmcsdInit(uint32_t instNum);

/**
 * \brief This function copies the application image to the DDR by reading the
 *       header info.
 *
 * \param  pEntryPoint  Entry address read from TI image header.
 *
 * \retVal TRUE         Image copy successful.
 * \retVal FALSE        Image copy failed.
 */
static uint32_t SblMmcsdImageCopy(uint32_t *pEntryPoint, uint32_t* imageSize);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/**
 * \brief Card and Controller information.
 *
 * TODO: Modify data alignment to cacheline size of SOC
 */
#ifdef __IAR_SYSTEMS_ICC__

#pragma data_alignment=32U
mmcsdLibCardInfo_t sdCard;
#pragma data_alignment=32U
mmcsdLibCtrlInfo_t ctrlInfo;
#pragma data_alignment=32U
static char gTmpBuf[SBL_MMCSD_DATA_BUF_SIZE];

#elif defined(__TMS470__)

#pragma DATA_ALIGN(sdCard, 32U);
mmcsdLibCardInfo_t sdCard;
#pragma DATA_ALIGN(ctrlInfo, 32U);
mmcsdLibCtrlInfo_t ctrlInfo;
#pragma DATA_ALIGN(gTmpBuf, 32U);
static char gTmpBuf[SBL_MMCSD_DATA_BUF_SIZE];

#else

mmcsdLibCardInfo_t sdCard __attribute__ ((aligned (32U)));
mmcsdLibCtrlInfo_t ctrlInfo __attribute__ ((aligned (32U)));
static char gTmpBuf[SBL_MMCSD_DATA_BUF_SIZE] __attribute__ ((aligned (32U)));

#endif

/**
 * \brief FAT fs object.
 */
static FATFS gFatFs;

/**
 * \brief File object.
 */
static FIL gFileObject;

/**
 * \brief Device.
 */
fatFsPortDev_t gDevice;

/**
 * \brief Drive.
 */
fatFsPortDrv_t gDrive;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t SBLMmcsdCopy(uint32_t *pEntryPoint, uint32_t* imageSize, uint32_t instNum)
{
    uint32_t retVal = FALSE;

    SblMmcsdInit(instNum);
    retVal = SblMmcsdImageCopy(pEntryPoint, imageSize);

    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void SblMmcsdInit(uint32_t instNum)
{
    HSMMCSDAppPolInit(&ctrlInfo, &sdCard, 0U);

    gDevice.devType = FATFS_PORT_DEV_TYPE_MMCSD;
    gDevice.pName = "CARD";
    gDevice.pIntrf = &sdCard;
    gDevice.initStatus = STA_NOINIT;

    gDrive.pName = "MMCSD0";
    gDrive.pDev = &gDevice;
    gDrive.pFatFs = &gFatFs;

    FATFSPortDevConfig(&gDevice, TRUE);
    FATFSPortDrvConfig(&gDrive, TRUE);
}

static uint32_t SblMmcsdImageCopy(uint32_t *pEntryPoint, uint32_t* imageSize)
{
    FRESULT fResult;
    uint32_t bytesRead = 0U;
    ti_header imageHdr;
    uint8_t *pDestAddr;
    char *pFileName = "/app";
    uint32_t retStat = FALSE;
    uint32_t tmpSize = 0;

    /* Open the file for reading. */
    fResult = f_open(&gFileObject, pFileName, FA_READ);

    if(FR_OK == fResult)
    {
        retStat = TRUE;
    }
    /* If there was some problem opening the file, then return an error. */
    else
    {
        CONSOLEUtilsPuts("\r\n Unable to open application file\r\n");
    }

    if(TRUE == retStat)
    {
        CONSOLEUtilsPuts("Copying application image from MMC/SD card to RAM\r\n");
        fResult = f_read(&gFileObject, (uint8_t *)&imageHdr, 8U,
                         (uint32_t *)&bytesRead);

        if(FR_OK != fResult)
        {
            CONSOLEUtilsPuts("\r\n Error reading application file\r\n");
            retStat = FALSE;
        }

        if(8U != bytesRead)
        {
            retStat = FALSE;
        }

        pDestAddr = (uint8_t *)imageHdr.load_addr;
        *pEntryPoint = imageHdr.load_addr;
        *imageSize   = imageHdr.image_size;
    }

    if(TRUE == retStat)
    {
        /*
         * Enter a loop to repeatedly read data from the file and display it, until
         * the end of the file is reached.
         */
        tmpSize = 8; /* 8-byte header has been read above */
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in the
             * temporary buffer, including a space for the trailing null.
             */
            fResult = f_read(&gFileObject, gTmpBuf, sizeof(gTmpBuf) - 1,
                             (uint32_t *)&bytesRead);

            /*
             * If there was an error reading, then print a newline and return the
             * error to the user.
             */
            if(fResult != FR_OK)
            {
                CONSOLEUtilsPuts("\r\n Error reading application file\r\n");
                retStat = FALSE;
            }

            if(bytesRead >= sizeof(gTmpBuf))
            {
                retStat = FALSE;
            }

            tmpSize += bytesRead;

            /* Read the last chunk of the file that was received. */
            memcpy(pDestAddr, gTmpBuf, (sizeof(gTmpBuf) - 1));
            pDestAddr += (sizeof(gTmpBuf) - 1);
            /*
             * Continue reading until less than the full number of bytes are read.
             * That means the end of the buffer was reached.
             */
        }
        while((bytesRead == sizeof(gTmpBuf) - 1) && (TRUE == retStat));

        /* Close the file. */
        fResult = f_close(&gFileObject);

        if (tmpSize != *imageSize)
        {
            CONSOLEUtilsPuts("\r\n Error reading application file. Size of read data doesn't match header\r\n");
            retStat = FALSE;
        }
    }

    /* Return success. */
    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
