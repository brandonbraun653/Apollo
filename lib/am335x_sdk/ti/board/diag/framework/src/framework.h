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

int32_t DIAG_PoSTTest(void);
int32_t DIAG_testExecute(uint32_t n);
void DIAG_runComplianceTest();
void DIAG_main();
void DIAG_printMenu();
int DIAG_checkCmd(char *cmd);
void DIAG_runTest();
void DIAG_parseApps();
void DIAG_printStatus();
int32_t DIAG_fread(void *buff, void *fileptr, uint32_t size);
void DIAG_fseek(void *fileptr, uint32_t location);

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && !defined(__aarch64__))
    typedef void (*diagMainFxn)(int, int*);
#else
    typedef void (*diagMainFxn)(int);
#endif

typedef struct DIAG_cmdEntry
{
    const char *cmdName;
    void (*cmdFn) ();
} DIAG_cmdEntry_t;

#define DIAG_APP_MAX_NAME_SIZE 32
#define DIAG_APP_MAX_NUM 50
#define DIAG_APP_POST_NUM 8
#define DIAG_APP_IDENTIFIER "TEST"
#define DIAG_VAL 0xfeedfeed
typedef struct DIAG_testApp
{
    char appName[DIAG_APP_MAX_NAME_SIZE];
    int (*testFn) ();
    int appPassed;
    int appRan;
} DIAG_testApp_t;

