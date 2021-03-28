/**
 * \file   qspi_app.c
 *
 * \brief  Source file containing the QSPI IP related configuration functions.
 *         These functions will be called by example application.
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
#include "chipdb.h"
#include "pinmux.h"
#include "error.h"
#include "device.h"
#include "soc.h"
#include "board.h"
#include "console_utils.h"
#include "prcm.h"
#include "qspi_flash.h"
#include "qspi_lib.h"

/* Application header files */
#include "qspi_app.h"


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


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t QSPIAppInit(qspiAppObj_t *pQspiObj)
{
    int32_t status = S_PASS;

    status = PRCMModuleEnable(CHIPDB_MOD_ID_QSPI, pQspiObj->instNum, FALSE);

    if(S_PASS == status)
    {
        /** PinMux for QSPI controller */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_QSPI, pQspiObj->instNum, NULL);
        if(S_PASS != status)
        {
            CONSOLEUtilsPrintf("\nFAILURE!!!!\nQSPI PinMuxing failed !\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\nFAILURE!!!!\nQSPI PRCM Module Enable failed !\n");
    }
    return status;
}

int32_t QSPIAppBoardInfoGet(qspiAppObj_t *pQspiObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t qspiInstNum;
    uint32_t chipSelect;
    uint32_t * qspiFlashDeviceIdList;
    uint32_t devIndex = 0U;

    /* Check which QSPI device is present on this board */
    qspiFlashDeviceIdList = QSPIFlashGetDeviceIdList();

    do {
        if (TRUE == BOARDIsDevicePresent(qspiFlashDeviceIdList[devIndex]))
        {
            /* QSPI Flash device found */
            pQspiObj->devId = qspiFlashDeviceIdList[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != qspiFlashDeviceIdList[devIndex]);

    if (DEVICE_ID_INVALID == qspiFlashDeviceIdList[devIndex])
    {
        CONSOLEUtilsPrintf("No QSPI device found \n");
    }
    else
    {
        /* Set the QSPI data for serial flash from board data */
        modId = BOARDGetDeviceCtrlModId(pQspiObj->devId,
            QSPI_APP_DEV_INST_NUM);
        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Invalid device information in board Data\n");
        }
        else if (CHIPDB_MOD_ID_QSPI == modId)
        {
            qspiInstNum = BOARDGetDeviceCtrlModInstNum(pQspiObj->devId,
                QSPI_APP_DEV_INST_NUM);
            chipSelect = BOARDGetDeviceCtrlInfo(pQspiObj->devId,
                QSPI_APP_DEV_INST_NUM);
            if((INVALID_INST_NUM == qspiInstNum) || (INVALID_INFO == chipSelect))
            {
                CONSOLEUtilsPrintf("Invalid QSPI board data!\n");
            }
            else
            {
                pQspiObj->instNum = qspiInstNum;
                pQspiObj->chipSelect  = chipSelect;
                status = S_PASS;
            }
        }
        else
        {
            status = E_FAIL;
            CONSOLEUtilsPrintf("This flash device is not connected to QSPI\n");
        }
    }
    return (status);
}

int32_t QSPIAppSocInfoGet(qspiAppObj_t *pQspiObj)
{
    int32_t status = S_PASS;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_QSPI, pQspiObj->instNum))
    {
        pQspiObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_QSPI,
            pQspiObj->instNum);
    }
    else
    {
        status = E_FAIL;
        /*QSPI instance number is not present . */
    }
    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
