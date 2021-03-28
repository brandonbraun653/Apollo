/**
 * \file   board_am335x_evmsk.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based EVMSK board.
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
#include "am335x_pinmux.h"

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
/* TBD: Check for accuracy */
const boardDeviceData_t gBoardAm335xEvmskDevData[] =
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
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RGMII,           /* devId */
        1U,                                 /* devInstNum */
        CHIPDB_MOD_ID_CPSW,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        2U, /* CPSW port number */          /* ctrlInfo */
        1U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_CPSW) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* VTT */
        DEVICE_ID_VTT,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        7, /* GPIO pin number */            /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
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
    }
#endif /* if defined(BUILDCFG_MOD_I2C) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm335xEvmskRevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "1.2B",      /* EVM 1.2B version board */
    "1.3A"       /* EVM 1.3A version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t gBoardAm335xEvmskData =
{
    (sizeof (gBoardAm335xEvmskDevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm335xEvmskDevData,
    /* pDevData */
    gEvmskPinmuxData,
    /* pPinmuxData */
    (BOARD_REV_EVMSK_MAX + 1),
    /* numRevStrings */
    gpBoardAm335xEvmskRevStrTable,
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
