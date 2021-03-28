/**
 * \file   nand_device.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         NAND Flash devices and global structure containing the
 *         NAND Flash timing parameters.
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
#include "device.h"
#include "nand_device.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

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

/** \brief Array holding the supported NAND device IDs. */
uint32_t gNandDeviceIdList[] =
{
    DEVICE_ID_FLASH_MT29F2G08ABAEAWP,
    /**< NAND 2Gb Flash Id. */
    DEVICE_ID_FLASH_MT29F4G08ABAEAWP,
    /**< NAND 4Gb Flash Id. */
    DEVICE_ID_INVALID
    /**< Invalid device ID. */
};

/** \brief Structure holding the device parameters for different NAND flash. */
nandDeviceData_t gNandDeviceData[] =
{
    {
        DEVICE_ID_FLASH_MT29F2G08ABAEAWP,   /* flashId */
        0U,    /* 8 bit Device */           /* busWdith */
        0U,    /* Active low Polarity */    /* waitPinPol */
        1U,     /* Pin Level High */         /* writeProtectPinLvl */
        {
            0U,  /* csOnTime */
            7U,  /* csRdOffTime */
            7U,  /* csWrOffTime */
            0U,  /* advOnTime */
            0U,  /* advRdOffTime */
            7U,  /* advWrOffTime */
            0U,  /* weOnTime */
            5U,  /* weOffTime */
            0U,  /* oeOnTime */
            5U,  /* oeOffTime */
            0U,  /* pageBurstAccessTime */
            6U,  /* rdAccessTime */
            6U,  /* wrAccessTime */
            7U,  /* rdCycleTime */
            7U,  /* wrCycleTime */
            7U,  /* wrDataOnMuxBusTime */
            0U,  /* cycleDelay */
        }
    },
    {
        DEVICE_ID_FLASH_MT29F4G08ABAEAWP,   /* flashId */
        0U,    /* 8 bit Device */           /* busWdith */
        0U,    /* Active low Polarity */    /* waitPinPol */
        1U,    /* Pin Level High */         /* writeProtectPinLvl */
        {
            0U,  /* csOnTime */
            7U,  /* csRdOffTime */
            7U,  /* csWrOffTime */
            0U,  /* advOnTime */
            0U,  /* advRdOffTime */
            7U,  /* advWrOffTime */
            0U,  /* weOnTime */
            5U,  /* weOffTime */
            0U,  /* oeOnTime */
            5U,  /* oeOffTime */
            0U,  /* pageBurstAccessTime */
            6U,  /* rdAccessTime */
            6U,  /* wrAccessTime */
            7U,  /* rdCycleTime */
            7U,  /* wrCycleTime */
            7U,  /* wrDataOnMuxBusTime */
            0U,  /* cycleDelay */
        }
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

nandDeviceData_t *NANDGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gNandDeviceData) / sizeof(nandDeviceData_t);
    uint32_t devIndex = 0U;
    nandDeviceData_t *pNandDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gNandDeviceData[devIndex].flashId)
        {
            /* Device Found */
            pNandDeviceData = &gNandDeviceData[devIndex];
            break;
        }
    }
    return pNandDeviceData;
}

uint32_t * NANDGetDeviceIdList(void)
{
    return gNandDeviceIdList;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */
