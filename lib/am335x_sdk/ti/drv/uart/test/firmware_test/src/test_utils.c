/**
 *  \file   test_utils.c
 *
 *  \brief  Test utilities.
 *
 */

/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include <ti/osal/osal.h>

#include "test/firmware_test/src/test_utils.h"

// UART1 HW IP pin mux settings
UartIoPinMuxAttrs gUartIoPinMuxAttrs = {
    {0x44e10984, IO_PIN_EN,  IO_PIN_OUTPUT, 0},   // TXD
    {0x44e10980, IO_PIN_EN,  IO_PIN_INPUT,  0},   // RXD
    {0x44e10978, IO_PIN_DIS, IO_PIN_INPUT,  0},   // CTSN
    {0x44e1097C, IO_PIN_DIS, IO_PIN_OUTPUT, 0}    // RTSN
};

//
// UART external loopback testing parameters
//

// Test data for external loopback testing
// 8-bit read data
char gTestExtLoopbackRdData8b[TEST_EXT_LB_RD_DATA_SZ] __attribute__ ((aligned (128)));
// 8-bit write data
char gTestExtLoopbackWrData8b[TEST_EXT_LB_WR_DATA_SZ] = {
    0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
    0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
    0xef, 0xee, 0xed, 0xec, 0xeb, 0xea, 0xe9, 0xe8,
    0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0,
    0xdf, 0xde, 0xdd, 0xdc, 0xdb, 0xda, 0xd9, 0xd8,
    0xd7, 0xd6, 0xd5, 0xd4, 0xd3, 0xd2, 0xd1, 0xd0,
    0xcf, 0xce, 0xcd, 0xcc, 0xcb, 0xca, 0xc9, 0xc8,
    0xc7, 0xc6, 0xc5, 0xc4, 0xc3, 0xc2, 0xc1, 0xc0,
    0xbf, 0xbe, 0xbd, 0xbc, 0xbb, 0xba, 0xb9, 0xb8,
    0xb7, 0xb6, 0xb5, 0xb4, 0xb3, 0xb2, 0xb1, 0xb0,
    0xaf, 0xae, 0xad, 0xac, 0xab, 0xaa, 0xa9, 0xa8,
    0xa7, 0xa6, 0xa5, 0xa4, 0xa3, 0xa2, 0xa1, 0xa0,
    0x9f, 0x9e, 0x9d, 0x9c, 0x9b, 0x9a, 0x99, 0x98,
    0x97, 0x96, 0x95, 0x94, 0x93, 0x92, 0x91, 0x90,
    0x8f, 0x8e, 0x8d, 0x8c, 0x8b, 0x8a, 0x89, 0x88,
    0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x80,
    0x7f, 0x7e, 0x7d, 0x7c, 0x7b, 0x7a, 0x79, 0x78,
    0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71, 0x70,
    0x6f, 0x6e, 0x6d, 0x6c, 0x6b, 0x6a, 0x69, 0x68,
    0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61, 0x60,
    0x5f, 0x5e, 0x5d, 0x5c, 0x5b, 0x5a, 0x59, 0x58,
    0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 0x50,
    0x4f, 0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48,
    0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41, 0x40,
    0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38,
    0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30,
    0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x29, 0x28,
    0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20,
    0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18,
    0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
    0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
    0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
    0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
    0xef, 0xee, 0xed, 0xec, 0xeb, 0xea, 0xe9, 0xe8,
    0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0,
    0xdf, 0xde, 0xdd, 0xdc, 0xdb, 0xda, 0xd9, 0xd8,
    0xd7, 0xd6, 0xd5, 0xd4, 0xd3, 0xd2, 0xd1, 0xd0,
    0xcf, 0xce, 0xcd, 0xcc, 0xcb, 0xca, 0xc9, 0xc8,
    0xc7, 0xc6, 0xc5, 0xc4, 0xc3, 0xc2, 0xc1, 0xc0,
    0xbf, 0xbe, 0xbd, 0xbc, 0xbb, 0xba, 0xb9, 0xb8,
    0xb7, 0xb6, 0xb5, 0xb4, 0xb3, 0xb2, 0xb1, 0xb0,
    0xaf, 0xae, 0xad, 0xac, 0xab, 0xaa, 0xa9, 0xa8,
    0xa7, 0xa6, 0xa5, 0xa4, 0xa3, 0xa2, 0xa1, 0xa0,
    0x9f, 0x9e, 0x9d, 0x9c, 0x9b, 0x9a, 0x99, 0x98,
    0x97, 0x96, 0x95, 0x94, 0x93, 0x92, 0x91, 0x90,
    0x8f, 0x8e, 0x8d, 0x8c, 0x8b, 0x8a, 0x89, 0x88,
    0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x80,
    0x7f, 0x7e, 0x7d, 0x7c, 0x7b, 0x7a, 0x79, 0x78,
    0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71, 0x70,
    0x6f, 0x6e, 0x6d, 0x6c, 0x6b, 0x6a, 0x69, 0x68,
    0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61, 0x60,
    0x5f, 0x5e, 0x5d, 0x5c, 0x5b, 0x5a, 0x59, 0x58,
    0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 0x50,
    0x4f, 0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48,
    0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41, 0x40,
    0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38,
    0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30,
    0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x29, 0x28,
    0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20,
    0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18,
    0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
    0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
    0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
};

