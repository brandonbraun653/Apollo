/*
 *   Copyright (c) Texas Instruments Incorporated 2018-2020
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

 /**
 *  \file     crc_cpu_app.c
 *
 *  \brief    This file contains CRC test code for CPU mode.
 *
 *  \details  CRC operational mode is set to CPU for channel number 1.
 *            CRC signature is calculated on a frame that is stored in DDR RAM
 *            and compared against pre-calculated good CRC signature value.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_crc.h>
#if defined (SOC_TDA3XX)
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#else
#if !defined (SOC_TPR12)
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#endif
#include <ti/board/board.h>
#include <ti/osal/osal.h>
#endif

#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#if defined (SOC_TDA3XX)
#define APP_CRC_MODULE                      (SOC_CRC_BASE)
#else
#define APP_CRC_MODULE                      (CSL_MCU_NAVSS0_MCRC_BASE)
#endif

#if defined (SOC_TPR12) && defined (_TMS320C6X)
#undef APP_CRC_MODULE
#define APP_CRC_MODULE                      (CSL_DSS_MCRC_U_BASE)
#endif

/* Pre-calculated crc signature value for given data pattern */
#define APP_CRC_REFERENCE_SIGN_VAL_L        (0xAEF33083U)
#define APP_CRC_REFERENCE_SIGN_VAL_H        (0x3668F7EAU)

/* Frame deatils - used as refeneance data */
#define APP_FRAME_HEIGHT                    ((uint32_t) 200U)
#define APP_FRAME_WIDTH                     ((uint32_t) 100U)
#define APP_FRAME_PIXEL_SIZE                ((uint32_t) 2U)

/* CRC configuration parameters */
#define APP_CRC_CHANNEL                     (CRC_CHANNEL_1)

/*CRC pattern size updated to 32 bits from 64 bits as CPU can copy only 32 bits at a time*/
#define APP_CRC_PATTERN_SIZE                ((uint32_t) 4U)
#define APP_CRC_PATTERN_CNT                                        \
    ((APP_FRAME_HEIGHT * APP_FRAME_WIDTH * APP_FRAME_PIXEL_SIZE) / \
     APP_CRC_PATTERN_SIZE)
#define APP_CRC_SECT_CNT                    ((uint32_t) 1U)
#define APP_CRC_WATCHDOG_PRELOAD_VAL        ((uint32_t) 0U)
#define APP_CRC_BLOCK_PRELOAD_VAL           ((uint32_t) 0U)

/* Interation count for checking data integrity */
#define APP_ITERATION_CNT                   (20U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if defined (SOC_TDA3XX)
static uint32_t gUartBaseAddr = SOC_UART3_BASE;
#endif

static int32_t  gTestStatus = STW_SOK;
static uint32_t gSrcBuffer[(uint32_t)(APP_FRAME_WIDTH * APP_FRAME_HEIGHT * APP_FRAME_PIXEL_SIZE)] __attribute__(( aligned(128), section(".data") )) = {1U};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void CRCAppClockEnable(void);
static void CRCAppInitUart(void);

static void CRCAppPrint(const char * str);
static void CRCAppPrint_arg(uint32_t *value);
static void CRCAppPrint_args_multiple(uint32_t value1, uint32_t value2);
void test_csl_crc_cputest_app_runner(void);
void test_csl_crc_cputest_app (void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}
#endif

void test_csl_crc_cputest_app_runner(void)
{
    /* @description:Test runner for CRC CPU tests

       @requirements: PRSDK-7037

       @cores: mpu1_0, mcu1_0 */
#if defined(UNITY_INCLUDE_CONFIG_H)
    UNITY_BEGIN();
    RUN_TEST (test_csl_crc_cputest_app);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
#else
    test_csl_crc_cputest_app();
#endif
    return;
}

int main(void)
{
    test_csl_crc_cputest_app_runner();
    while (true)
    {
    }
}

