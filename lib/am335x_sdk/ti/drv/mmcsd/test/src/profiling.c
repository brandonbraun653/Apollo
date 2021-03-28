/**
 *  \file   main.c
 *
 *  \brief  Test application main file. The test application demonstrates
 *          raw data write & read on a MMCSD device.
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


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <string.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/osal/osal.h>
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_chip.h>
#include "MMCSD_log.h"
#include "profiling.h"
#include <ti/csl/arch/csl_arch.h>
profile_Context_t profile_Context;
char uart_print_string[64];
void profile_initPerfCounters()
{
#if defined(__TI_ARM_V7M4__)
       extern volatile uint32_t *CACHE_SCTM_CTCR_WOT_j;
       extern volatile uint32_t *CACHE_SCTM_CTCNTL;
       extern volatile uint32_t *CACHE_SCTM_CTCNTR_k;

       /* SCTM Global Enable: Assign CACHE_SCTM_CTCNTL[0] = 1 to enable all
         * individual counters. Must be enabled for ANY counter to be configured */
        *CACHE_SCTM_CTCNTL = *CACHE_SCTM_CTCNTL | (uint32_t)1;
        /* Counter Enable: Assign CACHE_SCTM_CTCR_WOT_j[0] = 1 to increment */
        *CACHE_SCTM_CTCR_WOT_j = *CACHE_SCTM_CTCR_WOT_j | (uint32_t)1;
#elif defined (_TMS320C6X) 
    // Do nothing for C6x and M4 cores
#elif defined(BUILD_MPU)
        CSL_initGTC();
#elif defined(BUILD_MCU)
        uint32_t val;
        CSL_armR5PmuCfg(0, 0, 1);
        /* Clear the overflow */
        val = CSL_armR5PmuReadCntrOverflowStatus();
        val &= 0x80000000;
        CSL_armR5PmuClearCntrOverflowStatus(val);
        CSL_armR5PmuCfgCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, CSL_ARM_R5_PMU_EVENT_TYPE_CYCLE_CNT);
        CSL_armR5PmuEnableAllCntrs(1);
        CSL_armR5PmuEnableCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 1);
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

    memset(&profile_Context,0,sizeof(profile_Context));
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_READ].name,"MMCSD_READ");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_WRITE].name,"MMCSD_WRITE");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_WRITE_CMD_WAIT].name,"PROFILE_MMCSD_WRITE_CMD_WAIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_WAIT].name,"PROFILE_MMCSD_WRITE_DATA_WAIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_SUBMIT].name,"PROFILE_MMCSD_WRITE_DATA_TRANSFER_SUBMIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_COMPLETE].name,"PROFILE_MMCSD_WRITE_DATA_TRANSFER_COMPLETE");

    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_READ_CMD_WAIT].name,"PROFILE_MMCSD_READ_CMD_WAIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_WAIT].name,"PROFILE_MMCSD_READ_DATA_WAIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_SUBMIT].name,"PROFILE_MMCSD_READ_DATA_TRANSFER_SUBMIT");
    System_sprintf(profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_COMPLETE].name,"PROFILE_MMCSD_READ_DATA_TRANSFER_COMPLETE");

}

extern volatile uint32_t *CACHE_SCTM_CTCNTR_k;

static uint32_t readTime32(void)
{
    volatile uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#elif defined (__TI_ARM_V7M4__)
    timeVal = *CACHE_SCTM_CTCNTR_k;
//    MMCSD_log("Timeval=%u\n",*CACHE_SCTM_CTCNTR_k);
#elif defined(BUILD_MPU)
     timeVal = CSL_getGTCcount();
#elif defined(BUILD_MCU)
     timeVal=CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}
