/**
 * \file   am335x_ICEv1.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based ICEv1 board.
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
#include "am335x_icev1.h"

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
const boardDeviceData_t gBoardAm335xIceV1DevData[] =
{
#if defined(BUILDCFG_MOD_UART)
    { /* CONSOLE */
        DEVICE_ID_CONSOLE,                   /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_UART,                  /* ctrlModId */
        5U,                                 /* ctrlModInstNum */
        46U, /* Interrupt Number */         /* ctrlInfo */
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
#if defined(BUILDCFG_MOD_PRU_ETH)
    { /* Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RMII,            /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_PRU_ICSS_FW,          /* ctrlModId */
        1U,                                 /* ctrlModInstNum */
        1U, /* PRU port number */           /* ctrlInfo */
        2U, /* PHY device address */        /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_PRU_ETH) */
#if defined(BUILDCFG_MOD_GPIO)
    { /* LED */
        DEVICE_ID_LED,                      /* devId */
        0U,                                 /* devInstNum */
        CHIPDB_MOD_ID_GPIO,                 /* ctrlModId */
        0U,                                 /* ctrlModInstNum */
        17U, /* GPIO pin number */          /* ctrlInfo */
        CHIPDB_MOD_ID_INVALID,              /* dataModId */
        INVALID_INST_NUM,                   /* dataModInstNum */
        NULL,                               /* pFnSelectDev */
        NULL,                               /* pFnResetDev */
        NULL                                /* pFnPowerOnDev */
    },
#endif /* if defined(BUILDCFG_MOD_GPIO) */
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
   }
#endif /* if defined(BUILDCFG_MOD_MCSPI) */
};

/** \brief Strings configured for board revision information in the EEPROM. */
const char * gpBoardAm335xIceV1RevStrTable[] =
{
    "UNKNOWN",   /* Corresponds to UNKNOWN board. */
    "00A1",      /* EVM A1 version board */
    "00A2",      /* EVM A2 version board */
    "00A3",      /* EVM A3 version board */
    "00A5",      /* EVM A5 version board */
    "00A6"       /* EVM A6 version board */
};

/** \brief This object contains details of all devices on the board. */
const boardData_t   gBoardAm335xIceV1Data =
{
    (sizeof (gBoardAm335xIceV1DevData) / sizeof (boardDeviceData_t)),
    /* numDev */
    gBoardAm335xIceV1DevData,
    /* pDevData */
    gIceV1PinmuxData,
    /* pinmux data */
    (BOARD_REV_ICEV1_MAX + 1),
    /* numRevStrings */
    gpBoardAm335xIceV1RevStrTable,
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