// 16-bit read data
uint16_t gTestExtLoopbackRdData16b[TEST_EXT_LB_RD_DATA_SZ] __attribute__ ((aligned (128)));
// 16-bit write data
uint16_t gTestExtLoopbackWrData16b[TEST_EXT_LB_WR_DATA_SZ] = {
    0x55ff, 0xaafe, 0x55fd, 0xaafc, 0x55fb, 0xaafa, 0x55f9, 0xaaf8,
    0x55f7, 0xaaf6, 0x55f5, 0xaaf4, 0x55f3, 0xaaf2, 0x55f1, 0xaaf0,
    0x55ef, 0xaaee, 0x55ed, 0xaaec, 0x55eb, 0xaaea, 0x55e9, 0xaae8,
    0x55e7, 0xaae6, 0x55e5, 0xaae4, 0x55e3, 0xaae2, 0x55e1, 0xaae0,
    0x55df, 0xaade, 0x55dd, 0xaadc, 0x55db, 0xaada, 0x55d9, 0xaad8,
    0x55d7, 0xaad6, 0x55d5, 0xaad4, 0x55d3, 0xaad2, 0x55d1, 0xaad0,
    0x55cf, 0xaace, 0x55cd, 0xaacc, 0x55cb, 0xaaca, 0x55c9, 0xaac8,
    0x55c7, 0xaac6, 0x55c5, 0xaac4, 0x55c3, 0xaac2, 0x55c1, 0xaac0,
    0x55bf, 0xaabe, 0x55bd, 0xaabc, 0x55bb, 0xaaba, 0x55b9, 0xaab8,
    0x55b7, 0xaab6, 0x55b5, 0xaab4, 0x55b3, 0xaab2, 0x55b1, 0xaab0,
    0x55af, 0xaaae, 0x55ad, 0xaaac, 0x55ab, 0xaaaa, 0x55a9, 0xaaa8,
    0x55a7, 0xaaa6, 0x55a5, 0xaaa4, 0x55a3, 0xaaa2, 0x55a1, 0xaaa0,
    0x559f, 0xaa9e, 0x559d, 0xaa9c, 0x559b, 0xaa9a, 0x5599, 0xaa98,
    0x5597, 0xaa96, 0x5595, 0xaa94, 0x5593, 0xaa92, 0x5591, 0xaa90,
    0x558f, 0xaa8e, 0x558d, 0xaa8c, 0x558b, 0xaa8a, 0x5589, 0xaa88,
    0x5587, 0xaa86, 0x5585, 0xaa84, 0x5583, 0xaa82, 0x5581, 0xaa80,
    0x557f, 0xaa7e, 0x557d, 0xaa7c, 0x557b, 0xaa7a, 0x5579, 0xaa78,
    0x5577, 0xaa76, 0x5575, 0xaa74, 0x5573, 0xaa72, 0x5571, 0xaa70,
    0x556f, 0xaa6e, 0x556d, 0xaa6c, 0x556b, 0xaa6a, 0x5569, 0xaa68,
    0x5567, 0xaa66, 0x5565, 0xaa64, 0x5563, 0xaa62, 0x5561, 0xaa60,
    0x555f, 0xaa5e, 0x555d, 0xaa5c, 0x555b, 0xaa5a, 0x5559, 0xaa58,
    0x5557, 0xaa56, 0x5555, 0xaa54, 0x5553, 0xaa52, 0x5551, 0xaa50,
    0x554f, 0xaa4e, 0x554d, 0xaa4c, 0x554b, 0xaa4a, 0x5549, 0xaa48,
    0x5547, 0xaa46, 0x5545, 0xaa44, 0x5543, 0xaa42, 0x5541, 0xaa40,
    0x553f, 0xaa3e, 0x553d, 0xaa3c, 0x553b, 0xaa3a, 0x5539, 0xaa38,
    0x5537, 0xaa36, 0x5535, 0xaa34, 0x5533, 0xaa32, 0x5531, 0xaa30,
    0x552f, 0xaa2e, 0x552d, 0xaa2c, 0x552b, 0xaa2a, 0x5529, 0xaa28,
    0x5527, 0xaa26, 0x5525, 0xaa24, 0x5523, 0xaa22, 0x5521, 0xaa20,
    0x551f, 0xaa1e, 0x551d, 0xaa1c, 0x551b, 0xaa1a, 0x5519, 0xaa18,
    0x5517, 0xaa16, 0x5515, 0xaa14, 0x5513, 0xaa12, 0x5511, 0xaa10,
    0x550f, 0xaa0e, 0x550d, 0xaa0c, 0x550b, 0xaa0a, 0x5509, 0xaa08,
    0x5507, 0xaa06, 0x5505, 0xaa04, 0x5503, 0xaa02, 0x5501, 0xaa00,
    0x55ff, 0xaafe, 0x55fd, 0xaafc, 0x55fb, 0xaafa, 0x55f9, 0xaaf8,
    0x55f7, 0xaaf6, 0x55f5, 0xaaf4, 0x55f3, 0xaaf2, 0x55f1, 0xaaf0,
    0x55ef, 0xaaee, 0x55ed, 0xaaec, 0x55eb, 0xaaea, 0x55e9, 0xaae8,
    0x55e7, 0xaae6, 0x55e5, 0xaae4, 0x55e3, 0xaae2, 0x55e1, 0xaae0,
    0x55df, 0xaade, 0x55dd, 0xaadc, 0x55db, 0xaada, 0x55d9, 0xaad8,
    0x55d7, 0xaad6, 0x55d5, 0xaad4, 0x55d3, 0xaad2, 0x55d1, 0xaad0,
    0x55cf, 0xaace, 0x55cd, 0xaacc, 0x55cb, 0xaaca, 0x55c9, 0xaac8,
    0x55c7, 0xaac6, 0x55c5, 0xaac4, 0x55c3, 0xaac2, 0x55c1, 0xaac0,
    0x55bf, 0xaabe, 0x55bd, 0xaabc, 0x55bb, 0xaaba, 0x55b9, 0xaab8,
    0x55b7, 0xaab6, 0x55b5, 0xaab4, 0x55b3, 0xaab2, 0x55b1, 0xaab0,
    0x55af, 0xaaae, 0x55ad, 0xaaac, 0x55ab, 0xaaaa, 0x55a9, 0xaaa8,
    0x55a7, 0xaaa6, 0x55a5, 0xaaa4, 0x55a3, 0xaaa2, 0x55a1, 0xaaa0,
    0x559f, 0xaa9e, 0x559d, 0xaa9c, 0x559b, 0xaa9a, 0x5599, 0xaa98,
    0x5597, 0xaa96, 0x5595, 0xaa94, 0x5593, 0xaa92, 0x5591, 0xaa90,
    0x558f, 0xaa8e, 0x558d, 0xaa8c, 0x558b, 0xaa8a, 0x5589, 0xaa88,
    0x5587, 0xaa86, 0x5585, 0xaa84, 0x5583, 0xaa82, 0x5581, 0xaa80,
    0x557f, 0xaa7e, 0x557d, 0xaa7c, 0x557b, 0xaa7a, 0x5579, 0xaa78,
    0x5577, 0xaa76, 0x5575, 0xaa74, 0x5573, 0xaa72, 0x5571, 0xaa70,
    0x556f, 0xaa6e, 0x556d, 0xaa6c, 0x556b, 0xaa6a, 0x5569, 0xaa68,
    0x5567, 0xaa66, 0x5565, 0xaa64, 0x5563, 0xaa62, 0x5561, 0xaa60,
    0x555f, 0xaa5e, 0x555d, 0xaa5c, 0x555b, 0xaa5a, 0x5559, 0xaa58,
    0x5557, 0xaa56, 0x5555, 0xaa54, 0x5553, 0xaa52, 0x5551, 0xaa50,
    0x554f, 0xaa4e, 0x554d, 0xaa4c, 0x554b, 0xaa4a, 0x5549, 0xaa48,
    0x5547, 0xaa46, 0x5545, 0xaa44, 0x5543, 0xaa42, 0x5541, 0xaa40,
    0x553f, 0xaa3e, 0x553d, 0xaa3c, 0x553b, 0xaa3a, 0x5539, 0xaa38,
    0x5537, 0xaa36, 0x5535, 0xaa34, 0x5533, 0xaa32, 0x5531, 0xaa30,
    0x552f, 0xaa2e, 0x552d, 0xaa2c, 0x552b, 0xaa2a, 0x5529, 0xaa28,
    0x5527, 0xaa26, 0x5525, 0xaa24, 0x5523, 0xaa22, 0x5521, 0xaa20,
    0x551f, 0xaa1e, 0x551d, 0xaa1c, 0x551b, 0xaa1a, 0x5519, 0xaa18,
    0x5517, 0xaa16, 0x5515, 0xaa14, 0x5513, 0xaa12, 0x5511, 0xaa10,
    0x550f, 0xaa0e, 0x550d, 0xaa0c, 0x550b, 0xaa0a, 0x5509, 0xaa08,
    0x5507, 0xaa06, 0x5505, 0xaa04, 0x5503, 0xaa02, 0x5501, 0xaa00,
};