#ifdef MMCSD_CALIBRATION_TEST
void profile_calibration_test()
{
	uint32_t start_time, end_time,time_diff;
    float seconds_measured_by_ticks=0,milliseconds_measured_by_ticks=0;
	MMCSD_log("Calibration Test: Counting 5 seconds..\n");
	start_time=readTime32();
	Task_sleep(5000);
	end_time=readTime32();
	
    MMCSD_log("Calibration Test: End 5 seconds..\n");

	if(end_time > start_time) {
	   time_diff=end_time-start_time;
	} else {
		time_diff = (0xFFFFFFFF - start_time) + end_time;
	}
	milliseconds_measured_by_ticks = (float)((float)time_diff/(float)profile_Context.ticks_per_ms);
	seconds_measured_by_ticks = (float)milliseconds_measured_by_ticks/(float)1000;
	
    System_snprintf(uart_print_string,sizeof(uart_print_string)," Seconds measured by tick calculation is %5.2f",seconds_measured_by_ticks);
	
	MMCSD_log("CalibrationTest: %s\n",uart_print_string);
	
}
#endif
 
void profile_calibrate()
{
	uint32_t start_time, end_time,time_diff;
	MMCSD_log("Calibration Start\n");
	start_time=readTime32();
	Task_sleep(1000);
	end_time=readTime32();
	if(end_time > start_time) {
	   time_diff=end_time-start_time;
	} else {
		time_diff = (0xFFFFFFFF - start_time) + end_time;
	}
	profile_Context.ticks_per_ms = time_diff/(1*1000);
	MMCSD_log("Calibration: Ticks per ms is %d\n",profile_Context.ticks_per_ms);
	MMCSD_log("Calibration Completed\n");
#ifdef MMCSD_CALIBRATION_TEST	
	profile_calibration_test();
 #endif
}
void profile_init()	
{	
    profile_initPerfCounters();
    profile_calibrate();
}
void profile_start_point(uint32_t profile_id)
{
	profile_Context.profile_Points[profile_id].start_tick=readTime32();
}

void profile_end_point(uint32_t profile_id)
{
	uint32_t ticks_diff;
	profile_Context.profile_Points[profile_id].end_tick=readTime32();
	if(profile_Context.profile_Points[profile_id].end_tick > profile_Context.profile_Points[profile_id].start_tick) {
	   ticks_diff=profile_Context.profile_Points[profile_id].end_tick-profile_Context.profile_Points[profile_id].start_tick;
	} else {
	   ticks_diff = (0xFFFFFFFF - profile_Context.profile_Points[profile_id].start_tick) + profile_Context.profile_Points[profile_id].end_tick;
	}
    profile_Context.profile_Points[profile_id].total_ticks+= ticks_diff;
	profile_Context.profile_Points[profile_id].num_iterations++;
}

void profile_calculate_time(uint32_t profile_id)
{
    if(profile_Context.profile_Points[profile_id].num_iterations>0) {
      profile_Context.profile_Points[profile_id].total_time_ms =
	                (float)(profile_Context.profile_Points[profile_id].total_ticks/
	                (float)profile_Context.ticks_per_ms);

     if(profile_Context.profile_Points[profile_id].total_ticks_master>0) {
        profile_Context.profile_Points[profile_id].total_time_percentage =
	                              100* ((float)profile_Context.profile_Points[profile_id].total_ticks/
	                		      (float)profile_Context.profile_Points[profile_id].total_ticks_master);
      }

      profile_Context.profile_Points[profile_id].time_per_iter_ms = profile_Context.profile_Points[profile_id].total_time_ms/
	                                                           profile_Context.profile_Points[profile_id].num_iterations;
	  /* In M Bytes per sec */
	  profile_Context.profile_Points[profile_id].bandwidth_mbytes_per_sec =
                                                	           (float)(((float)profile_Context.profile_Points[profile_id].total_bytes_transferred)/(1024*1024))/
	                                                                    (float)(profile_Context.profile_Points[profile_id].total_time_ms/1000);

    }
}

void profile_calculate_all_time()
{
    int i;
	for(i=0;i<PROFILE_MAX_POINTS;i++) {
	   profile_calculate_time(i);
	}
}

