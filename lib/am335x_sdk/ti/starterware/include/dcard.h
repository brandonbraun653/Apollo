/**
 * \file   dcard.h
 *
 * \brief  This file provides structures required by daughter cards.
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

#ifndef DCARD_
#define DCARD_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "chipdb.h"
#include "pinmux.h"
#include "board.h"
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define DCARD_IS_PRESENT            (1U)
#define DCARD_IS_NOT_PRESENT        (0U)
#define DCARDS_COMPATIBLE           (1U)
#define DCARDS_INCOMPATIBLE         (0U)


/**
 *  \brief Forward declaration of boardI2cInstData_t type
 */
typedef struct boardI2cInstData boardI2cInstData_t;

/**
 *  \brief Forward declaration of boardData_t type
 */
typedef struct boardData boardData_t;

/**
 *  \brief Forward declaration of dCards_t type
 */
typedef struct dCards dCards_t;

/**
 *  \brief Function pointer typedef for board initialization
 */
typedef int32_t (*DCARDInitFxn)(boardData_t * pBoardData);


/**
 *  \brief Function pointer typedef for powering on daughter card device
 *         depending on the board.
 */
typedef uint32_t (*DCARDBoardPowerOnDCardDevFxn)(uint32_t dCardId, 
                                                 uint32_t devId,
                                                 uint32_t devInstNum,
                                                 uint32_t powerOn);

/**
 *  \brief Function pointer is provided to do any board specific daughter 
           card initialization in board files.
 */
typedef int32_t (*DCARDBoardDCardConfig)(uint32_t dCardId);

/**
 *  \brief Function pointer typedef to get eeprom offset array based on the 
 *         offset address passed.
 */
typedef uint8_t *(*DCARDgetEepromOffsetFxn)(uint32_t offset);

/**
 *  \brief Function pointer typedef to get eeprom offset address size.
 */
typedef uint8_t (*DCARDgetEepromOffsetSizeFxn)(void);

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Daughter card ID, unique for each daughter card.
 *         ID will be used to iterate through all daughter cards for the given
 *         board. Based on the Daughter card ID, daughter card APIs will provide
 *         a required daughter card data. 
 */
typedef enum dCardId
{
    DCARD_MIN,
    /**< Should be the first value of this enumeration. */
    DCARD_UNKNOWN = DCARD_MIN,
    /**< Unknown board. */
    DCARD_LCD4 = 0x1U,
    /**< LCD4 Daughter  card */
    DCARD_MAX = DCARD_LCD4
    /**< Max board ID. */
} dCardId_t;

/**
 *  \brief Forward declaration of boardDeviceData_t and boardI2cData_t type defined in board.h 
 */
typedef struct boardDeviceData boardDeviceData_t;
typedef struct boardI2cData boardI2cData_t; 

/**
 *  \brief Generic structure to hold daughter card EEPROM data.
 */
typedef struct dCardDataEeprom
{
    uint8_t *pHeader;
    /**< pointer to dCard EEPROM header. */
    uint8_t *pBoardName;
    /**< pointer to dCard name. */
    uint8_t *pVersion;
    /**< pointer to dCard version. */
    uint8_t *pSerialNumber;
    /**< pointer to Serial number information. */
} dCardDataEeprom_t;

/**
 *  \brief Daughter card data.
 */
