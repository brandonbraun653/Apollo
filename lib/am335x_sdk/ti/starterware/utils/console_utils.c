/**
 *  \file  console_utils.c
 *
 *  \brief  This file contains generic wrapper functions for console utilities
 *          which allow user to configure the console type and redirect all the
 *          console Input/Output to the console type selected.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <error.h>
#include <types.h>
#include <misc.h>
#include <console_utils.h>
#include "console_utils_uart.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief Active console interface type. */
static consoleUtilsType_t gConsoleUtilsType = CONSOLE_UTILS_TYPE_UART;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t CONSOLEUtilsInit(void)
{
    /*
     * Initializes the UART with appropriate Baud rate and Line
     * characteristics for use as console.
     */
    return CONSOLEUtilsUartInit();
}

consoleUtilsType_t CONSOLEUtilsGetType(void)
{
    return gConsoleUtilsType;
}

int32_t CONSOLEUtilsSetType(consoleUtilsType_t consoleType)
{
    int32_t retStatus = E_FAIL;

    if(consoleType < CONSOLE_UTILS_TYPE_MAX)
    {
        gConsoleUtilsType = consoleType;
        retStatus = S_PASS;
    }
    else
    {
        CONSOLEUtilsUartPutStr("Error! Invalid Console selection\r\n");
    }

    return retStatus;
}

int32_t CONSOLEUtilsGetc(void)
{
    int32_t retChar = '\0';

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        retChar = getchar();
        /*
         * The input stream stdin is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdin);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        retChar = CONSOLEUtilsUartGetChar();
    }

    return retChar;
}

int32_t CONSOLEUtilsPutc(int32_t character)
{
    int32_t retChar = '\0';

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        retChar = putchar(character);
        /*
         * the output stream of the CCS console is line buffered
         * so prints on the console do not appear until a newline is entered
         * to avoid this we flush the buffer explicitly
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        retChar = CONSOLEUtilsUartPutChar(character);
    }

    return retChar;
}

uint8_t *CONSOLEUtilsGets(uint8_t *pRxBuffer, int32_t size)
{
    uint8_t *pBuf = (void *)NULL;

    if(NULL != pRxBuffer)
    {
        if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
        {
            /*
             * Adding a compile time check to reduce the binary size
             * if semihosting is not needed.
             */
            #if defined(SEMIHOSTING)
            pBuf = (uint8_t *)fgets((char *)pRxBuffer, size, stdin);
            /*
             * The input stream stdin is flushed to avoid reading unwanted
             * characters from the CCS console
             */
            fflush(stdin);
            #else
            CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
            #endif
        }
        else
        {
            pBuf = CONSOLEUtilsUartGetStr(pRxBuffer, size);
        }
    }

    return pBuf;
}

int32_t CONSOLEUtilsPuts(const char *pString)
{
    int32_t retStatus = E_FAIL;

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        retStatus = fputs(pString, stdout);
        /*
         * the output stream of the CCS console is line buffered
         * so prints on the console do not appear until a newline is entered
         * to avoid this we flush the buffer explicitly
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        retStatus = CONSOLEUtilsUartPutStr(pString);
    }

    return retStatus;
}

#ifndef DDRLESS
int32_t CONSOLEUtilsPrintf(const char *pFormat, ...)
{
    va_list arg;
    int32_t retStatus = E_FAIL;

    /* Start the variable arguments processing. */
    va_start (arg, pFormat);

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size if semihosting
         * is not needed.
         */
        #if defined(SEMIHOSTING)
        retStatus = vprintf(pFormat, arg);
        /*
         * The input stream stdout is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        retStatus = CONSOLEUtilsUartPrintFmt(pFormat, arg);
    }

    /* End the variable arguments processing. */
    va_end(arg);
    return retStatus;
}
#endif

