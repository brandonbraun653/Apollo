/**
 * \file   dcard.c
 *
 * \brief  This file contains the implementation of the APIs that abstract the
 *         daughter card-specific details for StarterWare.
 *
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
#include "dcard_am335x.h"
#endif /* ifdef AM335X_FAMILY_BUILD */

#ifdef AM43XX_FAMILY_BUILD
#include "board_am43xx.h"
#include "dcard_am43xx.h"
#endif /* ifdef AM43XX_FAMILY_BUILD */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function returns the daughter card data based on the daughter 
 *         card ID. 
 * \param  dCardId  Daughter card ID. 
 *  
 * \retval pointer to the daughter card data
 */
const dCardData_t *DCardGetData(uint32_t dCardId);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void DCARDInit()
{
    socFamilyId_t socFamilyId = SOCGetSocFamilyId();

#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        DCardAm335xInit();
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        DCardAm43xxInit();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

}

const dCardData_t ** DCARDGetDCardList()
{
    const dCardData_t **pDCardList;
    socFamilyId_t socFamilyId = SOCGetSocFamilyId();
    
#ifdef AM335X_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM335X == socFamilyId)
    {
        pDCardList = DCardAm335xGetDCardList();
    }
#endif /* ifdef AM335X_FAMILY_BUILD */
#ifdef AM43XX_FAMILY_BUILD
    if (SOC_FAMILY_ID_AM43XX == socFamilyId)
    {
        pDCardList = DCardAm43xxGetDCardList();
    }
#endif /* ifdef AM43XX_FAMILY_BUILD */

    return pDCardList;
}

uint32_t DCARDIsDevPresent(uint32_t dCardId, uint32_t devId)
{
    uint32_t found = FALSE;
    uint32_t devCnt;
    const dCardData_t * pDCardData;
    const boardDeviceData_t * pDevData;

    pDCardData = DCARDGetData(dCardId);
    
    if(NULL != pDCardData)
    {    
        for (devCnt = 0U; devCnt < pDCardData->numDev; devCnt++)
        {
            pDevData = &pDCardData->pDevData[devCnt];
            if (pDevData->devId == devId)
            {
                /* Found at least one instance of the specified device. */
                found = TRUE;
                break;
            }
        }
    }

    return (found);
}

uint32_t DCARDGetDevDCardId(uint32_t devId)
{
    dCardId_t dCardId;
    dCards_t *pDCards;
    uint8_t dCardCnt;
    
    pDCards = BOARDGetDCardsData();
   
    if(NULL != pDCards)
    {
        for (dCardCnt = 0U ; (dCardCnt < pDCards->numDCards) ; dCardCnt++)
        {   
            if(TRUE == DCARDIsDevPresent(dCardCnt, devId))
            {
                dCardId = dCardCnt;
                break;
            }
        }
    }
    
    return (dCardId);
}

chipdbModuleID_t DCARDGetDeviceCtrlModId(uint32_t dCardId, 
                                         uint32_t devId, 
                                         uint32_t devInstNum)
{
    chipdbModuleID_t ctrlModId = CHIPDB_MOD_ID_INVALID;
    uint32_t devCnt;
    const dCardData_t * pDCardData;
    const boardDeviceData_t * pDevData;
    
    pDCardData = DCARDGetData(dCardId);
    ASSERT(NULL != pDCardData);
    
    for (devCnt = 0U; devCnt < pDCardData->numDev; devCnt++)
    {
        ASSERT(pDCardData->pDevData != NULL);
        pDevData = &pDCardData->pDevData[devCnt];
        if ((pDevData->devId == devId) &&
            (pDevData->devInstNum == devInstNum))
        {
            ctrlModId = pDevData->ctrlModId;
            break;
        }
    }
    
    if (CHIPDB_MOD_ID_INVALID == ctrlModId)
    {
        CONSOLEUtilsPrintf("Invalid device ID!!\n");
    }

    return (ctrlModId);
}            
uint8_t * DCARDGetRevStr(uint32_t dCardId)
{
    const dCardData_t *pDCardData = NULL;
    uint8_t * revStr = NULL;
    
    pDCardData = DCARDGetData(dCardId);
    ASSERT(pDCardData != NULL);
    
    revStr = pDCardData->eepromData.pVersion;
    ASSERT(revStr != NULL);
    
    return (revStr);
}
const dCardData_t *DCARDGetData(uint32_t dCardId)
{
    const dCardData_t **pDCardList = NULL;
    const dCardData_t *pDCardData = NULL;
    
    pDCardList = DCARDGetDCardList();
    ASSERT(NULL != pDCardList);
    
    if((dCardId > DCARD_UNKNOWN) && (dCardId < (DCARD_MAX + 1U)))
    {
        pDCardData = pDCardList[dCardId];
    }
    return (pDCardData);
}

const char ** DCARDGetRevTable(uint32_t dCardId)
{
    const dCardData_t *pDCardData = NULL;
    
    pDCardData = DCARDGetData(dCardId);
    ASSERT(pDCardData != NULL);
    
    return pDCardData->pRevStringTable;
}
/* -------------------------------------------------------------------------- */
/*                          Internal Function Definitions                     */
/* -------------------------------------------------------------------------- */