void test_csl_crc_cputest_app (void)
{
    /* @description:Test app for CRC CPU tests

       @requirements: PRSDK-7037

       @cores: mpu1_0, mcu1_0 */

    /* Declaration of variables */
    uint32_t              loopCnt, errorFlag, frameSize;
    uint32_t             *srcMemory;
    uint32_t              patternCnt, sectCnt, baseAddr;
    uint32_t              watchdogPreloadVal, blockPreloadVal, patternSize;
    crcChannel_t          chNumber;
    crcOperationMode_t    mode;
    crcSignature_t        sectSignVal,refSignVal;
    crcSignatureRegAddr_t psaSignRegAddr;

    /* Init UART*/
    CRCAppInitUart();

    CRCAppPrint("\nCRC Test Application\r\n");
    /* Initialize variables */
    errorFlag        = 0U;
    srcMemory        = (uint32_t *) &gSrcBuffer;
    sectSignVal.regL = 0U;
    sectSignVal.regH = 0U;
    /* Configure CRC parameters */
    baseAddr           = APP_CRC_MODULE;
    patternSize        = APP_CRC_PATTERN_SIZE;
    patternCnt         = APP_CRC_PATTERN_CNT;
    sectCnt            = APP_CRC_SECT_CNT;
    watchdogPreloadVal = APP_CRC_WATCHDOG_PRELOAD_VAL;
    blockPreloadVal    = APP_CRC_BLOCK_PRELOAD_VAL;
    chNumber           = APP_CRC_CHANNEL;
    mode               = CRC_OPERATION_MODE_FULLCPU;

    /* Enable CRC clock */
    CRCAppClockEnable();
    /* Get CRC PSA signature register address */
    CRCGetPSASigRegAddr(baseAddr, chNumber, &psaSignRegAddr);

    /* Initialize source memory with reference data */
    frameSize = (APP_FRAME_WIDTH * APP_FRAME_HEIGHT * APP_FRAME_PIXEL_SIZE);
    for (loopCnt = 0; loopCnt < (frameSize / 4); loopCnt++)
    {
        srcMemory[loopCnt] = loopCnt;
    }

    CRCAppPrint("\nCopied reference data into DDR memory");
    CRCAppPrint_arg(&gSrcBuffer[0]);
    CRCAppPrint("\nConfiguring CRC \n");

    /* Configure CRC channel */
    CRCInitialize(baseAddr, chNumber, watchdogPreloadVal, blockPreloadVal);
    CRCAppPrint("\nUsing Pre-Defined Reference CRC signature Value");
    refSignVal.regH = APP_CRC_REFERENCE_SIGN_VAL_H;
    refSignVal.regL = APP_CRC_REFERENCE_SIGN_VAL_L;
    for (loopCnt = 0U; loopCnt < APP_ITERATION_CNT; loopCnt++)
    {
        /* CRC channel RESET before initialization/configuration */
        CRCChannelReset(baseAddr, chNumber);
        /* Initialize CRC channel */
        CRCConfigure(baseAddr, chNumber, patternCnt, sectCnt, mode);
        for (loopCnt = 0; loopCnt < (frameSize / patternSize); loopCnt++)
        {
            HW_WR_REG32(psaSignRegAddr.regL, srcMemory[loopCnt]);
        }
         /* Fetch CRC signature value       */
        CRCGetPSASectorSig(baseAddr, chNumber, &sectSignVal);
        /* Compare CRC signature value against reference CRC signature */
        if ((sectSignVal.regH == refSignVal.regH)
            && (sectSignVal.regL == refSignVal.regL))
        {
            /* Sector signature matches */
        }
        else
        {
            errorFlag = 1U;
            CRCAppPrint("\n\nSector signature does not match with pre-calculated value.");
            CRCAppPrint("\nExpected CRC signature value (H,L):");
            CRCAppPrint_args_multiple(refSignVal.regH, refSignVal.regL);
            CRCAppPrint("Calculated CRC signature value (H,L):");
            CRCAppPrint_args_multiple(sectSignVal.regH, sectSignVal.regL);
            gTestStatus = STW_EFAIL;
            break;
        }
    }

    if (errorFlag == 0U)
    {
        CRCAppPrint("\n\nCRC signature verification done successfully.\n");
    }
    else
    {
        CRCAppPrint("\nCRC signature verification failed.\n");
    }

    if (gTestStatus == STW_SOK)
    {
        CRCAppPrint("\r\nCRC Test Pass");
    }
    else
    {
        CRCAppPrint("\r\nCRC Test Fail");
    }

    if (gTestStatus == STW_SOK)
    {
        CRCAppPrint("\n All tests have passed. \n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_PASS();
#endif
    }
    else
    {
        CRCAppPrint("\n CRC CPU Test failed. \n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_FAIL();
#endif
    }

    return;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static void CRCAppInitUart(void)
{
#if defined (SOC_TDA3XX)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);

    /* Initialize the UART Instance */
    UARTConfigInit(gUartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
                   UART_STOP_BIT_1, UART_NO_PARITY, UART_16x_MODE);
#else
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        CRCAppPrint("[Error] Board init failed!!\n");
    }
#endif
}

static void CRCAppClockEnable(void)
{
#if defined (SOC_TDA3XX)
    HW_WR_FIELD32(SOC_CORE_CM_CORE_BASE + CM_CRC_CLKSTCTRL,
                 CM_CRC_CLKSTCTRL_CLKTRCTRL,
                 CM_CRC_CLKSTCTRL_CLKTRCTRL_SW_WKUP);
    HW_WR_FIELD32(SOC_CORE_CM_CORE_BASE + CM_CRC_CRC_CLKCTRL,
                 CM_CRC_CRC_CLKCTRL_MODULEMODE,
                 CM_CRC_CRC_CLKCTRL_MODULEMODE_ENABLE);
#endif
}

static void CRCAppPrint(const char * str)
{
    printf(str);
#if defined (SOC_TDA3XX)
    UARTConfigPuts(gUartBaseAddr, str, -1);
#elif !defined (SOC_TPR12)
    UART_printf(str);
#endif
}

static void CRCAppPrint_arg(uint32_t *value)
{
    printf("@%p. \n",value);
#if defined (SOC_TDA3XX)
    UARTConfigPrintf(gUartBaseAddr,"@%p. \n", value);
#elif !defined (SOC_TPR12)
    UART_printf("@%p. \n", value);
#endif
}

static void CRCAppPrint_args_multiple(uint32_t value1, uint32_t value2)
{
    printf("0x%xU 0x%xU \n" ,value1, value2);
#if defined (SOC_TDA3XX)
    UARTConfigPrintf(gUartBaseAddr,"0x%xU 0x%xU \n", value1, value2);
#elif !defined (SOC_TPR12)
    UART_printf("0x%x%xU \n", value1, value2);
#endif

}