// Test UART settings for HW IP to SW IP external loopback testing
uint32_t gTestExtLbBaudRate[TEST_EXT_LB_NUM_UART_BAUD_RATE] = {
    BAUD_RATE_300,   BAUD_RATE_600,   BAUD_RATE_1200,  BAUD_RATE_2400,
    BAUD_RATE_4800,  BAUD_RATE_9600,  BAUD_RATE_14400, BAUD_RATE_19200,
    BAUD_RATE_28800, BAUD_RATE_38400, BAUD_RATE_57600, BAUD_RATE_115200
};
UART_LEN gTestExtLbCharLen[TEST_EXT_LB_NUM_UART_CHAR_LEN] = {
    UART_LEN_5, UART_LEN_6, UART_LEN_7, UART_LEN_8
};
UART_STOP gTestExtLbStopBits[TEST_EXT_LB_NUM_UART_STOP_BITS] = {
    UART_STOP_ONE, UART_STOP_TWO
};
UART_PAR gTestExtLbParity[TEST_EXT_LB_NUM_UART_PARITY] = {
    UART_PAR_NONE, UART_PAR_EVEN, UART_PAR_ODD
};

// Test UART settings for SW IP to SW IP external loopback testing
uint32_t gTestExtLbBaudRateSw2SwIp[TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP] = {
    BAUD_RATE_300,   BAUD_RATE_600,   BAUD_RATE_1200,  BAUD_RATE_2400,
    BAUD_RATE_4800,  BAUD_RATE_9600,  BAUD_RATE_14400, BAUD_RATE_19200,
    BAUD_RATE_28800, BAUD_RATE_38400, BAUD_RATE_57600, BAUD_RATE_115200
};
UART_LEN gTestExtLbCharLenSw2SwIp[TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP] = {
    UART_LEN_5, UART_LEN_6, UART_LEN_7, UART_LEN_8, UART_LEN_9
};
UART_STOP gTestExtLbStopBitsSw2SwIp[TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP] = {
    UART_STOP_ONE, UART_STOP_TWO, UART_STOP_ONEP5
};
UART_PAR gTestExtLbParitySw2SwIp[TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP] = {
    UART_PAR_NONE, UART_PAR_EVEN, UART_PAR_ODD
};