void profile_display(uint32_t profile_id)
{
    System_snprintf(uart_print_string,sizeof(uart_print_string),"%5.2f",(float)(profile_Context.profile_Points[profile_id].total_bytes_transferred)/(1024*1024));
    MMCSD_log("Results[%d:%s]:   Bytes transferred : %s MBytes \n",profile_id,profile_Context.profile_Points[profile_id].name, uart_print_string);

    System_snprintf(uart_print_string,sizeof(uart_print_string),"%5.2f",profile_Context.profile_Points[profile_id].total_time_ms);
    MMCSD_log("Results[%d:%s]:   Total Time in ms : %s milli seconds\n",profile_id,profile_Context.profile_Points[profile_id].name, uart_print_string);

    System_snprintf(uart_print_string,sizeof(uart_print_string),"%5.2f",profile_Context.profile_Points[profile_id].bandwidth_mbytes_per_sec);
    MMCSD_log("Results[%d:%s]:   Throughput : %s MBytes/sec \n",profile_id,profile_Context.profile_Points[profile_id].name, uart_print_string);

}

void profile_display_all()
{
    int i;
	MMCSD_log("---------------------------------------\n");
    for(i=0;i<PROFILE_MAX_POINTS;i++) {
        if(profile_Context.profile_Points[i].num_iterations>0) {
	      profile_display(i);
  		  MMCSD_log("\n");
		  }
	}   
	MMCSD_log("---------------------------------------\n");
}

void profile_reset_results() 
{
   int i;  
   for(i=0;i<PROFILE_MAX_POINTS;i++) {
     profile_Context.profile_Points[i].start_tick=0;
     profile_Context.profile_Points[i].end_tick=0;
     profile_Context.profile_Points[i].total_ticks=0;
     profile_Context.profile_Points[i].total_ticks_master=0;
     profile_Context.profile_Points[i].num_iterations=0;
     profile_Context.profile_Points[i].total_bytes_transferred=0;
     profile_Context.profile_Points[i].total_time_ms=0;
     profile_Context.profile_Points[i].total_time_percentage=0;/* w.r.t master */
     profile_Context.profile_Points[i].time_per_iter_ms=0;
     profile_Context.profile_Points[i].bandwidth_mbytes_per_sec=0;
  }   
}

void profile_calculate_results(uint32_t total_bytes_transferred)
{         
    int i;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_CMD_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_SUBMIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_COMPLETE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;

    profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_CMD_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_SUBMIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_COMPLETE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;

   	for(i=0;i<10;i++) {
   	    profile_Context.profile_Points[i].total_bytes_transferred=total_bytes_transferred;
    }
    profile_calculate_all_time();
}


void profile_display_results(uint32_t total_bytes_transferred)
{         
    int i;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_CMD_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_SUBMIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_WRITE_DATA_TRANSFER_COMPLETE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_WRITE].total_ticks;

    profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_CMD_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_WAIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_SUBMIT].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;
    profile_Context.profile_Points[PROFILE_MMCSD_READ_DATA_TRANSFER_COMPLETE].total_ticks_master=profile_Context.profile_Points[PROFILE_MMCSD_READ].total_ticks;

   	for(i=0;i<10;i++) {
   	    profile_Context.profile_Points[i].total_bytes_transferred=total_bytes_transferred;
    }
    profile_calculate_all_time();
    profile_display_all();
}


