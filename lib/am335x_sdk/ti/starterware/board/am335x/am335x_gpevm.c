/**
 * \file   board_am335x_gpevm.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based GPEVM board.
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
#include "board_am335x.h"
#include "am335x_gpevm.h"
#include "am335x_pinmux.h"
#include "prcm.h"

#include "gpio.h"
#include "console_utils.h"
#include "i2c_utils.h"

#include "lcdc.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \name Pin number and instance numbers of GPIO Pins that controls the
 *        back light of LCD on AM335X GPEVM board.
 */
/** @{ */
/** \brief Number of GPIO pin that controls the back light of LCD on AM335X
           GPEVM board. */
#define BOARD_AM335x_GPEVM_LCD_BACK_LIGHT_PIN             (7U)

/** \brief Instance Number of GPIO pin that controls the back light of LCD on
           AM335X GPEVM board. */
#define BOARD_AM335x_GPEVM_LCD_DEVICE_BACK_LIGHT_PIN_INST (0U)
/** @} */

/** \brief Macro indicating the i2c time out value. */
#define BOARD_I2C_TIMEOUT_VAL           (1000U)
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API configures the GPIO pin that controls the back light of
 *          the LCD device.
 *
 * \param   devId       device id of the LCD device.
 * \param   devInstNum  Instance number of the LCD device.
 * \param   powerOn     This controls powering on and power off of the device.
 *
 * \retval  S_PASS      Device power on is successful
 * \retval  E_FAIL      Device power on is failed.
 */
int32_t BoardAm335xGpevmLcdDevicePowerOn(uint32_t devId,
                                         uint32_t devInstNum,
                                         uint32_t powerOn);

/**
 *  \brief  This function initializes board specific lcd 
 *         parameters like pixel format and palette mode based on lcd device ID. 
 *
 *  \param  lcdDevId                Lcd device ID.
 *  \param  pLcdDeviceBoardData     Pointer to the board specific LCD data.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */                                                                                                          
int32_t BoardAm335xGpevmGetLcdDevData(uint32_t lcdDevId, 
                                     lcdDeviceBoardData_t *pLcdDeviceBoardData);                              
/**
 * \brief   This API configures the GPIO pin that controls the back light of
 *          the LCD device.
 *
 * \param   pinNum     GPIO pin number.
 * \param   instNum    GPIO instance number.
 * \param   instAddr   GPIO module instance address.
 * \param   direction  GPIO pin direction. This can following values
 *                     GPIO_DIRECTION_OUTPUT, GPIO_DIRECTION_INPUT.
 *
 * \retval  S_PASS      GPIO configuration is successful
 * \retval  E_FAIL      GPIO configuration is failed.
 */
int32_t BoardAm335xGpevmGpioCfg(uint32_t pinNum,
                                uint32_t instNum,
                                uint32_t instAddr,
                                uint32_t direction);


/**
 * \brief   This API configures the UPDP Pin.
 *
 * \retval  S_PASS  Pin configuration is successful.
 * \retval  E_FAIL  Pin configuration failed.
 */
