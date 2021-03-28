/*
 *   Copyright (c) Texas Instruments Incorporated 2018 - 2020
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
 *  \file     rti_app_dwwd.c
 *
 *  \brief    This file contains RTI DWWD test code for window size 100%.
 *
 *  \details  RTI Instance selected depends on the Core used for test
 *            MCU will use MCU RTI1 and MPU will use MAIN RTI0
 *            RTI clock source is selected as 32KHz.
 *            DWWD window size is set to 100%.
 *            DWWD reaction after expiry is set to interrupt mode.
 *            DWWD preload value is set for 10sec.
 *            DWWD time-out value is specified in "APP_RTI_DWWD_TIMEOUT_VALUE"
 *            macro in mili-seconds.
 *            DWWD will expire in 10sec and generate interrupt to Core.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/csl_rti.h>
#include <ti/csl/soc.h>
#include <ti/board/board.h>
#include <ti/osal/osal.h>
#ifdef WDT_RESET
#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/example/rti/rti_dwwdtest_app/rsc_table_basic.h>
#endif

#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define APP_NAME                       "CSL RTI APP"
#ifdef BUILD_MPU1_0
/**< CSL Sample App Name */
#define APP_RTI_MODULE                 (CSL_RTI0_CFG_BASE)
/**< RTI Instance */
#define APP_RTI_DWWD_WINDOW_SIZE       (RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT)
/**< DWWD Window Size */
#define APP_RTI_DWWD_TIMEOUT_VALUE     (10000U)
/**< DWWD Time Out Value */
#define APP_RTI_DWWD_REACTION          (RTI_RTIDWWDRXNCTRL_DWWDRXN_INTERRUPT)
/**< DWWD Reaction After Timeout */
#define RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ        (32U)
/**< RTI Clock Source Selection */
#endif

#ifdef BUILD_MCU1_0
/**< CSL Sample App Name */
#define APP_RTI_MODULE                 (CSL_MCU_RTI1_CFG_BASE)
/**< RTI Instance */
#define APP_RTI_DWWD_WINDOW_SIZE       (RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT)
/**< DWWD Window Size */
#define APP_RTI_DWWD_TIMEOUT_VALUE     (10000U)
/**< DWWD Time Out Value */
#define APP_RTI_DWWD_REACTION          (RTI_RTIDWWDRXNCTRL_DWWDRXN_INTERRUPT)
/**< DWWD Reaction After Timeout */
#define RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ        (32U)
/**< RTI Clock Source Selection */
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 * \brief  Enum to select the clock source for RTI module.
 */
typedef enum rtiClockSource
{
    RTI_CLOCK_SOURCE_HFOSC0_CLKOUT = 0U,
    /**< to select clock frequency of hfosc0 */
    RTI_CLOCK_SOURCE_LFOSC_CLKOUT = 1U,
    /**< to select clock frequency of lfosc */
    RTI_CLOCK_SOURCE_12MHZ = 2U,
    /**< to select clock frequency of 12 MHz */
    RTI_CLOCK_SOURCE_32KHZ = 3U,
    /**< to select clock frequency of 32KHz */
}rtiClockSource_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile uint32_t isrFlag = 0U;
/**< Flag used to indicate interrupt is generated */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/* Unity test app function */
void test_csl_rti_dwwd_test_app(void);
/* Unity test app runner function */
void test_csl_rti_dwwd_test_app_runner(void);

#ifndef WDT_RESET
/**
 * \brief   This API to select clock source for RTI module.
 *
 * \param   rtiModule       RTI module instance
 *
 * \param   rtiClockSource  RTI module clock source
 *                          Values given by enum #rtiClockSource_t
 *
 * \return  none.
 */
static void RTISetClockSource(uint32_t rtiModuleSelect,
                              uint32_t rtiClockSourceSelect);

/**
 * \brief   This API to calculate preload value from given time-out value.
 *
 * \param   rtiClockSource  RTI module clock source
 *                          Values given by enum #rtiClockSource_t
 *
 * \param   timeoutVal      RTI DWWD time-out value in mili-seconds.
 *
 * \return  Preload value   Time-out value in RTI source clock cycles.
 */
