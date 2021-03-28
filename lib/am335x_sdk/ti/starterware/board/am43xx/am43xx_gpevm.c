/**
 * \file   board_am43xx_gpevm.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM43xx based GPEVM board.
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
#include "board_priv.h"
#include "device.h"
#include "error.h"
#include "board_am43xx.h"
#include "am43xx_gpevm.h"
#include "am43xx_pinmux.h"
#include "prcm.h"

#include "gpio.h"
#include "console_utils.h"
#include "camera_device.h"
#include "pmic_device_tps65218.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \name Pin number and instance numbers of GPIO Pins that controls the
 *        following features of LCD on AM43XX GPEVM board: LCD/HDMI Selection,
 *        Back light control.
 */
/** @{ */
/** \brief Number of GPIO pin that controls the selection of LCD/HDMI
           on AM43XX GPEVM board. */
#define BOARD_AM43xx_GPEVM_LCD_DEVICE_SEL_PIN             (8U)

/** \brief Instance Number of GPIO pin that controls the selection of LCD/HDMI
           on AM43XX GPEVM board. */
#define BOARD_AM43xx_GPEVM_LCD_DEVICE_SEL_PIN_INST        (5U)

/** \brief Number of GPIO pin that controls the back light of LCD on AM43XX
           GPEVM board. */
#define BOARD_AM43xx_GPEVM_LCD_BACK_LIGHT_PIN             (7U)

/** \brief Instance Number of GPIO pin that controls the back light of LCD on
           AM43XX GPEVM board. */
#define BOARD_AM43xx_GPEVM_LCD_DEVICE_BACK_LIGHT_PIN_INST (0U)
/** @} */


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  Initialize the AM335x based GPEVM board.
 *
 *  \retval S_PASS      On success
 */
int32_t BoardAm43xxGpevmInit(void);

/**
 * \brief   This API configures the GPIO pin that controls the HDMI/LCD device
 *          selection.
 *
 * \param   devId       device id of the LCD device.
 * \param   devInstNum  Instance number of the LCD device.
 *
 * \retval  S_PASS       Device selection is successful
 * \retval  E_FAIL       Device selection is failed.
 */
int32_t BoardAm43xxGpevmLcdDeviceSelect(uint32_t devId, uint32_t devInstNum);


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
int32_t BoardAm43xxGpevmLcdDevicePowerOn(uint32_t devId,
                                         uint32_t devInstNum,
                                         uint32_t powerOn);


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
int32_t BoardAm43xxGpevmGpioCfg(uint32_t pinNum,
                                uint32_t instNum,
                                uint32_t instAddr,
                                uint32_t direction);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Information for all devices on the board is provided in this array */
