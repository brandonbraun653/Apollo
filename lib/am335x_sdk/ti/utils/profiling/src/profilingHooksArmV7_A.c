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
/**
 *  @file    profilingHooksArmV7_A.c
 *
 *  @brief   ARM Implementations of the runtime programming hooks of the Processor SDK Profiling Tool.
 *
 *  For more information, see:
 *  - @subpage profCCS
 *  - @subpage profDSS
 *
 *  ## Usage ##
 *
 *  Applications that are included in a profiling session must  set these
 *  compiler flags for the desired platform:
 *    - ARM: `-finstrument-functions -gdwarf-3 -g`
 *    - DSP: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
 *    - M4: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
 *
 *  For best results, ensure that the optimization levels are consistent between
 *  the library and the project (typically -O3, or optimization level 3).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "profilingHooks.h"
#include "profiling_osal.h"


int32_t CurrentTaskHookSetId, MaxTaskHookSetId;

/*!
 *  @brief    Maximum log count
 *
 *  This is a predefined value to indicate when the instrumentation hooks should
 *  stop logging data. This is important for applications that have long polling
 *  loops or a device that has a small cache.
 */
#define MAX_LOG (1U*1024U*1024U)

uint32_t log_idx = 0;

/*!
 *  @brief    Utils profiling log structure
 *
 *  Utils log elements have a predefined structure of four words (to avoid the
 *  need of malloc) and are stored in an array of predefined length, `elemlog`.
 */
typedef struct{
    /*! Indicates either enter or exit */
    int32_t isEnter;
    /*! Pointer address of the function in current context */
    int32_t this_fn;
    /*! Optional: Pointer address of calling function in current context */
    int32_t call_site;
    /*! Timestamp of the entry or exit */
    uint32_t timestamp;
}utilsProfilingElem;

utilsProfilingElem elemlog[MAX_LOG] = {{0}};

/*!
 *  @brief    Empty function for time adjustment
 *
 *  @ingroup pdk_profiling_hooks
 *
 *  Nothing more than an empty function that is referenced to measure the time
 *  used by the instrumentation functions themselves. This is recorded and
 *  passed into post-processing for a more accurate result.
 */
void __attribute__ ((noinline)) empty_fn(void); /*for misra warnings*/
void __attribute__ ((noinline)) empty_fn(void){
}


/*!
 *  @brief    ARMv7 GCC Utils init function
 *
 *  @ingroup pdk_profiling_hooks
 *
 *  Instruments the entry point and then calculate the entry and exit offset,
 *  the offset are stored in the first 2 elements of elem_log.
 *
 *  @param    none
 *
 */
void __attribute__((no_instrument_function))profiling_init(void){
    uint32_t entry_offset = 0;
    uint32_t exit_offset = 0;
    log_idx++;
    log_idx++;
    int32_t i;
    for (i = 0; i < 10; i++){
        empty_fn();
    }
    elemlog[0].isEnter = 2;
    elemlog[0].this_fn = 1;
    elemlog[0].call_site = 1;
    /*Taking 10 sample and subtracting (exit_log - entry log) of present for calculating the entry offset*/
    for(i=1;i<=10;i++)
    {
        entry_offset += (elemlog[(2*i)+1].timestamp - elemlog[(2*i)].timestamp);
    }
    /* Saving the average of 10 sample */
    elemlog[0].timestamp = entry_offset/10U;
    elemlog[1].isEnter = 2;
    elemlog[1].this_fn = 1;
    elemlog[1].call_site = 2;
    /* Taking 9 sample and subtracting (entry_log of next - exit_log of present) for calculating the exit offset*/
    for(i=2;i<=10;i++)
    {
        exit_offset += (elemlog[(2*i)].timestamp - elemlog[(2*i)-1].timestamp);
    }
    /* Saving the average of 9 sample */
    elemlog[1].timestamp = exit_offset/9U;
    log_idx = 2U;
}

void __attribute__((no_instrument_function))TaskRegisterId(int32_t hookSetId); /*for misra warnings*/
void __attribute__((no_instrument_function))TaskRegisterId(int32_t hookSetId)
{
	CurrentTaskHookSetId = hookSetId;
    if(MaxTaskHookSetId < CurrentTaskHookSetId)
    {
        MaxTaskHookSetId = CurrentTaskHookSetId;
    }
}


