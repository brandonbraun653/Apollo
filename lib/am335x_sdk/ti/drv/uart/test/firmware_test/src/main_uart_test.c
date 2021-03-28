/**
 * @file   main_uart_test.c
 *
 * @brief  This file tests the UART driver APIs mode.
 */
/*
 * Copyright (c) 2014 - 2019, Texas Instruments Incorporated
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
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* CSL Header files */
#include <ti/csl/csl_chip.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/soc/UART_soc.h>

/* Board Header files */
#include <ti/board/board.h>
#include <ti/starterware/include/prcm.h>

#include "test/firmware_test/src/test_utils.h"


#define TEST_UART_INST_IDX0 ( 0 )   // Test UART instance index 0
#define TEST_UART_INST_IDX1 ( 1 )   // Test UART instance index 1
#define TEST_UART_INST_IDX2 ( 2 )   // Test UART instance index 2
#define TEST_UART_INST_IDX3 ( 3 )   // Test UART instance index 3
#define TEST_UART_INST_IDX4 ( 4 )   // Test UART instance index 4
#define TEST_UART_INST_IDX5 ( 5 )   // Test UART instance index 5
#define TEST_UART_INST_IDX6 ( 6 )   // Test UART instance index 6
#define MAX_NUM_UART_TEST   ( 7 )   // maximum number of UARTs for particular test

/* Define the UART test interface */
typedef struct UART_Tests_s
{
    int8_t      numUartTestInstance;                    // Number of UART SW IP test instances
    uint32_t    testUartInstance[MAX_NUM_UART_TEST];    // Test UART SW IP instance(s)
    bool        (*testFunc)(uint32_t, uint32_t[]);      // Test function
    int32_t     testId;                                 // Test ID
    char        testDesc[2*80];                         // Test description
} UART_Tests;

/* UART test ID definitions */
// PC UART tests
#define UART_TEST_ID_INT                                1   /* UART non-DMA read write test in block mode */
#define UART_TEST_ID_CB                                 2   /* UART non-DMA read write test in callback mode */
#define UART_TEST_ID_TO                                 3   /* UART non DMA timeout test */
#define UART_TEST_ID_RXERR                              4   /* UART non-DMA RX error test */
#define UART_TEST_ID_CANCEL                             5   /* UART non-DMA read write cancel test */
#define UART_TEST_ID_RW                                 6   /* UART non-DMA simultaneous read write test */
#define UART_TEST_ID_PRINTF                             7   /* UART stdio printf and scanf test */
#define UART_TEST_ID_POLL_TO                            8   /* UART read write polling timeout test */
#define UART_TEST_ID_STDIOPARAMS                        9   /* UART stdio printf and scanf test, with configurable params(Default params) */
#define UART_TEST_ID_INT_DISABLE                        10  /* UART read write test with interrupt disabled */

// External loopback tests
#define UART_TEST_ID_HWIP_WR_TO_SWIP_RD_BLK             11  /* UART HW IP write to SW IP read test in block mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP_WR_TO_HWIP_RD_BLK             12  /* UART SW IP write to HW IP read test in block mode, all UART settings, external loopback */
#define UART_TEST_ID_HWIP_WR_TO_SWIP_RD_CB              13  /* UART HW IP write to SW IP read test in callback mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP_WR_TO_HWIP_RD_CB              14  /* UART SW IP write to HW IP read test in callback mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_BLK           15  /* UART SW IP5 write to SW IP6 read test in blocking mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP3_WR_TO_SWIP2_RD_BLK           16  /* UART SW IP3 write to SW IP2 read test in blocking mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_CB            17  /* UART SW IP5 write to SW IP6 read test in callback mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP3_WR_TO_SWIP2_RD_CB            18  /* UART SW IP3 write to SW IP2 read test in callback mode, all UART settings, external loopback */
#define UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_CB_HWFC       19  /* UART SW IP5 write to SW IP6 read test in callback mode, all UART settings, HW flow control enabled, external loopback */
#define UART_TEST_ID_OPEN_CLOSE_SWIP                    20  /* UART open/close SW IP test */
#define UART_TEST_ID_STRESS_SWIP                        21  /* UART SWIP stress test */

/* UART test descriptions */
/* 
   Arrays used as 16-bit char arrays for PRU UART FW.
   Initialize 8-bit char arrays w/ space (ASCII 0x20) padding. 
*/
// PC UART tests
#define UART_TEST_DESC_INT \
    "\r \n   U A R T   r e a d   w r i t e   t e s t   i n   b l o c k   m o d e "
#define UART_TEST_DESC_CB \
    "\r \n   U A R T   r e a d   w r i t e   t e s t   i n   c a l l b a c k   m o d e "
#define UART_TEST_DESC_TO \
    "\r \n   U A R T   t i m e o u t   t e s t ,   w a i t   f o r   1 0   s e c o n d s   t o   t i m e o u t   r e a d "
#define UART_TEST_DESC_RXERR \
    "\r \n   U A R T   R X   e r r o r   t e s t ,   e n t e r   a   b r e a k "
#define UART_TEST_DESC_CANCEL \
    "\r \n   U A R T   r e a d   w r i t e   c a n c e l   t e s t ,   e n t e r   l e s s   t h a n   1 6   c h a r s "
#define UART_TEST_DESC_RW \
    "\r \n   U A R T   s i m u l t a n e o u s   r e a d   w r i t e   t e s t   "
#define UART_TEST_DESC_PRINTF \
    "\r \n   U A R T   s t d i o   p r i n t f   a n d   s c a n f   t e s t   "
#define UART_TEST_DESC_POLL_TO \
    "\r \n   U A R T   p o l l i n g   t i m e o u t   t e s t ,   w a i t   f o r   1 0   s e c o n d s   t o   t i m e o u t   r e a d "
#define UART_TEST_DESC_STDIOPARAMS \
    "\r \n   U A R T   s t d i o   p r i n t f   a n d   s c a n f   t e s t   w i t h   S T D I O   p a r a m s ( D e f a u l t )   "
#define UART_TEST_DESC_INT_DISABLE \
    "\r \n   U A R T   r e a d   w r i t e   t e s t   w i t h   i n t e r r u p t   d i s a b l e d "

// External loopback tests
#define UART_TEST_DESC_HWIP_WR_TO_SWIP_RD_BLK \
    "\r \n   U A R T   H W   I P   w r i t e   t o   S W   I P   r e a d   t e s t ,   B L K :   E x t   L B "
#define UART_TEST_DESC_SWIP_WR_TO_HWIP_RD_BLK \
    "\r \n   U A R T   S W   I P   w r i t e   t o   H W   I P   r e a d   t e s t ,   B L K :   E x t   L B "
#define UART_TEST_DESC_HWIP_WR_TO_SWIP_RD_CB  \
    "\r \n   U A R T   H W   I P   w r i t e   t o   S W   I P   r e a d   t e s t :   C B ,   E x t   L B "
#define UART_TEST_DESC_SWIP_WR_TO_HWIP_RD_CB \
    "\r \n   U A R T   S W   I P   w r i t e   t o   H W   I P   r e a d   t e s t :   C B ,   E x t   L B "
#define UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_BLK \
    "\r \n   U A R T   S W   I P 5   w r i t e   t o   S W   I P 6   r e a d   t e s t :   B L K ,   E x t   L B "
#define UART_TEST_DESC_SWIP3_WR_TO_SWIP2_RD_BLK \
    "\r \n   U A R T   S W   I P 3   w r i t e   t o   S W   I P 2   r e a d   t e s t :   B L K ,   E x t   L B "
#define UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_CB  \
    "\r \n   U A R T   S W   I P 5   w r i t e   t o   S W   I P 6   r e a d   t e s t :   C B ,   E x t   L B "
#define UART_TEST_DESC_SWIP3_WR_TO_SWIP2_RD_CB  \
"\r \n   U A R T   S W   I P 3   w r i t e   t o   S W   I P 2   r e a d   t e s t :   C B ,   E x t   L B "
#define UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_CB_HWFC \
"\r \n   U A R T   S W   I P 5   w r i t e   t o   S W   I P 6   r e a d   t e s t :   C B ,   H W   F C ,   E x t   L B "
#define UART_TEST_DESC_OPEN_CLOSE_SWIP  \
"\r \n   U A R T   o p e n / c l o s e   S W   I P   t e s t :   E x t   L B "
#define UART_TEST_DESC_STRESS_SWIP \
"\r \n   U A R T   S W   I P   s t r e s s   t e s t :   E x t   L B "

/* Determine size in 16-bit units */
#define SIZEOF16B(X)                    ( sizeof(X)/2 )

/* Time out value of read and write */
#define UART_TEST_TIMEOUT               ( 5000U )

/* Number of 16-bit chars to read for input */
#define UART_TEST_READ_LEN              ( 16U )

/* Prompt lengths in 8-bit chars */
#define SCAN_PROMPT_LEN_8B              ( 2*256 )
#define ECHO_PROMPT_LEN_8B              ( 2*40 )
#define DATA_PRINT_LEN_8B               ( 2*40 )
#define READ_TIMEOUT_PROMPT_LEN_8B      ( 2*60 )
#define BREAK_ERR_PROMPT_LEN_8B         ( 2*60 )
#define RD_CANCEL_PROMPT_LEN_8B         ( 2*60 )
#define WR_CANCEL_PROMPT_LEN_8B         ( 2*60 )

#define STDIO_PRINT_LEN_8B              ( 64 )

#define WRITE_POLL_TIMEOUT_PRINT_LEN_8B ( 2*136 )

// char scanPrompt[256] __attribute__ ((aligned (128)));
char scanPrompt[SCAN_PROMPT_LEN_8B] __attribute__ ((aligned (128)));

/* 
   Arrays used as 16-bit char arrays for PRU UART FW.
   Initialize 8-bit char arrays w/ space (ASCII 0x20) padding. 
*/
char echoPrompt[ECHO_PROMPT_LEN_8B] = "\n \r   D a t a   e n t e r e d   i s   a s   f o l l o w s   \r \n ";
char dataPrint[DATA_PRINT_LEN_8B] = "\r \n   e n t e r   t h e   d a t a   o f   1 6   c h a r a c t e r   \r \n ";
char readTimeoutPrompt[READ_TIMEOUT_PROMPT_LEN_8B] = "\r \n   R e a d   t i m e d   o u t   \r \n ";
char breakErrPrompt[BREAK_ERR_PROMPT_LEN_8B] = "\r \n   R e c e i v e d   a   b r e a k   c o n d i t i o n   e r r o r   \r \n ";
char rdCancelPrompt[RD_CANCEL_PROMPT_LEN_8B] = "\r \n   P r e v i o u s   r e a d   c a n c e l e d   \r \n ";
char wrCancelPrompt[WR_CANCEL_PROMPT_LEN_8B] = "\r \n   P r e v i o u s   w r i t e   c a n c e l e d   \r \n ";

char stdioPrint[STDIO_PRINT_LEN_8B] = "\r\n enter the data of 16 character and press ENTER \r\n";

char writePollTimeoutPrint[WRITE_POLL_TIMEOUT_PRINT_LEN_8B] = {
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
    'a', ' ', 'b', ' ', 'c', ' ', 'd', ' ', 'w', ' ', 'x', ' ', 'y', ' ', 'z', ' ', 
};

UART_Transaction  callbackTransaction;
SemaphoreP_Handle callbackSem = NULL;

// UART instance for test output
uint32_t testOutUartInstance = UART_TEST_INSTANCE4;

UART_PAR uartParity = UART_PAR_NONE;

bool Board_initUART(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    int32_t status;
    bool ret = true;

    /* 
       Initialize the UART PRU FW configuration.
       Place before Board_init() to allow configuration to include BOARD_INIT_UART_STDIO.
    */
    UART_socInitFwCfg();
    
    /* Initialize board */
    boardCfg = BOARD_INIT_PLL | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX;
    //boardCfg |= BOARD_INIT_UART_STDIO;
    //boardCfg |= BOARD_INIT_PINMUX_CONFIG;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        ret = false;
    }
    
    if (ret == true)
    {
        // Enable PRU-ICSS module
        status = PRCMModuleEnable(CHIPDB_MOD_ID_PRU_ICSS, 1U, 0U);
        if (status != S_PASS)
        {
            ret = false;
        }
    }
    
    if (ret == true)
    {
        // Enable UART1 HW module
        status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 1U, 0U);
        if (status != S_PASS)
        {
            ret = false;
        }
    }
    
    if (ret == true)
    {
        // Configure pinmux for UART1 HW IP
        ret = configUartIoPinMux(&gUartIoPinMuxAttrs);
    }

    return ret;
}

void UART_callback(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(callbackSem);
}

void UART_callback2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_osalPostLock(callbackSem);
}

//
// External loopback testing
//
UART_Transaction  gRdCallbackTransaction;
UART_Transaction  gWrCallbackTransaction;
SemaphoreP_Handle gRdCallbackSem = NULL;
SemaphoreP_Handle gWrCallbackSem = NULL;

void UART_rdCallback(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gRdCallbackSem);
}
void UART_rdCallback2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_osalPostLock(gRdCallbackSem);
}
void UART_wrCallback(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gWrCallbackSem);
}
void UART_wrCallback2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_osalPostLock(gWrCallbackSem);
}

//
// UART SW IP Stress Test
//

// Function prototypes
// HW IP writer task function -- 8-bit UART interface
Void UART_stress_hwip_reader(UArg a0, UArg a1);
// HW IP writer task function -- 8-bit UART interface
Void UART_stress_hwip_writer(UArg a0, UArg a1);
// SW IP reader task function -- 16-bit UART interface
Void UART_stress_swip_reader(UArg a0, UArg a1);
// SW IP reader task function -- 16-bit UART interface
Void UART_stress_swip_writer(UArg a0, UArg a1);

// Semaphores
SemaphoreP_Handle gTestStressRdCompleteSem = NULL;  // all Readers complete semaphore
SemaphoreP_Handle gTestStressRdCallbackSem[TEST_STRESS_NUM_UART] = {NULL};  // Reader semaphores
SemaphoreP_Handle gTestStressWrCallbackSem[TEST_STRESS_NUM_UART] = {NULL};  // Writer semaphores

// UART Reader Task functions
Void (*gUART_TestStressUartReaderFxn[TEST_STRESS_NUM_UART])(UArg a0, UArg a1) =
{
    &UART_stress_hwip_reader,
    &UART_stress_swip_reader,
    &UART_stress_swip_reader,
    &UART_stress_swip_reader,
    &UART_stress_swip_reader,
    &UART_stress_swip_reader,
};

// UART Writer Task functions
Void (*gUART_TestStressUartWriterFxn[TEST_STRESS_NUM_UART])(UArg a0, UArg a1) =
{
    &UART_stress_hwip_writer,
    &UART_stress_swip_writer,
    &UART_stress_swip_writer,
    &UART_stress_swip_writer,
    &UART_stress_swip_writer,
    &UART_stress_swip_writer,
};