typedef struct dCardData
{
    uint32_t                        dCardId;
    /**< holds daughter card ID. */
    const char                    * pDCardName;
    /**< String containing the daughter card name. */
    uint32_t                        numDev;
    /**< Number of devices connected to the board. */
    const boardDeviceData_t       * pDevData;
    /**< Pointer to #numDev number of device data. */
    dCardDataEeprom_t               eepromData;
    /**< holds the eeprom data of the daughter card */
    uint32_t                     (* eepromDataFormat)[2U];  
    /**< holds the offset and length for each field in eeprom data */
    boardI2cInstData_t             * pI2cInstData;
    /**< I2c data for the daughter card */
    uint32_t                        numI2cSlaveAddr;
    /**< number of possible I2C slave addresses for this daughter card */
    uint32_t                      * pI2cSlaveAddrRange;
    /**< pointer to the array holding the possible addresses */
    uint32_t                        numRevStrings;
    /**< Number of board revision string names. */
    const char                   ** pRevStringTable;
    /**< Pointer to board revision string names table. */
    DCARDgetEepromOffsetFxn         pFnDCardGetEepromOffset;
    /**< Pointer to function to get eeprom offset array based on the offset
    address passed. */
    DCARDgetEepromOffsetSizeFxn     pFnDCardGetEepromOffsetSize;
    /**< Pointer to function to get eeprom offset array size. */
    DCARDInitFxn                    pFnDCardInit;
    /**< Pointer to optional board initialization function. */
} dCardData_t;

/**
 *  \brief Board specific daughter cards data.
 */
typedef struct dCards
{
    uint32_t                           numDCards;
    /**< Number of daughter cards for the board. */
    const dCardData_t               ** pDCardList;
    /**< Pointer to all daughter cards for the board. */
    const uint8_t                   (* pIsCompatible)[DCARD_MAX + 1]
                                                     [DCARD_MAX + 1];
    /**< compatibility matrix over all daughter cards for the board. */
    uint8_t                          * pIsDCardPresent;
    /**< Pointer to an array to hold the information of currently 
         present daughter cards. */
    DCARDBoardPowerOnDCardDevFxn       pFnBoardPowerOnDCardDev;
    /**< Pointer to a function to querry currently connected daughter careds. */
    DCARDBoardDCardConfig              pFnBoardDCardConfig;
    /**< Pointer to a function to connect the present daughter cards. */
}dCards_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  This function initializes daughter cards for the board.
 */
void DCARDInit(void);

/**
 *  \brief  This function returns the list of daughter cards.
 *
 *  \retval List of daughter cards
 */
const dCardData_t ** DCARDGetDCardList();

/**
 *  \brief  This function checks if the device present on daughter card.
 *
 *  \param  dCardId    Daughter card ID
 *  \param  devId      Device ID
 *
 *  \retval TRUE       If present
 *  \retval FALSE      If not present
 */
 
uint32_t DCARDIsDevPresent(uint32_t dCardId, uint32_t devId);

/**
 *  \brief  This function returns the daughter card ID based on Device ID.
 *
 *  \param  devId      Device ID
 *
 *  \retval daughter cardID
 */
uint32_t DCARDGetDevDCardId(uint32_t devId);

/**
 *  \brief  Returns the ID of the SoC module to which the device is connected
 *          for controlling it. 
 *
 *  \param  dCardId      Daughter card ID
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval SoC_Ctrl_Mod_ID        If found, returns the SoC module ID which is
 *                                 used for controlling this device.
 *  \retval CHIPDB_MOD_ID_INVALID  If device is not found, returns invalid
 *                                 module ID.
 */
chipdbModuleID_t DCARDGetDeviceCtrlModId(uint32_t dCardId, 
                                         uint32_t devId, 
                                         uint32_t devInstNum);

/**
 *  \brief  This function returns the daughter card revision string.
 *
 *  \param  dCardId    Daughter card ID
 *
 *  \retval revision string
 */                                      
uint8_t * DCARDGetRevStr(uint32_t dCardId);                                         

/**
 *  \brief  This function returns the daughter card data.
 *
 *  \param  dCardId    Daughter card ID
 *
 *  \retval daughter card data
 */
const dCardData_t *DCARDGetData(uint32_t dCardId);

/**
 *  \brief  This function returns the daughter card revision string table.
 *
 *  \param  dCardId    Daughter card ID
 *
 *  \retval daughter card revision string table
 */           
const char ** DCARDGetRevTable(uint32_t dCardId);      
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif  /* #ifndef DCARD_ */
