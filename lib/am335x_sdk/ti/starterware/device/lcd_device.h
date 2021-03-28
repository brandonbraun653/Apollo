/**
 *  \file  lcd_device.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the dss.
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

#ifndef LCD_DEVICE_H_
#define LCD_DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the polarity of the lcd signals. */
typedef enum lcdSigPolarity
{
    LCD_SIG_POLARITY_ACTIVE_LOW  = 0U,
    /**< Signal polarity is active low. */
    LCD_SIG_POLARITY_ACTIVE_HIGH = 1U,
    /**< Signal polarity is active high. */
}lcdSigPolarity_t;


/** \brief Enumerates the active edges of synchronization signals. */
typedef enum lcdActiveEdge
{
    LCD_ACTIVE_EDGE_RISING  = 0U,
    LCD_ACTIVE_EDGE_FALLING = 1U,
}lcdActiveEdge_t;


/** \brief Enumerates the control of synchronization signal by pixel clock. */
typedef enum lcdSyncEdgeCtrl
{
    LCD_SYNC_EDGE_CTRL_SAME_EDGE     = 0U,
    /**< HSYNC and VSYNC are driven on same edge as per active sync edge
         configuration. */
    LCD_SYNC_EDGE_CTRL_OPPOSITE_EDGES = 1U,
    /**< HSYNC and VSYNC are driven on opposite edges of pixel clock
         than pixel data. */
}lcdSyncEdgeCtrl_t;


/** \brief Structure holding the LCD panel configuration parameters. */
typedef struct lcdDeviceData
{
    uint32_t devId;
    /**< LCD device ID. */
    uint32_t pixelClk;
    /**< LCD pixel clock. */
    uint32_t pixelsPerLine;
    /**< Number of pixels per line. */
    uint32_t horzFrontPorch;
    /**< Horizontal front porch. */
    uint32_t horzBackPorch;
    /**< Horizontal back porch. */
    uint32_t horzSyncWidth;
    /**< Horizontal sync width. */
    uint32_t linesPerPanel;
    /**< Lines per panel. */
    uint32_t vertFrontPorch;
    /**< Vertical front porch. */
    uint32_t vertBackPorch;
    /**< Vertical back porch. */
    uint32_t vertSyncWidth;
    /**< vertical sync width. */
    lcdSigPolarity_t hSyncPolarity;
    /**< Horizontal synchronization signal polarity. */
    lcdSigPolarity_t vSyncPolarity;
    /**< Vertical synchronization signal polarity. */
    lcdSigPolarity_t outputEnablePolarity;
    /**< Output enable signal polarity. */
    lcdActiveEdge_t pixelClkPolarity;
    /**< Polarity of pixel clock. */
    lcdActiveEdge_t activeSyncEdge;
    /**< Active edge of synchronization signal. */
    lcdSyncEdgeCtrl_t syncEdgeControl;
    /**< Control synchronization signal using pixel clock. */
}lcdDeviceData_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the LCD related data according to the LCD panel that
 *        is connected to the board.
 *
 * \param devId The device id of the device that is connected to DSS.
 *
 * \retval QSPI_Device_Data Pointer to the QSPI device data.
 */
lcdDeviceData_t *LCDGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of LCD devices available.
 *
 * \retval lcd_device_id_list Pointer to the LCD device ID list
 */
uint32_t * LCDGetDeviceIdList(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef LCD_DEVICE_H_ */
