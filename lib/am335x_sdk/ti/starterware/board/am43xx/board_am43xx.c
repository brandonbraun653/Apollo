/**
 * \file   board_am43xx.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM43xx based boards.
 *
 * \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
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
#include "stdlib.h"
#include "string.h"
#include "error.h"
#include "debug.h"
#include "board.h"
#include "platform.h"
#include "device.h"
#include "chipdb.h"
#include "board_priv.h"
#include "console_utils.h"
#include "i2c_utils.h"
#include "board_am43xx.h"
#include "am43xx_gpevm.h"
#include "am43xx_evmsk.h"
#include "am43xx_idkevm.h"
#include "am43xx_eposevm.h"
#include "am43xx_custom.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Size of EEPROM header in bytes on AM43xx. */
#define BOARD_EEPROM_HEADER_SIZE        (4U)
/** \brief Size of EEPROM data for board name in bytes on AM43xx. */
#define BOARD_EEPROM_BOARD_NAME_SIZE    (8U)
/** \brief Size of EEPROM data for version in bytes on AM43xx. */
#define BOARD_EEPROM_VERSION_SIZE       (5U)
/** \brief Size of EEPROM data for serial number in bytes on AM43xx. */
#define BOARD_EEPROM_SERIAL_NUMBER_SIZE (12U)

/** \brief EEPROM offset containing the board information. */
#define BOARD_DATA_EEPROM_OFFSET        (0x00)

/**
 * \brief Size to compare for board version for AM43xx. This is to ensure that,
 * for example, 1.1X matches correctly when X may be any value.
 */
#define BOARD_AM43XX_VERSION_CMP_SIZE   (0x3U) /* String compare size */

/** \brief Timeout value for I2C operations set to 1000 ms. */
#define BOARD_I2C_TIMEOUT_VAL           (1000U)


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/** \brief Board EEPROM data structure. */
typedef struct boardDataEeprom
{
    uint8_t header[BOARD_EEPROM_HEADER_SIZE];
    /**< EEPROM header. */
    uint8_t boardName[BOARD_EEPROM_BOARD_NAME_SIZE];
    /**< Board name. */
    uint8_t version[BOARD_EEPROM_VERSION_SIZE];
    /**< Board version. Includes board ID information. */
    uint8_t serialNumber[BOARD_EEPROM_SERIAL_NUMBER_SIZE];
    /**< Serial number information. */
} boardDataEeprom_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief I2C instances data for AM43xx */
static boardI2cInstData_t gBoardAm43xxI2cInstData[] =
{
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        0U,                                 /* instNum */
        0x0U,                               /* baseAddr */
        0U,                                 /* intNum */
        100U                                /* busClkKHz */
    },
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        1U,                                 /* instNum */
        0x0U,                               /* baseAddr */
        0U,                                 /* intNum */
        100U                                /* busClkKHz */
    }
};

/** \brief I2C data for AM43xx */
static boardI2cData_t gBoardAm43xxI2cData =
{
    (sizeof (gBoardAm43xxI2cInstData) / sizeof (boardI2cInstData_t)),
    /* numInst */
    gBoardAm43xxI2cInstData,
    /* pInstData */
    0U,
    /* probeInstNum */
};

/** \brief Board module object. */
static boardCommonObj_t gBoardAm43xxObj =
{
    BOARD_UNKNOWN,     /* boardId */
    BOARD_REV_UNKNOWN, /* baseBoardRev */
    BOARD_REV_UNKNOWN  /* dcBoardRev */
};

/** \brief EEPROM data for AM43xx. */
static boardDataEeprom_t gBoardDataEeprom;

/**
 * \brief   Pointer to EEPROM data for AM43xx. Indicates if EEPROM data has
 *          already been read.
 */
static boardDataEeprom_t * gpBoardDataEeprom = NULL;

/* TBD: Kept as global for now to workaround bug in i2cUtils. */
static uint8_t gEepromOffset[2U] = {
    ((BOARD_DATA_EEPROM_OFFSET >> sizeof (uint8_t)) & 0xFF),
    (BOARD_DATA_EEPROM_OFFSET & 0xFF)
};