// UART handles
UART_Handle gTestStressUartHandle[TEST_STRESS_NUM_UART] = {NULL};

// Callback transactions
UART_Transaction gTestStressRdCbTransaction[TEST_STRESS_NUM_UART];
UART_Transaction gTestStressWrCbTransaction[TEST_STRESS_NUM_UART];

// Reader Callback functions
void UART_TestStressRdCallbackP0S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P0_S0_IDX]);
}
void UART_TestStressRdCallbackP0S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P0_S1_IDX]);
}
void UART_TestStressRdCallbackP1S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P1_S0_IDX]);
}
void UART_TestStressRdCallbackP1S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P1_S1_IDX]);
}
void UART_TestStressRdCallbackP2S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P2_S0_IDX]);
}
void UART_TestStressRdCallbackP2S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressRdCallbackSem[TEST_STRESS_P2_S1_IDX]);
}
// Read callback function pointer table
void (*gUART_TestStressRdCallback[TEST_STRESS_NUM_UART])(UART_Handle handle, void *buf, size_t count) = 
{
    &UART_TestStressRdCallbackP0S0,
    &UART_TestStressRdCallbackP0S1,
    &UART_TestStressRdCallbackP1S0,
    &UART_TestStressRdCallbackP1S1,
    &UART_TestStressRdCallbackP2S0,
    &UART_TestStressRdCallbackP2S1,
};

// Writer Callback functions
void UART_TestStressWrCallbackP0S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P0_S0_IDX]);
}
void UART_TestStressWrCallbackP0S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P0_S1_IDX]);
}
void UART_TestStressWrCallbackP1S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P1_S0_IDX]);
}
void UART_TestStressWrCallbackP1S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P1_S1_IDX]);
}
void UART_TestStressWrCallbackP2S0(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P2_S0_IDX]);
}
void UART_TestStressWrCallbackP2S1(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(gTestStressWrCallbackSem[TEST_STRESS_P2_S1_IDX]);
}
// Write callback function pointer table
void (*gUART_TestStressWrCallback[TEST_STRESS_NUM_UART])(UART_Handle handle, void *buf, size_t count) = 
{
    &UART_TestStressWrCallbackP0S0,
    &UART_TestStressWrCallbackP0S1,
    &UART_TestStressWrCallbackP1S0,
    &UART_TestStressWrCallbackP1S1,
    &UART_TestStressWrCallbackP2S0,
    &UART_TestStressWrCallbackP2S1,
};

// Reader error returns
#define TEST_STRESS_RD_ERR_SOK                  ( 0 )
#define TEST_STRESS_RD_ERR_READ_FXN             ( 1 )
#define TEST_STRESS_RD_ERR_READ_SEM_PEND        ( 2 )
#define TEST_STRESS_RD_ERR_READ_CMP_DATA        ( 3 )
#define TEST_STRESS_RD_ERR_READ_COMPLETE_POST   ( 4 )

// Writer error returns
#define TEST_STRESS_WR_ERR_SOK                  ( 0 )
#define TEST_STRESS_WR_ERR_WRITE_FXN            ( 1 )
#define TEST_STRESS_WR_ERR_WRITE_SEM_PEND       ( 2 )

// Reader/Writer error returns
uint8_t gTestStressRdErr[TEST_STRESS_NUM_UART];
uint8_t gTestStressWrErr[TEST_STRESS_NUM_UART];

// Debug, Reader/Writer error returns
uint32_t gTestStressRdCnt[TEST_STRESS_NUM_UART];
uint32_t gTestStressWrCnt[TEST_STRESS_NUM_UART];


/*
 *  ======== UART stdio printf/scanf test ========
 *
 *  The test function tests stdio driver printf/scanf APIs
 */
static bool UART_test_printf_scanf(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t uartInst;
    bool ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    if (uartParity == UART_PAR_NONE)
    {
        UART_stdioInit(uartInst);

        UART_printf(stdioPrint);

        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_scanFmt(scanPrompt) != S_PASS)
        {
            goto Err;
        }

        ret = true;

Err:
        UART_stdioDeInit();
    }
    else
    {
        /*
         * bypass this test if the parity is not the default setting
         * (UART_PAR_NONE), since UART_stdioInit() only allows default
         * UART parameter settings.
         */
        ret = true;
    }

    return (ret);
}

/*
 *  ======== UART stdio printf/scanf test with param config (default) ========
 *
 *  The test function tests stdio driver printf/scanf APIs with default params config.
 */
static bool UART_test_printf_scanf_stdio_params(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t uartInst;
    bool    ret = false;
    UART_Params params;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* UART params */
    UART_Params_init(&params);
    params.parityType = uartParity;

    UART_stdioInit2(uartInst,&params);

    UART_printf(stdioPrint);

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (UART_scanFmt(scanPrompt) != S_PASS)
    {
        goto Err;
    }

    ret = true;

Err:
    UART_stdioDeInit();
    return (ret);
}

/* Use a global variable to sync the read task and the write task */
volatile bool taskSyncFlag;
Void UART_simultaneous_rw_write(UArg a0, UArg a1)
{
	UART_Handle      uart = (UART_Handle)a0;
    uint32_t         addrDataPrint;
    UART_Transaction transaction;

    addrDataPrint = (uint32_t)(uintptr_t)dataPrint;

    UART_transactionInit(&transaction);

    while (taskSyncFlag == true)
	{
        transaction.buf = (void *)(uintptr_t)addrDataPrint;
	    transaction.count = SIZEOF16B(dataPrint);
	    UART_write2(uart, &transaction);
	    Osal_delay(100);
	}

    /* resume the read test task */
    taskSyncFlag = true;

    Task_exit ();
}

/*
 *  ======== UART simultaneous read/write test ========
 *
 *  The read task creates a write task which will continuously
 *  writes the data out to the console, while at the same time
 *  the read task reads the data from the console input.
 *
 *  Note:
 *  In blocking/interrupt mode, if the write size is less than
 *  the TX FIFO size (64 bytes), the driver will just copy
 *  the write data to the TX FIFO and will not use interrupt
 *  and write semaphore. The read task should have a higher
 *  priority than the write task to resume the task by the
 *  scheduler once it gets the read semaphore.
 *
 */