// Test UART settings for SW IP to SW IP external loopback testing, HW flow control enabled
uint32_t gTestExtLbBaudRateSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP_HWFC] = {
    BAUD_RATE_115200,BAUD_RATE_57600, BAUD_RATE_38400, BAUD_RATE_28800,
    BAUD_RATE_19200, BAUD_RATE_14400, BAUD_RATE_9600,  BAUD_RATE_4800,
    BAUD_RATE_2400,  BAUD_RATE_1200,  BAUD_RATE_600,   BAUD_RATE_300
};
UART_LEN gTestExtLbCharLenSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP_HWFC] = {
    UART_LEN_9, UART_LEN_8, UART_LEN_7, UART_LEN_6, UART_LEN_5
};
UART_STOP gTestExtLbStopBitsSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP_HWFC] = {
    UART_STOP_TWO, UART_STOP_ONEP5, UART_STOP_ONE
};
UART_PAR gTestExtLbParitySw2SwIpHwFc[TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP_HWFC] = {
    UART_PAR_ODD, UART_PAR_EVEN, UART_PAR_NONE
};
uint8_t gTestExtLbHwFcThrSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_HW_FC_THR_SW2SWIP_HWFC] = {
    0x01, 0x10, 0x15, 0x20
};


//
// UART SW IP Stress Test parameters
//

