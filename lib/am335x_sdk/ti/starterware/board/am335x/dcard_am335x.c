
/**
 * \file   dcards_am335x.c
 *
 * \brief  This file contains AM335X based daughter card detection and 
 *         initialization. It holds AM335X based daughter card objects
 *
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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
#include "error.h"
#include "i2c_utils.h"
#include "stdlib.h"
#include "string.h"
#include "board_am335x.h"
#include "dcard_am335x.h"
#include "am335x_lcd4_dcard.h"
#include "console_utils.h"
#include "debug.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Time out value for I2C operations set to 1000 ms. */
#define DCARD_AM335X_I2C_TIMEOUT_VAL            (1000U)

/** \brief Invalid I2C slave address */
#define DCARD_AM335X_I2C_SLAVE_ADDR_INVALID     (0xFFU)

/** \brief Number of EEPROM parameters */
#define DCARD_AM335X_EEPROM_PARAMS              (4U)

/** \brief EEPROM offset index */  
#define DCARD_AM335X_EEPROM_PARAM_OFFSET        (0U)

/** \brief EEPROM size index */
#define DCARD_AM335X_EEPROM_PARAM_SIZE          (1U)

/** \brief EEPROM header index */
#define DCARD_AM335X_EEPROM_HEADER_INDEX        (0U)

/** \brief EEPROM board name index */
#define DCARD_AM335X_EEPROM_BOARD_NAME_INDEX    (1U)

/** \brief EEPROM version index */
#define DCARD_AM335X_EEPROM_VERSION_INDEX       (2U)

/** \brief EEPROM serial number index */
#define DCARD_AM335X_EEPROM_SERIAL_NUMBER_INDEX (3U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function prints the EEPROM data.
 *
 * \param  pDCardParams    Pointer to daughter card object   
 */
static void DCardAm335xPrintEepromData(const dCardData_t * pDCardParams);

/**
 * \brief  This function returns the valid I2C slave address of all the 
 *         possible addresses. Valid address is an address that depends 
 *         on the current switch positions provided on the daughter card.
 *
 * \param  pDCardParams      Pointer to daughter card object   
 * \param  i2cInstNum       I2C instance number
 * \param  i2cUtilsParams   I2C utils parameter
 *
 * \retval valid i2c slave address.
 */
static uint8_t DCardAm335xGetI2cSlaveAddr(const dCardData_t * pDCardParams, 
                                   uint32_t i2cInstNum, 
                                   i2cUtilsInitParams_t * i2cUtilsParams);

/**
 * \brief  This function links the corresponding board specific daughter card 
 *         pointer to the detected daughter card object. It also updates the 
 *         array that holds the information of currently connected daughter 
 *         cards and marks the fields as connected.
 *
 * \param  pDCardParams    Pointer to daughter card object
 * \param  dCardId         Detected daughter card ID.
 * \param  pDCardData      Pointer to Detected daughter object. 
 */                                   
static void DCardAm335xLinkDCard(const boardData_t *pBoardData, 
                          uint32_t dCardId, 
                          const dCardData_t *pDCardData);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Contains pointers to the daughter card data . */
