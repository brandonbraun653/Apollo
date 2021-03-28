/*
 * audioSample_io.c
 *
 * This file contains the test / demo code to demonstrate the Audio component
 * driver functionality on SYS/BIOS 6.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
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

/** \file     audioSample_io.c
 *
 *  \brief    sample application for profiling
 *
 *             (C) Copyright 2017, Texas Instruments, Inc
 */

/* ========================================================================== */
/*                            INCLUDE FILES                                   */
/* ========================================================================== */

#include <xdc/std.h>
#include "MCASP_log.h"
#include "stdio.h"
#include "string.h"
#include "profiling.h"
#include <ti/osal/osal.h>

static uint64_t total_ticks=0;
static uint32_t start_time, end_time,ticks_per_ms,total_num_frames=0;

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
static uint32_t time_diff(uint32_t s_time, uint32_t e_time) 
{
	uint32_t ticks_lapsed;
	if(e_time > s_time) {
	   ticks_lapsed=e_time-s_time;
	} else {
		ticks_lapsed = (0xFFFFFFFF - s_time) + e_time;
	}
    return(ticks_lapsed);
}

void profiling_init()
{
   uint32_t ticks_diff;
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

	MCASP_log("Ticks Calibration Start\n");
	start_time=readTime32();
	Osal_delay(1000);
	end_time=readTime32();
    ticks_diff=time_diff(start_time,end_time);
	ticks_per_ms = ticks_diff/(1*1000);

	MCASP_log("Ticks Calibration End after 1 seconds\n");
	MCASP_log("Ticks per msec= %u, Time Diff = %u , start =%u, end=%u",ticks_per_ms,ticks_diff, start_time,end_time);
}

void profiling_start()
{
   start_time=readTime32();
}

void profiling_end()
{
   end_time=readTime32();
   total_ticks+=time_diff(start_time,end_time);
   total_num_frames++;
}

void profiling_display_results() 
{
	uint32_t ms_per_frame;
	uint32_t ticks_per_frame;

    ticks_per_frame=total_ticks/total_num_frames;
    ms_per_frame=total_ticks/(total_num_frames*ticks_per_ms);
    MCASP_log("\n Ticks per frame = %u ",ticks_per_frame);
    MCASP_log("\n Time elapsed per frame = %u ms",ms_per_frame);
    MCASP_log("\n Total Time elapsed for %d frames = %u seconds",total_num_frames,(ms_per_frame*total_num_frames)/1000);
}
