/**
 * \file   board_am335x_beagleboneblack.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based BEAGLEBONEBLACK board.
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
#include "board_priv.h"
#include "device.h"
#include "error.h"
#include "gpio.h"
#include "board_am335x.h"
#include "am335x_pinmux.h"
#include "dcard_am335x.h"
#include "console_utils.h"
#include "prcm.h"
#include "dcard.h"
#include "am335x_lcd4_dcard.h"
#include "lcdc.h"
#include "debug.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Number of GPIO pin that controls the back light of LCD4 
           BBB. */
#define BOARD_AM335X_BBB_DCARD_LCD4_00A1_BACK_LIGHT_PIN             (18U)

/** \brief Instance Number of GPIO pin that controls the back light of LCD4 on
           BBB. */
#define BOARD_AM335X_BBB_DCARD_LCD4_00A1_BACK_LIGHT_PIN_INST        (1U)

/** \brief Number of GPIO pin that controls the AVDD enable of LCD4 on 
           BBB. */
#define BOARD_AM335X_BBB_DCARD_LCD4_00A1_AVDD_PIN             (19U)

/** \brief Instance Number of GPIO pin that controls the back light of LCD4 
           BBB. */
#define BOARD_AM335X_BBB_DCARD_LCD4_00A1_AVDD_PIN_INST        (3U)


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */



/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  This function powers on the daughter card device based on 
 *          daughter card and its device ID. 
 *
 *  \param  dCardId    Daughter card ID
 *  \param  devId      Daughter card device ID
 *  \param  devInstNum Daughter card device instance number 
 *  \param  powerOn    power on or off flag
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */
uint32_t BoardAm335xBBBPowerOnDCardDev(uint32_t dCardId, 
                                       uint32_t devId,
                                       uint32_t devInstNum,
                                       uint32_t powerOn);

/**
 *  \brief  This function enables the backlight of the LCD. 
 *
 *  \param  pinNum      GPIO pin number
 *  \param  instNum     GPIO pin instance number
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */
                                       
uint32_t BoardAm335xBBBLcdBacklightEnable(uint32_t pinNum,
                                          uint32_t instNum);

/**
 *  \brief  This function configures the GPIO pin to enable AVDD. 
 *          It enables the Power management IC on the LCD4 daughter 
 *          card.
 *  \param  pinNum      GPIO pin number
 *  \param  instNum     GPIO pin instance number
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */                                   
uint32_t BoardAm335xBBBLcdAvddEnable(uint32_t pinNum,
                                     uint32_t instNum);

/**
 *  \brief  This function does GPIO configuration like pinmuxing,
 *          clock enabling, setting input output direction. 
 *
 *  \param  pinNum      GPIO pin number
 *  \param  instNum     GPIO pin instance number
 *  \param  instAddr    GPIO pin instance address
 *  \param  direction   GPIO pin direction
 
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */                                  
uint32_t BoardAm335xBBBGpioCfg(uint32_t pinNum,
                               uint32_t instNum,
                               uint32_t instAddr,
                               uint32_t direction);

/**
 *  \brief  This function initializes board specific lcd 
 *         parameters like pixel format and palete mode based on lcd device ID. 
 *
 *  \param  lcdDevId                Lcd device ID.
 *  \param  pLcdDeviceBoardData     Pointer to the board specific LCD data.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */                                                                 
int32_t BoardAm335xBBBGetLcdDevData(uint32_t lcdDevId, 
                                 lcdDeviceBoardData_t *pLcdDeviceBoardData);                               
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

uint8_t gBoardAm335xBeagleBoneBlackIsDCardPresent[DCARD_MAX + 1U] = 
{
    FALSE,     /* DCARD_UNKNOWN */
    FALSE,     /* DCARD_LCD4 */
};

const uint8_t gBoardAm335xBeagleBoneBlackIsCompatible[DCARD_MAX + 1U]
                                                     [DCARD_MAX + 1U] = 
{ /*DCARD_UNKNOWN */        /* DCARD_LCD4 */
    {TRUE,                       FALSE},     /* DCARD_UNKNOWN */
    {FALSE,                       TRUE},     /* DCARD_LCD4 */
};

const dCardData_t *gBoardAm335xBeagleboneblackDCardsList[DCARD_MAX + 1U] =
{
    NULL,       /* DCARD_UNKNOWN */
    NULL        /* DCARD_LCD4 */
};

const lcdDeviceBoardData_t gBoardAm335xBeagleboneblackLcd4DevData =
{
    LCDC_PIXEL_FORMAT_RGB16, /* pixelFormat*/
    LCDC_PALETTE_MODE_DATA, /* paletteMode */
};
/** \brief This object contains details of all daughter cards present for beaglebone black boards. */
dCards_t gBoardAm335xBeagleboneblackDCards =
{
    (sizeof (gBoardAm335xBeagleboneblackDCardsList) / sizeof (boardData_t *)),
    /* numDCards */
    gBoardAm335xBeagleboneblackDCardsList,
    /* pDdCardList */
    &gBoardAm335xBeagleBoneBlackIsCompatible,
    /* pIsCompatible */
    gBoardAm335xBeagleBoneBlackIsDCardPresent,
    /* pDCardConnected */
    &BoardAm335xBBBPowerOnDCardDev,
    /* pFnBoardPowerOnDCardDev */
    NULL
    /* pFnconnectDCard */
};

