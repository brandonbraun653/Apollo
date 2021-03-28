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
 * \file  dcan_test.h
 *
 * \brief   This file contains structure, typedefs, functions and
 *          prototypes used for dcan test
 *
 *****************************************************************************/

#ifndef        _DCAN_TEST_H_
#define        _DCAN_TEST_H_

#include "platform_test.h"
#include "platform_internal.h"

/*****************************************************************************
**                   MACRO DEFINITIONS
*****************************************************************************/
#define DCAN0_BASE                         (CSL_DCAN_0_CFG_REGS)
#define DCAN1_BASE                         (CSL_DCAN_1_CFG_REGS)

//CAN defines
#define CAN_DATA_BYTES_MAX_SIZE           (8u)
#define TRANSMIT_MULTIPLE_MSG             (2u)
#define TRANSMIT_REMOTE_FRAME             (3u)
#define DCAN_NO_INT_PENDING               (0x00000000u)
#define TRANSMIT_SINGLE_MSG               (1u)
#define DCAN_ERROR_OCCURED                (0x8000u)
#define ENTER_KEY_PRESSED                 (0xD)
#define CAN_RX_MSG_ID                     (0u)
#define DCAN_BIT_RATE                     (1000000u)
#define DCAN_IN_CLK                       (24000000u)

#define HWREG(x)                                                              \
        (*((volatile uint32_t *)(x)))
#define HWREGH(x)                                                             \
        (*((volatile uint16_t *)(x)))
#define HWREGB(x)                                                             \
        (*((volatile uint8_t *)(x)))

void dumpStats(uint32_t instance);
void DumpObjects(uint32_t instance);

/**
 * \brief This function performs dcan test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS dcanTest(void *testArgs);

#endif // _DCAN_TEST_H_

/* Nothing past this point */