char mmcsd_uart_print_string[128];
void mmcsd_display_benchmarks(mmcsdTestBenchmarks_t *benchmarks_ptr)
{
   int32_t i;
  
   if(benchmarks_ptr==NULL)
     return;
     
   MMCSD_log ("\n ----- RAW Read/Write Throughput measurements -------\n");
   MMCSD_log ("Throughput is measured by reading/writing a contiguous block of memory of varying sizes using MMCSD_Write/Read() APIs ");
   MMCSD_log ("\n\n---------------------------------------\n" );

   System_snprintf(mmcsd_uart_print_string,sizeof(mmcsd_uart_print_string), "| %4s | %6s | %8s |","Size(KB)","Write(MB/s)","Read(MB/s)");
   MMCSD_log ("%s",mmcsd_uart_print_string);
   MMCSD_log ("\n---------------------------------------" );
   for(i=0;i<MMCSD_TEST_MAX_NUM_BENCHMARKS;i++) 
   {
      if(benchmarks_ptr->RAW_measurements[i].valid) 
      {

		
 
		 System_snprintf(mmcsd_uart_print_string,sizeof(mmcsd_uart_print_string),"\n|  %6d  |  %5.2f   |   %5.2f   |",
              (uint32_t)( benchmarks_ptr->RAW_measurements[i].read.num_bytes_transferred/1024),
                    benchmarks_ptr->RAW_measurements[i].write.bandwidth_mbytes_per_sec,
		      benchmarks_ptr->RAW_measurements[i].read.bandwidth_mbytes_per_sec);
         MMCSD_log ("%s",mmcsd_uart_print_string);
 
      }
   }
   MMCSD_log ("\n---------------------------------------\n" );

#ifdef MMCSD_TEST_FATFS_BENCHMARK_ENABLED    
   MMCSD_log ("\n\n ---------------- FATFS Read/Write Throughput Measurements ----------------\n");
   MMCSD_log ("Throughput is measured by reading/writing a file of various sizes using FAT32");
   MMCSD_log ("\n\n---------------------------------------\n" );

   System_snprintf(mmcsd_uart_print_string,sizeof(mmcsd_uart_print_string),  "| %4s | %6s | %8s |","Size(KB)","Write(MB/s)","Read(MB/s)");
   MMCSD_log ("%s",mmcsd_uart_print_string);
   MMCSD_log ("\n--------------------------------------" );
   for(i=0;i<MMCSD_TEST_MAX_NUM_BENCHMARKS;i++) 
   {
      if(benchmarks_ptr->FATFS_measurements[i].valid) 
      {
 		 System_snprintf(mmcsd_uart_print_string,sizeof(mmcsd_uart_print_string),"\n|  %6d  |    %5.2f   |   %5.2f   |",
             (uint32_t)( benchmarks_ptr->FATFS_measurements[i].read.num_bytes_transferred/1024),
                    benchmarks_ptr->FATFS_measurements[i].write.bandwidth_mbytes_per_sec,
		      benchmarks_ptr->FATFS_measurements[i].read.bandwidth_mbytes_per_sec);
          MMCSD_log ("%s",mmcsd_uart_print_string);
 
      }
   }
   MMCSD_log ("\n--------------------------------------\n" );
#endif      
}
void mmcsd_reset_benchmarks(mmcsdTestBenchmarkElem_t *benchmark_elem_ptr)
{
   if(benchmark_elem_ptr==NULL)
     return;

    benchmark_elem_ptr->valid=FALSE; 
    benchmark_elem_ptr->write.num_bytes_transferred =0;
    benchmark_elem_ptr->write.bandwidth_mbytes_per_sec=0;
    benchmark_elem_ptr->read.num_bytes_transferred =0;
    benchmark_elem_ptr->read.bandwidth_mbytes_per_sec=0;
}

void mmcsd_store_benchmarks(mmcsdTestBenchmarkElem_t *benchmark_elem_ptr,uint32_t bytes_transferred)
{    
	 /* Store the benchmark information */
     benchmark_elem_ptr->valid=TRUE;

     benchmark_elem_ptr->write.bandwidth_mbytes_per_sec = profile_Context.profile_Points[PROFILE_MMCSD_WRITE].bandwidth_mbytes_per_sec;
     benchmark_elem_ptr->write.num_bytes_transferred = bytes_transferred;

     benchmark_elem_ptr->read.bandwidth_mbytes_per_sec = profile_Context.profile_Points[PROFILE_MMCSD_READ].bandwidth_mbytes_per_sec;
     benchmark_elem_ptr->read.num_bytes_transferred = bytes_transferred;
}
