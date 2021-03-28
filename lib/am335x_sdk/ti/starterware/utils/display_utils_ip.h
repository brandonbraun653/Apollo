/**
 *  \file     display_utils_ip.h
 *
 *  \brief    This file contains the prototypes of the display utility APIs.
 *            This file also contains the necessary macro definitions.
 *
 *  \copyright Copyright (C) 2013 - 2018 Texas Instruments Incorporated -
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

#ifndef  DISPLAY_UTILS_IP_H_
#define  DISPLAY_UTILS_IP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief Function pointer typedef for ISR call back function.
 *
 *  \details This function gets the starting address of the image buffer which
 *           has to be displayed next. This will accept the address of the
 *           buffer which is displayed currently as an input parameter.
 */
typedef uint32_t (*DISPLAYUtilsIsrCallbackFxn)(uint32_t currBufAddr);

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the supported pixel format types of display utils. */
typedef enum displayUtilsPixelFmt
{
    DISPLAY_UTILS_PIXEL_FMT_MIN = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    DISPLAY_UTILS_PIXEL_FMT_RGB12 = DISPLAY_UTILS_PIXEL_FMT_MIN,
    /**< Input pixel format is raw RGB12 */
    DISPLAY_UTILS_PIXEL_FMT_RGB16 = 1U,
    /**< Input pixel format is raw RGB16 */
    DISPLAY_UTILS_PIXEL_FMT_RGB24_UNPACKED = 2U,
    /**< Input pixel format is RGB24 unpacked in a 32 bit container. */
    DISPLAY_UTILS_PIXEL_FMT_YUV2 = 3U,
    /**< Input pixel format is YUV2: YUYV */
    DISPLAY_UTILS_PIXEL_FMT_MAX = DISPLAY_UTILS_PIXEL_FMT_YUV2
    /**< Maximum value of enumeration. Used for input validation. */
}displayUtilsInputFmt_t;


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Counter indicating the number of under flow interrupts. */
extern volatile uint32_t gDisplayUtilsUnderflowErrCnt;

/** \brief Counter indicating the number of sync lost interrupts. */
extern volatile uint32_t gDisplayUtilsSyncLostErrCnt;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * \brief   This API performs clock and pin mux configuration of IP. This also
 *          performs the board and SOC related configurations. This will also
 *          performs the interrupt controller configuration and fetches the
 *          LCD device data.
 *
 * \retval  S_PASS      Module initialization is successful.
 * \retval  E_FAIL      Module initialization is failed.
 */
int32_t DISPLAYUtilsModuleInit(void);


/**
 * \brief   This API configures the IP and their sub modules. This will
 *          configure the IP interrupts.
 *
 * \param   bufAddr          Starting address of the buffer containing the input
 *                           image data.
 * \param   bufSize          Size of the input frame buffer in bytes.
 * \param   inputWidth       Width of the input image in number of pixels.
 * \param   inputHeight      Number of lines in the input image.
 * \param   inputPixelFormat Pixel format of the input image. This can take
 *                           values from the following enum
 *                           #displayUtilsInputFmt_t.
 * \param   pFnIsrCb         ISR call back function pointer. This will get the
 *                           address of the next buffer that has to be displayed
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed.
 */
int32_t DISPLAYUtilsIpConfig(uint32_t bufAddr,
                             uint32_t bufSize,
                             uint32_t inputWidth,
                             uint32_t inputHeight,
                             uint32_t inputPixelFormat,
                             DISPLAYUtilsIsrCallbackFxn pFnIsrCb);


/**
 * \brief   This API enables the LCD output so that the image will be displayed
 *          on the LCD.
 */
void DISPLAYUtilsIpDisplayEnable(void);


/**
 * \brief   This API disables the LCD output so that LCD will stop displaying
 *          the image.
 */
void DISPLAYUtilsIpDisplayDisable(void);


/**
 * \brief   This API gets the display resolution of the LCD that is connected
 *          on the board.
 *
 * \param   pWidth   Pointer to the variable which contains width information.
 * \param   pHeight  Pointer to the variable which contains height information.
 */
void DISPLAYUtilsIpGetDisplayResolution(uint32_t *pWidth, uint32_t *pHeight);
/* ========================================================================== */
/*                      Internal Function Definitions                         */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DISPLAY_UTILS_IP_H_ */
