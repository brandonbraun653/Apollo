/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
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


#if defined(SOC_AM335x) || defined(SOC_AM437x)
#include "diag_mmc.h"
#else
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ti/csl/tistdtypes.h>
#include <ti/fs/fatfs/ff.h>

#if !defined(SOC_AM65XX) && !defined(SOC_J721E)
#include <ti/csl/csl_a15.h>
#endif

#include <ti/drv/uart/UART_stdio.h>
#include <ti/boot/sbl/src/rprc/sbl_rprc_parse.h>
#endif

#include "framework.h"

#ifdef iceAMIC110
#include <ti/csl/csl_mcspi.h>
#include <ti/csl/src/ip/mcspi/V0/mcspi.h>
#include "ti/board/src/iceAMIC110/include/board_cfg.h"

extern int eeprom_test();
extern int8_t BoardDiag_gpioLedFunctionalTest();
extern int mem_test();
extern int8_t BoardDiag_mcspiFuctionalTest();
extern int uart_test();
#endif  /* #ifdef iceAMIC110 */
/* Diagnostic commands */
DIAG_cmdEntry_t DIAG_cmdTbl[] =
{
    {"help", &DIAG_printMenu},
    {"run", &DIAG_runTest},
    {"status", &DIAG_printStatus},
    {NULL, NULL}
};

char gDiagVersion[] = "01.00.00.02";

/* Diagnostic applications */
#ifdef iceAMIC110
DIAG_testApp_t DIAG_appTbl[DIAG_APP_MAX_NUM] = 
    {{"uartTest", uart_test, 0, 0},
     {"eepromTest", eeprom_test, 0, 0},
     {"ledTest", BoardDiag_gpioLedFunctionalTest, 0, 0},
     {"spiTest", BoardDiag_mcspiFuctionalTest, 0, 0},
     {"ddrTest", mem_test, 0, 0},
    };
uint32_t DIAG_numApp = 5;
#else
DIAG_testApp_t DIAG_appTbl[DIAG_APP_MAX_NUM];
#if defined(SOC_AM65XX)
extern DIAG_testApp_t COMP_appTbl[DIAG_APP_MAX_NUM];
#endif
uint32_t DIAG_numApp;
#if defined(SOC_AM65XX)
extern uint32_t COMP_numApp;
#endif
static DIR DIAG_dir;
static FILINFO DIAG_fileInfo;
#endif  /* #ifdef iceAMIC110 */

void DIAG_printMenu()
{
    UART_printf("Command options:\n");
    UART_printf("\thelp - displays this help menu again\n");
    UART_printf("\trun - run a diagnostic application\n");
    UART_printf("\tstatus - prints the test status\n");
}

