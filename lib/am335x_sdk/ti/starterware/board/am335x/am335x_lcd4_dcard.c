
/**
 * \file   am335x_lcd4_dcard.c
 *
 * \brief  This file contains the information of the daughter card LCD4
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
#include "lcd_device.h"
#include "error.h"
#include "board_am335x.h"
#include "am335x_lcd4_dcard.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/** \brief Size of EEPROM header in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_HEADER_SIZE           (4U)
/** \brief Size of EEPROM data for board name in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_BOARD_NAME_SIZE       (20U)
/** \brief Size of EEPROM data for version in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_VERSION_SIZE          (4U)
/** \brief Size of EEPROM data for serial number in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_SERIAL_NUMBER_SIZE    (12U)

/** \brief Size of EEPROM header in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_HEADER_OFFSET         (0U)
/** \brief Size of EEPROM data for board name in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_BOARD_NAME_OFFSET     (6U)
/** \brief Size of EEPROM data for version in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_VERSION_OFFSET        (38U)
/** \brief Size of EEPROM data for serial number in bytes on AM335x. */
#define DCARD_LCD4_EEPROM_SERIAL_NUMBER_OFFSET  (76U)

/** \brief Unkown I2C instance number. */
#define UNKNOWN_I2C_INST_NUM                    (0xFFFFFFFF)
/** \brief Unkown I2C base address. */
#define UNKNOWN_I2C_BASE_ADDRESS                (0xFFFFFFFF)
/** \brief Unkown I2C iterrupt number. */
#define UNKNOWN_I2C_BASE_INTR_NUM               (0xFFFFFFFF)
/** \brief Unkown I2C bus clock. */
#define UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK        (0xFFFFFFFF)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function returns an array which holds the EEPROM offset in proper
           format. The format depends on the daughter card EEPROM address range.
 * \param  offset      EEPROM Offset address   
 *
 * \retval array containing the EEPROM offset address in byte format-MSB first.
 */
uint8_t *DCardAm335xLCD4GetEepromOffset(uint32_t offset);

/**
 * \brief  This value returned by this function indicates that EEPROM is 
 *         addresible by this many bytes.
 * \retval number of bytes by which EEPROM is addresible.
 */
uint8_t DCardAm335xLCD4GetEepromOffsetSize();

/* ========================================================================== */
/*                            Global Vaiables                                */
/* ========================================================================== */


/** \brief For two byte addresible EEPROM offset address initialized to zero */
uint8_t gDCardAm335xLCD4EepromOffset[2U] = 
{
        0x00,
        0x00
};

/** \brief Information for all devices on the LCD4 daughter card is provided in this array */
const boardDeviceData_t gDCardAm335xLCD4DevData[] =
{
#if defined(BUILDCFG_MOD_I2C)
    { /* EEPROM */
        DEVICE_ID_EEPROM,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        0xFF,                               /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_LCDC)
   { /* LCD */
        DEVICE_ID_DCARD_LCD4_DISPLAY,       /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_LCDC,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U,                                 /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL,                               /* pFnPowerOnDev */
   }
#endif /* if defined(BUILDCFG_MOD_LCDC) */
};

/** \brief Strings configured for LCD4 daughter card revision 
 *         information in the EEPROM. 
 */
const char * gpDCardAm335xLCD4RevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "00A1",      /* LCD4 A1 version board */
};

/** \brief Following are the possible slave addresses for LCD4 
 *         EEPROM, based on the switch positions on the board
 */
uint32_t gDCardAM335xLCD4I2cSlaveAddrRange[] = 
{
    0x54,
    0x55,
    0x56,
    0x57
};

/** \brief I2C instances data for AM335x boards to detect LCD4*/
boardI2cInstData_t gDCardAm335xLCD4I2cInstData[] =
{
    /* BOARD_UNKNOWN */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_GPEVM */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_EVMSK */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_BEAGLEBONE */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_IDKEVM */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_EPOSEVM */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    },
    /* BOARD_BEAGLEBONEBLACK */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        2U,                                 /* instNum */
        0x0U,                               /* baseAddr */
        0U,                                 /* intNum */
        100U                                /* busClkKHz */
    },
    /* BOARD_CUSTOM */
    { /* baseAddr & intNum get filled during initialization using ChipDB. */
        UNKNOWN_I2C_INST_NUM,               /* instNum */
        UNKNOWN_I2C_BASE_ADDRESS,           /* baseAddr */
        UNKNOWN_I2C_BASE_INTR_NUM,          /* intNum */
        UNKNOWN_I2C_BASE_ADDRESS_BUS_CLK    /* busClkKHz */
    }
};

