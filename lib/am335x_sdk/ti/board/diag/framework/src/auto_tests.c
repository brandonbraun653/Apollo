/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/board/board_cfg.h>
#include <diag_common_cfg.h>
#include "framework.h"
#if defined(am65xx_evm)
#include <ti/board/src/am65xx_evm/am65xx_evm_pinmux.h>
#endif
#if defined(am65xx_idk)
#include <ti/board/src/am65xx_idk/am65xx_idk_pinmux.h>
#endif
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ti/csl/tistdtypes.h>
#include <ti/fs/fatfs/ff.h>
#include <ti/csl/csl_a15.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/boot/sbl/src/rprc/sbl_rprc_parse.h>

#define PADCONFIG_MAX_COUNT     (9u)
#define GPIO_PADCONFIG_MUX_MODE (7u)

/* Pad Config register offset address details */
static uint32_t pinMuxgpio[PADCONFIG_MAX_COUNT] = 
{
    PIN_GPMC0_WPN,
    PIN_GPMC0_DIR,
    PIN_GPMC0_CSN0,
    PIN_GPMC0_CSN1,
    PIN_GPMC0_CLK,
    PIN_GPMC0_BE0N_CLE,
    PIN_GPMC0_BE1N,
    PIN_GPMC0_WAIT0,
    PIN_GPMC0_WAIT1
};

char *gSelfTestName[DIAG_APP_POST_NUM] =
                        {   "bootEepromCompliance_TEST",
                            "memCompliance_TEST",
                            "emmcCompliance_TEST",
                            "norflashCompliance_TEST",
                            "ospiCompliance_TEST",
                            "ledCompliance_TEST",
                            "bootSwitchCompliance_TEST",
                            "eepromCompliance_TEST",
                        };
DIAG_testApp_t COMP_appTbl[DIAG_APP_MAX_NUM];
uint32_t COMP_numApp;

/* Function to make SOC Signals as GPIO input */
void DIAG_gpio_pinmux(void)
{
    uint8_t index;

    for(index = 0; index < PADCONFIG_MAX_COUNT; index++)
    {
        Board_pinMuxSetMode(pinMuxgpio[index],
                            (GPIO_PADCONFIG_MUX_MODE | PIN_INPUT_ENABLE));
    }
}

/* Function to display the compliance test status */
void DIAG_printCompTestStatus(void)
{
    uint32_t i, j;
    UART_printf("Diagnostic Test Status:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("ID\tName\t\t\t\tPass\t# of times Ran\n");

    for (i = 0; i<COMP_numApp; i++)
    {
        UART_printf("%d\t%s",
            i+1,
            COMP_appTbl[i].appName);

        /* note: 32 is 4 tabs between "Name" and "Pass". This is just for display */
        for (j = 0; j<(32 - strlen(COMP_appTbl[i].appName)); j++)
        {
            UART_printf(" ");
        }
        UART_printf("%s\t%d\n",
            (COMP_appTbl[i].appPassed == 1) ? "Yes":"No",
            COMP_appTbl[i].appRan);
    }
    UART_printf("\n");
}

/* Function to run compliance tests */
void DIAG_runComplianceTest(void)
{
    uint32_t noi,index, breakLoop;
    char iterations[10],rdBuf = 'y';
    
    breakLoop = 1;

    /* Configure unused pins as GPIO for compliance test */
    DIAG_gpio_pinmux();
    DIAG_printCompTestStatus();

    UART_printf("Enter the number of iterations : ");
    UART_scanFmt("%s\n",iterations);
    noi = atoi(iterations);

    if(noi == 0)
    {
        breakLoop = 0;
        noi = 1;
    }

    while(noi>0)
    {
        UART_printf("\n\nRunning Compliance Test...\n");
        UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

        for(index = 1;index<=COMP_numApp;index++)
        {
            DIAG_testExecute(index);
        }

        DIAG_printCompTestStatus();
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            break;
        }

        if(breakLoop)
        {
            noi--;
        }
    }
}