static uint32_t RTIGetPreloadValue(uint32_t rtiClkSource, uint32_t timeoutVal);
#endif

/**
 * \brief   This API is used for app prints.
 *
 * \param   None.
 *
 * \return  None.
 */
static void RTIAppUtilsPrint (const char *pcString, ...);
/**
 * \brief   This API to register interrupt for a given instance.
 *
 * \param   rtiModuleSelect RTI module instance
 *
 * \return  0: Success, -1: Failure
 */
static int32_t RTIInterruptConfig(uint32_t rtiModuleSelect);
/**
 * \brief   ISR after interrupt generation, sets global flag
 *
 * \retval  None
 */
static void RTIAppISR(uintptr_t handle);

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

void test_csl_rti_dwwd_test_app(void)
{
    /* @description: Test that runs a basic functionality test of WDT

       @requirements: PRSDK-5575

       @cores: mpu1_0 */

#ifdef WDT_RESET

    Board_initCfg   boardCfg;

    boardCfg = BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    /* Register Interrupt */
    isrFlag = 0U;
    if(RTIInterruptConfig(APP_RTI_MODULE) != 0)
    {
        RTIAppUtilsPrint("\r\nRTI Interrupt configuration failed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
        return;
    }
    RTIAppUtilsPrint(APP_NAME ": RTI App WDT timeout interrupt configured.\n");
    while (0U == isrFlag)
    {
        /* Wait for interrupt */
    }
#else
    uint32_t rtiModule, rtiWindow_size, rtiPreload_value, rtiReaction;
    int32_t  config_status;

    Board_initCfg   boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    UART_printf("\n Board init complete\n");

    /* Register Interrupt */
    isrFlag = 0U;
    if(RTIInterruptConfig(APP_RTI_MODULE) != 0)
    {
        RTIAppUtilsPrint("\r\nRTI Interrupt configuration failed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
        return;
    }

    /* Configure RTI parameters */
    rtiModule        = APP_RTI_MODULE;
    rtiWindow_size   = APP_RTI_DWWD_WINDOW_SIZE;
    rtiReaction      = APP_RTI_DWWD_REACTION;
    rtiPreload_value = RTIGetPreloadValue((uint32_t) RTI_CLOCK_SOURCE_32KHZ,
                                          (uint32_t) APP_RTI_DWWD_TIMEOUT_VALUE);

    /* Select RTI module clock source */
    RTISetClockSource(rtiModule, (uint32_t) RTI_CLOCK_SOURCE_32KHZ);
    config_status = RTIDwwdWindowConfig(rtiModule, rtiReaction,
                                        rtiPreload_value,
                                        rtiWindow_size);
    if (config_status == CSL_EFAIL)
    {
        RTIAppUtilsPrint(APP_NAME ": Error during Window configuration.\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }
    else
    {
        RTIAppUtilsPrint(APP_NAME ": DWWD is configured for %u ms time-out \n",
            APP_RTI_DWWD_TIMEOUT_VALUE);
        RTIAppUtilsPrint(APP_NAME ": DWWD will generate interrupt after "
            "above time-out period.\n");
        RTIDwwdCounterEnable(rtiModule);
        /* Let DWWD expire here */
        RTIAppUtilsPrint(APP_NAME ": Wait for %u ms for interrupt "
            "to be generated by DWWD.\n", APP_RTI_DWWD_TIMEOUT_VALUE);

        while (0U == isrFlag)
        {
            /* Wait for interrupt */
        }
        RTIAppUtilsPrint(APP_NAME ": RTI App completed successfully.\n");
        UART_printStatus("\n ALL TESTS PASSED \n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
#endif
}
void test_csl_rti_dwwd_test_app_runner(void)
{
    /* @description: Test runner for WDT tests

       @requirements: PRSDK-5575

       @cores: mpu1_0 */

#ifdef UNITY_INCLUDE_CONFIG_H
    UNITY_BEGIN();
    RUN_TEST(test_csl_rti_dwwd_test_app);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
#else
    test_csl_rti_dwwd_test_app();
#endif
}

int main(void)
{
    test_csl_rti_dwwd_test_app_runner();
    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static void RTIAppUtilsPrint (const char *pcString, ...)
{
    static char printBuffer[2000U];
    va_list arguments;

    /* Start the varargs processing. */
    va_start(arguments, pcString);
    vsnprintf (printBuffer, sizeof(printBuffer), pcString, arguments);

    printf(printBuffer);
    UART_printf(printBuffer);

    /* End the varargs processing. */
    va_end(arguments);

    return;
}

#ifndef WDT_RESET
static void RTISetClockSource(uint32_t rtiModuleSelect,
                              uint32_t rtiClockSourceSelect)
{
    switch (rtiModuleSelect) {
#ifdef BUILD_MCU1_0
        case CSL_MCU_RTI0_CFG_BASE:
            HW_WR_FIELD32(CSL_MCU_CTRL_MMR0_CFG0_BASE +
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL,
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
        case CSL_MCU_RTI1_CFG_BASE:
            HW_WR_FIELD32(CSL_MCU_CTRL_MMR0_CFG0_BASE +
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL,
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
#endif
#ifdef BUILD_MPU1_0
        case CSL_RTI0_CFG_BASE:
            HW_WR_FIELD32(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_RTI0_CLKSEL,
                          CSL_MAIN_CTRL_MMR_CFG0_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);

            break;
#endif
        default:
            RTIAppUtilsPrint(APP_NAME ": Error : RTI Instance not supported "
                "!!!\r\n");
            break;
    }
}
#endif

static int32_t RTIInterruptConfig(uint32_t rtiModuleSelect)
{
    int32_t retVal = 0;
    OsalRegisterIntrParams_t intrPrms;
    OsalInterruptRetCode_e osalRetVal;
    HwiP_Handle hwiHandle;
    uint32_t rtiIntNum;

    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg          = (uintptr_t)0;
    intrPrms.corepacConfig.priority     = 1U;
    intrPrms.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */

    switch (rtiModuleSelect)
    {
#ifdef BUILD_MCU1_0
        case CSL_MCU_RTI0_CFG_BASE :
            rtiIntNum = CSL_MCU0_INTR_RTI0_INTR_WWD;
        break;
        case CSL_MCU_RTI1_CFG_BASE :
            rtiIntNum = CSL_MCU0_INTR_RTI1_INTR_WWD;
        break;
#endif
#ifdef BUILD_MPU1_0
        case CSL_RTI0_CFG_BASE :
            rtiIntNum = CSL_GIC0_INTR_RTI0_BUS_INTR_WWD;
        break;
#endif
        default :
            RTIAppUtilsPrint(APP_NAME ": Error : RTI Instance not supported "
                "!!!\r\n");
            retVal = -1;
        break;
    }

    if (retVal == 0)
    {
        intrPrms.corepacConfig.isrRoutine   = &RTIAppISR;
        intrPrms.corepacConfig.intVecNum    = rtiIntNum;

        osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
        if(OSAL_INT_SUCCESS != osalRetVal)
        {
            RTIAppUtilsPrint(APP_NAME ": Error Could not register ISR !!!\n");
            retVal = -1;
        }
    }

    return retVal;
}

#ifndef WDT_RESET
static uint32_t RTIGetPreloadValue(uint32_t rtiClkSource, uint32_t timeoutVal)
{
    uint32_t clkFreqKHz       = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ,
             timeoutNumCycles = 0;

    switch (rtiClkSource)
    {
        case RTI_CLOCK_SOURCE_32KHZ:
            clkFreqKHz = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ;
            break;
        default:
            break;
    }
    /* Get the clock ticks for given time-out value */
    timeoutNumCycles = timeoutVal * clkFreqKHz;
    return timeoutNumCycles;
}
#endif

static void RTIAppISR(uintptr_t handle)
{
    uint32_t intrStatus;

    RTIDwwdGetStatus(APP_RTI_MODULE, &intrStatus);
    RTIDwwdClearStatus(APP_RTI_MODULE, intrStatus);
    RTIAppUtilsPrint(APP_NAME ": Interrupt Generated!!!\n");
#ifdef WDT_RESET
    Sciclient_pmDeviceReset(SCICLIENT_SERVICE_WAIT_FOREVER);
#endif
    isrFlag  = 1U;
}
/********************************* End of file ******************************/
