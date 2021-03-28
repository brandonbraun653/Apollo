/**
 *  \file  read_write_app_main.c
 *
 *  \brief This application code will demonstrate the write and read to
 *         QSPI flash device using QSPI controller. The read is done in
 *         single, dual and quad mode in configuration mode
 *         and memory mapped mode.
 *         It supports only single write. No dual or quad write is suppported.
 *
 *         Flash must be erased before initiating a write command as write can
 *         only change the contents of flash from 1 to 0. To change the contents
 *         from 0 to 1, first an erase must be performed.
 *         This example demonstrates block erase of block 0,
 *         and read/write 1024 words.
 *         By default the QSPI controller is in Quad memory mapped read mode,
 *         but this can be later changed from the console.
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
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  This API generates random data to be written to the flash
 *
 *  \param  srcAddr  Address where pattern is to be generated.
 *                   This pattern is written to the QSPI flash.
 *  \param  destAddr This address will store the data read from QSPI flash
 *                   All values at destAddr are set to 0 in this API.
 *  \param  length   length of data.
 *
 * \retval None
 */
static void QspiAppGeneratePattern(uint32_t *srcAddr,
                                   uint32_t *destAddr,
                                   uint32_t length);

/**
 * \brief  This API verify that data written is same as data read.
 *
 * \param  srcAddr Address of data written to the QSPI flash.
 * \param  destAddr Address of data read from the QSPI flash.
 * \param  length of data to be verified
 *
 * \retval S_PASS Data written to flash is same as data read
 * \retval E_FAIL Data written ot flash is different from the data read
 */
static int32_t QspiAppVerifyData(uint32_t *srcAddr,
                                 uint32_t *destAddr,
                                 uint32_t length);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief  Global structure for QSPI instance related data */
static qspiAppObj_t gQspiAppReadWriteObj;

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