/** \brief Information for all devices on the board is provided in this array */
const boardDeviceData_t gBoardAm335xBeagleboneblackDevData[] =
{
#if defined(BUILDCFG_MOD_UART)
    { /* CONSOLE */
        DEVICE_ID_CONSOLE,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_UART,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        72U, /* Interrupt Number */         /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_UART) */
#if defined(BUILDCFG_MOD_I2C)
    { /* EEPROM */
        DEVICE_ID_EEPROM,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        BOARD_EEPROM_I2C_ADDR_0,            /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_CPSW)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_MII,             /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_CPSW,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        1U, /* CPSW port number */          /* ctrlInfo */
        0U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_CPSW) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* LED */
        DEVICE_ID_LED,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        23U, /* GPIO pin number */          /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    }
#endif /* if defined(BUILDCFG_MOD_GPIO) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm335xBeagleboneblackRevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "00A4",      /* EVM A4 version board */
    "00A6"       /* EVM A6 version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t   gBoardAm335xBeagleboneblackData =
{
    (sizeof (gBoardAm335xBeagleboneblackDevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm335xBeagleboneblackDevData,
    /* pDevData */
    gBbbPinmuxData,
    /* pinmux data */
    (BOARD_REV_BEAGLEBONEBLACK_MAX + 1),
    /* numRevStrings */
    gpBoardAm335xBeagleboneblackRevStrTable,
    /* pRevStringTable */
    &gBoardAm335xBeagleboneblackDCards,
    /* pDCards */
    NULL,
    /* pFnBoardInit */
    &BoardAm335xBBBGetLcdDevData
    /* pFnBoardLcdDevData */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t BoardAm335xBBBPowerOnDCardDev(uint32_t dCardId, 
                                       uint32_t devId,
                                       uint32_t devInstNum,
                                       uint32_t powerOn)
{
    uint32_t retVal = E_FAIL;
    char * revStr = NULL;
    const char ** revStrTable = NULL;
    switch(dCardId)
    {
        case DCARD_LCD4:
        {
            switch(devId)
            {    
                case DEVICE_ID_DCARD_LCD4_DISPLAY:
                {
                    revStrTable =DCARDGetRevTable(dCardId);
                    ASSERT(NULL != revStrTable);
                    
                    revStr = (char *)DCARDGetRevStr(dCardId);
                    ASSERT(NULL != revStr);
              
                    if(strncmp(revStrTable[DCARD_REV_AM335X_LCD4_A1],
                               revStr,4U) == 0U)
                    {
                        retVal = BoardAm335xBBBLcdBacklightEnable(
                        BOARD_AM335X_BBB_DCARD_LCD4_00A1_BACK_LIGHT_PIN,
                        BOARD_AM335X_BBB_DCARD_LCD4_00A1_BACK_LIGHT_PIN_INST);
                        
                        if(S_PASS == retVal)
                        {
                            retVal = BoardAm335xBBBLcdAvddEnable(
                            BOARD_AM335X_BBB_DCARD_LCD4_00A1_AVDD_PIN,
                            BOARD_AM335X_BBB_DCARD_LCD4_00A1_AVDD_PIN_INST);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }        

    return retVal;
}

int32_t BoardAm335xBBBGetLcdDevData(uint32_t lcdDevId, 
                                  lcdDeviceBoardData_t *pLcdDeviceBoardData)
{
    uint32_t retVal = E_FAIL;
    switch(lcdDevId)
    {    
        case DEVICE_ID_DCARD_LCD4_DISPLAY:
        {
                pLcdDeviceBoardData->pixelFormat = 
                gBoardAm335xBeagleboneblackLcd4DevData.pixelFormat;
                
                pLcdDeviceBoardData->paletteMode = 
                gBoardAm335xBeagleboneblackLcd4DevData.paletteMode;
                
                retVal = S_PASS;
                break;
        }
        default:
                break;
    }
    
    return retVal;
}
uint32_t BoardAm335xBBBLcdBacklightEnable( uint32_t pinNum, uint32_t instNum)
{
    uint32_t retVal = E_FAIL;
    uint32_t instAddr = 0U;
    
    /* Perform GPIO configuration corresponding to the LCD4 back light control */
        
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, instNum))
    {
        instAddr =
        CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, instNum);

        retVal = BoardAm335xBBBGpioCfg(pinNum, instNum,
                            instAddr, GPIO_DIRECTION_OUTPUT);

        if(S_PASS == retVal)
        {
            GPIOPinWrite(instAddr, pinNum, GPIO_PIN_HIGH);
        }
        else
        {
            CONSOLEUtilsPrintf("\n GPIO configuration failed.");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\n GPIO instance is not present\n");
    }
                
    return retVal;
}

uint32_t BoardAm335xBBBLcdAvddEnable(uint32_t pinNum, uint32_t instNum)
{
    uint32_t retVal = E_FAIL;
    uint32_t instAddr = 0U;
 
    /* Perform GPIO configuration corresponding to the LCD4 AVDD enable */
     
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, instNum))
    {
        instAddr =
        CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, instNum);

        retVal = BoardAm335xBBBGpioCfg(pinNum, instNum,
                            instAddr, GPIO_DIRECTION_OUTPUT);

        if(S_PASS == retVal)
        {
            GPIOPinWrite(instAddr, pinNum, GPIO_PIN_HIGH);
        }
        else
        {
            CONSOLEUtilsPrintf("\n GPIO configuration failed.");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\n GPIO instance is not present\n");
    }
           
    return retVal;
}

uint32_t BoardAm335xBBBGpioCfg(uint32_t pinNum,
                               uint32_t instNum,
                               uint32_t instAddr,
                               uint32_t direction)
{
    int32_t status = E_FAIL;

    /* Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, instNum, 0);
    if(S_PASS == status)
    {
        /* PinMux Configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, instNum, &pinNum);
        if(S_PASS == status)
        {
            /* Enabling the GPIO module. */
            GPIOModuleEnable(instAddr, TRUE);
          
            /* Configure Pin as an Input/Output Pin. */
            GPIODirModeSet(instAddr, pinNum, direction);
        }
    }

    return status;
}