int32_t BoardAm335xGpevmLcdUpdnPinControl(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

const lcdDeviceBoardData_t gBoardAm335xGpevmLcdDevData =
{
    LCDC_PIXEL_FORMAT_RGB24_UNPACKED, /* pixelFormat*/
    LCDC_PALETTE_MODE_BOTH_PALETTE_DATA, /* paletteMode */
};

/** \brief Information for all devices on the board is provided in this array */
const boardDeviceData_t gBoardAm335xGpevmDevData[] =
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
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
    { /* Temperature sensor */
        DEVICE_ID_TMP275,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_TMP275_I2C_ADDR_0,            /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
    { /* Accelerometer */
        DEVICE_ID_LIS331DLH,                /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_LIS331DLH_I2C_ADDR_0,         /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
    { /* AIC31 */
        DEVICE_ID_AIC31,                    /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_AIC31_I2C_ADDR_0,             /* ctrlInfo */
        CHIPDB_MOD_ID_MCASP,                /* dataModId */
        1U,                                 /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* Audio Buzzer */
        DEVICE_ID_BUZZER,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        23U, /* GPIO pin number */          /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_PWMSS)
   { /* Haptics Motor */
        DEVICE_ID_HAPTICS,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_PWMSS,                /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        1U, /* EPWM Out Ch 0=A, 1=B CH */   /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_PWMSS) */
#if defined(BUILDCFG_MOD_MCSPI)
   { /* W25Q64BV SPI Flash */
        DEVICE_ID_W25Q64BV,                 /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_MCSPI,                /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* Chip Select */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_MCSPI) */

#if defined(BUILDCFG_MOD_LCDC)
   { /* LCD */
        DEVICE_ID_LCD_S9700RTWV43_01B,      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_LCDC,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U,                          
       /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        BoardAm335xGpevmLcdDevicePowerOn,   /* pFnPowerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_LCDC) */
#if defined(BUILDCFG_MOD_CPSW)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RGMII,           /* devId */
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
#if defined(BUILDCFG_MOD_DCAN)
   { /* DCAN */
        DEVICE_ID_DCAN_CONNECTOR,           /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_DCAN,                 /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        0U,                                 /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL,                               /* powerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_DCAN) */

#if defined(BUILDCFG_MOD_GPMC)
   {
        DEVICE_ID_FLASH_MT29F2G08ABAEAWP,   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPMC,                 /* ctrlModId */
        0U,  /* Chip Select number */       /* ctrlModInstNum */
        0U, /* Wait Pin Number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPMC) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm335xGpevmRevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "1.0",       /* EVM 1.0x version board */
    "1.1",       /* EVM 1.1x version board */
    "1.2",       /* EVM 1.2x version board */
    "1.5"        /* EVM 1.5x version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t gBoardAm335xGpevmData =
{
    (sizeof (gBoardAm335xGpevmDevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm335xGpevmDevData,
    /* pDevData */
    gGpevmPinmuxData,
    /* pPinmuxData */
    (BOARD_REV_GPEVM_MAX + 1),
    /* numRevStrings */
    gpBoardAm335xGpevmRevStrTable,
    /* pRevStringTable */
    NULL,
    /* pDCards */
    NULL,
    /* pFnBoardInit */
    &BoardAm335xGpevmGetLcdDevData
    /* pFnBoardLcdDevData */
};


/** \brief Buffer containing the data that has to be transmitted over i2c. */
uint8_t gDataToSlave[2U];

/** \brief Buffer to hold the received data through i2c interface. */
uint8_t gDataFromSlave[2U];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BoardAm335xGpevmLcdDevicePowerOn(uint32_t devId,
                                         uint32_t devInstNum,
                                         uint32_t powerOn)
{
    uint32_t retVal = E_FAIL;
    uint32_t pinNum  = 0U;
    uint32_t instNum = 0U;
    uint32_t instAddr = 0U;

    /* Perform GPIO configuration corresponding to the LCD back light control */
    switch(devId)
    {
        case DEVICE_ID_LCD_S9700RTWV43_01B:
        {
            switch(devInstNum)
            {
                case 0U:
                {
                    /* GPIO Pin: GPIO_0_7 */
                    pinNum  = BOARD_AM335x_GPEVM_LCD_BACK_LIGHT_PIN;
                    instNum = BOARD_AM335x_GPEVM_LCD_DEVICE_BACK_LIGHT_PIN_INST;
                    if(TRUE ==
                        CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, instNum))
                    {
                        instAddr =
                            CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, instNum);

                        retVal = BoardAm335xGpevmGpioCfg(pinNum, instNum,
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
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    retVal = BoardAm335xGpevmLcdUpdnPinControl();
    if (S_PASS != retVal)
    {
        CONSOLEUtilsPrintf("\n UPDP Pin configuration failed. \n");
    }

    return retVal;
}

int32_t BoardAm335xGpevmGetLcdDevData(uint32_t lcdDevId, 
                                     lcdDeviceBoardData_t *pLcdDeviceBoardData)
{
    uint32_t retVal = E_FAIL;
    switch(lcdDevId)
    {
        case DEVICE_ID_LCD_S9700RTWV43_01B:
        {
                pLcdDeviceBoardData->pixelFormat = 
                gBoardAm335xGpevmLcdDevData.pixelFormat;
                
                pLcdDeviceBoardData->paletteMode = 
                gBoardAm335xGpevmLcdDevData.paletteMode;
                
                retVal = S_PASS;
                break;
        }
        default:
                break;
    }
    return retVal;
}
int32_t BoardAm335xGpevmLcdUpdnPinControl(void)
{
    int32_t status = E_FAIL;
    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;
    i2cUtilsTxRxParams_t i2cTxRxParams;
    uint32_t i2cInstNum;

    i2cInstNum = 0U;
    status = I2CUtilsInit(i2cInstNum, &i2cUtilsParams);
    if (S_PASS == status)
    {
        /* Transmit data */
        gDataToSlave[0U] = 0x0DU;
        gDataToSlave[1U] = 0x01U;

        i2cTxRxParams.slaveAddr  = 0x40U;
        i2cTxRxParams.pOffset    = NULL;
        i2cTxRxParams.offsetSize = 0U;
        i2cTxRxParams.bufLen = 2U;
        i2cTxRxParams.pBuffer = (uint8_t *) &gDataToSlave;

        status = I2CUtilsWrite(i2cInstNum, &i2cTxRxParams,
            BOARD_I2C_TIMEOUT_VAL);
        if (S_PASS == status)
        {
            /* Receive data: Read the MODE1 register: 00 is the reg offset. */
            gDataToSlave[0U]   = 0x00U;
            gDataFromSlave[0U] = 0x00U;
            gDataFromSlave[1U] = 0x00U;

            i2cTxRxParams.slaveAddr  = 0x40U;
            i2cTxRxParams.pOffset    = &gDataToSlave[0];
            i2cTxRxParams.offsetSize = 1U;
            i2cTxRxParams.bufLen = 1U;
            i2cTxRxParams.pBuffer = (uint8_t *) &gDataFromSlave;

            status = I2CUtilsRead(i2cInstNum, &i2cTxRxParams,
                BOARD_I2C_TIMEOUT_VAL);
            if (S_PASS == status)
            {
                /* Write back the value, exit low power */
                gDataToSlave[0U] = 0U;
                gDataToSlave[1U] = gDataFromSlave[0] & ~0x10U;

                i2cTxRxParams.slaveAddr  = 0x40U;
                i2cTxRxParams.pOffset    = NULL;
                i2cTxRxParams.offsetSize = 0U;
                i2cTxRxParams.bufLen = 2U;
                i2cTxRxParams.pBuffer = (uint8_t *) &gDataToSlave;
                status = I2CUtilsWrite(i2cInstNum, &i2cTxRxParams,
                    BOARD_I2C_TIMEOUT_VAL);
            }
        }
    }

    return status;
}


int32_t BoardAm335xGpevmGpioCfg(uint32_t pinNum,
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