int32_t DIAG_testExecute(uint32_t n)
{
    sblEntryPoint_t pEntry;
    FIL fp;
    FRESULT fresult;
    int32_t retVal;

    diagMainFxn func_ptr;
#if defined(SOC_AM65XX)
#if defined(__aarch64__)
    register int result asm("x20");
#else
    /* Explicit declaration of register variables is not supported by ti-cgt.
       Need to define the result as normal variable and pass it as parameter
       for diag test function */
    int result;
#endif
#else
    register int result asm("r9");
#endif

    fresult = f_open(&fp, COMP_appTbl[n-1].appName, (uint8_t) FA_READ);
    if (fresult != FR_OK)
    {
        UART_printf("Failed to open %s\n", COMP_appTbl[n-1].appName);
        return -1;
    }
    else
    {
        UART_printf("Parsing %s\n", COMP_appTbl[n-1].appName);
        retVal = SBL_MulticoreImageParse((void *) &fp, 0, &pEntry);

        f_close(&fp);
        if (retVal != E_PASS)
        {
            UART_printf("Error in parsing image\n");
            return -1;
        }
        else
        {
#if defined(am65xx_evm) || defined(am65xx_idk)
#if defined (__aarch64__)
            if (pEntry.CpuEntryPoint[MPU1_CPU0_ID] == 0)
#else
            if (pEntry.CpuEntryPoint[MCU1_CPU0_ID] == 0)
#endif
#else
            if (pEntry.entryPoint_MPU_CPU0 == 0)
#endif
            {
                UART_printf("Unable to get entry point\n");
                return -1;
            }
            else
            {
                UART_printf("Running %s\n", COMP_appTbl[n-1].appName);
                COMP_appTbl[n-1].appRan++;
                        
#if defined(am65xx_evm) || defined(am65xx_idk)
#if defined (__aarch64__)
                func_ptr = (diagMainFxn) pEntry.CpuEntryPoint[MPU1_CPU0_ID];
#else
                func_ptr = (diagMainFxn) pEntry.CpuEntryPoint[MCU1_CPU0_ID];
#endif
#else
                func_ptr = (diagMainFxn) pEntry.entryPoint_MPU_CPU0;
#endif

#if defined(SOC_K2G) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
                CSL_a15WbAllDataCache();
                CSL_a15InvAllInstrCache();
                __sync_synchronize();
#endif

#if defined(SOC_AM65XX) && !defined(__aarch64__)
                func_ptr(DIAG_VAL, &result);
#else
                func_ptr(DIAG_VAL);
#endif
                if (result == 0)
                {
                    COMP_appTbl[n-1].appPassed = 1;
                    retVal = 0;
                }
                else
                {
                    COMP_appTbl[n-1].appPassed = 0;
                    retVal = -1;
                }
            
                UART_printf("\nFinished running %s, result %s\n",
                            COMP_appTbl[n-1].appName,
                            (COMP_appTbl[n-1].appPassed == 1)? "passed!" : "failed!");
            }
        }
    }

    return retVal;
}

int32_t DIAG_PoSTTest(void)
{
    uint8_t testIndex,mainIndex;
    uint16_t timer=500;
    char *findStr = NULL;
    uint8_t rdBuf = 'y';
    int32_t retVal;

    UART_printf("\n\nRunning Power On Self Tests...\n");
    UART_printf("Press 'b' to Skip the Test\n");

    while (timer > 0)
    {
        if(!(timer % 100))
        {
            UART_printf("\r%d", (timer / 100));
        }

        BOARD_delay(10000);
        rdBuf = (uint8_t)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("\nSkipping the Test\n\n");
            return 0;
        }
        timer--;
    }

    UART_printf("\r\n");

    retVal = 0;
    for(testIndex = 0;testIndex < DIAG_APP_POST_NUM; testIndex++)
    {
        for(mainIndex = 0; mainIndex < COMP_numApp; mainIndex++)
        {
            findStr = strstr( COMP_appTbl[mainIndex].appName, gSelfTestName[testIndex]);
            if(findStr != NULL)
            {
                retVal |= DIAG_testExecute(mainIndex + 1);
            }
        }
    }

    UART_printf("\n\nPower On Self Test Result\n");
    if(retVal == 0)
    {
        UART_printf("All Tests Passed\n");
    }
    else
    {
        UART_printf("Some Tests Failed\n");
    }

    /* Clearing the status */
    for(mainIndex = 0; mainIndex < COMP_numApp; mainIndex++)
    {
        COMP_appTbl[mainIndex].appPassed = 0;
        COMP_appTbl[mainIndex].appRan = 0;
    }

    return 0;
}
