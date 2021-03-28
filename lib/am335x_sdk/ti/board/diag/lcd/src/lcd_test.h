/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 * \file  lcd_test.h
 *
 * \brief   This file contains structure, typedefs, functions and
 *          prototypes used for lcd test
 *
 *****************************************************************************/

#ifndef _LCD_TEST_H_
#define _LCD_TEST_H_

#include "platform_test.h"

#if 0
#define LCD_BLACK   (0x00000000)
#define LCD_WHITE   (0x00FFFFFF)
#define LCD_BLUE    (0x000000FF)
#define LCD_GREEN   (0x0000FF00)
#define LCD_RED     (0x00FF0000)
#define LCD_PURPLE  (0x00A020F0)
#define LCD_PINK    (0x00FFC0CB)
#define LCD_YELLOW  (0x00FFFF00)
#else
#define LCD_BLACK   (0x00000000)
#define LCD_WHITE   (0x00FFFFFF)
#define LCD_BLUE    (0x00FF0000)
#define LCD_GREEN   (0x0000FF00)
#define LCD_RED     (0x000000FF)
#define LCD_PURPLE  (0x00F020A0)
#define LCD_PINK    (0x00CBC0FF)
#define LCD_YELLOW  (0x0000FFFF)

#endif

#define LCD_DISPLAY_DELAY (5)

#define WAIT_DELAY				(1000000) /* 1 sec */

/**
 * \brief This function performs lcd test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS lcdTest(void *testArgs);

#endif // _LCD_TEST_H_

/* Nothing past this point */
