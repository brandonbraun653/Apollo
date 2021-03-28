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

#define RX_SYNC_THRESHOLD 4

/* 'Unpacked' timeslot data , gropued by serializer. These will be used to generate/analyze pattern of the sent/received samples
    before they are packed in the frame buffer and submitted to the McASP
  */
#define MAX_NUM_SERIALIZERS (16)
#define MAX_NUM_TIMESLOTS   (6)

/* Create the ramp sample combining the ramp value (val), and the serializer and timeslot signature*/
#define CREATE_SAMPLE_VAL(serIndex,tsIndex,word_width_bits,val)   ((serIndex<<(word_width_bits-4)) | (tsIndex<<(word_width_bits-8)) |  (val & ~((~(0x0u))<<(word_width_bits-8))))
/* Extract the ramp from the word, removing the serializer and timeslot signature used for ramp */
#define EXTRACT_SAMPLE_VAL(serIndex,tsIndex,word_width_bits,val)  (val & (~((~(0x0u))<<((word_width_bits)-8))))
/* Extract the timeslot signature from the word */
#define EXTRACT_SAMPLE_TS(serIndex,tsIndex,word_width_bits,val)   ((val >> (word_width_bits-8)) & 0xf)
/* Extract the serializer signature from the word */
#define EXTRACT_SAMPLE_SER(serIndex,tsIndex,word_width_bits,val)  ((val >> (word_width_bits-4)) & 0xf)

/* Create the ramp mask used to read/write the ramp value */
#define SAMPLE_MASK(ramp_width_bits)                              (~((~(0x0u))<<(ramp_width_bits)))

/* Direction. This is being used in the mcasp_chanparams[] to configure Tx and RX  */
#define RX 0
#define TX 1

typedef enum {
    RX_LOOPBACK_NOT_SYNCHED=0,
    RX_LOOPBACK_SYNCHED=1,
} rampSynchState_e;


typedef enum {
   FOUND_SYNC=0,
   LOST_SYNC_RAMP_VAL=1,
   LOST_SYNC_SER_TS_MISMATCH=2,
} rampSynchStatusChange_e;


/* Data structure to store information regarding a timeslot within a serializer. This helps
 * to keep track of the ramp information per timeslot.
 * */
typedef struct {
   uint32_t index; /* TS 0,1,.. */
   uint32_t *buf; /* The unpacked buffer */
   uint32_t *sample_word_offsets; /* Array containing the word offsets */
   uint32_t buf_num_samples; /* Number of 32 bit samples */
   uint32_t ramp_last_val;  /* For Tx, it is the last put value on the ramp, for Rx it is the last ramp value received */
   uint32_t ramp_last_sample;  /* Last sample sent/received */

   uint32_t ramp_synch_losses; /* Applicable to Rx */
   uint32_t ramp_synch_finds;  /* Applicable to Rx */
   uint32_t ramp_transmission_errors; /* Applicable to Rx */
   bool     isSynched; /* Applicable to Rx Only */
   uint32_t ramp_mask;
   uint32_t total_frames;
   uint32_t ValwordWidth; /* The actual width for ramp pattern, which is the lesser of Tx and Rx word widths  */
   uint32_t wordBitsSelect;
   rampSynchState_e rampRxSynchState;
   rampSynchState_e rampRxSynchStatePrev;
   rampSynchStatusChange_e statusChange;
} tsInfo_t;

/* All info pertaining to a serializer. */
typedef struct {
    uint32_t index; /* Serializer index */
    tsInfo_t tsInfo[MAX_NUM_TIMESLOTS];
    bool     enabled;
} serInfo_t;
/* Events to be pushed in to the event queue */
typedef struct {
  Osal_Queue_Elem link;
  uint32_t serIndex;
  uint32_t tsIndex;
  uint32_t dir;
  uint32_t sample_no;
  uint32_t frame_no;
  rampSynchStatusChange_e statusChange;
  uint32_t sample;
} dlbEvent_t;

/* DLB test context containing all the test info for a direction (TX/RX) */
typedef struct {
    serInfo_t serInfo[MAX_NUM_SERIALIZERS];
} dlbTestInfo_t;
extern Error_Block eb;
/* Configures the loopback type based upon the MCASP configuration */
void config_deviceloopback(uint32_t frame_size_in_bytes_tx,uint32_t frame_size_in_bytes_rx);
void deviceloopback_process_samples(void *buf, uint32_t len_in_bytes, int dir);
void finish_deviceloopback();
void dlb_process_events();

#ifdef __cplusplus
}
#endif
