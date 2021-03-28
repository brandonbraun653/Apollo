/**
 * \file       qspi_flash.c
 *
 * \brief      This file contains information specific to
 *             QSPI flash devices.
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
#include "device.h"
#include "qspi_flash.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/**
 * \brief This global variable contains the device ID of different QSPI
 *        flashes.
 */
uint32_t gQspiFlashDeviceIdList [] =
{
    DEVICE_ID_FLASH_MX66L51235F,
    /**< Micronix qspi flash */
    DEVICE_ID_FLASH_N25Q128A13ESE,
    /**< Micron QSPI flash device */
    DEVICE_ID_INVALID
    /**< Invalid device ID */
};

/**
 * \brief This global contains the device Data for different
 *        QSPI flash devices available.
 *        New data can be added here for future flash devices
 */
qspiFlashDeviceData_t gQspiFlashDeviceData[] =
{
    {
        /* Data for Macronix MX66L51235F flash*/
        DEVICE_ID_FLASH_MX66L51235F, /* devId */
        0x05U, /* QSPI read status register */
        0x01U, /* QSPI write to status register */
        0x6U,  /* Bit to be set to enable quad enable functionality */
        0x1U   /* Value to be written */
    },
    {
        /* Data for micron N25Q128A flash */
        DEVICE_ID_FLASH_N25Q128A13ESE, /* devId */
        0xB5, /* QSPI read non volatile configuration register */
        0xB1, /* QSPI write to non volatile configuration register */
        0x3U, /* Bit to be reset to enable quad functionality */
        0x0U  /* Value to be written */
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

qspiFlashDeviceData_t *QSPIFlashGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gQspiFlashDeviceData) / sizeof(qspiFlashDeviceData_t);
    uint32_t devIndex = 0U;
    qspiFlashDeviceData_t *flashDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gQspiFlashDeviceData[devIndex].devId)
        {
            /* Device Found */
            flashDeviceData = &gQspiFlashDeviceData[devIndex];
            break;
        }
        devIndex++;
    }
    return flashDeviceData;
}

uint32_t * QSPIFlashGetDeviceIdList(void)
{
    return gQspiFlashDeviceIdList;
}
