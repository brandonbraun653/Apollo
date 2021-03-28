/**
 * @file   board_utils.c
 *
 * @brief  This file includes the Keystone board level functions
 */
/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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

#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>
#if defined (_TMS320C6X)
#include <ti/csl/csl_chipAux.h>
#endif

#include "board_utils.h"

/**
* \brief  This API gets the input clock frequency.
*
* \param  pll         PLL controller type.
*
* \return input clock to the PLL controller.
*
* \note   This API gets the input clock frequency based on the
*         PLL controller type.\n
*/
/** ============================================================================
 *   @n@b BOARD_getExternalClk
 *
 *   @b Description
 *   @n  This function is used to get the exteranl clock frequency.
 *
 *
 *   @b Arguments
 *   @verbatim
            pll             Specifies the PLL controller type.
      @endverbatim
 *
 *   <b> Return Value </b>
 *   @n external clock frequency to the PLL controller, if 0, means failure
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   None
 *
 *   @b Affects
 *   @n None.
 *
 *   @b Example
 *   @verbatim
        uint32_t     ext_clk;

        ext_clk = BOARD_getExternalClk(CSL_PLL_SYS);

    @endverbatim
 * ===========================================================================
 */
uint32_t BOARD_getExternalClk(CSL_PllcType pll)
{
    return Board_ext_clk[pll];
}

/** ============================================================================
 *   @n@b BOARD_initPerfCounters
 *
 *   @b Description
 *   @n  This function enables the A15 performance counters.
 *
 *
 *   @b Arguments

 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   None
 *
 *   @b Affects
 *   @n None.
 *
 *   @b Example
 *   @verbatim
        BOARD_initPerfCounters();
    @endverbatim
 * ===========================================================================
 */
void BOARD_initPerfCounters()
{
#if defined (_TMS320C6X) || defined(__TI_ARM_V7M4__)
    // Do nothing for C6x and M4 cores
#else
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
}

static uint32_t readTime32(void)
{
    uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}

/** ============================================================================
 *   @n@b BOARD_delay
 *
 *   @b Description
 *   @n  This function delays a certain period of time in micro seconds.
 *
 *
 *   @b Arguments
 *   @verbatim
            usecs           Specifies the time to delay in micro second.
      @endverbatim
 *   @n To prevent 32-bit counter roll over, the delay time should be less than 2^32/freq_in_mhz (usec)
 *      e.g. for 1000Mhz PLL clock, delay time should be less than ~4.2 seconds.
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   None
 *
 *   @b Affects
 *   @n None.
 *
 *   @b Example
 *   @verbatim
        uint32_t     delay = 5;

        BOARD_delay(delay);

    @endverbatim
 * ===========================================================================
 */
void BOARD_delay(uint32_t usecs)
{
    uint32_t ext_clk, freq, start, delayCount;
    CSL_PllcType pllType;

#if defined (_TMS320C6X)
    pllType = CSL_PLL_SYS;
    CSL_chipWriteTSCL(0);
#else
#if defined(SOC_K2E)
    pllType = CSL_PLL_SYS;
#else
    pllType = CSL_PLL_ARM;
#endif
#endif

    start = readTime32();
    ext_clk = BOARD_getExternalClk(pllType);
    freq = CSL_BootCfgGetPllFreq(pllType, ext_clk);

    delayCount = usecs * (freq / 1000000);
    while ((readTime32() - start) < delayCount);
}
