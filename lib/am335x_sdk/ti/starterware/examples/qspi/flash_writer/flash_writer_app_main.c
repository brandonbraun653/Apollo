/**
 *  \file  flash_writer_app_main.c
 *
 *  \brief This application reads the images from mmcsd and
 *         copies them into qspi flash.
 *         It expects a file name config in the sd card which
 *         contains the name of the image to be flashed and the offset
 *         where it need to be flashed.
 *         Sample config file can be as :
 *         boot 0
 *         app 80000
 *         So this application will copy file named boot to offset 0
 *         of QSPI flash and app at offset 80000.
 *         It erases contents of flash before writing. The flash is erased
 *         in chunks of 64KB blocks.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "board.h"
#include "chipdb.h"
#include "soc.h"
#include "device.h"
#include "console_utils.h"
#include "misc.h"
#include "example_utils_mmu.h"
#include "cache.h"
#include "mmu.h"
#include "stdlib.h"

/* MMCSD and FS related header files */
#include "mmcsd_lib.h"
#include "ff.h"
#include "diskio.h"
#include "fatfs_port.h"
#include "fatfs_port_mmcsd.h"
#include "hsmmcsd_app_pol.h"

/* QSPI related header files */
#include "qspi_flash.h"
#include "qspi_lib.h"
#include "qspi.h"

/* Application header files */
#include "qspi_app.h"


/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */

/** \brief Base address of QSPI ctrl module */
#define QSPI_CONFIG_BASE_ADDR              (0x47900000U)

/** \brief Maximum buffer size. */
#define MMCSD_DATA_BUF_SIZE                 (512U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function initializes the MMCSD controller and mounts the device.
 */
static void QspiMmcsdInit(void);

/**
 * \brief This API copies the flash image from MMCSD to DDR
 *
 * \param fileName Name of the file to be copied.
 * \param destAddr Address where the file is to be copied
 * \param fileSize Total size of the file read
 *
 * \retval status S_PASS Image copy passed
 * \retval status E_FAIL Image copy failed
 */
static int32_t MmcsdImageCopy(char * fileName,
                               uint32_t destAddr,
                               uint32_t * fileSize);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief  Global structure for QSPI instance related data */
static qspiAppObj_t gQspiAppFlashWriterObj;

/** \brief Default configuration for QSPI */
static const qspiAppObj_t QSPIAPPOBJ_DEFAULT =
{
    0U,  /* chipSelect */
    0U,  /* instNum */
    0U,  /* instAddr */
    DEVICE_ID_INVALID,  /* devId */
    0U,  /* length*/
    {
        {
            0U, /* chipSelect */
            0U, /* memMapBaseAddr */
            0U, /* cfgBaseAddr */
            QSPI_LIB_READ_TYPE_QUAD, /* qspiLibReadType */
            QSPI_LIB_TX_MODE_MEMORY_MAPPED, /* qspiLibTxMode */
        },
        {
            (64U * MEM_SIZE_MB),/* deviceSize */
            0x19U,/* flashDevId */
            0xC2,/* flashMfgId */
            (4U * MEM_SIZE_KB),/* sectorSize */
            (64U * MEM_SIZE_KB),/* blockSize */
        }
    }
};

/**
 * \brief MMCSD card info object.
 */
ALIGN_VAR(sdCard, 32U)
mmcsdLibCardInfo_t sdCard;

/**
 * \brief MMCSD controller info object.
 */
ALIGN_VAR(ctrlInfo, 32U)
mmcsdLibCtrlInfo_t ctrlInfo;

/**
 * \brief Temporary data buffer to be used while copying data
 *        from SD card to DDR.
 */
ALIGN_VAR(gTmpBuf, 32U)
static char gTmpBuf[MMCSD_DATA_BUF_SIZE];

/**
 * \brief FAT fs object.
 */
static FATFS gFatFs;

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