static bool UART_test_simultaneous_rw(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    uint32_t         addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    Task_Handle      writeTask;
    Task_Params      writeTaskParams;
    Error_Block      eb;
    bool             ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* run the write teas when task is created */
    taskSyncFlag = true;

    Error_init(&eb);

    /* Initialize the task params */
    Task_Params_init(&writeTaskParams);
    writeTaskParams.arg0 = (UArg)uart;
    writeTaskParams.arg1 = (UArg)0;
    writeTaskParams.stackSize = 1024*8;
    /*
     * Set the write task priority to the default priority (1)
     * lower than the read task priority (2)
     */
    writeTaskParams.priority = 1;

    /* Create the UART write task */
    writeTask = Task_create((Task_FuncPtr)UART_simultaneous_rw_write, &writeTaskParams, &eb);
    if (writeTask == NULL)
    {
        System_abort("Task create failed");
        goto Err;
    }

    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;
    addrEchoPrompt = (uint32_t)(uintptr_t)echoPrompt;

    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
    	taskSyncFlag = false;
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
    	taskSyncFlag = false;
        goto Err;
    }

    /* stop the write test task */
    taskSyncFlag = false;

    /* Wait for the write task complete and exit */
    while (taskSyncFlag == false)
    {
        Osal_delay(100);
    }
    taskSyncFlag = false;

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = SIZEOF16B(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    Osal_delay(5000);

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART read cancel test ========
 *
 *  The test function uses console intput to simulate/test the
 *  read cancel in callback mode. In a real use case, user can
 *  read a large file from the console and cancel the read before
 *  the read is complete.
 *
 */
static bool UART_test_read_write_cancel(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t          uartInst;
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    SemaphoreP_Params semParams;
    UART_Transaction  transaction;
    uint32_t          addrRdCancelPrompt, addrWrCancelPrompt;
    uint32_t          addrDataPrint, addrEchoPrompt, addrScanPrompt;
    bool              ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Create call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    callbackSem = UART_osalCreateBlockingLock(0, &semParams);

    /* Set callback mode for read */
    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    addrRdCancelPrompt = (uint32_t)(uintptr_t)rdCancelPrompt;
    addrDataPrint = (uint32_t)(uintptr_t)dataPrint;
    addrEchoPrompt = (uint32_t)(uintptr_t)echoPrompt;
    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test receive error */

    /* Perform the first read, which will be cancelled before completion */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Delay for 10 seconds to allow user to enter chars */
    Osal_delay(10000);

    /* Cancel the read before the read transfer is completed */
    UART_readCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    /* Print read cancelled prompt */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrRdCancelPrompt;
    transaction.count = SIZEOF16B(rdCancelPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = SIZEOF16B(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Perform the 2nd read, which will be completed */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = SIZEOF16B(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Print the 2nd read chars, should NOT contain any chars
     * in the first cancelled read
     */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = SIZEOF16B(scanPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    UART_close(uart);

    /* write cancel test */

    /* Set callback mode for write */
    UART_Params_init(&uartParams);
    uartParams.writeCallback = UART_callback;
    uartParams.writeMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    addrWrCancelPrompt = (uint32_t)(uintptr_t)wrCancelPrompt;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Perform the 1st write */
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrWrCancelPrompt;
    callbackTransaction.count = SIZEOF16B(wrCancelPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Cancel the 1st write */
    UART_writeCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    /* Perform the 2nd write */
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrWrCancelPrompt;
    callbackTransaction.count = SIZEOF16B(wrCancelPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Cancel the write */
    UART_writeCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }
    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    if (callbackSem)
    {
    	UART_osalDeleteBlockingLock(callbackSem);
    	callbackSem = NULL;
    }
    return (ret);
}

/*
 *  ======== UART receive error test ========
 *
 *  The test function tests receive error (e.g. break condition)
 */
static bool UART_test_rx_err(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    UART_Transaction transaction;
    uint32_t         addrScanPrompt, addrBreakErrPrompt;
    bool             ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    addrBreakErrPrompt = (uint32_t)(uintptr_t)breakErrPrompt;
    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test receive error */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
    	if (transaction.status == UART_TRANSFER_STATUS_ERROR_BI)
    	{
    	    UART_transactionInit(&transaction);
            transaction.buf = (void *)(uintptr_t)addrBreakErrPrompt;
            transaction.count = SIZEOF16B(breakErrPrompt);
            if (UART_write2(uart, &transaction) == UART_ERROR)
            {
                goto Err;
            }
    	}
    	else
        {
            goto Err;
        }
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART timeout test ========
 *
 *  The test function tests read/write with OS timeout
 */
static bool UART_test_timeout(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    UART_Transaction transaction;
    uint32_t         addrScanPrompt, addrReadTimeoutPrompt;
    bool             ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    addrReadTimeoutPrompt = (uint32_t)(uintptr_t)readTimeoutPrompt;
    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read timeout */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    transaction.timeout = UART_TEST_TIMEOUT;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        UART_transactionInit(&transaction);
        transaction.buf = (void *)(uintptr_t)addrReadTimeoutPrompt;
        transaction.count = SIZEOF16B(readTimeoutPrompt);
        transaction.timeout = UART_TEST_TIMEOUT;
        if (UART_write2(uart, &transaction) == UART_ERROR)
        {
            goto Err;
        }
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART polling timeout test ========
 *
 *  The test function tests read/write with OS timeout in polling mode
 */
static bool UART_test_polling_timeout(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    bool             ret = false;
    uint32_t         rdSize = UART_TEST_READ_LEN;
    uint32_t         wrSize;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    /* timeout is 0 for read */
    uartParams.readTimeout  = UART_NO_WAIT;
    uartParams.writeTimeout = UART_WAIT_FOREVER;
    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
    {
        wrSize = SIZEOF16B(readTimeoutPrompt);
        UART_writePolling(uart, (const void *)readTimeoutPrompt, wrSize);
        ret = true;
    }
    
    if (ret == true)
    {
        ret = false;
        
        UART_close(uart);
        
        /* timeout is 0 for write */
        uartParams.readTimeout  = UART_NO_WAIT;
        uartParams.writeTimeout = UART_NO_WAIT;
        uart = UART_open(uartInst, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        /* Test write timeout */
        wrSize = SIZEOF16B(writePollTimeoutPrint);
        if (UART_writePolling(uart, (const void *)writePollTimeoutPrint, wrSize) != wrSize)
        {
            ret = true;
        }
    }
    
    if (ret == true)
    {
        ret = false;

        UART_close(uart);

        /* timeout is 5 seconds for both read and write */
        uartParams.readTimeout  = UART_TEST_TIMEOUT;
        uartParams.writeTimeout = UART_TEST_TIMEOUT;
        uart = UART_open(uartInst, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        /* Test read timeout */
        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
        {
            wrSize = SIZEOF16B(readTimeoutPrompt);
            UART_writePolling(uart, (const void *)readTimeoutPrompt, wrSize);
            ret = true;
        }
    }

    if (ret == true)
    {
        ret = false;

        UART_close(uart);

        /* timeout is 5 seconds for both read and write */
        uartParams.readTimeout  = UART_WAIT_FOREVER;
        uartParams.writeTimeout = UART_WAIT_FOREVER;
        uart = UART_open(uartInst, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        wrSize = SIZEOF16B(dataPrint);
        UART_writePolling(uart, (const void *)dataPrint, wrSize);

        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
        {
            goto Err;
        }

        wrSize = SIZEOF16B(echoPrompt);
        UART_writePolling(uart, (const void *)echoPrompt, wrSize);
        UART_writePolling(uart, (const void *)scanPrompt, rdSize);

        ret = true;
    }

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART callback test ========
 *
 *  The test function tests the read/write in callback mode
 */
static bool UART_test_callback(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t          uartInst;
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    SemaphoreP_Params semParams;
    uint32_t          addrScanPrompt, addrDataPrint, addrEchoPrompt;
    bool              ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Create call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    callbackSem = UART_osalCreateBlockingLock(0, &semParams);

    /* Test read/write API's in callback mode */

    /* Set callback mode for both read and write */
    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.writeCallback = UART_callback;
    uartParams.writeMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;
    addrDataPrint = (uint32_t)(uintptr_t)dataPrint;
    addrEchoPrompt = (uint32_t)(uintptr_t)echoPrompt;

    /* Write DMA or non-DMA test prompt */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, SIZEOF16B(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));

    if (UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.readTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, SIZEOF16B(echoPrompt)) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_close(uart);

    /* Test read2/write2 API's in callback mode */

    uartParams.readCallback2 = UART_callback2;
    uartParams.writeCallback2 = UART_callback2;
    uartParams.readCallback = NULL;
    uartParams.writeCallback = NULL;

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrDataPrint;
    callbackTransaction.count = SIZEOF16B(dataPrint);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    callbackTransaction.count = SIZEOF16B(echoPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }
    if (callbackSem)
    {
    	UART_osalDeleteBlockingLock(callbackSem);
    	callbackSem = NULL;
    }
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests read/write in blocking mode
 */
static bool UART_test_read_write(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    int              length = 0;
    uint32_t         addrDataPrint, addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    bool             ret = false;

    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    uart = UART_open(uartInst, &uartParams);

    if (uart == NULL)
    {
        goto Err;
    }

    addrDataPrint = (uint32_t)(uintptr_t)dataPrint;
    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;
    addrEchoPrompt = (uint32_t)(uintptr_t)echoPrompt;

    /* Test read/write API's in blocking mode */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, SIZEOF16B(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    length = UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN);
    if (length != UART_TEST_READ_LEN)
    {
        goto Err;
    }

    UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, SIZEOF16B(echoPrompt));

    UART_write(uart, (void *)(uintptr_t)addrScanPrompt, length);
    UART_close(uart);

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read2/write2 API's in blocking mode */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = SIZEOF16B(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = SIZEOF16B(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART read/write test with interrupt disabled ========
 *
 *  The test function tests read/write with interrupt disabled
 */
static bool UART_test_read_write_int_disable(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t         uartInst;
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    int              length = 0;
    uint32_t         addrDataPrint, addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    bool             ret = false;
    UART_SWIPAttrs   uart_cfg;
    
    uartInst = testUartInstance[TEST_UART_INST_IDX0]; // get UART instance ID
    
    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    /* Get the default UART init configurations */
    UART_socGetFwCfg(uartInst, &uart_cfg);
    uart_cfg.enableIntr=0; /* Disable interrupts */
    /* Get the default UART init configurations */
    UART_socSetFwCfg(uartInst, &uart_cfg);

    uart = UART_open(uartInst, &uartParams);

    if (uart == NULL)
    {
        goto Err;
    }

    addrDataPrint = (uint32_t)(uintptr_t)dataPrint;
    addrScanPrompt = (uint32_t)(uintptr_t)scanPrompt;
    addrEchoPrompt = (uint32_t)(uintptr_t)echoPrompt;

    /* Test read/write API's in blocking mode */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, SIZEOF16B(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    length = UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN);
    if (length != UART_TEST_READ_LEN)
    {
        goto Err;
    }

    UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, SIZEOF16B(echoPrompt));

    UART_write(uart, (void *)(uintptr_t)addrScanPrompt, length);
    UART_close(uart);

    uart = UART_open(uartInst, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read2/write2 API's in blocking mode */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = SIZEOF16B(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = SIZEOF16B(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    /* Get the default UART init configurations */
    UART_socGetFwCfg(uartInst, &uart_cfg);
    uart_cfg.enableIntr=1; /* Re-enable interrupt for remaining tests */
    /* Get the default UART init configurations */
    UART_socSetFwCfg(uartInst, &uart_cfg);

    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART HW IP write to UART SW IP read in blocking mode.
 *  Tests are performed for all combinations of UART settings.
 *      12 baud rate x 4 character length x 1 stop bit width x 3 parity x 2 API fxn = 288 tests.
 *      12 baud rate x 3 character length x 1 stop bit width x 3 parity x 2 API fxn = 216 tests.
 *      Total tests = 218 + 216 = 504 tests.
 */
static bool UART_test_hwip_write_to_swip_read_blk(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t hwIpUartWrInst;            // HW IP UART write instance ID
    uint32_t swIpUartRdInst;            // SW IP UART read instance ID
    UART_Handle hHwIpUartWrt = NULL;    // write UART handle
    UART_Handle hSwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    int length = 0;
    UART_Transaction transaction;    
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    hwIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    swIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    //
    // Test read/write API's in blocking mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
            {
                // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                    (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                    {
                        // initialize configuration params.
                        UART_Params_init(&uartParams);
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                        if (hSwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // open write UART instance
                        hHwIpUartWrt = UART_open(hwIpUartWrInst, &uartParams);
                        if (hHwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" write in blocking mode
                        if (UART_write(hHwIpUartWrt, (void *)gTestExtLoopbackWrData8b, TEST_EXT_LB_SMALL_WR_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" read in blocking mode
                        memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(uint16_t));
                        length = UART_read(hSwIpUartRd, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_SMALL_RD_SZ);
                        if (length != TEST_EXT_LB_SMALL_RD_SZ)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hSwIpUartRd);
                        hSwIpUartRd = NULL;
                        UART_close(hHwIpUartWrt);
                        hHwIpUartWrt = NULL;

                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData8b, gTestExtLoopbackRdData16b,
                            TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }                    
                    }
                }

                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hSwIpUartRd)
        {
            UART_close(hSwIpUartRd);
            hSwIpUartRd = NULL;
        }
        if (hHwIpUartWrt)
        {
            UART_close(hHwIpUartWrt);
            hHwIpUartWrt = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in blocking mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
                {
                    // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                    if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                        (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                    {
                        for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                        {
                            // initialize configuration params.
                            UART_Params_init(&uartParams);
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;
                            
                            // open read UART instance
                            hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                            if (hSwIpUartRd == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // open write UART instance
                            hHwIpUartWrt = UART_open(hwIpUartWrInst, &uartParams);
                            if (hHwIpUartWrt == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }

                            // perform "small" write in blocking mode
                            UART_transactionInit(&transaction);
                            transaction.buf = (void *)gTestExtLoopbackWrData8b;
                            transaction.count = TEST_EXT_LB_SMALL_WR_SZ;
                            if (UART_write2(hHwIpUartWrt, &transaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }

                            // perform "small" read in blocking mode        
                            memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(uint16_t));
                            UART_transactionInit(&transaction);
                            transaction.buf = (void *)gTestExtLoopbackRdData16b;
                            transaction.count = TEST_EXT_LB_SMALL_RD_SZ;
                            if (UART_read2(hSwIpUartRd, &transaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
                                (transaction.count != TEST_EXT_LB_SMALL_RD_SZ))
                            {
                                testLoopErr = true;
                                break;
                            }

                            // close read / write UART instances
                            UART_close(hSwIpUartRd);
                            hSwIpUartRd = NULL;
                            UART_close(hHwIpUartWrt);
                            hHwIpUartWrt = NULL;
                            
                            // compare read/write data
                            cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData8b, gTestExtLoopbackRdData16b, 
                                TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                            if (cmpStatus != true)
                            {
                                testLoopErr = true;
                                break;
                            }
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hSwIpUartRd)
            {
                UART_close(hSwIpUartRd);
                hSwIpUartRd = NULL;
            }
            if (hHwIpUartWrt)
            {
                UART_close(hHwIpUartWrt);
                hHwIpUartWrt = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART SW IP write to UART HW IP read in blocking mode.
 *  Tests are performed for all combinations of UART settings.
 *      12 baud rate x 4 character length x 1 stop bit width x 3 parity x 2 API fxn = 288 tests.
 *      12 baud rate x 3 character length x 1 stop bit width x 3 parity x 2 API fxn = 216 tests.
 *      Total tests = 218 + 216 = 504 tests.
 */
static bool UART_test_swip_write_to_hwip_read_blk(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartWrInst;            // SW IP UART write instance ID
    uint32_t hwIpUartRdInst;            // HW IP UART read instance ID
    UART_Handle hSwIpUartWrt = NULL;    // write UART handle
    UART_Handle hHwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    int length = 0;
    UART_Transaction transaction;    
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    swIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    hwIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    //
    // Test read/write API's in blocking mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
            {
                // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                    (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                    {
                        // initialize configuration params.
                        UART_Params_init(&uartParams);
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hHwIpUartRd = UART_open(hwIpUartRdInst, &uartParams);
                        if (hHwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // open write UART instance
                        hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                        if (hSwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" write in blocking mode
                        if (UART_write(hSwIpUartWrt, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_SMALL_WR_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" read in blocking mode
                        memset(gTestExtLoopbackRdData8b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(char));
                        length = UART_read(hHwIpUartRd, (void *)gTestExtLoopbackRdData8b, TEST_EXT_LB_SMALL_RD_SZ);
                        if (length != TEST_EXT_LB_SMALL_RD_SZ)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hHwIpUartRd);
                        hHwIpUartRd = NULL;
                        UART_close(hSwIpUartWrt);
                        hSwIpUartWrt = NULL;

                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData8b, gTestExtLoopbackWrData16b,
                            TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }                    
                    }
                }

                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hHwIpUartRd)
        {
            UART_close(hHwIpUartRd);
            hHwIpUartRd = NULL;
        }
        if (hSwIpUartWrt)
        {
            UART_close(hSwIpUartWrt);
            hSwIpUartWrt = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in blocking mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
                {
                    // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                    if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                        (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                    {
                        for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                        {
                            // initialize configuration params.
                            UART_Params_init(&uartParams);
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;
                            
                            // open read UART instance
                            hHwIpUartRd = UART_open(hwIpUartRdInst, &uartParams);
                            if (hHwIpUartRd == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // open write UART instance
                            hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                            if (hSwIpUartWrt == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }

                            // perform "small" write in blocking mode
                            UART_transactionInit(&transaction);
                            transaction.buf = (void *)gTestExtLoopbackWrData16b;
                            transaction.count = TEST_EXT_LB_SMALL_WR_SZ;
                            if (UART_write2(hSwIpUartWrt, &transaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }

                            // perform "small" read in blocking mode        
                            memset(gTestExtLoopbackRdData8b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(char));
                            UART_transactionInit(&transaction);
                            transaction.buf = (void *)gTestExtLoopbackRdData8b;
                            transaction.count = TEST_EXT_LB_SMALL_RD_SZ;
                            if (UART_read2(hHwIpUartRd, &transaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
                                (transaction.count != TEST_EXT_LB_SMALL_RD_SZ))
                            {
                                testLoopErr = true;
                                break;
                            }

                            // close read / write UART instances
                            UART_close(hHwIpUartRd);
                            hHwIpUartRd = NULL;
                            UART_close(hSwIpUartWrt);
                            hSwIpUartWrt = NULL;
                            
                            // compare read/write data
                            cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData8b, gTestExtLoopbackWrData16b, 
                                TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                            if (cmpStatus != true)
                            {
                                testLoopErr = true;
                                break;
                            }
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hHwIpUartRd)
            {
                UART_close(hHwIpUartRd);
                hHwIpUartRd = NULL;
            }
            if (hSwIpUartWrt)
            {
                UART_close(hSwIpUartWrt);
                hSwIpUartWrt = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART HW IP write to UART SW IP read in callback mode.
 *  Tests are performed for all combinations of UART settings.
 *      12 baud rate x 4 character length x 1 stop bit width x 3 parity x 2 API fxn = 288 tests.
 *      12 baud rate x 3 character length x 1 stop bit width x 3 parity x 2 API fxn = 216 tests.
 *      Total tests = 218 + 216 = 504 tests.
 */
static bool UART_test_hwip_write_to_swip_read_cb(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t hwIpUartWrInst;            // HW IP UART write instance ID
    uint32_t swIpUartRdInst;            // SW IP UART read instance ID
    UART_Handle hHwIpUartWrt = NULL;    // write UART handle
    UART_Handle hSwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    SemaphoreP_Params semParams;
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    hwIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    swIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    // create read call back semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gRdCallbackSem = UART_osalCreateBlockingLock(0, &semParams);

    // create write call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gWrCallbackSem = UART_osalCreateBlockingLock(0, &semParams);
    
    //
    // Test read/write API's in callback mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
            {
                // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                    (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                    {
                        // initialize configuration params.
                        // set callback mode for read
                        UART_Params_init(&uartParams);
                        uartParams.readMode = UART_MODE_CALLBACK;
                        uartParams.readCallback = UART_rdCallback;
                        uartParams.readCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];   // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];   // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];    // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];      // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                        if (hSwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // initialize configuration params.
                        // set callback mode for write
                        UART_Params_init(&uartParams);
                        uartParams.writeMode = UART_MODE_CALLBACK;
                        uartParams.writeCallback = UART_wrCallback;
                        uartParams.writeCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open write UART instance
                        hHwIpUartWrt = UART_open(hwIpUartWrInst, &uartParams);
                        if (hHwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));
                        
                        // perform "large" read in callback mode
                        if (UART_read(hSwIpUartRd, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_LARGE_RD_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // Perform "large" write in callback mode.
                        // Initiate read, don't Block on semaphore immediately after read API function call.
                        // Since chars not yet available, read must be completed using UART Rx HWI.
                        //
                        if (UART_write(hHwIpUartWrt, (void *)gTestExtLoopbackWrData8b, TEST_EXT_LB_LARGE_WR_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        if (UART_osalPendLock(gWrCallbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // wait for read completion    
                        if (UART_osalPendLock(gRdCallbackSem, uartParams.readTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hSwIpUartRd);
                        hSwIpUartRd = NULL;
                        UART_close(hHwIpUartWrt);
                        hHwIpUartWrt = NULL;

                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData8b, gTestExtLoopbackRdData16b,
                            TEST_EXT_LB_LARGE_WR_SZ, gTestExtLbCharLen[charLenIdx], true);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }      
                    }
                }
                
                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hSwIpUartRd)
        {
            UART_close(hSwIpUartRd);
            hSwIpUartRd = NULL;
        }
        if (hHwIpUartWrt)
        {
            UART_close(hHwIpUartWrt);
            hHwIpUartWrt = NULL;
        }

        if (gRdCallbackSem)
        {
            UART_osalDeleteBlockingLock(gRdCallbackSem);
            gRdCallbackSem = NULL;
        }
        if (gWrCallbackSem)
        {
            UART_osalDeleteBlockingLock(gWrCallbackSem);
            gWrCallbackSem = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in callback mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
                {
                    // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                    if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                        (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                    {
                        for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                        {
                            // initialize configuration params.
                            // set callback mode for read
                            UART_Params_init(&uartParams);
                            uartParams.readMode = UART_MODE_CALLBACK;
                            uartParams.readCallback = NULL;
                            uartParams.readCallback2 = UART_rdCallback2;
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;
                            
                            // open read UART instance
                            hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                            if (hSwIpUartRd == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // initialize configuration params.
                            // set callback mode for write
                            UART_Params_init(&uartParams);
                            uartParams.writeMode = UART_MODE_CALLBACK;
                            uartParams.writeCallback = NULL;
                            uartParams.writeCallback2 = UART_wrCallback2;
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;

                            // open write UART instance
                            hHwIpUartWrt = UART_open(hwIpUartWrInst, &uartParams);
                            if (hHwIpUartWrt == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }

                            memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));

                            // Perform "large" read in callback mode.
                            // Initiate read, don't Block on semaphore immediately after read API function call.
                            // Since chars not yet available, read must be completed using UART Rx HWI.
                            //
                            UART_transactionInit(&gRdCallbackTransaction);
                            gRdCallbackTransaction.buf = (void *)gTestExtLoopbackRdData16b;
                            gRdCallbackTransaction.count = TEST_EXT_LB_LARGE_RD_SZ;
                            if (UART_read2(hSwIpUartRd, &gRdCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            
                            // perform "large" write in callback mode.
                            UART_transactionInit(&gWrCallbackTransaction);
                            gWrCallbackTransaction.buf = (void *)gTestExtLoopbackWrData8b;
                            gWrCallbackTransaction.count = TEST_EXT_LB_LARGE_WR_SZ;
                            if (UART_write2(hHwIpUartWrt, &gWrCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            if (UART_osalPendLock(gWrCallbackSem, gWrCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // wait for read completion
                            if (UART_osalPendLock(gRdCallbackSem, gRdCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }                    

                            // close read / write UART instances
                            UART_close(hSwIpUartRd);
                            hSwIpUartRd = NULL;
                            UART_close(hHwIpUartWrt);
                            hHwIpUartWrt = NULL;
                            
                            // compare read/write data
                            cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData8b, gTestExtLoopbackRdData16b, 
                                TEST_EXT_LB_LARGE_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                            if (cmpStatus != true)
                            {
                                testLoopErr = true;
                                break;
                            }
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hSwIpUartRd)
            {
                UART_close(hSwIpUartRd);
                hSwIpUartRd = NULL;
            }
            if (hHwIpUartWrt)
            {
                UART_close(hHwIpUartWrt);
                hHwIpUartWrt = NULL;
            }
            
            if (gRdCallbackSem)
            {
                UART_osalDeleteBlockingLock(gRdCallbackSem);
                gRdCallbackSem = NULL;
            }
            if (gWrCallbackSem)
            {
                UART_osalDeleteBlockingLock(gWrCallbackSem);
                gWrCallbackSem = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART SW IP write to UART HW IP read in callback mode.
 *  Tests are performed for all combinations of UART settings.
 *      12 baud rate x 4 character length x 1 stop bit width x 3 parity x 2 API fxn = 288 tests.
 *      12 baud rate x 3 character length x 1 stop bit width x 3 parity x 2 API fxn = 216 tests.
 *      Total tests = 218 + 216 = 504 tests.
 */
static bool UART_test_swip_write_to_hwip_read_cb(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartWrInst;            // SW IP UART write instance ID
    uint32_t hwIpUartRdInst;            // HW IP UART read instance ID
    UART_Handle hSwIpUartWrt = NULL;    // write UART handle
    UART_Handle hHwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    SemaphoreP_Params semParams;
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    swIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    hwIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    // create read call back semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gRdCallbackSem = UART_osalCreateBlockingLock(0, &semParams);

    // create write call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gWrCallbackSem = UART_osalCreateBlockingLock(0, &semParams);
    
    //
    // Test read/write API's in callback mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
            {
                // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                    (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                    {
                        // initialize configuration params.
                        // set callback mode for read
                        UART_Params_init(&uartParams);
                        uartParams.readMode = UART_MODE_CALLBACK;
                        uartParams.readCallback = UART_rdCallback;
                        uartParams.readCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];   // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];   // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];    // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];      // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hHwIpUartRd = UART_open(hwIpUartRdInst, &uartParams);
                        if (hHwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // initialize configuration params.
                        // set callback mode for write
                        UART_Params_init(&uartParams);
                        uartParams.writeMode = UART_MODE_CALLBACK;
                        uartParams.writeCallback = UART_wrCallback;
                        uartParams.writeCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open write UART instance
                        hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                        if (hSwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        memset(gTestExtLoopbackRdData8b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(char));
                        
                        // perform "large" read in callback mode
                        if (UART_read(hHwIpUartRd, (void *)gTestExtLoopbackRdData8b, TEST_EXT_LB_LARGE_RD_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // Perform "large" write in callback mode.
                        // Initiate read, don't Block on semaphore immediately after read API function call.
                        // Since chars not yet available, read must be completed using UART Rx HWI.
                        //
                        if (UART_write(hSwIpUartWrt, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_LARGE_WR_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        if (UART_osalPendLock(gWrCallbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // wait for read completion    
                        if (UART_osalPendLock(gRdCallbackSem, uartParams.readTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hHwIpUartRd);
                        hHwIpUartRd = NULL;
                        UART_close(hSwIpUartWrt);
                        hSwIpUartWrt = NULL;

                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData8b, gTestExtLoopbackWrData16b,
                            TEST_EXT_LB_LARGE_WR_SZ, gTestExtLbCharLen[charLenIdx], true);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }      
                    }
                }
                
                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hHwIpUartRd)
        {
            UART_close(hHwIpUartRd);
            hHwIpUartRd = NULL;
        }
        if (hSwIpUartWrt)
        {
            UART_close(hSwIpUartWrt);
            hSwIpUartWrt = NULL;
        }

        if (gRdCallbackSem)
        {
            UART_osalDeleteBlockingLock(gRdCallbackSem);
            gRdCallbackSem = NULL;
        }
        if (gWrCallbackSem)
        {
            UART_osalDeleteBlockingLock(gWrCallbackSem);
            gWrCallbackSem = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in callback mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS))
                {
                    // Skip character length==5 & Stop bit duration==2 since this isn't supported by UART HW IP
                    if ((gTestExtLbCharLen[charLenIdx] != UART_LEN_5) ||
                        (gTestExtLbStopBits[stopBitsIdx] != UART_STOP_TWO))
                    {
                        for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY; parityIdx++)
                        {
                            // initialize configuration params.
                            // set callback mode for read
                            UART_Params_init(&uartParams);
                            uartParams.readMode = UART_MODE_CALLBACK;
                            uartParams.readCallback = NULL;
                            uartParams.readCallback2 = UART_rdCallback2;
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;
                            
                            // open read UART instance
                            hHwIpUartRd = UART_open(hwIpUartRdInst, &uartParams);
                            if (hHwIpUartRd == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // initialize configuration params.
                            // set callback mode for write
                            UART_Params_init(&uartParams);
                            uartParams.writeMode = UART_MODE_CALLBACK;
                            uartParams.writeCallback = NULL;
                            uartParams.writeCallback2 = UART_wrCallback2;
                            uartParams.baudRate = gTestExtLbBaudRate[baudRateIdx];  // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLen[charLenIdx];  // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBits[stopBitsIdx];  // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParity[parityIdx];    // set parity for test loop
                            uartParams.flowControlType = UART_FC_NONE;
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;

                            // open write UART instance
                            hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                            if (hSwIpUartWrt == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }

                            memset(gTestExtLoopbackRdData8b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(char));

                            // Perform "large" read in callback mode.
                            // Initiate read, don't Block on semaphore immediately after read API function call.
                            // Since chars not yet available, read must be completed using UART Rx HWI.
                            //
                            UART_transactionInit(&gRdCallbackTransaction);
                            gRdCallbackTransaction.buf = (void *)gTestExtLoopbackRdData8b;
                            gRdCallbackTransaction.count = TEST_EXT_LB_LARGE_RD_SZ;
                            if (UART_read2(hHwIpUartRd, &gRdCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            
                            // perform "large" write in callback mode.
                            UART_transactionInit(&gWrCallbackTransaction);
                            gWrCallbackTransaction.buf = (void *)gTestExtLoopbackWrData16b;
                            gWrCallbackTransaction.count = TEST_EXT_LB_LARGE_WR_SZ;
                            if (UART_write2(hSwIpUartWrt, &gWrCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            if (UART_osalPendLock(gWrCallbackSem, gWrCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // wait for read completion
                            if (UART_osalPendLock(gRdCallbackSem, gRdCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }                    

                            // close read / write UART instances
                            UART_close(hHwIpUartRd);
                            hHwIpUartRd = NULL;
                            UART_close(hSwIpUartWrt);
                            hSwIpUartWrt = NULL;
                            
                            // compare read/write data
                            cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData8b, gTestExtLoopbackWrData16b, 
                                TEST_EXT_LB_LARGE_RD_SZ, gTestExtLbCharLen[charLenIdx], true);
                            if (cmpStatus != true)
                            {
                                testLoopErr = true;
                                break;
                            }
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hHwIpUartRd)
            {
                UART_close(hHwIpUartRd);
                hHwIpUartRd = NULL;
            }
            if (hSwIpUartWrt)
            {
                UART_close(hSwIpUartWrt);
                hSwIpUartWrt = NULL;
            }
            
            if (gRdCallbackSem)
            {
                UART_osalDeleteBlockingLock(gRdCallbackSem);
                gRdCallbackSem = NULL;
            }
            if (gWrCallbackSem)
            {
                UART_osalDeleteBlockingLock(gWrCallbackSem);
                gWrCallbackSem = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART SW IP write to UART SW IP read in blocking mode.
 *  Tests are performed for all combinations of UART settings, including SW IP only settings:
 *      - 9-bit character length
 *      - 1.5 stop bit width
 *
 *      12 baud rate x 5 character length x 3 stop bit width x 3 parity x 2 API fxn = 1080 tests.
 */
static bool UART_test_swip_write_to_swip_read_blk(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartWrInst;            // SW IP UART write instance ID
    uint32_t swIpUartRdInst;            // SW IP UART read instance ID
    UART_Handle hSwIpUartWrt = NULL;    // write UART handle
    UART_Handle hSwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    int length = 0;
    UART_Transaction transaction;    
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    swIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    swIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    //
    // Test read/write API's in blocking mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP))
            {
                for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP; parityIdx++)
                {
                    // initialize configuration params.
                    UART_Params_init(&uartParams);
                    uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                    uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                    uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                    uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                    uartParams.flowControlType = UART_FC_NONE;
                    uartParams.readReturnMode = UART_RETURN_FULL;
                    uartParams.readDataMode = UART_DATA_BINARY;
                    uartParams.writeDataMode = UART_DATA_BINARY;
                    
                    // open read UART instance
                    hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                    if (hSwIpUartRd == NULL)
                    {
                        testLoopErr = true;
                        break;
                    }
                    
                    // open write UART instance
                    hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                    if (hSwIpUartWrt == NULL)
                    {
                        testLoopErr = true;
                        break;
                    }

                    // perform "small" write in blocking mode
                    if (UART_write(hSwIpUartWrt, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_SMALL_WR_SZ) == UART_ERROR)
                    {
                        testLoopErr = true;
                        break;
                    }

                    // perform "small" read in blocking mode
                    memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(uint16_t));
                    length = UART_read(hSwIpUartRd, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_SMALL_RD_SZ);
                    if (length != TEST_EXT_LB_SMALL_RD_SZ)
                    {
                        testLoopErr = true;
                        break;
                    }

                    // close read / write UART instances
                    UART_close(hSwIpUartRd);
                    hSwIpUartRd = NULL;
                    UART_close(hSwIpUartWrt);
                    hSwIpUartWrt = NULL;

                    // compare read/write data
                    cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b,
                        TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLenSw2SwIp[charLenIdx], false);
                    if (cmpStatus != true)
                    {
                        testLoopErr = true;
                        break;
                    }                    
                }

                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hSwIpUartRd)
        {
            UART_close(hSwIpUartRd);
            hSwIpUartRd = NULL;
        }
        if (hSwIpUartWrt)
        {
            UART_close(hSwIpUartWrt);
            hSwIpUartWrt = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in blocking mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP; parityIdx++)
                    {
                        // initialize configuration params.
                        UART_Params_init(&uartParams);
                        uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                        if (hSwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // open write UART instance
                        hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                        if (hSwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" write in blocking mode
                        UART_transactionInit(&transaction);
                        transaction.buf = (void *)gTestExtLoopbackWrData16b;
                        transaction.count = TEST_EXT_LB_SMALL_WR_SZ;
                        if (UART_write2(hSwIpUartWrt, &transaction) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // perform "small" read in blocking mode        
                        memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(uint16_t));
                        UART_transactionInit(&transaction);
                        transaction.buf = (void *)gTestExtLoopbackRdData16b;
                        transaction.count = TEST_EXT_LB_SMALL_RD_SZ;
                        if (UART_read2(hSwIpUartRd, &transaction) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
                            (transaction.count != TEST_EXT_LB_SMALL_RD_SZ))
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hSwIpUartRd);
                        hSwIpUartRd = NULL;
                        UART_close(hSwIpUartWrt);
                        hSwIpUartWrt = NULL;
                        
                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b, 
                            TEST_EXT_LB_SMALL_RD_SZ, gTestExtLbCharLenSw2SwIp[charLenIdx], false);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hSwIpUartRd)
            {
                UART_close(hSwIpUartRd);
                hSwIpUartRd = NULL;
            }
            if (hSwIpUartWrt)
            {
                UART_close(hSwIpUartWrt);
                hSwIpUartWrt = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART SW IP write to UART SW IP read in callback mode.
 *  Tests are performed for all combinations of UART settings, including SW IP only settings:
 *      - 9-bit character length
 *      - 1.5 stop bit width
 *   12 baud rate x 5 character length x 3 stop bit width x 3 parity x 2 API fxn = 1080 tests.
 *
 *  Hardware flow control is disabled.
 */
static bool UART_test_swip_write_to_swip_read_cb(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartWrInst;            // SW IP UART write instance ID
    uint32_t swIpUartRdInst;            // SW IP UART read instance ID
    UART_Handle hSwIpUartWrt = NULL;    // write UART handle
    UART_Handle hSwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    SemaphoreP_Params semParams;
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx;
    bool testLoopErr, cmpStatus, ret;

    swIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    swIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    // create read call back semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gRdCallbackSem = UART_osalCreateBlockingLock(0, &semParams);

    // create write call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gWrCallbackSem = UART_osalCreateBlockingLock(0, &semParams);
    
    //
    // Test read/write API's in callback mode.
    // Loop over all UART settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP))
            {
                for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP; parityIdx++)
                {
                    // initialize configuration params.
                    // set callback mode for read
                    UART_Params_init(&uartParams);
                    uartParams.readMode = UART_MODE_CALLBACK;
                    uartParams.readCallback = UART_rdCallback;
                    uartParams.readCallback2 = NULL;
                    uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                    uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                    uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                    uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                    uartParams.flowControlType = UART_FC_NONE;
                    uartParams.readReturnMode = UART_RETURN_FULL;
                    uartParams.readDataMode = UART_DATA_BINARY;
                    uartParams.writeDataMode = UART_DATA_BINARY;
                    
                    // open read UART instance
                    hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                    if (hSwIpUartRd == NULL)
                    {
                        testLoopErr = true;
                        break;
                    }
                    
                    // initialize configuration params.
                    // set callback mode for write
                    UART_Params_init(&uartParams);
                    uartParams.writeMode = UART_MODE_CALLBACK;
                    uartParams.writeCallback = UART_wrCallback;
                    uartParams.writeCallback2 = NULL;
                    uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                    uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                    uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                    uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                    uartParams.flowControlType = UART_FC_NONE;
                    uartParams.readReturnMode = UART_RETURN_FULL;
                    uartParams.readDataMode = UART_DATA_BINARY;
                    uartParams.writeDataMode = UART_DATA_BINARY;
                    
                    // open write UART instance
                    hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                    if (hSwIpUartWrt == NULL)
                    {
                        testLoopErr = true;
                        break;
                    }

                    memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));
                    
                    // perform "large" read in callback mode
                    if (UART_read(hSwIpUartRd, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_LARGE_RD_SZ) == UART_ERROR)
                    {
                        testLoopErr = true;
                        break;
                    }
                    
                    // Perform "large" write in callback mode.
                    // Initiate read, don't Block on semaphore immediately after read API function call.
                    // Since chars not yet available, read must be completed using UART Rx HWI.
                    //
                    if (UART_write(hSwIpUartWrt, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_LARGE_WR_SZ) == UART_ERROR)
                    {
                        testLoopErr = true;
                        break;
                    }
                    if (UART_osalPendLock(gWrCallbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
                    {
                        testLoopErr = true;
                        break;
                    }

                    // wait for read completion    
                    if (UART_osalPendLock(gRdCallbackSem, uartParams.readTimeout) != SemaphoreP_OK)
                    {
                        testLoopErr = true;
                        break;
                    }

                    // close read / write UART instances
                    UART_close(hSwIpUartRd);
                    hSwIpUartRd = NULL;
                    UART_close(hSwIpUartWrt);
                    hSwIpUartWrt = NULL;

                    // compare read/write data
                    cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b,
                        TEST_EXT_LB_LARGE_WR_SZ, gTestExtLbCharLenSw2SwIp[charLenIdx], false);
                    if (cmpStatus != true)
                    {
                        testLoopErr = true;
                        break;
                    }      
                }

                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hSwIpUartRd)
        {
            UART_close(hSwIpUartRd);
            hSwIpUartRd = NULL;
        }
        if (hSwIpUartWrt)
        {
            UART_close(hSwIpUartWrt);
            hSwIpUartWrt = NULL;
        }

        if (gRdCallbackSem)
        {
            UART_osalDeleteBlockingLock(gRdCallbackSem);
            gRdCallbackSem = NULL;
        }
        if (gWrCallbackSem)
        {
            UART_osalDeleteBlockingLock(gWrCallbackSem);
            gWrCallbackSem = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in callback mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP))
                {
                    for (parityIdx = 0; parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP; parityIdx++)
                    {
                        // initialize configuration params.
                        // set callback mode for read
                        UART_Params_init(&uartParams);
                        uartParams.readMode = UART_MODE_CALLBACK;
                        uartParams.readCallback = NULL;
                        uartParams.readCallback2 = UART_rdCallback2;
                        uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                        if (hSwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // initialize configuration params.
                        // set callback mode for write
                        UART_Params_init(&uartParams);
                        uartParams.writeMode = UART_MODE_CALLBACK;
                        uartParams.writeCallback = NULL;
                        uartParams.writeCallback2 = UART_wrCallback2;
                        uartParams.baudRate = gTestExtLbBaudRateSw2SwIp[baudRateIdx];   // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLenSw2SwIp[charLenIdx];   // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBitsSw2SwIp[stopBitsIdx];   // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParitySw2SwIp[parityIdx];     // set parity for test loop
                        uartParams.flowControlType = UART_FC_NONE;
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;

                        // open write UART instance
                        hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                        if (hSwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));

                        // Perform "large" read in callback mode.
                        // Initiate read, don't Block on semaphore immediately after read API function call.
                        // Since chars not yet available, read must be completed using UART Rx HWI.
                        //
                        UART_transactionInit(&gRdCallbackTransaction);
                        gRdCallbackTransaction.buf = (void *)gTestExtLoopbackRdData16b;
                        gRdCallbackTransaction.count = TEST_EXT_LB_LARGE_RD_SZ;
                        if (UART_read2(hSwIpUartRd, &gRdCallbackTransaction) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        
                        // perform "large" write in callback mode.
                        UART_transactionInit(&gWrCallbackTransaction);
                        gWrCallbackTransaction.buf = (void *)gTestExtLoopbackWrData16b;
                        gWrCallbackTransaction.count = TEST_EXT_LB_LARGE_WR_SZ;
                        if (UART_write2(hSwIpUartWrt, &gWrCallbackTransaction) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        if (UART_osalPendLock(gWrCallbackSem, gWrCallbackTransaction.timeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // wait for read completion
                        if (UART_osalPendLock(gRdCallbackSem, gRdCallbackTransaction.timeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }                    

                        // close read / write UART instances
                        UART_close(hSwIpUartRd);
                        hSwIpUartRd = NULL;
                        UART_close(hSwIpUartWrt);
                        hSwIpUartWrt = NULL;
                        
                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b, 
                            TEST_EXT_LB_LARGE_RD_SZ, gTestExtLbCharLenSw2SwIp[charLenIdx], false);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hSwIpUartRd)
            {
                UART_close(hSwIpUartRd);
                hSwIpUartRd = NULL;
            }
            if (hSwIpUartWrt)
            {
                UART_close(hSwIpUartWrt);
                hSwIpUartWrt = NULL;
            }
            
            if (gRdCallbackSem)
            {
                UART_osalDeleteBlockingLock(gRdCallbackSem);
                gRdCallbackSem = NULL;
            }
            if (gWrCallbackSem)
            {
                UART_osalDeleteBlockingLock(gWrCallbackSem);
                gWrCallbackSem = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests UART SW IP write to UART SW IP read in callback mode.
 *  Tests are performed for all combinations of UART settings, including SW IP only settings:
 *      - 9-bit character length
 *      - 1.5 stop bit width
 *   12 baud rate x 5 character length x 3 stop bit width x 3 parity x 4 HW FC thresholds x 2 API fxn = 4320 tests.
 *
 *  Hardware flow control is enabled.
 */
static bool UART_test_swip_write_to_swip_read_cb_hwfc(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartWrInst;            // SW IP UART write instance ID
    uint32_t swIpUartRdInst;            // SW IP UART read instance ID
    UART_Handle hSwIpUartWrt = NULL;    // write UART handle
    UART_Handle hSwIpUartRd = NULL;     // read UART handle
    UART_Params uartParams;
    SemaphoreP_Params semParams;
    uint8_t baudRateIdx, charLenIdx, stopBitsIdx, parityIdx, hwFcThrIdx;
    bool testLoopErr, cmpStatus, ret;

    swIpUartWrInst = testUartInstance[TEST_UART_INST_IDX0]; // get write UART instance ID
    swIpUartRdInst = testUartInstance[TEST_UART_INST_IDX1]; // get read UART instance ID

    // create read call back semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gRdCallbackSem = UART_osalCreateBlockingLock(0, &semParams);

    // create write call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gWrCallbackSem = UART_osalCreateBlockingLock(0, &semParams);
    
    //
    // Test read/write API's in callback mode.
    // Loop over all line & hardware flow control threshold settings.
    //
    testLoopErr = false;
    baudRateIdx = 0;
    while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP_HWFC))
    {
        charLenIdx = 0;
        while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP_HWFC))
        {
            stopBitsIdx = 0;
            while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP_HWFC))
            {
                parityIdx = 0;
                while ((testLoopErr == false) && (parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP_HWFC))
                {
                    for (hwFcThrIdx = 0; hwFcThrIdx < TEST_EXT_LB_NUM_UART_HW_FC_THR_SW2SWIP_HWFC; hwFcThrIdx++)
                    {
                        // initialize configuration params.
                        // set callback mode for read
                        UART_Params_init(&uartParams);
                        uartParams.readMode = UART_MODE_CALLBACK;
                        uartParams.readCallback = UART_rdCallback;
                        uartParams.readCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRateSw2SwIpHwFc[baudRateIdx];       // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLenSw2SwIpHwFc[charLenIdx];       // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBitsSw2SwIpHwFc[stopBitsIdx];       // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParitySw2SwIpHwFc[parityIdx];         // set parity for test loop
                        uartParams.flowControlType = UART_FC_HW;                                // enable hardware flow control
                        uartParams.hwFlowControlThr = gTestExtLbHwFcThrSw2SwIpHwFc[hwFcThrIdx]; // set hardware flow control threshold
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open read UART instance
                        hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                        if (hSwIpUartRd == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // initialize configuration params.
                        // set callback mode for write
                        UART_Params_init(&uartParams);
                        uartParams.writeMode = UART_MODE_CALLBACK;
                        uartParams.writeCallback = UART_wrCallback;
                        uartParams.writeCallback2 = NULL;
                        uartParams.baudRate = gTestExtLbBaudRateSw2SwIpHwFc[baudRateIdx];       // set baud rate for test loop
                        uartParams.dataLength = gTestExtLbCharLenSw2SwIpHwFc[charLenIdx];       // set character length for test loop
                        uartParams.stopBits = gTestExtLbStopBitsSw2SwIpHwFc[stopBitsIdx];       // set number of stop bits for test loop
                        uartParams.parityType = gTestExtLbParitySw2SwIpHwFc[parityIdx];         // set parity for test loop
                        uartParams.flowControlType = UART_FC_HW;                                // enable hardware flow control
                        uartParams.hwFlowControlThr = gTestExtLbHwFcThrSw2SwIpHwFc[hwFcThrIdx]; // set hardware flow control threshold
                        uartParams.readReturnMode = UART_RETURN_FULL;
                        uartParams.readDataMode = UART_DATA_BINARY;
                        uartParams.writeDataMode = UART_DATA_BINARY;
                        
                        // open write UART instance
                        hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                        if (hSwIpUartWrt == NULL)
                        {
                            testLoopErr = true;
                            break;
                        }

                        memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));
                        
                        // perform "large" read in callback mode
                        if (UART_read(hSwIpUartRd, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_LARGE_RD_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        
                        // Perform "large" write in callback mode.
                        // Initiate read, don't Block on semaphore immediately after read API function call.
                        // Since chars not yet available, read must be completed using UART Rx HWI.
                        //
                        if (UART_write(hSwIpUartWrt, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_LARGE_WR_SZ) == UART_ERROR)
                        {
                            testLoopErr = true;
                            break;
                        }
                        if (UART_osalPendLock(gWrCallbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // wait for read completion    
                        if (UART_osalPendLock(gRdCallbackSem, uartParams.readTimeout) != SemaphoreP_OK)
                        {
                            testLoopErr = true;
                            break;
                        }

                        // close read / write UART instances
                        UART_close(hSwIpUartRd);
                        hSwIpUartRd = NULL;
                        UART_close(hSwIpUartWrt);
                        hSwIpUartWrt = NULL;

                        // compare read/write data
                        cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b,
                            TEST_EXT_LB_LARGE_WR_SZ, gTestExtLbCharLenSw2SwIpHwFc[charLenIdx], false);
                        if (cmpStatus != true)
                        {
                            testLoopErr = true;
                            break;
                        }      
                        
                    }
                    
                    if (testLoopErr == false)
                    {
                        parityIdx++;
                    }
                }

                if (testLoopErr == false)
                {                
                    stopBitsIdx++;
                }
            }
            
            if (testLoopErr == false)
            {                
                charLenIdx++;
            }
        }
        
        if (testLoopErr == false)
        {
            baudRateIdx++;
        }
    }
    
    if (testLoopErr == true)
    {
        if (hSwIpUartRd)
        {
            UART_close(hSwIpUartRd);
            hSwIpUartRd = NULL;
        }
        if (hSwIpUartWrt)
        {
            UART_close(hSwIpUartWrt);
            hSwIpUartWrt = NULL;
        }

        if (gRdCallbackSem)
        {
            UART_osalDeleteBlockingLock(gRdCallbackSem);
            gRdCallbackSem = NULL;
        }
        if (gWrCallbackSem)
        {
            UART_osalDeleteBlockingLock(gWrCallbackSem);
            gWrCallbackSem = NULL;
        }
    }
    else
    {
        //
        // Test read2/write2 API's in callback mode.
        // Loop over all UART settings.
        //
        testLoopErr = false;
        baudRateIdx = 0;
        while ((testLoopErr == false) && (baudRateIdx < TEST_EXT_LB_NUM_UART_BAUD_RATE_SW2SWIP_HWFC))
        {
            charLenIdx = 0;
            while ((testLoopErr == false) && (charLenIdx < TEST_EXT_LB_NUM_UART_CHAR_LEN_SW2SWIP_HWFC))
            {
                stopBitsIdx = 0;
                while ((testLoopErr == false) && (stopBitsIdx < TEST_EXT_LB_NUM_UART_STOP_BITS_SW2SWIP_HWFC))
                {
                    parityIdx = 0;
                    while ((testLoopErr == false) && (parityIdx < TEST_EXT_LB_NUM_UART_PARITY_SW2SWIP_HWFC))
                    {
                        for (hwFcThrIdx = 0; hwFcThrIdx < TEST_EXT_LB_NUM_UART_HW_FC_THR_SW2SWIP_HWFC; hwFcThrIdx++)
                        {
                            // initialize configuration params.
                            // set callback mode for read
                            UART_Params_init(&uartParams);
                            uartParams.readMode = UART_MODE_CALLBACK;
                            uartParams.readCallback = NULL;
                            uartParams.readCallback2 = UART_rdCallback2;
                            uartParams.baudRate = gTestExtLbBaudRateSw2SwIpHwFc[baudRateIdx];       // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLenSw2SwIpHwFc[charLenIdx];       // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBitsSw2SwIpHwFc[stopBitsIdx];       // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParitySw2SwIpHwFc[parityIdx];         // set parity for test loop
                            uartParams.flowControlType = UART_FC_HW;                                // enable hardware flow control
                            uartParams.hwFlowControlThr = gTestExtLbHwFcThrSw2SwIpHwFc[hwFcThrIdx]; // set hardware flow control threshold
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;
                            
                            // open read UART instance
                            hSwIpUartRd = UART_open(swIpUartRdInst, &uartParams);
                            if (hSwIpUartRd == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // initialize configuration params.
                            // set callback mode for write
                            UART_Params_init(&uartParams);
                            uartParams.writeMode = UART_MODE_CALLBACK;
                            uartParams.writeCallback = NULL;
                            uartParams.writeCallback2 = UART_wrCallback2;
                            uartParams.baudRate = gTestExtLbBaudRateSw2SwIpHwFc[baudRateIdx];       // set baud rate for test loop
                            uartParams.dataLength = gTestExtLbCharLenSw2SwIpHwFc[charLenIdx];       // set character length for test loop
                            uartParams.stopBits = gTestExtLbStopBitsSw2SwIpHwFc[stopBitsIdx];       // set number of stop bits for test loop
                            uartParams.parityType = gTestExtLbParitySw2SwIpHwFc[parityIdx];         // set parity for test loop
                            uartParams.flowControlType = UART_FC_HW;                                // enable hardware flow control
                            uartParams.hwFlowControlThr = gTestExtLbHwFcThrSw2SwIpHwFc[hwFcThrIdx]; // set hardware flow control threshold
                            uartParams.readReturnMode = UART_RETURN_FULL;
                            uartParams.readDataMode = UART_DATA_BINARY;
                            uartParams.writeDataMode = UART_DATA_BINARY;

                            // open write UART instance
                            hSwIpUartWrt = UART_open(swIpUartWrInst, &uartParams);
                            if (hSwIpUartWrt == NULL)
                            {
                                testLoopErr = true;
                                break;
                            }

                            memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));

                            // Perform "large" read in callback mode.
                            // Initiate read, don't Block on semaphore immediately after read API function call.
                            // Since chars not yet available, read must be completed using UART Rx HWI.
                            //
                            UART_transactionInit(&gRdCallbackTransaction);
                            gRdCallbackTransaction.buf = (void *)gTestExtLoopbackRdData16b;
                            gRdCallbackTransaction.count = TEST_EXT_LB_LARGE_RD_SZ;
                            if (UART_read2(hSwIpUartRd, &gRdCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            
                            // perform "large" write in callback mode.
                            UART_transactionInit(&gWrCallbackTransaction);
                            gWrCallbackTransaction.buf = (void *)gTestExtLoopbackWrData16b;
                            gWrCallbackTransaction.count = TEST_EXT_LB_LARGE_WR_SZ;
                            if (UART_write2(hSwIpUartWrt, &gWrCallbackTransaction) == UART_ERROR)
                            {
                                testLoopErr = true;
                                break;
                            }
                            if (UART_osalPendLock(gWrCallbackSem, gWrCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }
                            
                            // wait for read completion
                            if (UART_osalPendLock(gRdCallbackSem, gRdCallbackTransaction.timeout) != SemaphoreP_OK)
                            {
                                testLoopErr = true;
                                break;
                            }                    

                            // close read / write UART instances
                            UART_close(hSwIpUartRd);
                            hSwIpUartRd = NULL;
                            UART_close(hSwIpUartWrt);
                            hSwIpUartWrt = NULL;
                            
                            // compare read/write data
                            cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackWrData16b, gTestExtLoopbackRdData16b, 
                                TEST_EXT_LB_LARGE_RD_SZ, gTestExtLbCharLenSw2SwIpHwFc[charLenIdx], false);
                            if (cmpStatus != true)
                            {
                                testLoopErr = true;
                                break;
                            }
                        }
                                                
                        if (testLoopErr == false)
                        {
                            parityIdx++;
                        }
                    }
                    
                    if (testLoopErr == false)
                    {                
                        stopBitsIdx++;
                    }
                }
                
                if (testLoopErr == false)
                {                
                    charLenIdx++;
                }
            }
            
            if (testLoopErr == false)
            {
                baudRateIdx++;
            }
        }

        if (testLoopErr == true)
        {
            if (hSwIpUartRd)
            {
                UART_close(hSwIpUartRd);
                hSwIpUartRd = NULL;
            }
            if (hSwIpUartWrt)
            {
                UART_close(hSwIpUartWrt);
                hSwIpUartWrt = NULL;
            }
            
            if (gRdCallbackSem)
            {
                UART_osalDeleteBlockingLock(gRdCallbackSem);
                gRdCallbackSem = NULL;
            }
            if (gWrCallbackSem)
            {
                UART_osalDeleteBlockingLock(gWrCallbackSem);
                gWrCallbackSem = NULL;
            }
        }
    }

    ret = (testLoopErr == true) ? false : true; // determine overall pass/fail result
    return (ret);
}

/*
 *  ======== UART open/close test ========
 *
 *  The test function tests UART SW IP open/close functionality.
 */
static bool UART_test_open_close_swip(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    uint32_t swIpUartPruX;                  // PRUX SW IP UART instance ID
    uint32_t swIpUartPruY;                  // PRUY SW IP UART instance ID
    uint32_t swIpUartPruYLb1;               // PRUY SW IP1 UART instance ID, external loopback
    uint32_t swIpUartPruYLb2;               // PRUY SW IP2 UART instance ID, external loopback
    UART_Handle hSwIpUartPruX1 = NULL;      // handle 1 for PRUX SW IP UART
    UART_Handle hSwIpUartPruX2 = NULL;      // handle 2 for PRUX SW IP UART
    UART_Handle hSwIpUartPruY = NULL;       // handle for PRUY SW IP UART
    UART_Handle hSwIpUartPruYLb1 = NULL;    // handle for PRUY SW IP UART, external loopback
    UART_Handle hSwIpUartPruYLb2 = NULL;    // handle for PRUY SW IP UART, external loopback
    UART_Params uartParams;
    SemaphoreP_Params semParams;    
    int length = 0;
    bool cmpStatus;
    bool ret = false;
    
    swIpUartPruX    = testUartInstance[TEST_UART_INST_IDX0]; // get PRUX SW IP UART instance ID
    swIpUartPruY    = testUartInstance[TEST_UART_INST_IDX1]; // get PRUY SW IP UART instance ID
    swIpUartPruYLb1 = testUartInstance[TEST_UART_INST_IDX2]; // get PRUY SW IP1 UART instance ID
    swIpUartPruYLb2 = testUartInstance[TEST_UART_INST_IDX3]; // get PRUY SW IP2 UART instance ID

    // initialize configuration params.
    UART_Params_init(&uartParams);
    uartParams.baudRate         = TEST_OPEN_CLOSE_SWIP_BAUD_RATE;       // set baud rate for test loop
    uartParams.dataLength       = TEST_OPEN_CLOSE_SWIP_DATA_LENGTH;     // set character length for test loop
    uartParams.stopBits         = TEST_OPEN_CLOSE_SWIP_STOP_BITS;       // set number of stop bits for test loop
    uartParams.parityType       = TEST_OPEN_CLOSE_SWIP_PARITY;          // set parity for test loop
    uartParams.flowControlType  = UART_FC_NONE;                         // disable hardware flow control
    uartParams.readReturnMode   = UART_RETURN_FULL;
    uartParams.readDataMode     = UART_DATA_BINARY;
    uartParams.writeDataMode    = UART_DATA_BINARY;

    // Open PRUX SW IP UART instance
    hSwIpUartPruX1 = UART_open(swIpUartPruX, &uartParams);
    if (hSwIpUartPruX1 == NULL)
    {
        goto Err;
    }

    // Re-Open PRUX SW IP UART instance.
    //  This is an error.
    //  Returned handle should be NULL.
    //  UART instance can still be used via handle returned from first Open.
    hSwIpUartPruX2 = UART_open(swIpUartPruX, &uartParams);
    if (hSwIpUartPruX2 != NULL)
    {
        goto Err;
    }

    // Close PRUX SW IP UART instance.
    //  Note API function doesn't provide return mechanism to indicate whether Close successful or not.
    UART_close(hSwIpUartPruX1);
    
    // Re-Close PRUX SW IP UART instance.
    //  Application didn't set UART handle to NULL after previous Close.
    //  Call Close again with un-changed handle.
    //  SW IP UART should be unchanged, i.e. remain closed.
    UART_close(hSwIpUartPruX1);
    hSwIpUartPruX1 = NULL;
    
    // Open PRUX SW IP UART instance
    // Open PRUY SW IP UART instance
    // Open PRUY SW IP UART instance, external loopback 1
    // Open PRUY SW IP UART instance, external loopback 2
    hSwIpUartPruX1 = UART_open(swIpUartPruX, &uartParams);
    if (hSwIpUartPruX1 == NULL)
    {
        goto Err;
    }
    hSwIpUartPruY = UART_open(swIpUartPruY, &uartParams);
    if (hSwIpUartPruY == NULL)
    {
        goto Err;
    }
    hSwIpUartPruYLb1 = UART_open(swIpUartPruYLb1, &uartParams);
    if (hSwIpUartPruYLb1 == NULL)
    {
        goto Err;
    }
    hSwIpUartPruYLb2 = UART_open(swIpUartPruYLb2, &uartParams);
    if (hSwIpUartPruYLb2 == NULL)
    {
        goto Err;
    }
    
    // Close UART instances in different order than Open order.
    // Close these UART instances:
    //  PRUY SW IP UART instance
    //  PRUY SW IP UART instance, external loopback 1
    // Leave these UART instances open:
    //  PRUX SW IP UART instance
    //  PRUY SW IP UART instance, external loopback 2
    UART_close(hSwIpUartPruY);
    hSwIpUartPruY = NULL;
    UART_close(hSwIpUartPruYLb1);
    hSwIpUartPruYLb1 = NULL;
    
    // Open PRUY SW IP UART instance, external loopback 1.
    // After this Open, these UART instances are open:
    //  PRUX SW IP UART instance
    //  PRUY SW IP UART instance, external loopback 1
    //  PRUY SW IP UART instance, external loopback 2
    hSwIpUartPruYLb1 = UART_open(swIpUartPruYLb1, &uartParams);
    if (hSwIpUartPruYLb1 == NULL)
    {
        goto Err;
    }
    
    //
    // Perform external loopback test, blocking mode
    //
    
    // Perform "small" write in blocking mode
    if (UART_write(hSwIpUartPruYLb2, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_SMALL_WR_SZ) == UART_ERROR)
    {
        goto Err;
    }
    // Perform "small" read in blocking mode
    memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_SMALL_RD_SZ*sizeof(uint16_t));
    length = UART_read(hSwIpUartPruYLb1, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_SMALL_RD_SZ);
    if (length != TEST_EXT_LB_SMALL_RD_SZ)
    {
        goto Err;
    }
    // Compare read/write data
    cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData16b, gTestExtLoopbackWrData16b, 
        TEST_EXT_LB_SMALL_RD_SZ, TEST_OPEN_CLOSE_SWIP_DATA_LENGTH, false);
    if (cmpStatus != true)
    {
        goto Err;
    }                    
    
    // Close UART instances in different order than Open order.
    // Close these UART instances:
    //  PRUY SW IP UART instance, external loopback 2
    // Leave these UART instances open:
    //  PRUX SW IP UART instance
    //  PRUY SW IP UART instance, external loopback 1
    UART_close(hSwIpUartPruYLb2);
    hSwIpUartPruYLb2 = NULL;
    
    //
    // Perform external loopback test, reader in callback mode, writer in blocking mode
    //
    
    // create read call back semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gRdCallbackSem = UART_osalCreateBlockingLock(0, &semParams);

    // initialize configuration params.
    UART_Params_init(&uartParams);
    uartParams.readMode         = UART_MODE_CALLBACK;
    uartParams.readCallback     = UART_rdCallback;
    uartParams.readCallback2    = NULL;
    uartParams.baudRate         = TEST_OPEN_CLOSE_SWIP_BAUD_RATE;       // set baud rate for test loop
    uartParams.dataLength       = TEST_OPEN_CLOSE_SWIP_DATA_LENGTH;     // set character length for test loop
    uartParams.stopBits         = TEST_OPEN_CLOSE_SWIP_STOP_BITS;       // set number of stop bits for test loop
    uartParams.parityType       = TEST_OPEN_CLOSE_SWIP_PARITY;          // set parity for test loop
    uartParams.flowControlType  = UART_FC_NONE;                         // disable hardware flow control
    uartParams.readReturnMode   = UART_RETURN_FULL;
    uartParams.readDataMode     = UART_DATA_BINARY;
    uartParams.writeDataMode    = UART_DATA_BINARY;

    // Open PRUY SW IP UART instance, external loopback 2.
    // After this Open, these UART instances are open:
    //  PRUX SW IP UART instance
    //  PRUY SW IP UART instance, external loopback 1
    //  PRUY SW IP UART instance, external loopback 2
    hSwIpUartPruYLb2 = UART_open(swIpUartPruYLb2, &uartParams);
    if (hSwIpUartPruYLb2 == NULL)
    {
        goto Err;
    }    
    
    // perform "large" read in callback mode
    memset(gTestExtLoopbackRdData16b, 0, TEST_EXT_LB_LARGE_RD_SZ*sizeof(uint16_t));
    if (UART_read(hSwIpUartPruYLb2, (void *)gTestExtLoopbackRdData16b, TEST_EXT_LB_LARGE_RD_SZ) == UART_ERROR)
    {
        goto Err;
    }
    // perform "large" write in blocking mode
    if (UART_write(hSwIpUartPruYLb1, (void *)gTestExtLoopbackWrData16b, TEST_EXT_LB_LARGE_WR_SZ) == UART_ERROR)
    {
        goto Err;
    }
    // wait for read completion    
    if (UART_osalPendLock(gRdCallbackSem, uartParams.readTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }
    // compare read/write data
    cmpStatus = compareExtLoopbackRdWrData(gTestExtLoopbackRdData16b, gTestExtLoopbackWrData16b,
        TEST_EXT_LB_LARGE_WR_SZ, TEST_OPEN_CLOSE_SWIP_DATA_LENGTH, false);
    if (cmpStatus != true)
    {
        goto Err;
    }      
    
    // Close UART instances in different order than Open order
    UART_close(hSwIpUartPruX1);
    hSwIpUartPruX1 = NULL;
    UART_close(hSwIpUartPruYLb1);
    hSwIpUartPruYLb1 = NULL;
    UART_close(hSwIpUartPruYLb2);
    hSwIpUartPruYLb2 = NULL;
    
    ret = true;

Err:
    if (hSwIpUartPruX1)
    {
        UART_close(hSwIpUartPruX1);
        hSwIpUartPruX1 = NULL;
    }
    if (hSwIpUartPruY)
    {
        UART_close(hSwIpUartPruY);
        hSwIpUartPruY = NULL;
    }
    if (hSwIpUartPruYLb1)
    {
        UART_close(hSwIpUartPruYLb1);
        hSwIpUartPruYLb1 = NULL;
    }
    if (hSwIpUartPruYLb2)
    {
        UART_close(hSwIpUartPruYLb2);
        hSwIpUartPruYLb2 = NULL;
    }
    if (gRdCallbackSem)
    {
        UART_osalDeleteBlockingLock(gRdCallbackSem);
        gRdCallbackSem = NULL;
    }
    
    return ret;
}

// HW IP writer task function -- 8-bit UART interface
Void UART_stress_hwip_reader(UArg a0, UArg a1)
{
    uint8_t pairId;
    uint8_t sideId;                         // read side ID
    uint8_t wrSideId;                       // write side ID
    uint8_t uartIdx;
    UART_Handle hHwIpUartRd;                // read UART handle
    SemaphoreP_Handle hRdCallbackSem;       // read semaphore
    UART_Transaction *pRdCbTransaction;     // pointer to read callback transaction
    TestStressUartXferPrms uartXferPrms;    // transfer parameters
    TestStressUartXferPrms wrUartXferPrms;  // write transfer parameters
    uint32_t xferCnt;
    bool cmpStatus;
    
    pairId = (uint8_t)a0;       // get loopback Pair ID
    sideId = (uint8_t)a1;       // get loopback Side ID

    // Compute UART index
    uartIdx = pairId*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + sideId;

    // Initialize error return
    gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_SOK;
    
    // Get read semaphore handle
    hRdCallbackSem = gTestStressRdCallbackSem[uartIdx];
    // Get pointer to read callback transaction
    pRdCbTransaction = &gTestStressRdCbTransaction[uartIdx];
    
    // Get UART handle
    hHwIpUartRd = gTestStressUartHandle[uartIdx];
    
    // Get read transfer parameters
    uartXferPrms = gTestStressUartXferPrms[pairId][sideId];

    // Get write transfer parameters.
    // Write transfer parameters are determined by other Side.
    wrSideId = (sideId == TEST_STRESS_LB_PAIR_SIDE0_IDX) ? TEST_STRESS_LB_PAIR_SIDE1_IDX : 
        TEST_STRESS_LB_PAIR_SIDE0_IDX;
    wrUartXferPrms = gTestStressUartXferPrms[pairId][wrSideId];
    
    // Perform UART read in loop
    for (xferCnt = 0; xferCnt < uartXferPrms.numRdXfer; xferCnt++)
    {
        // Clear receive buffer
        memset(uartXferPrms.rdData, 0, uartXferPrms.rdXferSz*sizeof(char));

        // Perform read
        UART_transactionInit(pRdCbTransaction);
        pRdCbTransaction->buf = uartXferPrms.rdData;
        pRdCbTransaction->count = uartXferPrms.rdXferSz;
        if (UART_read2(hHwIpUartRd, pRdCbTransaction) == UART_ERROR)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_FXN;
            break;
        }
        
        // Wait for read completion    
        if (UART_osalPendLock(hRdCallbackSem, pRdCbTransaction->timeout) != SemaphoreP_OK)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_SEM_PEND;
            break;
        }
        
        // Compare read/write data
        //  Read 8-bit data for HW IP.
        //  Write 16-bit data for SW IP.
        cmpStatus = compareExtLoopbackRdWrData(uartXferPrms.rdData, wrUartXferPrms.wrData, 
            uartXferPrms.rdXferSz, gTestStressUartCfgPrms[pairId].charLen, true);
        if (cmpStatus != true)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_CMP_DATA;
            break;
        }
        
        // debug, increment count
        gTestStressRdCnt[uartIdx]++;
    }

    // All read transactions complete, post counting semaphore
    if (UART_osalPostLock(gTestStressRdCompleteSem) != SemaphoreP_OK)
    {
        gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_COMPLETE_POST;
    }

    return;
}

// HW IP reader task function -- 8-bit UART interface
Void UART_stress_hwip_writer(UArg a0, UArg a1)
{
    uint8_t pairId;
    uint8_t sideId;
    uint8_t uartIdx;
    UART_Handle hHwIpUartWr;            // write UART handle
    SemaphoreP_Handle hWrCallbackSem;   // write semaphore
    UART_Transaction *pWrCbTransaction; // pointer to write callback transaction
    TestStressUartXferPrms uartXferPrms; // transfer parameters
    uint32_t xferCnt;
    
    pairId = (uint8_t)a0;       // get loopback Pair ID
    sideId = (uint8_t)a1;       // get loopback Side ID

    // Compute UART index
    uartIdx = pairId*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + sideId;
    
    // Initialize error return
    gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_SOK;

    // Get write semaphore handle
    hWrCallbackSem = gTestStressWrCallbackSem[uartIdx];
    // Get pointer to write callback transaction
    pWrCbTransaction = &gTestStressWrCbTransaction[uartIdx];
    
    // Get UART handle
    hHwIpUartWr = gTestStressUartHandle[uartIdx];
    // Get transfer parameters
    uartXferPrms = gTestStressUartXferPrms[pairId][sideId];
    
    // Perform UART write in loop
    for (xferCnt = 0; xferCnt < uartXferPrms.numWrXfer; xferCnt++)
    {
        // Perform write
        UART_transactionInit(pWrCbTransaction);
        pWrCbTransaction->buf = uartXferPrms.wrData;
        pWrCbTransaction->count = uartXferPrms.wrXferSz;
        if (UART_write2(hHwIpUartWr, pWrCbTransaction) == UART_ERROR)
        {
            gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_WRITE_FXN;
            break;
        }
        
        // Wait for write completion    
        if (UART_osalPendLock(hWrCallbackSem, pWrCbTransaction->timeout) != SemaphoreP_OK)
        {
            gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_WRITE_SEM_PEND;
            break;
        }
        
        // debug, increment count
        gTestStressWrCnt[uartIdx]++;
    }

    return;
}

// SW IP writer task function -- 16-bit UART interface
Void UART_stress_swip_reader(UArg a0, UArg a1)
{
    uint8_t pairId;
    uint8_t sideId;                         // read side ID
    uint8_t wrSideId;                       // write side ID
    uint8_t uartIdx;
    UART_Handle hSwIpUartRd;                // read UART handle
    SemaphoreP_Handle hRdCallbackSem;       // read semaphore
    UART_Transaction *pRdCbTransaction;     // pointer to read callback transaction
    TestStressUartXferPrms uartXferPrms;    // transfer parameters
    TestStressUartXferPrms wrUartXferPrms;  // write transfer parameters
    uint32_t xferCnt;
    bool cmpStatus;
    
    pairId = (uint8_t)a0;       // get loopback Pair ID
    sideId = (uint8_t)a1;       // get loopback Side ID

    // Compute UART index
    uartIdx = pairId*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + sideId;

    // Initialize error return
    gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_SOK;
    
    // Get read semaphore handle
    hRdCallbackSem = gTestStressRdCallbackSem[uartIdx];
    // Get pointer to read callback transaction
    pRdCbTransaction = &gTestStressRdCbTransaction[uartIdx];
    
    // Get UART handle
    hSwIpUartRd = gTestStressUartHandle[uartIdx];
    
    // Get read transfer parameters
    uartXferPrms = gTestStressUartXferPrms[pairId][sideId];
    
    // Get write transfer parameters.
    // Write transfer parameters are determined by other Side.
    wrSideId = (sideId == TEST_STRESS_LB_PAIR_SIDE0_IDX) ? TEST_STRESS_LB_PAIR_SIDE1_IDX : 
        TEST_STRESS_LB_PAIR_SIDE0_IDX;
    wrUartXferPrms = gTestStressUartXferPrms[pairId][wrSideId];

    // Perform UART read in loop
    for (xferCnt = 0; xferCnt < uartXferPrms.numRdXfer; xferCnt++)
    {
        // Clear receive buffer
        memset(uartXferPrms.rdData, 0, uartXferPrms.rdXferSz*sizeof(uint16_t));

        // Perform read
        UART_transactionInit(pRdCbTransaction);
        pRdCbTransaction->buf = uartXferPrms.rdData;
        pRdCbTransaction->count = uartXferPrms.rdXferSz;
        if (UART_read2(hSwIpUartRd, pRdCbTransaction) == UART_ERROR)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_FXN;
            break;
        }
        
        // Wait for read completion    
        if (UART_osalPendLock(hRdCallbackSem, pRdCbTransaction->timeout) != SemaphoreP_OK)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_SEM_PEND;
            break;
        }
        
        // Compare read/write data
        //  Read 16-bit data for SW IP.
        //  Write 16-bit data for SW IP -OR- 8-bit data for HW IP.
        cmpStatus = compareExtLoopbackRdWrData(wrUartXferPrms.wrData, uartXferPrms.rdData, 
            uartXferPrms.rdXferSz, gTestStressUartCfgPrms[pairId].charLen, wrUartXferPrms.wrData8b);
        if (cmpStatus != true)
        {
            gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_CMP_DATA;
            break;
        }
        
        // debug, increment count
        gTestStressRdCnt[uartIdx]++;
    }

    // All read transactions complete, post counting semaphore
    if (UART_osalPostLock(gTestStressRdCompleteSem) != SemaphoreP_OK)
    {
        gTestStressRdErr[uartIdx] = TEST_STRESS_RD_ERR_READ_COMPLETE_POST;
    }

    return;
}

// SW IP reader task function -- 16-bit UART interface
Void UART_stress_swip_writer(UArg a0, UArg a1)
{
    uint8_t pairId;
    uint8_t sideId;
    uint8_t uartIdx;
    UART_Handle hSwIpUartWr;            // write UART handle
    SemaphoreP_Handle hWrCallbackSem;   // write semaphore
    UART_Transaction *pWrCbTransaction; // pointer to write callback transaction
    TestStressUartXferPrms uartXferPrms; // transfer parameters
    uint32_t xferCnt;
    
    pairId = (uint8_t)a0;       // get loopback Pair ID
    sideId = (uint8_t)a1;       // get loopback Side ID

    // Compute UART index
    uartIdx = pairId*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + sideId;
    
    // Initialize error return
    gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_SOK;

    // Get write semaphore handle
    hWrCallbackSem = gTestStressWrCallbackSem[uartIdx];
    // Get pointer to write callback transaction
    pWrCbTransaction = &gTestStressWrCbTransaction[uartIdx];
    
    // Get UART handle
    hSwIpUartWr = gTestStressUartHandle[uartIdx];
    // Get transfer parameters
    uartXferPrms = gTestStressUartXferPrms[pairId][sideId];
    
    // Perform UART write in loop
    for (xferCnt = 0; xferCnt < uartXferPrms.numWrXfer; xferCnt++)
    {
        // Perform write
        UART_transactionInit(pWrCbTransaction);
        pWrCbTransaction->buf = uartXferPrms.wrData;
        pWrCbTransaction->count = uartXferPrms.wrXferSz;
        if (UART_write2(hSwIpUartWr, pWrCbTransaction) == UART_ERROR)
        {
            gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_WRITE_FXN;
            break;
        }
        
        // Wait for write completion    
        if (UART_osalPendLock(hWrCallbackSem, pWrCbTransaction->timeout) != SemaphoreP_OK)
        {
            gTestStressWrErr[uartIdx] = TEST_STRESS_WR_ERR_WRITE_SEM_PEND;
            break;
        }
        
        // debug, increment count
        gTestStressWrCnt[uartIdx]++;
    }

    return;
}

/*
 *  ======== UART open/close test ========
 *
 *  The test function performs a UART SW IP stress test.
 */
static bool UART_test_stress_swip(
    uint32_t numTestUartInstance, 
    uint32_t testUartInstance[]
)
{
    Task_Handle taskHandle;
    Int saveTaskPri;
    SemaphoreP_Params semParams;
    uint8_t numWrBlockingLock, numRdBlockingLock;
    uint8_t numWrTask, numRdTask;
    uint8_t numUart;
    Task_Handle rdTask[TEST_STRESS_NUM_UART];
    Task_Handle wrTask[TEST_STRESS_NUM_UART];
    Task_Params taskParams;
    Error_Block eb;
    UART_Params uartParams;
    UART_Handle hUart;
    int32_t testStressRdCompleteSemCnt;
    uint8_t i, j;
    //bool status, err, ret;
    bool err;
    bool rdErr=false;
    bool wrErr=false;
    bool ret;

    
    if (numTestUartInstance != TEST_STRESS_NUM_UART)
    {
        // check number of instance is correct
        return false;
    }
    else if (testUartInstance[TEST_UART_INST_IDX0] != UART_TEST_INSTANCE0)
    {
        // check first instance is HW IP
        return false;
    }

    // debug
    memset(gTestStressRdCnt, 0, TEST_STRESS_NUM_UART*sizeof(uint32_t));
    memset(gTestStressWrCnt, 0, TEST_STRESS_NUM_UART*sizeof(uint32_t));    
    
    taskHandle = Task_self();
    
    // Set Task priority higher than priority of all Reader/Write tasks
    // This keeps Read/Writer tasks from starting execution.
    // Save Task priority level before change.
    saveTaskPri = Task_setPri(taskHandle, TEST_STRESS_MASTER_TASK_PRI_HIGH);

    // Initialize number of Read/Write block locks
    // Initialize number of Read/Write tasks
    // Initialize number of UARTs
    numWrBlockingLock = 0;
    numRdBlockingLock = 0;
    numWrTask = 0;
    numRdTask = 0;
    numUart = 0;
    
    // Create all Readers Complete semaphore
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    gTestStressRdCompleteSem = UART_osalCreateBlockingLock(0, &semParams);
    if (gTestStressRdCompleteSem == NULL)
    {
        err = true;
        goto Err;
    }
    
    // Create Writer semaphores
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    err = false;
    for (i = 0; i < TEST_STRESS_NUM_UART; i++)
    {
        gTestStressWrCallbackSem[i] = UART_osalCreateBlockingLock(0, &semParams);
        if (gTestStressWrCallbackSem[i] == NULL)
        {
            err = true;
            break;
        }
        else
        {
            numWrBlockingLock++;
        }
    }
    if (err == true)
    {
        goto Err;
    }
    
    // Create Reader semaphores
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    err = false;
    for (i = 0; i < TEST_STRESS_NUM_UART; i++)
    {
        gTestStressRdCallbackSem[i] = UART_osalCreateBlockingLock(0, &semParams);
        if (gTestStressRdCallbackSem[i] == NULL)
        {
            err = true;
            break;
        }
        else
        {
            numRdBlockingLock++;
        }
    }
    if (err == true)
    {
        goto Err;
    }
 
    // Create writer tasks
    err = false;
    for (i = 0; i < TEST_STRESS_NUM_UART_LB_PAIR; i++)
    {
        for (j = 0; j < TEST_STRESS_NUM_SIDE_PER_LB_PAIR; j++)
        {
            Task_Params_init(&taskParams);
            taskParams.arg0 = (UArg)i;  // Pair i
            taskParams.arg1 = (UArg)j;  // Side j
            taskParams.stackSize = TEST_STRESS_TASK_STACK_SZ;
            taskParams.priority = TEST_STRESS_WRITER_TASK_PRI;
            wrTask[numWrTask] = Task_create((Task_FuncPtr)gUART_TestStressUartWriterFxn[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j], 
                &taskParams, &eb);
            if (wrTask[numWrTask] == NULL)
            {
                err = true;
                break;
            }
            else
            {
                numWrTask++;
            }
        }
        
        if (err == true)
        {
            break;
        }
    }
    if (err == true)
    {
        goto Err;
    }
    
    // Create reader tasks
    err = false;
    for (i = 0; i < TEST_STRESS_NUM_UART_LB_PAIR; i++)
    {
        for (j = 0; j < TEST_STRESS_NUM_SIDE_PER_LB_PAIR; j++)
        {
            Task_Params_init(&taskParams);
            taskParams.arg0 = (UArg)i;  // Pair i
            taskParams.arg1 = (UArg)j;  // Side j
            taskParams.stackSize = TEST_STRESS_TASK_STACK_SZ;
            taskParams.priority = TEST_STRESS_READER_TASK_PRI;
            rdTask[numRdTask] = Task_create((Task_FuncPtr)gUART_TestStressUartReaderFxn[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j], 
                &taskParams, &eb);
            if (rdTask[numRdTask] == NULL)
            {
                err = true;
                break;
            }
            else
            {
                numRdTask++;
            }
        }
        
        if (err == true)
        {
            break;
        }
    }
    if (err == true)
    {
        goto Err;
    }    
    
    // Open UARTs
    err = false;
    for (i = 0; i < TEST_STRESS_NUM_UART_LB_PAIR; i++)
    {
        for (j = 0; j < TEST_STRESS_NUM_SIDE_PER_LB_PAIR; j++)
        {
            // Get UART configuration.
            // Initialize configuration params.
            // Set callback mode for write/read.
            //
            // Note: Flow Control parameters are ignored by UART HW IP (Pair 0, Side 0).
            //
            UART_Params_init(&uartParams);
            uartParams.readMode = UART_MODE_CALLBACK;
            uartParams.writeMode = UART_MODE_CALLBACK;
            uartParams.readCallback = gUART_TestStressRdCallback[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j];
            uartParams.readCallback2 = NULL;
            uartParams.writeCallback = gUART_TestStressWrCallback[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j];
            uartParams.writeCallback2 = NULL;
            uartParams.baudRate = gTestStressUartCfgPrms[i].baudRate;                  // set baud rate for instance
            uartParams.dataLength = gTestStressUartCfgPrms[i].charLen;                 // set character length for instance
            uartParams.stopBits = gTestStressUartCfgPrms[i].stopBits;                  // set number of stop bits for instance
            uartParams.parityType = gTestStressUartCfgPrms[i].parity;                  // set parity for instance
            uartParams.flowControlType = gTestStressUartCfgPrms[i].flowControlType;    // set hardware flow control for instance
            uartParams.hwFlowControlThr = gTestStressUartCfgPrms[i].hwFlowControlThr;  // set hardware flow control instance
            uartParams.readReturnMode = UART_RETURN_FULL;
            uartParams.readDataMode = UART_DATA_BINARY;
            uartParams.writeDataMode = UART_DATA_BINARY;
            
            // Open UART for Pair i, Side j
            //hUart = UART_open(gTestStressUartInstIdTable[i][j], &uartParams);
            hUart = UART_open(testUartInstance[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j], &uartParams);
            if (hUart == NULL)
            {
                err = true;
                break;
            }
            else
            {
                gTestStressUartHandle[i*TEST_STRESS_NUM_SIDE_PER_LB_PAIR + j] = hUart;
                numUart++;
            }
        }
        
        if (err == true)
        {
            break;
        }
    }
    if (err == true)
    {
        goto Err;
    }    
    
    // Set Task priority lower than priority of all Reader/Writer tasks.
    // This allows the Reader/Writes tasks to start execution.
    Task_setPri(taskHandle, TEST_STRESS_MASTER_TASK_PRI_LOW);
    
    // Wait for final Reader task completion
    do {
        testStressRdCompleteSemCnt = SemaphoreP_getCount(gTestStressRdCompleteSem);
    } while (testStressRdCompleteSemCnt != TEST_STRESS_NUM_UART);

    // Check Reader/Writer error returns
    for (i = 0; i < TEST_STRESS_NUM_UART; i++)
    {
        if (gTestStressRdErr[i] != TEST_STRESS_RD_ERR_SOK)
        {
            rdErr = true;
            break;
        }
    }
    for (i = 0; i < TEST_STRESS_NUM_UART; i++)
    {        
        if (gTestStressWrErr[i] != TEST_STRESS_WR_ERR_SOK)
        {
            wrErr = true;
            break;
        }
    }
    
Err:    
    // Set Task priority higher than priority of all Reader/Write tasks
    // This keeps Read/Writer tasks from executing.
    Task_setPri(taskHandle, TEST_STRESS_MASTER_TASK_PRI_HIGH);

    // Close UARTs
    for (i = 0; i < numUart; i++)
    {
        if (gTestStressUartHandle[i] != NULL)
        {
            UART_close(gTestStressUartHandle[i]);
            gTestStressUartHandle[i] = NULL;
        }
    }
    
    // Delete Writer Tasks
    for (i = 0; i < numWrTask; i++)
    {
        if (wrTask[i] != NULL)
        {
            Task_delete(&wrTask[i]);
            wrTask[i] = NULL;
        }
    }
    
    // Delete Reader Tasks
    for (i = 0; i < numRdTask; i++)
    {
        if (rdTask[i] != NULL)
        {
            Task_delete(&rdTask[i]);
            rdTask[i] = NULL;
        }
    }
    
    // Delete all Readers complete semaphore
    if (gTestStressRdCompleteSem != NULL)
    {
        UART_osalDeleteBlockingLock(gTestStressRdCompleteSem);
        gTestStressRdCompleteSem = NULL;
    }
    
    // Delete Writer semaphores
    for (i = 0; i < numWrBlockingLock; i++)
    {
        if (gTestStressWrCallbackSem[i] != NULL)
        {
            UART_osalDeleteBlockingLock(gTestStressWrCallbackSem[i]);
            gTestStressWrCallbackSem[i] = NULL;
        }
    }
    
    // Delete Reader semaphores
    for (i = 0; i < numRdBlockingLock; i++)
    {
        if (gTestStressRdCallbackSem[i] != NULL)
        {
            UART_osalDeleteBlockingLock(gTestStressRdCallbackSem[i]);
            gTestStressRdCallbackSem[i] = NULL;
        }
    }

    // Restore Task priority level
    Task_setPri(taskHandle, saveTaskPri);
    
    // determine overall pass/fail result
    ret = true;
    if ((err == true) || (rdErr == true) || (wrErr == true))
    {
        ret = false; // test failed
    }
    return ret;    
}

UART_Tests Uart_tests[] =
{
    // PC UART tests
    {1, {UART_TEST_INSTANCE4}, UART_test_read_write, UART_TEST_ID_INT, UART_TEST_DESC_INT},
    {1, {UART_TEST_INSTANCE4}, UART_test_callback, UART_TEST_ID_CB, UART_TEST_DESC_CB},
    {1, {UART_TEST_INSTANCE4}, UART_test_timeout, UART_TEST_ID_TO, UART_TEST_DESC_TO},
    {1, {UART_TEST_INSTANCE4}, UART_test_rx_err, UART_TEST_ID_RXERR, UART_TEST_DESC_RXERR},
    {1, {UART_TEST_INSTANCE4}, UART_test_read_write_cancel, UART_TEST_ID_CANCEL, UART_TEST_DESC_CANCEL},
    {1, {UART_TEST_INSTANCE4}, UART_test_simultaneous_rw, UART_TEST_ID_RW, UART_TEST_DESC_RW},
    {1, {UART_TEST_INSTANCE4}, UART_test_printf_scanf, UART_TEST_ID_PRINTF, UART_TEST_DESC_PRINTF},
    {1, {UART_TEST_INSTANCE4}, UART_test_polling_timeout, UART_TEST_ID_POLL_TO, UART_TEST_DESC_POLL_TO},
    {1, {UART_TEST_INSTANCE4}, UART_test_printf_scanf_stdio_params, UART_TEST_ID_STDIOPARAMS, UART_TEST_DESC_STDIOPARAMS},
    {1, {UART_TEST_INSTANCE4}, UART_test_read_write_int_disable, UART_TEST_ID_INT_DISABLE, UART_TEST_DESC_INT_DISABLE},
#ifdef EXT_LOOPBACK_TESTS
    // external loopback tests
    {2, {UART_TEST_INSTANCE0, UART_TEST_INSTANCE1}, UART_test_hwip_write_to_swip_read_blk, UART_TEST_ID_HWIP_WR_TO_SWIP_RD_BLK, UART_TEST_DESC_HWIP_WR_TO_SWIP_RD_BLK},
    {2, {UART_TEST_INSTANCE1, UART_TEST_INSTANCE0}, UART_test_swip_write_to_hwip_read_blk, UART_TEST_ID_SWIP_WR_TO_HWIP_RD_BLK, UART_TEST_DESC_SWIP_WR_TO_HWIP_RD_BLK},
    {2, {UART_TEST_INSTANCE0, UART_TEST_INSTANCE1}, UART_test_hwip_write_to_swip_read_cb, UART_TEST_ID_HWIP_WR_TO_SWIP_RD_CB, UART_TEST_DESC_HWIP_WR_TO_SWIP_RD_CB},
    {2, {UART_TEST_INSTANCE1, UART_TEST_INSTANCE0}, UART_test_swip_write_to_hwip_read_cb, UART_TEST_ID_SWIP_WR_TO_HWIP_RD_CB, UART_TEST_DESC_SWIP_WR_TO_HWIP_RD_CB},
    {2, {UART_TEST_INSTANCE5, UART_TEST_INSTANCE6}, UART_test_swip_write_to_swip_read_blk, UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_BLK, UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_BLK},
    {2, {UART_TEST_INSTANCE3, UART_TEST_INSTANCE2}, UART_test_swip_write_to_swip_read_blk, UART_TEST_ID_SWIP3_WR_TO_SWIP2_RD_BLK, UART_TEST_DESC_SWIP3_WR_TO_SWIP2_RD_BLK},
    {2, {UART_TEST_INSTANCE5, UART_TEST_INSTANCE6}, UART_test_swip_write_to_swip_read_cb, UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_CB, UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_CB},
    {2, {UART_TEST_INSTANCE3, UART_TEST_INSTANCE2}, UART_test_swip_write_to_swip_read_cb, UART_TEST_ID_SWIP3_WR_TO_SWIP2_RD_CB, UART_TEST_DESC_SWIP3_WR_TO_SWIP2_RD_CB},
    {2, {UART_TEST_INSTANCE5, UART_TEST_INSTANCE6}, UART_test_swip_write_to_swip_read_cb_hwfc, UART_TEST_ID_SWIP5_WR_TO_SWIP6_RD_CB_HWFC, UART_TEST_DESC_SWIP5_WR_TO_SWIP6_RD_CB_HWFC},
    {4, {UART_TEST_INSTANCE1, UART_TEST_INSTANCE4, UART_TEST_INSTANCE5, UART_TEST_INSTANCE6}, UART_test_open_close_swip, UART_TEST_ID_OPEN_CLOSE_SWIP, UART_TEST_DESC_OPEN_CLOSE_SWIP},
    //{2, {UART_TEST_INSTANCE0, UART_TEST_INSTANCE1}, UART_test_stress_swip, UART_TEST_ID_STRESS_SWIP, UART_TEST_DESC_STRESS_SWIP},
    //{4, {UART_TEST_INSTANCE0, UART_TEST_INSTANCE1, UART_TEST_INSTANCE3, UART_TEST_INSTANCE2}, UART_test_stress_swip, UART_TEST_ID_STRESS_SWIP, UART_TEST_DESC_STRESS_SWIP},
    {6, {UART_TEST_INSTANCE0, UART_TEST_INSTANCE1, UART_TEST_INSTANCE3, UART_TEST_INSTANCE2, UART_TEST_INSTANCE6, UART_TEST_INSTANCE5}, UART_test_stress_swip, UART_TEST_ID_STRESS_SWIP, UART_TEST_DESC_STRESS_SWIP},
#endif
    {-1, }
};

void UART_test_print_test_desc(uint32_t uartInstance, UART_Tests *test)
{
    UART_Handle uart = NULL;
    UART_Params uartParams;
    char        testIdPrompt[2*16] = "\r \n   U A R T   U T   ";
	char        crPrompt[2*16] = "\r \n ";
    char        testId[2*16] = {0, };

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;
    uart = UART_open(uartInstance, &uartParams);

    /* Print unit test ID */
    sprintTestId(test->testId, testId, SIZEOF16B(testId));
    UART_write(uart, (void *)(uintptr_t)crPrompt, SIZEOF16B(crPrompt));
    UART_write(uart, (void *)(uintptr_t)testIdPrompt, SIZEOF16B(testIdPrompt));
    UART_write(uart, (void *)(uintptr_t)testId, SIZEOF16B(testId));
    UART_write(uart, (void *)(uintptr_t)crPrompt, SIZEOF16B(crPrompt));

    /* Print test description */
    UART_write(uart, (void *)(uintptr_t)test->testDesc, SIZEOF16B(test->testDesc));
    UART_write(uart, (void *)(uintptr_t)crPrompt, SIZEOF16B(crPrompt));

    UART_close(uart);
}

void UART_test_print_test_result(uint32_t uartInstance, UART_Tests *test, bool pass)
{
    UART_Handle uart = NULL;
    UART_Params uartParams;
    char        testIdPrompt[2*16] = "\r \n   U A R T   U T   ";
    char        crPrompt[2*16] = "\r \n ";
    char        testId[2*16] = {0, };
    char        resultPass[2*16] = "  P A S S E D ";
    char        resultFail[2*16] = "  F A I L E D ";

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;
    uart = UART_open(uartInstance, &uartParams);

    /* Print unit test ID */
    sprintTestId(test->testId, testId, SIZEOF16B(testId));
    UART_write(uart, (void *)(uintptr_t)crPrompt, SIZEOF16B(crPrompt));
    UART_write(uart, (void *)(uintptr_t)testIdPrompt, SIZEOF16B(testIdPrompt));
    UART_write(uart, (void *)(uintptr_t)testId, SIZEOF16B(testId));
    if (pass == true)
    {
        UART_write(uart, (void *)(uintptr_t)resultPass, SIZEOF16B(resultPass));
    }
    else
    {
        UART_write(uart, (void *)(uintptr_t)resultFail, SIZEOF16B(resultFail));
    }

    UART_write(uart, (void *)(uintptr_t)crPrompt, SIZEOF16B(crPrompt));

    UART_close(uart);
}

void UART_test_print_test_results(uint32_t uartInstance, bool pass)
{
    const char  resultPass[32] = "\r\n All tests have passed. \r\n";
    const char  resultFail[32] = "\r\n Some tests have failed. \r\n";

    UART_stdioInit(uartInstance);

    if (pass == true)
    {
        UART_printStatus(resultPass);
    }
    else
    {
        UART_printStatus(resultFail);
    }

    UART_stdioDeInit();
}

/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
{
    bool testResult = false;
    uint32_t i;

    /* Initialize UART driver */
    UART_init();

    for (i = 0; ; i++)
    {
        if (Uart_tests[i].numUartTestInstance == -1)
        {
            break;
        }
        
        UART_test_print_test_desc(testOutUartInstance, &Uart_tests[i]);
        testResult = Uart_tests[i].testFunc(Uart_tests[i].numUartTestInstance, Uart_tests[i].testUartInstance);
        UART_test_print_test_result(testOutUartInstance, &Uart_tests[i], testResult);

        if (testResult == false)
        {
            break;
        }
    }

    UART_test_print_test_results(testOutUartInstance, testResult);

    while (1)
    {
    }
}

/*
 *  ======== main ========
 */
Int main()
{
    Task_Handle task;
    Error_Block eb;
    Task_Params taskParams;

    if (Board_initUART() == false)
    {
        System_printf("\nBoard_initUART failed!\n");
        return(0);
    }

    Error_init(&eb);

    /* Initialize the task params */
    Task_Params_init(&taskParams);
    taskParams.stackSize = 0x4000;
    /* Set the task priority higher than the default priority (1) */
    taskParams.priority = 2;

    task = Task_create(taskFxn, &taskParams, &eb);
    if (task == NULL) 
    {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
    
    /* Start BIOS */
    BIOS_start();    /* does not return */
    return(0);
}