int32_t CONSOLEUtilsScanf(const char *pFormat, ...)
{
    va_list arg;
    int32_t retStatus = E_FAIL;

        /* Start the variable argument processing. */
        va_start(arg, pFormat);

        if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
        {
            /*
             * Adding a compile time check to reduce the binary size
             * if semihosting is not needed.
             */
            #if defined(SEMIHOSTING)
            retStatus = vscanf(pFormat, arg);
            /*
             * The input stream stdout is flushed to avoid reading unwanted
             * characters from the CCS console
             */
            fflush(stdin);
            #else
            CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
            retStatus = E_FAIL;
            #endif
        }
        else
        {
            retStatus = CONSOLEUtilsUartScanFmt(pFormat, arg);
        }

        /* End the variable argument processing. */
        va_end(arg);

    return retStatus;
}

int32_t CONSOLEUtilsGetNonBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
                                        void *pVar,
                                        uint32_t dataType,
                                        uint32_t *pStatus)
{
    int32_t retStatus = E_FAIL;

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        CONSOLEUtilsUartPutStr("Note! Non-Blocking input mode is not supported by"
            " SemiHosting. Use UART console interface to enter input.\r\n");
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        retStatus = E_FAIL;
        #endif
    }

    retStatus = CONSOLEUtilsUartGetNonBlockingInput(pRxConsoleBuf, pVar, dataType, pStatus);

    return retStatus;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Definitions                            */
/* -------------------------------------------------------------------------- */

void ConsoleUtilsInit(void)
{
    /*
     * Initializes the UART with appropriate Baud rate and Line
     * characteristics for use as console.
     */
    CONSOLEUtilsUartInit();
}

void ConsoleUtilsSetType(consoleUtilsType_t consoleFlag)
{
    if(consoleFlag < CONSOLE_UTILS_TYPE_MAX)
    {
        gConsoleUtilsType = consoleFlag;
    }
    else
    {
        CONSOLEUtilsUartPutStr("Error! Invalid Console selection\r\n");
    }
}

void ConsoleUtilsPrintf(const char *string, ...)
{
    va_list arg;

    /* Start the variable arguments processing. */
    va_start (arg, string);

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        vprintf(string, arg);
        /*
         * The input stream stdout is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        CONSOLEUtilsUartPrintFmt(string, arg);
    }
    /* End the variable arguments processing. */
    va_end(arg);
}

int32_t ConsoleUtilsScanf(const char *format, ...)
{
    va_list arg;
    int32_t inputStatus = -1;

    /* Start the variable argument processing. */
    va_start(arg, format);

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        inputStatus = vscanf(format, arg);
        /*
         * The input stream stdout is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdin);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        inputStatus = CONSOLEUtilsUartScanFmt(format, arg);
    }
    /* End the variable argument processing. */
    va_end(arg);
    return inputStatus;
}

char* ConsoleUtilsGets(char *rxBuffer, int32_t size)
{
    char *pBuf = (void *)0;

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        pBuf = fgets(rxBuffer, size, stdin);
        /*
         * The input stream stdin is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdin);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        pBuf = (char *)CONSOLEUtilsUartGetStr((uint8_t *)rxBuffer, size);
    }

    return pBuf;
}

void ConsoleUtilsPuts(char *string)
{
    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        fputs(string, stdout);
        /*
         * the output stream of the CCS console is line buffered
         * so prints on the console do not appear until a newline is entered
         * to avoid this we flush the buffer explicitly
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        CONSOLEUtilsUartPutStr(string);
    }
}

uint8_t ConsoleUtilsGetChar(void)
{
    uint8_t byte = 0U;

    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        byte = getchar();
        /*
         * The input stream stdin is flushed to avoid reading unwanted
         * characters from the CCS console
         */
        fflush(stdin);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        byte = CONSOLEUtilsUartGetChar();
    }

    return byte;
}

void ConsoleUtilsPutChar(uint8_t byte)
{
    if(CONSOLE_UTILS_TYPE_DEBUGGER == gConsoleUtilsType)
    {
        /*
         * Adding a compile time check to reduce the binary size
         * if semihosting is not needed.
         */
        #if defined(SEMIHOSTING)
        putchar(byte);
        /*
         * the output stream of the CCS console is line buffered
         * so prints on the console do not appear until a newline is entered
         * to avoid this we flush the buffer explicitly
         */
        fflush(stdout);
        #else
        CONSOLEUtilsUartPutStr("Error! SemiHosting Support is not enabled\r\n");
        #endif
    }
    else
    {
        CONSOLEUtilsUartPutChar(byte);
    }
}