int main(void)
{
    FRESULT fResult;

    static FIL fileObject;

    qspiFlashDeviceData_t *flashDeviceData;
    /* Object containing the QSPI flash device and controller info */
    qspiLibInfo_t qspiLibInfo;

    /* File name which need to be copied from mmcsd to QSPI */
    char fileName[9U];
    /* Offset address where the flash image is to be written */
    int offsetAddr = 0U;

    /* DDR address where image has to be copied from mmcsd card.
     * The image is then copied from this address to QSPI flash
     */
    uint32_t destAddr = 0x82000000U;

    /* First block which has to be erased */
    uint32_t startBlockNumber = 0U;
    /* The last block which has to be erased */
    uint32_t endBlockNumber = 0U;
    /* Temporary variable for loops */
    uint32_t i;

    int32_t status = E_FAIL;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();
    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare QSPI Flash Writer!!\n");

    gQspiAppFlashWriterObj = QSPIAPPOBJ_DEFAULT;
    qspiLibInfo = gQspiAppFlashWriterObj.qspiLibInfo;
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    QspiMmcsdInit();

    if (S_PASS == status)
    {
        /* Get Board Info for QSPI*/
        status = QSPIAppBoardInfoGet(&gQspiAppFlashWriterObj);
    }
    else
    {
        CONSOLEUtilsPrintf("Board Init Failed \n");
    }

    if(S_PASS == status)
    {
        /* Get SOC info for QSPI*/
        status = QSPIAppSocInfoGet(&gQspiAppFlashWriterObj);
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board\n");
    }

    if (S_PASS == status)
    {
        /* Clock and pinmux configurations for QSPI  */
        status = QSPIAppInit(&gQspiAppFlashWriterObj);
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this SOC\n ");
    }

    if (S_PASS == status)
    {
        /* TODO Set the QSPI config base address
           Hard coded for now.
         */
        qspiLibInfo.qspiLibCtrlInfo.cfgBaseAddr = QSPI_CONFIG_BASE_ADDR;
        /* Set the QSPI memory mapped base Address from chibdb*/
        qspiLibInfo.qspiLibCtrlInfo.memMapBaseAddr = gQspiAppFlashWriterObj.instAddr;
        qspiLibInfo.qspiLibCtrlInfo.chipSelect = gQspiAppFlashWriterObj.chipSelect;

        /* Initialise the QPSI controller */
        QSPILibInit(&qspiLibInfo);
        /* Display manufacturer and device ID of QSPI flash */
        QSPILibPrintId(&qspiLibInfo);

        /* Open the config file and read the file name and parameters */
        fResult = f_open(&fileObject, "config", FA_READ);

        if(FR_OK == fResult)
        {
            status = S_PASS;
        }
        /* If there was some problem opening the file, then return an error. */
        else
        {
            status = E_FAIL;
            CONSOLEUtilsPrintf("\r\n Unable to open config file \r\n");
        }
        if (S_PASS == status)
        {
            while(0U != f_gets(gTmpBuf, sizeof(gTmpBuf), &fileObject))
            {
                if ( -1 != sscanf(gTmpBuf,"%s %x", fileName, &offsetAddr))
                {
                    status = S_PASS;
                }
                else
                {
                    status = E_FAIL;
                    CONSOLEUtilsPrintf("\nSorry! Something wrong in config file\n");
                    CONSOLEUtilsPrintf("\nPlease check if file is in format shown below\n");
                    CONSOLEUtilsPrintf("\nboot 0\napp 80000\n");
                }
                if (S_PASS == status)
                {
	                gQspiAppFlashWriterObj.length = 0U;
                    status = MmcsdImageCopy(fileName,
                                            destAddr,
                                            &gQspiAppFlashWriterObj.length);
                }
                if (S_PASS == status)
                {
                    /* Computing the block numbers to be erased  */
                    startBlockNumber = (offsetAddr / qspiLibInfo.qspiLibFlashInfo.blockSize);
                    endBlockNumber = (offsetAddr + gQspiAppFlashWriterObj.length) /
                                      qspiLibInfo.qspiLibFlashInfo.blockSize;

                    for (i = startBlockNumber; i <= endBlockNumber; i++)
                    {
                        QSPILibBlockErase(&qspiLibInfo, i);
                    }
                    /* Write image to QSPI flash */
                    QSPILibWrite(&qspiLibInfo,
                                 offsetAddr,
                                 destAddr,
                                 gQspiAppFlashWriterObj.length);
                 }
                 else
                 {
                     /* Image copy from MMCSD failed */
                 }
             }
             /* Close the file here */
             f_close(&fileObject);
        }
        else
        {
            /* config file could not be opened */
        }
        /* The quad mode has to be enabled while flashing image as it cannot be
         * done while booting and the ROM code expects the Flash to be
         * in quad mode.
         * So this change to quad mode is required here.
         */
        CONSOLEUtilsPrintf("Changing read to quad mode ");

        flashDeviceData = QSPIFlashGetDeviceData(gQspiAppFlashWriterObj.devId);
        if(QSPI_LIB_READ_TYPE_QUAD == qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType)
        {
            /* Enter quad mode if Quad read mode is selected */
            QSPILibQuadEnable(&qspiLibInfo, flashDeviceData);
        }
        CONSOLEUtilsPrintf("\nRead mode has been changed to Quad mode \n");
        CONSOLEUtilsPrintf("SUCCESS!!!\n");
        CONSOLEUtilsPrintf("Flashing completed \n");
    }

    return (S_PASS);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void QspiMmcsdInit(void)
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

static int32_t MmcsdImageCopy(char * fileName,
                              uint32_t destAddr,
                              uint32_t * fileSize)
{
    FRESULT fResult;
    static FIL fileObject;
    uint32_t bytesRead = 0U;
    int32_t status = E_FAIL;
    /* Open the file for reading */
    fResult = f_open(&fileObject, fileName, FA_READ);

    if(FR_OK == fResult)
    {
        status = S_PASS;
    }
    /* If there was some problem opening the file, then return an error. */
    else
    {
        CONSOLEUtilsPrintf("\r\n Unable to open file %s \r\n", fileName);
    }

    if(S_PASS == status)
    {
        /*
         * Enter a loop to repeatedly read data from the file and display it, until
         * the end of the file is reached.
         */
        CONSOLEUtilsPrintf("Copying %s to QSPI Flash \n", fileName);
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in the
             * temporary buffer, including a space for the trailing null.
             */
            fResult = f_read(&fileObject, gTmpBuf, sizeof(gTmpBuf) - 1,
                             (unsigned int *) &bytesRead);

            /*
             * If there was an error reading, then print a newline and return the
             * error to the user.
             */
            if(fResult != FR_OK)
            {
                CONSOLEUtilsPuts("\r\n Error reading application file\r\n");
                status = E_FAIL;
            }

            if(bytesRead >= sizeof(gTmpBuf))
            {
                status = E_FAIL;
            }

            /* Read the last chunk of the file that was received. */
            memcpy((uint32_t *)destAddr, gTmpBuf, (sizeof(gTmpBuf) - 1));
            destAddr += (sizeof(gTmpBuf) - 1);
            /*
             * Continue reading until less than the full number of bytes are read.
             * That means the end of the buffer was reached.
             */
            *(fileSize) += bytesRead;
        }
        while((bytesRead == sizeof(gTmpBuf) - 1) && (S_PASS == status));
        /* Close the file. */
        fResult = f_close(&fileObject);
        if (E_FAIL == status)
        {
            CONSOLEUtilsPrintf(" Read failed for %s\n",fileName);
        }
    }
    return status;
}
