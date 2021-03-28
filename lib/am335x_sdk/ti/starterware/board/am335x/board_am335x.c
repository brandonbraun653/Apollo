/**
 * \file   board_am335x.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based boards.
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
#include "board_am335x.h"
#include "am335x_gpevm.h"
#include "am335x_evmsk.h"
#include "am335x_beaglebone.h"
#include "am335x_beagleboneblack.h"
#include "am335x_icev1.h"
#include "am335x_icev2.h"
#include "am335x_amic110.h"
#include "am335x_custom.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Size of EEPROM header in bytes on AM335x. */
#define BOARD_EEPROM_HEADER_SIZE        (4U)
/** \brief Size of EEPROM data for board name in bytes on AM335x. */
#define BOARD_EEPROM_BOARD_NAME_SIZE    (8U)
/** \brief Size of EEPROM data for version in bytes on AM335x. */
#define BOARD_EEPROM_VERSION_SIZE       (4U)
/** \brief Size of EEPROM data for serial number in bytes on AM335x. */
#define BOARD_EEPROM_SERIAL_NUMBER_SIZE (12U)

/** \brief EEPROM offset containing the board information. */
#define BOARD_DATA_EEPROM_OFFSET        (0x00)

/** \brief Size to compare for board version for AM335x. */
#define BOARD_AM335X_VERSION_CMP_SIZE   (0x3U) /* String compare size */

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

/** \brief I2C instances data for AM335x */
static boardI2cInstData_t gBoardAm335xI2cInstData[] =
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

/** \brief I2C data for AM335x */
static boardI2cData_t gBoardAm335xI2cData =
{
    (sizeof (gBoardAm335xI2cInstData) / sizeof (boardI2cInstData_t)),
    /* numInst */
    gBoardAm335xI2cInstData,
    /* pInstData */
    0U,
    /* probeInstNum */
};

/** \brief Board module object. */
static boardCommonObj_t gBoardAm335xObj =
{
    BOARD_UNKNOWN,     /* boardId */
    BOARD_REV_UNKNOWN, /* baseBoardRev */
    BOARD_REV_UNKNOWN  /* dcBoardRev */
};

/** \brief EEPROM data for AM335x. */
static boardDataEeprom_t gBoardDataEeprom;

/**
 * \brief   Pointer to EEPROM data for AM335x. Indicates if EEPROM data has
 *          already been read.
 */
static boardDataEeprom_t * gpBoardDataEeprom = NULL;

/* TBD: Kept as global for now to workaround bug in i2cUtils. */
static uint8_t gEepromOffset[2U] = {
    ((BOARD_DATA_EEPROM_OFFSET >> sizeof (uint8_t)) & 0xFF),
    (BOARD_DATA_EEPROM_OFFSET & 0xFF)
};

#ifndef DDRLESS
/** \brief Contains pointers to the board data for the different boards. */
static const boardData_t *gpBoardAm335xData [BOARD_MAX + 1U]= {
    NULL, /* BOARD_UNKNOWN */
    &gBoardAm335xGpevmData, /* BOARD_GPEVM */
    &gBoardAm335xEvmskData, /* BOARD_EVMSK */
    &gBoardAm335xBeagleboneData, /* BOARD_BEAGLEBONE */
    NULL, /* BOARD_IDKEVM */
    NULL, /* BOARD_EPOSEVM */
    &gBoardAm335xBeagleboneblackData, /* BOARD_BEAGLEBONEBLACK */
    &gBoardAm335xIceV1Data, /*BOARD_ICE ver 1*/
    &gBoardAm335xIceV2Data, /*BOARD_ICE ver 2*/
    &gBoardAm335xAMIC110Data, /* AMIC110 */
    &gBoardAm335xCustomData, /* BOARD_CUSTOM */
};
#else 
static const boardData_t *gpBoardAm335xData [BOARD_MAX + 1U]= {
    NULL, /* BOARD_UNKNOWN */
    &gBoardAm335xAMIC110Data /* AMIC110 */
};
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BoardAm335xInit(const boardInitParams_t *pInitPrms)
{
    uint8_t i;

    for (i = 0 ; i < gBoardAm335xI2cData.numInst ; i++)
    {
        gBoardAm335xI2cData.pInstData[i].baseAddr = CHIPDBBaseAddress(
            CHIPDB_MOD_ID_I2C,
            gBoardAm335xI2cData.pInstData[i].instNum);

        /* TBD: Comment interrupt number for now till implemented */
        /*
        gBoardAm335xI2cData.pInstData[i].baseAddr = ChipDBInterruptNum(
            CHIPDB_MOD_ID_I2C,
            gBoardAm335xI2cData.pInstData[i].instNum,
            intSigType);
        */
    }

    /* Setup the board information. */
    gBoardAm335xObj.boardId      = pInitPrms->boardId;
    gBoardAm335xObj.baseBoardRev = pInitPrms->baseBoardRev;
    gBoardAm335xObj.dcBoardRev   = pInitPrms->dcBoardRev;

    /* Do any initialization/configuration required for AM335X boards. */

    return (S_PASS);
}

