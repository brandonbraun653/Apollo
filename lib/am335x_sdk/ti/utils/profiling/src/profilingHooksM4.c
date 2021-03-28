/*
 * Copyright (c) 2015 - 2018, Texas Instruments Incorporated
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
 *  @file    profilingHooksM4.c
 *
 *  @brief   M4 Implementations of the runtime programming hooks of the Processor SDK Profiling Tool.
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
 *  The `_ENABLE_BM` flag is used to indicate in a class at compiletime whether
 *  or not profiling is being used.
 *
 *  For best results, ensure that the optimization levels are consistent between
 *  the library and the project (typically -O3, or optimization level 3).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "profilingHooks.h"

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
uint32_t lvl = 0;

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
#ifdef __cplusplus
#pragma FUNC_CANNOT_INLINE
#else
#pragma FUNC_CANNOT_INLINE(empty_fn);
#endif
void empty_fn(void); /*for misra warnings*/
void empty_fn(void){
}

/* IPU UNICACHE SCTM Registers:
 * Note that there are multiple counters that can be enabled, but for simplicity
 * only the first registers are used. (eg. CACHE_SCTM_CTCR_WOT_j is stored at
 * addresses 0x0000 0108 + 0x4*i for i = 0 to 1) For others, see TRM
 * reference 7.4.3 */
volatile uint32_t *CACHE_SCTM_CTCR_WOT_j = (uint32_t *)0x55080508;
volatile uint32_t *CACHE_SCTM_CTCNTL = (uint32_t *)0x55080400;
volatile uint32_t *CACHE_SCTM_CTCNTR_k = (uint32_t *)0x055080588;

/*!
 *  @brief    TI Toolchain Utils Entry Hook
 *
 *  @ingroup pdk_profiling_hooks
 *
 *  Instruments the entry point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at entry of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_entry(void (* func_addr)(void)){
    if (log_idx == 0){
        /* SCTM Global Enable: Assign CACHE_SCTM_CTCNTL[0] = 1 to enable all
         * individual counters. Must be enabled for ANY counter to be configured */
        *CACHE_SCTM_CTCNTL = *CACHE_SCTM_CTCNTL | (uint32_t)1;
        /* Counter Enable: Assign CACHE_SCTM_CTCR_WOT_j[0] = 1 to increment */
        *CACHE_SCTM_CTCR_WOT_j = *CACHE_SCTM_CTCR_WOT_j | (uint32_t)1;
        /* Counter Value: Register containing the value of the configured counter */
        uint32_t val = *CACHE_SCTM_CTCNTR_k;
        uint32_t entry_offset = 0;
        uint32_t exit_offset = 0;
        log_idx++;
        log_idx++;
        int32_t i;
        for (i = 0; i < 10; i++){
            empty_fn();
        }
        elemlog[0].isEnter = 2;
        elemlog[0].this_fn = 3;
        elemlog[0].call_site = 1;
        /*Taking 10 sample and subtracting (exit_log - entry log) of present for calculating the entry offset*/
        for(i=1;i<=10;i++)
        {
            entry_offset += (elemlog[(2*i)+1].timestamp - elemlog[(2*i)].timestamp);
        }
        /* Saving the average of 10 sample */
        elemlog[0].timestamp = entry_offset/10U;
        elemlog[1].isEnter = 2;
        elemlog[1].this_fn = 3;
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
    if (log_idx < MAX_LOG){
        elemlog[log_idx].isEnter = 1;
        elemlog[log_idx].this_fn = (int32_t)func_addr;
        elemlog[log_idx].timestamp = *CACHE_SCTM_CTCNTR_k;
      log_idx++;
    }
}

/*!
 *  @brief    TI Toolchain Utils Exit Hook
 *
 *  @ingroup pdk_profiling_hooks
 *
 *  Instruments the exit point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at end of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_exit(void (* func_addr)(void)){
    if (log_idx < MAX_LOG){
        elemlog[log_idx].isEnter = 0;
        elemlog[log_idx].this_fn = (int32_t)func_addr;
        elemlog[log_idx].timestamp = *CACHE_SCTM_CTCNTR_k;
        log_idx++;
    }
}

void TaskRegisterId(int32_t hookSetId); /*for misra warnings*/
#ifdef __cplusplus
#pragma NO_HOOKS
#else
#pragma NO_HOOKS (TaskRegisterId)
#endif
void TaskRegisterId(int32_t hookSetId)
{
	CurrentTaskHookSetId = hookSetId;
    if(MaxTaskHookSetId < CurrentTaskHookSetId)
    {
        MaxTaskHookSetId = CurrentTaskHookSetId;
    }
}

/* ======== mySwitch ========
* invoked whenever a Task switch occurs/is made ready to run */
void mySwitch(const void* prev, const void* next); /*for misra warnings*/
#ifdef __cplusplus
#pragma NO_HOOKS
#else
#pragma NO_HOOKS (mySwitch)
#endif
void mySwitch(const void* prev, const void* next)
{
    if (log_idx < MAX_LOG){
        elemlog[log_idx].isEnter = 3;
        elemlog[log_idx].this_fn = (int32_t)next;
        elemlog[log_idx].call_site = (int32_t)prev;
        elemlog[log_idx].timestamp = *CACHE_SCTM_CTCNTR_k;
        log_idx++;
    }
}
