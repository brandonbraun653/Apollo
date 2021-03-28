/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
 *  ======== counter_32k.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_synctimer.h>
#include <ti/osal/src/nonos/counter_32k/v0/counter_32k.h>

/* Soc specific time delay in ticks, 1 tick = 1ms */
int32_t Counter32k_delay(uint32_t nTicks)
{
    uintptr_t timerBase = (uintptr_t) SOC_COUNTER_32K_BASE;
    uint32_t  exitCount = 0;

    uint32_t baseTime, sampTime;
    uint32_t endTick = nTicks << 5;

    baseTime = (uint32_t) HW_RD_REG32((uint32_t)timerBase + (uint32_t)CSL_SYNCTIMER_CR);
    /* Every 32 cycle increment is 1ms */
    do {
      sampTime = (uint32_t) HW_RD_REG32((uint32_t)timerBase + (uint32_t)CSL_SYNCTIMER_CR);
      if (sampTime == baseTime) {
        exitCount++;
      }
      /* Exit the loop if counter_32k is not running */
      if (exitCount == nTicks) {
         break;
      }
    } while ((sampTime - baseTime) <= endTick);

    return(osal_OK);
}
/* Nothing past this point */
