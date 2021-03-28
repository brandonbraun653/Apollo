/**
 * \file   lcd_device.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         LCD devices and global structure containing the LCD panel parameters.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Structure holding the supported LCD device ids. */
uint32_t gLcdDeviceIdList[] =
{
    DEVICE_ID_LCD_OSD070T1718_19TS,
    /**< LCD device. */
    DEVICE_ID_LCD_S9700RTWV43_01B,
    /**< LCD device. */
    DEVICE_ID_DCARD_LCD4_DISPLAY,
    /**< Daughter card LCD device. */
    DEVICE_ID_INVALID
    /**< Invalid device ID. */
};

/** \brief Structure holding the panel parameters of different LCDs. */
lcdDeviceData_t gLcdDeviceData[] =
{
    {
        /* Data for LCD OSD070T1718_19TS */
        DEVICE_ID_LCD_OSD070T1718_19TS, /* devId */
        38000000U,                   /* pixelClk */
        800U,                        /* pixelsPerLine */
        240U,                       /* horzFrontPorch */
        15U,            /* horzBackPorch */
        30U,            /* horzSyncWidth */
        480U,           /* linesPerPanel */
        32U,            /* vertFrontPorch */
        10U,            /* vertBackPorch */
        13U,            /* vertSyncWidth */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* hSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* vSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_HIGH,  /* outputEnablePolarity */
        LCD_ACTIVE_EDGE_RISING,        /* pixelClkPolarity */
        LCD_ACTIVE_EDGE_FALLING,       /* activeSyncEdge */
        LCD_SYNC_EDGE_CTRL_SAME_EDGE,  /* syncEdgeControl */
    },
    {
        /* Data for LCD S9700RTWV43_01B */
        DEVICE_ID_LCD_S9700RTWV43_01B, /* devId */
        23040000U,                     /* pixelClk */
        800U,                          /* pixelsPerLine */
        40U,                          /* horzFrontPorch */
        40U,            /* horzBackPorch */
        48U,            /* horzSyncWidth */
        480U,           /* linesPerPanel */
        13U,            /* vertFrontPorch */
        29U,            /* vertBackPorch */
        3U,            /* vertSyncWidth */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* hSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* vSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_HIGH,  /* outputEnablePolarity */
        LCD_ACTIVE_EDGE_RISING,        /* pixelClkPolarity */
        LCD_ACTIVE_EDGE_RISING,        /* activeSyncEdge */
        LCD_SYNC_EDGE_CTRL_OPPOSITE_EDGES,  /* syncEdgeControl */
    },
    {
        /* Data for LCD4 daughter card display */
        DEVICE_ID_DCARD_LCD4_DISPLAY, /* devId */
        9000000U,                   /* pixelClk */
        480U,                        /* pixelsPerLine */
        8U,                       /* horzFrontPorch */
        43U,            /* horzBackPorch */
        4U,            /* horzSyncWidth */
        272U,           /* linesPerPanel */
        4U,            /* vertFrontPorch */
        12U,            /* vertBackPorch */
        10U,            /* vertSyncWidth */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* hSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_LOW,   /* vSyncPolarity */
        LCD_SIG_POLARITY_ACTIVE_HIGH,  /* outputEnablePolarity */
        LCD_ACTIVE_EDGE_RISING,        /* pixelClkPolarity */
        LCD_ACTIVE_EDGE_RISING,       /* activeSyncEdge */
        LCD_SYNC_EDGE_CTRL_OPPOSITE_EDGES,  /* syncEdgeControl */
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

lcdDeviceData_t *LCDGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gLcdDeviceData) / sizeof(lcdDeviceData_t);
    uint32_t devIndex = 0U;
    lcdDeviceData_t *lcdDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gLcdDeviceData[devIndex].devId)
        {
            /* Device Found */
            lcdDeviceData = &gLcdDeviceData[devIndex];
            break;
        }
    }
    return lcdDeviceData;
}

uint32_t * LCDGetDeviceIdList(void)
{
    return gLcdDeviceIdList;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */
