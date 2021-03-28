/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file   board_detect.c
 *
 *  \brief  board presence detect test file
 *
 *  This Verifying the read and write functionality of board detect interface.
 *
 */

#include "board_internal.h"
#include "board_cfg.h"
#include "board_i2c_io_exp.h"

/**
 * \brief board detect test
 *
 * This function used to check whether the specified board exists.
 *
 * \param   detectBoard  [IN]  enum used to send the name of the
 *                             board going to be detected.
 *
 * \return   bool
 *                    true   - In case of specified board detected
 *                    false  - In case of specified board not detected.
 *
 */
bool Board_detectBoard(boardPresDetect_t detectBoard)
{
    uint8_t boardDetectLineNum;
    bool isBoardDetected = false;
    uint8_t rdRegData;
    int8_t ret;
    
    Board_i2cIoExpInit();

    /* Reading the I/O expansion port to detect the board */
    ret = Board_i2cIoExpReadPort(BOARD_PRES_DETECT_SLAVE_ADDR,
                                 PORTNUM_NONE,
                                 &rdRegData);
    if(ret != BOARD_SOK)
    {
        isBoardDetected = false;
    }
    else
    {
        isBoardDetected    = false;
        for(boardDetectLineNum = 0; boardDetectLineNum < 4; boardDetectLineNum++)
        {
            /* Check if the board connected to the corresponding line is detected or not */
            if((!((bool)((rdRegData >> boardDetectLineNum) & 0x01))))
            {
                if((boardDetectLineNum == APP_CARD_DETECT) &&
                   (boardDetectLineNum == detectBoard))
                {
                    isBoardDetected = true;
                    break;
                }
                else if((boardDetectLineNum == LCD_BRD_DETECT) &&
                        (boardDetectLineNum == detectBoard))
                {
                    isBoardDetected = true;
                    break;
                }
                else if((boardDetectLineNum == SERDES_BRD_DETECT) &&
                        (boardDetectLineNum == detectBoard))
                {
                    isBoardDetected = true;
                    break;
                }
                else if((boardDetectLineNum == HDMI_BRD_DETECT) &&
                        (boardDetectLineNum == detectBoard))
                {
                    isBoardDetected = true;
                    break;
                }
            }
        }
    }

    Board_i2cIoExpDeInit();

    return isBoardDetected;
}

