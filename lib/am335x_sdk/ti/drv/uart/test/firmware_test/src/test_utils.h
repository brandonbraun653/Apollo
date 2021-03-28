/**
 *  \file   test_utils.h
 *
 *  \brief  Test utilities header file.
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


#ifndef _UART_TEST_UTILS_H
#define _UART_TEST_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/osal/osal.h>

// Test UART instance IDs
#if defined(icev2AM335x) || defined(bbbAM335x)
#define UART_TEST_INSTANCE0 ( 1U )  // HW IP, UART2
#define UART_TEST_INSTANCE1 ( 6U )  // SW IP, PRU0 UART0
#define UART_TEST_INSTANCE2 ( 7U )  // SW IP, PRU0 UART1
#define UART_TEST_INSTANCE3 ( 8U )  // SW IP, PRU0 UART2
#define UART_TEST_INSTANCE4 ( 9U )  // SW IP, PRU1 UART0
#define UART_TEST_INSTANCE5 ( 10U ) // SW IP, PRU1 UART1
#define UART_TEST_INSTANCE6 ( 11U ) // SW IP, PRU1 UART2
#endif

// External loopback testing maximum read/write sizes
#define TEST_EXT_LB_RD_DATA_SZ                      ( 512 )
#define TEST_EXT_LB_WR_DATA_SZ                      ( 512 )

// External loopback testing "small" & "large" read/write sizes
#define TEST_EXT_LB_SMALL_RD_SZ                     ( 40 )
#define TEST_EXT_LB_SMALL_WR_SZ                     ( 40 )
#define TEST_EXT_LB_LARGE_WR_SZ                     ( 384 )
#define TEST_EXT_LB_LARGE_RD_SZ                     ( 384 )

// Test parameters for HW IP to SW IP
#define TEST_EXT_LB_NUM_UART_BAUD_RATE              ( UART_NUM_BAUD_RATE )
#define TEST_EXT_LB_NUM_UART_CHAR_LEN               ( 4 )
#define TEST_EXT_LB_NUM_UART_STOP_BITS              ( 2 )
#define TEST_EXT_LB_NUM_UART_PARITY                 ( 3 )

// Test parameters for SW IP to SW IP 
#define TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP      ( UART_NUM_BAUD_RATE )
#define TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP       ( 5 )
#define TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP      ( 3 )
#define TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP         ( 3 )

// Test parameters for SW IP to SW IP, HW FC enabled 
#define TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP_HWFC ( UART_NUM_BAUD_RATE )
#define TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP_HWFC  ( 5 )
#define TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP_HWFC ( 3 )
#define TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP_HWFC    ( 3 )
#define TEST_EXT_LB_NUM_UART_HW_FC_THR_SW2SWIP_HWFC ( 4 )

// UART open/close SW IP test parameters
#define TEST_OPEN_CLOSE_SWIP_BAUD_RATE              ( 9600 )
#define TEST_OPEN_CLOSE_SWIP_DATA_LENGTH            ( UART_LEN_8 )
#define TEST_OPEN_CLOSE_SWIP_STOP_BITS              ( UART_STOP_ONE )
#define TEST_OPEN_CLOSE_SWIP_PARITY                 ( UART_PAR_NONE )

// UART character length masks
#define UART_CHAR_LEN_5_MASK                        ( 0x1F )
#define UART_CHAR_LEN_6_MASK                        ( 0x3F )
#define UART_CHAR_LEN_7_MASK                        ( 0x7F )
#define UART_CHAR_LEN_8_MASK                        ( 0xFF )
#define UART_CHAR_LEN_9_MASK                        ( 0x1FF )

// IO Pin Mux macros
#define IO_PIN_ENABLE_MASK                          ( 0x1 )             // pin enable bit mask
#define IO_PIN_DIS                                  ( 0 )               // setting for enabled UART IO pin
#define IO_PIN_EN                                   ( 1 )               // setting for disabled UART IO pin
#define IO_PIN_DIR_MASK                             ( 0x1 )             // pin direction bit mask
#define IO_PIN_INPUT                                ( 0 )               // setting for input UART IO pin 
#define IO_PIN_OUTPUT                               ( 1 )               // setting for output UART IO pin
#define IO_PIN_INPUT_SELECT_MASK                    ( 0xFFFFFFF0U )     // input selection mask
#define IO_PIN_OUTPUT_SELECT_MASK                   ( 0xFFFFFFD8U )     // output selection mask
#define IO_PIN_INPUT_ENABLE                         ( 0x00000030U )     // input pin mux setting:   pull-up enabled, receiver enabled
#define IO_PIN_OUTPUT_ENABLE                        ( 0x00000008U )     // output pin mux setting:  pullup/pulldown disabled, receiver disabled 

// IO Pin Mux structure
typedef struct IoPinMuxAttrs_s {
    uint32_t    confRegAddr;    // conf_<module>_<pin> register address
    uint8_t     pinEn;          // flag indicating whether pin enabled, (0/1): (disabled/enabled)
    uint8_t     pinDir;         // flag indicating whether pin is Input or Output, (0/1): (input/output)
    uint8_t     modeVal;        // mode value for pin
} IoPinMuxAttrs;

// UART IO Pin Mux structure
typedef struct UartIoPinMuxAttrs_s {
    IoPinMuxAttrs   txdPinMuxAttrs;
    IoPinMuxAttrs   rxdPinMuxAttrs;
    IoPinMuxAttrs   ctsnPinMuxAttrs;
    IoPinMuxAttrs   rtsnPinMuxAttrs;
} UartIoPinMuxAttrs;

// UART1 HW IP pin mux settings
extern UartIoPinMuxAttrs gUartIoPinMuxAttrs;

// Test data for external loopback testing
extern char gTestExtLoopbackRdData8b[TEST_EXT_LB_RD_DATA_SZ];
extern char gTestExtLoopbackWrData8b[TEST_EXT_LB_WR_DATA_SZ];
extern uint16_t gTestExtLoopbackRdData16b[TEST_EXT_LB_RD_DATA_SZ];
extern uint16_t gTestExtLoopbackWrData16b[TEST_EXT_LB_WR_DATA_SZ];

// Test UART settings for HW IP to SW IP external loopback testing
extern uint32_t gTestExtLbBaudRate[TEST_EXT_LB_NUM_UART_BAUD_RATE];
extern UART_LEN gTestExtLbCharLen[TEST_EXT_LB_NUM_UART_CHAR_LEN];
extern UART_STOP gTestExtLbStopBits[TEST_EXT_LB_NUM_UART_STOP_BITS];
extern UART_PAR gTestExtLbParity[TEST_EXT_LB_NUM_UART_PARITY];

// Test UART settings for SW IP to SW IP external loopback testing
extern uint32_t gTestExtLbBaudRateSw2SwIp[TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP];
extern UART_LEN gTestExtLbCharLenSw2SwIp[TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP];
extern UART_STOP gTestExtLbStopBitsSw2SwIp[TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP];
extern UART_PAR gTestExtLbParitySw2SwIp[TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP];

// Test UART settings for SW IP to SW IP external loopback testing, HW flow control enabled
extern uint32_t gTestExtLbBaudRateSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP_HWFC];
extern UART_LEN gTestExtLbCharLenSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP_HWFC];
extern UART_STOP gTestExtLbStopBitsSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP_HWFC];
extern UART_PAR gTestExtLbParitySw2SwIpHwFc[TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP_HWFC];
extern uint8_t gTestExtLbHwFcThrSw2SwIpHwFc[TEST_EXT_LB_NUM_UART_HW_FC_THR_SW2SWIP_HWFC];

// Configures UART IO Pin Mux
bool configUartIoPinMux(UartIoPinMuxAttrs *pUartIoPinMuxAttrs);

// Prints test ID to string formatted for 16-bit chars
bool sprintTestId(
    int testId, 
    char testIdStr[], 
    uint8_t testIdStrSize
);
 
// Compares external loopback testing read/write data
bool compareExtLoopbackRdWrData(
    void  *data8b,
    uint16_t *data16b,
    uint32_t dataLen,
    UART_LEN charLen,
    bool cmp8b
);

//
// UART SW IP Stress Test parameters
//
#define TEST_STRESS_NUM_UART_LB_PAIR            ( 3 )       // number of UART loopback pairs
#define TEST_STRESS_LB_PAIR_PAIR0_IDX           ( 0 )       // Loopback Pair 0 index in UART instance table
#define TEST_STRESS_LB_PAIR_PAIR1_IDX           ( 1 )       // Loopback Pair 1 index in UART instance table
#define TEST_STRESS_LB_PAIR_PAIR2_IDX           ( 2 )       // Loopback Pair 2 index in UART instance table

#define TEST_STRESS_NUM_SIDE_PER_LB_PAIR        ( 2 )       // number of Sides (UARTs) per loopback pair
#define TEST_STRESS_LB_PAIR_SIDE0_IDX           ( 0 )       // Side 0 index in each pair
#define TEST_STRESS_LB_PAIR_SIDE1_IDX           ( 1 )       // Side 1 index in each pair

#define TEST_STRESS_NUM_UART                    ( TEST_STRESS_NUM_UART_LB_PAIR * TEST_STRESS_NUM_SIDE_PER_LB_PAIR ) // total number of UARTs in loopback
#define TEST_STRESS_P0_S0_IDX                   ( 0 )       // UART1 HW IP
#define TEST_STRESS_P0_S1_IDX                   ( 1 )       // PRU0 UART0 SW IP
#define TEST_STRESS_P1_S0_IDX                   ( 2 )       // PRU0 UART2 SW IP
#define TEST_STRESS_P1_S1_IDX                   ( 3 )       // PRU0 UART1 SW IP
#define TEST_STRESS_P2_S0_IDX                   ( 4 )       // PRU1 UART2 SW IP
#define TEST_STRESS_P2_S1_IDX                   ( 5 )       // PRU1 UART1 SW IP

// Task priorities
#define TEST_STRESS_MASTER_TASK_PRI_HIGH        ( 4 )       // Master task "high" priority setting -- higher than all Reader/Write task priorities
#define TEST_STRESS_MASTER_TASK_PRI_LOW         ( 1 )       // Master task "low" priority setting -- lower than all Reader/Write task priorities
#define TEST_STRESS_READER_TASK_PRI             ( 3 )       // Reader task(s) priority
#define TEST_STRESS_WRITER_TASK_PRI             ( 2 )       // Writer task(s) priority
#define TEST_STRESS_TASK_STACK_SZ               ( 1024 )    // Reader/Writer task stack size (bytes)

// Maximum read/write sizes
#define TEST_STRESS_MAX_RD_DATA_SZ              ( 512 )
#define TEST_STRESS_MAX_WR_DATA_SZ              ( 512 )

// Read test data
// 8-bit read data
extern char gTestStressRdData8b[TEST_STRESS_MAX_RD_DATA_SZ];
// 16-bit read data
extern uint16_t gTestStressRdData16b[TEST_STRESS_NUM_UART-1][TEST_STRESS_MAX_RD_DATA_SZ];

// UART configuration parameters
typedef struct TestStressUartCfgPrms_s {
    uint32_t        baudRate;           // baud rate
    UART_LEN        charLen;            // character length
    UART_STOP       stopBits;           // stop bits
    UART_PAR        parity;             // parity
    UART_FC_TYPE    flowControlType;    // flow control type
    uint8_t         hwFlowControlThr;   // hardware flow control threshold
} TestStressUartCfgPrms;

// UART transfer parameters
typedef struct TestStressUartXferPrms_s {
    uint32_t    numWrXfer;  // number of write transfers
    uint32_t    wrXferSz;   // size of write transfer
    uint32_t    numRdXfer;  // number of read transfers
    uint32_t    rdXferSz;   // size of read transfer
    void *      rdData;     // address of read data buffer
    void *      wrData;     // address of write data buffer
    bool        wrData8b;   // flag indicates whether write data is 8 or 16 bit
} TestStressUartXferPrms;

// UART instance ID table
//extern uint32_t gTestStressUartInstIdTable[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR];

// UART settings
extern TestStressUartCfgPrms gTestStressUartCfgPrms[TEST_STRESS_NUM_UART_LB_PAIR];

// UART transfer parameters
extern TestStressUartXferPrms gTestStressUartXferPrms[TEST_STRESS_NUM_UART_LB_PAIR][TEST_STRESS_NUM_SIDE_PER_LB_PAIR];


#ifdef __cplusplus
}
#endif

#endif /* _UART_TEST_UTILS_H */
