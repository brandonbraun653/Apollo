/**
 *  \file     display_utils.h
 *
 *  \brief    This file contains the prototypes of the display utility APIs.
 *            This file also contains the display utility macros and structure
 *            definitions.
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

#ifndef  DISPLAY_UTILS_H_
#define  DISPLAY_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "display_utils_ip.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the display resolution parameters.*/
typedef struct displayUtilsRes
{
    uint32_t width;
    /**< Width of the LCD display in number of pixels. */
    uint32_t height;
    /**< Number of lines present in the LCD display. */
}displayUtilsRes_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API performs the initialization of the display utilities.
 *
 * \details This performs the clock and pin mux configuration of corresponding
 *          IP. This will fetch the necessary board and SoC data and will
 *          configure the interrupt controller. This API also fetches the
 *          parameters of the LCD that is connected to the board.
 *
 * \retval  S_PASS    Display utilities initialization is successful.
 * \retval  E_FAIL    Display utilities initialization is failed.
 *
 * \note    Please find the below notes:
 *          -# The following configurations should have done before calling this
 *             API:
 *             -# Console utils initialization.
 *             -# Board initialization.
 *          -# With out performing above initialization, this API will not
 *             function properly.
 */
int32_t DISPLAYUtilsInit(void);

/**
 * \brief   This API configures the display utilities to display the image as
 *          per the parameters passed by the user.
 *
 * \details This performs the IP configuration and necessary IP interrupt
 *          configurations. This will also initialize the frame buffer handling.
 *
 * \param   frmBufAddr       Starting address of the buffer containing the input
 *                           image data.
 * \param   frmBufSize       Size of the input frame buffer in bytes.
 * \param   inputFrmWidth    Width of the input image in number of pixels.
 * \param   inputFrmHeight   Number of lines in the input image.
 * \param   inputFrmFormat   Pixel format of the input image. This can take
 *                           values from the following enum
 *                           displayUtilsInputFmt_t.
 * \param   pFnIsrCb         Pointer to the ISR call back function, which gets
 *                           address of the next buffer that has to be displayed
 *
 * \retval S_PASS    Display utilities configuration is successful.
 * \retval E_FAIL    Display utilities configuration is failed.
 *
 * \note   Display utilities configuration may fail due to one of following
 *         reasons:
 *         -# Input width and/or height are not supported by the LCD.
 *         -# Input pixel format is not supported.
 *         -# Input buffer pointer is NULL.
 */
int32_t DISPLAYUtilsConfig(uint32_t frmBufAddr,
                           uint32_t frmBufSize,
                           uint32_t inputFrmWidth,
                           uint32_t inputFrmHeight,
                           uint32_t inputFrmFormat,
                           DISPLAYUtilsIsrCallbackFxn pFnIsrCb);

/**
 * \brief  This API starts the display. LCD will start displaying the content
 *         only after calling this API.
 *
 * \note   Display utilities configuration should have called prior to calling
 *         this API. The following APIs should have called before this API
 *         -# #DISPLAYUtilsInit.
 *         -# #DISPLAYUtilsConfig.
 */
void DISPLAYUtilsStartDisplay(void);

/**
 * \brief  This API stops the display. Nothing will be displayed on the LCD
 *         after calling this API.
 *
 * \note   Display utilities configuration should have called prior to calling
 *         this API. The following APIs should have called before this API
 *         -# #DISPLAYUtilsInit.
 *         -# #DISPLAYUtilsConfig.
 */
void DISPLAYUtilsStopDisplay(void);

/**
 * \brief  This API gets the resolution of the LCD panel that is connected on
 *         the board.
 *
 * \retval dispResolution Structure of type #displayUtilsRes_t containing the
 *                        display resolution of the LCD that is connected on the
 *                        board. This will contain width(number of pixels) and
 *                        height(number of lines) information of the LCD.
 *
 * \note   Display utilities should have been initialized before calling this
 *         API. The following API should be called before calling this API
 *         - DISPLAYUtilsInit.
 *
 */
displayUtilsRes_t DISPLAYUtilsGetDisplayResolution(void);


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DISPLAY_UTILS_H_ */