static const dCardData_t *gpDCardAm335xData [DCARD_MAX + 1U]= {
    NULL, /* DCARD_UNKNOWN */
#ifndef DDRLESS
    &gDCardAm335xLCD4Data /* DCARD_LCD4 */
#endif
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void DCardAm335xInit(void)
{
    int32_t  status = S_PASS;
    boardId_t boardId;
    const boardData_t *pBoardData;
    const dCardData_t *pDCardParams;
    boardI2cInstData_t * pI2cInstData;
    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;
    i2cUtilsTxRxParams_t i2cRxParams;
    uint32_t i2cInstNum;
    uint8_t dCardCnt;
    uint8_t eepromParamsCnt;
    uint8_t i2cSlaveAddr;
    uint8_t i2cParamOffset;
    
    /* Get the board Data */
    pBoardData = BOARDGetData();
    ASSERT(NULL != pBoardData);

    boardId = BOARDGetId();
    
    CONSOLEUtilsPrintf("\nAM335X DAUGHTER CARDS INIT: Checking connectivity\n");

#ifndef DDRLESS
    /*Iterate through all Daughter cards of Am335x and check for presence*/
    for (dCardCnt = 0U ; (dCardCnt < DCARD_MAX + 1) ; dCardCnt++)
    {
        
        pDCardParams = gpDCardAm335xData[dCardCnt];
        if(pDCardParams == NULL)
        {
            continue;
        }
        
        /* Get I2C data for probing the daughter card */
        pI2cInstData = &(pDCardParams->pI2cInstData[boardId]);
        i2cInstNum = pI2cInstData->instNum;
        i2cUtilsParams.busSpeed = pI2cInstData->busClkKHz;
                
        /* Find the valid i2c address */
        i2cSlaveAddr = DCardAm335xGetI2cSlaveAddr(pDCardParams, i2cInstNum, &i2cUtilsParams);
                
        if(DCARD_AM335X_I2C_SLAVE_ADDR_INVALID == i2cSlaveAddr)
        {
            CONSOLEUtilsPrintf("\nNOT CONNECTED        :    %s\n", pDCardParams->pDCardName);
            continue;
        }
        else
        {
            CONSOLEUtilsPrintf("\nCONNECTED    : %s\n", pDCardParams->pDCardName);
            DCardAm335xLinkDCard(pBoardData, pDCardParams->dCardId, pDCardParams);
        }
                
        status = I2CUtilsInit(i2cInstNum, &i2cUtilsParams);
        if(E_FAIL == status)
        {
            break;
        }
        
        i2cRxParams.slaveAddr = i2cSlaveAddr;
        
        /* Read the EEPROM parameters */       
        for (eepromParamsCnt = 0U ; 
             eepromParamsCnt < DCARD_AM335X_EEPROM_PARAMS; 
             eepromParamsCnt++)
        {
            i2cParamOffset = pDCardParams->eepromDataFormat[eepromParamsCnt]
                            [DCARD_AM335X_EEPROM_PARAM_OFFSET];
            i2cRxParams.pOffset = (uint8_t *)(pDCardParams->
                                    pFnDCardGetEepromOffset(i2cParamOffset));
            i2cRxParams.offsetSize = pDCardParams->pFnDCardGetEepromOffsetSize();
            i2cRxParams.bufLen = pDCardParams->eepromDataFormat
                                              [eepromParamsCnt]
                                              [DCARD_AM335X_EEPROM_PARAM_SIZE];
            i2cRxParams.pBuffer = (uint8_t *)
                                  (*(&(pDCardParams->eepromData.pHeader) + 
                                       eepromParamsCnt));
            status = I2CUtilsRead(i2cInstNum,
                                &i2cRxParams,
                                DCARD_AM335X_I2C_TIMEOUT_VAL);
            if (E_FAIL == status)
            {
                break; 
            }
        }
        
        /* Print the EEPROM parameters of a daughter card if required*/
        
        
        DCardAm335xPrintEepromData(pDCardParams);
         
    }
#endif
}

const dCardData_t **DCardAm335xGetDCardList(void)
{
    return gpDCardAm335xData;
}

/* ========================================================================== */
/*                       Internal Function Definitions                        */
/* ========================================================================== */
static void DCardAm335xPrintEepromData(const dCardData_t * pDCardParams)
{
    CONSOLEUtilsPrintf("HEADER           :    0x%x 0x%x 0x%x 0x%x\n", 
                        pDCardParams->eepromData.pHeader[0],
                        pDCardParams->eepromData.pHeader[1],
                        pDCardParams->eepromData.pHeader[2],
                        pDCardParams->eepromData.pHeader[3]);

    pDCardParams->eepromData.pBoardName
        [pDCardParams->eepromDataFormat[DCARD_AM335X_EEPROM_BOARD_NAME_INDEX]
                                      [DCARD_AM335X_EEPROM_PARAM_SIZE]] = '\0';
    CONSOLEUtilsPrintf("DCARD NAME       :    %s\n", 
                        pDCardParams->eepromData.pBoardName);
                
    pDCardParams->eepromData.pVersion
        [pDCardParams->eepromDataFormat[DCARD_AM335X_EEPROM_VERSION_INDEX]
                                      [DCARD_AM335X_EEPROM_PARAM_SIZE]] = '\0';
    CONSOLEUtilsPrintf("VERSION          :    %s\n",
                        pDCardParams->eepromData.pVersion);
                
    pDCardParams->eepromData.pSerialNumber
        [pDCardParams->eepromDataFormat[DCARD_AM335X_EEPROM_SERIAL_NUMBER_INDEX]
                                      [DCARD_AM335X_EEPROM_PARAM_SIZE]] = '\0';
    CONSOLEUtilsPrintf("SERIAL NUMBER    :    %s\n", 
                        pDCardParams->eepromData.pSerialNumber);            
}

static uint8_t DCardAm335xGetI2cSlaveAddr(const dCardData_t * pDCardParams, 
                                   uint32_t i2cInstNum, 
                                   i2cUtilsInitParams_t * i2cUtilsParams)
{
    i2cUtilsTxRxParams_t i2cRxParams;
    int32_t status = E_FAIL;
    uint8_t addrCnt;
    uint8_t i2cFoundAddr; 
    uint8_t i2cParamOffset;
                
    for (addrCnt = 0U ; (addrCnt < pDCardParams->numI2cSlaveAddr) ; addrCnt++)
    {
        status = I2CUtilsInit(i2cInstNum, i2cUtilsParams);
        if(E_FAIL == status)
        {
            break;
        }
        i2cRxParams.slaveAddr = pDCardParams->pI2cSlaveAddrRange[addrCnt];
        i2cParamOffset = pDCardParams->eepromDataFormat
                            [DCARD_AM335X_EEPROM_BOARD_NAME_INDEX]
                            [DCARD_AM335X_EEPROM_PARAM_OFFSET];
        i2cRxParams.pOffset = (uint8_t *)(pDCardParams->
                                pFnDCardGetEepromOffset(i2cParamOffset));
        i2cRxParams.offsetSize = pDCardParams->pFnDCardGetEepromOffsetSize();
        i2cRxParams.bufLen = pDCardParams->eepromDataFormat
                                [DCARD_AM335X_EEPROM_BOARD_NAME_INDEX]
                                [DCARD_AM335X_EEPROM_PARAM_SIZE];
        i2cRxParams.pBuffer = (uint8_t *)(pDCardParams->eepromData.pBoardName);
        status = I2CUtilsRead(i2cInstNum,
                              &i2cRxParams,
                              DCARD_AM335X_I2C_TIMEOUT_VAL);
     
        if (S_PASS == status)
        {
            pDCardParams->eepromData.pBoardName
            [pDCardParams->eepromDataFormat[DCARD_AM335X_EEPROM_BOARD_NAME_INDEX]
                                    [DCARD_AM335X_EEPROM_PARAM_SIZE]] = '\0';
             
            if (strncmp(pDCardParams->pDCardName,
                       (char *)pDCardParams->eepromData.pBoardName,
                        pDCardParams->eepromDataFormat[DCARD_AM335X_EEPROM_BOARD_NAME_INDEX]
                       [DCARD_AM335X_EEPROM_PARAM_SIZE]) == 0U)
            {
                i2cFoundAddr = i2cRxParams.slaveAddr;   
                break;
            }
            else
            {
                status = E_FAIL;
            }
        }       
    }    

    if (S_PASS == status)
    {
        return i2cFoundAddr;
    }
    else
    {
        return DCARD_AM335X_I2C_SLAVE_ADDR_INVALID;
    }
}

static void DCardAm335xLinkDCard(const boardData_t *pBoardData, uint32_t dCardId, const dCardData_t *pDCardData)
{
    if((dCardId > DCARD_UNKNOWN) && (dCardId < (DCARD_MAX + 1U)))
    {
        pBoardData->pDCards->pDCardList[dCardId] = pDCardData;
        pBoardData->pDCards->pIsDCardPresent[dCardId] = TRUE;    
    }
}