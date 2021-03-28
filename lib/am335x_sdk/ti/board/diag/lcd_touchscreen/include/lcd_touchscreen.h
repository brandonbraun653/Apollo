/**
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
 *
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
 
//touch screen controller registers
//FT5506
#define TOUCH_SLAVE_ADDR 	(0x38)

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

#define TOUCH6_XH               (0x21)
#define TOUCH6_XL               (0x22)
#define TOUCH6_YH               (0x23)
#define TOUCH6_YL               (0x24)

#define TOUCH7_XH               (0x27)
#define TOUCH7_XL               (0x28)
#define TOUCH7_YH               (0x29)
#define TOUCH7_YL               (0x2a)

#define TOUCH8_XH               (0x2d)
#define TOUCH8_XL               (0x2e)
#define TOUCH8_YH               (0x2f)
#define TOUCH8_YL               (0x30)

#define TOUCH9_XH               (0x33)
#define TOUCH9_XL               (0x34)
#define TOUCH9_YH               (0x35)
#define TOUCH9_YL               (0x36)

#define TOUCH10_XH              (0x39)
#define TOUCH10_XL              (0x40)
#define TOUCH10_YH              (0x41)
#define TOUCH10_YL              (0x42)

#define ID_G_THGROUP            (0x80)    // valid touching detect threshold
#define ID_G_THPEAK             (0x81)    // valid touching peak detect threshold
#define ID_G_THCAL              (0x82)    // the threshold when calculating the focus of touching
#define ID_G_THWATER            (0x83)    // the threshold when there is surface water
#define ID_G_TEMP               (0x84)    // the threshold of temperature compensation
#define ID_G_THDIFF             (0x85)    // the threshold whether the coordinate is different from original
#define ID_G_CTRL               (0x86)    //
#define ID_G_TIME_ENTER_MONITOR (0x87)    // the timer for entering monitor status
#define ID_G_PERIODACTIVE       (0x88)    //2
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
#define ID_G_CLB                (0xaa)    // Configure TP module during calibration in Test Mode
#define ID_G_B_AREA_TH          (0xae)    // The threshold of big area
#define LOG_MSG_CNT             (0xfe)    // The log M SG count
#define LOG_CUR_CHA             (0xff)    // Current character of log message

#define NORMAL_OPMODE           (0x00)
#define SYSINFO_MODE            (0x10)
#define TEST_MODE               (0x40)