void DIAG_printStatus()
{
    int i, j;
    UART_printf("Diagnostic Test Status:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("ID\tName\t\t\t\tPass\t# of times Ran\n");
#if defined(SOC_AM65XX)
    UART_printf("0\tAuto Run All Compliance Tests\n");
#endif
    for (i = 0; i<DIAG_numApp; i++)
    {
        UART_printf("%d\t%s",
            i+1,
            DIAG_appTbl[i].appName);

        /* note: 32 is 4 tabs between "Name" and "Pass". This is just for display */
        for (j = 0; j<(32 - strlen(DIAG_appTbl[i].appName)); j++)
        {
            UART_printf(" ");
        }
        UART_printf("%s\t%d\n",
            (DIAG_appTbl[i].appPassed == 1) ? "Yes":"No",
            DIAG_appTbl[i].appRan);
    }
    UART_printf("\n");
}

#ifdef iceAMIC110
void DIAG_parseApps()
{
    /* Nothing to be done here */
}
#else
void DIAG_parseApps()
{
#if defined(SOC_AM65XX)
    char compliance[] = "Compliance";
#endif
    FRESULT fresult;
    char *dir = "0:";
    int i;

    for (i = 0; i<DIAG_APP_MAX_NUM; i++)
    {
        DIAG_appTbl[i].appName[0] = '\0';
        DIAG_appTbl[i].appPassed = 0;
        DIAG_appTbl[i].appRan = 0;
#if defined(SOC_AM65XX)
        COMP_appTbl[i].appName[0] = '\0';
        COMP_appTbl[i].appPassed = 0;
        COMP_appTbl[i].appRan = 0;
#endif
    }

    DIAG_numApp = 0;
#if defined(SOC_AM65XX)
    COMP_numApp = 0;
#endif
    fresult = f_opendir(&DIAG_dir, dir);
    while (fresult == FR_OK)
    {
        fresult = f_readdir(&DIAG_dir, &DIAG_fileInfo);
        if (fresult == FR_OK)
        {
            if(DIAG_fileInfo.fname[0] == '\0') break;
            else
            {
                if (DIAG_fileInfo.fname[0])
                {
                    if (strstr(DIAG_fileInfo.fname, DIAG_APP_IDENTIFIER) != NULL)
                    {
#if defined(SOC_AM65XX)
                        if(!strstr(DIAG_fileInfo.fname, compliance))
                        {
                            if (strlen(DIAG_fileInfo.fname) < sizeof(DIAG_appTbl[DIAG_numApp].appName))
                            {
                                strncpy(DIAG_appTbl[DIAG_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                                DIAG_appTbl[DIAG_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                                DIAG_numApp++;
                            }
                        }
                        else
                        {
                            if (strlen(DIAG_fileInfo.fname) < sizeof(COMP_appTbl[COMP_numApp].appName))
                            {
                                strncpy(COMP_appTbl[COMP_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                                COMP_appTbl[COMP_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                                COMP_numApp++;
                            }
                        }
#else
                        if (strlen(DIAG_fileInfo.fname) < sizeof(DIAG_appTbl[DIAG_numApp].appName))
                        {
                            strncpy(DIAG_appTbl[DIAG_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                            DIAG_appTbl[DIAG_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                            DIAG_numApp++;
                        }
#endif
                    }
                }
                else
                {
                    if (strstr(DIAG_fileInfo.fname, DIAG_APP_IDENTIFIER) != NULL)
                    {
#if defined(SOC_AM65XX)
                        if(!strstr(DIAG_fileInfo.fname, compliance))
                        {
                            if (strlen(DIAG_fileInfo.fname) < sizeof(DIAG_appTbl[DIAG_numApp].appName))
                            {
                                strncpy(DIAG_appTbl[DIAG_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                                DIAG_appTbl[DIAG_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                                DIAG_numApp++;
                            }
                        }
                        else
                        {
                            if (strlen(DIAG_fileInfo.fname) < sizeof(COMP_appTbl[COMP_numApp].appName))
                            {
                                strncpy(COMP_appTbl[COMP_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                                COMP_appTbl[COMP_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                                COMP_numApp++;
                            }
                        }
#else
                        if (strlen(DIAG_fileInfo.fname) < sizeof(DIAG_appTbl[DIAG_numApp].appName))
                        {
                            strncpy(DIAG_appTbl[DIAG_numApp].appName, DIAG_fileInfo.fname, strlen(DIAG_fileInfo.fname));
                            DIAG_appTbl[DIAG_numApp].appName[strlen(DIAG_fileInfo.fname)] = '\0';
                            DIAG_numApp++;
                        }
#endif
                    }
                }
            }
        }
        else
        {
            UART_printf("Failed in f_readdir()\n");
        }
        if (DIAG_numApp == DIAG_APP_MAX_NUM)
        {
            UART_printf("Warning: max number of diagnostic applications reached\n");
            break;
        }
    }
#if defined(SOC_K2G) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x) || defined (am65xx_evm) || defined (am65xx_idk) || defined(j721e_evm)
    fp_readData = &DIAG_fread;
    fp_seek = &DIAG_fseek;
#endif
}
#endif

int DIAG_checkCmd(char *cmd)
{
    int index;
    for (index = 0; DIAG_cmdTbl[index].cmdName != NULL; index++)
    {
        if (strcmp(cmd, DIAG_cmdTbl[index].cmdName) == 0) break;
    }
    if (DIAG_cmdTbl[index].cmdName == NULL) index = -1;
    return index;
}

#ifdef iceAMIC110
void DIAG_runTest()
{
    int32_t retVal;
    int n;
    char buf[10];
    register int result asm("r9");

    DIAG_printStatus();
    UART_printf("Select test number (1 - %d): ", DIAG_numApp);
    UART_scanFmt("%s\n", buf);
    n = atoi(buf);
    UART_printf("\nOption is %d",n);

    if ( (n<1) || (n>(DIAG_numApp+1)) )
    {
        UART_printf("Invalid number %d! Please select from 1 to %d.\n", n, DIAG_numApp);
        return;
    }
    else
    {
        retVal = DIAG_appTbl[n-1].testFn();
        if(retVal == 0)
        {
            DIAG_appTbl[n-1].appPassed = 1;
        }
        else
        {
            DIAG_appTbl[n-1].appPassed = 0;
        }

        DIAG_appTbl[n-1].appRan++;
    }
}
#else
void DIAG_runTest()
{
    int32_t retVal;
    FIL fp;
    FRESULT fresult;
    int n;
    char buf[10];
    sblEntryPoint_t pEntry;

    diagMainFxn func_ptr;
#if defined(SOC_AM65XX) || defined(SOC_J721E)
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

    DIAG_printStatus();
    UART_printf("Select test number (1 - %d): ", DIAG_numApp);
    UART_scanFmt("%s\n", buf);
    n = atoi(buf);
#if defined(SOC_AM65XX)
    if(n==0)
    {
        DIAG_runComplianceTest();
    }
    else if (n>(DIAG_numApp+1))
#else
    if ( (n<1) || (n>(DIAG_numApp+1)) )
#endif
    {
        UART_printf("Invalid number %d! Please select from 1 to %d.\n", n, DIAG_numApp);
        return;
    }
    else
    {
        fresult = f_open(&fp, DIAG_appTbl[n-1].appName, (uint8_t) FA_READ);
        if (fresult != FR_OK)
        {
            UART_printf("Failed to open %s\n", DIAG_appTbl[n-1].appName);
            return;
        }
        else
        {
            UART_printf("Parsing %s\n", DIAG_appTbl[n-1].appName);
            retVal = SBL_MulticoreImageParse((void *) &fp, 0, &pEntry);

            f_close(&fp);
            if (retVal != E_PASS)
            {
                UART_printf("Error in parsing image\n");
                return;
            }
            else
            {
#if defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_evm)
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
                    return;
                }
                else
                {
                    UART_printf("Running %s\n", DIAG_appTbl[n-1].appName);
                    DIAG_appTbl[n-1].appRan++;
                    
#if defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_evm)
#if defined (__aarch64__)
                    func_ptr = (diagMainFxn) (uintptr_t)pEntry.CpuEntryPoint[MPU1_CPU0_ID];
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

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && !defined(__aarch64__)
                    func_ptr(DIAG_VAL, &result);
#else
                    func_ptr(DIAG_VAL);
#endif
                    if (result == 0)
                        DIAG_appTbl[n-1].appPassed = 1;
                    else
                        DIAG_appTbl[n-1].appPassed = 0;
                    
                    UART_printf("\nFinished running %s, result %s\n",
                        DIAG_appTbl[n-1].appName,
                        (DIAG_appTbl[n-1].appPassed == 1)? "passed!" : "failed!");
                }
            }
        }
    }
}
#endif

void DIAG_main()
{
    char cmd[255];
    bool diag_continue = true;
    int index = 0;
    void (*fnPtr) ();
    UART_printf("\nDIAGNOSTIC TEST FRAMEWORK\n");
    UART_printf("Version - %s\n", gDiagVersion);
    UART_printf("Build Date - %s, Time - %s\n\n\n", __DATE__, __TIME__);

    DIAG_parseApps();
    DIAG_printMenu();
#if defined(SOC_AM65XX)
    DIAG_PoSTTest();
#endif
    while (diag_continue)
    {
        UART_printf("[Diag Menu]: ");
        UART_scanFmt("%s", cmd);
        index = DIAG_checkCmd(cmd);
        if (index >= 0)
        {
            fnPtr = DIAG_cmdTbl[index].cmdFn;
            (*fnPtr)();
        }
    }
}

#ifndef iceAMIC110
int32_t DIAG_fread(void *buff, void *fileptr, uint32_t size)
{
    FIL     *fp         = (FIL *) (fileptr);
    uint32_t i          = 0;
    uint32_t bytes_read = 0;
    uint32_t Max_read   = 0x400U;
    FRESULT  fresult    = FR_OK;
    uint8_t *dataBuff = (uint8_t *)buff;

    for (i = 0; i < (size / Max_read); ++i)
    {
        fresult  = f_read(fp, (void *)dataBuff, Max_read, &bytes_read);
        dataBuff += bytes_read;
        if (fresult != FR_OK)
        {
            break;
        }
    }
    if (fresult == FR_OK)
    {
        fresult = f_read(fp, (void *)dataBuff, (uint16_t) (size % Max_read), &bytes_read);
    }

    return fresult;
}

void DIAG_fseek(void *fileptr, uint32_t location)
{
    FIL *fp = (FIL *) (fileptr);
    f_lseek(fp, location);
}
#endif
