/*
 * mcasp_debug.h
 *  *
 * This file contains the test / demo code to demonstrate the Audio component
 * driver functionality on SYS/BIOS 6.
 *
 * Copyright (C) 2009-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/** \file     mcasp_tune.h
 *
 *  \brief    sample application for demostration of audio playing
 *
 *  This file contains the definitions for tuning the McASP performance.
 *
 *             (C) Copyright 2009-2017, Texas Instruments, Inc
 */

/* ========================================================================== */
/*                            INCLUDE FILES                                   */
/* ========================================================================== */
#ifndef _MCASP_TUNE_H_
#define _MCASP_TUNE_H_

#include <xdc/std.h>


#define MCASP_DEBUG_UNDEFINED 0

/* This holds the maximum number of debug probe points. If the events exceeed this limit it
 * will start from the beginning overwriting old probe data */
#define MAX_NUM_DEBUG_PRINTS 1000

/* The below are the debug codes which have been found to be useful.
 * The way it works is that we could log various steps in the execution of
 * the applicaiton/driver by enabling MCASP_ENABLE_DEBUG_LOG during compilation and
 * placing various probe points with logical bookmarks defined in mcaspDebugPrint_e.
 * Additional arguments relevant to that particular probe point can be passed (up to 4)
 * All these will be logged in the mcaspDebugPrints variable defined in mcasp_debug.c 
 * At the end of the execution this variable could be analyzed to see the chain of events 
 * which were logged. To summarize the usage of the debug feature, we would need to
 * 1) Include the mcasp_debug.h in the application & driver (if needed) 
 * 2) Add probepoints if necessary in the application/driver.
 * 3) Recompile after enabling MCASP_ENABLE_DEBUG_LOG in the application's makefile.
 *    Make sure to include mcasp_debug.c in the list of files to be compiled inside the makefile.
 * 4) Analyze at the end of the test using mcaspDebugLog_PrintAll (optional) or 
 *    use emulator/CCS to display in the memory window
 * Please refer to the usage in detail in audioSample_io.c 
 */ 

#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
	DEBUG_APP_AFTER_TX_CREATECHAN,
	DEBUG_APP_AFTER_RX_CREATECHAN,
	DEBUG_APP_PRIMING_BEGIN,
    DEBUG_APP_PRIMING_END,
	DEBUG_APP_SUBMIT_WRITE,
	DEBUG_APP_SUBMIT_WRITE_COMPLETE,
	DEBUG_APP_SUBMIT_READ,
	DEBUG_APP_SUBMIT_READ_COMPLETE,
	DEBUG_NAVSS_READ,
	DEBUG_NAVSS_READ_XYZ,
	DEBUG_NAVSS_WRITE,
	DEBUG_NAVSS_WRITE_XYZ,
	DEBUG_NAVSS_SUBMIT_QUEUE_TX,
	DEBUG_NAVSS_SUBMIT_QUEUE_RX,
    DEBUG_NAVSS_TX_ISR,
    DEBUG_NAVSS_TX_MCASP_CALLBACK,
    DEBUG_NAVSS_TX_MCASP_CALLBACK_COMPLETE,
    DEBUG_NAVSS_TX_ISR_COMPLETE,
    DEBUG_APP_TX_CALLBACK,
    DEBUG_NAVSS_RX_ISR,
    DEBUG_NAVSS_RX_MCASP_CALLBACK,
    DEBUG_NAVSS_RX_MCASP_CALLBACK_COMPLETE,
    DEBUG_NAVSS_RX_ISR_COMPLETE,
    DEBUG_NAVSS_POP_CQ,
    DEBUG_NAVSS_POP_FREEQ,
    DEBUG_APP_RX_CALLBACK,
    DEBUG_MCASPDRV_OPEN_TX_PDMA_PRMS,
    DEBUG_MCASPDRV_OPEN_RX_PDMA_PRMS,
    DEBUG_MCASPDRV_LOAD_DMA,
    DEBUG_MCASPDRV_ENABLE_TRANSFER,
    DEBUG_MCASPDRV_Mcasp_localEdmaProcessPkt,
    DEBUG_APP_CALLBACK,
    DEBUG_APP_CALLBACK_READ,
    DEBUG_APP_CALLBACK_WRITE,
    DEBUG_APP_CALLBACK_SPURIOUS,
    DEBUG_APP_CALLBACK_READ_MISMATCH,
    DEBUG_APP_CALLBACK_WRITE_MISMATCH,
    DEBUG_NAVSS_EMPTY_CQ,
} mcaspDebugPrint_e;


typedef struct {
  mcaspDebugPrint_e code;
  uint32_t val[4];
}mcaspDebugPrints_t;

/* Log the mcasp Event with a arguments */
void mcaspDebugLog(mcaspDebugPrint_e code, uint32_t val1, uint32_t val2, uint32_t val3,uint32_t val4);

/* Display the sequence of events logged at the end of the test */
void mcaspDebugLog_PrintAll();

/* Initialization of log structures at the beginnning of the test */
void mcaspDebugLog_init();
#ifdef __cplusplus
}
#endif

#endif /* __MCASP_TUNE_H_ */
