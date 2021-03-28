/**
 * \copyright  Copyright (C) 2016-2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* 
 * This file contains implementation for usb_osal for bare metal USB examples 
 */
#include <stdio.h>
#include "types.h"

#ifdef TIRTOS
#include <xdc/runtime/System.h>
#endif

#include "hw_types.h"
#include "usb_osal.h"
#include "timer.h"
#include "hardware.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>


/* temporary OSAL implementation */

void vconsolePrint(const char* fmt, va_list argp)
{
#define MAX_LEN 300

    char buffer[MAX_LEN+1];

#ifdef TIRTOS
    System_vsnprintf(buffer, MAX_LEN, fmt, argp);
    /*System_printf("%s", buffer);
    System_flush();*/
    UART_printf("%s", buffer);
#else
    /* bare metail */
    vsnprintf(buffer, MAX_LEN, fmt, argp);
    UART_printf("%s", buffer);
#endif
}

void consolePrintf(const char *pcString, ...)
{
    va_list argp;

    va_start(argp, pcString);
    vconsolePrint(pcString, argp);
    va_end(argp);
}

void consoleGets(uint8_t* buffer, int32_t size)
{
    UART_gets((char*)buffer, size);
}

void consolePuts(int8_t* buffer, int32_t size)
{
    UART_puts((char*)buffer, size);
}

uint8_t consoleGetc(void)
{
    return UART_getc();
}

void consolePutc(uint8_t ch)
{
    UART_putc(ch);
}



void usb_osalDelayMs(uint32_t delay_ms)
{
    osalTimerDelay(delay_ms);
}


void usb_osalStartTimerMs(uint32_t ms)
{
    osalTimerStart(ms);
}

void usb_osalStopTimer()
{
    osalTimerStop();
}

uint32_t usb_osalIsTimerExpired()
{
    return osalTimerExpired();
}


void usb_osalDisableInterruptNum(uint32_t intNum)
{
    HwiP_disableInterrupt(intNum);
}

void usb_osalEnableInterruptNum(uint32_t intNum)
{
    HwiP_enableInterrupt(intNum);
}

uint32_t usb_osalHardwareIntDisable(void)
{
    return HwiP_disable();
}

void     usb_osalHardwareIntRestore(uint32_t intCx)
{
    HwiP_restore(intCx);
}


void usb_osalClearInterrupt(uint32_t intNum)
{
    HwiP_clearInterrupt(intNum);
}

/* end of OSAL implementation */


