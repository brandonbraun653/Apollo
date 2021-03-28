/**
 * \file   board_am43xx_idkevm.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM43xx based IDKEVM board.
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
#include "am43xx_pinmux.h"


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

/* None */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Information for all devices on the board is provided in this array */
const boardDeviceData_t gBoardAm43xxIdkevmDevData[] =
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
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_I2C)
    { /* EEPROM */
        DEVICE_ID_I2C_LED,                  /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_I2C,                  /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        BOARD_LED_I2C_ADDR_2,            	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* VTT */
        DEVICE_ID_VTT,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        22, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        24, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        25, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        2U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        22, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        3U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        2U,                                 /* ctrlModInstNum */
        23, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        4U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        4U,                                 /* ctrlModInstNum */
        13, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* TRICOLOR LED */
        DEVICE_ID_LED,                      /* devId */
        5U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        4U,                                 /* ctrlModInstNum */
        16, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_GPIO)
 { /* PHY RESET GPIO */
        DEVICE_ID_RESET_PHY,                      /* devId */
        6U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        4U,                                 /* ctrlModInstNum */
        20, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
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
#if defined(BUILDCFG_MOD_PRU_ETH)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_MII,            	/* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_ICSS_MDIO,          	/* ctrlModId */
        1U, /* PRUSS Instace*/              /* ctrlModInstNum */
        0U, /* PRU port number */           /* ctrlInfo */
        0U, /* PHY device address */        /* dataModId */
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
        1U, /* PRUSS Instace*/              /* ctrlModInstNum */
        1U, /* PRU port number */           /* ctrlInfo */
        1U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_PRU_ETH) */
#if defined(BUILDCFG_MOD_QSPI)
    { /* QSPI Flash device */
        DEVICE_ID_FLASH_MX66L51235F,        /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_QSPI,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        0U, /* Chip Select number */        /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_QSPI) */
#if defined(BUILDCFG_MOD_MCSPI)
    { /* W25Q64BV SPI Flash */
        DEVICE_ID_HVS882,                 	/* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_MCSPI,                /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        0U, /* Chip Select */           	/* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* selectDev */
        NULL,                               /* resetDev */
        NULL                                /* powerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_MCSPI) */
#if defined(BUILDCFG_MOD_MCSPI)
    { /* GPIO for HVS882 */
        DEVICE_ID_HVS882,                      /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        3U,                                 /* ctrlModInstNum */
        1, /* GPIO pin number */           /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    }
#endif /* if defined(BUILDCFG_MOD_MCSPI) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm43xxIdkevmRevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "1.0A"       /* EVM TBD version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t gBoardAm43xxIdkevmData =
{
    (sizeof (gBoardAm43xxIdkevmDevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm43xxIdkevmDevData,
    /* pDevData */
    gIdkevmPinmuxData,
    /* pPinmuxData */
    (BOARD_REV_IDKEVM_MAX + 1),
    /* numRevStrings */
    gpBoardAm43xxIdkevmRevStrTable,
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

/* None */
