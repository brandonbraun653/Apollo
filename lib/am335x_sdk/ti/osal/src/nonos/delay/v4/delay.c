/*
 * Copyright (c) 2017-2018, Texas Instruments Incorporated
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
#include <ti/csl/soc.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/nonos/Nonos_config.h>

static void osal_core_delay(uint32_t nTicks);

#if defined (__C7100__)
static void osal_core_delay(uint32_t nTicks)
{
    /** Todo: Need to implement */
}
#else
static void osal_core_delay(uint32_t nTicks)
{
    TimeStamp_Struct    timestamp64;
    uint32_t            msTick = 0;
    uint64_t            start, end, diff;
    int32_t             tsFreqKHz;

    /* Get the frequency of the timeStatmp provider */
    tsFreqKHz  = osalArch_TimeStampGetFreqKHz();

    /* Make sure init is done, if not done already */
    osalArch_TimestampInit();

    osalArch_TimestampGet64(&timestamp64);

    start = ((uint64_t) timestamp64.hi << 32) | timestamp64.lo;

    do {
        osalArch_TimestampGet64(&timestamp64);
        end = ((uint64_t) timestamp64.hi << 32) | timestamp64.lo;

        diff  = end - start;

        if ((int64_t)diff >= tsFreqKHz)
        {
            msTick++;
            start = end;
        }
        else
        {
           /* No action */
        }
    } while (msTick < nTicks);

    return;
}
#endif


/* Osal delay implementation for bare metal,
 * where nTicks is number of ticks in 1ms
 */
int32_t Osal_delay(uint32_t nTicks)
{
  /* Delay by number of ticks */
   osal_core_delay(nTicks);
   return (osal_OK);
}

#ifdef _MSC_VER
/* Below functions are not defined for windows host emulation build so define dummy functions for build to work */
void osalArch_TimestampGet64(TimeStamp_Struct *tStamp)
{
}

void    osalArch_TimestampInit(void)
{
}

int32_t  osalArch_TimeStampGetFreqKHz(void)
{
    /* R5F time Stamp is via PMU, which runs at CPU speed */
    return (0);
}
#endif

/* nothing past this point */
