/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file   evmk2g_hdmi.h
 *
 * \brief  This is the header file for hdmi
 ******************************************************************************/

#ifndef _EVMK2G_HDMI_H_
#define _EVMK2G_HDMI_H_

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Macros for I2C slave address and instance */
#define HDMI_SLAVE_ADDR					(0x3B)
#define HDMI_I2C_INSTANCE				(1)

/** Macros definitons for return types */
#define HDMI_ERR					(-1)
#define HDMI_SUCCESS				(0)

/** Macros to unmute/mute HDMI audio */
#define HDMI_AUDIO_MUTE				(1)
#define HDMI_AUDIO_UNMUTE			(0)

/** Macros for HDMI GPIO pin */
#define HDMI_ENABLE_GPIO_INSTANCE	(0)
#define HDMI_ENABLE_GPIO_PIN		(84)
#define HDMI_INT_GPIO_INSTANCE		(1)
#define HDMI_INT_GPIO_PIN			(31)

/** Macro for maximum number of bytes to read edid */
#define HDMI_EDID_MAX_LEN				(256)

/** Registers for HDMI controller */
#define HDMI_REG_CHIPID0				(0x1B)
#define HDMI_REG_TPI_RQB				(0xC7)

#define VERTICAL_FREQ					(0x3C)

/** HDMI TPI Registers  */
#define HDMI_TPI_VIDEO_DATA_BASE_REG		(0x00)
#define HDMI_TPI_PIXEL_CLK_LSB_REG			(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x00)
#define HDMI_TPI_PIXEL_CLK_MSB_REG			(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x01)
#define HDMI_TPI_VFREQ_LSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x02)
#define HDMI_TPI_VFREQ_MSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x03)
#define HDMI_TPI_PIXELS_LSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x04)
#define HDMI_TPI_PIXELS_MSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x05)
#define HDMI_TPI_LINES_LSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x06)
#define HDMI_TPI_LINES_MSB_REG				(HDMI_TPI_VIDEO_DATA_BASE_REG + 0x07)

#define HDMI_TPI_PIXEL_REPETITION_REG		(0x08)

#define HDMI_TPI_AVI_INOUT_BASE_REG			(0x09)
#define HDMI_TPI_AVI_IN_FORMAT_REG			(HDMI_TPI_AVI_INOUT_BASE_REG + 0x00)
#define HDMI_TPI_AVI_OUT_FORMAT_REG			(HDMI_TPI_AVI_INOUT_BASE_REG + 0x01)

#define HDMI_SYS_CTRL_DATA_REG				(0x1A)
#define HDMI_TPI_POWER_STATE_CTRL_REG		(0x1E)

#define HDMI_REG_1F					(0x1F)
#define HDMI_REG_20					(0x20)
#define HDMI_REG_21					(0x21)
#define HDMI_REG_22					(0x22)
#define HDMI_REG_23					(0x23)
#define HDMI_REG_24					(0x24)
#define HDMI_REG_25					(0x25)
#define HDMI_REG_26					(0x26)
#define HDMI_REG_27					(0x27)
#define HDMI_REG_BC					(0xBC)
#define HDMI_REG_BD					(0xBD)
#define HDMI_REG_BE					(0xBE)

/** Macros for HDCP */
#define HDMI_TPI_HDCP_QUERYDATA_REG			(0x29)
#define HDMI_TPI_HDCP_CONTROLDATA_REG		(0x2A)

/** Macros for HDMI_TPI_AVI_OUTPUT_FORMAT  */
#define TPI_AVI_OUTPUT_CONV_BT709			(1 << 4)
#define TPI_AVI_OUTPUT_CONV_BT601			(0 << 4)
#define TPI_AVI_OUTPUT_RANGE_LIMITED		(2 << 2)
#define TPI_AVI_OUTPUT_RANGE_FULL			(1 << 2)
#define TPI_AVI_OUTPUT_RANGE_AUTO			(0 << 2)
#define TPI_AVI_OUTPUT_COLORSPACE_RGBDVI	(3 << 0)
#define TPI_AVI_OUTPUT_COLORSPACE_YUV422	(2 << 0)
#define TPI_AVI_OUTPUT_COLORSPACE_YUV444	(1 << 0)
#define TPI_AVI_OUTPUT_COLORSPACE_RGBHDMI	(0 << 0)

/** Macros for HDMI_SYS_CTRL_DATA_REG  */
#define TPI_SYS_CTRL_POWER_DOWN				(1 << 4)
#define TPI_SYS_CTRL_POWER_ACTIVE			(0 << 4)
#define TPI_SYS_CTRL_AV_MUTE				(1 << 3)
#define TPI_SYS_CTRL_DDC_BUS_REQUEST		(1 << 2)
#define TPI_SYS_CTRL_DDC_BUS_GRANTED		(1 << 1)
#define TPI_SYS_CTRL_OUTPUT_MODE_HDMI		(1 << 0)
#define TPI_SYS_CTRL_OUTPUT_MODE_DVI		(0 << 0)

