/**
 * \file   board.c
 *
 * \brief  This file contains the implementation of the APIs that abstract the
 *         board-specific details for StarterWare.
 *
 */

/*
* Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include "string.h"
#include "error.h"
#include "debug.h"
#include "board.h"
#include "dcard.h"
#include "platform.h"
#include "device.h"
#include "soc.h"
#include "board_priv.h"
#include "console_utils.h"

#ifdef AM335X_FAMILY_BUILD
#include "board_am335x.h"
#endif /* ifdef AM335X_FAMILY_BUILD */

#ifdef AM43XX_FAMILY_BUILD
#include "board_am43xx.h"
#endif /* ifdef AM43XX_FAMILY_BUILD */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  struct boardIdString_t
 *  \brief Structure to store board ID and string pair.
 */
typedef struct boardIdString
{
    boardId_t boardId;
    /**< Board ID. */
    const char *pBoardIdStr;
    /**< Pointer to board ID string. */
} boardIdString_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function powers on the device on daughter card.
 *
 * \param  devId    Device ID 
 * \param  devInstNum       Device instance number
 * \param  powerOn   Power on or off flag
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
static uint32_t BoardPowerOnDCardDevice(uint32_t devId,
                                 uint32_t devInstNum, 
                                 uint32_t powerOn);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Board module object. */
static boardCommonObj_t gBoardCommonObj;

/** \brief Table containing all board ID strings */
#ifndef DDRLESS
static boardIdString_t  gBoardIdStrTable[] =
{
    {BOARD_UNKNOWN,         "UNKNOWN"         },
    {BOARD_GPEVM,           "GPEVM"           },
    {BOARD_EVMSK,           "EVMSK"           },
    {BOARD_BEAGLEBONE,      "BEAGLEBONE"      },
    {BOARD_IDKEVM,          "IDKEVM"          },
    {BOARD_EPOSEVM,         "EPOSEVM"         },
    {BOARD_BEAGLEBONEBLACK, "BEAGLEBONEBLACK" },
    {BOARD_ICEV1,           "ICE ver 1"       },
    {BOARD_ICEV2,           "ICE Ver 2"       },
    {BOARD_AMIC110,         "AMIC110"         },
    {BOARD_CUSTOM,          "Custom"          }
};
#else
static boardIdString_t  gBoardIdStrTable[] =
{
    {BOARD_AMIC110,         "AMIC110"         }
};
#endif

/** \brief Provides defaults for board initialization parameters. */
const boardInitParams_t BOARDINITPARAMS_DEFAULT =
{
    BOARD_AUTO_DETECT, /* boardId */
    BOARD_AUTO_DETECT, /* baseBoardRev */
    BOARD_AUTO_DETECT  /* dcBoardRev */
};

/** \brief Number of entries in board ID string table. */
#define BOARD_NUM_ID_STR_ENTRIES        (sizeof (gBoardIdStrTable) / \
                                         sizeof (boardIdString_t))


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BOARDInit(const boardInitParams_t *pInitPrms)
{
    int32_t status = S_PASS;
    boardInitParams_t localInitPrms = BOARDINITPARAMS_DEFAULT;

    /* If NULL is passed the parameters will be initialized by default */
    if (NULL == pInitPrms)
    {
        pInitPrms = &localInitPrms;
    }

    /* Check for validity of parameters. If board ID is overridden, then the
     * board revisions must also be overridden. They cannot be specified as
     * auto-detect.
     */
    if ((BOARD_AUTO_DETECT != pInitPrms->boardId) &&
        ((BOARD_AUTO_DETECT == pInitPrms->baseBoardRev) ||
         (BOARD_AUTO_DETECT == pInitPrms->dcBoardRev)))
    {
        status = E_INVALID_PARAM;
    }
    else
    {
        memset(&gBoardCommonObj, 0, sizeof (gBoardCommonObj));

        gBoardCommonObj.boardId      = pInitPrms->boardId;
        gBoardCommonObj.baseBoardRev = pInitPrms->baseBoardRev;
        gBoardCommonObj.dcBoardRev   = pInitPrms->dcBoardRev;

        /* Macro is used insted of checking for SoC. Any SoC API
         * cannot be called in board init as SoC init happens after board
         * init */

#ifdef AM335X_FAMILY_BUILD
        status = BoardAm335xInit(pInitPrms);
#endif /* ifdef AM335X_FAMILY_BUILD */

#ifdef AM43XX_FAMILY_BUILD
        status = BoardAm43xxInit(pInitPrms);
#endif /* ifdef AM43XX_FAMILY_BUILD */
    }

    return (status);
}

int32_t BOARDDeInit(void * args)
{
    int32_t status = S_PASS;

    return (status);
}

