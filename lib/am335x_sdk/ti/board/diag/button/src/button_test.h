/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file   button_test.h
 *
 * \brief  This is the header file for push button diagnostic test.
 *
 */

#ifndef _BUTTON_TEST_H_
#define _BUTTON_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/gpio/GPIO.h>
#if (!(defined(SOC_AM65XX)))
#include <ti/drv/gpio/soc/GPIO_soc.h>
#else
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif

#include <ti/drv/uart/UART_stdio.h>
#include <soc.h>
#if (!defined(SOC_AM65XX))
#include <ti/starterware/include/interrupt.h>
#endif

#if defined(SOC_AM65XX)
#include "diag_common_cfg.h"
#endif

#include "board.h"
#include "board_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_PIN_VAL_LOW             (0U)
#define GPIO_PIN_VAL_HIGH            (1U)

#define BOARD_NAME_LENGTH            (8U)

/** \brief Successful completion of the functionality.  */
#ifndef S_PASS
#define S_PASS                       (0)
#endif
/** \brief Generic failure code.                        */
#ifndef E_FAIL
#define E_FAIL                       (-1)
#endif

/** \brief structure holding the GPIO related information for buttons.  */
typedef struct gpioInfo
{
    uint32_t instance;
    uint32_t pin;
}gpioInfo_t;

/** \brief structure holding the Keypad information of the board.  */
typedef struct keyPadInfo
{
    uint32_t buttonSet;
    uint32_t scnKeyNum;
    uint32_t pwrKeyNum;
    uint32_t pwrKeyIdx;
}keyPadInfo_t;

/**
 * \brief   Get the Board keypad information as per the board Id.
 *
 * \param   *pBoardName       [IN]      Pointer to hold the board name
 * \param   *pBoardKeyPad     [OUT]     Structure pointer for holding the
 *                                      Keypad information of the board.
 *
 * \retval  S_PASS  if the board id matches
 * \retval  E_FAIL  if the board id fails.
 *
 */
int32_t BoardDiag_GetKeyPadInfo(char *pBoardName, keyPadInfo_t *pBoardKeyPad);

/**
 * \brief   This function is used to perform the push button diagnostic test.
 *
 * \param   *pBoardKeyPad     [IN]      Structure pointer consisting of the
 *                                      Keypad information of the board.
 *
 * \retval  S_PASS  if the board id matches
 * \retval  E_FAIL  if the board id fails.
 *
 */
int32_t BoardDiag_ButtonTest();

/**
 * \brief   This is used for keep on checking for a specified button to
 *          be pressed.
 *
 * \param   *pBoardKeyPad     [IN]      Structure pointer consisting of the
 *                                      Keypad information of the board.
 * \param   button            [IN]      Push button switch number.
 * \param   scnKey            [IN]      Push button switch index.
 * \param   pwrKey            [IN]      Power key number.
 *
 * \retval  S_PASS  if the board id matches
 * \retval  E_FAIL  if the board id fails.
 *
 */
int32_t BoardDiag_KeyPressCheck(keyPadInfo_t *pBoardKeyPad,
                                uint32_t button,
                                uint32_t scnKey,
                                uint32_t pwrKey);

/**
 * \brief   This function is used enable the power key by making the power
 *          key GPIO line high.
 *
 * \param   *pBoardKeyPad     [IN]      Structure pointer consisting of the
 *                                      Keypad information of the board
 * \param   num               [IN]      Power key number.
 *
 * \retval  S_PASS  if the board id matches
 * \retval  E_FAIL  if the board id fails.
 *
 */
void BoardDiag_BtnPwr(keyPadInfo_t *pBoardKeyPad, uint32_t num);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BUTTON_TEST_H_ */
