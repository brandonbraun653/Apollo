/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
/*
 *  ======== delay.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>
#if defined (_TMS320C6X)
#include <ti/csl/csl_chipAux.h>
#endif

/* General purpose timer for KeyStone devices*/
static uint32_t Delay_readTime32(void)
{
    uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}

/* Osal delay implementation for bare metal,
 * where nTicks is number of ticks in 1ms
 */
int32_t Osal_delay(uint32_t nTicks)
{
    uint32_t extClk;
    CSL_PllcType pllType;
    uint32_t  freq, start, delayCount;

    pllType = SOC_PLL_TYPE;

    extClk = gOsal_HwAttrs.extClkKHz;

#if defined (_TMS320C6X)
    uint32_t  tscl1, tscl2;
    /* Read TSCL */
    tscl1 = CSL_chipReadTSCL();
    /* Read the TSCL again */
    tscl2 = CSL_chipReadTSCL();
    /* if they are same, it is not counting, initialize it to count */
    if (tscl1 == tscl2) {
      CSL_chipWriteTSCL(0);
    }
#endif

    start = Delay_readTime32();
    freq = CSL_BootCfgGetPllFreq(pllType, extClk);

    delayCount = nTicks * freq;
    while ((Delay_readTime32() - start) < delayCount);	
    return(osal_OK);
}
/* nothing past this point */