// Read test data
// 8-bit read data
char gTestStressRdData8b[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));
// 16-bit read data
uint16_t gTestStressRdData16bP0S1[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));
uint16_t gTestStressRdData16bP1S0[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));
uint16_t gTestStressRdData16bP1S1[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));
uint16_t gTestStressRdData16bP2S0[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));
uint16_t gTestStressRdData16bP2S1[TEST_STRESS_MAX_RD_DATA_SZ] __attribute__ ((aligned (128)));

// UART settings
// Different baud rates
//TestStressUartCfgPrms gTestStressUartCfgPrms[TEST_STRESS_NUM_UART_LB_PAIR] = {
//    {BAUD_RATE_115200, UART_LEN_8, UART_STOP_TWO,   UART_PAR_ODD,  UART_FC_HW,   0x10}, // Pair 0: UART1 HW IP      <-> PRU0 UART0 SW IP
//    {BAUD_RATE_38400,  UART_LEN_9, UART_STOP_ONEP5, UART_PAR_EVEN, UART_FC_NONE, 0x0},  // Pair 1: PRU0 UART2 SW IP <-> PRU0 UART1 SW IP
//    {BAUD_RATE_9600,   UART_LEN_5, UART_STOP_ONE,   UART_PAR_NONE, UART_FC_NONE, 0x0},  // Pair 2: PRU1 UART2 SW IP <-> PRU1 UART1 SW IP
//};
// UART transfer parameters
// Small number of transfers
//TestStressUartXferPrms gTestStressUartXferPrms[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR] = {
//    {{12,384,24,192,gTestStressRdData8b,     gTestExtLoopbackWrData8b, true},           // Pair 0, Side 0
//     {24,192,12,384,gTestStressRdData16bP0S1,gTestExtLoopbackWrData16b,false}},         // Pair 0, Side 1
//    {{ 6,256, 3,512,gTestStressRdData16bP1S0,gTestExtLoopbackWrData16b,false},          // Pair 1, Side 0
//     { 3,512, 6,256,gTestStressRdData16bP1S1,gTestExtLoopbackWrData16b,false}},         // Pair 1, Side 1
//    {{ 3,128, 1,384,gTestStressRdData16bP2S0,gTestExtLoopbackWrData16b,false},          // Pair 2, Side 0
//     { 1,384, 3,128,gTestStressRdData16bP2S1,gTestExtLoopbackWrData16b,false}}          // Pair 2, Side 1
//};
// Larger number of transfers
//TestStressUartXferPrms gTestStressUartXferPrms[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR] = {
//    {{1200,384,2400,192,gTestStressRdData8b,     gTestExtLoopbackWrData8b, true},       // Pair 0, Side 0
//     {2400,192,1200,384,gTestStressRdData16bP0S1,gTestExtLoopbackWrData16b,false}},     // Pair 0, Side 1
//    {{ 600,256, 300,512,gTestStressRdData16bP1S0,gTestExtLoopbackWrData16b,false},      // Pair 1, Side 0
//     { 300,512, 600,256,gTestStressRdData16bP1S1,gTestExtLoopbackWrData16b,false}},     // Pair 1, Side 1
//    {{ 300,128, 100,384,gTestStressRdData16bP2S0,gTestExtLoopbackWrData16b,false},      // Pair 2, Side 0
//     { 100,384, 300,128,gTestStressRdData16bP2S1,gTestExtLoopbackWrData16b,false}}      // Pair 2, Side 1
//};

