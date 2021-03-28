/**
 * \file   tcpecho_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case. For hoat pc setup please refer to client
 *         application in tools/enet_client.
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
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "mmu.h"
#include "soc_control.h"
#include "example_utils_mmu.h"
#include "console_utils.h"
#include "mmcsd_lib.h"
#include "hsmmcsd_lib_port.h"
#include "ff.h"
#include "diskio.h"
#include "fatfs_port.h"
#include "fatfs_port_mmcsd.h"
#include "fs_shell_app_utils.h"
#include "hsmmcsd_app_pol.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=FS_SHELL_APP_UTILS_CACHELINE_SIZE
static mmcsdLibCardInfo_t sdCard;

#elif defined(__TMS470__)
#pragma DATA_ALIGN(sdCard, FS_SHELL_APP_UTILS_CACHELINE_SIZE);
static mmcsdLibCardInfo_t sdCard;

#elif defined(gcc)
static mmcsdLibCardInfo_t sdCard  __attribute__ ((aligned (FS_SHELL_APP_UTILS_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=FS_SHELL_APP_UTILS_CACHELINE_SIZE
static mmcsdLibCtrlInfo_t ctrlInfo;

#elif defined(__TMS470__)
#pragma DATA_ALIGN(ctrlInfo, FS_SHELL_APP_UTILS_CACHELINE_SIZE);
static mmcsdLibCtrlInfo_t ctrlInfo;

#elif defined(gcc)
static mmcsdLibCtrlInfo_t ctrlInfo  __attribute__ ((aligned (FS_SHELL_APP_UTILS_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

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

int main()
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare MMCSD FS Shell Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* MMCSD IP configuration */
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

    while(1)
    {
        FSShellAppUtilsProcess();
    }

    return (S_PASS);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*              Use-case specific Internal Function Definitions               */
/* -------------------------------------------------------------------------- */
