/**
 *  \file   MMCSD_log.h
 *
 *  \brief  This file contains the prototypes for the log print functions. By
            default the prints will be directed to serial console using UART.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _PROFILING_H
#define _PROFILING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifndef BARE_METAL
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#endif


#include "MMCSD_log.h"

typedef struct {
   char name[64];
   uint32_t start_tick;
   uint32_t end_tick;
   uint32_t total_ticks;
   uint32_t total_ticks_master;
   uint32_t num_iterations;
   uint32_t total_bytes_transferred;
   
   float total_time_ms;
   float total_time_percentage;/* w.r.t master */
   float time_per_iter_ms;
   float bandwidth_mbytes_per_sec;

} profilePoint_t;


typedef enum {
	  PROFILE_MMCSD_WRITE=0,
	  PROFILE_MMCSD_READ=1,
	  PROFILE_MMCSD_WRITE_CMD_WAIT=2,
	  PROFILE_MMCSD_WRITE_DATA_WAIT=3,
	  PROFILE_MMCSD_WRITE_DATA_TRANSFER_SUBMIT=4,
	  PROFILE_MMCSD_WRITE_DATA_TRANSFER_COMPLETE=5,
	  PROFILE_MMCSD_READ_CMD_WAIT=6,
	  PROFILE_MMCSD_READ_DATA_WAIT=7,
	  PROFILE_MMCSD_READ_DATA_TRANSFER_SUBMIT=8,
	  PROFILE_MMCSD_READ_DATA_TRANSFER_COMPLETE=9,
} profile_ProfilePoint_e;

#define PROFILE_MAX_POINTS 10
typedef struct {
   uint32_t ticks_per_ms;
   profilePoint_t profile_Points[PROFILE_MAX_POINTS];
} profile_Context_t;


typedef struct {
 	float bandwidth_mbytes_per_sec;
	uint64_t num_bytes_transferred;
} mmcsdTestBenchmarkMeasurements_t;

typedef struct {
	bool valid;
	mmcsdTestBenchmarkMeasurements_t read;
	mmcsdTestBenchmarkMeasurements_t write;
} mmcsdTestBenchmarkElem_t;


#define MMCSD_TEST_MAX_NUM_BENCHMARKS (5U) /* 0.25 MB, 0.5 MB, 1 MB , 2MB, 5 MB*/

typedef struct {
	mmcsdTestBenchmarkElem_t RAW_measurements[MMCSD_TEST_MAX_NUM_BENCHMARKS];
	mmcsdTestBenchmarkElem_t FATFS_measurements[MMCSD_TEST_MAX_NUM_BENCHMARKS];
} mmcsdTestBenchmarks_t;

void profile_initPerfCounters();
void profile_calibrate();
void profile_start_point(uint32_t profile_id);
void profile_end_point(uint32_t profile_id);
void profile_calculate_time(uint32_t profile_id);
void profile_calculate_all_time();
void profile_display_all();
void profile_reset_results();
void profile_calculate_results(uint32_t total_bytes_transferred);
void profile_display_results(uint32_t total_bytes_transferred);
void profile_init();
void mmcsd_display_benchmarks(mmcsdTestBenchmarks_t *benchmarks_ptr);
void mmcsd_reset_benchmarks(mmcsdTestBenchmarkElem_t *benchmark_elem_ptr);
void mmcsd_store_benchmarks(mmcsdTestBenchmarkElem_t *benchmark_elem_ptr,uint32_t bytes_transferred);
extern profile_Context_t profile_Context;

#ifdef __cplusplus
}
#endif

#endif /* _PROFILING_H */