// All baud rate 115200
TestStressUartCfgPrms gTestStressUartCfgPrms[TEST_STRESS_NUM_UART_LB_PAIR] = {
    {BAUD_RATE_115200, UART_LEN_8, UART_STOP_TWO,   UART_PAR_ODD,  UART_FC_NONE, 0x0},  // Pair 0: UART1 HW IP      <-> PRU0 UART0 SW IP
    {BAUD_RATE_115200, UART_LEN_9, UART_STOP_ONEP5, UART_PAR_EVEN, UART_FC_NONE, 0x0},  // Pair 1: PRU0 UART2 SW IP <-> PRU0 UART1 SW IP
    {BAUD_RATE_115200, UART_LEN_5, UART_STOP_ONE,   UART_PAR_NONE, UART_FC_HW,   0x10}, // Pair 2: PRU1 UART2 SW IP <-> PRU1 UART1 SW IP
};
// Small number of transfers
//TestStressUartXferPrms gTestStressUartXferPrms[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR] = {
//    {{12,384,24,192,gTestStressRdData8b,     gTestExtLoopbackWrData8b, true},           // Pair 0, Side 0
//     {24,192,12,384,gTestStressRdData16bP0S1,gTestExtLoopbackWrData16b,false}},         // Pair 0, Side 1
//    {{24,192,12,384,gTestStressRdData16bP1S0,gTestExtLoopbackWrData16b,false},          // Pair 1, Side 0
//     {12,384,24,192,gTestStressRdData16bP1S1,gTestExtLoopbackWrData16b,false}},         // Pair 1, Side 1
//    {{12,384,24,192,gTestStressRdData16bP2S0,gTestExtLoopbackWrData16b,false},          // Pair 2, Side 0
//     {24,192,12,384,gTestStressRdData16bP2S1,gTestExtLoopbackWrData16b,false}}          // Pair 2, Side 1
//};
// Larger number of transfers
TestStressUartXferPrms gTestStressUartXferPrms[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR] = {
    {{12000,384,24000,192,gTestStressRdData8b,     gTestExtLoopbackWrData8b, true},     // Pair 0, Side 0
     {24000,192,12000,384,gTestStressRdData16bP0S1,gTestExtLoopbackWrData16b,false}},   // Pair 0, Side 1
    {{24000,192,12000,384,gTestStressRdData16bP1S0,gTestExtLoopbackWrData16b,false},    // Pair 1, Side 0
     {12000,384,24000,192,gTestStressRdData16bP1S1,gTestExtLoopbackWrData16b,false}},   // Pair 1, Side 1
    {{12000,384,24000,192,gTestStressRdData16bP2S0,gTestExtLoopbackWrData16b,false},    // Pair 2, Side 0
     {24000,192,12000,384,gTestStressRdData16bP2S1,gTestExtLoopbackWrData16b,false}}    // Pair 2, Side 1
};

// Configures IO Pin Mux
static bool configIoPinMux(IoPinMuxAttrs *pIoPinMuxAttrs)
{
    uint32_t regVal;
    uint8_t pinDir;
    bool ret;
    
    if (pIoPinMuxAttrs != NULL)
    {
        if ((pIoPinMuxAttrs->pinEn & IO_PIN_ENABLE_MASK) == IO_PIN_EN)
        {
            regVal = *(volatile uint32_t *)(pIoPinMuxAttrs->confRegAddr);
            pinDir = pIoPinMuxAttrs->pinDir & IO_PIN_DIR_MASK;            
            if (pinDir == IO_PIN_INPUT)
            {
                regVal &= IO_PIN_INPUT_SELECT_MASK;
                regVal |= IO_PIN_INPUT_ENABLE;
                regVal |= (uint32_t)pIoPinMuxAttrs->modeVal;
                ret = true;
            }
            else if (pinDir == IO_PIN_OUTPUT)
            {
                regVal &= IO_PIN_OUTPUT_SELECT_MASK;
                regVal |= IO_PIN_OUTPUT_ENABLE;
                regVal |= (uint32_t)(pIoPinMuxAttrs->modeVal);
                ret = true;
            }
            else
            {
                // error, Pin not configured as Input or Output
                ret = false;
            }
            
            *(volatile uint32_t *)(pIoPinMuxAttrs->confRegAddr) = regVal;
        }
        else
        {
            ret = true;
        }
    }
    else
    {
        ret = false;
    }
    
    return ret;
}

