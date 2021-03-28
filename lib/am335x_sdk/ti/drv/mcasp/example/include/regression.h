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

/** \file     profiling.c
 *
 *  \brief    sample application for profiling frame processing
 *
 *  This file contains the implementation of the sample appliation for the
 *  demonstration of audio playing through the audio interface layer.
 *
 *             (C) Copyright 2009, Texas Instruments, Inc
 */

/* ========================================================================== */
/*                            INCLUDE FILES                                   */
/* ========================================================================== */

#include <xdc/std.h>
#include <mcasp_drv.h>
#include "mcasp_osal.h"
#include "mcasp_cfg.h"
#include "MCASP_log.h"
#include "stdio.h"
#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif


/* MCASP Regression test Data structures */
typedef enum {
	MCASP_TEST_PROFILE_I2S,
	MCASP_TEST_PROFILE_DSP,
}mcaspTestProfile_Protocol_e;

typedef enum {
	MCASP_REGRESSION_TEST_1,
	MCASP_REGRESSION_TEST_2,
	MCASP_REGRESSION_TEST_3,
	MCASP_REGRESSION_TEST_4,
	MCASP_REGRESSION_TEST_5,
	MCASP_REGRESSION_TEST_6,
	MCASP_REGRESSION_TEST_7,
	MCASP_REGRESSION_TEST_8,
	MCASP_REGRESSION_TEST_9,
	MCASP_REGRESSION_TEST_10,
	MCASP_REGRESSION_TEST_11,
	MCASP_REGRESSION_TEST_12,
	MCASP_REGRESSION_TEST_13,
	MCASP_REGRESSION_TEST_MAX,
    MCASP_REGRESSION_ALL_NON_POWERCYCLE_TESTS = -1,
    MCASP_REGRESSION_TEST_EXIT = -2,
}mcaspTestProfileID_e;

typedef struct {
	/* Test ID/description */
	mcaspTestProfileID_e testID;
	char testDescription[100];
	bool powerCycleRequired;
	/* Device Configuration */
	uint32_t instance_num; /* McASP instance number 0,1,2 etc */
	uint32_t num_timeslots;
	mcaspTestProfile_Protocol_e protocol; /* I2S, DSP */
	uint32_t num_serializers;
	Mcasp_BufferFormat bufferformat; /* INTERLEAVED */
	Mcasp_OpMode channelMode; /* TDM/DIT */
	Mcasp_WordLength wordLength; /* 8/16/24/32 */
	bool enableFifo; /* TRUE/FALSE */
	uint32_t hwFifoEventDMARatio;
} mcaspTestProfile_t;


extern mcaspTestProfile_t * mcaspTestProfiles[MCASP_REGRESSION_TEST_MAX+1];/* +1 is for NULL */

void configure_mcasp_with_testProfile(mcaspTestProfile_t *testProfilePtr);
void display_testProfile(mcaspTestProfile_t *testProfilePtr);
int32_t mcasp_regression_seek_testID();

#ifdef __cplusplus
}
#endif