boardId_t BOARDGetId(void)
{
    socFamilyId_t socFamilyId;

    if (PLATFORMGetId() != PLATFORM_ID_EVM)
    {
        gBoardCommonObj.boardId = BOARD_UNKNOWN;
    }
    else
    {
        /* If board is to be auto-detected, the SoC specific APIs perform the
         * auto-detection and return the discovered board ID. Otherwise, they
         * return the same value used for overriding the board ID.
         */
        socFamilyId = SOCGetSocFamilyId ();
#ifdef AM335X_FAMILY_BUILD
        if (SOC_FAMILY_ID_AM335X == socFamilyId)
        {
#ifndef DDRLESS
            gBoardCommonObj.boardId = BoardGetIdAm335x();
#else
	        gBoardCommonObj.boardId = BOARD_AMIC110;
#endif
        }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
        if (SOC_FAMILY_ID_AM43XX == socFamilyId)
        {
            gBoardCommonObj.boardId = BoardGetIdAm43xx();
        }
#endif /* ifdef AM43XX_FAMILY_BUILD */
    }

    return (gBoardCommonObj.boardId);
}

const char * BOARDGetBoardName(void)
{
    const char * pBoardIdStr = NULL;
    uint32_t entryCnt;
    boardId_t boardId;

    boardId = BOARDGetId();
    if (boardId > BOARD_MAX)
    {
        boardId = BOARD_UNKNOWN;
    }

    for (entryCnt = 0U; entryCnt < BOARD_NUM_ID_STR_ENTRIES; entryCnt++)
    {
        if (gBoardIdStrTable[entryCnt].boardId == boardId)
        {
            pBoardIdStr = gBoardIdStrTable[entryCnt].pBoardIdStr;
            break;
        }
    }
    ASSERT(NULL != pBoardIdStr);

    return (pBoardIdStr);
}

uint32_t BOARDGetBaseBoardRev(void)
{
    socFamilyId_t socFamilyId;

    if (PLATFORMGetId() != PLATFORM_ID_EVM)
    {
        /*
         * Set to first permitted revision, since it is irrelevant for
         * non-EVM platforms.
         */
        gBoardCommonObj.baseBoardRev = 1U;
    }
    else
    {
        /* If board revision is to be auto-detected, the SoC specific APIs
         * perform the auto-detection and return the discovered board revision.
         * Otherwise, they return the same value used for overriding the board
         * revision.
         */
        socFamilyId = SOCGetSocFamilyId ();
#ifdef AM335X_FAMILY_BUILD
        if (SOC_FAMILY_ID_AM335X == socFamilyId)
        {
#ifndef DDRLESS
            gBoardCommonObj.baseBoardRev = BoardGetBaseBoardRevAm335x();
#else
            gBoardCommonObj.baseBoardRev = BOARD_REV_UNKNOWN;
#endif
        }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
        if (SOC_FAMILY_ID_AM43XX == socFamilyId)
        {
            gBoardCommonObj.baseBoardRev = BoardGetBaseBoardRevAm43xx();
        }
#endif /* ifdef AM43XX_FAMILY_BUILD */
    }

    return (gBoardCommonObj.baseBoardRev);
}

const char * BOARDGetBaseBoardRevName(void)
{
    const char * boardRevString = NULL;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId ();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
#ifndef DDRLESS
        boardRevString = BoardGetBaseBoardRevNameAm335x();
#else
		boardRevString = "UNKNOWN";
#endif
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        boardRevString = BoardGetBaseBoardRevNameAm43xx();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (boardRevString);
}

uint32_t BOARDGetDcRev(void)
{
    socFamilyId_t socFamilyId;

    /* If dc board revision is to be auto-detected, the SoC specific APIs
     * perform the auto-detection and return the discovered dc board revision.
     * Otherwise, they return the same value used for overriding the dc board
     * revision.
     */
    socFamilyId = SOCGetSocFamilyId ();
#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        gBoardCommonObj.dcBoardRev = BoardGetDcRevAm335x();
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        gBoardCommonObj.dcBoardRev = BoardGetDcRevAm43xx();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (gBoardCommonObj.dcBoardRev);
}

const char *BOARDGetDcRevName(void)
{
    const char * boardDcRevString = NULL;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId ();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
#ifndef DDRLESS
        boardDcRevString = BoardGetDcRevNameAm335x();
#else
		boardDcRevString = "UNKNOWN";
#endif
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        boardDcRevString = BoardGetDcRevNameAm43xx();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (boardDcRevString);
}

