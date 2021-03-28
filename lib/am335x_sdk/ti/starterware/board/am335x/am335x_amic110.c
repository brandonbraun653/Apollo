/**
 * \file   am335x_amic110.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based AMIC110 board.
 *
 * \copyright Copyright (C) 2017 Texas Instruments Incorporated -
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
#include "am335x_pinmux.h"
#include "am335x_amic110.h"
#include "gpio.h"
#include "delay_utils.h"
#include "prcm.h"
#include "console_utils.h"

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
 * \brief   This API configures the Phy Reset, Phy Mux select and Other Phy
 *          related configurations.
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 *
 * \status  S_PASS      PHY is successfully reset
 * \status  E_FAIL      Failed to reset
 */
int32_t BoardAm335xAMIC110PhySetupAndReset(uint32_t devId, uint32_t devInstNum);



/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Variable for Phy Reset status intended for reset to happen only once */
static int32_t gBoardAm335xAMIC110PhyResetStatus;

/** \brief Information for all devices on the board is provided in this array */
const boardDeviceData_t gBoardAm335xAMIC110DevData[] =
{
#ifndef DDRLESS
#if defined(BUILDCFG_MOD_UART)
    { /* CONSOLE */
        DEVICE_ID_CONSOLE,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_UART,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        73U, /* Interrupt Number */         /* ctrlInfo */
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
#if defined(BUILDCFG_MOD_I2C)
    { /* EEPROM */
        DEVICE_ID_I2C_LED,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        BOARD_LED_I2C_ADDR_2,            	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_I2C)
    { /* EEPROM */
        DEVICE_ID_I2C_OLED,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        BOARD_OLED_I2C_ADDR_0,            	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_I2C)
    { /* Rotary Switch */
	DEVICE_ID_I2C_ROTARY_SW,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
		BOARD_ROTARY_SW_ADDR_0,            	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_PRUSS)
    { /* PRUSS */
        DEVICE_ID_PRUSS,            		/* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_PRU_ICSS_FW,          /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* Resvd */           			/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID, 		        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_PRU_ETH) */
#if defined(BUILDCFG_MOD_CPSW)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RMII,            /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_CPSW,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        1U, /* CPSW port number */          /* ctrlInfo */
        1U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        BoardAm335xAMIC110PhySetupAndReset,   /* pFnResetDev */
        NULL,                               /* pFnPowerOnDev */
    },
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RMII,            /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_CPSW,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        2U, /* CPSW port number */          /* ctrlInfo */
        3U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        BoardAm335xAMIC110PhySetupAndReset,   /* pFnResetDev */
        NULL,                               /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_CPSW) */

#if defined(BUILDCFG_MOD_PRU_ETH)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_MII,            	/* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_ICSS_MDIO,          	/* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* PRU port number */           /* ctrlInfo */
        1U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_PRU_ETH) */
#if defined(BUILDCFG_MOD_PRU_ETH)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_MII,            	/* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_ICSS_MDIO,          	/* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        1U, /* PRU port number */           /* ctrlInfo */
        3U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_PRU_ETH) */

#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        17, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        16, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        2U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        9, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        3U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        30, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        4U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        20, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        5U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        19, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* PHY RESET GPIO */
        DEVICE_ID_RESET_PHY,                      /* devId */
        6U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        5, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* PHY RESET GPIO */
        DEVICE_ID_MII_MUX,                  /* devId */
        7U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        10, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* PHY RESET GPIO */
        DEVICE_ID_MII_MUX,                  /* devId */
        8U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        4, /* GPIO pin number */           	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
    { /* PHY RESET GPIO */
        DEVICE_ID_MII_MUX,                  /* devId */
        9U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        7, /* GPIO pin number */           	/* ctrlInfo */
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
        0U,                                 /* ctrlModInstNum */
        18, /* GPIO pin number */            /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },

#endif /* if defined(BUILDCFG_MOD_GPIO) */
#endif
#if defined(BUILDCFG_MOD_MCSPI)
   { /* M29W160EB SPI Flash */
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
   { /* W25Q64BV SPI Flash */
        DEVICE_ID_HVS882,                 	/* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_MCSPI,                /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        1U, /* Channel */		           	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
   },
   { /* GPIO for HVS882 */
        DEVICE_ID_HVS882,                      /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        18, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    }
#endif /* if defined(BUILDCFG_MOD_MCSPI) */
};

#ifndef DDRLESS
/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm335xAMIC110RevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "00A1",      /* EVM A1 version board */
    "00A2",      /* EVM A2 version board */
    "00A3",      /* EVM A3 version board */
    "00A5",      /* EVM A5 version board */
    "00A6"       /* EVM A6 version board */
};
#endif

/** \brief This object contains details of all devices on the board. */
const boardData_t   gBoardAm335xAMIC110Data =
{
    (sizeof (gBoardAm335xAMIC110DevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm335xAMIC110DevData,
    /* pDevData */
    gAMIC11xPinmuxData,
    /* pinmux data */
    (BOARD_REV_ICEV2_MAX + 1),
    /* numRevStrings */
#ifndef DDRLESS
    gpBoardAm335xAMIC110RevStrTable,
#else
	NULL,
#endif
    /* pRevStringTable */
    NULL,
    /* pDCards */
    NULL,
    /* pFnBoardInit */
    NULL
    /* pFnBoardLcdDevData */
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t BoardAm335xAMIC110PhySetupAndReset(uint32_t devId, uint32_t devInstNum)
{

    uint32_t status = E_FAIL;
    volatile uint32_t gpio0BaseAddress;
    volatile uint32_t gpio2BaseAddress;
    volatile uint32_t gpio3BaseAddress;

    if (gBoardAm335xAMIC110PhyResetStatus == 0)
    {
        gpio0BaseAddress = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, 0);
        gpio2BaseAddress = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, 2);
        gpio3BaseAddress = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, 3);

        /* Clock Configuration */
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO,0, 0);
        status &= PRCMModuleEnable(CHIPDB_MOD_ID_GPIO,2, 0);
        status &= PRCMModuleEnable(CHIPDB_MOD_ID_GPIO,3, 0);
        if(S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n PRCM for GPIO failed to setup Phy\n");
        }

        if(S_PASS == status)
        {
            /* PinMux Configuration */
            status  = PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, 0, NULL);
            status &= PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, 2, NULL);
            status &= PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, 3, NULL);
           if(S_PASS != status)
           {
               CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
           }
        }

        /* Enable GPIO modules */
        GPIOModuleEnable(gpio0BaseAddress, TRUE);
        GPIOModuleEnable(gpio2BaseAddress, TRUE);
        GPIOModuleEnable(gpio3BaseAddress, TRUE);

        /* Set Direction */
        GPIODirModeSet(gpio0BaseAddress,7,GPIO_DIRECTION_OUTPUT);
        GPIODirModeSet(gpio0BaseAddress,18,GPIO_DIRECTION_OUTPUT);
        GPIODirModeSet(gpio2BaseAddress,5,GPIO_DIRECTION_OUTPUT);
        GPIODirModeSet(gpio3BaseAddress,4,GPIO_DIRECTION_OUTPUT);
        GPIODirModeSet(gpio3BaseAddress,10,GPIO_DIRECTION_OUTPUT);

        /* PR1_MII_CTL */
        GPIOPinWrite(gpio3BaseAddress, 4, 1);

        /* MUX MII CONTROL */
        GPIOPinWrite(gpio3BaseAddress, 10, 1);

        /* FET SWITCH CONTROL */
        GPIOPinWrite(gpio0BaseAddress, 7, 1);

        /* DDR VTT ENABLE */
        GPIOPinWrite(gpio0BaseAddress, 18, 1);

        /* Phy 0 & 1 reset */
        GPIOPinWrite( gpio2BaseAddress, 5, 0);
        delay(1);
        GPIOPinWrite(gpio2BaseAddress, 5, 1);
        delay(1);

        gBoardAm335xAMIC110PhyResetStatus ++;
    }
    else
    {
        status = S_PASS;
    }

    return(status);
}
