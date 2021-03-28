/**
 *  \file  fatfsport_mmcsd.c
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <types.h>
#include "mmcsd_lib.h"
#include "fatfs_port_mmcsd.h"
#include "console_utils.h"
#include "diskio.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

uint32_t FATFSPortMmcsdDiskInitialize(mmcsdLibCardInfo_t *pCard)
{
    uint32_t retVal = STA_NOINIT;
    uint32_t status = FALSE;

    /* SD Card init */
    status = MMCSDLibCardInit(pCard->pCtrl);

    if (FALSE == status)
    {
        CONSOLEUtilsPrintf("\r\nCard Init Failed \r\n", -1);
    }
    else
    {
#if DEBUG
        if (pCard->cardType == MMCSD_LIB_CARD_SD)
        {
            CONSOLEUtilsPrintf("\r\nSD Card ");
            CONSOLEUtilsPrintf("version : %d", pCard->sdVer);

            if (pCard->highCap)
            {
                CONSOLEUtilsPrintf(", High Capacity");
            }

            if (pCard->tranSpeed == MMCSD_LIB_TRANSPEED_50MBPS)
            {
                CONSOLEUtilsPrintf(", High Speed");
            }
        }
        else if (pCard->cardType == MMCSD_LIB_CARD_MMC)
        {
            CONSOLEUtilsPrintf("\r\nMMC Card ", -1);
        }
#endif
        /* Set bus width */
        if (pCard->cardType == MMCSD_LIB_CARD_SD)
        {
            MMCSDLibBusWidthSet(pCard->pCtrl);
        }

        /* Transfer speed */
        MMCSDLibTranSpeedSet(pCard->pCtrl);

        status = TRUE;
    }

    if(TRUE == status)
    {
        retVal = RES_OK;
    }

    return retVal;
}

uint32_t FATFSPortMmcsdDiskStatus(mmcsdLibCardInfo_t *pCard)
{
    return RES_OK;
}

uint32_t FATFSPortMmcsdDiskRead(mmcsdLibCardInfo_t *pCard, uint8_t *pBuf, uint32_t sector, uint8_t cnt)
{
    uint32_t retVal = RES_ERROR;

    /* READ BLOCK */
    if (TRUE == MMCSDLibReadCmdSend(pCard->pCtrl, pBuf, sector, cnt))
    {
        retVal = RES_OK;
    }

    return retVal;
}

uint32_t FATFSPortMmcsdDiskWrite(mmcsdLibCardInfo_t *pCard, const uint8_t *pBuf, uint32_t sector, uint8_t cnt)
{
    uint32_t retVal = RES_ERROR;

    /* WRITE BLOCK */
    if(TRUE == MMCSDLibWriteCmdSend(pCard->pCtrl,(BYTE*) pBuf, sector, cnt))
    {
        retVal = RES_OK;
    }

    return retVal;
}

uint32_t FATFSPortMmcsdDiskIoctl(mmcsdLibCardInfo_t *pCard, uint8_t cmd, void *pBuf)
{
    return RES_OK;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