const boardI2cData_t * BOARDGetI2cData(void)
{
    const boardI2cData_t * i2cData = NULL;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId ();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        i2cData = BoardGetI2cDataAm335x();
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        i2cData = BoardGetI2cDataAm43xx();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (i2cData);
}

const boardData_t * BOARDGetData(void)
{
    const boardData_t * pBoardData = NULL;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId ();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        pBoardData = BoardGetDataAm335x();
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        pBoardData = BoardGetDataAm43xx();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (pBoardData);
}

uint32_t BOARDIsDevicePresent(uint32_t devId)
{
    uint32_t found = FALSE;
    uint32_t devCnt; 
    uint32_t dCardCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;
#ifndef DDRLESS
    dCards_t *pDCards;    
    uint8_t *pIsDCardPresent = NULL;
#endif
    
    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);
 
    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if (pDevData->devId == devId)
        {
            /* Found at least one instance of the specified device. */
            found = TRUE;
            break;
        }
    }
#ifndef DDRLESS
    /* Check the device on connected daughter cards if not found on board*/
    if(FALSE == found)
    {
        pDCards = pBoardData->pDCards;
        if(NULL != pDCards)
        {
            pIsDCardPresent = pDCards->pIsDCardPresent;
            ASSERT(pIsDCardPresent != NULL);
 
            for (dCardCnt = 0U; dCardCnt < pDCards->numDCards; dCardCnt++)
            {
                if(TRUE == pIsDCardPresent[dCardCnt])
                {
                    found = DCARDIsDevPresent(dCardCnt, devId);
                    if(TRUE == found)
                    {
                        break;
                    }
                }
            }
        }    
    }
#endif
    return (found);
}

uint32_t BOARDGetNumDevices(uint32_t devId)
{
    uint32_t numDevFound = 0U;
    uint32_t devCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if (pDevData->devId == devId)
        {
            numDevFound++;
        }
    }

    return (numDevFound);
}

chipdbModuleID_t BOARDGetDeviceCtrlModId(uint32_t devId, uint32_t devInstNum)
{
    chipdbModuleID_t ctrlModId = CHIPDB_MOD_ID_INVALID;
    uint32_t devCnt;
    uint32_t dCardCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;
#ifndef DDRLESS
    dCards_t * pDCards;
    uint8_t *pIsDCardPresent = NULL;
#endif
    
    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            ctrlModId = pDevData->ctrlModId;
            break;
        }
    }
	
#ifndef DDRLESS
    /* check on the connected daughter cards if not found on the board */
    if (CHIPDB_MOD_ID_INVALID == ctrlModId)
    {
        pDCards = pBoardData->pDCards;
        if(NULL != pDCards)
        {
            pIsDCardPresent = pDCards->pIsDCardPresent;
            ASSERT(NULL != pIsDCardPresent);
        
            for (dCardCnt = 0U; dCardCnt < pDCards->numDCards; dCardCnt++)
            {
                if(TRUE == pIsDCardPresent[dCardCnt] && 
                   DCARDIsDevPresent(dCardCnt, devId))
                {
                    ctrlModId = DCARDGetDeviceCtrlModId(dCardCnt, devId, devInstNum);
                    break;
                }
            }
        }
    }
#endif
    if (CHIPDB_MOD_ID_INVALID == ctrlModId)
    {
        CONSOLEUtilsPrintf("Invalid device ID!!\n");
    }

    return (ctrlModId);
}

uint32_t BOARDGetDeviceCtrlModInstNum(uint32_t devId, uint32_t devInstNum)
{
    uint32_t ctrlModInstNum = INVALID_INST_NUM;
    uint32_t devCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            ctrlModInstNum = pDevData->ctrlModInstNum;
            break;
        }
    }

    if (INVALID_INST_NUM == ctrlModInstNum)
    {
        CONSOLEUtilsPrintf("Invalid device ID!!\n");
    }

    return (ctrlModInstNum);
}

uint32_t BOARDGetDeviceCtrlInfo(uint32_t devId, uint32_t devInstNum)
{
    uint32_t ctrlInfo = INVALID_INFO;
    uint32_t devCnt;
    const boardData_t *pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            ctrlInfo = pDevData->ctrlInfo;
            break;
        }
    }

    return (ctrlInfo);
}

chipdbModuleID_t BOARDGetDeviceDataModId(uint32_t devId, uint32_t devInstNum)
{
    chipdbModuleID_t dataModId = CHIPDB_MOD_ID_INVALID;
    uint32_t devCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            dataModId = pDevData->dataModId;
            break;
        }
    }

    return (dataModId);
}