/** \brief matrix to hold EEPROM data format 
 *         each row corresponds to parameter     
 *         column 0 is offset of the parameter
 *         column 1 is the size of the parameter string
 */
uint32_t gDCardAm335xLCD4EepromDataFormat[4U][2U] =
{
    {DCARD_LCD4_EEPROM_HEADER_OFFSET,       DCARD_LCD4_EEPROM_HEADER_SIZE},
    {DCARD_LCD4_EEPROM_BOARD_NAME_OFFSET,   DCARD_LCD4_EEPROM_BOARD_NAME_SIZE},
    {DCARD_LCD4_EEPROM_VERSION_OFFSET,      DCARD_LCD4_EEPROM_VERSION_SIZE},
    {DCARD_LCD4_EEPROM_SERIAL_NUMBER_OFFSET,DCARD_LCD4_EEPROM_SERIAL_NUMBER_SIZE}
};

uint8_t gDCardAm335xLCD4EepromDataHeader[DCARD_LCD4_EEPROM_HEADER_SIZE + 1];
uint8_t gDCardAm335xLCD4EepromDataBoardName[DCARD_LCD4_EEPROM_BOARD_NAME_SIZE + 1];
uint8_t gDCardAm335xLCD4EepromDataVersion[DCARD_LCD4_EEPROM_VERSION_SIZE + 1];
uint8_t gDCardAm335xLCD4EepromDataSerialNumber[DCARD_LCD4_EEPROM_SERIAL_NUMBER_SIZE + 1];

/** \brief This object contains details of the LCD4 daughter card. */
const dCardData_t gDCardAm335xLCD4Data =
{
        DCARD_LCD4,
        /* dCardId */
        "BeagleBone LCD4 CAPE",
        /* pDCardName */
        (sizeof (gDCardAm335xLCD4DevData) / sizeof (boardDeviceData_t)),
        /* numDev */
        gDCardAm335xLCD4DevData,
        /* pDevData */
        {
            gDCardAm335xLCD4EepromDataHeader,
            gDCardAm335xLCD4EepromDataBoardName,
            gDCardAm335xLCD4EepromDataVersion,
            gDCardAm335xLCD4EepromDataSerialNumber
        },
        /* eepromData */
        gDCardAm335xLCD4EepromDataFormat,
        /* eepromDataFormat */
        gDCardAm335xLCD4I2cInstData,
        /* pI2cInstData */
        (sizeof (gDCardAM335xLCD4I2cSlaveAddrRange) / sizeof (uint32_t)),
        /* numI2cSlaveAddr */
        gDCardAM335xLCD4I2cSlaveAddrRange,
        /* pI2cSlaveAddrRange */
        (DCARD_REV_AM335X_LCD4_MAX + 1),
        /* numRevStrings */
        gpDCardAm335xLCD4RevStrTable,
        /* pRevStringTable */
        &DCardAm335xLCD4GetEepromOffset,
        /* pFnDCardGetEepromOffset */
        &DCardAm335xLCD4GetEepromOffsetSize,
        /* pFnDCardGetEepromOffsetSize */
        NULL
        /* pFnBoardInit */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


uint8_t * DCardAm335xLCD4GetEepromOffset(uint32_t offset)
{
    gDCardAm335xLCD4EepromOffset[0U] = (offset >> 8U) & 0xFF;
    gDCardAm335xLCD4EepromOffset[1U] = (offset & 0xFF);
    
    return gDCardAm335xLCD4EepromOffset;   
}

uint8_t DCardAm335xLCD4GetEepromOffsetSize()
{
    return sizeof(gDCardAm335xLCD4EepromOffset);
}