#ifndef DDRLESS
boardId_t BoardGetIdAm335x(void)
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
        if (BOARD_AUTO_DETECT == gBoardAm335xObj.boardId)
        {
            pI2cData = BoardGetI2cDataAm335x();
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

                    /* Set NULL character as the last character for the name. */
                    gBoardDataEeprom.boardName
                        [BOARD_EEPROM_BOARD_NAME_SIZE - 1] = '\0';

                    /* Check if the board is GPEVM */
                    if (strncmp(BOARD_AM335X_GPEVM_BOARD_NAME,
                                (char *)gBoardDataEeprom.boardName,
                                BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_GPEVM;
                    }
                    /* Check if the board is EVMSK */
                    else if (strncmp(BOARD_AM335X_EVMSK_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_EVMSK;
                    }
                    /* Check if the board is BEAGLEBONE */
                    else if (strncmp(BOARD_AM335X_BEAGLEBONE_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_BEAGLEBONE;
                    }
                    /* Check if the board is BEAGLEBONEBLACK */
                    else if (strncmp(BOARD_AM335X_BEAGLEBONEBLACK_BOARD_NAME,
                                     (char *)gBoardDataEeprom.boardName,
                                     BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_BEAGLEBONEBLACK;
                    }
                    /* Check if the board is ICE */
                    else if (strncmp(BOARD_AM335X_ICEV1_BOARD_NAME,
                                    (char *)gBoardDataEeprom.boardName,
                                    BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        /* Check if the board is Ice Ver 1 */
                        if (strncmp(BOARD_AM335X_ICEV1_BOARD_VERSION,
                                   (char *)gBoardDataEeprom.version,
                                    BOARD_EEPROM_VERSION_SIZE) == 0U)
                        {
                            boardId = BOARD_ICEV1;
                        }
                        /* Check if the board is Ice Ver 2 */
                        else if (strncmp(BOARD_AM335X_ICEV2_BOARD_VERSION,
                                (char *)gBoardDataEeprom.version,
                                BOARD_EEPROM_VERSION_SIZE) == 0U)
                        {
                            boardId = BOARD_ICEV2;
                        }
                    }
                    /* Check if the board is AMIC110, if so use icev2 settings */
                    else if (strncmp(BOARD_AM335X_AMIC110_BOARD_NAME,
                                    (char *)gBoardDataEeprom.boardName,
                                    BOARD_EEPROM_BOARD_NAME_SIZE) == 0U)
                    {
                        boardId = BOARD_AMIC110;
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
                        if (NULL != gpBoardAm335xData[boardId]->pFnBoardInit)
                        {
                            status = gpBoardAm335xData[boardId]->pFnBoardInit();
                        }
                    }
                }
            }
        }
        else
        {
            /* Return the already detected / overridden board ID */
            boardId = gBoardAm335xObj.boardId;
        }
    }

    /* Set the global to the found value. */
    gBoardAm335xObj.boardId = boardId;

    return (boardId);
}

uint32_t BoardGetBaseBoardRevAm335x(void)
{
    boardId_t boardId;
    uint32_t boardRev = BOARD_REV_UNKNOWN;
    const boardData_t * pBoardData = NULL;
    uint8_t i;

    /* Check if board revision is to be auto-detected, or overridden. */
    if (BOARD_AUTO_DETECT == gBoardAm335xObj.baseBoardRev)
    {
        /* Get the board ID. At the end of this, the other data is already
         * read into the local gBoardDataEeprom variable, and hence it does
         * not need to be read from EEPROM again.
         * If the board ID has already been detected or overridden, it is
         * directly returned. Otherwise it is auto-detected.
         */
        boardId = BoardGetIdAm335x();

        if (BOARD_UNKNOWN != boardId)
        {
            pBoardData = gpBoardAm335xData[boardId];

            /* Check for the board revision that matches. */
            for (i = 0U ; (i < pBoardData->numRevStrings) ; i++)
            {
                /* Check if the board revision matches. */
                if (strncmp(pBoardData->pRevStringTable[i],
                            (char *)gBoardDataEeprom.version,
                            BOARD_AM335X_VERSION_CMP_SIZE) == 0U)
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
        boardRev = gBoardAm335xObj.baseBoardRev;
    }

    /* Set the global to the found value. */
    gBoardAm335xObj.baseBoardRev = boardRev;

    return (boardRev);
}

const char * BoardGetBaseBoardRevNameAm335x(void)
{
    uint32_t boardRev;
    const char * pBoardRevStr = NULL;

    /* Board ID should have been detected before this API is called. */
    ASSERT (BOARD_UNKNOWN != gBoardAm335xObj.boardId);
    ASSERT (BOARD_AUTO_DETECT != gBoardAm335xObj.boardId);

    /* If the board revision has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
    boardRev = BoardGetBaseBoardRevAm335x();
    ASSERT (boardRev <
            gpBoardAm335xData[gBoardAm335xObj.boardId]->numRevStrings);

    /* Get the revision string from the board data. */
    pBoardRevStr =
        gpBoardAm335xData[gBoardAm335xObj.boardId]->pRevStringTable[boardRev];

    return (pBoardRevStr);
}
#endif

uint32_t BoardGetDcRevAm335x(void)
{
    uint32_t dcBoardRev = BOARD_REV_UNKNOWN;

    /* Check if board revision is to be auto-detected, or overridden. */
    if (BOARD_AUTO_DETECT == gBoardAm335xObj.dcBoardRev)
    {
        /* To be implemented once support for add-on daughter cards is added. */
        dcBoardRev = BOARD_REV_UNKNOWN;
    }
    else
    {
        /* Return the already detected / overridden board revision */
        dcBoardRev = gBoardAm335xObj.dcBoardRev;
    }

    /* Set the global to the found value. */
    gBoardAm335xObj.dcBoardRev = dcBoardRev;

    return (dcBoardRev);
}

const char * BoardGetDcRevNameAm335x(void)
{
    const char * pBoardDcRevStr = NULL;
    uint32_t dcBoardRev = BOARD_REV_UNKNOWN;

    /* Board ID should have been detected before this API is called. */
    ASSERT (BOARD_UNKNOWN != gBoardAm335xObj.boardId);
    ASSERT (BOARD_AUTO_DETECT != gBoardAm335xObj.boardId);

    /* If the board dc revision has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
    dcBoardRev = BoardGetDcRevAm335x();
    ASSERT (dcBoardRev <
            gpBoardAm335xData[gBoardAm335xObj.boardId]->numRevStrings);

    /* Return the string from board rev string table for now. */
    pBoardDcRevStr =
        gpBoardAm335xData[gBoardAm335xObj.boardId]->pRevStringTable[dcBoardRev];

    return (pBoardDcRevStr);
}

const boardI2cData_t * BoardGetI2cDataAm335x(void)
{
    return (&gBoardAm335xI2cData);
}

const boardData_t *BoardGetDataAm335x(void)
{
    boardId_t boardId;
    const boardData_t * pBoardData = NULL;

    /* Get the board ID. At the end of this, the other data is already
     * read into the local gBoardDataEeprom variable, and hence it does
     * not need to be read from EEPROM again.
     * If the board ID has already been detected or overridden, it is
     * directly returned. Otherwise it is auto-detected.
     */
#ifndef DDRLESS
	boardId = BoardGetIdAm335x();
#else
	boardId = BOARD_AMIC110;
#endif
    pBoardData = gpBoardAm335xData[boardId];

    return (pBoardData);
}