uint32_t BOARDGetDeviceDataModInstNum(uint32_t devId, uint32_t devInstNum)
{
    uint32_t dataModInstNum = INVALID_INST_NUM;
    uint32_t devCnt;
    const boardData_t * pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            dataModInstNum = pDevData->dataModInstNum;
            break;
        }
    }

    return (dataModInstNum);
}

int32_t BOARDPowerOnDevice(uint32_t devId,
                           uint32_t devInstNum,
                           uint32_t powerOn)
{
    int32_t  status = E_FAIL;
    uint32_t devCnt;
    const boardData_t *pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum) &&
            (pDevData->pFnPowerOnDev != NULL))
        {
            status = pDevData->pFnPowerOnDev(devId, devInstNum, powerOn);
            if (S_PASS != status)
            {
                CONSOLEUtilsPrintf("Device power-on failed on Board!!\n");
            }
            break;
        }
    }

    if(S_PASS != status)
    {
        status = BoardPowerOnDCardDevice(devId,
                                         devInstNum, 
                                         powerOn);
        if (S_PASS != status)
        {
                CONSOLEUtilsPrintf("Device power-on failed on Daughter card!!\n");
        }
    }
    
    return (status);
}

int32_t BOARDSelectDevice(uint32_t devId, uint32_t devInstNum)
{
    int32_t  status = S_PASS;
    uint32_t devCnt;
    const boardData_t *pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum) &&
            (pDevData->pFnSelectDev != NULL))
        {
            status = pDevData->pFnSelectDev(devId, devInstNum);
            if (S_PASS != status)
            {
                CONSOLEUtilsPrintf("Device select failed!!\n");
            }
            break;
        }
    }

    return (status);
}

int32_t BOARDResetDevice(uint32_t devId, uint32_t devInstNum)
{
    int32_t  status = S_PASS;
    uint32_t devCnt;
    const boardData_t *pBoardData;
    const boardDeviceData_t * pDevData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    for (devCnt = 0U; devCnt < pBoardData->numDev; devCnt++)
    {
        ASSERT(pBoardData->pDevData != NULL);
        pDevData = &pBoardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum) &&
            (pDevData->pFnResetDev != NULL))
        {
            status = pDevData->pFnResetDev(devId, devInstNum);
            if (S_PASS != status)
            {
                CONSOLEUtilsPrintf("Device reset failed!!\n");
            }
            break;
        }
    }

    return (status);
}

void BOARDPrintInfo(void)
{
    CONSOLEUtilsPrintf(
              " Board Detected        : [%s]\r\n", BOARDGetBoardName());
    CONSOLEUtilsPrintf(
              " Base Board Revision   : [%s]\r\n",
              BOARDGetBaseBoardRevName());
    CONSOLEUtilsPrintf(
              " Daughter Card Revision: [%s]\r\n", BOARDGetDcRevName());
}

dCards_t * BOARDGetDCardsData(void)
{
    const boardData_t * pBoardData  = NULL;
    dCards_t    * pDCardsData = NULL;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId ();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        pBoardData = BoardGetDataAm335x();
        pDCardsData   = pBoardData->pDCards;
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        pBoardData = BoardGetDataAm43xx();
        pDCardsData   = pBoardData->pDCards;
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return (pDCardsData);
}

uint32_t BOARDIsDCardPresent(uint32_t dCardId)
{
    uint32_t found = FALSE;
    dCards_t    * pDCards;  
    
    pDCards = BOARDGetDCardsData();
    
    if((NULL != pDCards) && (TRUE == pDCards->pIsDCardPresent[dCardId]))
    {
        found = TRUE;
    }
    return (found);
}
int32_t BOARDGetLcdDevData(uint32_t lcdDevId, 
                           lcdDeviceBoardData_t *pLcdDeviceBoardData)
{
    int32_t  status = E_FAIL;
    const boardData_t *pBoardData;

    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);
    
    if(NULL != pBoardData->pFnBoardLcdDevData)
    {
        pBoardData->pFnBoardLcdDevData(lcdDevId, pLcdDeviceBoardData);
        status = S_PASS;
    }
    else
    {
         status = E_FAIL;
    }
    
    return status;
}
/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static uint32_t BoardPowerOnDCardDevice(uint32_t devId,
                                 uint32_t devInstNum, 
                                 uint32_t powerOn)
{
    int32_t  status = E_FAIL;
    dCardId_t dCardId;
    dCards_t    * pDCards; 
    
    dCardId = DCARDGetDevDCardId(devId);
    pDCards = BOARDGetDCardsData();
    ASSERT(NULL != pDCards);
    
    if(NULL != pDCards->pFnBoardPowerOnDCardDev)
    {
        status = pDCards->pFnBoardPowerOnDCardDev(dCardId, devId, devInstNum, powerOn);
    }
    
    return (status);
}