/** \brief Contains pointers to the board data for the different boards. */
static const boardData_t *gpBoardAm43xxData [BOARD_MAX + 1U]= {
    NULL, /* BOARD_UNKNOWN */
    &gBoardAm43xxGpevmData, /* BOARD_GPEVM */
    &gBoardAm43xxEvmskData, /* BOARD_EVMSK */
    NULL, /* BOARD_BEAGLEBONE */
    &gBoardAm43xxIdkevmData, /* BOARD_IDKEVM */
    &gBoardAm43xxEposevmData, /* BOARD_EPOSEVM */
    &gBoardAm43xxCustomData, /* BOARD_CUSTOM */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BoardAm43xxInit(const boardInitParams_t *pInitPrms)
{
    uint8_t i;

    for (i = 0 ; i < gBoardAm43xxI2cData.numInst ; i++)
    {
        gBoardAm43xxI2cData.pInstData[i].baseAddr = CHIPDBBaseAddress(
            CHIPDB_MOD_ID_I2C,
            gBoardAm43xxI2cData.pInstData[i].instNum);

        /* TBD: Comment interrupt number for now till implemented */
        /*
        gBoardAm43xxI2cData.pInstData[i].baseAddr = ChipDBInterruptNum(
            CHIPDB_MOD_ID_I2C,
            gBoardAm43xxI2cData.pInstData[i].instNum,
            intSigType);
        */
    }

    /* Setup the board information. */
    gBoardAm43xxObj.boardId      = pInitPrms->boardId;
    gBoardAm43xxObj.baseBoardRev = pInitPrms->baseBoardRev;
    gBoardAm43xxObj.dcBoardRev   = pInitPrms->dcBoardRev;

    /* Do any initialization/configuration required for AM43XX boards. */

    return (S_PASS);
}

boardId_t BoardGetIdAm43xx(void)
{
    int32_t status = S_PASS;
    boardId_t boardId = BOARD_UNKNOWN;
    const boardI2cData_t * pI2cData;
    boardI2cInstData_t * pInstData;
    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;
    i2cUtilsTxRxParams_t i2cRxParams;
    uint32_t i2cInstNum;

    if ((PLATFORM_ID_ZEBU == PLATFORMGetId()) ||
        (PLATFORM_ID_VIRTIO == PLATFORMGetId()))
    {
        /* Set to a default for Zebu / Virtio platforms. */
        boardId = BOARD_GPEVM;
    }
    else
    {
        /* If board ID is to be auto-detected, initialize I2C and get the board
         * ID.
         */
        if (BOARD_AUTO_DETECT == gBoardAm43xxObj.boardId)
        {
            pI2cData = BoardGetI2cDataAm43xx();
            ASSERT(NULL != pI2cData);

            /* Detect board ID */
            i2cInstNum = pI2cData->probeInstNum;
            pInstData = &(pI2cData->pInstData[i2cInstNum]);

            i2cUtilsParams.busSpeed = pInstData->busClkKHz;
            status = I2CUtilsInit(i2cInstNum, &i2cUtilsParams);
            if (S_PASS == status)
            {
                /* Read the Board data from EEPROM */
                i2cRxParams.slaveAddr = BOARD_EEPROM_I2C_ADDR_0;
                i2cRxParams.pOffset = gEepromOffset;
                i2cRxParams.offsetSize = sizeof (gEepromOffset);
                i2cRxParams.bufLen = sizeof (boardDataEeprom_t);
                i2cRxParams.pBuffer = (uint8_t *) &gBoardDataEeprom;
                status = I2CUtilsRead(i2cInstNum,
                            &i2cRxParams,
                            BOARD_I2C_TIMEOUT_VAL);
                if (S_PASS == status)
                {
                    /* Set the pointer so that next time the data can be
                     * directly read from the local variable.
                     */
                    gpBoardDataEeprom = &gBoardDataEeprom;

                    /* Check if the board is GPEVM */
                    if (strncmp(BOARD_AM43XX_GPEVM_BOARD_NAME,
                                (char *)gBoardDataEeprom.boardName,
                                BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_GPEVM;
                    }
                    /* Check if the board is EVMSK */
                    else if (strncmp(BOARD_AM43XX_EVMSK_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_EVMSK;
                    }
                    /* Check if the board is IDKEVM */
                    else if (strncmp(BOARD_AM43XX_IDKEVM_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_IDKEVM;
                    }
                    /* Check if the board is EPOSEVM */
                    else if (strncmp(BOARD_AM43XX_EPOSEVM_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_EPOSEVM;
                    }
                    /* Check if the board is AM43xHS EVM */
                    else if (strncmp(BOARD_AM43XX_HSEVM_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        /* treat HS as GP EVM since we don't handle secure 
                           related stuff in board */
                        boardId = BOARD_GPEVM;
                    }
                    else
                    {
                        /* If the board is not one of these, then the board
                         * ID is returned as BOARD_UNKNOWN.
                         */
                    }

                    if (BOARD_UNKNOWN != boardId)
                    {
                        /* Call board initialization function, if any. */
                        if (NULL != gpBoardAm43xxData[boardId]->pFnBoardInit)
                        {
                            status = gpBoardAm43xxData[boardId]->pFnBoardInit();
                        }
                    }
                }
            }
        }
        else
        {
            /* Return the already detected / overridden board ID */
            boardId = gBoardAm43xxObj.boardId;
        }
    }

    /* Set the global to the found value. */
    gBoardAm43xxObj.boardId = boardId;

    return (boardId);
}

uint32_t BoardGetBaseBoardRevAm43xx(void)
{
    boardId_t boardId;
    uint32_t boardRev = BOARD_REV_UNKNOWN;
    const boardData_t * pBoardData = NULL;
    uint8_t i;

    /* Check if board revision is to be auto-detected, or overridden. */
    if (BOARD_AUTO_DETECT == gBoardAm43xxObj.baseBoardRev)
    {
        /* Get the board ID. At the end of this, the other data is already
         * read into the local gBoardDataEeprom variable, and hence it does
         * not need to be read from EEPROM again.
         * If the board ID has already been detected or overridden, it is
         * directly returned. Otherwise it is auto-detected.
         */
        boardId = BoardGetIdAm43xx();

        if (BOARD_UNKNOWN != boardId)
        {
            pBoardData = gpBoardAm43xxData[boardId];

            /* Check for the board revision that matches. */
            for (i = 0U ; (i < pBoardData->numRevStrings) ; i++)
            {
                /* Check if the board revision matches. */
                if (strncmp(pBoardData->pRevStringTable[i],
                            (char *)gBoardDataEeprom.version,
                            BOARD_AM43XX_VERSION_CMP_SIZE) == 0U)
                {
                    boardRev = i;
                    break;
                }
            }
        }
    }
    else
    {
        /* Return the already detected / overridden board revision */
        boardRev = gBoardAm43xxObj.baseBoardRev;
    }

    /* Set the global to the found value. */
    gBoardAm43xxObj.baseBoardRev = boardRev;

    return (boardRev);
}

const char * BoardGetBaseBoardRevNameAm43xx(void)
{
    uint32_t boardRev;
    const char * pBoardRevStr = NULL;

    /* Board ID should have been detected before this API is called. */
    ASSERT (BOARD_UNKNOWN != gBoardAm43xxObj.boardId);
    ASSERT (BOARD_AUTO_DETECT != gBoardAm43xxObj.boardId);

    /* If the board revision has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
    boardRev = BoardGetBaseBoardRevAm43xx();
    ASSERT (boardRev <
            gpBoardAm43xxData[gBoardAm43xxObj.boardId]->numRevStrings);

    /* Get the revision string from the board data. */
    pBoardRevStr =
        gpBoardAm43xxData[gBoardAm43xxObj.boardId]->pRevStringTable[boardRev];

    return (pBoardRevStr);
}

uint32_t BoardGetDcRevAm43xx(void)
{
    uint32_t dcBoardRev = BOARD_REV_UNKNOWN;

    /* Check if board revision is to be auto-detected, or overridden. */
    if (BOARD_AUTO_DETECT == gBoardAm43xxObj.dcBoardRev)
    {
        /* To be implemented once support for add-on daughter cards is added. */
        dcBoardRev = BOARD_REV_UNKNOWN;
    }
    else
    {
        /* Return the already detected / overridden board revision */
        dcBoardRev = gBoardAm43xxObj.dcBoardRev;
    }

    /* Set the global to the found value. */
    gBoardAm43xxObj.dcBoardRev = dcBoardRev;

    return (dcBoardRev);
}

const char * BoardGetDcRevNameAm43xx(void)
{
    const char * pBoardDcRevStr = NULL;
    uint32_t dcBoardRev = BOARD_REV_UNKNOWN;

    /* Board ID should have been detected before this API is called. */
    ASSERT (BOARD_UNKNOWN != gBoardAm43xxObj.boardId);
    ASSERT (BOARD_AUTO_DETECT != gBoardAm43xxObj.boardId);

    /* If the board dc revision has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
    dcBoardRev = BoardGetDcRevAm43xx();
    ASSERT (dcBoardRev <
            gpBoardAm43xxData[gBoardAm43xxObj.boardId]->numRevStrings);

    /* Return the string from board rev string table for now. */
    pBoardDcRevStr =
        gpBoardAm43xxData[gBoardAm43xxObj.boardId]->pRevStringTable[dcBoardRev];

    return (pBoardDcRevStr);
}

const boardI2cData_t * BoardGetI2cDataAm43xx(void)
{
    return (&gBoardAm43xxI2cData);
}

const boardData_t *BoardGetDataAm43xx(void)
{
    boardId_t boardId;
    const boardData_t * pBoardData = NULL;

    /* Get the board ID. At the end of this, the other data is already
     * read into the local gBoardDataEeprom variable, and hence it does
     * not need to be read from EEPROM again.
     * If the board ID has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
    boardId = BoardGetIdAm43xx();
    pBoardData = gpBoardAm43xxData[boardId];

    return (pBoardData);
}