/** \brief Global variable to store data to be written to flash */
static uint32_t gQspiAppReadWriteTxBuf[1024U];
/** \brief Global variable to store data read back from the flash */
static uint32_t gQspiAppReadWriteRxBuf[1024U];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    qspiFlashDeviceData_t *flashDeviceData;
    qspiLibInfo_t qspiLibInfo;

    /* Object containing the QSPI flash device and controller info */
    int32_t status = S_PASS;
    uint32_t offsetAddr;
    uint32_t blockNumber;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();
    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare QSPI Read Write Application!!\n");

    gQspiAppReadWriteObj = QSPIAPPOBJ_DEFAULT;
    qspiLibInfo = gQspiAppReadWriteObj.qspiLibInfo;

    /* The length of data in bytes to be transferred to QSPI Flash */
    gQspiAppReadWriteObj.length = 4U * MEM_SIZE_KB;
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get Board Info for QSPI*/
    status = QSPIAppBoardInfoGet(&gQspiAppReadWriteObj);
    if(S_PASS == status)
    {
        /* Get SOC info for QSPI*/
        status = QSPIAppSocInfoGet(&gQspiAppReadWriteObj);
        if (S_PASS == status)
        {
            /* Clock and pinmux configurations for QSPI  */
            QSPIAppInit(&gQspiAppReadWriteObj);
            /* TODO Set the QSPI config base address
               Hard coded for now.
            */
            qspiLibInfo.qspiLibCtrlInfo.cfgBaseAddr = QSPI_CONFIG_BASE_ADDR;
            /* Set the QSPI memory mapped base Address from chibdb*/
            qspiLibInfo.qspiLibCtrlInfo.memMapBaseAddr = gQspiAppReadWriteObj.instAddr;
            qspiLibInfo.qspiLibCtrlInfo.chipSelect = gQspiAppReadWriteObj.chipSelect;

            /* Initialise the QPSI controller */
            QSPILibInit(&qspiLibInfo);
            /* Display manufacturer and device ID of QSPI flash */
            QSPILibPrintId(&qspiLibInfo);
            do
            {
                blockNumber = 0U;
                offsetAddr = 0x0;
                /* Read Write test */
                /* Generate a pattern to be written to the flash device */
                QspiAppGeneratePattern(gQspiAppReadWriteTxBuf,
                                       gQspiAppReadWriteRxBuf,
                                       gQspiAppReadWriteObj.length);
                /* first erase the flash area where the data is to be written
                * This erases one block of 64 KB from the flash device
                */

                QSPILibBlockErase(&qspiLibInfo, blockNumber);

                CONSOLEUtilsPrintf("\nSUCCESS!!!\nBlock erase successful");
                /* Write length  bytes to QSPI flash in selected mode*/
                QSPILibWrite(&qspiLibInfo,
                            offsetAddr,
                            (uint32_t) gQspiAppReadWriteTxBuf,
                            gQspiAppReadWriteObj.length);

                /* Read length number of bytes from serial flash from offsetAddr = 0*/

                flashDeviceData = QSPIFlashGetDeviceData(gQspiAppReadWriteObj.devId);
                if(QSPI_LIB_READ_TYPE_QUAD == qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType)
                {
                    /* Enter quad mode if Quad read mode is selected */
                    QSPILibQuadEnable(&qspiLibInfo, flashDeviceData);
                }
                QSPILibRead(&qspiLibInfo,
                            offsetAddr,
                           (uint32_t) gQspiAppReadWriteRxBuf,
                            gQspiAppReadWriteObj.length);
                /* Verify that the data read is same as data written */
                status = QspiAppVerifyData(gQspiAppReadWriteRxBuf,
                                           gQspiAppReadWriteTxBuf,
                                           gQspiAppReadWriteObj.length);

                if(status == S_PASS)
                {
                   CONSOLEUtilsPrintf("\nSUCCESS!!!\nRead Write test passed ");
                }
                else
                {
                    CONSOLEUtilsPrintf("\nFAILURE!!!\nRead Write test failed ");
                }
                CONSOLEUtilsPrintf("\n\n\nStarting Again ... \n");
                CONSOLEUtilsPrintf("\nEnter 1 for memory mapped read/write\n");
                CONSOLEUtilsPrintf("Enter 2 for config mode read write\n");
                uint32_t mode;
                CONSOLEUtilsScanf("%d", &mode);

                if(1U == mode)
                {
                    qspiLibInfo.qspiLibCtrlInfo.qspiLibTxMode = QSPI_LIB_TX_MODE_MEMORY_MAPPED;
                } else if(2U == mode)
                {
                    qspiLibInfo.qspiLibCtrlInfo.qspiLibTxMode = QSPI_LIB_TX_MODE_CONFIG_MODE;
                } else
                {
                    /* Default mode is memory mapped mode */
                    CONSOLEUtilsPrintf("Sorry Wrong option! Setting to memory mapped mode\n");
                    qspiLibInfo.qspiLibCtrlInfo.qspiLibTxMode = QSPI_LIB_TX_MODE_MEMORY_MAPPED;
                }
                CONSOLEUtilsPrintf("\nEnter 1 for read type as single read\n");
                CONSOLEUtilsPrintf("Enter 2 for read type as dual read\n");
                CONSOLEUtilsPrintf("Enter 3 for read type as quad read \n");
                uint32_t readType;
                CONSOLEUtilsScanf("%d",&readType);
                switch(readType)
                {
                    case 1U:
                        qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType = QSPI_LIB_READ_TYPE_SINGLE;
                        break;
                    case 2U:
                        qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType = QSPI_LIB_READ_TYPE_DUAL;
                        break;
                    case 3U:
                        qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType = QSPI_LIB_READ_TYPE_QUAD;
                        break;
                    default:
                        /* By default the read type is quad */
                        CONSOLEUtilsPrintf("Sorry Wrong Option! Setting to quad read mode\n");
                        qspiLibInfo.qspiLibCtrlInfo.qspiLibReadType = QSPI_LIB_READ_TYPE_QUAD;
                        break;
                }
            } while(1U);
        }
        else
        {
            CONSOLEUtilsPrintf("This example is not supported on this SOC\n ");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board\n");
    }
    return (S_PASS);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void QspiAppGeneratePattern(uint32_t *srcAddr,uint32_t *destAddr, uint32_t length)
{
    uint32_t index;
    for(index = 0U; index < length/4U; index++)
    {
        /* Writing increementing data to the flash device */
        srcAddr[index] = index;
        destAddr[index] = 0U;
    }
}

static int32_t QspiAppVerifyData(uint32_t *srcAddr, uint32_t *destAddr, uint32_t length)
{
    int32_t status = S_PASS;
    int index = 0U;
    for(index = 0U; index < length/4U; index++)
    {
        if(srcAddr[index] != destAddr[index])
        {
            status = E_FAIL;
        }
    }
    return status;
}

