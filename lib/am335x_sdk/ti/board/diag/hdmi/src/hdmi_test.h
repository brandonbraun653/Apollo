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
 * \file  hdmi_test.h
 *
 * \brief   This file contains structure, typedefs, functions and
 *          prototypes used for hdmi test
 *
 *****************************************************************************/

#ifndef	_HDMI_TEST_H_
#define	_HDMI_TEST_H_

#include "platform_test.h"

#define HDMI_EDID_MAX_LENGTH    (256)
#define HDMI_CHIPID_902x        (0xB0)
#if 0
#define HDMI_BLACK   (0x00000000)
#define HDMI_WHITE   (0x00FFFFFF)
#define HDMI_BLUE    (0x000000FF)
#define HDMI_GREEN   (0x0000FF00)
#define HDMI_RED     (0x00FF0000)
#define HDMI_PURPLE  (0x00A020F0)
#define HDMI_PINK    (0x00FFC0CB)
#define HDMI_YELLOW  (0x00FFFF00)
#else
#define HDMI_BLACK   (0x00000000)
#define HDMI_WHITE   (0x00FFFFFF)
#define HDMI_BLUE    (0x00FF0000)
#define HDMI_GREEN   (0x0000FF00)
#define HDMI_RED     (0x000000FF)
#define HDMI_PURPLE  (0x00F020A0)
#define HDMI_PINK    (0x00CBC0FF)
#define HDMI_YELLOW  (0x0000FFFF)
#endif

#define HDMI_DISPLAY_DELAY (5)

/**
 * \brief This function performs hdmi test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS hdmiTest(void *testArgs);

#endif // _HDMI_TEST_H_

/* Nothing past this point */