/** Macros for ratio of TDMS Clock to input Video Clock */
#define TPI_CLK_RATIO_HALF				(0 << 6)
#define TPI_CLK_RATIO_1X				(1 << 6)
#define TPI_CLK_RATIO_2X				(2 << 6)
#define TPI_CLK_RATIO_4X				(3 << 6)

/** Macros for HDMI_TPI_DEVICE_POWER_STATE */
#define TPI_AVI_POWER_STATE_D3				(3 << 0)
#define TPI_AVI_POWER_STATE_D2				(2 << 0)
#define TPI_AVI_POWER_STATE_D0				(0 << 0)

/** Macros for HDMI_TPI_PIXEL_REPETITION */
#define TPI_AVI_PIXEL_REP_BUS_24BIT			(1 << 5)
#define TPI_AVI_PIXEL_REP_BUS_12BIT			(0 << 5)
#define TPI_AVI_PIXEL_REP_RISING_EDGE		(1 << 4)
#define TPI_AVI_PIXEL_REP_FALLING_EDGE		(0 << 4)
#define TPI_AVI_PIXEL_REP_4X				(3 << 0)
#define TPI_AVI_PIXEL_REP_2X				(1 << 0)
#define TPI_AVI_PIXEL_REP_NONE				(0 << 0)

/** Macros for HDMI_TPI_AVI_INPUT_FORMAT */
#define TPI_AVI_INPUT_BITMODE_12BIT			(1 << 7)
#define TPI_AVI_INPUT_BITMODE_8BIT			(0 << 7)
#define TPI_AVI_INPUT_DITHER				(1 << 6)
#define TPI_AVI_INPUT_RANGE_LIMITED			(2 << 2)
#define TPI_AVI_INPUT_RANGE_FULL			(1 << 2)
#define TPI_AVI_INPUT_RANGE_AUTO			(0 << 2)
#define TPI_AVI_INPUT_COLORSPACE_BLACK		(3 << 0)
#define TPI_AVI_INPUT_COLORSPACE_YUV422		(2 << 0)
#define TPI_AVI_INPUT_COLORSPACE_YUV444		(1 << 0)
#define TPI_AVI_INPUT_COLORSPACE_RGB		(0 << 0)

/** Macors for Stream Header Data */
#define HDMI_SH_PCM					    (0x1 << 4)
#define HDMI_SH_TWO_CHANNELS			(0x1 << 0)
#define HDMI_SH_44KHz					(0x2 << 2)
#define HDMI_SH_48KHz					(0x3 << 2)
#define HDMI_SH_16BIT					(0x1 << 0)
#define HDMI_SH_24BIT					(0x3 << 0)
#define HDMI_SH_SPKR_FLFR				(0x0)
#define HDMI_SH_0dB_ATUN				(0x0)


/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 *
 * \brief   Initializes the HDMI controller.
 *
 * \param   NULL.
 *
 * \return  NONE.
 *
 */
int8_t hdmiInit(void);

/**
 *
 * \brief    This function is used to set all the registers to enable
 *           the HDMI transmitter.
 *
 * \param    NULL.
 *
 * \return  HDMI_SUCCESS	- On Success.
 *          HDMI_ERR		- On Failure.
 *
 */
int8_t hdmiHwEnable(void);

/**
 * \brief    Enables the power state of HDMI controller.
 *
 * \return  HDMI_SUCCESS	-      On Success
 *          HDMI_ERR		-      On Failure
 *
 */
int8_t hdmiConnect(void);

/**
 * \brief    Reads the HDMI edid information.
 *
 * \param    data	 [IN] Pointer to the data buffer
 * \param    dataLen [IN] Length of edid data to be read.
 *
 * \return   HDMI_SUCCESS	- On Success
 *           HDMI_ERR		- On Failure
 *
 */
int8_t hdmiReadEdid(uint8_t *data, uint32_t dataLen);

/**
 *
 * \brief    This function is used to check the HDMI chip version.
 *
 * \param    chipVer : Pointer to the buffer passed from test app.
 *
 * \return   HDMI_SUCCESS	- On Success.
 *           HDMI_ERR		- On Failure.
 *
 */
int8_t hdmiProbeChipVersion(uint8_t *chipVer);

/**
 *
 * \brief    Configures HDMI audio
 *
 * \param    NULL.
 *
 * \return   HDMI_SUCCESS	- On Success
 *           HDMI_ERR		- On Failure
 *
 */
int8_t hdmiAudioConfigure(void);

#endif /* _EVMK2G_HDMI_H_ */
