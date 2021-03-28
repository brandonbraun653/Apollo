/**
 * \copyright  Copyright (C) 2016-2019 Texas Instruments Incorporated -
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

#include "usb_osal.h"
#include "timer.h"
#include "hardware.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/arch/csl_arch.h>


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


/* cadence debug print function - commented out when done */
void DbgPrint(const char *pcString, ...)
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

void consolePuts(const char* buffer, int32_t size)
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



#if (defined(SOC_AM65XX) || defined(SOC_J721E))
static uint64_t pmuOverhead = 0;
#endif

void usb_osalInitPerfUnit(void)
{
#if (defined(SOC_AM65XX) || defined(SOC_J721E))
    #ifdef BUILD_MPU
    CSL_initPmu();

    pmuOverhead = CSL_getPmuCycleCountOverhead();
    #else

    uint32_t val;

    pmuOverhead = 0;
    CSL_armR5PmuCfg(0, 0, 1);
    /* Clear the overflow */
    val = CSL_armR5PmuReadCntrOverflowStatus();
    val &= 0x80000000;

    CSL_armR5PmuClearCntrOverflowStatus(val);
    CSL_armR5PmuCfgCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 
                        CSL_ARM_R5_PMU_EVENT_TYPE_CYCLE_CNT);

    CSL_armR5PmuEnableAllCntrs(1);
    CSL_armR5PmuEnableCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 1);

    #endif
#else
#if !(defined(SOC_OMAPL137) || defined(SOC_OMAPL138) || defined(SOC_J721E))
    /* PMCR
    31......24 23......16 15....11 10.....6  5 4 3 2 1 0
        IMP      IDCODE       N       Res   DP X D C P E
    [31:24] IMP: Implementer code; read-only
    [23:16] IDCODE: Identification code; read-only
    [15:11] N: Number of event counters; read-only
    [10:6] Reserved
    [5] DP: Disable cycle counter in prohibited regions; r/w
    [4] X: Export enable; r/w
    [3] D: Clock divider - PMCCNTR counts every 64 clock cycles when enabled; r/w
    [2] C: Clock counter reset; write-only
    [1] P: Event counter reset; write-only
    [0] E: Enable all counters; r/w
    */
    __asm__ __volatile__ ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x17));

    /* PMCNTENSET - Count Enable Set Register */
    __asm__ __volatile__ ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));

    /* PMOVSR - Overflow Flag Status Register */
    __asm__ __volatile__ ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
#endif
#endif
}


/* 
 * start the cycle counter unit
 * 
 */
void usb_osalStartPerfCounter(void)
{
#if (defined(SOC_AM65XX) || defined(SOC_J721E))
#if BUILD_MPU
    CSL_startPmuCycleCounter();
#else
#endif
#endif
}

void usb_osalStopPerfCounter(void)
{
#if (defined(SOC_AM65XX) || defined(SOC_J721E))
#if BUILD_MPU
    CSL_stopPmuCycleCounter();
#endif
#endif
}

void usb_osalClearPerfCounter(void)
{
#if (defined(SOC_AM65XX) || defined(SOC_J721E))
#if BUILD_MPU
    CSL_clearPmuCycleCounter();
#endif
#endif
}

/* 
 * read time stamp count 
 * Using SOC/ARM/DSP provided performance measure counter unit
 * 
 */
uint64_t usb_osalGetPerfCounter(void)
{
    uint64_t timeVal = 0;

#if (defined(SOC_AM65XX) || defined(SOC_J721E))
#if defined(BUILD_MPU)
    timeVal = CSL_getPmuCycleCount() - pmuOverhead;
#endif
#if defined(BUILD_MCU)
    timeVal =CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
    timeVal -= pmuOverhead;
#endif
#else
#if !(defined(SOC_OMAPL137) || defined(SOC_OMAPL138) || defined(SOC_J721E))
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal)); 
#endif
#endif

    return timeVal;
}



/* end of OSAL implementation */