// Configures UART IO Pin Mux
bool configUartIoPinMux(UartIoPinMuxAttrs *pUartIoPinMuxAttrs)
{
    bool ret;
    
    if (pUartIoPinMuxAttrs != NULL)
    {
        // Configure UART TXD
        ret = configIoPinMux(&pUartIoPinMuxAttrs->txdPinMuxAttrs);
        
        // Configure UART RXD
        if (ret == true)
        {
            ret = configIoPinMux(&pUartIoPinMuxAttrs->rxdPinMuxAttrs);
        }
        
        // Configure UART CTSN
        if (ret == true)
        {
            ret = configIoPinMux(&pUartIoPinMuxAttrs->ctsnPinMuxAttrs);
        }
        
        // Configure UART RTSN
        if (ret == true)
        {
            ret = configIoPinMux(&pUartIoPinMuxAttrs->rtsnPinMuxAttrs);
        }
    }
    else
    {
        ret = false;
    }
    
    return ret;
}

// Prints test ID to string formatted for 16-bit chars
bool sprintTestId(int testId, char testIdStr[], uint8_t testIdStrSize)
{
    uint8_t len;
    char *pIn, *pOut;
    uint8_t i;
    bool ret;
    
    sprintf(testIdStr, "%d", testId);
    
    len = strlen(testIdStr);    // determine string length in chars
    if (len <= testIdStrSize)
    {
        pIn = &testIdStr[len-1];
        pOut = &testIdStr[2*len-2];
        for (i = len; i > 0; i--)
        {
            *(pOut+1) = ' ';    // insert dummy space
            *pOut = *pIn;       // insert char
            pOut -= 2;
            pIn--;
        }
        
        ret = true;
    }
    else
    {
        ret = false;
    }

    return ret;
}

// Compares external loopback testing read/write data
bool compareExtLoopbackRdWrData(
    void *data,
    uint16_t *data16b,
    uint32_t dataLen,
    UART_LEN charLen,
    bool cmp8b)
{
    uint16_t charMask;
    uint16_t data1, data2;
    uint32_t i;
    bool cmpErr, ret = true;
    
    // determine bit mask for compare
    switch (charLen)
    {
        case UART_LEN_5:
            charMask = UART_CHAR_LEN_5_MASK;
            break;
        case UART_LEN_6:
            charMask = UART_CHAR_LEN_6_MASK;
            break;
        case UART_LEN_7:
            charMask = UART_CHAR_LEN_7_MASK;
            break;
        case UART_LEN_8:
            charMask = UART_CHAR_LEN_8_MASK;
            break;
        case UART_LEN_9:
            charMask = UART_CHAR_LEN_9_MASK;
            break;
        default:
            ret = false;
            break;
    }

    if (ret == true)
    {
        if (cmp8b == true)
        {
            // compare 8- and 16-bit data vectors
            // continue until all data compared or mismatch identified
            cmpErr = false;
            i = 0;
            while ((cmpErr == false) && (i < dataLen))
            {
                data1 = (uint16_t)(*((uint8_t *)data + i)) & charMask;
                data2 = data16b[i] & charMask;
                if (data1 == data2)
                {
                    i++;
                }
                else
                {
                    cmpErr = true;
                }
            }
        }
        else
        {
            // compare 16- and 16-bit data vectors
            // continue until all data compared or mismatch identified
            cmpErr = false;
            i = 0;
            while ((cmpErr == false) && (i < dataLen))
            {
                data1 = *((uint16_t *)data + i) & charMask;
                data2 = data16b[i] & charMask;
                if (data1 == data2)
                {
                    i++;
                }
                else
                {
                    cmpErr = true;
                }
            }
        }
    
        ret = (cmpErr == false) ? true : false;
    }

    return ret;
}
