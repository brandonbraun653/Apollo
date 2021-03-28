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
 * \file   evmk2g_touch.h
 *
 * \brief  This is the header file for touch controller
 *
 ******************************************************************************/

#ifndef _EVMK2G_TOUCH_H_
#define _EVMK2G_TOUCH_H_

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Macros for return types */
#define TOUCH_ERR               (-1)
#define TOUCH_SUCCESS           (0)

/** Macros for I2C slave address and instance */
#define TOUCH_SLAVE_ADDR        (0x38)
#define TOUCH_I2C_INSTANCE      (1)

/** Macros for TOUCH instance and GPIO pin number */
#define TOUCH_GPIO_INSTANCE     (1)
#define TOUCH_GPIO_PIN_NUM      (42)

/** Macro to define total number of touch registers */
#define TOUCH_REGISTERS_NUM     (32)

/** Registers for touch controller */
#define DEVICE_MODE             (0x00)  // device mode
#define GEST_ID                 (0x01)  // gesture id
#define TD_STATUS               (0x02)  // touch points

#define TOUCH1_XH               (0x03)
#define TOUCH1_XL               (0x04)
#define TOUCH1_YH               (0x05)
#define TOUCH1_YL               (0x06)

#define TOUCH2_XH               (0x09)
#define TOUCH2_XL               (0x0a)
#define TOUCH2_YH               (0x0b)
#define TOUCH2_YL               (0x0c)

#define TOUCH3_XH               (0x0f)
#define TOUCH3_XL               (0x10)
#define TOUCH3_YH               (0x11)
#define TOUCH3_YL               (0x12)

#define TOUCH4_XH               (0x15)
#define TOUCH4_XL               (0x16)
#define TOUCH4_YH               (0x17)
#define TOUCH4_YL               (0x18)

#define TOUCH5_XH               (0x1b)
#define TOUCH5_XL               (0x1c)
#define TOUCH5_YH               (0x1d)
#define TOUCH5_YL               (0x1e)

#define ID_G_THGROUP            (0x80)    // valid touching detect threshold
#define ID_G_THPEAK             (0x81)    // valid touching peak detect threshold
#define ID_G_THCAL              (0x82)    // the threshold when calculating the focus of touching
#define ID_G_THWATER            (0x83)    // the threshold when there is surface water
#define ID_G_TEMP               (0x84)    // the threshold of temperature compensation
#define ID_G_THDIFF             (0x85)    // the threshold whether the coordinate is different from original
#define ID_G_CTRL               (0x86)    //
#define ID_G_TIME_ENTER_MONITOR (0x87)    // the timer for entering monitor status
#define ID_G_PERIODACTIVE       (0x88)    //
#define ID_G_PERIODMONITOR      (0x89)    // the timer of entering idle when in monitor status
#define ID_G_AUTO_CLB_MODE      (0xa0)    // auto calibration mode
#define ID_G_LIB_VERSION_H      (0xa1)    // Firmware Library Version H byte
#define ID_G_LIB_VERSION_L      (0xa2)    // Firmware Library Version L byte
#define ID_G_CIPHER             (0xa3)    // Chip vendor ID
#define ID_G_MODE               (0xa4)    // the interrupt status to host
#define ID_G_PMODE              (0xa5)    // Power Consume Mode
#define ID_G_FIRMID             (0xa6)    // Firmware ID
#define ID_G_STATE              (0xa7)    // Running State
#define ID_G_FT5201ID           (0xa8)    // CTPM Vendor ID
#define ID_G_ERR                (0xa9)    // Error Code

#define NORMAL_OPMODE           (0x00)
#define SYSINFO_MODE            (0x10)
#define TEST_MODE               (0x40)

#define DELAY                   (1000000) /* 1 sec */

#define DIMENSIONS				2


/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 *
 * \brief     Function to read the status of TOUCH GPIO.
 *
 * \return    0 : if GPIO pin is HIGH.
 *            1 : if GPIO pin is LOW.
 *
 */
uint8_t touchGpioPinRead(void);

/**
 *
 * \brief     Function to write the data into touch controller register.
 *
 * \param     reg  [IN] : Register to be written.
 * \param     data [IN] : Data to write into the register.
 *
 * \return    TOUCH_SUCCESS  : On Success.
 *            TOUCH_ERR      : On Failure.
 *
 */
int8_t touchWrite(uint8_t reg, uint8_t data);

/**
 *
 * \brief     Function to read data from the touch controller reg.
 *
 * \param     reg [IN] : Register to be read.
 * 			  value    : Value read
 *
 * \return    TOUCH_SUCCESS			  : On Success.
 *            TOUCH_ERR               : On Failure.
 *
 */
int8_t touchRead(uint32_t reg, uint8_t *value);

/**
 *
 * \brief     Function to get all the value of Touch Panel registers
 *            from [00h to 1Fh] and save in the array.
 *
 * \param     data [IN]	: Buffer to store the touch data read
 * 			  touches	: No: of touch points
 *
 * \return    TOUCH_SUCCESS	:  On Success.
 *            TOUCH_ERR		:  On Failure.
 *
 */
int8_t touchGetAllData(uint16_t data[][DIMENSIONS], uint8_t touches);

/**
 *
 * \brief     Function to configure the touch controller and clear
 *            the status registers if the touch already exists.
 *
 * \return    TOUCH_SUCCESS : On Success.
 *            TOUCH_ERR     : On Failure.
 *
 */
int8_t touchSetup(void);

/**
 *
 * \brief     Function to initialize the touch controller.
 *
 * No input parameters.
 *
 * \return    NONE.
 *
 */
int8_t touchInit(void);

#endif /* _EVMK2G_TOUCH_H_ */

/* Nothing past this point */