const boardDeviceData_t gBoardAm43xxGpevmDevData[] =
{
#if defined(BUILDCFG_MOD_UART)
    { /* CONSOLE */
        DEVICE_ID_CONSOLE,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_UART,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        104U, /* Interrupt Number */        /* ctrlInfo */
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
    { /* Temperature sensor */
        DEVICE_ID_TMP275,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_TMP275_I2C_ADDR_0,            /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* Accelerometer */
        DEVICE_ID_LIS331DLH,                /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_LIS331DLH_I2C_ADDR_0,         /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* AIC31 */
        DEVICE_ID_AIC31,                    /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        BOARD_AIC31_I2C_ADDR_0,             /* ctrlInfo */
        CHIPDB_MOD_ID_MCASP,                /* dataModId */
        1U,                                 /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* PMIC */
        DEVICE_ID_PMIC_TPS65218,            /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0x24,                               /* ctrlInfo */
        0x00000201, /*Rails to Output sources Mapping */ /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* LED */
        DEVICE_ID_LED,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        5U,                                 /* ctrlModInstNum */
        10, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
	{ /* LED */
        DEVICE_ID_LED,                      /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        5U,                                 /* ctrlModInstNum */
        11, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* LED */
        DEVICE_ID_LED,                      /* devId */
        2U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        18, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* Audio Buzzer */
        DEVICE_ID_BUZZER,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        4U,                                 /* ctrlModInstNum */
        12U, /* GPIO pin number */          /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* VTT */
        DEVICE_ID_VTT,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        5U,                                 /* ctrlModInstNum */
        7U, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_PWMSS)
   { /* Haptics Motor */
        DEVICE_ID_HAPTICS,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_PWMSS,                /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* EPWM Out Ch 0=A, 1=B CH */   /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL,                               /* pFnPowerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_PWMSS) */
#if defined(BUILDCFG_MOD_DSS)
   { /* LCD */
        DEVICE_ID_LCD_OSD070T1718_19TS,     /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_DSS,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U,                                 /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        BoardAm43xxGpevmLcdDeviceSelect,    /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        BoardAm43xxGpevmLcdDevicePowerOn,   /* pFnPowerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_DSS) */
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
        0U,                                 /* ctrlModInstNum */
        0U,                                 /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL,                               /* powerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_DCAN) */
#if defined(BUILDCFG_MOD_VPFE)
   { /* LCD */
        DEVICE_ID_CAMERA_OV2659,             /* devId */
        0U,                                  /* devInstNum */
        CHIPDB_MOD_ID_VPFE,                  /* ctrlModId */
        0U,                                  /* ctrlModInstNum */
        1U, /* sensor i2c instance */        /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,               /* dataModId */
        INVALID_INST_NUM,                    /* dataModInstNum */
        NULL,                                /* pFnSelectDev */
        NULL,                                /* pFnResetDev */
        NULL,                                /* pFnPowerOnDev */
   },
#endif /* if defined(BUILDCFG_MOD_VPFE) */
#if defined(BUILDCFG_MOD_GPMC)
   { /* NAND Flash */
        DEVICE_ID_FLASH_MT29F4G08ABAEAWP,   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPMC,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* Chip Select number */        /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    }
#endif  /* if defined(BUILDCFG_MOD_GPMC) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm43xxGpevmRevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "1.0A",      /* EVM 1.0A version board */
    "1.1B",      /* EVM 1.1B version board */
    "1.2",       /* EVM 1.1B version board */
    "1.5"        /* EVM 1.1B version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t gBoardAm43xxGpevmData =
{
    (sizeof (gBoardAm43xxGpevmDevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm43xxGpevmDevData,
    /* pDevData */
    gGpevmPinmuxData,
    /* pPinmuxData */
    (BOARD_REV_GPEVM_MAX + 1),
    /* numRevStrings */
    gpBoardAm43xxGpevmRevStrTable,
    /* pRevStringTable */
    NULL,
    /* pDCards */
    &BoardAm43xxGpevmInit,
    /* pFnBoardInit */
    NULL
    /* pFnBoardLcdDevData */
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BoardAm43xxGpevmInit(void)
{
    /* Perform AM43xx GPEVM specific initialization, if any. */
    return S_PASS;
}

int32_t BoardAm43xxGpevmLcdDeviceSelect(uint32_t devId, uint32_t devInstNum)
{
    uint32_t retVal  = E_FAIL;
    uint32_t pinNum  = 0U;
    uint32_t instNum = 0U;
    uint32_t instAddr = 0U;

    /* Perform GPIO configuration corresponding to the LCD/HDMI selection */
    switch(devId)
    {
        case DEVICE_ID_LCD_OSD070T1718_19TS:
        {
            switch(devInstNum)
            {
                case 0U:
                {
                    /* GPIO Pin: GPIO_5_8 */
                    pinNum  = BOARD_AM43xx_GPEVM_LCD_DEVICE_SEL_PIN;
                    instNum = BOARD_AM43xx_GPEVM_LCD_DEVICE_SEL_PIN_INST;
                    if(TRUE ==
                        CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, instNum))
                    {
                        instAddr =
                            CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, instNum);

                        retVal = BoardAm43xxGpevmGpioCfg(pinNum, instNum,
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

    return retVal;
}


int32_t BoardAm43xxGpevmLcdDevicePowerOn(uint32_t devId,
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
        case DEVICE_ID_LCD_OSD070T1718_19TS:
        {
            switch(devInstNum)
            {
                case 0U:
                {
                    /* GPIO Pin: GPIO_0_7 */
                    pinNum  = BOARD_AM43xx_GPEVM_LCD_BACK_LIGHT_PIN;
                    instNum = BOARD_AM43xx_GPEVM_LCD_DEVICE_BACK_LIGHT_PIN_INST;
                    if(TRUE ==
                        CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, instNum))
                    {
                        instAddr =
                            CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, instNum);

                        retVal = BoardAm43xxGpevmGpioCfg(pinNum, instNum,
                            instAddr, GPIO_DIRECTION_OUTPUT);

                        if(S_PASS == retVal)
                        {
                            GPIOPinWrite(instAddr, pinNum, GPIO_PIN_LOW);
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

    return retVal;
}

int32_t BoardAm43xxGpevmGpioCfg(uint32_t pinNum,
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
